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
// @doc SRGraphTip
// @module GrphTip.h | SRGraphTip header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// SRGraphTip window
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA    AFX_DATA_EXPORT
#endif

#ifndef __GRAPH_TIP__
#define __GRAPH_TIP__

//@doc SRGraphTip

//@mfunc virtual BOOL  | SRGraphTip | IsShowing | Returns TRUE if the Graph Tip is currently visible

// using cmember tags only for simple data items


//@doc SRGraphTip
//@mdata HBRUSH  | SRGraphTip | m_hBkBrush | This handle stores the brush used to paint the background of chart tips. It is created 
//when ShowTip is called and recycled automatically when the SRGraphTip object is deleted.

//@mdata CString  | SRGraphTip | m_ClassName | Afx generated class name

//@mdata CString  | SRGraphTip | m_TextString | Text string to display in the Graph Tip

//@mdata CPoint  | SRGraphTip | m_Point | Point at which the graph tip is drawn

//@mdata BOOL  | SRGraphTip | m_bShowing | TRUE when the Graph Tip is visible

//@doc SRGraphTip
//@mdata int  | SRGraphTip | m_nTipTime | The time (in milliseconds) that the tip is to be shown

//adinsert
//$head Utility classes
//$level 1
//@class A simple tooltip-style window designed to show data for the SRGraphFeedback system
//@rem This simple window draws a ToolTip-like box with text on the main window. It is not 
//clipped by its parent and remains in place for 5 seconds unless it is turned off or 
//the mouse cursor passes over it.
class SRGraphTip : public CWnd
{
// Construction
public:
	//@cmember,mfunc
	/* Initializes the tip timer*/
	virtual void SetTipTime(int v){m_nTipTime=v;}

	//@cmember,mfunc
	/* retrieves the tip timer value */
	virtual int GetTipTime(){return m_nTipTime;}
	//@cmember
	/* Returns TRUE if the Graph Tip is currently visible*/
	virtual BOOL IsShowing(){return m_bShowing;}

	//@cmember
	/* One-step initialization of the Graph Tip*/
	virtual void ShowTip(LPCTSTR strText,CPoint point,CWnd *pParentWnd);

	//@cmember
	/* Variable argument version of ShowTip*/
	virtual void ShowTip(CPoint point, CWnd* pParentWnd, LPCTSTR lpszFormat, ...);

	//@cmember
	/* Constructor*/
	SRGraphTip();

	//@cmember
	/* Removes the Graph Tip and destroys the window*/
	virtual void EraseTip();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphTip)
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Destructor*/
	virtual ~SRGraphTip();

	// Generated message map functions
protected:
	//@cmember
	/* The time (in milliseconds) that the tip is to be shown */
	int m_nTipTime;

	//@cmember
	/* Handle to the background brush*/
	HBRUSH m_hBkBrush;

	//@cmember
	/* The Afx generated class name*/
	CString m_ClassName;

	//@cmember
	/* The text to display in the Graph Tip*/
	CString m_TextString;

	//@cmember
	/* The point at which the graph tip is drawn*/
	CPoint m_Point;

	//@cmember
	/* TRUE when the Graph Tip is visible*/
	BOOL m_bShowing;

	//{{AFX_MSG(SRGraphTip)
	//@cmember
	/* Draws the tip text in the window*/
	afx_msg void OnPaint();
	//@cmember
	/* Destroys the tip window when mouse cursor passes over it*/
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//@cmember
	/* Destroys the tip window when time limit (5 seconds) expires*/
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

