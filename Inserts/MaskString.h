// MaskString.h: interface for the CMaskString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MASKSTRING_H__A426DBCA_62AC_4595_A19F_396765EB5E31__INCLUDED_)
#define AFX_MASKSTRING_H__A426DBCA_62AC_4595_A19F_396765EB5E31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define LITERAL_SENTINEL    128

class CMaskString  
{
public:
	CMaskString();
	virtual ~CMaskString();

    /* Sets the display mask for the string.*/
    BOOL SetMask(LPCTSTR lpszMask);

	/* Puts data into the masked string.*/
    BOOL SetData(const CString& strData, 
						int nStartPos = 0, 
						BOOL bInsert = FALSE,
						BOOL bIgnorePromptChars = TRUE);

	/* Retrieves the data from the masked edit with all literal */
	// characters intact.
    CString& GetRawData(void) {return m_strDisplay;}

	/* Retrieves data from the masked edit and strips out the */
	// literals and spaces if specified.
    void GetData(CString& strData, BOOL bTrim = FALSE);

protected:
	CString m_strMask;
	CString m_strDisplay;
    TCHAR	m_chPrompt;

	//@cmember
	/* Determines if a character is valid for the specified position.*/
    BOOL IsCharValid(int nPos, TCHAR& ch);

	//@cmember
	/* Determines if a character is a literal character.*/
    BOOL IsLiteralChar(TCHAR ch);

	//@cmember
	/* Determines if a character is a mask character.*/
    BOOL IsMaskChar(TCHAR ch);
    
	//@cmember
	/* Updates the string displayed in the control based on the current mask.*/
    void UpdateDisplayStr();

// Implementation - mask operations

	//@cmember
	/* Given a mask, returns a displayable string based on the current*/
	// prompt character.
	void ConvertMaskToDisplayStr(CString strMask,CString& strResult);

	//@cmember
	/* Parses the mask string.*/
    void ParseMaskString();

	//@cmember
	/* Retrieves the next data position relative to a given position.*/
    virtual int GetNextDataPos(int nOldPos);

	//@cmember
	/* Retrieves the previous data position relative to a given position.*/
    virtual int GetPrevDataPos(int nOldPos);

	//@cmember
	/* Inserts a character, and optionally refreshes the display.*/
    virtual BOOL PushChar(int nStartPos, TCHAR ch);

};

#endif // !defined(AFX_MASKSTRING_H__A426DBCA_62AC_4595_A19F_396765EB5E31__INCLUDED_)
