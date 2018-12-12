
#ifndef __MASKEDIT_H__
#define __MASKEDIT_H__


#define LITERAL_SENTINEL    128

//forward declaration
class CMaskEdit;

class CMaskEdit : public CEdit
{
    DECLARE_DYNAMIC(CMaskEdit);
    
public:     

	//access Creation/Initialization

    CMaskEdit();
    
    BOOL AttachEdit(int nCtlID, CWnd* pParentWnd);

public:    
	
	//@access Attributes

    //@cmember
    /* Sets the input mask for the edit control.*/
    virtual BOOL SetMask(LPCTSTR lpszMask);
    
	//@cmember
	/* Sets the prompt character.*/
    virtual void SetPromptChar(TCHAR chNewPrompt );

	//@cmember
	/* Retrieves the current prompt character.*/
    virtual TCHAR GetPromptChar() {return m_chPrompt;}
    
	//@cmember
	/* Puts data into the masked edit.*/
    virtual BOOL SetData(const CString& strData, 
						int nStartPos = 0, 
						BOOL bInsert = FALSE,
						BOOL bIgnorePromptChars = TRUE);
    
	//@cmember
	/* Retrieves data from the masked edit and strips out the */
	// literals and spaces if specified.
    virtual void GetData(CString& strData, BOOL bTrim = FALSE);

	//@cmember
	/* Retrieves the data from the masked edit with all literal */
	// characters intact.
    virtual CString& GetRawData(void) {return m_strDisplay;}

	//@cmember
	/* Determines if the edit is in insert mode or not.*/
    virtual BOOL InsertMode() {return m_bInsert;}
    
public:

	//@access Operations

	//@cmember
	/* Clears the non-literal data from the masked edit.*/
    void ClearData(void);

	// Undo operations
	// Since the CEdit::Undo functions are not virtual,
	// these are new implementations.

	//@cmember
	/* Determines if the last operation can be undone.*/
	virtual BOOL CanUndo();

	//@cmember
	/* Performs an "undo" on the last operation.*/
	virtual BOOL Undo();	

	//@cmember
	/* Clears the "undo" buffer.*/
	virtual void EmptyUndoBuffer();
    

// Implementation
    
public:
    virtual ~CMaskEdit();

#ifdef _DEBUG
    BOOL m_bIsAttached;
    virtual void Dump(CDumpContext& dc) const;
    virtual void AssertValid() const;
#endif
    
protected:

	//@access Overrideables

	//@cmember
	/* Determines if a character is valid for the specified position.*/
    virtual BOOL IsCharValid(int nPos, TCHAR& ch);

	//@cmember
	/* Determines if a character is a literal character.*/
    virtual BOOL IsLiteralChar(TCHAR ch);

	//@cmember
	/* Determines if a character is a mask character.*/
    virtual BOOL IsMaskChar(TCHAR ch);
    
	//@cmember
	/* Updates the string displayed in the control based on the current mask.*/
    virtual void UpdateDisplayStr();

// Implementation - mask operations

	//@cmember
	/* Given a mask, returns a displayable string based on the current*/
	// prompt character.
	virtual void ConvertMaskToDisplayStr(CString strMask,CString& strResult);

	//@cmember
	/* Parses the mask string.*/
    virtual void ParseMaskString();

	//@cmember
	/* Locates the last filled in data position.*/
    virtual int  FindLastFilledDataPos(int nStartPos);
    
// Implementation - edit manipulation...    

	//@cmember
	/* Inserts a character, and optionally refreshes the display.*/
    virtual BOOL PushChar(int nStartPos, TCHAR ch, BOOL bRefreshDisplay = TRUE);

	//@cmember
	/* Removes a range of characters.*/
    virtual void PullChar(int nFromPos, int nToPos);

	//@cmember
	/* Sets the cursor position.*/
    virtual int SetCursorPos(int nOldPos, int nDirection, BOOL bSelect = FALSE);

	//@cmember
	/* Retrieves the next data position relative to a given position.*/
    virtual int GetNextDataPos(int nOldPos);

	//@cmember
	/* Retrieves the previous data position relative to a given position.*/
    virtual int GetPrevDataPos(int nOldPos);

// Implementation - redrawing

	//@cmember
	/* Redraws the control.*/
    virtual void UpdateDisplay();

	//@access Overrides
	
	// Called when a nonsystem key is pressed.
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	// Called when a keystroke translates to a nonsystem character. 
    afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	// Called when the user presses the left mouse button.
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	// Called when a copy operation occurs.
    afx_msg LRESULT OnCopy(WPARAM, LPARAM);
	
	// Called when a paste operation occurs.
    afx_msg LRESULT OnPaste(WPARAM, LPARAM);
	
	// Called when a cut operation occurs.
    afx_msg LRESULT OnCut(WPARAM,LPARAM);
	
	// Called when a clear operation occurs.
    afx_msg LRESULT OnClear(WPARAM,LPARAM);

	// Called when the control receive the input focus.
	afx_msg void OnSetFocus(CWnd* pOldWnd);

protected:

	//@access Protected data members

	//@cmember
	/* The mask string.*/
    CString m_strMask;

	//@cmember
	/* The displayed string.*/
    CString m_strDisplay;

	//@cmember
	/* The prompt character (default = space)*/
    TCHAR m_chPrompt;

	// Set by OnKeyDown...
	//@cmember
	/* Signals OnChar that a key was already handled.*/
    BOOL m_bKeyProcessed;     

	//@cmember
	/* Insert mode flag (default = overwrite).*/
    BOOL m_bInsert;

	//@cmember
	/* The undo buffer.*/
	CString m_strUndoText;

	//@cmember
	/* The redo buffer.*/
	CString m_strRedoText;
    
	
	// Implementation - Message map and entries    
    DECLARE_MESSAGE_MAP();
};

//
// SEC Extension DLL
// Reset declaration context
//

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

#endif // __CMaskEDIT_H__

