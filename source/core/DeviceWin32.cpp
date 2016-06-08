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

#include <core/DeviceWin32.h>
#include <windows.h>

namespace core
{
    bool activeWindow;

	const int32 Device::keyMap[] =
	{
		0,
		'A',
		'B',
		'C',
		'D',
		'E',
		'F',
		'G',
		'H',
		'I',
		'J',
		'K',
		'L',
		'M',
		'N',
		'O',
		'P',
		'Q',
		'R',
		'S',
		'T',
		'U',
		'V',
		'W',
		'X',
		'Y',
		'Z',
		VK_TAB,
		VK_SHIFT,
		VK_CONTROL,
		VK_SPACE,
		VK_RETURN,
		VK_ESCAPE,
		VK_LEFT,
		VK_RIGHT,
		VK_UP,
		VK_DOWN,
		VK_F1,
		VK_F2,
		VK_F3,
		VK_F4,
		VK_F5,
		VK_F6,
		VK_F7,
		VK_F8,
		VK_F9,
		VK_F10,
		VK_F11,
		VK_F12
	};

    LRESULT CALLBACK WndProc(HWND _hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_ACTIVATE:
            {
                if (!HIWORD(wParam))
                {
                    activeWindow = true;
                }
                else
                {
                    activeWindow = false;
                }

                break;
            }

        case WM_SYSCOMMAND:
            {
                switch (wParam)
                {
                case SC_SCREENSAVE:
                case SC_MONITORPOWER:
                    break;
                }
                break;
            }

        case WM_CLOSE:
            {
                PostQuitMessage(0);
                break;
            }

        case WM_KEYDOWN:
            {
				InputMap::getInstance()->inputKey(core::Device::getRealKey(wParam));
                break;
            }

        case WM_KEYUP:
            {
                break;
            }
        }

        // Pass All Unhandled Messages To DefWindowProc
        return DefWindowProc(_hWnd, uMsg, wParam, lParam);
    }

    DeviceWin32::DeviceWin32()
    {}

    DeviceWin32::~DeviceWin32()
    {
		InputMap::deleteInstance();
    }

	float32 DeviceWin32::getTimeInSeconds()
	{
		float32 time = 0.001f * timeGetTime();

		return time;
	}

    bool DeviceWin32::createWindow(DeviceConfig &device)
    {
        TRACE("DeviceWin32::createWindow");

        assert(device.pTitleName != NULL && device.height > 0 && device.width > 0);

        WNDCLASSEX winClass;
        MSG uMsg;

        memset(&uMsg, 0, sizeof(uMsg));

        winClass.lpszClassName = "DeviceWin32";
        winClass.cbSize        = sizeof(WNDCLASSEX);
        winClass.style         = CS_HREDRAW | CS_VREDRAW;
        winClass.lpfnWndProc   = WndProc;
        winClass.hInstance     = _hInstance;
        winClass.hIcon	       = LoadIcon(NULL, IDI_WINLOGO);
        winClass.hIconSm	   = LoadIcon(NULL, IDI_WINLOGO);
        winClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
        winClass.hbrBackground = NULL; 
        winClass.lpszMenuName  = NULL;
        winClass.cbClsExtra    = 0;
        winClass.cbWndExtra    = 0;

        if ( !RegisterClassEx(&winClass) )
            return false;

		if(device.fullScreen)
		{
			DEVMODE screenSettings;								
			memset(&screenSettings,0,sizeof(screenSettings));	
			screenSettings.dmSize=sizeof(screenSettings);		
			screenSettings.dmPelsWidth	= device.width;				
			screenSettings.dmPelsHeight	= device.height;				
			screenSettings.dmBitsPerPel	= device.bits;					
			screenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

			if (ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN)!= DISP_CHANGE_SUCCESSFUL)
				return false;

			_hWnd = CreateWindowEx( WS_EX_APPWINDOW,
				"DeviceWin32",
				device.pTitleName,
				WS_POPUP,
				0, 0, device.width, device.height, 0, 0, _hInstance, 0 );

			ShowCursor(FALSE);		
		}
		else
		{
			_hWnd = CreateWindowEx( 0,
				"DeviceWin32",
				device.pTitleName,
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				0, 0, device.width, device.height, 0, 0, _hInstance, 0 );
		}

        if ( _hWnd == NULL )
            return false;

		if(!createRender(device, _hWnd))
			return false;

        ShowWindow(_hWnd, SW_SHOW );
        UpdateWindow(_hWnd);

        _pRenderDevice->setup(device.width, device.height);

		InputMap::createInstance();

        return true;
    }

    bool DeviceWin32::run()
    {
        MSG msg;

        bool quit = false;

        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);

            if (activeWindow && msg.hwnd == _hWnd)
                WndProc(_hWnd, msg.message, msg.wParam, msg.lParam);
            else
                DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
			{
                quit = true;
				Log::closeLogs();
			}
        }

        return !quit;
    }
} //namespace

#endif //WIN32
