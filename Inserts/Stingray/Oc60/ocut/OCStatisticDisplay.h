// OCStatisticDisplay.h: interface for the OCStatisticDisplay class.
//
//////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_UT_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OCUT_DATA
#endif

#if !defined(AFX_OCSTATISTICDISPLAY_H__C3B32534_159A_11D2_B2E5_006008AF1D5D__INCLUDED_)
#define AFX_OCSTATISTICDISPLAY_H__C3B32534_159A_11D2_B2E5_006008AF1D5D__INCLUDED_


class OCStatisticDisplay : public SRGraphDisplay  
{
public:
	OCStatisticDisplay();
	virtual ~OCStatisticDisplay();

	void SetBarWidth(double  v){m_dBarWidth=v;}
	double  GetBarWidth(){return m_dBarWidth;}

protected:
	virtual void DrawScatterData();

	double  m_dBarWidth;
};

#endif // !defined(AFX_OCSTATISTICDISPLAY_H__C3B32534_159A_11D2_B2E5_006008AF1D5D__INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
