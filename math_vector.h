#pragma once
#include "point.h"
#include <cmath>

template <class T>
class math_vector {
public:
    math_vector() = default;
    math_vector(T x, T y): x_(x), y_(y) {};
    math_vector(Point<T> A, Point<T> B): x_(B.x - A.x), y_(B.y - A.y) {};

    math_vector operator+(math_vector other);
    math_vector operator-(math_vector other);
    math_vector operator*(T k);
    T operator*(math_vector other);
    T operator^(math_vector other);

    math_vector& operator=(math_vector other);

    T GetAngle(math_vector other);

    math_vector Rotate(T angle);

    Point<T> GetPointImage(Point<T> point);

    void setX(T x);
    void setY(T y);

protected:
    T x_;
    T y_;
};

