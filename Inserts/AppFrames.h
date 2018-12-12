// AppFrames.h : interface of the standard App frame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(_APPFRAME_H)
#define _APPFRAME_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#pragma comment (lib, "MfcSubs.lib") // make linker search this lib

// Stingray Objective Toolkit custom status bars is used in all frames
//#include "\vssource\inserts\stingray\ot60\ot_statusbar.h"

#include "splitter.h"
#include "\VSSource\Inserts\Resource.h"


#define ACTIVE_VIEW			0
#define SPLITTER_BOTTOM     1
#define SPLITTER_TOP_LEFT   2
#define SPLITTER_TOP_RIGHT  3


class CAppFrame : public CFrameWnd
{
protected: // create from serialization only
	CAppFrame();
	DECLARE_DYNCREATE(CAppFrame)

// Attributes
public:

// Operations
public:
	BOOL SetMainMenu(UINT nID);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	CMenu * GetMainMenu();
	void StatusMessage(const char *text);
	virtual ~CAppFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	//SECCustomStatusBar	m_wndStatusBar;
	CStatusBar			m_wndStatusBar;
	CToolBar			m_wndToolBar;
	CMenu				*m_MainMenu;

// Generated message map functions
protected:
	int CheckAutoUpdate();
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg LRESULT OnViperCmdString( WPARAM , LPARAM );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CApp3WaySplitterFrame
/////////////////////////////////////////////////////////////////////////////

class CApp3WaySplitterFrame : public CAppFrame
{
protected: // create from serialization only
	CApp3WaySplitterFrame();
	DECLARE_DYNCREATE(CApp3WaySplitterFrame)

// Attributes
public:

// Operations
public:

// Overrides
	virtual CRuntimeClass *GetSplitterView(int which_one);
	CWnd *GetSplitterWnd(int which_one);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CApp3WaySplitterFrame)
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CApp3WaySplitterFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
    // Splitter Related Stuff
    C3WaySplitter	*pSPLMgr;

// Generated message map functions
protected:
	//{{AFX_MSG(CApp3WaySplitterFrame)
	afx_msg void OnClose();
	afx_msg LRESULT OnViperCmdString( WPARAM , LPARAM );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(_APPFRAME_H)
