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

#ifndef IO_INPUTSTREAM_H
#define IO_INPUTSTREAM_H

#include <util/Object.h>
#include <util/Log.h>
#include <lang/String.h>

namespace io
{
    /**
     * @brief
     * This abstract class is the superclass of all classes representing an input stream of bytes.
     * 
     * @note
     * Applications that need to define a subclass of InputStream  must always provide a method 
     * that returns the next byte of input.
     */
	class API_STATE InputStream : public Object
    {
    public:
        /**
         * Returns a byte of data from this input stream.
         */
        virtual int32 read() = 0;

        /**
         * Tries to read specified number of bytes from the stream.
         * Doesn't block the caller if specified number of bytes isn't available.
         * 
         * \note
         * We don't use the read(byte[] b) 
         *
         * @param pDataOut The data buffer
         * @param size     The size of buffer
         * @return Number of bytes actually read.
         */
        virtual int32 read(char *pDataOut, int32 size) = 0;

        /**
         * Tries to skip over n bytes from the stream.
         * 
         * @param n The number to be skipped
         * @return Number of bytes actually skipped.
         */
        virtual int32 skip(int32 n) = 0;

        /**
         * Returns the number of bytes that can be read from the stream without blocking.
         */
        virtual int32 available() const = 0;
    };
} //namespace

#endif

