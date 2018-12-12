// DbDataDAO.h: interface for the CDbDataDAO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBDATADAO_H__3E554944_19B1_408A_A3FD_63EEE517BCDF__INCLUDED_)
#define AFX_DBDATADAO_H__3E554944_19B1_408A_A3FD_63EEE517BCDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_

#include "DBdata.h"

class CDbDataDAO : public CDbData  
{
public:
	CDbDataDAO();
	virtual ~CDbDataDAO();

protected:
	CDaoDatabase	m_DaoDB;

};

#endif // !defined(AFX_DBDATADAO_H__3E554944_19B1_408A_A3FD_63EEE517BCDF__INCLUDED_)
