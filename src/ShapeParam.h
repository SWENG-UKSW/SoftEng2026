#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H

#include <vector>
#include <stdexcept> 
#include "ShapeType.h"
#include "ShapeParamIndex.h"

template <class T> class ShapeParam {
private:
    std::vector<T> attribs;

public:
    ShapeType type;

    inline T get_attrib(size_t ind) const
    {
        if (ind >= attribs.size())
        {
            throw std::out_of_range("Indeks poza zakresem parametrów kszta³tu");
        }
        return attribs[ind];
    }

    inline bool set_attrib(size_t ind, const T& val)
    {
        if (ind >= attribs.size())
        {
            attribs.resize(ind + 1);
        }
        attribs[ind] = val;
        return true;
    }

    inline bool validate() const;
};


#endif