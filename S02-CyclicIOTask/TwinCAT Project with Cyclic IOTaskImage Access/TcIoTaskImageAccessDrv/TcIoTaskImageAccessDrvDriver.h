///////////////////////////////////////////////////////////////////////////////
// TcIoTaskImageAccessDrvDriver.h

#ifndef __TCIOTASKIMAGEACCESSDRVDRIVER_H__
#define __TCIOTASKIMAGEACCESSDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCIOTASKIMAGEACCESSDRVDRV_NAME        "TCIOTASKIMAGEACCESSDRV"
#define TCIOTASKIMAGEACCESSDRVDRV_Major       1
#define TCIOTASKIMAGEACCESSDRVDRV_Minor       0

#define DEVICE_CLASS CTcIoTaskImageAccessDrvDriver

#include "ObjDriver.h"

class CTcIoTaskImageAccessDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCIOTASKIMAGEACCESSDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCIOTASKIMAGEACCESSDRVDRV)
	VxD_Service( TCIOTASKIMAGEACCESSDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCIOTASKIMAGEACCESSDRVDRIVER_H__