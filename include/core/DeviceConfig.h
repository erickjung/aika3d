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

#ifndef __DEVICE_CONFIG_H__
#define __DEVICE_CONFIG_H__

#include <render/Render.h>

namespace core
{
    /**
     * The render type.
     */
    enum E_DEVICE_TYPE
    {
        DT_WIN32 = 0,  //!< Windows type
        DT_LINUX	   //!< Linux type
    };

    /**
     * @brief
     * The Device configuration.
     */
    class DeviceConfig
    {
    public:
        /**
        * Constructor.
        */
        DeviceConfig() 
			: pTitleName(NULL), 
			pDataPath(NULL),
			width(0), 
			height(0),
			bits(32),
			renderType(render::RT_OPENGL),
			deviceType(DT_WIN32),
			useShaders(false),
			fullScreen(false)
		{}

        /**
        * The title name.
        */
        const char* pTitleName;

        /**
        * The data path.
        */
        const char* pDataPath;

        /**
        * The screen width.
        */
        int16 width;

        /**
        * The screen height.
        */
        int16 height;

        /**
        * The bits.
        */
        int16 bits;

		/**
        * The render type.
        */
        render::E_RENDER_TYPE renderType;

        /**
        * The device type.
        */
        core::E_DEVICE_TYPE deviceType;

        /**
        * Use shaders.
        */
        bool useShaders;

        /**
        * Use fullscreen.
        */
		bool fullScreen;
    };
}

#endif //__DEVICE_CONFIG_H__
