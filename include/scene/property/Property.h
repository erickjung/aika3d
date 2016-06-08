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

#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <util/Object.h>
#include <util/Log.h>

namespace scene
{
    /**
     * @brief
     * This is the property class.
     */
	class API_STATE Property : public Object
	{
	public:
		/**
		 * The properties type.
		 */
		enum E_PROPERTY_TYPE
		{
			PT_UNKNOWN = 0,
			PT_ALPHA,
			PT_MATERIAL,
			PT_TEXTURE,
			PT_CULL
		};

        /**
         * Constructor
		 *
		 * @param type The property type
         */
		Property(E_PROPERTY_TYPE type = PT_UNKNOWN);

        /**
         * Destructor
         */
		virtual ~Property(){}
		
        /**
         * Get the property type
         *
		 * @return The property
         */
		E_PROPERTY_TYPE getType();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Property";}

	private:
		/**
		 * The property value
		 */
		E_PROPERTY_TYPE _type;
	};

#include <scene/property/Property.inl>

}

#endif