// TcFileTestDrvCtrl.cpp : Implementation of CTcTcFileTestDrvCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TcFileTestDrvW32.h"
#include "TcFileTestDrvCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTcFileTestDrvCtrl

CTcFileTestDrvCtrl::CTcFileTestDrvCtrl() 
	: ITcOCFCtrlImpl<CTcFileTestDrvCtrl, CTcFileTestDrvClassFactory>() 
{
}

CTcFileTestDrvCtrl::~CTcFileTestDrvCtrl()
{
}

