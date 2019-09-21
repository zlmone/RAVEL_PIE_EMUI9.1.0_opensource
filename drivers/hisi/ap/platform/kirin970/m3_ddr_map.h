#ifndef __M3_DDR_MAP_H__
#define __M3_DDR_MAP_H__ 
#include <global_ddr_map.h>
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
#define LPMCU_RAM_SIZE (184*1024)
#define OCBC_RAM_SIZE (0)
#define UCE_RAM_SIZE (14*1024)
#ifdef __FASTBOOT__
#ifdef CONFIG_HISI_FAMA
#define M3_DDR_MEM_BASE_ADDR (HISI_RESERVED_LPMX_CORE_PHYMEM_BASE_FAMA)
#else
#define M3_DDR_MEM_BASE_ADDR (HISI_RESERVED_LPMX_CORE_PHYMEM_BASE)
#endif
#else
#define M3_DDR_MEM_BASE_ADDR (HISI_RESERVED_LPMX_CORE_PHYMEM_BASE)
#endif
#define M3_DDR_MEM_BASE_SIZE (HISI_RESERVED_LPMX_CORE_PHYMEM_SIZE)
#define TELE_MNTN_AREA_ADDR (M3_DDR_MEM_BASE_ADDR)
#define TELE_MNTN_AREA_SIZE (0x80000)
#define M3_DDR_SYS_MEM_ADDR (TELE_MNTN_AREA_ADDR + TELE_MNTN_AREA_SIZE)
#define M3_DDR_SYS_MEM_SIZE (0x10000)
#define M3_DDR_SYS_MEM_CODE_SEC_ADDR (M3_DDR_SYS_MEM_ADDR)
#define M3_DDR_SYS_MEM_CODE_SEC_SIZE (0x8000)
#define M3_DDR_SYS_MEM_DATA_SEC_ADDR (M3_DDR_SYS_MEM_CODE_SEC_ADDR+M3_DDR_SYS_MEM_CODE_SEC_SIZE)
#ifdef CONFIG_GCOV_LPMCU
#define M3_DDR_SYS_MEM_DATA_SEC_SIZE (0x2800)
#else
#define M3_DDR_SYS_MEM_DATA_SEC_SIZE (0x1000)
#endif
#define M3_DDR_SYS_MEM_BSS_SEC_ADDR (M3_DDR_SYS_MEM_DATA_SEC_ADDR+M3_DDR_SYS_MEM_DATA_SEC_SIZE)
#define M3_DDR_SYS_MEM_BSS_SEC_SIZE (0x1000)
#define M3_DDR_SYS_MEM_USED_SIZE ( M3_DDR_SYS_MEM_CODE_SEC_SIZE \
                                                 + M3_DDR_SYS_MEM_DATA_SEC_SIZE \
                                                 + M3_DDR_SYS_MEM_BSS_SEC_SIZE )
