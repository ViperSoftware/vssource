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
//@doc SRGraphFeedback
//@module SRGFbck.h | SRGraphFeedback header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGFbck.h: Declaration of the SRGraphFeedback class
//
////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __FEEDBACK__
#define __FEEDBACK__


//@doc SRGraphFeedback

//@mdata CRgn | SRGraphFeedback | m_polygonRegion | Polygonal region which outlines the data

//@mdata CRect | SRGraphFeedback | m_BoundingRect | Bounding rectangle for the polygonal region (not currently used)

//@mdata int | SRGraphFeedback | m_nGroup | Group to which the data defined by the region belongs

//@mdata int | SRGraphFeedback | m_nIndex | Index in which the data defined by the region is stored

//@mdata SRGraph * | SRGraphFeedback | m_pParentGraph | Pointer to the SRGraph object that owns this feedback object

//@doc SRGraphFeedback
//@mdata int  | SRGraphFeedback | m_nRadius | NEW for 6.0. Feedback may now use a point and radius combination to define the hot spot. This variable defines the radius from the point stored in m_FeedbackPoint which specfies the hot area.

//@doc SRGraphFeedback
//@mdata CPoint  | SRGraphFeedback | m_FeedbackPoint | NEW 6.0 Feedback may now use a point / radius combination to define the hot spot for feedback. This variable stores the point upon which the hot spot is centered.

//@doc SRGraphFeedback
//@mdata CRect  | SRGraphFeedback | m_rFeedbackRect | NEW 6.0 Feedback may now use a rectangular area defined in this variable to create the hot spot for feedback as an alternative to the older region based system.

//@doc SRGraphFeedback
//@mdata int  | SRGraphFeedback | m_nFeedbackType | NEW 6.0 The type of feedback used. This mfay be one of Point, Rectangle or Region.<nl>




// adinsert

//$head Chart feedback
//$level 1

//@doc SRGraphFeedback
//@class A list of SRGraphFeedback objects stores "hot" areas which can be used to 
//associate a screen area with the data displayed in it.<nl>
//When a graphic object like a bar or graph data point is drawn, the outline of that 
//object is stored in an SRGraphFeedback object as a CRgn (GDI region object) along
//with the group and index of the associated data item.<nl>
//An hit-test routine can then use this list to determine which data item, if any, is 
//associated with the screen location of the mouse cursor.
//@base public | CObject
class SRGraphFeedback : public CObject
{
public:
	//@cmember
	/* Returns the index of the data item attached to this feedback object*/
	int GetnIndex();
	//@cmember
	/* Returns the group of the data item attached to this feedback object*/
	virtual int GetnGroup();
	//@cmember
	/* Constructor*/
	SRGraphFeedback();
	//@cmember
	/* Destructor*/
	virtual ~SRGraphFeedback();
	//@cmember
	/* Constructor with initialization*/
	SRGraphFeedback(LPPOINT points,int PointCount,int group,int index,SRGraph *Parent);
	//@cmember
	/* Performs hit testing for the coordinates supplied in X and Y*/
	BOOL ptInFeedback(int x,int y);

// Attributes
public:
	//@cmember
	/* Creates a feedback item that uses a point and radius combination instead of the normal region */
	SRGraphFeedback(CPoint p,int nRadius, int group, int index, SRGraph *pParent);
	//@cmember
	/* Creates a feedback item that uses a rectangle instead of the normal region */
	SRGraphFeedback(CRect r,int group,int index, SRGraph *pParent);
	//@cmember
	/* Region which defines the on-screen feedback area*/
	CRgn *m_polygonRegion;
	//@cmember
	/* Calculated bounding rectangle of the region*/
	CRect m_BoundingRect;
	//@cmember
	/* Group associated with this hot area*/
	int m_nGroup;
	//@cmember
	/* Index associated with this hot area*/
	int m_nIndex;
	//@cmember
	/* Pointer to the SRGraph object which owns this object*/
	SRGraph * m_pParentGraph;
protected:
	//@cmember
	/* NEW 6.0 Feedback radius from a point */
	int m_nRadius;
	//@cmember
	/* NEW 6.0 feedback may use points as well as regions */
	CPoint m_FeedbackPoint;
	//@cmember
	/* NEW 6.0 Feedback may use rectangles as well as regions */
	CRect m_rFeedbackRect;
	//@cmember
	/* The type of feedback used, point, rectangle or region */
	int m_nFeedbackType;
};


#endif
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

