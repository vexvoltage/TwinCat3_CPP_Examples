#include "TcPch.h"
#pragma hdrstop

#include "MultiplicationClass.h"


IMPLEMENT_IUNKNOWN()

BEGIN_INTERFACE_MAP(MultiplicationClass)
	INTERFACE_ENTRY(IID_ITcUnknown, ITcUnknown)
END_INTERFACE_MAP()

MultiplicationClass::MultiplicationClass(void)
{
}


MultiplicationClass::~MultiplicationClass(void)
{
}

HRESULT TCOMAPI MultiplicationClass::SampleMultiplicationMethod(ULONG Parameter1, ULONG Parameter2, ULONG& Parameter3) 
{

	Parameter3 = Parameter1 * Parameter2;
	return S_OK;

}
