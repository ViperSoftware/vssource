// 
// Stingray Software Extension Classes
// Copyright (C) 1998 Stingray Software Inc.
// All Rights Reserved
// 
// This source code is only intended as a supplement to the
// Stingray Extension Class product.
// See the SEC help files for detailed information
// regarding using SEC classes.
// 
//  Author:			Mark Isham
//  Description:	Build Wizard configuration template
//  Created:		Jan 1998
//
//

// Default.h : Generated Configuration Info for 
//                    configuration "Default"
//

// To automatically link your application with this configuration:
//
// Add 
// #include "config/Default.h" 
// before 
// #include "cmnall.h" 
// in your application's stdafx.h file.

#ifndef _CMNBWCONFIG_H_
#define _CMNBWCONFIG_H_

/////////////////////////////////////////////////////////////////////////////
// Win32 libraries

//
// Automatic library inclusion macros that use the #pragma/lib feature
//
// Define _CMNNOAUTOLIB when compiling SEC so that it does
// not try and link to itself. -chicken and egg.
//
#ifndef _CMNNOAUTOLIB

#if _MFC_VER > 0x0200		// 32 bit only!

	// This file is used to autolink a custom build configuration. Do not 
	// include more than 1 custom autolink.
	#ifdef CMN_CUSTOM_AUTOLINK
	#pragma message("Error, including more than 1 autolink header.")
	#endif

	// Define this preprocessor such that cmnver.h knows not to use the
	// default autolink information
	#define CMN_CUSTOM_AUTOLINK

	#ifndef _UNICODE
		#if !defined(_CMNDLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60d.lib"
		#elif !defined(_CMNDLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60.lib"
		#elif !defined(_CMNDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60ad.lib"
		#elif !defined(_CMNDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60a.lib"
		#elif defined(_CMNDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60asd.lib"
		#elif defined(_CMNDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60as.lib"
		#elif defined(_CMNDLL) && !defined(_AFXDLL)
			#error _CMNDLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#else
		#if !defined(_CMNDLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60ud.lib"
		#elif !defined(_CMNDLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60u.lib"
		#elif !defined(_CMNDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60aud.lib"
		#elif !defined(_CMNDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60au.lib"
		#elif defined(_CMNDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60asud.lib"
		#elif defined(_CMNDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _CMNAUTOLIBNAME "OSC60asu.lib"
		#elif defined(_CMNDLL) && !defined(_AFXDLL)
			#error _CMNDLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#endif
#endif // 32-bit only

#endif // _CMNNOAUTOLIB

// If using the autolink, also add any preprocessor defines that are unique
// to this configuration
#ifdef CMN_CUSTOM_AUTOLINK



#pragma message("Objective Studio autolink configuration: Default")

#endif

#endif // _CMNBWCONFIG_H_

