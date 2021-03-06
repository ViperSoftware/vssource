	// 
// Stingray Software Extension Classes
// Copyright (C) 1995 Stingray Software Inc.
// All Rights Reserved
// 
// This source code is only intended as a supplement to the
// Stingray Extension Class product.
// See the SEC help files for detaild information
// regarding using SEC classes.
// 
//  Authors:		Don
//  Description:	Declarations for SECToolBarsDlg/SECNewToolBar
//  Created:		August 1996
//

#ifdef WIN32

#ifndef __TBARSDLG_H__
#define __TBARSDLG_H__

//
// Header include diagnostics
//
#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
	#pragma message ( __TIME__ ":  include " __FILE__ )
#endif

#ifndef __SECRES_H__
#include "secres.h"
#endif

#ifndef __TBARMGR_H__
#include "tbarmgr.h"
#endif

//
// SEC Extension DLL
// Initialize declaration context
//

#ifdef _SECDLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA    SEC_DATAEXT
#endif //_SECDLL


///////////////////////////////////////////////////////////////////////////////
// Forward references
class SECToolBarManager;


///////////////////////////////////////////////////////////////////////////////
// SECToolBarsBase 
//
// Implements common functionality for SECToolBarsDlg and SECToolBarsPage.
//
class SECToolBarsBase
{
// Construction
protected:
	// Hide constructor, so that class cannot be instantiated directly
	SECToolBarsBase();

// Attributes
public:
	BOOL m_bToolTips;						// TRUE if tooltips enabled
	BOOL m_bCoolLook;						// TRUE if cool look enabled
	BOOL m_bLargeButtons;					// TRUE if large buttons enabled

	// Backup values to restore upon "cancel"
	BOOL m_bOrigToolTips;					
	BOOL m_bOrigCoolLook;					
	BOOL m_bOrigLargeButtons;				

// Operations
public:
	void SetManager(SECToolBarManager* pManager);

// Implementation
public:
	virtual ~SECToolBarsBase();

protected:
	inline CFrameWnd* GetFrameWnd() const { return m_pManager->GetFrameWnd(); }
	BOOL GetCurBar(CControlBar*& pBar, int* nID = NULL);
	int  FindIndex(UINT nID);
	void SetWnd(CWnd* pWnd);
	void InitDialog();
	void FillToolBarList();
	void SaveState();
	void RestoreState();

	// Implementation, data members.
protected:
	SECToolBarManager* m_pManager;			// Pointer to the toolbar manager
	CCheckListBox	   m_toolbarList;		// Subclassed listbox showing list
											// of all toolbars
	CWnd*			   m_pWnd;				// Pointer to dialog window object

	// Implementation - message map entries
	void OnSelChange();
	void OnNameKillFocus();
	BOOL OnNewToolbar();
	void OnResetBtn();
	void OnChkChange();
	void OnToolTips();
	void OnCoolLook();
	void OnLargeButtons();
	LONG OnBarNotify(UINT nID, LONG lParam);
};


/////////////////////////////////////////////////////////////////////////////
// SECToolBarsDlg
//
/////////////////////////////
// AutoDuck tag block block for SECToolBarsDlg 
// adinsert AutoDuck insertion point for SECToolBarsDlg 
//@doc SECToolBarsDlg 
//@class SECToolBarsDlg implements the Customize dialog, which an end user can use 
// to create a customized toolbar with buttons geared toward a particular task.  
//@comm 
// This dialog displays a list of toolbars to the user, and allows the user to manipulate these 
// toolbars.  Through the toolbar dialog, the user can choose between large or small buttons, 
// tooltips enabled or disabled, and conventional appearance or the new cool look. This 
// dialog can be invoked through the SECToolBarManager::ExecViewToolBarsDlg() method.  
// Note that if this function returns IDC_TOOLBAR_CUSTOMIZE, then the customize dialog 
// should be displayed.
//
// See the sample TOOLBAR in the \OT\SAMPLES\STANDARD\DOCKING\TOOLBAR directory for a demonstration of 
// this class.
//@xref <c SECToolBarsPage>  <c SECCustomToolBar>  <c SECToolBarManager>

	//@cmember
	/* Constructs an SECToolBarsDlg dialog object and associates it with a parent window.*/
class SECToolBarsDlg : public CDialog, public SECToolBarsBase
{
// Construction
public:
	/////////////////////////////
	SECToolBarsDlg(CWnd* pParent);

// Attributes
public:
	enum { IDD = IDD_TOOLBARS };	

// Overrideables
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// Implementation
public:

protected:
	void Terminate(int nResult);

	// Implementation, data members.

	// Implementation - message map and entries
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnChkChange();
	afx_msg void OnSelChange();
	afx_msg void OnNameKillFocus();
	afx_msg LONG OnFloatStatus(WPARAM wParam, LPARAM lParam);
	afx_msg LONG OnBarNotify(UINT nID, LONG lParam);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnResetBtn();
	afx_msg void OnNewToolbar();
	afx_msg void OnCustomise();
	afx_msg void OnToolTips();
	afx_msg void OnCoolLook();
	afx_msg void OnLargeButtons();
};


/////////////////////////////////////////////////////////////////////////////
// SECToolBarsPage property page
//
/////////////////////////////
// AutoDuck tag block block for SECToolBarsPage 

// adinsert AutoDuck insertion point for SECToolBarsPage 
//@doc SECToolBarsPage 
//@class SECToolBarsPage constructs a toolbar property page for the Customize dialog, 
// which can be used to create a toolbar with buttons geared toward a particular task.
//@comm
// Through the toolbar dialog, the user can choose between large or small buttons, 
// tooltips enabled or disabled, and conventional appearance or the new cool look.
//
// The SECToolBarsPage property page should only be embedded in an SECToolBarSheet 
// (not a CPropertySheet).
//
// See the sample TOOLBAR in the \OT\SAMPLES\STANDARD\DOCKING\TOOLBAR directory for a demonstration 
// of this class.
//@xref <c SECToolBarsBase>
//@base public | CPropertyPage
//@base public | SECToolBarsPage
class SECToolBarsPage : public CPropertyPage, public SECToolBarsBase
{
// Construction
public:
	//@cmember
	/* Constructs a SECToolBarsPage.*/
	SECToolBarsPage();
	SECToolBarsPage(UINT nIDTemplate, UINT nIDCaption = 0);
	SECToolBarsPage(LPCTSTR lpszTemplate, UINT nIDCaption = 0);

// Attributes
public:
	enum { IDD = IDD_TOOLBARS_PAGE };

// Overrideables
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnSetActive();
	virtual BOOL OnKillActive();
	virtual void OnReset();
	virtual void OnCancel();
	virtual void OnOK();

// Implementation
public:
	virtual ~SECToolBarsPage();

protected:
	// Notifies sibling pages of a change in toolbar style.
	void OnStyleChanging(UINT nEvent);

	// Implementation - message map and entries
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
	afx_msg void OnSelChange();
	afx_msg void OnNameKillFocus();
	afx_msg void OnNewToolbar();
	afx_msg void OnResetBtn();
	afx_msg void OnChkChange();
	afx_msg void OnToolTips();
	afx_msg void OnCoolLook();
	afx_msg void OnLargeButtons();
	afx_msg LONG OnBarNotify(UINT nID, LONG lParam);
};

/////////////////////////////////////////////////////////////////////////////
// SECNewToolBar dialog
//
class SECNewToolBar : public CDialog
{
// Construction
public:
	SECNewToolBar(CWnd* pParent = NULL);

// Attributes
public:
	enum { IDD = IDD_TOOLBAR_NEW };
	CString	m_strToolBarName;				// Name of new toolbar

// Overrideables
protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// Implementation
public:

protected:
	// Implementation, data members.

	// Implementation - message map and entries
	DECLARE_MESSAGE_MAP()

	afx_msg void OnChangeName();
};

// Registered message used by SECToolBarsPage to notify sibling pages when 
// a toolbar style is changing
extern const int wmSECToolBarStyleChanging;

// wParam for wmSECToolBarStyleChanging.
#define TBSC_LARGEBTNS		0x0001			// Changing to large buttons
#define TBSC_COOLLOOK		0x0002			// Changing to cool look

//
// SEC Extension DLL
// Reset declaration context
//

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

#endif // __TBARSDLG_H__

#endif // WIN32

