///////////////////////////////////////////////////////////////////////////////////
//DYULCCommonDefine.h

//此文件用于定义的收录系统总体设置的数据库结构
///////////////////////////////////////////////////////////////////////////////////

#if !defined( __H__DYULCCommonDefine__H__ )
#define __H__DYULCCommonDefine__H__

#include "\Dayang\Include\DYE_CommonDefine.h"
#include "\dayang\dyrsoftwaresdk\dayangresearch\include\dyr_dmc\dyr_dmc_codeccommondefine.h"
//#include "\Dayang\Include\DYCommonVADefine.h"

struct SDYULCHeadInfo
{
	CString 	strColumnName;              //列名称
	int		    nColumnIndex;               //列序号
	int		    nColumnWidth;               //列宽度

	SDYULCHeadInfo()
	{
		strColumnName = _T("");
		nColumnIndex  = 0;
		nColumnWidth  = 100;
	};

	SDYULCHeadInfo(const SDYULCHeadInfo &other)
	{
		*this = other;
	};

	SDYULCHeadInfo& operator = (const SDYULCHeadInfo& other)
	{
		strColumnName = other.strColumnName;
		nColumnIndex  = other.nColumnIndex;
		nColumnWidth  = other.nColumnWidth;
		return *this;
	};
};
typedef CArray<SDYULCHeadInfo, SDYULCHeadInfo&> ASDYULCHeadInfoArray;

//实际任务生成方式
enum  DYULC_TASK_CREATETYPE
{
	DYULCDEVICE_TASKCREATE_UNKNOWN		= 0,   
	DYULCDEVICE_TASKCREATE_ATCREATE		= 1,	//一添加预约任务就生成对应的实际任务
	DYULCDEVICE_TASKCREATE_ATAUDIT		= 2,	//审核完成以后生成预约任务对应的实际任务
};

//收录中心的整体参数
struct SDYULCParamInfo
{
	BOOL	                    IfVASplite;                          //VA是否分离
	BOOL					    IfResetToWait;                       //是否重设为可执行

	BOOL					    IfLinkMsgServer;                     //是否连接消息服务器
	int                         masterskport;                        //与新闻连接主通道                      
	int                         backupskport;                        //与新闻连接备通道
	CString                     masterskip;                          //与新闻连接主IP
	CString                     backupskip;                          //与新闻连接备IP

	CString                     strLogPath;                          //日志路径,网络路径

	BOOL                        bIfNeedpreAllocate;                  //是否需要预分配
    int                         nPreAllocateTime;                    //预分配提前时间，以分钟为单位

	int                         nPreLockTime;                        //提前锁定，距当前时间多少不准添加任务限制

	BOOL                        bNeedLocalToNet;                     //是否采用先本地再网络的模式采集
	BOOL                        bNeedCapCompile;                     //是否任务都是采用边采边编的方式
	BOOL                        bNeedInpect;                         //是否需要技审
	BOOL                        bNeedCapTrans;                       //是否边采集边传送

	BOOL                        bIfCapSeg;                           //是否分段采集
	int                         nCapSegTime;                         //分段采集时间，秒
	
	int                         nTransDelayTime;                     //迁移延迟时间，以分钟为单位

	DYULC_TASK_CREATETYPE		enumTaskCreateType;					//实际任务生成的方式
	int							nArrangeLimitMinute;				//编排任务时间阀值，小于就不能修改

	BOOL						bCreatePreTaskInfo;					//添加任务时，生成和实际任务对应的预约任务
	int							nCutDelayMin;						//从收录任务剪切一段生成素材，延长的分钟

	BOOL                        bIfLimitTaskNum;                    //是否限制任务条数
	int                         nLimitTaskNum;                      //限制任务条数
    BOOL                        bIfUseWorkFlow;                      //是否使用工作流插件

	SDYULCParamInfo()
	{
		IfVASplite      = FALSE;    
		IfResetToWait   = FALSE; 
		IfLinkMsgServer = FALSE;    
		masterskport    = 0;
		backupskport    = 0;
		masterskip      = _T("");
		backupskip      = _T("");
		strLogPath      = _T("");

		bIfNeedpreAllocate = FALSE;
		nPreAllocateTime   = 0;

		nPreLockTime       = 0;

		bNeedLocalToNet    = FALSE;
		bNeedCapCompile    = FALSE;
		bNeedInpect        = FALSE;
		bNeedCapTrans      = FALSE;
		bIfCapSeg          = FALSE;
        nCapSegTime        = 0;

		nTransDelayTime    = 0;
		enumTaskCreateType = DYULCDEVICE_TASKCREATE_UNKNOWN;
		nArrangeLimitMinute	= 0;

		bCreatePreTaskInfo = FALSE;
		nCutDelayMin = 0;

        bIfLimitTaskNum = FALSE;
	    nLimitTaskNum = 100;
            bIfUseWorkFlow = FALSE;
	};

	SDYULCParamInfo(const SDYULCParamInfo &other)
	{
		*this = other;
	};	

	SDYULCParamInfo& operator = (const SDYULCParamInfo& other)
	{
		IfVASplite      = other.IfVASplite;    
		IfResetToWait   = other.IfResetToWait; 
		IfLinkMsgServer = other.IfLinkMsgServer;    
		masterskport    = other.masterskport;
		backupskport    = other.backupskport;
		masterskip      = other.masterskip;
		backupskip      = other.backupskip;
		
		strLogPath        = other.strLogPath;

		bIfNeedpreAllocate = other.bIfNeedpreAllocate;
		nPreAllocateTime   = other.nPreAllocateTime;

		nPreLockTime       = other.nPreLockTime;

		bNeedLocalToNet    = other.bNeedLocalToNet;
		bNeedCapCompile    = other.bNeedCapCompile;
		bNeedInpect        = other.bNeedInpect;
		bNeedCapTrans      = other.bNeedCapTrans;
        
        bIfCapSeg          = other.bIfCapSeg;
        nCapSegTime        = other.nCapSegTime;

		nTransDelayTime    = other.nTransDelayTime;
		enumTaskCreateType = other.enumTaskCreateType;
		nArrangeLimitMinute   = other.nArrangeLimitMinute;
		bCreatePreTaskInfo = other.bCreatePreTaskInfo;
		nCutDelayMin = other.nCutDelayMin;

		bIfLimitTaskNum = other.bIfLimitTaskNum;
		nLimitTaskNum = other.nLimitTaskNum;
                bIfUseWorkFlow = other.bIfUseWorkFlow;
		return *this;
	};
};

//设备通道属性
enum  DYULC_DEVICE_PORTDIR
{
	DYULCDEVICE_PORTDIR_UNKNOWN				= 0,   
	DYULCDEVICE_PORTDIR_IN					= 1,	//输入通道
	DYULCDEVICE_PORTDIR_OUT					= 2,	//输出通道	
};

//设备通道工作状态
enum  DYULC_DEVICE_PORTSTATUS
{
	DYULDEVICE_PORTSTATUS_FREE              = 0X00000000,   //空闲
	DYULDEVICE_PORTSTATUS_LOCK              = 0X00000001,   //锁定
	DYULDEVICE_PORTSTATUS_PRELOCK           = 0X00000002,   //预分配锁定
	DYULDEVICE_PORTSTATUS_HANDLELOCK        = 0X00000003,   //手动锁定
};

//信号通道信号类型,命令控制通道控制方式
typedef DWORD DYULCPORTPROPERTYFLAG;
// 设备(信号)通道类型
enum  DYULC_DEVICE_PORTTYPE
{
	DYULCDEVICE_PORTTYPE_UNKNOWN			= 0x00000000,

	DYULCDEVICE_PORTTYPE_V					= 0x00000001,	//Video 输入通道
	DYULCDEVICE_PORTTYPE_A					= 0x00000002,	//Audio 输入通道
	DYULCDEVICE_PORTTYPE_VA					= 0x00000004,	//VA SDI 输入通道
	DYULCDEVICE_PORTTYPE_TS					= 0x00000008,	//VA TS 输入通道
	DYULCDEVICE_PORTTYPE_SDTI				= 0x00000010,	//VA SDTI 输入通道
	DYULCDEVICE_PORTTYPE_SDTI_CP			= 0x00000020,	//VA SDTI CP 输入通道
	DYULCDEVICE_PORTTYPE_1394_25M			= 0x00000040,	//VA 1394-DV25 输入输出通道
	DYULCDEVICE_PORTTYPE_1394_50M			= 0x00000080,	//VA 1394-DV50 输入输出通道
	DYULCDEVICE_PORTTYPE_UDP			    = 0x00000100,	//UDP控制通道

	DYULCDEVICE_PORTTYPE_CTRL_232			= 0x10000000,	//通过232口命令控制通道
	DYULCDEVICE_PORTTYPE_CTRL_422			= 0x20000000,	//通过422口命令控制通道
	DYULCDEVICE_PORTTYPE_CTRL_Socket		= 0x40000000,	//通过Socket口命令控制通道
};

//设备种类
enum DYULC_DEVICE_TYPE
{
	DYULC_DEVICE_UNKOWN						=	0,	//未知设备
	DYULC_DEVICE_VTR						=	1,	//VTR
	DYULC_DEVICE_SATREVEIVER				=	2,	//卫星接收机
	DYULC_DEVICE_UPLOAD						=	3,	//采集工作站
	DYULC_DEVICE_VIDEOSERVER				=	4,	//视频服务器
	DYULC_DEVICE_MATRIX_VA					=	5,	//视音频矩阵
	DYULC_DEVICE_MATRIX_CTRL				=	6,	//控制矩阵
	DYULC_DEVICE_BYPASSSIGNAL				=	7,	//By Pass Signal
	DYULC_DEVICE_MANAGER					=	8,	//Manager
	DYULC_DEVICE_PC_CTRL					=	9,	//PC(VDCP or 422)Ctrl Server or VTR
	DYULC_DEVICE_XEDIT					    =	10,	//非编工作站
	DYULC_DEVICE_MEDIAGATEWAY               =   11, //媒体网关
	DYULC_DEVICE_DECODER                    =   12, //解码器
	DYULC_DEVICE_ENCODER                    =   13, //编码器
	DYULC_DEVICE_SATSIGPROCESSOR            =   14, //卫星信号解出设备
	DYULC_DEVICE_ADEMBED                    =   15, //A/D嵌入设备，（模拟调节器）
	DYULC_DEVICE_ADOUTBED                   =   16, //A/D解出设备
	DYULC_DEVICE_TVDECODER                  =   17, //电视解调器
	DYULC_DEVICE_DIGITALSIGPROCESSER        =   18, //数字信号质量处理设备
	DYULC_DEVICE_DIGITALSIGSHOWER           =   19, //数字信号分割显示器
	DYULC_DEVICE_SIGPLAYER                  =   20, //信号播放设备
	DYULC_DEVICE_MACHINETOP                 =   21, //机顶盒
	DYULC_DEVICE_MACHINEPERIPHERAL          =   22, //外部采集控制设备（比如DY3000）
	DYULC_DEVICE_CHANGEVIDEOSTANDARD        =   23, //制转设备
	DYULC_DEVICE_VIDEOSPLITTERDEVICE        =   24, //视分设备
	DYULC_DEVICE_MONITOR	                =   25, //监控部分 
	DYULC_DEVICE_PHEDEVICEMANAGER		    =	26,	//外部采集设备控制的设备
    DYULC_DEVICE_PHEDEVICE  				=	27,	//外部采集设备
	DYULC_DEVICE_RESERVED3                  =   28, //保留字段
	DYULC_DEVICE_RESERVED4                  =   29, //保留字段                 
	DYULC_DEVICE_RESERVED5                  =   30, //保留字段
};

enum  DYULC_UDP_PACKTYPE
{
	DYULC_UDP_NO                            = 0x00000000,   //不考虑
	DYULC_UDP_TS			                = 0x00000001,   //一般TS封装
	DYULC_UDP_TSMPEG2                       = 0x00000002,   //MPEG2封装的TS
	DYULC_UDP_PS                            = 0x00000004,   //一般PS封装
	DYULC_UDP_PSMPEG2                       = 0x00000008,   //MPEG2封装的PS
	DYULC_UDP_H264                          = 0x00000010,   //一般H264封装

	DYULC_UDP_HDTS			                = 0x00000020,   //高清TS封装
	DYULC_UDP_HDPS                          = 0x00000040,   //高清PS封装
	DYULC_UDP_HDH264                        = 0x00000080,   //高清H264封装
    
	DYULC_UDP_RTSP	                        = 0x00000100,   //rtsp
    DYULC_UDP_HTTP	                        = 0x00000200,   //http
	DYULC_UDP_RTP	                        = 0x00000400,   //RTP
    DYULC_UDP_OTHER	                        = 0x00000800,   //其他

	DYULC_UDP_UNICAST                       = 0x10000000,   //单播模式
};

//不同UDP占用通道设置
struct SDYULCUDPPackPortSet
{
	int     nTsSetPort;             //一般TS
	int     nTSMpeg2Port;           //MPEG2TS
	int     nPsPort;                //一般PS
	int     nPSMpeg2Port;           //MPEG2PS
	int     nH264Port;              //一般H264

	int     nHDTSPort;              //高清TS
	int     nHDPSPort;              //高清PS
	int     nHDH264Port;            //高清H264

	SDYULCUDPPackPortSet()
	{
		nTsSetPort      = 1;
		nTSMpeg2Port    = 1;
		nPsPort         = 1;
		nPSMpeg2Port    = 1;
		nH264Port       = 1;

		nHDTSPort       = 1;
		nHDPSPort       = 1;
		nHDH264Port     = 1;
	};

	SDYULCUDPPackPortSet(const SDYULCUDPPackPortSet &other)
	{
		*this = other;
	};

	SDYULCUDPPackPortSet& operator = (const SDYULCUDPPackPortSet& other)
	{
		nTsSetPort      = other.nTsSetPort;
		nTSMpeg2Port    = other.nTSMpeg2Port;
		nPsPort         = other.nPsPort;
		nPSMpeg2Port    = other.nPSMpeg2Port;
		nH264Port       = other.nH264Port;

		nHDTSPort       = other.nHDTSPort;
		nHDPSPort       = other.nHDPSPort;
		nHDH264Port     = other.nHDH264Port;

		return *this;
	};
};

// 信号源组
struct SDYULCSignalSourceGroupInfo
{
	DY_GUID		guidGroupID;				//信号组DY_GUID
	CString		strGroupName;				//信号组名称
	CString		strGroupHint;				//信号组描述

	SDYULCSignalSourceGroupInfo()
	{
		guidGroupID = GUID_NULL;
		strGroupName = _T("");
		strGroupHint = _T("");
	};

	SDYULCSignalSourceGroupInfo(const SDYULCSignalSourceGroupInfo &other)
	{
		*this = other;
	};

	SDYULCSignalSourceGroupInfo& operator = (const SDYULCSignalSourceGroupInfo& other)
	{
		guidGroupID = other.guidGroupID;
		strGroupName = other.strGroupName;
		strGroupHint = other.strGroupHint;
		return *this;
	};
};
typedef CArray<SDYULCSignalSourceGroupInfo, SDYULCSignalSourceGroupInfo&> ASDYULCSignalSourceGroupInfoArray;

