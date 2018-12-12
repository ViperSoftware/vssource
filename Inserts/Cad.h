#ifndef __CCAD_H_
#define __CCAD_H_


#pragma comment (lib, "Cad.lib") // make linker search this lib

// misc CAD system structures

#ifndef POINT_2D_Defined
typedef struct two_d_coordinate
        {
                float x;
                float y;
        } POINT_2D;
#define POINT_2D_Defined
#endif

#ifndef POINT_3D_Defined
typedef struct three_d_coordinate
        {
                float x;
                float y;
                float z;
        } POINT_3D;
#define POINT_3D_Defined
#endif

#ifndef LINE_2D_Defined
typedef struct two_d_line
        {
                float xf;
                float yf;
                float xt;
                float yt;
        } LINE_2D;
#define LINE_2D_Defined
#endif

#ifndef LINE_3D_Defined
typedef struct three_d_line
        {
                float xf;
                float yf;
                float zf;
                float xt;
                float yt;
                float zt;
        } LINE_3D;
#define LINE_3D_Defined
#endif


typedef struct info_struct {
  short int Xpixels,        // max pixel X-axis
            Ypixels,        // max pixel Y-axis
            CharW,          // # pixels in char width
            CharH,
            ScreenType,
            Xunits,
            Yunits; } GINFO; // # pixels in char height

typedef struct  line_element  {short int len;
                                long  prev;
                                long  next;
                       unsigned char  type;     /* element type = 101 */
                       unsigned char  color;
                                char  num_axis;
                                char  num_points;
                               float  PtCoors;
                          }  LINE, *LINEPTR;

/* filled polygon data,  this structure follows the array of points
   defined above for type 110 elements */
typedef struct fpgon  {short  int  border_style;
                             char  fill_type;
                             char  line_style;
                            float  spacing,
                                   angle;
                                               }  FPGON, *FPGONPTR;
/*
   border_style: type of line to use (2,3,11-19), see line types above
   fill_type :   1 = shading
                 2 = hatching
                 3 = cross-hatching (90 degrees)
                 4 = diamond-hatching
   line_style:  when fill_type = 1,
                    0 = solid  (current foreground color)
                    1 = blank
                when fill_type = 2 & 3,
                    type of line to use (2,3,11-19), see line types
*/

typedef struct  text_element  {short int len;
                               long  prev;
                               long  next;
                      unsigned char  type;     /* element type = 121 */
                      unsigned char  color;
                               char  num_axis;
                               char  num_points;
                              float  xPt,
                                     yPt,
                                     angle,
                                     height;
                          short int  num_chars;
                               char  text;  // start of text (NULL terminated)
                                               }  TEXT, *TEXTPTR;

// The DimLn structure will handle continuous "Running" dimension lines as
// well as a single dimension line.  For continuous dimension lines, the
// 'PtCoors' variable at the end of the structure is the first of a variable
// number of points appended to the structure -- similar to the points
// appended to the line structure for a polygon.

typedef struct  dimln_element {short int len;
                               long  prev;
                               long  next;
                      unsigned char  type;     /* element type = 150 */
                      unsigned char  color;    /* element type = 151 */
                               char  num_axis;
                               char  num_points;
                              float  xPt1, yPt1,
                                     xPt2, yPt2,
                                     Asize,
                                     Chgt;
                               char  Atype,
                                     Corient;
                              float  PtCoors;
                                               }  DIMLN, *DIMLNPTR;
typedef struct    arc_element {short int len;
                               long  prev;
                               long  next;
                      unsigned char  type;     /* element type = 141 */
                      unsigned char  color;
                               char  num_axis;
                               char  num_points;
                              float  xPt,
                                     yPt,
                                     radius,
                                     arc_start,
                                     arc_end;
                                               }  ARC, *ARCPTR;

/* this structure is also used for the freelist object.  the element
   type for this is 1 & no name is stored. */
typedef struct  obj_element {short int len;
                             long  prev;
                             long  next;
                    unsigned char  type;  /* element type = 61 */
                    unsigned char  flags; /* status flags       */
                             long  head;  /* top of element list */
                             long  tail;  /* bot of element list */
                             char  name;  /* NULL terminated string */
                                               }  CADOBJECT, *OBJECTPTR;
        /* flags bit 0 = hide flag
                 bit 1 = open flag
                 bit 2 = scaled object */
#define HIDDEN_OBJ 1
#define OPENED_OBJ 2
#define SCALED_OBJ 4
// color flags
#define HIDDEN_ELE 0x80   // 8th bit
#define THICK_LINE 0x40   // 7th bit

/* Object Transformation Matrix Element */
typedef struct  otm_element {short int len;
                             long  prev;
                             long  next;
                    unsigned char  type;  /* element type = 63 */
                             char  dummy;
                             float PLLx,PLLy,
                                   PURx,PURy,
                                   OPscale,
                                   OLLx,OLLy,
                                   OURx,OURy;
                                               }  OTMele, *OTMPTR;


typedef struct select_mode_data {
                long Ip;
                 int Type;
                char *ObjName;
                long ObjIp;
                 int ier;
                              } SELECT_MODE_DATA;

// define standard color values for 256 color mode

#define   C_BLACK       0
#define RGB_BLACK		RGB(  0,  0,  0) 
#define   C_DARKRED     1
#define RGB_DARKRED     RGB(128,  0,  0) 
#define   C_DARKGREEN   2
#define RGB_DARKGREEN   RGB(  0,128,  0) 
#define   C_DARKYELLOW  3
#define RGB_DARKYELLOW  RGB(128,128,  0) 
#define   C_DARKBLUE    4
#define RGB_DARKBLUE    RGB(  0,128,128) 
#define   C_DARKMAGENTA 5
#define RGB_DARKMAGENTA RGB(128,  0,128) 
#define   C_DARKCYAN    6
#define RGB_DARKCYAN    RGB(  0,128,128) 
#define   C_GRAY1       7
#define RGB_GRAY1       RGB(192,192,192) 
#define   C_MONEYGREEN  8
#define RGB_MONEYGREEN  RGB(192,220,192) 
#define   C_SKYBLUE     9
#define RGB_SKYBLUE     RGB(166,202,240) 
#define   C_CREAM       10 
#define RGB_CREAM       RGB(255,251,240) 
#define   C_BROWN       11 
#define RGB_BROWN       RGB(218,157, 84) 
#define   C_RED			13 
#define RGB_RED         RGB(255,  0,  0) 
#define   C_WHITE       19 
#define RGB_WHITE       RGB(255,255,255) 

#define  CAD_OBJECT			61
#define  CAD_LINE				101
#define  CAD_POLYLINE		110
#define  CAD_TEXT				121
#define  CAD_ARC				131
#define  CAD_DIMEN_LINE 150
#define  CAD_DIMEN_POLYLINE 151
#define  C_ANY_LINE 200
#define  C_HIGHLIGHT_SEGMENTS 1

#define MaxOpenObjects 21
#define MAX_BUFFER_REC 20

class CCadBuffer
{
   friend class CCad;
// Construction
public:
	CCadBuffer (int size = 10000);   // standard constructor
	virtual ~CCadBuffer();

	void	ClearBuffer();
	void	ImageInfo (float *X1,float *Y1,float *X2,float *Y2,float *Sc, int SizeOpt);
	void	CadCaptureOn();
	void	CadCaptureOff();
	void	LoadRec(int rec);
	long	GetCadStor(int len);
	long	StoreIt(void *pObjBuf, int len);
	void	StoreLine(int num, float X[], float Y[], char Type[]);
	void	StorePolyLine(float X[], float Y[], int num);

	// element methods
	void	InitElementLoop(long *Ip);
	void	GetLastElementAdded(long *Ep);
	void	GetEMp(long ip, void **Emp);
	void	UnlinkElement(long i);
	void	NextElement (long *Pointer);
	void	C_Element_Rect ( long ip, float* xmin, float* ymin, float* xmax, float* ymax );
	void	C_EMnMx(long ip);
	void	DrawElement(long ip);
	void	C_DrawPolyL(LINE *Ep);
	void	C_PolyL(int Num, float *Pts, int closed = 1, int numAxis = 2);
	void	C_Circle (float x, float y, float r, float start, float end);
	void	CheckSnap(UINT settings, float *Xorg, float *Yorg);
	void	CheckSnapObj(const char *Name);
	void	Snap(long ip);
	void	C_SearchStart(long *ip);
	int		CheckObject (long ip, const char *ObjName, int option);
	void	C_LocEle (long *Pointer,int *Type,char *ObjName,float X1,float Y1,int *ier);
	void	C_SelOptions (const char *ObjName, int option);


	// object methods
	void	C_ObjSiz( long iP );
	int		C_FindOpenObj(long ip);
	void	C_UpdateOpenObj(int i);
	void	ObjectDraw(long ip);
	void	C_Obj_Set_Current( long cadObjPtr, void *pEp );
	void	C_ObjectOpen( char *ObjName, long *Pointer);
	void	C_ObjectClose(char *ObjName);
	void	C_ObjectCreat(char *name, long *ip);
	void	C_ObjFind(char *ObjName, long *Pointer, int TreeWalk);

private:  // internal routines
	int		Name_Matches( char *name, char *ObjName );

   // keep these in the same order because the active DW CB
   // points to the same data in the initialize cad routine

public:
          int LastRec,     // last record in CadStor virtual file
              Len,         // size of buffer
              dirty,
              capture,
              swap_handle; // file handle to swap file
    short int *buffer;
    short int *buffer_rec[MAX_BUFFER_REC];
         char swap_path[32];// swap file pathname
         long OpenObjects[21][3];  // open object list
          int ActiveObject,// object in list that all elements are linked to
              LastObject;  // last open object in list
		 long SearchStart;  // used by cad command to select elements
		  int SearchOption;
		char  C_flag1;

	// Max/Min boundries of plot image (world coors)
	float	Xmax;
	float	Ymax;
	float	Xmin;
	float	Ymin;

	float	m_MaxSnap;

	float   C_Xf,    // X/Y from coor of line selection was closest too.
            C_Yf,
            C_Xt,    // X/Y to coor of line selection was closest too.
            C_Yt,
            C_X1,    // Xcoor of point selection took place
            C_Y1,    // Ycoor  "   "       "
            C_PDist, // perp dist to the selected line/edge.
            C_XTempPt,
            C_YTempPt;

	CCad *	m_pCad;  // Cad object buffer is currently attached to

};

class CCadData
{
   friend class CCad;
   friend class CCadView;
// Construction
public:
	CCadData();   // standard constructor
	virtual ~CCadData();
	int		getPixelX (float Xdist);
	int		getPixelY (float Ydist);
	float   PixelToXUnits (int i3);
	float   PixelToYUnits (int i3);
	void	C_Plot2(float Xval, float Yval, int Ip);
	void	C_Plot (float Xval, float Yval, int Ip);
	int		inwindow (float x, float y);
protected:
	void	C_RelPlt(float RELX,float RELY,int IPEN); 
public:
	void	drawSymbol(void *aEp, const char *Text);
	void	drawArrow(float Xf, float Yf, float Xt, float Yt, float Len, float Wid);
	void	DrawDimenLine(void *aObjBuf);

//protected:
          int LLVPx,
              LLVPy,  // lower left coors of viewport
              URVPx,
              URVPy;  // upper right  "    "    "
        float URwinX,
              URwinY,   /* upper right coors of window */
              LLwinX,
              LLwinY;   /* lower left    "   "    "    */
        float VPscaleX,
              VPscaleY;
        float CrosHairX,
              CrosHairY;
        float RefPtX,
              RefPtY;
        float LastX,
              LastY;
         void *pMultiSelectList;
        float CrosHairStep;
	short int ICx,ICy;   // save last plotted pixel location



protected:
	CCad *	m_pCad;  // Cad object buffer is currently attached to

};

//      Pixel Mode Functions

#define GPIX_SET  0   //this will draw (no OR) with the set pen color
#define GPIX_OR   1   //this will draw OR with color that is the pen inverse
#define GPIX_XOR  2   //this will draw XOR with color that is the pen inverse
#define GPIX_NOT  3   //this will draw OR with color that is the screen inverse

class CDC;

