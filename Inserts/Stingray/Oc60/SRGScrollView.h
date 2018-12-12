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
//@doc SRGScrollView
//@module SRGScrollView.h | SRGScrollView header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGScrollView.h : interface of the SRGScrollView class
//
/////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __GRAPHSCROLLVW_H__
#define __GRAPHSCROLLVW_H__

//$head View classes
//$level 1

/////////////////////////////////////////////////////////////////////////////
//@doc SRGScrollView 

//@mdata BOOL  | SRGScrollView | m_bDragable | Flag which specifies whether data may be dragged

//@mdata BOOL  | SRGScrollView | m_bZoomable | Flag to define the charts ability to be zoomed -- TRUE enables zooming

//@mdata SRGraphTip  | SRGScrollView | m_GraphTip | The chart tip object for this view

//@mdata BOOL  | SRGScrollView | m_bSelecting | TRUE when a selection is in progress

//@mdata BOOL  | SRGScrollView | m_bDragging | TRUE when chart data is being dragged

//@mdata BOOL  | SRGScrollView | m_bInFeedback | TRUE when the mouse point is in a feedback area

//@mdata BOOL  | SRGScrollView | m_bShowingTip | TRUE when a chart tip is displayed

//@mdata BOOL  | SRGScrollView | m_bZoomed | TRUE when the chart is zoomed

//@mdata SRGraphComponent*  | SRGScrollView | m_pZoomedDisplay | Pointer to the zoomed display

//@mdata BOOL  | SRGScrollView | m_bMouseTimerIsRunning | TRUE when the mouse timer is running<nl>
//When the timer expires, a check is made to see if the mouse point is in a feedback area. 
//If it is, then a graph tip may be displayed.

//@mdata BOOL  | SRGScrollView | m_bUseMaxArea | TRUE when the area of the chart is set 
//at print time or during print preview

//@mdata int  | SRGScrollView | m_nValign | Vertical alignment code for pagination -- may be one of...<nl>
// CX_ALIGN_VTOP		0x00000001<nl>
// CX_ALIGN_VCENTER		0x00000002<nl>
// CX_ALIGN_VBOTTOM		0x00000003<nl>


//@mdata int  | SRGScrollView | m_nHalign | Horizontal alignment code for pagination -- may be one of...<nl>
// CX_ALIGN_NONE		0x00000000<nl>
// CX_ALIGN_HLEFT		0x00000010<nl>
// CX_ALIGN_HCENTER		0x00000020<nl>
// CX_ALIGN_HRIGHT		0x00000030<nl>

//@mdata int  | SRGScrollView | m_nPageSizeCode | Page size code used in print pagination<nl>
//Codes may be one of..<nl>
// 0		320x240 pixels<nl>
// 1		640x480 pixels<nl>
// 2		800x600 pixels<nl>
// 3		1024x768 pixels<nl>
// 4		A4 Portrait <nl>
// 5		A4 Landscape <nl>
// 6		A5 Portrait<nl>
// 7		A5 Landscape<nl>

//@mdata int  | SRGScrollView | m_nDragGroup | Group in which the dragged item is stored

//@mdata int  | SRGScrollView | m_nDragIndex | Index of the item being dragged

//@mdata int  | SRGScrollView | m_nUnzoomMinGroup | Minimum group of the un-zoomed display -- used to restore the unzoomed state

//@mdata int  | SRGScrollView | m_nUnzoomMaxGroup | Maximum group of the un-zoomed display -- used to restore the unzoomed state
//@mdata int  | SRGScrollView | m_nUnzoomMinIndex | Minimum index of the un-zoomed display -- used to restore the unzoomed state

//@mdata int  | SRGScrollView | m_nUnzoomMaxIndex | Maximum index of the un-zoomed display -- used to restore the unzoomed state

//@mdata CPoint  | SRGScrollView | m_SelectionPointA | First screen point used in defining the selection area

//@mdata CPoint  | SRGScrollView | m_SelectionPointB | Second screen point used in defining the selection area

//@mdata CPoint  | SRGScrollView | m_MousePoint | Current mouse point

//@mdata int  | SRGScrollView | m_TimerIdent | Identifier of the mouse feedback timer

//@mdata CRect  | SRGScrollView | m_OldAreaRect | Area of the chart before pagination

//@mdata BOOL  | SRGScrollView | m_bPreserveArea | When TRUE the old chart area should be restored after print preview or printing is done

//@mdata DWORD  | SRGScrollView | m_dwOldAlignment | Retains the old alignment codes during printing

//@mfunc virtual void  | SRGScrollView | SetDragable | Sets or resets the dragable flag
//@parm BOOL  | v | TRUE to enable data dragging

//@mfunc virtual BOOL  | SRGScrollView | GetDragable |  Returns the dragable flag 

//@mfunc virtual void  | SRGScrollView | SetZoomable | Sets the flag signifying whether this chart is able to zoom
//@parm BOOL  | v | TRUE to enable zooming 

//@mfunc virtual BOOL  | SRGScrollView | GetZoomable | Gets the zoom enable flag

//@mdata CPalette  | SRGScrollView | m_Palette | Our color palette

//@doc SRGScrollView
//@mdata BOOL  | SRGScrollView | m_bDragTips | TRUE if drag tips are enabled

//@doc SRGScrollView
//@mdata BOOL  | SRGScrollView | m_bHasDocument | TRUE if this view uses or needs a document


//@doc SRGScrollView
//@mdata CObStack  | SRGScrollView | m_ZoomStack | The FILO stack that contains the zoom levels

//adinsert

//@topic SRGScrollView Class Overview |
//This class provides all the functionality of an SRGraphView and adds the scrolling capabilities of CScrollView too.


//@doc SRGScrollView 
//@class This class provides a CScrollView-based alternative to the <c SRGraphView> class.
//@base public | CScrollView
class SRGScrollView : public CScrollView
{
protected: // create from serialization only
	//@cmember
	/* Constructor*/
	SRGScrollView();
	DECLARE_DYNCREATE(SRGScrollView)

	//@cmember
	/* Flag which specifies whether data may be dragged*/
	BOOL m_bDragable;
	//@cmember
	/* Called when items are being dragged*/
	virtual void MouseDrag(int nFlags,CPoint point);
	//@cmember
	/* Draws the mouse selection rectangle*/
	virtual void DrawSelection(CPoint point);

// Attributes
public:
	CGraphDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGScrollView)
	public:
	//@cmember
	/* The draw function -- overridden to draw this view*/
	virtual void OnDraw(CDC* pDC);  
	//@cmember
	/* Standard window pre-creation*/
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//@cmember
	/* Standard CView overridable -- sets the chart scroll sizes*/
		virtual void OnInitialUpdate();  // called first time after construct
	//@cmember
	/* Standard CView overridable*/
		virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//@cmember
	/* Standard CView overridable -- sets up print pagination*/
		virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	//@cmember
	/* Standard CView overridable*/
		virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Member variables
protected:
	//@cmember
	/* A FILO stack for the zoom levels */
	CObStack m_ZoomStack;
	//@cmember
	/* Flag to define the charts ability to be zoomed -- TRUE enables zooming*/
	BOOL m_bZoomable;
	//@cmember
	/* The one and only GraphTip window*/
	SRGraphTip m_GraphTip;
	//@cmember
	/* When TRUE the chart is being selected with a selecting rectangle or other shape*/
	BOOL m_bSelecting;
	//@cmember
	/* When TRUE chart data is being dragged*/
	BOOL m_bDragging;
	//@cmember
	/* When TRUE the mouse is in a feedback area*/
	BOOL m_bInFeedback;
	//@cmember
	/* When TRUE the chart tip is being displayed*/
	BOOL m_bShowingTip;
	//@cmember
	/* When TRUE the chart is zoomed in*/
	BOOL m_bZoomed;
	//@cmember
	/* Points to the display item currently being zoomed*/
	SRGraphComponent* m_pZoomedDisplay;
	//@cmember
	/* When TRUE the mouse timer is running<nl>*/
	//A timeout of this timer will trigger a feedback search and possibly initiate the display of a chart tip.
	BOOL m_bMouseTimerIsRunning;
	//@cmember
	/* When TRUE the max area of the chart is set explicitly during printing and print preview*/
	BOOL m_bUseMaxArea;
	//@cmember
	/* Vertical alignment code*/
	int m_nValign;
	//@cmember
	/* Horizontal alignment code*/
	int m_nHalign;
	//@cmember
	/* Page size code for use in pagination*/
	int m_nPageSizeCode;
	//@cmember
	/* Group in which the dragged item is stored*/
	int m_nDragGroup;
	//@cmember
	/* Index of the item being dragged*/
	int m_nDragIndex;
	//@cmember
	/* Record of the un-zoomed scope -- min group*/
	int m_nUnzoomMinGroup;
	//@cmember
	/* Record of the un-zoomed scope -- max group*/
	int m_nUnzoomMaxGroup;
	//@cmember
	/* Record of the un-zoomed scope -- min index*/
	int m_nUnzoomMinIndex;
	//@cmember
	/* Record of the un-zoomed scope -- max index*/
	int m_nUnzoomMaxIndex;
	//@cmember
	/* First selection point on screen -- used for drawing the selection area*/
	CPoint m_SelectionPointA;
	//@cmember
	/* Second selection point on screen -- used for drawing the selection area*/
	CPoint m_SelectionPointB;
	//@cmember
	/* Current mouse position*/
	CPoint m_MousePoint;



