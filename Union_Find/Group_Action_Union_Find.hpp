#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template<class G, auto op, G identity, auto inv>
requires Group_Concept<G, op, identity, inv>
class Group_Action_Union_Find {
    private:
    vector<vector<int>> groups;
    vector<int> belong;
    vector<G> lazy, eager;

    public:
    /**
     * @brief Group_Action_Union_Find を構築する.
     * @param n 頂点数
     */
    explicit Group_Action_Union_Find(int n) {
        groups.resize(n);
        belong.resize(n);
        lazy.assign(n, identity);
        eager.assign(n, identity);

        for (int i = 0; i < n; ++i) {
            groups[i] = {i};
            belong[i] = i;
        }
    }

    /**
     * @brief 頂点 x が属する連結成分の代表元を求める.
     * @param x 頂点
     * @return 頂点 x が属する連結成分の代表元
     */
    int find(int x) const { return belong[x]; }

    /**
     * @brief 頂点 x と頂点 y を結ぶ.
     * @param x 頂点
     * @param y 頂点
     * @return すでに連結だった場合は false, 新たに連結になった場合は true
     */
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        // 小さい方を大きい方にマージ (Union by Size)
        if (groups[x].size() < groups[y].size()) {
            swap(x, y);
        }

        const G d = op(inv(lazy[x]), lazy[y]);

        for (int z : groups[y]) {
            belong[z] = x;
            groups[x].push_back(z);
            eager[z] = op(d, eager[z]);
        }

        groups[y].clear();
        return true;
    }

    /**
     * @brief 頂点 x と頂点 y が同じ連結成分に属するかを判定する.
     * @param x 頂点
     * @param y 頂点
     * @return 同じ連結成分に属する場合は true, そうでない場合は false
     */
    bool same(int x, int y) const { return find(x) == find(y); }

    /**
     * @brief 頂点 x が属する連結成分のサイズを求める.
     * @param x 頂点
     * @return 連結成分のサイズ
     */
    int size(int x) const { return groups[find(x)].size(); }

    /**
     * @brief 頂点 x が属する連結成分全体に、左から作用 a を適用する.
     * @param x 頂点
     * @param a 作用させる群の元
     */
    void action(int x, G a) {
        x = find(x);
        lazy[x] = op(a, lazy[x]);
    }

    /**
     * @brief 頂点 x の値 V(x) に、左から作用 a を適用し V(x) <- a・V(x) とする.
     * @param x 頂点
     * @param a 作用させる群の元
     */
    void vertex_action(int x, G a) {
        update(x, op(a, get(x)));
    }

    /**
     * @brief 頂点 x の値を a に更新する.
     * @param x 頂点
     * @param a 更新後の値
     */
    void update(int x, const G& a) { eager[x] = op(inv(lazy[find(x)]), a); }

    /**
     * @brief 頂点 x の現在の値を取得する.
     * @param x 頂点
     * @return 頂点 x の現在の値
     */
    G get(int x) const { return op(lazy[find(x)], eager[x]); }

    /**
     * @brief 頂点 x の現在の値を取得する. get(x) のエイリアス.
     * @param x 頂点
     * @return 頂点 x の現在の値
     */
    G operator[](int x) const { return get(x); }
};