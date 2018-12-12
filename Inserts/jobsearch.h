#if !defined(AFX_JOBSEARCH_H__C00D78DE_5D65_4582_94F7_F6B693B90F0E__INCLUDED_)
#define AFX_JOBSEARCH_H__C00D78DE_5D65_4582_94F7_F6B693B90F0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// jobsearch.h : header file
//

#include "\VSSource\Inserts\Resource.h"
#include "\VSSource\Libs\DBCore\DBDataSource.h"
#include "\VSSource\Libs\DBCore\DbListDef.h"
#include "\VSSource\Libs\DBCore\DbListCtrlBase.h"
#include "\VSSource\Libs\DBCore\Db3WaySplitterScreenDef.h"

/////////////////////////////////////////////////////////////////////////////
// CJobSearch dialog

class CJobSearch : public CDialog
{
// Construction
public:
	CJobSearch(CDbDataSource *pDS = NULL, CView* pParent = NULL);   // standard constructor
	int Display(CDbDataSource *pDS, CDbListDef *pListDef);

// Dialog Data
	//{{AFX_DATA(CJobSearch)
	enum { IDD = IDD_JOBSEARCH };
	CString	m_JobKey;
	CString	m_Customer;
	CString	m_Location;
	CString	m_SalesRep;
	CString	m_SearchData;
	CString	m_SearchData2;
	CString	m_SearchField;
	CString	m_SearchOperator;
	CString	m_SearchData3;
	CString	m_SearchField3;
	CString	m_SearchOperator3;
//	CMultiSortListCtrl	m_JobCtrl;
	CDBListCtrlBase	m_JobCtrl;
	CString	m_Status;
	//}}AFX_DATA

	CDbDataSource *	m_pDS;
	CView *			m_pView;
	CDbListDef *	m_pListDef;
	CString			m_EditFormSource;
	CDb3WaySplitterScreenDef	m_EditScreenDef;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobSearch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
   virtual BOOL OnInitDialog();

// Implementation
protected:

   void load_search_fields ( CComboBox *searchFields, bool bDatesOnly );

	// Generated message map functions
	//{{AFX_MSG(CJobSearch)
	afx_msg void OnSearch();
	afx_msg void OnViewJob();
	afx_msg void OnPrintList();
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBSEARCH_H__C00D78DE_5D65_4582_94F7_F6B693B90F0E__INCLUDED_)
