#ifndef _HEXAGON_H
#define _HEXAGON_H
#include <cmath>

#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Hexagon : public Shape2D<T> {
  public:
    inline ShapeResultData<T> compute();

    inline string print();

    inline Hexagon(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResultData<T> Hexagon<T>::compute() {

  T side = this->param.getParam1();

  T area = (3 * sqrt(3) / 2) * side * side;
  T perimeter = 6 * side;

  return ShapeResultData<T>(area, perimeter);
}

template<class T>
inline string Hexagon<T>::print() {

  T side = this->param.getParam1();

  return "Hexagon side=" + to_string(side);
}

template<class T>
inline Hexagon<T>::Hexagon(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif
