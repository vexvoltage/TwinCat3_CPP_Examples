// TONCtrl.cpp : Implementation of CTcTONCtrl
#include "TcPch.h"
#pragma hdrstop

#include "TONW32.h"
#include "TONCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTONCtrl

CTONCtrl::CTONCtrl() 
	: ITcOCFCtrlImpl<CTONCtrl, CTONClassFactory>() 
{
}

CTONCtrl::~CTONCtrl()
{
}

