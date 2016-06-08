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

#ifndef DEFINE_H_
#define DEFINE_H_

/**
 * @page config Configuration Instructions
 *
 * @section intro Details
 *
 * You could turn on the main features of Aika (Memory Leak Tracking and Stack Trace).
 * Go to the "Define.h" and turn ON:
 *
 * - MEMORY_LOG  (To tracking memory allocation)
 * - TRACE_LOG   (For Stack Trace)
 *
 */

#ifdef WIN32
	#if defined( __MINGW32__ )
		#define API_STATE
		#define API_PRIVATE_STATE
	#else
        #pragma warning (disable : 4251)

		#if defined( AK_DYN_EXPORT )
			#define API_STATE __declspec( dllexport )
			#define EXPIMP_TEMPLATE
		#else
			#define API_STATE __declspec( dllimport )
			#define EXPIMP_TEMPLATE extern
		#endif
	#endif
#endif

//------------------------------
// Defs
//------------------------------
#define ON  1
#define OFF 0

#if defined(AK_DEBUG)
#	define ASSERTION_LOG ON
#	define MEMORY_LOG	 ON
#	define TRACE_LOG	 ON
#else
#	define ASSERTION_LOG OFF
#	define MEMORY_LOG	 OFF
#	define TRACE_LOG	 OFF
#endif

#endif //DEFINE_H_
