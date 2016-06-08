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

#ifndef MATH_MATRIX_H_
#define MATH_MATRIX_H_

#include <math/Vector3.h>

namespace math
{
    /**
     * @brief
   	 * The Matrix Class.
   	 */
    class API_STATE Matrix : public Object
    {
    public:
        float32 m[4][4]; //!< matrix elements

        /**
         * Constructor
         */
        Matrix();

        /**
         * Copy-Constructor
         * 
         * @param in Matrix reference
         */
        Matrix(const Matrix& in);

        /**
         * Destructor
         */
        ~Matrix();

        /**
         * Reset all elements
         */
        void reset();

        /**
         * Load the identity matrix
         */
        void loadIdentity();

        /**
         * Set the matrix as the rotation matrix of angle given by 'ang' around direction 'dir'
         * 
         * @param ang Angle
         * @param dir Direction
         */
        void setRotation(float32 ang, const Vector3f& dir);

        /**
         * Multiply the matrix by another with rotation given by 'ang' around direction 'dir'
         * 
         * @param and Angle
         * @param dir Direction
         */
        void rotate( float32 ang, const Vector3f& dir );

        /**
         * Interpolate between two rotation matrices using quaternions
         * 
         * @param matrix1 The first matrix
         * @param matrix2 The second matrix
         * @param interValue Interpolation value
         */
        void lerp(const Matrix& matrix1, const Matrix& matrix2, float32 interValue);

        /**
         * Atribuition operator
         * 
         * @param in Matrix reference
         */
        void operator=(const Matrix& in);

        /**
         * Multiplication operator
         * 
         * @param in The matrix reference
         */
        Matrix operator*(const Matrix& in) const;

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Matrix";}
    };
} //namespace
#endif
