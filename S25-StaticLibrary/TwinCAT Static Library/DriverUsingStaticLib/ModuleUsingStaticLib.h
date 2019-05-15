///////////////////////////////////////////////////////////////////////////////
// ModuleUsingStaticLib.h
#pragma once

#include "DriverUsingStaticLibInterfaces.h"
#include "..\StaticLib\MultiplicationClass.h"

class CModuleUsingStaticLib 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_DriverUsingStaticLibCModuleUsingStaticLib)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CModuleUsingStaticLib();
	virtual	~CModuleUsingStaticLib();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	ModuleUsingStaticLibParameter m_Parameter;
	ModuleUsingStaticLibInputs m_Inputs;
	ModuleUsingStaticLibOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
///</AutoGeneratedContent>

	// Tracing
	CTcTrace m_Trace;

	// TODO: Custom variable
	UINT m_counter;

	MultiplicationClass mc; 
};