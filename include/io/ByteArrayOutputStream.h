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

#ifndef IO_BYTEARRAYOUTPUTSTREAM_H
#define IO_BYTEARRAYOUTPUTSTREAM_H

#include <io/OutputStream.h>
#include <lang/Array.h>

namespace io
{
    /**
     * @brief
     * This class implements an output stream in which the data is written into a byte array. 
     * The buffer automatically grows as data is written to it. The data can be retrieved using 
     * toByteArray() and toString().
     */
    class API_STATE ByteArrayOutputStream : public OutputStream
    {
    private:
        /**
         * The buffer
         */
        lang::Array<char> _buffer;

    public:
        /**
         * Constructor
         */
        ByteArrayOutputStream(int32 size = 0);

        /**
         * Destructor
         */
        virtual ~ByteArrayOutputStream();

        /**
         * Resets the count field of this byte array output stream to 
         * zero, so that all currently accumulated output in the ouput stream is discarded. 
         */
        void reset();

        /**
         * Returns the current size of the buffer.
         */
        int32 size() const;

        /**
         * Creates a newly allocated byte array.
         */
        const char*	toByteArray() const;

        /**
         * Returns byte array identifier. 
         */
        lang::String toNatString() const;

        /**
         * Writes the complete contents of this byte array output stream to 
         * the specified output stream argument, as if by calling the output 
         * stream's write method using out.write(buf, count).
         * 
         * @param out The output outputstream
         */
        void writeTo(OutputStream *pStreamOut);

        /**
         * @see OutputStream::write(const char data)
         */
        void write(const char data);

        /**
         * @see OutputStream::write(const lang::String& data)
         */
        void write(const lang::String& data);

        /**
         * @see OutputStream::write(const void* data, int32 size)
         */
        void write(const char *pData, int32 size);

        /**
         * @see Object::toString()
         */
        const char *toString();
    };
} //namespace


#endif
