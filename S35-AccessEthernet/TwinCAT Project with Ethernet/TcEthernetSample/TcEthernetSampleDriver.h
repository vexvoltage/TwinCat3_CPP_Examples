///////////////////////////////////////////////////////////////////////////////
// TcEthernetSampleDriver.h

#ifndef __TCETHERNETSAMPLEDRIVER_H__
#define __TCETHERNETSAMPLEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCETHERNETSAMPLEDRV_NAME        "TCETHERNETSAMPLE"
#define TCETHERNETSAMPLEDRV_Major       1
#define TCETHERNETSAMPLEDRV_Minor       0

#define DEVICE_CLASS CTcEthernetSampleDriver

#include "ObjDriver.h"

class CTcEthernetSampleDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCETHERNETSAMPLEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCETHERNETSAMPLEDRV)
	VxD_Service( TCETHERNETSAMPLEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCETHERNETSAMPLEDRIVER_H__