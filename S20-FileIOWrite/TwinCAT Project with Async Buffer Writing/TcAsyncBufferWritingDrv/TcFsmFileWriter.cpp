///////////////////////////////////////////////////////////////////////////////
// TcFileAsyncTestModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcFsmFileWriter.h"
#include "TcTimeConversion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTcFsmFileWriter
///////////////////////////////////////////////////////////////////////////////

CTcFsmFileWriter::CTcFsmFileWriter()
{
	m_szFilename = NULL;
	m_hFileWriter = 0;
	m_pFileWriterBuffer = NULL;
	m_nFileWriterBuffer = 0; 
	m_nBytesWrittenTotal = 0;
}

HRESULT CTcFsmFileWriter::Init
(
	ITComObjectServer* ipSrv, 
	ITcFileAccessAsync* ipFileAccessAsync, 
	PCCH szFilename, 
	PBYTE pBuffer, 
	ULONG nBuffer
)
{
	HRESULT hr = S_OK;
	hr = TTcFsmFile::Init(ipSrv, ipFileAccessAsync, FileWriterError, FileWriterFinished); 
	if (SUCCEEDED(hr))
	{
		m_szFilename = szFilename; 
		m_hFileWriter = 0; 

		m_pFileWriterBuffer = pBuffer;
		m_nFileWriterBuffer = nBuffer;

		SetState(FileWriterOpen, S_OK);
	}
	return hr;
}

HRESULT CTcFsmFileWriter::Eval()
{
	HRESULT hr = S_OK;

	switch (GetState())
	{
	case FileWriterError:
		break;
	case FileWriterOpen:
		if (!m_fsmFileOpen.IsActive())
		{
			hr = m_fsmFileOpen.Init(m_spSrv, m_spFileAccessAsync, m_szFilename, static_cast<TcFileAccessMode>(amBinary | amAppend));
			if (FAILED(hr))
			{
				SetState(FileWriterError, hr);
			}
		}
		else
		{
			hr = m_fsmFileOpen.Eval();
			if (FAILED_AND_NOT_PENDING(hr))
			{
				SetState(FileWriterError, hr);
			}
			else if (SUCCEEDED(hr))
			{
				m_hFileWriter = m_fsmFileOpen.GetFileHandle();
				SetState(FileWriterWrite);
			}
		}
		break;
	case FileWriterWrite:
		if (!m_fsmFileWrite.IsActive())
		{
			hr = m_fsmFileWrite.Init(m_spSrv, m_spFileAccessAsync, m_hFileWriter, m_pFileWriterBuffer, m_nFileWriterBuffer);
			if (FAILED(hr))
			{
				SetState(FileWriterErrorCleanup, hr); 
			}
		}
		else
		{
			hr = m_fsmFileWrite.Eval();
			if (FAILED_AND_NOT_PENDING(hr))
			{
				SetState(FileWriterErrorCleanup, hr); 
			}
			else if (SUCCEEDED(hr))
			{
				m_nBytesWrittenTotal+=m_fsmFileWrite.GetFileWriteActually();
				SetState(FileWriterClose); 
			}
		}
		break;
	case FileWriterClose:
		if (m_hFileWriter == 0)
		{
			SetState(FileWriterFinished); 
		}
		else
		{
			if (!m_fsmFileClose.IsActive())
			{
				hr = m_fsmFileClose.Init(m_spSrv, m_spFileAccessAsync, m_hFileWriter);
				if (FAILED(hr))
				{
					SetState(FileWriterError, hr);
				}
			}
			else
			{
				hr = m_fsmFileClose.Eval();
				if (FAILED_AND_NOT_PENDING(hr))
				{
					SetState(FileWriterError, hr);
				}
				else if (SUCCEEDED(hr))
				{
					m_hFileWriter = 0;
					SetState(FileWriterFinished);
				}
			}
		}
		break;
	case FileWriterErrorCleanup:
		if (!m_fsmFileClose.IsActive())
		{
			hr = m_fsmFileClose.Init(m_spSrv, m_spFileAccessAsync, m_hFileWriter);
			if (FAILED(hr))
			{
				SetState(FileWriterError, hr);
			}
		}
		else
		{
			hr = m_fsmFileClose.Eval();
			if (FAILED_AND_NOT_PENDING(hr))
			{
				SetState(FileWriterError, hr);
			}
			else if (SUCCEEDED(hr))
			{
				m_hFileWriter = 0;
				SetState(FileWriterError);
			}
		}
		break;
	case FileWriterFinished:
		break; 
	}

	return hr;
}
