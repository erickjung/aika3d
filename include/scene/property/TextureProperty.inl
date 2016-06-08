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

inline void TextureProperty::setTextureData(const void *data)
{
	_textureData = (void *)data;
}

inline void TextureProperty::setWidth(uint32 value)
{
	_width = value;
}

inline void TextureProperty::setHeight(uint32 value)
{
	_height = value;
}

inline void TextureProperty::setFormat(uint32 value)
{
	_format = value;
}

inline void TextureProperty::setChannels(uint32 value)
{
	_channels = value;
}

inline const void * TextureProperty::getTextureData()
{
	return _textureData;
}

inline uint32 TextureProperty::getWidth()
{
	return _width;
}

inline uint32 TextureProperty::getHeight()
{
	return _height;
}

inline uint32 TextureProperty::getFormat()
{
	return _format;
}

inline uint32 TextureProperty::getChannels()
{
	return _channels;
}
