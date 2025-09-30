#pragma once

#include"Calculus.hpp"

template<const ll Mod>
Fast_Power_Series<Mod> Log(const Fast_Power_Series<Mod> &A) {
    return Integrate(Differential(A) / A);
}