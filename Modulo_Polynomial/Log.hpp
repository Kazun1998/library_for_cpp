#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Modulo_Polynomial/Log.hpp

#include"Calculus.hpp"

template<typename mint>
Fast_Power_Series<mint> Log(const Fast_Power_Series<mint> &A) {
    return Integrate(Differential(A) / A);
}