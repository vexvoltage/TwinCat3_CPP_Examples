///////////////////////////////////////////////////////////////////////////////
// TcAsyncBufferWritingDrvDriver.h

#ifndef __TCASYNCBUFFERWRITINGDRVDRIVER_H__
#define __TCASYNCBUFFERWRITINGDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCASYNCBUFFERWRITINGDRVDRV_NAME        "TCASYNCBUFFERWRITINGDRV"
#define TCASYNCBUFFERWRITINGDRVDRV_Major       1
#define TCASYNCBUFFERWRITINGDRVDRV_Minor       0

#define DEVICE_CLASS CTcAsyncBufferWritingDrvDriver

#include "ObjDriver.h"

class CTcAsyncBufferWritingDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCASYNCBUFFERWRITINGDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCASYNCBUFFERWRITINGDRVDRV)
	VxD_Service( TCASYNCBUFFERWRITINGDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCASYNCBUFFERWRITINGDRVDRIVER_H__