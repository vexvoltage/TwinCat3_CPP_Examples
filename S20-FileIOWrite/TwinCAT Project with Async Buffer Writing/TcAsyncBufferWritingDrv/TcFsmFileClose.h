#pragma once

#include "TcFileAccessInterfaces.h"
#include "TcFsmFile.h"

enum eFileCloseState
{
	FileCloseError,
	FileCloseInit,
	FileCloseCheck,
	FileCloseFinished
};

class CTcFsmFileClose : public TTcFsmFile<eFileCloseState>
{
public: 
	CTcFsmFileClose();
	HRESULT Init
	(
		ITComObjectServer* ipSrv, 
		ITcFileAccessAsync* ipFileAccessAsync, 
		TcFileHandle hFile
	);
	HRESULT Eval();

private: 
	TcFileHandle m_hFileClose;
};