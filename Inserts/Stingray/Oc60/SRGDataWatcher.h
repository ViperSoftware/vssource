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
//@doc SRGDataWatcher
//@module SRGDataWatcher.h | SRGDataWatcher header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGDataWatcher.h: interface for the SRGDataWatcher class.
//
//////////////////////////////////////////////////////////////////////


#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif

#if !defined(_SRGDATAWATCHER_H_INCLUDED_)
#define _SRGDATAWATCHER_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////
// AutoDuck tag block for SRGDataWatcher 


//@doc SRGDataWatcher
//@mfunc void  | SRGDataWatcher | SetScanType | Sets the type of scan to be used 
//@parm int  | n | Scan type...<nl>
//0 = above limit <nl>
//1 = below limit <nl>
//2 = average above limit <nl>
//3 = average below limit <nl>
//4 = out of bracket <nl>
//5 = in bracket <nl>
//6 = average out of bracket <nl>
//7 = average in bracket <nl>

//@mfunc int  | SRGDataWatcher | GetScanType | Returns the scan type

//@mfunc void  | SRGDataWatcher | SetLinkToDisplay | Sets a flag linking the watcher to the next display 
//component in the list
//@parm BOOL  | b | TRUE to set the link
//@rem This only applies to items on the main component list -- 
//data watchers in the compound display are handled by their respective axis managers.

//@mfunc BOOL  | SRGDataWatcher | GetLinkToDisplay | Returns the display linking flag

//@mfunc void  | SRGDataWatcher | SetHighLimit | Sets the value of the high limit 
//@parm double | d | Number for the upper limit

//@mfunc void  | SRGDataWatcher | SetLowLimit | Sets the value for the lower limit
//@parm double | d | Number for the lower limit

//@mfunc double  | SRGDataWatcher | GetHighLimit | Returns the value for the high limit

//@mfunc double  | SRGDataWatcher | GetLowLimit | Returns the value for the low limit

//@mfunc void  | SRGDataWatcher | SetVisible | Sets the visibility of this data watcher<nl>
//If visible (TRUE) then the data watcher will draw a control limit line in the m_DisplayRect rectangle.
//@parm BOOL  | v | TRUE to make this watcher visible

//@mfunc BOOL  | SRGDataWatcher | GetVisible | Returns the visibility flag

//@mfunc void  | SRGDataWatcher | SetGroupStep | Sets the step size for incrementing group counters
//@parm int  | v | Positive integer greater than zero

//@mfunc void  | SRGDataWatcher | SetIndexStep | Sets the step size for incrementing index counters
//@parm int  | v | Positive integer grater than zero

//@mfunc int  | SRGDataWatcher | GetGroupStep | Returns the group increment

//@mfunc int  | SRGDataWatcher | GetIndexStep |Returns the index increment

//@mdata int  | SRGDataWatcher | m_nGroupStep | Positive integer by which group counters are incremented during scanning

//@mdata int  | SRGDataWatcher | m_nIndexStep | Positive integer by which index counters are incremented during scanning

//@mdata BOOL  | SRGDataWatcher | m_bVisible | Visibility flag<nl>
//When TRUE, line is drawn to indicate the control limit.

//@mdata BOOL  | SRGDataWatcher | m_bLinkToDisplay | Display link flag<nl>
//When TRUE this watcher will link its scope to the next available display.

//@mdata double  | SRGDataWatcher | m_dHighLimit | High limit value

//@mdata double  | SRGDataWatcher | m_dLowLimit | Low limit value

//@mdata int  | SRGDataWatcher | m_nScanType | Scan type -- see <mf SRGDataWatcher::SetScanType>

// adinsert AutoDuck insertion point for SRGDataWatcher 

//$head Component classes
//$level 1

