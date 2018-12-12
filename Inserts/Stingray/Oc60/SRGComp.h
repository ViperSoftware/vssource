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
//@doc SRGraphComponent
//@module SRGComp.h|  definition of the graph component classes<nl>
//SRGraphComponent, SRGraphRect, SRGraphTitle, SRGraphBackground, SRGraphDisplay, SRGraphLabel, SRGraphLabelBlock, SRGraphLegend<nl>
//and structures GESorter and PointSorter<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGComp.h: definition of the graph component classes
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef __GRAPH_COMPONENT__
#define __GRAPH_COMPONENT__

/////////////////////////////////////////////////////////////////////
// defines for hints used in the basic component classes  -- uses 32 bit LPARAM hints

#define COMPONENT_FOREGROUND	0x00001000
#define LEGEND_TEXT				0x00002000
#define LEGEND_KEYS				0x00003000
#define DISPLAY_AXES			0x00004000
#define DISPLAY_LABELS			0x00005000
#define DISPLAY_DATA			0x00006000

#define COMPONENT_BACKGROUND	0x00000100

#define COMPONENT_BORDER		0x00000001

#define COMPONENT_SHADOW		0x00000010

// types

#define COMPONENT 0
#define OBJECT 1

// values above 0x0000ffff are available for your own custom hints


//@struct GESorter | Graph Element Sorter - An array of GESorter objects is used to sort graphic elements indirectly.<nl>
//Each GESorter object holds a value that is compared to sort the array and an index that 
//associates the value with a group or an index within a group.<nl>
//GESorter arrays are sorted by the qsort function using the <mf SRGraphComponent::qsSorterCompare> 
//callback. Once the elements are sorted into ascending order of value, the array of GESorter structures may 
//be sequentially referenced to access the associated grapic elements in sorted order.<nl>
//This technique is used in the stacked bar graphs and 3D bar and area graphs to ensure a front-to-back ordering 
//of the data elements.
struct GESorter {
	double	value;	//@field Value to be compared and sorted
	int index;		//@field Index of the item associated with this value -- used to dereference the item after sorting
};

struct GESorterEx : public GESorter
{
	int group;
};

//@struct PointSorter | An array of PointSorter objects is used to sort graphic elements indirectly.<nl>
//Each PointerSorter object holds a CPoint that is compared to sort the array and an index that 
//associates the value with a group or index within a group.<nl>
//PointSorter arrays are sorted by the qsort function using the <mf SRGraphComponent::qsPointSorterYCompareA> 
//callback. Once elements are sorted in ascending order of CPoint, the array of PointSorter structures may 
//be sequentially  referenced to access the associated grapic elements in sorted order.<nl>
//This technique is used primarily in the drawing of 3D pie chart elements to perform rudimentary Z ordering.
typedef struct tagPointSortingStruct {
	CPoint p;	//@field Value to be compared and sorted
	int i;		//@field Index of the item associated with this value -- used to dereference the item after sorting
} PointSorter;


//////////////////////////////////////////////////
// Autoduck tagged comments for SRGraphComponent

//@doc SRGraphComponent

//@mdata BOOL | SRGraphComponent | m_bDrawing | TRUE if the component is currently in a draw 
//cycle, otherwise FALSE
//@rem This semaphore is used to determine whether the current m_pCWnd and m_pDC pointers are valid. 
//Only when this flag is TRUE can the system rely on device capability data or window access.

//@mdata CBrush | SRGraphComponent | m_AutoBrush | Brush used for auto coloring
//@see <mf SRGraphComponent::CreateAutoBrush> <md SRGraphComponent::m_AutoPen>

//@mdata CPen | SRGraphComponent | m_AutoPen | Pen used for auto coloring
//@see <mf SRGraphComponent::CreateAutoPen> <md SRGraphComponent::m_AutoBrush>

//@mdata BOOL | SRGraphComponent | m_bHiLo | Semaphore set if this component needs to take notice of HiLo (<c CScale>) data

//@mdata double | SRGraphComponent | m_dMarginX | Device independent margin for the left and right sides of a component
//@see <md SRGraphComponent::m_dMarginY> <mf SRGraphComponent::GetXMargin> <mf SRGraphComponent::SetXMargin>

//@mdata double | SRGraphComponent | m_dMarginY | Y margin around the component -- may be set to a position independant value.<nl>
//The data returned by the GetMargin functions will use the type setting of the SRGraphRect m_Rect member to adjust the size.
//@see <md SRGraphComponent::m_dMarginX> <mf SRGraphComponent::GetYMargin> <mf SRGraphComponent::SetYMargin>

//@mdata int | SRGraphComponent | m_nMaxIndex| Maximum index that this component notices, -1 to autodetect and cover the whole range

//@mdata int | SRGraphComponent | m_nMinIndex| Minimum index that this component notices, -1 to autodetect and cover the whole range

//@mdata int | SRGraphComponent | m_nMaxGroup| Maximum group that this component notices, -1 to autodetect and cover the whole range

//@mdata int | SRGraphComponent | m_nMinGroup| Minimum group that this component notices, -1 to autodetect and cover the whole range

//@mdata int | SRGraphComponent | m_nDivCount| Calculated count of indices spanned by this component

//@mdata int | SRGraphComponent | m_nMaxDiv| Internal maximum index that this component notices -- 
//re-calculated at every draw cycle and depends on the value in <md SRGraphComponent::m_nMaxIndex>

//@mdata int | SRGraphComponent | m_nMinDiv| Internal minimum index which this component notices -- 
//re-calculated at every draw cycle and depends on the value in <md SRGraphComponent::m_nMinIndex>
 
//@mdata int | SRGraphComponent | m_nSetCount| Calculated count of groups (sets) spanned by this component
 
//@mdata int | SRGraphComponent | m_nMinSet| Internal minimum group that this component notices -- 
//re-calculated at every draw cycle and depends on the value in <md SRGraphComponent::m_nMinGroup>
 
//@mdata int | SRGraphComponent | m_nMaxSet| Internal maximum group which this component notices --  
//re-calculated at every draw cycle and depends on the value in <md SRGraphComponent::m_nMaxGroup>
 
//@mdata CScale | SRGraphComponent | m_ScaleY| Range of data values spanned by this component -- 
//used in the dynamic recalculation of graph scaling during each draw cycle

//@mdata double | SRGraphComponent | m_dTickSize| Size of the tick marks on graph axes -- the physical 
//size depends on the measurement mode used in the m_Rect variable
//@see <mf SRGraphRect::SetMeasurement> <md SRGraphComponent::m_Rect>

//@mdata SRGraphRect | SRGraphComponent | m_Rect| Rectangle that contains this component -- 
//similar to the CRect object but uses floating point coordinates so that various units may be 
//used (pixels, millimeters, inches, or percentage
//@see <c SRGraphRect>

//@mdata int | SRGraphComponent | m_nCurrentIndex | Integer variable used to generate the 
//automatic pens, fills, and wiget shapes<nl>
//Normally this variable is updated during the component drawing cycle according to graph type. 
//Bar and line graphs increment this variable according to the group currently being drawn. 
//Pie charts update it once for each pie wedge.

//@mdata SRGraphStyle | SRGraphComponent | m_Style | Style variable for this component -- used 
//to define the appearance of the item on screen
//@see <c SRGraphStyle>

//@mdata CWnd * | SRGraphComponent | m_pCWnd | Draw-time pointer to the window in which this 
//component is to be displayed -- passed to the graph routines in the <mf SRGraph::DrawComponentList> function

//@mdata CDC * | SRGraphComponent | m_pDC| Draw-time pointer to the device context upon which 
//this component is to be displayed -- passed to the graph routines in the <mf SRGraph::DrawComponentList> function 

//@mdata SRGraph * | SRGraphComponent | m_pParentGraph| Pointer to the SRGraphObject that owns 
//this component -- allows components to reference data stored by the graph

//@mdata UINT | SRGraphComponent | m_nType| Component type -- the resource ID of the string 
//that describes the component
//@see SRGraphResource (SRGRES.RC) files for details of IDS_SRG_TITLETYPE, etc.

//@mdata BOOL | SRGraphComponent | m_bSignificantChange | Set to tell the component that an 
//external agent has made a significant change to the graph's data structures or to the 
//components parameters<nl>
//When this semaphore is TRUE, the next draw cycle will recalculate all of the relevant sizes, 
//label parameters, etc. and then reset this flag to signify that the condition has been handled.

//@mdata CObList | SRGraphComponent | m_PolygonList | Linked list of previously compiled polygons that are available to this component<nl>
//Whenever a polygon resource is requested, the component examines this list to see if it 
//has already been compiled. If found, the existing model is used. If not, the requested polygon 
//is found, compiled, added to the list, and (finally) used.

//@mdata CScale | SRGraphComponent | m_ScaleX | Calculated scale for the X axis of scatter graphs and similar types -- 
//normally calculated at the beginning of the draw cycle by the relevant preparation routine

//@mdata int | SRGraphComponent | m_nCountryCode | Defines which annotation is to be used for text items in this component<nl>
//Any SRGraphAnnotationList-based text will use this country code to decide which one of the 
//available text strings will be used.

//@mfunc BOOL | SRGraphComponent | GetHiLo | Returns the status of hi-lo data gathering<nl>
//If hi-lo status is TRUE, the pre-draw preparation routines should take the current values 
//of the hi-lo records into account when working out any scales.

//@mfunc void | SRGraphComponent | SetHiLo | Returns the status of hi-lo data gathering<nl>
//If hi-lo status is TRUE, the pre-draw preparation routines should take the current values 
//of the hi-lo records into account when working out any scales.
//@parm BOOL | style | TRUE if hi-lo gathering is to be used

//@mfunc CDC * | SRGraphComponent | GetpDC | Returns a pointer to the CDC object being used to draw the component<nl>
//Note that this is only valid during a draw cycle or after the component has been suitably informed by the <mf SRGraphComponent::DrawingUsing> command.

//@mfunc CWnd * | SRGraphComponent | GetpCWnd | Returns a pointer to the CWnd object being used to draw the component<nl>
//Note that this is only valid during a draw cycle or after the component has been suitably informed by the <mf SRGraphComponent::DrawingUsing> command.

//@mfunc int | SRGraphComponent | GetDivCount | Returns the number of indices or divisions that this component currently has in its scope

//@mfunc int | SRGraphComponent | GetSetCount | Returns the number of groups or sets that this component currently has in its scope

//@mfunc CScale & | SRGraphComponent | GetScaleX | Returns a reference to the m_ScaleX member

//@mfunc CScale & | SRGraphComponent | GetScaleY | Returns a reference to the m_ScaleY member

//@mfunc int | SRGraphComponent | GetMaxDiv | Returns the maximum index which this component may currently act upon

//@mfunc int | SRGraphComponent | GetMinDiv | Returns the minimum index which this component may currently act upon

//@mfunc int | SRGraphComponent | GetMaxSet | Returns the maximum group which this component may currently act upon

//@mfunc int | SRGraphComponent | GetMinSet | Returns the minimum group which this component may currently act upon

//@mfunc int | SRGraphComponent | GetMeasurement | Returns the type of measurement which this component is using 
//@see <mf SRGraphRect::GetMeasurement> for code details

//@mfunc SRGraph * | SRGraphComponent | GetParent | Returns the pointer (m_pParentGraph) which references the SRGraph which owns this component

//@mfunc void | SRGraphComponent | SetpCWnd | Sets the CWnd object to be used to draw this component
//@parm CWnd * | pCWnd | CWnd object to use

//@mfunc void | SRGraphComponent | SetpDC | Sets the CDC object to be used to draw this component
//@parm CDC * | pDC | CDC object to use

//@mfunc void | SRGraphComponent | SetSignificantChange | Flags an important change in the data or parameters of this component

//@doc SRGraphComponent
//@mdata int  | SRGraphComponent | m_nBrushKey | Stores the most recently used brush key so that brushes are not created unneccesarily

//@doc SRGraphComponent
//@mdata int  | SRGraphComponent | m_nPenKey | Stores the most recently used pen key so that pens are not created unneccesarily

//@doc SRGraphComponent
//@mdata int  | SRGraphComponent | m_nPenWidth | Stores the width of the last used pen so that pens are not created and deleted unneccesarily

//@doc SRGraphComponent
//@mdata int  | SRGraphComponent | m_nSerializeVersion | Version number for serialization system

//@doc SRGraphComponent
//@mfunc void  | SRGraphComponent | SetPass | Sets the draw pass (0 or 1)
//@parm BOOL  | b | FALSE for pass 0, TRUE for pass 1


//@doc SRGraphComponent
//@mfunc BOOL  | SRGraphComponent | GetPass | Returns the draw pass (0 or 1)<nl>
//Pass 0 is usually a sizing pass.


//@doc SRGraphComponent
//@mfunc void  | SRGraphComponent | SetPMaster | Sets the pointer to the master component if this object is a subcomponent
//@parm SRGraphComponent  | *p | parm comment 


//@doc SRGraphComponent
//@mfunc SRGraphComponent  | SRGraphComponent | GetpMaster | Returns a pointer to the master component if this object is a subcomponent


//@doc SRGraphComponent
//@mfunc void  | SRGraphComponent | SetXMargin | Sets the size of the X margins
//@parm double | d | Device-independent margin size 


//@doc SRGraphComponent
//@mfunc void  | SRGraphComponent | SetYMargin | Sets the size of the Y margins
//@parm double  | d | Device-independent margin size 


//@doc SRGraphComponent
//@mfunc void  | SRGraphComponent | SetTickSize | Sets the size of the tick marks
//@parm double  | d | Tick mark size

//@doc SRGraphComponent
//@mdata BOOL  | SRGraphComponent | m_bPass | Current pass (0 or 1) -- pass 0 used to size the object, pass 1 draws it onto the DC

//@doc SRGraphComponent
//@mdata SRGraphComponent * | SRGraphComponent | m_pMaster | Pointer to the master component if this object is a subcomponent


//@doc SRGraphComponent
//@mfunc virtual void  | SRGraphComponent | DrawForeground | Does nothing in this basic component


//@doc SRGraphComponent
//@mfunc virtual CBitmap*  | SRGraphComponent | LoadCustomImage | Customization hook function called to load images not handled by the standard routines.


//@doc SRGraphComponent
//@mfunc UINT  | SRGraphComponent | GetType | Interrogates the type information for this component
//@rdesc UINT representing the type -- for example "background" or "legend"

//@doc SRGraphComponent
//@mfunc void | SRGraphComponent | SetMaxIndex | Sets the maximum index upon which this component should act
//@parm int | nIndex | Maximum index

//@doc SRGraphComponent
//@mfunc void |  SRGraphComponent | SetMinIndex | Sets the minimum index upon which this component should act
//@parm int | nIndex | Minimum index

//@doc SRGraphComponent
//@mfunc void | SRGraphComponent | SetMaxGroup | Sets the maximum group upon which this component should act
//@parm int | nGroup |Maximum group

//@doc SRGraphComponent
//@mfunc void | SRGraphComponent | SetMinGroup | Sets the minimum group upon which this component should act
//@parm int | nGroup | Minimum group

//@doc SRGraphComponent
//@mfunc int | SRGraphComponent | GetMaxIndex | Gets the maximum index upon which this component should act
//@rdesc Index as set by SetMaxIndex

//@doc SRGraphComponent
//@mfunc int | SRGraphComponent | GetMinIndex | Gets the minimum index upon which this component should act
//@rdesc Index as set by SetMinIndex

//@mfunc int | SRGraphComponent | GetMaxGroup | Gets the maximum group upon which this component should act
//@rdesc Group as set by SetMaxGroup

//@mfunc int | SRGraphComponent | GetMinGroup | Gets the minimum group upon which this component should act
//@rdesc Group as set by SetMinGroup

//@doc SRGraphComponent
//@mfunc void | SRGraphComponent | SetStyle | Initializes the m_Style member<nl>
//The m_Style member contains codes for panel fill style, border style and shadow style.
//@parm DWORD | style | The 32 bit component style data.<nl>
//@see <l Border styles>, <l Shadow styles>, <l Background styles> for available settings
//@rem These settings may be combined using a bitwise OR operator, but it is highly recommended 
//that you use the <mf SRGraphStyle::SetComponentBorderStyle>, <mf SRGraphStyle::SetComponentShadowStyle>, 
//and <mf SRGraphStyle::SetComponentFillStyle> member functions.




//@doc SRGraphComponent
//@mdata double  | SRGraphComponent | m_dXScreenToPrinterRatio | This retains the ratio of screen pixels to printed pixels for the X axis.

//@doc SRGraphComponent
//@mdata double  | SRGraphComponent | m_dYScreenToPrinterRatio | This retains the ratio of screen pixels to printed pixels for the Y axis.

//@doc SRGraphComponent
//@mdata CPen *  | SRGraphComponent | m_pAutoPen | This variable retains a pointer to the automatically created pen used to draw lines and outlines.

//@doc SRGraphComponent
//@mdata SRGraphLabel *  | SRGraphComponent | m_pLabel | This variable is used to hold a pointer to an SRGraphLabel object that is used in the data tagging system.

// adinsert Block for SRGraphComponent
//$head Component classes
//$level 1

//////////////////////////////////////////////////
//@doc SRGraphComponent 
//@class Base class for graphical components
//@base public | CObject
class SRGraphComponent :  public CObject
{
//@access protected data members
protected:
	//@cmember
	/* Most recently used brush key*/
	int m_nBrushKey;
	//@cmember
	/* Most recently used pen key*/
	int m_nPenKey;
	//@cmember
	/* Most recently used pen width*/
	int m_nPenWidth;
	//@cmember
	/* Current pass -- pre-draw sizing pass or actual drawing pass*/
	BOOL m_bPass;
	//@cmember
	/* Pointer to the master component -- used during drawing if the component is a */
	//subcomponent of another
	SRGraphComponent * m_pMaster;
	//@cmember
	/* Semaphore showing if a significant change has taken place either in this component or in the graph which owns it*/
	BOOL m_bSignificantChange;
	//@cmember
	/* List of SRGCompiledPolygons for this object*/
	CObList m_PolygonList; // NOTE This is going out of style!!
	//@cmember
	/* Integer localizing code for multi-lingual annotations*/
	int m_nCountryCode;
	//@cmember
	/* Semaphore showing if the use of hi-lo history data is required*/
	BOOL m_bHiLo;
	//@cmember
	/* Maximum index upon which this component should act (scope)*/
	int m_nMaxIndex;
	//@cmember
	/* Minimum index upon which this component should act (scope)*/
	int m_nMinIndex;
	//@cmember
	/* Maximum group upon which this component should act (scope)*/
	int m_nMaxGroup;
	//@cmember
	/* Minimum group upon which this component should act (scope)*/
	int m_nMinGroup;
	//@cmember
	/* Number of indices which this component may span*/
	int m_nDivCount;
	//@cmember
	/* Maximum index which this component may use*/
	int m_nMaxDiv;
	//@cmember
	/* Minimum index which this component may use*/
	int m_nMinDiv;
	//@cmember
	/* Number of groups which this component may span*/
	int m_nSetCount;
	//@cmember
	/* Minimum group*/
	int m_nMinSet;
	//@cmember
	/* Maximum group*/
	int m_nMaxSet;
	//@cmember
	/* Y scale calculated for this components range*/
	CScale m_ScaleY;
	//@cmember
	/* X scale calculated for this components range*/
	CScale m_ScaleX;
	//@cmember
	/* Device independent size for tick marks*/
	double m_dTickSize;
	//@cmember
	/* Device independent size for the Y margin*/
	double m_dMarginY;
	//@cmember
	/* Device independent size for the X margin*/
	double m_dMarginX;
	//@cmember
	/* Pen used to frame automatically framed objects*/
	CPen m_AutoPen;
	//@cmember
	/*  Brush used to fill automatically filled objects*/
	CBrush m_AutoBrush;
	//@cmember
	/* Device independent rectangle*/
	SRGraphRect m_Rect;
	//@cmember
	/* Index of the SRGraphData object being drawn -- used for automatic filling and framing*/
	int m_nCurrentIndex;
	//@cmember
	/* Drawing style flags*/
	SRGraphStyle m_Style;
	//@cmember
	/* Semaphore set when drawing is taking place*/
	BOOL m_bDrawing;
	//@cmember
	/* Pointer to the CWnd object which requested the drawing*/
	CWnd *m_pCWnd;
	//@cmember
	/* Pointer to the CDC of the window which requested the drawing*/
	CDC *m_pDC;
	//@cmember
	/* Pointer to the graph owning this object*/
	SRGraph * m_pParentGraph;
	//@cmember
	/* Component identifier -- used in reading, writing, and editing of graph templates*/
 	UINT m_nType;

	CBitmap* m_pImage;
	BOOL    m_bImageReady;

//@access public member functions
public:
	//@cmember
	/* (NEW 1.1) Sets the pass variable used for sizing or drawing*/
	inline void SetPass(BOOL b){m_bPass=b;}

	//@cmember
	/* (NEW 1.1) Retrieves the pass semaphore*/
	inline BOOL GetPass(){return (BOOL)m_bPass;}

	//@cmember
	/* (NEW 1.1) Sets the pointer to the master component*/
	inline void SetPMaster(SRGraphComponent *p){m_pMaster=p;}
	
	//@cmember
	/* (NEW 1.1) Retrieves a pointer to the master component*/
	inline SRGraphComponent * GetpMaster(){return m_pMaster;}

	//@cmember
	/* Initializes the X margin size*/
	inline void SetXMargin(double d){m_dMarginX=d;}
	
	//@cmember
	/* Initializes the Y margin size*/
	inline void SetYMargin(double d){m_dMarginY=d;}

	//@cmember
	/* Initializes the tick mark size*/
	inline 	void SetTickSize(double d){m_dTickSize=d;}

	//@cmember
	/* Draws custom borders*/
	virtual void DrawCustomBorder();

	//@cmember
	/* Draws custom shadows*/
	virtual void DrawCustomShadow();

	//@cmember
	/* Draws custom fills*/
	virtual void DrawCustomRgnFill(CRgn *rgn,SRGraphStyle *style,DWORD type,DWORD StyleOverride);

	//@cmember
	/* Sets a semaphore signifying a significant change in either the component or the graph which owns it*/
	inline void SetSignificantChange(){m_bSignificantChange=TRUE;}

	//@cmember
	/* Returns the minimum index which this component currently accesses*/
	inline int GetMinDiv(){return m_nMinDiv;}

	//@cmember
	/* Returns the maximum index which this component currently accesses*/
	inline int GetMaxDiv(){return m_nMaxDiv;}

	//@cmember
	/* Returns the minimum group which this component currently accesses*/
	inline int GetMinSet(){return m_nMinSet;}

	//@cmember
	/* Returns the maximum group which this component currently accesses*/
	inline int GetMaxSet(){return m_nMaxSet;}

	//@cmember
	/* Returns the Y scale range*/
	inline CScale &GetScaleY(){return m_ScaleY;}

	//@cmember
	/* Returns the X scale range*/
	inline CScale &GetScaleX(){return m_ScaleX;}

	//@cmember,mfunc
	/* Initializes the X scale range*/
	inline void SetScaleX(CScale v){m_ScaleX=v;}

	//@cmember,mfunc
	/* Initializes the Y scale range*/
	inline void SetScaleY(CScale v){m_ScaleY=v;}

	//@cmember
	/* Returns the number of groups which are spanned by this component*/
	inline const int GetSetCount(){return m_nSetCount;}

	//@cmember
	/* Returns the number of indices which are spanned by this component*/
	inline const int GetDivCount(){return m_nDivCount;}

	//@cmember
	/* Draws a wiget/line combination from one point to another in the style specified*/
	virtual void DrawPointObject(CPoint firstpoint,CPoint lastpoint,SRGraphStyle *ptrStyle,int nObjectMode, SRGraphData *pData = NULL);

	//@cmember
	/* Constructor*/
	SRGraphComponent();	

	//@cmember
	/*  Destructor*/
	virtual ~SRGraphComponent();	

	//@cmember
	/* Creates a brush which can be used for filling the interiors of objects according to an index*/
	virtual BOOL CreateAutoBrush(int key,int nColorRange=16);	

