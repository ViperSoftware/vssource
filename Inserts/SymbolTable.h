// Symbol Table classes

#ifndef __CSYMBOLTABLE
#define __CSYMBOLTABLE

#pragma comment (lib, "General.lib") // make linker search this lib

#include "stack.h"
#include "\vssource\inserts\resource.h"

// define flags codes
#define SYSTEM_VARIABLE        1   // not changable in rules file by user
#define USER_DEFINED_VARIABLE  2
#define USER_CHANGABLE         2   // or with SYSTEM_VARABLE to allow changes
#define SYM_DELETED            512 // Symbol inactive

class CSymbol
{
   friend class CSymbolTable;
// Construction
public:
	CWnd * GetEditControl();
	virtual void AttachEditControl(CWnd *pWnd);
	CSymbol(const char *Name = NULL);   // standard constructor
	virtual ~CSymbol();

   CString        m_name;
   enum SYMBOL_TYPE 
   {
		SYM_UNDEFINED = 0,
		SYM_ALPHA = 'S',     // string data
		SYM_INTEGER =1,      // 16 bit integers
		SYM_FLOAT   =2,      // 32 bit floats
		SYM_SARRAY  =4,      // String array (data is char**)
		SYM_IARRAY  =5,      // Integer + 4
		SYM_FARRAY  =6,      // Float + 4
		SYM_DBFIELD =10,     // CDbSymbol
		SYM_DBINT    = 'I',  // string integer
		SYM_DBFLOAT  = 'R',  // string float
		SYM_DBDATE   = 'D'   // string date
   };

   SYMBOL_TYPE	  m_type;  /* data type */
   short int      m_flags;   // access flag, for rules
   short int      m_owner;   // handle of process with right-to-destroy
   short int	  m_maxLength;

   static bool		m_LoadFromSymTableOnly;  

	virtual void SetValue(double value);
	virtual void SetValue(int value);
	virtual void SetValue(CString value);
	virtual int  GetValue(double *value);
	virtual int  GetValue(int *value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival) = 0;

protected:
   CSymbol       *m_left;
   CSymbol       *m_right;
   // this is set whenever a symbol is placed in edit mode (on a dialog/form/etc).
   // when set, all GetValue routines will use the text from the edit control instead
   // of value stored in the symbol.  this is needed for calc's to work on a form
   // using current form values and still support cancel which wouldn't update the
   // symbol value.
   CWnd	*		m_pEditControl;
	void		AddNodeToListbox(CListBox *pLB);

public:
	CString GetType();

};

class CAlphaSymbol : public CSymbol
{
public:
	CAlphaSymbol::CAlphaSymbol(const char *Name);
	virtual void SetValue(CString value);
	virtual void SetValue(double value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	CString        m_data;
};
class CAlphaPointerSymbol : public CSymbol
{
public:
	CAlphaPointerSymbol::CAlphaPointerSymbol(const char *Name, CString *sval);
	virtual void SetValue(CString value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	CString		*m_data;
};


class CFloatSymbol : public CSymbol
{
public:
	CFloatSymbol::CFloatSymbol(const char *Name);
	virtual void SetValue(double value);
	virtual void SetValue(int value);
	virtual void SetValue(CString value);
	virtual int  GetValue(double *value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	double       m_data;
};
class CIntSymbol : public CSymbol
{
public:
	CIntSymbol::CIntSymbol(const char *Name);
	virtual void SetValue(int value);
	virtual void SetValue(double value);
	virtual void SetValue(CString value);
	virtual int  GetValue(int *value);
	virtual int  GetValue(double *value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	int            m_data;
};
class CFloatPointerSymbol : public CSymbol
{
public:
	CFloatPointerSymbol::CFloatPointerSymbol(const char *Name, double *pValue);
	virtual int  GetValue(double *value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	double		*m_data;
};

class CIntPointerSymbol : public CSymbol
{
public:
	CIntPointerSymbol::CIntPointerSymbol(const char *Name, int *pValue);
	virtual int  GetValue(int *value);
	virtual int  GetValue(double *value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);
	virtual void SetValue(int value);
	virtual void SetValue(double value);
	int           *m_data;
};

class CSymbolTable : public CDialog
{
public:
	// Construction
	CSymbolTable(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSymbolTable();

// Dialog Data
	//{{AFX_DATA(CSymbolTable)
	enum { IDD = IDD_SYMBOLTABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSymbolTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

public:
	int LinkAlphaSymbol(const char *name, const char *value);
	int LinkIntSymbol(const char *name, int value);
	int LinkIntPointerSymbol(const char *name, int *value);
	int LinkFloatSymbol(const char *name, double value);
	void SetActiveObjectName(const char *Name);
	BOOL IsEmpty();
   //
   BOOL LinkSymbol(CSymbol *pSymbol);
   void UnlinkSymbol(const char *Name);
   BOOL DeleteAllSymbols();

	int				GetValue(const char *name, double *fval, CString &sval, int *ival);
	int				GetValue(const char *name, CString &sval);
   virtual CSymbol *GetSymbol(const char *Name);
	int				SetValue(const char *Name, const char *expr);
   virtual int      IsVariable (const char *expr,int *pos,double *value);
   virtual BOOL     SolveExpression (const char *Expr, double *Value);
    int				DoPrevOp();
    int				CalcLine (const char *formula, double *Result, char *pstr);
	int				GetNextArg (const char *ArgLine, int *Op, int *ArgType, double *Value, char *pStr);

protected:
   CSymbol  *m_Root;
   CStack    m_Stack;

   CString	m_ActiveObjectName;


   int      CheckParen(const char *Expr);
   int      PostFix (const char *Expr, char *PFExpr);
   int      Eval(const char *Expr, double *Value);
   int      CalcFunc (const char *FN);
   int      m_StkP;        /* current top of stack */
   double   m_StkD[100];   /* the stack */
   int      dPush (double *DataItem);
   int      dPop (double *DataItem);

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSymbolTable)
		// NOTE: the ClassWizard will add member functions here
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
};

#endif
