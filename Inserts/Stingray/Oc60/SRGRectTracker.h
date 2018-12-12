// SRGRectTracker.h: interface for the SRGRectTracker class.
//
//////////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRECTTRACKER_H__
#define __SRGRECTTRACKER_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxext.h>

/////////////////////////////
// AutoDuck tag block block for SRGRectTracker 

//$head The Chart Wizard
//$level 1


// adinsert AutoDuck insertion point for SRGRectTracker 
//@doc SRGRectTracker 
//@class Extention class of CRectTracker, this class added a new CWnd member
// whenever the rect changed size it send out a WM_TRACKINGRECTCHANGED message
// to the CWnd member, when it adjust its rect it also send out a WM_ADJUSTTRACKINGRECT
// message to CWnd member so that the CWnd member get a chance to do something
// if it choose to.
class SRGRectTracker : public CRectTracker  
{
public:
	//@cmember
	/* Send a WM_ADJUSTTRACKINGRECT message to its parent before call*/
	// the base class AdjustRect function
	virtual void AdjustRect( int nHandle, LPRECT lpRect );
	//@cmember
	/* Send a WM_TRACKINGRECTCHANGED message to its parent before call*/
	// the base class OnChangedRect function
	virtual void OnChangedRect(const CRect & rectOld);
	SRGRectTracker(CWnd* pParent = NULL);
	virtual ~SRGRectTracker();

	CWnd* m_pParent;
};

#endif // __SRGRECTTRACKER_H__

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

