/*$Source: D:/STB_BASE_HAL/vfd.fulan.7167/test/panel.h,v $*/
/*****************************文件头部注释*************************************/
//
//			Copyright (C), 2008-2013, AV Frontier Tech. Co., Ltd.
//
//
// 文 件 名：	$RCSfile: panel.h,v $
//
// 创 建 者：	D02SH
//
// 创建时间：	2008.12.03
//
// 最后更新：	$Date: 2011/07/07 10:47:58 $
//
//				$Author: d27lwj $
//
//				$Revision: 1.1.1.1 $
//
//				$State: Exp $
//
// 文件描述：	给外部使用的关于遥控和VFD的头文件
//
/******************************************************************************/

#ifndef __PANEL_H
#define __PANEL_H

/********************************  文件包含************************************/


#ifdef __cplusplus
extern "C" {
#endif

//#define COMBO
/********************************  常量定义************************************/
#define LOG_OFF     0
#define LOG_ON      1

/********************************  数据结构************************************/
typedef enum LogNum_e
{
/*----------------------------------11G-------------------------------------*/
	PLAY_FASTBACKWARD = 11*16+1,
	PLAY_HEAD,
	PLAY_LOG,
	PLAY_TAIL,
	PLAY_FASTFORWARD,
	PLAY_PAUSE,
    REC1,
    MUTE,
    CYCLE,
    DUBI,
    CA,
    CI,
    USB,
    DOUBLESCREEN,
    REC2,
/*----------------------------------12G-------------------------------------*/
    HDD_A8 = 12*16+1,
    HDD_A7,
    HDD_A6,
    HDD_A5,
    HDD_A4,
    HDD_A3,
    HDD_FULL,
    HDD_A2,
    HDD_A1,
    MP3,
    AC3,
    TVMODE_LOG,
    AUDIO,
    ALERT,
    HDD_A9,
/*----------------------------------13G-------------------------------------*/
    CLOCK_PM = 13*16+1,
    CLOCK_AM,
    CLOCK,
    TIME_SECOND, /*时与分之间的点*/
    DOT2,
    STANDBY,
    TER,
    DISK_S3,
    DISK_S2,
    DISK_S1,
    DISK_S0,
    SAT,
    TIMESHIFT,
    DOT1,
    CAB,	
  /*----------------------------------end-------------------------------------*/  
    LogNum_Max
}LogNum_T;

typedef struct YWVFD_Format_s
{
  unsigned char LogNum; 
  unsigned char LogSta;      
} YWVFD_Format_T; 

typedef struct YWVFD_Time_s
{
  unsigned char hour; 
  unsigned char mint;      
} YWVFD_Time_T; 

/********************************  宏 定 义************************************/
enum
{
	POWER_KEY = 88,

    TIME_SET_KEY = 87,
	UHF_KEY = 68,
	VFormat_KEY = 67,
    MUTE_KEY = 66, 
    
    TVSAT_KEY = 65,
    MUSIC_KEY = 64,
    FIND_KEY = 63,
    FAV_KEY = 62,

    MENU_KEY = 102,//HOME
    i_KEY = 61,
    EPG_KEY = 18,
    EXIT_KEY = 48,//B
    RECALL_KEY = 30,
    RECORD_KEY = 19,	
	
	UP_KEY = 103,//UP
	DOWN_KEY= 108,//DOWN
	LEFT_KEY = 105,//LEFT
	RIGHT_KEY= 106,//RIGTHT
	SELECT_KEY = 28,//ENTER	

    PLAY_KEY = 25,
    PAGE_UP_KEY = 104,	//P_UP
    PAUSE_KEY = 22,
    PAGE_DOWN_KEY = 109,//P_DOWN

    STOP_KEY = 20,
	SLOW_MOTION_KEY = 50,
	FAST_REWIND_KEY = 33,
	FAST_FORWARD_KEY = 49,

    DOCMENT_KEY = 32,
    SWITCH_PIC_KEY = 17,
    PALY_MODE_KEY = 24,
    USB_KEY = 111,

    RADIO_KEY = 110,
    SAT_KEY = 15,
    F1_KEY = 59,
	F2_KEY = 60,	
	
	RED_KEY = 44,//Z
	GREEN_KEY = 45,//X
	YELLOW_KEY = 46,//C
	BLUE_KEY = 47,//V
};
enum
{
	KEY_DIGIT0 = 11,//根据input修改
	KEY_DIGIT1 = 2,
	KEY_DIGIT2 = 3,
	KEY_DIGIT3 = 4,
	KEY_DIGIT4 = 5,
	KEY_DIGIT5 = 6,
	KEY_DIGIT6 = 7,
	KEY_DIGIT7 = 8,
	KEY_DIGIT8 = 9,
	KEY_DIGIT9 = 10
}; 
typedef enum YWPANEL_CPUSTATE_s
{
    YWPANEL_CPUSTATE_UNKNOW,
    YWPANEL_CPUSTATE_RUNNING = 0x01,
    YWPANEL_CPUSTATE_STANDBY,    
}YWPANEL_CPUSTATE_t; 

typedef enum YWPANEL_VFDSTATE_e
{
    YWPANEL_VFDSTATE_UNKNOW,
    YWPANEL_VFDSTATE_STANDBYOFF =0x01,
    YWPANEL_VFDSTATE_STANDBYON
}YWPANEL_VFDSTATE_t;
typedef enum YWPANEL_POWERONSTATE_e
{
    YWPANEL_POWERONSTATE_UNKNOW,
    YWPANEL_POWERONSTATE_RUNNING =0x01,     /*上电后进入running模式*/
    YWPANEL_POWERONSTATE_CHECKPOWERBIT       /*上电后检测状态位*/
}YWPANEL_POWERONSTATE_t;
typedef enum YWPANEL_LBDStatus_e
{        
    YWPANEL_LBD_STATUS_OFF,           
    YWPANEL_LBD_STATUS_ON,           
    YWPANEL_LBD_STATUS_FL                
}YWPANEL_LBDStatus_T;
typedef enum YWPANEL_STARTUPSTATE_e
{
    YWPANEL_STARTUPSTATE_UNKNOW,
    YWPANEL_STARTUPSTATE_ELECTRIFY =0x01,   /*上电启动*/  
    YWPANEL_STARTUPSTATE_STANDBY,            /*待机启动*/
    YWPANEL_STARTUPSTATE_TIMER            /*待机启动*/
}YWPANEL_STARTUPSTATE_t;

typedef enum YWPANEL_LOOPSTATE_e
{
    YWPANEL_LOOPSTATE_UNKNOW,
    YWPANEL_LOOPSTATE_LOOPOFF =0x01,     
    YWPANEL_LOOPSTATE_LOOPON       
}YWPANEL_LOOPSTATE_t;



typedef struct YWPANEL_CpuState_s
{
    YWPANEL_CPUSTATE_t state; 
    
}YWPANEL_CpuState_t;

typedef struct YWVFD_FuncKey_s
{
  unsigned char key_index; 
  unsigned int  key_value;      
} YWVFD_FuncKey_T; 
/********************************  ************************************/
typedef enum YWVFD_TYPE_s
{    
  YWVFD_UNKNOW,
  YWVFD_COMMON, 
  YWVFD_STAND_BY      
} YWVFD_TYPE_t; 

typedef struct YWVFD_INFO_s
{
  YWVFD_TYPE_t vfd_type;   
} YWVFD_INFO_t; 

/********************************  变量引用************************************/

/********************************  函数声明************************************/

/********************************  函数定义************************************/

#define BASE_VFD_PRIVATE 0x00

#define VFD_GetRevision         _IOWR('s',(BASE_VFD_PRIVATE+0),char*)
#define VFD_ShowLog             _IOWR('s',(BASE_VFD_PRIVATE+1),YWVFD_Format_T)
#define VFD_ShowTime            _IOWR('s',(BASE_VFD_PRIVATE+2),YWVFD_Time_T)
#define VFD_ShowStr             _IOWR('s',(BASE_VFD_PRIVATE+3),char*)
#define VFD_ClearTime           _IOWR('s',(BASE_VFD_PRIVATE+4),int)
#define VFD_SetBright           _IOWR('s',(BASE_VFD_PRIVATE+5),int)
#define VFD_GetCPUState         _IOWR('s',(BASE_VFD_PRIVATE+6),YWPANEL_CPUSTATE_t)
#define VFD_SetCPUState         _IOWR('s',(BASE_VFD_PRIVATE+7),YWPANEL_CPUSTATE_t)
#define VFD_GetStartUpState     _IOWR('s',(BASE_VFD_PRIVATE+8),YWPANEL_STARTUPSTATE_t)
#define VFD_GetVFDState         _IOWR('s',(BASE_VFD_PRIVATE+9),YWPANEL_VFDSTATE_t)
#define VFD_SetVFDState         _IOWR('s',(BASE_VFD_PRIVATE+10),YWPANEL_VFDSTATE_t)
#define VFD_GetPOWERONState     _IOWR('s',(BASE_VFD_PRIVATE+11),YWPANEL_POWERONSTATE_t)
#define VFD_SetPOWERONState     _IOWR('s',(BASE_VFD_PRIVATE+12),YWPANEL_POWERONSTATE_t)
#define VFD_GetTime             _IOWR('s',(BASE_VFD_PRIVATE+13),u32)
#define VFD_SetTime             _IOWR('s',(BASE_VFD_PRIVATE+14),u32)
#define VFD_ControlTime         _IOWR('s',(BASE_VFD_PRIVATE+15),int)
#define VFD_GetStandByKey       _IOWR('s',(BASE_VFD_PRIVATE+16),YWVFD_FuncKey_T)
#define VFD_SetStandByKey       _IOWR('s',(BASE_VFD_PRIVATE+17),YWVFD_FuncKey_T)
#define VFD_GetBlueKey          _IOWR('s',(BASE_VFD_PRIVATE+18),YWVFD_FuncKey_T)
#define VFD_SetBlueKey          _IOWR('s',(BASE_VFD_PRIVATE+19),YWVFD_FuncKey_T)
#define VFD_GetPowerOnTime      _IOWR('s',(BASE_VFD_PRIVATE+20),u32)
#define VFD_SetPowerOnTime      _IOWR('s',(BASE_VFD_PRIVATE+21),u32)
#define VFD_ControlLBD          _IOWR('s',(BASE_VFD_PRIVATE+22),YWPANEL_LBDStatus_T)

#ifdef __cplusplus
}
#endif


#endif  /* __PANEL_H */
/* EOF------------------------------------------------------------------------*/

/* BOL-------------------------------------------------------------------*/
//$Log: panel.h,v $
//Revision 1.1.1.1  2011/07/07 10:47:58  d27lwj
//no message
//
//Revision 1.1  2010/07/14 04:56:35  d27lwj
//升级NAND FLASH时面板驱动程序
//
//Revision 1.3  2009/11/27 01:15:29  d22cj
//修改部分VFD功能，使支持屏为LED时的面板，但还有扫键出错的问题
//
//Revision 1.2  2009/11/11 03:04:18  d48zm
//vfd自动检测导入
//
//Revision 1.1.1.1  2009/11/04 12:59:06  d22cj
//基于stsdk-a20的STI7111平台导入
//
//Revision 1.3  2009/06/10 03:51:06  d02sh
//加入COMBO支持
//
//Revision 1.2  2009/05/08 01:54:47  d22cj
//1、修改文档sparkdrv_framebuffer.doc，增加设置FrameBuffer图层设置透明度的用法，值得注意的是1080I时透明度的设置范围与其它分辨率不同，参考testapps/framebuffer_test，需要更新驱动stgfb_core.ko
//2、增加automount.sh和mdev.conf脚本，在dependence
//3、修改串口，使其支持SPCS，需更新内核
//
//Revision 1.1.1.1  2009/04/03 07:18:48  d22cj
//sparkdrv_stsdk版首次导入，与sparkdrv_0_4_00对应
//
/* EOL-------------------------------------------------------------------*/

