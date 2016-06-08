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

#ifndef __AKGFILE_H__
#define __AKGFILE_H__

#include <vector>

/**
 * @brief
 * This is simplevector. Used to make the lib more generic and independent.
 */
class SimpleVector
{
public:
       SimpleVector() : x(0), y(0), z(0), w(0){}
       SimpleVector(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
       float x, y, z, w;
};

/**
 * @brief
 * This is Normal data
 */
class NormalData
{
public:
	unsigned int normalSize;
	std::vector<float> normalData;
	std::vector<unsigned int> normalIndices;
};

/**
 * @brief
 * This is Vertex data
 */
class VertexData
{
public:
	unsigned int vertexSize;
	std::vector<float> vertexData;
	std::vector<unsigned int> vertexIndices;
};

/**
 * @brief
 * This is Texture data
 */
class TextureData
{
public:
	std::string textureFileName;
	unsigned int imageQuantity;

	unsigned int textureSize;
	std::vector<float> textureData;
	std::vector<unsigned int> textureIndices;
};

/**
 * @brief
 * This is Effect data
 */
class EffectData
{
public:
       SimpleVector ambient;
       SimpleVector specular;
       SimpleVector diffuse;
       SimpleVector emission;
       float shininess;
       float transparence;
};

/**
 * @brief
 * This is Material data
 */
class MaterialData
{
public:
       unsigned int materialQuantity;
       std::vector<EffectData> materialData;
};

/**
 * @brief
 * This is Geometry data
 */
class GeometryData
{
public:
	VertexData vertex;
	NormalData normal;
	TextureData texture;
	MaterialData material;

	unsigned int indicesSize;
};

/**
 * @brief
 * This is the IO akg.
 */
class ioAkg
{
public:
    /**
     * Write the file
     *
	 * @param pFileName the filename
	 * @param geometry the geometry data
	 *
	 * @return true if write the file
     */
	bool writeFile(const char* pFileName, const GeometryData &geometry);

    /**
     * Open the file
     *
	 * @param pFileName the filename
	 * @param geometry Return the geometry data
	 *
	 * @return true if opened the file
     */
	bool openFile(const char* pFileName, GeometryData &geometry);
};

#endif