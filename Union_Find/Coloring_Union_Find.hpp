#pragma once

template<typename Color>
class Coloring_Union_Find {
    int n, _group_number;
    vector<int> parents, rank;
    vector<Color> data;
    function<Color(const Color&, const Color&)> merge;

    public:
    Coloring_Union_Find(int n, function<Color(const Color&, const Color&)> merge, const Color& unit):
        n(n), parents(vector<int>(n, -1)), data(vector<Color>(n, unit)), rank(vector<int>(n, 0)), merge(merge), _group_number(n) {}

    int find(int x) {
        return parents[x] < 0 ? x : parents[x] = find(parents[x]);
    }

    /// @brief 辺 xy を加える. これによって x, y が連結になった場合, 連結成分の色の更新を行う.
    /// @param x 頂点 1
    /// @param y 頂点 2
    /// @return 連結成分の数が減ったら true.
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) { return false; }

        if (rank[x] < rank[y]) { swap(x, y); }

        data[x] = merge(data[x], data[y]);

        parents[x] += parents[y];
        parents[y] = x;

        _group_number--;

        if (rank[x] == rank[y]) { rank[x]++; }

        return true;
    }

    inline int size(int x) { return -parents[find(x)]; }

    inline bool same(int x, int y) { return find(x) == find(y); }

    /// @brief x が属する頂点の色を求める.
    /// @param x 頂点
    inline Color get(int x) { return data[find(x)]; }

    /// @brief x が属する連結成分の色を c に変更する.
    /// @param x 色を変更する頂点
    /// @param c 変更後の色
    inline void set(int x, Color c) { data[find(x)] = c; }

    inline int group_count() const { return _group_number; }
};
