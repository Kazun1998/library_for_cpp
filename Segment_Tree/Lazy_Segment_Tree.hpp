#pragma once

/* 遅延セグメント木
M を Monoid とする. M 上の列に対して, Monid F からの区間作用と, 連続部分列に対する区間積の計算の処理を高速に行う.

* M: Monoid
* F: Monoid
* op: M x M → M: M 上の演算
* unit: M の単位元
* act: F x M → M: F からの M の演算
* comp: F x F → F: F 同士の合成 (左の要素が新しい)
* id: F の単位元

(条件)
M: Monoid, F = {f: F x M → M: 作用素} に対して, 以下が成立する.
* F は写像の合成に閉じている. つまり, 任意の f,g in F に対して, comp(f,g) in F
* F は M に作用する. つまり, 以下が成り立つ.
    * F の単位元 id は恒等的に作用する. つまり, 任意の x in M に対して id(x) = x となる.
    * 任意の f in F, x,y in M に対して, f(xy) = f(x) f(y) である.


(注意)
作用素は左から掛ける. 更新も左から行う.
*/

template<typename M, typename F>
class Lazy_Segment_Tree {
    public:
    int n, depth;
    const function<M(M, M)> op;
    const function<M(F, M)> act;
    const function<F(F, F)> comp;
    vector<M> data; const M unit;
    vector<F> lazy; const F id;

    public:
    Lazy_Segment_Tree(int size, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id):
        n(), op(op), unit(unit), act(act), comp(comp), id(id), depth(0) {
            int m = 1;
            while (size > m) { depth++, m *= 2; }
            n = m;
            data.assign(2 * m, unit);
            lazy.assign(2 * m, id);
        }

    Lazy_Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id):
        Lazy_Segment_Tree(vec.size(), op, unit, act, comp, id){
            for (int k = 0; k < vec.size(); k++) { data[k+n] = vec[k]; }
            for (int k = n - 1; k > 0; k--) { data[k] = op(data[k << 1], data[k << 1 | 1]); }
        }

    private:
    inline M evaluate_at(int m){ return lazy[m] == id ? data[m] : act(lazy[m], data[m]); }

    /// @brief セグメントツリーの第 m 要素を更新し, 遅延していた作用を子に伝搬させる.
    /// @param m 
    void push(int m){
        data[m] = evaluate_at(m);

        if ((m < n) && (lazy[m] != id)){
            int left = m << 1;
            lazy[left] = (lazy[left] == id) ? lazy[m] : comp(lazy[m], lazy[left]);

            int right = m << 1 | 1;
            lazy[right] = (lazy[right] == id) ? lazy[m] : comp(lazy[m], lazy[right]); 
        }

        lazy[m] = id;
    }

    inline void propagate_above(int m){
        int h = 0, mm = m;
        for (mm; mm; mm >>= 1, h++){}

        for (h--; h >= 0; h--) { push(m >> h); }
    }

    inline void recalc_above(int m){
        while (m > 1){
            m >>= 1;
            data[m] = op(evaluate_at(m << 1), evaluate_at(m << 1 | 1));
        }
    }

    pair<int, int> range_propagate(int l, int r){
        int X = l + n, Y = r + n - 1, L0 = -1, R0 = -1;
    
        while (X < Y){
            if (X & 1) { L0 = max(L0, X++); }
            if ((Y & 1) ==0 ) { R0 = max(R0, Y--); }

            X >>= 1; Y >>= 1;
        }

        L0 = max(L0, X); R0 = max(R0, Y);
        propagate_above(L0); propagate_above(R0);
        return make_pair(L0, R0);
    }

    public:
    /// @brief 第 k 項を取得する.
    /// @param k 
    /// @return 第 k 項
    inline M operator[](int k){
        int m = k + n;
        propagate_above(m);
        lazy[m] = id;
        return data[m] = evaluate_at(m);
    }

    /// @brief i = l, l + 1, ..., r に対して, 第 i 項に対して alpha を作用させる.
    /// @param l 区間の左端
    /// @param r 区間の右端
    /// @param alpha 作用
    void action(int l, int r, F alpha){
        int L0, R0;
        tie(L0, R0) = range_propagate(l, r + 1);

        int L = l + n, R = r + n + 1;
        while (L < R){
            if (L & 1){
                lazy[L] = (alpha == id) ? id : comp(alpha, lazy[L]); 
                L++;
            }

            if (R & 1){
                R--;
                lazy[R] = (alpha == id) ? id : comp(alpha, lazy[R]);
            }

            L >>= 1; R >>= 1;
        }

        recalc_above(L0); recalc_above(R0);
    }

    /// @brief 第 k 項を x に更新する.
    /// @param k 更新場所
    /// @param x 更新後の要素
    inline void update(int k, M x){
        int m = k + n;
        propagate_above(m);
        data[m] = x; lazy[m] = id;
        recalc_above(m);
    }


    /// @brief 積 x[l] * x[l + 1] * ... * x[r] を求める.
    /// @param l 区間の左端
    /// @param r 区間の右端
    /// @return 積
    M product(int l, int r){
        int L0, R0;
        tie(L0, R0) = range_propagate(l, r + 1);

        int L = l + n, R = r + n + 1;
        M vL = unit, vR = unit;
        while (L < R){
            if (L & 1) { vL = op(vL, evaluate_at(L)); L++; }
            if (R & 1) { R--; vR=op(evaluate_at(R), vR); }

            L >>= 1; R >>= 1;
        }

        return op(vL, vR);
    }

    /// @brief 全要素における区間積を求める.
    /// @return 残要素における区間積
    inline M all_product() {return product(0, n);}

    void refresh() {
        for (int m = 1; m < 2 * n; m++){
            data[m] = evaluate_at(m);
            if ((m < n) && (lazy[m] != id)){
                int left = m << 1;
                lazy[left] = (lazy[left] == id) ? lazy[m] : comp(lazy[m], lazy[left]);

                int right = m << 1 | 1;
                lazy[right] = (lazy[right] == id) ? lazy[m] : comp(lazy[m], lazy[m << 1 | 1]);
            }
            lazy[m] = id;
        }
    }
};
