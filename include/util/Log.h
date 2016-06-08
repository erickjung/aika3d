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

#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <util/Define.h>
#include <util/Object.h>
#include <util/Assert.h>


#if (TRACE_LOG == ON)
#   define TRACE(text) Log __LOG__(text)
#else
#   define TRACE(text)
#endif

/**
 * @brief 
 * Description: Log system.
 *  - All the messages output need to use this class.
 * 
 * @note
 *  There is already an static Log instance, see the Usage.
 *  See the Define.h to know how turn ON the file save.
 * 
 * Usage:
 * @code
 *   01) New instance
 *     Log logging;
 *     logging << "Test";
 * 
 *   02) Static usage
 *     Log::log << "Test"; 
 * 
 * @endcode
 */
class API_STATE Log : public Object
{
private:

    /**
     * The number of instances
     */
    static int32 _count;

    /**
     * The depth for stacktrace
     */
    static int32 _depth;

    /**
     * Method name used in stacktrace
     */
    char *_pMethodName;

public:

    /**
     * Static instance
     */
    static Log log;

	/**
     * Constructor
     */
    Log();

	/**
     * Constructor
     */
    explicit Log(const char* pMethodName);

    /**
     * Destructor
     */
    virtual ~Log();

    /**
     * Operator overload to string
     */
    Log& operator << (char *pText);

    /**
     * Operator overload to signed integer
     */
    Log& operator << (int32 value);

    /**
     * Operator overload to unsigned integer
     */
    Log& operator << (uint32 value);

    /**
     * Operator overload to boolean
     */
    Log& operator << (bool value);

    /**
     * Operator overload to void*
     */
    Log& operator << (void *pObject);

    /**
     * This method is used to output stacktrace.
     * 
     * @param align        align the line.
     * @param action       the action of line.
     * @param methodName   the method name.
     * @see TRACE_LOG definition
     */
    void record(int32 align, const char *pText, const char *pMethodName);

    /**
     * This method is used to output memory allocation statements.
     * 
     * @param pComponent  the component name to be displayed.
     * @param pFile       the caller file.
     * @param line        the caller line.
     * @param ptr         the pointer.
     * @param size        the size.
     * @see MEMORY_LOG definition  
     * @see MEMORY_FILE_LOG definition
     */
    static void memAlloc(char *pComponent, char *pFile, int32 line);

    /**
     * This method is used to output assertions.
     * 
     * @param pErrorType  type of error.
     * @param pFile       the caller file.
     * @param line        the caller line.
     * @see ASSERTIOM_LOG definition
     */
    static void assertMsg(const char* pErrorType, const char* pFile, int32 line);

    /**
	 * Used to close all the logs.
	 */
    static void closeLogs();

	/**
	 * @see Object::toString()
	 */
	const char * toString();
};

#endif /*_LOG_H_*/
