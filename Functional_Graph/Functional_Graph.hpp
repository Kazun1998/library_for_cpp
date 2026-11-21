#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Functional_Graph/Functional_Graph.hpp

#include"../template/template.hpp"

class Functional_Graph {
    private:
    struct Cycle {
        // vertices = (c_0, c_1, ..., c_{m-1}) で, f(c_j) = c_{j+1}, f(c_{m-1}) = c_0 を満たす.
        vector<int> vertices;

        Cycle() = default;
        Cycle(vector<int> vertices): vertices(std::move(vertices)) {}

        inline int size() const { return vertices.size(); }

        // c_j から k 回移動した先の頂点 c_{(j + k) mod m} を求める.
        int jump(int j, ll k) const {
            int m = size();
            return vertices[(j + safe_mod(k, m)) % m];
        }
    };

    struct Tree {
        // vertices[0] は根 (サイクル上の頂点) である.
        vector<int> vertices;

        // depth[i] は vertices[i] の深さである.
        vector<int> depth;

        // doubling[b][i] は vertices[i] から 2^b 回移動した先の頂点の添字である.
        // ただし, 根は自分自身へ移るとする.
        vector<vector<int>> doubling;

        Tree() = default;

        // parent[i] は f(vertices[i]) の添字 (parent[0] = 0) である.
        Tree(vector<int> vertices, const vector<int> &parent, vector<int> depth): vertices(std::move(vertices)), depth(std::move(depth)) {
            int m = this->vertices.size();
            int max_depth = *max_element(this->depth.begin(), this->depth.end());
            int L = max<int>(1, bit_length(max_depth));

            doubling.assign(L, vector<int>(m));
            doubling[0] = parent;
            for (int b = 1; b < L; b++) {
                for (int i = 0; i < m; i++) {
                    doubling[b][i] = doubling[b - 1][doubling[b - 1][i]];
                }
            }
        }

        inline int root() const { return vertices[0]; }

        // vertices[i] から k 回移動した先の頂点を求める (0 <= k <= depth[i]).
        int upper(int i, ll k) const {
            for (int b = 0; k; k >>= 1, b++) {
                if (k & 1) { i = doubling[b][i]; }
            }
            return vertices[i];
        }
    };

    vector<int> f;
    vector<vector<int>> f_inv;
    int N;

    vector<Cycle> cycles;
    // cycle_ids[x]: x を含むサイクルの番号 (サイクル上の頂点でなければ -1)
    // cycle_vertex_ids[x]: x のサイクル内での添字 (サイクル上の頂点でなければ -1)
    vector<int> cycle_ids, cycle_vertex_ids;

    vector<Tree> trees;
    // tree_ids[x]: x を含む木の番号
    // tree_vertex_ids[x]: x の木の内での添字
    vector<int> tree_ids, tree_vertex_ids;

    public:
    Functional_Graph(const vector<int> &f): f(f), N(f.size()) {
        f_inv.resize(N);
        for (int x = 0; x < N; x++) { f_inv[f[x]].emplace_back(x); }
        build_up();
    }

    private:
    void build_up() {
        build_cycles();
        build_trees();
    }

    // サイクル検出パート
    void build_cycles() {
        vector<int> indegree(N);
        stack<int> st;
        for (int x = 0; x < N; x++) {
            indegree[x] = f_inv[x].size();
            if (indegree[x] == 0) { st.push(x); }
        }

        vector<bool> cycle_flag(N, true);

        while (!st.empty()) {
            int x = st.top();
            st.pop();

            cycle_flag[x] = false;
            indegree[f[x]]--;
            if (indegree[f[x]] == 0) { st.push(f[x]); }
        }

        cycles.clear();
        cycle_ids.assign(N, -1);
        cycle_vertex_ids.assign(N, -1);

        for (int x = 0; x < N; x++) {
            unless (cycle_flag[x]) { continue; }

            int cycle_id = cycles.size();

            vector<int> vertices{x};
            cycle_flag[x] = false;
            for (int y = f[x]; y != x; y = f[y]) {
                vertices.emplace_back(y);
                cycle_flag[y] = false;
            }

            int m = vertices.size();
            for (int j = 0; j < m; j++) {
                cycle_ids[vertices[j]] = cycle_id;
                cycle_vertex_ids[vertices[j]] = j;
            }

            cycles.emplace_back(std::move(vertices));
        }
    }

    // 木の構築パート
    void build_trees() {
        trees.clear();
        tree_ids.assign(N, -1);
        tree_vertex_ids.assign(N, -1);

        for (int x = 0; x < N; x++) {
            unless (is_on_cycle(x)) { continue; }

            int tree_id = trees.size();
            vector<int> vertices{x}, parent{0}, depth{0};
            tree_ids[x] = tree_id;
            tree_vertex_ids[x] = 0;

            stack<int> st;
            st.push(x);

            while (!st.empty()) {
                int y = st.top(); st.pop();
                int i = tree_vertex_ids[y];

                for (int z: f_inv[y]) {
                    if (is_on_cycle(z)) { continue; }

                    tree_ids[z] = tree_id;
                    tree_vertex_ids[z] = vertices.size();

                    vertices.emplace_back(z);
                    parent.emplace_back(i);
                    depth.emplace_back(depth[i] + 1);

                    st.push(z);
                }
            }

            trees.emplace_back(std::move(vertices), parent, std::move(depth));
        }
    }

    // x から k 回移動したときにサイクルに到達しているか (f^k(x) がサイクル上の頂点か) を判定する.
    // f(C) ⊂ C と深さの最小性より, k >= depth(x) と同値である.
    inline bool can_reach_cycle(int x, ll k) const { return k >= depth(x); }

    public:
    /// @brief 頂点 x がサイクル上の頂点かどうかを判定する.
    /// @param x 頂点
    /// @return ある k >= 1 について f^k(x) = x ならば true
    inline bool is_on_cycle(int x) const { return cycle_ids[x] != -1; }

    /// @brief 頂点 x の深さ (f^k(x) がサイクル上の頂点となる最小の k >= 0) を求める.
    /// @param x 頂点
    /// @return 頂点 x の深さ
    inline int depth(int x) const { return trees[tree_ids[x]].depth[tree_vertex_ids[x]]; }

    /// @brief 頂点 x の根 (x から深さの回数だけ移動して初めて到達するサイクル上の頂点) を求める.
    /// @param x 頂点
    /// @return 頂点 x の根
    inline int root(int x) const { return trees[tree_ids[x]].root(); }

    /// @brief 頂点 x が属する弱連結成分のサイクルの番号を求める.
    /// @param x 頂点
    /// @return x の根を含むサイクルの番号 (get_cycle, get_cycles の添字)
    inline int get_cycle_id(int x) const { return cycle_ids[root(x)]; }

    /// @brief サイクル上の頂点 c を根とする木の頂点集合を求める.
    /// @param c サイクル上の頂点
    /// @return 根が c である頂点全体 (先頭は c)
    const vector<int> &get_tree_vertices(int c) const {
        assert(is_on_cycle(c));
        return trees[tree_ids[c]].vertices;
    }

    /// @brief f^k(x) を求める.
    /// @param x 頂点
    /// @param k 移動回数 (k >= 0)
    /// @return f^k(x)
    int calculate(int x, ll k) const {
        assert(is_non_negative(k));

        const Tree &tree = trees[tree_ids[x]];
        int i = tree_vertex_ids[x];
        unless (can_reach_cycle(x, k)) { return tree.upper(i, k); }

        int r = tree.root();
        return cycles[cycle_ids[r]].jump(cycle_vertex_ids[r], k - tree.depth[i]);
    }

    /// @brief サイクルの個数を求める.
    inline int cycle_count() const { return cycles.size(); }

    /// @brief 番号 id のサイクルを求める.
    /// @param id サイクルの番号 (0 <= id < cycle_count())
    /// @return サイクル c_0, c_1, ..., c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0)
    const vector<int> &get_cycle(int id) const { return cycles[id].vertices; }

    /// @brief サイクル全体を求める.
    /// @return 各サイクル c_0, c_1, ..., c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0) のリスト
    vector<vector<int>> get_cycles() const {
        vector<vector<int>> res;
        res.reserve(cycles.size());
        for (const Cycle &cycle: cycles) { res.emplace_back(cycle.vertices); }
        return res;
    }
};
