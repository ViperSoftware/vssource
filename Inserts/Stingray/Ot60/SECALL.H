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
//  Author:			Scot Wingo
//  Description:	secall.h - Mega header file.
//  Created:		Tue Aug 29 14:08:25 1995
//
//

#ifndef __SECALL_H__
#define __SECALL_H__

//
// Header include diagnostics
//
#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
	#pragma message ( __TIME__ ":  include " __FILE__ )
#endif

// ***********************************************************
// *
// *  BuildWizard preliminary includes
// *
// ***********************************************************

#if defined(WIN32) && !defined(__SEC_BWDEFINES_H)
#include "BWDef.h"
#endif

// ***********************************************************
// *
// *  OT needs 8 byte packing for structures
// *
// ***********************************************************

#if defined(WIN32) && (_MFC_VER >= 0x0300)
// pshpack8.h saves the current #pragma pack value
#include "pshpack8.h"
#else
#pragma pack(8)
#endif

// CImageList, etc.
#if defined(WIN32) && !defined(__AFXCMN_H__)
#include <afxcmn.h>
#endif

// Common Library includes
// If OT is a DLL, then CMN must be a DLL
#ifdef _SECDLL
	#ifndef _CMNDLL
		#define _CMNDLL
	#endif
#endif // _SECDLL
#include /* */ "CmnAll.h"               // OT Common Components
#include /* */ "cmn_cnt.h"				// OT Common Components

// ***********************************************************
// *
// *  Version info
// *
// ***********************************************************

#ifndef __SECVER_H__
#include "secver.h"
#endif

// ***********************************************************
// *
// *  Objective Toolkit Resources
// *
// ***********************************************************

#include "secres.h"

// ***********************************************************
// *
// *  Objective Toolkit PRO Resources
// *
// ***********************************************************

#if defined(WIN32) && defined(OTPRO)
#include "secres_pro.h"
#endif

// ***********************************************************
// *
// *  Common Classes
// *
// ***********************************************************
#ifdef OT_BLD_COMMON

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_COMMON" )
	#endif

	#ifndef __SECAUX_H__
	#include "secaux.h"
	#endif // __SECAUX_H__

	// dll support
	#ifndef __SECDLL_H__
	#include "secdll.h"
	#endif // __SECDLL_H_

#endif // OT_BLD_COMMON

// ***********************************************************
// *
// *  Objective Toolkit Preliminary Includes
// *
// ***********************************************************

#if defined(WIN32) && defined(OTPRO)

	// In general, add Pro includes to ProAll.h (see below).
	#ifndef __PROPRE_H_
	#include "ProPre.h"
	#endif

#endif 

// ***********************************************************
// *
// *  Internationalization
// *
// ***********************************************************

#ifdef OT_BLD_SLOCALE

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_SLOCALE" )
	#endif

	// SECLocale
	#ifndef __SLOCALE_H__
	#include "slocale.h"
	#endif // __SLOCALE_H__

#endif // OT_BLD_SLOCALE

// ***********************************************************
// *
// *  Browse Edit Control
// *
// ***********************************************************

#ifdef OT_BLD_BROWEDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_BROWEDIT" )
	#endif

	#ifndef  __BROWEDIT_H__
	#include  "browedit.h"
	#endif // __BROWEDIT_H__

#endif // OT_BLD_BROWEDIT

// ***********************************************************
// *
// *  Calculator
// *
// ***********************************************************

#ifdef OT_BLD_CALCEDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_CALCEDIT" )
	#endif

	#ifndef __CALCBTN_H__
	#include "calcbtn.h"
	#endif // __CALCBTN_H__

	#ifndef __SECCALC_H__
	#include "seccalc.h"
	#endif // __SECCALC_H__

#endif // OT_BLD_CALCEDIT

// ***********************************************************
// *
// *  Calendar
// *
// ***********************************************************

#ifdef OT_BLD_CALENDAR

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_CALENDAR" )
	#endif

	#ifndef __SEC_CALENDAR_H__
	#include "calendar.h"
	#endif //__SEC_CALENDAR_H__

#endif // OT_BLD_CALENDAR

// ***********************************************************
// *
// *  Color Listbox
// *
// ***********************************************************

#ifdef OT_BLD_CLRLSTBOX

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_CLRLSTBOX" )
	#endif

	#ifndef __LSTBXCLR_H__
	#include "lstbxclr.h"
	#endif // __LSTBXCLR_H__

#endif // OT_BLD_CLRLSTBOX

// ***********************************************************
// *
// *  Currency Edit
// *
// ***********************************************************

#ifdef OT_BLD_CURREDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_CURREDIT" )
	#endif

	#ifndef __CURREDIT_H__
	#include "curredit.h"
	#endif

#endif

// ***********************************************************
// *
// *  DateTime Controls
// *
// ***********************************************************

#if defined(OT_BLD_DATETIME) && defined(WIN32)

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_DATETIME" )
	#endif

	#ifndef __DTCTRL_H__
	#include "dtctrl.h"
	#endif // __DTCTRL_H__

	#ifndef __DTGADGET_H__
	#include "dtgadget.h"
	#endif // __DTGADGET_H__

#endif // OT_BLD_DATETIME

// ***********************************************************
// *
// *  DropEdit Controls
// *
// ***********************************************************

#ifdef OT_BLD_DROPEDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_DROPEDIT" )
	#endif

	#ifndef __DROPEDIT_H__
	#include "dropedit.h"
	#endif // __DROPEDIT_H__

#endif // OT_BLD_DROPEDIT

// ***********************************************************
// *
// *  Editable Listbox
// *
// ***********************************************************

#ifdef OT_BLD_LBEDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_LBEDIT" )
	#endif

	#ifndef __LSTBXEDT_H__
	#include "lstbxedt.h"
	#endif // __LSTBXEDT_H__

#endif // OT_BLD_LBEDIT

// ***********************************************************
// *
// *  Progress Control
// *
// ***********************************************************

#ifdef OT_BLD_PROGRESS

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_PROGRESS" )
	#endif

	#ifndef __SECPROGRESSCTRL_H__
	#include "progress.h"
	#endif // __SECPROGRESSCTRL_H__

#endif

// ***********************************************************
// *
// *  Masked Edit Control
// *
// ***********************************************************

#ifdef OT_BLD_MASKEDIT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_MASKEDIT" )
	#endif

	#ifndef __SECMASKEDIT_H__
	#include "secmedit.h"
	#endif //__SECMASKEDIT_H__

#endif // OT_BLD_MASKEDIT

// ***********************************************************
// *
// *  Marquee Control
// *
// ***********************************************************

#ifdef OT_BLD_MARQUEE

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_MARQUEE" )
	#endif

	#ifndef __SECMARQUEE_H
	#include "marquee.h"
	#endif

#endif // OT_BLD_MARQUEE


// ***********************************************************
// *
// *  Image Classes
// *
// ***********************************************************

// ***********************************************************
// *
// *  SECGIF (requires the GIF/TIFF unlock pack)
// *
// ***********************************************************

#ifdef OT_BLD_SECGIF

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_GIF" )
	#endif

	#ifndef _SECGIF_H_
	#include "secgif.h"
	#endif //__SECGIF_H__

#endif // OT_BLD_GIF

// ***********************************************************
// *
// *  SECPcx
// *
// ***********************************************************

#ifdef OT_BLD_SECPCX

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_PCX" )
	#endif

	#ifndef __SECPCX_H__
	#include "secpcx.h"
	#endif //__SECPCX_H__

#endif // OT_BLD_PCX

// ***********************************************************
// *
// *  SECTga
// *
// ***********************************************************

#ifdef OT_BLD_SECTARGA

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TARGA" )
	#endif

	#ifndef __SECTARGA_H__
	#include "sectarga.h"
	#endif //__SECTARGA_H__

