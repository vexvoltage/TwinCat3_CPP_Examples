///////////////////////////////////////////////////////////////////////////////
// TcPciIoDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcPciIoDrvDriver.h"
#include "TcPciIoDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCPCIIODRVDRV)

IOSTATUS CTcPciIoDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcPciIoDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcPciIoDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcPciIoDrvDriver::TCPCIIODRVDRV_GetVersion( )
{
	return( (TCPCIIODRVDRV_Major << 8) | TCPCIIODRVDRV_Minor );
}

