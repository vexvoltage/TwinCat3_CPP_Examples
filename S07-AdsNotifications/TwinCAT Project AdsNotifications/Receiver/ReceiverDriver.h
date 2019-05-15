///////////////////////////////////////////////////////////////////////////////
// ReceiverDriver.h

#ifndef __RECEIVERDRIVER_H__
#define __RECEIVERDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define RECEIVERDRV_NAME        "RECEIVER"
#define RECEIVERDRV_Major       1
#define RECEIVERDRV_Minor       0

#define DEVICE_CLASS CReceiverDriver

#include "ObjDriver.h"

class CReceiverDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl RECEIVERDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(RECEIVERDRV)
	VxD_Service( RECEIVERDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __RECEIVERDRIVER_H__