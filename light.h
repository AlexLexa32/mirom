#pragma once
#include "math_vector.h"

class light: public math_vector {
public:
    light() = default;
    light(Point<double> point) : math_vector(0,0), p_(point) {};
    light(Point<double> A, Point<double> B) : math_vector(A, B), p_(A) {};
    light& operator=(light other);
    std::pair<Point<double>, Point<double>> GetPoints();

    void setPoint(Point<double> a);
protected:
    Point<double> p_;
};

