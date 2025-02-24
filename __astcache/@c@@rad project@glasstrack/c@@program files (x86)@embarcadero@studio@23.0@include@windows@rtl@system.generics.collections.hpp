// CodeGear C++Builder
// Copyright (c) 1995, 2024 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'System.Generics.Collections.pas' rev: 36.00 (Windows)

#ifndef System_Generics_CollectionsHPP
#define System_Generics_CollectionsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Types.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Defaults.hpp>

//-- user supplied -----------------------------------------------------------

namespace System
{
namespace Generics
{
namespace Collections
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TArray;
template<typename T> class DELPHICLASS TEnumerator__1;
template<typename T> class DELPHICLASS TEnumerable__1;
struct TListHelper;
template<typename T> class DELPHICLASS TList__1;
template<typename T> class DELPHICLASS TThreadList__1;
struct TQueueHelper;
template<typename T> class DELPHICLASS TQueue__1;
struct TStackHelper;
template<typename T> class DELPHICLASS TStack__1;
template<typename K, typename V> struct TPair__2;
template<typename K, typename V> class DELPHICLASS TDictionary__2;
template<typename K, typename V> class DELPHICLASS TOrderedDictionary__2;
template<typename T> class DELPHICLASS THashSet__1;
template<typename T> class DELPHICLASS TObjectList__1;
template<typename T> class DELPHICLASS TObjectQueue__1;
template<typename T> class DELPHICLASS TObjectStack__1;
template<typename K, typename V> class DELPHICLASS TObjectDictionary__2;
template<typename K, typename V> class DELPHICLASS TObjectOrderedDictionary__2;
template<typename T> class DELPHICLASS TObjectHashSet__1;
template<typename T> class DELPHICLASS TThreadedQueue__1;
//-- type declarations -------------------------------------------------------
#ifndef _WIN64
#pragma pack(push,4)
#endif /* not _WIN64 */
class PASCALIMPLEMENTATION TArray : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	template<typename T> static bool __fastcall DoBinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ System::NativeInt &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Index, System::NativeInt Count);
	template<typename T> static void __fastcall QuickSort(T *Values, const System::NativeInt Values_High, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt L, System::NativeInt R);
	static void __fastcall CheckArrays(void * Source, void * Destination, System::NativeInt SourceIndex, System::NativeInt SourceLength, System::NativeInt DestIndex, System::NativeInt DestLength, System::NativeInt Count);
	template<typename T> static int __fastcall InternalCompare(System::TObject* ASelf, const void *ALeft, const void *ARight);
	template<typename T> static System::NativeInt __fastcall DoIndexOf(const T *Values, const System::NativeInt Values_High, const T Item, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Base, System::NativeInt Count, System::Types::TDirection Direction);
	static void __fastcall DoFreeValues(void * P, System::NativeInt len, void * elTypeInfo);
#ifdef _WIN64
	static void __fastcall RangeInt32Error(System::NativeInt AIndex);
#endif /* _WIN64 */
	
public:
	template<typename T> static void __fastcall Sort(T *Values, const System::NativeInt Values_High)/* overload */;
	template<typename T> static void __fastcall Sort(T *Values, const System::NativeInt Values_High, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer)/* overload */;
	template<typename T> static void __fastcall Sort(T *Values, const System::NativeInt Values_High, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ System::NativeInt &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ System::NativeInt &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer)/* overload */;
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ System::NativeInt &FoundIndex)/* overload */;
#ifdef _WIN64
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ int &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, int Index, int Count)/* overload */;
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ int &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer)/* overload */;
	template<typename T> static bool __fastcall BinarySearch(const T *Values, const System::NativeInt Values_High, const T Item, /* out */ int &FoundIndex)/* overload */;
#endif /* _WIN64 */
	template<typename T> static void __fastcall Copy(const T *Source, const System::NativeInt Source_High, T *Destination, const System::NativeInt Destination_High, System::NativeInt SourceIndex, System::NativeInt DestIndex, System::NativeInt Count)/* overload */;
	template<typename T> static void __fastcall Copy(const T *Source, const System::NativeInt Source_High, T *Destination, const System::NativeInt Destination_High, System::NativeInt Count)/* overload */;
	template<typename T> static System::DynamicArray<T> __fastcall Concat(const System::DynamicArray<T> *Args, const System::NativeInt Args_High);
	template<typename T> static System::NativeInt __fastcall IndexOf(const T *Values, const System::NativeInt Values_High, const T Item)/* overload */;
	template<typename T> static System::NativeInt __fastcall IndexOf(const T *Values, const System::NativeInt Values_High, const T Item, System::NativeInt Index)/* overload */;
	template<typename T> static System::NativeInt __fastcall IndexOf(const T *Values, const System::NativeInt Values_High, const T Item, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
	template<typename T> static System::NativeInt __fastcall LastIndexOf(const T *Values, const System::NativeInt Values_High, const T Item)/* overload */;
	template<typename T> static System::NativeInt __fastcall LastIndexOf(const T *Values, const System::NativeInt Values_High, const T Item, System::NativeInt Index)/* overload */;
	template<typename T> static System::NativeInt __fastcall LastIndexOf(const T *Values, const System::NativeInt Values_High, const T Item, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
	template<typename T> static bool __fastcall Contains(const T *Values, const System::NativeInt Values_High, const T Item)/* overload */;
	template<typename T> static bool __fastcall Contains(const T *Values, const System::NativeInt Values_High, const T Item, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer)/* overload */;
	template<typename T> static void __fastcall FreeValues(const T *Values, const System::NativeInt Values_High)/* overload */;
	template<typename T> static void __fastcall FreeValues(System::DynamicArray<T> &Values)/* overload */;
	template<typename T> static System::UnicodeString __fastcall ToString(const T *Values, const System::NativeInt Values_High, const System::Sysutils::TFormatSettings &AFormatSettings, const System::UnicodeString ASeparator = L",", const System::UnicodeString ADelim1 = System::UnicodeString(), const System::UnicodeString ADelim2 = System::UnicodeString())/* overload */;
	template<typename T> static System::UnicodeString __fastcall ToString(const T *Values, const System::NativeInt Values_High, const System::UnicodeString ASeparator = L",", const System::UnicodeString ADelim1 = System::UnicodeString(), const System::UnicodeString ADelim2 = System::UnicodeString())/* overload */;
public:
	/* TObject.Create */ inline __fastcall TArray() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TArray() { }
	
};

#ifndef _WIN64
#pragma pack(pop)
#endif /* not _WIN64 */

enum DECLSPEC_DENUM TCollectionNotification : unsigned char { cnAdding, cnAdded, cnExtracting, cnExtracted, cnDeleting, cnRemoved };

/* [Template Alias] */
#if defined(__clang__)
template<typename T> using TCollectionNotifyEvent__1 = void __fastcall (__closure *)(System::TObject* Sender, const T Item, TCollectionNotification Action);
#endif

#ifndef _WIN64
#pragma pack(push,4)
#endif /* not _WIN64 */
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TEnumerator__1 : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual T __fastcall DoGetCurrent() = 0 ;
	virtual bool __fastcall DoMoveNext() = 0 ;
	
public:
	__property T Current = {read=DoGetCurrent};
	bool __fastcall MoveNext();
public:
	/* TObject.Create */ inline __fastcall TEnumerator__1() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TEnumerator__1() { }
	
};

#ifndef _WIN64
#pragma pack(pop)
#endif /* not _WIN64 */

#ifndef _WIN64
#pragma pack(push,4)
#endif /* not _WIN64 */
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TEnumerable__1 : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::DynamicArray<T> __fastcall ToArrayImpl(System::NativeInt Count);
	virtual TEnumerator__1<T>* __fastcall DoGetEnumerator() = 0 ;
	
public:
	__fastcall virtual ~TEnumerable__1();
	TEnumerator__1<T>* __fastcall GetEnumerator();
	virtual System::DynamicArray<T> __fastcall ToArray();
public:
	/* TObject.Create */ inline __fastcall TEnumerable__1() : System::TObject() { }
	
};

#ifndef _WIN64
#pragma pack(pop)
#endif /* not _WIN64 */

typedef TListHelper *PListHelper;

struct DECLSPEC_DRECORD TListHelper
{
	template <typename T> friend class DELPHICLASS TList__1;
	template <typename T> friend class DELPHICLASS TStack__1;
	template <typename T> friend class DELPHICLASS TQueue__1;
	
	
private:
	typedef void __fastcall (*TInternalNotifyProc)(System::TObject* ASelf, const void *AItem, TCollectionNotification AAction);
	
