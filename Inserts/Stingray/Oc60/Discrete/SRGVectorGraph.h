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
//@doc SRGVectorGraph
//@module SRGVectorGraph.h|  definition of the Vector Graph display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGVectorGraph.h: definition of the Vector Graph display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGVectorGraph__
#define __SRGVectorGraph__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGVectorGraph
//
//@doc SRGVectorGraph


// adinsert SRGVectorGraph

////////////////////////////////////////////////////////

//@doc SRGVectorGraph
//@class The graph display component specialized for Vector charts<nl> 
//Vector charts use the same axis system as XY scatter charts.<nl> 
//Inherits basic graph component functions from SRGDisplayBase, and 
//component and font capabilities from SRGraphTitle
//@base public | SRGDisplayBase
//@devnote This class defines all of SRGDisplayBase's PrepareXXX, DrawXXXAxis, DrawXXXLabels, 
//and DrawXXXData functions, but only the Vector chart functions do anything useful.<nl> 
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class.
class SRGVectorGraph : public SRGDisplayBase
{
	DECLARE_SERIAL(SRGVectorGraph);

	
//@access Public member functions
public:

	//@cmember Constructor
	SRGVectorGraph();

	//@cmember Virtual destructor for this class
	virtual ~SRGVectorGraph();

//@access Protected member functions
protected:

	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Calculates X and Y scale information for vector graphs
	virtual void PrepareVector();

	//@cmember Draws vector data
	virtual void DrawVectorData();

	//@cmember Draws X,Y scatter labels
	virtual void DrawScatterLabels();

	//@cmember Draws X,Y scatter axes 
	virtual void DrawScatterAxis();
	
	//@cmember Called to draw standard X,Y axes - called by DrawScatter Axis
	virtual void DrawClassicAxis();


	///////////////////////////////////////////////////////
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
	virtual void PrepareYScale();
	virtual void DrawWebData();
	virtual void DrawWebLabels();
	virtual void DrawWebAxis();
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
	virtual void PrepareScatter();
	virtual void DrawScatterData();

};

#endif //__SRGVectorGraph__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
