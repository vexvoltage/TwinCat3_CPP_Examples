///////////////////////////////////////////////////////////////////////////////
// SortOrderModule.h
#pragma once

#include "SortOrderInterfaces.h"

class CSortOrderModule 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_SortOrderCSortOrderModule)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CSortOrderModule();
	virtual	~CSortOrderModule();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	ULONG m_TaskSortOrderContext1Parameter;
	SortOrderModuleInputs m_Inputs;
	SortOrderModuleOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
///</AutoGeneratedContent>

	// TODO: Custom variable
	UINT m_counter;
};