class CCadDC
{
friend class CCadBuffer;
friend class CCadData;
friend class CCad;
// Construction
public:
	CCadDC();   // standard constructor
   virtual ~CCadDC();
   void     setColors (int FG, int BG);
   int      getForegroundColor( void );
   int      getBackgroundColor( void );
   int      setForegroundColor( int color );
   int      setBackgroundColor( int color ); 
   void     setDC(CDC *pDC); 
   CDC*     getDC();
   void     setPixelMode( int Mode );
   void     paintBackground(RECT *rect);
   void     drawThickLine( int xFrom, int yFrom, int xTo, int yTo ); 
   void     drawLine( int xFrom, int yFrom, int xTo, int yTo ); 
	void	drawPolygon( POINT *points, int numPoints );

protected:
   CDC      *m_pDC;
   HPEN     m_thinPen;
   HPEN     m_thickPen;
   HBRUSH   m_Brush;
   BOOL     m_graphicsOn;
   int      m_FGcolor;
   int      m_BGcolor;
   BOOL		m_bThickPenOn;
};
 
class CRect;

class CCad
{
// Construction
   friend class CCadView;
   friend class CCadData;
   friend class CCadBuffer;
public:
	CCad();   // standard constructor
   virtual ~CCad();
   int      Initialize(HWND hWnd);
   void     SetViewPort(CRect* Rect);
   void     GetViewPort(CRect* Rect);
   void     ReDraw();
   void     Zoom (const char *iOpt);
   void     UpdateZoomStack();
   void     SetWindow (float LLx,float LLy,float URx,float URy);
   void     GetWindow (float *LLx,float *LLy,float *URx,float *URy);
   void     ScaleWindowToViewport();
	void    LoadDIF(const char *FileName);
	void	ImportDXF (const char *filename);

   void     LineClipWindow (POINT_2D Pt1, POINT_2D Pt2, int Type);
   void     drawLine (float X1, 
					  float Y1,
					  float X2,
					  float Y2,
					  int Type,
					  BOOL bStoreInCadBuffer = TRUE);
	void	C_Symbol (float Xt,float Yt,float HITE,const char *Text,float THETA,int NCHARS);
	void    drawMarker (int iopt, float X, float Y);
	void    Reset();
	void    ClearBuffer();
	void	SetActiveColor(int colorIndex);
	void	DimenSettings(float textSize, float markSize, int markType, int textOrient);
	int		DimenLine(float Xf, float Yf, float Xt, float Yt);

   // panning function
protected:
	void     Pan(float fDeltaX, float fDeltaY);

public:
   	void     PanUp(float factor);
	void     PanLeft(float factor);
	void     PanDown(float factor);
	void     PanRight(float factor);

   // temporary method to set this object as the active cad object
   // returns the previously activated cad
   CCad*    Activate(); 

   // for now this data elements have to be pointers
   // because so much of the software uses them
   // when a window is made the active cad window
   // it's buffer and data pointers need to be set
   // in the cad object
   // this is necessary because the plotting routines
   // now use the cad objects directly
   // if it wasn't done, the plotting would be done
   // with the incorrect cad data for the active window

   CCadBuffer*	GetCadBuffer() { return m_pCadBuffer; }
   CCadData*	GetCadData() { return m_pCadData; }
   //CAD_3D_DATA* GetCadData3D() { return m_pCadData3D; }

   void SetCadBuffer(CCadBuffer* pCadBuffer);
   void SetCadData(CCadData* pCadData);
   //void SetCadData3D(CAD_3D_DATA* pCadData3D) { m_pCadData3D = pCadData3D; }

   CCadBuffer*	m_pCadBuffer;
   CCadData*	m_pCadData;
   //CAD_3D_DATA* m_pCadData3D;
   
   // functions to convert class data to a structure pointer
/*
   CAD_BUFFER* GetCadBuffer() { return (CAD_BUFFER*) &m_CB.LastRec; }
   CAD_DATA* GetCadData() { return (CAD_DATA *) &m_CD.LLVPx; }
*/

	FPGON	m_ActFPgon; // polygon fill defaults
	float	m_DimTextSize;	// Hieght of dimension line characters,  >0 = user units, <0 = fixed size.
	float	m_DimMarkSize;	// Size of dimension marks, >0=user units, <0=fixed size.
	int		m_DimOrient;	// Orientation of dimension chars, 1 = parallel, 2 = perpendicular.
	int		m_DimMarkType;	// Type of dimension marks, 1=arrow, 2=slash.
   
//protected:  commented for conversion only
   HWND        m_hWnd;
   CCadDC      m_cadDC;
   int         m_Xpixels;
   int         m_Ypixels;
   int         m_CharW;
   int         m_CharH;    // determine pixel hieght for font character
   int         m_Xunits;
   int         m_Yunits;
   float       m_ZoomStack[4][5];
   int         m_zs;
   static BOOL m_bSystemInitialized; // once for all instances
   BOOL        m_bInitialized; // for this instance

   BOOL        IsInitialized() { return m_bInitialized; }

   void Line(float x1, float y1, float x2, float y2, int type);
};


class CCadRubberBand
{
// Construction
public:
	CCadRubberBand ();   // standard constructor
   virtual ~CCadRubberBand();
   BOOL     isOn();
   void     Start(CCad *pCad,float x, float y, int type);
   void     Stop();
   void     Move(float x, float y);
   void     Draw();
protected:
   CCad *	m_pCad;
   float    m_X1,m_Y1;
   float    m_StartX,m_StartY;
   int      m_Type;
   BOOL     m_On;
   BOOL     m_done;
   long     m_dragIp;
};

class CCadPointer
{
	friend class CCadView;
public:
	int SetType(int type);
	void Hide();
	void Move(HWND Wnd, int x, int y);
	void DisplayXY(HWND Wnd, int iopt, float X1, float Y1);
	void Show();
	CCadPointer(CCad *pCad = NULL);
	virtual ~CCadPointer();

protected:
	void DrawCrossHair();
	CCad *	m_pCad;
	int		m_Type;
	float	m_LastCHx;
	float	m_LastCHy;
};

// MFC Cad GUI classes  ********************************************************

#define ID_ZOOM_ALL                     40012
#define ID_ZOOM_WINDOW                  40013
#define ID_ZOOM_PREV                    40014
#define ID_ZOOM_REDRAW                  40015
#define ID_REFER_PT                     40018


// define CAD window flags values  (bits 9-16)
#define ZOOM_WINDOW                  512
#define ZOOM_2ND_POINT              1024
#define SELECT_MODE                 2048
#define MULTI_SELECT_MODE           4096
#define MULTI_SELECT_MODE_SUSPENDED 8192
#define RDPT_MODE                   16384

#define KEYBOARD_ONLY_INPUT 1  // bit 0 is only one on
#define COMMAND_INPUT 3  // bits 0 & 1  on
#define RDPOINT_INPUT 5  // bits 0 & 2  on

/*

  C_InputFlag   - flag that defines the default input mode.
                = 0, Keyboard & CmdHWin are both active,  mouse moves
                     highlight bar in CmdHWin.
                = 1, Keyboard input only, no mouse used.
                = 2, Keyboard & mouse click, mouse limited to screen
                     region defined by application program.
                = 3, Keyboard & mouse click, mouse will be limited to
                     to window passed to C_Init_KBinput.
                = 4, List Box mode.  CmdHWin is used to display the list
                     & the mouse controls highlight bar.  Keyboard entry
                     only occurs if last list item = "$KB$" & then only
                     if the item is selected.
                =10, combined RdCmd & RdPt, mouse free to roam entire screen.
*/


// CRdEntry window

class CRdEntry : public CEdit
{
// Construction
public:
	CRdEntry();

// Attributes
public:
//   CCadFrame   *pFrame;
   CCadView    *m_pView;
   int         (*m_CallBackProc)(CCadView *pView, char *buf);

// Operations
public:
   int   Start(CCadView *pView, char *buf, void *kbentry_proc);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRdEntry)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PostNcDestroy();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRdEntry();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRdEntry)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};




//  CCadFrame class  ******************************************************

#include "\VSSource\inserts\AppFrames.h"


class CCadFrame : public CAppFrame
{
protected: // create from serialization only
	CCadFrame();
	DECLARE_DYNCREATE(CCadFrame)

// Attributes
public:
   CToolBar     m_CadToolBar;
   CToolBar    *m_CadToolBar2;
   CDialogBar  *m_CadDlgBar;
   CComboBox   *m_ObjSelBox;
   CDialogBar  *m_PromptDlgBar;

// Operations
public:
   BOOL     PromptMessage(char *buf);
   int      StartRdPoint(CCadView *pView, char *buf, void *select_rdpt_proc);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCadFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCadFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//protected:
   HWND     m_PromptWnd;
   char     m_PreviousMessagePrompt[132];

   HWND     m_RdPointWnd;
   CRdEntry *m_RdPointField;
   char     m_RdPtBuf[132];
   
   HWND     m_XYMonitorWnd;
   BOOL     m_TempRef;
   BOOL     m_LenFlag;
   float    m_XTempPt;
   float    m_YTempPt;

// Generated message map functions
protected:
	//{{AFX_MSG(CCadFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
   afx_msg void OnCadUtils();
	DECLARE_MESSAGE_MAP()
};

// global CCadFrame access functions 
extern "C" {

BOOL MW_PromptMessage(char *buf);
BOOL MW_PromptString(UINT nID);
BOOL MW_PromptSubString(UINT nIDS, int subitem);
char *MW_GetPromptString(UINT nID);
BOOL MW_GetPromptSubString(UINT, int, char *);
char *MW_GetPrevPromptMessage(void);
void MW_SetPromptWindow(HWND Prompt_hWnd);
void MW_SetRdPtField(HWND Prompt_hWnd);
HWND MW_GetRdPtField(void);
void MW_SetRdPointBuf(char *buf);
void MW_GetRdPtValue(char *buf);
void MW_ClearRdPtValue(void);
void MW_HiliteRdPtField(void);

int C_DecPoint (char *buf, float *x, float *y);

}

// define bit flag usage in m_InputFlag
#define KB_ACTIVE       1
#define MENU_ACTIVE     2
#define RDPT_ACTIVE     4
#define DIALOG_ACTIVE   8
#define MOUSE_ACTIVE    16
#define OLD_RDPT_ACTIVE 32


// CAD pointer equipment & option flags.
//              bit 0 = 1 if a mouse is present
//              bit 1 = 1 use cross hairs instead of mouse ICON
#define MOUSE     1
#define CROSSHptr 2

#define C_SNAP_ON   1
#define C_GRID_ON   2
#define C_GRID_SHOW 4
#define C_SNAP_DISABLED 8

#define ID_SNAP_ON                      40016
#define ID_SNAP_OFF                     40017

#define IDC_ADD_CURSOR                  137

#define IDM_CAD_UTILS_START             40066
#define IDM_CAD_LN_PTTOPT               40067
#define IDM_CAD_LN_PTANGLE              40068
#define IDM_CAD_LN_PTSLOPE              40069
#define IDM_CAD_LN_PARLN                40070
#define IDM_CAD_LN_PARMULTI             40071
#define IDM_CAD_LN_PERP                 40072
#define IDM_CAD_LN_HORIZ                40073
#define IDM_CAD_LN_VERT                 40074
#define IDM_CAD_LN_ARROWSI              40075
#define IDM_CAD_LN_ARROWSDO             40076
#define IDM_CAD_BRK_PT                  40077
#define IDM_CAD_BRK_LINE                40078
#define IDM_CAD_TRIM_POINT              40079
#define IDM_CAD_TRIM_LINE               40080
#define IDM_CAD_TRIM_MULTILN            40081
#define IDM_CAD_POLYGON_ADD             40082
#define IDM_CAD_POLYGON_CHG             40083
#define IDM_CAD_CIRCLE_ADD              40084
#define IDM_CAD_MOVEELE                 40085
#define IDM_CAD_OPTIONS                 40086
#define IDM_CAD_EXTENDLN                40087
#define IDM_CAD_POLYGON_AREA            40088
#define IDM_CAD_CHGCOLOR                40089
#define IDM_CAD_ADDTEXT                 40090
#define IDM_CAD_CLOSE                   40091
#define IDM_CAD_UTILS_END               40092


class CCadView : public CScrollView
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CCadView)
 	CDC	*m_pClientDC;

	HWND	m_XYPointWnd;

	CCadPointer *	m_pCadPointer;

// Attributes
public:
	CCadView();
	CCad m_Cad;

// Operations
public:

	UINT     m_flags;
	UINT     m_InputFlag;
	UINT     m_InputMode;

	unsigned short m_CadFlags;  // bit field flag variable.
                                   //   1 = highlight individual section of 110 and
                                   //       segmented line.  Used var. in CadSys.h
	unsigned short m_HighLightColor;

	// there is a 32 pixel window range when the mouse movement coordinate
	// display are frozen - RB
	BOOL     m_PixWindowMode;
	CPoint   m_prevPoint;
	UINT     m_PointSnap;

	int		m_ActiveLineType;

	float    x1,y1;      // work variables used by process_zoom
	// View cursor info
	HCURSOR m_Cursor;    // currently active mouse cursor handle
	UINT    m_CursorID;  // resource ID of active cursor   

	CCadRubberBand m_RubberBand;

	void	process_zoom(CPoint point);
	void	setCadDC(CDC *pDC);
	UINT	SetCursorType(UINT nID);
	void	RelativeToAbsoluteCoors(float *X, float *Y);
	int		SelectElement (SELECT_MODE_DATA *smd, void *select_mode_proc);
	int		HighLightElement(long ip);
	int		GetHighLightColor();
	int		SetHighLightColor(int newColor);
	void	SetCadFlags(unsigned short option);
	void	ResetCadFlags(unsigned short option);


	void	ResetCadBuffer();
   // virtual functions that deal with the Device Context
   virtual CDC	 *GetClientDC();
   virtual void ReleaseClientDC();

	void SetXYMonitorWnd(HWND hWnd);
	void DisplayXY (int iopt, float X1, float Y1);

   int      (*m_DblClickProc)(CCadView *pView, char *buf);
   int      (*m_LeftClickProc)(CCadView *pView, char *buf);
   int      (*m_MiddleClickProc)(CCadView *pView, char *buf);
   int      (*m_RightClickProc)(CCadView *pView, char *buf);
	int		(*m_SelectModeProc)(CCadView *pView, SELECT_MODE_DATA *Msg);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCadView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual void OnInitialUpdate();
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
    virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetLineType( void );
	virtual ~CCadView();
	virtual void MeasureScrollSize();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCadView)
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnZoomAll();
	afx_msg void OnZoomRedraw();
	afx_msg void OnZoomWindow();
    afx_msg void OnReferPt();
    afx_msg void OnZoomIn();
	afx_msg void OnSnapFunction(UINT nID);
	afx_msg void OnSnapUpdate(CCmdUI* pCmdUI);
	afx_msg void OnCadUtilsMenuProc(UINT nID);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CCadCtrl window

class CCadCtrl : public CStatic
{
// Construction
public:
	CCadCtrl();

	CCad	m_Cad;

// Attributes
public:
   COLORREF GetTextColor() const;
   COLORREF GetBackgroundColor() const;
   void AttachToDialog(CDialog *, UINT id, UINT promptId);
   CCadRubberBand m_RubberBand;

// Operations
public:
   void SetTextColor(COLORREF clrText);
   void SetBackgroundColor(COLORREF clrBackground);

   BOOL PromptMessage(char *buf);
   int  StartRdPoint(char *buf, void *select_rdpt_proc);

   int(*m_DblClickProc)(CCadCtrl *pCtrl, char *buf);
   int(*m_LeftClickProc)(CCadCtrl *pCtrl, char *buf);
   int(*m_MiddleClickProc)(CCadCtrl *pCtrl, char *buf);
   int(*m_RightClickProc)(CCadCtrl *pCtrl, char *buf);
   int(*m_SelectModeProc)(CCadCtrl *pCtrl, SELECT_MODE_DATA *Msg);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCadCtrl)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	//}}AFX_VIRTUAL

// Overridables
public:
protected:
	CCadPointer *	m_pCadPointer;

// Implementation
public:
	virtual ~CCadCtrl();
	float    x1, y1;      // work variables used by RdPoint process

private:
	UINT    m_flags;
	UINT    m_PointSnap;
   COLORREF m_clrText;           // Text color
   COLORREF m_clrBackground;     // Background color
   CBrush*  m_pbrBackground;     // Brush object for holding background brush
   CWnd*    m_pPromptWnd;
   char     m_PreviousMessagePrompt[132];

	// Generated message map functions
protected:
	//{{AFX_MSG(CCadCtrl)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	void SnapOn();
	void SnapOff();
};

/////////////////////////////////////////////////////////////////////////////



#endif //__CCAD_H_