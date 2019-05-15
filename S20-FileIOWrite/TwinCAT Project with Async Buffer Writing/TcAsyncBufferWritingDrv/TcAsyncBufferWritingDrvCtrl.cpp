// TcAsyncBufferWritingDrvCtrl.cpp : Implementation of CTcTcAsyncBufferWritingDrvCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TcAsyncBufferWritingDrvW32.h"
#include "TcAsyncBufferWritingDrvCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTcAsyncBufferWritingDrvCtrl

CTcAsyncBufferWritingDrvCtrl::CTcAsyncBufferWritingDrvCtrl() 
	: ITcOCFCtrlImpl<CTcAsyncBufferWritingDrvCtrl, CTcAsyncBufferWritingDrvClassFactory>() 
{
}

CTcAsyncBufferWritingDrvCtrl::~CTcAsyncBufferWritingDrvCtrl()
{
}

