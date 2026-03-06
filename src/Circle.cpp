
#include "Circle.h"

template <class T>
void Circle<T>::compute() {
    T radius=this->param->get(PARAM_RADIUS);

const double PI=3.14159265358979323846;
this->area=static_cast<T>(PI*radius*radius);
this->perimeter=static_cast<T>(2*PI*radius);
}

