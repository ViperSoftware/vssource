#if !defined(AFX_PRINTDOCFRAME_H__F3606F90_BA73_4507_9A87_1414CE295986__INCLUDED_)
#define AFX_PRINTDOCFRAME_H__F3606F90_BA73_4507_9A87_1414CE295986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// printdocframe.h : header file
//

#include "\VSSource\Inserts\Resource.h"
#include "\VSSource\inserts\printdocpreview.h"

/////////////////////////////////////////////////////////////////////////////
// CPrintDocFrame frame

class CPrintDocFrame : public CFrameWnd
{
public:
	CPrintDocFrame(CPrintDoc *pPDoc = NULL);           // protected constructor used by dynamic creation

protected:
	CPrintDocPreview *	m_pView;
	CPrintDoc *			m_pPrintDoc;

	int				m_CloseReturnValue;
	BOOL			m_bRunningModal;

// Attributes
public:
	int		GoModal();
	virtual ~CPrintDocFrame();

// Operations
public:
	void Create();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintDocFrame)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintDocFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnSysCommand(UINT nID, LPARAM);
	//}}AFX_MSG
	afx_msg LRESULT OnClosePopup( WPARAM, LPARAM );
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTDOCFRAME_H__F3606F90_BA73_4507_9A87_1414CE295986__INCLUDED_)
