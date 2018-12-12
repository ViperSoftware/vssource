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
// #include "secall.h" 
// in your application's stdafx.h file.

#ifndef _SECBWCONFIG_H_
#define _SECBWCONFIG_H_

/////////////////////////////////////////////////////////////////////////////
// Win32 libraries

//
// Automatic library inclusion macros that use the #pragma/lib feature
//
// Define _SECNOAUTOLIB when compiling SEC so that it does
// not try and link to itself. -chicken and egg.
//
#ifndef _SECNOAUTOLIB

#if _MFC_VER > 0x0200		// 32 bit only!

	// This file is used to autolink a custom build configuration. Do not 
	// include more than 1 custom autolink.
	#ifdef SEC_CUSTOM_AUTOLINK
	#pragma message("Error, including more than 1 autolink header.")
	#endif

	// Define this preprocessor such that secver.h knows not to use the
	// default autolink information
	#define SEC_CUSTOM_AUTOLINK

	#ifndef _UNICODE
		#if !defined(_SECDLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60d.lib"
		#elif !defined(_SECDLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60.lib"
		#elif !defined(_SECDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60ad.lib"
		#elif !defined(_SECDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60a.lib"
		#elif defined(_SECDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60asd.lib"
		#elif defined(_SECDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60as.lib"
		#elif defined(_SECDLL) && !defined(_AFXDLL)
			#error _SECDLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#else
		#if !defined(_SECDLL) && !defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60ud.lib"
		#elif !defined(_SECDLL) && !defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60u.lib"
		#elif !defined(_SECDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60aud.lib"
		#elif !defined(_SECDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60au.lib"
		#elif defined(_SECDLL) && defined(_AFXDLL) && defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60asud.lib"
		#elif defined(_SECDLL) && defined(_AFXDLL) && !defined(_DEBUG)
			#define _SECAUTOLIBNAME "OT60asu.lib"
		#elif defined(_SECDLL) && !defined(_AFXDLL)
			#error _SECDLL is defined but _AFXDLL is not. You must defined both.
		#endif
	#endif
#endif // 32-bit only

#endif // _SECNOAUTOLIB

// If using the autolink, also add any preprocessor defines that are unique
// to this configuration
#ifdef SEC_CUSTOM_AUTOLINK

#ifndef SEC_NO_TMPL_EXPLICIT_INST
#define SEC_NO_TMPL_EXPLICIT_INST
#endif

#ifndef OT_BLD_BROWEDIT
#define OT_BLD_BROWEDIT
#endif

#ifndef OT_BLD_COMMON
#define OT_BLD_COMMON
#endif

#ifndef OT_BLD_FILESYS
#define OT_BLD_FILESYS
#endif

#ifndef CMN_BLD_BUTTON_CTRL
#define CMN_BLD_BUTTON_CTRL
#endif

#ifndef CMN_BLD_COLORWELL
#define CMN_BLD_COLORWELL
#endif

#ifndef OT_BLD_CALCEDIT
#define OT_BLD_CALCEDIT
#endif

#ifndef OT_BLD_CALENDAR
#define OT_BLD_CALENDAR
#endif

#ifndef OT_BLD_CLRLSTBOX
#define OT_BLD_CLRLSTBOX
#endif

#ifndef OT_BLD_CURREDIT
#define OT_BLD_CURREDIT
#endif

#ifndef OT_BLD_DROPEDIT
#define OT_BLD_DROPEDIT
#endif

#ifndef OT_BLD_DATETIME
#define OT_BLD_DATETIME
#endif

#ifndef OT_BLD_LBEDIT
#define OT_BLD_LBEDIT
#endif

#ifndef OT_BLD_PROGRESS
#define OT_BLD_PROGRESS
#endif

#ifndef OT_BLD_MASKEDIT
#define OT_BLD_MASKEDIT
#endif

#ifndef OT_BLD_MARQUEE
#define OT_BLD_MARQUEE
#endif

#ifndef CMN_BLD_SECDIB
#define CMN_BLD_SECDIB
#endif

#ifndef OT_BLD_SECGIF
#define OT_BLD_SECGIF
#endif

#ifndef CMN_BLD_SECJPEG
#define CMN_BLD_SECJPEG
#endif

#ifndef OT_BLD_SECPCX
#define OT_BLD_SECPCX
#endif

#ifndef OT_BLD_SECTARGA
#define OT_BLD_SECTARGA
#endif

#ifndef OT_BLD_SECTIFF
#define OT_BLD_SECTIFF
#endif

#ifndef OT_BLD_MTI
#define OT_BLD_MTI
#endif

#ifndef OT_BLD_GRADIENT
#define OT_BLD_GRADIENT
#endif

#ifndef OT_BLD_DOCKWIN
#define OT_BLD_DOCKWIN
#endif

#ifndef OT_BLD_WDI
#define OT_BLD_WDI
#endif

#ifndef OT_BLD_CUSTTBAR
#define OT_BLD_CUSTTBAR
#endif

#ifndef OT_BLD_WSMGR
#define OT_BLD_WSMGR
#endif

#ifndef OT_BLD_FDI
#define OT_BLD_FDI
#endif

#ifndef OT_BLD_REGISTRY
#define OT_BLD_REGISTRY
#endif

#ifndef OT_BLD_TABCTRL
#define OT_BLD_TABCTRL
#endif

#ifndef OT_BLD_SCUTBAR
#define OT_BLD_SCUTBAR
#endif

#ifndef OT_BLD_BMPDLG
#define OT_BLD_BMPDLG
#endif

#ifndef OT_BLD_STATUS
#define OT_BLD_STATUS
#endif

#ifndef OT_BLD_KBSCUT
#define OT_BLD_KBSCUT
#endif

#ifndef OT_BLD_TOD
#define OT_BLD_TOD
#endif

#ifndef OT_BLD_TOOLSMENU
#define OT_BLD_TOOLSMENU
#endif

#ifndef OT_BLD_THUMBNAIL
#define OT_BLD_THUMBNAIL
#endif

#ifndef OT_BLD_SPLASH
#define OT_BLD_SPLASH
#endif

#ifndef OT_BLD_TRAYICON
#define OT_BLD_TRAYICON
#endif

#ifndef OT_BLD_ENCRYPT
#define OT_BLD_ENCRYPT
#endif

#ifndef OT_BLD_COMPRESSFILE
#define OT_BLD_COMPRESSFILE
#endif

#ifndef OT_BLD_RANDOM
#define OT_BLD_RANDOM
#endif

#ifndef CMN_BLD_PATTERNS
#define CMN_BLD_PATTERNS
#endif

#ifndef OT_BLD_TREECTRL
#define OT_BLD_TREECTRL
#endif

#ifndef OT_BLD_PANZOOM
#define OT_BLD_PANZOOM
#endif



#pragma message("Objective Toolkit autolink configuration: Default")

#endif

#endif // _SECBWCONFIG_H_

