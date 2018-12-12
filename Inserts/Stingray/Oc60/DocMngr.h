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

////////////////////////////////////////////////
//@doc
//@module DocMngr.h | implementation file for the SECDocManager class<nl>
//Adds functionality to the default OnFileNew behavior
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SECDOCMANAGER__
#define __SECDOCMANAGER__

//$head The "ComDoc" system
//$level 1
//@class Stingray Document Manager class -- inherits behaviors from the standard CDocManager class 
//and adds the ability to open and link <c SECComDoc> documents
class SECDocManager : public CDocManager
{
public:
	//@cmember
	/* File creation function with parameters to allow a document to begin some process immediately and without user intervention*/
	virtual CDocument *OnFileNew(LPCTSTR DocIdent, UINT nOpCode,UINT nSubCode=0, DWORD dwData=NULL,SECComDoc *parent=NULL);
	
	//@cmember
	/* Constructor*/
	SECDocManager();

	//@cmember
	/* File creation function with a choice of document type and parameter passing to empty documents*/
	void OnFileNew(LPCTSTR DocIdent,LPCTSTR Params=NULL,SECComDoc *parent=NULL);

	//@cmember
	/* Standard behavior*/
	void OnFileNew();

};




#endif
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

