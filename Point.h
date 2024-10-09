#pragma once
#include <iostream>

template <class Tp>
struct Point {
    Tp x, y;
    Point(Tp x0 = 0, Tp y0 = 0): x(x0), y(y0) {};
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

template <class Tp>
std::ostream& operator<<(std::ostream& out, const Point<Tp>& point) {
    out << '(' << point.x << ' ' << point.y << ')';
    return out;
}
