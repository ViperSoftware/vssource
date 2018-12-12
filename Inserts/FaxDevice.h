// FaxDevice.h: interface for the CFaxDevice class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FAXDEVICE_H__28378F89_8563_4877_A046_FEDE36498880__INCLUDED_)
#define AFX_FAXDEVICE_H__28378F89_8563_4877_A046_FEDE36498880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFaxDevice  
{
public:
	int AddAttachment(const char *path);
	CFaxDevice();
	virtual ~CFaxDevice();

	virtual int Reset();
	virtual int Disconnect() = 0;
	virtual int Connect() = 0;
	virtual int SendFax() = 0;

	CString		m_FirstName;
	CString		m_LastName;
	CString		m_Company;
	CString		m_Dept;
	CString		m_FaxNum;
	CString		m_VoiceNum;
	CString		m_Email;
	CString		m_BodyText;
	CString		m_Subject;
	int				m_NumAttachments;
	CStringArray	m_Attachments;

};


class CFaxMakerDevice : public CFaxDevice  
{
public:
	CFaxMakerDevice();
	virtual ~CFaxMakerDevice();

	virtual int Reset();
	virtual int Disconnect();
	virtual int Connect();
	virtual int SendFax();

protected:
	COleDispatchDriver	m_Dispatch;
	CLSID 				m_XLclsid;

	BOOL	GetDispID(LPTSTR pstrName, DISPID* pdisp, LPDISPATCH lpDisp = NULL);

};

#endif // !defined(AFX_FAXDEVICE_H__28378F89_8563_4877_A046_FEDE36498880__INCLUDED_)
