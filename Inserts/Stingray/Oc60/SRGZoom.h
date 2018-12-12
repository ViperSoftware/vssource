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
//@doc SRGZoom
//@module SRGZoom.h | SRGZoom header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SRGZoom.h: interface for the SRGZoom class
//
/////////////////////////////////////////////////////////////////

#if !defined(AFX_SRGZOOM_H_INCLUDED_)
#define AFX_SRGZOOM_H_INCLUDED_

#include "SRGDat.h"	// Added by ClassView
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000



/////////////////////////////
// AutoDuck tag block for SRGZoom 
//@doc SRGZoom

//@mfunc void  | SRGZoom | SetMinY | Initializes the minimum Y value 
//@parm double  | v | New minimum Y value 

//@mfunc double  | SRGZoom | GetMinY | Retrieves the minimum Y value

//@mfunc void  | SRGZoom | SetMaxY | Initializes the maximum Y value 
//@parm double  | v | New maximum Y value

//@mfunc double  | SRGZoom | GetMaxY | Retrieves the maximum Y value 

//@mfunc void  | SRGZoom | SetMinX | Initializes the minimum X value 
//@parm double  | v | New minimum X value  

//@mfunc double  | SRGZoom | GetMinX | Retrieves the minimum X value 

//@mfunc void  | SRGZoom | SetMaxX | Initializes the maximum X value 
//@parm double  | v | New maximum X value 

//@mfunc double  | SRGZoom | GetMaxX | Retrieves the maximum X value 

//@mfunc void  | SRGZoom | SetMinZ | Initializes the minimum Z value 
//@parm double  | v | New minimum Z value 

//@mfunc double  | SRGZoom | GetMinZ | Retrieves the minimum Z value 

//@mfunc void  | SRGZoom | SetMaxZ | Initializes the maximum Z value 
//@parm double  | v | New maximum Z value 

//@mfunc double  | SRGZoom | GetMaxZ | Retrieves the maximum Z value 

//@mfunc void  | SRGZoom | SetYZoom | Sets the Y zoom semaphore 
//@parm BOOL  | v | TRUE if the Y zoom values are to be used, FALSE if they should be ignored

//@mfunc BOOL  | SRGZoom | GetYZoom | Retrieves the Y zoom semaphore 

//@mfunc void  | SRGZoom | SetXZoom | Sets the X zoom semaphore 
//@parm BOOL  | v | TRUE if the X zoom values are to be used, FALSE if they should be ignored

//@mfunc BOOL  | SRGZoom | GetXZoom | Retrieves the X zoom semaphore 

//@mfunc void  | SRGZoom | SetZZoom | Sets the Z zoom semaphore 
//@parm BOOL  | v | TRUE if the Z zoom values are to be used, FALSE if they should be ignored

//@mfunc BOOL  | SRGZoom | GetZZoom | Retrieves the Z zoom semaphore 

//@mfunc void  | SRGZoom | SetMinGroup | Initializes the minimum group in scope 
//@parm int  | v | New minimum group 

//@mfunc int  | SRGZoom | GetMinGroup | Retrieves the minimum group in scope 

//@mfunc void  | SRGZoom | SetMaxGroup | Initializes the maximum group in scope 
//@parm int  | v | New maximum group 

//@mfunc int  | SRGZoom | GetMaxGroup | Retrieves the maximum group in scope 

//@mfunc void  | SRGZoom | SetMinIndex | Initializes the minimum index in scope 
//@parm int  | v | New minimum index 

//@mfunc int  | SRGZoom | GetMinIndex | Retrieves the minimum index in scope 

//@mfunc void  | SRGZoom | SetMaxIndex | Initializes the maximum index in scope 
//@parm int  | v | New maximum index

//@mfunc int  | SRGZoom | GetMaxIndex | Retrieves the maximum index in scope 

//@mdata double  | SRGZoom | m_dMinY | Minimum Y value for the current zoom

//@mdata double  | SRGZoom | m_dMaxY | Maximum Y value for the current zoom

//@mdata double  | SRGZoom | m_dMinX | Minimum X value for the current zoom

//@mdata double  | SRGZoom | m_dMaxX | Maximum X value for the current zoom

//@mdata double  | SRGZoom | m_dMinZ | Minimum Z value for the current zoom 

//@mdata double  | SRGZoom | m_dMaxZ | Maximum Z value for the current zoom

//@mdata BOOL  | SRGZoom | m_bYZoom | TRUE if the Y values are to be used, FALSE if the Y values are ignored

//@doc SRGZoom
//@mdata BOOL  | SRGZoom | m_bXZoom | TRUE if the X values are to be used, FALSE if the X values are ignored

//@doc SRGZoom
//@mdata BOOL  | SRGZoom | m_bZZoom | TRUE if the Z values are to be used, FALSE if the Z values are ignored

//@doc SRGZoom
//@mdata int  | SRGZoom | m_nMinGroup | Minimum group number in scope

//@doc SRGZoom
//@mdata int  | SRGZoom | m_nMaxGroup | Maximum group number in scope

//@doc SRGZoom
//@mdata int  | SRGZoom | m_nMinIndex | Minimum index number in scope

//@doc SRGZoom
//@mdata int  | SRGZoom | m_nMaxIndex | Maximum index number in scope

// adinsert AutoDuck insertion point for SRGZoom 
//$head Utility classes
//$level 1

//@doc SRGZoom 
//@topic SRGZoom Class Overview |
//The SRGZoom class keeps zoom levels for the SRGraphView and SRGScrollView classes. 
//It is used to implement a full zoom-in and zoom-out system.

//@class The SRGZoom class keeps zoom levels for the SRGraphView and SRGScrollView classes. 
//It is used to implement a full zoom-in and zoom-out system.
//@base public | CObject
class SRGZoom : public CObject  
{
public:
	void SetScaleZ(CScale v){m_ScaleZ=v;}
	CScale GetScaleZ(){return m_ScaleZ;}
	void SetScaleY(CScale v){m_ScaleY=v;}
	CScale GetScaleY(){return m_ScaleY;}
	void SetScaleX(CScale v){m_ScaleX=v;}
	CScale GetScaleX(){return m_ScaleX;}
	void SetDisplayIndex(int v){m_nDisplayIndex=v;}
	int GetDisplayIndex(){return m_nDisplayIndex;}
	void SetGraph(SRGraph * v){m_pGraph=v;}
	SRGraph * GetGraph(){return m_pGraph;}
	//@cmember
	/* Default constructor*/
	SRGZoom();
	//@cmember
	/* Destructor*/
	~SRGZoom();
	//@cmember
	/* Initializes the minimum Y value*/
	void SetMinY(double v){m_dMinY=v;}
	//@cmember
	/* Retrieves the minimum Y value*/
	double GetMinY(){return m_dMinY;}
	//@cmember
	/* Initializes the maximum Y value*/
	void SetMaxY(double v){m_dMaxY=v;}
	//@cmember
	/* Retrieves the maximum Y value*/
	double GetMaxY(){return m_dMaxY;}
	//@cmember
	/* Initializes the minimum X value*/
	void SetMinX(double v){m_dMinX=v;}
	//@cmember
	/* Retrieves the minimum X value*/
	double GetMinX(){return m_dMinX;}
	//@cmember
	/* Initializes the maximum X value*/
	void SetMaxX(double v){m_dMaxX=v;}
	//@cmember
	/* Retrieves the maximum X value*/
	double GetMaxX(){return m_dMaxX;}
	//@cmember
	/* Initializes the minimum Z value*/
	void SetMinZ(double v){m_dMinZ=v;}
	//@cmember
	/* Retrieves the minimum Z value*/
	double GetMinZ(){return m_dMinZ;}
	//@cmember
	/* Initializes the maximum Z value*/
	void SetMaxZ(double v){m_dMaxZ=v;}
	//@cmember
	/* Retrieves the maximum Z value*/
	double GetMaxZ(){return m_dMaxZ;}
	//@cmember
	/* Initializes the Y zoom level semaphore*/
	void SetYZoom(BOOL v){m_bYZoom=v;}
	//@cmember
	/* Retrieves the Y zoom level semaphore*/
	BOOL GetYZoom(){return m_bYZoom;}
	//@cmember
	/* Initializes the X zoom level semaphore*/
	void SetXZoom(BOOL v){m_bXZoom=v;}
	//@cmember
	/* Retrieves the X zoom level semaphore*/
	BOOL GetXZoom(){return m_bXZoom;}
	//@cmember
	/* Initializes the Z zoom level semaphore*/
	void SetZZoom(BOOL v){m_bZZoom=v;}
	//@cmember
	/* Retrieves the Z zoom level semaphore*/
	BOOL GetZZoom(){return m_bZZoom;}
	//@cmember
	/* Sets the minimum group in scope*/
	void SetMinGroup(int v){m_nMinGroup=v;}
	//@cmember
	/* Retrieves the minimum group in scope*/
	int GetMinGroup(){return m_nMinGroup;}
	//@cmember
	/* Sets the minimum group in scope*/
	void SetMaxGroup(int v){m_nMaxGroup=v;}
	//@cmember
	/* Retrieves the maximum group in scope*/
	int GetMaxGroup(){return m_nMaxGroup;}
	//@cmember
	/* Sets the minimum index in scope*/
	void SetMinIndex(int v){m_nMinIndex=v;}
	//@cmember
	/* Retrieves the minimum index in scope*/
	int GetMinIndex(){return m_nMinIndex;}
	//@cmember
	/* Sets the maximum index in scope*/
	void SetMaxIndex(int v){m_nMaxIndex=v;}
	//@cmember
	/* Retrieves the maximum index in scope*/
	int GetMaxIndex(){return m_nMaxIndex;}

protected:
	CScale m_ScaleZ;
	CScale m_ScaleY;
	CScale m_ScaleX;
	int m_nDisplayIndex;
	SRGraph * m_pGraph;
		//@cmember
		/* Minimum Y value*/
	double m_dMinY;
		//@cmember
		/* Maximum Y value*/
	double m_dMaxY;
		//@cmember
		/* Minimum X value*/
	double m_dMinX;
		//@cmember
		/* Maximum X value	*/
	double m_dMaxX;
		//@cmember
		/* Minimum Z value*/
	double m_dMinZ;
		//@cmember
		/* Maximum Z value*/
	double m_dMaxZ;
		//@cmember
		/* Y zoom level semaphore*/
	BOOL m_bYZoom;
		//@cmember
		/* X zoom level semaphore*/
	BOOL m_bXZoom;
		//@cmember
		/* Z zoom level semaphore*/
	BOOL m_bZZoom;
		//@cmember
		/* Minimum group in scope*/
	int m_nMinGroup;
		//@cmember
		/*  Maximum group in scope*/
	int m_nMaxGroup;
		//@cmember
		/*  Minimum index in scope*/
	int m_nMinIndex;
		//@cmember
		/*  Maximum index in scope*/
	int m_nMaxIndex;
};





#endif // !defined(AFX_SRGZOOM_H_INCLUDED_)

