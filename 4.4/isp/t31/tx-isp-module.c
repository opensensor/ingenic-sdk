/*
 * Video Class definitions of Tomahawk series SoC.
 *
 * Copyright 2017, <xianghui.shen@ingenic.com>
 *
 * This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/proc_fs.h>
#include <linux/of.h>
#include <txx-funcs.h>
#include <tx-isp-common.h>
#include <tx-isp-debug.h>
#include <tx-isp-platform.h>

// These come from the firmware.a
extern int32_t tx_isp_open(int32_t arg1, void* arg2);
extern int32_t tx_isp_unlocked_ioctl(void* arg1, int32_t arg2, int32_t arg3);
extern int32_t tx_isp_release(int32_t arg1, void* arg2);
extern void* isp_mem_init(void);
 extern int32_t tx_isp_notify(int32_t arg1, int32_t arg2);
extern int32_t tx_isp_request_irq(int32_t* arg1, int32_t* arg2);
extern void tx_isp_free_irq(int32_t* arg1);
//extern struct tx_isp_device* globe_ispdev;

extern struct platform_driver tx_isp_vin_driver;
extern struct platform_driver tx_isp_csi_driver;
extern struct platform_driver tx_isp_vin_driver;
extern struct platform_driver tx_isp_core_driver;
extern struct platform_driver tx_isp_fs_driver;

static struct platform_driver *isp_drivers[] = {
		&tx_isp_vin_driver,
		&tx_isp_csi_driver,
		&tx_isp_vin_driver,
		&tx_isp_core_driver,
		&tx_isp_fs_driver,
};

static unsigned int drivers_num = ARRAY_SIZE(isp_drivers);


static void private_tx_isp_unregister_platforms(struct tx_isp_platform *pform)
{
	int index = 0;

	for(index = 0; index < TX_ISP_PLATFORM_MAX_NUM; index++){
#if 0
		if(pform[index].drv){
			private_platform_driver_unregister(pform[index].drv);
		}
		if(pform[index].dev){
			private_platform_device_unregister(pform[index].dev);
		}
#else
		if(pform[index].drv){
			pform[index].drv->remove(pform[index].dev);
		}
		if(pform[index].dev){
			private_platform_device_unregister(pform[index].dev);
		}
#endif
	}
	return;
}


static int private_tx_isp_match_and_register_platforms(struct private_tx_isp_device_descriptor *desc, struct tx_isp_platform *pform)
{
	struct platform_device *dev;
	struct platform_driver *drv;
	int dev_index, drv_index;
	int ret = 0;
	if(desc == NULL)
		return -EINVAL;
	/*printk("%s %d\n", __func__, __LINE__);*/
	if(desc->entity_num > TX_ISP_PLATFORM_MAX_NUM)
	{
		ISP_ERROR("The number of platform device is too much!\n");
		return -EINVAL;
	}
	for(dev_index = 0; dev_index < desc->entity_num; dev_index++){
		dev = desc->entities[dev_index];
		pform[dev_index].dev = dev;
		for(drv_index = 0; drv_index < drivers_num; drv_index++){
			drv = isp_drivers[drv_index];
			if(strcmp(dev->name, drv->driver.name) == 0){
				ret = private_platform_device_register(dev);
				if(ret){
					ISP_ERROR("Failed to register isp device(%d)\n", dev_index);
					pform[dev_index].dev = NULL;
					goto error;
				}
#if 0
				printk("%s %d\n", __func__, __LINE__);
				ret = private_platform_driver_register(drv);
				if(ret){
					ISP_ERROR("Failed to register isp driver(%d)\n", drv_index);
					goto error;
				}
#else
				/*printk("%s %d name = %s\n", __func__, __LINE__,dev->name);*/
				if(drv->probe)
					drv->probe(dev);
#endif
				pform[dev_index].drv = drv;
				break;
			}
		}
	}

	return 0;
	error:
	private_tx_isp_unregister_platforms(pform);
	return ret;
}

int private_tx_isp_module_init(struct platform_device *pdev, struct tx_isp_module *module)
{
	int ret = 0;
	struct private_tx_isp_descriptor *desc = NULL;
	if(!module){
		ISP_ERROR("%s the parameters are invalid!\n", __func__);
		return -EINVAL;
	}
	desc = pdev ? pdev->dev.platform_data : NULL;
	if(desc)
		module->desc = *desc;
	module->parent = NULL;
	memset(module->submods, 0, sizeof(module->submods));
	module->name = pdev->name;
	module->ops = NULL;
	module->debug_ops = NULL;
	module->dev = &(pdev->dev);
	// module->notify = tx_isp_notify;

	return ret;
}

