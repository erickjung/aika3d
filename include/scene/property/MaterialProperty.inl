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

inline void MaterialProperty::setEmissive(ColorRGBA &emissive)
{
	_emissive = emissive;
}

inline void MaterialProperty::setAmbient(ColorRGBA &ambient)
{
	_ambient = ambient;
}

inline void MaterialProperty::setDiffuse(ColorRGBA &diffuse)
{
	_diffuse = diffuse;
}

inline void MaterialProperty::setSpecular(ColorRGBA &specular)
{
	_specular = specular;
}

inline void MaterialProperty::setShininess(float32 shininess)
{
	_shininess = shininess;
}

inline void MaterialProperty::setAlphaValue(float32 value)
{
	_alphaValue = value;
}

inline const ColorRGBA &MaterialProperty::getEmissive()
{
	return _emissive;
}

inline const ColorRGBA &MaterialProperty::getAmbient()
{
	return _ambient;
}

inline const ColorRGBA &MaterialProperty::getDiffuse()
{
	return _diffuse;
}

inline const ColorRGBA &MaterialProperty::getSpecular()
{
	return _specular;
}

inline float32 MaterialProperty::getShininess()
{
	return _shininess;
}

inline float32 MaterialProperty::getAlphaValue()
{
	return _alphaValue;
}
