// dao2Dlg.h : header file
//

#if !defined(_CEDITGRID)
#define _CEDITGRID

#include "..\libs\gridlib97\Daougctrl.h"
#include "..\libs\gridlib97\ugdao.h"
#include "\VSSource\Inserts\EditGridDataSource.h"

#include "\VSSource\Inserts\DbData.h"
#include "\VSSource\Inserts\resource.h"

/////////////////////////////////////////////////////////////////////////////
// CEditGrid dialog

class CEditGrid : public CDialog
{
// Construction
public:
	CEditGrid(UINT IDD = DEFAULT_IDD, CWnd* pParent = NULL);	// standard constructor
	~CEditGrid();

	CDaoUGCtrl			m_ctrl;
	CEditGridDataSource	m_dao;
	//CUGDAODataSource	m_dao;
	int					m_dataIndex;
	CString				m_SQL;
	CString				m_path;
	BOOL				m_hideHeadings;
protected:
	CString		m_Title;

// Dialog Data
	//{{AFX_DATA(CEditGrid)
	enum { DEFAULT_IDD = IDD_WORKORDER_GRID };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditGrid)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void	SetTitle(const char *title);
	int		AttachDB(CDbData *Db, const char *SQL);
	int		AttachDB(CDbDataSource *pDS);

protected:

	// Generated message map functions
	//{{AFX_MSG(CEditGrid)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	afx_msg void OnSendToParent();
	DECLARE_MESSAGE_MAP()
};

class CMemEditGrid : public CUGCtrl
{
protected:
	BOOL		m_enablePopupMenus;
public:
	CMemEditGrid();
	virtual ~CMemEditGrid();
	void	EnablePopUpMenus();

	//***** Over-ridable Notify Functions *****
	virtual void OnSetup();
	virtual int OnMenuStart(int col,long row,int section);
	virtual void OnMenuCommand(int col,long row,int section,int item);
	//mouse and key strokes
	virtual void OnLClicked(int col,long row,int updn,RECT *rect,POINT *point,int processed);
	virtual void OnRClicked(int col,long row,int updn,RECT *rect,POINT *point,int processed);
	virtual void OnDClicked(int col,long row,RECT *rect,POINT *point,BOOL processed);
	virtual void OnSH_LClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed=0);
	//virtual void OnSH_RClicked(int col,long row,int updn,RECT *rect,POINT *point,BOOL processed=0);
	//virtual void OnSH_DClicked(int col,long row,RECT *rect,POINT *point,BOOL processed=0);

};

#endif

