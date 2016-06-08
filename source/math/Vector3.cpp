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

#include <math.h>
#include <math/Vector3.h>

namespace math
{
	template class API_STATE Vector3<float>;
	const Vector3f Vector3f::UNIT_ZERO(0.0f,0.0f,0.0f);
	const Vector3f Vector3f::UNIT_ONE(1.0f,1.0f,1.0f);
	const Vector3f Vector3f::UNIT_X(1.0f,0.0f,0.0f);
	const Vector3f Vector3f::UNIT_Y(0.0f,1.0f,0.0f);
	const Vector3f Vector3f::UNIT_Z(0.0f,0.0f,1.0f);

	template <class T>
	Vector3<T>::Vector3() : x(0), y(0), z(0)
	{
	}

	template <class T>
	Vector3<T>::Vector3(T x, T y, T z) :
	x(x), y(y), z(z)
	{
	}

	template <class T>
	bool Vector3<T>::operator== (const Vector3& vector) const
	{
		if(x == vector.x && y == vector.y && z == vector.z)
			return true;

		return false;
	}

	template <class T>
	bool Vector3<T>::operator!= (const Vector3& vector) const
	{
		if(x == vector.x && y == vector.y && z == vector.z)
			return false;

		return true;
	}

	template <class T>
	bool Vector3<T>::operator<  (const Vector3& vector) const
	{
		if(x < vector.x || y < vector.y || z < vector.z)
			return true;

		return false;
	}

	template <class T>
	bool Vector3<T>::operator<= (const Vector3& vector) const
	{
		if(x <= vector.x || y <= vector.y || z <= vector.z)
			return true;

		return false;
	}

	template <class T>
	bool Vector3<T>::operator>  (const Vector3& vector) const
	{
		if(x > vector.x || y > vector.y || z > vector.z)
			return true;

		return false;
	}

	template <class T>
	bool Vector3<T>::operator>= (const Vector3& vector) const
	{
		if(x >= vector.x || y >= vector.y || z >= vector.z)
			return true;

		return false;
	}

	template <class T>
	Vector3<T> Vector3<T>::operator+ (const Vector3& vector) const
	{
		Vector3<T> tempVec;
		tempVec.x = x + vector.x;
		tempVec.y = y + vector.y;
		tempVec.z = z + vector.z;
		return tempVec;
	}

	template <class T>
	Vector3<T> Vector3<T>::operator- (const Vector3& vector) const
	{
		Vector3<T> tempVec;
		tempVec.x = x - vector.x;
		tempVec.y = y - vector.y;
		tempVec.z = z - vector.z;
		return tempVec;
	}

	template <class T>
	Vector3<T> Vector3<T>::operator* (T value) const
	{
		Vector3<T> tempVec;
		tempVec.x = value * x;
		tempVec.y = value * y;
		tempVec.z = value * z;
		return tempVec;
	}

	template <class T>
	Vector3<T> Vector3<T>::operator/ (T value) const
	{
		Vector3<T> tempVec;
		tempVec.x = value / x;
		tempVec.y = value / y;
		tempVec.z = value / z;
		return tempVec;
	}

	template <class T>
	Vector3<T> Vector3<T>::negative() const
	{
		Vector3<T> tempVec;
		tempVec.x = -x;
		tempVec.y = -y;
		tempVec.z = -z;
		return tempVec;
	}

	template <class T>
	Vector3<T>& Vector3<T>::operator+= (const Vector3& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		return *this;
	}

	template <class T>
	Vector3<T>& Vector3<T>::operator-= (const Vector3& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		return *this;
	}

	template <class T>
	Vector3<T>& Vector3<T>::operator*= (T value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	template <class T>
	Vector3<T>& Vector3<T>::operator/= (T value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	template <class T>
	void Vector3<T>::normalize()
    {
        float32 f = (float32)sqrt(x*x + y*y + z*z);

        if (f != 0.0f)
        {
            x /= f;
            y /= f;
            z /= f;
        }
    }
}
