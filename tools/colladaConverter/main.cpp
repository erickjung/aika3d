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

#include <ioAkg/ioAkg.h>

#define NO_LIBXML
#include "FCollada.h"
#include "FCDocument/FCDocument.h"
#include "FCDocument/FCDAsset.h"
#include "FCDocument/FCDLibrary.h"
#include "FCDocument/FCDGeometry.h"
#include "FCDocument/FCDGeometryMesh.h"
#include "FCDocument/FCDGeometryPolygons.h"
#include "FCDocument/FCDGeometryPolygonsTools.h"
#include "FCDocument/FCDGeometryPolygonsInput.h"

#include "FCDocument/FCDGeometrySource.h"
#include "FCDocument/FCDExtra.h"
#include "FCDocument/FCDImage.h"

#include "FCDocument\FCDMaterial.h"
#include "FCDocument\FCDEffect.h"
#include "FCDocument\FCDEffectProfile.h"
#include "FCDocument\FCDEffectStandard.h"
#include "FCDocument\FCDTexture.h"

bool parseColladaFile(const char* pFileName, GeometryData &geometry);
std::string extractFileName(const std::string &fullPath, bool extension);

int main(int argc, char **argv)
{
	printf("Aika Collada converter\n");
	printf("version 0.1\n\n");

	if(argc < 2)
	{
		printf("use: colladaconv inputfile [-o outputfile]\n\n");
		return 0;
	}
	
	std::string inFile = argv[1];
	std::string outFile;

	GeometryData geometry;
	parseColladaFile(inFile.c_str(), geometry);

	ioAkg file;

	bool foundOut = false;
	for(int i=2; i < argc; ++i)
	{
		if(strcmp(argv[i], "-o") == 0)
		{
			if(argc > i + 1)
			{
				std::string tempStr = argv[++i];
				outFile = extractFileName(tempStr.c_str(), false);
				foundOut = true;
			}
			else
			{
				printf("invalid argument");
				return 0;
			}
		}
		else
		{
			printf("invalid argument");
			return 0;
		}
	}

	if(foundOut == false)
	{
		outFile = extractFileName(inFile.c_str(), false);
	}

	outFile += ".akg";

	file.writeFile(outFile.c_str(), geometry);
	printf("Write DONE\n");

	bool resultLoad = file.openFile(outFile.c_str(), geometry);
	if(resultLoad)
		printf("Test PASSED\n");
	else
		printf("Test FAILED\n");

	return 0;
}

