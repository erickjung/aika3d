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

#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <util/Define.h>
#include <util/Types.h>

// Assert macro
#undef assert
#if (ASSERTION_LOG == ON)
#   define assert(value) Assert::assertState(value, __FILE__, __LINE__);
#else
#   define assert(value)
#endif

/**
 * @brief 
 * Description: Assertions.
 * 
 * @note
 *  See the Define.h to know how turn ON the assetion.
 * 
 * Usage:
 * @code
 *   01) Pointer assert:
 *       assert(pointer);
 *
 *   02) Bool assert:
 *       assert(int32 > 0);
 *
 *   03) Pointer and bool assert:
 *       assert(pointer != NULL && int32 > 0);
 *
 * @endcode
 */
class API_STATE Assert
{
private:
    enum E_ASSERT_TYPE
    {
        AT_POINTER = 0,
        AT_BOOL
    };

    /**
     * This method is used to output assertions.
     * 
     * @param errorType   type of error.
     * @param pFile       the caller file.
     * @param line        the caller line.
     */
    static void printError(E_ASSERT_TYPE errorType, const char* pFile, int32 line);

public:

    /**
     * This method is used to catch the pointer assertion.
     * 
     * @param pState      the object assert statement.
     * @param pFile       the caller file.
     * @param line        the caller line.
     */
    static bool assertState(const void *pState, const char* pFile, int32 line);

    /**
     * This method is used to catch the bool assertion.
     * 
     * @param state       the bool assert statement.
     * @param pFile       the caller file.
     * @param line        the caller line.
     */
    static bool assertState(bool state, const char* pFile, int32 line);
};


#endif //__ASSERT_H__*/
