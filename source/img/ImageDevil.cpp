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

#include <img/Image.h>
#include <scene/Node.h>
#include <scene/property/TextureProperty.h>
#include <core/Device.h>


#include <IL/il.h>
#include <IL/ilu.h>

namespace img
{
	bool Image::openDevil()
	{
		TRACE("Image::openDevil");

		bool result = false;

		ILuint imageId;

		ilInit();

		// opengl lower coord, opposite to directx
		ilEnable(IL_ORIGIN_SET);
		ilOriginFunc(IL_ORIGIN_LOWER_LEFT); 

		ilGenImages(1, &imageId);
		ilBindImage(imageId);

		if(!ilLoadImage(_filename.getChars()))
            return false;

		ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

		scene::TextureProperty textureProperty;
		textureProperty.setChannels(ilGetInteger(IL_IMAGE_CHANNELS));
		textureProperty.setWidth(ilGetInteger(IL_IMAGE_WIDTH));
		textureProperty.setHeight(ilGetInteger(IL_IMAGE_HEIGHT));
		textureProperty.setFormat(ilGetInteger(IL_IMAGE_FORMAT));
		textureProperty.setTextureData(ilGetData());

		_imageId = core::Device::getRenderInstance()->setTextureProperty(&textureProperty);

		ilDeleteImages(1, &imageId); 
		ilShutDown();


		return result;
	}
}