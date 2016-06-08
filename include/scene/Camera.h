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

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <scene/Transformation.h>
#include <math/Vector3.h>


namespace scene
{
    /**
     * @brief
     * This is the Camera class.
     */
	class API_STATE Camera : public Transformation
	{
	public:
        /**
         * Constructor
         */
		Camera();

        /**
         * Destructor
         */
		virtual ~Camera() { }

        /**
         * Initialize the camera properties
		 *
		 * @note Use this method before use the camera
         */
		void initialize();

        /**
         * Set the up vector
         *
		 * @param upVector The up vector value
         */
		void setUpVector(const math::Vector3f &upVector);

        /**
         * Set the camera perspective
         *
		 * @param fovValue The fov value
		 * @param nearValue The near value
		 * @param farValue The far value
         */
		void setPerspective(float32 fovValue, float32 nearValue, float32 farValue);

        /**
         * Enable the camera
         *
		 * @param value Set to enable the camera
         */
		void setEnable(bool value);

		/**
         * Verify if the camera is enabled
         *
		 * @return True if enabled
         */
		bool isEnabled();

		/**
         * Update the camera data
         */
		void update();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Camera";}

	private:
		/**
         * Used to enable the camera
         */
		bool _enabled;

		/**
         * The fov value
         */
		float32 _fovValue;

		/**
         * The far value
         */
		float32 _farValue;

		/**
         * The near value
         */
		float32 _nearValue;

		/**
         * The upvector value
         */
		math::Vector3f _upVector;
	};

#include <scene/Camera.inl>
}

#endif