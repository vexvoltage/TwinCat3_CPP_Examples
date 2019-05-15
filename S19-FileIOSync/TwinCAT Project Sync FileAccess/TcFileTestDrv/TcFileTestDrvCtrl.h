///////////////////////////////////////////////////////////////////////////////
// TcFileTestDrvCtrl.h

#ifndef __TCFILETESTDRVCTRL_H__
#define __TCFILETESTDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCFILETESTDRVDRV_NAME "TCFILETESTDRV"

#include "resource.h"       // main symbols
#include "TcFileTestDrvW32.h"
#include "TcBase.h"
#include "TcFileTestDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcFileTestDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcFileTestDrvCtrl, &CLSID_TcFileTestDrvCtrl>
	, public ITcFileTestDrvCtrl
	, public ITcOCFCtrlImpl<CTcFileTestDrvCtrl, CTcFileTestDrvClassFactory>
{
public:
	CTcFileTestDrvCtrl();
	virtual ~CTcFileTestDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCFILETESTDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcFileTestDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcFileTestDrvCtrl)
	COM_INTERFACE_ENTRY(ITcFileTestDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCFILETESTDRVCTRL_H__
