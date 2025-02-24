// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Winapi.Messages.pas' rev: 36.00 (Windows)

#ifndef Winapi_MessagesHPP
#define Winapi_MessagesHPP

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
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Winapi
{
namespace Messages
{
//-- forward type declarations -----------------------------------------------
struct TWordFiller;
#ifndef _WIN64
struct DECLSPEC_DRECORD TDWordFiller
{
};


#else /* _WIN64 */
struct TDWordFiller;
#endif /* _WIN64 */
struct TMessage;
struct TWMNoParams;
struct TWMKey;
struct TWMMouse;
struct TWMMouseWheel;
struct TMSHMouseWheel;
struct TWMWindowPosMsg;
struct TWMScroll;
struct TWMDpi;
struct TWMActivate;
struct TWMActivateApp;
struct TWMAskCBFormatName;
struct TWMChangeCBChain;
struct TWMCharToItem;
struct TWMChooseFont_GetLogFont;
struct TWMCommand;
struct TWMCompacting;
struct TWMCompareItem;
struct TWMCopyData;
struct TWMCreate;
struct TWMCtlColor;
struct TWMDDE_Ack;
struct TWMDDE_Advise;
struct TWMDDE_Data;
struct TWMDDE_Execute;
struct TWMDDE_Initiate;
struct TWMDDE_Poke;
struct TWMDDE_Request;
struct TWMDDE_Terminate;
struct TWMDDE_Unadvise;
struct TWMDeleteItem;
struct TWMDevModeChange;
struct TWMDrawItem;
struct TWMDropFiles;
struct TWMEnable;
struct TWMEndSession;
struct TWMEnterIdle;
struct TWMEnterMenuLoop;
struct TWMEraseBkgnd;
struct TWMGetIcon;
struct TWMGetMinMaxInfo;
struct TWMGetText;
struct TWMHotKey;
struct TWMHScrollClipboard;
struct TWMInitDialog;
struct TWMInitMenu;
struct TWMInitMenuPopup;
struct TWMKillFocus;
struct TWMMDIActivate;
struct TWMMDICascade;
struct TWMMDICreate;
struct TWMMDIDestroy;
struct TWMMDIMaximize;
struct TWMMDINext;
struct TWMMDIRestore;
struct TWMMDISetMenu;
struct TWMMDITile;
struct TWMMeasureItem;
struct TWMMenuChar;
struct TWMMenuSelect;
struct TWMMouseActivate;
struct TWMMove;
struct TWMMoving;
struct TWMNCActivate;
struct TWMNCCalcSize;
struct TWMNCCreate;
struct TWMNCHitTest;
struct TWMNCHitMessage;
struct TWMNCPaint;
struct TWMNextDlgCtl;
struct TWMNotify;
struct TWMNotifyFormat;
struct TWMPaint;
struct TWMPaintClipboard;
struct TWMPaletteChanged;
struct TWMPaletteIsChanging;
struct TWMParentNotify;
struct TWMPower;
struct TWMQueryEndSession;
struct TWMQuit;
struct TWMRenderFormat;
struct TWMSetCursor;
struct TWMSetFocus;
struct TWMSetFont;
struct TWMSetHotKey;
struct TWMSetIcon;
struct TWMSetRedraw;
struct TWMSetText;
struct TWMShowWindow;
struct TWMSize;
struct TWMSizeClipboard;
struct TWMSpoolerStatus;
struct TWMStyleChange;
struct TWMSysCommand;
struct TWMSysDeadChar;
struct TWMSystemError;
struct TWMTimer;
struct TWMUIState;
struct TWMVScrollClipboard;
struct TWMWinIniChange;
struct TWMSettingChange;
struct TWMHelp;
struct TWMDisplayChange;
struct TWMContextMenu;
struct TWMPrint;
struct TWMGestureNotify;
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TWordFiller
{
public:
#ifndef _WIN64
	System::StaticArray<System::Byte, 2> Filler;
#else /* _WIN64 */
	System::StaticArray<System::Byte, 6> Filler;
};


struct DECLSPEC_DRECORD TDWordFiller
{
public:
	System::StaticArray<System::Byte, 4> Filler;
#endif /* _WIN64 */
};


typedef TMessage *PMessage;

struct DECLSPEC_DRECORD TMessage
{
public:
	unsigned Msg;
	
public:
	union
	{
		struct 
		{
			System::Word WParamLo;
			System::Word WParamHi;
#ifdef _WIN64
			TDWordFiller WParamFiller;
#endif /* _WIN64 */
			System::Word LParamLo;
			System::Word LParamHi;
#ifdef _WIN64
			TDWordFiller LParamFiller;
#endif /* _WIN64 */
			System::Word ResultLo;
			System::Word ResultHi;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller ResultFiller;
#endif /* _WIN64 */
		};
		struct 
		{
#ifndef _WIN64
			unsigned WParam;
			int LParam;
			int Result;
#else /* _WIN64 */
			unsigned __int64 WParam;
			__int64 LParam;
			__int64 Result;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNoParams
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::StaticArray<System::Word, 4> Unused;
#ifndef _WIN64
	
	
	int Result;
#else /* _WIN64 */
	TDWordFiller UnusedFiller;
	TDWordFiller UnusedFiller2;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMKey
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word CharCode;
	System::Word Unused;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller CharCodeUnusedFiller;
#endif /* _WIN64 */
	System::LongInt KeyData;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller KeyDataFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMouse
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongInt Keys;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller KeysFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMMouseWheel
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	short Keys;
	short WheelDelta;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller KeysWhellFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TMSHMouseWheel
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	int WheelDelta;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller WheelDeltaFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMWindowPosMsg
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	int Unused;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller UnusedFiller;
#endif /* _WIN64 */
	Winapi::Windows::PWindowPos WindowPos;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMScroll
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	short ScrollCode;
	short Pos;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller ScrollCodePosFiller;
#endif /* _WIN64 */
	HWND ScrollBar;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDpi
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word YDpi;
	System::Word XDpi;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller WParamFiller;
#endif /* _WIN64 */
	Winapi::Windows::PRect ScaledRect;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMActivate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word Active;
	System::WordBool Minimized;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller ActiveMinimizedFiller;
#endif /* _WIN64 */
	HWND ActiveWindow;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMActivateApp
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool Active;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller ActiveFiller;
#endif /* _WIN64 */
	System::LongInt ThreadId;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller TheadIdFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMAskCBFormatName
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word NameLen;
	TWordFiller NameLenFiller;
	System::WideChar *FormatName;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMCancelMode;

struct DECLSPEC_DRECORD TWMChangeCBChain
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Remove;
	HWND Next;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMKey TWMChar;

struct DECLSPEC_DRECORD TWMCharToItem
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word Key;
	System::Word CaretPos;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller keyCaretPosFiller;
#endif /* _WIN64 */
	HWND ListBox;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMChildActivate;

struct DECLSPEC_DRECORD TWMChooseFont_GetLogFont
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongInt Unused;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller UnusedFiller;
#endif /* _WIN64 */
	Winapi::Windows::PLogFont LogFont;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMClear;

typedef TWMNoParams TWMClose;

struct DECLSPEC_DRECORD TWMCommand
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word ItemID;
	System::Word NotifyCode;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller ItemIDNotifyCodeFiller;
#endif /* _WIN64 */
	HWND Ctl;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMCompacting
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned CompactRatio;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 CompactRatio;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMCompareItem
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Ctl;
	Winapi::Windows::PCompareItemStruct CompareItemStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMCopy;

struct DECLSPEC_DRECORD TWMCopyData
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND From;
	Winapi::Windows::PCopyDataStruct CopyDataStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMCreate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	Winapi::Windows::PCreateStruct CreateStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMCtlColor
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HDC ChildDC;
	HWND ChildWnd;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMCtlColor TWMCtlColorBtn;

typedef TWMCtlColor TWMCtlColorDlg;

typedef TWMCtlColor TWMCtlColorEdit;

typedef TWMCtlColor TWMCtlColorListbox;

typedef TWMCtlColor TWMCtlColorMsgbox;

typedef TWMCtlColor TWMCtlColorScrollbar;

typedef TWMCtlColor TWMCtlColorStatic;

typedef TWMNoParams TWMCut;

struct DECLSPEC_DRECORD TWMDDE_Ack
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	
public:
	union
	{
		struct 
		{
			System::LongInt PackedVal;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller PackedValFiller;
#endif /* _WIN64 */
		};
		struct 
		{
			System::Word App;
			System::Word Topic;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller AppTopicFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMDDE_Advise
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::LongInt PackedVal;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller PackedValFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Data
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::LongInt PackedVal;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller PackedValFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Execute
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	Winapi::Windows::THandle Commands;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Initiate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::Word App;
	System::Word Topic;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller AppTopicFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Poke
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::LongInt PackedVal;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller PackedValFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Request
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::Word Format;
	System::Word Item;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller FormatItemFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Terminate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDDE_Unadvise
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PostingApp;
	System::Word Format;
	System::Word Item;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller FormatItemFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMKey TWMDeadChar;

struct DECLSPEC_DRECORD TWMDeleteItem
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Ctl;
	Winapi::Windows::PDeleteItemStruct DeleteItemStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMDestroy;

typedef TWMNoParams TWMDestroyClipboard;

struct DECLSPEC_DRECORD TWMDevModeChange
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	System::WideChar *Device;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMDrawClipboard;

struct DECLSPEC_DRECORD TWMDrawItem
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Ctl;
	Winapi::Windows::PDrawItemStruct DrawItemStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDropFiles
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	Winapi::Windows::THandle Drop;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMEnable
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool Enabled;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller EnabledFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMEndSession
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool EndSession;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller EndSessionFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMEnterIdle
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Source;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Source;
#endif /* _WIN64 */
	HWND IdleWnd;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMEnterMenuLoop
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool IsTrackPopupMenu;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller IsTrackPopupMenuFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMEnterMenuLoop TWMExitMenuLoop;

struct DECLSPEC_DRECORD TWMEraseBkgnd
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HDC DC;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMFontChange;

typedef TWMNoParams TWMGetDlgCode;

typedef TWMNoParams TWMGetFont;

struct DECLSPEC_DRECORD TWMGetIcon
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool BigIcon;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller BigIconFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMGetHotKey;

struct DECLSPEC_DRECORD TWMGetMinMaxInfo
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	Winapi::Windows::PMinMaxInfo MinMaxInfo;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMGetText
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned TextMax;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 TextMax;
#endif /* _WIN64 */
	System::WideChar *Text;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMGetTextLength;

struct DECLSPEC_DRECORD TWMHotKey
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned HotKey;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 HotKey;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMScroll TWMHScroll;

struct DECLSPEC_DRECORD TWMHScrollClipboard
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Viewer;
	System::Word ScrollCode;
	System::Word Pos;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller ScrollCodePosFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMEraseBkgnd TWMIconEraseBkgnd;

struct DECLSPEC_DRECORD TWMInitDialog
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Focus;
#ifndef _WIN64
	int InitParam;
	int Result;
#else /* _WIN64 */
	__int64 InitParam;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMInitMenu
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HMENU Menu;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMInitMenuPopup
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HMENU MenuPopup;
	short Pos;
	System::WordBool SystemMenu;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller PosSystemMenuFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMKey TWMKeyDown;

typedef TWMKey TWMKeyUp;

struct DECLSPEC_DRECORD TWMKillFocus
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND FocusedWnd;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMMouse TWMLButtonDblClk;

typedef TWMMouse TWMLButtonDown;

typedef TWMMouse TWMLButtonUp;

typedef TWMMouse TWMMButtonDblClk;

typedef TWMMouse TWMMButtonDown;

typedef TWMMouse TWMMButtonUp;

struct DECLSPEC_DRECORD TWMMDIActivate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			HWND DeactiveWnd;
			HWND ActiveWnd;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			HWND ChildWnd;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMMDICascade
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Cascade;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Cascade;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMDICreate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	Winapi::Windows::PMDICreateStruct MDICreateStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMDIDestroy
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Child;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMMDIGetActive;

typedef TWMNoParams TWMMDIIconArrange;

struct DECLSPEC_DRECORD TWMMDIMaximize
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Maximize;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMDINext
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Child;
#ifndef _WIN64
	int Next;
	int Result;
#else /* _WIN64 */
	__int64 Next;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMMDIRefreshMenu;

struct DECLSPEC_DRECORD TWMMDIRestore
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND IDChild;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMDISetMenu
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HMENU MenuFrame;
	HMENU MenuWindow;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMDITile
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Tile;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Tile;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMeasureItem
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND IDCtl;
	Winapi::Windows::PMeasureItemStruct MeasureItemStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMenuChar
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::WideChar User;
	System::Word MenuFlag;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller UserMenuFlagFiller;
#endif /* _WIN64 */
	HMENU Menu;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMenuSelect
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word IDItem;
	System::Word MenuFlag;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller IDItemMenuFlagFiller;
#endif /* _WIN64 */
	HMENU Menu;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMMouseActivate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND TopLevel;
	System::Word HitTestCode;
	System::Word MouseMsg;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller HitTestCodeMouseMsg;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMMouse TWMMouseMove;

struct DECLSPEC_DRECORD TWMMove
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMMoving
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Edge;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Edge;
#endif /* _WIN64 */
	Winapi::Windows::PRect DragRect;
};


struct DECLSPEC_DRECORD TWMNCActivate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool Active;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller ActiveFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMNCCalcSize
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool CalcValidRects;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller CalcValidRectsFiller;
#endif /* _WIN64 */
	Winapi::Windows::PNCCalcSizeParams CalcSize_Params;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMNCCreate
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	Winapi::Windows::PCreateStruct CreateStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMNCDestroy;

struct DECLSPEC_DRECORD TWMNCHitTest
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMNCHitMessage
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongInt HitTest;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller HitTestFiller;
#endif /* _WIN64 */
	short XCursor;
	short YCursor;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller XYCursorFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNCHitMessage TWMNCLButtonDblClk;

typedef TWMNCHitMessage TWMNCLButtonDown;

typedef TWMNCHitMessage TWMNCLButtonUp;

typedef TWMNCHitMessage TWMNCMButtonDblClk;

typedef TWMNCHitMessage TWMNCMButtonDown;

typedef TWMNCHitMessage TWMNCMButtonUp;

typedef TWMNCHitMessage TWMNCMouseMove;

struct DECLSPEC_DRECORD TWMNCPaint
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HRGN RGN;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNCHitMessage TWMNCRButtonDblClk;

typedef TWMNCHitMessage TWMNCRButtonDown;

typedef TWMNCHitMessage TWMNCRButtonUp;

struct DECLSPEC_DRECORD TWMNextDlgCtl
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned CtlFocus;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 CtlFocus;
#endif /* _WIN64 */
	System::WordBool Handle;
	TWordFiller HandleFiller;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMNotify
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned IDCtrl;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 IDCtrl;
#endif /* _WIN64 */
	Winapi::Windows::PNMHdr NMHdr;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMNotifyFormat
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND From;
#ifndef _WIN64
	int Command;
	int Result;
#else /* _WIN64 */
	__int64 Command;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMPaint
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HDC DC;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMPaintClipboard
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Viewer;
	Winapi::Windows::THandle PaintStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMPaintIcon;

struct DECLSPEC_DRECORD TWMPaletteChanged
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND PalChg;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMPaletteIsChanging
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Realize;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMParentNotify
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			System::Word Event;
			System::Word Value1;
#ifndef _WIN64
			int Value2;
			int Result;
#else /* _WIN64 */
			TDWordFiller EventValue1Filler;
			__int64 Value2;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			System::Word Unused2;
			System::Word Value;
#ifdef _WIN64
			TDWordFiller EventValueFiller;
#endif /* _WIN64 */
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		struct 
		{
			System::Word Unused1;
			System::Word ChildID;
#ifdef _WIN64
			TDWordFiller EventChildIDFiller;
#endif /* _WIN64 */
			HWND ChildWnd;
		};
		
	};
};


typedef TWMNoParams TWMPaste;

struct DECLSPEC_DRECORD TWMPower
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned PowerEvt;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 PowerEvt;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMQueryDragIcon;

struct DECLSPEC_DRECORD TWMQueryEndSession
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Source;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Source;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMNoParams TWMQueryNewPalette;

typedef TWMNoParams TWMQueryOpen;

typedef TWMNoParams TWMQueueSync;

struct DECLSPEC_DRECORD TWMQuit
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned ExitCode;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 ExitCode;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMMouse TWMRButtonDblClk;

typedef TWMMouse TWMRButtonDown;

typedef TWMMouse TWMRButtonUp;

typedef TWMNoParams TWMRenderAllFormats;

struct DECLSPEC_DRECORD TWMRenderFormat
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Format;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Format;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetCursor
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND CursorWnd;
	short HitTest;
	System::Word MouseMsg;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller HitTestMouseMsgFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetFocus
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND FocusedWnd;
#ifndef _WIN64
	int Unused;
	int Result;
#else /* _WIN64 */
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetFont
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HFONT Font;
	System::WordBool Redraw;
	TWordFiller RedrawFiller;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetHotKey
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongInt Key;
#ifndef _WIN64
	
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller KeyFiller;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetIcon
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool BigIcon;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller BigIconFiller;
#endif /* _WIN64 */
	HICON Icon;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetRedraw
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Redraw;
	int Unused;
	int Result;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Redraw;
	__int64 Unused;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSetText
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	System::WideChar *Text;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMShowWindow
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::LongBool Show;
#ifndef _WIN64
	
	int Status;
	int Result;
#else /* _WIN64 */
	TDWordFiller ShowFiller;
	__int64 Status;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSize
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned SizeType;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 SizeType;
#endif /* _WIN64 */
	System::Word Width;
	System::Word Height;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller WidthHeightFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSizeClipboard
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Viewer;
	Winapi::Windows::THandle RC;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSpoolerStatus
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned JobStatus;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 JobStatus;
#endif /* _WIN64 */
	System::Word JobsLeft;
	TWordFiller JobsLeftFiller;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMStyleChange
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned StyleType;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 StyleType;
#endif /* _WIN64 */
	Winapi::Windows::PStyleStruct StyleStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMStyleChange TWMStyleChanged;

typedef TWMStyleChange TWMStyleChanging;

typedef TWMKey TWMSysChar;

typedef TWMNoParams TWMSysColorChange;

struct DECLSPEC_DRECORD TWMSysCommand
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned CmdType;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 CmdType;
#endif /* _WIN64 */
	
public:
	union
	{
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			System::Word Key;
		};
		struct 
		{
			HWND ActivateWnd;
		};
		
	};
};


struct DECLSPEC_DRECORD TWMSysDeadChar
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word CharCode;
	TWordFiller CharCodeFiller;
	System::LongInt KeyData;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller KeyDataFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMKey TWMSysKeyDown;

typedef TWMKey TWMSysKeyUp;

struct DECLSPEC_DRECORD TWMSystemError
{
public:
	unsigned Msg;
	System::Word ErrSpec;
	System::LongInt Unused;
	System::LongInt Result;
};


typedef TWMNoParams TWMTimeChange;

struct DECLSPEC_DRECORD TWMTimer
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned TimerID;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 TimerID;
#endif /* _WIN64 */
	Winapi::Windows::TFarProc TimerProc;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMUIState
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	System::Word Action;
	System::Word Flags;
#ifndef _WIN64
	
	int Unused;
#else /* _WIN64 */
	TDWordFiller ActionFlagsFiller;
	__int64 Unused;
#endif /* _WIN64 */
};


typedef TWMUIState TWMChangeUIState;

typedef TWMUIState TWMUpdateUIState;

typedef TWMNoParams TWMQueryUIState;

typedef TWMNoParams TWMUndo;

typedef TWMCharToItem TWMVKeyToItem;

typedef TWMScroll TWMVScroll;

struct DECLSPEC_DRECORD TWMVScrollClipboard
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND Viewer;
	System::Word ScollCode;
	System::Word ThumbPos;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller ScrollCodeThumbPosFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMWindowPosMsg TWMWindowPosChanged;

typedef TWMWindowPosMsg TWMWindowPosChanging;

struct DECLSPEC_DRECORD TWMWinIniChange
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	System::WideChar *Section;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMSettingChange
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Flag;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Flag;
#endif /* _WIN64 */
	System::WideChar *Section;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMHelp
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	Winapi::Windows::PHelpInfo HelpInfo;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMDisplayChange
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned BitsPerPixel;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 BitsPerPixel;
#endif /* _WIN64 */
	System::Word Width;
	System::Word Height;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller WidthHeightFiller;
	__int64 Result;
#endif /* _WIN64 */
};


struct DECLSPEC_DRECORD TWMContextMenu
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HWND hWnd;
	
public:
	union
	{
		struct 
		{
			System::Types::TSmallPoint Pos;
#ifndef _WIN64
			int Result;
#else /* _WIN64 */
			TDWordFiller PosFiller;
			__int64 Result;
#endif /* _WIN64 */
		};
		struct 
		{
			short XPos;
			short YPos;
#ifndef _WIN64
			
#else /* _WIN64 */
			TDWordFiller XYPosFiller;
#endif /* _WIN64 */
		};
		
	};
};


struct DECLSPEC_DRECORD TWMPrint
{
public:
	unsigned Msg;
#ifndef _WIN64
	
#else /* _WIN64 */
	TDWordFiller MsgFiller;
#endif /* _WIN64 */
	HDC DC;
	unsigned Flags;
#ifndef _WIN64
	
	int Result;
#else /* _WIN64 */
	TDWordFiller FlagsFiller;
	__int64 Result;
#endif /* _WIN64 */
};


typedef TWMPrint TWMPrintClient;

struct DECLSPEC_DRECORD TWMGestureNotify
{
public:
	unsigned Msg;
#ifndef _WIN64
	
	unsigned Unused;
#else /* _WIN64 */
	TDWordFiller MsgFiller;
	unsigned __int64 Unused;
#endif /* _WIN64 */
	GESTURENOTIFYSTRUCT *NotifyStruct;
#ifndef _WIN64
	int Result;
#else /* _WIN64 */
	__int64 Result;
#endif /* _WIN64 */
};


