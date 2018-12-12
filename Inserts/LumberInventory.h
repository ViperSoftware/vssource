// LumberInventory.h: interface for the CLumberInventory class.
//
//////////////////////////////////////////////////////////////////////
#include "\VSSource\inserts\DBdata.h"
#include <stdlib.h>
#include <malloc.h>


#if !defined(AFX_LUMBERINVENTORY_H__37596C44_EE01_4D14_8996_9467C4A369B2__INCLUDED_)
#define AFX_LUMBERINVENTORY_H__37596C44_EE01_4D14_8996_9467C4A369B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#define LEAST_COST 1
#define NEXT_LENGTH 2
#define NEXT_GRADE 3
#define NEXT_LENGTH_THEN_GRADE 4

typedef struct Price_struct  {    float length;
                                    int NomLength;
                                  float price;
																	float AvgCost;
                    struct Price_struct *next; } *PRICEPTR;

typedef struct Grade_struct  {    short grade;
                                   char GradeName[32];
									char AliasNames[512];
                                   char usage[10];
                               PRICEPTR price;
                    struct Grade_struct *next; } GRADE, *GRADEPTR;

typedef struct Size_struct   {    float size;
                                  float thickness;
                                  float volumefactor;   /* used for board foot calculations*/
                                   char label[20];
                               GRADEPTR grade;
                     struct Size_struct *next;} *SIZEPTR;


class CLumberInventory  
{
public:
	CLumberInventory();
	virtual ~CLumberInventory();


SIZEPTR		size_root;
GRADEPTR	grade_root;
PRICEPTR    price_root;

int			search_change_grade;
float		Smallest_Distance;

SIZEPTR		SearchSize(LPCTSTR sizename);
GRADEPTR	SearchGrade(SIZEPTR Sp, LPCTSTR grade);
PRICEPTR	SearchPrice ( GRADEPTR Gp, float length);
PRICEPTR	Get_Next_Price ( PRICEPTR Pp );
PRICEPTR	Get_Next_Grade_Price (GRADE **Gp, float length, short type);
void		GetPrice (float size, float thickness, short *grade, float *length,
               float *price, short search,const char *label,float *bdftout, short type);
GRADEPTR	AddGrade(SIZEPTR size_ptr, short grade, LPCTSTR name);
void			AddGradeAlias(GRADEPTR grade_ptr, LPCTSTR alias);
int				AddPrices(GRADEPTR grade_ptr,float price,float cost,float length);
SIZEPTR		AddSize(float size, LPCTSTR label,
                 float  thickness, float volumefactor);
void		ReadLumberInv(const char *filename);
int			ReadLumberInv(CDbData *pDB, const char *LumCode);

void		Reset();

};

#endif // !defined(AFX_LUMBERINVENTORY_H__37596C44_EE01_4D14_8996_9467C4A369B2__INCLUDED_)
