#ifndef _HEXAGON_H
#define _HEXAGON_H

#include <cmath>
#include <string>
#include <stdexcept>
#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeResultIndex.h"
#include "ShapeParam.h"
#include "ShapeParamIndex.h"

using namespace std;

template <class T> class Hexagon : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Hexagon(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Hexagon<T>::compute()
{
    ShapeResult<T> result;

    T side = this->m_param.get_attrib(PARAM_WIDTH);

    if (side < 0)
    {
        throw std::invalid_argument("Side cannot be negative");
    }

    T area = static_cast<T>((3.0 * sqrt(3.0) / 2.0) * side * side);
    T perimeter = static_cast<T>(6.0 * side);

    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_PERIMETER, perimeter);

    return result;
}

template <class T> inline string Hexagon<T>::print()
{
    ShapeResult<T> result = compute();
    T area = result.get_attrib(RESULT_AREA);
    T perimeter = result.get_attrib(RESULT_PERIMETER);
    T side = this->m_param.get_attrib(PARAM_WIDTH);

    return "Hexagon (side=" + to_string(side) + ") | area: " + to_string(area)
        + ", perimeter: " + to_string(perimeter);
}

template <class T>
inline Hexagon<T>::Hexagon(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif
