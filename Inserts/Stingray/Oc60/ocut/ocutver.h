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

#ifndef __OCUTVER_H__
#define __OCUTVER_H__

/////////////////////////////////////////////////////////////////////////////
// Master version number
/////////////////////////////////////////////////////////////////////////////

#define _OCUT_VER 0x0600 // Objective Chart 6.0 

// Changes have been made to serialization since version 0 (beta)
#define _OCUTHART_FILE_VERSION 1

#ifdef _OBJCHART_UT_DLL

	#ifdef _OCUT_NO_AUTOLIB
		#define OCUT_DATA _declspec(dllexport)
	#else
		#define OCUT_DATA _declspec(dllimport)
	#endif

#endif


//
// Automatic library inclusion macros that use the #pragma/lib feature
//
// Define __OCUT_NO_AUTOLIB when compiling OC so that it does
// not try and link to itself.
//
#ifndef _OCUT_NO_AUTOLIB

	#ifndef _UNICODE
		#if !defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60d.lib"
		#elif !defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60.lib"
		#elif !defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60ad.lib"
		#elif !defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60a.lib"
		#elif defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60asd.lib"
		#elif defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60as.lib"
		#elif defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL)
			#error _OBJCHART_UT_DLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#else
		#if !defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60ud.lib"
		#elif !defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60u.lib"
		#elif !defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60aud.lib"
		#elif !defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60au.lib"
		#elif defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60asud.lib"
		#elif defined(_OBJCHART_UT_DLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _OCUTAUTOLIBNAME "OCUT60asu.lib"
		#elif defined(_OBJCHART_UT_DLL) && !defined(_AFXDLL)
			#error _OBJCHART_UT_DLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#endif


#pragma message("")
#pragma message("**********Objective Chart Message**********")
#pragma message("")

#if _MFC_VER >= 0x0410
  #pragma comment(lib, _OCUTAUTOLIBNAME)
  #pragma message("  Your application will automatically link with-> " _OCUTAUTOLIBNAME)
#else
  #pragma message("  You should link your application with-> " _OCUTAUTOLIBNAME)
#endif

#pragma message("")
#pragma message("**********Objective Chart Message**********")
#pragma message("")

#endif //_OCUT_NO_AUTOLIB
/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined
#ifdef _OBJCHART_UT_DLL
	#ifndef _OBJCHART_DLL
		#define _OBJCHART_DLL
	#endif
#endif // _OBJCHART_UT_DLL

 
#endif // __OCUTVER_H__
