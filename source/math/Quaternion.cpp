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

#include <math/Quaternion.h>
#include <math/Util.h>
#include <util/Log.h>

namespace math
{
    Quaternion::Quaternion() 
    {}

    Quaternion::Quaternion(float32 angle, const Vector3f &axis)
    {
		float32 f=sinf(angle* AK_PI_OVER_180 *0.5f);
        x=axis.x*f;
        y=axis.y*f;
        z=axis.z*f;
		w=cosf(angle * AK_PI_OVER_180 * 0.5f);
    }

    Quaternion::Quaternion(const Quaternion &rIn) 
    {}

    Quaternion::Quaternion(const Matrix &rIn)
    {
        float32 tr,s,q[4];
        int32 i,j,k;

        int32 nxt[3] = {1, 2, 0};

        tr = rIn.m[0][0] + rIn.m[1][1] + rIn.m[2][2];

        // check the diagonal
        if (tr > 0.0)
        {
            s = sqrtf(tr + 1.0f);
            w = s/2.0f;
            s = 0.5f/s;
            x = (rIn.m[1][2] - rIn.m[2][1]) * s;
            y = (rIn.m[2][0] - rIn.m[0][2]) * s;
            z = (rIn.m[0][1] - rIn.m[1][0]) * s;
        }
        else
        {
            // diagonal is negative
            i = 0;
            if (rIn.m[1][1] > rIn.m[0][0])
                i = 1;
            if (rIn.m[2][2] > rIn.m[i][i])
                i = 2;
            j = nxt[i];
            k = nxt[j];

            s=sqrtf((rIn.m[i][i]-(rIn.m[j][j] + rIn.m[k][k])) + 1.0f);

            q[i]=s*0.5f;

            if(s!=0.0f)
                s = 0.5f/s;

            q[3] = (rIn.m[j][k] - rIn.m[k][j]) * s;
            q[j] = (rIn.m[i][j] + rIn.m[j][i]) * s;
            q[k] = (rIn.m[i][k] + rIn.m[k][i]) * s;

            x = q[0];
            y = q[1];
            z = q[2];
            w = q[3];
        }
    }

    void Quaternion::normalize()
    {
        float32 factor = 1.0f/sqrtf(x*x+y*y+z*z+w*w);

        x*=factor;
        y*=factor;
        z*=factor;
        w*=factor;
    }

    void Quaternion::getMatrix(Matrix &rMat) const
    {
        float32 wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;

        // calculate coefficients
        x2 = x + x;
        y2 = y + y;
        z2 = z + z;
        xx = x * x2;
        xy = x * y2;
        xz = x * z2;
        yy = y * y2;
        yz = y * z2;
        zz = z * z2;
        wx = w * x2;
        wy = w * y2;
        wz = w * z2;

        rMat.m[0][0] = 1.0f-(yy+zz);
        rMat.m[1][0] = xy - wz;
        rMat.m[2][0] = xz + wy;
        rMat.m[3][0] = 0.0;

        rMat.m[0][1] = xy + wz;
        rMat.m[1][1] = 1.0f-(xx + zz);
        rMat.m[2][1] = yz - wx;
        rMat.m[3][1] = 0.0;

        rMat.m[0][2] = xz - wy;
        rMat.m[1][2] = yz + wx;
        rMat.m[2][2] = 1.0f - (xx + yy);
        rMat.m[3][2] = 0.0;

        rMat.m[0][3] = 0;
        rMat.m[1][3] = 0;
        rMat.m[2][3] = 0;
        rMat.m[3][3] = 1;

    }

    void Quaternion::getRotate(float32 &rAngle, Vector3f &rAxis) const
    {
		rAngle=acosf(w) * 2 * AK_PI_UNDER_180;

		float32 f=sinf(rAngle * AK_PI_OVER_180 * 0.5f);

        rAxis.x=x/f;
        rAxis.y=y/f;
        rAxis.z=z/f;

    }

    void Quaternion::lerp(const Quaternion& q1, const Quaternion& q2, float32 interValue)
    {
        float32 v;        // complement to t
        float32 o;        // complement to v (t)
        float32 theta;    // angle between q1 & q2
        float32 sin_t;    // sin(theta)
        float32 cos_t;    // cos(theta)
        float32 phi;      // spins added to theta
        int32 flip;       // flag for negating q2

        cos_t = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

        if (cos_t < 0.0)
        {
            cos_t = -cos_t;
            flip = 1;
        }
        else
            flip = 0;

        if (1.0 - cos_t < 1e-6)
        {
            v = 1.0f - interValue;
            o = interValue;
        }
        else
        {
            theta = acosf(cos_t);
            phi = theta;
            sin_t = sinf(theta);
            v = sinf(theta - interValue * phi) / sin_t;
            o = sinf(interValue * phi) / sin_t;
        }
        if (flip)
            o = -o;

        x = v * q1.x + o * q2.x;
        y = v * q1.y + o * q2.y;
        z = v * q1.z + o * q2.z;
        w = v * q1.w + o * q2.w;
    }

    Quaternion Quaternion::operator * (const Quaternion& q)
    {
        Quaternion result;

        result.w = w * q.w - x * q.x - y * q.y - z * q.z;
        result.x = w * q.x + x * q.w + y * q.z - z * q.y;
        result.y = w * q.y + y * q.w + z * q.x - x * q.z;
        result.z = w * q.z + z * q.w + x * q.y - y * q.x;

        return result;
    }

    Quaternion Quaternion::operator + (const Quaternion& q)
    {
        Quaternion res;
        res.x=x+q.x;
        res.y=y+q.y;
        res.z=z+q.z;
        res.w=w+q.w;
        return res;
    }
}//namespace
