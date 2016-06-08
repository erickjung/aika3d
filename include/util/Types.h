// Copyright (c) 2007-2016 Erick Jung
//
// This code is distributed under the terms and conditions of the MIT license.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>

#ifndef TYPES_H_
#define TYPES_H_

//------------------------------
// Type Defs
//------------------------------

// char types

/** 8 bits - char */
typedef signed char int8;

/** 16 bits - wchar_t (unicode) */
typedef wchar_t wint16;

// short types

/** 16 bits - short */
typedef short int16;

/** 16 bits - unsigned short*/
typedef unsigned short uint16;

// int types

/** 32 bits - int */
typedef int int32;

/** 32 bits - unsigned int */
typedef unsigned int uint32;

// long types

/** 32 bits - long */
typedef long long32;

/** 32 bits - unsigned long */
typedef unsigned long ulong32;

// float type

/** 32 bits - float */
typedef float float32;

// double types

/** 64 bits - double */
typedef double double64;

/** 96 bits - long double */
typedef long double ldouble96;

#endif
