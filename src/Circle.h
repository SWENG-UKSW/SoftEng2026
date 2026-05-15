#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <cmath>
#include <string>
#include <stdexcept>
#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include "ShapeResultIndex.h"
#include "ShapeParamIndex.h"

using namespace std;

template <class T> class Circle : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Circle(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Circle<T>::compute()
{
    ShapeResult<T> result;

    // Pobieramy promieñ z parametrów (zak³adam, ¿e w indeksach to PARAM_RADIUS)
    T radius = this->m_param.get_attrib(PARAM_RADIUS);

    // ETAP 2: Zabezpieczenie przed ujemnym promieniem
    if (radius < 0)
    {
        throw std::invalid_argument("Radius cannot be negative");
    }

    // Obliczanie pola (Pi * r^2) i obwodu (2 * Pi * r)
    T area = static_cast<T>(3.14159265358979323846 * radius * radius);
    T perimeter = static_cast<T>(2.0 * 3.14159265358979323846 * radius);

    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_PERIMETER, perimeter);

    return result;
}

template <class T> inline string Circle<T>::print()
{
    ShapeResult<T> result = compute();
    T area = result.get_attrib(RESULT_AREA);
    T perimeter = result.get_attrib(RESULT_PERIMETER);
    T radius = this->m_param.get_attrib(PARAM_RADIUS);

    return "Circle (radius=" + to_string(radius) + ") | area: "
        + to_string(area) + ", perimeter: " + to_string(perimeter);
}

template <class T>
inline Circle<T>::Circle(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif