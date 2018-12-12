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
// @doc SRGraphView
// @module GraphVw.h | SRGraphView header file<nl>
// Also includes CSelectQuery and PageSetup<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)
/////////////////////////////////////////////////////////////
//
#include "ObStack.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __GRAPHVW_H__
#define __GRAPHVW_H__


// GraphVw.h : interface of the SRGraphView class
//

/////////////////////////////////////////////////////////////////////////////
// PageSetup dialog

//@doc PageSetup

//$head Dialogs used by the view classes
//$level 1

// using cmember tags only for typical dialog functions

//@mdata BOOL | PageSetup | m_bUseMaxArea | Set TRUE if the page should be limited in size during printing
//@rem The PageSetup dialog allows standard sizes of display or a selection of paper sizes to be chosen and a 
//simple alignment to be specified.

//@mdata int | PageSetup | m_nValign | Vertical alignment code for print pagination
//@rem May be... Align to top of page, center, or bottom of page, or none

//@mdata int | PageSetup | m_nHalign | Horizontal alignment code for print pagination
//@rem May be... Align to left, center, or right of page, or none

//@mdata CComboBox  | PageSetup | m_Size | Combo box for page size selection

//@mdata int | PageSetup | m_nPageSizeCode | Selected page size from combo box
//@rem The following standard page sizes are available:<nl><nl>
// 320 X 240<nl>
// 640 X 480<nl>
// 800 X 600<nl>
//1024 X 768<nl>
//A5<nl>
//A4<nl>


//adinsert

//$head Miscellaneous dialog classes
//$level 1

//@topic PageSetup Class Overview |
//This simple class allows print pagination for charts. This class could be modified to provide other paper sizes.

//@class PageSetup - Dialog for setting options for placing graph on printed page
//@base public | CDialog
class PageSetup : public CDialog
{
// Construction
public:
	//@cmember
	/* Standard constructor*/
	PageSetup(CWnd* pParent = NULL);   // standard constructor

	//@cmember
	/* Selected page size code from combo box*/
	int m_nPageSizeCode;

// Dialog Data
	//{{AFX_DATA(PageSetup)
	enum { IDD = IDD_GVW_PAGESETUP };
	//@cmember
	/* Combo box for page size selection*/
	CComboBox	m_Size;
	//@cmember
	/* Set TRUE if the page should be limited in size during printing*/
	BOOL	m_bUseMaxArea;
	//@cmember
	/* Vertical alignment code for print pagination*/
	int		m_nValign;
	//@cmember
	/* Horizontal alignment code for print pagination*/
	int		m_nHalign;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSetup)
	protected:
	//@cmember,mfunc
	/* Standard dialog data excange */
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageSetup)
	//@cmember
	/* Initializes controls, calls <mf PageSetup::OnGvwCheck1>*/
	virtual BOOL OnInitDialog();
	//@cmember
	/* Retrieves user selections from controls and closes the dialog*/
	virtual void OnOK();
	//@cmember
	/* Enables or disables alignment radio buttons according to state of Use Max Size check box*/
	afx_msg void OnGvwCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};






/////////////////////////////////////////////////////////////////////////////
// CSelectQuery dialog

//@doc CSelectQuery 

// using cmember tags only for this simple dialog class


//@doc CSelectQuery
//@mdata int   | CSelectQuery | m_Selection | Holds the radiobutton results

//@mdata void | CSelectQuery | CSelectQuery | Constructor.

//@doc CSelectQuery
//@mfunc virtual void  | CSelectQuery | DoDataExchange | Standard dialog data exchange. 

//adinsert

//$head Miscellaneous dialog classes
//$level 1

//@doc CSelectQuery 
//@class CSelectQuery - dialog displayed when user selects data items including both groups and indices 
//@base public | CDialog
class CSelectQuery : public CDialog
{
// Construction
public:
	//@cmember
	/* Standard constructor*/
	CSelectQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectQuery)
	enum { IDD = IDD_GVW_SELECTQUERY1 };
	//@cmember
	/* Radio button index specifying type of data items desired*/
	int		m_Selection;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectQuery)
	protected:
	//@cmember
	/* Standard dialog data exchange */
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectQuery)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#define MOUSE_TIMER_EVENT 3860

//$head View classes
//$level 1


//@doc SRGraphView

// data members

//@mdata BOOL | SRGraphView | m_bUseMaxArea | TRUE if the page should be limited in size during printing
//@rem The PageSetup dialog allows standard sizes of display or a selection of paper sizes to be chosen and a 
//simple alignment to be specified.

//@mdata int | SRGraphView | m_nValign | Vertical alignment code for print pagination
//@rem May be... Align to top of page, centre, or bottom of page, or none

//@mdata int | SRGraphView | m_nHalign | Horizontal alignment code for print pagination
//@rem May be... Align to left, centre, or right of page, or none

//@mdata int | SRGraphView | m_nPageSizeCode | Selected page size from PageSetup dialog
//@rem The following standard page sizes are available:<nl><nl>
// 320 X 240<nl>
// 640 X 480<nl>
// 800 X 600<nl>
//1024 X 768<nl>
//A5<nl>
//A4<nl>

//@mdata UINT | SRGraphView | m_TimerIdent | Mouse timer identifier

//@mdata SRGraphTip | SRGraphView | m_GraphTip | The single graph tip object

//@mdata DWORD | SRGraphView | m_dwSelectionType | Current selection type -- horizontal, vertical, box, or circular

//@mdata int | SRGraphView | m_nUnzoomMinIndex | The graph's original minimum index (used for unzooming data)

//@mdata int | SRGraphView | m_nUnzoomMaxIndex |  The graph's original maximum index (used for unzooming data)

//@mdata int | SRGraphView | m_nUnzoomMinGroup | The graph's original minimum group (used for unzooming data)

//@mdata int | SRGraphView | m_nUnzoomMaxGroup | The graph's original maximum group (used for unzooming data)

//@mdata SRGraphComponent * | SRGraphView | m_pZoomedDisplay |	Pointer to the display which has been zoomed (used to restore the original state)

//@mdata BOOL | SRGraphView | m_bZoomed | TRUE if the graph has been zoomed (used to activate the unzoom menu command via the command update interface)

//@mdata BOOL | SRGraphView | m_bShowingTip | TRUE if a graph tip is currently on display -- a call for a new tip will recycle the old one

//@mdata CPoint | SRGraphView | m_SelectionPointA | First point in a selection area

//@mdata CPoint | SRGraphView | m_SelectionPointB | Last point in a selection area

//@mdata BOOL | SRGraphView | m_bSelecting | TRUE if the graph is in selection box mode

//@mdata BOOL | SRGraphView | m_bInFeedback | TRUE if the mouse point was clicked inside a feedback area (data dragging will commence)

//@mdata int | SRGraphView | m_nDragIndex | Index of the data item being dragged

//@mdata int | SRGraphView | m_nDragGroup | Group of the data item being dragged

//@mdata BOOL | SRGraphView | m_bDragging | TRUE if dragging is in progress

//@mdata CPoint | SRGraphView | m_MousePoint | Stored mouse position (used to ascertain if the mouse has remained still for the requisite 1.5 seconds)

//@mdata BOOL | SRGraphView | m_bMouseTimerIsRunning | TRUE if the mouse is considered to be "still" and the timeout is waiting to fire

//@mdata BOOL  | SRGraphView | m_bZoomable | Flag to enable or disable the zooming process -- TRUE to enable chart zooming

//@mdata BOOL  | SRGraphView | m_bDragable | Flag which specifies whether data may be dragged

//@mdata BOOL  | SRGraphView | m_bHasDocument | Flag to signify whether this view has a document

//@mdata CObStack  | SRGraphView | m_ZoomStack | First-in last-out stack for storing and recovering zoomed states

//@mdata CPalette  | SRGraphView | m_Palette | Color palette to use in drawing the graph

// inline functions

//@mfunc void  | SRGraphView | SetDragable | Sets the m_Draggable flag which allows data to be dragged
//@parm BOOL  | v | TRUE to allow dragging, FALSE to disable dragging

//@mfunc BOOL  | SRGraphView | GetDragable | Returns the m_Draggable flag -- TRUE if data may be dragged

//@mfunc void  | SRGraphView | SetZoomable | Call to set or reset the m_bZoomable flag -- TRUE if zooming is allowed 
//@parm BOOL  | v | TRUE to enable zooming, FALSE to disable

//@mfunc BOOL  | SRGraphView | GetZoomable | Returns the zoomable flag -- TRUE if the chart may be zoomed

//@mfunc void  | SRGraphView | SetHasDocument | Sets m_bHasDocument flag to indicate that this view has a document 
//@parm BOOL  | v | TRUE if view has a document, FALSE if it does not 

//@mfunc BOOL  | SRGraphView | GetHasDocument | Returns the m_bHasDocument flag -- TRUE if this view has a document 


//@doc SRGraphView
//@mdata BOOL  | SRGraphView | m_bDragTips | This will be set to TRUE if drag tips are enabled. Drag tips are numerical chart tips that change as data is dragged on the display.

//@doc SRGraphView
//@mfunc virtual void  | SRGraphView | SetDragTips | Sets the semaphore that enables or disables drag tips.
//@parm BOOL  | v | TRUE to enable FALSE to disable


//@doc SRGraphView
//@mfunc virtual BOOL  | SRGraphView | GetDragTips | Returns TRUE if drag tips are enabled, FALSE if disabled.

//adinsert

//@doc SRGraphView
//@class Specialized view class for the display and management of SRGraph objects<nl>
//This CView-based class simply adds graph feedback, data dragging, and data zooming 
//to your graph and chart applications.
//@base public | CView
//@devnote The classes for PageSetup and CSelectQuery are also in the files of this class.
class SRGraphView : public CView
{
protected:
	//@cmember
	/* Set TRUE if the page should be limited in size during printing*/
	BOOL m_bUseMaxArea;
	//@cmember
	/* Vertical alignment code for print pagination*/
	int m_nValign;
	//@cmember
	/* Horizontal alignment code for print pagination*/
	int m_nHalign;
	//@cmember
	/* Code for selected page sizes*/
	int m_nPageSizeCode;
	//@cmember
	/* Mouse timer identifier*/
	UINT m_TimerIdent;
	//@cmember
	/* The single graph tip object*/
	SRGraphTip m_GraphTip;
	//@cmember
	/* Current selection type -- horizontal, vertical, box, or circular*/
	DWORD m_dwSelectionType;
	//@cmember
	/* Original minimum index (used for unzooming data)*/
	int m_nUnzoomMinIndex;
	//@cmember
	/* Original maximum index (used for unzooming data)*/
	int m_nUnzoomMaxIndex;
	//@cmember
	/* Original minimum group (used for unzooming data)*/
	int m_nUnzoomMinGroup;
	//@cmember
	/* Original maximum group (used for unzooming data)*/
	int m_nUnzoomMaxGroup;
	//@cmember
	/* Pointer to the display which has been zoomed (used in restoration of the original state)*/
	SRGraphComponent * m_pZoomedDisplay;
	//@cmember
	/* TRUE if the graph has been zoomed (used to activate the unzoom menu command via the command update interface)*/
	BOOL m_bZoomed;
	//@cmember
	/* TRUE if a graph tip is currently on display*/
	BOOL m_bShowingTip;
	//@cmember
	/* First point in a selection area*/
	CPoint m_SelectionPointA;
	//@cmember
	/* Last point in a selection area*/
	CPoint m_SelectionPointB;
	//@cmember
	/* TRUE if the graph is in selection box mode*/
	BOOL m_bSelecting;
	//@cmember
	/* TRUE if the mouse point was clicked inside a feedback area (data dragging will commence)*/
	BOOL m_bInFeedback;
	//@cmember
	/* Index of the data item being dragged*/
	int m_nDragIndex;
	//@cmember
	/* Group of the data item being dragged*/
	int m_nDragGroup;
	//@cmember
	/* TRUE if dragging is in progress*/
	BOOL m_bDragging;
	//@cmember
	/* Stored mouse position (used to ascertain if the mouse has rested still for the requisite 1.5 seconds)*/
	CPoint m_MousePoint;
	//@cmember
	/* TRUE if the mouse is considered to be "still" and the timeout is waiting to fire*/
	BOOL m_bMouseTimerIsRunning;
	//@cmember
	/* Flag to define the charts ability to be zoomed -- TRUE enables zooming*/
	BOOL m_bZoomable;
	//@cmember
	/* Flag which specifies whether data may be dragged*/
	BOOL m_bDragable;
	//@cmember
	/* Flag to signify whether this view has a document*/
	BOOL m_bHasDocument;


public:

	//@cmember
	/* Constructor*/
	SRGraphView(); // moved to the public section as an experiment...

