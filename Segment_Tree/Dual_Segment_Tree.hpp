#pragma once

#include"../template/template.hpp"

template <typename F>
class Dual_Segment_Tree {
    private:
    function<F(F, F)> comp;
    F id;
    int N, size;
    vector<F> lazy;

    void propagate_at(int m) {
        if (lazy[m] == id) { return; }

        lazy[(m << 1) | 0] = comp(lazy[m], lazy[(m << 1) | 0]);
        lazy[(m << 1) | 1] = comp(lazy[m], lazy[(m << 1) | 1]);
        lazy[m] = id;
    }

    inline void propagate_above(int m) {
        for (int h = bit_length(m) - 1; h > 0; --h) {
            propagate_at(m >> h);
        }
    }

    public:
    Dual_Segment_Tree(int N, std::function<F(F, F)> comp, const F& id): N(N), comp(comp), id(id) {
        int d = max(1, (int)bit_length(N - 1));
        int k = 1 << d;

        lazy.resize(2 * k, id);
        size = k;
    }

    void action(int l, int r, const F &alpha, bool left_closed = true, bool right_closed = true) {
        int L = l + size + (left_closed ? 0 : 1);
        int R = r + size + (right_closed ? 1 : 0);

        // 葉ノードより上の伝搬が必要なノードの最大番号を求める処理
        int L0 = -1, R0 = -1;
        int X = L, Y = R - 1; // Rは開区間なので R-1
        
        while (X < Y) {
            if (X & 1) {
                L0 = max(L0, X);
                X++;
            }

            if ((Y & 1) == 0) {
                R0 = max(R0, Y);
                Y--;
            }

            X >>= 1;
            Y >>= 1;
        }

        L0 = max(L0, X);
        R0 = max(R0, Y);

        if (L0 != -1) { propagate_above(L0); }
        if (R0 != -1) { propagate_above(R0); }

        while (L < R) {
            if (L & 1) {
                lazy[L] = comp(alpha, lazy[L]);
                L++;
            }

            if (R & 1) {
                R--;
                lazy[R] = comp(alpha, lazy[R]);
            }

            L >>= 1;
            R >>= 1;
        }
    }

    inline void refresh() {
        for (int m = 1; m < size; ++m) { propagate_at(m); }
    }

    inline F get(int k) {
        int m = k + size;
        propagate_above(m);
        return lazy[m];
    }

    inline const F operator[](const int index) { return get(index); }
};