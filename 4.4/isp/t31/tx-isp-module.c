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
#include <misc/isp_mem_map.h>
#include "txx-funcs.h"

extern int tx_isp_init(void);
extern void tx_isp_exit(void);

static void __iomem *isp_base;

static int __init tx_isp_module_init(void)
{
    isp_base = get_isp_base();
    if (!isp_base) {
        pr_err("Failed to initialize ISP\n");
        return -EFAULT;
    }
	return tx_isp_init();
}

static void __exit tx_isp_module_exit(void)
{
    private_iounmap(isp_base);
	tx_isp_exit();
}

module_init(tx_isp_module_init);
module_exit(tx_isp_module_exit);

MODULE_AUTHOR("Ingenic xhshen");
MODULE_DESCRIPTION("tx isp driver");
MODULE_LICENSE("GPL");
