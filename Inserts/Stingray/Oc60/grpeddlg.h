//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes.
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////
//@doc
//@module GrpEdDlg.h | Interface for the SRGraphEditDialog class<nl>
//Copyright <cp>Stingray Software 1996.<nl>
//Written by Bob Powell ( www.stingray.com )
//
// using cmember tags only for these dialog classes
/////////////////////////////////////////////////////////////
//
// grpeddlg.h : header file
//
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif
/////////////////////////////////////////////////////////////////////////////
// SRGraphEditDialog dialog
#ifndef __SRGRAPHEDITDIALOG_H__
#define __SRGRAPHEDITDIALOG_H__

/////////////////////////////
// AutoDuck tag block for SRGraphEditDialog

// adinsert AutoDuck insertion point for SRGraphEditDialog 

//$head The Chart explorer
//$level 1

//@topic SRGraphEditDialog Class Overview |
//The components and data lists in the current graph are displayed in an expandable tree diagram. 
//When the user double-clicks a component, data list, or individual data item; 
//a dialog (property sheet) is displayed that allows many properties of the selected item to be changed.<nl>
//When the user right-clicks on an item, a popup menu appears that is specific to the item type. 
//Components can be added or deleted, loaded or stored to disk, or reordered. Annotations can be added to data items.

//@doc SRGraphEditDialog
//@class Part of Chart Explorer<nl>
//The components and data lists in the current graph are displayed in an expandable tree diagram. 
//When the user double-clicks a component, data list, or individual data item; 
//a dialog (property sheet) is displayed that allows many properties of the selected item to be changed.<nl>
//When the user right-clicks on an item, a popup menu appears that is specific to the item type. 
//Components can be added or deleted, loaded or stored to disk, or reordered. Annotations can be added to data items.
//@base public | CDialog
class SRGraphEditDialog : public CDialog
{
// Construction
public:
	//@cmember
	/* Displays the SRGraphComponentProperties dialog with pages appropriate for the type of the selected item*/
	virtual void OnEditDataItem();
	//@cmember
	/* Override this routine to add your own components*/
	virtual void AddCustomComponent(int Selection);
	//@cmember
	/* Builds an expandable tree diagram showing the components and data in the current graph*/
	virtual void BuildTree();
	//@cmember
	/* Constructor*/
	SRGraphEditDialog(CWnd* pParent = NULL);   // standard constructor

	enum ImageValues {
	GRAPH_SEL,
	GRAPH_NSEL,
	COMLIST_SEL,
	COMLIST_NSEL,
	COMPONENT_SEL,
	COMPONENT_NSEL,
	ANNOTATION_SEL,
	ANNOTATION_NSEL,
	DATALIST_SEL,
	DATALIST_NSEL,
	DATAITEM_SEL,
	DATAITEM_NSEL,
	VALUE_SEL,
	VALUE_NSEL
	} ;

// Dialog Data
	//{{AFX_DATA(SRGraphEditDialog)
	enum { IDD = SRG_IDD_GRAPHEDIT };
	//@cmember
	/* Tree diagram control*/
	SRGTreeCtrl	m_GraphTree;
	//}}AFX_DATA

	//@cmember
	/* Pointer to the graph being edited*/
	SRGraph *m_pGraph; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGraphEditDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//@cmember
	/* Data list item for tree diagram*/
	HTREEITEM m_DataListItem;
	//@cmember
	/* Component list item for tree diagram*/
	HTREEITEM m_ComponentListItem;
	//@cmember
	/* Root item for tree diagram*/
	HTREEITEM m_Root;
	//@cmember
	/* List of items in tree diagram*/
	CImageList m_ImageList;

	// Generated message map functions
	//{{AFX_MSG(SRGraphEditDialog)
	//@cmember
	/* Initializes dialog -- builds tree diagram*/
	virtual BOOL OnInitDialog();
	//@cmember
	/* Handles double-click on tree items -- displays editing dialog*/
	afx_msg void OnDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//@cmember
	/* Handles right-click on tree items -- displays popup menu*/
	afx_msg void OnRclickTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//@cmember
	/* Displays file selection dialog and loads the graph from the file*/
	afx_msg void OnLoadComponentList();
	//@cmember
	/* Saves a description of the graph in a disk file for reuse*/
	afx_msg void OnSaveComponentList();
	//@cmember
	/* Deletes the selected component from the graph*/
	afx_msg void OnDeleteComponent();
	//@cmember
	/* Displays property editing dialog for the selected component*/
	afx_msg void OnEditComponentProperties();
	//@cmember
	/* Adds a new component to the graph*/
	afx_msg void OnAddComponent();
	//@cmember
	/* Does nothing*/
	afx_msg void OnAddLabel();
	//@cmember
	/* Adds an annotation to a data item, data list, or component*/
	afx_msg void OnAddannotation();
	//@cmember
	/* Calls OnAddannotation*/
	afx_msg void OnLabelAddannotation();
	//@cmember
	/* Moves the selected item back one step in the list order*/
	afx_msg void OnIdBack1();
	//@cmember
	/* Moves the selected item forward one step in the list order*/
	afx_msg void OnIdForward1();
	//@cmember
	/* Moves the selected item to the top of the list order*/
	afx_msg void OnIdMovetotop();
	//@cmember
	/* Moves the selected item to the back of the list order*/
	afx_msg void OnIdSendtoback();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

