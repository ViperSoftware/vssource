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
//@doc
//@module GraphDoc.h| interface of the CGraphDoc class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)
/////////////////////////////////////////////////////////////
//
// GraphDoc.h : interface of the CGraphDoc class
//
/////////////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef __GRAPHDOC_H__
#define __GRAPHDOC_H__

// Document subcodes for processing data via the SECComDoc linking system

#define OGRIDDOC_CMND_NOOP			0x00000000	// No-Ops are always zero
#define OGRIDDOC_CMND_CELLVALUE		0x00000100	// Grid commands are kept away from graph commands



/////////////////////////////
// AutoDuck tag block for CGraphDoc

// adinsert AutoDuck insertion point for CGraphDoc 

//@doc CGraphDoc
//$head Document classes
//$level 1
//@mdata SRGraph | CGraphDoc | m_Graph | The chart object

//@class Manages linked document operations for the SRGraphView class
//@rem This file is optional and it is not required for the normal operation 
//of the Objective Graph kit.
//@base public | SECComDoc
class CGraphDoc : public SECComDoc
{
protected: // create from serialization only
	//@cmember
	/* Constructor*/
	CGraphDoc();
	DECLARE_DYNCREATE(CGraphDoc)

// Attributes
public:
	//@cmember
	/* Initializes a document with data stored in global memory*/
	virtual BOOL GmemInit(UINT code,HANDLE hMem);

	//@cmember
	/* The graph object*/
	SRGraph m_Graph;	 

// Operations
public:

	//@cmember
	/* Update the document*/
	int SecDocUpdate(UINT nSubCode,DWORD dwData);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphDoc)
	public:
	//@cmember
	/* New document handler*/
	virtual BOOL OnNewDocument();
	//@cmember
	/* Serialization*/
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	//@cmember
	/* Destructor*/
	virtual ~CGraphDoc();

#ifdef _DEBUG
	//@cmember,mfunc
	/* Debug*/
	virtual void AssertValid() const;
	//@cmember,mfunc
	/* Debug*/
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



#endif // __GRAPHDOC_H__

/////////////////////////////////////////////////////////////////////////////
// Reset DLL declaration context

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

