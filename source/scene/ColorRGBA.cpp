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

#include <scene/ColorRGBA.h>

namespace scene
{
	const ColorRGBA ColorRGBA::BLACK(0.0f,0.0f,0.0f,0.0f);
	const ColorRGBA ColorRGBA::WHITE(1.0f,1.0f,1.0f,1.0f);
	const ColorRGBA ColorRGBA::GRAY(0.5f,0.5f,0.5f,1.0f);

	ColorRGBA::ColorRGBA() :
		r(0), g(0), b(0), a(1)
	{
	}

	ColorRGBA::ColorRGBA(float32 r, float32 g, float32 b, float32 a) :
		r(r), g(g), b(b), a(a)
	{
	}
}