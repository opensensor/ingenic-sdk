#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/of.h>

int32_t tx_isp_probe(int32_t* arg1)
{
    uint32_t allocatedMemory;
    int32_t platformDeviceCount;
    allocatedMemory = private_kmalloc(0x124, 0x24000c0);
    int32_t returnStatus;
    if (allocatedMemory == 0)
    {
        printk("Failed to allocate memory for isp driver\n");
        returnStatus = 0xfffffff4;
    }
    else
    {
        int32_t memsetResult = memset(allocatedMemory, 0, 0x124);
        void* platformDeviceData = arg1[0x16];
        if (platformDeviceData == 0)
        {
            returnStatus = 0xffffffea;
        label_fc0c:
            private_kfree(allocatedMemory);
        }
        else
        {
            if (((uint32_t)*(uint8_t*)((char*)platformDeviceData + 4)) >= 0x11)
            {
                isp_printf(2, "The number of platform device is…", memsetResult);
                returnStatus = 0xffffffea;
                goto label_fc0c;
            }
            void* platformDeviceEntry = (allocatedMemory + 0x88);
            int32_t platformDeviceIndex = 0;
            uint32_t actualPlatformDeviceCount;
            while (true)
            {
                actualPlatformDeviceCount = ((uint32_t)*(uint8_t*)((char*)platformDeviceData + 4));
                if (platformDeviceIndex >= actualPlatformDeviceCount)
                {
                    break;
                }
                int32_t* currentPlatformDevice = *(uint32_t*)(*(uint32_t*)((char*)platformDeviceData + 8) + (platformDeviceIndex << 2));
                struct IspDriverEntry* i = &isp_drivers;
                *(uint32_t*)platformDeviceEntry = currentPlatformDevice;
                struct IspDriver* currentIspDriver;
                while (i != 0x6e5a8)
                {
                    currentIspDriver = i->field_00;
                    char* currentPlatformDeviceName = *(uint32_t*)currentPlatformDevice;
                    struct NameMatchEntry* currentNameMatchEntry = currentIspDriver->nameMatchTable;
                    uint32_t nameHash_1 = ((uint32_t)*(uint8_t*)currentPlatformDeviceName);
                    uint32_t nameHash;
                    while (true)
                    {
                        nameHash = ((uint32_t)currentNameMatchEntry->nameHash);
                        currentPlatformDeviceName = &currentPlatformDeviceName[1];
                        currentNameMatchEntry = &currentNameMatchEntry[1];
                        if (nameHash != nameHash_1)
                        {
                            break;
                        }
                        uint32_t nameHash_2 = nameHash_1;
                        nameHash_1 = ((uint32_t)*(uint8_t*)currentPlatformDeviceName);
                        if (nameHash_2 == 0)
                        {
                            nameHash_1 = nameHash;
                            break;
                        }
                    }
                    i = &i[1];
                    if ((nameHash_1 - nameHash) == 0)
                    {
                        break;
                    }
                }
                if (i != 0x6e5a8)
                {
                    int32_t platformDeviceRegisterResult = private_platform_device_register(currentPlatformDevice, 0);
                    returnStatus = platformDeviceRegisterResult;
                    if (platformDeviceRegisterResult != 0)
                    {
                        break;
                    }
                    int32_t driverInfo = currentIspDriver->driverInfo;
                    if (driverInfo == 0)
                    {
                        *(uint32_t*)((char*)platformDeviceEntry + 4) = currentIspDriver;
                    }
                    else
                    {
                        driverInfo(currentPlatformDevice);
                        *(uint32_t*)((char*)platformDeviceEntry + 4) = currentIspDriver;
                    }
                }
                platformDeviceIndex = (platformDeviceIndex + 1);
                platformDeviceEntry = ((char*)platformDeviceEntry + 8);
            }
            if (platformDeviceIndex < actualPlatformDeviceCount)
            {
                isp_printf(2, "Failed to register isp device(%d…", platformDeviceIndex);
                *(uint32_t*)platformDeviceEntry = 0;
                goto label_fbfc;
            }
            *(uint32_t*)(allocatedMemory + 0x84) = actualPlatformDeviceCount;
            private_spin_lock_init((allocatedMemory + 0x118));
            if (tx_isp_module_init(arg1, allocatedMemory) != 0)
            {
                isp_printf(2, "Failed to init isp module(%d.%d)…", ((uint32_t)*(uint8_t*)((char*)platformDeviceData + 2)));
                returnStatus = 0xfffffff4;
            label_fbfc:
                tx_isp_unregister_platforms((allocatedMemory + 0x88));
                goto label_fc0c;
            }
            *(uint32_t*)(allocatedMemory + 0xc) = 0xff;
            *(uint32_t*)(allocatedMemory + 0x34) = 0x78d8c;
            *(uint32_t*)(allocatedMemory + 0x14) = 0x78d8c;
            *(uint32_t*)(allocatedMemory + 0x10) = "tx-isp";
            int32_t miscRegisterResult;
            int32_t miscRegisterFailureMessage;
            miscRegisterResult = private_misc_register((allocatedMemory + 0xc));
            returnStatus = miscRegisterResult;
            int32_t procDirectoryCreationResult;
            int32_t returnStatus_1;
            if (miscRegisterResult >= 0)
            {
                int32_t procDirectoryCreationFailureMessage;
                procDirectoryCreationResult = private_jz_proc_mkdir(&$LC38);
                *(uint32_t*)(allocatedMemory + 0x120) = procDirectoryCreationResult;
                if (procDirectoryCreationResult != 0)
                {
                    private_platform_set_drvdata(arg1, allocatedMemory);
                    globe_ispdev = allocatedMemory;
                    returnStatus_1 = tx_isp_create_graph_and_nodes(allocatedMemory);
                    returnStatus = returnStatus_1;
                    if (returnStatus_1 != 0)
                    {
                        private_proc_remove(*(uint32_t*)(allocatedMemory + 0x120));
                    }
                    else
                    {
                        isp_mem_init();
                        *(uint32_t*)(allocatedMemory + 0x108) = "H20210817b";
                        isp_printf(1, "@@@@ tx-isp-probe ok(version %s)…", "H20210817b");
                    }
                }
                else
                {
                    isp_printf(2, "Failed to create debug directory…", procDirectoryCreationFailureMessage);
                }
                if ((procDirectoryCreationResult == 0 || (procDirectoryCreationResult != 0 && returnStatus_1 != 0)))
                {
                    private_misc_deregister((allocatedMemory + 0xc));
                }
            }
            else
            {
                isp_printf(2, "Failed to register tx-isp miscde…", miscRegisterFailureMessage);
                returnStatus = 0xfffffffe;
            }
            if ((miscRegisterResult < 0 || (miscRegisterResult >= 0 && (procDirectoryCreationResult == 0 || (procDirectoryCreationResult != 0 && returnStatus_1 != 0)))))
            {
                tx_isp_module_deinit(allocatedMemory);
                goto label_fbfc;
            }
        }
    }
    return returnStatus;
}


int tx_isp_init(void)  {
	int32_t returnValue;
	returnValue = platform_device_register("tx-isp");
	if (returnValue != 0)
	{
		isp_printf("Failed to insmod isp driver!!!\n");
	}
	else
	{
		returnValue = platform_driver_register(0x78d30);
		if (returnValue != 0)
		{
			platform_device_unregister("tx-isp");
		}
	}
	return returnValue;
}

void tx_isp_exit(void) {

}

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
