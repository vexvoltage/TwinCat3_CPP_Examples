///////////////////////////////////////////////////////////////////////////////
// TcDataPointerSampleDrvDriver.h

#ifndef __TCDATAPOINTERSAMPLEDRVDRIVER_H__
#define __TCDATAPOINTERSAMPLEDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCDATAPOINTERSAMPLEDRVDRV_NAME        "TCDATAPOINTERSAMPLEDRV"
#define TCDATAPOINTERSAMPLEDRVDRV_Major       1
#define TCDATAPOINTERSAMPLEDRVDRV_Minor       0

#define DEVICE_CLASS CTcDataPointerSampleDrvDriver

#include "ObjDriver.h"

class CTcDataPointerSampleDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCDATAPOINTERSAMPLEDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCDATAPOINTERSAMPLEDRVDRV)
	VxD_Service( TCDATAPOINTERSAMPLEDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCDATAPOINTERSAMPLEDRVDRIVER_H__