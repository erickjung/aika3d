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

#include <util/Object.h>
#include <util/Assert.h>
#include <util/Log.h>

#define NEW_STR "NEW"
#define DEL_STR "DEL"

int32 Object::_instanceCount = 0;

Object::Object()
{
}

Object::~Object()
{
}

void* Object::operator new(size_t size)
{
    void *pPointer = NULL;

    if(size != sizeof(Object))
    {
        pPointer = ::operator new(size);

        if (pPointer != NULL)
        {
            memset(pPointer, 0, size);  

            //Log::memAlloc(NEW_STR, __FILE__, __LINE__, (pPointer), (size));
        }
    }

    // extra check
    assert(pPointer);

    if(size == 0)
        size = 1;

    _instanceCount++;
    return pPointer;
}

void Object::operator delete(void *pPointer)
{
    if (pPointer != NULL)
    {
        ::operator delete(pPointer);
        pPointer = NULL;

        _instanceCount--;

        //Log::memAlloc(DEL_STR, __FILE__, __LINE__);
    }
}

bool Object::equals(Object *pObject)
{
    return (this == pObject);
}

int32 Object::instances()
{
    return _instanceCount;
}

void Object::showPointer()
{
    Log::log << "Pointer: " << ((void *)this) << "\n";
}

Object* Object::clone()
{
    // temporary copy reference
    return this;
}
