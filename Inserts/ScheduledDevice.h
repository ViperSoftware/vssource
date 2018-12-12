// ScheduledDevice.h: interface for the CScheduledDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "\VSSource\libs\DBcore\DbDataSource.h"
#include "resource.h"
#include "ErrorLog.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __CScheduledDevice__
#define __CScheduledDevice__

#pragma comment (lib, "General.lib") // make linker search this lib

// Eshop device types
#define ES_DISPATCHER      0
#define ES_CLARY_SAW       1
#define ES_DEPAUW_SAW      2
#define ES_AUTOWEB_SAW     3
#define ES_AUTOMILL_SAW    4
#define ES_TIMBERMILL_SAW  5
#define ES_OTHER_SAW       6
#define ES_SPEEDCUT_SAW    7
#define ES_AUTOSET_TABLE   8
#define ES_AUTOSETII_TABLE 9
#define ES_CART           10
#define ES_DESIGNER       11
#define ES_AUTO_OMNI_SAW  12
#define ES_OTHER_TRUCK    13
#define ES_OMNI_JETSET_TABLE 14
#define ES_AUTO8_TABLE    15
#define ES_SPIDA_RADIAL_SAW  16
#define ES_OTHER_TABLE    17
#define ES_RESERVATIONS   18
#define ES_SPEEDROLL_TABLE   19
#define ES_LOGIN_QUEUE		 20
#define ES_NOSETUP_TABLE	 21
#define ES_FETCH_LUMBER		 22
#define ES_FETCH_PLATE		 23
#define ES_ALS_SAW			 24
#define ES_SPEEDCUT_EX_SAW	 25
#define ES_MANGO_SAW		 26
#define ES_TCT_SAW		     27
#define ES_STEEL_ROLLFORMER  28
#define ES_MITEK_PLANX		 29	
#define ES_BLADE_SAW		 30	
#define ES_MITEK_ROOFTRACKER 31	
#define ES_MONET_SHORTCUTTER 32	


// Location types (must match in LocationTypes table in database)
#define ES_UNKNOWN		0
#define ES_PLANT		1
#define ES_OFFICE		2

// queue data file types
#define ES_ALLTYPES      0
#define ES_PIECECUTFILE  1
#define ES_SAW_WO        1
#define ES_TRUSSPICFILE  2
#define ES_TABLE_WO      2

// status values
#define ES_NEWITEM    0
#define ES_INCOMPLETE 1
#define ES_COMPLETE   2
#define ES_REMOVED    4
#define ES_IN_USE     5

// device status values
#define ES_INACTIVE			0
#define ES_ACTIVE			1
#define ES_DOWN_MAINTENENCE 2


class CScheduledDevice : public CDialog
{
// Construction
public:
	CScheduledDevice(CWnd* pParent = NULL);   // standard constructor
	~CScheduledDevice();

protected:
	enum { IDD = IDD_ADD_DEVICE };
public:
	static BOOL	IsTable(int type);
	static BOOL	IsAutoOmni(int type);
	static BOOL	IsAlpineAutoSaw(int type);

	//{{AFX_DATA(CScheduledDevice)
	CString m_Title;         
	int		m_DeviceType;
	int		m_FileType;     
	CString	m_Directory;     
	int		m_Capacity;      
	int		m_Used;          
	int		m_Status; 
	CString m_Date;
	CString m_Location;
	BOOL	m_WorkOrderBased;
	CString m_Parameters;
	CString m_selectSQL;
	CString m_filterSQL;
	CString m_sortSQL;
	//}}AFX_DATA
	long	m_DeviceID;  // actual ID field value from device table (primary key)
	long	m_ID;
	CString m_Department;
	CString m_NextWOStartTime;
	CString m_ActiveWO;
	long	m_ActiveWOID;
	double  m_ProdRate;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScheduledDevice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	int		SetActiveWO(CDaoDatabase *pDB, const char *Label, long WOID);
	void	CreateLogsDirectory();
	void	LoadFromDbDataSource(CDbDataSource *pDS);
	int		AddToDbDataSource(CDbDataSource *pDS);
	void	SetActiveDate(CString Date);
	virtual void GetTableSQL(char *) { return; };
	virtual void GetFilterSQL(char *) { return; };
	virtual void CreateSpecialFiles(CDaoDatabase *pDB, CDbDataSource *pDS);
	virtual void ProcessTimeLog(CDbDataSource *pDS, const char *path, CErrorLog *ErrorLog, BOOL bClearTotals);
	void	Process_ALS_TimeLog(CDbDataSource *pDS, const char *path, CErrorLog *ErrorLog, BOOL bClearTotals,const char *WOStart,const char *WOStop);
	virtual void CopyWorkOrders(const char *whereSQL, const char *targetPath);
	virtual void UpdateCopiedWorkOrders(const char *targetPath);

protected:
	// Generated message map functions
	//{{AFX_MSG(CScheduledDevice)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDirBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
