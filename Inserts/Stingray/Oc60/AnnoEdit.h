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
// SRGraphAnnotationEdit.h : header file
//


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


/////////////////////////////////////////////////////////////////////////////
// SRGraphAnnotationEdit dialog

#ifndef __SRGRAPHANNOTATIONEDIT_H__
#define	__SRGRAPHANNOTATIONEDIT_H__

/////////////////////////////
// AutoDuck tag block for SRGraphAnnotationEdit 
// cmember tags only used for this dialog class
// adinsert AutoDuck insertion point for SRGraphAnnotationEdit 

//$head The Chart explorer
//$level 1

//@doc SRGraphAnnotationEdit
//@topic SRGraphAnnotationEdit Class Overview |
//This dialog is displayed when the user right-clicks a data item or data list. 
//It allows the user to enter annotation text and country code for the selected object.


//@doc SRGraphAnnotationEdit 
//@class Part of Chart Explorer<nl>
//This dialog is displayed when the user right-clicks a data item or data list. 
//It allows the user to enter annotation text and country code for the selected object.
//@base public | CDialog
class SRGraphAnnotationEdit : public CDialog
{
// Construction
public:
	SRGraphAnnotationEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SRGraphAnnotationEdit)
	enum { IDD = SRG_IDD_ANNOTATIONEDIT };
	//@cmember
	/* Annotation text*/
	CString	m_Text;
	//@cmember
	/* Country code*/
	int		m_nCode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphAnnotationEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SRGraphAnnotationEdit)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#endif 

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

