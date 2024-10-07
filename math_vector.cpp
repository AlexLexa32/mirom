#include "math_vector.h"

template<class T>
math_vector<T> math_vector<T>::operator+(math_vector other) {
    other.x_ += x_;
    other.y_ += y_;
    return other;
}

template<class T>
math_vector<T> math_vector<T>::operator-(math_vector other) {
    other.x_ -= x_;
    other.y_ -= y_;
    return other;
}

template<class T>
math_vector<T> math_vector<T>::operator*(T k) {
    return math_vector<T>(x_ * k, y_ * k);
}

template<class T>
T math_vector<T>::operator*(math_vector other) {
    return x_ * other.x_ + y_ * other.y_;
}

template<class T>
T math_vector<T>::operator^(math_vector other) {
    return x_  * other.y_ - y_ * other.x_;
}

template<class T>
T math_vector<T>::GetAngle(math_vector other) {
    return atan2(*this * other.x_, *this ^ other.y_);
}

template<class T>
math_vector<T> math_vector<T>::Rotate(T angle) {
    math_vector<T> old(x_, y_);
    old.x_ = x_ * cos(angle) - y_ * sin(angle);
    old.y_ = y_ * cos(angle) + x_ * sin(angle);

    return old;
}

template<class T>
Point<T> math_vector<T>::GetPointImage(Point<T> point) {
    return point(point.x() + x_, point.y() + y_);
}

template<class T>
void math_vector<T>::setX(T x) {
    x_ = x;
}

template<class T>
void math_vector<T>::setY(T y) {
    y_ = y;
}



