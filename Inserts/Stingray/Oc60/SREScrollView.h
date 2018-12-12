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
// @doc SREScrollView
// @module SREScrollView.h | SREScrollView header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell and Chuanzhong Zhu (www.stingray.com)
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SREScrollView_H__
#define __SREScrollView_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////
//
// SREScrollView.h : header file
//
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////
// AutoDuck tag block for SREScrollView 
//@doc SREScrollView

//$head View classes
//$level 1

//@mdata BOOL  | SREScrollView | m_bAutoDelete | Semaphore indicating whether this object should delete itself
// when its window is destroyed. By default, m_bAutoDelete is set to FALSE, meaning that its parent
// will free the memory used by this object.  This is the case when the parent is a CDialog and CFormView or
// their derivatives. If an SREScrollView is allocated on the heap and used as a more typical view, such as a splitter window; SetAutoDelete(TRUE) should be called.

//@mdata SRGraphComponent*  | SREScrollView | m_DragingComponent | Holds the dragging component when in tracking mode -- available for derived classes

//@mfunc void  | SREScrollView | SetAutoDelete | Sets or resets the auto-delete semaphore
//@parm BOOL  | v | TRUE if this object will not be deleted by its parent
//@see <md SREScrollView::m_bAutoDelete>

//@mfunc BOOL  | SREScrollView | GetAutoDelete | Returns the value of the auto-delete semaphore 
//@see <md SREScrollView::m_bAutoDelete>

//@doc SREScrollView
//@mdata SRGraph*  | SREScrollView | m_pGraph | Pointer to an existing SRGraph-derived object -- must be set before the view is drawn


// adinsert AutoDuck insertion point for SREScrollView 

//@topic SREScrollView Class Overview |
//This class, derived from SRGScrollView, provides an extended view class which has the ability to exist without a document. Consequently, this class may be used to provide 
// all the functionality of a CScrollView class and the data dragging capabilities and chart interaction of the SRGraphView class on dialogs and in non document - view aplications.


//@doc SREScrollView 
//@class SREScrollView is a small extension of the SRGScrollView class which can be 
//put into dialog boxes and similar windows.  It does not depend on a document class. 
//On the other hand, it still behaves like a SRGScrollView class, reacting to mouse events, etc.<nl> 
//The m_pGraph member variable must be set to point to an existing SRGraph object.<nl> 
//SetAutoDelete(TRUE) should be called if this view object is not in a dialog or form view, so that it will delete itself.
//@base public | SRGScrollView
class SREScrollView : public SRGScrollView
{
protected:
	DECLARE_DYNCREATE(SREScrollView)

// Attributes
public:
	//@cmember
	/* Sets or resets the auto-delete semaphore*/
	void SetAutoDelete(BOOL v){m_bAutoDelete=v;}
	//@cmember
	/* Returns the value of the auto-delete semaphore*/
	BOOL GetAutoDelete(){return m_bAutoDelete;}

// Operations
public:
	//@cmember
	/* Constructor*/
	SREScrollView();           // protected constructor used by dynamic creation
	//@cmember
	/* Destructor*/
	virtual ~SREScrollView();

	//@cmember
	/* Overridden to return the internal pointer m_pGraph instead of accessing a document*/
	virtual SRGraph* GetGraph();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SREScrollView)
	protected:
	//@cmember
	/* Checks the validity of m_pGraph and draws the chart that it points to*/
	virtual void OnDraw(CDC* pDC);

	//@cmember
	/* Deletes the this pointer when its window is destroyed, if m_bAutoDelete is TRUE*/
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	//@cmember
	/* Pointer to the dragging component when tracking (not used internally)*/
	SRGraphComponent* m_DragingComponent;

	//@cmember
	/* Semaphore indicating whether this object should delete itself when its window is destroyed*/
	BOOL              m_bAutoDelete;


#ifdef _DEBUG
	//@cmember,mfunc
	/* Standard debug code */
	virtual void AssertValid() const;
	//@cmember,mfunc
	/* Standard debug code */
	virtual void Dump(CDumpContext& dc) const;
#endif

	//@cmember
	/* Special handling to support use as a child for no frame window -- always returns MA_ACTIVATE*/
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);

	// Generated message map functions
	//{{AFX_MSG(SREScrollView)
	//@cmember
	/* Calls CWnd::OnCreate directly*/
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	//@cmember,mfunc
	/* Enables printing from non doc - view - frame architectures. */
	virtual void Printing();
	//@cmember
	/* Finds the top-most component under the mouse position*/
	virtual SRGraphComponent* GetTrackingComponent(CPoint point);

	//@cmember
	/* Pointer to an existing SRGraph-derived object -- must be set before the view is drawn*/
	SRGraph* m_pGraph;
};


#endif // __SREScrollView_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

