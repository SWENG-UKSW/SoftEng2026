#ifndef _SPHERE_H
#define _SPHERE_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath>
#include "ShapeParam.h"

using namespace std;

template<class T>
class Sphere : public Shape3D<T> {
public:
    inline virtual ShapeResultData<T> compute();

    inline string print();

    inline Sphere(const ShapeParam<T>& param);
};

template<class T>
inline ShapeResultData<T> Sphere<T>::compute() {

    T r = this->param.get(0);

    T volume = (4.0 / 3.0) * 3.141592653589793 * r * r * r;
    T surface = 4 * 3.141592653589793 * r * r;

    return ShapeResultData<T>(surface, volume);
}

template<class T>
inline string Sphere<T>::print() {
    return "Sphere";
}

template<class T>
inline Sphere<T>::Sphere(const ShapeParam<T>& param)
    : Shape3D<T>(param) {
}

#endif