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
//@doc CObStack
//@module ObStack.h | CObStack header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)
/////////////////////////////////////////////////////////////
//
// ObStack.h: interface for the CObStack class.
//
//////////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#if !defined(AFX_OBSTACK_H_INCLUDED_)
#define AFX_OBSTACK_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//$head Utility classes
//$level 1

/////////////////////////////
// AutoDuck tag block block for CObStack 

// adinsert AutoDuck insertion point for CObStack 
//@doc CObStack 
//@class This class implements a push-pop style first-in-last-out stack.
//@base public | CObList
class CObStack : public CObList  
{
public:
	//@cmember
	/* Remove the top item from the stack and return it*/
	virtual CObject * Pop();
	//@cmember
	/* Place an item on the top of the stack*/
	virtual POSITION Push(CObject * pObject);
	//@cmember
	/* Default constructor*/
	CObStack();
	//@cmember
	/* Destructor*/
	virtual ~CObStack();

};



#endif // !defined(AFX_OBSTACK_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

