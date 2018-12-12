// WorkOrder.h: interface for the CWorkOrder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(WORKORDER_H_INCLUDED_)
#define WORKORDER_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// include the Stringray toolkit
#include "\vssource\inserts\stingray\ot60\ot_buttons.h"
#include "\VSSource\Inserts\Resource.h"
#include "\VSSource\Inserts\DbData.h"
#include "\VSSource\Libs\DBCore\DbDataSource.h"
#include "\VSSource\Libs\DBCore\DbListDef.h"
#include "\VSSource\Inserts\ScheduleShift.h"
#include "\VSSource\Libs\DBCore\MultiSortListCtrl.h"
#include "\VSSource\Inserts\DbScriptProcessor.h"

class CWorkOrder : public CDialog
{
public:
	CWorkOrder(CWnd* pParent = NULL);
	virtual ~CWorkOrder();
//
	enum UpdateFlags
	{	
		UPDATE_ALL = 1,
		UPDATE_ESTIMATES = 2,
		NEW_TIMELOG_ENTRY = 3,
		UPDATE_TIMELOG_ENTRY = 4,
		UPDATE_STATUS = 5
	};

	// this is used for command routing from child popup dialogs back to the main
	// application.  EditDetail uses this to send CALC_LABOR messages back to 
	// QueueDetailView for example.
	CWnd *		m_CommandWnd;

// Dialog Data
	//{{AFX_DATA(CWorkOrder)
	enum { IDD = IDD_WORKORDER };
	CString		m_JobKey;
	CString		m_Mark;
	CString		m_Device;
	CString		m_DueDate;
    CString		m_SchedStart;
    CString		m_SchedStop;
	float		m_TotalTime;
	int			m_ProcessedUnits;
	CString		m_FilePath;
	float		m_ResourceAmount;
	CString		m_Status;
	CString		m_Activity;
	//}}AFX_DATA
	CString		m_NextStation;
	long		m_JobID;
	long		m_WOID;
	CString		m_Location;
	CString		m_Shift;
    CString		m_ActualStart;
    CString		m_ActualStop;
	float		m_ActualResourceAmount;
	int			m_FileType;
	int			m_TotalUnits;

	int			m_nActivities;
	char		*m_ActivityList;  // list of activities (null seperated)

	CString		m_LaborScriptPath;

	CString		m_Data1;  // this is dup job info
	CString		m_Data2;
	CString		m_Data3;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	void AttachActivityList(const int num, char *list);
	void AttachActivityList(CDbDataSource *pDS, char *list);
	virtual void	LoadFromDataSource(CDbDataSource *pDS);
	virtual void	SaveToDataSource(CDbDataSource *pDS);
	virtual void	UpdateDataSource(CDbDataSource *pDS, int options = UPDATE_ALL);
	int				FindInDataSource(CDbDataSource *pDS, bool usingWOID=false);
	virtual void	Reset(const char *Job, const char *Mark, const char *Activity);
	virtual int		AddWO(CDbDataSource *pDS);
	virtual void	EditDetail(CDbData *pDB, CDbListDef *pLDef, BOOL EditAllowed = TRUE);
	virtual void	EditWO(CDbDataSource *pDS, BOOL EditAllowed = TRUE);
	virtual float	GetScheduledResourceAmount(const char *date, CScheduleShift *pShift);
	virtual float	GetActualResourceAmount(const char *date, CScheduleShift *pShift);
	virtual CDbDataSource * GetDetailDataSource(CDbData *pDB) {return(NULL);};
	int				SetScheduledStartStop(const char *start, CScheduleShift &pShift);
	virtual int		UpdateDependentWOs(CDbDataSource *pDS) {return(1);};
	virtual void	CalcLabor(CDbScriptProcessor *pSP, CDbData *pDB);

protected:


	BOOL		m_bEditAllowed;

	// Generated message map functions
	//{{AFX_MSG(CWorkOrder)
	virtual BOOL OnInitDialog();
	afx_msg void OnStartWO();
	afx_msg void OnStopWO();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // !defined(WORKORDER_H_INCLUDED_)
/////////////////////////////////////////////////////////////////////////////
// CWorkOrderSearch dialog

class CWorkOrderSearch : public CDialog
{
// Construction
public:
	int Display(CDbDataSource *pDS, CDbListDef *pListDef);
	CWorkOrderSearch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWorkOrderSearch)
	enum { IDD = IDD_FIND_WO };
	CString	m_Job;
	CString	m_Mark;
	CString	m_Activity;
	CMultiSortListCtrl	m_WOCtrl;
	//}}AFX_DATA

	CDbDataSource *	m_pWODS;
	CDbListDef *	m_pListDef;

	int				m_ButtonMenuID;
	CMenu			m_ButtonMenus;
	SECMenuButton	m_ActionsButton;
	SECMenuButton	m_ActivitiesButton;
	SECMenuButton	m_ReportsButton;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWorkOrderSearch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWorkOrderSearch)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimeLine();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	afx_msg void OnUnSchedule();
	afx_msg void OnWoCalcLabor();
	afx_msg void OnShopImpact();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
