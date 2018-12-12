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
//@doc SRGWebGraph
//@module SRGWebGraph.h|  definition of the Web Graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGWebGraph.h: definition of the Web Graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGWebGraph__
#define __SRGWebGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGWebGraph
//
//@doc SRGWebGraph


// adinsert SRGWebGraph

////////////////////////////////////////////////////////

//@doc SRGWebGraph
//@class The graph display component specialized for Web and AreaWeb charts
//Inherits basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGDisplayBase
//@devnote This class defines all of SRGDisplayBase's PrepareXXX, DrawXXXAxis, DrawXXXLabels, 
//and DrawXXXData functions, but only the Web chart functions do anything useful.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class.
class SRGWebGraph : public SRGDisplayBase
{
	DECLARE_SERIAL(SRGWebGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGWebGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGWebGraph();

//@access Protected member functions
protected:
	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Calculates scale ranges for most simple graph types
	virtual void PrepareYScale();

	//@cmember Draws Web chart labels
	virtual void DrawWebLabels();

	//@cmember Draws Web chart axes
	virtual void DrawWebAxis();

	//@cmember Draws Web char data
	virtual void DrawWebData();

///////////////////////////////////////////////////////////////////////
	virtual void DrawStepData();
	virtual void DrawGanttLabels();
	virtual void DrawGanttData();
	virtual void DrawPolarLabels();
	virtual void DrawPolarAxis();
	virtual void PreparePolar();
	virtual void DrawPolarData();
	virtual void DrawCandleData();
	virtual void DrawAreaData();
	virtual void DrawIsoClassicAxis();
	virtual void DrawFreeStyleData();
	virtual void PrepareIsoBar();
	virtual void PrepareScatter();
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

#endif //__SRGWebGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
