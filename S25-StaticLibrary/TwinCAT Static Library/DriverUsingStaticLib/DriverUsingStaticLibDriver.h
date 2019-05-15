///////////////////////////////////////////////////////////////////////////////
// DriverUsingStaticLibDriver.h

#ifndef __DRIVERUSINGSTATICLIBDRIVER_H__
#define __DRIVERUSINGSTATICLIBDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define DRIVERUSINGSTATICLIBDRV_NAME        "DRIVERUSINGSTATICLIB"
#define DRIVERUSINGSTATICLIBDRV_Major       1
#define DRIVERUSINGSTATICLIBDRV_Minor       0

#define DEVICE_CLASS CDriverUsingStaticLibDriver

#include "ObjDriver.h"

class CDriverUsingStaticLibDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl DRIVERUSINGSTATICLIBDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(DRIVERUSINGSTATICLIBDRV)
	VxD_Service( DRIVERUSINGSTATICLIBDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __DRIVERUSINGSTATICLIBDRIVER_H__