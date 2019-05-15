///////////////////////////////////////////////////////////////////////////////
// TcFileAsyncTestModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "TcFsmFileClose.h"
#include "TcTimeConversion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTcFsmFileClose
///////////////////////////////////////////////////////////////////////////////

CTcFsmFileClose::CTcFsmFileClose()
{
	m_hFileClose = 0;
}

HRESULT CTcFsmFileClose::Init
(
	ITComObjectServer* ipSrv, 
	ITcFileAccessAsync* ipFileAccessAsync, 
	TcFileHandle hFile
)
{
	HRESULT hr = S_OK;
	hr = TTcFsmFile::Init(ipSrv, ipFileAccessAsync, FileCloseError, FileCloseFinished); 
	if (SUCCEEDED(hr))
	{
		m_hFileClose = hFile;
		SetState(FileCloseInit, S_OK);
	}
	return hr;
}

HRESULT CTcFsmFileClose::Eval()
{
	HRESULT hr = S_OK;
	switch(GetState())
	{
	case FileCloseError:
		break;
	case FileCloseInit:
		hr = m_spFileAccessAsync->FileClose(m_hFileClose); 
		if (FAILED_AND_NOT_PENDING(hr))
		{
			SetState(FileCloseError, hr);
		}
		else 
		{
			SetState(FileCloseCheck);
		}
		break;
	case FileCloseCheck:
		hr = m_spFileAccessAsync->Check(); 
		if (FAILED_AND_NOT_PENDING(hr))
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "hFile=0x%08x, hr=0x%08x(%s) failed",
				m_hFileClose, hr, AdsGetHResultText(hr));
			SetState(FileCloseError, hr);
		}
		else if (SUCCEEDED(hr))
		{
			m_spSrv->TcReportLog(ADSLOG_MSGTYPE_LOG | ADSLOG_MSGTYPE_STRING,
				FNAMEA "hFile=0x%08x", 
				m_hFileClose);
			SetState(FileCloseFinished);
		}
		break;

	case FileCloseFinished:
		break;
	}
	return hr;
}
