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

#ifndef __APPFRAMEWORK_H__
#define __APPFRAMEWORK_H__

#include <aika.h>
#include <core/Device.h>
#include <util/Ptr.h>

using namespace aika;

/**
 * @brief
 * This is app framework.
 */
class AppFramework
{
public:
    /**
     * Destructor.
     */
	virtual ~AppFramework();

    /**
     * Constructor of the app instance.
     */
	static AppFramework * createApp();

    /**
     * Process the input.
     */
	virtual void processInput() = 0;

    /**
     * Used to create data before the main loop.
     */
	virtual void onCreate() = 0;

    /**
     * Update data.
     */
	virtual void onUpdate() = 0;

    /**
     * Draw data.
     */
	virtual void onDraw() = 0;

    /**
     * The main loop.
     */
	virtual void onLoop();

protected:
    /**
     * The main device instance.
     */
	Device *_mainDevice;

    /**
     * The main render instance.
     */
	Render *_mainRender;

    /**
     * Constructor.
	 *
	 * @param pTitle The window title
	 * @param windowWidth The window width
	 * @param windowHeight The window height
	 * @param fullscreen Set the fullscreen mode
     */
	AppFramework(const char* pTitle, int16 windowWidth, int16 windowHeight, bool fullscreen);

    /**
     * Get the framerate.
	 *
	 * @return The framerate
     */
	float32 getFrameRate();

    /**
     * Get the elapsed time.
	 *
	 * @return The elapsed time
     */
	float32 getElapsedTime();

    /**
     * Quit the app.
     */
	void quitApp();

private:
    /**
     * Flag used to quit the main loop.
     */
	bool _quitApp;

    /**
     * The last time.
     */
	float32 _lastTime;

    /**
     * The elapsed time.
     */
	float32 _timeInSeconds;

    /**
     * The framerate.
     */
	float32 _framerate;

    /**
     * The click.
     */
	uint32 _click;

    /**
     * Used to calculate the elapsed time and framerate.
     */
	void calculateTime();
};

#endif