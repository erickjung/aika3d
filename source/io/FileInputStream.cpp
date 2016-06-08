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

#include <io/FileInputStream.h>


namespace io
{
    FileInputStream::FileInputStream()
    {
    }

    FileInputStream::~FileInputStream()
    {
        if (_fileHandle)
            fclose(_fileHandle);
    }

    bool FileInputStream::openFile(const lang::String& filename)
    {
        assert(filename.length() > 0);

        _fileHandle = fopen(filename, "rb" );
        assert(_fileHandle);

        return true;
    }

    int32 FileInputStream::read()
    {
        int32 byte = 0;
        fread(&byte, 1, 1, _fileHandle);

        return byte;
    }

    int32 FileInputStream::read(uint16 &data)
    {
        int32 byte = fread(&data, sizeof(uint16), 1, _fileHandle);

        return byte;
    }

    int32 FileInputStream::read(char *pDataOut, int32 size)
    {
        assert(pDataOut != NULL && size > 0);
        
        return fread(pDataOut, 1, size, _fileHandle );
    }

    int32 FileInputStream::available() const
    {
        int32 cur = ftell(_fileHandle);
        if(fseek(_fileHandle, 0, SEEK_END) != 0)
            return 0;

        int32 end = ftell(_fileHandle);

        if(fseek(_fileHandle, cur, SEEK_SET) != 0)
            return 0;

        if (ferror(_fileHandle))
        {
            assert(false);
        }

        return end - cur;
    }

    int32 FileInputStream::skip(int32 n)
    {
        // TODO: implement the skip
        return 0;
    }

    const char * FileInputStream::toString()
    {
        return "class: FileInputStream";
    }
} //namespace