// 信号源信息
struct SDYULCSignalSourceInfo
{
	DY_GUID					guidID;                       //信号源DY_GUID
	CString					strName;                      //信号源名称
	DY_GUID					guidGroupID;				  //信号源组DY_GUID
	CString					strGroupName;                 //信号源组名称
	CString					strHint;                      //信号源描述

	CString                 strZBAddress;                 //主播地址
	CString                 strZBPort;                    //主播端口

	BOOL					bIfPassSatelliteViewer;       //是否直通信号
	DYULC_DEVICE_PORTTYPE	enumPortType;                 //信号通道类型
	CString					strFreqCtrlInfo;			  //信号频点控制信息
	CString					strProgCtrlInfo;			  //信号节目控制信息

	int                     nPrerollSec;                  //信号收录提前时间    在EPG编单时使用
	int                     nLastSec;                     //信号收录延后时间    在EPG编单时使用
	CString                 strEpgServiceID;              //信号的 Service ID   在EPG编单时使用

	BOOL                    bPassGateWay;                 //是否过媒体网关


	BOOL                    bPassLMatrix;                 //是否过中频矩阵
	CString                 strInterFreSig;               //中频名称  //Satellite Freq. 这六个其实是TT卫星接收机的参数
	CString                 strInterFreRate;              //中频频率  //LNC Freq.
	CString                 strFreRate;                   //符号率    //Symbol Rate
	CString                 strForwardErr;                //前向纠错  //Inner Code
	CString                 strServiceID;                 //ServiceID
	CString                 strLNCVoltage;                //LNC Voltage
	CString                 strChannelParam;              //通道参数
	CString                 strSatOtherParam;             //其他的参数    

	BOOL                    bPassTVEncoder;               //是否过电视解调器
	CString                 strChannelIndex;              //频道号

	BOOL                    bNeedDigitalAdj;              //是否需要数字调整
	CString                 strDigiAdjParam1;             //数字调整参数1
	CString                 strDigiAdjParam2;             //数字调整参数2
	CString                 strDigiAdjParam3;             //数字调整参数3

	BOOL                    bNeedAnalogAdj;               //是否需要模拟调整
	CString                 strAnagadjParam1;             //模拟调整参数1
	CString                 strAnagadjParam2;             //模拟调整参数2
	CString                 strAnagadjParam3;             //模拟调整参数3

	BOOL                    bTestCardSig;                 //是否为测试信号
	BOOL                    bColorBandSig;                //是否为彩条信号

	BOOL                    bIfZemu;                      //是否需要遮幕
    DWORD				    dwZemuSizeInByte;			  //遮幕数据大小
	PBYTE					pbZemuData;			          //遮幕数据

	BOOL                    bIfHavePriority;              //是否有优先级配置
	int                     nPriority;                    //优先级

	BOOL                    bIfHaveError;                 //信号质量是否有问题	

	BOOL                    bIsHD;                        //是否为高清信号

	DYULC_UDP_PACKTYPE      enumUDPPackType;              //UDP封装方式

	BOOL					bKeepRecord;				//持续采集的信号

	DYVIDEO_SCALE_TYPE	iVideoUpScaleType;		//高清，标清上变换方式
	DYVIDEO_SCALE_TYPE	iVideoDownScaleType;	//高清，标清下变换方式

	CString             strAddtion;             //附加信息	

	SDYULCSignalSourceInfo()
	{
		guidID = GUID_NULL;
		strName = _T("");
		strGroupName = _T("");
		strHint = _T("");
		guidGroupID = GUID_NULL;

		strZBAddress = _T("");
        strZBPort    = _T("");

		bIfPassSatelliteViewer = FALSE;
		enumPortType = DYULCDEVICE_PORTTYPE_UNKNOWN;
		strFreqCtrlInfo = _T("");
		strProgCtrlInfo = _T("");
		nPrerollSec     = 0;
		nLastSec        = 0;
		strEpgServiceID = _T("");

		bPassGateWay     = FALSE;
		bPassLMatrix     = FALSE;    
		strInterFreSig   = _T("");  
		strInterFreRate  = _T(""); 
		strFreRate       = _T("");      
		strForwardErr    = _T("");  
		strServiceID     = _T(""); 
		strLNCVoltage    = _T("");
		strChannelParam  = _T("");
        strSatOtherParam = _T("");

		bPassTVEncoder   = FALSE;   
		strChannelIndex  = _T("");
		bNeedDigitalAdj  = FALSE; 
		strDigiAdjParam1 = _T("");
		strDigiAdjParam2 = _T("");
		strDigiAdjParam3 = _T("");
		bNeedAnalogAdj   = FALSE;  
		strAnagadjParam1 = _T("");
		strAnagadjParam2 = _T("");
		strAnagadjParam3 = _T("");
		bTestCardSig     = FALSE;    
		bColorBandSig    = FALSE;

        bIfZemu          = FALSE;
        dwZemuSizeInByte = 0;
		pbZemuData       = NULL;

		bIfHavePriority  = FALSE;
		nPriority        = 0;      
				
		bIfHaveError     = FALSE;
		bIsHD            = FALSE;

		enumUDPPackType  = DYULC_UDP_NO;

		bKeepRecord = FALSE;
		iVideoUpScaleType=DYVIDEO_SCALE_TYPE_NONE;
		iVideoDownScaleType=DYVIDEO_SCALE_TYPE_NONE;

		strAddtion = _T("");
	};

	~SDYULCSignalSourceInfo()
	{
		if( pbZemuData )
		{
			delete pbZemuData;
			pbZemuData = NULL;
		}
	};

	SDYULCSignalSourceInfo(const SDYULCSignalSourceInfo &other)
	{
		pbZemuData = NULL;
		*this = other;
	};

	SDYULCSignalSourceInfo& operator = (const SDYULCSignalSourceInfo& other)
	{
		guidID = other.guidID;
		strName = other.strName;
		strGroupName = other.strGroupName;
		strHint = other.strHint;
		guidGroupID = other.guidGroupID;

		strZBAddress = other.strZBAddress;
        strZBPort    = other.strZBPort;

		bIfPassSatelliteViewer = other.bIfPassSatelliteViewer;
		enumPortType = other.enumPortType;
		strFreqCtrlInfo = other.strFreqCtrlInfo;
		strProgCtrlInfo = other.strProgCtrlInfo;
		nPrerollSec     = other.nPrerollSec;
		nLastSec        = other.nLastSec;
		strEpgServiceID = other.strEpgServiceID;

		bPassGateWay     = other.bPassGateWay;
		bPassLMatrix     = other.bPassLMatrix;    
		strInterFreSig   = other.strInterFreSig;  
		strInterFreRate  = other.strInterFreRate; 
		strFreRate       = other.strFreRate;      
		strForwardErr    = other.strForwardErr;   
		strServiceID     = other.strServiceID; 
		strLNCVoltage    = other.strLNCVoltage;
		strChannelParam  = other.strChannelParam;
        strSatOtherParam = other.strSatOtherParam;

		bPassTVEncoder   = other.bPassTVEncoder;   
		strChannelIndex  = other.strChannelIndex;
		bNeedDigitalAdj  = other.bNeedDigitalAdj; 
		strDigiAdjParam1 = other.strDigiAdjParam1;
		strDigiAdjParam2 = other.strDigiAdjParam2;
		strDigiAdjParam3 = other.strDigiAdjParam3;
		bNeedAnalogAdj   = other.bNeedAnalogAdj;  
		strAnagadjParam1 = other.strAnagadjParam1;
		strAnagadjParam2 = other.strAnagadjParam2;
		strAnagadjParam3 = other.strAnagadjParam3;
		bTestCardSig     = other.bTestCardSig;    
		bColorBandSig    = other.bColorBandSig;

		bIfZemu          = other.bIfZemu;

		dwZemuSizeInByte = other.dwZemuSizeInByte;
		if( pbZemuData ) 
		{
			delete pbZemuData;
			pbZemuData = NULL;
		}
		if(other.pbZemuData && dwZemuSizeInByte > 0 ) 
		{
			pbZemuData = new BYTE[dwZemuSizeInByte];
			memcpy( pbZemuData, other.pbZemuData, dwZemuSizeInByte );
		}

		bIfHavePriority  = other.bIfHavePriority;
		nPriority        = other.nPriority;      

		bIfHaveError     = other.bIfHaveError;
		bIsHD            = other.bIsHD;
		enumUDPPackType  = other.enumUDPPackType;

		bKeepRecord = other.bKeepRecord;

		iVideoUpScaleType=other.iVideoUpScaleType;
		iVideoDownScaleType=other.iVideoDownScaleType;

		strAddtion = other.strAddtion;

		return *this;
	};
};
typedef CArray<SDYULCSignalSourceInfo, SDYULCSignalSourceInfo&> ASDYULCSignalSourceInfoArray;

