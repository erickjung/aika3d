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

inline void Light::setDirection(const math::Vector3f &direction)
{
	_direction = direction;
}

inline void Light::setAmbient(const ColorRGBA &ambient)
{
	_ambient = ambient;
}

inline void Light::setDiffuse(const ColorRGBA &diffuse)
{
	_diffuse = diffuse;
}

inline void Light::setSpecular(const ColorRGBA &specular)
{
	_specular = specular;
}

inline void Light::setLightType(E_LIGHT_TYPE eType)
{
	_eType = eType;
}

inline void Light::setSpotParams(float32 exponent, float32 cutOff)
{
	// exponent need to be no more than 180.0f
	// cutoff need to be no more than 90.0f
	_exponent = exponent;
	_cutOff = cutOff;
}

inline const math::Vector3f &Light::getDirection()
{
	return _direction;
}

inline const ColorRGBA &Light::getAmbient()
{
	return _ambient;
}

inline const ColorRGBA &Light::getDiffuse()
{
	return _diffuse;
}

inline const ColorRGBA &Light::getSpecular()
{
	return _specular;
}

inline Light::E_LIGHT_TYPE Light::getLightType()
{
	return _eType;
}

inline void Light::getSpotParams(float32 &exponent, float32 &cutOff)
{
	exponent = _exponent;
	cutOff = _cutOff;
}

inline void Light::setEnable(bool value)
{
	_enabled = value;
}

inline bool Light::isEnabled()
{
	return _enabled;
}

inline void Light::setLightNumber(uint32 number)
{
	_number = number;
}

inline uint32 Light::getLightNumber()
{
	return _number;
}
