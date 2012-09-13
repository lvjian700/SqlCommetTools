///////////////////////////////////////////////////////////////////////////////////
//DYULCTaskDefine.h

//���ļ����ڶ�����������ṹ
///////////////////////////////////////////////////////////////////////////////////

#if !defined( __H__DYULCTaskDef__H__ )
#define __H__DYULCTaskDef__H__

#include "\Dayang\DYBaseCtrl\Src\DYCommonDlg\DYDateLoopDef.h"
#include "DYULCCommonDefine.h"

//����Դ����
enum DYULC_TASK_SOURCETYPE
{ 
	DYULCTASK_SOURCETYPE_UNKOWN			    =	0,
	DYULCTASK_SOURCETYPE_VTRTAPE		    =	1,	       //VTR TAPE
	DYULCTASK_SOURCETYPE_SIGNAL			    =	2,	       //�ź�
	DYULCTASK_SOURCETYPE_SERVER             =   3,         //����������
    DYULCTASK_SOURCETYPE_K2                 =   4,         //K2��Ƶ����
    DYULCTASK_SOURCETYPE_EVS                =   5,         //EVS�ļ�
	DYULCTASK_SOURCETYPE_BD                 =   6,         //����
	DYULCTASK_SOURCETYPE_EX1                =   7,         //��չ
	DYULCTASK_SOURCETYPE_EX2                =   8,         //��չ
	DYULCTASK_SOURCETYPE_OTHER              =   9,         //����
};

//����Ŀ������
enum DYULC_TASK_TARGETTYPE
{
	DYULCTASK_TARGETTYPE_UNKOWN			=	0,			//δ֪�豸
	DYULCTASK_TARGETTYPE_VTRTAPE		=	1,			//VTR TAPE
	DYULCTASK_TARGETTYPE_DATAFILES		=	2,			//�ɼ��ͻ���
	DYULCTASK_TARGETTYPE_SERVER		    =	3,			//�������ɼ��ͻ���
	DYULCTASK_TARGETTYPE_DY3000		    =	4,			//DY3000�ͻ���
    DYULCTASK_TARGETTYPE_K2             =   5,          //K2��Ƶ����
    DYULCTASK_TARGETTYPE_EVS            =   6,          //EVS�ļ�
	DYULCTASK_TARGETTYPE_BD             =   7,          //��չ
	DYULCTASK_TARGETTYPE_EX1            =   8,          //��չ
	DYULCTASK_TARGETTYPE_EX2             =  9,          //��չ
	DYULCTASK_TARGETTYPE_OTHER		    =	10,			//�����ͻ���
};


//����༭״̬
enum  DYULC_TASK_EDITSTATUS
{
	DYULCTASK_EDITSTATUS_NOPREFER		=	0,			//�����ѱ���
    DYULCTASK_EDITSTATUS_PREPERED       =   1,          //���ύ
	DYULCTASK_EDITSTATUS_AUDITLEVEL1    =	2,			//����һ��ͨ��
	DYULCTASK_EDITSTATUS_AUDITLEVEL2	=	3,			//�������ͨ��
	DYULCTASK_EDITSTATUS_AUDITLEVEL3	=	4,			//��������ͨ��
	DYULCTASK_EDITSTATUS_AUDITLEVEL4	=	5,			//��������ͨ��
	DYULCTASK_EDITSTATUS_AUDITLEVEL5	=	6,			//��������ͨ��
    DYULCTASK_EDITSTATUS_RETURN		=	7,			//�����˻�
};

//�������ȼ�
enum DYULC_TASK_PRIORITY
{
	DYULCTASK_PRIORITY_LOW				=	0,          //������ȼ�
	DYULCTASK_PRIORITY_BELOWNORMAL		=	1,          //�ϵ����ȼ�
	DYULCTASK_PRIORITY_NORMAL			=	2,          //�������ȼ�
	DYULCTASK_PRIORITY_ABOVENORMAL		=	3,          //�ϸ����ȼ�
	DYULCTASK_PRIORITY_HIGH				=	4,          //������ȼ�
};

//����༭����Դ
enum DYULC_TASK_EDITSOURCE
{
	DYULCTASK_EDITSOURCE_UNKNOWN	=	0,
	DYULCTASK_EDITSOURCE_CSEDIT		=	1,		//CS�༭������
	DYULCTASK_EDITSOURCE_BSEDIT		=	2,		//BS�༭������
};

//����ִ��״̬
enum DYULC_TASK_RUNSTATUS
{ 
	DYULCTASK_RUNSTATUS_SLEEP			=	0,			//˯��
	DYULCTASK_RUNSTATUS_WAITING			=	1,			//�ȴ�
	DYULCTASK_RUNSTATUS_RUNING			=	2,			//ִ��
	DYULCTASK_RUNSTATUS_FINISHED		=	3,			//���
	DYULCTASK_RUNSTATUS_ERROR			=	4,			//����
	DYULCTASK_RUNSTATUS_CANCEL			=	5,			//ȡ��
	DYULCTASK_RUNSTATUS_ALLOCATED       =   6,          //�����ѷ���	
};

//�������̹�������
enum DYULC_LINKTYPE
{
	DYULC_LINKTYPE_NONE	      = 0,		// δ֪
	DYULC_LINKTYPE_CLIPDATA   = 1,      // CLIPDATA��  �Ƿֶ��ز�
	DYULC_LINKTYPE_CLIPPART   = 2,		// CLIPPART��  �ֶ��ز�
};
//ϵͳ��������
enum DYULC_SYSTEMCONFIG_TYPE
{
	DYULCSYSTEMCONFIG_TYPE_LIFECYCLESET			= 1,	//�������ڹ�������
	DYULCSYSTEMCONFIG_TYPE_COLUMNPRECEPTSET	    = 2,	//��Ŀ�ͷ�����Ӧ��ϵ����
};

//��¼����ʹ���м��豸��Ϣ
struct SDYULCTaskDeviceInfo
{
	DY_GUID                        guidTaskID;                       //��������guid

	DY_GUID                        guidMCtrlPortID;                  //����������ͨ��guid
	DY_GUID                        guidCCtrlPortID;                  //���񱻿���ͨ��guid

	BOOL                        bPassMidMatrix;                   //�Ƿ���м����
	CDYGuidArray                  asGuidMidMatrixArr;               //�����м�����guid����
	CDYGuidArray                  asGuidMidMatrixPortArr;           //�����м����˿�(����)guid����

