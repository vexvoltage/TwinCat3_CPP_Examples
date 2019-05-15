// SortOrderCtrl.cpp : Implementation of CTcSortOrderCtrl
#include "TcPch.h"
#pragma hdrstop

#include "SortOrderW32.h"
#include "SortOrderCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CSortOrderCtrl

CSortOrderCtrl::CSortOrderCtrl() 
	: ITcOCFCtrlImpl<CSortOrderCtrl, CSortOrderClassFactory>() 
{
}

CSortOrderCtrl::~CSortOrderCtrl()
{
}

