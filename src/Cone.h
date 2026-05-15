#ifndef _CONE_H
#define _CONE_H

#include <cmath>
#include <string>
#include <stdexcept>
#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include "ShapeResultIndex.h"
#include "ShapeParamIndex.h"

using namespace std;

template <class T> class Cone : public Shape3D<T> {
public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Cone(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Cone<T>::compute()
{
    ShapeResult<T> result;

    // Pobieramy promieñ i wysokoœæ
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);

    // Zabezpieczenie przed ujemnymi wartoœciami
    if (radius < 0 || height < 0)
    {
        throw std::invalid_argument("Radius and height cannot be negative");
    }

    // Obliczanie tworz¹cej sto¿ka: l = sqrt(r^2 + h^2)
    T slant_height = static_cast<T>(sqrt(radius * radius + height * height));

    // Pole powierzchni ca³kowitej = Pi * r * (r + l)
    T area = static_cast<T>(3.14159265358979323846 * radius
                            * (radius + slant_height));

    // Objêtoœæ = 1/3 * Pi * r^2 * h
    T volume = static_cast<T>((1.0 / 3.0) * 3.14159265358979323846 * radius
                              * radius * height);

    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_VOLUME, volume);

    return result;
}

template <class T> inline string Cone<T>::print()
{
    ShapeResult<T> result = compute();
    T area = result.get_attrib(RESULT_AREA);
    T volume = result.get_attrib(RESULT_VOLUME);
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);

    return "Cone (radius=" + to_string(radius) + ", height=" + to_string(height)
        + ") | area: " + to_string(area) + ", volume: " + to_string(volume);
}

template <class T>
inline Cone<T>::Cone(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif

