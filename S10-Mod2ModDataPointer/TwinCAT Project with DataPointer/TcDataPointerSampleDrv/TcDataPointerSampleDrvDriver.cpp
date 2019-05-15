///////////////////////////////////////////////////////////////////////////////
// TcDataPointerSampleDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcDataPointerSampleDrvDriver.h"
#include "TcDataPointerSampleDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCDATAPOINTERSAMPLEDRVDRV)

IOSTATUS CTcDataPointerSampleDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcDataPointerSampleDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcDataPointerSampleDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcDataPointerSampleDrvDriver::TCDATAPOINTERSAMPLEDRVDRV_GetVersion( )
{
	return( (TCDATAPOINTERSAMPLEDRVDRV_Major << 8) | TCDATAPOINTERSAMPLEDRVDRV_Minor );
}

