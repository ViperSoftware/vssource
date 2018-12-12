// TrussBearing.h: interface for the CTrussBearing class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRUSSBEARING_H__3F52B64F_C3CF_4679_912E_3A94E21C6EFD__INCLUDED_)
#define AFX_TRUSSBEARING_H__3F52B64F_C3CF_4679_912E_3A94E21C6EFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define DOUBLE_PLATE    1
#define SINGLE_PLATE    2
#define CONCRETE_BEAM   3
#define GIRDER_FACE     4
#define GIRDER_TOP_EDGE 5
#define BEAM_FACE       6
#define BEAM_TOP_EDGE   7
#define SINGLE_LEDGER   8
#define DOUBLE_LEDGER   9
#define SLANT_TRUSS     10

#define BRG_REFEDGE_LEFT   1
#define BRG_REFEDGE_CENTER 2
#define BRG_REFEDGE_RIGHT  3


class CTrussBearing : public CObject  
{
public:
	CTrussBearing();
	virtual ~CTrussBearing();

  float     Size,                //Actual size in feet
            Xpt,                 //Upper left corner in feet. Required.
            Ypt;                 //Bearings must draw at proper location.
  short int Ref_edge,            //Use above defines (1=left,2=center,3=right)
            Type;                //Bearing type
  short int Bearing_plate_type,  //Type of bearing hanger/truss 
            Bearing_plate_size,  //Size of member hanger attached to
            Bearing_plate_mems;  //Number of members supporting hanger
  float		MaxGravity,
			MaxUplift;
  int		GravityJointID;
  int		UpliftJointID;

};

#endif // !defined(AFX_TRUSSBEARING_H__3F52B64F_C3CF_4679_912E_3A94E21C6EFD__INCLUDED_)
