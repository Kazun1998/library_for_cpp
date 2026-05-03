#pragma once

#include"../template/template.hpp"

class Tree {
    private:
    int N, _offset, root;
    vector<int> parent;
    vector<vector<int>> children;

    bool locked;

    public:
    Tree(int N, int _offset = 0): N(N), _offset(_offset) {
        parent.assign(N + _offset, -1);
        locked = false;
    }

    bool is_locked() const { return locked; }

    public:
    inline void set_root(const int &x) {
        assert (!is_locked());
        root = x;
    }

    inline int vector_size() const { return order() + offset(); }

    inline int get_root() const { return root; }
    inline int get_parent(const int &x) const { return parent[x]; }
    inline vector<int> get_children(const int &x) const { return children[x]; }

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
        children.assign(N + offset(), vector<int>());
        for (int v = offset(); v < N + offset(); v++) {
            unless(is_root(v)) { children[parent[v]].emplace_back(v); }
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
        depth.assign(N + offset(), -1);

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

    public:
    vector<int> top_down() const {
        vector<int> res;
        for (auto layer: tower) {
            res.insert(res.end(), layer.begin(), layer.end());
        }

        return res;
    }

    public:
    vector<int> bottom_up() const {
        vector<int> res;
        for (auto it = tower.rbegin(); it != tower.rend(); ++it) {
            const auto &layer = *it;
            res.insert(res.end(), layer.begin(), layer.end());
        }

        return res;
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

    // 頂点 x の深さを求める.
    inline int vertex_depth(const int &x) const { return depth[x]; }

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

    int lowest_common_ancestor_greedy(int x, int y) const {
        assert(is_locked());

        if (vertex_depth(x) > vertex_depth(y)) { swap(x, y); }

        while (vertex_depth(x) < vertex_depth(y)) {
            y = parent[y];
        }

        while (x != y) {
            x = get_parent(x);
            y = get_parent(y);
        }

        return x;
    }

    private:
    bool has_euler_tour_vertex = false, has_euler_tour_edge = false;

    public:
    vector<int> in_time, out_time;
    vector<int> euler_tour_vertex;
    vector<tuple<int, int, int>> euler_tour_edge;

    // Euler Tour に関する計算を行う.
    void calculate_euler_tour_vertex() {
        if(has_euler_tour_vertex) { return; }

        euler_tour_vertex.clear();
        in_time.assign(N + offset(), -1);
        out_time.assign(N + offset(), -1);

        auto dfs = [&](auto self, int x) -> void {
            in_time[x] = (int)euler_tour_vertex.size();
            euler_tour_vertex.emplace_back(x);

            for (int y: children[x]) {
                self(self, y);
            }

            out_time[x] = (int)euler_tour_vertex.size() - 1;
            unless(is_root(x)) { euler_tour_vertex.emplace_back(parent[x]); }
        };

        dfs(dfs, root);

        has_euler_tour_vertex = true;
    }

    void calculate_euler_tour_edge() {
        if(has_euler_tour_edge) { return; }

        calculate_euler_tour_vertex();
        euler_tour_edge.clear();

        for (int t = 0; t < 2 * (N - 1); t++) {
            int x = euler_tour_vertex[t], y = euler_tour_vertex[t + 1];
            int k = (x == parent[y]) ? 1 : -1;
            euler_tour_edge.emplace_back(make_tuple(x, y, k));
        }

        has_euler_tour_edge = true;
    }

    vector<int> path(int u, int v) const {
        int w = lowest_common_ancestor_greedy(u, v);

        vector<int> path_first{u}, path_second{v};

        while (u != w) {
            u = get_parent(u);
            path_first.emplace_back(u);
        }

        while (v != w) {
            v = get_parent(v);
            path_second.emplace_back(v);
        }

        path_second.pop_back();
        reverse(path_second.begin(), path_second.end());

        path_first.insert(path_first.end(), make_move_iterator(path_second.begin()), make_move_iterator(path_second.end()));

        return path_first;
    }

    inline int order() const { return N; }
    inline int offset() const { return _offset; }
};

Tree Construct_Tree(int N, vector<pair<int, int>> edges, int root, int offset = 0) {
    vector<vector<int>> adj(N + offset, vector<int>());
    for (auto &[u, v]: edges) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    Tree T(N, offset);
    T.set_root(root);

    vector<bool> seen(N + 1, false);
    seen[root] = true;
    vector<int> stack({root});

    until(stack.empty()) {
        int v = stack.back();
        stack.pop_back();

        for (int w: adj[v]) {
            if (seen[w]) { continue; }

            seen[w] = true;
            T.set_parent(w, v);
            stack.emplace_back(w);
        }
    }

    T.seal();
    return T;
}
