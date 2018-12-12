// TimeEstimate.h: interface for the CTimeEstimate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMEESTIMATE_H__B03943E3_946F_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_TIMEESTIMATE_H__B03943E3_946F_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTimeEstimate : public CString  
{
public:
    CTimeEstimate() : CString( ){};
    CTimeEstimate( const CString& stringSrc) : CString( stringSrc ){};
    CTimeEstimate( LPCWSTR lpsz ) : CString( lpsz ){};
    CTimeEstimate( LPCSTR lpsz ) : CString( lpsz ){};

	float GetMinutes();
};

#endif // !defined(AFX_TIMEESTIMATE_H__B03943E3_946F_11D3_95C5_0000C0F3C6B2__INCLUDED_)
