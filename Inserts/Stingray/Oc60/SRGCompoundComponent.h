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
//@doc SRGCompoundComponent
//@module SRGCompoundComponent.h | SRGCompoundComponent header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGCompoundComponent.h: Interface for the SRGCompoundComponent class.
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#if !defined(_SRGCOMPOUNDCOMPONENT_H_INCLUDED_)
#define _SRGCOMPOUNDCOMPONENT_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block for SRGCompoundComponent 
//
//@doc SRGCompoundComponent 

//@mfunc CObList * | SRGCompoundComponent  | GetComponentList | Returns a pointer to the 
//component list owned by this compound component

//@mfunc BOOL  | SRGCompoundComponent  | GetDrawLocalForeground | Returns TRUE if the local 
//foreground is to be drawn
//@devnote Aside from the drawing actions performed by the various subcomponents of this object, 
//drawing local to this object may be performed. 
//Such drawing may be placed behind or in front of the graphics produced by the subcomponents 
//by altering the state of the foreground order flag.
//@see <mf SRGCompoundComponent::GetForegroundOrder> <mf SRGCompoundComponent::GetForegroundOrder>

//@mfunc BOOL  | SRGCompoundComponent  | GetForegroundOrder | Returns the foreground order flag -- used 
//to determine if the local foreground is to be drawn before or after the subcomponent list 

//@mfunc void  | SRGCompoundComponent  | SetDrawLocalForeground | Sets that flag that signifies that 
//the local foreground should be drawn
//@parm BOOL  | b | TRUE to draw the local foreground

//@mfunc void  | SRGCompoundComponent  | SetForegroundOrder | Sets the order of the foreground drawing
//@parm BOOL  | b | FALSE to draw the foreground before the subcomponent list, TRUE to draw the foreground after

//@mfunc void  | SRGCompoundComponent  | SetDrawPanel | Sets the flag signifying that the 
//panel is to be drawn for this compound object
//@parm BOOL  | b | TRUE (default) to draw the panel, FALSE to ignore

//@mfunc BOOL  | SRGCompoundComponent  | GetDrawPanel | Returns the draw panel flag

//@mfunc BOOL  | SRGCompoundComponent  | GetAutoPanel | Returns the auto panel sizing flag

//@mfunc void  | SRGCompoundComponent  | SetTwoPass | Sets the two-pass flag
//@parm BOOL  | b | TRUE (default) to do a two pass draw with pre-display sizing

//@mfunc BOOL  | SRGCompoundComponent  | GetTwoPass | Returns the two-pass flag

//@mfunc void  | SRGCompoundComponent | SetTopLevel | Sets the top-level flag
//@parm BOOL  | v | If TRUE this component is considered to be a top-level or master component

//@mfunc BOOL  | SRGCompoundComponent | GetTopLevel | Returns the top-level flag


//@mdata BOOL  | SRGCompoundComponent | m_bTwoPass | TRUE if this component performs pre-draw sizing functions

//@mdata BOOL  | SRGCompoundComponent | m_bDrawLocalForeground | Draw local foreground flag

//@doc SRGCompoundComponent
//@mdata BOOL  | SRGCompoundComponent | m_bForegroundOrder | Foreground drawing order flag<nl>
//If FALSE, the foreground is drawn before the subcomponent list.<nl>
//If TRUE, the foreground is drawn after.

//@mdata BOOL  | SRGCompoundComponent | m_bAutoPanel | TRUE if automatic panel sizing from the sizes of subcomponents is available

//@mdata BOOL  | SRGCompoundComponent | m_bDrawPanel | TRUE if the panel is filled, and borders and shadows are drawn as normal

//@mdata CRect  | SRGCompoundComponent | m_DisplayRect | Data display rectangle

//@mdata BOOL  | SRGCompoundComponent | m_bTopLevel | True if this is a top level component 
//(ie. if it can be displayed directly from the graph's component list)

//@mdata CObList  | SRGCompoundComponent | m_ComponentList | The local subcomponent list

// adinsert
//$head Compound components
//$level 1

//@doc SRGCompoundComponent 
//@class This class allows a component to manage its own local subcomponent list. 
//This means that a list of subcomponents may now be considered as a single entity.<nl>
//The compound component manages its own subcomponents in much the same way as an 
//SRGraph user application would manage the component list in the SRGraph class.<nl>
//It is responsible for the placement, sizing, and other housekeeping tasks. 
//A two pass system is implemented that handles pre-draw sizing and final drawing processes. 
//These tasks are performed by the <mf SRGCompoundComponent::PassOneSetup>, <mf SRGCompoundComponent::PassOneCleanup>, 
//<mf SRGCompoundComponent::PassTwoSetup> and <mf SRGCompoundComponent::PassTwoCleanup> functions 
//that are called to allow this housekeeping to be carried out by a derived class.
//@base public | SRGraphComponent
class SRGCompoundComponent : public SRGraphComponent  
{
public:
	virtual BOOL IsCompound();
	virtual void SetSignificantChange();
	//@cmember
	/* Serializes this component*/
	virtual void Serialize(CArchive& ar);
	//@cmember
	/* Sets the top-level flag*/
	virtual void SetTopLevel(BOOL v){m_bTopLevel=v;}
	//@cmember
	/* Returns the top-level flag*/
	virtual BOOL GetTopLevel(){return m_bTopLevel;}
	//@cmember
	/* Returns a nested component*/
	virtual SRGraphComponent * GetComponent(int nComponent,UINT Type,int *pCurrentComponent=0);
	//@cmember
	/* Returns a pointer to the local subcomponent list*/
	virtual CObList * GetComponentList(){return &m_ComponentList;}
	//@cmember
	/* Sets the parent of this and all subcomponent objects*/
	virtual void SetParent(SRGraph *pG);
	//@cmember
	/* Adds a component to the local list*/
	virtual POSITION AddComponent(SRGraphComponent * pC);
	//@cmember
	/* Returns the draw local foreground flag*/
	virtual BOOL GetDrawLocalForeground(){return m_bDrawLocalForeground;}
	//@cmember
	/* Returns the foreground drawing order flag*/
	virtual BOOL GetForegroundOrder(){return m_bForegroundOrder;}
	//@cmember
	/* Sets the draw local foreground flag*/
	virtual void SetDrawLocalForeground(BOOL b){m_bDrawLocalForeground=b;}
	//@cmember
	/* Sets the foreground drawing order flag*/
	virtual void SetForegroundOrder(BOOL b){m_bForegroundOrder=b;}
	//@cmember
	/* Draws this compound component*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);
	//@cmember
	/* Sets the draw panel flag*/
	virtual void SetDrawPanel(BOOL b=TRUE){m_bDrawPanel=b;}
	//@cmember
	/* Returns the draw panel flag*/
	virtual BOOL GetDrawPanel(){return m_bDrawPanel;}
	//@cmember
	/* Returns the automatic panel sizing flag*/
	virtual BOOL GetAutoPanel(){return m_bAutoPanel;}
	//@cmember
	/* Sets the two pass processing flag*/
	virtual void SetTwoPass(BOOL b=TRUE){m_bTwoPass=b;}
	//@cmember
	/* Returns the two pass processing flag*/
	virtual BOOL GetTwoPass(){return m_bTwoPass;}

	//@cmember
	/* Constructor*/
	SRGCompoundComponent();

	DECLARE_SERIAL(SRGCompoundComponent);

	//@cmember
	/* Destructor*/
	virtual ~SRGCompoundComponent();



protected:
	//@cmember
	/* Draws subcomponents that have been deferred*/
	virtual void DrawDeferred();
	//@cmember
	/* Pass one setup -- override to perform sensible tasks*/
	virtual void PassOneSetup();
	//@cmember
	/* Pass one setup -- override to perform sensible tasks*/
	virtual void PassTwoSetup();
	//@cmember
	/* Pass one cleanup -- override to perform sensible tasks*/
	virtual void PassOneCleanup();
	//@cmember
	/* Pass two cleanup -- override to perform sensible tasks*/
	virtual void PassTwoCleanup();
	//@cmember
	/* Custom panel sizing -- override to perform sensible tasks*/
	virtual void CalcAutoPanel();
	//@cmember
	/* Draw local foreground graphics -- override to perform sensible tasks */
	virtual void DrawLocalForeground();
	//@cmember
	/* Draws all items in the subcomponent list*/
	virtual void DrawForeground();

	//@cmember
	/* The subcomponent list*/
	CObList m_ComponentList;
	//@cmember
	/* Top level or master component flag*/
	BOOL m_bTopLevel;
	//@cmember
	/* Two pass processing flag*/
	BOOL m_bTwoPass;
	//@cmember
	/* Draw local foreground flag*/
	BOOL m_bDrawLocalForeground;
	//@cmember
	/* Foreground drawing order flag*/
	BOOL m_bForegroundOrder;
	//@cmember
	/* Automatic panel resizing flag*/
	BOOL m_bAutoPanel;
	//@cmember
	/* Panel drawing flag*/
	BOOL m_bDrawPanel;
	//@cmember
	/* Data display rectangle*/
	CRect m_DisplayRect;
};


#endif // !defined(_SRGCOMPOUNDCOMPONENT_H_INCLUDED_)
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