	//@cmember
	/* Creates a pen which can be used for framing the boundaries of objects according to an index*/
	virtual BOOL CreateAutoPen(int key,int nPenWidth=1,int nColorRange=16);	

	//@cmember	Retrieves
	/* pertinent data from the parent graph*/
	virtual void GetParentContent(); 

	//@cmember
	/* Interrogates the device independent Y margin value*/
	virtual double GetYMargin();

	//@cmember
	/* Interrogates the device independent X margin value*/
	virtual double GetXMargin();

	//@cmember
	/* Interrogates the device independent axis tick value*/
	virtual double GetTickSize();

	//@cmember
	/* Initializes the maximum index that a component may use*/
	inline 	void SetMaxIndex(int index)
	{
		m_nMaxIndex=index;
		m_bSignificantChange=TRUE;
	}


	//@cmember
	/* Initializes the maximum index that a component may use*/
	inline void SetMinIndex(int index)
	{
		m_nMinIndex=index;
		m_bSignificantChange=TRUE;
	}

	//@cmember
	/* Initializes the maximum group that a component may use*/
	inline void SetMaxGroup(int group)
	{
		m_nMaxGroup=group;
		m_bSignificantChange=TRUE;
	}

	//@cmember
	/* Initializes the minimum group that a component may use*/
	inline void SetMinGroup(int group)
	{
		m_nMinGroup=group;
		m_bSignificantChange=TRUE;
	}

	//@cmember
	/* Interrogates the maximum index setting*/
	inline int GetMaxIndex(){	return m_nMaxIndex;}

	//@cmember
	/* Interrogates the minimum index setting*/
	inline int GetMinIndex(){ return m_nMinIndex;}

	//@cmember
	/* Interrogates the maximum group setting*/
	inline int GetMaxGroup(){return m_nMaxGroup;}

	//@cmember
	/* Interrogates the minimum group setting*/
	inline int GetMinGroup(){return m_nMinGroup;}

	//@cmember
	/* Fetches the type of the component (ie. background, title, etc.)*/
	inline UINT GetType(){	return m_nType;}


	//@cmember
	/* Initializes the pointer to the SRGraph which owns this object*/
	virtual void SetParent(SRGraph *pParent);

	//@cmember
	/* Initializes the name of the bitmap resource used to tile the background*/
	virtual void SetResourceName(LPCTSTR name);

	//@cmember
	/* Initializes the m_Angle member*/
	virtual void SetAngle(int angle);

	//@cmember
	/* Initializes the RGB color values of the filled background*/
	virtual void SetColor(COLORREF a,COLORREF b);

	//@cmember,mfunc
	/* Retrieves the style of this object*/
	inline SRGraphStyle * GetStyle(){return &m_Style;}

	//@cmember
	/* Initializes the style of this object*/
	inline void SetStyle(DWORD style)
	{
		m_Style.SetComponentStyle(style);
	}


	//@cmember
	/* Initializes the device independant rectangle from a CRect*/
	virtual void SetRect(const CRect& r);

	//@cmember
	/* Initializes the device independant rectangle with floating point coordinates*/
	virtual void SetRect(double l, double t, double r, double b);

	//@cmember
	/* Initializes the device independant rectangle with the contents of a second*/
	virtual void SetRect(const SRGraphRect& r);

	//@cmember
	/* Retrieves a pointer to the device independant rectangle which defines the boundary of this object*/
	virtual SRGraphRect* GetRect();

	//@cmember
	/* Initializes the measurement mode of the m_Rect data member (0=pixels, 1=millimeters, 2=inches, 3=percentage)*/
	virtual void SetMeasurement(int m=PIXELS);

	//@cmember
	/* Called by the CWnd managing the display of graph data to draw the graph*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);

	//@cmember
	/* Fills a polygon held in an array of points according to a style*/
	virtual void FillPoly(LPPOINT points,int nCount,SRGraphStyle *style,DWORD StyleOverride);

	//@cmember
	/* Frames a polygon held in an array of points according to a style*/
	virtual void FramePoly(LPPOINT points,int nCount,SRGraphStyle *style,DWORD StyleOverride);

	//@cmember
	/* Frames a predefined region according to a style*/
	virtual void FrameRgn(CRgn *rgn,SRGraphStyle *style,DWORD type,DWORD StyleOverride);

	//@cmember
	/* Fills a predefined region according to a style*/
	virtual void FillRgn(CRgn *rgn,SRGraphStyle *style,DWORD type,DWORD StyleOverride=0);

	//@cmember
	/* Decides which areas of the display need to be invalidated after a CWnd::OnUpdate with a hint*/
	virtual void ProcessHint(CWnd *pCWnd);

	//@cmember
	/* Callback routine for the qsort function*/
	static int __cdecl qsSorterCompareA(const void *a,const void *b);

	//@cmember
	/* Callback routine for the qsort function.*/
	static int __cdecl qsSorterCompareD(const void *a,const void *b);

#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember
	/* Reads the parameters for this component from the template line*/
	virtual int ReadTemplateLine(LPCTSTR line);

	//@cmember
	/* Reads the basic rectangle and component fill, border, and shadow parameters for all components*/
	virtual int ReadBasicParameters(LPCTSTR line);

	//@cmember
	/* Writes the component to a template file*/
	virtual void WriteComponent(CStdioFile* file);

	//@cmember
	/* Writes this component name to a template file*/
	virtual void WriteName(CStdioFile* file);

	//@cmember
	/* Writes font details of this component to a template file*/
	virtual void WriteFontParameters(CStdioFile* file);

	//@cmember
	/* Writes the main details for this component to a template file*/
	virtual void WriteMainParameters(CStdioFile* file);

	//@cmember
	/* Writes specific details of this component to a template file*/
	virtual void WriteSpecificParameters(CStdioFile* file);

#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE

	//@cmember
	/* Callback routine for the qsort function -- used to order Y components for pie chart wedges into acending order*/
	static int _cdecl qsPointYSorterCompareA(const void *a,const  void *b);

	//@cmember
	/* Callback routine for the qsort function --  used to order Y components for pie chart wedges into decending order*/
	static int _cdecl qsPointYSorterCompareD(const void *a,const  void *b);

	//@cmember
	/* Returns the m_bHiLo semaphore*/
	inline BOOL GetHiLo(){return m_bHiLo;}

	//@cmember
	/* Initializes the m_bHiLo semaphore*/
	inline void SetHiLo(BOOL hilo=TRUE){m_bHiLo=hilo;}

	//@cmember
	/* Fetches the measurement mode from the m_Rect member*/
	inline int GetMeasurement(){return m_Rect.GetMeasurement();}

	//@cmember
	/* Initializes the m_pDC member*/
	inline void SetpDC(CDC *pDC){m_pDC=pDC;}

	//@cmember
	/* Interrogates the m_pDC member*/
	inline CDC * GetpDC(){return m_pDC;}

	//@cmember
	/* Initializes the m_pCWnd member*/
	inline void SetpCWnd(CWnd *pCWnd){m_pCWnd=pCWnd;}

	//@cmember
	/* Interrogates the m_pCWnd member*/
	inline CWnd * GetpCWnd(){return m_pCWnd;}

	//@cmember
	/*  Draws a line from ptStart to ptEnd in the desired style.*/
	virtual void DrawStyledLine(CPoint ptStart,CPoint ptEnd,SRGraphStyle *ptrStyle=NULL, int nKey=0,DWORD dwStyleOverride=0,SRGraphData *pData = NULL);

	//@cmember
	/* Draws bars for bar graphs*/
	virtual void DrawBar(CPoint topleft,CPoint bottomright, int group, int index,SRGraphStyle* ptrStyle,DWORD dwStyleOverride=0,SRGraphData *pData=NULL);

	//@cmember
	/* Moves a polygon stored as an array of CPoints by specified X and Y offsets*/
	virtual void OffsetPolygon(CPoint * points,int nPointCount, int xOffset,int yOffset);

	//@cmember
	/* Sets the m_nCountryCode member*/
	virtual void SetCountryCode(int c=1);

	//@cmember
	/* Interrogates the m_nCountryCode member*/
	virtual int GetCountryCode();

	//@cmember
	/* Interrogates the m_pParentGraph member*/
	inline SRGraph * GetParent(){return m_pParentGraph;}

	//@cmember
	/* Calculates the width and height of a given polygon from its points*/
	virtual CSize GetPolygonSize(CPoint * points,int nPointCount);

	//@cmember
	/* Calculates the length of the line between the two points*/
	double GetLineLength(CPoint ptStart,CPoint ptEnd);

	//@cmember
	/* Calculates the angle of ptEnd with respect to ptStart*/
	double GetLineAngle(CPoint ptStart,CPoint ptEnd);

	//@cmember
	/* Invalidates the m_bDrawing semaphore*/
	virtual void NotDrawing();

	//@cmember
	/* Informs a component that draw operations are taking place using a specific set of CWnd and CDC pointers*/
	virtual void DrawingUsing(CDC *pDC,CWnd *pCWnd);

	//@cmember
	/* Interrogates the m_bDrawing member*/
	virtual BOOL IsDrawing();

	//@cmember
	/* Draws a graphical token at a point on screen*/
	virtual void DrawWiget(CPoint point,SRGraphStyle *ptrStyle,SRGraphData *pData = NULL);

	//@cmember
	/* Override this function to load image from external file*/
	virtual CBitmap* LoadCustomImage();

	DECLARE_SERIAL(SRGraphComponent);

	//@cmember
	/* Stores or retrieves component information via a CArchive*/
	virtual void Serialize(CArchive& ar);

	//@cmember
	/* Returns the border thickness if a custom border is selected*/
	virtual int GetCustomBorderThickness();

	//@cmember
	/* Adjusts the rectangle for the current margins and border thicknesses*/
	virtual CRect AdjustRect(CRect r);

#ifdef _DEBUG

	void Dump(CDumpContext& dc) const;

#endif

//@cmember,menum
/* The measurement standard used in this rectangle*/
enum Measurement_type {
	PIXELS,			//@@emem No conversion. Data is in pixels
	MILLIMETERS,	//@@emem The floating point value is in millimeters.
	INCHES,			//@@emem The floating point value is in inches.
	PERCENT			//@@emem The value is a percentage of the available client area (Not currently implemented. Do not use)
	} ;


public:
	CRect CalcBounds(CPoint *pPoints,int nPointCount);
	void FillRgnEx(CRgn *pRgn,SRGraphStyle *pStyle, DWORD dwType, DWORD dwStyleOverride, CRect rcBound);
	//@cmember
	/* Returns a pointer to a pen that is newly created or that is already in the pen cache */
	CPen * GetPen(int nPenStyle,int nPenWidth,COLORREF PenColor);
	//@cmember
	/* Draws fancy line ends on lines and vectors*/
	virtual void DrawLineEnd(CPoint point,SRGraphStyle *ptrStyle, int nEnd, double dAngle);
	//@cmember
	/* Returns the ratio of screen pixels to printer pixels*/
	virtual double GetYScreenToPrinterRatio(CDC *pPrinterDC);
	//@cmember
	/* Returns the ratio of screen pixels to printer pixels*/
	virtual double GetXScreenToPrinterRatio(CDC *pPrinterDC);
	//@cmember
	/* Draws a data tag*/
	virtual void DrawTag(CPoint point,SRGraphData *pData);
	//@cmember
	/* Calls the parent graph's LoadPolygon function.*/
	virtual SRGCompiledPolygon *LoadPolygon(LPCTSTR strPolygonName,LPCTSTR strSectionName);
	//@cmember
	/* Returns FALSE*/
	virtual BOOL IsCompound();
	//@cmember
	/* Checks if specified data item is in scope*/
	virtual BOOL XGInScope(int nIndex, int nGroup);
	//@cmember
	/* Draws a simple dot object*/
	virtual void DrawDotObject(CPoint point,SRGraphStyle * ptrStyle, SRGraphData *pData=NULL);
	//@cmember
	/* Virtual function to draw custom point objects */
	virtual void DrawCustomPointObject(CPoint point,SRGraphStyle *ptrStyle,SRGraphData *pData = NULL);
	//@cmember
	/* Defines custom pen styles for the DrawStyledLine function*/
	virtual void GetCustomPenStyle(CPen ** pPen);
	//@cmember
	/* Returns the scope of this component */
	virtual SRGScope GetScope();
	//@cmember
	/* Initializes the scope with the provided data*/
	virtual void SetScope(SRGScope s);
	//@cmember
	/* Allows component initialization*/
	virtual void Initialize();
	//@cmember
	/* Sets the scope of the component*/
	virtual void SetScope(int nImin,int nImax,int nGmin,int nGmax);
	//@cmember
	/* Sets default margin sizes, etc*/
	virtual void SetSizeDefaults();
	//@cmember
	/* Returns the file version for individual components*/
	virtual int GetComponentFileVersion(CArchive &ar);
	//@cmember
	/* Sets the file version for individual components*/
	virtual CScale SetComponentFileVersion();
	//@cmember
	/* Rotates a point in two dimensions around the origin  */
	virtual CPoint RotatePoint(CPoint p,double dAngle,BOOL bUseRadians=TRUE);


	//@access protected member functions
protected:
	//@cmember
	/* Screen Width in pixel */
	int m_nLogPixelX;
	//@cmember
	/* Screen Height in pixel */
	int m_nLogPixelY;
	//@cmember
	/* The pointer to the auto pen.  */
	CPen * m_pAutoPen;
	//@cmember
	/* A pointer  */
	SRGraphLabel * m_pLabel;
	//@cmember
	/* Adjusts line style for highlighting*/
	virtual void HighlightLineStyle(SRGraphStyle *pStyle);
	//@cmember
	/* Allows modification of a style for highlighting a wiget*/
	virtual void HighlightWigetStyle(SRGraphStyle *pStyle);
	//@cmember
	/* Allows modification of a style for highlighting a bar*/
	virtual void HighlightBarStyle(int index,int group,SRGraphStyle *pStyle);
	//@cmember
	/* Used to extend the serialization system*/
	int m_nSerializeVersion;
	//@cmember
	/* Draws the filled background to this component (if any)*/
	virtual void DrawFill();
	//@cmember
	/* Draws the border to this component (if any)*/
	virtual void DrawBorder();
	//@cmember
	/* Override this virtual function to draw the forground content of this component (if any)*/
	virtual void DrawForeground(){}
	//@cmember
	/* Draws a shadow around this component (if any)*/
	virtual void DrawShadow();
};





#endif //__GRAPH_COMPONENT__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

