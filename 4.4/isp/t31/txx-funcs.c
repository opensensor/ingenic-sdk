/*
 *
 * Copyright (C) 2017 Ingenic Semiconductor Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/proc_fs.h>
#include <txx-funcs.h>

struct clk_wrapper {
	struct clk *clk;
	bool is_enabled;
};


static inline int clk_wrapper_enable(struct clk_wrapper *clk_wrap) {
	int ret = clk_prepare_enable(clk_wrap->clk);
	if (ret == 0) {
		clk_wrap->is_enabled = true;
	}
	return ret;
}

static inline void clk_wrapper_disable(struct clk_wrapper *clk_wrap) {
	clk_disable_unprepare(clk_wrap->clk);
	clk_wrap->is_enabled = false;
}

static inline bool clk_wrapper_is_enabled(struct clk_wrapper *clk_wrap) {
	return clk_wrap->is_enabled;
}


static const unsigned int __pow2_lut[33]={
		1073741824,1097253708,1121280436,1145833280,1170923762,1196563654,1222764986,1249540052,
		1276901417,1304861917,1333434672,1362633090,1392470869,1422962010,1454120821,1485961921,
		1518500250,1551751076,1585730000,1620452965,1655936265,1692196547,1729250827,1767116489,
		1805811301,1845353420,1885761398,1927054196,1969251188,2012372174,2056437387,2101467502,
		2147483648U};

uint32_t private_math_exp2(uint32_t val, const unsigned char shift_in, const unsigned char shift_out)
{
	unsigned int fract_part = (val & ((1<<shift_in)-1));
	unsigned int int_part = val >> shift_in;
	if (shift_in <= 5)
	{
		unsigned int lut_index = fract_part << (5-shift_in);
		return __pow2_lut[lut_index] >> (30 - shift_out - int_part);
	}
	else
	{
		unsigned int lut_index = fract_part >> (shift_in - 5);
		unsigned int lut_fract = fract_part & ((1<<(shift_in-5))-1);
		unsigned int a = __pow2_lut[lut_index];
		unsigned int b =  __pow2_lut[lut_index+1];
		unsigned int res = ((unsigned long long)(b - a)*lut_fract) >> (shift_in-5);
		res = (res + a) >> (30-shift_out-int_part);
		return res;
	}
}
EXPORT_SYMBOL(private_math_exp2);

uint8_t private_leading_one_position(const uint32_t in)
{
	uint8_t pos = 0;
	uint32_t val = in;
	if (val >= 1<<16) { val >>= 16; pos += 16; }
	if (val >= 1<< 8) { val >>=  8; pos +=  8; }
	if (val >= 1<< 4) { val >>=  4; pos +=  4; }
	if (val >= 1<< 2) { val >>=  2; pos +=  2; }
	if (val >= 1<< 1) {             pos +=  1; }
	return pos;
}

int private_leading_one_position_64(uint64_t val)
{
	int pos = 0;
	if (val >= (uint64_t)1<<32) { val >>= 32; pos += 32; }
	if (val >= 1<<16) { val >>= 16; pos += 16; }
	if (val >= 1<< 8) { val >>=  8; pos +=  8; }
	if (val >= 1<< 4) { val >>=  4; pos +=  4; }
	if (val >= 1<< 2) { val >>=  2; pos +=  2; }
	if (val >= 1<< 1) {             pos +=  1; }
	return pos;
}
//  y = log2(x)
//
//	input:  Integer: val
//	output: Fixed point x.y
//  y: out_precision
//
uint32_t private_log2_int_to_fixed(const uint32_t val, const uint8_t out_precision, const uint8_t shift_out)
{
	int i;
	int pos = 0;
	uint32_t a = 0;
	uint32_t b = 0;
	uint32_t in = val;
	uint32_t result = 0;
	const unsigned char precision = out_precision;

	if(0 == val)
	{
		return 0;
	}
	// integral part
	pos = private_leading_one_position(val);
	// fractional part
	a = (pos <= 15) ? (in << (15 - pos)) : (in>>(pos - 15));
	for(i = 0; i < precision; ++i)
	{
		b = a * a;
		if(b & (1<<31))
		{
			result = (result << 1) + 1;
			a = b >> 16;
		}
		else
		{
			result = (result << 1);
			a = b >> 15;
		}
	}
	return (((pos << precision) + result) << shift_out) | ((a & 0x7fff)>> (15-shift_out));
}
EXPORT_SYMBOL(private_log2_int_to_fixed);

uint32_t private_log2_int_to_fixed_64(uint64_t val, uint8_t out_precision, uint8_t shift_out)
{
	int i;
	int pos = 0;
	uint64_t a = 0;
	uint64_t b = 0;
	uint64_t in = val;
	uint64_t result = 0;
	const unsigned char precision = out_precision;

	if(0 == val)
	{
		return 0;
	}
	// integral part
	pos = private_leading_one_position_64(val);
	// fractional part
	a = (pos <= 15) ? (in << (15 - pos)) : (in>>(pos - 15));
	for(i = 0; i < precision; ++i)
	{
		b = a * a;
		if(b & (1<<31))
		{
			result = (result << 1) + 1;
			a = b >> 16;
		}
		else
		{
			result = (result << 1);
			a = b >> 15;
		}
	}
	return (uint32_t)((((pos << precision) + result) << shift_out) | ((a & 0x7fff)>> (15-shift_out)));
}
//  y = log2(x)
//
//	input:  Fixed point: x1.y1
//	output: Fixed point: x2.y2
//  y1: in_fraction
//  y2: out_precision
//
uint32_t private_log2_fixed_to_fixed(const uint32_t val, const int in_fix_point, const uint8_t out_fix_point)
{
	return private_log2_int_to_fixed(val, out_fix_point, 0) - (in_fix_point << out_fix_point);
}
EXPORT_SYMBOL(private_log2_fixed_to_fixed);

int32_t private_log2_fixed_to_fixed_64(uint64_t val, int32_t in_fix_point, uint8_t out_fix_point)
{
	return private_log2_int_to_fixed_64(val, out_fix_point, 0) - (in_fix_point << out_fix_point);
}

/********************************************
 * The following interfaces are from kernel *
 ********************************************/
static struct jz_driver_common_interfaces *pfaces = NULL;

/* platform  */
int private_platform_driver_register(struct platform_driver *drv)
{
	return platform_driver_register(drv);
}

void private_platform_driver_unregister(struct platform_driver *drv)
{
	platform_driver_unregister(drv);
}


void private_platform_set_drvdata(struct platform_device *pdev, void *data)
{
	platform_set_drvdata(pdev, data);
}

void *private_platform_get_drvdata(struct platform_device *pdev)
{
	return platform_get_drvdata(pdev);
}

int private_platform_device_register(struct platform_device *pdev)
{
	return platform_device_register(pdev);
}

void private_platform_device_unregister(struct platform_device *pdev)
{
	return platform_device_unregister(pdev);
}

struct resource *private_platform_get_resource(struct platform_device *dev,
			       unsigned int type, unsigned int num)
{
	return platform_get_resource(dev, type, num);
}

int private_dev_set_drvdata(struct device *dev, void *data)
{
	dev_set_drvdata(dev, data);
	return 0;
}

void* private_dev_get_drvdata(const struct device *dev)
{
	return dev_get_drvdata(dev);
}

int private_platform_get_irq(struct platform_device *dev, unsigned int num)
{
	return platform_get_irq(dev, num);
}
#if 0
struct resource * private_request_mem_region(resource_size_t start, resource_size_t n,
			   const char *name)
{
	return tx_request_mem_region(start, n, name);
}

void private_release_mem_region(resource_size_t start, resource_size_t n)
{
	tx_release_mem_region(start, n);
}

void __iomem * private_ioremap(phys_addr_t offset, unsigned long size)
{
	return tx_ioremap(offset, size);
}
#endif
void private_iounmap(const volatile void __iomem *addr)
{
	iounmap(addr);
}

/* interrupt interfaces */
int private_request_threaded_irq(unsigned int irq, irq_handler_t handler,
		irq_handler_t thread_fn, unsigned long irqflags,
		const char *devname, void *dev_id)
{
	return request_threaded_irq(irq, handler, thread_fn, irqflags, devname, dev_id);
}

void private_enable_irq(unsigned int irq)
{
	enable_irq(irq);
}

void private_disable_irq(unsigned int irq)
{
	disable_irq(irq);
}

void private_free_irq(unsigned int irq, void *dev_id)
{
	free_irq(irq, dev_id);
}

/* lock and mutex interfaces */
#if 0
void private_spin_lock_irqsave(spinlock_t *lock, unsigned long flags)
{
	tx_spin_lock_irqsave(lock, &flags);
}
#endif
void private_spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
{
	spin_unlock_irqrestore(lock, flags);
}
#if 0
void private_spin_lock_init(spinlock_t *lock)
{
	tx_spin_lock_init(lock);
}
#endif
void private_mutex_lock(struct mutex *lock)
{
	mutex_lock(lock);
}

void private_mutex_unlock(struct mutex *lock)
{
	mutex_unlock(lock);
}
#if 0
void private_mutex_init(struct mutex *mutex)
{
	tx_mutex_init(mutex);
}
#endif
/* clock interfaces */
struct clk * private_clk_get(struct device *dev, const char *id)
{
	return clk_get(dev, id);
}

int private_clk_enable(struct clk *clk)
{
	int ret;
	ret = clk_prepare(clk);
	if (ret) {
		// Handle error
		return ret;
	}
	ret = clk_enable(clk);
	if (ret) {
		// Handle error
		clk_unprepare(clk);
		return ret;
	}
	return 0;
}
EXPORT_SYMBOL(private_clk_enable);

int private_clk_is_enabled(struct clk *clk)
{
	struct clk_wrapper my_clk;
	return clk_wrapper_is_enabled(&my_clk);
}

void private_clk_disable(struct clk *clk)
{
	clk_disable(clk);
}
EXPORT_SYMBOL(private_clk_disable);

void private_clk_put(struct clk *clk)
{
	clk_put(clk);
}
EXPORT_SYMBOL(private_clk_put);

int private_clk_set_rate(struct clk *clk, unsigned long rate)
{
	return clk_set_rate(clk, rate);
}
EXPORT_SYMBOL(private_clk_set_rate);

unsigned long private_clk_get_rate(struct clk *clk)
{
	return clk_get_rate(clk);
}

/* i2c interfaces */
struct i2c_adapter* private_i2c_get_adapter(int nr)
{
	return i2c_get_adapter(nr);
}

void private_i2c_put_adapter(struct i2c_adapter *adap)
{
	i2c_put_adapter(adap);
}

int private_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
	return i2c_transfer(adap, msgs, num);
}
EXPORT_SYMBOL(private_i2c_transfer);

int private_i2c_register_driver(struct module *mod, struct i2c_driver *drv)
{
	return i2c_register_driver(mod, drv);
}

void private_i2c_del_driver(struct i2c_driver *drv)
{
	i2c_del_driver(drv);
}
EXPORT_SYMBOL(private_i2c_del_driver);

struct i2c_client *private_i2c_new_device(struct i2c_adapter *adap, struct i2c_board_info const *info)
{
	return i2c_new_device(adap, info);
}

void *private_i2c_get_clientdata(const struct i2c_client *dev)
{
	return i2c_get_clientdata(dev);
}
EXPORT_SYMBOL(private_i2c_get_clientdata);

void private_i2c_set_clientdata(struct i2c_client *dev, void *data)
{
	i2c_set_clientdata(dev, data);
}
EXPORT_SYMBOL(private_i2c_set_clientdata);

int private_i2c_add_driver(struct i2c_driver *drv)
{
	return i2c_register_driver(THIS_MODULE, drv);
}
EXPORT_SYMBOL(private_i2c_add_driver);

void private_i2c_unregister_device(struct i2c_client *client)
{
	i2c_unregister_device(client);
}

/* gpio interfaces */
int private_gpio_request(unsigned gpio, const char *label)
{
	return gpio_request(gpio, label);
}
EXPORT_SYMBOL(private_gpio_request);

void private_gpio_free(unsigned gpio)
{
	gpio_free(gpio);
}
EXPORT_SYMBOL(private_gpio_free);

int private_gpio_direction_output(unsigned gpio, int value)
{
	return gpio_direction_output(gpio, value);
}
EXPORT_SYMBOL(private_gpio_direction_output);

int private_gpio_direction_input(unsigned gpio)
{
	return gpio_direction_input(gpio);
}

int private_gpio_set_debounce(unsigned gpio, unsigned debounce)
{
	return gpio_set_debounce(gpio, debounce);
}

int private_jzgpio_set_func(enum gpio_port port, enum gpio_function func,unsigned long pins)
{
	return jzgpio_set_func(port, func, pins);
}
EXPORT_SYMBOL(private_jzgpio_set_func);

/* system interfaces */
void private_msleep(unsigned int msecs)
{
	msleep(msecs);
}
EXPORT_SYMBOL(private_msleep);

bool private_capable(int cap)
{
	return capable(cap);
}
EXPORT_SYMBOL(private_capable);

unsigned long long private_sched_clock(void)
{
	return sched_clock();
}

bool private_try_module_get(struct module *module)
{
	return try_module_get(module);
}

void private_module_put(struct module *module)
{
	module_put(module);
}

/* wait interfaces */
void private_init_completion(struct completion *x)
{
	init_completion(x);
}

void private_complete(struct completion *x)
{
	complete(x);
}

int private_wait_for_completion_interruptible(struct completion *x)
{
	return wait_for_completion_interruptible(x);
}

/* misc driver interfaces */
int private_misc_register(struct miscdevice *mdev)
{
	return misc_register(mdev);
}

int private_misc_deregister(struct miscdevice *mdev)
{
	misc_deregister(mdev);
	return 0;
}

/* proc file interfaces */
ssize_t private_seq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	return seq_read(file, buf, size, ppos);
}

loff_t private_seq_lseek(struct file *file, loff_t offset, int whence)
{
	return seq_lseek(file, offset, whence);
}

int private_single_release(struct inode *inode, struct file *file)
{
	return single_release(inode, file);
}

int private_single_open_size(struct file *file, int (*show)(struct seq_file *, void *),
		void *data, size_t size)
{
	return single_open_size(file, show, data, size);
}

struct proc_dir_entry* private_jz_proc_mkdir(char *s)
{
	return jz_proc_mkdir(s);
}

///* isp driver interface */
void private_get_isp_priv_mem(unsigned int *phyaddr, unsigned int *size)
{
	// get_isp_priv_mem(phyaddr, size);
	// TODO What to actually call here?
}

struct proc_dir_entry *private_proc_create_data(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct file_operations *proc_fops, void *data) {
	return proc_create_data(name, mode, parent, proc_fops, data);
}

/* Must be check the return value */
__must_check int private_driver_get_interface(void)
{
	return 0;
}
EXPORT_SYMBOL(private_driver_get_interface);
