///////////////////////////////////////////////////////////////////////////////
// SortOrderCtrl.h

#ifndef __SORTORDERCTRL_H__
#define __SORTORDERCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define SORTORDERDRV_NAME "SORTORDER"

#include "resource.h"       // main symbols
#include "SortOrderW32.h"
#include "TcBase.h"
#include "SortOrderClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CSortOrderCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CSortOrderCtrl, &CLSID_SortOrderCtrl>
	, public ISortOrderCtrl
	, public ITcOCFCtrlImpl<CSortOrderCtrl, CSortOrderClassFactory>
{
public:
	CSortOrderCtrl();
	virtual ~CSortOrderCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_SORTORDERCTRL)
DECLARE_NOT_AGGREGATABLE(CSortOrderCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSortOrderCtrl)
	COM_INTERFACE_ENTRY(ISortOrderCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __SORTORDERCTRL_H__
