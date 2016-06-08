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

#ifndef OBJECT_H_
#define OBJECT_H_

#include <memory.h>
#include <util/Define.h>
#include <util/Types.h>

/**
 * Use this to log properly when we need to create a instance 
 */
#define kNew(classObject) new classObject; Log::memAlloc("NEW", __FILE__, __LINE__);

/**
 * Use this to log properly when we need to delete a instance 
 */
#define kDelete(instObject) delete instObject; if(instObject != NULL){Log::memAlloc("DEL", __FILE__, __LINE__);}

/**
 * @brief  
 * Description: Object declaration.
 *  - All the classes need to extend this class.
 * 
 * @note
 *  The extension attribute must be "public".
 *  All the constructors need to initialize the Object constructor passing the name of the class.
 * 
 * Usage:
 * @code
 *   class Test : public Object
 *   {
 * 		Test()
 * 		{}
 * 
 * 		virtual ~Test()
 * 		{}
 *    
 *      void toString()
 *      {
 *         // print the name of class
 *      }
 *   }; 
 * @endcode
 */
class API_STATE Object
{
private:
    
	/**
	 * The instance counter. Used to know how instances are in the memory.
	 */
	static int32 _instanceCount;

public:
    /**
     * Constructor
     */
    Object();

    /**
     * Destructor
     */
    virtual ~Object();

    /**
     * The overload of NEW
     * 
     * @param size Size of new object
     */
    void *operator new(size_t size);

    /**
     * The overload of DELETE
     * 
     * @param pPointer Pointer to delete
     */
    void operator delete(void *pPointer);

	/**
     * Return the number of instances classes
     */
    static int32 instances();

	/**
     * Indicates whether some other object is "equal to" this one.
     * 
     * @param pObject The object instance
     */
    bool equals(Object *pObject);

	/**
     * Show the pointer of the instance.
     */
	void showPointer();

	/**
	 * Creates and returns a copy of this object.
	 */
	Object *clone();

	/**
     * Returns a string representation of the object.
     */
	virtual const char *toString() = 0;
};

#endif // OBJECT_H_
