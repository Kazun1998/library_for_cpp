#pragma once

#include"../template/template.hpp"
#include"Tree.hpp"

class Centroid_Decomposition {
    private:
    int N, _offset;
    vector<vector<int>> adj;
    vector<int> centroid_parent, centroid_depth;
    vector<int> decomposition_order;
    vector<bool> removed;
    vector<int> subtree_size;
    vector<vector<int>> component_vertices;

    private:
    // Tree オブジェクトを (親, 子) の辺リストに変換する.
    static vector<pair<int, int>> to_edges(const Tree &tree) {
        assert(tree.is_locked());

        vector<pair<int, int>> edges;
        for (int v = tree.offset(); v < tree.order() + tree.offset(); v++) {
            for (int c: tree.get_children(v)) { edges.emplace_back(v, c); }
        }
        return edges;
    }

    public:
    /**
     * @brief コンストラクタ. 重心分解を構築する.
     * @param tree 対象となる Tree オブジェクト. 事前に seal() している必要がある.
     */
    Centroid_Decomposition(const Tree &tree): Centroid_Decomposition(tree.order(), to_edges(tree), tree.offset()) {}

    Centroid_Decomposition(int N, const vector<pair<int, int>> &edges, int offset = 0): N(N), _offset(offset) {
        adj.assign(N + offset, {});
        for (auto &[u, v]: edges) {
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        centroid_parent.assign(N + offset, -1);
        centroid_depth.assign(N + offset, -1);
        removed.assign(N + offset, false);
        subtree_size.assign(N + offset, 0);
        component_vertices.assign(N + offset, {});
        decomposition_order.reserve(N);

        build(offset, -1, 0);
    }

    private:
    // x を根とする (removed な頂点を除いた) 部分木のサイズを計算する.
    int calculate_subtree_size(int x, int p) {
        subtree_size[x] = 1;
        for (int y: adj[x]) {
            if (y == p || removed[y]) { continue; }
            subtree_size[x] += calculate_subtree_size(y, x);
        }
        return subtree_size[x];
    }

    // x を含む連結成分 (サイズ total) の重心を求める.
    int find_centroid(int x, int p, int total) {
        for (int y: adj[x]) {
            if (y == p || removed[y]) { continue; }
            if (subtree_size[y] > total / 2) {
                subtree_size[x] = total - subtree_size[y];
                return find_centroid(y, x, total);
            }
        }
        return x;
    }

    // x を根とする (removed な頂点を除いた) 部分木の頂点一覧を out に集める.
    void collect_component(int x, int p, vector<int> &out) {
        out.emplace_back(x);
        for (int y: adj[x]) {
            if (y == p || removed[y]) { continue; }
            collect_component(y, x, out);
        }
    }

    void build(int start, int parent_centroid, int depth) {
        int total = calculate_subtree_size(start, -1);
        int c = find_centroid(start, -1, total);

        centroid_parent[c] = parent_centroid;
        centroid_depth[c] = depth;
        decomposition_order.emplace_back(c);

        component_vertices[c].reserve(total);
        collect_component(c, -1, component_vertices[c]);

        removed[c] = true;
        for (int y: adj[c]) {
            unless(removed[y]) { build(y, c, depth + 1); }
        }
    }

    public:
    // 重心木上での x の親 (x が根なら -1).
    inline int get_centroid_parent(const int &x) const { return centroid_parent[x]; }

    // 重心木上での x の深さ (最初に取り除かれた頂点が深さ 0).
    inline int get_centroid_depth(const int &x) const { return centroid_depth[x]; }

    // 重心を取り除いた順番 (= 重心木を深さの浅い方から並べたもの).
    const vector<int>& order() const { return decomposition_order; }

    // 重心木の根.
    inline int get_root() const { return decomposition_order.front(); }

    // 重心 x が取り除かれた際に属していた連結成分の頂点一覧 (x 自身を含む).
    inline const vector<int>& get_component(const int &x) const { return component_vertices[x]; }

    inline int vertex_size() const { return N; }
    inline int offset() const { return _offset; }
};
