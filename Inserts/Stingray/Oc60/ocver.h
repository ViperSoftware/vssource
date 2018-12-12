// 
// Stingray Software Extension Classes
// Copyright (C) 1997 Stingray Software Inc.
// All Rights Reserved
// 
// This source code is only intended as a supplement to the
// Stingray Extension Class product.
// See the SEC help files for detailed information
// regarding using SEC classes.
// 
//
//  Author:	      Steve Danielson
//                Chuanzhong Zhu: Modified for Objective chart
//  Description:  Version information for Comon libraries
//  Created:      06/24/98/

#ifndef __OCVER_H__
#define __OCVER_H__

/////////////////////////////////////////////////////////////////////////////
// Master version number
/////////////////////////////////////////////////////////////////////////////

#define _OC_VER 0x0600 // Objective Chart 6.0 

// Changes have been made to serialization since version 0 (beta)
#define _OCHART_FILE_VERSION 1

/////////////////////////////////////////////
// Extension DLL link management

#ifdef _OBJCHART_DLL

	#ifdef _OCNOAUTOLIB
		#define OC_DATA _declspec(dllexport)
	#else
		#define OC_DATA _declspec(dllimport)
	#endif

#endif

//
// Automatic library inclusion macros that use the #pragma/lib feature
//
// Define _OCNOAUTOLIB when compiling OC so that it does
// not try and link to itself.
//
#ifndef _OCNOAUTOLIB

	#ifndef _UNICODE
		#if !defined(_OBJCHART_DLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60d.lib"
		#elif !defined(_OBJCHART_DLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60.lib"
		#elif !defined(_OBJCHART_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60ad.lib"
		#elif !defined(_OBJCHART_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60a.lib"
		#elif defined(_OBJCHART_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60asd.lib"
		#elif defined(_OBJCHART_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60as.lib"
		#elif defined(_OBJCHART_DLL) && !defined(_AFXDLL)
			#error _OBJCHART_DLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#else
		#if !defined(_OBJCHART_DLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60ud.lib"
		#elif !defined(_OBJCHART_DLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60u.lib"
		#elif !defined(_OBJCHART_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60aud.lib"
		#elif !defined(_OBJCHART_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60au.lib"
		#elif defined(_OBJCHART_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60asud.lib"
		#elif defined(_OBJCHART_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCAUTOLIBNAME "OC60asu.lib"
		#elif defined(_OBJCHART_DLL) && !defined(_AFXDLL)
			#error _OBJCHART_DLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#endif


#pragma message("")
#pragma message("**********Objective Chart Message**********")
#pragma message("")

#if _MFC_VER >= 0x0410
  #pragma comment(lib, _OCAUTOLIBNAME)
  #pragma message("  Your application will automatically link with-> " _OCAUTOLIBNAME)
#else
  #pragma message("  You should link your application with-> " _OCAUTOLIBNAME)
#endif

#pragma message("")
#pragma message("**********Objective Chart Message**********")
#pragma message("")

#endif //_OCNOAUTOLIB
/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined

// Common Library includes
// If OC is a DLL, then CMN must be a DLL
#ifdef _OBJCHART_DLL
	#ifndef _CMNDLL
		#define _CMNDLL
	#endif
#endif // _OBJCHART_DLL

//************************************
// Include CMN
//************************************
#ifndef CMN_BLD_SECDIB
	#define CMN_BLD_SECDIB
#endif

#ifndef CMN_BLD_BUTTON_CTRL
	#define CMN_BLD_BUTTON_CTRL
#endif

#ifndef CMN_BLD_PATTERNS
	#define CMN_BLD_PATTERNS
#endif

#ifndef CMN_BLD_COLORWELL_CTRL
	#define CMN_BLD_COLORWELL_CTRL
#endif

#include /* */ "../osc/CmnAll.h"
#include /* */ "../osc/cmn_cnt.h"
 
#endif // __OCVER_H__
