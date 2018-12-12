// ViperApp.h: interface for the CViperApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIPERAPP_H__A2190F01_9359_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_VIPERAPP_H__A2190F01_9359_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib, "MfcSubs.lib") // make linker search this lib


//*****************************************************************



class CViperApp : public CWinApp  
{
public:
	CViperApp();
	virtual ~CViperApp();

	CString		m_UserLoginName;
	CString		m_StationID;
	CString		m_StationName;
	CString		m_ClassName;

protected:

	bool	m_bCopyProtectionEnabled;
	bool	m_bIsEvaluationLicense;
	bool	m_bAutoUpdatePrompt;
	CString	LICENSE_FILE; 
	CString ENCRYPTION_KEY; 
	double  VERSION;
	void	EnableAutoUpdatePrompt();


	void GetCommonSettings();
	int  CheckAutoUpdate();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViperApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual LRESULT ProcessWndProcException(CException* e, const MSG* pMsg);
	//}}AFX_VIRTUAL

};

#endif // !defined(AFX_VIPERAPP_H__A2190F01_9359_11D3_95C5_0000C0F3C6B2__INCLUDED_)
