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

#ifndef __SCENE_H__
#define __SCENE_H__

#include <scene/Node.h>
#include <irrxml/irrXml.h>
using namespace irr; // irrXML is located in the namespace irr::io

namespace scene
{
    /**
     * @brief
     * This is the scene node class. This class is used to load the AKS (Aika scene file).
     */
	class API_STATE Scene : public Node
	{
	public:
        /**
         * Constructor
         */
		Scene();

        /**
         * Destructor
         */
		~Scene();

        /**
         * Open the scene file.
         *
         * @param pFilename The name of file
		 * @return true if opened the file
         */
		bool openScene(const char* pFilename);

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "Class: Scene";}

	private:
        /**
         * Parse the xml main structure.
         */
		void openXml();

        /**
         * Parse the xml mesh structure.
         */
		void readMesh();

        /**
         * Parse the xml camera structure.
         */
		void readCamera();

        /**
         * Parse the xml light structure.
         */
		void readLight();

        /**
         * The xml parser (using IrrXml for now).
         */
		IrrXMLReader* xml;
	};
}

#endif