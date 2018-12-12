// WOScriptProcessor.h: interface for the CWOScriptProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WOSCRIPTPROCESSOR_H__B64D8E41_F657_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_WOSCRIPTPROCESSOR_H__B64D8E41_F657_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\DbScriptProcessor.h"
#include "\VSSource\Inserts\Truss.h"
#include "\VSSource\INSERTS\LumberInventory.h"


class CWOScriptProcessor : public CDbScriptProcessor  
{
	DECLARE_DYNAMIC(CWOScriptProcessor)
public:
	CWOScriptProcessor(const char *path = NULL, CView *pView = NULL, const char *Caller = NULL);
	virtual ~CWOScriptProcessor();

	virtual int	Run(const char *Caller = NULL);
	virtual int	DoCmd(int iCmd);

protected:
	virtual void	InitStdVariables();
	virtual int		ParseLine();

	void	InitBatchAssembly(float OffSet = -50.0f);
	int		CalcBatchAssembly();

	CTruss	m_Truss;
	CLumberInventory	m_LumInventory;
};

#endif // !defined(AFX_WOSCRIPTPROCESSOR_H__B64D8E41_F657_11D3_95C5_0000C0F3C6B2__INCLUDED_)
