#pragma once

#include"../Lazy_Segment_Tree.hpp"

template<typename T>
class Range_Add_Range_Min_Lazy_Segment_Tree : public Lazy_Segment_Tree<T, T> {
    using M = T;
    using F = T;

    static M op(M x, M y) { return x < y ? x : y; }
    static M act(F a, M x) { return x + a; }
    static F comp(F a, F b) { return a + b; }

    public:
    Range_Add_Range_Min_Lazy_Segment_Tree(int n, T first, T unit) : Lazy_Segment_Tree<M, F>(
        vector<M>(n, first), op, unit, act, comp, 0
    ) {}

    Range_Add_Range_Min_Lazy_Segment_Tree(int n, T unit) : Range_Add_Range_Min_Lazy_Segment_Tree<T>(n, unit, unit) {}

    Range_Add_Range_Min_Lazy_Segment_Tree(const vector<T> &vec, T unit) : Lazy_Segment_Tree<M, F>(
        vec, op, unit, act, comp, 0
    ) {}

    void update(int k, T x) { Lazy_Segment_Tree<M, F>::update(k, x); }

    T operator[](int k) { return Lazy_Segment_Tree<M, F>::operator[](k); }

    void add(int l, int r, T x) { this->action(l, r, x); }

    T min(int l, int r) { return this->product(l, r); }
};