	typedef int __fastcall (*TInternalCompareFunc)(System::TObject* ASelf, const void *ALeft, const void *ARight);
	
	__interface DELPHIINTERFACE TInternalEmptyFunc;
	typedef System::DelphiInterface<TInternalEmptyFunc> _di_TInternalEmptyFunc;
	__interface TInternalEmptyFunc  : public System::IInterface 
	{
		virtual bool __fastcall Invoke(const void *Item) = 0 ;
	};
	
	typedef System::DynamicArray<System::Byte> *PBytes;
	
	
private:
	void *FItems;
	System::NativeInt FCount;
	void *FTypeInfo;
	System::TObject* FListObj;
	TInternalNotifyProc FNotify;
	TInternalCompareFunc FCompare;
	void * __fastcall GetElType();
	System::NativeInt __fastcall GetElSize();
	bool __fastcall CheckDeleteRange(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall CheckItemRange(System::NativeInt AIndex);
	void __fastcall CheckInsertRange(System::NativeInt AIndex);
	System::NativeInt __fastcall DoIndexOfFwd1(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd2(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd4(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd8(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwdN(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwdMRef(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwdString(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd1UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd2UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd4UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwd8UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwdMRefUsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfFwdStringUsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev1(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev2(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev4(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev8(const void *Value);
	System::NativeInt __fastcall DoIndexOfRevN(const void *Value);
	System::NativeInt __fastcall DoIndexOfRevMRef(const void *Value);
	System::NativeInt __fastcall DoIndexOfRevString(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev1UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev2UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev4UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRev8UsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRevMRefUsingComparer(const void *Value);
	System::NativeInt __fastcall DoIndexOfRevStringUsingComparer(const void *Value);
	void __fastcall DoExtractItemFwd1(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwd2(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwd4(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwd8(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdN(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdInterface(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdVariant(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdByteString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdWideString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdManaged(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemFwdWeak(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRev1(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRev2(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRev4(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRev8(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevN(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevInterface(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevVariant(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevByteString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevWideString(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevManaged(const void *Value, /* out */ void *Item);
	void __fastcall DoExtractItemRevWeak(const void *Value, /* out */ void *Item);
	void __fastcall DoExchangeStringInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeInterfaceInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeVariantInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeDynArrayInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeByteStringInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeWideStringInline(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeString(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeInterface(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeVariant(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeDynArray(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeByteString(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall DoExchangeWideString(System::NativeInt Index1, System::NativeInt Index2);
	System::NativeInt __fastcall DoRemoveFwd1(const void *Value);
	System::NativeInt __fastcall DoRemoveFwd2(const void *Value);
	System::NativeInt __fastcall DoRemoveFwd4(const void *Value);
	System::NativeInt __fastcall DoRemoveFwd8(const void *Value);
	System::NativeInt __fastcall DoRemoveFwdN(const void *Value);
	System::NativeInt __fastcall DoRemoveFwdMRef(const void *Value);
	System::NativeInt __fastcall DoRemoveFwdString(const void *Value);
	System::NativeInt __fastcall DoRemoveFwdManaged(const void *Value);
	System::NativeInt __fastcall DoRemoveFwdWeak(const void *Value);
	System::NativeInt __fastcall DoRemoveRev1(const void *Value);
	System::NativeInt __fastcall DoRemoveRev2(const void *Value);
	System::NativeInt __fastcall DoRemoveRev4(const void *Value);
	System::NativeInt __fastcall DoRemoveRev8(const void *Value);
	System::NativeInt __fastcall DoRemoveRevN(const void *Value);
	System::NativeInt __fastcall DoRemoveRevMRef(const void *Value);
	System::NativeInt __fastcall DoRemoveRevString(const void *Value);
	System::NativeInt __fastcall DoRemoveRevManaged(const void *Value);
	System::NativeInt __fastcall DoRemoveRevWeak(const void *Value);
	void __fastcall SetItem1(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItem2(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItem4(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItem8(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItemManaged(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItemN(const void *Value, System::NativeInt AIndex);
	void __fastcall DoInsertByteString(System::NativeInt AIndex, const void *Value);
	void __fastcall DoSetItemByteString(const void *Value, System::NativeInt AIndex);
	System::NativeInt __fastcall DoAddByteString(const void *Value);
	void __fastcall DoInsertWideString(System::NativeInt AIndex, const void *Value);
	void __fastcall DoSetItemWideString(const void *Value, System::NativeInt AIndex);
	System::NativeInt __fastcall DoAddWideString(const void *Value);
	void __fastcall DoInsertInterface(System::NativeInt AIndex, const void *Value);
	void __fastcall DoSetItemInterface(const void *Value, System::NativeInt AIndex);
	void __fastcall DoInsertString(System::NativeInt AIndex, const void *Value);
	void __fastcall DoSetItemString(const void *Value, System::NativeInt AIndex);
	void __fastcall DoInsertDynArray(System::NativeInt AIndex, const void *Value);
	void __fastcall DoSetItemDynArray(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItemVariant(const void *Value, System::NativeInt AIndex);
	void __fastcall SetItemMRef(const void *Value, System::NativeInt AIndex, System::TTypeKind TypeKind);
	System::NativeInt __fastcall DoAddInterface(const void *Value);
	System::NativeInt __fastcall DoAddString(const void *Value);
	System::NativeInt __fastcall DoAddDynArray(const void *Value);
	void __fastcall DoReverseMRef(System::TTypeKind Kind);
	void __fastcall DoReverseString();
	void __fastcall DoReverseInterface();
	void __fastcall DoReverseVariant();
	void __fastcall DoReverseDynArray();
	void __fastcall DoReverseByteString();
	void __fastcall DoReverseWideString();
	System::NativeInt __fastcall InternalAdd1(const void *Value);
	System::NativeInt __fastcall InternalAdd2(const void *Value);
	System::NativeInt __fastcall InternalAdd4(const void *Value);
	System::NativeInt __fastcall InternalAdd8(const void *Value);
	System::NativeInt __fastcall InternalAddN(const void *Value);
	System::NativeInt __fastcall InternalAddVariant(const void *Value);
	System::NativeInt __fastcall InternalAddMRef(const void *Value, System::TTypeKind TypeKind);
	System::NativeInt __fastcall InternalAddManaged(const void *Value);
	void __fastcall InternalGrow(System::NativeInt ANewCount);
	void __fastcall InternalGrowCheck(System::NativeInt ANewCount);
	void __fastcall InternalDeleteRange1(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRange2(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRange4(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRange8(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRangeN(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRangeMRef(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRangeManaged(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDeleteRangeWeak(System::NativeInt AIndex, System::NativeInt ACount);
	void __fastcall InternalDoDelete1(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDelete2(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDelete4(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDelete8(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDeleteN(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDeleteMRef(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDeleteManaged(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalDoDeleteWeak(System::NativeInt AIndex, TCollectionNotification Action);
	void __fastcall InternalSetCapacity(System::NativeInt Value);
	void __fastcall InternalSetCount1(System::NativeInt Value);
	void __fastcall InternalSetCount2(System::NativeInt Value);
	void __fastcall InternalSetCount4(System::NativeInt Value);
	void __fastcall InternalSetCount8(System::NativeInt Value);
	void __fastcall InternalSetCountN(System::NativeInt Value);
	void __fastcall InternalSetCountMRef(System::NativeInt Value);
	void __fastcall InternalSetCountManaged(System::NativeInt Value);
	void __fastcall InternalSetCountWeak(System::NativeInt Value);
	void __fastcall InternalClear1();
	void __fastcall InternalClear2();
	void __fastcall InternalClear4();
	void __fastcall InternalClear8();
	void __fastcall InternalClearN();
	void __fastcall InternalClearMRef();
	void __fastcall InternalClearManaged();
	void __fastcall InternalClearWeak();
	void __fastcall InternalInsert1(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsert2(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsert4(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsert8(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsertN(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsertVariant(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsertMRef(System::NativeInt AIndex, const void *Value, System::TTypeKind TypeKind);
	void __fastcall InternalInsertManaged(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsertWeak(System::NativeInt AIndex, const void *Value);
	void __fastcall InternalInsertRange1(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRange2(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRange4(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRange8(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRangeN(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRangeManaged(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	void __fastcall InternalInsertRangeWeak(System::NativeInt AIndex, void * Values, System::NativeInt ACount);
	System::NativeInt __fastcall InternalIndexOf1(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOf2(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOf4(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOf8(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOfN(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOfMRef(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalIndexOfString(const void *Value, System::Byte Direction);
	void __fastcall InternalExtractItem1(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItem2(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItem4(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItem8(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItemN(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItemMRef(const void *Value, System::TTypeKind Kind, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItemVariant(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItemManaged(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExtractItemWeak(const void *Value, /* out */ void *Item, System::Byte Direction);
	void __fastcall InternalExchange1(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalExchange2(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalExchange4(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalExchange8(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalExchangeN(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalExchangeMRef(System::NativeInt Index1, System::NativeInt Index2, System::TTypeKind Kind);
	void __fastcall InternalExchangeManaged(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall InternalMove1(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMove2(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMove4(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMove8(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMoveN(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMoveMRef(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalMoveManaged(System::NativeInt CurIndex, System::NativeInt NewIndex);
	void __fastcall InternalPackInline(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPack1(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPack2(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPack4(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPack8(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPackN(const _di_TInternalEmptyFunc IsEmpty);
	void __fastcall InternalPackManaged(const _di_TInternalEmptyFunc IsEmpty);
	System::NativeInt __fastcall InternalRemove1(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemove2(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemove4(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemove8(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemoveN(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemoveMRef(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemoveString(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemoveManaged(const void *Value, System::Byte Direction);
	System::NativeInt __fastcall InternalRemoveWeak(const void *Value, System::Byte Direction);
	void __fastcall InternalReverse1();
	void __fastcall InternalReverse2();
	void __fastcall InternalReverse4();
	void __fastcall InternalReverse8();
	void __fastcall InternalReverseN();
	void __fastcall InternalReverseMRef(System::TTypeKind Kind);
	void __fastcall InternalReverseManaged();
	void __fastcall InternalToArray(void * &Dest);
	void __fastcall InternalToArrayManaged(void * &Dest);
	__property void * ElType = {read=GetElType};
	__property System::NativeInt ElSize = {read=GetElSize};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TList__1 : public TEnumerable__1<T>
{
	typedef TEnumerable__1<T> inherited;
	
	
public:
	typedef System::DynamicArray<T> arrayofT;
	
	typedef System::DynamicArray<T> *ParrayofT;
	
	typedef System::Types::TDirection TDirection;
	__interface DELPHIINTERFACE TEmptyFunc;
	typedef System::DelphiInterface<TEmptyFunc> _di_TEmptyFunc;
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	__interface TEmptyFunc  : public System::IInterface 
	{
		virtual bool __fastcall Invoke(const T L, const T R) = 0 ;
	};
	
	class DELPHICLASS TEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TEnumerator : public TEnumerator__1<T>
	{
		typedef TEnumerator__1<T> inherited;
		
	private:
		TList__1<T>* FList;
		System::NativeInt FIndex;
		T __fastcall GetCurrent();
		
	protected:
		virtual T __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TEnumerator(TList__1<T>* const AList);
		HIDESBASE bool __fastcall MoveNext();
		__property T Current = {read=GetCurrent};
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	
public:
	T operator[](System::NativeInt Index) { return this->Items[Index]; }
	
private:
	System::DynamicArray<T> FItems;
	System::NativeInt FCount;
	void *FTypeInfo;
	System::TObject* FListObj;
	TListHelper::TInternalNotifyProc FNotify;
	TListHelper::TInternalCompareFunc FCompare;
	System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > FComparer;
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_1)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_1 FOnNotify;
	PListHelper __fastcall FListHelper();
	System::DynamicArray<T> __fastcall GetList();
	ParrayofT __fastcall GetPList();
	System::NativeInt __fastcall GetCapacity();
	void __fastcall SetCapacity(System::NativeInt Value)/* overload */;
	void __fastcall SetCount(System::NativeInt Value);
	bool __fastcall GetIsEmpty();
	void __fastcall CheckItemRange(System::NativeInt AIndex);
	T __fastcall GetItem(System::NativeInt Index);
	void __fastcall SetItem(System::NativeInt Index, const T Value);
	void __fastcall GrowCheck(System::NativeInt ACount);
	void __fastcall DoDelete(System::NativeInt Index, TCollectionNotification Notification);
	void __fastcall InternalNotify(const void *Item, TCollectionNotification Action);
	void __fastcall UpdateNotify();
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_2)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	void __fastcall SetOnNotify(const _dt_System_Generics_Collections_2 Value);
	int __fastcall InternalCompare(const void *Left, const void *Right);
	void __fastcall UpdateComparer(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer);
	
protected:
	System::NativeInt __fastcall ItemValue(const T Item);
	virtual TEnumerator__1<T>* __fastcall DoGetEnumerator();
	virtual void __fastcall Notify(const T Item, TCollectionNotification Action);
	
public:
	__fastcall TList__1()/* overload */;
	__fastcall TList__1(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	__fastcall TList__1(TEnumerable__1<T>* const Collection)/* overload */;
	__fastcall TList__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	__fastcall TList__1(const T *Values, const System::NativeInt Values_High)/* overload */;
	__fastcall virtual ~TList__1();
	__classmethod virtual void __fastcall Error(const System::UnicodeString Msg, System::NativeInt Data)/* overload */;
	__classmethod void __fastcall Error(System::PResStringRec Msg, System::NativeInt Data)/* overload */;
	System::NativeInt __fastcall Add(const T Value);
	void __fastcall AddRange(const T *Values, const System::NativeInt Values_High)/* overload */;
	void __fastcall AddRange(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	void __fastcall AddRange(TEnumerable__1<T>* const Collection)/* overload */;
	void __fastcall Insert(System::NativeInt Index, const T Value);
	void __fastcall InsertRange(System::NativeInt Index, const T *Values, const System::NativeInt Values_High, System::NativeInt Count)/* overload */;
	void __fastcall InsertRange(System::NativeInt Index, const T *Values, const System::NativeInt Values_High)/* overload */;
	void __fastcall InsertRange(System::NativeInt Index, const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	void __fastcall InsertRange(System::NativeInt Index, TEnumerable__1<T>* const Collection)/* overload */;
	void __fastcall Pack()/* overload */;
	void __fastcall Pack(const _di_TEmptyFunc IsEmpty)/* overload */;
	System::NativeInt __fastcall Remove(const T Value);
	System::NativeInt __fastcall RemoveItem(const T Value, System::Types::TDirection Direction);
	void __fastcall Delete(System::NativeInt Index);
	void __fastcall DeleteRange(System::NativeInt AIndex, System::NativeInt ACount);
	T __fastcall ExtractItem(const T Value, System::Types::TDirection Direction);
	T __fastcall Extract(const T Value);
	T __fastcall ExtractAt(System::NativeInt Index);
	void __fastcall Exchange(System::NativeInt Index1, System::NativeInt Index2);
	void __fastcall Move(System::NativeInt CurIndex, System::NativeInt NewIndex);
	T __fastcall First();
	T __fastcall Last();
	void __fastcall Clear();
	TList__1<T>* __fastcall Expand();
	bool __fastcall Contains(const T Value);
	System::NativeInt __fastcall IndexOf(const T Value);
	System::NativeInt __fastcall IndexOfItem(const T Value, System::Types::TDirection Direction);
	System::NativeInt __fastcall LastIndexOf(const T Value);
	void __fastcall Reverse();
	void __fastcall Sort()/* overload */;
	void __fastcall Sort(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	void __fastcall Sort(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ System::NativeInt &FoundIndex)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ System::NativeInt &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ System::NativeInt &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer, System::NativeInt Index, System::NativeInt Count)/* overload */;
#ifdef _WIN64
	bool __fastcall BinarySearch(const T Item, /* out */ int &FoundIndex)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ int &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */;
	bool __fastcall BinarySearch(const T Item, /* out */ int &FoundIndex, const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer, int Index, int Count)/* overload */;
#endif /* _WIN64 */
	void __fastcall TrimExcess();
	virtual System::DynamicArray<T> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property System::NativeInt Count = {read=FCount, write=SetCount, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity};
	__property System::NativeInt Count = {read=FCount, write=SetCount};
#endif /* _WIN64 */
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property T Items[System::NativeInt Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::DynamicArray<T> List = {read=GetList};
	__property ParrayofT PList = {read=GetPList};
	__property System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > Comparer = {read=FComparer};
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_3)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_3 OnNotify = {read=FOnNotify, write=SetOnNotify};
	HIDESBASE TEnumerator* __fastcall GetEnumerator();
};


#ifndef _WIN64
#pragma pack(push,4)
#endif /* not _WIN64 */
// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TThreadList__1 : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TList__1<T>* FList;
	System::TObject* FLock;
	System::Types::TDuplicates FDuplicates;
	
public:
	__fastcall TThreadList__1();
	__fastcall virtual ~TThreadList__1();
	void __fastcall Add(const T Item);
	void __fastcall Clear();
	TList__1<T>* __fastcall LockList();
	void __fastcall Remove(const T Item);
	void __fastcall RemoveItem(const T Item, System::Types::TDirection Direction);
	void __fastcall UnlockList();
	__property System::Types::TDuplicates Duplicates = {read=FDuplicates, write=FDuplicates, nodefault};
};

#ifndef _WIN64
#pragma pack(pop)
#endif /* not _WIN64 */

typedef TQueueHelper *PQueueHelper;

struct DECLSPEC_DRECORD TQueueHelper
{
private:
	System::NativeInt FHead;
	System::NativeInt FTail;
	TListHelper FLH;
	void __fastcall DynArraySetLength(System::NativeInt Value);
	void * __fastcall GetElType();
	System::NativeInt __fastcall GetElSize();
	System::NativeInt __fastcall GetNewCap();
	void __fastcall CheckEmpty();
	void __fastcall DequeueAdjust(TCollectionNotification Notification, const void *Item);
	void __fastcall InternalDequeueString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueInterface(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueDynArray(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueByteString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueWideString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeue1(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeue2(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeue4(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeue8(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueN(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDequeueMRef(TCollectionNotification Notification, bool Peek, /* out */ void *Item, System::TTypeKind Kind);
	void __fastcall InternalDequeueManaged(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalClearString();
	void __fastcall InternalClearInterface();
	void __fastcall InternalClearDynArray();
	void __fastcall InternalClearByteString();
	void __fastcall InternalClearWideString();
	void __fastcall InternalClear1();
	void __fastcall InternalClear2();
	void __fastcall InternalClear4();
	void __fastcall InternalClear8();
	void __fastcall InternalClearN();
	void __fastcall InternalClearMRef(System::TTypeKind Kind);
	void __fastcall InternalClearManaged();
	void __fastcall EnqueueAdjust(const void *Value);
	void __fastcall InternalEnqueueString(const void *Value);
	void __fastcall InternalEnqueueInterface(const void *Value);
	void __fastcall InternalEnqueueByteString(const void *Value);
	void __fastcall InternalEnqueueDynArray(const void *Value);
	void __fastcall InternalEnqueueWideString(const void *Value);
	void __fastcall InternalEnqueue1(const void *Value);
	void __fastcall InternalEnqueue2(const void *Value);
	void __fastcall InternalEnqueue4(const void *Value);
	void __fastcall InternalEnqueue8(const void *Value);
	void __fastcall InternalEnqueueN(const void *Value);
	void __fastcall InternalEnqueueMRef(const void *Value, System::TTypeKind Kind);
	void __fastcall InternalEnqueueManaged(const void *Value);
	void __fastcall InternalGrow1();
	void __fastcall InternalGrow2();
	void __fastcall InternalGrow4();
	void __fastcall InternalGrow8();
	void __fastcall InternalGrowN();
	void __fastcall InternalGrowMRef();
	void __fastcall InternalGrowManaged();
	void __fastcall InternalSetCapacityInline(System::NativeInt Value, System::NativeInt ElemSize);
	void __fastcall InternalSetCapacity1(System::NativeInt Value);
	void __fastcall InternalSetCapacity2(System::NativeInt Value);
	void __fastcall InternalSetCapacity4(System::NativeInt Value);
	void __fastcall InternalSetCapacity8(System::NativeInt Value);
	void __fastcall InternalSetCapacityN(System::NativeInt Value);
	void __fastcall InternalSetCapacityMRef(System::NativeInt Value);
	void __fastcall InternalSetCapacityManaged(System::NativeInt Value);
	__property void * FItems = {read=FLH.FItems};
	__property void * ElType = {read=GetElType};
	__property System::NativeInt ElSize = {read=GetElSize};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TQueue__1 : public TEnumerable__1<T>
{
	typedef TEnumerable__1<T> inherited;
	
	
private:
	typedef System::DynamicArray<T> arrayOfT;
	
	
public:
	class DELPHICLASS TEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TEnumerator : public TEnumerator__1<T>
	{
		typedef TEnumerator__1<T> inherited;
		
	private:
		TQueue__1<T>* FQueue;
		System::NativeInt FIndex;
		T __fastcall GetCurrent();
		
	protected:
		virtual T __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TEnumerator(TQueue__1<T>* const AQueue);
		__property T Current = {read=GetCurrent};
		HIDESBASE bool __fastcall MoveNext();
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	
private:
	System::NativeInt FHead;
	System::NativeInt FTail;
	System::DynamicArray<T> FItems;
	System::NativeInt FCount;
	void *FTypeInfo;
	System::TObject* FListObj;
	TListHelper::TInternalNotifyProc FNotify;
	TListHelper::TInternalCompareFunc FCompare;
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_4)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_4 FOnNotify;
	PQueueHelper __fastcall FQueueHelper();
	bool __fastcall GetIsEmpty();
	System::DynamicArray<T> __fastcall GetList();
	void __fastcall SetCapacity(System::NativeInt Value);
	T __fastcall DoDequeue(TCollectionNotification Notification);
	void __fastcall DoSetCapacity(System::NativeInt Value);
	System::NativeInt __fastcall GetCapacity();
	void __fastcall InternalNotify(const void *Item, TCollectionNotification Action);
	int __fastcall InternalCompare(const void *Left, const void *Right);
	
protected:
	virtual TEnumerator__1<T>* __fastcall DoGetEnumerator();
	virtual void __fastcall Notify(const T Item, TCollectionNotification Action);
	
public:
	__fastcall TQueue__1()/* overload */;
	__fastcall TQueue__1(TEnumerable__1<T>* const Collection)/* overload */;
	__fastcall TQueue__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	__fastcall virtual ~TQueue__1();
	void __fastcall Enqueue(const T Value);
	T __fastcall Dequeue();
	T __fastcall Extract();
	T __fastcall Peek();
	void __fastcall Clear();
	void __fastcall TrimExcess();
#ifndef _WIN64
	__property System::NativeInt Count = {read=FCount, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Count = {read=FCount};
#endif /* _WIN64 */
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property System::DynamicArray<T> List = {read=GetList};
#ifndef _WIN64
	__property System::NativeInt Capacity = {read=GetCapacity, write=DoSetCapacity, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Capacity = {read=GetCapacity, write=DoSetCapacity};
#endif /* _WIN64 */
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_5)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_5 OnNotify = {read=FOnNotify, write=FOnNotify};
	virtual System::DynamicArray<T> __fastcall ToArray() _FINAL_ATTRIBUTE;
	HIDESBASE TEnumerator* __fastcall GetEnumerator();
};


typedef TStackHelper *PStackHelper;

struct DECLSPEC_DRECORD TStackHelper
{
private:
	TListHelper FLH;
	void * __fastcall GetElType();
	System::NativeInt __fastcall GetElSize();
	void __fastcall CheckEmpty();
	void __fastcall CheckGrow();
	void __fastcall InternalGrow();
	void __fastcall InternalSetCapacity(System::NativeInt Value);
	void __fastcall PopAdjust(const void *Value, TCollectionNotification Notification);
	void __fastcall InternalDoPopString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopInterface(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopDynArray(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopByteString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopWideString(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPop1(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPop2(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPop4(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPop8(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopN(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalDoPopMRef(TCollectionNotification Notification, bool Peek, /* out */ void *Item, System::TTypeKind Kind);
	void __fastcall InternalDoPopManaged(TCollectionNotification Notification, bool Peek, /* out */ void *Item);
	void __fastcall InternalClearString();
	void __fastcall InternalClearInterface();
	void __fastcall InternalClearDynArray();
	void __fastcall InternalClearByteString();
	void __fastcall InternalClearWideString();
	void __fastcall InternalClear1();
	void __fastcall InternalClear2();
	void __fastcall InternalClear4();
	void __fastcall InternalClear8();
	void __fastcall InternalClearN();
	void __fastcall InternalClearMRef(System::TTypeKind Kind);
	void __fastcall InternalClearManaged();
	void __fastcall PushAdjust(const void *Value);
	void __fastcall InternalPushString(const void *Value);
	void __fastcall InternalPushInterface(const void *Value);
	void __fastcall InternalPushDynArray(const void *Value);
	void __fastcall InternalPushByteString(const void *Value);
	void __fastcall InternalPushWideString(const void *Value);
	void __fastcall InternalPush1(const void *Value);
	void __fastcall InternalPush2(const void *Value);
	void __fastcall InternalPush4(const void *Value);
	void __fastcall InternalPush8(const void *Value);
	void __fastcall InternalPushN(const void *Value);
	void __fastcall InternalPushMRef(const void *Value, System::TTypeKind Kind);
	void __fastcall InternalPushManaged(const void *Value);
	__property void * FItems = {read=FLH.FItems};
	__property void * ElType = {read=GetElType};
	__property System::NativeInt ElSize = {read=GetElSize};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TStack__1 : public TEnumerable__1<T>
{
	typedef TEnumerable__1<T> inherited;
	
	
private:
	typedef System::DynamicArray<T> arrayOfT;
	
	
public:
	class DELPHICLASS TEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TEnumerator : public TEnumerator__1<T>
	{
		typedef TEnumerator__1<T> inherited;
		
	private:
		TStack__1<T>* FStack;
		System::NativeInt FIndex;
		T __fastcall GetCurrent();
		
	protected:
		virtual T __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TEnumerator(TStack__1<T>* const AStack);
		__property T Current = {read=GetCurrent};
		HIDESBASE bool __fastcall MoveNext();
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	
private:
	System::DynamicArray<T> FItems;
	System::NativeInt FCount;
	void *FTypeInfo;
	System::TObject* FListObj;
	TListHelper::TInternalNotifyProc FNotify;
	TListHelper::TInternalCompareFunc FCompare;
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_6)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_6 FOnNotify;
	PStackHelper __fastcall FStackHelper();
	bool __fastcall GetIsEmpty();
	System::DynamicArray<T> __fastcall GetList();
	T __fastcall DoPop(TCollectionNotification Notification);
	void __fastcall DoSetCapacity(System::NativeInt Value);
	System::NativeInt __fastcall GetCapacity();
	void __fastcall InternalNotify(const void *Item, TCollectionNotification Action);
	
protected:
	virtual TEnumerator__1<T>* __fastcall DoGetEnumerator();
	virtual void __fastcall Notify(const T Item, TCollectionNotification Action);
	
public:
	__fastcall TStack__1()/* overload */;
	__fastcall TStack__1(TEnumerable__1<T>* const Collection)/* overload */;
	__fastcall TStack__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	__fastcall virtual ~TStack__1();
	void __fastcall Clear();
	void __fastcall Push(const T Value);
	T __fastcall Pop();
	T __fastcall Peek();
	T __fastcall Extract();
	void __fastcall TrimExcess();
	virtual System::DynamicArray<T> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
	__property System::NativeInt Count = {read=FCount, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Count = {read=FCount};
#endif /* _WIN64 */
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property System::DynamicArray<T> List = {read=GetList};
#ifndef _WIN64
	__property System::NativeInt Capacity = {read=GetCapacity, write=DoSetCapacity, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Capacity = {read=GetCapacity, write=DoSetCapacity};
#endif /* _WIN64 */
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_7)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_7 OnNotify = {read=FOnNotify, write=FOnNotify};
	HIDESBASE TEnumerator* __fastcall GetEnumerator();
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename K, typename V> struct __declspec(delphirecord) TPair__2
{
public:
	K Key;
	V Value;
	__fastcall TPair__2(const K AKey, const V AValue);
	TPair__2() {}
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename K, typename V> class PASCALIMPLEMENTATION TDictionary__2 : public TEnumerable__1<TPair__2<K,V> >
{
	typedef TEnumerable__1<TPair__2<K,V> > inherited;
	
	
private:
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
#ifndef _WIN64
	struct DECLSPEC_DRECORD TItem
#else /* _WIN64 */
	struct DECLSPEC_DRECORD _DRECORD_ALIGNAS(4) TItem
#endif /* _WIN64 */
	{
	public:
		int HashCode;
		K Key;
		V Value;
	};
	
	
	typedef TItem *PItem;
	
	typedef System::DynamicArray<TItem> TItemArray;
	
	
public:
	class DELPHICLASS TPairEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TPairEnumerator : public TEnumerator__1<TPair__2<K,V> >
	{
		typedef TEnumerator__1<TPair__2<K,V> > inherited;
		
	private:
		TDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		TPair__2<K,V> __fastcall GetCurrent();
		
	protected:
		virtual TPair__2<K,V> __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TPairEnumerator(TDictionary__2<K,V>* const ADictionary);
		__property TPair__2<K,V> Current = {read=GetCurrent};
		HIDESBASE bool __fastcall MoveNext();
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TPairEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TKeyEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TKeyEnumerator : public TEnumerator__1<K>
	{
		typedef TEnumerator__1<K> inherited;
		
	private:
		TDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		K __fastcall GetCurrent();
		
	protected:
		virtual K __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TKeyEnumerator(TDictionary__2<K,V>* const ADictionary);
		__property K Current = {read=GetCurrent};
		HIDESBASE bool __fastcall MoveNext();
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TKeyEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TValueEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TValueEnumerator : public TEnumerator__1<V>
	{
		typedef TEnumerator__1<V> inherited;
		
	private:
		TDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		V __fastcall GetCurrent();
		
	protected:
		virtual V __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TValueEnumerator(TDictionary__2<K,V>* const ADictionary);
		__property V Current = {read=GetCurrent};
		HIDESBASE bool __fastcall MoveNext();
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TValueEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TValueCollection;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TValueCollection : public TEnumerable__1<V>
	{
		typedef TEnumerable__1<V> inherited;
		
	private:
		TDictionary__2<K,V>* FDictionary;
		System::NativeInt __fastcall GetCount();
		
	protected:
		virtual TEnumerator__1<V>* __fastcall DoGetEnumerator();
		
	public:
		__fastcall TValueCollection(TDictionary__2<K,V>* const ADictionary);
		HIDESBASE typename TDictionary__2<K,V>::TValueEnumerator* __fastcall GetEnumerator();
		virtual System::DynamicArray<V> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
		__property System::NativeInt Count = {read=GetCount, nodefault};
#else /* _WIN64 */
		__property System::NativeInt Count = {read=GetCount};
#endif /* _WIN64 */
	public:
		/* {System_Generics_Collections}TEnumerable<System_Generics_Collections_TDictionary<K,V>_V>.Destroy */ inline __fastcall virtual ~TValueCollection() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TKeyCollection;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TKeyCollection : public TEnumerable__1<K>
	{
		typedef TEnumerable__1<K> inherited;
		
	private:
		TDictionary__2<K,V>* FDictionary;
		System::NativeInt __fastcall GetCount();
		
	protected:
		virtual TEnumerator__1<K>* __fastcall DoGetEnumerator();
		
	public:
		__fastcall TKeyCollection(TDictionary__2<K,V>* const ADictionary);
		HIDESBASE typename TDictionary__2<K,V>::TKeyEnumerator* __fastcall GetEnumerator();
		virtual System::DynamicArray<K> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
		__property System::NativeInt Count = {read=GetCount, nodefault};
#else /* _WIN64 */
		__property System::NativeInt Count = {read=GetCount};
#endif /* _WIN64 */
	public:
		/* {System_Generics_Collections}TEnumerable<System_Generics_Collections_TDictionary<K,V>_K>.Destroy */ inline __fastcall virtual ~TKeyCollection() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	
public:
	V operator[](const K Key) { return this->Items[Key]; }
	
private:
	System::DynamicArray<TItem> FItems;
	System::NativeInt FCount;
	System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > FComparer;
	System::NativeInt FGrowThreshold;
	void __fastcall InternalSetCapacity(System::NativeInt ACapacity);
	void __fastcall Rehash(System::NativeInt NewCapPow2);
	void __fastcall Grow();
	System::NativeInt __fastcall GetBucketIndex(const K Key, int HashCode);
	int __fastcall Hash(const K Key);
	bool __fastcall GetIsEmpty();
	V __fastcall GetItem(const K Key);
	void __fastcall SetItem(const K Key, const V Value);
	void __fastcall DoAdd(int HashCode, System::NativeInt Index, const K Key, const V Value);
	void __fastcall DoSetValue(System::NativeInt Index, const V Value);
	V __fastcall DoRemove(const K Key, int HashCode, TCollectionNotification Notification);
	System::NativeInt __fastcall GetCapacity();
	void __fastcall SetCapacity(const System::NativeInt Value);
	System::NativeInt __fastcall GetCollisions();
	
protected:
	virtual TEnumerator__1<TPair__2<K,V> >* __fastcall DoGetEnumerator();
	virtual void __fastcall KeyNotify(const K Key, TCollectionNotification Action);
	virtual void __fastcall ValueNotify(const V Value, TCollectionNotification Action);
	
public:
	__fastcall TDictionary__2()/* overload */;
	__fastcall TDictionary__2(System::NativeInt ACapacity)/* overload */;
	__fastcall TDictionary__2(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall TDictionary__2(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall TDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection)/* overload */;
	__fastcall TDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall TDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High)/* overload */;
	__fastcall TDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall virtual ~TDictionary__2();
	void __fastcall Add(const K Key, const V Value);
	void __fastcall Remove(const K Key);
	TPair__2<K,V> __fastcall ExtractPair(const K Key);
	void __fastcall Clear();
	void __fastcall TrimExcess();
	bool __fastcall TryGetValue(const K Key, V &Value);
	void __fastcall AddOrSetValue(const K Key, const V Value);
	bool __fastcall TryAdd(const K Key, const V Value);
	bool __fastcall ContainsKey(const K Key);
	bool __fastcall ContainsValue(const V Value);
	virtual System::DynamicArray<TPair__2<K,V> > __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity};
#endif /* _WIN64 */
	__property V Items[const K Key] = {read=GetItem, write=SetItem/*, default*/};
#ifndef _WIN64
	__property System::NativeInt Count = {read=FCount, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Count = {read=FCount};
#endif /* _WIN64 */
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
#ifndef _WIN64
	__property System::NativeInt GrowThreshold = {read=FGrowThreshold, nodefault};
	__property System::NativeInt Collisions = {read=GetCollisions, nodefault};
#else /* _WIN64 */
	__property System::NativeInt GrowThreshold = {read=FGrowThreshold};
	__property System::NativeInt Collisions = {read=GetCollisions};
#endif /* _WIN64 */
	
private:
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_8)(System::TObject* Sender, const K Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_8 FOnKeyNotify;
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_9)(System::TObject* Sender, const V Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_9 FOnValueNotify;
	TKeyCollection* FKeyCollection;
	TValueCollection* FValueCollection;
	TKeyCollection* __fastcall GetKeys();
	TValueCollection* __fastcall GetValues();
	
public:
	HIDESBASE TPairEnumerator* __fastcall GetEnumerator();
	__property TKeyCollection* Keys = {read=GetKeys};
	__property TValueCollection* Values = {read=GetValues};
	__property System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > Comparer = {read=FComparer};
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_10)(System::TObject* Sender, const K Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_10 OnKeyNotify = {read=FOnKeyNotify, write=FOnKeyNotify};
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_11)(System::TObject* Sender, const V Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_11 OnValueNotify = {read=FOnValueNotify, write=FOnValueNotify};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename K, typename V> class PASCALIMPLEMENTATION TOrderedDictionary__2 : public TDictionary__2<K,V>
{
	typedef TDictionary__2<K,V> inherited;
	
	
public:
	class DELPHICLASS TPairEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TPairEnumerator : public TEnumerator__1<TPair__2<K,V> >
	{
		typedef TEnumerator__1<TPair__2<K,V> > inherited;
		
	private:
		TOrderedDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		
	protected:
		virtual TPair__2<K,V> __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TPairEnumerator(TOrderedDictionary__2<K,V>* const ADictionary);
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TPairEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TKeyEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TKeyEnumerator : public TEnumerator__1<K>
	{
		typedef TEnumerator__1<K> inherited;
		
	private:
		TOrderedDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		
	protected:
		virtual K __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TKeyEnumerator(TOrderedDictionary__2<K,V>* const ADictionary);
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TKeyEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TValueEnumerator;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TValueEnumerator : public TEnumerator__1<V>
	{
		typedef TEnumerator__1<V> inherited;
		
	private:
		TOrderedDictionary__2<K,V>* FDictionary;
		System::NativeInt FIndex;
		
	protected:
		virtual V __fastcall DoGetCurrent();
		virtual bool __fastcall DoMoveNext();
		
	public:
		__fastcall TValueEnumerator(TOrderedDictionary__2<K,V>* const ADictionary);
	public:
		/* TObject.Destroy */ inline __fastcall virtual ~TValueEnumerator() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TValueCollection;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TValueCollection : public TEnumerable__1<V>
	{
		typedef TEnumerable__1<V> inherited;
		
	private:
		TOrderedDictionary__2<K,V>* FDictionary;
		System::NativeInt __fastcall GetCount();
		
	protected:
		virtual TEnumerator__1<V>* __fastcall DoGetEnumerator();
		
	public:
		__fastcall TValueCollection(TOrderedDictionary__2<K,V>* const ADictionary);
		virtual System::DynamicArray<V> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
		__property System::NativeInt Count = {read=GetCount, nodefault};
#else /* _WIN64 */
		__property System::NativeInt Count = {read=GetCount};
#endif /* _WIN64 */
	public:
		/* {System_Generics_Collections}TEnumerable<System_Generics_Collections_TOrderedDictionary<K,V>_V>.Destroy */ inline __fastcall virtual ~TValueCollection() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	class DELPHICLASS TKeyCollection;
#ifndef _WIN64
	#pragma pack(push,4)
#endif /* not _WIN64 */
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	class PASCALIMPLEMENTATION TKeyCollection : public TEnumerable__1<K>
	{
		typedef TEnumerable__1<K> inherited;
		
	private:
		TOrderedDictionary__2<K,V>* FDictionary;
		System::NativeInt __fastcall GetCount();
		
	protected:
		virtual TEnumerator__1<K>* __fastcall DoGetEnumerator();
		
	public:
		__fastcall TKeyCollection(TOrderedDictionary__2<K,V>* const ADictionary);
		virtual System::DynamicArray<K> __fastcall ToArray() _FINAL_ATTRIBUTE;
#ifndef _WIN64
		__property System::NativeInt Count = {read=GetCount, nodefault};
#else /* _WIN64 */
		__property System::NativeInt Count = {read=GetCount};
#endif /* _WIN64 */
	public:
		/* {System_Generics_Collections}TEnumerable<System_Generics_Collections_TOrderedDictionary<K,V>_K>.Destroy */ inline __fastcall virtual ~TKeyCollection() { }
		
	};
	
#ifndef _WIN64
	#pragma pack(pop)
#endif /* not _WIN64 */
	
	
private:
	TList__1<K>* FKeys;
	K __fastcall GetKeyList(System::NativeInt Index);
	V __fastcall GetValueList(System::NativeInt Index);
	TPair__2<K,V> __fastcall GetPairList(System::NativeInt Index);
	void __fastcall SetValueList(System::NativeInt Index, const V Value);
	
protected:
	virtual TEnumerator__1<TPair__2<K,V> >* __fastcall DoGetEnumerator();
	virtual void __fastcall KeyNotify(const K Key, TCollectionNotification Action);
	
public:
	__classmethod virtual System::TObject* __fastcall NewInstance();
	__fastcall virtual ~TOrderedDictionary__2();
	HIDESBASE void __fastcall Clear();
	HIDESBASE void __fastcall TrimExcess();
	void __fastcall Delete(System::NativeInt Index);
	void __fastcall Insert(System::NativeInt Index, const K Key, const V Value);
	bool __fastcall TryInsert(System::NativeInt Index, const K Key, const V Value);
	System::NativeInt __fastcall IndexOf(const K Key);
	System::NativeInt __fastcall IndexOfValue(const V Value);
	void __fastcall SortByKeys()/* overload */;
	void __fastcall SortByKeys(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<K> > AComparer)/* overload */;
	void __fastcall SortByValues()/* overload */;
	void __fastcall SortByValues(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<V> > AComparer)/* overload */;
	__property K KeyList[System::NativeInt Index] = {read=GetKeyList};
	__property V ValueList[System::NativeInt Index] = {read=GetValueList, write=SetValueList};
	__property TPair__2<K,V> PairList[System::NativeInt Index] = {read=GetPairList};
	
private:
	TKeyCollection* FKeyCollection;
	TValueCollection* FValueCollection;
	HIDESBASE TKeyCollection* __fastcall GetKeys();
	HIDESBASE TValueCollection* __fastcall GetValues();
	
public:
	HIDESBASE TEnumerator__1<TPair__2<K,V> >* __fastcall GetEnumerator();
	__property TKeyCollection* Keys = {read=GetKeys};
	__property TValueCollection* Values = {read=GetValues};
public:
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2()/* overload */ : TDictionary__2<K,V>() { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(System::NativeInt ACapacity)/* overload */ : TDictionary__2<K,V>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection)/* overload */ : TDictionary__2<K,V>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High)/* overload */ : TDictionary__2<K,V>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TOrderedDictionary<K,V>_K,System_Generics_Collections_TOrderedDictionary<K,V>_V>.Create */ inline __fastcall TOrderedDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(AItems, AItems_High, AComparer) { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION THashSet__1 : public TEnumerable__1<T>
{
	typedef TEnumerable__1<T> inherited;
	
	
private:
	// Template declaration generated by Delphi parameterized types is
	// used only for accessing Delphi variables and fields.
	// Don't instantiate with new type parameters in user code.
	struct DECLSPEC_DRECORD TVoid
	{
	};
	
	
	
private:
	TDictionary__2<T,TVoid>* FDict;
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_12)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	_dt_System_Generics_Collections_12 FOnNotify;
	System::NativeInt __fastcall GetCapacity();
	void __fastcall SetCapacity(const System::NativeInt Value);
	System::NativeInt __fastcall GetCount();
	System::NativeInt __fastcall GetGrowThreshold();
	System::NativeInt __fastcall GetCollisions();
	System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > __fastcall GetComparer();
	bool __fastcall GetIsEmpty();
	void __fastcall InternalNotify(System::TObject* Sender, const T Item, TCollectionNotification Action);
	void __fastcall UpdateNotify();
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_13)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	void __fastcall SetOnNotify(const _dt_System_Generics_Collections_13 Value);
	
protected:
	virtual TEnumerator__1<T>* __fastcall DoGetEnumerator();
	virtual void __fastcall Notify(const T Item, TCollectionNotification Action);
	
public:
	__fastcall THashSet__1()/* overload */;
	__fastcall THashSet__1(System::NativeInt ACapacity)/* overload */;
	__fastcall THashSet__1(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall THashSet__1(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall THashSet__1(TEnumerable__1<T>* const Collection)/* overload */;
	__fastcall THashSet__1(TEnumerable__1<T>* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall THashSet__1(const T *AItems, const System::NativeInt AItems_High)/* overload */;
	__fastcall THashSet__1(const T *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall virtual ~THashSet__1();
	bool __fastcall Add(const T Value);
	bool __fastcall Remove(const T Value);
	T __fastcall GetOrAdd(const T Value);
	void __fastcall Clear();
	void __fastcall TrimExcess();
	bool __fastcall Contains(const T Value);
	virtual System::DynamicArray<T> __fastcall ToArray() _FINAL_ATTRIBUTE;
	bool __fastcall AddRange(const T *Values, const System::NativeInt Values_High)/* overload */;
	bool __fastcall AddRange(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */;
	bool __fastcall AddRange(TEnumerable__1<T>* const Collection)/* overload */;
	void __fastcall ExceptWith(TEnumerable__1<T>* const AOther);
	void __fastcall IntersectWith(TEnumerable__1<T>* const AOther);
	void __fastcall UnionWith(TEnumerable__1<T>* const AOther);
	bool __fastcall Overlaps(TEnumerable__1<T>* const AOther);
	bool __fastcall SetEquals(TEnumerable__1<T>* const AOther);
	bool __fastcall IsSubsetOf(TEnumerable__1<T>* const AOther);
	bool __fastcall IsSupersetOf(TEnumerable__1<T>* const AOther);
#ifndef _WIN64
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity, nodefault};
	__property System::NativeInt Count = {read=GetCount, nodefault};
#else /* _WIN64 */
	__property System::NativeInt Capacity = {read=GetCapacity, write=SetCapacity};
	__property System::NativeInt Count = {read=GetCount};
#endif /* _WIN64 */
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
#ifndef _WIN64
	__property System::NativeInt GrowThreshold = {read=GetGrowThreshold, nodefault};
	__property System::NativeInt Collisions = {read=GetCollisions, nodefault};
#else /* _WIN64 */
	__property System::NativeInt GrowThreshold = {read=GetGrowThreshold};
	__property System::NativeInt Collisions = {read=GetCollisions};
#endif /* _WIN64 */
	__property System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > Comparer = {read=GetComparer};
	typedef void __fastcall (__closure *_dt_System_Generics_Collections_14)(System::TObject* Sender, const T Item, TCollectionNotification Action);
	__property _dt_System_Generics_Collections_14 OnNotify = {read=FOnNotify, write=SetOnNotify};
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TObjectList__1 : public TList__1<T>
{
	typedef TList__1<T> inherited;
	
private:
	bool FOwnsObjects;
	
protected:
	virtual void __fastcall Notify(const T Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectList__1()/* overload */;
	__fastcall TObjectList__1(bool AOwnsObjects)/* overload */;
	__fastcall TObjectList__1(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer, bool AOwnsObjects)/* overload */;
	__fastcall TObjectList__1(TEnumerable__1<T>* const Collection, bool AOwnsObjects)/* overload */;
	__fastcall virtual ~TObjectList__1();
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
public:
	/* {System_Generics_Collections}TList<System_Generics_Collections_TObjectList<T>_T>.Create */ inline __fastcall TObjectList__1(const System::DelphiInterface<System::Generics::Defaults::IComparer__1<T> > AComparer)/* overload */ : TList__1<T>(AComparer) { }
	/* {System_Generics_Collections}TList<System_Generics_Collections_TObjectList<T>_T>.Create */ inline __fastcall TObjectList__1(TEnumerable__1<T>* const Collection)/* overload */ : TList__1<T>(Collection) { }
	/* {System_Generics_Collections}TList<System_Generics_Collections_TObjectList<T>_T>.Create */ inline __fastcall TObjectList__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */ : TList__1<T>(Collection) { }
	/* {System_Generics_Collections}TList<System_Generics_Collections_TObjectList<T>_T>.Create */ inline __fastcall TObjectList__1(const T *Values, const System::NativeInt Values_High)/* overload */ : TList__1<T>(Values, Values_High) { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TObjectQueue__1 : public TQueue__1<T>
{
	typedef TQueue__1<T> inherited;
	
private:
	bool FOwnsObjects;
	
protected:
	virtual void __fastcall Notify(const T Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectQueue__1()/* overload */;
	__fastcall TObjectQueue__1(bool AOwnsObjects)/* overload */;
	__fastcall TObjectQueue__1(TEnumerable__1<T>* const Collection, bool AOwnsObjects)/* overload */;
	HIDESBASE void __fastcall Dequeue();
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
public:
	/* {System_Generics_Collections}TQueue<System_Generics_Collections_TObjectQueue<T>_T>.Create */ inline __fastcall TObjectQueue__1(TEnumerable__1<T>* const Collection)/* overload */ : TQueue__1<T>(Collection) { }
	/* {System_Generics_Collections}TQueue<System_Generics_Collections_TObjectQueue<T>_T>.Create */ inline __fastcall TObjectQueue__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */ : TQueue__1<T>(Collection) { }
	/* {System_Generics_Collections}TQueue<System_Generics_Collections_TObjectQueue<T>_T>.Destroy */ inline __fastcall virtual ~TObjectQueue__1() { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TObjectStack__1 : public TStack__1<T>
{
	typedef TStack__1<T> inherited;
	
private:
	bool FOwnsObjects;
	
protected:
	virtual void __fastcall Notify(const T Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectStack__1()/* overload */;
	__fastcall TObjectStack__1(bool AOwnsObjects)/* overload */;
	__fastcall TObjectStack__1(TEnumerable__1<T>* const Collection, bool AOwnsObjects)/* overload */;
	HIDESBASE void __fastcall Pop();
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
public:
	/* {System_Generics_Collections}TStack<System_Generics_Collections_TObjectStack<T>_T>.Create */ inline __fastcall TObjectStack__1(TEnumerable__1<T>* const Collection)/* overload */ : TStack__1<T>(Collection) { }
	/* {System_Generics_Collections}TStack<System_Generics_Collections_TObjectStack<T>_T>.Create */ inline __fastcall TObjectStack__1(const System::DelphiInterface<System::IEnumerable__1<T> > Collection)/* overload */ : TStack__1<T>(Collection) { }
	/* {System_Generics_Collections}TStack<System_Generics_Collections_TObjectStack<T>_T>.Destroy */ inline __fastcall virtual ~TObjectStack__1() { }
	
};


enum DECLSPEC_DENUM TDictionaryOwnership : unsigned char { doOwnsKeys, doOwnsValues };

typedef System::Set<TDictionaryOwnership, TDictionaryOwnership::doOwnsKeys, TDictionaryOwnership::doOwnsValues> TDictionaryOwnerships;

// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename K, typename V> class PASCALIMPLEMENTATION TObjectDictionary__2 : public TDictionary__2<K,V>
{
	typedef TDictionary__2<K,V> inherited;
	
private:
	TDictionaryOwnerships FOwnerships;
	
protected:
	virtual void __fastcall KeyNotify(const K Key, TCollectionNotification Action);
	virtual void __fastcall ValueNotify(const V Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectDictionary__2(TDictionaryOwnerships Ownerships, System::NativeInt ACapacity)/* overload */;
	__fastcall TObjectDictionary__2(TDictionaryOwnerships Ownerships, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall TObjectDictionary__2(TDictionaryOwnerships Ownerships, System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
public:
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2()/* overload */ : TDictionary__2<K,V>() { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(System::NativeInt ACapacity)/* overload */ : TDictionary__2<K,V>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection)/* overload */ : TDictionary__2<K,V>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High)/* overload */ : TDictionary__2<K,V>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Create */ inline __fastcall TObjectDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TDictionary__2<K,V>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectDictionary<K,V>_K,System_Generics_Collections_TObjectDictionary<K,V>_V>.Destroy */ inline __fastcall virtual ~TObjectDictionary__2() { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename K, typename V> class PASCALIMPLEMENTATION TObjectOrderedDictionary__2 : public TOrderedDictionary__2<K,V>
{
	typedef TOrderedDictionary__2<K,V> inherited;
	
private:
	TDictionaryOwnerships FOwnerships;
	
protected:
	virtual void __fastcall KeyNotify(const K Key, TCollectionNotification Action);
	virtual void __fastcall ValueNotify(const V Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectOrderedDictionary__2(TDictionaryOwnerships Ownerships, System::NativeInt ACapacity)/* overload */;
	__fastcall TObjectOrderedDictionary__2(TDictionaryOwnerships Ownerships, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
	__fastcall TObjectOrderedDictionary__2(TDictionaryOwnerships Ownerships, System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */;
public:
	/* {System_Generics_Collections}TOrderedDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Destroy */ inline __fastcall virtual ~TObjectOrderedDictionary__2() { }
	
public:
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2()/* overload */ : TOrderedDictionary__2<K,V>() { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(System::NativeInt ACapacity)/* overload */ : TOrderedDictionary__2<K,V>(ACapacity) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TOrderedDictionary__2<K,V>(AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TOrderedDictionary__2<K,V>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection)/* overload */ : TOrderedDictionary__2<K,V>(Collection) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(TEnumerable__1<TPair__2<K,V> >* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TOrderedDictionary__2<K,V>(Collection, AComparer) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High)/* overload */ : TOrderedDictionary__2<K,V>(AItems, AItems_High) { }
	/* {System_Generics_Collections}TDictionary<System_Generics_Collections_TObjectOrderedDictionary<K,V>_K,System_Generics_Collections_TObjectOrderedDictionary<K,V>_V>.Create */ inline __fastcall TObjectOrderedDictionary__2(const TPair__2<K,V> *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<K> > AComparer)/* overload */ : TOrderedDictionary__2<K,V>(AItems, AItems_High, AComparer) { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TObjectHashSet__1 : public THashSet__1<T>
{
	typedef THashSet__1<T> inherited;
	
private:
	bool FOwnsObjects;
	
protected:
	virtual void __fastcall Notify(const T Value, TCollectionNotification Action);
	
public:
	__fastcall TObjectHashSet__1(bool AOwnsObjects, System::NativeInt ACapacity)/* overload */;
	__fastcall TObjectHashSet__1(bool AOwnsObjects, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__fastcall TObjectHashSet__1(bool AOwnsObjects, System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */;
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
public:
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1()/* overload */ : THashSet__1<T>() { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(System::NativeInt ACapacity)/* overload */ : THashSet__1<T>(ACapacity) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */ : THashSet__1<T>(AComparer) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(System::NativeInt ACapacity, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */ : THashSet__1<T>(ACapacity, AComparer) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(TEnumerable__1<T>* const Collection)/* overload */ : THashSet__1<T>(Collection) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(TEnumerable__1<T>* const Collection, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */ : THashSet__1<T>(Collection, AComparer) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(const T *AItems, const System::NativeInt AItems_High)/* overload */ : THashSet__1<T>(AItems, AItems_High) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Create */ inline __fastcall TObjectHashSet__1(const T *AItems, const System::NativeInt AItems_High, const System::DelphiInterface<System::Generics::Defaults::IEqualityComparer__1<T> > AComparer)/* overload */ : THashSet__1<T>(AItems, AItems_High, AComparer) { }
	/* {System_Generics_Collections}THashSet<System_Generics_Collections_TObjectHashSet<T>_T>.Destroy */ inline __fastcall virtual ~TObjectHashSet__1() { }
	
};


// Template declaration generated by Delphi parameterized types is
// used only for accessing Delphi variables and fields.
// Don't instantiate with new type parameters in user code.
template<typename T> class PASCALIMPLEMENTATION TThreadedQueue__1 : public System::TObject
{
	typedef System::TObject inherited;
	
	
public:
	typedef System::DynamicArray<T> _1;
	
	
private:
	System::DynamicArray<T> FQueue;
	System::TObject* FQueueNotEmpty;
	System::TObject* FQueueNotFull;
	System::TObject* FQueueLock;
	unsigned __int64 FTotalItemsPushed;
	unsigned __int64 FTotalItemsPopped;
	System::NativeInt FQueueSize;
	System::NativeInt FQueueOffset;
	unsigned FPushTimeout;
	unsigned FPopTimeout;
	bool FShutDown;
#ifndef _WIN64
	unsigned __int64 __fastcall GetTotalItemsPopped();
	unsigned __int64 __fastcall GetTotalItemsPushed();
#endif /* not _WIN64 */
	
public:
	__fastcall TThreadedQueue__1(int AQueueDepth, unsigned PushTimeout, unsigned PopTimeout);
	__fastcall virtual ~TThreadedQueue__1();
	void __fastcall Grow(System::NativeInt ADelta);
	System::Types::TWaitResult __fastcall PushItem(const T AItem)/* overload */;
	System::Types::TWaitResult __fastcall PushItem(const T AItem, /* out */ System::NativeInt &AQueueSize)/* overload */;
#ifdef _WIN64
	System::Types::TWaitResult __fastcall PushItem(const T AItem, /* out */ int &AQueueSize)/* overload */;
#endif /* _WIN64 */
	T __fastcall PopItem()/* overload */;
	T __fastcall PopItem(/* out */ System::NativeInt &AQueueSize)/* overload */;
	System::Types::TWaitResult __fastcall PopItem(/* out */ System::NativeInt &AQueueSize, T &AItem)/* overload */;
#ifdef _WIN64
	T __fastcall PopItem(/* out */ int &AQueueSize)/* overload */;
	System::Types::TWaitResult __fastcall PopItem(/* out */ int &AQueueSize, T &AItem)/* overload */;
#endif /* _WIN64 */
	System::Types::TWaitResult __fastcall PopItem(T &AItem)/* overload */;
	void __fastcall DoShutDown();
#ifndef _WIN64
	__property System::NativeInt QueueSize = {read=FQueueSize, nodefault};
#else /* _WIN64 */
	__property System::NativeInt QueueSize = {read=FQueueSize};
#endif /* _WIN64 */
	__property bool ShutDown = {read=FShutDown, nodefault};
#ifndef _WIN64
	__property unsigned __int64 TotalItemsPushed = {read=GetTotalItemsPushed};
	__property unsigned __int64 TotalItemsPopped = {read=GetTotalItemsPopped};
#else /* _WIN64 */
	__property unsigned __int64 TotalItemsPushed = {read=FTotalItemsPushed};
	__property unsigned __int64 TotalItemsPopped = {read=FTotalItemsPopped};
#endif /* _WIN64 */
};


typedef System::TObject* *PObject;

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE void __fastcall ErrorArgumentOutOfRange(void)/* overload */;
extern DELPHI_PACKAGE void __fastcall ErrorArgumentOutOfRange(System::NativeInt AIndex, System::NativeInt AMaxIndex, System::TObject* AListObj)/* overload */;
extern DELPHI_PACKAGE bool __fastcall InCircularRange(System::NativeInt Bottom, System::NativeInt Item, System::NativeInt TopInc);
}	/* namespace Collections */
}	/* namespace Generics */
}	/* namespace System */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM_GENERICS_COLLECTIONS)
using namespace System::Generics::Collections;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM_GENERICS)
using namespace System::Generics;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SYSTEM)
using namespace System;
#endif

//-- user supplied -----------------------------------------------------------
namespace System
{
namespace Generics
{
namespace Collections
{
  template<typename TKey, typename TValue>
  inline __fastcall TPair__2<TKey, TValue>::TPair__2(const TKey AKey, const TValue AValue) :
                                            Key(AKey), Value(AValue)
  {}
}	/* namespace Collections */
}	/* namespace Generics */
}	/* namespace System */

#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// System_Generics_CollectionsHPP
