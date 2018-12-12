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

//@doc
//@module CPropSht.h | definition of the Chart Explorer property sheet class<nl>
//Copyright <cp> Stingray Software 1996.<nl>
//Written by Bob Powell (www.stingray.com)

//$head The chart explorer
//$level 1

// cmember tags only used for this class

// SRGCPropertySheet.h : header file
//
// This class defines custom modal property sheet 
// SRGraphComponentProperties.

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef __SRGCPROPERTYSHEET_H__
#define __SRGCPROPERTYSHEET_H__
#include "CPropPg.h"

/////////////////////////////////////////////////////////////////////////////
// SRGraphComponentProperties

/////////////////////////////
// AutoDuck tag block for SRGraphComponentProperties 

// adinsert AutoDuck insertion point for SRGraphComponentProperties 

//@topic SRGraphComponentProperties Class Overview |
//This is a property sheet in the chart explorer

//@doc SRGraphComponentProperties 
//@class SRGraphComponentProperties defines a custom modal property sheet.<nl>
//Part of Chart Explorer
//@base public | CPropertySheet
class SRGraphComponentProperties : public CPropertySheet
{
	DECLARE_DYNAMIC(SRGraphComponentProperties)

// Construction
public:
	//@cmember
	/* Constructor -- adds property pages appropriate or the type */
	//of item that the user selected, adds font style page if bFontSheet is TRUE 
	SRGraphComponentProperties(CWnd* pParentWnd = NULL,BOOL bFontSheet=FALSE,int type=0);
// Attributes
public:
	//@cmember
	/* Property page for component rectangle position, measurement mode, and view angles*/
	SRGCTypeAndPos m_Page1;
	//@cmember
	/* Property page for component fill style*/
	SRGCFillStyle m_Page2;
	//@cmember
	/* Property page for component border style*/
	SRGCBorderStyle m_Page3;
	//@cmember
	/* Property page for component shadow style*/
	SRGCShadowStyle m_Page4;
	//@cmember
	/* Property page for component font style*/
	SRGCFontStyle m_Page5;
	//@cmember
	/* Property page for display component -- graph and axis type, scope, etc.*/
	SRGCDisplayStyle m_Page6;
	//@cmember
	/* Property page for legend component -- legend type, key style, scope*/
	SRGCLegendEdit m_Page7;
	//@cmember
	/* Property page for label component*/
	SRGCLabelStyle m_Page8;
	//@cmember
	/* Property page for annotations*/
	SRGCLabelStyle m_Page9;
	//@cmember
	/* Property page for data or data list objects*/
	SRGObjStyle m_Page10;
	//@cmember
	/* Property page for the interior of data or data list objects*/
	SRGInteriorEdit m_Page11;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphComponentProperties)
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Destructor*/
	virtual ~SRGraphComponentProperties();

// Generated message map functions
protected:
	//{{AFX_MSG(SRGraphComponentProperties)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////


#endif	// __SRGCPROPERTYSHEET_H__
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

