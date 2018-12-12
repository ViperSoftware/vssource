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
//@doc SRGPolarGraph
//@module SRGPolarGraph.h|  definition of the Polar Graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGPolarGraph.h: definition of the Polar Graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGPolarGraph__
#define __SRGPolarGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGPolarGraph
//
//@doc SRGPolarGraph


// adinsert SRGPolarGraph

////////////////////////////////////////////////////////

//@doc SRGPolarGraph
//@class The graph display component specialized for Polar charts
//Inherits basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGDisplayBase
//@devnote This class defines all of SRGDisplayBase's PrepareXXX, DrawXXXAxis, DrawXXXLabels, 
//and DrawXXXData functions, but only the Polar chart functions do anything useful.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class.
class SRGPolarGraph : public SRGDisplayBase
{
	DECLARE_SERIAL(SRGPolarGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGPolarGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGPolarGraph();

//@access Protected member functions
protected:
	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Prepares the display for drawing polar data
	virtual void PreparePolar();

	//@cmember Draws polar chart labels
	virtual void DrawPolarLabels();

	//@cmember Draws polar chart axes
	virtual void DrawPolarAxis();

	//@cmember Draws polar chart data
	virtual void DrawPolarData();

	/////////////////////////////////////////////////////////////////////
	virtual void PrepareYScale();
	virtual void DrawStepData();
	virtual void DrawGanttLabels();
	virtual void DrawGanttData();
	virtual void DrawCandleData();
	virtual void DrawAreaData();
	virtual void DrawIsoClassicAxis();
	virtual void DrawFreeStyleData();
	virtual void PrepareIsoBar();
	virtual void PrepareScatter();
	virtual void DrawWebData();
	virtual void DrawWebLabels();
	virtual void DrawWebAxis();
	virtual void DrawScatterData();
	virtual void DrawScatterLabels();
	virtual void DrawScatterAxis();
	virtual void DrawStockData();
	virtual void DrawYXLabels();
	virtual void DrawStrataData();
	virtual void DrawIsoPieData();
	virtual void DrawYXAxis();
	virtual void DrawHBarData();
	virtual void DrawStackVBarData();
	virtual void DrawStackHBarData();
	virtual int  StageCalcSize(CRect *BackPlane);
	virtual void DrawStageLabels();
	virtual void DrawIsoAreaData();
	virtual void DrawIsoBarData();
	virtual void DrawStageAxis();
	virtual void DrawPieLabels();
	virtual void DrawPieData();
	virtual void DrawClassicLabels();
	virtual void DrawClassicAxis();
	virtual void DrawLineData();
	virtual void DrawVBarData();
	virtual void PrepareStrata();
	virtual void DrawStrataHBarGLabels();
	virtual void DrawStrataVBarGLabels();
	virtual void DrawStrataHBarGData();
	virtual void DrawStrataVBarGData();
	virtual void PrepareStrataBarG();
	virtual void PrepareStrataBar();
	virtual void DrawStrataHBarData();
	virtual void DrawStrataVBarData();
	virtual void PrepareBubble();
	virtual void DrawBubbleData();
	virtual void PrepareVector();
	virtual void DrawVectorData();

};

#endif //__SRGPolarGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
