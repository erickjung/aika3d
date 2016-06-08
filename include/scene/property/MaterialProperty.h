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

#ifndef __MATERIALPROPERTY_H__
#define __MATERIALPROPERTY_H__

#include <scene/property/Property.h>
#include <scene/ColorRGBA.h>

namespace scene
{
    /**
     * @brief
     * This is the Material property class.
     */
	class API_STATE MaterialProperty : public Property
	{
	public:
        /**
         * Constructor
         */
		MaterialProperty();

        /**
         * Destructor
         */
		virtual ~MaterialProperty(){}

        /**
         * Set the emissive material
         *
		 * @param emissive The color value
         */
		void setEmissive(ColorRGBA &emissive);

        /**
         * Set the ambient material
         *
		 * @param ambient The color value
         */
		void setAmbient(ColorRGBA &ambient);

        /**
         * Set the diffuse material
         *
		 * @param diffuse The color value
         */
		void setDiffuse(ColorRGBA &diffuse);

        /**
         * Set the specular material
         *
		 * @param specular The color value
         */
		void setSpecular(ColorRGBA &specular);

        /**
         * Set the shininess material
         *
		 * @param shininess The color value
         */
		void setShininess(float32 shininess);

        /**
         * Set the alpha value
         *
		 * @param value The alpha value
         */
		void setAlphaValue(float32 value);

        /**
         * Get the emissive material
         *
		 * @return The material
         */
		const ColorRGBA &getEmissive();

        /**
         * Get the ambient material
         *
		 * @return The material
         */
		const ColorRGBA &getAmbient();

        /**
         * Get the diffuse material
         *
		 * @return The material
         */
		const ColorRGBA &getDiffuse();

        /**
         * Get the specular material
         *
		 * @return The material
         */
		const ColorRGBA &getSpecular();

        /**
         * Get the shininess material
         *
		 * @return The material
         */
		float32 getShininess();

        /**
         * Get the alpha value
         *
		 * @return The material
         */
		float32 getAlphaValue();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: MaterialProperty";}

	private:
		/**
		 * The emissive value
		 */
		ColorRGBA _emissive;

		/**
		 * The ambient value
		 */
		ColorRGBA _ambient;

		/**
		 * The diffuse value
		 */
		ColorRGBA _diffuse;

		/**
		 * The specular value
		 */
		ColorRGBA _specular;

		/**
		 * The shininess value
		 */
		float32 _shininess;

		/**
		 * The alpha value
		 */
		float32 _alphaValue;
	};

#include <scene/property/MaterialProperty.inl>
}

#endif