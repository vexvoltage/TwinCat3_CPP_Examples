///////////////////////////////////////////////////////////////////////////////
// TcEthernetSampleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcEthernetSampleDriver.h"
#include "TcEthernetSampleClassFactory.h"

DECLARE_GENERIC_DEVICE(TCETHERNETSAMPLEDRV)

IOSTATUS CTcEthernetSampleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcEthernetSampleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcEthernetSampleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcEthernetSampleDriver::TCETHERNETSAMPLEDRV_GetVersion( )
{
	return( (TCETHERNETSAMPLEDRV_Major << 8) | TCETHERNETSAMPLEDRV_Minor );
}

