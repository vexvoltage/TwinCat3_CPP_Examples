///////////////////////////////////////////////////////////////////////////////
// TcConcurrentDADrvDriver.h

#ifndef __TCCONCURRENTDADRVDRIVER_H__
#define __TCCONCURRENTDADRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCCONCURRENTDADRVDRV_NAME        "TCCONCURRENTDADRV"
#define TCCONCURRENTDADRVDRV_Major       1
#define TCCONCURRENTDADRVDRV_Minor       0

#define DEVICE_CLASS CTcConcurrentDADrvDriver

#include "ObjDriver.h"

class CTcConcurrentDADrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCCONCURRENTDADRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCCONCURRENTDADRVDRV)
	VxD_Service( TCCONCURRENTDADRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCCONCURRENTDADRVDRIVER_H__