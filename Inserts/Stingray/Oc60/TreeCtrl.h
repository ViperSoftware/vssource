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
//@doc SRGTreeCtrl
//@module TreeCtrl.h | SRGTreeCtrl header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// TreeCtrl.cpp: interface of the SRGTreeCtrl class
//
/////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHEDITDIALOH_H__
#define __SRGRAPHEDITDIALOH_H__

/////////////////////////////
// AutoDuck tag block for SRGTreeCtrl 
// adinsert AutoDuck insertion point for SRGTreeCtrl 

// cmember tags only used for this simple control class

//$head The Chart explorer
//$level 1

//@doc SRGTreeCtrl 
//@topic SRGTreeCtrl Class Overview |
//This class is a simple extension of the standard CTreeCtrl class that 
//maintains the current mouse position and the last tree view item clicked.<nl>
//It is part of the chart explorer.

//@class SRGTreeCtrl is a simple extension of the standard CTreeCtrl class that 
//maintains the current mouse position and the last tree view item clicked
//@base public | CTreeCtrl
class SRGTreeCtrl : public CTreeCtrl
{
// Construction
public:
	//@cmember
	/* Current position of the mouse cursor in screen coordinates*/
	CPoint m_CurrentPoint;
	//@cmember
	/* Last tree view item clicked by the user or NULL*/
	HTREEITEM m_LastItemHit;
	//@cmember
	/* Constructor*/
	SRGTreeCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Destructor*/
	virtual ~SRGTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(SRGTreeCtrl)
	//@cmember
	/* Overridden to store the mouse position*/
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//@cmember
	/* Overridden to store the tree item clicked*/
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//@cmember
	/* Overridden to store the tree item clicked*/
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

