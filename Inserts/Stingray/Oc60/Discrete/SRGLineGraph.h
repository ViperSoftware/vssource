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
//@doc SRGLineGraph
//@module SRGLineGraph.h|  definition of the Line and Line Only graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGLineGraph.h: definition of the Line and Line Only graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGLineGraph__
#define __SRGLineGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGLineGraph
//
//@doc SRGLineGraph


// adinsert SRGLineGraph

////////////////////////////////////////////////////////

//@doc SRGLineGraph
//@class Performs data drawing for Line and Line Only graph types<nl>
//Inherits axis drawing abilities from SRGClassicAxisBase, 
//basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGClassicAxisBase
//@devnote All PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines are defined in SRGClassicAxisBase. 
//This class defines all DrawXXXData functions -- only the DrawLineData function does anything useful.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class.
class SRGLineGraph : public SRGClassicAxisBase
{
	DECLARE_SERIAL(SRGLineGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGLineGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGLineGraph();

//@access Protected member functions
protected:

	//@cmember Called to draw a line plot of the data
	virtual void DrawLineData();

/////////////////////////////////////////////////////////////////
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
	virtual void DrawHBarData();
	virtual void DrawStackVBarData();
	virtual void DrawStackHBarData();
	virtual void DrawIsoAreaData();
	virtual void DrawIsoBarData();
	virtual void DrawPieData();
	virtual void DrawVBarData();
	virtual void DrawStrataHBarGData();
	virtual void DrawStrataVBarGData();
	virtual void DrawStrataHBarData();
	virtual void DrawStrataVBarData();
	virtual void DrawBubbleData();
	virtual void DrawVectorData();

};

#endif //__SRGLineGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
