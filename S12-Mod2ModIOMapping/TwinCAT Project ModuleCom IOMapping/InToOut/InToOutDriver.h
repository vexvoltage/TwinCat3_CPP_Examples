///////////////////////////////////////////////////////////////////////////////
// InToOutDriver.h

#ifndef __INTOOUTDRIVER_H__
#define __INTOOUTDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define INTOOUTDRV_NAME        "INTOOUT"
#define INTOOUTDRV_Major       1
#define INTOOUTDRV_Minor       0

#define DEVICE_CLASS CInToOutDriver

#include "ObjDriver.h"

class CInToOutDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl INTOOUTDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(INTOOUTDRV)
	VxD_Service( INTOOUTDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __INTOOUTDRIVER_H__