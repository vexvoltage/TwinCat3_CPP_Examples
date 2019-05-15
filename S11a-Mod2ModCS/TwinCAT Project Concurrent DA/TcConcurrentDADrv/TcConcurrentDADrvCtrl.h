///////////////////////////////////////////////////////////////////////////////
// TcConcurrentDADrvCtrl.h

#ifndef __TCCONCURRENTDADRVCTRL_H__
#define __TCCONCURRENTDADRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCCONCURRENTDADRVDRV_NAME "TCCONCURRENTDADRV"

#include "resource.h"       // main symbols
#include "TcConcurrentDADrvW32.h"
#include "TcBase.h"
#include "TcConcurrentDADrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcConcurrentDADrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcConcurrentDADrvCtrl, &CLSID_TcConcurrentDADrvCtrl>
	, public ITcConcurrentDADrvCtrl
	, public ITcOCFCtrlImpl<CTcConcurrentDADrvCtrl, CTcConcurrentDADrvClassFactory>
{
public:
	CTcConcurrentDADrvCtrl();
	virtual ~CTcConcurrentDADrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCCONCURRENTDADRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcConcurrentDADrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcConcurrentDADrvCtrl)
	COM_INTERFACE_ENTRY(ITcConcurrentDADrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCCONCURRENTDADRVCTRL_H__
