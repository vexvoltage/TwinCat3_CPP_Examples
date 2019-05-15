#include "TcPch.h"
#pragma hdrstop

#include "TON.h"
#include "TONInterfaces.h"

CTON::CTON(void): m_InFlag(false), m_startTime(0)
{
}


VOID CTON::Update(ITcTask* ipTask, BOOL IN1, LONGLONG PT, BOOL& Q, LONGLONG& ET)
       {
              if (ipTask != NULL)
              {
                     if (IN1)
                     {
                           if (!m_InFlag)
                           {
                                  // Start Timer 
                                  LONGLONG sysTime = 0;
                                  if (!SUCCEEDED(ipTask->GetCurrentSysTime(&sysTime)))
                                  {
                                         m_startTime = 0;
                                  }
                                  else
                                  {
                                         m_startTime = sysTime;
                                  }
                           }
                           if (!Q)
                           {
                                  // Timer is running 
                                  LONGLONG sysTime = 0;
                                  ipTask->GetCurrentSysTime(&sysTime);

                                  ET = (sysTime - m_startTime) / 10000;

                                  if (ET >= PT)
                                  {
                                         Q = TRUE;
                                         ET = PT;
                                  }
                           }
                     }
                     else
                     {
                           // Reset everything 
                           Q = FALSE;
                           ET = 0;
                     }
                     m_InFlag = IN1;
              }
       }



