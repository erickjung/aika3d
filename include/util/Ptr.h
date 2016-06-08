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

#ifndef PTR_H
#define PTR_H

/**
 * @brief 
 * Description: Smart Pointer Declaration.
 *  - Used to make sure that a dynamic object instance will be deleted out of scope automatically.
 * 
 * @note
 *  All the dynamic object instances that need to be released out of scope, need to use smart pointer.
 * 
 * @warning
 *  Don't use when the pointer need to be used out of scope.
 * 
 * Usage:
 * @code
 *   void Function()
 *   {
 * 		Test *test = new Test(); // wrong
 * 
 * 		Ptr<Test> test(new Test); // right use of smart pointer
 *   } 
 * @endcode
 */
template <class T>
class Ptr
{
private:

    /**
     * The pointer to be used
     */
    T* _mObject;

public:

    /**
     * Constructor
     * 
     * Note: Null object 
     */
    Ptr()
    {
        _mObject = 0;
    }

    /**
     * Constructor
     * 
     * Note: Stores the pointer to an object
     * 
     * @param other New pointer 
     */
    Ptr( const Ptr<T>& other )
    {
        _mObject = other.ptr();
    }

    /**
     * Constructor
     * 
     * Note: Stores the pointer to an object
     * 
     * @param New pointer 
     */
    Ptr( T* other )
    {
        _mObject = other;
    }

    /**
     * Destructor 
     */
    ~Ptr()
    {
        if ( _mObject )
            delete _mObject;
    }

    /**
     * Releases old reference if any and stores the new reference
     * 
     * @param other New pointer
     * @return Return new reference
     */
    Ptr<T>& operator=( const Ptr<T>& other )
    {
        if ( _mObject )
            delete _mObject;

        _mObject = other.ptr();
        return *this;
    }

    /**
     * Return reference to the object
     * 
     * @return Return the reference 
     */
    T&	operator* () const
    {
        return *_mObject;
    }

    /**
     * Access member of the object
     * 
     * @return Return the value 
     */
    T*	operator-> () const
    {
        return _mObject;
    }

    /**
     * Returns pointer to the object
     * 
     * @return Return the pointer 
     */
    operator T* () const
    {
        return _mObject;
    }

    /**
     * Returns pointer to the object
     * 
     * @return Return the pointer 
     */
    T* ptr() const
    {
        return _mObject;
    }
};

#endif //PTR_H
