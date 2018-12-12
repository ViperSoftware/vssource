// OCFTChart.h: interface for the OCFTChart class.
//
//////////////////////////////////////////////////////////////////////
#ifdef _OBJCHART_UT_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OCUT_DATA
#endif

#if !defined(AFX_OCFTCHART_H_INCLUDED_)
#define AFX_OCFTCHART_H_INCLUDED_

/////////////////////////////
// AutoDuck tag block block for OCFTStructData 


//@doc OCFTStructData
//@mdata CString  | OCFTStructData | m_strAnnotation | The annotation text

//@doc OCFTStructData
//@mdata int  | OCFTStructData | m_nGroup | The grous number this structure is dealing with.

// adinsert AutoDuck insertion point for OCFTStructData 
//@doc OCFTStructData 
//@class Structure data class for Fourier Transformation. It allow user to 
// indicating the group number this structure will be added to, so by overriding
// the GetAnnotation function user can give the annotation to a dynamic graph on
// the fly.
class OCFTStructData : public SRGDoubleStructData  
{
public:
	OCFTStructData(int nGroup)
	{
		m_nGroup = nGroup;
	}
	virtual ~OCFTStructData(){};

	//@cmember Feed the annotation for the data with given index and group and 
	// the language code
	virtual CString& GetAnnotation(int code, int nIndex, int nGroup);

protected:
	OCFTStructData()
	{
		m_nGroup = -1;
	}
	//@cmember This function delegate the call to the other version of 
	// GetAnnotation function.
	virtual CString& GetAnnotation(int code);
	//@cmember Annotation string.
	CString m_strAnnotation;
	//@cmember The group number this structure is dealing with.
	int m_nGroup;
};

/////////////////////////////
// AutoDuck tag block block for OCFTChart 

//@doc OCFTChart
//@mdata int  | OCFTChart | m_nDataSize | Data sample size

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bShowReIn | Flag indicating whether displaying real part of input

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bShowImIn | Flag indicating whether displaying imaginary part of input
//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bShowReOut | Flag indicating whether displaying real part of output

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bShowImOut | Flag indicating whether displaying imaginary part of output

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bShowPS | Flag indicating whether displaying power spectrum of output

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bOwnReOut | Flagging whether the class own the memory of the real part of the output

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bOwnReIn | Flagging whether the class own the memory of the real part of the input

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bOwnImOut | Flagging whether the class own the memory of the imaginary part of the output

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bOwnImIn | Flagging whether the class own the memory of the imaginary part of the input

//@doc OCFTChart
//@mdata BOOL  | OCFTChart | m_bOwnPS | Flagging whether the class own the memory of the power spectrum data

//@doc OCFTChart
//@mdata double*  | OCFTChart | m_pPS | Pointer to the data buffer of power spectrum

//@doc OCFTChart
//@mdata double*  | OCFTChart | m_pImOut | Pointer to the data buffer of the imaginary part of output

//@doc OCFTChart
//@mdata double*  | OCFTChart | m_pReOut | Pointer to the data buffer of the real part of the output

//@doc OCFTChart
//@mdata double*  | OCFTChart | m_pImIn | Pointer to the data buffer of the imaginary part of the input

//@doc OCFTChart
//@mdata double*  | OCFTChart | m_pReIn | Pointer to the data buffer of the real part of the input

//@doc OCFTChart
//@mdata SRGraphDisplay*  | OCFTChart | m_pReInD | Pointer to the display for the real input data

//@doc OCFTChart
//@mdata SRGraphDisplay*  | OCFTChart | m_pImInD | Pointer to the display for the imaginary input data

//@doc OCFTChart
//@mdata SRGraphDisplay*  | OCFTChart | m_pReOutD | Pointer to the display for the real output data

//@doc OCFTChart
//@mdata SRGraphDisplay*  | OCFTChart | m_pImOutD | Pointer to the display for the imaginary output data

//@doc OCFTChart
//@mdata SRGraphDisplay*  | OCFTChart | m_pPSD | Pointer to the display for the power spectrum data

// adinsert AutoDuck insertion point for OCFTChart 
//@doc OCFTChart 
//@class This class encaptulate the Fourier Transformation and graphically represent 
// the result of the Fourier Transformation. 
class OCFTChart : public OCutItem  
{	
public:
	enum {RE_IN, IM_IN, RE_OUT, IM_OUT, POWER_SPECTRUM};
	enum Direction { FOREWARD = 1, BACKWARD = -1};

	//@cmember Clear all the memory used by the components
	virtual void ClearComponents();
	//@cmember Remove the given components from the component list of the graph. Memory is not freed.
	virtual void RemoveComponent(SRGraphComponent* pC);
	//@cmember Perform the fourier transformation on the given data
	virtual void DoFourierTransform(Direction nDir);
	//@cmember Create some default components for to the graph.
	virtual void SetupComponents();
	//@cmember Check if a given part is current shown.
	BOOL GetShowPart(int nWhichPart);
	//@cmember Dynamically hide and show a given part of the data
	void SetShowPart(int nWhichPart, BOOL bShow);
	//@cmember Get hold of the data buffer of the given part
	double* GetData(int nWhichPart);
	//@cmember Set the data buffer of the given part
	virtual void SetData(int nWhichPart, int nSize, double* pDataBuf = NULL);
	//@cmember Set the data buffers. 
	virtual void SetData(int nSize, double* pReIn, double* pImIn, double* pReOut = NULL, double* pImOut = NULL, double* pPowerSpectrum = NULL);
	//@cmember Get hold the display of the given part
	SRGraphDisplay* GetDisplay(int nWhichPart);

	//@cmember Add a display for the given part of the data
	virtual SRGraphDisplay* AddDisplay(int nWhichPart, SRGraphDisplay* pD = NULL);

	//@cmember Setup the dynamic data structure for the diffent part of the data. The data buffer is 
	// not set yet inside this function
	virtual void InitializeData();
	//@cmember Erase the components and the data
	virtual void Clear();
	//@cmember Erase all the data
	virtual void ClearData();
	//@cmember Set the data size
	void SetDataSize(int nSize){m_nDataSize=nSize;}
	//@cmember Get the data size
	int GetDataSize(){return m_nDataSize;}

	//@cmember Constructor
	OCFTChart();
	//@cmember Clear all the responsible memroy
	virtual ~OCFTChart();

protected:
	//@cmember Check the memory ownership of the data buffer of the given part
	BOOL GetOwnership(int nWhichPart);
	//@cmember Set the ownership of the data buffer of the given part
	void SetOwnership(int nWhichPart, BOOL bOwn);
	//@cmember Set up the dynamic data structure for the given group
	virtual void AddStructData(int nGroup);
	//@cmember Data size of input data.
	int m_nDataSize;

	//@cmember Flagging whether display the real part of the input
	BOOL m_bShowReIn;
	//@cmember Flagging whether displaying the imaginary part of the input
	BOOL m_bShowImIn;
	//@cmember Flagging whether displaying the real part of the output data
	BOOL m_bShowReOut;
	//@cmember Flagging whether displaying the imaginary part of the output data
	BOOL m_bShowImOut;
	//@cmember Flagging whether displaying the power spectrum data
	BOOL m_bShowPS;

	//@cmember Flagging whether this class own the memory of the real part of the output
	BOOL m_bOwnReOut;
	//@cmember Flagging whether this class own the memory of the real part of the input
	BOOL m_bOwnReIn;
	//@cmember Flagging whether this class own the memory of the imaginary part of the output
	BOOL m_bOwnImOut;
	//@cmember Flagging whether this class own the memory of the imaginary part of the input
	BOOL m_bOwnImIn;
	//@cmember Flagging whether this class own the memory of the power spectrum data
	BOOL m_bOwnPS;


	//@cmember Pointer to the data buffer of the power spectrum
	double* m_pPS;
	//@cmember Pointer to the data buffer of the imginary part of output
	double* m_pImOut;
	//@cmember Pointer to the data buffer of the real part of the output
	double* m_pReOut;
	//@cmember Pointer to the data buffer of the imaginary part of the input
	double* m_pImIn;
	//@cmember Pointer to the data buffer of the real part of the input
	double* m_pReIn;

	//@cmember Pointer to the display for the real part of input
	SRGraphDisplay* m_pReInD;
	//@cmember Pointer to the display for the imaginary part of the input
	SRGraphDisplay* m_pImInD;
	//@cmember Pointer to the display for the real part of the output
	SRGraphDisplay* m_pReOutD;
	//@cmember Pointer to the display for the imaginary part of the output
	SRGraphDisplay* m_pImOutD;
	//@cmember Pointer to the display for the power spectrum
	SRGraphDisplay* m_pPSD;
};

#endif // !defined(AFX_OCFTCHART_H_INCLUDED_)

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR
