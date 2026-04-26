#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H

#include <vector>
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
    if (attribs.empty()) return false;


    switch (type)
    {
        case ShapeType::PT_TORUS: {
            T R = get_attrib(PARAM_RADIUS);
            T r = get_attrib(PARAM_RADIUS_2);


            return (R > r) && (r > static_cast<T>(0));
        }

        default: return false;
    }
}

#endif
