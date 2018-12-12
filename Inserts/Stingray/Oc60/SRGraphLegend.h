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
//@doc SRGraphLegend
//@module SRGComp.h|  definition of the graph legend class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGraphLegend.h: definition of the graph legend class
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHLEGEND__
#define __SRGRAPHLEGEND__

////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphLegend
//
// cmember tags only used for some data members

//@doc SRGraphLegend

//@mdata SRGDisplayBase * | SRGraphLegend | m_pDisplay | Pointer to a graph display component
//@rem When a legend finds itself immediately after a display in the component list, 
//it locks itself to it and displays legend information tailiored to that display type. 
//The locked legend will examine the scope of the graph display to find out 
//what range of data needs keys, etc.

//@mdata CRect | SRGraphLegend | m_LegendRect | Rectangle used to keep track of the automatically resized legend's extents

//@mdata SRGraphRect | SRGraphLegend | m_RectStore | Original extent
//@rem At draw time a legend may resize or move itself. The original rectangle of the legend 
//is stored here during draw cycles. The information is replaced after the draw is complete 
//so that the graph remains true to the requested template or setup data.

//@mdata int | SRGraphLegend | m_nIndexStep | Number of steps the index advances with each key (normally 1)

//@mdata int  | SRGraphLegend | m_nGroupStep | Number of steps the group advances with each key (normally 1)

//@mdata int  | SRGraphLegend | m_nKeyHeight | Stores the height of the key items between passes

//@mfunc double  | SRGraphLegend | GetKeySize | Retrieves the size of the graphic keys

//@mdata BOOL | SRGraphLegend | m_bKeepTop | Semaphore to prevent moving the vertical origin of the rectangle during automatic resizing
//@mdata BOOL | SRGraphLegend | m_bKeepLeft | Semaphore to prevent moving the left origin of the rectangle during automatic resizing

//@mdata BOOL | SRGraphLegend | m_bAutoSizeX | Semaphore to prevent changing the height of the rectangle during auto resizing
//@mdata BOOL | SRGraphLegend | m_bAutoSizeY | TRUE if the legend is to automatically extend its bottom boundary to contain the list
//@mdata BOOL | SRGraphLegend | m_bSizeForeground | Semaphore signifying a demand to recalculate the component size -- see <mf SRGraphLegend::DrawForeground>

//@mdata double | SRGraphLegend | m_dKeySize | Width of key data
//@devnote A key is the pattern or color filled box which accompanies the text in the legend panel. 
//Heights for keys are calculated according to the height of text used. Widths are decided by you or 
//the user via a template or explicit initialization of the m_dKeySize member.

//@mdata BOOL | SRGraphLegend | m_nKeyCount | Count of the number of keys currently in this legend.

//@mdata SRGraphLabelBlock  | SRGraphLegend | m_LegendLabels | List of text items used to annotate the legend keys


//adinsert
//$head Component classes
//$level 1


//@doc SRGraphLegend
//@class Handles painting of the legend panel and inherits font management from the SRGraphTitle class
//@base public | SRGraphTitle
class SRGraphLegend : public SRGraphTitle
{
//@access Protected data members
protected:
	//@cmember
	/* Number of steps the index advances with each key (normally 1)*/
	int m_nIndexStep;
	//@cmember
	/* Number of steps the group advances with each key (normally 1)*/
	int m_nGroupStep;
	//@cmember
	/* Stores the height of the key items between passes.*/
	int m_nKeyHeight;
	//@cmember
	/* Copy of the device independent rectangle stored so that the original settings can be restored after each draw cycle*/
	SRGraphRect m_RectStore;
	//cmember List of text items used to annotate the legend keys
	SRGraphLabelBlock m_LegendLabels;
	//@cmember
	/* Pointer to the SRGDisplayBase to which this legend has locked itself (do not alter)*/
	SRGDisplayBase * m_pDisplay;
	//@cmember
	/* Basic rectangle of the legend panel*/
	CRect m_LegendRect;
	//@cmember
	/* Semaphore to prevent moving the horizontal origin of the rectangle during auto resizing*/
	BOOL m_bKeepTop;
	//@cmember
	/* Semaphore to prevent moving the vertical origin of the rectangle during auto resizing*/
	BOOL m_bKeepLeft;
	//@cmember
	/* Semaphore to prevent changing the height of the rectangle during auto resizing*/
	BOOL m_bAutoSizeX;
	//@cmember
	/* TRUE if the legend is to automatically extend its bottom boundary to contain the list*/
	BOOL m_bAutoSizeY;
	//@cmember
	/* Semaphore signifying a demand to recalculate the component size -- see <mf SRGraphLegend::DrawForeground>*/
	BOOL m_bSizeForeground;
	//@cmember
	/* Width of key data*/
	double m_dKeySize;
	//@cmember
	/* Count of the number of keys currently in this legend.*/
	int m_nKeyCount;
	

//@access Protected member functions
protected:
	//@Cmember Draws text or recalculates the size of the component
	virtual void DrawForeground();
	//@cmember
	/* Draws legend keys onto the component*/
	virtual void DrawKey(CPoint topleft,CPoint bottomright, int index, int group, int CurrentKey);
	//@cmember
	/* Calculates size of graphic keys*/
	virtual int CalcKeySize();
	//@cmember
	/* Customization system for legend keys*/
	virtual void DrawCustomKey(CPoint topleft,CPoint bottomright,int group,int index,SRGraphStyle *ptrStyle);
	//@cmember
	/* Sets the group and index stepping interval for legends*/
	virtual void SetCustomLegendSteps();

//@access public member functions
public:
	//@cmember
	/* Sets default key size according to measurement mode*/
	virtual void SetSizeDefaults();
	//@cmember
	/* Calculates font size for the legend class*/
	virtual int CalcFontAutoSize();
#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Writes special legend parameters to a template file*/
	virtual void WriteSpecificParameters(CStdioFile *f);
	//@cmember
	/* Reads a legend line from a template file*/
	virtual int ReadTemplateLine(LPCTSTR line);
	//@cmember
	/* Writes the object's name to a template file*/
	virtual void WriteName(CStdioFile *file);
#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember
	/* Destructor*/
	virtual ~SRGraphLegend();
	//@cmember
	/* Initializes the size of graphic keys*/
	void SetKeySize(double keysize);
	//@cmember
	/* Retrieves the size of the graphic keys*/
	double GetKeySize(){return m_dKeySize;}
	//@cmember
	/* Initializes the auto-sizing flags*/
	virtual void SetAutoSize(int sizebits);
	//@cmember
	/* Overrides <mf SRGraphComponent::Draw> to enable automatic resizing*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);
	//@cmember
	/* Retrieves pertinent data from the parent <c SRGraph>*/
	virtual void GetParentContent();
	//@cmember
	/* Constructor*/
	SRGraphLegend();

	DECLARE_SERIAL(SRGraphLegend);
	//@cmember
	/* To store or retrieve information via a CArchive*/
	virtual void Serialize(CArchive& ar); 
};



#endif //__SRGRAPHLEGEND__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