void private_tx_isp_module_deinit(struct tx_isp_module *module)
{
	if(module)
		memset(module, 0, sizeof(*module));
}

static int isp_subdev_init_clks(struct tx_isp_subdev *sd, struct private_tx_isp_device_clk *info)
{
	struct clk **clks = NULL;
	unsigned int num = sd->clk_num;
	int ret = 0;
	int i;

	if(!sd->clk_num){
		sd->clks = NULL;
		return 0;
	}

	clks = (struct clk **)kzalloc(sizeof(clks) * num, GFP_KERNEL);
	if(!clks){
		ISP_ERROR("%s[%d] Failed to allocate core's clks\n",__func__,__LINE__);
		ret = -ENOMEM;
		goto exit;
	}
	for (i = 0; i < num; i++) {
		clks[i] = clk_get(sd->module.dev, info[i].name);
		if (IS_ERR(clks[i])) {
			ISP_ERROR("Failed to get %s clock %ld\n", info[i].name, PTR_ERR(clks[i]));
			ret = PTR_ERR(clks[i]);
			goto failed_to_get_clk;
		}
		if(info[i].rate != DUMMY_CLOCK_RATE) {
			ret = clk_set_rate(clks[i], info[i].rate);
			if(ret){
				ISP_ERROR("Failed to set %s clock rate(%ld)\n", info[i].name, info[i].rate);
				goto failed_to_get_clk;
			}
		}
	}
	sd->clks = clks;
	return 0;
	failed_to_get_clk:
	while(--i >= 0){
		clk_put(clks[i]);
	}
	kfree(clks);
	exit:
	return ret;
}

static int isp_subdev_release_clks(struct tx_isp_subdev *sd)
{
	struct clk **clks = sd->clks;
	int i = 0;

	if(clks == NULL)
		return 0;
	for (i = 0; i < sd->clk_num; i++)
		clk_put(clks[i]);

	kfree(clks);
	sd->clks = NULL;
	return 0;
}

static int private_tx_isp_subdev_device_init(struct tx_isp_subdev *sd, struct private_tx_isp_subdev_descriptor *desc)
{
	int ret = 0;
	int index = 0;
	int count = 0;
	struct tx_isp_subdev_pad *outpads = NULL;
	struct tx_isp_subdev_pad *inpads = NULL;

	/* init clks */
	sd->clk_num = desc->clks_num;
	ret = isp_subdev_init_clks(sd, desc->clks);
	if(ret){
		ISP_ERROR("Failed to init %s's clks!\n", sd->module.name);
		return ret;
	}
	/* init pads */
	for(index = 0; index < desc->pads_num; index++){
		if(desc->pads[index].type == TX_ISP_PADTYPE_OUTPUT)
			sd->num_outpads++;
		else
			sd->num_inpads++;
	}

	/*printk("## %s %d pads = %d inpads = %d, outpads = %d ##\n",__func__,__LINE__, desc->pads_num, sd->num_inpads, sd->num_outpads);*/
	if(sd->num_outpads){
		outpads = (struct tx_isp_subdev_pad *)kzalloc(sizeof(*outpads) * sd->num_outpads, GFP_KERNEL);
		if(!outpads){
			ISP_ERROR("Failed to malloc %s's outpads\n",sd->module.name);
			ret = -ENOMEM;
			goto failed_outpads;
		}

		count = 0;
		for(index = 0; index < desc->pads_num; index++){
			if(desc->pads[index].type == TX_ISP_PADTYPE_OUTPUT){
				outpads[count].sd = sd;
				outpads[count].index = count;
				outpads[count].type = desc->pads[index].type;
				outpads[count].links_type = desc->pads[index].links_type;
				outpads[count].state = TX_ISP_PADSTATE_FREE;
				outpads[count].link.flag = TX_ISP_LINKFLAG_DYNAMIC;
				count++;
			}
		}
	}
	if(sd->num_inpads){
		inpads = (struct tx_isp_subdev_pad *)kzalloc(sizeof(*inpads) * sd->num_inpads, GFP_KERNEL);
		if(!outpads){
			ISP_ERROR("Failed to malloc %s's inpads\n",sd->module.name);
			ret = -ENOMEM;
			goto failed_inpads;
		}

		count = 0;
		for(index = 0; index < desc->pads_num; index++){
			if(desc->pads[index].type == TX_ISP_PADTYPE_INPUT){
				inpads[count].sd = sd;
				inpads[count].index = count;
				inpads[count].type = desc->pads[index].type;
				inpads[count].links_type = desc->pads[index].links_type;
				inpads[count].state = TX_ISP_PADSTATE_FREE;
				inpads[count].link.flag = TX_ISP_LINKFLAG_DYNAMIC;
				count++;
			}
		}
	}
	sd->outpads = outpads;
	sd->inpads = inpads;

	return 0;
	failed_inpads:
	kfree(outpads);
	failed_outpads:
	isp_subdev_release_clks(sd);
	return ret;
}

static inline int private_tx_isp_subdev_widget_init(struct tx_isp_subdev *sd, struct private_tx_isp_widget_descriptor *desc)
{
	/* init clks */
	sd->clk_num = desc->clks_num;
	return isp_subdev_init_clks(sd, desc->clks);
}

int private_tx_isp_subdev_init(struct platform_device *pdev, struct tx_isp_subdev *sd, struct tx_isp_subdev_ops *ops)
{
	int ret = 0;
	struct resource *res = NULL;
	int index = 0;
	struct private_tx_isp_device_descriptor *desc = NULL;
	if(!pdev || !sd){
		ISP_ERROR("%s the parameters are invalid!\n", __func__);
		return -EINVAL;
	}
	/* subdev ops */
	sd->ops = ops;

	/*printk("## %s %d ##\n",__func__,__LINE__);*/
	private_tx_isp_module_init(pdev, &sd->module);

	desc = pdev->dev.platform_data;
	if(desc == NULL)
		goto done;

	/* init interrupt */
	ret = tx_isp_request_irq(pdev, &sd->irqdev);
	if(ret){
		ISP_ERROR("Failed to request irq!\n");
		goto failed_irq;
	}

	/**/
	for(index = 0; index < pdev->num_resources; index++){
		res = private_platform_get_resource(pdev, IORESOURCE_MEM, index);
		if(res && !strcmp(res->name, TX_ISP_DEV_NAME))
			break;
		else
			res = NULL;
	}
	if(res){
		res = private_request_mem_region(res->start,
										 res->end - res->start + 1, dev_name(&pdev->dev));
		if (!res) {
			ISP_ERROR("%s[%d] Not enough memory for resources\n", __func__,__LINE__);
			ret = -EBUSY;
			goto failed_req;
		}

		sd->base = private_ioremap(res->start, res->end - res->start + 1);
		if (!sd->base) {
			ISP_ERROR("%s[%d] Unable to ioremap registers\n", __func__,__LINE__);
			ret = -ENXIO;
			goto err_ioremap;
		}
	}
	sd->res = res;

	/* init subdev */
	if(desc->type == TX_ISP_TYPE_SUBDEV){
		printk("## %s %d ##\n",__func__,__LINE__);
		ret = private_tx_isp_subdev_device_init(sd, (void*)desc);
	}else if(desc->type == TX_ISP_TYPE_WIDGET){
		printk("## %s %d ##\n",__func__,__LINE__);
		ret = private_tx_isp_subdev_widget_init(sd, (void*)desc);
	}else{
		ISP_INFO("It's header!\n");
	}
	if(ret){
		ISP_ERROR("[%d] Failed to init subdev!\n", __LINE__);
		goto failed_init;
	}
	done:
	return 0;
	failed_init:
	private_iounmap(sd->base);
	err_ioremap:
	private_release_mem_region(res->start, res->end - res->start + 1);
	failed_req:
	tx_isp_free_irq(&sd->irqdev);
	failed_irq:
	private_tx_isp_module_deinit(&sd->module);
	exit:
	return ret;
}

EXPORT_SYMBOL(private_tx_isp_subdev_init);

void private_tx_isp_subdev_deinit(struct tx_isp_subdev *sd)
{
	struct tx_isp_module *module = &sd->module;
	if(module->ops)
		private_misc_deregister(&module->miscdev);

	isp_subdev_release_clks(sd);
	if(sd->outpads)
		kfree(sd->outpads);
	if(sd->inpads)
		kfree(sd->inpads);
	if(sd->base){
		private_iounmap(sd->base);
	}
	if(sd->res){
		private_release_mem_region(sd->res->start, sd->res->end - sd->res->start + 1);
		sd->res = NULL;
	}
	if(sd->irqdev.irq){
		tx_isp_free_irq(&sd->irqdev);
	}
	private_tx_isp_module_deinit(&sd->module);
	sd->ops = NULL;
}

EXPORT_SYMBOL(private_tx_isp_subdev_deinit);

int private_tx_isp_create_graph_and_nodes(struct tx_isp_device* ispdev)
{
	int ret = 0;
	int index = 0;
	struct tx_isp_platform *pdevs = ispdev->pdevs;
	struct tx_isp_module *module = NULL;
	struct tx_isp_module *submodule = NULL;
	struct tx_isp_module *header = &ispdev->module;

	printk("%s %d\n", __func__, __LINE__);
	/* First, find subdevs */
	for(index = 0; index < ispdev->pdev_num; index++){
		module = private_platform_get_drvdata(pdevs[index].dev);
		if (!module) {
			pr_err("Module for device %d is NULL!\n", index);
			continue;
		}
		printk("%s %d module = %p\n", __func__, __LINE__,module);
		if(IS_ERR_OR_NULL(module)){
			printk("Can't find the module(%d) driver!\n", index);
			continue;
		}
		if(module->desc.type == TX_ISP_TYPE_SUBDEV){
			header->submods[TX_ISP_GET_ID(module->desc.unitid)] = module;
		}
	}
	printk("%s %d\n", __func__, __LINE__);
	/* Second, find widgets */
	for(index = 0; index < ispdev->pdev_num; index++){
		module = private_platform_get_drvdata(pdevs[index].dev);
		if (!module) {
			pr_err("Module for device %d is NULL!\n", index);
			continue;
		}
		if(module->desc.type == TX_ISP_TYPE_WIDGET){
			printk("%s %d  subdev %d, widget %d\n", __func__, __LINE__, TX_ISP_GET_ID(module->desc.parentid), TX_ISP_GET_ID(module->desc.unitid));
			submodule = header->submods[TX_ISP_GET_ID(module->desc.parentid)];
			if(submodule == NULL){
				ISP_ERROR("the module(%d.%d) doesn't have parent!\n",module->desc.parentid, module->desc.unitid);
				ret = -EINVAL;
				break;
			}
			submodule->submods[TX_ISP_GET_ID(module->desc.unitid)] = module;
		}
	}

	printk("%s %d\n", __func__, __LINE__);
	/* Thrid, create misc device and debug node */
	for(index = 0; index < ispdev->pdev_num; index++){
		module = private_platform_get_drvdata(pdevs[index].dev);
		if (!module) {
			pr_err("Module for device %d is NULL!\n", index);
			continue;
		}
		if(module->ops){
			module->miscdev.minor = MISC_DYNAMIC_MINOR;
			module->miscdev.name = module->name;
			module->miscdev.fops = module->ops;
			ret = private_misc_register(&module->miscdev);
			if (ret < 0) {
				ret = -ENOENT;
				ISP_ERROR("Failed to register tx-isp miscdev(%d.%d)!\n", module->desc.parentid, module->desc.unitid);
				goto failed_misc_register;
			}
		}
		if (module->debug_ops) {
			if (!proc_create_data(module->name, S_IRUGO, ispdev->proc, module->debug_ops, (void *)module)) {
				pr_err("Failed to create proc entry for module %s\n", module->name);
				// Handle proc creation failure if necessary
			}
		}
	}
	return 0;
	failed_misc_register:
	while (--index >= 0) {
		module = private_platform_get_drvdata(pdevs[index].dev);
		if (module->ops) {
			private_misc_deregister(&module->miscdev);
		}
	}
	return ret;
}

static struct file_operations private_tx_isp_fops = {
		.open = tx_isp_open,
		.release = tx_isp_release,
		.unlocked_ioctl = tx_isp_unlocked_ioctl,
};

static int private_tx_isp_probe(struct platform_device *pdev)
{
	struct tx_isp_device* ispdev = NULL;
	struct private_tx_isp_device_descriptor *desc = NULL;
	struct tx_isp_module *module = NULL;
	int ret = ISP_SUCCESS;

	ISP_INFO("@@@@@@@@@@@@@@@@@@@@ tx-isp-probe @@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	ispdev = (struct tx_isp_device*)kzalloc(sizeof(*ispdev), GFP_KERNEL);
	if (!ispdev) {
		ISP_ERROR("Failed to allocate camera device\n");
		ret = -ENOMEM;
		goto exit;
	}

	/* register subdev */
	desc = pdev->dev.platform_data;
	ret = private_tx_isp_match_and_register_platforms(desc, ispdev->pdevs);
	if (ret) {
		goto failed_to_match;
	}
	ispdev->pdev_num = desc->entity_num;

	/* init self */
	private_spin_lock_init(&ispdev->slock);
	ret = private_tx_isp_module_init(pdev, &ispdev->module);
	if (ret) {
		ISP_ERROR("Failed to init isp module(%d.%d)\n", desc->parentid, desc->unitid);
		ret = -ENOMEM;
		goto failed_to_ispmodule;
	}

	// tx_isp_set_module_nodeops(&ispdev->module, &private_tx_isp_fops);
	/*private_tx_isp_set_module_debugops(&ispdev->module, &private_tx_isp_debug_fops);*/
	module = &ispdev->module;

	module->miscdev.minor = MISC_DYNAMIC_MINOR;
	module->miscdev.name = "tx-isp";
	// module->miscdev.fops = &private_tx_isp_fops;
	ret = private_misc_register(&module->miscdev);
	if (ret < 0) {
		ret = -ENOENT;
		ISP_ERROR("Failed to register tx-isp miscdev!\n");
		goto failed_misc_register;
	}

	ispdev->proc = jz_proc_mkdir("isp");
	if (!ispdev->proc) {
		ispdev->proc = NULL;
		ISP_ERROR("Failed to create debug directory of tx-isp!\n");
		goto failed_to_proc;
	}
	private_platform_set_drvdata(pdev, ispdev);
	// globe_ispdev = ispdev;

	/* create the topology graph of isp modules */
	ret = private_tx_isp_create_graph_and_nodes(ispdev);
	if (ret) {
		goto failed_to_nodes;
	}
	isp_mem_init();
	/*isp_debug_init();*/
	ispdev->version = TX_ISP_DRIVER_VERSION;
	printk("@@@@ tx-isp-probe ok(version %s) @@@@@\n", ispdev->version);
	return 0;

	failed_to_nodes:
	private_proc_remove(ispdev->proc);
	failed_to_proc:
	private_misc_deregister(&module->miscdev);
	failed_misc_register:
	private_tx_isp_module_deinit(&ispdev->module);
	failed_to_ispmodule:
	private_tx_isp_unregister_platforms(ispdev->pdevs);
	failed_to_match:
	kfree(ispdev);
	exit:
	return ret;
}


static int __exit private_tx_isp_remove(struct platform_device *pdev)
{
	struct tx_isp_device* ispdev = private_platform_get_drvdata(pdev);
	struct tx_isp_module *module = &ispdev->module;

	/*printk("%s %d\n", __func__, __LINE__);*/

	private_misc_deregister(&module->miscdev);
	private_proc_remove(ispdev->proc);
	private_tx_isp_unregister_platforms(ispdev->pdevs);
	platform_set_drvdata(pdev, NULL);
	/*isp_debug_deinit();*/

	kfree(ispdev);

	return 0;
}

#ifdef CONFIG_PM
static int private_tx_isp_suspend(struct device *dev)
{
//	private_tx_isp_device_t* ispdev = dev_get_drvdata(dev);

//	isp_dev_call(ispdev->isp, suspend, NULL);

	return 0;
}

static int private_tx_isp_resume(struct device *dev)
{
//	private_tx_isp_device_t* ispdev = dev_get_drvdata(dev);

//	isp_dev_call(ispdev->isp, resume, NULL);

	return 0;
}

static struct dev_pm_ops private_tx_isp_pm_ops = {
	.suspend = private_tx_isp_suspend,
	.resume = private_tx_isp_resume,
};
#endif

static struct platform_driver private_tx_isp_driver = {
		.probe = private_tx_isp_probe,
		.remove = __exit_p(private_tx_isp_remove),
		.driver = {
				.name = "tx-isp",
				.owner = THIS_MODULE,
#ifdef CONFIG_PM
				.pm = &private_tx_isp_pm_ops,
#endif
		},
};


static const struct of_device_id tx_isp_of_match[] = {
		{ .compatible = "ingenic,t31-isp", },
		{},
};
MODULE_DEVICE_TABLE(of, tx_isp_of_match);


static int __init private_tx_isp_init(void)
{
	int ret = 0;
	private_platform_device_register(&private_tx_isp_platform_device);
	ret = private_platform_driver_register(&private_tx_isp_driver);
	if(ret){
		private_platform_device_unregister(&private_tx_isp_platform_device);
	}
	return ret;
}

static void __exit private_tx_isp_exit(void)
{
	private_platform_driver_unregister(&private_tx_isp_driver);
	private_platform_device_unregister(&private_tx_isp_platform_device);
}

module_init(private_tx_isp_init);
module_exit(private_tx_isp_exit);

MODULE_AUTHOR("Ingenic xhshen");
MODULE_DESCRIPTION("tx isp driver");
MODULE_LICENSE("GPL");
