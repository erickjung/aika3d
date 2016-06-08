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

#ifndef __CAMERANODE_H__
#define __CAMERANODE_H__

#include <scene/Node.h>

namespace scene
{
	class Camera;

    /**
     * @brief
     * This is the camera node class.
     */
	class API_STATE CameraNode : public Node
	{
	public:
        /**
         * Constructor
         */
		CameraNode();

        /**
         * Destructor
         */
		virtual ~CameraNode();

        /**
         * Set the camera on the node
         *
		 * @param pCamera The camera object
         */
		void setCamera(Camera *pCamera);

        /**
         * Get the camera on the node
         *
		 * @return the camera
         */
		const Camera* getCamera() const;
		Camera* getCamera();

	private:
        /**
         * The camera object
         */
		Camera *_pCamera;
	};

#include <scene/CameraNode.inl>
}
#endif