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

#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <core/DeviceConfig.h>
#include <core/InputMap.h>
#include <lang/String.h>

namespace core
{
    /**
     * @brief
     * This is an abstract class, where all the specific device context need to extend.
     *  - All the device classes need to extend from this class.
     * 
     * @note
     * All the device classes need to extend from this class.
     */
    class API_STATE Device : public Object
    {
    public:
        /**
         * Window width
         */
		static float32 windowWidth;

		/**
         * Window height
         */
		static float32 windowHeight;

        /**
         * Constructor
         */
        Device();

		/**
         * Destructor
         */
        virtual ~Device();

        /**
         * Create the main device
         *
         * @param device The device configuration
         */
        bool createDevice(DeviceConfig &device);

		/**
         * Initialize the render
         */
        virtual bool run();

        /**
         * Return the time in seconds
         */
		virtual float32 getTimeInSeconds(){return 0;}

        /**
         * Set the data path
         *
         * @param path The data path
         */
		static void setDataPath(lang::String path);

        /**
         * Get the data path
         *
         * @return The data path
         */
		static lang::String &getDataPath();

		/**
         * An auxiliar method to get the real key.
         */
		static uint32 getRealKey(uint32 input);

        /**
         * Return the render object instance
         */
        static render::Render *getRenderInstance();

        /**
         * Return the device object instance
         */
		static Device *getDeviceInstance();

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Device";}

	protected:
        /**
         * The platform specific key map
         */
		static const int32 keyMap[];

        /**
         * The render device.
         */
        render::Render *_pRenderDevice;

        /**
         * Create the window.
         * 
         * @param renderType The type of render (e.g. RT_OPENGL).
         * @return Returns true if success.
         */
        virtual bool createWindow(DeviceConfig &device);

        /**
         * An auxiliar method to create the render.
         */
        bool createRender(DeviceConfig &device, HWND hWnd);

    private:

        /**
         * The device.
         */
        Device *_pDeviceWindow;

        /**
         * The static render instance.
         */
		static render::Render *_renderInstance;

        /**
         * The static device instance.
         */
		static Device* _deviceInstace;

        /**
         * The data path.
         */
		static lang::String _dataPath;
    };
}

#endif /*DEVICENULL_H_*/
