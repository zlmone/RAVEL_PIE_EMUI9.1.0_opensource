/*
* Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
* foss@huawei.com
*
* If distributed as part of the Linux kernel, the following license terms
* apply:
*
* * This program is free software; you can redistribute it and/or modify
* * it under the terms of the GNU General Public License version 2 and
* * only version 2 as published by the Free Software Foundation.
* *
* * This program is distributed in the hope that it will be useful,
* * but WITHOUT ANY WARRANTY; without even the implied warranty of
* * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* * GNU General Public License for more details.
* *
* * You should have received a copy of the GNU General Public License
* * along with this program; if not, write to the Free Software
* * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
*
* Otherwise, the following license terms apply:
*
* * Redistribution and use in source and binary forms, with or without
* * modification, are permitted provided that the following conditions
* * are met:
* * 1) Redistributions of source code must retain the above copyright
* *    notice, this list of conditions and the following disclaimer.
* * 2) Redistributions in binary form must reproduce the above copyright
* *    notice, this list of conditions and the following disclaimer in the
* *    documentation and/or other materials provided with the distribution.
* * 3) Neither the name of Huawei nor the names of its contributors may
* *    be used to endorse or promote products derived from this software
* *    without specific prior written permission.
*
* * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*/
#ifndef __AT_RNIC_INTERFACE_H__
#define __AT_RNIC_INTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsCommonDef.h"
#include "TafTypeDef.h"
#include "RnicInterface.h"

#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
/*================================================*/
/* 数值宏定义 */
/*================================================*/
#if (VOS_OS_VER == VOS_WIN32)
/* 测试ST用例定义的IP数据包长度，单位字节 */
#define RNIC_IP_DATA_LEN                (12)
#endif
/* APP拨号后默认空闲时间 */
#define AT_APP_IDLE_TIME                (600)

/* 最大IPV6地址长度，不包括":" */
#define RNICITF_MAX_IPV6_ADDR_LEN       (16)

/* RABID取值范围[5 15] */
#define RNICITF_MIN_RAB_ID              (5)
#define RNICITF_MAX_RAB_ID              (15)

#define RNIC_MODEM_0_RMNET_ID_IS_VALID(ucRmNetId)\
    (((ucRmNetId) == RNIC_RMNET_ID_0)\
  || ((ucRmNetId) == RNIC_RMNET_ID_1)\
  || ((ucRmNetId) == RNIC_RMNET_ID_2))

#define RNIC_RMNET_NAME_MAX_LEN         (16)

/*================================================*/
/* 功能函数宏定义 */
/*================================================*/

/*******************************************************************************
  3 枚举定义
*******************************************************************************/

enum AT_RNIC_USB_TETHER_CONN_ENUM
{
    AT_RNIC_USB_TETHER_DISCONNECT       = 0x00,                                 /* USB tethering未连接 */
    AT_RNIC_USB_TETHER_CONNECTED        = 0x01,                                 /* USB tethering已连接 */
    AT_RNIC_USB_TETHER_CONN_BUTT
};
typedef VOS_UINT8 AT_RNIC_USB_TETHER_CONN_ENUM_UINT8;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/

/*****************************************************************************
  5 消息头定义
*****************************************************************************/

/*****************************************************************************
  6 消息定义
*****************************************************************************/

enum AT_RNIC_MSG_ID_ENUM
{
    /* AT发给RNIC的消息枚举 */
    ID_AT_RNIC_DIAL_MODE_IND            = 0x0001,   /* 拨号模式指示 */          /* _H2ASN_MsgChoice AT_RNIC_DIAL_MODE_IND_STRU */
    ID_AT_RNIC_DIAL_MODE_REQ            = 0x0002,   /* 拨号模式查询 */          /* _H2ASN_MsgChoice AT_RNIC_DIAL_MODE_REQ_STRU */
    ID_AT_RNIC_IPV4_PDP_ACT_IND         = 0x0003,   /* IPV4 PDP激活指示 */      /* _H2ASN_MsgChoice AT_RNIC_IPV4_PDP_ACT_IND_STRU */
    ID_AT_RNIC_IPV6_PDP_ACT_IND         = 0x0004,   /* IPV6 PDP激活指示 */      /* _H2ASN_MsgChoice AT_RNIC_IPV6_PDP_ACT_IND_STRU */
    ID_AT_RNIC_IPV4V6_PDP_ACT_IND       = 0x0005,   /* IPV4V6 PDP激活指示 */    /* _H2ASN_MsgChoice AT_RNIC_IPV4V6_PDP_ACT_IND_STRU */
    ID_AT_RNIC_PDP_DEACT_IND            = 0x0006,   /* PDP去激活指示 */         /* _H2ASN_MsgChoice AT_RNIC_PDP_DEACT_IND_STRU */
    ID_AT_RNIC_DSFLOW_IND               = 0x0007,   /* 流量上报指示 */          /* _H2ASN_MsgChoice AT_RNIC_DSFLOW_IND_STRU */
    ID_AT_RNIC_MTU_CHANGE_IND           = 0x0008,   /* MTU更改指示 */           /* _H2ASN_MsgChoice AT_RNIC_MTU_CHANGE_IND_STRU */
    /* Added by L47619 for V3R3 Share-PDP Project, 2013-6-3, begin */
    ID_AT_RNIC_PDN_INFO_CFG_IND         = 0x0009,   /* Share-PDP配置指示 */      /* _H2ASN_MsgChoice AT_RNIC_PDN_INFO_CFG_IND_STRU */
    ID_AT_RNIC_PDN_INFO_REL_IND         = 0x000A,   /* Share-PDP释放指示 */      /* _H2ASN_MsgChoice AT_RNIC_PDN_INFO_REL_IND_STRU */
    /* Added by L47619 for V3R3 Share-PDP Project, 2013-6-3, end */
    ID_AT_RNIC_USB_TETHER_INFO_IND      = 0x000B,   /* USB Tethering信息指示 */ /* _H2ASN_MsgChoice AT_RNIC_USB_TETHER_INFO_IND_STRU */

