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

#ifndef ENGINE_ARRAY_H_
#define ENGINE_ARRAY_H_

#include <util/Types.h>
#include <util/Assert.h>

namespace lang
{
	/**
	 * @brief
	 * The Array class.
	 */
    template <class T> class Array
    {
    public:

        /**
         * Constructor
         */
        Array();

        /**
         * Copy Constructor
         * 
         * @param in The array reference
         */
        Array(const Array<T>& in);

        /**
         * Destructor
         */
        virtual ~Array();

        /**
         * Get the length
         * 
         * @return Return the array length
         */
        uint32 getLength() const;

        /**
         * Get the size in bytes
         * 
         * @return Return the array size
         */
        uint32 getSize() const;

        /**
         * Reserve the required amount of space for the array
         * 
         * @param n The desired size of memory
         */
        void reserve(uint32 number);

        /**
         * Free all the space
         */
        void free();

        /**
         * Clear the whole array, but keep the memory space
         */
        void clear();

        /**
         * Add a new element to the end of the array, automatically allocating more space, if needed
         * 
         * @param elem The item to be inserted
         */
        void add(const T elem);

        /**
         * Remove the element in the given position
         * 
         * @param i The index
         */
        void remove(int32 i);

        /**
         * Remove 'n' elements in the given position
         * 
         * @param i The index
         * @param n The number
         */
        void remove(int32 i, int32 n);

        /**
         * Indexing operator returning const
         * 
         * @param i The index
         * @return Return the object const reference
         */
        const T& operator[](int32 i) const;

        /**
         * Indexing operator
         * 
         * @param i The index
         * @return Return the object reference
         */
        T& operator[](int32 i);

        /**
         * Copy Constructor
         * 
         * @param in The object reference
         */
        void operator=(const Array<T>& in);

        /**
         * Adds another array to the end of current array
         * 
         * @param in The object reference
         */
        void operator+=(Array<T>& in);

		/**
		 * @see Object::toString()
		 */
		const char *toString();

    private:
        /**
         * The buffer
         */
        T *_pBuffer;

        /**
         * The array size in bytes
         */
        uint32 _arraySize;

        /**
         * The array length
         */
        uint32 _length;

        /**
         * Resize the array
         */
        void resize();
    };

#include "Array.inl"

} //namespace

#endif
