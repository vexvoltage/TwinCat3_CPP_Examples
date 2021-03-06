///////////////////////////////////////////////////////////////////////////////
// TcStopWatchSampleServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_TcStopWatchSample = 0x3F000000;
#define SRVNAME_TCSTOPWATCHSAMPLE "TcStopWatchSample"


///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_TcStopWatchSampleCStopWatchModule = {0xa0fdb766,0x0c96,0x4af8,{0xa4,0xe1,0x22,0x80,0x8f,0x26,0xb2,0xf8}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
typedef struct _StopWatchModuleInputs
{
	ULONG nCount;
} StopWatchModuleInputs, *PStopWatchModuleInputs;

typedef struct _StopWatchModuleOutputs
{
	LONGLONG PentiumTimeStart;
	LONGLONG PentiumTimeStop;
	ULONGLONG PentiumTimeDiff;
	LONGLONG TaskSysTime;
	LONGLONG TaskDcTime;
	ULONG TaskCycleTime;
	ULONG TaskCpuAccountForAnotherPi;
} StopWatchModuleOutputs, *PStopWatchModuleOutputs;

typedef struct _StopWatchModuleInternalResults
{
	double Pi;
	double AnotherPi;
} StopWatchModuleInternalResults, *PStopWatchModuleInternalResults;

///</AutoGeneratedContent>
