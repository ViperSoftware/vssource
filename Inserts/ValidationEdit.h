// ValidationEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CValidationEdit window

class CValidationEdit : public CEdit
{
// Construction
public:
	CValidationEdit();

// Attributes
public:
   COLORREF GetTextColor() const;
   COLORREF GetBackgroundColor() const;
   CString GetOriginalData() const;          // Whatever the user typed in, if valid

// Operations
public:
   void SetTextColor(COLORREF clrText);
   void SetBackgroundColor(COLORREF clrBackground);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValidationEdit)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	//}}AFX_VIRTUAL

// Overridables
public:
   virtual CString GetStrippedData() const;  // Override this to return "clean" data for editing or saving (called from OnGetFocus())
                                             // If you want to let the user edit the original data, just don't override this function.
   virtual CString GetFormattedData() const; // Override this to return formatted data for display (called from OnKillFocus())
                                             // If you want to let the user see the original data, just don't override this function.
   virtual void SetWindowText(LPCTSTR lpszString);

protected:
   virtual BOOL IsValid() const;             // Override this to validate input
   virtual void DisplayError();              // Override this to take action in the event of an error
                                             // Default implementation displays a message box, resets focus and selects all the text 

// Implementation
public:
	virtual ~CValidationEdit();

private:
   COLORREF m_clrText;           // Text color
   COLORREF m_clrBackground;     // Background color
   CBrush*  m_pbrBackground;     // Brush object for holding background brush
   CString  m_strOriginalData;   // Holds whatever the user typed in, if valid

	// Generated message map functions
protected:
	//{{AFX_MSG(CValidationEdit)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
   afx_msg void OnDisplayError();

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