    /* RNIC发给AT的消息枚举 */
    ID_RNIC_AT_PDP_OPERATE_IND          = 0x1001,   /* PDP激活或者去激活指示 */ /* _H2ASN_MsgChoice RNIC_AT_PDP_OPERATE_IND_STRU */
    ID_RNIC_AT_DSFLOW_RSP               = 0x1002,   /* 流量回复 */              /* _H2ASN_MsgChoice RNIC_AT_DSFLOW_RSP_STRU */
    ID_RNIC_AT_DIAL_MODE_CNF            = 0x1003,   /* 拨号模式查询回复 */      /* _H2ASN_MsgChoice RNIC_AT_DIAL_MODE_CNF_STRU */
    ID_RNIC_AT_MSG_ID_ENUM_BUTT

};
typedef VOS_UINT32 AT_RNIC_MSG_ID_ENUM_UINT32;

/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


typedef struct
{
    VOS_MSG_HEADER                                                                  /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                    /* 消息ID */    /* _H2ASN_Skip */
    MN_CLIENT_ID_T                      clientId;                   /* Client ID */
    VOS_UINT8                           aucRsv[2];                  /* 保留 */
}AT_RNIC_DIAL_MODE_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                  /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                    /* 消息ID */    /* _H2ASN_Skip */
    MN_CLIENT_ID_T                      clientId;                   /* Client ID */
    VOS_UINT8                           aucRsv[2];                  /* 保留 */
    VOS_UINT32                          ulDialMode;                 /* Dial模式 */
    VOS_UINT32                          ulIdleTime;                 /* 定时器长度 */
    VOS_UINT32                          ulEventReportFlag;          /*是否给应用上报标识*/
}RNIC_AT_DIAL_MODE_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                  /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                    /* 消息ID */    /* _H2ASN_Skip */
    MN_CLIENT_ID_T                      clientId;                   /* Client ID */
    /* Modified by l60609 for V9R1 IPv6&TAF/SM Project, 2013-4-27, begin */
    RNIC_RMNET_ID_ENUM_UINT8            enRnicRmNetId;              /* RNIC网卡ID */
    VOS_UINT8                           aucRsv[1];                  /* 保留 */
    /* Modified by l60609 for V9R1 IPv6&TAF/SM Project, 2013-4-27, end */
}AT_RNIC_DSFLOW_IND_STRU;


typedef struct RNIC_DATA_RATE_STRU
{
    VOS_UINT32                          ulDLDataRate;                           /* 当前下行速率 */
    VOS_UINT32                          ulULDataRate;                           /* 当前上行速率 */
}RNIC_DATA_RATE_STRU;




