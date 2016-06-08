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

#ifndef __VECTOR3__
#define __VECTOR3__

#include <util/Log.h>
#include <util/Object.h>

namespace math
{
    /**
     * @brief
     * The vector3 class.
     */
	template <class T>
	class API_STATE Vector3 : public Object
	{
	public:
        /**
         * Predefined vector property
         */
		static const Vector3 UNIT_ZERO;
		static const Vector3 UNIT_ONE;
		static const Vector3 UNIT_X;
		static const Vector3 UNIT_Y;
		static const Vector3 UNIT_Z;

        /**
         * x value
         */
		T x;

		/**
         * y value
         */
		T y;

		/**
         * z value
         */
		T z;

        /**
         * Constructor
         */
		Vector3();

		/**
         * Constructor
         */
		Vector3(T x, T y, T z);

        /**
         * Vectors comparison
         * 
         * @param vector The outside vector
		 * @return result
         */
		bool operator== (const Vector3& vector) const;
		bool operator!= (const Vector3& vector) const;
		bool operator<  (const Vector3& vector) const;
		bool operator<= (const Vector3& vector) const;
		bool operator>  (const Vector3& vector) const;
		bool operator>= (const Vector3& vector) const;

        /**
         * Vectors operation
         * 
         * @param vector The outside vector
		 * @return the vector result
         */
		Vector3<T> operator+ (const Vector3& vector) const;
		Vector3<T> operator- (const Vector3& vector) const;
		Vector3<T> operator* (T value) const;
		Vector3<T> operator/ (T value) const;

        /**
         * Vectors attribution
         * 
         * @param vector The outside vector
		 * @return the vector result
         */
		Vector3<T>& operator+= (const Vector3& vector);
		Vector3<T>& operator-= (const Vector3& vector);
		Vector3<T>& operator*= (T value);
		Vector3<T>& operator/= (T value);

		/**
         * Negate the vector values
         * 
		 * @return the vector result
         */
		Vector3<T> negative() const;

		/**
         * Normalize the vector values
         */
		void normalize();

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Vector3";}
	};

	typedef Vector3<float> Vector3f;
}

#endif