#pragma once

#include "../Segment_Tree.hpp"

template<typename T>
class Range_Sum_Segment_Tree : public Segment_Tree<T> {
    static T op(T x, T y) { return x + y; }

    public:
    Range_Sum_Segment_Tree(int n) : Segment_Tree<T>(n, op, T(0)) {}

    Range_Sum_Segment_Tree(const vector<T> &vec) : Segment_Tree<T>(vec, op, T(0)) {}

    void update(int k, T x) { Segment_Tree<T>::update(k, x); }

    // 第 k 要素を取得する
    T get(int k) { return Segment_Tree<T>::get(k); }

    // 区間 [l, r] の総和を求める
    T sum(int l, int r) { return this->product(l, r); }
};
