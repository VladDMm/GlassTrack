// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FireDAC.Stan.Def.pas' rev: 36.00 (Windows)

#ifndef FireDAC_Stan_DefHPP
#define FireDAC_Stan_DefHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <FireDAC.Stan.Intf.hpp>

//-- user supplied -----------------------------------------------------------
#ifndef _WIN64
#pragma link "FireDAC.Stan.Def.obj"
#else /* _WIN64 */
#pragma link "FireDAC.Stan.Def.o"
#endif /* _WIN64 */

namespace Firedac
{
namespace Stan
{
namespace Def
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall FDSaveConnDefGlobalFileName(const System::UnicodeString AName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FDLoadConnDefGlobalFileName();
extern DELPHI_PACKAGE void __fastcall FDSaveDriverDefGlobalFileName(const System::UnicodeString AName);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FDLoadDriverDefGlobalFileName();
}	/* namespace Def */
}	/* namespace Stan */
}	/* namespace Firedac */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FIREDAC_STAN_DEF)
using namespace Firedac::Stan::Def;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FIREDAC_STAN)
using namespace Firedac::Stan;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FIREDAC)
using namespace Firedac;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FireDAC_Stan_DefHPP
