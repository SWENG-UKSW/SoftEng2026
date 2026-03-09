#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <string>
#include "Shape3D.h"
#include "Shape2D.h"
#include "ShapeResultData.h"
#include <cmath>
#include "ShapeParam.h"

template<class T>
class Rectangle : public Shape2D<T> {
public:

    virtual ShapeResult<T> compute() override;

    std::string print();

    Rectangle(const ShapeParam<T>& m_param);
};


template<class T>
inline ShapeResult<T> Rectangle<T>::compute() {
    T a = this->m_param.get_attrib(ShapeParamIndex(0));
    T b = this->m_param.get_attrib(ShapeParamIndex(0));

    T area = a * b;

    T perimeter = static_cast<T>(2) * (a + b);

    ShapeResult<T> result;
    result.set_attrib(ShapeResultIndex(0), area);
    result.set_attrib(ShapeResultIndex(1), perimeter);

    return result;
}

template<class T>
inline std::string Rectangle<T>::print() {
    T a = this->m_param.get_attrib(ShapeParamIndex(0));
    T b = this->m_param.get_attrib(ShapeParamIndex(0));
    return "Rectangle a=" + std::to_string(a) + " b=" + std::to_string(b);
}

template<class T>
inline Rectangle<T>::Rectangle(const ShapeParam<T>& m_param) : Shape2D<T>(m_param) {
}

#endif