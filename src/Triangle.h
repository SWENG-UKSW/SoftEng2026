#ifndef _TRIANGLE_H
#define _TRIANGLE_H


#include "AbstractShape.h"
#include "IShape2D.h"

#include <iostream>
template<class T>
class Triangle : public AbstractShape<T>, public IShape2D<T> {
  public:
    inline void print();

    inline void compute();

    inline T getArea();

    inline T getPerimeter();

};
template<class T>
inline void Triangle<T>::print() 
  {std::cout << "Trojkat z BOUML" << std::endl;}

template<class T>
inline void Triangle<T>::compute() 
 {this->calculatedValue = 100;}

template<class T>
inline T Triangle<T>::getArea() {
}

template<class T>
inline T Triangle<T>::getPerimeter() {
  return 0;
}

#endif
