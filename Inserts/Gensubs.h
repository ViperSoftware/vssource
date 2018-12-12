// Misc general lib function prototypes

#pragma comment (lib, "General.lib") // make linker search this lib

int		REQ(double Value1,double Value2,int Prec);
int		REQ16(double Value1, double Value2, int Sixteenths);
int		REQ32(double Value1, double Value2);
int		REQ32(double Value1, double Value2, int Thirtyseconds);
float	QfAbs( float v1 );
double Radians (double degrees);

int Index(const char *s, const char *t);
int DecodeDistance(const char *instr, double *number);
int CharToDouble (const char *buf, double *num);

void EncodeDistance (char *String, double Number);
void EncodeSmallDistance (char *String, double Number);
void SetDecimalResolution(int new_resolution);
int  GetDecimalResolution(void); 

int FileCopy (const char *from, const char *to );
int WildUnlink (const char *path);

// direct fileio.cpp functions
int ReadRec(HANDLE );
int WritRec(HANDLE );
int EndFile(HANDLE );
int ResetDat(void );
int SkipDat(int );
int ReadDat(int ,void *);
int WritDat(int ,void *);
int load_int(int *);
int load_float(float *);
int load_char(char *,int );
int writ_char(char *,int );
int RewindRec(int );

