///////////////////////////////////////////////////////////////////////////////
// TcAccessCoESdoViaAdsDrvDriver.h

#ifndef __TCACCESSCOESDOVIAADSDRVDRIVER_H__
#define __TCACCESSCOESDOVIAADSDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCACCESSCOESDOVIAADSDRVDRV_NAME        "TCACCESSCOESDOVIAADSDRV"
#define TCACCESSCOESDOVIAADSDRVDRV_Major       1
#define TCACCESSCOESDOVIAADSDRVDRV_Minor       0

#define DEVICE_CLASS CTcAccessCoESdoViaAdsDrvDriver

#include "ObjDriver.h"

class CTcAccessCoESdoViaAdsDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCACCESSCOESDOVIAADSDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCACCESSCOESDOVIAADSDRVDRV)
	VxD_Service( TCACCESSCOESDOVIAADSDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCACCESSCOESDOVIAADSDRVDRIVER_H__