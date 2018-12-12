// ScheduleShift.h: interface for the CScheduleShift class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ScheduleShift_H_INCLUDED_)
#define ScheduleShift_H_INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\Resource.h"
#include "\VSSource\Libs\DBCore\DbDataSource.h"
#include "\VSSource\libs\DBcore\DAOSource.h"


class CShiftData  
{
public:
	CShiftData();
	virtual ~CShiftData();

	BOOL			m_IsWorkDay;
	COleDateTime	m_Start;
	COleDateTime	m_Break1;
	COleDateTime	m_Lunch;
	COleDateTime	m_Break2;
	COleDateTime	m_Stop;
	int				m_LunchLength;
	int				m_BreakLength;
	long			m_ShiftID;
	long			m_LocationID;


	// methods

};

class CScheduleShift : public CDialog
{
	class CShiftWeek
	{
	public:
		CString		m_Name;
		CShiftData	m_Day[7];
	};
public:
	CScheduleShift(CWnd* pParent = NULL);
	virtual ~CScheduleShift();

// Dialog Data
	//{{AFX_DATA(CScheduleShift)
	enum { IDD = IDD_SCHEDULESHIFT };
	CString	m_Name;
	CString	m_Start;
	CString	m_Break1;
	CString	m_Lunch;
	CString	m_Break2;
	CString	m_Stop;
	int		m_BreakLength;
	int		m_LunchLength;
	long	m_LocationID;
	int		m_Weekday;
	long	m_ShiftID;
	COleDateTime	m_CurLoadedDay;
	CString			m_CurLoadedDate;
	//}}AFX_DATA

	BOOL		m_bDataLoaded;
//	CShiftData	m_Days[7];  // one for each day of week
	CShiftWeek	m_Shifts[3];
	int			m_iShift;
	int			m_ActiveShiftDayID;

	CStringList	m_Holidays; // list of non-work days for all devices

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScheduleShift)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	COleDateTime GetProductionDayStart(const char *date);
	COleDateTime GetProductionDate(const char *date);
	int SetActiveShift(const char *Name);
	void AdjustToValidWorkday(COleDateTime &date, int direction = -1);
	virtual void	LoadFromDataSource(CDbDataSource *pDS);
	virtual void	SaveToDataSource(CDbDataSource *pDS);
	virtual void	UpdateDataSource(CDbDataSource *pDS);
	int				FindInDataSource(CDbDataSource *pDS);
	virtual int		Edit(BOOL EditAllowed);
	virtual void	LoadShiftDays(CDbDataSource *pDS);
	void			SetActiveShiftDay(const char *Date);
	void			SetActiveShiftDay(int weekDay);
	BOOL			IsWorkDay(int DayOfWeek);
	BOOL			IsWorkDay(const char *Date);
	int				Capacity(const char *Date);

protected:


	BOOL		m_bEditAllowed;

	// Generated message map functions
	//{{AFX_MSG(CScheduleShift)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CShifts dialog

class CShifts : public CDialog
{
// Construction
public:
	CShifts(CWnd* pParent = NULL);   // standard constructor
	CDbDataSource * GetDatasource();

// Dialog Data
	//{{AFX_DATA(CShifts)
	enum { IDD = IDD_SHIFTS };
	CString	m_Shift;
	//}}AFX_DATA
	long	m_LocationID;
	CString m_Location;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShifts)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDbDAODataSource m_DAO;

	// Generated message map functions
	//{{AFX_MSG(CShifts)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnActivate();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(ScheduleShift_H_INCLUDED_)
