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
//@doc SRGraphRect
//@module SRGraphRect.h|  definition of the graph rectangle classes<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGraphRect.h: definition of the graph component rectangle classes
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHRECT__
#define __SRGRAPHRECT__

/////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphRect

//@doc SRGraphRect

//@mfunc  | SRGraphRect | SRGraphRect | Constructor with device independent coordinates
//@parm double | left | Left side coordinate
//@parm double | topt | Top edge coordinate
//@parm double | right | Right side coordinate
//@parm double | bottom | Bottom edge coordinate

//@mfunc  | SRGraphRect | SRGraphRect | Default constructor

//@mfunc void | SRGraphRect | operator = | Assignment operator (overload #1)
//@parm SRGraphRect & | r | Reference to an existing SRGraphRect

//@mfunc void | SRGraphRect | operator = | Assignment operator (overload #2)
//@parm CRect & | r | Reference to a CRect object<nl>
//The edge coordinates are converted to doubles and stored in the equivalent variable in this SRGraphRect.

//@mfunc double | SRGraphRect | Width | Returns the width of the object
//@rdesc Right-Left
//@see <mf SRGraphRect::Height> 
 
//@mfunc double | SRGraphRect | Height | Returns the height of the object
//@rdesc Bottom-Top
//@see <mf SRGraphRect::Width>

//@mfunc void | SRGraphRect | Move | Shifts the rectangle by the x and y offsets provided
//@parm double | x | Value by which to move horizontally (may be negative)
//@parm double | y | Value by which to move vertically (may be negative)

//@mdata double | SRGraphRect | left | Left side coordinate

//@mdata double | SRGraphRect | top |  Top edge coordinate

//@mdata double | SRGraphRect | right |	 Right side coordinate

//@mdata double | SRGraphRect | bottom |  Bottom edge coordinate

//@mdata int  | SRGraphRect | m_nType |	Type of measurement used<nl>
//Values may be one of...<nl>
//0 = PIXELS<nl>
//1 = MILLIMETERS<nl>
//2 = INCHES<nl>
//3 = PERCENTAGE of available area

//@mdata CRect | SRGraphRect | m_LogRect | Used in the calculation of logical rectangles from device independent rectangles (private)

//@mdata SRGraph *  | SRGraphRect | m_pGraph | Pointer to the SRGraph object that manages the chart

// adinsert for SRGraphRect
//$head Component rectangle manager
//$level 1
/////////////////////////////////////////////////////////

//@doc SRGraphRect
//@class Device independent rectangle class
//@base public | CObject
class SRGraphRect : public CObject
{
//@access public data members
public:
	//@cmember
	/* Device independent coordinate for the left of the rectangle*/
	double left;
	//@cmember
	/* Device independent coordinate for the top of the rectangle*/
	double top;
	//@cmember
	/* Device independent coordinate for the right of the rectangle*/
	double right;
	//@cmember
	/* Device independent coordinate for the bottom of the rectangle*/
	double bottom;

	enum _MeasurementTypes {
		pixel,
		millimeter,
		inch,
		percentage
	} ;


//@access protected data members
protected:
	//@cmember
	/* Pointer to the parent graph*/
	SRGraph * m_pGraph;
	//@cmember
	/* Type of measurement used: 0=pixels, 1=millimeters, 2=inches, 3=percentage*/
	int  m_nType;

//@access private data members
private:	
	//@cmember
	/* CRect object for internal conversions and calculations*/
	CRect m_LogRect;



//@access public member functions
public:
	//@cmember
	/* Initializes the pointer to the owner graph*/
	virtual void SetGraph(SRGraph *pGraph);
	//@cmember
	/* Returns m_nType data member*/
	virtual int GetMeasurement();
	//@cmember
	/* Initializes m_nType data member*/
	virtual void SetMeasurement(int m);
	//@cmember
	/* Initializes the rectangle from a CRect*/
	virtual void SetRect(const CRect& r);
	//@cmember
	/* Initializes the rectangle with device independent coordinates*/
	virtual void SetRect(double l,double t,double r, double b);
	//@cmember
	/* Construction*/
	SRGraphRect(){left=top=right=bottom=(double)-1.0;m_nType=0;m_pGraph=NULL;}
	//@cmember
	/* Construction*/
	SRGraphRect(double l,double t,double r,double b){left=l; top=t; right=r; bottom=b;}
	//@cmember
	/* Construction*/
	SRGraphRect(CRect& r);


	//@cmember
	/* Calculates logical rectangle from device independent coordinates*/
	virtual CRect CalcCRect(CDC *pDC,CWnd *pCWnd=NULL);


	DECLARE_SERIAL(SRGraphRect);
	//@cmember
	/* Stores or retrieves information via a CArchive*/
	virtual void Serialize(CArchive& ar);


	//@cmember
	/* Assignment of data from an existing SRGraphRect object*/
	void operator =(const SRGraphRect& r){top=r.top;
										  left=r.left;
										  bottom=r.bottom; 
										  right=r.right; 
										  m_nType=r.m_nType;
										  m_pGraph=r.m_pGraph;}

	//@cmember
	/* Assignment of data from a CRect object*/
	void operator =(const CRect& r){top=(double)r.top; 
									left=(double)r.left; 
									bottom=(double)r.bottom; 
									right=(double)r.right;}

	//@cmember
	/* Test for equality of one SRGRect to another.*/
	BOOL operator ==(const SRGraphRect& r)
	{
		return (left==r.left &&
				right==r.right &&
				top==r.top &&
				bottom==r.bottom &&
				m_nType==m_nType);
	}

	//@cmember
	/* Returns the width of the rectangle*/
	double Width(){return right-left;}
	//@cmember
	/* Returns the height of the rectangle*/
	double Height(){return bottom-top;}
	//@cmember
	/* Displaces the rectangle*/
	void Move(double x, double y){left+=x; right+=x; top+=y; bottom+=y;}
	//@cmember
	/* Expands the rectangle*/
	void Grow(double x, double y);
	//@cmember
	/* Calculates device independent measurements*/
	void CRectToSRGRect(CRect& rect,CDC *pDC);

	//@cmember
	/* Calculates device independent measurements (special overload for percentage measuring system)*/
	virtual void CRectToSRGRect(CRect& rect,CDC *pDC,CWnd *pCWnd);

	//@todo Decide if I need this or not
	friend class SRGraphComponent;
};




#endif // __SRGRAPHRECT__


// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

