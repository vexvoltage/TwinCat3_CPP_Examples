///////////////////////////////////////////////////////////////////////////////
// TcEthernetSampleCtrl.h

#ifndef __TCETHERNETSAMPLECTRL_H__
#define __TCETHERNETSAMPLECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCETHERNETSAMPLEDRV_NAME "TCETHERNETSAMPLE"

#include "resource.h"       // main symbols
#include "TcEthernetSampleW32.h"
#include "TcBase.h"
#include "TcEthernetSampleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcEthernetSampleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcEthernetSampleCtrl, &CLSID_TcEthernetSampleCtrl>
	, public ITcEthernetSampleCtrl
	, public ITcOCFCtrlImpl<CTcEthernetSampleCtrl, CTcEthernetSampleClassFactory>
{
public:
	CTcEthernetSampleCtrl();
	virtual ~CTcEthernetSampleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCETHERNETSAMPLECTRL)
DECLARE_NOT_AGGREGATABLE(CTcEthernetSampleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcEthernetSampleCtrl)
	COM_INTERFACE_ENTRY(ITcEthernetSampleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCETHERNETSAMPLECTRL_H__
