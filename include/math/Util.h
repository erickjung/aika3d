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

#ifndef __MATHUTIL__
#define __MATHUTIL__

#include <math.h>
#include <stdlib.h>

namespace math
{
    /** lower bound for overflow detection*/
    static const float32 AK_BOUND_SMALL = 1.0e-4f;

	/** upper bound for overflow detection*/
    static const float32 AK_BOUND_BIG = 1.0e+10f;

    /** represents the value of pi*/
    static const float32 AK_PI = 3.14159265359f;

    /** represents the value of 2*pi*/
	static const float32 AK_PI_DOUBLE = 6.28318530718f;

	/** represents the value of pi/2*/
    static const float32 AK_PI_HALF = 1.57079632679f;

    /** represents the value of pi/180*/
    static const float32 AK_PI_OVER_180 = 1.74532925199433E-002f;

	/** represents the value of 180/pi*/
    static const float32 AK_PI_UNDER_180 = 5.72957795130823E+001f;

    /**
     * Random floating point number
     * 
     * @note
     * 
     * 
     * @return Returns the random number
     */
    inline float32 floatRandom()
    {
        return (((rand() % 10000) - 5000) / 5000.0f);
    }
}

#endif