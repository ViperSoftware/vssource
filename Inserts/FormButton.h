#if !defined(AFX_FORMBUTTON_H__6C40DDD9_75C4_41DB_A122_39FE92DF2F9F__INCLUDED_)
#define AFX_FORMBUTTON_H__6C40DDD9_75C4_41DB_A122_39FE92DF2F9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FormButton.h : header file
//
#include "DbFormField.h"

/////////////////////////////////////////////////////////////////////////////
// CFormButton window

class CFormButton : public CButton
{
// Construction
public:
	CFormButton(CDbFormField *pField = NULL);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFormButton();

protected:
	CDbFormField *m_pField;

	// Generated message map functions
protected:
	//{{AFX_MSG(CFormButton)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMBUTTON_H__6C40DDD9_75C4_41DB_A122_39FE92DF2F9F__INCLUDED_)
