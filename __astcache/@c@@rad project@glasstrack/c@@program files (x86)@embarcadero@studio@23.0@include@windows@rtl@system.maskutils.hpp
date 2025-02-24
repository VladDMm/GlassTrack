// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'System.MaskUtils.pas' rev: 36.00 (Windows)

#ifndef System_MaskUtilsHPP
#define System_MaskUtilsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>

//-- user supplied -----------------------------------------------------------

namespace System
{
namespace Maskutils
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TMaskCharType : unsigned char { mcNone, mcLiteral, mcIntlLiteral, mcDirective, mcMask, mcMaskOpt, mcFieldSeparator, mcField };

enum DECLSPEC_DENUM TMaskDirective : unsigned char { mdReverseDir, mdUpperCase, mdLowerCase, mdLiteralChar };

typedef System::Set<TMaskDirective, TMaskDirective::mdReverseDir, TMaskDirective::mdLiteralChar> TMaskDirectives;

typedef System::UnicodeString TMaskedText;

typedef System::UnicodeString TEditMask;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::WideChar mDirReverse = (System::WideChar)(0x21);
static _DELPHI_CONST System::WideChar mDirUpperCase = (System::WideChar)(0x3e);
static _DELPHI_CONST System::WideChar mDirLowerCase = (System::WideChar)(0x3c);
static _DELPHI_CONST System::WideChar mDirLiteral = (System::WideChar)(0x5c);
static _DELPHI_CONST System::WideChar mMskAlpha = (System::WideChar)(0x4c);
static _DELPHI_CONST System::WideChar mMskAlphaOpt = (System::WideChar)(0x6c);
static _DELPHI_CONST System::WideChar mMskAlphaNum = (System::WideChar)(0x41);
static _DELPHI_CONST System::WideChar mMskAlphaNumOpt = (System::WideChar)(0x61);
static _DELPHI_CONST System::WideChar mMskAscii = (System::WideChar)(0x43);
static _DELPHI_CONST System::WideChar mMskAsciiOpt = (System::WideChar)(0x63);
static _DELPHI_CONST System::WideChar mMskNumeric = (System::WideChar)(0x30);
static _DELPHI_CONST System::WideChar mMskNumericOpt = (System::WideChar)(0x39);
static _DELPHI_CONST System::WideChar mMskNumSymOpt = (System::WideChar)(0x23);
static _DELPHI_CONST System::WideChar mMskTimeSeparator = (System::WideChar)(0x3a);
static _DELPHI_CONST System::WideChar mMskDateSeparator = (System::WideChar)(0x2f);
extern DELPHI_PACKAGE System::WideChar DefaultBlank;
extern DELPHI_PACKAGE System::WideChar MaskFieldSeparator;
extern DELPHI_PACKAGE System::WideChar MaskNoSave;
extern DELPHI_PACKAGE TMaskCharType __fastcall MaskGetCharType(const System::UnicodeString EditMask, int MaskOffset);
extern DELPHI_PACKAGE TMaskDirectives __fastcall MaskGetCurrentDirectives(const System::UnicodeString EditMask, int MaskOffset);
extern DELPHI_PACKAGE System::WideChar __fastcall MaskIntlLiteralToChar(System::WideChar IChar);
extern DELPHI_PACKAGE System::UnicodeString __fastcall MaskDoFormatText(const System::UnicodeString EditMask, const System::UnicodeString Value, System::WideChar Blank);
extern DELPHI_PACKAGE bool __fastcall MaskGetMaskSave(const System::UnicodeString EditMask);
extern DELPHI_PACKAGE System::WideChar __fastcall MaskGetMaskBlank(const System::UnicodeString EditMask);
extern DELPHI_PACKAGE int __fastcall MaskGetFldSeparator(const System::UnicodeString EditMask);
extern DELPHI_PACKAGE int __fastcall MaskOffsetToOffset(const System::UnicodeString EditMask, int MaskOffset);
extern DELPHI_PACKAGE int __fastcall MaskOffsetToWideOffset(const System::UnicodeString EditMask, int MaskOffset);
extern DELPHI_PACKAGE int __fastcall OffsetToMaskOffset(const System::UnicodeString EditMask, int Offset);
extern DELPHI_PACKAGE bool __fastcall IsLiteralChar(const System::UnicodeString EditMask, int Offset);
extern DELPHI_PACKAGE System::UnicodeString __fastcall PadInputLiterals(const System::UnicodeString EditMask, const System::UnicodeString Value, System::WideChar Blank);
extern DELPHI_PACKAGE System::UnicodeString __fastcall FormatMaskText(const System::UnicodeString EditMask, const System::UnicodeString Value);
}	/* namespace Maskutils */
}	/* namespace System */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM_MASKUTILS)
using namespace System::Maskutils;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM)
using namespace System;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// System_MaskUtilsHPP
