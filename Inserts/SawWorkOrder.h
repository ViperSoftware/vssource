// SawWorkOrder.h: interface for the CSawWorkOrder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAWWORKORDER_H__0553AA67_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_SAWWORKORDER_H__0553AA67_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\WorkOrder.h"
#include "\VSSource\Inserts\SawBatch.h"	// Added by ClassView

class CSawWorkOrder : public CWorkOrder  
{
public:
	CSawWorkOrder(CWnd* pParent = NULL);
	virtual ~CSawWorkOrder();

	int				CreateTRSInputFile(CDaoDatabase *pDB, const char *path, int format, int bevels, int DeviceType);
	virtual void	EditDetail(CDbData *pDB, CDbListDef *pLDef, BOOL EditAllowed);
	virtual CDbDataSource * GetDetailDataSource(CDbData *pDB);

protected:
	CSawBatch	m_SawBatch;
	CString		m_WOSawDetailSQL;
};

#endif // !defined(AFX_SAWWORKORDER_H__0553AA67_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
