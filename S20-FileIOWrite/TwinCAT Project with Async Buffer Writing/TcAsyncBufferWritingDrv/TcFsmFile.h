#pragma once

inline BOOL FAILED_AND_NOT_PENDING(HRESULT hr) 
{
	return FAILED(hr) && (hr != ADS_E_PENDING);
}

template<typename eState>
class TTcFsmFile 
{
public:
	TTcFsmFile(); 

	HRESULT GetResult() const { return m_hrFile; }
	BOOL IsActive() const; 

protected:
	HRESULT Init
	(
		ITComObjectServer* ipSrv, 
		ITcFileAccessAsync* ipFileAccessAsync,
		eState stateError,
		eState stateFinished
	);
	VOID Deinit();

	VOID SetState(eState State); 
	VOID SetState(eState State, HRESULT hr);
	eState GetState() const { return m_State; }

	ITComObjectServerPtr  m_spSrv;
	ITcFileAccessAsyncPtr m_spFileAccessAsync;

private:
	HRESULT m_hrFile;
	eState  m_State;
	eState  m_StateError;
	eState  m_StateFinished;
};

template<typename eState>
TTcFsmFile<eState>::TTcFsmFile()
{
	m_State = static_cast<eState>(0);
	m_StateError = static_cast<eState>(0); 
	m_StateFinished = static_cast<eState>(0);
}

template<typename eState>
HRESULT TTcFsmFile<eState>::Init
(
	ITComObjectServer* ipSrv, 
	ITcFileAccessAsync* ipFileAccessAsync,
	eState stateError,
	eState stateFinished
)
{
	HRESULT hr = S_OK;
	if (ipSrv == NULL || ipFileAccessAsync==NULL)
	{
		hr = ADS_E_INVALIDPARM;
	}
	else
	{
		m_spSrv = ipSrv;
		m_spFileAccessAsync = ipFileAccessAsync;
		m_State = stateFinished;
		m_StateError = stateError;
		m_StateFinished = stateFinished;
	}
	return hr;
}

template<typename eState>
VOID TTcFsmFile<eState>::Deinit()
{
	m_spSrv = NULL;
	m_spFileAccessAsync = NULL;
}

template<typename eState>
VOID TTcFsmFile<eState>::SetState(eState State)
{
	if (State == m_StateError || State == m_StateFinished)
	{
		Deinit();
	}
	m_State = State;
}

template<typename eState>
VOID TTcFsmFile<eState>::SetState(eState State, HRESULT hr)
{
	SetState(State);
	m_hrFile = hr;
}

template<typename eState>
BOOL TTcFsmFile<eState>::IsActive() const
{
	return m_State!=m_StateError && m_State!=m_StateFinished;
}
