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

#ifndef IO_FILEINPUTSTREAM_H
#define IO_FILEINPUTSTREAM_H

#include <io/InputStream.h>
#include <stdio.h>

namespace io
{
    /**
     * @brief
     * A FileInputStream obtains input bytes from a file in a file system. 
     * What files are available depends on the host environment.
     * 
     * @note
     * FileInputStream is meant for reading streams of raw bytes such as 
     * image data. For reading streams of characters, consider using FileReader.
     */
    class API_STATE FileInputStream : public InputStream
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
        FileInputStream();

        /**
         * Destructor
         */
        virtual ~FileInputStream();

        /**
         * Open the desired file.
         * 
         * @param filename The name of file
         * @return true if operation was a success.
         */
        bool openFile(const lang::String& filename);

        /**
         * @see InputStream::read()
         */
        int32 read();

        /**
         * @see InputStream::read()
         */
        int32 read(uint16 &data);

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
} // io


#endif
