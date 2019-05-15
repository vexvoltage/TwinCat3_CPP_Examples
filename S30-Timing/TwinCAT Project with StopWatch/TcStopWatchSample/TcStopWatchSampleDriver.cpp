///////////////////////////////////////////////////////////////////////////////
// TcStopWatchSampleDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcStopWatchSampleDriver.h"
#include "TcStopWatchSampleClassFactory.h"

DECLARE_GENERIC_DEVICE(TCSTOPWATCHSAMPLEDRV)

IOSTATUS CTcStopWatchSampleDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CTcStopWatchSampleClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CTcStopWatchSampleDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CTcStopWatchSampleDriver::TCSTOPWATCHSAMPLEDRV_GetVersion( )
{
	return( (TCSTOPWATCHSAMPLEDRV_Major << 8) | TCSTOPWATCHSAMPLEDRV_Minor );
}

