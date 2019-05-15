///////////////////////////////////////////////////////////////////////////////
// TcFileTestDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcFileTestDrvDriver.h"
#include "TcFileTestDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCFILETESTDRVDRV)

IOSTATUS CTcFileTestDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcFileTestDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcFileTestDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcFileTestDrvDriver::TCFILETESTDRVDRV_GetVersion( )
{
	return( (TCFILETESTDRVDRV_Major << 8) | TCFILETESTDRVDRV_Minor );
}

