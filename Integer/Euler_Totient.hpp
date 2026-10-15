#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Euler_Totient.hpp

#include"Prime.hpp"

long long Euler_Totient(long long N, bool mode = true) {
    if (N == 1) { return mode ? 1 : 0; }

    long long phi = 1;
    for (auto &&[p, e]: prime::prime_factorization(N)) {
        phi *= p - 1;
        for (int k = 0; k < e - 1; k++) { phi *= p; }
    }

    return phi;
}
