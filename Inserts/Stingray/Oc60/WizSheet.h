//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes.
// Written by Bob Powell and Chuanzhong Zhu (www.stingray.com)
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////
//
// SRGEWizSheet.h : interface of the SRGWizSheet class
//
/////////////////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#if !defined(_SRGEWizSheet_H_INCLUDED_)
#define _SRGEWizSheet_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block for SRGWizSheet 
//@doc SRGWizSheet

//@mdata CSize | SRGWizSheet | m_viewSize | Size of the drawing area of the chart passed to the constructor

//@mdata CRect | SRGWizSheet | m_Rect | Actual window rect of the view area

//@mdata SRGWizView* | SRGWizSheet | m_pGraphView | Pointer to a view object used to  display the chart

//@mdata CMainPage | SRGWizSheet | m_NewMain | The General page of the wizard

//@mdata CAdvancedPage  | SRGWizSheet | m_Advanced | The Other page of the wizard

//@mdata int | SRGWizSheet | m_nCurSelComponent | Index of the currently selected component in the combo box 
//in the General, Fill style, Font style pages

//@mdata BOOL | SRGWizSheet | m_bAllowTracking | Flag that allows components to be repostioned by dragging with the mouse

//@mdata CButton | SRGWizSheet | m_Next | Button member used to navigate preliminary layout-selection pages

//@mdata CButton | SRGWizSheet | m_Back | Button member used to navigate layout-selection pages

//@mdata SRGToolTipCtrl | SRGWizSheet | m_ToolTip | SRGToolTipCtrl object used to display information about wizard controls in tooltips

//@mdata CString | SRGWizSheet | m_strViewTip | Tooltip text for the view area

//@mdata CObArray | SRGWizSheet | m_Layouts | Stores all the layout information as an array of pointers to 
//CPtrArray objects, which in turn store a array of pointer to SRGLayoutInfo objects

//@mdata int  | SRGWizSheet | m_nCurIndex | The m_pLayout member uses this index to find layout information 
//to draw the graph of the available six image controls, the layout information of m_Layouts at this index will be used to draw
// the topleft corner image.

//@mdata DWORD | SRGWizSheet | m_nChartType | The graph type selected by the user from layout page -- CX_GRAPH_LINE by default


// adinsert AutoDuck insertion point for SRGWizSheet 

//$head The Chart wizard
//$level 1
//@doc SRGWizSheet 
//@class This class allows user to interactively configure their chart at runtime. When started, the class will make a copy of the 
// user's graph. Inside this wizard, all the modification is effective only on the copy of the graph. After exit from the wizard, 
// user's can call SaveGraph function to copy the modified graph inside the wizard back to the user's graph. If the graph user passed
// in does not contain any component, the wizard will start from three easy steps to help user choose a graph type with a basic layout to work with. If the 
// graph does contain some components, then the wizard will start right to the page to let user configurate their graphs
class SRGWizSheet : public CPropertySheet  
{
	DECLARE_DYNAMIC(SRGWizSheet)

public:
	// For compatibility with old wizard
	SRGWizSheet(SRGraph* pGraph, LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0, CSize viewSize = CSize(0, 0), BOOL bUseGraphData = TRUE);

protected:
	//@cmember
	/* Flag if the passed in graph has any component in it*/
	BOOL            m_bGraphEmpty;
	//@cmember
	/* The size of the drawing area of the chart given form the constructor*/
	CSize           m_viewSize;
	//@cmember
	/* Actual view port rectangle in the wizard*/
	CRect           m_Rect;    // View area rectangle
	//@cmember
	/* The drawing area of the wizard*/
	SRGWizView*  m_pGraphView;
	//@cmember
	/* The main setup page of the wizard*/
	CMainPage    m_NewMain;
	//@cmember
	/* The advanced setup page of the wizard.*/
	CAdvancedPage   m_Advanced;

	//@cmember
	/* The integer identifier of the currently selected component */
	int m_nCurSelComponent;

	//@cmember
	/* Set to TRUE if tracking is allowed. */
	BOOL         m_bAllowTracking;

	CButton             m_Next;
	CButton             m_Back;
	CLayoutPage*        m_pLayout;
	CStandardChartPage* m_pStdChart;
	CFinishPage*        m_pFinish;

	//@cmember
	/* A tool tip control to help to show some tip for some of the controls*/
	SRGToolTipCtrl        m_ToolTip;
	//@cmember
	/* ToolTip text for the view area*/
//	CString             m_strViewTip;

	//@cmember
	/* Store all the layout information*/
	CObArray            m_Layouts;
	//@cmember
	/* Graph type user selected from the Chart layout page*/
	DWORD               m_nChartType;
	//@cmember
	/* The current index of the layout information of the topleft image on */
	// the CLayoutPage in the m_Layouts array
	int                 m_nCurIndex;

	UINT				m_nTimerID;

public:
	virtual BOOL OnInitDialog();

	//@cmember
	/* Override this function to load custom created chart into the list box, by default, it does nothing*/
	virtual void LoadCustomStandChart(CListBox& listBox);
	//@cmember
	/* Load the all the standard chart type of Objective Chart into the lis tbox*/
	virtual void LoadStandardChart(CListBox& listBox);
	//@cmember
	/* Override this function to add custom layout, by default it does nothing*/
	virtual void LoadCustomLayout(CObArray& layoutInfo);
	//@cmember
	/* Load some default layout from resource.*/
	virtual void LoadLayout(LPCTSTR lpResName, LPCTSTR lpResType);

	//@cmember
	/* Fills the combobox from the specified resource file -- see <mf CMainPage::LoadGraphType>*/
	virtual void  LoadTypeResource(CComboBox& combo, LPCTSTR lpResName, LPCTSTR lpResType);
	//@cmember
	/* Override this function to add custom axis type*/
	virtual void LoadCustomAxisType(CComboBox& /*axisStyleCombo*/, DWORD /*dwGraphType*/){};
	//@cmember
	/* Load the supporting axis type based on the graph type selected*/
	virtual void FillAxisType();
	//@cmember
	/* Override this function to load custom graph types*/
	virtual void LoadCustomGraphType(CComboBox& /* graphStyleCombo*/);
	//@cmember
	/* Load the standard graph types*/
	virtual void LoadGraphType(LPCTSTR lpResName, LPCTSTR lpResType);

	//@cmember
	/* Override this function to load a custom axis type*/
	virtual void SetCustomAxisStyle(SRGraphDisplay* pDisplay, DWORD dwAxisStyle);
	//@cmember
	/* Override this function to load a custom graph type*/
	virtual void SetCustomGraphStyle(SRGraphDisplay* pDisplay, DWORD dwGraphStyle);

	//@cmember
	/* Sets the graph type for the display component according to user selection*/
	virtual void SetGraphStyle(SRGraphDisplay* pd);
	//@cmember
	/* Sets the axis type for the display component according to user selection*/
	virtual void SetAxisStyle(SRGraphDisplay* pd);
	//@cmember
	/* Setup the specified page of the graph*/
	virtual void SetupGraph(UINT nWhichPage);
	//@cmember
	/* Called to delete a component from the list.*/
	virtual void OnDeleteComponent();

	//@cmember
	/* Destructor */
	virtual ~SRGWizSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(SRGWizSheet)
	//@cmember
	/* Handles SC_CLOSE message to prevent unintentional termination of the wizard*/
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	
	//@cmember
	/* Message handler, called when the Apply button is clicked -- only applies changes */
	//in the active page
	afx_msg void OnApplyNow();
	//@cmember
	/* Message handler called when click OK button in the wizard.*/
	afx_msg void OnOK();
	//@cmember
	/* Message handler, called when the user selects a different component the combobox -- */
	//updates the controls in the property pages according to the component selected by user
	afx_msg LRESULT OnChangeComponentType(WPARAM, LPARAM);
	//@cmember
	/* Message handler, called when the user changes the graph type from the main page*/
	afx_msg LRESULT OnChangeGraphType(WPARAM wParam, LPARAM lParam);
	//@cmember
	/* Message handler, called when the user changes the axis type of the chart.*/
	afx_msg LRESULT OnChangeAxisType(WPARAM wParam, LPARAM lParam);

	//@cmember
	/* Message handler, called when user change the component name in the component list*/
	afx_msg LRESULT OnChangeComponentName(WPARAM wParam, LPARAM lParam);
	//@cmember
	/* Message handler, called when any property page changes a graph setting that */
	//requires the graph to be redrawn
	afx_msg LRESULT OnNeedRedraw(WPARAM wParam, LPARAM lParam);

	afx_msg void OnNextButton();
	afx_msg void OnBackButton();

	DECLARE_MESSAGE_MAP()

	//@cmember
	/* Fill Style setup page*/
	CFillStyle  m_FillPage;
	//@cmember
	/* Font Style setup page*/
	CFontStyle m_FontPage;

public:
	//@cmember
	/* Wizard call this function to decide whether to prevent user from modifying the*/
	// setting of this component
	virtual BOOL EnableGeneralSetting(SRGraphComponent* gc);
	//@cmember
	/* Wizard call this function to decide whether to prevent user from modifying the*/
	// the filling setting of this component
	virtual BOOL EnableFillSetting(SRGraphComponent* gc);
	//@cmember
	/* Wizard call this function to decide whether to prevent user from modifying the*/
	// the font settting of this component
	virtual BOOL EnableFontSetting(SRGraphComponent* gc);
	//@cmember
	/* Register some of the controls on the pages to have tool*/
	virtual void RegisterToolTips();
	//@cmember
	/* Move component from one place to another.*/
	virtual void OnReArrangeComponent(int nSrcIndex, int nDestIndex);
	//@cmember
	/* Override this function to add user derived component to the available */
	// components list that the user can add to the graph.
	virtual void AddCustomComponents(SRGComboBox& combo);
	//@cmember
	/* Switch between view with scroll bar or not*/
	virtual void SwitchView(BOOL bUseScroll);
	//@cmember
	/* Add the component with the given name to the graph*/
	virtual void AddToComponentComboBox(LPCTSTR lpszName, SRGraphComponent* pc);
	//@cmember
	/* Adds a new property page to the sheet and optionally set the caption for its tab*/
	void AddPage(CPropertyPage* page, LPCTSTR lpszCaption = NULL);
	//@cmember
	/* Copies the graph and its data using CSharedFile serialization*/
	virtual void CopyGraph(SRGraph* pFromGraph, SRGraph* pToGraph, BOOL bCopyData = TRUE);
	//@cmember
	/* Saves the local copy of the graph configuration to the user suppied graph object without modifying the user's data*/
	virtual void SaveGraph(BOOL bSaveGraphData = FALSE);
	//@cmember
	/* Initializes the property pages from the settings of the user supplied graph*/
	virtual BOOL InitializePages();
	//@cmember
	/* Sets the shadow style bits in a SRGraphStyle object*/
	void SetShadowStyle(SRGraphStyle* pStyle, UINT nType);
	//@cmember
	/* Sets a component's style from the selections in the Main page -- called */
	//when user modifies any setting or presses the Apply button
	void SetMainPageOf(SRGraphComponent* gc);
	//@cmember
	/* Setup the font style of the component from the settings in the Font Style page*/
	void SetFontStyleOf(SRGraphComponent* pc);
	//@cmember
	/* Setup the fill style of the component from the settings in the Fill Style page*/
	void SetFillStyleOf(SRGraphComponent* pc);

protected:
	//@cmember
	/* Create a name for this component that will be visible in the component list of */
	// graph. This function will prevent the name collision.
	virtual CString GetComponentName(SRGraphComponent* gc);
	//@cmember
	/* Create a new suffix to prevent the name collision.*/
	virtual CString GetNewSuffix();
	//@cmember
	/* Show or hide the controls related to the scope settings depending on the type */
	// of component.
	virtual void ShowScopeSection(BOOL bShow);
	CStatic m_Dummy;
	// This varible is just used to identity the component in the graph.
	CString m_strDummy;
	
	//@cmember
	/* Add the user selected component to the graph.*/
	virtual void OnAddComponent();
	//@cmember
	/* Initializes the controls in the Main page that are common to all components*/
	void InitMainPage(SRGraphComponent* gc);
	//@cmember
	/* Sets the controls of the fill style page from the component data*/
	void InitFillPage(SRGraphComponent* pc);
	//@cmember
	/* Sets the controls of the font style page from the component data*/
	void InitFontPage(SRGraphComponent* pc);

	//@cmember
	/* Pointer to store the address of the user supplied graph*/
	SRGraph*   m_pRemoteGraph;  
	//@cmember
	/* Local copy of the user's graph*/
	SRGraph*  m_pGraph;

	//@cmember
	/* Flag indicate whether the wizard will use the data of the passed graph or generate dummy data */
	BOOL      m_bUseOutData;

	friend class CMainPage;
	friend class CFillStyle;
	friend class CFontStyle;
	friend class CAdvancedPage;
	friend class CLayoutPage;
	friend class CStandardChartPage;
	friend class CFinishPage;
	friend class SRGWizView;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(_SRGEWizSheet_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


