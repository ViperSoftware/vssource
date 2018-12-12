// SawBatch.h: interface for the CSawBatch class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAWBATCH_H__0553AA61_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_SAWBATCH_H__0553AA61_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\Piece.h"
#include "\VSSource\Libs\DbCore\DAOSource.h"

class CSawBatch : public CObject  
{
public:
	CSawBatch();
	virtual ~CSawBatch();

	int		Load(CDaoDatabase *Db, const char *WOID);
	void	AttachDB(CDaoDatabase *Db, const char *SQL);
	int		GetFirstPiece();
	int		GetNextPiece();
	int		GetPiece(int record);
	int		CreateTRS(const char *path, int format, int bevels=0);
	int		CreateOMNI(const char *path, int format);
	int		CreateTCT(const char *path, int format);
	int		CreateBladeXML(const char *path, int format);
	long	GetDupPieces(CString *pDupLabels, int *pDupQty, int format);
	CString				m_WOID;
	CString				m_JobKey;
	CString				m_Mark;
	CString				m_Activity;
	CString				m_DeviceName;
	int					m_DeviceType;
	bool				m_bIncludeCutPieces;
	bool				m_bDontMarkCutPieces;
protected:
	CDbDAODataSource 	m_DbSource;// DataSource for pieces in batch
	CCutPiece			m_Piece;	// currently loaded piece from DataSource
	int					m_NumPieces;
	int					m_NumPiecesCut;
	int					m_NumSetups;
	// internal blade xml routines
	void	OutputPart(FILE *fp, const char *group);
	void	OutputBatches(FILE *fp);
};

#endif // !defined(AFX_SAWBATCH_H__0553AA61_03A6_11D3_95C5_0000C0F3C6B2__INCLUDED_)
