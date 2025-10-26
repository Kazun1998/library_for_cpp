#include"../template/template.hpp"

class Functional_Graph {
    private:
    vector<int> f;
    vector<vector<int>> f_inv;
    int N;

    vector<vector<int>> cycles;
    vector<int> cycle_ids, cycle_vertex_ids;

    vector<int> tree_ids, tree_vertex_ids, tree_depth;
    vector<vector<int>> tree_vertices;
    vector<vector<vector<int>>> tree_doubling;

    public:
    Functional_Graph(const vector<int> &f): f(f), N(f.size()) {
        f_inv.resize(N);
        for (int x = 0; x < N; x++) { f_inv[f[x]].emplace_back(x); }
        build_up();
    }

    private:
    void build_up() {
        build_cycles();
        build_branches();
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
            if (!cycle_flag[x]) { continue; }

            int cycle_id = cycles.size();

            vector<int> cycle{x};
            cycle_flag[x] = false;
            int y = f[x];
            while (y != x) {
                cycle.emplace_back(y);
                cycle_flag[y] = false;
                y = f[y];
            }

            cycles.emplace_back(cycle);
            for (int j = 0; j < cycle.size(); j++) {
                int y = cycle[j];
                cycle_ids[y] = cycle_id;
                cycle_vertex_ids[y] = j;
            }
        }
    }

    void build_branches() {
        tree_ids.assign(N, -1);
        tree_vertex_ids.assign(N, -1);
        tree_depth.assign(N, 0);

        for (int x = 0; x < N; x++) {
            if (cycle_ids[x] == -1) { continue; }

            int tree_id = tree_vertices.size();
            vector<int> tree_vertex{x};

            int vertex_id = 0;
            tree_ids[x] = tree_id;
            tree_vertex_ids[x] = vertex_id;

            stack<int> st;
            st.push(x);

            int max_depth = 0;

            while (!st.empty()) {
                int y = st.top(); st.pop();

                for (int z: f_inv[y]) {
                    if (cycle_ids[z] != -1) { continue; }

                    vertex_id++;
                    tree_ids[z] = tree_id;
                    tree_vertex_ids[z] = vertex_id;

                    tree_depth[z] = tree_depth[y] + 1;
                    chmax(max_depth, tree_depth[z]);

                    st.push(z);
                    tree_vertex.emplace_back(z);
                }
            }

            tree_vertices.emplace_back(tree_vertex);
            int m = tree_vertex.size();
            vector<vector<int>> doubling(max<int>(1, bit_length(max_depth)), vector<int>(m, -1));

            for (int j = 1; j < m; j++) {
                doubling[0][j] = tree_vertex_ids[f[tree_vertex[j]]];
            }

            for (int b = 1; b < max<int>(1, bit_length(max_depth)); b++) {
                for (int j = 0; j < m; j++) {
                    doubling[b][j] = doubling[b - 1][doubling[b - 1][j]];
                }
            }

            tree_doubling.emplace_back(doubling);
        }
    }

    int upper(int x, ll k) {
        int tree_id = tree_ids[x];
        int vertex_id = tree_vertex_ids[x];

        vector<vector<int>> doubling = tree_doubling[tree_id];
        for (int b = 0; k; k >>= 1, b++) {
            if (k & 1) { vertex_id = doubling[b][vertex_id]; }
        }

        return tree_vertices[tree_id][vertex_id];
    }

    int jump_on_cycle(int cycle_id, int vertex_id, ll k) {
        auto &cycle = cycles[cycle_id];
        int m = cycle.size();
        k = safe_mod(k, m);
        return cycle[(vertex_id + k) % m];
    }

    public:
    inline int root(int x) const { return tree_vertices[tree_ids[x]][0]; }

    int calculate(int x, ll k) {
        if ( k < tree_depth[x]) { return upper(x, k); }

        k -= tree_depth[x];
        x = root(x);

        int cycle_id = cycle_ids[x];
        int vertex_id = cycle_vertex_ids[x];
        return jump_on_cycle(cycle_id, vertex_id, k);
    }

    vector<vector<int>> &get_cycles() { return cycles; }
};
