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
//  Author:			Rob Oliver
//  Description:	ot_colorwell.h - Colorwell control component header
//  Created:		Tue Aug 27 14:08:25 1998
//
//

#ifndef __OTM_CONTROLWELL_H__
#define  __OTM_CONTROLWELL_H__

// ***********************************************************
// *
// *  OT needs 8 byte packing for structures
// *
// ***********************************************************

#if (_MFC_VER >= 0x0300)
// pshpack8.h saves the current #pragma pack value
#include "pshpack8.h"
#else
#pragma pack(8)
#endif

// ***********************************************************
// *
// *  OT optimized include file
// *
// ***********************************************************

#ifndef __SECOPT_H__
    #include "secopt.h"
#endif

// ***********************************************************
// *
// *  Color Well
// *
// ***********************************************************

#ifdef CMN_BLD_COLORWELL
	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  CMN_BLD_COLORWELL" )
	#endif
	// SECColorWell
	#ifndef __SECWELL_H__
	#include /* */ "secwell.h"
	#endif // __SECWELL_H__

#else
	#pragma message("Warning:  The colorwell control was not included in the Objective Studio Common library.")
	#pragma message("          Add this component to the library using the BuildWizard and rebuild Objective Studio Common library.")
#endif // CMN_BLD_COLORWELL

// ***********************************************************
// *
// *  Restore default byte packing
// *
// ***********************************************************

#if (_MFC_VER >= 0x0300)
// poppack.h restores the original #pragma pack value
#include /* */ "poppack.h"
#else
// restore default packing value
#pragma pack()
#endif

#endif // __OTM_COLORWELL_H__