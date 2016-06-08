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

#include <scene/MeshNode.h>
#include <scene/Mesh.h>

namespace scene
{
	MeshNode::MeshNode()
	{
		TRACE("MeshNode::MeshNode");

		setType(Node::T_MESH);
	}

	MeshNode::~MeshNode()
	{
		kDelete(_pModel);
	}

	void MeshNode::draw(render::Render *pRender)
	{
		Node::draw(pRender);

		pRender->setProjectionType(render::PT_MODELVIEW);
		pRender->pushMatrix();
		{
			pRender->setTranslation(math::Vector3f(_pModel->getTranslation()));
			// TODO: Add the rotation support on the mesh class

			_pModel->getRotation(_rotateAngle, _rotate);
			pRender->setRotation(_rotateAngle, _rotate);

			pRender->setScale(_pModel->getScale());

			_pModel->draw(pRender);
		}
		pRender->popMatrix();


	}
}
