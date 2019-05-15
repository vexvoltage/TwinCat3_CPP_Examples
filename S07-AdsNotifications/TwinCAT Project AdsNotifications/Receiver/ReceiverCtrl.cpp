// ReceiverCtrl.cpp : Implementation of CTcReceiverCtrl
#include "TcPch.h"
#pragma hdrstop

#include "ReceiverW32.h"
#include "ReceiverCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CReceiverCtrl

CReceiverCtrl::CReceiverCtrl() 
	: ITcOCFCtrlImpl<CReceiverCtrl, CReceiverClassFactory>() 
{
}

CReceiverCtrl::~CReceiverCtrl()
{
}

