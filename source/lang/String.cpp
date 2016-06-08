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

#include <lang/String.h>
#include <util/Assert.h>

namespace lang
{
    String::String() 
        : _size(STR_MINSIZE), _length(0), _pBuffer(NULL)
    {
        _pBuffer = new char[_size];
        assert(_pBuffer);
        memset(_pBuffer, 0, _size);
    }

    String::String(const char* pData) 
        : _size(STR_MINSIZE), _length(strlen(pData)), _pBuffer(NULL)
    {
        assert(pData);

        while ( _size < _length + 1 )
            _size <<= 1;

        _pBuffer = new char[_size];
        assert(_pBuffer);
        memset(_pBuffer, 0, _size);

        strcpy(_pBuffer, pData);
    }

    String::String(const String& data) 
        : _size(data._size), _length(data._length), _pBuffer(NULL)
    {
        assert(data.length() > 0);

        _pBuffer = new char[_size];
        assert(_pBuffer);
        memset(_pBuffer, 0, _size);

        strcpy(_pBuffer, (const char *)data);
    }

    String::String(const char* pData, int32 p, int32 n) 
        : _size(STR_MINSIZE), _length(n), _pBuffer(NULL)
    {
        assert(pData);

        while ( _size < _length + 1 )
            _size <<= 1;

        _pBuffer = new char[_size];
        assert(_pBuffer);
        memset(_pBuffer, 0, _size);

        memcpy(_pBuffer, &pData[p], _length);
        _pBuffer[_length] = '\0';
    }

    String::~String()
    {
        delete[] _pBuffer;
    }

    const char* String::getChars() const
    {
        return _pBuffer;
    }

    void String::concat(const char* pData)
    {
        assert(pData);

        _length += strlen(pData) + 1;

        if (_size < _length + 1)
        {
            while ( _size < _length + 1 )
                _size <<= 1;

            char* temp = new char[_size];
            assert(temp);

			for(uint16 i=0; i < _length; ++i)
			{
				temp[i] = _pBuffer[i];
			}

			strcat(temp, pData);
            delete[] _pBuffer;

			_pBuffer = temp;
        }
        else
            strcat(_pBuffer, pData);
    }

    void String::concat(const String& in)
    {
        assert(in.length() > 0);

        concat((const char *)in);
    }

    int32 String::findString(const char *pData) const
    {
        assert(pData);

        char *pos=strstr(_pBuffer,pData);
        if (pos==0)
        {
            return -1;
        }

        return (int32)(pos-_pBuffer);
    }

    int32 String::findChar(char c) const
    {
        char *pos=strchr(_pBuffer,c);
        if (pos==0)
        {
            return -1;
        }

        return (int32)(pos-_pBuffer);
    }

    void String::setChar(int32 i, char c)
    {
        if (i<_length)
        {
            _pBuffer[i]=c;
        }
        if (c==0)
        {
            if (_length>i)
            {
                _length=i;
            }
        }
    }

    void String::clearChars(int32 n)
    {
        if (n<_length)
        {
            _length-=n;
            strcpy(_pBuffer,&_pBuffer[n]);
        }
    }

    String String::substringFixedNumber(int32 n) const
    {
        return String(_pBuffer, 0, n);
    }

    String String::substring(int32 p, int32 n) const
    {
        return String(_pBuffer, p, n);
    }

    bool String::equals(String &string)
    {
        assert(string.length() > 0);

        return (strcmp(_pBuffer, string.getChars()) == 0) ? true : false;
    }

    void String::toLowerCase()
    {
        _strlwr(_pBuffer);
    }

    void String::toUpperCase()
    {
        _strupr(_pBuffer);
    }

    char String::charAt(int32 i) const
    {
        return _pBuffer[i];
    }

    int32 String::length() const
    {
        return _length;
    }

    String String::intToStr(int32 i)
    {
        char buf[50];
        memset(buf, 0, 50);
        sprintf(buf, "%d", i);

        return String(buf);
    }

    //    ------------------------------------------------------

    void String::operator=(const String& in)
    {
        assert(in.length() > 0);

        operator=((const char *)in);
    }

    String String::operator+(const String& in)
    {
        assert(in.length() > 0);

        return operator+((const char *)in);
    }

    String String::operator+(const char* pData)
    {
        assert(pData);

        String str(_pBuffer);
        str.concat(pData);

        return str;
    }

    void String::operator=(const char* pData)
    {
        assert(pData);

        _length = strlen(pData);
        if (_size < _length + 1)
        {
            while ( _size < _length + 1 )
                _size <<= 1;

            delete[] _pBuffer;
            _pBuffer = new char[_size];
            assert(_pBuffer);
        }
        strcpy(_pBuffer, pData);
    }

    String::operator const char *() const
    {
        return _pBuffer;
    }

    int32 String::operator==(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)==0;
    }

    int32 String::operator!=(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)!=0;
    }

    int32 String::operator>(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)>0;
    }

    int32 String::operator<(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)<0;
    }

    int32 String::operator>=(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)>=0;
    }

    int32 String::operator<=(const char *pData) const
    {
        assert(pData);

        return strcmp(_pBuffer,pData)<=0;
    }

	bool String::compareStrings(const char* pStringOne, const char* pStringTwo)
	{
		assert(pStringOne && pStringTwo);

		if(strcmp(pStringOne, pStringTwo) == 0)
			return true;

		return false;
	}

    const char * String::toString()
    {
        return "class: String";
    }
} //namespace

