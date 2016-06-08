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

#include <aika.h>
#include <core/Device.h>
#include <stdio.h>
#include <lang/String.h>
#include <util/Assert.h>

#include <scene/Scene.h>
#include <scene/CameraNode.h>
#include <scene/Camera.h>

#include <util/Ptr.h>
#include <math/Vector3.h>

#include <scene/Mesh.h>
#include <scene/MeshNode.h>

using namespace aika;

float lastTime = -1.0f;
float elapsedTime = 0.0f;
float framerate = 0.0f;
int click = 0;

void printData(int &click, render::Render *pRender, core::Device *dev)
{
	if ( lastTime == -1.0f )
	{
		lastTime = dev->getDeviceInstance()->getTimeInSeconds();
	}
	float fCurrentTime = dev->getDeviceInstance()->getTimeInSeconds();
	float fDelta = fCurrentTime - lastTime;
	lastTime = fCurrentTime;
	elapsedTime += fDelta;

	framerate = click / elapsedTime;

	pRender->writeText(10, 14, "Aika");
	lang::String strFrameRate = lang::String::intToStr((int)framerate);
	strFrameRate.concat(" fps");
	pRender->writeText(10, 13, strFrameRate.getChars());
}

void testEngine()
{
	Device::setDataPath("../media/");

	DeviceConfig config;
    config.pTitleName = "Hello World Sample";
    config.width = 800;
    config.height = 600;
    config.deviceType = core::DT_WIN32;
    config.renderType = render::RT_OPENGL;

	Ptr<Device> dev = kNew(Device);
	assert(dev);
    dev->createDevice(config);

    Render *rend = dev->getRenderInstance();
    assert(rend);

	Ptr<Scene> scene = kNew(Scene);
	scene->openScene("scene.aks");

	CameraNode *cameraNode = (CameraNode*)scene->getNodeByName("Camera");
	Camera *camera = (Camera*)cameraNode->getCamera();
	if(camera)
		camera->initialize();

	MeshNode *skyNode = (MeshNode*)scene->getNodeByName("Skydome");
	MeshNode *duckNode = (MeshNode*)scene->getNodeByName("Duck");

	InputMap *input = InputMap::getInstance();

	float incr = 0;
	float incr1 = 0;
	bool quitApp = false;
	while (dev->run() && quitApp == false)
    {
		if(input->verifyIfWasPressed(InputMap::KT_ESC))
			quitApp = true;

		incr+=0.01f;
		incr1 -= 0.1f;

        rend->begin(0.2f, 0.2f, 0.2f, 1.0f);

		scene->update();
		scene->draw(rend);

		if(camera)camera->update();

		if(skyNode)
			skyNode->getMesh()->setRotation(incr, math::Vector3f.UNIT_Y);

		if(duckNode)
			duckNode->getMesh()->setRotation(incr1, math::Vector3f.UNIT_Y);
		
		printData(click, rend, dev);

		rend->end();
		click++;
    }

    printf("\nInstances on: %d", Object::instances());
}

int main()
{
    testEngine();
    printf("\nInstances on: %d\n", Object::instances());
}




