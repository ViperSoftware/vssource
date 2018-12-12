// ErrorLog.h: interface for the CErrorLog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ERRORLOG_H__268F60C4_F956_11D2_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_ERRORLOG_H__268F60C4_F956_11D2_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <io.h>

class CErrorLog  
{
public:
	void	SetCaption(const char *Caption);
	void	SetPath(const char *path, int clear);
	void	SetDisplayOnDestroy(int display);
	FILE *	GetFp();
	void	DisplayErrorLog();
	CErrorLog();
	CErrorLog(const char *path, int clear, int display);
	virtual ~CErrorLog();

protected:
	BOOL	m_bCaptionPrinted;
	BOOL	m_bClear;
	BOOL	m_bDisplay;
	CString m_Caption;
	CString m_Path;
	FILE *	m_fpLog;
};

#endif // !defined(AFX_ERRORLOG_H__268F60C4_F956_11D2_95C5_0000C0F3C6B2__INCLUDED_)
