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

////////////////////////////////////////////////
//@doc SRGDisplayBase
//@module SRGDisplayBase.h | Class definition file for the SRGDisplayBase class<nl>
//This class is an abstract base class used to facillitate the conversion of OC to a lighter format
//Copyright <cp>Stingray Software 1996, 1997, 1998<nl>
//Written by Bob Powell (www.stingray.com)

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#if !defined(_SRGDISPLAYBASE_H_INCLUDED_)
#define _SRGDISPLAYBASE_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SRGraphTitle.h"
#include "SRGDat.h"	// Added by ClassView

/////////////////////////////
// AutoDuck tag block for SRGDisplayBase 

//@doc SRGDisplayBase
//@mdata CScale  | SRGDisplayBase | m_oZoomStateY | The Y scale zoom state.

//@doc SRGDisplayBase
//@mdata CScale  | SRGDisplayBase | m_oZoomStateX | The X scale zoom state.

//@doc SRGDisplayBase
//@mfunc virtual void  | SRGDisplayBase | SetZoomStateY | Sets the Y scale zoom state. This keeps a record of the zoom level between draw cycles.
//@parm CScale  | v | The zoom level to retain.


//@doc SRGDisplayBase
//@mfunc virtual CScale  | SRGDisplayBase | GetZoomStateY | Returns the current Y scale zoom state.


//@doc SRGDisplayBase
//@mfunc virtual void  | SRGDisplayBase | SetZoomStateX | Sets the X scale zoom state. This keeps a record of the zoom level between draw cycles.
//@parm CScale  | v | The zoom level to retain.


//@doc SRGDisplayBase
//@mfunc virtual CScale  | SRGDisplayBase | GetZoomStateX | Returns the current X scale zoom state. 

//@mdata double | SRGDisplayBase | m_dMaxRangeY |  Maximum range which this display will show on its axes
//@rem If this range is exceeded by the data, there is no overflow procedure. It is the responsibility of
//the application to keep data within the correct range when these limits are used.
//@see <mf SRGDisplayBase::SetMaxRange>  <mf SRGDisplayBase::GetMaxRange>

//@mdata double | SRGDisplayBase | m_dMaxScaleY | Used internally to calculate the scaling factor for data<nl>
//This variable is usually set by taking the maximum range of data and multiplying by 1.1. 
//This ensures a maximum data scale which is always a little bit larger than the data in the graph. 
//Axes, labels and, scales are all re-calculated using this number to keep data from 
//overflowing the display area.

//@mdata CRect | SRGDisplayBase | m_LabelRectX | Rectangle used during the drawing of X labels

//@mdata CRect | SRGDisplayBase | m_LabelRectY | Rectangle used during the drawing of Y labels

//@mdata CRect | SRGDisplayBase | m_DisplayRect | Rectangle which contains the usable data display area 
//@rem The rectangle starts out each draw cycle with the whole component area. 
//As items are drawn, this rectangle is reduced in size so that subsequent items know how much 
//area is left to work with. For example, the component reduces the area to account 
//for its borders. The labels then reduce the area to account for their widths and heights 
//leaving the axis and data to be drawn in the area that is left.

//@mdata CRect | SRGDisplayBase | m_DrawnRect | Record of the previous final m_DisplayRect value
//@see <md SRGDisplayBase::m_DisplayRect>

//@mdata BOOL | SRGDisplayBase | m_bDisplayDrawn | Set to TRUE when the display has been drawn at least once

//@mdata CPtrList | SRGDisplayBase | m_XTickList | The X, Y and Z tick lists are optionally 
//built by the label system to allow accurate positioning of the tick marks and grid lines.
//@rem The tick list contains a simple CPoint list. Each point is derived directly from the 
//position of a label used on the graph's axes. These positions are normally only used to 
//position the ticks or grid lines vertically or horizontally.

//@mdata SRGraphLabelBlock * | SRGDisplayBase | m_ptrXLabels | The X, Y and Z label pointers 
//are placeholders for any one of the SRGraphLabelBlock (or derived) objects. 
//The axis drawing system will normally assign a semi-permanent label block 
//(<c SRGraphLabelBlock>) or decimal scale (<c SRGDecimalScale>) to one of these pointers 
//for the duration of its existence. Keeping the same label block and modifying it requires 
//far less time than constantly creating and destroying large, complex objects on the stack.

//@mdata SRGraphLabelBlock *  | SRGDisplayBase | m_ptrYLabels | Pointer to the Y label scale
//@see <md SRGDisplayBase::m_ptrXLabels>

//@mdata SRGraphLabelBlock *  | SRGDisplayBase | m_ptrZLabels | Pointer to the Z label scale
//@see <md SRGDisplayBase::m_ptrXLabels>

//@mdata BOOL  | SRGDisplayBase | m_bPrepared | TRUE if the display has been prepared for drawing

//@mdata BOOL  | SRGDisplayBase | m_bUnZoomY | TRUE if the Y axis has been zoomed (only used for scatter graphs)

//@mdata BOOL  | SRGDisplayBase | m_bUnZoomX | TRUE if the X axis has been zoomed (only used for scatter graphs)

//@mdata double  | SRGDisplayBase | m_dMaxRangeX | Maximum allowed X value 
//@mdata double  | SRGDisplayBase | m_dMinRangeX | Minimum allowed X value 

//@mdata double  | SRGDisplayBase | m_dMinRangeY | Minimum allowed Y value 

//@mdata double  | SRGDisplayBase | m_dMaxScaleX | Minimum usable X scale 

//@mdata CPtrList  | SRGDisplayBase | m_YTickList | Pointer to the list of CPoint objects that will be updated by the Y labels

//@mdata CPtrList  | SRGDisplayBase | m_ZTickList | Pointer to the list of CPoint objects that will be updated by the Z labels

//@mdata CScale  | SRGDisplayBase | m_ZoomScaleY | Scale used when zooming the Y axis for scatter charts

//@mdata CScale  | SRGDisplayBase | m_ZoomScaleX | Scale used when zooming the X axis for scatter charts

//@mfunc void  | SRGDisplayBase | SetptrXLabels | Initializes the X labels with an externally created label class 
//@parm SRGraphLabelBlock *  | v | Pointer to label block

//@mfunc SRGraphLabelBlock * | SRGDisplayBase | GetptrXLabels | Retrieves the X labels so that they may be modified 
//@rdesc Pointer to label block

//@mfunc void  | SRGDisplayBase | SetptrYLabels | Initializes the Y labels with an externally created label class
//@parm SRGraphLabelBlock *  | v | Pointer to label block

//@mfunc SRGraphLabelBlock * |SRGDisplayBase | GetptrYLabels | Retrieves the Y labels so that they may be modified  
//@rdesc Pointer to label block

//@mfunc void  | SRGDisplayBase | SetptrZLabels | Initializes the Z labels with an externally created label class
//@parm SRGraphLabelBlock *  | v | Pointer to label block 

//@mfunc SRGraphLabelBlock * | SRGDisplayBase | GetptrZLabels | Retrieves the Z labels so that they may be modified  
//@rdesc Pointer to label block

//@mfunc virtual void  | SRGDisplayBase | CleanZoomScaleX | Zeroes the X data zooming scale -- currently only used for scattergraphs

//@mfunc virtual void  | SRGDisplayBase | CleanZoomScaleY | Zeroes the Y data zooming scale -- currently only used for scattergraphs

//@mfunc virtual CRect  | SRGDisplayBase | GetDisplayRect | Returns the display rectangle

//@mfunc virtual double  | SRGDisplayBase | GetMaxScaleY | Returns the m_dMaxScaleY member

//@mfunc virtual double  | SRGDisplayBase | GetMaxScaleX | Returns the m_dMaxScaleX member

//@mfunc virtual CPtrList * | SRGDisplayBase | GetXTickList | Returns the X tick list

//@mfunc virtual CPtrList * | SRGDisplayBase | GetYTickList | Returns the Y tick list

//@mfunc virtual CPtrList * | SRGDisplayBase | GetZTickList | Returns the Z tick list

//@mfunc virtual CScale  | SRGDisplayBase | GetZoomScaleX | Returns the X data zooming scale -- currently only used for scattergraphs

//@mfunc virtual CScale  | SRGDisplayBase | GetZoomScaleY | Returns the Y data zooming scale -- currently only used for scattergraphs

//@mfunc virtual void  | SRGDisplayBase | SetZoomScaleX | Sets the X data zooming scale -- currently only used for scattergraphs
//@parm CScale  | scale | CScale object containing the desired limits

//@mfunc virtual void  | SRGDisplayBase | SetZoomScaleY | Sets the Y data zooming scale -- currently only used for scattergraphs
//@parm CScale  | scale | CScale object containing the desired limits

//@mfunc virtual void  | SRGDisplayBase | SetUnZoomY | Initializes the Y unzoom semaphore
//@parm BOOL  | v | TRUE if Y is zoomed 

//@mfunc virtual BOOL  | SRGDisplayBase | GetUnZoomY | Retrieves the Y unzoom semaphore

//@mfunc virtual void  | SRGDisplayBase | SetUnZoomX | Initializes the X unzoom semaphore
//@parm BOOL  | v | TRUE if X is zoomed

//@mfunc virtual BOOL  | SRGDisplayBase | GetUnZoomX | Retrieves the X unzoom semaphore



// adinsert AutoDuck insertion point for SRGDisplayBase 
//$head Component classes
//$level 1



//@doc SRGDisplayBase 
//@class Abstract base class for graph display components including <c SRGraphDisplay> -- inherits font abilities from SRGraphTitle
//@base public | SRGraphTitle
class SRGDisplayBase : public SRGraphTitle  
{

	DECLARE_DYNAMIC(SRGDisplayBase);

public:
	//@cmember
	/* Constructor*/
	SRGDisplayBase();

	//@cmember
	/* Destructor*/
	virtual ~SRGDisplayBase();

//@access Protected data members
protected:
	//@cmember
	/* Y scale to be used when data is zoomed up -- used only on XY Scatter graphs for the moment*/
	CScale m_ZoomScaleY;
	//@cmember
	/* X scale to be used when data is zoomed up -- used only on XY Scatter graphs for the moment*/
	CScale m_ZoomScaleX;
	//@cmember
	/* Minimum Y numeric value allowed for this graph*/
	double m_dMinRangeY;
	//@cmember
	/* Maximum Y numeric value allowed for this graph*/
	double m_dMaxRangeY;
	//@cmember
	/* Maximum Y scale of the values in this graph display*/
	double m_dMaxScaleY;
	//@cmember
	/* Minimum X numeric value allowed for this graph*/
	double m_dMinRangeX;
	//@cmember
	/* Maximum X numeric value allowed for this graph*/
	double m_dMaxRangeX;
	//@cmember
	/* Maximum X scale of the values in this graph display*/
	double m_dMaxScaleX;

	//@cmember
	/* Pointer to a block of labels used to annotate the X axis*/
	SRGraphLabelBlock * m_ptrXLabels;
	//@cmember
	/* Pointer to a block of labels used to annotate the Y axis*/
	SRGraphLabelBlock * m_ptrYLabels;
	//@cmember
	/* Pointer to a block of labels used to annotate the Z axis*/
	SRGraphLabelBlock * m_ptrZLabels;

	//@cmember
	/* List of points which have been provided by the X label block -- used to position tick marks and grid lines*/
	CPtrList m_YTickList;
	//@cmember
	/* List of points which have been provided by the Y label block -- used to position tick marks and grid lines*/
	CPtrList m_XTickList;
	//@cmember
	/* List of points which have been provided by the Z label block -- used to position tick marks and grid lines*/
	CPtrList m_ZTickList;

	//@cmember
	/* Rectangle enclosing the X labels*/
	CRect m_LabelRectX;
	//@cmember
	/* Rectangle enclosing the Y labels*/
	CRect m_LabelRectY;
	//@cmember
	/* Display rectangle -- initially the whole component display area, resized according to room taken up by labels, etc.*/
	CRect m_DisplayRect;
	//@cmember
	/* Previously drawn rectangle*/
	CRect m_DrawnRect;

	//@cmember
	/* Semaphore - TRUE if the display has been drawn*/
	BOOL m_bDisplayDrawn;

	//@cmember
	/* Flag signifying that the chart has been prepared for this draw cycle*/
	BOOL m_bPrepared;

	//@cmember
	/* Flag signifying that the X axis is zoomed*/
	BOOL m_bUnZoomY;

	//@cmember
	/* Flag signifying that the Y axis is zoomed*/
	BOOL m_bUnZoomX;

//@access Public member functions
public:
	//@cmember
	/* Initializes the Y unzoom semaphore*/
	virtual void SetUnZoomY(BOOL v){m_bUnZoomY=v;}
	//@cmember
	/* Retrieves the Y unzoom semaphore*/
	virtual BOOL GetUnZoomY(){return m_bUnZoomY;}
	//@cmember
	/* Initializes the X unzoom semaphore*/
	virtual void SetUnZoomX(BOOL v){m_bUnZoomX=v;}
	//@cmember
	/* Retrieves the X unzoom semaphore*/
	virtual BOOL GetUnZoomX(){return m_bUnZoomX;}

	//@cmember
	/* Calculates font sizes for the display class*/
	virtual int CalcFontAutoSize();

	//@cmember
	/* Prepares the chart*/
	virtual void Prepare();

	//@cmember
	/* Initializes the X labels with an externally created label class*/
	virtual void SetptrXLabels(SRGraphLabelBlock * v){m_ptrXLabels=v;}

	//@cmember
	/* Retrieves the X labels so that they may be modified*/
	virtual SRGraphLabelBlock * GetptrXLabels(){return m_ptrXLabels;}

	//@cmember
	/* Initializes the Y labels with an externally created label class*/
	virtual void SetptrYLabels(SRGraphLabelBlock * v){m_ptrYLabels=v;}

	//@cmember
	/* Retrieves the Y labels so that they may be modified*/
	virtual SRGraphLabelBlock * GetptrYLabels(){return m_ptrYLabels;}

	//@cmember
	/* Initializes the Z labels with an externally created label class*/
	virtual void SetptrZLabels(SRGraphLabelBlock * v){m_ptrZLabels=v;}

	//@cmember
	/* Retrieves the Z labels so that they may be modified*/
	virtual SRGraphLabelBlock * GetptrZLabels(){return m_ptrZLabels;}

	//@cmember
	/* Stores or retrieves this object*/
	virtual void Serialize(CArchive& ar);

	//@cmember
	/* Returns the m_dMaxScaleY member*/
	virtual double GetMaxScaleY(){return m_dMaxScaleY;}

	//@cmember
	/* Returns the m_dMaxScaleX member*/
	virtual double GetMaxScaleX(){return m_dMaxScaleX;}

	//@cmember
	/* Refreshes the display after a change is made to the graph type after its first draw cycle*/
	virtual void Refresh();

#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Reads a single line from the graph template */
	virtual int ReadTemplateLine(LPCTSTR line);

	//@cmember
	/* Writes the name of this component to a file*/
	virtual void WriteName(CStdioFile* file);

	//@cmember
	/* Writes component parameters for Display components to a file*/
	virtual void WriteSpecificParameters(CStdioFile* file);
#endif // _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember
	/* Sets the X data zooming scale -- currently only used for scattergraphs*/
	virtual void SetZoomScaleX(CScale scale){m_ZoomScaleX=scale;}

	//@cmember
	/* Sets the Y data zooming scale -- currently only used for scattergraphs*/
	virtual void SetZoomScaleY(CScale scale){m_ZoomScaleY=scale;}

	//@cmember
	/* Gets the X data zooming scale -- currently only used for scattergraphs*/
	virtual CScale GetZoomScaleX(){return m_ZoomScaleX;}

	//@cmember
	/* Gets the Y data zooming scale -- currently only used for scattergraphs*/
	virtual CScale GetZoomScaleY(){return m_ZoomScaleY;}

	//@cmember
	/* Zeroes the X data zooming scale -- currently only used for scattergraphs*/
	virtual void CleanZoomScaleX(){m_ZoomScaleX.Zero();}

	//@cmember
	/* Zeroes the Y data zooming scale -- currently only used for scattergraphs*/
	virtual void CleanZoomScaleY(){m_ZoomScaleY.Zero();}

	//@cmember
	/* Returns the display rectangle*/
	virtual CRect GetDisplayRect(){return m_DisplayRect;}

	//@cmember
	/* Returns the minimum numeric value allowed for this graph's Y axis*/
 	virtual double GetMinRangeY();

	//@cmember
	/* Retrieves the maximum numeric value allowed for this graph*/
	virtual double GetMaxRangeY();

	//@cmember
	/* Sets the minimum numeric value allowed for this graph*/
	virtual void SetMinRangeY(double dValue);

	//@cmember
	/* Sets the maximum numeric value allowed for this graph*/
	virtual void SetMaxRangeY(double dValue);

	//@cmember
	/* Retrieves the minimum numeric X value allowed for this graph*/
	virtual double GetMinRangeX();

	//@cmember
	/* Retrieves the maximum numeric X value allowed for this graph*/
	virtual double GetMaxRangeX();

	//@cmember
	/* Sets the minimum numeric Y value allowed for this graph*/
	virtual void SetMinRangeX(double dValue);

	//@cmember
	/* Sets the maximum numeric Y value allowed for this graph*/
	virtual void SetMaxRangeX(double dValue);

	//@cmember
	/* Allows initialization and locking of the display rectangle*/
	virtual void SetDisplayRect(CRect r,BOOL lock=FALSE);

	//@cmember
	/* Initializes the Y scale zoom state */
	virtual void SetZoomStateY(CScale v){m_oZoomStateY=v;}
	//@cmember
	/* Returns the Y scale zoom state */
	virtual CScale GetZoomStateY(){return m_oZoomStateY;}
	//@cmember
	/* Initializes the X scale zoom state */
	virtual void SetZoomStateX(CScale v){m_oZoomStateX=v;}
	//@cmember
	/* Returns the X scale zoom state */
	virtual CScale GetZoomStateX(){return m_oZoomStateX;}


//@access Protected member functions
protected:
	//@cmember
	/* The Y scale zoom state. */
	CScale m_oZoomStateY;
	//@cmember
	/* The Y scale zoom state. */
	CScale m_oZoomStateX;
	//@cmember
	/* Displays the data representation -- called from DrawForeground*/
	virtual void DrawData();

	//@cmember
	/* Displays the axes -- called from DrawForeground*/
	virtual void DrawAxis();

	//@cmember
	/* Displays the labels -- called from DrawForeground*/
	virtual void DrawLabels();

	//@cmember
	/* Displays the graph data*/
	virtual void DrawForeground();

	//@cmember
	/* Displays a warning sign for null graphs*/
	virtual void DrawEmptyGraph();

	//@cmember
	/* Returns the X tick list*/
	virtual CPtrList * GetXTickList(){return &m_XTickList;}
	//@cmember
	/* Returns the Y tick list*/
	virtual CPtrList * GetYTickList(){return &m_YTickList;}
	//@cmember
	/* Returns the Z tick list*/
	virtual CPtrList * GetZTickList(){return &m_ZTickList;}

	//@cmember
	/* Empties a tick list and deletes its contents*/
	virtual void KillTickList(CPtrList * pTickList);
	
	//@cmember
	/* Returns 1.1 -- override to return your own custom Y scaling adjustment*/
	virtual double GetYScaleAdjustment();
	//@cmember
	/* Returns 1.1 -- override to return your own custom X scaling adjustment*/
	virtual double GetXScaleAdjustment();

	//@cmember
	/* Generates a list of numbers which are used to annotate the Y axis of graphs (no longer used, maintained for compatibility)*/
	virtual void CreateNumberList(double multiplier,CStringList *list);

	//@cmember
	/* Returns the step required to generate numbers for a graph (superceded by SRGDecimalScale class)*/
	virtual double GetIdealScale();
	//@cmember
	/* Allows custom adjustment of safety scaling*/
	virtual void AdjustScale();

	//@cmember
	/* Adjusts data range so that labels display "nice" numbers*/
	void FindLimits(CScale* pScale, double dScaleAdjust);
	//@cmember
	/* Expands data range to give "nice" limits for log axis*/
	void FindLogLimits(CScale* pScale, BOOL bFullDecade=TRUE);
	//@cmember
	/* Adjusts the data range to find sensible limits for date scales */
	void FindDateLimits(CScale* pScale, double dScaleAdjust);


// Custom charts
	//@cmember
	/* (Empty) Virtual function to allow extension of the preparation process*/
	virtual void PrepareCustom();
	//@cmember
	/* (Empty) Override to draw custom axes*/
	virtual void DrawCustomAxis();
	//@cmember
	/* (Empty) Override to draw custom labels*/
	virtual void DrawCustomLabels();
	//@cmember
	/* (Empty) Override to draw custom data*/
	virtual void DrawCustomData();

	//@cmember,mfunc
	/* (Pure Virtual) Prepares the display component for drawing*/
	virtual void PrepareDisplay() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Calculates scale ranges for most simple graph types*/
	virtual void PrepareYScale() = 0;

// Classic axes
	//@cmember,mfunc
	/* (Pure Virtual) Called to draw standard X,Y labels*/
	virtual void DrawClassicLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Called to draw standard X,Y axes*/
	virtual void DrawClassicAxis() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws the pseudo 3D axis*/
	virtual void DrawIsoClassicAxis() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Called to draw labels for the YX graphs*/
	virtual void DrawYXLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws the YX axis for use with horizontal bar charts*/
	virtual void DrawYXAxis() = 0;

// Stage axes
	//@cmember,mfunc
	/* (Pure Virtual) Calculates the size of a stage or platform axis*/
	virtual int StageCalcSize(CRect *BackPlane) = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws labels and annotations on the stage or platform graphs*/
	virtual void DrawStageLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws the "stage" type axis*/
	virtual void DrawStageAxis() = 0;

//Pie charts
	//@cmember,mfunc
	/* (Pure Virtual) Draws pie chart labels*/
	virtual void DrawPieLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws pie chart data*/
	virtual void DrawPieData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws the 3D pie chart*/
	virtual void DrawIsoPieData() = 0;

// Bar charts
	//@cmember,mfunc
	/* (Pure Virtual) Draws vertical bar chart data*/
	virtual void DrawVBarData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws horizontal bar data*/
	virtual void DrawHBarData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws vertical stacked bars*/
	virtual void DrawStackVBarData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws horizontal stacked bars*/
	virtual void DrawStackHBarData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Prepares displays for the drawing of Manhattan type graphs*/
	virtual void PrepareIsoBar() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws "Manhattan" bars*/
	virtual void DrawIsoBarData() = 0;


// Polar charts
	//@cmember,mfunc
	/* (Pure Virtual) Prepares the display for drawing polar data*/
	virtual void PreparePolar() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws polar chart labels*/
	virtual void DrawPolarLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws polar chart axes*/
	virtual void DrawPolarAxis() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws polar chart data*/
	virtual void DrawPolarData() = 0;

// Strata charts
	//@cmember,mfunc
	/* (Pure Virtual) Pre-display preparation for strata graphs*/
	virtual void PrepareStrata() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws strata graphs*/
	virtual void DrawStrataData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw a strata hbar label with the group header as the label text of each bar*/
	virtual void DrawStrataHBarGLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw a strata vbar label with the group header as the label text of each bar*/
	virtual void DrawStrataVBarGLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw a strata hbar with each group on one bar*/
	virtual void DrawStrataHBarGData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw a strata vbar with each group on one bar*/
	virtual void DrawStrataVBarGData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Do some pre-initialization for the strata bar( one group/ per bar )*/
	virtual void PrepareStrataBarG() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Do some pre-initialization for the strata bar( one index/per bar )*/
	virtual void PrepareStrataBar() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw strata hbar(data with the same index of different group on the same bar)*/
	virtual void DrawStrataHBarData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draw strata vbar(data with the same index of different group on the same bar)*/
	virtual void DrawStrataVBarData() = 0;

// Gantt chart
	//@cmember,mfunc
	/* (Pure Virtual) Draws Gantt labels*/
	virtual void DrawGanttLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws Gantt data*/
	virtual void DrawGanttData() = 0;

// Web chart
	//@cmember,mfunc
	/* (Pure Virtual) Draws Web char data*/
	virtual void DrawWebData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws Web chart labels*/
	virtual void DrawWebLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws Web chart axes*/
	virtual void DrawWebAxis() = 0;

// Scatter charts
	//@cmember,mfunc
	/* (Pure Virtual) Calculates X,Y, and marker size scale information for bubble graphs*/
	virtual void PrepareBubble() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws bubble chart data*/
	virtual void DrawBubbleData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) prepares scales for the display of vector charts */
	virtual void PrepareVector() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws vector data */
	virtual void DrawVectorData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Calculates X and Y scale information for scatter graphs*/
	virtual void PrepareScatter() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws X,Y scatter data*/
	virtual void DrawScatterData() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws X,Y scatter labels*/
	virtual void DrawScatterLabels() = 0;
	//@cmember,mfunc
	/* (Pure Virtual) Draws X,Y scatter axes */
	virtual void DrawScatterAxis() = 0;

// Various charts
	//@cmember,mfunc
	/* (Pure Virtual) Called to draw a line plot of the data*/
	virtual void DrawLineData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Draws the data for the step charts*/
	virtual void DrawStepData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Draws candle chart labels*/
	virtual void DrawCandleData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Draws area charts*/
	virtual void DrawAreaData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Draws the data components of FreeStyle graphs*/
	virtual void DrawFreeStyleData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Called to draw stock quote hi-lo-close graphs*/
	virtual void DrawStockData() = 0;

	//@cmember,mfunc
	/* (Pure Virtual) Draws "Rooftop" objects*/
	virtual void DrawIsoAreaData() = 0;

};



#endif // !defined(_SRGDISPLAYBASE_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

