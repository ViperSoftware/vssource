#if !defined(AFX_PRINTDOCPREVIEW_H__C8BCA264_4710_4BEC_AA26_CE82A47026FE__INCLUDED_)
#define AFX_PRINTDOCPREVIEW_H__C8BCA264_4710_4BEC_AA26_CE82A47026FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <AFXPriv.h>
// _MSC_VER > 1000
// printdocpreview.h : header file
//
#include "\VSSource\inserts\printlib.h"

/////////////////////////////////////////////////////////////////////////////
// CPrintDocPreview view

class CPrintDocPreview : public CPreviewView
{
friend class CPrintDocFrame;
protected:
	CPrintDocPreview();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPrintDocPreview)

	CPrintDoc *			m_pPrintDoc;

	virtual void OnDisplayPageNumber(UINT nPage, UINT nPagesDisplayed);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintDocPreview)
	public:
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPrintDocPreview();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CPrintDocPreview)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPreviewPrint();
	afx_msg void OnPreviewClose();
	afx_msg void OnFilePrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTDOCPREVIEW_H__C8BCA264_4710_4BEC_AA26_CE82A47026FE__INCLUDED_)
