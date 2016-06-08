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

#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <util/Object.h>
#include <math/Vector3.h>


namespace scene
{
    /**
     * @brief
     * This is the Transformation class.
     */
	class API_STATE Transformation : public Object
	{
	public:
        /**
         * Constructor
         */
		Transformation();

        /**
         * Destructor
         */
		virtual ~Transformation() { }

        /**
         * Set the translation
         *
		 * @param translate The translation value
         */
		void setTranslation(const math::Vector3f &translate);

        /**
         * Set the target
         *
		 * @param target The target value
         */
		void setTarget(const math::Vector3f &target);

        /**
         * Set the rotation
         *
		 * @param rotateAngle The rotate angle
		 * @param rotate The rotate 
         */
		void setRotation(float rotateAngle, const math::Vector3f &rotate);

        /**
         * Set the scale
         *
		 * @param scale The scale
         */
		void setScale(math::Vector3f);

        /**
         * Get the translation
         *
		 * @return The translation
         */
		const math::Vector3f &getTranslation();

        /**
         * Get the rotation
         *
		 * @param rotateAngle Return the rotate angle
		 * @param rotate Return the rotate 
         */
		void getRotation(float &rotateAngle, math::Vector3f &rotate);

        /**
         * Get target
         *
		 * @return The scale
         */
		const math::Vector3f &getTarget();

		/**
         * Get scale
         *
		 * @return The scale
         */
		const math::Vector3f &getScale();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Transformation";}

	protected:
		/**
         * The translation value
         */
		math::Vector3f _translate;

		/**
         * The target value
         */
		math::Vector3f _target;

		/**
         * The rotation
         */
		math::Vector3f _rotate;

		/**
         * The rotate angle
         */
		float _rotateAngle;

		/**
         * The scale
         */
		math::Vector3f _scale;
	};

#include <scene/Transformation.inl>
}

#endif