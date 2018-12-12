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
//  Description:	ot_toolbar.h - Customizable toolbar/menubar component header
//  Created:		Tue Aug 27 14:08:25 1998
//
//

#ifndef __OTM_TOOLBAR_H__
#define  __OTM_TOOLBAR_H__

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
// *  Customizable Toolbar/Menubar
// *
// ***********************************************************

#ifdef OT_BLD_CUSTTBAR

	// SECCustomToolBar
	#ifndef __TBARCUST_H__
	#include "tbarcust.h"
	#endif // __TBARCUST_H__

	// SECToolBarManager
	#ifndef __TBARMGR_H__
	#include "tbarmgr.h"
	#endif // __TBARMGR_H__

	// SECToolBarCmdPage
	#ifndef __TBARPAGE_H__
	#include "tbarpage.h"
	#endif // __TBARPAGE_H__

	// SECToolBarsDlg
	#ifndef __TBARSDLG_H__
	#include "tbarsdlg.h"
	#endif // __TBARSDLG_H__

	// SECToolBarRectTracker
	#ifndef __TBARTRCK_H__
	#include "tbartrck.h"
	#endif // __TBARTRCK_H__

	// SECTwoPartBtn
	#ifndef __TBTN2PRT_H__
	#include "tbtn2prt.h"
	#endif // __TBTN2PRT_H__

	// SECComboBtn
	#ifndef __TBTNCMBO_H__
	#include "tbtncmbo.h"
	#endif // __TBTNCMBO_H__

	// SECStdBtn
	#ifndef __TBTNSTD_H__
	#include "tbtnstd.h"
	#endif // __TBTNSTD_H__

	// SECWndBtn
	#ifndef __TBTNWND_H__
	#include "tbtnwnd.h"
	#endif // __TBTNWND_H__

	// SECTBTextButton
	#ifndef __SECTEXTWBDBUTTON_H__
	#include "tbtntxt.h"
	#endif // __SECTEXTWBDBUTTON_H__

	// SECMenuBarBtnInfo
	#ifndef __TMENUFRM_H__
	#include "TMenuFrm.h"
	#endif // __TMENUFRM_H__

	// SECTBMenuBtn
	#ifndef __TBTNMENU_H__
	#include "TBtnMenu.h"
	#endif // __TBTNMENU_H__

	// Bitmap menu support
	#ifndef __TBMPMENU_H__
	#include "TBmpMenu.h"
	#endif // __TBMPMENU_H__

	// SECBmpMgr
	#ifndef __TBMPMGR_H__
	#include "TBmpMgr.h"
	#endif // __TBMPMGR_H__

#else
	#pragma message("Warning:  The customizable toolbar/menubar component was not included in the Objective Toolkit library.")
	#pragma message("          Add this component to the library using the BuildWizard and rebuild Objective Toolkit.")
#endif // OT_BLD_CUSTTBAR

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

#endif // __OTM_TOOLBAR_H__