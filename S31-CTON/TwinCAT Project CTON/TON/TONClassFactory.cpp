///////////////////////////////////////////////////////////////////////////////
// TONClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TONClassFactory.h"
#include "TONServices.h"
#include "TONVersion.h"
#include "Module1.h"

BEGIN_CLASS_MAP(CTONClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_TONCModule1, SRVNAME_TON "!CModule1", CModule1)
///</AutoGeneratedContent>
END_CLASS_MAP()

CTONClassFactory::CTONClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_TON)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(TON));
#endif //defined(TCDBG_UNIT_VERSION)
}

