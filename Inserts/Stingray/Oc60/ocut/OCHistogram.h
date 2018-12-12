//////////////////////////////////////////////////////////////////////////////////
//
// Objective Chart Utility Toolkit (OCUT) 
//
// Written by Bob Powell (BobPowell@stingray.com)
//
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1998 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// The text comments in this file are formatted to generate
// a help file on build using Microsoft's free Autoduck tool.
// The help file is available with this source and it is
// recommended that you use this file in conjunction with the
// mfc help files.
//////////////////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_UT_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OCUT_DATA
#endif

#ifndef __OCUTITEM__
#define __OCUTITEM__

/////////////////////////////
// AutoDuck tag block block for OCHistogram 


//@doc OCHistogram
//@mfunc virtual void  | OCHistogram | SetDataDivisions | Initializes the number of slots in the histogram<nl>
//Though the count of data items may be very large the number of slots needed may be quite small. For example an image 
//having 1024 * 768 pixels at 24 bits per pixel will have 786,432 pixels. To create a histogram of all the red pixels 
//will require 256 slots (one for each red-pixel brightness level) and a data count of 786,432 for the scan.
//@parm int  | v | The number of slots desired


//@doc OCHistogram
//@mfunc virtual int  | OCHistogram | GetDataDivisions | Returns the number of slots programmed for his histogram.


//@doc OCHistogram
//@mfunc virtual void  | OCHistogram | SetScanCount | Sets the number of data items to be considered in a single scan.
//@parm int  | v | The actual number of items to use


//@doc OCHistogram
//@mfunc virtual int  | OCHistogram | GetScanCount | Returns the number of items programmed for the scan


//@doc OCHistogram
//@mdata CScale  | OCHistogram | m_Scale | This scale is used to determine the full range of data used in the histogram. This scale is divided by 
//the number of slots to give the final value for each slot.

//@doc OCHistogram
//@mdata int  | OCHistogram | m_nScanCount | This data member sets the number of items to be scanned.

//@doc OCHistogram
//@mdata int  | OCHistogram | m_nDataDivisions | This sets the number of slots used in the histogram.

// adinsert AutoDuck insertion point for OCHistogram 
//@doc OCHistogram 
//@class This class allows the simple generation of a histogram for any given set of data.<nl><nl>
//@head2 How to use this class.<nl><nl>|
//After the initial creation of the class SetDataDivisions should be called to initialize the number of slots in the chart.<nl>
//Then use SetScanCount to initialize the number of data items to be scanned. once this is accomplished each data item may be 
//added to the total by calling AddToScan once for each value. This process is used to ascertain the overall range of data in the set.<nl>
//When all data items have been scanned they are then processed by assigning them one by one to thier slots using the AddData function.<nl>
//The chart is drawn by the Paint() function in the base class.
class OCHistogram : public OCutItem 
{
public:
	//@cmember
	/* Removes data items from the scan and cleans the chart */
	virtual void Clear();
	//@cmember
	/* Adds the value to the scaling value */
	virtual void AddToScan(double d);
	//@cmember
	/* resets the data before the beginning of a scan. Does not reset the chart */
	virtual void ResetScan();
	//@cmember
	/* adds one data item to the scan. Data is assigned to the correct slot  */
	virtual void AddData(double d);
	//@cmember
	/* Creates the components for the chart. */
	virtual void SetupComponents();
	//@cmember
	/* removes data and initializes the correct number of indices */
	virtual void InitializeData();
	//@cmember
	/* constructor */
	OCHistogram();
	//@cmember
	/* destructor */
	virtual ~OCHistogram();
	//@cmember
	/* sets the number of data divisions to use in this histogram  */
	virtual void SetDataDivisions(int v){m_nDataDivisions=v;}
	//@cmember
	/* Returns the number of data divisions used in this histogram */
	virtual int GetDataDivisions(){return m_nDataDivisions;}
	//@cmember
	virtual void SetScanCount(int v){m_nScanCount=v;}
	//@cmember
	/* Returns the number of items to be scanned */
	virtual int GetScanCount(){return m_nScanCount;}

protected:
	//@cmember
	/* The scale to use in determining the slots */
	CScale m_Scale;
	//@cmember
	/* The count of data items to be scanned */
	int m_nScanCount;
	//@cmember
	/* the number of data divisions in the histogram */
	int m_nDataDivisions;

};


#endif

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
