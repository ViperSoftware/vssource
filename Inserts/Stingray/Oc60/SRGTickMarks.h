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
//$head Component classes (Specialized sub components)
//level 2

/////////////////////////////////////////////////////////////
//@doc SRGTickMarks
//@module SRGTickMarks.h | SRGTickMarks header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SRGTickMarks.h: interface for the SRGTickMarks class.
//
/////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#if !defined(_SRGTICKMARKS_H_INCLUDED_)
#define _SRGTICKMARKS_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SRGComp.h"


/////////////////////////////
// AutoDuck tag block for SRGTickMarks 


//@doc SRGTickMarks
//@mfunc void  | SRGTickMarks | SetMinorTickColor | Sets the color of the minor ticks
//@parm COLORREF  | c | RGB color value

//@mfunc COLORREF  | SRGTickMarks | GetMinorTickColor | Returns the minor tick color

//@mfunc void  | SRGTickMarks | SetMajorTickColor | Sets the color of the major ticks
//@parm COLORREF  | c | RGB color

//@mfunc COLORREF  | SRGTickMarks | GetMajorTickColor | Returns the major tick color

//@mfunc void  | SRGTickMarks | SetMajorTickWidth | Sets the width of the major ticks in pixels
//@parm int  | n | Positive integer specifying the width

//@mfunc void  | SRGTickMarks | SetMinorTickWidth | Sets the width of the minor ticks in pixels.
//@parm int  | n | Positive integer specifying the width

//@mfunc int  | SRGTickMarks | GetMinorTickWidth | Returns the minor tick width

//@mfunc int  | SRGTickMarks | GetMajorTickWidth |  Returns the major tick width

//@mfunc void  | SRGTickMarks | SetptrTickPositionList | Initializes the pointer to the tick position list
//@parm CPtrList  * | pList | Pointer to a CPtrList object that contains addresses of a list of CPoint objects that control the tick list

//@mfunc CPtrList * | SRGTickMarks | GetptrTickPositionList | Returns the tick position list pointer

//@mfunc void  | SRGTickMarks | SetTickSide | Sets the side of the line upon which ticks are displayed
//@parm BOOL  | bSide | TRUE = right

//@mfunc BOOL  | SRGTickMarks | GetTickSide | Returns the side of the line upon which ticks are displayed

//@mfunc void  | SRGTickMarks | SetMajorTickSize | Sets the size of the major tick marks
//@parm int  | nTickSize | Positive integer specifying the length of the tick marks

//@mfunc int  | SRGTickMarks | GetMajorTickSize | Returns the size of the major tick marks

//@mfunc void  | SRGTickMarks | SetMinorTickSize | Sets the size of the minor ticks
//@parm double  | d | Ratio of major tick to minor tick sizes (ie. 0.5 makes minor ticks half as long as the major ticks)

//@mfunc double  | SRGTickMarks | GetMinorTickSize | Returns the minor tick size

//@mdata int  | SRGTickMarks | m_nMinorTickWidth | Width in pixels of the minor tick marks

//@mdata int  | SRGTickMarks | m_nMajorTickWidth | Width in pixels of the major tick marks

//@mdata COLORREF  | SRGTickMarks | m_MinorTickColor | RGB color of the minor ticks

//@mdata COLORREF  | SRGTickMarks | m_MajorTickColor | RGB color of the major ticks

//@mdata BOOL  | SRGTickMarks | m_bTickSide | Side of the line upon which ticks are displayed

//@mdata int  | SRGTickMarks | m_nTickSize | Size of the major ticks

//@mdata double  | SRGTickMarks | m_dMinorTickSize | Ratio of minor tick length to major tick length

//@mdata CPtrList *  | SRGTickMarks | m_pTickPositionList | Pointer to the tick position list

//@mdata int  | SRGTickMarks | m_nMinorTickRatio | Number of minor ticks to each major tick

// adinsert AutoDuck insertion point for SRGTickMarks 
//$head Component classes (Specialized sub components)
//$level 2
//@doc SRGTickMarks 
//@class This class manages the major and minor tick marks that may optionally be displayed on the axis of a chart. 
//The positions of the major ticks are defined by a list of CPoint coordinates. 
//Normally this list of CPoint objects is generated by an SRGraphLabelBlock-based class and 
//then passed by pointer to the SRGTickMarks object.<nl>
//Minor tick marks are interspersed between major tick marks at a preset ratio (N:1).<nl>
//Major and minor color, length, and thickness styles are individually adjustable. 
//@base public | SRGraphComponent
class SRGTickMarks : public SRGraphComponent  
{
public:
	//@cmember
	/* Modifies a start and end position so that the label block won't overwrite the tick marks*/
	virtual void GetStandoff(CPoint *ptStart, CPoint *ptEnd);
	//@cmember
	/* Offsets a single CPoint by the angle and size of the major tick*/
	virtual CPoint OffsetPoint(CPoint ptPos, int nSize,double dAngle);
	//@cmember
	/* Draws this component*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);
	//@cmember
	/* Serializes this component*/
	virtual void Serialize(CArchive &ar);
	//@cmember
	/* Draws a single tick mark with a given style and position*/
	virtual void DrawTick(CPoint ptPos, int nSize, double dAngle,int nStrength=1,COLORREF Color=CXCLR_BLACK);
	//@cmember
	/* Initializes the ratio of minor ticks to major ticks*/
	virtual void SetMinorTickRatio(int n);
	//@cmember
	/* Returns the ratio of minor ticks to major ticks*/
	virtual int GetMinorTickRatio();
	//@cmember
	/* Constructor*/
	SRGTickMarks();

