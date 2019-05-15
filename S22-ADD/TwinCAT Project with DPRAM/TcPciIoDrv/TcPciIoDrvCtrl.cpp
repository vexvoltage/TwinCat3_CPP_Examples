// TcPciIoDrvCtrl.cpp : Implementation of CTcTcPciIoDrvCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TcPciIoDrvW32.h"
#include "TcPciIoDrvCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTcPciIoDrvCtrl

CTcPciIoDrvCtrl::CTcPciIoDrvCtrl() 
	: ITcOCFCtrlImpl<CTcPciIoDrvCtrl, CTcPciIoDrvClassFactory>() 
{
}

CTcPciIoDrvCtrl::~CTcPciIoDrvCtrl()
{
}

