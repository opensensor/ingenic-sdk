#ifndef __TX_SENSOR_COMMON_H__
#define __TX_SENSOR_COMMON_H__
#include <soc/gpio.h>

#include <txx-funcs.h>

#define SENSOR_R_BLACK_LEVEL	0
#define SENSOR_GR_BLACK_LEVEL	1
#define SENSOR_GB_BLACK_LEVEL	2
#define SENSOR_B_BLACK_LEVEL	3

/* External v4l2 format info. */
#define V4L2_I2C_REG_MAX		(150)
#define V4L2_I2C_ADDR_16BIT		(0x0002)
#define V4L2_I2C_DATA_16BIT		(0x0004)
#define V4L2_SBUS_MASK_SAMPLE_8BITS	0x01
#define V4L2_SBUS_MASK_SAMPLE_16BITS	0x02
#define V4L2_SBUS_MASK_SAMPLE_32BITS	0x04
#define V4L2_SBUS_MASK_ADDR_8BITS	0x08
#define V4L2_SBUS_MASK_ADDR_16BITS	0x10
#define V4L2_SBUS_MASK_ADDR_32BITS	0x20
#define V4L2_SBUS_MASK_ADDR_STEP_16BITS 0x40
#define V4L2_SBUS_MASK_ADDR_STEP_32BITS 0x80
#define V4L2_SBUS_MASK_SAMPLE_SWAP_BYTES 0x100
#define V4L2_SBUS_MASK_SAMPLE_SWAP_WORDS 0x200
#define V4L2_SBUS_MASK_ADDR_SWAP_BYTES	0x400
#define V4L2_SBUS_MASK_ADDR_SWAP_WORDS	0x800
#define V4L2_SBUS_MASK_ADDR_SKIP	0x1000
#define V4L2_SBUS_MASK_SPI_READ_MSB_SET 0x2000
#define V4L2_SBUS_MASK_SPI_INVERSE_DATA 0x4000
#define V4L2_SBUS_MASK_SPI_HALF_ADDR	0x8000
#define V4L2_SBUS_MASK_SPI_LSB		0x10000





/*
 * These pixel codes uniquely identify data formats on the media bus. Mostly
 * they correspond to similarly named V4L2_PIX_FMT_* formats, format 0 is
 * reserved, V4L2_MBUS_FMT_FIXED shall be used by host-client pairs, where the
 * data format is fixed. Additionally, "2X8" means that one pixel is transferred
 * in two 8-bit samples, "BE" or "LE" specify in which order those samples are
 * transferred over the bus: "LE" means that the least significant bits are
 * transferred first, "BE" means that the most significant bits are transferred
 * first, and "PADHI" and "PADLO" define which bits - low or high, in the
 * incomplete high byte, are filled with padding bits.
 *
 * The pixel codes are grouped by type, bus_width, bits per component, samples
 * per pixel and order of subsamples. Numerical values are sorted using generic
 * numerical sort order (8 thus comes before 10).
 *
 * As their value can't change when a new pixel code is inserted in the
 * enumeration, the pixel codes are explicitly given a numerical value. The next
 * free values for each category are listed below, update them when inserting
 * new pixel codes.
 */
#define V4L2_MBUS_FMT_FIXED 0x0001

/* RGB - next is 0x100d */
#define V4L2_MBUS_FMT_RGB444_2X8_PADHI_BE 0x1001
#define V4L2_MBUS_FMT_RGB444_2X8_PADHI_LE 0x1002
#define V4L2_MBUS_FMT_RGB555_2X8_PADHI_BE 0x1003
#define V4L2_MBUS_FMT_RGB555_2X8_PADHI_LE 0x1004
#define V4L2_MBUS_FMT_BGR565_2X8_BE 0x1005
#define V4L2_MBUS_FMT_BGR565_2X8_LE 0x1006
#define V4L2_MBUS_FMT_RGB565_2X8_BE 0x1007
#define V4L2_MBUS_FMT_RGB565_2X8_LE 0x1008
#define V4L2_MBUS_FMT_RGB666_1X18 0x1009
#define V4L2_MBUS_FMT_RGB888_1X24 0x100a
#define V4L2_MBUS_FMT_RGB888_2X12_BE 0x100b
#define V4L2_MBUS_FMT_RGB888_2X12_LE 0x100c

/* YUV (including grey) - next is 0x2017 */
#define V4L2_MBUS_FMT_Y8_1X8 0x2001
#define V4L2_MBUS_FMT_UV8_1X8 0x2015
#define V4L2_MBUS_FMT_UYVY8_1_5X8 0x2002
#define V4L2_MBUS_FMT_VYUY8_1_5X8 0x2003
#define V4L2_MBUS_FMT_YUYV8_1_5X8 0x2004
#define V4L2_MBUS_FMT_YVYU8_1_5X8 0x2005
#define V4L2_MBUS_FMT_UYVY8_2X8 0x2006
#define V4L2_MBUS_FMT_VYUY8_2X8 0x2007
#define V4L2_MBUS_FMT_YUYV8_2X8 0x2008
#define V4L2_MBUS_FMT_YVYU8_2X8 0x2009
#define V4L2_MBUS_FMT_Y10_1X10 0x200a
#define V4L2_MBUS_FMT_YUYV10_2X10 0x200b
#define V4L2_MBUS_FMT_YVYU10_2X10 0x200c
#define V4L2_MBUS_FMT_Y12_1X12 0x2013
#define V4L2_MBUS_FMT_UYVY8_1X16 0x200f
#define V4L2_MBUS_FMT_VYUY8_1X16 0x2010
#define V4L2_MBUS_FMT_YUYV8_1X16 0x2011
#define V4L2_MBUS_FMT_YVYU8_1X16 0x2012
#define V4L2_MBUS_FMT_YDYUYDYV8_1X16 0x2014
#define V4L2_MBUS_FMT_YUYV10_1X20 0x200d
#define V4L2_MBUS_FMT_YVYU10_1X20 0x200e
#define V4L2_MBUS_FMT_YUV10_1X30 0x2016

/* Bayer - next is 0x3019 */
#define V4L2_MBUS_FMT_SBGGR8_1X8 0x3001
#define V4L2_MBUS_FMT_SGBRG8_1X8 0x3013
#define V4L2_MBUS_FMT_SGRBG8_1X8 0x3002
#define V4L2_MBUS_FMT_SRGGB8_1X8 0x3014
#define V4L2_MBUS_FMT_SBGGR10_ALAW8_1X8 0x3015
#define V4L2_MBUS_FMT_SGBRG10_ALAW8_1X8 0x3016
#define V4L2_MBUS_FMT_SGRBG10_ALAW8_1X8 0x3017
#define V4L2_MBUS_FMT_SRGGB10_ALAW8_1X8 0x3018
#define V4L2_MBUS_FMT_SBGGR10_DPCM8_1X8 0x300b
#define V4L2_MBUS_FMT_SGBRG10_DPCM8_1X8 0x300c
#define V4L2_MBUS_FMT_SGRBG10_DPCM8_1X8 0x3009
#define V4L2_MBUS_FMT_SRGGB10_DPCM8_1X8 0x300d
#define V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_BE 0x3003
#define V4L2_MBUS_FMT_SBGGR10_2X8_PADHI_LE 0x3004
#define V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_BE 0x3005
#define V4L2_MBUS_FMT_SBGGR10_2X8_PADLO_LE 0x3006
#define V4L2_MBUS_FMT_SBGGR10_1X10 0x3007
#define V4L2_MBUS_FMT_SGBRG10_1X10 0x300e
#define V4L2_MBUS_FMT_SGRBG10_1X10 0x300a
#define V4L2_MBUS_FMT_SRGGB10_1X10 0x300f
#define V4L2_MBUS_FMT_SBGGR12_1X12 0x3008
#define V4L2_MBUS_FMT_SGBRG12_1X12 0x3010
#define V4L2_MBUS_FMT_SGRBG12_1X12 0x3011
#define V4L2_MBUS_FMT_SRGGB12_1X12 0x3012

/* JPEG compressed formats - next is 0x4002 */
#define V4L2_MBUS_FMT_JPEG_1X8 0x4001

/* Vendor specific formats - next is 0x5002 */

/* S5C73M3 sensor specific interleaved UYVY and JPEG */
#define V4L2_MBUS_FMT_S5C_UYVY_JPEG_1X8 0x5001




static inline int set_sensor_gpio_function(int func_set)
{
	int ret = 0;
	/* VDD select 1.8V */
//	*(volatile unsigned int*)(0xB0010104) = 0x1;
	*(volatile unsigned int*)(0xB0010130) = 0x2aaa000;
	switch (func_set) {
	case DVP_PA_LOW_8BIT:
		ret = jzgpio_set_func(GPIO_PORT_A, GPIO_FUNC_1, 0x000340ff);
		pr_info("set sensor gpio as PA-low-8bit\n");
		break;
	case DVP_PA_HIGH_8BIT:
		ret = jzgpio_set_func(GPIO_PORT_A, GPIO_FUNC_1, 0x00034ff0);
		pr_info("set sensor gpio as PA-high-8bit\n");
		break;
	case DVP_PA_LOW_10BIT:
		ret = jzgpio_set_func(GPIO_PORT_A, GPIO_FUNC_1, 0x000343ff);
		pr_info("set sensor gpio as PA-low-10bit\n");
		break;
	case DVP_PA_HIGH_10BIT:
		ret = jzgpio_set_func(GPIO_PORT_A, GPIO_FUNC_1, 0x00034ffc);
		pr_info("set sensor gpio as PA-high-10bit\n");
		break;
	case DVP_PA_12BIT:
		ret = jzgpio_set_func(GPIO_PORT_A, GPIO_FUNC_1, 0x00034fff);
		pr_info("set sensor gpio as PA-12bit\n");
		break;
	default:
		pr_err("set sensor gpio error: unknow function %d\n", func_set);
		ret = -1;
		break;
	}
	return ret;
}

#endif// __TX_SENSOR_COMMON_H__
