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

#ifndef __VECTOR4__
#define __VECTOR4__

#include <util/Log.h>
#include <util/Object.h>

namespace math
{
    /**
     * @brief
     * The vector4 class.
     */
	template <class T>
	class API_STATE Vector4 : public Object
	{
	public:
        /**
         * Predefined vector property
         */
		static const Vector4 UNIT_ZERO;
		static const Vector4 UNIT_ONE;
		static const Vector4 UNIT_X;
		static const Vector4 UNIT_Y;
		static const Vector4 UNIT_Z;
		static const Vector4 UNIT_W;

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
         * w value
         */
		T w;

        /**
         * Constructor
         */
		Vector4();

        /**
         * Constructor
         */
		Vector4(T x, T y, T z, T w);

        /**
         * Vectors comparison
         * 
         * @param vector The outside vector
		 * @return result
         */
		bool operator== (const Vector4& vector) const;
		bool operator!= (const Vector4& vector) const;
		bool operator<  (const Vector4& vector) const;
		bool operator<= (const Vector4& vector) const;
		bool operator>  (const Vector4& vector) const;
		bool operator>= (const Vector4& vector) const;

        /**
         * Vectors operation
         * 
         * @param vector The outside vector
		 * @return the vector result
         */
		Vector4<T> operator+ (const Vector4& vector) const;
		Vector4<T> operator- (const Vector4& vector) const;
		Vector4<T> operator* (T value) const;
		Vector4<T> operator/ (T value) const;

        /**
         * Vectors attribution
         * 
         * @param vector The outside vector
		 * @return the vector result
         */
		Vector4<T>& operator+= (const Vector4& vector);
		Vector4<T>& operator-= (const Vector4& vector);
		Vector4<T>& operator*= (T value);
		Vector4<T>& operator/= (T value);

		/**
         * Negate the vector values
         * 
		 * @return the vector result
         */
		Vector4<T> negative() const;

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Vector4";}
	};

	typedef Vector4<float> Vector4f;
}

#endif