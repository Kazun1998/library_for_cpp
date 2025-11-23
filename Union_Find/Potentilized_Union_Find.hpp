#pragma once

#include"../template/template.hpp"

template<typename Pot>
class Potentilized_Union_Find {
    int n, _group_number;
    vector<int> par, rank;
    vector<Pot> pot; // P(x) = pot[x] P(par[x])
    vector<bool> valid;

    Pot zero;
    function<Pot(const Pot&, const Pot&)> add;
    function<Pot(const Pot&, const Pot&)> diff;
    function<Pot(const Pot&)> neg;

    public:
    Potentilized_Union_Find(int n, function<Pot(const Pot&, const Pot&)> add, const Pot &zero, const function<Pot(const Pot &)> neg):
        n(n), par(vector<int>(n, -1)), rank(vector<int>(n, 0)), pot(vector<Pot>(n, zero)), valid(vector<bool>(n, true)), _group_number(n),
        zero(zero), add(add), neg(neg) {
            diff = [&add, &neg](const Pot& a, const Pot& b) { return add(neg(a), b); };
        }

    /// @brief 頂点 x が属する連結成分の代表元を求める.
    /// @param x 
    int find(int x) {
        // x 自身が代表元ならば, x で決定
        if (par[x] < 0) { return x; }

        int r = find(par[x]);
        pot[x] = add(pot[x], pot[par[x]]);
        return par[x] = r;
    }

    /// @brief 頂点 x, y は連結か?
    /// @param x 
    /// @param y 
    inline bool same(int x, int y) { return find(x) == find(y); }

    /// @brief 頂点 x が属する連結成分における頂点数を求める.
    /// @param x 
    inline int size(int x) { return -par[find(x)]; }

    /// @brief P(x) = a P(y) という情報を加える.
    /// @param x 
    /// @param y 
    /// @param a 
    /// @return x, y の間が無矛盾ならば true, 矛盾があれば false.
    bool unite(int x, int y, Pot a) {
        a = add(a, potential(y));
        a = add(neg(potential(x)), a);

        x = find(x), y = find(y);

        if (x == y) {
            valid[x] = valid[x] && (a == zero);
            return valid[x];
        }

        if (rank[x] > rank[y]) {
            swap(x, y);
            a = neg(a);
        }

        if (rank[x] == rank[y]) { rank[x]++; }

        valid[y] = valid[x] && valid[y];

        par[y] += par[x];

        par[x] = y;
        pot[x] = a;

        _group_number--;

        return true;
    }

    Pot potential(int x) {
        find(x);
        return pot[x];
    }

    /// @brief x から見た y のポテンシャルを求める. つまり, -P(y) + P(x) を求める.
    /// @param x 基準
    /// @param y ポテンシャルを求める点
    Pot potential(int x, int y) { return add(potential(x), neg(potential(y))); }

    bool is_valid(int x) { return valid[x]; }

    /// @brief x - y 間のポテンシャルは位置に定まるか?
    /// @param x 
    /// @param y 
    /// @return 
    inline bool is_well_defined(int x, int y) { return same(x, y) && is_valid(x); }

    /// @brief P(x) = P(y) + a となり得るか?
    /// @param x 
    /// @param y 
    /// @param a 
    /// @return 
    bool is_possible(int x, int y, Pot a) { return !same(x, y) || potential(x, y) == a; }

    /// @brief 連結成分の数
    int group_count() const { return _group_number; }
};
