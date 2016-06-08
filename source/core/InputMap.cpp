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

#include <core/InputMap.h>
#include <util/Log.h>

namespace core
{
	bool InputMap::_keyPressed = false;
	InputMap::E_KEY_TYPE InputMap::_key = KT_NONE;

	InputMap *InputMap::_instance = NULL;
	void InputMap::createInstance()
	{
		TRACE("InputMap::createInstance");

		if(_instance == NULL)
			_instance = kNew(InputMap);
	}

	void InputMap::deleteInstance()
	{
		TRACE("InputMap::deleteInstance");

		if(_instance != NULL)
			kDelete(_instance);
	}

	InputMap *InputMap::getInstance()
	{
		return _instance;
	}

	void InputMap::inputKey(uint32 key)
	{
		_keyPressed = true;

		_key = (E_KEY_TYPE)key;
	}

	bool InputMap::verifyIfWasPressed(E_KEY_TYPE eKey)
	{
		if(_keyPressed)
		{
			if(eKey == _key)
			{
				_keyPressed = false;
				return true;
			}
		}

		return false;
	}
}