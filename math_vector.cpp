#include "math_vector.h"

math_vector math_vector::operator+(math_vector other) {
    other.x_ += x_;
    other.y_ += y_;
    return other;
}

math_vector math_vector::operator-(math_vector other) {
    other.x_ -= x_;
    other.y_ -= y_;
    return other;
}

math_vector math_vector::operator*(double k) {
    return math_vector(x_ * k, y_ * k);
}

double math_vector::operator*(math_vector other) {
    return x_ * other.x_ + y_ * other.y_;
}

double math_vector::operator^(math_vector other) {
    return x_  * other.y_ - y_ * other.x_;
}

double math_vector::GetAngle(math_vector other) {
    return atan2(*this * other, *this ^ other);
}

math_vector math_vector::Rotate(double angle) {
    math_vector old(x_, y_);
    old.x_ = x_ * cos(angle) - y_ * sin(angle);
    old.y_ = y_ * cos(angle) + x_ * sin(angle);

    return old;
}

Point math_vector::GetPointImage(Point point) {
    Point ans(point.x + x_, point.y + y_);
    return ans;
}

void math_vector::setX(double x) {
    x_ = x;
}

void math_vector::setY(double y) {
    y_ = y;
}

math_vector& math_vector::operator=(math_vector other) {
    std::swap(x_, other.x_);
    std::swap(y_, other.y_);
    return *this;
}
