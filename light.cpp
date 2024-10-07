#include "light.h"

template<class T>
std::pair<Point<T>, Point<T>> light<T>::GetPoints() {
    return {p_, this->GetPointImage(p_)};
}

template<class T>
void light<T>::setPoint(Point<T> p) {
    p_ = p;
}