#include "light.h"

template<class T>
std::pair<Point<T>, Point<T>> light<T>::GetPoints() {
    return {p_, this->GetPointImage(p_)};
}

template<class T>
void light<T>::setPoint(Point<T> p) {
    p_ = p;
}

template<class T>
light<T>& light<T>::operator=(light<T> other) {
    std::swap(p_, other.p_);
    std::swap(math_vector<T>::x_, other.x_);
    std::swap(math_vector<T>::y_, other.y_);
    return *this;
}


