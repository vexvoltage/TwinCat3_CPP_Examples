#pragma once

#include "TcFileAccessInterfaces.h"
#include "TcFsmFile.h"

enum eFileOpenState
{
	FileOpenError,
	FileOpenInit,
	FileOpenCheck,
	FileOpenFinished
};

class CTcFsmFileOpen : public TTcFsmFile<eFileOpenState>
{
public: 
	CTcFsmFileOpen();
	HRESULT Init
	(
		ITComObjectServer* ipSrv, 
		ITcFileAccessAsync* ipFileAccessAsync, 
		PCCH szFileName,
		TcFileAccessMode mode
	);
	HRESULT Eval();

	// output
	TcFileHandle GetFileHandle() const { return m_hFileOpen; }

private: 
	PCCH             m_szFileOpenName;
	TcFileAccessMode m_Mode;
	TcFileHandle     m_hFileOpen; 
};