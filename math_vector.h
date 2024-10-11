#pragma once
#include "Point.h"
#include <cmath>

class math_vector {
public:
    math_vector() = default;
    math_vector(double x, double y): x_(x), y_(y) {};
    math_vector(const Point& A, const Point& B): x_(B.x - A.x), y_(B.y - A.y) {};

    math_vector operator+(math_vector other);
    math_vector operator-(math_vector other);
    math_vector operator*(double k);
    double operator*(math_vector other);
    double operator^(math_vector other);

    math_vector& operator=(math_vector other);

    double GetAngle(math_vector other);

    math_vector Rotate(double angle);

    Point GetPointImage(const Point& point);

    void setX(double x);
    void setY(double y);

protected:
    double x_;
    double y_;
};

