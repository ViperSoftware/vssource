// FormScriptProcessor.h: interface for the CFormScriptProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_FORMSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\WOScriptProcessor.h"
#include "DbFormView.h"

class CFormScriptProcessor : public CWOScriptProcessor  
{
	DECLARE_DYNAMIC(CFormScriptProcessor)
public:
	CFormScriptProcessor(const char *path = NULL, CDbFormView *pView = NULL, const char *Caller = NULL);
	virtual ~CFormScriptProcessor();

	CDbFormView *	GetFormView();
	int				RunEventScript(long scriptStart, const char *event);
	void			PreProcess(long scriptStart);

	virtual int	DoCmd(int iCmd);

protected:
	virtual int	ParseLine();

	CString		m_ActiveEvent;

	int			m_CurrentSelectedDbListItem;

};

#endif // !defined(AFX_FORMSCRIPTPROCESSOR_H__6027A761_F014_11D3_95C5_0000C0F3C6B2__INCLUDED_)
