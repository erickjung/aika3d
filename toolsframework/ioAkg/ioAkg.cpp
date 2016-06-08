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

#include "ioAkg.h"

// -----------------------------
#define MAGIC "AKFG"
#define VERSION 1
// -----------------------------

bool ioAkg::writeFile(const char* pFileName, const GeometryData &geometry)
{
	FILE *file = fopen(pFileName, "wb");

	if(file)
	{
		// magic
		printf("Add magic\n");
		fwrite(MAGIC, 4, 1, file);
		unsigned int version = VERSION;
		fwrite(&version, sizeof(unsigned int), 1, file);
		
		// indice size
		printf("Add indices\n");
		unsigned int indexSize = geometry.indicesSize;
		fwrite(&indexSize, sizeof(unsigned int), 1, file);

		// ----------------------------------

		// vertex data
		printf("Add vertex data\n");
		unsigned int dataSize = geometry.vertex.vertexSize;
		fwrite(&dataSize, sizeof(unsigned int), 1, file);
		for(unsigned int i=0; i<dataSize; i++)
			fwrite(&geometry.vertex.vertexData[i], sizeof(float), 1, file);

		// vertex indices
		printf("Add vertex indices\n");
		for(unsigned int i=0; i<indexSize; i++)
			fwrite(&geometry.vertex.vertexIndices[i], sizeof(unsigned int), 1, file);

		// ----------------------------------

		// vertex normal
		printf("Add normal data\n");
		unsigned int normalSize = geometry.normal.normalSize;
		fwrite(&normalSize, sizeof(unsigned int), 1, file);
		for(unsigned int i=0; i<normalSize; i++)
			fwrite(&geometry.normal.normalData[i], sizeof(float), 1, file);

		// vertex indices
		printf("Add normal indices\n");
		for(unsigned int i=0; i < indexSize; i++)
			fwrite(&geometry.normal.normalIndices[i], sizeof(unsigned int), 1, file);

		// ----------------------------------

		if(geometry.texture.imageQuantity > 0)
		{
			// texture quantity
			// TODO: add support for more than one texture
			//unsigned int texImageSize = geometry.texture.imageQuantity;
			//fwrite(&texImageSize, sizeof(unsigned int), 1, file);
			unsigned int texImageSize = 1;
			fwrite(&texImageSize, sizeof(unsigned int), 1, file);


			printf("...has texture\n");
			printf("Add image name\n");
			// texture name size
			unsigned int textureNameSize = (unsigned int)geometry.texture.textureFileName.size();
			fwrite(&textureNameSize, sizeof(unsigned int), 1, file);

			// texture name
			char *textureName = new char[textureNameSize+1];
			memset(textureName, 0, textureNameSize+1);
			strcpy(&textureName[0], geometry.texture.textureFileName.c_str());
			fwrite(textureName, textureNameSize, 1, file);
			delete[] textureName;

			// texture data
			printf("Add texture data\n");
			unsigned int texSize = (unsigned int) geometry.texture.textureData.size();
			fwrite(&texSize, sizeof(unsigned int), 1, file);
			for(unsigned int i=0; i<texSize; i++)
				fwrite(&geometry.texture.textureData[i], sizeof(float), 1, file);

			// texture indices
			printf("Add texture indices\n");
			for(unsigned int i=0; i<indexSize; i++)
				fwrite(&geometry.texture.textureIndices[i], sizeof(unsigned int), 1, file);
		}
		else
		{
			printf("... dont has texture\n");
			unsigned int texImageSize = 0;
			fwrite(&texImageSize, sizeof(unsigned int), 1, file);
		}


		// material
		unsigned int materialSize = geometry.material.materialQuantity;
		fwrite(&materialSize, sizeof(unsigned int), 1, file);

		if(materialSize > 0)
		{
			printf("...has material\n");
			printf("Add material data\n");
			for(unsigned int i=0; i<materialSize; i++)
			{
				EffectData effect = geometry.material.materialData[i];

				// ambient
				fwrite(&effect.ambient.x, sizeof(float), 1, file);
				fwrite(&effect.ambient.y, sizeof(float), 1, file);
				fwrite(&effect.ambient.z, sizeof(float), 1, file);
				fwrite(&effect.ambient.w, sizeof(float), 1, file);

				// diffuse
				fwrite(&effect.diffuse.x, sizeof(float), 1, file);
				fwrite(&effect.diffuse.y, sizeof(float), 1, file);
				fwrite(&effect.diffuse.z, sizeof(float), 1, file);
				fwrite(&effect.diffuse.w, sizeof(float), 1, file);

				// specular
				fwrite(&effect.specular.x, sizeof(float), 1, file);
				fwrite(&effect.specular.y, sizeof(float), 1, file);
				fwrite(&effect.specular.z, sizeof(float), 1, file);
				fwrite(&effect.specular.w, sizeof(float), 1, file);

				// emission
				fwrite(&effect.emission.x, sizeof(float), 1, file);
				fwrite(&effect.emission.y, sizeof(float), 1, file);
				fwrite(&effect.emission.z, sizeof(float), 1, file);
				fwrite(&effect.emission.w, sizeof(float), 1, file);

				// shininess & transparence
				fwrite(&effect.shininess, sizeof(float), 1, file);
				fwrite(&effect.transparence, sizeof(float), 1, file);
			}
		}
		else
			printf("... dont has material\n");

		// ----------------------------------

		fclose(file);
		printf("DONE\n");
	}

	return true;
}


