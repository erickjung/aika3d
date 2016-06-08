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

#include "AppFramework.h"

AppFramework::AppFramework(const char* pTitle, int16 windowWidth, int16 windowHeight, bool fullscreen)
: _mainDevice(NULL), 
_mainRender(NULL), 
_lastTime(-1.0f), 
_timeInSeconds(0.0f),
_framerate(0.0f),
_click(0),
_quitApp(false)
{
    DeviceConfig config;
    config.pTitleName = pTitle;
    config.width = windowWidth;
    config.height = windowHeight;
#if defined(WIN32)
    config.deviceType = core::DT_WIN32;
#endif
    config.renderType = render::RT_OPENGL;
	config.fullScreen = fullscreen;

	_mainDevice = kNew(Device);
	assert(_mainDevice);
    _mainDevice->createDevice(config);

    _mainRender = _mainDevice->getRenderInstance();
    assert(_mainRender);
}

AppFramework::~AppFramework()
{
	kDelete(_mainDevice);
}

void AppFramework::calculateTime()
{
	if (_lastTime == -1.0f)
	{
		_lastTime = _mainDevice->getDeviceInstance()->getTimeInSeconds();
	}

	float32 currentTime = _mainDevice->getDeviceInstance()->getTimeInSeconds();
	float32 delta = currentTime - _lastTime;
	_lastTime = currentTime;

	_timeInSeconds += delta;

	_framerate = _click / _timeInSeconds;
}

void AppFramework::onLoop()
{
	onCreate();

	while (_mainDevice->run() && !_quitApp)
    {
		// calculate time, framerate, etc
		calculateTime();

		// begin the render properties
        _mainRender->begin(0.2f, 0.2f, 0.2f, 1.0f);

		// process the input buttons
		processInput();

		// process the update data
		onUpdate();

		// process the draw data
		onDraw();

		// end render
		_mainRender->end();

		// add click
		_click++;
    }
}

void AppFramework::quitApp()
{
	_quitApp = true;
}

float32 AppFramework::getFrameRate()
{
	return _framerate;
}

float32 AppFramework::getElapsedTime()
{
	return _timeInSeconds;
}

int main()
{
	AppFramework *appFramework = AppFramework::createApp();

	appFramework->onLoop();

	kDelete(appFramework);
}
