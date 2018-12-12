#if !defined(AFX_DBLISTVIEWER_H__94CD71E1_8E56_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_DBLISTVIEWER_H__94CD71E1_8E56_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dblistviewer.h : header file
//
#include "\VSSource\Inserts\Resource.h"
#include "\VSSource\Inserts\DbData.h"
#include "\VSSource\Libs\DBCore\DbListDef.h"
#include "\VSSource\Libs\DBCore\DbListCtrlBase.h"

/////////////////////////////////////////////////////////////////////////////
// CDbListViewer dialog

class CDbListViewer : public CDialog
{
// Construction
public:
	CDbListViewer(CWnd* pParent = NULL);   // standard constructor
	~CDbListViewer();

// Dialog Data
	//{{AFX_DATA(CDbListViewer)
	enum { IDD = IDD_DBLIST_VIEWER };  
	CDBListCtrlBase	m_DbListCtrl;
	CString	m_Select;
	CString	m_Filter;
	CString	m_Sort;
	CString	m_ListDef;
	//}}AFX_DATA

protected:
	CDbData	*			m_pDbData;
	CDbDataSource *		m_pDS;
	CDbListDefinitions *m_pListDefs;
	CDbListDef *		m_pListDef;

	// field changed flags
	BOOL	m_bSelect;
	BOOL	m_bFilter;
	BOOL	m_bSort;
	BOOL	m_bListDef;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbListViewer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	int Display(CDbData *pDbData, CDbListDefinitions *pListDefs);

protected:

	// Generated message map functions
	//{{AFX_MSG(CDbListViewer)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeFilter();
	afx_msg void OnEditchangeListdef();
	afx_msg void OnChangeSelect();
	afx_msg void OnChangeSort();
	afx_msg void OnDefineFilter();
	afx_msg void OnDefineSort();
	afx_msg void OnDefineListdef();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnEditItem();
	afx_msg void OnEditAllItems();
	afx_msg void OnNewItem();
	afx_msg void OnDeleteItem();
	afx_msg void OnPrintList();
	afx_msg LRESULT OnItemAction( WPARAM, LPARAM );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBLISTVIEWER_H__94CD71E1_8E56_11D3_95C5_0000C0F3C6B2__INCLUDED_)
