// TcPch.h : include file for TwinCAT standard include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#pragma once

#include "TcDef.h"

#if defined(TC_ENVIROMENT_UM) || defined(TC_ENVIROMENT_CE)
#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
#endif //WIN32_RUNTIME

#include "TcBase.h"
#include "TcError.h"
#include "OsBase.h"
