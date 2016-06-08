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

#ifndef __MESH_H__
#define __MESH_H__

#include <util/Log.h>
#include <scene/Transformation.h>
#include <lang/String.h>
#include <render/Render.h>
#include <scene/property/MaterialProperty.h>
#include <scene/property/AlphaProperty.h>
#include <scene/property/CullProperty.h>
#include <img/Image.h>

namespace scene
{
    using namespace lang;

    /**
     * @brief
     * This is the Mesh class.
     */
    class API_STATE Mesh : public Transformation
    {
    public:
        /**
         * Constructor
         */
        Mesh();

        /**
         * Destructor
         */
		virtual ~Mesh();

        /**
         * Load the mesh file (AKG file)
         *
		 * @param filename The filename
         */
        void load(const String &filename);

        /**
         * Draw the mesh data
         *
		 * @param pRender The render instance
         */
		void draw(render::Render *pRender);

        /**
         * Set the mesh alpha property
         *
		 * @param alphaProperty The alpha property
         */
		void setMeshAlphaProperty(const AlphaProperty &alphaProperty);

        /**
         * Set the mesh material property
         *
		 * @param materialProperty The material property
         */
		void setMeshMaterialProperty(const MaterialProperty &materialProperty);

		/**
         * Get alpha property
         *
		 * @return The alha property
         */
		const AlphaProperty &getMeshAlphaProperty();

        /**
         * Get material property
         *
		 * @return The material property
         */
		const MaterialProperty &getMeshMaterialProperty();

		/**
		 * @see Object::toString()
		 */
		const char * toString(){return "class: Mesh";}

	private:
		/**
         * The filename
         */
		String _filename;

		/**
         * The texture image object
         */
		img::Image textureImage;

		/**
         * The alpha property
         */
		AlphaProperty _alphaProperty;

		/**
         * The material property
         */
		MaterialProperty _materialProperty;

		/**
         * The cull property
         */
		CullProperty _cullProperty;

		/**
         * The geometry list id
         */
		int32 _listId;

		/**
         * The vertex list
         */
		lang::Array<math::Vector3f> _vertexList;

		/**
         * The normal list
         */
		lang::Array<math::Vector3f> _normalList;

		/**
         * The texture list
         */
		lang::Array<math::Vector3f> _texList;

		/**
         * The image id
         */
		uint32 _imageId;

		/**
         * has texture
         */
		bool _hasTexture;

		/**
         * has texture
         */
		bool _hasMaterial;

		// file types
		/**
         * Open the AKG (aika geometry) file
		 *
		 * @return True if open the file
         */
		bool openAkg();
    };

#include <scene/Mesh.inl>

}//namespace

#endif /*__MESH_H__*/