// 磁带类型组
struct SDYULCVTRTapeTypeGroupInfo
{
	DY_GUID		guidGroupID;                //磁带类型组DY_GUID
	CString		strGroupName;               //磁带类型组名称
	CString		strGroupHint;               //磁带类型组描述

	SDYULCVTRTapeTypeGroupInfo()
	{
		guidGroupID = GUID_NULL;
		strGroupName = _T("");
		strGroupHint = _T("");
	};

	SDYULCVTRTapeTypeGroupInfo(const SDYULCVTRTapeTypeGroupInfo &other)
	{
		*this = other;
	};

	SDYULCVTRTapeTypeGroupInfo& operator = (const SDYULCVTRTapeTypeGroupInfo& other)
	{
		guidGroupID = other.guidGroupID;
		strGroupName = other.strGroupName;
		strGroupHint = other.strGroupHint;
		return *this;
	};
};
typedef CArray<SDYULCVTRTapeTypeGroupInfo, SDYULCVTRTapeTypeGroupInfo&> ASDYULCVTRTapeTypeGroupInfoArray;

//磁带类型
struct SDYULCVTRTapeTypeInfo
{
	DY_GUID		guidID;                //磁带类型DY_GUID
	CString		strName;               //磁带类型名称
	CString		strHint;               //磁带类型描述
	DY_GUID		guidGroupID;		   //磁带类型组DY_GUID
	CString     strGroupName;          //磁带组名称
	int         nMaxLength;            //磁带类型支持的最大长度 
	BOOL        bIfDefault;            //是否为默认磁带类型

	SDYULCVTRTapeTypeInfo()
	{
		guidID = GUID_NULL;
		strName = _T("");
		strHint = _T("");
		guidGroupID = GUID_NULL;
		strGroupName = _T("");
		nMaxLength  = 0;
		bIfDefault  = FALSE;
	};

	SDYULCVTRTapeTypeInfo(const SDYULCVTRTapeTypeInfo &other)
	{
		*this = other;
	};

	SDYULCVTRTapeTypeInfo& operator = (const SDYULCVTRTapeTypeInfo& other)
	{
		guidID              = other.guidID;
		strName             = other.strName;
		strHint             = other.strHint;
		guidGroupID         = other.guidGroupID;
		strGroupName        = other.strGroupName;
		nMaxLength          = other.nMaxLength;
		bIfDefault          = other.bIfDefault;
		return *this;
	};
};
typedef CArray<SDYULCVTRTapeTypeInfo, SDYULCVTRTapeTypeInfo&> ASDYULCVTRTapeTypeInfoArray;

//素材类，标识素材视音频类型及数据文件的存在状况
typedef	DWORD DYULCCLIPCLASSFLAG;
enum	DYULCCLIP_CLASS
{
	DYULCCLIP_CLASS_Unknow		=	0x00000000,		//	无类型
	DYULCCLIP_CLASS_V			=	0x00000001,		//	视频
	DYULCCLIP_CLASS_A			=	0x00000002,		//	音频
	DYULCCLIP_CLASS_VA			=	0x00000003,		//	视音频
};

//任务目标素材视音频格式信息
struct SDYULClipElementInfo
{
	DY_GUID                 guidID;                     //格式DY_GUID
	CString					strName;                    //格式名称
	CString					strGroupName;			    //所在格式组组名

	DYULCCLIP_CLASS			enumClass;                  //素材视音频分类
	DY_VIDEO_STANDARD		enumVideoStandard;			//视频标准
	DY_STREAM_TYPE    	    enumSpecialMediaType;		//视音频编解码格式类型
	DWORD					dwPropertyFlag;				//特别标志 see DYCLIPELEMENTPROPERTYFLAG_???

	DY_GUID                 guidGroupID;                //所在格式组DY_GUID
	SDYStreamMediaInfo		sStreamMediaInfo;		    //视音频详细信息

	SMulitProgramAppendInfo	sAppendInfo;                //附加信息
	DWORD                   dwAppendSize;
	DWORD                   dwReserve;
	CString                 strReserve;                 //

	SDYULClipElementInfo()
	{
		guidID               = GUID_NULL;
		strName              = _T("");
		strGroupName         = _T("");
		enumClass            = DYULCCLIP_CLASS_Unknow;
		enumVideoStandard    = DYVIDEOSTANDARD_UNKNOW;
		enumSpecialMediaType = DYSTREAMTYPE_UNKNOWN;
		dwPropertyFlag       = 0;

		dwAppendSize         = 0;
		dwReserve            = 0;
        strReserve           = _T("");
		
		guidGroupID          = GUID_NULL;
	};

	SDYULClipElementInfo(const SDYULClipElementInfo & other) 
	{ 
		*this = other; 
	};	

	SDYULClipElementInfo& operator = (const SDYULClipElementInfo& other)
	{
		guidID               = other.guidID;
		strName              = other.strName;
		strGroupName         = other.strGroupName;
		enumClass            = other.enumClass;
		enumVideoStandard    = other.enumVideoStandard;
		enumSpecialMediaType = other.enumSpecialMediaType;
		dwPropertyFlag       = other.dwPropertyFlag;		
		sStreamMediaInfo     = other.sStreamMediaInfo;
        sAppendInfo          = other.sAppendInfo;
        dwAppendSize         = other.dwAppendSize;
		dwReserve            = other.dwReserve;
		strReserve           = other.strReserve;
		guidGroupID          = other.guidGroupID;
		return *this;
	};
};
typedef CArray<SDYULClipElementInfo, SDYULClipElementInfo&> ASDYULClipElementInfoArray;

//视音频格式组信息
struct SDYULClipElementGroupInfo
{
	DY_GUID		guidGroupID;				//格式组DY_GUID
	CString		strGroupName;				//格式组名称
	CString		strGroupHint;				//格式组描述
	BOOL        bIfDefault;                 //是否为默认格式组

	ASDYULClipElementInfoArray	asClipElementInfo;

	SDYULClipElementGroupInfo()
	{
		guidGroupID = GUID_NULL;
		strGroupName = _T("");
		strGroupHint = _T("");
		bIfDefault   = FALSE;
	};

	SDYULClipElementGroupInfo(const SDYULClipElementGroupInfo &other)
	{
		*this = other;
	};

	~SDYULClipElementGroupInfo()
	{
		asClipElementInfo.RemoveAll();
	};

