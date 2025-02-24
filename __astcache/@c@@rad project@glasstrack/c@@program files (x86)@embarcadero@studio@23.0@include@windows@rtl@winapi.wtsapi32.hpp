// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Winapi.Wtsapi32.pas' rev: 36.00 (Windows)

#ifndef Winapi_Wtsapi32HPP
#define Winapi_Wtsapi32HPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>

//-- user supplied -----------------------------------------------------------
#include "wtsapi32.h"
#pragma comment(lib, "wtsapi32")

namespace Winapi
{
namespace Wtsapi32
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
typedef _WTS_SERVER_INFOW WTS_SERVER_INFO;

typedef PWTS_SERVER_INFOW PWTS_SERVER_INFO;

typedef _WTS_SESSION_INFOW WTS_SESSION_INFO;

typedef PWTS_SESSION_INFOW PWTS_SESSION_INFO;

typedef PWTS_SESSION_INFOA *PPWTS_SESSION_INFOA;

typedef PWTS_SESSION_INFOW *PPWTS_SESSION_INFOW;

typedef PPWTS_SESSION_INFOW PPWTS_SESSION_INFO;

typedef _WTS_SESSION_INFO_1W WTS_SESSION_INFO_1;

typedef PWTS_SESSION_INFO_1W PWTS_SESSION_INFO_1;

typedef _WTS_PROCESS_INFOW WTS_PROCESS_INFO;

typedef PWTS_PROCESS_INFOW PWTS_PROCESS_INFO;

typedef PWTS_PROCESS_INFOA *PPWTS_PROCESS_INFOA;

typedef PWTS_PROCESS_INFOW *PPWTS_PROCESS_INFOW;

typedef PPWTS_PROCESS_INFOW PPWTS_PROCESS_INFO;

typedef PWTSCONFIGINFOW PWTSCONFIGINFO;

typedef _WTSINFOW WTSINFO;

typedef PWTSINFOW PWTSINFO;

typedef _WTSINFOEX_LEVEL1_W WTSINFOEX_LEVEL1_;

typedef PWTSINFOEX_LEVEL1_W PWTSINFOEX_LEVEL1_;

typedef _WTSINFOEX_LEVEL_W WTSINFOEX_LEVEL_;

typedef PWTSINFOEX_LEVEL_W PWTSINFOEX_LEVEL_;

typedef _WTSINFOEXW WTSINFOEX;

typedef PWTSINFOEXW PWTSINFOEX;

typedef _WTSCLIENTW WTSCLIENT;

typedef PWTSCLIENTW PWTSCLIENT;

typedef _WTS_PRODUCT_INFOW PRODUCT_INFO;

typedef _WTS_VALIDATION_INFORMATIONW WTS_VALIDATION_INFORMATION;

typedef PWTS_VALIDATION_INFORMATIONW PWTS_VALIDATION_INFORMATION;

typedef _WTSUSERCONFIGW WTSUSERCONFIG;

typedef PWTSUSERCONFIGW PWTSUSERCONFIG;

typedef WTS_SESSION_ADDRESS _WTS_SESSION_ADDRESS;

typedef _WTS_PROCESS_INFO_EXW WTS_PROCESS_INFO_EX;

typedef PWTS_PROCESS_INFO_EXW PWTS_PROCESS_INFO_EX;

typedef WTSLISTENERNAMEW WTSLISTENERNAME;

typedef PWTSLISTENERNAMEW PWTSLISTENERNAME;

typedef _WTSLISTENERCONFIGW WTSLISTENERCONFIG;

typedef PWTSLISTENERCONFIGW PWTSLISTENERCONFIG;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 WTSConfigInfo_ = System::Int8(0x1a);
}	/* namespace Wtsapi32 */
}	/* namespace Winapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI_WTSAPI32)
using namespace Winapi::Wtsapi32;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI)
using namespace Winapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Winapi_Wtsapi32HPP
