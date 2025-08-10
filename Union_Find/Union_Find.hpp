#pragma once

class Union_Find{
    private:
    int N;
    vector<int> data;

    public:
    Union_Find(int N) : N(N), data(N, -1) {}

    // x が属する族の代表元を求める.
    int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]); }

    // x と y を結合する.
    // 返り値: 元々非連結ならば true, 連結ならば false
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) { return false; }

        if (data[x] > data[y]) { swap(x, y); }

        data[x] += data[y];
        data[y] = x;

        return true;
    }

    // x が属する族における位数を求める.
    int size(int x) { return -data[find(x)]; }

    // x, y は同じ連結成分にある?
    int same(int x, int y) { return find(x) == find(y); }
};
