// SpanString.h: interface for the CSpanString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPANSTRING_H__D75904C1_827B_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_SPANSTRING_H__D75904C1_827B_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpanString : public CString  
{
public:

    CSpanString() : CString( ){};
    CSpanString( const CString& stringSrc) : CString( stringSrc ){};
    CSpanString( const CSpanString& stringSrc) : CString( stringSrc ){};
    CSpanString( TCHAR ch, int nRepeat = 1 ) : CString( ch, nRepeat ){};
    CSpanString( LPCTSTR lpch, int nLength ) : CString( lpch, nLength ){};
    CSpanString( const unsigned char* psz ) : CString( psz ){};
    CSpanString( LPCWSTR lpsz ) : CString( lpsz ){};
    CSpanString( LPCSTR lpsz ) : CString( lpsz ){};

	virtual ~CSpanString();

	float DecimalFeet();

};

#endif // !defined(AFX_SPANSTRING_H__D75904C1_827B_11D3_95C5_0000C0F3C6B2__INCLUDED_)
