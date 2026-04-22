#ifndef _RECTANGLE_H
#define _RECTANGLE_H


#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Rectangle : public Shape2D<T> {
public:
    inline virtual ShapeResultData<T> compute();

    inline string print();

    inline Rectangle(const ShapeParam<T>& param);

};
template<class T>
inline ShapeResultData<T> Rectangle<T>::compute() {

    T a = this->param.getA();
    T b = this->param.getB();

    T area = a * b;
    T perimeter = 2 * (a + b);

    return ShapeResultData<T>(area, perimeter);
}

template<class T>
inline string Rectangle<T>::print() {

    T a = this->param.getA();
    T b = this->param.getB();

    return "Rectangle a=" + to_string(a) + " b=" + to_string(b);
}


template<class T>
inline Rectangle<T>::Rectangle(const ShapeParam<T>& param) : Shape2D<T>(param) {
}

#endif
