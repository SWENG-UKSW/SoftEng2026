#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H

#include <vector>
#include <stdexcept>
using namespace std;

#include "ShapeType.h"
#include "ShapeParamIndex.h"

template <class T> class ShapeParam {
private:
    vector<T> attribs;

public:
    ShapeType type;

    inline T get_attrib(ShapeParamIndex ind) const;
    inline bool set_attrib(ShapeParamIndex ind, const T& val);
    inline bool validate() const;
};

template <class T> inline T ShapeParam<T>::get_attrib(ShapeParamIndex ind) const
{
    if (ind < attribs.size()) return attribs[ind];
    return 0;
}

template <class T>
inline bool ShapeParam<T>::set_attrib(ShapeParamIndex ind, const T& val)
{
    if (ind >= attribs.size()) attribs.resize(ind + 1);
    attribs[ind] = val;
    return true;
}

template <class T> inline bool ShapeParam<T>::validate() const
{
    switch (type)
    {
        case ShapeType::PT_TRIANGLE: {
            if (attribs.size() <= PARAM_SIDE_C) return false;

            T a = get_attrib(PARAM_SIDE_A);
            T b = get_attrib(PARAM_SIDE_B);
            T c = get_attrib(PARAM_SIDE_C);

            if (a <= 0 || b <= 0 || c <= 0) return false;

            if (a + b <= c || a + c <= b || b + c <= a) return false;

            return true;
        }
        default: return false;
    }
}

#endif