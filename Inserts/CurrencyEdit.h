// CurrencyEdit.h: interface for the CCurrencyEdit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CURRENCYEDIT_H__753D2B3E_2E4F_48DD_85A2_921C9341502E__INCLUDED_)
#define AFX_CURRENCYEDIT_H__753D2B3E_2E4F_48DD_85A2_921C9341502E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\ValidationEdit.h"

class CCurrencyEdit : public CValidationEdit  
{
public:
	CCurrencyEdit();
	virtual ~CCurrencyEdit();

   virtual CString GetFormattedData() const; // Override this to return formatted data for display (called from OnKillFocus())
                                             // If you want to let the user see the original data, just don't override this function.
protected:
   virtual BOOL IsValid() const;             // Override this to validate input
   virtual void DisplayError();              // Override this to take action in the event of an error


};

#endif // !defined(AFX_CURRENCYEDIT_H__753D2B3E_2E4F_48DD_85A2_921C9341502E__INCLUDED_)
