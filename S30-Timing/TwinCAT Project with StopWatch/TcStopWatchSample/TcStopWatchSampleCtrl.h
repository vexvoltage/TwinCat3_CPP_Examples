///////////////////////////////////////////////////////////////////////////////
// TcStopWatchSampleCtrl.h

#ifndef __TCSTOPWATCHSAMPLECTRL_H__
#define __TCSTOPWATCHSAMPLECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCSTOPWATCHSAMPLEDRV_NAME "TCSTOPWATCHSAMPLE"

#include "resource.h"       // main symbols
#include "TcStopWatchSampleW32.h"
#include "TcBase.h"
#include "TcStopWatchSampleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcStopWatchSampleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcStopWatchSampleCtrl, &CLSID_TcStopWatchSampleCtrl>
	, public ITcStopWatchSampleCtrl
	, public ITcOCFCtrlImpl<CTcStopWatchSampleCtrl, CTcStopWatchSampleClassFactory>
{
public:
	CTcStopWatchSampleCtrl();
	virtual ~CTcStopWatchSampleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCSTOPWATCHSAMPLECTRL)
DECLARE_NOT_AGGREGATABLE(CTcStopWatchSampleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcStopWatchSampleCtrl)
	COM_INTERFACE_ENTRY(ITcStopWatchSampleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCSTOPWATCHSAMPLECTRL_H__
