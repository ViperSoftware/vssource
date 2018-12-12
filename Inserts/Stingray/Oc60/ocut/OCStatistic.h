// OCStatistic.h: interface for the OCStatistic class.
//
//////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_UT_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OCUT_DATA
#endif

#if !defined(AFX_OCStatistic_H__027FBE84_FC77_11D1_B2DB_006008AF1D5D__INCLUDED_)
#define AFX_OCStatistic_H__027FBE84_FC77_11D1_B2DB_006008AF1D5D__INCLUDED_


/////////////////////////////
// AutoDuck tag block block for OCStatistic 




//@doc OCStatistic
//@mfunc double   | OCStatistic |  GetStep | Just return the current m_dStep value 



//@doc OCStatistic
//@mfunc int   | OCStatistic |         GetDataDivision | Return the current m_nDivision value


//@doc OCStatistic
//@mfunc double   | OCStatistic |      GetMean | Return the mean of the input data sample


//@doc OCStatistic
//@mfunc double   | OCStatistic |      GetDeviation | Return the deviation of the input data samples









//@doc OCStatistic
//@mdata BOOL  | OCStatistic | m_bOwnIn | Flags for internal use to keep track the input data memory ownership.

//@doc OCStatistic
//@mdata double  | OCStatistic | *m_pOut | Pointer to the output data memory block

//@doc OCStatistic
//@mdata int  | OCStatistic | m_nDivision | Output divided into 2 * m_nDivision items

//@doc OCStatistic
//@mdata double  | OCStatistic | m_dStep | The range inteval to calculate the distribution

//@doc OCStatistic
//@mdata double  | OCStatistic | m_dMean | Mean of the input data samples

//@doc OCStatistic
//@mdata double  | OCStatistic | m_dDev | Deviation of the input data samples

// adinsert AutoDuck insertion point for OCStatistic 
//@doc OCStatistic 
//@class OCStatistic class wraps the statistic chart type. This class manage five groups of
// data by encaptulate them into SRGDoubleStructData, the first group is assumed to the 
// input sample data and the other four groups store the output data after the data has been 
// processed by a call to ProcessData() function. The second and the third groups show the 
// sample distribution, while the forth and the fifth group show the normal distribution with
// same mean and deviation of the samples. These two chart will be overlapped, so the user 
// can easily compare the difference of the two distribution. User can choose to hide 
// and show the normal distribution. The user can also choose to manage the memory
// for the input data or let this class manage the memory. The number of items is 
// 2 * m_nDivision. The output item i is the count of input data samples that are in the range of 
//  (i-m_nDivision)*m_dStep*Deviation+Mean to (i+1-m_nDivision)*m_dStep*Deviation+Mean divided
// by size * m_dStep * Deviation. Here the Deviation and Mean are the deviation and Mean of 
// the input data samples.
// According to Center Limit theroem in the statistics and probability, the most of the samples
// should fall in the range of a few deviation away from the mean of the samples, so the peak
// value is usually in the middle items if the step is close to 1.0.

// Be default the chart use the CX_GRAPH_XYSCATTERG chart type to present the distribution output.
// However, the scatter graph with draw a vertical bar for each data points.


class OCStatistic : public OCutItem  
{
public:
	void SetShowNormal(BOOL v);
	BOOL GetShowNormal();
	//@cmember Set the input data.
	virtual void SetData(int size, double* pIn);
	//@cmember Set a new value to m_dStep, PrecessData() must be called to obtain valid output
	virtual void SetStep(double step);
	//@cmember Return the current m_dStep value.
	double		 GetStep(){return m_dStep; }
	//@cmember Set a new value to m_nDivision. ProcessData() must be called to obtain the valid output
	virtual void SetDataDivision(int d);
	//@cmember Return the current m_nDivision value
	int          GetDataDivision(){ return m_nDivision;}
	//@cmember Return the mean of the input data. ProcessData() must be call before to obtain valid output
	double       GetMean() { return m_dMean; }
	//@cmember Return the deviation of the input data. ProcessData() must be call before to obtain valid output
	double       GetDeviation() { return m_dDev; }
	//@cmember Process the input data to obtain the output data. It should be called
	// whenever m_dStep, m_nDivision and input data changed.
	virtual void ProcessData();
	//@cmember Setup the component for the graph to display the output data.
	virtual void SetupComponents();
	//@cmember not used.
	virtual void InitializeData();
	//@cmember Only kill the data item and free the responsible memory.
	virtual void ClearData();
	//@cmember Kill the component list in the graph and the data list, clear all 
	// resposible memroy.
	virtual void Clear();
	//@cmember Constructor
	OCStatistic();
	//@cmember Destructor 
	virtual ~OCStatistic();
protected:

	//@cmember Flag to keep track of the input data memory ownership
	BOOL m_bOwnIn;
	BOOL m_bShowNormal;
	//@cmember Pointer to the output data memroy block
	double *m_pOutX;
	double *m_pOutY;
	double *m_pNX;
	double *m_pNY;
	//@cmember number of intevals to divide the input data
	int m_nDivision;
	//@cmember The length of the distribution inteval
	double m_dStep;
	//@cmember Mean of the input data
	double m_dMean;
	//@cmember Deviation of the input data
	double m_dDev;
};

#endif // !defined(AFX_OCStatistic_H__027FBE84_FC77_11D1_B2DB_006008AF1D5D__INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
