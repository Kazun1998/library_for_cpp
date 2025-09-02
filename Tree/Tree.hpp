#pragma once

#include"../template/template.hpp"

class Tree {
    private:
    int N, offset, root;
    vector<int> parent;
    vector<set<int>> children;

    int N_bit;
    bool locked;

    public:
    Tree(int N, int offset = 0): N(N), offset(offset), N_bit(0) {
        parent.assign(N + offset, -1);
        for (; (1 << N_bit) <= N; N_bit++) {}
        locked = false;
    }

    bool is_locked() const { return locked; }

    public:
    inline void set_root(const int &x) {
        assert (!is_locked());
        root = x;
    }

    inline int vector_size() const { return N + offset; }

    public:
    // 頂点 x の親を頂点 y に設定する.
    inline void set_parent(const int &x, const int &y) {
        assert (!is_locked());
        parent[x] = y;
    }

    // 頂点 x の子の一つに頂点 y を設定する.
    inline void set_child(const int &x, const int &y) { set_parent(y, x); }

    // 木を確定させる
    void seal() {
        assert(!is_locked());

        parent[root] = -1;
        children.assign(N + offset, set<int>());
        for (int v = offset; v < N + offset; v++) {
            unless(is_root(v)) { children[parent[v]].insert(v); }
        }

        locked = true;
        bfs();
    }

    private:
    vector<int> depth;
    vector<vector<int>> tower;
    void bfs() {
        assert(is_locked());

        tower.assign(N, {});
        depth.assign(N + offset, -1);

        deque<int> Q{ root };
        tower[0] = { root };
        depth[root] = 0;

        while (!Q.empty()){
            int x = Q.front(); Q.pop_front();

            for (int y: children[x]) {
                depth[y] = depth[x] + 1;
                tower[depth[y]].emplace_back(y);
                Q.push_back(y);
            }
        }
    }

    // 1 頂点に関する情報
    public:

    // x は根?
    bool is_root(const int &x) const { return x == root; }

    // x は葉?
    bool is_leaf(const int &x) const {
        assert(is_locked());
        return children[x].empty();
    }

    // x の次数
    int degree(const int &x) const {
        assert(is_locked());
        int d = children[x].size();
        if (is_root(x)) { d--; }
        return d;
    }

    inline int vertex_depth(const int &x) { return depth[x]; }

    // 2 頂点に関する条件

    // x は y の親か?
    bool is_parent(const int &x, const int &y) const {
        assert(is_locked());
        return !is_root(y) && x == parent[y];
    }

    // x は y の個か?
    inline bool is_children(const int &x, const int &y) const { return is_parent(y, x); }

    // x と y は兄弟 (親が同じ) か?
    bool is_brother(const int &x, const int &y) const {
        assert(is_locked());
        return !is_root(x) && !is_root(y) && parent[x] == parent[y];
    }

    private:
    bool has_upper_list = false;
    vector<vector<int>> upper_list;

    void build_upper_list() {
        assert(is_locked());

        if (has_upper_list) { return; }

        has_upper_list = true;

        upper_list.assign(N_bit, vector<int>(N + offset, -1));

        // Step I
        for (int i = offset; i < N + offset; i++) {
            if (is_root(i)) { upper_list[0][i] = i; }
            else { upper_list[0][i] = parent[i]; }
        }

        // Step II
        for (int k = 1; k < N_bit; k++) {
            for (int i = offset; i < N + offset; i++) {
                upper_list[k][i] = upper_list[k - 1][upper_list[k - 1][i]];
            }
        }
    }

    public:
    int upper(int x, int k, bool over = true) {
        assert(is_locked());

        build_upper_list();
        if (vertex_depth(x) < k) { return over? root: -1; }

        for(int b = 0; k; k >>= 1, b++){ 
            if (k & 1) { x = upper_list[b][x]; }
        }

        return x;
    }

    public:
    int lowest_common_ancestor(int x, int y) {
        assert(is_locked());

        if (vertex_depth(x) > vertex_depth(y)) { swap(x, y); }
        y = upper(y, vertex_depth(y) - vertex_depth(x));

        if (is_root(x) || x == y) { return x; }

        for (int k = N_bit - 1; k >= 0; k--) {
            int px = upper_list[k][x], py = upper_list[k][y];
            if (px != py) { x = px, y = py; }
        }

        return is_root(x) ? root : parent[x];
    }
};
