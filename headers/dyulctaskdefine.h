///////////////////////////////////////////////////////////////////////////////////
//DYULCTaskDefine.h

//此文件用于定义上载任务结构
///////////////////////////////////////////////////////////////////////////////////

#if !defined( __H__DYULCTaskDef__H__ )
#define __H__DYULCTaskDef__H__

#include "\Dayang\DYBaseCtrl\Src\DYCommonDlg\DYDateLoopDef.h"
#include "DYULCCommonDefine.h"

//任务源类型
enum DYULC_TASK_SOURCETYPE
{ 
	DYULCTASK_SOURCETYPE_UNKOWN			    =	0,
	DYULCTASK_SOURCETYPE_VTRTAPE		    =	1,	       //VTR TAPE
	DYULCTASK_SOURCETYPE_SIGNAL			    =	2,	       //信号
	DYULCTASK_SOURCETYPE_SERVER             =   3,         //服务器播出
    DYULCTASK_SOURCETYPE_K2                 =   4,         //K2视频服务
    DYULCTASK_SOURCETYPE_EVS                =   5,         //EVS文件
	DYULCTASK_SOURCETYPE_BD                 =   6,         //蓝光
	DYULCTASK_SOURCETYPE_EX1                =   7,         //扩展
	DYULCTASK_SOURCETYPE_EX2                =   8,         //扩展
	DYULCTASK_SOURCETYPE_OTHER              =   9,         //其他
};

//任务目标类型
enum DYULC_TASK_TARGETTYPE
{
	DYULCTASK_TARGETTYPE_UNKOWN			=	0,			//未知设备
	DYULCTASK_TARGETTYPE_VTRTAPE		=	1,			//VTR TAPE
	DYULCTASK_TARGETTYPE_DATAFILES		=	2,			//采集客户端
	DYULCTASK_TARGETTYPE_SERVER		    =	3,			//服务器采集客户端
	DYULCTASK_TARGETTYPE_DY3000		    =	4,			//DY3000客户端
    DYULCTASK_TARGETTYPE_K2             =   5,          //K2视频服务
    DYULCTASK_TARGETTYPE_EVS            =   6,          //EVS文件
	DYULCTASK_TARGETTYPE_BD             =   7,          //扩展
	DYULCTASK_TARGETTYPE_EX1            =   8,          //扩展
	DYULCTASK_TARGETTYPE_EX2             =  9,          //扩展
	DYULCTASK_TARGETTYPE_OTHER		    =	10,			//其他客户端
};


//任务编辑状态
enum  DYULC_TASK_EDITSTATUS
{
	DYULCTASK_EDITSTATUS_NOPREFER		=	0,			//任务已保存
    DYULCTASK_EDITSTATUS_PREPERED       =   1,          //已提交
	DYULCTASK_EDITSTATUS_AUDITLEVEL1    =	2,			//任务一审通过
	DYULCTASK_EDITSTATUS_AUDITLEVEL2	=	3,			//任务二审通过
	DYULCTASK_EDITSTATUS_AUDITLEVEL3	=	4,			//任务三审通过
	DYULCTASK_EDITSTATUS_AUDITLEVEL4	=	5,			//任务四审通过
	DYULCTASK_EDITSTATUS_AUDITLEVEL5	=	6,			//任务五审通过
    DYULCTASK_EDITSTATUS_RETURN		=	7,			//任务退回
};

//任务优先级
enum DYULC_TASK_PRIORITY
{
	DYULCTASK_PRIORITY_LOW				=	0,          //最低优先级
	DYULCTASK_PRIORITY_BELOWNORMAL		=	1,          //较低优先级
	DYULCTASK_PRIORITY_NORMAL			=	2,          //正常优先级
	DYULCTASK_PRIORITY_ABOVENORMAL		=	3,          //较高优先级
	DYULCTASK_PRIORITY_HIGH				=	4,          //最高优先级
};

//任务编辑的来源
enum DYULC_TASK_EDITSOURCE
{
	DYULCTASK_EDITSOURCE_UNKNOWN	=	0,
	DYULCTASK_EDITSOURCE_CSEDIT		=	1,		//CS编辑的任务
	DYULCTASK_EDITSOURCE_BSEDIT		=	2,		//BS编辑的任务
};

//任务执行状态
enum DYULC_TASK_RUNSTATUS
{ 
	DYULCTASK_RUNSTATUS_SLEEP			=	0,			//睡眠
	DYULCTASK_RUNSTATUS_WAITING			=	1,			//等待
	DYULCTASK_RUNSTATUS_RUNING			=	2,			//执行
	DYULCTASK_RUNSTATUS_FINISHED		=	3,			//完成
	DYULCTASK_RUNSTATUS_ERROR			=	4,			//错误
	DYULCTASK_RUNSTATUS_CANCEL			=	5,			//取消
	DYULCTASK_RUNSTATUS_ALLOCATED       =   6,          //任务已分配	
};

//操作流程关联类型
enum DYULC_LINKTYPE
{
	DYULC_LINKTYPE_NONE	      = 0,		// 未知
	DYULC_LINKTYPE_CLIPDATA   = 1,      // CLIPDATA表  非分段素材
	DYULC_LINKTYPE_CLIPPART   = 2,		// CLIPPART表  分段素材
};
//系统设置类型
enum DYULC_SYSTEMCONFIG_TYPE
{
	DYULCSYSTEMCONFIG_TYPE_LIFECYCLESET			= 1,	//生命周期管理设置
	DYULCSYSTEMCONFIG_TYPE_COLUMNPRECEPTSET	    = 2,	//栏目和方案对应关系设置
};

//收录任务使用中间设备信息
struct SDYULCTaskDeviceInfo
{
	DY_GUID                        guidTaskID;                       //所属任务guid

	DY_GUID                        guidMCtrlPortID;                  //任务主控制通道guid
	DY_GUID                        guidCCtrlPortID;                  //任务被控制通道guid

	BOOL                        bPassMidMatrix;                   //是否过中间矩阵
	CDYGuidArray                  asGuidMidMatrixArr;               //所过中间矩阵的guid队列
	CDYGuidArray                  asGuidMidMatrixPortArr;           //所过中间矩阵端口(出口)guid队列

	BOOL                        bPassGateWay;                     //信号是否过媒体网关
	DY_GUID                        guidGateWayDevice;                //媒体网关设备guid
	DY_GUID                        guidGateWayPort;                  //媒体网关设备通道guid
	CString                     strIPAddressGateWayDevice;        //媒体网关设备IP地址
	CString                     strIPAddressGateWayPort;          //媒体网关设备通道IP地址

	CString                     strGateWayInportName;             //媒体网关入口名称
	CString                     strGateWayOutPortName;            //媒体网关出口名称

	CString                     strDecoderName;                   //解码器名
	DY_GUID                        guidDecoderDevice;                //解码器Guid
	CString                     strIPAddressDecoder;              //解码器IP地址

	CString                     strEncoderName;                   //编码器名
	DY_GUID                        guidEncoderDevice;                //编码器guid
	CString                     strIPAddressEncoder;              //编码器IP地址

	BOOL                        bPassLMatrix;	                  //是否过中频矩阵
	CString                     strSatsigProcesserName;           //卫星信号解出设备名称
	DY_GUID                        guidSatsigProcesser;              //卫星信号解出设备guid
	DY_GUID						guidSatsigProcesserOutPort;		 //卫星信号解出设备输出通道guid

	BOOL                        bNeedAnalogAdj;                   //是否需要模拟调节
	CString                     strAnalogAdjuster;                //模拟调节器名称
	DY_GUID                        guidAnalogAdjuster;               //模拟调节器guid	

	BOOL                        bNeedDigitalAdj;                  //是否需要数字调节
	CString                     strDigitalAdjuster;               //数字调节器名称
	DY_GUID                        guidDigitalAdjuster;              //数字调节器guid

	BOOL                        bPassTVEncoder;                   //是否使用电视解调器
	CString                     strTVEncoder;                     //电视解调器名称	
	DY_GUID                        guidTVEncoder;                    //电视解调器guid
	DY_GUID                        guidTVEncoderPort;                //使用的电视解调器通道guid

	CString                     strMagicWall;                     //多画面分割器名称
	DY_GUID                        guidMagicWall;                    //多画面分割器guid	
	DY_GUID                        guidMagicWallPort;                //使用的多画面分割器通道guid

	CString                     strDAOutbedDeviceName;            //使用D/A设备名
	DY_GUID                        guidDAOutbedDevice;               //使用D/A设备guid
	CString                     strADInbedDeviceName;             //使用A/D设备名称	
	DY_GUID                        guidADInbedDevice;                //使用A/D设备guid

	CString                     strVSChangeDeviceName;            //转制设备名称
	DY_GUID                        guidVSChangeDevice;               //转制设置DY_GUID	

	CString                     strTerminalMatrixIn;              //最终矩阵入口（切换用）
	CString                     strTerminalMatrixOut;             //最终矩阵出口（切换用）
	DY_GUID                        guidTerminalMatrix;               //最终矩阵guid

	SDYULCTaskDeviceInfo()
	{
		guidTaskID                 = GUID_NULL;              
		guidMCtrlPortID            = GUID_NULL;         
		guidCCtrlPortID            = GUID_NULL;         

		bPassMidMatrix             = FALSE;          
		asGuidMidMatrixArr.RemoveAll();      
		asGuidMidMatrixPortArr.RemoveAll();  

		bPassGateWay               = FALSE;            
		guidGateWayDevice          = GUID_NULL;       
		guidGateWayPort            = GUID_NULL;         
		strIPAddressGateWayDevice  = _T("");
		strIPAddressGateWayPort    = _T(""); 
		strGateWayInportName	   = _T("");
		strGateWayOutPortName      = _T("");

		strDecoderName             = _T("");          
		guidDecoderDevice          = GUID_NULL;       
		strIPAddressDecoder        = _T("");     

		strEncoderName             = _T("");          
		guidEncoderDevice          = GUID_NULL;       
		strIPAddressEncoder        = _T("");     

		bPassLMatrix               = FALSE;	         
		strSatsigProcesserName     = _T("");  
		guidSatsigProcesser        = GUID_NULL;
		guidSatsigProcesserOutPort = GUID_NULL;

		bNeedAnalogAdj             = FALSE;          
		strAnalogAdjuster          = _T("");       
		guidAnalogAdjuster         = GUID_NULL;      

		bNeedDigitalAdj            = FALSE;         
		strDigitalAdjuster         = _T("");      
		guidDigitalAdjuster        = GUID_NULL;     

		bPassTVEncoder             = FALSE;
		strTVEncoder               = _T("");            
		guidTVEncoder              = GUID_NULL;           
		guidTVEncoderPort          = GUID_NULL;       

		strMagicWall               = _T("");            
		guidMagicWall              = GUID_NULL;           
		guidMagicWallPort          = GUID_NULL;       

		strDAOutbedDeviceName      = _T("");   
		guidDAOutbedDevice         = GUID_NULL;      
		strADInbedDeviceName       = _T("");    
		guidADInbedDevice          = GUID_NULL;       

		strVSChangeDeviceName      = _T("");   
		guidVSChangeDevice         = GUID_NULL;      

		strTerminalMatrixIn        = _T("");     
		strTerminalMatrixOut       = _T("");    
		guidTerminalMatrix         = GUID_NULL;
	};

	~SDYULCTaskDeviceInfo()
	{
		asGuidMidMatrixArr.RemoveAll();      
		asGuidMidMatrixPortArr.RemoveAll();		
	};

	SDYULCTaskDeviceInfo(const SDYULCTaskDeviceInfo & other)
	{ 		
		*this = other; 
	};

