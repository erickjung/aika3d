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

#ifndef IO_OUTPUTSTREAM_H
#define IO_OUTPUTSTREAM_H

#include <util/Object.h>
#include <util/Log.h>
#include <lang/String.h>

namespace io
{
    /**
     * @brief
     * This abstract class is the superclass of all classes representing an output stream of bytes. 
     * An output stream accepts output bytes and sends them to some sink.
     */
    class API_STATE OutputStream : public Object
    {
    public:
        /**
         * Flushes this output stream and forces any buffered output bytes to be written out.
         */
        virtual void flush()
        {}

        /**
         * Writes the specified byte to this byte array output stream.
         */
        virtual void write(const char data) = 0;

        /**
         * Writes a string in the array output stream.
         * 
         * \note
         * With this method we don't need to use the FileWriter for example.
         * 
         * @param data Data to be write
         */
        virtual void write(const lang::String& data) = 0;

        /**
         * Writes len bytes from the specified byte array to this output stream.
         * 
         * @param data Data to be write
         * @param size Size of bytes
         */
        virtual void write( const char* pData, int32 size ) = 0;
    };
} //namespace

#endif
