///////////////////////////////////////////////////////////////////////////////
// TcAsyncBufferWritingDrvCtrl.h

#ifndef __TCASYNCBUFFERWRITINGDRVCTRL_H__
#define __TCASYNCBUFFERWRITINGDRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCASYNCBUFFERWRITINGDRVDRV_NAME "TCASYNCBUFFERWRITINGDRV"

#include "resource.h"       // main symbols
#include "TcAsyncBufferWritingDrvW32.h"
#include "TcBase.h"
#include "TcAsyncBufferWritingDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcAsyncBufferWritingDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcAsyncBufferWritingDrvCtrl, &CLSID_TcAsyncBufferWritingDrvCtrl>
	, public ITcAsyncBufferWritingDrvCtrl
	, public ITcOCFCtrlImpl<CTcAsyncBufferWritingDrvCtrl, CTcAsyncBufferWritingDrvClassFactory>
{
public:
	CTcAsyncBufferWritingDrvCtrl();
	virtual ~CTcAsyncBufferWritingDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCASYNCBUFFERWRITINGDRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcAsyncBufferWritingDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcAsyncBufferWritingDrvCtrl)
	COM_INTERFACE_ENTRY(ITcAsyncBufferWritingDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCASYNCBUFFERWRITINGDRVCTRL_H__
