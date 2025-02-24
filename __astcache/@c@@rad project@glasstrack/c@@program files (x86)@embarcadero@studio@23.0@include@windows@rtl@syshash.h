// -----------------------------------------------------------------------------
// syshash.h C++ specializations of Delphi string types for 'std::hash'.
//
// $Rev: 000000 $
//
// Copyright(c) 2024 Embarcadero Technologies, Inc.
// -----------------------------------------------------------------------------
#ifndef SYSHASH_H
#define SYSHASH_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'System.hpp'.
#endif

#if defined(_WIN32)
#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif
#if !defined(DSTRING_H)
#include <dstring.h>
#endif
#if !defined(USTRING_H)
#include <ustring.h>
#endif
#if !defined(WSTRING_H)
#include <wstring.h>
#endif

#include <functional>

#if __clang_major__ >= 15
#include <__string/char_traits.h>

namespace std {

template <unsigned short CP>
struct hash<System::AnsiStringT<CP> > {
  size_t operator()(const System::AnsiStringT<CP>& s) const {
    const char* data = reinterpret_cast<const char*>(s.data());
    return __do_string_hash(
      reinterpret_cast<const unsigned char*>(data),
      reinterpret_cast<const unsigned char*>(data + s.Length())
    );
  }
};

template <>
struct hash<System::UnicodeString> {
  size_t operator()(const System::UnicodeString& s) const {
	const System::WideChar* data = reinterpret_cast<const System::WideChar*>(s.data());
    return __do_string_hash(
      reinterpret_cast<const unsigned char*>(data),
      reinterpret_cast<const unsigned char*>(data + s.Length())
    );
  }
};

template <>
struct hash<System::WideString> {
  size_t operator()(const System::WideString& s) const {
	const System::WideChar* data = s.c_bstr();
    return __do_string_hash(
      reinterpret_cast<const unsigned char*>(data),
      reinterpret_cast<const unsigned char*>(data + s.Length())
    );
  }
};

}
#else
#if defined(__clang__)
#include <xstddef>
#else
inline size_t _Hash_seq(const unsigned char *_First, size_t _Count) {
  size_t hash_val = 0;
  for (size_t i = 0; i < _Count; ++i)
    hash_val = hash_val * 127773 + _First[i];
  ldiv_t _Qrem = ldiv(static_cast<long>(hash_val), 127773);
  _Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
  if (_Qrem.rem < 0)
    _Qrem.rem += 2147483647;
  return static_cast<size_t>(_Qrem.rem);
}
#endif

namespace std {

#if !defined(__clang__)
namespace tr1 {
#endif

template <unsigned short CP>
struct hash<System::AnsiStringT<CP> > {
  size_t operator()(const System::AnsiStringT<CP>& s) const {
    return _Hash_seq(
      reinterpret_cast<const unsigned char*>(s.data()),
      static_cast<size_t>(s.Length()) * sizeof(char)
    );
  }
};

template <>
struct hash<System::UnicodeString> {
  size_t operator()(const System::UnicodeString& s) const {
    return _Hash_seq(
      reinterpret_cast<const unsigned char*>(s.data()),
	  static_cast<size_t>(s.Length()) * sizeof(System::WideChar)
    );
  }
};

template <>
struct hash<System::WideString> {
  size_t operator()(const System::WideString& s) const {
    return _Hash_seq(
      reinterpret_cast<const unsigned char*>(s.c_bstr()),
	  static_cast<size_t>(s.Length()) * sizeof(System::WideChar)
    );
  }
};

#if !defined(__clang__)
}
#endif

}
#endif
#endif

#endif