	BOOL                        bPassGateWay;                     //�ź��Ƿ��ý������
	DY_GUID                        guidGateWayDevice;                //ý�������豸guid
	DY_GUID                        guidGateWayPort;                  //ý�������豸ͨ��guid
	CString                     strIPAddressGateWayDevice;        //ý�������豸IP��ַ
	CString                     strIPAddressGateWayPort;          //ý�������豸ͨ��IP��ַ

	CString                     strGateWayInportName;             //ý�������������
	CString                     strGateWayOutPortName;            //ý�����س�������

	CString                     strDecoderName;                   //��������
	DY_GUID                        guidDecoderDevice;                //������Guid
	CString                     strIPAddressDecoder;              //������IP��ַ

	CString                     strEncoderName;                   //��������
	DY_GUID                        guidEncoderDevice;                //������guid
	CString                     strIPAddressEncoder;              //������IP��ַ

	BOOL                        bPassLMatrix;	                  //�Ƿ����Ƶ����
	CString                     strSatsigProcesserName;           //�����źŽ���豸����
	DY_GUID                        guidSatsigProcesser;              //�����źŽ���豸guid
	DY_GUID						guidSatsigProcesserOutPort;		 //�����źŽ���豸���ͨ��guid

	BOOL                        bNeedAnalogAdj;                   //�Ƿ���Ҫģ�����
	CString                     strAnalogAdjuster;                //ģ�����������
	DY_GUID                        guidAnalogAdjuster;               //ģ�������guid	

	BOOL                        bNeedDigitalAdj;                  //�Ƿ���Ҫ���ֵ���
	CString                     strDigitalAdjuster;               //���ֵ���������
	DY_GUID                        guidDigitalAdjuster;              //���ֵ�����guid

	BOOL                        bPassTVEncoder;                   //�Ƿ�ʹ�õ��ӽ����
	CString                     strTVEncoder;                     //���ӽ��������	
	DY_GUID                        guidTVEncoder;                    //���ӽ����guid
	DY_GUID                        guidTVEncoderPort;                //ʹ�õĵ��ӽ����ͨ��guid

	CString                     strMagicWall;                     //�໭��ָ�������
	DY_GUID                        guidMagicWall;                    //�໭��ָ���guid	
	DY_GUID                        guidMagicWallPort;                //ʹ�õĶ໭��ָ���ͨ��guid

	CString                     strDAOutbedDeviceName;            //ʹ��D/A�豸��
	DY_GUID                        guidDAOutbedDevice;               //ʹ��D/A�豸guid
	CString                     strADInbedDeviceName;             //ʹ��A/D�豸����	
	DY_GUID                        guidADInbedDevice;                //ʹ��A/D�豸guid

	CString                     strVSChangeDeviceName;            //ת���豸����
	DY_GUID                        guidVSChangeDevice;               //ת������DY_GUID	

	CString                     strTerminalMatrixIn;              //���վ�����ڣ��л��ã�
	CString                     strTerminalMatrixOut;             //���վ�����ڣ��л��ã�
	DY_GUID                        guidTerminalMatrix;               //���վ���guid

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

//���񸽼���Ϣ
struct SDYULCTaskExtraInfo
{
	DY_GUID                     guidTaskID;             //��������Guid

	BOOL                        bColorHaveSwitched;     //��ɫ�Ƿ����л������ھ�����˸��ʾ��
	BOOL                        bSigHaveSwitched;       //�ź��Ƿ��л�����Ҫ��ָ�����Կ��ź��Ƿ��л���
	BOOL                        bHandleOverdue;         //�Ƿ�Թ����ز��Ѿ�����	

	DWORD			            dwTaskProgress;			//�������
	COleDateTime                odtLastProcessTime;     //�����������ʱ��
	COleDateTime	            odtFinishDate;			//���ʱ��
	COleDateTime                odtTrueBegin;           //������ʵ��ʼʱ��
	COleDateTime                odtTrueEnd;             //������ʵ����ʱ��
	DWORD                       dwTrueLength;           //������ʵִ�г���

	int                         nHadMoveClip;           //�Ƿ��Ѿ�Ǩ�ƹ� 0δǨ�ƣ�1����Ǩ�ƣ�2ȫ��Ǩ��(����ֻ����)
	int                         bOnceError;             //�����Ƿ��������ֹ�����������ִ��	
	BOOL                        bTansferNetFail;        //���͵������Ƿ�ʧ��

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


//����Ŀ���زĽṹ��Ϣ
struct	SDYULClipData
{
	//---------------	������Ϣ	---------------------------------------------
	DY_GUID 						guidTaskID;						//	��¼����DY_GUID
	DY_GUID 						guidItem;                       //  �ز�DY_GUID,��ʼΪ��
	DY_GUID						guidDir;                        //  ·��DY_GUID,��ʼΪ��
	DY_GUID						guidDir20;                        // ����2.0, ·��DY_GUID,��ʼΪ��

	CString						strName;						//	�ز�����
	CString						strInformation;                 //  ��Ŀ���
	CString						strProvider;                    //  �����ṩ��
	CString						strKeyWords;					//	�ؼ�����Ϣ;���ŷָ�
	CString						strRemark;						//	��ע��Ϣ
	DYITEM_OWNERTYPE			enumOwnerType;					//	ӵ��������
	CString						strOwnerID;						//	ӵ���߱�ʶ
	CString						strOwnerID20;						//����2.0	ӵ���߱�ʶ
	//-----------------------------------------------------------------------------------

	//---------------	��Ŀ��Ϣ	---------------------------------------------
	CString						strOutsideId;					//  �ⲿΨһ��ʶ
	CString						strSubName;						//  ������---���ƵĽ��ͺͲ�����Ϣ
	//DYRITEM_AUDIENCELEVEL		enumAudienceLevel;				//	���ڼ���
	//DYRITEM_SECRETLEVEL			enumSecretLevel;				//	���ܼ���
	int         enumAudienceLevel;				//	���ڼ���
	int			enumSecretLevel;				//	���ܼ���
	DY_GUID						guidContent;					//	���ݷ���
	DY_GUID						guidCate;						//	������
	DY_GUID						guidType;						//	������
	DY_GUID						guidLenssort;					//	��ͷ����
	DY_GUID						guidMISItem;					//	��MISϵͳ������DY_GUID
	ASDYMarkPointInfoArray		asMarkPoint;					//  ������֡�������
	DWORD						dwIconFrameNo;					//  ͼ���֡��
	//-----------------------------------------------------------------------------------

	//---------------	����Ƶ��Ϣ	---------------------------------------------

	DY_GUID                    	guidElementInfoGropuID;		    // �زĸ�ʽ��DY_GUID
	ASDYULClipElementInfoArray	asFileElementInfo;              // �زľ����ʽ��Ϣ
	//-----------------------------------------------------------------------------------

	//---------------	����������Ϣ	---------------------------------------------
	DWORD						dwExtraDataType;				// ������������
	DWORD						dwExtraDataSizeInByte;			// �������ݴ�С
	PBYTE						pbExtraData;					// ���ӵĶ�������
	//-----------------------------------------------------------------------------------

	int              nMainClass;
	int              nSubClass;
	CString          strClassname;
	int              nLevel;

	BOOL			 bNeedAudioSearch;						//��Ҫ��Ƶ����

	DYVIDEO_SCALE_TYPE	iVideoUpScaleType;		//���壬�����ϱ任��ʽ
	DYVIDEO_SCALE_TYPE	iVideoDownScaleType;	//���壬�����±任��ʽ

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

//�����ⲿ��Ϣ
struct SDYULCTaskExternInfo 
{
	DY_GUID     guidTaskID;                      //��������DY_GUID

	CString  strProgramCode;                  //��Ŀ����
	CString  strProgmanSysColType;            //��Ŀ����ϵͳ����Ŀ����
	CString  strProgManSysColCode;            //��Ŀ����ϵͳ����Ŀ����
	CString  strProgManSysColName;            //��Ŀ����ϵͳ����Ŀ����

	CString  strTaskExternID;                 //�ⲿϵͳ��¼������ID
	CString  strExternUserCode;               //�ⲿϵͳ���û����룬������ķ�����
	int      nRecTaskType;                    //��������� 1���ֶ���ʼ,�Զ�����
	//		   2���Զ���ʼ,�ֶ�����
	//		   3���Զ���ʼ,�Զ�����
	//    	   4���ֶ���ʼ,�ֶ�����
	//           5������ģ��
	CString  strStrategys;                    //��������,�����,Ǩ�Ʋ������

	CString  strProcessID;                    //�������̵�ID
	CString  strPreStepID;                    //�������̵���һ����guid
	CString  strSourceSystemID;               //��������ߵ�ϵͳID

	int      nApplicationType;                //����������/��ͨ�ȵ�
	int      nApplicationUseage;              //������������/�ݲ���

	//��¼�����Ӧ��ԤԼ��Ŀ����Ϣ
	BOOL	bFromProgram;					//�����Ƿ����Խ�Ŀ��
	DY_GUID	guidProgram;					//��Ӧ�Ľ�Ŀ��ID
	int				nBespeakTime;			//ԤԼ�Ĵ���
	CDYGuidArray		asBespeakUserGuid;		//ԤԼ�����û�DY_GUID(ԤԼ���ľͲ����ٴ�ԤԼ��)
	CStringArray	asBespeakUserName;		//ԤԼ�����û���
	CStringArray	asBespeakUserColumn;	//ԤԼ�����û���Ŀ

	DY_GUID	guidPreTask;					//��Ӧ��ԤԼ����DY_GUID,(����Լ���ʵ������Ļ�)
	DY_GUID	guidWorkTask;					//��Ӧ��ʵ����¼�����DY_GUID(����Լ���ԤԼ����Ļ�)

	BOOL	bInArrange;						//�����Ƿ����ڱ���(�ڱ�����������±���)

	DY_GUID	guidCutTask;					//ԤԼ�����Ӧ�Ĵ�ʵ�����������е�����

	BOOL	bModAfterArrange;				//ԤԼ�����ڱ��ź��ֱ��޸�
	BOOL	bCancelAfterArrange;			//ԤԼ�����ڱ��ź󱻳���

	int		nExchangeState;					//Ǩ���Ƿ����(0:δǨ�ƣ�1:Ǩ����ɣ�2:Ǩ��ʧ��)
	BOOL	bNewsMediaTask;					//����ý����������

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

//��¼���������Ϣ
struct SDYULCTaskInfo
{
	//������Ϣ
	DY_GUID						guidTaskID;				//��������DY_GUID
	CString						strName;				//������
	CString						strHint;				//��������

	DYULC_TASK_EDITSTATUS		enumEditStatus;			//�༭״̬
	COleDateTime				odtPreferDate;			//�ύʱ��
	DYULC_TASK_EDITSOURCE		enumEditSource;			//����༭����Դ(BS,CS)
    ///////////////////
	COleDateTime				odtTaskStartDate;		//��ʼʱ��
	COleDateTime				odtTaskStopDate;		//����ʱ��
	DWORD                       dwDuration;				//���ȣ���֡Ϊ��λ

	BOOL                        bLoopTask;
	DY_GUID                     guidCycle;              //ѭ�����õ�guid
	SDYDateLoop                 sDateLoop;              //ѭ��ʱ�������Ϣ
    //////////////////
    /////////////////////////
    //�ź���Ϣ
	DY_GUID						guidSigGroup;	        //�ź���DY_GUID
	CString                     strSigGroupName;        //�ź�������
	DY_GUID						guidSignalID;	        //�ź�DY_GUID	
	CString                     strSignalName;          //�ź�����
	CString                     strSignalAddress;       //�ź�������ַ	
    CString                     strSignalPort;          //�ź������˿ں�	
	
	DYULC_TASK_SOURCETYPE		enumSourceType;			//����Դ����
	
	//VTR��Ϣ
	DY_GUID						guidSrcVTRTapeType;     //Դ�Ŵ�����guid
	CString                     strSrcVTRTapeTypeName;  //Դ�Ŵ���������
	CString						strSrcVTRTapeName;	    //Դ�Ŵ���
	BOOL						bSrcSetTrimInOut;       //Դ�Ƿ����������
	DWORD						dwSrcVTRTrimIn;		    //Դ�����Ϣ
	DWORD						dwSrcVTRTrimOut;	    //Դ������Ϣ

	BOOL                        bIfReceiver;            //�Ƿ�Ϊ���ǽ��ջ�	
	DY_GUID                     guidReceiver;           //���ǽ��ջ��豸DY_GUID
	DYULC_DEVICE_PORTTYPE	    enumSrcSigType;         //�ź�����,����
	BOOL                        bHavePrioritySig;       //��ʹ�õ��ź��Ƿ�������ȼ�
	BOOL                        bIsHD;                  //��ʹ�õ��ź��Ƿ�Ϊ����

