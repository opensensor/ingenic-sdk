#define unkchar9   unsigned long long
#define unkchar10   unsigned long long
#define unkchar11   unsigned long long
#define unkchar12   unsigned long long
#define unkchar13   unsigned long long
#define unkchar14   unsigned long long
#define unkchar15   unsigned long long
#define unkchar16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

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

typedef struct Elf32_RegInfo_MIPS Elf32_RegInfo_MIPS, *PElf32_RegInfo_MIPS;

struct Elf32_RegInfo_MIPS {
    enum Elf32_GPRMask_MIPS ri_gprmask;
    int field1_0x4[4];
    int ri_gp_value;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

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

struct Elf32_Shdr {
    int sh_name;
    enum Elf_SectionHeaderType_MIPS sh_type;
    int sh_flags;
    int sh_addr;
    int sh_offset;
    int sh_size;
    int sh_link;
    int sh_info;
    int sh_addralign;
    int sh_entsize;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    int r_offset; // location to apply the relocation action
    int r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    int st_name;
    int st_value;
    int st_size;
    char st_info;
    char st_other;
    short st_shndx;
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    char e_ident_magic_num;
    char e_ident_magic_str[3];
    char e_ident_class;
    char e_ident_data;
    char e_ident_version;
    char e_ident_osabi;
    char e_ident_abiversion;
    char e_ident_pad[7];
    short e_type;
    short e_machine;
    int e_version;
    int e_entry;
    int e_phoff;
    int e_shoff;
    int e_flags;
    short e_ehsize;
    short e_phentsize;
    short e_phnum;
    short e_shentsize;
    short e_shnum;
    short e_shstrndx;
};

typedef long size_t;




void tx_isp_release_device(void);
int ** pop_buffer_fifo(int **param_1);
int tx_isp_vic_start(int param_1);
int ispvic_frame_channel_qbuf(uint param_1,int *param_2);
int ispvic_frame_channel_clearbuf(uint param_1);
int tx_isp_vic_probe(int param_1);
void dump_isp_vic_frd_open(int param_1,int param_2);
int isp_vic_frd_show(int param_1);
int tx_isp_vic_activate_subdev(uint param_1);
int vic_sensor_ops_ioctl(uint param_1,int param_2,short *param_3);
int vic_sensor_ops_sync_sensor_attr(uint param_1,int param_2);
void dump_vic_reg(int param_1);
void check_vic_error(void);
void tx_vic_enable_irq(void);
void tx_vic_disable_irq(void);
int vic_core_s_stream(uint param_1,int param_2);
int vic_core_ops_init(uint param_1,int param_2);
int tx_isp_vic_slake_subdev(uint param_1);
void vic_mdma_enable(int param_1,int param_2,int param_3,uint param_4,int param_5,char param_6);
uint isp_vic_cmd_set(int param_1,int param_2,uint param_3);
void vic_pipo_mdma_enable(int param_1);
int ispvic_frame_channel_s_stream(uint param_1,int param_2);
void vic_framedone_irq_function(int param_1);
void vic_mdma_irq_function(int param_1,int param_2);
int isp_vic_interrupt_service_routine(uint param_1);
int tx_isp_subdev_pipo(code *param_1,code **param_2);
int vic_core_ops_ioctl(int param_1,int param_2,int *param_3);
int vic_core_ops_ioctl(int param_1,int param_2,int *param_3);
int vin_s_stream(int param_1,int param_2);
int tx_isp_vin_activate_subdev(int param_1);
int tx_isp_vin_init(int param_1,int param_2);
int subdev_sensor_ops_set_input(int param_1,uint *param_2);
int tx_isp_vin_reset(int param_1);
int tx_isp_vin_probe(int param_1);
void video_input_cmd_open(int param_1,int param_2);
uint video_input_cmd_set(int param_1,uint param_2,uint param_3);
void video_input_cmd_show(int param_1,int param_2,char *param_3,int param_4);
int subdev_sensor_ops_release_all_sensor(int param_1);
int tx_isp_vin_slake_subdev(int param_1);
int isp_i2c_new_subdev_board(int param_1,int param_2);
int subdev_sensor_ops_enum_input(int param_1,int *param_2);
int subdev_sensor_ops_ioctl(int param_1,int param_2,int *param_3);
int tx_isp_csi_probe(int param_1);
void dump_isp_csi_open(int param_1,int param_2);
int isp_csi_show(int param_1);
int csi_core_ops_init(uint param_1,int param_2);
int csi_sensor_ops_ioctl(uint param_1,int param_2);
int csi_sensor_ops_sync_sensor_attr(uint param_1,int param_2);
int tx_isp_csi_activate_subdev(uint param_1);
int csi_video_s_stream(uint param_1,int param_2);
int tx_isp_csi_slake_subdev(uint param_1);
int dump_csi_reg(int param_1);
void check_csi_error(void);
int csi_set_on_lanes(int param_1,uint param_2);
int isp_core_tunning_open(int param_1,int param_2);
int isp_core_tunning_release(int param_1,int param_2);
int apical_isp_hvflip_update(int param_1,uint param_2);
int apical_isp_mask_s_attr.isra.29(int param_1);
int apical_isp_gamma_s_attr.isra.34(int param_1);
int apical_isp_expr_s_ctrl.isra.35(int param_1,int param_2);
int apical_isp_ae_s_roi.isra.36(int *param_1);
int apical_isp_ae_zone_weight_s_attr.isra.47(int *param_1);
int apical_isp_af_hist_s_attr.isra.50(int param_1);
int apical_isp_af_weight_s_attr.isra.51(int *param_1);
int apical_isp_core_ops_s_ctrl(int *param_1,uint *param_2);
int apical_isp_mask_g_attr.isra.68(int *param_1);
int apical_isp_expr_g_ctrl.isra.72(int *param_1);
int apical_isp_max_again_g_ctrl.isra.73(int *param_1);
int apical_isp_max_dgain_g_ctrl.isra.74(int *param_1);
int apical_isp_ev_g_attr.isra.75(int *param_1);
int apical_isp_gamma_g_attr.isra.76(int *param_1);
int apical_isp_ae_g_roi.isra.77(int *param_1);
int apical_isp_ae_zone_g_ctrl.isra.84(int *param_1);
int apical_isp_af_zone_g_ctrl.isra.85(int *param_1);
int apical_isp_ae_zone_weight_g_attr.isra.89(int *param_1);
int apical_isp_ae_hist_origin_g_attr.isra.92(int *param_1);
int apical_isp_awb_zone_statis_g_attr.isra.94(int *param_1);
int apical_isp_af_hist_g_attr.isra.95(int *param_1);
int apical_isp_af_weight_g_attr.isra.96(int *param_1);
int tiziano_isp_ae_manual_attr_g_ctrl.isra.103(int *param_1);
int tiziano_isp_csc_g_attr.isra.108(int *param_1);
int isp_frame_done_wait(uint param_1,int *param_2);
int apical_isp_core_ops_g_ctrl(int *param_1,uint *param_2);
int isp_core_tunning_unlocked_ioctl(int param_1,int param_2,int param_3);
void isp_frame_done_wakeup(void);
int isp_core_tuning_event(int param_1,uint param_2);
int * isp_core_tuning_init(int param_1);
void isp_core_tuning_deinit(int param_1);
uint private_math_exp2(uint param_1,uint param_2,uint param_3);
void private_clk_enable(void);
void private_clk_disable(void);
void private_clk_put(void);
void private_clk_set_rate(void);
void private_i2c_transfer(void);
void private_i2c_del_driver(void);
void private_i2c_get_clientdata(void);
void private_i2c_set_clientdata(void);
void private_i2c_add_driver(int param_1);
void private_gpio_request(void);
void private_gpio_free(void);
void private_gpio_direction_output(void);
void private_jzgpio_set_func(void);
void private_msleep(void);
void private_capable(void);
int private_driver_get_interface(void);
char private_leading_one_position(uint param_1);
uint private_log2_int_to_fixed(uint param_1,uint param_2,uint param_3);
int private_log2_fixed_to_fixed(int param_1,int param_2,uint param_3);
int private_leading_one_position_64(uint param_1,uint param_2);
uint private_log2_int_to_fixed_64(uint param_1,uint param_2,uint param_3,uint param_4);
int private_log2_fixed_to_fixed_64(int param_1,int param_2,int param_3,uint param_4);
void private_platform_driver_register(void);
void private_platform_driver_unregister(void);
void private_platform_set_drvdata(void);
void private_platform_get_drvdata(int param_1);
void private_platform_device_register(void);
void private_platform_device_unregister(void);
void private_platform_get_resource(void);
void private_dev_set_drvdata(void);
void private_dev_get_drvdata(void);
void private_platform_get_irq(void);
void private_request_mem_region(void);
void private_release_mem_region(void);
void private_ioremap(void);
void private_iounmap(void);
void private_request_threaded_irq(void);
void private_enable_irq(void);
void private_disable_irq(void);
void private_free_irq(void);
void __private_spin_lock_irqsave(void);
void private_spin_unlock_irqrestore(void);
void private_spin_lock_init(void);
void private_mutex_lock(void);
void private_mutex_unlock(void);
void private_raw_mutex_init(void);
void private_clk_get(void);
void private_clk_is_enabled(void);
void private_clk_get_rate(void);
void private_i2c_get_adapter(void);
void private_i2c_put_adapter(void);
void private_i2c_register_driver(void);
void private_i2c_new_device(void);
void private_i2c_unregister_device(void);
void private_gpio_direction_input(void);
void private_gpio_set_debounce(void);
void private_jzgpio_ctrl_pull(void);
void private_sched_clock(void);
void private_try_module_get(void);
void private_request_module(int param_1,int param_2,int param_3,int param_4);
void private_module_put(void);
void private_init_completion(void);
void private_complete(void);
void private_wait_for_completion_interruptible(void);
void private_wait_event_interruptible(void);
void private_wake_up_all(void);
void private_wake_up(void);
void private_init_waitqueue_head(void);
void private_wait_for_completion_timeout(void);
void private_misc_register(void);
void private_misc_deregister(void);
void private_proc_create_data(int param_1,short param_2);
void private_seq_read(void);
void private_seq_lseek(void);
void private_single_release(void);
void private_single_open_size(void);
void private_jz_proc_mkdir(void);
void private_proc_remove(void);
void private_seq_printf(int param_1,int param_2,int param_3,int param_4);
void private_simple_strtoull(void);
void private_kthread_should_stop(void);
void private_kthread_run(void);
void private_kthread_stop(void);
void private_kmalloc(void);
void private_kfree(void);
void private_copy_from_user(void);
void private_copy_to_user(void);
void private_nlmsg_new(void);
void private_nlmsg_put(void);
void private_netlink_unicast(void);
void private_netlink_kernel_create(void);
void private_sock_release(void);
void private_filp_open(int param_1,int param_2,short param_3);
void private_filp_close(void);
void private_vfs_read(void);
void private_vfs_write(void);
void private_vfs_llseek(void);
int private_get_fs(int param_1);
void private_set_fs(void);
void private_dma_cache_sync(void);
void private_getrawmonotonic(void);
void private_get_init_net(void);
void private_get_isp_priv_mem(void);
char * find_new_buffer(void);
void isp_mem_init(void);
int isp_malloc_buffer(int param_1);
void isp_free_buffer(int param_1);
int isp_printf(void);
int get_isp_clk(void);
int private_vmalloc(void);
void private_vfree(void);
void private_ktime_set(int *param_1);
void private_set_current_state(void);
int private_schedule_hrtimeout(void);
int private_schedule_work(void);
void private_do_gettimeofday(void);
void private_dma_sync_single_for_device(void);
int private_get_driver_interface(void);
int * FUN_00019bc4(int *param_1);
int private_devm_clk_get(void);
int private_clk_prepare_enable(void);
void private_clk_disable_unprepare(void);
void private_devm_clk_put(void);
int isp_irq_handle(int param_1,int param_2);
int isp_irq_thread_handle(int param_1,int param_2);
void tx_isp_enable_irq(int *param_1);
void tx_isp_disable_irq(int *param_1);
int tx_isp_request_irq(int *param_1,int *param_2);
void tx_isp_free_irq(int *param_1);
int fs_activate_module(uint param_1);
int __enqueue_in_driver(int param_1);
void __vb2_queue_cancel(uint param_1);
void __vb2_queue_free(int param_1,int param_2);
void dump_isp_framesource_open(int param_1,int param_2);
int isp_framesource_show(int param_1);
void __fill_v4l2_buffer(void *param_1,void *param_2);
int frame_chan_event(int *param_1,int param_2,int param_3);
int frame_channel_open(int param_1,int param_2);
int frame_channel_vidioc_set_fmt(uint param_1,int param_2);
int frame_channel_vidioc_get_fmt(uint param_1,int param_2);
uint check_state(int param_1);
int __frame_channel_vb2_streamoff(int param_1,int param_2);
int fs_slake_module(uint param_1);
int frame_channel_release(int param_1,int param_2);
uint frame_channel_unlocked_ioctl(int param_1,uint param_2,uint param_3);
void tx_isp_frame_chan_deinit(uint param_1);
int tx_isp_fs_probe(int param_1);
void sensor_alloc_analog_gain(int param_1,short *param_2);
void sensor_alloc_analog_gain_short(int param_1,int param_2);
void sensor_alloc_digital_gain(int param_1,int param_2);
int sensor_alloc_integration_time(int param_1,int param_2);
int sensor_alloc_integration_time_short(int param_1,int param_2);
void sensor_set_integration_time(uint param_1);
void sensor_set_integration_time_short(uint param_1);
void sensor_set_analog_gain(int param_1);
void sensor_set_analog_gain_short(int param_1);
void sensor_set_digital_gain(int param_1);
uint sensor_get_normal_fps(void);
int sensor_read_black_pedestal(void);
void sensor_end_changes(void);
short sensor_get_id(void);
void sensor_set_wdr_mode(void);
int sensor_fps_control(int param_1,int param_2);
void sensor_disable_isp(void);
int sensor_get_lines_per_second(void);
void sensor_set_mode(char param_1,char *param_2);
void sensor_start_changes(void);
void sensor_hw_reset_enable(void);
void sensor_hw_reset_disable(void);
void sensor_init(int param_1);
int sensor_early_init(int param_1);
int tx_isp_video_s_stream(int param_1,int param_2);
int tx_isp_video_link_stream(int param_1,int param_2);
int tx_isp_open(int param_1,int param_2);
int tx_isp_notify(int param_1,uint param_2,int param_3);
int find_subdev_link_pad(int param_1,char **param_2);
int isp_subdev_release_clks(int param_1);
uint isp_subdev_init_clks(int param_1,int *param_2);
void tx_isp_unregister_platforms(int *param_1);
void tx_isp_exit(void);
int subdev_video_destroy_link(int *param_1);
int tx_isp_video_link_destroy.isra.5(int param_1);
int tx_isp_release(int param_1,int param_2);
int tx_isp_init(void);
int tx_isp_get_ae_algo_handle.isra.16(int param_1,int param_2);
int tx_isp_unlocked_ioctl(int param_1,uint param_2,int param_3);
int private_reset_tx_isp_module(int param_1);
int tx_isp_reg_set(int param_1,int param_2,uint param_3,int param_4,int param_5);
int tx_isp_send_event_to_remote(int param_1);
int tx_isp_module_init(int *param_1,void *param_2);
void tx_isp_module_deinit(void *param_1);
int tx_isp_subdev_init(int *param_1,int param_2,int param_3);
void tx_isp_subdev_deinit(int param_1);
int tx_isp_create_graph_and_nodes(int param_1);
int tx_isp_probe(int param_1);
int * FUN_000202e4(int *param_1);
uint tisp_math_exp2(uint param_1,uint param_2,uint param_3);
void fix_point_add(void);
void fix_point_sub(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6);
void fix_point_mult2(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6);
void fix_point_mult3(int param_1);
void fix_point_add_64(void);
void fix_point_sub_64(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6);
void fix_point_mult2_64(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6);
void fix_point_mult3_64(int param_1);
uint64_t fix_point_div_64(int param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6);
void fix_point_div(void);
int fix_point_add_32(int param_1,int param_2,int param_3);
int fix_point_sub_32(int param_1,uint param_2,uint param_3);
int fix_point_mult2_32(uint param_1,uint param_2,uint param_3);
void fix_point_mult3_32(int param_1,int param_2,int param_3,int param_4);
uint fix_point_div_32(int param_1,uint param_2,uint param_3);
int fix_point_intp(uint param_1,uint param_2,uint param_3,int param_4,int param_5);
int table_intp(int param_1,int *param_2,uint param_3,uint param_4);
int tisp_simple_intp(uint param_1,int param_2,int param_3);
uint tisp_log2_int_to_fixed(uint param_1,uint param_2,uint param_3);
int tisp_log2_fixed_to_fixed(int param_1,int param_2,uint param_3);
uint tisp_log2_int_to_fixed_64(uint param_1,uint param_2,uint param_3,uint param_4);
int tisp_log2_fixed_to_fixed_64(int param_1,int param_2,int param_3,uint param_4);
void netlink_rcv_msg(int param_1);
int netlink_send_msg(void *param_1,uint param_2);
int tisp_netlink_event_set_cb(int param_1);
int tisp_netlink_init(void);
void tisp_netlink_exit(void);
bool isp_tunning_poll(int param_1,code **param_2);
int tisp_code_tuning_release(void);
int tisp_param_operate_process(int *param_1);
uint isp_tunning_read(int param_1,uint param_2,uint param_3);
int tisp_code_tuning_open(void);
int tisp_top_param_array_get(void *param_1,int *param_2);
int tisp_get_ae_info(int param_1);
int tisp_set_ae_info(int param_1);
int tisp_get_awb_info(int param_1);
int tisp_set_awb_info(int param_1);
int tisp_reg_map_get(int param_1,int param_2,int *param_3);
int tisp_reg_map_set(int param_1);
int tisp_dn_mode_get(int param_1,int *param_2);
int tisp_dn_mode_set(int param_1);
int tisp_blc_get_par_cfg(int param_1,int *param_2);
int tisp_blc_set_par_cfg(int param_1);
int tisp_lsc_get_par_cfg(int param_1,int *param_2);
int tisp_lsc_set_par_cfg(int param_1,int param_2);
int tisp_wdr_get_par_cfg(int param_1,int *param_2);
int tisp_wdr_set_par_cfg(int param_1);
int tisp_dpc_get_par_cfg(int param_1,int *param_2);
int tisp_dpc_set_par_cfg(int param_1);
int tisp_gib_get_par_cfg(int param_1,int *param_2);
int tisp_gib_set_par_cfg(int param_1);
int tisp_rdns_get_par_cfg(int param_1,int *param_2);
int tisp_rdns_set_par_cfg(int param_1);
int tisp_adr_get_par_cfg(int param_1,int *param_2);
int tisp_adr_set_par_cfg(int param_1);
int tisp_dmsc_get_par_cfg(int param_1,int *param_2);
int tisp_dmsc_set_par_cfg(int param_1);
int tisp_ccm_get_par_cfg(int param_1,int *param_2);
int tisp_ccm_set_par_cfg(int param_1);
int tisp_gamma_get_par_cfg(int param_1,int *param_2);
int tisp_gamma_set_par_cfg(int param_1);
int tisp_defog_get_par_cfg(int param_1,int *param_2);
int tisp_defog_set_par_cfg(int param_1);
int tisp_mdns_get_par_cfg(int param_1,int *param_2);
int tisp_mdns_set_par_cfg(int param_1);
int tisp_ydns_get_par_cfg(int param_1,int *param_2);
int tisp_ydns_set_par_cfg(int param_1);
int tisp_bcsh_get_par_cfg(int param_1,int *param_2);
int tisp_bcsh_set_par_cfg(int param_1);
int tisp_clm_get_par_cfg(int param_1,int *param_2);
int tisp_clm_set_par_cfg(int param_1);
int tisp_ysp_get_par_cfg(int param_1,int *param_2);
int tisp_ysp_set_par_cfg(int param_1);
int tisp_sdns_get_par_cfg(int param_1,int *param_2);
int tisp_sdns_set_par_cfg(int param_1);
int tisp_af_get_par_cfg(int param_1,int *param_2);
int tisp_af_set_par_cfg(int param_1);
int tisp_hldc_get_par_cfg(int param_1,int *param_2);
int tisp_hldc_set_par_cfg(int param_1);
int tisp_ae_get_par_cfg(int param_1,int *param_2);
int tisp_ae_set_par_cfg(int param_1);
int tisp_awb_get_par_cfg(int param_1,int *param_2);
int tisp_awb_set_par_cfg(int param_1);
int tisp_code_tuning_ioctl(int param_1,uint param_2,uint param_3);
int tisp_code_create_tuning_node(void);
int tisp_param_operate_init(void);
void tisp_code_destroy_tuning_node(void);
int tisp_param_operate_deinit(void);
int tisp_again_update(void);
int tisp_tgain_update(int param_1,int param_2);
int tisp_ev_update(int param_1,int param_2);
int tisp_ct_update(int param_1,int param_2);
int tisp_ae_ir_update(void);
int ip_done_interrupt_static(void);
int tisp_deinit(void);
int tisp_fw_process(void);
int tisp_channel_start(uint param_1);
int tisp_channel_stop(uint param_1);
int tisp_channel_fifo_clear(int param_1);
int tisp_channel_attr_set(int param_1,int *param_2);
int tiziano_load_parameters(char *param_1);
int tisp_init(int *param_1,char *param_2);
int tiziano_sync_sensor_attr(int *param_1);
int tisp_event_init(void);
int tisp_event_set_cb(int param_1,int param_2);
int tisp_event_push(int param_1);
int tisp_event_exit(void);
int tisp_event_process(void);
void JZ_Isp_Awb_Reg2par(uint *param_1,uint *param_2);
void JZ_Isp_Awb_Awbg2reg(int *param_1,uint *param_2);
void JZ_Isp_Get_Awb_Statistics(uint *param_1,uint param_2);
int tisp_awb_ev_update(int param_1);
int tiziano_awb_params_refresh(void);
int tiziano_awb_dump(void);
void system_reg_write_awb(int param_1,int param_2,int param_3);
void Tiziano_awb_set_gain(int param_1,uint param_2,int *param_3);
void Tiziano_awb_fpga(int param_1,int param_2,int param_3,int param_4,uint *param_5,int *param_6,int param_7,uint param_8,int *param_9,uint *param_10,int param_11,int param_12,int param_13);
int JZ_Isp_Awb(void);
int tiziano_awb_set_lum_th_freq(void);
int awb_interrupt_static(void);
int tiziano_awb_set_hardware_param(void);
int tiziano_awb_dn_params_refresh(void);
int tiziano_awb_init(uint param_1,uint param_2);
int tisp_g_wb_mode(void *param_1);
void tisp_awb_set_frz(uint param_1);
void tisp_awb_get_frz(char *param_1);
int tisp_s_wb_mode(int param_1,int param_2,int param_3);
void tisp_awb_get_ct(int *param_1);
void tisp_awb_set_ct(int *param_1);
void tiziano_s_awb_start(uint param_1,int param_2);
void tiziano_g_awb_start(int *param_1);
int tiziano_s_wb_algo(int param_1);
int tisp_awb_get_zone(void *param_1);
int tisp_awb_set_cluster_awb_params(int param_1,int param_2,int param_3,int param_4);
int tisp_awb_get_cluster_awb_params(int *param_1);
int tisp_awb_set_ct_trend(int param_1,int param_2,int param_3,int param_4);
int tisp_awb_get_ct_trend(int param_1);
int tisp_awb_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_awb_param_array_set(int param_1,void *param_2,int *param_3);
void tisp_awb_algo_init(int param_1);
void tisp_awb_algo_handle(int param_1);
int tisp_awb_deinit(void);
int ISPAWBInterpolation1(uint param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6);
int ISPAWBInterpolation2(uint param_1,int param_2,int param_3,int param_4,uint param_5,uint param_6);
uint func_zone_ct_weight(uint param_1,uint *param_2,int param_3,uint param_4,int param_5,int param_6,int param_7);
void Tiziano_Awb_Ct_Detect(uint *param_1,uint *param_2,int *param_3,uint *param_4,int *param_5,uint **param_6,int param_7,uint *param_8,uint *param_9,int *param_10,int *param_11,int param_12,int param_13,int *param_14,uint *param_15,char *param_16,uint *param_17,int *param_18,uint *param_19,int *param_20);
int subsection_map(int param_1,int param_2,int param_3,short *param_4,int param_5,int *param_6,int param_7,uint param_8,uint param_9,int param_10);
void subsection(int *param_1,int param_2,int param_3,short *param_4,int param_5,int param_6,uint param_7,int param_8,int param_9);
void subsection_up(int *param_1,int param_2,int *param_3,int param_4);
void subsection_light(int *param_1,int *param_2,int param_3,int *param_4);
int interpolate_adr_x8_y12(int param_1,int param_2,int param_3,int param_4,int param_5);
void Tiziano_adr_fpga(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int **param_6,int *param_7,int *param_8,int param_9,int *param_10,int param_11,int param_12,int *param_13,int *param_14,int *param_15,int *param_16);
void cm_control(int *param_1,int param_2,int *param_3);
int minFun(int param_1,int param_2);
int maxFun(int param_1,int param_2);
int Log2(int param_1);
int absFun(int param_1,int param_2);
int getVar(int param_1);
void wdr_detail_para_rgb(int *param_1,int *param_2,int *param_3);
void Tiziano_wdr_fpga(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,int *param_7,int *param_8,int *param_9,int *param_10,int *param_11,int *param_12,int *param_13,int *param_14,int *param_15,int *param_16,int *param_17,int *param_18,int *param_19,int *param_20,int *param_21,int *param_22,int *param_23,int *param_24,int param_25,int *param_26,int *param_27,int *param_28,int param_29,int *param_30);
int tiziano_gamma_lut_parameter(void);
int tiziano_gamma_params_refresh(void);
int tisp_gamma_wdr_en(int param_1);
int tiziano_gamma_dn_params_refresh(void);
int tiziano_gamma_init(void);
int tisp_gamma_param_array_get(int param_1,void *param_2,int *param_3);
int tisp_gamma_param_array_set(int param_1,void *param_2,int *param_3);
void system_reg_write_gib(int param_1,int param_2,int param_3);
int tisp_gib_gain_interpolation(uint param_1);
int tiziano_gib_lut_parameter(void);
int tiziano_gib_params_refresh(void);
int tiziano_gib_dn_params_refresh(void);
void tiziano_gib_deir_reg(int param_1,int param_2,int param_3);
void tiziano_gib_deir_interpolate(uint *param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6);
void tiziano_gib_deir_ir_interpolation(uint param_1);
int tisp_gib_deir_ir_update(uint param_1);
int tiziano_gib_init(void);
int tisp_gib_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_gib_param_array_set(int param_1,void *param_2,int *param_3);
void system_reg_write_gb(int param_1,int param_2,int param_3);
int tisp_gb_blc_again_interp(uint param_1,int param_2);
int tisp_gb_init_reg(void);
int tisp_gb_params_refresh(void);
int tisp_gb_dn_params_refresh(void);
int tisp_gb_init(void);
int tisp_gb_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_gb_param_array_set(int param_1,void *param_2,int *param_3);
void tisp_lsc_wdr_en(int param_1);
int tisp_lsc_ct_update(int param_1);
int tisp_lsc_gain_update(int param_1);
int tiziano_lsc_params_refresh(void);
int tiziano_lsc_dn_params_refresh(void);
int tisp_lsc_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_lsc_judge_ct_update_flag(void);
bool tisp_lsc_judge_gain_update_flag(void);
int tisp_lsc_write_lut_datas(void);
int tiziano_lsc_init(void);
int tisp_lsc_param_array_set(int param_1,void *param_2,size_t *param_3);
int tisp_lsc_upside_down_lut(void *param_1,int param_2,int param_3);
void tisp_lsc_lut_mirror_exchange(int param_1,int param_2,int param_3,int param_4,int param_5);
int tisp_lsc_mirror_flip(int param_1,int param_2,int param_3,int param_4);
int tisp_dmsc_out_opt_cfg(void);
int tisp_dmsc_uu_par_cfg(void);
int tisp_dmsc_alias_par_cfg(void);
int tisp_dmsc_uu_np_cfg(void);
int tisp_dmsc_sp_d_sigma_3_np_cfg(void);
int tisp_dmsc_sp_d_w_wei_np_cfg(void);
int tisp_dmsc_sp_d_b_wei_np_cfg(void);
int tisp_dmsc_sp_ud_w_wei_np_cfg(void);
int tisp_dmsc_sp_ud_b_wei_np_cfg(void);
int tisp_dmsc_dir_par_cfg(void);
int tisp_dmsc_nor_par_cfg(void);
int tisp_dmsc_sp_d_par_cfg(void);
int tisp_dmsc_sp_ud_par_cfg(void);
int tisp_dmsc_sp_alias_par_cfg(void);
int tisp_dmsc_rgb_alias_par_cfg(void);
int tisp_dmsc_fc_par_cfg(void);
int tisp_dmsc_deir_par_cfg(void);
int tisp_dmsc_awb_gain_par_cfg(void);
int tisp_dmsc_deir_rgb_par_cfg(void);
int tisp_dmsc_d_ud_ns_par_cfg(void);
int tisp_dmsc_intp(uint param_1);
void tisp_dmsc_wdr_en(int param_1);
int tisp_dmsc_all_reg_refresh(void);
int tisp_dmsc_intp_reg_refresh(void);
int tisp_dmsc_par_refresh(uint param_1,uint param_2,int param_3);
int tisp_dmsc_refresh(int param_1);
int tisp_dmsc_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_dmsc_param_array_set(int param_1,void *param_2,size_t *param_3);
int tisp_dmsc_sharpness_set(char param_1);
int tiziano_dmsc_params_refresh(void);
int tiziano_dmsc_dn_params_refresh(void);
int tiziano_dmsc_init(void);
char tisp_dmsc_sharpness_get(void);
int tiziano_ccm_lut_parameter(int param_1);
void jz_isp_ccm_reg2par(uint *param_1,uint *param_2);
void jz_isp_ccm_para2reg(uint *param_1,uint *param_2);
void jz_isp_ccm_parameter_convert(void);
void tiziano_ct_ccm_interpolation(uint param_1,int param_2);
int jz_isp_ccm(void);
int tisp_ccm_ev_update(uint param_1);
int tisp_ccm_ct_update(uint param_1);
int tiziano_ccm_params_refresh(void);
int tisp_ccm_wdr_en(int param_1);
int tiziano_ccm_dn_params_refresh(void);
int tiziano_ccm_init(void);
void tisp_ccm_get_attr(void *param_1);
int tisp_ccm_set_attr(void *param_1);
int tisp_ccm_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_ccm_param_array_set(int param_1,void *param_2,size_t *param_3);
uint tiziano_bcsh_StrenCal.part.0(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5);
void tiziano_bcsh_dump2(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,int *param_7,int *param_8,int *param_9,int *param_10,int *param_11,int *param_12,int *param_13,int *param_14,int *param_15,int *param_16,int *param_17,int *param_18,int *param_19);
int tiziano_bcsh_lut_parameter(int *param_1,int *param_2,int *param_3,uint *param_4,int *param_5,uint *param_6,int *param_7,uint *param_8,int *param_9,uint *param_10,int *param_11,int *param_12,uint *param_13,uint *param_14,int *param_15,uint *param_16,int *param_17,uint *param_18,int *param_19);
void tiziano_bcsh_reg2para(uint *param_1,uint *param_2);
void tiziano_bcsh_para2reg(uint *param_1,uint *param_2);
void tiziano_bcsh_Tccm_Comp2Orig(void);
void tiziano_ct_bcsh_interpolation(uint param_1);
void tiziano_bcsh_Tccm_RGBYUV(int *param_1,int *param_2,int *param_3,int *param_4);
void tiziano_bcsh_Tccm_RGB2YUV(int param_1,int param_2);
void tiziano_bcsh_Toffset_RGBYUV(int *param_1,int *param_2,int *param_3);
void tiziano_bcsh_Toffset_RGB2YUV(int *param_1,int *param_2);
uint tiziano_bcsh_StrenCal(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6);
void tiziano_bcsh_TransitParam(void);
int tiziano_bcsh_update(void);
int tisp_bcsh_ev_update(uint param_1);
int tisp_bcsh_ct_update(uint param_1);
int tisp_bcsh_wdr_en(int param_1);
void tiziano_bcsh_dump(void);
int tiziano_bcsh_params_refresh(void);
int tiziano_bcsh_dn_params_refresh(void);
int tiziano_bcsh_init(void);
int tisp_bcsh_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_bcsh_param_array_set(int param_1,int *param_2,size_t *param_3);
int tisp_bcsh_set_mjpeg_contrast(char param_1,char param_2,char param_3);
int tisp_bcsh_contrast(char param_1);
int tisp_bcsh_saturation(char param_1);
int tisp_bcsh_brightness(char param_1);
int tisp_bcsh_s_hue(char param_1);
void tisp_bcsh_g_hue(char *param_1);
char tisp_bcsh_g_brightness(void);
char tisp_bcsh_g_saturation(void);
char tisp_bcsh_g_contrast(void);
void tisp_bcsh_get_attr(void *param_1);
int tisp_bcsh_set_attr(void *param_1);
int tisp_bcsh_s_rgb_coefft(ushort *param_1);
void tisp_bcsh_g_rgb_coefft(short *param_1);
int tisp_sharpen_intp(uint param_1);
int tisp_y_sp_sl_exp_cfg(void);
int tisp_y_sp_std_scope_cfg(void);
int tisp_y_sp_uu_cfg(void);
int tisp_y_sp_fl_thres_cfg(void);
int tisp_y_sp_v1_v2_coef_cfg(void);
int tisp_y_sp_w_b_ll_cfg(void);
int tisp_y_sp_uu_w_b_wei_cfg(void);
int tisp_y_sp_w_b_sl_cfg(void);
int tisp_y_sp_uu_fl_sl_cfg(void);
void tisp_sharpen_wdr_en(int param_1);
int tisp_sharpen_all_reg_refresh(void);
int tisp_sharpen_intp_reg_refresh(void);
int tisp_sharpen_par_refresh(uint param_1,uint param_2,int param_3);
int tiziano_sharpen_params_refresh(void);
int tiziano_sharpen_init(void);
int tisp_sharpen_refresh(int param_1);
int tiziano_sharpen_dn_params_refresh(void);
int tisp_sharpen_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_sharpen_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_sdns_grad_thres_opt_cfg(void);
int tisp_sdns_h_mv_wei_opt_cfg(void);
int tisp_sdns_mv_seg_number_num_thres_cfg(void);
int tisp_sdns_g_det_val_div_cfg(void);
int tisp_sdns_r_s_mv_cfg(void);
int tisp_sdns_h_s_cfg(void);
int tisp_sdns_h_mv_cfg(void);
int tisp_sdns_dark_light_tt_opt_cfg(void);
int tisp_sdns_d_s1_thres_cfg(void);
int tisp_sdns_w_thres_cfg(void);
int tisp_sdns_hls_en_ave_filter_cfg(void);
int tisp_sdns_gaussian_y_cfg(void);
int tisp_sdns_gaussian_x_cfg(void);
int tisp_sdns_gaussian_k_cfg(void);
int tisp_sdns_h_line_cfg(void);
int tisp_sdns_sp_std_en_seg_opt_cfg(void);
int tisp_sdns_sp_uu_cfg(void);
int tisp_sdns_sp_v2_d_w_b_ll_hl_flat_cfg(void);
int tisp_sdns_sp_ud_v2_v1_coef_w_wei_opt_cfg(void);
int tisp_sdns_sp_ud_w_stren_cfg(void);
int tisp_sdns_sp_ud_w_limit_b_wei_opt_cfg(void);
int tisp_sdns_sp_ud_b_stren_cfg(void);
int tisp_sdns_sp_ud_b_limit_srd_ll_hl_flat_cfg(void);
int tisp_sdns_sp_ud_stren_shift_opt_cfg(void);
int tisp_sdns_sp_uu_np_array_cfg(void);
int tisp_sdns_sp_d_w_wei_np_array_cfg(void);
int tisp_sdns_sp_d_b_wei_np_array_cfg(void);
int tisp_sdns_sp_ud_w_wei_np_array_cfg(void);
int tisp_sdns_sp_ud_b_wei_np_array_cfg(void);
int tisp_sdns_intp(uint param_1);
int tisp_sdns_all_reg_refresh(void);
int tisp_sdns_intp_reg_refresh(void);
int tisp_sdns_par_refresh(uint param_1,uint param_2,int param_3);
int tisp_sdns_refresh(int param_1);
int tisp_sdns_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_sdns_param_array_set(int param_1,void *param_2,size_t *param_3);
int tisp_s_sdns_ratio(uint param_1);
int tisp_sdns_wdr_en(int param_1);
int tiziano_sdns_params_refresh(void);
int tiziano_sdns_init(void);
int tiziano_sdns_dn_params_refresh(void);
int tisp_mdns_top_func_cfg(int param_1);
int tisp_mdns_y_3d_param_cfg(void);
int tisp_mdns_y_2d_param_cfg(void);
int tisp_mdns_c_3d_param_cfg(void);
int tisp_mdns_c_2d_param_cfg(void);
int tisp_mdns_intp(uint param_1);
int tisp_mdns_all_reg_refresh(void);
int tisp_mdns_top_func_refresh(void);
int tisp_mdns_reg_trigger(void);
int tisp_mdns_intp_reg_refresh(void);
int tisp_mdns_par_refresh(uint param_1,uint param_2);
int tisp_mdns_bypass(int param_1);
int tisp_mdns_refresh(int param_1);
int tisp_mdns_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_mdns_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_s_mdns_ratio(uint param_1);
int tisp_mdns_wdr_en(int param_1);
int tiziano_mdns_params_refresh(void);
int tiziano_mdns_dn_params_refresh(void);
int tiziano_mdns_init(int param_1,int param_2);
int tisp_ctr_md_np_cfg(void);
int tisp_ctr_std_np_cfg(void);
int tisp_dpc_s_par_cfg(void);
int tisp_dpc_d_m1_par_cfg(void);
int tisp_dpc_d_m2_par_cfg(void);
int tisp_dpc_d_m3_par_cfg(void);
int tisp_dpc_cor_par_cfg(void);
int tisp_ctr_par_cfg(void);
int tisp_dpc_intp(uint param_1);
void tisp_dpc_wdr_en(int param_1);
int tisp_dpc_all_reg_refresh(void);
int tisp_dpc_intp_reg_refresh(void);
int tisp_dpc_par_refresh(uint param_1,uint param_2,int param_3);
int tisp_dpc_refresh(int param_1);
int tisp_dpc_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_dpc_param_array_set(int param_1,void *param_2,size_t *param_3);
int tisp_s_dpc_str_internal(uint param_1);
int tiziano_dpc_params_refresh(void);
int tiziano_dpc_dn_params_refresh(void);
int tiziano_dpc_init(void);
void tisp_g_dpc_str_internal(int *param_1);
void system_reg_write_clm(int param_1,int param_2,int param_3);
void clm_lut2reg(ushort *param_1,char *param_2,int param_3,int param_4);
int tiziano_set_parameter_clm(void);
int tiziano_clm_params_refresh(void);
int tiziano_clm_dn_params_refresh(void);
int tiziano_clm_init(void);
int tisp_clm_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_clm_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_set_csc_version(char param_1);
int tisp_set_user_csc(void *param_1);
void tisp_get_current_csc(int *param_1,void *param_2);
int tisp_defog_ev_update(uint param_1,int param_2);
void tiziano_defog_get_data(int param_1);
void tiziano_defog_set_reg_params(void);
int tiziano_defog_interrupt_static(void);
void tisp_defog_max_filter3(int param_1,char *param_2);
void tisp_defog_img_filter5(int param_1,char *param_2,int param_3);
void tisp_defog_soft_process(int param_1,int param_2,int param_3,int param_4,int param_5,uint *param_6,uint *param_7,uint *param_8,uint *param_9,int param_10,int *param_11,int param_12,int param_13,int param_14,uint *param_15,uint *param_16,uint *param_17,uint *param_18,uint *param_19,uint *param_20,uint *param_21,uint *param_22,int *param_23,int *param_24);
int tiziano_defog_algorithm(void);
int tisp_defog_process(void);
int tiziano_defog_params_init(void);
int tiziano_defog_params_refresh(void);
void tisp_defog_wdr_en(int param_1);
int tiziano_defog_dn_params_refresh(void);
void defog_wei_interpcot(int param_1,int param_2,int param_3,int param_4,uint *param_5);
int defog_3x3_5x5_params_init(int param_1,int param_2);
int tiziano_defog_init(uint param_1,uint param_2);
int tisp_defog_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_defog_param_array_set(int param_1,void *param_2,int *param_3);
int defog_itp(int param_1,int param_2,int param_3);
void tisp_g_defog_str_internal(char *param_1);
void tisp_s_defog_str_internal(char *param_1);
int tisp_adr_ev_update(uint param_1,int param_2);
void tiziano_adr_get_data(uint *param_1);
int tiziano_adr_algorithm(void);
int tisp_adr_process(void);
void tisp_adr_set_params(void);
int tiziano_adr_interrupt_static(void);
int tiziano_adr_5x5_param_distance(int param_1,int param_2,int param_3,int param_4,int param_5);
int tiziano_adr_5x5_param(void);
int tiziano_adr_params_init(void);
int tiziano_adr_gamma_refresh(void);
int tisp_adr_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_adr_param_array_set(int param_1,int *param_2,int *param_3);
void tisp_g_adr_str_internal(int *param_1);
void tisp_s_adr_str_internal(uint param_1);
int tiziano_adr_params_refresh(void);
int tiziano_adr_dn_params_refresh(void);
int tisp_adr_wdr_en(int param_1);
int tiziano_adr_init(uint param_1,uint param_2);
int tisp_hldc_con_par_cfg(void);
int tisp_hldc_par_refresh(int param_1);
int tiziano_hldc_params_refresh(void);
int tiziano_hldc_init(void);
int tisp_hldc_param_array_get(int param_1,void *param_2,int *param_3);
int tisp_hldc_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_set_sensor_integration_time(int param_1);
int tisp_set_sensor_integration_time_short(int param_1);
uint tisp_set_sensor_analog_gain(int param_1);
uint tisp_set_sensor_analog_gain_short(int param_1);
uint tisp_set_sensor_digital_gain_short(int param_1);
void tisp_set_sensor_digital_gain(void);
void JZ_Isp_Ae_Reg2par(uint *param_1,uint *param_2);
void JZ_Isp_Ae_Dg2reg(int param_1,uint *param_2,uint param_3,int *param_4);
void printf_func0(uint param_1,uint param_2);
void printf_func1(uint param_1,uint param_2);
void tisp_ae0_get_statistics(uint *param_1,uint param_2);
int ae0_interrupt_static(void);
void tisp_ae1_get_statistics(uint *param_1,uint param_2);
int ae1_interrupt_static(void);
void tisp_ae1_get_hist(uint *param_1);
int ae1_interrupt_hist(void);
void tisp_ae0_get_hist(uint *param_1,int param_2,int param_3);
int ae0_interrupt_hist(void);
int tisp_ae_get_hist_custome(void *param_1);
int tisp_ae_set_hist_custome(void);
int AePweightCalculate(uint param_1,int param_2,int param_3,int param_4);
void ae0_weight_mean2(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,void *param_8,void *param_9,int param_10,int param_11,int param_12,int param_13,int param_14,int param_15,int param_16,int param_17,uint *param_18,int param_19,int param_20,uint *param_21,int *param_22,int *param_23,uint *param_24,uint *param_25);
void tisp_ae_tune(int *param_1,int *param_2,int *param_3,int param_4,uint param_5,uint param_6);
int tisp_ae_target(uint param_1,int *param_2,int *param_3,uint param_4);
void ae0_tune2(int *param_1,int param_2,code *param_3,int param_4,uint param_5,uint *param_6,uint *param_7,uint *param_8,int param_9,int *param_10,int *param_11,int *param_12,int param_13_00,int *param_13,uint *param_14,uint *param_15,int *param_16,uint *param_17,int *param_18,uint *param_19,uint *param_20,int *param_21,int param_23_00,uint *param_22,uint *param_23,int param_26_00,uint *param_24,uint *param_25,uint *param_26,int param_30_00,uint *param_27);
int tisp_ae_g_min(int *param_1);
int tisp_ae_s_min(uint param_1,uint param_2,uint param_3,uint param_4);
void Tiziano_ae0_fpga(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int *param_7,int param_8,int param_9,int param_10);
void tisp_set_ae0_ag(void);
void tisp_set_ae1_ag(void);
int tisp_ae1_expt(void);
void tisp_ae_mean_update(uint *param_1,uint *param_2);
void ae1_weight_mean2(int param_1,int param_2,int param_3);
int Tiziano_ae1_fpga(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,void *param_7,void *param_8);
int tisp_ae0_ctrls_update(void);
int tisp_ae1_ctrls_update(void);
void tiziano_ae_dump(void);
int tiziano_ae_params_refresh(void);
int tiziano_ae_s_max_again(uint param_1);
int tiziano_ae_s_max_isp_dgain(int param_1);
int tisp_ae_s_at_list(int param_1,int param_2,int param_3,int param_4);
int tisp_ae_g_at_list(int *param_1);
void tiziano_deflicker_expt(int param_1,uint param_2,int param_3,int param_4,uint *param_5,uint *param_6);
void tiziano_deflicker_expt_tune(void);
void system_reg_write_ae(int param_1,int param_2,int param_3);
int tisp_ae1_process_impl(void);
int tisp_ae1_process(void);
int tiziano_ae_set_hardware_param(int param_1,uint *param_2,int param_3);
void tiziano_ae_para_addr(void);
void tiziano_ae_init_exp_th(void);
int tisp_ae_wdr_en(int param_1);
int tiziano_ae_init(int param_1,int param_2,int param_3);
int tisp_ae_min_max_set(void);
void tiziano_ae_s_ev_start(int param_1);
int tisp_ae_state_get(int param_1);
int tisp_ae_manual_get(void *param_1);
int tisp_ae_manual_set(int param_1,uint param_2,uint param_3,int param_4,uint param_5);
int tisp_ae_get_y_zone(void *param_1);
int tisp_ae_s_comp(uint param_1);
int tiziano_ae_dn_params_refresh(void);
void tisp_ae_g_comp(char *param_1);
void tisp_ae_g_luma(char *param_1);
void tisp_ae_g_scene_luma(uint *param_1);
int tisp_ae0_process_impl(void);
int tisp_ae0_process(void);
int tisp_ae_get_antiflicker_step(void *param_1,int *param_2);
int tisp_ae_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_ae_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_ae_trig(void);
void tisp_ae_deinit(void);
void tisp_ae_algo_init(int param_1,int param_2);
void tisp_ae_algo_handle(int param_1);
void tisp_af_get_statistics(uint *param_1,int param_2,int param_3);
void Tiziano_af_fpga(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8,int *param_9,int param_10,int *param_11);
int tisp_af_process_impl(void);
int af_interrupt_static(void);
int tiziano_af_params_refresh(void);
void tiziano_af_dump(void);
void system_reg_write_af(int param_1,int param_2,int param_3);
int tiziano_af_set_hardware_param(void);
int tiziano_af_init(int param_1,int param_2);
int tisp_af_get_metric(uint *param_1);
int tisp_af_get_attr(uint *param_1);
int tisp_af_set_attr_refresh(void);
int tisp_af_set_attr(int param_1,int param_2,int param_3,int param_4);
int tiziano_af_dn_params_refresh(void);
int tisp_af_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_af_param_array_set(int param_1,void *param_2,size_t *param_3);
void tisp_af_get_zone(void *param_1);
int tisp_ydns_param_cfg(void);
int tisp_ydns_intp(uint param_1);
int tisp_ydns_all_reg_refresh(void);
int tisp_ydns_intp_reg_refresh(void);
int tisp_ydns_par_refresh(uint param_1);
int tisp_ydns_gain_update(int param_1);
int tiziano_ydns_params_refresh(void);
int tiziano_ydns_dn_params_refresh(void);
int tiziano_ydns_init(void);
int tisp_ydns_refresh(int param_1);
int tisp_ydns_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_ydns_param_array_set(int param_1,void *param_2,int *param_3);
int tisp_rdns_intp(uint param_1);
int tisp_rdns_awb_gain_par_cfg(void);
int tisp_rdns_opt_cfg(void);
int tisp_rdns_slope_cfg(void);
int tisp_rdns_thres_par_cfg(void);
int tisp_rdns_gray_np_par_cfg(void);
int tisp_rdns_text_np_par_cfg(void);
int tisp_rdns_lum_np_par_cfg(void);
int tisp_rdns_std_np_par_cfg(void);
int tisp_rdns_sl_par_cfg(void);
int tisp_rdns_awb_gain_updata(uint param_1,uint param_2);
void tisp_rdns_wdr_en(int param_1);
int tisp_rdns_all_reg_refresh(void);
int tisp_rdns_intp_reg_refresh(void);
int tisp_rdns_par_refresh(uint param_1,int param_2,int param_3);
int tisp_rdns_gain_update(int param_1);
int tiziano_rdns_params_refresh(void);
int tiziano_rdns_init(void);
int tisp_rdns_refresh(int param_1);
int tiziano_rdns_dn_params_refresh(void);
int tisp_rdns_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_rdns_param_array_set(int param_1,void *param_2,int *param_3);
int tiziano_wdr_fusion1_curve(void);
int tiziano_wdr_fusion1_curve_block_mean1(void);
int tisp_wdr_rx_ae0_infm(void *param_1,void *param_2);
int tisp_wdr_rx_ae1_infm(void *param_1,void *param_2);
int tisp_wdr_rx_ae0_dms(int *param_1,int *param_2,int *param_3,int param_4);
int tisp_wdr_rx_ae1_dms(void);
int tisp_wdr_expTime_updata(void);
int tisp_wdr_ev_update(uint param_1,int param_2);
int tisp_wdr_ev_calculate(void);
void tiziano_wdr_get_data(uint *param_1);
int tiziano_wdr_interrupt_static(void);
int tiziano_wdr_algorithm(void);
int tiziano_wdr_soft_para_out(void);
int tisp_wdr_process(void);
int tiziano_wdr_5x5_param_distance(int param_1,int param_2,int param_3,int param_4,int param_5);
int tiziano_wdr_5x5_param(void);
int tiziano_wdr_params_init(void);
int tiziano_wdr_gamma_refresh(void);
int tiziano_wdr_params_refresh(void);
int tiziano_wdr_dn_params_refresh(void);
int tiziano_wdr_init(uint param_1,uint param_2);
int tisp_wdr_param_array_get(int param_1,void *param_2,size_t *param_3);
int tisp_wdr_param_array_set(int param_1,int *param_2,int *param_3);
int system_yvu_or_yuv(int param_1,int param_2,uint param_3);
int tisp_day_or_night_s_ctrl(int param_1);
int tisp_cust_mode_s_ctrl(int param_1);
int tisp_cust_mode_g_ctrl(void);
int tisp_day_or_night_g_ctrl(void);
int tisp_mirror_enable(int param_1);
int tisp_hv_flip_enable(uint param_1);
void tisp_hv_flip_get(char *param_1);
int tisp_flip_enable(int param_1);
int tisp_set_fps(uint param_1);
void tisp_set_brightness(char param_1);
int tisp_set_ae_comp(uint param_1);
void tisp_get_ae_comp(void);
void tisp_get_ae_luma(void);
void tisp_set_sharpness(char param_1);
void tisp_set_saturation(char param_1);
void tisp_set_contrast(char param_1);
void tisp_set_bcsh_hue(char param_1);
void tisp_get_brightness(void);
void tisp_get_sharpness(void);
void tisp_get_saturation(void);
void tisp_get_contrast(void);
void tisp_get_bcsh_hue(void);
int tisp_top_sel(void);
int tisp_top_read(void);
int tisp_g_ncuinfo(int param_1);
int tisp_s_antiflick(int param_1);
int tisp_s_Hilightdepress(int param_1);
int tisp_g_Hilightdepress(int *param_1);
int tisp_s_BacklightComp(int param_1);
int tisp_g_BacklightComp(int *param_1);
int tisp_s_Gamma(void *param_1);
int tisp_g_Gamma(int param_1);
int tisp_s_aeroi_weight(int *param_1);
int tisp_g_aeroi_weight(int param_1);
int tisp_s_aezone_weight(void *param_1);
int tisp_g_aezone_weight(int param_1);
int tisp_s_af_weight(void *param_1);
int tisp_g_af_weight(int param_1);
int tisp_g_ev_attr(int *param_1);
int tisp_g_wb_attr(void);
int tisp_s_wb_attr(void);
int tisp_g_wb_zone(void);
int tisp_g_wb_ct(void);
int tisp_s_wb_ct(void);
int tisp_s_awb_cluster(int param_1,int param_2,int param_3,int param_4);
int tisp_g_awb_cluster(void);
int tisp_s_awb_ct_trend(void);
int tisp_g_awb_ct_trend(void);
int tisp_g_ccm_attr(int param_1);
int tisp_s_ccm_attr(char *param_1);
int tisp_g_ae_hist(void);
int tisp_s_ae_hist(int param_1,int param_2,int param_3,int param_4);
int tisp_s_ae_at_list(int param_1,int param_2,int param_3,int param_4);
int tisp_g_ae_at_list(void);
int tisp_s_3dns_ratio(void);
int tisp_s_2dns_ratio(void);
int tisp_s_ae_attr(int param_1);
int tisp_g_ae_attr(int *param_1);
int tisp_g_ae_min(int *param_1);
int tisp_s_ae_min(void);
int tisp_g_ae_zone(void);
int tisp_g_af_zone(void);
int tisp_g_af_metric(void);
int tisp_g_af_attr(void);
int tisp_s_af_attr(int param_1,int param_2,int param_3,int param_4);
void tisp_s_wb_frz(char param_1);
void tisp_g_wb_frz(void);
void tisp_s_module_control(uint param_1);
void tisp_g_module_control(uint *param_1);
void tisp_s_autozoom_control(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8,int param_9);
void tisp_g_autozoom_control(void);
int tisp_s_scaler_level_control(uint param_1,int param_2,uint param_3);
int tisp_s_fcrop_control(char param_1,uint param_2,int param_3,int param_4,uint param_5);
void tisp_g_fcrop_control(char *param_1);
int tisp_s_wdr_en(int param_1);
int tisp_s_wdr_init_en(int param_1);
int tisp_g_wdr_en(int *param_1);
void tisp_s_max_again(void);
void tisp_s_max_isp_dgain(void);
int tisp_g_dpc_strength(void);
int tisp_s_dpc_strength(void);
int tisp_g_drc_strength(void);
int tisp_s_drc_strength(void);
void tisp_mscaler_mask_change(int param_1);
int tisp_mscaler_mask_setreg(uint param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,int param_7,unsigned long long param_8,unsigned long long param_10,int param_12,int param_13,int param_14,unsigned long long param_15,unsigned long long param_17,int param_19,int param_20,int param_21,unsigned long long param_22,unsigned long long param_24,int param_26,int param_27,int param_28,unsigned long long param_29,unsigned long long param_31,int param_33,int param_34,int param_35,unsigned long long param_36,unsigned long long param_38,int param_40,int param_41,int param_42);
int tisp_s_mscaler_mask_attr(int param_1,int param_2,int param_3,int param_4);
int tisp_g_mscaler_mask_attr(int param_1);
void tisp_s_mscaler_hvflip_mask(uint param_1);
void tisp_s_ev_start(void);
void tisp_s_awb_start(void);
void tisp_g_awb_start(void);
int tisp_s_awb_algo(void);
void tisp_deinit_free(void);
int tisp_s_ae_it_max(int param_1);
int tisp_g_ae_it_max(int *param_1);
int tisp_s_adr_enable(int param_1);
int tisp_s_defog_enable(uint param_1);
int tisp_set_ae_freeze(int param_1);
void tisp_get_antiflicker_step(void);
void tisp_set_ae_attr(int *param_1);
void tisp_get_ae_attr(void);
void tisp_get_ae_state(void);
int tisp_get_blc_attr(uint *param_1);
int tisp_set_defog_strength(void);
int tisp_get_defog_strength(void);
int tisp_set_csc_attr(uint *param_1);
int tisp_get_csc_attr(int param_1);
void tisp_ae_algo_deinit(void);
void tisp_awb_algo_deinit(void);
int tisp_set_wdr_output_mode(int *param_1);
int tisp_get_wdr_output_mode(int *param_1);
int tisp_set_bcsh_fixed_contrast(char *param_1);
int tisp_set_frame_drop(int param_1,int *param_2);
int tisp_get_frame_drop(int param_1,int *param_2);
void tisp_s_rgb_coefft(void);
void tisp_g_rgb_coefft(void);
void tisp_lsc_hvflip(void);
int ispcore_sensor_ops_release_all_sensor(int param_1);
int ispcore_sensor_ops_ioctl(int param_1,int param_2,int param_3);
void ispcore_irq_fs_work(void);
int ispcore_link_setup(void);
void isp_pre_frame_dequeue(void);
void isp_ch1_frame_dequeue_delay(void);
int ispcore_frame_channel_dqbuf(int param_1,int param_2);
int ispcore_core_ops_ioctl(int param_1,int param_2,int *param_3);
int isp_fw_process(void);
int ispcore_irq_thread_handle(uint param_1);
int ispcore_frame_channel_streamoff(uint *param_1);
void dump_isp_info_open(int param_1,int param_2);
int isp_core_cmd_set(int param_1,int param_2,int param_3);
int ispcore_sync_sensor_attr(uint param_1,void *param_2);
int isp_info_show.isra.0(int param_1);
int isp_core_debug_show(int param_1);
int ispcore_pad_event_handle(uint *param_1,int param_2,void *param_3);
int ispcore_activate_module(uint param_1);
void dump_msca_regs(void);
int system_reg_write(int param_1,int param_2);
int system_reg_read(int param_1);
void exception_handle(void);
void tx_isp_enable_irq(int param_1);
void tx_isp_disable_irq(int param_1);
int ispcore_video_s_stream(int param_1,int param_2);
int ispcore_core_ops_init(uint param_1,int param_2);
int ispcore_slake_module(uint param_1);
int tx_isp_core_probe(int param_1);
int system_irq_func_set(int param_1,int param_2);
int mbus_to_bayer_write(int param_1);
int ispcore_interrupt_service_routine(int param_1);
int tx_isp_vic_remove(int param_1);
int tx_isp_vin_remove(int param_1);
int tx_isp_csi_remove(int param_1);
int tx_isp_fs_remove(void);
int tx_isp_remove(int param_1);
int tx_isp_core_remove(void);
char __ashldi3();
char alloc_chrdev_region();
char __udelay();
char dev_get_drvdata();
char __class_create();
void * memmove(void * __dest, void * __src, size_t __n);
int snprintf(char * __s, size_t __maxlen, char * __format, ...);
char finish_wait();
char class_destroy();
char prepare_to_wait();
void * memcpy(void * __dest, void * __src, size_t __n);
char kfree();
char __wake_up();
char kfree_skb();
char schedule_timeout();
char kmem_cache_alloc();
char __lshrdi3();
char cdev_add();
char preempt_schedule();
char device_create();
void * memset(void * __s, int __c, size_t __n);
char PDE_DATA();
char __init_waitqueue_head();
char __copy_user();
char __might_sleep();
char arch_local_irq_restore();
int sprintf(char * __s, char * __format, ...);
char unregister_chrdev_region();
char device_destroy();
char seq_printf();
char div64_u64();
char register_chrdev_region();
char arch_local_irq_save();
size_t strlen(char * __s);
char cdev_init();
char cdev_del();
char simple_strtoull();

