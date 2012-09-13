///////////////////////////////////////////////////////////////////////////////////
//DYULCCommonDefine.h

//���ļ����ڶ������¼ϵͳ�������õ����ݿ�ṹ
///////////////////////////////////////////////////////////////////////////////////

#if !defined( __H__DYULCCommonDefine__H__ )
#define __H__DYULCCommonDefine__H__

#include "\Dayang\Include\DYE_CommonDefine.h"
#include "\dayang\dyrsoftwaresdk\dayangresearch\include\dyr_dmc\dyr_dmc_codeccommondefine.h"
//#include "\Dayang\Include\DYCommonVADefine.h"

struct SDYULCHeadInfo
{
	CString 	strColumnName;              //������
	int		    nColumnIndex;               //�����
	int		    nColumnWidth;               //�п��

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

//ʵ���������ɷ�ʽ
enum  DYULC_TASK_CREATETYPE
{
	DYULCDEVICE_TASKCREATE_UNKNOWN		= 0,   
	DYULCDEVICE_TASKCREATE_ATCREATE		= 1,	//һ���ԤԼ��������ɶ�Ӧ��ʵ������
	DYULCDEVICE_TASKCREATE_ATAUDIT		= 2,	//�������Ժ�����ԤԼ�����Ӧ��ʵ������
};

//��¼���ĵ��������
struct SDYULCParamInfo
{
	BOOL	                    IfVASplite;                          //VA�Ƿ����
	BOOL					    IfResetToWait;                       //�Ƿ�����Ϊ��ִ��

	BOOL					    IfLinkMsgServer;                     //�Ƿ�������Ϣ������
	int                         masterskport;                        //������������ͨ��                      
	int                         backupskport;                        //���������ӱ�ͨ��
	CString                     masterskip;                          //������������IP
	CString                     backupskip;                          //���������ӱ�IP

	CString                     strLogPath;                          //��־·��,����·��

	BOOL                        bIfNeedpreAllocate;                  //�Ƿ���ҪԤ����
    int                         nPreAllocateTime;                    //Ԥ������ǰʱ�䣬�Է���Ϊ��λ

	int                         nPreLockTime;                        //��ǰ�������൱ǰʱ����ٲ�׼�����������

	BOOL                        bNeedLocalToNet;                     //�Ƿ�����ȱ����������ģʽ�ɼ�
	BOOL                        bNeedCapCompile;                     //�Ƿ������ǲ��ñ߲ɱ߱�ķ�ʽ
	BOOL                        bNeedInpect;                         //�Ƿ���Ҫ����
	BOOL                        bNeedCapTrans;                       //�Ƿ�߲ɼ��ߴ���

	BOOL                        bIfCapSeg;                           //�Ƿ�ֶβɼ�
	int                         nCapSegTime;                         //�ֶβɼ�ʱ�䣬��
	
	int                         nTransDelayTime;                     //Ǩ���ӳ�ʱ�䣬�Է���Ϊ��λ

	DYULC_TASK_CREATETYPE		enumTaskCreateType;					//ʵ���������ɵķ�ʽ
	int							nArrangeLimitMinute;				//��������ʱ�䷧ֵ��С�ھͲ����޸�

	BOOL						bCreatePreTaskInfo;					//�������ʱ�����ɺ�ʵ�������Ӧ��ԤԼ����
	int							nCutDelayMin;						//����¼�������һ�������زģ��ӳ��ķ���

	BOOL                        bIfLimitTaskNum;                    //�Ƿ�������������
	int                         nLimitTaskNum;                      //������������
    BOOL                        bIfUseWorkFlow;                      //�Ƿ�ʹ�ù��������

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

//�豸ͨ������
enum  DYULC_DEVICE_PORTDIR
{
	DYULCDEVICE_PORTDIR_UNKNOWN				= 0,   
	DYULCDEVICE_PORTDIR_IN					= 1,	//����ͨ��
	DYULCDEVICE_PORTDIR_OUT					= 2,	//���ͨ��	
};

//�豸ͨ������״̬
enum  DYULC_DEVICE_PORTSTATUS
{
	DYULDEVICE_PORTSTATUS_FREE              = 0X00000000,   //����
	DYULDEVICE_PORTSTATUS_LOCK              = 0X00000001,   //����
	DYULDEVICE_PORTSTATUS_PRELOCK           = 0X00000002,   //Ԥ��������
	DYULDEVICE_PORTSTATUS_HANDLELOCK        = 0X00000003,   //�ֶ�����
};

//�ź�ͨ���ź�����,�������ͨ�����Ʒ�ʽ
typedef DWORD DYULCPORTPROPERTYFLAG;
// �豸(�ź�)ͨ������
enum  DYULC_DEVICE_PORTTYPE
{
	DYULCDEVICE_PORTTYPE_UNKNOWN			= 0x00000000,

	DYULCDEVICE_PORTTYPE_V					= 0x00000001,	//Video ����ͨ��
	DYULCDEVICE_PORTTYPE_A					= 0x00000002,	//Audio ����ͨ��
	DYULCDEVICE_PORTTYPE_VA					= 0x00000004,	//VA SDI ����ͨ��
	DYULCDEVICE_PORTTYPE_TS					= 0x00000008,	//VA TS ����ͨ��
	DYULCDEVICE_PORTTYPE_SDTI				= 0x00000010,	//VA SDTI ����ͨ��
	DYULCDEVICE_PORTTYPE_SDTI_CP			= 0x00000020,	//VA SDTI CP ����ͨ��
	DYULCDEVICE_PORTTYPE_1394_25M			= 0x00000040,	//VA 1394-DV25 �������ͨ��
	DYULCDEVICE_PORTTYPE_1394_50M			= 0x00000080,	//VA 1394-DV50 �������ͨ��
	DYULCDEVICE_PORTTYPE_UDP			    = 0x00000100,	//UDP����ͨ��

	DYULCDEVICE_PORTTYPE_CTRL_232			= 0x10000000,	//ͨ��232���������ͨ��
	DYULCDEVICE_PORTTYPE_CTRL_422			= 0x20000000,	//ͨ��422���������ͨ��
	DYULCDEVICE_PORTTYPE_CTRL_Socket		= 0x40000000,	//ͨ��Socket���������ͨ��
};

//�豸����
enum DYULC_DEVICE_TYPE
{
	DYULC_DEVICE_UNKOWN						=	0,	//δ֪�豸
	DYULC_DEVICE_VTR						=	1,	//VTR
	DYULC_DEVICE_SATREVEIVER				=	2,	//���ǽ��ջ�
	DYULC_DEVICE_UPLOAD						=	3,	//�ɼ�����վ
	DYULC_DEVICE_VIDEOSERVER				=	4,	//��Ƶ������
	DYULC_DEVICE_MATRIX_VA					=	5,	//����Ƶ����
	DYULC_DEVICE_MATRIX_CTRL				=	6,	//���ƾ���
	DYULC_DEVICE_BYPASSSIGNAL				=	7,	//By Pass Signal
	DYULC_DEVICE_MANAGER					=	8,	//Manager
	DYULC_DEVICE_PC_CTRL					=	9,	//PC(VDCP or 422)Ctrl Server or VTR
	DYULC_DEVICE_XEDIT					    =	10,	//�Ǳ๤��վ
	DYULC_DEVICE_MEDIAGATEWAY               =   11, //ý������
	DYULC_DEVICE_DECODER                    =   12, //������
	DYULC_DEVICE_ENCODER                    =   13, //������
	DYULC_DEVICE_SATSIGPROCESSOR            =   14, //�����źŽ���豸
	DYULC_DEVICE_ADEMBED                    =   15, //A/DǶ���豸����ģ���������
	DYULC_DEVICE_ADOUTBED                   =   16, //A/D����豸
	DYULC_DEVICE_TVDECODER                  =   17, //���ӽ����
	DYULC_DEVICE_DIGITALSIGPROCESSER        =   18, //�����ź����������豸
	DYULC_DEVICE_DIGITALSIGSHOWER           =   19, //�����źŷָ���ʾ��
	DYULC_DEVICE_SIGPLAYER                  =   20, //�źŲ����豸
	DYULC_DEVICE_MACHINETOP                 =   21, //������
	DYULC_DEVICE_MACHINEPERIPHERAL          =   22, //�ⲿ�ɼ������豸������DY3000��
	DYULC_DEVICE_CHANGEVIDEOSTANDARD        =   23, //��ת�豸
	DYULC_DEVICE_VIDEOSPLITTERDEVICE        =   24, //�ӷ��豸
	DYULC_DEVICE_MONITOR	                =   25, //��ز��� 
	DYULC_DEVICE_PHEDEVICEMANAGER		    =	26,	//�ⲿ�ɼ��豸���Ƶ��豸
    DYULC_DEVICE_PHEDEVICE  				=	27,	//�ⲿ�ɼ��豸
	DYULC_DEVICE_RESERVED3                  =   28, //�����ֶ�
	DYULC_DEVICE_RESERVED4                  =   29, //�����ֶ�                 
	DYULC_DEVICE_RESERVED5                  =   30, //�����ֶ�
};

enum  DYULC_UDP_PACKTYPE
{
	DYULC_UDP_NO                            = 0x00000000,   //������
	DYULC_UDP_TS			                = 0x00000001,   //һ��TS��װ
	DYULC_UDP_TSMPEG2                       = 0x00000002,   //MPEG2��װ��TS
	DYULC_UDP_PS                            = 0x00000004,   //һ��PS��װ
	DYULC_UDP_PSMPEG2                       = 0x00000008,   //MPEG2��װ��PS
	DYULC_UDP_H264                          = 0x00000010,   //һ��H264��װ

	DYULC_UDP_HDTS			                = 0x00000020,   //����TS��װ
	DYULC_UDP_HDPS                          = 0x00000040,   //����PS��װ
	DYULC_UDP_HDH264                        = 0x00000080,   //����H264��װ
    
	DYULC_UDP_RTSP	                        = 0x00000100,   //rtsp
    DYULC_UDP_HTTP	                        = 0x00000200,   //http
	DYULC_UDP_RTP	                        = 0x00000400,   //RTP
    DYULC_UDP_OTHER	                        = 0x00000800,   //����

	DYULC_UDP_UNICAST                       = 0x10000000,   //����ģʽ
};

//��ͬUDPռ��ͨ������
struct SDYULCUDPPackPortSet
{
	int     nTsSetPort;             //һ��TS
	int     nTSMpeg2Port;           //MPEG2TS
	int     nPsPort;                //һ��PS
	int     nPSMpeg2Port;           //MPEG2PS
	int     nH264Port;              //һ��H264

	int     nHDTSPort;              //����TS
	int     nHDPSPort;              //����PS
	int     nHDH264Port;            //����H264

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

// �ź�Դ��
struct SDYULCSignalSourceGroupInfo
{
	DY_GUID		guidGroupID;				//�ź���DY_GUID
	CString		strGroupName;				//�ź�������
	CString		strGroupHint;				//�ź�������

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

// �ź�Դ��Ϣ
struct SDYULCSignalSourceInfo
{
	DY_GUID					guidID;                       //�ź�ԴDY_GUID
	CString					strName;                      //�ź�Դ����
	DY_GUID					guidGroupID;				  //�ź�Դ��DY_GUID
	CString					strGroupName;                 //�ź�Դ������
	CString					strHint;                      //�ź�Դ����

	CString                 strZBAddress;                 //������ַ
	CString                 strZBPort;                    //�����˿�

	BOOL					bIfPassSatelliteViewer;       //�Ƿ�ֱͨ�ź�
	DYULC_DEVICE_PORTTYPE	enumPortType;                 //�ź�ͨ������
	CString					strFreqCtrlInfo;			  //�ź�Ƶ�������Ϣ
	CString					strProgCtrlInfo;			  //�źŽ�Ŀ������Ϣ

	int                     nPrerollSec;                  //�ź���¼��ǰʱ��    ��EPG�൥ʱʹ��
	int                     nLastSec;                     //�ź���¼�Ӻ�ʱ��    ��EPG�൥ʱʹ��
	CString                 strEpgServiceID;              //�źŵ� Service ID   ��EPG�൥ʱʹ��

	BOOL                    bPassGateWay;                 //�Ƿ��ý������


	BOOL                    bPassLMatrix;                 //�Ƿ����Ƶ����
	CString                 strInterFreSig;               //��Ƶ����  //Satellite Freq. ��������ʵ��TT���ǽ��ջ��Ĳ���
	CString                 strInterFreRate;              //��ƵƵ��  //LNC Freq.
	CString                 strFreRate;                   //������    //Symbol Rate
	CString                 strForwardErr;                //ǰ�����  //Inner Code
	CString                 strServiceID;                 //ServiceID
	CString                 strLNCVoltage;                //LNC Voltage
	CString                 strChannelParam;              //ͨ������
	CString                 strSatOtherParam;             //�����Ĳ���    

	BOOL                    bPassTVEncoder;               //�Ƿ�����ӽ����
	CString                 strChannelIndex;              //Ƶ����

	BOOL                    bNeedDigitalAdj;              //�Ƿ���Ҫ���ֵ���
	CString                 strDigiAdjParam1;             //���ֵ�������1
	CString                 strDigiAdjParam2;             //���ֵ�������2
	CString                 strDigiAdjParam3;             //���ֵ�������3

	BOOL                    bNeedAnalogAdj;               //�Ƿ���Ҫģ�����
	CString                 strAnagadjParam1;             //ģ���������1
	CString                 strAnagadjParam2;             //ģ���������2
	CString                 strAnagadjParam3;             //ģ���������3

	BOOL                    bTestCardSig;                 //�Ƿ�Ϊ�����ź�
	BOOL                    bColorBandSig;                //�Ƿ�Ϊ�����ź�

	BOOL                    bIfZemu;                      //�Ƿ���Ҫ��Ļ
    DWORD				    dwZemuSizeInByte;			  //��Ļ���ݴ�С
	PBYTE					pbZemuData;			          //��Ļ����

	BOOL                    bIfHavePriority;              //�Ƿ������ȼ�����
	int                     nPriority;                    //���ȼ�

	BOOL                    bIfHaveError;                 //�ź������Ƿ�������	

	BOOL                    bIsHD;                        //�Ƿ�Ϊ�����ź�

	DYULC_UDP_PACKTYPE      enumUDPPackType;              //UDP��װ��ʽ

	BOOL					bKeepRecord;				//�����ɼ����ź�

	DYVIDEO_SCALE_TYPE	iVideoUpScaleType;		//���壬�����ϱ任��ʽ
	DYVIDEO_SCALE_TYPE	iVideoDownScaleType;	//���壬�����±任��ʽ

	CString             strAddtion;             //������Ϣ	

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

// �Ŵ�������
struct SDYULCVTRTapeTypeGroupInfo
{
	DY_GUID		guidGroupID;                //�Ŵ�������DY_GUID
	CString		strGroupName;               //�Ŵ�����������
	CString		strGroupHint;               //�Ŵ�����������

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

//�Ŵ�����
struct SDYULCVTRTapeTypeInfo
{
	DY_GUID		guidID;                //�Ŵ�����DY_GUID
	CString		strName;               //�Ŵ���������
	CString		strHint;               //�Ŵ���������
	DY_GUID		guidGroupID;		   //�Ŵ�������DY_GUID
	CString     strGroupName;          //�Ŵ�������
	int         nMaxLength;            //�Ŵ�����֧�ֵ���󳤶� 
	BOOL        bIfDefault;            //�Ƿ�ΪĬ�ϴŴ�����

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

//�ز��࣬��ʶ�ز�����Ƶ���ͼ������ļ��Ĵ���״��
typedef	DWORD DYULCCLIPCLASSFLAG;
enum	DYULCCLIP_CLASS
{
	DYULCCLIP_CLASS_Unknow		=	0x00000000,		//	������
	DYULCCLIP_CLASS_V			=	0x00000001,		//	��Ƶ
	DYULCCLIP_CLASS_A			=	0x00000002,		//	��Ƶ
	DYULCCLIP_CLASS_VA			=	0x00000003,		//	����Ƶ
};

//����Ŀ���ز�����Ƶ��ʽ��Ϣ
struct SDYULClipElementInfo
{
	DY_GUID                 guidID;                     //��ʽDY_GUID
	CString					strName;                    //��ʽ����
	CString					strGroupName;			    //���ڸ�ʽ������

	DYULCCLIP_CLASS			enumClass;                  //�ز�����Ƶ����
	DY_VIDEO_STANDARD		enumVideoStandard;			//��Ƶ��׼
	DY_STREAM_TYPE    	    enumSpecialMediaType;		//����Ƶ������ʽ����
	DWORD					dwPropertyFlag;				//�ر��־ see DYCLIPELEMENTPROPERTYFLAG_???

	DY_GUID                 guidGroupID;                //���ڸ�ʽ��DY_GUID
	SDYStreamMediaInfo		sStreamMediaInfo;		    //����Ƶ��ϸ��Ϣ

	SMulitProgramAppendInfo	sAppendInfo;                //������Ϣ
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

//����Ƶ��ʽ����Ϣ
struct SDYULClipElementGroupInfo
{
	DY_GUID		guidGroupID;				//��ʽ��DY_GUID
	CString		strGroupName;				//��ʽ������
	CString		strGroupHint;				//��ʽ������
	BOOL        bIfDefault;                 //�Ƿ�ΪĬ�ϸ�ʽ��

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

//�շ�ʱ���
struct SDYULCFeeTimeBandInfo
{
    DY_GUID		    guidID;			           //
	DY_GUID            guidFeeID;                 //�շѱ�׼DY_GUID
	COleDateTime    odtBeginTime;              //��ʼʱ��
	COleDateTime    odtEndTime;                //��ֹʱ��
	int             nInitPrice;                //�𲽼�
	int             nInitTime;                 //��ʱ�䵥λ
    int             nPerPrice;                 //����
	int             nPerTime;                  //����ʱ�䵥λ

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

//�շѱ�׼
struct SDYULCCatlogFeeInfo
{
    DY_GUID		       guidFeeID;		            //�շѱ�׼DY_GUID

	BOOL               bIfDeviceType;               //�����źŻ��ǲɼ��豸
	DYULC_DEVICE_TYPE  enumDeviceType;              //�ɼ��豸����
    DY_GUID		       guidSigGroupID;		        //�ź���DY_GUID
	CString            strSigGroupName;             //�ź�������

	COleDateTime       odtBeginDate;                //��Ч��ʼ����
	COleDateTime       odtEndDate;                  //��Ч��ֹ����

	ASDYULCFeeTimeBandInfoArray	asFeeTimeBandInfo;  //ʱ���


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

//������������Ϣ
struct SDYULCPlugInTypeInfo
{
	DY_GUID		guidID;	                      //���DY_GUID
	CString		strName;                      //�������
	CString		strCFName;                    //���Ψһ���ƣ�ȫ��д��
	CString     strHint;                      //�������

	int         iPreferType;                  //�ύ����,1(��������)2(������)3(ESB/EMB)4(ftp)5(�洢·��)6(�ز�����)
    CString     strParam;                     //����

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

//�豸֧�ֵĴŴ����ͣ�����¼���豸��
struct SDYULCSUPTVtrTapeTypeInfo
{
	DY_GUID   guidDeviceID;                      //�豸DY_GUID
	DY_GUID   guidVTRTapeTypeGuid;               //�Ŵ�����guid

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

//�豸֧�ֵ��źţ�ֱָͨ�豸�����ǽ��ջ���
struct SDYULCDeviceSigInfo
{
	DY_GUID	 guidDeviceID;                //�豸DY_GUID
	DY_GUID     guidSigID;                   //�ź�guid

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


//�Ǳ��豸֧�ֵ�VTR����������������ָ��ÿ̨�Ǳ���Կ�����VTR�豸��
struct SDYULCEditSPTVtrInfo
{
	DY_GUID	 guidEditDeviceID;            //�Ǳ��豸DY_GUID
	DY_GUID     guidVTRDeviceID;             //VTR�豸DY_GUID

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

//�豸ͨ���Ľṹ��Ϣ
struct SDYULCDevicePortInfo
{
	DY_GUID						guidID;                             //ͨ����Guid
	DWORD						dwIndex;                            //ͨ�����
	CString                     strName;							//ͨ������
	CString						strHint;                            //ͨ����ע

	DYULC_DEVICE_PORTDIR		enumDir;                            //ͨ������
	DYULC_DEVICE_PORTTYPE		enumType;                           //ͨ������
	DYULCPORTPROPERTYFLAG		dwConnectPropertyFlag;              //ͨ������ͬʱ֧�ֶ�������
	CString						strSocketInfo;                      //ͨ��Socket��Ϣ
	DWORD						dwSDTIMaxSpeed;                     //ͨ�������ٶ�

	DYULC_DEVICE_PORTSTATUS     enumPortWorkStatus;                 //�豸ͨ���Ĺ���״̬��æ���ǿ��У�
	DY_GUID                        guidBelongDeviceID;                 //�豸ͨ�����ڵ��豸��DY_GUID

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

//�豸��
struct SDYULCDeviceGroupInfo
{
	DY_GUID		guidGroupID;				//�豸��DY_GUID
	CString		strGroupName;				//�ź�������
	CString		strGroupHint;				//�ź�������

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

//�豸��Ϣ���ݽṹ
struct SDYULCDeviceInfo
{
	DY_GUID						guidID;                            //�豸Guid                    
	DYULC_DEVICE_TYPE			enumType;                          //�豸����
	CString						strName;                           //�豸����
	CString						strHint;                           //�豸��ע

	DY_GUID						guidGroupID;				  //�豸��DY_GUID
	CString						strGroupName;                 //�豸������

	BOOL						bIsEnable;                         //�豸�Ƿ����
	CDYGuidArray					aSupportPlayTapeTypeID;            //�豸֧�ֵĲ����Ŵ�����
	CDYGuidArray					aSupportRecordTapeTypeID;          //�豸֧�ֵ�¼�ƴŴ�����
	CDYGuidArray					aSupportSatelliteSignalID;         //�豸֧�ֵ��ź�

	CString                     strDeviceModal;                    //�豸�ͺ� 
	int                         nIsPlayOrRec;                      //¼�ƻ��ǲ��� ��1��δ֪��0��ֻ�ܲ��ţ�1ֻ��¼�ƣ�2���ܲ�������¼��
	CString                     strFTPServerIP;                    //���ڷ�����IP��ַ�ļ�¼
	
	CString                     strDestIPSocket;                   //���ڼ�¼��������£�ָ���Ľ��յ�ַ�Ͷ˿�

	int                         nXpos;                             //���豸���ó�������е�λ��X����
	int                         nYpos;                             //���豸���ó�������е�λ��Y����

	BOOL                        bIfLinkDirect;                     //�Ƿ�ֱ���ɼ��豸

	COleDateTime                odtLastUsedOverTime;               //���ʹ��ʱ��

	BOOL                        bMidMatrix;                        //�Ƿ��м����

	BOOL                        bUserLock;                         //�Ƿ�����(����Ϸ�̨���ǽ��ջ���ʹ��Ҫ��)�൱�ڽ���

	COleDateTime                odtPrepareUseTime;                 //Ԥ����Ҫʹ��ʱ��
	ASDYULCDevicePortInfoArray	asPortInfo;                        //�豸ͨ����Ϣ
	
	CString                     strUniCastIPPort;                  //����Ŀ��IP��ַ�Լ��˿�

	int							bBackup;							//�����豸
    
    int                         nMaxPortNum;                        //���˿���Ŀ�����UDP�ɼ�
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
	DY_GUID	guidInputDeviceID;                 //����豸guid
	DY_GUID	guidInputDevicePortID;             //����豸ͨ��guid
	DY_GUID	guidOutputDeviceID;                //�����豸guid
	DY_GUID	guidOutputDevicePortID;            //�����豸ͨ��guid

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
	DY_GUID		  guidColID;				  //��ĿDY_GUID
	CString		  strColName;                 //��Ŀ����
	DY_GUID		  guidVAGroupID;			  //VA��ʽ��DY_GUID
	CString		  strVAGroupName;			  //VA��ʽ������	
	float         fFeeWeight;                 //��Ŀ�Ʒ�Ȩ��
	CDYGuidArray    asGuidPlugInTypeInfo;       //Ĭ�ϵ��ò��
	CStringArray  asStrPlugInTypeInfo;        //Ĭ�ϵ��ò��������
	DY_GUID		  guidOwner;				  //��ĿĬ��ӵ����
	CString		  strOwnerName;				  //��ĿĬ��ӵ��������

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


//ͳһ���뵼���ṹ
struct SDYULCCommonReferInfo
{
	LPVOID        pParamArr;         //��������
	int           nParmaType;        //�������� 0Ϊ�ź��飬1Ϊ�źţ�2Ϊ�Ŵ��飬3Ϊ�Ŵ����ͣ�4Ϊ��������5Ϊ������࣬
	//6Ϊ����Ƶ��ʽ����Ϣ��7Ϊ����Ƶ��ʽ��Ϣ��8Ϊ�Ʒ�ʱ����Ϣ��9Ϊ�Ʒѱ�׼��Ϣ��10Ϊ��Ŀ��Ϣ�еķ���
	//11Ϊ��Ŀ���������Ĺ�����Ϣ��12Ϊ��Ŀ���ʽ��Ĺ�����Ϣ��13Ϊ��Ŀ��Ʒѱ�׼�Ĺ�����Ϣ
	//14Ϊ���������Ϣ��15Ϊ���ý�Ŀ����

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

//ͼ�α൥�ṹ(�ź���)
struct SDYULGraCompileGroup
{
	DY_GUID guidGroup;				//
	CString strGrougName;	//������
	CStringArray asName;	//����������
	CDYGuidArray aGuid;		//DY_GUID
	BOOL	bSigOrDevice;	//�ź�������豸��

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

//ͼ�α൥�ṹ(�ź���)
struct SDYULGraCompileClass
{
	DY_GUID guidClass;				//
	CString strClassName;		//������
	CStringArray asGroupName;	//�����������
	CDYGuidArray aGroupGuid;		//�������DY_GUID

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

//�������ݿ�����
struct SDYULCOfflineDBSetting
{
	DY_GUID				guidSetting;	//
	CString				strDBName;		//���ݿ�����
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

//�ź����ò�����
/*struct SDYULCSigConfigStrategy
{
	DY_GUID guidSigConfig;
	CString strConfigName;

	ASDYNMUserInfoArray		asNMUserInfo;		//���õ���Щ�û�
	ASDYULCSignalSourceInfoArray   asSigSourceArr;		//���õ��źŵ��б�

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

//��¼�������ݽṹ
enum DYULC_SUBJECT_STATE
{
	DYULC_SUBJECTSTATE_UNKNOWN	= 0,
	DYULC_SUBJECTSTATE_DECLARE	= 1,	//���⴦���걨״̬
	DYULC_SUBJECTSTATE_CREATED	= 2,	//���⴦���ѽ���״̬
};

struct SDYULCSubject
{
	DY_GUID			guidSubject;
	CString			strSubjectName;		//��������
	CString			strHint;			//��ע
	int				nPriority;			//���ȼ�(�ص�)
	DYULC_SUBJECT_STATE enumState;		//״̬
	DY_GUID			guidDeclare;		//�걨��guid
	CString			strDeclarer;		//�걨������
	COleDateTime	odtDeclareTime;		//�걨ʱ��
	DY_GUID			guidCreator;		//������guid
	CString			strCreator;			//����������
	COleDateTime	odtCreateTime;		//����ʱ��
	COleDateTime	odtInvalidDate;		//ʧЧʱ��

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

//����ṹ
struct SDYULBulletin
{
	DY_GUID			guidBulletin;		//����guid
	CString			strBulletTitle;		//����
	CString			strContent;			//����
	int				nPriority;			//���ȼ�(�ص�)
	DY_GUID			guidCreator;		//���淢����
	CString			strCreator;			//����������
	COleDateTime	odtDeclareDate;		//��������
	COleDateTime	odtInvalidDate;		//ʧЧʱ��

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