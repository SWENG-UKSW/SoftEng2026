#ifndef _CONE_H
#define _CONE_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include <string>
#include <cmath>
#include <sstream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

template <class T> class Cone : public Shape3D<T> {
public:
    inline ShapeResult<T> compute() override;
    inline string print() override;
    inline Cone(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Cone<T>::compute()
{
    this->m_param.validate(); // Wywołanie poprawionej walidacji

    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);

    double r = static_cast<double>(radius);
    double h = static_cast<double>(height);

    double volume = (M_PI * r * r * h) / 3.0;
    double slantHeight = sqrt(r * r + h * h);
    double surface = M_PI * r * (r + slantHeight);

    ShapeResult<T> result;
    result.set_attrib(RESULT_VOLUME, static_cast<T>(volume));
    result.set_attrib(RESULT_SURFACE, static_cast<T>(surface));

    return result;
}

template <class T> inline string Cone<T>::print()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);
    ShapeResult<T> result = compute();

    ostringstream out;
    out << "=== SOLID: CONE ===" << endl;
    out << "Radius: " << radius << endl;
    out << "Height: " << height << endl;
    out << "Volume: " << result.get_attrib(RESULT_VOLUME) << endl;
    out << "Surface: " << result.get_attrib(RESULT_SURFACE) << endl;
    out << "=====================";

    return out.str();
}

template <class T>
inline Cone<T>::Cone(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif
