///////////////////////////////////////////////////////////////////////////////
// DriverUsingStaticLibCtrl.h

#ifndef __DRIVERUSINGSTATICLIBCTRL_H__
#define __DRIVERUSINGSTATICLIBCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define DRIVERUSINGSTATICLIBDRV_NAME "DRIVERUSINGSTATICLIB"

#include "resource.h"       // main symbols
#include "DriverUsingStaticLibW32.h"
#include "TcBase.h"
#include "DriverUsingStaticLibClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CDriverUsingStaticLibCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CDriverUsingStaticLibCtrl, &CLSID_DriverUsingStaticLibCtrl>
	, public IDriverUsingStaticLibCtrl
	, public ITcOCFCtrlImpl<CDriverUsingStaticLibCtrl, CDriverUsingStaticLibClassFactory>
{
public:
	CDriverUsingStaticLibCtrl();
	virtual ~CDriverUsingStaticLibCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_DRIVERUSINGSTATICLIBCTRL)
DECLARE_NOT_AGGREGATABLE(CDriverUsingStaticLibCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDriverUsingStaticLibCtrl)
	COM_INTERFACE_ENTRY(IDriverUsingStaticLibCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __DRIVERUSINGSTATICLIBCTRL_H__
