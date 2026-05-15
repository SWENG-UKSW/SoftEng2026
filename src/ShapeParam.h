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

    // Dodany konstruktor inicjalizuj¹cy typ, aby usun¹æ ostrze¿enia (warning
    // C26495)
    inline ShapeParam() : type() {} 
                           

    inline T get_attrib(ShapeParamIndex ind) const;
    inline bool set_attrib(ShapeParamIndex ind, const T& val);

    // Zmiana: teraz validate() faktycznie sprawdza wartoœci
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
    // Sprawdzamy wszystkie zapisane atrybuty
    for (size_t i = 0; i < attribs.size(); ++i)
    {
        // Zaden wymiar figury (promieñ, bok, wysokoœæ) nie mo¿e byæ ujemny
        if (attribs[i] < 0)
        {
            return false;
        }
    }
    // Jeœli przeszliœmy pêtlê i nic nie by³o ujemne, to parametry s¹ OK
    return true;
}

#endif