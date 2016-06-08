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

#include <scene/Mesh.h>
#include <util/Assert.h>
#include <core/Device.h>

namespace scene
{
	Mesh::Mesh() : _imageId(0), _hasTexture(false), _hasMaterial(false)
    {
		TRACE("Mesh::Mesh");
    }

    Mesh::~Mesh()
    {
    }

    void Mesh::load(const String &filename)
    {
		TRACE("Mesh::load");

        assert(filename.length() > 0);

		//filename.clearChars(core::Device::getDataPath().length());
  //      String strTemp = filename.substring(filename.findChar('.')+1, filename.length());
		
        String strTemp = filename;
		strTemp.clearChars(core::Device::getDataPath().length());
		strTemp = strTemp.substring(strTemp.findChar('.')+1, strTemp.length());

		_filename = filename;
        if(strTemp.equals(String("akg")))
        {
			openAkg();
        }
    }

	void Mesh::draw(render::Render *pRender)
	{
		if(_hasTexture)
			pRender->bindImage(_imageId);

		pRender->setFeatureStatus(render::FT_CULL_FACE, true);
		pRender->setFeatureStatus(render::FT_DEPTH_TEST, true);

		if(_hasMaterial)
		{
			pRender->setMaterialProperty(&_materialProperty);

			if(_materialProperty.getAlphaValue() < 1.0f)
			{
				pRender->setFeatureStatus(render::FT_BLEND, true);
				pRender->setAlphaProperty(&_alphaProperty);

				_cullProperty.setCullType(CullProperty::CT_BACK);
				pRender->drawList(_listId, &_cullProperty);

				pRender->setFeatureStatus(render::FT_BLEND, false);
			}
			else
			{
				_cullProperty.setCullType(CullProperty::CT_BACK);
				pRender->drawList(_listId, &_cullProperty);
			}
		}
		else
			pRender->drawList(_listId);

	}
}