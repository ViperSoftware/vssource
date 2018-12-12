// OCutItem.h: interface for the OCutItem class.
//
//////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_UT_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OCUT_DATA
#endif

#if !defined(AFX_OCUTITEM_H__62F41647_AD27_11D1_B2AA_006008AFBC41__INCLUDED_)
#define AFX_OCUTITEM_H__62F41647_AD27_11D1_B2AA_006008AFBC41__INCLUDED_

class OCutItem  
{
public:
	virtual SRGraph * GetGraph();
	virtual void Paint(CDC *pDC,CWnd *pWnd, CRect r=CRect(0,0,0,0));
	virtual void ClearData();
	virtual void ClearComponents();
	virtual void Clear() = 0;
	virtual void InitializeData() = 0;
	virtual void SetupComponents() = 0;
	OCutItem();
	virtual ~OCutItem();

protected:
	SRGraph m_Graph;
};

#endif // !defined(AFX_OCUTITEM_H__62F41647_AD27_11D1_B2AA_006008AFBC41__INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
