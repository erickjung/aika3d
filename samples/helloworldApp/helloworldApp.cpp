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

#include "helloworldApp.h"
#include <scene/Mesh.h>
#include <scene/MeshNode.h>

Demo::Demo() : AppFramework("Hello World Sample (using AppFramework)", 800, 600, false), _pCamera(NULL)
{
	Device::setDataPath("../media/");
}

void Demo::printFramerate()
{
	_mainRender->writeText(10, 14, "Aika");

	String strFrameRate = String::intToStr((int)getFrameRate());
	strFrameRate.concat(" fps");
	_mainRender->writeText(10, 13, strFrameRate.getChars());
}

void Demo::processInput()
{
	InputMap *input = InputMap::getInstance();

	if(input->verifyIfWasPressed(InputMap::KT_ESC))
	{
		quitApp();
	}
}

void Demo::onCreate()
{
	_scene.openScene("scene.aks");

	const CameraNode * cameraNode = (CameraNode*)_scene.getNodeByName("Camera");
	if(cameraNode)
	{
		_pCamera = (Camera*)cameraNode->getCamera();
		_pCamera->initialize();
	}

}

void Demo::onUpdate()
{
	static float incr = 0;
	incr+=0.01f;

	static float incr1 = 0;
	incr1 -= 0.1f;

	_scene.update();

	MeshNode *skyNode = (MeshNode*)_scene.getNodeByName("Skydome");
	if(skyNode)
		skyNode->getMesh()->setRotation(incr, math::Vector3f.UNIT_Y);

	MeshNode *duckNode = (MeshNode*)_scene.getNodeByName("Duck");
	if(duckNode)
		duckNode->getMesh()->setRotation(incr1, math::Vector3f.UNIT_Y);

	if(_pCamera)_pCamera->update();
}

void Demo::onDraw()
{
	_scene.draw(_mainRender);

	printFramerate();
}