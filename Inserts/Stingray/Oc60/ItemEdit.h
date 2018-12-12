//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//@doc SRGraphItemEdit
//@module ItemEdit.h | SRGraphItemEdit header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)
/////////////////////////////////////////////////////////////

// using cmember tags only for this simple dialog class

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif
/////////////////////////////////////////////////////////////////////////////
// SRGraphItemEdit dialog
#ifndef __SRGRAPHITEMEDIT_H__
#define __SRGRAPHITEMEDIT_H__

/////////////////////////////
// AutoDuck tag block for SRGraphItemEdit 
//@doc SRGraphItemEdit

// adinsert AutoDuck insertion point for SRGraphItemEdit 

//$head The Chart explorer
//$level 1

//@doc SRGraphItemEdit 

//@topic SRGraphItemEdit Class Overview |
//This is a simple dialog to enable or disable background draw processing and feedback logging<nl>
//Part of Chart Explorer -- displayed when user double-clicks the root item in the tree diagram

//@class Dialog to enable or disable background draw processing and feedback logging<nl>
//Part of Chart Explorer -- displayed when user double-clicks the root item in the tree diagram
//@base public | CDialog
class SRGraphItemEdit : public CDialog
{
// Construction
public:
	SRGraphItemEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SRGraphItemEdit)
	enum { IDD = SRG_IDD_GRAPHITEMEDIT };
	//@cmember
	/* Check box to enable background draw processing*/
	BOOL	m_bBackgroundDraw;
	//@cmember
	/* Check box to enable feedback logging*/
	BOOL	m_bFeedbackLogging;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphItemEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SRGraphItemEdit)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

