///////////////////////////////////////////////////////////////////////////////
// InToOutDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "InToOutDriver.h"
#include "InToOutClassFactory.h"

DECLARE_GENERIC_DEVICE(INTOOUTDRV)

IOSTATUS CInToOutDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CInToOutClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CInToOutDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CInToOutDriver::INTOOUTDRV_GetVersion( )
{
	return( (INTOOUTDRV_Major << 8) | INTOOUTDRV_Minor );
}

