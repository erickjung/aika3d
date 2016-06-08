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

#include <math.h>
#include <math/Matrix.h>
#include <math/Quaternion.h>
#include <util/Log.h>

namespace math
{
    Matrix::Matrix()
    {
        m[0][0]=m[1][1]=m[2][2]=m[3][3]=1.0f;
        m[0][1]=m[0][2]=m[0][3]=0.0f;
        m[1][0]=m[1][2]=m[1][3]=0.0f;
        m[2][0]=m[2][1]=m[2][3]=0.0f;
        m[3][0]=m[3][1]=m[3][2]=0.0f;
    }

    Matrix::Matrix(const Matrix& in)
    {
        m[0][0]=in.m[0][0];
        m[0][1]=in.m[0][1];
        m[0][2]=in.m[0][2];
        m[0][3]=in.m[0][3];
        m[1][0]=in.m[1][0];
        m[1][1]=in.m[1][1];
        m[1][2]=in.m[1][2];
        m[1][3]=in.m[1][3];
        m[2][0]=in.m[2][0];
        m[2][1]=in.m[2][1];
        m[2][2]=in.m[2][2];
        m[2][3]=in.m[2][3];
        m[3][0]=in.m[3][0];
        m[3][1]=in.m[3][1];
        m[3][2]=in.m[3][2];
        m[3][3]=in.m[3][3];
    }

    Matrix::~Matrix()
    {}

    void Matrix::reset()
    {
        m[0][0]=m[0][1]=m[0][2]=m[0][3]=
            m[1][0]=m[1][1]=m[1][2]=m[1][3]=
            m[2][0]=m[2][1]=m[2][2]=m[2][3]=
            m[3][0]=m[3][1]=m[3][2]=m[3][3]=0.0f;
    }

    void Matrix::loadIdentity()
    {
        m[0][0]=m[1][1]=m[2][2]=m[3][3]=1.0f;
        m[0][1]=m[0][2]=m[0][3]=0.0f;
        m[1][0]=m[1][2]=m[1][3]=0.0f;
        m[2][0]=m[2][1]=m[2][3]=0.0f;
        m[3][0]=m[3][1]=m[3][2]=0.0f;
    }

    void Matrix::setRotation(float32 ang, const Vector3f& dir )
    {
        Vector3f direction = dir;
        direction.normalize();

        //ang*=-AK_PIOVER180;

        float32 fCos=cosf( ang );
        float32 fSin=sinf( ang );

        m[0][0] = ( direction.x * direction.x ) * ( 1.0f - fCos ) + fCos;
        m[0][1] = ( direction.x * direction.y ) * ( 1.0f - fCos ) - (direction.z * fSin);
        m[0][2] = ( direction.x * direction.z ) * ( 1.0f - fCos ) + (direction.y * fSin);

        m[1][0] = ( direction.y * direction.x ) * ( 1.0f - fCos ) + (direction.z * fSin);
        m[1][1] = ( direction.y * direction.y ) * ( 1.0f - fCos ) + fCos ;
        m[1][2] = ( direction.y * direction.z ) * ( 1.0f - fCos ) - (direction.x * fSin);

        m[2][0] = ( direction.z * direction.x ) * ( 1.0f - fCos ) - (direction.y * fSin);
        m[2][1] = ( direction.z * direction.y ) * ( 1.0f - fCos ) + (direction.x * fSin);
        m[2][2] = ( direction.z * direction.z ) * ( 1.0f - fCos ) + fCos;

        m[0][3] = m[1][3] = m[2][3] = 0;
        m[3][0] = m[3][1] = m[3][2] = 0;
        m[3][3] = 1;
    }

    void Matrix::rotate( float32 ang, const Vector3f& dir )
    {
        static Matrix m;
        m.setRotation(ang,dir);
        *this=*this*m;
    }

    void Matrix::lerp(const Matrix& matrix1, const Matrix& matrix2, float32 interValue)
    {
        Quaternion q1(matrix1),q2(matrix2), qt;
        qt.lerp(q1, q2, interValue);
        qt.getMatrix(*this);

        m[3][0]=matrix1.m[3][0]*(1-interValue) + matrix2.m[3][0]*interValue;
        m[3][1]=matrix1.m[3][1]*(1-interValue) + matrix2.m[3][1]*interValue;
        m[3][2]=matrix1.m[3][2]*(1-interValue) + matrix2.m[3][2]*interValue;
    }

    void Matrix::operator=(const Matrix& in)
    {
        m[0][0]=in.m[0][0];
        m[0][1]=in.m[0][1];
        m[0][2]=in.m[0][2];
        m[0][3]=in.m[0][3];
        m[1][0]=in.m[1][0];
        m[1][1]=in.m[1][1];
        m[1][2]=in.m[1][2];
        m[1][3]=in.m[1][3];
        m[2][0]=in.m[2][0];
        m[2][1]=in.m[2][1];
        m[2][2]=in.m[2][2];
        m[2][3]=in.m[2][3];
        m[3][0]=in.m[3][0];
        m[3][1]=in.m[3][1];
        m[3][2]=in.m[3][2];
        m[3][3]=in.m[3][3];
    }

    Matrix Matrix::operator*(const Matrix& in) const
    {
        Matrix out;
        int32 i,j;
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
            {
                out.m[i][j] = m[i][0]*in.m[0][j] + m[i][1]*in.m[1][j] +
                    m[i][2]*in.m[2][j] + m[i][3]*in.m[3][j];
            }
            return out;
    }
}//namespace
