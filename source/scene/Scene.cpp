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

#include <scene/Scene.h>

#include <scene/CameraNode.h>
#include <scene/Camera.h>
#include <scene/LightNode.h>
#include <scene/Light.h>
#include <scene/MeshNode.h>
#include <scene/Mesh.h>
#include <lang/String.h>

//----------------------------------------------------
#define STR_ROOT				"root"
#define STR_MAIN_NODE			"AKSCENE"
#define STR_CAMERALIST			"cameralist"
#define STR_LIGHTLIST			"lightlist"
#define STR_MESHLIST			"meshlist"

#define STR_CAMERA				"camera"
#define STR_CAMERA_FOV			"fov"
#define STR_CAMERA_NEAR			"near"
#define STR_CAMERA_FAR			"far"

#define STR_LIGHT				"light"
#define STR_LIGHT_COLOR			"color"
#define STR_LIGHT_SPECULAR		"specular"
#define STR_LIGHT_AMBIENT		"ambient"
#define STR_LIGHT_EXPONENT		"exponent"
#define STR_LIGHT_CUTOFF		"cutoff"
#define STR_LIGHT_SPOTDATA		"spotdata"
#define STR_LIGHT_SPOT			"Spot"
#define STR_LIGHT_POINT			"Point"
#define STR_LIGHT_DIRECTIONAL	"Directional"

#define STR_MESH				"mesh"

#define STR_FILENAME			"filename"
#define STR_TYPE				"type"
#define STR_NAME				"name"
#define STR_TRANSLATE			"translate"
#define STR_TARGET				"target"
#define STR_ROTATE			    "rotate"
#define STR_SCALE			    "scale"
#define STR_ANGLE			    "angle"
#define STR_VALUE				"value"
#define STR_X					"x"
#define STR_Y					"y"
#define STR_Z					"z"
#define STR_R					"r"
#define STR_G					"g"
#define STR_B					"b"
#define STR_A					"a"
//----------------------------------------------------

namespace scene
{
	Scene::Scene()
	{
		TRACE("Scene::Scene");

		setType(Node::T_SCENE);
	}

	Scene::~Scene()
	{
	}

	bool Scene::openScene(const char *fileName)
	{
		TRACE("Scene::openScene");

		lang::String filename = core::Device::getDataPath();
		filename.concat(fileName);

		setName(STR_ROOT);
		xml = createIrrXMLReader(filename.getChars());
		if(!xml)
			return false;

		lang::String meshFile;

		while(xml && xml->read())
		{
			if(xml->getNodeType() == EXN_ELEMENT)
			{
				if (String::compareStrings(STR_MAIN_NODE, xml->getNodeName()))
					openXml();
			}
		}

		// delete the xml parser after usage
		delete xml;

		return true;
	}

	void Scene::openXml()
	{
		TRACE("Scene::openXml");

		while(xml->read())
		{
			if (xml->getNodeType() == EXN_ELEMENT)
			{
				if (String::compareStrings(STR_CAMERALIST, xml->getNodeName()))
					readCamera();
				else if (String::compareStrings(STR_LIGHTLIST, xml->getNodeName()))
					readLight();
				else if (String::compareStrings(STR_MESHLIST, xml->getNodeName()))
					readMesh();
			}
		}
	}

	void Scene::readCamera()
	{
		TRACE("Scene::readCamera");

		uint32 cameraNumber = 0;

		while(xml->read())
		{
			if (xml->getNodeType() == EXN_ELEMENT)
			{
				if (String::compareStrings(STR_CAMERA, xml->getNodeName()))
				{
					cameraNumber++;

					CameraNode *cameraNode = kNew(CameraNode);
					Camera *camera = kNew(Camera);
					//if(cameraNumber <= 1)
						camera->setEnable(true);

					lang::String name = xml->getAttributeValue(STR_NAME);

					cameraNode->setName(name.getChars());
					cameraNode->setCamera(camera);

					float32 fovValue, nearValue, farValue;

					while(xml->read())
					{
						if (xml->getNodeType() == EXN_ELEMENT)
						{
							if (String::compareStrings(STR_TRANSLATE, xml->getNodeName()))
							{
								float32 x,y,z;
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								camera->setTranslation(math::Vector3f(x,y,z));
							}
							else if (String::compareStrings(STR_ROTATE, xml->getNodeName()))
							{
								float32 angle, x,y,z;
								angle = xml->getAttributeValueAsFloat(STR_ANGLE);
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								camera->setRotation(angle, math::Vector3f(x,y,z));
							}
							else if (String::compareStrings(STR_TARGET, xml->getNodeName()))
							{
								float32 x,y,z;
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								camera->setTarget(math::Vector3f(x,y,z));
							}
							else if (String::compareStrings(STR_CAMERA_FOV, xml->getNodeName()))
							{
								fovValue = xml->getAttributeValueAsFloat(STR_VALUE);
							}
							else if (String::compareStrings(STR_CAMERA_NEAR, xml->getNodeName()))
							{
								nearValue = xml->getAttributeValueAsFloat(STR_VALUE);
							}
							else if (String::compareStrings(STR_CAMERA_FAR, xml->getNodeName()))
							{
								farValue = xml->getAttributeValueAsFloat(STR_VALUE);
								break;
							}
						}
					}

					camera->setPerspective(fovValue, nearValue, farValue);
					attachChild(cameraNode);
				}
			}
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{
				if (String::compareStrings(STR_CAMERALIST, xml->getNodeName()))
					break;
			}

		}
	}

	void Scene::readLight()
	{
		TRACE("Scene::readLight");

		while(xml->read())
		{
			if (xml->getNodeType() == EXN_ELEMENT)
			{
				if (String::compareStrings(STR_LIGHT, xml->getNodeName()))
				{
					static int32 number = 0;
					static bool isSpot = false;

					LightNode *lightNode = kNew(LightNode);
					Light *light = kNew(Light);
					light->setLightNumber(number);

					lang::String name = xml->getAttributeValue(STR_NAME);

					lightNode->setName(name.getChars());
					lightNode->setLight(light);

					while(xml->read())
					{
						if (xml->getNodeType() == EXN_ELEMENT)
						{
							if (String::compareStrings(STR_TRANSLATE, xml->getNodeName()))
							{
								float32 x,y,z;
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								light->setTranslation(math::Vector3f(x,y,z));

							}
							else if (String::compareStrings(STR_LIGHT_COLOR, xml->getNodeName()))
							{
								float32 r,g,b,a;
								r = xml->getAttributeValueAsFloat(STR_R);
								g = xml->getAttributeValueAsFloat(STR_G);
								b = xml->getAttributeValueAsFloat(STR_B);
								a = xml->getAttributeValueAsFloat(STR_A);
								light->setDiffuse(ColorRGBA(r,g,b,a));
							}
							else if (String::compareStrings(STR_LIGHT_SPECULAR, xml->getNodeName()))
							{
								float32 r,g,b,a;
								r = xml->getAttributeValueAsFloat(STR_R);
								g = xml->getAttributeValueAsFloat(STR_G);
								b = xml->getAttributeValueAsFloat(STR_B);
								a = xml->getAttributeValueAsFloat(STR_A);
								light->setSpecular(ColorRGBA(r,g,b,a));
							}
							else if (String::compareStrings(STR_LIGHT_AMBIENT, xml->getNodeName()))
							{
								float32 r,g,b,a;
								r = xml->getAttributeValueAsFloat(STR_R);
								g = xml->getAttributeValueAsFloat(STR_G);
								b = xml->getAttributeValueAsFloat(STR_B);
								a = xml->getAttributeValueAsFloat(STR_A);
								light->setAmbient(ColorRGBA(r,g,b,a));
							}
							else if (String::compareStrings(STR_TYPE, xml->getNodeName()))
							{
								lang::String str = xml->getAttributeValue(STR_VALUE);

								if(String::compareStrings(STR_LIGHT_POINT, str.getChars()))
									light->setLightType(Light::LT_POINT);
								else if(String::compareStrings(STR_LIGHT_SPOT, str.getChars()))
								{
									light->setLightType(Light::LT_SPOT);
									isSpot = true;
								}
								else if(String::compareStrings(STR_LIGHT_DIRECTIONAL, str.getChars()))
									light->setLightType(Light::LT_DIRECTIONAL);

								if(!isSpot)
									break;
							}
							else if (String::compareStrings(STR_LIGHT_SPOTDATA, xml->getNodeName()) && isSpot)
							{
								float32 exp, cut;
								exp = xml->getAttributeValueAsFloat(STR_LIGHT_EXPONENT);
								cut = xml->getAttributeValueAsFloat(STR_LIGHT_CUTOFF);

								light->setSpotParams(exp, cut);
								isSpot = false;

								break;
							}
						}
					}

					number++;
					attachChild(lightNode);
				}
			}
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{
				if (String::compareStrings(STR_LIGHTLIST, xml->getNodeName()))
					break;
			}
		}
	}

	void Scene::readMesh()
	{
		TRACE("Scene::readMesh");

		while(xml->read())
		{
			if (xml->getNodeType() == EXN_ELEMENT)
			{
				if (String::compareStrings(STR_MESH, xml->getNodeName()))
				{
					Mesh *mesh = kNew(Mesh);
					MeshNode *meshNode = kNew(MeshNode);

					lang::String name = xml->getAttributeValue(STR_NAME);
					//lang::String filename = xml->getAttributeValue(STR_FILENAME);
					lang::String filename(core::Device::getDataPath());
					filename.concat(xml->getAttributeValue(STR_FILENAME));

					mesh->load(filename.getChars());

					meshNode->setName(name.getChars());
					meshNode->setMesh(mesh);

					while(xml->read())
					{
						if (xml->getNodeType() == EXN_ELEMENT)
						{
							if (String::compareStrings(STR_TRANSLATE, xml->getNodeName()))
							{
								float32 x,y,z;
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								mesh->setTranslation(math::Vector3f(x,y,z));
							}
							else if (String::compareStrings(STR_ROTATE, xml->getNodeName()))
							{
								float32 angle, x,y,z;
								angle = xml->getAttributeValueAsFloat(STR_ANGLE);
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								mesh->setRotation(angle, math::Vector3f(x,y,z));
							}
							else if (String::compareStrings(STR_SCALE, xml->getNodeName()))
							{
								float32 x,y,z;
								x = xml->getAttributeValueAsFloat(STR_X);
								y = xml->getAttributeValueAsFloat(STR_Y);
								z = xml->getAttributeValueAsFloat(STR_Z);
								mesh->setScale(math::Vector3f(x,y,z));
								break;
							}
						}
					}
					attachChild(meshNode);
				}
			}
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{
				if (String::compareStrings(STR_MESHLIST, xml->getNodeName()))
					break;
			}

		}
	}
}
