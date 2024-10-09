#pragma once
#include "math_vector.h"

template <class T>
class light: public math_vector<T> {
public:
    light() = default;
    light(Point<T> point) : math_vector<T>(0,0), p_(point) {};
    light(Point<T> A, Point<T> B) : math_vector<T>(A, B), p_(A) {};
    light& operator=(light other);
    std::pair<Point<T>, Point<T>> GetPoints();

    void setPoint(Point<T> a);
protected:
    Point<T> p_;
};

