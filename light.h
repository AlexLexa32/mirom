#pragma once
#include "math_vector.h"

class light: public math_vector {
public:
    light() = default;
    light(Point point) : math_vector(0,0), p_(point) {};
    light(Point A, Point B) : math_vector(A, B), p_(A) {};
    light(const Point& A, const Point& B, const Point& C) : math_vector(A, B), p_(C) {};
    light& operator=(light other);
    std::pair<Point, Point> GetPoints();
    light Rotate(double angle);

    void setPoint(Point a);
protected:
    Point p_;
};

