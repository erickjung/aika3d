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

#include <core/Device.h>
#include <render/RenderOpenGL.h>
#include <util/Assert.h>
#include <lang/String.h>

#include <scene/property/MaterialProperty.h>
#include <scene/property/AlphaProperty.h>
#include <scene/property/CullProperty.h>
#include <scene/property/TextureProperty.h>
#include <scene/Light.h>

#ifndef __MINGW32__
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
#endif

namespace render
{
	GLenum E_GL_FUNCTION[] =
	{
		GL_ZERO,
		GL_ONE,
		GL_DST_COLOR,
		GL_SRC_ALPHA,
		GL_DST_ALPHA,
		GL_ONE_MINUS_DST_COLOR,
		GL_ONE_MINUS_SRC_ALPHA,
		GL_ONE_MINUS_DST_ALPHA,
		GL_SRC_ALPHA_SATURATE,
		GL_SRC_COLOR,
		GL_ONE_MINUS_SRC_COLOR
	};

	RenderOpenGL::RenderOpenGL()
    {
        TRACE("RenderOpenGL::RenderOpenGL");
    }

    RenderOpenGL::~RenderOpenGL()
    {}

    bool RenderOpenGL::initialize(HWND &hWnd)
    {
        TRACE("RenderOpenGL::initialize");

        uint32 PixelFormat;

        static	PIXELFORMATDESCRIPTOR pfd =
        {
            sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW |
                PFD_SUPPORT_OPENGL |
                PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                32,
                0, 0, 0, 0, 0, 0,
                0,
                0,
                0,
                0, 0, 0, 0,
                16,
                0,
                0,
                PFD_MAIN_PLANE,
                0,
                0, 0, 0
        };

        if (!(_hDc = GetDC(hWnd)))
        {
            destroy();
            return false;
        }

        if (!(PixelFormat = ChoosePixelFormat(_hDc, &pfd)))
        {
            destroy();
            return false;
        }

        if (!SetPixelFormat(_hDc, PixelFormat, &pfd))
        {
            destroy();
            return false;
        }

        if (!(_hRc = wglCreateContext(_hDc)))
        {
            destroy();
            return false;
        }

        if (!wglMakeCurrent(_hDc, _hRc))
        {
            destroy();
            return false;
        }
        glEnable(GL_TEXTURE_2D);
        buildFont();

        return true;
    }

    void RenderOpenGL::setup(int16 width, int16 height)
    {
        TRACE("RenderOpenGL::setup");
        assert(width > 0 && height > 0);

        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        // Calculate The Aspect Ratio Of The Window
        gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1000.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

    }

    void RenderOpenGL::buildFont()
    {
        HFONT	font;					

        _base = glGenLists(256);			

        font = CreateFont(	-1,			
            0,							
            0,							
            0,							
			FW_ULTRALIGHT,					
            TRUE,						
            FALSE,						
            FALSE,						
            ANSI_CHARSET,				
            OUT_TT_PRECIS,				
            CLIP_DEFAULT_PRECIS,		
            ANTIALIASED_QUALITY,		
            FF_DONTCARE|DEFAULT_PITCH,	
            "Arial");				

        SelectObject(_hDc, font);	
        GLYPHMETRICSFLOAT storageInfo[256];

        wglUseFontOutlines(	_hDc,	
            0,						
            255,					
            _base,					
            0.0f,					
            0.0f,					
            WGL_FONT_POLYGONS,		
            storageInfo);					

    }

    void RenderOpenGL::writeText(int32 x, int32 y, const char *pData)
    {
        assert(pData != NULL && x > 0 && y > 0);
		
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);

        glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(-1,1,-1,1,-1,1);
        glColor3f(1,1,1);

        if (pData == NULL)
            return;

        glScalef(0.05f, 0.05f, 0);
        glTranslatef((float32)(x/10)*-19, (float32)y+3, 0.0f);

