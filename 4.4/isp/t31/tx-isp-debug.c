#include <linux/debugfs.h>
#include <linux/module.h>
#include <tx-isp-debug.h>
#include <linux/vmalloc.h>

#include "txx-funcs.h"
#include "tx-isp-device.h"

/* -------------------debugfs interface------------------- */
static int print_level = ISP_WARNING_LEVEL;
//module_param(print_level, int, S_IRUGO);
//MODULE_PARM_DESC(print_level, "isp print level");
//
static int isp_clk = 100000000;
//module_param(isp_clk, int, S_IRUGO);
//MODULE_PARM_DESC(isp_clk, "isp clock freq");

//extern int isp_ch0_pre_dequeue_time;
//module_param(isp_ch0_pre_dequeue_time, int, S_IRUGO);
//MODULE_PARM_DESC(isp_ch0_pre_dequeue_time, "isp pre dequeue time, unit ms");
//
//extern int isp_ch0_pre_dequeue_interrupt_process;
//module_param(isp_ch0_pre_dequeue_interrupt_process, int, S_IRUGO);
//MODULE_PARM_DESC(isp_ch0_pre_dequeue_interrupt_process, "isp pre dequeue interrupt process");
//
//extern int isp_ch0_pre_dequeue_valid_lines;
//module_param(isp_ch0_pre_dequeue_valid_lines, int, S_IRUGO);
//MODULE_PARM_DESC(isp_ch0_pre_dequeue_valid_lines, "isp pre dequeue valid lines");
//
//extern int isp_ch1_dequeue_delay_time;
//module_param(isp_ch1_dequeue_delay_time, int, S_IRUGO);
//MODULE_PARM_DESC(isp_ch1_dequeue_delay_time, "isp pre dequeue time, unit ms");
//
//extern int isp_day_night_switch_drop_frame_num;
//module_param(isp_day_night_switch_drop_frame_num, int, S_IRUGO);
//MODULE_PARM_DESC(isp_day_night_switch_drop_frame_num, "isp day night switch drop frame number");
//
//extern int isp_memopt;
//module_param(isp_memopt, int, S_IRUGO);
//MODULE_PARM_DESC(isp_memopt, "isp memory optimize");

int isp_printf(unsigned int level, unsigned char *fmt, ...)
{
	struct va_format vaf;
	va_list args;
	int r = 0;

	if(level >= print_level){
		va_start(args, fmt);

		vaf.fmt = fmt;
		vaf.va = &args;

		r = printk("%pV",&vaf);
		va_end(args);
		if(level >= ISP_ERROR_LEVEL)
			dump_stack();
	}
	return r;
}
EXPORT_SYMBOL(isp_printf);

int get_isp_clk(void)
{
	return isp_clk;
}

void *private_vmalloc(unsigned long size)
{
	void *addr = vmalloc(size);
	return addr;
}

void private_vfree(const void *addr)
{
	vfree(addr);
}

ktime_t private_ktime_set(const long secs, const unsigned long nsecs)
{
	return ktime_set(secs, nsecs);
}

void private_set_current_state(unsigned int state)
{
	__set_current_state(state);
	return;
}


int private_schedule_hrtimeout(ktime_t *ex, const enum hrtimer_mode mode)
{
	return schedule_hrtimeout(ex, mode);
}

bool private_schedule_work(struct work_struct *work)
{
	return schedule_work(work);
}


void private_do_gettimeofday(struct timeval *tv)
{
	do_gettimeofday(tv);
	return;
}


void private_dma_sync_single_for_device(struct device *dev,
							      dma_addr_t addr, size_t size, enum dma_data_direction dir)
{
	dma_sync_single_for_device(dev, addr, size, dir);
	return;
}


struct resource * private_request_mem_region(resource_size_t start, resource_size_t n,
													const char *name)
{
	return request_mem_region(start, n, name);
}
EXPORT_SYMBOL(private_request_mem_region);

void private_release_mem_region(resource_size_t start, resource_size_t n)
{
	release_mem_region(start, n);
}
EXPORT_SYMBOL(private_release_mem_region);

void __iomem * private_ioremap(phys_addr_t offset, unsigned long size)
{
return ioremap(offset, size);
}
EXPORT_SYMBOL(private_ioremap);

void private_spin_lock_irqsave(spinlock_t *lock, unsigned long *flags)
{
	spin_lock_irqsave(spinlock_check(lock), *flags);
}
EXPORT_SYMBOL(private_spin_lock_irqsave);

void private_spin_lock_init(spinlock_t *lock)
{
	spin_lock_init(lock);
}
EXPORT_SYMBOL(private_spin_lock_init);

void private_raw_mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
	__mutex_init(lock, name, key);
}
EXPORT_SYMBOL(private_raw_mutex_init);

int private_request_module(bool wait, const char *fmt, ...)
{
	int ret = 0;
	struct va_format vaf;
	va_list args;

	va_start(args, fmt);
	vaf.fmt = fmt;
	vaf.va = &args;
	ret = request_module("%pV", &vaf);
	va_end(args);

	return ret;
}
EXPORT_SYMBOL(private_request_module);

//static struct sk_buff *private_nlmsg_new(size_t payload, gfp_t flags)
//{
//	return nlmsg_new(payload, flags);
//}
//
//static struct nlmsghdr *private_nlmsg_put(struct sk_buff *skb, u32 portid, u32 seq,
//										  int type, int payload, int flags)
//{
//	return nlmsg_put(skb, portid, seq, type, payload, flags);
//}


struct sock *private_netlink_kernel_create(struct net *net, int unit, struct netlink_kernel_cfg *cfg) {
	return netlink_kernel_create(net, unit, cfg);
}
EXPORT_SYMBOL(private_netlink_kernel_create);


mm_segment_t private_get_fs(void)
{
	return get_fs();
}
EXPORT_SYMBOL(private_get_fs);

void private_set_fs(mm_segment_t val)
{
	set_fs(val);
}
EXPORT_SYMBOL(private_set_fs);

extern struct net init_net;
struct net *private_get_init_net(void)
{
	return &init_net;
}
EXPORT_SYMBOL(private_get_init_net);




///* Must be check the return value */
//__must_check int private_get_driver_interface(struct jz_driver_common_interfaces **pfaces)
//{
//	if(pfaces == NULL)
//		return -1;
//	*pfaces = get_driver_common_interfaces();
//	if(*pfaces && ((*pfaces)->flags_0 != (unsigned int)printk || (*pfaces)->flags_0 !=(*pfaces)->flags_1)){
//		ISP_ERROR("flags = 0x%08x, jzflags = %p,0x%08x", (*pfaces)->flags_0, printk, (*pfaces)->flags_1);
//		return -1;
//	}else
//		return 0;
//}
