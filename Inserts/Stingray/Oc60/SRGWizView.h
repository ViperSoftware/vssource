//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes.
// Written by Bob Powell and Chuanzhong Zhu (www.stingray.com)
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////
// SRGWizView.h: interface for the SRGWizView class.
//
//////////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGWizView_H__
#define __SRGWizView_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// SRGWizView view

//$head View classes
//$level 1

//@doc SRGWizView
//@mdata BOOL  | SRGWizView | m_bIsTracking | Flag for tracking.

//@mdata CRectTracker  | SRGWizView | m_Tracker | Tracking rectangle used for component dragging

//@mdata CRect         | SRGWizView | m_rectTracker | Helper rectangle for tracking

//@mdata BOOL  | SRGWizView | m_bShowGrid | Semaphore indicating if user want to
// draw alignment grid


//$head The Chart Wizard
//level 1





// adinsert AutoDuck insertion point for SRGWizView 

//@doc SRGWizView 
//@class Special view class for internal use by the Wizard
class SRGWizView : public SREScrollView
{
protected:
	DECLARE_DYNCREATE(SRGWizView)

// Attributes
public:

// Operations
public:
	//@cmember
	/* Constructor*/
	SRGWizView();           // protected constructor used by dynamic creation
	//@cmember
	/* Destructor*/
	virtual ~SRGWizView();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGWizView)
	protected:
	//@cmember
	/* Draws the chart, tracking component, and placement grid*/
		virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	//@cmember
	/* Flag if it is in the tracking mode*/
	BOOL m_bIsTracking;
	//@cmember
	/* Tracking rectangle for component dragging*/
	SRGRectTracker m_Tracker;

	//@cmember
	/* Semaphore indicating if user want to draw an alignment grid*/
	BOOL m_bShowGrid;

#ifdef _DEBUG
	//@cmember,mfunc
	/* Debug code */
	virtual void AssertValid() const;
	//@cmember,mfunc
	/* Debug code */
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(SRGWizView)
	//@cmember
	/* Left button down + shift key initiates tracking */
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//@cmember
	/* Terminates tracking*/
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//@cmember
	/* Changes cursor while tracking*/
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//@cmember
	/* Command handler to stop tracking when in Tracking mode*/
	afx_msg void OnStopTracking();
	//@cmember
	/* Copies the graph to the clipboard as a bitmap*/
	afx_msg void OnWizardCopy();
	//@cmember
	/* Command handler to save the layout for future use*/
	afx_msg void OnSaveLayout();
	//@cmember
	/* Command handler to print the graph from the wizard*/
	afx_msg void OnWizardPrint();
	//@cmember
	/* Bring up the context menu in the view area when user right click mouse*/
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//@cmember,mfunc
	/* Handler for the "Save as DIB" menu */
	afx_msg void OnSaveAsDib();
	//@cmember,mfunc
	/* Handler for the "Save as JPEG" menu */
	afx_msg void OnSaveAsJpeg();
	//}}AFX_MSG
	//@cmember
	/* Message handler called when tracking rect changed size*/
	afx_msg LRESULT OnTrackingRectChanged(WPARAM wParam, LPARAM lParam);
	//@cmember
	/* Message handler called when tracking rect adjust size*/
	afx_msg LRESULT OnAdjustTrackingRect(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	virtual void StopTracking();
	//@cmember
	/* Finding the top most component under the mouse.*/
	virtual SRGraphComponent* GetTrackingComponent(CPoint point);
	//@cmember
	/* Addjust the rectangle to align with the alignment grid*/
	virtual void SnapToGrid(CRect* pRect);
	//@cmember
	/* Draw or erase the alignment grid*/
	virtual void DrawGrid(BOOL bShow = TRUE);
};




#endif // __SRGWizView_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


