#if !defined(AFX_VIPERVIEW_H__BB04BA62_1800_4A0B_8D21_573E9038B3FB__INCLUDED_)
#define AFX_VIPERVIEW_H__BB04BA62_1800_4A0B_8D21_573E9038B3FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// viperview.h : header file
//
#include "\VSSource\Inserts\PrintLib.h"

/////////////////////////////////////////////////////////////////////////////
// CViperView view

class CViperView : public CView
{
protected:
	CViperView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CViperView)

// Attributes
public:

// Operations
public:

	void AttachPrintDoc(CPrintDoc *printDoc);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViperView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CViperView();

	CPrintDoc			*m_pPrintDoc;		// attached printing doc object

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CViperView)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg LRESULT OnAttachPrintDoc( WPARAM, LPARAM );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIPERVIEW_H__BB04BA62_1800_4A0B_8D21_573E9038B3FB__INCLUDED_)
