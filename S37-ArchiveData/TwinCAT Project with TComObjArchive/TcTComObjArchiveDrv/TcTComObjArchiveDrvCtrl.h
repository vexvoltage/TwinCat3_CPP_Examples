///////////////////////////////////////////////////////////////////////////////
// TcTComObjArchiveDrvCtrl.h

#ifndef __TCTCOMOBJARCHIVEDRVCTRL_H__
#define __TCTCOMOBJARCHIVEDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCTCOMOBJARCHIVEDRVDRV_NAME "TCTCOMOBJARCHIVEDRV"

#include "resource.h"       // main symbols
#include "TcTComObjArchiveDrvW32.h"
#include "TcBase.h"
#include "TcTComObjArchiveDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcTComObjArchiveDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcTComObjArchiveDrvCtrl, &CLSID_TcTComObjArchiveDrvCtrl>
	, public ITcTComObjArchiveDrvCtrl
	, public ITcOCFCtrlImpl<CTcTComObjArchiveDrvCtrl, CTcTComObjArchiveDrvClassFactory>
{
public:
	CTcTComObjArchiveDrvCtrl();
	virtual ~CTcTComObjArchiveDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCTCOMOBJARCHIVEDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcTComObjArchiveDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcTComObjArchiveDrvCtrl)
	COM_INTERFACE_ENTRY(ITcTComObjArchiveDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCTCOMOBJARCHIVEDRVCTRL_H__
