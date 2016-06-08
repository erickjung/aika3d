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

#include <io/FileOutputStream.h>
#include <util/Assert.h>


namespace io
{
    FileOutputStream::FileOutputStream( const lang::String& filename )
    {
        assert(filename.length() > 0);

        _fileHandle = fopen(filename, "wb" );
        assert(_fileHandle);
    }

    FileOutputStream::~FileOutputStream()
    {
        close();
    }

    void FileOutputStream::close()
    {
        if (_fileHandle)
            fclose(_fileHandle);
    }

    void FileOutputStream::write(const int32 data)
    {
        char tmp[15];
        sprintf(tmp, "%d", data);

        lang::String str(tmp);
        write(str);
    }

    void FileOutputStream::write(const char data)
    {
        fwrite(&data, 1, 1, _fileHandle);
    }

    void FileOutputStream::write(const lang::String& data)
    {
        fwrite(data, 1, data.length(), _fileHandle);
    }

    void FileOutputStream::write(const char* pData, int32 size)
    {
        fwrite(pData, 1, size, _fileHandle);
    }

    lang::String FileOutputStream::toString() const
    {
        // TODO: implement the toString
        return 0;
    }

    const char * FileOutputStream::toString()
    {
        return "class: FileOutputStream";
    }
} //namespace
