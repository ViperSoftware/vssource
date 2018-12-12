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
//@doc SRGraph
//@module SRGraph.h | SRGraph header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SRGraph.h: interface for the SRGraph class
//
/////////////////////////////////////////////////////////////////


#include "SRGDat.h"	// Added by ClassView
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef __SRGRAPH__
#define __SRGRAPH__

class SRGraphDummyData : public SRGraphData
{
public:
	virtual void SetNull(BOOL /*b*/){}
	virtual void SetValue(double /*number*/){}
	SRGraphDummyData(){m_HiLoValue.Zero();m_bNULL=TRUE;m_dValue=0.0;}
	virtual void SetAnnotation(int /*code*/, LPCTSTR /*text*/){}
	virtual void SetAnnotation(LPCTSTR /*text*/, BOOL /*clear=FALSE*/, int /*code=1*/){}
};


//////////////////////////////////////////////////////
// Autoduck help file entries for SRGraph

//@doc SRGraph

//@mfunc BOOL | SRGraph | IsBackgroundDraw | Interrogates the m_bBackgroundDraw member
//@see <mf SRGraph::SetBackgroundDraw> <md SRGraph::m_bBackgroundDraw>

//@mfunc BOOL | SRGraph | IsFeedbackLogging | Interrogates the m_bFeedbackLogging member
//@see <mf SRGraph::SetFeedbackLogging>, <md SRGraph::m_bFeedbackLogging>

//@mfunc void | SRGraph | SetBackgroundDraw | Initializes the m_BackgroundDraw member
//@parm BOOL | bBDraw | TRUE to enable background drawing, FALSE to disable

//@mfunc void | SRGraph | SetFeedbackLogging | Initializes the m_bFeedbackLogging member
//@parm BOOL | bLogging | TRUE to enable feedback logging, FALSE to disable
//@rem When drawing a graph, a list of feedback items may be created. Each feedback item contains 
//information about a data item and its appearance on screen. When the mouse button is clicked or 
//moves over a "hot" area, the feedback list can determine the group and index of the data associated with the area.
//@see <c SRGraphFeedback>, <md SRGraph::m_FeedbackList>

//@mdata BOOL | SRGraph | m_bIsEmpty | TRUE if this graph holds no data, otherwise FALSE

//@mdata BOOL | SRGraph | m_bSignificantChange | TRUE after a <mf SRGraph::SetSignificantChanges> command
//@rem The signficant change system allows the graph to process data faster by only updating items 
//when they have changed. All of the components in the component list look at their own 
//significant change flag before the draw cycle commences. If the flag is TRUE, the component 
//completely redraws all of its elements and updates all of its labels.

//@mdata BOOL | SRGraph | m_bBackgroundDraw | TRUE if the <mf SRGraph::DrawComponentList> 
//function should draw data in a back buffer before copying to the screen<nl>
//Ignored if the owner window is printing
//@rem Background drawing is useful for drawing flicker-free graphs, but it may be slow 
//or memory hungry on slower or smaller systems.

//@mdata BOOL | SRGraph | m_bFeedbackLogging | TRUE if automatic construction of the feedback list is required, otherwise FALSE
//@see <c SRGraphFeedback>, <md SRGraph::m_FeedbackList>

//@mdata BOOL | SRGraph | m_bHintPending | TRUE if a redrawing hint has been flagged but not yet processed

//@mdata CObList | SRGraph | m_ComponentList | Holds a list of <c SRGraphComponent> objects 
//which define the appearance of this graph
//@rem This is the master list of all graphic components in this graph.
//@see <c SRGraphComponent>, <c SRGraphDisplay>, <c SRGraphLegend>, <c SRGraphTitle>, 
//<c SRGraphBackground>, <mf SRGraph::DrawComponentList>, <mf SRGraph::GetComponentList>

//@mdata CPtrList | SRGraph | m_data | Main list of <c SRGraphDataList> objects
//@rem This is root object for the data array in this graph. It holds pointers to a list 
//of SRGraphDataList objects -- one for each group.
//@see <mf SRGraph::GetDataList>

//@mdata int | SRGraph | m_nDefaultGroup | Group currently being used as the default data set

//@mdata CObList | SRGraph | m_FeedbackList | Holds a list of <c SRGraphFeedback> objects
//@see <md SRGraph::m_bFeedbackLogging>

//@mdata LPARAM | SRGraph | m_lHint | Hint value passed to this graph after a view update request

//@mdata CObject* | SRGraph | m_pHint | Pointer to a CObject-based hint item -- not currently 
//used in this implementation of Objective Chart (reserved)

//@mdata SRGraphStyle | SRGraph | m_Style | An <c SRGraphStyle> object which holds information about this graph

//@mdata SRGraphAnnotationList | SRGraph | m_strTitle |  Multi-lingual titles for this graph object
//@see <c SRGraphAnnotationList> <c SRGraphAnnotation>

//@mdata int | SRGraph | m_nCountryCode | Telephone dialing code of the country for which 
//annotation texts should be displayed
//@rem The default setting for the country code is 1 (USA). Providing that you have made the 
//correct entries in your annotation lists, setting this data member will make the graph 
//display the corresponding language text at the next redraw.
//@see <mf SRGraph::SetCountryCode>, <mf SRGraph::GetCountryCode>

//@mfunc void | SRGraph | SetCountryCode | Initializes the country code for this graph
//@parm int | nCode | Integer specifying the telephone dialing code of the desired language 
//(ie. 1 for USA, 49 for Germany, etc.)
//@see <mf SRGraph::GetCountryCode>, <md SRGraph::m_nCountryCode>

//@mfunc int | SRGraph | GetCountryCode | Interrogates the country code for this graph
//@rdesc Integer which specifies the telephone dialing code of the desired language (i.e, 1 for USA, 49 for Germany, etc.)
//@see <mf SRGraph::SetCountryCode> <md SRGraph::m_nCountryCode>

//@mfunc void | SRGraph | SetMaxArea | Sets the maximum area which a graph may use
//@parm CRect | r | Rectangle in which to display the graph
//@parm BOOL | UseMaxArea | If TRUE (default) then this area is used
//@rem The maximum area is primarily used to limit page sizes and image areas during printing, 
//but it could be used for window displays too.

//@mdata CRect | SRGraph | m_MaxArea | Maximum area which a chart may occupy
//@rem The maximum area is currently used only in print preview mode, 
//but it could be used in a screen mode too.

//@mdata DWORD | SRGraph | m_dwAlignInDC | Semaphores for centering behaviour
//@rem Alignment is currently used only in print preview mode, but it could be used in a screen mode too.

//@mdata BOOL | SRGraph | m_bUseMaxArea | Flag to use maximum area rectangle
//@rem When this flag is not set, the size is determined by the DC being drawn on.<nl>
//The maximum area is currently used only in print preview mode, but it could be used in a screen mode too.

//@mfunc BOOL | SRGraph | GetUseMaxArea | Returns TRUE if the maximum area described in m_MaxArea is to be used

//@mfunc BOOL | SRGraph | SetUseMaxArea | Initializes the m_MaxArea member variable
//@parm BOOL | b | TRUE if the area is to be used

//@mfunc CRect | SRGraph | GetMaxArea | Returns the m_MaxArea rectangle

//@mfunc void | SRGraph | SetAlignment | Sets up pagination of the graph
//@parm DWORD | dwAlign | Alignment code
//@rem The alignment code may be defined by mixing parameters with a binary OR operator.<nl>
//Vertical alignment codes are...<nl>
//		CX_ALIGN_NONE<nl>
//		CX_ALIGN_VTOP<nl>
//		CX_ALIGN_VCENTER<nl>
//		CX_ALIGN_VBOTTOM<nl>
//Horizontal alignment codes are...<nl>
//		CX_ALIGN_NONE<nl>
//		CX_ALIGN_HLEFT<nl>
//		CX_ALIGN_HCENTER<nl>
//		CX_ALIGN_HRIGHT<nl>


//@mdata POSITION  | SRGraph | m_CurrentComponentPos | POSITION in the list of the component currently being drawn

//@mdata POSITION  | SRGraph | m_LastPos | POSITION of last accessed data item

//@mdata int  | SRGraph | m_LastGroup | Group of last accessed data item

//@mdata BOOL  | SRGraph | m_bDrawing | Flag set while chart is being drawn

//@mdata CWnd *  | SRGraph | m_pCWnd | Pointer to the CWnd being drawn into

//@mdata CDC *  | SRGraph | m_pDC | Pointer to the CDC being drawn into

//@mdata CRect  | SRGraph | m_OldRect | Rectangle used to retain the old display rectangle

//@mdata CRect  | SRGraph | m_BGRect | Background rectangle

//@mdata CBitmap  | SRGraph | m_Shadow | Bitmap used as a back buffer for flicker free drawing

//@mdata SRGraphData  | SRGraph | dummydata | A dummy chart data object that is returned in case none exists

//@mfunc void  | SRGraph | SetBanding | Sets the banding flag.
//@parm BOOL  | v | Set TRUE before a print preview or print run to use the PrintComponentList routine

//@mfunc BOOL  | SRGraph | GetBanding | Returns the m_bBanding flag -- set during construction of a banded print bitmap

//@mdata CRect  | SRGraph | m_DisplayRect | Current display rectangle -- not saved at serialization

//@mdata CObStack  | SRGraph | m_ClipStack | Stack for storing clipping regions

//@mdata CRect  | SRGraph | m_PageRect | Drawing rectangle used in printing

//@mdata BOOL  | SRGraph | m_bBanding | Banding flag to enable use of banding system during printing

//@mfunc virtual void  | SRGraph | SetPaletteSupported | Initializes the palette support flag 
//@parm BOOL  | v | Set to TRUE to enable palette support 

//@mfunc virtual BOOL  | SRGraph | GetPaletteSupported | Returns the palette support flag.

//@mdata CPalette  | SRGraph | m_Palette | Palette used for this chart (normally preset to a 332 scheme)

//@mdata BOOL  | SRGraph | m_bPaletteSupported | Palette support flag<nl>
//When this flag is set TRUE, the chart is being drawn on a palettized GDI.

//@mfunc virtual CPalette * | SRGraph | GetPalette | Returns a pointer to the stored palette

//@mfunc DWORD  | SRGraph | GetAlignment | Returns the alignment style for this graph


//@doc SRGraph
//@mdata SRGraphStyle  | SRGraph | m_DefaultDataStyle | This <c SRGraphStyle> object is used to generate a default style
// that is copied automatically to new data items as they are created through the <mf SRGraph::SetValue> process.

//@doc SRGraph
//@mdata int  | SRGraph | m_nAutoColorRange | This is the range of colors recognised by the auto pen and auto brush features of OC. This defaults to 16 but
// may be set to generate any default data style configuration.


//@doc SRGraph
//@mfunc virtual void  | SRGraph | SetDefaultDataStyle | This allows initialisation of the default style used whenever a new data object is created. Preset this to
//  some visual style, for example set the default color to red or the default object type to CX_OBJECT_DOT, and this style will be used for all subsequent data creation operations. 
//@parm SRGraphStyle  | v | The pre-set style.


//@doc SRGraph
//@mfunc virtual SRGraphStyle  * | SRGraph |GetDefaultDataStyle | This function returns the default style as set by <mf SRGraph::SetDefaultDataStyle >


//@doc SRGraph
//@mfunc virtual void  | SRGraph | SetAutoColorRange | The normal range of pen colors defaults to 16. Using this function it is possible to use a default range of any number.
// The auto-pen and auto-bruh creation routines will return a color that is based upon this range or the standard colors if 16 is used.
//@parm int  | v | parm comment 


//@doc SRGraph
//@mfunc virtual int  | SRGraph | GetAutoColorRange | This returns the value set by <mf SRGraph::SetAutoColorRange>





//@doc SRGraph
//@mdata CObList  | SRGraph | m_PolygonList | This variable retains the list of compiled polygons used by all the components on the component list.



//@doc SRGraph
//@mdata CMapStringToPtr  | SRGraph | m_PenMap | This map collection stores pens which have been created by the chart 
//Pens are given a string identifier generated from thier color and style information. These pens can then be re-used 
//thereby eliminating the time consuming pen creation and destruction process.

//@doc SRGraph
//@mdata CString  | SRGraph | m_strEmptyString | Always contains an empty string. This eliminates some CString object creation and speeds up execution.

//adinsert

/////////////////////////////////////////////////////////////////////////////////////////////

//$head The Graph object
//$level 1

//@doc SRGraph
//@class The graph data parent object -- the main placeholder for all Objective Chart functionality
//@base public | CObject
class SRGraph : public CObject
{
protected:
	//@cmember
	/* Contains an empty string */
	CString m_strEmptyString;	// always empty
//@access Public data members
public:
	//@cmember
	/* Returns the m_bFeedbackLogging flag*/
	virtual BOOL GetFeedbackLogging();

	//@cmember
	/* Set TRUE to inform the whole graph of a change in the data or component structures*/
	BOOL m_bSignificantChange;

	//@cmember
	/* Dialing code of the country for which this graph should be adjusted*/
	int m_nCountryCode;
	
	//@cmember
	/* Pointer to a hint object (not currently used)*/
	CObject * m_pHint;

	//@cmember
	/* Most recent hint code*/
	LPARAM m_lHint;

	//@cmember
	/* Semaphore signifying that a hint operation is outstanding*/
	BOOL m_bHintPending;

	//@cmember
	/* Semaphore enabling or disabling the use of a back buffer in draw operations*/
	BOOL m_bBackgroundDraw;

	//@cmember
	/* Default group for all display types that use only one group -- pie charts, etc. */
	int m_nDefaultGroup;

	//@cmember
	/* Style data for axes and graph types*/
	SRGraphStyle m_Style;
	
	//@cmember
	/* List of components which make up the graphical display elements for this graph*/
	CObList m_ComponentList;

	//@cmember
	/* Flag signifying a clean graph if TRUE*/
	BOOL m_bIsEmpty;

	//@cmember
	/* Title list*/
	SRGraphAnnotationList m_strTitle;
	
	//@cmember
	/* List of pointers to the data*/
	CPtrList m_data;

	//@cmember
	/* Semaphore to enable or disable feedback logging*/
	BOOL m_bFeedbackLogging;
	
	//@cmember
	/* Linked list of SRGraphFeedback objects*/
	CObList m_FeedbackList;
	

//operations
//@access Private member functions
private:

	//@cmember
	/* Parses a substring from the text buffer*/
	int SubString(LPCTSTR text,CString &section,DWORD *index,double *number);

#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Reports syntax errors in graph template text*/
	virtual void TemplateSyntax(LPCTSTR line);
#endif	//  _OC_DONT_SUPPORT_TEXT_TEMPLATE

//@access Public member functions
public:
	//@cmember
	/* A one step version of add component to graph*/
	virtual SRGraphComponent* AddComponent(UINT nType, int nMeasure = CX_PERCENT, 
		const CRect& rect = CRect(-1, -1, -1, -1), DWORD nBorder = CX_NO_BORDER, 
		DWORD nShadow = CX_NO_SHADOW, DWORD nFillStyle = CX_SOLID_FILL, 
		DWORD nGraphStyle = CX_GRAPH_VBAR, DWORD nAxisStyle = CX_AXIS_AUTOMATIC);
	//@cmember
	/* Returns a new pen or one stored in the cache */
	CPen * GetPen(int nPenStyle, int nPenWidth, COLORREF PenColor);
	//@cmember
	/* Loads a named polygon*/
	virtual SRGCompiledPolygon * LoadPolygon(LPCTSTR strPolygonName, LPCTSTR strSectionName);
	//@cmember
	/* Initialises the default data style*/
	virtual void SetDefaultDataStyle(SRGraphStyle v){m_DefaultDataStyle=v;}
	//@cmember
	/* Retrieves the default data style*/
	virtual SRGraphStyle * GetDefaultDataStyle(){return &m_DefaultDataStyle;}
	//@cmember
	/* Sets the range of colors used by auto pen and auto brush*/
	virtual void SetAutoColorRange(int v){m_nAutoColorRange=v;}
	//@cmember
	/* Sets the range of colors used by auto pen and auto brush*/
	virtual int GetAutoColorRange(){return m_nAutoColorRange;}
	//@cmember
	/* Deletes components designated as "temporary" from the component list.*/
	virtual void DeleteTemporaryComponents(LPCTSTR strName);
	//@cmember
	/* Finds a component on the component list*/
	virtual SRGraphComponent * FindComponentByName(LPCTSTR strName);
	//@cmember
	/* Finds or tries to create a compiled polygon by accessing the polgon cache*/
	virtual BOOL GetCompiledPolygon(LPCTSTR strPolygonName, LPCTSTR strSectionName, SRGCompiledPolygon * * pPoly,double dAngle=0);
	//@cmember
	/* Creates a half tone palette*/
	virtual void Create332Palette(CPalette *pPal);

	//@cmember
	/* Saves or loads the component list via serialization*/
	virtual void SerializeComponentList(CArchive &ar);
	
	//@cmember
	/* Adds a point to the feedback logging system*/
	virtual void LogPoint(CPoint point,int group,int index,int nRadius);
	
	//@cmember
	/* Removes all data from the graph object while leaving the component list intact*/
	virtual void KillData();

	//@cmember
	/* Sets the clipping region to a particular polygon*/
	virtual void ClipPoly(CPoint *pPoint,int nPointCount,int nMode=RGN_COPY);

	//@cmember
	/* Sets the clipping region to a particular rectangle*/
	virtual void ClipRect(CRect r,int nMode=RGN_COPY);
	
	//@cmember
	/* "Pops" a stored clipping region and restores it*/
	virtual void PopClip();
	
	//@cmember
	/* "Pushes" the current clipping region on to a stack*/
	virtual void PushClip();
	
	//@cmember
	/* Uses a print banding system to output the component list to the printer */
	virtual void PrintComponentList(CDC *pCD, CWnd *pCWnd);
	
	//@cmember
	/* Returns the POSITION of the component currently being drawn*/
	virtual POSITION GetCurrentComponentPos();
	
	//@cmember
	/* Creates a new SRGraphDataList-based object -- overridable to */
	//allow objects derived from SRGraphDataList to be returned
	virtual SRGraphDataList * NewGroup();
	
	//@cmember
	/* Returns the 'safe' data item -- does not grow the list, does not assert*/
	virtual SRGraphData * GetSafeData(int index,int group);
	
	//@cmember
	/* Returns the 'unsafe' data item -- can grow the list*/
	virtual SRGraphData * GetData(int index,int group);
	
	//@cmember
	/* Returns the size of the display area*/
	virtual CSize GetDisplaySize();
	
	//@cmember
	/* Constructor*/
	SRGraph();
	
	//@cmember
	/* Current display rectangle -- not saved at serialization*/
	CRect m_DisplayRect;
	
	//@cmember
	/* Destructor*/
	virtual ~SRGraph();

	//@cmember
	/* Rolls a group in the specified direction*/
	virtual void RollGroup(int nGroup, double dValue=0.0, BOOL bDirection=FALSE);

	//@cmember
	/* Places a feedbck rectangle on the feedback list*/
	virtual void LogRectangle(CRect r,int group, int index);

	//@cmember
	/* Sets the maximum area which a graph may use*/
	void SetMaxArea(CRect r,BOOL bUseArea=TRUE){m_MaxArea=r;m_bUseMaxArea=bUseArea;}

	//@cmember
	/* Returns the rectangle defined as the maximum usable area*/
	CRect GetMaxArea(){return m_MaxArea;}

	//@cmember
	/* Returns TRUE if the sizes of the final display are to be controlled by the m_MaxArea rectangle*/
	BOOL GetUseMaxArea(){return m_bUseMaxArea;}

	//@cmember
	/* Enables or disables the use of the maximum size rectangle*/
	void SetUseMaxArea(BOOL b){m_bUseMaxArea=b;}

	//@cmember
	/* Sets the alignment style for this graph*/
	void SetAlignment(DWORD dwAlign){m_dwAlignInDC=dwAlign;}

	//@cmember
	/* Gets the alignment style for this graph*/
	DWORD GetAlignment(){return m_dwAlignInDC;}

	//@cmember
	/* Signals to all components on the main list that an important change has taken place*/
	virtual void SetSignificantChanges();
	
	//@cmember
	/* Sets the style of all data items in a range to a reference style*/
	virtual void SetGlobalStyle(int nStartGroup,int nEndGroup,int nStartIndex,int nEndIndex,SRGraphStyle *ptrStyle,BOOL bSetHeaders=TRUE);

	//@cmember
	/* Sets the minimum index for a given display on the component list*/
	virtual void SetComponentMinIndex(int nComponent,int index,UINT Type=-1);
	
	//@cmember
	/* Sets the maximum index for a given display on the component list*/
	virtual void SetComponentMaxIndex(int nComponent,int index,UINT Type=-1);
	
	//@cmember
	/* Sets the minimum group for a given display on the component list*/
	virtual void SetComponentMinGroup(int nComponent,int group,UINT Type=-1);
	
	//@cmember
	/* Sets the maximum group for a given display on the component list*/
	virtual void SetComponentMaxGroup(int nComponent,int group,UINT Type=-1);
	
	//@cmember
	/* Returns the average of all data items in this group*/
	virtual double GetGroupAverage(int group);

	//@cmember
	/* Returns the total for a given index across all groups*/
	virtual double GetIndexTotal(int index,int nMinGroup=0,int nMaxGroup=0);

	//@cmember
	/* Returns FALSE  -- this object is not a dynamic graph*/
	virtual BOOL IsDynamic();

	//@cmember
	/* Wipes the component list without destroying the graph data*/
	virtual void KillComponentList();

	//@cmember
	/* Changes title text in the m_strTitle annotation list*/
	virtual void SetGraphTitle(LPCTSTR title,int code=1);

	//@cmember
	/* Updates hint information for the component drawing routines*/
	virtual void SetComponentHint(CWnd * pCWnd,LPARAM lHint,CObject * pHint);

	//@cmember
	/* Interprets tab delimited text data into graph information*/
	virtual void ParseText(LPCTSTR text);
	
	//@cmember
	/* Empties a graph of data*/
	virtual void KillGraph(void);

	//@cmember
	/* Calculates the total of all data values in a given range of groups and indices -- used to calculate percentages*/
	virtual double GetDataTotal(int mingroup, int  minindex, int maxgroup, int maxindex);

	//@cmember
	/* Calculates the total of all data storage values in this graph -- used to calculate percentages*/
	virtual double GetDataTotal(int group=-1);

#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Parses a graph template either from a resource or filename*/
	virtual void ReadTemplate(LPCTSTR TemplateName);

	//@cmember
	/* Override this function to interpret your own custom template commands*/
	virtual BOOL UserParser(LPCTSTR line);
#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember	Returns
	/* the header from the <c SRGraphDataList> list indexed by group*/
	virtual CString& GetHeader(int group=0,int code=1);

	//@cmember	Returns
	/* text held in the <c SRGraphData> object within group and referenced by index*/
	virtual CString& GetText(int group,int index,int code=1);

	//@cmember
	/* Returns the title of the graph*/
	virtual CString & GetGraphTitle(int code=1);

	//@cmember
	/* Returns the total number of data sets (groups) in the graph*/
	virtual int GetGroupCount();

	//@cmember
	/* Returns the count of the longest group*/
	virtual int GetMaxXDivisions();

	//@cmember
	/* Scans the graph data and returns the maximum and minimum value used in this graph*/
	virtual CScale GetAutoScaleRange(BOOL HiLo=FALSE);

	//@cmember
	/* References the correct <c SRGraphDataList> in the array*/
	SRGraphDataList *GetGroup(int group,BOOL GrowList=TRUE);

	//@cmember	Adds
	/* a <c SRGraphComponent> or derived object to the list of graphic objects*/
	virtual POSITION AddComponent(SRGraphComponent *gc);

	//@Cmember Scans the component list, drawing as it goes (order in the list is reverse Z order on screen)
	virtual void DrawComponentList(CDC *pDC,CWnd *pCWnd);


	DECLARE_SERIAL(SRGraph);

	//@cmember
	/* Handles storage and retrieval of data*/
	virtual void Serialize(CArchive &ar);

	//@cmember
	/* Sets a header for a group of data by annotating the <c SRGraphDataList> for that group*/
	void SetHeader(int group,LPCTSTR text,int nCode=1);

	//@cmember
	/* Sets a numeric value in the data array*/
	void SetValue(int x,int group,double number,BOOL bUseDefaultStyle=FALSE);

	//@cmember
	/* Sets text in the data array*/
	void SetText(int x,int group,LPCTSTR text);

#ifdef _DEBUG

	//@cmember
	/* Dump diagnostics -- debug only*/
	void Dump(CDumpContext &dc) const;

#endif //_DEBUG

	//@cmember
	/* Searches for a feedback point*/
	virtual SRGraphFeedback *GetFeedback(int x,int y);
	
	//@cmember
	/* Adds a polygon to the feedback list*/
	virtual void LogPoly(LPPOINT points,int PointCount,int group,int index);
	
	//@cmember
	/* Adds a point to the feedback list*/
	virtual void LogPoint(CPoint point,int group,int index);
	
	//@cmember
	/* Retrieves an average value for a specific index across a range of groups*/
	virtual double GetGroupAverage(int MinIndex,int MaxIndex,int Group);
	
	//@cmember
	/* Calculates the total of all graph values*/
	virtual double GetGraphTotal();
	
	//@cmember
	/* Retrieves the m_bBackgroundDraw member*/
	virtual BOOL IsBackgroundDraw(){return m_bBackgroundDraw;}
	
	//@cmember
	/* Retrieves the m_bFeedbackLogging member*/
	virtual BOOL IsFeedbackLogging(){return m_bFeedbackLogging;}
	
	//@cmember
	/* Initializes the m_bFeedbackLogging member*/
	virtual void SetFeedbackLogging(BOOL bLogging=TRUE){m_bFeedbackLogging=bLogging;}
	
	//@cmember
	/* Initializes the m_bBackgroundDraw member*/
	virtual void SetBackgroundDraw(BOOL bBDraw=TRUE){m_bBackgroundDraw=bBDraw;}
	
	//@cmember
	/* Returns a pointer to the m_strTitle member*/
	virtual SRGraphAnnotationList * GetTitle();
	
	//@cmember
	/* Returns a pointer to the m_FeedbackList member*/
	virtual CObList * GetFeedbackList();
	
	//@cmember
	/* Returns a pointer to the m_ComponentList member*/
	virtual CObList * GetComponentList();
	
	//@cmember
	/* Returns a pointer to the m_ComponentList member*/
	virtual SRGraphStyle * GetStyle();
	
	//@cmember
	/* Gets a numeric value from the data array*/
	virtual double GetValue(int index,int group);
	
	//@cmember
	/* Returns a pointer to a specific component in the component list*/
	virtual SRGraphComponent * GetComponent(int nComponent,UINT Type);
	
	//@cmember
	/* Searches the m_ComponentList for the next item after the supplied POSITION*/
	virtual SRGraphComponent * GetNextComponent(POSITION& rPos,UINT Type=-1);
	
	//@cmember
	/* Gets the first POSITION in the component list*/
	virtual POSITION GetFirstComponentPosition(UINT Type=-1);
	
	//@cmember
	/* Returns a pointer to the m_data member*/
	virtual CPtrList *GetDataList();
	
	//@cmember
	/* Finds the first POSITION of the first item on the m_data list*/
	virtual POSITION GetFirstDataPosition();
	
	//@cmember
	/* Gets the next item fron the m_data list*/
	virtual void *GetNextData(POSITION& p);

	//@cmember
	/* Sets the dialing code for the annotations in this graph*/
	virtual void SetCountryCode(int n){m_nCountryCode=n;SetSignificantChanges();}
	
	//@cmember
	/* Interrogates the dialing code for the annotations in this graph.*/
	virtual int GetCountryCode(){return m_nCountryCode;}

	//@cmember
	/* Sets the banding variable -- call SetBanding before a print or preview to use the banding system*/
	virtual void SetBanding(BOOL v){m_bBanding=v;}
	
	//@cmember
	/* Returns the banding flag*/
	virtual BOOL GetBanding(){return m_bBanding;}

	//@cmember
	/* Initializes the palette support flag.*/
	virtual void SetPaletteSupported(BOOL v){m_bPaletteSupported=v;}

	//@cmember
	/* Returns the palette support flag.*/
	virtual BOOL GetPaletteSupported(){return m_bPaletteSupported;}

