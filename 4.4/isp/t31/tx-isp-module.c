#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/of.h>

extern int tx_isp_init(void);
extern void tx_isp_exit(void);

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
