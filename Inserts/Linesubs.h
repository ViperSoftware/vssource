#pragma comment (lib, "General.lib") // make linker search this lib

#include "linefunc.h"


#ifndef POINT_2D_Defined
typedef struct two_d_coordinate
{
        float x;
        float y;
}POINT_2D;
#define POINT_2D_Defined
#endif

int   LineInt  ( float, float, float, float, float, float, float, float,
                 float *, float * );
#define LS_PARALLEL     -1
#define LS_OUTSIDE_BOTH 0
#define LS_IN_1ST_ONLY  1
#define LS_IN_2ND_ONLY  2
#define LS_IN_BOTH      3

int   LnIntRjs ( float *, float * );

float PerpDist ( float, float, float, float, float, float );
float Q_PerpDist ( float, float, float, float, float, float );

int   PDWhere  ( float *, float * );

float GetLnRj  ( float, float, float, float, float, float );

void  URjCoors ( float, float, float, float, float, float *, float * );

void  RjCoors  ( float, float, float, float, float, float *, float * );

float LineLen  ( float, float, float, float );

void  MakParLn ( float, float, float, float, float,
                 float *, float *, float *, float * );

void  MakeParL ( float Line1[], float Dist, float Line2[] );

void  MakePerL ( float Line1[], float Rj, float Line2[] );

void MakPerLn (float ,float ,float ,float ,float ,
               float *,float *,float *,float *);

float AreaPolygon(POINT_2D *pts, short numPoints);

int PolyClipLn (float *side_to_keep, int old_numpts, float *old_pl,
                float *clip_ln,     int *new_numpts, float *new_pl);

