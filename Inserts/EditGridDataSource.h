// EditGridDataSource.h: interface for the CEditGridDataSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITGRIDDATASOURCE_H__03B494A1_086D_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_EDITGRIDDATASOURCE_H__03B494A1_086D_11D3_95C5_0000C0F3C6B2__INCLUDED_

#include "\VSSource\libs\GridLib97\ugdao.h"
#include "\VSSource\libs\DbCore\DbListDef.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEditGridDataSource : public CUGDAODataSource
{
public:
	void AttachListDef(CDbListDef *pLDef);
	CEditGridDataSource();
	virtual ~CEditGridDataSource();

	virtual int Close();
	virtual int GetNumCols();
	virtual int GetColName(int col,CString * string);
	virtual int GetColFieldName(int col,CString * string);
	virtual int GetColFormat(int col,CString *string);

	// override this to supply default vals when adding records
	// using GhostRowMode
	virtual BOOL AddDefaultField(const char *Field);

	void		SetRelatedFieldInfo(const char *Field, const char *Value);
	void		SetInitialValues(const char *string);
	CDbListDef	*m_pListDef;

protected:
	CString		m_RelatedField;
	CString		m_RelatedFieldValue;
	CString		m_InitialValues;

};

#endif // !defined(AFX_EDITGRIDDATASOURCE_H__03B494A1_086D_11D3_95C5_0000C0F3C6B2__INCLUDED_)