	SDYULCTaskDeviceInfo& operator = (const SDYULCTaskDeviceInfo& other)
	{
		guidTaskID                 = other.guidTaskID;              
		guidMCtrlPortID            = other.guidMCtrlPortID;         
		guidCCtrlPortID            = other.guidCCtrlPortID;         

		bPassMidMatrix             = other.bPassMidMatrix;          
		asGuidMidMatrixArr.Copy(other.asGuidMidMatrixArr);
		asGuidMidMatrixPortArr.Copy(other.asGuidMidMatrixPortArr);  

		bPassGateWay               = other.bPassGateWay;            
		guidGateWayDevice          = other.guidGateWayDevice;       
		guidGateWayPort            = other.guidGateWayPort;         
		strIPAddressGateWayDevice  = other.strIPAddressGateWayDevice;
		strIPAddressGateWayPort    = other.strIPAddressGateWayPort; 
		strGateWayInportName       = other.strGateWayInportName; 
		strGateWayOutPortName      = other.strGateWayOutPortName; 

		strDecoderName             = other.strDecoderName;          
		guidDecoderDevice          = other.guidDecoderDevice;       
		strIPAddressDecoder        = other.strIPAddressDecoder;     

		strEncoderName             = other.strEncoderName;          
		guidEncoderDevice          = other.guidEncoderDevice;       
		strIPAddressEncoder        = other.strIPAddressEncoder;     

		bPassLMatrix               = other.bPassLMatrix;	         
		strSatsigProcesserName     = other.strSatsigProcesserName;  
		guidSatsigProcesser        = other.guidSatsigProcesser;  
		guidSatsigProcesserOutPort = other.guidSatsigProcesserOutPort;

		bNeedAnalogAdj             = other.bNeedAnalogAdj;          
		strAnalogAdjuster          = other.strAnalogAdjuster;       
		guidAnalogAdjuster         = other.guidAnalogAdjuster;      

		bNeedDigitalAdj            = other.bNeedDigitalAdj;         
		strDigitalAdjuster         = other.strDigitalAdjuster;      
		guidDigitalAdjuster        = other.guidDigitalAdjuster;     

		bPassTVEncoder             = other.bPassTVEncoder;
		strTVEncoder               = other.strTVEncoder;            
		guidTVEncoder              = other.guidTVEncoder;           
		guidTVEncoderPort          = other.guidTVEncoderPort;       

		strMagicWall               = other.strMagicWall;            
		guidMagicWall              = other.guidMagicWall;           
		guidMagicWallPort          = other.guidMagicWallPort;       

		strDAOutbedDeviceName      = other.strDAOutbedDeviceName;   
		guidDAOutbedDevice         = other.guidDAOutbedDevice;      
		strADInbedDeviceName       = other.strADInbedDeviceName;    
		guidADInbedDevice          = other.guidADInbedDevice;       

		strVSChangeDeviceName      = other.strVSChangeDeviceName;   
		guidVSChangeDevice         = other.guidVSChangeDevice;      

		strTerminalMatrixIn        = other.strTerminalMatrixIn;     
		strTerminalMatrixOut       = other.strTerminalMatrixOut;    
		guidTerminalMatrix         = other.guidTerminalMatrix;

		return *this;
	};
};
typedef CArray<SDYULCTaskDeviceInfo, SDYULCTaskDeviceInfo&> ASDYULCTaskDeviceInfoArray;

//任务附加信息
struct SDYULCTaskExtraInfo
{
	DY_GUID                     guidTaskID;             //所属任务Guid

	BOOL                        bColorHaveSwitched;     //颜色是否需切换（用于警告闪烁提示）
	BOOL                        bSigHaveSwitched;       //信号是否切换（主要是指最后测试卡信号是否切换）
	BOOL                        bHandleOverdue;         //是否对过期素材已经处理	

	DWORD			            dwTaskProgress;			//任务进度
	COleDateTime                odtLastProcessTime;     //任务进度设置时间
	COleDateTime	            odtFinishDate;			//完成时间
	COleDateTime                odtTrueBegin;           //任务真实开始时间
	COleDateTime                odtTrueEnd;             //任务真实结束时间
	DWORD                       dwTrueLength;           //任务真实执行长度

	int                         nHadMoveClip;           //是否已经迁移过 0未迁移；1部分迁移；2全部迁移(这里只备份)
	int                         bOnceError;             //任务是否曾经出现过错误又重新执行	
	BOOL                        bTansferNetFail;        //传送到网络是否失败

	SDYULCTaskExtraInfo()
	{
		guidTaskID             = GUID_NULL;        

		bColorHaveSwitched     = FALSE;
		bSigHaveSwitched       = FALSE;  
		bHandleOverdue         = FALSE;    

		dwTaskProgress         = 0;
		odtLastProcessTime.SetDateTime(2000,1,1,0,0,0);
		odtFinishDate.SetDateTime(2000,1,1,0,0,0);		
		odtTrueBegin.SetDateTime(2000,1,1,0,0,0);      
		odtTrueEnd.SetDateTime(2000,1,1,0,0,0);        
		dwTrueLength           = 0;      

		nHadMoveClip           = 0;      
		bOnceError             = FALSE;        
		bTansferNetFail        = FALSE;		
	};

	SDYULCTaskExtraInfo(const SDYULCTaskExtraInfo &other)
	{		
		*this = other;
	};

	~SDYULCTaskExtraInfo()
	{

	};

	SDYULCTaskExtraInfo& operator = (const SDYULCTaskExtraInfo& other)
	{
		guidTaskID             = other.guidTaskID;        

		bColorHaveSwitched     = other.bColorHaveSwitched;
		bSigHaveSwitched       = other.bSigHaveSwitched;  
		bHandleOverdue         = other.bHandleOverdue;    

		dwTaskProgress         = other.dwTaskProgress;
		odtLastProcessTime     = other.odtLastProcessTime;
		odtFinishDate          = other.odtFinishDate;		
		odtTrueBegin           = other.odtTrueBegin;      
		odtTrueEnd             = other.odtTrueEnd;        
		dwTrueLength           = other.dwTrueLength;      

		nHadMoveClip           = other.nHadMoveClip;      
		bOnceError             = other.bOnceError;        
		bTansferNetFail        = other.bTansferNetFail;	

		return *this;
	};
};
typedef CArray<SDYULCTaskExtraInfo, SDYULCTaskExtraInfo&> ASDYULCTaskExtraInfoArray;


//任务目标素材结构信息
struct	SDYULClipData
{
	//---------------	基本信息	---------------------------------------------
	DY_GUID 						guidTaskID;						//	收录任务DY_GUID
	DY_GUID 						guidItem;                       //  素材DY_GUID,初始为空
	DY_GUID						guidDir;                        //  路径DY_GUID,初始为空
	DY_GUID						guidDir20;                        // 网管2.0, 路径DY_GUID,初始为空

	CString						strName;						//	素材名称
	CString						strInformation;                 //  节目简介
	CString						strProvider;                    //  内容提供商
	CString						strKeyWords;					//	关键字信息;逗号分隔
	CString						strRemark;						//	备注信息
	DYITEM_OWNERTYPE			enumOwnerType;					//	拥有者类型
	CString						strOwnerID;						//	拥有者标识
	CString						strOwnerID20;						//网管2.0	拥有者标识
	//-----------------------------------------------------------------------------------

	//---------------	编目信息	---------------------------------------------
	CString						strOutsideId;					//  外部唯一标识
	CString						strSubName;						//  副名称---名称的解释和补充信息
	//DYRITEM_AUDIENCELEVEL		enumAudienceLevel;				//	受众级别
	//DYRITEM_SECRETLEVEL			enumSecretLevel;				//	保密级别
	int         enumAudienceLevel;				//	受众级别
	int			enumSecretLevel;				//	保密级别
	DY_GUID						guidContent;					//	内容分类
	DY_GUID						guidCate;						//	组别分类
	DY_GUID						guidType;						//	类别分类
	DY_GUID						guidLenssort;					//	镜头分类
	DY_GUID						guidMISItem;					//	与MIS系统关联的DY_GUID
	ASDYMarkPointInfoArray		asMarkPoint;					//  特征点帧序号数组
	DWORD						dwIconFrameNo;					//  图标的帧号
	//-----------------------------------------------------------------------------------

	//---------------	视音频信息	---------------------------------------------

	DY_GUID                    	guidElementInfoGropuID;		    // 素材格式组DY_GUID
	ASDYULClipElementInfoArray	asFileElementInfo;              // 素材具体格式信息
	//-----------------------------------------------------------------------------------

	//---------------	额外数据信息	---------------------------------------------
	DWORD						dwExtraDataType;				// 额外数据类型
	DWORD						dwExtraDataSizeInByte;			// 额外数据大小
	PBYTE						pbExtraData;					// 附加的额外数据
	//-----------------------------------------------------------------------------------

	int              nMainClass;
	int              nSubClass;
	CString          strClassname;
	int              nLevel;

	BOOL			 bNeedAudioSearch;						//需要音频检索

	DYVIDEO_SCALE_TYPE	iVideoUpScaleType;		//高清，标清上变换方式
	DYVIDEO_SCALE_TYPE	iVideoDownScaleType;	//高清，标清下变换方式

	SDYULClipData()
	{
		guidTaskID        = GUID_NULL;
		guidItem          = GUID_NULL;
		guidDir           = GUID_NULL;
		guidDir20         = GUID_NULL;
		strName           = _T("");
		strKeyWords       = _T("");
		strInformation    = _T("");
		strProvider       = _T("");
		strRemark         = _T("");	
		enumOwnerType     = DYRES_OWNERTYPE_UNKNOW;
		strOwnerID        = _T("");		
        strOwnerID20        = _T("");	

		strOutsideId      = _T("");
		strSubName        = _T("");
		enumAudienceLevel = 0;//DYITEMAUDIENCELEVEL_UNKNOW;
		enumSecretLevel   = 0;//DYITEMSECRETLEVEL_UNKNOWN;
		guidContent       = GUID_NULL;
		guidCate          = GUID_NULL;
		guidType          = GUID_NULL;
		guidLenssort      = GUID_NULL;
		guidMISItem       = GUID_NULL;
		asMarkPoint.RemoveAll();
		dwIconFrameNo     = 0;

		guidElementInfoGropuID = GUID_NULL;
		asFileElementInfo.RemoveAll();

		dwExtraDataType       = 0;
		dwExtraDataSizeInByte = 0;
		pbExtraData           = NULL;

		nMainClass    = 0;
		nSubClass     = 0;
		strClassname  = _T("");
		nLevel        = 0;

		bNeedAudioSearch = FALSE;

		iVideoUpScaleType=DYVIDEO_SCALE_TYPE_NONE;
		iVideoDownScaleType=DYVIDEO_SCALE_TYPE_NONE;
	};

	SDYULClipData(const SDYULClipData & other) 
	{ 
		pbExtraData           = NULL;
		*this = other; 
	};	

	~SDYULClipData()
	{
		asMarkPoint.RemoveAll();
		asFileElementInfo.RemoveAll();

		if( pbExtraData )
			delete pbExtraData;
	};

	SDYULClipData& operator = (const SDYULClipData& other)
	{

		guidTaskID     = other.guidTaskID;
		guidItem       = other.guidItem;
		guidDir        = other.guidDir;
		guidDir20      = other.guidDir20;
		strName        = other.strName;
		strKeyWords    = other.strKeyWords;
		strInformation = other.strInformation;
		strProvider    = other.strProvider;
		strRemark      = other.strRemark;		
		enumOwnerType  = other.enumOwnerType;
		strOwnerID     = other.strOwnerID;
		strOwnerID20     = other.strOwnerID20;

		strOutsideId      = other.strOutsideId;
		strSubName        = other.strSubName;
		enumAudienceLevel = other.enumAudienceLevel;
		enumSecretLevel   = other.enumSecretLevel;
		guidContent       = other.guidContent;
		guidCate          = other.guidCate;
		guidType          = other.guidType;
		guidLenssort      = other.guidLenssort;
		guidMISItem       = other.guidMISItem;
		asMarkPoint.Copy( other.asMarkPoint );
		dwIconFrameNo     = other.dwIconFrameNo;

		guidElementInfoGropuID = other.guidElementInfoGropuID;
		asFileElementInfo.Copy(other.asFileElementInfo);

		dwExtraDataType = other.dwExtraDataType;
		dwExtraDataSizeInByte = other.dwExtraDataSizeInByte;
		if( pbExtraData ) {
			delete pbExtraData;
			pbExtraData = NULL;
		}
		if( other.pbExtraData && dwExtraDataSizeInByte > 0 ) {
			pbExtraData = new BYTE[dwExtraDataSizeInByte];
			memcpy( pbExtraData, other.pbExtraData, dwExtraDataSizeInByte );
		}

		nMainClass    = other.nMainClass;
		nSubClass     = other.nSubClass;
		strClassname  = other.strClassname;
		nLevel        = other.nLevel;

		bNeedAudioSearch	= other.bNeedAudioSearch;

		iVideoUpScaleType=other.iVideoUpScaleType;
		iVideoDownScaleType=other.iVideoDownScaleType;
		return *this;
	};
};
typedef CArray<SDYULClipData, SDYULClipData&> ASDYULClipDataArray;

//任务外部信息
struct SDYULCTaskExternInfo 
{
	DY_GUID     guidTaskID;                      //所属任务DY_GUID

	CString  strProgramCode;                  //节目代码
	CString  strProgmanSysColType;            //节目管理系统的栏目类型
	CString  strProgManSysColCode;            //节目管理系统的栏目代码
	CString  strProgManSysColName;            //节目管理系统的栏目名称

	CString  strTaskExternID;                 //外部系统记录的任务ID
	CString  strExternUserCode;               //外部系统的用户编码，是任务的发起者
	int      nRecTaskType;                    //任务的类型 1：手动开始,自动结束
	//		   2：自动开始,手动结束
	//		   3：自动开始,自动结束
	//    	   4：手动开始,手动结束
	//           5：任务模板
	CString  strStrategys;                    //策略序列,由入库,迁移策略组合

