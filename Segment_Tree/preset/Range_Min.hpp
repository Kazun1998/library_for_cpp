#pragma once

#include "../Segment_Tree.hpp"

template<typename T>
class Range_Min_Segment_Tree : public Segment_Tree<T> {
    static T op(T x, T y) { return x < y ? x : y; }

    public:
    Range_Min_Segment_Tree(int n, T unit) : Segment_Tree<T>(n, op, unit) {}

    Range_Min_Segment_Tree(const vector<T> &vec, T unit) : Segment_Tree<T>(vec, op, unit) {}

    void update(int k, T x) { Segment_Tree<T>::update(k, x); }

    // 第 k 要素を取得する
    T get(int k) { return Segment_Tree<T>::get(k); }

    // 区間 [l, r] の最小値を求める
    T min(int l, int r) { return this->product(l, r); }
};
