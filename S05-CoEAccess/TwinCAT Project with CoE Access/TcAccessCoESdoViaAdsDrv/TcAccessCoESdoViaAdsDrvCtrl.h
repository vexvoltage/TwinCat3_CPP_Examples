///////////////////////////////////////////////////////////////////////////////
// TcAccessCoESdoViaAdsDrvCtrl.h

#ifndef __TCACCESSCOESDOVIAADSDRVCTRL_H__
#define __TCACCESSCOESDOVIAADSDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCACCESSCOESDOVIAADSDRVDRV_NAME "TCACCESSCOESDOVIAADSDRV"

#include "resource.h"       // main symbols
#include "TcAccessCoESdoViaAdsDrvW32.h"
#include "TcBase.h"
#include "TcAccessCoESdoViaAdsDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcAccessCoESdoViaAdsDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcAccessCoESdoViaAdsDrvCtrl, &CLSID_TcAccessCoESdoViaAdsDrvCtrl>
	, public ITcAccessCoESdoViaAdsDrvCtrl
	, public ITcOCFCtrlImpl<CTcAccessCoESdoViaAdsDrvCtrl, CTcAccessCoESdoViaAdsDrvClassFactory>
{
public:
	CTcAccessCoESdoViaAdsDrvCtrl();
	virtual ~CTcAccessCoESdoViaAdsDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCACCESSCOESDOVIAADSDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcAccessCoESdoViaAdsDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcAccessCoESdoViaAdsDrvCtrl)
	COM_INTERFACE_ENTRY(ITcAccessCoESdoViaAdsDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCACCESSCOESDOVIAADSDRVCTRL_H__