	CString  strProcessID;                    //任务流程的ID
	CString  strPreStepID;                    //任务流程的上一步的guid
	CString  strSourceSystemID;               //服务调用者的系统ID

	int      nApplicationType;                //任务是特批/普通等等
	int      nApplicationUseage;              //申请来自新闻/演播室

	//收录任务对应的预约节目单信息
	BOOL	bFromProgram;					//任务是否来自节目单
	DY_GUID	guidProgram;					//对应的节目单ID
	int				nBespeakTime;			//预约的次数
	CDYGuidArray		asBespeakUserGuid;		//预约过的用户DY_GUID(预约过的就不能再次预约了)
	CStringArray	asBespeakUserName;		//预约过的用户名
	CStringArray	asBespeakUserColumn;	//预约过的用户栏目

	DY_GUID	guidPreTask;					//对应的预约任务DY_GUID,(如果自己是实际任务的话)
	DY_GUID	guidWorkTask;					//对应的实际收录任务的DY_GUID(如果自己是预约任务的话)

	BOOL	bInArrange;						//任务是否正在编排(在编排软件里重新编排)

	DY_GUID	guidCutTask;					//预约任务对应的从实际任务来剪切的任务

	BOOL	bModAfterArrange;				//预约任务在编排后又被修改
	BOOL	bCancelAfterArrange;			//预约任务在编排后被撤销

	int		nExchangeState;					//迁移是否完成(0:未迁移，1:迁移完成，2:迁移失败)
	BOOL	bNewsMediaTask;					//新闻媒资类型任务

	SDYULCTaskExternInfo()
	{
		guidTaskID            = GUID_NULL;

		strProgramCode        = _T("");     
		strProgmanSysColType  = _T("");
		strProgManSysColCode  = _T("");
		strProgManSysColName  = _T("");

		strTaskExternID       = _T("");
		strExternUserCode     = _T("");
		nRecTaskType          = 3;
		strStrategys          = _T("");
		strProcessID          = _T("");
		strPreStepID          = _T("");
		strSourceSystemID     = _T("");

		nApplicationType      = 0;
		nApplicationUseage    = 0;

		bFromProgram		  = FALSE;
		guidProgram			  = GUID_NULL;
		nBespeakTime		  = 0;

		guidPreTask			  = GUID_NULL;
		guidWorkTask		  = GUID_NULL;

		bInArrange			  = FALSE;
		guidCutTask			  = GUID_NULL;

		bModAfterArrange	  = FALSE;
		bCancelAfterArrange	  = FALSE;

		nExchangeState = 0;
		bNewsMediaTask = FALSE;
	};

	SDYULCTaskExternInfo(const SDYULCTaskExternInfo &other)
	{
		*this = other;
	};	

	SDYULCTaskExternInfo& operator = (const SDYULCTaskExternInfo& other)
	{
		guidTaskID            = other.guidTaskID;

		strProgramCode        = other.strProgramCode;     
		strProgmanSysColType  = other.strProgmanSysColType;
		strProgManSysColCode  = other.strProgManSysColCode;
		strProgManSysColName  = other.strProgManSysColName;

		strTaskExternID       = other.strTaskExternID;
		strExternUserCode     = other.strExternUserCode;
		nRecTaskType          = other.nRecTaskType;
		strStrategys          = other.strStrategys;
		strProcessID          = other.strProcessID;
		strPreStepID          = other.strPreStepID;
		strSourceSystemID     = other.strSourceSystemID;

		nApplicationType      = other.nApplicationType;
		nApplicationUseage    = other.nApplicationUseage;

		bFromProgram		  = other.bFromProgram;
		guidProgram			  = other.guidProgram;
		nBespeakTime		  = other.nBespeakTime;
		asBespeakUserGuid.Copy(other.asBespeakUserGuid);
		asBespeakUserName.Copy(other.asBespeakUserName);
		asBespeakUserColumn.Copy(other.asBespeakUserColumn);

		guidPreTask			  = other.guidPreTask;
		guidWorkTask		  = other.guidWorkTask;

		bInArrange			  = other.bInArrange;
		guidCutTask			  = other.guidCutTask;

		bModAfterArrange = other.bModAfterArrange;
		bCancelAfterArrange = other.bCancelAfterArrange;

		nExchangeState = other.nExchangeState;
		bNewsMediaTask = other.bNewsMediaTask;

		return *this;
	};	
};
typedef CArray<SDYULCTaskExternInfo, SDYULCTaskExternInfo&> ASDYULCTaskExternInfoArray;

//收录任务基本信息
struct SDYULCTaskInfo
{
	//基本信息
	DY_GUID						guidTaskID;				//所属任务DY_GUID
	CString						strName;				//任务名
	CString						strHint;				//任务描述

	DYULC_TASK_EDITSTATUS		enumEditStatus;			//编辑状态
	COleDateTime				odtPreferDate;			//提交时间
	DYULC_TASK_EDITSOURCE		enumEditSource;			//任务编辑的来源(BS,CS)
    ///////////////////
	COleDateTime				odtTaskStartDate;		//开始时间
	COleDateTime				odtTaskStopDate;		//结束时间
	DWORD                       dwDuration;				//长度，以帧为单位

	BOOL                        bLoopTask;
	DY_GUID                     guidCycle;              //循环配置的guid
	SDYDateLoop                 sDateLoop;              //循环时间具体信息
    //////////////////
    /////////////////////////
    //信号信息
	DY_GUID						guidSigGroup;	        //信号组DY_GUID
	CString                     strSigGroupName;        //信号组名称
	DY_GUID						guidSignalID;	        //信号DY_GUID	
	CString                     strSignalName;          //信号名称
	CString                     strSignalAddress;       //信号主播地址	
    CString                     strSignalPort;          //信号主播端口号	
	
	DYULC_TASK_SOURCETYPE		enumSourceType;			//任务源类型
	
	//VTR信息
	DY_GUID						guidSrcVTRTapeType;     //源磁带类型guid
	CString                     strSrcVTRTapeTypeName;  //源磁带类型名称
	CString						strSrcVTRTapeName;	    //源磁带号
	BOOL						bSrcSetTrimInOut;       //源是否设置入出点
	DWORD						dwSrcVTRTrimIn;		    //源入点信息
	DWORD						dwSrcVTRTrimOut;	    //源出点信息

	BOOL                        bIfReceiver;            //是否为卫星接收机	
	DY_GUID                     guidReceiver;           //卫星接收机设备DY_GUID
	DYULC_DEVICE_PORTTYPE	    enumSrcSigType;         //信号类型,大类
	BOOL                        bHavePrioritySig;       //所使用的信号是否具有优先级
	BOOL                        bIsHD;                  //所使用的信号是否为高清

	DYULC_UDP_PACKTYPE          enumUDPPackType;        //UDP封装方式，子类
	////////////////////////////////
	//录机信息
	DY_GUID						guidRecordDeviceID;		//任务目标使用设备DY_GUID
	DY_GUID						guidRecordPortID;		//任务目标使用通道guid
	CString                     strRecordDeviceName;    //录机名称

	DYULC_TASK_TARGETTYPE		enumTargetType;			//任务目标类型
	DYULC_DEVICE_TYPE			enumRecordDevice;       //录制设备类型
    //
	//VTR信息
	DY_GUID						guidDestVTRTapeType;    //目标磁带类型guid
	CString                     strDestTapeTypeName;    //目标磁带类型名称
	CString						strDestVTRTapeName;		//目标磁带号	
	BOOL						bDestSetTrimInOut;      //目标是否设置入出点
	DWORD						dwDestVTRTrimIn;		//目标入出点信息
	DWORD						dwDestVTRTrimOut;
	DYDEVICERECTRACKFLAG		dwDestVTRRecTrackFlag;			//是否输出视频，音频中的几路
	int						    bDestIsVTRRecAssemble;			//组合 /插入方式 0-插入，1－组合，2－硬录

	////////////////////////////////////////////////////////////////////////////////
   	CString                     strChannelID;           //拥有者部门
	CString                     strChannelName;         //拥有者部门名称
    CString                     strColumnID;            //拥有者栏目
	CString                     strColumnName;          //拥有者栏目名称

    CString						strOwnerID20;			  //网管2.0,拥有者ID
	CString                     strOwnerName20;           //网管2.0,拥有者
	
	CString						strOwnerID;				//拥有者ID
	CString                     strOwnerName;           //拥有者

	DY_GUID                     guidBizDomain;          //网管3.0,域
    CString                     strBizDomain;           //域名
    DY_GUID                     guidProjectItem;        //项目guid
    CString                     strProjectItem;         //项目名
    //////////////////////////////////////////////////////////////////
    DYULC_TASK_PRIORITY			enumPriority;			//优先级
	DYULC_TASK_RUNSTATUS		enumRunStatus;          //任务运行状态
	
    BOOL                        bBackUp;
	DY_GUID                     guidOrgTask;            //原任务DY_GUID
	CString                     strOrgTaskName;         //原任务名称   

	//数据化文件参数
	DY_GUID                     guidClipFormat;         //采集格式guid
	CString                     strClipFormatName;      //采集格式
    
	SDYULClipData			    sClipDataInfo;			//采集的素材信息
    
	int                         iFileFormat;            //文件格式
	CString                     strProgramPath;         //文件存放
	int                         iPreGetFlag;            //预领标识
    COleDateTime                odtModifyTime;          //修改

	CString                     strTaskFrom;            //来源于

	///////////////////////////////////////////////////////////
    CString                     strAddition;            //附加
	///////////////////////////////////////////////////////////
	DY_GUID                     guidTaskClass;          //任务调用插件,任务分类
	CString                     strTaskClassName;       //任务调用插件的名称,任务分类名称

	CString						strSubject;				//任务的主题	
	CString						strSponser;				//提交者	
	COleDateTime				odtAuditDate;		    //审核时间
	CString						strAuditorName;			//审核者
	CString						strAuditorHint;			//审核描述
	int                         nAduitLevel;            //级别
    
	BOOL						bRemoteTDIR;            //是否边采边编
	double						dSec_FlushFrequency;    //刷新率
	BOOL						bIfVideoFrameAnalysis;  //是否抽帧
	BOOL						bIfDoServerTranscode;   //是否转码
	BOOL						bIfSaveServerFiles;     //是否保存服务器文件
	BOOL						bIfDoCopy;              //是否拷贝

	BOOL                        bIfCapSeg;              //是否分段采集
	int                         nCapSegTime;            //分段采集时间，秒
	BOOL						bNeedPartInsertDB;		//需要分段入数据库
	BOOL						bNeedCombine;			//需要最后自动合并
	BOOL                        bIfSaveExplorer;        //自动合并入库
	BOOL                        bNeedAutoImportPart;    //是否分段迁移/提交
	
	BOOL                        bIfLinkDirect;          //是否直联
	BOOL                        bIfConflict;            //是否为冲突任务
	BOOL                        bIfVirtual;             //是否为虚拟任务，只进行统计不执行
	DY_GUID                     guidLinkOutSys;         //关联的外部系统条目guid(有可能是新闻,通稿等)

	//任务使用的首尾设备情况	
	BOOL                        bNeedDecode;             //信号是否需经过解码
	BOOL                        bNeedEncode;             //信号是否需经过编码
	BOOL                        bNeedChangeRate;         //信号是否需经过转换码率
	float                       fTargetRate;             //目标码率
	BOOL                        bNeedchangeVideo;        //是否需要转制
	BOOL                        bNeedDAOutbed;           //是否需要DA解出设备
	BOOL                        bNeedADInbed;            //是否需要AD合成设备	

	DY_GUID						guidPlayDeviceID;		 //任务源使用设备DY_GUID	
	DY_GUID						guidPlayPortID;		     //任务源使用通道guid
    
	BOOL                        bPreAllocFinish;        //是否经过预分配
	BOOL                        bPheDeviceSwitched;     //外围设备是否已经切换
	BOOL                        bIsServerPlay;          //源设备是否为服务器设备
	
	DWORD			            dwOldTaskProgress;	    //任务进度差异次数
	DWORD			            dwLastTaskProgress;     //任务进度

	BOOL						bUrgencyTask;			//紧急任务
	CString						strConflictReason;		//冲突原因

	DY_GUID						guidRecordSFDeviceID;    //任务目标使用时分设备DY_GUID
	DY_GUID						guidRecordSFPortID;		 //任务目标使用时分通道guid

	//预约关联信息
	BOOL						bFromProgram;			//来自于节目单
	DY_GUID						guidProgram;			//对应的节目单guid
	int							nBespeakTime;			//预约次数
	CStringArray				asBespeakUserName;		//预约过的用户名称
	CStringArray				asBespeakUserColumn;	//预约过的用户栏目

	BOOL                        bImportant;                       //重点节目
	BOOL                        bNeedTrans;                       //是否需要迁移
	int                         nTransDelayTime;                  //迁移延迟时间
    BOOL                        bInspect;               //是否技审
	BOOL                        bSigConfirm;            //是否信号确认
	CString                     strSatParam;            //信号参数
	CString                     strInMatrixPortName;    //矩阵端口名

	int                         nReserve1;              //int型冗余字段1
	int                         nReserve2;              //int型冗余字段2
	CString                     strReserve1;            //string型冗余字段1
	CString                     strReserve2;            //string型冗余字段2

	SDYULCTaskDeviceInfo		sTaskDeviceInfo;		//中间设备信息
	SDYULCTaskExtraInfo			sTaskExtraInfo;			//任务附加信息
	SDYULCTaskExternInfo		sTaskExternInfo;		//一些外部信息

   	SDYULCTaskInfo()
	{
		guidTaskID                = GUID_NULL;				
		strName                   = _T("");			
		strHint                   = _T("");			

		//
        strSignalAddress          = _T("");
		strSignalPort             = _T("");
        strRecordDeviceName       = _T("");

		guidTaskClass             = GUID_NULL;
	    strTaskClassName          = _T("");
        guidClipFormat            = GUID_NULL;
	    strClipFormatName         = _T("");

		strChannelID              = _T("");       
		strChannelName            = _T("");     
		strColumnID               = _T("");        
		strColumnName             = _T("");      
		strOwnerID                = _T("");			
		strOwnerName              = _T("");  
		strOwnerID20              = _T("");			
		strOwnerName20            = _T("");  

		strSubject				  = _T("");

		enumPriority              = DYULCTASK_PRIORITY_NORMAL;		
		enumEditStatus            = DYULCTASK_EDITSTATUS_NOPREFER;	
		enumEditSource			  = DYULCTASK_EDITSOURCE_UNKNOWN;
		strSponser                = _T("");			
		odtPreferDate.SetDateTime(2000,1,1,0,0,0);		
		odtAuditDate.SetDateTime(2000,1,1,0,0,0);	
		strAuditorName            = _T("");		
		strAuditorHint            = _T("");
		nAduitLevel               = 0;
		enumRunStatus             = DYULCTASK_RUNSTATUS_WAITING;      
        bLoopTask                 = FALSE;
		guidCycle                 = GUID_NULL;          

		odtTaskStartDate.SetDateTime(2000,1,1,0,0,0);	
		odtTaskStopDate.SetDateTime(2000,1,1,0,0,0);		
		dwDuration                = 0;			
        bBackUp                   = FALSE;
		guidOrgTask               = GUID_NULL;        
		strOrgTaskName            = _T("");     

		bIfLinkDirect             = FALSE;      
		bIfConflict               = FALSE;        
		bIfVirtual                = FALSE;         
		guidLinkOutSys            = GUID_NULL;

		bNeedDecode               = FALSE;        
		bNeedEncode               = FALSE;        
		bNeedChangeRate           = FALSE;    
		fTargetRate               = FALSE;        
		bNeedchangeVideo          = FALSE;   
		bNeedDAOutbed             = FALSE;      
		bNeedADInbed              = FALSE; 

		guidPlayDeviceID          = GUID_NULL;	
		guidPlayPortID            = GUID_NULL;
		guidRecordDeviceID    = GUID_NULL;	
		guidRecordPortID      = GUID_NULL;

		enumSourceType          = DYULCTASK_SOURCETYPE_UNKOWN;
        
		guidSrcVTRTapeType      = GUID_NULL;
	    strSrcVTRTapeTypeName   = _T("");
	    strSrcVTRTapeName       = _T("");

	    bSrcSetTrimInOut        = FALSE;
		dwSrcVTRTrimIn	        = 0;
	    dwSrcVTRTrimOut         = 0;	
        
		guidSigGroup            = GUID_NULL;
		strSigGroupName         = _T("");
	    guidSignalID            = GUID_NULL;
	    strSignalName           = _T("");
	    bIfReceiver             = FALSE;
		guidReceiver			= GUID_NULL;
	    enumSrcSigType          = DYULCDEVICE_PORTTYPE_UNKNOWN;
	    bHavePrioritySig        = FALSE;
		bIsHD                   = FALSE;

		enumUDPPackType  = DYULC_UDP_NO;

		enumTargetType        = DYULCTASK_TARGETTYPE_UNKOWN;

		enumRecordDevice	= DYULC_DEVICE_UNKOWN;
        
		guidDestVTRTapeType   = GUID_NULL;
	    strDestTapeTypeName   = _T("");
	    strDestVTRTapeName    = _T("");
	    bDestSetTrimInOut     = FALSE;
	    dwDestVTRTrimIn           = 0;
	    dwDestVTRTrimOut          = 0;
		dwDestVTRRecTrackFlag = (DYDEVICE_RECTRACK_AUDIO_1|DYDEVICE_RECTRACK_AUDIO_2|DYDEVICE_RECTRACK_VIDEO);
		bDestIsVTRRecAssemble = 2;

    	bRemoteTDIR           = FALSE;
	    dSec_FlushFrequency   = 1.0;
	    bIfVideoFrameAnalysis = FALSE;
		bIfDoServerTranscode  = FALSE;
	    bIfSaveServerFiles    = FALSE;
	    bIfDoCopy             = FALSE;
		bIfCapSeg          = FALSE;
        nCapSegTime        = 0;
		bNeedPartInsertDB	= FALSE;
		bNeedAutoImportPart     = TRUE;
		bNeedCombine		= FALSE;
		bIfSaveExplorer     =FALSE;

		bPreAllocFinish = FALSE;
		bPheDeviceSwitched = FALSE;
		bIsServerPlay = FALSE;

		dwOldTaskProgress = 0;
		dwLastTaskProgress = 0;

		bUrgencyTask = FALSE;

		guidRecordSFDeviceID    = GUID_NULL;	
		guidRecordSFPortID      = GUID_NULL;

		bFromProgram		= FALSE;
		guidProgram			= GUID_NULL;
		nBespeakTime		= 0;

		bImportant          = FALSE;
		bNeedTrans               = TRUE;     
		nTransDelayTime          = 1;

		bInspect         = FALSE;
	    bSigConfirm       = FALSE;
	    strSatParam       = _T("");
	    strInMatrixPortName = _T("");

		nReserve1         = 0;
	    nReserve2         = 0;

	    strReserve1       =_T("");
        strReserve2       =_T("");

		iFileFormat = 0;
		iPreGetFlag = 0;
		odtModifyTime.SetDateTime(2000,1,1,0,0,0);
		strProgramPath=_T("");

		guidBizDomain = GUID_NULL; 
        strBizDomain  = _T("");
        guidProjectItem = GUID_NULL;
        strProjectItem = _T("");
		strAddition = _T("");
		strTaskFrom = _T("");
	};

	SDYULCTaskInfo(const SDYULCTaskInfo &other)
	{		
		*this = other;
	};

	~SDYULCTaskInfo()
	{
		
	};

	SDYULCTaskInfo& operator = (const SDYULCTaskInfo& other)
	{
		guidTaskID                = other.guidTaskID;				
		strName                   = other.strName;			
		strHint                   = other.strHint;

		strSignalAddress          = other.strSignalAddress;
		strSignalPort             = other.strSignalPort;
		strRecordDeviceName       = other.strRecordDeviceName;

		guidTaskClass             = other.guidTaskClass;
	    strTaskClassName          = other.strTaskClassName;
        guidClipFormat            = other.guidClipFormat;
	    strClipFormatName         = other.strClipFormatName;
				
		strChannelID              = other.strChannelID;       
		strChannelName            = other.strChannelName;     
		strColumnID               = other.strColumnID;        
		strColumnName             = other.strColumnName;      
		strOwnerID                = other.strOwnerID;			
		strOwnerName              = other.strOwnerName;
        strOwnerID20              = other.strOwnerID20;			
		strOwnerName20            = other.strOwnerName20;

		strSubject				  = other.strSubject;

		enumPriority              = other.enumPriority;		
		enumEditStatus            = other.enumEditStatus;	
		enumEditSource			  = other.enumEditSource;
		strSponser                = other.strSponser;			
		odtPreferDate             = other.odtPreferDate;		
		odtAuditDate              = other.odtAuditDate;	
		strAuditorName            = other.strAuditorName;		
		strAuditorHint            = other.strAuditorHint;
		nAduitLevel               = other.nAduitLevel;
		enumRunStatus             = other.enumRunStatus;      
        bLoopTask                 = other.bLoopTask;
		guidCycle                 = other.guidCycle;          
		sDateLoop                 = other.sDateLoop;          
		odtTaskStartDate          = other.odtTaskStartDate;	
		odtTaskStopDate           = other.odtTaskStopDate;		
		dwDuration                = other.dwDuration;			
        bBackUp                   = other.bBackUp;
		guidOrgTask               = other.guidOrgTask;        
		strOrgTaskName            = other.strOrgTaskName;     

		bIfLinkDirect             = other.bIfLinkDirect;      
		bIfConflict               = other.bIfConflict;        
		bIfVirtual                = other.bIfVirtual;         
		guidLinkOutSys            = other.guidLinkOutSys;

		bNeedDecode               = other.bNeedDecode;        
		bNeedEncode               = other.bNeedEncode;        
		bNeedChangeRate           = other.bNeedChangeRate;    
		fTargetRate               = other.fTargetRate;        
		bNeedchangeVideo          = other.bNeedchangeVideo;   
		bNeedDAOutbed             = other.bNeedDAOutbed;      
		bNeedADInbed              = other.bNeedADInbed; 

		guidPlayDeviceID          = other.guidPlayDeviceID;	
        guidPlayPortID            = other.guidPlayPortID;
        guidRecordDeviceID        = other.guidRecordDeviceID;		
		guidRecordPortID          = other.guidRecordPortID;

		enumSourceType          = other.enumSourceType;
        
		guidSrcVTRTapeType      = other.guidSrcVTRTapeType;
	    strSrcVTRTapeTypeName   = other.strSrcVTRTapeTypeName;
	    strSrcVTRTapeName       = other.strSrcVTRTapeName;
	    
		bSrcSetTrimInOut        = other.bSrcSetTrimInOut;
	    dwSrcVTRTrimIn		    = other.dwSrcVTRTrimIn;
	    dwSrcVTRTrimOut         = other.dwSrcVTRTrimOut;	
        
		guidSigGroup            = other.guidSigGroup;
		strSigGroupName         = other.strSigGroupName;
	    guidSignalID            = other.guidSignalID;
	    strSignalName           = other.strSignalName;
	    bIfReceiver             = other.bIfReceiver;
		guidReceiver			= other.guidReceiver;
	    enumSrcSigType          = other.enumSrcSigType;
	    bHavePrioritySig        = other.bHavePrioritySig;
		bIsHD                   = other.bIsHD;	
        
		enumUDPPackType  = other.enumUDPPackType;

        enumTargetType        = other.enumTargetType;

		enumRecordDevice	 = other.enumRecordDevice;
        
		guidDestVTRTapeType   = other.guidDestVTRTapeType;
	    strDestTapeTypeName   = other.strDestTapeTypeName;
	    strDestVTRTapeName    = other.strDestVTRTapeName;
	    bDestSetTrimInOut     = other.bDestSetTrimInOut;
	    dwDestVTRTrimIn           = other.dwDestVTRTrimIn;
	    dwDestVTRTrimOut          = other.dwDestVTRTrimOut;
		dwDestVTRRecTrackFlag = other.dwDestVTRRecTrackFlag;
		bDestIsVTRRecAssemble = other.bDestIsVTRRecAssemble;

		sClipDataInfo		  = other.sClipDataInfo;
    	bRemoteTDIR           = other.bRemoteTDIR;
	    dSec_FlushFrequency   = other.dSec_FlushFrequency;
	    bIfVideoFrameAnalysis = other.bIfVideoFrameAnalysis;
		bIfDoServerTranscode  = other.bIfDoServerTranscode;
	    bIfSaveServerFiles    = other.bIfSaveServerFiles;
	    bIfDoCopy             = other.bIfDoCopy;       
        
		bIfCapSeg          = other.bIfCapSeg;
        nCapSegTime        = other.nCapSegTime;
		bNeedPartInsertDB  = other.bNeedPartInsertDB;
		bNeedCombine	   = other.bNeedCombine;
        bIfSaveExplorer    = other.bIfSaveExplorer;
		bNeedAutoImportPart = other.bNeedAutoImportPart;

		sTaskDeviceInfo	   = other.sTaskDeviceInfo;
		sTaskExtraInfo	   = other.sTaskExtraInfo;
		sTaskExternInfo	   = other.sTaskExternInfo;
        
		bPreAllocFinish    = other.bPreAllocFinish;
		bPheDeviceSwitched = other.bPheDeviceSwitched;
		bIsServerPlay      = other.bIsServerPlay;

		dwOldTaskProgress  = other.dwOldTaskProgress;
        dwLastTaskProgress  = other.dwLastTaskProgress;

		bUrgencyTask		= other.bUrgencyTask;
		strConflictReason	= other.strConflictReason;

		guidRecordSFDeviceID        = other.guidRecordSFDeviceID;		
		guidRecordSFPortID          = other.guidRecordSFPortID;

		bFromProgram		= other.bFromProgram;
		guidProgram			= other.guidProgram;
		nBespeakTime		= other.nBespeakTime;

		asBespeakUserName.Copy(other.asBespeakUserName);
		asBespeakUserColumn.Copy(other.asBespeakUserColumn);
        
		bImportant          = other.bImportant;

		bNeedTrans               = other.bNeedTrans;     
		nTransDelayTime          = other.nTransDelayTime;
		bInspect         = other.bInspect;
	    bSigConfirm       = other.bSigConfirm;
	    strSatParam       = other.strSatParam;
	    strInMatrixPortName = other.strInMatrixPortName;

		nReserve1         = other.nReserve1;
	    nReserve2         = other.nReserve2;
	    strReserve1       = other.strReserve1;
        strReserve2       = other.strReserve2;
		iFileFormat       = other.iFileFormat;
		iPreGetFlag       = other.iPreGetFlag;
		odtModifyTime     = other.odtModifyTime;
        strProgramPath    = other.strProgramPath;

		guidBizDomain = other.guidBizDomain; 
        strBizDomain  = other.strBizDomain;
        guidProjectItem = other.guidProjectItem;
        strProjectItem = other.strProjectItem;

		strAddition = other.strAddition;
		strTaskFrom = other.strTaskFrom;

		return *this;
	};
};
typedef CArray<SDYULCTaskInfo, SDYULCTaskInfo&> ASDYULCTaskInfoArray;

//任务保留字段信息
struct SDYULCTaskReserveInfo 
{
	DY_GUID     guidTaskID;                      //所属任务DY_GUID

	CString  strReserve1;                     //保留字段1
	CString  strReserve2;
	CString  strReserve3;
	CString  strReserve4;
	CString  strReserve5;
	CString  strReserve6;
	CString  strReserve7;
	CString  strReserve8;
	CString  strReserve9;
	CString  strReserve10;

	SDYULCTaskReserveInfo()
	{
		guidTaskID      = GUID_NULL;

		strReserve1     = _T("");     
		strReserve2     = _T("");
		strReserve3     = _T("");
		strReserve4     = _T("");
		strReserve5     = _T("");
		strReserve6     = _T("");
		strReserve7     = _T("");
		strReserve8     = _T("");
		strReserve9     = _T("");
		strReserve10    = _T("");	
	};

	SDYULCTaskReserveInfo(const SDYULCTaskReserveInfo &other)
	{
		*this = other;
	};	

	SDYULCTaskReserveInfo& operator = (const SDYULCTaskReserveInfo& other)
	{
		guidTaskID       = other.guidTaskID;

		strReserve1      = other.strReserve1;     
		strReserve2      = other.strReserve3;
		strReserve3      = other.strReserve3;
		strReserve4      = other.strReserve4;
		strReserve5      = other.strReserve5;
		strReserve6      = other.strReserve6;
		strReserve7      = other.strReserve7;
		strReserve8      = other.strReserve8;
		strReserve9      = other.strReserve9;
		strReserve10     = other.strReserve10;		
		
		return *this;
	};	
};
typedef CArray<SDYULCTaskReserveInfo, SDYULCTaskReserveInfo&> ASDYULCTaskReserveInfoArray;

//任务素材迁移状态记录
struct SDYULContentImportStatus
{
	CString          strRequestid;             //迁移要求DY_GUID
	CString          strTaskguid;              //涉及任务的DY_GUID
	long             lStatus;                  //完成状态        0未迁移；1正在迁移；2迁移成功 3 迁移失败
	COleDateTime     dtModifyTime;             //状态的改变时间
	CString          strProcessName;           //迁移要求流程名称

	SDYULContentImportStatus()
	{
		strRequestid   = _T("");
		strTaskguid    = _T("");
		lStatus        = 0;
		dtModifyTime   = COleDateTime::GetCurrentTime();
		strProcessName = _T("");
	};

	SDYULContentImportStatus(const SDYULContentImportStatus &other)
	{
		*this = other;
	};

	~SDYULContentImportStatus()
	{
	};

	SDYULContentImportStatus& operator = (const SDYULContentImportStatus& other)
	{
		strRequestid   = other.strRequestid;
		strTaskguid    = other.strTaskguid;
		lStatus        = other.lStatus;
		dtModifyTime   = other.dtModifyTime;
		strProcessName = other.strProcessName;

		return *this;
	};
};
typedef CArray<SDYULContentImportStatus, SDYULContentImportStatus&> ASDYULContentImportStatusArray;

//目标素材文件段信息
struct SDYULClipPartInfo
{
	DY_GUID		        guidTask;			//任务DY_GUID
	DY_GUID		        guidClip;			//对应素材段DY_GUID
	int			        nIndex;				//素材段序号
	COleDateTime        odtCreateTime;      //生成时间

	SDYULClipPartInfo()
	{
		guidTask       = GUID_NULL;
		guidClip       = GUID_NULL;
		nIndex         = 0;
		odtCreateTime  = COleDateTime::GetCurrentTime();
	};

	SDYULClipPartInfo(const SDYULClipPartInfo &other)
	{
		*this = other;
	};

	~SDYULClipPartInfo()
	{
	};

	SDYULClipPartInfo& operator = (const SDYULClipPartInfo& other)
	{
		guidTask       = other.guidTask;
		guidClip       = other.guidClip;
		nIndex         = other.nIndex;
		odtCreateTime  = other.odtCreateTime;

		return *this;
	};
};
typedef CArray<SDYULClipPartInfo, SDYULClipPartInfo&> ASDYULClipPartInfoArray;

//任务目标素材文件成员信息
struct SDYULClipFileElementInfo
{
	DY_GUID                    guidClip;                       //  素材DY_GUID
	CString					strName;                        //  素材名称
	DYCLIPCLASSFLAG			dwClass;						//	素材视音频分类
	DWORD					dwLanguageID;					//	DEFAULT : 0
	DY_VIDEO_STANDARD		enumVideoStandard;				//	视频标准
	DY_STREAM_TYPE 	        enumSpecialMediaType;			//	视音频编解码格式类型
	DWORD					dwPropertyFlag;					//	特别标志 see DYCLIPELEMENTPROPERTYFLAG_???
	DY_GUID                    guidClipVAElement;              //  素材视音频类型结构guid

	CString					strFileName;					//	除音频文件外的文件名
	CString					strAudioFileNames[8];			//	音频文件名

	DWORD                   dwTrimIn;                       //  入点
	DWORD                   dwTrimOut;                      //  出点
	
	CString					strSignalSourceName;			//	素材来源, example:录像带ID, or 卫星channel...
	CString					strSignalSourceHint;			//	素材来源备注
	DWORD					dwVTRTapeInPoint;				//	录像带入点
	DWORD					dwVTRTapeOutPoint;				//	录像带出点

	//DYCLIP_STORETYPE_FLAG	dwDataStoreType;				//  素材存储类型
	int	 dwDataStoreType;				//  素材存储类型
	CString 				strAccessPath;					//  对 DYClipStoreType_AccessPath;
	CString 				strBackupPath;					//  对 DYClipStoreType_BackupPath;
	CString 				strFTPServerInfo;				//  对 DYClipStoreType_FTPServer;
	CString 				strBackupFTPServerInfo;			//  对 DYClipStoreType_BackupFTPServer;

	SDYULClipFileElementInfo()
	{
		guidClip             = GUID_NULL;
		strName              = _T("");
		dwClass              = 0;
		dwLanguageID         = 0;
		enumVideoStandard    = DYVIDEOSTANDARD_UNKNOW;
		enumSpecialMediaType = DYSTREAMTYPE_UNKNOWN;
		dwPropertyFlag       = 0;
		guidClipVAElement    = GUID_NULL;

		strFileName          = _T("");
		for( int i=0; i<8; i++ )
			strAudioFileNames[i] = _T("");

		dwTrimIn             = 0;
		dwTrimOut            = 0;
		
		strSignalSourceName  = _T("");
		strSignalSourceHint  = _T("");
		dwVTRTapeInPoint     = 0;
		dwVTRTapeOutPoint    = 0;

		dwDataStoreType        = 0;//DYClipStoreType_UnKnow;
		strAccessPath          = _T("");
		strBackupPath          = _T("");
		strFTPServerInfo       = _T("");
		strBackupFTPServerInfo = _T("");		
	};

	SDYULClipFileElementInfo(const SDYULClipFileElementInfo & other) 
	{ 
		*this = other; 
	};	

	SDYULClipFileElementInfo& operator = (const SDYULClipFileElementInfo& other)
	{
		guidClip             = other.guidClip;
		strName              = other.strName;
		dwClass              = other.dwClass;
		dwLanguageID         = other.dwLanguageID;
		enumVideoStandard    = other.enumVideoStandard;
		enumSpecialMediaType = other.enumSpecialMediaType;
		dwPropertyFlag       = other.dwPropertyFlag;
		guidClipVAElement    = other.guidClipVAElement;

		strFileName          = other.strFileName;
		for( int i=0; i<8; i++ )
			strAudioFileNames[i] = other.strAudioFileNames[i];

		dwTrimIn             = other.dwTrimIn;
		dwTrimOut            = other.dwTrimOut;
				
		strSignalSourceName  = other.strSignalSourceName;
		strSignalSourceHint  = other.strSignalSourceHint;
		dwVTRTapeInPoint     = other.dwVTRTapeInPoint;
		dwVTRTapeOutPoint    = other.dwVTRTapeOutPoint;

		dwDataStoreType        = other.dwDataStoreType;
		strAccessPath          = other.strAccessPath;
		strBackupPath          = other.strBackupPath;
		strFTPServerInfo       = other.strFTPServerInfo;
		strBackupFTPServerInfo = other.strBackupFTPServerInfo;
		
		return *this;
	};

	BOOL IsMultiAudioElement()
	{
		return ((dwPropertyFlag&DYAUDIOPROPERTYTYPE_MULTIAUDIOSET)?TRUE:FALSE);
	}

	BOOL IsAudio51Element()
	{
		return ((dwPropertyFlag&DYAUDIOPROPERTYTYPE_AUDIOSET51)?TRUE:FALSE);
	}

	BOOL IsAudio71Element()
	{
		return ((dwPropertyFlag&DYAUDIOPROPERTYTYPE_AUDIOSET71)?TRUE:FALSE);
	}

	CString	GetFileName( int nIndex = 0 )
	{
		if(dwClass != (DWORD)DYCLIP_CLASS_A && IsMultiAudioElement() == 0 && IsAudio51Element() == 0 && IsAudio71Element() == 0 )
			return strFileName;
		else if( nIndex >= 0 && nIndex < 8 )
			return strAudioFileNames[nIndex];
		else
			return _T("");
	};
	//CString	GetFullFileName( int nIndex = 0, DY_CLIP_STORE_TYPE enumStoreType=DYClipStoreType_AccessPath )
	CString	GetFullFileName( int nIndex = 0, int enumStoreType=0 )
	{
		CString	strFileName = GetFileName( nIndex );
		if( strFileName.GetLength() <= 0 )
			return _T("");
		
		return (strAccessPath + CString(strAccessPath.IsEmpty() ? _T("") : _T("\\")) + strFileName);		
	};
	/*
	CString	GetFullFileName( int nIndex = 0, int enumStoreType=0 )
	{
		CString	strFileName = GetFileName( nIndex );
		if( strFileName.GetLength() <= 0 || 
			(dwDataStoreType&enumStoreType) == 0 ||
			(enumStoreType != DYClipStoreType_AccessPath &&
			enumStoreType != DYClipStoreType_BackupPath &&
			enumStoreType != DYClipStoreType_FTPServer &&
			enumStoreType != DYClipStoreType_BackupFTPServer) )
			return _T("");
		if( enumStoreType == DYClipStoreType_AccessPath )
			return (strAccessPath + CString(strAccessPath.IsEmpty() ? _T("") : _T("\\")) + strFileName);
		else if( enumStoreType == DYClipStoreType_BackupPath )
			return (strAccessPath + CString(strAccessPath.IsEmpty() ? _T("") : _T("\\")) + strFileName);
		else if( enumStoreType == DYClipStoreType_FTPServer )
			return (strAccessPath + CString(strAccessPath.IsEmpty() ? _T("") : _T("\\")) + strFileName);
		else if( enumStoreType == DYClipStoreType_BackupFTPServer )
			return (strAccessPath + CString(strAccessPath.IsEmpty() ? _T("") : _T("\\")) + strFileName);
		else
			return _T("");
	};*/
};
typedef CArray<SDYULClipFileElementInfo, SDYULClipFileElementInfo&> ASDYULClipFileElementInfoArray;

