///////////////////////////////////////////////////////////////////////////////
// TcIoTaskImageAccessDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcIoTaskImageAccessDrvDriver.h"
#include "TcIoTaskImageAccessDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCIOTASKIMAGEACCESSDRVDRV)

IOSTATUS CTcIoTaskImageAccessDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcIoTaskImageAccessDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcIoTaskImageAccessDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcIoTaskImageAccessDrvDriver::TCIOTASKIMAGEACCESSDRVDRV_GetVersion( )
{
	return( (TCIOTASKIMAGEACCESSDRVDRV_Major << 8) | TCIOTASKIMAGEACCESSDRVDRV_Minor );
}