	SDYULClipElementGroupInfo& operator = (const SDYULClipElementGroupInfo& other)
	{
		guidGroupID = other.guidGroupID;
		strGroupName = other.strGroupName;
		strGroupHint = other.strGroupHint;
		bIfDefault   = other.bIfDefault;
		asClipElementInfo.Copy( other.asClipElementInfo );

		return *this;
	};
};
typedef CArray<SDYULClipElementGroupInfo, SDYULClipElementGroupInfo&> ASDYULClipElementGroupInfoArray;

//收费时间段
struct SDYULCFeeTimeBandInfo
{
    DY_GUID		    guidID;			           //
	DY_GUID            guidFeeID;                 //收费标准DY_GUID
	COleDateTime    odtBeginTime;              //起始时间
	COleDateTime    odtEndTime;                //终止时间
	int             nInitPrice;                //起步价
	int             nInitTime;                 //起步时间单位
    int             nPerPrice;                 //单价
	int             nPerTime;                  //单价时间单位

    SDYULCFeeTimeBandInfo()
	{
		guidID     = GUID_NULL;
		guidFeeID  = GUID_NULL;
		odtBeginTime = COleDateTime::GetCurrentTime();
	    odtEndTime   = COleDateTime::GetCurrentTime();
		nInitPrice = 0;
		nInitTime  = 0;
		nPerPrice  = 0;
		nPerTime   = 0;
	};
    SDYULCFeeTimeBandInfo(const SDYULCFeeTimeBandInfo &other)
	{
		*this = other;
	};

	SDYULCFeeTimeBandInfo& operator = (const SDYULCFeeTimeBandInfo& other)
	{
		guidID        = other.guidID;
		guidFeeID     = other.guidFeeID;
		odtBeginTime    = other.odtBeginTime;
		odtEndTime      = other.odtEndTime;
		nInitPrice    = other.nInitPrice;
		nInitTime     = other.nInitTime;
		nPerPrice     = other.nPerPrice;
        nPerTime      = other.nPerTime;

		return *this;
	};
};
typedef CArray<SDYULCFeeTimeBandInfo, SDYULCFeeTimeBandInfo&> ASDYULCFeeTimeBandInfoArray;

//收费标准
struct SDYULCCatlogFeeInfo
{
    DY_GUID		       guidFeeID;		            //收费标准DY_GUID

	BOOL               bIfDeviceType;               //是以信号还是采集设备
	DYULC_DEVICE_TYPE  enumDeviceType;              //采集设备类型
    DY_GUID		       guidSigGroupID;		        //信号组DY_GUID
	CString            strSigGroupName;             //信号组名称

	COleDateTime       odtBeginDate;                //有效起始日期
	COleDateTime       odtEndDate;                  //有效终止日期

	ASDYULCFeeTimeBandInfoArray	asFeeTimeBandInfo;  //时间段


	SDYULCCatlogFeeInfo()
	{
		guidFeeID         = GUID_NULL;

		bIfDeviceType     = TRUE;
		enumDeviceType    = DYULC_DEVICE_UNKOWN;
		guidSigGroupID    = GUID_NULL;
		strSigGroupName   = _T("");
				
		odtBeginDate.SetDate(2009,1,1);
		odtEndDate.SetDate(3000,1,1);
	};

	SDYULCCatlogFeeInfo(const SDYULCCatlogFeeInfo &other)
	{
		*this = other;
	};
    
	~SDYULCCatlogFeeInfo()
	{
		asFeeTimeBandInfo.RemoveAll();
	};

	SDYULCCatlogFeeInfo& operator = (const SDYULCCatlogFeeInfo& other)
	{
		guidFeeID         = other.guidFeeID;

		bIfDeviceType     = other.bIfDeviceType;
		enumDeviceType    = other.enumDeviceType;
		guidSigGroupID    = other.guidSigGroupID;
		strSigGroupName   = other.strSigGroupName;
		
		odtBeginDate    = other.odtBeginDate;
		odtEndDate      = other.odtEndDate;

		asFeeTimeBandInfo.Copy( other.asFeeTimeBandInfo );
		return *this;
	};
};
typedef CArray<SDYULCCatlogFeeInfo, SDYULCCatlogFeeInfo&> ASDYULCCatlogFeeInfoArray;

//任务插件类型信息
struct SDYULCPlugInTypeInfo
{
	DY_GUID		guidID;	                      //插件DY_GUID
	CString		strName;                      //插件名称
	CString		strCFName;                    //插件唯一名称（全大写）
	CString     strHint;                      //插件描述

	int         iPreferType;                  //提交类型,1(调用主干)2(工作流)3(ESB/EMB)4(ftp)5(存储路径)6(素材命名)
    CString     strParam;                     //参数

	int         iReserve;
	CString     strReserve;

	SDYULCPlugInTypeInfo()
	{
		guidID         = GUID_NULL;
		strName        = _T("");
		strCFName      = _T("");
		strHint        = _T("");
        iPreferType    = 0;
		strParam       = _T("");
        
		iReserve       = 0;
        strReserve     = _T("");
	};

	SDYULCPlugInTypeInfo(const SDYULCPlugInTypeInfo &other)
	{
		*this = other;
	};
    
	SDYULCPlugInTypeInfo& operator = (const SDYULCPlugInTypeInfo& other)
	{
		guidID              = other.guidID;
		strName             = other.strName;		
		strCFName           = other.strCFName;
		strHint             = other.strHint;

		iPreferType         = other.iPreferType;
		strParam            = other.strParam;
        
		iReserve            = other.iReserve;
        strReserve          = other.strReserve;

		return *this;
	};
};
typedef CArray<SDYULCPlugInTypeInfo, SDYULCPlugInTypeInfo&> ASDYULCPlugInTypeInfoArray;

//设备支持的磁带类型（用于录机设备）
struct SDYULCSUPTVtrTapeTypeInfo
{
	DY_GUID   guidDeviceID;                      //设备DY_GUID
	DY_GUID   guidVTRTapeTypeGuid;               //磁带类型guid

	SDYULCSUPTVtrTapeTypeInfo()
	{
		guidDeviceID          = GUID_NULL;
		guidVTRTapeTypeGuid   = GUID_NULL;
	}

	SDYULCSUPTVtrTapeTypeInfo(const SDYULCSUPTVtrTapeTypeInfo &other)
	{
		*this = other;
	};

	SDYULCSUPTVtrTapeTypeInfo& operator = (const SDYULCSUPTVtrTapeTypeInfo& other)
	{
		guidDeviceID          = other.guidDeviceID;
		guidVTRTapeTypeGuid   = other.guidVTRTapeTypeGuid;	

		return *this;
	};
};
typedef CArray <SDYULCSUPTVtrTapeTypeInfo, SDYULCSUPTVtrTapeTypeInfo&> ASDYULCSUPTVtrTapeTypeInfoArray;

//设备支持的信号（指直通设备或卫星接收机）
struct SDYULCDeviceSigInfo
{
	DY_GUID	 guidDeviceID;                //设备DY_GUID
	DY_GUID     guidSigID;                   //信号guid

	SDYULCDeviceSigInfo()
	{
		guidDeviceID = GUID_NULL;
		guidSigID    = GUID_NULL;
	};

	SDYULCDeviceSigInfo(const SDYULCDeviceSigInfo &other)
	{
		*this = other;
	};
	
	SDYULCDeviceSigInfo& operator = (const SDYULCDeviceSigInfo& other)
	{
		guidDeviceID = other.guidDeviceID;
		guidSigID    = other.guidSigID;

		return *this;
	};
};
typedef CArray<SDYULCDeviceSigInfo, SDYULCDeviceSigInfo&> ASDYULCDeviceSigInfoArray;


//非编设备支持的VTR（用于上下载任务，指定每台非编可以看到的VTR设备）
struct SDYULCEditSPTVtrInfo
{
	DY_GUID	 guidEditDeviceID;            //非编设备DY_GUID
	DY_GUID     guidVTRDeviceID;             //VTR设备DY_GUID

