///////////////////////////////////////////////////////////////////////////////
// TcPciIoDrvDriver.h

#ifndef __TCPCIIODRVDRIVER_H__
#define __TCPCIIODRVDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define TCPCIIODRVDRV_NAME        "TCPCIIODRV"
#define TCPCIIODRVDRV_Major       1
#define TCPCIIODRVDRV_Minor       0

#define DEVICE_CLASS CTcPciIoDrvDriver

#include "ObjDriver.h"

class CTcPciIoDrvDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl TCPCIIODRVDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(TCPCIIODRVDRV)
	VxD_Service( TCPCIIODRVDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __TCPCIIODRVDRIVER_H__