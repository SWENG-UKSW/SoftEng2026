#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H


#include <vector>
using namespace std;
#include "ShapeType.h"
#include "ShapeParamIndex.h"
#include <stdexcept>

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

    if (attribs.size() > PARAM_RADIUS && attribs[PARAM_RADIUS] < 0)
        throw std::invalid_argument("Radius must be > 0");

    if (attribs.size() > PARAM_HEIGHT && attribs[PARAM_HEIGHT] <= 0)
        throw std::invalid_argument("Height must be > 0");

    if (attribs.size() > PARAM_WIDTH && attribs[PARAM_WIDTH] <= 0)
        throw std::invalid_argument("Width must be > 0");

    return true;
}

#endif
