// Piece.h: interface for the CPiece class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIECE_H__16E4DF26_0A17_11D3_95C5_0000C0F3C6B2__INCLUDED_)
#define AFX_PIECE_H__16E4DF26_0A17_11D3_95C5_0000C0F3C6B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma comment (lib, "TrusSubs.lib") // make linker search this lib

#include "\VSSource\Libs\DbCore\DbDataSource.h"
#include "\VSSource\Inserts\PrintLib.h"
#include "\VSSource\Inserts\Cad.h"

#define BEVEL_STRUCT 1
#define COPE_STRUCT  2
#define NO_BEVEL 1
#define SINGLE_BEVEL 2
#define DOUBLE_BEVEL 3
#define SQUARE_BEVEL 4

#define  LEFT_END_BEVEL 0
#define RIGHT_END_BEVEL 1

class CPieceBrace
{
public:
	CPieceBrace(int numPts);
	virtual ~CPieceBrace();

short int   Type;
	float   Size;
CString     Grade;
CString     Label;
short int   GradeNum;
short int   NumPoints;
	float * points;   
};

class CPieceBevel : public CObject
{
public:
	CPieceBevel() {};
	virtual ~CPieceBevel() {};

	short int    struct_type;
	void         *next;
	unsigned int size;
	short int    bevel_type;
	float        front_angle;
	float        back_angle;
	float        offset;
	struct		{
				unsigned int beveled_end:1;
				unsigned int      unused:15;
				} flags;                  
};


class CPieceCope : public CObject
{
public:
	CPieceCope() {
		struct_type = COPE_STRUCT;
		size = sizeof(CPieceCope);
		x1 = x2 = x3 = 0.0f;
	};
	virtual ~CPieceCope() {};

	short int    struct_type;
	void         *next;
	unsigned int size;
	char		 End;  // 'L' or 'R'
	float        x1;   // length of cope in feet
	float        x2;
	float        x3;
	CString		 Type;
};

class CPiecePoint  
{
public:
	CPiecePoint();
	virtual ~CPiecePoint();

	virtual int		Add(CDbRecordset *pRS, long PieceID);

	int		m_PointNum;  // from 1 to # of points in piece, clockwise from bottom left
	float	m_X;
	float	m_Y;
};

class CPiece : public CObject  
{
public:
	float GetPitch();
	bool PointOnCenterline(float x, float y);
	CPiece();
	virtual ~CPiece();

	void	MaxCoors(float *X, float *Y);
	void	MinCoors(float *X, float *Y);
	void	GetCoors(int p, float *X, float *Y);
	int		GetNumLeftPoints();
	virtual int		Load(CDbDataSource *pDS);
	virtual int		Add(CDbDataSource *pDS, long WOID);
	virtual int		Update(CDbDataSource *pDS);
	virtual int		Draw(CCad *pCad);

	CString		m_JobKey;
	CString		m_Mark;
	CString		m_Tag;
	CString		m_TrussDesc;

    short		m_Type;          
    int			m_Qty; 
    float		m_Size;          // in feet
	float       m_Depth;         // in feet
    CString		m_SizeName;
    CString     m_Label;
	short		m_GradeNum;
    CString		m_GradeName;
    short		m_NumPts;
    short		m_NumPtsLeft;
    CPtrArray	m_Points;
    CObList		m_SpecialData;
	long		m_CadIp;
	int			m_TypeScrews;
	CString		m_LScrews;
	CString		m_RScrews;
	CString		m_MaterialID;  // optional special material id

	CPieceBrace *	m_pBrace;
	void FormatBevelString(CString &bevel);
	void FormatCopeString(CString &cope);
};


class CCutPiecePoint : public CPiecePoint  
{
public:
	CCutPiecePoint();
	virtual ~CCutPiecePoint();

	virtual int	Add(CDbRecordset *pRS, long PieceID);

	float	m_EdgeAngle;
	float	m_EdgeLength;

};

class CCutPiece : public CPiece  
{
public:
	int SawCheck(CString &name);
	CCutPiecePoint * GetPoint(int p);
	void CalcNumLeftPoints();
	bool IsSameLengthSizeGrade(CCutPiece *other);
	bool IsSameLengths(CCutPiece *other);
	bool IsSameAngles(CCutPiece *other);
	bool IsDuplicate(CCutPiece *other);
	bool IsCenterline();
	CCutPiece();
	CCutPiece(CPiece *piece, bool nodupcheck = false);
	virtual ~CCutPiece();

	virtual int		Load(CDbDataSource *pDS);
	virtual int		Add(CDbDataSource *pDS, long WOID);
	int		DrawStdLength(CCad *pCad);
	int		DrawStdLength(CPrintDoc *pPrintDoc);
	char *	AngleColorCode(float angle);
	int		PrintCutEdgeLength(int edge, CString &buf);
	int		CalcEdgeAngles();
    void    FlipAboutYaxis();
	void    RotateAboutYaxis();
    void    FlipAboutXaxis();
	void    RotateAboutXaxis();
	void	RotateToStandardPosition(bool nodupcheck = false);
	void	CalcEdgeLenghtsAngles();

    int             m_NumCutsL;
    int             m_NumCutsR;
    int             m_TtlEdgs;
    float           m_TopLen;
    float           m_BotLen;
		float						m_SqSqLen;
    float           m_OverallLen;
    float           m_CenterLen;
    float           m_NominalLength;
		float						m_LTopAngle;
		float						m_LBotAngle;
		float						m_RTopAngle;
		float						m_RBotAngle;
		float						m_AngleTolerance;
    enum DupTypes
	{
		NEW_PIECE = 0,
		EXACT_MATCH = 1,
		ANGLES_MATCH = 2
	}				m_DupFlag;
    float           m_BoardFoot;
    float           m_Price;
    int				m_TrussOrder; //This is the order which the truss was written
    int				m_PieceOrder; //This is the order which the piece was written
	int				m_PieceID;		
	int				m_QtyCut;
	int				m_SetupNumber;
	CString			m_BevelData;
	CString			m_CopeData;
	struct PrintFormatCodes
	{
		unsigned int PictureOnly :1;
		unsigned int ColorCodes  :1;
		unsigned int SqCutZeroDeg:1;
		unsigned int LengthInInches:1;
		unsigned int PiecePitch:1;
	}				m_PrintFormat;
	// used for blade saw printing info
	double			m_TDelta_X;	// translation vector for piece from saved local coor system to truss global coor system
	double			m_TDelta_Y;
	double			m_TAngle;
};




#endif // !defined(AFX_PIECE_H__16E4DF26_0A17_11D3_95C5_0000C0F3C6B2__INCLUDED_)
