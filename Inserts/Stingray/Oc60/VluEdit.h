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
//@doc SRGraphValueEdit
//@module VluEdit.h | SRGraphValueEdit header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// VluEdit.cpp: interface of the SRGraphValueEdit class
//
/////////////////////////////////////////////////////////////////


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif
/////////////////////////////////////////////////////////////////////////////
// SRGraphValueEdit dialog
#ifndef __SRGRAPHVALUEEDIT_H__
#define __SRGRAPHVALUEEDIT_H__

/////////////////////////////
// AutoDuck tag block for SRGraphValueEdit 
// adinsert AutoDuck insertion point for SRGraphValueEdit 
// cmember tags only for this simple dialog class

//$head The Chart explorer
//$level 1

//@doc SRGraphValueEdit 
//@topic SRGraphValueEdit Class Overview |
//This is a part of Chart Explorer, this dialog is invoked when the user double-clicks a 
//data item's value on the tree control.  It allows the user to modify the value assigned to the data item.

//@class Part of Chart Explorer, this simple dialog is invoked when the user double-clicks a 
//data item's value on the tree control.  It allows the user to modify the value assigned to the data item.
//@base public | CDialog
class SRGraphValueEdit : public CDialog
{
// Construction
public:
		//@cmember
		/* Standard constructor*/
	SRGraphValueEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SRGraphValueEdit)
	enum { IDD = SRG_IDD_VALUEEDIT };
		//@cmember
		/* Value displayed in the edit control -- may be modified by the user*/
	double	m_dValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphValueEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SRGraphValueEdit)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


