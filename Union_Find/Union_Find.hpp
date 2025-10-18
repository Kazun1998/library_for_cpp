#pragma once

class Union_Find{
    private:
    int N;
    vector<int> data;
    int group_number;

    public:
    Union_Find(int N) : N(N), data(N, -1), group_number(N) {}

    // x が属する族の代表元を求める.
    int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]); }

    // 頂点を 1 個追加する.
    int add_vertex() {
      data.emplace_back(-1);
      N++;
      group_number++;

      return N - 1;
    }

    // 頂点を k 個追加する.
    vector<int> add_vertices(int k) {
      vector<int> ids;
      for (; k; k--) { ids.emplace_back(add_vertex()); }

      return ids;
    }

    // x と y を結合する.
    // force を true にすると, 必ず find(x) が根になるように結合する.
    // 返り値: 元々非連結ならば true, 連結ならば false
    bool unite(int x, int y, bool force = false) {
        x = find(x);
        y = find(y);

        if (x == y) { return false; }

        if (!force && (data[x] > data[y])) { swap(x, y); }

        data[x] += data[y];
        data[y] = x;

        group_number--;

        return true;
    }

    // x が属する族における位数を求める.
    int size(int x) { return -data[find(x)]; }

    // x, y は同じ連結成分にある?
    int same(int x, int y) { return find(x) == find(y); }
};
