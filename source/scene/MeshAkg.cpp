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
#include <scene/Node.h>
#include <ioAkg/ioAkg.h>

namespace scene
{
	bool Mesh::openAkg()
	{
		TRACE("Mesh::openAkg");

		ioAkg file;
		GeometryData geometry;
		bool result = file.openFile(_filename.getChars(), geometry);

		if(!result)
			return result;


		_vertexList.reserve(geometry.indicesSize);
		_normalList.reserve(geometry.indicesSize);
		_texList.reserve(geometry.indicesSize);

		for (uint32 i=0; i<geometry.indicesSize; i++) 
		{
			uint32 index= geometry.vertex.vertexIndices[i];

			// vertex list
			const float32 *p= &geometry.vertex.vertexData[index*3];
			math::Vector3f vec(p[0], p[1], p[2]);
			//_vertexList.push_back(vec);
			_vertexList.add(vec);

			// normal list
			index= geometry.normal.normalIndices[i];
			p= &geometry.normal.normalData[index*3];
			math::Vector3f vec1(p[0], p[1], p[2]);
			//_normalList.push_back(vec1);
			_normalList.add(vec1);

			// texture list
			if(geometry.texture.imageQuantity > 0)
			{
				index= geometry.texture.textureIndices[i];
				p= &geometry.texture.textureData[index*2];
				math::Vector3f vec2(p[0], p[1], 0.0f);
				//_texList.push_back(vec2);
				_texList.add(vec2);
			}
		}

		render::Render *pRender = core::Device::getRenderInstance();
		_listId = pRender->indexDataList(
			geometry.indicesSize,
			_vertexList, 
			_normalList, 
			_texList);

		if(geometry.texture.imageQuantity > 0)
		{
			_hasTexture = true;

			lang::String tmpStr = core::Device::getDataPath();
			tmpStr.concat(geometry.texture.textureFileName.c_str());

			result = textureImage.load(tmpStr, _imageId);
		}

		for(uint32 i = 0; i < geometry.material.materialQuantity; i++)
		{
			_hasMaterial = true;

			_materialProperty.setAlphaValue(geometry.material.materialData[i].transparence);

			_materialProperty.setDiffuse(ColorRGBA(
				geometry.material.materialData[i].diffuse.x,
				geometry.material.materialData[i].diffuse.y,
				geometry.material.materialData[i].diffuse.z,
				geometry.material.materialData[i].transparence));

			_materialProperty.setSpecular(ColorRGBA(
				geometry.material.materialData[i].specular.x,
				geometry.material.materialData[i].specular.y,
				geometry.material.materialData[i].specular.z,
				geometry.material.materialData[i].specular.w));

			_materialProperty.setAmbient(ColorRGBA(
				geometry.material.materialData[i].ambient.x,
				geometry.material.materialData[i].ambient.y,
				geometry.material.materialData[i].ambient.z,
				geometry.material.materialData[i].ambient.w));

			_materialProperty.setEmissive(ColorRGBA(
				geometry.material.materialData[i].emission.x,
				geometry.material.materialData[i].emission.y,
				geometry.material.materialData[i].emission.z,
				geometry.material.materialData[i].emission.w));

			_materialProperty.setShininess(geometry.material.materialData[i].shininess);
		}

		return result;
	}
}