	DYULC_UDP_PACKTYPE          enumUDPPackType;        //UDP��װ��ʽ������
	////////////////////////////////
	//¼����Ϣ
	DY_GUID						guidRecordDeviceID;		//����Ŀ��ʹ���豸DY_GUID
	DY_GUID						guidRecordPortID;		//����Ŀ��ʹ��ͨ��guid
	CString                     strRecordDeviceName;    //¼������

	DYULC_TASK_TARGETTYPE		enumTargetType;			//����Ŀ������
	DYULC_DEVICE_TYPE			enumRecordDevice;       //¼���豸����
    //
	//VTR��Ϣ
	DY_GUID						guidDestVTRTapeType;    //Ŀ��Ŵ�����guid
	CString                     strDestTapeTypeName;    //Ŀ��Ŵ���������
	CString						strDestVTRTapeName;		//Ŀ��Ŵ���	
	BOOL						bDestSetTrimInOut;      //Ŀ���Ƿ����������
	DWORD						dwDestVTRTrimIn;		//Ŀ���������Ϣ
	DWORD						dwDestVTRTrimOut;
	DYDEVICERECTRACKFLAG		dwDestVTRRecTrackFlag;			//�Ƿ������Ƶ����Ƶ�еļ�·
	int						    bDestIsVTRRecAssemble;			//��� /���뷽ʽ 0-���룬1����ϣ�2��Ӳ¼

	////////////////////////////////////////////////////////////////////////////////
   	CString                     strChannelID;           //ӵ���߲���
	CString                     strChannelName;         //ӵ���߲�������
    CString                     strColumnID;            //ӵ������Ŀ
	CString                     strColumnName;          //ӵ������Ŀ����

    CString						strOwnerID20;			  //����2.0,ӵ����ID
	CString                     strOwnerName20;           //����2.0,ӵ����
	
	CString						strOwnerID;				//ӵ����ID
	CString                     strOwnerName;           //ӵ����

	DY_GUID                     guidBizDomain;          //����3.0,��
    CString                     strBizDomain;           //����
    DY_GUID                     guidProjectItem;        //��Ŀguid
    CString                     strProjectItem;         //��Ŀ��
    //////////////////////////////////////////////////////////////////
    DYULC_TASK_PRIORITY			enumPriority;			//���ȼ�
	DYULC_TASK_RUNSTATUS		enumRunStatus;          //��������״̬
	
    BOOL                        bBackUp;
	DY_GUID                     guidOrgTask;            //ԭ����DY_GUID
	CString                     strOrgTaskName;         //ԭ��������   

	//���ݻ��ļ�����
	DY_GUID                     guidClipFormat;         //�ɼ���ʽguid
	CString                     strClipFormatName;      //�ɼ���ʽ
    
	SDYULClipData			    sClipDataInfo;			//�ɼ����ز���Ϣ
    
	int                         iFileFormat;            //�ļ���ʽ
	CString                     strProgramPath;         //�ļ����
	int                         iPreGetFlag;            //Ԥ���ʶ
    COleDateTime                odtModifyTime;          //�޸�

	CString                     strTaskFrom;            //��Դ��

	///////////////////////////////////////////////////////////
    CString                     strAddition;            //����
	///////////////////////////////////////////////////////////
	DY_GUID                     guidTaskClass;          //������ò��,�������
	CString                     strTaskClassName;       //������ò��������,�����������

	CString						strSubject;				//���������	
	CString						strSponser;				//�ύ��	
	COleDateTime				odtAuditDate;		    //���ʱ��
	CString						strAuditorName;			//�����
	CString						strAuditorHint;			//�������
	int                         nAduitLevel;            //����
    
	BOOL						bRemoteTDIR;            //�Ƿ�߲ɱ߱�
	double						dSec_FlushFrequency;    //ˢ����
	BOOL						bIfVideoFrameAnalysis;  //�Ƿ��֡
	BOOL						bIfDoServerTranscode;   //�Ƿ�ת��
	BOOL						bIfSaveServerFiles;     //�Ƿ񱣴�������ļ�
	BOOL						bIfDoCopy;              //�Ƿ񿽱�

	BOOL                        bIfCapSeg;              //�Ƿ�ֶβɼ�
	int                         nCapSegTime;            //�ֶβɼ�ʱ�䣬��
	BOOL						bNeedPartInsertDB;		//��Ҫ�ֶ������ݿ�
	BOOL						bNeedCombine;			//��Ҫ����Զ��ϲ�
	BOOL                        bIfSaveExplorer;        //�Զ��ϲ����
	BOOL                        bNeedAutoImportPart;    //�Ƿ�ֶ�Ǩ��/�ύ
	
	BOOL                        bIfLinkDirect;          //�Ƿ�ֱ��
	BOOL                        bIfConflict;            //�Ƿ�Ϊ��ͻ����
	BOOL                        bIfVirtual;             //�Ƿ�Ϊ��������ֻ����ͳ�Ʋ�ִ��
	DY_GUID                     guidLinkOutSys;         //�������ⲿϵͳ��Ŀguid(�п���������,ͨ���)

	//����ʹ�õ���β�豸���	
	BOOL                        bNeedDecode;             //�ź��Ƿ��辭������
	BOOL                        bNeedEncode;             //�ź��Ƿ��辭������
	BOOL                        bNeedChangeRate;         //�ź��Ƿ��辭��ת������
	float                       fTargetRate;             //Ŀ������
	BOOL                        bNeedchangeVideo;        //�Ƿ���Ҫת��
	BOOL                        bNeedDAOutbed;           //�Ƿ���ҪDA����豸
	BOOL                        bNeedADInbed;            //�Ƿ���ҪAD�ϳ��豸	

	DY_GUID						guidPlayDeviceID;		 //����Դʹ���豸DY_GUID	
	DY_GUID						guidPlayPortID;		     //����Դʹ��ͨ��guid
    
	BOOL                        bPreAllocFinish;        //�Ƿ񾭹�Ԥ����
	BOOL                        bPheDeviceSwitched;     //��Χ�豸�Ƿ��Ѿ��л�
	BOOL                        bIsServerPlay;          //Դ�豸�Ƿ�Ϊ�������豸
	
	DWORD			            dwOldTaskProgress;	    //������Ȳ������
	DWORD			            dwLastTaskProgress;     //�������

	BOOL						bUrgencyTask;			//��������
	CString						strConflictReason;		//��ͻԭ��

	DY_GUID						guidRecordSFDeviceID;    //����Ŀ��ʹ��ʱ���豸DY_GUID
	DY_GUID						guidRecordSFPortID;		 //����Ŀ��ʹ��ʱ��ͨ��guid

