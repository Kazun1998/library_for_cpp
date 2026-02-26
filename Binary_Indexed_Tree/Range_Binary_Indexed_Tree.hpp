#pragma once

#include"../template/template.hpp"
#include"Binary_Indexed_Tree.hpp"

template<typename G>
class Range_Binary_Indexed_Tree {
    private:
    const int n;
    const function<G(G, G)> op;
    const G zero;
    const function<G(G)> neg;
    const function<G(int, G)> mul;

    Binary_Indexed_Tree<G> bit0, bit1;

    public:
    Range_Binary_Indexed_Tree(int n, const function<G(G, G)> op, const G zero, const function<G(G)> neg, const function<G(int, G)> mul): n(n), op(op), zero(zero), neg(neg), mul(mul) {
        bit0 = Binary_Indexed_Tree<G>(vector<G>(n, zero), op, zero, neg);
        bit1 = Binary_Indexed_Tree<G>(vector<G>(n, zero), op, zero, neg);
    }

    /// @brief 第 k 要素を x に更新する.
    /// @param k 更新箇所
    /// @param x 更新後の値
    inline void update(int k, G x) { bit0.add(k, op(neg(get(k)), x)); }

    /// @brief 第 k 要素に x を加算する.
    /// @param k 加算箇所
    /// @param x 加算要素
    inline void add(int k, G x) { bit0.add(k, x); }

    /// @brief 第 l 要素から第 r 要素の全てに対して x を加算する.
    /// @param l 左端
    /// @param r 右端
    /// @param x 加算要素
    void add(int l, int r, G x) {
        bit0.add(l, neg(mul(l, x)));
        bit1.add(l, x);
        if (r < n - 1) {
            bit0.add(r + 1, mul(r + 1, x));
            bit1.add(r + 1, neg(x));
        }
    }

    /// @brief 第 k 要素を取得する.
    /// @param k 取得箇所
    inline G get(int k) const { return sum(k, k); }

    /// @brief 第 0 要素から第 r 要素までの総和を求める.
    /// @param r 右端
    inline G sum(int r) const { return op(bit0.sum(r), mul(r + 1, bit1.sum(r))); }

    /// @brief 第 l 要素から第 r 要素までの総和を求める.
    /// @param l 左端
    /// @param r 右端
    G sum(int l, int r) const {
        return l > 0 ? op(sum(r), neg(sum(l - 1))) : sum(r);
    }

    inline G operator[](const int k) const { return sum(k, k); }
};
