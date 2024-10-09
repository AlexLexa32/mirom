#pragma once
#include "light.h"

template<class T>
class flat_mirro {
public:
    flat_mirro() = default;
    flat_mirro(Point<T> A, Point<T> B) : A_(A), B_(B) {};

    virtual bool IsCross(light<T> light);
    virtual light<T> Reflect(light<T> light);

protected:
    Point<T> A_;
    Point<T> B_;
};

template<class T>
class rad_mirro : public flat_mirro<T> {
public:
    rad_mirro() = default;
    rad_mirro(Point<T> A, Point<T> B, Point<T> C, T R) : flat_mirro<T>(A, B), R_(R), C_(C) {};

    bool IsCross(light<T> Light);
    light<T> Reflect(light<T> Light);

protected:
  Point<T> C_;
  T R_;
};

// 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
