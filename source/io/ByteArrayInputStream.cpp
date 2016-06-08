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
#include <io/ByteArrayInputStream.h>
#include <util/Assert.h>

namespace io
{
    ByteArrayInputStream::ByteArrayInputStream( const void* pData, int32 size ) 
        : _index(0), _position(0)
    {
        assert(pData != NULL && size > 0);

        reset( pData, size );
    }

    ByteArrayInputStream::~ByteArrayInputStream()
    {
        _buffer.free();
    }

    void ByteArrayInputStream::reset(const void* pData, int32 size)
    {
        assert(pData != NULL && size > 0);

        _buffer.reserve(size);

        if (size > 0)
            memcpy(&_buffer[0], pData, size );
        _index = 0;
    }

    int32 ByteArrayInputStream::read()
    {
        return _buffer[_position++];
    }

    int32 ByteArrayInputStream::read(char *pDataOut, int32 size)
    {
        assert(pDataOut != NULL && size > 0);

        if(size > 0)
        {
            pDataOut = new char[size];
            memset(pDataOut, 0, size);

            for (int32 i = 0 ; i < size; ++i )
                pDataOut[i] = _buffer[i];

            pDataOut[size] = '\0';
        }

        return 0;
    }

    int32 ByteArrayInputStream::available() const
    {
        return (_buffer.getSize() - _index);
    }

    int32 ByteArrayInputStream::skip(int32 n)
    {
        // not implemented
        return 0;
    }

    const char * ByteArrayInputStream::toString()
    {
        return "class: ByteArrayInputStream";
    }
} //namespace