//@doc SRGDataWatcher 
//@class The SRGDataWatcher class provides a simple method for monitoring data levels and 
//triggering events or highlighting data should the scanned items exceed certain preset limits.
//@base public | SRGGridLines
class SRGDataWatcher : public SRGGridLines  
{
public:
	//void DrawExtra(); //To be added for 6.1 to draw watchers on displays.
	//@cmember
	/* Overridden to prevent the base class function from effecting this object*/
	virtual void SetptrTickPointerList(CPtrList *p);
	//@cmember
	/* Saves or retrieves this data watcher via the archive*/
	virtual void Serialize(CArchive &ar);
	//@cmember
	/* Removes the highlight from a data object if it no longer causes an excursion*/
	virtual void UnmarkExcursion(int index,int group);
	//@cmember
	/* Flags an excursion for a particular data object -- must be overridden by your application if used*/
	virtual void FlagExcursion(int index, int group);
#ifndef _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Writes the datawatcher parameters to a template*/
	virtual void WriteSpecificParameters(CStdioFile *pFile);
	//@cmember
	/* Writes the name of this object to a template*/
	virtual void WriteName(CStdioFile *pFile);
#endif	// _OC_DONT_SUPPORT_TEXT_TEMPLATE
	//@cmember
	/* Scans the data scope applying the current criteria and calls either DataInRange or DataExcursion*/
	virtual void Draw(CDC *pDC,CWnd *pCWnd);
	DECLARE_SERIAL(SRGDataWatcher)
	//@cmember
	/* Construction*/
	SRGDataWatcher();
	//@cmember
	/* Destruction*/
	virtual ~SRGDataWatcher();
	//@cmember
	/* Sets the type of scan to be used */
	virtual void SetScanType(int n){m_nScanType=n;}
	//@cmember
	/* Returns the scan type*/
	virtual int GetScanType(){return m_nScanType;}
	//@cmember
	/* Set flag linking the watcher to the next display component in the list*/
	virtual void SetLinkToDisplay(BOOL b){m_bLinkToDisplay=b;}
	//@cmember
	/* Returns flag linking the watcher to a display component*/
	virtual BOOL GetLinkToDisplay(){return m_bLinkToDisplay;}
	//@cmember
	/* Sets the value of the high limit */
	virtual void SetHighLimit(double d){m_dHighLimit=d;}
	//@cmember
	/* Sets the value of the low limit */
	virtual void SetLowLimit(double d){m_dLowLimit=d;}
	//@cmember
	/* Returns the value of the high limit */
	virtual double GetHighLimit(){return m_dHighLimit;}
	//@cmember
	/* Returns the value of the low limit */
	virtual double GetLowLimit(){return m_dLowLimit;}
	//@cmember
	/* Sets the visibility flag*/
	virtual void SetVisible(BOOL v){m_bVisible=v;}
	//@cmember
	/* Returns the visibility flag*/
	virtual BOOL GetVisible(){return m_bVisible;}
	//@cmember
	/* Sets the step size for incrementing group counters*/
	virtual void SetGroupStep(int v){m_nGroupStep=v;}
	//@cmember
	/* Sets the step size for incrementing index counters*/
	virtual void SetIndexStep(int v){m_nIndexStep=v;}
	//@cmember
	/* Returns the step size for incrementing group counters*/
	virtual int GetGroupStep(){return m_nGroupStep;}
	//@cmember
	/* Returns the step size for incrementing index counters*/
	virtual int GetIndexStep(){return m_nIndexStep;}


protected:
	//@cmember
	/* Sets scan levels according to your own custom system*/
	virtual void SetCustomScanLevels();
	//@cmember
	/* Draws a control limit line or lines on the chart -- if this object is a subcomponent */
	virtual void DrawForeground();

	//@cmember
	/* Gets data scope from linked display component if m_bLinkToDisplay is set*/
	virtual void GetWorkingScope();
	//@cmember
	/* Sets the highlight style of the data object that caused the excursion*/
	virtual void MarkExcursion(int index, int group);
	//@cmember
	/* Override to signal an out-of-range event*/
	virtual void DataExcursion();
	//@cmember
	/* Override to signal an in-range event*/
	virtual void DataInRange();
	//@cmember
	/* Performs a data scan over the scope */
	virtual void DataScan();

	//@cmember
	/* Performs data checking for "above limit" scan type*/
	virtual BOOL ScanAboveLimit();
	//@cmember
	/* Performs data checking for "below limit" scan type*/
	virtual BOOL ScanBelowLimit();
	//@cmember
	/* Performs data checking for "average above limit" scan type*/
	virtual BOOL ScanAverageAboveLimit();
	//@cmember
	/* Performs data checking for "average below limit" scan type*/
	virtual BOOL ScanAverageBelowLimit();
	//@cmember
	/* Performs data checking for "in bracket" scan type*/
	virtual BOOL ScanInBracket();
	//@cmember
	/* Performs data checking for "out of bracket" scan type*/
	virtual BOOL ScanOutOfBracket();
	//@cmember
	/* Performs data checking for "average in bracket" scan type*/
	virtual BOOL ScanAverageInBracket();
	//@cmember
	/* Performs data checking for "average out of bracket" scan type*/
	virtual BOOL ScanAverageOutOfBracket();
	//@cmember
	/* Performs data checking for custom scan types -- must be overriden if used*/
	virtual BOOL ScanCustom();

	// data members
	//@cmember
	/* Step size for incrementing group counters*/
	int m_nGroupStep;
	//@cmember
	/* Step size for incrementing index counters*/
	int m_nIndexStep;
	//@cmember
	/* Visibility flag*/
	BOOL m_bVisible;
	//@cmember
	/* Flag linking the watcher to the next display component in the list*/
	BOOL m_bLinkToDisplay;
	//@cmember
	/* High limit value*/
	double m_dHighLimit;
	//@cmember
	/* Low limit value*/
	double m_dLowLimit;
	//@cmember
	/* Type of data checking to do*/
	int m_nScanType;

};

#endif // !defined(_SRGDATAWATCHER_H_INCLUDED_)


#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

