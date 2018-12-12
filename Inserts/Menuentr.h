
// This file defines the CMenuEntry and CMenuEntryArray classes
// Many functions are inlined for efficiency.  The CMenuEntry class
// simply holds data describing a menu entry, while CMenuEntryArray
// is a CArray template class specialization that allows a collection
// of menu entries.

#if !defined(AFX_MENUENTRY_H__81771142_D3AE_11D2_95C4_0000C0F3C6B2__INCLUDED_)
#define AFX_MENUENTRY_H__81771142_D3AE_11D2_95C4_0000C0F3C6B2__INCLUDED_


class CMenuEntry : public CObject
{
	// implementation
	DECLARE_SERIAL(CMenuEntry)
public:
	CMenuEntry(CMenuEntry& ref);
	CMenuEntry(LPCTSTR pstrCaption, LPCTSTR pstrFlyby, LPCTSTR pstrText, int nID);
	CMenuEntry() { m_nAttributes = 0; m_nID = 0; }
	~CMenuEntry() { }

	void Serialize(CArchive& ar);

	// interface
public:
	BOOL IsChecked() const { return ((m_nAttributes & MF_CHECKED) == MF_CHECKED); }
	BOOL IsEnabled() const { return !((m_nAttributes & MF_DISABLED) == MF_DISABLED); }
	BOOL IsSeparator() const { return ((m_nAttributes & MF_SEPARATOR) == MF_SEPARATOR); }

	void SetChecked(BOOL b = TRUE) { m_nAttributes = b ? (m_nAttributes | MF_CHECKED) :
														(m_nAttributes & ~MF_CHECKED); }

	void SetSeparator(BOOL b = TRUE) { m_nAttributes = b ? (m_nAttributes | MF_SEPARATOR) :
														(m_nAttributes & ~MF_SEPARATOR); }

	void SetEnabled(BOOL b = TRUE) { m_nAttributes = b ? (m_nAttributes & ~MF_DISABLED ) :
														(m_nAttributes | MF_DISABLED); }

	CMenuEntry& operator=(const CMenuEntry& ref);

	CString GetCaption() const;

	CString	m_strCaption;
	CString m_strFlyby;
	CString m_strText;
	UINT m_nAttributes;
	int m_nID;

protected:
#ifdef _DEBUG
	void Dump(CDumpContext& dc) const;
#endif
};

void AFXAPI DestructElements(CMenuEntry* pCurrent, int nCount);
void AFXAPI ConstructElements(CMenuEntry* pCurrent, int nCount);
void AFXAPI SerializeElements(CArchive& ar, CMenuEntry* pCurrent, int nCount);

typedef CArray<CMenuEntry, CMenuEntry&> CMenuEntryArray ;

#endif // !defined(AFX_MENUENTRY_H__81771142_D3AE_11D2_95C4_0000C0F3C6B2__INCLUDED_)
