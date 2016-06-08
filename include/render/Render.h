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

#ifndef RENDER_H_
#define RENDER_H_

#include <windows.h>
#include <util/Log.h>
#include <util/Object.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <lang/Array.h>
#include <vector>

namespace scene
{
	class MaterialProperty;
	class AlphaProperty;
	class CullProperty;
	class TextureProperty;
	class Light;
}

namespace render
{
    /**
     * The render type.
     */
    enum E_RENDER_TYPE
    {
        RT_OPENGL = 0, //!< Opengl Type
        RT_DIRECTX	   //!< DirectX Type
    };

    /**
     * The projection type.
     */
    enum E_PROJECTION_TYPE
    {
        PT_PROJECTION = 0, //!< projection Type
        PT_MODELVIEW	   //!< modelview Type
    };

    /**
     * The feature type.
     */
    enum E_FEATURE_TYPE
    {
        FT_TEXTURE = 0, //!< texture Type
		FT_BLEND,       //!< blend Type
		FT_CULL_FACE,   //!< cull face Type
		FT_DEPTH_TEST   //!< depth test Type
    };

	/**
     * @brief
     * This is the interface class for all the api's renders.
     */
	class API_STATE Render : public Object
    {
    public:
        /**
         * Initialize the window
         */
        virtual bool initialize(HWND &hWnd) = 0;

        /**
         * Setup the screen
         *
         * @param width The screen width
         * @param height The screen height
         */
        virtual void setup(int16 width, int16 height) = 0;

        /**
         * The begin scene method
         *
         * @param color The color vector
         */
        virtual void begin(float32 r, float32 g, float32 b, float32 a) = 0;

        /**
         * The end scene method (to swap the buffer)
         */
        virtual void end() = 0;

        /**
         * Write a text in the screen
         *
         * @param x The x position
         * @param y The y position
         * @param pData The data to be writed
         */
        virtual void writeText(int32 x, int32 y, const char *pData) = 0;

        /**
         * Index data to render
         *
         * @param indicesSize The indices
         * @param vertexList The list of vertexs
         * @param normalList The list of normals
		 * @param textureList The list of texture coord
		 *
		 * @return the list id (to be used on drawList())
         */
		virtual int32 indexDataList(uint32 indicesSize, const lang::Array<math::Vector3f> &vertexList, const lang::Array<math::Vector3f> &normalList, const lang::Array<math::Vector3f> &textureList) = 0;

        /**
         * Draw the indexed data
         *
         * @param list The list id
         * @param pProperty The cull property
         * 
		 * @note Need to index data before call this method
         */
		virtual void drawList(int32 list, scene::CullProperty *pProperty = NULL) = 0;

        /**
         * Push the matrix
         */
		virtual void pushMatrix() = 0;

        /**
         * Pop the matrix
         */
		virtual void popMatrix() = 0;

        /**
         * Set Scale 
         */
		virtual void setScale(math::Vector3f scale) = 0;

        /**
         * Set Translation
         */
		virtual void setTranslation(math::Vector3f scale) = 0;

        /**
         * Set Rotation
         */
		virtual void setRotation(float32 angle, math::Vector3f scale) = 0;

        /**
         * Set projection type
		 *
		 * @param eType The type of projection
         */
		virtual void setProjectionType(E_PROJECTION_TYPE eType) = 0;

        /**
         * Load identity
         */
		virtual void loadIdentity() = 0;

        /**
         * Set the camera perspective
         *
         * @param fovValue the fov value
         * @param nearValue the near value
		 * @param farValue the far value
         */
		virtual void setCameraPerspective(float32 fovValue, float32 nearValue, float32 farValue) = 0;

        /**
         * Set the camera translation
         *
         * @param translation The translation vector
         * @param target The target vector
		 * @param upVector The up vector
         */
		virtual void setCameraTranslation(const math::Vector3f &translation, const math::Vector3f &target, const math::Vector3f &upVector) = 0;

        /**
         * Set the feature status
         *
         * @param eType The type of feature
         * @param value The status to set
         */
		virtual void setFeatureStatus(E_FEATURE_TYPE eType, bool value) = 0;

        /**
         * Set the material property to the render
         *
         * @param pProperty The property
         */
		virtual void setMaterialProperty(scene::MaterialProperty *pProperty) = 0;

        /**
         * Set the alpha property to the render
         *
         * @param pProperty The property
         */
		virtual void setAlphaProperty(scene::AlphaProperty *pProperty) = 0;

        /**
         * Set the texture property to the render
         *
         * @param pProperty The property
		 * @return The image number
         */
		virtual uint32 setTextureProperty(scene::TextureProperty *pProperty) = 0;

        /**
         * Set the light
         *
         * @param pLight The light
         */
		virtual void setLight(scene::Light *pLight) = 0;

        /**
         * Bind a specific image
         *
         * @param number The number of the image
         */
		virtual void bindImage(uint32 number) = 0;
    };

}//namespace

#endif /*RENDER_H_*/
