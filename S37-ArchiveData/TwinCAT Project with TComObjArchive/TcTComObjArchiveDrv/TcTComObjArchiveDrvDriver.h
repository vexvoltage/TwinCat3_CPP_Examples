///////////////////////////////////////////////////////////////////////////////
// TcTComObjArchiveDrvDriver.h

#ifndef __TCTCOMOBJARCHIVEDRVDRIVER_H__
#define __TCTCOMOBJARCHIVEDRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCTCOMOBJARCHIVEDRVDRV_NAME        "TCTCOMOBJARCHIVEDRV"
#define TCTCOMOBJARCHIVEDRVDRV_Major       1
#define TCTCOMOBJARCHIVEDRVDRV_Minor       0

#define DEVICE_CLASS CTcTComObjArchiveDrvDriver

#include "ObjDriver.h"

class CTcTComObjArchiveDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCTCOMOBJARCHIVEDRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCTCOMOBJARCHIVEDRVDRV)
	VxD_Service( TCTCOMOBJARCHIVEDRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCTCOMOBJARCHIVEDRVDRIVER_H__