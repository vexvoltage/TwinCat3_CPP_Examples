///////////////////////////////////////////////////////////////////////////////
// TcPciIoDrvCtrl.h

#ifndef __TCPCIIODRVCTRL_H__
#define __TCPCIIODRVCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define TCPCIIODRVDRV_NAME "TCPCIIODRV"

#include "resource.h"       // main symbols
#include "TcPciIoDrvW32.h"
#include "TcBase.h"
#include "TcPciIoDrvClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CTcPciIoDrvCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CTcPciIoDrvCtrl, &CLSID_TcPciIoDrvCtrl>
	, public ITcPciIoDrvCtrl
	, public ITcOCFCtrlImpl<CTcPciIoDrvCtrl, CTcPciIoDrvClassFactory>
{
public:
	CTcPciIoDrvCtrl();
	virtual ~CTcPciIoDrvCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_TCPCIIODRVCTRL)
DECLARE_NOT_AGGREGATABLE(CTcPciIoDrvCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTcPciIoDrvCtrl)
	COM_INTERFACE_ENTRY(ITcPciIoDrvCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __TCPCIIODRVCTRL_H__
