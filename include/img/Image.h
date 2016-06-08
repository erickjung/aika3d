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

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <util/Object.h>
#include <lang/String.h>

namespace img
{
	using namespace lang;

	/**
     * @brief
     * This is the image class, responsible to load all the image files.
     * 
     * @note
     * For now we only have support for OpenIL.
     */
	class API_STATE Image : public Object
	{
	public:

		/**
         * Constructor
         */
		Image();

        /**
         * Destructor
         */
		virtual ~Image(){}

        /**
         * Load the image file
         *
         * @param filename The file name
		 * @return true if the file was loaded
         */
		bool load(const String &filename, uint32 &numberId);

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Image";}

	private:
        /**
         * The filename.
         */
		String _filename;

        /**
         * The image id.
         */
		uint32 _imageId;

		// image types

        /**
         * The OpenIL loader.
		 *
		 * @return true if the file was loaded
         */
		bool openDevil();
	};
}

#endif