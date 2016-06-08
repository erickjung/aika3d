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

#include <string.h>
#include <io/ByteArrayOutputStream.h>
#include <util/Assert.h>


namespace io
{
    ByteArrayOutputStream::ByteArrayOutputStream(int32 size)
    {
        assert(size > 0);
        
        _buffer.reserve(size);
    }

    ByteArrayOutputStream::~ByteArrayOutputStream()
    {
        _buffer.free();
    }

    void ByteArrayOutputStream::reset()
    {
        _buffer.free();
    }

    int32 ByteArrayOutputStream::size() const
    {
        return _buffer.getSize();
    }

    const char* ByteArrayOutputStream::toByteArray() const
    {
        // TODO: add the return

        return 0;
    }

    lang::String ByteArrayOutputStream::toNatString() const
    {
        // TODO: add the natString
        return 0;
    }

    void ByteArrayOutputStream::write(const char data)
    {
        int32 oldsize = _buffer.getSize();
        _buffer.reserve(oldsize + 1);

        _buffer.add(data);
    }

    void ByteArrayOutputStream::write(const lang::String& data)
    {
        assert(data.length() > 0);

        int32 size =  _buffer.getSize() + data.length();
        _buffer.reserve(size);

        for (uint16 i = 0; i < data.length(); i++)
            _buffer.add(data.charAt(i));
    }

    void ByteArrayOutputStream::write( const char* pData, int32 size )
    {
        assert(pData != NULL && size > 0);

        int32 oldsize = _buffer.getSize();
        _buffer.reserve( oldsize + size );

        for (int32 i = 0 ; i < size ; i++)
            _buffer.add(pData[i]);
    }

    void ByteArrayOutputStream::writeTo(OutputStream *pStreamOut)
    {
        // TODO: add the writeTo
    }

    const char * ByteArrayOutputStream::toString()
    {
        return "class: ByteArrayOutputStream";
    }
} //namespace
