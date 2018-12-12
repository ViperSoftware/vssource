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

/////////////////////////////////////////////////////////////
// @doc SREGraphView
// @module SREGraphView.h | SREGraphView header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell and Chuanzhong Zhu (www.stingray.com)
/////////////////////////////////////////////////////////////

//$head View classes
//$level 1

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#if !defined(_GRAPHVIEW_H_INCLUDED_)
#define _GRAPHVIEW_H_INCLUDED_


/////////////////////////////////////////////////////////////
//
// SREGraphView.h : header file
//
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////
// AutoDuck tag block for SREGraphView 
//@doc SREGraphView

//@mdata BOOL  | SREGraphView | m_bAutoDelete | Semaphore indicating whether this object should delete itself
// when its window is destroyed. By default, m_bAutoDelete is set to FALSE, meaning that its parent
// will free the memory used by this object.  This is the case when the parent is a CDialog and CFormView or
// their derivatives. If an SREGraphView is allocated on the heap and used as a more typical view, such as a splitter window; SetAutoDelete(TRUE) should be called.

//@mdata SRGraphComponent*  | SREGraphView | m_DragingComponent | Holds the dragging component when in tracking mode -- available for derived classes

//@mfunc void  | SREGraphView | SetAutoDelete | Sets or resets the auto-delete semaphore
//@parm BOOL  | v | TRUE if this object will not be deleted by its parent
//@see <md SREGraphView::m_bAutoDelete>

//@mfunc BOOL  | SREGraphView | GetAutoDelete | Returns the value of the auto-delete semaphore 
//@see <md SREGraphView::m_bAutoDelete>


// adinsert AutoDuck insertion point for SREGraphView 

//@topic SREGraphView Class Overview |
//SREGraphView is a small extension of the SRGraphView class which can be 
//put into dialog boxes and similar windows.  It does not depend on a document class. 
//On the other hand, it still behaves like a SRGraphView class, reacting to mouse events, etc.<nl> 
//The m_pGraph member variable must be set to point to an existing SRGraph object.<nl> 
//SetAutoDelete(TRUE) should be called if this view object is not in a dialog or form view, so that it will delete itself.


//@doc SREGraphView 
//@class SREGraphView is a small extension of the SRGraphView class which can be 
//put into dialog boxes and similar windows.  It does not depend on a document class. 
//On the other hand, it still behaves like a SRGraphView class, reacting to mouse events, etc.<nl> 
//The m_pGraph member variable must be set to point to an existing SRGraph object.<nl> 
//SetAutoDelete(TRUE) should be called if this view object is not in a dialog or form view, so that it will delete itself.
//@base public | SRGraphView
class SREGraphView : public SRGraphView
{
	DECLARE_DYNCREATE(SREGraphView)
// Construction
public:
	//@cmember
	/* Constructor*/
	SREGraphView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SREGraphView)
	protected:
	//@cmember
	/* Deletes the this pointer when its window is destroyed, if m_bAutoDelete is TRUE*/
	virtual void PostNcDestroy();

	//@cmember
	/* Checks the validity of m_pGraph and draws the chart that it points to*/
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Destructor*/
	virtual ~SREGraphView();

	//@cmember
	/* Sets or resets the auto-delete semaphore*/
	void SetAutoDelete(BOOL v){m_bAutoDelete=v;}
	//@cmember
	/* Returns the value of the auto-delete semaphore*/
	BOOL GetAutoDelete(){return m_bAutoDelete;}

	// Generated message map functions
protected:
	//@cmember
	/* Pointer to the dragging component when tracking (not used internally)*/
	SRGraphComponent* m_DragingComponent;

	//@cmember
	/* Semaphore indicating whether this object should delete itself when its window is destroyed*/
	BOOL m_bAutoDelete;

	//{{AFX_MSG(SREGraphView)
	//@cmember
	/* Performs zoom out and calls the base class function*/
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

	//@cmember
	/* Calls CWnd::OnCreate directly*/
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	//@cmember
	/* Special handling to support use as a child with no frame window -- always returns MA_ACTIVATE*/
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);

	//@cmember
	/* Overridden to return the internal pointer m_pGraph instead of accessing a document*/
	virtual SRGraph* GetGraph();

	DECLARE_MESSAGE_MAP()

public:
	virtual void Printing();
	//@cmember
	/* Finds the top-most component under the mouse position*/
	virtual SRGraphComponent* GetTrackingComponent(CPoint point);

	//@cmember
	/* Pointer to an existing SRGraph-derived object -- must be set before the view is drawn*/
	SRGraph* m_pGraph;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(_GRAPHVIEW_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


