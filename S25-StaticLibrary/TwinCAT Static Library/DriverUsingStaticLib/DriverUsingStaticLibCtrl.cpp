// DriverUsingStaticLibCtrl.cpp : Implementation of CTcDriverUsingStaticLibCtrl
#include "TcPch.h"
#pragma hdrstop

#include "DriverUsingStaticLibW32.h"
#include "DriverUsingStaticLibCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CDriverUsingStaticLibCtrl

CDriverUsingStaticLibCtrl::CDriverUsingStaticLibCtrl() 
	: ITcOCFCtrlImpl<CDriverUsingStaticLibCtrl, CDriverUsingStaticLibClassFactory>() 
{
}

CDriverUsingStaticLibCtrl::~CDriverUsingStaticLibCtrl()
{
}

