///////////////////////////////////////////////////////////////////////////////
// SEHSampleCtrl.h

#ifndef __SEHSAMPLECTRL_H__
#define __SEHSAMPLECTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define SEHSAMPLEDRV_NAME "SEHSAMPLE"

#include "resource.h"       // main symbols
#include "SEHSampleW32.h"
#include "TcBase.h"
#include "SEHSampleClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CSEHSampleCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CSEHSampleCtrl, &CLSID_SEHSampleCtrl>
	, public ISEHSampleCtrl
	, public ITcOCFCtrlImpl<CSEHSampleCtrl, CSEHSampleClassFactory>
{
public:
	CSEHSampleCtrl();
	virtual ~CSEHSampleCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_SEHSAMPLECTRL)
DECLARE_NOT_AGGREGATABLE(CSEHSampleCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSEHSampleCtrl)
	COM_INTERFACE_ENTRY(ISEHSampleCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __SEHSAMPLECTRL_H__
