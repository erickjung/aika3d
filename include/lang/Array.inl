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

template <class T>
Array<T>::Array() 
: _pBuffer(NULL), _arraySize(0), _length(0)
{ }

template <class T>
Array<T>::Array(const Array<T>& in) 
: _pBuffer(NULL), _arraySize(0), _length(0)
{
    reserve(in.getLength());

    for(uint16 i=0; i < in.getLength(); i++ )
    {
        add(in[i]);
    }
}

template <class T>
Array<T>::~Array()
{
    delete[] _pBuffer;
}

template <class T>
void Array<T>::resize()
{
    if (_length==_arraySize)
    {
        if (_arraySize==0)
        {
            _arraySize=4;
        }
        else
        {
            _arraySize+=(_arraySize*3)>>1;
        }

        T *tmp=new T[_arraySize];
        assert(tmp);
        //memset(tmp, 0, _arraySize);

        for(uint16 i=0; i < getLength(); ++i)
        {
            tmp[i] = _pBuffer[i];
        }

        delete[] _pBuffer;
        _pBuffer = tmp;
    }
}

template <class T>
uint32 Array<T>::getLength() const
{
    return _length;
}

template <class T>
uint32 Array<T>::getSize() const
{
    return _arraySize * _length;
}

template <class T>
void Array<T>::reserve(uint32 number)
{
    assert(number > 0);

    if (_arraySize < number)
    {
        T * tmp = new T[number];
        assert(tmp);
        _arraySize = number;
        //memset(tmp, 0, _arraySize);

        for(uint32 i=0; i < _length; ++i)
        {
            tmp[i] = _pBuffer[i];
        }

        delete[] _pBuffer;
        _pBuffer = tmp;
    }
}

template <class T>
void Array<T>::free()
{
    _pBuffer=0;
    _length=0;
    _arraySize=0;
}

template <class T>
void Array<T>::clear()
{
    _length=0;
}

template <class T>
void Array<T>::add(const T elem)
{
    resize();

    _pBuffer[_length++]=elem;
}

template <class T>
void Array<T>::remove(int32 i)
{
    if (i < _length)
    {
        for (int32 j = i; j < _length-1; j++)
        {
            _pBuffer[j] = _pBuffer[j+1];
        }
        _length--;
    }
}

template <class T>
void Array<T>::remove(int32 i, int32 n)
{
    if (i+n<=_length)
    {
        for (int32 j = i; j < _length-n; j++)
        {
            _pBuffer[j] = _pBuffer[j+n];
        }
        _length-=n;
    }
}

template <class T>
const T& Array<T>::operator[](int32 i) const
{
    return(_pBuffer[i]);
}

template <class T>
T& Array<T>::operator[](int32 i)
{
    return _pBuffer[i];
}

template <class T>
void Array<T>::operator=(const Array<T>& in)
{
    reserve(in.getLength());
    clear();

    for(uint16 i=0; i < in.getLength(); i++)
    {
        add(in[i]);
    }
}

template <class T>
void Array<T>::operator+=(Array<T>& in)
{	
    if (_length+in.getLength()>_arraySize)
    {
        _arraySize=getLength()+in.getLength();
        T *tmp=new T[_arraySize];
        assert(tmp);

        for(uint16 i=0; i < getLength(); i++)
        {
            tmp[i]=_pBuffer[i];
        }

        delete[] _pBuffer;
        _pBuffer=tmp;
    }

    for(uint16 i=0; i < in.getLength(); i++)
    {
        _pBuffer[i+getLength()]=in[i];
    }
    _length+=in.getLength();
}

template <class T>
const char * Array<T>::toString()
{
    return "class: Array";
}

