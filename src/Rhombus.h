#ifndef _RHOMBUS_H
#define _RHOMBUS_H


#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include "ShapeResultIndex.h"

template<class T>
class Rhombus : public Shape2D<T> {
  public:
    inline ShapeResultData<T> compute();

    inline string print();

    inline Rhombus(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResultData<T> Rhombus<T>::compute() {
    T d1 = this->m_param.get(ShapeParamIndex::PARAM_DIAGONAL);
    T d2 = this->m_param.get(ShapeParamIndex::PARAM_DIAGONAL_2);

    ShapeResultData<T> res;
    res.set(ShapeResultIndex::RESULT_AREA, (d1 * d2) / 2);
    return res;
}

template<class T>
inline string Rhombus<T>::print() {
    T d1 = this->m_param.get(ShapeParamIndex::PARAM_DIAGONAL);
    T d2 = this->m_param.get(ShapeParamIndex::PARAM_DIAGONAL_2);

    return "Rhombus(" + to_string(d1) + "," + to_string(d2) + ")";
}


template<class T>
inline Rhombus<T>::Rhombus(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif
