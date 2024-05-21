#include "tx-isp-load-parameters.h"
#include "gc2053_data.h"

/*****************************************************
	the struct of ISP parameters data is as follow:
	|-------------------|
	|      version      |
	|-------------------|
	| parameter0 header |
	|-------------------|
	| parameter0 data   |
	|-------------------|
	| parameter1 header |
	|-------------------|
	| parameter1 data   |
	|-------------------|

	The parameter0 is the data of  apcial_static_calibrations and apcial_dynamic_calibrations.
	The parameter1 is the data of customer initializations.

*****************************************************/
extern uint32_t get_dynamic_calibrations( ApicalCalibrations *c );
extern uint32_t get_static_calibrations( ApicalCalibrations * c );
extern void init_tx_isp_customer_parameter(TXispPrivCustomerParamer *m);

static TXispPrivParamManage *manager = NULL;
static ApicalCalibrations tmp_isp_param;			//the struct of private0 manager.

static const unsigned int crc_table[8] = {
	0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL,
	0x076dc419L, 0x706af48fL, 0xe963a535L, 0x9e6495a3L,
};

static unsigned int crc32(const unsigned int *p, unsigned int len)
{
	int i = 0;
	unsigned int crc = crc_table[0];
	for(i = 0; i < len; i++){
		crc ^= *p++;
		crc = crc ^ crc_table[crc & 0x7];
	}

	return crc;
}

static void full_the_tables_space(TXispPrivParamManage *m)
{
	int index = 0;
	ApicalCalibrations *isp_param = m->isp_param;
	LookupTable *param_table = m->param_table;
	for(index = 0; index < _CALIBRATION_TOTAL_SIZE; index++){
		printk("full_the_tables_space index = %d\n", index);
		isp_param[TX_ISP_PRIV_PARAM_DAY_MODE].calibrations[index] = &param_table[index<<1];
		isp_param[TX_ISP_PRIV_PARAM_NIGHT_MODE].calibrations[index] = &param_table[(index << 1)+1];
	}
}

static inline TXispPrivParamManage * malloc_tx_isp_priv_param_manage(void)
{
	int index = 0;
//	LookupTable** c = NULL;
	printk("malloc_tx_isp_priv_param_manage\n");
	TXispPrivParamManage *m = kmalloc(sizeof(*m), GFP_KERNEL);
	if(!m) {
		printk("Failed to kmalloc TXispPrivParamManage\n");
		return NULL;
	}

	printk("malloc_tx_isp_priv_param_manage success\n");
	memset(m, 0, sizeof(*m));
	printk("malloc_tx_isp_priv_param manage memset success\n");
	snprintf(m->version, sizeof(m->version), "%s", TX_ISP_VERSION_ID);
	printk("TX_ISP_VERSION_ID = %s\n", TX_ISP_VERSION_ID);
	for(index = 0; index < TX_ISP_PRIV_PARAM_MAX_INDEX; index++){
		printk("index = %d\n", index);
		snprintf(m->headers[index].flag, TX_ISP_PRIV_PARAM_FLAG_SIZE, "header%d", index);
	}

	printk("malloc_tx_isp_priv_param_manage success\n");
	/* calibrate the memory size of apical_static and apcial_dynamic */
	get_dynamic_calibrations(&tmp_isp_param);
	printk("get_dynamic_calibrations success\n");
	get_static_calibrations(&tmp_isp_param);
	printk("get_static_calibrations success\n");
	full_the_tables_space(m);
	printk("full_the_tables_space success\n");
	return m;
}

void free_tx_isp_priv_param_manage(void)
{
	if(manager){
		manager->customer = NULL;
		init_tx_isp_customer_parameter(manager->customer);
		if(manager->data)
			kfree(manager->data);
		if(manager->fw_data)
			kfree(manager->fw_data);
		kfree(manager);
		manager = NULL;
	}
}

void print_hex_dump_custom(const char *prefix, const void *data, size_t size)
{
	const unsigned char *p = data;
	size_t i;

	printk("%s: ", prefix);
	for (i = 0; i < size; i++) {
		printk("%02x ", p[i]);
		if ((i + 1) % 16 == 0 || i + 1 == size)
			printk("\n");
	}
}

TXispPrivParamManage* load_tx_isp_parameters(struct tx_isp_sensor_attribute *attr)
{
	unsigned int ret = 0;
	int index = 0;
	struct file *file = NULL;
	struct inode *inode = NULL;
	mm_segment_t old_fs;
	loff_t fsize;
	printk("load_tx_isp_parameters\n");
	struct kstat stat;
	char file_name[64];
	char *cursor = NULL;
	char *fw_cursor = NULL;
	unsigned int size = 0;
	LookupTable** c = NULL;
	LookupTable** c_day = NULL;
	LookupTable** c_night = NULL;
	LookupTable* tmp = NULL;
	TXispPrivParamHeader *header = NULL;
	printk("load_tx_isp_parameters\n");

	if(!attr) {
		printk("The sensor attribute is NULL!\n");
		return NULL;
	}

	if(manager == NULL){
		printk("malloc_tx_isp_priv_param_manage\n");
		manager = malloc_tx_isp_priv_param_manage();
		if(manager == NULL){
			printk("Failed to kmalloc TXispPrivParamManage\n");
			return NULL;
		}
	}
/* Skip file reading and use the C array directly */
	fsize = gc2053_bin_len;
	printk("Data size: %lld bytes\n", fsize);

/* Allocate memory for the data buffer */
	if (manager->data == NULL) {
		printk("malloc data\n");
		manager->data = kmalloc(fsize, GFP_KERNEL);
		if (manager->data == NULL) {
			printk("%s[%d]: Failed to alloc %lld KB buffer!\n", __func__, __LINE__, fsize >> 10);
			ret = -ENOMEM;
			goto failed_malloc_data;
		}
		manager->data_size = fsize;
	}

	if (manager->data_size < fsize) {
		printk("The size of data has been modified!\n");
		ret = -1;
		goto failed_check_total_size;
	}

/* Copy the data from the C array */
	memcpy(manager->data, gc2053_bin, fsize);

	printk("Successfully copied %lld bytes of data.\n", fsize);
	cursor = manager->data;

	printk("load_tx_isp_parameters compare version\n");
	printk("load_tx_isp_parameters compare version done\n");
	header = &manager->headers[TX_ISP_PRIV_PARAM_BASE_INDEX];
	if (!header) {
		printk("Invalid header index\n");
		return NULL;
	}
	cursor += TX_ISP_VERSION_SIZE;
	printk("load_tx_isp_parameters compare flags\n");
	header = &manager->headers[TX_ISP_PRIV_PARAM_BASE_INDEX];
	printk("load_tx_isp_parameters compare flags 2\n");
	header->size = ((TXispPrivParamHeader *)cursor)->size;
	printk("load_tx_isp_parameters compare flags 3\n");
	header->crc = ((TXispPrivParamHeader *)cursor)->crc;
	printk("## %s %d base size = %d ##\n", __func__,__LINE__,header->size);
	if(manager->fw_data == NULL){
		manager->fw_data = kmalloc(header->size >> 1, GFP_KERNEL);
		if(manager->fw_data == NULL){
			printk("%s[%d]: Failed to alloc %d KB buffer!\n",__func__,__LINE__, header->size >> 11);
			ret = -1;
			goto failed_malloc_fw_data;
		}
	}
	printk("load_tx_isp_parameters\n");
	cursor += sizeof(TXispPrivParamHeader);
	if(header->crc != crc32((unsigned int*)cursor, header->size / 4)){
			printk("%s[%d]: Failed to CRC sensor setting!\n",__func__,__LINE__);
			ret = -1;
			goto failed_crc_header0;
	}

	fw_cursor = manager->fw_data;
	printk("load_tx_isp_parameters fw_cursor\n");
	manager->base_buf = cursor;
	c = tmp_isp_param.calibrations;
	c_day = manager->isp_param[TX_ISP_PRIV_PARAM_DAY_MODE].calibrations;
	c_night = manager->isp_param[TX_ISP_PRIV_PARAM_NIGHT_MODE].calibrations;
	printk("load_tx_isp_parameters for loop calibration\n");
	for(index = 0; index < _CALIBRATION_TOTAL_SIZE; index++){
		if(c[index] && c[index]->ptr){
			tmp = (LookupTable *)cursor;
			/* copy the parameters of isp during the day */
			c_day[index]->ptr = cursor + sizeof(LookupTable);
			c_day[index]->rows = tmp->rows;
			c_day[index]->cols = tmp->cols;
			c_day[index]->width = tmp->width;
			size = c_day[index]->rows * c_day[index]->cols * c_day[index]->width;
			cursor += size + sizeof(LookupTable);

			c[index]->ptr = fw_cursor;
			c[index]->rows = tmp->rows;
			c[index]->cols = tmp->cols;
			c[index]->width = tmp->width;
			memcpy(c[index]->ptr, c_day[index]->ptr, size);  //update the default parameters.
			fw_cursor += size;
			/* copy the parameters of isp during the night */
			tmp = (LookupTable *)cursor;
			c_night[index]->ptr = cursor + sizeof(LookupTable);
			c_night[index]->rows = tmp->rows;
			c_night[index]->cols = tmp->cols;
			c_night[index]->width = tmp->width;
			cursor += size + sizeof(LookupTable);
		}
	}

	/* check private1 header and set parameter */
	header = &manager->headers[TX_ISP_PRIV_PARAM_CUSTOM_INDEX];
	printk("load_tx_isp_parameters compare flags\n");
	header->size = ((TXispPrivParamHeader *)cursor)->size;
	header->crc = ((TXispPrivParamHeader *)cursor)->crc;
	printk("## %s %d custom size = %d ##\n", __func__,__LINE__,header->size);
	if(header->size == 0){
		manager->customer_buf = NULL;
		manager->customer = NULL;
	}else{
		manager->customer_buf = cursor + sizeof(TXispPrivParamHeader);
		manager->customer = manager->customer_buf;
		cursor += sizeof(TXispPrivParamHeader);
		if(header->crc != crc32((unsigned int*)cursor, header->size / 4)){
			printk("%s[%d]: Failed to CRC sensor setting!\n",__func__,__LINE__);
			ret = -1;
			goto failed_crc_header1;
		}
	}

	printk("load_tx_isp_parameters success -- loading customer parameters\n");
	init_tx_isp_customer_parameter(manager->customer);
	printk("load_tx_isp_parameters success -- loading customer parameters done\n");
	return manager;
failed_crc_header1:
failed_check_header1:
failed_crc_header0:
failed_malloc_fw_data:
failed_check_header0:
failed_check_version:
failed_check_total_size:
failed_malloc_data:
	filp_close(file, NULL);
	set_fs(old_fs);
failed_open_file:
	return NULL;
}
