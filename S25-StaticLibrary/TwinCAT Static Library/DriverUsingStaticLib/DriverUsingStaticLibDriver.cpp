///////////////////////////////////////////////////////////////////////////////
// DriverUsingStaticLibDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "DriverUsingStaticLibDriver.h"
#include "DriverUsingStaticLibClassFactory.h"

DECLARE_GENERIC_DEVICE(DRIVERUSINGSTATICLIBDRV)

IOSTATUS CDriverUsingStaticLibDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CDriverUsingStaticLibClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CDriverUsingStaticLibDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CDriverUsingStaticLibDriver::DRIVERUSINGSTATICLIBDRV_GetVersion( )
{
	return( (DRIVERUSINGSTATICLIBDRV_Major << 8) | DRIVERUSINGSTATICLIBDRV_Minor );
}

