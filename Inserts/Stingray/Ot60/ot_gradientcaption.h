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
//  Description:	ot_gradientcaption.h - Gradient caption component header
//  Created:		Tue Aug 27 14:08:25 1998
//
//

#ifndef __OTM_GRADIENTCAPTION_H__
#define  __OTM_GRADIENTCAPTION_H__

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
// *  Gradient Caption Classes
// *
// ***********************************************************

#ifdef OT_BLD_GRADIENT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_GRADIENT" )
	#endif

	// SECFrameWnd
	#ifndef __SWINMDI_H__
	#include "swinmdi.h"
	#endif //__SWINMDI_H__

	// SECMDIFrameWnd
	#ifndef __SWINFRM_H__
	#include "swinfrm.h"
	#endif //__SWINFRM_H__

#else
	#pragma message("Warning:  The gradient caption component was not included in the Objective Toolkit library.")
	#pragma message("          Add this component to the library using the BuildWizard and rebuild Objective Toolkit.")
#endif //  OT_BLD_GRADIENT

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

#endif // __OTM_GRADIENTCAPTION_H__