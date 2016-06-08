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

#ifndef __TEXTUREPROPERTY_H__
#define __TEXTUREPROPERTY_H__

#include <scene/property/Property.h>

namespace scene
{
    /**
     * @brief
     * This is the Texture property class.
     */
	class API_STATE TextureProperty : public Property
	{
	public:
        /**
         * Constructor
         */
		TextureProperty();

        /**
         * Destructor
         */
		virtual ~TextureProperty(){}

        /**
         * Set the texture data
         *
		 * @param data The texture data
         */
		void setTextureData(const void * data);

        /**
         * Set the texture width
         *
		 * @param value The texture width
         */
		void setWidth(uint32 value);

        /**
         * Set the texture height
         *
		 * @param value The texture height
         */
		void setHeight(uint32 value);

        /**
         * Set the texture format
         *
		 * @param value The texture format
         */
		void setFormat(uint32 value);

        /**
         * Set the texture channels
         *
		 * @param value The texture channels
         */
		void setChannels(uint32 value);

        /**
         * Get the texture data
         *
		 * @return The texture data
         */
		const void * getTextureData();

        /**
         * Get the texture width
         *
		 * @return The texture witdh
         */
		uint32 getWidth();

        /**
         * Get the texture height
         *
		 * @return The texture height
         */
		uint32 getHeight();

        /**
         * Get the texture format
         *
		 * @return The texture format
         */
		uint32 getFormat();

        /**
         * Get the texture channels
         *
		 * @return The texture channels
         */
		uint32 getChannels();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: TextureProperty";}

	private:
		/**
		 * The texture data
		 */
		void * _textureData;

		/**
		 * The texture width
		 */
		uint32 _width;

		/**
		 * The texture height
		 */
		uint32 _height;

		/**
		 * The texture format
		 */
		uint32 _format;

		/**
		 * The texture channels
		 */
		uint32 _channels;
	};

#include <scene/property/TextureProperty.inl>

}

#endif