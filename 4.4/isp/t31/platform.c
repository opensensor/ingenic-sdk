/*
 * Platform device support for Jz4780 SoC.
 *
 * Copyright 2007, <zpzhong@ingenic.cn>
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/resource.h>
#include <linux/i2c-gpio.h>
#include <linux/module.h>
#include <net/sock.h>
#include <net/netlink.h>
#include <asm/uaccess.h>
#include <dt-bindings/interrupt-controller/t31-irq.h>
#include <txx-isp.h>
#include <linux/spinlock.h>
#include <linux/export.h>

static u64 tx_isp_module_dma_mask = ~(u64)0;

#define IPU_IOBASE	    0x13080000

#define ISP_LDC_IOBASE 		0x130a0000
#define ISP_NCU_IOBASE 		0x13090000
#define ISP_MSCALER_IOBASE 	0x130b0000

// T31 Specific
#define ISP_CORE_IOBASE	0x13300000
#define ISP_VIC_IOBASE	0x133e0000
#define MIPI_CSI_IOBASE	0x10023000
/* AHB2 BUS Devices Base */
#define HARB2_IOBASE	0x13400000
#define NEMC_IOBASE		0x13410000 /*TODO:check it*/
#define PDMA_IOBASE		0x13420000
#define AES_IOBASE  	0x13430000
#define SFC_IOBASE		0x13440000
#define MSC0_IOBASE		0x13450000
#define MSC1_IOBASE		0x13460000
#define HASH_IOBASE		0x13480000
#define ETHC_IOBASE		0x134b0000
#define OTG_IOBASE		0x13500000
#define EFUSE_IOBASE	0x13540000

static void tx_isp_release_device(struct device *dev)
{
	/*printk("isp device release!\n");*/
	return;
}

/* the widget is the controller of  all sensors */
struct tx_isp_widget_descriptor tx_isp_widget_vin = {
	.type = TX_ISP_TYPE_WIDGET,
	.subtype = TX_ISP_SUBTYPE_INPUT_TERMINAL,
	.parentid = TX_ISP_SUBDEV_ID(0),
	.unitid = TX_ISP_WIDGET_ID(0),
	.clks_num = 0,
};

struct platform_device tx_isp_vin_platform_device = {
	.name = TX_ISP_VIN_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_widget_vin,
		.release = tx_isp_release_device,
	},
	.num_resources = 0,
};


/* the controller is mipi interfaces*/
static struct resource tx_isp_csi_resource[] = {
	[0] = {
		/*.name = "mipi_csi",*/
		.name = TX_ISP_DEV_NAME,
		.start = MIPI_CSI_IOBASE,
		.end = MIPI_CSI_IOBASE + 0x1000 - 1,
		.flags = IORESOURCE_MEM,
	},
};

static struct tx_isp_device_clk isp_csi_clk_info[] = {
	{"csi", DUMMY_CLOCK_RATE},
};

struct tx_isp_widget_descriptor tx_isp_widget_csi = {
	.type = TX_ISP_TYPE_WIDGET,
	.subtype = TX_ISP_SUBTYPE_SELECTOR_UNIT,
	.parentid = TX_ISP_SUBDEV_ID(0),
	.unitid = TX_ISP_WIDGET_ID(2),
	.clks_num = ARRAY_SIZE(isp_csi_clk_info),
	.clks = isp_csi_clk_info,
};

struct platform_device tx_isp_csi_platform_device = {
	.name = TX_ISP_CSI_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_widget_csi,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_csi_resource),
	.resource = tx_isp_csi_resource,
};

/* It's a process unit that connects several interfaces of sensor */
static struct resource tx_isp_vic_resource[] = {
	[0] = {
		.name = TX_ISP_DEV_NAME,
		.start = ISP_VIC_IOBASE,
		.end = ISP_VIC_IOBASE + 0x21000 - 1,
		.flags = IORESOURCE_MEM,
	},
};

struct tx_isp_widget_descriptor tx_isp_widget_vic = {
	.type = TX_ISP_TYPE_WIDGET,
	.subtype = TX_ISP_SUBTYPE_CONTROLLER,
	.parentid = TX_ISP_SUBDEV_ID(0),
	.unitid = TX_ISP_WIDGET_ID(1),
	.clks_num = 0,
};

struct platform_device tx_isp_vic_platform_device = {
	.name = TX_ISP_VIC_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_widget_vic,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_vic_resource),
	.resource = tx_isp_vic_resource,
};

