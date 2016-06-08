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

#ifndef ENGINE_STRING_H_
#define ENGINE_STRING_H_

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <util/Log.h>
#include <util/Object.h>

namespace lang
{
	/**
	 * @brief
	 * The string class.
	 */
    class API_STATE String : public Object
    {
    private:
        /** String's minimum size in bytes*/
        static const uint16 STR_MINSIZE = 16;

        /**
         * The buffer
         */
        char* _pBuffer;

        /**
         * The string size
         */
        int32 _size;

        /**
         * The string length
         */
        int32 _length;

    public:

        /**
         * Constructor
         */
        String();

        /**
         * Constructor
         * 
         * @param in Char array
         */
        String(const char* pData);

        /**
         * Copy Constructor
         * 
         * @param in String reference
         */
        String(const String& data);

        /**
         * Constructor 
         * 
         * @param in Char array
         * @param position The position to begin
         * @param length The lenght
         */
        String(const char* pData, int32 position, int32 length);

        /**
         * Destructor
         */
        virtual ~String();

        /**
         * Return an array of chars
         *
         * @return Return an array of chars
         */
        const char* getChars() const;

        /**
         * Find a sub-string in the string
         * 
         * @param str Char array
         */
        int32 findString(const char * pData) const;

        /**
         * Find the first occurrence of a character in the string
         * 
         * @param c The character
         */
        int32 findChar(char c) const;

        /**
         * Change the character of the string in the respective index
         * 
         * @param index The index
         * @param c The character
         */
        void setChar(int32 index, char c);

        /**
         * Clear the first quantity of characters in the string
         * 
         * @param quant The quantity of characters
         */
        void clearChars(int32 quant);

        /**
         * Return a string consisting of the first 'n' characters of the original one
         * 
         * @param n The index
         */
        String substringFixedNumber(int32 n) const;

        /**
         * Return a string consisting of the 'n' characters of the original one that follow 
         * the respective position
         * 
         * @param position The position
         * @param n The index
         */
        String substring(int32 position, int32 n) const;

        /**
         * Compare the strings
         * 
         * @param string The string object
         */
        bool equals(String &string);

        /**
         * Change all characters to lower-case
         */
        void toLowerCase();

        /**
         * Change all characters to upper-case
         */
        void toUpperCase();

        /**
         * Return the length of the string in bytes
         * 
         * @return Return the length
         */
        int32 length() const;

        /**
         * Indexing operator
         * 
         * @param i The integer
         */
        char charAt(int32 i) const;

        /**
         * Convert an integer to string
         * 
         * @param i The integer
         * @return the string
         */
        static String intToStr(int32 i);

        /**
         * Type cast to char pointer
         */
        operator const char *() const;

        /**
         * Char pointer atribuition operator
         * 
         * @param in The text
         */
        void operator=(const char* pData);

        /**
         * Atribuition operator
         * 
         * @param in The string reference
         */
        void operator=(const String& in);

        /**
         * Self-concatenation operator with a char pointer
         * 
         * @param in The text
         */
        void concat(const char* pData);

        /**
         * Self-concatenation operator
         * 
         * @param in The string reference
         */
        void concat(const String& in);

        /**
         * Concatenation operator with a char pointer
         * 
         * @param in The text
         * @return Return the string
         */
        String operator+(const char* pData);

        /**
         * Concatenation operator
         * 
         * @param in The string reference
         * @return Return the string
         */
        String operator+(const String& in);

        /**
         * Equal compare operator
         * 
         * @param str The text
         */
        int32 operator==(const char * pData) const;

        /**
         * Diference compare operator
         * 
         * @param str The text
         */
        int32 operator!=(const char * pData) const;

        /**
         * Bigger compare operator
         * 
         * @param str The text
         */
        int32 operator>(const char * pData) const;

        /**
         * Less compare operator
         * 
         * @param str The text
         */
        int32 operator<(const char * pData) const;

        /**
         * Bigger equal compare operator
         * 
         * @param str The text
         */
        int32 operator>=(const char * pData) const;

        /**
         * Less equal compare operator
         * 
         * @param str The text
         */
        int32 operator<=(const char * pData) const;

		static bool compareStrings(const char* pStringOne, const char* pStringTwo);

		/**
		 * @see Object::toString()
		 */
		const char *toString();
    };
} //namespace

#endif
