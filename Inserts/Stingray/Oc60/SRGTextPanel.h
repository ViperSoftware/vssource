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
//@doc SRGTextPanel
//@module SRGTextPanel.h | SRGTextPanel header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SRGTextPanel.cpp: Interface of the SRGTextPanel class
//
/////////////////////////////////////////////////////////////////

#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef _SRGTEXTPANEL_H_INCLUDED_
#define _SRGTEXTPANEL_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


//@doc SRGTextPanel

//@mfunc void  | SRGTextPanel | SetTitleOrientation | Sets the orientation of the title block with respect to the text block
//@parm _TitleOrientation  | n | Enumeration value 0-3 signifying top, left, right, and bottom respectively

//@mfunc _TitleOrientation  | SRGTextPanel | GetTitleOrientation | Returns the title orientation parameter
//@see <mf SRGTextPanel::SetTitleOrientation>

//@mfunc void  | SRGTextPanel | SetTitleTextColor | Sets the RGB color of the title text
//@parm COLORREF  | c | RGB color value

//@mfunc void  | SRGTextPanel | SetBodyTextColor | Sets the color of the body text
//@parm COLORREF  | c |  RGB color value

//@mfunc COLORREF  | SRGTextPanel | GetTitleTextColor | Returns the RGB color value of the title text

//@mfunc COLORREF  | SRGTextPanel | GetBodyTextColor | Returns the RGB color value of the body text

//@mfunc SRGraphStyle * | SRGTextPanel | GetTitleStyle | Returns a pointer to the SRGraphStyle object that controls the title panel

//@mfunc void  | SRGTextPanel | SetBodyFontSize | Sets the size of the font for body text
//@parm int  | n | Positive values denote size in points, Negative values denote size in pixels.

//@mfunc void  | SRGTextPanel | SetTitleFontSize | Sets the size of the title font
//@parm int  | n | Positive values denote size in points, Negative values denote size in pixels.

//@mfunc void  | SRGTextPanel | SetBodyFontStyle | Sets the style of the body font
//@parm int  | n | Bit-mapped flags
//@see <mf SRGraphTitle::SetFontStyle>

//@mfunc void  | SRGTextPanel | SetTitleFontStyle | Sets the style of the title font
//@parm int  | n | Bit-mapped flags
//@see <mf SRGraphTitle::SetFontStyle>

//@mfunc void  | SRGTextPanel | SetBodyFontFaceName | Set the typeface name of the body font
//@parm CString  | strFaceName | A valid typeface name (eg. "Times New Roman")

//@mfunc void  | SRGTextPanel | SetTitleFontFaceName | Set the typeface name of the title font.
//@parm CString  | strFaceName | A valid typeface name (eg. "Times New Roman")

//@mfunc BOOL  | SRGTextPanel | GetUseTitle | Returns TRUE if the title is to be used

//@mfunc void  | SRGTextPanel | SetUseTitle | Sets the title use flag
//@parm BOOL  | b | TRUE to use and display a title panel and text

//@mfunc void  | SRGTextPanel | SetResize | Sets the auto-resize flag
//@parm BOOL  | b=TRUE | Set TRUE to automatically resize the panel to accommodate the text

//@mfunc BOOL  | SRGTextPanel | GetResize | Returns the resize flag

//@mdata int  | SRGTextPanel | m_nBodyFontJustification | Justification of the body text
//@see <c SRGraphTitle> justification values for details

//@mdata int  | SRGTextPanel | m_nTitleFontJustification | Justification of the title text
//@see <c SRGraphTitle> justification values for details

//@mdata CRect  | SRGTextPanel | m_BGRect | Complete background rectangle

//@mdata CRect  | SRGTextPanel | m_RefRect | Reference rectangle used in auto sizing

//@mdata SRGraphStyle  | SRGTextPanel | m_TitleStyle | Style member of the title panel

//@mdata CRect  | SRGTextPanel | m_TitleRect | Rectangle covered by the title

//@mdata BOOL  | SRGTextPanel | m_bSizeForeground | When TRUE the foreground is being calculated

//@mdata COLORREF  | SRGTextPanel | m_BodyTextColor | RGB color of the body text

//@mdata COLORREF  | SRGTextPanel | m_TitleTextColor | RGB color of the title text

//@mdata int  | SRGTextPanel | m_nEscapement | Escapement angle of the title text font

//@mdata CFont  | SRGTextPanel | m_TitleFont | Title font member

//@mdata SRGraphAnnotationList  | SRGTextPanel | m_TitleText | Text contained in the title

//@mdata SRGraphAnnotationList  | SRGTextPanel | m_BodyText | Text contained in the body

//@mdata CRect  | SRGTextPanel | m_TextRect | Text area rectangle

//@mdata BOOL  | SRGTextPanel | m_bUseTitle | TRUE when the title is visible

//@mdata BOOL  | SRGTextPanel | m_bResize | TRUE when the panel resizes to accommodate the text length

//@mdata int  | SRGTextPanel | m_nTitleFontSize | Height of the title font

//@mdata int  | SRGTextPanel | m_nBodyFontSize | Height of the body font

//@mdata int  | SRGTextPanel | m_nTitleFontStyle | Style of the title font (ie. bold, underline, etc.)
//@see <c SRGraphTitle> for details on font styling

//@mdata int  | SRGTextPanel | m_nBodyFontStyle | Style of the body font (ie. bold, underline, etc.)
//@see <c SRGraphTitle> for details on font styling

//@mdata CString  | SRGTextPanel | m_strTitleFontFaceName | Typeface name of the title font

//@mdata CString  | SRGTextPanel | m_strBodyFontFaceName | Typeface name of the body font

//@mdata enum  | SRGTextPanel | m_nTitleOrientation | Specifies the location of the text within the panel -- top, bottom, left, or right

//@mfunc virtual int  | SRGTextPanel | GetBodyFontSize | Returns the size of the font used to display the body text

//@mfunc virtual int  | SRGTextPanel | GetTitleFontSize | Returns the size of the font used to display the title text

//@mfunc virtual int  | SRGTextPanel | GetBodyFontStyle | Returns the style of the font used to display the body text

//@mfunc virtual int  | SRGTextPanel | GetTitleFontStyle | Returns the style of the font used to display the title text

//@mfunc virtual CString  | SRGTextPanel | GetBodyFontFaceName | Returns the typeface name of the body text

//@mfunc virtual CString  | SRGTextPanel | GetTitleFontFaceName | Returns the typeface name of the title text

//@mfunc virtual CString  | SRGTextPanel | GetTitleText | Returns the title text string
//@parm int | code | Country code for desired string

//adinsert

//@doc SRGTextPanel 
//$head Component classes
//$level 1
//@class This class provides a simple multi-line text panel with independently styled title and body fonts.
//@base public | SRGraphTitle
class SRGTextPanel : public SRGraphTitle  
{
public:
	virtual CScale SetComponentFileVersion();
#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Exports font parameters to the template file*/
	virtual void WriteFontParameters(CStdioFile *file);

	//@cmember
	/* Writes the "textpanel" command name to the template file*/
	virtual void WriteName(CStdioFile *file);
#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember
	/* Default constructor*/
	SRGTextPanel();
	//@cmember
	/* Destructor*/
	virtual ~SRGTextPanel();

	DECLARE_SERIAL(SRGTextPanel);

	//@cmember
	/* Serializes this object*/
	virtual void Serialize(CArchive &ar);

	//@cmember
	/* Specifies the location of text within the panel*/
	enum _TitleOrientation
	{
		top,
		left,
		right,
		bottom
	} m_nTitleOrientation;

	//@cmember
	/* Returns the title text*/
	virtual CString GetTitleText(int code = 1)	{return m_TitleText.GetAnnotation(code);}
	//@cmember
	/* Sets the orientation of the title -- top, left, bottom or right*/
	virtual void SetTitleOrientation(_TitleOrientation n){m_nTitleOrientation = n;}
	//@cmember
	/* Returns the current title orientation*/
	virtual _TitleOrientation GetTitleOrientation(){return m_nTitleOrientation;}
	//@cmember
	/* Sets the color of the title text*/
	virtual void SetTitleTextColor(COLORREF c){m_TitleTextColor=c;}
	//@cmember
	/* Sets the color of the body text*/
	virtual void SetBodyTextColor(COLORREF c){m_BodyTextColor=c;}
	//@cmember
	/* Returns the color of the title text*/
	virtual COLORREF GetTitleTextColor(){return m_TitleTextColor;}
	//@cmember
	/* Returns the color of the body text*/
	virtual COLORREF GetBodyTextColor(){return m_BodyTextColor;}
	//@cmember
	/* Returns a pointer to the style object associated with the title bar*/
	virtual SRGraphStyle * GetTitleStyle(){return &m_TitleStyle;}
	//@cmember
	/* Draws this object*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);
	//@cmember
	/* Refreshes the title font*/
	virtual void UpdateTitleFont();
	//@cmember
	/* Calculates the rectangle required to display the title*/
	virtual CRect CalcTitleRect();
	//@cmember
	/* Sets the text displayed in the body panel*/
	virtual void SetBodyText(CString s,int code=1);
	//@cmember
	/* Returns the text displayed in the body panel*/
	virtual CString GetBodyText(int code = 1);
	//@cmember
	/* Sets the text displayed in the title panel*/
	virtual void SetTitleText(CString s,int code=1);
	//@cmember
	/* Sets the size of the font used to display the body text*/
	virtual void SetBodyFontSize(int n){m_nBodyFontSize=n;}
	//@cmember
	/* Returns the size of the font used to display the body text*/
	virtual int GetBodyFontSize(){ return m_nBodyFontSize; }
	//@cmember
	/* Sets the size of the font used to display the title text*/
	virtual void SetTitleFontSize(int n){m_nTitleFontSize=n;}
	//@cmember
	/* Returns the size of the font used to display the title text*/
	virtual int GetTitleFontSize(){ return m_nTitleFontSize;}
	//@cmember
	/* Sets the style of the font used to display the body text*/
	virtual void SetBodyFontStyle(int n){m_nBodyFontStyle=n;}
	//@cmember
	/* Returns the style of the font used to display the body text*/
	virtual int GetBodyFontStyle(){return m_nBodyFontStyle; }
	//@cmember
	/* Sets the style of the font used to display the title text*/
	virtual void SetTitleFontStyle(int n){m_nTitleFontStyle=n;}
	//@cmember
	/* Returns the style of the font used to display the title text*/
	virtual int GetTitleFontStyle(){return m_nTitleFontStyle;}

	//@cmember
	/* Calculates font size for the text panel body if the text style includes CX_FONT_AUTOSIZE */
	virtual int CalcFontAutoSize();
	//@cmember
	/* Sets the typeface name for the body text*/
	virtual void SetBodyFontFaceName(CString strFaceName){m_strBodyFontFaceName=strFaceName;}
	//@cmember
	/* Returns the typeface name of the body text*/
	virtual CString GetBodyFontFaceName(){return m_strBodyFontFaceName; }
	//@cmember
	/* Sets the typeface name for the title text*/
	virtual void SetTitleFontFaceName(CString strFaceName){m_strTitleFontFaceName=strFaceName;}
	//@cmember
	/* Returns the typeface name of the title text*/
	virtual CString GetTitleFontFaceName() {return m_strTitleFontFaceName;}
	//@cmember
	/* Returns TRUE if the title is to be used*/
	virtual BOOL GetUseTitle(){return m_bUseTitle;}
	//@cmember
	/* Set TRUE if the title is to be used*/
	virtual void SetUseTitle(BOOL b){m_bUseTitle=b;}
	//@cmember
	/* Set TRUE if the body text panel is to be resizable*/
	virtual void SetResize(BOOL b=TRUE){m_bResize=b;}
	//@cmember
	/* Returns TRUE if the body text panel is resizable*/
	virtual BOOL GetResize(){return m_bResize;}
	//@cmember
	/* Overidden to do nothing*/
	virtual void GetParentContent();
	//@cmember,mfunc
	/* initializes font justification for the title panel */
	virtual void SetTitleFontJustification(int v){m_nTitleFontJustification=v;}
	//@cmember,mfunc
	/* returns font justification for the title panel */
	virtual int GetTitleFontJustification(){return m_nTitleFontJustification;}
	//@cmember,mfunc
	/* initializes font justification for the body panel */
	virtual void SetBodyFontJustification(int v){m_nBodyFontJustification=v;}
	//@cmember,mfunc
	/* returns font justification for the body panel */
	virtual int GetBodyFontJustification(){return m_nBodyFontJustification;}

protected:
	//@cmember
	/* Justification of body text*/
	int m_nBodyFontJustification;
	//@cmember
	/* Justification of title text*/
	int m_nTitleFontJustification;
	//@cmember
	/* Background rectangle*/
	CRect m_BGRect;
	//@cmember
	/* Rectangle used as a comparison reference*/
	CRect m_RefRect;
	//@cmember
	/* Style parameters for the title panel*/
	SRGraphStyle m_TitleStyle;
	//@cmember
	/* Rectangle used to draw the title*/
	CRect m_TitleRect;
	//@cmember
	/* Set to TRUE when the foreground is being sized*/
	BOOL m_bSizeForeground;
	//@cmember
	/* RGB color of body text*/
	COLORREF m_BodyTextColor;
	//@cmember
	/* RGB color of title text*/
	COLORREF m_TitleTextColor;
	//@cmember
	/* Escapement angle for text*/
	int m_nEscapement;
	//@cmember
	/* Font for title text*/
	CFont m_TitleFont;
	//@cmember
	/* Annotation list for title text*/
	SRGraphAnnotationList m_TitleText;
	//@cmember
	/* Annotation list for body text*/
	SRGraphAnnotationList m_BodyText;
	//@cmember
	/* Text area rectangle*/
	CRect m_TextRect;
	//@cmember
	/* Flag to use title*/
	BOOL m_bUseTitle;
	//@cmember
	/* Automatic resizing flag*/
	BOOL m_bResize;
	//@cmember
	/* Size of font for title text*/
	int m_nTitleFontSize;
	//@cmember
	/* Size of font for body text*/
	int m_nBodyFontSize;
	//@cmember
	/* Font style for title text*/
	int m_nTitleFontStyle;
	//@cmember
	/* Fong style for body text*/
	int m_nBodyFontStyle;
	//@cmember
	/* Font facename for title text*/
	CString m_strTitleFontFaceName;
	//@cmember
	/* Font facename for body text*/
	CString m_strBodyFontFaceName;


	//@cmember
	/* Draws the fill of the title rectangle*/
	virtual void DrawFill();
	//@cmember
	/* Draws the text panel foreground*/
	virtual void DrawForeground();
};


#endif // !defined(_SRGTEXTPANEL_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


