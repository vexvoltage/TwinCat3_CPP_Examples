///////////////////////////////////////////////////////////////////////////////
// InToOutCtrl.h

#ifndef __INTOOUTCTRL_H__
#define __INTOOUTCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define INTOOUTDRV_NAME "INTOOUT"

#include "resource.h"       // main symbols
#include "InToOutW32.h"
#include "TcBase.h"
#include "InToOutClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CInToOutCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CInToOutCtrl, &CLSID_InToOutCtrl>
	, public IInToOutCtrl
	, public ITcOCFCtrlImpl<CInToOutCtrl, CInToOutClassFactory>
{
public:
	CInToOutCtrl();
	virtual ~CInToOutCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_INTOOUTCTRL)
DECLARE_NOT_AGGREGATABLE(CInToOutCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CInToOutCtrl)
	COM_INTERFACE_ENTRY(IInToOutCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __INTOOUTCTRL_H__