//-- var, const, procedure ---------------------------------------------------
#ifndef _WIN64
extern DELPHI_PACKAGE int __fastcall SendTextMessage(HWND Handle, unsigned Msg, unsigned WParam, System::UnicodeString LParam)/* overload */;
extern DELPHI_PACKAGE int __fastcall SendStructMessage(HWND Handle, unsigned Msg, unsigned WParam, const void *LParam);
extern DELPHI_PACKAGE int __fastcall SendGetStructMessage(HWND Handle, unsigned Msg, unsigned WParam, void *LParam, bool Unused = false);
extern DELPHI_PACKAGE int __fastcall SendGetIntMessage(HWND Handle, unsigned Msg, int &WParam, int &LParam);
#else /* _WIN64 */
extern DELPHI_PACKAGE __int64 __fastcall SendTextMessage(HWND Handle, unsigned Msg, unsigned __int64 WParam, System::UnicodeString LParam)/* overload */;
extern DELPHI_PACKAGE __int64 __fastcall SendStructMessage(HWND Handle, unsigned Msg, unsigned __int64 WParam, const void *LParam);
extern DELPHI_PACKAGE __int64 __fastcall SendGetStructMessage(HWND Handle, unsigned Msg, unsigned __int64 WParam, void *LParam, bool Unused = false);
extern DELPHI_PACKAGE __int64 __fastcall SendGetIntMessage(HWND Handle, unsigned Msg, int &WParam, int &LParam);
#endif /* _WIN64 */
}	/* namespace Messages */
}	/* namespace Winapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI_MESSAGES)
using namespace Winapi::Messages;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_WINAPI)
using namespace Winapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Winapi_MessagesHPP
