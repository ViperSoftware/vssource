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
// SRGComboBox.h : header file
//
//////////////////////////////////////////////////////////////
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#if !defined(_SRGCOMBOBOX_H_INCLUDED_)
#define _SRGCOMBOBOX_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block for SRGraphItemData
// adinsert AutoDuck insertion point for SRGraphItemData
//@doc SRGraphItemData
//@struct SRGraphItemData | The SRGraphItemData structure combines a DWORD value and a string into a single object. 
//It is used by the wizard to associate a resource ID and a resource file name with an item in a list box.
struct SRGraphItemData
{
	DWORD    id;			//@field Resource ID
	CString  axisResName;	//@field Resource file name string

	//@cmember
	/* Constructor with parameters*/
	SRGraphItemData(DWORD value, LPCTSTR lpResName)
	{
		id = value;
		axisResName = lpResName;
	}
};


/////////////////////////////
// AutoDuck tag block for SRGComboBox 




// adinsert AutoDuck insertion point for SRGComboBox 

//$head The Chart Wizard
//$level 1

//@doc SRGComboBox 
//@class SRGComboBox is an extension of CComboBox with several useful utility functions.<nl>
//Several functions assume that the 32-bit value associated with each combobox item is a 
//pointer to an SRGraphItemData object.
class SRGComboBox : public CComboBox
{
// Construction
public:
	//@cmember
	/* Constructor*/
	SRGComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SRGComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual BOOL ReplaceItemString(int nIndex, LPCTSTR lpszNew);
	//@cmember
	/* Remove the item with index nSrcIndex and insert it before*/
	// the item with index nDestIndex.
	virtual void RePositionItemAndData(int nSrcIndex, int nDestIndex);
	//@cmember
	/* Replaces the data dwOld with the data dwNew. Every item */
	//with data dwOld will have its data be replaced.
	virtual void ReplaceItemData(DWORD dwOld, DWORD dwNew);
	//@cmember
	/* Searches the items in the combobox for one that has the specified resource ID */
	//in its associated SRGraphItemData object -- if such an item is found, it becomes the current selection
	virtual int SetCurSelByPtrData(DWORD dwValue);
	//@cmember
	/* Deletes the item from the combobox that has the specified resource ID */
	//in its associated SRGraphItemData object
	virtual void DeleteItemByData(DWORD dwItemData);
	//@cmember
	/* Adds a string to the combobox and sets the 32-bit value associated with the item to the specified value*/
	int AddStringData(LPCTSTR lpszString, DWORD dwItemData);
	//@cmember
	/* Searches the items in the combobox for one that has the specified value */
	//in its associated 32-bit data -- if such an item is found, it becomes the current selection
	int SetCurSelByData(DWORD dwValue);
	//@cmember
	/* Returns the 32-bit value associated the currently selected item or CB_ERR*/
	virtual		DWORD GetCurItemData();
	//@cmember
	/* Destructor*/
	virtual ~SRGComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(SRGComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(_SRGCOMBOBOX_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

