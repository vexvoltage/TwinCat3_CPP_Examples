// TcIoTaskImageAccessDrvCtrl.cpp : Implementation of CTcTcIoTaskImageAccessDrvCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TcIoTaskImageAccessDrvW32.h"
#include "TcIoTaskImageAccessDrvCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTcIoTaskImageAccessDrvCtrl

CTcIoTaskImageAccessDrvCtrl::CTcIoTaskImageAccessDrvCtrl() 
	: ITcOCFCtrlImpl<CTcIoTaskImageAccessDrvCtrl, CTcIoTaskImageAccessDrvClassFactory>() 
{
}

CTcIoTaskImageAccessDrvCtrl::~CTcIoTaskImageAccessDrvCtrl()
{
}