	//ԤԼ������Ϣ
	BOOL						bFromProgram;			//�����ڽ�Ŀ��
	DY_GUID						guidProgram;			//��Ӧ�Ľ�Ŀ��guid
	int							nBespeakTime;			//ԤԼ����
	CStringArray				asBespeakUserName;		//ԤԼ�����û�����
	CStringArray				asBespeakUserColumn;	//ԤԼ�����û���Ŀ

	BOOL                        bImportant;                       //�ص��Ŀ
	BOOL                        bNeedTrans;                       //�Ƿ���ҪǨ��
	int                         nTransDelayTime;                  //Ǩ���ӳ�ʱ��
    BOOL                        bInspect;               //�Ƿ���
	BOOL                        bSigConfirm;            //�Ƿ��ź�ȷ��
	CString                     strSatParam;            //�źŲ���
	CString                     strInMatrixPortName;    //����˿���

	int                         nReserve1;              //int�������ֶ�1
	int                         nReserve2;              //int�������ֶ�2
	CString                     strReserve1;            //string�������ֶ�1
	CString                     strReserve2;            //string�������ֶ�2

	SDYULCTaskDeviceInfo		sTaskDeviceInfo;		//�м��豸��Ϣ
	SDYULCTaskExtraInfo			sTaskExtraInfo;			//���񸽼���Ϣ
	SDYULCTaskExternInfo		sTaskExternInfo;		//һЩ�ⲿ��Ϣ

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

//�������ֶ���Ϣ
struct SDYULCTaskReserveInfo 
{
	DY_GUID     guidTaskID;                      //��������DY_GUID

	CString  strReserve1;                     //�����ֶ�1
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

//�����ز�Ǩ��״̬��¼
struct SDYULContentImportStatus
{
	CString          strRequestid;             //Ǩ��Ҫ��DY_GUID
	CString          strTaskguid;              //�漰�����DY_GUID
	long             lStatus;                  //���״̬        0δǨ�ƣ�1����Ǩ�ƣ�2Ǩ�Ƴɹ� 3 Ǩ��ʧ��
	COleDateTime     dtModifyTime;             //״̬�ĸı�ʱ��
	CString          strProcessName;           //Ǩ��Ҫ����������

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

//Ŀ���ز��ļ�����Ϣ
struct SDYULClipPartInfo
{
	DY_GUID		        guidTask;			//����DY_GUID
	DY_GUID		        guidClip;			//��Ӧ�زĶ�DY_GUID
	int			        nIndex;				//�زĶ����
	COleDateTime        odtCreateTime;      //����ʱ��

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

//����Ŀ���ز��ļ���Ա��Ϣ
struct SDYULClipFileElementInfo
{
	DY_GUID                    guidClip;                       //  �ز�DY_GUID
	CString					strName;                        //  �ز�����
	DYCLIPCLASSFLAG			dwClass;						//	�ز�����Ƶ����
	DWORD					dwLanguageID;					//	DEFAULT : 0
	DY_VIDEO_STANDARD		enumVideoStandard;				//	��Ƶ��׼
	DY_STREAM_TYPE 	        enumSpecialMediaType;			//	����Ƶ������ʽ����
	DWORD					dwPropertyFlag;					//	�ر��־ see DYCLIPELEMENTPROPERTYFLAG_???
	DY_GUID                    guidClipVAElement;              //  �ز�����Ƶ���ͽṹguid

	CString					strFileName;					//	����Ƶ�ļ�����ļ���
	CString					strAudioFileNames[8];			//	��Ƶ�ļ���

	DWORD                   dwTrimIn;                       //  ���
	DWORD                   dwTrimOut;                      //  ����
	
	CString					strSignalSourceName;			//	�ز���Դ, example:¼���ID, or ����channel...
	CString					strSignalSourceHint;			//	�ز���Դ��ע
	DWORD					dwVTRTapeInPoint;				//	¼������
	DWORD					dwVTRTapeOutPoint;				//	¼�������

	//DYCLIP_STORETYPE_FLAG	dwDataStoreType;				//  �زĴ洢����
	int	 dwDataStoreType;				//  �زĴ洢����
	CString 				strAccessPath;					//  �� DYClipStoreType_AccessPath;
	CString 				strBackupPath;					//  �� DYClipStoreType_BackupPath;
	CString 				strFTPServerInfo;				//  �� DYClipStoreType_FTPServer;
	CString 				strBackupFTPServerInfo;			//  �� DYClipStoreType_BackupFTPServer;

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
	DYULCTASK_LOGTYPE_OVERTIMEERR   =	1,			    //���ڳ�������ʱ����Ϊʧ��
	DYULCTASK_LOGTYPE_ALLOCATE		=	2,			    //��������
	DYULCTASK_LOGTYPE_NOALLOCANSWER	=	3,			    //��������δ��Ӧ
	DYULCTASK_LOGTYPE_RESETWAIT		=	4,			    //����Ϊ�ȴ�
	DYULCTASK_LOGTYPE_ACCEPTANSWER  =	5,			    //���������Ѿ���Ӧ
	DYULCTASK_LOGTYPE_DENYRECANSWER =	6,			    //����¼�����񲻽���
	DYULCTASK_LOGTYPE_DENYPLYANSWER =	7,			    //���䲥�����񲻽���

	DYULCTASK_LOGTYPE_NOBEGINRECANSWER  = 8,			//δ���յ���ʼ¼����Ϣ��ʱ
	DYULCTASK_LOGTYPE_ACTBEGINRECANSWER = 9,            //���յ���ʼ¼����Ϣ
	DYULCTASK_LOGTYPE_SETDOING          = 10,           //����Ϊ����ִ��
	DYULCTASK_LOGTYPE_ACTPROGRSS        = 11,           //���յ����Ȼظ�
	DYULCTASK_LOGTYPE_NOACTPROGRSS      = 12,           //��ʱδ���յ����Ȼظ�
	DYULCTASK_LOGTYPE_NOACTPROGRSEERR   = 13,           //��ʱδ���յ����Ȼظ���Ϊʧ��
	DYULCTASK_LOGTYPE_NOACTPROGRSEEND   = 14,           //��ʱδ���յ����Ȼظ���Ϊ����
	DYULCTASK_LOGTYPE_ACTENDRECANSWER   = 15,           //���յ�¼�ƽ�����Ϣ
	DYULCTASK_LOGTYPE_ACTENDRECANSWEREND= 16,           //���յ�¼�ƽ�����Ϣ��Ϊ����
	DYULCTASK_LOGTYPE_ACTRECERROR       = 17,           //���յ�¼�ƴ�����Ϣ
	DYULCTASK_LOGTYPE_ACTPLYERROR       = 18,           //���յ����Ŵ�����Ϣ

	DYULCTASK_LOGTYPE_CHANGELENGTH      = 19,           //�ı䳤��
	DYULCTASK_LOGTYPE_FROCESTOP         = 20,           //�ֶ�ֹͣ
	DYULCTASK_LOGTYPE_HANDRECALLOC      = 21,           //�ֶ�ȡ������
	
	DYULCTASK_LOGTYPE_NOGETSRCVTR		= 22,           //û�л��ԴVTR
	DYULCTASK_LOGTYPE_NOGETSRCSIG       = 23,           //û�л��Դ�ź�
	DYULCTASK_LOGTYPE_NOGETDESTVTR      = 24,           //û�л��Ŀ��VTR
	DYULCTASK_LOGTYPE_NOGETDESTUL       = 25,           //û�л��Ŀ�깤��վ
	DYULCTASK_LOGTYPE_NOGETDESTSV       = 26,           //û�л��Ŀ�������	
	DYULCTASK_LOGTYPE_SWITCHGATEWAYERR  = 27,           //�л�ý������ʧ��
	DYULCTASK_LOGTYPE_SWITCHMATRIXERR   = 28,           //�л�����ʧ��
	DYULCTASK_LOGTYPE_ALLOCATETASKERR   = 29,           //�����������ʧ��

	DYULCTASK_LOGTYPE_ADDTASK           = 30,           //�������
	DYULCTASK_LOGTYPE_MODTASK           = 31,           //�޸�����
	DYULCTASK_LOGTYPE_DELTASK           = 32,           //ɾ������
	DYULCTASK_LOGTYPE_PRETASK           = 33,           //�ύ����
	DYULCTASK_LOGTYPE_AUDTASK           = 34,           //�������
	DYULCTASK_LOGTYPE_AUDRECJTASK       = 35,           //���ʧ������

	DYULCTASK_LOGTYPE_CHANGESATRECEV    = 36,           //�ı����ǽ��ջ�

	DYULCTASK_LOGTYPE_MOVECLIPSUCCESS   = 37,           //�ɼ��ز�Ǩ�Ƴɹ�
	DYULCTASK_LOGTYPE_MOVECLIPFAILE     = 38,           //�ɼ��ز�Ǩ��ʧ��

	DYULCTASK_LOGTYPE_NOGETSATSIGPROCESSER    = 39,        //û���ҵ����õ������źŴ����豸
	DYULCTASK_LOGTYPE_NOGETTVENCODERPORT      = 40,        //û���ҵ����õĵ��ӽ�����˿�
	DYULCTASK_LOGTYPE_NOGETANALOGADJUSTER     = 41,        //û���ҵ����õ�ģ���źŵ����豸
	DYULCTASK_LOGTYPE_NOGETDAOUTBEDDEVICE     = 42,        //û���ҵ����õ�DA����豸
	DYULCTASK_LOGTYPE_SWITCHLBANDMATRIXERR    = 43,        //�л�L���ξ���ʧ��
	DYULCTASK_LOGTYPE_SWITCHSATSIGPROCESSERR  = 44,        //�л������źŴ����豸ʧ��
	DYULCTASK_LOGTYPE_SWITCHTVENCODERERR      = 45,        //�л������źŽ����ʧ��
	DYULCTASK_LOGTYPE_SWITCHANALOGADJSTERERR  = 46,        //�л�ģ���źŵ����豸ʧ��
	DYULCTASK_LOGTYPE_SWITCHMIDMATRIXERR      = 47,        //�л��м����ʧ��

	DYULCTASK_LOGTYPE_CLIENTLOSTLINK          = 48,        //�ͻ���ʧȥ����
	DYULCTASK_LOGTYPE_SRCSIGHAVEERR           = 49,        //����Դ�źŴ�����������

	DYULCTASK_LOGTYPE_PREALLOCNOGETSRCVTR             = 50,        //Ԥ����û�л��ԴVTR
	DYULCTASK_LOGTYPE_PREALLOCNOGETSRCSIG             = 51,        //Ԥ����û�л��Դ�ź�
	DYULCTASK_LOGTYPE_PREALLOCNOGETSATSIGPROCESSER    = 52,        //Ԥ����û���ҵ����õ������źŴ����豸
	DYULCTASK_LOGTYPE_PREALLOCNOGETTVENCODERPORT      = 53,        //Ԥ����û���ҵ����õĵ��ӽ�����˿�
	DYULCTASK_LOGTYPE_PREALLOCNOGETANALOGADJUSTER     = 54,        //Ԥ����û���ҵ����õ�ģ���źŵ����豸
	DYULCTASK_LOGTYPE_PREALLOCNOGETDAOUTBEDDEVICE     = 55,        //Ԥ����û���ҵ����õ�DA����豸
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTVTR            = 56,        //Ԥ����û�л��Ŀ��VTR
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTUL             = 57,        //Ԥ����û�л��Ŀ�깤��վ
	DYULCTASK_LOGTYPE_PREALLOCNOGETDESTSV             = 58,        //Ԥ����û�л��Ŀ�������
	DYULCTASK_LOGTYPE_PREALLOCSWITCHGATEWAYERR        = 59,        //Ԥ�����л�ý������ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHLBANDMATRIXERR    = 60,        //Ԥ�����л�L���ξ���ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHSATSIGPROCESSERR  = 61,        //Ԥ�����л������źŴ����豸ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHTVENCODERERR      = 62,        //Ԥ�����л������źŽ����ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHANALOGADJSTERERR  = 63,        //Ԥ�����л�ģ���źŵ����豸ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHMIDMATRIXERR      = 64,        //Ԥ�����л��м����ʧ��
	DYULCTASK_LOGTYPE_PREALLOCSWITCHMATRIXERR         = 65,        //Ԥ�����л�����ʧ��
	DYULCTASK_LOGTYPE_PREALLOCALLOCATE		          =	66,		   //Ԥ�����������

	DYULCTASK_LOGTYPE_PRETESTVTRSTATUS_ERROR          = 67,        //Ԥ�����⵽¼��״̬����	
	DYULCTASK_LOGTYPE_USEDCONFILCTDEVICE              = 68,        //Ԥ�����⵽ʹ������ͬ���豸

	DYULCTASK_LOGTYPE_PREALLOCATETASKGETDEVICEERR     = 69,        //Ԥ��������ʧ��

	DYULCTASK_LOGTYPE_FROCESETTASKFINISHSTATUS        = 70,        //ǿ����Ϊִ�����

	DYULCTASK_LOGTYPE_FROCEREPREALLOCATE              = 71,        //ǿ������Ԥ����

	DYULCTASK_LOGTYPE_CLIENTSYSBUSY                   = 72,        //�ͻ���ϵͳæ
	DYULCTASK_LOGTYPE_CLIENTTASKEXIST                 = 73,        //�ͻ������д��������
	DYULCTASK_LOGTYPE_CLIENTGETTASKFAIL               = 74,        //�ͻ��˲�ѯ����ʧ�� 
	DYULCTASK_LOGTYPE_CLIENTGETTASKCONFLICT           = 75,        //�ͻ�������ɼ�ʱ����ڳ�ͻ
	DYULCTASK_LOGTYPE_CLIENTNOENOUGHSPACE             = 76,        //�ͻ��˷��ִ��̿ռ䲻��
	DYULCTASK_LOGTYPE_CLIENTNOFINDSIGNAL              = 77,        //�ͻ���û���ҵ��ź�
	DYULCTASK_LOGTYPE_CLIENTGETCLIPLENGTHFAIL         = 78,        //�ͻ���ȡ���زĳ���ʧ��
	DYULCTASK_LOGTYPE_CLIENTGETPATHERROE              = 79,        //�ͻ��˷��ֲɼ�·������

	DYULCTASK_LOGTYPE_PREALLOCSWITCHDECODERERR        = 80,        //Ԥ�����л��������豸ʧ��
	DYULCTASK_LOGTYPE_SWITCHDECODERERR                = 81,        //�л��������豸ʧ��

	DYULCTASK_LOGTYPE_NOGETVSCHANGEDEVICE             = 82,        //û���ҵ����õ���ת�豸
	DYULCTASK_LOGTYPE_PREALLOCNOGETVSCHANGEDEVICE     = 83,        //Ԥ����û���ҵ����õ���ת�豸
	DYULCTASK_LOGTYPE_SIGNALCHECKERROR                = 84,        //�ź��Զ����췢������
    DYULCTASK_LOGTYPE_SIGCONFIRM                      = 85,        //�ź�ȷ��
};

//��������������  ��־����룩
struct STypeParamTranslate
{
	DY_GUID						guidID;        //          
	int                         nType;         //���
	int                         nCode;         //����   
	CString                     strMsg;        //��־�ַ���
	CString                     strExtern;     //��ע
		
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

//������־��Ϣ�ṹ
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
	CString   strColName;     //��Ŀ����
	CString   strColCode;     //��Ŀ����
	CString   strChannelCode; //Ƶ������
	CString   strChannelName; //Ƶ������
	

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
	CString   strColTypeName;     //��Ŀ��������
	CString   strColTypeCode;     //��Ŀ���ʹ���

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

//���������Ϣ�ṹ
struct SDYULCTaskAuditInfo
{
	DY_GUID						guidTask;                //����DY_GUID
	DY_GUID                        guidAudit;               //����DY_GUID
	CString                     strAuditorName;          //���������
	int                         nAuditLeve;              //��˼���,�ֱ�Ϊ1��2��3��4��5
	int                         nAuditRet;               //��˽����ͨ��Ϊ1����ͨ��Ϊ0
	CString                     strAuditInfo;            //�����Ϣ
	COleDateTime                odtAuditTime;            //���ʱ��


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

//TRAP��Ϣ����
enum  DYULC_TASK_TRAPTYPE
{
	DYULCTASK_TRAPTYPE_UNKNOWN			=	0,			//δ֪����
	DYULCTASK_TRAPTYPE_USERCHANGESTATUS	=	1,			//�û���½/ע����Ϣ
	DYULCTASK_TRAPTYPE_TASKFAILURE		=	2,			//����ʧ����Ϣ
	DYULCTASK_TRAPTYPE_SERVICEEXCEPTION	=	3,			//�����쳣��Ϣ
	DYULCTASK_TRAPTYPE_DEVICEEXCEPTION	=	4,			//�豸�쳣��Ϣ
};

//TRAP��Ϣ��Ϣ
struct SDYULCTaskTrapInfo
{
	DY_GUID					guidTrap;		//TrapGUID
	DYULC_TASK_TRAPTYPE		enumTrapType;	//Trap����
	CString					strTrapContent;	//Trap����
	COleDateTime			odtCreateTime;	//����ʱ��

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
	CString strName;//����
	int		nOldPos;//�̶�λ��//����
	int		nNewPos;//���˵������λ��
	int		nWidth;//���˵�����Ŀ�
};
typedef CArray<SDYULCPrintGridItemInfo, SDYULCPrintGridItemInfo> ASDYULCPrintGridItemInfoArray;

//��Ŀ�������ݽṹ
struct SDYULCProgramInfo
{
	DY_GUID			guidProgram;			//��Ŀguid
	CString			strProgramName;			//��Ŀ����
	CString			strHint;				//��ע
	DY_GUID			guidSignalSource;		//�ź�Դ
	CString			strSignalName;			//�ź�Դ����
	COleDateTime	odtStartTime;			//��ʼʱ��
	COleDateTime	odtStopTime;			//����ʱ��
	DY_GUID			guidSubject;			//����guid
	CString			strSubject;				//��������
	CString			strColumn;				//��Ŀ����
	BOOL			bImportant;				//�ص��Ŀ

