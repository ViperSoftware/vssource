#if !defined(AFX_WorkOrderGantt_H__C1294361_09D4_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_WorkOrderGantt_H__C1294361_09D4_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WorkOrderGantt.h : header file
//
#include "\VSSource\Libs\DbCore\DbDataSource.h"
#include "\VSSource\Inserts\Stingray\oc60\ochart.h"

/////////////////////////////////////////////////////////////////////////////
// CWorkOrderGantt dialog

class CWorkOrderGantt : public CDialog
{
// Construction
public:
	CWorkOrderGantt(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkOrderGantt)
	enum { IDD = 132 };  // IDD_WORKORDER_GANTT
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CDbDataSource * m_pDBSource;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkOrderGantt)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	//SREGraphView*  m_pView;
	SREScrollView* m_pView;
	SRGraph        m_Graph;

	// Generated message map functions
	//{{AFX_MSG(CWorkOrderGantt)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPrint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WorkOrderGantt_H__C1294361_09D4_11D3_95C5_0000C0F3C6B2__INCLUDED_)
