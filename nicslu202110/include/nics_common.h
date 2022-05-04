/*
nics_common.h
This header file provides basic definitions of data types and macros.
It must be included in all source files.
Following macro can be defined:
__NICS_INT64: for 64-bit integer, it can be only used when code is complied in x64 mode.

Length (in bytes) of all integer types on Windows and Linux, for mainstream compilers (VS/GCC/ICC).
UNIX-like OS uses LP64, Windows uses LLP64.
'long' is not used in NICSLU as it has different sizes on Linux and Windows.

          Windows x86  Windows x64  Linux x86  Linux x64
char           1            1           1          1
short          2            2           2          2
int            4            4           4          4
long           4            4           4          8
long long      8            8           8          8
size_t         4            8           4          8
*/

#ifndef __NICS_COMMON__
#define __NICS_COMMON__

#ifdef _MSC_VER
/*to avoid some inexplicable errors on visual studio 2017/2019/2022*/
#define _CRT_SECURE_NO_WARNINGS		1
#define _CRT_NONSTDC_NO_WARNINGS	1
#define _CRT_SECURE_NO_DEPRECATE	1
#endif

#include <stddef.h>

/*check system*/
#if !(defined(_WIN32) || defined(__linux__) || defined(__unix__))
	#error UNSUPPORTED OPERATING SYSTEM!
#endif

/*check x86 or x64*/
#undef __NICS_X64
#ifdef _WIN32
	#if (defined(_M_X64) || defined(_WIN64))/*VS2008 does not define _WIN64 in x64 mode*/
		#define __NICS_X64
	#endif/*_M_X64 or _WIN64*/
#else/*_WIN32*/
	#if (defined(__amd64__) || defined(__x86_64__))
		#define __NICS_X64
	#endif/*__amd64__ or __x86_64__*/
#endif/*_WIN32*/

/*check int64*/
#ifdef __NICS_INT64
	#ifndef __NICS_X64
		#error __NICS_INT64 CAN ONLY BE DEFINED IN X64!
	#endif/*__NICS_X64*/
#endif/*__NICS_INT64*/

/*return code & helper*/
#define __OK				(0)
#define __SUCCESS(code)		(((int)code) >= __OK)
#define __FAIL(code)		(((int)code) < __OK)
#define __WARNING(code)		(((int)code) > __OK)

/*typedef*/
#ifdef _WIN32/*workaround for VC++ 6.0*/
#define __INT64				__int64
#else
#define __INT64				long long
#endif
typedef void			   *_handle_t;
typedef unsigned char		_byte_t;
typedef unsigned char		_bool_t;
typedef int					_int32_t;
typedef unsigned int		_uint32_t;
typedef __INT64				_int64_t;
typedef unsigned __INT64	_uint64_t;
#ifdef __NICS_INT64
typedef _int64_t			_int_t;
typedef _uint64_t			_uint_t;
#else/*__NICS_INT64*/
typedef _int32_t			_int_t;
typedef _uint32_t			_uint_t;
#endif/*__NICS_INT64*/
typedef float				_float_t;
typedef double				_double_t;
typedef _double_t			_complex_t[2];
typedef size_t				_size_t;
#ifdef __NICS_X64
typedef __INT64				_ssize_t;
#else/*__NICS_X64*/
typedef int					_ssize_t;
#endif/*__NICS_X64*/
#undef __INT64

/*argument flags*/
#define __IN
#define __OUT
#define __INANDOUT
#define __INOROUT

#endif
