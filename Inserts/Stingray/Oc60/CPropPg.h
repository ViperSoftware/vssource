//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes.
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////
//@doc
//@module CPropPg.h | definitions for Chart Explorer property page classes
//Copyright <cp>Stingray Software 1996.<nl>
//Written by Bob Powell ( www.stingray.com )
//
// using cmember tags only for these dialog classes
/////////////////////////////////////////////////////////////
//
// CPropPg.h : header file
//
//////////////////////////////////////////////////////////////

//$head The chart explorer
//$level 1
//adinsert

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGCOMPONENTPROPERTYPAGES_H__
#define __SRGCOMPONENTPROPERTYPAGES_H__

/////////////////////////////////////////////////////////////////////////////
// SRGCTypeAndPos dialog
//
/////////////////////////////
// AutoDuck tag block for SRGCTypeAndPos 


//@doc SRGCBorderStyle
//@mdata int   | SRGCBorderStyle | m_nBorderStyle | The border style

// adinsert AutoDuck insertion point for SRGCTypeAndPos 

//@topic SRGCTypeAndPos Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCTypeAndPos 
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to specify the position, measurement mode, and view angles 
//for the selected component
//@base public | CPropertyPage
class SRGCTypeAndPos : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCTypeAndPos)

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCTypeAndPos();
	//@cmember
	/* Destructor*/
	~SRGCTypeAndPos();

// Dialog Data
	//{{AFX_DATA(SRGCTypeAndPos)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE1 };
	//@cmember
	/* Position of left edge of component rectangle*/
	double	m_dLeft;
	//@cmember
	/* Position of top edge of component rectangle*/
	double	m_dTop;
	//@cmember
	/* Position of right edge of component rectangle*/
	double	m_dRight;
	//@cmember
	/* Position of bottom edge of component rectangle*/
	double	m_dBottom;
	//@cmember
	/* Measurement mode or units for position parameters*/
	int		m_nMeasurement;
	//@cmember
	/* Text naming the type of the selected component*/
	CString	m_strType;
	//@cmember
	/* Z viewing angle*/
	double	m_dZAngle;
	//@cmember
	/* X viewing angle*/
	double	m_dXAngle;
	//@cmember
	/* Y viewing angle*/
	double	m_dYAngle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCTypeAndPos)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCTypeAndPos)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////
// SRGCFillStyle dialog

//@topic SRGCFillStyle Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCFillStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to specify how the background of the selected component is filled
//@base public | CPropertyPage
class SRGCFillStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCFillStyle)

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCFillStyle();
	//@cmember
	/* Destructor*/
	~SRGCFillStyle();

// Dialog Data
	//{{AFX_DATA(SRGCFillStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE2 };
	//@cmember
	/* Displays and selects final color for shade (vignette)*/
	SRSwatchButton	m_SwatchB;
	//@cmember
	/* Displays and selects solid color or initial color for shade (vignette)*/
	SRSwatchButton	m_SwatchA;
	//@cmember
	/* Index of radio button for selected type of fill*/
	int		m_nFillStyle;
	//@cmember
	/* Angle for Angled shade*/
	double	m_dAngle;
	//@cmember
	/* Name of resource file for resource image fill*/
	CString	m_strResourceName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCFillStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	virtual BOOL OnInitDialog();

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCFillStyle)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};




/////////////////////////////////////////////////////////////////////////////
// SRGCBorderStyle dialog

//@topic SRGCBorderStyle Class Overview |
//This class is a simple property page that is used in the chart explorer.

//@doc SRGCBorderStyle
//@mdata int   | SRGCBorderStyle | m_nBorderStyle | Holds the radio button data.

//@doc SRGCBorderStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to choose a border style for the selected component
//@base public | CPropertyPage
class SRGCBorderStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCBorderStyle)

// Construction
public:
	//@cmember,mfunc
	/* Constructor*/
	SRGCBorderStyle();
	//@cmember,mfunc
	/* Destructor*/
	~SRGCBorderStyle();

// Dialog Data
	//{{AFX_DATA(SRGCBorderStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE3 };
	//@cmember
	/* Index of radio button for selected style*/
	int		m_nBorderStyle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCBorderStyle)
	protected:

	//@cmember,mfunc
	/* Standard dialog box data exchange */
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCBorderStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};




/////////////////////////////////////////////////////////////////////////////
// SRGCShadowStyle dialog

//@topic SRGCShadowStyle Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCShadowStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to choose a shadow style for the selected component
//@base public | CPropertyPage
class SRGCShadowStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCShadowStyle)

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCShadowStyle();
	//@cmember
	/* Destructor*/
	~SRGCShadowStyle();

// Dialog Data
	//{{AFX_DATA(SRGCShadowStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE4 };
	//@cmember
	/* Index of radio button for selected style*/
	int		m_nShadowStyle;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCShadowStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCShadowStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// SRGCFontStyle dialog

//@topic SRGCFontStyle Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCFontStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to choose a font style for the selected component
//@base public | CPropertyPage
class SRGCFontStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCFontStyle)

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCFontStyle();
	//@cmember
	/* Destructor*/
	~SRGCFontStyle();

// Dialog Data
	//{{AFX_DATA(SRGCFontStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE5 };
	//@cmember
	/* Displays and selects a color for the font*/
	SRSwatchButton	m_FontSwatch;
	//@cmember
	/* Face name for the font*/
	CString	m_strTypeFaceName;
	//@cmember
	/* Units for font size*/
	int		m_nPointsOrPixels;
	//@cmember
	/* Font size*/
	int		m_nPointSize;
	//@cmember
	/* Bold check box*/
	BOOL	m_bBoldFont;
	//@cmember
	/* Italic check box*/
	BOOL	m_bItalicFont;
	//@cmember
	/* Underline check box*/
	BOOL	m_bUnderlineFont;
	//@cmember
	/* Strikeout check box*/
	BOOL	m_bStrikeoutFont;
	//@cmember
	/* Index of radio button for selected justification (Left, Right, or Centered)*/
	int		m_nJustification;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCFontStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCFontStyle)
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////
// SRGCDisplayStyle dialog

//@topic SRGCDisplayStyle Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCDisplayStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to change to appearance of the graph in the display component
//@base public | CPropertyPage
class SRGCDisplayStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCDisplayStyle)

	//$NoJumps

// public data
public:
	//@cmember
	/* Current graph type*/
	DWORD m_dwGraphType;
	//@cmember
	/* Current axis type*/
	DWORD m_dwAxisType;
	//@cmember
	/* Current label type*/
	DWORD m_dwLabelType;

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCDisplayStyle();
	//@cmember
	/* Destructor*/
	~SRGCDisplayStyle();

	// Dialog Data
	//{{AFX_DATA(SRGCDisplayStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE6 };
	//@cmember
	/* List of available axis types*/
	CComboBox	m_AxisType;
	//@cmember
	/* List of available label types*/
	CComboBox	m_LabelType;
	//@cmember
	/* List of available graph types*/
	CComboBox	m_GraphType;
	//@cmember
	/* First group in scope*/
	int		m_nFirstGroup;
	//@cmember
	/* Last group in scope*/
	int		m_nLastGroup;
	//@cmember
	/* First index in scope*/
	int		m_nFirstIndex;
	//@cmember
	/* Last index in scope*/
	int		m_nLastIndex;
	//@cmember
	/* Log scale check box*/
	BOOL	m_bLogScale;
	//@cmember
	/* Always show zero check box*/
	BOOL	m_bAlwaysShowZero;
	//@cmember
	/* Show X labels check box*/
	BOOL	m_bShowXL;
	//@cmember
	/* Show Y labels check box*/
	BOOL	m_bShowYL;
	//@cmember
	/* Show Z labels check box*/
	BOOL	m_bShowZL;
	//@cmember
	/* Show X grid lines check box*/
	BOOL	m_bShowXG;
	//@cmember
	/* Show Y grid lines check box*/
	BOOL	m_bShowYG;
	//@cmember
	/* Show Z grid lines check box*/
	BOOL	m_bShowZG;
	//@cmember
	/* Show tick marks check box*/
	BOOL	m_bShowTicks;
	//@cmember
	/* Show grid on top check box*/
	BOOL	m_bGridOrder;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCDisplayStyle)
	public:
	//@cmember
	/* When leaving page, set current type DWORDS from combo box selections*/
	virtual BOOL OnKillActive();
	//@cmember
	/* When entering page, set combo box selections from current type DWORDS*/
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCDisplayStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};




/////////////////////////////////////////////////////////////////////////////
// SRGCLegendEdit dialog

//@topic SRGCLegendEdit Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCLegendEdit
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to change the appearance of the legend component
//@base public | CPropertyPage
class SRGCLegendEdit : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCLegendEdit)

// Construction
public:
	//@cmember
	/* Current key type*/
	DWORD m_dwKeyStyle;
	//@cmember
	/* Current legend type*/
	DWORD m_dwLegendStyle;

	//@cmember
	/* Constructor*/
	SRGCLegendEdit();
	//@cmember
	/* Destructor*/
	~SRGCLegendEdit();

// Dialog Data
	//{{AFX_DATA(SRGCLegendEdit)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE7 };
	//@cmember
	/* List of available key types*/
	CComboBox	m_KeyCombo;
	//@cmember
	/* List of available legend types*/
	CComboBox	m_LegendCombo;
	//@cmember
	/* First group in scope*/
	int		m_nFirstGroup;
	//@cmember
	/* Last group in scope*/
	int		m_nLastGroup;
	//@cmember
	/* First index in scope*/
	int		m_nFirstIndex;
	//@cmember
	/* Last index in scope*/
	int		m_nLastIndex;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCLegendEdit)
	public:
	//@cmember
	/* When leaving page, set current type DWORDS from combo box selections*/
	virtual BOOL OnKillActive();
	//@cmember
	/* When entering page, set combo box selections from current type DWORDS*/
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCLegendEdit)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////
// SRGCLabelStyle dialog

//@topic SRGCLabelStyle Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGCLabelStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to change the appearance of the label component
//@base public | CPropertyPage
class SRGCLabelStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGCLabelStyle)

// Construction
public:
	//@cmember
	/* Constructor*/
	SRGCLabelStyle();
	//@cmember
	/* Destructor*/
	~SRGCLabelStyle();

// Dialog Data
	//{{AFX_DATA(SRGCLabelStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE8 };
	//@cmember
	/* Orientation angle*/
	double	m_dOrientation;
	//@cmember
	/* X coordinate of screen position*/
	double	m_dXPos;
	//@cmember
	/* Y coordinate of screen position*/
	double	m_dYPos;
	//@cmember
	/* Index of radio button for selected alignment and rotation location*/
	int		m_nLocationPoint;
	//}}AFX_DATA

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGCLabelStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGCLabelStyle)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};




/////////////////////////////////////////////////////////////////////////////
// SRGObjStyle dialog

//@topic SRGObjStyle Class Overview |
//This class is a simple property page used in the chart explorer.


//@doc SRGCLabelStyle
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to change the appearance of the data objects in the graph
//@base public | CPropertyPage
class SRGObjStyle : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGObjStyle)

// Construction
public:
	//@cmember
	/* TRUE if the user selected a data list from the tree, FALSE if data item was selected*/
	BOOL m_bIsList;
	//@cmember
	/* Current frame style*/
	int m_nFrameStyle;
	//@cmember
	/* Current object style*/
	int m_nObjectStyle;

	//@cmember
	/* Constructor*/
	SRGObjStyle();
	//@cmember
	/* Destructor*/
	~SRGObjStyle();

// Dialog Data
	//{{AFX_DATA(SRGObjStyle)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE10 };
	//@cmember
	/* List of available frame styles*/
	CComboBox	m_FrameStyle;
	//@cmember
	/* List of available object styles*/
	CComboBox	m_ObjectStyle;
	//@cmember
	/* Displays and selects color for the frame*/
	SRSwatchButton	m_FrameColor;
	//@cmember
	/* Pen width used to draw the frame*/
	int		m_nFrameWidth;
	//@cmember
	/* Check to have setting apply to all data objects in the list (group)*/
	BOOL	m_bApplyToList;
	//@cmember
	/* Check to enable maximum size parameters*/
	BOOL	m_bUseMaxSize;
	//@cmember
	/* Maximum width for object*/
	double	m_dMaxWidth;
	//@cmember
	/* Maximum height for object*/
	double	m_dMaxHeight;
	//@cmember
	/* Maximum depth for object*/
	double	m_dMaxDepth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGObjStyle)
	public:
	//@cmember
	/* When leaving page, set current types from combo box selections*/
	virtual BOOL OnKillActive();
	//@cmember
	/* When entering page, set combo box selections from current types*/
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGObjStyle)
	//@cmember
	/* Handles color swatch button click -- displays color selection dialog*/
	afx_msg void OnIdcButton1();
	//@cmember
	/* Handles Choose Color button click -- displays color selection dialog*/
	afx_msg void OnIdcButton2();
	//@cmember
	/* Handles change in Use Max Dimensions check box*/
	afx_msg void OnIdcCheck2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



/////////////////////////////////////////////////////////////////////////////
// SRGInteriorEdit dialog

//@topic SRGInteriorEdit Class Overview |
//This class is a simple property page used in the chart explorer.

//@doc SRGInteriorEdit
//@class One of the property pages of Chart Explorer's editing dialog<nl>
//Allows the user to change the interior appearance of the data objects in the graph
//@base public | CPropertyPage
class SRGInteriorEdit : public CPropertyPage
{
	DECLARE_DYNCREATE(SRGInteriorEdit)

// Construction
public:
	//@cmember
	/* Current interior style*/
	int m_nInteriorStyle;
	//@cmember
	/* Constructor*/
	SRGInteriorEdit();
	//@cmember
	/* Destructor*/
	~SRGInteriorEdit();

// Dialog Data
	//{{AFX_DATA(SRGInteriorEdit)
	enum { IDD = SRG_IDD_COMPONENT_PROPPAGE11 };
	//@cmember
	/* List of available interior styles*/
	CComboBox	m_InteriorStyle;
	//@cmember
	/* Displays and selects the final color for shades (vignettes)*/
	SRSwatchButton	m_ColorB;
	//@cmember
	/* Displays and selects a solid color or the initial color for shades*/
	SRSwatchButton	m_ColorA;
	//@cmember
	/* Rotation angle for angled shades*/
	double	m_dAngle;
	//@cmember
	/* Resource file name or resource image fills*/
	CString	m_strResourceName;
	//@cmember
	/* Object name*/
	CString	m_strObjectName;
	//@cmember
	/* Check to stretch an resource image to fill the area, clear to tile*/
	BOOL	m_bStretch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(SRGInteriorEdit)
	public:
	//@cmember
	/* When leaving page, set current style from combo box selection*/
	virtual BOOL OnKillActive();
	//@cmember
	/* When entering page, set combo box selection from current style*/
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(SRGInteriorEdit)
	//@cmember
	/* Handles Choose Color 1 button click -- displays color selection dialog*/
	afx_msg void OnIdcButton3();
	//@cmember
	/* Handles Choose Color 2 button click -- displays color selection dialog*/
	afx_msg void OnIdcButton4();
	//@cmember
	/* Handles Color 1 swatch button click -- displays color selection dialog*/
	afx_msg void OnIdcButton1();
	//@cmember
	/* Handles Color 2 swatch button click -- displays color selection dialog*/
	afx_msg void OnIdcButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


#endif // __SRGCOMPONENTPROPERTYPAGES_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