	SDYULCEditSPTVtrInfo()
	{
		guidEditDeviceID = GUID_NULL;
		guidVTRDeviceID  = GUID_NULL;
	};

	SDYULCEditSPTVtrInfo(const SDYULCEditSPTVtrInfo &other)
	{
		*this = other;
	};
	
	SDYULCEditSPTVtrInfo& operator = (const SDYULCEditSPTVtrInfo& other)
	{
		guidEditDeviceID = other.guidEditDeviceID;
		guidVTRDeviceID  = other.guidVTRDeviceID;

		return *this;
	};
};
typedef CArray<SDYULCEditSPTVtrInfo, SDYULCEditSPTVtrInfo&> ASDYULCEditSPTVtrInfoArray;

//设备通道的结构信息
struct SDYULCDevicePortInfo
{
	DY_GUID						guidID;                             //通道的Guid
	DWORD						dwIndex;                            //通道序号
	CString                     strName;							//通道名称
	CString						strHint;                            //通道备注

	DYULC_DEVICE_PORTDIR		enumDir;                            //通道方向
	DYULC_DEVICE_PORTTYPE		enumType;                           //通道种类
	DYULCPORTPROPERTYFLAG		dwConnectPropertyFlag;              //通道可能同时支持多种类型
	CString						strSocketInfo;                      //通道Socket信息
	DWORD						dwSDTIMaxSpeed;                     //通道传输速度

	DYULC_DEVICE_PORTSTATUS     enumPortWorkStatus;                 //设备通道的工作状态（忙还是空闲）
	DY_GUID                        guidBelongDeviceID;                 //设备通道属于的设备的DY_GUID

	CString                     strAddtion;

	SDYULCDevicePortInfo()
	{
		guidID = GUID_NULL;
		dwIndex = 0;
		strName = _T("");
		strHint = _T("");
		enumDir = DYULCDEVICE_PORTDIR_UNKNOWN;
		enumType = DYULCDEVICE_PORTTYPE_UNKNOWN;
		dwConnectPropertyFlag = DYULCDEVICE_PORTTYPE_UNKNOWN;
		strSocketInfo = _T("");
		dwSDTIMaxSpeed = 1;

		enumPortWorkStatus = DYULDEVICE_PORTSTATUS_FREE;
		guidBelongDeviceID = GUID_NULL;

		strAddtion = _T("");
	};

	SDYULCDevicePortInfo(const SDYULCDevicePortInfo &other)
	{
		*this = other;
	};

	SDYULCDevicePortInfo& operator = (const SDYULCDevicePortInfo& other)
	{
		guidID = other.guidID;
		dwIndex = other.dwIndex;
		strName = other.strName;
		strHint = other.strHint;
		enumDir = other.enumDir;
		enumType = other.enumType;
		dwConnectPropertyFlag = other.dwConnectPropertyFlag;
		strSocketInfo = other.strSocketInfo;
		dwSDTIMaxSpeed = other.dwSDTIMaxSpeed;

		enumPortWorkStatus = other.enumPortWorkStatus;
		guidBelongDeviceID = other.guidBelongDeviceID;

		strAddtion = other.strAddtion;

		return *this;
	};
};
typedef CArray <SDYULCDevicePortInfo, SDYULCDevicePortInfo&> ASDYULCDevicePortInfoArray;

//设备组
struct SDYULCDeviceGroupInfo
{
	DY_GUID		guidGroupID;				//设备组DY_GUID
	CString		strGroupName;				//信号组名称
	CString		strGroupHint;				//信号组描述

	SDYULCDeviceGroupInfo()
	{
		guidGroupID = GUID_NULL;
		strGroupName = _T("");
		strGroupHint = _T("");
	};

	SDYULCDeviceGroupInfo(const SDYULCDeviceGroupInfo &other)
	{
		*this = other;
	};

	SDYULCDeviceGroupInfo& operator = (const SDYULCDeviceGroupInfo& other)
	{
		guidGroupID = other.guidGroupID;
		strGroupName = other.strGroupName;
		strGroupHint = other.strGroupHint;
		return *this;
	};
};
typedef CArray<SDYULCDeviceGroupInfo, SDYULCDeviceGroupInfo&> ASDYULCDeviceGroupInfoArray;

//设备信息数据结构
struct SDYULCDeviceInfo
{
	DY_GUID						guidID;                            //设备Guid                    
	DYULC_DEVICE_TYPE			enumType;                          //设备类型
	CString						strName;                           //设备名称
	CString						strHint;                           //设备备注

	DY_GUID						guidGroupID;				  //设备组DY_GUID
	CString						strGroupName;                 //设备组名称

	BOOL						bIsEnable;                         //设备是否可用
	CDYGuidArray					aSupportPlayTapeTypeID;            //设备支持的播出磁带类型
	CDYGuidArray					aSupportRecordTapeTypeID;          //设备支持的录制磁带类型
	CDYGuidArray					aSupportSatelliteSignalID;         //设备支持的信号

	CString                     strDeviceModal;                    //设备型号 
	int                         nIsPlayOrRec;                      //录制还是播放 －1，未知，0，只能播放，1只能录制，2既能播放又能录制
	CString                     strFTPServerIP;                    //对于服务器IP地址的记录
	
	CString                     strDestIPSocket;                   //用于记录单播情况下，指定的接收地址和端口

	int                         nXpos;                             //在设备配置程序界面中的位置X坐标
	int                         nYpos;                             //在设备配置程序界面中的位置Y坐标

	BOOL                        bIfLinkDirect;                     //是否直联采集设备

	COleDateTime                odtLastUsedOverTime;               //最后使用时间

	BOOL                        bMidMatrix;                        //是否中间矩阵

	BOOL                        bUserLock;                         //是否锁定(针对南方台卫星接收机的使用要求)相当于禁用

	COleDateTime                odtPrepareUseTime;                 //预定将要使用时间
	ASDYULCDevicePortInfoArray	asPortInfo;                        //设备通道信息
	
	CString                     strUniCastIPPort;                  //单播目标IP地址以及端口

	int							bBackup;							//备份设备
    
    int                         nMaxPortNum;                        //最大端口数目，针对UDP采集
	SDYULCDeviceInfo()
	{
		guidID = GUID_NULL;
		enumType = DYULC_DEVICE_UNKOWN;
		strName = _T("");
		strHint = _T("");

		guidGroupID = GUID_NULL;
		strGroupName = _T("");

		bIsEnable = TRUE;
		asPortInfo.RemoveAll();
		aSupportPlayTapeTypeID.RemoveAll();
		aSupportRecordTapeTypeID.RemoveAll();
		aSupportSatelliteSignalID.RemoveAll();

		strDeviceModal = _T("");
		nIsPlayOrRec   = -1;
		strFTPServerIP = _T("");
		nXpos          = 0;
		nYpos          = 0;
		bIfLinkDirect  = FALSE;

		odtLastUsedOverTime.SetDateTime(1900,1,1,1,1,1);
		bMidMatrix     = FALSE;

		bUserLock      = FALSE;

		odtPrepareUseTime.SetDateTime(1900,1,1,1,1,1);
		strUniCastIPPort = _T("");

		bBackup = FALSE;

		nMaxPortNum = 0;
	};

	SDYULCDeviceInfo(const SDYULCDeviceInfo &other)
	{
		*this = other;
	};

	~SDYULCDeviceInfo()
	{
		asPortInfo.RemoveAll();
		aSupportPlayTapeTypeID.RemoveAll();
		aSupportRecordTapeTypeID.RemoveAll();
		aSupportSatelliteSignalID.RemoveAll();
	};

