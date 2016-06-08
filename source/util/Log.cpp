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

#include <util/Log.h>
#include <io/FileOutputStream.h>

//-----------------------
// Static Initialization
//-----------------------

/**
* The output file stream. Only used when the MEMORY_FILE_LOG is ON.
*/
#if (MEMORY_LOG == ON)
io::FileOutputStream memoryFile("memory.txt");
#endif

/**
* The output file stream. Only used when the TRACE_LOG is ON.
*/
#if (TRACE_LOG == ON)
io::FileOutputStream debugFile("trace.txt");
#endif

/**
* The output file stream. Only used when the ASSERTION_LOG is ON.
*/
#if (TRACE_LOG == ON)
io::FileOutputStream assertFile("assertion.txt");
#endif

Log Log::log;

int32 Log::_count = 0;

int32 Log::_depth = 0;

//------------------------


Log::Log()
{
}

Log::Log(const char *pMethodName)
{
#if (TRACE_LOG == ON)

    _pMethodName = (char*)pMethodName;

    record(_depth*2, "-->", _pMethodName);
    ++_depth;

#endif
}

Log::~Log()
{
#if (TRACE_LOG == ON)

    --_depth;
    if(_depth >= 0)
        record(_depth*2, "<--", "");
#endif

    if(Object::instances() == 0)
        closeLogs();
}

Log& Log::operator << (char *pText)
{
    printf("%s", pText);
    return *this;
}

Log& Log::operator << (int32 value)
{
    printf("%d", value);
    return *this;
}

Log& Log::operator << (uint32 value)
{
    printf("%u", value);
    return *this;
}

Log& Log::operator << (bool value)
{
    printf("%s", value ? "true" : "false");
    return *this;
}

Log& Log::operator << (void *pText)
{
    printf("0x%08X", (uint32)pText);
    return *this;
}

void Log::record(int32 align, const char *pText, const char *pMethodName)
{
    /*int32 depth, int32 align,*/ 
#if (TRACE_LOG == ON)

    if(align > 0)
    {
        for(int32 i = 1; i <= align; i++)
        {
            debugFile.write(' ');
            //printf(" ");
        }
    }

    //printf("(%d) [trace]:%s <%s>\n", depth, action, methodName);
    debugFile.write("(");
    debugFile.write(_depth);
    debugFile.write(")");
    debugFile.write(pText);
    debugFile.write(" <");
    debugFile.write(pMethodName);
    debugFile.write("> \n");

#endif
}

void Log::memAlloc(char *pComponent, char *pFile, int32 line)
{
#if (MEMORY_LOG == ON)

    _count++;
    memoryFile.write(_count);
    memoryFile.write(" ["); memoryFile.write(pComponent);
    memoryFile.write("] - file: "); memoryFile.write(pFile);
    memoryFile.write(" - line: "); memoryFile.write(line);
    memoryFile.write('\n');

#endif
}

void Log::assertMsg(const char* pErrorType, const char* pFile, int32 line)
{
#if (ASSERTION_LOG == ON)

    assertFile.write(pErrorType);
    assertFile.write(" - Error in line: ");
    assertFile.write(line);
    assertFile.write(" in file: ");
    assertFile.write(pFile);
#endif
}

void Log::closeLogs()
{
#if (MEMORY_LOG == ON)
	memoryFile.write("Number of memory allocated: "); memoryFile.write(instances());
    memoryFile.write('\n');
#endif

#if (TRACE_LOG == ON)
    debugFile.close();
#endif
}

const char * Log::toString()
{
    return "class: Log";
}