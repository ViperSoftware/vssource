// TrussPlate.h: interface for the CTrussPlate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRUSSPLATE_H__9FEA8E50_C18E_4682_8BD4_65A35EFB2C77__INCLUDED_)
#define AFX_TRUSSPLATE_H__9FEA8E50_C18E_4682_8BD4_65A35EFB2C77__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "\VSSource\Inserts\XGeometry.h"

typedef union misc_vars
{  char   c;
   int    i;
   long   l;
   float  f;
   double d;
} MISC_VAR;

typedef enum                { NO_LABEL,
                              PREPEND,
                              APPEND,   
                              TW_LABEL } PEND;

typedef enum                { PLATE_ON_FACE,
                              PLATE_ON_SIDE,
                              PLATE_FRONT_ONLY,
                              PLATE_BACK_ONLY  } PLATE_PLANE;


class CTrussPlate : public CObject  
{
public:
	int GetQty();
	float GetArea();
	CTrussPlate();
	virtual ~CTrussPlate();

unsigned short  m_Type;
CString         m_Name;
double			m_Width;
double			m_Length;
CXPoint         m_Points[4];
CXPoint         m_Center;
double			m_Angle;
short int       m_Side;  
short int       m_Label_Side;   
CString         m_Label;
MISC_VAR        m_Shift_Var[6];
short int       m_JointNumber;
short int		m_FloorSplice;  // 0 = no, 1 = yes
CString			m_Location;  // T or B

};

#endif // !defined(AFX_TRUSSPLATE_H__9FEA8E50_C18E_4682_8BD4_65A35EFB2C77__INCLUDED_)