	SDYULCDeviceInfo& operator = (const SDYULCDeviceInfo& other)
	{
		guidID = other.guidID;
		enumType = other.enumType;
		strName = other.strName;
		strHint = other.strHint;

		guidGroupID = other.guidGroupID;
		strGroupName = other.strGroupName;

		bIsEnable = other.bIsEnable;
		asPortInfo.Copy( other.asPortInfo );
		aSupportPlayTapeTypeID.Copy( other.aSupportPlayTapeTypeID );
		aSupportRecordTapeTypeID.Copy( other.aSupportRecordTapeTypeID );
		aSupportSatelliteSignalID.Copy( other.aSupportSatelliteSignalID );

		strDeviceModal = other.strDeviceModal;
		nIsPlayOrRec   = other.nIsPlayOrRec;
		strFTPServerIP = other.strFTPServerIP;
		nXpos          = other.nXpos;
		nYpos          = other.nYpos;
		bIfLinkDirect  = other.bIfLinkDirect;

		odtLastUsedOverTime = other.odtLastUsedOverTime;
		bMidMatrix     = other.bMidMatrix;

		bUserLock      = other.bUserLock;

		odtPrepareUseTime = other.odtPrepareUseTime;		

		strUniCastIPPort  = other.strUniCastIPPort;

		bBackup = other.bBackup;
		nMaxPortNum = other.nMaxPortNum;

		return *this;
	};
};
typedef CArray<SDYULCDeviceInfo, SDYULCDeviceInfo&> ASDYULCDeviceInfoArray;

struct SDYULCDevicePortConnectInfo
{
	DY_GUID	guidInputDeviceID;                 //入口设备guid
	DY_GUID	guidInputDevicePortID;             //入口设备通道guid
	DY_GUID	guidOutputDeviceID;                //出口设备guid
	DY_GUID	guidOutputDevicePortID;            //出口设备通道guid

	SDYULCDevicePortConnectInfo()
	{
		guidInputDeviceID = GUID_NULL;
		guidInputDevicePortID = GUID_NULL;
		guidOutputDeviceID = GUID_NULL;
		guidOutputDevicePortID = GUID_NULL;
	};

	SDYULCDevicePortConnectInfo(const SDYULCDevicePortConnectInfo &other)
	{
		*this = other;
	};

	SDYULCDevicePortConnectInfo& operator = (const SDYULCDevicePortConnectInfo& other)
	{
		guidInputDeviceID = other.guidInputDeviceID;
		guidInputDevicePortID = other.guidInputDevicePortID;
		guidOutputDeviceID = other.guidOutputDeviceID;
		guidOutputDevicePortID = other.guidOutputDevicePortID;
		return *this;
	};
};
typedef CArray<SDYULCDevicePortConnectInfo, SDYULCDevicePortConnectInfo&> ASDYULCDevicePortConnectInfoArray;

struct SDYULCLinkNetClass
{
	DY_GUID		  guidColID;				  //栏目DY_GUID
	CString		  strColName;                 //栏目名称
	DY_GUID		  guidVAGroupID;			  //VA格式组DY_GUID
	CString		  strVAGroupName;			  //VA格式组名称	
	float         fFeeWeight;                 //栏目计费权重
	CDYGuidArray    asGuidPlugInTypeInfo;       //默认调用插件
	CStringArray  asStrPlugInTypeInfo;        //默认调用插件的名称
	DY_GUID		  guidOwner;				  //栏目默认拥有者
	CString		  strOwnerName;				  //栏目默认拥有者名称

	SDYULCLinkNetClass()
	{
		guidColID      = GUID_NULL;
		strColName     = _T("");
		guidVAGroupID  = GUID_NULL;
		strVAGroupName = _T("");
		fFeeWeight     = 1.0f;
		guidOwner	   = GUID_NULL;
	};
    ~SDYULCLinkNetClass()
	{
        asGuidPlugInTypeInfo.RemoveAll();
        asStrPlugInTypeInfo.RemoveAll();
	}
	SDYULCLinkNetClass(const SDYULCLinkNetClass &other)
	{
		*this = other;
	};	

	SDYULCLinkNetClass& operator = (const SDYULCLinkNetClass& other)
	{
		guidColID      = other.guidColID;
		strColName     = other.strColName;
		guidVAGroupID  = other.guidVAGroupID;
		strVAGroupName = other.strVAGroupName;		
        fFeeWeight     = other.fFeeWeight;
		asGuidPlugInTypeInfo.Copy( other.asGuidPlugInTypeInfo );
		asStrPlugInTypeInfo.Copy( other.asStrPlugInTypeInfo );
		guidOwner	   = other.guidOwner;
		strOwnerName   = other.strOwnerName;

		return *this;
	};
};
typedef CArray<SDYULCLinkNetClass, SDYULCLinkNetClass&> ASDYULCLinkNetClassArray;


//统一导入导出结构
struct SDYULCCommonReferInfo
{
	LPVOID        pParamArr;         //参数队列
	int           nParmaType;        //参数类型 0为信号组，1为信号，2为磁带组，3为磁带类型，4为任务插件，5为任务分类，
	//6为视音频格式组信息，7为视音频格式信息，8为计费时段信息，9为计费标准信息，10为编目信息中的分类
	//11为栏目与任务分类的关联信息，12为栏目与格式组的关联信息，13为栏目与计费标准的关联信息
	//14为整体参数信息，15为常用节目名称

	SDYULCCommonReferInfo()
	{
		pParamArr  = NULL;
		nParmaType = -1;
	};

	SDYULCCommonReferInfo(const SDYULCCommonReferInfo &other)
	{
		*this = other;
	};

	SDYULCCommonReferInfo& operator = (const SDYULCCommonReferInfo& other)
	{
		pParamArr  = other.pParamArr;
		nParmaType = other.nParmaType;

		return *this;
	};
};
typedef CArray<SDYULCCommonReferInfo, SDYULCCommonReferInfo&> ASDYULCCommonReferInfoArray;

struct SDYULCDVBMAINLEVEL
{
	int           nLevel1;
	CString       strLevelname;	

	SDYULCDVBMAINLEVEL()
	{
		nLevel1         = -1;
		strLevelname    = _T("");		
	};

	SDYULCDVBMAINLEVEL(const SDYULCDVBMAINLEVEL & other) 
	{ 
		*this = other; 
	};

	SDYULCDVBMAINLEVEL& operator = (const SDYULCDVBMAINLEVEL& other)
	{
		nLevel1         = other.nLevel1;
		strLevelname    = other.strLevelname;

		return *this;
	};
};
typedef CArray<SDYULCDVBMAINLEVEL, SDYULCDVBMAINLEVEL&> ASDYULCDVBMAINLEVELArray;

struct SDYULCDVBSUBLEVEL
{
	int           nLevel1;
	int           nLevel2;
	CString       strLevelname;	

	SDYULCDVBSUBLEVEL()
	{
		nLevel1         = -1;
		nLevel2         = -1;
		strLevelname    = _T("");		
	};

	SDYULCDVBSUBLEVEL(const SDYULCDVBSUBLEVEL & other) 
	{ 
		*this = other; 
	};

	SDYULCDVBSUBLEVEL& operator = (const SDYULCDVBSUBLEVEL& other)
	{
		nLevel1         = other.nLevel1;
		nLevel2         = other.nLevel2;
		strLevelname    = other.strLevelname;

		return *this;
	};
};
typedef CArray<SDYULCDVBSUBLEVEL, SDYULCDVBSUBLEVEL&> ASDYULCDVBSUBLEVELArray;

