///////////////////////////////////////////////////////////////////////////////
// TcFileTestDrvDriver.h

#ifndef __TCFILETESTDRVDRIVER_H__
#define __TCFILETESTDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCFILETESTDRVDRV_NAME        "TCFILETESTDRV"
#define TCFILETESTDRVDRV_Major       1
#define TCFILETESTDRVDRV_Minor       0

#define DEVICE_CLASS CTcFileTestDrvDriver

#include "ObjDriver.h"

class CTcFileTestDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCFILETESTDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCFILETESTDRVDRV)
	VxD_Service( TCFILETESTDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCFILETESTDRVDRIVER_H__