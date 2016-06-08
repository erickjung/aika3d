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

#ifndef AIKA_H_
#define AIKA_H_

#include <core/Namespace-core.h>
#include <io/Namespace-io.h>
#include <lang/Namespace-lang.h>
#include <math/Namespace-math.h>
#include <render/Namespace-render.h>
#include <scene/Namespace-scene.h>
#include <img/Namespace-img.h>

/** 
 * @mainpage Aika API Documentation
 * @section author Author 
 * - Erick Jung (erickjung@gmail.com)
 *
 * @section intro Introduction
 *
 * Welcome to the Aika API documentation.\n\n
 * Aika is a simple and powerful Game Engine, written in C++ (without any platform dependence),\n
 * you could compile and run aika on several types of platform (including nintendo ds, symbian, etc).
 *
 * The main proposal of the engine is to create a portable and easy of use framework to create multimedia content, e.g. games.  
 *
 * @section license License
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/**
 * @page compile Compile Instructions
 *
 * @section intro Details
 *
 * You could compile Aika using the visual c++ 8 project.
 *
 * - To use the Visual C++ 8, go to "\projects\vc8\".
 *
 * Pre-Processor:
 * AK_DYN_EXPORT
 * - Used to compile the lib/dll
 *
 * AK_DEBUG
 * - If you wanna use memory, assertion and trace traking
 *
 * AK_OPENGL
 * - Used to compile the engine with opengl support.
 *
 * AK_DIRECTX
 * - Used to compile the engine with directx support. (removed for now).
 */

/**
 * @brief
 * The aika namespace
 *
 * @note
 * Used to group all the namespaces
 */
namespace aika
{
    using namespace core;
    using namespace io;
    using namespace lang;
    using namespace math;
    using namespace render;
    using namespace scene;
    using namespace img;
}

#endif /*AIKA_H_*/
