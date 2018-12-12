///////////////////////////////////////////////////////////////////////
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
//@doc SRGraphPosition
//@module SRGPosn.h | SRGraphPosition header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGPosn.h: Interface of the SRGraphPosition class
//
/////////////////////////////////////////////////////////////////


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHPOSITION__
#define __SRGRAPHPOSISION__

//////////////////////////////////////////////////////
//  Autoduck comment block for SRGraphPosition

//@doc SRGraphPosition

//@mdata int | SRGraphPosition | m_nGroup | Zero-based indicator of the group in which the data point is found
//@rem This is only valid if <mf SRGaphPosition::HasGroup> returns TRUE.<nl>
//Retrieve this value using <mf SRGraphPosition::GetGroup>.

//@mdata int | SRGraphPosition | m_nIndex |	Zero-based index giving data point's position within its group
//@rem This is only valid if <mf SRGaphPosition::HasIndex> returns TRUE.<nl>
//Retrieve this value using <mf SRGraphPosition::GetIndex>.


//@mdata double | SRGraphPosition | m_dValueY | Y value relative to the current graph axis at which the point was placed
//@rem This is only valid if <mf SRGaphPosition::HasValueY> returns TRUE.<nl>
//Retrieve this value using <mf SRGraphPosition::GetValueY>.


//@mdata double | SRGraphPosition | m_dValueX | X value relative to the current graph axis at which the point was placed
//@rem This is only valid if <mf SRGaphPosition::HasValueX> returns TRUE.<nl>
//Retrieve this value using <mf SRGraphPosition::GetValueX>.


//@mdata SRGraph *| SRGraphPosition | m_pParent | Pointer to the graph being interrogated 


//@mdata DWORD | SRGraphPosition | m_dwFlags | Set of bitwise flags which communicate information to and from this class<nl>
//CX_POSITION_MASK			0x0000000f	Bitmask for separating the position code<nl>
//<nl>
//CX_POSITION_NONE			0x00000000	<nl>
//CX_POSITION_SINGLE		0x00000001	 Position is for a single component --  m_pSubject points to an SRGraphComponent<nl>
//CX_POSITION_LIST			0x00000002	 For a list of components, m_pSubject points to a CPtrList containing multiple SRGraphComponent pointers<nl>
//<nl>
//CX_POSITION_VALUEY		0x00000010	 The Y value is known.<nl>
//CX_POSITION_VALUEX		0x00000020	 The X value is known.<nl>
//CX_POSITION_GROUP			0x00000040	 The group is known.	 
//CX_POSITION_INDEX			0x00000080	 The index is known.<nl>
//<nl>
//CX_POSITION_SELECT_MASK	0x000f0000						   <nl>
//CX_POSITION_SELECT_H		0x00000000	 Selection is horizontal (classic).<nl>
//CX_POSITION_SELECT_V		0x00010000	 Selection is vertical (yx).<nl>
//CX_POSITION_SELECT_B		0x00020000	 Selection is both (x,y scatter).<nl>
//CX_POSITION_SELECT_C		0x00030000	 Selection is circular (webs).<nl>


//@mdata void *| SRGraphPosition | m_pSubject | Points to the subject of the interrogation
//@rem This may be either a pointer to an SRGraphComponent object or a pointer to a CPtrList 
//containing, in turn, pointers to multiple SRGraphComponent objects. 
//To ascertain the position type (ie. single or multiple SRGDisplayBase hits), call GetPosType first. 
//If the position is single (CX_POSITION_SINGLE), then use GetComponent() to retrieve the pointer. 
//If it is multiple, you must use GetList() to retrieve the CPtrList pointer. 
//Effectively, these routines simply return the m_pSubject pointer cast to the correct type. 
//However some error checking and verification are done first so it is best to use the routines provided.

//@mdata POSITION | SRGraphPosition | m_pos | Currently reserved and unused

//@mdata CWnd *| SRGraphPosition | m_pCWnd | Pointer to the window displaying the graph -- used in position calculations

//@mdata CPoint | SRGraphPosition | m_Point | Mouse position or the X,Y coordinates to 
//test for hits, positions and values

//@mfunc virtual void  | SRGraphPosition | SetGroup | Sets the group
//@parm int  | g | Group of data item of interest 

//@mfunc virtual int  | SRGraphPosition | GetGroup | Returns the group -- do not rely on this data unless <mf SRGraphPosition::HasGroup> returns TRUE

//@mfunc virtual void  | SRGraphPosition | SetIndex | Sets the index
//@parm int  | i | Index of the data item of interest

//@mfunc virtual int  | SRGraphPosition | GetIndex | Returns the index -- do not rely on this data unless <mf SRGraphPosition::HasIndex> returns TRUE

//@mfunc virtual void  | SRGraphPosition | SetValueX | Sets the X value
//@parm double  | d | New X value 

//@mfunc virtual void  | SRGraphPosition | SetValueY | Sets the Y value
//@parm double  | d | New Y value

//@mfunc virtual double  | SRGraphPosition | GetValueX | Retrieves the calculated X value -- do not rely on this data unless <mf SRGraphPosition::HasValueX> returns TRUE

//@mfunc virtual double  | SRGraphPosition | GetValueY | Retrieves the calculated Y value -- do not rely on this data unless <mf SRGraphPosition::HasValueY> returns TRUE


//adinsert
//$head Chart data position
//$level 1

//////////////////////////////////////////////////////

//@doc SRGraphPosition
//@class SRGraphPosition manages the passing of position information from the graph to the user. 
//It is used primarily in data dragging to define which data item in the graph data structure 
//is associated with the positon of the mouse pointer.
//@base public | CObject
//@rem To use graph positions, you simply call the constructor with a pointer to the graph 
//being interrogated and a mouse pointer position. 
//The SRGraphPosition system then scans the graph structures taking into account the type of 
//graph display and fills its member variables with pertinent information. 
//The calling function or class then interrogates the position to find out what type of 
//information is available. For example, calling SRGraphPosition::HasValueX() will 
//return TRUE if the value currently stored in the m_dValueX data member was obtained on the 
//last scan. If this routine returns FALSE, the data in that member will be undefined and unreliable.<nl>
//All data members are protected and should be accessed using the correct methods.
class SRGraphPosition : public CObject
{
//@access Protected data members
protected:
	  //@cmember
	  /* Calculated group in which the point was found*/
	  int m_nGroup;
	  //@cmember
	  /* Calculated index of the point within its group*/
	  int m_nIndex;
	  //@cmember
	  /* The Y value relative to the current graph axis at which the point was placed*/
	  double m_dValueY;
	  //@cmember
	  /* The X value relative to the current graph axis at which the point was placed*/
	  double m_dValueX;
	  //@cmember
	  /* Pointer to the graph being interrogated*/
	  SRGraph *m_pParent;
	  //@cmember
	  /* Bitwise flags*/
	  DWORD m_dwFlags;
	  //@cmember
	  /* Pointer to either the graph component (SRGrapDisplay) or a list of components in which the point was found*/
	  void *m_pSubject;
	  //@cmember
	  /* Type of position for selection purposes*/
	  POSITION m_pos;
	  //@cmember
	  /* Pointer to the CWnd being used to draw the graph*/
	  CWnd *m_pCWnd;
	  //@cmember
	  /* Point at which calculations are to be made*/
	  CPoint m_Point;

//@access Public member functions
public:
	//@cmember
	/* Sets the position for hit testing*/
	virtual void SetGraphPosition(CPoint p);
	//@cmember
	/* Returns TRUE if a Y scale value has been calculated*/
	virtual BOOL HasValueY();
	//@cmember
	/* Returns TRUE if an X scale value has been calculated*/
	virtual BOOL HasValueX();
	//@cmember
	/* Returns TRUE if an index has been calculated*/
	virtual BOOL HasIndex();
	//@cmember
	/* Returns TRUE if an group has been calculated*/
	virtual BOOL HasGroup();
	//@cmember
	/* Allows the addition of a user-defined calculation routine for your own graph types*/
	virtual void CalcUserDisplayPosition(SRGDisplayBase *pD);
	//@cmember
	/* Calculates the data from the given display depending on the graph type*/
	virtual void CalcDisplayPosition(SRGDisplayBase *pD);
	//@cmember
	/* Calculates the positions and values with reference to the indexed display in the list*/
	virtual void CalcPos(int nDisplay=0);
	//@cmember
	/* Returns the position type*/
	virtual DWORD GetPosType();
	//@cmember,mfunc
	/* Returns the type of selection made (ie. horizontal, vertical, etc.)*/
	virtual DWORD GetSelectionType(){return m_dwFlags & CX_POSITION_SELECT_MASK;}
	//@cmember
	/* Sets the type of position to use as a basis for the calculations*/
	virtual void SetPosType(DWORD postype);
	//@cmember
	/* Constructor*/
	SRGraphPosition();
	//@cmember
	/* Constructor with parameters*/
	SRGraphPosition(SRGraph *pGraph,CPoint point,CWnd *pWnd);
	//@cmember
	/* Destructor*/
	virtual ~SRGraphPosition();
	//@cmember
	/* Sets the group*/
	virtual void SetGroup(int g){m_nGroup=g;}
	//@cmember
	/* Returns the group -- do not rely on this data unless <mf SRGraphPosition::HasGroup> returns TRUE*/
	virtual int GetGroup(){return m_nGroup;}
	//@cmember
	/* Sets the index*/
	virtual void SetIndex(int i){m_nIndex=i;}
	//@cmember
	/* Returns the index -- do not rely on this data unless <mf SRGraphPosition::HasIndex> returns TRUE*/
	virtual int GetIndex(){return m_nIndex;}
	//@cmember
	/* Sets the X value*/
	virtual void SetValueX(double d){m_dValueX=d;}
	//@cmember
	/* Sets the Y value*/
	virtual void SetValueY(double d){m_dValueY=d;}
	//@cmember
	/* Retrieves the calculated X value -- do not rely on this data unless <mf SRGraphPosition::HasValueX> returns TRUE*/
	virtual double GetValueX(){return m_dValueX;}
	//@cmember
	/* Retrieves the calculated Y value -- do not rely on this data unless <mf SRGraphPosition::HasValueY> returns TRUE*/
	virtual double GetValueY(){return m_dValueY;}
	//@cmember
	/* Returns a pointer to the list of items in which the point is found*/
	virtual CPtrList *GetList();
	//@cmember
	/* Returns a pointer to the unique display component in which the point has been found*/
	virtual SRGraphComponent *GetComponent();
};


#endif //__SRGRAPHPOSITION__

// Reset DLL declaration context

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR



