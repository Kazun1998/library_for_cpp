#pragma once

#include "../Segment_Tree.hpp"

template<typename T>
class Range_Max_Segment_Tree : public Segment_Tree<T> {
    static T op(T x, T y) { return x < y ? y : x; }

    public:
    Range_Max_Segment_Tree(int n, T unit) : Segment_Tree<T>(n, op, unit) {}

    Range_Max_Segment_Tree(const vector<T> &vec, T unit) : Segment_Tree<T>(vec, op, unit) {}

    void update(int k, T x) { Segment_Tree<T>::update(k, x); }

    // 第 k 要素を取得する
    T get(int k) { return Segment_Tree<T>::get(k); }

    // 区間 [l, r] の最大値を求める
    T max(int l, int r) { return this->product(l, r); }
};