	DECLARE_SERIAL(SRGTickMarks);
	//@cmember
	/* Destructor*/
	virtual ~SRGTickMarks();
	//@cmember
	/* Sets the color of the minor ticks*/
	virtual void SetMinorTickColor(COLORREF c){m_MinorTickColor=c;}
	//@cmember
	/* Gets the color of the minor ticks*/
	virtual COLORREF GetMinorTickColor(){return m_MinorTickColor;}
	//@cmember
	/* Sets the color of the major ticks*/
	virtual void SetMajorTickColor(COLORREF c){m_MajorTickColor=c;}
	//@cmember
	/* Gets the color of the major ticks*/
	virtual COLORREF GetMajorTickColor(){return m_MajorTickColor;}
	//@cmember
	/* Sets the width in pixels of the major ticks*/
	virtual void SetMajorTickWidth(int n){m_nMajorTickWidth=n;}
	//@cmember
	/* Sets the width in pixels of the minor ticks*/
	virtual void SetMinorTickWidth(int n){m_nMinorTickWidth=n;}
	//@cmember
	/* Gets the width in pixels of the major ticks*/
	virtual int GetMinorTickWidth(){return m_nMinorTickWidth;}
	//@cmember
	/* Gets the width in pixels of the major tick*/
	virtual int GetMajorTickWidth(){return m_nMajorTickWidth;}
	//@cmember
	/* Sets the tick position pointer*/
	virtual void SetptrTickPositionList(CPtrList *pList){m_pTickPositionList=pList;}
	//@cmember
	/* Returns the tick position list address*/
	virtual CPtrList *GetptrTickPositionList(){return m_pTickPositionList;}
	//@cmember
	/* Sets the side upon which ticks are displayed*/
	virtual void SetTickSide(BOOL bSide){m_bTickSide=bSide;}
	//@cmember
	/* Returns the side upon which ticks are displayed*/
	virtual BOOL GetTickSide(){return m_bTickSide;}
	//@cmember
	/* Sets the size (length) of the major ticks*/
	virtual void SetMajorTickSize(int nTickSize){m_nTickSize=nTickSize;}
	//@cmember
	/* Returns the size (length) of the major ticks*/
	virtual int GetMajorTickSize(){return m_nTickSize;}
	//@cmember
	/* Sets the size of the minor tick as a ratio of the length of the major tick*/
	virtual void SetMinorTickSize(double d){m_dMinorTickSize=d;}
	//@cmember
	/* Returns the size of the minor tick expressed as a ratio to the length of the major tick*/
	virtual double GetMinorTickSize(){return m_dMinorTickSize;}



protected:
	//@cmember
	/* Overridden to do nothing*/
	virtual void DrawShadow();
	//@cmember
	/* Overridden to do nothing*/
	virtual void DrawBorder();
	//@cmember
	/* Overridden to do nothing*/
	virtual void DrawFill();
	//@cmember
	/* Width in pixels of the minor ticks*/
	int m_nMinorTickWidth;
	//@cmember
	/* Width in pixels of the major ticks*/
	int m_nMajorTickWidth;
	//@cmember
	/* RGB color of the minor ticks*/
	COLORREF m_MinorTickColor;
	//@cmember
	/* RGB color of the major ticks*/
	COLORREF m_MajorTickColor;
	//@cmember
	/* Side (left=0 right=1) upon which the ticks are drawn*/
	BOOL m_bTickSide;
	//@cmember
	/* Size (length) of the major ticks*/
	int m_nTickSize;
	//@cmember
	/* Ratio of the size of the minor ticks to the major ticks*/
	double m_dMinorTickSize;
	//@cmember
	/* Pointer to the CPtrList object that controls the tick list*/
	CPtrList * m_pTickPositionList;
	//@cmember
	/* Draws the ticks*/
	virtual void DrawForeground();
	//@cmember
	/* Number of minor ticks for each major tick (0 or positive integers only)*/
	int m_nMinorTickRatio;

};




#endif // !defined(_SRGTICKMARKS_H_INCLUDED_)
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