enum  DYULC_LOGTYPE
{
	DYULCTASK_LOGTYPE_UNKNOWN		=	0,
	DYULCTASK_LOGTYPE_OVERTIMEERR   =	1,			    //由于超过结束时间设为失败
	DYULCTASK_LOGTYPE_ALLOCATE		=	2,			    //分配任务
	DYULCTASK_LOGTYPE_NOALLOCANSWER	=	3,			    //分配任务未响应
	DYULCTASK_LOGTYPE_RESETWAIT		=	4,			    //重设为等待
	DYULCTASK_LOGTYPE_ACCEPTANSWER  =	5,			    //分配任务已经响应
	DYULCTASK_LOGTYPE_DENYRECANSWER =	6,			    //分配录制任务不接受
	DYULCTASK_LOGTYPE_DENYPLYANSWER =	7,			    //分配播放任务不接受

	DYULCTASK_LOGTYPE_NOBEGINRECANSWER  = 8,			//未接收到开始录制消息超时
	DYULCTASK_LOGTYPE_ACTBEGINRECANSWER = 9,            //接收到开始录制消息
	DYULCTASK_LOGTYPE_SETDOING          = 10,           //设置为正在执行
	DYULCTASK_LOGTYPE_ACTPROGRSS        = 11,           //接收到进度回复
	DYULCTASK_LOGTYPE_NOACTPROGRSS      = 12,           //超时未接收到进度回复
	DYULCTASK_LOGTYPE_NOACTPROGRSEERR   = 13,           //超时未接收到进度回复设为失败
	DYULCTASK_LOGTYPE_NOACTPROGRSEEND   = 14,           //超时未接收到进度回复设为结束
	DYULCTASK_LOGTYPE_ACTENDRECANSWER   = 15,           //接收到录制结束消息
	DYULCTASK_LOGTYPE_ACTENDRECANSWEREND= 16,           //接收到录制结束消息设为结束
	DYULCTASK_LOGTYPE_ACTRECERROR       = 17,           //接收到录制错误消息
	DYULCTASK_LOGTYPE_ACTPLYERROR       = 18,           //接收到播放错误消息

	DYULCTASK_LOGTYPE_CHANGELENGTH      = 19,           //改变长度
	DYULCTASK_LOGTYPE_FROCESTOP         = 20,           //手动停止
	DYULCTASK_LOGTYPE_HANDRECALLOC      = 21,           //手动取消分配
	
	DYULCTASK_LOGTYPE_NOGETSRCVTR		= 22,           //没有获得源VTR
	DYULCTASK_LOGTYPE_NOGETSRCSIG       = 23,           //没有获得源信号
	DYULCTASK_LOGTYPE_NOGETDESTVTR      = 24,           //没有获得目标VTR
	DYULCTASK_LOGTYPE_NOGETDESTUL       = 25,           //没有获得目标工作站
	DYULCTASK_LOGTYPE_NOGETDESTSV       = 26,           //没有获得目标服务器	
	DYULCTASK_LOGTYPE_SWITCHGATEWAYERR  = 27,           //切换媒体网关失败
	DYULCTASK_LOGTYPE_SWITCHMATRIXERR   = 28,           //切换矩阵失败
	DYULCTASK_LOGTYPE_ALLOCATETASKERR   = 29,           //发送任务分配失败

	DYULCTASK_LOGTYPE_ADDTASK           = 30,           //添加任务
	DYULCTASK_LOGTYPE_MODTASK           = 31,           //修改任务
	DYULCTASK_LOGTYPE_DELTASK           = 32,           //删除任务
	DYULCTASK_LOGTYPE_PRETASK           = 33,           //提交任务
	DYULCTASK_LOGTYPE_AUDTASK           = 34,           //审核任务
	DYULCTASK_LOGTYPE_AUDRECJTASK       = 35,           //审核失败任务

	DYULCTASK_LOGTYPE_CHANGESATRECEV    = 36,           //改变卫星接收机

	DYULCTASK_LOGTYPE_MOVECLIPSUCCESS   = 37,           //采集素材迁移成功
	DYULCTASK_LOGTYPE_MOVECLIPFAILE     = 38,           //采集素材迁移失败

	DYULCTASK_LOGTYPE_NOGETSATSIGPROCESSER    = 39,        //没有找到可用的卫星信号处理设备
	DYULCTASK_LOGTYPE_NOGETTVENCODERPORT      = 40,        //没有找到可用的电视解调器端口
	DYULCTASK_LOGTYPE_NOGETANALOGADJUSTER     = 41,        //没有找到可用的模拟信号调节设备
	DYULCTASK_LOGTYPE_NOGETDAOUTBEDDEVICE     = 42,        //没有找到可用的DA解出设备
	DYULCTASK_LOGTYPE_SWITCHLBANDMATRIXERR    = 43,        //切换L波段矩阵失败
	DYULCTASK_LOGTYPE_SWITCHSATSIGPROCESSERR  = 44,        //切换卫星信号处理设备失败
	DYULCTASK_LOGTYPE_SWITCHTVENCODERERR      = 45,        //切换电视信号解调器失败
	DYULCTASK_LOGTYPE_SWITCHANALOGADJSTERERR  = 46,        //切换模拟信号调节设备失败
	DYULCTASK_LOGTYPE_SWITCHMIDMATRIXERR      = 47,        //切换中间矩阵失败

	DYULCTASK_LOGTYPE_CLIENTLOSTLINK          = 48,        //客户端失去连接
	DYULCTASK_LOGTYPE_SRCSIGHAVEERR           = 49,        //任务源信号存在质量问题

	DYULCTASK_LOGTYPE_PREALLOCNOGETSRCVTR             = 50,        //预分配没有获得源VTR
	DYULCTASK_LOGTYPE_PREALLOCNOGETSRCSIG             = 51,        //预分配没有获得源信号
	DYULCTASK_LOGTYPE_PREALLOCNOGETSATSIGPROCESSER    = 52,        //预分配没有找到可用的卫星信号处理设备
	DYULCTASK_LOGTYPE_PREALLOCNOGETTVENCODERPORT      = 53,        //预分配没有找到可用的电视解调器端口
	DYULCTASK_LOGTYPE_PREALLOCNOGETANALOGADJUSTER     = 54,        //预分配没有找到可用的模拟信号调节设备
	DYULCTASK_LOGTYPE_PREALLOCNOGETDAOUTBEDDEVICE     = 55,        //预分配没有找到可用的DA解出设备
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTVTR            = 56,        //预分配没有获得目标VTR
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTUL             = 57,        //预分配没有获得目标工作站
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTSV             = 58,        //预分配没有获得目标服务器
	DYULCTASK_LOGTYPE_PREALLOCSWITCHGATEWAYERR        = 59,        //预分配切换媒体网关失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHLBANDMATRIXERR    = 60,        //预分配切换L波段矩阵失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHSATSIGPROCESSERR  = 61,        //预分配切换卫星信号处理设备失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHTVENCODERERR      = 62,        //预分配切换电视信号解调器失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHANALOGADJSTERERR  = 63,        //预分配切换模拟信号调节设备失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHMIDMATRIXERR      = 64,        //预分配切换中间矩阵失败
	DYULCTASK_LOGTYPE_PREALLOCSWITCHMATRIXERR         = 65,        //预分配切换矩阵失败
	DYULCTASK_LOGTYPE_PREALLOCALLOCATE		          =	66,		   //预分配分配任务

	DYULCTASK_LOGTYPE_PRETESTVTRSTATUS_ERROR          = 67,        //预分配检测到录机状态错误	
	DYULCTASK_LOGTYPE_USEDCONFILCTDEVICE              = 68,        //预分配检测到使用了相同的设备

	DYULCTASK_LOGTYPE_PREALLOCATETASKGETDEVICEERR     = 69,        //预分配任务失败

	DYULCTASK_LOGTYPE_FROCESETTASKFINISHSTATUS        = 70,        //强制设为执行完毕

	DYULCTASK_LOGTYPE_FROCEREPREALLOCATE              = 71,        //强制重新预分配

	DYULCTASK_LOGTYPE_CLIENTSYSBUSY                   = 72,        //客户端系统忙
	DYULCTASK_LOGTYPE_CLIENTTASKEXIST                 = 73,        //客户端已有此任务存在
	DYULCTASK_LOGTYPE_CLIENTGETTASKFAIL               = 74,        //客户端查询任务失败 
	DYULCTASK_LOGTYPE_CLIENTGETTASKCONFLICT           = 75,        //客户端任务采集时间存在冲突
	DYULCTASK_LOGTYPE_CLIENTNOENOUGHSPACE             = 76,        //客户端发现磁盘空间不够
	DYULCTASK_LOGTYPE_CLIENTNOFINDSIGNAL              = 77,        //客户端没有找到信号
	DYULCTASK_LOGTYPE_CLIENTGETCLIPLENGTHFAIL         = 78,        //客户端取得素材长度失败
	DYULCTASK_LOGTYPE_CLIENTGETPATHERROE              = 79,        //客户端发现采集路径错误

	DYULCTASK_LOGTYPE_PREALLOCSWITCHDECODERERR        = 80,        //预分配切换解码器设备失败
	DYULCTASK_LOGTYPE_SWITCHDECODERERR                = 81,        //切换解码器设备失败

	DYULCTASK_LOGTYPE_NOGETVSCHANGEDEVICE             = 82,        //没有找到可用的制转设备
	DYULCTASK_LOGTYPE_PREALLOCNOGETVSCHANGEDEVICE     = 83,        //预分配没有找到可用的制转设备
	DYULCTASK_LOGTYPE_SIGNALCHECKERROR                = 84,        //信号自动技检发现问题
    DYULCTASK_LOGTYPE_SIGCONFIRM                      = 85,        //信号确认
};

//参数类别翻译表（例如  日志类别翻译）
struct STypeParamTranslate
{
	DY_GUID						guidID;        //          
	int                         nType;         //类别
	int                         nCode;         //代码   
	CString                     strMsg;        //日志字符串
	CString                     strExtern;     //备注
		
	STypeParamTranslate()
	{
		guidID       = GUID_NULL;     
		nType     = 0;
		nCode     = 0;
		strMsg       = _T("");
		strExtern      = _T("");		
	};
};
typedef CArray<STypeParamTranslate, STypeParamTranslate&> ASTypeParamTranslateArray;

//任务日志信息结构
struct SDYULCTaskLogInfo
{
	DY_GUID						guidLog;              
	COleDateTime                odtCreatTime;
	DY_GUID                        guidTask;
	CString                     strTaskName;
	DYULC_LOGTYPE               enumLogType;
	CString                     strActor;
	CString                     strLogMsg;
    BOOL                        bShow;
	
	SDYULCTaskLogInfo()
	{
		guidLog       = GUID_NULL;     
		odtCreatTime.SetDateTime(1900,1,1,0,0,0);
		guidTask      = GUID_NULL;
		strTaskName   = _T("");
		enumLogType   = DYULCTASK_LOGTYPE_UNKNOWN;
		strActor      = _T("");
		strLogMsg     = _T("");
		bShow         = FALSE;
	};
	
	SDYULCTaskLogInfo(const SDYULCTaskLogInfo &other)
	{
		*this = other;
	};

	SDYULCTaskLogInfo& operator = (const SDYULCTaskLogInfo& other)
	{
		guidLog       = other.guidLog;     
		odtCreatTime  = other.odtCreatTime;
		guidTask      = other.guidTask;
		strTaskName   = other.strTaskName;
		enumLogType   = other.enumLogType;
		strActor      = other.strActor;
		strLogMsg     = other.strLogMsg;
        bShow         = other.bShow;

		return *this;
	};
};
typedef CArray<SDYULCTaskLogInfo, SDYULCTaskLogInfo&> ASDYULCTaskLogInfoArray;

struct SDYULCMatrixLinkInfo
{
	DY_GUID          guidMatrix;
	DY_GUID          guidInPort;
	DY_GUID          guidOutPort;

	SDYULCMatrixLinkInfo()
	{
		guidMatrix     = GUID_NULL;
		guidInPort     = GUID_NULL;
		guidOutPort    = GUID_NULL;		
	};

	SDYULCMatrixLinkInfo(const SDYULCMatrixLinkInfo & other) 
	{ 
		*this = other; 
	};

	SDYULCMatrixLinkInfo& operator = (const SDYULCMatrixLinkInfo& other)
	{
		guidMatrix         = other.guidMatrix;
		guidInPort         = other.guidInPort;
		guidOutPort        = other.guidOutPort;

		return *this;
	};
};
typedef CArray<SDYULCMatrixLinkInfo, SDYULCMatrixLinkInfo&> ASDYULCMatrixLinkInfoArray;

struct SDYULCProgManSysColNameInfo
{
	CString   strColName;     //栏目名称
	CString   strColCode;     //栏目代码
	CString   strChannelCode; //频道编码
	CString   strChannelName; //频道名称
	

