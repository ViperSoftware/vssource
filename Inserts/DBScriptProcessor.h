// DBScriptProcessor.h: interface for the CDBScriptProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_DBSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\ScriptProcessor.h"
#include "\VSSource\Inserts\DbData.h"
#include "\VSSource\Libs\DBCore\DbFormDef.h"

class CDbScriptProcessor : public CScriptProcessor  
{
	DECLARE_DYNAMIC(CDbScriptProcessor)
public:
	CDbDataSource * GetDataSource(CString &Name);
	bool			IsDataSource(CString &name);
	CDbScriptProcessor(const char *path = NULL, CView *pView = NULL, const char *Caller = NULL);
	virtual ~CDbScriptProcessor();

	void AttachDbData(CDbData *pDbData);
	CDbData * GetDbData(CString &name);
	CDbData * FindDbData(const char *name);

	virtual int	DoCmd(int iCmd);

protected:
	virtual int	ParseLine();

	CDbData	*	m_pDbData;
	BOOL		m_bDbDataLocallyLoaded;

	CDbData	*	m_pLocalDbData[10];  // locally opened DB's

	CStringEx	m_ImportFields;
	int			m_numImportLinesPerRead;
	char		m_ImportDelimChar;

	CObArray 	m_FormDefs;	// optional tab'd form view (list of forms in tabs)
};

#endif // !defined(AFX_DBSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_)
