#if !defined( __SKY_RAWDATA_H__ )
#define __SKY_RAWDATA_H__

/*===========================================================================

               SKY_RAWDATA.H

DESCRIPTION

Copyright (c) 2011 by Pantech All Rights Reserved.

===========================================================================*/

/*===========================================================================
                        EDIT HISTORY FOR MODULE

when        who              what,where,why
----------  ------------     ------------------------------------------------
2011-01-11  choiseulkee      Create.
============================================================================*/

#define SECTOR_SIZE               512
#define SKY_RAWDATA_MAX           (8192*SECTOR_SIZE) // 4MB
#define SECTOR_SIZE_DEFAULT       1

//----------------------------------------------------------------------------------

#define DLOAD_SECTOR_START        0
#define DLOAD_INFO_OFFSET         DLOAD_SECTOR_START
#define PARTITION_INFO_OFFSET     (DLOAD_SECTOR_START+SECTOR_SIZE)
#define BACKUP_DLOAD_INFO_OFFSET  (DLOAD_SECTOR_START+(SECTOR_SIZE*2))
#define DLOAD_STATUS_OFFSET       (DLOAD_SECTOR_START+(SECTOR_SIZE*3))
#define DLOAD_HISTORY_OFFSET      (DLOAD_SECTOR_START+(SECTOR_SIZE*4))
#define DLOAD_SECTOR_MAX          (SECTOR_SIZE*8)

//----------------------------------------------------------------------------------

#define BACKUP_SECTOR_START		(DLOAD_SECTOR_START+DLOAD_SECTOR_MAX)

#define SECUREESN_START			BACKUP_SECTOR_START
#define SECUREESN_LENGTH		((SECTOR_SIZE*25) * 2) // use sectors as pages // "*2" means 2 blocks

#define RFCAL_BACKUP_START		(SECUREESN_START+SECUREESN_LENGTH)
#define RFCAL_BACKUP_LENGTH		(SECTOR_SIZE*100)

#define FACTORY_EFS_INIT_START		(RFCAL_BACKUP_START+RFCAL_BACKUP_LENGTH)
#define FACTORY_EFS_INIT_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define MSEC_BACKUP_START		(FACTORY_EFS_INIT_START+FACTORY_EFS_INIT_LENGTH)
#define MSEC_BACKUP_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define FUNCTEST_RESULT_INIT_START	(MSEC_BACKUP_START+MSEC_BACKUP_LENGTH)
#define FUNCTEST_RESULT_INIT_LENGTH	(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define WIFI_DEVICE_INFO_START		(FUNCTEST_RESULT_INIT_START+FUNCTEST_RESULT_INIT_LENGTH)
#define WIFI_DEVICE_INFO_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define BT_DEVICE_INFO_START		(WIFI_DEVICE_INFO_START+WIFI_DEVICE_INFO_LENGTH)
#define BT_DEVICE_INFO_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define PWR_ON_CNT_START		(BT_DEVICE_INFO_START+BT_DEVICE_INFO_LENGTH)
#define PWR_ON_CNT_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define SDCARD_UPDATE_START		(PWR_ON_CNT_START+PWR_ON_CNT_LENGTH)
#define SDCARD_UPDATE_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define USB_CHARGING_START		(SDCARD_UPDATE_START+SDCARD_UPDATE_LENGTH)
#define USB_CHARGING_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define PERMANENTMEMORY_START		(USB_CHARGING_START+USB_CHARGING_LENGTH)
#define PERMANENTMEMORY_LENGTH		(SECTOR_SIZE*2)

//F_PANTECH_MEID_IMEI_ADDR_BACKUP
#define NON_SECURE_IMEI_START       (PERMANENTMEMORY_START+PERMANENTMEMORY_LENGTH)
#define NON_SECURE_IMEI_LENGTH      (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

//Reset_data for CIQ
#define CIQ_RESET_DATA_START        (NON_SECURE_IMEI_START+NON_SECURE_IMEI_LENGTH)
#define CIQ_RESET_DATA_LENGTH       (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

// P12554 MMP DivX DRM
#define PANTECH_DIVX_DRM_FRAG1_START                 (CIQ_RESET_DATA_START+CIQ_RESET_DATA_LENGTH)
#define PANTECH_DIVX_DRM_FRAG1_LENGTH               (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)
 
#define PANTECH_DIVX_DRM_FRAG2_START                 (PANTECH_DIVX_DRM_FRAG1_START+PANTECH_DIVX_DRM_FRAG1_LENGTH)
#define PANTECH_DIVX_DRM_FRAG2_LENGTH               (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)
 
#define PANTECH_DIVX_DRM_FRAG3_START                 (PANTECH_DIVX_DRM_FRAG2_START+PANTECH_DIVX_DRM_FRAG2_LENGTH)
#define PANTECH_DIVX_DRM_FRAG3_LENGTH               (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)
// P12554 MMP DivX DRM

//p14777 jang checks gota status
#define GOTA_UPDATE_START		(PANTECH_DIVX_DRM_FRAG3_START+PANTECH_DIVX_DRM_FRAG3_LENGTH)
#define GOTA_UPDATE_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

//>> [FEATURE_SKY_CP_NEW_OPENING_DAY]
#define OPENINGDAY_START		(GOTA_UPDATE_START+GOTA_UPDATE_LENGTH)
#define OPENINGDAY_LENGTH		(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)
//<< [FEATURE_SKY_CP_NEW_OPENING_DAY]	

//F_PANTECH_OEM_ROOTING
#define PANTECH_ROOTING_CHECK_START           (OPENINGDAY_START+OPENINGDAY_LENGTH)
#define PANTECH_ROOTING_CHECK_LENGTH          (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

//chjeon20120223@LS1 add FEATURE_PANTECH_WIDEVINE_DRM
#define PANTECH_WV_DRM_DEVICEID_START   (PANTECH_ROOTING_CHECK_START+PANTECH_ROOTING_CHECK_LENGTH)
#define PANTECH_WV_DRM_DEVICEID_LENGTH  (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define PANTECH_WV_DRM_KEYBOX_START     (PANTECH_WV_DRM_DEVICEID_START+PANTECH_WV_DRM_DEVICEID_LENGTH)
#define PANTECH_WV_DRM_KEYBOX_LENGTH    (SECTOR_SIZE*SECTOR_SIZE_DEFAULT)

#define MDM_PREVENT_UPGRADE_START	(PANTECH_WV_DRM_KEYBOX_START+PANTECH_WV_DRM_KEYBOX_LENGTH)
#define MDM_PREVENT_UPGRADE_LENGTH	(SECTOR_SIZE*SECTOR_SIZE_DEFAULT)


#define BACKUP_SECTOR_LENGTH		(MDM_PREVENT_UPGRADE_START+MDM_PREVENT_UPGRADE_LENGTH-BACKUP_SECTOR_START)

// Backup Item �߰��� BACKUP_SECTOR_LENGTH ���� �߰� �Ͻð� �̳� ������ �ּ���
// ���� MDM�� sky_rawdata.h(core/pantech/sky_rawdata/inc)���� �����ϰ� update ���ּ���!!!
// �ݵ�� SYS VOB�� �۾��� �� ���� UI VOB���� �ʳ��� �ʵ��� ���ֽñ� �ٶ��ϴ�!!!

//----------------------------------------------------------------------------------


#ifdef FEATURE_SKY_RAWDATA_ACCESS
extern int sky_rawdata_write( unsigned int address, unsigned int size, char *buf );
extern int sky_rawdata_read( unsigned int address, unsigned int size, char *buf );
extern void sky_rawdata_init_cb( void );
#endif

#endif /* __SKY_RAWDATA_H__ */