	SDYULCProgManSysColNameInfo()
	{
		strColName     = _T("");    
		strColCode     = _T("");    
		strChannelCode = _T("");
		strChannelName = _T("");
	};

	SDYULCProgManSysColNameInfo(const SDYULCProgManSysColNameInfo &other)
	{
		*this = other;
	};

	SDYULCProgManSysColNameInfo& operator = (const SDYULCProgManSysColNameInfo& other)
	{
		strColName     = other.strColName;    
		strColCode     = other.strColCode;    
		strChannelCode = other.strChannelCode;
		strChannelName = other.strChannelName;

		return *this;
	};
};
typedef CArray<SDYULCProgManSysColNameInfo, SDYULCProgManSysColNameInfo&> ASDYULCProgManSysColNameInfoArray;

struct SDYULCProgManSysColInfo
{
	CString   strColTypeName;     //栏目类型名称
	CString   strColTypeCode;     //栏目类型代码

	ASDYULCProgManSysColNameInfoArray  asColNameInfoArr;	

	SDYULCProgManSysColInfo()
	{
		strColTypeName = _T("");
		strColTypeCode = _T("");

		asColNameInfoArr.RemoveAll();		
	};

	SDYULCProgManSysColInfo(const SDYULCProgManSysColInfo &other)
	{
		*this = other;
	};

	SDYULCProgManSysColInfo& operator = (const SDYULCProgManSysColInfo& other)
	{
		strColTypeName = other.strColTypeName;
		strColTypeCode = other.strColTypeCode;

		asColNameInfoArr.RemoveAll();
		asColNameInfoArr.Copy(other.asColNameInfoArr);

		return *this;
	};
};
typedef CArray<SDYULCProgManSysColInfo, SDYULCProgManSysColInfo&> ASDYULCProgManSysColInfoArray;

//任务审核信息结构
struct SDYULCTaskAuditInfo
{
	DY_GUID						guidTask;                //任务DY_GUID
	DY_GUID                        guidAudit;               //本身DY_GUID
	CString                     strAuditorName;          //审核人名称
	int                         nAuditLeve;              //审核级别,分别为1，2，3，4，5
	int                         nAuditRet;               //审核结果，通过为1，不通过为0
	CString                     strAuditInfo;            //审核信息
	COleDateTime                odtAuditTime;            //审核时间


	SDYULCTaskAuditInfo()
	{
		guidTask        = GUID_NULL; 
		guidAudit       = GUID_NULL;
		strAuditorName  = _T("");
		nAuditLeve      = 0;
		nAuditRet       = 0;
		strAuditInfo    = _T("");
		odtAuditTime.SetDateTime(1900,1,1,0,0,0);					
	};

	SDYULCTaskAuditInfo(const SDYULCTaskAuditInfo &other)
	{
		*this = other;
	};

	SDYULCTaskAuditInfo& operator = (const SDYULCTaskAuditInfo& other)
	{
		guidTask        = other.guidTask; 
		guidAudit       = other.guidAudit;
		strAuditorName  = other.strAuditorName;
		nAuditLeve      = other.nAuditLeve;
		nAuditRet       = other.nAuditRet;
		strAuditInfo    = other.strAuditInfo;
		odtAuditTime    = other.odtAuditTime;

		return *this;
	};
};
typedef CArray<SDYULCTaskAuditInfo, SDYULCTaskAuditInfo&> ASDYULCTaskAuditInfoArray;

//TRAP消息类型
enum  DYULC_TASK_TRAPTYPE
{
	DYULCTASK_TRAPTYPE_UNKNOWN			=	0,			//未知类型
	DYULCTASK_TRAPTYPE_USERCHANGESTATUS	=	1,			//用户登陆/注销信息
	DYULCTASK_TRAPTYPE_TASKFAILURE		=	2,			//任务失败信息
	DYULCTASK_TRAPTYPE_SERVICEEXCEPTION	=	3,			//服务异常信息
	DYULCTASK_TRAPTYPE_DEVICEEXCEPTION	=	4,			//设备异常信息
};

//TRAP消息信息
struct SDYULCTaskTrapInfo
{
	DY_GUID					guidTrap;		//TrapGUID
	DYULC_TASK_TRAPTYPE		enumTrapType;	//Trap类型
	CString					strTrapContent;	//Trap内容
	COleDateTime			odtCreateTime;	//生成时间

	SDYULCTaskTrapInfo()
	{
		guidTrap = GUID_NULL;
		enumTrapType = DYULCTASK_TRAPTYPE_UNKNOWN;
		strTrapContent = _T("");
		odtCreateTime   = COleDateTime::GetCurrentTime();
	};

	SDYULCTaskTrapInfo(const SDYULCTaskTrapInfo &other)
	{
		*this = other;
	};

	~SDYULCTaskTrapInfo()
	{
	};

	SDYULCTaskTrapInfo& operator = (const SDYULCTaskTrapInfo& other)
	{
		guidTrap = other.guidTrap;
		enumTrapType = other.enumTrapType;
		strTrapContent = other.strTrapContent;
		odtCreateTime   = other.odtCreateTime;

		return *this;
	};
};
typedef CArray<SDYULCTaskTrapInfo, SDYULCTaskTrapInfo&> ASDYULCTaskTrapInfoArray;

struct SDYULCPrintGridItemInfo
{
	CString strName;//标题
	int		nOldPos;//固定位置//不变
	int		nNewPos;//个人调整后的位置
	int		nWidth;//个人调整后的宽
};
typedef CArray<SDYULCPrintGridItemInfo, SDYULCPrintGridItemInfo> ASDYULCPrintGridItemInfoArray;

//节目单的数据结构
struct SDYULCProgramInfo
{
	DY_GUID			guidProgram;			//节目guid
	CString			strProgramName;			//节目名称
	CString			strHint;				//备注
	DY_GUID			guidSignalSource;		//信号源
	CString			strSignalName;			//信号源名称
	COleDateTime	odtStartTime;			//开始时间
	COleDateTime	odtStopTime;			//结束时间
	DY_GUID			guidSubject;			//主题guid
	CString			strSubject;				//主题名称
	CString			strColumn;				//栏目名称
	BOOL			bImportant;				//重点节目

	BOOL			bBespeak;				//是否被预约
	DY_GUID			guidPreTask;			//对应的预约任务guid
	DY_GUID			guidRealTask;			//对应的实际任务的guid
	int				nBespeakTime;			//预约的次数
	CDYGuidArray		asBespeakUserGuid;		//预约过的用户ID(预约过的就不能再次预约了)
	CStringArray	asBespeakUserName;		//预约过的用户名称
	CStringArray	asBespeakUserColumn;	//预约过的用户栏目

	SDYULCProgramInfo()
	{
		guidProgram = GUID_NULL;
		guidSignalSource = GUID_NULL;
		odtStartTime = COleDateTime::GetCurrentTime();
		odtStopTime = COleDateTime::GetCurrentTime();
		guidSubject = GUID_NULL;
		bImportant = FALSE;

		bBespeak = FALSE;
		guidPreTask = GUID_NULL;
		guidRealTask = GUID_NULL;
		nBespeakTime = 0;
	};

	SDYULCProgramInfo(const SDYULCProgramInfo& other)
	{
		*this = other;
	};

	SDYULCProgramInfo& operator= (const SDYULCProgramInfo& other)
	{
		guidProgram = other.guidProgram;
		strProgramName = other.strProgramName;
		strHint = other.strHint;
		guidSignalSource = other.guidSignalSource;
		strSignalName = other.strSignalName;
		odtStartTime = other.odtStartTime;
		odtStopTime = other.odtStopTime;
		guidSubject = other.guidSubject;
		strSubject = other.strSubject;
		strColumn = other.strColumn;
		bImportant = other.bImportant;

		bBespeak = other.bBespeak;
		guidPreTask = other.guidPreTask;
		guidRealTask = other.guidRealTask;
		nBespeakTime = other.nBespeakTime;
		asBespeakUserGuid.Copy(other.asBespeakUserGuid);
		asBespeakUserName.Copy(other.asBespeakUserName);
		asBespeakUserColumn.Copy(other.asBespeakUserColumn);

		return *this;
	};
};
typedef CArray<SDYULCProgramInfo , SDYULCProgramInfo&> ASDYULCProgramInfoArray;

//收录任务对应的预约节目单信息

//上传任务的表结构
enum DYULC_UPLOADTASK_STATE
{
	DYULC_UPLOADTASKSTATE_UNKNOWN	= 0,
	DYULC_UPLOADTASKSTATE_WAITING	= 1,	//任务已保存，等待执行
	DYULC_UPLOADTASKSTATE_RUNNING	= 2,	//正在执行
	DYULC_UPLOADTASKSTATE_FINISH	= 3,	//完成
	DYULC_UPLOADTASKSTATE_ERROR		= 4,	//失败
};

struct SDYULUploadTaskInfo
{
	DY_GUID guidUploadTask;	//任务guid
	CString strTaskName;	//任务名称
	CString strHint;		//描述
	CStringArray	asUploadFileName;		//上传的文件名数组
	CStringArray	asKeyWord;				//关键字
	CString			strSenderID;			//发送者ID
	CString         strSenderName;           //发送者名称	
	CString			strOwnerID;				//拥有者ID(接受)
	CString         strOwnerName;           //拥有者	
	COleDateTime	odtCreateTime;			//任务创建时间
	CString			strSubject;				//主题名称
	DY_GUID			guidSubject;			//主题DY_GUID
	DYULC_UPLOADTASK_STATE		enumRunStatus;	//运行状态
	DY_GUID			guidClip;				//对应素材DY_GUID

	SDYULUploadTaskInfo()
	{
		guidUploadTask = GUID_NULL;
		odtCreateTime = COleDateTime::GetCurrentTime();
		guidSubject = GUID_NULL;
		enumRunStatus = DYULC_UPLOADTASKSTATE_UNKNOWN;
		guidClip = GUID_NULL;
	}

	SDYULUploadTaskInfo(const SDYULUploadTaskInfo& other)
	{
		*this = other;
	}

	SDYULUploadTaskInfo& operator = (const SDYULUploadTaskInfo& other)
	{
		guidUploadTask = other.guidUploadTask;
		strTaskName = other.strTaskName;
		strHint = other.strHint;
		asUploadFileName.Copy(other.asUploadFileName);
		asKeyWord.Copy(other.asKeyWord);
		strSenderID = other.strSenderID;
		strSenderName = other.strSenderName;
		strOwnerID = other.strOwnerID;
		strOwnerName = other.strOwnerName;
		odtCreateTime = other.odtCreateTime;
		strSubject = other.strSubject;
		guidSubject = other.guidSubject;
		enumRunStatus = other.enumRunStatus;
		guidClip = other.guidClip;

		return *this;
	}
};

typedef CArray<SDYULUploadTaskInfo , SDYULUploadTaskInfo&> ASDYULUploadTaskInfoArray;

//任务需迁移条目结构
struct SDYULCTaskTransInfo
{
	DY_GUID						guidTask;                //任务DY_GUID
	CString                     strTaskName;             //任务名称
	COleDateTime                odtFinishRecTime;        //任务结束时间
	int                         nTransDelayTime;         //迁移延迟时间
	int                         nTransState;             //迁移状态，0尚未迁移，1已开始迁移
	
	SDYULCTaskTransInfo()
	{
		guidTask        = GUID_NULL;  
		strTaskName     = _T("");
		odtFinishRecTime.SetDateTime(1900,1,1,0,0,0);
		nTransDelayTime = 0;
		nTransState     = 0;				
	};

	SDYULCTaskTransInfo(const SDYULCTaskTransInfo &other)
	{
		*this = other;
	};

	SDYULCTaskTransInfo& operator = (const SDYULCTaskTransInfo& other)
	{
		guidTask         = other.guidTask;  
		strTaskName      = other.strTaskName;
		odtFinishRecTime = other.odtFinishRecTime;
		nTransDelayTime  = other.nTransDelayTime;
		nTransState      = other.nTransState;

		return *this;
	};
};
typedef CArray<SDYULCTaskTransInfo, SDYULCTaskTransInfo&> ASDYULCTaskTransInfoArray;

//需要从存在的任务中分割一段素材给预约的任务
struct SDYULCTaskOrderCutInfo
{
	DY_GUID						guidCutTask;                //任务DY_GUID
	CString                     strTaskName;				//任务名称
	
	DY_GUID						guidSignal;					//信号
	CString						strSignalName;				//信号名称

	CString						strOwnerID;				//拥有者ID
	CString                     strOwnerName;           //拥有者	

	CString						strColumnName;			//拥有者栏目

	COleDateTime				odtTaskStartDate;		//开始时间
	COleDateTime				odtTaskStopDate;		//结束时间
	DWORD                       dwDuration;				//长度，以帧为单位

	DYULC_TASK_RUNSTATUS		enumRunStatus;          //任务运行状态

