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

#ifndef __ALPHAPROPERTY_H__
#define __ALPHAPROPERTY_H__

#include <scene/property/Property.h>

namespace scene
{
    /**
     * @brief
     * This is the Alpha property class.
     */
	class API_STATE AlphaProperty : public Property
	{
	public:
		/**
		 * The Alpha properties.
		 */
		enum E_BLEND_FUNCTION
		{
			BF_ZERO = 0,
			BF_ONE,
			BF_DST_COLOR,
			BF_SRC_ALPHA,
			BF_DST_ALPHA,
			BF_ONE_MINUS_DST_COLOR,
			BF_ONE_MINUS_SRC_ALPHA,
			BF_ONE_MINUS_DST_ALPHA,
			BF_SRC_ALPHA_SATURATE,
			BF_SRC_COLOR,
			BF_ONE_MINUS_SRC_COLOR
		};

        /**
         * Constructor
         */
		AlphaProperty();

        /**
         * Destructor
         */
		virtual ~AlphaProperty(){}

        /**
         * Set the source alpha property
         *
		 * @param eValue The property value
         */
		void setSourceFunction(E_BLEND_FUNCTION eValue);

        /**
         * Set the destination alpha property
         *
		 * @param eValue The property value
         */
		void setDestinationFunction(E_BLEND_FUNCTION eValue);

        /**
         * Set the source and destination alpha property
         *
		 * @param eSrc The source property value
		 * @param eDest The destination property value
         */
		void setSrcAndDestFunction(E_BLEND_FUNCTION eSrc, E_BLEND_FUNCTION eDest);

        /**
         * Get the source alpha property
         *
		 * @return The property
         */
		E_BLEND_FUNCTION getSourceFunction();

        /**
         * Get the destination alpha property
         *
		 * @return The property
         */
		E_BLEND_FUNCTION getDestinationFunction();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: AlphaProperty";}

	private:
		/**
		 * The source value
		 */
		E_BLEND_FUNCTION _eSourceValue;

		/**
		 * The destination value
		 */
		E_BLEND_FUNCTION _eDestinationValue;
	};

#include <scene/property/AlphaProperty.inl>
}

#endif