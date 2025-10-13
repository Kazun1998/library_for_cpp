#pragma once

#include"../template/template.hpp"

template<typename S>
vector<pair<S, size_t>> Run_Length_Encoding(const vector<S> &x) {
    vector<pair<S, size_t>> res;

    if (x.empty()) { return res; }

    res.emplace_back(x[0], 1);
    for (size_t i = 1; i < x.size(); ++i) {
        auto &last = res.back();

        if(last.first == x[i]) { last.second++; }
        else { res.emplace_back(x[i], 1); }
    }

    return res;
}

std::vector<std::pair<char, size_t>> Run_Length_Encoding(const std::string &S) {
    if (S.empty()) { return {}; }
    
    std::vector<std::pair<char, size_t>> res;
    res.emplace_back(S[0], 1);
    
    for (size_t i = 1; i < S.size(); ++i) {
        auto &last = res.back();

        if (last.first == S[i]) { 
            last.second++; 
        } else {
            res.emplace_back(S[i], 1);
        }
    }
    return res;
}
