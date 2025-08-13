#include<bits/stdc++.h>

using namespace std;

#pragma

class Tree {
    private:
    int N, offset, root;
    vector<int> parent;
    vector<set<int>> children;

    int N_bit;
    bool locked;

    public:
    Tree(int N, int offset = 0) {
        parent.assign(N + offset, -1);
        for (int N_bit = 0; (1 << N_bit) <= N; N_bit++) {}
        locked = false;
    }

    bool is_locked() { return locked; }

    public:
    inline void set_root(const int &x) {
        assert (!is_locked());
        root = x;
    }

    public:
    // 頂点 x の親を頂点 y に設定する.
    inline void set_parent(const int &x, const int &y) {
        assert (!is_locked());
        parent[x] = y;
    }

    // 頂点 x の子の一つに頂点 y を設定する.
    inline void set_parent(const int &x, const int &y) { set_parent(y, x); }
};