	DY_GUID						guidCorrespondOrderTask;			//对应的预约任务的guid
	DY_GUID						guidCutUseTask;			//从实际任务切分的那个任务的guid

	DY_GUID						guidClip;				//切分生成的素材的guid

	SDYULCTaskOrderCutInfo()
	{
		guidCutTask		= GUID_NULL;  
		strTaskName		= _T("");
		guidSignal		= GUID_NULL;

		odtTaskStartDate = COleDateTime::GetCurrentTime();
		odtTaskStopDate = COleDateTime::GetCurrentTime();
		dwDuration     = 0;

		enumRunStatus = DYULCTASK_RUNSTATUS_WAITING;

		guidCorrespondOrderTask = GUID_NULL;
		guidCutUseTask = GUID_NULL;
		guidClip = GUID_NULL;
	};

	SDYULCTaskOrderCutInfo(const SDYULCTaskOrderCutInfo &other)
	{
		*this = other;
	};

	SDYULCTaskOrderCutInfo& operator = (const SDYULCTaskOrderCutInfo& other)
	{
		guidCutTask		= other.guidCutTask;  
		strTaskName		= other.strTaskName;

		guidSignal		= other.guidSignal;
		strSignalName  = other.strSignalName;

		strOwnerID      = other.strOwnerID;
		strOwnerName      = other.strOwnerName;

		strColumnName	= other.strColumnName;

		odtTaskStartDate      = other.odtTaskStartDate;
		odtTaskStopDate      = other.odtTaskStopDate;
		dwDuration      = other.dwDuration;

		enumRunStatus      = other.enumRunStatus;
		guidCorrespondOrderTask      = other.guidCorrespondOrderTask;
		guidCutUseTask      = other.guidCutUseTask;
		guidClip		= other.guidClip;

		return *this;
	};
};
typedef CArray<SDYULCTaskOrderCutInfo, SDYULCTaskOrderCutInfo&> ASDYULCTaskOrderCutInfoArray;

//任务编排时间段结构
struct SArrangeTimePart
{
	DY_GUID	guidTimePart;			//时段ID
	CString strTimePartName;		//时段名
	CString strTimePartHint;		//时段备注
	COleDateTime	odtFromTime;	//开始时间
	COleDateTime	odtToTime;		//结束时间
	int				nShowIndex;		//显示顺序

	SArrangeTimePart()
	{
		guidTimePart = GUID_NULL;
		odtFromTime = odtToTime = COleDateTime::GetCurrentTime();
		nShowIndex = 0;
	}

	~SArrangeTimePart() {}

	SArrangeTimePart(const SArrangeTimePart& other)
	{
		*this = other;
	}

	SArrangeTimePart& operator = (const SArrangeTimePart& other)
	{
		guidTimePart = other.guidTimePart;
		strTimePartName = other.strTimePartName;
		strTimePartHint = other.strTimePartHint;
		odtFromTime = other.odtFromTime;
		odtToTime = other.odtToTime;
		nShowIndex = other.nShowIndex;

		return *this;
	}
};

typedef CArray<SArrangeTimePart , SArrangeTimePart&> ASArrangeTimePartArray;

//短信通知类型
enum DYULC_TASK_CHANGENOTIFYTYPE
{ 
	DYULCTASK_CHANGENOTIFY_UNKOWN			    =	0,
	DYULCTASK_CHANGENOTIFY_ARRANGEPASS		    =	1,	       //任务编排通过
	DYULCTASK_CHANGENOTIFY_ARRANGERETURN	    =	2,	       //任务编排退回
	DYULCTASK_CHANGENOTIFY_RECFINISH		    =	3,	       //采集完成
	DYULCTASK_CHANGENOTIFY_NEWSUPLOADFINISH		=	4,		   //领用稿件上传完毕
	DYULCTASK_CHANGENOTIFY_NEWSRECFINISH		=	5,		   //领用稿件采集完毕
};

//向任务提交人发送短信通知
struct SDYULCTaskWorkStateChangeNotify
{
	DY_GUID			guidNotify;		//通知的DY_GUID
	CString			strTaskName;	//任务名称
	DY_GUID			guidTaskID;		//收录任务DY_GUID
	COleDateTime	odtNotifyTime;	//通知创建时间
	DYULC_TASK_CHANGENOTIFYTYPE		enumNotifyType;		//通知类型
	BOOL			bSendNotify;	//是否已发送

	//预约关联信息
	BOOL						bFromProgram;			//来自于节目单
	DY_GUID						guidProgram;			//对应的节目单guid
	int							nBespeakTime;			//预约次数
	CStringArray				asBespeakUserName;		//预约过的用户名称
	CStringArray				asBespeakUserColumn;	//预约过的用户栏目

	SDYULCTaskWorkStateChangeNotify()
	{
		guidNotify = GUID_NULL;
		guidTaskID = GUID_NULL;
		odtNotifyTime = COleDateTime::GetCurrentTime();
		enumNotifyType = DYULCTASK_CHANGENOTIFY_UNKOWN;
		bSendNotify = FALSE;

		bFromProgram = FALSE;
		guidProgram = GUID_NULL;
		nBespeakTime = 0;
	}

	~SDYULCTaskWorkStateChangeNotify() {}

	SDYULCTaskWorkStateChangeNotify(const SDYULCTaskWorkStateChangeNotify& other)
	{
		*this = other;
	}

	SDYULCTaskWorkStateChangeNotify& operator = (const SDYULCTaskWorkStateChangeNotify& other)
	{
		guidNotify = other.guidNotify;
		strTaskName = other.strTaskName;
		guidTaskID = other.guidTaskID;
		odtNotifyTime = other.odtNotifyTime;
		enumNotifyType = other.enumNotifyType;
		bSendNotify = other.bSendNotify;

		bFromProgram = other.bFromProgram;
		guidProgram = other.guidProgram;
		nBespeakTime = other.nBespeakTime;
		asBespeakUserName.Copy(other.asBespeakUserName);
		asBespeakUserColumn.Copy(other.asBespeakUserColumn);

		return *this;
	}
};
typedef CArray<SDYULCTaskWorkStateChangeNotify , SDYULCTaskWorkStateChangeNotify&> ASDYULCTaskWorkStateChangeNotifyArray;

//任务分类信息
struct SDYULCTaskClassInfo
{
	DY_GUID		  guidID;                //任务分类guid
	CString		  strName;               //任务分类名称
	CString		  strCFName;             //任务分类唯一名称（全大写）
	CString		  strHint;               //任务分类的描述
	CStringArray  astrPlgInNameArr;      //分类中包含的前插件名称
	CDYGuidArray  asguidPlugInArr;       //分类中包含的前插件DY_GUID
	CStringArray  astrBPlgInNameArr;     //分类中包含的后插件名称
	CDYGuidArray  asBguidPlugInArr;      //分类中包含的后插件DY_GUID

	int           nPlugType;             //插件类型 前插件0，后插件1

	ASDYULCPlugInTypeInfoArray asPlugInTypeInfoArr;

	int           iReserve;
	CString       strReserve;     

	SDYULCTaskClassInfo()
	{
		guidID    = GUID_NULL;
		strName   = _T("");
		strCFName = _T("");
		strHint   = _T("");
		astrPlgInNameArr.RemoveAll();
		asguidPlugInArr.RemoveAll();
		astrBPlgInNameArr.RemoveAll();
		asBguidPlugInArr.RemoveAll();
		asPlugInTypeInfoArr.RemoveAll();
		nPlugType = 0;
		iReserve = 0;
        strReserve = _T("");
	};

	SDYULCTaskClassInfo(const SDYULCTaskClassInfo &other)
	{
		*this = other;
	};

	~SDYULCTaskClassInfo()
	{
		astrPlgInNameArr.RemoveAll();
		asguidPlugInArr.RemoveAll();
		astrBPlgInNameArr.RemoveAll();
		asBguidPlugInArr.RemoveAll();
		asPlugInTypeInfoArr.RemoveAll();
	};

	SDYULCTaskClassInfo& operator = (const SDYULCTaskClassInfo& other)
	{
		guidID              = other.guidID;
		strName             = other.strName;
		strCFName           = other.strCFName;
		strHint             = other.strHint;
		astrPlgInNameArr.Copy(other.astrPlgInNameArr);
		asguidPlugInArr.Copy(other.asguidPlugInArr);
		astrBPlgInNameArr.Copy(other.astrBPlgInNameArr);
		asBguidPlugInArr.Copy(other.asBguidPlugInArr);
		nPlugType           = other.nPlugType;

		asPlugInTypeInfoArr.Copy(other.asPlugInTypeInfoArr);
		iReserve = other.iReserve;
        strReserve = other.strReserve;

		return *this;
	};
};
typedef CArray<SDYULCTaskClassInfo, SDYULCTaskClassInfo&> ASDYULCTaskClassInfoArray;

//////////////////////////////////////////////////////////////////////////////
//收录相关操作流程信息
//以下为DYULCOperateFlow表结构
typedef struct tagDYULCOperateFlow
{
	CString  strIndexGuid;//索引DY_GUID(KEY)
	int		 iLinkType;//关联类型  值参看 DYULC_LINKTYPE
	CString  strLinkGuid;//关联guid
	int      iOrderNum;//序号
	CString  strUsePerson;//操作人
	COleDateTime  odtUseTime;//操作时间
	CString  strUseRemark;//操作备注
	int      iUseState;//操作方式
	CString  strUseState;//操作方式名称
	CString  strFlowContent;//此操作相关信息 比如审核
	tagDYULCOperateFlow()
	{
		strIndexGuid  =  DYCoCreateGuidString();
		iLinkType	= 0;
		iOrderNum	= 0;
		odtUseTime = COleDateTime::GetCurrentTime();
		iUseState	= 0;
	}
	~tagDYULCOperateFlow()
	{
	}
} SDYULCOperateFlow,*PSDYULCOperateFlow;
typedef CArray<SDYULCOperateFlow, SDYULCOperateFlow&> SDYULCOperateFlow_ARR;
//
//以上为DYULCOperateFlow表结构
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//系统设置表
//以下为DYULCSystemConfig表结构
typedef struct tagDYULCSystemConfig
{
	CString  strConfigGuid;//配置DY_GUID
	CString  strConfigName;//配置名称
	int      enumConfigType;//配置类型    DYULC_SYSTEMCONFIG_TYPE
	int      iOrderNum;//次序
	CString  strConfigValue;//值
	CString	 strPreceptName;	//方案名称
	BOOL     bDefault;          //是否为缺省
	tagDYULCSystemConfig()
	{
		strConfigGuid  =  DYCoCreateGuidString();
		strConfigName = _T("");
		enumConfigType	= 0;
		iOrderNum	= 0;
		strConfigValue = _T("");
		strPreceptName = _T("");
		bDefault = FALSE;
	}
	~tagDYULCSystemConfig()
	{
	}
} SDYULCSystemConfig,*PSDYULCSystemConfig;
typedef CArray<SDYULCSystemConfig, SDYULCSystemConfig&> SDYULCSystemConfig_ARR;
//
//以上为DYULCSystemConfig表结构
//////////////////////////////////////////////////////////////////////////////
enum  DYULC_TASK_LIFECYCLETYPE
{
	DYULC_TASK_LIFECYCLE_GEN	        = 0,
	DYULC_TASK_LIFECYCLE_COLOMN 		= 1,
	DYULC_TASK_LIFECYCLE_SIGNAL 		= 2,
	DYULC_TASK_LIFECYCLE_TASK   		= 3,   
};

typedef struct SDYLifeCycleInfo
{
public:
    DYULC_TASK_LIFECYCLETYPE enumType;
	int   iLevel;
	DY_GUID  guidItem;
	CString strItemName;
	int   iLife1;
	int   iLife2;
	int   iLife3;
	int   iLife4;
public:
	SDYLifeCycleInfo()
	{
        enumType = DYULC_TASK_LIFECYCLE_GEN;
	    iLevel = 1;
	    guidItem = GUID_NULL;
	    strItemName = _T("");
	    iLife1 = 30;
	    iLife2 = 30;	
	    iLife3 = 30;
		iLife4 = 30;
	};
	
	SDYLifeCycleInfo(const SDYLifeCycleInfo &other)
	{
		*this = other;
	};

	virtual SDYLifeCycleInfo& operator = (const SDYLifeCycleInfo& other)
	{
		enumType = other.enumType;
		iLevel = other.iLevel;
	    guidItem = other.guidItem;
	    strItemName = other.strItemName;
	    iLife1 = other.iLife1;
	    iLife2 = other.iLife2;	
	    iLife3 = other.iLife3;
        iLife4 = other.iLife4;
		return *this;
	};	
};

typedef CArray<SDYLifeCycleInfo,SDYLifeCycleInfo&> ASDYLifeCycleInfoArray ;
#endif // !defined(__H__DYULCTaskDef__H__)
