// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'System.UITypes.pas' rev: 36.00 (Windows)

#ifndef System_UITypesHPP
#define System_UITypesHPP

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
namespace Uitypes
{
  enum DECLSPEC_DENUM TFontStyle : unsigned char { fsBold, fsItalic, fsUnderline, fsStrikeOut };
  typedef System::SmallStringBase<124> TFontDataName;
  typedef System::SetBase<TFontStyle, fsBold, fsStrikeOut> TFontStylesBase;
}	/* namespace Uitypes */
}	/* namespace System */
namespace System
{
namespace Uitypes
{
  enum DECLSPEC_DENUM TCursor : short {crMin=-32768, crMax=32767};
}	/* namespace Uitypes */
}	/* namespace System */
namespace System
{
namespace Uitypes
{
  enum DECLSPEC_DENUM TColor : int {clMin=-0x7fffffff-1, clMax=0x7fffffff};
}	/* namespace Uitypes */
}	/* namespace System */

namespace System
{
namespace Uitypes
{
//-- forward type declarations -----------------------------------------------
struct TColorRec;
struct TAlphaColorRec;
struct TAlphaColorF;
//-- type declarations -------------------------------------------------------
enum class DECLSPEC_DENUM TOpenOption : unsigned char { ofReadOnly, ofOverwritePrompt, ofHideReadOnly, ofNoChangeDir, ofShowHelp, ofNoValidate, ofAllowMultiSelect, ofExtensionDifferent, ofPathMustExist, ofFileMustExist, ofCreatePrompt, ofShareAware, ofNoReadOnlyReturn, ofNoTestFileCreate, ofNoNetworkButton, ofNoLongNames, ofOldStyleDialog, ofNoDereferenceLinks, ofEnableIncludeNotify, ofEnableSizing, ofDontAddToRecent, ofForceShowHidden };

typedef System::Set<TOpenOption, _DELPHI_SET_ENUMERATOR(TOpenOption::ofReadOnly), _DELPHI_SET_ENUMERATOR(TOpenOption::ofForceShowHidden)> TOpenOptions;

enum class DECLSPEC_DENUM TOpenOptionEx : unsigned char { ofExNoPlacesBar };

typedef System::Set<TOpenOptionEx, _DELPHI_SET_ENUMERATOR(TOpenOptionEx::ofExNoPlacesBar), _DELPHI_SET_ENUMERATOR(TOpenOptionEx::ofExNoPlacesBar)> TOpenOptionsEx;

enum class DECLSPEC_DENUM TDialogType : unsigned char { Standard, Directory };

enum class DECLSPEC_DENUM TPrintRange : unsigned char { prAllPages, prSelection, prPageNums };

enum class DECLSPEC_DENUM TPrintDialogOption : unsigned char { poPrintToFile, poPageNums, poSelection, poWarning, poHelp, poDisablePrintToFile };

typedef System::Set<TPrintDialogOption, _DELPHI_SET_ENUMERATOR(TPrintDialogOption::poPrintToFile), _DELPHI_SET_ENUMERATOR(TPrintDialogOption::poDisablePrintToFile)> TPrintDialogOptions;

enum class DECLSPEC_DENUM TPageSetupDialogOption : unsigned char { psoDefaultMinMargins, psoDisableMargins, psoDisableOrientation, psoDisablePagePainting, psoDisablePaper, psoDisablePrinter, psoMargins, psoMinMargins, psoShowHelp, psoWarning, psoNoNetworkButton };

typedef System::Set<TPageSetupDialogOption, _DELPHI_SET_ENUMERATOR(TPageSetupDialogOption::psoDefaultMinMargins), _DELPHI_SET_ENUMERATOR(TPageSetupDialogOption::psoNoNetworkButton)> TPageSetupDialogOptions;

enum class DECLSPEC_DENUM TPrinterKind : unsigned char { pkDotMatrix, pkHPPCL };

enum class DECLSPEC_DENUM TPageType : unsigned char { ptEnvelope, ptPaper };

enum class DECLSPEC_DENUM TPageMeasureUnits : unsigned char { pmDefault, pmMillimeters, pmInches };

enum class DECLSPEC_DENUM TMsgDlgType : unsigned char { mtWarning, mtError, mtInformation, mtConfirmation, mtCustom };

enum class DECLSPEC_DENUM TMsgDlgBtn : unsigned char { mbYes, mbNo, mbOK, mbCancel, mbAbort, mbRetry, mbIgnore, mbAll, mbNoToAll, mbYesToAll, mbHelp, mbClose };

typedef System::Set<TMsgDlgBtn, _DELPHI_SET_ENUMERATOR(TMsgDlgBtn::mbYes), _DELPHI_SET_ENUMERATOR(TMsgDlgBtn::mbClose)> TMsgDlgButtons;

enum class DECLSPEC_DENUM TMsgDlgIcon : unsigned char { mdiNone, mdiWarning, mdiError, mdiInformation, mdiShield };

enum class DECLSPEC_DENUM TCalDayOfWeek : unsigned char { dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday, dowSunday, dowLocaleDefault };

enum class DECLSPEC_DENUM TBorderIcon : unsigned char { biSystemMenu, biMinimize, biMaximize, biHelp };

typedef System::Set<TBorderIcon, _DELPHI_SET_ENUMERATOR(TBorderIcon::biSystemMenu), _DELPHI_SET_ENUMERATOR(TBorderIcon::biHelp)> TBorderIcons;

enum class DECLSPEC_DENUM TWindowState : unsigned char { wsNormal, wsMinimized, wsMaximized };

enum class DECLSPEC_DENUM TEditCharCase : unsigned char { ecNormal, ecUpperCase, ecLowerCase };

typedef System::Byte TFontCharset;

enum class DECLSPEC_DENUM TFontPitch : unsigned char { fpDefault, fpVariable, fpFixed };

enum class DECLSPEC_DENUM TFontQuality : unsigned char { fqDefault, fqDraft, fqProof, fqNonAntialiased, fqAntialiased, fqClearType, fqClearTypeNatural };

typedef System::Set<TFontStyle, _DELPHI_SET_ENUMERATOR(TFontStyle::fsBold), _DELPHI_SET_ENUMERATOR(TFontStyle::fsStrikeOut)> TFontStyles;

typedef System::UnicodeString TFontName;

enum class DECLSPEC_DENUM TCloseAction : unsigned char { caNone, caHide, caFree, caMinimize };

enum class DECLSPEC_DENUM TMouseButton : unsigned char { mbLeft, mbRight, mbMiddle };

enum class DECLSPEC_DENUM TMouseActivate : unsigned char { maDefault, maActivate, maActivateAndEat, maNoActivate, maNoActivateAndEat };

typedef short TTabOrder;

typedef int TModalResult;

enum class DECLSPEC_DENUM TDragMode : unsigned char { dmManual, dmAutomatic };

enum class DECLSPEC_DENUM TDragState : unsigned char { dsDragEnter, dsDragLeave, dsDragMove };

enum class DECLSPEC_DENUM TDragKind : unsigned char { dkDrag, dkDock };

enum class DECLSPEC_DENUM TAnchorKind : unsigned char { akLeft, akTop, akRight, akBottom };

typedef System::Set<TAnchorKind, _DELPHI_SET_ENUMERATOR(TAnchorKind::akLeft), _DELPHI_SET_ENUMERATOR(TAnchorKind::akBottom)> TAnchors;

enum class DECLSPEC_DENUM TScrollCode : unsigned char { scLineUp, scLineDown, scPageUp, scPageDown, scPosition, scTrack, scTop, scBottom, scEndScroll };

enum class DECLSPEC_DENUM TPrinterState : unsigned char { psNoHandle, psHandleIC, psHandleDC };

enum class DECLSPEC_DENUM TPrinterOrientation : unsigned char { poPortrait, poLandscape };

enum class DECLSPEC_DENUM TPrinterCapability : unsigned char { pcCopies, pcOrientation, pcCollation };

typedef System::Set<TPrinterCapability, _DELPHI_SET_ENUMERATOR(TPrinterCapability::pcCopies), _DELPHI_SET_ENUMERATOR(TPrinterCapability::pcCollation)> TPrinterCapabilities;

typedef System::UInt32 TColorRef;

typedef TColor *PColor;

typedef TColorRec *PColorRec;

struct DECLSPEC_DRECORD TColorRec
{
public:
	static _DELPHI_CONST unsigned SystemColor = unsigned(0xff000000);
	
	static _DELPHI_CONST System::Int8 cSCROLLBAR = System::Int8(0x0);
	
	static _DELPHI_CONST System::Int8 cBACKGROUND = System::Int8(0x1);
	
	static _DELPHI_CONST System::Int8 cACTIVECAPTION = System::Int8(0x2);
	
	static _DELPHI_CONST System::Int8 cINACTIVECAPTION = System::Int8(0x3);
	
	static _DELPHI_CONST System::Int8 cMENU = System::Int8(0x4);
	
	static _DELPHI_CONST System::Int8 cWINDOW = System::Int8(0x5);
	
	static _DELPHI_CONST System::Int8 cWINDOWFRAME = System::Int8(0x6);
	
	static _DELPHI_CONST System::Int8 cMENUTEXT = System::Int8(0x7);
	
	static _DELPHI_CONST System::Int8 cWINDOWTEXT = System::Int8(0x8);
	
	static _DELPHI_CONST System::Int8 cCAPTIONTEXT = System::Int8(0x9);
	
	static _DELPHI_CONST System::Int8 cACTIVEBORDER = System::Int8(0xa);
	
	static _DELPHI_CONST System::Int8 cINACTIVEBORDER = System::Int8(0xb);
	
	static _DELPHI_CONST System::Int8 cAPPWORKSPACE = System::Int8(0xc);
	
	static _DELPHI_CONST System::Int8 cHIGHLIGHT = System::Int8(0xd);
	
	static _DELPHI_CONST System::Int8 cHIGHLIGHTTEXT = System::Int8(0xe);
	
	static _DELPHI_CONST System::Int8 cBTNFACE = System::Int8(0xf);
	
	static _DELPHI_CONST System::Int8 cBTNSHADOW = System::Int8(0x10);
	
	static _DELPHI_CONST System::Int8 cGRAYTEXT = System::Int8(0x11);
	
	static _DELPHI_CONST System::Int8 cBTNTEXT = System::Int8(0x12);
	
	static _DELPHI_CONST System::Int8 cINACTIVECAPTIONTEXT = System::Int8(0x13);
	
	static _DELPHI_CONST System::Int8 cBTNHIGHLIGHT = System::Int8(0x14);
	
	static _DELPHI_CONST System::Int8 c3DDKSHADOW = System::Int8(0x15);
	
	static _DELPHI_CONST System::Int8 c3DLIGHT = System::Int8(0x16);
	
	static _DELPHI_CONST System::Int8 cINFOTEXT = System::Int8(0x17);
	
	static _DELPHI_CONST System::Int8 cINFOBK = System::Int8(0x18);
	
	static _DELPHI_CONST System::Int8 cHOTLIGHT = System::Int8(0x1a);
	
	static _DELPHI_CONST System::Int8 cGRADIENTACTIVECAPTION = System::Int8(0x1b);
	
	static _DELPHI_CONST System::Int8 cGRADIENTINACTIVECAPTION = System::Int8(0x1c);
	
	static _DELPHI_CONST System::Int8 cMENUHILIGHT = System::Int8(0x1d);
	
	static _DELPHI_CONST System::Int8 cMENUBAR = System::Int8(0x1e);
	
	static _DELPHI_CONST System::Int8 cENDCOLORS = System::Int8(0x1e);
	
	static _DELPHI_CONST System::Int8 cDESKTOP = System::Int8(0x1);
	
	static _DELPHI_CONST System::Int8 c3DFACE = System::Int8(0xf);
	
	static _DELPHI_CONST System::Int8 c3DSHADOW = System::Int8(0x10);
	
	static _DELPHI_CONST System::Int8 c3DHIGHLIGHT = System::Int8(0x14);
	
	static _DELPHI_CONST System::Int8 c3DHILIGHT = System::Int8(0x14);
	
	static _DELPHI_CONST System::Int8 cBTNHILIGHT = System::Int8(0x14);
	
	static _DELPHI_CONST TColor SysScrollBar = TColor(-16777216);
	
	static _DELPHI_CONST TColor SysBackground = TColor(-16777215);
	
	static _DELPHI_CONST TColor SysActiveCaption = TColor(-16777214);
	
	static _DELPHI_CONST TColor SysInactiveCaption = TColor(-16777213);
	
	static _DELPHI_CONST TColor SysMenu = TColor(-16777212);
	
	static _DELPHI_CONST TColor SysWindow = TColor(-16777211);
	
	static _DELPHI_CONST TColor SysWindowFrame = TColor(-16777210);
	
	static _DELPHI_CONST TColor SysMenuText = TColor(-16777209);
	
	static _DELPHI_CONST TColor SysWindowText = TColor(-16777208);
	
	static _DELPHI_CONST TColor SysCaptionText = TColor(-16777207);
	
	static _DELPHI_CONST TColor SysActiveBorder = TColor(-16777206);
	
	static _DELPHI_CONST TColor SysInactiveBorder = TColor(-16777205);
	
	static _DELPHI_CONST TColor SysAppWorkSpace = TColor(-16777204);
	
	static _DELPHI_CONST TColor SysHighlight = TColor(-16777203);
	
	static _DELPHI_CONST TColor SysHighlightText = TColor(-16777202);
	
	static _DELPHI_CONST TColor SysBtnFace = TColor(-16777201);
	
	static _DELPHI_CONST TColor SysBtnShadow = TColor(-16777200);
	
	static _DELPHI_CONST TColor SysGrayText = TColor(-16777199);
	
	static _DELPHI_CONST TColor SysBtnText = TColor(-16777198);
	
	static _DELPHI_CONST TColor SysInactiveCaptionText = TColor(-16777197);
	
	static _DELPHI_CONST TColor SysBtnHighlight = TColor(-16777196);
	
	static _DELPHI_CONST TColor Sys3DDkShadow = TColor(-16777195);
	
	static _DELPHI_CONST TColor Sys3DLight = TColor(-16777194);
	
	static _DELPHI_CONST TColor SysInfoText = TColor(-16777193);
	
	static _DELPHI_CONST TColor SysInfoBk = TColor(-16777192);
	
	static _DELPHI_CONST TColor SysHotLight = TColor(-16777190);
	
	static _DELPHI_CONST TColor SysGradientActiveCaption = TColor(-16777189);
	
	static _DELPHI_CONST TColor SysGradientInactiveCaption = TColor(-16777188);
	
	static _DELPHI_CONST TColor SysMenuHighlight = TColor(-16777187);
	
	static _DELPHI_CONST TColor SysMenuBar = TColor(-16777186);
	
	static _DELPHI_CONST TColor SysNone = TColor(536870911);
	
	static _DELPHI_CONST TColor SysDefault = TColor(536870912);
	
	static _DELPHI_CONST TColor Aliceblue = TColor(16775408);
	
	static _DELPHI_CONST TColor Antiquewhite = TColor(14150650);
	
	static _DELPHI_CONST TColor Aqua = TColor(16776960);
	
	static _DELPHI_CONST TColor Aquamarine = TColor(13959039);
	
	static _DELPHI_CONST TColor Azure = TColor(16777200);
	
	static _DELPHI_CONST TColor Beige = TColor(14480885);
	
	static _DELPHI_CONST TColor Bisque = TColor(12903679);
	
	static _DELPHI_CONST TColor Black = TColor(0);
	
	static _DELPHI_CONST TColor Blanchedalmond = TColor(13495295);
	
	static _DELPHI_CONST TColor Blue = TColor(16711680);
	
	static _DELPHI_CONST TColor Blueviolet = TColor(14822282);
	
	static _DELPHI_CONST TColor Brown = TColor(2763429);
	
	static _DELPHI_CONST TColor Burlywood = TColor(8894686);
	
	static _DELPHI_CONST TColor Cadetblue = TColor(10526303);
	
	static _DELPHI_CONST TColor Chartreuse = TColor(65407);
	
	static _DELPHI_CONST TColor Chocolate = TColor(1993170);
	
	static _DELPHI_CONST TColor Coral = TColor(5275647);
	
	static _DELPHI_CONST TColor Cornflowerblue = TColor(15570276);
	
	static _DELPHI_CONST TColor Cornsilk = TColor(14481663);
	
	static _DELPHI_CONST TColor Crimson = TColor(3937500);
	
	static _DELPHI_CONST TColor Cyan = TColor(16776960);
	
	static _DELPHI_CONST TColor Darkblue = TColor(9109504);
	
	static _DELPHI_CONST TColor Darkcyan = TColor(9145088);
	
	static _DELPHI_CONST TColor Darkgoldenrod = TColor(755384);
	
	static _DELPHI_CONST TColor Darkgray = TColor(11119017);
	
	static _DELPHI_CONST TColor Darkgreen = TColor(25600);
	
	static _DELPHI_CONST TColor Darkgrey = TColor(11119017);
	
	static _DELPHI_CONST TColor Darkkhaki = TColor(7059389);
	
	static _DELPHI_CONST TColor Darkmagenta = TColor(9109643);
	
	static _DELPHI_CONST TColor Darkolivegreen = TColor(3107669);
	
	static _DELPHI_CONST TColor Darkorange = TColor(36095);
	
	static _DELPHI_CONST TColor Darkorchid = TColor(13382297);
	
	static _DELPHI_CONST TColor Darkred = TColor(139);
	
	static _DELPHI_CONST TColor Darksalmon = TColor(8034025);
	
	static _DELPHI_CONST TColor Darkseagreen = TColor(9419919);
	
	static _DELPHI_CONST TColor Darkslateblue = TColor(9125192);
	
	static _DELPHI_CONST TColor Darkslategray = TColor(5197615);
	
	static _DELPHI_CONST TColor Darkslategrey = TColor(5197615);
	
	static _DELPHI_CONST TColor Darkturquoise = TColor(13749760);
	
	static _DELPHI_CONST TColor Darkviolet = TColor(13828244);
	
	static _DELPHI_CONST TColor Deeppink = TColor(9639167);
	
	static _DELPHI_CONST TColor Deepskyblue = TColor(16760576);
	
	static _DELPHI_CONST TColor Dimgray = TColor(6908265);
	
	static _DELPHI_CONST TColor Dimgrey = TColor(6908265);
	
	static _DELPHI_CONST TColor Dodgerblue = TColor(16748574);
	
	static _DELPHI_CONST TColor Firebrick = TColor(2237106);
	
	static _DELPHI_CONST TColor Floralwhite = TColor(15792895);
	
	static _DELPHI_CONST TColor Forestgreen = TColor(2263842);
	
	static _DELPHI_CONST TColor Fuchsia = TColor(16711935);
	
	static _DELPHI_CONST TColor Gainsboro = TColor(14474460);
	
	static _DELPHI_CONST TColor Ghostwhite = TColor(16775416);
	
	static _DELPHI_CONST TColor Gold = TColor(55295);
	
	static _DELPHI_CONST TColor Goldenrod = TColor(2139610);
	
	static _DELPHI_CONST TColor Gray = TColor(8421504);
	
	static _DELPHI_CONST TColor Green = TColor(32768);
	
	static _DELPHI_CONST TColor Greenyellow = TColor(3145645);
	
	static _DELPHI_CONST TColor Grey = TColor(8421504);
	
	static _DELPHI_CONST TColor Honeydew = TColor(15794160);
	
	static _DELPHI_CONST TColor Hotpink = TColor(11823615);
	
	static _DELPHI_CONST TColor Indianred = TColor(6053069);
	
	static _DELPHI_CONST TColor Indigo = TColor(8519755);
	
	static _DELPHI_CONST TColor Ivory = TColor(15794175);
	
	static _DELPHI_CONST TColor Khaki = TColor(9234160);
	
	static _DELPHI_CONST TColor Lavender = TColor(16443110);
	
	static _DELPHI_CONST TColor Lavenderblush = TColor(16118015);
	
	static _DELPHI_CONST TColor Lawngreen = TColor(64636);
	
	static _DELPHI_CONST TColor Lemonchiffon = TColor(13499135);
	
	static _DELPHI_CONST TColor Lightblue = TColor(15128749);
	
	static _DELPHI_CONST TColor Lightcoral = TColor(8421616);
	
	static _DELPHI_CONST TColor Lightcyan = TColor(16777184);
	
	static _DELPHI_CONST TColor Lightgoldenrodyellow = TColor(13826810);
	
	static _DELPHI_CONST TColor Lightgray = TColor(13882323);
	
	static _DELPHI_CONST TColor Lightgreen = TColor(9498256);
	
	static _DELPHI_CONST TColor Lightgrey = TColor(13882323);
	
	static _DELPHI_CONST TColor Lightpink = TColor(12695295);
	
	static _DELPHI_CONST TColor Lightsalmon = TColor(8036607);
	
	static _DELPHI_CONST TColor Lightseagreen = TColor(11186720);
	
	static _DELPHI_CONST TColor Lightskyblue = TColor(16436871);
	
	static _DELPHI_CONST TColor Lightslategray = TColor(10061943);
	
	static _DELPHI_CONST TColor Lightslategrey = TColor(10061943);
	
	static _DELPHI_CONST TColor Lightsteelblue = TColor(14599344);
	
	static _DELPHI_CONST TColor Lightyellow = TColor(14745599);
	
	static _DELPHI_CONST TColor LtGray = TColor(12632256);
	
	static _DELPHI_CONST TColor MedGray = TColor(10789024);
	
	static _DELPHI_CONST TColor DkGray = TColor(8421504);
	
	static _DELPHI_CONST TColor MoneyGreen = TColor(12639424);
	
	static _DELPHI_CONST TColor LegacySkyBlue = TColor(15780518);
	
	static _DELPHI_CONST TColor Cream = TColor(15793151);
	
	static _DELPHI_CONST TColor Lime = TColor(65280);
	
	static _DELPHI_CONST TColor Limegreen = TColor(3329330);
	
	static _DELPHI_CONST TColor Linen = TColor(15134970);
	
	static _DELPHI_CONST TColor Magenta = TColor(16711935);
	
	static _DELPHI_CONST TColor Maroon = TColor(128);
	
	static _DELPHI_CONST TColor Mediumaquamarine = TColor(11193702);
	
	static _DELPHI_CONST TColor Mediumblue = TColor(13434880);
	
	static _DELPHI_CONST TColor Mediumorchid = TColor(13850042);
	
	static _DELPHI_CONST TColor Mediumpurple = TColor(14381203);
	
	static _DELPHI_CONST TColor Mediumseagreen = TColor(7451452);
	
	static _DELPHI_CONST TColor Mediumslateblue = TColor(15624315);
	
	static _DELPHI_CONST TColor Mediumspringgreen = TColor(10156544);
	
	static _DELPHI_CONST TColor Mediumturquoise = TColor(13422920);
	
	static _DELPHI_CONST TColor Mediumvioletred = TColor(8721863);
	
	static _DELPHI_CONST TColor Midnightblue = TColor(7346457);
	
	static _DELPHI_CONST TColor Mintcream = TColor(16449525);
	
	static _DELPHI_CONST TColor Mistyrose = TColor(14804223);
	
	static _DELPHI_CONST TColor Moccasin = TColor(11920639);
	
	static _DELPHI_CONST TColor Navajowhite = TColor(11394815);
	
	static _DELPHI_CONST TColor Navy = TColor(8388608);
	
	static _DELPHI_CONST TColor Oldlace = TColor(15136253);
	
	static _DELPHI_CONST TColor Olive = TColor(32896);
	
	static _DELPHI_CONST TColor Olivedrab = TColor(2330219);
	
	static _DELPHI_CONST TColor Orange = TColor(42495);
	
	static _DELPHI_CONST TColor Orangered = TColor(17919);
	
	static _DELPHI_CONST TColor Orchid = TColor(14053594);
	
	static _DELPHI_CONST TColor Palegoldenrod = TColor(11200750);
	
	static _DELPHI_CONST TColor Palegreen = TColor(10025880);
	
	static _DELPHI_CONST TColor Paleturquoise = TColor(15658671);
	
	static _DELPHI_CONST TColor Palevioletred = TColor(9662683);
	
	static _DELPHI_CONST TColor Papayawhip = TColor(14020607);
	
	static _DELPHI_CONST TColor Peachpuff = TColor(12180223);
	
	static _DELPHI_CONST TColor Peru = TColor(4163021);
	
	static _DELPHI_CONST TColor Pink = TColor(13353215);
	
	static _DELPHI_CONST TColor Plum = TColor(14524637);
	
	static _DELPHI_CONST TColor Powderblue = TColor(15130800);
	
	static _DELPHI_CONST TColor Purple = TColor(8388736);
	
	static _DELPHI_CONST TColor Red = TColor(255);
	
	static _DELPHI_CONST TColor Rosybrown = TColor(9408444);
	
	static _DELPHI_CONST TColor Royalblue = TColor(14772545);
	
	static _DELPHI_CONST TColor Saddlebrown = TColor(1262987);
	
	static _DELPHI_CONST TColor Salmon = TColor(7504122);
	
	static _DELPHI_CONST TColor Sandybrown = TColor(6333684);
	
	static _DELPHI_CONST TColor Seagreen = TColor(5737262);
	
	static _DELPHI_CONST TColor Seashell = TColor(15660543);
	
	static _DELPHI_CONST TColor Sienna = TColor(2970272);
	
	static _DELPHI_CONST TColor Silver = TColor(12632256);
	
	static _DELPHI_CONST TColor Skyblue = TColor(15453831);
	
	static _DELPHI_CONST TColor Slateblue = TColor(13458026);
	
	static _DELPHI_CONST TColor Slategray = TColor(9470064);
	
	static _DELPHI_CONST TColor Slategrey = TColor(9470064);
	
	static _DELPHI_CONST TColor Snow = TColor(16448255);
	
	static _DELPHI_CONST TColor Springgreen = TColor(8388352);
	
	static _DELPHI_CONST TColor Steelblue = TColor(11829830);
	
	static _DELPHI_CONST TColor Tan = TColor(9221330);
	
	static _DELPHI_CONST TColor Teal = TColor(8421376);
	
	static _DELPHI_CONST TColor Thistle = TColor(14204888);
	
	static _DELPHI_CONST TColor Tomato = TColor(4678655);
	
	static _DELPHI_CONST TColor Turquoise = TColor(13688896);
	
	static _DELPHI_CONST TColor Violet = TColor(15631086);
	
	static _DELPHI_CONST TColor Wheat = TColor(11788021);
	
	static _DELPHI_CONST TColor White = TColor(16777215);
	
	static _DELPHI_CONST TColor Whitesmoke = TColor(16119285);
	
	static _DELPHI_CONST TColor Yellow = TColor(65535);
	
	static _DELPHI_CONST TColor Yellowgreen = TColor(3329434);
	
	static _DELPHI_CONST TColor Null = TColor(0);
	
	static int __fastcall (*ColorToRGB)(TColor Color);
	
public:
	union
	{
		struct 
		{
			System::Byte R;
			System::Byte G;
			System::Byte B;
			System::Byte A;
		};
		struct 
		{
			System::Word HiWord;
			System::Word LoWord;
		};
		struct 
		{
			TColor Color;
		};
		
	};
};


typedef TColorRec TColors;

typedef unsigned TAlphaColor;

typedef TAlphaColor *PAlphaColor;

typedef TAlphaColorRec *PAlphaColorRec;

struct DECLSPEC_DRECORD TAlphaColorRec
{
public:
	static _DELPHI_CONST TAlphaColor Alpha = TAlphaColor(0xff000000);
	
	static _DELPHI_CONST TAlphaColor Aliceblue = TAlphaColor(0xfff0f8ff);
	
	static _DELPHI_CONST TAlphaColor Antiquewhite = TAlphaColor(0xfffaebd7);
	
	static _DELPHI_CONST TAlphaColor Aqua = TAlphaColor(0xff00ffff);
	
	static _DELPHI_CONST TAlphaColor Aquamarine = TAlphaColor(0xff7fffd4);
	
	static _DELPHI_CONST TAlphaColor Azure = TAlphaColor(0xfff0ffff);
	
	static _DELPHI_CONST TAlphaColor Beige = TAlphaColor(0xfff5f5dc);
	
	static _DELPHI_CONST TAlphaColor Bisque = TAlphaColor(0xffffe4c4);
	
	static _DELPHI_CONST TAlphaColor Black = TAlphaColor(0xff000000);
	
	static _DELPHI_CONST TAlphaColor Blanchedalmond = TAlphaColor(0xffffebcd);
	
	static _DELPHI_CONST TAlphaColor Blue = TAlphaColor(0xff0000ff);
	
	static _DELPHI_CONST TAlphaColor Blueviolet = TAlphaColor(0xff8a2be2);
	
	static _DELPHI_CONST TAlphaColor Brown = TAlphaColor(0xffa52a2a);
	
	static _DELPHI_CONST TAlphaColor Burlywood = TAlphaColor(0xffdeb887);
	
	static _DELPHI_CONST TAlphaColor Cadetblue = TAlphaColor(0xff5f9ea0);
	
	static _DELPHI_CONST TAlphaColor Chartreuse = TAlphaColor(0xff7fff00);
	
	static _DELPHI_CONST TAlphaColor Chocolate = TAlphaColor(0xffd2691e);
	
	static _DELPHI_CONST TAlphaColor Coral = TAlphaColor(0xffff7f50);
	
	static _DELPHI_CONST TAlphaColor Cornflowerblue = TAlphaColor(0xff6495ed);
	
	static _DELPHI_CONST TAlphaColor Cornsilk = TAlphaColor(0xfffff8dc);
	
	static _DELPHI_CONST TAlphaColor Crimson = TAlphaColor(0xffdc143c);
	
	static _DELPHI_CONST TAlphaColor Cyan = TAlphaColor(0xff00ffff);
	
	static _DELPHI_CONST TAlphaColor Darkblue = TAlphaColor(0xff00008b);
	
	static _DELPHI_CONST TAlphaColor Darkcyan = TAlphaColor(0xff008b8b);
	
	static _DELPHI_CONST TAlphaColor Darkgoldenrod = TAlphaColor(0xffb8860b);
	
	static _DELPHI_CONST TAlphaColor Darkgray = TAlphaColor(0xffa9a9a9);
	
	static _DELPHI_CONST TAlphaColor Darkgreen = TAlphaColor(0xff006400);
	
	static _DELPHI_CONST TAlphaColor Darkgrey = TAlphaColor(0xffa9a9a9);
	
	static _DELPHI_CONST TAlphaColor Darkkhaki = TAlphaColor(0xffbdb76b);
	
	static _DELPHI_CONST TAlphaColor Darkmagenta = TAlphaColor(0xff8b008b);
	
	static _DELPHI_CONST TAlphaColor Darkolivegreen = TAlphaColor(0xff556b2f);
	
	static _DELPHI_CONST TAlphaColor Darkorange = TAlphaColor(0xffff8c00);
	
	static _DELPHI_CONST TAlphaColor Darkorchid = TAlphaColor(0xff9932cc);
	
	static _DELPHI_CONST TAlphaColor Darkred = TAlphaColor(0xff8b0000);
	
	static _DELPHI_CONST TAlphaColor Darksalmon = TAlphaColor(0xffe9967a);
	
	static _DELPHI_CONST TAlphaColor Darkseagreen = TAlphaColor(0xff8fbc8f);
	
	static _DELPHI_CONST TAlphaColor Darkslateblue = TAlphaColor(0xff483d8b);
	
	static _DELPHI_CONST TAlphaColor Darkslategray = TAlphaColor(0xff2f4f4f);
	
	static _DELPHI_CONST TAlphaColor Darkslategrey = TAlphaColor(0xff2f4f4f);
	
	static _DELPHI_CONST TAlphaColor Darkturquoise = TAlphaColor(0xff00ced1);
	
	static _DELPHI_CONST TAlphaColor Darkviolet = TAlphaColor(0xff9400d3);
	
	static _DELPHI_CONST TAlphaColor Deeppink = TAlphaColor(0xffff1493);
	
	static _DELPHI_CONST TAlphaColor Deepskyblue = TAlphaColor(0xff00bfff);
	
	static _DELPHI_CONST TAlphaColor Dimgray = TAlphaColor(0xff696969);
	
	static _DELPHI_CONST TAlphaColor Dimgrey = TAlphaColor(0xff696969);
	
	static _DELPHI_CONST TAlphaColor Dodgerblue = TAlphaColor(0xff1e90ff);
	
	static _DELPHI_CONST TAlphaColor Firebrick = TAlphaColor(0xffb22222);
	
	static _DELPHI_CONST TAlphaColor Floralwhite = TAlphaColor(0xfffffaf0);
	
	static _DELPHI_CONST TAlphaColor Forestgreen = TAlphaColor(0xff228b22);
	
	static _DELPHI_CONST TAlphaColor Fuchsia = TAlphaColor(0xffff00ff);
	
	static _DELPHI_CONST TAlphaColor Gainsboro = TAlphaColor(0xffdcdcdc);
	
	static _DELPHI_CONST TAlphaColor Ghostwhite = TAlphaColor(0xfff8f8ff);
	
	static _DELPHI_CONST TAlphaColor Gold = TAlphaColor(0xffffd700);
	
	static _DELPHI_CONST TAlphaColor Goldenrod = TAlphaColor(0xffdaa520);
	
	static _DELPHI_CONST TAlphaColor Gray = TAlphaColor(0xff808080);
	
	static _DELPHI_CONST TAlphaColor Green = TAlphaColor(0xff008000);
	
	static _DELPHI_CONST TAlphaColor Greenyellow = TAlphaColor(0xffadff2f);
	
	static _DELPHI_CONST TAlphaColor Grey = TAlphaColor(0xff808080);
	
	static _DELPHI_CONST TAlphaColor Honeydew = TAlphaColor(0xfff0fff0);
	
	static _DELPHI_CONST TAlphaColor Hotpink = TAlphaColor(0xffff69b4);
	
	static _DELPHI_CONST TAlphaColor Indianred = TAlphaColor(0xffcd5c5c);
	
	static _DELPHI_CONST TAlphaColor Indigo = TAlphaColor(0xff4b0082);
	
	static _DELPHI_CONST TAlphaColor Ivory = TAlphaColor(0xfffffff0);
	
	static _DELPHI_CONST TAlphaColor Khaki = TAlphaColor(0xfff0e68c);
	
	static _DELPHI_CONST TAlphaColor Lavender = TAlphaColor(0xffe6e6fa);
	
	static _DELPHI_CONST TAlphaColor Lavenderblush = TAlphaColor(0xfffff0f5);
	
	static _DELPHI_CONST TAlphaColor Lawngreen = TAlphaColor(0xff7cfc00);
	
	static _DELPHI_CONST TAlphaColor Lemonchiffon = TAlphaColor(0xfffffacd);
	
	static _DELPHI_CONST TAlphaColor Lightblue = TAlphaColor(0xffadd8e6);
	
	static _DELPHI_CONST TAlphaColor Lightcoral = TAlphaColor(0xfff08080);
	
	static _DELPHI_CONST TAlphaColor Lightcyan = TAlphaColor(0xffe0ffff);
	
	static _DELPHI_CONST TAlphaColor Lightgoldenrodyellow = TAlphaColor(0xfffafad2);
	
	static _DELPHI_CONST TAlphaColor Lightgray = TAlphaColor(0xffd3d3d3);
	
	static _DELPHI_CONST TAlphaColor Lightgreen = TAlphaColor(0xff90ee90);
	
	static _DELPHI_CONST TAlphaColor Lightgrey = TAlphaColor(0xffd3d3d3);
	
	static _DELPHI_CONST TAlphaColor Lightpink = TAlphaColor(0xffffb6c1);
	
	static _DELPHI_CONST TAlphaColor Lightsalmon = TAlphaColor(0xffffa07a);
	
	static _DELPHI_CONST TAlphaColor Lightseagreen = TAlphaColor(0xff20b2aa);
	
	static _DELPHI_CONST TAlphaColor Lightskyblue = TAlphaColor(0xff87cefa);
	
	static _DELPHI_CONST TAlphaColor Lightslategray = TAlphaColor(0xff778899);
	
	static _DELPHI_CONST TAlphaColor Lightslategrey = TAlphaColor(0xff778899);
	
	static _DELPHI_CONST TAlphaColor Lightsteelblue = TAlphaColor(0xffb0c4de);
	
	static _DELPHI_CONST TAlphaColor Lightyellow = TAlphaColor(0xffffffe0);
	
	static _DELPHI_CONST TAlphaColor LtGray = TAlphaColor(0xffc0c0c0);
	
	static _DELPHI_CONST TAlphaColor MedGray = TAlphaColor(0xffa0a0a0);
	
	static _DELPHI_CONST TAlphaColor DkGray = TAlphaColor(0xff808080);
	
	static _DELPHI_CONST TAlphaColor MoneyGreen = TAlphaColor(0xffc0dcc0);
	
	static _DELPHI_CONST TAlphaColor LegacySkyBlue = TAlphaColor(0xfff0caa6);
	
	static _DELPHI_CONST TAlphaColor Cream = TAlphaColor(0xfff0fbff);
	
	static _DELPHI_CONST TAlphaColor Lime = TAlphaColor(0xff00ff00);
	
	static _DELPHI_CONST TAlphaColor Limegreen = TAlphaColor(0xff32cd32);
	
	static _DELPHI_CONST TAlphaColor Linen = TAlphaColor(0xfffaf0e6);
	
	static _DELPHI_CONST TAlphaColor Magenta = TAlphaColor(0xffff00ff);
	
	static _DELPHI_CONST TAlphaColor Maroon = TAlphaColor(0xff800000);
	
	static _DELPHI_CONST TAlphaColor Mediumaquamarine = TAlphaColor(0xff66cdaa);
	
	static _DELPHI_CONST TAlphaColor Mediumblue = TAlphaColor(0xff0000cd);
	
	static _DELPHI_CONST TAlphaColor Mediumorchid = TAlphaColor(0xffba55d3);
	
	static _DELPHI_CONST TAlphaColor Mediumpurple = TAlphaColor(0xff9370db);
	
	static _DELPHI_CONST TAlphaColor Mediumseagreen = TAlphaColor(0xff3cb371);
	
	static _DELPHI_CONST TAlphaColor Mediumslateblue = TAlphaColor(0xff7b68ee);
	
	static _DELPHI_CONST TAlphaColor Mediumspringgreen = TAlphaColor(0xff00fa9a);
	
	static _DELPHI_CONST TAlphaColor Mediumturquoise = TAlphaColor(0xff48d1cc);
	
	static _DELPHI_CONST TAlphaColor Mediumvioletred = TAlphaColor(0xffc71585);
	
	static _DELPHI_CONST TAlphaColor Midnightblue = TAlphaColor(0xff191970);
	
	static _DELPHI_CONST TAlphaColor Mintcream = TAlphaColor(0xfff5fffa);
	
	static _DELPHI_CONST TAlphaColor Mistyrose = TAlphaColor(0xffffe4e1);
	
	static _DELPHI_CONST TAlphaColor Moccasin = TAlphaColor(0xffffe4b5);
	
	static _DELPHI_CONST TAlphaColor Navajowhite = TAlphaColor(0xffffdead);
	
	static _DELPHI_CONST TAlphaColor Navy = TAlphaColor(0xff000080);
	
	static _DELPHI_CONST TAlphaColor Oldlace = TAlphaColor(0xfffdf5e6);
	
	static _DELPHI_CONST TAlphaColor Olive = TAlphaColor(0xff808000);
	
	static _DELPHI_CONST TAlphaColor Olivedrab = TAlphaColor(0xff6b8e23);
	
	static _DELPHI_CONST TAlphaColor Orange = TAlphaColor(0xffffa500);
	
	static _DELPHI_CONST TAlphaColor Orangered = TAlphaColor(0xffff4500);
	
	static _DELPHI_CONST TAlphaColor Orchid = TAlphaColor(0xffda70d6);
	
	static _DELPHI_CONST TAlphaColor Palegoldenrod = TAlphaColor(0xffeee8aa);
	
	static _DELPHI_CONST TAlphaColor Palegreen = TAlphaColor(0xff98fb98);
	
	static _DELPHI_CONST TAlphaColor Paleturquoise = TAlphaColor(0xffafeeee);
	
	static _DELPHI_CONST TAlphaColor Palevioletred = TAlphaColor(0xffdb7093);
	
	static _DELPHI_CONST TAlphaColor Papayawhip = TAlphaColor(0xffffefd5);
	
	static _DELPHI_CONST TAlphaColor Peachpuff = TAlphaColor(0xffffdab9);
	
	static _DELPHI_CONST TAlphaColor Peru = TAlphaColor(0xffcd853f);
	
	static _DELPHI_CONST TAlphaColor Pink = TAlphaColor(0xffffc0cb);
	
	static _DELPHI_CONST TAlphaColor Plum = TAlphaColor(0xffdda0dd);
	
	static _DELPHI_CONST TAlphaColor Powderblue = TAlphaColor(0xffb0e0e6);
	
	static _DELPHI_CONST TAlphaColor Purple = TAlphaColor(0xff800080);
	
	static _DELPHI_CONST TAlphaColor Red = TAlphaColor(0xffff0000);
	
	static _DELPHI_CONST TAlphaColor Rosybrown = TAlphaColor(0xffbc8f8f);
	
	static _DELPHI_CONST TAlphaColor Royalblue = TAlphaColor(0xff4169e1);
	
	static _DELPHI_CONST TAlphaColor Saddlebrown = TAlphaColor(0xff8b4513);
	
	static _DELPHI_CONST TAlphaColor Salmon = TAlphaColor(0xfffa8072);
	
	static _DELPHI_CONST TAlphaColor Sandybrown = TAlphaColor(0xfff4a460);
	
	static _DELPHI_CONST TAlphaColor Seagreen = TAlphaColor(0xff2e8b57);
	
	static _DELPHI_CONST TAlphaColor Seashell = TAlphaColor(0xfffff5ee);
	
	static _DELPHI_CONST TAlphaColor Sienna = TAlphaColor(0xffa0522d);
	
	static _DELPHI_CONST TAlphaColor Silver = TAlphaColor(0xffc0c0c0);
	
	static _DELPHI_CONST TAlphaColor Skyblue = TAlphaColor(0xff87ceeb);
	
	static _DELPHI_CONST TAlphaColor Slateblue = TAlphaColor(0xff6a5acd);
	
	static _DELPHI_CONST TAlphaColor Slategray = TAlphaColor(0xff708090);
	
	static _DELPHI_CONST TAlphaColor Slategrey = TAlphaColor(0xff708090);
	
	static _DELPHI_CONST TAlphaColor Snow = TAlphaColor(0xfffffafa);
	
	static _DELPHI_CONST TAlphaColor Springgreen = TAlphaColor(0xff00ff7f);
	
	static _DELPHI_CONST TAlphaColor Steelblue = TAlphaColor(0xff4682b4);
	
	static _DELPHI_CONST TAlphaColor Tan = TAlphaColor(0xffd2b48c);
	
	static _DELPHI_CONST TAlphaColor Teal = TAlphaColor(0xff008080);
	
	static _DELPHI_CONST TAlphaColor Thistle = TAlphaColor(0xffd8bfd8);
	
	static _DELPHI_CONST TAlphaColor Tomato = TAlphaColor(0xffff6347);
	
	static _DELPHI_CONST TAlphaColor Turquoise = TAlphaColor(0xff40e0d0);
	
	static _DELPHI_CONST TAlphaColor Violet = TAlphaColor(0xffee82ee);
	
	static _DELPHI_CONST TAlphaColor Wheat = TAlphaColor(0xfff5deb3);
	
	static _DELPHI_CONST TAlphaColor White = TAlphaColor(0xffffffff);
	
	static _DELPHI_CONST TAlphaColor Whitesmoke = TAlphaColor(0xfff5f5f5);
	
	static _DELPHI_CONST TAlphaColor Yellow = TAlphaColor(0xffffff00);
	
	static _DELPHI_CONST TAlphaColor Yellowgreen = TAlphaColor(0xff9acd32);
	
	static _DELPHI_CONST TAlphaColor Null = TAlphaColor(0x0);
	
	__fastcall TAlphaColorRec(const TAlphaColor Color);
	static int __fastcall (*ColorToRGB)(TAlphaColor Color);
	TAlphaColorRec() {}
	
public:
	union
	{
		struct 
		{
			System::Byte B;
			System::Byte G;
			System::Byte R;
			System::Byte A;
		};
		struct 
		{
			System::Word HiWord;
			System::Word LoWord;
		};
		struct 
		{
			TAlphaColor Color;
		};
		
	};
};


typedef TAlphaColorRec TAlphaColors;

typedef TAlphaColorF *PAlphaColorF;

struct DECLSPEC_DRECORD TAlphaColorF
{
public:
	#define TAlphaColorF_Epsilon  (1.525900E-05)
	
	
private:
	static bool __fastcall SameComponent(const float Value1, const float Value2);
	static float __fastcall ClampComponent(const float Value);
	
public:
	float R;
	float G;
	float B;
	float A;
	static TAlphaColorF __fastcall Create(const float R, const float G, const float B, const float A = 1.000000E+00f)/* overload */;
	static TAlphaColorF __fastcall Create(const TAlphaColor Color)/* overload */;
	static TAlphaColorF __fastcall _op_Addition(const TAlphaColorF &Color1, const TAlphaColorF &Color2);
	static TAlphaColorF __fastcall _op_Subtraction(const TAlphaColorF &Color1, const TAlphaColorF &Color2);
	static bool __fastcall _op_Equality(const TAlphaColorF &Color1, const TAlphaColorF &Color2);
	static bool __fastcall _op_Inequality(const TAlphaColorF &Color1, const TAlphaColorF &Color2);
	static TAlphaColorF __fastcall _op_UnaryNegation(const TAlphaColorF &Color);
	static TAlphaColorF __fastcall _op_Multiply(const TAlphaColorF &Color1, const TAlphaColorF &Color2);
	static TAlphaColorF __fastcall _op_Multiply(const TAlphaColorF &Color, const float Factor);
	static TAlphaColorF __fastcall _op_Multiply(const float Factor, const TAlphaColorF &Color);
	static TAlphaColorF __fastcall _op_Division(const TAlphaColorF &Color, const float Factor);
	TAlphaColorF __fastcall PremultipliedAlpha();
	TAlphaColorF __fastcall UnpremultipliedAlpha();
	TAlphaColorF __fastcall Clamp();
	TAlphaColor __fastcall ToAlphaColor();
	
	friend TAlphaColorF operator +(const TAlphaColorF &Color1, const TAlphaColorF &Color2) { return TAlphaColorF::_op_Addition(Color1, Color2); }
	friend TAlphaColorF operator -(const TAlphaColorF &Color1, const TAlphaColorF &Color2) { return TAlphaColorF::_op_Subtraction(Color1, Color2); }
	friend bool operator ==(const TAlphaColorF &Color1, const TAlphaColorF &Color2) { return TAlphaColorF::_op_Equality(Color1, Color2); }
	friend bool operator !=(const TAlphaColorF &Color1, const TAlphaColorF &Color2) { return TAlphaColorF::_op_Inequality(Color1, Color2); }
	TAlphaColorF operator -() { return TAlphaColorF::_op_UnaryNegation(*this); }
	friend TAlphaColorF operator *(const TAlphaColorF &Color1, const TAlphaColorF &Color2) { return TAlphaColorF::_op_Multiply(Color1, Color2); }
	friend TAlphaColorF operator *(const TAlphaColorF &Color, const float Factor) { return TAlphaColorF::_op_Multiply(Color, Factor); }
	friend TAlphaColorF operator *(const float Factor, const TAlphaColorF &Color) { return TAlphaColorF::_op_Multiply(Factor, Color); }
	friend TAlphaColorF operator /(const TAlphaColorF &Color, const float Factor) { return TAlphaColorF::_op_Division(Color, Factor); }
};


typedef int TImageIndex;

typedef System::UnicodeString TImageName;

enum class DECLSPEC_DENUM TScrollStyle : unsigned char { ssNone, ssHorizontal, ssVertical, ssBoth };

enum DECLSPEC_DENUM TTouchTrackingItem : unsigned char { ttVertical, ttHorizontal };

typedef System::Set<TTouchTrackingItem, TTouchTrackingItem::ttVertical, TTouchTrackingItem::ttHorizontal> TTouchTracking;

//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST TCursor crDefault = TCursor(0);
static _DELPHI_CONST TCursor crNone = TCursor(-1);
static _DELPHI_CONST TCursor crArrow = TCursor(-2);
static _DELPHI_CONST TCursor crCross = TCursor(-3);
static _DELPHI_CONST TCursor crIBeam = TCursor(-4);
static _DELPHI_CONST TCursor crSize = TCursor(-22);
static _DELPHI_CONST TCursor crSizeNESW = TCursor(-6);
static _DELPHI_CONST TCursor crSizeNS = TCursor(-7);
static _DELPHI_CONST TCursor crSizeNWSE = TCursor(-8);
static _DELPHI_CONST TCursor crSizeWE = TCursor(-9);
static _DELPHI_CONST TCursor crUpArrow = TCursor(-10);
static _DELPHI_CONST TCursor crHourGlass = TCursor(-11);
static _DELPHI_CONST TCursor crDrag = TCursor(-12);
static _DELPHI_CONST TCursor crNoDrop = TCursor(-13);
static _DELPHI_CONST TCursor crHSplit = TCursor(-14);
static _DELPHI_CONST TCursor crVSplit = TCursor(-15);
static _DELPHI_CONST TCursor crMultiDrag = TCursor(-16);
static _DELPHI_CONST TCursor crSQLWait = TCursor(-17);
static _DELPHI_CONST TCursor crNo = TCursor(-18);
static _DELPHI_CONST TCursor crAppStart = TCursor(-19);
static _DELPHI_CONST TCursor crHelp = TCursor(-20);
static _DELPHI_CONST TCursor crHandPoint = TCursor(-21);
static _DELPHI_CONST TCursor crSizeAll = TCursor(-22);
static _DELPHI_CONST System::Int8 idOK = System::Int8(0x1);
static _DELPHI_CONST System::Int8 idCancel = System::Int8(0x2);
static _DELPHI_CONST System::Int8 idAbort = System::Int8(0x3);
static _DELPHI_CONST System::Int8 idRetry = System::Int8(0x4);
static _DELPHI_CONST System::Int8 idIgnore = System::Int8(0x5);
static _DELPHI_CONST System::Int8 idYes = System::Int8(0x6);
static _DELPHI_CONST System::Int8 idNo = System::Int8(0x7);
static _DELPHI_CONST System::Int8 idClose = System::Int8(0x8);
static _DELPHI_CONST System::Int8 idHelp = System::Int8(0x9);
static _DELPHI_CONST System::Int8 idTryAgain = System::Int8(0xa);
static _DELPHI_CONST System::Int8 idContinue = System::Int8(0xb);
static _DELPHI_CONST System::Int8 mrNone = System::Int8(0x0);
static _DELPHI_CONST System::Int8 mrOk = System::Int8(0x1);
static _DELPHI_CONST System::Int8 mrCancel = System::Int8(0x2);
static _DELPHI_CONST System::Int8 mrAbort = System::Int8(0x3);
static _DELPHI_CONST System::Int8 mrRetry = System::Int8(0x4);
static _DELPHI_CONST System::Int8 mrIgnore = System::Int8(0x5);
static _DELPHI_CONST System::Int8 mrYes = System::Int8(0x6);
static _DELPHI_CONST System::Int8 mrNo = System::Int8(0x7);
static _DELPHI_CONST System::Int8 mrClose = System::Int8(0x8);
static _DELPHI_CONST System::Int8 mrHelp = System::Int8(0x9);
static _DELPHI_CONST System::Int8 mrTryAgain = System::Int8(0xa);
static _DELPHI_CONST System::Int8 mrContinue = System::Int8(0xb);
static _DELPHI_CONST System::Int8 mrAll = System::Int8(0xc);
static _DELPHI_CONST System::Int8 mrNoToAll = System::Int8(0xd);
static _DELPHI_CONST System::Int8 mrYesToAll = System::Int8(0xe);
static _DELPHI_CONST System::Int8 vkLButton = System::Int8(0x1);
static _DELPHI_CONST System::Int8 vkRButton = System::Int8(0x2);
static _DELPHI_CONST System::Int8 vkCancel = System::Int8(0x3);
static _DELPHI_CONST System::Int8 vkMButton = System::Int8(0x4);
static _DELPHI_CONST System::Int8 vkXButton1 = System::Int8(0x5);
static _DELPHI_CONST System::Int8 vkXButton2 = System::Int8(0x6);
static _DELPHI_CONST System::Int8 vkBack = System::Int8(0x8);
static _DELPHI_CONST System::Int8 vkTab = System::Int8(0x9);
static _DELPHI_CONST System::Int8 vkLineFeed = System::Int8(0xa);
static _DELPHI_CONST System::Int8 vkClear = System::Int8(0xc);
static _DELPHI_CONST System::Int8 vkReturn = System::Int8(0xd);
static _DELPHI_CONST System::Int8 vkShift = System::Int8(0x10);
static _DELPHI_CONST System::Int8 vkControl = System::Int8(0x11);
static _DELPHI_CONST System::Int8 vkMenu = System::Int8(0x12);
static _DELPHI_CONST System::Int8 vkPause = System::Int8(0x13);
static _DELPHI_CONST System::Int8 vkCapital = System::Int8(0x14);
static _DELPHI_CONST System::Int8 vkKana = System::Int8(0x15);
static _DELPHI_CONST System::Int8 vkHangul = System::Int8(0x15);
static _DELPHI_CONST System::Int8 vkJunja = System::Int8(0x17);
static _DELPHI_CONST System::Int8 vkFinal = System::Int8(0x18);
static _DELPHI_CONST System::Int8 vkHanja = System::Int8(0x19);
static _DELPHI_CONST System::Int8 vkKanji = System::Int8(0x19);
static _DELPHI_CONST System::Int8 vkConvert = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 vkNonConvert = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 vkAccept = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 vkModeChange = System::Int8(0x1f);
static _DELPHI_CONST System::Int8 vkEscape = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 vkSpace = System::Int8(0x20);
static _DELPHI_CONST System::Int8 vkPrior = System::Int8(0x21);
static _DELPHI_CONST System::Int8 vkNext = System::Int8(0x22);
static _DELPHI_CONST System::Int8 vkEnd = System::Int8(0x23);
static _DELPHI_CONST System::Int8 vkHome = System::Int8(0x24);
static _DELPHI_CONST System::Int8 vkLeft = System::Int8(0x25);
static _DELPHI_CONST System::Int8 vkUp = System::Int8(0x26);
static _DELPHI_CONST System::Int8 vkRight = System::Int8(0x27);
static _DELPHI_CONST System::Int8 vkDown = System::Int8(0x28);
static _DELPHI_CONST System::Int8 vkSelect = System::Int8(0x29);
static _DELPHI_CONST System::Int8 vkPrint = System::Int8(0x2a);
static _DELPHI_CONST System::Int8 vkExecute = System::Int8(0x2b);
static _DELPHI_CONST System::Int8 vkSnapshot = System::Int8(0x2c);
static _DELPHI_CONST System::Int8 vkInsert = System::Int8(0x2d);
static _DELPHI_CONST System::Int8 vkDelete = System::Int8(0x2e);
static _DELPHI_CONST System::Int8 vkHelp = System::Int8(0x2f);
static _DELPHI_CONST System::Int8 vk0 = System::Int8(0x30);
static _DELPHI_CONST System::Int8 vk1 = System::Int8(0x31);
static _DELPHI_CONST System::Int8 vk2 = System::Int8(0x32);
static _DELPHI_CONST System::Int8 vk3 = System::Int8(0x33);
static _DELPHI_CONST System::Int8 vk4 = System::Int8(0x34);
static _DELPHI_CONST System::Int8 vk5 = System::Int8(0x35);
static _DELPHI_CONST System::Int8 vk6 = System::Int8(0x36);
static _DELPHI_CONST System::Int8 vk7 = System::Int8(0x37);
static _DELPHI_CONST System::Int8 vk8 = System::Int8(0x38);
static _DELPHI_CONST System::Int8 vk9 = System::Int8(0x39);
static _DELPHI_CONST System::Int8 vkLCommand = System::Int8(0x3d);
static _DELPHI_CONST System::Int8 vkRCommand = System::Int8(0x3e);
static _DELPHI_CONST System::Int8 vkFunction = System::Int8(0x3f);
static _DELPHI_CONST System::Int8 vkA = System::Int8(0x41);
static _DELPHI_CONST System::Int8 vkB = System::Int8(0x42);
static _DELPHI_CONST System::Int8 vkC = System::Int8(0x43);
static _DELPHI_CONST System::Int8 vkD = System::Int8(0x44);
static _DELPHI_CONST System::Int8 vkE = System::Int8(0x45);
static _DELPHI_CONST System::Int8 vkF = System::Int8(0x46);
static _DELPHI_CONST System::Int8 vkG = System::Int8(0x47);
static _DELPHI_CONST System::Int8 vkH = System::Int8(0x48);
static _DELPHI_CONST System::Int8 vkI = System::Int8(0x49);
static _DELPHI_CONST System::Int8 vkJ = System::Int8(0x4a);
static _DELPHI_CONST System::Int8 vkK = System::Int8(0x4b);
static _DELPHI_CONST System::Int8 vkL = System::Int8(0x4c);
static _DELPHI_CONST System::Int8 vkM = System::Int8(0x4d);
static _DELPHI_CONST System::Int8 vkN = System::Int8(0x4e);
static _DELPHI_CONST System::Int8 vkO = System::Int8(0x4f);
static _DELPHI_CONST System::Int8 vkP = System::Int8(0x50);
static _DELPHI_CONST System::Int8 vkQ = System::Int8(0x51);
static _DELPHI_CONST System::Int8 vkR = System::Int8(0x52);
static _DELPHI_CONST System::Int8 vkS = System::Int8(0x53);
static _DELPHI_CONST System::Int8 vkT = System::Int8(0x54);
static _DELPHI_CONST System::Int8 vkU = System::Int8(0x55);
static _DELPHI_CONST System::Int8 vkV = System::Int8(0x56);
static _DELPHI_CONST System::Int8 vkW = System::Int8(0x57);
static _DELPHI_CONST System::Int8 vkX = System::Int8(0x58);
static _DELPHI_CONST System::Int8 vkY = System::Int8(0x59);
static _DELPHI_CONST System::Int8 vkZ = System::Int8(0x5a);
static _DELPHI_CONST System::Int8 vkLWin = System::Int8(0x5b);
static _DELPHI_CONST System::Int8 vkRWin = System::Int8(0x5c);
static _DELPHI_CONST System::Int8 vkApps = System::Int8(0x5d);
static _DELPHI_CONST System::Int8 vkSleep = System::Int8(0x5f);
static _DELPHI_CONST System::Int8 vkNumpad0 = System::Int8(0x60);
static _DELPHI_CONST System::Int8 vkNumpad1 = System::Int8(0x61);
static _DELPHI_CONST System::Int8 vkNumpad2 = System::Int8(0x62);
static _DELPHI_CONST System::Int8 vkNumpad3 = System::Int8(0x63);
static _DELPHI_CONST System::Int8 vkNumpad4 = System::Int8(0x64);
static _DELPHI_CONST System::Int8 vkNumpad5 = System::Int8(0x65);
static _DELPHI_CONST System::Int8 vkNumpad6 = System::Int8(0x66);
static _DELPHI_CONST System::Int8 vkNumpad7 = System::Int8(0x67);
static _DELPHI_CONST System::Int8 vkNumpad8 = System::Int8(0x68);
static _DELPHI_CONST System::Int8 vkNumpad9 = System::Int8(0x69);
static _DELPHI_CONST System::Int8 vkMultiply = System::Int8(0x6a);
static _DELPHI_CONST System::Int8 vkAdd = System::Int8(0x6b);
static _DELPHI_CONST System::Int8 vkSeparator = System::Int8(0x6c);
static _DELPHI_CONST System::Int8 vkSubtract = System::Int8(0x6d);
static _DELPHI_CONST System::Int8 vkDecimal = System::Int8(0x6e);
static _DELPHI_CONST System::Int8 vkDivide = System::Int8(0x6f);
static _DELPHI_CONST System::Int8 vkF1 = System::Int8(0x70);
static _DELPHI_CONST System::Int8 vkF2 = System::Int8(0x71);
static _DELPHI_CONST System::Int8 vkF3 = System::Int8(0x72);
static _DELPHI_CONST System::Int8 vkF4 = System::Int8(0x73);
static _DELPHI_CONST System::Int8 vkF5 = System::Int8(0x74);
static _DELPHI_CONST System::Int8 vkF6 = System::Int8(0x75);
static _DELPHI_CONST System::Int8 vkF7 = System::Int8(0x76);
static _DELPHI_CONST System::Int8 vkF8 = System::Int8(0x77);
static _DELPHI_CONST System::Int8 vkF9 = System::Int8(0x78);
static _DELPHI_CONST System::Int8 vkF10 = System::Int8(0x79);
static _DELPHI_CONST System::Int8 vkF11 = System::Int8(0x7a);
static _DELPHI_CONST System::Int8 vkF12 = System::Int8(0x7b);
static _DELPHI_CONST System::Int8 vkF13 = System::Int8(0x7c);
static _DELPHI_CONST System::Int8 vkF14 = System::Int8(0x7d);
static _DELPHI_CONST System::Int8 vkF15 = System::Int8(0x7e);
static _DELPHI_CONST System::Int8 vkF16 = System::Int8(0x7f);
static _DELPHI_CONST System::Byte vkF17 = System::Byte(0x80);
static _DELPHI_CONST System::Byte vkF18 = System::Byte(0x81);
static _DELPHI_CONST System::Byte vkF19 = System::Byte(0x82);
static _DELPHI_CONST System::Byte vkF20 = System::Byte(0x83);
static _DELPHI_CONST System::Byte vkF21 = System::Byte(0x84);
static _DELPHI_CONST System::Byte vkF22 = System::Byte(0x85);
static _DELPHI_CONST System::Byte vkF23 = System::Byte(0x86);
static _DELPHI_CONST System::Byte vkF24 = System::Byte(0x87);
static _DELPHI_CONST System::Byte vkCamera = System::Byte(0x88);
static _DELPHI_CONST System::Byte vkHardwareBack = System::Byte(0x89);
static _DELPHI_CONST System::Byte vkNumLock = System::Byte(0x90);
static _DELPHI_CONST System::Byte vkScroll = System::Byte(0x91);
static _DELPHI_CONST System::Byte vkLShift = System::Byte(0xa0);
static _DELPHI_CONST System::Byte vkRShift = System::Byte(0xa1);
static _DELPHI_CONST System::Byte vkLControl = System::Byte(0xa2);
static _DELPHI_CONST System::Byte vkRControl = System::Byte(0xa3);
static _DELPHI_CONST System::Byte vkLMenu = System::Byte(0xa4);
static _DELPHI_CONST System::Byte vkRMenu = System::Byte(0xa5);
static _DELPHI_CONST System::Byte vkBrowserBack = System::Byte(0xa6);
static _DELPHI_CONST System::Byte vkBrowserForward = System::Byte(0xa7);
static _DELPHI_CONST System::Byte vkBrowserRefresh = System::Byte(0xa8);
static _DELPHI_CONST System::Byte vkBrowserStop = System::Byte(0xa9);
static _DELPHI_CONST System::Byte vkBrowserSearch = System::Byte(0xaa);
static _DELPHI_CONST System::Byte vkBrowserFavorites = System::Byte(0xab);
static _DELPHI_CONST System::Byte vkBrowserHome = System::Byte(0xac);
static _DELPHI_CONST System::Byte vkVolumeMute = System::Byte(0xad);
static _DELPHI_CONST System::Byte vkVolumeDown = System::Byte(0xae);
static _DELPHI_CONST System::Byte vkVolumeUp = System::Byte(0xaf);
static _DELPHI_CONST System::Byte vkMediaNextTrack = System::Byte(0xb0);
static _DELPHI_CONST System::Byte vkMediaPrevTrack = System::Byte(0xb1);
static _DELPHI_CONST System::Byte vkMediaStop = System::Byte(0xb2);
static _DELPHI_CONST System::Byte vkMediaPlayPause = System::Byte(0xb3);
static _DELPHI_CONST System::Byte vkLaunchMail = System::Byte(0xb4);
static _DELPHI_CONST System::Byte vkLaunchMediaSelect = System::Byte(0xb5);
static _DELPHI_CONST System::Byte vkLaunchApp1 = System::Byte(0xb6);
static _DELPHI_CONST System::Byte vkLaunchApp2 = System::Byte(0xb7);
static _DELPHI_CONST System::Byte vkSemicolon = System::Byte(0xba);
static _DELPHI_CONST System::Byte vkEqual = System::Byte(0xbb);
static _DELPHI_CONST System::Byte vkComma = System::Byte(0xbc);
static _DELPHI_CONST System::Byte vkMinus = System::Byte(0xbd);
static _DELPHI_CONST System::Byte vkPeriod = System::Byte(0xbe);
static _DELPHI_CONST System::Byte vkSlash = System::Byte(0xbf);
static _DELPHI_CONST System::Byte vkTilde = System::Byte(0xc0);
static _DELPHI_CONST System::Byte vkLeftBracket = System::Byte(0xdb);
static _DELPHI_CONST System::Byte vkBackslash = System::Byte(0xdc);
static _DELPHI_CONST System::Byte vkRightBracket = System::Byte(0xdd);
static _DELPHI_CONST System::Byte vkQuote = System::Byte(0xde);
static _DELPHI_CONST System::Byte vkPara = System::Byte(0xdf);
static _DELPHI_CONST System::Byte vkOem102 = System::Byte(0xe2);
static _DELPHI_CONST System::Byte vkIcoHelp = System::Byte(0xe3);
static _DELPHI_CONST System::Byte vkIco00 = System::Byte(0xe4);
static _DELPHI_CONST System::Byte vkProcessKey = System::Byte(0xe5);
static _DELPHI_CONST System::Byte vkIcoClear = System::Byte(0xe6);
static _DELPHI_CONST System::Byte vkPacket = System::Byte(0xe7);
static _DELPHI_CONST System::Byte vkAttn = System::Byte(0xf6);
static _DELPHI_CONST System::Byte vkCrsel = System::Byte(0xf7);
static _DELPHI_CONST System::Byte vkExsel = System::Byte(0xf8);
static _DELPHI_CONST System::Byte vkErEof = System::Byte(0xf9);
static _DELPHI_CONST System::Byte vkPlay = System::Byte(0xfa);
static _DELPHI_CONST System::Byte vkZoom = System::Byte(0xfb);
static _DELPHI_CONST System::Byte vkNoname = System::Byte(0xfc);
static _DELPHI_CONST System::Byte vkPA1 = System::Byte(0xfd);
static _DELPHI_CONST System::Byte vkOemClear = System::Byte(0xfe);
static _DELPHI_CONST System::Byte vkNone = System::Byte(0xff);
static _DELPHI_CONST System::Int8 sgiNoGesture = System::Int8(0x0);
static _DELPHI_CONST System::Int8 sgiLeft = System::Int8(0x1);
static _DELPHI_CONST System::Int8 sgiRight = System::Int8(0x2);
static _DELPHI_CONST System::Int8 sgiUp = System::Int8(0x3);
static _DELPHI_CONST System::Int8 sgiDown = System::Int8(0x4);
static _DELPHI_CONST System::Int8 sgiUpLeft = System::Int8(0x5);
static _DELPHI_CONST System::Int8 sgiUpRight = System::Int8(0x6);
static _DELPHI_CONST System::Int8 sgiDownLeft = System::Int8(0x7);
static _DELPHI_CONST System::Int8 sgiDownRight = System::Int8(0x8);
static _DELPHI_CONST System::Int8 sgiLeftUp = System::Int8(0x9);
static _DELPHI_CONST System::Int8 sgiLeftDown = System::Int8(0xa);
static _DELPHI_CONST System::Int8 sgiRightUp = System::Int8(0xb);
static _DELPHI_CONST System::Int8 sgiRightDown = System::Int8(0xc);
static _DELPHI_CONST System::Int8 sgiUpDown = System::Int8(0xd);
static _DELPHI_CONST System::Int8 sgiDownUp = System::Int8(0xe);
static _DELPHI_CONST System::Int8 sgiLeftRight = System::Int8(0xf);
static _DELPHI_CONST System::Int8 sgiRightLeft = System::Int8(0x10);
static _DELPHI_CONST System::Int8 sgiUpLeftLong = System::Int8(0x11);
static _DELPHI_CONST System::Int8 sgiUpRightLong = System::Int8(0x12);
static _DELPHI_CONST System::Int8 sgiDownLeftLong = System::Int8(0x13);
static _DELPHI_CONST System::Int8 sgiDownRightLong = System::Int8(0x14);
static _DELPHI_CONST System::Int8 sgiScratchout = System::Int8(0x15);
static _DELPHI_CONST System::Int8 sgiTriangle = System::Int8(0x16);
static _DELPHI_CONST System::Int8 sgiSquare = System::Int8(0x17);
static _DELPHI_CONST System::Int8 sgiCheck = System::Int8(0x18);
static _DELPHI_CONST System::Int8 sgiCurlicue = System::Int8(0x19);
static _DELPHI_CONST System::Int8 sgiDoubleCurlicue = System::Int8(0x1a);
static _DELPHI_CONST System::Int8 sgiCircle = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 sgiDoubleCircle = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 sgiSemiCircleLeft = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 sgiSemiCircleRight = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 sgiChevronUp = System::Int8(0x1f);
static _DELPHI_CONST System::Int8 sgiChevronDown = System::Int8(0x20);
static _DELPHI_CONST System::Int8 sgiChevronLeft = System::Int8(0x21);
static _DELPHI_CONST System::Int8 sgiChevronRight = System::Int8(0x22);
static _DELPHI_CONST System::Int8 sgiFirst = System::Int8(0x1);
static _DELPHI_CONST System::Int8 sgiLast = System::Int8(0x22);
static _DELPHI_CONST short cgiFirst = short(-512);
static _DELPHI_CONST System::Int8 cgiLast = System::Int8(-1);
static _DELPHI_CONST short rgiFirst = short(-1024);
static _DELPHI_CONST short rgiLast = short(-513);
static _DELPHI_CONST System::Word igiFirst = System::Word(0x100);
static _DELPHI_CONST System::Word igiLast = System::Word(0x1ff);
static _DELPHI_CONST System::Word igiBegin = System::Word(0x101);
static _DELPHI_CONST System::Word igiEnd = System::Word(0x102);
static _DELPHI_CONST System::Word igiZoom = System::Word(0x103);
static _DELPHI_CONST System::Word igiPan = System::Word(0x104);
static _DELPHI_CONST System::Word igiRotate = System::Word(0x105);
static _DELPHI_CONST System::Word igiTwoFingerTap = System::Word(0x106);
static _DELPHI_CONST System::Word igiPressAndTap = System::Word(0x107);
static _DELPHI_CONST System::Word igiLongTap = System::Word(0x108);
static _DELPHI_CONST System::Word igiDoubleTap = System::Word(0x109);
extern DELPHI_PACKAGE bool __fastcall IsPositiveResult(const TModalResult AModalResult);
extern DELPHI_PACKAGE bool __fastcall IsNegativeResult(const TModalResult AModalResult);
extern DELPHI_PACKAGE bool __fastcall IsAbortResult(const TModalResult AModalResult);
extern DELPHI_PACKAGE bool __fastcall IsAnAllResult(const TModalResult AModalResult);
extern DELPHI_PACKAGE TModalResult __fastcall StripAllFromResult(const TModalResult AModalResult);
}	/* namespace Uitypes */
}	/* namespace System */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM_UITYPES)
using namespace System::Uitypes;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM)
using namespace System;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// System_UITypesHPP
