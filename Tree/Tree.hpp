#pragma once

#include"../template/template.hpp"

class Tree {
    private:
    int N, offset, root;
    vector<int> parent;
    vector<vector<int>> children;

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
        children.assign(N + offset, vector<int>());
        for (int v = offset; v < N + offset; v++) {
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

    public:
    vector<int> top_down() const {
        vector<int> res;
        for (auto layer: tower) {
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
    // 頂点 x から見て k 代前の頂点を求める.
    // vertex_depth(x) < k のとき返り値は over = true ならば root, false ならば, -1 である.
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
    // 頂点 x と頂点 y の最小共通先祖を求める.
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

    int lowest_common_ancestor_greedy(int x, int y) {
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

    // 2 頂点 x, y 間の距離を求める.
    int distance(int x, int y) {
        return vertex_depth(x) + vertex_depth(y) - 2 * vertex_depth(lowest_common_ancestor(x, y));
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
        in_time.assign(N + offset, -1);
        out_time.assign(N + offset, -1);

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

    // 頂点 u から頂点 v へ向かうパスにおいて k 番目 (0-indexed) に通る頂点 (パスの長さが k より大きい場合は over)
    int jump(int u, int v, int k, int over = -1) {
        if (k == 0) { return u; }

        int w = lowest_common_ancestor(u, v);
        int dist_uw = vertex_depth(u) - vertex_depth(w);
        int dist_wv = vertex_depth(v) - vertex_depth(w);
        int dist_uv = dist_uw + dist_wv;

        if (dist_uv < k) { 
            return over;
        } else if (k <= dist_uw) {
            return upper(u, k);
        } else {
            return upper(v, dist_uv - k);
        }
    }
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
