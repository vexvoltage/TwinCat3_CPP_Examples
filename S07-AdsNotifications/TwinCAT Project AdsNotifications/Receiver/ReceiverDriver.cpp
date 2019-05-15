///////////////////////////////////////////////////////////////////////////////
// ReceiverDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ReceiverDriver.h"
#include "ReceiverClassFactory.h"

DECLARE_GENERIC_DEVICE(RECEIVERDRV)

IOSTATUS CReceiverDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CReceiverClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CReceiverDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CReceiverDriver::RECEIVERDRV_GetVersion( )
{
	return( (RECEIVERDRV_Major << 8) | RECEIVERDRV_Minor );
}

