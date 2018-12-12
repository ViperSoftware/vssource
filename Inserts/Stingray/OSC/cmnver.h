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
//  Description:  Version information for Comon libraries
//  Created:      06/24/98/

#ifndef __CMNVER_H__
#define __CMNVER_H__

/////////////////////////////////////////////////////////////////////////////
// Master version numbers
/////////////////////////////////////////////////////////////////////////////

#define _CMN_VER 0x0600

//
// Automatic library inclusion macros that use the #pragma/lib feature
//
// Define _CMNNOAUTOLIB when compiling CMN so that it does
// not try and link to itself.
//
#ifndef _CMNNOAUTOLIB

// If a custom autolink was used, do not bother with the defaults
#ifndef CMN_CUSTOM_AUTOLINK

// Ok, no custom autolink was used, use the default (i.e. if you only 
// included "cmnall.h". The default is the configuration last set by the
// build wizard
// 32 bit
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

#endif	// CMN_CUSTOM_AUTOLINK

#if _MFC_VER >= 0x0300

// You may turn off SEC++ specific compilation message
// by adding _SECNOMSG to your C/C++ settings.
#ifndef _SECNOMSG
#pragma message( "Objective Studio will automatically link with " _CMNAUTOLIBNAME )
#endif //_SECNOMSG

// Perform autolink here:
#pragma comment(lib, _CMNAUTOLIBNAME)

#endif //end of 32-bit message

#endif //_CMNNOAUTOLIB
/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined

#define CMN_DATA

#endif // __CMNVER_H__
