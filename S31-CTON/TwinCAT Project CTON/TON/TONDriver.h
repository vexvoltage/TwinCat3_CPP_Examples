///////////////////////////////////////////////////////////////////////////////
// TONDriver.h

#ifndef __TONDRIVER_H__
#define __TONDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TONDRV_NAME        "TON"
#define TONDRV_Major       1
#define TONDRV_Minor       0

#define DEVICE_CLASS CTONDriver

#include "ObjDriver.h"

class CTONDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TONDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TONDRV)
	VxD_Service( TONDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TONDRIVER_H__