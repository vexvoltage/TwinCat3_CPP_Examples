///////////////////////////////////////////////////////////////////////////////
// TcTComObjArchiveDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcTComObjArchiveDrvDriver.h"
#include "TcTComObjArchiveDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCTCOMOBJARCHIVEDRVDRV)

IOSTATUS CTcTComObjArchiveDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcTComObjArchiveDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcTComObjArchiveDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcTComObjArchiveDrvDriver::TCTCOMOBJARCHIVEDRVDRV_GetVersion( )
{
	return( (TCTCOMOBJARCHIVEDRVDRV_Major << 8) | TCTCOMOBJARCHIVEDRVDRV_Minor );
}