	DECLARE_DYNCREATE(SRGraphView)

// Attributes
public:
	//@cmember
	/* Set or resets the m_bDragTips flag*/
	virtual void SetDragTips(BOOL v){m_bDragTips=v;}
	//@cmember
	/* Return the m_bDragTips flag*/
	virtual BOOL GetDragTips(){return m_bDragTips;}
	//@cmember
	/* Sets or resets the m_bDragable flag*/
	virtual void SetDragable(BOOL v){m_bDragable=v;}
	//@cmember
	/* Returns the m_bDragable flag*/
	virtual BOOL GetDragable(){return m_bDragable;}
	//@cmember
	/* Sets or resets the flag signifying whether this chart is able to zoom*/
	virtual void SetZoomable(BOOL v){m_bZoomable=v;}
	//@cmember
	/* Returns the zoom enable flag*/
	virtual BOOL GetZoomable(){return m_bZoomable;}
	//@cmember
	/* Draws a selecting box*/
	virtual void DrawSelection(CPoint point);
	//@cmember
	/* Override this function to draw your own selection styles*/
	virtual void DrawCustomSelection(CPoint point);
	//@cmember
	/* Handles data dragging and selection box display*/
	virtual void MouseDrag(int nFlags,CPoint point);
	//@cmember,mfunc
	/* Returns the document for this view*/
	CGraphDoc* GetDocument();
	//@cmember
	/* Sets or resets the m_bHasDocument flag*/
	virtual void SetHasDocument(BOOL v){m_bHasDocument=v;}
	//@cmember
	/* Returns the m_bHasDocument flag*/
	virtual BOOL GetHasDocument(){return m_bHasDocument;}

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphView)
	public:
	//@cmember
	/* Draws the graph*/
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	protected:
	//@cmember
	/* Prepares the print job*/
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//@cmember
	/* Performs print pagination and outputs the graph to the printer*/
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	//@cmember
	/* Completes printing and terminates print mode*/
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Render the chart into the passed bitmap*/
	virtual void DrawToBitmap(CDC* pDC, CBitmap& bmp);
	//@cmember
	/*  Returns a SRGraphPosition object in response to a mouse event -- override */
	virtual SRGraphPosition * GetPosition(SRGraph *pGraph,CPoint point);
	//@cmember
	/* Destructor*/
	virtual ~SRGraphView();
#ifdef _DEBUG
	//@cmember,mfunc
	/* Standard debug code */
	virtual void AssertValid() const;
	//@cmember,mfunc
	/* Standard debug code */
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//@cmember
	/* Returns a pointer to the graph object which this view displays and interfaces to*/
	virtual SRGraph * GetGraph();
	//@cmember
	/* Displays a feedback chart tip -- override*/
	virtual void ShowFeedback(SRGraphFeedback *pFeedback);
	//@cmember
	/* Saves current view as a DIB file. */
	virtual void SaveToFileAsDib(LPCTSTR lpszFileName);
	//@cmember
	/* Saves the current view's image as a JPEG */
	virtual void SaveToFileAsJpeg(LPCTSTR lpszFileName);

protected:
	//@cmember
	/* Semaphore for the draging tips*/
	BOOL m_bDragTips;
	//@cmember
	/* First-in last-out stack of zoomed states*/
	CObStack m_ZoomStack;
	//@cmember
	/* Color palette*/
	CPalette m_Palette;

// Generated message map functions
	//{{AFX_MSG(SRGraphView)
	//@cmember
	/* Does nothing*/
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//@cmember
	/* Handles mouse movement and chart tip triggering*/
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//@cmember
	/* Handles mouse button press*/
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//@cmember
	/* Handles mouse button release*/
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//@cmember
	/* Checks to see if a chart tip is needed*/
	afx_msg void OnTimer(UINT nIDEvent);
	//@cmember
	/* Copies the image to the clipboard*/
	afx_msg void OnEditCopy();
	//@cmember
	/* Returns zoomed graph to normal size*/
	afx_msg void OnGraphZoomout();
	//@cmember
	/* Activates or deactivates the zoom out button and menu items*/
	afx_msg void OnUpdateGraphZoomout(CCmdUI* pCmdUI);
	//@cmember
	/* Runs a simple pagination dialog*/
	afx_msg void OnGraphPagesetup();
	//@cmember
	/* Edits a graph using the Graph Explorer*/
	afx_msg void OnGraphEdit();
	//@cmember,mfunc
	/* Message handler for the Save As DIB menu item */
	afx_msg void OnSaveAsDib();
	//@cmember,mfunc
	/* Message handler for the Save As JPEG menu item */
	afx_msg void OnSaveAsJpeg();
	//@cmember,mfunc
	/* Invokes the chart wizard */
	afx_msg void OnGraphWizard();
	//@cmember
	/* Creation initialization*/
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	//@cmember
	/* Palette management*/
	afx_msg BOOL OnQueryNewPalette();
	//@cmember
	/* Palette management */
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#ifndef _DEBUG  // debug version in GraphView.cpp
inline CGraphDoc* SRGraphView::GetDocument()
   { return (CGraphDoc*)m_pDocument; }
#endif

#endif // __GRAPHVW_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

/////////////////////////////////////////////////////////////////////////////

