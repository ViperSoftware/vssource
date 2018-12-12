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
//@doc SRGraphException
//@module SRGExc.h | SRGraphException header file<nl>
//Copyright <cp>Stingray Software 1996<nl>
//Written by Bob Powell (www.stingray.com)

////////////////////////////////////////////////////////////////
//
// SRGExc.h: Declaration of the SRGraphException class
//
////////////////////////////////////////////////////////////////

#ifdef _OBJCHART_DLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXAPI_DATA
	#undef AFX_DATA
	#define AFX_DATA OC_DATA
#endif


#ifndef __SRGRAPHEXCEPTION__
#define __SRGRAPHEXCEPTION__

//@doc SRGraphException

//@mdata int | SRGraphException | m_nCause | Holds the cause of the current exception<nl>
//May be one of...<nl>
//none				No cause was given<nl>
//generic			An undefined error occurred.<nl>
//group				An attempt was made to access a non-existent group.<nl>
//index				An attempt was made to access a non-existent index.<nl>
//null				A required data item was marked as null data.<nl>
//dynamic			A dynamic data error occurred.<nl>
//dynamicType		An attempt to use a data type not consistent with other dynamic data was attempted.<nl>
//dynamicNotready	An attempt was made to send data to an un-initialized dynamic data store.<nl>
//component			A component error occurred.<nl>
//fillstyle			An error occurred while reading a fill style from a template.<nl>
//font				An error occurred while reading a font descriptor from a template.<nl>
//legend			An error occurred while reading a legend descriptor from a template<nl>
//data				An error occurred while reading a data descriptor from a template.<nl>
//command			A template command was not recognized.<nl>
//border			An error occurred while reading a border descriptor from a template.<nl>
//type				An unknown type has been found in a component.<nl>
//syntax			A syntax error occurred while reading a template.<nl>
//label				The placement of a label has reduced the drawing surface to zero.<nl>
//drawing			A function requiring a valid m-pCWnd or m_pDC was called while the graph was not drawing.<nl>
//polygon			An error occurred while loading a polygon resource.<nl>
//wiget				An error occurred while loading a wiget resource.<nl>
//graphtype			A graph type was used that is not suitable for the type or range of data.<nl>
//logscale			The data in the graph were not suitable for use on a logarithmic scale.<nl>
//odd				An odd number of data items exists, but an even number is required.<nl>

void SRThrowGraphException(int cause);

//$head The chart exeption class
//$level 1

//@class Exception class for SRGraph
//@base public | CException
class SRGraphException : public CException
{
public:
	
	//@cmember
	/* Called to allow user exception handling*/
	virtual UINT UserExceptionID();

	//@cmember
	/* Construction*/
	SRGraphException(int cause=0);

	DECLARE_DYNCREATE(SRGraphException);

	//@cmember
	/* Displays the message associated with the current exception code*/
	void ShowErrorMessage();
	
	//@cmember
	/* Override of the CException::GetErrorMessage function -- uses strings defined in the SRGraphResource (SRGRES.RC) file*/
	virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, PUINT pnHelpContext=NULL);

	enum {
		none=0,
		generic,
		// data access exceptions
		group,
		index,
		dynamic,
		dynamicType,
		dynamicNotready,
		null,
		// template exceptions
		component,
		fillstyle,
		font,
		legend,
		data,
		command,
		border,
		type,
		syntax,
		//drawing eceptions
		label,
		drawing,
		//resource exceptions
		polygon,
		wiget,
		//configuration exceptions
		graphtype,
		//range exceptions
		logscale,
		odd
	}  ;

	//@cmember
	/* Cause of the exception*/
	int m_nCause;



//@access protected member functions
protected:
	//@cmember
	/* Fetches the correct resource ID for the error*/
	virtual UINT GetErrorID();
};

#endif //__SRGRAPHEXCEPTION__

// Reset DLL declaration context

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

