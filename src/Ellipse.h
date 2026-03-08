#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include "ShapeResultIndex.h"

template<class T>
class Ellipse : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Ellipse(const ShapeParam<T>& param);
};

template<class T>
    inline ShapeResult<T> Ellipse<T>::compute() {
    T w = this->m_param.get_attrib(ShapeParamIndex::PARAM_WIDTH);
    T h = this->m_param.get_attrib(ShapeParamIndex::PARAM_HEIGHT);

    T a = w / (T)2;
    T b = h / (T)2;

    ShapeResult<T> res;

    const double PI = 3.14159265358979323846;
    res.set_attrib(ShapeResultIndex::RESULT_AREA, (T)(PI * a * b));

    return res;
    }

    template<class T>
    inline string Ellipse<T>::print() {
        T w = this->m_param.get_attrib(ShapeParamIndex::PARAM_WIDTH);
        T h = this->m_param.get_attrib(ShapeParamIndex::PARAM_HEIGHT);
        return "Ellipse(" + to_string(w) + ", " + to_string(h) + ")";
    }

    template<class T>
    inline Ellipse<T>::Ellipse(const ShapeParam<T> &param) : Shape2D<T>(param) {
    }
#endif