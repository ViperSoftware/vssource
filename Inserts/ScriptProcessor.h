// ScriptProcessor.h: interface for the CScriptProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIPTPROCESSOR_H__BAB90401_783A_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_SCRIPTPROCESSOR_H__BAB90401_783A_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\StringEx.h"
#include "\VSSource\Inserts\SymbolTable.h"
#include "\VSSource\INSERTS\PrintLib.h"
#include "\VSSource\INSERTS\FaxDevice.h"

#include <afxinet.h>


#define ERROR_AND_QUIT 911

class CScriptProcessor : public CObject
{
	DECLARE_DYNAMIC(CScriptProcessor)
public:
	class CSubBlock : public CObject
	{
	public:
		CSubBlock::CSubBlock(const char *name) {m_Name = name;};
		CString m_IncludePath;
		CString m_Name;
		DWORD	m_Offset;
	};
	class CKeyword : public CObject
	{
	public:
		CKeyword::CKeyword(const char *pName = NULL, CScriptProcessor *pProcessor = NULL, short id = 0) 
		{
			m_pProcessor = pProcessor;
			if (pName != NULL)  m_Name = pName;
			m_id = id;
		};
		CString m_Name;
		CScriptProcessor *	m_pProcessor;
		short	m_id;
	};

friend class CSubBlock;	
friend class CKeyword;

class CScriptBuffer : public CStdioFile
{
public:
	CScriptBuffer()
	{
		m_buffer = NULL;
	}
	virtual ~CScriptBuffer()
	{
		if (m_buffer != NULL)  delete m_buffer;
	}
	virtual int				Open(const char *path, unsigned int mode, CFileException *e);
	virtual void			Close(void) {};
	virtual unsigned int	Seek(unsigned int pos, unsigned int mode)  {m_curPos=pos;return(m_curPos);};
	virtual ULONGLONG		GetPosition() const {return(m_curPos);};
	virtual BOOL			ReadString(CString &line);
	virtual CString			GetFilePath() const {return(m_filePath);};
protected:
	CString			m_filePath;
	char *			m_buffer;
	unsigned int	m_bufSize;
	ULONGLONG		m_curPos;
};
	

typedef CTypedPtrMap<CMapStringToOb,CString,CKeyword*> CCommandMap;

public:
	CScriptProcessor(const char *path = NULL, CView *pView = NULL, const char *Caller = NULL);
	virtual ~CScriptProcessor();

public:
	int IsKeyword(const char *keywords[]);
	void AttachPrintDoc(CPrintDoc *pPrintDoc);
	void AttachFaxDevice(CFaxDevice *pFax);
	void PreviewPrintDoc();
	BOOL SetPath(const char *path);
	virtual int	Run(const char *Caller = NULL);

	virtual int	DoCmd(int iCmd);

protected:
	virtual void	InitStdVariables();
	virtual int		set_value(const char *Name, int flag, const char *expr);
	virtual double	get_value(const char *Name);
	void		process_switch();
	int 		process_if();
	int			process_for();
	int			process_while();
	int			process_assignment();
	int			process_subcall(int num, CString args[]);
	int			if_statement_true();
	int			while_expr_true();
	int			skip_if();
	int			end_of_block();
	int			skip_to_endif();
	void		skip_to_endfor();
	void		skip_to_endwhile();
	void		skip_to_endsub();
	int			eval_if_expr( const char *value1, const char *oper, const char *value2 );
	virtual int	ParseLine();
	int			ReadLine();
	int			GetNextToken();
	void *		FindSub(const char *Name);

	CString		m_ScriptPath;
	CScriptBuffer  m_ScriptFile;
//	CStdioFile  m_ScriptFile;
//	char		m_ScriptBuffer[4096];
	BOOL		m_ScriptLoaded;
	int			m_Trace;
	CStringEx	m_Line;
	CStringEx	m_originalLine;  // as found in source file
	int			m_LineNum;
	CString		m_Token;
	int			m_TokenNum;
	int			m_LinePos;
	DWORD		m_curFilePos;
	CCommandMap *	m_pCommandMap;

	// fileio stuff
	int			process_fileio();
	int			GetFileNo();
	int			print_line(CStdioFile *fpout,int flag);
	int			print_string(CString& str,int flag);
    CStdioFile *m_FileTable[20];

	CSymbolTable *	m_pSymbolTable;

	CObList		m_SubBlocks;  // list of subroutine objects

	CView *		m_pView;  // attached view
	CString		m_Caller;
	void		process_printdoc();
	CPrintDoc *	m_pPrintDoc;  

	int			process_fax();
	CFaxDevice *m_pFaxDevice;

	CFtpConnection		*m_pFTPSite;
	CInternetSession	*m_pSess;

public:
	bool EmptyMessageQueue();
};

#endif // !defined(AFX_SCRIPTPROCESSOR_H__BAB90401_783A_11D3_95C5_0000C0F3C6B2__INCLUDED_)
