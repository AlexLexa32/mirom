#include "light.h"

std::pair<Point, Point> light::GetPoints() {
    return {p_, this->GetPointImage(p_)};
}

void light::setPoint(Point p) {
    p_ = p;
}

light& light::operator=(light other) {
    std::swap(p_, other.p_);
    std::swap(math_vector::x_, other.x_);
    std::swap(math_vector::y_, other.y_);
    return *this;
}

light light::Rotate(double angle) {
    light old(x_, y_);
    old.x_ = x_ * cos(angle) - y_ * sin(angle);
    old.y_ = y_ * cos(angle) + x_ * sin(angle);

    return old;
}


