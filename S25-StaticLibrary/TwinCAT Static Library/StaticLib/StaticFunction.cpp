#include "TcPch.h"
#pragma hdrstop

#include "StaticFunction.h"

HRESULT ComputeSomething(ULONG value1, ULONG value2, ULONG& result)
{
	HRESULT hr = S_OK; 

	result = value1 + value2; 

	return hr; 
}