// Implementation
public:
	//@cmember
	/* Render the chart into the passed bitmap*/
	virtual void DrawToBitmap(CDC* pDC, CBitmap& bmp);

	//@cmember,mfunc
	/* Sets the semaphore that signfies that this view has a document (true) or does not (false) */
	virtual void SetHasDocument(BOOL v){m_bHasDocument=v;}
	//@cmember,mfunc
	/* Returns TRUE if this view has a document or FALSE if it does not */
	virtual BOOL GetHasDocument(){return m_bHasDocument;}

	//@cmember,mfunc
	/* Turns drag-tips on (TRUE) or off (FALSE) */
	virtual void SetDragTips(BOOL v){m_bDragTips=v;}
	//@cmember,mfunc
	/* Returns te drag-tips flag. If this is TRUE then drag-tips are enabled. Otherwise FALSE. */
	virtual BOOL GetDragTips(){return m_bDragTips;}
	//@cmember
	/* Sets or resets the dragable flag*/
	virtual void SetDragable(BOOL v){m_bDragable=v;}
	//@cmember
	/* Returns the dragable flag*/
	virtual BOOL GetDragable(){return m_bDragable;}
	//@cmember
	/* Sets the flag signifying whether this chart is able to zoom*/
	virtual void SetZoomable(BOOL v){m_bZoomable=v;}
	//@cmember
	/* Gets the zoom enable flag*/
	virtual BOOL GetZoomable(){return m_bZoomable;}
	//@cmember
	/* Override to draw the custom selection shape for your own chart type*/
	virtual void DrawCustomSelection(CPoint point);
	//@cmember
	/* Timer identifier*/
	int m_TimerIdent;
	//@cmember
	/* Displays the feedback with a chart tip -- override to add your own text formatting*/
	virtual void ShowFeedback(SRGraphFeedback *pFeedback);
	//@cmember
	/* Destructor*/
	virtual ~SRGScrollView();
#ifdef _DEBUG
	//@cmember
	/* Standard debug code */
	virtual void AssertValid() const;
	//@cmember
	/* Standard debug code */
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//@cmember
	/* Semaphore to flag the existence of document class*/
	BOOL m_bHasDocument;

	//@cmember
	/* semaphore for the draging tips*/
	BOOL m_bDragTips;

	//@cmember
	/* Color palette*/
	CPalette m_Palette;
	//@cmember
	/* Retains the old alignment codes during printing*/
	DWORD m_dwOldAlignment;
	//@cmember
	/* Retains the old alignment rectangle during printing*/
	CRect m_OldAreaRect;
	//@cmember
	/* Set TRUE if the area should be restored after printing*/
	BOOL m_bPreserveArea;
	//@cmember
	/* Creates and returns an SRGraphPosition object filled with data about the chart item under the specified point*/
	virtual SRGraphPosition * GetPosition(SRGraph *pGraph, CPoint point);
	//@cmember
	/* Returns a pointer to the graph object*/
	virtual SRGraph *GetGraph();
	//{{AFX_MSG(SRGScrollView)
	//@cmember
	/* Overridden to do nothing*/
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//@cmember
	/* Begins the selection or dragging process*/
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//@cmember
	/* Ends the selection or dragging process*/
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//@cmember
	/* Handles the selection or dragging of data items*/
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//@cmember
	/* Handles the chart-tip timing and display*/
	afx_msg void OnTimer(UINT nIDEvent);
	//@cmember
	/* Copies the screen bitmap to the clipboard for pasting into another application*/
	afx_msg void OnEditCopy();
	//@cmember,mfunc
	/* Handles graph zoomout command*/
	afx_msg void OnGraphZoomout();
	//@cmember
	/* Updates the graph-zoomout menu command*/
	afx_msg void OnUpdateGraphZoomout(CCmdUI* pCmdUI);
	//@cmember
	/* Displays the print pagination setup dialog*/
	afx_msg void OnGraphPagesetup();
	//@cmember
	/* Handles the GraphEdit command*/
	afx_msg void OnGraphEdit();
	//@cmember
	/* Creation initialization -- creates a color palette if required*/
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	//@cmember
	/* Palette management*/
	afx_msg BOOL OnQueryNewPalette();
	//@cmember
	/* Palette management*/
	afx_msg void OnPaletteChanged(CWnd* pFocusWnd);
	//@cmember,mfunc
	/* Message handler for the Graph Wizard menu item */
	afx_msg void OnGraphWizard();
	//@cmember,mfunc
	/* Message handler for the Save As DIB menu item */
	afx_msg void OnSaveAsDib();
	//@cmember,mfunc
	/* Message handler for the Save As JPEG menu item */
	afx_msg void OnSaveAsJpeg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#ifndef _DEBUG  // debug version in SRGScrollView.cpp
inline CGraphDoc* SRGScrollView::GetDocument()
   { return (CGraphDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
#endif // __GRAPHSCROLLVW_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