        glPushAttrib(GL_LIST_BIT);
        glListBase(_base);
        glCallLists(strlen(pData), GL_UNSIGNED_BYTE, pData);
        glPopAttrib();

        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
    }

    void RenderOpenGL::begin(float32 r, float32 g, float32 b, float32 a)
    {
        glShadeModel(GL_SMOOTH);
		glEnable(GL_TEXTURE_2D);


        glClearColor(r, g, b, a);
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void RenderOpenGL::end()
    {
        SwapBuffers(_hDc);
    }

    void RenderOpenGL::destroy()
    {
        // need to add delete stuff
    }

	int32 RenderOpenGL::indexDataList(uint32 indicesSize, const lang::Array<math::Vector3f> &vertexList, const lang::Array<math::Vector3f> &normalList, const lang::Array<math::Vector3f> &textureList)
	{
		int32 listId = glGenLists(1); 
		glNewList(listId, GL_COMPILE); 

		glBegin (GL_TRIANGLES);

		for(uint32 i=0; i < indicesSize; i++) 
		{ 
			if(textureList.getSize() > 0)
				glTexCoord2f(textureList[i].x, textureList[i].y);

			if(normalList.getSize() > 0)
				glNormal3f(normalList[i].x, normalList[i].y, normalList[i].z);

			if(vertexList.getSize() > 0)
				glVertex3f(vertexList[i].x, vertexList[i].y, vertexList[i].z);
		}

		glEnd();
		glEndList();

		return listId;
	}

	void RenderOpenGL::drawList(int32 list, scene::CullProperty *pProperty)
	{
		if(pProperty)
		{
			if(pProperty->getCullType() == scene::CullProperty::CT_FRONT)
				glCullFace(GL_FRONT);
			else if(pProperty->getCullType() == scene::CullProperty::CT_BACK)
				glCullFace(GL_BACK);
			glFrontFace(GL_CCW);
		}

		glCallList(list);
	}

    void RenderOpenGL::pushMatrix()
	{
		glPushMatrix();
	}

	void RenderOpenGL::popMatrix()
	{
		glPopMatrix();
	}

	void RenderOpenGL::setScale(math::Vector3f scale)
	{
		glScalef(scale.x, scale.y, scale.z);
	}

	void RenderOpenGL::setTranslation(math::Vector3f scale)
	{
		glTranslatef(scale.x, scale.y, scale.z);
	}

	void RenderOpenGL::setRotation(float32 angle, math::Vector3f scale)
	{
		glRotatef(angle, scale.x, scale.y, scale.z);
	}

	void RenderOpenGL::setProjectionType(E_PROJECTION_TYPE eType)
	{
		switch(eType)
		{
		case PT_PROJECTION:
			glMatrixMode(GL_PROJECTION);
			break;
		case PT_MODELVIEW:
			glMatrixMode(GL_MODELVIEW);
			break;
		}
	}

	void RenderOpenGL::loadIdentity()
	{
		glLoadIdentity();
	}

	void RenderOpenGL::setCameraPerspective(float32 fovValue, float32 nearValue, float32 farValue)
	{
		gluPerspective(fovValue,(GLfloat)core::Device::windowWidth/(GLfloat)core::Device::windowHeight, nearValue, farValue);
	}

	void RenderOpenGL::setCameraTranslation(const math::Vector3f &translation, const math::Vector3f &target, const math::Vector3f &upVector)
	{
		gluLookAt(
			translation.x, translation.y, translation.z,
			target.x, target.y, target.z,
			upVector.x, upVector.y, upVector.z);
	}

	void RenderOpenGL::setFeatureStatus(E_FEATURE_TYPE eType, bool value)
	{
		switch(eType)
		{
		case FT_TEXTURE:
			(value) ? glEnable(GL_TEXTURE_2D) : glDisable(GL_TEXTURE_2D);
			break;
		case FT_BLEND:
			(value) ? glEnable(GL_BLEND) : glDisable(GL_BLEND);
			break;
		case FT_CULL_FACE:
			(value) ? glEnable(GL_CULL_FACE) : glDisable(GL_CULL_FACE);
			break;
		case FT_DEPTH_TEST:
			(value) ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
			break;
		}
	}

	void RenderOpenGL::setMaterialProperty(scene::MaterialProperty *pProperty)
	{
		assert(pProperty);

		GLfloat value[4];

		value[0] = pProperty->getDiffuse().r;
		value[1] = pProperty->getDiffuse().g;
		value[2] = pProperty->getDiffuse().b;
		value[3] = pProperty->getAlphaValue();
		glMaterialfv(GL_FRONT, GL_DIFFUSE, value);

		value[0] = pProperty->getAmbient().r;
		value[1] = pProperty->getAmbient().g;
		value[2] = pProperty->getAmbient().b;
		//value[3] = pProperty->getAmbient().a;
		glMaterialfv(GL_FRONT, GL_AMBIENT, value);

		value[0] = pProperty->getSpecular().r;
		value[1] = pProperty->getSpecular().g;
		value[2] = pProperty->getSpecular().b;
		//value[3] = pProperty->getSpecular().a;
		glMaterialfv(GL_FRONT, GL_SPECULAR, value);

		value[0] = pProperty->getEmissive().r;
		value[1] = pProperty->getEmissive().g;
		value[2] = pProperty->getEmissive().b;
		value[3] = pProperty->getEmissive().a;
		glMaterialfv(GL_FRONT, GL_EMISSION, value);

		glMaterialf(GL_FRONT, GL_SHININESS, pProperty->getShininess());
	}

	void RenderOpenGL::setAlphaProperty(scene::AlphaProperty *pProperty)
	{
		assert(pProperty);

		glBlendFunc(E_GL_FUNCTION[pProperty->getSourceFunction()],
			E_GL_FUNCTION[pProperty->getDestinationFunction()]);
	}

	uint32 RenderOpenGL::setTextureProperty(scene::TextureProperty *pProperty)
	{
		assert(pProperty);

		GLuint texture = 0;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		gluBuild2DMipmaps(GL_TEXTURE_2D, 
			pProperty->getChannels(),
			pProperty->getWidth(),
			pProperty->getHeight(),
			pProperty->getFormat(),
			GL_UNSIGNED_BYTE,
			pProperty->getTextureData());

		return texture;
	}

	void RenderOpenGL::setLight(scene::Light *pLight)
	{
		assert(pLight);

		GLenum glLight = GL_LIGHT0 + pLight->getLightNumber();

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, &pLight->getAmbient().r);

		glLightfv(glLight, GL_AMBIENT,  &pLight->getAmbient().r);
		glLightfv(glLight, GL_DIFFUSE,  &pLight->getDiffuse().r);
		glLightfv(glLight, GL_SPECULAR, &pLight->getSpecular().r);

		if(pLight->getLightType() == scene::Light::LT_POINT)
		{
			math::Vector4f Pos;

			Pos.x = pLight->getTranslation().x;
			Pos.y = pLight->getTranslation().y;
			Pos.z = pLight->getTranslation().z;
			Pos.w = 1.0f;

			glLightfv(glLight, GL_POSITION, &Pos.x);
			GLenum err = glGetError();

			glLightf(glLight, GL_SPOT_CUTOFF, 180.0f);

			glLightf(glLight, GL_CONSTANT_ATTENUATION, 1.0f);
			glLightf(glLight, GL_LINEAR_ATTENUATION, 0.0f);
			glLightf(glLight, GL_QUADRATIC_ATTENUATION, 0.0f);
		}
		else if(pLight->getLightType() == scene::Light::LT_SPOT)
		{
			glLightfv(glLight, GL_POSITION, &pLight->getTranslation().x);
			glLightfv(glLight, GL_SPOT_DIRECTION, &pLight->getDirection().x);

			float32 exponent, cutoff;
			pLight->getSpotParams(exponent, cutoff);
			glLightf(glLight, GL_SPOT_EXPONENT, exponent);
			glLightf(glLight, GL_SPOT_CUTOFF, cutoff);

			glLightf(glLight, GL_CONSTANT_ATTENUATION, 0.5f);
			glLightf(glLight, GL_LINEAR_ATTENUATION, 0.0f);
			glLightf(glLight, GL_QUADRATIC_ATTENUATION, 0.0f);
		}
		else if(pLight->getLightType() == scene::Light::LT_DIRECTIONAL)
		{
			math::Vector4f Dir;

			Dir.x = -pLight->getDirection().x;
			Dir.y = -pLight->getDirection().y;
			Dir.z = -pLight->getDirection().z;
			Dir.w = 0.0f;

			glLightfv(glLight, GL_POSITION, &Dir.x);
		}

		if(pLight->isEnabled())
			glEnable(glLight);
		glEnable(GL_LIGHTING);

	}

	void RenderOpenGL::bindImage(uint32 number)
	{
		glBindTexture(GL_TEXTURE_2D, number);
	}
} //namespace

#endif
