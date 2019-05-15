#pragma once

#include "TONInterfaces.h"

class CTON
{
public:
	CTON::CTON(void);
	VOID CTON::Update(ITcTask*, BOOL , LONGLONG, BOOL& , LONGLONG& );

private:
       BOOL m_InFlag;
       LONGLONG m_startTime;
};

