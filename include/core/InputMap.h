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

#ifndef __INPUTMAP_H__
#define __INPUTMAP_H__

#include <util/Object.h>

namespace core
{
    /**
     * @brief
	 * This is the input map class.
     */
	class API_STATE InputMap /*: public Object*/
	{
	public:
        /**
         * The keys
         */
		enum E_KEY_TYPE
		{
			KT_NONE,
			KT_A,
			KT_B,
			KT_C,
			KT_D,
			KT_E,
			KT_F,
			KT_G,
			KT_H,
			KT_I,
			KT_J,
			KT_K,
			KT_L,
			KT_M,
			KT_N,
			KT_O,
			KT_P,
			KT_Q,
			KT_R,
			KT_S,
			KT_T,
			KT_U,
			KT_V,
			KT_W,
			KT_X,
			KT_Y,
			KT_Z,
			KT_TAB,
			KT_SHIFT,
			KT_CTRL,
			KT_SPACE,
			KT_RETURN,
			KT_ESC,
			KT_LEFT,
			KT_RIGHT,
			KT_UP,
			KT_DOWN,
			KT_F1,
			KT_F2,
			KT_F3,
			KT_F4,
			KT_F5,
			KT_F6,
			KT_F7,
			KT_F8,
			KT_F9,
			KT_F10,
			KT_F11,
			KT_F12,
			KT_QUANTITY
		};

        /**
         * Create the input map instance.
         */
		static void createInstance();

        /**
         * Delete the input map instance.
         */
		static void deleteInstance();

		/**
         * Get the input map instance.
         * 
         * @return Returns the instance.
         */
		static InputMap *getInstance();

        /**
         * Receive the input key from the specific device.
		 * @note This only need to be used directly on the device.
         * 
         * @param key The input key.
         */
		static void inputKey(uint32 key);

        /**
         * Verify if the specific key was pressed.
         * 
         * @param eKey The key type.
         * @return Returns true if was pressed.
         */
		static bool verifyIfWasPressed(E_KEY_TYPE eKey);

		/**
		 * @see Object::toString()
		 */
		const char *toString(){return "class: InputMap";}

	private:
        /**
         * Use to verify if the key was pressed.
         */
		static bool _keyPressed;

        /**
         * The key type.
         */
		static E_KEY_TYPE _key;

        /**
         * The input key instance.
         */
		static InputMap *_instance;

        /**
         * Constructor.
         */
		InputMap(){}

		/**
         * Destructor.
         */
		~InputMap(){}
	};
}

#endif
