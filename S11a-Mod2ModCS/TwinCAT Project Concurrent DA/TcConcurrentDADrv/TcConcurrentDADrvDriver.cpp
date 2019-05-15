///////////////////////////////////////////////////////////////////////////////
// TcConcurrentDADrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcConcurrentDADrvDriver.h"
#include "TcConcurrentDADrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCCONCURRENTDADRVDRV)

IOSTATUS CTcConcurrentDADrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcConcurrentDADrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcConcurrentDADrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcConcurrentDADrvDriver::TCCONCURRENTDADRVDRV_GetVersion( )
{
	return( (TCCONCURRENTDADRVDRV_Major << 8) | TCCONCURRENTDADRVDRV_Minor );
}

