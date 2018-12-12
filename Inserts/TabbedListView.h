#if !defined(AFX_TABBEDLISTVIEW_H__ACC2BA24_8FE2_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_TABBEDLISTVIEW_H__ACC2BA24_8FE2_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabbedListView.h : header file
//
#include "\VSSource\Inserts\ViperView.h"

// include the Stringray toolkit
#include "\VSSource\Inserts\Stingray\ot60\ot_tabwnd.h"

/////////////////////////////////////////////////////////////////////////////
// CTabbedListView view

#define LISTCTRL_ID  1003
#define TABCTRL_ID   1002

class CTabbedListView : public CViperView
{
protected:
	CTabbedListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTabbedListView)

	CListCtrl&			GetListCtrl();
	SEC3DTabControl&	GetTabCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabbedListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTabbedListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	CListCtrl		m_ListCtrl;
	SEC3DTabControl	m_TabCtrl;

	// Generated message map functions
protected:
	//{{AFX_MSG(CTabbedListView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABBEDLISTVIEW_H__ACC2BA24_8FE2_11D3_95C5_0000C0F3C6B2__INCLUDED_)
