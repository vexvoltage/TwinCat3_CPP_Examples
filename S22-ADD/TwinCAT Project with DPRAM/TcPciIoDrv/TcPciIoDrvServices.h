///////////////////////////////////////////////////////////////////////////////
// TcPciIoDrvServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_TcPciIoDrv = 0x3F000000;
#define SRVNAME_TCPCIIODRV "TcPciIoDrv"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_TcPciIoDrvCModuleDPRAM = {0x304c8854,0x7aa5,0x4c0b,{0x92,0xaa,0x87,0xa2,0x42,0xf4,0x31,0x73}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_ModuleDPRAMParameter = 0x00000001;
const PTCID PID_ModuleDPRAMPciDeviceAdi = 0x03002030;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
typedef struct _ModuleDPRAMParameter
{
	ULONG ByteOffsetInput;
	ULONG ByteOffsetOutput;
} ModuleDPRAMParameter, *PModuleDPRAMParameter;

typedef struct _ModuleDPRAMInputs
{
	ULONG Value;
} ModuleDPRAMInputs, *PModuleDPRAMInputs;

typedef struct _ModuleDPRAMOutputs
{
	ULONG Value;
} ModuleDPRAMOutputs, *PModuleDPRAMOutputs;

///</AutoGeneratedContent>



///<AutoGeneratedContent id="InterfaceIDs">
///</AutoGeneratedContent>
