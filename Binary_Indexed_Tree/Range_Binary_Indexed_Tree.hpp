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

    inline void update(int k, G x) { bit0.add(k, op(neg(get(k)), x)); }

    inline void add(int l, G x) { bit0.add(l, x); }

    void add(int l, int r, G x) {
        bit0.add(l, neg(mul(l, x)));
        bit1.add(l, x);
        if (r < n - 1) {
            bit0.add(r + 1, mul(r + 1, x));
            bit1.add(r + 1, neg(x));
        }
    }

    inline G get(int k) const { return sum(k, k); }

    inline G sum(int r) const { return op(bit0.sum(r), mul(r + 1, bit1.sum(r))); }

    G sum(int l, int r) const {
        if (l > 0) {
            return op(sum(r), neg(sum(l - 1)));
        } else {
            return sum(r);
        }
    }
};