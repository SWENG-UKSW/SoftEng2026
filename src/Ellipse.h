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
<<<<<<< HEAD
    public:
        inline ShapeResultData<T> compute();
        inline string print();
        inline Ellipse(const ShapeParam<T> & param);
=======
  public:
    inline ShapeResult<T> compute();

    inline string print();

    inline Ellipse(const ShapeParam<T> & param);

>>>>>>> main
};

template<class T>
<<<<<<< HEAD
inline ShapeResultData<T> Ellipse<T>::compute() {
    T w = this->m_param.get(ShapeParamIndex::PARAM_WIDTH);
    T h = this->m_param.get(ShapeParamIndex::PARAM_HEIGHT);

    T a = w / (T)2;
    T b = h / (T)2;

    ShapeResultData<T> res;
    
    const double PI = 3.14159265358979323846;
    res.set(ShapeResultIndex::RESULT_AREA, (T)(PI * a * b));
    
    return res;
=======
inline ShapeResult<T> Ellipse<T>::compute() {
  return ShapeResult<T>();
>>>>>>> main
}

template<class T>
inline string Ellipse<T>::print() {
    T w = this->m_param.get(ShapeParamIndex::PARAM_WIDTH);
    T h = this->m_param.get(ShapeParamIndex::PARAM_HEIGHT);

    return "Ellipse(" + to_string(w) + ", " + to_string(h) + ")";
}

template<class T>
inline Ellipse<T>::Ellipse(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif