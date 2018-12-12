// splitter.h : header file
//
#ifndef __MFCWIN_SPLITTER_H_
#define __MFCWIN_SPLITTER_H_
/////////////////////////////////////////////////////////////////////////////
// CSplitter frame with splitter

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CSplitter : public CSplitterWnd
{
	DECLARE_DYNCREATE(CSplitter)

public:
   	CSplitter();

protected:
     int m_nHidedCol;  // hided column number, -1 if all columns are shown

public:
    void ShowColumn();
    void HideColumn(int colHide);
      
// Operations
public:
    BOOL ReplaceView(int row, int col,CRuntimeClass * pViewClass,SIZE size);
    BOOL HideView(int row, int col);
    BOOL ShowView(int row, int col);

// Implementation
public:
	virtual ~CSplitter();

	// Generated message map functions
	//{{AFX_MSG(CSplitter)
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

class C3WaySplitter
{
friend class CApp3WaySplitterFrame;
public:
	C3WaySplitter();
	virtual ~C3WaySplitter();

protected:
   CString            m_CurrentAppName;
   CFrameWnd          *m_pFrame;		// frame this splitter is inside
   CSplitter          m_wndSplitter;
   CSplitter          m_wndSplitter2;
   CRect              m_SplitterLoc;

public:
	void Init();
   // Methods
   // splitters are arranged differently and different views are created based
   // on the application
   void RearrangeSplitters(const char *AppName);
   BOOL SaveSplitterLocation(const char *AppName);
   CRect GetSplitterLocation(const char *AppName);
   void ArrangeSplitterNow();

};

#endif //__MFCWIN_SPLITTER_H_