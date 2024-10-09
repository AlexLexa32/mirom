#pragma once
#include "light.h"

class flat_mirro {
public:
    flat_mirro() = default;
    flat_mirro(const Point& A, const Point& B) : A_(A), B_(B) {};

    virtual bool IsCross(light light);
    virtual Point Cross(light light);
    virtual light Reflect(light light);

protected:
    Point A_;
    Point B_;
};

class rad_mirro : public flat_mirro {
public:
    rad_mirro() = default;
    rad_mirro(Point A, Point B, Point C, double R) : flat_mirro(A, B), R_(R), C_(C) {};

    bool IsCross(light Light);

    light Reflect(light Light);

protected:
  Point C_;
  double R_;
};

// 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
