// SSNEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSSNEdit window
#include "\VSSource\Inserts\ValidationEdit.h"

class CSSNEdit : public CValidationEdit
{
// Construction
public:
	CSSNEdit();

// Attributes
public:

// Operations
public:

// Overrides
public:
   virtual CString GetFormattedData() const; // Override this to return formatted data for display (called from OnKillFocus())
                                             // If you want to let the user see the original data, just don't override this function.
protected:
   virtual BOOL IsValid() const;             // Override this to validate input
   virtual void DisplayError();              // Override this to take action in the event of an error

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSSNEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSSNEdit();

private:
   void StripCharacter(LPTSTR lpszString, TCHAR chRemove) const;

	// Generated message map functions
protected:
	//{{AFX_MSG(CSSNEdit)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
