///////////////////////////////////////////////////////////////////////////////
// TONDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TONDriver.h"
#include "TONClassFactory.h"

DECLARE_GENERIC_DEVICE(TONDRV)

IOSTATUS CTONDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTONClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTONDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTONDriver::TONDRV_GetVersion( )
{
	return( (TONDRV_Major << 8) | TONDRV_Minor );
}

