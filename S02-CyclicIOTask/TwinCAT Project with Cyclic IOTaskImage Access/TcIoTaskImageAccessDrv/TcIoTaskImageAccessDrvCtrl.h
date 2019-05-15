///////////////////////////////////////////////////////////////////////////////
// TcIoTaskImageAccessDrvCtrl.h

#ifndef __TCIOTASKIMAGEACCESSDRVCTRL_H__
#define __TCIOTASKIMAGEACCESSDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCIOTASKIMAGEACCESSDRVDRV_NAME "TCIOTASKIMAGEACCESSDRV"

#include "resource.h"       // main symbols
#include "TcIoTaskImageAccessDrvW32.h"
#include "TcBase.h"
#include "TcIoTaskImageAccessDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcIoTaskImageAccessDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcIoTaskImageAccessDrvCtrl, &CLSID_TcIoTaskImageAccessDrvCtrl>
	, public ITcIoTaskImageAccessDrvCtrl
	, public ITcOCFCtrlImpl<CTcIoTaskImageAccessDrvCtrl, CTcIoTaskImageAccessDrvClassFactory>
{
public:
	CTcIoTaskImageAccessDrvCtrl();
	virtual ~CTcIoTaskImageAccessDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCIOTASKIMAGEACCESSDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcIoTaskImageAccessDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcIoTaskImageAccessDrvCtrl)
	COM_INTERFACE_ENTRY(ITcIoTaskImageAccessDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCIOTASKIMAGEACCESSDRVCTRL_H__
