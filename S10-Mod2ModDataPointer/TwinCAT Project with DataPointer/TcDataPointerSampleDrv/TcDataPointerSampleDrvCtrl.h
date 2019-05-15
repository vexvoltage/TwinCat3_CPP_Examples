///////////////////////////////////////////////////////////////////////////////
// TcDataPointerSampleDrvCtrl.h

#ifndef __TCDATAPOINTERSAMPLEDRVCTRL_H__
#define __TCDATAPOINTERSAMPLEDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCDATAPOINTERSAMPLEDRVDRV_NAME "TCDATAPOINTERSAMPLEDRV"

#include "resource.h"       // main symbols
#include "TcDataPointerSampleDrvW32.h"
#include "TcBase.h"
#include "TcDataPointerSampleDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcDataPointerSampleDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcDataPointerSampleDrvCtrl, &CLSID_TcDataPointerSampleDrvCtrl>
	, public ITcDataPointerSampleDrvCtrl
	, public ITcOCFCtrlImpl<CTcDataPointerSampleDrvCtrl, CTcDataPointerSampleDrvClassFactory>
{
public:
	CTcDataPointerSampleDrvCtrl();
	virtual ~CTcDataPointerSampleDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCDATAPOINTERSAMPLEDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcDataPointerSampleDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcDataPointerSampleDrvCtrl)
	COM_INTERFACE_ENTRY(ITcDataPointerSampleDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCDATAPOINTERSAMPLEDRVCTRL_H__
