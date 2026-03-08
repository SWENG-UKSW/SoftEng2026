#ifndef _TORUS_H
#define _TORUS_H


#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Torus : public Shape3D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Torus(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResultData<T> Torus<T>::compute() {

    ShapeResultData<T> result;

    const T PI = 3.141592653589793;

    T R = this->m_param.get(PARAM_RADIUS);
    T r = this->m_param.get(PARAM_WIDTH);

    T surface = 4 * PI * PI * R * r;
    T volume = 2 * PI * PI * R * r * r;

    result.set(RESULT_SURFACE, surface);
    result.set(RESULT_VOLUME, volume);

    return result;
}

template<class T>
std::string Torus<T>::print() {
    return "";}

template<class T>
inline Torus<T>::Torus(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
