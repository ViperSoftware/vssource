
#if !defined(PIECECUT_H)
#define PIECECUT_H
#define PIECECUT_REC_LENGTH 162

#define MAXPCPIECES 256

typedef struct piececut_hdr  {
    char  HeaderFl[10] ;
    short TotRecs ;
    short j_keychg;
    char  OldJobKey[10];
    char  Filler[138] ;
  } PIECECUT_HDR;

typedef struct piececut_truss_hdr {
    char  HeaderFl[10] ;
    float SeqNumber,
          OASpan,
          TCSlope,
          BCSlope;
    short NumTrussPlys;
    float LeftOH,
          RightOH;
    char  TrussType[4],
          TrussDesc[32];
    float LeftOHcut,
          RightOHcut,
          ChordBdFt,
          WebBdFt,
          MiscBdFt,
          SawType;
    char  JobKey[10],
          JobMark[10];
    short NumPieces;
    char  JobTag[8];      //Truss tag (pic)
    char  Filler[36] ;  } PIECECUT_TRUSS_HDR;

typedef struct Point_Piececut_Data_Struct {
    float x,
          y,
          Length,
          Angle;} POINT_PIECECUT_DATA;

typedef struct Piece_Piececut_Data_Struct  {
    struct Piece_Piececut_Data_Struct *Next ;
    short                          Type;
    short                          PieceNum;
    float                          Size;
    char                           GradeName[30];
    char                           Label[10];
    short                          NumCutsL,
                                   NumCutsR,
                                   TtlEdgs;
    float                          TopLen,
                                   BotLen,
                                   OverallLen,
                                   CenterLen,
                                   NominalLength;
    unsigned short                 GradeNum;
    short                          DupFlag;
    float                          BoardFoot;
    char                           SizeName[20];
    float                          Price;
    unsigned short                 NumPts;
    POINT_PIECECUT_DATA            *Point_Data;
    void                           *SpecialData_Root;
    unsigned short                 Truss_Order; //This is the order which the piece was written
    unsigned short                 Piece_Order; //This is the order which the piece was written
    short                          Qty; // count merged pcs in memory (to elim OF_PIECECUT_PIECE)
	SHORT						   SetupNumber;
  } PIECECUT_PIECE;

typedef struct piececut_piece_rec {
    char  Filler[160];
    char  dum;
    char  EOFmark;
  } PIECECUT_PIECE_REC;


#define BEVEL_STRUCT 1
#define NO_BEVEL 1
#define SINGLE_BEVEL 2
#define DOUBLE_BEVEL 3
#define SQUARE_BEVEL 4

#define  LEFT_END_BEVEL 0
#define RIGHT_END_BEVEL 1

typedef struct BevelData_Struct { short int    struct_type;
                                  void         *next;
                                  unsigned int size;
                                  short int    bevel_type;
                                  float        front_angle;
                                  float        back_angle;
                                  float        offset;
                                  struct{
                                    unsigned int beveled_end:1;
                                    unsigned int      unused:15;
                                  }flags;                  } BEVEL_DATA;

// prototypes

void InitPiececut(void);
int  OpenPiececut (const char *Path);
void ClosePiececut (int option);
int  ReadPiececut (int rec, void *bufr);
int  WritePiececut (int rec, void *bufr);
int  WriteNewPiececutRec (void *bufr);
int  WriteNewPiececutPiece (PIECECUT_PIECE *Pp);
int  SeekToPiececutRecNum (int rec) ;
int  GetLastPiececutRecordWritten (void) ;
int  ReadPiececutTruss (int rec, PIECECUT_TRUSS_HDR *bufr);
int  ReadFirstPiececutTruss (PIECECUT_TRUSS_HDR *bufr);
int  ReadNextPiececutTruss (PIECECUT_TRUSS_HDR *bufr);
int  ReadPiececutPiece (int rec, PIECECUT_PIECE *Pp);
int  ReadFirstPiececutPiece (PIECECUT_PIECE *Pp);
int  ReadNextPiececutPiece (PIECECUT_PIECE *Pp);
void SetKeyInfo (short keychng, char *OldJobKey);
HANDLE GetPiececutFileHandle (void);
void SetPiececutFileHandle (HANDLE FileH);
void TogglePiececutFile (void);
void FreePointData(PIECECUT_PIECE *Pp);
int REQ16 (double Value1,double Value2,int Sixteenths);
int REQ32 (double Value1,double Value2,int Thirtyseconds);
int TrussIsTheSameAsThePreviousTruss(PIECECUT_TRUSS_HDR *PreviousTruss, PIECECUT_TRUSS_HDR *CurrentTruss);
int PieceHasTheSameAnglesAsThePreviousPiece(PIECECUT_PIECE *Pp,PIECECUT_PIECE *PreviousPiece);
int PieceHasTheSameLengthsAsThePreviousPiece(PIECECUT_PIECE *CurrentPiece,PIECECUT_PIECE *PreviousPiece);
int PieceHasTheSameLengthsGradeSizeAsThePreviousPiece(PIECECUT_PIECE *CurrentPiece,PIECECUT_PIECE *PreviousPiece);
int PieceIsTheSameAsThePreviousPiece(PIECECUT_PIECE *PreviousPiece,PIECECUT_PIECE *CurrentPiece);
int GetDupFlag(PIECECUT_PIECE  *pPc1, PIECECUT_PIECE  *pPc2);
int GetDupFlagC(PIECECUT_PIECE  *pPc1, PIECECUT_PIECE  *pPc2);
void SetIgnoreCrowning(short bIgnore);
int WritePiececutPiece ( PIECECUT_PIECE *Pp, int Rec );


#ifdef __AFX_H__
void GroupMatchingPieces(PIECECUT_PIECE *pPcHeader, bool bIgnoreCrowning);
#endif

#endif

