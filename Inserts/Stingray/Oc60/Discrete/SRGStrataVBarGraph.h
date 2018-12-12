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
//@doc SRGStrataVBarGraph
//@module SRGStrataVBarGraph.h | definition of the Strata VBar graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGStrataVBarGraph.h: definition of the Strata VBar graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGStrataVBarGraph__
#define __SRGStrataVBarGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGStrataVBarGraph
//
//@doc SRGStrataVBarGraph


// adinsert SRGStrataVBarGraph

////////////////////////////////////////////////////////

//@doc SRGStrataVBarGraph
//@class Performs data drawing for Strata Vertical Bar and Strata Vertical Bar Group graph types<nl>
//Inherits axis drawing abilities from SRGVBarAxisBase, 
//basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGVBarAxisBase
//@devnote All PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines are defined in SRGVBarAxisBase. 
//This class defines all DrawXXXData functions -- only the DrawStrataVBarData, DrawStrataVBarGData, and DrawVBarData do anything useful.
//It also overrides PrepareDisplay, PrepareStrataBar, and PrepareStrataBarG functions.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class
class SRGStrataVBarGraph : public SRGVBarAxisBase
{
	DECLARE_SERIAL(SRGStrataVBarGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGStrataVBarGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGStrataVBarGraph();

//@access Protected member functions
protected:
	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Do some pre-initialization for the strata bar( one index/per bar )
	virtual void PrepareStrataBar();

	//@cmember Do some pre-initialization for the strata bar( one group/ per bar )
	virtual void PrepareStrataBarG();

	//@cmember Draw a strata vbar label with the group header as the label text of each bar
	virtual void DrawStrataVBarGLabels();

	//@cmember Draw strata vbar(data with the same index of different group on the same bar)
	virtual void DrawStrataVBarData();

	//@cmember Draw a strata vbar with each group on one bar
	virtual void DrawStrataVBarGData();

	//@cmember Draws vertical bar chart data - used if data contains neg values
	virtual void DrawVBarData();

/////////////////////////////////////////////////////////
	virtual void DrawStrataHBarGData();
	virtual void DrawStrataHBarData();
	virtual void DrawHBarData();
	virtual void DrawStepData();
	virtual void DrawGanttData();
	virtual void DrawPolarData();
	virtual void DrawCandleData();
	virtual void DrawAreaData();
	virtual void DrawFreeStyleData();
	virtual void DrawWebData();
	virtual void DrawScatterData();
	virtual void DrawStockData();
	virtual void DrawStrataData();
	virtual void DrawIsoPieData();
	virtual void DrawStackVBarData();
	virtual void DrawStackHBarData();
	virtual void DrawIsoAreaData();
	virtual void DrawIsoBarData();
	virtual void DrawPieData();
	virtual void DrawLineData();
	virtual void DrawBubbleData();
	virtual void DrawVectorData();

};

#endif //__SRGStrataVBarGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
