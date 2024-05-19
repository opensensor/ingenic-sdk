#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/of.h>

int32_t static int tx_isp_probe(struct platform_device *pdev)
{
	struct tx_isp_device* ispdev = NULL;
	struct tx_isp_device_descriptor *desc = NULL;
	struct tx_isp_module *module = NULL;
	int ret = ISP_SUCCESS;

	/*ISP_INFO("@@@@@@@@@@@@@@@@@@@@ tx-isp-probe @@@@@@@@@@@@@@@@@@@@@@@@@@\n");*/
	ispdev = (struct tx_isp_device*)kzalloc(sizeof(*ispdev), GFP_KERNEL);
	if (!ispdev) {
		ISP_ERROR("Failed to allocate camera device\n");
		ret = -ENOMEM;
		goto exit;
	}

	/* register subdev */
	desc = pdev->dev.platform_data;
	ret = tx_isp_match_and_register_platforms(desc, ispdev->pdevs);
	if(ret){
		goto failed_to_match;
	}
	ispdev->pdev_num = desc->entity_num;

	/* init self */
	private_spin_lock_init(&ispdev->slock);
	ret = tx_isp_module_init(pdev, &ispdev->module);
	if(ret){
		ISP_ERROR("Failed to init isp module(%d.%d)\n", desc->parentid, desc->unitid);
		ret = -ENOMEM;
		goto failed_to_ispmodule;
	}

	tx_isp_set_module_nodeops(&ispdev->module, &tx_isp_fops);
	/*tx_isp_set_module_debugops(&ispdev->module, &tx_isp_debug_fops);*/
	module = &ispdev->module;

	module->miscdev.minor = MISC_DYNAMIC_MINOR;
	module->miscdev.name = "tx-isp";
	module->miscdev.fops = &tx_isp_fops;
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
	globe_ispdev = ispdev;

	/* create the topology graph of isp modules */
	ret = tx_isp_create_graph_and_nodes(ispdev);
	if(ret){
		goto failed_to_nodes;
	}

	isp_mem_init();
	/*isp_debug_init();*/
	ispdev->version = TX_ISP_DRIVER_VERSION;
	printk("@@@@ tx-isp-probe ok(version %s) @@@@@\n", ispdev->version);
	return 0;

	failed_to_nodes:
	proc_remove(ispdev->proc);
	failed_to_proc:
	private_misc_deregister(&module->miscdev);
	failed_misc_register:
	tx_isp_module_deinit(&ispdev->module);
	failed_to_ispmodule:
	tx_isp_unregister_platforms(ispdev->pdevs);
	failed_to_match:
	kfree(ispdev);
	exit:
	return ret;

}

int tx_isp_init(void)  {
	int32_t returnValue;
	returnValue = platform_device_register("tx-isp");
	if (returnValue != 0)
	{
		isp_printf("Failed to insmod isp driver!!!\n");
	}
	else
	{
		returnValue = platform_driver_register(0x78d30);
		if (returnValue != 0)
		{
			platform_device_unregister("tx-isp");
		}
	}
	return returnValue;
}

void tx_isp_exit(void) {

}

static const struct of_device_id tx_isp_of_match[] = {
		{ .compatible = "ingenic,t31-isp", },
		{},
};
MODULE_DEVICE_TABLE(of, tx_isp_of_match);

static int __init tx_isp_module_init(void)
{
	printk(KERN_INFO "tx_isp_module_init: Initializing tx-isp module\n");
	int ret = tx_isp_init();
	if (ret == 0) {
		printk(KERN_INFO "tx_isp_module_init: tx_isp_init succeeded\n");
	} else {
		printk(KERN_ERR "tx_isp_module_init: tx_isp_init failed: %d\n", ret);
	}
	return ret;
}

static void __exit tx_isp_module_exit(void)
{
	printk(KERN_INFO "tx_isp_module_exit: Exiting tx-isp module\n");
	tx_isp_exit();
}

module_init(tx_isp_module_init);
module_exit(tx_isp_module_exit);

MODULE_AUTHOR("Ingenic xhshen");
MODULE_DESCRIPTION("tx isp driver");
MODULE_LICENSE("GPL");
