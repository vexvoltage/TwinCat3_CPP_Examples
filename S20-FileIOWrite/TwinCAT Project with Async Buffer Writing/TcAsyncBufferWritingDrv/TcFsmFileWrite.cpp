///////////////////////////////////////////////////////////////////////////////
// TcFileAsyncTestModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcFsmFileWrite.h"
#include "TcTimeConversion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTcFsmFileWrite
///////////////////////////////////////////////////////////////////////////////

CTcFsmFileWrite::CTcFsmFileWrite()
{
	m_hFileWrite = 0;
	memset(&m_pFileWriteBuffer, 0, sizeof(m_pFileWriteBuffer));
	//m_pFileWriteBuffer = NULL;
	m_nFileWriteBuffer = 0; 
	m_nFileWriteActually = 0;
}

HRESULT CTcFsmFileWrite::Init
(
	ITComObjectServer* ipSrv, 
	ITcFileAccessAsync* ipFileAccessAsync,
	TcFileHandle hFileWrite, 
	PBYTE pFileWriteBuffer, 
	ULONG nFileWriteBuffer
)
{
	HRESULT hr = S_OK;
	hr = TTcFsmFile::Init(ipSrv, ipFileAccessAsync, FileWriteError, FileWriteFinished); 
	m_hFileWrite = hFileWrite;
	m_pFileWriteBuffer = pFileWriteBuffer;
	m_nFileWriteBuffer = nFileWriteBuffer;
	m_nFileWriteActually = 0;
	SetState(FileWriteInit, S_OK);
	return hr;
}

HRESULT CTcFsmFileWrite::Eval()
{
	HRESULT hr = S_OK;
	switch(GetState())
	{
	case FileWriteError:
		break;
	case FileWriteInit:
		hr = m_spFileAccessAsync->FileWrite(m_hFileWrite, m_pFileWriteBuffer, m_nFileWriteBuffer, &m_nFileWriteActually);
		if (FAILED_AND_NOT_PENDING(hr))
		{
			SetState(FileWriteError, hr);
		}
		else 
		{
			SetState(FileWriteCheck);
		}
		break;
	case FileWriteCheck:
		hr = m_spFileAccessAsync->Check();
		if (FAILED(hr) && hr!=ADS_E_PENDING)
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "hFileWrite=0x%08x, hr=0x%08x(%s) failed",
				m_hFileWrite, hr, AdsGetHResultText(hr));
			SetState(FileWriteError, hr); 
		}
		else if (SUCCEEDED(hr))
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "hFileWrite=0x%08x, nFileWriteActually=%d",
				m_hFileWrite, m_nFileWriteActually);
			SetState(FileWriteFinished);
		}
		break;
	case FileWriteFinished:
		break;
	}
	return hr;
}
