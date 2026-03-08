#ifdef _HEXAGON_H
#define _HEXAGON_H
#include <cmath>

#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

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

    T area = static_cast<T>((3 * sqrt(3.0) / 2) * side * side);
    T perimeter = 6 * side;

    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_PERIMETER, perimeter);

    return result;
}

template <class T> inline string Hexagon<T>::print()
{

    T side = this->m_param.get_attrib(PARAM_WIDTH);

    return "Hexagon side=" + to_string(side);
}

template <class T>
inline Hexagon<T>::Hexagon(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif