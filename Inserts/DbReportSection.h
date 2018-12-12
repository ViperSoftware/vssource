// DbReportSection.h: interface for the CDbReportSection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBREPORTSECTION_H__8C1A71BD_6BF4_48D8_A548_33D6E864DA0B__INCLUDED_)
#define AFX_DBREPORTSECTION_H__8C1A71BD_6BF4_48D8_A548_33D6E864DA0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDbReportSection : public CObject  
{
public:
	CDbReportSection();
	virtual ~CDbReportSection();


protected:

	CString		m_Name;  // section name
	CString		m_DS_select;
	CString		m_DS_filter;
	CString		m_DS_sort;
	CObArray	m_HeaderArray;  // array of all section elements
	CObArray	m_BodyArray;    // array of all section elements
	CObArray	m_FooterArray;  // array of all section elements

};

#endif // !defined(AFX_DBREPORTSECTION_H__8C1A71BD_6BF4_48D8_A548_33D6E864DA0B__INCLUDED_)
