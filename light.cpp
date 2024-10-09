#include "light.h"

std::pair<Point<double>, Point<double>> light::GetPoints() {
    return {p_, this->GetPointImage(p_)};
}

void light::setPoint(Point<double> p) {
    p_ = p;
}

light& light::operator=(light other) {
    std::swap(p_, other.p_);
    std::swap(math_vector::x_, other.x_);
    std::swap(math_vector::y_, other.y_);
    return *this;
}


