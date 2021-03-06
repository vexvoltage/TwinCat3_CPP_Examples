///////////////////////////////////////////////////////////////////////////////
// TcAsyncBufferWritingModule.h
#pragma once

#include "TcIoInterfaces.h"
#include "TcAsyncBufferWritingDrvServices.h"
#include "TcAsyncBufferWritingDrvInterfaces.h"

#include "TcFileAccessInterfaces.h"
#include "TcFsmFileWriter.h"

#define ASYNCWRITE_BUFFERSIZE 500

///////////////////////////////////////////////////////////////////////////////
// CTcAsyncBufferWritingModule has two buffers (m_Buffer1, m_Buffer2),
// which are filled with current data alternately. The member m_pBufferFill 
// points to the current fill buffer. If a buffer is completely filled, then
// the member m_pBufferWrite is set such that it points to the filled buffer. 
// This data is written to a file using the TcFsmFileWriter. 
class CTcAsyncBufferWritingModule 
	: public ITComObject
	, public ITcADI
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST(CID_TcAsyncBufferWritingDrvCTcAsyncBufferWritingModule)
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_OBJDATAAREA_MAP()
	DECLARE_ITCADI()

	CTcAsyncBufferWritingModule();

	virtual	~CTcAsyncBufferWritingModule();

///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

///<AutoGeneratedContent id="Members">
	TcAsyncBufferWritingModuleParameter m_Parameter;
	TcAsyncBufferWritingModuleInputs m_Inputs;
	TcAsyncBufferWritingModuleOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
///</AutoGeneratedContent>

	BOOL FillBuffer
	(
		float* pBuffer, 
		UINT nBuffer, 
		UINT& nBufferIndex
	);


	UINT m_counter;
	

	float m_Buffer1[ASYNCWRITE_BUFFERSIZE];
	float m_Buffer2[ASYNCWRITE_BUFFERSIZE];

	float* m_pBufferFill;
	UINT   m_nBufferFillIndex;
	float* m_pBufferWrite;

	ITcFileAccessAsyncPtr m_spFileAccessAsync; 
	
	CTcFsmFileWriter m_fsmFileWriter;
};
