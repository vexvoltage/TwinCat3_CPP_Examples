// SEHSampleCtrl.cpp : Implementation of CTcSEHSampleCtrl
#include "TcPch.h"
#pragma hdrstop

#include "SEHSampleW32.h"
#include "SEHSampleCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CSEHSampleCtrl

CSEHSampleCtrl::CSEHSampleCtrl() 
	: ITcOCFCtrlImpl<CSEHSampleCtrl, CSEHSampleClassFactory>() 
{
}

CSEHSampleCtrl::~CSEHSampleCtrl()
{
}