#endif // OT_BLD_TARGA

// ***********************************************************
// *
// *  SECTiff
// *
// ***********************************************************

#ifdef OT_BLD_SECTIFF

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TIFF" )
	#endif

	#ifndef WIN32
	#pragma warning(disable : 4103)
	#endif // WIN32

	#ifndef __SECTIFF_H__
	#include /* */ "sectiff.h"
	#endif //__SECTIFF_H__

	#ifndef WIN32
	#pragma warning(default : 4103)
	#endif // WIN32

#endif // OT_BLD_TIFF

// ***********************************************************
// *
// *  MDI Alternatives
// *
// ***********************************************************

// ***********************************************************
// *
// *  Multiple Top Level Interface
// *
// ***********************************************************

#ifdef OT_BLD_MTI

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_MTI" )
	#endif

	#ifndef __SECTLF_H__
	#include "sectlf.h"
	#endif //__SECTLF_H__

#endif // OT_BLD_MTI

// ***********************************************************
// *
// *  Floating Document Interface
// *
// ***********************************************************

#ifdef OT_BLD_FDI

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_FDI" )
	#endif

	#ifndef __FDIMAIN_H__
	#include "fdimain.h"
	#endif //__FDIMAIN_H__

	#ifndef __FDICHILD_H__
	#include "fdichild.h"
	#endif //__FDICHILD_H__

#endif // OT_BLD_FDI

// ***********************************************************
// *
// *  Workbook Document Interface
// *
// ***********************************************************

#ifdef OT_BLD_WDI

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_WDI" )
	#endif

	#ifndef __SECWB_H__
	#include "secwb.h"
	#endif //__SECWB_H__

#endif // OT_BLD_WDI

// ***********************************************************
// *
// *  Tab
// *
// ***********************************************************

#ifdef OT_BLD_TABCTRL

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TABCTRL" )
	#endif

	// SECTabControlBase
	#ifndef __TABCTRLB_H__
	#include "tabctrlb.h"
	#endif //__TABCTRLB_H__

	// SECTabWndBase
	#ifndef __TABWNDB_H__
	#include "tabwndb.h"
	#endif //__TABWNDB_H__

	// SECTabControl
	#ifndef __TABCTRL_H__
	#include "tabctrl.h"
	#endif //__TABCTRL_H__

	// SECTabWnd
	#ifndef __TABWND_H__
	#include "tabwnd.h"
	#endif //__TABWND_H__

	// SEC3DTabControl
	#ifndef __TABCTRL3_H__
	#include "tabctrl3.h"
	#endif //__TABCTRL3_H__

	// SEC3DTabWnd
	#ifndef __TABWND3_H__
	#include "tabwnd3.h"
	#endif //__TABWND3_H__

#endif // OT_BLD_TABCTRL


// ***********************************************************
// *
// *  Shortcut Bar
// *
// ***********************************************************

#ifdef OT_BLD_SCUTBAR
	
	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_SCUTBAR" )
	#endif

	// SECShortcutBar
	#ifndef __SECOUTLOOKBAR_H__
	#include "olbar.h"
	#endif

	// SECShortcutListCtrl
	#ifndef __OLLC_H__
	#include "ollc.h"
	#endif

	#ifndef __LISTBAR_H__
	#include "listbar.h"
	#endif

#endif // OT_BLD_SCUTBAR

// ***********************************************************
// *
// *  UI Extensions
// *
// ***********************************************************

// ***********************************************************
// *
// *  Bitmapped dialog
// *
// ***********************************************************

#ifdef OT_BLD_BMPDLG

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_BMPDLG" )
	#endif

	// SECBitmapDialog
	#ifndef __SECBMPDG_H__
	#include "secbmpdg.h"
	#endif //__SECBMPDG_H__

#endif // OT_BLD_BMPDLG

// ***********************************************************
// *
// *  Custom Status Bar
// *
// ***********************************************************

#ifdef OT_BLD_STATUS

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_STATUS" )
	#endif

	// SECCustomStatusBar
	#ifndef __SBARCUST_H__
	#include "sbarcust.h"
	#endif //__SBARCUST_H__

#endif // OT_BLD_STATUS

// ***********************************************************
// *
// *  Keyboard Shortcuts
// *
// ***********************************************************

#ifdef OT_BLD_KBSCUT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_KBSCUT" )
	#endif

	// SECShortcuts
	#ifndef __SCUTACCL_H__
	#include "scutaccl.h"
	#endif //__SCUTACCL_H__

	// SECCommandList
	#ifndef __SCUTCMDS_H__
	#include "scutcmds.h"
	#endif //__SCUTCMDS_H__

	// SECShortcutDlg
	#ifndef __SCUTDIALOG_H__
	#include "scutdlg.h"
	#endif //__SCUTDIALOG_H__

	// SECAssignKeyDlg
	#ifndef __SCUTKDIALOG_H__
	#include "scutkdlg.h"
	#endif //__SCITKDIALOG_H__

#endif // OT_BLD_KBSCUT

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

#endif //  OT_BLD_GRADIENT

// ***********************************************************
// *
// *  Tip of the Day Class
// *
// ***********************************************************

#ifdef OT_BLD_TOD

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TOD" )
	#endif

	// SECTipOfDay
	#ifndef __SECTOD_H__
	#include "sectod.h"
	#endif //__SECTOD_H__

#endif // OT_BLD_TOD

// ***********************************************************
// *
// *  Workspace Manger
// *
// ***********************************************************

#ifdef OT_BLD_WSMGR

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_WSMGR" )
	#endif

	// SECWorkspaceManager
	#ifndef __SECWSMGR_H__
	#include "secwsmgr.h"
	#endif //__SECWSMGR_H__

	// SECWorkspaceManagerEx
	#ifndef __SECWSMGREX_H__
	#include "swsmgrex.h"
	#endif	// __SECWSMGREX_H__

	// SECWSLBEditorEx
	#ifndef __WKSEXDLG_H__
	#include "WkSExDlg.h"
	#endif

#endif // OT_BLD_WSMGR

// ***********************************************************
// *
// *  User-Tools Menu Class
// *
// ***********************************************************

#ifdef OT_BLD_TOOLSMENU

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TOOLSMENU" )
	#endif

	// SECUserTool
	#ifndef __USERTOOL_H__
	#include "usertool.h"
	#endif

	// SECUserToolsDlg
	#ifndef __USRTLDLG_H__
	#include "usrtldlg.h"
	#endif

#endif // OT_BLD_TOOLSMENU

// ***********************************************************
// *
// *  Thumbnail Classes
// *
// ***********************************************************

#ifdef OT_BLD_THUMBNAIL

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_THUMBNAIL" )
	#endif

	//Needed by SECTNFileDialog
	#ifndef __AFXDLGS_H__
	#include <afxdlgs.h>
	#endif

	//SECTNBitmap
	#ifndef __SECTNBITMAP_H__
	#include "sectnbmp.h"
	#endif //__SECTNBITMAP_H__

	//SECTNDC
	#ifndef __SECTNDC_H__
	#include "sectndc.h"
	#endif // __SECTNDC_H__

	//SECTNDocument
	#ifndef __SECTNDOC_H__
	#include "sectndoc.h"
	#endif //__SECTNDOC_H__

	//SECTNFileDialog
	#ifndef __SECTNFILEDLG_H__
	#include "sectndlg.h"
	#endif // __SECTNFILEDLG_H__

	//SECTNView
	#ifndef __SECTNVW_H__
	#include "sectnvw.h"
	#endif // __SECTNVW_H__

	//SECTNWinApp
	#ifndef __SECTNWIN_H__
	#include "sectnwin.h"
	#endif //__SECTNWIN_H__

#endif // OT_BLD_THUMBNAIL

// ***********************************************************
// *
// *  Splash Window Class
// *
// ***********************************************************

#ifdef OT_BLD_SPLASH

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_SPLASH" )
	#endif

	// SECSplashWnd
	#ifndef __SECSPLSH_H__
	#include "secsplsh.h"
	#endif //__SECSPLSH_H__

#endif // OT_BLD_SPLASH

// ***********************************************************
// *
// *  Tray Icon Class
// *
// ***********************************************************

#ifdef OT_BLD_TRAYICON

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TRAYICON" )
	#endif

	// SECTrayIcon
	#ifndef __SEC_TRAYICON_H
	#include "trayicon.h"
	#endif // __SEC_TRAYICON_H

#endif // OT_BLD_TRAYICON

// ***********************************************************
// *
// *  UTILITY CLASSES
// *
// ***********************************************************

// ***********************************************************
// *
// *  Encrypted File Class
// *
// ***********************************************************

#ifdef OT_BLD_ENCRYPT

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_ENCRYPT" )
	#endif

	// SECCryptFile
	#ifndef __CRYPTOFIL_H__
	#include "cryptfil.h"
	#endif   //__CRYPTOFIL_H__

#endif // OT_BLD_ENCRYPT

// ***********************************************************
// *
// *  Compressed File Class
// *
// ***********************************************************

#ifdef OT_BLD_COMPRESSFILE

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_COMPRESSFILE" )
	#endif

	// SECCompressFile
	#ifndef __SECCOMPRESS_FILE_H__
	#include "seccomp.h"
	#endif //__SECCOMPRESS_FILE_H__

#endif // OT_BLD_COMPRESSFILE


// ***********************************************************
// *
// *  File System Class
// *
// ***********************************************************

#ifdef OT_BLD_FILESYS

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_FILESYS" )
	#endif

	// SECFileSystem
	#ifndef __SECFILESYSTEM_H__
	#include "filesys.h"
	#endif //__SECFILESYSTEM_H__

#endif // OT_BLD_FILESYS

// ***********************************************************
// *
// *  Random Number Generator Class
// *
// ***********************************************************

#ifdef OT_BLD_RANDOM

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_RANDOM" )
	#endif

	// SECRandom
	#ifndef __SECRAND_H__
	#include "secrand.h"
	#endif //__SECRAND_H__

#endif // OT_BLD_RANDOM

// ***********************************************************
// *
// *  Registry Class
// *
// ***********************************************************

#ifdef OT_BLD_REGISTRY

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_REGISTRY" )
	#endif

	//Needed by SECRegistry
	#if defined(WIN32) && !defined(_WINREG_)
	#include <winreg.h>
	#endif

	// SECRegistry
	#ifndef __SECREG_H__
	#include "secreg.h"
	#endif //__SECREG_H__

#endif // OT_BLD_REGISTRY

// ***********************************************************
// *
// *  Persistent Tree Node
// *
// ***********************************************************

#ifdef OT_BLD_PERSTREE

	// SECPersistentTreeNode
	#ifndef __SECPERSTREE_H__
	#include "PersTree.h"
	#endif // __SECPERSTREE_H__

#endif // OT_BLD_PERSTREE

// ***********************************************************
// *
// *  Doc Template Utils
// *
// ***********************************************************

#ifdef OT_BLD_DOCTEMPUTILS

	// SECDocTemplateUtils
	#ifndef __DOCTEMPLATE_UTILS_H__
	#include "DtplUtil.h"
	#endif

#endif // OT_BLD_DOCTEMPUTILS

// ***********************************************************
// *
// *  
// *
// ***********************************************************



// ***********************************************************
// *
// *  Customizable Toolbar/Menubar
// *
// ***********************************************************

#ifdef OT_BLD_CUSTTBAR

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_CUSTTBAR" )
	#endif

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

#endif // OT_BLD_CUSTTBAR

// ***********************************************************
// *
// *  Docking Windows
// *
// ***********************************************************

#ifdef OT_BLD_DOCKWIN

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_DOCKWIN" )
	#endif

	// SECCDialogBar
	#ifndef __SBARDLG_H__
	#include "sbardlg.h"
	#endif //__SBARDLG_H__

	// SECDockBar
	#ifndef __SECBARDOCK_H__
	#include "sbardock.h"
	#endif //__SECBARDOCK_H__

	// SECControlBar
	#ifndef __SBARCORE_H__
	#include "sbarcore.h"
	#endif //__SBARCORE_H__

	// SECToolBar
	#ifndef __SBARTOOL_H__
	#include "sbartool.h"
	#endif //__SBARTOOL_H__

	// SECStatusBar
	#ifndef __SBARSTAT_H__
	#include "sbarstat.h"
	#endif //__SBARSTAT_H__


	#ifndef __SDOCKCNT_H__
	#include "sdockcnt.h"
	#endif //__SDOCKCNT_H__

	// SECDockContext
	#ifndef __SDOCKSTA_H__
	#include "sdocksta.h"
	#endif

	// SECControlBarManager
	#ifndef __SBARMGR_H__
	#include "sbarmgr.h"
	#endif //__SBARMGR_H__

	// SECOleServerItem
	#ifndef __SECOLEDOCK_H__
	#include "SOleDock.h"
	#endif

#endif //  OT_BLD_DOCKWIN


// ***********************************************************
// *
// *  Tree Control
// *
// ***********************************************************

#ifdef OT_BLD_TREECTRL

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_TREECTRL" )
	#endif

	// SECListTip
	#ifndef __SLSTCTIP_H__
	#include "slstctip.h"
	#endif // __SLSTCTIP_H__

	// SECListClient
	#ifndef __SLSTEDIT_H__
	#include "slstedit.h"
	#endif // __SLSTEDIT_H__

	// SECListCtrl
	#ifndef __SLSTCTL_H__
	#include "slstctl.h"
	#endif // __SLSTCTL_H__

	// SECListView
	#ifndef __SLSTVW_H__
	#include "slstvw.h"
	#endif // __SLSTVW_H__

	// SECTreeNode
	#ifndef __TREENODE_H__
	#include "TreeNode.h"
	#endif // __TREENODE_H__

	// SECTreeCtrl
	#ifndef __TRCTLX_H__
	#include "TrCtlX.h"
	#endif // __TRCTLX_H__

	// SECTreeView
	#ifndef __TRVWX_H__
	#include "TrVwX.h"
	#endif // __TRVWX_H__

#endif // OT_BLD_TREECTRL


// ***********************************************************
// *
// *  View Classes
// *
// ***********************************************************

#ifdef OT_BLD_PANZOOM

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OT_BLD_PANZOOM" )
	#endif

	// SECZoomView
	#ifndef __SECZMVW_H__
	#include "seczmvw.h"
	#endif //__SECZMVW_H__

	// SECPanView
	#ifndef __SECPANVW_H__
	#include "secpanvw.h"
	#endif //__SECPANVW_H__

	// SECPanWnd - The OverView Window
	#ifndef __SECPANWN_H__
	#include "secpanwn.h"
	#endif //__SECPANWN_H__

#endif // OT_BLD_PANZOOM

// ***********************************************************
// *
// *  Objective Toolkit PRO Components
// *
// ***********************************************************

#if defined(WIN32) && defined(OTPRO)

	#if defined(WIN32) && defined(SEC_DBG_HEADER_DIAGNOSTICS)
		#pragma message ( __TIME__ ":  OTPRO" )
	#endif

	// common library stuff
	#ifdef _SECDLL
		#ifndef _MVCDLL
			#define _MVCDLL
		#endif
	#endif


	#ifndef __PROALL_H_	
	#include "ProAll.h"
	#endif // __PROALL_H_	

#endif // OTPRO


#if _MFC_VER >= 0x0300
// poppack.h restores the original #pragma pack value
#include /* */ "poppack.h"
#else
// restore default packing value
#pragma pack()
#endif

#endif // __SECALL_H__

