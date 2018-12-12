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
//@doc SRGStrataHBarGraph
//@module SRGStrataHBarGraph.h|  definition of the Strata HBar graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGStrataHBarGraph.h: definition of the Strata HBar graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGStrataHBarGraph__
#define __SRGStrataHBarGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGStrataHBarGraph
//
//@doc SRGStrataHBarGraph


// adinsert SRGStrataHBarGraph

////////////////////////////////////////////////////////

//@doc SRGStrataHBarGraph
//@class Performs data drawing for Strata Horizontal Bar and Strata Horizontal Bar Group graph types<nl>
//Inherits axis drawing abilities from SRGHBarAxisBase, 
//basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGHBarAxisBase
//@devnote All PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines are defined in SRGHBarAxisBase. 
//This class defines all DrawXXXData functions -- only the DrawStrataHBarData, DrawStrataHBarGData, and DrawHBarData do anything useful.
//It also overrides PrepareDisplay, PrepareStrataBar, and PrepareStrataBarG functions.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class
class SRGStrataHBarGraph : public SRGHBarAxisBase
{
	DECLARE_SERIAL(SRGStrataHBarGraph);

	
//@access Public member functions
public:
	//@cmember Constructor
	SRGStrataHBarGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGStrataHBarGraph();

//@access Protected member functions
protected:
	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Do some pre-initialization for the strata bar( one index/per bar )
	virtual void PrepareStrataBar();

	//@cmember Do some pre-initialization for the strata bar( one group/ per bar )
	virtual void PrepareStrataBarG();

	//@cmember Draw a strata hbar label with the group header as the label text of each bar
	virtual void DrawStrataHBarGLabels();

	//@cmember Draw a strata hbar with each group on one bar
	virtual void DrawStrataHBarGData();

	//@cmember Draw strata hbar(data with the same index of different group on the same bar)
	virtual void DrawStrataHBarData();

	//@cmember Draws horizontal bar data - used if data contains neg. values
	virtual void DrawHBarData();

/////////////////////////////////////////////////////
	virtual void DrawStrataData();
	virtual void DrawStrataVBarData();
	virtual void DrawStrataVBarGData();
	virtual void DrawVBarData();
	virtual void DrawStepData();
	virtual void DrawGanttData();
	virtual void DrawPolarData();
	virtual void DrawCandleData();
	virtual void DrawAreaData();
	virtual void DrawFreeStyleData();
	virtual void DrawWebData();
	virtual void DrawScatterData();
	virtual void DrawStockData();
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

#endif //__SRGStrataHBarGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
