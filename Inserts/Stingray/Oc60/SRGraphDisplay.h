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
//@doc SRGraphDisplay
//@module SRGraphDisplay.h|  definition of the graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGraphDisplay.h: definition of the graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHDISPLAY__
#define __SRGRAPHDISPLAY__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphDisplay
//
//@doc SRGraphDisplay






// adinsert SRGraphDisplay
//$head Component classes
//$level 1
////////////////////////////////////////////////////////

//@doc SRGraphDisplay
//@class The graph display component -- inherits font abilities from SRGraphTitle
//@base public | SRGDisplayBase
//@devnote Note that v 1.2 has modified the ancestry of this class so that the <c SRGDisplayBase> abstract class
// contains all data members and defines the member functions.
class SRGraphDisplay : public SRGDisplayBase
{
	DECLARE_SERIAL(SRGraphDisplay);

	
//@access public member functions
public:
	//@cmember
	/* Constructor*/
	SRGraphDisplay();

	//@cmember
	/* Virtual destructor for this class*/
	virtual ~SRGraphDisplay();

//@access Protected member functions
protected:
	//@cmember
	/* This function actually draw the vector chart*/
	virtual void DrawVectorData();
	//@cmember
	/* This function prepare the axis scale for vector chart before the drawing*/
	virtual void PrepareVector();
	//@cmember
	/* Draw the bubble chart*/
	virtual void DrawBubbleData();
	//@cmember
	/* Prepare the axis scale for bubble chart before the drawing*/
	virtual void PrepareBubble();
	//@cmember
	/* Draws the data for the step charts*/
	virtual void DrawStepData();

	//@cmember
	/* Draws Gantt labels*/
	virtual void DrawGanttLabels();
	//@cmember
	/* Draws Gantt data*/
	virtual void DrawGanttData();

	//@cmember
	/* Draws polar chart labels*/
	virtual void DrawPolarLabels();
	//@cmember
	/* Draws polar chart axes*/
	virtual void DrawPolarAxis();
	//@cmember
	/* Prepares the display for drawing polar data*/
	virtual void PreparePolar();
	//@cmember
	/* Draws polar chart data*/
	virtual void DrawPolarData();
	//@cmember
	/* Draws area chart data*/

	//@cmember
	/* Draws candle chart labels*/
	virtual void DrawCandleData();

	//@cmember
	/* Draws area charts*/
	virtual void DrawAreaData();

	//@cmember
	/* Draws the pseudo 3D axis*/
	virtual void DrawIsoClassicAxis();

	//@cmember
	/* Draws the data components of FreeStyle graphs*/
	virtual void DrawFreeStyleData();

	//@cmember
	/* Prepares displays for the drawing of Manhattan type graphs*/
	virtual void PrepareIsoBar();

	//@cmember
	/* Prepares the display component for drawing*/
	virtual void PrepareDisplay();

	//@cmember
	/* Calculates scale ranges for most simple graph types*/
	virtual void PrepareYScale();

	//@cmember
	/* Calculates X and Y scale information for scatter graphs*/
	virtual void PrepareScatter();

	//@cmember
	/* Draws Web char data*/
	virtual void DrawWebData();
	//@cmember
	/* Draws Web chart labels*/
	virtual void DrawWebLabels();
	//@cmember
	/* Draws Web chart axes*/
	virtual void DrawWebAxis();

	//@cmember
	/* Draws X,Y scatter data*/
	virtual void DrawScatterData();
	//@cmember
	/* Draws X,Y scatter labels*/
	virtual void DrawScatterLabels();
	//@cmember
	/* Draws X,Y scatter axes */
	virtual void DrawScatterAxis();

	//@cmember
	/* Called to draw stock quote hi-lo-close graphs*/
	virtual void DrawStockData();

	//@cmember
	/* Called to draw labels for the YX graphs*/
	virtual void DrawYXLabels();

	//@cmember
	/* Draws strata graphs*/
	virtual void DrawStrataData();

	//@cmember
	/* Draws the 3D pie chart*/
	virtual void DrawIsoPieData();

	//@cmember
	/* Draws the YX axis for use with horizontal bar charts*/
	virtual void DrawYXAxis();

	//@cmember
	/* Draws horizontal bar data*/
	virtual void DrawHBarData();

	//@cmember
	/* Draws vertical stacked bars*/
	virtual void DrawStackVBarData();

	//@cmember
	/* Draws horizontal stacked bars*/
	virtual void DrawStackHBarData();

	//@cmember
	/* Calculates the size of a stage or platform axis*/
	virtual int StageCalcSize(CRect *BackPlane);
	//@cmember
	/* Draws labels and annotations on the stage or platform graphs*/
	virtual void DrawStageLabels();

	//@cmember
	/* Draws "Rooftop" objects*/
	virtual void DrawIsoAreaData();

	//@cmember
	/* Draws "Manhattan" bars*/
	virtual void DrawIsoBarData();

	//@cmember
	/* Draws the "stage" type axis*/
	virtual void DrawStageAxis();

	//@cmember
	/* Draws pie chart labels*/
	virtual void DrawPieLabels();
	//@cmember
	/* Draws pie chart data*/
	virtual void DrawPieData();

	//@cmember
	/* Called to draw standard X,Y labels*/
	virtual void DrawClassicLabels();
	//@cmember
	/* Called to draw standard X,Y axes*/
	virtual void DrawClassicAxis();

	//@cmember
	/* Called to draw a line plot of the data*/
	virtual void DrawLineData();

	//@cmember
	/* Draws vertical bar chart data*/
	virtual void DrawVBarData();

	//@cmember
	/* Pre-display preparation for strata graphs*/
	virtual void PrepareStrata();
	//@cmember
	/* Draw a strata hbar label with the group header as the label text of each bar*/
	virtual void DrawStrataHBarGLabels();
	//@cmember
	/* Draw a strata vbar label with the group header as the label text of each bar*/
	virtual void DrawStrataVBarGLabels();
	//@cmember
	/* Draw a strata hbar with each group on one bar*/
	virtual void DrawStrataHBarGData();
	//@cmember
	/* Draw a strata vbar with each group on one bar*/
	virtual void DrawStrataVBarGData();
	//@cmember
	/* Do some pre-initialization for the strata bar( one group/ per bar )*/
	virtual void PrepareStrataBarG();
	//@cmember
	/* Do some pre-initialization for the strata bar( one index/per bar )*/
	virtual void PrepareStrataBar();
	//@cmember
	/* Draw strata hbar(data with the same index of different group on the same bar)*/
	virtual void DrawStrataHBarData();
	//@cmember
	/* Draw strata vbar(data with the same index of different group on the same bar)*/
	virtual void DrawStrataVBarData();

};


#endif //__SRGRAPHDISPLAY__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

