//
//  Truss.h
//  Definition file for CTruss
//

#ifndef __Truss_h
#define __Truss_h

#pragma comment (lib, "TrusSubs.lib") // make linker search this lib

#define WOODTRUSS_OBJECT 1

#include "\VSSource\Inserts\Cad.h"
#include "\VSSource\Inserts\Piece.h"
#include "\VSSource\Inserts\TrussPlate.h"
#include "\VSSource\Inserts\TrussBearing.h"
#include "\VSSource\Inserts\XGeometry.h"
#include "\VSSource\Inserts\PrintLib.h"
#include "\VSSource\Inserts\SymbolTable.h"
#include "\VSSource\Inserts\DbData.h"



class CTruss : public CObject
{
public:
// Contruction
	CTruss(const char *Name = NULL);
	virtual ~CTruss();

// Attributes
public:

	enum LOAD_PIECE_OPTIONS
	{
		FIRST_PIECE=1001,
		NEXT_PIECE =1002
	};
	enum LOAD_PLATE_OPTIONS
	{
		FIRST_PLATE=1001,
		NEXT_PLATE =1002
	};
	
	int		m_Type;
	CString	m_Name;
	CString m_Version;

	// General info
    float	m_OASpan;
	float   m_OAHeight;
    int		m_Qty;
	int		m_PriceQty;
    float	m_LOverHang;
    float	m_ROverHang;
    int		m_NumPlys;
	CString m_Tag;
	CString m_Mark;
	int		m_BuildOrder;
    CString m_TrusDesc;
	CString m_TrusType;
    float	m_LeftCant;
    float   m_RightCant;
	float	m_LHeel;
	float	m_RHeel;
	float   m_LeftElevation;
	CString m_LoadingID;
	int		m_maxLC;
	float	m_Spacing;
	float	m_TCLL;  // all in psf
	float	m_TCDL;
	float	m_BCLL;
	float	m_BCDL;
	float	m_SurfaceArea;  // sqFt
	float	m_TCSlope;  // pitch
	float	m_BCSlope;  // pitch
	int		m_SeqNumber;
	float	m_Weight;   // per ply
	CString m_TrussID;  // mitek SeqNumber
	// truss component lists

	short	m_NumPieces;
	CObList	m_PieceList;
	short	m_NumBearings;
	CObList m_BearingList;
	short	m_NumPlates;
	short	m_NumJoints,
			m_NumTC,
			m_NumTCPitchBreaks,
			m_NumBC,
			m_NumBCPitchBreaks;
    short	m_NumTCJointSplices,
            m_NumTCPanelSplices,
            m_NumBCJointSplices,
            m_NumBCPanelSplices;
	short	m_NumUnplatedJoints;
	short	m_NumBraces;
	short	m_NumStrongBacks;
	CObList m_PlateList;

	// fabrication info
	float	m_EstSetup;		// in minutes
	float	m_EstAssemble;	// in minutes
	CString	m_ActualStart;
	CString m_ActualStop;
   
	BOOL m_bDrawAsLoading;
	struct	DrawOptions  // flags for things to be included
	{
		unsigned int Plates:1;
		unsigned int Labels:1;
		unsigned int LabelsChordsOnly : 1;
		unsigned int Dimensions:1;
		unsigned int PitchMarks:1;
		unsigned int Bearings:1;
		unsigned int BearingLabels : 1;
		unsigned int JointDimensions:1;
	} m_DrawOptions;

protected:
   float m_LumberThickness;  // depth plane of lumber    

// Operations
public:
	int		Load(CDbDataSource *pDS);
	int		Save(CDbDataSource *pDS);
	int		LoadFromPic(const char *filename);
	int		ReadEng(const char *filename);
	int		LoadFromTRE(const char *path);
	int		LoadFromBCH(const char *path);
	int		LoadFromSUM(const char *path);
	void	MinMaxCoors(float *xMin, float *yMin, float *xMax, float *yMax);
	int		CalcPerimeterYcoor ( float X, float *Yh, float *Yl);

// virtual function overrides
public:
	int SpliceChords();
	CPiece * GetPiece(const char *label);
	void		SetDrawOptions(const char *options);
	void		CreateJetSet(CStdioFile *fp);
	void		CreateAutoSet(CStdioFile *fp);
	int			Cut(const char *dbName, bool append = true, bool nodupcheck = false);
	int			Cut(CDbData *pDb, bool append = true, bool nodupcheck = false);
	CPiece *	GetPiece(int num);
	CPiece *	GetFirstPiece(int type);
	int				AddToSymbolTable(CSymbolTable *pSymTab);
	int				AddPieceToSymbolTable(CSymbolTable *pSymTab, int option = FIRST_PIECE);
	int				AddPlateToSymbolTable(CSymbolTable *pSymTab, int option = FIRST_PLATE);
	int				AddBearingToSymbolTable(CSymbolTable *pSymTab, int option = FIRST_PIECE);
	virtual int		Draw(CCad *pCad);
	virtual int		Draw(CPrintDoc *pPrintDoc);
	virtual void	Reset();

protected:
	void GetNumPitchBreaks(int type, short& num, short& numPB);
private:
	void CheckSpliceLocation(CPiece *pPiece, float *xDist);
	void SplicePieceAt(CPiece *, float);
	POSITION m_piecePos;
	POSITION m_platePos;
	POSITION m_bearingPos;
public:
	int m_Wind_Cantilever;	// 0 = none, 1 = left, 2 = right, 3 = both
	int m_Wind_Porch;				// 0 = none, 1 = left, 2 = right, 3 = both
	int m_Wind_EndVert;			// 0 = none, 1 = left, 2 = right, 3 = both
	int m_SprinklerLoad;		// 0=no, 1=yes
	int m_ACLoad;						// 0=no, 1=yes
	int m_DragLoad;					// 0=no, 1=yes
	int m_ManualLoad;				// 0=no, 1=yes
	float m_Wind_MeanRoofHeight;
	float m_Wind_TCDL;
	float m_Wind_BCDL;
	float m_Wind_Speed;
	CString m_Wind_ExposureCategory;


	float m_DurFactor;
};


#endif // sentry
