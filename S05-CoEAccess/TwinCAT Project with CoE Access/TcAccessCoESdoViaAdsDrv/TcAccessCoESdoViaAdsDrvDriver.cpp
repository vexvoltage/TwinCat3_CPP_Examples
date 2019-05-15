///////////////////////////////////////////////////////////////////////////////
// TcAccessCoESdoViaAdsDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcAccessCoESdoViaAdsDrvDriver.h"
#include "TcAccessCoESdoViaAdsDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCACCESSCOESDOVIAADSDRVDRV)

IOSTATUS CTcAccessCoESdoViaAdsDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcAccessCoESdoViaAdsDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcAccessCoESdoViaAdsDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcAccessCoESdoViaAdsDrvDriver::TCACCESSCOESDOVIAADSDRVDRV_GetVersion( )
{
	return( (TCACCESSCOESDOVIAADSDRVDRV_Major << 8) | TCACCESSCOESDOVIAADSDRVDRV_Minor );
}

