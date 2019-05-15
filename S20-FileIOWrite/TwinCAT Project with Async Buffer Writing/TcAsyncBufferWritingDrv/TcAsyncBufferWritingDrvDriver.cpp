///////////////////////////////////////////////////////////////////////////////
// TcAsyncBufferWritingDrvDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcAsyncBufferWritingDrvDriver.h"
#include "TcAsyncBufferWritingDrvClassFactory.h"

DECLARE_GENERIC_DEVICE(TCASYNCBUFFERWRITINGDRVDRV)

IOSTATUS CTcAsyncBufferWritingDrvDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcAsyncBufferWritingDrvClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcAsyncBufferWritingDrvDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcAsyncBufferWritingDrvDriver::TCASYNCBUFFERWRITINGDRVDRV_GetVersion( )
{
	return( (TCASYNCBUFFERWRITINGDRVDRV_Major << 8) | TCASYNCBUFFERWRITINGDRVDRV_Minor );
}

