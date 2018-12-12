// TableWorkOrder.h: interface for the CTableWorkOrder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEWORKORDER_H__0553AA68_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_TABLEWORKORDER_H__0553AA68_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\INSERTS\WorkOrder.h"
#include "\VSSource\INSERTS\TableBatch.h"	// Added by ClassView

class CTableWorkOrder : public CWorkOrder  
{
public:
	CTableWorkOrder(CWnd* pParent = NULL);
	virtual ~CTableWorkOrder();

	virtual void	EditDetail(CDbData *pDB, CDbListDef *pLDef, BOOL EditAllowed);
	virtual CDbDataSource *GetDetailDataSource(CDbData *pDB);
	virtual int		UpdateDependentWOs(CDbDataSource *pDS);

protected:
	CTableBatch m_TableBatch;
	CString		m_WOTableDetailSQL;

	// Generated message map functions
	//{{AFX_MSG(CTableWorkOrder)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_TABLEWORKORDER_H__0553AA68_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
