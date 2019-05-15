///////////////////////////////////////////////////////////////////////////////
// SEHSampleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "SEHSampleDriver.h"
#include "SEHSampleClassFactory.h"

DECLARE_GENERIC_DEVICE(SEHSAMPLEDRV)

IOSTATUS CSEHSampleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CSEHSampleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CSEHSampleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CSEHSampleDriver::SEHSAMPLEDRV_GetVersion( )
{
	return( (SEHSAMPLEDRV_Major << 8) | SEHSAMPLEDRV_Minor );
}

