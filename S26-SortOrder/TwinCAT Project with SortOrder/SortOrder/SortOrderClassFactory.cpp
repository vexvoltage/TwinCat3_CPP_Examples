///////////////////////////////////////////////////////////////////////////////
// SortOrderClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "SortOrderClassFactory.h"
#include "SortOrderServices.h"
#include "SortOrderVersion.h"
#include "SortOrderModule.h"

BEGIN_CLASS_MAP(CSortOrderClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_SortOrderCSortOrderModule, SRVNAME_SORTORDER "!CSortOrderModule", CSortOrderModule)
///</AutoGeneratedContent>
END_CLASS_MAP()

CSortOrderClassFactory::CSortOrderClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_SORTORDER)); 
#if defined(TCDBG_UNIT_VERSION)
	TcDbgUnitSetVersion(TCDBG_UNIT_VERSION(SortOrder));
#endif //defined(TCDBG_UNIT_VERSION)
}

