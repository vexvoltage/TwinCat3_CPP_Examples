///////////////////////////////////////////////////////////////////////////////
// SortOrderDriver.h

#ifndef __SORTORDERDRIVER_H__
#define __SORTORDERDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define SORTORDERDRV_NAME        "SORTORDER"
#define SORTORDERDRV_Major       1
#define SORTORDERDRV_Minor       0

#define DEVICE_CLASS CSortOrderDriver

#include "ObjDriver.h"

class CSortOrderDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl SORTORDERDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(SORTORDERDRV)
	VxD_Service( SORTORDERDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __SORTORDERDRIVER_H__