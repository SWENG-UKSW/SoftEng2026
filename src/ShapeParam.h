#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H


#include <vector>
using namespace std;
#include "ShapeType.h"
#include "ShapeParamIndex.h"

template<class T>
class ShapeParam {
  private:
    vector<T> attribs;


  public:
    ShapeType type;

    inline T get_attrib(ShapeParamIndex ind) const;

    inline bool set_attrib(ShapeParamIndex ind, const T & val);

    inline bool validate() const;

};
template<class T>
inline T ShapeParam<T>::get_attrib(ShapeParamIndex ind) const {
    if(ind<attribs.size()) return attribs[ind];
    return 0;
}

template<class T>
inline bool ShapeParam<T>::set_attrib(ShapeParamIndex ind, const T & val) {
  if(ind>=attribs.size())attribs.resize(ind+1);
  attribs[ind]=val;
  return true;
}

template <class T> inline bool ShapeParam<T>::validate() const
{

    T width = get_attrib(PARAM_WIDTH);
    T depth = get_attrib(PARAM_DEPTH);
    T height = get_attrib(PARAM_HEIGHT);

    return (width > static_cast<T>(0)) && (depth > static_cast<T>(0))
        && (height > static_cast<T>(0));
}

#endif
