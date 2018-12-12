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
//@doc SRGraphComponent
//@module SRGComp.h|  definition of the graph component classes<nl>
//SRGraphComponent, SRGraphRect, SRGraphTitle, SRGraphBackground, SRGraphDisplay, SRGraphLabel, SRGraphLabelBlock, SRGraphLegend<nl>
//and structures GESorter and PointSorter<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGComp.h: definition of the graph component classes
//
/////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHBACKGROUND__
#define __SRGRAPHBACKGROUND__

////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphBackground
//
//@doc SRGraphBackground

//@doc SRGraphBackground
//@mfunc virtual void  | SRGraphBackground | DrawForeground | Does nothing -- background does not have a foreground

//adinsert SRGraphBackground
//$head Component classes
//$level 1



//@doc SRGraphBackground
//@class Based on SRGraphComponent, this class handles painting of the background.
//@base public | SRGraphComponent
class SRGraphBackground : public SRGraphComponent
{
//@access public member functions
public:
	//@cmember
	/* Constructor*/
	SRGraphBackground();
	
#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	
	//@cmember
	/* Reads a line from the template file*/
	virtual int ReadTemplateLine(LPCTSTR line);
	//@cmember
	/* Writes the name to the template file.*/
	virtual void WriteName(CStdioFile* file);

#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE

	DECLARE_SERIAL(SRGraphBackground);

//@access protected member functions
protected:
	//@cmember
	/* Overridden from base class -- does nothing because backgrounds don't have foregrounds*/
	virtual void DrawForeground(){}
};




#endif //__SRGRAPHBACKGROUND__


// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