//图形编单结构(信号组)
struct SDYULGraCompileGroup
{
	DY_GUID guidGroup;				//
	CString strGrougName;	//组名称
	CStringArray asName;	//包含的名称
	CDYGuidArray aGuid;		//DY_GUID
	BOOL	bSigOrDevice;	//信号组或者设备组

	SDYULGraCompileGroup()
	{
		guidGroup = GUID_NULL;
		bSigOrDevice = TRUE;
	}

	SDYULGraCompileGroup(const SDYULGraCompileGroup & other) 
	{ 
		*this = other; 
	};

	SDYULGraCompileGroup& operator = (const SDYULGraCompileGroup& other)
	{
		guidGroup		= other.guidGroup;
		strGrougName	= other.strGrougName;
		asName.Copy(other.asName);
		aGuid.Copy(other.aGuid);
		bSigOrDevice	= other.bSigOrDevice;

		return *this;
	};
};
typedef CArray<SDYULGraCompileGroup, SDYULGraCompileGroup&> ADYULGraCompileGroupArray;

//图形编单结构(信号类)
struct SDYULGraCompileClass
{
	DY_GUID guidClass;				//
	CString strClassName;		//类名称
	CStringArray asGroupName;	//包含组的名称
	CDYGuidArray aGroupGuid;		//包含类的DY_GUID

	SDYULGraCompileClass()
	{
		guidClass = GUID_NULL;
	}

	SDYULGraCompileClass(const SDYULGraCompileClass & other) 
	{ 
		*this = other; 
	};

	SDYULGraCompileClass& operator = (const SDYULGraCompileClass& other)
	{
		guidClass		= other.guidClass;
		strClassName	= other.strClassName;
		asGroupName.Copy(other.asGroupName);
		aGroupGuid.Copy(other.aGroupGuid);

		return *this;
	};
};
typedef CArray<SDYULGraCompileClass, SDYULGraCompileClass&> ASDYULGraCompileClassArray;

//离线数据库配置
struct SDYULCOfflineDBSetting
{
	DY_GUID				guidSetting;	//
	CString				strDBName;		//数据库名称
	DY_DATABASE_TYPE	enumDBType;
	CString				strServerId;
	CString				strDataSource;
	CString				strUserId;
	CString				strPWD;

	SDYULCOfflineDBSetting()
	{
		guidSetting = GUID_NULL;
		strDBName = _T("");
		enumDBType = DYDATABASETYPE_UNKNOW;
	}

	SDYULCOfflineDBSetting(const SDYULCOfflineDBSetting & other) 
	{ 
		*this = other; 
	};

	SDYULCOfflineDBSetting& operator = (const SDYULCOfflineDBSetting& other)
	{
		guidSetting		= other.guidSetting;
		strDBName		= other.strDBName;
		enumDBType		= other.enumDBType;
		strServerId		= other.strServerId;
		strDataSource	= other.strDataSource;
		strUserId		= other.strUserId;
		strPWD			= other.strPWD;

		return *this;
	};
};
typedef CArray<SDYULCOfflineDBSetting, SDYULCOfflineDBSetting&> ASDYULCOfflineDBSettingArray;

//信号配置策略组
/*struct SDYULCSigConfigStrategy
{
	DY_GUID guidSigConfig;
	CString strConfigName;

	ASDYNMUserInfoArray		asNMUserInfo;		//配置的那些用户
	ASDYULCSignalSourceInfoArray   asSigSourceArr;		//可用的信号的列表

	SDYULCSigConfigStrategy()
	{
		guidSigConfig = GUID_NULL;
		strConfigName = _T("");
	}

	SDYULCSigConfigStrategy(const SDYULCSigConfigStrategy& other)
	{
		*this = other;
	}

	SDYULCSigConfigStrategy& operator = (const SDYULCSigConfigStrategy& other)
	{
		guidSigConfig = other.guidSigConfig;
		strConfigName = other.strConfigName;
		asNMUserInfo.Copy(other.asNMUserInfo);
		asSigSourceArr.Copy(other.asSigSourceArr);

		return *this;
	}
};
typedef CArray<SDYULCSigConfigStrategy , SDYULCSigConfigStrategy&> ASDYULCSigConfigStrategyArray;*/

//收录主题数据结构
enum DYULC_SUBJECT_STATE
{
	DYULC_SUBJECTSTATE_UNKNOWN	= 0,
	DYULC_SUBJECTSTATE_DECLARE	= 1,	//主题处于申报状态
	DYULC_SUBJECTSTATE_CREATED	= 2,	//主题处于已建立状态
};

struct SDYULCSubject
{
	DY_GUID			guidSubject;
	CString			strSubjectName;		//主题名称
	CString			strHint;			//备注
	int				nPriority;			//优先级(重点)
	DYULC_SUBJECT_STATE enumState;		//状态
	DY_GUID			guidDeclare;		//申报人guid
	CString			strDeclarer;		//申报人名称
	COleDateTime	odtDeclareTime;		//申报时间
	DY_GUID			guidCreator;		//创建人guid
	CString			strCreator;			//创建人名称
	COleDateTime	odtCreateTime;		//创建时间
	COleDateTime	odtInvalidDate;		//失效时间

	SDYULCSubject()
	{
		guidSubject = GUID_NULL;
		nPriority = 0;
		enumState = DYULC_SUBJECTSTATE_UNKNOWN;
		guidDeclare = GUID_NULL;
		odtDeclareTime = COleDateTime::GetCurrentTime();
		guidCreator = GUID_NULL;
		odtCreateTime = COleDateTime::GetCurrentTime();
		odtInvalidDate.SetDate(2099 , 1 , 1);
	}

	SDYULCSubject(const SDYULCSubject& other)
	{
		*this = other;
	}

	SDYULCSubject& operator = (const SDYULCSubject& other)
	{
		guidSubject = other.guidSubject;
		strSubjectName = other.strSubjectName;
		strHint = other.strHint;
		nPriority = other.nPriority;
		enumState = other.enumState;
		guidDeclare = other.guidDeclare;
		strDeclarer = other.strDeclarer;
		odtDeclareTime = other.odtDeclareTime;
		guidCreator = other.guidCreator;
		strCreator = other.strCreator;
		odtCreateTime = other.odtCreateTime;
		odtInvalidDate = other.odtInvalidDate;

		return *this;
	}
};

typedef CArray<SDYULCSubject , SDYULCSubject&> ASDYULCSubjectArray;

//公告结构
struct SDYULBulletin
{
	DY_GUID			guidBulletin;		//公告guid
	CString			strBulletTitle;		//标题
	CString			strContent;			//内容
	int				nPriority;			//优先级(重点)
	DY_GUID			guidCreator;		//公告发布者
	CString			strCreator;			//发布者名称
	COleDateTime	odtDeclareDate;		//发布日期
	COleDateTime	odtInvalidDate;		//失效时间

	SDYULBulletin()
	{
		guidBulletin = GUID_NULL;
		nPriority = 0;
		guidCreator = GUID_NULL;
		odtDeclareDate = COleDateTime::GetCurrentTime();
		odtInvalidDate = COleDateTime(2099 , 1 , 1, 1 ,1 ,1 );
	}

	SDYULBulletin(const SDYULBulletin& other)
	{
		*this = other;
	}

	SDYULBulletin& operator = (const SDYULBulletin& other)
	{
		guidBulletin = other.guidBulletin;
		strBulletTitle = other.strBulletTitle;
		strContent = other.strContent;
		nPriority = other.nPriority;
		guidCreator = other.guidCreator;
		strCreator = other.strCreator;
		odtDeclareDate = other.odtDeclareDate;
		odtInvalidDate = other.odtInvalidDate;

		return *this;
	}
};
typedef CArray<SDYULBulletin , SDYULBulletin&> ASDYULBulletinArray;

#endif // !defined(__H__DYULCCommonDefine__H__)