///////////////////////////////////////////////////////////////////////////////
// SortOrderDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "SortOrderDriver.h"
#include "SortOrderClassFactory.h"

DECLARE_GENERIC_DEVICE(SORTORDERDRV)

IOSTATUS CSortOrderDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CSortOrderClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CSortOrderDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CSortOrderDriver::SORTORDERDRV_GetVersion( )
{
	return( (SORTORDERDRV_Major << 8) | SORTORDERDRV_Minor );
}

