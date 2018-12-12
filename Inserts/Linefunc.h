//***keyword-flag*** "File %n | Ver %v | Date %f | Status %l"
//"File LINEFUNC.H | Ver 4 | Date 26-Jan-94,10:47:04 | Status ***_NOBODY_***"
#ifdef __cplusplus
extern "C" {
#endif


#ifndef LOGICAL_Defined
//typedef enum logical { FALSE = 0, TRUE = 1 } LOGICAL;  // WINDOWS conflict
typedef int LOGICAL;
#define LOGICAL_Defined
#endif

#ifndef POINT_2D_Defined
typedef struct two_d_coordinate
{
        float x;
        float y;
}POINT_2D;
#define POINT_2D_Defined
#endif

#ifndef LINE_2D_Defined
typedef struct two_d_line
{
        float xf;
        float yf;
        float xt;
        float yt;
}LINE_2D;
#define LINE_2D_Defined
#endif

#ifndef LINE_PT_SLOPE_Defined
typedef struct ptSlopeLine
{
        POINT_2D point;
        float    vectAngle;
}LINE_PT_SLOPE;
#define LINE_PT_SLOPE_Defined
#endif

typedef struct quadrilateral
{
        POINT_2D a;          // bÚÄÄÄÄÄÄÄÄÄÄÄÄ¿c
        POINT_2D b;          //  ³            ³
        POINT_2D c;          //  ³            ³
        POINT_2D d;          // aÀÄÄÄÄÄÄÄÄÄÄÄÄÙd
}QUAD;

/* Below is cutom line interseciton routine
        __
        ab is the first  line segment.
        __
        cd is the second line segment.

        p  is the point of intersection.
                                                     __     __
        Flags below determine the position of p wrto ab and cd

*/
typedef struct intLines_return_struct
{
        unsigned dum : 8;
        unsigned apb : 1; /* aÄÄÄÄÄÄÄÄÄÄpÄÄÄÄÄÄÄÄÄÄb */
        unsigned cpd : 1; /* cÄÄÄÄÄÄÄÄÄÄpÄÄÄÄÄÄÄÄÄÄd */
        unsigned pab : 1; /* p----ÄaÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄb */
        unsigned abp : 1; /* aÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄb-----p */
        unsigned pcd : 1; /* p-----cÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄb */
        unsigned cdp : 1; /* cÄÄÄÄÄÄÄÄÄÄÄÄd--------p */
        unsigned perp: 1;
        unsigned rest: 1;
}LINE_INT;


typedef struct perpLine_struct
{
        LINE_INT lineint;
        float    distance;
        POINT_2D point;
        float    vectAngle;
}PERP_LN;


PERP_LN *PerpLine( LINE_2D *l, POINT_2D *p, PERP_LN *perpSt );


#ifdef __cplusplus
}
#endif
