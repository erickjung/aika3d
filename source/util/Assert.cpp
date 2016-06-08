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

#include <stdlib.h>
#include <util/Assert.h>
#include <util/Log.h>

const char* errorTypes[] = {
        "Pointer",
        "Boolean"
};

void Assert::printError(E_ASSERT_TYPE errorType, const char* pFile, int32 line)
{
    Log::assertMsg(errorTypes[errorType], pFile, line);
    exit(-1);
}

bool Assert::assertState(const void *state, const char* pFile, int32 line)
{
    if(state == NULL)
    {
        printError(AT_POINTER, pFile, line);
    }

    return (state != NULL) ? true : false;
}

bool Assert::assertState(bool state, const char* pFile, int32 line)
{
    if(state == false)
    {
        printError(AT_BOOL, pFile, line);
    }

    return (state == true) ? true : false;
}


