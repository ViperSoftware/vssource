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
//@doc SRSwatchButton
//@module SwtchBtn.h | SRSwatchButton header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SwtchBtn.h: interface of the SRSwatchButton class
//
/////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGSWATCHBUTTON_H__
#define __SRGSWATCHBUTTON_H__

/////////////////////////////
// AutoDuck tag block for SRSwatchButton 

//@doc SRSwatchButton

//@mdata COLORREF  | SRSwatchButton | m_RGBSwatchColor | RGB color of the button -- must be set directly

// adinsert AutoDuck insertion point for SRSwatchButton 
//$head Utility classes
//$level 1

//@topic SRSwatchButton Class Overview |
//This class is an extension of the simple buton class which is used to display a "swatch" of color on a dialog. 
//The button has a variable which may be set to an RGB color combination. This then indicates a chosen color value.

//@doc SRSwatchButton 
//@class Simple button control that paints itself the solid color specified in the 
//m_RGBSwatchColor member variable<nl>
//SRSwatchButton is used in dialogs to display a current color selection.<nl>
//Typically, the developer will provide a handler for this control's "been clicked" message 
//which invokes the standard color selection dialog.
//@base public | CButton
class SRSwatchButton : public CButton
{
// Construction
public:
		//@cmember
		/* Color of the button -- must be set directly*/
	COLORREF m_RGBSwatchColor;
		//@cmember
		/* Default constructor*/
	SRSwatchButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRSwatchButton)
	public:
		//@cmember
		/* Standard function called to draw the item onto the dialog or parent window.*/
		virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
		//@cmember
		/* Destructor*/
	virtual ~SRSwatchButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(SRSwatchButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////


#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


