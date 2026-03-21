#pragma once

#include "../Lazy_Segment_Tree.hpp"

template<typename T>
class Range_Composite_Range_Min_Lazy_Segment_Tree : public Lazy_Segment_Tree<pair<T, int>, pair<T, T>> {
    using M = pair<T, int>;
    using F = pair<T, T>;

    static M op(M x, M y) { return { x.first + y.first, x.second + y.second }; }
    static M act(F f, M x) { return { f.first * T(x.second) + f.second * x.first, x.second }; }
    static F comp(F f, F g) { return { f.first + f.second * g.first, f.second * g.second }; }

    static vector<M> convert(const vector<T> &vec) {
        vector<M> res(vec.size());
        for (int i = 0; i < (int)vec.size(); ++i) {
            res[i] = {vec[i], 1};
        }
        return res;
    }

    public:
    Range_Composite_Range_Min_Lazy_Segment_Tree(int n) : Lazy_Segment_Tree<M, F>(
        vector<M>(n, {0, 1}), op, {0, 0}, act, comp, {0, 1}
    ) {}

    Range_Composite_Range_Min_Lazy_Segment_Tree(const vector<T> &vec) : Lazy_Segment_Tree<M, F>(
        convert(vec), op, {0, 0}, act, comp, {0, 1}
    ) {}

    void update(int k, T x) { Lazy_Segment_Tree<M, F>::update(k, {x, 1}); }

    T operator[](int k) { return Lazy_Segment_Tree<M, F>::operator[](k).first; }

    void composite(int l, int r, T a, T b) { this->action(l, r, {a, b}); }

    T sum(int l, int r) { return this->product(l, r).first; }
};
