#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape2D.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"
#include <sstream>
#include <string>
#include <cmath>

template <class T> class Circle : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline std::string print();
    inline Circle(const ShapeParam<T>& paran);
};

template <class T> inline ShapeResult<T> Circle<T>::compute()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    const T PI = static_cast<T>(3.14159265358979323846);

    T area = PI * radius * radius;
    T perimeter = static_cast<T>(2.0) * PI * radius;

    ShapeResult<T> result;
    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_PERIMETER, perimeter);

    return result;
}

template <class T> inline std::string Circle<T>::print()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    ShapeResult<T> result = compute();

    std::ostringstream out;
    out << "=== FIGURA: KOLO ===" << std::endl;
    out << "Promien: " << radius << std::endl;
    out << "Pole powierzchni: " << result.get_attrib(RESULT_AREA) << std::endl;
    out << "Obwod: " << result.get_attrib(RESULT_PERIMETER) << std::endl;
    out << "====================";

    return out.str();
}

template <class T>
inline Circle<T>::Circle(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif // CIRCLE_H_