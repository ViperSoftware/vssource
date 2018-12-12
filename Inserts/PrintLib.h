#ifndef __PRINTDOC_H_
#define __PRINTDOC_H_

#pragma comment (lib, "PrintLib.lib") // make linker search this lib

#include "\VSSource\inserts\xgeometry.h"

#define PRINTDRV_CONTEXT 

class PRINTDRV_CONTEXT CLocation:public CObject
{
public:
   CLocation();
   CLocation(const CLocation& Loc);
   CLocation(float, float);
   float m_x;
   float m_y;
   const CLocation& operator=(const CLocation& r);
   int IsLocationInRect(CXRect &Rect);
};


typedef CList<CLocation, CLocation&>CPrintPolyLine;

class PRINTDRV_CONTEXT COTM:public CObject
{
public: // data
	COTM();
   COTM(CXRect& WinRect, CXRect& ObjRect);
   ~COTM();
   const COTM& operator=(const COTM& OTM);

   //window to place object  (in current coordinates)
   CXRect m_WinRect; 
   // Object window (in new object coordinates)
   CXRect m_ObjRect;
   // Scale factor used to map new object to current coors
   float      m_ObjScale;

public: // methods
   CLocation WinToObjLocation(CLocation& Loc);
   CLocation ObjToWinLocation(CLocation& Loc);
};

class PRINTDRV_CONTEXT CPrintCircle:public CObject
{
public:
   CXRect nBoundsRect;
   int   nColor;
   const CPrintCircle& operator=(const CPrintCircle& r);
};

class PRINTDRV_CONTEXT CPrintRect:public CObject
{
public:
   CXRect nRect;
   int   nColor;
   int   nBGColor;
   float fThick;
   const CPrintRect& operator=(const CPrintRect& r);
};

class PRINTDRV_CONTEXT CPrintDocImage:public CObject
{
public:
   CXRect	nRect;
   CString	m_Path;
   const CPrintDocImage& operator=(const CPrintDocImage& r);
};


class PRINTDRV_CONTEXT CPrintLine:public CObject
{
public:
   CPrintLine();
   CPrintLine(const CPrintLine& Ln);
   CPrintLine(CLocation& lFrom, CLocation& lTo);

   CLocation From;
   CLocation To;
   float     fThick;
   int       nColor;
   const CPrintLine& operator=(const CPrintLine& r);
};

class PRINTDRV_CONTEXT CPrintText:public CObject
{
public:
	void PrintBarCode(CDC* pDC);
	CLocation  location;
	float	fieldWidth;
	CString Options;
	CString strText;
	int     nColor;
	int     nBGColor;
	float   nFontHeight;
	float   nFontWidth;
	float   nFontWeight;
	float   nFontItalic;
	int		nFontEscapement;
	bool	bBarCode;
	CString strFontName;
	int		nFontPointSize;
	const CPrintText& operator=(const CPrintText& r);
};

typedef CList<CPrintText, CPrintText &>CPrintTextList;
typedef CList<CPrintLine, CPrintLine &>CPrintLineList;
typedef CList<CPrintRect, CPrintRect &>CPrintRectList;
typedef CList<CPrintCircle, CPrintCircle &>CPrintCircleList;
typedef CList<CPrintDocImage, CPrintDocImage &>CPrintDocImageList;

class PRINTDRV_CONTEXT CPrintPage:public CObject
{
public:
	virtual  ~CPrintPage();
   CPrintPage();
   CPrintTextList *PrintTextList;
   CPrintLineList *PrintLineList;
   CPrintRectList *PrintRectList;
   CPrintCircleList *PrintCircleList;
   CPrintDocImageList  *PrintImageList;
   int m_CurPageNo;
   CXRect m_PageSize;
   //const CPrintPage& CPrintPage::operator=(const CPrintPage& r);

};

class PRINTDRV_CONTEXT CPrintPageLayout : public CObject  
{
protected:
	int m_nColumns;
	int m_nRows;
	CXRect m_rcPageBounds;
public:
	CPrintPageLayout();
	virtual ~CPrintPageLayout();

public:
	void SetPageBoundary(CXRect& rcBounds);
	int SetNumColumns(int nColumns);
	int SetNumRows(int nRows);
	CXRect GetBoundary(int nRow, int nColumn);
};

typedef CList<CPrintPage* , CPrintPage* &>CPrintPageList;

class PRINTDRV_CONTEXT CPrintDoc:public CObject
{
public:
	COTM m_OTM;
   CPrintDoc();
   ~CPrintDoc();

protected:
	void CleanUp();
   BOOL bPageStarted;
   float m_text90flag;

public: // data
	int		m_nPages;
	int		m_nCurPage;
	int		m_pageOrientation;
	float m_scaleY;
	float m_scaleX;

	// used to support std point fonts (overrules variable fonts if m_PointFontName is not empty)
	CString m_OutputFileName;
	CString m_PaperSize;
	CString m_CurFontName;
	CString m_PointFontName;
	int		m_PointFontSize;
	// used to handle variable fixed font characters
	float m_CurFontWidth;
	float m_CurFontHeight;
	float m_DefFontWidth;
	float m_DefFontHeight;
	float m_CurFontWeight;
	float m_CurFontItalic;
	int   m_CurFontEscapement;
	int   m_DefFontEscapement;

    float m_PenWidth;
	COLORREF m_PenFGcolor;
	COLORREF m_PenBGcolor;

	float m_sizeX;
	float m_sizeY;
	CPrintPageList *pageDocList;
	CPrintPage *CurPage;
	CLocation m_PenLoc;
	CPrintPolyLine *PL;
	CXRect m_ViewPort;
	CXRect m_Window;
	CPrintPageLayout *m_Layout;

	CString		m_strPrinterName;

public: // methods
	void SetFont(const char *Name, int Size);
	void Print();
	BOOL PDGetDefaultPrinter(LPTSTR pPrinterName, LPDWORD pdwBufferSize);
	BOOL PDSetDefaultPrinter(LPTSTR pPrinterName);
	void SetOutputPath(const char *buf);
	void SetPaperSize(const char *buf);
	void PrintPreview();
	void ConvertCentimetersToInches(float *fX, float *fY);
	int m_nMapMode;
	void SetMapMode(int nMapMode);
	void AddBox(CLocation &LeftBottom, CLocation &RightTop);
	BOOL Reset();
	void SetFontEscapement(int nValue);
	void SetFontWeight(int nValue);
	void StartPage();
	void EndPage();
	void SetPageSize(CXRect &r);
	int  GetNumberofPages();

	void SetViewPort(CXRect& rect);
	void SetWindow(CXRect& rect);
   CPrintLine GetClippedLine(CPrintLine& Ln);
	void AddLine(CLocation& From, CLocation& To);
	void AddLine(float Xf, float Yf, float Xt, float Yt);
	void AddCircle(CXRect& rect);
	void AddPolyLine(CPrintPolyLine* lineRoot);
	void AddBox(CXRect &rect);
	void AddText(const char *buf, CLocation &Loc, bool bBarCode=false);
	void AddText(const char *buf, float X, float Y, bool bBarCode=false);
	void AddText(const char *buf, float X, float Y, float W, const char *Options=NULL);
	void AddImage(float xLL, float yLL, float xUR, float yUR, const char *path);
	void SetPageNumber(int Num);
	void SetPageOrientation(int i);
	void NextLine(const char *buf, float fSepHeight = 1.5f);
	void SetPen(CLocation &loc);
	CLocation PaperLocation(float X, float Y);
   void PrintTextLine(const char *string,unsigned char crflag = 1,int textweight = FW_NORMAL,
                 unsigned char italic = 0);
   void GetCharSize(float *Height, float *Width);
   void ChangeCharSize(float Height, float Width);
   void SetDefCharSize(int linesperpage, int charperline);
   void GetCurrentPosition(float *X, float *Y);
   void ChangePenWidth(float Width);
   void SetPenFGColor(COLORREF color) {m_PenFGcolor = color;};
   void SetPenBGColor(COLORREF color) {m_PenBGcolor = color;};
   void GetPageDimension(float *sizex, float *sizey);
   void SetPageDimension(float sizex, float sizey);

   CPoint ConvertInchesToPixels(CDC *pDC, float x, float y);
   CPoint ConvertInchesToPixels(CDC *pDC, CLocation &loc);
   CRect  ConvertInchesToPixels(CDC *pDC, float left, float right, float top, float bottom);
   CRect  ConvertInchesToPixels(CDC *pDC, CXRect& rect);
   void   ConvertPixelsToInches(CDC *pDC, float *x, float *y);
   void   ReDraw(CDC* pDC, int PageNo, char* FontName);
   void   PrepareDC(CDC* pDC, CPrintInfo* pInfo);

	BOOL LoadTextFile(CString strFileName);

   void LPtoDP(CDC *pDC, LPXSIZE lpSize) const;
   void DPtoLP(CDC *pDC,LPXSIZE lpSize) const;
   void DPtoHIMETRIC(CDC *pDC,LPXSIZE lpSize) const;
   void HIMETRICtoDP(CDC *pDC,LPXSIZE lpSize) const;
   void LPtoHIMETRIC(CDC *pDC,LPXSIZE lpSize) const;
   void HIMETRICtoLP(CDC *pDC,LPXSIZE lpSize) const;
};

#undef PRINTDRV_CONTEXT
#endif //__PRINTDOC_H
