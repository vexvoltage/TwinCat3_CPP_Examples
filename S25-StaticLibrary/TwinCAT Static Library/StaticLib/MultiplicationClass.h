#pragma once
#include "StaticLibInterfaces.h"

class MultiplicationClass :
	public ISampleInterface
{
public:

	DECLARE_IUNKNOWN() 

	MultiplicationClass(void);

	~MultiplicationClass(void);
	
	HRESULT TCOMAPI SampleMultiplicationMethod(ULONG Parameter1, ULONG Parameter2, ULONG& Parameter3);
};

