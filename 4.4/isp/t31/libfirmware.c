typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned long long    qword;
typedef int    sdword;
typedef long long    sqword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef enum Elf32_GPRMask_MIPS {
    gpr_zero=1,
    gpr_at=2,
    gpr_v0=4,
    gpr_v1=8,
    gpr_a0=16,
    gpr_a1=32,
    gpr_a2=64,
    gpr_a3=128,
    gpr_t0=256,
    gpr_t1=512,
    gpr_t2=1024,
    gpr_t3=2048,
    gpr_t4=4096,
    gpr_t5=8192,
    gpr_t6=16384,
    gpr_t7=32768,
    gpr_s0=65536,
    gpr_s1=131072,
    gpr_s2=262144,
    gpr_s3=524288,
    gpr_s4=1048576,
    gpr_s5=2097152,
    gpr_s6=4194304,
    gpr_s7=8388608,
    gpr_t8=16777216,
    gpr_t9=33554432,
    gpr_k0=67108864,
    gpr_k1=134217728,
    gpr_gp=268435456,
    gpr_sp=536870912,
    gpr_fp=1073741824,
    gpr_ra=2147483648
} Elf32_GPRMask_MIPS;

typedef ulong size_t;

typedef longlong qsize_t;

typedef ushort umode_t;

typedef dword u32;

typedef dword __kernel_gid32_t;

typedef longlong __kernel_loff_t;

typedef word __u16;

typedef int __kernel_ssize_t;

typedef char s8;

typedef qword __u64;

typedef bool _Bool;

typedef uint fmode_t;

typedef uint __kernel_size_t;

typedef uint blkcnt_t;

typedef dword __u32;

typedef sdword __s32;

typedef int __kernel_long_t;

typedef uint sector_t;

typedef word u16;

typedef uchar u8;

typedef sqword s64;

typedef qword u64;

typedef dword __kernel_uid32_t;

typedef uint gfp_t;

typedef struct completion completion, *Pcompletion;

typedef struct __wait_queue_head __wait_queue_head, *P__wait_queue_head;

typedef struct __wait_queue_head wait_queue_head_t;

typedef struct spinlock spinlock, *Pspinlock;

typedef struct spinlock spinlock_t;

typedef struct list_head list_head, *Plist_head;

typedef union anon_union_0_1_a8932bbd_for_spinlock_0 anon_union_0_1_a8932bbd_for_spinlock_0, *Panon_union_0_1_a8932bbd_for_spinlock_0;

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

union anon_union_0_1_a8932bbd_for_spinlock_0 { // Missing member rlock : raw_spinlock at offset unknown [data type larger than union]
};

struct spinlock {
    union anon_union_0_1_a8932bbd_for_spinlock_0 field_0;
};

struct __wait_queue_head {
    spinlock_t lock;
    struct list_head task_list;
};

struct completion {
    uint done;
    wait_queue_head_t wait;
};

typedef struct idr_layer idr_layer, *Pidr_layer;

typedef union anon_union_32_2_c44092ce_for_idr_layer_4 anon_union_32_2_c44092ce_for_idr_layer_4, *Panon_union_32_2_c44092ce_for_idr_layer_4;

typedef struct callback_head callback_head, *Pcallback_head;

struct callback_head {
    struct callback_head *next;
    void (*func)(struct callback_head *);
};

union anon_union_32_2_c44092ce_for_idr_layer_4 {
    ulong bitmap[8];
    struct callback_head callback_head;
};

struct idr_layer {
    int prefix;
    int layer;
    struct idr_layer *ary[256];
    int count;
    union anon_union_32_2_c44092ce_for_idr_layer_4 field_4;
};

typedef struct ida ida, *Pida;

typedef struct idr idr, *Pidr;

typedef struct ida_bitmap ida_bitmap, *Pida_bitmap;

struct idr {
    struct idr_layer *hint;
    struct idr_layer *top;
    int layers;
    int cur;
    spinlock_t lock;
    int id_free_cnt;
    struct idr_layer *id_free;
};

struct ida {
    struct idr idr;
    struct ida_bitmap *free_bitmap;
};

struct ida_bitmap {
    long nr_busy;
    ulong bitmap[31];
};

typedef struct arch_rwlock_t arch_rwlock_t, *Parch_rwlock_t;

struct arch_rwlock_t {
};

typedef struct arch_spinlock_t arch_spinlock_t, *Parch_spinlock_t;

struct arch_spinlock_t {
};

typedef struct mm_segment_t mm_segment_t, *Pmm_segment_t;

struct mm_segment_t {
    ulong seg;
};

typedef __kernel_ssize_t ssize_t;

typedef struct hlist_node hlist_node, *Phlist_node;

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};


// WARNING! conflicting data type names: /DWARF/types.h/size_t - /stddef.h/size_t

typedef __u32 __kernel_dev_t;

typedef struct atomic_t atomic_t, *Patomic_t;

struct atomic_t {
    int counter;
};

typedef struct hlist_head hlist_head, *Phlist_head;

struct hlist_head {
    struct hlist_node *first;
};

typedef __kernel_uid32_t uid_t;

typedef __kernel_loff_t loff_t;

typedef __kernel_gid32_t gid_t;

typedef __kernel_long_t __kernel_time_t;

typedef __kernel_time_t time_t;

typedef __kernel_dev_t dev_t;

typedef struct lockref lockref, *Plockref;

typedef union anon_union_4_1_2f67eb89_for_lockref_0 anon_union_4_1_2f67eb89_for_lockref_0, *Panon_union_4_1_2f67eb89_for_lockref_0;

typedef struct anon_struct_4_2_d9f537bb_for_anon_union_4_1_2f67eb89_for_lockref_0_0 anon_struct_4_2_d9f537bb_for_anon_union_4_1_2f67eb89_for_lockref_0_0, *Panon_struct_4_2_d9f537bb_for_anon_union_4_1_2f67eb89_for_lockref_0_0;

struct anon_struct_4_2_d9f537bb_for_anon_union_4_1_2f67eb89_for_lockref_0_0 {
    spinlock_t lock;
    int count;
};

union anon_union_4_1_2f67eb89_for_lockref_0 {
    struct anon_struct_4_2_d9f537bb_for_anon_union_4_1_2f67eb89_for_lockref_0_0 field_0;
};

struct lockref {
    union anon_union_4_1_2f67eb89_for_lockref_0 field_0;
};

typedef enum migrate_mode {
    MIGRATE_ASYNC=0,
    MIGRATE_SYNC_LIGHT=1,
    MIGRATE_SYNC=2
} migrate_mode;

typedef struct elf32_sym elf32_sym, *Pelf32_sym;

typedef struct elf32_sym Elf32_Sym;

typedef __u32 Elf32_Word;

typedef __u32 Elf32_Addr;

typedef __u16 Elf32_Half;

struct elf32_sym {
    Elf32_Word st_name;
    Elf32_Addr st_value;
    Elf32_Word st_size;
    uchar st_info;
    uchar st_other;
    Elf32_Half st_shndx;
};

typedef struct kset kset, *Pkset;

typedef struct kobject kobject, *Pkobject;

typedef struct kset_uevent_ops kset_uevent_ops, *Pkset_uevent_ops;

typedef struct kobj_uevent_env kobj_uevent_env, *Pkobj_uevent_env;

typedef struct kobj_type kobj_type, *Pkobj_type;

typedef struct kobj_ns_type_operations kobj_ns_type_operations, *Pkobj_ns_type_operations;

typedef struct sock sock, *Psock;

typedef struct kernfs_node kernfs_node, *Pkernfs_node;

typedef struct kref kref, *Pkref;

typedef struct sysfs_ops sysfs_ops, *Psysfs_ops;

typedef struct attribute attribute, *Pattribute;

typedef enum kobj_ns_type {
    KOBJ_NS_TYPE_NONE=0,
    KOBJ_NS_TYPE_NET=1,
    KOBJ_NS_TYPES=2
} kobj_ns_type;

typedef struct rb_node rb_node, *Prb_node;

typedef union anon_union_24_3_f2422723_for_kernfs_node_7 anon_union_24_3_f2422723_for_kernfs_node_7, *Panon_union_24_3_f2422723_for_kernfs_node_7;

typedef struct kernfs_iattrs kernfs_iattrs, *Pkernfs_iattrs;

typedef struct kernfs_elem_dir kernfs_elem_dir, *Pkernfs_elem_dir;

typedef struct kernfs_elem_symlink kernfs_elem_symlink, *Pkernfs_elem_symlink;

typedef struct kernfs_elem_attr kernfs_elem_attr, *Pkernfs_elem_attr;

typedef struct rb_root rb_root, *Prb_root;

typedef struct kernfs_root kernfs_root, *Pkernfs_root;

typedef struct kernfs_ops kernfs_ops, *Pkernfs_ops;

typedef struct seq_file seq_file, *Pseq_file;

typedef struct kernfs_open_file kernfs_open_file, *Pkernfs_open_file;

typedef struct vm_area_struct vm_area_struct, *Pvm_area_struct;

typedef struct kernfs_open_node kernfs_open_node, *Pkernfs_open_node;

typedef struct kernfs_syscall_ops kernfs_syscall_ops, *Pkernfs_syscall_ops;

typedef struct file file, *Pfile;

typedef struct mutex mutex, *Pmutex;

typedef struct vm_operations_struct vm_operations_struct, *Pvm_operations_struct;

typedef union anon_union_8_2_834e7c5b_for_f_u anon_union_8_2_834e7c5b_for_f_u, *Panon_union_8_2_834e7c5b_for_f_u;

typedef struct path path, *Ppath;

typedef struct inode inode, *Pinode;

typedef struct file_operations file_operations, *Pfile_operations;

typedef struct kiocb kiocb, *Pkiocb;

typedef struct iov_iter iov_iter, *Piov_iter;

typedef struct dir_context dir_context, *Pdir_context;

typedef struct poll_table_struct poll_table_struct, *Ppoll_table_struct;

typedef void *fl_owner_t;

typedef struct file_lock file_lock, *Pfile_lock;

typedef struct page page, *Ppage;

typedef struct pipe_inode_info pipe_inode_info, *Ppipe_inode_info;

typedef struct atomic_t atomic_long_t;

typedef struct fown_struct fown_struct, *Pfown_struct;

typedef struct cred cred, *Pcred;

typedef struct file_ra_state file_ra_state, *Pfile_ra_state;

typedef struct address_space address_space, *Paddress_space;

typedef struct llist_node llist_node, *Pllist_node;

typedef struct vfsmount vfsmount, *Pvfsmount;

typedef struct dentry dentry, *Pdentry;

typedef struct kuid_t kuid_t, *Pkuid_t;

typedef struct kgid_t kgid_t, *Pkgid_t;

typedef struct posix_acl posix_acl, *Pposix_acl;

typedef struct inode_operations inode_operations, *Pinode_operations;

typedef struct iattr iattr, *Piattr;

typedef struct kstat kstat, *Pkstat;

typedef struct fiemap_extent_info fiemap_extent_info, *Pfiemap_extent_info;

typedef struct timespec timespec, *Ptimespec;

typedef struct super_block super_block, *Psuper_block;

typedef union anon_union_4_2_26e7ee41_for_inode_11 anon_union_4_2_26e7ee41_for_inode_11, *Panon_union_4_2_26e7ee41_for_inode_11;

typedef union anon_union_8_2_76d55e2d_for_inode_29 anon_union_8_2_76d55e2d_for_inode_29, *Panon_union_8_2_76d55e2d_for_inode_29;

typedef struct file_lock_context file_lock_context, *Pfile_lock_context;

typedef union anon_union_4_4_6df45cb4_for_inode_38 anon_union_4_4_6df45cb4_for_inode_38, *Panon_union_4_4_6df45cb4_for_inode_38;

typedef struct module module, *Pmodule;

typedef int (*filldir_t)(struct dir_context *, char *, int, loff_t, u64, uint);

typedef struct pid pid, *Ppid;

typedef struct fasync_struct fasync_struct, *Pfasync_struct;

typedef struct file_lock_operations file_lock_operations, *Pfile_lock_operations;

typedef struct lock_manager_operations lock_manager_operations, *Plock_manager_operations;

typedef union anon_union_16_3_6ffd4daa_for_fl_u anon_union_16_3_6ffd4daa_for_fl_u, *Panon_union_16_3_6ffd4daa_for_fl_u;

typedef struct rwlock_t rwlock_t, *Prwlock_t;

typedef enum pid_type {
    PIDTYPE_PID=0,
    PIDTYPE_PGID=1,
    PIDTYPE_SID=2,
    PIDTYPE_MAX=3
} pid_type;

typedef struct radix_tree_root radix_tree_root, *Pradix_tree_root;

typedef struct rw_semaphore rw_semaphore, *Prw_semaphore;

typedef struct address_space_operations address_space_operations, *Paddress_space_operations;

typedef struct writeback_control writeback_control, *Pwriteback_control;

typedef struct swap_info_struct swap_info_struct, *Pswap_info_struct;

typedef struct seqcount seqcount, *Pseqcount;

typedef struct seqcount seqcount_t;

typedef struct hlist_bl_node hlist_bl_node, *Phlist_bl_node;

typedef struct qstr qstr, *Pqstr;

typedef struct dentry_operations dentry_operations, *Pdentry_operations;

typedef union anon_union_8_2_70c2e615_for_d_u anon_union_8_2_70c2e615_for_d_u, *Panon_union_8_2_70c2e615_for_d_u;

typedef struct fiemap_extent fiemap_extent, *Pfiemap_extent;

typedef struct file_system_type file_system_type, *Pfile_system_type;

typedef struct super_operations super_operations, *Psuper_operations;

typedef struct kstatfs kstatfs, *Pkstatfs;

typedef struct shrink_control shrink_control, *Pshrink_control;

typedef struct dquot_operations dquot_operations, *Pdquot_operations;

typedef struct dquot dquot, *Pdquot;

typedef struct kprojid_t kprojid_t, *Pkprojid_t;

typedef struct quotactl_ops quotactl_ops, *Pquotactl_ops;

typedef struct qc_info qc_info, *Pqc_info;

typedef struct kqid kqid, *Pkqid;

typedef struct qc_dqblk qc_dqblk, *Pqc_dqblk;

typedef struct qc_state qc_state, *Pqc_state;

typedef struct export_operations export_operations, *Pexport_operations;

typedef struct xattr_handler xattr_handler, *Pxattr_handler;

typedef struct hlist_bl_head hlist_bl_head, *Phlist_bl_head;

typedef struct block_device block_device, *Pblock_device;

typedef struct backing_dev_info backing_dev_info, *Pbacking_dev_info;

typedef struct mtd_info mtd_info, *Pmtd_info;

typedef struct quota_info quota_info, *Pquota_info;

typedef struct sb_writers sb_writers, *Psb_writers;

typedef struct shrinker shrinker, *Pshrinker;

typedef struct workqueue_struct workqueue_struct, *Pworkqueue_struct;

typedef struct list_lru list_lru, *Plist_lru;

typedef struct work_struct work_struct, *Pwork_struct;

typedef struct cdev cdev, *Pcdev;

typedef enum module_state {
    MODULE_STATE_LIVE=0,
    MODULE_STATE_COMING=1,
    MODULE_STATE_GOING=2,
    MODULE_STATE_UNFORMED=3
} module_state;

typedef struct module_kobject module_kobject, *Pmodule_kobject;

typedef struct module_attribute module_attribute, *Pmodule_attribute;

typedef struct kernel_symbol kernel_symbol, *Pkernel_symbol;

typedef struct kernel_param kernel_param, *Pkernel_param;

typedef struct exception_table_entry exception_table_entry, *Pexception_table_entry;

typedef struct mod_arch_specific mod_arch_specific, *Pmod_arch_specific;

typedef struct module_sect_attrs module_sect_attrs, *Pmodule_sect_attrs;

typedef struct module_notes_attrs module_notes_attrs, *Pmodule_notes_attrs;

typedef struct upid upid, *Pupid;

typedef struct nfs_lock_info nfs_lock_info, *Pnfs_lock_info;

typedef struct nfs4_lock_info nfs4_lock_info, *Pnfs4_lock_info;

typedef struct anon_struct_12_2_f813cfa2_for_afs anon_struct_12_2_f813cfa2_for_afs, *Panon_struct_12_2_f813cfa2_for_afs;

typedef struct radix_tree_node radix_tree_node, *Pradix_tree_node;

typedef struct raw_spinlock raw_spinlock, *Praw_spinlock;

typedef struct raw_spinlock raw_spinlock_t;

typedef union anon_union_8_2_ae5c065a_for_qstr_0 anon_union_8_2_ae5c065a_for_qstr_0, *Panon_union_8_2_ae5c065a_for_qstr_0;

typedef struct lock_class_key lock_class_key, *Plock_class_key;

typedef struct mem_cgroup mem_cgroup, *Pmem_cgroup;

typedef struct mem_dqblk mem_dqblk, *Pmem_dqblk;

typedef __kernel_uid32_t projid_t;

typedef union anon_union_4_3_d2ff16bc_for_kqid_0 anon_union_4_3_d2ff16bc_for_kqid_0, *Panon_union_4_3_d2ff16bc_for_kqid_0;

typedef enum quota_type {
    USRQUOTA=0,
    GRPQUOTA=1,
    PRJQUOTA=2
} quota_type;

typedef struct qc_type_state qc_type_state, *Pqc_type_state;

typedef struct hd_struct hd_struct, *Phd_struct;

typedef struct gendisk gendisk, *Pgendisk;

typedef struct request_queue request_queue, *Prequest_queue;

typedef struct mem_dqinfo mem_dqinfo, *Pmem_dqinfo;

typedef struct quota_format_ops quota_format_ops, *Pquota_format_ops;

typedef struct percpu_rw_semaphore percpu_rw_semaphore, *Ppercpu_rw_semaphore;

typedef struct list_lru_node list_lru_node, *Plist_lru_node;

typedef void (*work_func_t)(struct work_struct *);

typedef struct module_param_attrs module_param_attrs, *Pmodule_param_attrs;

typedef struct kernel_param_ops kernel_param_ops, *Pkernel_param_ops;

typedef union anon_union_4_3_eb4d9846_for_kernel_param_6 anon_union_4_3_eb4d9846_for_kernel_param_6, *Panon_union_4_3_eb4d9846_for_kernel_param_6;

typedef struct mips_hi16 mips_hi16, *Pmips_hi16;

typedef struct pid_namespace pid_namespace, *Ppid_namespace;

typedef struct nlm_lockowner nlm_lockowner, *Pnlm_lockowner;

typedef struct nfs4_lock_state nfs4_lock_state, *Pnfs4_lock_state;

typedef union anon_union_8_2_0496ad32_for_radix_tree_node_2 anon_union_8_2_0496ad32_for_radix_tree_node_2, *Panon_union_8_2_0496ad32_for_radix_tree_node_2;

typedef struct anon_struct_8_2_62570ece_for_anon_union_8_2_ae5c065a_for_qstr_0_0 anon_struct_8_2_62570ece_for_anon_union_8_2_ae5c065a_for_qstr_0_0, *Panon_struct_8_2_62570ece_for_anon_union_8_2_ae5c065a_for_qstr_0_0;

typedef struct quota_format_type quota_format_type, *Pquota_format_type;

typedef struct rcu_sync rcu_sync, *Prcu_sync;

typedef struct list_lru_one list_lru_one, *Plist_lru_one;

typedef struct kparam_string kparam_string, *Pkparam_string;

typedef struct kparam_array kparam_array, *Pkparam_array;

typedef struct anon_struct_8_2_37b64459_for_anon_union_8_2_0496ad32_for_radix_tree_node_2_0 anon_struct_8_2_37b64459_for_anon_union_8_2_0496ad32_for_radix_tree_node_2_0, *Panon_struct_8_2_37b64459_for_anon_union_8_2_0496ad32_for_radix_tree_node_2_0;

typedef enum rcu_sync_type {
    RCU_SYNC=0,
    RCU_SCHED_SYNC=1,
    RCU_BH_SYNC=2
} rcu_sync_type;

struct rwlock_t {
    struct arch_rwlock_t raw_lock;
};

struct address_space_operations {
    int (*writepage)(struct page *, struct writeback_control *);
    int (*readpage)(struct file *, struct page *);
    int (*writepages)(struct address_space *, struct writeback_control *);
    int (*set_page_dirty)(struct page *);
    int (*readpages)(struct file *, struct address_space *, struct list_head *, uint);
    int (*write_begin)(struct file *, struct address_space *, loff_t, uint, uint, struct page **, void **);
    int (*write_end)(struct file *, struct address_space *, loff_t, uint, uint, struct page *, void *);
    sector_t (*bmap)(struct address_space *, sector_t);
    void (*invalidatepage)(struct page *, uint, uint);
    int (*releasepage)(struct page *, gfp_t);
    void (*freepage)(struct page *);
    ssize_t (*direct_IO)(struct kiocb *, struct iov_iter *, loff_t);
    int (*migratepage)(struct address_space *, struct page *, struct page *, enum migrate_mode);
    int (*launder_page)(struct page *);
    int (*is_partially_uptodate)(struct page *, ulong, ulong);
    void (*is_dirty_writeback)(struct page *, bool *, bool *);
    int (*error_remove_page)(struct address_space *, struct page *);
    int (*swap_activate)(struct swap_info_struct *, struct file *, sector_t *);
    void (*swap_deactivate)(struct file *);
};

struct kparam_string {
    uint maxlen;
    char *string;
};

struct qc_dqblk {
    int d_fieldmask;
    u64 d_spc_hardlimit;
    u64 d_spc_softlimit;
    u64 d_ino_hardlimit;
    u64 d_ino_softlimit;
    u64 d_space;
    u64 d_ino_count;
    s64 d_ino_timer;
    s64 d_spc_timer;
    int d_ino_warns;
    int d_spc_warns;
    u64 d_rt_spc_hardlimit;
    u64 d_rt_spc_softlimit;
    u64 d_rt_space;
    s64 d_rt_spc_timer;
    int d_rt_spc_warns;
};

union anon_union_4_3_eb4d9846_for_kernel_param_6 {
    void *arg;
    struct kparam_string *str;
    struct kparam_array *arr;
};

struct kernel_param {
    char *name;
    struct module *mod;
    struct kernel_param_ops *ops;
    u16 perm;
    s8 level;
    u8 flags;
    union anon_union_4_3_eb4d9846_for_kernel_param_6 field_6;
};

struct kernfs_root {
    struct kernfs_node *kn;
    uint flags;
    struct ida ino_ida;
    struct kernfs_syscall_ops *syscall_ops;
    struct list_head supers;
    wait_queue_head_t deactivate_waitq;
};

struct kernfs_syscall_ops {
    int (*remount_fs)(struct kernfs_root *, int *, char *);
    int (*show_options)(struct seq_file *, struct kernfs_root *);
    int (*mkdir)(struct kernfs_node *, char *, umode_t);
    int (*rmdir)(struct kernfs_node *);
    int (*rename)(struct kernfs_node *, struct kernfs_node *, char *);
};

struct kgid_t {
    gid_t val;
};

struct radix_tree_root {
    uint height;
    gfp_t gfp_mask;
    struct radix_tree_node *rnode;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct raw_spinlock {
    struct arch_spinlock_t raw_lock;
};

struct rw_semaphore {
    __s32 count;
    raw_spinlock_t wait_lock;
    struct list_head wait_list;
};

struct address_space {
    struct inode *host;
    struct radix_tree_root page_tree;
    spinlock_t tree_lock;
    struct atomic_t i_mmap_writable;
    struct rb_root i_mmap;
    struct rw_semaphore i_mmap_rwsem;
    ulong nrpages;
    ulong nrshadows;
    ulong writeback_index;
    struct address_space_operations *a_ops;
    ulong flags;
    spinlock_t private_lock;
    struct list_head private_list;
    void *private_data;
};

union anon_union_4_4_6df45cb4_for_inode_38 {
    struct pipe_inode_info *i_pipe;
    struct block_device *i_bdev;
    struct cdev *i_cdev;
    char *i_link;
};

union anon_union_4_2_26e7ee41_for_inode_11 {
    uint i_nlink;
    uint __i_nlink;
};

union anon_union_8_2_76d55e2d_for_inode_29 {
    struct hlist_head i_dentry;
    struct callback_head i_rcu;
};

struct mutex {
    struct atomic_t count;
    spinlock_t wait_lock;
    struct list_head wait_list;
};

struct timespec {
    __kernel_time_t tv_sec;
    long tv_nsec;
};

struct kuid_t {
    uid_t val;
};

struct inode {
    umode_t i_mode;
    ushort i_opflags;
    struct kuid_t i_uid;
    struct kgid_t i_gid;
    uint i_flags;
    struct posix_acl *i_acl;
    struct posix_acl *i_default_acl;
    struct inode_operations *i_op;
    struct super_block *i_sb;
    struct address_space *i_mapping;
    ulong i_ino;
    union anon_union_4_2_26e7ee41_for_inode_11 field_11;
    dev_t i_rdev;
    loff_t i_size;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    spinlock_t i_lock;
    ushort i_bytes;
    uint i_blkbits;
    blkcnt_t i_blocks;
    ulong i_state;
    struct mutex i_mutex;
    ulong dirtied_when;
    ulong dirtied_time_when;
    struct hlist_node i_hash;
    struct list_head i_io_list;
    struct list_head i_lru;
    struct list_head i_sb_list;
    union anon_union_8_2_76d55e2d_for_inode_29 field_29;
    u64 i_version;
    struct atomic_t i_count;
    struct atomic_t i_dio_count;
    struct atomic_t i_writecount;
    struct file_operations *i_fop;
    struct file_lock_context *i_flctx;
    struct address_space i_data;
    struct list_head i_devices;
    union anon_union_4_4_6df45cb4_for_inode_38 field_38;
    __u32 i_generation;
    void *i_private;
};

struct iov_iter {
};

struct path {
    struct vfsmount *mnt;
    struct dentry *dentry;
};

struct shrink_control {
    gfp_t gfp_mask;
    ulong nr_to_scan;
    int nid;
    struct mem_cgroup *memcg;
};

struct kernel_symbol {
    ulong value;
    char *name;
};

struct module_notes_attrs {
};

struct llist_node {
    struct llist_node *next;
};

struct anon_struct_8_2_62570ece_for_anon_union_8_2_ae5c065a_for_qstr_0_0 {
    u32 hash;
    u32 len;
};

union anon_union_8_2_ae5c065a_for_qstr_0 {
    struct anon_struct_8_2_62570ece_for_anon_union_8_2_ae5c065a_for_qstr_0_0 field_0;
    u64 hash_len;
};

struct qstr {
    union anon_union_8_2_ae5c065a_for_qstr_0 field_0;
    uchar *name;
};

struct anon_struct_12_2_f813cfa2_for_afs {
    struct list_head link;
    int state;
};

struct mem_dqblk {
    qsize_t dqb_bhardlimit;
    qsize_t dqb_bsoftlimit;
    qsize_t dqb_curspace;
    qsize_t dqb_rsvspace;
    qsize_t dqb_ihardlimit;
    qsize_t dqb_isoftlimit;
    qsize_t dqb_curinodes;
    time_t dqb_btime;
    time_t dqb_itime;
};

struct hlist_bl_head {
    struct hlist_bl_node *first;
};

struct exception_table_entry {
    ulong insn;
    ulong nextinsn;
};

struct nfs_lock_info {
    u32 state;
    struct nlm_lockowner *owner;
    struct list_head list;
};

struct dentry_operations {
    int (*d_revalidate)(struct dentry *, uint);
    int (*d_weak_revalidate)(struct dentry *, uint);
    int (*d_hash)(struct dentry *, struct qstr *);
    int (*d_compare)(struct dentry *, struct dentry *, uint, char *, struct qstr *);
    int (*d_delete)(struct dentry *);
    void (*d_release)(struct dentry *);
    void (*d_prune)(struct dentry *);
    void (*d_iput)(struct dentry *, struct inode *);
    char * (*d_dname)(struct dentry *, char *, int);
    vfsmount * (*d_automount)(struct path *);
    int (*d_manage)(struct dentry *, bool);
    inode * (*d_select_inode)(struct dentry *, uint);
    undefined field12_0x30;
    undefined field13_0x31;
    undefined field14_0x32;
    undefined field15_0x33;
    undefined field16_0x34;
    undefined field17_0x35;
    undefined field18_0x36;
    undefined field19_0x37;
    undefined field20_0x38;
    undefined field21_0x39;
    undefined field22_0x3a;
    undefined field23_0x3b;
    undefined field24_0x3c;
    undefined field25_0x3d;
    undefined field26_0x3e;
    undefined field27_0x3f;
};

struct quota_format_ops {
    int (*check_quota_file)(struct super_block *, int);
    int (*read_file_info)(struct super_block *, int);
    int (*write_file_info)(struct super_block *, int);
    int (*free_file_info)(struct super_block *, int);
    int (*read_dqblk)(struct dquot *);
    int (*commit_dqblk)(struct dquot *);
    int (*release_dqblk)(struct dquot *);
};

struct quotactl_ops {
    int (*quota_on)(struct super_block *, int, int, struct path *);
    int (*quota_off)(struct super_block *, int);
    int (*quota_enable)(struct super_block *, uint);
    int (*quota_disable)(struct super_block *, uint);
    int (*quota_sync)(struct super_block *, int);
    int (*set_info)(struct super_block *, int, struct qc_info *);
    int (*get_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (*set_dqblk)(struct super_block *, struct kqid, struct qc_dqblk *);
    int (*get_state)(struct super_block *, struct qc_state *);
    int (*rm_xquota)(struct super_block *, uint);
};

struct kref {
    struct atomic_t refcount;
};

struct kobject {
    char *name;
    struct list_head entry;
    struct kobject *parent;
    struct kset *kset;
    struct kobj_type *ktype;
    struct kernfs_node *sd;
    struct kref kref;
    uint state_initialized:1;
    uint state_in_sysfs:1;
    uint state_add_uevent_sent:1;
    uint state_remove_uevent_sent:1;
    uint uevent_suppress:1;
};

struct kset {
    struct list_head list;
    spinlock_t list_lock;
    struct kobject kobj;
    struct kset_uevent_ops *uevent_ops;
};

struct kstat {
    u64 ino;
    dev_t dev;
    umode_t mode;
    uint nlink;
    struct kuid_t uid;
    struct kgid_t gid;
    dev_t rdev;
    loff_t size;
    struct timespec atime;
    struct timespec mtime;
    struct timespec ctime;
    ulong blksize;
    ulonglong blocks;
};

struct fiemap_extent_info {
    uint fi_flags;
    uint fi_extents_mapped;
    uint fi_extents_max;
    struct fiemap_extent *fi_extents_start;
};

struct mod_arch_specific {
    struct list_head dbe_list;
    struct exception_table_entry *dbe_start;
    struct exception_table_entry *dbe_end;
    struct mips_hi16 *r_mips_hi16_list;
};

struct module_kobject {
    struct kobject kobj;
    struct module *mod;
    struct kobject *drivers_dir;
    struct module_param_attrs *mp;
    struct completion *kobj_completion;
};

struct module {
    enum module_state state;
    struct list_head list;
    char name[60];
    struct module_kobject mkobj;
    struct module_attribute *modinfo_attrs;
    char *version;
    char *srcversion;
    struct kobject *holders_dir;
    struct kernel_symbol *syms;
    ulong *crcs;
    uint num_syms;
    struct mutex param_lock;
    struct kernel_param *kp;
    uint num_kp;
    uint num_gpl_syms;
    struct kernel_symbol *gpl_syms;
    ulong *gpl_crcs;
    bool async_probe_requested;
    undefined field18_0xb9;
    undefined field19_0xba;
    undefined field20_0xbb;
    struct kernel_symbol *gpl_future_syms;
    ulong *gpl_future_crcs;
    uint num_gpl_future_syms;
    uint num_exentries;
    struct exception_table_entry *extable;
    int (*init)(void);
    undefined field27_0xd4;
    undefined field28_0xd5;
    undefined field29_0xd6;
    undefined field30_0xd7;
    undefined field31_0xd8;
    undefined field32_0xd9;
    undefined field33_0xda;
    undefined field34_0xdb;
    undefined field35_0xdc;
    undefined field36_0xdd;
    undefined field37_0xde;
    undefined field38_0xdf;
    void *module_init;
    void *module_core;
    uint init_size;
    uint core_size;
    uint init_text_size;
    uint core_text_size;
    uint init_ro_size;
    uint core_ro_size;
    struct mod_arch_specific arch;
    uint taints;
    Elf32_Sym *symtab;
    Elf32_Sym *core_symtab;
    uint num_symtab;
    uint core_num_syms;
    char *strtab;
    char *core_strtab;
    struct module_sect_attrs *sect_attrs;
    struct module_notes_attrs *notes_attrs;
    char *args;
    struct list_head source_list;
    struct list_head target_list;
    void (*exit)(void);
    struct atomic_t refcnt;
    undefined field62_0x154;
    undefined field63_0x155;
    undefined field64_0x156;
    undefined field65_0x157;
    undefined field66_0x158;
    undefined field67_0x159;
    undefined field68_0x15a;
    undefined field69_0x15b;
    undefined field70_0x15c;
    undefined field71_0x15d;
    undefined field72_0x15e;
    undefined field73_0x15f;
};

struct iattr {
    uint ia_valid;
    umode_t ia_mode;
    struct kuid_t ia_uid;
    struct kgid_t ia_gid;
    loff_t ia_size;
    struct timespec ia_atime;
    struct timespec ia_mtime;
    struct timespec ia_ctime;
    struct file *ia_file;
};

struct kernfs_elem_attr {
    struct kernfs_ops *ops;
    struct kernfs_open_node *open;
    loff_t size;
    struct kernfs_node *notify_next;
};

struct kernfs_elem_symlink {
    struct kernfs_node *target_kn;
};

struct kernfs_elem_dir {
    ulong subdirs;
    struct rb_root children;
    struct kernfs_root *root;
};

union anon_union_24_3_f2422723_for_kernfs_node_7 {
    struct kernfs_elem_dir dir;
    struct kernfs_elem_symlink symlink;
    struct kernfs_elem_attr attr;
};

struct qc_type_state {
    uint flags;
    uint spc_timelimit;
    uint ino_timelimit;
    uint rt_spc_timelimit;
    uint spc_warnlimit;
    uint ino_warnlimit;
    uint rt_spc_warnlimit;
    ulonglong ino;
    blkcnt_t blocks;
    blkcnt_t nextents;
};

struct qc_state {
    uint s_incoredqs;
    struct qc_type_state s_state[3];
};

struct lock_manager_operations {
    int (*lm_compare_owner)(struct file_lock *, struct file_lock *);
    ulong (*lm_owner_key)(struct file_lock *);
    fl_owner_t (*lm_get_owner)(fl_owner_t);
    void (*lm_put_owner)(fl_owner_t);
    void (*lm_notify)(struct file_lock *);
    int (*lm_grant)(struct file_lock *, int);
    bool (*lm_break)(struct file_lock *);
    int (*lm_change)(struct file_lock *, int, struct list_head *);
    void (*lm_setup)(struct file_lock *, void **);
};

struct kprojid_t {
    projid_t val;
};

union anon_union_4_3_d2ff16bc_for_kqid_0 {
    struct kuid_t uid;
    struct kgid_t gid;
    struct kprojid_t projid;
};

struct kqid {
    union anon_union_4_3_d2ff16bc_for_kqid_0 field_0;
    enum quota_type type;
};

struct list_lru_one {
    struct list_head list;
    long nr_items;
};

struct list_lru_node {
    spinlock_t lock;
    struct list_lru_one lru;
};

struct kset_uevent_ops {
    int (*filter)(struct kset *, struct kobject *);
    char * (*name)(struct kset *, struct kobject *);
    int (*uevent)(struct kset *, struct kobject *, struct kobj_uevent_env *);
};

struct posix_acl {
};

struct rcu_sync {
    int gp_state;
    int gp_count;
    wait_queue_head_t gp_wait;
    int cb_state;
    struct callback_head cb_head;
    enum rcu_sync_type gp_type;
};

struct percpu_rw_semaphore {
    struct rcu_sync rss;
    uint *fast_read_ctr;
    struct rw_semaphore rw_sem;
    struct atomic_t slow_read_ctr;
    wait_queue_head_t write_waitq;
};

struct sb_writers {
    int frozen;
    wait_queue_head_t wait_unfrozen;
    struct percpu_rw_semaphore rw_sem[3];
};

struct kparam_array {
    uint max;
    uint elemsize;
    uint *num;
    struct kernel_param_ops *ops;
    void *elem;
};

struct kstatfs {
};

struct shrinker {
    ulong (*count_objects)(struct shrinker *, struct shrink_control *);
    ulong (*scan_objects)(struct shrinker *, struct shrink_control *);
    int seeks;
    long batch;
    ulong flags;
    struct list_head list;
    atomic_long_t *nr_deferred;
};

struct qc_info {
    int i_fieldmask;
    uint i_flags;
    uint i_spc_timelimit;
    uint i_ino_timelimit;
    uint i_rt_spc_timelimit;
    uint i_spc_warnlimit;
    uint i_ino_warnlimit;
    uint i_rt_spc_warnlimit;
};

struct anon_struct_8_2_37b64459_for_anon_union_8_2_0496ad32_for_radix_tree_node_2_0 {
    struct radix_tree_node *parent;
    void *private_data;
};

union anon_union_8_2_70c2e615_for_d_u {
    struct hlist_node d_alias;
    struct callback_head d_rcu;
};

struct file_operations {
    struct module *owner;
    loff_t (*llseek)(struct file *, loff_t, int);
    ssize_t (*read)(struct file *, char *, size_t, loff_t *);
    ssize_t (*write)(struct file *, char *, size_t, loff_t *);
    ssize_t (*read_iter)(struct kiocb *, struct iov_iter *);
    ssize_t (*write_iter)(struct kiocb *, struct iov_iter *);
    int (*iterate)(struct file *, struct dir_context *);
    uint (*poll)(struct file *, struct poll_table_struct *);
    long (*unlocked_ioctl)(struct file *, uint, ulong);
    long (*compat_ioctl)(struct file *, uint, ulong);
    int (*mmap)(struct file *, struct vm_area_struct *);
    int (*open)(struct inode *, struct file *);
    int (*flush)(struct file *, fl_owner_t);
    int (*release)(struct inode *, struct file *);
    int (*fsync)(struct file *, loff_t, loff_t, int);
    int (*aio_fsync)(struct kiocb *, int);
    int (*fasync)(int, struct file *, int);
    int (*lock)(struct file *, int, struct file_lock *);
    ssize_t (*sendpage)(struct file *, struct page *, int, size_t, loff_t *, int);
    ulong (*get_unmapped_area)(struct file *, ulong, ulong, ulong, ulong);
    int (*check_flags)(int);
    int (*flock)(struct file *, int, struct file_lock *);
    ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, uint);
    ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, uint);
    int (*setlease)(struct file *, long, struct file_lock **, void **);
    long (*fallocate)(struct file *, int, loff_t, loff_t);
    void (*show_fdinfo)(struct seq_file *, struct file *);
};

struct file_ra_state {
    ulong start;
    uint size;
    uint async_size;
    uint ra_pages;
    uint mmap_miss;
    loff_t prev_pos;
};

union anon_union_8_2_834e7c5b_for_f_u {
    struct llist_node fu_llist;
    struct callback_head fu_rcuhead;
};

struct fown_struct {
    struct rwlock_t lock;
    struct pid *pid;
    enum pid_type pid_type;
    struct kuid_t uid;
    struct kuid_t euid;
    int signum;
};

struct file {
    union anon_union_8_2_834e7c5b_for_f_u f_u;
    struct path f_path;
    struct inode *f_inode;
    struct file_operations *f_op;
    spinlock_t f_lock;
    atomic_long_t f_count;
    uint f_flags;
    fmode_t f_mode;
    struct mutex f_pos_lock;
    loff_t f_pos;
    struct fown_struct f_owner;
    struct cred *f_cred;
    struct file_ra_state f_ra;
    u64 f_version;
    void *private_data;
    struct list_head f_ep_links;
    struct list_head f_tfile_llink;
    struct address_space *f_mapping;
};

struct mtd_info {
};

struct nfs4_lock_info {
    struct nfs4_lock_state *owner;
};

union anon_union_16_3_6ffd4daa_for_fl_u {
    struct nfs_lock_info nfs_fl;
    struct nfs4_lock_info nfs4_fl;
    struct anon_struct_12_2_f813cfa2_for_afs afs;
};

struct lock_class_key {
};

struct attribute {
    char *name;
    umode_t mode;
};

struct kobj_type {
    void (*release)(struct kobject *);
    struct sysfs_ops *sysfs_ops;
    struct attribute **default_attrs;
    kobj_ns_type_operations * (*child_ns_type)(struct kobject *);
    void * (*namespace)(struct kobject *);
};

struct cred {
};

struct dquot_operations {
    int (*write_dquot)(struct dquot *);
    dquot * (*alloc_dquot)(struct super_block *, int);
    void (*destroy_dquot)(struct dquot *);
    int (*acquire_dquot)(struct dquot *);
    int (*release_dquot)(struct dquot *);
    int (*mark_dirty)(struct dquot *);
    int (*write_info)(struct super_block *, int);
    qsize_t * (*get_reserved_space)(struct inode *);
    int (*get_projid)(struct inode *, struct kprojid_t *);
};

struct kobj_ns_type_operations {
    enum kobj_ns_type type;
    bool (*current_may_mount)(void);
    void * (*grab_current_ns)(void);
    void * (*netlink_ns)(struct sock *);
    void * (*initial_ns)(void);
    void (*drop_ns)(void *);
};

struct sysfs_ops {
    ssize_t (*show)(struct kobject *, struct attribute *, char *);
    ssize_t (*store)(struct kobject *, struct attribute *, char *, size_t);
};

struct seq_file {
};

struct seqcount {
    uint sequence;
};

struct mips_hi16 {
};

struct inode_operations {
    dentry * (*lookup)(struct inode *, struct dentry *, uint);
    char * (*follow_link)(struct dentry *, void **);
    int (*permission)(struct inode *, int);
    posix_acl * (*get_acl)(struct inode *, int);
    int (*readlink)(struct dentry *, char *, int);
    void (*put_link)(struct inode *, void *);
    int (*create)(struct inode *, struct dentry *, umode_t, bool);
    int (*link)(struct dentry *, struct inode *, struct dentry *);
    int (*unlink)(struct inode *, struct dentry *);
    int (*symlink)(struct inode *, struct dentry *, char *);
    int (*mkdir)(struct inode *, struct dentry *, umode_t);
    int (*rmdir)(struct inode *, struct dentry *);
    int (*mknod)(struct inode *, struct dentry *, umode_t, dev_t);
    int (*rename)(struct inode *, struct dentry *, struct inode *, struct dentry *);
    int (*rename2)(struct inode *, struct dentry *, struct inode *, struct dentry *, uint);
    int (*setattr)(struct dentry *, struct iattr *);
    int (*getattr)(struct vfsmount *, struct dentry *, struct kstat *);
    int (*setxattr)(struct dentry *, char *, void *, size_t, int);
    ssize_t (*getxattr)(struct dentry *, char *, void *, size_t);
    ssize_t (*listxattr)(struct dentry *, char *, size_t);
    int (*removexattr)(struct dentry *, char *);
    int (*fiemap)(struct inode *, struct fiemap_extent_info *, u64, u64);
    int (*update_time)(struct inode *, struct timespec *, int);
    int (*atomic_open)(struct inode *, struct dentry *, struct file *, uint, umode_t, int *);
    int (*tmpfile)(struct inode *, struct dentry *, umode_t);
    int (*set_acl)(struct inode *, struct posix_acl *, int);
    undefined field26_0x68;
    undefined field27_0x69;
    undefined field28_0x6a;
    undefined field29_0x6b;
    undefined field30_0x6c;
    undefined field31_0x6d;
    undefined field32_0x6e;
    undefined field33_0x6f;
    undefined field34_0x70;
    undefined field35_0x71;
    undefined field36_0x72;
    undefined field37_0x73;
    undefined field38_0x74;
    undefined field39_0x75;
    undefined field40_0x76;
    undefined field41_0x77;
    undefined field42_0x78;
    undefined field43_0x79;
    undefined field44_0x7a;
    undefined field45_0x7b;
    undefined field46_0x7c;
    undefined field47_0x7d;
    undefined field48_0x7e;
    undefined field49_0x7f;
};

struct rb_node {
    ulong __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct kernfs_node {
    struct atomic_t count;
    struct atomic_t active;
    struct kernfs_node *parent;
    char *name;
    struct rb_node rb;
    void *ns;
    uint hash;
    union anon_union_24_3_f2422723_for_kernfs_node_7 field_7;
    void *priv;
    ushort flags;
    umode_t mode;
    uint ino;
    struct kernfs_iattrs *iattr;
};

struct file_lock_operations {
    void (*fl_copy_lock)(struct file_lock *, struct file_lock *);
    void (*fl_release_private)(struct file_lock *);
};

struct writeback_control {
};

struct hd_struct {
};

struct module_attribute {
    struct attribute attr;
    ssize_t (*show)(struct module_attribute *, struct module_kobject *, char *);
    ssize_t (*store)(struct module_attribute *, struct module_kobject *, char *, size_t);
    void (*setup)(struct module *, char *);
    int (*test)(struct module *);
    void (*free)(struct module *);
};

struct fiemap_extent {
    __u64 fe_logical;
    __u64 fe_physical;
    __u64 fe_length;
    __u64 fe_reserved64[2];
    __u32 fe_flags;
    __u32 fe_reserved[3];
};

union anon_union_8_2_0496ad32_for_radix_tree_node_2 {
    struct anon_struct_8_2_37b64459_for_anon_union_8_2_0496ad32_for_radix_tree_node_2_0 field_0;
    struct callback_head callback_head;
};

struct poll_table_struct {
};

struct kernfs_open_node {
};

struct xattr_handler {
};

struct mem_dqinfo {
    struct quota_format_type *dqi_format;
    int dqi_fmt_id;
    struct list_head dqi_dirty_list;
    ulong dqi_flags;
    uint dqi_bgrace;
    uint dqi_igrace;
    qsize_t dqi_max_spc_limit;
    qsize_t dqi_max_ino_limit;
    void *dqi_priv;
};

struct quota_info {
    uint flags;
    struct mutex dqio_mutex;
    struct mutex dqonoff_mutex;
    struct inode *files[3];
    struct mem_dqinfo info[3];
    struct quota_format_ops *ops[3];
};

struct work_struct {
    atomic_long_t data;
    struct list_head entry;
    work_func_t func;
};

struct list_lru {
    struct list_lru_node *node;
};

struct super_block {
    struct list_head s_list;
    dev_t s_dev;
    uchar s_blocksize_bits;
    ulong s_blocksize;
    loff_t s_maxbytes;
    struct file_system_type *s_type;
    struct super_operations *s_op;
    struct dquot_operations *dq_op;
    struct quotactl_ops *s_qcop;
    struct export_operations *s_export_op;
    ulong s_flags;
    ulong s_iflags;
    ulong s_magic;
    struct dentry *s_root;
    struct rw_semaphore s_umount;
    int s_count;
    struct atomic_t s_active;
    struct xattr_handler **s_xattr;
    struct hlist_bl_head s_anon;
    struct list_head s_mounts;
    struct block_device *s_bdev;
    struct backing_dev_info *s_bdi;
    struct mtd_info *s_mtd;
    struct hlist_node s_instances;
    uint s_quota_types;
    struct quota_info s_dquot;
    struct sb_writers s_writers;
    char s_id[32];
    u8 s_uuid[16];
    void *s_fs_info;
    uint s_max_links;
    fmode_t s_mode;
    u32 s_time_gran;
    struct mutex s_vfs_rename_mutex;
    char *s_subtype;
    char *s_options;
    struct dentry_operations *s_d_op;
    int cleancache_poolid;
    struct shrinker s_shrink;
    atomic_long_t s_remove_count;
    int s_readonly_remount;
    struct workqueue_struct *s_dio_done_wq;
    struct hlist_head s_pins;
    struct list_lru s_dentry_lru;
    struct list_lru s_inode_lru;
    struct callback_head rcu;
    struct work_struct destroy_work;
    struct mutex s_sync_lock;
    int s_stack_depth;
    spinlock_t s_inode_list_lock;
    struct list_head s_inodes;
};

struct file_lock {
    struct file_lock *fl_next;
    struct list_head fl_list;
    struct hlist_node fl_link;
    struct list_head fl_block;
    fl_owner_t fl_owner;
    uint fl_flags;
    uchar fl_type;
    uint fl_pid;
    int fl_link_cpu;
    struct pid *fl_nspid;
    wait_queue_head_t fl_wait;
    struct file *fl_file;
    loff_t fl_start;
    loff_t fl_end;
    struct fasync_struct *fl_fasync;
    ulong fl_break_time;
    ulong fl_downgrade_time;
    struct file_lock_operations *fl_ops;
    struct lock_manager_operations *fl_lmops;
    union anon_union_16_3_6ffd4daa_for_fl_u fl_u;
};

struct module_param_attrs {
};

struct upid {
    int nr;
    struct pid_namespace *ns;
    struct hlist_node pid_chain;
};

struct pid {
    struct atomic_t count;
    uint level;
    struct hlist_head tasks[3];
    struct callback_head rcu;
    struct upid numbers[1];
};

struct kobj_uevent_env {
    char *argv[3];
    char *envp[32];
    int envp_idx;
    char buf[2048];
    int buflen;
};

struct block_device {
    dev_t bd_dev;
    int bd_openers;
    struct inode *bd_inode;
    struct super_block *bd_super;
    struct mutex bd_mutex;
    struct list_head bd_inodes;
    void *bd_claiming;
    void *bd_holder;
    int bd_holders;
    bool bd_write_holder;
    struct list_head bd_holder_disks;
    struct block_device *bd_contains;
    uint bd_block_size;
    struct hd_struct *bd_part;
    uint bd_part_count;
    int bd_invalidated;
    struct gendisk *bd_disk;
    struct request_queue *bd_queue;
    struct list_head bd_list;
    ulong bd_private;
    int bd_fsfreeze_count;
    struct mutex bd_fsfreeze_mutex;
};

struct swap_info_struct {
};

struct workqueue_struct {
};

struct backing_dev_info {
};

struct request_queue {
};

struct kernel_param_ops {
    uint flags;
    int (*set)(char *, struct kernel_param *);
    int (*get)(char *, struct kernel_param *);
    void (*free)(void *);
};

struct kernfs_ops {
    int (*seq_show)(struct seq_file *, void *);
    void * (*seq_start)(struct seq_file *, loff_t *);
    void * (*seq_next)(struct seq_file *, void *, loff_t *);
    void (*seq_stop)(struct seq_file *, void *);
    ssize_t (*read)(struct kernfs_open_file *, char *, size_t, loff_t);
    size_t atomic_write_len;
    bool prealloc;
    ssize_t (*write)(struct kernfs_open_file *, char *, size_t, loff_t);
    int (*mmap)(struct kernfs_open_file *, struct vm_area_struct *);
};

struct pipe_inode_info {
};

struct radix_tree_node {
    uint path;
    uint count;
    union anon_union_8_2_0496ad32_for_radix_tree_node_2 field_2;
    struct list_head private_list;
    void *slots[64];
    ulong tags[3][2];
};

struct nfs4_lock_state {
};

struct vm_operations_struct {
};

struct module_sect_attrs {
};

struct page {
};

struct vfsmount {
};

struct mem_cgroup {
};

struct dir_context {
    filldir_t actor;
    loff_t pos;
};

struct file_system_type {
    char *name;
    int fs_flags;
    dentry * (*mount)(struct file_system_type *, int, char *, void *);
    void (*kill_sb)(struct super_block *);
    struct module *owner;
    struct file_system_type *next;
    struct hlist_head fs_supers;
    struct lock_class_key i_mutex_dir_key;
    struct lock_class_key i_mutex_key;
    struct lock_class_key i_lock_key;
    struct lock_class_key s_writers_key[0];
    struct lock_class_key s_vfs_rename_key;
    struct lock_class_key s_umount_key;
    struct lock_class_key s_lock_key;
};

struct nlm_lockowner {
};

struct pid_namespace {
};

struct export_operations {
};

struct gendisk {
};

struct vm_area_struct {
};

struct dquot {
    struct hlist_node dq_hash;
    struct list_head dq_inuse;
    struct list_head dq_free;
    struct list_head dq_dirty;
    struct mutex dq_lock;
    struct atomic_t dq_count;
    wait_queue_head_t dq_wait_unused;
    struct super_block *dq_sb;
    struct kqid dq_id;
    loff_t dq_off;
    ulong dq_flags;
    struct mem_dqblk dq_dqb;
};

struct kernfs_iattrs {
};

struct kiocb {
    struct file *ki_filp;
    loff_t ki_pos;
    void (*ki_complete)(struct kiocb *, long, long);
    void *private;
    int ki_flags;
};

struct fasync_struct {
    spinlock_t fa_lock;
    int magic;
    int fa_fd;
    struct fasync_struct *fa_next;
    struct file *fa_file;
    struct callback_head fa_rcu;
};

struct file_lock_context {
    spinlock_t flc_lock;
    struct list_head flc_flock;
    struct list_head flc_posix;
    struct list_head flc_lease;
};

struct hlist_bl_node {
    struct hlist_bl_node *next;
    struct hlist_bl_node **pprev;
};

struct dentry {
    uint d_flags;
    seqcount_t d_seq;
    struct hlist_bl_node d_hash;
    struct dentry *d_parent;
    struct qstr d_name;
    struct inode *d_inode;
    uchar d_iname[40];
    struct lockref d_lockref;
    struct dentry_operations *d_op;
    struct super_block *d_sb;
    ulong d_time;
    void *d_fsdata;
    struct list_head d_lru;
    struct list_head d_child;
    struct list_head d_subdirs;
    union anon_union_8_2_70c2e615_for_d_u d_u;
};

struct sock {
};

struct super_operations {
    inode * (*alloc_inode)(struct super_block *);
    void (*destroy_inode)(struct inode *);
    void (*dirty_inode)(struct inode *, int);
    int (*write_inode)(struct inode *, struct writeback_control *);
    int (*drop_inode)(struct inode *);
    void (*evict_inode)(struct inode *);
    void (*put_super)(struct super_block *);
    int (*sync_fs)(struct super_block *, int);
    int (*freeze_super)(struct super_block *);
    int (*freeze_fs)(struct super_block *);
    int (*thaw_super)(struct super_block *);
    int (*unfreeze_fs)(struct super_block *);
    int (*statfs)(struct dentry *, struct kstatfs *);
    int (*remount_fs)(struct super_block *, int *, char *);
    void (*umount_begin)(struct super_block *);
    int (*show_options)(struct seq_file *, struct dentry *);
    int (*show_devname)(struct seq_file *, struct dentry *);
    int (*show_path)(struct seq_file *, struct dentry *);
    int (*show_stats)(struct seq_file *, struct dentry *);
    int (*bdev_try_to_free_page)(struct super_block *, struct page *, gfp_t);
    long (*nr_cached_objects)(struct super_block *, struct shrink_control *);
    long (*free_cached_objects)(struct super_block *, struct shrink_control *);
};

struct quota_format_type {
    int qf_fmt_id;
    struct quota_format_ops *qf_ops;
    struct module *qf_owner;
    struct quota_format_type *qf_next;
};

struct kernfs_open_file {
    struct kernfs_node *kn;
    struct file *file;
    void *priv;
    struct mutex mutex;
    int event;
    struct list_head list;
    char *prealloc_buf;
    size_t atomic_write_len;
    bool mmapped;
    struct vm_operations_struct *vm_ops;
};

struct cdev {
};

typedef enum zone_watermarks {
    WMARK_MIN=0,
    WMARK_LOW=1,
    WMARK_HIGH=2,
    NR_WMARK=3
} zone_watermarks;

typedef enum lru_list {
    LRU_INACTIVE_ANON=0,
    LRU_ACTIVE_ANON=1,
    LRU_INACTIVE_FILE=2,
    LRU_ACTIVE_FILE=3,
    LRU_UNEVICTABLE=4,
    NR_LRU_LISTS=5
} lru_list;

typedef enum anon_enum_32 {
    DQF_ROOT_SQUASH_B=0,
    DQST_LOOKUPS=0,
    MIGRATE_UNMOVABLE=0,
    SB_UNFROZEN=0,
    DQST_DROPS=1,
    MIGRATE_MOVABLE=1,
    SB_FREEZE_WRITE=1,
    DQST_READS=2,
    MIGRATE_RECLAIMABLE=2,
    SB_FREEZE_PAGEFAULT=2,
    DQST_WRITES=3,
    MIGRATE_HIGHATOMIC=3,
    MIGRATE_PCPTYPES=3,
    SB_FREEZE_FS=3,
    DQST_CACHE_HITS=4,
    MIGRATE_TYPES=4,
    SB_FREEZE_COMPLETE=4,
    DQST_ALLOC_DQUOTS=5,
    DQST_FREE_DQUOTS=6,
    DQST_SYNCS=7,
    _DQST_DQSTAT_LAST=8,
    DQF_SYS_FILE_B=16,
    DQF_PRIVATE=17
} anon_enum_32;

typedef enum zone_stat_item {
    NR_FREE_PAGES=0,
    NR_ALLOC_BATCH=1,
    NR_INACTIVE_ANON=2,
    NR_LRU_BASE=2,
    NR_ACTIVE_ANON=3,
    NR_INACTIVE_FILE=4,
    NR_ACTIVE_FILE=5,
    NR_UNEVICTABLE=6,
    NR_MLOCK=7,
    NR_ANON_PAGES=8,
    NR_FILE_MAPPED=9,
    NR_FILE_PAGES=10,
    NR_FILE_DIRTY=11,
    NR_WRITEBACK=12,
    NR_SLAB_RECLAIMABLE=13,
    NR_SLAB_UNRECLAIMABLE=14,
    NR_PAGETABLE=15,
    NR_KERNEL_STACK=16,
    NR_UNSTABLE_NFS=17,
    NR_BOUNCE=18,
    NR_VMSCAN_WRITE=19,
    NR_VMSCAN_IMMEDIATE=20,
    NR_WRITEBACK_TEMP=21,
    NR_ISOLATED_ANON=22,
    NR_ISOLATED_FILE=23,
    NR_SHMEM=24,
    NR_DIRTIED=25,
    NR_WRITTEN=26,
    NR_PAGES_SCANNED=27,
    WORKINGSET_REFAULT=28,
    WORKINGSET_ACTIVATE=29,
    WORKINGSET_NODERECLAIM=30,
    NR_ANON_TRANSPARENT_HUGEPAGES=31,
    NR_FREE_CMA_PAGES=32,
    NR_VM_ZONE_STAT_ITEMS=33
} zone_stat_item;

typedef enum pcpu_fc {
    PCPU_FC_AUTO=0,
    PCPU_FC_EMBED=1,
    PCPU_FC_PAGE=2,
    PCPU_FC_NR=3
} pcpu_fc;

typedef struct of_device_id of_device_id, *Pof_device_id;

struct of_device_id {
    char name[32];
    char type[32];
    char compatible[128];
    void *data;
};

typedef struct task_struct task_struct, *Ptask_struct;

struct task_struct {
};

typedef struct pt_regs pt_regs, *Ppt_regs;

struct pt_regs {
};

typedef struct thread_info thread_info, *Pthread_info;

struct thread_info {
    struct task_struct *task;
    ulong flags;
    ulong tp_value;
    __u32 cpu;
    int preempt_count;
    int r2_emul_return;
    struct mm_segment_t addr_limit;
    struct pt_regs *regs;
    long syscall;
};

typedef enum node_states {
    N_POSSIBLE=0,
    N_ONLINE=1,
    N_NORMAL_MEMORY=2,
    N_HIGH_MEMORY=3,
    N_MEMORY=3,
    N_CPU=4,
    NR_NODE_STATES=5
} node_states;

typedef struct Elf32_RegInfo_MIPS Elf32_RegInfo_MIPS, *PElf32_RegInfo_MIPS;

struct Elf32_RegInfo_MIPS {
    enum Elf32_GPRMask_MIPS ri_gprmask;
    dword field1_0x4[4];
    dword ri_gp_value;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef enum Elf_SectionHeaderType_MIPS {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_MIPS_LIBLIST=1879048192,
    SHT_MIPS_MSYM=1879048193,
    SHT_MIPS_CONFLICT=1879048194,
    SHT_MIPS_GPTAB=1879048195,
    SHT_MIPS_UCODE=1879048196,
    SHT_MIPS_DEBUG=1879048197,
    SHT_MIPS_REGINFO=1879048198,
    SHT_MIPS_PACKAGE=1879048199,
    SHT_MIPS_PACKSYM=1879048200,
    SHT_MIPS_RELD=1879048201,
    =1879048203,
    SHT_MIPS_CONTENT=1879048204,
    SHT_MIPS_OPTIONS=1879048205,
    SHT_MIPS_SHDR=1879048208,
    SHT_MIPS_FDESC=1879048209,
    SHT_MIPS_EXTSYM=1879048210,
    SHT_MIPS_DENSE=1879048211,
    SHT_MIPS_PDESC=1879048212,
    SHT_MIPS_LOCSYM=1879048213,
    SHT_MIPS_AUXSYM=1879048214,
    SHT_MIPS_OPTSYM=1879048215,
    SHT_MIPS_LOCSTR=1879048216,
    SHT_MIPS_LINE=1879048217,
    SHT_MIPS_RFDESC=1879048218,
    SHT_MIPS_DELTASYM=1879048219,
    SHT_MIPS_DELTAINST=1879048220,
    SHT_MIPS_DELTACLASS=1879048221,
    SHT_MIPS_DWARF=1879048222,
    SHT_MIPS_DELTADECL=1879048223,
    SHT_MIPS_SYMBOL_LIB=1879048224,
    SHT_MIPS_EVENTS=1879048225,
    SHT_MIPS_TRANSLATE=1879048226,
    SHT_MIPS_PIXIE=1879048227,
    SHT_MIPS_XLATE=1879048228,
    SHT_MIPS_XLATE_DEBUG=1879048229,
    SHT_MIPS_WHIRL=1879048230,
    SHT_MIPS_EH_REGION=1879048231,
    SHT_MIPS_XLATE_OLD=1879048232,
    SHT_MIPS_PDR_EXCEPTION=1879048233,
    SHT_MIPS_ABIFLAGS=1879048234
} Elf_SectionHeaderType_MIPS;


// WARNING! conflicting data type names: /ELF/Elf32_Sym - /DWARF/elf.h/Elf32_Sym

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_MIPS sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};




void tx_isp_release_device(void)

{
  return;
}



int ** pop_buffer_fifo(int **param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  int *piVar3;
  
  ppiVar1 = (int **)*param_1;
  if (ppiVar1 != param_1) {
    ppiVar2 = (int **)ppiVar1[1];
    piVar3 = *ppiVar1;
    piVar3[1] = (int)ppiVar2;
    *ppiVar2 = piVar3;
    *ppiVar1 = (int *)0x100;
    ppiVar1[1] = (int *)0x200;
    return ppiVar1;
  }
  return (int **)0x0;
}



undefined4 tx_isp_vic_start(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x114) + 0x14);
  if (iVar2 == 1) {
    if (*(int *)(*(int *)(param_1 + 0x114) + 0x18) == 1) {
      isp_printf();
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x10) = 0x20000;
      iVar2 = *(int *)(param_1 + 0xbc);
      puVar6 = (undefined *)0x100010;
    }
    else {
      isp_printf();
      iVar2 = *(int *)(param_1 + 0xbc);
      puVar6 = &DAT_000a000a;
    }
    *(undefined **)(iVar2 + 0x1a4) = puVar6;
    iVar7 = *(int *)(*(int *)(param_1 + 0x114) + 0x7c);
    iVar2 = 8;
    if (iVar7 != 0) {
      if (iVar7 == 1) {
        iVar2 = 10;
      }
      else {
        iVar2 = 0xc;
        if (iVar7 != 2) {
          iVar2 = 0;
        }
      }
    }
    uVar3 = iVar2 * *(int *)(*(int *)(param_1 + 0x114) + 0x2c);
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x100) = (uVar3 >> 5) + (uint)((uVar3 & 0x1f) != 0);
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 2;
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x14) =
         *(undefined4 *)(*(int *)(param_1 + 0x114) + 0x7c);
    *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
         *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
    iVar2 = *(int *)(param_1 + 0x114);
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x10c) =
         *(int *)(iVar2 + 0x40) << 0x19 | *(int *)(iVar2 + 0x44) << 0x18 | *(uint *)(iVar2 + 0x78) |
         *(int *)(iVar2 + 0x48) << 0x17 | *(int *)(iVar2 + 0x5c) << 0x16 |
         *(int *)(iVar2 + 0x60) << 0x14 | *(int *)(iVar2 + 100) << 0x12 |
         *(int *)(iVar2 + 0x68) << 0xc | *(int *)(iVar2 + 0x6c) << 8 | *(int *)(iVar2 + 0x74) << 4 |
         *(int *)(iVar2 + 0x70) << 2;
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x110) =
         (uint)*(ushort *)(*(int *)(param_1 + 0x114) + 0x4c) |
         *(int *)(*(int *)(param_1 + 0x114) + 0x2c) << 0x10;
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x114) =
         (uint)*(ushort *)(*(int *)(param_1 + 0x114) + 0x50);
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x118) =
         (uint)*(ushort *)(*(int *)(param_1 + 0x114) + 0x54);
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x11c) =
         (uint)*(ushort *)(*(int *)(param_1 + 0x114) + 0x58);
    iVar2 = *(int *)(*(int *)(param_1 + 0x114) + 0x74);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0xbc);
      uVar4 = 0x4440;
LAB_00010284:
      *(undefined4 *)(iVar2 + 0x1ac) = uVar4;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a8) = uVar4;
      iVar2 = *(int *)(param_1 + 0xbc);
    }
    else {
      if (iVar2 == 1) {
        iVar2 = *(int *)(param_1 + 0xbc);
        uVar4 = 0x4140;
        goto LAB_00010284;
      }
      if (iVar2 == 2) {
        iVar2 = *(int *)(param_1 + 0xbc);
        uVar4 = 0x4240;
        goto LAB_00010284;
      }
      isp_printf();
      iVar2 = *(int *)(param_1 + 0xbc);
    }
    *(undefined4 *)(iVar2 + 0x1b0) = 0x10;
    **(undefined4 **)(param_1 + 0xbc) = 2;
    **(undefined4 **)(param_1 + 0xbc) = 4;
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x1a0) =
         *(int *)(*(int *)(param_1 + 0x114) + 0x74) << 4 |
         *(uint *)(*(int *)(param_1 + 0x114) + 0x78);
    do {
    } while (**(int **)(param_1 + 0xbc) != 0);
    (*(int **)(param_1 + 0xbc))[0x41] =
         CONCAT22(*(undefined2 *)(*(int *)(param_1 + 0x114) + 0x52),
                  *(undefined2 *)(*(int *)(param_1 + 0x114) + 0x4e));
    *(uint *)(*(int *)(param_1 + 0xbc) + 0x108) =
         CONCAT22(*(undefined2 *)(*(int *)(param_1 + 0x114) + 0x5a),
                  *(undefined2 *)(*(int *)(param_1 + 0x114) + 0x56));
    puVar5 = *(undefined4 **)(param_1 + 0xbc);
LAB_00010628:
    *puVar5 = 1;
  }
  else {
    if (iVar2 != 5) {
      if (iVar2 == 4) {
        isp_printf();
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 0;
        if (*(int *)(*(int *)(param_1 + 0x114) + 0x18) != 0) goto LAB_000103e0;
        *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
             *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 0;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x10) = 0x800c0000;
        *(int *)(*(int *)(param_1 + 0xbc) + 0x18) = *(int *)(param_1 + 0xe0) << 1;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a4) = 0x100010;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1ac) = 0x4440;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1d0) = 0x200;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1d4) = 0x200;
        puVar5 = *(undefined4 **)(param_1 + 0xbc);
        goto LAB_000104a4;
      }
      if (iVar2 != 3) {
        if (iVar2 != 2) {
          isp_printf();
          return 0xffffffff;
        }
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 3;
        uVar3 = *(uint *)(param_1 + 0xe8);
        if (0x300f < uVar3) {
          if (0x310f < uVar3) {
            if (0x31ff < uVar3) {
              if (uVar3 < 0x3210) {
                iVar2 = *(int *)(param_1 + 0x114);
                goto LAB_0001078c;
              }
              if (uVar3 - 0x3300 < 0x10) {
                iVar2 = *(int *)(param_1 + 0x114);
                goto LAB_0001080c;
              }
            }
            goto LAB_00010824;
          }
          if (uVar3 < 0x3100) {
            if (uVar3 < 0x3013) {
              iVar2 = *(int *)(param_1 + 0x114);
LAB_0001080c:
              uVar8 = 0x50000;
              if (*(int *)(iVar2 + 0x1c) != 2) {
                uVar8 = 0x40000;
              }
              goto LAB_0001086c;
            }
            bVar1 = uVar3 < 0x3015;
LAB_00010718:
            if (!bVar1) goto LAB_00010824;
            iVar2 = *(int *)(param_1 + 0x114);
          }
          else {
            iVar2 = *(int *)(param_1 + 0x114);
          }
          uVar8 = 0;
          if (*(int *)(iVar2 + 0x18) != 3) {
            if (*(int *)(iVar2 + 0x18) != 4) goto LAB_000107f0;
            uVar8 = 0x100000;
          }
          goto LAB_0001086c;
        }
        if (uVar3 < 0x300e) {
          uVar8 = 0xc0000;
          if (uVar3 == 0x2011) goto LAB_0001086c;
          if (0x2011 < uVar3) {
            if (uVar3 == 0x3007) {
              iVar2 = *(int *)(param_1 + 0x114);
            }
            else {
              if (uVar3 < 0x3008) {
                bVar1 = uVar3 - 0x3001 < 2;
                goto LAB_00010718;
              }
              if (uVar3 == 0x3008) {
                iVar2 = *(int *)(param_1 + 0x114);
                goto LAB_0001080c;
              }
              if (uVar3 != 0x300a) goto LAB_00010824;
              iVar2 = *(int *)(param_1 + 0x114);
            }
            goto LAB_0001078c;
          }
          uVar8 = 0x80000;
          if (uVar3 == 0x1008) goto LAB_0001086c;
          if (0x1008 < uVar3) {
            if (uVar3 - 0x2002 < 4) {
              uVar8 = 0xc0000;
              goto LAB_0001086c;
            }
LAB_00010824:
            isp_printf();
            goto LAB_00010804;
          }
          if (uVar3 != 0x1006) goto LAB_00010824;
          uVar8 = 0xa0000;
          uVar4 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0x114);
LAB_0001078c:
          iVar7 = *(int *)(iVar2 + 0x18);
          if (*(int *)(iVar2 + 0x1c) == 2) {
            uVar8 = 0x30000;
            if (iVar7 != 0) {
              if (iVar7 != 1) {
LAB_000107f0:
                isp_printf();
LAB_00010804:
                uVar8 = 0;
                uVar4 = 0xffffffff;
                goto LAB_00010870;
              }
              uVar8 = 0x130000;
            }
          }
          else {
            uVar8 = 0x20000;
            if (iVar7 != 0) {
              if (iVar7 != 1) goto LAB_000107f0;
              uVar8 = 0x120000;
            }
          }
LAB_0001086c:
          uVar4 = 0;
        }
LAB_00010870:
        iVar2 = *(int *)(param_1 + 0x114);
        if (*(char *)(iVar2 + 0x24) == '\x02') {
          uVar8 = uVar8 | 2;
        }
        if (*(char *)(iVar2 + 0x25) == '\x02') {
          uVar8 = uVar8 | 1;
        }
        if (*(ushort *)(iVar2 + 0x22) != 0) {
          *(uint *)(*(int *)(param_1 + 0xbc) + 0x18) =
               (uint)*(ushort *)(iVar2 + 0x22) * 0x10000 + *(int *)(param_1 + 0xe0);
        }
        uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x114) + 0x20);
        if (uVar3 == 0) {
          iVar2 = *(int *)(param_1 + 0x114);
        }
        else {
          *(uint *)(*(int *)(param_1 + 0xbc) + 0x3c) = uVar3;
          iVar2 = *(int *)(param_1 + 0x114);
        }
        *(uint *)(*(int *)(param_1 + 0xbc) + 0x18) =
             (uint)*(ushort *)(iVar2 + 0x22) * 0x10000 + *(int *)(param_1 + 0xe0);
        *(uint *)(*(int *)(param_1 + 0xbc) + 0x10) =
             uVar8 | *(int *)(*(int *)(param_1 + 0x114) + 0x28) << 0x1f;
        *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
             *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
        **(undefined4 **)(param_1 + 0xbc) = 2;
        **(undefined4 **)(param_1 + 0xbc) = 4;
        do {
        } while (**(int **)(param_1 + 0xbc) != 0);
        **(int **)(param_1 + 0xbc) = 1;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a4) = 0x100010;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1ac) = 0x4210;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1b0) = 0x10;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1b4) = 0;
        goto LAB_000109a4;
      }
      isp_printf();
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 1;
      iVar2 = *(int *)(*(int *)(param_1 + 0x114) + 0x18);
      if (iVar2 == 0) {
        *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
             *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
        uVar4 = 0x800c8000;
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 1;
        iVar2 = *(int *)(param_1 + 0xbc);
      }
      else {
        if (iVar2 != 1) goto LAB_000103e0;
        *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
             *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
        *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 1;
        iVar2 = *(int *)(param_1 + 0xbc);
        uVar4 = 0x88060820;
      }
      *(undefined4 *)(iVar2 + 0x10) = uVar4;
      *(uint *)(*(int *)(param_1 + 0xbc) + 0x18) = *(int *)(param_1 + 0xe0) << 1 | 0x100000;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x3c) = 0x30;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1c) = 0x1b8;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x30) = 0x1402d0;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x34) = 0x50014;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x38) = 0x2d00014;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a0) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a4) = 0x100010;
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1ac) = 0x4440;
      **(undefined4 **)(param_1 + 0xbc) = 2;
      isp_printf();
      puVar5 = *(undefined4 **)(param_1 + 0xbc);
      goto LAB_00010628;
    }
    isp_printf();
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0xc) = 4;
    if (*(int *)(*(int *)(param_1 + 0x114) + 0x18) != 0) {
LAB_000103e0:
      isp_printf();
      return 0xffffffff;
    }
    *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
         *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x10) = 0x800c0000;
    *(int *)(*(int *)(param_1 + 0xbc) + 0x18) = *(int *)(param_1 + 0xe0) << 1;
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1a4) = 0x100010;
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x1ac) = 0x4440;
    puVar5 = *(undefined4 **)(param_1 + 0xbc);
LAB_000104a4:
    *puVar5 = 2;
    isp_printf();
    **(undefined4 **)(param_1 + 0xbc) = 1;
  }
  uVar4 = 0;
LAB_000109a4:
  isp_printf();
  vic_start_ok = 1;
  return uVar4;
}



undefined4 vic_sensor_ops_ioctl(uint param_1,uint param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    uVar4 = 0;
    bVar1 = true;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar4 != 0) {
      bVar1 = 0xfffff000 < uVar4;
    }
  }
  if (!bVar1) {
    if (param_2 == 0x200000e) {
      puVar2 = *(undefined4 **)(uVar4 + 0xbc);
      uVar3 = 0x10;
    }
    else {
      if (param_2 < 0x200000f) {
        if (param_2 != 0x200000c) {
          return 0;
        }
LAB_00010aac:
        uVar3 = tx_isp_vic_start(uVar4);
        return uVar3;
      }
      if (param_2 == 0x200000f) goto LAB_00010aac;
      if (param_2 != 0x2000013) {
        return 0;
      }
      uVar3 = 4;
      **(undefined4 **)(uVar4 + 0xbc) = 0;
      puVar2 = *(undefined4 **)(uVar4 + 0xbc);
    }
    *puVar2 = uVar3;
  }
  return 0;
}



undefined4 tx_isp_vic_probe(undefined4 *param_1)

{
  void *__s;
  uint uVar1;
  undefined4 uVar2;
  
  __s = (void *)private_kmalloc();
  if (__s == (void *)0x0) {
    isp_printf();
    uVar2 = 0xffffffff;
  }
  else {
    memset(__s,0,0x220);
    uVar1 = tx_isp_subdev_init(param_1,__s,vic_subdev_ops);
    if (uVar1 == 0) {
      private_platform_set_drvdata();
      *(undefined1 **)((int)__s + 0x38) = isp_vic_frd_fops;
      private_spin_lock_init();
      private_raw_mutex_init();
      private_raw_mutex_init();
      private_init_completion();
      *(undefined4 *)((int)__s + 300) = 1;
      *(void **)((int)__s + 0xd8) = __s;
      test_addr = (int)__s + 0x84;
      uVar2 = 0;
      dump_vsd = __s;
    }
    else {
      isp_printf();
      private_kfree();
      uVar2 = 0xfffffff4;
    }
  }
  return uVar2;
}



undefined4 tx_isp_vic_activate_subdev(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar3 != 0) {
      bVar1 = 0xfffff000 < uVar3;
    }
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else {
    private_mutex_lock();
    if (*(int *)(uVar3 + 300) == 1) {
      *(undefined4 *)(uVar3 + 300) = 2;
    }
    private_mutex_unlock();
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 dump_isp_vic_frd_open(void)

{
  undefined4 uVar1;
  
  PDE_DATA();
  uVar1 = private_single_open_size();
  return uVar1;
}



undefined4 isp_vic_frd_show(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  uVar2 = *(uint *)(param_1 + 0x48);
  if ((uVar2 == 0 || 0xfffff000 < uVar2) || (bVar1 = 0xfffff000 < uVar2, uVar2 == 0)) {
    uVar2 = 0;
    bVar1 = true;
  }
  uVar3 = 0;
  if (bVar1) {
    bVar1 = true;
  }
  else {
    uVar3 = *(uint *)(uVar2 + 0xd8);
    bVar1 = true;
    if (uVar3 != 0) {
      bVar1 = 0xfffff000 < uVar3;
    }
  }
  if (bVar1) {
    isp_printf();
  }
  else {
    piVar5 = &vic_err;
    *(undefined4 *)(uVar3 + 0x168) = 0;
    iVar6 = 0;
    do {
      iVar4 = *piVar5;
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + iVar4;
    } while (piVar5 != (int *)vic_cmd_buf);
    *(int *)(uVar3 + 0x168) = iVar6;
    private_seq_printf();
    private_seq_printf();
  }
  return 0;
}



undefined4 ispvic_frame_channel_clearbuf(uint param_1)

{
  int **ppiVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0 && param_1 < 0xfffff001) {
    iVar4 = *(int *)(param_1 + 0xd8);
  }
  __private_spin_lock_irqsave();
  while (ppiVar1 = *(int ***)(int **)(iVar4 + 0x1f8), ppiVar1 != (int **)(iVar4 + 0x1f8)) {
    piVar2 = ppiVar1[1];
    iVar3 = (int)*ppiVar1;
    *(int **)(iVar3 + 4) = piVar2;
    *piVar2 = iVar3;
    *ppiVar1 = (int *)0x100;
    ppiVar1[1] = (int *)0x200;
  }
  *(undefined4 *)(iVar4 + 0x214) = 0;
  *(undefined4 *)(iVar4 + 0x218) = 0;
  private_spin_unlock_irqrestore();
  return 0;
}



undefined4 ispvic_frame_channel_qbuf(uint param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  int **ppiVar5;
  
  iVar4 = 0;
  if (param_1 != 0 && param_1 < 0xfffff001) {
    iVar4 = *(int *)(param_1 + 0xd8);
  }
  ppiVar5 = (int **)(iVar4 + 0x1f8);
  __private_spin_lock_irqsave();
  puVar1 = *(undefined4 **)(iVar4 + 0x1fc);
  *(undefined4 **)(iVar4 + 0x1fc) = param_2;
  *param_2 = ppiVar5;
  param_2[1] = puVar1;
  *puVar1 = param_2;
  if ((*(int ***)(iVar4 + 0x200) == (int **)(iVar4 + 0x200)) ||
     (*(int ***)(iVar4 + 0x1f8) == ppiVar5)) {
    isp_printf();
  }
  else {
    ppiVar5 = pop_buffer_fifo(ppiVar5);
    ppiVar2 = pop_buffer_fifo((int **)(iVar4 + 0x200));
    piVar3 = ppiVar5[2];
    ppiVar2[2] = piVar3;
    *(int **)(*(int *)(iVar4 + 0xbc) + ((int)ppiVar2[4] + 0xc6) * 4) = piVar3;
    piVar3 = *(int **)(iVar4 + 0x20c);
    *(int ***)(iVar4 + 0x20c) = ppiVar2;
    *ppiVar2 = (int *)(iVar4 + 0x208);
    ppiVar2[1] = piVar3;
    *piVar3 = (int)ppiVar2;
    *(int *)(iVar4 + 0x21c) = *(int *)(iVar4 + 0x21c) + 1;
  }
  private_spin_unlock_irqrestore();
  return 0;
}



undefined4 vic_sensor_ops_sync_sensor_attr(uint param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    uVar4 = 0;
    bVar1 = true;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar4 != 0) {
      bVar1 = 0xfffff000 < uVar4;
    }
  }
  if (bVar1) {
    isp_printf();
    uVar2 = 0xffffffea;
  }
  else {
    if (param_2 == 0) {
      param_2 = 0;
      pcVar3 = memset;
    }
    else {
      pcVar3 = memcpy;
    }
    (*pcVar3)(uVar4 + 0xe0,param_2,0x4c);
    uVar2 = 0;
  }
  return uVar2;
}



void dump_vic_reg(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 4;
    isp_printf();
  } while (iVar1 != 0x1b4);
  return;
}



void check_vic_error(void)

{
  do {
    dump_vic_reg();
  } while( true );
}



void tx_vic_enable_irq(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (dump_vsd != 0 && dump_vsd < 0xfffff001) {
    uVar1 = dump_vsd;
  }
  if (uVar1 != 0 && uVar1 < 0xfffff001) {
    __private_spin_lock_irqsave();
    if (*(int *)(dump_vsd + 0x140) == 0) {
      *(undefined4 *)(dump_vsd + 0x140) = 1;
      if (*(code **)(uVar1 + 0x88) != (code *)0x0) {
        (**(code **)(uVar1 + 0x88))(uVar1 + 0x84);
      }
    }
    private_spin_unlock_irqrestore();
  }
  return;
}



void tx_vic_disable_irq(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (dump_vsd != 0 && dump_vsd < 0xfffff001) {
    uVar1 = dump_vsd;
  }
  if ((uVar1 != 0 && uVar1 < 0xfffff001) && (*(int *)(dump_vsd + 0x140) != 0)) {
    *(undefined4 *)(dump_vsd + 0x140) = 0;
    if (*(code **)(uVar1 + 0x8c) != (code *)0x0) {
      (**(code **)(uVar1 + 0x8c))(uVar1 + 0x84);
    }
  }
  return;
}



undefined4 vic_core_s_stream(uint param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar3 != 0) {
      bVar1 = 0xfffff000 < uVar3;
    }
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else if (param_2 == 0) {
    uVar2 = 0;
    if (*(int *)(uVar3 + 300) == 4) {
      *(undefined4 *)(uVar3 + 300) = 3;
    }
  }
  else if (*(int *)(uVar3 + 300) == 4) {
    uVar2 = 0;
  }
  else {
    tx_vic_disable_irq();
    uVar2 = tx_isp_vic_start(uVar3);
    *(undefined4 *)(uVar3 + 300) = 4;
    tx_vic_enable_irq();
  }
  return uVar2;
}



undefined4 vic_core_ops_init(uint param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    isp_printf();
    uVar4 = 0xffffffea;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xd8);
    iVar1 = *(int *)(iVar3 + 300);
    if (param_2 == 0) {
      uVar5 = 2;
      if (iVar1 == 2) {
        return 0;
      }
      pcVar2 = tx_vic_disable_irq;
    }
    else {
      uVar5 = 3;
      if (iVar1 == 3) {
        return 0;
      }
      pcVar2 = tx_vic_enable_irq;
    }
    uVar4 = 0;
    (*pcVar2)(0x5310000);
    *(undefined4 *)(iVar3 + 300) = uVar5;
  }
  return uVar4;
}



undefined4 tx_isp_vic_slake_subdev(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar4 != 0) {
      bVar1 = 0xfffff000 < uVar4;
    }
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar3 = *(int *)(uVar4 + 300);
    if (iVar3 == 4) {
      vic_core_s_stream(param_1,0);
      iVar3 = *(int *)(uVar4 + 300);
    }
    if (iVar3 == 3) {
      vic_core_ops_init(param_1,0);
    }
    private_mutex_lock();
    if (*(int *)(uVar4 + 300) == 2) {
      *(undefined4 *)(uVar4 + 300) = 1;
    }
    private_mutex_unlock();
    uVar2 = 0;
  }
  return uVar2;
}



void vic_mdma_enable(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  vic_mdma_ch0_set_buff_index = 4;
  iVar2 = *(int *)(param_1 + 0xe0) * 2;
  vic_mdma_ch1_set_buff_index = 4;
  iVar1 = iVar2 * *(int *)(param_1 + 0xe4);
  if (param_3 != 0) {
    vic_mdma_ch1_sub_get_num = param_4;
  }
  vic_mdma_ch0_sub_get_num = param_4;
  *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x308) = 1;
  *(uint *)(*(int *)(param_1 + 0xbc) + 0x304) =
       *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
  *(int *)(*(int *)(param_1 + 0xbc) + 0x310) = iVar2;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x314) = iVar2;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x318) = param_5;
  if (param_3 == 0) {
    *(int *)(*(int *)(param_1 + 0xbc) + 0x31c) = param_5 + iVar1;
    *(int *)(*(int *)(param_1 + 0xbc) + 800) = param_5 + iVar1 * 2;
    *(int *)(*(int *)(param_1 + 0xbc) + 0x324) = iVar1 * 3 + param_5;
    iVar2 = iVar1 * 4;
  }
  else {
    *(int *)(*(int *)(param_1 + 0xbc) + 0x31c) = param_5 + iVar1 * 2;
    *(int *)(*(int *)(param_1 + 0xbc) + 800) = param_5 + iVar1 * 4;
    *(int *)(*(int *)(param_1 + 0xbc) + 0x324) = iVar1 * 6 + param_5;
    iVar2 = iVar1 * 8;
  }
  *(int *)(*(int *)(param_1 + 0xbc) + 0x328) = param_5 + iVar2;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x340) = param_5 + iVar1;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x344) = iVar1 * 3 + param_5;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x348) = iVar1 * 5 + param_5;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x34c) = iVar1 * 7 + param_5;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x350) = iVar1 * 9 + param_5;
  if (7 < param_4) {
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x300) = 0x80080020;
    return;
  }
  *(uint *)(*(int *)(param_1 + 0xbc) + 0x300) = param_4 << 0x10 | 0x80000020;
  return;
}



uint isp_vic_cmd_set(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  char *pcVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  char cVar12;
  undefined *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  int iVar16;
  uint uVar17;
  undefined auStack_90 [64];
  undefined4 local_50;
  uint local_4c;
  undefined *local_48;
  undefined4 local_44;
  code *local_40;
  undefined4 local_3c;
  int local_38;
  code *local_34;
  char *local_30;
  undefined *local_2c;
  
  iVar16 = *(int *)(param_1 + 0x78);
  uVar4 = *(uint *)(iVar16 + 0x48);
  if ((uVar4 == 0 || 0xfffff000 < uVar4) || (bVar3 = 0xfffff000 < uVar4, uVar4 == 0)) {
    uVar4 = 0;
    bVar3 = true;
  }
  uVar14 = 0;
  if (!bVar3) {
    uVar14 = *(uint *)(uVar4 + 0xd8);
  }
  isp_printf();
  if (uVar14 == 0 || 0xfffff000 < uVar14) {
    uVar4 = seq_printf(iVar16,"Can\'t ops the node!\n");
    return uVar4;
  }
  if (param_3 < 0x21) {
    puVar15 = vic_cmd_buf;
  }
  else {
    puVar15 = (undefined1 *)private_kmalloc();
    if (puVar15 == (char *)0x0) {
      return 0xfffffff4;
    }
  }
  iVar16 = private_copy_from_user();
  iVar10 = 7;
  if (iVar16 != 0) {
    uVar4 = 0xfffffff2;
    goto joined_r0x00011f90;
  }
  pcVar9 = "snapraw";
  iVar16 = 7;
  pcVar5 = puVar15;
  while( true ) {
    cVar1 = *pcVar5;
    cVar2 = *pcVar9;
    cVar12 = cVar2;
    if (iVar16 == 0) break;
    iVar16 = iVar16 + -1;
    pcVar5 = pcVar5 + 1;
    cVar12 = cVar1;
    if ((cVar2 != cVar1) || (pcVar9 = pcVar9 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
  }
  if (cVar12 == cVar2) {
    uVar4 = simple_strtoull(puVar15 + 8,0);
    if (uVar4 < 2) {
      uVar4 = 1;
    }
    else if (param_3 == 8) {
      uVar4 = 1;
    }
    iVar16 = *(int *)(uVar14 + 0xe0) * *(int *)(uVar14 + 0xe4) * 2;
    isp_printf();
    if (0xa80 < *(uint *)(uVar14 + 0xe0)) {
LAB_00011c7c:
      private_seq_printf();
      return 0;
    }
    if (*(int *)(uVar14 + 0x144) != 0) {
LAB_00011978:
      private_seq_printf();
      return 0;
    }
    iVar10 = isp_malloc_buffer(uVar4 * iVar16);
    *(int *)(uVar14 + 0x144) = iVar10;
    if (iVar10 != 0) {
      *(int *)(uVar14 + 0x148) = iVar10 + -0x80000000;
      vic_mdma_enable(uVar14,0,(uint)(*(int *)(*(int *)(uVar14 + 0x114) + 0x90) != 0),uVar4,iVar10);
      iVar10 = 600;
      local_40 = (code *)0x20000;
      pcVar6 = private_wait_for_completion_interruptible;
LAB_00011a00:
      iVar7 = (*pcVar6)(uVar14 + 0x14c);
      if (iVar7 < 0) goto LAB_00011a34;
      pcVar6 = (code *)&_LC32;
      pcVar5 = "/tmp/snap%d.%s";
      puVar13 = (undefined *)0xe0000;
      iVar10 = 0;
      for (uVar17 = 0; uVar17 != uVar4; uVar17 = uVar17 + 1) {
        local_38 = iVar10 + iVar16;
        local_34 = pcVar6;
        local_30 = pcVar5;
        local_2c = puVar13;
        (*(code *)(puVar13 + -0x5ff0))(auStack_90,0x40,pcVar5,uVar17,pcVar6);
        private_filp_open();
        private_get_fs(&local_50);
        local_40 = private_set_fs;
        local_3c = local_50;
        private_set_fs();
        private_vfs_write();
        private_filp_close();
        (*local_40)(local_3c);
        pcVar6 = local_34;
        pcVar5 = local_30;
        puVar13 = local_2c;
        iVar10 = local_38;
      }
      iVar16 = *(int *)(uVar14 + 0x144);
      goto LAB_00011f74;
    }
  }
  else {
    pcVar9 = "saveraw";
    pcVar5 = puVar15;
    while( true ) {
      cVar1 = *pcVar5;
      cVar2 = *pcVar9;
      cVar12 = cVar2;
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      pcVar5 = pcVar5 + 1;
      cVar12 = cVar1;
      if ((cVar2 != cVar1) || (pcVar9 = pcVar9 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar12 == cVar2) {
      local_4c = system_reg_read(0x7810);
      local_44 = system_reg_read(0x7814);
      uVar4 = system_reg_read(0x7804);
      iVar16 = system_reg_read(0x7820);
      system_reg_write(0x7810,local_4c & 0x11110111);
      system_reg_write(0x7814,0);
      local_48 = (undefined *)(uVar4 | 1);
      system_reg_write(0x7804,(undefined *)(uVar4 | 1));
      iVar10 = 0xb;
      while (iVar10 = iVar10 + -1, iVar10 != 0) {
        __udelay(1000);
      }
      uVar4 = simple_strtoull(puVar15 + 8,0,0);
      if (uVar4 < 2) {
        uVar4 = 1;
      }
      else if (param_3 == 8) {
        uVar4 = 1;
      }
      iVar10 = *(int *)(uVar14 + 0xe0);
      iVar7 = *(int *)(uVar14 + 0xe4);
      isp_printf();
      if (0xa80 < *(uint *)(uVar14 + 0xe0)) goto LAB_00011c7c;
      if (*(int *)(uVar14 + 0x144) != 0) goto LAB_00011978;
      *(int *)(uVar14 + 0x144) = iVar16;
      if (iVar16 != 0) {
        *(int *)(uVar14 + 0x148) = iVar16 + -0x80000000;
        vic_mdma_enable(uVar14,0,(uint)(*(int *)(*(int *)(uVar14 + 0x114) + 0x90) != 0),uVar4,iVar16
                       );
        iVar16 = 600;
        local_40 = (code *)0x20000;
        pcVar6 = private_wait_for_completion_interruptible;
LAB_00011d38:
        iVar8 = (*pcVar6)(uVar14 + 0x14c);
        if (iVar8 < 0) goto LAB_00011d6c;
        pcVar5 = "/tmp/snap%d.%s";
        puVar13 = &_LC32;
        iVar16 = 0xe0000;
        pcVar9 = (char *)0x0;
        for (uVar17 = 0; uVar17 != uVar4; uVar17 = uVar17 + 1) {
          local_40 = (code *)pcVar5;
          local_38 = iVar16;
          local_30 = pcVar9 + iVar10 * iVar7 * 2;
          local_2c = puVar13;
          (*(code *)(iVar16 + -0x5ff0))(auStack_90,0x40,pcVar5,uVar17,puVar13);
          private_filp_open();
          private_get_fs(&local_50);
          local_3c = local_50;
          local_34 = private_set_fs;
          private_set_fs();
          private_vfs_write();
          private_filp_close();
          (*local_34)(local_3c);
          puVar13 = local_2c;
          pcVar5 = (char *)local_40;
          iVar16 = local_38;
          pcVar9 = local_30;
        }
      }
      pcVar6 = system_reg_write;
      system_reg_write(0x7810,local_4c & 0x11111111);
      system_reg_write(0x7814,local_44);
      uVar11 = 0x7804;
      puVar13 = local_48;
    }
    else {
      pcVar5 = "help";
      iVar16 = 4;
      while( true ) {
        cVar1 = *puVar15;
        cVar2 = *pcVar5;
        cVar12 = cVar2;
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        puVar15 = puVar15 + 1;
        cVar12 = cVar1;
        if ((cVar2 != cVar1) || (pcVar5 = pcVar5 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar12 != cVar2) {
        iVar16 = *(int *)(uVar14 + 0x144);
        goto LAB_00011f74;
      }
      pcVar6 = isp_printf;
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      isp_printf();
      uVar11 = 1;
      puVar13 = &_LC36;
    }
    (*pcVar6)(uVar11,puVar13);
  }
  iVar16 = *(int *)(uVar14 + 0x144);
LAB_00011f74:
  uVar4 = param_3;
  if (iVar16 != 0) {
    isp_free_buffer(iVar16);
    *(undefined4 *)(uVar14 + 0x144) = 0;
  }
joined_r0x00011f90:
  if (0x20 < param_3) {
    private_kfree();
  }
  return uVar4;
LAB_00011d6c:
  iVar16 = iVar16 + -1;
  pcVar6 = local_40 + -0x6cd8;
  if (iVar16 == 0) goto LAB_00011fb8;
  goto LAB_00011d38;
LAB_00011a34:
  iVar10 = iVar10 + -1;
  pcVar6 = local_40 + -0x6cd8;
  if (iVar10 == 0) goto LAB_00011fb8;
  goto LAB_00011a00;
LAB_00011fb8:
  private_seq_printf();
  iVar16 = *(int *)(uVar14 + 0x144);
  goto LAB_00011f74;
}



void vic_pipo_mdma_enable(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xe0);
  *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x308) = 1;
  iVar1 = iVar1 << 1;
  *(uint *)(*(int *)(param_1 + 0xbc) + 0x304) =
       *(int *)(param_1 + 0xe0) << 0x10 | *(uint *)(param_1 + 0xe4);
  *(int *)(*(int *)(param_1 + 0xbc) + 0x310) = iVar1;
  *(int *)(*(int *)(param_1 + 0xbc) + 0x314) = iVar1;
  return;
}



undefined4 ispvic_frame_channel_s_stream(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0 && param_1 < 0xfffff001) {
    iVar2 = *(int *)(param_1 + 0xd8);
  }
  if (param_1 == 0) {
    isp_printf();
    uVar1 = 0xffffffea;
  }
  else {
    isp_printf();
    uVar1 = 0;
    if (param_2 != *(int *)(iVar2 + 0x214)) {
      __private_spin_lock_irqsave();
      if (param_2 == 0) {
        *(undefined4 *)(*(int *)(iVar2 + 0xbc) + 0x300) = 0;
        *(undefined4 *)(iVar2 + 0x214) = 0;
      }
      else {
        vic_pipo_mdma_enable(iVar2);
        *(uint *)(*(int *)(iVar2 + 0xbc) + 0x300) = *(int *)(iVar2 + 0x21c) << 0x10 | 0x80000020;
        *(undefined4 *)(iVar2 + 0x214) = 1;
      }
      private_spin_unlock_irqrestore();
      uVar1 = 0;
    }
  }
  return uVar1;
}



void vic_framedone_irq_function(int param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((*(int *)(param_1 + 0x218) != 0) && (iVar5 = 0, *(int *)(param_1 + 0x214) != 0)) {
    iVar4 = *(int *)(param_1 + 0xbc);
    puVar3 = *(undefined4 **)(param_1 + 0x208);
    iVar6 = 0;
    bVar2 = false;
    while (puVar3 != (undefined4 *)(param_1 + 0x208)) {
      iVar6 = iVar6 + (uint)bVar2;
      piVar1 = puVar3 + 2;
      puVar3 = (undefined4 *)*puVar3;
      iVar5 = iVar5 + 1;
      if (*piVar1 == *(int *)(iVar4 + 0x380)) {
        bVar2 = true;
      }
    }
    if (!bVar2) {
      iVar6 = iVar5;
    }
    *(uint *)(iVar4 + 0x300) = iVar6 << 0x10 | *(uint *)(iVar4 + 0x300) & 0xfff0ffff;
  }
  return;
}



void vic_mdma_irq_function(int param_1,int param_2)

{
  int iVar1;
  int **ppiVar2;
  int *piVar3;
  int **ppiVar4;
  int iVar5;
  int **ppiVar6;
  int *piVar7;
  
  iVar5 = *(int *)(param_1 + 0xe0);
  iVar1 = *(int *)(param_1 + 0xe4);
  if (*(int *)(param_1 + 0x218) == 0) {
    isp_printf();
    iVar1 = iVar5 * iVar1 * 2;
    if (param_2 == 0) {
      if (vic_mdma_ch0_sub_get_num != 0) {
        iVar5 = vic_mdma_ch0_set_buff_index + 0xc6;
        vic_mdma_ch0_set_buff_index = (vic_mdma_ch0_set_buff_index + 1) % 5;
        *(int *)(*(int *)(param_1 + 0xbc) + (vic_mdma_ch0_set_buff_index + 0xc6) * 4) =
             *(int *)(*(int *)(param_1 + 0xbc) + iVar5 * 4) + iVar1;
        vic_mdma_ch0_sub_get_num = vic_mdma_ch0_sub_get_num + -1;
        if (vic_mdma_ch0_sub_get_num == 7) {
          *(uint *)(*(int *)(param_1 + 0xbc) + 0x300) =
               *(uint *)(*(int *)(param_1 + 0xbc) + 0x300) & 0xfff0ffff | 0x70000;
        }
      }
    }
    else if ((param_2 == 1) && (vic_mdma_ch1_sub_get_num != 0)) {
      iVar5 = vic_mdma_ch1_set_buff_index + 0xc6;
      vic_mdma_ch1_set_buff_index = (vic_mdma_ch1_set_buff_index + 1) % 5;
      *(int *)(*(int *)(param_1 + 0xbc) + (vic_mdma_ch1_set_buff_index + 0xc6) * 4) =
           *(int *)(*(int *)(param_1 + 0xbc) + iVar5 * 4) + iVar1;
      vic_mdma_ch1_sub_get_num = vic_mdma_ch1_sub_get_num + -1;
    }
    if (vic_mdma_ch0_sub_get_num != 0) {
      return;
    }
    if (vic_mdma_ch1_sub_get_num != 0) {
      return;
    }
    private_complete();
    return;
  }
  if (*(int *)(param_1 + 0x214) == 0) {
    return;
  }
  ppiVar6 = (int **)(param_1 + 0x208);
  piVar7 = *(int **)(*(int *)(param_1 + 0xbc) + 0x380);
  ppiVar2 = pop_buffer_fifo(ppiVar6);
  iVar1 = raw_pipe;
  if (ppiVar2 == (int **)0x0) {
    isp_printf();
  }
  else {
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + -1;
    (**(code **)(iVar1 + 4))(*(undefined4 *)(iVar1 + 0x14),ppiVar2);
    piVar3 = *(int **)(param_1 + 0x204);
    *(int ***)(param_1 + 0x204) = ppiVar2;
    *ppiVar2 = (int *)(param_1 + 0x200);
    ppiVar2[1] = piVar3;
    *piVar3 = (int)ppiVar2;
    iVar1 = 0;
    if (ppiVar2[2] != piVar7) {
      iVar5 = *(int *)(param_1 + 0x21c);
      do {
        while( true ) {
          if (iVar1 == iVar5) {
            isp_printf();
            isp_printf();
            ppiVar2 = *(int ***)(param_1 + 0x200);
            goto LAB_000123b4;
          }
          ppiVar2 = pop_buffer_fifo(ppiVar6);
          if (ppiVar2 != (int **)0x0) break;
          isp_printf();
          iVar1 = iVar1 + 1;
        }
        *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + -1;
        isp_printf();
        (**(code **)(raw_pipe + 4))(*(undefined4 *)(raw_pipe + 0x14),ppiVar2);
        piVar3 = *(int **)(param_1 + 0x204);
        *(int ***)(param_1 + 0x204) = ppiVar2;
        *ppiVar2 = (int *)(param_1 + 0x200);
        ppiVar2[1] = piVar3;
        *piVar3 = (int)ppiVar2;
        iVar1 = iVar1 + 1;
      } while (ppiVar2[2] != piVar7);
      ppiVar2 = *(int ***)(param_1 + 0x200);
      goto LAB_000123b4;
    }
  }
  ppiVar2 = *(int ***)(param_1 + 0x200);
LAB_000123b4:
  if ((ppiVar2 != (int **)(param_1 + 0x200)) &&
     (*(int ***)(param_1 + 0x1f8) != (int **)(param_1 + 0x1f8))) {
    ppiVar2 = pop_buffer_fifo((int **)(param_1 + 0x1f8));
    ppiVar4 = pop_buffer_fifo((int **)(param_1 + 0x200));
    ppiVar4[2] = ppiVar2[2];
    piVar7 = *(int **)(param_1 + 0x20c);
    *(int ***)(param_1 + 0x20c) = ppiVar4;
    *ppiVar4 = (int *)ppiVar6;
    ppiVar4[1] = piVar7;
    *piVar7 = (int)ppiVar4;
    *(int *)(param_1 + 0x21c) = *(int *)(param_1 + 0x21c) + 1;
    *(int **)(*(int *)(param_1 + 0xbc) + ((int)ppiVar4[4] + 0xc6) * 4) = ppiVar4[2];
  }
  return;
}



undefined4 isp_vic_interrupt_service_routine(uint param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar6 != 0) {
      bVar1 = 0xfffff000 < uVar6;
    }
  }
  if (!bVar1) {
    iVar2 = *(int *)(param_1 + 0xbc);
    uVar4 = ~*(uint *)(iVar2 + 0x1e8) & *(uint *)(iVar2 + 0x1e0);
    uVar5 = ~*(uint *)(iVar2 + 0x1ec) & *(uint *)(iVar2 + 0x1e4);
    *(uint *)(iVar2 + 0x1f0) = uVar4;
    *(uint *)(*(int *)(param_1 + 0xbc) + 500) = uVar5;
    if (vic_start_ok != '\0') {
      if ((uVar4 & 1) != 0) {
        *(int *)(uVar6 + 0x164) = *(int *)(uVar6 + 0x164) + 1;
        vic_framedone_irq_function(uVar6);
      }
      if ((uVar4 & 0x200) != 0) {
        DAT_000b3bcc = DAT_000b3bcc + 1;
        isp_printf();
      }
      if ((uVar4 & 0x400) != 0) {
        vic_err = vic_err + 1;
        isp_printf();
      }
      if ((uVar4 & 0x800) != 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((uVar4 & 0x1000) != 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((uVar4 & 0x2000) != 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((uVar4 & 0x4000) != 0) {
        DAT_000b3ba4 = DAT_000b3ba4 + 1;
        isp_printf();
      }
      if ((uVar4 & 0x8000) != 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 0xf) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 0xe) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 0xd) < 0) {
        DAT_000b3ba8 = DAT_000b3ba8 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 0xc) < 0) {
        DAT_000b3bac = DAT_000b3bac + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 0xb) < 0) {
        DAT_000b3bb0 = DAT_000b3bb0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 10) < 0) {
        DAT_000b3bb4 = DAT_000b3bb4 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 9) < 0) {
        DAT_000b3bb8 = DAT_000b3bb8 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 8) < 0) {
        DAT_000b3bbc = DAT_000b3bbc + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 7) < 0) {
        DAT_000b3bc0 = DAT_000b3bc0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 6) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 5) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 4) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 3) < 0) {
        DAT_000b3bc4 = DAT_000b3bc4 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 2) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)(uVar4 << 1) < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((int)uVar4 < 0) {
        DAT_000b3bd0 = DAT_000b3bd0 + 1;
        isp_printf();
      }
      if ((uVar5 & 1) != 0) {
        vic_mdma_irq_function(uVar6,0);
      }
      if ((uVar5 & 2) != 0) {
        vic_mdma_irq_function(uVar6,1);
      }
      if ((uVar5 & 4) != 0) {
        isp_printf();
      }
      if ((uVar5 & 8) != 0) {
        DAT_000b3bc8 = DAT_000b3bc8 + 1;
        isp_printf();
      }
      if (((uVar4 & 0xde00) != 0) && (vic_start_ok == '\x01')) {
        isp_printf();
        **(undefined4 **)(uVar6 + 0xbc) = 4;
        while (piVar3 = *(int **)(uVar6 + 0xbc), *piVar3 != 0) {
          isp_printf();
        }
        piVar3[0x41] = piVar3[0x41];
        *(undefined4 *)(*(int *)(uVar6 + 0xbc) + 0x108) =
             *(undefined4 *)(*(int *)(uVar6 + 0xbc) + 0x108);
        **(undefined4 **)(uVar6 + 0xbc) = 1;
      }
    }
  }
  return 1;
}



undefined4 tx_isp_subdev_pipo(undefined *param_1,undefined **param_2)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  if (param_1 != (undefined *)0x0 && param_1 < (undefined *)0xfffff001) {
    iVar5 = *(int *)(param_1 + 0xd8);
  }
  *(undefined4 *)(iVar5 + 0x210) = 1;
  raw_pipe = (code **)param_2;
  if (param_2 == (undefined **)0x0) {
    *(undefined4 *)(iVar5 + 0x218) = 0;
  }
  else {
    iVar6 = iVar5 + 0x200;
    *(int *)(iVar5 + 0x208) = iVar5 + 0x208;
    *(int *)(iVar5 + 0x20c) = iVar5 + 0x208;
    *(int *)(iVar5 + 0x1f8) = iVar5 + 0x1f8;
    *(int *)(iVar5 + 0x1fc) = iVar5 + 0x1f8;
    *(int *)(iVar5 + 0x200) = iVar6;
    *(int *)(iVar5 + 0x204) = iVar6;
    private_spin_lock_init();
    *raw_pipe = ispvic_frame_channel_qbuf;
    ppcVar1 = raw_pipe;
    raw_pipe[2] = ispvic_frame_channel_clearbuf;
    ppcVar1[3] = ispvic_frame_channel_s_stream;
    ppcVar1[4] = (code *)param_1;
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar3 = iVar3 + iVar5;
      *(int *)(iVar3 + 0x17c) = iVar2;
      piVar4 = *(int **)(iVar5 + 0x204);
      *(int *)(iVar5 + 0x204) = iVar3 + 0x16c;
      *(int *)(iVar3 + 0x16c) = iVar6;
      *(int **)(iVar3 + 0x170) = piVar4;
      *piVar4 = iVar3 + 0x16c;
      iVar3 = iVar2 + 0xc6;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*(int *)(iVar5 + 0xbc) + iVar3 * 4) = 0;
      iVar3 = iVar2 * 0x1c;
    } while (iVar2 != 5);
    *(undefined4 *)(iVar5 + 0x218) = 1;
  }
  return 0;
}



int vic_core_ops_ioctl(undefined *param_1,int param_2,undefined **param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (param_2 == 0x1000001) {
    if (param_1 == (undefined *)0x0) {
      return -0x13;
    }
    if (*(int *)(*(int *)(param_1 + 200) + 0xc) == 0) {
      return 0;
    }
    pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 200) + 0xc) + 4);
    if (pcVar1 == (code *)0x0) {
      return 0;
    }
  }
  else {
    if (param_2 == 0x3000009) {
      iVar2 = tx_isp_subdev_pipo(param_1,param_3);
      goto LAB_00012f6c;
    }
    if (param_2 != 0x1000000) {
      return 0;
    }
    if (param_1 == (undefined *)0x0) {
      return -0x13;
    }
    if (**(int **)(param_1 + 200) == 0) {
      return 0;
    }
    pcVar1 = *(code **)(**(int **)(param_1 + 200) + 4);
    if (pcVar1 == (code *)0x0) {
      return 0;
    }
    param_3 = (undefined **)*param_3;
  }
  iVar2 = (*pcVar1)(param_1,param_3);
LAB_00012f6c:
  if (iVar2 == -0x203) {
    iVar2 = 0;
  }
  return iVar2;
}



int vic_core_ops_ioctl(int param_1,int param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xe8);
  if ((param_2 == 0x1000000) && (iVar2 != 0)) {
    if (**(int **)(iVar2 + 200) == 0) {
      return 0;
    }
    pcVar1 = *(code **)(**(int **)(iVar2 + 200) + 4);
    if (pcVar1 != (code *)0x0) {
      iVar2 = (*pcVar1)(iVar2,*param_3);
      if (iVar2 == -0x203) {
        iVar2 = 0;
      }
      return iVar2;
    }
  }
  return 0;
}



int vin_s_stream(int param_1,int param_2)

{
  undefined4 uVar1;
  code **ppcVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xe8);
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0xf8) != 4) {
      return 0;
    }
  }
  else if (*(int *)(param_1 + 0xf8) == 4) {
    return 0;
  }
  if (iVar4 != 0) {
    ppcVar2 = *(code ***)(*(int *)(iVar4 + 200) + 4);
    if (ppcVar2 == (code **)0x0) {
      return -0x203;
    }
    pcVar3 = *ppcVar2;
    if (pcVar3 == (code *)0x0) {
      return -0x203;
    }
    iVar4 = (*pcVar3)(iVar4,param_2);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  uVar1 = 4;
  if (param_2 == 0) {
    uVar1 = 3;
  }
  *(undefined4 *)(param_1 + 0xf8) = uVar1;
  return 0;
}



int tx_isp_vin_reset(int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xe8) == 0) {
    isp_printf();
    iVar2 = -1;
  }
  else {
    iVar2 = **(int **)(*(int *)(param_1 + 0xe8) + 200);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      pcVar1 = *(code **)(iVar2 + 8);
      if (pcVar1 == (code *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*pcVar1)();
        if (iVar2 == -0x203) {
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}



int tx_isp_vin_init(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0xe8) == 0) {
    isp_printf();
    iVar1 = -1;
  }
  else {
    iVar1 = **(int **)(*(int *)(param_1 + 0xe8) + 200);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      pcVar2 = *(code **)(iVar1 + 4);
      if (pcVar2 == (code *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*pcVar2)();
        if (iVar1 == -0x203) {
          iVar1 = 0;
        }
      }
    }
  }
  uVar3 = 3;
  if (param_2 == 0) {
    uVar3 = 2;
  }
  *(undefined4 *)(param_1 + 0xf8) = uVar3;
  return iVar1;
}



undefined4 tx_isp_vin_probe(undefined4 *param_1)

{
  void *__s;
  undefined4 uVar1;
  uint uVar2;
  
  __s = (void *)private_kmalloc();
  if (__s == (void *)0x0) {
    isp_printf();
    uVar1 = 0xfffffff4;
  }
  else {
    memset(__s,0,0x100);
    private_raw_mutex_init();
    *(int *)((int)__s + 0xe0) = (int)__s + 0xe0;
    *(int *)((int)__s + 0xe4) = (int)__s + 0xe0;
    *(undefined4 *)((int)__s + 0xfc) = 0;
    *(undefined4 *)((int)__s + 0xe8) = 0;
    uVar2 = tx_isp_subdev_init(param_1,__s,vin_subdev_ops);
    if (uVar2 == 0) {
      *(void **)((int)__s + 0xdc) = __s;
      private_platform_set_drvdata();
      *(undefined1 **)((int)__s + 0x38) = video_input_cmd_fops;
      *(undefined4 *)((int)__s + 0xf8) = 1;
      uVar1 = 0;
    }
    else {
      isp_printf();
      private_kfree();
      uVar1 = 0xfffffff4;
    }
  }
  return uVar1;
}



int subdev_sensor_ops_set_input(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_20 [3];
  
  local_20[0] = 0;
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    return -0x16;
  }
  iVar2 = *(int *)(param_1 + 0xe8);
  if (iVar2 == 0) {
LAB_0001333c:
    if (*param_2 == 0xffffffff) {
      return 0;
    }
    private_mutex_lock();
    for (puVar3 = *(undefined4 **)(param_1 + 0xe0);
        (puVar4 = puVar3 + -0x3a, puVar3 != (undefined4 *)(param_1 + 0xe0) &&
        (puVar3[-2] != *param_2)); puVar3 = (undefined4 *)*puVar3) {
    }
    private_mutex_unlock();
    if (puVar3[-2] != *param_2) {
      isp_printf();
      return -0x16;
    }
    *(undefined4 **)(param_1 + 0xe8) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      return -2;
    }
    if ((code *)puVar3[-0x1a] == (code *)0x0) {
      return -0x203;
    }
    iVar2 = (*(code *)puVar3[-0x1a])(puVar4,0x1000001,puVar3 + 0x54);
    if (iVar2 != 0) {
      return iVar2;
    }
    local_20[0] = 1;
    if ((code *)puVar3[-0x1a] != (code *)0x0) {
      iVar1 = (*(code *)puVar3[-0x1a])(puVar4,0x1000000,local_20);
      if (iVar1 == 0) {
        *param_2 = (uint)*(ushort *)(puVar3 + 99) | puVar3[0x62] << 0x10;
        return 0;
      }
      goto LAB_000134d0;
    }
  }
  else {
    if (*param_2 == *(uint *)(iVar2 + 0xe0)) {
      return 0;
    }
    if (*(int *)(param_1 + 0xf8) == 4) {
      isp_printf();
      return -1;
    }
    if (*(code **)(param_1 + 0x80) != (code *)0x0) {
      iVar1 = (**(code **)(param_1 + 0x80))(param_1,0x1000000,local_20);
      if (iVar1 != 0) goto LAB_000134d0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
      if (*(code **)(iVar2 + 0x80) == (code *)0x0) {
        return -0x203;
      }
      iVar2 = (**(code **)(iVar2 + 0x80))(iVar2,0x1000001,0);
      if (iVar2 != 0) {
        return iVar2;
      }
      goto LAB_0001333c;
    }
  }
  iVar1 = -0x203;
LAB_000134d0:
  isp_printf();
  return iVar1;
}



undefined4 tx_isp_vin_activate_subdev(int param_1)

{
  private_mutex_lock();
  if (*(int *)(param_1 + 0xf8) == 1) {
    *(undefined4 *)(param_1 + 0xf8) = 2;
  }
  private_mutex_unlock();
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  return 0;
}



undefined4 video_input_cmd_open(void)

{
  undefined4 uVar1;
  
  PDE_DATA();
  uVar1 = private_single_open_size();
  return uVar1;
}



uint video_input_cmd_set(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 extraout_v0;
  code *pcVar6;
  undefined4 extraout_v0_00;
  uint extraout_v0_01;
  char *pcVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  uint uVar11;
  undefined1 *__s;
  int unaff_gp;
  int local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  uVar4 = *(uint *)(*(int *)(param_1 + 0x78) + 0x48);
  if ((uVar4 == 0 || 0xfffff000 < uVar4) || (bVar3 = 0xfffff000 < uVar4, uVar4 == 0)) {
    uVar4 = 0;
    bVar3 = true;
  }
  if (bVar3) {
    uVar4 = 0;
    bVar3 = true;
  }
  else {
    uVar4 = *(uint *)(uVar4 + 0xdc);
    bVar3 = true;
    if (uVar4 != 0) {
      bVar3 = 0xfffff000 < uVar4;
    }
  }
  uVar11 = 0;
  if (bVar3) {
    bVar3 = true;
  }
  else {
    uVar11 = *(uint *)(uVar4 + 0xe8);
    bVar3 = true;
    if (uVar11 != 0) {
      bVar3 = 0xfffff000 < uVar11;
    }
  }
  if (bVar3) {
    private_seq_printf();
    return 0;
  }
  if (param_3 < 0x81) {
    __s = video_input_cmd_buf;
  }
  else {
    __s = (undefined1 *)private_kmalloc();
    if (__s == (char *)0x0) {
      return 0xfffffff4;
    }
    memset(__s,0,param_3 + 1);
  }
  uVar4 = param_3;
  if (((param_2 | param_3 | param_2 + param_3) & *(uint *)(unaff_gp + 0x18)) == 0) {
    __might_fault("/home_a/ywu/t31-4.4/new/Project/isp-t31-kernel-4.4/t31-firmware/videoin/tx-isp-video-in.c"
                  ,0x264);
    __copy_user(__s,param_2);
  }
  else {
    memset(__s,0,param_3);
  }
  if (uVar4 != 0) {
    uVar4 = 0xfffffff2;
    goto LAB_00013b2c;
  }
  iVar9 = 9;
  pcVar7 = "r sen_reg";
  iVar8 = 9;
  pcVar5 = __s;
  while( true ) {
    cVar1 = *pcVar5;
    cVar2 = *pcVar7;
    cVar10 = cVar2;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar5 = pcVar5 + 1;
    cVar10 = cVar1;
    if ((cVar2 != cVar1) || (pcVar7 = pcVar7 + 1, cVar10 = cVar2, cVar1 == '\0')) break;
  }
  uVar4 = param_3;
  if (cVar10 == cVar2) {
    private_simple_strtoull();
    local_48[0] = uVar11 + 0x90;
    local_3c = 0;
    local_40 = extraout_v0;
    if ((((uVar11 == 0) || (**(int **)(uVar11 + 200) == 0)) ||
        (pcVar6 = *(code **)(**(int **)(uVar11 + 200) + 0xc), pcVar6 == (code *)0x0)) ||
       (iVar8 = (*pcVar6)(uVar11,local_48), iVar8 != 0)) {
      isp_printf();
    }
    uVar11 = local_38;
    private_seq_printf();
    sprintf(video_input_cmd_buf,"0x%x\n",uVar11);
    goto LAB_00013b2c;
  }
  pcVar7 = "r list";
  iVar8 = 6;
  pcVar5 = __s;
  while( true ) {
    cVar1 = *pcVar5;
    cVar2 = *pcVar7;
    cVar10 = cVar2;
    if (iVar8 == 0) break;
    iVar8 = iVar8 + -1;
    pcVar5 = pcVar5 + 1;
    cVar10 = cVar1;
    if ((cVar2 != cVar1) || (pcVar7 = pcVar7 + 1, cVar10 = cVar2, cVar1 == '\0')) break;
  }
  if (cVar10 == cVar2) {
    local_48[0] = uVar11 + 0x90;
    if (((uVar11 != 0) && (**(int **)(uVar11 + 200) != 0)) &&
       (pcVar6 = *(code **)(**(int **)(uVar11 + 200) + 0x10), pcVar6 != (code *)0x0)) {
      iVar8 = (*pcVar6)(uVar11,local_48);
joined_r0x000139f0:
      if (iVar8 == 0) goto LAB_00013b2c;
    }
  }
  else {
    pcVar7 = "r all";
    iVar8 = 5;
    pcVar5 = __s;
    while( true ) {
      cVar1 = *pcVar5;
      cVar2 = *pcVar7;
      cVar10 = cVar2;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar5 = pcVar5 + 1;
      cVar10 = cVar1;
      if ((cVar2 != cVar1) || (pcVar7 = pcVar7 + 1, cVar10 = cVar2, cVar1 == '\0')) break;
    }
    if (cVar10 != cVar2) {
      pcVar5 = "w sen_reg";
      while( true ) {
        cVar1 = *__s;
        cVar2 = *pcVar5;
        cVar10 = cVar2;
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        __s = __s + 1;
        cVar10 = cVar1;
        if ((cVar2 != cVar1) || (pcVar5 = pcVar5 + 1, cVar10 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar10 == cVar2) {
        local_30 = 0;
        private_simple_strtoull();
        private_simple_strtoull();
        private_seq_printf();
        local_48[0] = uVar11 + 0x90;
        local_3c = 0;
        local_34 = 0;
        local_40 = extraout_v0_00;
        local_38 = extraout_v0_01;
        if ((((uVar11 == 0) || (**(int **)(uVar11 + 200) == 0)) ||
            (pcVar6 = *(code **)(**(int **)(uVar11 + 200) + 0x18), pcVar6 == (code *)0x0)) ||
           (iVar8 = (*pcVar6)(uVar11,local_48), iVar8 != 0)) {
          pcVar5 = "failed";
        }
        else {
          pcVar5 = "ok";
        }
        sprintf(video_input_cmd_buf,"%s\n",pcVar5);
      }
      else {
        sprintf(video_input_cmd_buf,"null");
      }
      goto LAB_00013b2c;
    }
    local_48[0] = uVar11 + 0x90;
    if (((uVar11 != 0) && (**(int **)(uVar11 + 200) != 0)) &&
       (pcVar6 = *(code **)(**(int **)(uVar11 + 200) + 0x14), pcVar6 != (code *)0x0)) {
      iVar8 = (*pcVar6)(uVar11,local_48);
      goto joined_r0x000139f0;
    }
  }
  isp_printf();
LAB_00013b2c:
  if (0x80 < param_3) {
    private_kfree();
  }
  return uVar4;
}



undefined4 subdev_sensor_ops_release_all_sensor(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (*(int *)(param_1 + 0xf8) == 1) {
    isp_printf();
    uVar1 = 0xffffffff;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xe0);
    while (piVar2 != (int *)(param_1 + 0xe0)) {
      piVar3 = (int *)piVar2[1];
      iVar4 = *piVar2;
      *(int **)(iVar4 + 4) = piVar3;
      *piVar3 = iVar4;
      *piVar2 = 0x100;
      piVar2[1] = 0x200;
      if (piVar2[10] == 1) {
        if (*(int *)(piVar2[-4] + 0x18) != 0) {
          private_i2c_put_adapter();
        }
        private_i2c_unregister_device();
        piVar2 = *(int **)(param_1 + 0xe0);
      }
      else {
        if (piVar2[10] != 2) {
          isp_printf();
          return 0xffffffea;
        }
        piVar2 = *(int **)(param_1 + 0xe0);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 tx_isp_vin_slake_subdev(int param_1)

{
  int iVar1;
  uint local_18 [3];
  
  if (*(int *)(param_1 + 0xfc) != 0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  }
  if (*(int *)(param_1 + 0xfc) == 0) {
    iVar1 = *(int *)(param_1 + 0xf8);
    if (iVar1 == 4) {
      vin_s_stream(param_1,0);
      iVar1 = *(int *)(param_1 + 0xf8);
    }
    if (iVar1 == 3) {
      tx_isp_vin_init(param_1,0);
      iVar1 = *(int *)(param_1 + 0xe8);
    }
    else {
      iVar1 = *(int *)(param_1 + 0xe8);
    }
    if (iVar1 != 0) {
      local_18[0] = 0xffffffff;
      subdev_sensor_ops_set_input(param_1,local_18);
    }
    if (*(int *)(param_1 + 0xe0) != param_1 + 0xe0) {
      subdev_sensor_ops_release_all_sensor(param_1);
    }
    private_mutex_lock();
    if (*(int *)(param_1 + 0xf8) == 2) {
      *(undefined4 *)(param_1 + 0xf8) = 1;
    }
    private_mutex_unlock();
  }
  return 0;
}



undefined4 video_input_cmd_show(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x48);
  if ((uVar2 == 0 || 0xfffff000 < uVar2) || (bVar1 = 0xfffff000 < uVar2, uVar2 == 0)) {
    uVar2 = 0;
    bVar1 = true;
  }
  iVar3 = 0;
  if (!bVar1) {
    iVar3 = *(int *)(uVar2 + 0xdc);
  }
  if (*(int *)(iVar3 + 0xf8) < 4) {
    private_seq_printf();
  }
  else {
    private_seq_printf();
  }
  return 0;
}



int isp_i2c_new_subdev_board(undefined4 param_1,int param_2)

{
  int iVar1;
  
  private_request_module();
  if (*(short *)(param_2 + 0x16) != 0) {
    iVar1 = private_i2c_new_device();
    if (iVar1 != 0) {
      if ((*(int *)(iVar1 + 100) != 0x1c) && (iVar1 = private_try_module_get(), iVar1 != 0)) {
        iVar1 = private_i2c_get_clientdata();
        private_module_put();
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      private_i2c_unregister_device();
    }
  }
  return 0;
}



undefined4 subdev_sensor_ops_enum_input(int param_1,int *param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 0xffffffea;
  }
  private_mutex_lock();
  iVar3 = 0;
  for (puVar7 = *(undefined4 **)(param_1 + 0xe0); puVar7 != (undefined4 *)(param_1 + 0xe0);
      puVar7 = (undefined4 *)*puVar7) {
    puVar7[-2] = iVar3;
    bVar1 = iVar3 == *param_2;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      puVar6 = puVar7 + 2;
      iVar3 = 0x20;
      param_2[9] = puVar7[-1];
      piVar4 = param_2 + 1;
      goto LAB_00013fa4;
    }
  }
  goto LAB_00013fe4;
  while (puVar6 = (undefined4 *)((int)puVar6 + 1), iVar3 != 0) {
LAB_00013fa4:
    cVar2 = *(char *)puVar6;
    iVar3 = iVar3 + -1;
    *(char *)piVar4 = cVar2;
    piVar4 = (int *)((int)piVar4 + 1);
    if (cVar2 == '\0') break;
  }
LAB_00013fe4:
  private_mutex_unlock();
  if (puVar7[-2] == *param_2) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



int subdev_sensor_ops_ioctl(int param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int **ppiVar7;
  int iVar8;
  code *pcVar9;
  undefined4 *puVar10;
  uint uVar11;
  char cVar12;
  int **ppiVar13;
  int *piVar14;
  undefined auStack_48 [22];
  undefined2 local_32;
  
  uVar11 = *(uint *)(param_1 + 0xe8);
  switch(param_2) {
  case 0x2000000:
    if (param_1 == 0) {
      return -0x16;
    }
    if (param_3 == (undefined4 *)0x0) {
      return -0x16;
    }
    if (*(int *)(param_1 + 0xf8) == 1) goto LAB_00014358;
    if (param_3[8] == 1) {
      iVar8 = private_i2c_get_adapter();
      if (iVar8 == 0) {
LAB_000141e4:
        isp_printf();
        return -0x16;
      }
      memset(auStack_48,0,0x2c);
      memcpy(auStack_48,param_3 + 9,0x14);
      local_32 = (undefined2)param_3[0xe];
      pvVar5 = (void *)isp_i2c_new_subdev_board(iVar8,(int)auStack_48);
      if (pvVar5 == (void *)0x0 || (void *)0xfffff000 < pvVar5) {
        private_i2c_put_adapter();
        goto LAB_000141e4;
      }
      iVar8 = *(int *)((int)pvVar5 + 0xdc);
    }
    else {
      pvVar5 = (void *)0x0;
      iVar8 = iRam000000dc;
      if (param_3[8] != 2) {
LAB_000144c0:
        isp_printf();
        return -0x16;
      }
    }
    memcpy((void *)(iVar8 + 0xf0),param_3,0x50);
    if (pvVar5 != (void *)0x0) {
      if ((code **)**(int **)((int)pvVar5 + 200) == (code **)0x0) {
        iVar8 = param_3[8];
        goto LAB_00014248;
      }
      pcVar9 = *(code **)**(int **)((int)pvVar5 + 200);
      if (pcVar9 != (code *)0x0) {
        iVar6 = (*pcVar9)(pvVar5,(int)pvVar5 + 0x90);
        if (iVar6 == 0) {
          private_mutex_lock();
          piVar14 = *(int **)(param_1 + 0xe4);
          *(int *)(param_1 + 0xe4) = iVar8 + 0xe8;
          *(int *)(iVar8 + 0xe8) = param_1 + 0xe0;
          *(int **)(iVar8 + 0xec) = piVar14;
          *piVar14 = iVar8 + 0xe8;
          private_mutex_unlock();
          *(undefined4 *)((int)pvVar5 + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
          isp_printf();
          return 0;
        }
        iVar8 = param_3[8];
        goto LAB_00014248;
      }
    }
    iVar8 = param_3[8];
LAB_00014248:
    if (iVar8 == 1) {
      if (*(int *)(*(int *)((int)pvVar5 + 0xd8) + 0x18) != 0) {
        private_i2c_put_adapter();
      }
      private_i2c_unregister_device();
    }
    tx_isp_subdev_deinit(pvVar5);
    return -0x16;
  case 0x2000001:
    if (param_1 == 0) {
      return -0x16;
    }
    if (param_3 == (undefined4 *)0x0) {
      return -0x16;
    }
    piVar14 = (int *)(param_1 + 0xec);
    if (*(int *)(param_1 + 0xf8) != 1) {
      private_mutex_lock();
      ppiVar13 = *(int ***)(param_1 + 0xe0);
      do {
        if (ppiVar13 == (int **)(param_1 + 0xe0)) {
LAB_000143e8:
          pcVar9 = private_mutex_unlock;
LAB_00014490:
          (*pcVar9)(piVar14);
          return 0;
        }
        ppiVar7 = ppiVar13 + 2;
        cVar2 = *(char *)ppiVar7;
        puVar10 = param_3;
        do {
          cVar3 = *(char *)puVar10;
          ppiVar7 = (int **)((int)ppiVar7 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
          cVar12 = cVar2;
          if (cVar3 != cVar2) break;
          bVar1 = cVar2 != '\0';
          cVar2 = *(char *)ppiVar7;
          cVar12 = cVar3;
        } while (bVar1);
        if (cVar12 == cVar3) {
          if (ppiVar13 != (int **)0xe8) {
            if (ppiVar13 + -0x3a == *(int ***)(param_1 + 0xe8)) {
              private_mutex_unlock();
              isp_printf();
              return -0x16;
            }
            ppiVar7 = (int **)ppiVar13[1];
            piVar14 = *ppiVar13;
            piVar14[1] = (int)ppiVar7;
            *ppiVar7 = piVar14;
            *ppiVar13 = (int *)0x100;
            ppiVar13[1] = (int *)0x200;
            private_mutex_unlock();
            if (ppiVar13[10] != (int *)0x1) {
              if (ppiVar13[10] == (int *)0x2) {
                return 0;
              }
              goto LAB_000144c0;
            }
            piVar14 = ppiVar13[-4];
            if (piVar14[6] != 0) {
              private_i2c_put_adapter();
            }
            pcVar9 = private_i2c_unregister_device;
            goto LAB_00014490;
          }
          goto LAB_000143e8;
        }
        ppiVar13 = (int **)*ppiVar13;
      } while( true );
    }
LAB_00014358:
    isp_printf();
    return -1;
  case 0x2000002:
    pcVar9 = subdev_sensor_ops_enum_input;
    break;
  case 0x2000003:
    if (param_1 == 0) {
      return -0x16;
    }
    if (param_3 == (undefined4 *)0x0) {
      return -0x16;
    }
    uVar4 = 0xffffffff;
    if (uVar11 != 0 && uVar11 < 0xfffff001) {
      uVar4 = *(undefined4 *)(uVar11 + 0xe0);
    }
    *param_3 = uVar4;
    goto LAB_00014564;
  case 0x2000004:
    pcVar9 = subdev_sensor_ops_set_input;
    break;
  default:
    if (uVar11 == 0) {
LAB_00014590:
      isp_printf();
      return -1;
    }
    iVar8 = *(int *)(*(int *)(uVar11 + 200) + 0xc);
    if (iVar8 == 0) goto LAB_00014564;
    pcVar9 = *(code **)(iVar8 + 8);
    if (pcVar9 == (code *)0x0) {
      return 0;
    }
    iVar8 = (*pcVar9)(uVar11,param_2,param_3);
    goto LAB_000145a8;
  case 0x2000011:
    if (uVar11 == 0) goto LAB_00014590;
    if (**(int **)(uVar11 + 200) == 0) {
      return 0;
    }
    pcVar9 = *(code **)(**(int **)(uVar11 + 200) + 0x18);
    goto LAB_00014524;
  case 0x2000012:
    if (uVar11 == 0) goto LAB_00014590;
    if (**(int **)(uVar11 + 200) == 0) {
      return 0;
    }
    pcVar9 = *(code **)(**(int **)(uVar11 + 200) + 0xc);
LAB_00014524:
    if (pcVar9 == (code *)0x0) {
      return 0;
    }
    iVar8 = (*pcVar9)(uVar11,param_3);
    goto LAB_000145a8;
  }
  iVar8 = (*pcVar9)(param_1,param_3);
LAB_000145a8:
  if (iVar8 == -0x203) {
LAB_00014564:
    iVar8 = 0;
  }
  return iVar8;
}



undefined4 tx_isp_csi_probe(undefined4 *param_1)

{
  void *__s;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  __s = (void *)private_kmalloc();
  if (__s == (void *)0x0) {
    isp_printf();
    uVar3 = 0xfffffff4;
  }
  else {
    memset(__s,0,0x14c);
    uVar1 = tx_isp_subdev_init(param_1,__s,csi_subdev_ops);
    if (uVar1 == 0) {
      iVar2 = private_request_mem_region();
      if (iVar2 == 0) {
        isp_printf();
        uVar3 = 0xfffffff0;
      }
      else {
        uVar3 = private_ioremap();
        *(undefined4 *)((int)__s + 0x140) = uVar3;
        if (*(int *)((int)__s + 0xbc) != 0) {
          *(undefined1 **)((int)__s + 0x38) = isp_csi_fops;
          *(int *)((int)__s + 0x13c) = iVar2;
          private_raw_mutex_init();
          private_platform_set_drvdata();
          *(undefined4 *)((int)__s + 300) = 1;
          *(void **)((int)__s + 0xd8) = __s;
          dump_csd = __s;
          return 0;
        }
        isp_printf();
        private_release_mem_region();
        uVar3 = 0xfffffffa;
      }
      tx_isp_subdev_deinit(__s);
    }
    else {
      isp_printf();
      uVar3 = 0xfffffff4;
    }
    private_kfree();
  }
  return uVar3;
}



undefined4 csi_clks_ops(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    bVar1 = true;
    if (*(uint *)(param_1 + 0xc0) != 0) {
      bVar1 = 0xfffff000 < *(uint *)(param_1 + 0xc0);
    }
  }
  if (!bVar1) {
    if (param_2 == 0) {
      iVar5 = *(int *)(param_1 + 0xc4);
      iVar3 = 0;
      while (iVar3 = iVar3 + 1, -1 < iVar5 - iVar3) {
        private_clk_disable_unprepare();
      }
    }
    else {
      uVar2 = *(uint *)(param_1 + 0xc4);
      for (uVar4 = 0; uVar4 < uVar2; uVar4 = uVar4 + 1) {
        private_clk_prepare_enable();
        uVar2 = *(uint *)(param_1 + 0xc4);
      }
    }
  }
  return 0;
}



undefined4 tx_isp_csi_activate_subdev(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar3 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar3 != 0) {
      bVar1 = 0xfffff000 < uVar3;
    }
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else {
    private_mutex_lock();
    if (*(int *)(uVar3 + 300) == 1) {
      *(undefined4 *)(uVar3 + 300) = 2;
      csi_clks_ops(param_1,1);
    }
    private_mutex_unlock();
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 dump_isp_csi_open(void)

{
  undefined4 uVar1;
  
  PDE_DATA();
  uVar1 = private_single_open_size();
  return uVar1;
}



int isp_csi_show(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar2 = *(uint *)(param_1 + 0x48);
  if ((uVar2 == 0 || 0xfffff000 < uVar2) || (bVar1 = 0xfffff000 < uVar2, uVar2 == 0)) {
    uVar2 = 0;
    bVar1 = true;
  }
  uVar7 = 0;
  if (bVar1) {
    bVar1 = true;
  }
  else {
    uVar7 = *(uint *)(uVar2 + 0xd8);
    bVar1 = true;
    if (uVar7 != 0) {
      bVar1 = 0xfffff000 < uVar7;
    }
  }
  if (bVar1) {
    isp_printf();
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    iVar5 = *(int *)(*(int *)(uVar7 + 0xbc) + 0x20);
    iVar3 = *(int *)(*(int *)(uVar7 + 0xbc) + 0x24);
    if (iVar5 != 0) {
      iVar6 = seq_printf(param_1,"0x0020 is  0x%08x\n",iVar5);
    }
    if (iVar3 != 0) {
      iVar4 = seq_printf(param_1,"0x0024 is  0x%08x\n",iVar3);
      iVar6 = iVar6 + iVar4;
    }
    if (iVar5 == 0) {
      if (iVar3 == 0) {
        return iVar6;
      }
      iVar3 = *(int *)(uVar7 + 0xbc);
    }
    else {
      iVar3 = *(int *)(uVar7 + 0xbc);
    }
    iVar3 = seq_printf(param_1,"0x0014 is  0x%08x\n",*(undefined4 *)(iVar3 + 0x14));
    iVar6 = iVar6 + iVar3;
  }
  return iVar6;
}



undefined4 csi_video_s_stream(uint param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      bVar1 = true;
      goto LAB_00014be4;
    }
    bVar1 = false;
    if (param_1 < 0xfffff001) goto LAB_00014be4;
  }
  bVar1 = true;
LAB_00014be4:
  if (bVar1) {
    isp_printf();
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    if (*(int *)(*(int *)(param_1 + 0x114) + 0x14) == 1) {
      uVar3 = 4;
      if (param_2 == 0) {
        uVar3 = 3;
      }
      *(undefined4 *)(param_1 + 300) = uVar3;
      return uVar2;
    }
  }
  return uVar2;
}



undefined4 csi_sensor_ops_sync_sensor_attr(uint param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      bVar1 = true;
      goto LAB_00014c88;
    }
    bVar1 = false;
    if (param_1 < 0xfffff001) goto LAB_00014c88;
  }
  bVar1 = true;
LAB_00014c88:
  if (bVar1) {
    isp_printf();
    uVar2 = 0xffffffea;
  }
  else {
    if (param_2 == 0) {
      param_2 = 0;
      pcVar3 = memset;
    }
    else {
      pcVar3 = memcpy;
    }
    (*pcVar3)(param_1 + 0xe0,param_2,0x4c);
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 csi_core_ops_init(uint param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar5 != 0) {
      bVar1 = 0xfffff000 < uVar5;
    }
  }
  uVar2 = 0xffffffea;
  if ((!bVar1) && (uVar2 = 0, 1 < *(int *)(uVar5 + 300))) {
    if (param_2 == 0) {
      isp_printf();
      *(uint *)(*(int *)(uVar5 + 0xbc) + 8) = *(uint *)(*(int *)(uVar5 + 0xbc) + 8) & 0xfffffffe;
      *(uint *)(*(int *)(uVar5 + 0xbc) + 0xc) = *(uint *)(*(int *)(uVar5 + 0xbc) + 0xc) & 0xfffffffe
      ;
      *(uint *)(*(int *)(uVar5 + 0xbc) + 0x10) =
           *(uint *)(*(int *)(uVar5 + 0xbc) + 0x10) & 0xfffffffe;
      uVar2 = 2;
    }
    else {
      iVar6 = *(int *)(*(int *)(uVar5 + 0x114) + 0x14);
      if (iVar6 == 1) {
        *(uint *)(*(int *)(uVar5 + 0xbc) + 4) = *(byte *)(*(int *)(uVar5 + 0x114) + 0x24) - 1;
        *(uint *)(*(int *)(uVar5 + 0xbc) + 8) = *(uint *)(*(int *)(uVar5 + 0xbc) + 8) & 0xfffffffe;
        *(undefined4 *)(*(int *)(uVar5 + 0xbc) + 0xc) = 0;
        private_msleep();
        *(uint *)(*(int *)(uVar5 + 0xbc) + 0x10) =
             *(uint *)(*(int *)(uVar5 + 0xbc) + 0x10) & 0xfffffffe;
        private_msleep();
        *(undefined4 *)(*(int *)(uVar5 + 0xbc) + 0xc) = 1;
        private_msleep();
        if (*(int *)(*(int *)(uVar5 + 0x114) + 0x3c) == 0) {
          iVar6 = *(int *)(*(int *)(uVar5 + 0x114) + 0x1c);
          uVar4 = 0;
          if ((((((0x1d < iVar6 - 0x50U) && (uVar4 = 1, 0x27 < iVar6 - 0x6eU)) &&
                (uVar4 = 2, 0x31 < iVar6 - 0x96U)) &&
               ((uVar4 = 3, 0x31 < iVar6 - 200U && (uVar4 = 4, 0x31 < iVar6 - 0xfaU)))) &&
              ((uVar4 = 5, 99 < iVar6 - 300U &&
               ((uVar4 = 6, 99 < iVar6 - 400U && (uVar4 = 7, 99 < iVar6 - 500U)))))) &&
             ((uVar4 = 8, 99 < iVar6 - 600U && (uVar4 = 9, 99 < iVar6 - 700U)))) {
            uVar4 = 0xb;
          }
          uVar4 = uVar4 | *(uint *)(*(int *)(uVar5 + 0x140) + 0x160) & 0xfffffff0;
          *(uint *)(*(int *)(uVar5 + 0x140) + 0x160) = uVar4;
          *(uint *)(*(int *)(uVar5 + 0x140) + 0x1e0) = uVar4;
          *(uint *)(*(int *)(uVar5 + 0x140) + 0x260) = uVar4;
          puVar3 = *(undefined4 **)(uVar5 + 0x140);
        }
        else {
          puVar3 = *(undefined4 **)(uVar5 + 0x140);
        }
        *puVar3 = 0x7d;
        *(undefined4 *)(*(int *)(uVar5 + 0x140) + 0x128) = 0x3f;
        *(undefined4 *)(*(int *)(uVar5 + 0xbc) + 0x10) = 1;
        private_msleep();
        uVar2 = 3;
      }
      else if (iVar6 == 2) {
        *(undefined4 *)(*(int *)(uVar5 + 0xbc) + 0xc) = 0;
        *(undefined4 *)(*(int *)(uVar5 + 0xbc) + 0xc) = 1;
        **(undefined4 **)(uVar5 + 0x140) = 0x7d;
        *(undefined4 *)(*(int *)(uVar5 + 0x140) + 0x80) = 0x3e;
        *(undefined4 *)(*(int *)(uVar5 + 0x140) + 0x2cc) = 1;
        uVar2 = 3;
      }
      else {
        isp_printf();
        uVar2 = 3;
      }
    }
    *(undefined4 *)(uVar5 + 300) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 tx_isp_csi_slake_subdev(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_1 == 0 || 0xfffff000 < param_1) {
    bVar1 = true;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xd8);
    bVar1 = true;
    if (uVar4 != 0) {
      bVar1 = 0xfffff000 < uVar4;
    }
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar3 = *(int *)(uVar4 + 300);
    if (iVar3 == 4) {
      csi_video_s_stream(param_1,0);
      iVar3 = *(int *)(uVar4 + 300);
    }
    if (iVar3 == 3) {
      csi_core_ops_init(param_1,0);
    }
    private_mutex_lock();
    if (*(int *)(uVar4 + 300) == 2) {
      *(undefined4 *)(uVar4 + 300) = 1;
      csi_clks_ops(param_1,0);
    }
    private_mutex_unlock();
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 csi_sensor_ops_ioctl(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    uVar2 = 0;
  }
  else {
    uVar2 = param_1;
    if ((param_1 != 0) && (bVar1 = false, param_1 < 0xfffff001)) goto LAB_00015128;
  }
  bVar1 = true;
LAB_00015128:
  if (!bVar1) {
    if (param_2 == 0x200000e) {
      if (*(int *)(*(int *)(uVar2 + 0x114) + 0x14) == 1) {
        *(undefined4 *)(uVar2 + 300) = 3;
      }
    }
    else if (param_2 == 0x200000f) {
      if (*(int *)(*(int *)(uVar2 + 0x114) + 0x14) == 1) {
        *(undefined4 *)(uVar2 + 300) = 4;
      }
    }
    else if (param_2 == 0x200000c) {
      csi_core_ops_init(param_1,1);
      return 0;
    }
  }
  return 0;
}



undefined4 dump_csi_reg(void)

{
  undefined4 uVar1;
  
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  isp_printf();
  uVar1 = isp_printf();
  return uVar1;
}



void check_csi_error(void)

{
  int iVar1;
  
  do {
    do {
      dump_csi_reg();
      iVar1 = *(int *)(*(int *)(dump_csd + 0xbc) + 0x24);
      if (*(int *)(*(int *)(dump_csd + 0xbc) + 0x20) != 0) {
        isp_printf();
      }
    } while (iVar1 == 0);
    isp_printf();
  } while( true );
}



undefined4 csi_set_on_lanes(int param_1,uint param_2)

{
  isp_printf();
  *(uint *)(*(int *)(param_1 + 0xbc) + 4) =
       (param_2 & 0xff) - 1 & 3 | *(uint *)(*(int *)(param_1 + 0xbc) + 4) & 0xfffffffc;
  return 0;
}



undefined4 isp_core_tunning_open(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0x78) + 0xcc) + 0x1c0);
  if (*(int *)(iVar1 + 0x40c4) == 2) {
    frame_done_cnt = 0;
    DAT_000b3c9c = 0;
    *(undefined4 *)(iVar1 + 0x40ac) = 0;
    *(undefined4 *)(iVar1 + 0x40c4) = 3;
    return 0;
  }
  return 0xffffffff;
}



undefined4 isp_core_tunning_release(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0x78) + 0xcc) + 0x1c0);
  isp_printf();
  if (*(int *)(iVar1 + 0x40c4) != 2) {
    if (*(int *)(iVar1 + 0x40ac) == 0) {
      *(undefined4 *)(iVar1 + 0x40c4) = 2;
    }
    else {
      isp_free_buffer(*(int *)(iVar1 + 0x40ac));
      *(undefined4 *)(iVar1 + 0x40c4) = 2;
    }
  }
  return 0;
}



undefined4 apical_isp_expr_s_ctrl(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_110;
  uint local_a0;
  undefined local_90 [32];
  int local_70;
  int local_20;
  int local_1c;
  ushort local_18;
  
  iVar2 = *(int *)(*(int *)(*param_1 + 0xd8) + 0x124);
  private_copy_from_user();
  if (local_20 == 0) {
    local_70 = 0;
  }
  else {
    if (local_20 != 1) {
LAB_000155e4:
      isp_printf();
      return 0xffffffff;
    }
    local_70 = local_20;
    if (local_1c == 1) {
      local_a0 = (uint)*(ushort *)(iVar2 + 0xbc);
      if (local_a0 == 0) {
        local_110 = 0;
        isp_printf();
        return 0xffffffff;
      }
      local_a0 = local_18 / local_a0;
    }
    else {
      if (local_1c != 0) goto LAB_000155e4;
      local_a0 = (uint)local_18;
    }
  }
  for (uVar1 = 0; uVar1 < 0x70; uVar1 = uVar1 + 1) {
    *(undefined *)((int)&local_110 + uVar1) = local_90[uVar1];
  }
  tisp_s_ae_attr(local_a0);
  return 0;
}



undefined4 apical_isp_mask_s_attr_isra_43(void)

{
  uint uVar1;
  undefined local_158 [160];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined local_a8 [164];
  
  private_copy_from_user();
  for (uVar1 = 0; uVar1 < 0x9c; uVar1 = uVar1 + 1) {
    local_158[uVar1] = local_a8[uVar1];
  }
  tisp_s_mscaler_mask_attr(local_b8,local_b4,local_b0,local_ac);
  return 0;
}



undefined4 apical_isp_hvflip_update(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff;
  if (*(int *)(param_1 + 0x138) == 1) {
    *(undefined4 *)(param_1 + 0x1ac) = 1;
    *(uint *)(param_1 + 0x1b0) = param_2;
    uVar1 = param_2 & 0xfd;
  }
  tisp_s_mscaler_hvflip_mask(uVar1);
  tisp_hv_flip_enable(uVar1);
  return 0;
}



int apical_isp_gamma_s_attr_isra_48(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 local_210 [130];
  undefined2 local_10c [130];
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = -1;
  }
  else {
    private_copy_from_user();
    iVar1 = 0;
    do {
      puVar2 = (undefined2 *)((int)local_210 + iVar1);
      puVar3 = (undefined2 *)((int)local_10c + iVar1);
      iVar1 = iVar1 + 2;
      *puVar2 = *puVar3;
    } while (iVar1 != 0x102);
    iVar1 = tisp_s_Gamma(local_210);
    if (iVar1 != 0) {
      isp_printf();
    }
  }
  return iVar1;
}



int apical_isp_ae_s_roi_isra_49(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte local_f8 [236];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar5 = -1;
  }
  else {
    iVar5 = -1;
    if (*(int *)(param_1 + 4) != 0) {
      private_copy_from_user();
      iVar5 = 0;
      do {
        iVar3 = 0;
        do {
          iVar1 = iVar3 + iVar5 * 0xf;
          iVar4 = iVar3 * 4;
          if (8 < local_f8[iVar1]) {
            isp_printf();
            iVar5 = -1;
            goto LAB_00015934;
          }
          iVar3 = iVar3 + 1;
          *(uint *)((int)pvVar2 + iVar4 + iVar5 * 0x3c) = (uint)local_f8[iVar1];
        } while (iVar3 != 0xf);
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0xf);
      iVar5 = tisp_s_aeroi_weight(pvVar2);
      if (iVar5 != 0) {
        isp_printf();
      }
    }
LAB_00015934:
    private_kfree();
  }
  return iVar5;
}



int apical_isp_ae_zone_weight_s_attr_isra_59(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte local_f8 [236];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar5 = -1;
  }
  else {
    iVar5 = -1;
    if (*(int *)(param_1 + 4) != 0) {
      private_copy_from_user();
      iVar5 = 0;
      do {
        iVar3 = 0;
        do {
          iVar1 = iVar3 + iVar5 * 0xf;
          iVar4 = iVar3 * 4;
          if (8 < local_f8[iVar1]) {
            isp_printf();
            iVar5 = -1;
            goto LAB_00015a90;
          }
          iVar3 = iVar3 + 1;
          *(uint *)((int)pvVar2 + iVar4 + iVar5 * 0x3c) = (uint)local_f8[iVar1];
        } while (iVar3 != 0xf);
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0xf);
      iVar5 = tisp_s_aezone_weight(pvVar2);
      if (iVar5 != 0) {
        isp_printf();
      }
    }
LAB_00015a90:
    private_kfree();
  }
  return iVar5;
}



int apical_isp_af_weight_s_attr_isra_63(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte local_f8 [236];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar5 = -1;
  }
  else {
    iVar5 = -1;
    if (*(int *)(param_1 + 4) != 0) {
      private_copy_from_user();
      iVar5 = 0;
      do {
        iVar3 = 0;
        do {
          iVar1 = iVar3 + iVar5 * 0xf;
          iVar4 = iVar3 * 4;
          if (8 < local_f8[iVar1]) {
            isp_printf();
            iVar5 = -1;
            goto LAB_00015bec;
          }
          iVar3 = iVar3 + 1;
          *(uint *)((int)pvVar2 + iVar4 + iVar5 * 0x3c) = (uint)local_f8[iVar1];
        } while (iVar3 != 0xf);
        iVar5 = iVar5 + 1;
      } while (iVar5 != 0xf);
      iVar5 = tisp_s_af_weight(pvVar2);
      if (iVar5 != 0) {
        isp_printf();
      }
    }
LAB_00015bec:
    private_kfree();
  }
  return iVar5;
}



// WARNING: Type propagation algorithm not settling

int apical_isp_core_ops_s_ctrl(int *param_1,uint *param_2)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  int in_stack_fffffb18;
  int in_stack_fffffb1c;
  int in_stack_fffffb20;
  int in_stack_fffffb24;
  int in_stack_fffffb28;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_30;
  ushort local_2c;
  ushort local_2a;
  undefined local_28;
  undefined local_27;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  char local_1e;
  byte local_1d;
  byte local_1c;
  byte local_1b;
  uint local_18 [2];
  
  uVar3 = *param_2;
  if (uVar3 == 0x8000039) {
    private_copy_from_user();
    puVar8 = local_18;
    pcVar6 = tisp_set_defog_strength;
LAB_00016d8c:
    iVar7 = (*pcVar6)(puVar8);
    return iVar7;
  }
  if (uVar3 < 0x800003a) {
    if (uVar3 == 0x800000e) {
      private_copy_from_user();
      for (uVar3 = 0; uVar3 < 0x18; uVar3 = uVar3 + 1) {
        (&stack0xfffffb18)[uVar3] = *(undefined *)((int)&local_b8 + uVar3);
      }
      iVar7 = tisp_s_awb_cluster(local_c8,local_c4,local_c0,local_bc);
      return iVar7;
    }
    if (uVar3 < 0x800000f) {
      if (uVar3 == 0x9a0914) {
        return 0;
      }
      if (uVar3 < 0x9a0915) {
        if (uVar3 == 0x980914) {
          uVar9 = param_2[1];
          iVar7 = *(int *)(*param_1 + 0xd8);
          param_1[0x3ad] = uVar9;
          uVar3 = *(uint *)(iVar7 + 0x16c);
          *(uint *)(iVar7 + 0x174) = uVar9;
        }
        else {
          if (uVar3 < 0x980915) {
            if (uVar3 == 0x980901) {
              if (*(int *)(*(int *)(*param_1 + 0xd8) + 0xf8) == 0x2011) {
                return 0;
              }
              bVar1 = *(byte *)(param_2 + 1);
              pcVar6 = tisp_set_contrast;
              param_1[0x1023] = (uint)bVar1;
              local_c8 = (uint)bVar1;
            }
            else if (uVar3 == 0x980902) {
              if (*(int *)(*(int *)(*param_1 + 0xd8) + 0xf8) == 0x2011) {
                return 0;
              }
              bVar1 = *(byte *)(param_2 + 1);
              pcVar6 = tisp_set_saturation;
              param_1[0x1024] = (uint)bVar1;
              local_c8 = (uint)bVar1;
            }
            else {
              if (uVar3 != 0x980900) {
                return 0xffffffff;
              }
              if (*(int *)(*(int *)(*param_1 + 0xd8) + 0xf8) == 0x2011) {
                return 0;
              }
              bVar1 = *(byte *)(param_2 + 1);
              pcVar6 = tisp_set_brightness;
              param_1[0x1025] = (uint)bVar1;
              local_c8 = (uint)bVar1;
            }
            goto LAB_00016b94;
          }
          if (uVar3 == 0x980918) {
            param_1[0x3bf] = param_2[1];
            iVar7 = -0x16;
            if (param_2[1] < 3) {
              iVar7 = (int)*(char *)((int)&CSWTCH_87 + param_2[1]);
            }
            iVar7 = tisp_s_antiflick(iVar7);
            if (iVar7 == 0) {
              return 0;
            }
            goto LAB_00016d2c;
          }
          if (0x980918 < uVar3) {
            uVar9 = 0x98091f;
            if (uVar3 != 0x98091b) goto LAB_000160cc;
            if (*(int *)(*(int *)(*param_1 + 0xd8) + 0xf8) == 0x2011) {
              return 0;
            }
            bVar1 = *(byte *)(param_2 + 1);
            pcVar6 = tisp_set_sharpness;
            param_1[0xfdb] = (uint)bVar1;
            local_c8 = (uint)bVar1;
            goto LAB_00016b94;
          }
          if (uVar3 != 0x980915) {
            return 0xffffffff;
          }
          uVar3 = param_2[1];
          iVar7 = *(int *)(*param_1 + 0xd8);
          param_1[0x3ac] = uVar3;
          uVar9 = *(uint *)(iVar7 + 0x174);
          *(uint *)(iVar7 + 0x16c) = uVar3;
        }
        uVar4 = 2;
        if (uVar3 == 0) {
          uVar4 = 0;
        }
        uVar4 = uVar4 | uVar9 != 0;
LAB_000162ac:
        apical_isp_hvflip_update(iVar7,uVar4);
        return 0;
      }
      if (uVar3 < 0x8000009) {
        if (0x8000005 < uVar3) {
          return 0;
        }
        if (0x8000002 < uVar3) {
          if (uVar3 != 0x8000004) {
            return 0xffffffff;
          }
          private_copy_from_user();
          switch(local_30) {
          case 0:
            uVar5 = 0;
            break;
          case 1:
            uVar5 = 1;
            break;
          case 2:
            uVar5 = 2;
            break;
          case 3:
            uVar5 = 3;
            break;
          case 4:
            uVar5 = 4;
            break;
          case 5:
            uVar5 = 5;
            break;
          case 6:
            uVar5 = 6;
            break;
          case 7:
            uVar5 = 7;
            break;
          case 8:
            uVar5 = 8;
            break;
          case 9:
            uVar5 = 9;
            break;
          default:
LAB_000168f0:
            isp_printf();
            return -1;
          }
          tisp_s_wb_attr(uVar5,(uint)local_2c,(uint)local_2a);
          return 0;
        }
        if (0x8000000 < uVar3) {
          return 0;
        }
        uVar9 = 0x9a091a;
        goto LAB_000160cc;
      }
      if (uVar3 == 0x800000c) {
        iVar7 = tisp_s_awb_algo(param_2[1]);
        if (iVar7 == 0) {
          return 0;
        }
        goto LAB_00016d2c;
      }
      if (uVar3 < 0x800000d) {
        if (uVar3 == 0x800000a) {
          private_copy_from_user();
          tisp_s_awb_start(local_c8,local_c4);
          return 0;
        }
        return 0xffffffff;
      }
      local_18[0] = *(uint *)param_2[1];
      iVar7 = tisp_s_wb_ct(local_18);
    }
    else {
      if (uVar3 == 0x800002b) {
        pcVar6 = apical_isp_gamma_s_attr_isra_48;
LAB_0001698c:
        iVar7 = (*pcVar6)(param_2);
        return iVar7;
      }
      if (uVar3 < 0x800002c) {
        if (uVar3 == 0x8000024) {
          pcVar6 = apical_isp_ae_s_roi_isra_49;
          goto LAB_0001698c;
        }
        if (uVar3 < 0x8000025) {
          if (uVar3 == 0x8000022) {
            return 0;
          }
          if (0x8000022 < uVar3) {
            if (0xff < param_2[1]) goto LAB_00016bd4;
            pcVar6 = tisp_set_ae_comp;
            local_c8 = param_2[1];
            goto LAB_00016b94;
          }
          if (uVar3 != 0x800000f) {
            return 0xffffffff;
          }
          private_copy_from_user();
          iVar7 = tisp_s_awb_ct_trend(local_c8,local_c4,local_c0,local_bc);
        }
        else {
          if (uVar3 == 0x8000028) {
            pcVar6 = tisp_s_max_again;
            local_c8 = param_2[1];
LAB_00016b94:
            (*pcVar6)(local_c8);
            return 0;
          }
          if (uVar3 < 0x8000029) {
            if (uVar3 == 0x8000025) {
              iVar7 = apical_isp_expr_s_ctrl(param_1);
              return iVar7;
            }
            return 0xffffffff;
          }
          if (uVar3 == 0x8000029) {
            pcVar6 = tisp_s_max_isp_dgain;
            local_c8 = param_2[1];
            goto LAB_00016b94;
          }
          if (uVar3 != 0x800002a) {
            return 0xffffffff;
          }
          iVar7 = tisp_s_Hilightdepress(param_2[1]);
        }
      }
      else if (uVar3 == 0x8000032) {
        iVar7 = tisp_s_ae_it_max(param_2[1]);
      }
      else {
        if (uVar3 < 0x8000033) {
          if (uVar3 != 0x800002d) {
            if (uVar3 < 0x800002d) {
              return 0;
            }
            if (uVar3 != 0x800002e) {
              if (uVar3 != 0x800002f) {
                return 0xffffffff;
              }
              if (param_2[1] != 0) {
                private_copy_from_user();
                iVar7 = tisp_s_ae_min(local_c8,local_c4,local_c0,local_bc);
                return iVar7;
              }
              return 0xffffffff;
            }
            uVar3 = private_kmalloc();
            if (uVar3 == 0) goto LAB_00016bd4;
            private_copy_from_user();
            *(uint *)(uVar3 + 0x414) = local_c8 & 0xff;
            *(uint *)(uVar3 + 0x418) = local_c8 >> 8 & 0xff;
            *(uint *)(uVar3 + 0x41c) = local_c8 >> 0x10 & 0xff;
            *(uint *)(uVar3 + 0x420) = local_c8 >> 0x18;
            for (uVar9 = 0; uVar9 < 0x41c; uVar9 = uVar9 + 1) {
              (&stack0xfffffb18)[uVar9] = *(undefined *)(uVar3 + 0x10 + uVar9);
            }
            tisp_s_ae_hist();
            pcVar6 = private_kfree;
            local_c8 = uVar3;
            goto LAB_00016b94;
          }
          pcVar6 = apical_isp_ae_zone_weight_s_attr_isra_59;
          goto LAB_0001698c;
        }
        if (uVar3 == 0x8000035) {
          private_copy_from_user();
          iVar7 = tisp_set_ae_attr((int *)&local_c8);
        }
        else {
          if (uVar3 < 0x8000036) {
            if (uVar3 != 0x8000034) {
              return 0xffffffff;
            }
            uVar3 = param_2[1];
            pcVar6 = tisp_set_ae_freeze;
            goto LAB_00016a60;
          }
          if (uVar3 == 0x8000037) {
            iVar7 = tisp_s_BacklightComp(param_2[1]);
          }
          else {
            if (uVar3 != 0x8000038) {
              return 0xffffffff;
            }
            private_copy_from_user();
            for (uVar3 = 0; uVar3 < 0x18; uVar3 = uVar3 + 1) {
              (&stack0xfffffb18)[uVar3] = *(undefined *)((int)&local_b8 + uVar3);
            }
            iVar7 = tisp_s_ae_at_list(local_c8,local_c4,local_c0,local_bc);
          }
        }
      }
    }
  }
  else {
    if (uVar3 == 0x80000e0) {
      iVar10 = *param_1;
      local_18[0] = param_2[1];
      if (local_18[0] == *(uint *)(*(int *)(iVar10 + 0xd8) + 0x130)) {
        return 0;
      }
      iVar7 = -2;
      if (iVar10 != 0) {
        if (*(code **)(iVar10 + 0x80) == (code *)0x0) {
          iVar7 = -0x203;
        }
        else {
          iVar7 = (**(code **)(iVar10 + 0x80))(iVar10,0x200000a,local_18);
          if (iVar7 == 0) {
            param_1[0x1028] = local_18[0];
            tisp_set_fps(local_18[0]);
            return 0;
          }
        }
      }
      goto LAB_00016d2c;
    }
    if (uVar3 < 0x80000e1) {
      if (uVar3 == 0x8000085) {
        if (param_2[1] < 0x100) {
          pcVar6 = tisp_s_3dns_ratio;
LAB_000169dc:
          iVar7 = (*pcVar6)();
          if (-1 < iVar7) {
            return iVar7;
          }
          isp_printf();
          return iVar7;
        }
LAB_00016bd4:
        isp_printf();
        return -1;
      }
      if (uVar3 < 0x8000086) {
        if (uVar3 < 0x8000062) {
          if (0x800005f < uVar3) {
            return 0;
          }
          if (uVar3 == 0x8000042) {
            private_copy_from_user();
            if (local_1e == '\0') {
              local_1e = '\x01';
            }
            if (local_1d < 3) {
              local_1d = 3;
            }
            if ((((local_1c < 0x10) && (local_1b < 0x10)) && (4 < local_1c)) && (4 < local_1b)) {
              local_b4 = CONCAT31(CONCAT21(local_b4._2_2_,local_1b),local_1c);
              local_c0 = CONCAT22(local_26,CONCAT11(local_27,local_28));
              local_bc = CONCAT22(local_22,local_24);
              local_b8 = CONCAT13(local_1d,CONCAT12(local_1e,local_20));
              tisp_s_af_attr(local_c8,local_c4,local_c0,local_bc);
              return 0;
            }
            goto LAB_000168f0;
          }
          if (uVar3 != 0x8000044) {
            return 0xffffffff;
          }
          pcVar6 = apical_isp_af_weight_s_attr_isra_63;
          goto LAB_0001698c;
        }
        if (uVar3 == 0x8000080) {
          private_copy_from_user();
          return 0;
        }
        if (0x8000080 < uVar3) {
          uVar9 = 0x8000084;
          goto LAB_000160e0;
        }
        if (uVar3 != 0x8000062) {
          return 0xffffffff;
        }
        iVar7 = tisp_s_dpc_strength(param_2[1]);
      }
      else {
        if (uVar3 == 0x80000a3) {
          uVar3 = param_2[1];
          pcVar6 = tisp_s_adr_enable;
LAB_00016a60:
          (*pcVar6)(uVar3);
          return 0;
        }
        if (0x80000a3 < uVar3) {
          if (uVar3 == 0x80000a6) {
            private_copy_from_user();
            puVar8 = &local_c8;
            pcVar6 = tisp_set_csc_attr;
            goto LAB_00016d8c;
          }
          if (uVar3 < 0x80000a7) {
            if (uVar3 != 0x80000a4) {
              return 0xffffffff;
            }
            uVar3 = param_2[1];
            pcVar6 = tisp_s_defog_enable;
            goto LAB_00016a60;
          }
          bVar2 = uVar3 + 0xf7ffff40 < 3;
          goto LAB_000160e4;
        }
        if (uVar3 < 0x80000a2) {
          if (0x800009f < uVar3) {
            return 0;
          }
          if (uVar3 != 0x8000086) {
            return 0xffffffff;
          }
          if (param_2[1] < 0x100) {
            pcVar6 = tisp_s_2dns_ratio;
            goto LAB_000169dc;
          }
          goto LAB_00016bd4;
        }
        iVar7 = tisp_s_drc_strength(param_2[1]);
      }
    }
    else {
      if (uVar3 == 0x80000e9) {
        private_copy_from_user();
        tisp_s_scaler_level_control(local_c8,local_c4,local_c0);
        return 0;
      }
      if (uVar3 < 0x80000ea) {
        if (uVar3 != 0x80000e4) {
          if (uVar3 < 0x80000e5) {
            if (uVar3 != 0x80000e2) {
              if (0x80000e2 < uVar3) {
                private_copy_from_user();
                tisp_s_fcrop_control((char)local_c8,local_c4,local_c0,local_bc,local_b8);
                return 0;
              }
              iVar7 = *(int *)(*param_1 + 0xd8);
              if (param_2[1] == param_1[0x1029]) {
                return 0;
              }
              param_1[0x1029] = param_2[1];
              *(undefined4 *)(iVar7 + 0x17c) = 1;
              return 0;
            }
            private_copy_from_user();
            pcVar6 = tisp_s_module_control;
          }
          else {
            if (uVar3 != 0x80000e6) {
              if (uVar3 < 0x80000e6) {
                pcVar6 = apical_isp_mask_s_attr_isra_43;
                goto LAB_0001698c;
              }
              if (uVar3 != 0x80000e7) {
                if (uVar3 == 0x80000e8) {
                  private_copy_from_user();
                  for (uVar3 = 0; uVar3 < 0x14; uVar3 = uVar3 + 1) {
                    (&stack0xfffffb18)[uVar3] = *(undefined *)((int)&local_b8 + uVar3);
                  }
                  tisp_s_autozoom_control
                            (local_c8,local_c4,local_c0,local_bc,in_stack_fffffb18,in_stack_fffffb1c
                             ,in_stack_fffffb20,in_stack_fffffb24,in_stack_fffffb28);
                  return 0;
                }
                return 0xffffffff;
              }
              uVar3 = param_2[1];
              iVar10 = *(int *)(*param_1 + 0xd8);
              iVar7 = tisp_cust_mode_s_ctrl(uVar3);
              if (iVar7 == 0) {
                if (uVar3 == 1) {
                  if ((param_1[0x1029] & 0xfffffffdU) == 0) {
                    iVar7 = 2;
                    *(undefined4 *)(iVar10 + 0x17c) = 2;
                  }
                  else {
                    if ((param_1[0x1029] & 0xfffffffdU) != 1) {
                      return 0;
                    }
                    *(undefined4 *)(iVar10 + 0x17c) = 2;
                    iVar7 = 3;
                  }
                  param_1[0x1029] = iVar7;
                }
                else if (uVar3 == 0) {
                  if ((param_1[0x1029] & 0xfffffffdU) == 0) {
                    uVar5 = 2;
                  }
                  else {
                    if ((param_1[0x1029] & 0xfffffffdU) != 1) {
                      return 0;
                    }
                    uVar5 = 3;
                  }
                  *(undefined4 *)(iVar10 + 0x17c) = uVar5;
                  return 0;
                }
                return 0;
              }
              goto LAB_00016bd4;
            }
            local_c8 = param_2[1];
            pcVar6 = tisp_s_ev_start;
          }
          goto LAB_00016b94;
        }
        uVar4 = param_2[1];
        iVar7 = *(int *)(*param_1 + 0xd8);
        uVar3 = (uVar4 << 0x1e) >> 0x1f;
        param_1[0x3ac] = uVar3;
        *(uint *)(iVar7 + 0x16c) = uVar3;
        param_1[0x3ad] = uVar4 & 1;
        *(uint *)(iVar7 + 0x174) = uVar4 & 1;
        goto LAB_000162ac;
      }
      if (uVar3 == 0x8000161) {
        return 0;
      }
      if (0x8000161 < uVar3) {
        if (uVar3 == 0x8000164) {
          if (param_2[1] == 1) {
            *(undefined4 *)(*(int *)(*param_1 + 0xd8) + 0x160) = 0;
          }
          else {
            *(undefined4 *)(*(int *)(*param_1 + 0xd8) + 0x160) = 1;
          }
          isp_printf();
          return 0;
        }
        if (uVar3 < 0x8000165) {
          uVar9 = 0x8000163;
LAB_000160cc:
          if (uVar3 == uVar9) {
            return 0;
          }
          return -1;
        }
        uVar9 = 0x800016a;
LAB_000160e0:
        bVar2 = uVar3 < uVar9;
LAB_000160e4:
        if (bVar2) {
          return 0;
        }
        return 0xffffffff;
      }
      if (uVar3 == 0x8000101) {
        local_c8 = param_2[1];
        if (local_c8 < 0x100) {
          pcVar6 = tisp_set_bcsh_hue;
          goto LAB_00016b94;
        }
        goto LAB_00016bd4;
      }
      if (0x8000101 < uVar3) {
        uVar9 = 0x8000140;
        if (uVar3 == 0x8000120) {
          return 0;
        }
        goto LAB_000160cc;
      }
      if (uVar3 != 0x8000100) {
        return 0xffffffff;
      }
      private_copy_from_user();
      iVar7 = tisp_s_ccm_attr((undefined *)&local_c8);
    }
  }
  if (iVar7 == 0) {
    return 0;
  }
LAB_00016d2c:
  isp_printf();
  return iVar7;
}



undefined4 apical_isp_mask_g_attr_isra_77(void)

{
  undefined auStack_b8 [176];
  
  tisp_g_mscaler_mask_attr(auStack_b8);
  private_copy_to_user();
  return 0;
}



undefined4 apical_isp_expr_g_ctrl_isra_81(void)

{
  int local_98 [12];
  int local_68;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_1c;
  uint local_18;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  
  tisp_g_ev_attr(local_98);
  local_18 = (uint)(local_68 != 0);
  local_12 = local_2c;
  local_10 = local_2a;
  local_e = local_1c;
  private_copy_to_user();
  return 0;
}



int apical_isp_max_again_g_ctrl_isra_82(int param_1)

{
  int iVar1;
  int aiStack_90 [8];
  undefined4 local_70;
  
  iVar1 = tisp_g_ev_attr(aiStack_90);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = local_70;
  }
  else {
    isp_printf();
  }
  return iVar1;
}



int apical_isp_max_dgain_g_ctrl_isra_83(int param_1)

{
  int iVar1;
  int aiStack_90 [9];
  undefined4 local_6c;
  
  iVar1 = tisp_g_ev_attr(aiStack_90);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = local_6c;
  }
  else {
    isp_printf();
  }
  return iVar1;
}



int apical_isp_ev_g_attr_isra_84(void)

{
  int iVar1;
  int iStack_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = tisp_g_ev_attr(&iStack_a8);
  if (iVar1 == 0) {
    local_28 = local_a4;
    local_1c = local_98;
    local_18 = local_94;
    local_14 = local_90;
    local_24 = local_a0;
    local_20 = local_9c;
    private_copy_to_user();
  }
  else {
    isp_printf();
  }
  return iVar1;
}



int apical_isp_gamma_g_attr_isra_85(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 local_218 [130];
  undefined2 local_114 [130];
  
  iVar1 = tisp_g_Gamma(local_218);
  iVar2 = 0;
  if (iVar1 == 0) {
    do {
      puVar3 = (undefined2 *)((int)local_114 + iVar2);
      puVar4 = (undefined2 *)((int)local_218 + iVar2);
      iVar2 = iVar2 + 2;
      *puVar3 = *puVar4;
    } while (iVar2 != 0x102);
    private_copy_to_user();
  }
  else {
    isp_printf();
  }
  return iVar1;
}



int apical_isp_ae_g_roi_isra_86(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined local_f8 [232];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar3 = -1;
  }
  else {
    iVar3 = tisp_g_aeroi_weight(pvVar2);
    iVar6 = 0;
    if (iVar3 == 0) {
      iVar4 = 0;
      do {
        iVar5 = 0;
        do {
          iVar7 = iVar5 * 4;
          iVar1 = iVar5 + iVar6 * 0xf;
          iVar5 = iVar5 + 1;
          local_f8[iVar1] = (char)*(undefined4 *)((int)pvVar2 + iVar7 + iVar4);
        } while (iVar5 != 0xf);
        iVar6 = iVar6 + 1;
        iVar4 = iVar6 * 0x3c;
      } while (iVar6 != 0xf);
      private_copy_to_user();
    }
    else {
      isp_printf();
    }
    private_kfree();
  }
  return iVar3;
}



undefined4 apical_isp_ae_zone_g_ctrl_isra_92(void)

{
  undefined auStack_390 [904];
  
  tisp_g_ae_zone(auStack_390);
  private_copy_to_user();
  return 0;
}



undefined4 apical_isp_af_zone_g_ctrl_isra_93(void)

{
  undefined auStack_390 [904];
  
  tisp_g_af_zone(auStack_390);
  private_copy_to_user();
  return 0;
}



int apical_isp_ae_zone_weight_g_attr_isra_97(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined local_f8 [232];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar3 = -1;
  }
  else {
    iVar3 = tisp_g_aezone_weight(pvVar2);
    iVar6 = 0;
    if (iVar3 == 0) {
      iVar4 = 0;
      do {
        iVar5 = 0;
        do {
          iVar7 = iVar5 * 4;
          iVar1 = iVar5 + iVar6 * 0xf;
          iVar5 = iVar5 + 1;
          local_f8[iVar1] = (char)*(undefined4 *)((int)pvVar2 + iVar7 + iVar4);
        } while (iVar5 != 0xf);
        iVar6 = iVar6 + 1;
        iVar4 = iVar6 * 0x3c;
      } while (iVar6 != 0xf);
      private_copy_to_user();
    }
    else {
      isp_printf();
    }
    private_kfree();
  }
  return iVar3;
}



undefined4 apical_isp_ae_hist_origin_g_attr_isra_100(void)

{
  void *__src;
  undefined4 uVar1;
  undefined auStack_410 [1028];
  
  __src = (void *)private_kmalloc();
  if (__src == (void *)0x0) {
    isp_printf();
    uVar1 = 0xffffffff;
  }
  else {
    tisp_g_ae_hist(__src);
    memcpy(auStack_410,__src,0x400);
    private_copy_to_user();
    private_kfree();
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 apical_isp_awb_zone_statis_g_attr_isra_102(void)

{
  void *__src;
  undefined4 uVar1;
  undefined auStack_2b8 [684];
  
  __src = (void *)private_vmalloc();
  if (__src == (void *)0x0) {
    isp_printf();
    uVar1 = 0xffffffff;
  }
  else {
    tisp_g_wb_zone(__src);
    memcpy(auStack_2b8,__src,0x2a3);
    private_copy_to_user();
    private_vfree();
    uVar1 = 0;
  }
  return uVar1;
}



int apical_isp_af_weight_g_attr_isra_104(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined local_f8 [232];
  
  pvVar2 = (void *)private_kmalloc();
  if (pvVar2 == (void *)0x0) {
    isp_printf();
    iVar3 = -1;
  }
  else {
    iVar3 = tisp_g_af_weight(pvVar2);
    iVar6 = 0;
    if (iVar3 == 0) {
      iVar4 = 0;
      do {
        iVar5 = 0;
        do {
          iVar7 = iVar5 * 4;
          iVar1 = iVar5 + iVar6 * 0xf;
          iVar5 = iVar5 + 1;
          local_f8[iVar1] = (char)*(undefined4 *)((int)pvVar2 + iVar7 + iVar4);
        } while (iVar5 != 0xf);
        iVar6 = iVar6 + 1;
        iVar4 = iVar6 * 0x3c;
      } while (iVar6 != 0xf);
      private_copy_to_user();
    }
    else {
      isp_printf();
    }
    private_kfree();
  }
  return iVar3;
}



undefined4 tiziano_isp_ae_manual_attr_g_ctrl_isra_111(void)

{
  undefined auStack_a0 [152];
  
  tisp_get_ae_attr(auStack_a0);
  private_copy_to_user();
  return 0;
}



undefined4 tiziano_isp_csc_g_attr_isra_116(void)

{
  undefined4 uVar1;
  undefined4 auStack_50 [17];
  
  uVar1 = tisp_get_csc_attr(auStack_50);
  private_copy_to_user();
  return uVar1;
}



undefined4 isp_frame_done_wait(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_38 [3];
  undefined4 ****local_2c;
  undefined4 ****local_28;
  
  frame_done_cond = 0;
  __might_sleep("/home_a/ywu/t31-4.4/new/Project/isp-t31-kernel-4.4/t31-firmware/tx-isp-core-tuning.c"
                ,0x7be,0);
  if (frame_done_cond == 1) {
    iVar3 = 1;
    if (param_1 != 0) {
      iVar3 = param_1;
    }
  }
  else {
    iVar3 = 0;
    if (param_1 != 0) {
      local_2c = &local_2c;
      local_38[0] = 0;
      local_28 = local_2c;
      while (iVar1 = prepare_to_wait_event(&frame_done_wq,local_38,1), iVar3 = param_1,
            frame_done_cond != 1) {
        if ((param_1 == 0) || (iVar3 = iVar1, iVar1 != 0)) goto LAB_000177ec;
        param_1 = schedule_timeout(param_1);
      }
      if (param_1 == 0) {
        iVar3 = 1;
      }
LAB_000177ec:
      finish_wait(&frame_done_wq,local_38);
    }
  }
  uVar2 = DAT_000b3c9c;
  *param_2 = frame_done_cnt;
  param_2[1] = uVar2;
  if (iVar3 == -0x200) {
    uVar2 = 0xfffffe00;
  }
  else {
    uVar2 = 0xffffff6f;
    if (iVar3 != 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



// WARNING: Type propagation algorithm not settling

int apical_isp_core_ops_g_ctrl(int *param_1,uint *param_2)

{
  uint uVar1;
  code *pcVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int unaff_gp;
  uint local_b0;
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  ushort local_98;
  uint local_94;
  undefined4 local_30;
  undefined4 local_2c;
  undefined local_28;
  undefined local_27;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  uint local_18;
  undefined4 local_14;
  
  uVar1 = *param_2;
  if (uVar1 == 0x8000032) {
    iVar4 = tisp_g_ae_it_max(&local_18);
    local_94 = local_18;
  }
  else if (uVar1 < 0x8000033) {
    if (uVar1 == 0x800000d) {
      tisp_g_wb_ct(&local_18);
      goto LAB_00017d90;
    }
    if (uVar1 < 0x800000e) {
      if (uVar1 < 0x8000002) {
        if (0x7ffffff < uVar1) {
          return 0;
        }
        if (uVar1 == 0x980915) {
          local_18 = param_1[0x3ac];
        }
        else if (uVar1 < 0x980916) {
          if (uVar1 == 0x980901) {
            local_18 = param_1[0x1023];
          }
          else {
            if (uVar1 < 0x980902) {
              if (uVar1 == 0x980900) {
                param_2[1] = param_1[0x1025];
                return 0;
              }
              return -1;
            }
            if (uVar1 != 0x980902) {
              if (uVar1 == 0x980914) {
                param_2[1] = param_1[0x3ad];
                return 0;
              }
              return -1;
            }
            local_18 = param_1[0x1024];
          }
        }
        else if (uVar1 == 0x98091b) {
          local_18 = param_1[0xfdb];
        }
        else {
          if (uVar1 < 0x98091c) {
            if (uVar1 == 0x980918) {
              param_2[1] = param_1[0x3bf];
              return 0;
            }
            return -1;
          }
          if (uVar1 != 0x98091f) {
            if (uVar1 == 0x9a091a) {
              param_2[1] = param_1[0x1026];
              return 0;
            }
            return -1;
          }
          local_18 = param_1[0x1027];
        }
        goto LAB_00017ef0;
      }
      if (uVar1 < 0x8000009) {
        if (0x8000005 < uVar1) {
          return 0;
        }
        if (uVar1 == 0x8000004) {
          iVar4 = tisp_g_wb_attr(&local_b0);
          if (iVar4 == 0) {
            switch(local_b0) {
            case 0:
              local_30 = 0;
              break;
            case 1:
              local_30 = 1;
              break;
            case 2:
              local_30 = 2;
              break;
            case 3:
              local_30 = 3;
              break;
            case 4:
              local_30 = 4;
              break;
            case 5:
              local_30 = 5;
              break;
            case 6:
              local_30 = 6;
              break;
            case 7:
              local_30 = 7;
              break;
            case 8:
              local_30 = 8;
              break;
            case 9:
              local_30 = 9;
              break;
            default:
              isp_printf();
              return -1;
            }
            local_2c = CONCAT22((short)local_a8,(short)local_ac);
            iVar4 = 0;
LAB_00018694:
            private_copy_to_user();
            return iVar4;
          }
          goto LAB_00017e94;
        }
        uVar5 = 0x8000003;
        if (uVar1 < 0x8000005) {
LAB_00017d44:
          if (uVar1 == uVar5) {
            return 0;
          }
          return -1;
        }
        tisp_g_wb_attr(&local_b0);
      }
      else {
        if (uVar1 == 0x800000a) {
          tisp_g_awb_start(&local_b0);
          goto LAB_00017d90;
        }
        if (0x8000009 < uVar1) {
          if (uVar1 != 0x800000b) {
            return -1;
          }
          pcVar2 = apical_isp_awb_zone_statis_g_attr_isra_102;
          goto LAB_000186b8;
        }
        tisp_g_wb_attr(&local_b0);
        local_9c = local_a4;
        local_98 = (ushort)local_a0;
      }
      local_18 = (uint)local_98 + local_9c * 0x10000;
      goto LAB_00017ef0;
    }
    if (uVar1 == 0x8000028) {
      pcVar2 = apical_isp_max_again_g_ctrl_isra_82;
      goto LAB_000186b8;
    }
    if (uVar1 < 0x8000029) {
      if (uVar1 == 0x8000023) {
        pcVar2 = tisp_get_ae_comp;
        goto LAB_00018524;
      }
      if (uVar1 < 0x8000024) {
        if (uVar1 == 0x800000f) {
          iVar4 = tisp_g_awb_ct_trend((int)&local_b0);
          private_copy_to_user();
        }
        else {
          if (0x800000e < uVar1) {
            uVar5 = 0x8000020;
            goto LAB_00017c30;
          }
          iVar4 = tisp_g_awb_cluster(&local_b0);
          private_copy_to_user();
        }
        goto joined_r0x000185ec;
      }
      if (uVar1 == 0x8000025) {
        pcVar2 = apical_isp_expr_g_ctrl_isra_81;
        goto LAB_000186b8;
      }
      if (uVar1 < 0x8000025) {
        pcVar2 = apical_isp_ae_g_roi_isra_86;
        goto LAB_000186b8;
      }
      if (uVar1 == 0x8000026) {
        pcVar2 = apical_isp_ev_g_attr_isra_84;
        goto LAB_000186b8;
      }
      if (uVar1 != 0x8000027) {
        return -1;
      }
      iVar4 = tisp_g_ev_attr((int *)&local_b0);
    }
    else {
      if (uVar1 == 0x800002d) {
        pcVar2 = apical_isp_ae_zone_weight_g_attr_isra_97;
LAB_000186b8:
        iVar4 = (*pcVar2)(param_2);
        return iVar4;
      }
      if (0x800002d < uVar1) {
        if (uVar1 == 0x800002f) {
          iVar4 = tisp_g_ae_min(&local_b0);
          if (iVar4 != 0) {
            return iVar4;
          }
          goto LAB_00018694;
        }
        if (uVar1 < 0x800002f) {
          pvVar3 = (void *)private_kmalloc();
          if (pvVar3 != (void *)0x0) {
            tisp_g_ae_hist(pvVar3);
            local_b0 = CONCAT13((char)*(undefined4 *)((int)pvVar3 + 0x420),
                                CONCAT12((char)*(undefined4 *)((int)pvVar3 + 0x41c),
                                         CONCAT11((char)*(undefined4 *)((int)pvVar3 + 0x418),
                                                  (char)*(undefined4 *)((int)pvVar3 + 0x414))));
            local_ac = CONCAT22((short)*(undefined4 *)((int)pvVar3 + 0x404),
                                (short)*(undefined4 *)((int)pvVar3 + 0x400));
            local_a8 = CONCAT22((short)*(undefined4 *)((int)pvVar3 + 0x40c),
                                (short)*(undefined4 *)((int)pvVar3 + 0x408));
            local_a4 = CONCAT13((char)*(undefined4 *)((int)pvVar3 + 0x428),
                                CONCAT12((char)*(undefined4 *)((int)pvVar3 + 0x424),
                                         (short)*(undefined4 *)((int)pvVar3 + 0x410)));
            private_copy_to_user();
            private_kfree();
            return 0;
          }
          goto LAB_00018564;
        }
        if (uVar1 == 0x8000030) {
          pcVar2 = apical_isp_ae_zone_g_ctrl_isra_92;
        }
        else {
          if (uVar1 != 0x8000031) {
            return -1;
          }
          pcVar2 = apical_isp_ae_hist_origin_g_attr_isra_100;
        }
        goto LAB_000186b8;
      }
      if (uVar1 != 0x800002a) {
        if (uVar1 < 0x800002a) {
          pcVar2 = apical_isp_max_dgain_g_ctrl_isra_83;
        }
        else {
          uVar5 = 0x800002c;
          if (uVar1 != 0x800002b) goto LAB_00017d44;
          pcVar2 = apical_isp_gamma_g_attr_isra_85;
        }
        goto LAB_000186b8;
      }
      iVar4 = tisp_g_Hilightdepress((int *)&local_18);
      local_94 = local_18;
    }
  }
  else if (uVar1 == 0x80000a2) {
    iVar4 = tisp_g_drc_strength(&local_18);
    local_94 = local_18;
  }
  else {
    if (0x80000a2 < uVar1) {
      if (uVar1 == 0x80000e5) {
        pcVar2 = apical_isp_mask_g_attr_isra_77;
        goto LAB_000186b8;
      }
      if (0x80000e5 < uVar1) {
        if (0x8000161 < uVar1) {
          if (uVar1 != 0x8000167) {
            if (uVar1 == 0x8000169) {
              return 0;
            }
            if (uVar1 == 0x8000162) {
              uVar1 = param_2[1];
              local_18 = 0;
              local_14 = 0;
              if (((uVar1 + 0x18 | uVar1) & *(uint *)(unaff_gp + 0x18)) == 0) {
                __might_fault("/home_a/ywu/t31-4.4/new/Project/isp-t31-kernel-4.4/t31-firmware/tx-isp-core-tuning.c"
                              ,0x7d7);
                __copy_user(&local_b0,uVar1,0x18);
              }
              else {
                memset(&local_b0,0,0x18);
              }
              iVar4 = isp_frame_done_wait(local_b0,&local_18);
              uVar1 = param_2[1];
              local_a8 = local_18;
              local_a4 = local_14;
              if (((uVar1 + 0x18 | uVar1) & *(uint *)(unaff_gp + 0x18)) == 0) {
                __might_fault("/home_a/ywu/t31-4.4/new/Project/isp-t31-kernel-4.4/t31-firmware/tx-isp-core-tuning.c"
                              ,0x7dd);
                __copy_user(uVar1,&local_b0,0x18);
                return iVar4;
              }
              return iVar4;
            }
            return -1;
          }
          local_18 = param_1[0x3b1];
          goto LAB_00017ef0;
        }
        if (0x800015f < uVar1) {
          return 0;
        }
        if (uVar1 == 0x8000100) {
          tisp_g_ccm_attr(&local_b0);
          goto LAB_00017d90;
        }
        if (uVar1 < 0x8000101) {
          if (uVar1 != 0x80000e7) {
            return -1;
          }
          uVar1 = tisp_cust_mode_g_ctrl();
          if (-1 < (int)uVar1) {
            param_2[1] = uVar1;
            return 0;
          }
LAB_00018564:
          isp_printf();
          return -1;
        }
        if (uVar1 != 0x8000101) {
          uVar5 = 0x8000120;
          goto LAB_00017d44;
        }
        pcVar2 = tisp_get_bcsh_hue;
LAB_00018524:
        (*pcVar2)(&local_18);
        local_18 = local_18 & 0xff;
LAB_00017ef0:
        param_2[1] = local_18;
        return 0;
      }
      if (uVar1 == 0x80000e0) {
        local_18 = *(uint *)(*(int *)(*param_1 + 0xd8) + 0x130);
        goto LAB_00017ef0;
      }
      if (0x80000e0 < uVar1) {
        if (uVar1 != 0x80000e2) {
          if (uVar1 < 0x80000e2) {
            local_18 = param_1[0x1029] & 1;
          }
          else {
            if (uVar1 == 0x80000e3) {
              tisp_g_fcrop_control((undefined *)&local_b0);
              goto LAB_00017d90;
            }
            if (uVar1 != 0x80000e4) {
              return -1;
            }
            local_18 = 2;
            if (*(int *)(*(int *)(*param_1 + 0xd8) + 0x16c) == 0) {
              local_18 = 0;
            }
            local_18 = local_18 | *(int *)(*(int *)(*param_1 + 0xd8) + 0x174) != 0;
          }
          goto LAB_00017ef0;
        }
        tisp_g_module_control(&local_b0);
        goto LAB_00017d90;
      }
      if (uVar1 == 0x80000a6) {
        pcVar2 = tiziano_isp_csc_g_attr_isra_116;
        goto LAB_000186b8;
      }
      if (0x80000a6 < uVar1) {
        if (uVar1 + 0xf7ffff40 < 3) {
          return 0;
        }
        return -1;
      }
      if (uVar1 != 0x80000a5) {
        return -1;
      }
      pcVar2 = tisp_get_blc_attr;
LAB_00018668:
      (*pcVar2)(&local_b0);
LAB_00017d90:
      private_copy_to_user();
      return 0;
    }
    if (uVar1 == 0x8000043) {
      iVar4 = tisp_g_af_metric(&local_18);
      if (iVar4 != 0) {
        isp_printf();
        return 0;
      }
      goto LAB_00017ef0;
    }
    if (uVar1 < 0x8000044) {
      if (uVar1 == 0x8000038) {
        iVar4 = tisp_g_ae_at_list((int)&local_b0);
        private_copy_to_user();
joined_r0x000185ec:
        if (iVar4 == 0) {
          return 0;
        }
        goto LAB_00017e94;
      }
      if (0x8000038 < uVar1) {
        if (uVar1 < 0x8000042) {
          if (0x800003f < uVar1) {
            return 0;
          }
          if (uVar1 != 0x8000039) {
            return -1;
          }
          iVar4 = tisp_get_defog_strength((undefined *)&local_18);
          goto LAB_00018694;
        }
        tisp_g_af_attr(&local_b0);
        local_28 = (undefined)local_a8;
        local_27 = local_a8._1_1_;
        local_26 = local_a8._2_2_;
        local_24 = (undefined2)local_a4;
        local_22 = local_a4._2_2_;
        local_20 = (ushort)local_a0;
        local_1e = local_a0._2_1_;
        local_1d = local_a0._3_1_;
        local_1c = (undefined)local_9c;
        local_1b = local_9c._1_1_;
        goto LAB_00017d90;
      }
      if (uVar1 == 0x8000035) {
        pcVar2 = tiziano_isp_ae_manual_attr_g_ctrl_isra_111;
        goto LAB_000186b8;
      }
      if (uVar1 < 0x8000036) {
        if (uVar1 != 0x8000033) {
          return -1;
        }
        pcVar2 = tisp_get_ae_luma;
        goto LAB_00018524;
      }
      if (uVar1 == 0x8000036) {
        tisp_get_ae_state((int)&local_b0);
        goto LAB_00017d90;
      }
      if (uVar1 != 0x8000037) {
        return -1;
      }
      iVar4 = tisp_g_BacklightComp((int *)&local_18);
      local_94 = local_18;
    }
    else {
      if (0x8000083 < uVar1) {
        uVar5 = 0x80000a0;
        if (uVar1 != 0x8000084) {
LAB_00017c30:
          if (uVar5 <= uVar1) {
            return 0;
          }
          return -1;
        }
        pcVar2 = tisp_g_ncuinfo;
        goto LAB_00018668;
      }
      if (0x8000081 < uVar1) {
        return 0;
      }
      if (uVar1 == 0x8000045) {
        iVar4 = *(int *)(*param_1 + 0xd8);
        local_b0 = (uint)*(ushort *)(*(int *)(iVar4 + 0x124) + 0xb0);
        local_ac = (uint)*(ushort *)(*(int *)(iVar4 + 0x124) + 0xb2);
        local_a8 = *(undefined4 *)(iVar4 + 0x130);
        local_a4 = *(int *)(iVar4 + 0x128);
        local_a0 = *(undefined4 *)(iVar4 + 300);
        goto LAB_00017d90;
      }
      if (uVar1 < 0x8000045) {
        pcVar2 = apical_isp_af_weight_g_attr_isra_104;
        goto LAB_000186b8;
      }
      if (uVar1 == 0x8000046) {
        pcVar2 = apical_isp_af_zone_g_ctrl_isra_93;
        goto LAB_000186b8;
      }
      if (uVar1 != 0x8000062) {
        return -1;
      }
      iVar4 = tisp_g_dpc_strength(&local_18);
      local_94 = local_18;
    }
  }
  if (iVar4 == 0) {
    param_2[1] = local_94;
    return 0;
  }
LAB_00017e94:
  isp_printf();
  return iVar4;
}



int isp_core_tunning_unlocked_ioctl(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint local_20;
  uint auStack_1c [4];
  
  piVar4 = *(int **)(*(int *)(*(int *)(param_1 + 0x78) + 0xcc) + 0x1c0);
  if (piVar4[0x1031] != 3) {
    return -1;
  }
  if (param_2 == -0x3ff7a9e5) {
    iVar1 = private_copy_from_user();
    if (iVar1 != 0) {
      return -0xe;
    }
    iVar1 = apical_isp_core_ops_g_ctrl(piVar4,&local_20);
    if ((iVar1 != 0) && (iVar1 != -0x203)) {
      return iVar1;
    }
    iVar2 = private_copy_to_user();
    if (iVar2 != 0) {
      return -0xe;
    }
    goto LAB_00018840;
  }
  if (param_2 == -0x3ff7a9e4) {
    iVar1 = private_copy_from_user();
    puVar3 = &local_20;
    if (iVar1 != 0) {
      return -0xe;
    }
  }
  else {
    iVar1 = private_copy_from_user();
    if (iVar1 != 0) {
      iVar1 = -0xe;
      goto LAB_00018840;
    }
    puVar3 = auStack_1c;
    if (local_20 != 0) {
      iVar1 = apical_isp_core_ops_g_ctrl(piVar4,puVar3);
      if (((iVar1 == 0) || (iVar1 == -0x203)) && (iVar2 = private_copy_to_user(), iVar2 != 0)) {
        iVar1 = -0xe;
      }
      goto LAB_00018840;
    }
  }
  iVar1 = apical_isp_core_ops_s_ctrl(piVar4,puVar3);
LAB_00018840:
  if (iVar1 == -0x203) {
    iVar1 = 0;
  }
  return iVar1;
}



void isp_frame_done_wakeup(void)

{
  DAT_000b3c9c = (uint)(frame_done_cnt + 1 < frame_done_cnt) + DAT_000b3c9c;
  frame_done_cond = 1;
  frame_done_cnt = frame_done_cnt + 1;
  __wake_up(&frame_done_wq,3,1,0);
  return;
}



undefined4 isp_core_tuning_event(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 != 0x4000001) {
    if (param_2 < 0x4000002) {
      if (param_2 == 0x4000000) {
        *(undefined4 *)(param_1 + 0x40c4) = 2;
      }
    }
    else if (param_2 == 0x4000002) {
      isp_frame_done_wakeup();
    }
    else if (param_2 == 0x4000003) {
      iVar1 = *(int *)(param_1 + 0x40a4);
      tisp_day_or_night_s_ctrl(iVar1);
      *(int *)(param_1 + 0x40a4) = iVar1;
    }
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40c4) = 1;
  return 0;
}



undefined4 * isp_core_tuning_init(undefined4 param_1)

{
  undefined4 *__s;
  
  __s = (undefined4 *)private_kmalloc();
  if (__s == (undefined4 *)0x0) {
    isp_printf();
  }
  else {
    memset(__s,0,0x40d0);
    *__s = param_1;
    private_spin_lock_init();
    private_raw_mutex_init();
    __s[0x1031] = 1;
    __s[0x1032] = isp_core_tunning_fops;
    __s[0x1033] = isp_core_tuning_event;
  }
  return __s;
}



void isp_core_tuning_deinit(int param_1)

{
  if (param_1 != 0) {
    private_kfree();
    return;
  }
  return;
}



uint private_math_exp2(uint param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = param_2 & 0xff;
  uVar3 = (1 << (param_2 & 0x1f)) - 1U & param_1;
  uVar6 = param_1 >> (param_2 & 0x1f);
  if (uVar4 < 6) {
    uVar6 = (0x1e - uVar6) - (param_3 & 0xff);
    uVar3 = *(uint *)(__pow2_lut + (uVar3 << (5 - uVar4 & 0x1f)) * 4);
  }
  else {
    uVar5 = uVar3 >> (uVar4 - 5 & 0x1f);
    iVar7 = *(int *)(__pow2_lut + uVar5 * 4);
    lVar1 = (ulonglong)(uint)(*(int *)(__pow2_lut + (uVar5 + 1) * 4) - iVar7) *
            (ulonglong)((1 << (uVar4 - 5 & 0x1f)) - 1U & uVar3);
    iVar2 = __lshrdi3((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    uVar3 = iVar7 + iVar2;
    uVar6 = (0x1e - uVar6) - (param_3 & 0xff);
  }
  return uVar3 >> (uVar6 & 0x1f);
}



char private_leading_one_position(uint param_1)

{
  char cVar1;
  
  if (param_1 < 0x10000) {
    cVar1 = '\0';
  }
  else {
    param_1 = param_1 >> 0x10;
    cVar1 = '\x10';
  }
  if (0xff < param_1) {
    cVar1 = cVar1 + '\b';
    param_1 = param_1 >> 8;
  }
  if (0xf < param_1) {
    cVar1 = cVar1 + '\x04';
    param_1 = param_1 >> 4;
  }
  if (3 < param_1) {
    cVar1 = cVar1 + '\x02';
    param_1 = param_1 >> 2;
  }
  if (1 < param_1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}



uint private_log2_int_to_fixed(uint param_1,uint param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int extraout_v0;
  
  uVar2 = 0;
  if (param_1 != 0) {
    cVar1 = private_leading_one_position(param_1);
    extraout_v0 = CONCAT31(extraout_var,cVar1);
    if (extraout_v0 < 0x10) {
      uVar2 = param_1 << (0xfU - extraout_v0 & 0x1f);
    }
    else {
      uVar2 = param_1 >> (extraout_v0 - 0xfU & 0x1f);
    }
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < (int)(param_2 & 0xff); iVar4 = iVar4 + 1) {
      uVar2 = uVar2 * uVar2;
      iVar3 = iVar3 * 2;
      if ((int)uVar2 < 0) {
        iVar3 = iVar3 + 1;
        uVar2 = uVar2 >> 0x10;
      }
      else {
        uVar2 = uVar2 >> 0xf;
      }
    }
    uVar2 = (uVar2 & 0x7fff) >> (0xf - (param_3 & 0xff) & 0x1f) |
            iVar3 + (extraout_v0 << (param_2 & 0x1f)) << (param_3 & 0x1f);
  }
  return uVar2;
}



int private_log2_fixed_to_fixed(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = private_log2_int_to_fixed(param_1,param_3 & 0xff,0);
  return uVar1 - (param_2 << (param_3 & 0x1f));
}



int private_leading_one_position_64(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = param_2;
  if (param_2 != 0) {
    iVar1 = 0x20;
    uVar2 = 0;
    param_1 = param_2;
  }
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    uVar2 = 0;
    iVar1 = iVar1 + 0x10;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    uVar2 = 0;
    iVar1 = iVar1 + 8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    uVar2 = 0;
    iVar1 = iVar1 + 4;
  }
  if (3 < param_1) {
    param_1 = uVar2 << 0x1e | param_1 >> 2;
    iVar1 = iVar1 + 2;
    if (uVar2 >> 2 != 0) goto LAB_00018d58;
  }
  if (param_1 < 2) {
    return iVar1;
  }
LAB_00018d58:
  return iVar1 + 1;
}



uint private_log2_int_to_fixed_64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar2 = 0;
  if ((param_1 | param_2) != 0) {
    iVar3 = private_leading_one_position_64(param_1,param_2);
    if (iVar3 < 0x10) {
      iVar6 = 0xf - iVar3;
      pcVar4 = __ashldi3;
    }
    else {
      iVar6 = iVar3 + -0xf;
      pcVar4 = __lshrdi3;
    }
    uVar7 = 0;
    uVar10 = (*pcVar4)(param_1,param_2,iVar6);
    uVar8 = 0;
    for (iVar6 = 0; iVar6 < (int)(param_3 & 0xff); iVar6 = iVar6 + 1) {
      uVar5 = uVar7 >> 0x1f;
      lVar1 = (uVar10 & 0xffffffff) * (uVar10 & 0xffffffff);
      uVar9 = (uint)lVar1;
      uVar2 = (int)(uVar10 >> 0x20) * (uint)uVar10 * 2 + (int)((ulonglong)lVar1 >> 0x20);
      uVar7 = uVar7 * 2;
      if ((uVar9 & 0x80000000 | uVar2) == 0) {
        uVar9 = uVar2 * 0x20000 | uVar9 >> 0xf;
        uVar8 = uVar5 | uVar8 << 1;
        uVar2 = uVar2 >> 0xf;
      }
      else {
        uVar8 = (uint)(uVar7 + 1 < uVar7) + (uVar5 | uVar8 << 1);
        uVar9 = uVar2 * 0x10000 | uVar9 >> 0x10;
        uVar2 = uVar2 >> 0x10;
        uVar7 = uVar7 + 1;
      }
      uVar10 = CONCAT44(uVar2,uVar9);
    }
    uVar2 = __lshrdi3((uint)uVar10 & 0x7fff,0,0xf - (param_4 & 0xff));
    iVar3 = iVar3 << (param_3 & 0x1f);
    uVar5 = uVar7 + iVar3;
    uVar7 = __ashldi3(uVar5,(uint)(uVar5 < uVar7) + uVar8 + (iVar3 >> 0x1f),param_4 & 0xff);
    uVar2 = uVar2 | uVar7;
  }
  return uVar2;
}



int private_log2_fixed_to_fixed_64(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = private_log2_int_to_fixed_64(param_1,param_2,param_4 & 0xff,0);
  return uVar1 - (param_3 << (param_4 & 0x1f));
}



undefined * find_new_buffer(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((&DAT_000b3cad)[iVar2] == '\0') {
      memset(&DAT_000b3cac + iVar2,0,0x14);
      (&DAT_000b3cad)[iVar2] = 1;
      return &DAT_000b3cac + iVar2;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar1 * 0x14;
  } while (iVar1 != 0x14);
  return (undefined *)0x0;
}



void isp_mem_init(void)

{
  undefined4 uVar1;
  
  memset(&ispmem,0,0x1ac);
  private_get_isp_priv_mem();
  private_raw_mutex_init();
  DAT_000b3e3c = find_new_buffer();
  *DAT_000b3e3c = 0;
  uVar1 = ispmem;
  *(undefined4 *)(DAT_000b3e3c + 4) = 0;
  *(undefined4 *)(DAT_000b3e3c + 8) = 0;
  *(undefined4 *)(DAT_000b3e3c + 0xc) = uVar1;
  *(undefined4 *)(DAT_000b3e3c + 0x10) = DAT_000b3ca4;
  return;
}



undefined4 isp_malloc_buffer(int param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  
  if (ispmem == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar5 = param_1 + 0xfffU & 0xfffff000;
      private_mutex_lock();
      pcVar4 = DAT_000b3e3c;
      while (pcVar4 != (char *)0x0) {
        if (*pcVar4 == '\0') {
          if (uVar5 <= *(uint *)(pcVar4 + 0x10)) {
            if (uVar5 < *(uint *)(pcVar4 + 0x10)) {
              puVar2 = find_new_buffer();
              if (puVar2 == (undefined *)0x0) {
                private_mutex_unlock();
                return 0;
              }
              *(uint *)(puVar2 + 0xc) = uVar5 + *(int *)(pcVar4 + 0xc);
              iVar3 = *(int *)(pcVar4 + 0x10);
              *(char **)(puVar2 + 4) = pcVar4;
              *(uint *)(puVar2 + 0x10) = iVar3 - uVar5;
              if (*(int *)(pcVar4 + 8) != 0) {
                *(undefined **)(*(int *)(pcVar4 + 8) + 4) = puVar2;
              }
              *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(pcVar4 + 8);
              *(undefined **)(pcVar4 + 8) = puVar2;
            }
            *(uint *)(pcVar4 + 0x10) = uVar5;
            *pcVar4 = '\x01';
            break;
          }
          pcVar4 = *(char **)(pcVar4 + 8);
        }
        else {
          pcVar4 = *(char **)(pcVar4 + 8);
        }
      }
      private_mutex_unlock();
      uVar1 = 0;
      if (pcVar4 != (char *)0x0) {
        uVar1 = *(undefined4 *)(pcVar4 + 0xc);
      }
    }
  }
  return uVar1;
}



void isp_free_buffer(int param_1)

{
  char *pcVar1;
  char *__s;
  
  private_mutex_lock();
  pcVar1 = DAT_000b3e3c;
LAB_000191f0:
  do {
    __s = DAT_000b3e3c;
    if (pcVar1 == (char *)0x0) {
LAB_0001927c:
      while (pcVar1 = __s, pcVar1 != (char *)0x0) {
        __s = *(char **)(pcVar1 + 8);
        if ((((*pcVar1 == '\0') && (__s != (char *)0x0)) && (*__s == '\0')) &&
           (*(int *)(pcVar1 + 0x10) + *(int *)(pcVar1 + 0xc) == *(int *)(__s + 0xc))) {
          *(int *)(pcVar1 + 0x10) = *(int *)(__s + 0x10) + *(int *)(pcVar1 + 0x10);
          *(undefined4 *)(pcVar1 + 8) = *(undefined4 *)(__s + 8);
          if (*(int *)(__s + 8) != 0) {
            *(char **)(*(int *)(__s + 8) + 4) = pcVar1;
          }
          memset(__s,0,0x14);
          __s[1] = '\0';
          __s = pcVar1;
        }
      }
      private_mutex_unlock();
      return;
    }
    if (*pcVar1 != '\0') {
      if (*(int *)(pcVar1 + 0xc) == param_1) {
        *pcVar1 = '\0';
        __s = DAT_000b3e3c;
        goto LAB_0001927c;
      }
      pcVar1 = *(char **)(pcVar1 + 8);
      goto LAB_000191f0;
    }
    pcVar1 = *(char **)(pcVar1 + 8);
  } while( true );
}



undefined4 isp_printf(void)

{
  return 0;
}



undefined4 get_isp_clk(void)

{
  return 0;
}



undefined4 private_vmalloc(void)

{
  return 0;
}



void private_vfree(void)

{
  return;
}



void private_ktime_set(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



void private_set_current_state(void)

{
  return;
}



undefined4 private_schedule_hrtimeout(void)

{
  return 0;
}



undefined4 private_schedule_work(void)

{
  return 0;
}



void private_do_gettimeofday(void)

{
  return;
}



void private_dma_sync_single_for_device(void)

{
  return;
}



void private_init_completion(void)

{
  return;
}



void private_complete(void)

{
  return;
}



undefined4 private_wait_for_completion_interruptible(void)

{
  return 0;
}



undefined4 private_wait_for_completion_timeout(void)

{
  return 0;
}



undefined4 private_wait_event_interruptible(void)

{
  return 0;
}



void private_wake_up_all(void)

{
  return;
}



void private_wake_up(void)

{
  return;
}



void private_init_waitqueue_head(void)

{
  return;
}



void private_enable_irq(void)

{
  return;
}



void private_disable_irq(void)

{
  return;
}



void private_free_irq(void)

{
  return;
}



undefined4 private_filp_open(void)

{
  return 0;
}



undefined4 private_filp_close(void)

{
  return 0;
}



undefined4 private_vfs_read(void)

{
  return 0;
}



undefined4 private_vfs_write(void)

{
  return 0;
}



undefined8 private_vfs_llseek(void)

{
  return 0;
}



undefined4 * private_get_fs(undefined4 *param_1)

{
  undefined4 local_10 [2];
  
  memset(local_10,0,4);
  *param_1 = local_10[0];
  return param_1;
}



void private_set_fs(void)

{
  return;
}



void private_dma_cache_sync(void)

{
  return;
}



void private_getrawmonotonic(void)

{
  return;
}



undefined4 private_get_init_net(void)

{
  return 0;
}



undefined4 private_platform_driver_register(void)

{
  return 0;
}



void private_platform_driver_unregister(void)

{
  return;
}



void private_platform_set_drvdata(void)

{
  return;
}



undefined4 private_platform_get_drvdata(void)

{
  return 0;
}



undefined4 private_platform_device_register(void)

{
  return 0;
}



void private_platform_device_unregister(void)

{
  return;
}



undefined4 private_platform_get_resource(void)

{
  return 0;
}



void private_dev_set_drvdata(void)

{
  return;
}



undefined4 private_dev_get_drvdata(void)

{
  return 0;
}



undefined4 private_platform_get_irq(void)

{
  return 0;
}



undefined4 private_request_mem_region(void)

{
  return 0;
}



void private_release_mem_region(void)

{
  return;
}



undefined4 private_ioremap(void)

{
  return 0;
}



void private_iounmap(void)

{
  return;
}



undefined4 private_request_threaded_irq(void)

{
  return 0;
}



void __private_spin_lock_irqsave(void)

{
  return;
}



void private_spin_unlock_irqrestore(void)

{
  return;
}



void private_spin_lock_init(void)

{
  return;
}



void private_mutex_lock(void)

{
  return;
}



void private_mutex_unlock(void)

{
  return;
}



void private_raw_mutex_init(void)

{
  return;
}



undefined4 private_clk_get(void)

{
  return 0;
}



undefined4 private_clk_enable(void)

{
  return 0;
}



void private_clk_disable(void)

{
  return;
}



undefined4 private_clk_get_rate(void)

{
  return 0;
}



void private_clk_put(void)

{
  return;
}



undefined4 private_clk_set_rate(void)

{
  return 0;
}



undefined4 private_devm_clk_get(void)

{
  return 0;
}



undefined4 private_clk_prepare_enable(void)

{
  return 0;
}



void private_clk_disable_unprepare(void)

{
  return;
}



void private_devm_clk_put(void)

{
  return;
}



undefined4 private_i2c_get_adapter(void)

{
  return 0;
}



void private_i2c_put_adapter(void)

{
  return;
}



undefined4 private_i2c_new_device(void)

{
  return 0;
}



void private_i2c_set_clientdata(void)

{
  return;
}



undefined4 private_i2c_get_clientdata(void)

{
  return 0;
}



undefined4 private_i2c_add_driver(void)

{
  return 0;
}



void private_i2c_unregister_device(void)

{
  return;
}



undefined4 private_gpio_request(void)

{
  return 0;
}



void private_gpio_free(void)

{
  return;
}



undefined4 private_gpio_direction_output(void)

{
  return 0;
}



undefined4 private_gpio_direction_input(void)

{
  return 0;
}



undefined4 private_gpio_set_debounce(void)

{
  return 0;
}



undefined4 private_jzgpio_set_func(void)

{
  return 0;
}



void private_msleep(void)

{
  return;
}



undefined4 private_capable(void)

{
  return 0;
}



undefined8 private_sched_clock(void)

{
  return 0;
}



undefined4 private_try_module_get(void)

{
  return 0;
}



undefined4 private_request_module(void)

{
  return 0;
}



void private_module_put(void)

{
  return;
}



undefined4 private_misc_register(void)

{
  return 0;
}



void private_misc_deregister(void)

{
  return;
}



undefined4 private_proc_create_data(void)

{
  return 0;
}



undefined4 private_seq_read(void)

{
  return 0;
}



undefined8 private_seq_lseek(void)

{
  return 0;
}



undefined4 private_single_release(void)

{
  return 0;
}



undefined4 private_single_open_size(void)

{
  return 0;
}



undefined4 private_jz_proc_mkdir(void)

{
  return 0;
}



void private_proc_remove(void)

{
  return;
}



void private_seq_printf(void)

{
  return;
}



undefined8 private_simple_strtoull(void)

{
  return 0;
}



undefined4 private_kthread_should_stop(void)

{
  return 0;
}



undefined4 private_kthread_run(void)

{
  return 0;
}



undefined4 private_kthread_stop(void)

{
  return 0;
}



undefined4 private_kmalloc(void)

{
  return 0;
}



void private_kfree(void)

{
  return;
}



undefined4 private_copy_from_user(void)

{
  return 0;
}



undefined4 private_copy_to_user(void)

{
  return 0;
}



void private_get_isp_priv_mem(void)

{
  return;
}



undefined4 isp_irq_handle(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 + -0x84 == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 1;
    if ((**(int **)(param_2 + 0x44) != 0) &&
       (pcVar1 = *(code **)(**(int **)(param_2 + 0x44) + 0x20), pcVar1 != (code *)0x0)) {
      iVar2 = (*pcVar1)(param_2 + -0x84,0,0);
      uVar3 = 1;
      if (iVar2 == 2) {
        uVar3 = 2;
      }
    }
  }
  iVar4 = 0;
  iVar2 = param_2 + -0x84;
  do {
    iVar2 = *(int *)(iVar2 + 0x3c);
    if ((((iVar2 != 0) && (**(int **)(iVar2 + 200) != 0)) &&
        (pcVar1 = *(code **)(**(int **)(iVar2 + 200) + 0x20), pcVar1 != (code *)0x0)) &&
       (iVar2 = (*pcVar1)(iVar2,0,0), iVar2 == 2)) {
      uVar3 = 2;
    }
    iVar4 = iVar4 + 4;
    iVar2 = param_2 + -0x84 + iVar4;
  } while (iVar4 != 0x40);
  return uVar3;
}



undefined4 isp_irq_thread_handle(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if (((param_2 + -0x84 != 0) && (**(int **)(param_2 + 0x44) != 0)) &&
     (pcVar1 = *(code **)(**(int **)(param_2 + 0x44) + 0x24), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_2 + -0x84,0);
  }
  iVar3 = 0;
  iVar2 = param_2 + -0x84;
  do {
    iVar2 = *(int *)(iVar2 + 0x3c);
    if (((iVar2 != 0) && (**(int **)(iVar2 + 200) != 0)) &&
       (pcVar1 = *(code **)(**(int **)(iVar2 + 200) + 0x24), pcVar1 != (code *)0x0)) {
      (*pcVar1)(iVar2,0);
    }
    iVar3 = iVar3 + 4;
    iVar2 = param_2 + -0x84 + iVar3;
  } while (iVar3 != 0x40);
  return 1;
}



void tx_isp_disable_irq(void)

{
  private_disable_irq();
  return;
}



void tx_isp_enable_irq(void)

{
  private_enable_irq();
  return;
}



undefined4 tx_isp_request_irq(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    isp_printf();
    uVar3 = 0xffffffea;
  }
  else {
    iVar1 = private_platform_get_irq();
    if (iVar1 < 0) {
      *param_2 = 0;
      uVar3 = 0;
    }
    else {
      private_spin_lock_init();
      iVar2 = private_request_threaded_irq();
      if (iVar2 == 0) {
        param_2[1] = (int)tx_isp_enable_irq;
        *param_2 = iVar1;
        param_2[2] = (int)tx_isp_disable_irq;
        tx_isp_disable_irq();
        uVar3 = 0;
      }
      else {
        isp_printf();
        uVar3 = 0xfffffffc;
        *param_2 = 0;
      }
    }
  }
  return uVar3;
}



void tx_isp_free_irq(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      *param_1 = 0;
    }
    else {
      private_free_irq();
      *param_1 = 0;
    }
  }
  return;
}



undefined4 check_state(int param_1)

{
  if ((param_1 != 0) &&
     ((*(int *)(param_1 + 0x1f8) != param_1 + 0x1f8 || ((*(uint *)(param_1 + 0x20c) & 1) == 0)))) {
    return 1;
  }
  return 0;
}



void __vb2_queue_free(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(int *)(param_1 + 0x1e8) - param_2;
  iVar4 = uVar1 * 4;
  iVar2 = 0;
  while( true ) {
    iVar3 = param_1 + iVar4 + iVar2;
    if (*(uint *)(param_1 + 0x1e8) <= uVar1) break;
    uVar1 = uVar1 + 1;
    private_kfree();
    iVar2 = iVar2 + 4;
    *(undefined4 *)(iVar3 + 0xe8) = 0;
  }
  *(int *)(param_1 + 0x1ec) = param_1 + 0x1ec;
  *(int *)(param_1 + 0x1f0) = param_1 + 0x1ec;
  *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) - param_2;
  __private_spin_lock_irqsave();
  *(int *)(param_1 + 0x1f8) = param_1 + 0x1f8;
  *(int *)(param_1 + 0x1fc) = param_1 + 0x1f8;
  private_spin_unlock_irqrestore();
  tx_isp_send_event_to_remote(*(int *)(param_1 + 0x288));
  return;
}



void __vb2_queue_cancel(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0 && param_1 < 0xfffff001) {
    if ((*(uint *)(param_1 + 0x20c) & 1) != 0) {
      tx_isp_send_event_to_remote(*(int *)(param_1 + 0x288));
    }
    *(byte *)(param_1 + 0x20c) = *(byte *)(param_1 + 0x20c) & 0xfe;
    *(uint *)(param_1 + 0x1ec) = param_1 + 0x1ec;
    *(uint *)(param_1 + 0x1f0) = param_1 + 0x1ec;
    __private_spin_lock_irqsave();
    *(uint *)(param_1 + 0x1f8) = param_1 + 0x1f8;
    *(uint *)(param_1 + 0x1fc) = param_1 + 0x1f8;
    *(undefined4 *)(param_1 + 500) = 0;
    *(undefined4 *)(param_1 + 0x200) = 0;
    private_spin_unlock_irqrestore();
    tx_isp_send_event_to_remote(*(int *)(param_1 + 0x288));
    private_wake_up_all();
    for (uVar1 = 0; uVar1 < *(uint *)(param_1 + 0x1e8); uVar1 = uVar1 + 1) {
      *(undefined4 *)(*(int *)(param_1 + uVar1 * 4 + 0xe8) + 0x48) = 0;
    }
  }
  return;
}



int __enqueue_in_driver(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x48) = 3;
  *(undefined *)(param_1 + 0x4c) = 3;
  iVar1 = tx_isp_send_event_to_remote(*(int *)(*(int *)(param_1 + 0x44) + 0x288));
  if ((iVar1 != 0) && (iVar1 != -0x203)) {
    isp_printf();
  }
  return iVar1;
}



undefined4 fs_activate_module(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      bVar1 = true;
      goto LAB_00019c94;
    }
    bVar1 = false;
    if (param_1 < 0xfffff001) goto LAB_00019c94;
  }
  bVar1 = true;
LAB_00019c94:
  if (bVar1) {
    return 0xffffffea;
  }
  iVar4 = 0;
  uVar3 = 0;
  if (*(int *)(param_1 + 0xe8) == 1) {
    while( true ) {
      if (*(int *)(param_1 + 0xe4) <= iVar4) {
        *(undefined4 *)(param_1 + 0xe8) = 2;
        return 0;
      }
      iVar2 = iVar4 * 0x2e0 + *(int *)(param_1 + 0xe0);
      if (*(int *)(iVar2 + 0x2c4) != 1) break;
      *(undefined4 *)(iVar2 + 0x2c4) = 2;
      iVar4 = iVar4 + 1;
    }
    isp_printf();
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



undefined4 dump_isp_framesource_open(void)

{
  undefined4 uVar1;
  
  PDE_DATA();
  uVar1 = private_single_open_size();
  return uVar1;
}



undefined4 isp_framesource_show(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = *(uint *)(param_1 + 0x48);
  if ((uVar2 == 0 || 0xfffff000 < uVar2) || (bVar1 = 0xfffff000 < uVar2, uVar2 == 0)) {
    uVar2 = 0;
    bVar1 = true;
  }
  uVar7 = 0;
  if (!bVar1) {
    uVar7 = *(uint *)(uVar2 + 0xd8);
  }
  iVar6 = 0;
  if (uVar7 == 0 || 0xfffff000 < uVar7) {
    isp_printf();
  }
  else {
    while (iVar6 < *(int *)(uVar7 + 0xe4)) {
      private_seq_printf();
      iVar5 = iVar6 * 0x2e0 + *(int *)(uVar7 + 0xe0);
      private_seq_printf();
      if (*(int *)(iVar5 + 0x2c4) == 4) {
        private_seq_printf();
        private_seq_printf();
        private_seq_printf();
        if (*(char *)(iVar5 + 0x278) != '\0') {
          private_seq_printf();
          private_seq_printf();
        }
        private_seq_printf();
        if (*(char *)(iVar5 + 0x264) != '\0') {
          private_seq_printf();
          private_seq_printf();
          private_seq_printf();
          private_seq_printf();
        }
        private_seq_printf();
        __private_spin_lock_irqsave();
        private_seq_printf();
        for (puVar3 = *(undefined4 **)(iVar5 + 0x214); puVar3 != (undefined4 *)(iVar5 + 0x214);
            puVar3 = (undefined4 *)*puVar3) {
          private_seq_printf();
        }
        private_seq_printf();
        for (puVar3 = *(undefined4 **)(iVar5 + 0x220); puVar3 != (undefined4 *)(iVar5 + 0x220);
            puVar3 = (undefined4 *)*puVar3) {
          private_seq_printf();
        }
        private_spin_unlock_irqrestore();
        private_seq_printf();
        private_seq_printf();
        if (iVar6 == 0) {
          private_seq_printf();
          private_seq_printf();
          private_seq_printf();
        }
        private_seq_printf();
        iVar8 = 0;
        iVar4 = 0;
        do {
          if (*(int *)(iVar5 + iVar4 + 0x110) != 0) {
            private_seq_printf();
          }
          iVar8 = iVar8 + 1;
          iVar4 = iVar8 * 4;
        } while (iVar8 != 0x40);
        iVar6 = iVar6 + 1;
      }
      else {
        iVar6 = iVar6 + 1;
      }
    }
  }
  return 0;
}



undefined4 frame_channel_open(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x78);
  if ((uVar3 == 0 || 0xfffff000 < uVar3) || (bVar1 = 0xfffff000 < uVar3, uVar3 == 0)) {
    uVar3 = 0;
    bVar1 = true;
  }
  if (bVar1) {
    uVar2 = 0xffffffea;
  }
  else {
    private_mutex_lock();
    if (*(int *)(uVar3 + 0x2c4) < 2) {
      private_mutex_unlock();
      isp_printf();
      uVar2 = 0xffffffff;
    }
    else {
      private_mutex_unlock();
      memset((void *)(uVar3 + 0x240),0,0x60);
      *(undefined4 *)(uVar3 + 0x2d4) = 0;
      *(undefined4 *)(uVar3 + 0x2d8) = 0;
      private_init_completion();
      __vb2_queue_free(uVar3 + 0x28,*(int *)(uVar3 + 0x210));
      *(undefined4 *)(uVar3 + 0x2c4) = 3;
      uVar2 = 0;
    }
  }
  return uVar2;
}



void __fill_v4l2_buffer(void *param_1,void *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)param_1 + 0x44);
  memcpy(param_2,param_1,0x34);
  *(undefined4 *)((int)param_2 + 0x3c) = *(undefined4 *)((int)param_1 + 0x3c);
  *(undefined4 *)((int)param_2 + 0x40) = *(undefined4 *)((int)param_1 + 0x40);
  uVar2 = *(uint *)((int)param_2 + 0xc) & 0xffff1bb8;
  *(uint *)((int)param_2 + 0xc) = uVar2;
  uVar2 = uVar2 | *(uint *)(iVar3 + 0x14);
  *(uint *)((int)param_2 + 0xc) = uVar2;
  uVar1 = *(uint *)((int)param_1 + 0x48);
  if (uVar1 != 3) {
    if (3 < uVar1) {
      if (uVar1 != 4) {
        if (uVar1 != 5) {
          return;
        }
        *(uint *)((int)param_2 + 0xc) = uVar2 | 0x40;
      }
      *(uint *)((int)param_2 + 0xc) = *(uint *)((int)param_2 + 0xc) | 4;
      return;
    }
    if (uVar1 != 1) {
      return;
    }
  }
  *(uint *)((int)param_2 + 0xc) = uVar2 | 2;
  return;
}



undefined4 frame_chan_event(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int **ppiVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *__src;
  int *piVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  int local_40;
  int local_3c;
  
  if (param_1 == (int *)0x0 || (int *)0xfffff000 < param_1) {
    return 0xffffffea;
  }
  if (param_2 != 0x3000006) {
    return 0;
  }
  if (param_3 == 0) {
    isp_printf();
    dump_msca_regs();
    return 0;
  }
  iVar5 = (uint)*(byte *)(param_1 + 1) * 0x2e0 + *(int *)(*param_1 + 0xe0);
  __private_spin_lock_irqsave();
  if (isp_ch0_pre_dequeue_time == 0) {
    puVar6 = *(undefined4 **)(iVar5 + 0x214);
LAB_0001a6e4:
    bVar8 = 0;
    for (; __src = puVar6 + -0x16, (undefined4 *)(iVar5 + 0x214) != puVar6;
        puVar6 = (undefined4 *)*puVar6) {
      if (puVar6[-9] == *(int *)(param_3 + 8)) {
        *(undefined *)(puVar6 + -3) = 0x65;
        goto LAB_0001a730;
      }
      bVar8 = bVar8 + 1;
    }
    __src = (undefined4 *)0x0;
LAB_0001a730:
    if (bVar8 != 0) {
      isp_printf();
      for (puVar6 = *(undefined4 **)(iVar5 + 0x214); (undefined4 *)(iVar5 + 0x214) != puVar6;
          puVar6 = (undefined4 *)*puVar6) {
        isp_printf();
      }
      isp_printf();
      dump_msca_regs();
    }
  }
  else {
    if (*(int *)(iVar5 + 0x2b4) != 0) {
      puVar6 = *(undefined4 **)(iVar5 + 0x214);
      goto LAB_0001a6e4;
    }
    if (*(int *)(param_3 + 0x14) == 0) {
      if (ch0_pre_dequeue_vb._52_4_ != *(int *)(param_3 + 8)) {
        isp_printf();
      }
      if (isp_ch0_pre_dequeue_intc_ahead == '\x01') {
        isp_printf();
      }
      if (isp_ch0_pre_dequeue_flag == '\x01') {
        isp_ch0_pre_dequeue_flag = '\0';
      }
      else {
        isp_printf();
        isp_ch0_pre_dequeue_intc_ahead = '\x01';
        isp_ch0_pre_dequeue_intc_ahead_cnt = isp_ch0_pre_dequeue_intc_ahead_cnt + '\x01';
        isp_ch0_pdq_intc_cnt = isp_ch0_pdq_intc_cnt + 1;
      }
      goto LAB_0001aac0;
    }
    if ((*(int *)(iVar5 + 0x214) == iVar5 + 0x214) ||
       (*(int *)(*(uint *)(*(int *)(iVar5 + 0x214) + -0x24) | 0xa0000000) == 0x12345678)) {
      isp_ch0_pre_dequeue_drop = isp_ch0_pre_dequeue_drop + 1;
      goto LAB_0001aac0;
    }
    uVar10 = *(uint *)(param_3 + 0x18) & 0xffff;
    if (((uVar10 == *(uint *)(iVar5 + 0x248)) || ((*(uint *)(param_3 + 0x18) & 0xffff) == 0)) &&
       (isp_ch0_pre_dequeue_intc_ahead != '\x01')) {
      isp_printf();
    }
    isp_ch0_pre_dequeue_intc_ahead = '\0';
    iVar4 = *(int *)(iVar5 + 0x214);
    isp_ch0_pre_dequeue_flag = '\x01';
    if (iVar4 == iVar5 + 0x214) {
      isp_printf();
      goto LAB_0001aac0;
    }
    __src = (undefined4 *)(iVar4 + -0x58);
    memcpy(ch0_pre_dequeue_vb,__src,0x68);
    ch0_pre_dequeue_vb._64_4_ = uVar10 << 0x10 | 1;
    *(undefined4 *)(iVar4 + -0x18) = ch0_pre_dequeue_vb._64_4_;
    isp_ch0_pre_dequeue_valid_lines = uVar10;
    *(undefined *)(iVar5 + 0x23c) = 0;
    bVar8 = 0;
    isp_ch0_pdq_cnt = isp_ch0_pdq_cnt + 1;
  }
  if (__src != (undefined4 *)0x0) {
    bVar9 = 0;
    piVar7 = *(int **)(iVar5 + 0x214);
    do {
      piVar1 = piVar7 + -0x16;
      if ((piVar1 == (int *)0x0) || (piVar7[-4] != 3)) {
        isp_printf();
        dump_msca_regs();
        *(int *)(iVar5 + 0x2d8) = *(int *)(iVar5 + 0x2d8) + 1;
      }
      else {
        *(undefined *)(piVar7 + -3) = 0x66;
        private_getrawmonotonic();
        piVar7[-1] = piVar7[-1] + 1;
        piVar7[-0x11] = local_40;
        piVar7[-0xb] = 0;
        piVar3 = (int *)piVar7[1];
        iVar4 = *piVar7;
        piVar7[-0x10] = local_3c / 1000;
        *(int **)(iVar4 + 4) = piVar3;
        *piVar3 = iVar4;
        *piVar7 = 0x100;
        piVar7[1] = 0x200;
        *(int *)(iVar5 + 0x21c) = *(int *)(iVar5 + 0x21c) + -1;
        if ((isp_ch0_pre_dequeue_time == 0) || (iVar4 = *(int *)(iVar5 + 0x2b4), iVar4 != 0)) {
          piVar7[-6] = piVar7[-6] & 0xffff0000;
          iVar4 = *(int *)(iVar5 + 0x2b4);
        }
        if (iVar4 == 0) {
          if (isp_day_night_switch_drop_frame_cnt != '\0') {
            isp_day_night_switch_drop_frame_cnt = isp_day_night_switch_drop_frame_cnt + -1;
            if (piVar1 != (int *)ch0_pre_dequeue_vb) {
              ppiVar2 = *(int ***)(iVar5 + 0x218);
              *(int **)(iVar5 + 0x218) = piVar7;
              piVar7[1] = (int)ppiVar2;
              *piVar7 = iVar5 + 0x214;
              *ppiVar2 = piVar7;
              piVar7[-4] = 1;
              goto LAB_0001a920;
            }
            goto LAB_0001aac0;
          }
        }
        else if (iVar4 == 1) {
          if (DAT_000d9875 != '\0') {
            ppiVar2 = *(int ***)(iVar5 + 0x218);
            DAT_000d9875 = DAT_000d9875 + -1;
            *(int **)(iVar5 + 0x218) = piVar7;
            *piVar7 = iVar5 + 0x214;
            piVar7[1] = (int)ppiVar2;
            *ppiVar2 = piVar7;
            piVar7[-4] = 1;
LAB_0001a920:
            *(int *)(iVar5 + 0x21c) = *(int *)(iVar5 + 0x21c) + 1;
            __enqueue_in_driver((int)piVar1);
            goto LAB_0001aac0;
          }
        }
        else if ((iVar4 == 2) && (DAT_000d9876 != '\0')) {
          ppiVar2 = *(int ***)(iVar5 + 0x218);
          DAT_000d9876 = DAT_000d9876 + -1;
          *(int **)(iVar5 + 0x218) = piVar7;
          *piVar7 = iVar5 + 0x214;
          piVar7[1] = (int)ppiVar2;
          *ppiVar2 = piVar7;
          piVar7[-4] = 1;
          goto LAB_0001a920;
        }
        piVar7[-4] = 4;
        ppiVar2 = *(int ***)(iVar5 + 0x224);
        *(int **)(iVar5 + 0x224) = piVar7 + 2;
        piVar7[2] = iVar5 + 0x220;
        piVar7[3] = (int)ppiVar2;
        *ppiVar2 = piVar7 + 2;
        *(int *)(iVar5 + 0x228) = *(int *)(iVar5 + 0x228) + 1;
        private_wake_up();
        private_complete();
      }
      bVar9 = bVar9 + 1;
      if (bVar8 < bVar9) goto code_r0x0001aa48;
      piVar7 = *(int **)(iVar5 + 0x214);
    } while( true );
  }
  isp_printf();
  isp_err3 = isp_err3 + 1;
  iVar5 = *(int *)(iVar5 + 0x2b4);
LAB_0001aaa4:
  *(undefined4 *)(lastaddr + iVar5 * 4) = *(undefined4 *)(param_3 + 8);
LAB_0001aac0:
  private_spin_unlock_irqrestore();
  return 0;
code_r0x0001aa48:
  iVar5 = *(int *)(iVar5 + 0x2b4);
  goto LAB_0001aaa4;
}



void tx_isp_frame_chan_deinit(uint param_1)

{
  if (param_1 != 0 && param_1 < 0xfffff001) {
    private_misc_deregister();
    __vb2_queue_cancel(param_1 + 0x28);
    __vb2_queue_free(param_1 + 0x28,*(int *)(param_1 + 0x210));
    *(undefined4 *)(param_1 + 0x2c4) = 1;
  }
  return;
}



undefined4 tx_isp_fs_probe(undefined4 *param_1)

{
  byte bVar1;
  void *__s;
  uint uVar2;
  void *__s_00;
  int iVar3;
  undefined4 *__s_01;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  __s = (void *)private_kmalloc();
  if (__s == (void *)0x0) {
    isp_printf();
    uVar6 = 0xfffffff4;
  }
  else {
    memset(__s,0,0xec);
    uVar2 = tx_isp_subdev_init(param_1,__s,fs_subdev_ops);
    if (uVar2 == 0) {
      *(uint *)((int)__s + 0xe4) = (uint)*(ushort *)((int)__s + 0xcc);
      if (*(ushort *)((int)__s + 0xcc) != 0) {
        __s_00 = (void *)private_kmalloc();
        *(void **)((int)__s + 0xe0) = __s_00;
        memset(__s_00,0,*(int *)((int)__s + 0xe4) * 0x2e0);
        iVar3 = *(int *)((int)__s + 0xe4);
        for (iVar5 = 0; iVar5 < iVar3; iVar5 = iVar5 + 1) {
          puVar4 = (undefined4 *)(iVar5 * 0x2e0 + *(int *)((int)__s + 0xe0));
          uVar2 = iVar5 * 0x24 + *(int *)((int)__s + 0xd0);
          if (puVar4 == (undefined4 *)0x0 || (undefined4 *)0xfffff000 < puVar4) {
            uVar6 = 0xffffffea;
LAB_0001af34:
            iVar3 = iVar5 * 0x2e0;
            while( true ) {
              iVar5 = iVar5 + -1;
              iVar3 = iVar3 + -0x2e0;
              if (iVar5 == 0) break;
              tx_isp_frame_chan_deinit(*(int *)((int)__s + 0xe0) + iVar3);
            }
            goto LAB_0001af08;
          }
          if (uVar2 == 0 || 0xfffff000 < uVar2) {
            uVar6 = 0xffffffea;
            goto LAB_0001af34;
          }
          bVar1 = *(byte *)(uVar2 + 4);
          puVar4[0xac] = uVar2;
          puVar4[0xad] = (uint)bVar1;
          if (*(char *)(uVar2 + 5) != '\0') {
            sprintf((char *)(puVar4 + 0xa8),"framechan%d",(uint)bVar1);
            *puVar4 = 0xff;
            puVar4[2] = fs_channel_ops;
            puVar4[1] = puVar4 + 0xa8;
            iVar3 = private_misc_register();
            if (iVar3 < 0) {
              isp_printf();
              uVar6 = 0xfffffffe;
            }
            else {
              __s_01 = puVar4 + 10;
              if (__s_01 != (undefined4 *)0x0 && __s_01 < (undefined4 *)0xfffff001) {
                memset(__s_01,0,0x218);
                puVar4[0x10] = 2;
                puVar4[0xe] = 0x84;
                puVar4[0xf] = 0x2000;
                puVar4[0x85] = puVar4 + 0x85;
                puVar4[0x86] = puVar4 + 0x85;
                puVar4[10] = 1;
                puVar4[0x88] = puVar4 + 0x88;
                puVar4[0x89] = puVar4 + 0x88;
                private_spin_lock_init();
                private_raw_mutex_init();
                puVar4[0x87] = 0;
                puVar4[0x8a] = 0;
                private_init_waitqueue_head();
                private_spin_lock_init();
                private_raw_mutex_init();
                private_init_completion();
                *(code **)(uVar2 + 0x1c) = frame_chan_event;
                puVar4[0xb1] = 1;
                goto LAB_0001aed4;
              }
              private_misc_deregister();
              uVar6 = 0xffffffea;
            }
            goto LAB_0001af34;
          }
          puVar4[0xb1] = 0;
LAB_0001aed4:
          iVar3 = *(int *)((int)__s + 0xe4);
        }
      }
      *(undefined4 *)((int)__s + 0xe8) = 1;
      private_platform_set_drvdata();
      *(undefined1 **)((int)__s + 0x38) = isp_framesource_fops;
      *(void **)((int)__s + 0xd8) = __s;
      uVar6 = 0;
    }
    else {
      isp_printf();
      uVar6 = 0xfffffff4;
LAB_0001af08:
      private_kfree();
    }
  }
  return uVar6;
}



undefined4 __frame_channel_vb2_streamoff(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == *(int *)(param_1 + 0x28)) && ((*(uint *)(param_1 + 0x234) & 1) != 0)) {
    __vb2_queue_cancel(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x2c4) = 3;
    uVar1 = 0;
  }
  else {
    isp_printf();
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



undefined4 frame_channel_release(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_2 + 0x78);
  if ((uVar2 == 0 || 0xfffff000 < uVar2) || (bVar1 = 0xfffff000 < uVar2, uVar2 == 0)) {
    uVar2 = 0;
    bVar1 = true;
  }
  if (bVar1) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    if (*(int *)(uVar2 + 0x2c4) == 4) {
      __frame_channel_vb2_streamoff(uVar2,*(int *)(uVar2 + 0x28));
      __vb2_queue_free(uVar2 + 0x28,*(int *)(uVar2 + 0x210));
      *(undefined4 *)(uVar2 + 0x2c4) = 2;
    }
  }
  return uVar3;
}



undefined4 fs_slake_module(uint param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0 || 0xfffff000 < param_1) {
    param_1 = 0;
  }
  else {
    if (param_1 == 0) {
      bVar1 = true;
      goto LAB_0001b118;
    }
    bVar1 = false;
    if (param_1 < 0xfffff001) goto LAB_0001b118;
  }
  bVar1 = true;
LAB_0001b118:
  uVar2 = 0xffffffea;
  if (!bVar1) {
    iVar4 = 0;
    if (*(int *)(param_1 + 0xe8) != 1) {
      for (; iVar4 < *(int *)(param_1 + 0xe4); iVar4 = iVar4 + 1) {
        iVar3 = iVar4 * 0x2e0 + *(int *)(param_1 + 0xe0);
        if (*(int *)(iVar3 + 0x2c4) == 4) {
          __frame_channel_vb2_streamoff(iVar3,*(int *)(iVar3 + 0x28));
          __vb2_queue_free(iVar3 + 0x28,*(int *)(iVar3 + 0x210));
          *(undefined4 *)(iVar3 + 0x2c4) = 1;
        }
        else {
          *(undefined4 *)(iVar3 + 0x2c4) = 1;
        }
      }
      *(undefined4 *)(param_1 + 0xe8) = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// WARNING: Type propagation algorithm not settling

int frame_channel_unlocked_ioctl(int param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  int local_68;
  uint local_64;
  int local_60;
  uint local_38;
  int local_30;
  
  uVar2 = *(uint *)(param_1 + 0x78);
  if (uVar2 == 0 || 0xfffff000 < uVar2) {
    uVar2 = 0;
  }
  if (param_2 == 0x800456c5) {
    local_38 = 0;
    if (uVar2 == 0 || 0xfffff000 < uVar2) {
      return -0x16;
    }
    if (param_3 != 0 && param_3 < 0xfffff001) {
      iVar3 = private_copy_from_user();
      if (iVar3 == 0) {
        iVar3 = tx_isp_send_event_to_remote(*(int *)(uVar2 + 0x2b0));
        if (iVar3 == 0) {
          return 0;
        }
        if (iVar3 == -0x203) {
          return 0;
        }
        isp_printf();
        return iVar3;
      }
      goto LAB_0001c06c;
    }
    goto LAB_0001b358;
  }
  if (param_2 < 0x800456c6) {
    if (param_2 == 0x406056c4) {
      if (uVar2 == 0 || 0xfffff000 < uVar2) {
        return -0x16;
      }
      iVar3 = tx_isp_send_event_to_remote(*(int *)(uVar2 + 0x2b0));
      if ((iVar3 != 0) && (iVar3 != -0x203)) {
LAB_0001b414:
        isp_printf();
        return iVar3;
      }
      local_7c = 8;
      local_88 = 4;
      local_98 = 1;
LAB_0001b450:
      iVar3 = private_copy_to_user();
      if (iVar3 == 0) {
        memcpy((void *)(uVar2 + 0x240),&local_98,0x60);
        return 0;
      }
      goto LAB_0001c06c;
    }
    if (0x406056c4 < param_2) {
      if (param_2 == 0x80045612) {
        if (uVar2 == 0 || 0xfffff000 < uVar2) {
          return -0x16;
        }
        if (*(int *)(uVar2 + 0x2c4) != 3) {
          isp_printf();
          return -1;
        }
        if (param_3 != 0 && param_3 < 0xfffff001) {
          iVar3 = private_copy_from_user();
          if (iVar3 != 0) goto LAB_0001c06c;
          if (local_38 == *(int *)(uVar2 + 0x28)) {
            if ((*(uint *)(uVar2 + 0x234) & 1) == 0) {
              puVar9 = *(undefined4 **)(uVar2 + 0x214);
              while( true ) {
                if (puVar9 == (undefined4 *)(uVar2 + 0x214)) break;
                __enqueue_in_driver((int)(puVar9 + -0x16));
                puVar9 = (undefined4 *)*puVar9;
              }
              *(byte *)(uVar2 + 0x234) = *(byte *)(uVar2 + 0x234) & 0xfe | 1;
              iVar3 = tx_isp_send_event_to_remote(*(int *)(uVar2 + 0x2b0));
              if ((iVar3 != 0) && (iVar3 != -0x203)) {
                isp_printf();
                __vb2_queue_cancel(uVar2 + 0x28);
                *(byte *)(uVar2 + 0x234) = *(byte *)(uVar2 + 0x234) & 0xfe;
                return iVar3;
              }
              *(undefined4 *)(uVar2 + 0x2c4) = 4;
              isp_printf();
              return 0;
            }
LAB_0001bdec:
            isp_printf();
            return -0x10;
          }
        }
LAB_0001b358:
        isp_printf();
        return -0x16;
      }
      if (param_2 != 0x80045613) {
        return -0x203;
      }
      if (uVar2 == 0 || 0xfffff000 < uVar2) {
        return -0x16;
      }
      if (param_3 == 0 || 0xfffff000 < param_3) goto LAB_0001b358;
      iVar3 = private_copy_from_user();
      if (iVar3 == 0) {
        iVar3 = __frame_channel_vb2_streamoff(uVar2,local_38);
        return iVar3;
      }
      goto LAB_0001c06c;
    }
    if (param_2 != 0x400456bf) {
      return -0x203;
    }
    local_38 = 0;
    iVar3 = private_wait_for_completion_interruptible();
    local_38 = iVar3;
    if (-1 < iVar3) {
      local_38 = *(int *)(uVar2 + 0x2c8) + 1;
    }
    iVar6 = private_copy_to_user();
  }
  else {
    if (param_2 == 0xc044560f) {
      local_38 = 0;
      if (uVar2 == 0 || 0xfffff000 < uVar2) {
        return -0x16;
      }
      if (param_3 == 0 || 0xfffff000 < param_3) goto LAB_0001b358;
      iVar3 = private_copy_from_user();
      if (iVar3 != 0) goto LAB_0001c06c;
      if (local_94 != *(int *)(uVar2 + 0x28)) goto LAB_0001b358;
      if (*(uint *)(uVar2 + 0x210) <= local_98) {
LAB_0001b988:
        isp_printf();
        return -0x16;
      }
      pvVar8 = *(void **)(uVar2 + (local_98 + 0x3a) * 4 + 0x28);
      if ((pvVar8 == (void *)0x0) ||
         (*(undefined *)((int)pvVar8 + 0x4c) = 1, local_68 != *(int *)(uVar2 + 0x40)))
      goto LAB_0001b358;
      if (local_60 != *(int *)(uVar2 + 0x5c)) goto LAB_0001b988;
      if (*(int *)((int)pvVar8 + 0x48) != 0) goto LAB_0001b358;
      iVar3 = *(int *)(uVar2 + 0x2b4);
      *(uint *)((int)pvVar8 + 0x34) = local_64;
      *(int *)((int)pvVar8 + 0x38) = local_60;
      *(int *)((int)pvVar8 + 0x10) = local_88;
      *(undefined4 *)((int)pvVar8 + 0x14) = local_84;
      *(undefined4 *)((int)pvVar8 + 0x18) = local_80;
      *(uint *)((int)pvVar8 + 0xc) = local_8c & 0xffff1bb8;
      private_dma_sync_single_for_device();
      if ((isp_ch0_pre_dequeue_time != 0) && (iVar3 == 0)) {
        *(undefined4 *)(local_64 | 0xa0000000) = 0x12345678;
      }
      *(int *)((int)pvVar8 + 0x68) = (int)pvVar8 + 0x68;
      *(int *)((int)pvVar8 + 0x6c) = (int)pvVar8 + 0x68;
      *(uint *)((int)pvVar8 + 0x70) = local_64;
      *(undefined4 *)((int)pvVar8 + 0x48) = 2;
      *(undefined *)((int)pvVar8 + 0x4c) = 2;
      private_mutex_lock();
      __private_spin_lock_irqsave();
      piVar10 = *(int **)(uVar2 + 0x218);
      *(int *)(uVar2 + 0x218) = (int)pvVar8 + 0x58;
      *(uint *)((int)pvVar8 + 0x58) = uVar2 + 0x214;
      *(int **)((int)pvVar8 + 0x5c) = piVar10;
      *piVar10 = (int)pvVar8 + 0x58;
      *(undefined4 *)((int)pvVar8 + 0x48) = 1;
      *(int *)(uVar2 + 0x21c) = *(int *)(uVar2 + 0x21c) + 1;
      private_spin_unlock_irqrestore();
      if ((*(uint *)(uVar2 + 0x234) & 1) != 0) {
        __enqueue_in_driver((int)pvVar8);
      }
      *(undefined *)((int)pvVar8 + 0x4c) = 0x1e;
      __fill_v4l2_buffer(pvVar8,&local_98);
      private_mutex_unlock();
    }
    else {
      if (0xc044560f < param_2) {
        if (param_2 == 0xc0445611) {
          if (uVar2 == 0 || 0xfffff000 < uVar2) {
            return -0x16;
          }
          if (param_3 != 0 && param_3 < 0xfffff001) {
            iVar3 = private_copy_from_user();
            if (iVar3 != 0) goto LAB_0001c06c;
            if (local_94 == *(int *)(uVar2 + 0x28)) {
              local_38 = 0;
              piVar10 = (int *)0x0;
              iVar3 = 0;
              uVar4 = *(uint *)(uVar2 + 0x234);
              do {
                if ((uVar4 & 1) == 0) {
                  isp_printf();
                  return -0x16;
                }
                local_30 = uVar2 + 0x228;
                __private_spin_lock_irqsave();
                if (*(int *)(uVar2 + 0x2b4) == 0) {
                  if (isp_ch0_pre_dequeue_interrupt_process == 0) {
                    piVar5 = *(int **)(uVar2 + 0x220);
                    goto LAB_0001c088;
                  }
                  if (*(char *)(uVar2 + 0x23c) == '\0') {
                    piVar5 = *(int **)(uVar2 + 0x220);
                    goto LAB_0001c088;
                  }
                  if (ch0_pre_dequeue_vb._64_2_ != 2) {
                    piVar5 = *(int **)(uVar2 + 0x220);
                    goto LAB_0001c088;
                  }
                  *(undefined *)(uVar2 + 0x23c) = 0;
                  piVar10 = (int *)ch0_pre_dequeue_vb;
LAB_0001bc88:
                  bVar1 = true;
                }
                else {
                  piVar5 = *(int **)(uVar2 + 0x220);
LAB_0001c088:
                  bVar1 = false;
                  if (piVar5 != (int *)(uVar2 + 0x220)) {
                    piVar10 = (int *)piVar5[1];
                    iVar6 = *piVar5;
                    *(int **)(iVar6 + 4) = piVar10;
                    *piVar10 = iVar6;
                    *piVar5 = 0x100;
                    piVar5[1] = 0x200;
                    *(int *)(uVar2 + 0x228) = *(int *)(uVar2 + 0x228) + -1;
                    piVar10 = piVar5 + -0x18;
                    goto LAB_0001bc88;
                  }
                }
                private_spin_unlock_irqrestore();
                if (bVar1) {
LAB_0001bcec:
                  if (iVar3 < 0) {
                    return iVar3;
                  }
                  __fill_v4l2_buffer(piVar10,&local_98);
                  piVar10[0x12] = 0;
                  iVar6 = private_copy_to_user();
                  iVar3 = 0;
                  goto LAB_0001c058;
                }
                iVar3 = private_wait_event_interruptible();
                if (iVar3 == -0x200) {
                  uVar4 = *(uint *)(uVar2 + 0x234);
                }
                else {
                  if (iVar3 != 0) {
                    isp_printf();
                    goto LAB_0001bcec;
                  }
                  uVar4 = *(uint *)(uVar2 + 0x234);
                }
              } while( true );
            }
          }
          goto LAB_0001b358;
        }
        if (param_2 != 0xc06056c3) {
          return -0x203;
        }
        if (uVar2 == 0 || 0xfffff000 < uVar2) {
          return -0x16;
        }
        iVar3 = private_copy_from_user();
        if (iVar3 != 0) goto LAB_0001c06c;
        if (local_98 != 1) goto LAB_0001b358;
        if (local_88 == 0) {
          local_88 = 4;
        }
        else if (local_88 != 4) goto LAB_0001b358;
        if (local_7c != 8) goto LAB_0001b358;
        iVar3 = tx_isp_send_event_to_remote(*(int *)(uVar2 + 0x2b0));
        if ((iVar3 != 0) && (iVar3 != -0x203)) goto LAB_0001b414;
        goto LAB_0001b450;
      }
      if (param_2 == 0xc0145608) {
        if (uVar2 == 0 || 0xfffff000 < uVar2) {
          return -0x16;
        }
        if (param_3 != 0 && param_3 < 0xfffff001) {
          iVar3 = private_copy_from_user();
          if (iVar3 != 0) goto LAB_0001c06c;
          piVar10 = (int *)(uVar2 + 0x28);
          if ((*(uint *)(uVar2 + 0x234) & 1) != 0) goto LAB_0001bdec;
          if (((local_98 == 0) || (*(int *)(uVar2 + 0x210) != 0)) ||
             (*(int *)(uVar2 + 0x40) != local_90)) {
            __vb2_queue_free((int)piVar10,*(int *)(uVar2 + 0x210));
            if (local_98 == 0) {
              return 0;
            }
            iVar3 = *(int *)(uVar2 + 0x40);
          }
          else {
            iVar3 = *(int *)(uVar2 + 0x40);
          }
          if (iVar3 == local_90) {
            uVar4 = 0x40;
            if (local_98 < 0x41) {
              uVar4 = local_98;
            }
            uVar7 = 0;
            if (((isp_ch0_pre_dequeue_time < 1) || (*(int *)(uVar2 + 0x2b4) != 0)) || (uVar4 < 2)) {
              do {
                if (uVar7 == uVar4) {
LAB_0001b670:
                  isp_printf();
                  if (uVar7 == 0) {
                    isp_printf();
                    return -0xc;
                  }
                  local_38 = uVar7;
                  if (uVar7 < uVar4) {
                    __vb2_queue_free((int)piVar10,uVar7);
                    isp_printf();
                    return -0xc;
                  }
                  *(uint *)(uVar2 + 0x210) = uVar7;
                  local_98 = uVar7;
                  iVar3 = tx_isp_send_event_to_remote(*(int *)(uVar2 + 0x2b0));
                  if ((iVar3 != 0) && (iVar3 != -0x203)) {
                    isp_printf();
                    return iVar3;
                  }
                  iVar3 = private_copy_to_user();
                  if (iVar3 != 0) {
                    isp_printf();
                    return -0xc;
                  }
                  if (uVar2 == 0xfffffdc0 || 0xfffff000 < uVar2 + 0x240) {
                    return 0;
                  }
                  if (uVar2 != 0xffffffbc && uVar2 + 0x44 < 0xfffff001) {
                    *(undefined4 *)(uVar2 + 0x44) = *(undefined4 *)(uVar2 + 0x240);
                    memcpy((void *)(uVar2 + 0x48),(void *)(uVar2 + 0x244),0x20);
                    return 0;
                  }
                  return 0;
                }
                piVar5 = (int *)private_kmalloc();
                if (piVar5 == (int *)0x0) {
                  isp_printf();
                  goto LAB_0001b670;
                }
                memset(piVar5,0,*(size_t *)(uVar2 + 0x38));
                piVar5[0x12] = 0;
                piVar5[0x11] = (int)piVar10;
                *piVar5 = uVar7 + *(int *)(uVar2 + 0x210);
                piVar5[1] = *piVar10;
                piVar5[0xc] = *(int *)(uVar2 + 0x40);
                piVar10[uVar7 + *(int *)(uVar2 + 0x210) + 0x3a] = (int)piVar5;
                uVar7 = uVar7 + 1;
              } while( true );
            }
            goto LAB_0001b988;
          }
        }
        goto LAB_0001b358;
      }
      if (param_2 != 0xc0445609) {
        return -0x203;
      }
      if (uVar2 == 0 || 0xfffff000 < uVar2) {
        return -0x16;
      }
      if (param_3 == 0 || 0xfffff000 < param_3) goto LAB_0001b358;
      iVar3 = private_copy_from_user();
      if (iVar3 != 0) goto LAB_0001c06c;
      if ((local_94 != *(int *)(uVar2 + 0x28)) || (*(uint *)(uVar2 + 0x210) <= local_98))
      goto LAB_0001b358;
      __fill_v4l2_buffer(*(void **)(uVar2 + (local_98 + 0x3a) * 4 + 0x28),&local_98);
    }
    iVar6 = private_copy_to_user();
    iVar3 = iVar6;
  }
LAB_0001c058:
  if (iVar6 == 0) {
    return iVar3;
  }
LAB_0001c06c:
  isp_printf();
  return -0xc;
}



void sensor_hw_reset_enable(void)

{
  return;
}



void sensor_hw_reset_disable(void)

{
  return;
}



void sensor_alloc_analog_gain(undefined4 param_1,undefined2 *param_2)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  (**(code **)(*(int *)(g_ispcore + 0x124) + 0xc0))(param_1,0x10,local_10);
  *param_2 = (short)local_10[0];
  return;
}



void sensor_alloc_analog_gain_short(undefined4 param_1,int param_2)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  (**(code **)(*(int *)(g_ispcore + 0x124) + 0xc4))(param_1,0x10,local_10);
  *(short *)(param_2 + 0xe) = (short)local_10[0];
  return;
}



void sensor_alloc_digital_gain(undefined4 param_1,int param_2)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  (**(code **)(*(int *)(g_ispcore + 0x124) + 200))(param_1,0x10,local_10);
  *(short *)(param_2 + 2) = (short)local_10[0];
  return;
}



undefined4 sensor_alloc_integration_time(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  pcVar1 = *(code **)(*(int *)(g_ispcore + 0x124) + 0xd0);
  if (pcVar1 == (code *)0x0) {
    *(short *)(param_2 + 0x10) = (short)param_1;
  }
  else {
    param_1 = (*pcVar1)(param_1,0,local_10);
    *(short *)(param_2 + 0x10) = (short)local_10[0];
  }
  return param_1;
}



undefined4 sensor_alloc_integration_time_short(undefined4 param_1,int param_2)

{
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  if (*(int *)(*(int *)(g_ispcore + 0x124) + 0xd0) == 0) {
    *(short *)(param_2 + 0x12) = (short)param_1;
  }
  else {
    param_1 = (**(code **)(*(int *)(g_ispcore + 0x124) + 0xd4))(param_1,0,local_10);
    *(short *)(param_2 + 0x12) = (short)local_10[0];
  }
  return param_1;
}



void sensor_set_integration_time(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = g_ispcore;
  uVar3 = param_1 & 0xffff;
  iVar2 = *(int *)(g_ispcore + 0x124);
  if (uVar3 == *(uint *)(iVar2 + 0xac)) {
    if (*(int *)(g_ispcore + 0x1dc) != 1) {
      return;
    }
    uVar4 = *(uint *)(iVar2 + 0xec);
  }
  else {
    uVar4 = *(uint *)(iVar2 + 0xec);
  }
  *(uint *)(iVar2 + 0xac) = uVar3;
  *(uint *)(iVar2 + 0xec) = uVar3 + (uVar4 & 0xffff0000);
  *(undefined4 *)(iVar1 + 0x19c) = 1;
  *(uint *)(iVar1 + 0x1a0) = uVar3;
  *(undefined4 *)(iVar1 + 0x1b4) = 1;
  *(undefined4 *)(iVar1 + 0x1b8) = *(undefined4 *)(iVar2 + 0xec);
  return;
}



void sensor_set_integration_time_short(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = g_ispcore;
  uVar3 = param_1 & 0xffff;
  iVar2 = *(int *)(g_ispcore + 0x124);
  if (uVar3 == *(uint *)(iVar2 + 0xdc)) {
    if (*(int *)(g_ispcore + 0x1dc) != 1) {
      return;
    }
    *(uint *)(iVar2 + 0xdc) = uVar3;
  }
  else {
    *(uint *)(iVar2 + 0xdc) = uVar3;
  }
  *(undefined4 *)(iVar1 + 0x1a4) = 1;
  *(uint *)(iVar1 + 0x1a8) = uVar3;
  return;
}



void sensor_set_analog_gain(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = g_ispcore;
  iVar3 = *(int *)(g_ispcore + 0x124);
  if (param_1 == *(int *)(iVar3 + 0x9c)) {
    if (*(int *)(g_ispcore + 0x1dc) != 1) {
      return;
    }
    uVar1 = *(ushort *)(iVar3 + 0xec);
  }
  else {
    uVar1 = *(ushort *)(iVar3 + 0xec);
  }
  *(int *)(iVar3 + 0x9c) = param_1;
  *(uint *)(iVar3 + 0xec) = param_1 << 0x10 | (uint)uVar1;
  *(undefined4 *)(iVar2 + 0x184) = 1;
  *(int *)(iVar2 + 0x188) = param_1;
  *(undefined4 *)(iVar2 + 0x1b4) = 1;
  *(undefined4 *)(iVar2 + 0x1b8) = *(undefined4 *)(iVar3 + 0xec);
  return;
}



void sensor_set_analog_gain_short(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_ispcore;
  iVar2 = *(int *)(g_ispcore + 0x124);
  if (param_1 == *(int *)(iVar2 + 0xe4)) {
    if (*(int *)(g_ispcore + 0x1dc) != 1) {
      return;
    }
    *(int *)(iVar2 + 0xe4) = param_1;
  }
  else {
    *(int *)(iVar2 + 0xe4) = param_1;
  }
  *(undefined4 *)(iVar1 + 0x18c) = 1;
  *(int *)(iVar1 + 400) = param_1;
  return;
}



void sensor_set_digital_gain(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_ispcore;
  iVar2 = *(int *)(g_ispcore + 0x124);
  if (param_1 == *(int *)(iVar2 + 0xa0)) {
    if (*(int *)(g_ispcore + 0x1dc) != 1) {
      return;
    }
    *(int *)(iVar2 + 0xa0) = param_1;
  }
  else {
    *(int *)(iVar2 + 0xa0) = param_1;
  }
  *(undefined4 *)(iVar1 + 0x194) = 1;
  *(int *)(iVar1 + 0x198) = param_1;
  return;
}



uint sensor_get_normal_fps(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(g_ispcore + 0x130) >> 0x10;
  uVar1 = *(uint *)(g_ispcore + 0x130) & 0xffff;
  return (uVar2 % uVar1 << 8) / uVar1 + (uVar2 / uVar1) * 0x100 & 0xffff;
}



undefined4 sensor_read_black_pedestal(void)

{
  return 0;
}



void sensor_start_changes(void)

{
  return;
}



void sensor_end_changes(void)

{
  return;
}



undefined2 sensor_get_id(void)

{
  return *(undefined2 *)(*(int *)(g_ispcore + 0x124) + 4);
}



void sensor_set_wdr_mode(void)

{
  return;
}



undefined4 sensor_fps_control(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = g_ispcore;
  iVar2 = *(int *)(g_ispcore + 0x124);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar2 + 0xb0);
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iVar2 + 0xb2);
  *(uint *)(param_2 + 0x28) = (uint)*(ushort *)(iVar2 + 0xa4);
  *(uint *)(param_2 + 0x2c) = (uint)*(ushort *)(iVar2 + 0xb4);
  *(uint *)(param_2 + 0x50) = (uint)*(ushort *)(iVar2 + 0xd8);
  *(uint *)(param_2 + 0x54) = (uint)*(ushort *)(iVar2 + 0xda);
  *(uint *)(param_2 + 0x30) = (uint)*(ushort *)(iVar2 + 0xb4);
  *(uint *)(param_2 + 0x34) = (uint)*(ushort *)(iVar2 + 0xaa);
  return *(undefined4 *)(iVar1 + 0x130);
}



void sensor_disable_isp(void)

{
  return;
}



undefined4 sensor_get_lines_per_second(void)

{
  return 0;
}



void sensor_set_mode(undefined param_1,undefined *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined local_20 [12];
  
  iVar2 = g_ispcore;
  local_20[0] = 1;
  iVar4 = *(int *)(g_ispcore + 0x124);
  if (((g_ispcore == 0) || (*(code **)(g_ispcore + 0x80) == (code *)0x0)) ||
     (iVar3 = (**(code **)(g_ispcore + 0x80))(g_ispcore,0x200000d,local_20), iVar3 != 0)) {
    isp_printf();
  }
  else {
    *(short *)(param_2 + 6) = (short)*(undefined4 *)(iVar2 + 0xf0);
    *(short *)(param_2 + 8) = (short)*(undefined4 *)(iVar2 + 0xf4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(iVar4 + 0xb0);
    *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iVar4 + 0xb2);
    *(uint *)(param_2 + 0x28) = (uint)*(ushort *)(iVar4 + 0xa4);
    *(uint *)(param_2 + 0x2c) = (uint)*(ushort *)(iVar4 + 0xb4);
    *(uint *)(param_2 + 0x50) = (uint)*(ushort *)(iVar4 + 0xd8);
    *(uint *)(param_2 + 0x54) = (uint)*(ushort *)(iVar4 + 0xda);
    *(uint *)(param_2 + 0x30) = (uint)*(ushort *)(iVar4 + 0xb4);
    uVar1 = *(ushort *)(iVar4 + 0xaa);
    *param_2 = param_1;
    *(uint *)(param_2 + 0x34) = (uint)uVar1;
  }
  return;
}



void sensor_init(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(g_ispcore + 0x124);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 0x94);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x98);
  *(char *)(param_1 + 0x3a) = (char)*(undefined2 *)(iVar1 + 0xb6);
  *(char *)(param_1 + 0x3b) = (char)*(undefined2 *)(iVar1 + 0xb8);
  *(char *)(param_1 + 0x3c) = (char)*(undefined2 *)(iVar1 + 0xba);
  *(uint *)(param_1 + 0x28) = (uint)*(ushort *)(iVar1 + 0xa4);
  *(uint *)(param_1 + 0x2c) = (uint)*(ushort *)(iVar1 + 0xb4);
  *(uint *)(param_1 + 0x50) = (uint)*(ushort *)(iVar1 + 0xd8);
  *(uint *)(param_1 + 0x54) = (uint)*(ushort *)(iVar1 + 0xda);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 + 0xe0);
  *(code **)(param_1 + 0x5c) = sensor_hw_reset_disable;
  *(code **)(param_1 + 0x60) = sensor_hw_reset_enable;
  *(code **)(param_1 + 100) = sensor_alloc_analog_gain;
  *(code **)(param_1 + 0x68) = sensor_alloc_analog_gain_short;
  *(code **)(param_1 + 0x6c) = sensor_alloc_digital_gain;
  *(code **)(param_1 + 0x70) = sensor_alloc_integration_time;
  *(code **)(param_1 + 0x74) = sensor_alloc_integration_time_short;
  *(code **)(param_1 + 0x78) = sensor_set_integration_time;
  *(code **)(param_1 + 0x7c) = sensor_set_integration_time_short;
  *(code **)(param_1 + 0x80) = sensor_start_changes;
  *(code **)(param_1 + 0x84) = sensor_end_changes;
  *(code **)(param_1 + 0x88) = sensor_set_analog_gain;
  *(code **)(param_1 + 0x8c) = sensor_set_analog_gain_short;
  *(code **)(param_1 + 0x90) = sensor_set_digital_gain;
  *(code **)(param_1 + 0x94) = sensor_get_normal_fps;
  *(code **)(param_1 + 0x98) = sensor_read_black_pedestal;
  *(code **)(param_1 + 0x9c) = sensor_set_mode;
  *(code **)(param_1 + 0xa0) = sensor_set_wdr_mode;
  *(code **)(param_1 + 0xa4) = sensor_fps_control;
  *(code **)(param_1 + 0xa8) = sensor_get_id;
  *(code **)(param_1 + 0xac) = sensor_disable_isp;
  *(code **)(param_1 + 0xb0) = sensor_get_lines_per_second;
  return;
}



undefined4 sensor_early_init(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = 0;
    if (g_ispcore == 0) {
      g_ispcore = param_1;
      return uVar1;
    }
  }
  return uVar1;
}



int tx_isp_video_s_stream(int param_1,int param_2)

{
  code **ppcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  iVar7 = 0;
  while( true ) {
    iVar3 = *(int *)(param_1 + iVar7 + 0x3c);
    if ((((iVar3 != 0) &&
         (ppcVar1 = *(code ***)(*(int *)(iVar3 + 200) + 4), ppcVar1 != (code **)0x0)) &&
        (pcVar2 = *ppcVar1, pcVar2 != (code *)0x0)) &&
       ((iVar3 = (*pcVar2)(iVar3,param_2), iVar3 != 0 && (iVar3 != -0x203)))) break;
    iVar5 = iVar5 + 1;
    iVar7 = iVar5 * 4;
    if (iVar5 == 0x10) {
      return 0;
    }
  }
  iVar6 = 0;
  while (iVar6 != iVar5) {
    iVar4 = *(int *)(iVar6 * -4 + param_1 + iVar7 + 0x3c);
    if (iVar4 == 0) {
      iVar6 = iVar6 + 1;
    }
    else {
      ppcVar1 = *(code ***)(*(int *)(iVar4 + 200) + 4);
      if (ppcVar1 == (code **)0x0) {
        iVar6 = iVar6 + 1;
      }
      else {
        pcVar2 = *ppcVar1;
        if (pcVar2 == (code *)0x0) {
          iVar6 = iVar6 + 1;
        }
        else {
          (*pcVar2)(iVar4,param_2 == 0);
          iVar6 = iVar6 + 1;
        }
      }
    }
  }
  return iVar3;
}



int tx_isp_video_link_stream(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  iVar7 = 0;
  while( true ) {
    iVar4 = *(int *)(param_1 + iVar7 + 0x3c);
    if ((((iVar4 != 0) && (iVar2 = *(int *)(*(int *)(iVar4 + 200) + 4), iVar2 != 0)) &&
        (pcVar3 = *(code **)(iVar2 + 4), pcVar3 != (code *)0x0)) &&
       ((iVar4 = (*pcVar3)(iVar4,param_2), iVar4 != 0 && (iVar4 != -0x203)))) break;
    iVar6 = iVar6 + 1;
    iVar7 = iVar6 * 4;
    if (iVar6 == 0x10) {
      return 0;
    }
  }
  iVar2 = 0;
  while (iVar2 != iVar6) {
    iVar5 = *(int *)(iVar2 * -4 + param_1 + iVar7 + 0x3c);
    if (iVar5 == 0) {
      iVar2 = iVar2 + 1;
    }
    else {
      iVar1 = *(int *)(*(int *)(iVar5 + 200) + 4);
      if (iVar1 == 0) {
        iVar2 = iVar2 + 1;
      }
      else {
        pcVar3 = *(code **)(iVar1 + 4);
        if (pcVar3 == (code *)0x0) {
          iVar2 = iVar2 + 1;
        }
        else {
          (*pcVar3)(iVar5,param_2 == 0);
          iVar2 = iVar2 + 1;
        }
      }
    }
  }
  return iVar4;
}



int tx_isp_open(undefined4 param_1,int param_2)

{
  int iVar1;
  code **ppcVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *(int *)(param_2 + 0x78);
  if (*(int *)(iVar4 + 0x10c) != 0) {
    *(int *)(iVar4 + 0x10c) = *(int *)(iVar4 + 0x10c) + 1;
    return 0;
  }
  iVar6 = 0;
  *(undefined4 *)(iVar4 + 0x110) = 0xffffffff;
  iVar1 = 0;
  iVar5 = iVar4 + -0xc;
  do {
    if (*(int *)(iVar5 + 0x3c) != 0) {
      ppcVar2 = *(code ***)(*(int *)(*(int *)(iVar5 + 0x3c) + 200) + 0x10);
      if ((ppcVar2 != (code **)0x0) && (pcVar3 = *ppcVar2, pcVar3 != (code *)0x0)) {
        iVar1 = (*pcVar3)();
        if (iVar1 == 0) goto LAB_0001ca1c;
        if (iVar1 != -0x203) {
          return iVar1;
        }
      }
      iVar1 = -0x203;
    }
LAB_0001ca1c:
    iVar6 = iVar6 + 4;
    iVar5 = iVar4 + -0xc + iVar6;
    if (iVar6 == 0x40) {
      if (iVar1 == -0x203) {
        iVar1 = 0;
      }
      return iVar1;
    }
  } while( true );
}



int tx_isp_notify(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = globe_ispdev;
  iVar5 = 0;
  iVar2 = 0;
  iVar4 = globe_ispdev;
  do {
    iVar4 = *(int *)(iVar4 + 0x3c);
    if (iVar4 != 0) {
      if ((param_2 & 0xff000000) == 0x1000000) {
        if (**(int **)(iVar4 + 200) != 0) {
          pcVar3 = *(code **)(**(int **)(iVar4 + 200) + 0x1c);
LAB_0001caf0:
          if (pcVar3 != (code *)0x0) {
            iVar4 = (*pcVar3)(iVar4,param_2,param_3);
            if (iVar4 == 0) {
              iVar2 = 0;
            }
            else {
              if (iVar4 != -0x203) {
                return iVar4;
              }
              iVar2 = -0x203;
            }
            goto LAB_0001cb1c;
          }
        }
        iVar2 = -0x203;
      }
      else if ((param_2 & 0xff000000) == 0x2000000) {
        iVar2 = *(int *)(*(int *)(iVar4 + 200) + 0xc);
        if (iVar2 != 0) {
          pcVar3 = *(code **)(iVar2 + 8);
          goto LAB_0001caf0;
        }
        iVar2 = -0x203;
      }
      else {
        iVar2 = 0;
      }
    }
LAB_0001cb1c:
    iVar5 = iVar5 + 4;
    iVar4 = iVar1 + iVar5;
    if (iVar5 == 0x40) {
      if (iVar2 == -0x203) {
        iVar2 = 0;
      }
      return iVar2;
    }
  } while( true );
}



undefined4 tx_isp_suspend(void)

{
  return 0;
}



undefined4 tx_isp_resume(void)

{
  return 0;
}



void tx_isp_exit(void)

{
  private_platform_driver_unregister();
  private_platform_device_unregister();
  return;
}



void tx_isp_unregister_platforms(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (param_1[1] == 0) {
      iVar1 = *param_1;
    }
    else {
      (**(code **)(param_1[1] + 4))(*param_1);
      iVar1 = *param_1;
    }
    if (iVar1 != 0) {
      private_platform_device_unregister();
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 2;
  } while (iVar2 != 0x10);
  return;
}



int find_subdev_link_pad(int param_1,char **param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  
  iVar4 = 0;
  iVar5 = param_1;
  do {
    iVar5 = *(int *)(iVar5 + 0x3c);
    if (iVar5 != 0) {
      pcVar7 = *(char **)(iVar5 + 8);
      pcVar8 = *param_2;
      cVar2 = *pcVar7;
      do {
        cVar3 = *pcVar8;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
        cVar9 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar7;
        cVar9 = cVar3;
      } while (bVar1);
      if (cVar9 == cVar3) {
        if (*(char *)(param_2 + 1) == '\x01') {
          uVar6 = (uint)*(byte *)((int)param_2 + 5);
          if (uVar6 < *(ushort *)(iVar5 + 0xce)) {
            iVar5 = *(int *)(iVar5 + 0xd4);
            goto LAB_0001ccc0;
          }
        }
        else if ((*(char *)(param_2 + 1) == '\x02') &&
                (uVar6 = (uint)*(byte *)((int)param_2 + 5), uVar6 < *(ushort *)(iVar5 + 0xcc))) {
          iVar5 = *(int *)(iVar5 + 0xd0);
LAB_0001ccc0:
          return uVar6 * 0x24 + iVar5;
        }
        isp_printf();
        return 0;
      }
    }
    iVar4 = iVar4 + 4;
    if (iVar4 == 0x40) {
      return 0;
    }
    iVar5 = param_1 + iVar4;
  } while( true );
}



undefined4 tx_isp_get_ae_algo_handle(int param_1)

{
  undefined2 uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined auStack_b0 [4];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_4c;
  undefined4 local_44;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 0xd8);
  private_wait_for_completion_interruptible();
  memset((void *)(ae_info_mine + 8),0,2000);
  tisp_g_ae_zone((void *)(ae_info_mine + 8));
  tisp_g_ae_hist(ae_statis_mine);
  memcpy((void *)(ae_info_mine + 0x38c),ae_statis_mine,0x400);
  pvVar2 = ae_statis_mine;
  iVar3 = ae_info_mine;
  *(char *)(ae_info_mine + 0x78c) = (char)*(undefined4 *)((int)ae_statis_mine + 0x414);
  *(char *)(iVar3 + 0x78d) = (char)*(undefined4 *)((int)pvVar2 + 0x418);
  *(char *)(iVar3 + 0x78e) = (char)*(undefined4 *)((int)pvVar2 + 0x41c);
  *(char *)(iVar3 + 0x78f) = (char)*(undefined4 *)((int)pvVar2 + 0x420);
  uVar1 = *(undefined2 *)((int)pvVar2 + 0x400);
  *(char *)(iVar3 + 0x790) = (char)uVar1;
  *(char *)(iVar3 + 0x791) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)((int)pvVar2 + 0x404);
  *(char *)(iVar3 + 0x792) = (char)uVar1;
  *(char *)(iVar3 + 0x793) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)((int)pvVar2 + 0x408);
  *(char *)(iVar3 + 0x794) = (char)uVar1;
  *(char *)(iVar3 + 0x795) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)((int)pvVar2 + 0x40c);
  *(char *)(iVar3 + 0x796) = (char)uVar1;
  *(char *)(iVar3 + 0x797) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)((int)pvVar2 + 0x410);
  *(char *)(iVar3 + 0x798) = (char)uVar1;
  *(char *)(iVar3 + 0x799) = (char)((ushort)uVar1 >> 8);
  *(char *)(iVar3 + 0x79a) = (char)*(undefined4 *)((int)pvVar2 + 0x424);
  *(char *)(iVar3 + 0x79b) = (char)*(undefined4 *)((int)pvVar2 + 0x428);
  tisp_get_ae_attr(auStack_b0);
  iVar3 = ae_info_mine;
  *(undefined4 *)(ae_info_mine + 0x7a0) = local_a4;
  *(undefined4 *)(iVar3 + 0x7a4) = local_ac;
  *(undefined4 *)(iVar3 + 0x7a8) = local_a8;
  *(undefined4 *)(iVar3 + 0x7ac) = local_a0;
  *(undefined4 *)(iVar3 + 0x7b0) = local_64;
  *(undefined4 *)(iVar3 + 0x7b4) = local_68;
  *(undefined4 *)(iVar3 + 0x7b8) = local_4c;
  *(undefined4 *)(iVar3 + 0x7bc) = local_44;
  *(undefined4 *)(iVar3 + 0x7c0) = *(undefined4 *)(iVar5 + 0x180);
  *(uint *)(iVar3 + 0x7c4) = (uint)*(ushort *)(*(int *)(iVar5 + 0x124) + 0xb0);
  *(uint *)(iVar3 + 0x7c8) = (uint)*(ushort *)(*(int *)(iVar5 + 0x124) + 0xb2);
  *(undefined4 *)(iVar3 + 0x7cc) = *(undefined4 *)(iVar5 + 0x130);
  *(undefined4 *)(iVar3 + 2000) = *(undefined4 *)(iVar5 + 0x128);
  *(undefined4 *)(iVar3 + 0x7d4) = *(undefined4 *)(iVar5 + 300);
  iVar3 = private_copy_to_user();
  uVar4 = 0;
  if (iVar3 != 0) {
    isp_printf();
    uVar4 = 0xfffffff2;
  }
  return uVar4;
}



undefined4 isp_subdev_release_clks(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0xc0) != 0) {
    for (uVar1 = 0; uVar1 < *(uint *)(param_1 + 0xc4); uVar1 = uVar1 + 1) {
      private_clk_put();
    }
    private_kfree();
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  return 0;
}



uint isp_subdev_init_clks(int param_1,int param_2)

{
  uint *__s;
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xc4);
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  else {
    __s = (uint *)private_kmalloc();
    if (__s == (uint *)0x0) {
      isp_printf();
      return 0xfffffff4;
    }
    memset(__s,0,iVar4 << 2);
    iVar2 = 0;
    puVar3 = __s;
    do {
      uVar1 = private_clk_get();
      *puVar3 = uVar1;
      if (0xfffff000 < uVar1) {
        isp_printf();
        uVar1 = *puVar3;
LAB_0001d0e8:
        for (iVar4 = 0; iVar4 != iVar2; iVar4 = iVar4 + 1) {
          private_clk_put();
        }
        private_kfree();
        return uVar1;
      }
      if ((*(int *)(param_2 + 4) != 0xffff) && (uVar1 = private_clk_set_rate(), uVar1 != 0)) {
        isp_printf();
        goto LAB_0001d0e8;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 8;
      puVar3 = puVar3 + 1;
    } while (iVar2 != iVar4);
    *(uint **)(param_1 + 0xc0) = __s;
  }
  return 0;
}



undefined4 subdev_video_destroy_link(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[3] != 0) {
    iVar3 = *param_1;
    puVar1 = (undefined4 *)param_1[2];
    iVar2 = param_1[1];
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    *(undefined *)(iVar3 + 7) = 2;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
    }
    if (iVar2 != 0) {
      *(undefined *)(iVar2 + 7) = 2;
    }
  }
  return 0;
}



int tx_isp_video_link_destroy_isra_7(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x11c) < 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x11c) * 8;
  iVar6 = *(int *)(configs + iVar1);
  iVar5 = *(int *)(configs + iVar1 + 4);
  iVar1 = 0;
  do {
    while( true ) {
      if (iVar5 <= iVar1) {
        *(undefined4 *)(param_1 + 0x11c) = 0xffffffff;
        return 0;
      }
      ppcVar4 = (char **)(iVar1 * 0x14 + iVar6);
      iVar2 = find_subdev_link_pad(param_1,ppcVar4);
      iVar3 = find_subdev_link_pad(param_1,ppcVar4 + 2);
      if ((iVar2 != 0) && (iVar3 != 0)) break;
      iVar1 = iVar1 + 1;
    }
    subdev_video_destroy_link((int *)(iVar2 + 8));
    iVar2 = subdev_video_destroy_link((int *)(iVar3 + 8));
    iVar1 = iVar1 + 1;
  } while ((iVar2 == 0) || (iVar2 == -0x203));
  return iVar2;
}



int tx_isp_release(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_2 + 0x78);
  iVar5 = 0;
  if (*(int *)(iVar4 + 0x10c) == 0) {
    iVar1 = 0;
    iVar3 = iVar4 + -0xc;
    do {
      if (*(int *)(iVar3 + 0x3c) != 0) {
        iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x3c) + 200) + 0x10);
        if ((iVar3 != 0) && (pcVar2 = *(code **)(iVar3 + 4), pcVar2 != (code *)0x0)) {
          iVar1 = (*pcVar2)();
          if (iVar1 == 0) goto LAB_0001d3f0;
          if (iVar1 != -0x203) {
            return iVar1;
          }
        }
        iVar1 = -0x203;
      }
LAB_0001d3f0:
      iVar5 = iVar5 + 4;
      iVar3 = iVar4 + -0xc + iVar5;
    } while (iVar5 != 0x40);
    if (iVar1 == -0x203) {
      iVar5 = *(int *)(iVar4 + 0x110);
    }
    else {
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar5 = *(int *)(iVar4 + 0x110);
    }
    if (-1 < iVar5) {
      tx_isp_video_link_destroy_isra_7(iVar4 + -0xc);
    }
  }
  else {
    *(int *)(iVar4 + 0x10c) = *(int *)(iVar4 + 0x10c) + -1;
  }
  return 0;
}



// WARNING: Type propagation algorithm not settling
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int tx_isp_unlocked_ioctl(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  char **ppcVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  int local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38 [2];
  int local_30;
  
  iVar12 = *(int *)(param_1 + 0x78);
  iVar7 = iVar12 + -0xc;
  if (param_2 == 0x800856d4) {
    iVar12 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
    iVar7 = private_copy_from_user();
    if (iVar7 == 0) {
      uVar6 = *(int *)(iVar12 + 0xf0) + 7U & 0xfffffff8;
      uVar11 = uVar6 * *(int *)(iVar12 + 0xf4);
      system_reg_write(0x7820,local_a0);
      system_reg_write(0x7824,uVar6);
      if (uVar11 <= local_9c) {
        iVar7 = *(int *)(iVar12 + 0xf4);
        uVar6 = *(int *)(iVar12 + 0xf0) + 7U & 0xfffffff8;
        system_reg_write(0x7828,uVar11 + local_a0);
        system_reg_write(0x782c,uVar6);
        uVar11 = (uVar6 * iVar7 >> 1) + uVar11;
        if (uVar11 <= local_9c) {
          iVar7 = *(int *)(iVar12 + 0xf4);
          uVar6 = (*(int *)(iVar12 + 0xf0) + 0x1fU >> 5) + 7 & 0xfffffff8;
          system_reg_write(0x7830,uVar11 + local_a0);
          system_reg_write(0x7834,uVar6);
          iVar7 = uVar6 * ((iVar7 + 0xfU >> 4) + 1);
          if (isp_memopt == 0) {
            system_reg_write(0x7840,uVar11 + iVar7 + local_a0);
            system_reg_write(0x7844,uVar6);
            system_reg_write(0x7848,uVar11 + local_a0 + iVar7 * 2);
            system_reg_write(0x784c,uVar6);
            iVar9 = iVar7 * 3;
            iVar7 = iVar7 * 4;
            system_reg_write(0x7850,iVar9 + uVar11 + local_a0);
            system_reg_write(0x7854,uVar6);
          }
          else {
            system_reg_write(0x7840,uVar11 + local_a0);
            system_reg_write(0x7844,0);
            system_reg_write(0x7848,uVar11 + local_a0);
            system_reg_write(0x784c,0);
            system_reg_write(0x7850,uVar11 + local_a0);
            system_reg_write(0x7854,0);
          }
          system_reg_write(0x7838,0);
          system_reg_write(0x783c,1);
          uVar11 = iVar7 + uVar11;
          if (uVar11 <= local_9c) {
            if (isp_memopt == 0) {
              iVar7 = *(int *)(iVar12 + 0xf4);
              uVar6 = (*(uint *)(iVar12 + 0xf0) >> 1) + 7 & 0xfffffff8;
              system_reg_write(0x7858,uVar11 + local_a0);
              system_reg_write(0x785c,uVar6);
              uVar11 = uVar11 + uVar6 * iVar7;
              if (local_9c < uVar11) goto LAB_0001d734;
              iVar7 = *(int *)(iVar12 + 0xf4);
              uVar6 = (*(uint *)(iVar12 + 0xf0) >> 1) + 7 & 0xfffffff8;
              system_reg_write(0x7860,uVar11 + local_a0);
              system_reg_write(0x7864,uVar6);
              uVar11 = uVar11 + (uVar6 * iVar7 >> 1);
              if (local_9c < uVar11) goto LAB_0001d734;
              iVar7 = *(int *)(iVar12 + 0xf4);
              uVar6 = (*(uint *)(iVar12 + 0xf0) >> 5) + 7 & 0xfffffff8;
              system_reg_write(0x7868,uVar11 + local_a0);
              system_reg_write(0x786c,uVar6);
              uVar11 = uVar11 + (uVar6 * iVar7 >> 5);
            }
            else {
              system_reg_write(0x7858,local_a0);
              system_reg_write(0x785c,0);
              system_reg_write(0x7860,local_a0);
              system_reg_write(0x7864,0);
              system_reg_write(0x7868,local_a0);
              system_reg_write(0x786c,0);
            }
            if (uVar11 <= local_9c) {
              return 0;
            }
          }
        }
      }
    }
    goto LAB_0001d734;
  }
  if (0x800856d4 < param_2) {
    if (param_2 == 0xc0045627) {
      iVar9 = private_copy_from_user();
      iVar1 = 0;
      iVar12 = iVar7;
      if (iVar9 != 0) goto LAB_0001d734;
      while( true ) {
        iVar12 = *(int *)(iVar12 + 0x3c);
        if ((((iVar12 != 0) && (iVar9 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar9 != 0)) &&
            (pcVar2 = *(code **)(iVar9 + 8), pcVar2 != (code *)0x0)) &&
           ((iVar12 = (*pcVar2)(iVar12,0x2000004,local_38), iVar12 != 0 && (iVar12 != -0x203)))) {
          return iVar12;
        }
        iVar1 = iVar1 + 4;
        if (iVar1 == 0x40) break;
        iVar12 = iVar7 + iVar1;
      }
      iVar7 = private_copy_to_user();
    }
    else if (param_2 < 0xc0045628) {
      if (param_2 == 0x800856d7) {
        iVar7 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
        local_a0 = 0;
        local_9c = 0;
        iVar12 = *(int *)(*(int *)(iVar7 + 0x124) + 0x90);
        if (iVar12 == 1) {
          local_9c = *(int *)(iVar7 + 0x128) * *(int *)(iVar7 + 300) * 2;
        }
        else if (iVar12 == 2) {
          local_9c = *(uint *)(*(int *)(iVar7 + 0x124) + 0xe8);
        }
        else {
          isp_printf();
        }
        isp_printf();
        iVar7 = private_copy_to_user();
        if (iVar7 != 0) {
          isp_printf();
          return -0xe;
        }
        return 0;
      }
      if (0x800856d7 < param_2) {
        if (param_2 == 0x805056c1) {
          iVar9 = private_copy_from_user();
          iVar1 = 0;
          iVar12 = iVar7;
          if (iVar9 == 0) {
            while (((iVar12 = *(int *)(iVar12 + 0x3c), iVar12 == 0 ||
                    (iVar9 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar9 == 0)) ||
                   ((pcVar2 = *(code **)(iVar9 + 8), pcVar2 == (code *)0x0 ||
                    ((iVar12 = (*pcVar2)(iVar12,0x2000000,&local_a0), iVar12 == 0 ||
                     (iVar12 == -0x203))))))) {
              iVar1 = iVar1 + 4;
              iVar12 = iVar7 + iVar1;
              if (iVar1 == 0x40) {
                return 0;
              }
            }
            return iVar12;
          }
        }
        else if (param_2 == 0x805056c2) {
          iVar9 = private_copy_from_user();
          iVar1 = 0;
          iVar12 = iVar7;
          if (iVar9 == 0) {
            while ((((iVar12 = *(int *)(iVar12 + 0x3c), iVar12 == 0 ||
                     (iVar9 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar9 == 0)) ||
                    (pcVar2 = *(code **)(iVar9 + 8), pcVar2 == (code *)0x0)) ||
                   ((iVar12 = (*pcVar2)(iVar12,0x2000001,&local_a0), iVar12 == 0 ||
                    (iVar12 == -0x203))))) {
              iVar1 = iVar1 + 4;
              iVar12 = iVar7 + iVar1;
              if (iVar1 == 0x40) {
                return 0;
              }
            }
            return iVar12;
          }
        }
        else {
          if (param_2 != 0x8038564f) {
            return 0;
          }
          iVar12 = private_copy_from_user();
          if (iVar12 == 0) {
            local_44 = local_74;
            local_48 = local_78;
            local_3c = local_6c;
            local_40 = local_70;
            iVar9 = 0;
            iVar12 = iVar7;
            local_50 = &local_9c;
            while (((iVar12 = *(int *)(iVar12 + 0x3c), iVar12 == 0 ||
                    (iVar1 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar1 == 0)) ||
                   ((pcVar2 = *(code **)(iVar1 + 8), pcVar2 == (code *)0x0 ||
                    ((iVar12 = (*pcVar2)(iVar12,0x2000011,&local_50), iVar12 == 0 ||
                     (iVar12 == -0x203))))))) {
              iVar9 = iVar9 + 4;
              iVar12 = iVar7 + iVar9;
              if (iVar9 == 0x40) {
                return 0;
              }
            }
            return iVar12;
          }
        }
        goto LAB_0001d734;
      }
      if (param_2 != 0x800856d5) {
        if (param_2 != 0x800856d6) {
          return 0;
        }
        iVar12 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
        iVar7 = private_copy_from_user();
        if (iVar7 != 0) {
          isp_printf();
          return -0xe;
        }
        isp_printf();
        iVar7 = *(int *)(*(int *)(iVar12 + 0x124) + 0x90);
        if (iVar7 == 1) {
          uVar6 = *(uint *)(iVar12 + 300);
          uVar11 = uVar6 * *(int *)(iVar12 + 0x128) * 2;
        }
        else {
          if (iVar7 != 2) {
            isp_printf();
            return -1;
          }
          uVar11 = *(uint *)(*(int *)(iVar12 + 0x124) + 0xe8);
          uVar6 = uVar11 / (uint)(*(int *)(iVar12 + 0x128) << 1);
        }
        isp_printf();
        if (uVar11 <= local_9c) {
          system_reg_write(0x2004,local_a0);
          system_reg_write(0x2008,*(int *)(iVar12 + 0x128) << 1);
          system_reg_write(0x200c,uVar6);
          return 0;
        }
        isp_printf();
        *(undefined4 *)(iVar12 + 0x180) = 0;
        tisp_s_wdr_en(0);
        return -0xe;
      }
      iVar7 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
      uVar11 = *(uint *)(iVar7 + 0xf0);
      iVar12 = *(int *)(iVar7 + 0xf4);
      iVar7 = iVar12 * 8;
      uVar6 = (uVar11 + 7 >> 3) * iVar7;
      iVar12 = ((iVar12 + 0xfU >> 4) + 1) * 8 * ((uVar11 + 0x1f >> 5) + 7 >> 3);
      iVar9 = (uVar6 >> 1) + uVar6;
      local_9c = iVar12 + iVar9;
      if (isp_memopt == 0) {
        uVar6 = ((uVar11 >> 1) + 7 >> 3) * iVar7;
        local_9c = iVar9 + (uVar6 >> 1) + uVar6 + (((uVar11 >> 5) + 7 >> 3) * iVar7 >> 5) +
                   iVar12 * 4;
      }
      local_a0 = 0;
      iVar7 = private_copy_to_user();
    }
    else {
      if (param_2 == 0xc00456e3) {
        tisp_awb_algo_init(1);
        awb_info_mine = (int *)kmem_cache_alloc(_DAT_000da0a8,0x24000c0);
        awb_algo_comp = 0;
        __init_waitqueue_head(&DAT_000b3ef8,"&x->wait",0x10000);
        return 0;
      }
      if (param_2 < 0xc00456e4) {
        if (param_2 != 0xc00456e1) {
          if (param_2 != 0xc00456e2) {
            return 0;
          }
          iVar7 = private_copy_from_user();
          if (iVar7 == 0) {
            if (local_98 != 1) {
              return 0;
            }
            piVar5 = &local_a0;
            pcVar2 = tisp_awb_algo_handle;
LAB_0001eba8:
            (*pcVar2)(piVar5);
            return 0;
          }
          goto LAB_0001d734;
        }
        private_wait_for_completion_interruptible();
        memset(awb_info_mine + 2,0,699);
        tisp_g_wb_zone(awb_info_mine + 8);
        tisp_g_wb_attr(&local_a0);
        piVar5 = awb_info_mine;
        awb_info_mine[4] = local_94;
        piVar5[5] = local_90;
        piVar5[6] = local_8c;
        piVar5[7] = local_88;
        piVar5[2] = local_9c;
        piVar5[3] = local_98;
        iVar7 = private_copy_to_user();
      }
      else if (param_2 == 0xc0385650) {
        iVar12 = private_copy_from_user();
        if (iVar12 != 0) goto LAB_0001d734;
        local_44 = local_74;
        local_48 = local_78;
        iVar9 = 0;
        iVar12 = iVar7;
        local_50 = &local_9c;
        while( true ) {
          iVar12 = *(int *)(iVar12 + 0x3c);
          if ((((iVar12 != 0) && (iVar1 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar1 != 0)) &&
              (pcVar2 = *(code **)(iVar1 + 8), pcVar2 != (code *)0x0)) &&
             ((iVar12 = (*pcVar2)(iVar12,0x2000012,&local_50), iVar12 != 0 && (iVar12 != -0x203))))
          {
            return iVar12;
          }
          iVar9 = iVar9 + 4;
          if (iVar9 == 0x40) break;
          iVar12 = iVar7 + iVar9;
        }
        local_70 = local_40;
        local_7c = local_4c;
        local_6c = local_3c;
        iVar7 = private_copy_to_user();
      }
      else {
        if (param_2 != 0xc050561a) {
          if (param_2 != 0xc00456e4) {
            return 0;
          }
          iVar7 = private_copy_from_user();
          if (iVar7 == 0) {
            tisp_awb_algo_deinit();
            tisp_awb_algo_init(0);
            pcVar2 = private_kfree;
            piVar5 = awb_info_mine;
            goto LAB_0001eba8;
          }
          goto LAB_0001d734;
        }
        iVar9 = private_copy_from_user();
        iVar1 = 0;
        iVar12 = iVar7;
        if (iVar9 != 0) goto LAB_0001d734;
        while( true ) {
          iVar12 = *(int *)(iVar12 + 0x3c);
          if (((iVar12 != 0) && (iVar9 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar9 != 0)) &&
             ((pcVar2 = *(code **)(iVar9 + 8), pcVar2 != (code *)0x0 &&
              ((iVar12 = (*pcVar2)(iVar12,0x2000002,&local_a0), iVar12 != 0 && (iVar12 != -0x203))))
             )) {
            return iVar12;
          }
          iVar1 = iVar1 + 4;
          if (iVar1 == 0x40) break;
          iVar12 = iVar7 + iVar1;
        }
        iVar7 = private_copy_to_user();
      }
    }
joined_r0x0001d7d0:
    if (iVar7 == 0) {
      return 0;
    }
LAB_0001d734:
    isp_printf();
    return -0xe;
  }
  if (param_2 == 0x800456d3) {
    param_3 = 0;
LAB_0001dc60:
    pcVar2 = tx_isp_video_link_stream;
  }
  else {
    if (0x800456d3 < param_2) {
      if (param_2 != 0x800456db) {
        if (param_2 < 0x800456dc) {
          if (param_2 == 0x800456d8) {
            local_38[0] = 1;
            iVar7 = *(int *)(iVar12 + 0x30);
            iVar12 = *(int *)(iVar7 + 0xd8);
            if (*(int *)(iVar12 + 0x180) == 1) {
              return 0;
            }
            *(undefined4 *)(iVar12 + 0x180) = 1;
            if (wdr_switch != 0) {
              if ((iVar7 != 0) && (*(code **)(iVar7 + 0x80) != (code *)0x0)) {
                (**(code **)(iVar7 + 0x80))(iVar7,0x2000013,local_38);
              }
              tisp_s_wdr_en(local_38[0]);
              if (iVar7 == 0) {
                iVar7 = *(int *)(iVar12 + 0x124);
              }
              else {
                if (*(code **)(iVar7 + 0x80) != (code *)0x0) {
                  (**(code **)(iVar7 + 0x80))(iVar7,0x200000c,local_38);
                }
                iVar7 = *(int *)(iVar12 + 0x124);
              }
              *(undefined4 *)(iVar7 + 0xac) = 0;
              *(undefined4 *)(iVar7 + 0xdc) = 0;
              *(undefined4 *)(iVar7 + 0x9c) = 0;
              *(undefined4 *)(iVar7 + 0xe4) = 0;
              *(undefined4 *)(iVar7 + 0xa0) = 0;
            }
          }
          else {
            if (param_2 != 0x800456d9) {
              return 0;
            }
            local_38[0] = 0;
            iVar12 = *(int *)(iVar12 + 0x30);
            iVar7 = *(int *)(iVar12 + 0xd8);
            iVar9 = *(int *)(iVar7 + 0x124);
            if (*(int *)(iVar7 + 0x180) == 0) {
              return 0;
            }
            *(undefined4 *)(iVar7 + 0x180) = 0;
            if (wdr_switch != 0) {
              if ((iVar12 != 0) && (*(code **)(iVar12 + 0x80) != (code *)0x0)) {
                (**(code **)(iVar12 + 0x80))(iVar12,0x2000013,local_38);
              }
              tisp_s_wdr_en(local_38[0]);
              if (iVar12 == 0) {
                *(undefined4 *)(iVar9 + 0xac) = 0;
              }
              else {
                if (*(code **)(iVar12 + 0x80) != (code *)0x0) {
                  (**(code **)(iVar12 + 0x80))(iVar12,0x200000c,local_38);
                }
                *(undefined4 *)(iVar9 + 0xac) = 0;
              }
              *(undefined4 *)(iVar9 + 0xdc) = 0;
              *(undefined4 *)(iVar9 + 0x9c) = 0;
              *(undefined4 *)(iVar9 + 0xe4) = 0;
              *(undefined4 *)(iVar9 + 0xa0) = 0;
            }
          }
          wdr_switch = 1;
          return 0;
        }
        if (param_2 == 0x800456dd) {
          piVar5 = (int *)kmem_cache_alloc(_DAT_000da09c,0x24000c0);
          iVar12 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
          iVar7 = private_copy_from_user();
          if (iVar7 == 0) {
            if (*piVar5 != 0x336ac) {
              isp_printf();
              return -1;
            }
            iVar7 = *(int *)(iVar12 + 0x124);
            tisp_ae_algo_init(1,(int)piVar5);
            piVar5[0x1b] = *(int *)(iVar12 + 0x130);
            piVar5[3] = *(int *)(iVar7 + 0xac);
            uVar11 = private_math_exp2(*(uint *)(iVar7 + 0x9c),0x10,10);
            piVar5[4] = uVar11;
            piVar5[5] = 0x400;
            piVar5[0xf] = *(int *)(iVar7 + 0xdc);
            uVar11 = private_math_exp2(*(uint *)(iVar7 + 0xe4),0x10,10);
            piVar5[0x10] = uVar11;
            piVar5[0x11] = 0x400;
            if (*(int *)(iVar12 + 0x180) == 0) {
              uVar11 = system_reg_read(0x1030);
              piVar5[6] = uVar11 & 0xffff;
            }
            else {
              uVar11 = system_reg_read(0x1000);
              piVar5[6] = uVar11 & 0xffff;
              uVar11 = system_reg_read(0x100c);
              piVar5[0x12] = uVar11 & 0xffff;
            }
            ae_info_mine = kmem_cache_alloc(_DAT_000da0ac,0x24000c0);
            ae_statis_mine = kmem_cache_alloc(_DAT_000da0ac,0x24000c0);
            ae_algo_comp = 0;
            __init_waitqueue_head(&DAT_000b3f04,"&x->wait",0x10000);
            iVar7 = private_copy_to_user();
            if (iVar7 == 0) {
              private_kfree();
              *(undefined4 *)(iVar12 + 0x1dc) = 1;
              return 0;
            }
          }
        }
        else if (param_2 < 0x800456dd) {
          iVar7 = private_copy_from_user();
          if (iVar7 == 0) {
            if (local_98 != 1) {
              return 0;
            }
            pcVar2 = tisp_ae_algo_handle;
            piVar5 = &local_a0;
            goto LAB_0001eba8;
          }
        }
        else {
          if (param_2 != 0x800456de) {
            return 0;
          }
          iVar12 = *(int *)(*(int *)(iVar12 + 0x30) + 0xd8);
          iVar7 = private_copy_from_user();
          if (iVar7 == 0) {
            tisp_ae_algo_deinit();
            tisp_ae_algo_init(0,0);
            private_kfree();
            private_kfree();
            *(undefined4 *)(iVar12 + 0x1dc) = 0;
            return 0;
          }
        }
        goto LAB_0001d734;
      }
      pcVar2 = tx_isp_get_ae_algo_handle;
      goto LAB_0001e6b8;
    }
    if (param_2 == 0x80045613) {
      param_3 = 0;
    }
    else {
      if (0x80045613 < param_2) {
        if (param_2 == 0x800456d1) {
          iVar7 = tx_isp_video_link_destroy_isra_7(iVar7);
          return iVar7;
        }
        if (param_2 < 0x800456d2) {
          if (param_2 != 0x800456d0) {
            return 0;
          }
          iVar9 = private_copy_from_user();
          if (iVar9 == 0) {
            if ((local_38[0] < 0) || (1 < local_38[0])) {
              isp_printf();
              return -0x16;
            }
            if (*(int *)(iVar12 + 0x110) == local_38[0]) {
              return 0;
            }
            local_30 = *(int *)(configs + local_38[0] * 8 + 4);
            ppcVar8 = *(char ***)(configs + local_38[0] * 8);
            iVar9 = 0;
            do {
              if (local_30 <= iVar9) {
                *(int *)(iVar12 + 0x110) = local_38[0];
                return 0;
              }
              iVar1 = find_subdev_link_pad(iVar7,ppcVar8);
              iVar3 = find_subdev_link_pad(iVar7,ppcVar8 + 2);
              if ((iVar1 != 0) && (iVar3 != 0)) {
                pcVar10 = ppcVar8[4];
                if (((uint)pcVar10 & (uint)(*(byte *)(iVar3 + 6) & *(byte *)(iVar1 + 6))) == 0) {
                  isp_printf();
                  return -1;
                }
                if ((*(char *)(iVar1 + 7) == '\x04') || (*(char *)(iVar3 + 7) == '\x04')) {
                  isp_printf();
                  return -1;
                }
                if ((((*(char *)(iVar1 + 7) == '\x03') && (*(int *)(iVar1 + 0xc) != iVar3)) &&
                    (iVar4 = subdev_video_destroy_link((int *)(iVar1 + 8)), iVar4 != 0)) ||
                   (((*(char *)(iVar3 + 7) == '\x03' && (*(int *)(iVar3 + 0xc) != iVar1)) &&
                    (iVar4 = subdev_video_destroy_link((int *)(iVar3 + 8)), iVar4 != 0)))) {
                  if (iVar4 != -0x203) {
                    return iVar4;
                  }
                }
                else {
                  *(int *)(iVar1 + 0x10) = iVar3 + 8;
                  uVar11 = (uint)pcVar10 | 1;
                  *(int *)(iVar1 + 8) = iVar1;
                  *(int *)(iVar1 + 0xc) = iVar3;
                  *(uint *)(iVar1 + 0x14) = uVar11;
                  *(undefined *)(iVar1 + 7) = 3;
                  *(int *)(iVar3 + 8) = iVar3;
                  *(int *)(iVar3 + 0xc) = iVar1;
                  *(int *)(iVar3 + 0x10) = iVar1 + 8;
                  *(uint *)(iVar3 + 0x14) = uVar11;
                  *(undefined *)(iVar3 + 7) = 3;
                }
              }
              iVar9 = iVar9 + 1;
              ppcVar8 = ppcVar8 + 5;
            } while( true );
          }
          goto LAB_0001d734;
        }
        param_3 = 1;
        goto LAB_0001dc60;
      }
      if (param_2 == 0x40045626) {
        iVar9 = 0;
        iVar12 = iVar7;
        while( true ) {
          iVar12 = *(int *)(iVar12 + 0x3c);
          if (((iVar12 != 0) && (iVar1 = *(int *)(*(int *)(iVar12 + 200) + 0xc), iVar1 != 0)) &&
             ((pcVar2 = *(code **)(iVar1 + 8), pcVar2 != (code *)0x0 &&
              ((iVar12 = (*pcVar2)(iVar12,0x2000003,local_38), iVar12 != 0 && (iVar12 != -0x203)))))
             ) {
            return iVar12;
          }
          iVar9 = iVar9 + 4;
          if (iVar9 == 0x40) break;
          iVar12 = iVar7 + iVar9;
        }
        iVar7 = private_copy_to_user();
        goto joined_r0x0001d7d0;
      }
      if (param_2 != 0x80045612) {
        return 0;
      }
      param_3 = 1;
    }
    pcVar2 = tx_isp_video_s_stream;
  }
LAB_0001e6b8:
  iVar7 = (*pcVar2)(iVar7,param_3);
  return iVar7;
}



int tx_isp_init(void)

{
  int iVar1;
  
  iVar1 = private_platform_device_register();
  if (iVar1 == 0) {
    iVar1 = private_platform_driver_register();
    if (iVar1 != 0) {
      private_platform_device_unregister();
    }
  }
  else {
    isp_printf();
  }
  return iVar1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 private_reset_tx_isp_module(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    return 0;
  }
  iVar1 = 500;
  _DAT_b00000c4 = _DAT_b00000c4 | 0x200000;
  do {
    if ((_DAT_b00000c4 & 0x100000) != 0) {
      _DAT_b00000c4 = _DAT_b00000c4 & 0xff9fffff;
      return 0;
    }
    iVar1 = iVar1 + -1;
    private_msleep();
  } while (iVar1 != 0);
  return 0xffffffff;
}



undefined4 tx_isp_reg_set(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = 0;
  for (iVar1 = 0; iVar1 < (int)((param_4 - param_3) + 1); iVar1 = iVar1 + 1) {
    uVar2 = uVar2 + (1 << (iVar1 + param_3 & 0x1f));
  }
  puVar3 = (uint *)(*(int *)(param_1 + 0xbc) + param_2);
  *puVar3 = ~uVar2 & *puVar3 | param_5 << (param_3 & 0x1f);
  return 0;
}



undefined4 tx_isp_send_event_to_remote(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0xc) + 0x1c),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x0001edd4. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xfffffdfd;
}



undefined4 tx_isp_module_init(undefined4 *param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (void *)0x0) {
    isp_printf();
    uVar1 = 0xffffffea;
  }
  else {
    if ((param_1 != (undefined4 *)0x0) && ((void *)param_1[0x16] != (void *)0x0)) {
      memcpy(param_2,(void *)param_1[0x16],4);
    }
    *(undefined4 *)((int)param_2 + 0x7c) = 0;
    memset((void *)((int)param_2 + 0x3c),0,0x40);
    uVar1 = *param_1;
    *(undefined4 *)((int)param_2 + 0x34) = 0;
    *(undefined4 *)((int)param_2 + 8) = uVar1;
    *(code **)((int)param_2 + 0x80) = tx_isp_notify;
    *(undefined4 *)((int)param_2 + 0x38) = 0;
    *(undefined4 **)((int)param_2 + 4) = param_1 + 4;
    uVar1 = 0;
  }
  return uVar1;
}



void tx_isp_module_deinit(void *param_1)

{
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x84);
    return;
  }
  return;
}



void tx_isp_subdev_deinit(void *param_1)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + 0x34) != 0) {
    private_misc_deregister();
  }
  isp_subdev_release_clks((int)param_1);
  if (*(int *)((int)param_1 + 0xd0) != 0) {
    private_kfree();
  }
  if (*(int *)((int)param_1 + 0xd4) != 0) {
    private_kfree();
  }
  if (*(int *)((int)param_1 + 0xbc) != 0) {
    private_iounmap();
  }
  if (*(int *)((int)param_1 + 0xb8) == 0) {
    iVar1 = *(int *)((int)param_1 + 0x84);
  }
  else {
    private_release_mem_region();
    *(undefined4 *)((int)param_1 + 0xb8) = 0;
    iVar1 = *(int *)((int)param_1 + 0x84);
  }
  if (iVar1 != 0) {
    tx_isp_free_irq((int *)((int)param_1 + 0x84));
  }
  tx_isp_module_deinit(param_1);
  *(undefined4 *)((int)param_1 + 200) = 0;
  return;
}



uint tx_isp_subdev_init(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  void **ppvVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  char *pcVar13;
  void *__s;
  uint uVar14;
  void *__s_00;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (void *)0x0)) {
    isp_printf();
    return 0xffffffea;
  }
  *(undefined4 *)((int)param_2 + 200) = param_3;
  iVar5 = tx_isp_module_init(param_1,param_2);
  if (iVar5 != 0) {
    isp_printf();
    return 0xfffffff4;
  }
  pcVar13 = (char *)param_1[0x16];
  if (pcVar13 == (char *)0x0) {
    return 0;
  }
  uVar6 = tx_isp_request_irq((int)param_1,(int *)((int)param_2 + 0x84));
  uVar14 = 0;
  if (uVar6 != 0) {
    isp_printf();
    goto LAB_0001f4e4;
  }
  for (; uVar14 < (uint)param_1[0x5a]; uVar14 = uVar14 + 1) {
    iVar5 = private_platform_get_resource();
    if (iVar5 != 0) {
      pcVar8 = *(char **)(iVar5 + 8);
      cVar2 = *pcVar8;
      pcVar9 = "isp-device";
      do {
        cVar3 = *pcVar9;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
        cVar11 = cVar2;
        if (cVar3 != cVar2) break;
        bVar1 = cVar2 != '\0';
        cVar2 = *pcVar8;
        cVar11 = cVar3;
      } while (bVar1);
      if (cVar11 == cVar3) {
        iVar5 = private_request_mem_region();
        if (iVar5 == 0) {
          isp_printf();
          uVar6 = 0xfffffff0;
          goto LAB_0001f4d0;
        }
        iVar10 = private_ioremap();
        *(int *)((int)param_2 + 0xbc) = iVar10;
        if (iVar10 != 0) goto LAB_0001f19c;
        isp_printf();
        uVar6 = 0xfffffffa;
        goto LAB_0001f4b4;
      }
    }
  }
  iVar5 = 0;
LAB_0001f19c:
  *(int *)((int)param_2 + 0xb8) = iVar5;
  if (*pcVar13 == '\x01') {
    *(uint *)((int)param_2 + 0xc4) = (uint)(byte)pcVar13[4];
    uVar6 = isp_subdev_init_clks((int)param_2,*(int *)(pcVar13 + 8));
    iVar5 = 0;
    if (uVar6 != 0) {
      isp_printf();
      goto LAB_0001f480;
    }
    for (; iVar5 < (int)(uint)(byte)pcVar13[0xc]; iVar5 = iVar5 + 1) {
      if (*(char *)(*(int *)(pcVar13 + 0x10) + iVar5 * 2) == '\x02') {
        *(short *)((int)param_2 + 0xcc) = *(short *)((int)param_2 + 0xcc) + 1;
      }
      else {
        *(short *)((int)param_2 + 0xce) = *(short *)((int)param_2 + 0xce) + 1;
      }
    }
    __s = (void *)0x0;
    if (*(short *)((int)param_2 + 0xcc) == 0) {
LAB_0001f320:
      __s_00 = (void *)0x0;
      if (*(short *)((int)param_2 + 0xce) == 0) {
LAB_0001f418:
        *(void **)((int)param_2 + 0xd0) = __s;
        *(void **)((int)param_2 + 0xd4) = __s_00;
        return 0;
      }
      __s_00 = (void *)private_kmalloc();
      if (__s != (void *)0x0) {
        memset(__s_00,0,(uint)*(ushort *)((int)param_2 + 0xce) * 0x24);
        iVar10 = 0;
        iVar5 = 0;
        while (iVar5 < (int)(uint)(byte)pcVar13[0xc]) {
          iVar12 = iVar5 * 2;
          iVar5 = iVar5 + 1;
          if (*(char *)(*(int *)(pcVar13 + 0x10) + iVar12) == '\x01') {
            ppvVar7 = (void **)(iVar10 * 0x24 + (int)__s_00);
            *(char *)(ppvVar7 + 1) = (char)iVar10;
            *ppvVar7 = param_2;
            iVar10 = iVar10 + 1;
            *(undefined *)((int)ppvVar7 + 5) = *(undefined *)(*(int *)(pcVar13 + 0x10) + iVar12);
            uVar4 = *(undefined *)(*(int *)(pcVar13 + 0x10) + iVar12 + 1);
            *(undefined *)((int)ppvVar7 + 7) = 2;
            ppvVar7[5] = (void *)0x0;
            *(undefined *)((int)ppvVar7 + 6) = uVar4;
          }
        }
        goto LAB_0001f418;
      }
      isp_printf();
      private_kfree();
    }
    else {
      __s = (void *)private_kmalloc();
      if (__s != (void *)0x0) {
        memset(__s,0,(uint)*(ushort *)((int)param_2 + 0xcc) * 0x24);
        iVar10 = 0;
        iVar5 = 0;
        while (iVar5 < (int)(uint)(byte)pcVar13[0xc]) {
          iVar12 = iVar5 * 2;
          iVar5 = iVar5 + 1;
          if (*(char *)(*(int *)(pcVar13 + 0x10) + iVar12) == '\x02') {
            ppvVar7 = (void **)(iVar10 * 0x24 + (int)__s);
            *(char *)(ppvVar7 + 1) = (char)iVar10;
            *ppvVar7 = param_2;
            iVar10 = iVar10 + 1;
            *(undefined *)((int)ppvVar7 + 5) = *(undefined *)(*(int *)(pcVar13 + 0x10) + iVar12);
            uVar4 = *(undefined *)(*(int *)(pcVar13 + 0x10) + iVar12 + 1);
            *(undefined *)((int)ppvVar7 + 7) = 2;
            ppvVar7[5] = (void *)0x0;
            *(undefined *)((int)ppvVar7 + 6) = uVar4;
          }
        }
        goto LAB_0001f320;
      }
      isp_printf();
    }
    isp_subdev_release_clks((int)param_2);
    uVar6 = 0xfffffff4;
  }
  else {
    if (*pcVar13 != '\x02') {
      isp_printf();
      return 0;
    }
    *(uint *)((int)param_2 + 0xc4) = (uint)(byte)pcVar13[4];
    uVar6 = isp_subdev_init_clks((int)param_2,*(int *)(pcVar13 + 8));
LAB_0001f480:
    if (uVar6 == 0) {
      return 0;
    }
  }
  isp_printf();
  private_iounmap();
LAB_0001f4b4:
  private_release_mem_region();
LAB_0001f4d0:
  tx_isp_free_irq((int *)((int)param_2 + 0x84));
LAB_0001f4e4:
  tx_isp_module_deinit(param_2);
  return uVar6;
}



undefined4 tx_isp_create_graph_and_nodes(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  while (uVar4 < *(uint *)(param_1 + 0x84)) {
    pcVar1 = (char *)private_platform_get_drvdata();
    if (pcVar1 == (char *)0x0 || (char *)0xfffff000 < pcVar1) {
      isp_printf();
      uVar4 = uVar4 + 1;
    }
    else {
      uVar4 = uVar4 + 1;
      if (*pcVar1 == '\x01') {
        *(char **)(param_1 + (((byte)pcVar1[3] & 0xf) + 0xe) * 4 + 4) = pcVar1;
      }
    }
  }
  uVar4 = 0;
LAB_0001f6ac:
  do {
    if (*(uint *)(param_1 + 0x84) <= uVar4) {
LAB_0001f680:
      uVar4 = 0;
      do {
        if (*(uint *)(param_1 + 0x84) <= uVar4) {
          return 0;
        }
        iVar2 = private_platform_get_drvdata();
        if (*(int *)(iVar2 + 0x34) == 0) {
          iVar2 = *(int *)(iVar2 + 0x38);
        }
        else {
          *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x34);
          *(undefined4 *)(iVar2 + 0xc) = 0xff;
          *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar2 + 8);
          iVar3 = private_misc_register();
          if (iVar3 < 0) {
            isp_printf();
            while (uVar4 = uVar4 - 1, uVar4 != 0xffffffff) {
              iVar2 = private_platform_get_drvdata();
              if (*(int *)(iVar2 + 0x34) != 0) {
                private_misc_deregister();
              }
            }
            return 0xfffffffe;
          }
          iVar2 = *(int *)(iVar2 + 0x38);
        }
        if (iVar2 != 0) {
          private_proc_create_data();
        }
        uVar4 = uVar4 + 1;
      } while( true );
    }
    pcVar1 = (char *)private_platform_get_drvdata();
    if (*pcVar1 != '\x02') {
      uVar4 = uVar4 + 1;
      goto LAB_0001f6ac;
    }
    iVar2 = *(int *)(param_1 + (((byte)pcVar1[2] & 0xf) + 0xe) * 4 + 4);
    if (iVar2 == 0) {
      isp_printf();
      goto LAB_0001f680;
    }
    *(char **)(iVar2 + (((byte)pcVar1[3] & 0xf) + 0xe) * 4 + 4) = pcVar1;
    uVar4 = uVar4 + 1;
  } while( true );
}



int tx_isp_probe(undefined4 *param_1)

{
  bool bVar1;
  code cVar2;
  code cVar3;
  void *__s;
  undefined **ppuVar4;
  code **ppcVar5;
  code *pcVar6;
  code *pcVar7;
  code cVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  code **ppcVar13;
  
  __s = (void *)private_kmalloc();
  if (__s == (void *)0x0) {
    isp_printf();
    iVar9 = -0xc;
  }
  else {
    memset(__s,0,0x124);
    iVar10 = param_1[0x16];
    if (iVar10 == 0) {
      iVar9 = -0x16;
    }
    else if (*(byte *)(iVar10 + 4) < 0x11) {
      piVar11 = (int *)((int)__s + 0x88);
      for (iVar12 = 0; iVar12 < (int)(uint)*(byte *)(iVar10 + 4); iVar12 = iVar12 + 1) {
        ppcVar5 = *(code ***)(*(int *)(iVar10 + 8) + iVar12 * 4);
        *piVar11 = (int)ppcVar5;
        ppuVar4 = &isp_drivers;
        do {
          if (ppuVar4 == (undefined **)&UNK_0007c038) goto LAB_0001f970;
          ppcVar13 = (code **)*ppuVar4;
          pcVar6 = *ppcVar5;
          pcVar7 = ppcVar13[5];
          cVar2 = *pcVar6;
          do {
            cVar3 = *pcVar7;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
            cVar8 = cVar2;
            if (cVar3 != cVar2) break;
            bVar1 = cVar2 != (code)0x0;
            cVar2 = *pcVar6;
            cVar8 = cVar3;
          } while (bVar1);
          ppuVar4 = ppuVar4 + 1;
        } while (cVar8 != cVar3);
        iVar9 = private_platform_device_register();
        if (iVar9 != 0) {
          isp_printf();
          *piVar11 = 0;
          goto LAB_0001faf4;
        }
        if (*ppcVar13 == (code *)0x0) {
          piVar11[1] = (int)ppcVar13;
        }
        else {
          (**ppcVar13)(ppcVar5);
          piVar11[1] = (int)ppcVar13;
        }
LAB_0001f970:
        piVar11 = piVar11 + 2;
      }
      *(uint *)((int)__s + 0x84) = (uint)*(byte *)(iVar10 + 4);
      private_spin_lock_init();
      iVar10 = tx_isp_module_init(param_1,__s);
      if (iVar10 == 0) {
        *(undefined4 *)((int)__s + 0xc) = 0xff;
        *(undefined1 **)((int)__s + 0x34) = tx_isp_fops;
        *(undefined1 **)((int)__s + 0x14) = tx_isp_fops;
        *(char **)((int)__s + 0x10) = "tx-isp";
        iVar9 = private_misc_register();
        if (iVar9 < 0) {
          isp_printf();
          iVar9 = -2;
        }
        else {
          iVar10 = private_jz_proc_mkdir();
          *(int *)((int)__s + 0x120) = iVar10;
          if (iVar10 == 0) {
            isp_printf();
          }
          else {
            private_platform_set_drvdata();
            globe_ispdev = __s;
            iVar9 = tx_isp_create_graph_and_nodes((int)__s);
            if (iVar9 == 0) {
              isp_mem_init();
              *(char **)((int)__s + 0x108) = "H20210817b";
              isp_printf();
              return 0;
            }
            private_proc_remove();
          }
          private_misc_deregister();
        }
        tx_isp_module_deinit(__s);
      }
      else {
        isp_printf();
        iVar9 = -0xc;
      }
LAB_0001faf4:
      tx_isp_unregister_platforms((int *)((int)__s + 0x88));
    }
    else {
      isp_printf();
      iVar9 = -0x16;
    }
    private_kfree();
  }
  return iVar9;
}



undefined4 * FUN_0001fc7c(undefined4 *param_1)

{
  undefined4 local_10 [2];
  
  memset(local_10,0,4);
  *param_1 = local_10[0];
  return param_1;
}



undefined4 FUN_0001fee0(void)

{
  return 0;
}



undefined4 private_netlink_unicast(void)

{
  return 0;
}



undefined4 private_nlmsg_put(void)

{
  return 0;
}



void private_sock_release(void)

{
  return;
}



undefined4 private_nlmsg_new(void)

{
  return 0;
}



undefined4 private_netlink_kernel_create(void)

{
  return 0;
}



uint tisp_math_exp2(uint param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = param_2 & 0xff;
  uVar3 = (1 << (param_2 & 0x1f)) - 1U & param_1;
  uVar6 = param_1 >> (param_2 & 0x1f);
  if (uVar4 < 6) {
    uVar6 = (0x1e - uVar6) - (param_3 & 0xff);
    uVar3 = *(uint *)(__pow2_lut + (uVar3 << (5 - uVar4 & 0x1f)) * 4);
  }
  else {
    uVar5 = uVar3 >> (uVar4 - 5 & 0x1f);
    iVar7 = *(int *)(__pow2_lut + uVar5 * 4);
    lVar1 = (ulonglong)(uint)(*(int *)(__pow2_lut + (uVar5 + 1) * 4) - iVar7) *
            (ulonglong)((1 << (uVar4 - 5 & 0x1f)) - 1U & uVar3);
    iVar2 = __lshrdi3((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    uVar3 = iVar7 + iVar2;
    uVar6 = (0x1e - uVar6) - (param_3 & 0xff);
  }
  return uVar3 >> (uVar6 & 0x1f);
}



void fix_point_add(undefined param_1,undefined param_2,undefined param_3,undefined param_4,
                  undefined4 param_5,undefined4 param_6)

{
  return;
}



void fix_point_sub(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                  uint param_6)

{
  if ((param_4 < param_6) || ((param_6 == param_4 && (param_3 < param_5)))) {
    isp_printf();
  }
  return;
}



void fix_point_mult2(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                    uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  
  uVar5 = 0;
  if (param_1 != 0) {
    uVar5 = __lshrdi3(0xffffffff,0xffffffff,0x40 - param_1);
  }
  uVar3 = (uint)((ulonglong)uVar5 >> 0x20);
  lVar6 = __lshrdi3(param_3,param_4,param_1);
  uVar1 = uVar3 & param_4;
  lVar7 = __lshrdi3(param_5,param_6,param_1);
  uVar8 = (undefined4)((ulonglong)lVar7 >> 0x20);
  uVar4 = (uint)uVar5 & param_3;
  uVar2 = (uint)uVar5 & param_5;
  __ashldi3((int)(lVar6 * lVar7),(int)((ulonglong)(lVar6 * lVar7) >> 0x20),param_1);
  lVar6 = (ulonglong)uVar2 * (ulonglong)uVar4;
  __lshrdi3((int)lVar6,uVar1 * uVar2 + (uVar3 & param_6) * uVar4 + (int)((ulonglong)lVar6 >> 0x20),
            param_1,uVar1,param_5,uVar8);
  return;
}



void fix_point_mult3(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                    uint param_6,uint param_7,uint param_8)

{
  undefined8 uVar1;
  
  uVar1 = fix_point_mult2(param_1,param_2,param_3,param_4,param_5,param_6);
  fix_point_mult2(param_1,param_2,(uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),param_7,param_8);
  return;
}



ulonglong fix_point_div(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,
                       uint param_6)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  lVar8 = div64_u64(param_3,param_4,param_5,param_6);
  iVar5 = 0;
  lVar1 = lVar8 * CONCAT44(param_6,param_5);
  uVar4 = param_3 - (int)lVar1;
  uVar3 = (param_4 - (int)((ulonglong)lVar1 >> 0x20)) - (uint)(param_3 < uVar4);
  uVar7 = 0;
  uVar6 = 0;
LAB_00020450:
  do {
    uVar9 = CONCAT44(uVar7,uVar6);
    if (iVar5 == param_1) {
LAB_00020458:
      uVar10 = __ashldi3((int)lVar8,(int)((ulonglong)lVar8 >> 0x20),param_1);
      return uVar9 | uVar10;
    }
    uVar3 = uVar4 >> 0x1f | uVar3 << 1;
    uVar2 = uVar6 >> 0x1f;
    uVar6 = uVar6 << 1;
    uVar7 = uVar2 | uVar7 << 1;
    uVar4 = uVar4 * 2;
    if ((param_6 < uVar3) || ((uVar3 == param_6 && (param_5 < uVar4)))) {
      uVar6 = uVar6 | 1;
      uVar3 = (uVar3 - param_6) - (uint)(uVar4 < uVar4 - param_5);
      iVar5 = iVar5 + 1;
      uVar4 = uVar4 - param_5;
      goto LAB_00020450;
    }
    if (uVar4 == param_5) {
      if (uVar3 == param_6) {
        uVar9 = __ashldi3(uVar6 | 1,uVar7,(param_1 + -1) - iVar5);
        goto LAB_00020458;
      }
      iVar5 = iVar5 + 1;
    }
    else {
      iVar5 = iVar5 + 1;
    }
  } while( true );
}



void fix_point_add_64(undefined param_1,undefined param_2,undefined param_3,undefined param_4,
                     undefined4 param_5,undefined4 param_6)

{
  return;
}



void fix_point_sub_64(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                     uint param_6)

{
  if ((param_4 < param_6) || ((param_6 == param_4 && (param_3 < param_5)))) {
    isp_printf();
  }
  return;
}



void fix_point_mult2_64(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                       uint param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar5 = __lshrdi3(0xffffffff,0xffffffff,0x40 - param_1);
  uVar1 = (uint)((ulonglong)uVar5 >> 0x20);
  uVar6 = __lshrdi3(param_3,param_4,param_1);
  uVar8 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar2 = uVar1 & param_4;
  lVar7 = __lshrdi3(param_5,param_6,param_1);
  uVar9 = (undefined4)((ulonglong)lVar7 >> 0x20);
  uVar4 = (uint)uVar5 & param_5;
  uVar3 = (uint)uVar5 & param_3;
  lVar7 = lVar7 * CONCAT44(uVar8,(int)uVar6);
  __ashldi3((int)lVar7,(int)((ulonglong)lVar7 >> 0x20),param_1);
  lVar7 = (ulonglong)uVar4 * (ulonglong)uVar3;
  __lshrdi3((int)lVar7,uVar2 * uVar4 + (uVar1 & param_6) * uVar3 + (int)((ulonglong)lVar7 >> 0x20),
            param_1,uVar2,uVar9);
  return;
}



void fix_point_mult3_64(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                       uint param_6,uint param_7,uint param_8)

{
  undefined8 uVar1;
  
  uVar1 = fix_point_mult2_64(param_1,param_2,param_3,param_4,param_5,param_6);
  fix_point_mult2_64(param_1,param_2,(uint)uVar1,(uint)((ulonglong)uVar1 >> 0x20),param_7,param_8);
  return;
}



ulonglong fix_point_div_64(int param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,
                          uint param_6)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  lVar8 = div64_u64(param_3,param_4,param_5,param_6);
  iVar5 = 0;
  lVar1 = lVar8 * CONCAT44(param_6,param_5);
  uVar4 = param_3 - (int)lVar1;
  uVar3 = (param_4 - (int)((ulonglong)lVar1 >> 0x20)) - (uint)(param_3 < uVar4);
  uVar7 = 0;
  uVar6 = 0;
LAB_00020884:
  do {
    uVar9 = CONCAT44(uVar7,uVar6);
    if (iVar5 == param_1) {
LAB_0002088c:
      uVar10 = __ashldi3((int)lVar8,(int)((ulonglong)lVar8 >> 0x20),param_1);
      return uVar9 | uVar10;
    }
    uVar3 = uVar4 >> 0x1f | uVar3 << 1;
    uVar2 = uVar6 >> 0x1f;
    uVar6 = uVar6 << 1;
    uVar7 = uVar2 | uVar7 << 1;
    uVar4 = uVar4 * 2;
    if ((param_6 < uVar3) || ((uVar3 == param_6 && (param_5 < uVar4)))) {
      uVar6 = uVar6 | 1;
      uVar3 = (uVar3 - param_6) - (uint)(uVar4 < uVar4 - param_5);
      iVar5 = iVar5 + 1;
      uVar4 = uVar4 - param_5;
      goto LAB_00020884;
    }
    if (uVar4 == param_5) {
      if (uVar3 == param_6) {
        uVar9 = __ashldi3(uVar6 | 1,uVar7,(param_1 + -1) - iVar5);
        goto LAB_0002088c;
      }
      iVar5 = iVar5 + 1;
    }
    else {
      iVar5 = iVar5 + 1;
    }
  } while( true );
}



int fix_point_add_32(undefined4 param_1,int param_2,int param_3)

{
  return param_3 + param_2;
}



int fix_point_sub_32(undefined4 param_1,uint param_2,uint param_3)

{
  if (param_2 < param_3) {
    isp_printf();
  }
  return param_2 - param_3;
}



int fix_point_mult2_32(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_2 >> (param_1 & 0x1f);
  uVar4 = 0xffffffff >> (-param_1 & 0x1f);
  uVar1 = param_3 >> (param_1 & 0x1f);
  uVar3 = uVar4 & param_2;
  uVar4 = uVar4 & param_3;
  return (uVar1 * uVar2 << (param_1 & 0x1f)) + uVar4 * uVar2 + uVar3 * uVar1 +
         (uVar4 * uVar3 >> (param_1 & 0x1f));
}



int fix_point_mult3_32(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = fix_point_mult2_32(param_1,param_2,param_3);
  iVar2 = fix_point_mult2_32(param_1,uVar1,param_4);
  return iVar2;
}



uint fix_point_div_32(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = param_2 - (param_2 / param_3) * param_3;
  iVar1 = 0;
LAB_00020a28:
  do {
    uVar2 = uVar2 * 2;
    if (iVar1 == param_1) {
LAB_00020a30:
      uVar2 = __ashldi3(param_2 / param_3,0,param_1);
      return uVar3 | uVar2;
    }
    uVar3 = uVar3 << 1;
    if (param_3 < uVar2) {
      uVar3 = uVar3 | 1;
      uVar2 = uVar2 - param_3;
      iVar1 = iVar1 + 1;
      goto LAB_00020a28;
    }
    if (uVar2 == param_3) {
      uVar3 = (uVar3 | 1) << ((param_1 + -1) - iVar1 & 0x1fU);
      goto LAB_00020a30;
    }
    iVar1 = iVar1 + 1;
  } while( true );
}



int fix_point_intp(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  if (param_3 < param_2) {
    isp_printf();
  }
  if (param_2 == param_3) {
    if (param_4 != param_5) {
      isp_printf();
      param_4 = 0;
    }
  }
  else {
    uVar8 = param_3 - param_2;
    if (param_4 != param_5) {
      uVar9 = div64_u64(0,0,uVar8,0);
      iVar2 = (int)(uVar9 >> 0x20);
      lVar1 = (uVar9 & 0xffffffff) * (ulonglong)uVar8;
      uVar7 = 0;
      uVar4 = -(int)lVar1;
      iVar5 = -(uint)(uVar4 != 0) - (iVar2 * uVar8 + (int)((ulonglong)lVar1 >> 0x20));
      for (uVar3 = 0; uVar3 < param_1; uVar3 = uVar3 + 1 & 0xff) {
        uVar6 = uVar4 >> 0x1f | iVar5 << 1;
        uVar4 = uVar4 * 2;
        uVar7 = uVar7 << 1;
        if ((uVar6 == 0) && (uVar4 <= uVar8)) {
          if (uVar4 == uVar8) {
            uVar7 = (uVar7 | 1) << ((param_1 - 1) - uVar3 & 0x1f);
            break;
          }
          iVar5 = 0;
        }
        else {
          uVar7 = uVar7 | 1;
          iVar5 = uVar6 - (uVar4 < uVar4 - uVar8);
          uVar4 = uVar4 - uVar8;
        }
      }
      uVar8 = __ashldi3((int)uVar9,iVar2,param_1);
      param_4 = (int)uVar9 - (uVar7 | uVar8);
    }
  }
  return param_4;
}



int table_intp(uint param_1,int *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 1;
  if (param_4 <= (uint)param_2[1]) {
    return *param_2;
  }
  while( true ) {
    if (param_3 <= uVar1) {
      return param_2[param_3 * 2 + -2];
    }
    uVar3 = (param_2 + uVar1 * 2)[1];
    if (param_4 <= uVar3) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = fix_point_intp(param_1,(param_2 + (uVar1 - 1) * 2)[1],uVar3,param_2[(uVar1 - 1) * 2],
                         param_2[uVar1 * 2]);
  return iVar2;
}



int tisp_simple_intp(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (7 < param_1) {
    return *(int *)(param_3 + 0x20);
  }
  iVar3 = *(int *)(param_3 + param_1 * 4);
  iVar1 = *(int *)(param_3 + (param_1 + 1) * 4);
  if (iVar3 != iVar1) {
    if (iVar3 < iVar1) {
      iVar2 = iVar1 - iVar3;
    }
    else {
      iVar2 = iVar3 - iVar1;
    }
    iVar4 = (iVar2 * param_2 >> 0x10) - (iVar2 * param_2 * 0x10000 >> 0x1f);
    iVar2 = -iVar4;
    if (iVar3 < iVar1) {
      iVar2 = iVar4;
    }
    return iVar3 + iVar2;
  }
  return iVar3;
}



uint tisp_log2_int_to_fixed(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_1 < 0x10000) {
      uVar2 = 0;
      uVar1 = param_1;
    }
    else {
      uVar1 = param_1 >> 0x10;
      uVar2 = 0x10;
    }
    if (0xff < uVar1) {
      uVar2 = uVar2 + 8;
      uVar1 = uVar1 >> 8;
    }
    if (0xf < uVar1) {
      uVar2 = uVar2 + 4;
      uVar1 = uVar1 >> 4;
    }
    if (3 < uVar1) {
      uVar2 = uVar2 + 2;
      uVar1 = uVar1 >> 2;
    }
    if (uVar1 != 1) {
      uVar2 = uVar2 + 1 & 0xff;
    }
    if (uVar2 < 0x10) {
      uVar1 = param_1 << (0xf - uVar2 & 0x1f);
    }
    else {
      uVar1 = param_1 >> (uVar2 - 0xf & 0x1f);
    }
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < (int)(param_2 & 0xff); iVar4 = iVar4 + 1) {
      uVar1 = uVar1 * uVar1;
      iVar3 = iVar3 * 2;
      if ((int)uVar1 < 0) {
        iVar3 = iVar3 + 1;
        uVar1 = uVar1 >> 0x10;
      }
      else {
        uVar1 = uVar1 >> 0xf;
      }
    }
    uVar1 = (uVar1 & 0x7fff) >> (0xf - (param_3 & 0xff) & 0x1f) |
            iVar3 + (uVar2 << (param_2 & 0x1f)) << (param_3 & 0x1f);
  }
  return uVar1;
}



int tisp_log2_fixed_to_fixed(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = tisp_log2_int_to_fixed(param_1,param_3 & 0xff,0);
  return uVar1 - (param_2 << (param_3 & 0x1f));
}



// WARNING: Removing unreachable block (ram,0x00020f20)

uint tisp_log2_int_to_fixed_64(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  
  uVar2 = 0;
  if ((param_1 | param_2) != 0) {
    if (param_2 == 0) {
      uVar8 = 0;
      uVar2 = param_1;
    }
    else {
      uVar8 = 0x20;
      uVar2 = param_2;
    }
    if (0xffff < uVar2) {
      uVar2 = uVar2 >> 0x10;
      uVar8 = uVar8 + 0x10;
    }
    if (0xff < uVar2) {
      uVar2 = uVar2 >> 8;
      uVar8 = uVar8 + 8;
    }
    if (0xf < uVar2) {
      uVar2 = uVar2 >> 4;
      uVar8 = uVar8 + 4;
    }
    if (3 < uVar2) {
      uVar2 = uVar2 >> 2;
      uVar8 = uVar8 + 2;
    }
    if (uVar2 != 1) {
      uVar8 = uVar8 + 1;
    }
    if (uVar8 < 0x10) {
      iVar4 = 0xf - uVar8;
      pcVar3 = __ashldi3;
    }
    else {
      iVar4 = uVar8 - 0xf;
      pcVar3 = __lshrdi3;
    }
    uVar6 = 0;
    uVar10 = (*pcVar3)(param_1,param_2,iVar4);
    uVar7 = 0;
    iVar4 = 0;
    while( true ) {
      if ((int)(param_3 & 0xff) <= iVar4) break;
      uVar5 = uVar6 >> 0x1f;
      lVar1 = (uVar10 & 0xffffffff) * (uVar10 & 0xffffffff);
      uVar9 = (uint)lVar1;
      uVar2 = (int)(uVar10 >> 0x20) * (uint)uVar10 * 2 + (int)((ulonglong)lVar1 >> 0x20);
      uVar6 = uVar6 * 2;
      if ((uVar9 & 0x80000000 | uVar2) == 0) {
        uVar9 = uVar2 * 0x20000 | uVar9 >> 0xf;
        uVar7 = uVar5 | uVar7 << 1;
        uVar2 = uVar2 >> 0xf;
      }
      else {
        uVar7 = (uint)(uVar6 + 1 < uVar6) + (uVar5 | uVar7 << 1);
        uVar9 = uVar2 * 0x10000 | uVar9 >> 0x10;
        uVar2 = uVar2 >> 0x10;
        uVar6 = uVar6 + 1;
      }
      uVar10 = CONCAT44(uVar2,uVar9);
      iVar4 = iVar4 + 1;
    }
    uVar2 = __lshrdi3((uint)uVar10 & 0x7fff,0,0xf - (param_4 & 0xff));
    iVar4 = uVar8 << (param_3 & 0x1f);
    uVar8 = uVar6 + iVar4;
    uVar8 = __ashldi3(uVar8,(uint)(uVar8 < uVar6) + uVar7 + (iVar4 >> 0x1f),param_4 & 0xff);
    uVar2 = uVar2 | uVar8;
  }
  return uVar2;
}



int tisp_log2_fixed_to_fixed_64(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = tisp_log2_int_to_fixed_64(param_1,param_2,param_4 & 0xff,0);
  return uVar1 - (param_3 << (param_4 & 0x1f));
}



void netlink_rcv_msg(int param_1)

{
  int *piVar1;
  
  if (0xf < *(uint *)(param_1 + 0x50)) {
    piVar1 = *(int **)(param_1 + 0x9c) + 4;
    if ((piVar1 != (int *)0x0) && (net_event_process != (code *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x000210d0. Too many branches
                    // WARNING: Treating indirect jump as call
      (*net_event_process)(piVar1,**(int **)(param_1 + 0x9c) + -0x10);
      return;
    }
  }
  return;
}



undefined4 netlink_send_msg(void *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = private_nlmsg_new();
  if (iVar1 == 0) {
    isp_printf();
  }
  else {
    iVar2 = private_nlmsg_put();
    if (iVar2 != 0) {
      memcpy((void *)(iVar2 + 0x10),param_1,param_2 & 0xffff);
      uVar3 = private_netlink_unicast();
      return uVar3;
    }
    isp_printf();
    kfree_skb(iVar1);
  }
  return 0xffffffff;
}



undefined4 tisp_netlink_event_set_cb(undefined4 param_1)

{
  net_event_process = param_1;
  return 0;
}



undefined4 tisp_netlink_init(void)

{
  undefined4 uVar1;
  
  nlsk = private_netlink_kernel_create();
  uVar1 = 0;
  if (nlsk == 0) {
    isp_printf();
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



void tisp_netlink_exit(void)

{
  if ((nlsk != 0) && (*(int *)(nlsk + 0x158) != 0)) {
    private_sock_release();
    return;
  }
  return;
}



undefined4 tisp_code_tuning_release(void)

{
  private_kfree();
  tisp_par_ioctl = 0;
  return 0;
}



undefined4 tisp_code_tuning_open(void)

{
  tisp_par_ioctl = (void *)private_kmalloc();
  memset(tisp_par_ioctl,0,0x500c);
  return 0;
}



undefined4 tisp_param_operate_process(int *param_1)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  uint local_a8;
  void *local_20;
  int local_1c [2];
  
  piVar4 = opmsg;
  iVar3 = *param_1;
  local_1c[0] = 0;
  if (iVar3 == 0) {
    iVar3 = param_1[1];
    if ((iVar3 == 0) || (iVar3 - 1U < 0x22)) {
      pcVar1 = tisp_ae_param_array_get;
    }
    else if (iVar3 - 0x23U < 0x19) {
      pcVar1 = tisp_awb_param_array_get;
    }
    else if (iVar3 - 0x3cU < 2) {
      pcVar1 = tisp_gamma_param_array_get;
    }
    else if (iVar3 - 0x3eU < 0x16) {
      pcVar1 = tisp_gib_param_array_get;
    }
    else if (iVar3 - 0x5fU < 0x4a) {
      pcVar1 = tisp_dmsc_param_array_get;
    }
    else if (iVar3 - 0x54U < 0xb) {
      pcVar1 = tisp_lsc_param_array_get;
    }
    else if (iVar3 - 0xa9U < 0xc) {
      pcVar1 = tisp_ccm_param_array_get;
    }
    else if (iVar3 - 0xb5U < 0x31) {
      pcVar1 = tisp_sharpen_param_array_get;
    }
    else if (iVar3 - 0xe6U < 0x1f) {
      pcVar1 = tisp_dpc_param_array_get;
    }
    else if (iVar3 - 0x105U < 0x7b) {
      pcVar1 = tisp_sdns_param_array_get;
    }
    else if (iVar3 - 0x180U < 0x1d7) {
      pcVar1 = tisp_mdns_param_array_get;
    }
    else if (iVar3 - 0x357U < 3) {
      pcVar1 = tisp_clm_param_array_get;
    }
    else if (iVar3 - 0x35aU < 0x26) {
      pcVar1 = tisp_defog_param_array_get;
    }
    else if (iVar3 - 0x380U < 0x2c) {
      pcVar1 = tisp_adr_param_array_get;
    }
    else if (iVar3 == 0x3ac) {
      iVar3 = 0x3ac;
      pcVar1 = tisp_hldc_param_array_get;
    }
    else if (iVar3 - 0x3adU < 0x13) {
      pcVar1 = tisp_af_param_array_get;
    }
    else if (iVar3 - 0x3c0U < 0x26) {
      pcVar1 = tisp_bcsh_param_array_get;
    }
    else if (iVar3 - 0x3e6U < 0xf) {
      pcVar1 = tisp_ydns_param_array_get;
    }
    else if (iVar3 - 0x3f5U < 10) {
      pcVar1 = tisp_gb_param_array_get;
    }
    else if (iVar3 - 0x3ffU < 0x33) {
      pcVar1 = tisp_wdr_param_array_get;
    }
    else {
      if (0x14 < iVar3 - 0x432U) goto LAB_00022084;
      pcVar1 = tisp_rdns_param_array_get;
    }
    (*pcVar1)(iVar3,opmsg + 6,local_1c);
    piVar4 = opmsg;
    *opmsg = *param_1;
    piVar4[1] = param_1[1];
    uVar5 = local_1c[0] + 0x18U & 0xffff;
    piVar4[2] = param_1[2];
    piVar4[3] = param_1[3];
    piVar4[4] = param_1[4];
    goto LAB_00021e50;
  }
  if (iVar3 == 1) {
    local_1c[0] = param_1[2];
    iVar3 = param_1[1];
    if ((iVar3 == 0) || (iVar3 - 1U < 0x22)) {
      pcVar1 = tisp_ae_param_array_set;
    }
    else if (iVar3 - 0x23U < 0x19) {
      pcVar1 = tisp_awb_param_array_set;
    }
    else if (iVar3 - 0x3cU < 2) {
      pcVar1 = tisp_gamma_param_array_set;
    }
    else if (iVar3 - 0x3eU < 0x16) {
      pcVar1 = tisp_gib_param_array_set;
    }
    else if (iVar3 - 0x54U < 0xb) {
      pcVar1 = tisp_lsc_param_array_set;
    }
    else if (iVar3 - 0x5fU < 0x4a) {
      pcVar1 = tisp_dmsc_param_array_set;
    }
    else if (iVar3 - 0xa9U < 0xc) {
      pcVar1 = tisp_ccm_param_array_set;
    }
    else if (iVar3 - 0xb5U < 0x31) {
      pcVar1 = tisp_sharpen_param_array_set;
    }
    else if (iVar3 - 0xe6U < 0x1f) {
      pcVar1 = tisp_dpc_param_array_set;
    }
    else if (iVar3 - 0x105U < 0x7b) {
      pcVar1 = tisp_sdns_param_array_set;
    }
    else if (iVar3 - 0x180U < 0x1d7) {
      pcVar1 = tisp_mdns_param_array_set;
    }
    else if (iVar3 - 0x357U < 3) {
      pcVar1 = tisp_clm_param_array_set;
    }
    else if (iVar3 - 0x35aU < 0x26) {
      pcVar1 = tisp_defog_param_array_set;
    }
    else if (iVar3 - 0x380U < 0x2c) {
      pcVar1 = tisp_adr_param_array_set;
    }
    else if (iVar3 == 0x3ac) {
      iVar3 = 0x3ac;
      pcVar1 = tisp_hldc_param_array_set;
    }
    else if (iVar3 - 0x3adU < 0x13) {
      pcVar1 = tisp_af_param_array_set;
    }
    else if (iVar3 - 0x3c0U < 0x26) {
      pcVar1 = tisp_bcsh_param_array_set;
    }
    else if (iVar3 - 0x3e6U < 0xf) {
      pcVar1 = tisp_ydns_param_array_set;
    }
    else if (iVar3 - 0x3f5U < 10) {
      pcVar1 = tisp_gb_param_array_set;
    }
    else if (iVar3 - 0x3ffU < 0x33) {
      pcVar1 = tisp_wdr_param_array_set;
    }
    else {
      if (0x14 < iVar3 - 0x432U) goto LAB_00022084;
      pcVar1 = tisp_rdns_param_array_set;
    }
    (*pcVar1)(iVar3,param_1 + 6,local_1c);
    piVar4 = opmsg;
    goto LAB_00021f04;
  }
  if (iVar3 == 2) {
    iVar3 = param_1[1];
    piVar7 = param_1 + 6;
    *opmsg = 2;
    piVar4[1] = param_1[1];
    piVar4[2] = param_1[2];
    piVar4[3] = param_1[3];
    iVar6 = param_1[4];
    piVar4[5] = 0;
    piVar4[4] = iVar6;
    if (iVar3 == 0) {
      memcpy(&local_b8,piVar7,0x98);
      for (uVar5 = 0; uVar5 < 0x88; uVar5 = uVar5 + 1) {
        (&stack0xfffffb28)[uVar5] = *(undefined *)((int)&local_a8 + uVar5);
      }
      pcVar1 = tisp_ae_manual_set;
LAB_00021b40:
      (*pcVar1)(local_b8,local_b4,local_b0,local_ac);
      piVar4 = opmsg;
    }
    else if (iVar3 == 1) {
      uVar5 = 0xc;
      iVar3 = param_1[2];
LAB_00021bf4:
      system_reg_write(uVar5,iVar3);
      piVar4 = opmsg;
    }
    else {
      if (iVar3 == 0xb) {
        memcpy(&local_b8,piVar7,0x98);
        for (uVar5 = 0; uVar5 < 0x88; uVar5 = uVar5 + 1) {
          (&stack0xfffffb28)[uVar5] = *(undefined *)((int)&local_a8 + uVar5);
        }
        pcVar1 = tisp_ae_min_max_set;
        goto LAB_00021b40;
      }
      if (iVar3 == 0xd) {
        pvVar2 = (void *)private_kmalloc();
        memcpy(pvVar2,piVar7,0x42c);
        for (uVar5 = 0; uVar5 < 0x41c; uVar5 = uVar5 + 1) {
          (&stack0xfffffb28)[uVar5] = *(undefined *)((int)pvVar2 + uVar5 + 0x10);
        }
        tisp_s_ae_hist();
        pcVar1 = private_kfree;
LAB_00021cac:
        (*pcVar1)(pvVar2);
        piVar4 = opmsg;
      }
      else {
        if (iVar3 == 2) {
          iVar3 = param_1[3];
          uVar5 = param_1[2] & 0x1ffff;
          goto LAB_00021bf4;
        }
        if (iVar3 == 3) {
          iVar3 = 0;
          if ((param_1[2] != 0) && (iVar3 = 1, param_1[2] != 1)) {
            isp_printf();
            iVar3 = 0;
          }
          pcVar1 = tisp_day_or_night_s_ctrl;
        }
        else if (iVar3 == 0xc) {
          iVar3 = param_1[2];
          pcVar1 = tisp_s_Hilightdepress;
        }
        else {
          if (iVar3 != 0x10) {
            if (iVar3 == 9) {
              pvVar2 = (void *)(uint)*(byte *)(param_1 + 2);
              pcVar1 = tisp_set_brightness;
            }
            else if (iVar3 == 6) {
              pvVar2 = (void *)(uint)*(byte *)(param_1 + 2);
              pcVar1 = tisp_set_saturation;
            }
            else if (iVar3 == 7) {
              pvVar2 = (void *)(uint)*(byte *)(param_1 + 2);
              pcVar1 = tisp_set_sharpness;
            }
            else {
              if (iVar3 != 8) {
                if (iVar3 == 5) {
                  memcpy(&local_b8,piVar7,0x1c);
                  tisp_s_wb_attr(local_b8,local_b4,local_b0);
                  piVar4 = opmsg;
                }
                else if (iVar3 == 10) {
                  memcpy(&local_b8,piVar7,0x14);
                  tisp_s_fcrop_control((char)local_b8,local_b4,local_b0,local_ac,local_a8);
                  piVar4 = opmsg;
                }
                else {
                  isp_printf();
                  opmsg[5] = 1;
                  piVar4 = opmsg;
                }
                goto LAB_00021f04;
              }
              pvVar2 = (void *)(uint)*(byte *)(param_1 + 2);
              pcVar1 = tisp_set_contrast;
            }
            goto LAB_00021cac;
          }
          iVar3 = param_1[2];
          pcVar1 = tisp_s_wdr_en;
        }
        (*pcVar1)(iVar3);
        piVar4 = opmsg;
      }
    }
  }
  else {
    if (iVar3 != 3) {
LAB_00022084:
      isp_printf();
      return 0xffffffff;
    }
    iVar3 = param_1[1];
    *opmsg = 3;
    piVar7 = piVar4 + 6;
    piVar4[1] = param_1[1];
    piVar4[2] = param_1[2];
    piVar4[3] = param_1[3];
    iVar6 = param_1[4];
    piVar4[5] = 0;
    piVar4[4] = iVar6;
    if (iVar3 == 0) {
      memcpy(piVar7,&tisp_ae_ctrls,0x98);
      uVar5 = 0xb0;
      piVar4 = opmsg;
      goto LAB_00021e50;
    }
    if (iVar3 == 0xd) {
      local_20 = (void *)private_kmalloc();
      tisp_g_ae_hist(local_20);
      memcpy(piVar7,&local_20,0x42c);
      netlink_send_msg(opmsg,0x444);
      private_kfree();
      return 0;
    }
    if (iVar3 == 1) {
      iVar3 = system_reg_read(0xc);
      piVar4 = opmsg;
      opmsg[2] = iVar3;
      goto LAB_00021f04;
    }
    if (iVar3 == 0x10) {
      pcVar1 = tisp_g_wdr_en;
LAB_00021fbc:
      local_20 = (void *)0x0;
      (*pcVar1)(&local_20);
      pvVar2 = local_20;
    }
    else {
      if (iVar3 != 2) {
        if (iVar3 != 3) {
          if (iVar3 != 0xc) {
            if (iVar3 == 4) {
              memcpy(piVar7,&sensor_info,0x60);
              uVar5 = 0x78;
              piVar4 = opmsg;
            }
            else {
              if (iVar3 != 5) {
                isp_printf();
                opmsg[5] = 1;
                return 0;
              }
              tisp_g_wb_attr(&local_b8);
              memcpy(piVar7,&local_b8,0x1c);
              uVar5 = 0x34;
              piVar4 = opmsg;
            }
            goto LAB_00021e50;
          }
          pcVar1 = tisp_g_Hilightdepress;
          goto LAB_00021fbc;
        }
        iVar3 = tisp_day_or_night_g_ctrl();
        if (iVar3 == 0) {
LAB_00021f98:
          iVar6 = 0;
        }
        else {
          iVar6 = 1;
          if (iVar3 != 1) {
            isp_printf();
            goto LAB_00021f98;
          }
        }
        piVar4 = opmsg;
        opmsg[3] = iVar6;
        goto LAB_00021f04;
      }
      pvVar2 = (void *)system_reg_read(param_1[2] & 0xfffff);
    }
    piVar4 = opmsg;
    opmsg[3] = (int)pvVar2;
  }
LAB_00021f04:
  uVar5 = 0x18;
LAB_00021e50:
  netlink_send_msg(piVar4,uVar5);
  return 0;
}



undefined4 tisp_param_operate_deinit(void)

{
  tisp_netlink_exit();
  if (opmsg != 0) {
    private_kfree();
    opmsg = 0;
  }
  return 0;
}



undefined4 tisp_top_param_array_get(void *param_1,undefined4 *param_2)

{
  tisp_g_wdr_en(&DAT_000b40a4);
  memcpy(param_1,&sensor_info,0x60);
  *param_2 = 0x60;
  return 0;
}



undefined4 tisp_get_ae_info(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x98;
  memcpy((void *)(param_1 + 0xc),&tisp_ae_ctrls,0x98);
  return 0;
}



undefined4 tisp_set_ae_info(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0x98;
  memcpy(&tisp_ae_ctrls,(void *)(param_1 + 0xc),0x98);
  return 0;
}



undefined4 tisp_get_awb_info(int param_1)

{
  undefined auStack_28 [32];
  
  tisp_g_wb_attr(auStack_28);
  *(undefined4 *)(param_1 + 4) = 0x1c;
  memcpy((void *)(param_1 + 0xc),auStack_28,0x1c);
  return 0;
}



undefined4 tisp_set_awb_info(int param_1)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  *(undefined4 *)(param_1 + 4) = 0x1c;
  memcpy(&local_28,(void *)(param_1 + 0xc),0x1c);
  tisp_s_wb_attr(local_28,local_24,local_20);
  return 0;
}



undefined4 tisp_reg_map_get(int param_1,int param_2,undefined4 *param_3)

{
  int local_res0 [4];
  undefined4 local_18 [2];
  
  local_res0[0] = param_1;
  local_18[0] = system_reg_read(param_1 + -0x13300000);
  memcpy((void *)(param_2 + 0xc),local_res0,4);
  memcpy((void *)(param_2 + 0x10),local_18,4);
  *param_3 = 8;
  return 0;
}



undefined4 tisp_reg_map_set(int param_1)

{
  undefined4 local_18;
  int local_14 [2];
  
  memcpy(local_14,(void *)(param_1 + 0xc),4);
  memcpy(&local_18,(void *)(param_1 + 0x10),4);
  local_14[0] = local_14[0] + -0x13300000;
  system_reg_write(local_14[0],local_18);
  return 0;
}



undefined4 tisp_dn_mode_get(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_18 [3];
  
  iVar1 = tisp_day_or_night_g_ctrl();
  if (iVar1 == 0) {
    local_18[0] = 0;
  }
  else if (iVar1 == 1) {
    local_18[0] = 1;
  }
  else {
    isp_printf();
  }
  memcpy((void *)(param_1 + 0xc),local_18,4);
  *param_2 = 4;
  return 0;
}



undefined4 tisp_dn_mode_set(int param_1)

{
  int iVar1;
  int local_10 [3];
  
  memcpy(local_10,(void *)(param_1 + 0xc),4);
  iVar1 = 0;
  if ((local_10[0] != 0) && (iVar1 = 1, local_10[0] != 1)) {
    isp_printf();
    iVar1 = 0;
  }
  tisp_day_or_night_s_ctrl(iVar1);
  return 0;
}



undefined4 tisp_blc_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3f5;
  do {
    tisp_gb_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3ff);
  return 0;
}



undefined4 tisp_blc_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3f5;
  do {
    tisp_gb_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3ff);
  return 0;
}



undefined4 tisp_lsc_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_28 [2];
  
  local_28[0] = 0;
  *param_2 = 0;
  iVar1 = 0x54;
  do {
    tisp_lsc_param_array_get(iVar1,param_1,local_28);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_28[0]);
    *param_2 = *param_2 + local_28[0];
  } while (iVar1 != 0x59);
  iVar1 = 0x5c;
  do {
    tisp_lsc_param_array_get(iVar1,param_1,local_28);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_28[0]);
    *param_2 = *param_2 + local_28[0];
  } while (iVar1 != 0x5f);
  return 0;
}



undefined4 tisp_lsc_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_28 [3];
  
  local_28[0] = 0;
  iVar1 = 0x54;
  do {
    tisp_lsc_param_array_set(iVar1,param_1,local_28);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_28[0]);
  } while (iVar1 != 0x59);
  iVar1 = 0x5c;
  do {
    tisp_lsc_param_array_set(iVar1,param_1,local_28);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_28[0]);
  } while (iVar1 != 0x5f);
  return 0;
}



undefined4 tisp_wdr_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3ff;
  do {
    tisp_wdr_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x432);
  return 0;
}



undefined4 tisp_wdr_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3ff;
  do {
    tisp_wdr_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x432);
  return 0;
}



undefined4 tisp_dpc_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0xe6;
  do {
    tisp_dpc_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x105);
  return 0;
}



undefined4 tisp_dpc_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0xe6;
  do {
    tisp_dpc_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x105);
  return 0;
}



undefined4 tisp_gib_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3e;
  do {
    tisp_gib_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x54);
  return 0;
}



undefined4 tisp_gib_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3e;
  do {
    tisp_gib_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x54);
  return 0;
}



undefined4 tisp_rdns_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x432;
  do {
    tisp_rdns_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x447);
  return 0;
}



undefined4 tisp_rdns_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x432;
  do {
    tisp_rdns_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x447);
  return 0;
}



undefined4 tisp_adr_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x380;
  do {
    tisp_adr_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3ac);
  return 0;
}



undefined4 tisp_adr_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x380;
  do {
    tisp_adr_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3ac);
  return 0;
}



undefined4 tisp_dmsc_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x5f;
  do {
    tisp_dmsc_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0xa9);
  return 0;
}



undefined4 tisp_dmsc_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x5f;
  do {
    tisp_dmsc_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0xa9);
  return 0;
}



undefined4 tisp_ccm_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0xa9;
  do {
    tisp_ccm_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0xb5);
  return 0;
}



undefined4 tisp_ccm_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0xa9;
  do {
    tisp_ccm_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0xb5);
  return 0;
}



undefined4 tisp_gamma_get_par_cfg(void *param_1,int *param_2)

{
  int local_18 [2];
  
  *param_2 = 0;
  local_18[0] = 0;
  tisp_gamma_param_array_get(0x3c,param_1,local_18);
  *param_2 = *param_2 + local_18[0];
  tisp_gamma_param_array_get(0x3d,(void *)((int)param_1 + local_18[0]),local_18);
  *param_2 = *param_2 + local_18[0];
  return 0;
}



undefined4 tisp_gamma_set_par_cfg(void *param_1)

{
  int local_18 [3];
  
  local_18[0] = 0;
  tisp_gamma_param_array_set(0x3c,param_1,local_18);
  tisp_gamma_param_array_set(0x3d,(void *)((int)param_1 + local_18[0]),local_18);
  return 0;
}



undefined4 tisp_defog_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x35a;
  do {
    tisp_defog_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x380);
  return 0;
}



undefined4 tisp_defog_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x35a;
  do {
    tisp_defog_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x380);
  return 0;
}



undefined4 tisp_mdns_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x180;
  do {
    tisp_mdns_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x357);
  return 0;
}



undefined4 tisp_mdns_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x180;
  do {
    tisp_mdns_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x357);
  return 0;
}



undefined4 tisp_ydns_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3e6;
  do {
    tisp_ydns_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3f5);
  return 0;
}



undefined4 tisp_ydns_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3e6;
  do {
    tisp_ydns_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3f5);
  return 0;
}



undefined4 tisp_bcsh_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3c0;
  do {
    tisp_bcsh_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3e6);
  return 0;
}



undefined4 tisp_bcsh_set_par_cfg(undefined4 *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3c0;
  do {
    tisp_bcsh_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (undefined4 *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3e6);
  return 0;
}



undefined4 tisp_clm_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x357;
  do {
    tisp_clm_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x35a);
  return 0;
}



undefined4 tisp_clm_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x357;
  do {
    tisp_clm_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x35a);
  return 0;
}



undefined4 tisp_ysp_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0xb5;
  do {
    tisp_sharpen_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0xe6);
  return 0;
}



undefined4 tisp_ysp_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0xb5;
  do {
    tisp_sharpen_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0xe6);
  return 0;
}



undefined4 tisp_sdns_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x105;
  do {
    tisp_sdns_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x180);
  return 0;
}



undefined4 tisp_sdns_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x105;
  do {
    tisp_sdns_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x180);
  return 0;
}



undefined4 tisp_af_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x3ad;
  do {
    tisp_af_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3bf);
  return 0;
}



undefined4 tisp_af_set_par_cfg(void *param_1)

{
  int iVar1;
  size_t local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x3ad;
  do {
    tisp_af_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3c0);
  return 0;
}



undefined4 tisp_hldc_get_par_cfg(void *param_1,int *param_2)

{
  int local_10 [2];
  
  *param_2 = 0;
  local_10[0] = 0;
  tisp_hldc_param_array_get(0x3ac,param_1,local_10);
  *param_2 = *param_2 + local_10[0];
  return 0;
}



undefined4 tisp_hldc_set_par_cfg(void *param_1)

{
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  tisp_hldc_param_array_set(0x3ac,param_1,local_10);
  return 0;
}



undefined4 tisp_ae_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 1;
  do {
    tisp_ae_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x23);
  return 0;
}



undefined4 tisp_ae_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 1;
  do {
    tisp_ae_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x23);
  return 0;
}



undefined4 tisp_awb_get_par_cfg(void *param_1,int *param_2)

{
  int iVar1;
  size_t local_20 [2];
  
  local_20[0] = 0;
  *param_2 = 0;
  iVar1 = 0x23;
  do {
    tisp_awb_param_array_get(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
    *param_2 = *param_2 + local_20[0];
  } while (iVar1 != 0x3c);
  return 0;
}



undefined4 tisp_awb_set_par_cfg(void *param_1)

{
  int iVar1;
  int local_20 [3];
  
  local_20[0] = 0;
  iVar1 = 0x23;
  do {
    tisp_awb_param_array_set(iVar1,param_1,local_20);
    iVar1 = iVar1 + 1;
    param_1 = (void *)((int)param_1 + local_20[0]);
  } while (iVar1 != 0x3c);
  return 0;
}



// WARNING: Type propagation algorithm not settling

undefined4 tisp_code_tuning_ioctl(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_gp;
  
  if (((param_2 << 0x10) >> 0x18 != 0x74) || (0x32 < (param_2 & 0xff))) {
    isp_printf();
    return 0xffffffea;
  }
  switch(param_2) {
  case 0x20007400:
    uVar2 = param_3 + 0x500c | param_3;
    if ((uVar2 & *(uint *)(unaff_gp + 0x18)) != 0) {
LAB_00023a48:
      memset(tisp_par_ioctl,0,0x500c);
      goto LAB_00023a60;
    }
    iVar3 = 0x500c;
    __copy_user(tisp_par_ioctl,param_3);
    if (iVar3 != 0) goto LAB_00023a60;
    switch(*tisp_par_ioctl) {
    case 0:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_top_param_array_get;
      break;
    case 1:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_blc_get_par_cfg;
      break;
    case 2:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_lsc_get_par_cfg;
      break;
    case 3:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_wdr_get_par_cfg;
      break;
    case 4:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_dpc_get_par_cfg;
      break;
    case 5:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_gib_get_par_cfg;
      break;
    case 6:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_rdns_get_par_cfg;
      break;
    case 7:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_adr_get_par_cfg;
      break;
    case 8:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_dmsc_get_par_cfg;
      break;
    case 9:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_ccm_get_par_cfg;
      break;
    case 10:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_gamma_get_par_cfg;
      break;
    case 0xb:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_defog_get_par_cfg;
      break;
    case 0xc:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_mdns_get_par_cfg;
      break;
    case 0xd:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_ydns_get_par_cfg;
      break;
    case 0xe:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_bcsh_get_par_cfg;
      break;
    case 0xf:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_clm_get_par_cfg;
      break;
    case 0x10:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_ysp_get_par_cfg;
      break;
    case 0x11:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_sdns_get_par_cfg;
      break;
    case 0x12:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_af_get_par_cfg;
      break;
    case 0x13:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_hldc_get_par_cfg;
      break;
    case 0x14:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_ae_get_par_cfg;
      break;
    case 0x15:
      puVar5 = tisp_par_ioctl + 3;
      pcVar4 = tisp_awb_get_par_cfg;
      break;
    case 0x16:
      goto switchD_00023aa0_caseD_16;
    case 0x17:
      tisp_reg_map_get(tisp_par_ioctl[2],(int)tisp_par_ioctl,tisp_par_ioctl + 1);
      uVar1 = *(uint *)(unaff_gp + 0x18);
      goto LAB_00023c98;
    case 0x18:
      pcVar4 = tisp_dn_mode_get;
      puVar5 = tisp_par_ioctl;
      break;
    default:
      uVar1 = *(uint *)(unaff_gp + 0x18);
      goto LAB_00023c98;
    }
    (*pcVar4)(puVar5,tisp_par_ioctl + 1);
switchD_00023aa0_caseD_16:
    uVar1 = *(uint *)(unaff_gp + 0x18);
LAB_00023c98:
    uVar2 = uVar2 & uVar1;
    goto joined_r0x00023f74;
  case 0x20007401:
    if (((param_3 + 0x500c | param_3) & *(uint *)(unaff_gp + 0x18)) != 0) goto LAB_00023a48;
    iVar6 = 0x500c;
    iVar3 = __copy_user(tisp_par_ioctl,param_3);
    puVar5 = *(undefined4 **)(iVar3 + 0x3f54);
    if (iVar6 != 0) goto LAB_00023a60;
    switch(*puVar5) {
    case 1:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_blc_set_par_cfg;
      break;
    case 2:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_lsc_set_par_cfg;
      break;
    case 3:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_wdr_set_par_cfg;
      break;
    case 4:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_dpc_set_par_cfg;
      break;
    case 5:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_gib_set_par_cfg;
      break;
    case 6:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_rdns_set_par_cfg;
      break;
    case 7:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_adr_set_par_cfg;
      break;
    case 8:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_dmsc_set_par_cfg;
      break;
    case 9:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_ccm_set_par_cfg;
      break;
    case 10:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_gamma_set_par_cfg;
      break;
    case 0xb:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_defog_set_par_cfg;
      break;
    case 0xc:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_mdns_set_par_cfg;
      break;
    case 0xd:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_ydns_set_par_cfg;
      break;
    case 0xe:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_bcsh_set_par_cfg;
      break;
    case 0xf:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_clm_set_par_cfg;
      break;
    case 0x10:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_ysp_set_par_cfg;
      break;
    case 0x11:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_sdns_set_par_cfg;
      break;
    case 0x12:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_af_set_par_cfg;
      break;
    case 0x13:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_hldc_set_par_cfg;
      break;
    case 0x14:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_ae_set_par_cfg;
      break;
    case 0x15:
      puVar5 = puVar5 + 3;
      pcVar4 = tisp_awb_set_par_cfg;
      break;
    case 0x16:
    default:
      isp_printf();
      return 0;
    case 0x17:
      pcVar4 = tisp_reg_map_set;
      break;
    case 0x18:
      pcVar4 = tisp_dn_mode_set;
    }
    break;
  case 0x20007402:
  case 0x20007405:
    goto switchD_000239fc_caseD_20007402;
  case 0x20007403:
    pcVar4 = tisp_get_ae_info;
    goto LAB_00023f5c;
  case 0x20007404:
    if (((param_3 + 0x500c | param_3) & *(uint *)(unaff_gp + 0x18)) != 0) {
      memset(tisp_par_ioctl,0,0x500c);
LAB_00024014:
      isp_printf();
      return 0xfffffff2;
    }
    iVar6 = 0x500c;
    iVar3 = __copy_user(tisp_par_ioctl,param_3);
    if (iVar6 != 0) goto LAB_00024014;
    puVar5 = *(undefined4 **)(iVar3 + 0x3f54);
    pcVar4 = tisp_set_ae_info;
    break;
  case 0x20007406:
    pcVar4 = tisp_get_awb_info;
LAB_00023f5c:
    (*pcVar4)(tisp_par_ioctl);
    uVar2 = (param_3 + 0x500c | param_3) & *(uint *)(unaff_gp + 0x18);
joined_r0x00023f74:
    if (uVar2 == 0) {
      iVar3 = 0x500c;
      __copy_user(param_3,tisp_par_ioctl);
      if (iVar3 == 0) {
        return 0;
      }
    }
LAB_00023a60:
    isp_printf();
    return 0xfffffff2;
  case 0x20007407:
    if (((param_3 + 0x500c | param_3) & *(uint *)(unaff_gp + 0x18)) != 0) {
      memset(tisp_par_ioctl,0,0x500c);
      goto LAB_00024014;
    }
    iVar6 = 0x500c;
    iVar3 = __copy_user(tisp_par_ioctl,param_3);
    puVar5 = *(undefined4 **)(iVar3 + 0x3f54);
    if (iVar6 != 0) goto LAB_00024014;
    pcVar4 = tisp_set_awb_info;
    break;
  default:
    return 0;
  }
  (*pcVar4)(puVar5);
switchD_000239fc_caseD_20007402:
  return 0;
}



undefined4 tisp_code_create_tuning_node(void)

{
  uint local_18 [2];
  
  if (major == 0) {
    alloc_chrdev_region(local_18,0,1,&_LC9);
    major = local_18[0] >> 0x14;
  }
  else {
    local_18[0] = major << 0x14;
    register_chrdev_region(local_18[0],1,&_LC9);
  }
  cdev_init(tisp_cdev,tisp_fops);
  cdev_add(tisp_cdev,local_18[0],1);
  cls = __class_create(&__this_module,&_LC9,0x10000);
  device_create(cls,0,major << 0x14,0,&_LC9);
  return 0;
}



undefined4 tisp_param_operate_init(void)

{
  undefined4 uVar1;
  
  opmsg = private_kmalloc();
  if (opmsg == 0) {
    isp_printf();
    uVar1 = 0xffffffff;
  }
  else {
    tisp_code_create_tuning_node();
    uVar1 = 0;
  }
  return uVar1;
}



void tisp_code_destroy_tuning_node(void)

{
  int iVar1;
  
  iVar1 = major;
  cdev_del(tisp_cdev);
  device_destroy(cls,major << 0x14);
  class_destroy(cls);
  unregister_chrdev_region(iVar1 << 0x14,1);
  major = 0;
  return;
}



undefined4 tisp_again_update(void)

{
  return 0;
}



undefined4 tisp_ae_ir_update(uint param_1)

{
  tisp_gib_deir_ir_update(param_1);
  return 0;
}



undefined4 tisp_ct_update(uint param_1)

{
  uint uVar1;
  
  uVar1 = system_reg_read(0xc);
  if ((uVar1 & 0x200) == 0) {
    tisp_ccm_ct_update(param_1);
  }
  if ((uVar1 & 0x40) == 0) {
    tisp_lsc_ct_update(param_1);
  }
  if (-1 < (int)(uVar1 << 0xf)) {
    tisp_bcsh_ct_update(param_1);
  }
  return 0;
}



undefined4 tisp_ev_update(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = system_reg_read(0xc);
  if ((ev_last != param_1) || (uVar1 = ev_last, iVar2 = DAT_000b41dc, DAT_000b41dc != param_2)) {
    tisp_awb_ev_update(param_1);
    tisp_ccm_ev_update(param_1);
    if ((uVar3 & 0x80) == 0) {
      tisp_adr_ev_update(param_1,param_2);
    }
    if ((uVar3 & 0x800) == 0) {
      tisp_defog_ev_update(param_1,param_2);
    }
    tisp_bcsh_ev_update(param_1);
    uVar1 = param_1;
    iVar2 = param_2;
    if ((uVar3 & 8) == 0) {
      tisp_wdr_ev_update(param_1,param_2);
      uVar1 = param_1;
      iVar2 = param_2;
    }
  }
  DAT_000b41dc = iVar2;
  ev_last = uVar1;
  return 0;
}



undefined4 tisp_tgain_update(uint param_1,int param_2)

{
  tisp_gib_gain_interpolation(param_1);
  tisp_gb_blc_again_interp(param_1,0);
  tisp_dmsc_refresh(param_1);
  tisp_sharpen_refresh(param_1);
  tisp_sdns_refresh(param_1);
  tisp_dpc_refresh(param_1);
  tisp_lsc_gain_update(param_1,param_2);
  tisp_ydns_gain_update(param_1);
  tisp_rdns_gain_update(param_1);
  tisp_mdns_refresh(param_1);
  return 0;
}



undefined4 tisp_deinit(void)

{
  int iVar1;
  
  iVar1 = tisp_param_operate_deinit();
  if (iVar1 != 0) {
    isp_printf();
  }
  iVar1 = tisp_event_exit();
  if (iVar1 != 0) {
    isp_printf();
  }
  if (DAT_000b416c != 0) {
    private_kfree();
    DAT_000b416c = 0;
  }
  if (DAT_000b4184 != 0) {
    private_kfree();
    DAT_000b4184 = 0;
  }
  if (DAT_000b419c != 0) {
    private_kfree();
    DAT_000b419c = 0;
  }
  if (DAT_000b41a8 != 0) {
    private_kfree();
    DAT_000b41a8 = 0;
  }
  if (DAT_000b41b4 != 0) {
    private_kfree();
    DAT_000b41b4 = 0;
  }
  if (DAT_000b41c0 != 0) {
    private_kfree();
    DAT_000b41c0 = 0;
  }
  if (DAT_000b41cc != 0) {
    private_kfree();
    DAT_000b41cc = 0;
  }
  if (tparams_day != 0) {
    private_vfree();
    tparams_day = 0;
  }
  if (tparams_night != 0) {
    private_vfree();
    tparams_night = 0;
  }
  if (tparams_cust != 0) {
    private_vfree();
    tparams_cust = 0;
  }
  tisp_deinit_free();
  return 0;
}



undefined4 tisp_fw_process(void)

{
  tisp_event_process();
  return 0;
}



undefined4 tisp_channel_start(uint param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *unaff_s2;
  uint uVar3;
  int iVar4;
  
  if (msca_ch_en == 0xffffffff) {
    msca_ch_en = 0;
  }
  msca_ch_en = msca_ch_en | 1 << (param_1 & 0x1f);
  uVar2 = msca_dmaout_arb | 0xe;
  bVar1 = msca_dmaout_arb != 0xffffffff;
  msca_dmaout_arb = 0xe;
  if (bVar1) {
    msca_dmaout_arb = uVar2;
  }
  if (param_1 == 1) {
    unaff_s2 = &ds1_attr;
  }
  else if (param_1 == 2) {
    unaff_s2 = &ds2_attr;
  }
  else if (param_1 == 0) {
    unaff_s2 = &ds0_attr;
  }
  else {
    isp_printf();
  }
  system_reg_write(0x9818,msca_dmaout_arb);
  uVar2 = DAT_000b4164;
  uVar3 = tispinfo;
  if (unaff_s2[8] == 1) {
    uVar2 = DAT_000b4044;
    uVar3 = DAT_000b4040;
  }
  if (((uint)(unaff_s2[1] << 1) < uVar3) || ((uint)(unaff_s2[2] << 1) < uVar2)) {
    iVar4 = (param_1 + 0x98) * 0x100;
    system_reg_write(iVar4 + 0x1c0,0x40080);
    system_reg_write(iVar4 + 0x1c4,0x40080);
    system_reg_write(iVar4 + 0x1c8,0x40080);
    system_reg_write(iVar4 + 0x1cc,0x40080);
    uVar2 = 1 << (param_1 + 0xb & 0x1f) | 1 << (param_1 + 8 & 0x1f) | msca_ch_en;
  }
  else {
    iVar4 = (param_1 + 0x98) * 0x100;
    system_reg_write(iVar4 + 0x1c0,0x200);
    system_reg_write(iVar4 + 0x1c4,0);
    system_reg_write(iVar4 + 0x1c8,0x200);
    system_reg_write(iVar4 + 0x1cc,0);
    uVar2 = ~(1 << (param_1 + 0xb & 0x1f) | 1 << (param_1 + 8 & 0x1f)) & msca_ch_en;
  }
  msca_ch_en = uVar2 | 0xf0000;
  system_reg_write(0x9804,msca_ch_en);
  system_reg_read(0x9864);
  iVar4 = (param_1 + 0x98) * 0x100;
  system_reg_read(0x9860);
  system_reg_read(iVar4 + 0x180);
  system_reg_read(iVar4 + 0x198);
  system_reg_read(iVar4 + 0x128);
  system_reg_read(iVar4 + 300);
  system_reg_read(iVar4 + 0x104);
  system_reg_read((param_1 + 0x99) * 0x100);
  isp_printf();
  return 0;
}



undefined4 tisp_channel_stop(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 1 << (param_1 & 0x1f);
  if (msca_ch_en == 0xffffffff) {
    msca_ch_en = 0;
  }
  msca_ch_en = msca_ch_en & ~uVar3;
  iVar2 = 0xbb9;
  system_reg_write(0x9804,msca_ch_en);
  do {
    uVar1 = system_reg_read(0x9808);
    iVar2 = iVar2 + -1;
    private_msleep();
    if (iVar2 == 0) {
      isp_printf();
      return 0;
    }
  } while ((uVar1 & uVar3) != 0);
  return 0;
}



undefined4 tisp_channel_fifo_clear(int param_1)

{
  int iVar1;
  
  iVar1 = (param_1 + 0x98) * 0x100;
  system_reg_write(iVar1 + 0x19c,1);
  system_reg_write(iVar1 + 0x1a0,1);
  system_reg_write(iVar1 + 0x1a4,1);
  system_reg_write(iVar1 + 0x1a8,1);
  return 0;
}



undefined4 tisp_channel_attr_set(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *__dest;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  isp_printf();
  __dest = &ds0_attr;
  if (param_1 != 0) {
    if (param_1 == 1) {
      __dest = &ds1_attr;
    }
    else {
      if (param_1 != 2) goto LAB_00024cfc;
      __dest = &ds2_attr;
    }
  }
  memcpy(__dest,param_2,0x34);
LAB_00024cfc:
  if (DAT_000b4034 == 0) {
    DAT_000b4038 = 0;
    DAT_000b403c = 0;
    DAT_000b4040 = tispinfo;
    DAT_000b4044 = DAT_000b4164;
    uVar3 = 0;
  }
  else {
    if ((DAT_000b4164 < DAT_000b4044 + DAT_000b403c) || (tispinfo < DAT_000b4040 + DAT_000b4038)) {
      isp_printf();
      return 0xffffffff;
    }
    uVar3 = DAT_000b4038 << 0x10 | DAT_000b403c;
  }
  uVar2 = DAT_000b4044;
  uVar1 = DAT_000b4040;
  system_reg_write(0x9860,uVar3);
  system_reg_write(0x9864,uVar1 << 0x10 | uVar2);
  if (*param_2 == 0) {
    param_2[1] = uVar1;
    param_2[2] = uVar2;
    uVar3 = uVar1;
    uVar4 = uVar2;
  }
  else {
    uVar3 = param_2[1];
    uVar4 = param_2[2];
  }
  system_reg_write((param_1 + 0x99) * 0x100,uVar3 << 0x10 | uVar4);
  iVar5 = (param_1 + 0x98) * 0x100;
  system_reg_write(iVar5 + 0x104,(uVar1 << 9) / uVar3 << 0x10 | (uVar2 << 9) / uVar4 & 0xffff);
  if (param_2[3] == 0) {
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = uVar3;
    param_2[7] = uVar4;
    uVar1 = uVar4;
    uVar2 = uVar3;
  }
  else {
    uVar1 = param_2[7];
    uVar2 = param_2[6];
    if ((uVar4 < uVar1 + param_2[5]) || (uVar3 < uVar2 + param_2[4])) {
      isp_printf();
      return 0xffffffff;
    }
  }
  system_reg_write(iVar5 + 300,uVar2 << 0x10 | uVar1);
  system_reg_write(iVar5 + 0x128,param_2[4] << 0x10 | param_2[5]);
  system_reg_write(iVar5 + 0x180,uVar2);
  system_reg_write(iVar5 + 0x198,uVar2);
  return 0;
}



undefined4 tiziano_load_parameters(void)

{
  char cVar1;
  char cVar2;
  void *pvVar3;
  char *param0;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  char cVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  int iVar17;
  char acStack_70 [64];
  undefined4 local_30;
  code *local_2c;
  
  param0 = (char *)private_vmalloc();
  if (param0 == (char *)0x0) {
    isp_printf();
    return 0xffffffff;
  }
  memset(param0,0,0x34);
  snprintf(param0,8,"%s","2.10");
  snprintf(param0 + 8,8,"header%d",0);
  snprintf(acStack_70,0x40,"/etc/sensor/%s-t31.bin",&DAT_000b4054);
  uVar4 = private_filp_open();
  if (0xfffff000 < uVar4) {
    isp_printf();
    return 0xffffffff;
  }
  uVar15 = *(uint *)(*(int *)(uVar4 + 0x10) + 0x30);
  iVar17 = *(int *)(*(int *)(uVar4 + 0x10) + 0x34);
  private_get_fs(&local_30);
  private_set_fs();
  if (*(int *)(param0 + 0x28) == 0) {
    local_2c = (code *)(uVar4 + 0x30);
    iVar5 = private_vmalloc();
    *(int *)(param0 + 0x28) = iVar5;
    if (iVar5 != 0) {
      *(uint *)(param0 + 0x2c) = uVar15;
      goto LAB_000250dc;
    }
LAB_000253bc:
    isp_printf();
  }
  else {
LAB_000250dc:
    if ((iVar17 < 1) && ((iVar17 != 0 || (uVar15 <= *(uint *)(param0 + 0x2c))))) {
      private_vfs_read();
      private_filp_close();
      private_set_fs();
      pcVar16 = *(char **)(param0 + 0x28);
      iVar17 = 8;
      iVar5 = 8;
      pcVar6 = param0;
      pcVar7 = pcVar16;
      while( true ) {
        cVar1 = *pcVar6;
        cVar2 = *pcVar7;
        cVar12 = cVar2;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar6 = pcVar6 + 1;
        cVar12 = cVar1;
        if ((cVar2 != cVar1) || (pcVar7 = pcVar7 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
      }
      pcVar6 = param0 + 8;
      if (cVar12 != cVar2) {
        isp_printf();
        isp_printf();
LAB_000254c4:
        isp_printf();
        isp_printf();
        goto LAB_00025660;
      }
      pcVar8 = pcVar16 + 8;
      pcVar7 = pcVar6;
      while( true ) {
        cVar1 = *pcVar7;
        cVar2 = *pcVar8;
        cVar12 = cVar2;
        if (iVar17 == 0) break;
        iVar17 = iVar17 + -1;
        pcVar7 = pcVar7 + 1;
        cVar12 = cVar1;
        if ((cVar2 != cVar1) || (pcVar8 = pcVar8 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
      }
      if (cVar12 == cVar2) {
        uVar4 = *(uint *)(pcVar16 + 0x10);
        puVar11 = (uint *)(pcVar16 + 0x18);
        *(uint *)(param0 + 0x10) = uVar4;
        uVar13 = *(uint *)(pcVar16 + 0x14);
        *(uint *)(param0 + 0x14) = uVar13;
        pvVar3 = tparams_day;
        uVar15 = 0;
        puVar10 = puVar11;
        for (uVar9 = 0; uVar9 != uVar4 >> 2; uVar9 = uVar9 + 1) {
          uVar14 = *puVar10;
          puVar10 = puVar10 + 1;
          uVar15 = *(uint *)(crc_table + ((uVar15 ^ uVar14) & 7) * 4) ^ uVar15 ^ uVar14;
        }
        if (uVar13 == uVar15) {
          *(uint **)(param0 + 0x30) = puVar11;
          local_2c = memcpy;
          memcpy(pvVar3,puVar11,0x137f0);
          (*local_2c)(tparams_night,pcVar16 + 0x13808,0x137f0);
          snprintf(acStack_70,0x40,"/etc/sensor/%s-cust-t31.bin",&DAT_000b4054);
          uVar4 = private_filp_open();
          if (0xfffff000 < uVar4) {
            isp_printf();
            goto LAB_00025628;
          }
          uVar15 = *(uint *)(*(int *)(uVar4 + 0x10) + 0x30);
          iVar17 = *(int *)(*(int *)(uVar4 + 0x10) + 0x34);
          private_get_fs(&local_30);
          private_set_fs();
          if (*(int *)(param0 + 0x28) == 0) {
            local_2c = (code *)(uVar4 + 0x30);
            iVar5 = private_vmalloc();
            *(int *)(param0 + 0x28) = iVar5;
            if (iVar5 == 0) goto LAB_000253bc;
            *(uint *)(param0 + 0x2c) = uVar15;
          }
          if ((0 < iVar17) || ((iVar17 == 0 && (*(uint *)(param0 + 0x2c) < uVar15))))
          goto LAB_00025400;
          private_vfs_read();
          private_filp_close();
          private_set_fs();
          pcVar8 = *(char **)(param0 + 0x28);
          iVar17 = 8;
          iVar5 = 8;
          pcVar7 = param0;
          pcVar16 = pcVar8;
          while( true ) {
            cVar1 = *pcVar7;
            cVar2 = *pcVar16;
            cVar12 = cVar2;
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            pcVar7 = pcVar7 + 1;
            cVar12 = cVar1;
            if ((cVar2 != cVar1) || (pcVar16 = pcVar16 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
          }
          pcVar7 = pcVar8 + 8;
          if (cVar12 != cVar2) {
            isp_printf();
            isp_printf();
            goto LAB_000254c4;
          }
          while( true ) {
            cVar1 = *pcVar6;
            cVar2 = *pcVar7;
            cVar12 = cVar2;
            if (iVar17 == 0) break;
            iVar17 = iVar17 + -1;
            pcVar6 = pcVar6 + 1;
            cVar12 = cVar1;
            if ((cVar2 != cVar1) || (pcVar7 = pcVar7 + 1, cVar12 = cVar2, cVar1 == '\0')) break;
          }
          if (cVar12 != cVar2) {
            isp_printf();
            goto LAB_00025534;
          }
          uVar4 = *(uint *)(pcVar8 + 0x10);
          puVar11 = (uint *)(pcVar8 + 0x18);
          *(uint *)(param0 + 0x10) = uVar4;
          uVar13 = *(uint *)(pcVar8 + 0x14);
          *(uint *)(param0 + 0x14) = uVar13;
          uVar15 = 0;
          puVar10 = puVar11;
          for (uVar9 = 0; uVar9 != uVar4 >> 2; uVar9 = uVar9 + 1) {
            uVar14 = *puVar10;
            puVar10 = puVar10 + 1;
            uVar15 = *(uint *)(crc_table + ((uVar15 ^ uVar14) & 7) * 4) ^ uVar15 ^ uVar14;
          }
          if (uVar13 == uVar15) {
            tparams_cust = (void *)private_vmalloc();
            memset(tparams_cust,0,0x137f0);
            pvVar3 = tparams_cust;
            *(uint **)(param0 + 0x30) = puVar11;
            memcpy(pvVar3,puVar11,0x137f0);
LAB_00025628:
            private_vfree();
            private_vfree();
            return 0;
          }
        }
        isp_printf();
      }
      else {
        isp_printf();
LAB_00025534:
        isp_printf();
        isp_printf();
      }
    }
    else {
LAB_00025400:
      isp_printf();
    }
  }
  private_filp_close();
  private_set_fs();
LAB_00025660:
  private_kfree();
  private_kfree();
  return 0xffffffff;
}



// WARNING: Restarted to delay deadcode elimination for space: ram

undefined4 tisp_init(uint *param_1)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  memset(&tispinfo,0,0x74);
  memset(&sensor_info,0,0x60);
  memset(&ds0_attr,0,0x34);
  memset(&ds1_attr,0,0x34);
  memset(&ds2_attr,0,0x34);
  memcpy(&sensor_info,param_1,0x60);
  tparams_day = (void *)private_vmalloc();
  memset(tparams_day,0,0x137f0);
  tparams_night = (void *)private_vmalloc();
  memset(tparams_night,0,0x137f0);
  tparams_cust = (void *)private_vmalloc();
  memset(tparams_cust,0,0x137f0);
  iVar6 = tiziano_load_parameters();
  pvVar5 = tparams_day;
  pvVar4 = tparams_night;
  pvVar3 = tparams_cust;
  if (isp_memopt == 1) {
    *(undefined4 *)((int)tparams_day + 0xbb58) = 1;
    *(undefined4 *)((int)pvVar5 + 0xbb50) = 0;
    *(undefined4 *)((int)pvVar5 + 0xbb68) = 0;
    *(undefined4 *)((int)pvVar5 + 0xbb60) = 0;
    *(undefined4 *)((int)pvVar4 + 0xbb58) = 1;
    *(undefined4 *)((int)pvVar4 + 0xbb50) = 0;
    *(undefined4 *)((int)pvVar4 + 0xbb68) = 0;
    *(undefined4 *)((int)pvVar4 + 0xbb60) = 0;
    *(undefined4 *)((int)pvVar3 + 0xbb58) = 1;
    *(undefined4 *)((int)pvVar3 + 0xbb50) = 0;
    *(undefined4 *)((int)pvVar3 + 0xbb68) = 0;
    *(undefined4 *)((int)pvVar3 + 0xbb60) = 0;
    iVar9 = 0;
    do {
      *(undefined4 *)((int)pvVar5 + iVar9 + 0xd838) = 0;
      *(undefined4 *)((int)pvVar4 + iVar9 + 0xd838) = 0;
      iVar2 = iVar9 + 0xd838;
      iVar9 = iVar9 + 4;
      *(undefined4 *)((int)pvVar3 + iVar2) = 0;
    } while (iVar9 != 0x24);
  }
  if (iVar6 == 0) {
    memcpy(&DAT_00095d30,tparams_day,0x137f0);
    uVar12 = *param_1;
  }
  else {
    isp_printf();
    uVar12 = *param_1;
  }
  system_reg_write(4,uVar12 << 0x10 | param_1[1]);
  uVar12 = *param_1;
  uVar10 = param_1[1];
  tispinfo = uVar12;
  DAT_000b4164 = uVar10;
  switch(param_1[2]) {
  case 0:
    uVar13 = 0;
    goto LAB_00025928;
  case 1:
    uVar13 = 1;
    goto LAB_00025928;
  case 2:
    uVar13 = 2;
    goto LAB_00025928;
  case 3:
    uVar13 = 3;
LAB_00025928:
    system_reg_write(8,uVar13);
    deir_en = 0;
    goto LAB_000259fc;
  case 4:
    uVar13 = 8;
    break;
  case 5:
    uVar13 = 9;
    break;
  case 6:
    uVar13 = 10;
    break;
  case 7:
    uVar13 = 0xb;
    break;
  case 8:
    uVar13 = 0xc;
    break;
  case 9:
    uVar13 = 0xd;
    break;
  case 10:
    uVar13 = 0xe;
    break;
  case 0xb:
    uVar13 = 0xf;
    break;
  case 0xc:
    uVar13 = 0x10;
    break;
  case 0xd:
    uVar13 = 0x11;
    break;
  case 0xe:
    uVar13 = 0x12;
    break;
  case 0xf:
    uVar13 = 0x13;
    break;
  case 0x10:
    uVar13 = 0x14;
    break;
  case 0x11:
    uVar13 = 0x15;
    break;
  case 0x12:
    uVar13 = 0x16;
    break;
  case 0x13:
    uVar13 = 0x17;
    break;
  default:
    isp_printf();
    goto LAB_000259fc;
  }
  system_reg_write(8,uVar13);
  deir_en = 1;
LAB_000259fc:
  uVar13 = 0x3f00;
  if (deir_en == 1) {
    uVar13 = 0x10003f00;
  }
  system_reg_write(0x1c,uVar13);
  sensor_init(0xb40ac);
  tisp_set_csc_version(0);
  isp_printf();
  uVar14 = 0x8077efff;
  uVar7 = 0;
  do {
    uVar8 = uVar7 & 0x1f;
    piVar11 = &DAT_00095d30 + uVar7;
    uVar1 = uVar7 & 0x1f;
    uVar7 = uVar7 + 1;
    uVar14 = (*piVar11 << uVar1) + (uVar14 & ~(1 << uVar8));
  } while (uVar7 != 0x20);
  isp_printf();
  if (DAT_000b40a4 == 1) {
    uVar7 = 0xa1ffdf76;
    uVar8 = 0x880002;
  }
  else {
    uVar7 = 0xb577fffd;
    uVar8 = 0x34000009;
  }
  system_reg_write(0xc,uVar14 & uVar7 | uVar8);
  isp_printf();
  system_reg_write(0x30,0xffffffff);
  uVar13 = 0x33f;
  if (DAT_000b40a4 != 1) {
    uVar13 = 0x133;
  }
  system_reg_write(0x10,uVar13);
  iVar6 = private_kmalloc();
  if (iVar6 != 0) {
    system_reg_write(0xa02c,iVar6 + -0x80000000);
    system_reg_write(0xa030,iVar6 + -0x7ffff000);
    system_reg_write(0xa034,iVar6 + -0x7fffe000);
    system_reg_write(0xa038,iVar6 + -0x7fffd000);
    system_reg_write(0xa03c,iVar6 + -0x7fffc000);
    system_reg_write(0xa040,iVar6 + -0x7fffb800);
    system_reg_write(0xa044,iVar6 + -0x7fffb000);
    system_reg_write(0xa048,iVar6 + -0x7fffa800);
    system_reg_write(0xa04c,0x33);
    DAT_000b4168 = 4;
    DAT_000b4178 = iVar6 + 0x4000;
    DAT_000b4174 = 4;
    DAT_000b416c = iVar6;
    DAT_000b4170 = iVar6 + -0x80000000;
    DAT_000b417c = iVar6 + -0x7fffc000;
    iVar6 = private_kmalloc();
    if (iVar6 != 0) {
      system_reg_write(0xa82c,iVar6 + -0x80000000);
      system_reg_write(0xa830,iVar6 + -0x7ffff000);
      system_reg_write(0xa834,iVar6 + -0x7fffe000);
      system_reg_write(0xa838,iVar6 + -0x7fffd000);
      system_reg_write(0xa83c,iVar6 + -0x7fffc000);
      system_reg_write(0xa840,iVar6 + -0x7fffb800);
      system_reg_write(0xa844,iVar6 + -0x7fffb000);
      system_reg_write(0xa848,iVar6 + -0x7fffa800);
      system_reg_write(0xa84c,0x33);
      DAT_000b4180 = 4;
      DAT_000b4190 = iVar6 + 0x4000;
      DAT_000b418c = 4;
      DAT_000b4184 = iVar6;
      DAT_000b4188 = iVar6 + -0x80000000;
      DAT_000b4194 = iVar6 + -0x7fffc000;
      iVar6 = private_kmalloc();
      if (iVar6 != 0) {
        system_reg_write(0xb03c,iVar6 + -0x80000000);
        system_reg_write(0xb040,iVar6 + -0x7ffff000);
        system_reg_write(0xb044,iVar6 + -0x7fffe000);
        system_reg_write(0xb048,iVar6 + -0x7fffd000);
        system_reg_write(0xb04c,3);
        DAT_000b4198 = 4;
        DAT_000b419c = iVar6;
        DAT_000b41a0 = iVar6 + -0x80000000;
        iVar6 = private_kmalloc();
        if (iVar6 != 0) {
          system_reg_write(0x4494,iVar6 + -0x80000000);
          system_reg_write(0x4498,iVar6 + -0x7ffff000);
          system_reg_write(0x449c,iVar6 + -0x7fffe000);
          system_reg_write(0x44a0,iVar6 + -0x7fffd000);
          system_reg_write(0x4490,3);
          DAT_000b41a4 = 4;
          DAT_000b41a8 = iVar6;
          DAT_000b41ac = iVar6 + -0x80000000;
          iVar6 = private_kmalloc();
          if (iVar6 != 0) {
            system_reg_write(0x5b84,iVar6 + -0x80000000);
            system_reg_write(0x5b88,iVar6 + -0x7ffff000);
            system_reg_write(0x5b8c,iVar6 + -0x7fffe000);
            system_reg_write(0x5b90,iVar6 + -0x7fffd000);
            system_reg_write(0x5b80,3);
            DAT_000b41b0 = 4;
            DAT_000b41b4 = iVar6;
            DAT_000b41b8 = iVar6 + -0x80000000;
            isp_printf();
            iVar6 = private_kmalloc();
            if (iVar6 != 0) {
              system_reg_write(0xb8a8,iVar6 + -0x80000000);
              system_reg_write(0xb8ac,iVar6 + -0x7ffff000);
              system_reg_write(0xb8b0,iVar6 + -0x7fffe000);
              system_reg_write(0xb8b4,iVar6 + -0x7fffd000);
              system_reg_write(0xb8b8,3);
              DAT_000b41bc = 4;
              DAT_000b41c0 = iVar6;
              DAT_000b41c4 = iVar6 + -0x80000000;
              iVar6 = private_kmalloc();
              if (iVar6 != 0) {
                system_reg_write(0x2010,iVar6 + -0x80000000);
                system_reg_write(0x2014,iVar6 + -0x7fffe000);
                system_reg_write(0x2018,iVar6 + -0x7fffc000);
                system_reg_write(0x201c,iVar6 + -0x7fffa000);
                system_reg_write(0x2020,0x400);
                system_reg_write(0x2024,3);
                DAT_000b41c8 = 4;
                DAT_000b41cc = iVar6;
                DAT_000b41d0 = iVar6 + -0x80000000;
                tiziano_ae_init(DAT_000b4164,tispinfo,(uint)*(ushort *)(param_1 + 0xc));
                tiziano_awb_init(DAT_000b4164,tispinfo);
                tiziano_gamma_init();
                tiziano_gib_init();
                tiziano_lsc_init();
                tiziano_ccm_init();
                tiziano_dmsc_init();
                tiziano_sharpen_init();
                tiziano_sdns_init();
                tiziano_mdns_init(uVar12,uVar10);
                tiziano_clm_init();
                tiziano_dpc_init();
                tiziano_hldc_init();
                tiziano_defog_init(uVar12,uVar10);
                tiziano_adr_init(uVar12,uVar10);
                tiziano_af_init(uVar10,uVar12);
                tiziano_bcsh_init();
                tiziano_ydns_init();
                tiziano_rdns_init();
                if (DAT_000b40a4 == 1) {
                  tiziano_wdr_init(uVar12,uVar10);
                  tisp_gb_init();
                  tisp_dpc_wdr_en(1);
                  tisp_lsc_wdr_en(1);
                  tisp_gamma_wdr_en(1);
                  tisp_sharpen_wdr_en(1);
                  tisp_ccm_wdr_en(1);
                  tisp_bcsh_wdr_en(1);
                  tisp_rdns_wdr_en(1);
                  tisp_adr_wdr_en(1);
                  tisp_defog_wdr_en(1);
                  tisp_mdns_wdr_en(1);
                  tisp_dmsc_wdr_en(1);
                  tisp_ae_wdr_en(1);
                  tisp_sdns_wdr_en(1);
                }
                uVar13 = 0x1c;
                if (DAT_000b40a4 != 0) {
                  uVar13 = 0x10;
                }
                system_reg_write(0x804,uVar13);
                system_reg_write(0x1c,8);
                system_reg_write(0x800,1);
                tisp_event_init();
                tisp_event_set_cb(4,tisp_tgain_update);
                tisp_event_set_cb(5,tisp_again_update);
                tisp_event_set_cb(7,tisp_ev_update);
                tisp_event_set_cb(9,tisp_ct_update);
                tisp_event_set_cb(8,tisp_ae_ir_update);
                iVar6 = tisp_param_operate_init();
                if (iVar6 == 0) {
                  return 0;
                }
                isp_printf();
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}



undefined4 tiziano_sync_sensor_attr(undefined4 *param_1)

{
  sensor_info = *param_1;
  DAT_000b404c = param_1[1];
  DAT_000b4064 = tisp_math_exp2(param_1[7],0x10,10);
  DAT_000b4068 = tisp_math_exp2(param_1[8],0x10,10);
  DAT_000b4074 = param_1[0xb];
  DAT_000b4078 = *(ushort *)(param_1 + 0xc);
  DAT_000b407a = *(undefined2 *)((int)param_1 + 0x32);
  DAT_000b407c = *(undefined2 *)(param_1 + 0xd);
  DAT_000b407e = *(undefined2 *)((int)param_1 + 0x36);
  DAT_000b4084 = *(undefined2 *)(param_1 + 0xf);
  DAT_000b4086 = *(undefined2 *)((int)param_1 + 0x3e);
  DAT_000b4088 = *(ushort *)(param_1 + 0x10);
  DAT_000b408a = *(undefined2 *)((int)param_1 + 0x42);
  DAT_000b408c = *(undefined2 *)(param_1 + 0x11);
  DAT_000b408e = *(undefined2 *)((int)param_1 + 0x46);
  DAT_000b4090 = *(undefined2 *)(param_1 + 0x12);
  DAT_000b4092 = *(ushort *)((int)param_1 + 0x4a);
  DAT_000b4094 = *(ushort *)(param_1 + 0x13);
  DAT_000b409c = tisp_math_exp2(param_1[0x15],0x10,10);
  if ((DAT_000d3af0 == 0) || (DAT_000d3af0 == DAT_000b4064)) {
    DAT_000d3af0 = DAT_000b4064;
  }
  DAT_000d3af4 = DAT_000b4068;
  DAT_000d3b2c = DAT_000b409c;
  DAT_000d3b54 = (uint)DAT_000b4078;
  DAT_000d3b30 = (uint)DAT_000b4094;
  DAT_000d3b60 = (uint)DAT_000b4092;
  DAT_000d3af8 = (uint)DAT_000b4088;
  sensor_ctrl._32_4_ = param_1[7];
  sensor_ctrl._84_4_ = (uint)DAT_000b4094;
  sensor_ctrl._40_4_ = (uint)DAT_000b4078;
  sensor_ctrl._36_4_ = param_1[8];
  sensor_ctrl._44_4_ = (uint)DAT_000b4088;
  sensor_ctrl._80_4_ = (uint)DAT_000b4092;
  sensor_ctrl[58] = (char)DAT_000b408a;
  sensor_ctrl[59] = (char)DAT_000b408c;
  sensor_ctrl[60] = (char)DAT_000b408e;
  sensor_ctrl._88_4_ = param_1[0x15];
  return 0;
}



undefined4 tisp_event_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DAT_000b45b0 = &DAT_000b45b0;
  DAT_000b45b4 = &DAT_000b45b0;
  DAT_000b45b8 = &DAT_000b45b8;
  DAT_000b45bc = &DAT_000b45b8;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    puVar4 = &DAT_000b41f0 + iVar1 * 0xc;
    *puVar4 = puVar4;
    (&DAT_000b41f4)[iVar1 * 0xc] = puVar4;
    iVar1 = iVar2;
  } while (iVar2 != 0x14);
  iVar1 = 0;
  do {
    puVar4 = DAT_000b45bc;
    iVar2 = iVar1 + 1;
    puVar3 = &DAT_000b41f0 + iVar1 * 0xc;
    DAT_000b45bc = puVar3;
    *puVar3 = &DAT_000b45b8;
    (&DAT_000b41f4)[iVar1 * 0xc] = puVar4;
    *puVar4 = puVar3;
    iVar1 = iVar2;
  } while (iVar2 != 0x14);
  tevent_info = 0;
  __init_waitqueue_head(&DAT_000b41e4,"&x->wait",0x10000);
  return 0;
}



undefined4 tisp_event_set_cb(int param_1,undefined4 param_2)

{
  *(undefined4 *)(cb + param_1 * 4) = param_2;
  return 0;
}



undefined4 tisp_event_push(int param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar3 = Status;
  ppiVar2 = DAT_000b45b8;
  Status = Status & 0xfffffffe;
  if ((int ***)DAT_000b45b8 == &DAT_000b45b8) {
    isp_printf();
    Status = Status & 0xfffffffe;
    if ((uVar3 & 1) != 0) {
      Status = Status | 1;
    }
    uVar5 = 0xffffffff;
  }
  else {
    piVar4 = DAT_000b45b8[1];
    iVar6 = (int)*DAT_000b45b8;
    *(int **)(iVar6 + 4) = piVar4;
    *piVar4 = iVar6;
    *ppiVar2 = (int *)0x100;
    ppiVar2[1] = (int *)0x200;
    ppiVar2[2] = *(int **)(param_1 + 8);
    piVar4 = *(int **)(param_1 + 0x14);
    ppiVar2[4] = *(int **)(param_1 + 0x10);
    ppiVar2[5] = piVar4;
    piVar4 = *(int **)(param_1 + 0x1c);
    ppiVar2[6] = *(int **)(param_1 + 0x18);
    ppiVar2[7] = piVar4;
    piVar4 = *(int **)(param_1 + 0x24);
    ppiVar2[8] = *(int **)(param_1 + 0x20);
    ppiVar2[9] = piVar4;
    piVar4 = *(int **)(param_1 + 0x2c);
    ppiVar2[10] = *(int **)(param_1 + 0x28);
    ppiVar2[0xb] = piVar4;
    ppiVar1 = DAT_000b45b4;
    DAT_000b45b4 = ppiVar2;
    ppiVar2[1] = (int *)ppiVar1;
    *ppiVar2 = &DAT_000b45b0;
    *ppiVar1 = (int *)ppiVar2;
    private_complete();
    Status = Status & 0xfffffffe;
    if ((uVar3 & 1) != 0) {
      Status = Status | 1;
    }
    uVar5 = 0;
  }
  return uVar5;
}



undefined4 tisp_event_exit(void)

{
  undefined auStack_38 [8];
  undefined4 local_30;
  
  local_30 = 0;
  tisp_event_push((int)auStack_38);
  return 0;
}



int tisp_event_process(void)

{
  int **ppiVar1;
  int **ppiVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = private_wait_for_completion_timeout();
  uVar3 = Status;
  ppiVar1 = DAT_000b45b0;
  if (iVar4 == -0x200) {
    isp_printf();
    iVar4 = 0;
  }
  else if (iVar4 != 0) {
    Status = Status & 0xfffffffe;
    if ((int ***)DAT_000b45b0 == &DAT_000b45b0) {
      isp_printf();
      Status = Status & 0xfffffffe;
      if ((uVar3 & 1) != 0) {
        Status = Status | 1;
      }
      iVar4 = -1;
    }
    else {
      piVar5 = DAT_000b45b0[1];
      iVar4 = (int)*DAT_000b45b0;
      *(int **)(iVar4 + 4) = piVar5;
      *piVar5 = iVar4;
      *ppiVar1 = (int *)0x100;
      ppiVar1[1] = (int *)0x200;
      if (*(code **)(cb + (int)ppiVar1[2] * 4) != (code *)0x0) {
        (**(code **)(cb + (int)ppiVar1[2] * 4))
                  (ppiVar1[4],ppiVar1[5],ppiVar1[6],ppiVar1[7],ppiVar1[8],ppiVar1[9],ppiVar1[10],
                   ppiVar1[0xb]);
      }
      ppiVar2 = DAT_000b45bc;
      DAT_000b45bc = ppiVar1;
      *ppiVar1 = &DAT_000b45b8;
      ppiVar1[1] = (int *)ppiVar2;
      *ppiVar2 = (int *)ppiVar1;
      Status = Status & 0xfffffffe;
      if ((uVar3 & 1) != 0) {
        Status = Status | 1;
      }
      iVar4 = 0;
    }
  }
  return iVar4;
}



void system_reg_write_awb_trig_part_0(void)

{
  system_reg_write(0xb000,1);
  return;
}



void system_reg_write_awb_trig(int param_1)

{
  if (param_1 == 1) {
    system_reg_write_awb_trig_part_0();
    return;
  }
  if (param_1 == 2) {
    system_reg_write(0x1800,1);
    return;
  }
  return;
}



void JZ_Isp_Awb_Reg2par(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_98 [16];
  uint local_58 [17];
  
  uVar1 = *param_2;
  iVar4 = 0;
  do {
    uVar9 = *(uint *)((int)param_2 + iVar4 + 4);
    uVar8 = *(uint *)((int)param_2 + iVar4 + 0x14);
    iVar3 = 0;
    do {
      uVar6 = iVar3 * -8;
      uVar7 = 0x7f << (uVar6 & 0x1f);
      iVar2 = iVar3 + -1;
      local_58[iVar4 - iVar3] = (uVar7 & uVar9) >> (uVar6 & 0x1f);
      local_98[iVar4 - iVar3] = (uVar7 & uVar8) >> (uVar6 & 0x1f);
      iVar3 = iVar2;
    } while (iVar2 != -4);
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x10);
  uVar8 = param_2[9];
  uVar9 = param_2[10];
  uVar6 = param_2[0xb];
  uVar7 = param_2[0xc];
  uVar5 = param_2[0xd];
  *param_1 = uVar1 & 0x7ff;
  param_1[1] = (uVar1 << 0x10) >> 0x1c;
  param_1[2] = (uVar1 << 5) >> 0x15;
  param_1[3] = uVar1 >> 0x1c;
  iVar4 = 0;
  do {
    *(undefined4 *)((int)param_1 + iVar4 + 0x10) = *(undefined4 *)((int)local_58 + iVar4);
    iVar3 = iVar4 + 4;
    *(undefined4 *)((int)param_1 + iVar4 + 0x4c) = *(undefined4 *)((int)local_98 + iVar4);
    iVar4 = iVar3;
  } while (iVar3 != 0x3c);
  param_1[0x22] = uVar8 & 0xfff;
  param_1[0x23] = (uVar8 << 4) >> 0x14;
  param_1[0x24] = uVar9 & 0xfff;
  param_1[0x25] = (uVar9 << 4) >> 0x14;
  param_1[0x26] = uVar6 & 0xffff;
  param_1[0x27] = uVar6 >> 0x10;
  param_1[0x28] = uVar7 & 0xffff;
  param_1[0x29] = uVar7 >> 0x10;
  param_1[0x2a] = uVar5 & 0xff;
  param_1[0x2b] = (uVar5 << 0x10) >> 0x18;
  param_1[0x2c] = (uVar5 << 0xc) >> 0x1c;
  return;
}



void JZ_Isp_Awb_Awbg2reg(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1 * 4;
  uVar1 = param_1[1] * 4;
  if ((_awb_trend == 1) && (tawb_custom_en == 0)) {
    if (_awb_ct_last_offset < _awb_ct) {
      uVar3 = _awb_ct - _awb_ct_last_offset;
    }
    else {
      uVar3 = _awb_ct_last_offset - _awb_ct;
    }
    if ((199 < uVar3) || (awb_moa == 1)) {
      _awb_ct_last_offset = _awb_ct;
      if (_awb_ct < 5000) {
        if (_awb_ct < 0xbb9) {
          awb_gr_offset = DAT_000aaf78;
          awb_gb_offset = DAT_000aaf7c;
        }
        else {
          awb_gr_offset = DAT_000aaf70;
          awb_gb_offset = DAT_000aaf74;
        }
      }
      else {
        awb_gr_offset = DAT_000aaf68;
        awb_gb_offset = DAT_000aaf6c;
      }
    }
    uVar2 = uVar2 + awb_gr_offset + -0x400;
    uVar1 = uVar1 + awb_gb_offset + -0x400;
  }
  if (0x3fff < uVar2) {
    uVar2 = 0x3fff;
  }
  *param_2 = uVar2 | 0x4000000;
  if (0x3fff < uVar1) {
    uVar1 = 0x3fff;
  }
  param_2[1] = uVar1 | 0x4000000;
  return;
}



void JZ_Isp_Get_Awb_Statistics(uint *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  for (uVar4 = 0; iVar2 = uVar4 * 0x3c, uVar4 != (param_2 << 0x10) >> 0x1c; uVar4 = uVar4 + 1) {
    puVar1 = param_1;
    for (iVar3 = 0; iVar3 != (param_2 >> 0x1c) << 2; iVar3 = iVar3 + 4) {
      *(uint *)((int)&awb_array_r + iVar3 + iVar2) = *puVar1 & 0x1fffff;
      *(uint *)((int)&awb_array_g + iVar3 + iVar2) = (puVar1[1] & 0x3ff) << 0xb | *puVar1 >> 0x15;
      *(uint *)((int)&awb_array_b + iVar3 + iVar2) = (puVar1[1] & 0x7ffffc00) >> 10;
      *(uint *)((int)&awb_array_ir + iVar3 + iVar2) = (puVar1[2] & 0xfffff) << 1 | puVar1[1] >> 0x1f
      ;
      *(uint *)((int)&awb_array_p + iVar3 + iVar2) = (puVar1[3] & 1) << 0xc | puVar1[2] >> 0x14;
      puVar1 = puVar1 + 4;
    }
    param_1 = param_1 + (param_2 >> 0x1c) * 4;
  }
  return;
}



void Tiziano_awb_set_gain(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  
  local_28 = *(uint *)(param_1 + 0x10);
  local_24 = *(int *)(param_1 + 0x14);
  iVar1 = fix_point_mult2_32(param_2,local_28 << (param_2 & 0x1f),*param_3);
  iVar2 = 1 << (param_2 - 1 & 0x1f);
  local_28 = (uint)(iVar1 + iVar2) >> (param_2 & 0x1f);
  iVar1 = fix_point_mult2_32(param_2,local_24 << (param_2 & 0x1f),param_3[1]);
  local_24 = (uint)(iVar1 + iVar2) >> (param_2 & 0x1f);
  DAT_000b69b4 = 0x10000 / local_28;
  DAT_000b69b8 = 0x10000 / local_24;
  if (tawb_custom_en == 0) {
    if (tisp_wb_attr - 1U < 8) {
      local_28 = DAT_000b69a4;
      local_24 = DAT_000b69a8;
    }
    else if (tisp_wb_attr == 9) {
      local_28 = (DAT_000b69a4 + 0x40) * local_28 >> 6;
      local_24 = local_24 * (DAT_000b69a8 + 0x40) >> 6;
    }
    JZ_Isp_Awb_Awbg2reg((int *)&local_28,&local_30);
    if (awb_frz == 0) {
      system_reg_write(0x1804,local_30);
      system_reg_write(0x1808,local_2c);
      system_reg_write(0x180c,local_30);
      system_reg_write(0x1810,local_2c);
      system_reg_write_awb_trig(2);
      tisp_rdns_awb_gain_updata((uint)local_30._2_2_,(uint)local_2c._2_2_);
    }
  }
  awb_moa = 0;
  return;
}



void Tiziano_awb_fpga(int param_1,int param_2,int param_3,int param_4,uint *param_5,int *param_6,
                     int param_7,uint param_8,uint *param_9,uint *param_10,int param_11,int param_12
                     ,uint param_13)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 extraout_v0;
  uint *puVar7;
  undefined4 extraout_v1;
  undefined *puVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  int iVar26;
  int iVar27;
  undefined8 uVar28;
  int *piVar29;
  int *in_stack_ffffff10;
  int *in_stack_ffffff14;
  int *in_stack_ffffff18;
  int *in_stack_ffffff1c;
  int *in_stack_ffffff20;
  int in_stack_ffffff24;
  int *in_stack_ffffff28;
  int **in_stack_ffffff2c;
  uint *in_stack_ffffff30;
  int in_stack_ffffff34;
  uint *in_stack_ffffff38;
  int **in_stack_ffffff3c;
  uint local_b8;
  uint local_b4;
  int local_b0 [2];
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  int local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint *local_5c;
  code *local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  undefined4 *local_40;
  code *local_3c;
  code *local_38;
  uint local_34;
  int local_30;
  
  local_a0 = *(int *)(param_7 + 0xc);
  local_68 = *param_6;
  local_a8 = *(int *)(param_7 + 4);
  uVar21 = *param_10;
  local_6c = param_8;
  local_94 = param_6[2];
  local_64 = *(int *)(param_11 + 0x20);
  local_9c = param_6[4];
  local_98 = param_6[5];
  local_74 = param_6[1];
  local_90 = param_6[3];
  uVar20 = *param_5;
  local_8c = *(uint *)(param_11 + 0x24);
  local_70 = param_5[1];
  uVar24 = 0x100 << (uVar21 & 0x1f);
  local_88 = param_4;
  local_80 = param_1;
  local_7c = param_2;
  local_78 = param_3;
  local_a4 = fix_point_mult2_32(uVar21,uVar24,*param_9);
  local_60 = fix_point_mult2_32(uVar21,uVar24,param_9[1]);
  iVar11 = local_a0;
  local_34 = local_a0 * local_a8;
  puVar25 = &zone_rgbg;
  iVar23 = local_a0 * 4;
  iVar26 = 0;
  iVar27 = 0x20000;
  puVar19 = &zone_pix_cnt;
  local_30 = local_34 * 4;
  puVar13 = puVar25;
  for (local_3c = (code *)0x0; local_3c != (code *)local_a8; local_3c = (code *)((int)local_3c + 1))
  {
    iVar17 = (int)puVar13 + local_30;
    iVar22 = 0;
    iVar18 = local_7c + iVar26;
    iVar6 = local_80 + iVar26;
    iVar16 = (int)puVar19 + iVar26;
    for (iVar14 = 0; iVar14 != local_a0; iVar14 = iVar14 + 1) {
      uVar24 = *(uint *)(iVar18 + iVar22);
      if (uVar24 == 0) {
        *(undefined4 *)((int)puVar13 + iVar22) = 0;
        *(undefined4 *)(iVar17 + iVar22) = 0;
        *(undefined4 *)(iVar16 + iVar22) = 0;
      }
      else {
        local_58 = (code *)(iVar27 + 0x92c);
        local_84 = (uint)(*(int *)(iVar6 + iVar22) << (uVar21 & 0x1f)) / uVar24;
        local_5c = (uint *)(iVar18 + iVar22);
        local_54 = iVar17;
        local_50 = iVar27;
        local_4c = iVar18;
        local_48 = iVar6;
        local_44 = iVar16;
        local_40 = puVar19;
        local_38 = (code *)iVar14;
        uVar5 = (*local_58)(uVar21,local_84,local_a4);
        *(undefined4 *)((int)puVar13 + iVar22) = uVar5;
        local_84 = (uint)(*(int *)(local_78 + iVar26 + iVar22) << (uVar21 & 0x1f)) / *local_5c;
        uVar5 = (*local_58)(uVar21,local_84,local_60);
        *(undefined4 *)(local_54 + iVar22) = uVar5;
        *(undefined4 *)(local_44 + iVar22) = *(undefined4 *)(local_88 + iVar26 + iVar22);
        iVar6 = local_48;
        iVar18 = local_4c;
        iVar14 = (int)local_38;
        iVar16 = local_44;
        iVar17 = local_54;
        puVar19 = local_40;
        iVar27 = local_50;
      }
      iVar22 = iVar22 + 4;
    }
    puVar13 = puVar13 + iVar11;
    iVar26 = iVar26 + iVar23;
  }
  awb_rg_global = 0;
  awb_bg_global = 0;
  uVar12 = 0;
  iVar27 = 0;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  bVar1 = false;
  DAT_000b699c = local_34;
  uVar24 = local_34;
  for (iVar26 = 0; iVar26 != local_a8; iVar26 = iVar26 + 1) {
    iVar6 = 0;
    while (iVar6 != iVar23) {
      iVar18 = *(int *)((int)puVar25 + iVar6 + local_30);
      uVar12 = uVar12 + *(int *)((int)puVar25 + iVar6);
      iVar27 = iVar27 + iVar18;
      if (*(int *)((int)puVar25 + iVar6) == 0) {
        uVar24 = uVar24 - 1;
        bVar3 = true;
      }
      iVar6 = iVar6 + 4;
      if (iVar18 == 0) {
        DAT_000b699c = DAT_000b699c - 1;
        bVar4 = true;
      }
      bVar1 = true;
      bVar2 = true;
    }
    puVar25 = puVar25 + iVar11;
  }
  if (bVar1) {
    awb_rg_global = uVar12;
  }
  if (bVar2) {
    awb_bg_global = iVar27;
  }
  awb_pix_cnt = local_34;
  if (bVar3) {
    awb_pix_cnt = uVar24;
  }
  if (bVar4) {
    uVar12 = *param_9;
  }
  else {
    uVar12 = *param_9;
    DAT_000b699c = local_34;
  }
  local_3c = fix_point_div;
  fix_point_div(uVar21,uVar24,awb_rg_global,0,uVar12,0);
  local_38 = __lshrdi3;
  awb_rg_global = __lshrdi3(extraout_v0,extraout_v1,uVar21);
  puVar7 = (uint *)param_9[1];
  piVar29 = (int *)0x0;
  uVar28 = (*local_3c)(uVar21);
  awb_bg_global = (*local_38)((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar21);
  if (awb_pix_cnt == 0) {
    DAT_000b69ac = 0x100;
  }
  else {
    DAT_000b69ac = awb_rg_global / awb_pix_cnt;
  }
  if (DAT_000b699c == 0) {
    DAT_000b69b0 = 0x100;
  }
  else {
    DAT_000b69b0 = awb_bg_global / DAT_000b699c;
  }
  iVar27 = 0;
  iVar11 = local_88;
  for (puVar10 = &tisp_wb_zone_attr; iVar26 = 0, puVar10 != &tisp_wb_zone_attr + local_a8 * 0xf;
      puVar10 = puVar10 + 0xf) {
    for (iVar6 = 0; puVar15 = (uint *)(iVar11 + iVar26), iVar6 != local_a0; iVar6 = iVar6 + 1) {
      puVar8 = puVar10 + iVar6;
      if (*puVar15 == 0) {
        *puVar8 = 0;
        puVar8[0xe1] = 0;
        puVar8[0x1c2] = 0;
      }
      else {
        *puVar8 = (char)(*(uint *)(local_80 + iVar27 + iVar26) / *puVar15);
        puVar8[0xe1] = (char)(*(uint *)(local_7c + iVar27 + iVar26) / *puVar15);
        puVar8[0x1c2] = (char)(*(uint *)(local_78 + iVar27 + iVar26) / *puVar15);
      }
      iVar26 = iVar26 + 4;
    }
    iVar27 = iVar27 + iVar23;
    iVar11 = iVar11 + iVar23;
  }
  for (iVar11 = 0; iVar11 != local_a8; iVar11 = iVar11 + 1) {
    iVar27 = 0;
    iVar6 = 0;
    while (iVar6 != local_a0) {
      iVar6 = iVar6 + 1;
      if (*(uint *)(local_88 + iVar26 + iVar27) <= local_6c) {
        *(undefined4 *)((int)&zone_rgbg + iVar27 + iVar26) = 0;
        *(undefined4 *)((int)&zone_rgbg + iVar27 + iVar26 + local_30) = 0;
        *(undefined4 *)((int)&zone_pix_cnt + iVar27 + iVar26) = 0;
      }
      iVar27 = iVar27 + 4;
    }
    iVar26 = iVar26 + iVar23;
  }
  if (first_frame == 0) {
    local_a0 = (int)&zone_rgbg + local_30;
    iVar11 = 0;
    iVar27 = 0;
    iVar26 = 0;
    for (iVar6 = 0; iVar6 != local_a8; iVar6 = iVar6 + 1) {
      iVar18 = 0;
      while (iVar18 != iVar23) {
        uVar24 = *(uint *)((int)&zone_rgbg + iVar18 + iVar11);
        uVar12 = *(uint *)((int)&zone_rgbg_last + iVar18 + iVar11);
        iVar14 = uVar24 - uVar12;
        if (uVar24 <= uVar12) {
          iVar14 = uVar12 - uVar24;
        }
        iVar26 = iVar26 + iVar14;
        uVar24 = *(uint *)(local_a0 + iVar11 + iVar18);
        uVar12 = *(uint *)((int)&zone_rgbg_last + iVar18 + iVar11 + local_30);
        iVar18 = iVar18 + 4;
        iVar14 = uVar24 - uVar12;
        if (uVar24 <= uVar12) {
          iVar14 = uVar12 - uVar24;
        }
        iVar27 = iVar27 + iVar14;
      }
      iVar11 = iVar11 + iVar23;
    }
    offet_thres = DAT_000ab100;
    if (((((uint)(iVar26 + iVar27) >> (uVar21 & 0x1f)) / local_34 < DAT_000ab100) &&
        (tisp_wb_attr == 0)) && (awb_moa == 0)) {
      offet_thres = DAT_000ab100;
      return;
    }
  }
  iVar11 = 0;
  for (iVar27 = 0; iVar27 != local_a8; iVar27 = iVar27 + 1) {
    for (iVar26 = 0; iVar26 != iVar23; iVar26 = iVar26 + 4) {
      *(undefined4 *)((int)&zone_rgbg_last + iVar26 + iVar11) =
           *(undefined4 *)((int)&zone_rgbg + iVar26 + iVar11);
      *(undefined4 *)((int)&zone_rgbg_last + iVar26 + iVar11 + local_30) =
           *(undefined4 *)((int)&zone_rgbg + iVar26 + iVar11 + local_30);
    }
    iVar11 = iVar11 + iVar23;
  }
  puVar15 = &local_b8;
  for (uVar24 = 0; uVar24 < 0x38; uVar24 = uVar24 + 1) {
    (&stack0xffffff08)[uVar24] = (&stack0x00000034)[uVar24];
  }
  Tiziano_Awb_Ct_Detect
            (&zone_rgbg,(int **)&zone_pix_cnt,param_12,param_13,puVar7,piVar29,in_stack_ffffff10,
             in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,
             in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30,
             in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,puVar15,local_b0);
  uVar24 = _awb_ct;
  if (first_frame == 0) {
    iVar11 = 0;
    do {
      *(undefined4 *)((int)&AWBRgI + iVar11) = *(undefined4 *)((int)&DAT_000ab1d0 + iVar11);
      *(undefined4 *)((int)&AWBBgI + iVar11) = *(undefined4 *)((int)&DAT_000ab20c + iVar11);
      puVar13 = (undefined4 *)((int)&AWBCTI + iVar11);
      puVar19 = (undefined4 *)((int)&DAT_000ab248 + iVar11);
      iVar11 = iVar11 + 4;
      *puVar13 = *puVar19;
      DAT_000ab27c = _awb_ct;
    } while (iVar11 != 0x38);
    DAT_000ab204 = local_b8;
    DAT_000ab240 = local_b4;
    if (uVar20 < 0x10) {
      if (uVar20 == 0) {
        uVar20 = 1;
      }
    }
    else {
      uVar20 = 0xf;
    }
    iVar11 = 0xf - uVar20;
    iVar27 = iVar11 * 4;
    iVar23 = 0;
    uVar9 = 0;
    iVar26 = 0;
    uVar12 = 0;
    iVar6 = 0;
    uVar24 = 0;
    iVar18 = 0;
    do {
      iVar11 = iVar11 + 1;
      uVar24 = uVar24 + iVar11;
      iVar14 = iVar23 + iVar27;
      uVar12 = uVar12 + iVar11;
      uVar9 = uVar9 + iVar11;
      iVar18 = iVar11 * *(int *)((int)&AWBRgI + iVar23 + iVar27) + iVar18;
      iVar16 = iVar23 + iVar27;
      iVar23 = iVar23 + 4;
      iVar6 = iVar11 * *(int *)((int)&AWBBgI + iVar14) + iVar6;
      iVar26 = iVar11 * *(int *)((int)&AWBCTI + iVar16) + iVar26;
    } while (iVar11 != 0xf);
    uVar24 = ((uVar24 >> 1) + iVar18) / uVar24;
    uVar12 = ((uVar12 >> 1) + iVar6) / uVar12;
    _awb_ct = ((uVar9 >> 1) + iVar26) / uVar9;
    if ((((uVar24 == awb_gain_original) && (uVar12 == DAT_000b6c64)) &&
        ((tisp_wb_attr == 0 && ((awb_moa == 0 && (param_6[2] == param_6[4])))))) &&
       (param_6[3] == param_6[5])) {
      return;
    }
  }
  else {
    iVar11 = 0;
    do {
      *(uint *)((int)&AWBRgI + iVar11) = local_b8;
      *(uint *)((int)&AWBBgI + iVar11) = local_b4;
      puVar7 = (uint *)((int)&AWBCTI + iVar11);
      iVar11 = iVar11 + 4;
      *puVar7 = uVar24;
    } while (iVar11 != 0x3c);
    first_frame = 0;
    uVar20 = 1;
    uVar24 = local_b8;
    uVar12 = local_b4;
  }
  local_b4 = uVar12;
  local_b8 = uVar24;
  uVar12 = 1 << (uVar21 + 0x10 & 0x1f);
  DAT_000b6c64 = local_b4;
  iVar11 = 1 << (uVar21 - 1 & 0x1f);
  uVar24 = local_70;
  if (local_64 != 0) {
    uVar24 = local_8c;
  }
  uVar9 = uVar12 / local_b8 + iVar11 >> (uVar21 & 0x1f);
  uVar12 = uVar12 / local_b4 + iVar11 >> (uVar21 & 0x1f);
  iVar11 = uVar9 - local_94;
  if (uVar9 <= local_94) {
    iVar11 = local_94 - uVar9;
  }
  iVar27 = uVar12 - local_90;
  if (uVar12 <= local_90) {
    iVar27 = local_90 - uVar12;
  }
  awb_gain_original = local_b8;
  if (local_b0[0] == 1) {
    param_6[2] = 0x100;
    param_6[3] = 0x100;
    param_6[4] = 0x100;
    param_6[5] = 0x100;
  }
  if (local_68 == 0) {
    if (uVar24 < (uint)(iVar27 + iVar11)) {
      if (local_b0[0] != 1) {
        param_6[2] = uVar9;
        param_6[3] = uVar12;
        *param_6 = 1;
        param_6[1] = 1;
        param_6[4] = local_9c + (int)(uVar9 - local_94) / (int)uVar20;
        uVar9 = local_90;
        goto LAB_00027a70;
      }
      *param_6 = 0;
    }
    else {
      *param_6 = 0;
    }
    param_6[1] = 0;
  }
  else {
    if (((uint)(iVar27 + iVar11) <= local_70) || (local_b0[0] == 1)) {
      if ((local_74 + 1U == uVar20) || (uVar20 == 1)) {
        *param_6 = 0;
        param_6[4] = param_6[2];
        iVar11 = param_6[3];
      }
      else {
        *param_6 = 1;
        param_6[4] = local_9c + (int)(uVar9 - local_9c) / (int)(uVar20 - local_74);
        iVar11 = local_98 + (int)(uVar12 - local_98) / (int)(uVar20 - local_74);
      }
      param_6[5] = iVar11;
      param_6[1] = param_6[1] + 1;
      goto LAB_00027a78;
    }
    param_6[2] = uVar9;
    *param_6 = 1;
    param_6[1] = 1;
    param_6[3] = uVar12;
    param_6[4] = local_9c + (int)(uVar9 - local_9c) / (int)uVar20;
    uVar9 = local_98;
LAB_00027a70:
    param_6[5] = local_98 + (int)(uVar12 - uVar9) / (int)uVar20;
  }
LAB_00027a78:
  local_8c = uVar24;
  Tiziano_awb_set_gain((int)param_6,uVar21,param_9);
  return;
}



undefined4 JZ_Isp_Awb(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *in_stack_ffffff58;
  int *in_stack_ffffff5c;
  int in_stack_ffffff60;
  uint in_stack_ffffff64;
  uint *in_stack_ffffff68;
  uint *in_stack_ffffff6c;
  int in_stack_ffffff70;
  int in_stack_ffffff74;
  uint in_stack_ffffff78;
  undefined auStack_48 [8];
  undefined4 local_40;
  int local_38;
  undefined4 local_34;
  
  uVar1 = _ev;
  _awb_ct_last = _awb_ct;
  if (_ev < (uint)(_awb_mode << 10)) {
    DAT_000b6924 = _awb_ct_th_ot_luxhigh;
  }
  else {
    if ((uint)(DAT_000ab0d4 << 10) <= _ev) {
      DAT_000b692c = _rgbg_weight;
      DAT_000b6920 = _light_src_num;
      DAT_000b6924 = _awb_ct_th_in;
      DAT_000b6928 = &_awb_ct_para_in;
      goto LAB_00027bb4;
    }
    DAT_000b6924 = _awb_ct_th_ot_luxlow;
  }
  DAT_000b692c = _rgbg_weight_ot;
  DAT_000b6920 = 0;
  DAT_000b6928 = &_awb_ct_para_ot;
LAB_00027bb4:
  IspAwbCtDetectParam = _light_src;
  if (_light_src._76_4_ == 1) {
    DAT_000b692c = _rgbg_weight_global;
  }
  DAT_000b6930 = DAT_000ab11c;
  DAT_000b6934 = DAT_000ab114;
  DAT_000b6938 = _rg_pos;
  DAT_000b693c = _bg_pos;
  DAT_000b6940 = _color_temp_mesh;
  DAT_000b6944 = _awb_wght;
  DAT_000b6948 = _awb_dis_tw;
  DAT_000b694c = &_awb_ct;
  DAT_000b6950 = _ls_w_lut;
  IspAwbFpgaParam = &awb_array_r;
  DAT_000b6960 = &awb_array_g;
  DAT_000b6964 = &awb_array_b;
  DAT_000b6974 = &_awb_parameter;
  DAT_000b6968 = &awb_array_p;
  DAT_000b696c = &_awb_cof;
  DAT_000b6978 = _pixel_cnt_th;
  DAT_000b6984 = &_awb_cluster;
  DAT_000b6958 = &_awb_cluster;
  DAT_000b6970 = _awb_mf_para;
  DAT_000b697c = &_wb_static;
  DAT_000b6980 = &_AwbPointPos;
  DAT_000b6954 = &_AwbPointPos;
  for (uVar3 = 0; uVar3 < 0x40; uVar3 = uVar3 + 1) {
    (&stack0xffffff74)[uVar3] = *(undefined *)((int)&IspAwbCtDetectParam + uVar3);
  }
  for (uVar3 = 0; uVar3 < 0x1c; uVar3 = uVar3 + 1) {
    (&stack0xffffff58)[uVar3] = *(undefined *)((int)&DAT_000b696c + uVar3);
  }
  Tiziano_awb_fpga(0xb6598,0xb6214,0xb5e90,0xb5b0c,in_stack_ffffff58,in_stack_ffffff5c,
                   in_stack_ffffff60,in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,
                   in_stack_ffffff70,in_stack_ffffff74,in_stack_ffffff78);
  if (tawb_custom_en == 1) {
    private_complete();
  }
  iVar2 = _awb_ct;
  if (tisp_wb_attr == 1) {
    iVar2 = awb_ct_manual;
    if (awb_ct_manual == 0) {
      iVar2 = _awb_ct;
    }
  }
  else if (tisp_wb_attr == 0) {
    awb_ct_manual = _awb_ct;
  }
  _awb_ct = iVar2;
  if (_light_src._76_4_ == 0) {
    if ((uint)(DAT_000ab0d8 << 10) < uVar1) {
      if ((ModeFlag == 0) && (ModeFlag = 1, awb_frz == 0)) {
        system_reg_write(0xb028,DAT_000ab108 << 0x10 | _awb_lowlight_rg_th);
        system_reg_write(0xb02c,0x3ff0001);
      }
    }
    else if ((ModeFlag == 1) && (ModeFlag = 0, awb_frz == 0)) {
      system_reg_write(0xb028,DAT_000ab19c << 0x10 | DAT_000ab198);
      system_reg_write(0xb02c,DAT_000ab1a4 << 0x10 | DAT_000ab1a0);
    }
    system_reg_write_awb_trig_part_0();
  }
  local_40 = 9;
  local_34 = 0;
  local_38 = _awb_ct;
  tisp_event_push((int)auStack_48);
  return 0;
}



undefined4 tisp_awb_ev_update(undefined4 param_1)

{
  _ev = param_1;
  return 0;
}



undefined4 tiziano_awb_params_refresh(void)

{
  memcpy(&_awb_parameter,&DAT_00096d40,0xb4);
  memcpy(&_pixel_cnt_th,&DAT_00096df4,4);
  memcpy(&_awb_lowlight_rg_th,&DAT_00096df8,8);
  memcpy(&_AwbPointPos,&DAT_00096e00,8);
  memcpy(&_awb_cof,&DAT_00096e08,8);
  memcpy(&_awb_mode,&DAT_00096e28,0xc);
  memcpy(&_wb_static,&DAT_00096e3c,8);
  memcpy(_light_src,&DAT_00096e44,0x50);
  memcpy(&_light_src_num,&DAT_00096e94,4);
  memcpy(_rg_pos,&DAT_00096e98,0x3c);
  memcpy(_bg_pos,&DAT_00096ed4,0x3c);
  memcpy(_awb_ct_th_ot_luxhigh,&DAT_00096f10,0x10);
  memcpy(_awb_ct_th_ot_luxlow,&DAT_00096f20,0x10);
  memcpy(_awb_ct_th_in,&DAT_00096f30,0x10);
  memcpy(&_awb_ct_para_ot,&DAT_00096f40,8);
  memcpy(&_awb_ct_para_in,&DAT_00096f48,8);
  memcpy(_awb_dis_tw,&DAT_00096f50,0xc);
  memcpy(_rgbg_weight,&DAT_00096f5c,900);
  memcpy(_color_temp_mesh,&DAT_000972e0,900);
  memcpy(_awb_wght,&DAT_00097664,900);
  memcpy(_rgbg_weight_ot,&DAT_000979e8,900);
  memcpy(_ls_w_lut,&DAT_00097d6c,0x808);
  if (awb_dn_refresh_flag == 0) {
    memcpy(_awb_mf_para,&DAT_00096e10,0x18);
    memcpy(&_awb_ct,&DAT_00096e34,4);
    memcpy(&_awb_ct_last,&DAT_00096e38,4);
  }
  awb_dn_refresh_flag = 0;
  return 0;
}



undefined4 tiziano_awb_set_lum_th_freq(void)

{
  uint uVar1;
  uint local_10;
  uint local_c [2];
  
  local_10 = 0x400;
  local_c[0] = 0;
  tisp_ae_mean_update(local_c,&local_10);
  uVar1 = DAT_000ab1b8;
  if (local_c[0] < DAT_000ab1b8) {
    uVar1 = local_c[0];
  }
  uVar1 = uVar1 * local_10 >> 10;
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  system_reg_write(0xb038,DAT_000ab1bc << 8 | DAT_000ab1c0 << 0x10 | uVar1);
  system_reg_write_awb_trig_part_0();
  return 0;
}



undefined4 awb_interrupt_static(void)

{
  int iVar1;
  undefined auStack_40 [8];
  undefined4 local_38;
  
  iVar1 = system_reg_read(0xb050);
  private_dma_cache_sync();
  JZ_Isp_Get_Awb_Statistics((uint *)(iVar1 * 0x1000 + DAT_000b419c),0xf001f001);
  tiziano_awb_set_lum_th_freq();
  local_38 = 10;
  tisp_event_push((int)auStack_40);
  return 1;
}



undefined * tiziano_awb_dump(void)

{
  undefined *puVar1;
  
  if (DumpNum_37584 == 0) {
    DumpNum_37584 = 1;
    isp_printf();
    system_reg_read(0xb000);
    isp_printf();
    system_reg_read(0xb004);
    isp_printf();
    system_reg_read(0xb008);
    isp_printf();
    system_reg_read(0xb00c);
    isp_printf();
    system_reg_read(0xb010);
    isp_printf();
    system_reg_read(0xb014);
    isp_printf();
    system_reg_read(0xb018);
    isp_printf();
    system_reg_read(0xb01c);
    isp_printf();
    system_reg_read(0xb020);
    isp_printf();
    system_reg_read(0xb024);
    isp_printf();
    system_reg_read(0xb028);
    isp_printf();
    system_reg_read(0xb02c);
    isp_printf();
    system_reg_read(0xb030);
    isp_printf();
    system_reg_read(0xb034);
    isp_printf();
    system_reg_read(0xb038);
    isp_printf();
    system_reg_read(0xb03c);
    isp_printf();
    system_reg_read(0xb040);
    isp_printf();
    system_reg_read(0xb044);
    isp_printf();
    system_reg_read(0xb048);
    isp_printf();
    system_reg_read(0xb04c);
    isp_printf();
    system_reg_read(0xb050);
    isp_printf();
    system_reg_read(0xb054);
    isp_printf();
    system_reg_read(0xb058);
    puVar1 = (undefined *)isp_printf();
    return puVar1;
  }
  return &DAT_000b0000;
}



undefined4 tiziano_awb_set_hardware_param(void)

{
  if (awb_first == 0) {
    awb_first = 1;
    system_reg_write(0xb004,DAT_000ab11c << 0x1c | DAT_000ab118 << 0x10 | _awb_parameter |
                            DAT_000ab114 << 0xc);
    system_reg_write(0xb008,DAT_000ab12c << 0x18 | DAT_000ab128 << 0x10 | DAT_000ab120 |
                            DAT_000ab124 << 8);
    system_reg_write(0xb00c,DAT_000ab13c << 0x18 | DAT_000ab138 << 0x10 | DAT_000ab130 |
                            DAT_000ab134 << 8);
    system_reg_write(0xb010,DAT_000ab14c << 0x18 | DAT_000ab148 << 0x10 | DAT_000ab140 |
                            DAT_000ab144 << 8);
    system_reg_write(0xb014,DAT_000ab158 << 0x10 | DAT_000ab154 << 8 | DAT_000ab150);
    system_reg_write(0xb018,DAT_000ab168 << 0x18 | DAT_000ab164 << 0x10 | DAT_000ab15c |
                            DAT_000ab160 << 8);
    system_reg_write(0xb01c,DAT_000ab178 << 0x18 | DAT_000ab174 << 0x10 | DAT_000ab16c |
                            DAT_000ab170 << 8);
    system_reg_write(0xb020,DAT_000ab188 << 0x18 | DAT_000ab184 << 0x10 | DAT_000ab17c |
                            DAT_000ab180 << 8);
    system_reg_write(0xb024,DAT_000ab194 << 0x10 | DAT_000ab190 << 8 | DAT_000ab18c);
  }
  if (_light_src._76_4_ == 0) {
    if (ModeFlag == 1) {
      system_reg_write(0xb028,DAT_000ab108 << 0x10 | _awb_lowlight_rg_th);
      system_reg_write(0xb02c,0x3ff0001);
    }
    else if (ModeFlag == 0) {
      system_reg_write(0xb028,DAT_000ab19c << 0x10 | DAT_000ab198);
      system_reg_write(0xb02c,DAT_000ab1a4 << 0x10 | DAT_000ab1a0);
    }
    system_reg_write(0xb030,DAT_000ab1ac << 0x10 | DAT_000ab1a8);
    system_reg_write(0xb034,DAT_000ab1b4 << 0x10 | DAT_000ab1b0);
    tiziano_awb_set_lum_th_freq();
  }
  else {
    system_reg_write(0xb028,0xfff0001);
    system_reg_write(0xb02c,0xfff0001);
    system_reg_write(0xb030,0x100);
    system_reg_write(0xb034,0xffff0100);
  }
  system_reg_write_awb_trig_part_0();
  return 0;
}



undefined4 tiziano_awb_dn_params_refresh(void)

{
  first_frame = 1;
  awb_dn_refresh_flag = 1;
  tiziano_awb_params_refresh();
  tiziano_awb_set_hardware_param();
  return 0;
}



undefined4 tiziano_awb_init(uint param_1,uint param_2)

{
  uint uVar1;
  
  awb_first = 0;
  memset(&tisp_wb_attr,0,0x1c);
  tiziano_awb_params_refresh();
  for (uVar1 = 0; uVar1 < DAT_000ab11c; uVar1 = uVar1 + 1) {
    (&DAT_000ab120)[uVar1] = (param_2 >> 1) / DAT_000ab11c;
  }
  for (uVar1 = 0; uVar1 < DAT_000ab114; uVar1 = uVar1 + 1) {
    (&DAT_000ab15c)[uVar1] = (param_1 >> 1) / DAT_000ab114;
  }
  if (awb_frz == 0) {
    tiziano_awb_set_hardware_param();
    Tiziano_awb_set_gain(0xab0dc,_AwbPointPos,(uint *)&_wb_static);
  }
  tisp_event_set_cb(10,JZ_Isp_Awb);
  system_irq_func_set(0x1e,awb_interrupt_static);
  return 0;
}



undefined4 tisp_g_wb_mode(void *param_1)

{
  memcpy(param_1,&tisp_wb_attr,0x1c);
  if (tisp_wb_attr == 0) {
    *(uint *)((int)param_1 + 4) = 0x10000 / DAT_000b69b4;
    *(uint *)((int)param_1 + 8) = 0x10000 / DAT_000b69b8;
  }
  return 0;
}



void tisp_awb_set_frz(uint param_1)

{
  awb_frz = param_1 & 0xff;
  return;
}



void tisp_awb_get_frz(undefined *param_1)

{
  *param_1 = (char)awb_frz;
  return;
}



undefined4 tisp_s_wb_mode(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_1) {
  case 0:
    tisp_wb_attr = 0;
    break;
  case 1:
    tisp_wb_attr = 1;
    DAT_000b69a4 = param_2;
    DAT_000b69a8 = param_3;
    break;
  case 2:
    tisp_wb_attr = 2;
    DAT_000b69a8 = 0x180;
    DAT_000b69a4 = 0x180;
    break;
  case 3:
    tisp_wb_attr = 3;
    DAT_000b69a4 = 0x1b6;
    DAT_000b69a8 = 0x12f;
    break;
  case 4:
    tisp_wb_attr = 4;
    DAT_000b69a4 = 0xdb;
    DAT_000b69a8 = 0x2b2;
    break;
  case 5:
    tisp_wb_attr = 5;
    DAT_000b69a4 = 0xf0;
    DAT_000b69a8 = 0x234;
    break;
  case 6:
    tisp_wb_attr = 6;
    DAT_000b69a4 = 0x13b;
    DAT_000b69a8 = 0x1cb;
    break;
  case 7:
    tisp_wb_attr = 7;
    DAT_000b69a4 = 0x1d4;
    DAT_000b69a8 = 0x117;
    break;
  case 8:
    tisp_wb_attr = 8;
    DAT_000b69a4 = 0xf0;
    DAT_000b69a8 = 0x178;
    break;
  case 9:
    tisp_wb_attr = 9;
    DAT_000b69a4 = param_2;
    DAT_000b69a8 = param_3;
    break;
  default:
    isp_printf();
  }
  awb_moa = 1;
  return 0;
}



void tisp_awb_get_ct(undefined4 *param_1)

{
  *param_1 = _awb_ct;
  return;
}



void tisp_awb_set_ct(undefined4 *param_1)

{
  awb_ct_manual = *param_1;
  return;
}



void tiziano_s_awb_start(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = tparams_day;
  _awb_mf_para._8_4_ = param_1;
  _awb_mf_para._16_4_ = param_1;
  *(undefined4 *)(tparams_day + 0x10e8) = param_1;
  *(undefined4 *)(iVar1 + 0x10f0) = param_1;
  _awb_mf_para._12_4_ = param_2;
  _awb_mf_para._20_4_ = param_2;
  *(undefined4 *)(iVar1 + 0x10ec) = param_2;
  *(undefined4 *)(iVar1 + 0x10f4) = param_2;
  Tiziano_awb_set_gain(0xab0dc,_AwbPointPos,(uint *)&_wb_static);
  return;
}



void tiziano_g_awb_start(undefined4 *param_1)

{
  *param_1 = _awb_mf_para._8_4_;
  param_1[1] = _awb_mf_para._12_4_;
  return;
}



undefined4 tiziano_s_wb_algo(int param_1)

{
  if (param_1 == 1) {
    _light_src._76_4_ = 1;
  }
  else {
    if ((param_1 != 0) && (param_1 != 2)) {
      isp_printf();
      return 0xffffffff;
    }
    _light_src._76_4_ = 0;
  }
  tiziano_awb_set_hardware_param();
  return 0;
}



undefined4 tisp_awb_get_zone(void *param_1)

{
  memcpy(param_1,&tisp_wb_zone_attr,0x2a3);
  return 0;
}



undefined4
tisp_awb_set_cluster_awb_params
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_resc;
  
  local_resc = param_4;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)&DAT_000aaf84 + iVar1) = *(undefined4 *)((int)&local_resc + iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0x1c);
  _awb_cluster = param_1;
  DAT_000aafa0 = param_2;
  DAT_000aafa4 = param_3;
  return 0;
}



undefined4 tisp_awb_get_cluster_awb_params(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)param_1 + iVar1 + 0xc) = *(undefined4 *)((int)&DAT_000aaf84 + iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0x1c);
  *param_1 = _awb_cluster;
  param_1[1] = DAT_000aafa0;
  param_1[2] = DAT_000aafa4;
  return 0;
}



undefined4
tisp_awb_set_ct_trend(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_res0 [4];
  
  local_res0[2] = param_3;
  local_res0[0] = param_1;
  local_res0[1] = param_2;
  local_res0[3] = param_4;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)&DAT_000aaf68 + iVar1) = *(undefined4 *)((int)local_res0 + iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0x18);
  awb_moa = 1;
  return 0;
}



undefined4 tisp_awb_get_ct_trend(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined4 *)((int)&DAT_000aaf68 + iVar2);
    puVar3 = (undefined4 *)(param_1 + iVar2);
    iVar2 = iVar2 + 4;
    *puVar3 = *puVar1;
  } while (iVar2 != 0x18);
  return 0;
}



undefined4 tisp_awb_param_array_get(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__src;
  size_t __n;
  
  switch(param_1) {
  case 0x23:
    __src = (undefined1 *)&_awb_parameter;
    __n = 0xb4;
    break;
  case 0x24:
    __src = (undefined1 *)&_pixel_cnt_th;
    goto LAB_000290c4;
  case 0x25:
    __src = (undefined1 *)&_awb_lowlight_rg_th;
    goto LAB_00028f5c;
  case 0x26:
    __src = (undefined1 *)&_AwbPointPos;
    goto LAB_00028f5c;
  case 0x27:
    __src = (undefined1 *)&_awb_cof;
    goto LAB_00028f5c;
  case 0x28:
    __src = _awb_mf_para;
    __n = 0x18;
    break;
  case 0x29:
    __src = (undefined1 *)&_awb_mode;
    goto LAB_00029030;
  case 0x2a:
    __src = (undefined1 *)&_awb_ct;
    goto LAB_000290c4;
  case 0x2b:
    __src = (undefined1 *)&_awb_ct_last;
    goto LAB_000290c4;
  case 0x2c:
    __src = (undefined1 *)&_wb_static;
    goto LAB_00028f5c;
  case 0x2d:
    __src = _light_src;
    __n = 0x50;
    break;
  case 0x2e:
    __src = (undefined1 *)&_light_src_num;
LAB_000290c4:
    __n = 4;
    break;
  case 0x2f:
    __src = _rg_pos;
    goto LAB_00028fe0;
  case 0x30:
    __src = _bg_pos;
LAB_00028fe0:
    __n = 0x3c;
    break;
  case 0x31:
    __src = _awb_ct_th_ot_luxhigh;
    goto LAB_00029008;
  case 0x32:
    __src = _awb_ct_th_ot_luxlow;
    goto LAB_00029008;
  case 0x33:
    __src = _awb_ct_th_in;
LAB_00029008:
    __n = 0x10;
    break;
  case 0x34:
    __src = (undefined1 *)&_awb_ct_para_ot;
    goto LAB_00028f5c;
  case 0x35:
    __src = (undefined1 *)&_awb_ct_para_in;
LAB_00028f5c:
    __n = 8;
    break;
  case 0x36:
    __src = _awb_dis_tw;
LAB_00029030:
    __n = 0xc;
    break;
  case 0x37:
    __src = _rgbg_weight;
    goto LAB_00029064;
  case 0x38:
    __src = _color_temp_mesh;
    goto LAB_00029064;
  case 0x39:
    __src = _awb_wght;
    goto LAB_00029064;
  case 0x3a:
    __src = _rgbg_weight_ot;
LAB_00029064:
    __n = 900;
    break;
  case 0x3b:
    __src = _ls_w_lut;
    __n = 0x808;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  memcpy(param_2,__src,__n);
  *param_3 = __n;
  return 0;
}



undefined4 tisp_awb_param_array_set(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *__dest;
  undefined8 *__dest_00;
  undefined1 *puVar2;
  
  switch(param_1) {
  case 0x23:
    memcpy(&_awb_parameter,param_2,0xb4);
    uVar1 = 0xb4;
    break;
  case 0x24:
    __dest = &_pixel_cnt_th;
    goto LAB_000291cc;
  case 0x25:
    __dest_00 = (undefined8 *)&_awb_lowlight_rg_th;
    goto LAB_00029168;
  case 0x26:
    __dest_00 = (undefined8 *)&_AwbPointPos;
    goto LAB_00029168;
  case 0x27:
    __dest_00 = &_awb_cof;
    goto LAB_00029168;
  case 0x28:
    uVar1 = 0x18;
    break;
  case 0x29:
    puVar2 = (undefined1 *)&_awb_mode;
    goto LAB_00029268;
  case 0x2a:
  case 0x2b:
    uVar1 = 4;
    break;
  case 0x2c:
    __dest_00 = &_wb_static;
    goto LAB_00029168;
  case 0x2d:
    memcpy(_light_src,param_2,0x50);
    uVar1 = 0x50;
    break;
  case 0x2e:
    __dest = &_light_src_num;
LAB_000291cc:
    memcpy(__dest,param_2,4);
    uVar1 = 4;
    break;
  case 0x2f:
    puVar2 = _rg_pos;
    goto LAB_000291f8;
  case 0x30:
    puVar2 = _bg_pos;
LAB_000291f8:
    memcpy(puVar2,param_2,0x3c);
    uVar1 = 0x3c;
    break;
  case 0x31:
    puVar2 = _awb_ct_th_ot_luxhigh;
    goto LAB_00029230;
  case 0x32:
    puVar2 = _awb_ct_th_ot_luxlow;
    goto LAB_00029230;
  case 0x33:
    puVar2 = _awb_ct_th_in;
LAB_00029230:
    memcpy(puVar2,param_2,0x10);
    uVar1 = 0x10;
    break;
  case 0x34:
    __dest_00 = &_awb_ct_para_ot;
    goto LAB_00029168;
  case 0x35:
    __dest_00 = &_awb_ct_para_in;
LAB_00029168:
    memcpy(__dest_00,param_2,8);
    uVar1 = 8;
    break;
  case 0x36:
    puVar2 = _awb_dis_tw;
LAB_00029268:
    memcpy(puVar2,param_2,0xc);
    uVar1 = 0xc;
    break;
  case 0x37:
    puVar2 = _rgbg_weight;
    goto LAB_000292a0;
  case 0x38:
    puVar2 = _color_temp_mesh;
    goto LAB_000292a0;
  case 0x39:
    puVar2 = _awb_wght;
    goto LAB_000292a0;
  case 0x3a:
    puVar2 = _rgbg_weight_ot;
LAB_000292a0:
    memcpy(puVar2,param_2,900);
    uVar1 = 900;
    break;
  case 0x3b:
    memcpy(_ls_w_lut,param_2,0x808);
    uVar1 = 0x808;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  *param_3 = uVar1;
  tiziano_awb_set_hardware_param();
  return 0;
}



void tisp_awb_algo_init(undefined4 param_1)

{
  tawb_custom_en = param_1;
  return;
}



void tisp_awb_algo_handle(int param_1)

{
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 8) == 1) {
    tisp_s_wb_mode(1,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    awb_ct_manual = *(undefined4 *)(param_1 + 0x14);
    local_14 = *(int *)(param_1 + 0xc);
    local_10 = *(undefined4 *)(param_1 + 0x10);
    JZ_Isp_Awb_Awbg2reg(&local_14,&local_1c);
    system_reg_write(0x1804,local_1c);
    system_reg_write(0x1808,local_18);
    system_reg_write(0x180c,local_1c);
    system_reg_write(0x1810,local_18);
    system_reg_write_awb_trig(2);
    tisp_rdns_awb_gain_updata((uint)local_1c._2_2_,(uint)local_18._2_2_);
  }
  return;
}



undefined4 tisp_awb_deinit(void)

{
  if (tawb_custom_en == 1) {
    tawb_custom_en = 0;
  }
  return 0;
}



int ISPAWBInterpolation1(uint param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  uint uVar1;
  
  if (param_6 < param_5) {
    uVar1 = fix_point_mult2_32(param_1,param_5 - param_6 << (param_1 & 0x1f),
                               param_2 - (param_3 << (param_1 & 0x1f)));
    uVar1 = fix_point_div_32(param_1,uVar1,param_4 - param_3 << (param_1 & 0x1f));
    return (param_5 << (param_1 & 0x1f)) - uVar1;
  }
  uVar1 = fix_point_mult2_32(param_1,param_6 - param_5 << (param_1 & 0x1f),
                             param_2 - (param_3 << (param_1 & 0x1f)));
  uVar1 = fix_point_div_32(param_1,uVar1,param_4 - param_3 << (param_1 & 0x1f));
  return uVar1 + (param_5 << (param_1 & 0x1f));
}



int ISPAWBInterpolation2(uint param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_3 << (param_1 & 0x1f);
  if (param_6 < param_5) {
    uVar1 = fix_point_mult2_32(param_1,param_5 - param_6,param_2 - iVar2);
    uVar1 = fix_point_div_32(param_1,uVar1,param_4 - param_3 << (param_1 & 0x1f));
    return param_5 - uVar1;
  }
  uVar1 = fix_point_mult2_32(param_1,param_6 - param_5,param_2 - iVar2);
  uVar1 = fix_point_div_32(param_1,uVar1,param_4 - param_3 << (param_1 & 0x1f));
  return uVar1 + param_5;
}



uint func_zone_ct_weight(uint param_1,uint *param_2,int param_3,uint param_4,uint param_5,
                        uint param_6,uint param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 < param_2[3]) && (param_2[1] < param_1)) {
    if (param_2[2] < param_1) {
      uVar2 = param_2[3] - param_1 << (param_4 & 0x1f);
      param_7 = param_6;
    }
    else {
      if (*param_2 <= param_1) {
        uVar3 = 0x100 << (param_4 & 0x1f);
        uVar2 = uVar3;
        goto LAB_000296dc;
      }
      uVar2 = param_1 - param_2[1] << (param_4 & 0x1f);
    }
    iVar1 = fix_point_mult2_32(param_4,uVar2,param_7);
    uVar3 = iVar1 + (param_3 << (param_4 & 0x1f));
    uVar2 = 0x100 << (param_4 & 0x1f);
  }
  else {
    uVar3 = param_3 << (param_4 & 0x1f);
    uVar2 = 0x100 << (param_4 & 0x1f);
  }
LAB_000296dc:
  uVar3 = fix_point_mult2_32(param_4,param_5,uVar3);
  uVar2 = fix_point_div_32(param_4,uVar3,uVar2);
  return uVar2;
}



void Tiziano_Awb_Ct_Detect
               (uint *param_1,int **param_2,int param_3,uint param_4,uint *param_5,int *param_6,
               int *param_7,int *param_8,int *param_9,int *param_10,int *param_11,int param_12,
               int *param_13,int **param_14,uint *param_15,int param_16,uint *param_17,
               int **param_18,uint *param_19,undefined4 *param_20)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  uint *puVar7;
  int *piVar8;
  int **ppiVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  code *pcVar13;
  int iVar14;
  int **ppiVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  uint *puVar22;
  int *piVar23;
  undefined4 *puVar24;
  int *piVar25;
  undefined4 *puVar26;
  uint uVar27;
  uint *puVar28;
  int iVar29;
  undefined4 *puVar30;
  uint uVar31;
  uint *puVar32;
  uint uVar33;
  undefined4 *puVar34;
  uint uVar35;
  int *piVar36;
  ulonglong uVar37;
  uint local_118 [20];
  code *local_c8;
  int *local_c4;
  int *local_c0;
  int local_bc;
  int *local_b8;
  uint local_b4;
  code *local_b0;
  code *local_ac;
  int *local_a8;
  undefined4 *local_a4;
  int local_a0;
  uint *local_9c;
  int *local_98;
  uint local_94;
  int *local_90;
  int *local_8c;
  int *local_88;
  uint *local_84;
  int local_80;
  int *local_7c;
  uint *local_78;
  code *local_74;
  int *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  
  local_a8 = param_9;
  local_c8 = (code *)param_7;
  local_a0 = param_12;
  local_74 = (code *)param_13;
  local_68 = *param_14;
  local_58 = param_14[1];
  local_9c = param_5;
  local_6c = param_14[2];
  uVar35 = *param_17;
  local_30 = param_10;
  local_3c = param_8;
  local_38 = param_11;
  local_78 = param_15;
  local_80 = param_16;
  local_8c = (int *)param_4;
  memset(local_118,0,0x50);
  local_a4 = (undefined4 *)*param_6;
  uVar31 = *local_9c;
  uVar27 = local_9c[1];
  local_60 = param_18[2];
  local_64 = *param_18;
  local_5c = param_18[4];
  local_90 = (int *)param_6[1];
  local_54 = param_18[5];
  if (local_a4 == (undefined4 *)0x1) {
    uVar19 = 0x100 - param_6[1] << (uVar35 & 0x1f);
    local_48 = param_18[3];
    local_44 = param_18[1];
    local_88 = (int *)fix_point_div_32(uVar35,uVar19,local_9c[3] - local_9c[2] << (uVar35 & 0x1f));
    local_84 = (uint *)fix_point_div_32(uVar35,uVar19,uVar31 - uVar27 << (uVar35 & 0x1f));
    local_ac = (code *)local_44;
    local_7c = local_48;
  }
  else {
    local_84 = (uint *)0x0;
    local_88 = (int *)0x0;
    local_ac = (code *)param_18[1];
    local_7c = param_18[3];
  }
  piVar23 = local_30;
  piVar36 = local_38;
  piVar5 = local_3c;
  if (((uint)local_8c & 0x7fffffff) != 0) {
    iVar14 = (int)local_8c << 3;
    iVar2 = 0;
    do {
      piVar8 = (int *)(param_3 + iVar2);
      piVar3 = (int *)((int)local_118 + iVar2);
      iVar2 = iVar2 + 4;
      *piVar3 = *piVar8 + -1;
    } while (iVar2 != iVar14);
  }
  local_c0 = *param_2;
  piVar8 = (int *)local_ac;
  piVar3 = local_7c;
  if (local_a8 != (int *)0x0) {
    piVar8 = (int *)0x0;
    ppiVar15 = param_2;
    do {
      piVar3 = (int *)0x0;
      if (piVar5 != (int *)0x0) {
        do {
          ppiVar9 = (int **)((int)ppiVar15 + (int)piVar3);
          piVar3 = piVar3 + 1;
          if (local_c0 < *ppiVar9) {
            local_c0 = *ppiVar9;
          }
        } while ((int *)((int)piVar5 * 4) != piVar3);
      }
      piVar8 = (int *)((int)piVar8 + 1);
      ppiVar15 = ppiVar15 + (int)piVar5;
    } while (piVar8 != local_a8);
    uVar27 = (int)local_c0 << (uVar35 & 0x1f);
    piVar8 = (int *)0x0;
    local_c4 = piVar23;
    local_b0 = (code *)piVar36;
    local_b8 = (int *)((int)piVar5 * 4);
    do {
      if (piVar5 != (int *)0x0) {
        if (local_c0 == (int *)0x0) {
          (&zone_pix_wgh)[(int)piVar8 * 0xf] = 0;
          goto LAB_00029d60;
        }
        puVar22 = &zone_pix_wgh + (int)piVar8 * 0xf;
        piVar36 = (int *)0x0;
        ppiVar15 = param_2;
        do {
          uVar31 = fix_point_div_32(uVar35,(int)*ppiVar15 << (uVar35 & 0x1f),uVar27);
          piVar36 = (int *)((int)piVar36 + 1);
          *puVar22 = uVar31;
          ppiVar15 = ppiVar15 + 1;
          puVar22 = puVar22 + 1;
        } while (piVar36 != piVar5);
      }
      local_4c = local_7c;
      piVar36 = (int *)local_b0;
      piVar8 = (int *)((int)piVar8 + 1);
      param_2 = (int **)((int)param_2 + (int)local_b8);
    } while (piVar8 != local_a8);
    local_7c = (int *)((int)piVar5 * (int)local_a8 * 4);
    piVar23 = (int *)0x0;
    puVar22 = param_1;
    do {
      if (piVar5 != (int *)0x0) {
        puVar32 = puVar22 + (int)piVar5 * (int)local_a8;
        piVar8 = (int *)0x0;
        puVar20 = puVar22;
        do {
          uVar27 = local_c4[0xe] << (uVar35 & 0x1f);
          if ((uVar27 < *puVar20) || (uVar27 = *local_c4 << (uVar35 & 0x1f), *puVar20 < uVar27)) {
            *puVar20 = uVar27;
          }
          uVar27 = *(int *)((int)local_b0 + 0x38) << (uVar35 & 0x1f);
          if ((uVar27 < *puVar32) ||
             (uVar27 = *(int *)local_b0 << (uVar35 & 0x1f), *puVar32 < uVar27)) {
            *puVar32 = uVar27;
          }
          piVar8 = (int *)((int)piVar8 + 1);
          puVar20 = puVar20 + 1;
          puVar32 = puVar32 + 1;
        } while (piVar8 != piVar5);
      }
      piVar23 = (int *)((int)piVar23 + 1);
      puVar22 = (uint *)((int)puVar22 + (int)local_b8);
    } while (piVar23 != local_a8);
    local_b0 = (code *)0x0;
    local_50 = (int *)local_ac;
    local_70 = local_b8;
    local_30 = local_c4;
    local_ac = (code *)param_1;
    do {
      if (piVar5 != (int *)0x0) {
        puVar20 = &rgbg_wght + (int)local_b0 * 0xf;
        puVar32 = (uint *)((int)local_7c + (int)local_ac);
        piVar23 = (int *)0x0;
        puVar22 = (uint *)local_ac;
        do {
          uVar27 = *puVar22;
          if ((uVar27 < (uint)(*local_30 << (uVar35 & 0x1f))) ||
             (uVar31 = local_30[0xe] << (uVar35 & 0x1f), uVar31 < uVar27)) {
            uVar27 = *puVar32;
            iVar2 = 0;
            if ((uint)(*piVar36 << (uVar35 & 0x1f)) <= uVar27) goto LAB_0002a048;
LAB_00029b54:
            iVar14 = -1;
            if (iVar2 == 0xf) {
              iVar29 = 0;
LAB_0002a56c:
              iVar2 = (iVar29 + -1) * 0x38;
              *(int *)(iVar2 + 0xb7ac4) = *(int *)(iVar2 + 0xb7ac4) + 1;
              if (iVar29 != 0) {
                if (iVar29 != 0xf) goto LAB_0002a5a0;
LAB_0002a67c:
                uVar27 = *(int *)((int)local_c8 + 0x380) << (uVar35 & 0x1f);
                *puVar20 = uVar27;
                if (local_a4 != (undefined4 *)0x1) goto LAB_00029b94;
                uVar31 = *(uint *)(local_a0 + 0x380);
                local_3c = piVar5;
                local_34 = piVar23;
                goto LAB_0002a1d8;
              }
            }
            else {
              iVar29 = 0;
              iVar16 = -2;
LAB_00029b68:
              iVar11 = iVar2 + -1;
              (&Cluster_rgbg_index_num)[(iVar14 * 0x10 - iVar16) + iVar11] =
                   (&Cluster_rgbg_index_num)[(iVar14 * 0x10 - iVar16) + iVar11] + 1;
              if ((iVar2 != 0) && (iVar29 != 0)) {
                if (iVar29 == 0xf) {
LAB_0002a0cc:
                  local_40 = (int *)((iVar2 + 0xd1) * 4);
                  local_44 = local_30 + iVar11;
                  piVar8 = local_30 + iVar2;
                  iVar14 = (iVar2 + 0xd2) * 4;
                  local_3c = piVar5;
                  local_34 = piVar23;
                  uVar27 = ISPAWBInterpolation1
                                     (uVar35,*puVar22,*local_44,*piVar8,
                                      *(uint *)((int)local_c8 + (iVar2 + 0xd1) * 4),
                                      *(uint *)((int)local_c8 + (iVar2 + 0xd2) * 4));
                  *puVar20 = uVar27;
                  piVar5 = local_3c;
                  piVar23 = local_34;
                  if (local_a4 == (undefined4 *)0x1) {
                    uVar31 = *puVar22;
                    uVar27 = *(uint *)(local_a0 + (int)local_40);
                    goto LAB_0002a170;
                  }
                }
                else {
                  iVar14 = iVar29 * 0xf + iVar2;
                  local_44 = (int *)((iVar14 + -0x10) * 4);
                  local_c0 = local_30 + iVar11;
                  local_b8 = local_30 + iVar2;
                  local_48 = (int *)((iVar14 + -0xf) * 4);
                  local_3c = piVar5;
                  local_34 = piVar23;
                  local_38 = (int *)ISPAWBInterpolation1
                                              (uVar35,*puVar22,*local_c0,*local_b8,
                                               *(uint *)((int)local_c8 + (iVar14 + -0x10) * 4),
                                               *(uint *)((int)local_c8 + (iVar14 + -0xf) * 4));
                  local_c4 = (int *)((iVar14 + -1) * 4);
                  uVar27 = ISPAWBInterpolation1
                                     (uVar35,*puVar22,*local_c0,*local_b8,
                                      *(uint *)((int)local_c8 + (iVar14 + -1) * 4),
                                      *(uint *)((int)local_c8 + iVar14 * 4));
                  uVar27 = ISPAWBInterpolation2
                                     (uVar35,*puVar32,piVar36[iVar29 + -1],piVar36[iVar29],
                                      (uint)local_38,uVar27);
                  *puVar20 = uVar27;
                  piVar5 = local_3c;
                  piVar23 = local_34;
                  if (local_a4 == (undefined4 *)0x1) {
                    local_48 = (int *)ISPAWBInterpolation1
                                                (uVar35,*puVar22,*local_c0,*local_b8,
                                                 *(uint *)(local_a0 + (int)local_44),
                                                 *(uint *)(local_a0 + (int)local_48));
                    uVar27 = ISPAWBInterpolation1
                                       (uVar35,*puVar22,*local_c0,*local_b8,
                                        *(uint *)(local_a0 + (int)local_c4),
                                        *(uint *)(local_a0 + iVar14 * 4));
                    uVar27 = ISPAWBInterpolation2
                                       (uVar35,*puVar32,piVar36[iVar29 + -1],piVar36[iVar29],
                                        (uint)local_48,uVar27);
                    local_c0 = (int *)(1000000 / (uVar27 >> (uVar35 & 0x1f)));
                    uVar27 = func_zone_ct_weight((uint)local_c0,local_9c,(int)local_90,uVar35,
                                                 *puVar20,(uint)local_88,(uint)local_84);
                    *puVar20 = uVar27;
                    piVar5 = local_3c;
                    piVar23 = local_34;
                  }
                }
                goto LAB_00029b94;
              }
            }
LAB_00029b90:
            *puVar20 = 0;
          }
          else {
            if (uVar27 != uVar31) {
              iVar2 = 1;
              piVar8 = local_30;
              do {
                if (((uint)(*piVar8 << (uVar35 & 0x1f)) <= uVar27) &&
                   (uVar27 < (uint)(piVar8[1] << (uVar35 & 0x1f)))) goto LAB_00029b3c;
                iVar2 = iVar2 + 1;
                piVar8 = piVar8 + 1;
              } while (iVar2 != 0x10);
            }
            iVar2 = 0xf;
LAB_00029b3c:
            uVar27 = *puVar32;
            if (uVar27 < (uint)(*piVar36 << (uVar35 & 0x1f))) goto LAB_00029b54;
LAB_0002a048:
            uVar31 = piVar36[0xe] << (uVar35 & 0x1f);
            if (uVar31 < uVar27) goto LAB_00029b54;
            if (uVar27 != uVar31) {
              iVar29 = 1;
              piVar8 = piVar36;
              do {
                if (((uint)(*piVar8 << (uVar35 & 0x1f)) <= uVar27) &&
                   (uVar27 < (uint)(piVar8[1] << (uVar35 & 0x1f)))) {
                  if (iVar2 == 0xf) goto LAB_0002a560;
                  iVar14 = iVar29 + -1;
                  if (iVar29 == 0xf) goto LAB_0002a0b0;
                  iVar16 = iVar14 * 2;
                  goto LAB_00029b68;
                }
                iVar29 = iVar29 + 1;
                piVar8 = piVar8 + 1;
              } while (iVar29 != 0x10);
              if (iVar2 != 0xf) goto LAB_0002a0b0;
              iVar29 = 0xf;
LAB_0002a560:
              if (iVar29 == 0xf) goto LAB_0002a660;
              goto LAB_0002a56c;
            }
            if (iVar2 != 0xf) {
LAB_0002a0b0:
              (&Cluster_rgbg_index_num)[iVar2 + 0xb5] = (&Cluster_rgbg_index_num)[iVar2 + 0xb5] + 1;
              if (iVar2 != 0) {
                iVar11 = iVar2 + -1;
                goto LAB_0002a0cc;
              }
              goto LAB_00029b90;
            }
            iVar29 = 0xf;
LAB_0002a660:
            DAT_000b7d9c = DAT_000b7d9c + 1;
            if (iVar29 == 0xf) goto LAB_0002a67c;
LAB_0002a5a0:
            local_40 = (int *)(iVar29 * 0x3c + -4);
            local_44 = piVar36 + iVar29 + -1;
            piVar8 = piVar36 + iVar29;
            iVar14 = iVar29 * 0x3c + 0x38;
            local_3c = piVar5;
            local_34 = piVar23;
            uVar27 = ISPAWBInterpolation1
                               (uVar35,*puVar32,*local_44,*piVar8,
                                *(uint *)((int)local_c8 + (iVar29 * 0xf + -1) * 4),
                                *(uint *)((int)local_c8 + (iVar29 * 0xf + 0xe) * 4));
            *puVar20 = uVar27;
            piVar5 = local_3c;
            piVar23 = local_34;
            if (local_a4 == (undefined4 *)0x1) {
              uVar31 = *puVar32;
              uVar27 = *(uint *)(local_a0 + (int)local_40);
LAB_0002a170:
              uVar31 = ISPAWBInterpolation1
                                 (uVar35,uVar31,*local_44,*piVar8,uVar27,
                                  *(uint *)(local_a0 + iVar14));
              uVar31 = uVar31 >> (uVar35 & 0x1f);
              uVar27 = *puVar20;
LAB_0002a1d8:
              local_c0 = (int *)(1000000 / uVar31);
              uVar27 = func_zone_ct_weight((uint)local_c0,local_9c,(int)local_90,uVar35,uVar27,
                                           (uint)local_88,(uint)local_84);
              *puVar20 = uVar27;
              piVar5 = local_3c;
              piVar23 = local_34;
            }
          }
LAB_00029b94:
          piVar23 = (int *)((int)piVar23 + 1);
          puVar22 = puVar22 + 1;
          puVar20 = puVar20 + 1;
          puVar32 = puVar32 + 1;
        } while (piVar23 != piVar5);
      }
      local_b0 = (code *)((int)local_b0 + 1);
      local_ac = (code *)((int)local_ac + (int)local_70);
      piVar8 = local_50;
      piVar23 = local_30;
      piVar3 = local_4c;
    } while ((int *)local_b0 != local_a8);
  }
  if (local_8c != (int *)0x0) {
    local_a4 = &rgbg_wght;
    iVar2 = 1 << (uVar35 - 1 & 0x1f);
    local_c0 = piVar36;
    puVar22 = local_118;
    uVar27 = 0;
    local_c8 = (code *)piVar23;
    do {
      if (local_a8 != (int *)0x0) {
        iVar29 = 0;
        piVar25 = (int *)0x0;
        iVar14 = (int)piVar5 * (int)local_a8 * 4;
        puVar20 = &rgbg_wght + (int)piVar5;
        do {
          if (piVar5 != (int *)0x0) {
            uVar19 = *puVar22;
            uVar31 = puVar22[1];
            piVar4 = (int *)((int)param_1 + iVar14 + (int)piVar5 * (int)local_a8 * -4);
            puVar32 = &rgbg_wght + (int)piVar25 * 0xf;
            do {
              uVar17 = (uint)(iVar2 + *piVar4) >> (uVar35 & 0x1f);
              if (uVar17 < uVar19) {
                uVar12 = (uint)(iVar2 + *(int *)((int)piVar4 + iVar14 + iVar29)) >> (uVar35 & 0x1f);
                iVar16 = uVar19 - uVar17;
                if (uVar31 <= uVar12) goto LAB_00029d3c;
LAB_00029c94:
                iVar11 = uVar31 - uVar12;
              }
              else {
                uVar12 = (uint)(iVar2 + *(int *)((int)piVar4 + iVar14 + iVar29)) >> (uVar35 & 0x1f);
                iVar16 = uVar17 - uVar19;
                if (uVar12 < uVar31) goto LAB_00029c94;
LAB_00029d3c:
                iVar11 = uVar12 - uVar31;
              }
              uVar17 = iVar16 * iVar16 + iVar11 * iVar11;
              if (uVar17 < 0x332) {
                if (uVar17 < 0x2a7) {
                  if (uVar17 < 0x267) {
                    if (uVar17 < 0x23c) {
                      if (uVar17 < 0x21c) {
                        if (uVar17 < 0x202) {
                          iVar16 = *(int *)(local_80 + uVar17 * 4);
                        }
                        else {
                          iVar16 = 5;
                        }
                      }
                      else {
                        iVar16 = 4;
                      }
                    }
                    else {
                      iVar16 = 3;
                    }
                  }
                  else {
                    iVar16 = 2;
                  }
                }
                else {
                  iVar16 = 1;
                }
                uVar17 = iVar16 << (uVar35 & 0x1f);
                if (*puVar32 < uVar17) {
                  *puVar32 = uVar17;
                }
              }
              puVar32 = puVar32 + 1;
              piVar4 = piVar4 + 1;
            } while (puVar20 != puVar32);
          }
          piVar25 = (int *)((int)piVar25 + 1);
          puVar20 = puVar20 + 0xf;
          iVar29 = iVar29 + (int)piVar5 * -4;
          iVar14 = iVar14 + (int)piVar5 * 4;
        } while (piVar25 != local_a8);
      }
      uVar27 = uVar27 + 1;
      puVar22 = puVar22 + 2;
    } while ((int *)uVar27 != local_8c);
  }
  if (local_64 == (int *)0x1) {
    piVar25 = &DAT_000b87e4;
    piVar4 = &Cluster_rgbg_index_max;
    do {
      iVar14 = 0;
      iVar2 = 0;
      do {
        puVar22 = (uint *)((int)&Cluster_rgbg_index_num + (iVar14 * 0x40 - iVar2));
        iVar2 = 0;
        do {
          uVar27 = *puVar22;
          puVar22 = puVar22 + 1;
          if ((uVar27 != 0) && ((uint)piVar25[0xc] < uVar27)) {
            piVar25[-0xc] = iVar2;
            *piVar25 = iVar14;
            piVar25[0xc] = uVar27;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0xe);
        iVar14 = iVar14 + 1;
        iVar2 = iVar14 * 8;
      } while (iVar14 != 0xe);
      iVar2 = *piVar25;
      piVar10 = piVar25 + -0xc;
      piVar25 = piVar25 + 1;
      (&Cluster_rgbg_index_num)[iVar2 * 0xe + *piVar10] = 0;
    } while (piVar25 != &DAT_000b8814);
    puVar20 = &Cluster_rgbg_value1;
    puVar22 = puVar20;
    do {
      iVar14 = *piVar4;
      iVar2 = piVar4[0xc];
      puVar18 = (uint *)(piVar23 + iVar14);
      *puVar22 = *puVar18;
      puVar7 = (uint *)(piVar36 + iVar2);
      puVar22[0x3c] = *puVar7;
      puVar22[1] = *puVar18;
      puVar32 = (uint *)(piVar36 + iVar2 + 1);
      puVar22[0x3d] = *puVar32;
      puVar28 = (uint *)(piVar23 + iVar14 + 1);
      puVar22[2] = *puVar18 + 1 + *puVar28 >> 1;
      puVar22[0x3e] = *puVar7 + 1 + *puVar32 >> 1;
      puVar22[3] = *puVar28;
      piVar4 = piVar4 + 1;
      puVar22[0x3f] = *puVar7;
      puVar22[4] = *puVar28;
      puVar22[0x40] = *puVar32;
      puVar22 = puVar22 + 5;
    } while (piVar4 != &DAT_000b87e4);
    iVar2 = 1;
    uVar27 = Cluster_rgbg_value1;
    puVar22 = puVar20;
    if (Cluster_rgbg_value1 == 0) goto LAB_0002a940;
    while( true ) {
      if (puVar22[0x3c] == 0) goto LAB_0002a940;
      if (iVar2 == 0x3c) break;
      puVar32 = &Cluster_rgbg_value1 + iVar2;
      while( true ) {
        if ((*puVar32 == uVar27) && (puVar22[0x3c] == puVar32[0x3c])) {
          *puVar32 = 0;
          puVar32[0x3c] = 0;
        }
        if (puVar32 == (uint *)0xb85d0) break;
        puVar32 = puVar32 + 1;
        uVar27 = *puVar22;
      }
      while( true ) {
        puVar22 = puVar22 + 1;
        uVar27 = *puVar22;
        iVar2 = iVar2 + 1;
        if (uVar27 != 0) break;
LAB_0002a940:
        if (iVar2 == 0x3c) goto LAB_0002a94c;
      }
    }
LAB_0002a94c:
    iVar2 = 1 << (uVar35 - 1 & 0x1f);
    do {
      if (((*puVar20 != 0) && (puVar20[0x3c] != 0)) && (local_a8 != (int *)0x0)) {
        piVar25 = (int *)0x1;
        while( true ) {
          piVar4 = (int *)0x0;
          uVar27 = 0;
          iVar14 = 0;
          iVar29 = 0;
          puVar22 = param_1;
          do {
            if (piVar5 != (int *)0x0) {
              uVar19 = *puVar20;
              uVar31 = puVar20[0x3c];
              piVar10 = (int *)0x0;
              puVar32 = puVar22;
              do {
                uVar12 = *puVar32;
                uVar17 = uVar12 + iVar2 >> (uVar35 & 0x1f);
                if (uVar17 < uVar19) {
                  iVar16 = uVar19 - uVar17;
                }
                else {
                  iVar16 = uVar17 - uVar19;
                }
                puVar28 = puVar32 + 0xe1;
                uVar17 = *puVar28 + iVar2 >> (uVar35 & 0x1f);
                if (uVar17 < uVar31) {
                  iVar11 = uVar31 - uVar17;
                }
                else {
                  iVar11 = uVar17 - uVar31;
                }
                piVar10 = (int *)((int)piVar10 + 1);
                puVar32 = puVar32 + 1;
                if ((int *)(iVar16 * iVar16 + iVar11 * iVar11) <= piVar8) {
                  iVar29 = iVar29 + uVar12;
                  iVar14 = iVar14 + *puVar28;
                  uVar27 = uVar27 + 1;
                }
              } while (piVar10 != piVar5);
            }
            piVar4 = (int *)((int)piVar4 + 1);
            puVar22 = puVar22 + 0xf;
          } while (piVar4 != local_a8);
          if (uVar27 == 0) break;
          uVar17 = *puVar20;
          uVar31 = ((uVar27 >> 1) + iVar29) / uVar27 >> (uVar35 & 0x1f);
          uVar19 = ((uVar27 >> 1) + iVar14) / uVar27 >> (uVar35 & 0x1f);
          if (uVar17 < uVar31) {
            piVar4 = (int *)(uVar31 - uVar17);
          }
          else {
            piVar4 = (int *)(uVar17 - uVar31);
          }
          if (piVar4 <= local_5c) {
            uVar17 = puVar20[0x3c];
            if (uVar17 < uVar19) {
              piVar4 = (int *)(uVar19 - uVar17);
            }
            else {
              piVar4 = (int *)(uVar17 - uVar19);
            }
            if (piVar4 <= local_5c) break;
          }
          bVar1 = local_54 < piVar25;
          piVar25 = (int *)((int)piVar25 + 1);
          if (bVar1) break;
          *puVar20 = uVar31;
          puVar20[0x3c] = uVar19;
          puVar20[0x78] = uVar27;
        }
      }
      puVar20 = puVar20 + 1;
    } while (puVar20 != &DAT_000b85d4);
    puVar20 = &DAT_000b8304;
    puVar32 = &DAT_000b83f4;
    puVar22 = puVar20;
    do {
      uVar27 = *puVar22;
      puVar28 = &DAT_000b86c4;
      do {
        uVar31 = *puVar28;
        if ((uVar31 != 0) && (uVar27 < uVar31)) {
          uVar27 = puVar28[-0x3c];
          puVar22[-0x78] = puVar28[-0x78];
          puVar22[-0x3c] = uVar27;
          *puVar22 = uVar31;
          uVar27 = uVar31;
        }
        puVar28 = puVar28 + 1;
      } while (puVar28 != &Cluster_rgbg_index_max);
      iVar14 = 0;
      puVar28 = puVar20;
      if (uVar27 == 0) break;
      uVar27 = 0;
      iVar29 = 0;
      puVar7 = &DAT_000b86c4;
      do {
        uVar31 = *puVar7;
        if (uVar31 != 0) {
          uVar19 = puVar7[-0x78];
          uVar17 = puVar22[-0x78];
          if (uVar17 < uVar19) {
            uVar12 = puVar7[-0x3c];
            uVar21 = puVar22[-0x3c];
            iVar16 = uVar19 - uVar17;
            if (uVar12 <= uVar21) goto LAB_0002b540;
LAB_0002b4d0:
            iVar11 = uVar12 - uVar21;
          }
          else {
            uVar12 = puVar7[-0x3c];
            uVar21 = puVar22[-0x3c];
            iVar16 = uVar17 - uVar19;
            if (uVar21 < uVar12) goto LAB_0002b4d0;
LAB_0002b540:
            iVar11 = uVar21 - uVar12;
          }
          if ((int *)(iVar11 * iVar11 + iVar16 * iVar16) <= local_60) {
            iVar29 = uVar19 * uVar31 + iVar29;
            *puVar7 = 0;
            iVar14 = uVar12 * uVar31 + iVar14;
            uVar27 = uVar27 + uVar31;
          }
        }
        puVar7 = puVar7 + 1;
      } while (puVar7 != &Cluster_rgbg_index_max);
      if (uVar27 != 0) {
        *puVar22 = 0;
        puVar22[-0x78] = ((uVar27 >> 1) + iVar29) / uVar27;
        puVar22[-0x3c] = ((uVar27 >> 1) + iVar14) / uVar27;
      }
      puVar22 = puVar22 + 1;
    } while (puVar22 != &DAT_000b83f4);
    do {
      uVar27 = puVar28[-0x78];
      if ((uVar27 != 0) && (uVar31 = puVar28[-0x3c], uVar31 != 0)) {
        *puVar28 = 0;
        puVar28[0x3c] = 0;
        if (local_a8 != (int *)0x0) {
          piVar8 = (int *)0x0;
          puVar22 = param_1 + 0xe1;
          do {
            if (piVar5 != (int *)0x0) {
              piVar25 = &rgbg_wght + (int)piVar8 * 0xf;
              puVar7 = puVar22;
              do {
                iVar14 = *piVar25;
                if (iVar14 != 0) {
                  uVar19 = iVar2 + puVar7[-0xe1] >> (uVar35 & 0x1f);
                  if (uVar19 < uVar27) {
                    uVar17 = iVar2 + *puVar7 >> (uVar35 & 0x1f);
                    iVar29 = uVar27 - uVar19;
                    if (uVar31 <= uVar17) goto LAB_0002b68c;
LAB_0002b610:
                    iVar16 = uVar31 - uVar17;
                  }
                  else {
                    uVar17 = iVar2 + *puVar7 >> (uVar35 & 0x1f);
                    iVar29 = uVar19 - uVar27;
                    if (uVar17 < uVar31) goto LAB_0002b610;
LAB_0002b68c:
                    iVar16 = uVar17 - uVar31;
                  }
                  if ((int *)(iVar29 * iVar29 + iVar16 * iVar16) <= piVar3) {
                    *puVar28 = *puVar28 + 1;
                    puVar28[0x3c] = puVar28[0x3c] + iVar14;
                  }
                }
                puVar7 = puVar7 + 1;
                piVar25 = piVar25 + 1;
              } while (puVar22 + (int)piVar5 != puVar7);
            }
            piVar8 = (int *)((int)piVar8 + 1);
            puVar22 = puVar22 + 0xf;
          } while (piVar8 != local_a8);
        }
      }
      puVar28 = puVar28 + 1;
      puVar22 = puVar32;
    } while (puVar28 != &DAT_000b83f4);
    do {
      uVar27 = puVar22[-0x3c];
      if (uVar27 != 0) {
        *puVar22 = ((uVar27 >> 1) + *puVar22) / uVar27;
      }
      puVar22 = puVar22 + 1;
      uVar27 = 0;
    } while (puVar22 != &Cluster_rgbg_value1);
    do {
      uVar31 = *puVar32;
      puVar32 = puVar32 + 1;
      if ((uVar31 != 0) && (uVar27 < uVar31)) {
        uVar27 = uVar31;
      }
      puVar22 = puVar20;
    } while (puVar32 != &Cluster_rgbg_value1);
    do {
      if (*puVar22 != 0) {
        *puVar22 = (*puVar22 * puVar22[0x3c] + (uVar27 >> 1)) / uVar27;
      }
      puVar22 = puVar22 + 1;
    } while (puVar22 != &DAT_000b83f4);
    uVar27 = 0;
    do {
      uVar31 = *puVar20;
      puVar20 = puVar20 + 1;
      if ((uVar31 != 0) && (uVar27 < uVar31)) {
        uVar27 = uVar31;
      }
    } while (puVar20 != &DAT_000b83f4);
    if (local_a8 == (int *)0x0) goto LAB_00029d60;
    puVar22 = param_1 + 0xe1;
    piVar8 = (int *)0x0;
    do {
      if (piVar5 != (int *)0x0) {
        puVar32 = &rgbg_wght + (int)piVar8 * 0xf;
        puVar20 = puVar22;
        do {
          puVar28 = &Cluster_rgbg_value2;
          iVar14 = 1;
          iVar29 = 0;
LAB_0002b810:
          do {
            iVar16 = iVar14;
            uVar31 = *puVar28;
            if ((uVar31 != 0) && (uVar19 = puVar28[0x3c], uVar19 != 0)) {
              uVar17 = iVar2 + puVar20[-0xe1] >> (uVar35 & 0x1f);
              if (uVar17 < uVar31) {
                iVar14 = uVar31 - uVar17;
                uVar31 = iVar2 + *puVar20 >> (uVar35 & 0x1f);
                if (uVar19 <= uVar31) goto LAB_0002b85c;
LAB_0002b7c8:
                iVar11 = uVar19 - uVar31;
              }
              else {
                iVar14 = uVar17 - uVar31;
                uVar31 = iVar2 + *puVar20 >> (uVar35 & 0x1f);
                if (uVar31 < uVar19) goto LAB_0002b7c8;
LAB_0002b85c:
                iVar11 = uVar31 - uVar19;
              }
              if ((int *)(iVar14 * iVar14 + iVar11 * iVar11) <= piVar3) {
                if (iVar29 == 0) {
                  puVar28 = puVar28 + 1;
                  iVar14 = iVar16 + 1;
                  iVar29 = iVar16;
                  if (puVar28 == &DAT_000b8214) break;
                  goto LAB_0002b810;
                }
                if ((uint)(&Cluster_rgbg_value2)[iVar29 + 0x77] < puVar28[0x78]) {
                  iVar29 = iVar16;
                }
              }
            }
            puVar28 = puVar28 + 1;
            iVar14 = iVar16 + 1;
            iVar16 = iVar29;
          } while (puVar28 != &DAT_000b8214);
          if (iVar16 == 0) {
            *puVar32 = ((uVar27 >> 1) + *puVar32) / uVar27;
          }
          else {
            *puVar32 = ((&Cluster_rgbg_value2)[iVar16 + 0x77] * *puVar32 + (uVar27 >> 1)) / uVar27;
          }
          puVar20 = puVar20 + 1;
          puVar32 = puVar32 + 1;
        } while (puVar22 + (int)piVar5 != puVar20);
      }
      piVar8 = (int *)((int)piVar8 + 1);
      puVar22 = puVar22 + 0xf;
      local_c8 = (code *)piVar23;
      local_b0 = (code *)piVar3;
    } while (piVar8 != local_a8);
  }
  else if (local_a8 == (int *)0x0) goto LAB_00029d60;
  local_a4 = &rgbg_wght;
  local_90 = (int *)((int)piVar5 * 4);
  piVar8 = local_90 + 0x2ddc3;
  piVar3 = (int *)0x0;
  iVar2 = 0;
  do {
    if (piVar5 != (int *)0x0) {
      piVar25 = &rgbg_wght + (int)piVar3 * 0xf;
      do {
        iVar14 = *piVar25;
        piVar25 = piVar25 + 1;
        iVar2 = iVar2 + iVar14;
      } while (piVar8 != piVar25);
    }
    piVar3 = (int *)((int)piVar3 + 1);
    piVar8 = piVar8 + 0xf;
  } while (piVar3 < local_a8);
  if (iVar2 == 0) {
LAB_00029d60:
    *param_20 = 1;
    *local_78 = 5000;
    *param_19 = 0x100;
    param_19[1] = 0x100;
    return;
  }
  *param_20 = 0;
  if (local_a8 == (int *)0x0) {
LAB_0002a4d0:
    *param_20 = 1;
    *local_78 = 5000;
    *param_19 = 0x100;
    param_19[1] = 0x100;
    return;
  }
  local_c0 = (int *)((int)piVar5 * (int)local_a8 * 4);
  local_80 = (int)piVar5 * -4;
  local_84 = param_1 + -((int)piVar5 * (int)local_a8);
  uVar31 = 0;
  iVar2 = 0;
  local_88 = (int *)local_74;
  local_98 = (int *)local_74;
  local_b8 = (int *)0x0;
  local_ac = (code *)0x0;
  uVar27 = 0;
  iVar14 = 0;
  uVar19 = 0;
  uVar17 = 0;
  local_c4 = piVar5;
  local_9c = (uint *)local_c0;
  local_8c = piVar23;
  local_7c = piVar36;
  do {
    if (local_c4 != (int *)0x0) {
      local_38 = local_a4 + (int)local_ac * 0xf;
      puVar24 = (undefined4 *)((int)local_c0 + (int)local_84);
      local_b0 = fix_point_mult3_32;
      local_30 = (int *)0x0;
      piVar5 = &zone_pix_wgh + (int)local_ac * 0xf;
      local_c8 = fix_point_mult2_32;
      piVar36 = local_98;
      uVar12 = uVar31;
      uVar21 = uVar19;
      uVar33 = uVar27;
      do {
        local_44 = piVar5;
        local_34 = piVar36;
        iVar29 = (*local_b0)(uVar35,*local_38,*piVar5,*piVar36 << (uVar35 & 0x1f));
        iVar16 = (*local_c8)(uVar35,*puVar24,iVar29);
        uVar27 = iVar16 + uVar33;
        iVar14 = (uint)(uVar27 < uVar33) + iVar14;
        iVar16 = (*local_c8)(uVar35,*(undefined4 *)((int)local_b8 + (int)puVar24 + (int)local_c0),
                             iVar29);
        uVar31 = iVar16 + uVar12;
        uVar19 = uVar21 + iVar29;
        iVar2 = (uint)(uVar31 < uVar12) + iVar2;
        uVar17 = (uVar19 < uVar21) + uVar17;
        local_30 = (int *)((int)local_30 + 1);
        local_38 = local_38 + 1;
        piVar5 = local_44 + 1;
        piVar36 = local_34 + 1;
        puVar24 = puVar24 + 1;
        uVar12 = uVar31;
        uVar21 = uVar19;
        uVar33 = uVar27;
      } while (local_30 != local_c4);
    }
    local_ac = (code *)((int)local_ac + 1);
    local_98 = local_98 + 0xf;
    local_b8 = (int *)((int)local_b8 + local_80);
    local_c0 = (int *)((int)local_c0 + (int)local_90);
  } while ((int *)local_ac != local_a8);
  if ((uVar19 | uVar17) == 0) goto LAB_0002a4d0;
  local_30 = local_8c;
  local_3c = local_c4;
  local_40 = local_90;
  local_38 = local_7c;
  pcVar13 = fix_point_div_64;
  uVar37 = fix_point_div_64(uVar35,fix_point_div_64,uVar27,iVar14,uVar19,uVar17);
  local_c8 = (code *)uVar37;
  uVar37 = fix_point_div_64(uVar35,pcVar13,uVar31,iVar2,uVar19,uVar17);
  piVar5 = (int *)uVar37;
  piVar36 = local_30;
  piVar23 = local_38;
  if (local_68 == (int *)0x1) {
    local_c0 = local_40;
    local_b0 = (code *)local_30;
    local_ac = (code *)local_38;
    uVar27 = 0;
    piVar36 = (int *)0x0;
    local_40 = (int *)0x0;
    piVar23 = (int *)local_9c;
    piVar8 = local_3c;
    piVar3 = (int *)local_74;
    local_98 = (int *)uVar19;
    local_94 = uVar17;
    do {
      piVar25 = piVar3;
      if (piVar8 != (int *)0x0) {
        puVar28 = (uint *)((int)piVar23 + (int)local_84);
        puVar32 = &zone_pix_wgh + (int)piVar36 * 0xf;
        puVar20 = &rgbg_dis + (int)piVar36 * 0xf;
        puVar22 = local_a4 + (int)piVar36 * 0xf;
        piVar4 = (int *)0x0;
        local_c4 = piVar23;
        local_b8 = piVar8;
        local_90 = piVar3;
        local_8c = piVar36;
        do {
          uVar31 = *puVar28;
          if (uVar31 < local_c8) {
            uVar31 = (int)local_c8 - uVar31;
            piVar36 = *(int **)((int)local_40 + (int)puVar28 + (int)local_c4);
            local_48 = (int *)((int)piVar36 - (int)piVar5);
          }
          else {
            uVar31 = uVar31 - (int)local_c8;
            piVar36 = *(int **)((int)local_40 + (int)puVar28 + (int)local_c4);
            local_48 = (int *)((int)piVar36 - (int)piVar5);
          }
          if (piVar36 < piVar5) {
            local_48 = (int *)((int)piVar5 - (int)piVar36);
          }
          local_34 = (int *)fix_point_mult2_32(uVar35,uVar31,uVar31);
          iVar2 = fix_point_mult2_32(uVar35,(uint)local_48,(uint)local_48);
          uVar31 = *puVar22;
          *puVar20 = iVar2 + (int)local_34;
          if (((uVar31 != 0) && (*puVar32 != 0)) && (*piVar3 != 0)) {
            uVar31 = fix_point_mult3_32(uVar35,iVar2 + (int)local_34,uVar31,*puVar32);
            iVar2 = fix_point_mult2_32(uVar35,uVar31,*piVar3 << (uVar35 & 0x1f));
            uVar27 = uVar27 + iVar2;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          puVar28 = puVar28 + 1;
          puVar32 = puVar32 + 1;
          piVar3 = piVar3 + 1;
          puVar20 = puVar20 + 1;
          puVar22 = puVar22 + 1;
          piVar36 = local_8c;
          piVar23 = local_c4;
          piVar8 = local_b8;
          piVar25 = local_90;
        } while (piVar4 != local_b8);
      }
      local_40 = (int *)((int)local_40 + local_80);
      piVar36 = (int *)((int)piVar36 + 1);
      piVar23 = (int *)((int)piVar23 + (int)local_c0);
      piVar3 = piVar25 + 0xf;
    } while (piVar36 != local_a8);
    local_30 = (int *)local_b0;
    local_38 = (int *)local_ac;
    local_40 = local_c0;
    local_3c = piVar8;
    local_98 = (int *)fix_point_div_32(uVar35,uVar27,(uint)local_98);
    piVar36 = local_30;
    piVar23 = local_38;
    if (local_98 != (int *)0x0) {
      local_8c = (int *)(1 << (uVar35 & 0x1f));
      local_b0 = (code *)0x0;
      piVar36 = (int *)0x0;
      piVar3 = (int *)0x0;
      piVar8 = (int *)0x0;
      local_b8 = (int *)0x0;
      local_b4 = 0;
      local_c0 = (int *)0x0;
      local_bc = 0;
      local_90 = local_3c;
      local_68 = local_30;
      local_64 = local_38;
      local_60 = local_40;
      local_70 = piVar5;
      do {
        if (local_90 != (int *)0x0) {
          puVar26 = (undefined4 *)((int)local_9c + (int)local_84);
          puVar22 = &rgbg_dis + (int)piVar36 * 0xf;
          puVar34 = &zone_pix_wgh + (int)piVar36 * 0xf;
          puVar30 = &rgbg_d_wght + (int)piVar36 * 0xf;
          local_74 = fix_point_mult3_32;
          puVar24 = local_a4 + (int)piVar36 * 0xf;
          local_7c = (int *)((int)local_58 - (int)local_6c);
          local_c4 = (int *)0x0;
          local_ac = fix_point_mult2_32;
          piVar5 = local_88;
          local_5c = piVar36;
          do {
            local_48 = piVar3;
            local_34 = piVar8;
            piVar36 = (int *)fix_point_div_32(uVar35,*puVar22,(uint)local_98);
            if (local_58 < piVar36) {
              *puVar30 = 0;
              uVar6 = 0;
            }
            else if (piVar36 < local_6c) {
              uVar6 = *puVar24;
              *puVar30 = uVar6;
            }
            else {
              uVar6 = *puVar24;
              uVar27 = fix_point_div_32(uVar35,(int)piVar36 - (int)local_6c,(uint)local_7c);
              uVar6 = (*local_ac)(uVar35,uVar6,(int)local_8c - uVar27);
              *puVar30 = uVar6;
            }
            iVar2 = (*local_74)(uVar35,uVar6,*puVar34,*piVar5 << (uVar35 & 0x1f));
            iVar14 = (*local_ac)(uVar35,*puVar26,iVar2);
            local_bc = (uint)((int *)(iVar14 + (int)local_c0) < local_c0) + local_bc;
            local_c0 = (int *)(iVar14 + (int)local_c0);
            iVar14 = (*local_ac)(uVar35,*(undefined4 *)
                                         ((int)puVar26 + (int)local_b0 + (int)local_9c),iVar2);
            piVar23 = (int *)(iVar14 + (int)local_b8);
            piVar3 = (int *)((int)local_48 + iVar2);
            uVar27 = (piVar23 < local_b8) + local_b4;
            piVar8 = (int *)((uint)(piVar3 < local_48) + (int)local_34);
            local_c4 = (int *)((int)local_c4 + 1);
            puVar22 = puVar22 + 1;
            puVar34 = puVar34 + 1;
            piVar5 = piVar5 + 1;
            puVar26 = puVar26 + 1;
            puVar30 = puVar30 + 1;
            puVar24 = puVar24 + 1;
            piVar36 = local_5c;
            local_b8 = piVar23;
            local_b4 = uVar27;
          } while (local_c4 != local_90);
        }
        local_b0 = (code *)((int)local_b0 + local_80);
        local_9c = (uint *)((int)local_9c + (int)local_60);
        local_88 = local_88 + 0xf;
        piVar36 = (int *)((int)piVar36 + 1);
      } while (piVar36 != local_a8);
      piVar36 = local_68;
      piVar5 = local_70;
      piVar23 = local_64;
      if (((uint)piVar3 | (uint)piVar8) != 0) {
        local_30 = local_68;
        local_38 = local_64;
        local_48 = piVar3;
        local_34 = piVar8;
        uVar37 = fix_point_div_64(uVar35,uVar27,(uint)local_c0,local_bc,(uint)piVar3,(uint)piVar8);
        local_c8 = (code *)uVar37;
        uVar37 = fix_point_div_64(uVar35,uVar27,(uint)local_b8,local_b4,(uint)local_48,
                                  (uint)local_34);
        piVar5 = (int *)uVar37;
        piVar36 = local_30;
        piVar23 = local_38;
      }
    }
  }
  uVar31 = piVar36[0xe] << (uVar35 & 0x1f);
  uVar27 = uVar31;
  if ((local_c8 <= uVar31) &&
     (uVar19 = *piVar36 << (uVar35 & 0x1f), uVar27 = (uint)local_c8, local_c8 <= uVar19)) {
    uVar27 = uVar19;
  }
  piVar3 = (int *)(piVar23[0xe] << (uVar35 & 0x1f));
  piVar8 = piVar3;
  if ((piVar5 <= piVar3) &&
     (piVar25 = (int *)(*piVar23 << (uVar35 & 0x1f)), piVar8 = piVar5, piVar5 <= piVar25)) {
    piVar8 = piVar25;
  }
  if (uVar27 == uVar31) {
    if (piVar8 != piVar3) {
      iVar2 = 0xf;
      goto LAB_0002abf0;
    }
LAB_0002b3f8:
    iVar14 = 0x3bc;
    iVar16 = 0x380;
    iVar2 = 0x3c;
    iVar29 = 0x38;
LAB_0002b36c:
    uVar31 = ISPAWBInterpolation1
                       (uVar35,(int)piVar8,*(int *)((int)piVar23 + iVar29),
                        *(int *)((int)piVar23 + iVar2),*(uint *)(local_a0 + iVar16),
                        *(uint *)(local_a0 + iVar14));
  }
  else {
    iVar2 = 1;
    piVar5 = piVar36;
    do {
      if (((uint)(*piVar5 << (uVar35 & 0x1f)) <= uVar27) &&
         (uVar27 < (uint)(piVar5[1] << (uVar35 & 0x1f)))) goto LAB_0002abe8;
      iVar2 = iVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 != 0x10);
    iVar2 = 0xf;
LAB_0002abe8:
    if (piVar8 == piVar3) {
      if (iVar2 == 0xf) goto LAB_0002b3f8;
    }
    else {
LAB_0002abf0:
      iVar14 = 0;
      piVar5 = piVar23;
      while( true ) {
        iVar11 = iVar14 + 1;
        if (((int *)(*piVar5 << (uVar35 & 0x1f)) <= piVar8) &&
           (piVar8 < (int *)(piVar5[1] << (uVar35 & 0x1f)))) {
          if (iVar2 == 0xf) goto LAB_0002b350;
          if (iVar11 == 0xf) goto LAB_0002b2a4;
          iVar29 = iVar11 * 0xf + iVar2;
          local_38 = piVar23;
          local_30 = (int *)ISPAWBInterpolation1
                                      (uVar35,uVar27,piVar36[iVar2 + -1],piVar36[iVar2],
                                       *(uint *)(local_a0 + (iVar29 + -0x10) * 4),
                                       *(uint *)(local_a0 + (iVar29 + -0xf) * 4));
          uVar31 = ISPAWBInterpolation1
                             (uVar35,uVar27,piVar36[iVar2 + -1],piVar36[iVar2],
                              *(uint *)(local_a0 + (iVar29 + -1) * 4),
                              *(uint *)(local_a0 + iVar29 * 4));
          uVar31 = ISPAWBInterpolation2
                             (uVar35,(int)piVar8,local_38[iVar14],local_38[iVar11],(uint)local_30,
                              uVar31);
          goto LAB_0002b2fc;
        }
        piVar5 = piVar5 + 1;
        if (iVar14 == 0xe) break;
        iVar14 = iVar14 + 1;
      }
      if (iVar2 == 0xf) {
        iVar11 = 0xf;
LAB_0002b350:
        iVar2 = iVar11 * 4;
        iVar16 = iVar11 * 0x3c + -4;
        iVar29 = (iVar11 + -1) * 4;
        iVar14 = iVar11 * 0x3c + 0x38;
        goto LAB_0002b36c;
      }
    }
LAB_0002b2a4:
    uVar31 = ISPAWBInterpolation1
                       (uVar35,uVar27,piVar36[iVar2 + -1],piVar36[iVar2],
                        *(uint *)(local_a0 + (iVar2 + 0xd1) * 4),
                        *(uint *)(local_a0 + (iVar2 + 0xd2) * 4));
  }
LAB_0002b2fc:
  if (uVar31 == 0) {
    *local_78 = 5000;
    iVar2 = 1 << (uVar35 - 1 & 0x1f);
  }
  else {
    uVar31 = fix_point_div_32(uVar35,1000000 << (uVar35 & 0x1f),uVar31);
    iVar2 = 1 << (uVar35 - 1 & 0x1f);
    *local_78 = uVar31 + iVar2 >> (uVar35 & 0x1f);
  }
  *param_19 = iVar2 + uVar27 >> (uVar35 & 0x1f);
  param_19[1] = (uint)(iVar2 + (int)piVar8) >> (uVar35 & 0x1f);
  *param_20 = 0;
  return;
}



int subsection_map(int param_1,int param_2,int param_3,short *param_4,int param_5,int *param_6,
                  int param_7,uint param_8,uint param_9,int param_10)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  
  iVar6 = 0;
  iVar5 = 0;
  iVar3 = 0;
  iVar2 = 10000;
LAB_0002b984:
  do {
    iVar4 = *param_6;
    if (param_1 < iVar4) {
      iVar4 = iVar4 - param_1;
      if (iVar4 < iVar2) goto LAB_0002b9a4;
LAB_0002b970:
      if (iVar4 != iVar2) {
        iVar3 = iVar3 + 1;
        param_6 = param_6 + 1;
        if (iVar3 == 0x200) break;
        goto LAB_0002b984;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + iVar3;
    }
    else {
      iVar4 = param_1 - iVar4;
      if (iVar2 <= iVar4) goto LAB_0002b970;
LAB_0002b9a4:
      iVar6 = 1;
      iVar5 = iVar3;
    }
    iVar3 = iVar3 + 1;
    param_6 = param_6 + 1;
    iVar2 = iVar4;
  } while (iVar3 != 0x200);
  if (iVar5 < 1) {
    iVar5 = 1;
  }
  if (iVar6 < 1) {
    iVar6 = 1;
  }
  uVar1 = fix_point_div_32(param_9,iVar5 << (param_9 & 0x1f),iVar6 << (param_9 & 0x1f));
  iVar6 = (1 << (param_9 & 0x1f)) / 2;
  iVar5 = (int)*(short *)(param_5 + 0x100);
  iVar3 = ((int)(iVar6 + uVar1) >> (param_9 & 0x1f)) * param_7 + -1;
  iVar2 = 0;
  psVar7 = param_4;
  do {
    iVar4 = (int)*psVar7;
    if (iVar3 < iVar4) {
      psVar7 = (short *)(param_5 + iVar2 * 2);
      uVar1 = fix_point_div_32(param_9,(int)*psVar7 - (int)*(short *)(param_5 + (iVar2 + -1) * 2) <<
                                       (param_9 & 0x1f),
                               iVar4 - param_4[iVar2 + -1] << (param_9 & 0x1f));
      iVar2 = fix_point_mult2_32(param_9,uVar1,iVar4 - iVar3 << (param_9 & 0x1f));
      iVar5 = (int)*psVar7 - (iVar6 + iVar2 >> (param_9 & 0x1f));
      break;
    }
    iVar2 = iVar2 + 1;
    psVar7 = psVar7 + 1;
  } while (iVar2 != 0x81);
  if ((param_10 == 1) || (iVar5 <= param_2)) {
    iVar2 = (iVar5 - param_2) * param_3 + param_2 * 100;
  }
  else {
    iVar2 = param_2 * 100;
  }
  uVar1 = fix_point_div_32(param_8,iVar2 << (param_8 & 0x1f),100 << (param_8 & 0x1f));
  return (int)((1 << (param_8 & 0x1f)) / 2 + uVar1) >> (param_8 & 0x1f);
}



void subsection(undefined4 *param_1,int param_2,short *param_3,short *param_4,int *param_5,
               int param_6,uint param_7,uint param_8,int param_9)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = 2 << (param_7 & 0x1f);
  *param_1 = 0;
  param_1[8] = 0xfff;
  uVar1 = fix_point_div_32(param_7,0xfff << (param_7 & 0x1f),uVar9);
  iVar2 = subsection_map(5000,(int)(uVar1 + 0x200) >> (param_7 & 0x1f),param_2,param_3,(int)param_4,
                         param_5,param_6,param_7,param_8,param_9);
  iVar8 = (int)param_3[0x80];
  iVar4 = 0;
  psVar5 = param_4;
  do {
    iVar3 = (int)*psVar5;
    if (iVar2 < iVar3) {
      uVar1 = fix_point_div_32(param_7,(int)param_3[iVar4] - (int)param_3[iVar4 + -1] <<
                                       (param_7 & 0x1f),
                               iVar3 - param_4[iVar4 + -1] << (param_7 & 0x1f));
      iVar8 = fix_point_mult2_32(param_7,uVar1,iVar3 - iVar2 << (param_7 & 0x1f));
      iVar8 = (int)param_3[iVar4] - (iVar8 + 0x200 >> (param_7 & 0x1f));
      break;
    }
    iVar4 = iVar4 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar4 != 0x81);
  uVar10 = param_6 << (param_7 & 0x1f);
  param_1[4] = iVar8;
  uVar1 = fix_point_div_32(param_7,iVar8 << (param_7 & 0x1f),uVar10);
  iVar8 = param_5[(int)(uVar1 + 0x200) >> (param_7 & 0x1f)];
  uVar1 = fix_point_div_32(param_7,iVar2 << (param_7 & 0x1f),uVar9);
  iVar8 = subsection_map(iVar8 / 2,(int)(uVar1 + 0x200) >> (param_7 & 0x1f),param_2,param_3,
                         (int)param_4,param_5,param_6,param_7,param_8,param_9);
  iVar4 = (int)param_3[0x80];
  iVar3 = 0;
  psVar5 = param_4;
  do {
    iVar6 = (int)*psVar5;
    if (iVar8 < iVar6) {
      uVar1 = fix_point_div_32(param_7,(int)param_3[iVar3] - (int)param_3[iVar3 + -1] <<
                                       (param_7 & 0x1f),
                               iVar6 - param_4[iVar3 + -1] << (param_7 & 0x1f));
      iVar4 = fix_point_mult2_32(param_7,uVar1,iVar6 - iVar8 << (param_7 & 0x1f));
      iVar4 = (int)param_3[iVar3] - (iVar4 + 0x200 >> (param_7 & 0x1f));
      break;
    }
    iVar3 = iVar3 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar3 != 0x81);
  param_1[2] = iVar4;
  uVar1 = fix_point_div_32(param_7,iVar4 << (param_7 & 0x1f),uVar10);
  iVar4 = param_5[(int)(uVar1 + 0x200) >> (param_7 & 0x1f)];
  uVar1 = fix_point_div_32(param_7,iVar8 << (param_7 & 0x1f),uVar9);
  iVar4 = subsection_map(iVar4 / 2,(int)(uVar1 + 0x200) >> (param_7 & 0x1f),param_2,param_3,
                         (int)param_4,param_5,param_6,param_7,param_8,param_9);
  iVar3 = (int)param_3[0x80];
  iVar6 = 0;
  psVar5 = param_4;
  do {
    iVar7 = (int)*psVar5;
    if (iVar4 < iVar7) {
      uVar1 = fix_point_div_32(param_7,(int)param_3[iVar6] - (int)param_3[iVar6 + -1] <<
                                       (param_7 & 0x1f),
                               iVar7 - param_4[iVar6 + -1] << (param_7 & 0x1f));
      iVar4 = fix_point_mult2_32(param_7,uVar1,iVar7 - iVar4 << (param_7 & 0x1f));
      iVar3 = (int)param_3[iVar6] - (iVar4 + 0x200 >> (param_7 & 0x1f));
      break;
    }
    iVar6 = iVar6 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar6 != 0x81);
  param_1[1] = iVar3;
  uVar1 = fix_point_div_32(param_7,param_1[2] << (param_7 & 0x1f),uVar10);
  uVar10 = fix_point_div_32(param_7,param_1[4] << (param_7 & 0x1f),uVar10);
  iVar3 = param_5[(int)(uVar1 + 0x200) >> (param_7 & 0x1f)];
  iVar4 = param_5[(int)(uVar10 + 0x200) >> (param_7 & 0x1f)];
  uVar1 = fix_point_div_32(param_7,iVar8 + iVar2 << (param_7 & 0x1f),uVar9);
  iVar2 = subsection_map((iVar3 + iVar4) / 2,(int)(uVar1 + 0x200) >> (param_7 & 0x1f),param_2,
                         param_3,(int)param_4,param_5,param_6,param_7,param_8,param_9);
  iVar4 = (int)param_3[0x80];
  iVar8 = 0;
  psVar5 = param_4;
  do {
    iVar3 = (int)*psVar5;
    if (iVar2 < iVar3) {
      uVar1 = fix_point_div_32(param_7,(int)param_3[iVar8] - (int)param_3[iVar8 + -1] <<
                                       (param_7 & 0x1f),
                               iVar3 - param_4[iVar8 + -1] << (param_7 & 0x1f));
      iVar2 = fix_point_mult2_32(param_7,uVar1,iVar3 - iVar2 << (param_7 & 0x1f));
      iVar4 = (int)param_3[iVar8] - (iVar2 + 0x200 >> (param_7 & 0x1f));
      break;
    }
    iVar8 = iVar8 + 1;
    psVar5 = psVar5 + 1;
  } while (iVar8 != 0x81);
  iVar2 = param_1[4];
  param_1[3] = iVar4;
  param_1[5] = iVar2 + 1;
  param_1[6] = iVar2 + 2;
  param_1[7] = iVar2 + 3;
  if (0xffe < iVar2 + 3) {
    param_1[4] = 0xffb;
    param_1[5] = 0xffc;
    param_1[6] = 0xffd;
    param_1[7] = 0xffe;
  }
  iVar2 = 0xfff;
  if ((int)param_1[8] < 0x1000) {
    iVar2 = param_1[8];
  }
  param_1[8] = iVar2;
  return;
}



void subsection_up(undefined4 *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  *param_1 = 0;
  param_1[8] = 0xfff;
  iVar7 = 0;
  do {
    iVar4 = *(int *)(param_2 + iVar7 + 4);
    iVar6 = 0;
    iVar5 = 0;
    iVar1 = 0;
    piVar2 = param_3;
    iVar8 = 10000;
    do {
      while (iVar3 = *piVar2, iVar4 < iVar3) {
        iVar3 = iVar3 - iVar4;
        if (iVar8 <= iVar3) goto LAB_0002c184;
LAB_0002c1b8:
        iVar6 = 1;
        iVar5 = iVar1;
LAB_0002c1c8:
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
        iVar8 = iVar3;
        if (iVar1 == 0x200) goto LAB_0002c1d4;
      }
      iVar3 = iVar4 - iVar3;
      if (iVar3 < iVar8) goto LAB_0002c1b8;
LAB_0002c184:
      if (iVar3 == iVar8) {
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + iVar1;
        goto LAB_0002c1c8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 != 0x200);
LAB_0002c1d4:
    iVar8 = 1;
    if (0 < iVar6) {
      iVar8 = iVar6;
    }
    iVar8 = (iVar5 << 0xc) / iVar8;
    iVar1 = iVar7 + 4;
    iVar5 = iVar8 + 0x800;
    if (iVar5 < 0) {
      iVar5 = iVar8 + 0x17ff;
    }
    *(int *)((int)param_1 + iVar7 + 4) = (iVar5 >> 0xc) * param_4 + -1;
    iVar7 = iVar1;
    if (iVar1 == 0x1c) {
      return;
    }
  } while( true );
}



void subsection_light(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    while( true ) {
      iVar1 = *(int *)(param_1 + iVar3);
      iVar2 = *(int *)(param_2 + iVar3);
      if (iVar1 <= iVar2) break;
      iVar3 = iVar3 + 4;
      *param_4 = (iVar1 * 1000 - (iVar1 - iVar2) * param_3) / 1000;
      param_4 = param_4 + 1;
      if (iVar3 == 0x24) {
        return;
      }
    }
    iVar3 = iVar3 + 4;
    *param_4 = (iVar2 * 1000 - (iVar2 - iVar1) * param_3) / 1000;
    param_4 = param_4 + 1;
  } while (iVar3 != 0x24);
  return;
}



// WARNING: Type propagation algorithm not settling

void Tiziano_adr_fpga(int param_1,int *param_2,uint param_3,int **param_4,int *param_5,int **param_6
                     ,int param_7,int *param_8,int param_9,int **param_10,short *param_11,
                     short *param_12,int *param_13,uint *param_14,int *param_15,uint *param_16)

{
  short *psVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int **ppiVar5;
  int **ppiVar6;
  int **ppiVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  short *psVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  uint *puVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  int iVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  int *piVar26;
  undefined4 *puVar27;
  uint uVar28;
  int iVar29;
  int *piVar30;
  int iVar31;
  int *piVar32;
  int *local_428 [71];
  int aiStack_30c [10];
  int local_2e4;
  int local_2e0;
  undefined4 local_2dc [9];
  undefined4 local_2b8 [9];
  int local_294 [9];
  int local_270 [9];
  undefined4 auStack_24c [9];
  undefined4 local_228 [9];
  int *local_204;
  int *local_200;
  int *local_1fc;
  int *local_1f8;
  int *local_1f4;
  int *local_1f0;
  int *local_1ec;
  int *local_1e8;
  int *local_1e4;
  int *local_1e0 [9];
  int *local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  int *local_19c;
  int *local_198 [9];
  int *local_174 [10];
  uint local_14c [7];
  int **local_130;
  int *local_12c;
  int *local_128;
  int local_124;
  int *local_120;
  int *local_11c;
  int *local_118;
  int *local_114;
  uint local_110;
  int *local_10c;
  int **local_108;
  int *local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  int *local_f4;
  int *local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  int **local_e0;
  int **local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  int *local_b8;
  uint local_b4;
  uint local_b0;
  int **local_ac;
  int *local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  int local_98;
  int **local_94;
  int **local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  short *local_30;
  short *local_2c;
  
  puVar2 = &DAT_0007c4c0;
  local_a8 = param_5;
  local_90 = param_6;
  local_e0 = param_10;
  local_104 = param_13;
  local_128 = param_15;
  puVar12 = local_2b8;
  local_124 = param_1;
  local_108 = (int **)param_2;
  local_dc = param_4;
  local_d4 = param_3;
  do {
    uVar25 = *puVar2;
    uVar24 = puVar2[1];
    uVar22 = puVar2[2];
    uVar20 = puVar2[3];
    puVar2 = puVar2 + 4;
    *puVar12 = uVar25;
    puVar12[1] = uVar24;
    puVar12[2] = uVar22;
    puVar12[3] = uVar20;
    puVar12 = puVar12 + 4;
  } while (puVar2 != (undefined4 *)&UNK_0007c4e0);
  puVar2 = &DAT_0007c4e4;
  *puVar12 = 10000;
  puVar12 = local_2dc;
  do {
    uVar25 = *puVar2;
    uVar24 = puVar2[1];
    uVar22 = puVar2[2];
    uVar20 = puVar2[3];
    puVar2 = puVar2 + 4;
    *puVar12 = uVar25;
    puVar12[1] = uVar24;
    puVar12[2] = uVar22;
    puVar12[3] = uVar20;
    puVar12 = puVar12 + 4;
  } while (puVar2 != (undefined4 *)&UNK_0007c504);
  *puVar12 = 0xfff;
  local_30 = param_11;
  local_2c = param_12;
  local_a4 = fix_point_div_32(0x10,0x385b0000,0x27100000);
  psVar1 = local_2c;
  psVar14 = local_30;
  local_c0 = *param_16;
  aiStack_30c[3] = local_128[2];
  aiStack_30c[4] = local_128[3];
  aiStack_30c[5] = local_128[4];
  aiStack_30c[6] = local_128[5];
  local_2e4 = local_128[9];
  aiStack_30c[7] = local_128[6];
  aiStack_30c[8] = local_128[7];
  aiStack_30c[9] = local_128[8];
  local_bc = param_16[1];
  local_68 = param_16[3];
  local_d8 = param_16[2];
  local_b8 = (int *)param_16[7];
  local_d0 = param_16[10];
  local_cc = param_16[0xb];
  local_80 = param_16[4];
  local_c8 = param_16[0xc];
  aiStack_30c[1] = *local_128;
  aiStack_30c[2] = local_128[1];
  local_120 = (int *)param_16[6];
  uVar10 = param_16[8];
  uVar3 = param_16[9];
  local_64 = local_128[0x13];
  local_ec = local_128[0x12];
  local_118 = (int *)local_128[0xe];
  local_60 = local_128[0x14];
  local_c4 = param_16[0xd];
  local_54 = local_128[0x17];
  local_50 = local_128[0x18];
  local_5c = local_128[0x15];
  local_2e0 = local_128[10];
  local_58 = local_128[0x16];
  local_98 = local_128[0x1c];
  local_11c = (int *)local_128[0x19];
  iVar31 = local_128[0x1a];
  uVar28 = param_16[0xe];
  local_14c[0] = 0x1e;
  local_14c[1] = 0x28;
  local_4c = *param_14;
  local_48 = param_14[1];
  local_44 = param_14[2];
  local_40 = param_14[3];
  local_14c[2] = 0x32;
  local_b4 = param_14[4];
  local_14c[3] = 0x3c;
  local_7c = param_14[5];
  local_3c = param_14[6];
  local_78 = param_14[7];
  local_74 = param_14[8];
  local_38 = param_14[9];
  local_14c[4] = 0x46;
  local_34 = param_14[10];
  local_14c[5] = 0x50;
  local_14c[6] = 100;
  local_174[9] = (int *)0x0;
  iVar16 = 0;
  do {
    uVar20 = *(undefined4 *)((int)local_e0 + iVar16);
    puVar27 = (undefined4 *)((int)local_228 + iVar16);
    puVar12 = (undefined4 *)((int)local_198 + iVar16);
    puVar21 = (undefined4 *)((int)local_174 + iVar16);
    puVar2 = (undefined4 *)((int)local_1e0 + iVar16);
    iVar16 = iVar16 + 4;
    *puVar27 = uVar20;
    *puVar21 = uVar20;
    *puVar12 = uVar20;
    *puVar2 = uVar20;
  } while (iVar16 != 0x24);
  iVar16 = uVar10 * uVar3;
  if (iVar16 < 0) {
    iVar16 = iVar16 + 3;
  }
  iVar17 = iVar16 >> 2;
  iVar23 = 0;
  if (iVar17 < 0x1400) {
    iVar16 = 0x14;
    iVar13 = 0xd5;
    iVar17 = 0x1400;
  }
  else {
    iVar16 = iVar16 >> 10;
    iVar13 = iVar17 / 0x18;
    iVar23 = iVar16 / 0x18;
  }
  iVar4 = 0;
  iVar11 = 0;
  do {
    piVar26 = (int *)((int)param_8 + iVar4);
    iVar4 = iVar4 + 4;
    iVar11 = iVar11 + *piVar26;
  } while (iVar4 != 0xc0);
  local_e4 = iVar11 / iVar17;
  iVar4 = 0;
  local_128[0xb] = local_e4;
  iVar11 = 0;
  do {
    piVar26 = (int *)((int)&adr_hist_512 + iVar11);
    iVar4 = iVar4 + *(int *)(param_7 + iVar11);
    if (iVar17 < iVar4) {
      iVar4 = iVar17;
    }
    iVar11 = iVar11 + 4;
    *piVar26 = iVar4;
  } while (iVar11 != 0x800);
  iVar17 = 0;
  do {
    piVar26 = (int *)((int)&adr_hist_512 + iVar17);
    piVar18 = (int *)((int)&adr_prod + iVar17);
    iVar17 = iVar17 + 4;
    iVar4 = ((*piVar26 << 8) / iVar16) * 10000;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xffff;
    }
    *piVar18 = iVar4 >> 0x10;
  } while (iVar17 != 0x800);
  iVar16 = 0;
  do {
    iVar17 = param_9 + 0x78;
    puVar2 = &adr_block_hist_120 + iVar16;
    do {
      iVar4 = iVar17 + 0x14;
      *puVar2 = *(undefined4 *)(iVar17 + 0x14);
      puVar2[1] = *(undefined4 *)(iVar17 + 0x18);
      puVar2[2] = *(undefined4 *)(iVar17 + 0x1c);
      puVar2[3] = *(undefined4 *)(iVar17 + 0x20);
      puVar2[4] = *(undefined4 *)(iVar17 + 0x24);
      iVar17 = iVar4;
      puVar2 = puVar2 + 5;
    } while (iVar4 != param_9 + 200);
    iVar16 = iVar16 + 0x14;
    param_9 = param_9 + 0x78;
  } while (iVar16 != 0x78);
  iVar16 = 0;
  do {
    piVar26 = (int *)((int)&adr_block_hist_120 + iVar16);
    piVar18 = (int *)((int)&adr_block_prod + iVar16);
    iVar16 = iVar16 + 4;
    iVar17 = ((*piVar26 << 8) / iVar23) * 10000;
    if (iVar17 < 0) {
      iVar17 = iVar17 + 0xffff;
    }
    *piVar18 = iVar17 >> 0x10;
  } while (iVar16 != 0x1e0);
  puVar2 = &adr_block_y_24;
  piVar26 = param_8;
  do {
    piVar26 = piVar26 + 6;
    iVar16 = 0;
    do {
      iVar23 = iVar16 + 4;
      puVar12 = (undefined4 *)((int)puVar2 + iVar16);
      iVar16 = iVar16 + 4;
      *puVar12 = *(undefined4 *)((int)piVar26 + iVar23);
    } while (iVar16 != 0x10);
    puVar2 = puVar2 + 4;
  } while (puVar2 != &block_mean_y);
  if (uVar28 == 1) {
    adr_block_y_24 = adr_block_y_24 + *param_8 + param_8[1] + param_8[6];
    DAT_000b9c14 = DAT_000b9c14 + param_8[2];
    DAT_000b9c18 = DAT_000b9c18 + param_8[3];
    DAT_000b9c1c = DAT_000b9c1c + param_8[4] + param_8[5] + param_8[0xb];
    DAT_000b9c20 = DAT_000b9c20 + param_8[0xc];
    DAT_000b9c2c = DAT_000b9c2c + param_8[0x11];
    DAT_000b9c30 = DAT_000b9c30 + param_8[0x12];
    DAT_000b9c3c = DAT_000b9c3c + param_8[0x17];
    DAT_000b9c40 = DAT_000b9c40 + param_8[0x18];
    DAT_000b9c4c = DAT_000b9c4c + param_8[0x1d];
    DAT_000b9c50 = DAT_000b9c50 + param_8[0x1e];
    DAT_000b9c5c = DAT_000b9c5c + param_8[0x23];
    DAT_000b9c60 = DAT_000b9c60 + param_8[0x24] + param_8[0x2a] + param_8[0x2b];
    DAT_000b9c64 = DAT_000b9c64 + param_8[0x2c];
    DAT_000b9c68 = DAT_000b9c68 + param_8[0x2d];
    DAT_000b9c6c = DAT_000b9c6c + param_8[0x29] + param_8[0x2e] + param_8[0x2f];
  }
  local_f8 = &block_mean_y;
  piVar18 = &DAT_000b9c14;
  iVar23 = 0;
  iVar17 = 0;
  local_12c = (int *)0xfff;
  piVar26 = (int *)0x0;
  iVar4 = 0;
  iVar16 = adr_block_y_24;
  ppiVar6 = (int **)&block_mean_y;
  while( true ) {
    piVar32 = (int *)(iVar16 / iVar13);
    if ((int)piVar26 < (int)piVar32) {
      iVar17 = iVar4;
    }
    if ((int)piVar32 < (int)local_12c) {
      iVar23 = iVar4;
    }
    iVar4 = iVar4 + 1;
    *ppiVar6 = piVar32;
    if ((int)piVar26 < (int)piVar32) {
      piVar26 = piVar32;
    }
    if ((int)piVar32 < (int)local_12c) {
      local_12c = piVar32;
    }
    if (iVar4 == 0x18) break;
    iVar16 = *piVar18;
    piVar18 = piVar18 + 1;
    ppiVar6 = ppiVar6 + 1;
  }
  local_130 = local_174 + 9;
  local_128[0xc] = iVar17 + (int)piVar26 * 1000;
  local_128[0xd] = iVar23 + (int)local_12c * 1000;
  iVar23 = 0;
  iVar16 = 0;
  ppiVar6 = local_428;
  while( true ) {
    subsection(&local_204,iVar23,psVar14,psVar1,&adr_prod,8,10,0x10,iVar31);
    *ppiVar6 = local_204;
    ppiVar6[1] = local_200;
    ppiVar6[2] = local_1fc;
    ppiVar6[3] = local_1f8;
    ppiVar6[4] = local_1f4;
    ppiVar6[5] = local_1f0;
    ppiVar6[6] = local_1ec;
    ppiVar6[7] = local_1e8;
    ppiVar6[8] = local_1e4;
    iVar23 = (int)local_11c;
    piVar26 = local_12c;
    if (iVar16 + 4 == 0x20) break;
    iVar23 = *(int *)((int)local_14c + iVar16);
    iVar16 = iVar16 + 4;
    ppiVar6 = ppiVar6 + 9;
  }
  if (local_118 == (int *)0x1) {
    subsection_up(auStack_24c,(int)local_2b8,&adr_prod,8);
    subsection_light((int)auStack_24c,(int)local_2dc,(int)local_b8 * 10,local_270);
    uVar3 = local_d4;
    ppiVar6 = local_dc;
    iVar16 = 0;
    do {
      puVar2 = (undefined4 *)((int)local_270 + iVar16);
      puVar12 = (undefined4 *)((int)local_174 + iVar16);
      iVar16 = iVar16 + 4;
      *puVar12 = *puVar2;
    } while (iVar16 != 0x24);
    if ((int)local_174[0] < 1) {
      local_174[0] = (int *)0x0;
    }
    piVar18 = local_174[0];
    ppiVar7 = local_174;
    piVar32 = local_174[0];
    while( true ) {
      ppiVar7 = ppiVar7 + 1;
      if ((int)*ppiVar7 <= (int)piVar32) {
        *ppiVar7 = (int *)((int)piVar32 + 1);
      }
      if (ppiVar7 == local_174 + 8) break;
      piVar32 = *ppiVar7;
    }
    local_114 = *local_e0;
    local_12c = local_e0[1];
    local_11c = local_174[1];
    iVar16 = (int)local_174[1] - (int)local_174[0];
    local_f4 = local_e0[8];
    local_118 = local_174[2];
    local_10c = local_174[3];
    local_100 = local_174[4];
    local_fc = local_174[8];
    local_120 = local_12c;
    if ((int)local_12c - (int)local_114 < iVar16) {
      local_120 = (int *)((int)local_114 + iVar16);
    }
    local_12c = (int *)(((int)local_e0[2] + (int)local_120) - (int)local_12c);
    iVar31 = (int)local_174[2] - (int)local_174[1];
    iVar17 = (int)local_12c - (int)local_120;
    if (iVar17 < iVar31) {
      local_12c = (int *)(iVar31 + (int)local_120);
      iVar17 = (int)local_12c - (int)local_120;
    }
    iVar11 = (int)local_e0[3] + ((int)local_12c - (int)local_e0[2]);
    iVar4 = iVar11 - (int)local_12c;
    iVar13 = (int)local_174[3] - (int)local_174[2];
    if (iVar4 < iVar13) {
      iVar11 = iVar13 + (int)local_12c;
      iVar4 = iVar11 - (int)local_12c;
    }
    iVar29 = (int)local_e0[4] + (iVar11 - (int)local_e0[3]);
    iVar9 = (int)local_174[4] - (int)local_174[3];
    if (iVar29 - iVar11 < iVar9) {
      iVar29 = iVar9 + iVar11;
    }
    if (0xffe < iVar29) {
      iVar29 = 0xfff;
    }
    local_8c = iVar9 * 0x400;
    local_f0 = (int *)((int)local_114 << 10);
    local_110 = (int)local_174[0] << 10;
    local_e8 = ((int)local_120 - (int)local_114) * 0x400;
    local_b8 = (int *)(iVar16 * 0x400);
    local_b0 = iVar17 << 10;
    local_ac = (int **)(iVar31 * 0x400);
    local_a0 = iVar4 << 10;
    local_9c = iVar13 * 0x400;
    local_94 = (int **)((iVar29 - iVar11) * 0x400);
    local_88 = ((int)local_f4 - iVar29) * 0x400;
    local_84 = ((int)local_174[8] - (int)local_174[4]) * 0x400;
    local_dc = (int **)piVar26;
    iVar16 = 0;
    do {
      while (iVar31 = *(int *)(uVar3 + iVar16), (int)piVar18 <= iVar31) {
        if (iVar31 < (int)local_11c) {
          local_30 = (short *)((int)local_11c - iVar31);
          uVar10 = fix_point_div_32(10,local_e8,(uint)local_b8);
          iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
          *ppiVar6 = (int *)((int)local_120 - (iVar31 + 0x200 >> 10));
        }
        else if (iVar31 < (int)local_118) {
          local_30 = (short *)((int)local_118 - iVar31);
          uVar10 = fix_point_div_32(10,local_b0,(uint)local_ac);
          iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
          *ppiVar6 = (int *)((int)local_12c - (iVar31 + 0x200 >> 10));
        }
        else if (iVar31 < (int)local_10c) {
          local_30 = (short *)((int)local_10c - iVar31);
          uVar10 = fix_point_div_32(10,local_a0,local_9c);
          iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
          *ppiVar6 = (int *)(iVar11 - (iVar31 + 0x200 >> 10));
        }
        else if (iVar31 < (int)local_100) {
          local_30 = (short *)((int)local_100 - iVar31);
          uVar10 = fix_point_div_32(10,(uint)local_94,local_8c);
          iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
          *ppiVar6 = (int *)(iVar29 - (iVar31 + 0x200 >> 10));
        }
        else if (iVar31 < (int)local_fc) {
          local_30 = (short *)((int)local_fc - iVar31);
          uVar10 = fix_point_div_32(10,local_88,local_84);
          iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
          *ppiVar6 = (int *)((int)local_f4 - (iVar31 + 0x200 >> 10));
        }
        else {
          *ppiVar6 = local_f4;
        }
        iVar16 = iVar16 + 4;
        ppiVar6 = ppiVar6 + 1;
        if (iVar16 == 0x2c) goto LAB_0002e794;
      }
      local_30 = (short *)((int)piVar18 - iVar31);
      uVar10 = fix_point_div_32(10,(uint)local_f0,local_110);
      iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
      iVar16 = iVar16 + 4;
      *ppiVar6 = (int *)((int)local_114 - (iVar31 + 0x200 >> 10));
      ppiVar6 = ppiVar6 + 1;
    } while (iVar16 != 0x2c);
LAB_0002e794:
    piVar18 = (int *)local_dc;
    subsection_light((int)auStack_24c,(int)local_2dc,0,local_294);
    piVar26 = local_104;
    local_ac = &local_1bc;
    iVar16 = 0;
    do {
      puVar2 = (undefined4 *)((int)local_294 + iVar16);
      puVar21 = (undefined4 *)((int)local_198 + iVar16);
      puVar12 = (undefined4 *)((int)&local_1bc + iVar16);
      iVar16 = iVar16 + 4;
      *puVar21 = *puVar2;
      *puVar12 = *puVar2;
    } while (iVar16 != 0x24);
    iVar16 = 0;
    piVar32 = (int *)local_108;
    do {
      *piVar32 = *(int *)((int)piVar26 + iVar16);
      iVar31 = *(int *)(local_124 + iVar16);
      if (iVar31 < (int)local_1bc) {
        *piVar32 = *piVar26;
      }
      else if (iVar31 < local_1b8) {
        iVar17 = piVar26[1] - *piVar26;
        iVar31 = local_1b8 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(*piVar26 - piVar26[1]) * 0x400,
                                   (local_1b8 - (int)local_1bc) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[1] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1b8 - (int)local_1bc) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[1] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1b4) {
        iVar17 = piVar26[2] - piVar26[1];
        iVar31 = local_1b4 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[1] - piVar26[2]) * 0x400,
                                   (local_1b4 - local_1b8) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[2] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1b4 - local_1b8) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[2] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1b0) {
        iVar17 = piVar26[3] - piVar26[2];
        iVar31 = local_1b0 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[2] - piVar26[3]) * 0x400,
                                   (local_1b0 - local_1b4) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[3] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1b0 - local_1b4) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[3] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1ac) {
        iVar17 = piVar26[4] - piVar26[3];
        iVar31 = local_1ac - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[3] - piVar26[4]) * 0x400,
                                   (local_1ac - local_1b0) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[4] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1ac - local_1b0) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[4] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1a8) {
        iVar17 = piVar26[5] - piVar26[4];
        iVar31 = local_1a8 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[4] - piVar26[5]) * 0x400,
                                   (local_1a8 - local_1ac) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[5] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1a8 - local_1ac) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[5] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1a4) {
        iVar17 = piVar26[6] - piVar26[5];
        iVar31 = local_1a4 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[5] - piVar26[6]) * 0x400,
                                   (local_1a4 - local_1a8) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[6] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1a4 - local_1a8) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[6] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < local_1a0) {
        iVar17 = piVar26[7] - piVar26[6];
        iVar31 = local_1a0 - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[6] - piVar26[7]) * 0x400,
                                   (local_1a0 - local_1a4) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[7] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,(local_1a0 - local_1a4) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[7] - (iVar31 + 0x200 >> 10);
        }
      }
      else if (iVar31 < (int)local_19c) {
        iVar17 = piVar26[8] - piVar26[7];
        iVar31 = (int)local_19c - iVar31;
        if (iVar17 < 0) {
          uVar3 = fix_point_div_32(10,(piVar26[7] - piVar26[8]) * 0x400,
                                   ((int)local_19c - local_1a0) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[8] + (iVar31 + 0x200 >> 10);
        }
        else {
          uVar3 = fix_point_div_32(10,iVar17 * 0x400,((int)local_19c - local_1a0) * 0x400);
          iVar31 = fix_point_mult2_32(10,uVar3,iVar31 * 0x400);
          *piVar32 = piVar26[8] - (iVar31 + 0x200 >> 10);
        }
      }
      else {
        *piVar32 = piVar26[8];
      }
      iVar16 = iVar16 + 4;
      piVar32 = piVar32 + 1;
    } while (iVar16 != 0x24);
  }
  else {
    puVar19 = local_14c;
    iVar16 = 0;
    uVar3 = 0;
    iVar31 = 0;
LAB_0002ca00:
    if (local_120 == (int *)uVar3) {
      iVar31 = 0;
      do {
        iVar17 = iVar31 + iVar16 * 4;
        puVar2 = (undefined4 *)((int)local_174 + iVar31);
        iVar31 = iVar31 + 4;
        *puVar2 = *(undefined4 *)((int)local_428 + iVar17);
      } while (iVar31 != 0x24);
    }
    else if ((int)local_120 < (int)uVar3) {
      if (iVar31 == 0) {
        iVar31 = 0;
        do {
          iVar17 = iVar31 + iVar16 * 4;
          puVar2 = (undefined4 *)((int)local_174 + iVar31);
          iVar31 = iVar31 + 4;
          *puVar2 = *(undefined4 *)((int)local_428 + iVar17);
        } while (iVar31 != 0x24);
      }
      else {
        piVar18 = local_428[iVar16 + -8];
        piVar32 = local_428[iVar16 + 1];
        iVar17 = uVar3 - local_14c[iVar31 + -2];
        iVar31 = (int)local_120 - local_14c[iVar31 + -2];
        if ((int)piVar18 < (int)piVar32) {
          local_12c = (int *)((iVar31 * ((int)piVar32 - (int)piVar18) * 0x400) / iVar17);
          iVar13 = (int)local_12c + (int)piVar18 * 0x400;
        }
        else {
          local_12c = (int *)((iVar31 * ((int)piVar18 - (int)piVar32) * 0x400) / iVar17);
          iVar13 = (int)piVar18 * 0x400 - (int)local_12c;
        }
        piVar18 = local_428[iVar16 + -7];
        piVar32 = local_428[iVar16 + 2];
        iVar4 = iVar13 + 0x200;
        if (iVar13 + 0x200 < 0) {
          iVar4 = iVar13 + 0x5ff;
        }
        local_174[1] = (int *)(iVar4 >> 10);
        if ((int)piVar18 < (int)piVar32) {
          iVar13 = (iVar31 * ((int)piVar32 - (int)piVar18) * 0x400) / iVar17 + (int)piVar18 * 0x400;
        }
        else {
          iVar13 = (int)piVar18 * 0x400 - (iVar31 * ((int)piVar18 - (int)piVar32) * 0x400) / iVar17;
        }
        piVar32 = local_428[iVar16 + 3];
        piVar18 = local_428[iVar16 + -6];
        iVar4 = iVar13 + 0x200;
        if (iVar13 + 0x200 < 0) {
          iVar4 = iVar13 + 0x5ff;
        }
        local_174[2] = (int *)(iVar4 >> 10);
        if ((int)piVar18 < (int)piVar32) {
          local_12c = (int *)((iVar31 * ((int)piVar32 - (int)piVar18) * 0x400) / iVar17);
          iVar13 = (int)local_12c + (int)piVar18 * 0x400;
        }
        else {
          local_12c = (int *)((iVar31 * ((int)piVar18 - (int)piVar32) * 0x400) / iVar17);
          iVar13 = (int)piVar18 * 0x400 - (int)local_12c;
        }
        piVar18 = local_428[iVar16 + -5];
        piVar32 = local_428[iVar16 + 4];
        iVar16 = iVar13 + 0x200;
        if (iVar13 + 0x200 < 0) {
          iVar16 = iVar13 + 0x5ff;
        }
        local_174[3] = (int *)(iVar16 >> 10);
        if ((int)piVar18 < (int)piVar32) {
          iVar16 = (iVar31 * ((int)piVar32 - (int)piVar18) * 0x400) / iVar17 + (int)piVar18 * 0x400;
        }
        else {
          iVar16 = (int)piVar18 * 0x400 - (iVar31 * ((int)piVar18 - (int)piVar32) * 0x400) / iVar17;
        }
        iVar31 = iVar16 + 0x200;
        if (iVar16 + 0x200 < 0) {
          iVar31 = iVar16 + 0x5ff;
        }
        local_174[4] = (int *)(iVar31 >> 10);
      }
    }
    else {
      iVar16 = iVar16 + 9;
      iVar31 = iVar31 + 1;
      if (iVar16 != 0x48) goto LAB_0002c9f8;
      iVar16 = 0;
      do {
        iVar31 = iVar16 + 4;
        puVar2 = (undefined4 *)((int)local_174 + iVar16);
        iVar16 = iVar16 + 4;
        *puVar2 = *(undefined4 *)((int)aiStack_30c + iVar31);
      } while (iVar16 != 0x24);
    }
    if ((int)local_174[0] < 1) {
      local_174[0] = (int *)0x0;
    }
    piVar18 = local_174[0];
    ppiVar6 = local_174 + 1;
    piVar32 = local_174[0];
    piVar30 = local_174[1];
    while( true ) {
      if ((int)piVar30 <= (int)piVar32) {
        *ppiVar6 = (int *)((int)piVar32 + 1);
      }
      uVar3 = local_d4;
      ppiVar7 = local_dc;
      piVar30 = local_174[2];
      piVar32 = local_174[1];
      ppiVar5 = ppiVar6 + 1;
      if (ppiVar5 == local_130) break;
      piVar30 = *ppiVar5;
      piVar32 = *ppiVar6;
      ppiVar6 = ppiVar5;
    }
    local_11c = *local_e0;
    local_118 = local_e0[1];
    iVar16 = (int)local_174[1] - (int)local_174[0];
    local_12c = local_174[3];
    local_114 = local_174[4];
    local_100 = local_174[8];
    local_f0 = local_e0[8];
    if ((int)local_118 - (int)local_11c < iVar16) {
      local_10c = (int *)((int)local_11c + iVar16);
    }
    else {
      local_10c = local_118;
    }
    iVar31 = (int)local_174[2] - (int)local_174[1];
    local_118 = (int *)(((int)local_e0[2] + (int)local_10c) - (int)local_118);
    iVar17 = (int)local_118 - (int)local_10c;
    if (iVar17 < iVar31) {
      local_118 = (int *)(iVar31 + (int)local_10c);
      iVar17 = (int)(int *)(iVar31 + (int)local_10c) - (int)local_10c;
    }
    local_120 = (int *)((int)local_e0[3] + ((int)local_118 - (int)local_e0[2]));
    iVar4 = (int)local_120 - (int)local_118;
    iVar13 = (int)local_174[3] - (int)local_174[2];
    if (iVar4 < iVar13) {
      local_120 = (int *)(iVar13 + (int)local_118);
      iVar4 = (int)local_120 - (int)local_118;
    }
    local_84 = ((int)local_e0[4] + (int)local_120) - (int)local_e0[3];
    iVar11 = (int)local_174[4] - (int)local_174[3];
    if ((int)(local_84 - (int)local_120) < iVar11) {
      local_84 = iVar11 + (int)local_120;
    }
    if (0xffe < (int)local_84) {
      local_84 = 0xfff;
    }
    local_fc = (int *)((int)local_11c << 10);
    local_88 = iVar11 * 0x400;
    local_dc = (int **)piVar26;
    local_94 = (int **)iVar23;
    local_f4 = (int *)((int)local_174[0] << 10);
    local_110 = ((int)local_10c - (int)local_11c) * 0x400;
    local_e8 = iVar16 * 0x400;
    local_b0 = iVar17 << 10;
    local_ac = (int **)(iVar31 * 0x400);
    local_a0 = iVar4 << 10;
    local_9c = iVar13 * 0x400;
    local_8c = (local_84 - (int)local_120) * 0x400;
    local_70 = ((int)local_e0[8] - local_84) * 0x400;
    local_6c = ((int)local_174[8] - (int)local_174[4]) * 0x400;
    iVar16 = 0;
    do {
      while( true ) {
        iVar31 = *(int *)(uVar3 + iVar16);
        if ((int)piVar18 <= iVar31) break;
        uVar10 = fix_point_div_32(10,(uint)local_fc,(uint)local_f4);
        iVar31 = fix_point_mult2_32(10,uVar10,((int)piVar18 - iVar31) * 0x400);
        iVar16 = iVar16 + 4;
        *ppiVar7 = (int *)((int)local_11c - (iVar31 + 0x200 >> 10));
        ppiVar7 = ppiVar7 + 1;
        if (iVar16 == 0x2c) goto LAB_0002cce8;
      }
      if (iVar31 < (int)piVar32) {
        uVar10 = fix_point_div_32(10,local_110,local_e8);
        iVar31 = fix_point_mult2_32(10,uVar10,((int)piVar32 - iVar31) * 0x400);
        *ppiVar7 = (int *)((int)local_10c - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)piVar30) {
        local_30 = (short *)((int)piVar30 - iVar31);
        uVar10 = fix_point_div_32(10,local_b0,(uint)local_ac);
        iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
        *ppiVar7 = (int *)((int)local_118 - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_12c) {
        local_30 = (short *)((int)local_12c - iVar31);
        uVar10 = fix_point_div_32(10,local_a0,local_9c);
        iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
        *ppiVar7 = (int *)((int)local_120 - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_114) {
        local_30 = (short *)((int)local_114 - iVar31);
        uVar10 = fix_point_div_32(10,local_8c,local_88);
        iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
        *ppiVar7 = (int *)(local_84 - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_100) {
        local_30 = (short *)((int)local_100 - iVar31);
        uVar10 = fix_point_div_32(10,local_70,local_6c);
        iVar31 = fix_point_mult2_32(10,uVar10,(int)local_30 << 10);
        *ppiVar7 = (int *)((int)local_f0 - (iVar31 + 0x200 >> 10));
      }
      else {
        *ppiVar7 = local_f0;
      }
      iVar16 = iVar16 + 4;
      ppiVar7 = ppiVar7 + 1;
    } while (iVar16 != 0x2c);
LAB_0002cce8:
    iVar23 = (int)local_94;
    piVar26 = (int *)local_dc;
    ppiVar6 = local_174 + 9;
    iVar16 = 0;
    do {
      piVar18 = *ppiVar6;
      ppiVar6 = ppiVar6 + 1;
      if (piVar18 == local_b8) {
        iVar31 = iVar16 * 9;
        local_198[0] = local_428[iVar16 * 9];
        local_198[1] = local_428[iVar31 + 1];
        local_198[2] = local_428[iVar31 + 2];
        local_198[3] = local_428[iVar31 + 3];
        local_198[4] = local_428[iVar31 + 4];
        local_198[5] = local_428[iVar31 + 5];
        local_198[6] = local_428[iVar31 + 6];
        local_198[7] = local_428[iVar31 + 7];
        local_198[8] = local_428[iVar31 + 8];
        break;
      }
      if ((int)local_b8 < (int)piVar18) {
        if (iVar16 == 0) {
          local_198[0] = local_428[0];
          local_198[1] = local_428[1];
          local_198[2] = local_428[2];
          local_198[3] = local_428[3];
          local_198[4] = local_428[4];
          local_198[5] = local_428[5];
          local_198[6] = local_428[6];
          local_198[7] = local_428[7];
          local_198[8] = local_428[8];
        }
        else {
          iVar31 = iVar16 * 9;
          piVar32 = local_428[iVar31 + 1];
          piVar30 = local_428[iVar31 + -8];
          iVar17 = (int)local_b8 - local_14c[iVar16 + -2];
          uVar3 = ((int)piVar18 - local_14c[iVar16 + -2]) * 0x400;
          if ((int)piVar30 < (int)piVar32) {
            uVar10 = fix_point_div_32(10,((int)piVar32 - (int)piVar30) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
            local_198[1] = (int *)((int)piVar30 + (iVar16 + 0x200 >> 10));
          }
          else {
            uVar10 = fix_point_div_32(10,((int)piVar30 - (int)piVar32) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
            local_198[1] = (int *)((int)piVar30 - (iVar16 + 0x200 >> 10));
          }
          uVar10 = iVar17 * 0x400;
          piVar18 = local_428[iVar31 + 2];
          piVar32 = local_428[iVar31 + -7];
          if ((int)piVar32 < (int)piVar18) {
            uVar28 = fix_point_div_32(10,((int)piVar18 - (int)piVar32) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar28,uVar10);
            local_198[2] = (int *)((int)piVar32 + (iVar16 + 0x200 >> 10));
          }
          else {
            uVar28 = fix_point_div_32(10,((int)piVar32 - (int)piVar18) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar28,uVar10);
            local_198[2] = (int *)((int)piVar32 - (iVar16 + 0x200 >> 10));
          }
          piVar18 = local_428[iVar31 + 3];
          piVar32 = local_428[iVar31 + -6];
          if ((int)piVar32 < (int)piVar18) {
            uVar28 = fix_point_div_32(10,((int)piVar18 - (int)piVar32) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar28,uVar10);
            local_198[3] = (int *)((int)piVar32 + (iVar16 + 0x200 >> 10));
          }
          else {
            uVar28 = fix_point_div_32(10,((int)piVar32 - (int)piVar18) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar28,uVar10);
            local_198[3] = (int *)((int)piVar32 - (iVar16 + 0x200 >> 10));
          }
          piVar18 = local_428[iVar31 + 4];
          piVar32 = local_428[iVar31 + -5];
          if ((int)piVar32 < (int)piVar18) {
            uVar3 = fix_point_div_32(10,((int)piVar18 - (int)piVar32) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar3,uVar10);
            local_198[4] = (int *)((int)piVar32 + (iVar16 + 0x200 >> 10));
          }
          else {
            uVar3 = fix_point_div_32(10,((int)piVar32 - (int)piVar18) * 0x400,uVar3);
            iVar16 = fix_point_mult2_32(10,uVar3,uVar10);
            local_198[4] = (int *)((int)piVar32 - (iVar16 + 0x200 >> 10));
          }
        }
        break;
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 != 8);
    if ((int)local_198[1] < 2) {
      local_198[1] = (int *)0x1;
    }
    ppiVar7 = &local_1bc;
    local_ac = ppiVar7;
    iVar16 = 0;
    ppiVar6 = local_198;
    piVar18 = local_198[1];
    while( true ) {
      piVar32 = *ppiVar6;
      iVar16 = iVar16 + 1;
      if ((int)piVar18 <= (int)piVar32) {
        ppiVar6[1] = (int *)((int)piVar32 + 1);
      }
      *ppiVar7 = piVar32;
      piVar32 = local_104;
      ppiVar7 = ppiVar7 + 1;
      if (iVar16 == 8) break;
      piVar18 = ppiVar6[2];
      ppiVar6 = ppiVar6 + 1;
    }
    local_12c = piVar26;
    local_19c = local_198[8];
    iVar16 = 0;
    piVar26 = (int *)local_108;
    do {
      while( true ) {
        *piVar26 = *(int *)((int)piVar32 + iVar16);
        psVar14 = *(short **)(local_124 + iVar16);
        if ((int)local_1bc <= (int)psVar14) break;
        if (-1 < *piVar32) {
          local_30 = psVar14;
          uVar3 = fix_point_div_32(10,*piVar32 << 10,(int)local_1bc << 10);
          iVar31 = fix_point_mult2_32(10,uVar3,((int)local_1bc - (int)local_30) * 0x400);
          *piVar26 = *piVar32 - (iVar31 + 0x200 >> 10);
        }
LAB_0002cde8:
        iVar16 = iVar16 + 4;
        piVar26 = piVar26 + 1;
        piVar18 = local_12c;
        if (iVar16 == 0x20) goto LAB_0002ce88;
      }
      if (local_1b8 <= (int)psVar14) {
        if ((int)psVar14 < local_1b4) {
          iVar31 = piVar32[2] - piVar32[1];
          local_30 = (short *)(local_1b4 - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[1] - piVar32[2]) * 0x400,
                                     (local_1b4 - local_1b8) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
            *piVar26 = piVar32[2] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1b4 - local_1b8) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
            *piVar26 = piVar32[2] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < local_1b0) {
          iVar31 = piVar32[3] - piVar32[2];
          local_120 = (int *)(local_1b0 - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[2] - piVar32[3]) * 0x400,
                                     (local_1b0 - local_1b4) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[3] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1b0 - local_1b4) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[3] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < local_1ac) {
          iVar31 = piVar32[4] - piVar32[3];
          local_120 = (int *)(local_1ac - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[3] - piVar32[4]) * 0x400,
                                     (local_1ac - local_1b0) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[4] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1ac - local_1b0) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[4] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < local_1a8) {
          iVar31 = piVar32[5] - piVar32[4];
          local_120 = (int *)(local_1a8 - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[4] - piVar32[5]) * 0x400,
                                     (local_1a8 - local_1ac) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[5] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1a8 - local_1ac) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[5] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < local_1a4) {
          iVar31 = piVar32[6] - piVar32[5];
          local_120 = (int *)(local_1a4 - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[5] - piVar32[6]) * 0x400,
                                     (local_1a4 - local_1a8) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[6] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1a4 - local_1a8) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[6] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < local_1a0) {
          iVar31 = piVar32[7] - piVar32[6];
          local_120 = (int *)(local_1a0 - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[6] - piVar32[7]) * 0x400,
                                     (local_1a0 - local_1a4) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[7] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1a0 - local_1a4) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[7] - (iVar31 + 0x200 >> 10);
          }
        }
        else if ((int)psVar14 < (int)local_19c) {
          iVar31 = piVar32[8] - piVar32[7];
          local_120 = (int *)((int)local_19c - (int)psVar14);
          if (iVar31 < 0) {
            uVar3 = fix_point_div_32(10,(piVar32[7] - piVar32[8]) * 0x400,
                                     ((int)local_19c - local_1a0) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[8] + (iVar31 + 0x200 >> 10);
          }
          else {
            uVar3 = fix_point_div_32(10,iVar31 * 0x400,((int)local_19c - local_1a0) * 0x400);
            iVar31 = fix_point_mult2_32(10,uVar3,(int)local_120 << 10);
            *piVar26 = piVar32[8] - (iVar31 + 0x200 >> 10);
          }
        }
        else {
          *piVar26 = piVar32[8];
        }
        goto LAB_0002cde8;
      }
      iVar31 = piVar32[1] - *piVar32;
      local_30 = (short *)(local_1b8 - (int)psVar14);
      if (iVar31 < 0) {
        uVar3 = fix_point_div_32(10,(*piVar32 - piVar32[1]) * 0x400,
                                 (local_1b8 - (int)local_1bc) * 0x400);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *piVar26 = piVar32[1] + (iVar31 + 0x200 >> 10);
        goto LAB_0002cde8;
      }
      uVar3 = fix_point_div_32(10,iVar31 * 0x400,(local_1b8 - (int)local_1bc) * 0x400);
      iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
      iVar16 = iVar16 + 4;
      *piVar26 = piVar32[1] - (iVar31 + 0x200 >> 10);
      piVar26 = piVar26 + 1;
      piVar18 = local_12c;
    } while (iVar16 != 0x20);
  }
LAB_0002ce88:
  if (local_c0 != 0) {
    if (local_c0 == 1) {
      local_d8 = local_e4;
    }
    else if (local_c0 == 2) {
      local_d8 = local_4c;
    }
    else if (local_c0 == 3) {
      iVar16 = (0x100 - local_48) * local_e4 + local_4c * local_48;
      if (iVar16 < 0) {
        iVar16 = iVar16 + 0xff;
      }
      local_d8 = iVar16 >> 8;
    }
  }
  if (local_ec == 1) {
    uVar3 = local_64;
    if ((int)local_64 <= (int)local_d8) {
      uVar3 = local_d8;
    }
    local_d8 = local_60;
    if ((int)uVar3 <= (int)local_60) {
      local_d8 = uVar3;
    }
  }
  else if ((int)local_d8 < 0x14) {
    local_d8 = 0x14;
  }
  else if (4000 < (int)local_d8) {
    local_d8 = 4000;
  }
  uVar3 = local_68;
  if (local_bc != 0) {
    if (local_bc == 1) {
      uVar3 = (int)(local_d8 - (int)piVar18) / 2;
    }
    else {
      uVar3 = local_44;
      if ((local_bc != 2) && (uVar3 = local_68, local_bc == 3)) {
        iVar16 = (0x100 - local_40) * ((int)(local_d8 - (int)piVar18) / 2) + local_44 * local_40;
        if (iVar16 < 0) {
          iVar16 = iVar16 + 0xff;
        }
        uVar3 = iVar16 >> 8;
      }
    }
  }
  if (local_ec == 1) {
    if ((int)uVar3 < (int)local_5c) {
      uVar3 = local_5c;
    }
    if ((int)local_58 < (int)uVar3) {
      uVar3 = local_58;
    }
  }
  else if ((int)uVar3 < 0x14) {
    uVar3 = 0x14;
  }
  else if (600 < (int)uVar3) {
    uVar3 = 600;
  }
  uVar10 = local_7c;
  if (local_b4 != 0) {
    if (local_b4 == 1) {
      uVar10 = (int)(local_80 + 200) / 2;
    }
    else {
      uVar10 = local_80;
      if ((local_b4 != 2) && (uVar10 = local_7c, local_b4 == 3)) {
        iVar16 = (0x100 - local_3c) * ((int)(local_80 + 200) / 2) + local_7c * local_3c;
        if (iVar16 < 0) {
          iVar16 = iVar16 + 0xff;
        }
        uVar10 = iVar16 >> 8;
      }
    }
  }
  if (local_ec == 1) {
    if ((int)uVar10 < (int)local_54) {
      uVar10 = local_54;
    }
    if ((int)local_50 < (int)uVar10) {
      uVar10 = local_50;
    }
  }
  else if ((int)uVar10 < 0x14) {
    uVar10 = 0x14;
  }
  else if (600 < (int)uVar10) {
    uVar10 = 600;
  }
  local_a0 = uVar10 * uVar10 * 0x800;
  local_b0 = local_98 << 0x10;
  local_9c = uVar3 * uVar3 * 0x800;
  local_128[0xf] = local_d8;
  local_128[0x10] = uVar3;
  local_128[0x11] = uVar10;
  local_94 = local_90;
  local_108 = local_90;
LAB_0002cffc:
  iVar16 = *local_f8;
  if (iVar16 < 2) {
    iVar16 = 1;
    *local_f8 = 1;
  }
  if ((int)local_d8 < iVar16) {
    iVar31 = (iVar16 - local_d8) * (iVar16 - local_d8);
    iVar16 = 0x3ffffc;
    if (iVar31 < 0x3ffffd) {
      iVar16 = iVar31;
    }
    uVar3 = fix_point_div_32(10,iVar16 << 10,local_a0);
    uVar10 = fix_point_mult2_32(0x10,uVar3 << 6,local_a4);
    uVar3 = 0xeffff;
    if ((int)uVar10 < 0xf0000) {
      uVar3 = uVar10;
    }
    uVar3 = tisp_math_exp2(uVar3,0x10,0x10);
    uVar3 = fix_point_div_32(0x10,local_b0,uVar3);
    iVar16 = (int)uVar3 >> 0x10;
    if (10000 < (int)uVar3 >> 0x10) {
      iVar16 = 10000;
    }
  }
  else {
    iVar31 = (local_d8 - iVar16) * (local_d8 - iVar16);
    iVar16 = 0x3ffffc;
    if (iVar31 < 0x3ffffd) {
      iVar16 = iVar31;
    }
    uVar3 = fix_point_div_32(10,iVar16 << 10,local_9c);
    uVar10 = fix_point_mult2_32(0x10,uVar3 << 6,local_a4);
    uVar3 = 0xeffff;
    if ((int)uVar10 < 0xf0000) {
      uVar3 = uVar10;
    }
    uVar3 = tisp_math_exp2(uVar3,0x10,0x10);
    uVar3 = fix_point_div_32(0x10,local_b0,uVar3);
    iVar31 = local_98 + ((int)(local_b0 - uVar3) >> 0x10);
    iVar16 = 10000;
    if (iVar31 < 0x2711) {
      iVar16 = iVar31;
    }
  }
  uVar3 = fix_point_div_32(10,iVar16 << 10,0x19000);
  piVar26 = (int *)((int)(uVar3 + 0x200) >> 10);
  iVar16 = 0;
  ppiVar6 = local_174 + 9;
  while( true ) {
    piVar18 = *ppiVar6;
    ppiVar6 = ppiVar6 + 1;
    if (piVar18 == piVar26) {
      iVar31 = iVar16 * 9;
      local_1e0[0] = local_428[iVar16 * 9];
      local_1e0[1] = local_428[iVar31 + 1];
      local_1e0[2] = local_428[iVar31 + 2];
      local_1e0[3] = local_428[iVar31 + 3];
      local_1e0[4] = local_428[iVar31 + 4];
      local_1e0[5] = local_428[iVar31 + 5];
      local_1e0[6] = local_428[iVar31 + 6];
      local_1e0[7] = local_428[iVar31 + 7];
      local_1e0[8] = local_428[iVar31 + 8];
      goto LAB_0002d0fc;
    }
    if ((int)piVar26 < (int)piVar18) break;
    iVar16 = iVar16 + 1;
    if (iVar16 == 8) {
LAB_0002d0fc:
      ppiVar6 = local_ac;
      if ((int)local_1e0[0] < 2) {
        local_1e0[0] = (int *)0x1;
      }
      piVar26 = local_1e0[0];
      ppiVar7 = local_1e0 + 1;
      piVar18 = local_1e0[0];
      piVar32 = local_1e0[1];
      while( true ) {
        if ((int)piVar32 <= (int)piVar18) {
          *ppiVar7 = (int *)((int)piVar18 + 1);
        }
        piVar18 = local_1e0[1];
        ppiVar5 = ppiVar7 + 1;
        if (ppiVar6 == ppiVar5) break;
        piVar32 = *ppiVar5;
        piVar18 = *ppiVar7;
        ppiVar7 = ppiVar5;
      }
      local_120 = *local_e0;
      uVar10 = (int)local_1e0[1] - (int)local_1e0[0];
      uVar3 = local_d0;
      if ((int)local_d0 < (int)uVar10) {
        uVar3 = uVar10;
      }
      local_128 = (int *)(uVar3 + (int)local_120);
      uVar28 = (int)local_1e0[2] - (int)local_1e0[1];
      uVar3 = local_cc;
      if ((int)local_cc < (int)uVar28) {
        uVar3 = uVar28;
      }
      local_124 = uVar3 + (int)local_128;
      uVar15 = (int)local_1e0[3] - (int)local_1e0[2];
      local_12c = local_1e0[2];
      uVar3 = local_c8;
      if ((int)local_c8 < (int)uVar15) {
        uVar3 = uVar15;
      }
      local_11c = (int *)(uVar3 + local_124);
      uVar8 = (int)local_1e0[4] - (int)local_1e0[3];
      local_118 = local_1e0[3];
      local_114 = local_1e0[4];
      uVar3 = local_c4;
      if ((int)local_c4 < (int)uVar8) {
        uVar3 = uVar8;
      }
      local_10c = (int *)(uVar3 + (int)local_11c);
      local_f4 = local_e0[8];
      local_104 = local_1e0[8];
      local_f0 = (int *)(((int)local_128 - (int)local_120) * 0x400);
      local_bc = uVar8 * 0x400;
      iVar16 = 1;
      iVar31 = *local_a8;
      local_e4 = uVar28 * 0x400;
      local_dc = (int **)(uVar15 * 0x400);
      local_ec = uVar10 * 0x400;
      local_e8 = (local_124 - (int)local_128) * 0x400;
      local_d4 = ((int)local_11c - local_124) * 0x400;
      local_c0 = ((int)local_10c - (int)local_11c) * 0x400;
      local_b8 = (int *)(((int)local_e0[8] - (int)local_10c) * 0x400);
      local_b4 = ((int)local_1e0[8] - (int)local_1e0[4]) * 0x400;
      local_100 = (int *)((int)local_120 << 10);
      local_fc = (int *)((int)local_1e0[0] << 10);
      ppiVar6 = local_108;
      piVar32 = local_a8;
      if (iVar31 < (int)local_1e0[0]) goto LAB_0002d338;
LAB_0002d2bc:
      if (iVar31 < (int)piVar18) {
        local_30 = (short *)((int)piVar18 - iVar31);
        uVar3 = fix_point_div_32(10,(uint)local_f0,local_ec);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *ppiVar6 = (int *)((int)local_128 - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_12c) {
        local_30 = (short *)((int)local_12c - iVar31);
        uVar3 = fix_point_div_32(10,local_e8,local_e4);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *ppiVar6 = (int *)(local_124 - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_118) {
        local_30 = (short *)((int)local_118 - iVar31);
        uVar3 = fix_point_div_32(10,local_d4,(uint)local_dc);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *ppiVar6 = (int *)((int)local_11c - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_114) {
        local_30 = (short *)((int)local_114 - iVar31);
        uVar3 = fix_point_div_32(10,local_c0,local_bc);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *ppiVar6 = (int *)((int)local_10c - (iVar31 + 0x200 >> 10));
      }
      else if (iVar31 < (int)local_104) {
        local_30 = (short *)((int)local_104 - iVar31);
        uVar3 = fix_point_div_32(10,(uint)local_b8,local_b4);
        iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
        *ppiVar6 = (int *)((int)local_f4 - (iVar31 + 0x200 >> 10));
      }
      else {
        *ppiVar6 = local_f4;
      }
      if (iVar23 == 1) goto LAB_0002d37c;
joined_r0x0002d318:
      do {
        if (iVar16 == 0xb) {
          local_f8 = local_f8 + 1;
          local_108 = local_108 + 0xb;
          if (local_f8 == &s_in) {
            if ((local_78 == 1) && (iVar16 = (&adr_prod)[local_34], (int)local_74 <= iVar16)) {
              if ((int)local_38 < iVar16) {
                iVar16 = 0;
                do {
                  iVar31 = 0;
                  do {
                    puVar2 = (undefined4 *)((int)local_a8 + iVar31);
                    puVar12 = (undefined4 *)((int)local_94 + iVar31);
                    iVar31 = iVar31 + 4;
                    *puVar12 = *puVar2;
                  } while (iVar31 != 0x2c);
                  iVar16 = iVar16 + 1;
                  local_94 = local_94 + 0xb;
                } while (iVar16 != 0x18);
                return;
              }
              do {
                ppiVar7 = local_94 + 0xb;
                ppiVar6 = local_94;
                piVar26 = local_a8;
                do {
                  iVar31 = *piVar26;
                  local_94 = ppiVar6 + 1;
                  piVar26 = piVar26 + 1;
                  iVar31 = (int)*ppiVar6 * 0x400 -
                           (int)((iVar16 - local_74) * ((int)*ppiVar6 - iVar31) * 0x400) /
                           (int)(local_38 - local_74);
                  if (iVar31 < 0) {
                    iVar31 = iVar31 + 0x3ff;
                  }
                  *ppiVar6 = (int *)(iVar31 >> 10);
                  ppiVar6 = local_94;
                } while (local_94 != ppiVar7);
              } while (local_94 != local_90 + 0x108);
              return;
            }
            return;
          }
          goto LAB_0002cffc;
        }
        while( true ) {
          piVar32 = piVar32 + 1;
          iVar31 = *piVar32;
          iVar16 = iVar16 + 1;
          ppiVar6 = ppiVar6 + 1;
          if ((int)piVar26 <= iVar31) goto LAB_0002d2bc;
LAB_0002d338:
          local_30 = (short *)((int)piVar26 - iVar31);
          uVar3 = fix_point_div_32(10,(uint)local_100,(uint)local_fc);
          iVar31 = fix_point_mult2_32(10,uVar3,(int)local_30 << 10);
          *ppiVar6 = (int *)((int)local_120 - (iVar31 + 0x200 >> 10));
          if (iVar23 != 1) goto joined_r0x0002d318;
LAB_0002d37c:
          if (iVar16 != iVar23) break;
          iVar31 = *piVar32 * aiStack_30c[1];
          if (aiStack_30c[1] < ((int)*local_108 << 0x10) / *piVar32) {
            if (iVar31 < 0) {
              iVar31 = iVar31 + 0xffff;
            }
            *local_108 = (int *)(iVar31 >> 0x10);
          }
        }
        if (aiStack_30c[iVar16] <
            (((int)*ppiVar6 - (int)ppiVar6[-1]) * 0x10000) / (*piVar32 - piVar32[-1])) {
          iVar31 = (*piVar32 - piVar32[-1]) * aiStack_30c[iVar16] + (int)ppiVar6[-1] * 0x10000;
          if (iVar31 < 0) {
            iVar31 = iVar31 + 0xffff;
          }
          *ppiVar6 = (int *)(iVar31 >> 0x10);
        }
      } while( true );
    }
  }
  if (iVar16 == 0) {
    local_1e0[2] = local_428[2];
    local_1e0[3] = local_428[3];
    local_1e0[0] = local_428[0];
    local_1e0[4] = local_428[4];
    local_1e0[1] = local_428[1];
    local_1e0[5] = local_428[5];
    local_1e0[6] = local_428[6];
    local_1e0[7] = local_428[7];
    local_1e0[8] = local_428[8];
    goto LAB_0002d0fc;
  }
  iVar31 = iVar16 * 9;
  piVar32 = local_428[iVar31 + 1];
  piVar30 = local_428[iVar31 + -8];
  iVar17 = (int)piVar26 - local_14c[iVar16 + -2];
  uVar3 = ((int)piVar18 - local_14c[iVar16 + -2]) * 0x400;
  if ((int)piVar30 < (int)piVar32) {
    uVar10 = fix_point_div_32(10,((int)piVar32 - (int)piVar30) * 0x400,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[1] = (int *)((int)piVar30 + (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 2];
    piVar18 = local_428[iVar31 + -7];
    iVar16 = (int)piVar18 - (int)piVar26;
    if ((int)piVar18 < (int)piVar26) {
      iVar16 = (int)piVar26 - (int)piVar18;
      goto LAB_0002da54;
    }
LAB_0002dbc0:
    uVar10 = fix_point_div_32(10,iVar16 << 10,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[2] = (int *)((int)piVar18 - (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 3];
    piVar18 = local_428[iVar31 + -6];
    iVar16 = (int)piVar26 - (int)piVar18;
    if ((int)piVar26 <= (int)piVar18) {
      iVar16 = (int)piVar18 - (int)piVar26;
      goto LAB_0002dc24;
    }
LAB_0002dab8:
    uVar10 = fix_point_div_32(10,iVar16 << 10,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[3] = (int *)((int)piVar18 + (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 4];
    piVar18 = local_428[iVar31 + -5];
    if ((int)piVar26 <= (int)piVar18) {
LAB_0002dc80:
      uVar3 = fix_point_div_32(10,((int)piVar18 - (int)piVar26) * 0x400,uVar3);
      iVar16 = fix_point_mult2_32(10,uVar3,iVar17 * 0x400);
      local_1e0[4] = (int *)((int)piVar18 - (iVar16 + 0x200 >> 10));
      goto LAB_0002d0fc;
    }
  }
  else {
    uVar10 = fix_point_div_32(10,((int)piVar30 - (int)piVar32) * 0x400,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[1] = (int *)((int)piVar30 - (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 2];
    piVar18 = local_428[iVar31 + -7];
    iVar16 = (int)piVar26 - (int)piVar18;
    if ((int)piVar26 <= (int)piVar18) {
      iVar16 = (int)piVar18 - (int)piVar26;
      goto LAB_0002dbc0;
    }
LAB_0002da54:
    uVar10 = fix_point_div_32(10,iVar16 << 10,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[2] = (int *)((int)piVar18 + (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 3];
    piVar18 = local_428[iVar31 + -6];
    iVar16 = (int)piVar18 - (int)piVar26;
    if ((int)piVar18 < (int)piVar26) {
      iVar16 = (int)piVar26 - (int)piVar18;
      goto LAB_0002dab8;
    }
LAB_0002dc24:
    uVar10 = fix_point_div_32(10,iVar16 << 10,uVar3);
    iVar16 = fix_point_mult2_32(10,uVar10,iVar17 * 0x400);
    local_1e0[3] = (int *)((int)piVar18 - (iVar16 + 0x200 >> 10));
    piVar26 = local_428[iVar31 + 4];
    piVar18 = local_428[iVar31 + -5];
    if ((int)piVar26 <= (int)piVar18) goto LAB_0002dc80;
  }
  uVar3 = fix_point_div_32(10,((int)piVar26 - (int)piVar18) * 0x400,uVar3);
  iVar16 = fix_point_mult2_32(10,uVar3,iVar17 * 0x400);
  local_1e0[4] = (int *)((int)piVar18 + (iVar16 + 0x200 >> 10));
  goto LAB_0002d0fc;
LAB_0002c9f8:
  uVar3 = *puVar19;
  puVar19 = puVar19 + 1;
  goto LAB_0002ca00;
}



int interpolate_adr_x8_y12(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < param_4) {
    iVar2 = param_3 * 0x400 +
            ((param_5 - param_1) * (param_4 - param_3) * 0x400) / (param_2 - param_1);
    iVar1 = iVar2 + 0x200;
    if (iVar1 < 0) {
      iVar1 = iVar2 + 0x5ff;
    }
    return iVar1 >> 10;
  }
  iVar2 = param_3 * 0x400 -
          ((param_5 - param_1) * (param_3 - param_4) * 0x400) / (param_2 - param_1);
  iVar1 = iVar2 + 0x200;
  if (iVar1 < 0) {
    iVar1 = iVar2 + 0x5ff;
  }
  return iVar1 >> 10;
}



void cm_control(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_50 [4];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int iStack_2c;
  
  local_50[3] = 0x4c8b - ((uint)(param_2 * 0x4c8b) >> 8);
  local_50[1] = 0x9646 - ((uint)(param_2 * 0x9646) >> 8);
  local_50[2] = 0x1d2f - ((uint)(param_2 * 0x1d2f) >> 8);
  piVar6 = &cm_in;
  local_40 = ((uint)(param_2 * 0x69ba) >> 8) + 0x9646;
  local_3c = local_50[2];
  local_38 = local_50[3];
  local_50[0] = ((uint)(param_2 * 0xb375) >> 8) + 0x4c8b;
  local_34 = local_50[1];
  local_30 = ((uint)(param_2 * 0xe2d1) >> 8) + 0x1d2f;
  piVar2 = piVar6;
  do {
    while (-1 < *param_1) {
      *piVar2 = 1;
      piVar1 = piVar2 + 2;
      piVar2[1] = *param_1;
      param_1 = param_1 + 1;
      piVar2 = piVar1;
      if (piVar1 == &claHistR0) goto LAB_0002f6c0;
    }
    *piVar2 = -1;
    piVar1 = piVar2 + 2;
    piVar2[1] = -*param_1;
    param_1 = param_1 + 1;
    piVar2 = piVar1;
  } while (piVar1 != &claHistR0);
LAB_0002f6c0:
  puVar7 = &s_in;
  piVar2 = local_50;
  do {
    while( true ) {
      iVar5 = *piVar2;
      piVar2 = piVar2 + 1;
      if (-1 < iVar5) break;
      *puVar7 = 0xffffffff;
      puVar7[1] = -iVar5;
      puVar7 = puVar7 + 2;
      if (piVar2 == &iStack_2c) goto LAB_0002f71c;
    }
    *puVar7 = 1;
    puVar7[1] = iVar5;
    puVar7 = puVar7 + 2;
  } while (piVar2 != &iStack_2c);
LAB_0002f71c:
  do {
    iVar8 = *piVar6 * s_in;
    iVar5 = fix_point_mult2_32(0x10,piVar6[1] << 6,DAT_000b9cd4);
    iVar10 = piVar6[2] * DAT_000b9ce8;
    iVar3 = fix_point_mult2_32(0x10,piVar6[3] << 6,DAT_000b9cec);
    iVar9 = piVar6[4] * DAT_000b9d00;
    iVar4 = fix_point_mult2_32(0x10,piVar6[5] << 6,DAT_000b9d04);
    *param_3 = iVar9 * iVar4 + iVar10 * iVar3 + iVar8 * iVar5;
    iVar8 = *piVar6 * DAT_000b9cd8;
    iVar5 = fix_point_mult2_32(0x10,piVar6[1] << 6,DAT_000b9cdc);
    iVar10 = piVar6[2] * DAT_000b9cf0;
    iVar3 = fix_point_mult2_32(0x10,piVar6[3] << 6,DAT_000b9cf4);
    iVar9 = piVar6[4] * DAT_000b9d08;
    iVar4 = fix_point_mult2_32(0x10,piVar6[5] << 6,DAT_000b9d0c);
    param_3[1] = iVar9 * iVar4 + iVar10 * iVar3 + iVar8 * iVar5;
    iVar9 = *piVar6 * DAT_000b9ce0;
    iVar5 = fix_point_mult2_32(0x10,piVar6[1] << 6,DAT_000b9ce4);
    iVar11 = piVar6[2] * DAT_000b9cf8;
    iVar3 = fix_point_mult2_32(0x10,piVar6[3] << 6,DAT_000b9cfc);
    iVar10 = piVar6[4] * DAT_000b9d10;
    iVar4 = fix_point_mult2_32(0x10,piVar6[5] << 6,DAT_000b9d14);
    iVar8 = *param_3;
    param_3[2] = iVar10 * iVar4 + iVar11 * iVar3 + iVar9 * iVar5;
    if (iVar8 < 0) {
      *param_3 = -(-iVar8 >> 6);
    }
    else {
      *param_3 = iVar8 >> 6;
    }
    iVar5 = param_3[1];
    if (iVar5 < 0) {
      param_3[1] = -(-iVar5 >> 6);
    }
    else {
      param_3[1] = iVar5 >> 6;
    }
    iVar5 = param_3[2];
    if (iVar5 < 0) {
      param_3[2] = -(-iVar5 >> 6);
    }
    else {
      param_3[2] = iVar5 >> 6;
    }
    piVar6 = piVar6 + 6;
    param_3 = param_3 + 3;
  } while (piVar6 != &claHistR0);
  return;
}



int minFun(int param_1,int param_2)

{
  if (param_2 <= param_1) {
    param_1 = param_2;
  }
  return param_1;
}



int maxFun(int param_1,int param_2)

{
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  return param_1;
}



int Log2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 1;
  if (1 < param_1) {
    do {
      iVar1 = iVar2;
      if (iVar1 == 0xc) {
        return 0xb;
      }
      iVar3 = 1;
      iVar2 = 1;
      do {
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 << 1;
      } while (iVar1 + 1 != iVar2);
      iVar2 = iVar1 + 1;
    } while (iVar3 < param_1);
  }
  return iVar1;
}



int absFun(int param_1,int param_2)

{
  if (param_1 <= param_2) {
    return param_2 - param_1;
  }
  return param_1 - param_2;
}



int getVar(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = (int *)(param_1 + 4);
  iVar4 = 0xff;
  iVar6 = 0;
  iVar1 = 0;
  do {
    iVar4 = iVar4 + -1;
    if ((*piVar2 < 200) && (piVar2[1] < 200)) {
      iVar1 = iVar1 + 1;
      iVar6 = iVar6 + ((piVar2[1] - piVar2[-1]) + 1) / 2;
    }
    piVar2 = piVar2 + 1;
  } while (iVar4 != 0);
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else {
    piVar2 = (int *)(param_1 + 8);
    iVar4 = 0;
    iVar3 = 1;
    do {
      iVar3 = iVar3 + 1;
      iVar5 = (((*piVar2 - piVar2[-2]) + 1) / 2) * 10 - (iVar6 * 10 + iVar1 / 2) / iVar1;
      piVar2 = piVar2 + 1;
      iVar4 = iVar4 + iVar5 * iVar5;
    } while (iVar3 != iVar1 + 1);
  }
  return (iVar4 + iVar1 / 2) / iVar1;
}



void wdr_detail_para_rgb(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = *param_2 - param_2[2];
  iVar10 = *param_2 + param_2[1];
  iVar5 = param_2[3] - param_2[5];
  iVar8 = param_2[3] + param_2[4];
  if (iVar10 < iVar6) {
    iVar9 = 0;
    iVar11 = 0;
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    iVar9 = 0;
    iVar11 = 0;
    do {
      iVar2 = 0x1f;
      piVar1 = (int *)(param_3 + 4);
      do {
        if (iVar6 < iVar2) {
          iVar3 = (*piVar1 - piVar1[-1]) * (iVar2 - iVar6) * 0x1000;
          iVar2 = iVar3 + 8;
          if (iVar2 < 0) {
            iVar2 = iVar3 + 0x17;
          }
          iVar3 = *piVar1 * 0x1000 - (iVar2 >> 4);
          iVar2 = iVar3 + 0x800;
          if (iVar2 < 0) {
            iVar2 = iVar3 + 0x17ff;
          }
          iVar3 = iVar2 >> 0xc;
          break;
        }
        iVar2 = iVar2 + 0x10;
        piVar1 = piVar1 + 1;
        iVar3 = *(int *)(param_3 + 0x3fc);
      } while (iVar2 != 0x100f);
      iVar11 = iVar11 + iVar6;
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 1;
      iVar9 = iVar9 + iVar3;
    } while (iVar6 <= iVar10);
    iVar11 = iVar11 + iVar7 / 2;
    iVar9 = iVar9 + iVar7 / 2;
  }
  if (iVar8 < iVar5) {
    iVar10 = 0;
    iVar2 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    iVar10 = 0;
    iVar2 = 0;
    do {
      iVar3 = 0x1f;
      piVar1 = (int *)(param_3 + 4);
      do {
        if (iVar5 < iVar3) {
          iVar4 = (*piVar1 - piVar1[-1]) * (iVar3 - iVar5) * 0x1000;
          iVar3 = iVar4 + 8;
          if (iVar3 < 0) {
            iVar3 = iVar4 + 0x17;
          }
          iVar4 = *piVar1 * 0x1000 - (iVar3 >> 4);
          iVar3 = iVar4 + 0x800;
          if (iVar3 < 0) {
            iVar3 = iVar4 + 0x17ff;
          }
          iVar4 = iVar3 >> 0xc;
          break;
        }
        iVar3 = iVar3 + 0x10;
        piVar1 = piVar1 + 1;
        iVar4 = *(int *)(param_3 + 0x3fc);
      } while (iVar3 != 0x100f);
      iVar2 = iVar2 + iVar5;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + iVar4;
    } while (iVar5 <= iVar8);
    iVar2 = iVar2 + iVar6 / 2;
    iVar10 = iVar10 + iVar6 / 2;
  }
  *param_1 = iVar11 / iVar7;
  iVar5 = iVar2 / iVar6 - iVar11 / iVar7;
  param_1[1] = iVar9 / iVar7;
  param_1[2] = (iVar5 / 2 + (iVar10 / iVar6 - iVar9 / iVar7) * 0x1000) / iVar5;
  return;
}



void Tiziano_wdr_fpga(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                     int *param_7,int *param_8,int *param_9,int *param_10,int *param_11,
                     int *param_12,int param_13,int *param_14,int *param_15,int *param_16,
                     int *param_17,int *param_18,int *param_19,int *param_20,int *param_21,
                     int *param_22,int *param_23,int *param_24,int param_25,int param_26,
                     int *param_27,int *param_28,int *param_29,int *param_30)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int *piVar27;
  int local_1f8 [26];
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int *local_168;
  int local_164;
  int *local_160;
  undefined4 *local_15c;
  int *local_158;
  int *local_154;
  int local_150;
  undefined4 *local_14c;
  undefined4 *local_148;
  int local_144;
  int *local_140;
  int *local_13c;
  int *local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  int local_124;
  int *local_120;
  int *local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int *local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int *local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  uint local_b8;
  int local_b4;
  int *local_b0;
  int *local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  
  local_fc = param_12;
  local_13c = param_5;
  iVar18 = *param_16;
  local_140 = param_9;
  local_b0 = param_10;
  local_ac = param_11;
  local_d4 = param_13;
  local_11c = param_14;
  local_138 = param_15;
  local_134 = param_25;
  local_a8 = param_26;
  local_158 = param_27;
  local_154 = param_28;
  iVar25 = *param_1;
  local_e8 = param_29;
  local_160 = param_30;
  local_d0 = param_1[1];
  local_144 = *param_2;
  local_130 = param_2[1];
  local_e4 = param_2[2];
  local_e0 = param_2[3];
  local_164 = *param_3;
  local_a4 = param_3[1];
  local_a0 = param_3[2];
  local_9c = param_3[3];
  local_98 = param_1[2];
  local_150 = *param_8;
  local_118 = param_8[1];
  local_94 = param_8[2];
  local_80 = param_3[6];
  local_cc = param_2[4];
  local_90 = param_8[3];
  local_8c = param_8[4];
  local_88 = param_3[4];
  local_84 = param_3[5];
  local_114 = param_8[5];
  local_78 = param_6[2];
  local_7c = *param_6;
  local_110 = param_6[1];
  local_10c = param_6[3];
  local_74 = param_6[4];
  local_70 = param_6[5];
  local_6c = param_6[6];
  local_108 = param_6[7];
  local_68 = param_6[0xb];
  local_12c = param_6[0xd];
  local_64 = param_6[0xe];
  local_60 = param_6[0xf];
  local_5c = param_6[0x10];
  local_58 = param_6[0x11];
  local_54 = param_6[0x12];
  local_c8 = param_6[0x13];
  local_c0 = param_8[7];
  local_50 = param_8[8];
  local_104 = param_8[9];
  local_c4 = param_8[6];
  local_4c = param_8[10];
  local_100 = param_8[0xb];
  local_b8 = param_1[3];
  local_44 = param_8[0xe];
  local_bc = param_8[0xc];
  local_48 = param_8[0xd];
  local_ec = param_7[0xe];
  iVar26 = param_7[0xf];
  local_b4 = param_8[0xf];
  local_dc = param_8[0x10];
  iVar16 = *param_17;
  iVar14 = *param_18;
  iVar22 = *param_19;
  iVar21 = *param_20;
  iVar20 = *param_21;
  piVar27 = &claHistB1;
  piVar11 = &DAT_000ba964;
  piVar9 = &DAT_000ba564;
  piVar7 = &DAT_000ba164;
  piVar2 = &DAT_000b9d64;
  iVar13 = 0;
  claHistR0 = iVar18;
  claHistG0 = iVar16;
  claHistB0 = iVar14;
  claHistR1 = iVar22;
  claHistG1 = iVar21;
  claHistB1 = iVar20;
  while( true ) {
    iVar18 = *(int *)((int)param_16 + iVar13 + 4) + iVar18;
    *piVar2 = iVar18;
    iVar16 = *(int *)((int)param_17 + iVar13 + 4) + iVar16;
    *piVar7 = iVar16;
    iVar14 = *(int *)((int)param_18 + iVar13 + 4) + iVar14;
    *piVar9 = iVar14;
    iVar22 = *(int *)((int)param_19 + iVar13 + 4) + iVar22;
    *piVar11 = iVar22;
    *(int *)((int)&DAT_000bad64 + iVar13) = *(int *)((int)param_20 + iVar13 + 4) + iVar21;
    *(int *)((int)&DAT_000bb164 + iVar13) = *(int *)((int)param_21 + iVar13 + 4) + iVar20;
    iVar20 = claHistG1;
    if (iVar13 + 4 == 0x3fc) break;
    iVar21 = *(int *)((int)&DAT_000bad64 + iVar13);
    iVar20 = *(int *)((int)&DAT_000bb164 + iVar13);
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
    piVar11 = piVar11 + 1;
    iVar13 = iVar13 + 4;
  }
  local_d8 = claHistG1;
  local_40 = DAT_000bad64;
  local_3c = DAT_000bad68;
  local_38 = DAT_000bad6c;
  if (iVar25 != 0) {
    piVar7 = &tmpMapR_8bit;
    piVar2 = &tmpMapR;
    piVar11 = &claHistR1;
    piVar9 = &claHistR0;
    iVar22 = 0xf;
    iVar13 = 0;
    do {
      iVar16 = *piVar11;
      iVar14 = *piVar9;
      if (iVar14 < iVar16) {
        iVar14 = iVar16 - iVar14;
      }
      else {
        iVar14 = iVar14 - iVar16;
      }
      iVar13 = iVar13 + 1;
      *piVar7 = iVar13;
      *piVar2 = iVar22;
      piVar6 = &DAT_000b9d64;
      iVar21 = 0x1f;
      iVar18 = 2;
      do {
        iVar25 = *piVar6;
        if (iVar16 < iVar25) {
          iVar25 = iVar25 - iVar16;
        }
        else {
          iVar25 = iVar16 - iVar25;
        }
        if (iVar25 < iVar14) {
          if (iVar18 < iVar13) {
            *piVar7 = iVar13;
            iVar14 = iVar22;
          }
          else {
            *piVar7 = iVar18;
            iVar14 = iVar21;
          }
          *piVar2 = iVar14;
          iVar14 = iVar25;
        }
        iVar18 = iVar18 + 1;
        piVar6 = piVar6 + 1;
        iVar21 = iVar21 + 0x10;
      } while (iVar18 != 0x101);
      piVar11 = piVar11 + 1;
      piVar9 = piVar9 + 1;
      iVar22 = iVar22 + 0x10;
      piVar2 = piVar2 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar13 != 0x100);
    piVar2 = &tmpMapG_8bit;
    piVar9 = &claHistG0;
    piVar7 = &tmpMapG;
    piVar11 = &DAT_000bad64;
    iVar14 = 0xf;
    iVar22 = 0;
    iVar13 = claHistG0;
    if (iVar20 <= claHistG0) goto LAB_00030bb8;
    do {
      iVar13 = iVar20 - iVar13;
      while( true ) {
        iVar22 = iVar22 + 1;
        *piVar2 = iVar22;
        *piVar7 = iVar14;
        piVar6 = &DAT_000ba164;
        iVar18 = 0x1f;
        iVar16 = 2;
        do {
          iVar21 = *piVar6;
          if (iVar20 < iVar21) {
            iVar21 = iVar21 - iVar20;
          }
          else {
            iVar21 = iVar20 - iVar21;
          }
          if (iVar21 < iVar13) {
            if (iVar16 < iVar22) {
              *piVar2 = iVar22;
              iVar13 = iVar14;
            }
            else {
              *piVar2 = iVar16;
              iVar13 = iVar18;
            }
            *piVar7 = iVar13;
            iVar13 = iVar21;
          }
          iVar16 = iVar16 + 1;
          piVar6 = piVar6 + 1;
          iVar18 = iVar18 + 0x10;
        } while (iVar16 != 0x101);
        piVar9 = piVar9 + 1;
        iVar14 = iVar14 + 0x10;
        piVar7 = piVar7 + 1;
        piVar2 = piVar2 + 1;
        if (iVar22 == 0x100) {
          piVar9 = &claHistB0;
          piVar2 = &tmpMapB;
          piVar7 = &tmpMapB_8bit;
          iVar16 = 0xf;
          iVar14 = 0;
          iVar13 = claHistB1;
          iVar22 = claHistB0;
          if (claHistB1 <= claHistB0) goto LAB_00030cd0;
          goto LAB_00030c3c;
        }
        iVar20 = *piVar11;
        iVar13 = *piVar9;
        piVar11 = piVar11 + 1;
        if (iVar13 < iVar20) break;
LAB_00030bb8:
        iVar13 = iVar13 - iVar20;
      }
    } while( true );
  }
  piVar2 = &tmpMapR_8bit;
  piVar9 = &tmpMapR;
  piVar7 = &claHistR1;
  iVar13 = 0;
LAB_000300f0:
  do {
    iVar13 = iVar13 + 1;
    iVar14 = *piVar7;
    *piVar2 = iVar13;
    iVar22 = 1;
    piVar11 = &claHistR0;
    do {
      if ((*piVar11 < iVar14) && (iVar14 <= piVar11[1])) {
        *piVar2 = iVar22;
        if (iVar13 <= iVar22) {
          *piVar9 = iVar22 * 0x10 + -1;
          piVar2 = piVar2 + 1;
          piVar7 = piVar7 + 1;
          piVar9 = piVar9 + 1;
          goto LAB_000300f0;
        }
        *piVar2 = iVar13;
        break;
      }
      piVar11 = piVar11 + 1;
      iVar22 = iVar22 + 1;
    } while (piVar11 != (int *)0xba15c);
    *piVar9 = iVar13 * 0x10 + -1;
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  } while (iVar13 != 0x100);
  piVar2 = &tmpMapG_8bit;
  piVar7 = &tmpMapG;
  piVar9 = &DAT_000bad64;
  iVar13 = 0;
LAB_000301a8:
  iVar13 = iVar13 + 1;
  *piVar2 = iVar13;
  iVar22 = 1;
  piVar11 = &claHistG0;
  do {
    if ((*piVar11 < iVar20) && (iVar20 <= piVar11[1])) {
      *piVar2 = iVar22;
      if (iVar13 <= iVar22) {
        *piVar7 = iVar22 * 0x10 + -1;
        iVar20 = *piVar9;
        piVar2 = piVar2 + 1;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
        goto LAB_000301a8;
      }
      *piVar2 = iVar13;
      break;
    }
    piVar11 = piVar11 + 1;
    iVar22 = iVar22 + 1;
  } while (piVar11 != (int *)0xba55c);
  *piVar7 = iVar13 * 0x10 + -1;
  piVar2 = piVar2 + 1;
  piVar7 = piVar7 + 1;
  if (iVar13 != 0x100) {
    iVar20 = *piVar9;
    piVar9 = piVar9 + 1;
    goto LAB_000301a8;
  }
  piVar2 = &tmpMapB_8bit;
  piVar7 = &tmpMapB;
  iVar13 = 0;
LAB_00030258:
  do {
    iVar13 = iVar13 + 1;
    iVar14 = *piVar27;
    *piVar2 = iVar13;
    iVar22 = 1;
    piVar9 = &claHistB0;
    do {
      if ((*piVar9 < iVar14) && (iVar14 <= piVar9[1])) {
        *piVar2 = iVar22;
        if (iVar13 <= iVar22) {
          *piVar7 = iVar22 * 0x10 + -1;
          piVar2 = piVar2 + 1;
          piVar27 = piVar27 + 1;
          piVar7 = piVar7 + 1;
          goto LAB_00030258;
        }
        *piVar2 = iVar13;
        break;
      }
      piVar9 = piVar9 + 1;
      iVar22 = iVar22 + 1;
    } while (piVar9 != (int *)0xba95c);
    *piVar7 = iVar13 * 0x10 + -1;
    piVar2 = piVar2 + 1;
    piVar27 = piVar27 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar13 != 0x100);
LAB_000302c8:
  local_f0 = 0xc0000;
  local_f4 = 0xc0000;
  local_f8 = 0xc0000;
  local_124 = 0xc0000;
  local_128 = 0xc0000;
  local_148 = &tmpMapR_8bit;
  local_14c = &tmpMapG_8bit;
  local_15c = &tmpMapB_8bit;
  local_34 = (undefined4 *)0xc0000;
  local_120 = param_4;
  wdr_detail_para_rgb(&local_178,param_29,0xbb960);
  local_168 = &local_190;
  wdr_detail_para_rgb(&local_184,local_e8,local_124 + -0x3ea0);
  wdr_detail_para_rgb(&local_190,local_e8,local_128 + -0x36a0);
  *local_160 = local_178;
  local_160[1] = local_174;
  local_160[2] = local_170;
  local_160[3] = local_184;
  local_160[4] = local_180;
  local_160[5] = local_17c;
  local_160[6] = local_190;
  local_160[7] = local_18c;
  local_160[8] = local_188;
  iVar13 = 0;
  do {
    *(undefined4 *)((int)&mapR_before + iVar13) = *(undefined4 *)((int)param_22 + iVar13);
    puVar3 = (undefined4 *)((int)param_23 + iVar13);
    *(undefined4 *)((int)&mapG_before + iVar13) = *(undefined4 *)((int)param_24 + iVar13);
    puVar4 = (undefined4 *)((int)&mapB_before + iVar13);
    iVar13 = iVar13 + 4;
    *puVar4 = *puVar3;
  } while (iVar13 != 0x144);
  param_22[1] = *(int *)((int)local_34 + -0x46a0);
  param_24[1] = *(int *)(local_124 + -0x3ea0);
  piVar9 = param_22 + 2;
  param_23[1] = *(int *)(local_128 + -0x36a0);
  piVar7 = param_24 + 2;
  piVar2 = param_23 + 2;
  iVar16 = 0;
  iVar14 = 0;
  iVar22 = 0;
  iVar13 = 1;
LAB_00030438:
  do {
    if (iVar13 < 0x10) {
      *piVar9 = *(int *)((int)&DAT_000bb964 + iVar22);
      *piVar7 = *(int *)((int)&DAT_000bc164 + iVar22);
      *piVar2 = *(int *)((int)&DAT_000bc964 + iVar22);
    }
    else {
      if (7 < iVar13 - 0x10U) {
        iVar13 = iVar13 + 1;
        *piVar9 = *(int *)((int)&DAT_000bb87c + iVar16);
        iVar22 = iVar22 + 4;
        *piVar7 = *(int *)((int)&DAT_000bc07c + iVar16);
        piVar9 = piVar9 + 1;
        *piVar2 = *(int *)((int)&DAT_000bc87c + iVar16);
        piVar7 = piVar7 + 1;
        piVar2 = piVar2 + 1;
        iVar14 = iVar14 + 8;
        iVar16 = iVar16 + 0x10;
        if (iVar13 == 0x50) break;
        goto LAB_00030438;
      }
      *piVar9 = *(int *)((int)&DAT_000bb92c + iVar14);
      *piVar7 = *(int *)((int)&DAT_000bc12c + iVar14);
      *piVar2 = *(int *)((int)&DAT_000bc92c + iVar14);
    }
    iVar13 = iVar13 + 1;
    iVar22 = iVar22 + 4;
    piVar9 = piVar9 + 1;
    piVar7 = piVar7 + 1;
    piVar2 = piVar2 + 1;
    iVar14 = iVar14 + 8;
    iVar16 = iVar16 + 0x10;
  } while (iVar13 != 0x50);
  local_34 = &mapG_before;
  local_30 = &mapR_before;
  iVar13 = getVar(local_f0 + -0x4aa0);
  iVar22 = getVar(local_f4 + -0x42a0);
  iVar14 = getVar(local_f8 + -0x3aa0);
  iVar13 = (iVar13 + iVar22 + iVar14) / 3;
  if ((param_7[0xc] == 1) && (iVar22 = param_7[4], iVar22 <= iVar13)) {
    iVar14 = param_7[5];
    iVar16 = iVar14 - iVar22;
    if (iVar13 < iVar14) {
      local_160 = (int *)((iVar14 * iVar16 + (param_7[7] - param_7[6]) * (iVar13 - iVar22) +
                          iVar16 / 2) / iVar16);
    }
    else {
      local_160 = (int *)param_7[7];
    }
    iVar14 = 0x10 - (int)local_160;
    iVar22 = 0;
    piVar2 = param_22;
    piVar7 = param_23;
    piVar9 = param_24;
    do {
      piVar9 = piVar9 + 1;
      piVar7 = piVar7 + 1;
      piVar2 = piVar2 + 1;
      iVar16 = (int)local_160 * *(int *)((int)local_30 + iVar22 + 4) + iVar14 * *piVar2;
      iVar18 = iVar16 + 8;
      if (iVar18 < 0) {
        iVar18 = iVar16 + 0x17;
      }
      *piVar2 = iVar18 >> 4;
      iVar20 = iVar22 + 4;
      iVar16 = (int)local_160 * *(int *)((int)local_34 + iVar22 + 4) + iVar14 * *piVar9;
      iVar18 = iVar16 + 8;
      if (iVar18 < 0) {
        iVar18 = iVar16 + 0x17;
      }
      *piVar9 = iVar18 >> 4;
      iVar22 = (int)local_160 * *(int *)((int)&DAT_000bcfec + iVar22) + iVar14 * *piVar7;
      iVar16 = iVar22 + 8;
      if (iVar16 < 0) {
        iVar16 = iVar22 + 0x17;
      }
      *piVar7 = iVar16 >> 4;
      iVar22 = iVar20;
    } while (iVar20 != 0x140);
    iVar22 = param_7[0xd];
  }
  else {
    iVar22 = param_7[0xd];
    local_160 = (int *)0x0;
  }
  if (iVar22 == 1) {
    iVar22 = param_7[8];
    if (iVar22 <= iVar13) {
      local_ec = param_7[9] - iVar22;
      if (param_7[9] <= iVar13) {
        local_ec = param_7[0xb];
        param_7[0xe] = param_7[0xb];
        goto LAB_00030528;
      }
      local_ec = (param_7[10] * local_ec + (param_7[0xb] - param_7[10]) * (iVar13 - iVar22) +
                 local_ec / 2) / local_ec;
    }
    param_7[0xe] = local_ec;
  }
LAB_00030528:
  iVar13 = param_22[2] * -0xf + param_22[1] * 0x1f;
  iVar22 = iVar13 + 8;
  if (iVar22 < 0) {
    iVar22 = iVar13 + 0x17;
  }
  iVar22 = iVar22 >> 4;
  if (iVar22 < 0) {
    iVar22 = 0;
  }
  *param_22 = iVar22;
  iVar13 = param_24[2] * -0xf + param_24[1] * 0x1f;
  iVar22 = iVar13 + 8;
  if (iVar22 < 0) {
    iVar22 = iVar13 + 0x17;
  }
  iVar22 = iVar22 >> 4;
  if (iVar22 < 0) {
    iVar22 = 0;
  }
  *param_24 = iVar22;
  iVar13 = param_23[2] * -0xf + param_23[1] * 0x1f;
  iVar22 = iVar13 + 8;
  if (iVar22 < 0) {
    iVar22 = iVar13 + 0x17;
  }
  iVar22 = iVar22 >> 4;
  if (iVar22 < 0) {
    iVar22 = 0;
  }
  *param_23 = iVar22;
  if ((((1 < local_e4) && (iVar13 = local_148[1], iVar13 <= iVar26)) &&
      (iVar22 = local_14c[1], iVar22 <= iVar26)) && (iVar14 = local_15c[1], iVar14 <= iVar26)) {
    iVar20 = local_130 * 4;
    iVar16 = 0;
    iVar25 = 1;
    iVar21 = 0;
    iVar18 = 0;
LAB_00030668:
    iVar23 = iVar25 - local_130;
    if (iVar23 < 0) {
      iVar23 = 0;
    }
    iVar8 = iVar25 + local_130;
    iVar1 = 0;
    do {
      iVar5 = *(int *)((int)&DAT_000bb564 + iVar1 + iVar18 + iVar20);
      if (iVar5 <= iVar26) {
        iVar10 = *(int *)((int)&DAT_000bbd64 + iVar1 + iVar18 + iVar20);
        if ((iVar10 <= iVar26) &&
           (iVar15 = *(int *)((int)&DAT_000bc564 + iVar1 + iVar18 + iVar20), iVar15 <= iVar26))
        goto LAB_0003073c;
      }
      iVar8 = iVar8 + -1;
      iVar1 = iVar1 + -4;
    } while( true );
  }
  iVar21 = 0;
LAB_00030cf0:
  iVar22 = (local_a4 * 0x80 + local_164 / 2) / local_164;
  iVar13 = -4;
  if (local_a0 <= iVar22) {
    iVar13 = 4;
  }
  if (iVar22 < local_9c) {
    iVar21 = 2;
  }
  if ((param_7[0xc] == 1) && (8 < (int)local_160)) {
    iVar21 = 0;
  }
  iVar14 = local_120[1];
  if (iVar14 < local_164) {
    iVar16 = local_120[2];
    if (iVar16 < local_164) {
      if (local_64 < local_164) {
        iVar14 = local_5c;
        if (local_164 <= local_60) {
          iVar14 = local_68 * 4 * iVar22 +
                   (((local_164 - local_6c) + local_108 / 2) / local_108 + local_70) * 0x200;
        }
      }
      else {
        iVar14 = local_120[3] - iVar16;
        local_160 = (int *)((local_13c[2] * iVar14 +
                             (local_164 - iVar16) * (local_13c[3] - local_13c[2]) + iVar14 / 2) /
                           iVar14);
        iVar14 = iVar22 * 4 * local_74 + (int)local_160 * 0x200;
      }
    }
    else {
      iVar16 = iVar16 - iVar14;
      local_15c = (undefined4 *)
                  ((iVar22 * 4 * (local_78 * 0x10 + iVar14 * -3 + local_164) + local_10c / 2) /
                  local_10c);
      iVar16 = ((local_13c[1] * iVar16 + (local_164 - iVar14) * (local_13c[2] - local_13c[1]) +
                iVar16 / 2) / iVar16) * 0x2000 + (int)local_15c;
      iVar14 = iVar16 + 8;
      if (iVar14 < 0) {
        iVar14 = iVar16 + 0x17;
      }
      iVar14 = iVar14 >> 4;
    }
  }
  else {
    iVar14 = iVar14 - *local_120;
    local_15c = (undefined4 *)
                (((local_7c * 8 - local_164) * 4 * iVar22 + local_110 / 2) / local_110);
    iVar16 = ((*local_13c * iVar14 + (local_164 - *local_120) * (local_13c[1] - *local_13c) +
              iVar14 / 2) / iVar14) * 0x1000 + (int)local_15c;
    iVar14 = iVar16 + 4;
    if (iVar14 < 0) {
      iVar14 = iVar16 + 0xb;
    }
    iVar14 = iVar14 >> 3;
  }
  if (iVar22 < local_12c * 0x80) {
    iVar16 = local_12c * 0x80 - iVar22;
  }
  else {
    iVar16 = iVar22 + local_12c * -0x80;
  }
  if (1 < local_b8) {
    iVar13 = 0;
    do {
      while( true ) {
        iVar22 = *(int *)((int)local_158 + iVar13);
        if (iVar22 != 0) break;
        iVar13 = iVar13 + 4;
        *local_154 = 0x10000;
        local_154 = local_154 + 1;
        if (iVar13 == 0x6c) {
          return;
        }
      }
      iVar13 = iVar13 + 4;
      *local_154 = (local_118 * 0x4000 + iVar22 / 2) / iVar22;
      local_154 = local_154 + 1;
    } while (iVar13 != 0x6c);
    return;
  }
  piVar2 = (int *)(local_134 + 4);
  piVar7 = piVar2;
  piVar9 = local_1f8;
  do {
    piVar11 = local_168;
    piVar27 = piVar9 + 1;
    *piVar9 = *piVar7 - piVar7[-1];
    piVar7 = piVar7 + 1;
    piVar9 = piVar27;
  } while (piVar11 != piVar27);
  if (local_b8 == 1) {
    iVar18 = 0;
    do {
      puVar17 = (undefined4 *)((int)local_fc + iVar18);
      uVar12 = *(undefined4 *)((int)local_1f8 + iVar18);
      puVar19 = (undefined4 *)((int)local_140 + iVar18);
      puVar3 = (undefined4 *)((int)local_138 + iVar18);
      puVar4 = (undefined4 *)((int)local_11c + iVar18);
      iVar18 = iVar18 + 4;
      *puVar19 = uVar12;
      *puVar17 = uVar12;
      *puVar4 = uVar12;
      *puVar3 = uVar12;
    } while (iVar18 != 0x68);
    *local_11c = local_c4;
    local_11c[1] = local_c4;
    *local_138 = local_c0;
    local_138[1] = local_c0;
    if (2 < local_bc) {
      iVar18 = 0;
      do {
        iVar20 = iVar18 + 4;
        *(int *)((int)local_138 + iVar18 + 8) =
             (local_50 * *(int *)((int)local_1f8 + iVar18 + 8) + local_104 / 2) / local_104;
        iVar18 = iVar20;
      } while (iVar20 != (local_bc + -2) * 4);
    }
    iVar18 = 0;
    do {
      piVar7 = (int *)((int)local_1f8 + iVar18);
      piVar9 = (int *)(local_d4 + iVar18);
      iVar18 = iVar18 + 4;
      *piVar9 = (local_4c * *piVar7 + local_100 / 2) / local_100;
    } while (iVar18 != 0x68);
  }
  if (local_d0 == 1) {
    iVar18 = local_dc - local_b4;
    iVar20 = 0x1a;
    piVar7 = local_140;
    if (local_b4 >= local_164) goto LAB_00031870;
    do {
      if (local_dc < local_164) {
        *piVar7 = *local_ac;
      }
      else {
        *piVar7 = (*local_ac * iVar18 + (*local_ac - *local_b0) * (local_164 - local_dc) +
                  iVar18 / 2) / iVar18;
      }
      while( true ) {
        iVar20 = iVar20 + -1;
        local_b0 = local_b0 + 1;
        piVar7 = piVar7 + 1;
        local_ac = local_ac + 1;
        if (iVar20 == 0) goto LAB_00030f10;
        if (local_b4 < local_164) break;
LAB_00031870:
        *piVar7 = *local_b0;
      }
    } while( true );
  }
  iVar18 = 0;
  if (local_d0 == 2) {
    do {
      puVar3 = (undefined4 *)((int)local_fc + iVar18);
      puVar4 = (undefined4 *)((int)local_140 + iVar18);
      iVar18 = iVar18 + 4;
      *puVar4 = *puVar3;
    } while (iVar18 != 0x68);
  }
LAB_00030f10:
  local_38 = local_d8 + local_40 + local_3c + local_38;
  iVar18 = local_38 + 0x400;
  if (iVar18 < 0) {
    iVar18 = local_38 + 0xbff;
  }
  iVar14 = iVar14 + (iVar16 * iVar13 + local_12c / 2) / local_12c;
  iVar16 = param_7[1] - *param_7;
  iVar16 = (param_7[2] * iVar16 + ((iVar18 >> 0xb) - *param_7) * (param_7[3] - param_7[2]) +
           iVar16 / 2) / iVar16;
  iVar13 = iVar14 + 0x40;
  if (iVar13 < 0) {
    iVar13 = iVar14 + 0xbf;
  }
  iVar13 = iVar13 >> 7;
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  if (local_94 <= iVar13) {
    local_90 = local_8c;
  }
  if (local_84 < iVar22) {
    if (iVar22 <= local_80) {
      local_114 = local_114 + 1;
    }
  }
  else if (local_88 < iVar22) {
    local_114 = local_114 + 2;
  }
  if (local_98 == 0) {
    iVar22 = local_150;
    if (iVar16 <= local_150) {
      iVar22 = iVar16;
    }
    iVar14 = 0;
    piVar9 = local_140;
    piVar7 = local_158;
    do {
      piVar11 = piVar7 + 1;
      if (iVar14 < 2) {
        iVar18 = iVar22 * (iVar14 + -3) + iVar13;
        if (iVar18 < 0x4b1) {
          *piVar11 = iVar18;
          if (iVar18 < 0) {
            iVar18 = 0;
          }
        }
        else {
          iVar18 = 0x4b0;
        }
LAB_00031068:
        *piVar11 = iVar18;
      }
      else {
        if (1 < iVar14 - 2U) {
          iVar18 = *piVar7 + *piVar9;
          if (local_90 < *piVar7 + *piVar9) {
            iVar18 = local_90;
          }
          goto LAB_00031068;
        }
        iVar18 = *piVar7 + *piVar9;
        if (0x4b0 < iVar18) {
          iVar18 = 0x4b0;
        }
        *piVar11 = iVar18;
      }
      iVar14 = iVar14 + 1;
      piVar9 = piVar9 + 1;
      piVar7 = piVar11;
    } while (iVar14 != 0x1a);
  }
  else {
    iVar20 = (1 - local_114) * local_c8 + -1;
    iVar18 = 1;
    iVar14 = 0;
    piVar7 = local_158;
    iVar22 = local_150;
    if (iVar16 <= local_150) {
      iVar22 = iVar16;
    }
    do {
      piVar7 = piVar7 + 1;
      if (iVar14 < 2) {
        iVar25 = iVar22 * (iVar14 + -3) + iVar13;
        if (iVar25 < 0x4b1) {
          *piVar7 = iVar25;
          if (iVar25 < 0) {
            iVar25 = 0;
          }
          *piVar7 = iVar25;
        }
        else {
          *piVar7 = 0x4b0;
        }
      }
      else if (local_48 < iVar14) {
        if (local_44 < iVar14) {
          iVar25 = iVar20 * (iVar20 + 5) + iVar13;
          if (local_90 < iVar25) {
            iVar25 = local_90;
          }
          *piVar7 = iVar25;
        }
        else {
          iVar25 = iVar13 + local_54 + iVar18;
          if (local_90 <= iVar25) {
            iVar25 = local_90;
          }
          *piVar7 = iVar25;
        }
      }
      else {
        iVar25 = (iVar18 + local_58) * iVar14 + iVar13;
        if (0x4b0 < iVar25) {
          iVar25 = 0x4b0;
        }
        *piVar7 = iVar25;
      }
      iVar14 = iVar14 + 1;
      iVar18 = iVar18 + 1;
      iVar20 = iVar20 + local_c8;
    } while (iVar14 != 0x1a);
  }
  piVar7 = local_158 + 1;
  piVar9 = local_158 + 2;
  *local_140 = *piVar7;
  iVar22 = 0;
  do {
    iVar14 = iVar22 + 4;
    *(int *)((int)local_140 + iVar22 + 4) = *piVar9 - piVar9[-1];
    piVar9 = piVar9 + 1;
    iVar22 = iVar14;
  } while (iVar14 != 100);
  if (iVar21 == 0) {
    iVar14 = 4;
    iVar22 = 0;
    piVar9 = local_154;
    if (local_150 < iVar16) {
      iVar16 = local_150;
    }
    do {
      piVar9 = piVar9 + 1;
      if (iVar22 < 2) {
        iVar18 = iVar16 * (iVar22 + -3) + iVar13;
        if (iVar18 < 0x4b1) {
          *piVar7 = iVar18;
          if (iVar18 < 0) {
            iVar18 = 0;
          }
        }
        else {
          iVar18 = 0x4b0;
        }
      }
      else {
        iVar18 = piVar7[-1] + *(int *)((int)local_140 + iVar14 + -4);
        if (local_90 < iVar18) {
          iVar18 = local_90;
        }
      }
      *piVar7 = iVar18;
      if (iVar18 == 0) {
        *piVar9 = 0x10000;
      }
      else {
        *piVar9 = (local_118 * 0x4000 + iVar18 / 2) / iVar18;
      }
      iVar22 = iVar22 + 1;
      iVar14 = iVar14 + 4;
      piVar7 = piVar7 + 1;
    } while (iVar22 != 0x1a);
  }
  else if (iVar21 == 1) {
    piVar9 = local_138;
    if (local_144 < local_cc) {
      iVar22 = 0;
      local_cc = local_cc - local_e0;
      do {
        piVar9 = (int *)((int)local_11c + iVar22);
        piVar11 = (int *)((int)local_138 + iVar22);
        piVar27 = (int *)((int)local_fc + iVar22);
        iVar22 = iVar22 + 4;
        *piVar27 = (*piVar9 * local_cc + (*piVar11 - *piVar9) * (local_144 - local_e0) +
                   local_cc / 2) / local_cc;
        piVar9 = local_fc;
      } while (iVar22 != 0x68);
    }
    iVar22 = 1;
    iVar14 = 4;
    piVar11 = local_154;
    do {
      piVar11 = piVar11 + 1;
      if (iVar22 + -1 < 2) {
        iVar16 = iVar22 * *piVar9 + iVar13;
        if (0x4b0 < iVar16) {
          iVar16 = 0x4b0;
        }
        *piVar7 = iVar16;
        if (iVar16 != 0) goto LAB_000319e0;
LAB_00031988:
        *piVar11 = 0x10000;
      }
      else {
        iVar16 = piVar7[-1] + *piVar9;
        if (local_90 < piVar7[-1] + *piVar9) {
          iVar16 = local_90;
        }
        *piVar7 = iVar16;
        if (iVar16 == 0) goto LAB_00031988;
LAB_000319e0:
        *piVar11 = (local_118 * 0x4000 + iVar16 / 2) / iVar16;
      }
      iVar14 = iVar14 + 4;
      iVar22 = iVar22 + 1;
      piVar9 = piVar9 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar14 != 0x6c);
  }
  else {
    if (local_150 < iVar16) {
      iVar16 = local_150;
    }
    iVar14 = 4;
    iVar22 = 0;
    piVar9 = local_154 + 1;
    do {
      while( true ) {
        if (iVar22 < 2) {
          iVar18 = iVar16 * (iVar22 + -3) + iVar13;
          if (iVar18 < 0x4b1) {
            *piVar7 = iVar18;
            if (iVar18 < 0) {
              iVar18 = 0;
            }
          }
          else {
            iVar18 = 0x4b0;
          }
        }
        else {
          iVar18 = piVar7[-1] + *(int *)(local_d4 + iVar14 + -4);
          if (local_90 < iVar18) {
            iVar18 = local_90;
          }
        }
        *piVar7 = iVar18;
        if (iVar18 == 0) break;
        iVar22 = iVar22 + 1;
        iVar14 = iVar14 + 4;
        piVar7 = piVar7 + 1;
        *piVar9 = (local_118 * 0x4000 + iVar18 / 2) / iVar18;
        piVar9 = piVar9 + 1;
        if (iVar22 == 0x1a) goto LAB_00031174;
      }
      iVar22 = iVar22 + 1;
      *piVar9 = 0x10000;
      iVar14 = iVar14 + 4;
      piVar9 = piVar9 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar22 != 0x1a);
  }
LAB_00031174:
  iVar13 = 0;
  do {
    iVar14 = 0;
    iVar22 = 1;
    if (1 < *piVar2 - piVar2[-1]) {
      do {
        iVar14 = iVar22;
        if (iVar14 == 0xc) {
          *(undefined4 *)(local_a8 + iVar13) = 0xb;
          goto joined_r0x0003159c;
        }
        iVar22 = 1;
        iVar16 = 1;
        do {
          iVar22 = iVar22 + 1;
          iVar16 = iVar16 << 1;
        } while (iVar14 + 1 != iVar22);
        iVar22 = iVar14 + 1;
      } while (iVar16 < *piVar2 - piVar2[-1]);
    }
    *(int *)(local_a8 + iVar13) = iVar14;
joined_r0x0003159c:
    piVar2 = piVar2 + 1;
    iVar13 = iVar13 + 4;
    if (iVar13 == 0x68) {
      iVar13 = *(int *)(local_134 + 8) - *(int *)(local_134 + 4);
      iVar13 = ((local_158[1] * iVar13 - (local_158[2] - local_158[1]) * *(int *)(local_134 + 4)) +
               iVar13 / 2) / iVar13;
      iVar22 = local_154[1];
      iVar14 = local_154[2];
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      *local_158 = iVar13;
      iVar13 = *(int *)(local_134 + 8) - *(int *)(local_134 + 4);
      iVar13 = ((iVar13 * local_154[1] - (iVar14 - iVar22) * *(int *)(local_134 + 4)) + iVar13 / 2)
               / iVar13;
      if (0x10000 < iVar13) {
        iVar13 = 0x10000;
      }
      *local_154 = iVar13;
      return;
    }
  } while( true );
LAB_00030c3c:
  iVar22 = iVar13 - iVar22;
  while( true ) {
    iVar14 = iVar14 + 1;
    *piVar7 = iVar14;
    *piVar2 = iVar16;
    piVar11 = &DAT_000ba564;
    iVar20 = 0x1f;
    iVar18 = 2;
    do {
      iVar21 = *piVar11;
      if (iVar13 < iVar21) {
        iVar21 = iVar21 - iVar13;
      }
      else {
        iVar21 = iVar13 - iVar21;
      }
      if (iVar21 < iVar22) {
        if (iVar18 < iVar14) {
          *piVar7 = iVar14;
          iVar22 = iVar16;
        }
        else {
          *piVar7 = iVar18;
          iVar22 = iVar20;
        }
        *piVar2 = iVar22;
        iVar22 = iVar21;
      }
      iVar18 = iVar18 + 1;
      piVar11 = piVar11 + 1;
      iVar20 = iVar20 + 0x10;
    } while (iVar18 != 0x101);
    piVar27 = piVar27 + 1;
    piVar9 = piVar9 + 1;
    iVar16 = iVar16 + 0x10;
    piVar2 = piVar2 + 1;
    piVar7 = piVar7 + 1;
    if (iVar14 == 0x100) goto LAB_000302c8;
    iVar13 = *piVar27;
    iVar22 = *piVar9;
    if (iVar22 < iVar13) break;
LAB_00030cd0:
    iVar22 = iVar22 - iVar13;
  }
  goto LAB_00030c3c;
LAB_0003073c:
  iVar8 = iVar8 - iVar23;
  iVar24 = iVar25 - iVar23;
  iVar1 = iVar8 / 2;
  iVar5 = (local_148[iVar23] * iVar8 + iVar24 * (iVar5 - local_148[iVar23]) + iVar1) / iVar8;
  if (iVar13 < iVar5) {
    iVar5 = iVar5 - iVar13;
  }
  else {
    iVar5 = iVar13 - iVar5;
  }
  if (iVar16 <= iVar5) {
    iVar16 = iVar5;
  }
  if (local_e0 < iVar5) {
    iVar21 = 1;
  }
  iVar13 = (iVar1 + iVar8 * local_14c[iVar23] + iVar24 * (iVar10 - local_14c[iVar23])) / iVar8;
  if (iVar22 < iVar13) {
    iVar13 = iVar13 - iVar22;
  }
  else {
    iVar13 = iVar22 - iVar13;
  }
  if (local_e0 < iVar13) {
    iVar21 = 1;
  }
  iVar8 = (iVar1 + iVar8 * local_15c[iVar23] + iVar24 * (iVar15 - local_15c[iVar23])) / iVar8;
  if (iVar16 < iVar13) {
    iVar16 = iVar13;
  }
  if (iVar14 < iVar8) {
    iVar8 = iVar8 - iVar14;
  }
  else {
    iVar8 = iVar14 - iVar8;
  }
  if (iVar16 < iVar8) {
    iVar16 = iVar8;
  }
  iVar25 = iVar25 + 1;
  if (local_e0 < iVar8) {
    iVar21 = 1;
  }
  if (local_144 < iVar16) {
    local_144 = iVar16;
  }
  if (((iVar25 == local_e4) || (iVar13 = *(int *)((int)local_148 + iVar18 + 8), iVar26 < iVar13)) ||
     (iVar22 = *(int *)((int)local_14c + iVar18 + 8), iVar26 < iVar22)) goto LAB_00030884;
  iVar14 = *(int *)((int)local_15c + iVar18 + 8);
  iVar18 = iVar18 + 4;
  if (iVar26 < iVar14) goto LAB_00030884;
  goto LAB_00030668;
LAB_00030884:
  goto LAB_00030cf0;
}



undefined4 tiziano_gamma_lut_parameter(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0x40000;
  iVar3 = 2;
  do {
    iVar5 = iVar3 + -2;
    system_reg_write(iVar4,(uint)*(ushort *)(tiziano_gamma_lut_now + iVar5) |
                           (uint)*(ushort *)(tiziano_gamma_lut_now + iVar3) << 0xc);
    system_reg_write(iVar4 + 0x8000,
                     (uint)*(ushort *)(tiziano_gamma_lut_now + iVar5) |
                     (uint)*(ushort *)(tiziano_gamma_lut_now + iVar3) << 0xc);
    iVar2 = iVar4 + 0x10000;
    iVar4 = iVar4 + 4;
    puVar1 = (ushort *)(tiziano_gamma_lut_now + iVar3);
    iVar3 = iVar3 + 2;
    system_reg_write(iVar2,(uint)*(ushort *)(tiziano_gamma_lut_now + iVar5) | (uint)*puVar1 << 0xc);
  } while (iVar3 != 0x102);
  return 0;
}



undefined4 tiziano_gamma_params_refresh(void)

{
  memcpy(&tiziano_gamma_lut,&DAT_00098574,0x102);
  memcpy(tiziano_gamma_lut_wdr,&DAT_00098676,0x102);
  return 0;
}



undefined4 tisp_gamma_wdr_en(int param_1)

{
  undefined1 *puVar1;
  
  gamma_wdr_en = param_1;
  if (param_1 == 0) {
    puVar1 = (undefined1 *)&tiziano_gamma_lut;
  }
  else {
    puVar1 = tiziano_gamma_lut_wdr;
  }
  tiziano_gamma_lut_now = puVar1;
  return 0;
}



undefined4 tiziano_gamma_dn_params_refresh(void)

{
  tiziano_gamma_params_refresh();
  tiziano_gamma_lut_parameter();
  return 0;
}



undefined4 tiziano_gamma_init(void)

{
  undefined1 *puVar1;
  
  if (gamma_wdr_en == 0) {
    puVar1 = (undefined1 *)&tiziano_gamma_lut;
  }
  else {
    puVar1 = tiziano_gamma_lut_wdr;
  }
  tiziano_gamma_lut_now = puVar1;
  tiziano_gamma_params_refresh();
  tiziano_gamma_lut_parameter();
  return 0;
}



undefined4 tisp_gamma_param_array_get(int param_1,void *param_2,undefined4 *param_3)

{
  undefined1 *__src;
  
  if (param_1 == 0x3c) {
    __src = (undefined1 *)&tiziano_gamma_lut;
  }
  else {
    if (param_1 != 0x3d) {
      isp_printf();
      return 0xffffffff;
    }
    __src = tiziano_gamma_lut_wdr;
  }
  memcpy(param_2,__src,0x102);
  *param_3 = 0x102;
  return 0;
}



undefined4 tisp_gamma_param_array_set(int param_1,void *param_2,undefined4 *param_3)

{
  undefined1 *__dest;
  
  if (param_1 == 0x3c) {
    __dest = (undefined1 *)&tiziano_gamma_lut;
  }
  else {
    if (param_1 != 0x3d) {
      isp_printf();
      return 0xffffffff;
    }
    __dest = tiziano_gamma_lut_wdr;
  }
  *param_3 = 0x102;
  memcpy(__dest,param_2,0x102);
  tiziano_gamma_lut_parameter();
  tiziano_adr_gamma_refresh();
  tiziano_wdr_gamma_refresh();
  return 0;
}



void system_reg_write_gib(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    system_reg_write(0x1070,1);
  }
  system_reg_write(param_2,param_3);
  return;
}



undefined4 tisp_gib_gain_interpolation(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  uVar6 = param_1 >> 0x10;
  uVar5 = param_1 & 0xffff;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  uVar1 = tisp_simple_intp(uVar6,uVar5,0xab4dc);
  uVar2 = tisp_simple_intp(uVar6,uVar5,0xab4b8);
  uVar3 = tisp_simple_intp(uVar6,uVar5,0xab494);
  uVar4 = tisp_simple_intp(uVar6,uVar5,0xab470);
  uVar5 = tisp_simple_intp(uVar6,uVar5,0xab44c);
  uVar6 = system_reg_read(8);
  switch(uVar6 & 0x1f) {
  case 0:
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar3;
    local_34 = uVar4;
    local_30 = uVar5;
    break;
  case 1:
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar2;
    local_34 = uVar1;
    local_30 = uVar5;
    break;
  case 2:
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar4;
    local_34 = uVar3;
    local_30 = uVar5;
    break;
  case 3:
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar1;
    local_34 = uVar2;
    local_30 = uVar5;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  default:
    isp_printf();
    break;
  case 8:
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar5;
    local_34 = uVar4;
    local_30 = uVar3;
    break;
  case 9:
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar5;
    local_34 = uVar1;
    local_30 = uVar2;
    break;
  case 10:
    local_40 = uVar1;
    local_3c = uVar5;
    local_38 = uVar3;
    local_34 = uVar4;
    local_30 = uVar2;
    break;
  case 0xb:
    local_40 = uVar4;
    local_3c = uVar5;
    local_38 = uVar2;
    local_34 = uVar1;
    local_30 = uVar3;
    break;
  case 0xc:
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar4;
    local_34 = uVar5;
    local_30 = uVar3;
    break;
  case 0xd:
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar1;
    local_34 = uVar5;
    local_30 = uVar2;
    break;
  case 0xe:
    local_40 = uVar5;
    local_3c = uVar1;
    local_38 = uVar4;
    local_34 = uVar3;
    local_30 = uVar2;
    break;
  case 0xf:
    local_40 = uVar5;
    local_3c = uVar4;
    local_38 = uVar1;
    local_34 = uVar2;
    local_30 = uVar3;
    break;
  case 0x10:
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar3;
    local_34 = uVar5;
    local_30 = uVar4;
    break;
  case 0x11:
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar2;
    local_34 = uVar5;
    local_30 = uVar1;
    break;
  case 0x12:
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar5;
    local_34 = uVar3;
    local_30 = uVar4;
    break;
  case 0x13:
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar5;
    local_34 = uVar2;
    local_30 = uVar1;
    break;
  case 0x14:
    local_40 = uVar3;
    local_3c = uVar5;
    local_38 = uVar1;
    local_34 = uVar2;
    local_30 = uVar4;
    break;
  case 0x15:
    local_40 = uVar2;
    local_3c = uVar5;
    local_38 = uVar4;
    local_34 = uVar3;
    local_30 = uVar1;
    break;
  case 0x16:
    local_40 = uVar5;
    local_3c = uVar3;
    local_38 = uVar2;
    local_34 = uVar1;
    local_30 = uVar4;
    break;
  case 0x17:
    local_40 = uVar5;
    local_3c = uVar2;
    local_38 = uVar3;
    local_34 = uVar4;
    local_30 = uVar1;
  }
  system_reg_write_gib(1,0x1060,local_40);
  system_reg_write_gib(1,0x1064,local_38 << 0x10 | local_3c);
  system_reg_write_gib(1,0x1068,local_30 << 0x10 | local_34);
  tisp_gib_blc_ag = param_1;
  return 0;
}



undefined4 tiziano_gib_lut_parameter(void)

{
  system_reg_write(0x1038,DAT_000ab53c << 0x10 | DAT_000ab538);
  system_reg_write(0x103c,DAT_000ab520 << 0xe | DAT_000ab52c << 0x10 |
                          tiziano_gib_config_line << 0xc | DAT_000ab514 << 10 | DAT_000ab528 << 8 |
                          DAT_000ab534 << 4 | DAT_000ab530 << 2);
  system_reg_write_gib(1,0x106c,DAT_000ab51c << 0x10 | DAT_000ab518 << 3 | DAT_000ab524);
  tisp_gib_gain_interpolation(tisp_gib_blc_ag);
  if (init_37190 == 0) {
    system_reg_write_gib(1,0x1030,DAT_000ab50c << 0x10 | tiziano_gib_r_g_linear);
    system_reg_write_gib(1,0x1034,DAT_000ab504 << 0x10 | tiziano_gib_b_ir_linear);
    init_37190 = 1;
  }
  return 0;
}



undefined4 tiziano_gib_params_refresh(void)

{
  memcpy(&tiziano_gib_config_line,&DAT_00098778,0x30);
  memcpy(&tiziano_gib_r_g_linear,&DAT_000987a8,8);
  memcpy(&tiziano_gib_b_ir_linear,&DAT_000987b0,8);
  memcpy(tiziano_gib_deirm_blc_r_linear,&DAT_000987b8,0x24);
  memcpy(tiziano_gib_deirm_blc_gr_linear,&DAT_000987dc,0x24);
  memcpy(tiziano_gib_deirm_blc_gb_linear,&DAT_00098800,0x24);
  memcpy(tiziano_gib_deirm_blc_b_linear,&DAT_00098824,0x24);
  memcpy(tiziano_gib_deirm_blc_ir_linear,&DAT_00098848,0x24);
  memcpy(&gib_ir_point,&DAT_0009886c,0x10);
  memcpy(gib_ir_reser,&DAT_0009887c,0x3c);
  memcpy(tiziano_gib_deir_r_h,&DAT_000988b8,0x84);
  memcpy(tiziano_gib_deir_g_h,&DAT_0009893c,0x84);
  memcpy(tiziano_gib_deir_b_h,&DAT_000989c0,0x84);
  memcpy(tiziano_gib_deir_r_m,&DAT_00098a44,0x84);
  memcpy(tiziano_gib_deir_g_m,&DAT_00098ac8,0x84);
  memcpy(tiziano_gib_deir_b_m,&DAT_00098b4c,0x84);
  memcpy(tiziano_gib_deir_r_l,&DAT_00098bd0,0x84);
  memcpy(tiziano_gib_deir_g_l,&DAT_00098c54,0x84);
  memcpy(tiziano_gib_deir_b_l,&DAT_00098cd8,0x84);
  memcpy(tiziano_gib_deir_matrix_h,&DAT_00098d5c,0x3c);
  memcpy(tiziano_gib_deir_matrix_m,&DAT_00098d98,0x3c);
  memcpy(tiziano_gib_deir_matrix_l,&DAT_00098dd4,0x3c);
  return 0;
}



undefined4 tiziano_gib_dn_params_refresh(void)

{
  tiziano_gib_params_refresh();
  if (deir_en == 1) {
    DAT_000ab51c = (uint)(day_night == 0);
  }
  else {
    DAT_000ab51c = 0;
  }
  tiziano_gib_lut_parameter();
  return 0;
}



void tiziano_gib_deir_reg(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    system_reg_write(iVar3 + 0x80000,
                     ((uint *)(param_1 + iVar3))[1] << 0xc | *(uint *)(param_1 + iVar3));
    system_reg_write((int)("%s[%d] the type of sensor SBUS hasn\'t been defined.\n" + iVar3 + 0x28),
                     ((uint *)(param_2 + iVar3))[1] << 0xc | *(uint *)(param_2 + iVar3));
    puVar2 = (uint *)(param_3 + iVar3);
    iVar1 = iVar3 + 0x14;
    iVar3 = iVar3 + 4;
    system_reg_write((int)("Failed to acquire subdev %s, deferring probe\n" + iVar1),
                     puVar2[1] << 0xc | *puVar2);
  } while (iVar3 != 0x80);
  return;
}



void tiziano_gib_deir_interpolate
               (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  
  uVar3 = (param_3 + (uint)(param_3 == param_4)) - param_4;
  iVar1 = 0;
  do {
    piVar2 = (int *)(param_6 + iVar1);
    piVar4 = (int *)(param_5 + iVar1);
    puVar5 = (uint *)(param_1 + iVar1);
    iVar1 = iVar1 + 4;
    *puVar5 = (*piVar2 * uVar3 + (*piVar4 - *piVar2) * (param_2 - param_4)) / uVar3;
  } while (iVar1 != 0x84);
  return;
}



void tiziano_gib_deir_ir_interpolation(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  uVar4 = DAT_000ab438;
  uVar3 = DAT_000ab434;
  uVar2 = DAT_000ab430;
  uVar1 = gib_ir_point;
  if (DAT_000ab438 < param_1) {
    deir_flag_37221 = 0;
  }
  else if (DAT_000ab434 < param_1) {
    deir_flag_37221 = 1;
  }
  else if (DAT_000ab430 < param_1) {
    deir_flag_37221 = 2;
  }
  else if (gib_ir_point < param_1) {
    deir_flag_37221 = 3;
  }
  else {
    deir_flag_37221 = 4;
  }
  if (deir_flag_37221 == 0) {
    if (deir_flag_last_37222 == 0) {
      return;
    }
  }
  else if (((deir_flag_37221 == 2) || (deir_flag_37221 == 4)) &&
          (deir_flag_last_37222 == deir_flag_37221)) {
    return;
  }
  deir_flag_last_37222 = deir_flag_37221;
  switch(deir_flag_37221) {
  case 0:
    puVar5 = tiziano_gib_deir_r_h;
    puVar6 = tiziano_gib_deir_g_h;
    puVar7 = tiziano_gib_deir_b_h;
    break;
  case 1:
    tiziano_gib_deir_interpolate(0xbd758,param_1,DAT_000ab438,DAT_000ab434,0xbd688,0xab3a8);
    tiziano_gib_deir_interpolate(0xbd7dc,param_1,uVar4,uVar3,0xbd604,0xab324);
    tiziano_gib_deir_interpolate(0xbd860,param_1,uVar4,uVar3,0xbd580,0xab2a0);
    puVar5 = gib_deir_r_37227;
    puVar6 = gib_deir_g_37228;
    puVar7 = gib_deir_b_37229;
    break;
  case 2:
    puVar5 = tiziano_gib_deir_r_m;
    puVar6 = tiziano_gib_deir_g_m;
    puVar7 = tiziano_gib_deir_b_m;
    break;
  case 3:
    tiziano_gib_deir_interpolate(0xbd758,param_1,DAT_000ab430,gib_ir_point,0xab3a8,0xbd4fc);
    tiziano_gib_deir_interpolate(0xbd7dc,param_1,uVar2,uVar1,0xab324,0xbd478);
    tiziano_gib_deir_interpolate(0xbd860,param_1,uVar2,uVar1,0xab2a0,0xbd3f4);
    puVar5 = gib_deir_r_37227;
    puVar6 = gib_deir_g_37228;
    puVar7 = gib_deir_b_37229;
    break;
  case 4:
    puVar5 = tiziano_gib_deir_r_l;
    puVar6 = tiziano_gib_deir_g_l;
    puVar7 = tiziano_gib_deir_b_l;
    break;
  default:
    return;
  }
  tiziano_gib_deir_reg((int)puVar5,(int)puVar6,(int)puVar7);
  return;
}



undefined4 tisp_gib_deir_ir_update(uint param_1)

{
  uint uVar1;
  
  gib_ir_value = param_1;
  if ((DAT_000ab51c == 1) && (gib_ir_mode == 1)) {
    uVar1 = param_1 - DAT_000ab440;
    if (param_1 <= DAT_000ab440) {
      uVar1 = DAT_000ab440 - param_1;
    }
    if ((DAT_000ab448 < uVar1) || (trig_set_deir == 1)) {
      trig_set_deir = 0;
      tiziano_gib_deir_ir_interpolation(param_1);
      DAT_000ab440 = gib_ir_value;
    }
  }
  return 0;
}



undefined4 tiziano_gib_init(void)

{
  tiziano_gib_params_refresh();
  if (deir_en == 1) {
    DAT_000ab51c = (uint)(day_night == 0);
  }
  else {
    DAT_000ab51c = 0;
  }
  tiziano_gib_lut_parameter();
  tiziano_gib_deir_reg(0xab3a8,0xab324,0xab2a0);
  return 0;
}



undefined4 tisp_gib_param_array_get(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__src;
  size_t __n;
  
  switch(param_1) {
  case 0x3e:
    __src = (undefined1 *)&tiziano_gib_config_line;
    __n = 0x30;
    goto LAB_00032c38;
  case 0x3f:
    __src = (undefined1 *)&tiziano_gib_r_g_linear;
    goto LAB_00032c34;
  case 0x40:
    __src = (undefined1 *)&tiziano_gib_b_ir_linear;
LAB_00032c34:
    __n = 8;
    goto LAB_00032c38;
  case 0x41:
    __src = tiziano_gib_deirm_blc_r_linear;
    goto LAB_00032b0c;
  case 0x42:
    __src = tiziano_gib_deirm_blc_gr_linear;
    goto LAB_00032b0c;
  case 0x43:
    __src = tiziano_gib_deirm_blc_gb_linear;
    goto LAB_00032b0c;
  case 0x44:
    __src = tiziano_gib_deirm_blc_b_linear;
    goto LAB_00032b0c;
  case 0x45:
    __src = tiziano_gib_deirm_blc_ir_linear;
LAB_00032b0c:
    __n = 0x24;
    goto LAB_00032c38;
  case 0x46:
    __src = (undefined1 *)&gib_ir_point;
    __n = 0x10;
    goto LAB_00032c38;
  case 0x47:
    __src = gib_ir_reser;
    goto LAB_00032be4;
  case 0x48:
    __src = tiziano_gib_deir_r_h;
    break;
  case 0x49:
    __src = tiziano_gib_deir_g_h;
    break;
  case 0x4a:
    __src = tiziano_gib_deir_b_h;
    break;
  case 0x4b:
    __src = tiziano_gib_deir_r_m;
    break;
  case 0x4c:
    __src = tiziano_gib_deir_g_m;
    break;
  case 0x4d:
    __src = tiziano_gib_deir_b_m;
    break;
  case 0x4e:
    __src = tiziano_gib_deir_r_l;
    break;
  case 0x4f:
    __src = tiziano_gib_deir_g_l;
    break;
  case 0x50:
    __src = tiziano_gib_deir_b_l;
    break;
  case 0x51:
    __src = tiziano_gib_deir_matrix_h;
    goto LAB_00032be4;
  case 0x52:
    __src = tiziano_gib_deir_matrix_m;
    goto LAB_00032be4;
  case 0x53:
    __src = tiziano_gib_deir_matrix_l;
LAB_00032be4:
    __n = 0x3c;
    goto LAB_00032c38;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 0x84;
LAB_00032c38:
  memcpy(param_2,__src,__n);
  *param_3 = __n;
  return 0;
}



undefined4 tisp_gib_param_array_set(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  undefined4 *__dest;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 0x3e:
    memcpy(&tiziano_gib_config_line,param_2,0x30);
    uVar2 = 0x30;
    goto LAB_00032e38;
  case 0x3f:
    __dest = &tiziano_gib_r_g_linear;
    goto LAB_00032cd0;
  case 0x40:
    __dest = &tiziano_gib_b_ir_linear;
LAB_00032cd0:
    memcpy(__dest,param_2,8);
    uVar2 = 8;
    goto LAB_00032e38;
  case 0x41:
    puVar1 = tiziano_gib_deirm_blc_r_linear;
    goto LAB_00032cf8;
  case 0x42:
    puVar1 = tiziano_gib_deirm_blc_gr_linear;
    goto LAB_00032cf8;
  case 0x43:
    puVar1 = tiziano_gib_deirm_blc_gb_linear;
    goto LAB_00032cf8;
  case 0x44:
    puVar1 = tiziano_gib_deirm_blc_b_linear;
    goto LAB_00032cf8;
  case 0x45:
    puVar1 = tiziano_gib_deirm_blc_ir_linear;
LAB_00032cf8:
    memcpy(puVar1,param_2,0x24);
    uVar2 = 0x24;
    goto LAB_00032e38;
  case 0x46:
    memcpy(&gib_ir_point,param_2,0x10);
    uVar2 = 0x10;
    goto LAB_00032e38;
  case 0x47:
    puVar1 = gib_ir_reser;
    goto LAB_00032df4;
  case 0x48:
    puVar1 = tiziano_gib_deir_r_h;
    break;
  case 0x49:
    puVar1 = tiziano_gib_deir_g_h;
    break;
  case 0x4a:
    puVar1 = tiziano_gib_deir_b_h;
    break;
  case 0x4b:
    puVar1 = tiziano_gib_deir_r_m;
    break;
  case 0x4c:
    puVar1 = tiziano_gib_deir_g_m;
    break;
  case 0x4d:
    puVar1 = tiziano_gib_deir_b_m;
    break;
  case 0x4e:
    puVar1 = tiziano_gib_deir_r_l;
    break;
  case 0x4f:
    puVar1 = tiziano_gib_deir_g_l;
    break;
  case 0x50:
    puVar1 = tiziano_gib_deir_b_l;
    break;
  case 0x51:
    puVar1 = tiziano_gib_deir_matrix_h;
    goto LAB_00032df4;
  case 0x52:
    puVar1 = tiziano_gib_deir_matrix_m;
    goto LAB_00032df4;
  case 0x53:
    puVar1 = tiziano_gib_deir_matrix_l;
LAB_00032df4:
    memcpy(puVar1,param_2,0x3c);
    uVar2 = 0x3c;
    goto LAB_00032e38;
  default:
    isp_printf();
    return 0xffffffff;
  }
  memcpy(puVar1,param_2,0x84);
  uVar2 = 0x84;
LAB_00032e38:
  tiziano_gib_lut_parameter();
  trig_set_deir = 1;
  *param_3 = uVar2;
  return 0;
}



void system_reg_write_gb(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    system_reg_write(0x1070,1);
  }
  system_reg_write(param_2,param_3);
  return;
}



undefined4 tisp_gb_blc_again_interp(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  uVar10 = param_1 >> 0x10;
  uVar8 = param_1 & 0xffff;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  uVar1 = tisp_simple_intp(uVar10,uVar8,0xab5d0);
  uVar2 = tisp_simple_intp(uVar10,uVar8,0xab5ac);
  uVar3 = tisp_simple_intp(uVar10,uVar8,0xab588);
  uVar4 = tisp_simple_intp(uVar10,uVar8,0xab564);
  uVar5 = tisp_simple_intp(uVar10,uVar8,0xab540);
  iVar6 = tisp_simple_intp(uVar10,uVar8,0xbd8f8);
  uVar8 = param_1;
  if ((param_2 == 0) || (uVar8 = tisp_gb_blc_ag, param_2 != 1)) {
    tisp_gb_blc_ag = uVar8;
    iVar7 = 0x1020;
    iVar9 = 0x101c;
    iVar11 = 0x1018;
  }
  else {
    iVar7 = 0x102c;
    iVar9 = 0x1028;
    iVar11 = 0x1024;
    DAT_000bd8f4 = param_1;
  }
  uVar8 = system_reg_read(8);
  switch(uVar8 & 0x1f) {
  case 0:
    local_48 = uVar1;
    local_44 = uVar2;
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar5;
    break;
  case 1:
    local_48 = uVar4;
    local_44 = uVar3;
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar5;
    break;
  case 2:
    local_48 = uVar2;
    local_44 = uVar1;
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar5;
    break;
  case 3:
    local_48 = uVar3;
    local_44 = uVar4;
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar5;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  default:
    isp_printf();
    break;
  case 8:
    local_48 = uVar1;
    local_44 = uVar2;
    local_40 = uVar5;
    local_3c = uVar4;
    local_38 = uVar3;
    break;
  case 9:
    local_48 = uVar4;
    local_44 = uVar3;
    local_40 = uVar5;
    local_3c = uVar1;
    local_38 = uVar2;
    break;
  case 10:
    local_48 = uVar1;
    local_44 = uVar5;
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar2;
    break;
  case 0xb:
    local_48 = uVar4;
    local_44 = uVar5;
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar3;
    break;
  case 0xc:
    local_48 = uVar2;
    local_44 = uVar1;
    local_40 = uVar4;
    local_3c = uVar5;
    local_38 = uVar3;
    break;
  case 0xd:
    local_48 = uVar3;
    local_44 = uVar4;
    local_40 = uVar1;
    local_3c = uVar5;
    local_38 = uVar2;
    break;
  case 0xe:
    local_48 = uVar5;
    local_44 = uVar1;
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar2;
    break;
  case 0xf:
    local_48 = uVar5;
    local_44 = uVar4;
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar3;
    break;
  case 0x10:
    local_48 = uVar1;
    local_44 = uVar2;
    local_40 = uVar3;
    local_3c = uVar5;
    local_38 = uVar4;
    break;
  case 0x11:
    local_48 = uVar4;
    local_44 = uVar3;
    local_40 = uVar2;
    local_3c = uVar5;
    local_38 = uVar1;
    break;
  case 0x12:
    local_48 = uVar2;
    local_44 = uVar1;
    local_40 = uVar5;
    local_3c = uVar3;
    local_38 = uVar4;
    break;
  case 0x13:
    local_48 = uVar3;
    local_44 = uVar4;
    local_40 = uVar5;
    local_3c = uVar2;
    local_38 = uVar1;
    break;
  case 0x14:
    local_48 = uVar3;
    local_44 = uVar5;
    local_40 = uVar1;
    local_3c = uVar2;
    local_38 = uVar4;
    break;
  case 0x15:
    local_48 = uVar2;
    local_44 = uVar5;
    local_40 = uVar4;
    local_3c = uVar3;
    local_38 = uVar1;
    break;
  case 0x16:
    local_48 = uVar5;
    local_44 = uVar3;
    local_40 = uVar2;
    local_3c = uVar1;
    local_38 = uVar4;
    break;
  case 0x17:
    local_48 = uVar5;
    local_44 = uVar2;
    local_40 = uVar3;
    local_3c = uVar4;
    local_38 = uVar1;
  }
  system_reg_write(0x1014,DAT_000bd920 << 0x10 | tisp_gb_blc_min_en);
  system_reg_write(iVar11,local_44 << 0x10 | local_48);
  system_reg_write(iVar9,local_3c << 0x10 | local_40);
  system_reg_write(iVar7,iVar6 << 0x10 | local_38);
  return 0;
}



undefined4 tisp_gb_init_reg(void)

{
  system_reg_write_gb(1,0x1008,DAT_000bd928 << 2 | tisp_gb_dgain_shift);
  if (init_37179 == 0) {
    system_reg_write_gb(1,0x1000,DAT_000ab608 << 0x10 | tisp_gb_dgain_rgbir_l);
    system_reg_write_gb(1,0x1004,DAT_000ab610 << 0x10 | DAT_000ab60c);
    system_reg_write_gb(1,0x100c,DAT_000ab5f8 << 0x10 | tisp_gb_dgain_rgbir_s);
    system_reg_write_gb(1,0x1010,DAT_000ab600 << 0x10 | DAT_000ab5fc);
  }
  tisp_gb_blc_again_interp(tisp_gb_blc_ag,0);
  tisp_gb_blc_again_interp(DAT_000bd8f4,1);
  init_37179 = 1;
  return 0;
}



undefined4 tisp_gb_params_refresh(void)

{
  memcpy(&tisp_gb_dgain_shift,&DAT_000a852c,8);
  memcpy(&tisp_gb_dgain_rgbir_l,&DAT_000a8534,0x10);
  memcpy(&tisp_gb_dgain_rgbir_s,&DAT_000a8544,0x10);
  memcpy(tisp_gb_blc_r,&DAT_000a8554,0x24);
  memcpy(tisp_gb_blc_gr,&DAT_000a8578,0x24);
  memcpy(tisp_gb_blc_gb,&DAT_000a859c,0x24);
  memcpy(tisp_gb_blc_b,&DAT_000a85c0,0x24);
  memcpy(tisp_gb_blc_ir,&DAT_000a85e4,0x24);
  memcpy(&tisp_gb_blc_min_en,&DAT_000a8608,8);
  memcpy(tisp_gb_blc_min,&DAT_000a8610,0x24);
  return 0;
}



undefined4 tisp_gb_dn_params_refresh(void)

{
  tisp_gb_params_refresh();
  tisp_gb_init_reg();
  return 0;
}



undefined4 tisp_gb_init(void)

{
  tisp_gb_params_refresh();
  tisp_gb_init_reg();
  return 0;
}



undefined4 tisp_gb_param_array_get(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__src;
  size_t __n;
  
  switch(param_1) {
  case 0x3f5:
    __src = (undefined1 *)&tisp_gb_dgain_shift;
    goto LAB_000335fc;
  case 0x3f6:
    __src = (undefined1 *)&tisp_gb_dgain_rgbir_l;
    goto LAB_0003360c;
  case 0x3f7:
    __src = (undefined1 *)&tisp_gb_dgain_rgbir_s;
LAB_0003360c:
    __n = 0x10;
    goto LAB_00033610;
  case 0x3f8:
    __src = tisp_gb_blc_r;
    break;
  case 0x3f9:
    __src = tisp_gb_blc_gr;
    break;
  case 0x3fa:
    __src = tisp_gb_blc_gb;
    break;
  case 0x3fb:
    __src = tisp_gb_blc_b;
    break;
  case 0x3fc:
    __src = tisp_gb_blc_ir;
    break;
  case 0x3fd:
    __src = (undefined1 *)&tisp_gb_blc_min_en;
LAB_000335fc:
    __n = 8;
    goto LAB_00033610;
  case 0x3fe:
    __src = tisp_gb_blc_min;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 0x24;
LAB_00033610:
  memcpy(param_2,__src,__n);
  *param_3 = __n;
  return 0;
}



undefined4 tisp_gb_param_array_set(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined1 *__dest;
  undefined4 *puVar2;
  
  switch(param_1) {
  case 0x3f5:
    puVar2 = &tisp_gb_dgain_shift;
    goto LAB_000336fc;
  case 0x3f6:
    puVar2 = &tisp_gb_dgain_rgbir_l;
    goto LAB_00033694;
  case 0x3f7:
    puVar2 = &tisp_gb_dgain_rgbir_s;
LAB_00033694:
    memcpy(puVar2,param_2,0x10);
    uVar1 = 0x10;
    goto LAB_0003376c;
  case 0x3f8:
    __dest = tisp_gb_blc_r;
    break;
  case 0x3f9:
    __dest = tisp_gb_blc_gr;
    break;
  case 0x3fa:
    __dest = tisp_gb_blc_gb;
    break;
  case 0x3fb:
    __dest = tisp_gb_blc_b;
    break;
  case 0x3fc:
    __dest = tisp_gb_blc_ir;
    break;
  case 0x3fd:
    puVar2 = &tisp_gb_blc_min_en;
LAB_000336fc:
    memcpy(puVar2,param_2,8);
    uVar1 = 8;
    goto LAB_0003376c;
  case 0x3fe:
    memcpy(tisp_gb_blc_min,param_2,0x24);
    tisp_gb_init_reg();
    uVar1 = 0x24;
    goto LAB_0003376c;
  default:
    isp_printf();
    return 0xffffffff;
  }
  memcpy(__dest,param_2,0x24);
  uVar1 = 0x24;
LAB_0003376c:
  *param_3 = uVar1;
  return 0;
}



undefined4 tiziano_lsc_lut_parameter(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  system_reg_write(0x3800,DAT_000bd934 << 0x10 | mesh_size);
  puVar3 = &d_linear;
  system_reg_write(0x3804,lut_stride << 0x10 | lsc_mean_en << 0xf | mesh_scale);
  for (uVar2 = 0; uVar2 < lut_num; uVar2 = uVar2 + 3) {
    uVar6 = puVar3[1];
    uVar1 = *puVar3;
    uVar5 = puVar3[2];
    puVar3 = puVar3 + 3;
    iVar4 = (uVar2 / 3 + 0x2800) * 0x10;
    system_reg_write(iVar4,uVar1);
    system_reg_write(iVar4 + 4,uVar6);
    system_reg_write(iVar4 + 8,uVar5);
  }
  system_reg_write(0x2800c,0);
  return 0;
}



uint jz_isp_lsc_interpolate(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  
  uVar1 = param_2 - param_3;
  return ((param_5 >> 0xc) * uVar1 + ((param_4 >> 0xc) - (param_5 >> 0xc)) * (param_1 - param_3)) /
         uVar1 << 0xc |
         ((param_5 & 0xfff) * uVar1 + ((param_4 & 0xfff) - (param_5 & 0xfff)) * (param_1 - param_3))
         / uVar1;
}



void tisp_lsc_wdr_en(int param_1)

{
  undefined1 *puVar1;
  
  lsc_wdr_en = param_1;
  if (param_1 == 0) {
    puVar1 = mesh_lsc_str;
  }
  else {
    puVar1 = mesh_lsc_str_wdr;
  }
  mesh_lsc_str_now = puVar1;
  return;
}



uint jz_isp_lsc_inter_str(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)((param_3 - param_2) * param_1 + param_2 * 0x1000) >> 0xc;
  uVar1 = 0xfff;
  if (uVar2 < 0x1000) {
    uVar1 = uVar2;
  }
  return uVar1;
}



undefined4 jz_isp_lsc_ct(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint local_70 [4];
  undefined4 *local_60;
  undefined4 *local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_44 = lut_num;
  local_50 = DAT_000ab62c;
  local_4c = DAT_000ab628;
  local_54 = DAT_000ab630;
  local_48 = tiziano_lsc_ct_points;
  iVar4 = 0x1000;
  if (lsc_gain_old != 0xffffffff) {
    iVar4 = tisp_simple_intp(lsc_gain_old >> 0x10,lsc_gain_old & 0xffff,(int)mesh_lsc_str_now);
  }
  if (local_54 < ct) {
    lsc_change_flag = 0;
  }
  else if (local_50 < ct) {
    lsc_change_flag = 1;
  }
  else if (local_4c < ct) {
    lsc_change_flag = 2;
  }
  else if (local_48 < ct) {
    lsc_change_flag = 3;
  }
  else {
    lsc_change_flag = 4;
  }
  if (lsc_change_flag == 0) {
    if (lsc_change_flag_last != 0) goto LAB_00033afc;
  }
  else if ((lsc_change_flag == 2) || (lsc_change_flag == 4)) {
    if (lsc_change_flag_last != lsc_change_flag) goto LAB_00033afc;
  }
  else {
    if ((lsc_change_flag != 1) && (lsc_change_flag != 3)) goto LAB_00033afc;
    if (ct_last < ct) {
      uVar8 = ct - ct_last;
    }
    else {
      uVar8 = ct_last - ct;
    }
    if (299 < uVar8) goto LAB_00033afc;
  }
  if (gain_no_change != 0) {
    lsc_change_flag_last = lsc_change_flag;
    return 0;
  }
LAB_00033afc:
  local_5c = &d_linear;
  local_60 = &a_linear;
  puVar6 = &t_linear;
  iVar3 = 0;
  for (uVar8 = 3; uVar5 = ct, uVar7 = uVar8 - 3, uVar7 < local_44; uVar8 = uVar8 + 3) {
    switch(lsc_change_flag) {
    case 0:
      iVar10 = 0;
      for (uVar5 = uVar7; uVar5 < uVar8; uVar5 = uVar5 + 1) {
        puVar1 = (undefined4 *)((int)local_70 + iVar10);
        puVar2 = (undefined4 *)((int)local_5c + iVar10);
        iVar10 = iVar10 + 4;
        *puVar1 = *puVar2;
      }
      break;
    case 1:
      iVar10 = 0;
      for (uVar9 = uVar7; uVar9 < uVar8; uVar9 = uVar9 + 1) {
        uVar11 = jz_isp_lsc_interpolate
                           (uVar5,local_54,local_50,*(uint *)((int)local_5c + iVar10),
                            *(uint *)((int)puVar6 + iVar10));
        *(uint *)((int)local_70 + iVar10) = uVar11;
        iVar10 = iVar10 + 4;
      }
      break;
    case 2:
      iVar10 = 0;
      for (uVar5 = uVar7; uVar5 < uVar8; uVar5 = uVar5 + 1) {
        *(undefined4 *)((int)local_70 + iVar10) = *(undefined4 *)((int)puVar6 + iVar10);
        iVar10 = iVar10 + 4;
      }
      break;
    case 3:
      iVar10 = 0;
      for (uVar9 = uVar7; uVar9 < uVar8; uVar9 = uVar9 + 1) {
        uVar11 = jz_isp_lsc_interpolate
                           (uVar5,local_4c,local_48,*(uint *)((int)puVar6 + iVar10),
                            *(uint *)((int)local_60 + iVar10));
        *(uint *)((int)local_70 + iVar10) = uVar11;
        iVar10 = iVar10 + 4;
      }
      break;
    case 4:
      iVar10 = 0;
      for (uVar5 = uVar7; uVar5 < uVar8; uVar5 = uVar5 + 1) {
        puVar1 = (undefined4 *)((int)local_70 + iVar10);
        puVar2 = (undefined4 *)((int)local_60 + iVar10);
        iVar10 = iVar10 + 4;
        *puVar1 = *puVar2;
      }
    }
    uVar5 = local_70[0] & 0xfff;
    local_58 = local_70[0] >> 0xc;
    uVar11 = local_70[1] & 0xfff;
    local_40 = local_70[1] >> 0xc;
    uVar9 = local_70[2] & 0xfff;
    local_3c = local_70[2] >> 0xc;
    if (mesh_scale == 1) {
      iVar3 = 0x400;
    }
    else if (mesh_scale == 0) {
      iVar3 = 0x800;
    }
    else if (mesh_scale == 2) {
      iVar3 = 0x200;
    }
    else if (mesh_scale == 3) {
      iVar3 = 0x100;
    }
    else {
      isp_printf();
    }
    local_34 = jz_isp_lsc_inter_str(iVar4,iVar3,uVar5);
    local_30 = jz_isp_lsc_inter_str(iVar4,iVar3,uVar11);
    uVar5 = jz_isp_lsc_inter_str(iVar4,iVar3,uVar9);
    uVar9 = jz_isp_lsc_inter_str(iVar4,iVar3,local_58);
    local_38 = jz_isp_lsc_inter_str(iVar4,iVar3,local_40);
    uVar11 = jz_isp_lsc_inter_str(iVar4,iVar3,local_3c);
    local_30 = local_38 << 0xc | local_30;
    puVar6 = puVar6 + 3;
    iVar10 = (uVar7 / 3 + 0x2800) * 0x10;
    local_38 = uVar11 << 0xc | uVar5;
    system_reg_write(iVar10,uVar9 << 0xc | local_34);
    system_reg_write(iVar10 + 4,local_30);
    system_reg_write(iVar10 + 8,local_38);
    local_60 = local_60 + 3;
    local_5c = local_5c + 3;
  }
  system_reg_write(0x2800c,0);
  lsc_change_flag_last = lsc_change_flag;
  return 0;
}



undefined4 tisp_lsc_ct_update(undefined4 param_1)

{
  ct = param_1;
  jz_isp_lsc_ct();
  ct_last = ct;
  return 0;
}



undefined4 jz_isp_lsc_gain(void)

{
  return 0;
}



undefined4 tisp_lsc_gain_update(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1;
  if (lsc_gain_old != 0xffffffff) {
    if ((param_2 == 0) && (param_1 <= lsc_gain_old)) {
      uVar2 = lsc_gain_old - param_1;
    }
    else {
      uVar2 = param_1 - lsc_gain_old;
    }
    uVar1 = lsc_gain_old;
    if (0xff < uVar2) {
      gain_no_change = 0;
      lsc_gain_old = param_1;
      jz_isp_lsc_ct();
      gain_no_change = 1;
      return 0;
    }
  }
  lsc_gain_old = uVar1;
  return 0;
}



undefined4 tiziano_lsc_params_refresh(void)

{
  memcpy(&lut_num,&DAT_00098e10,4);
  memcpy(&mesh_scale,&DAT_00098e14,4);
  memcpy(&lut_stride,&DAT_00098e18,4);
  memcpy(&mesh_size,&DAT_00098e1c,8);
  memcpy(&tiziano_lsc_ct_points,&DAT_00098e24,0x10);
  memcpy(&a_linear,&DAT_00098e34,0x1ffc);
  memcpy(&t_linear,&DAT_0009ae30,0x1ffc);
  memcpy(&d_linear,&DAT_0009ce2c,0x1ffc);
  memcpy(mesh_lsc_str,&DAT_0009ee28,0x24);
  memcpy(mesh_lsc_str_wdr,&DAT_0009ee4c,0x24);
  memcpy(&lsc_mean_en,&DAT_0009ee70,4);
  return 0;
}



undefined4 tiziano_lsc_dn_params_refresh(void)

{
  tiziano_lsc_params_refresh();
  return 0;
}



undefined4 tiziano_lsc_init(void)

{
  undefined1 *puVar1;
  
  lsc_gain_old = 0xffffffff;
  if (lsc_wdr_en == 0) {
    puVar1 = mesh_lsc_str;
  }
  else {
    puVar1 = mesh_lsc_str_wdr;
  }
  mesh_lsc_str_now = puVar1;
  tiziano_lsc_params_refresh();
  tiziano_lsc_lut_parameter();
  return 0;
}



undefined4 tisp_lsc_param_array_get(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__src;
  size_t __n;
  
  switch(param_1) {
  case 0x54:
    __src = (undefined1 *)&lut_num;
    break;
  case 0x55:
    __src = (undefined1 *)&mesh_scale;
    break;
  case 0x56:
    __src = (undefined1 *)&lut_stride;
    break;
  case 0x57:
    __src = (undefined1 *)&mesh_size;
    __n = 8;
    goto LAB_00034274;
  case 0x58:
    __src = (undefined1 *)&tiziano_lsc_ct_points;
    __n = 0x10;
    goto LAB_00034274;
  case 0x59:
    __src = (undefined1 *)&a_linear;
    goto LAB_000341fc;
  case 0x5a:
    __src = (undefined1 *)&t_linear;
    goto LAB_000341fc;
  case 0x5b:
    __src = (undefined1 *)&d_linear;
LAB_000341fc:
    __n = 0x1ffc;
    goto LAB_00034274;
  case 0x5c:
    __src = mesh_lsc_str;
    goto LAB_00034218;
  case 0x5d:
    __src = mesh_lsc_str_wdr;
LAB_00034218:
    __n = 0x24;
    goto LAB_00034274;
  case 0x5e:
    __src = (undefined1 *)&lsc_mean_en;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 4;
LAB_00034274:
  memcpy(param_2,__src,__n);
  *param_3 = __n;
  return 0;
}



undefined4 tisp_lsc_param_array_set(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__dest;
  size_t __n;
  
  switch(param_1) {
  case 0x54:
    __dest = (undefined1 *)&lut_num;
    break;
  case 0x55:
    __dest = (undefined1 *)&mesh_scale;
    break;
  case 0x56:
    __dest = (undefined1 *)&lut_stride;
    break;
  case 0x57:
    __dest = (undefined1 *)&mesh_size;
    __n = 8;
    goto LAB_000343ac;
  case 0x58:
    __dest = (undefined1 *)&tiziano_lsc_ct_points;
    __n = 0x10;
    goto LAB_000343ac;
  case 0x59:
    __dest = (undefined1 *)&a_linear;
    goto LAB_0003433c;
  case 0x5a:
    __dest = (undefined1 *)&t_linear;
    goto LAB_0003433c;
  case 0x5b:
    __dest = (undefined1 *)&d_linear;
LAB_0003433c:
    __n = 0x1ffc;
    goto LAB_000343ac;
  case 0x5c:
    __dest = mesh_lsc_str;
    goto LAB_00034358;
  case 0x5d:
    __dest = mesh_lsc_str_wdr;
LAB_00034358:
    __n = 0x24;
    goto LAB_000343ac;
  case 0x5e:
    __dest = (undefined1 *)&lsc_mean_en;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 4;
LAB_000343ac:
  memcpy(__dest,param_2,__n);
  system_reg_write(0x3800,DAT_000bd934 << 0x10 | mesh_size);
  system_reg_write(0x3804,lut_stride << 0x10 | lsc_mean_en << 0xf | mesh_scale);
  lsc_change_flag_last = 5;
  ct_last = ct + 500;
  gain_no_change = 0;
  jz_isp_lsc_ct();
  gain_no_change = 1;
  *param_3 = __n;
  return 0;
}



undefined4 tisp_set_csc_version(undefined param_1)

{
  switch(param_1) {
  case 0:
    memcpy(&csc_param_current,csc_bt601_full,0x3c);
    csc_version_now = 0;
    break;
  case 1:
    memcpy(&csc_param_current,csc_bt601_clip,0x3c);
    csc_version_now = 1;
    break;
  case 2:
    memcpy(&csc_param_current,csc_bt709_full,0x3c);
    csc_version_now = 2;
    break;
  case 3:
    memcpy(&csc_param_current,csc_bt709_clip,0x3c);
    csc_version_now = 3;
    break;
  case 4:
    memcpy(&csc_param_current,csc_manual,0x3c);
    csc_version_now = 4;
    break;
  default:
    isp_printf();
    return 0xffffffff;
  }
  system_reg_write(0x6000,0x1f);
  system_reg_write(0x6004,0);
  system_reg_write(0x6010,(((int)DAT_000c39a4 >> 0x1f ^ DAT_000c39a4) - ((int)DAT_000c39a4 >> 0x1f)
                          & 0x3ff) << 10 |
                          (((int)DAT_000c39a8 >> 0x1f ^ DAT_000c39a8) - ((int)DAT_000c39a8 >> 0x1f)
                          & 0x3ff) << 0x14 |
                          ((int)csc_param_current >> 0x1f ^ csc_param_current) -
                          ((int)csc_param_current >> 0x1f) & 0x3ff);
  system_reg_write(0x6014,(((int)DAT_000c39b0 >> 0x1f ^ DAT_000c39b0) - ((int)DAT_000c39b0 >> 0x1f)
                          & 0x3ff) << 10 |
                          (((int)DAT_000c39b4 >> 0x1f ^ DAT_000c39b4) - ((int)DAT_000c39b4 >> 0x1f)
                          & 0x3ff) << 0x14 |
                          ((int)DAT_000c39ac >> 0x1f ^ DAT_000c39ac) - ((int)DAT_000c39ac >> 0x1f) &
                          0x3ff);
  system_reg_write(0x6018,(((int)DAT_000c39bc >> 0x1f ^ DAT_000c39bc) - ((int)DAT_000c39bc >> 0x1f)
                          & 0x3ff) << 10 |
                          (((int)DAT_000c39c0 >> 0x1f ^ DAT_000c39c0) - ((int)DAT_000c39c0 >> 0x1f)
                          & 0x3ff) << 0x14 |
                          ((int)DAT_000c39b8 >> 0x1f ^ DAT_000c39b8) - ((int)DAT_000c39b8 >> 0x1f) &
                          0x3ff);
  system_reg_write(0x6020,(DAT_000c39c8 & 0xff) << 8 | (uint)DAT_000c39c4);
  system_reg_write(0x6030,DAT_000c39d0 << 0x18 | (uint)DAT_000c39d4 | (DAT_000c39d8 & 0xff) << 8 |
                          (uint)DAT_000c39cc << 0x10);
  return 1;
}



undefined4 tisp_set_user_csc(void *param_1)

{
  undefined4 uVar1;
  
  memcpy(csc_manual,param_1,0x3c);
  uVar1 = tisp_set_csc_version(4);
  return uVar1;
}



void tisp_get_current_csc(undefined4 *param_1,void *param_2)

{
  *param_1 = csc_version_now;
  memcpy(param_2,&csc_param_current,0x3c);
  return;
}



undefined4 tisp_dmsc_out_opt_cfg(void)

{
  system_reg_write(0x4800,dmsc_out_opt);
  return 0;
}



undefined4 tisp_dmsc_uu_par_cfg(void)

{
  system_reg_write(0x4808,dmsc_uu_thres_intp << 0x10 | dmsc_uu_stren_intp);
  system_reg_write(0x4804,dmsc_uu_par_array << 0x1f | DAT_000c418c << 10 | DAT_000c4194 |
                          DAT_000c4190 << 8);
  return 0;
}



undefined4 tisp_dmsc_alias_par_cfg(void)

{
  system_reg_write(0x480c,(dmsc_alias_dir_thres_intp - DAT_000c40f4) * 0x10000 |
                          dmsc_alias_dir_thres_intp);
  system_reg_write(0x4834,dmsc_alias_stren_intp << 0x12 | dmsc_alias_par_array | DAT_000c40f0 << 10
                          | DAT_000c40ec << 6);
  system_reg_write(0x4838,dmsc_alias_thres_2_intp << 0x10 | dmsc_alias_thres_1_intp);
  return 0;
}



undefined4 tisp_dmsc_uu_np_cfg(void)

{
  system_reg_write(0x48c8,DAT_000c44e4 << 0x10 | dmsc_uu_np_array);
  system_reg_write(0x48cc,DAT_000c44ec << 0x10 | DAT_000c44e8);
  system_reg_write(0x48d0,DAT_000c44f4 << 0x10 | DAT_000c44f0);
  system_reg_write(0x48d4,DAT_000c44fc << 0x10 | DAT_000c44f8);
  system_reg_write(0x48d8,DAT_000c4504 << 0x10 | DAT_000c4500);
  system_reg_write(0x48dc,DAT_000c450c << 0x10 | DAT_000c4508);
  system_reg_write(0x48e0,DAT_000c4514 << 0x10 | DAT_000c4510);
  system_reg_write(0x48e4,DAT_000c451c << 0x10 | DAT_000c4518);
  return 0;
}



undefined4 tisp_dmsc_sp_d_sigma_3_np_cfg(void)

{
  system_reg_write(0x48e8,DAT_000c4454 << 0x19 | DAT_000c4450 << 0x14 | dmsc_sp_d_sigma_3_np_array |
                          DAT_000c444c << 0xf | DAT_000c4448 << 10 | DAT_000c4444 << 5);
  system_reg_write(0x48ec,DAT_000c446c << 0x19 | DAT_000c4468 << 0x14 | DAT_000c4458 |
                          DAT_000c4464 << 0xf | DAT_000c4460 << 10 | DAT_000c445c << 5);
  system_reg_write(0x48f0,DAT_000c447c << 0xf | DAT_000c4478 << 10 | DAT_000c4470 |
                          DAT_000c4474 << 5);
  return 0;
}



undefined4 tisp_dmsc_sp_d_w_wei_np_cfg(void)

{
  system_reg_write(0x48f4,DAT_000c43f8 << 0x18 | DAT_000c43f4 << 0x12 | dmsc_sp_d_w_wei_np_array |
                          DAT_000c43f0 << 0xc | DAT_000c43ec << 6);
  system_reg_write(0x48f8,DAT_000c440c << 0x18 | DAT_000c4408 << 0x12 | DAT_000c43fc |
                          DAT_000c4404 << 0xc | DAT_000c4400 << 6);
  system_reg_write(0x48fc,DAT_000c4420 << 0x18 | DAT_000c441c << 0x12 | DAT_000c4410 |
                          DAT_000c4418 << 0xc | DAT_000c4414 << 6);
  system_reg_write(0x4900,DAT_000c4434 << 0x18 | DAT_000c4430 << 0x12 | DAT_000c4424 |
                          DAT_000c442c << 0xc | DAT_000c4428 << 6);
  system_reg_write(0x4904,DAT_000c443c << 6 | DAT_000c4438);
  return 0;
}



undefined4 tisp_dmsc_sp_d_b_wei_np_cfg(void)

{
  system_reg_write(0x4908,DAT_000c43a0 << 0x18 | DAT_000c439c << 0x12 | dmsc_sp_d_b_wei_np_array |
                          DAT_000c4398 << 0xc | DAT_000c4394 << 6);
  system_reg_write(0x490c,DAT_000c43b4 << 0x18 | DAT_000c43b0 << 0x12 | DAT_000c43a4 |
                          DAT_000c43ac << 0xc | DAT_000c43a8 << 6);
  system_reg_write(0x4910,DAT_000c43c8 << 0x18 | DAT_000c43c4 << 0x12 | DAT_000c43b8 |
                          DAT_000c43c0 << 0xc | DAT_000c43bc << 6);
  system_reg_write(0x4914,DAT_000c43dc << 0x18 | DAT_000c43d8 << 0x12 | DAT_000c43cc |
                          DAT_000c43d4 << 0xc | DAT_000c43d0 << 6);
  system_reg_write(0x4918,DAT_000c43e4 << 6 | DAT_000c43e0);
  return 0;
}



undefined4 tisp_dmsc_sp_ud_w_wei_np_cfg(void)

{
  system_reg_write(0x491c,DAT_000c4348 << 0x18 | DAT_000c4344 << 0x12 | dmsc_sp_ud_w_wei_np_array |
                          DAT_000c4340 << 0xc | DAT_000c433c << 6);
  system_reg_write(0x4920,DAT_000c435c << 0x18 | DAT_000c4358 << 0x12 | DAT_000c434c |
                          DAT_000c4354 << 0xc | DAT_000c4350 << 6);
  system_reg_write(0x4924,DAT_000c4370 << 0x18 | DAT_000c436c << 0x12 | DAT_000c4360 |
                          DAT_000c4368 << 0xc | DAT_000c4364 << 6);
  system_reg_write(0x4928,DAT_000c4384 << 0x18 | DAT_000c4380 << 0x12 | DAT_000c4374 |
                          DAT_000c437c << 0xc | DAT_000c4378 << 6);
  system_reg_write(0x492c,DAT_000c438c << 6 | DAT_000c4388);
  return 0;
}



undefined4 tisp_dmsc_sp_ud_b_wei_np_cfg(void)

{
  system_reg_write(0x4930,DAT_000c42f0 << 0x18 | DAT_000c42ec << 0x12 | dmsc_sp_ud_b_wei_np_array |
                          DAT_000c42e8 << 0xc | DAT_000c42e4 << 6);
  system_reg_write(0x4934,DAT_000c4304 << 0x18 | DAT_000c4300 << 0x12 | DAT_000c42f4 |
                          DAT_000c42fc << 0xc | DAT_000c42f8 << 6);
  system_reg_write(0x4938,DAT_000c4318 << 0x18 | DAT_000c4314 << 0x12 | DAT_000c4308 |
                          DAT_000c4310 << 0xc | DAT_000c430c << 6);
  system_reg_write(0x493c,DAT_000c432c << 0x18 | DAT_000c4328 << 0x12 | DAT_000c431c |
                          DAT_000c4324 << 0xc | DAT_000c4320 << 6);
  system_reg_write(0x4940,DAT_000c4334 << 6 | DAT_000c4330);
  return 0;
}



undefined4 tisp_dmsc_dir_par_cfg(void)

{
  system_reg_write(0x4810,(dmsc_dir_par_array - (dmsc_dir_par_array >> 3)) * 0x10000 |
                          dmsc_hv_thres_1_intp - (dmsc_hv_thres_1_intp >> 3));
  system_reg_write(0x4814,dmsc_dir_par_array << 0x10 | dmsc_hv_thres_1_intp);
  system_reg_write(0x4820,DAT_000c41e8 << 0x10 | DAT_000c41e4 << 0x18 | dmsc_hv_stren_intp);
  system_reg_write(0x4824,DAT_000c41ec << 0x10 | dmsc_aa_thres_1_intp);
  system_reg_write(0x4828,DAT_000c41f4 << 0x10 | DAT_000c41f0 << 0x18 | dmsc_aa_stren_intp);
  system_reg_write(0x482c,DAT_000c41f8 << 0x10 | dmsc_hvaa_thres_1_intp);
  system_reg_write(0x4830,DAT_000c4200 << 0x10 | DAT_000c41fc << 0x18 | dmsc_hvaa_stren_intp);
  return 0;
}



undefined4 tisp_dmsc_nor_par_cfg(void)

{
  system_reg_write(0x483c,dmsc_nor_par_array << 0x10 | dmsc_nor_alias_thres_intp);
  system_reg_write(0x4840,DAT_000c40b8 << 0x10 | DAT_000c40bc << 6 | DAT_000c40c0);
  return 0;
}



undefined4 tisp_dmsc_sp_d_par_cfg(void)

{
  system_reg_write(0x4844,dmsc_sp_d_par_array << 0x11 | DAT_000c3f6c << 7 | DAT_000c3f74 |
                          DAT_000c3f70 << 6 | DAT_000c3f74 << 4 | DAT_000c3f74 << 2);
  system_reg_write(0x4848,dmsc_sp_d_w_stren_intp << 0x10 | dmsc_sp_d_b_stren_intp);
  system_reg_write(0x484c,DAT_000c3f78 << 0x10 | DAT_000c3f7c);
  system_reg_write(0x4850,dmsc_sp_d_brig_thres_intp << 0x10 | dmsc_sp_d_dark_thres_intp);
  system_reg_write(0x4854,DAT_000c3f80);
  system_reg_write(0x4858,DAT_000c3f84);
  system_reg_write(0x48a4,dmsc_sp_d_v2_win5_thres_intp << 0x10 | DAT_000c3f88);
  system_reg_write(0x48a8,dmsc_sp_d_flat_thres_intp << 0x14 | dmsc_sp_d_flat_stren_intp |
                          DAT_000c3f8c << 0xb);
  system_reg_write(0x48ac,DAT_000c3f88 << 0x10 | dmsc_sp_d_oe_stren_intp);
  return 0;
}



undefined4 tisp_dmsc_sp_ud_par_cfg(void)

{
  system_reg_write(0x485c,dmsc_sp_ud_par_array << 0x10 | DAT_000c3df4 << 0xc | DAT_000c3e00 |
                          DAT_000c3df8 << 8 | DAT_000c3dfc << 4 | DAT_000c3e00 << 2);
  system_reg_write(0x4860,dmsc_sp_ud_w_stren_intp << 0x10 | dmsc_sp_ud_b_stren_intp);
  system_reg_write(0x4864,DAT_000c3e04 << 0x10 | DAT_000c3e08);
  system_reg_write(0x4868,dmsc_sp_ud_brig_thres_intp << 0x10 | dmsc_sp_ud_dark_thres_intp);
  system_reg_write(0x486c,DAT_000c3e0c);
  system_reg_write(0x4870,DAT_000c3e10);
  system_reg_write(0x48b0,dmsc_sp_ud_v1_v2_par_array << 0x1b | DAT_000c3dcc << 0xf | DAT_000c3dd4 |
                          DAT_000c3dd0 << 8);
  system_reg_write(0x48b4,DAT_000c3dd8 << 0x1b | DAT_000c3ddc << 0x18 | DAT_000c3dec |
                          DAT_000c3de0 << 0x10 | DAT_000c3de4 << 8 | DAT_000c3de8 << 4);
  system_reg_write(0x48b8,dmsc_sp_ud_std_thres_intp << 0x10 | dmsc_sp_ud_std_stren_intp |
                          DAT_000c3e14 << 8);
  system_reg_write(0x48bc,dmsc_sp_ud_flat_stren_intp << 0x10 | DAT_000c3e18);
  system_reg_write(0x48c0,dmsc_sp_ud_flat_stren_intp);
  system_reg_write(0x48c4,dmsc_sp_ud_oe_stren_intp << 8 | DAT_000c3e1c | DAT_000c3e20 << 0x1b);
  return 0;
}



undefined4 tisp_dmsc_sp_alias_par_cfg(void)

{
  system_reg_write(0x4874,dmsc_sp_alias_thres_intp << 0x10 | dmsc_sp_alias_par_array);
  return 0;
}



undefined4 tisp_dmsc_rgb_alias_par_cfg(void)

{
  system_reg_write(0x4878,dmsc_rgb_alias_par_array << 0x10 | dmsc_rgb_dir_thres_intp);
  system_reg_write(0x487c,dmsc_rgb_alias_stren_intp << 5 | DAT_000c3d50 | DAT_000c3da0 << 0x10);
  return 0;
}



undefined4 tisp_dmsc_fc_par_cfg(void)

{
  int iVar1;
  int iVar2;
  
  system_reg_write(0x4880,dmsc_fc_t1_stren_intp << 0xe | dmsc_fc_alias_stren_intp << 0x15 |
                          dmsc_fc_t2_stren_intp << 7 | DAT_000c3c48);
  system_reg_write(0x4884,DAT_000c3c2c << 0x10 | dmsc_fc_t1_thres_intp);
  system_reg_write(0x4888,DAT_000c3c30 << 0x10 | DAT_000c3c34);
  system_reg_write(0x488c,DAT_000c3c44 << 0xc | DAT_000c3c4c |
                          (DAT_000c3c38 + dmsc_fc_t1_thres_intp) * 0x20000);
  system_reg_write(0x4890,dmsc_fc_par_array << 0x10 | dmsc_fc_par_array << 6 | dmsc_fc_par_array);
  system_reg_write(0x4894,dmsc_fc_t3_stren_intp);
  system_reg_write(0x4898,DAT_000c3c38 + DAT_000c3c3c + dmsc_fc_t1_thres_intp |
                          dmsc_fc_par_array << 0x10);
  system_reg_write(0x489c,(DAT_000c3c38 + dmsc_fc_t1_thres_intp + DAT_000c3c3c) * 0x10000 |
                          DAT_000c3c38 + dmsc_fc_t1_thres_intp);
  iVar1 = DAT_000c3c38 + DAT_000c3c3c + dmsc_fc_t1_thres_intp + DAT_000c3c40;
  iVar2 = 0xfff;
  if (iVar1 < 0x1000) {
    iVar2 = iVar1;
  }
  system_reg_write(0x48a0,iVar2);
  system_reg_write(0x4980,dmsc_fc_lum_thres_intp << 0x10 | dmsc_fc_lum_stren_intp);
  return 0;
}



undefined4 tisp_dmsc_deir_par_cfg(void)

{
  system_reg_write(0x4944,dmsc_deir_oe_en << 8 | DAT_000c3c24);
  system_reg_write(0x4948,dmsc_deir_rgb_ir_oe_slope << 0x10 | DAT_000c3c10);
  system_reg_write(0x494c,DAT_000c3c14 << 0x10 | DAT_000c3c18);
  system_reg_write(0x4988,dmsc_deir_fusion_stren_intp << 8 | dmsc_deir_fusion_thres_intp << 0x10 |
                          DAT_000c3c1c);
  return 0;
}



undefined4 tisp_dmsc_awb_gain_par_cfg(void)

{
  system_reg_write(0x4984,DAT_000c3b70 << 0x1c | DAT_000c3b6c << 0x10 | dmsc_awb_gain);
  return 0;
}



undefined4 tisp_dmsc_deir_rgb_par_cfg(void)

{
  system_reg_write(0x4950,dmsc_r_deir_array << 0x10 | DAT_000c44c4);
  system_reg_write(0x4954,DAT_000c44c8 << 0x10 | DAT_000c44cc);
  system_reg_write(0x4958,DAT_000c44d0 << 0x10 | DAT_000c44d4);
  system_reg_write(0x495c,DAT_000c44d8 << 0x10 | DAT_000c44dc);
  system_reg_write(0x4960,dmsc_g_deir_array << 0x10 | DAT_000c44a4);
  system_reg_write(0x4964,DAT_000c44a8 << 0x10 | DAT_000c44ac);
  system_reg_write(0x4968,DAT_000c44b0 << 0x10 | DAT_000c44b4);
  system_reg_write(0x496c,DAT_000c4498 << 0x10 | DAT_000c449c);
  system_reg_write(0x4970,dmsc_b_deir_array << 0x10 | DAT_000c4484);
  system_reg_write(0x4974,DAT_000c4488 << 0x10 | DAT_000c448c);
  system_reg_write(0x4978,DAT_000c4490 << 0x10 | DAT_000c4494);
  system_reg_write(0x497c,DAT_000c4498 << 0x10 | DAT_000c449c);
  return 0;
}



undefined4 tisp_dmsc_d_ud_ns_par_cfg(void)

{
  system_reg_write(0x49a0,dmsc_sp_d_ud_ns_opt << 0x10 | dmsc_sp_d_ns_thres_intp);
  system_reg_write(0x49a4,DAT_000c3b78 << 0x10 | dmsc_sp_ud_ns_thres_intp);
  return 0;
}



undefined4 tisp_dmsc_intp(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (int)param_1 >> 0x10;
  uVar1 = param_1 & 0xffff;
  dmsc_hv_thres_1_intp = tisp_simple_intp(uVar2,uVar1,0xc42b8);
  dmsc_hv_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc4294);
  dmsc_aa_thres_1_intp = tisp_simple_intp(uVar2,uVar1,0xc4270);
  dmsc_aa_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc424c);
  dmsc_hvaa_thres_1_intp = tisp_simple_intp(uVar2,uVar1,0xc4228);
  dmsc_hvaa_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc4204);
  dmsc_uu_thres_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_uu_thres_array_now);
  dmsc_uu_stren_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_uu_stren_array_now);
  dmsc_alias_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc4164);
  dmsc_alias_thres_1_intp = tisp_simple_intp(uVar2,uVar1,0xc4140);
  dmsc_alias_thres_2_intp = tisp_simple_intp(uVar2,uVar1,0xc411c);
  dmsc_alias_dir_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc40f8);
  dmsc_nor_alias_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc40c4);
  dmsc_sp_d_w_stren_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_sp_d_w_stren_array_now);
  dmsc_sp_d_b_stren_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_sp_d_b_stren_array_now);
  dmsc_sp_d_brig_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc4048);
  dmsc_sp_d_dark_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc4024);
  dmsc_sp_ud_w_stren_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_sp_ud_w_stren_array_now);
  dmsc_sp_ud_b_stren_intp = tisp_simple_intp(uVar2,uVar1,(int)dmsc_sp_ud_b_stren_array_now);
  dmsc_sp_ud_brig_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3efc);
  dmsc_sp_ud_dark_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3ed8);
  dmsc_sp_alias_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3da4);
  dmsc_rgb_dir_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3d78);
  dmsc_rgb_alias_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3d54);
  dmsc_fc_alias_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3d28);
  dmsc_fc_t1_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3d04);
  dmsc_fc_t1_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3ce0);
  dmsc_fc_t2_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3cbc);
  dmsc_fc_t3_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3c98);
  dmsc_deir_fusion_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3be8);
  dmsc_deir_fusion_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3bc4);
  dmsc_sp_d_v2_win5_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc4000);
  dmsc_sp_d_flat_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3fdc);
  dmsc_sp_d_flat_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3fb8);
  dmsc_sp_d_oe_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3f94);
  dmsc_sp_ud_std_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3eb4);
  dmsc_sp_ud_std_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3e90);
  dmsc_sp_ud_flat_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3e6c);
  dmsc_sp_ud_flat_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3e48);
  dmsc_sp_ud_oe_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3e24);
  dmsc_fc_lum_stren_intp = tisp_simple_intp(uVar2,uVar1,0xc3c74);
  dmsc_fc_lum_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3c50);
  dmsc_sp_d_ns_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3ba0);
  dmsc_sp_ud_ns_thres_intp = tisp_simple_intp(uVar2,uVar1,0xc3b7c);
  return 0;
}



void tisp_dmsc_wdr_en(int param_1)

{
  undefined1 *puVar1;
  
  dmsc_wdr_en = param_1;
  if (param_1 == 0) {
    dmsc_uu_thres_array_now = dmsc_uu_thres_array;
    dmsc_uu_stren_array_now = (undefined *)&dmsc_uu_stren_array;
    dmsc_sp_d_w_stren_array_now = (undefined *)&dmsc_sp_d_w_stren_array;
    dmsc_sp_d_b_stren_array_now = (undefined *)&dmsc_sp_d_b_stren_array;
    dmsc_sp_ud_w_stren_array_now = (undefined *)&dmsc_sp_ud_w_stren_array;
    puVar1 = (undefined1 *)&dmsc_sp_ud_b_stren_array;
  }
  else {
    dmsc_uu_thres_array_now = dmsc_uu_thres_wdr_array;
    dmsc_uu_stren_array_now = dmsc_uu_stren_wdr_array;
    dmsc_sp_d_w_stren_array_now = dmsc_sp_d_w_stren_wdr_array;
    dmsc_sp_d_b_stren_array_now = dmsc_sp_d_b_stren_wdr_array;
    dmsc_sp_ud_w_stren_array_now = dmsc_sp_ud_w_stren_wdr_array;
    puVar1 = dmsc_sp_ud_b_stren_wdr_array;
  }
  dmsc_sp_ud_b_stren_array_now = puVar1;
  return;
}



undefined4 tisp_dmsc_all_reg_refresh(uint param_1)

{
  tisp_dmsc_intp(param_1);
  tisp_dmsc_out_opt_cfg();
  tisp_dmsc_uu_par_cfg();
  tisp_dmsc_alias_par_cfg();
  tisp_dmsc_uu_np_cfg();
  tisp_dmsc_sp_d_sigma_3_np_cfg();
  tisp_dmsc_sp_d_w_wei_np_cfg();
  tisp_dmsc_sp_d_b_wei_np_cfg();
  tisp_dmsc_sp_ud_w_wei_np_cfg();
  tisp_dmsc_sp_ud_b_wei_np_cfg();
  tisp_dmsc_dir_par_cfg();
  tisp_dmsc_nor_par_cfg();
  tisp_dmsc_sp_d_par_cfg();
  tisp_dmsc_sp_ud_par_cfg();
  tisp_dmsc_sp_alias_par_cfg();
  tisp_dmsc_rgb_alias_par_cfg();
  tisp_dmsc_fc_par_cfg();
  tisp_dmsc_deir_par_cfg();
  tisp_dmsc_awb_gain_par_cfg();
  tisp_dmsc_deir_rgb_par_cfg();
  tisp_dmsc_d_ud_ns_par_cfg();
  system_reg_write(0x499c,1);
  return 0;
}



undefined4 tisp_dmsc_intp_reg_refresh(uint param_1)

{
  tisp_dmsc_intp(param_1);
  tisp_dmsc_uu_par_cfg();
  tisp_dmsc_alias_par_cfg();
  tisp_dmsc_dir_par_cfg();
  tisp_dmsc_nor_par_cfg();
  tisp_dmsc_sp_d_par_cfg();
  tisp_dmsc_sp_ud_par_cfg();
  tisp_dmsc_sp_alias_par_cfg();
  tisp_dmsc_rgb_alias_par_cfg();
  tisp_dmsc_fc_par_cfg();
  tisp_dmsc_deir_par_cfg();
  tisp_dmsc_d_ud_ns_par_cfg();
  return 0;
}



undefined4 tisp_dmsc_par_refresh(uint param_1,uint param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  
  if (gain_old == 0xffffffff) {
    pcVar1 = tisp_dmsc_all_reg_refresh;
  }
  else {
    uVar2 = param_1 - gain_old;
    if (param_1 < gain_old) {
      uVar2 = gain_old - param_1;
    }
    if (uVar2 < param_2) goto LAB_00036268;
    pcVar1 = tisp_dmsc_intp_reg_refresh;
  }
  gain_old = param_1;
  (*pcVar1)();
LAB_00036268:
  if (param_3 == 1) {
    system_reg_write(0x499c,1);
  }
  return 0;
}



undefined4 tisp_dmsc_refresh(uint param_1)

{
  tisp_dmsc_par_refresh(param_1,0x100,1);
  return 0;
}



undefined4 tisp_dmsc_param_array_get(undefined4 param_1,void *param_2,size_t *param_3)

{
  undefined1 *__src;
  size_t __n;
  
  switch(param_1) {
  case 0x5f:
    __src = (undefined1 *)&dmsc_uu_np_array;
    goto LAB_000366c4;
  case 0x60:
    __src = (undefined1 *)&dmsc_r_deir_array;
    goto LAB_000366d4;
  case 0x61:
    __src = (undefined1 *)&dmsc_g_deir_array;
    goto LAB_000366d4;
  case 0x62:
    __src = (undefined1 *)&dmsc_b_deir_array;
LAB_000366d4:
    __n = 0x20;
    goto LAB_000366d8;
  case 99:
    __src = (undefined1 *)&dmsc_sp_d_sigma_3_np_array;
LAB_000366c4:
    __n = 0x40;
    goto LAB_000366d8;
  case 100:
    __src = (undefined1 *)&dmsc_sp_d_w_wei_np_array;
    goto LAB_0003633c;
  case 0x65:
    __src = (undefined1 *)&dmsc_sp_d_b_wei_np_array;
    goto LAB_0003633c;
  case 0x66:
    __src = (undefined1 *)&dmsc_sp_ud_w_wei_np_array;
    goto LAB_0003633c;
  case 0x67:
    __src = (undefined1 *)&dmsc_sp_ud_b_wei_np_array;
LAB_0003633c:
    __n = 0x58;
    goto LAB_000366d8;
  case 0x68:
    __src = (undefined1 *)&dmsc_out_opt;
    __n = 4;
    goto LAB_000366d8;
  case 0x69:
    __src = dmsc_hv_thres_1_array;
    break;
  case 0x6a:
    __src = dmsc_hv_stren_array;
    break;
  case 0x6b:
    __src = dmsc_aa_thres_1_array;
    break;
  case 0x6c:
    __src = dmsc_aa_stren_array;
    break;
  case 0x6d:
    __src = dmsc_hvaa_thres_1_array;
    break;
  case 0x6e:
    __src = dmsc_hvaa_stren_array;
    break;
  case 0x6f:
    __src = (undefined1 *)&dmsc_dir_par_array;
    break;
  case 0x70:
    __src = dmsc_uu_thres_array;
    break;
  case 0x71:
    __src = (undefined1 *)&dmsc_uu_stren_array;
    break;
  case 0x72:
    __src = (undefined1 *)&dmsc_uu_par_array;
    goto LAB_00036434;
  case 0x73:
    __src = dmsc_alias_stren_array;
    break;
  case 0x74:
    __src = dmsc_alias_thres_1_array;
    break;
  case 0x75:
    __src = dmsc_alias_thres_2_array;
    break;
  case 0x76:
    __src = dmsc_alias_dir_thres_array;
    break;
  case 0x77:
    __src = (undefined1 *)&dmsc_alias_par_array;
    goto LAB_00036434;
  case 0x78:
    __src = dmsc_nor_alias_thres_array;
    break;
  case 0x79:
    __src = (undefined1 *)&dmsc_nor_par_array;
LAB_00036434:
    __n = 0x10;
    goto LAB_000366d8;
  case 0x7a:
    __src = (undefined1 *)&dmsc_sp_d_w_stren_array;
    break;
  case 0x7b:
    __src = (undefined1 *)&dmsc_sp_d_b_stren_array;
    break;
  case 0x7c:
    __src = dmsc_sp_d_brig_thres_array;
    break;
  case 0x7d:
    __src = dmsc_sp_d_dark_thres_array;
    break;
  case 0x7e:
    __src = dmsc_sp_d_v2_win5_thres_array;
    break;
  case 0x7f:
    __src = dmsc_sp_d_flat_stren_array;
    break;
  case 0x80:
    __src = dmsc_sp_d_flat_thres_array;
    break;
  case 0x81:
    __src = dmsc_sp_d_oe_stren_array;
    break;
  case 0x82:
    __src = (undefined1 *)&dmsc_sp_d_par_array;
    __n = 0x2c;
    goto LAB_000366d8;
  case 0x83:
    __src = (undefined1 *)&dmsc_sp_ud_w_stren_array;
    break;
  case 0x84:
    __src = (undefined1 *)&dmsc_sp_ud_b_stren_array;
    break;
  case 0x85:
    __src = dmsc_sp_ud_brig_thres_array;
    break;
  case 0x86:
    __src = dmsc_sp_ud_dark_thres_array;
    break;
  case 0x87:
    __src = dmsc_sp_ud_std_stren_array;
    break;
  case 0x88:
    __src = dmsc_sp_ud_std_thres_array;
    break;
  case 0x89:
    __src = dmsc_sp_ud_flat_thres_array;
    break;
  case 0x8a:
    __src = dmsc_sp_ud_flat_stren_array;
    break;
  case 0x8b:
    __src = dmsc_sp_ud_oe_stren_array;
    break;
  case 0x8c:
    __src = (undefined1 *)&dmsc_sp_ud_par_array;
    __n = 0x34;
    goto LAB_000366d8;
  case 0x8d:
    __src = (undefined1 *)&dmsc_sp_ud_v1_v2_par_array;
    goto LAB_000365cc;
  case 0x8e:
    __src = dmsc_sp_alias_thres_array;
    break;
  case 0x8f:
    __src = (undefined1 *)&dmsc_sp_alias_par_array;
    goto LAB_00036628;
  case 0x90:
    __src = dmsc_rgb_dir_thres_array;
    break;
  case 0x91:
    __src = dmsc_rgb_alias_stren_array;
    break;
  case 0x92:
    __src = (undefined1 *)&dmsc_rgb_alias_par_array;
    goto LAB_00036628;
  case 0x93:
    __src = dmsc_fc_alias_stren_array;
    break;
  case 0x94:
    __src = dmsc_fc_t1_thres_array;
    break;
  case 0x95:
    __src = dmsc_fc_t1_stren_array;
    break;
  case 0x96:
    __src = dmsc_fc_t2_stren_array;
    break;
  case 0x97:
    __src = dmsc_fc_t3_stren_array;
    break;
  case 0x98:
    __src = dmsc_fc_lum_stren_array;
    break;
  case 0x99:
    __src = dmsc_fc_lum_thres_array;
    break;
  case 0x9a:
    __src = (undefined1 *)&dmsc_fc_par_array;
LAB_000365cc:
    __n = 0x28;
    goto LAB_000366d8;
  case 0x9b:
    __src = (undefined1 *)&dmsc_deir_oe_en;
    goto LAB_00036628;
  case 0x9c:
    __src = (undefined1 *)&dmsc_deir_rgb_ir_oe_slope;
    __n = 0x14;
    goto LAB_000366d8;
  case 0x9d:
    __src = dmsc_deir_fusion_thres_array;
    break;
  case 0x9e:
    __src = dmsc_deir_fusion_stren_array;
    break;
  case 0x9f:
    __src = dmsc_sp_d_ns_thres_array;
    break;
  case 0xa0:
    __src = dmsc_sp_ud_ns_thres_array;
    break;
  case 0xa1:
    __src = (undefined1 *)&dmsc_sp_d_ud_ns_opt;
LAB_00036628:
    __n = 8;
    goto LAB_000366d8;
  case 0xa2:
    __src = dmsc_uu_thres_wdr_array;
    break;
  case 0xa3:
    __src = dmsc_uu_stren_wdr_array;
    break;
  case 0xa4:
    __src = dmsc_sp_d_w_stren_wdr_array;
    break;
  case 0xa5:
    __src = dmsc_sp_d_b_stren_wdr_array;
    break;
  case 0xa6:
    __src = dmsc_sp_ud_w_stren_wdr_array;
    break;
  case 0xa7:
    __src = dmsc_sp_ud_b_stren_wdr_array;
    break;
  case 0xa8:
    __src = (undefined1 *)&dmsc_awb_gain;
    __n = 0xc;
    goto LAB_000366d8;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 0x24;
LAB_000366d8:
  memcpy(param_2,__src,__n);
  *param_3 = __n;
  return 0;
}



undefined4 tisp_dmsc_param_array_set(undefined4 param_1,void *param_2,size_t *param_3)

{
  size_t __n;
  undefined1 *__dest;
  
  switch(param_1) {
  case 0x5f:
    __dest = (undefined1 *)&dmsc_uu_np_array;
    goto LAB_00036af4;
  case 0x60:
    __dest = (undefined1 *)&dmsc_r_deir_array;
    goto LAB_00036b04;
  case 0x61:
    __dest = (undefined1 *)&dmsc_g_deir_array;
    goto LAB_00036b04;
  case 0x62:
    __dest = (undefined1 *)&dmsc_b_deir_array;
LAB_00036b04:
    __n = 0x20;
    goto LAB_00036b08;
  case 99:
    __dest = (undefined1 *)&dmsc_sp_d_sigma_3_np_array;
LAB_00036af4:
    __n = 0x40;
    goto LAB_00036b08;
  case 100:
    __dest = (undefined1 *)&dmsc_sp_d_w_wei_np_array;
    goto LAB_0003676c;
  case 0x65:
    __dest = (undefined1 *)&dmsc_sp_d_b_wei_np_array;
    goto LAB_0003676c;
  case 0x66:
    __dest = (undefined1 *)&dmsc_sp_ud_w_wei_np_array;
    goto LAB_0003676c;
  case 0x67:
    __dest = (undefined1 *)&dmsc_sp_ud_b_wei_np_array;
LAB_0003676c:
    __n = 0x58;
    goto LAB_00036b08;
  case 0x68:
    __dest = (undefined1 *)&dmsc_out_opt;
    __n = 4;
    goto LAB_00036b08;
  case 0x69:
    __dest = dmsc_hv_thres_1_array;
    break;
  case 0x6a:
    __dest = dmsc_hv_stren_array;
    break;
  case 0x6b:
    __dest = dmsc_aa_thres_1_array;
    break;
  case 0x6c:
    __dest = dmsc_aa_stren_array;
    break;
  case 0x6d:
    __dest = dmsc_hvaa_thres_1_array;
    break;
  case 0x6e:
    __dest = dmsc_hvaa_stren_array;
    break;
  case 0x6f:
    __dest = (undefined1 *)&dmsc_dir_par_array;
    break;
  case 0x70:
    __dest = dmsc_uu_thres_array;
    break;
  case 0x71:
    __dest = (undefined1 *)&dmsc_uu_stren_array;
    break;
  case 0x72:
    __dest = (undefined1 *)&dmsc_uu_par_array;
    goto LAB_00036864;
  case 0x73:
    __dest = dmsc_alias_stren_array;
    break;
  case 0x74:
    __dest = dmsc_alias_thres_1_array;
    break;
  case 0x75:
    __dest = dmsc_alias_thres_2_array;
    break;
  case 0x76:
    __dest = dmsc_alias_dir_thres_array;
    break;
  case 0x77:
    __dest = (undefined1 *)&dmsc_alias_par_array;
    goto LAB_00036864;
  case 0x78:
    __dest = dmsc_nor_alias_thres_array;
    break;
  case 0x79:
    __dest = (undefined1 *)&dmsc_nor_par_array;
LAB_00036864:
    __n = 0x10;
    goto LAB_00036b08;
  case 0x7a:
    __dest = (undefined1 *)&dmsc_sp_d_w_stren_array;
    break;
  case 0x7b:
    __dest = (undefined1 *)&dmsc_sp_d_b_stren_array;
    break;
  case 0x7c:
    __dest = dmsc_sp_d_brig_thres_array;
    break;
  case 0x7d:
    __dest = dmsc_sp_d_dark_thres_array;
    break;
  case 0x7e:
    __dest = dmsc_sp_d_v2_win5_thres_array;
    break;
  case 0x7f:
    __dest = dmsc_sp_d_flat_stren_array;
    break;
  case 0x80:
    __dest = dmsc_sp_d_flat_thres_array;
    break;
  case 0x81:
    __dest = dmsc_sp_d_oe_stren_array;
    break;
  case 0x82:
    __dest = (undefined1 *)&dmsc_sp_d_par_array;
    __n = 0x2c;
    goto LAB_00036b08;
  case 0x83:
    __dest = (undefined1 *)&dmsc_sp_ud_w_stren_array;
    break;
  case 0x84:
    __dest = (undefined1 *)&dmsc_sp_ud_b_stren_array;
    break;
  case 0x85:
    __dest = dmsc_sp_ud_brig_thres_array;
    break;
  case 0x86:
    __dest = dmsc_sp_ud_dark_thres_array;
    break;
  case 0x87:
    __dest = dmsc_sp_ud_std_stren_array;
    break;
  case 0x88:
    __dest = dmsc_sp_ud_std_thres_array;
    break;
  case 0x89:
    __dest = dmsc_sp_ud_flat_thres_array;
    break;
  case 0x8a:
    __dest = dmsc_sp_ud_flat_stren_array;
    break;
  case 0x8b:
    __dest = dmsc_sp_ud_oe_stren_array;
    break;
  case 0x8c:
    __dest = (undefined1 *)&dmsc_sp_ud_par_array;
    __n = 0x34;
    goto LAB_00036b08;
  case 0x8d:
    __dest = (undefined1 *)&dmsc_sp_ud_v1_v2_par_array;
    goto LAB_000369fc;
  case 0x8e:
    __dest = dmsc_sp_alias_thres_array;
    break;
  case 0x8f:
    __dest = (undefined1 *)&dmsc_sp_alias_par_array;
    goto LAB_00036a58;
  case 0x90:
    __dest = dmsc_rgb_dir_thres_array;
    break;
  case 0x91:
    __dest = dmsc_rgb_alias_stren_array;
    break;
  case 0x92:
    __dest = (undefined1 *)&dmsc_rgb_alias_par_array;
    goto LAB_00036a58;
  case 0x93:
    __dest = dmsc_fc_alias_stren_array;
    break;
  case 0x94:
    __dest = dmsc_fc_t1_thres_array;
    break;
  case 0x95:
    __dest = dmsc_fc_t1_stren_array;
    break;
  case 0x96:
    __dest = dmsc_fc_t2_stren_array;
    break;
  case 0x97:
    __dest = dmsc_fc_t3_stren_array;
    break;
  case 0x98:
    __dest = dmsc_fc_lum_stren_array;
    break;
  case 0x99:
    __dest = dmsc_fc_lum_thres_array;
    break;
  case 0x9a:
    __dest = (undefined1 *)&dmsc_fc_par_array;
LAB_000369fc:
    __n = 0x28;
    goto LAB_00036b08;
  case 0x9b:
    __dest = (undefined1 *)&dmsc_deir_oe_en;
    goto LAB_00036a58;
  case 0x9c:
    __dest = (undefined1 *)&dmsc_deir_rgb_ir_oe_slope;
    __n = 0x14;
    goto LAB_00036b08;
  case 0x9d:
    __dest = dmsc_deir_fusion_thres_array;
    break;
  case 0x9e:
    __dest = dmsc_deir_fusion_stren_array;
    break;
  case 0x9f:
    __dest = dmsc_sp_d_ns_thres_array;
    break;
  case 0xa0:
    __dest = dmsc_sp_ud_ns_thres_array;
    break;
  case 0xa1:
    __dest = (undefined1 *)&dmsc_sp_d_ud_ns_opt;
LAB_00036a58:
    __n = 8;
    goto LAB_00036b08;
  case 0xa2:
    __dest = dmsc_uu_thres_wdr_array;
    break;
  case 0xa3:
    __dest = dmsc_uu_stren_wdr_array;
    break;
  case 0xa4:
    __dest = dmsc_sp_d_w_stren_wdr_array;
    break;
  case 0xa5:
    __dest = dmsc_sp_d_b_stren_wdr_array;
    break;
  case 0xa6:
    __dest = dmsc_sp_ud_w_stren_wdr_array;
    break;
  case 0xa7:
    __dest = dmsc_sp_ud_b_stren_wdr_array;
    break;
  case 0xa8:
    __dest = (undefined1 *)&dmsc_awb_gain;
    __n = 0xc;
    goto LAB_00036b08;
  default:
    isp_printf();
    return 0xffffffff;
  }
  __n = 0x24;
LAB_00036b08:
  *param_3 = __n;
  memcpy(__dest,param_2,__n);
  tisp_dmsc_all_reg_refresh(gain_old);
  return 0;
}



undefined4 tisp_dmsc_sharpness_set(byte param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  uVar1 = (uint)param_1;
  iVar5 = uVar1 - 0x80;
  piVar4 = &DAT_0009f2e0;
  iVar2 = 0;
  dmsc_ratio = param_1;
  do {
    if (uVar1 < 0x81) {
      *(uint *)((int)&dmsc_sp_d_w_stren_array + iVar2) = uVar1 * *piVar4 >> 7;
      *(uint *)((int)&dmsc_sp_d_b_stren_array + iVar2) = uVar1 * piVar4[9] >> 7;
      *(uint *)((int)&dmsc_sp_ud_w_stren_array + iVar2) = uVar1 * piVar4[0x53] >> 7;
      *(uint *)((int)&dmsc_sp_ud_b_stren_array + iVar2) = uVar1 * piVar4[0x5c] >> 7;
      *(uint *)((int)&dmsc_uu_stren_array + iVar2) = uVar1 * piVar4[-0x42] >> 7;
    }
    else {
      *(uint *)((int)&dmsc_sp_d_w_stren_array + iVar2) =
           ((uint)((0x15e - *piVar4) * iVar5) >> 7) + *piVar4;
      *(uint *)((int)&dmsc_sp_d_b_stren_array + iVar2) =
           ((uint)((0x15e - piVar4[9]) * iVar5) >> 7) + piVar4[9];
      *(uint *)((int)&dmsc_sp_ud_w_stren_array + iVar2) =
           ((uint)((400 - piVar4[0x53]) * iVar5) >> 7) + piVar4[0x53];
      *(uint *)((int)&dmsc_sp_ud_b_stren_array + iVar2) =
           ((uint)((400 - piVar4[0x5c]) * iVar5) >> 7) + piVar4[0x5c];
      *(uint *)((int)&dmsc_uu_stren_array + iVar2) =
           ((uint)((300 - piVar4[-0x42]) * iVar5) >> 7) + piVar4[-0x42];
    }
    iVar2 = iVar2 + 4;
    piVar4 = piVar4 + 1;
  } while (iVar2 != 0x24);
  uVar3 = tisp_dmsc_all_reg_refresh(gain_old);
  return uVar3;
}



undefined4 tiziano_dmsc_params_refresh(void)

{
  memcpy(&dmsc_uu_np_array,&DAT_0009ee74,0x40);
  memcpy(&dmsc_r_deir_array,&DAT_0009eeb4,0x20);
  memcpy(&dmsc_g_deir_array,&DAT_0009eed4,0x20);
  memcpy(&dmsc_b_deir_array,&DAT_0009eef4,0x20);
  memcpy(&dmsc_sp_d_sigma_3_np_array,&DAT_0009ef14,0x40);
  memcpy(&dmsc_sp_d_w_wei_np_array,&DAT_0009ef54,0x58);
  memcpy(&dmsc_sp_d_b_wei_np_array,&DAT_0009efac,0x58);
  memcpy(&dmsc_sp_ud_w_wei_np_array,&DAT_0009f004,0x58);
  memcpy(&dmsc_sp_ud_b_wei_np_array,&DAT_0009f05c,0x58);
  memcpy(&dmsc_out_opt,&DAT_0009f0b4,4);
  memcpy(dmsc_hv_thres_1_array,&DAT_0009f0b8,0x24);
  memcpy(dmsc_hv_stren_array,&DAT_0009f0dc,0x24);
  memcpy(dmsc_aa_thres_1_array,&DAT_0009f100,0x24);
  memcpy(dmsc_aa_stren_array,&DAT_0009f124,0x24);
  memcpy(dmsc_hvaa_thres_1_array,&DAT_0009f148,0x24);
  memcpy(dmsc_hvaa_stren_array,&DAT_0009f16c,0x24);
  memcpy(&dmsc_dir_par_array,&DAT_0009f190,0x24);
  memcpy(dmsc_uu_thres_array,&DAT_0009f1b4,0x24);
  memcpy(&dmsc_uu_stren_array,&DAT_0009f1d8,0x24);
  memcpy(&dmsc_uu_par_array,&DAT_0009f1fc,0x10);
  memcpy(dmsc_alias_stren_array,&DAT_0009f20c,0x24);
  memcpy(dmsc_alias_thres_1_array,&DAT_0009f230,0x24);
  memcpy(dmsc_alias_thres_2_array,&DAT_0009f254,0x24);
  memcpy(dmsc_alias_dir_thres_array,&DAT_0009f278,0x24);
  memcpy(&dmsc_alias_par_array,&DAT_0009f29c,0x10);
  memcpy(dmsc_nor_alias_thres_array,&DAT_0009f2ac,0x24);
  memcpy(&dmsc_nor_par_array,&DAT_0009f2d0,0x10);
  memcpy(&dmsc_sp_d_w_stren_array,&DAT_0009f2e0,0x24);
  memcpy(&dmsc_sp_d_b_stren_array,&DAT_0009f304,0x24);
  memcpy(dmsc_sp_d_brig_thres_array,&DAT_0009f328,0x24);
  memcpy(dmsc_sp_d_dark_thres_array,&DAT_0009f34c,0x24);
  memcpy(dmsc_sp_d_v2_win5_thres_array,&DAT_0009f370,0x24);
  memcpy(dmsc_sp_d_flat_stren_array,&DAT_0009f394,0x24);
  memcpy(dmsc_sp_d_flat_thres_array,&DAT_0009f3b8,0x24);
  memcpy(dmsc_sp_d_oe_stren_array,&DAT_0009f3dc,0x24);
  memcpy(&dmsc_sp_d_par_array,&DAT_0009f400,0x2c);
  memcpy(&dmsc_sp_ud_w_stren_array,&DAT_0009f42c,0x24);
  memcpy(&dmsc_sp_ud_b_stren_array,&DAT_0009f450,0x24);
  memcpy(dmsc_sp_ud_brig_thres_array,&DAT_0009f474,0x24);
  memcpy(dmsc_sp_ud_dark_thres_array,&DAT_0009f498,0x24);
  memcpy(dmsc_sp_ud_std_stren_array,&DAT_0009f4bc,0x24);
  memcpy(dmsc_sp_ud_std_thres_array,&DAT_0009f4e0,0x24);
  memcpy(dmsc_sp_ud_flat_thres_array,&DAT_0009f504,0x24);
  memcpy(dmsc_sp_ud_flat_stren_array,&DAT_0009f528,0x24);
  memcpy(dmsc_sp_ud_oe_stren_array,&DAT_0009f54c,0x24);
  memcpy(&dmsc_sp_ud_par_array,&DAT_0009f570,0x34);
  memcpy(&dmsc_sp_ud_v1_v2_par_array,&DAT_0009f5a4,0x28);
  memcpy(dmsc_sp_alias_thres_array,&DAT_0009f5cc,0x24);
  memcpy(&dmsc_sp_alias_par_array,&DAT_0009f5f0,8);
  memcpy(dmsc_rgb_dir_thres_array,&DAT_0009f5f8,0x24);
  memcpy(dmsc_rgb_alias_stren_array,&DAT_0009f61c,0x24);
  memcpy(&dmsc_rgb_alias_par_array,&DAT_0009f640,8);
  memcpy(dmsc_fc_alias_stren_array,&DAT_0009f648,0x24);
  memcpy(dmsc_fc_t1_thres_array,&DAT_0009f66c,0x24);
  memcpy(dmsc_fc_t1_stren_array,&DAT_0009f690,0x24);
  memcpy(dmsc_fc_t2_stren_array,&DAT_0009f6b4,0x24);
  memcpy(dmsc_fc_t3_stren_array,&DAT_0009f6d8,0x24);
  memcpy(dmsc_fc_lum_stren_array,&DAT_0009f6fc,0x24);
  memcpy(dmsc_fc_lum_thres_array,&DAT_0009f720,0x24);
  memcpy(&dmsc_fc_par_array,&DAT_0009f744,0x28);
  memcpy(&dmsc_deir_oe_en,&DAT_0009f76c,8);
  memcpy(&dmsc_deir_rgb_ir_oe_slope,&DAT_0009f774,0x14);
  memcpy(dmsc_deir_fusion_thres_array,&DAT_0009f788,0x24);
  memcpy(dmsc_deir_fusion_stren_array,&DAT_0009f7ac,0x24);
  memcpy(dmsc_sp_d_ns_thres_array,&DAT_0009f7d0,0x24);
  memcpy(dmsc_sp_ud_ns_thres_array,&DAT_0009f7f4,0x24);
  memcpy(&dmsc_sp_d_ud_ns_opt,&DAT_0009f818,8);
  memcpy(dmsc_uu_thres_wdr_array,&DAT_0009f820,0x24);
  memcpy(dmsc_uu_stren_wdr_array,&DAT_0009f844,0x24);
  memcpy(dmsc_sp_d_w_stren_wdr_array,&DAT_0009f868,0x24);
  memcpy(dmsc_sp_d_b_stren_wdr_array,&DAT_0009f88c,0x24);
  memcpy(dmsc_sp_ud_w_stren_wdr_array,&DAT_0009f8b0,0x24);
  memcpy(dmsc_sp_ud_b_stren_wdr_array,&DAT_0009f8d4,0x24);
  memcpy(&dmsc_awb_gain,&DAT_0009f8f8,0xc);
  if (dmsc_ratio != 0x80) {
    tisp_dmsc_sharpness_set(dmsc_ratio);
  }
  return 0;
}



undefined4 tiziano_dmsc_init(void)

{
  undefined1 *puVar1;
  
  if (dmsc_wdr_en == 0) {
    dmsc_uu_thres_array_now = dmsc_uu_thres_array;
    dmsc_uu_stren_array_now = (undefined *)&dmsc_uu_stren_array;
    dmsc_sp_d_w_stren_array_now = (undefined *)&dmsc_sp_d_w_stren_array;
    dmsc_sp_d_b_stren_array_now = (undefined *)&dmsc_sp_d_b_stren_array;
    dmsc_sp_ud_w_stren_array_now = (undefined *)&dmsc_sp_ud_w_stren_array;
    puVar1 = (undefined1 *)&dmsc_sp_ud_b_stren_array;
  }
  else {
    dmsc_uu_thres_array_now = dmsc_uu_thres_wdr_array;
    dmsc_uu_stren_array_now = dmsc_uu_stren_wdr_array;
    dmsc_sp_d_w_stren_array_now = dmsc_sp_d_w_stren_wdr_array;
    dmsc_sp_d_b_stren_array_now = dmsc_sp_d_b_stren_wdr_array;
    dmsc_sp_ud_w_stren_array_now = dmsc_sp_ud_w_stren_wdr_array;
    puVar1 = dmsc_sp_ud_b_stren_wdr_array;
  }
  gain_old = 0xffffffff;
  dmsc_sp_ud_b_stren_array_now = puVar1;
  tiziano_dmsc_params_refresh();
  tisp_dmsc_par_refresh(0x10000,0x10000,1);
  return 0;
}



undefined4 tiziano_dmsc_dn_params_refresh(void)

{
  gain_old = gain_old + 0x200;
  tiziano_dmsc_params_refresh();
  tisp_dmsc_all_reg_refresh(gain_old);
  return 0;
}



undefined tisp_dmsc_sharpness_get(void)

{
  return dmsc_ratio;
}



undefined4 tiziano_ccm_lut_parameter(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + 4);
  iVar3 = 0;
  do {
    if (iVar3 == 8) {
      uVar2 = *(uint *)(param_1 + 0x20);
    }
    else {
      uVar2 = *piVar4 << 0x10 | piVar4[-1];
    }
    iVar1 = iVar3 + 0x2802;
    iVar3 = iVar3 + 2;
    system_reg_write(iVar1 * 2,uVar2);
    piVar4 = piVar4 + 2;
  } while (iVar3 != 10);
  if (ccm_real == 1) {
    system_reg_write(0x5018,DAT_000ab7a8 << 0x10 | tiziano_ccm_dp_cfg << 0xc | DAT_000ab7ac);
    if (DAT_000ab7a8 == DAT_000ab7ac) {
      system_reg_write(0x501c,1);
    }
    else {
      if (DAT_000ab7ac < DAT_000ab7a8) {
        uVar2 = DAT_000ab7a8 - DAT_000ab7ac;
      }
      else {
        uVar2 = DAT_000ab7ac - DAT_000ab7a8;
      }
      system_reg_write(0x501c,0x20 / uVar2);
    }
    system_reg_write(0x5020,DAT_000ab7b4 << 0x10 | DAT_000ab7b0);
  }
  system_reg_write(0x5000,1);
  return 0;
}



void jz_isp_ccm_reg2par(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = 0;
  do {
    uVar2 = *(uint *)(param_2 + iVar1);
    puVar3 = (uint *)(param_1 + iVar1);
    if (0x1fff < uVar2) {
      uVar2 = uVar2 - 0x4000;
    }
    iVar1 = iVar1 + 4;
    *puVar3 = uVar2;
  } while (iVar1 != 0x24);
  return;
}



void jz_isp_ccm_para2reg(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = 0;
  do {
    uVar2 = *(uint *)(param_2 + iVar1);
    puVar3 = (uint *)(param_1 + iVar1);
    if ((int)uVar2 < 0) {
      uVar2 = uVar2 & 0x3fff;
    }
    iVar1 = iVar1 + 4;
    *puVar3 = uVar2;
  } while (iVar1 != 0x24);
  return;
}



void jz_isp_ccm_parameter_convert(void)

{
  jz_isp_ccm_reg2par(0xc4698,(int)tiziano_ccm_a_now);
  jz_isp_ccm_reg2par(0xc4674,(int)tiziano_ccm_t_now);
  jz_isp_ccm_reg2par(0xc4650,(int)tiziano_ccm_d_now);
  return;
}



void tiziano_ct_ccm_interpolation(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *__src;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  ct_list_37192 = param_2 + 0xaf0;
  DAT_000c474c = 0xed8 - param_2;
  DAT_000c4750 = param_2 + 0xed8;
  DAT_000c4754 = 5000 - param_2;
  if (DAT_000c4754 < param_1) {
    ct_flag_37193 = 0;
  }
  else if (DAT_000c4750 < param_1) {
    ct_flag_37193 = 1;
  }
  else if (DAT_000c474c < param_1) {
    ct_flag_37193 = 2;
  }
  else if (ct_list_37192 < param_1) {
    ct_flag_37193 = 3;
  }
  else {
    ct_flag_37193 = 4;
  }
  if (ccm_real == 0) {
    if (ct_flag_37193 == 0) {
      if (ct_flag_last_37194 == 0) {
        return;
      }
    }
    else if (((ct_flag_37193 == 2) || (ct_flag_37193 == 4)) && (ct_flag_last_37194 == ct_flag_37193)
            ) {
      return;
    }
  }
  ct_flag_last_37194 = ct_flag_37193;
  switch(ct_flag_37193) {
  case 0:
    __src = &_ccm_d_parameter;
    break;
  case 1:
    iVar4 = param_1 - DAT_000c4750;
    if (param_1 <= DAT_000c4750) {
      iVar4 = DAT_000c4750 - param_1;
    }
    uVar2 = DAT_000c4750 - DAT_000c4754;
    if (DAT_000c4750 <= DAT_000c4754) {
      uVar2 = DAT_000c4754 - DAT_000c4750;
    }
    iVar1 = 0;
    do {
      iVar3 = *(int *)((int)&_ccm_t_parameter + iVar1);
      iVar5 = *(int *)((int)&_ccm_d_parameter + iVar1);
      if (iVar5 < iVar3) {
        uVar7 = -((uint)((iVar3 - iVar5) * iVar4) / uVar2);
      }
      else {
        uVar7 = (uint)((iVar5 - iVar3) * iVar4) / uVar2;
      }
      piVar6 = (int *)((int)&ccm_parameter + iVar1);
      iVar1 = iVar1 + 4;
      *piVar6 = uVar7 + iVar3;
    } while (iVar1 != 0x24);
    goto switchD_00037884_caseD_5;
  case 2:
    __src = &_ccm_t_parameter;
    break;
  case 3:
    iVar4 = param_1 - ct_list_37192;
    if (param_1 <= ct_list_37192) {
      iVar4 = ct_list_37192 - param_1;
    }
    uVar2 = ct_list_37192 - DAT_000c474c;
    if (ct_list_37192 <= DAT_000c474c) {
      uVar2 = DAT_000c474c - ct_list_37192;
    }
    iVar1 = 0;
    do {
      iVar3 = *(int *)((int)&_ccm_a_parameter + iVar1);
      iVar5 = *(int *)((int)&_ccm_t_parameter + iVar1);
      if (iVar5 < iVar3) {
        uVar7 = -((uint)((iVar3 - iVar5) * iVar4) / uVar2);
      }
      else {
        uVar7 = (uint)((iVar5 - iVar3) * iVar4) / uVar2;
      }
      piVar6 = (int *)((int)&ccm_parameter + iVar1);
      iVar1 = iVar1 + 4;
      *piVar6 = uVar7 + iVar3;
    } while (iVar1 != 0x24);
    goto switchD_00037884_caseD_5;
  case 4:
    __src = &_ccm_a_parameter;
    break;
  default:
    goto switchD_00037884_caseD_5;
  }
  memcpy(&ccm_parameter,__src,0x24);
switchD_00037884_caseD_5:
  memcpy(&DAT_000c4764,&ccm_parameter,0x24);
  return;
}



undefined4 jz_isp_ccm(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined auStack_60 [36];
  int aiStack_3c [12];
  
  uVar1 = _ct;
  DAT_000c4740 = 100;
  uVar4 = _ev >> 10;
  if (ccm_real == 1) {
LAB_00037aa0:
    iVar2 = 0;
    iVar8 = 0;
    do {
      uVar6 = *(uint *)(cm_ev_list_now + iVar8);
      if (uVar4 <= uVar6) {
        if (-iVar2 == 0) {
          DAT_000c4744 = *(uint *)cm_sat_list_now;
        }
        else {
          iVar2 = (-iVar2 + -1) * 4;
          uVar3 = *(uint *)(cm_ev_list_now + iVar2);
          if (uVar6 == uVar3) {
            DAT_000c4744 = *(uint *)(cm_sat_list_now + iVar8);
          }
          else {
            uVar7 = *(uint *)(cm_sat_list_now + iVar2);
            uVar5 = *(uint *)(cm_sat_list_now + iVar8);
            if (uVar5 < uVar7) {
              iVar2 = uVar4 - uVar3;
              if (uVar4 <= uVar3) {
                iVar2 = uVar3 - uVar4;
              }
              uVar4 = uVar3 - uVar6;
              if (uVar3 <= uVar6) {
                uVar4 = uVar6 - uVar3;
              }
              uVar4 = -((iVar2 * (uVar7 - uVar5)) / uVar4);
            }
            else {
              iVar2 = uVar4 - uVar3;
              if (uVar4 <= uVar3) {
                iVar2 = uVar3 - uVar4;
              }
              uVar4 = uVar3 - uVar6;
              if (uVar3 <= uVar6) {
                uVar4 = uVar6 - uVar3;
              }
              uVar4 = (iVar2 * (uVar5 - uVar7)) / uVar4;
            }
            DAT_000c4744 = uVar7 + uVar4;
          }
        }
        goto LAB_00037b94;
      }
      iVar2 = iVar2 + -1;
      iVar8 = iVar2 * -4;
    } while (iVar2 != -9);
    DAT_000c4744 = *(uint *)(cm_sat_list_now + 0x20);
  }
  else {
    uVar6 = uVar4 - DAT_000c4734;
    if (uVar4 <= DAT_000c4734) {
      uVar6 = DAT_000c4734 - uVar4;
    }
    if (DAT_000c4738 < uVar6) goto LAB_00037aa0;
  }
LAB_00037b94:
  jz_isp_ccm_parameter_convert();
  if (ccm_real != 1) {
    uVar4 = uVar1 - DAT_000c473c;
    if (uVar1 <= DAT_000c473c) {
      uVar4 = DAT_000c473c - uVar1;
    }
    if (uVar4 <= DAT_000c4740) goto LAB_00037c04;
  }
  tiziano_ct_ccm_interpolation(uVar1,DAT_000c4740);
LAB_00037c04:
  cm_control(&ccm_parameter,DAT_000c4744,aiStack_3c);
  jz_is