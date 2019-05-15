///////////////////////////////////////////////////////////////////////////////
// ModuleReceiver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ModuleReceiver.h"
#include "ModuleReceiverAds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CModuleReceiver
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CModuleReceiver
BEGIN_INTERFACE_MAP(CModuleReceiver)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_ITCOMOBJECT(CModuleReceiver)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CModuleReceiver)
IMPLEMENT_ITCADI(CModuleReceiver)
IMPLEMENT_ITCWATCHSOURCE(CModuleReceiver)

///////////////////////////////////////////////////////////////////////////////
// Set parameters of CModuleReceiver 
BEGIN_SETOBJPARA_MAP(CModuleReceiver)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_ModuleReceiverDefaultAdsPort, m_DefaultAdsPort)
	SETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	SETOBJPARA_VALUE(PID_ModuleReceiverCounter, m_Counter)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CModuleReceiver 
BEGIN_GETOBJPARA_MAP(CModuleReceiver)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_ModuleReceiverDefaultAdsPort, m_DefaultAdsPort)
	GETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	GETOBJPARA_VALUE(PID_ModuleReceiverCounter, m_Counter)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
	GETOBJPARA_TYPE_CODE(PID_ModuleReceiverAdsPort, WORD, *p = AmsGetPort())
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CModuleReceiver
BEGIN_OBJPARAWATCH_MAP(CModuleReceiver)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
	OBJPARAWATCH_VALUE(PID_ModuleReceiverCounter, m_Counter)
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CModuleReceiver
BEGIN_OBJDATAAREA_MAP(CModuleReceiver)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(0, m_Inputs)
	OBJDATAAREA_VALUE(1, m_Outputs)
	OBJDATAAREA_VALUE(3, m_AdsCommuncationDataArea)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CModuleReceiver::CModuleReceiver()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_TraceLevelMax(tlAlways)
	, m_DefaultAdsPort(0)
	, m_ContextAdsPort(0)
	, m_Counter(0)
{
	memset(&m_Inputs, 0, sizeof(m_Inputs)); 
	memset(&m_Outputs, 0, sizeof(m_Outputs)); 
	memset(&m_AdsCommuncationDataArea, 0, sizeof(m_AdsCommuncationDataArea)); 
}

///////////////////////////////////////////////////////////////////////////////
CModuleReceiver::~CModuleReceiver() 
{
}

///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CModuleReceiver)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CModuleReceiver::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	hr = SUCCEEDED(hr) ? InitAmsPort(m_spSrv, m_DefaultAdsPort) : hr;
	//prepare address - here: take local one
	m_Addr.netId = AmsGetNetId();
	// and the default PLC port: 
	m_Addr.port = 851;
	// cleanup on failure
	if (FAILED(hr))
	{
		ShutdownAmsPort();
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CModuleReceiver::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization


	// If following call is successful the CycleUpdate method will be called, 
	// eventually even before method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CModuleReceiver::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	// deregister handles 
	long nErr = AdsDelDeviceNotificationReq(m_Addr, NOTSAMPLE_INVOKEID_DELNOTIFICATION_MAINPLCVAR, m_AdsCommuncationDataArea.hNotification);
	nErr = AdsWriteReq(m_Addr, NOTSAMPLE_INVOKEID_RELEASEHDL_MAINPLCVAR, ADSIGRP_SYM_RELEASEHND, 0, sizeof(m_AdsCommuncationDataArea.hUser), &m_AdsCommuncationDataArea.hUser); 
	// ...and wait for confirmations
	CTimeout timeoutHelper(1000);
	while ( m_AdsCommuncationDataArea.hNotification != 0 || m_AdsCommuncationDataArea.hUser != 0) // wait for all handles to be 0, which is done while receiving confirmations
	{
      m_spRTime->Delay(1);
      if ( timeoutHelper.IsElapsed() )
         {
	      	m_Trace.Log(tlAlways, FNAMEA "Error during shutdown: Havent received confirmations during 1000ms", hr);
            break;
      }
	}
  	m_Trace.Log(tlAlways, FNAMEA "Shutdown ended", hr);

	RemoveModuleFromCaller(); 

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CModuleReceiver::SetObjStateSP()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	ShutdownAmsPort();

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CModuleReceiver::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;
	int nErr;

	char m_szVar[] = {"MAIN.PlcVar"}; // variable to monitor

	// DeviceNotification state machine: 
	switch(m_AdsCommuncationDataArea.Status)
	{
	case STATUS_INIT:
		// Get variable handle
		nErr = AdsReadWriteReq(m_Addr, NOTSAMPLE_INVOKEID_GETHDL_MAINPLCVAR, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(m_AdsCommuncationDataArea.hUser), sizeof(m_szVar), m_szVar);
		if(nErr != S_OK) 
		{
			m_AdsCommuncationDataArea.Status = STATUS_ERROR_ADSCOM;
		} 
		else 
		{
			m_AdsCommuncationDataArea.Status = STATUS_WAITHDL;
		}
		break;
	case STATUS_ADDNOT:
		// Add Device Notification
		// set the attributes of the notification
		AdsNotificationAttrib  adsNotificationAttrib;
		adsNotificationAttrib.cbLength = 4;
		adsNotificationAttrib.nTransMode = ADSTRANS_SERVERONCHA;
		adsNotificationAttrib.nMaxDelay = 0;
		adsNotificationAttrib.nCycleTime = 10000000; // 1sec 

		nErr = AdsAddDeviceNotificationReq(	m_Addr,
   					NOTSAMPLE_INVOKEID_ADDNOTIFICATION_MAINPLCVAR, 
   					ADSIGRP_SYM_VALBYHND, 
   					m_AdsCommuncationDataArea.hUser, 
   					adsNotificationAttrib
					);
		if(nErr != S_OK) 
		{
			m_AdsCommuncationDataArea.Status = STATUS_ERROR_ADSCOM;
		} 
		else 
		{
			m_AdsCommuncationDataArea.Status = STATUS_WAITADDNOT;
		}
		break; 
	case STATUS_RECEIVINGNOT:
		// wait for notifications; do nothing
		break; 
	} 

	// handle pending ADS indications and confirmations
	CheckOrders();

	//TODO: Add logic here
	m_Counter+= (1+m_Inputs.Value);
	m_Outputs.Value=m_Counter;

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CModuleReceiver::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CModuleReceiver::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;
	m_Trace.Log(tlVerbose, FLEAVEA);
}



///////////////////////////////////////////////////////////////////////////////
//////////ADS Communication receiving functions ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void CModuleReceiver::AdsReadWriteCon( AmsAddr& rAddr, ULONG invokeId, ULONG nResult, ULONG cbLength, PVOID pData )
{

	if(nResult == S_OK && invokeId == NOTSAMPLE_INVOKEID_GETHDL_MAINPLCVAR) 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsReadWrite for ads-variable getHdl got invokeid=0x%08x and nresult=0x%08x", invokeId, nResult);
		memcpy(&m_AdsCommuncationDataArea.hUser, pData, sizeof(m_AdsCommuncationDataArea.hUser));
		m_AdsCommuncationDataArea.Status = STATUS_ADDNOT;
	} 
	else 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsReadWrite for ads-variable getHdl failed nresult=0x%08x - retrying", nResult);
		m_AdsCommuncationDataArea.Status = STATUS_INIT; //retry
	}


}

void CModuleReceiver::AdsAddDeviceNotificationCon( AmsAddr& rAddr, ULONG invokeId, ULONG nResult, ULONG handle) 
{
	if(nResult == S_OK && invokeId == NOTSAMPLE_INVOKEID_ADDNOTIFICATION_MAINPLCVAR) {
		memcpy(&m_AdsCommuncationDataArea.hNotification, &handle, sizeof(m_AdsCommuncationDataArea.hNotification));
		m_Trace.Log(tlAlways, FNAMEA "AdsAddDeviceNotificationCon for ads-variable getHdl got called with invokeid=0x%08x and nresult=0x%08x:notification hdl 0x%08x ", invokeId, nResult, m_AdsCommuncationDataArea.hNotification );
		m_AdsCommuncationDataArea.Status = STATUS_RECEIVINGNOT;
	} 
	else 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsAddDeviceNotificationCon received with unknown information!");
		m_AdsCommuncationDataArea.Status = STATUS_ERROR_ADDDEVNOT;
	}
}

void CModuleReceiver::AdsDeviceNotificationInd( AmsAddr& rAddr, ULONG invokeId, ULONG cbLength, AdsNotificationStream* pNotifications ) 
{
	if( pNotifications->nStamps >= 1 && pNotifications->tStamp[0].tSample->cbSampleSize == 4 && pNotifications->tStamp[0].tSample->hNotification == m_AdsCommuncationDataArea.hNotification ) //check the received notification if correct data and expected notification hdl
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsDeviceNotificationInd received for notification hdl 0x%08x with new value 0x%08x", m_AdsCommuncationDataArea.hNotification , pNotifications->tStamp[0].tSample->data[0]);
	}
	else 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsDeviceNotificationInd received with unknown information!");
		m_AdsCommuncationDataArea.Status = STATUS_ERROR_DEVNOT;
	}
}

void CModuleReceiver::AdsDelDeviceNotificationCon( AmsAddr& rAddr, ULONG invokeId, ULONG nResult ) 
{
	if( invokeId == NOTSAMPLE_INVOKEID_DELNOTIFICATION_MAINPLCVAR ) // check the received notification if correct data and expected notification hdl
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsDelDeviceNotificationCon received ");
		m_AdsCommuncationDataArea.hNotification = 0;
	}
	else 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsDelDeviceNotificationCon received with unknown invokeid 0x%08x!", invokeId);
	}


}
void CModuleReceiver::AdsWriteCon( AmsAddr& rAddr, ULONG invokeId, ULONG nResult )
{
	if( invokeId == NOTSAMPLE_INVOKEID_RELEASEHDL_MAINPLCVAR ) // heck the received notification if correct data and expected notification hdl
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsWriteCon received for deleting ads handle");
		m_AdsCommuncationDataArea.hUser = 0; 
	}
	else 
	{
		m_Trace.Log(tlAlways, FNAMEA "AdsWriteCon received with unknown invokeid 0x%08x!", invokeId);
	}
}
