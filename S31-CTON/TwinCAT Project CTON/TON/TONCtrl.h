///////////////////////////////////////////////////////////////////////////////
// TONCtrl.h

#ifndef __TONCTRL_H__
#define __TONCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TONDRV_NAME "TON"

#include "resource.h"       // main symbols
#include "TONW32.h"
#include "TcBase.h"
#include "TONClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTONCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTONCtrl, &CLSID_TONCtrl>
	, public ITONCtrl
	, public ITcOCFCtrlImpl<CTONCtrl, CTONClassFactory>
{
public:
	CTONCtrl();
	virtual ~CTONCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TONCTRL)
DECLARE_NOT_AGGREGATABLE(CTONCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTONCtrl)
	COM_INTERFACE_ENTRY(ITONCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TONCTRL_H__
