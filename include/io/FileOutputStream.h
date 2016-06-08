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

#ifndef IO_FILEOUTPUTSTREAM_H
#define IO_FILEOUTPUTSTREAM_H

#include <io/OutputStream.h>
#include <stdio.h>

namespace io
{
    /**
     * @brief
     * A file output stream is an output stream for writing data to a File 
     * or to a FileDescriptor. Whether or not a file is available or may be 
     * created depends upon the underlying platform. Some platforms, in particular, 
     * allow a file to be opened for writing by only one FileOutputStream 
     * (or other file-writing object) at a time. In such situations the constructors 
     * in this class will fail if the file involved is already open.
     * 
     * @note
     * FileOutputStream is meant for writing streams of raw bytes 
     * such as image data. We use write(string) to work with strings.
     */
    class API_STATE FileOutputStream : public OutputStream
    {
    private:
        /**
         * The file data handle
         */
        FILE* _fileHandle;

    public:
        /**
         * Constructor
         */
        FileOutputStream(const lang::String& filename);

        /**
         * Destructor
         */
        virtual ~FileOutputStream();

        /**
         * Returns name of the file 
         */
        lang::String toString() const;

        /**
         * Close the file.
         */
        void close();

        /**
         * @see OutputStream::write(const int32 data)
         */
        void write(const int32 data);

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
        void write(const char* pData, int32 size);

		/**
		 * @see Object::toString()
		 */
		const char *toString();
    };
} // io


#endif
