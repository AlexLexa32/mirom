#pragma once
#include <iostream>

struct Point {
    double x, y;
    Point(double x0 = 0, double y0 = 0): x(x0), y(y0) {};
    Point(const Point& xx): x(xx.x), y(xx.x) {};
    Point operator/(double xx) {
        Point q = *this;
        q.x /= xx;
        q.y /= xx;
        return q;
    }
    Point& operator=(Point other) {
        x = other.x;
        y = other.y;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << '(' << point.x << ' ' << point.y << ')';
    return out;
}
