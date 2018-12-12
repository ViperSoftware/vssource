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
//@doc SRGraphTitle
//@module SRGraphTitle.h|  definition of the graph title class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif
#ifndef __SRGRAPHTITLE__
#define __SRGRAPHTITLE__

//////////////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphTitle

//@doc SRGraphTitle

//@mdata int  | SRGraphTitle | m_nJustification | Text justification<nl>
//0=Left justified<nl>
//1=Right justified<nl>
//2=Centered in component
//@see <mf SRGraphTitle::SetText> <mf SRGraphTitle::GetJustification> <mf SRGraphTitle::SetJustification>

//@mdata CString  | SRGraphTitle | m_strTitle | Text to be displayed
//@rem Note that setting this text outside the draw loop will never be seen because 
//the component updates the text using <mf SRGraphTitle::GetParentContent> every draw cycle.

//@mdata CFont  | SRGraphTitle | m_Font | CFont object which defines the text style to be used
//@see <mf SRGraphTitle::GetFont> <mf SRGraphTitle::SetFont>

//@mdata COLORREF  | SRGraphTitle | m_RGBTextColor | Sets the RGB color used to display text
//@see <mf SRGraphTitle::SetTextColor> <mf SRGraphTitle::GetTextColor>

//@mdata BOOL  | SRGraphTitle | MakeFont | Internal font update semaphore<nl>
//When TRUE the component updates the font information and creates a new font.<nl>
//Use this variable to ensure correct updating of fonts after changes to a font style.

//@mdata int  | SRGraphTitle | m_nSize | Font size -- positive numbers specify the font size 
//in points, negative numbers specify the size in screen pixels
//
//@ex For example: | <nl>
//	SetFontSize(10);	
//	SetMakeFont();	// Sets a font of 10 points
//
//	SetFontSize(-10);
//	SetMakeFont();	//Sets a font of 10 pixels
//@see <mf SRGraphTitle::SetFontSize> <mf SRGraphTitle::GetFontSize> <md SRGraphTitle::MakeFont> <mf SRGraphTitle::SetMakeFont>

//@mdata int | SRGraphTitle | m_nStyle | Bitwise flag which defines the font settings for bold, italic and other styles<nl>
//bit 0 = BOLD<nl>
//bit 1 = ITALIC<nl>
//bit 2 = UNDERLINE<nl>
//bit 3 = STRIKEOUT<nl>
//@see <mf SRGraphTitle::SetFontStyle> <mf SRGraphTitle::GetFontStyle>

//@mdata CString | SRGraphTitle | m_strFaceName | Name of the current typeface (eg. "Times New Roman")
//@see <mf SRGraphTitle::SetFaceName> <mf SRGraphTitle::GetFaceName> <mf SRGraphTitle::SetFont>

//@mfunc  void | SRGraphTitle |  SetFontSize | Set the font size
//@parm int | Size | Desired font size
//@rem Positive numbers make point size fonts. The absolute values of negative numbers make pixel sized fonts.
//@see <mf SRGraphTitle::GetFontSize> <md SRGraphTitle::m_nFontSize>

//@mfunc  void | SRGraphTitle |  SetFontStyle | Sets the bitwise flags which define the font style
//@parm int | style | Logical OR combination of the required flags
//@see For bit combinations... <md SRGraphTitle::m_nStyle> <mf SRGraphTitle::GetFontStyle>

//@mfunc  void | SRGraphTitle |  SetJustification | Sets the justification style
//@parm int | Justification | Type of justification desired
//@see For justification types... <md SRGraphTitle::m_nJustification> <mf SRGraphTitle::GetJustification>

//@mfunc  int | SRGraphTitle | GetFontSize | Fetches the current font size
//@rdesc Contents of the m_nSize member
//@see <mf SRGraphTitle::SetSize> <md SRGraphTitle::m_nSize>

