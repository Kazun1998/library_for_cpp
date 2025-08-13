#pragma once

template<typename G>
class Binary_Indexed_Tree{
    private:
    int n;
    vector<G> data;
    G zero;
    function<G(G, G)> op;
    function<G(G)> neg;

    // 初期化
    public:
    Binary_Indexed_Tree(int n, const function<G(G, G)> op, const G zero, const function<G(G)> neg): n(n), op(op), zero(zero), neg(neg) {
        data.assign(n + 1, zero);
    }

    Binary_Indexed_Tree(const vector<G> &vec, const function<G(G, G)> op, const G zero, const function<G(G)> neg):
        Binary_Indexed_Tree(vec.size(), op, zero, neg) {
            for (int k = 1; k <= n; k++){
                data[k] = op(data[k], vec[k - 1]);
                int l = k + (k & (-k));
                if (l <= n) { data[l] = op(data[l], data[k]); }
            }
        }

    // 第 k 要素に x を左から加える.
    void add(int k, G x) {
        for (++k; k <= n; k += k & (-k)) { data[k] = op(data[k], x); }
    }

    // 第 k 要素を x に変更する.
    void update(int k, G x) {
        add(k, op(neg((*this)[k]), x));
    }

    // 右半開区間 [0, k] における総和を求める.
    G sum(int k) const {
        G total = zero;

        for (++k; k > 0; k -= k & (-k)) { total = op(total, data[k]); }

        return total;
    }

    // 右半開区間 [l, r] における総和を求める.
    G sum(int l, int r) const {
        l = max(l, 0);
        r = min(r, n - 1);

        if (l > r) { return zero; }
        else if (l == 0) { return sum(r); }
        else { return op(sum(r), neg(sum(l - 1))); }
    }

    // 第 k 要素を取得する.
    inline G operator[](int k) const { return sum(k, k + 1); }
};

template<typename G>
Binary_Indexed_Tree<G> Group_Binary_Indexed_Tree(const vector<G> &vec, G zero){
    auto add = [](G x, G y) -> G { return x + y; };
    auto inv = [](G x) -> G { return -x; };
    return Binary_Indexed_Tree<G>(vec, add, zero, inv);
}
