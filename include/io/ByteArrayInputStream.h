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

#ifndef IO_BYTEARRAYINPUTSTREAM_H
#define IO_BYTEARRAYINPUTSTREAM_H

#include <io/InputStream.h>
#include <lang/Array.h>

namespace io
{
    /**
     * @brief
     * A ByteArrayInputStream contains an internal buffer that contains bytes that 
     * may be read from the stream. An internal counter keeps track of the next byte 
     * to be supplied by the read method.
     */
    class API_STATE ByteArrayInputStream : public InputStream
    {
    private:
        /**
         * The data buffer
         */
        lang::Array<char> _buffer;

        /**
         * The data index
         */
        int32 _index;

		/**
		 * Position
		 */
		int32 _position;

    public:

        /**
         * Constructor 
         */
        ByteArrayInputStream(const void* pData, int32 size);

        /**
         * Destructor
         */
        virtual ~ByteArrayInputStream();

        /**
         * Resets with new input buffer.
         * Note that the contents of the buffer is duplicated so the buffer
         * can be freed immediately after ByteArrayInputStream constructor returns.
         */
        void reset(const void* pData, int32 size);

        /**
         * @see InputStream::read()
         */
        int32 read();

        /**
         * @see InputStream::read(void* pDataOut, int32 size)
         */
        int32 read(char *pDataOut, int32 size);

        /**
         * @see InputStream::int32 skip(int32 n)
         */
        int32 skip(int32 n);

        /**
         * @see InputStream::available()
         */
        int32 available() const;

		/**
		 * @see Object::toString()
		 */
		const char *toString();
    };
} //namespace

#endif
