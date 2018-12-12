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
//@doc SRGGridLines
//@module SRGGridLines.h | SRGGridLines header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGGridLines.h: Interface for the SRGGridLines class
//
/////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#if !defined(_SRGGRIDLINES_H_INCLUDED_)
#define _SRGGRIDLINES_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block for SRGGridLines 
//@doc SRGGridLines

//@mfunc void  | SRGGridLines | SetMajorStyleCount | Sets the number of style items to be used in constructing the pen for the major grids
//@parm int  | v | Number of style items

//@mfunc void  | SRGGridLines | SetMinorStyleCount | Sets the number of style items to be used in constructing the pen for the minor grid lines
//@parm int  | v | Number of style items

//@mfunc int  | SRGGridLines | GetMajorStyleCount | Returns the number of style items used in the major grid line pen

//@mfunc int  | SRGGridLines | GetMinorStyleCount | Returns the number of style items used in the minor grid line pen

//@mfunc void  | SRGGridLines | SetMinorGridRatio | Sets the ratio of minor grid lines to major grid lines
//@parm int  | v | Positive integer or zero

//@mfunc int  | SRGGridLines | GetMinorGridRatio | Returns the number of minor grids lines for each major grid line

//@mfunc void  | SRGGridLines | SetMinorLogPen | Sets the LOGPEN used in the construction of the minor grids
//@parm LOGPEN *  | v | Pointer to the LOGPEN

//@mfunc void  | SRGGridLines | SetMajorLogPen | Sets the LOGPEN used in the construction of the major grids
//@parm LOGPEN *  | v | Pointer to the LOGPEN

//@mfunc void  | SRGGridLines | SetMajorStyleList | Sets a pointer to the style item list used to construct a pen for the major grid lines
//@parm DWORD *  | v | Pointer to a list of DWords that hold the style list for the pen
//@see the CPen construction system

//@mfunc void  | SRGGridLines | SetMinorStyleList | Sets a pointer to the style item list used to construct a pen for the minor grid lines
//@parm DWORD *  | v | Pointer to a list of DWords that hold the style list for the pen
//@see the CPen construction system

//@mfunc LOGPEN	* | SRGGridLines | GetMinorLogPen | Returns a pointer to the LOGPEN structure for the minor grid style

//@mfunc LOGPEN * | SRGGridLines | GetMajorLogPen | Returns a pointer to the LOGPEN structure for the major grid style

//@mfunc DWORD  *| SRGGridLines | GetMajorStyleList | Returns the major style list (see CPen for details)

//@mfunc DWORD  *| SRGGridLines | GetMinorStyleList | Returns the minor style list (see CPen for details)

//@mfunc void  | SRGGridLines | SetDisplayRect | Sets the display rectangle into which the grid lines will be drawn
//@parm CRect  | v | Display rectangle

//@mfunc CRect  | SRGGridLines | GetDisplayRect | Returns the display rectangle

//@mfunc void  | SRGGridLines | SetVertical | Set TRUE to signify that these grid lines are drawn vertically
//@parm BOOL  | v | TRUE=vertical, FALSE=horizontal

//@mfunc BOOL  | SRGGridLines | GetVertical | Returns the vertical flag -- TRUE=vertical, FALSE=horizontal

//@mfunc void  | SRGGridLines | SetptrTickPositionList | Sets the pointer to the common tick position list used to coordinate grid lines and tick marks with the labels that maintain the tick list
//@parm CPtrList  | *pList | Pointer to a CPtrList containing CPoint objects

//@mfunc void  | SRGGridLines | SetMajorGridColor | Sets the RGB color of the major grid lines
//@parm COLORREF  | r | RGB color value

//@mfunc void  | SRGGridLines | SetMinorGridColor | Sets the RGB color of the minor grid lines
//@parm COLORREF  | r | RGB color value

//@mfunc void  | SRGGridLines | SetMajorGridWidth | Sets the width (in pixels) of the major grid lines
//@parm int  | n | Positive integer greater than 0

//@mfunc void  | SRGGridLines | SetMinorGridWidth | Sets the width (in pixels) of the minor grid lines
//@parm int  | n | Positive integer greater than 0

//@mfunc void  | SRGGridLines | SetMajorGridStyle | Sets the grid style to one of the standard CPen styles 
//@parm int  | n | Desired style -- see CPen for details

//@mfunc void  | SRGGridLines | SetMinorGridStyle | Sets the grid style to one of the standard CPen styles
//@parm int  | n | Desired style -- see CPen for details

//@mfunc COLORREF  | SRGGridLines | GetMajorGridColor | Returns the major grid color

//@mfunc COLORREF  | SRGGridLines | GetMinorGridColor | Returns the minor grid color

//@mfunc int  | SRGGridLines | GetMajorGridWidth | Returns the major grid line width

//@mfunc int  | SRGGridLines | GetMinorGridWidth | Returns the minor grid line width

//@mfunc int  | SRGGridLines | GetMajorGridStyle | Returns the major grid style

//@mfunc int  | SRGGridLines | GetMinorGridStyle | Returns the minor grid style

//@mdata int  | SRGGridLines | m_nMinorGridRatio | Numerical ratio of minor grid lines to each major line

//@mdata int  | SRGGridLines | m_nMajorGridStyle | Pen style of the major grid lines

//@mdata int  | SRGGridLines | m_nMinorGridStyle | Pen style of the minor grid lines

//@mdata int  | SRGGridLines | m_nMajorGridWidth | Width of the major grid lines

//@mdata int  | SRGGridLines | m_nMinorGridWidth | Width of the minor grid lines

//@mdata CPtrList  * | SRGGridLines | m_pTickPositionList | Pointer to the tick position list that coordinates label positions with tick and grid objects

//@mdata COLORREF  | SRGGridLines | m_MajorGridColor | RGB color of the major grids

//@mdata COLORREF  | SRGGridLines | m_MinorGridColor | RGB color of the minor grids

//@mdata BOOL  | SRGGridLines | m_bVertical | Vertical flag -- if TRUE, these grid lines are vertically oriented in the display rectangle

//@mdata CRect  | SRGGridLines | m_DisplayRect | Rectangle that corresponds to the data display area

//@mdata LOGPEN  *| SRGGridLines | m_pMinorLogPen | Pointer to an optional LOGPEN structure used to define the minor grid-line style

//@mdata LOGPEN  *| SRGGridLines | m_pMajorLogPen | Pointer to an optional LOGPEN structure used to define the major grid-line style

//@mdata DWORD  *| SRGGridLines | m_pMajorStyleList | Pointer to the style item list used to construct a pen for the major grid lines

//@mdata DWORD  *| SRGGridLines | m_pMinorStyleList | Pointer to the style item list used to construct a pen for the minor grid lines

//@mdata int  | SRGGridLines | m_nMajorStyleCount | Count of style items used in the construction of the pen for major grid lines

//@mdata int  | SRGGridLines | m_nMinorStyleCount | Count of style items used in the construction of the pen for minor grid lines

// adinsert AutoDuck insertion point for SRGGridLines 
//$head Component classes (Specialized sub components)
//$level 2
//@doc SRGGridLines 
//@class This grid line manager is similar to the <c SRGTickMarks> class in that it uses a 
//list of CPoint objects generated by the <c SRGraphLabelBlock>-based classes to generate 
//and position the grid lines. These grids may show major and minor lines that may 
//have different color and line styles. A specified number of minor lines are drawn for every 
//major line. The major lines are positioned by the tick position list.
//@base public | SRGraphComponent
class SRGGridLines : public SRGraphComponent  
{
public:
	virtual CScale SetComponentFileVersion();
	//@cmember
	/* Sets the number of style items used in constructing a pen for major grid lines*/
	virtual void SetMajorStyleCount(int v){m_nMajorStyleCount=v;}
	//@cmember
	/* Sets the number of style items used in constructing a pen for minor grid lines*/
	virtual void SetMinorStyleCount(int v){m_nMinorStyleCount=v;}
	//@cmember
	/* Returns the number of style items used in constructing a pen for major grid lines*/
	virtual int GetMajorStyleCount(){return m_nMajorStyleCount;}
	//@cmember
	/* Returns the number of style items used in constructing a pen for minor grid lines*/
	virtual int GetMinorStyleCount(){return m_nMinorStyleCount;}
	//@cmember
	/* Specifies the number of minor grid lines for each major grid line*/
	virtual void SetMinorGridRatio(int v){m_nMinorGridRatio=v;}
	//@cmember
	/* Returns the number of minor grid lines for each major grid line*/
	virtual int GetMinorGridRatio(){return m_nMinorGridRatio;}
	//@cmember
	/* Specifies an optional LOGPEN structure that defines the pen for the minor grid lines*/
	virtual void SetMinorLogPen(LOGPEN *v){m_pMinorLogPen=v;}
	//@cmember
	/* Specifies an optional LOGPEN structure that defines the pen for the major grid lines*/
	virtual void SetMajorLogPen(LOGPEN *v){m_pMajorLogPen=v;}
	//@cmember
	/* Specifies a style item list that defines the pen for the major grid lines*/
	virtual void SetMajorStyleList(DWORD *v){m_pMajorStyleList=v;}
	//@cmember
	/* Specifies a style item list that defines the pen for the minor grid lines*/
	virtual void SetMinorStyleList(DWORD *v){m_pMinorStyleList=v;}
	//@cmember
	/* Returns the LOGPEN structure that defines the pen for the minor grid lines*/
	virtual LOGPEN *GetMinorLogPen(){return m_pMinorLogPen;}
	//@cmember
	/* Returns the LOGPEN structure that defines the pen for the major grid lines*/
	virtual LOGPEN *GetMajorLogPen(){return m_pMajorLogPen;}
	//@cmember
	/* Returns a pointer to the style item list that defines the pen for the major grid lines*/
	virtual DWORD *GetMajorStyleList(){return m_pMajorStyleList;}
	//@cmember
	/* Returns a pointer to the style item list that defines the pen for the minor grid lines*/
	virtual DWORD *GetMinorStyleList(){return m_pMinorStyleList;}
	//@cmember
	/* Saves or restores this object to an archive*/
	virtual void Serialize(CArchive &ar);
	//@cmember
	/* Specifies the rectangle that corresponds to the data display area*/
	virtual void SetDisplayRect(CRect v){m_DisplayRect=v;}
	//@cmember
	/* Returns the rectangle that corresponds to the data display area*/
	virtual CRect GetDisplayRect(){return m_DisplayRect;}
	//@cmember
	/* Sets the flag that selects vertical or horizontal orientation of grid lines*/
	virtual void SetVertical(BOOL v){m_bVertical=v;}
	//@cmember
	/* Returns the flag that selects vertical or horizontal orientation of grid lines*/
	virtual BOOL GetVertical(){return m_bVertical;}
	//@cmember
	/* Sets a pointer to the tick position list that coordinates label positions with tick and grid objects*/
	virtual void SetptrTickPositionList(CPtrList *pList){m_pTickPositionList=pList;}
	//@cmember
	/* Draws the grid lines*/
	virtual void DrawForeground();
	//@cmember
	/* Specifies the RGB color for the major grid lines*/
	virtual void SetMajorGridColor(COLORREF r){m_MajorGridColor=r;}
	//@cmember
	/* Specifies the RGB color for the minor grid lines*/
	virtual void SetMinorGridColor(COLORREF r){m_MinorGridColor=r;}
	//@cmember
	/* Sets the pen width for the major grid lines*/
	virtual void SetMajorGridWidth(int n){m_nMajorGridWidth=n;}
	//@cmember
	/* Sets the pen width for the minor grid lines*/
	virtual void SetMinorGridWidth(int n){m_nMinorGridWidth=n;}
	//@cmember
	/*  Sets the pen style for the major grid lines*/
	virtual void SetMajorGridStyle(int n){m_nMajorGridStyle=n;}
	//@cmember
	/* Sets the pen style for the minor grid lines*/
	virtual void SetMinorGridStyle(int n){m_nMinorGridStyle=n;}
	//@cmember
	/* Returns the RGB color for the major grid lines*/
	virtual COLORREF GetMajorGridColor(){return m_MajorGridColor;}
	//@cmember
	/* Returns the RGB color for the minor grid lines*/
	virtual COLORREF GetMinorGridColor(){return m_MinorGridColor;}
	//@cmember
	/* Returns the width of the major grid lines*/
	virtual int GetMajorGridWidth(){return m_nMajorGridWidth;}
	//@cmember
	/* Returns the width of the minor grid lines*/
	virtual int GetMinorGridWidth(){return m_nMinorGridWidth;}
	//@cmember
	/* Returns the pen style for the major grid lines*/
	virtual int GetMajorGridStyle(){return m_nMajorGridStyle;}
	//@cmember
	/* Returns the pen style for the minor grid lines*/
	virtual int GetMinorGridStyle(){return m_nMinorGridStyle;}
	//@cmember
	/* Constructor*/
	SRGGridLines();
	DECLARE_SERIAL(SRGGridLines);
	//@cmember
	/* Destructor*/
	virtual ~SRGGridLines();

protected:
	//@cmember
	/* Override to draw horizontal grid lines with a custom style*/
	virtual void DrawCustomHGrid(int x,int y);
	//@cmember
	/* Override to draw vertical grid lines with a custom style*/
	virtual void DrawCustomVGrid(int x,int y);
	//@cmember
	/* Draws a single horizontal grid line in a given style*/
	virtual void DrawHGridLine(int x,int y, CPen *p=NULL);
	//@cmember
	/* Draws a single vertical grid line in a given style*/
	virtual void DrawVGridLine(int x,int y,CPen *p=NULL);

	//@cmember
	/* Number of minor grid lines to be drawn between major grid lines*/
	int m_nMinorGridRatio;
	//@cmember
	/* Pen style for major grid lines*/
	int m_nMajorGridStyle;
	//@cmember
	/* Pen style for minor grid lines*/
	int m_nMinorGridStyle;
	//@cmember
	/* Pen width for major grid lines*/
	int m_nMajorGridWidth;
	//@cmember
	/* Pen width for minor grid lines*/
	int m_nMinorGridWidth;
	//@cmember
	/* Pointer to the tick position list that coordinates label positions with tick and grid objects*/
	CPtrList *m_pTickPositionList;
	//@cmember
	/* RGB color for major grid lines*/
	COLORREF m_MajorGridColor;
	//@cmember
	/* RGB color for minor grid lines*/
	COLORREF m_MinorGridColor;
	//@cmember
	/* Vertical flag -- TRUE for vertical, FALSE for horizontal*/
	BOOL m_bVertical;
	//@cmember
	/* Rectangle that corresponds to the data display area*/
	CRect m_DisplayRect;
	//@cmember
	/* Optional LOGPEN structure defining the pen style for the minor grid lines*/
	LOGPEN *m_pMinorLogPen;
	//@cmember
	/* Optional LOGPEN structure defining the pen style for the major grid lines*/
	LOGPEN *m_pMajorLogPen;
	//@cmember
	/* Pointer to a list of style items that define the pen for the major grid lines*/
	DWORD *m_pMajorStyleList;
	//@cmember
	/* Pointer to a list of style items that define the pen for the minor grid lines*/
	DWORD *m_pMinorStyleList;
	//@cmember
	/* Number of items in the list of styles for the major grid lines*/
	int m_nMajorStyleCount;
	//@cmember
	/* Number of items in the list of styles for the minor grid lines*/
	int m_nMinorStyleCount;


	//@cmember
	/* Overidden to do nothing*/
	virtual void DrawShadow();
	//@cmember
	/* Overidden to do nothing*/
	virtual void DrawBorder();
	//@cmember
	/* Overidden to do nothing*/
	virtual void DrawFill();
};





#endif // !defined(_SRGGRIDLINES_H_INCLUDED_)
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

