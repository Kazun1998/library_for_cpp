#pragma once

#include"../Lazy_Segment_Tree.hpp"

template<typename T>
class Range_Add_Range_Sum_Lazy_Segment_Tree : public Lazy_Segment_Tree<pair<T, int>, T> {
    using M = pair<T, int>;
    using F = T;

    static M op(M x, M y) { return {x.first + y.first, x.second + y.second}; }
    static M act(F a, M x) { return {x.first + a * T(x.second), x.second}; }
    static F comp(F a, F b) { return a + b; }

    static vector<M> convert(const vector<T> &vec) {
        vector<M> res(vec.size());
        for (int i = 0; i < (int)vec.size(); ++i) {
            res[i] = {vec[i], 1};
        }
        return res;
    }

    public:
    Range_Add_Range_Sum_Lazy_Segment_Tree(int n) : Lazy_Segment_Tree<M, F>(
        vector<M>(n, {0, 1}), op, {0, 0}, act, comp, 0
    ) {}

    Range_Add_Range_Sum_Lazy_Segment_Tree(const vector<T> &vec) : Lazy_Segment_Tree<M, F>(
        convert(vec), op, {0, 0}, act, comp, 0
    ) {}

    void update(int k, T x) { Lazy_Segment_Tree<M, F>::update(k, {x, 1}); }

    T operator[](int k) { return Lazy_Segment_Tree<M, F>::operator[](k).first; }

    void add(int l, int r, T x) { this->action(l, r, x); }

    T all_sum() { return this->all_product().first; }
    T sum(int l, int r) { return this->product(l, r).first; }
};
