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
//
// CmpChce.h : header file
//
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

/////////////////////////////////////////////////////////////////////////////
// SRGComponentChoice dialog


#ifndef __SRGRAPHCOMPONENTCHOICE_H__
#define __SRGRAPHCOMPONENTCHOICE_H__

/////////////////////////////
// AutoDuck tag block for SRGComponentChoice 
//@doc SRGComponentChoice
//@mdata CComboBox  | SRGComponentChoice | m_ComponentType | Combo box to hold component names

// adinsert AutoDuck insertion point for SRGComponentChoice 
// cmember tags only used for this dialog class

//$head The Chart Explorer
//$level 1

//@topic SRGComponentChoice Class Overview |
//This dialog is displayed when the user right-clicks the Components item 
//in the tree diagram and then selects the Add Component command from the popup menu. 
//The user can choose the type of component to be added from a combo box.

//@doc SRGComponentChoice 
//@class Part of Chart Explorer<nl>
//This dialog is displayed when the user right-clicks the Components item 
//in the tree diagram and then selects the Add Component command from the popup menu. 
//The user can choose the type of component to be added from a combo box.
//@base public | CDialog
class SRGComponentChoice : public CDialog
{
// Construction
public:
	//@cmember
	/* Standard constructor*/
	SRGComponentChoice(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SRGComponentChoice)
	enum { IDD = SRG_IDD_CHOOSECOMP };
	//@cmember
	/* List of components that can be added*/
	CComboBox	m_ComponentType;
	//}}AFX_DATA

	//@cmember
	/* Index of the selected component*/
	int m_nSelection;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGComponentChoice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	//@cmember
	/* Initializes the dialog -- sets initial selection in the combo box*/
	virtual BOOL OnInitDialog();

protected:

	// Generated message map functions
	//{{AFX_MSG(SRGComponentChoice)
	//@cmember
	/* Retrieves user selection*/
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};






#endif
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

