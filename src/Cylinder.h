#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include <string>
#include <sstream> 
#include <cmath>   

using namespace std;

template<class T>
class Cylinder : public Shape3D<T> {
  public:
    inline virtual ShapeResultData<T> compute();

    inline string print();

    inline Cylinder(const ShapeParam<T> & param);
};

template<class T>
inline ShapeResultData<T> Cylinder<T>::compute() {
    ShapeResultData<T> resultData;

    T r = this->m_param.get(static_cast<ShapeParamIndex>(0)); 
    T h = this->m_param.get(static_cast<ShapeParamIndex>(1));

    T pi = static_cast<T>(std::acos(-1.0));

    T volume = pi * r * r * h;
    T surfaceArea = static_cast<T>(2.0) * pi * r * (r + h);

    resultData.set(RESULT_VOLUME, volume);
    resultData.set(RESULT_SURFACE, surfaceArea);

    return resultData;
}

template<class T>
inline string Cylinder<T>::print() {
    std::ostringstream oss;
    
    T r = this->m_param.get(static_cast<ShapeParamIndex>(0));
    T h = this->m_param.get(static_cast<ShapeParamIndex>(1));

    oss << "--- WALEC (Cylinder) ---\n";
    oss << "Parametry wejsciowe:\n";
    oss << "  Promien podstawy (r) = " << r << "\n";
    oss << "  Wysokosc (h)         = " << h << "\n";

    return oss.str();
}

template<class T>
inline Cylinder<T>::Cylinder(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
