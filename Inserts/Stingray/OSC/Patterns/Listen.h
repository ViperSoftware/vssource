/////////////////////////////////////////////////////////////////////////////
// listen.h : Declaration of SECWndListener
//
// Stingray Software Extension Classes
// Copyright (C) 1997 Stingray Software Inc,
// All rights reserved.
//
// This source code is only intended as a supplement to
// the Objective Toolkit Class Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding
// the Objective Toolkit product.
//
// Author:       Mark Isham
// Description:  Declaration of SECWndListener
//
// $Header: $
// $NoKeywords: $

//
// SECWndListener
// This class implements the ability to attach to an existing CWnd and link 
// to its internal message queue via the standard subclassing mechanism.

#ifndef __SECWndListener_H__
#define __SECWndListener_H__

// Header Includes

//
// CMN Extension DLL
// Initialize declaration context
//
#ifdef _CMNDLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA    CMN_DATAEXT
#endif //_CMNDLL

// Constants

// Macros

// Types

// Forward Declarations


//@doc SECWndListener
//@mfunc WNDPROC  | SECWndListener | GetOldWndProc | Gets a pointer to the WNDPROC associated with this window listener.
//@xref <c SECWndListener>

//@doc SECWndListener
//@mfunc DLGPROC  | SECWndListener | GetOldDlgProc | Gets a pointer to the DLGPROC associated with this window listener.
//@xref <c SECWndListener>

class SECWndListener;	// forward


// Type-safe pointer list of window listener objects (to be associated with each HWND)
typedef CTypedPtrList<CPtrList,SECWndListener*> SECWndListenerList;

// This struct contains info to be associated with each HWND in the ptr map below.
typedef struct SECWndListener_MsgProcInfo_tag {
	// Pointer to the original WNDPROC/DLGPROC for the associated HWND
	UINT size;				// sizeof this struct. For error detection.
	WNDPROC lpfnWndProc;	// 1 or the other, not both!
	DLGPROC lpfnDlgProc;
	SECWndListenerList* pListenerList;
}	SECWndListener_MsgProcInfo;

// Map each HWDN to its unique information struct containing WNDPROC/DLGPROC info
typedef CTypedPtrMap<CMapPtrToPtr,HWND,SECWndListener_MsgProcInfo*> SECHWndToWndListenerListMap;

// Bitflags for SetMessageHandle call
#define SEC_LISTENER_PROCESSNORMAL		0x0000 // continue normal chained processing
#define SEC_LISTENER_HANDLED_LISTENERS	0x0001 // do not forward msg to any more chained listeners
#define SEC_LISTENER_HANDLED_WINDOW		0x0002 // do not forward msg to original window
#define SEC_LISTENER_HANDLED_ALL		0x00ff // stop all processing for this msg (listenrs + orig window)

/////////////////////////////////////////////////////////////////////////////
// SECWndListener

//@doc SECWndListener 
//@class Window Listener base class
//@base public | SECWndPlugIn
class SECWndListener : public SECWndPlugIn
{
	DECLARE_DYNAMIC(SECWndListener);

	//---------------------------------------------------------------------//
	// 						   Public Interface							   //
	//---------------------------------------------------------------------//
public:

	// Initialization/Destruction
	SECWndListener();
	virtual ~SECWndListener();

	virtual BOOL AttachWnd(CWnd* pWnd,BOOL bDialogProc=TRUE)
		{ bDialogProc;	// unused (provided for back. compat.)
		  return PlugInTo(pWnd); }

	// Attributes
	//	...Publicly accessible member variables...

	// Accessors
	//	...Get and Set functions...			

	// NOT IMPLEMENTED FOR THIS DERIVED CLASS! Use SetMessageHandleStatus instead!
	virtual void SetMessageHandled(BOOL) { ASSERT(FALSE); }

	virtual void SetMessageHandleStatus(DWORD dwHandledType);
	DWORD GetMessageHandleStatus() 					{ return m_dwMsgHandledType; }
	void ClearMessageHandleStatus()					{ m_dwMsgHandledType=SEC_LISTENER_PROCESSNORMAL; }

	// Operations
	virtual BOOL PlugInTo( CWnd* pWnd);
	virtual void UnPlug();

	//---------------------------------------------------------------------//
	// 							 Overridables							   //
	//---------------------------------------------------------------------//
protected:
	//@cmember
	/* Override this to "listen" for a particular message*/
	virtual BOOL OnSubclassMessage(UINT Message,WPARAM wParam,LPARAM lParam);

	//@cmember
	/* Override this to "listen" for a particular message*/
	virtual BOOL OnSubclassMessage(UINT Message,WPARAM wParam,LPARAM lParam,LRESULT& lResult);

	//---------------------------------------------------------------------//
	// 						Protected Implementation					   //
	//---------------------------------------------------------------------//
protected:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SECWndListener)
	//}}AFX_VIRTUAL

	// Implementation Member Variables
	DWORD m_dwMsgHandledType;
	HWND m_hWndCached;

	// Implementation Member Functions

	virtual BOOL SubclassAttached(CWnd* pWnd);
	virtual BOOL AddListenerEntry(SECWndListener_MsgProcInfo* pProcInfo);
	virtual BOOL SubclassNewListenerEntry(HWND hWndListen);
	virtual BOOL IsWindowProc(HWND hWndListen);
	virtual BOOL UnSubclassAttached();

	// Static callback functions. These dish off to actual instances of SECWndListener,
	// as is mapped via m_mapHwndToListenerList 
	static LONG FAR PASCAL SubclassWndProc(HWND hWnd,UINT Message,WPARAM wParam,LPARAM lParam);
	static LONG FAR PASCAL SubclassDlgProc(HWND hWnd,UINT Message,WPARAM wParam,LPARAM lParam);
	static LONG FAR PASCAL SubclassProc(HWND hWnd,UINT Message,WPARAM wParam,
										LPARAM lParam,BOOL bWndProc);
	static LONG FAR PASCAL UnplugAllListeners(HWND hWnd,UINT Message,WPARAM wParam,
										LPARAM lParam,BOOL bWndProc);

	// Map a C-Style message callback to an actual C++ window listener object.
	static SECHWndToWndListenerListMap m_mapHwndToListenerList;

	//---------------------------------------------------------------------//
	// 						  Base Class Overrides						   //
	//---------------------------------------------------------------------//

	//---------------------------------------------------------------------//
	// 						Message Map Declarations					   //
	//---------------------------------------------------------------------//

	// Generated message map functions
	//{{AFX_MSG(SECWndListener)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//---------------------------------------------------------------------//
	// 						Private Implementation						   //
	//---------------------------------------------------------------------//
private:
};

/////////////////////////////////////////////////////////////////////////////

//
// CMN Extension DLL
// Reset declaration context
//

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR


#endif //__SECWndListener_H__

