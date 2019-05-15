///////////////////////////////////////////////////////////////////////////////
// TcFileAsyncTestModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcFsmFileOpen.h"
#include "TcTimeConversion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTcFsmFileOpen
///////////////////////////////////////////////////////////////////////////////

CTcFsmFileOpen::CTcFsmFileOpen()
{
	m_spSrv = NULL;
	m_spFileAccessAsync = NULL;

}

HRESULT CTcFsmFileOpen::Init
(
	ITComObjectServer* ipSrv, 
	ITcFileAccessAsync* ipFileAccessAsync, 
	PCCH szFileName,
	TcFileAccessMode mode
)
{
	HRESULT hr = S_OK;
	hr = TTcFsmFile::Init(ipSrv, ipFileAccessAsync, FileOpenError, FileOpenFinished); 
	if (SUCCEEDED(hr))
	{
		m_szFileOpenName = szFileName;
		m_Mode = mode;
		m_hFileOpen = 0;
		SetState(FileOpenInit, S_OK);
	}
	return hr;
}

HRESULT CTcFsmFileOpen::Eval()
{
	HRESULT hr = S_OK;
	switch(GetState())
	{
	case FileOpenError:
		break;
	case FileOpenInit:
		hr = m_spFileAccessAsync->FileOpen(m_szFileOpenName, m_Mode, &m_hFileOpen); 
		if (FAILED_AND_NOT_PENDING(hr))
		{
			SetState(FileOpenError, hr);
		}
		else
		{
			SetState(FileOpenCheck);
		}
		break;
	case FileOpenCheck:
		hr = m_spFileAccessAsync->Check(); 
		if (FAILED_AND_NOT_PENDING(hr))
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "szFilename=%s, hr=0x%08x(%s) failed",
				m_szFileOpenName, hr, AdsGetHResultText(hr));
			SetState(FileOpenError, hr); 
		}
		else if (SUCCEEDED(hr))
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "szFilename=%s, m_hFileOpen=0x%08x",
				m_szFileOpenName, m_hFileOpen);
			SetState(FileOpenFinished);
		}
		break;

	case FileOpenFinished:
		break;
	}
	return hr;
}
