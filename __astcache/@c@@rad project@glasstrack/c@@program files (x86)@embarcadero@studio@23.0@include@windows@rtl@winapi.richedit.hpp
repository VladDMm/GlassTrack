// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Winapi.RichEdit.pas' rev: 36.00 (Windows)

#ifndef Winapi_RichEditHPP
#define Winapi_RichEditHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Messages.hpp>
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------
#include <RichEdit.h>

namespace Winapi
{
namespace Richedit
{
//-- forward type declarations -----------------------------------------------
struct _CHARFORMAT2A;
struct _CHARFORMAT2W;
struct TReqSize;
struct TEndDropFiles;
struct TWMNotifyRE;
//-- type declarations -------------------------------------------------------
typedef CHARFORMATW CHARFORMAT;

typedef CHARFORMATA TCharFormatA;

typedef CHARFORMATW TCharFormatW;

typedef CHARFORMATW TCharFormat;

typedef CHARRANGE TCharRange;

typedef TEXTRANGEA TTextRangeA;

typedef TEXTRANGEW TTextRangeW;

typedef TEXTRANGEW TEXTRANGE;

#ifndef _WIN64
typedef System::LongInt __stdcall (*TEditStreamCallBack)(unsigned dwCookie, Winapi::Windows::PByte pbBuff, System::LongInt cb, System::LongInt &pcb);
#else /* _WIN64 */
typedef System::LongInt __stdcall (*TEditStreamCallBack)(unsigned __int64 dwCookie, Winapi::Windows::PByte pbBuff, System::LongInt cb, System::LongInt &pcb);
#endif /* _WIN64 */

typedef EDITSTREAM TEditStream;

typedef FINDTEXTA TFindTextA;

typedef FINDTEXTW TFindTextW;

typedef FINDTEXTW TFindText;

typedef FINDTEXTEXA TFindTextExA;

typedef FINDTEXTEXW TFindTextExW;

typedef FINDTEXTEXW TFindTextEx;

typedef FORMATRANGE TFormatRange;

typedef PARAFORMAT TParaFormat;

#pragma pack(push,4)
struct DECLSPEC_DRECORD _CHARFORMAT2A
{
public:
	unsigned cbSize;
	unsigned dwMask;
	unsigned dwEffects;
	System::LongInt yHeight;
	System::LongInt yOffset;
	Winapi::Windows::TColorRef crTextColor;
	System::Byte bCharSet;
	System::Byte bPitchAndFamily;
	System::StaticArray<char, 32> szFaceName;
	System::Word wWeight;
	short sSpacing;
	Winapi::Windows::TColorRef crBackColor;
	unsigned lid;
	unsigned dwReserved;
	short sStyle;
	System::Word wKerning;
	System::Byte bUnderlineType;
	System::Byte bAnimation;
	System::Byte bRevAuthor;
	System::Byte bReserved1;
};
#pragma pack(pop)


#pragma pack(push,4)
struct DECLSPEC_DRECORD _CHARFORMAT2W
{
public:
	unsigned cbSize;
	unsigned dwMask;
	unsigned dwEffects;
	System::LongInt yHeight;
	System::LongInt yOffset;
	Winapi::Windows::TColorRef crTextColor;
	System::Byte bCharSet;
	System::Byte bPitchAndFamily;
	System::StaticArray<System::WideChar, 32> szFaceName;
	System::Word wWeight;
	short sSpacing;
	Winapi::Windows::TColorRef crBackColor;
	unsigned lid;
	unsigned dwReserved;
	short sStyle;
	System::Word wKerning;
	System::Byte bUnderlineType;
	System::Byte bAnimation;
	System::Byte bRevAuthor;
	System::Byte bReserved1;
};
#pragma pack(pop)


typedef _CHARFORMAT2A TCharFormat2A;

typedef _CHARFORMAT2W TCharFormat2W;

typedef _CHARFORMAT2W TCharFormat2;

typedef PARAFORMAT2 TParaFormat2;

typedef MSGFILTER *PMsgFilter;

typedef MSGFILTER TMsgFilter;

typedef TReqSize *PReqSize;

#pragma pack(push,4)
struct DECLSPEC_DRECORD TReqSize
{
public:
	Winapi::Windows::TNMHdr nmhdr;
	Winapi::Windows::TRect rc;
};
#pragma pack(pop)


typedef SELCHANGE *PSelChange;

typedef SELCHANGE TSelChange;

#pragma pack(push,4)
struct DECLSPEC_DRECORD TEndDropFiles
{
public:
	Winapi::Windows::TNMHdr nmhdr;
	Winapi::Windows::THandle hDrop;
	System::LongInt cp;
	System::LongBool fProtected;
};
#pragma pack(pop)


typedef ENPROTECTED *PENProtected;

typedef ENPROTECTED TENProtected;

typedef ENSAVECLIPBOARD *PENSaveClipboard;

typedef ENSAVECLIPBOARD TENSaveClipboard;

typedef ENOLEOPFAILED TENOleOpFailed;

typedef OBJECTPOSITIONS TObjectPositions;

typedef ENLINK *PENLink;

typedef ENLINK TENLink;

typedef ENCORRECTTEXT TENCorrectText;

typedef PUNCTUATION TPunctuation;

typedef COMPCOLOR TCompColor;

typedef REPASTESPECIAL TRepasteSpecial;

typedef GETTEXTEX TGetTextEx;

typedef GETTEXTLENGTHEX TGetTextLengthEx;

struct DECLSPEC_DRECORD TWMNotifyRE
{
public:
	unsigned Msg;
#ifndef _WIN64
	unsigned IDCtrl;
#else /* _WIN64 */
	unsigned __int64 IDCtrl;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			PReqSize ReqSize;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			PENLink ENLink;
		};
		struct 
		{
			PENSaveClipboard ENSaveClipBoard;
		};
		struct 
		{
			PENProtected ENProtected;
		};
		struct 
		{
			Winapi::Windows::PNMHdr NMHdr;
		};
		
	};
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 SES_NOXLTSYMBOLRANGE = System::Int8(0x20);
static _DELPHI_CONST System::Int8 FT_MATCHCASE _DEPRECATED_ATTRIBUTE1("Use CommDlg.FR_MATCHCASE")  = System::Int8(0x4);
static _DELPHI_CONST System::Int8 FT_WHOLEWORD _DEPRECATED_ATTRIBUTE1("Use CommDlg.FR_WHOLEWORD")  = System::Int8(0x2);
static _DELPHI_CONST System::Word PFE_TABLEROW = System::Word(0xc000);
static _DELPHI_CONST System::Word PFE_TABLECELLEND = System::Word(0x8000);
static _DELPHI_CONST System::Word PFE_TABLECELL = System::Word(0x4000);
#ifndef _WIN64
extern DELPHI_PACKAGE int __fastcall SendEMGetTextExMessage(HWND hWnd, unsigned Msg, const TGetTextEx &wParam, System::UnicodeString &lParam);
#else /* _WIN64 */
extern DELPHI_PACKAGE __int64 __fastcall SendEMGetTextExMessage(HWND hWnd, unsigned Msg, const TGetTextEx &wParam, System::UnicodeString &lParam);
#endif /* _WIN64 */
}	/* namespace Richedit */
}	/* namespace Winapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI_RICHEDIT)
using namespace Winapi::Richedit;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI)
using namespace Winapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Winapi_RichEditHPP
