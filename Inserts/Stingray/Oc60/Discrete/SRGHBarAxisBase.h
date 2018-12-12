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
//@doc SRGHBarAxisBase
//@module SRGHBarAxisBase.h|  definition of the Horizontal Bar Axis Base display class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGHBarAxisBase.h: definition of the Horizontal Bar Axis Base display class
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGHBarAxisBase__
#define __SRGHBarAxisBase__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGHBarAxisBase
//
//@doc SRGHBarAxisBase


// adinsert SRGHBarAxisBase

////////////////////////////////////////////////////////

//@doc SRGHBarAxisBase
//@class An abstract base class for display classes that support Horizontal Bar axis types<nl>
//Inherits basic graph component capabilites from SRGDisplayBase and font abilities from SRGraphTitle
//@base public | SRGDisplayBase
//@devnote A family of graph-type specific component classes are derived from this class.<nl>
//This class defines all of SRGDisplayBase's pure virtual PrepareXXX, DrawXXXAxis, and DrawXXXLabels routines. 
//The DrawXXXData functions must be defined in the derived classes.
//@see <c SRGraphDisplay> and <c SRGDisplayBase> for description of functions unused by this class
class SRGHBarAxisBase : public SRGDisplayBase
{

	DECLARE_DYNAMIC(SRGHBarAxisBase);
	
//@access Public member functions
public:

	//@cmember Constructor
	SRGHBarAxisBase();

	//@cmember Virtual destructor for this class
	virtual ~SRGHBarAxisBase();

//@access Protected member functions
protected:
	//@cmember Prepares the display component for drawing
	virtual void PrepareDisplay();

	//@cmember Calculates scale ranges for most simple graph types
	virtual void PrepareYScale();

	//@cmember Prepares displays for the drawing of Manhattan type graphs
	virtual void PrepareIsoBar();

	//@cmember Called to draw standard X,Y axes
	virtual void DrawClassicAxis();

	//@cmember Called to draw labels for the YX graphs
	virtual void DrawYXLabels();

	//@cmember Draws the YX axis for use with horizontal bar charts
	virtual void DrawYXAxis();

	//@cmember Draws the pseudo 3D axis
	virtual void DrawIsoClassicAxis();

	////////////////////////////////////////////////////////////////
	virtual void DrawStepData() = 0;
	virtual void DrawGanttLabels();
	virtual void DrawGanttData() = 0;
	virtual void DrawPolarLabels();
	virtual void DrawPolarAxis();
	virtual void PreparePolar();
	virtual void DrawPolarData() = 0;
	virtual void DrawCandleData() = 0;
	virtual void DrawAreaData() = 0;
	virtual void DrawFreeStyleData() = 0;
	virtual void PrepareScatter();
	virtual void DrawWebData() = 0;
	virtual void DrawWebLabels();
	virtual void DrawWebAxis();
	virtual void DrawScatterData() = 0;
	virtual void DrawScatterLabels();
	virtual void DrawScatterAxis();
	virtual void DrawStockData() = 0;
	virtual void DrawStrataData() = 0;
	virtual void DrawIsoPieData() = 0;
	virtual void DrawHBarData() = 0;
	virtual void DrawStackVBarData() = 0;
	virtual void DrawStackHBarData() = 0;
	virtual int  StageCalcSize(CRect *BackPlane);
	virtual void DrawStageLabels();
	virtual void DrawIsoAreaData() = 0;
	virtual void DrawIsoBarData() = 0;
	virtual void DrawStageAxis();
	virtual void DrawPieLabels();
	virtual void DrawPieData() = 0;
	virtual void DrawClassicLabels();
	virtual void DrawLineData() = 0;
	virtual void DrawVBarData() = 0;
	virtual void PrepareStrata();
	virtual void DrawStrataHBarGLabels();
	virtual void DrawStrataVBarGLabels();
	virtual void DrawStrataHBarGData() = 0;
	virtual void DrawStrataVBarGData() = 0;
	virtual void PrepareStrataBarG();
	virtual void PrepareStrataBar();
	virtual void DrawStrataHBarData() = 0;
	virtual void DrawStrataVBarData() = 0;
	virtual void PrepareBubble();
	virtual void DrawBubbleData() = 0;
	virtual void PrepareVector();
	virtual void DrawVectorData() = 0;

};

#endif //__SRGHBarAxisBase__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
