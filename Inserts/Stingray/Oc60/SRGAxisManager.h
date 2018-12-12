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
//@doc SRGAxisManager
//@module SRGAxisManager.h | SRGAxisManager header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGAxisManager.h: interface of the SRGAxisManager class
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#if !defined(_SRGAXISMANAGER_H_INCLUDED_)
#define _SRGAXISMANAGER_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block block for SRGAxisManager 

//@doc SRGAxisManager
//@mfunc void  | SRGAxisManager | SetNodeAdjust | Turns node adjustment on or off<nl>
//Node adjustments are made generally to label blocks that display groups or indices.<nl>
//A line graph that shows more than one index will have the first and 
//last indices shown on the left and right edges of the chart.<nl>
//A bar chart will have its first and last index markers at a 
//position equal to (DisplayWidth/GroupCount)/2 from either edge. 
//@parm BOOL  | b=TRUE | TRUE to turn node adjustment on (for use with line charts, etc.)

//@mfunc BOOL  | SRGAxisManager | GetNodeAdjust | Returns the node adjust flag<nl>
//For details see <mf SRGAxisManager::SetNodeAdjust>

//@mfunc void  | SRGAxisManager | SetStartPos | Sets the start position for the labels, 
//tick marks, and grid lines associated with this axis manager
//@parm CPoint  | ptStart | Logical coordinates of the start point


//@mfunc void  | SRGAxisManager | SetEndPos | Sets the end position for the labels, 
//tick marks, and grid lines associated with this axis manager
//@parm CPoint  | ptEnd | Logical coordinates of the end point


//@mfunc CPoint  | SRGAxisManager | GetStartPos | Returns the start position for all labels, 
//tick marks, and grid lines associated with this axis manager


//@mfunc CPoint  | SRGAxisManager | GetEndPos | Returns the end position for all labels, 
//tick marks, and grid lines associated with this axis manager

//@mdata BOOL  | SRGAxisManager | m_bNodeAdjust | TRUE if node adjustment should be made
//@see <mf SRGAxisManager::SetNodeAdjust>

//@mdata BOOL  | SRGAxisManager | m_bLabelsOK | TRUE if labels have been registered
//@see <mf SRGAxisManager::RegisterLabels>

//@mdata BOOL  | SRGAxisManager | m_bTicksOK | TRUE if tick marks have been registered
//@see <mf SRGAxisManager::RegisterTicks>

//@mdata BOOL  | SRGAxisManager | m_bGridsOK | TRUE if grid lines have been registered
//@see <mf SRGAxisManager::RegisterGrids>

//@mdata BOOL  | SRGAxisManager | m_bWatcherOK | TRUE if a data watcher has been registered
//@see <mf SRGAxisManager::RegisterWatcher>

//@mdata BOOL  | SRGAxisManager | m_bDisplayOK | TRUE if a display has been registered
//@see <mf SRGAxisManager::RegisterDisplay>

//@mdata BOOL  | SRGAxisManager | m_bTitleOK | TRUE when a title is registered

//@mdata CPoint  | SRGAxisManager | m_ptEnd | Defines the start position of the labels, 
//tick marks, and grid lines

//@mdata CPoint  | SRGAxisManager | m_ptStart | Defines the start position of the labels, 
//tick marks, and grid lines

// adinsert AutoDuck insertion point for SRGAxisManager 

//$head Compound components (sub components)
//$level 3

//@doc SRGAxisManager 
//@class The axis manager is a compound component used by <c SRGCompoundDisplay> to manage 
//one side of the chart axis area. The axis manager may hold up to six types of items. 
//These items are...<nl>
//	labels,<nl>
//	grid lines,<nl>
//	tick marks,<nl>
//	data watcher,<nl>
//	display,<nl>
//	title.<nl>
//These items are positioned and managed as subcomponents of the axis manager 
//which is, in turn, a subcomponent of the compound display.
//@base public | SRGCompoundComponent
class SRGAxisManager : public SRGCompoundComponent  
{
public:
	//@cmember
	/* Removes tick marks from the subcomponent list */
	virtual SRGTickMarks * UnregisterTicks(BOOL bDelete=FALSE);
	//@cmember
	/* Removes grid lines from the subcomponent list*/
	virtual SRGGridLines * UnregisterGrids(BOOL bDelete=FALSE);
	//@cmember
	/* Removes the data watcher from the subcomponent list*/
	virtual SRGDataWatcher * UnregisterWatcher(BOOL bDelete=FALSE);
	//@cmember
	/* Removes labels from the subcomponent list*/
	virtual SRGDecimalScale * UnregisterLabels(BOOL bDelete=FALSE);
	//@cmember
	/* Removes the display from the subcomponent list*/
	virtual SRGDisplayBase * UnregisterDisplay(BOOL bDelete=FALSE);
	//@cmember
	/* Removes the axis title label from the subcomponent list*/
	virtual SRGraphLabel * UnregisterTitle(BOOL bDelete=FALSE);
	//@cmember
	/* Serializes this object to the archive*/
	virtual void Serialize(CArchive &ar);
	//@cmember
	/* Returns the address of the grid line subcomponent*/
	virtual SRGGridLines * GetGrids();
	//@cmember
	/* Registers a grid line subcomponent*/
	virtual void RegisterGrids(SRGGridLines *pG);
	//@cmember
	/* Turns node adjustment on or off*/
	virtual void SetNodeAdjust(BOOL b=TRUE){m_bNodeAdjust=b;}
	//@cmember
	/*  Returns node adjustment status*/
	virtual BOOL GetNodeAdjust(){return m_bNodeAdjust;}
	//@cmember
	/* Specifies which side of the axis line the labels and tick marks are to be drawn*/
	virtual void SetLabelSide(BOOL b);
	//@cmember
	/* Sets the minimum numeric value used for the axis range*/
	virtual void SetMinValue(double d);
	//@cmember
	/* Sets the maximum numeric value used for the axis range*/
	virtual void SetMaxValue(double d);
	//@cmember
	/* Sets the scope of the axis manager and all the subcomponents*/
	virtual void SetScope(SRGScope s);
	//@cmember
	/* Returns the address of the data watcher subcomponent*/
	virtual SRGDataWatcher * GetWatcher();
	//@cmember
	/* Returns the address of the tick mark subcomponent*/
	virtual SRGTickMarks * GetTicks();
	//@cmember
	/* Returns the address of the label subcomponent*/
	virtual SRGDecimalScale * GetLabels();
	//@cmember
	/* Returns the address of the display subcomponent*/
	virtual SRGDisplayBase * GetDisplay();
	//@cmember
	/* Returns the address of the axis title label subcomponent*/
	virtual SRGraphLabel * GetTitle();
	//@cmember
	/* Returns the accumulated width of the subcomponents*/
	virtual int GetWidth();
	//@cmember
	/* Returns the accumulated height of the subcomponents*/
	virtual int GetHeight();
	//@cmember
	/* Registers a display subcomponent*/
	virtual void RegisterDisplay(SRGDisplayBase *pD);
	//@cmember
	/* Sets the start position of the labels, tick marks, and grid lines*/
	virtual void SetStartPos(CPoint ptStart){m_ptStart=ptStart;}
	//@cmember
	/* Sets the end position of the labels, tick marks, and grid lines*/
	virtual void SetEndPos(CPoint ptEnd){m_ptEnd=ptEnd;}
	//@cmember
	/* Returns the start position of the labels, tick marks, and grid lines*/
	virtual CPoint GetStartPos(){return m_ptStart;}
	//@cmember
	/* Returns the end position of the labels, tick marks, and grid lines*/
	virtual CPoint GetEndPos(){return m_ptEnd;}
	//@cmember
	/* Registers a tick mark subcomponent*/
	virtual void RegisterTicks(SRGTickMarks *pT);
	//@cmember
	/* Registers a label subcomponent*/
	virtual void RegisterLabels(SRGDecimalScale *pL);
	//@cmember
	/* Registers a data watcher subcomponent*/
	virtual void RegisterWatcher(SRGDataWatcher *pDW);
	//@cmember
	/* Registers an axis title label subcomponent*/
	virtual void RegisterTitle(SRGraphLabel *pL);
	//@cmember
	/* Constructor*/
	SRGAxisManager();

	DECLARE_SERIAL(SRGAxisManager);

	//@cmember
	/* Destructor*/
	virtual ~SRGAxisManager();

protected:
	//@cmember
	/* Performs pre-draw or pre-size initialization of the subcomponents*/
	virtual void PassTwoSetup();
	//@cmember
	/* Performs pre-draw initialization of the subcomponents*/
	virtual void PassOneSetup();

	//@cmember
	/* Node adjustment flag*/
	BOOL m_bNodeAdjust;
	//@cmember
	/* TRUE if labels have been registered*/
	BOOL m_bLabelsOK;	// 0
	//@cmember
	/* TRUE if tick marks have been registered*/
	BOOL m_bTicksOK;	// 1
	//@cmember
	/* TRUE if grid lines have been registered*/
	BOOL m_bGridsOK;	// 2
	//@cmember
	/* TRUE if a data watcher has been registered*/
	BOOL m_bWatcherOK;	// 3
	//@cmember
	/* TRUE if a display has been registered*/
	BOOL m_bDisplayOK;	// 4
	//@cmember
	/* TRUE if a title label been registered*/
	BOOL m_bTitleOK;	// 5
	//@cmember
	/* Position of the end of the axis*/
	CPoint m_ptEnd;
	//@cmember
	/* Position of the start of the axis*/
	CPoint m_ptStart;

};



#endif // !defined(_SRGAXISMANAGER_H_INCLUDED_)
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

