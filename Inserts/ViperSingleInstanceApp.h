// ViperSingleInstanceApp.h: interface for the CViperSingleInstanceApp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIPERSINGLEINSTANCEAPP_H__1E15F86B_6038_4C23_8F44_192E30130769__INCLUDED_)
#define AFX_VIPERSINGLEINSTANCEAPP_H__1E15F86B_6038_4C23_8F44_192E30130769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViperApp.h"

class CViperSingleInstanceApp : public CViperApp  
{
public:
	BOOL FirstInstance();
	void SetAppClassName(const char *name);
	CViperSingleInstanceApp();
	virtual ~CViperSingleInstanceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViperSingleInstanceApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

};

#endif // !defined(AFX_VIPERSINGLEINSTANCEAPP_H__1E15F86B_6038_4C23_8F44_192E30130769__INCLUDED_)
