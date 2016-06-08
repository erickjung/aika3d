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

#include <core/Device.h>
#include <core/DeviceWin32.h>
#include <render/RenderOpenGL.h>
//#include <render/RenderDirectx.h>

namespace core
{
	render::Render *Device::_renderInstance = NULL;
	Device *Device::_deviceInstace = NULL;
	float32 Device::windowWidth = NULL;
	float32 Device::windowHeight = NULL;
	lang::String Device::_dataPath;
	

    Device::Device() 
        : _pDeviceWindow(NULL), 
		_pRenderDevice(NULL)
    {
    }

    Device::~Device()
    {
        kDelete(_pDeviceWindow);
		kDelete(_pRenderDevice);
    }

	void Device::setDataPath(lang::String path)
	{
		_dataPath = path;
	}

	lang::String &Device::getDataPath()
	{
		return _dataPath;
	}

    bool Device::createWindow(DeviceConfig &device)
    {
        TRACE("Device::createWindow");

        return false;
    }

    bool Device::createDevice(DeviceConfig &device)
    {
        TRACE("Device::createDevice");

        switch (device.deviceType)
        {
        case core::DT_WIN32:
#ifdef WIN32
            _pDeviceWindow = kNew(DeviceWin32);
#else       
            Log::log << "Windows device was not compiled\n";
#endif
            break;

        case core::DT_LINUX:
            Log::log << "Linux device was not compiled\n";
            break;

        default:
            Log::log << "Device doesn't exist\n";
            break;
        }

		_deviceInstace = _pDeviceWindow;

        return (_pDeviceWindow) ? _pDeviceWindow->createWindow(device) : false;
    }

    bool Device::createRender(DeviceConfig &device, HWND hWnd)
    {
        TRACE("Device::createRender");

        switch (device.renderType)
        {
        case render::RT_OPENGL:
#if AK_OPENGL
            _pRenderDevice = kNew(render::RenderOpenGL);
#else
            Log::log << "OpenGL was not compiled\n";
#endif
            break;

        case render::RT_DIRECTX:
#if AK_DIRECTX
//            _pRenderDevice = kNew(render::RenderDirectx);
//#else
            Log::log << "Directx was not compiled\n";
#endif
            break;

        default:
            Log::log << "Type not defined\n";
            break;
        }

		if(_pRenderDevice == NULL)
			return false;

		_pRenderDevice->initialize(hWnd);

		windowWidth = device.width;
		windowHeight = device.height;
		_renderInstance = _pRenderDevice;

		return true;
    }

    bool Device::run()
    {
        return (_pDeviceWindow) ? _pDeviceWindow->run() : false;
    }

	Device *Device::getDeviceInstance()
	{
		return _deviceInstace;
	}

	uint32 Device::getRealKey(uint32 input)
	{
		uint32 key = 0;
		for(int i=0; i < InputMap::KT_QUANTITY; i++)
		{
			if(keyMap[i] == input)
			{
				key = i;
				break;
			}
		}

		return key;
	}

    render::Render *Device::getRenderInstance()
    {
		return _renderInstance;
    }
} //namespace
