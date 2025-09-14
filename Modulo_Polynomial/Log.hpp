#pragma once

#include"Calculus.hpp"

template<const ll Mod>
Fast_Polynominal_Series<Mod> Log(const Fast_Polynominal_Series<Mod> &A) {
    return Integrate(Differential(A) / A);
}