//@mfunc  int | SRGraphTitle |  GetFontStyle | Fetches the current font style
//@rdesc Contents of the m_nStyle member
//@see <mf SRGraphTitle::SetFontStyle> <md SRGraphTitle::m_nStyle>

//@mfunc  int | SRGraphTitle |  GetJustification | Fetches the current font justification
//@rdesc Contents of the m_nJustification member
//@see <mf SRGraphTitle::SetJustification> <md SRGraphTitle::m_nJustification>

//@mfunc  COLORREF | SRGraphTitle | GetTextColor | Fetches the color currently used for text
//@rdesc Contents of the m_RGBTextColor member
//@see <mf SRGraphTitle::SetTextColor> <md SRGraphTitle::m_RGBTextColor>

//@mfunc  CString& | SRGraphTitle | GetText | Fetches the current text for this title
//@rdesc Contents of the m_strTitle member
//@see <mf SRGraphTitle::SetText> <md SRGraphTitle::m_strTitle>

//@mfunc  CFont* | SRGraphTitle | GetFont | Returns a pointer to the m_Font member
//@rdesc Pointer to the m_Font member
//@see <md SRGraphTitle::m_Font> <mf SRGraphTitle::SetFont>

//@mfunc void | SRGraphTitle | SetMakeFont | Sets or resets the MakeFont variable<nl>//You should set the MakeFont variable after changing font styles<nl>
//The font is updated at draw time and it is only changed if the MakeFont semaphore is set.
//@parm BOOL | make | TRUE (default) to set the semaphore, FALSE to reset
//@rem This method is used because the UpdateFont routine needs to get information directly 
//from the CDC used to draw the font. Therefore the request to change font style is deferred 
//until the m_pDC pointer is known to be valid.
//@see <md SRGraphTitle::MakeFont> <mf SRGraphTitle::UpdateFont> <mf SRGraphTitle::SetFontStyle> <mf SRGraphTitle::SetFontSize>

//@mfunc void | SRGraphTitle | SetTextColor | Initializes the text color used in this object
//@parm COLORREF | c | Desired color

//@doc SRGraphTitle
//@mdata LOGFONT *  | SRGraphTitle | m_pLogFont | Normally NULLthis pointer may be set to point to a valid LOGFONT structure.<nl>
//This structure will then override the font creation process and the fonts will be defined by the values in the LOGFONT structure supplied.<nl>
//@devnote The object will not delete this structure if it is left in place during the destruction of the title component. It is up to the programmer to
// ensure that correct memory management is carried out.

//@doc SRGraphTitle
//@mfunc LOGFONT  *  | SRGraphTitle |GetLogFont | Returns a pointer to the LOGFONT stored in this object 

//@doc SRGraphTitle
//@mfunc void  | SRGraphTitle | SetLogFont | Initializes the LOGFONT used in this object.
//@parm LOGFONT *  | v | Pointer to a LOGFONT structure that describes the desired font 

// adinsert for SRGraphTitle
//$head Component classes
//$level 1
//////////////////////////////////////////////////////////////////
//@doc SRGraphTitle
//@class Title manager derived from <c SRGraphComponent>
//@base public | SRGraphComponent
class SRGraphTitle : public SRGraphComponent
{
//@access protected data members
protected:
	//@cmember
	/* Type of text justification to use*/
	int m_nJustification;
	//@cmember
	/* Title text*/
	CString m_strTitle;
	//@cmember
	/* Font in which to display text*/
	CFont m_Font;
	//@cmember
	/* Color of the text*/
	COLORREF m_RGBTextColor;
	//@cmember
	/* Semaphore which signifies that a font has been set or that an existing font needs updating*/
	BOOL MakeFont;
	//@cmember
	/* Font size -- negative numbers set sizes in pixels, positive numbers set sizes in points*/
	int m_nSize;
	//@cmember
	/* Style of font*/
	int m_nStyle;
	//@cmember
	/* Font typeface*/
	CString m_strFaceName;

//@access Protected member functions
protected:
	//@cmember
	/* A pointer to an optional LOGFONT that will define the font*/
	LOGFONT * m_pLogFont;

	//@cmember
	/* Draws the text*/
	virtual void DrawForeground();

	//@cmember
	/* Keeps font data current*/
	virtual BOOL UpdateFont();

	//@cmember
	/* Retrieves pertinent data from the parent*/
	virtual void GetParentContent();

//@access public member functions
public:
	//@cmember,mfunc
	/* Initializes the font using the supplied LOGFONT */
	inline void SetLogFont(LOGFONT * v){m_pLogFont=v;}
	//@cmember
	/* Returns a pointer to the LOGFONT stored in this object */
	inline LOGFONT * GetLogFont(){return m_pLogFont;}
	//@cmember
	/* Calculates the font size based on 90% of the title panel height*/
	virtual int CalcFontAutoSize();
	//@cmember
	/* Sets or resets the MakeFont semaphore*/
	virtual void SetMakeFont(BOOL make=TRUE);
	//@cmember
	/* Returns logical size of text*/
	virtual CSize GetTextDimension(LPCTSTR text);
	//@cmember
	/* Constructor*/
	SRGraphTitle();
	//@cmember
	/* Sets the point or pixel size of the current font*/
	inline void SetFontSize(int Size){m_nSize=Size;}
	//@cmember
	/* Sets the style of the font (ie. bold, underline, etc.)*/
	inline void SetFontStyle(int style){m_nStyle=style;}
	//@cmember
	/* Sets the font justification to left (0), right (1) or centered (2)*/
	inline void SetJustification(int Justification){m_nJustification=Justification;}
	//@cmember
	/* Fetches the font size data*/
	inline int GetFontSize(){return m_nSize;}
	//@cmember
	/* Fetches the font style data*/
	inline int GetFontStyle(){return m_nStyle;}
	//@cmember
	/* Fetches the font justification*/
	inline int GetJustification(){return m_nJustification;}
	//@cmember
	/* Fetches the RGB color used to display text*/
	virtual COLORREF GetTextColor(){return m_RGBTextColor;}
	//@cmember
	/* Returns the title text itself*/
	inline CString& GetText(){return m_strTitle;}
	//@cmember
	/* Fetches a pointer to the m_Font (CFont) object from this component*/
	inline CFont* GetFont(){return &m_Font;}
	//@cmember
	/* Sets the typeface name (ie. "Times New Roman")*/
	virtual void SetFaceName(CString &FaceName);
	//@cmember
	/* Fetches the type face name currently in use*/
	virtual CString& GetFaceName();

#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Reads and parses a chart template line*/
	virtual int ReadTemplateLine(LPCTSTR line);
	//@cmember
	/* Writes the name "title" to the template file*/
	virtual void WriteName(CStdioFile* file);
	//@cmember
	/* Outputs the current font details to the template file*/
	virtual void WriteFontParameters(CStdioFile* file);
#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE


#ifdef _DEBUG

	void Dump(CDumpContext& dc) const;

#endif


	DECLARE_SERIAL(SRGraphTitle);
	//@cmember
	/* Stores or retrieves information about the title via a CArchive*/
	virtual void Serialize(CArchive &ar);

	//@cmember
	/* Destructor -- ensures that no GDI objects remain*/
	virtual ~SRGraphTitle();

	//@cmember
	/* Sets font size, style, and typeface*/
	virtual BOOL SetFont(int nSize,int nStyle,CString FaceName);

	//@cmember
	/* Modifies the contents of the text*/
	virtual void SetText(LPCTSTR text,int justification=0);

	//@cmember
	/* Sets the color of text displayed to an RGB value*/
	virtual void SetTextColor(COLORREF color){m_RGBTextColor=color;}

};





#endif //__SRGRAPHTITLE__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

