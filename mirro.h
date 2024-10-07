#pragma once
#include "light.h"

template<class T>
class flat_mirro {
public:
    flat_mirro() = default;
    flat_mirro(Point<T> A, Point<T> B) : A_(A), B_(B) {};
//mda
    virtual bool IsCross(light<T> light);
    virtual Point<T> Cross(light<T> light);
    virtual light<T> Reflect(light<T> light);

protected:
    Point<T> A_;
    Point<T> B_;
};

