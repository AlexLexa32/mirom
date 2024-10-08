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

// 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
