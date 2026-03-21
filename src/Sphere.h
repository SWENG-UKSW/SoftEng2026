#ifndef _SPHERE_H
#define _SPHERE_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath>
#include "ShapeParam.h"

using namespace std;

template <class T> class Sphere : public Shape3D<T> {
public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Sphere(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Sphere<T>::compute()
{
    T r = this->m_param.get_attrib(ShapeParamIndex(0));

    ShapeResult<T> result;

    if (r <= 0)
    {
        result.set_attrib(ShapeResultIndex(0), 0);
        result.set_attrib(ShapeResultIndex(1), 0);
        return result;
    }

    T volume = (4.0 / 3.0) * 3.141592653589793 * r * r * r;
    T surface = 4 * 3.141592653589793 * r * r;

    result.set_attrib(ShapeResultIndex(0), surface);
    result.set_attrib(ShapeResultIndex(1), volume);

    return result;
}

template <class T> inline string Sphere<T>::print() { return "Sphere"; }

template <class T>
inline Sphere<T>::Sphere(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif