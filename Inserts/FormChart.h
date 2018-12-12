// FormChart.h: interface for the CFormChart class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMCHART_H__9080F999_BC34_46AA_8923_ABD058A555BD__INCLUDED_)
#define AFX_FORMCHART_H__9080F999_BC34_46AA_8923_ABD058A555BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Libs\DbCore\DbDataSource.h"
#include "\VSSource\Inserts\Stingray\oc60\ochart.h"

class CFormChart : public SREScrollView  
{
public:
	CFormChart();
	virtual ~CFormChart();

	SRGraph			m_Graph;
	SRGraphDisplay	*m_pDisplay;
	CDbDataSource	*m_pDbSource;

virtual void ShowFeedback(SRGraphFeedback* pFeedback)
{
	SRGraph *pGraph= GetGraph();
	SRGraphDataList *pDataList = pGraph->GetGroup(pFeedback->m_nGroup);
	SRGraphData *pData = pDataList->GetIndex(pFeedback->m_nIndex);

	CString label = pData->GetAnnotation(1);
	double value = pData->GetValue();

	CString strText;
	strText.Format("%s : %f", label, value); 

	CPoint tPoint=m_MousePoint;
	// Don’t forget this conversion
	ClientToScreen(&tPoint);  
	m_GraphTip.SetTipTime(15000);  // set the popup time limit to 15 sec
	m_GraphTip.ShowTip(strText,tPoint,this);
}

void SetYRange(double YMin, double YMax);
void ClearData(void);
void SetGroupLegend(int group, CString value);
void SetText(int group, int item, CString value);
void SetValue(int group, int item, double value);
};

#endif // !defined(AFX_FORMCHART_H__9080F999_BC34_46AA_8923_ABD058A555BD__INCLUDED_)