/* It's the first process unit */
static struct resource tx_isp_core_resource[] = {
	[0] = {
		.name = TX_ISP_DEV_NAME,
		/*.name = "isp_device",*/
		.start = ISP_CORE_IOBASE,
		.end = ISP_CORE_IOBASE + 0x80000 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		/*.name = "isp_irq_id",*/
		.name = TX_ISP_IRQ_ID,
		.start = IRQ_ISP,
		.end = IRQ_ISP,
		.flags = IORESOURCE_IRQ,
	},
};

static struct tx_isp_device_clk isp_core_clk_info[] = {
	{"cgu_isp", 85000000},
	{"isp", DUMMY_CLOCK_RATE},
};

struct tx_isp_pad_descriptor tx_isp_core_pads[] = {
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR | TX_ISP_PADLINK_LFB,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR | TX_ISP_PADLINK_LFB,
	},
	{
		.type = TX_ISP_PADTYPE_UNDEFINE,
	},
};

struct tx_isp_subdev_descriptor tx_isp_subdev_ispcore = {
	.type = TX_ISP_TYPE_SUBDEV,
	.subtype = TX_ISP_SUBTYPE_PROCESSING_UNIT,
	.parentid = TX_ISP_HEADER_ID(0),
	.unitid = TX_ISP_SUBDEV_ID(0),
	.clks_num = ARRAY_SIZE(isp_core_clk_info),
	.clks = isp_core_clk_info,
	.pads_num = ARRAY_SIZE(tx_isp_core_pads),
	.pads = tx_isp_core_pads,
};

struct platform_device tx_isp_core_platform_device = {
	.name = TX_ISP_CORE_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_subdev_ispcore,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_core_resource),
	.resource = tx_isp_core_resource,
};

/* It's the second process unit */
static struct resource tx_isp_ldc_resource[] = {
	[0] = {
		.name = TX_ISP_DEV_NAME,
		/*.name = "isp_device",*/
		.start = ISP_LDC_IOBASE,
		.end = ISP_LDC_IOBASE + 0x1000 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		/*.name = "isp_irq_id",*/
		.name = TX_ISP_IRQ_ID,
		.start = IRQ_LCD,
		.end = IRQ_LCD,
		.flags = IORESOURCE_IRQ,
	},
};

static struct tx_isp_device_clk isp_ldc_clk_info[] = {
	{"ldc", DUMMY_CLOCK_RATE},
	{"ahb1", DUMMY_CLOCK_RATE},
};

struct tx_isp_pad_descriptor tx_isp_ldc_pads[] = {
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
	{
		.type = TX_ISP_PADTYPE_INPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
};

struct tx_isp_subdev_descriptor tx_isp_subdev_ldc = {
	.type = TX_ISP_TYPE_SUBDEV,
	.subtype = TX_ISP_SUBTYPE_PROCESSING_UNIT,
	.parentid = TX_ISP_HEADER_ID(0),
	.unitid = TX_ISP_SUBDEV_ID(1),
	.clks_num = ARRAY_SIZE(isp_ldc_clk_info),
	.clks = isp_ldc_clk_info,
	.pads_num = ARRAY_SIZE(tx_isp_ldc_pads),
	.pads = tx_isp_ldc_pads,
};

struct platform_device tx_isp_ldc_platform_device = {
	.name = TX_ISP_LDC_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_subdev_ldc,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_ldc_resource),
	.resource = tx_isp_ldc_resource,
};

/* It's the thrid process unit */
static struct resource tx_isp_ncu_resource[] = {
	[0] = {
		.name = TX_ISP_DEV_NAME,
		.start = ISP_NCU_IOBASE,
		.end = ISP_NCU_IOBASE + 0x1000 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.name = TX_ISP_IRQ_ID,
		.start = IRQ_RESERVED33,
		.end = IRQ_RESERVED33,
		.flags = IORESOURCE_IRQ,
	},
};

static struct tx_isp_device_clk isp_ncu_clk_info[] = {
	{"ncu", DUMMY_CLOCK_RATE},
};

struct tx_isp_pad_descriptor tx_isp_ncu_pads[] = {
	{
		.type = TX_ISP_PADTYPE_INPUT,
		.links_type = TX_ISP_PADLINK_DDR | TX_ISP_PADLINK_LFB,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_LFB,
	},
};

struct tx_isp_subdev_descriptor tx_isp_subdev_ncu = {
	.type = TX_ISP_TYPE_SUBDEV,
	.subtype = TX_ISP_SUBTYPE_PROCESSING_UNIT,
	.parentid = TX_ISP_HEADER_ID(0),
	.unitid = TX_ISP_SUBDEV_ID(2),
	.clks_num = ARRAY_SIZE(isp_ncu_clk_info),
	.clks = isp_ncu_clk_info,
	.pads_num = ARRAY_SIZE(tx_isp_ncu_pads),
	.pads = tx_isp_ncu_pads,
};

struct platform_device tx_isp_ncu_platform_device = {
	.name = TX_ISP_NCU_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_subdev_ncu,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_ncu_resource),
	.resource = tx_isp_ncu_resource,
};

/* It's the fourth process unit */
static struct resource tx_isp_ms_resource[] = {
	[0] = {
		.name = TX_ISP_DEV_NAME,
		.start = ISP_MSCALER_IOBASE,
		.end = ISP_MSCALER_IOBASE + 0x1000 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.name = TX_ISP_IRQ_ID,
		.start = IRQ_RESERVED19,
		.end = IRQ_RESERVED19,
		.flags = IORESOURCE_IRQ,
	},
};

static struct tx_isp_device_clk isp_ms_clk_info[] = {
	{"mscaler", DUMMY_CLOCK_RATE},
};

struct tx_isp_pad_descriptor tx_isp_ms_pads[] = {
	{
		.type = TX_ISP_PADTYPE_INPUT,
		.links_type = TX_ISP_PADLINK_LFB,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
};

struct tx_isp_subdev_descriptor tx_isp_subdev_ms = {
	.type = TX_ISP_TYPE_SUBDEV,
	.subtype = TX_ISP_SUBTYPE_PROCESSING_UNIT,
	.parentid = TX_ISP_HEADER_ID(0),
	.unitid = TX_ISP_SUBDEV_ID(3),
	.clks_num = ARRAY_SIZE(isp_ms_clk_info),
	.clks = isp_ms_clk_info,
	.pads_num = ARRAY_SIZE(tx_isp_ms_pads),
	.pads = tx_isp_ms_pads,
};

struct platform_device tx_isp_ms_platform_device = {
	.name = TX_ISP_MSCALER_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_subdev_ms,
		.release = tx_isp_release_device,
	},
	.num_resources = ARRAY_SIZE(tx_isp_ms_resource),
	.resource = tx_isp_ms_resource,
};

struct tx_isp_pad_descriptor tx_isp_fs_pads[] = {
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
	{
		.type = TX_ISP_PADTYPE_OUTPUT,
		.links_type = TX_ISP_PADLINK_DDR,
	},
};

struct tx_isp_subdev_descriptor tx_isp_subdev_framesource = {
	.type = TX_ISP_TYPE_SUBDEV,
	.subtype = TX_ISP_SUBTYPE_OUTPUT_TERMINAL,
	.parentid = TX_ISP_HEADER_ID(0),
	.unitid = TX_ISP_SUBDEV_ID(4),
	.clks_num = 0,
	.pads_num = ARRAY_SIZE(tx_isp_fs_pads),
	.pads = tx_isp_fs_pads,
};

struct platform_device tx_isp_fs_platform_device = {
	.name = TX_ISP_FS_NAME,
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_isp_subdev_framesource,
		.release = tx_isp_release_device,
	},
	.num_resources = 0,
};

struct platform_device *tx_isp_devices[] = {
	/* isp core and its widgets */
	&tx_isp_core_platform_device,
	&tx_isp_vic_platform_device,
	&tx_isp_csi_platform_device,
	&tx_isp_vin_platform_device,
	/* ldc module and its widgets */
	&tx_isp_ldc_platform_device,
	/* ncu module and its widgets */
	&tx_isp_ncu_platform_device,
	/* mscaler module and its widgets */
	&tx_isp_ms_platform_device,
	/* framesource module and its widgets */
	&tx_isp_fs_platform_device,
};


/* It's the root device */
struct tx_isp_device_descriptor tx_video_device = {
	.type = TX_ISP_TYPE_HEADER,
	.subtype = TX_ISP_SUBTYPE_CONTROLLER,
	.parentid = -1,
	.unitid = TX_ISP_HEADER_ID(0),
	.entity_num = ARRAY_SIZE(tx_isp_devices),
	.entities = tx_isp_devices,
};

struct platform_device tx_isp_platform_device = {
	.name = "tx-isp",
	.id = -1,
	.dev = {
		.dma_mask = &tx_isp_module_dma_mask,
		.coherent_dma_mask = 0xffffffff,
		.platform_data = &tx_video_device,
		.release = tx_isp_release_device,
	},
	.num_resources = 0,
};


/*vpu irq*/
#if defined(CONFIG_AVPU) && defined(CONFIG_AVPU_DRIVER)
static u64 jz_vpu_dmamask = ~(u64)0;
#define IRQ_AVPU IRQ_HELIX0
static struct resource jz_avpu_irq_resources[] = {			\
	[0] = {								\
		.start          = AVPU_IOBASE_UNIT(0),			\
		.end            = AVPU_IOBASE_UNIT(0) + 0x100000 - 1,	\
		.flags          = IORESOURCE_MEM,			\
	},								\
	[1] = {								\
		.start          = IRQ_AVPU,		\
		.end            = IRQ_AVPU,	\
		.flags          = IORESOURCE_IRQ,			\
	},
};

struct platform_device jz_avpu_irq_device = {					\
	.name = "avpu",							\
	.id = 0,								\
	.dev = {								\
		.dma_mask				= &jz_vpu_dmamask,			\
		.coherent_dma_mask      = 0xffffffff,				\
	},									\
	.num_resources  = ARRAY_SIZE(jz_avpu_irq_resources),			\
	.resource       = jz_avpu_irq_resources,				\
};
#else
#ifdef CONFIG_JZ_VPU_IRQ_TEST
static struct resource jz_vpu_irq_resources[] = {			\
	[0] = {								\
		.start          = HELIX_IOBASE_UNIT(0),			\
		.end            = HELIX_IOBASE_UNIT(0) + 0x100000 - 1,	\
		.flags          = IORESOURCE_MEM,			\
	},								\
	[1] = {								\
		.start          = RADIX_IOBASE_UNIT(0),			\
		.end            = RADIX_IOBASE_UNIT(0) + 0x100000 - 1,	\
		.flags          = IORESOURCE_MEM,			\
	},								\
	[2] = {								\
		.start          = IRQ_HELIX0,			\
		.end            = IRQ_HELIX0,			\
		.flags          = IORESOURCE_IRQ,			\
	},								\
};									\

struct platform_device jz_vpu_irq_device = {					\
	.name = "jz-vpu-irq",							\
	.id = 0,								\
	.dev = {								\
		.coherent_dma_mask      = 0xffffffff,				\
	},									\
	.num_resources  = ARRAY_SIZE(jz_vpu_irq_resources),			\
	.resource       = jz_vpu_irq_resources,				\
};
#elif defined(CONFIG_SOC_VPU) && (defined(CONFIG_VPU_HELIX) || defined(CONFIG_VPU_RADIX))
static u64 jz_vpu_dmamask = ~(u64)0;
#define DEF_VPU(UNAME, LNAME, NO)								\
	static struct resource jz_vpu_##LNAME##NO##_resources[] = {			\
		[0] = {								\
			.start          = UNAME##_IOBASE_UNIT(NO),			\
			.end            = UNAME##_IOBASE_UNIT(NO) + 0x100000 - 1,	\
			.flags          = IORESOURCE_MEM,			\
		},								\
		[1] = {								\
			.start          = IRQ_##UNAME##NO,			\
			.end            = IRQ_##UNAME##NO,			\
			.flags          = IORESOURCE_IRQ,			\
		},								\
	};									\
struct platform_device jz_vpu_##LNAME##NO##_device = {					\
	.name = #LNAME,							\
	.id = NO,								\
	.dev = {								\
		.dma_mask               = &jz_vpu_dmamask,			\
		.coherent_dma_mask      = 0xffffffff,				\
	},									\
	.num_resources  = ARRAY_SIZE(jz_vpu_##LNAME##NO##_resources),			\
	.resource       = jz_vpu_##LNAME##NO##_resources,				\
};

#ifdef CONFIG_VPU_HELIX
#if (CONFIG_VPU_HELIX_NUM >= 1)
DEF_VPU(HELIX, helix, 0);
#endif
#endif
#ifdef CONFIG_VPU_RADIX
#if (CONFIG_VPU_RADIX_NUM >= 1)
DEF_VPU(RADIX, radix, 0);
#endif
#endif
#endif
#endif

/* ipu */
static u64 jz_ipu_dmamask = ~(u64) 0;
static struct resource jz_ipu_resources[] = {
		[0] = {
				.start = IPU_IOBASE,
				.end = IPU_IOBASE + 0x8000 - 1,
				.flags = IORESOURCE_MEM,
		},
		[1] = {
				.start = IRQ_IPU,
				.end = IRQ_IPU,
				.flags = IORESOURCE_IRQ,
		},
};

struct platform_device jz_ipu_device = {
		.name = "jz-ipu",
		.id = 0,
		.dev = {
				.dma_mask = &jz_ipu_dmamask,
				.coherent_dma_mask = 0xffffffff,
		},
		.num_resources = ARRAY_SIZE(jz_ipu_resources),
		.resource = jz_ipu_resources,
};

