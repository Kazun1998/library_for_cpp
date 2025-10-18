#pragma once

#include"../template/template.hpp"

template<typename T>
size_t Hamming_Distance(const std::vector<T> &x, const std::vector<T> &y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Vectors must have the same size to calculate Hamming Distance.");
    }

    size_t distance = 0;
    for (size_t i = 0; i < x.size(); i++) { 
        if (x[i] != y[i]) { distance++; }
    }

    return distance;
}

size_t Hamming_Distance(const std::string &S, const std::string &T) {
    if (S.size() != T.size()) {
        throw std::invalid_argument("Strings must have the same size to calculate Hamming Distance.");
    }

    size_t distance = 0;
    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) { distance++; }
    }

    return distance;
}
