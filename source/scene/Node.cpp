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

#include <Scene/Node.h>
#include <stdio.h>

namespace scene
{

	Node::Node() : _used(0), _growBy(1)
	{
		TRACE("Node::Node");
	}

	Node::~Node() 
	{ 
		for(uint32 i=0; i < _child.getLength(); i++)
		{
			kDelete(_child[i]);
		}
	}

	int32 Node::attachChild(Node *pChild)
	{
		TRACE("Node::attachChild");
		assert(pChild);

		pChild->setParent(this);
		_used++;

		int32 quantity = _child.getLength();
		for(int32 i=0; i < quantity; i++)
		{
			if(_child[i] == 0)
			{
				_child[i] = pChild;
				return i;
			}
		}

		_child.add(pChild);

		return quantity;
	}

	int32 Node::detachChild(Node *pChild)
	{
		TRACE("Node::detachChild");
		assert(pChild);

		if(pChild)
		{
			for(uint32 i=0; i < _child.getLength(); i++)
			{
				if(_child[i] == pChild)
				{
					pChild->setParent(NULL);
					_child[i] = NULL;
					_used--;
					return i;
				}
			}
		}

		return -1;
	}

	void Node::update()
	{
		for(uint32 i=0; i < _child.getLength(); i++)
		{
			_child[i]->update();
		}
	}

	const Node * Node::getNodeAt(uint32 value)
	{
		Node * node = NULL;

		if(_child.getLength() > 0)
			node = _child[value];

		return node;
	}

	const Node * Node::getNodeByName(const char *pName)
	{
		Node * node = NULL;

		for(uint32 i=0; i < _child.getLength(); i++)
		{
			if(String::compareStrings(_child[i]->getName().getChars(), pName))
				node = _child[i];
		}

		return node;
	}


	void Node::draw(render::Render *pRender)
	{
		assert(pRender);

		for(uint32 i=0; i < _child.getLength(); i++)
		{
			_child[i]->draw(pRender);
		}
	}
}