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

#ifndef MATH_QUAT_H_
#define MATH_QUAT_H_

#include <math/Vector3.h>
#include <math/Matrix.h>

namespace math
{
	/**
	 * @brief
 	 * The Quaternion Class.
 	 */
	class API_STATE Quaternion
    {
    public:
        /**
         * Constructor
         */
        Quaternion();

        /**
         * Constructor
         * 
         * @param angle The angle
         * @param axis The vector axis
         */
        Quaternion(float32 angle, const Vector3f &axis);

        /**
         * Copy Constructor
         * 
         * @param rIn The quaternion reference
         */
        Quaternion(const Quaternion &rIn);

        /**
         * Copy Constructor
         * 
         * @param rIn The matrix reference
         */
        Quaternion(const Matrix &rIn);

        /**
         * Normalize the quaternion
         */
        void normalize();

        /**
         * Converts the quaternion into a matrix
         * 
         * @param rMat The matrix reference
         */
        void getMatrix(Matrix &rMat) const;

        /**
         * Get the rotation angle and axis
         * 
         * @param rAngle The angle reference
         * @param rAxis the axis reference
         */
        void getRotate(float32 &rAngle, Vector3f &rAxis) const;

        /**
         * Interpolate two quaternions
         * 
         * @param q1 The first quaternion
         * @param q2 The second quaternion
         * @param interValue The interpolation value
         */
        void lerp(const Quaternion& q1, const Quaternion& q2, float32 interValue);

        /**
         * Multiplication between quaternions
         * 
         * @param q The quaternion reference
         */
        Quaternion operator * (const Quaternion& q);

        /**
         * Addition between quaternions
         * 
         * @param q The quaternion reference
         */
        Quaternion operator + (const Quaternion& q);

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Quaternion";}

	private:
		float32 x,y,z,w;
    };
}//namespace
#endif
