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

#include <math/Vector4.h>

namespace math
{
	template class API_STATE Vector4<float>;
	const Vector4f Vector4f::UNIT_ZERO(0.0f,0.0f,0.0f,0.0f);
	const Vector4f Vector4f::UNIT_ONE(1.0f,1.0f,1.0f,1.0f);
	const Vector4f Vector4f::UNIT_X(1.0f,0.0f,0.0f,0.0f);
	const Vector4f Vector4f::UNIT_Y(0.0f,1.0f,0.0f,0.0f);
	const Vector4f Vector4f::UNIT_Z(0.0f,0.0f,1.0f,0.0f);
	const Vector4f Vector4f::UNIT_W(0.0f,0.0f,0.0f,1.0f);

	template <class T>
	Vector4<T>::Vector4() : x(0), y(0), z(0), w(0)
	{
	}

	template <class T>
	Vector4<T>::Vector4(T x, T y, T z, T w) :
	x(x), y(y), z(z), w(w)
	{
	}

	template <class T>
	bool Vector4<T>::operator== (const Vector4& vector) const
	{
		if(x == vector.x && y == vector.y && z == vector.z && w == vector.w)
			return true;

		return false;
	}

	template <class T>
	bool Vector4<T>::operator!= (const Vector4& vector) const
	{
		if(x == vector.x && y == vector.y && z == vector.z && w == vector.w)
			return false;

		return true;
	}

	template <class T>
	bool Vector4<T>::operator<  (const Vector4& vector) const
	{
		if(x < vector.x || y < vector.y || z < vector.z)
			return true;

		return false;
	}

	template <class T>
	bool Vector4<T>::operator<= (const Vector4& vector) const
	{
		if(x <= vector.x || y <= vector.y || z <= vector.z || w <= vector.w)
			return true;

		return false;
	}

	template <class T>
	bool Vector4<T>::operator>  (const Vector4& vector) const
	{
		if(x > vector.x || y > vector.y || z > vector.z || w > vector.w)
			return true;

		return false;
	}

	template <class T>
	bool Vector4<T>::operator>= (const Vector4& vector) const
	{
		if(x >= vector.x || y >= vector.y || z >= vector.z || w >= vector.w)
			return true;

		return false;
	}

	template <class T>
	Vector4<T> Vector4<T>::operator+ (const Vector4& vector) const
	{
		Vector4<T> tempVec;
		tempVec.x = x + vector.x;
		tempVec.y = y + vector.y;
		tempVec.z = z + vector.z;
		tempVec.w = w + vector.w;
		return tempVec;
	}

	template <class T>
	Vector4<T> Vector4<T>::operator- (const Vector4& vector) const
	{
		Vector4<T> tempVec;
		tempVec.x = x - vector.x;
		tempVec.y = y - vector.y;
		tempVec.z = z - vector.z;
		tempVec.w = w - vector.w;
		return tempVec;
	}

	template <class T>
	Vector4<T> Vector4<T>::operator* (T value) const
	{
		Vector4<T> tempVec;
		tempVec.x = value * x;
		tempVec.y = value * y;
		tempVec.z = value * z;
		tempVec.w = value * w;
		return tempVec;
	}

	template <class T>
	Vector4<T> Vector4<T>::operator/ (T value) const
	{
		Vector4<T> tempVec;
		tempVec.x = value / x;
		tempVec.y = value / y;
		tempVec.z = value / z;
		tempVec.w = value / w;
		return tempVec;
	}

	template <class T>
	Vector4<T> Vector4<T>::negative() const
	{
		Vector4<T> tempVec;
		tempVec.x = -x;
		tempVec.y = -y;
		tempVec.z = -z;
		tempVec.w = -w;
		return tempVec;
	}

	template <class T>
	Vector4<T>& Vector4<T>::operator+= (const Vector4& vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
		w += vector.w;
		return *this;
	}

	template <class T>
	Vector4<T>& Vector4<T>::operator-= (const Vector4& vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
		w -= vector.w;
		return *this;
	}

	template <class T>
	Vector4<T>& Vector4<T>::operator*= (T value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	template <class T>
	Vector4<T>& Vector4<T>::operator/= (T value)
	{
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

}
