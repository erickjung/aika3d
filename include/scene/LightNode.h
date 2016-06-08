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

#ifndef __LIGHTNODE_H__
#define __LIGHTNODE_H__

#include <scene/Node.h>

namespace scene
{
	class Light;

    /**
     * @brief
     * This is the light node class.
     */
	class API_STATE LightNode : public Node
	{
	public:
        /**
         * Constructor
         */
		LightNode();

        /**
         * Destructor
         */
		virtual ~LightNode();

        /**
         * @see Node::draw()
         */
		virtual void draw(render::Render *pRender);

        /**
         * Set the light on the node
         *
		 * @param pLight The light object
         */
		void setLight(Light *pLight);

        /**
         * Get the light on the node
         *
		 * @return the light
         */
		const Light* getLight() const;
		Light* getLight();

	private:
        /**
         * The light object
         */
		Light *_pLight;
	};

#include <scene/LightNode.inl>
}
#endif