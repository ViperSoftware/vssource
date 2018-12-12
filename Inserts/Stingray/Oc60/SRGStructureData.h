//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//@doc SRGStructureData
//@module SRGStructureData.h | SRGStructureData header file<nl>
//Includes SRGShortStructData, SRGIntStructData, SRGCharStructData, 
//SRGDoubleStructData, and SRGFloatStructData<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////////
//
// SRGStructureData.h: Interface of the SRGStructureData classes
//
//////////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif



#if !defined(AFX_SRGSTRUCTUREDATA_H_INCLUDED_)
#define AFX_SRGSTRUCTUREDATA_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SRGDat.h"

//$head Structure data classes
//$level 1

/////////////////////////////
// AutoDuck tag block for SRGStructureData 

//@doc SRGStructureData
//@mfunc virtual void  | SRGStructureData | SetValue | Sets a char value in the structure 
//@parm  | _TCHAR | Char value to set 

//@mfunc virtual void  | SRGStructureData | SetValue | Sets a double value in the structure 
//@parm  | double | Double value to set

//@mfunc virtual void  | SRGStructureData | SetValue | Sets an int value in the structure 
//@parm  | int | Integer value to set

//@mfunc virtual void  | SRGStructureData | SetStructure | Sets the pointer to the memory block to be accessed
//@parm void *  | v | Void pointer to a memory block

//@mfunc virtual void * | SRGStructureData | GetStructure | Returns the pointer to the memory block

//@mfunc virtual void  | SRGStructureData | SetStructureSize | Sets the stepping interval for locating the next structure in the array 
//@parm int  | v | Size to be used to determine the address difference between successive structures in the memory block 

//@mfunc virtual int  | SRGStructureData | GetStructureSize | Returns the current structure size (stepping interval) 

//@mfunc virtual void  | SRGStructureData | SetDataOffset | Sets the offset from the base of the structure to the desired data item 
//@parm int  | v | Byte count offset

//@mfunc virtual int  | SRGStructureData | GetDataOffset | Returns the byte count offset of the current data item within the data structure 

//@mdata void *  | SRGStructureData | m_pStructure | Pointer to a data structure or memory block

//@mdata int  | SRGStructureData | m_nStructureSize | Size of each elemental structure within the memory block

//@mdata int  | SRGStructureData | m_nDataOffset | Offset of the data item within the structure

// adinsert AutoDuck insertion point for SRGStructureData 

//@doc SRGStructureData 
//@class Based upon SRGraphDynamicData, this class adds the ability to connect to external 
//data sources that can be interpreted as an array of data structures in a memory block.
//@base public | SRGraphDynamicData
class SRGStructureData : public SRGraphDynamicData  
{
public:
	//@cmember
	/* Sets the grow size to zero -- can't expand external data*/
	virtual void SetGrowSize(UINT nSize=0);
	//@cmember
	/* Override to set char values*/
	virtual void SetValue(_TCHAR){};
	//@cmember
	/* Override to set double values*/
	virtual void SetValue(double){};
	//@cmember
	/* Override to set int values*/
	virtual void SetValue(int){};
	//@cmember
	/* 	Returns the buffer grow size (zero)*/
	virtual UINT GetGrowSize();
	//@cmember
	/* 	Override to roll the structure data in the memory block*/
	virtual void Roll(double dValue,BOOL bDirection);
	//@cmember
	/* Sets the buffer size (the number of structures in the memory block)*/
	virtual void SetBufferSize(UINT size);
	//@cmember
	/* Constructor*/
	SRGStructureData();
	//@cmember
	/* 	Destructor*/
	virtual ~SRGStructureData();
	//@cmember
	/* 	Sets a pointer to the memory block*/
	virtual void SetStructure(void * v){m_pStructure=v;}
	//@cmember
	/* 	Returns the current pointer to the memory block*/
	virtual void * GetStructure(){return m_pStructure;}
	//@cmember
	/* 	Sets the size of the structures within the buffer*/
	virtual void SetStructureSize(int v){m_nStructureSize=v;}
	//@cmember
	/* 	Returns the size of the structures within the buffer*/
	virtual int GetStructureSize(){return m_nStructureSize;}
	//@cmember
	/* Sets the offset of the desired data item within the structure*/
	virtual void SetDataOffset(int v){m_nDataOffset=v;}
	//@cmember
	/* Returns the offset of the desired data item within the structure */
	virtual int GetDataOffset(){return m_nDataOffset;}
	//@cmember
	/* Increments the input index*/
	virtual void IncrementInput();
	//@cmember
	/* Increments the output index*/
	virtual void IncrementOutput();
	//@cmember
	/* Decrements the input index*/
	virtual void DecrementInput();
	//@cmember
	/* Decrements the output index*/
	virtual void DecrementOutput();
	
protected:
	//@cmember
	/* Pointer to the memory block that contains the structures*/
	void * m_pStructure;
	//@cmember
	/* Size in bytes of the structure*/
	int m_nStructureSize;
	//@cmember
	/* Offset of the desired data item within the structure*/
	int m_nDataOffset;

};

/////////////////////////////
// AutoDuck tag block for SRGIntStructData 

// adinsert AutoDuck insertion point for SRGIntStructData 

//@doc SRGIntStructData 
//@class SRGIntStructData is a specialized enhancement of SRGStructureData that retrieves 
//or places an int value at the current position within the array of structures or memory block.
//@base public | SRGStructureData
//@devnote The data value is always cast to double -- the data type that OC expects.
class SRGIntStructData : public SRGStructureData
{
public:
	//@cmember
	/* Constructor*/
	SRGIntStructData();
	//@cmember
	/* Destructor*/
	virtual ~SRGIntStructData();
	//@cmember
	/* Sets an int into the structure at the current position*/
	virtual void SetValue(double v);
	//@cmember
	/* Retrieves an int from the structure at the current position*/
	virtual double GetValue(BOOL bLogData = FALSE);
};

/////////////////////////////
// AutoDuck tag block for SRGCharStructData 

// adinsert AutoDuck insertion point for SRGCharStructData 

//@doc SRGCharStructData 
//@class SRGCharStructData is a specialized enhancement of SRGStructureData that retrieves 
//or places an char value at the current position within the array of structures or memory block.
//@base public | SRGStructureData
//@devnote The data value is always cast to double -- the data type that OC expects.
class SRGCharStructData : public SRGStructureData
{
public:
	//@cmember
	/* Constructor*/
	SRGCharStructData();
	//@cmember
	/* Destructor*/
	virtual ~SRGCharStructData();
	//@cmember
	/* Sets a char into the structure at the current position*/
	virtual void SetValue(double v);
	//@cmember
	/* Retrieves a char from the structure at the current position*/
	virtual double GetValue(BOOL bLogData = FALSE);
};

/////////////////////////////
// AutoDuck tag block for SRGDoubleStructData 

// adinsert AutoDuck insertion point for SRGDoubleStructData 

//@doc SRGDoubleStructData 
//@class SRGDoubleStructData is a specialized enhancement of SRGStructureData that retrieves 
//or places an double value at the current position within the array of structures or memory block.
//@base public | SRGStructureData
//@devnote The data value is always cast to double -- the data type that OC expects.
class SRGDoubleStructData : public SRGStructureData
{
public:
	//@cmember
	/* Constructor*/
	SRGDoubleStructData();
	//@cmember
	/* Destructor*/
	virtual ~SRGDoubleStructData();
	//@cmember
	/* Sets a double into the structure at the current position*/
	virtual void SetValue(double v);
	//@cmember
	/* Retrieves a double from the structure at the current position*/
	virtual double GetValue(BOOL bLogData = FALSE);
};

/////////////////////////////
// AutoDuck tag block for SRGFloatStructData 

// adinsert AutoDuck insertion point for SRGFloatStructData 

//@doc SRGFloatStructData 
//@class SRGFloatStructData is a specialized enhancement of SRGStructureData that retrieves 
//or places a float value at the current position within the array of structures or memory block.
//@base public | SRGStructureData
//@devnote The data value is always cast to double -- the data type that OC expects.
class SRGFloatStructData : public SRGStructureData
{
public:
	//@cmember
	/* Constructor*/
	SRGFloatStructData();
	//@cmember
	/* Destructor*/
	virtual ~SRGFloatStructData();
	//@cmember
	/* Sets a float into the structure at the current position*/
	virtual void SetValue(double v);
	//@cmember
	/* Retrieves a float from the structure at the current position*/
	virtual double GetValue(BOOL bLogData = FALSE);
};

/////////////////////////////
// AutoDuck tag block for SRGShortStructData 

// adinsert AutoDuck insertion point for SRGShortStructData 

//@doc SRGShortStructData 
//@class SRGShortStructData is a specialized enhancement of SRGStructureData that retrieves 
//or places an short value at the current position within the array of structures or memory block.
//@base public | SRGStructureData
//@devnote The data value is always cast to double -- the data type that OC expects.
class SRGShortStructData : public SRGStructureData
{
public:
	//@cmember
	/* Constructor.*/
	SRGShortStructData();
	//@cmember
	/* Destructor.*/
	virtual ~SRGShortStructData();
	//@cmember
	/* Sets a short into the structure at the current position*/
	virtual void SetValue(double v);
	//@cmember
	/* Retrieves a short from the structure at the current position*/
	virtual double GetValue(BOOL bLogData = FALSE);
};

#endif // !defined(AFX_SRGSTRUCTUREDATA_H_INCLUDED_)

// Reset DLL declaration context

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

