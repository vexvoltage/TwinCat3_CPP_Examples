#include <iostream>
#include <windows.h>
#include <conio.h>
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "C:\TwinCAT\AdsApi\TcAdsDll\Include\TcAdsAPI.h"

using namespace std;

void main()
{ 
  long      nErr, nPort; 
  AmsAddr   Addr; 
  PAmsAddr  pAddr = &Addr; 
  ULONG     lHdlVar1, lHdlVar2, lHdlVar3, lHdlVar4;
  //in / out
  long x = 0;
  long x2 = 0;
  long y = 0; 
  HRESULT res = S_OK;
  //buffer for concat
  char * pBothIn  = (char*)malloc(sizeof(x) + sizeof(x2));
  char * pBothOut = (char*)malloc(sizeof(res) + sizeof(y));
//Method ids to call
  char      szVar1 []={"foobar.IRpcTest#CallIn"};
  char      szVar2 []={"foobar.IRpcTest#CallInWHResult"}; 
  char      szVar3 []={"foobar.IRpcTest2#AddWOHResult"}; 
  char      szVar4 []={"foobar.IRpcTest2#AddWHResult" };

  // Open communication port on the ADS router
  nPort = AdsPortOpen();
  nErr =  AdsGetLocalAddress(pAddr);
  if (nErr) cerr << "Error: AdsGetLocalAddress: " << nErr << '\n';
  pAddr->port = 350;
  // Get the handles of methods
  nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHdlVar1), &lHdlVar1, sizeof(szVar1), szVar1);
  if (nErr) cerr << "Error: AdsSyncReadWriteReq (getHdl 1): " << nErr << '\n';
  else cerr << "OK: AdsSyncReadWriteReq (getHdl " << szVar1 << ")\n";
  nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHdlVar2), &lHdlVar2, sizeof(szVar2), szVar2);
  if (nErr) cerr << "Error: AdsSyncReadWriteReq (getHdl 2): " << nErr << '\n';
  else cerr << "OK: AdsSyncReadWriteReq (getHdl " << szVar2 << ")\n";
  nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHdlVar3), &lHdlVar3, sizeof(szVar3), szVar3);
  if (nErr) cerr << "Error: AdsSyncReadWriteReq (getHdl 3): " << nErr << '\n';
  else cerr << "OK: AdsSyncReadWriteReq (getHdl " << szVar3 << ")\n";
  nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof(lHdlVar4), &lHdlVar4, sizeof(szVar4), szVar4);
  if (nErr) cerr << "Error: AdsSyncReadWriteReq (getHdl 4): " << nErr << '\n';
  else cerr << "OK: AdsSyncReadWriteReq (getHdl " << szVar4 << ")\n";

  cerr << "\nPress key to call all methods\n";
  _getch();

  do 
  { 
	//Call 1: IRpcTest#CallIn
	cerr << "\nCalling " << szVar1 << "\n";
	nErr = AdsSyncReadWriteReq( pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar1, 0, NULL, sizeof(x), &x); 
    if (nErr) 
      cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n'; 
    else 
	{ 
		cout << "Send: " << x << '\n'; 
		x++;
	}
    cout.flush(); 

	//Call 2: IRpcTest#CallInWHResult
	cerr << "\nCalling " << szVar2 << "\n";
	nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar2, sizeof(res), &res, sizeof(x), &x);
	if (nErr)
		cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n';
    else 
	{ 
		cout << "Value given: " << x << '\n'; 
		cout << "ReturnCode: " << res << '\n'; 
	}
	cout.flush(); 

  	//Call 3: IRpcTest2#Add
	cerr << "\nCalling " << szVar3 << "\n";
	x2 = x+1;
	memcpy(pBothIn, &x, sizeof(x)); 
	memcpy(pBothIn+sizeof(x), &x2, sizeof(x2));
	nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar3, sizeof(y), &y, sizeof(x)+sizeof(x2), pBothIn);
    if (nErr) 
      cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n'; 
    else 
	{ 
		cout << "Value given A: " << x << '\n'; 
		cout << "Value given B: " << x2 << '\n'; 
		cout << "Value got (A+B): " << y << '\n'; 
	}
	cout.flush(); 

	//Call 4: IRpcTest2#AddWHResult
	cerr << "\nCalling " << szVar4 << "\n";
	memcpy(pBothIn, &x, sizeof(x));
	memcpy(pBothIn + sizeof(x), &x2, sizeof(x2));
	nErr = AdsSyncReadWriteReq(pAddr, ADSIGRP_SYM_VALBYHND, lHdlVar4, sizeof(res) + sizeof(y), pBothOut, sizeof(x) + sizeof(x2), pBothIn);
	if (nErr)
		cerr << "Error: AdsSyncReadWriteReq: " << nErr << '\n';
	else
	{
		memcpy(&res, pBothOut, sizeof(res));
		memcpy(&y, (PBYTE)pBothOut + sizeof(res), sizeof(y));
		cout << "Value given A: " << x << '\n';
		cout << "Value given B: " << x2 << '\n';

		cout << "ReturnCode: " << res << '\n';
		cout << "Value got (A+B): " << y << '\n';
	}
	cout.flush();


	cerr << "\nPress RETURN to recall all methods\n";
  }
  while ( _getch() == '\r'); 



  // Release the handle of the PLC-variable
  cerr << "\n Releasing handles \n";
  nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_RELEASEHND, 0, sizeof(lHdlVar1), &lHdlVar1);
  if (nErr) cerr << "Error: AdsSyncWriteReq (release 1): " << nErr << '\n';
  nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_RELEASEHND, 0, sizeof(lHdlVar2), &lHdlVar2); 
  if (nErr) cerr << "Error: AdsSyncWriteReq (release 2): " << nErr << '\n';
  nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_RELEASEHND, 0, sizeof(lHdlVar2), &lHdlVar3);
  if (nErr) cerr << "Error: AdsSyncWriteReq (release 3): " << nErr << '\n';
  nErr = AdsSyncWriteReq(pAddr, ADSIGRP_SYM_RELEASEHND, 0, sizeof(lHdlVar2), &lHdlVar4);
  if (nErr) cerr << "Error: AdsSyncWriteReq (release 4): " << nErr << '\n';

  // Close the communication port
  nErr = AdsPortClose(); 
  if (nErr) cerr << "Error: AdsPortClose: " << nErr << '\n';

  free(pBothIn);
  free(pBothOut);

}
