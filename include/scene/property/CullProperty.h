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

#ifndef __CULLPROPERTY_H__
#define __CULLPROPERTY_H__

#include <scene/property/Property.h>

namespace scene
{
    /**
     * @brief
     * This is the Cull property class.
     */
	class API_STATE CullProperty : public Property
	{
	public:
		/**
		 * The Cull properties.
		 */
		enum E_CULL_TYPE
		{
			CT_FRONT = 0,
			CT_BACK
		};

		enum E_FACE_TYPE
		{
			FT_CLOCKWISE = 0,
			FT_COUNTERCLOCKWISE
		};

		/**
         * Constructor
         */
		CullProperty();

        /**
         * Destructor
         */
		virtual ~CullProperty(){}

        /**
         * Set the cull property
         *
		 * @param eValue The property value
         */
		void setCullType(E_CULL_TYPE eValue);

        /**
         * Get the cull property
         *
		 * @return The property
         */
		E_CULL_TYPE getCullType();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: CullProperty";}

	private:
		/**
		 * The cull value
		 */
		E_CULL_TYPE _eValue;
	};

#include <scene/property/CullProperty.inl>
}

#endif