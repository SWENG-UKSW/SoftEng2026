#ifndef _TORUS_H
#define _TORUS_H

#include "Shape3D.h"
#include "ShapeParam.h"
#include <string>

using namespace std;

template <class T> class Torus : public Shape3D<T> {
public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Torus(const ShapeParam<T> &param);
};

template <class T> inline ShapeResult<T> Torus<T>::compute()
{
    ShapeResult<T> result;

    const T PI = 3.141592653589793;

    T R = this->m_param.get_attrib(PARAM_RADIUS);
    T r = this->m_param.get_attrib(PARAM_RADIUS_2);

    T surface = 4 * PI * PI * R * r;
    T volume = 2 * PI * PI * R * r * r;

    result.set_attrib(RESULT_SURFACE, surface);
    result.set_attrib(RESULT_VOLUME, volume);

    return result;
}

template <class T> inline string Torus<T>::print()
{
    T R = this->m_param.get_attrib(PARAM_RADIUS);
    T r = this->m_param.get_attrib(PARAM_RADIUS_2);

    return "Torus(R=" + to_string(R) + ", r=" + to_string(r) + ")";
}

template <class T>
inline Torus<T>::Torus(const ShapeParam<T> &param): Shape3D<T>(param)
{}

#endif
