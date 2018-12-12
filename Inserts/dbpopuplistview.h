#if !defined(AFX_DBPOPUPLISTVIEW_H__DD193281_C9C6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_DBPOPUPLISTVIEW_H__DD193281_C9C6_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dbpopuplistview.h : header file
//

// include the Stringray toolkit
#include "\VSSource\Inserts\Stingray\ot60\ot_buttons.h"
#include "\VSSource\Libs\DBCore\DAOSource.h"
#include "\VSSource\Libs\DBCore\DbListDef.h"
#include "\VSSource\Libs\DBCore\DbListCtrlBase.h"
#include "\VSSource\Libs\DBCore\Db3WaySplitterScreenDef.h"
#include "\VSSource\Inserts\Resource.h"


/////////////////////////////////////////////////////////////////////////////
// CDbPopupListView dialog

class CDbPopupListView : public CDialog
{
// Construction
public:
	CDb3WaySplitterScreenDef * GetEditScreenDef(const char *name);
	void AttachButtonMenu(int ID);
	CDbPopupListView(CWnd* pParent = NULL);   // standard constructor
	CDbPopupListView(int IDD, CWnd* pParent = NULL);   // standard constructor

	void AttachDataSource(CDbData *pDbData, CDbDataSource *pDb, CDbListDef *pLDef);
	void AttachFormSource(const char *NewForm, const char *EditForm = NULL);

// Dialog Data
	//{{AFX_DATA(CDbPopupListView)
	enum { IDD = IDD_DB_POPUP_LISTVIEW };
	CDBListCtrlBase	m_DbListCtrl;
	//}}AFX_DATA

	CString		m_Caption;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDbPopupListView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	CDbData			*m_pDbData;
	CDbDataSource	*m_pDbSource;
	CDbListDef		*m_pListDef;

	CString			m_AddFormSource;
	CString			m_EditFormSource;
	CDb3WaySplitterScreenDef	m_AddScreenDef;
	CDb3WaySplitterScreenDef	m_EditScreenDef;

	int				m_ButtonMenuID;
	CMenu			m_ButtonMenus;
	SECMenuButton	m_ActionsButton;
	SECMenuButton	m_ActivitiesButton;
	SECMenuButton	m_ReportsButton;

	// Generated message map functions
	//{{AFX_MSG(CDbPopupListView)
	virtual BOOL OnInitDialog();
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnNew();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBPOPUPLISTVIEW_H__DD193281_C9C6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
