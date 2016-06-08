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

#ifdef WIN32

#ifndef DEVICEWIN32_H_
#define DEVICEWIN32_H_

#include <windows.h>
#include <core/Device.h>

namespace core
{
    /**
     * @brief
     * The windows device specific implementation.
     */
    class API_STATE DeviceWin32 : public Device
    {
    public:
        /**
         * Constructor
         */
        DeviceWin32();

        /**
         * Destructor
         */
        virtual ~DeviceWin32();

        /**
         * @see Device::run()
         */
        bool run();

        /**
         * @see Device::createWindow(render::E_RENDER_TYPE renderType)
         */
        bool createWindow(DeviceConfig &device);

		/**
         * Return the time in seconds
         */
		float32 getTimeInSeconds();

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: DeviceWin32";}

    private:
        /**
         * The window handle.
         */
        HWND _hWnd;

        /**
         * The application instance.
         */
        HINSTANCE _hInstance;

    };
}

#endif /*DEVICEWIN32_H_*/

#endif // WIN32
