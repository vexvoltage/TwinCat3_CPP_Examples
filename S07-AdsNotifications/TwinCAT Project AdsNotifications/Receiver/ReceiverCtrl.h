///////////////////////////////////////////////////////////////////////////////
// ReceiverCtrl.h

#ifndef __RECEIVERCTRL_H__
#define __RECEIVERCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define RECEIVERDRV_NAME "RECEIVER"

#include "resource.h"       // main symbols
#include "ReceiverW32.h"
#include "TcBase.h"
#include "ReceiverClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CReceiverCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CReceiverCtrl, &CLSID_ReceiverCtrl>
	, public IReceiverCtrl
	, public ITcOCFCtrlImpl<CReceiverCtrl, CReceiverClassFactory>
{
public:
	CReceiverCtrl();
	virtual ~CReceiverCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_RECEIVERCTRL)
DECLARE_NOT_AGGREGATABLE(CReceiverCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CReceiverCtrl)
	COM_INTERFACE_ENTRY(IReceiverCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __RECEIVERCTRL_H__
