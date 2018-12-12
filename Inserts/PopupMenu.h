// PopupMenu.h: interface for the CPopupMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPUPMENU_H__C171C452_E054_4353_AB86_C263AC6AF61C__INCLUDED_)
#define AFX_POPUPMENU_H__C171C452_E054_4353_AB86_C263AC6AF61C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\MenuEntr.h"

class CPopupMenu  
{
public:
	CPopupMenu();
	virtual ~CPopupMenu();

	void		AddEntry(CMenuEntry& Entry);
	void		SetScriptInfo(const char *path, long start);
	void		GetScriptInfo(CString &path, long &start);
	int			GetIDAssignment() { return ++m_nMaxID; }
	CMenuEntry* GetEntryFromID(int nID);
	void		GetMenuStr(int nID, CString& rStr);
	BOOL		IDInCustomRange(int nID) const;
	BOOL		ShowContextMenu(CWnd *pWnd, CPoint point);
	void		Activate();
	HMENU		GetHMENU();
	int			OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo); 

protected:
	CMenuEntryArray m_arMenuEntries;
	int				m_nMaxID;
	int				m_nMinID;
	CString			m_ScriptsPath;
	long			m_startScripts; // file position to first line following

	CMenu	m_Menu;
	BOOL	m_bMenuLoaded;

};

#endif // !defined(AFX_POPUPMENU_H__C171C452_E054_4353_AB86_C263AC6AF61C__INCLUDED_)
