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
//@doc SRGHBarGraph
//@module SRGHBarGraph.h|  definition of the HBar and EX_HBar graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGHBarGraph.h: definition of the HBar and EX_HBar graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGHBarGraph__
#define __SRGHBarGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGHBarGraph
//
//@doc SRGHBarGraph


// adinsert SRGHBarGraph

////////////////////////////////////////////////////////

//@doc SRGHBarGraph
//@class Performs data drawing for Horizontal Bar and EX_HBar graph types<nl>
//Inherits axis drawing abilities from SRGHBarAxisBase, 
//basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGHBarAxisBase
//@devnote All PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines are defined in SRGHBarAxisBase. 
//This class defines all DrawXXXData functions -- only the DrawHBarData function does anything useful.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class
class SRGHBarGraph : public SRGHBarAxisBase
{
	DECLARE_SERIAL(SRGHBarGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGHBarGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGHBarGraph();

//@access Protected member functions
protected:
	//@cmember Draws horizontal bar data
	virtual void DrawHBarData();

/////////////////////////////////////////////////////////////
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
	virtual void DrawVBarData();
	virtual void DrawStrataHBarGData();
	virtual void DrawStrataVBarGData();
	virtual void DrawStrataHBarData();
	virtual void DrawStrataVBarData();
	virtual void DrawBubbleData();
	virtual void DrawVectorData();

};

#endif //__SRGHBarGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
