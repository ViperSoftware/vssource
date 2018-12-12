// DBdata.h: interface for the CDBdata class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBDATA_H__0D63504B_C835_11D2_95C4_0000C0F3C6B2__INCLUDED_)
#define AFX_DBDATA_H__0D63504B_C835_11D2_95C4_0000C0F3C6B2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <afxdb.h>

#include "\VSSource\Inserts\SymbolTable.h"
#include "\VSSource\Libs\DBCore\DAOSource.h"
#include "\VSSource\Libs\DBCore\ODBCSource.h"
#include "\VSSource\Libs\DBCore\DbDataSourceDef.h"
#include "\VSSource\Libs\DBCore\DbListDef.h"

class CDBTable;
class CDbRecordset;

class CDbData  
{
public:
	boolean IsOpen();
	bool IsValid(CDbDataSource *pDS);
	int CreateTable(const char *name);
	int CreateField(const char *table, const char *name, const char *options);
	CString m_UserPWD;
	CString m_UserID;
	CString m_WorkgroupPath;
	void SetUserID(const char *UserID = NULL, const char *PassW = NULL, const char *WGpath = NULL);
	void ListDataSources(CStdioFile *fp, bool bActiveOnly = true);
	void ListDataSources(CListBox *pLB, bool bActiveOnly = true);
	void ListDataSources(CComboBox *pLB, bool bActiveOnly = true);
	void AttachListDefinitions(CDbListDefinitions *pListDefs);
	void AttachSymbolTable(CSymbolTable *pSymTable);
	CDbData();
	virtual ~CDbData();

	CDbDataSource * CreateDataSource(const char *Name, const char *SQL);
	CDbDataSource * CreateDataSource(CDbDataSourceDef *pDSDef);
	CDbDataSource * CreateDataSource(const char *Name, CDaoRecordset *pRSet);
	CDbDataSource * CreateDAODataSource(CDbDataSourceDef *pDSDef);
	CDbDataSource * CreateODBCDataSource(CDbDataSourceDef *pDSDef);
	void			AttachDS(CDbDataSource *pDS);
	void			DetachDS(const char *Name);
	void			DeleteDataSource(const char *Name, bool bAllInstances = false);
	void			AddDataSourceToSymbolTable(CDbDataSource *pDS);
	CDbDataSource * Find(const char *Name);
	CDBTable *		GetTable(const char *name);
	BOOL			Create(const char *Title, const char *Name);
	BOOL			SetDBName(const char* Name);
	BOOL			SetDBName(const char* Title, const char* Name);
	CString &		GetDBName();
	CString &		GetDBTitle();
	CString 		GetDBDirPath();
	CSymbolTable *	GetSymbolTable();
	CDbListDefinitions *	GetListDefs();
	CDaoDatabase *  GetDaoDatabase();

protected:
	CSymbolTable *	m_pSymbolTable;  // active application symbol table
	CDbListDefinitions *	m_pListDefs;
	CDBTable *		m_pTables;
	CString			m_Title;  // Alias name for DB
	CString			m_DBName; // Path or ODBC connection string
	CDaoDatabase	m_DaoDB;
	CDatabase       m_OdbcDB;
	BOOL            m_isODBC;
	CObArray		m_ActiveDataSources;
private:
	BOOL LoadDBinfo();
};


class CDBTable  
{
friend class CDbData;
friend class CDbRecordset;
public:
	CDBTable();
	virtual ~CDBTable();

protected:
	CDaoTableDefInfo	 m_TableDefInfo;
	CDaoTableDef		*m_pTableDef;
	CDbRecordset		*m_pRecordSet;

	CDBTable	*m_pNext;
};

// this is a database table symbol

class CDBSymbol : public CSymbol
{
public:
	void UpdateDS();
	void Reset();
   CDBSymbol(const char *Name = NULL);

	virtual void AttachEditControl(CWnd *pWnd);
	virtual void SetValue(CString value);
	virtual void SetValue(double value);
	virtual void SetValue(int value);
	virtual int  GetValue(double *value);
	virtual int  GetValue(int *value);
	virtual int  GetValue(CString &value);
	virtual int  GetValue(double *fval, CString &sval, int *ival);

   CDbDataSource *	m_pDS;
   CString			m_Data;
   bool				m_bLocalData;
   int				m_DbType;

   static bool		m_LoadFromDSOnly;  
};



#endif // !defined(AFX_DBDATA_H__0D63504B_C835_11D2_95C4_0000C0F3C6B2__INCLUDED_)
