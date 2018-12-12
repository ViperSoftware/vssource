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
//@doc SRGIsoAreaGraph
//@module SRGIsoAreaGraph.h|  definition of the IsoArea and Ribbon graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGIsoAreaGraph.h: definition of the IsoBar and Ribbon graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGIsoAreaGraph__
#define __SRGIsoAreaGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGIsoAreaGraph
//
//@doc SRGIsoAreaGraph


// adinsert SRGIsoAreaGraph

////////////////////////////////////////////////////////

//@doc SRGIsoAreaGraph
//@class Performs data drawing for IsoArea and Ribbon graph types<nl>
//Inherits axis drawing abilities from SRGStageAxisBase, 
//basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGStageAxisBase
//@devnote All PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines are defined in SRGClassicAxisBase. 
//This class defines all DrawXXXData functions -- only the DrawIsoAreaData function does anything useful.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class
class SRGIsoAreaGraph : public SRGStageAxisBase
{
	DECLARE_SERIAL(SRGIsoAreaGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGIsoAreaGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGIsoAreaGraph();

//@access Protected member functions
protected:

	//@cmember Draws "Rooftop" objects
	virtual void DrawIsoAreaData();

	//@cmember Draws vertical bar chart data (used for plotting data with neg values)
	virtual void DrawVBarData();

	//////////////////////////////////////////////////////////////////////
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
	virtual void DrawIsoBarData();
	virtual void DrawPieData();
	virtual void DrawLineData();
	virtual void DrawStrataHBarGData();
	virtual void DrawStrataVBarGData();
	virtual void DrawStrataHBarData();
	virtual void DrawStrataVBarData();
	virtual void DrawBubbleData();
	virtual void DrawVectorData();

};

#endif //__SRGIsoAreaGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
