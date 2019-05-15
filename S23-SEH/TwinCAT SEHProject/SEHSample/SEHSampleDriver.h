///////////////////////////////////////////////////////////////////////////////
// SEHSampleDriver.h

#ifndef __SEHSAMPLEDRIVER_H__
#define __SEHSAMPLEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define SEHSAMPLEDRV_NAME        "SEHSAMPLE"
#define SEHSAMPLEDRV_Major       1
#define SEHSAMPLEDRV_Minor       0

#define DEVICE_CLASS CSEHSampleDriver

#include "ObjDriver.h"

class CSEHSampleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl SEHSAMPLEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(SEHSAMPLEDRV)
	VxD_Service( SEHSAMPLEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __SEHSAMPLEDRIVER_H__