	BOOL			bBespeak;				//�Ƿ�ԤԼ
	DY_GUID			guidPreTask;			//��Ӧ��ԤԼ����guid
	DY_GUID			guidRealTask;			//��Ӧ��ʵ�������guid
	int				nBespeakTime;			//ԤԼ�Ĵ���
	CDYGuidArray		asBespeakUserGuid;		//ԤԼ�����û�ID(ԤԼ���ľͲ����ٴ�ԤԼ��)
	CStringArray	asBespeakUserName;		//ԤԼ�����û�����
	CStringArray	asBespeakUserColumn;	//ԤԼ�����û���Ŀ

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

//��¼�����Ӧ��ԤԼ��Ŀ����Ϣ

//�ϴ�����ı�ṹ
enum DYULC_UPLOADTASK_STATE
{
	DYULC_UPLOADTASKSTATE_UNKNOWN	= 0,
	DYULC_UPLOADTASKSTATE_WAITING	= 1,	//�����ѱ��棬�ȴ�ִ��
	DYULC_UPLOADTASKSTATE_RUNNING	= 2,	//����ִ��
	DYULC_UPLOADTASKSTATE_FINISH	= 3,	//���
	DYULC_UPLOADTASKSTATE_ERROR		= 4,	//ʧ��
};

struct SDYULUploadTaskInfo
{
	DY_GUID guidUploadTask;	//����guid
	CString strTaskName;	//��������
	CString strHint;		//����
	CStringArray	asUploadFileName;		//�ϴ����ļ�������
	CStringArray	asKeyWord;				//�ؼ���
	CString			strSenderID;			//������ID
	CString         strSenderName;           //����������	
	CString			strOwnerID;				//ӵ����ID(����)
	CString         strOwnerName;           //ӵ����	
	COleDateTime	odtCreateTime;			//���񴴽�ʱ��
	CString			strSubject;				//��������
	DY_GUID			guidSubject;			//����DY_GUID
	DYULC_UPLOADTASK_STATE		enumRunStatus;	//����״̬
	DY_GUID			guidClip;				//��Ӧ�ز�DY_GUID

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

//������Ǩ����Ŀ�ṹ
struct SDYULCTaskTransInfo
{
	DY_GUID						guidTask;                //����DY_GUID
	CString                     strTaskName;             //��������
	COleDateTime                odtFinishRecTime;        //�������ʱ��
	int                         nTransDelayTime;         //Ǩ���ӳ�ʱ��
	int                         nTransState;             //Ǩ��״̬��0��δǨ�ƣ�1�ѿ�ʼǨ��
	
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

//��Ҫ�Ӵ��ڵ������зָ�һ���زĸ�ԤԼ������
struct SDYULCTaskOrderCutInfo
{
	DY_GUID						guidCutTask;                //����DY_GUID
	CString                     strTaskName;				//��������
	
	DY_GUID						guidSignal;					//�ź�
	CString						strSignalName;				//�ź�����

	CString						strOwnerID;				//ӵ����ID
	CString                     strOwnerName;           //ӵ����	

	CString						strColumnName;			//ӵ������Ŀ

	COleDateTime				odtTaskStartDate;		//��ʼʱ��
	COleDateTime				odtTaskStopDate;		//����ʱ��
	DWORD                       dwDuration;				//���ȣ���֡Ϊ��λ

	DYULC_TASK_RUNSTATUS		enumRunStatus;          //��������״̬

	DY_GUID						guidCorrespondOrderTask;			//��Ӧ��ԤԼ�����guid
	DY_GUID						guidCutUseTask;			//��ʵ�������зֵ��Ǹ������guid

	DY_GUID						guidClip;				//�з����ɵ��زĵ�guid

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

//�������ʱ��νṹ
struct SArrangeTimePart
{
	DY_GUID	guidTimePart;			//ʱ��ID
	CString strTimePartName;		//ʱ����
	CString strTimePartHint;		//ʱ�α�ע
	COleDateTime	odtFromTime;	//��ʼʱ��
	COleDateTime	odtToTime;		//����ʱ��
	int				nShowIndex;		//��ʾ˳��

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

//����֪ͨ����
enum DYULC_TASK_CHANGENOTIFYTYPE
{ 
	DYULCTASK_CHANGENOTIFY_UNKOWN			    =	0,
	DYULCTASK_CHANGENOTIFY_ARRANGEPASS		    =	1,	       //�������ͨ��
	DYULCTASK_CHANGENOTIFY_ARRANGERETURN	    =	2,	       //��������˻�
	DYULCTASK_CHANGENOTIFY_RECFINISH		    =	3,	       //�ɼ����
	DYULCTASK_CHANGENOTIFY_NEWSUPLOADFINISH		=	4,		   //���ø���ϴ����
	DYULCTASK_CHANGENOTIFY_NEWSRECFINISH		=	5,		   //���ø���ɼ����
};

//�������ύ�˷��Ͷ���֪ͨ
struct SDYULCTaskWorkStateChangeNotify
{
	DY_GUID			guidNotify;		//֪ͨ��DY_GUID
	CString			strTaskName;	//��������
	DY_GUID			guidTaskID;		//��¼����DY_GUID
	COleDateTime	odtNotifyTime;	//֪ͨ����ʱ��
	DYULC_TASK_CHANGENOTIFYTYPE		enumNotifyType;		//֪ͨ����
	BOOL			bSendNotify;	//�Ƿ��ѷ���

	//ԤԼ������Ϣ
	BOOL						bFromProgram;			//�����ڽ�Ŀ��
	DY_GUID						guidProgram;			//��Ӧ�Ľ�Ŀ��guid
	int							nBespeakTime;			//ԤԼ����
	CStringArray				asBespeakUserName;		//ԤԼ�����û�����
	CStringArray				asBespeakUserColumn;	//ԤԼ�����û���Ŀ

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

//���������Ϣ
struct SDYULCTaskClassInfo
{
	DY_GUID		  guidID;                //�������guid
	CString		  strName;               //�����������
	CString		  strCFName;             //�������Ψһ���ƣ�ȫ��д��
	CString		  strHint;               //������������
	CStringArray  astrPlgInNameArr;      //�����а�����ǰ�������
	CDYGuidArray  asguidPlugInArr;       //�����а�����ǰ���DY_GUID
	CStringArray  astrBPlgInNameArr;     //�����а����ĺ�������
	CDYGuidArray  asBguidPlugInArr;      //�����а����ĺ���DY_GUID

	int           nPlugType;             //������� ǰ���0������1

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
//��¼��ز���������Ϣ
//����ΪDYULCOperateFlow��ṹ
typedef struct tagDYULCOperateFlow
{
	CString  strIndexGuid;//����DY_GUID(KEY)
	int		 iLinkType;//��������  ֵ�ο� DYULC_LINKTYPE
	CString  strLinkGuid;//����guid
	int      iOrderNum;//���
	CString  strUsePerson;//������
	COleDateTime  odtUseTime;//����ʱ��
	CString  strUseRemark;//������ע
	int      iUseState;//������ʽ
	CString  strUseState;//������ʽ����
	CString  strFlowContent;//�˲��������Ϣ �������
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
//����ΪDYULCOperateFlow��ṹ
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//ϵͳ���ñ�
//����ΪDYULCSystemConfig��ṹ
typedef struct tagDYULCSystemConfig
{
	CString  strConfigGuid;//����DY_GUID
	CString  strConfigName;//��������
	int      enumConfigType;//��������    DYULC_SYSTEMCONFIG_TYPE
	int      iOrderNum;//����
	CString  strConfigValue;//ֵ
	CString	 strPreceptName;	//��������
	BOOL     bDefault;          //�Ƿ�Ϊȱʡ
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
//����ΪDYULCSystemConfig��ṹ
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
