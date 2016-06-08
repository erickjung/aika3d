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

#ifndef __NODE_H__
#define __NODE_H__

#include <lang/String.h>
#include <util/Object.h>
#include <util/Log.h>
#include <core/Device.h>
#include <math/Vector2.h>
#include <math/Vector3.h>
#include <math/Vector4.h>
#include <scene/ColorRGBA.h>

using namespace render;
using namespace lang;

namespace scene
{
    /**
     * @brief
     * This is the main node class.
     *  - All the node classes need to extend from this class.
     */
	class API_STATE Node : public Object
	{
	public:
		/**
		 * The node type.
		 */
		enum E_TYPE
		{
			T_CAMERA = 0,
			T_LIGHT,
			T_MESH,
			T_SCENE
		};

        /**
         * Constructor
         */
		Node();

        /**
         * Destructor
         */
		virtual ~Node();

        /**
         * Get the size
         *
		 * @return the size
         */
		int32 getSize() const;

        /**
         * Attach the child to node
         *
         * @param pChild The child
		 * @return the size
         */
		int32 attachChild(Node* pChild);

        /**
         * Detach the child to node
         *
         * @param pChild The child
		 * @return the size
         */
		int32 detachChild(Node* pChild);

        /**
         * Set the parent to the node
         *
         * @param pParent The parent
         */
		void setParent(Node* pParent);

        /**
         * Get the parent
         *
		 * @return the parent
         */
		Node *getParent();

        /**
         * Get the specific node by value
         *
		 * @param value The node position
		 * @return the node (if not, return NULL)
         */
		const Node *getNodeAt(uint32 value);

        /**
         * Get the specific node by name
         *
		 * @param value The node name
		 * @return the node (if not, return NULL)
         */
		const Node *getNodeByName(const char *pName);

        /**
         * Update the node
         */
		virtual void update();

        /**
         * Update selected the node
		 *
		 * @note This will only update the specific node
         */
		virtual void updateSelected(){}

        /**
         * Draw
		 *
		 * @param pRender The render instance
         */
		virtual void draw(render::Render *pRender);

        /**
         * Set the node name
		 *
		 * @param pName The name of the node
         */
		void setName(const char* pName);

        /**
         * Get the node name
		 *
		 * @return The name of the node
         */
		const lang::String getName();

        /**
         * Set the node type
		 *
		 * @param eType The type of the node
         */
		void setType(E_TYPE eType);

        /**
         * Get the node type
		 *
		 * @return The type of the node
         */
		E_TYPE getType();

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: Node";}

	private:
        /**
         * The name of node
         */
		lang::String _name;

        /**
         * The node
         */
		lang::Array<Node*> _child;

        /**
         * The node parent
         */
		Node * _pParent;

        /**
         * The number to increase the node list
         */
		int32 _growBy;

        /**
         * The size of node
         */
		int32 _used;

        /**
         * The node type
         */
		E_TYPE _eType;
	};

#include <scene/Node.inl>
}
#endif
