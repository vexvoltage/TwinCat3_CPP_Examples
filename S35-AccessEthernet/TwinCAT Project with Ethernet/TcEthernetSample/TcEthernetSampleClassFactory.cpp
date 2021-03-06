///////////////////////////////////////////////////////////////////////////////
// TcEthernetSampleClassFactory.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcEthernetSampleClassFactory.h"
#include "TcEthernetSampleServices.h"
#include "ModuleARP.h"

BEGIN_CLASS_MAP(CTcEthernetSampleClassFactory)
///<AutoGeneratedContent id="ClassMap">
	CLASS_ENTRY(CID_TcEthernetSampleCModuleARP, SRVNAME_TCETHERNETSAMPLE "!CModuleARP", CModuleARP)
///</AutoGeneratedContent>
END_CLASS_MAP()

CTcEthernetSampleClassFactory::CTcEthernetSampleClassFactory() : CObjClassFactory()
{
	TcDbgUnitSetImageName(TCDBG_UNIT_IMAGE_NAME(SRVNAME_TCETHERNETSAMPLE)); 
}