typedef struct
{
    VOS_MSG_HEADER                                                  /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                    /* 消息类型 */  /* _H2ASN_Skip */
    MN_CLIENT_ID_T                      clientId;                   /* Client ID */
    VOS_UINT8                           aucRsv[2];                  /* 保留 */
    RNIC_DATA_RATE_STRU                 stRnicDataRate;             /* 当前流量速率 */
}RNIC_AT_DSFLOW_RSP_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                  /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                    /* 消息类型 */  /* _H2ASN_Skip */
    VOS_UINT8                           ucRabId;                    /* RAB标识，取值范围:[5,15] */
    VOS_UINT8                           ucRmNetId;                  /* 网卡ID */

    VOS_UINT8                           aucRsv[2];

    VOS_UINT32                          ulIpv4Addr;                 /* IPV4的IP地址，主机序 */
    VOS_UINT32                          ulNetMask;                  /* IPV4的掩码，主机序 */
    VOS_UINT32                          ulGateWay;                  /* IPV4的网关地址，主机序 */

    VOS_UINT32                          OP_PriDns   : 1;
    VOS_UINT32                          OP_SecDns   : 1;
    VOS_UINT32                          OP_PriWINNS : 1;
    VOS_UINT32                          OP_SecWINNS : 1;
    VOS_UINT32                          OP_Spare    : 28;
    VOS_UINT32                          ulPrimDNS;                  /* IPV4的主DNS，主机序 */
    VOS_UINT32                          ulSecDNS;                   /* IPV4的主DNS，主机序 */
    VOS_UINT32                          ulPrimWINNS;                /* IPV4的主WINNS，主机序 */
    VOS_UINT32                          ulSecWINNS;                 /* IPV4的副WINNS，主机序 */
}AT_RNIC_IPV4_PDP_ACT_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */  /* _H2ASN_Skip */
    VOS_UINT8                           ucRabId;                                /* RAB标识，取值范围:[5,15] */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */

    VOS_UINT8                           aucRsv[2];

    VOS_UINT8                           aucIpv6Addr[RNICITF_MAX_IPV6_ADDR_LEN]; /* 从 PDP上下文带来的IPV6地址长度，不包括":" */

    VOS_UINT32                          OP_PriDns   : 1;
    VOS_UINT32                          OP_SecDns   : 1;
    VOS_UINT32                          OP_Spare    : 30;
    VOS_UINT8                           aucPrimDNS[RNICITF_MAX_IPV6_ADDR_LEN];  /* 从 PDP上下文带来的IPV6主DNS长度，不包括":" */
    VOS_UINT8                           aucSecDNS[RNICITF_MAX_IPV6_ADDR_LEN];   /* 从 PDP上下文带来的IPV6副DNS长度，不包括":" */
}AT_RNIC_IPV6_PDP_ACT_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */  /* _H2ASN_Skip */

    VOS_UINT32                          OP_IPv4PriDns   : 1;
    VOS_UINT32                          OP_IPv4SecDns   : 1;
    VOS_UINT32                          OP_IPv4PriWINNS : 1;
    VOS_UINT32                          OP_IPv4SecWINNS : 1;
    VOS_UINT32                          OP_IPv6PriDns   : 1;
    VOS_UINT32                          OP_IPv6SecDns   : 1;
    VOS_UINT32                          OP_Spare    : 26;

    VOS_UINT8                           ucRabId;                                /* RAB标识，取值范围:[5,15] */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */

    VOS_UINT8                           aucRsv[2];


    VOS_UINT32                          ulIpv4Addr;                             /* IPV4的IP地址，主机序 */
    VOS_UINT32                          ulIPv4NetMask;                              /* IPV4的掩码，主机序 */
    VOS_UINT32                          ulIPv4GateWay;                              /* IPV4的网关地址，主机序 */
    VOS_UINT32                          ulIPv4PrimDNS;                              /* IPV4的主DNS，主机序 */
    VOS_UINT32                          ulIPv4SecDNS;                               /* IPV4的主DNS，主机序 */
    VOS_UINT32                          ulIPv4PrimWINNS;                            /* IPV4的主WINNS，主机序 */
    VOS_UINT32                          ulIPv4SecWINNS;                             /* IPV4的副WINNS，主机序 */

    VOS_UINT8                           aucIpv6Addr[RNICITF_MAX_IPV6_ADDR_LEN];     /* 从 PDP上下文带来的IPV6地址长度，不包括":" */
    VOS_UINT8                           aucIpv6PrimDNS[RNICITF_MAX_IPV6_ADDR_LEN];  /* 从 PDP上下文带来的IPV6主DNS长度，不包括":" */
    VOS_UINT8                           aucIpv6SecDNS[RNICITF_MAX_IPV6_ADDR_LEN];   /* 从 PDP上下文带来的IPV6副DNS长度，不包括":" */

}AT_RNIC_IPV4V6_PDP_ACT_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */  /* _H2ASN_Skip */
    VOS_UINT8                           ucRabId;                                /* RAB标识，取值范围:[5,15] */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */
    VOS_UINT8                           aucRsv[2];
}AT_RNIC_PDP_DEACT_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头 */    /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */  /* _H2ASN_Skip */
    VOS_UINT32                          ulMtuValue;                             /* MTU值 */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */
    VOS_UINT8                           aucRsv[3];                              /* 保留 */
}AT_RNIC_MTU_CHANGE_IND_STRU;


/* Added by L47619 for V3R3 Share-PDP Project, 2013-6-3, begin */

typedef struct
{
    VOS_UINT32                          ulPdnAddr;                              /* IP地址 */
    VOS_UINT32                          ulSubnetMask;                           /* 子网掩码地址 */
    VOS_UINT32                          ulGateWayAddr;                          /* 网关地址 */
    VOS_UINT32                          ulDnsPrimAddr;                          /* 主DNS地址 */
    VOS_UINT32                          ulDnsSecAddr;                           /* 副DNS地址 */
    VOS_UINT32                          ulWinnsPrimAddr;                         /* 主WINNS地址 */
    VOS_UINT32                          ulWinnsSecAddr;                          /* 副WINNS地址 */
    VOS_UINT32                          ulPcscfPrimAddr;                        /* 主P-CSCF地址 */
    VOS_UINT32                          ulPcscfSecAddr;                         /* 副P-CSCF地址 */
    VOS_UINT32                          ulPcscfThiAddr;                         /* 第三P-CSCF地址 */
}AT_RNIC_IPV4_PDN_INFO_STRU;


typedef struct
{
    VOS_UINT8                           aucPdnAddr[RNICITF_MAX_IPV6_ADDR_LEN];      /* IP地址 */
    VOS_UINT8                           aucDnsPrimAddr[RNICITF_MAX_IPV6_ADDR_LEN];  /* 主DNS地址 */
    VOS_UINT8                           aucDnsSecAddr[RNICITF_MAX_IPV6_ADDR_LEN];   /* 副DNS地址 */
    VOS_UINT8                           aucPcscfPrimAddr[RNICITF_MAX_IPV6_ADDR_LEN];/* 主P-CSCF地址 */
    VOS_UINT8                           aucPcscfSecAddr[RNICITF_MAX_IPV6_ADDR_LEN]; /* 副P-CSCF地址 */
    VOS_UINT8                           aucPcscfThiAddr[RNICITF_MAX_IPV6_ADDR_LEN]; /* 第三P-CSCF地址 */
} AT_RNIC_IPV6_PDN_INFO_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头   */      /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */      /* _H2ASN_Skip */

    VOS_UINT32                          bitOpIpv4PdnInfo    : 1;
    VOS_UINT32                          bitOpIpv6PdnInfo    : 1;
    VOS_UINT32                          bitOpSpare          : 30;

    VOS_UINT8                           ucRabId;                                /* 承载号, 范围[5, 15] */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */
    VOS_UINT8                           aucRev[2];

    AT_RNIC_IPV4_PDN_INFO_STRU          stIpv4PdnInfo;                          /* IPv4 PDN连接信息 */
    AT_RNIC_IPV6_PDN_INFO_STRU          stIpv6PdnInfo;                          /* IPv6 PDN连接信息 */

} AT_RNIC_PDN_INFO_CFG_IND_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头   */      /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */      /* _H2ASN_Skip */

    VOS_UINT8                           ucRabId;                                /* 范围[5, 15] */
    VOS_UINT8                           ucRmNetId;                              /* 网卡ID */
    VOS_UINT8                           aucRsv[2];

} AT_RNIC_PDN_INFO_REL_IND_STRU;
/* Added by L47619 for V3R3 Share-PDP Project, 2013-6-3, end */


typedef struct
{
    VOS_MSG_HEADER                                                              /* 消息头   */      /* _H2ASN_Skip */
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;                                /* 消息类型 */      /* _H2ASN_Skip */

    VOS_UINT8                           aucRmnetName[RNIC_RMNET_NAME_MAX_LEN];  /* Rmnet网卡名 */
    AT_RNIC_USB_TETHER_CONN_ENUM_UINT8  enTetherConnStat;                       /* USB Tethering连接状态 */
    VOS_UINT8                           aucRsv[3];

} AT_RNIC_USB_TETHER_INFO_IND_STRU;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/

/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    AT_RNIC_MSG_ID_ENUM_UINT32          enMsgId;            /* _H2ASN_MsgChoice_Export AT_RNIC_MSG_ID_ENUM_UINT32 */
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          AT_RNIC_MSG_ID_ENUM_UINT32
    ****************************************************************************/
} AT_RNIC_INTERFACE_MSG_DATA;
/* _H2ASN_Length UINT32 */

typedef struct
{
    VOS_MSG_HEADER
    AT_RNIC_INTERFACE_MSG_DATA          stMsgData;
} AtRnicInterface_MSG;

/*****************************************************************************
  10 函数声明
*****************************************************************************/



#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* AtRnicInterface.h */
