#pragma once

#include "TcFileAccessInterfaces.h"
#include "TcFsmFile.h"
#include "TcFsmFileOpen.h"
#include "TcFsmFileWrite.h"
#include "TcFsmFileClose.h"


enum eStateFileWriter
{
	FileWriterError,
	FileWriterOpen,
	FileWriterWrite,
	FileWriterClose,
	FileWriterErrorCleanup,
	FileWriterFinished
};

class CTcFsmFileWriter : public TTcFsmFile<eStateFileWriter>
{
public: 
	CTcFsmFileWriter();
	HRESULT Init
	(
		ITComObjectServer* ipSrv, 
		ITcFileAccessAsync* ipFileAccessAsync, 
		PCCH szFilename, 
		PBYTE pBuffer, 
		ULONG nBuffer
	);
	HRESULT Eval();

	ULONG GetBytesWrittenTotal() { return m_nBytesWrittenTotal; }

private: 
	PCCH         m_szFilename;
	TcFileHandle m_hFileWriter;
	PBYTE        m_pFileWriterBuffer;
	ULONG        m_nFileWriterBuffer; 
	ULONG        m_nBytesWrittenTotal;

	CTcFsmFileOpen  m_fsmFileOpen;
	CTcFsmFileWrite m_fsmFileWrite;
	CTcFsmFileClose m_fsmFileClose;
};