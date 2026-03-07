#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include <string>
#include <sstream>

template<class T>
class Circle : public Shape2D<T> {
public:
    inline ShapeResultData<T> compute();
    inline std::string print();
    inline Circle(const ShapeParam<T>& param);
};

template<class T>
inline ShapeResultData<T> Circle<T>::compute() {
    T radius = this->m_param.get(PARAM_RADIUS);
    const double PI = 3.14159265358979323846;
    
    // Obliczenia na typie double dla precyzji
    double area = PI * static_cast<double>(radius) * static_cast<double>(radius);
    double perimeter = 2.0 * PI * static_cast<double>(radius);

    // Pakowanie wynikow do obiektu ShapeResultData
    ShapeResultData<T> result;
    result.set(RESULT_AREA, static_cast<T>(area));
    result.set(RESULT_PERIMETER, static_cast<T>(perimeter));

    return result;
}

template<class T>
inline std::string Circle<T>::print() {
    T radius = this->m_param.get(PARAM_RADIUS);
    ShapeResultData<T> result = compute();

    // Uzycie ostringstream do zbudowania wieloliniowego tekstu
    std::ostringstream out;
    out << "=== FIGURA: KOLO ===" << std::endl;
    out << "Promien: " << radius << std::endl;
    out << "Pole powierzchni: " << result.get(RESULT_AREA) << std::endl;
    out << "Obwod: " << result.get(RESULT_PERIMETER) << std::endl;
    out << "====================";

    return out.str();
}

template<class T>
inline Circle<T>::Circle(const ShapeParam<T>& param) : Shape2D<T>(param) {
}

#endif

