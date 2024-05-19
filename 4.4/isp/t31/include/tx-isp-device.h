#ifndef __TX_ISP_DEVICE_H__
#define __TX_ISP_DEVICE_H__

#include <linux/errno.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <asm/irq.h>
#include <asm/io.h>

#include "txx-isp.h"
#include "txx-funcs.h"

enum tx_isp_subdev_id {
	TX_ISP_CORE_SUBDEV_ID,
	TX_ISP_LDC_SUBDEV_ID,
	TX_ISP_NCU_SUBDEV_ID,
	TX_ISP_MSCALER_SUBDEV_ID,
	TX_ISP_MAX_SUBDEV_ID,
};

#define TX_ISP_ENTITY_ENUM_MAX_DEPTH	16
struct tx_isp_module;
struct tx_isp_irq_device;
struct tx_isp_subdev;
struct tx_isp_subdev_pad;
struct tx_isp_subdev_link;

struct tx_isp_module {
	struct tx_isp_descriptor desc;
	struct device *dev;
	const char *name;
	struct miscdevice miscdev;
	/*struct list_head list;*/

	/* the interface */
	struct file_operations *ops;

	/* the interface */
	struct file_operations *debug_ops;

	/* the list header of sub-modules */
	struct tx_isp_module *submods[TX_ISP_ENTITY_ENUM_MAX_DEPTH];
	/* the module's parent */
	void *parent;
	int (*notify)(struct tx_isp_module *module, unsigned int notification, void *data);
};

/* Description of the connection between modules */
struct link_pad_description {
	char *name; 		// the module name
	unsigned char type;	// the pad type
	unsigned char index;	// the index in array of some pad type
};

struct tx_isp_link_config {
	struct link_pad_description src;
	struct link_pad_description dst;
	unsigned int flag;
};

struct tx_isp_link_configs {
	struct tx_isp_link_config *config;
	unsigned int length;
};

/* The description of module entity */
struct tx_isp_subdev_link {
	struct tx_isp_subdev_pad *source;	/* Source pad */
	struct tx_isp_subdev_pad *sink;		/* Sink pad  */
	struct tx_isp_subdev_link *reverse;	/* Link in the reverse direction */
	unsigned int flag;				/* Link flag (TX_ISP_LINKTYPE_*) */
	unsigned int state;				/* Link state (TX_ISP_MODULE_*) */
};

struct tx_isp_subdev_pad {
	struct tx_isp_subdev *sd;	/* Subdev this pad belongs to */
	unsigned char index;			/* Pad index in the entity pads array */
	unsigned char type;			/* Pad type (TX_ISP_PADTYPE_*) */
	unsigned char links_type;			/* Pad link type (TX_ISP_PADLINK_*) */
	unsigned char state;				/* Pad state (TX_ISP_PADSTATE_*) */
	struct tx_isp_subdev_link link;	/* The active link */
	int (*event)(struct tx_isp_subdev_pad *, unsigned int event, void *data);
	void *priv;
};

struct tx_isp_dbg_register {
	char *name;
	unsigned int size;
	unsigned long long reg;
	unsigned long long val;
};

struct tx_isp_dbg_register_list {
	char *name;
	unsigned int size;
	unsigned short *reg;
};

struct tx_isp_chip_ident {
	char name[32];
	char *revision;
	unsigned int ident;
};

struct tx_isp_subdev_core_ops {
	int (*g_chip_ident)(struct tx_isp_subdev *sd, struct tx_isp_chip_ident *chip);
	int (*init)(struct tx_isp_subdev *sd, int on);		// clk's, power's and init ops.
	int (*reset)(struct tx_isp_subdev *sd, int on);
	int (*g_register)(struct tx_isp_subdev *sd, struct tx_isp_dbg_register *reg);
	int (*g_register_list)(struct tx_isp_subdev *sd, struct tx_isp_dbg_register_list *reg);
	int (*g_register_all)(struct tx_isp_subdev *sd, struct tx_isp_dbg_register_list *reg);
	int (*s_register)(struct tx_isp_subdev *sd, const struct tx_isp_dbg_register *reg);
	int (*ioctl)(struct tx_isp_subdev *sd, unsigned int cmd, void *arg);
	irqreturn_t (*interrupt_service_routine)(struct tx_isp_subdev *sd, u32 status, bool *handled);
	irqreturn_t (*interrupt_service_thread)(struct tx_isp_subdev *sd, void *data);
};

struct tx_isp_subdev_video_ops {
	int (*s_stream)(struct tx_isp_subdev *sd, int enable);
	int (*link_stream)(struct tx_isp_subdev *sd, int enable);
	int (*link_setup)(const struct tx_isp_subdev_pad *local,
			  const struct tx_isp_subdev_pad *remote, u32 flags);
};

struct tx_isp_subdev_sensor_ops {
	int (*release_all_sensor)(struct tx_isp_subdev *sd);
	int (*sync_sensor_attr)(struct tx_isp_subdev *sd, void *arg);
	int (*ioctl)(struct tx_isp_subdev *sd, unsigned int cmd, void *arg);
};

struct tx_isp_subdev_pad_ops {
	int (*g_fmt)(struct tx_isp_subdev *sd, struct v4l2_format *f);
	int (*s_fmt)(struct tx_isp_subdev *sd, struct v4l2_format *f);
	int (*streamon)(struct tx_isp_subdev *sd, void *data);
	int (*streamoff)(struct tx_isp_subdev *sd, void *data);
};

struct tx_isp_irq_device {
	spinlock_t slock;
	/*struct mutex mlock;*/
	int irq;
	void (*enable_irq)(struct tx_isp_irq_device *irq_dev);
	void (*disable_irq)(struct tx_isp_irq_device *irq_dev);
};

enum tx_isp_module_state {
	TX_ISP_MODULE_UNDEFINE = 0,
	TX_ISP_MODULE_SLAKE,
	TX_ISP_MODULE_ACTIVATE,
	TX_ISP_MODULE_DEINIT = TX_ISP_MODULE_ACTIVATE,
	TX_ISP_MODULE_INIT,
	TX_ISP_MODULE_RUNNING,
};

/*
 * Internal ops. Never call this from drivers, only the tx isp device can call
 * these ops.
 *
 * activate_module: called when this subdev is enabled. When called the module
 * could be operated;
 *
 * slake_module: called when this subdev is disabled. When called the
 *	module couldn't be operated.
 *
 */
struct tx_isp_subdev_internal_ops {
	int (*activate_module)(struct tx_isp_subdev *sd);
	int (*slake_module)(struct tx_isp_subdev *sd);
};

struct tx_isp_subdev_ops {
	struct tx_isp_subdev_core_ops		*core;
	struct tx_isp_subdev_video_ops		*video;
	struct tx_isp_subdev_pad_ops		*pad;
	struct tx_isp_subdev_sensor_ops		*sensor;
	struct tx_isp_subdev_internal_ops	*internal;
};

#define tx_isp_call_module_notify(ent, args...)				\
	(!(ent) ? -ENOENT : (((ent)->notify) ?				\
			     (ent)->notify(((ent)->parent), ##args) : -ENOIOCTLCMD))

#define tx_isp_call_subdev_notify(ent, args...)				\
	(!(ent) ? -ENOENT : (((ent)->module.notify) ?			\
			     ((ent)->module.notify(&((ent)->module), ##args)): -ENOIOCTLCMD))

#define tx_isp_call_subdev_event(ent, args...)				\
	(!(ent) ? -ENOENT : (((ent)->event) ?				\
			     (ent)->event((ent), ##args) : -ENOIOCTLCMD))

#define tx_isp_subdev_call(sd, o, f, args...)				\
	(!(sd) ? -ENODEV : (((sd)->ops->o && (sd)->ops->o->f) ?		\
			    (sd)->ops->o->f((sd) , ##args) : -ENOIOCTLCMD))

struct tx_isp_subdev {
	struct tx_isp_module module;
	struct tx_isp_irq_device irqdev;
	struct tx_isp_chip_ident chip;

	/* basic members */
	struct resource *res;
	void __iomem *base;
	struct clk **clks;
	unsigned int clk_num;
	struct tx_isp_subdev_ops *ops;

	/* expanded members */
	unsigned short num_outpads;			/* Number of sink pads */
	unsigned short num_inpads;			/* Number of source pads */

	struct tx_isp_subdev_pad *outpads;		/* OutPads array (num_pads elements) */
	struct tx_isp_subdev_pad *inpads;		/* InPads array (num_pads elements) */

	void *dev_priv;
	void *host_priv;
};

#define TX_ISP_PLATFORM_MAX_NUM 16

struct tx_isp_platform {
	struct platform_device *dev;
	struct platform_driver *drv;
};

struct tx_isp_device {
	struct tx_isp_module module;
	unsigned int pdev_num;
	struct tx_isp_platform pdevs[TX_ISP_PLATFORM_MAX_NUM];

	char *version;
	struct mutex mlock;
	spinlock_t slock;
	int refcnt;

	int active_link;
	/* debug parameters */
	struct proc_dir_entry *proc;
};

#define miscdev_to_module(mdev) (container_of(mdev, struct tx_isp_module, miscdev))
#define module_to_subdev(mod) (container_of(mod, struct tx_isp_subdev, module))
#define irqdev_to_subdev(dev) (container_of(dev, struct tx_isp_subdev, irqdev))
#define module_to_ispdev(mod) (container_of(mod, struct tx_isp_device, module))


#define tx_isp_sd_readl(sd, reg)		\
	tx_isp_readl(((sd)->base), reg)
#define tx_isp_sd_writel(sd, reg, value)	\
	tx_isp_writel(((sd)->base), reg, value)



struct jz_driver_common_interfaces {
	unsigned int flags_0;			// The flags must be checked.
	/* platform interface */
	int (*priv_platform_driver_register)(struct platform_driver *drv);
	void (*priv_platform_driver_unregister)(struct platform_driver *drv);
	void (*priv_platform_set_drvdata)(struct platform_device *pdev, void *data);
	void *(*priv_platform_get_drvdata)(const struct platform_device *pdev);
	int (*priv_platform_device_register)(struct platform_device *pdev);
	void (*priv_platform_device_unregister)(struct platform_device *pdev);
	struct resource *(*priv_platform_get_resource)(struct platform_device *dev,
												   unsigned int type, unsigned int num);
	int (*priv_dev_set_drvdata)(struct device *dev, void *data);
	void* (*priv_dev_get_drvdata)(const struct device *dev);
	int (*priv_platform_get_irq)(struct platform_device *dev, unsigned int num);
	struct resource * (*priv_request_mem_region)(resource_size_t start, resource_size_t n,
												 const char *name);
	void (*priv_release_mem_region)(resource_size_t start, resource_size_t n);
	void __iomem * (*priv_ioremap)(phys_addr_t offset, unsigned long size);
	void (*priv_iounmap)(const volatile void __iomem *addr);
	unsigned int reserve_platform[8];

	/* interrupt interface */
	int (*priv_request_threaded_irq)(unsigned int irq, irq_handler_t handler,
									 irq_handler_t thread_fn, unsigned long irqflags,
									 const char *devname, void *dev_id);
	void (*priv_enable_irq)(unsigned int irq);
	void (*priv_disable_irq)(unsigned int irq);
	void (*priv_free_irq)(unsigned int irq, void *dev_id);

	/* lock and mutex interface */
	void (*priv_spin_lock_irqsave)(spinlock_t *lock, unsigned long *flags);
	void (*priv_spin_unlock_irqrestore)(spinlock_t *lock, unsigned long flags);
	void (*priv_spin_lock_init)(spinlock_t *lock);
	void (*priv_mutex_lock)(struct mutex *lock);
	void (*priv_mutex_unlock)(struct mutex *lock);
	void (*priv_raw_mutex_init)(struct mutex *lock, const char *name, struct lock_class_key *key);


	/* i2c interfaces */
	struct i2c_adapter* (*priv_i2c_get_adapter)(int nr);
	void (*priv_i2c_put_adapter)(struct i2c_adapter *adap);
	int (*priv_i2c_transfer)(struct i2c_adapter *adap, struct i2c_msg *msgs, int num);
	int (*priv_i2c_register_driver)(struct module *, struct i2c_driver *);
	void (*priv_i2c_del_driver)(struct i2c_driver *);

	struct i2c_client *(*priv_i2c_new_device)(struct i2c_adapter *adap, struct i2c_board_info const *info);
	void *(*priv_i2c_get_clientdata)(const struct i2c_client *dev);
	void (*priv_i2c_set_clientdata)(struct i2c_client *dev, void *data);
	void (*priv_i2c_unregister_device)(struct i2c_client *client);

	unsigned int reserver_i2c[8];

	/* gpio interfaces */
	int (*priv_gpio_request)(unsigned gpio, const char *label);
	void (*priv_gpio_free)(unsigned gpio);
	int (*priv_gpio_direction_output)(unsigned gpio, int value);
	int (*priv_gpio_direction_input)(unsigned gpio);
	int (*priv_gpio_set_debounce)(unsigned gpio, unsigned debounce);
	int (*priv_jzgpio_set_func)(enum gpio_port port, enum gpio_function func,unsigned long pins);
	int (*priv_jzgpio_ctrl_pull)(enum gpio_port port, int enable_pull,unsigned long pins);

	/* system interface */
	void (*priv_msleep)(unsigned int msecs);
	bool (*priv_capable)(int cap);
	unsigned long long (*priv_sched_clock)(void);
	bool (*priv_try_module_get)(struct module *module);
	int (*priv_request_module)(bool wait, const char *fmt, ...);
	void (*priv_module_put)(struct module *module);

	/* wait */
	void (*priv_init_completion)(struct completion *x);
	void (*priv_complete)(struct completion *x);
	int (*priv_wait_for_completion_interruptible)(struct completion *x);
	int (*priv_wait_event_interruptible)(wait_queue_head_t *q, int (*state)(void *), void *data);
	void (*priv_wake_up_all)(wait_queue_head_t *q);
	void (*priv_wake_up)(wait_queue_head_t *q);
	void (*priv_init_waitqueue_head)(wait_queue_head_t *q);
	unsigned long (*priv_wait_for_completion_timeout)(struct completion *x, unsigned long timeout);

	/* misc */
	int (*priv_misc_register)(struct miscdevice *mdev);
	int (*priv_misc_deregister)(struct miscdevice *mdev);
	struct proc_dir_entry *(*priv_proc_create_data)(const char *name, umode_t mode,
													struct proc_dir_entry *parent,
													const struct file_operations *proc_fops,
													void *data);
	/* proc */
	ssize_t (*priv_seq_read)(struct file *file, char __user *buf, size_t size, loff_t *ppos);
	loff_t (*priv_seq_lseek)(struct file *file, loff_t offset, int whence);
	int (*priv_single_release)(struct inode *inode, struct file *file);
	int (*priv_single_open_size)(struct file *file, int (*show)(struct seq_file *, void *),
								 void *data, size_t size);
	struct proc_dir_entry* (*priv_jz_proc_mkdir)(char *s);
	void (*priv_proc_remove)(struct proc_dir_entry *de);
	int (*priv_seq_printf)(struct seq_file *m, const char *f, ...);
	unsigned long long (*priv_simple_strtoull)(const char *cp, char **endp, unsigned int base);

	/* kthread */
	bool (*priv_kthread_should_stop)(void);
	struct task_struct* (*priv_kthread_run)(int (*threadfn)(void *data), void *data, const char namefmt[]);
	int (*priv_kthread_stop)(struct task_struct *k);

	void * (*priv_kmalloc)(size_t s, gfp_t gfp);
	void (*priv_kfree)(void *p);
	long (*priv_copy_from_user)(void *to, const void __user *from, long size);
	long (*priv_copy_to_user)(void __user *to, const void *from, long size);

	/* netlink */
	struct sk_buff* (*priv_nlmsg_new)(size_t payload, gfp_t flags);
	struct nlmsghdr *(*priv_nlmsg_put)(struct sk_buff *skb, u32 portid, u32 seq,
									   int type, int payload, int flags);
	int (*priv_netlink_unicast)(struct sock *ssk, struct sk_buff *skb,
								u32 portid, int nonblock);
	struct sock *(*priv_netlink_kernel_create)(struct net *net, int unit, struct netlink_kernel_cfg *cfg);
	void (*priv_sock_release)(struct socket *sock);

	struct file *(*priv_filp_open)(const char *filename, int flags, umode_t mode);
	int (*priv_filp_close)(struct file *filp, fl_owner_t id);
	ssize_t (*priv_vfs_read)(struct file *file, char __user *buf, size_t count, loff_t *pos);
	ssize_t (*priv_vfs_write)(struct file *file, const char __user *buf, size_t count, loff_t *pos);
	loff_t (*priv_vfs_llseek)(struct file *file, loff_t offset, int whence);

	mm_segment_t (*priv_get_fs)(void);
	void (*priv_set_fs)(mm_segment_t val);
	void (*priv_dma_cache_sync)(struct device *dev, void *vaddr, size_t size,
								enum dma_data_direction direction);

	void (*priv_getrawmonotonic)(struct timespec *ts);

	struct net *(*priv_get_init_net)(void);
	/* isp driver interface */
	void (*get_isp_priv_mem)(unsigned int *phyaddr, unsigned int *size);
	unsigned int flags_1;			// The flags must be checked.
};


void *get_driver_common_interfaces(void);

int private_reset_tx_isp_module(enum tx_isp_subdev_id id);
int tx_isp_reg_set(struct tx_isp_subdev *sd, unsigned int reg, int start, int end, int val);

int tx_isp_subdev_init(struct platform_device *pdev, struct tx_isp_subdev *sd, struct tx_isp_subdev_ops *ops);
void tx_isp_subdev_deinit(struct tx_isp_subdev *sd);
int tx_isp_send_event_to_remote(struct tx_isp_subdev_pad *pad, unsigned int cmd, void *data);

static inline void tx_isp_set_module_nodeops(struct tx_isp_module *module, struct file_operations *ops)
{
	module->ops = ops;
}

static inline void tx_isp_set_module_debugops(struct tx_isp_module *module, struct file_operations *ops)
{
	module->debug_ops = ops;
}

static inline void tx_isp_set_subdev_nodeops(struct tx_isp_subdev *sd, struct file_operations *ops)
{
	tx_isp_set_module_nodeops(&sd->module, ops);
}

static inline void tx_isp_set_subdev_debugops(struct tx_isp_subdev *sd, struct file_operations *ops)
{
	tx_isp_set_module_debugops(&sd->module, ops);
}

static inline void tx_isp_set_subdevdata(struct tx_isp_subdev *sd, void *data)
{
	sd->dev_priv = data;
}

static inline void *tx_isp_get_subdevdata(struct tx_isp_subdev *sd)
{
	return sd->dev_priv;
}

static inline void tx_isp_set_subdev_hostdata(struct tx_isp_subdev *sd, void *data)
{
	sd->host_priv = data;
}

static inline void *tx_isp_get_subdev_hostdata(struct tx_isp_subdev *sd)
{
	return sd->host_priv;
}
#endif/*__TX_ISP_DEVICE_H__*/