bool parseColladaFile(const char* pFileName, GeometryData &geometry)
{
	FCollada::Initialize();
	FCDocument* document = FCollada::NewTopDocument();
	fstring inputFile = TO_FSTRING(pFileName);

	bool result = FCollada::LoadDocumentFromFile(document, inputFile.c_str());

	if(result)
	{
		FCDGeometryLibrary* geolib = document->GetGeometryLibrary();

		for (unsigned int i=0; i < (int) geolib->GetEntityCount(); i++)
		{
			FCDGeometryMesh* mesh;

			if (geolib->GetEntity(i)->IsMesh()==true) 
			{
				mesh = geolib->GetEntity(i)->GetMesh();
				if(!mesh->IsTriangles())
					FCDGeometryPolygonsTools::Triangulate(mesh);

				// vertex data
				size_t vertexCount = mesh->GetPositionSource()->GetDataCount();
				geometry.vertex.vertexData.reserve(vertexCount);
				for(unsigned int i=0; i < vertexCount; i++)
					geometry.vertex.vertexData.push_back(mesh->GetPositionSource()->GetData()[i]);
				geometry.vertex.vertexSize = (unsigned int) vertexCount;

				// vertex indices
				size_t indexCount = mesh->GetPolygons(0)->GetInput(0)->GetIndexCount();
				geometry.vertex.vertexIndices.reserve(indexCount);
				for(unsigned int i=0; i< indexCount; i++)
					geometry.vertex.vertexIndices.push_back(mesh->GetPolygons(0)->GetInput(0)->GetIndices()[i]);
				geometry.indicesSize = (unsigned int) indexCount;

				// normal data
				size_t normalCount = mesh->GetPolygons(0)->GetParent()->FindSourceByType(FUDaeGeometryInput::NORMAL)->GetDataCount();
				geometry.normal.normalData.reserve(normalCount);
				for(unsigned int i=0; i < normalCount; i++)
					geometry.normal.normalData.push_back(mesh->GetPolygons(0)->GetParent()->FindSourceByType(FUDaeGeometryInput::NORMAL)->GetData()[i]);
				geometry.normal.normalSize = (unsigned int) normalCount;

				// normal indices
				size_t normalIndexCount = mesh->GetPolygons(0)->FindInput(FUDaeGeometryInput::NORMAL)->GetIndexCount();
				geometry.normal.normalIndices.reserve(normalIndexCount);
				for(unsigned int i=0; i < normalIndexCount; i++)
					geometry.normal.normalIndices.push_back(mesh->GetPolygons(0)->FindInput(FUDaeGeometryInput::NORMAL)->GetIndices()[i]);


				// texture
				FCDGeometrySource *textureObject = mesh->GetPolygons(0)->GetParent()->FindSourceByType(FUDaeGeometryInput::TEXCOORD);
				if(textureObject)
				{
					size_t texCount = textureObject->GetDataCount();
					geometry.texture.textureData.reserve(texCount);
					for(unsigned int i=0; i < texCount; i++)
						geometry.texture.textureData.push_back(mesh->GetPolygons(0)->GetParent()->FindSourceByType(FUDaeGeometryInput::TEXCOORD)->GetData()[i]);

					size_t texIndexCount = mesh->GetPolygons(0)->FindInput(FUDaeGeometryInput::TEXCOORD)->GetIndexCount();
					geometry.texture.textureIndices.reserve(texIndexCount);
					for(unsigned int i=0; i < texIndexCount; i++)
						geometry.texture.textureIndices.push_back(mesh->GetPolygons(0)->FindInput(FUDaeGeometryInput::TEXCOORD)->GetIndices()[i]);
				}
			}

		}

		// image
		FCDImageLibrary* imagelib = document->GetImageLibrary();
		size_t textureCount = (int) imagelib->GetEntityCount();
		geometry.texture.imageQuantity = (unsigned int) textureCount;

		FCDImage * image = NULL;
		for(unsigned int i=0; i<textureCount; i++)
		{
			image = imagelib->GetEntity(i);
			wchar_t orig[512];
			swprintf(orig, L"%s", image->GetFilename().c_str() );
			size_t origsize = wcslen(orig) + 1;
			const size_t newsize = 256;
			size_t convertedChars = 0;
			char nstring[newsize];
			wcstombs_s(&convertedChars, nstring, origsize, orig, _TRUNCATE);
			geometry.texture.textureFileName = extractFileName(nstring, true);
		}

		FCDMaterialLibrary* materiallib = document->GetMaterialLibrary();
		size_t materialCount = (int) materiallib->GetEntityCount();
		geometry.material.materialData.reserve(materialCount);

		FCDMaterial* material;
		EffectData effect;
		geometry.material.materialQuantity = (unsigned int) materialCount;
		for(unsigned int i=0; i < materialCount; i++)
		{
			material = materiallib->GetEntity(i);

			if(material == NULL)
			{
				effect.ambient = SimpleVector(0.0f, 0.0f, 0.0f, 0.0f);
				effect.diffuse = SimpleVector(1.0f, 0.0f, 1.0f, 1.0f);
				effect.specular = SimpleVector(0.2f, 0.2f, 0.2f, 1.0f);
				effect.emission = SimpleVector(0.0f, 0.0f, 0.0f, 0.0f);
				effect.shininess = 10.0f;
				effect.transparence = 1.0f;
				break;
			}


			FCDEffect* collEffect = material->GetEffect();
			FCDEffectProfile* profile = collEffect->FindProfile(FUDaeProfileType::COMMON);
			FCDEffectStandard* standardProfile=dynamic_cast<FCDEffectStandard*>(profile);

			effect.transparence = standardProfile->GetTranslucencyFactor();

			effect.ambient = SimpleVector(
				standardProfile->GetAmbientColor().x,
				standardProfile->GetAmbientColor().y,
				standardProfile->GetAmbientColor().z,
				standardProfile->GetAmbientColor().w);

			effect.diffuse = SimpleVector(
				standardProfile->GetDiffuseColor().x,
				standardProfile->GetDiffuseColor().y,
				standardProfile->GetDiffuseColor().z,
				standardProfile->GetDiffuseColor().w);

			float specularFactor = standardProfile->GetSpecularFactor();
			effect.specular = SimpleVector(
				specularFactor*standardProfile->GetSpecularColor().x,
				specularFactor*standardProfile->GetSpecularColor().y,
				specularFactor*standardProfile->GetSpecularColor().z,
				specularFactor*standardProfile->GetSpecularColor().w);

			if(standardProfile->IsEmissionFactor())
			{
				effect.emission = SimpleVector(
					standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionFactor());
			}
			else
			{
				effect.emission = SimpleVector(
					standardProfile->GetEmissionColor().x * standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionColor().y * standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionColor().z * standardProfile->GetEmissionFactor(),
					standardProfile->GetEmissionColor().w * standardProfile->GetEmissionFactor());
			}

			effect.shininess = standardProfile->GetShininess();

			geometry.material.materialData.push_back(effect);
		}
	}

	return result;
}

std::string extractFileName(const std::string &fullPath, bool extension)
{
	int first = 0, last = (int)fullPath.length() - 1;
	
	for( int i = (int)fullPath.length() - 1; i >= 0; --i )
	{
		if( fullPath[i] == '.' )
		{
			last = i;
		}
		else if( fullPath[i] == '\\' || fullPath[i] == '/' )
		{
			first = i + 1;
			break;
		}
	}

	if( extension )
		return fullPath.substr( first, fullPath.length() - first );
	else
		return fullPath.substr( first, last - first );
}