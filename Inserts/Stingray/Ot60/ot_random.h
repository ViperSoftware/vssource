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
//  Description:	ot_random.h - Random number generator component header
//  Created:		Tue Aug 27 14:08:25 1998
//
//

#ifndef __OTM_RANDOM_H__
#define  __OTM_RANDOM_H__

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
// *  Random Number Generator Class
// *
// ***********************************************************

#ifdef OT_BLD_RANDOM

	// SECRandom
	#ifndef __SECRAND_H__
	#include "secrand.h"
	#endif //__SECRAND_H__

#else
	#pragma message("Warning:  The random number generator component was not included in the Objective Toolkit library") 
	#pragma message("          Add this component to the library using the BuildWizard and rebuild Objective Toolkit.")
#endif // OT_BLD_RANDOM

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

#endif // __OTM_RANDOM_H__