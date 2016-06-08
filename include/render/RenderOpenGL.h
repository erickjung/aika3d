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

#ifdef AK_OPENGL

#ifndef RENDER_OPENGL_H_
#define RENDER_OPENGL_H_

#include <gl/gl.h>
#include <gl/glu.h>
#include <render/Render.h>

namespace render
{
    /**
     * @brief
     * This is the OpenGL implementation.
     */
    class API_STATE RenderOpenGL : public Render
    {
    public:
        /**
         * Constructor
         */
        RenderOpenGL();

        /**
         * Destructor
         */
        virtual ~RenderOpenGL();

        /**
         * @see Render::initialize(HWND &hWnd)
         */
        bool initialize(HWND &hWnd);

        /**
         * @see Render::setup(int16 width, int16 height)
         */
        void setup(int16 width, int16 height);

        /**
         * @see Render::begin(math::Vector color)
         */
        void begin(float32 r, float32 g, float32 b, float32 a);

        /**
         * @see Render::end()
         */
        void end();

        /**
         * @see Render::writeText(int32 x, int32 y, const char *pData)
         */
        void writeText(int32 x, int32 y, const char *pData);

        /**
         * @see Render::indexDataList(uint32 indicesSize, const lang::Array<math::Vector3f> &vertexList, const lang::Array<math::Vector3f> &normalList, const lang::Array<math::Vector3f> &textureList)
         */
		int32 indexDataList(uint32 indicesSize, const lang::Array<math::Vector3f> &vertexList, const lang::Array<math::Vector3f> &normalList, const lang::Array<math::Vector3f> &textureList);

        /**
         * @see Render::drawList(int32 list, scene::CullProperty *pProperty = NULL)
         */
		void drawList(int32 list, scene::CullProperty *pProperty = NULL);

        /**
         * @see Render::pushMatrix()
         */
		void pushMatrix();

        /**
         * @see Render::popMatrix()
         */
		void popMatrix();

        /**
         * @see Render::setScale(math::Vector3f scale)
         */
		void setScale(math::Vector3f scale);

        /**
         * @see Render::setTranslation(math::Vector3f scale)
         */
		void setTranslation(math::Vector3f scale);

        /**
         * @see Render::setRotation(float32 angle, math::Vector3f scale)
         */
		void setRotation(float32 angle, math::Vector3f scale);

        /**
         * @see Render::setProjectionType(E_PROJECTION_TYPE eType)
         */
		void setProjectionType(E_PROJECTION_TYPE eType);

        /**
         * @see Render::loadIdentity()
         */
		void loadIdentity();

        /**
         * @see Render::setCameraPerspective(float32 fovValue, float32 nearValue, float32 farValue)
         */
		void setCameraPerspective(float32 fovValue, float32 nearValue, float32 farValue);

        /**
         * @see Render::setCameraTranslation(const math::Vector3f &translation, const math::Vector3f &target, const math::Vector3f &upVector)
         */
		void setCameraTranslation(const math::Vector3f &translation, const math::Vector3f &target, const math::Vector3f &upVector);

        /**
         * @see Render::setFeatureStatus(E_FEATURE_TYPE eType, bool value)
         */
		void setFeatureStatus(E_FEATURE_TYPE eType, bool value);

        /**
         * @see Render::setMaterialProperty(scene::MaterialProperty *pProperty)
         */
		void setMaterialProperty(scene::MaterialProperty *pProperty);

        /**
         * @see Render::setAlphaProperty(scene::AlphaProperty *pProperty)
         */
		void setAlphaProperty(scene::AlphaProperty *pProperty);

        /**
         * @see Render::setTextureProperty(scene::TextureProperty *pProperty)
         */
		uint32 setTextureProperty(scene::TextureProperty *pProperty);

        /**
         * @see Render::setLight(scene::Light *pLight)
         */
		void setLight(scene::Light *pLight);

        /**
         * @see Render::bindImage(uint32 number)
         */
		void bindImage(uint32 number);

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: RenderOpenGL";}

    private:
        /**
         * GDI Device Context
         */
        HDC _hDc;

        /**
         * Permanent Rendering Context
         */
        HGLRC _hRc;

        /**
         * Base for font type
         */
        int32 _base;

        /**
         * Initialize the font system
         */
        void buildFont();

        /**
         * Destroy all the window stuff
         */
        void destroy();
    };
}//namespace
#endif // RENDER_OPENGL_H_
#endif // AK_OPENGL
