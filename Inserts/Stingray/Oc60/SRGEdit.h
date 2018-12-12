
// SRGEdit.h

//////////////////////////////////////////////////////////////////////
// Stingray Software - Objective Chart(tm) Copyright (c) 1996 Stingray
// Software Inc. All Rights Reserved. This source code is only
// intended as a supplement to the Stingray Objective Chart product.
// See the help files for detailed information regarding the use of these classes
/////////////////////////////////////////////////////////////////////

#ifndef __SRGRAPHEDIT_H__
#define __SRGRAPHEDIT_H__

#ifndef __OCHART_H__

#include "ochart.h"

#endif

#include <afxcmn.h>

#include  "SRGRes.h"
//#include /* */ "SRGEdRes.h" superceeded by new SRGRes
#include  "TreeCtrl.h"
#include  "ItemEdit.h"
#include  "AnnoEdit.h"
#include  "VluEdit.h"
#include  "SwtchBtn.h"
#include  "CPropSht.h"
#include  "CmpChce.h"
#include  "grpeddlg.h"

#ifdef _OBJCHART_DLL

extern "C" OC_DATA int EditGraph(SRGraph *Graph);

#endif

#endif
