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
//@doc SRGraphLabelBlock
//@module SRGraphLabelBlock.h|  definition of the graph label block class<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

/////////////////////////////////////////////////////////////
//
// SRGLabelBlock.h: definition of the graph label block component class
//
/////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#ifndef __SRGRAPHLABELBLOCK__
#define __SRGRAPHLABELBLOCK__


////////////////////////////////////////////////////////
// Autoduck comment block for SRGraphLabelBlock
//
//@doc SRGraphLabelBlock

//@mdata POSITION  | SRGraphLabelBlock | m_LastPos | Last POSITION accessed in indexing the labels -- used in the list access speed-up code
//@doc SRGraphLabelBlock
//@mdata int  | SRGraphLabelBlock | m_nLastIndex | Last index accessed while indexing the labels -- used in the list access speed-up code

//@mdata int  | SRGraphLabelBlock | m_nBlockTitle | Set TRUE if this block should be titled (reserved for future expansion)

//@mdata BOOL  | SRGraphLabelBlock | m_bCheckOverlaps | When set, the labels within this block will be checked for overlaps

//@mdata CRect  | SRGraphLabelBlock | m_BlockRect | Rectangle of screen covered by the label block after pass 0 or pass 1 processing

//@mdata BOOL  | SRGraphLabelBlock | m_bLogTickPositions | Semaphore which enables the logging of label locations in a tick list

//@mdata BOOL  | SRGraphLabelBlock | m_bUseMyOwnTickList | Set by the label block when a tick logging request is made but no tick list is provided

//@mdata CObList  | SRGraphLabelBlock | m_LabelList | List of SRGraphLabel objects to be displayed in this block

//@mdata CPtrList *  | SRGraphLabelBlock | m_pTickPositionList | Pointer to the tick position list that this label block maintains

//@mdata CSize  | SRGraphLabelBlock | m_TotalBlockSize | Accumulated unrotated size of the label block

//@mfunc void  | SRGraphLabelBlock | DrawBorder | Overridden to prevent the drawing of a component panel 

//@mfunc void  | SRGraphLabelBlock | DrawFill | Overridden to prevent the drawing of a component panel

//@mfunc void  | SRGraphLabelBlock | DrawShadow | Overridden to prevent the drawing of a component panel

//@mfunc virtual BOOL  | SRGraphLabelBlock | GetCheckOverlaps | Returns the anti-collision test semaphore

//@mfunc virtual CRect  | SRGraphLabelBlock | GetBlockRect | Returns a rectangle calculated to fully cover the drawn block

//@mfunc virtual void  | SRGraphLabelBlock | SetPass | Initializes the pass semaphore to allow pre-draw sizing of the labels or actual drawing
//@parm BOOL  | b | FALSE to indicate preparation pass, TRUE to indicate drawing pass (no longer used) 

//@mfunc virtual BOOL  | SRGraphLabelBlock | GetPass | Returns the pass semaphore that allows pre-draw sizing of the labels or actual drawing (no longer used)

//@mfunc virtual void  | SRGraphLabelBlock | SetptrTickPositionList | Initializes the pointer to the block's tick list
//@parm CPtrList * | ptr | Pointer to the predefined position list

//@mdata BOOL  | SRGraphLabelBlock | m_bPass1 |  When reset - label placement and sizing takes place but no text is output, 
//When set - the text is generated (no longer used)

//@mfunc virtual void  | SRGraphLabelBlock | SetCheckOverlaps | Enables or disables the block's anti-collision feature
//@parm BOOL  | b | TRUE to check for overlaps

//@mfunc virtual void  | SRGraphLabelBlock | SetLogTickPositions | Enables or disables the tick position logging feature
//@parm BOOL  | b | TRUE to enable logging 


//adinsert
//$head Component classes
//$level 1


//@class Manages blocks of SRGraphLabel objects
//@base public | SRGraphLabel
//@rem Label blocks may perform anti-collision calculations on labels which they control. 
//If this facility is enabled, then any label found to be overlapping another may optionally 
//be removed or moved in a specific direction.<nl>
//Label blocks are also capable of maintaining a list of points, effectively the points at 
//which each label was displayed, for the positioning of tick marks or grid lines.
class SRGraphLabelBlock : public SRGraphLabel
{
//@access protected data members
protected:
	//@cmember
	/* When reset - label placement and sizing takes place but no text is output, */
	//when set - the text is generated (no longer used)
	BOOL m_bPass1; // Note: no longer used but left in to preserve class data
	//@cmember
	/* Set by the label block when a tick logging request is made but no tick list is provided*/
	BOOL m_bUseMyOwnTickList;
	//@cmember
	/* When TRUE, the label block checks all labels for overlaps and performs anti-collision vectoring*/
	BOOL m_bCheckOverlaps;
	//@cmember
	/* Rectangle of the screen covered by the label block -- determined during pass 0 or pass 1 processing*/
	CRect m_BlockRect;
	//@cmember
	/* Accumulated unrotated size of the label block*/
	CSize m_TotalBlockSize;
	//@cmember
	/* List of SRGraphLabel objects that this block holds*/
	CObList m_LabelList;
	//@cmember
	/* Enables the logging of label locations in a tick list*/
	BOOL m_bLogTickPositions;
	//@cmember
	/* Pointer to the tick position list which this label block maintains*/
	CPtrList * m_pTickPositionList;

//@access public member functions
public:
	virtual void SetParent(SRGraph * pParent);
	//@cmember
	/* Updates the tick list without an offset*/
	virtual void UpdateTickList();
	//@cmember
	/* Creates the labels*/
	virtual void CreateLabels();
	//@cmember
	/* Returns the number of labels in this block*/
	virtual int GetLabelCount();
	//@cmember
	/* Removes and deletes the "tail" label from the label list*/
	virtual void RemoveLastLabel();
	//@cmember
	/* Removes and deletes all labels in the list*/
	virtual void KillLabels();
	//@cmember
	/* Initializes the pass semaphore to allow pre-draw sizing of the labels or actual drawing*/
	virtual void SetPass(BOOL b){SRGraphComponent::SetPass(b);}
	//@cmember
	/* Interrogates the m_bPass member*/
	virtual BOOL GetPass(){return (BOOL)m_bPass;}
	//@cmember
	/* Adds a label or updates a label in an indexed position*/
	virtual void AddLabelIndex(LPCTSTR LabelText,int nIndex,int nCode=1);
	//@cmember
	/* Transfers all label locations to a list for use when drawing grid lines and tick marks*/
	virtual void UpdateTickList(int nOffsetX,int nOffsetY);
	//@cmember
	/* Retrieves a label from the list referenced by index*/
	virtual SRGraphLabel * GetLabelIndex(int nIndex);
	//@cmember
	/* Adds a label to the tail of the label list*/
	virtual void AddLabel(SRGraphLabel *label,BOOL bUseLocalFont=FALSE);
	//@cmember
	/* Globally sets the location points for all labels in the block*/
	virtual void SetBlockLocationPoints(int nLocationPoint);
	//@cmember
	/* Globally sets the orientation angles for all labels in the block*/
	virtual void SetBlockOrientations(double dAngle);
	//@cmember
	/* "Pegs" all labels in a block along a line between the two points supplied*/
	virtual void SetBlockPositions(CPoint StartPoint, CPoint EndPoint);
	//@cmember
	/* Globally sets the anti-collision vectors for all labels in the block*/
	virtual void SetBlockVectors(double dVectorX,double dVectorY);
	//@cmember
	/* Adds a label to the list (overload)*/
	virtual void AddLabel(LPCTSTR strLabelText);
	//@cmember
	/* Returns a rectangle calculated to fully cover the drawn block*/
	virtual CRect GetBlockRect(){return m_BlockRect;}
	//@cmember
	/* Initializes the pointer to the block's tick list*/
	virtual void SetptrTickPositionList(CPtrList *ptr){m_pTickPositionList=ptr;}
	//@cmember
	/* Enables or disables the tick position logging feature*/
	virtual void SetLogTickPositions(BOOL b){m_bLogTickPositions=b;}
	//@cmember,mfunc
	/* Retrieves the pointer to the tick position list associated with this label block*/
	virtual CPtrList *GetptrTickPositionList(){return m_pTickPositionList;}
	//@cmember
	/* Enables or disables the block's anti-collision feature*/
	virtual void SetCheckOverlaps(BOOL b){m_bCheckOverlaps=b;}
	//@cmember
	/* Returns the anti-collision test semaphore*/
	virtual BOOL GetCheckOverlaps(){return m_bCheckOverlaps;}
	//@cmember
	/* Constructor	*/
	SRGraphLabelBlock();
	//@cmember
	/* Destructor*/
	virtual ~SRGraphLabelBlock();

	DECLARE_SERIAL(SRGraphLabelBlock);
	//@cmember
	/* Allows storage or retrieval via the archive*/
	virtual void Serialize(CArchive &ar);

//@cmember,menum
/* Block title positions*/
enum BlockTitle {
	None,
	Above,
	Right,
	Below,
	Left
	} ;



//@cmember,menum
/* May be used instead of a positive integer index to return the first or last label on the list*/
enum LabelPositions {
	LabelFirst=-1,	//@@emem Get the first on the list -1
	LabelLast=-2	//@@emem Get the last -2
	} ;


//@access protected member functions
protected:
	//@cmember
	/* Overridden to prevent the drawing of a component panel*/
	void DrawBorder(){};
	//@cmember
	/* Overridden to prevent the drawing of a component panel*/
	void DrawFill(){};
	//@cmember
	/* Overridden to prevent the drawing of a component panel*/
	void DrawShadow(){};
	//@cmember
	/* Sizes or draws the text with anti-collision if enabled*/
	void DrawForeground();

//@access Protected data members
protected:
	//@cmember
	/* List class position storage for speed-up code*/
	POSITION m_LastPos;
	//@cmember
	/* List class index number for speed-up code*/
	int m_nLastIndex;
	//@cmember
	/* Reserved*/
	int m_nBlockTitle;
};

#endif //__SRGRAPHLABELBLOCK__

// Reset DLL declaration context
#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

