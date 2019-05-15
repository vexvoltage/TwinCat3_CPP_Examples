///////////////////////////////////////////////////////////////////////////////
// ModuleDataWrite.h
#pragma once

#include "TcConcurrentDADrvInterfaces.h"

class CModuleDataWrite 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_TcConcurrentDADrvCModuleDataWrite)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CModuleDataWrite();
	virtual	~CModuleDataWrite();


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
	ULONG m_DataWriteCounterModulo;
	ModuleDataWriteWrite m_Write;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	IDataWritePtr m_spDataWrite;
///</AutoGeneratedContent>

	// Tracing
	CTcTrace m_Trace;

	// TODO: Custom variable
	UINT m_counter;
};