#if (M3_DDR_SYS_MEM_USED_SIZE > (M3_DDR_SYS_MEM_SIZE))
#error m3_system_memory_size(M3_DDR_SYS_MEM_USED_SIZE) used beyond (M3_DDR_SYS_MEM_SIZE)
#endif
#define M3_DDR_STORAGE_MEM_ADDR (M3_DDR_SYS_MEM_ADDR + M3_DDR_SYS_MEM_SIZE)
#define M3_DDR_STORAGE_MEM_SIZE (0x10000)
#define M3_DDR_STORAGE_MEM_DDR_SECURITY_ADDR (M3_DDR_STORAGE_MEM_ADDR)
#define M3_DDR_STORAGE_MEM_DDR_SECURITY_SIZE (0x1800)
#define M3_DDR_SHARE_MEM_DDR2FASTBOOT_BASE (M3_DDR_STORAGE_MEM_DDR_SECURITY_ADDR + M3_DDR_STORAGE_MEM_DDR_SECURITY_SIZE)
#define M3_DDR_SHARE_MEM_DDR2FASTBOOT_SIZE (0x4000)
#define M3_DDR_STORAGE_MEM_RESERVED_ADDR (M3_DDR_SHARE_MEM_DDR2FASTBOOT_BASE + M3_DDR_SHARE_MEM_DDR2FASTBOOT_SIZE)
#if (M3_DDR_STORAGE_MEM_RESERVED_ADDR > (M3_DDR_STORAGE_MEM_ADDR+M3_DDR_STORAGE_MEM_SIZE))
#error m3_storage_memory_addr(M3_DDR_STORAGE_MEM_RESERVED_ADDR) used beyond (M3_DDR_STORAGE_MEM_ADDR+M3_DDR_STORAGE_MEM_SIZE)
#endif
#define M3_DDR_SHARE_MEM_ADDR (M3_DDR_STORAGE_MEM_ADDR + M3_DDR_STORAGE_MEM_SIZE)
#define M3_DDR_SHARE_MEM_SIZE (0x30000)
#define M3_DDR_INIT_UCE_MNTN_BASE (M3_DDR_SHARE_MEM_ADDR)
#define M3_DDR_INIT_UCE_MNTN_SIZE (0x24400)
#define M3_DDR_INIT_XLOADER_TO_FASTBOOT_BASE (M3_DDR_INIT_UCE_MNTN_BASE + M3_DDR_INIT_UCE_MNTN_SIZE)
#define M3_DDR_INIT_XLOADER_TO_FASTBOOT_SIZE (0x8000)
#define M3_DDR_STORAGE_MEM_DDR_MPU_ADDR (M3_DDR_INIT_XLOADER_TO_FASTBOOT_BASE + M3_DDR_INIT_XLOADER_TO_FASTBOOT_SIZE)
#define M3_DDR_STORAGE_MEM_DDR_MPU_SIZE (0x2400)
#define M3_DDR_SHARE_DFS_TRACKING_ADDR (M3_DDR_STORAGE_MEM_DDR_MPU_ADDR + M3_DDR_STORAGE_MEM_DDR_MPU_SIZE)
#define M3_DDR_SHARE_DFS_TRACKING_SZE (0x1000)
#define M3_DDR_SHARE_MEM_AGE_ADDR (M3_DDR_SHARE_DFS_TRACKING_ADDR + M3_DDR_SHARE_DFS_TRACKING_SZE)
#ifdef PRODUCT_DDR_AGING_TEST
#define M3_DDR_SHARE_MEM_AGE_SIZE (0x400)
#else
#define M3_DDR_SHARE_MEM_AGE_SIZE (0x0)
#endif
#define M3_DDR_SHARE_MEM_RESERVED_ADDR (M3_DDR_SHARE_MEM_AGE_ADDR + M3_DDR_SHARE_MEM_AGE_SIZE)
#if (M3_DDR_SHARE_MEM_RESERVED_ADDR > (M3_DDR_SHARE_MEM_ADDR+M3_DDR_SHARE_MEM_SIZE))
#error m3_share_memory_addr(M3_DDR_SHARE_MEM_RESERVED_ADDR) used beyond (M3_DDR_SHARE_MEM_ADDR+M3_DDR_SHARE_MEM_SIZE)
#endif
#define M3_DDR_MEM_RESERVED_ADDR (M3_DDR_SHARE_MEM_ADDR + M3_DDR_SHARE_MEM_SIZE)
#ifdef CONFIG_GCOV_LPMCU
#define M3_DDR_MEM_GCOV_ADDR M3_DDR_MEM_RESERVED_ADDR
#define M3_DDR_MEM_GCOV_SIZE (0x30000)
#endif
#if (M3_DDR_MEM_RESERVED_ADDR > (M3_DDR_MEM_BASE_ADDR+M3_DDR_MEM_BASE_SIZE))
#error m3_memory_addr(M3_DDR_MEM_RESERVED_ADDR) used beyond (M3_DDR_MEM_BASE_ADDR+M3_DDR_MEM_BASE_SIZE)
#endif
#define PMU_DUMP_SIZE (1024)
#ifdef __FASTBOOT__
#ifdef CONFIG_HISI_FAMA
#define PMU_DUMP_ADDR (HISI_RESERVED_LPMCU_PHYMEM_BASE_FAMA + HISI_RESERVED_LPMCU_PHYMEM_SIZE - PMU_DUMP_SIZE)
#else
#define PMU_DUMP_ADDR (HISI_RESERVED_LPMCU_PHYMEM_BASE + HISI_RESERVED_LPMCU_PHYMEM_SIZE - PMU_DUMP_SIZE)
#endif
#else
#define PMU_DUMP_ADDR (HISI_RESERVED_LPMCU_PHYMEM_BASE + HISI_RESERVED_LPMCU_PHYMEM_SIZE - PMU_DUMP_SIZE)
#endif
#define PER_CHIP_AVS_FLAG_ADDR (PMU_DUMP_ADDR + PMU_DUMP_SIZE - 0x100)
#ifdef CONFIG_HISI_FAMA
#define LPMCU_FIRMWARE_PACK_BACKUP_ADDR (HISI_RESERVED_LPMCU_PHYMEM_BASE_FAMA)
#else
#define LPMCU_FIRMWARE_PACK_BACKUP_ADDR (HISI_RESERVED_LPMCU_PHYMEM_BASE)
#endif
#define LPMCU_FIRMWARE_PACK_BACKUP_SIZE (HISI_RESERVED_LPMCU_PHYMEM_SIZE - PMU_DUMP_SIZE)
#define OCBC_FIRMWARE_BACKUP_ADDR (LPMCU_FIRMWARE_PACK_BACKUP_ADDR)
#define OCBC_FIRMWARE_BACKUP_SIZE (OCBC_RAM_SIZE)
#define LPMCU_FIRMWARE_BACKUP_ADDR (OCBC_FIRMWARE_BACKUP_ADDR + OCBC_FIRMWARE_BACKUP_SIZE)
#define LPMCU_FIRMWARE_BACKUP_SIZE (LPMCU_RAM_SIZE)
#define UCE_FIRMWARE_BACKUP_ADDR (LPMCU_FIRMWARE_BACKUP_ADDR + LPMCU_FIRMWARE_BACKUP_SIZE + M3_DDR_SYS_MEM_USED_SIZE)
#define UCE_FIRMWARE_BACKUP_SIZE (UCE_RAM_SIZE)
#define LPMCU_FIRMWARE_PACK_USED_SIZE (UCE_FIRMWARE_BACKUP_ADDR + UCE_FIRMWARE_BACKUP_SIZE - LPMCU_FIRMWARE_PACK_BACKUP_ADDR)
#if (LPMCU_FIRMWARE_PACK_USED_SIZE) > (LPMCU_FIRMWARE_PACK_BACKUP_SIZE)
#error "lpmcu firmware pack overflow!!!"
#endif
#define LPM3_MAGIC_ADDR (LPMCU_FIRMWARE_BACKUP_ADDR + 0x044)
#define DDR_WIN_MASK (0xF0000000)
#define DDR_PHY_TO_WIN(phy_addr) ((phy_addr) & DDR_WIN_MASK)
#define DDR_VIRT_TO_PHY(virt_addr,win_addr) (((virt_addr) & 0x0FFFFFFF) | (win_addr))
#define DDR_PHY_TO_VIRT(phy_addr) (((phy_addr) & 0x0FFFFFFF) | 0x10000000)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