	//@cmember
	/* Returns the stored palette*/
	virtual CPalette *GetPalette(){return &m_Palette;}


protected:
	//@cmember
	/* This map collection stores pens which have been created by the chart */
	CMapStringToPtr m_PenMap;
	//@cmember
	/* The polygon cache*/
	CObList m_PolygonList;
	//@cmember
	/* The default data style object*/
	SRGraphStyle m_DefaultDataStyle;
	//@cmember
	/* The color range used for choosing auto brushes.*/
	int m_nAutoColorRange;
	//@cmember
	/* TRUE if a palette is used on this chart*/
	BOOL m_bPaletteSupported;

	//@cmember
	/* Stored palette (set to a 332 palette)*/
	CPalette m_Palette;

	//@cmember
	/* Stack for storing clipping regions*/
	CObStack m_ClipStack;

	//@cmember
	/* Drawing rectangle used in printing*/
	CRect m_PageRect;

	//@cmember
	/* Banding flag to enable use of banding system during printing*/
	BOOL m_bBanding;

	//@cmember
	/* Aligns a display area rectangle within a given window or page*/
	virtual void AlignRect(CRect * r, CRect DCRect);

	//@cmember
	/* Dummy chart data object that is returned in case none exists*/
	SRGraphDummyData dummydata;

	//@cmember
	/* POSITION in the list of the component currently being drawn*/
	POSITION m_CurrentComponentPos;

	//@cmember
	/* POSITION of last accessed data item -- used to enhance data access speed*/
	POSITION m_LastPos;

	//@cmember
	/*  Group of last accessed data item -- used to enhance data access speed*/
	int m_LastGroup;

	//@cmember
	/* Flag set when the chart is being drawn and the DC should be valid*/
	BOOL m_bDrawing;

	//@cmember
	/* Pointer to the CWnd being drawn into -- not valid unless m_bDrawing is true*/
	CWnd * m_pCWnd;

	//@cmember
	/* Pointer to the CDC being drawn into -- not valid unless m_bDrawing is true*/
	CDC * m_pDC;

	//@cmember
	/* Rectangle used to retain the old display rectangle*/
	CRect m_OldRect;

	//@cmember
	/* Background rectangle*/
	CRect m_BGRect;

	//@cmember
	/* Bitmap used as a back-buffer in flicker free drawing.*/
	CBitmap m_Shadow;

	//@cmember
	/* Maximum area which a chart may occupy*/
	CRect m_MaxArea;

	//@cmember
	/* Binary semaphores for centering behaviour*/
	DWORD m_dwAlignInDC;

	//@cmember
	/* Semaphore set when maximum area is used to define the image size*/
	BOOL m_bUseMaxArea;
};

//$head The Graph object (dynamic graph)
//$level 2

//@doc SRDynamicGraph
//@class Graphs which handle dynamic data
class SRDynamicGraph : public SRGraph
{

public:
	 SRDynamicGraph();
	DECLARE_SERIAL(SRDynamicGraph);
	
	//@cmember
	/* Stores or retrieves dynamic graphs*/
	virtual void Serialize(CArchive &ar);

	//@cmember
	/* Sets text header for this data*/
	virtual void SetText(int x,int group,LPCTSTR text);
	
	//@cmember
	/* Overloaded member function: places a double in the buffer*/
	virtual void SetValue(int x,int group,double number);
	
	//@cmember
	/* Overloaded member function: places an integer in the buffer*/
	virtual void SetValue(int x,int group,int number);
	
	//@cmember
	/* Overloaded member function: places a _TCHAR in the buffer*/
	virtual void SetValue(int x,int group,_TCHAR number);
	
	//@cmember
	/* Overridden member function: Text parsing is not supported in dynamic graphs*/
	virtual void ParseText(LPCTSTR text);
	
	//@cmember
	/* Returns the requested annotation from the SRGraphData referenced by index and group */
	virtual CString& GetText(int group, int index, int code=1);
	
	//@cmember
	/* Returns the maximum number of indices allowed*/
	virtual int GetMaxXDivisions();
	
	//@cmember
	/* Returns the sum of all data stored in a specified group*/
	virtual double GetDataTotal(int group=-1);
	
	//@cmember
	/* Returns the maximum and minimum values stored in this graph	*/
	virtual CScale GetAutoScaleRange(BOOL HiLo=FALSE);
};




#endif //__SRGRAPH__

// Reset DLL declaration context

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

