///////////////////////////////////////////////////////////////////////////////
// TcStopWatchSampleDriver.h

#ifndef __TCSTOPWATCHSAMPLEDRIVER_H__
#define __TCSTOPWATCHSAMPLEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCSTOPWATCHSAMPLEDRV_NAME        "TCSTOPWATCHSAMPLE"
#define TCSTOPWATCHSAMPLEDRV_Major       1
#define TCSTOPWATCHSAMPLEDRV_Minor       0

#define DEVICE_CLASS CTcStopWatchSampleDriver

#include "ObjDriver.h"

class CTcStopWatchSampleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCSTOPWATCHSAMPLEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCSTOPWATCHSAMPLEDRV)
	VxD_Service( TCSTOPWATCHSAMPLEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCSTOPWATCHSAMPLEDRIVER_H__