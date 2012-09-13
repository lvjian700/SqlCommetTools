#pragma once

#define GRIDHEADCOLOR	RGB(200 ,220 , 250)

struct SExtXMLTaskInfo
{
	DY_GUID      guidTaskID; 
	CString      strFileName;
	CString      strContentCode;
	CString      strCPID;
	CString      strProgramName;
	CString      strStartTime;
	CString      strEndTime;
	CString      strSubContentCode;
	CString      strSubContentURL;
	CString      strPort;
	int          nStatus;
	int          nSignalSubType;	
	CString      strFileFormat;    
    COleDateTime odtCreateTime;
    CString      strXML;    
	CString      strErrorInfo;
    int          iErrorType;

	CString      strProgramPath;

	SExtXMLTaskInfo()
	{
		guidTaskID        = GUID_NULL; 
	    strFileName       = _T("");
		strContentCode    = _T("");
		strCPID           = _T("");
		strProgramName    = _T("");
	    strStartTime      = _T("");
	    strEndTime        = _T("");
	    strSubContentCode = _T("");
	    strSubContentURL  = _T("");
        strXML            = _T("");
		strPort           = _T("");
	    nStatus           = 0;
	    nSignalSubType    = 0;
	    strFileFormat     = _T("");    
        odtCreateTime.SetDateTime(2000,1,1,1,1,1);
		strErrorInfo      = _T("");
		iErrorType        = 0;
		strProgramPath    = _T("");
	};

	~SExtXMLTaskInfo()
	{		
	};

	SExtXMLTaskInfo(const SExtXMLTaskInfo & other)
	{ 		
		*this = other; 
	};

	SExtXMLTaskInfo& operator = (const SExtXMLTaskInfo& other)
	{
		guidTaskID        = other.guidTaskID;
		strFileName       = other.strFileName;
		strContentCode    = other.strContentCode;
		strCPID           = other.strCPID;
		strProgramName    = other.strProgramName;
		strStartTime      = other.strStartTime;
		strEndTime        = other.strEndTime;
		strSubContentCode = other.strSubContentCode;
	    strSubContentURL  = other.strSubContentURL;
		strXML            = other.strXML;
		strPort           = other.strPort;
	    nStatus           = other.nStatus;
		nSignalSubType    = other.nSignalSubType;
		strFileFormat     = other.strFileFormat;    
        odtCreateTime.SetDateTime(2000,1,1,1,1,1);
		strErrorInfo      = other.strErrorInfo;
		iErrorType        = other.iErrorType;
        strProgramPath    = other.strProgramPath;
		return *this;
	};
};
typedef CArray<SExtXMLTaskInfo, SExtXMLTaskInfo&> ASExtXMLTaskInfoArray;


struct SExtMatrixSatParamInfo
{
	DY_GUID      guidID;
	DY_GUID      guidDevice;
	CString      strDeviceName;
	CString      strManagerIP;
	int          iDeviceType;
	int          iDeviceSubType;	
	CString      strParam;    
   
	SExtMatrixSatParamInfo()
	{
		guidID          = GUID_NULL;
		guidDevice        = GUID_NULL;
		strDeviceName   = _T("");
	    strManagerIP       = _T("");
		iDeviceType           = 0;
	    iDeviceSubType    = 0;
	    strParam     = _T("");        
	};

	~SExtMatrixSatParamInfo()
	{		
	};

	SExtMatrixSatParamInfo(const SExtMatrixSatParamInfo & other)
	{ 		
		*this = other; 
	};

	SExtMatrixSatParamInfo& operator = (const SExtMatrixSatParamInfo& other)
	{
		guidID        = other.guidID;
		guidDevice        = other.guidDevice;
		strDeviceName        = other.strDeviceName;
		strManagerIP      = other.strManagerIP;
		iDeviceType    = other.iDeviceType;
		iDeviceSubType           = other.iDeviceSubType;
		strParam    = other.strParam;		
		return *this;
	};
};
typedef CArray<SExtMatrixSatParamInfo, SExtMatrixSatParamInfo&> ASExtMatrixSatParamInfoArray;
