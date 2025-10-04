#pragma once

#include"Calculus.hpp"

template<typename mint>
Fast_Power_Series<mint> Log(const Fast_Power_Series<mint> &A) {
    return Integrate(Differential(A) / A);
}