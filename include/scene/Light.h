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

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <scene/Transformation.h>
#include <math/Vector3.h>
#include <scene/ColorRGBA.h>


namespace scene
{
    /**
     * @brief
     * This is the Light class.
     */
	class API_STATE Light : public Transformation
	{
	public:
		enum E_LIGHT_TYPE
		{
			LT_POINT = 0,
			LT_SPOT,
			LT_DIRECTIONAL
		};

        /**
         * Constructor
         */
		Light();

        /**
         * Destructor
         */
		virtual ~Light() { }

        /**
         * Set the light direction
         *
		 * @param direction The direction value
         */
		void setDirection(const math::Vector3f &direction);

        /**
         * Set the ambient color
         *
		 * @param ambient The ambient value
         */
		void setAmbient(const ColorRGBA &ambient);

        /**
         * Set the diffuse color
         *
		 * @param diffuse The diffuse value
         */
		void setDiffuse(const ColorRGBA &diffuse);

        /**
         * Set the specular color
         *
		 * @param specular The specular value
         */
		void setSpecular(const ColorRGBA &specular);

        /**
         * Set the spot parameters
         *
		 * @param exponent The exponent value
		 * @param cutOff The cutOff value
         */
		void setSpotParams(float32 exponent, float32 cutOff);

        /**
         * Set the light type
         *
		 * @param eType The light type
         */
		void setLightType(E_LIGHT_TYPE eType);

        /**
         * Get the direction
         *
		 * @return The direction
         */
		const math::Vector3f &getDirection();

        /**
         * Get the ambient color
         *
		 * @return The color
         */
		const ColorRGBA &getAmbient();

        /**
         * Get the diffuse color
         *
		 * @return The color
         */
		const ColorRGBA &getDiffuse();

        /**
         * Get the specular color
         *
		 * @return The color
         */
		const ColorRGBA &getSpecular();

        /**
         * Get the light type
         *
		 * @return The light type
         */
		E_LIGHT_TYPE getLightType();

        /**
         * Get the ambient color
         *
		 * @param exponent The exponent value
		 * @param cutOff The cutOff value
         */
		void getSpotParams(float32 &exponent, float32 &cutOff);

        /**
         * Enable the light
         *
		 * @param value Set to enable the light
         */
		void setEnable(bool value);

		/**
         * Verify if the light is enabled
         *
		 * @return True if enabled
         */
		bool isEnabled();

        /**
         * Set the light number
         *
		 * @param number Set to light number
         */
		void setLightNumber(uint32 number);

		/**
         * Get the light number
         *
		 * @return the light number
         */
		uint32 getLightNumber();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Light";}

	private:
		/**
         * The light direction
         */
		math::Vector3f _direction;

		/**
         * The ambient color
         */
		ColorRGBA _ambient;

		/**
         * The diffuse color
         */
		ColorRGBA _diffuse;

		/**
         * The specular color
         */
		ColorRGBA _specular;

		/**
         * The exponent value
         */
		float32 _exponent;

		/**
         * The cutoff value
         */
		float32 _cutOff;

		/**
         * Used to enable the light
         */
		bool _enabled;

		/**
         * The light type
         */
		E_LIGHT_TYPE _eType;

		/**
         * The light number
         */
		uint32 _number;
	};

#include <scene/Light.inl>

}

#endif