bool ioAkg::openFile(const char* pFileName, GeometryData &geometry)
{
	FILE *file = fopen(pFileName, "rb");

	if(file)
	{
		// load magic
		char magic[5];
		memset(&magic[0], 0, 5);
		fread(&magic[0], 4, 1, file);

		if(memcmp(MAGIC, &magic[0], 4) != 0)
			return false;

		// load version
		unsigned int version = 0;
		fread(&version, sizeof(unsigned int), 1, file);
		if(version != VERSION)
			return false;

		// load indices size
		fread(&geometry.indicesSize, sizeof(unsigned int), 1, file);

		// load vertex data
		fread(&geometry.vertex.vertexSize, sizeof(unsigned int), 1, file);
		geometry.vertex.vertexData.reserve(geometry.vertex.vertexSize);
		for(unsigned int i=0; i<geometry.vertex.vertexSize; i++)
		{
			float value;
			fread(&value, sizeof(float), 1, file);
			geometry.vertex.vertexData.push_back(value);
		}

		// load vertex indices
		geometry.vertex.vertexIndices.reserve(geometry.indicesSize);
		for(unsigned int i=0; i<geometry.indicesSize; i++)
		{
			unsigned int value;
			fread(&value, sizeof(unsigned int), 1, file);
			geometry.vertex.vertexIndices.push_back(value);
		}

		// load normals data
		fread(&geometry.normal.normalSize, sizeof(unsigned int), 1, file);
		geometry.normal.normalData.reserve(geometry.normal.normalSize);
		for(unsigned int i=0; i<geometry.normal.normalSize; i++)
		{
			float value;
			fread(&value, sizeof(float), 1, file);
			geometry.normal.normalData.push_back(value);
		}

		// load normal indices
		geometry.normal.normalIndices.reserve(geometry.indicesSize);
		for(unsigned int i=0; i < geometry.indicesSize; i++)
		{
			unsigned int value;
			fread(&value, sizeof(unsigned int), 1, file);
			geometry.normal.normalIndices.push_back(value);
		}

		// load texture
		fread(&geometry.texture.imageQuantity, sizeof(unsigned int), 1, file);
		if(geometry.texture.imageQuantity > 0)
		{
			// load texture filename
			unsigned int textureNameSize;
			fread(&textureNameSize, sizeof(unsigned int), 1, file);

			char *textureName = new char[textureNameSize+1];
			memset(textureName, 0, textureNameSize+1);
			fread(&textureName[0], textureNameSize, 1, file);
			geometry.texture.textureFileName = textureName;
			delete[] textureName;

			// load texture data
			unsigned int textureSize;
			fread(&textureSize, sizeof(unsigned int), 1, file);
			geometry.texture.textureSize = textureSize;
			geometry.texture.textureData.reserve(textureSize);
			for(unsigned int i=0; i<textureSize; i++)
			{
				float value;
				fread(&value, sizeof(float), 1, file);
				geometry.texture.textureData.push_back(value);
			}

			// load texture indices
			geometry.texture.textureIndices.reserve(geometry.indicesSize);
			for(unsigned int i=0; i<geometry.indicesSize; i++)
			{
				unsigned int value;
				fread(&value, sizeof(unsigned int), 1, file);
				geometry.texture.textureIndices.push_back(value);
			}
		}

		// load material
		fread(&geometry.material.materialQuantity, sizeof(unsigned int), 1, file);
		if(geometry.material.materialQuantity > 0)
		{
			for(unsigned int i=0; i<geometry.material.materialQuantity; i++)
			{
				EffectData effect;

				fread(&effect.ambient.x, sizeof(float), 1, file);
				fread(&effect.ambient.y, sizeof(float), 1, file);
				fread(&effect.ambient.z, sizeof(float), 1, file);
				fread(&effect.ambient.w, sizeof(float), 1, file);

				// diffuse
				fread(&effect.diffuse.x, sizeof(float), 1, file);
				fread(&effect.diffuse.y, sizeof(float), 1, file);
				fread(&effect.diffuse.z, sizeof(float), 1, file);
				fread(&effect.diffuse.w, sizeof(float), 1, file);

				// specular
				fread(&effect.specular.x, sizeof(float), 1, file);
				fread(&effect.specular.y, sizeof(float), 1, file);
				fread(&effect.specular.z, sizeof(float), 1, file);
				fread(&effect.specular.w, sizeof(float), 1, file);

				// emission
				fread(&effect.emission.x, sizeof(float), 1, file);
				fread(&effect.emission.y, sizeof(float), 1, file);
				fread(&effect.emission.z, sizeof(float), 1, file);
				fread(&effect.emission.w, sizeof(float), 1, file);

				// shininess & transparence
				fread(&effect.shininess, sizeof(float), 1, file);
				fread(&effect.transparence, sizeof(float), 1, file);

				geometry.material.materialData.push_back(effect);
			}
		}


		fclose(file);

		return true;
	}

	return false;
}
