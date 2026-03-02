#pragma once

#include"../template/template.hpp"

// Reference: https://github.com/drken1215/algorithm/blob/master/DataStructure/intervals_management.cpp

template<typename T, class V = ll>
class Interval_Set {
    struct Node {
        T l, r;
        V val;

        /// @brief 値 val が紐づいている, 右半開区間 [l, r) を生成する.
        /// @param l 左端
        /// @param r 右端
        /// @param val 紐づける要素
        Node (const T &l, const T &r, const V &val): l(l), r(r), val(val) {};

        /// @brief p はこの右半開区間に含まれるか?
        /// @param p 
        constexpr bool contains(const T &p) const { return l <= p && p < r; }

        constexpr bool operator<(const Node &rhs) const {
            if (l != rhs.l) { return l < rhs.l; }
            return r < rhs.r;
        }

        friend ostream& operator<<(ostream &os, const Node &node) {
            return os << "([" << node.l << ", " << node.r << "): " << node.val << ")";
        }
    };

    const V nil; // デフォルト値
    size_t set_size;
    set<Node> intervals;

    template<class ADDFUNC>
    void add_update(const ADDFUNC &add, const T l, const T r, const V &val) {
        add(l, r, val);
        set_size += r - l;
    }

    template<class DELFUNC>
    void del_update(const DELFUNC &del, const T l, const T r, const V &val) {
        del(l, r, val);
        set_size -= r - l;
    }

    public:
    Interval_Set(): Interval_Set(V()) {}

    // デフォルト値を nil として, Interval Set インスタンスを生成する.
    Interval_Set(const V &nil): nil(nil), set_size(0) {}

    // iterators
    constexpr typename set<Node>::iterator begin() { return intervals.begin(); }
    constexpr typename set<Node>::iterator end() { return intervals.end(); }

    /// @brief p を含む区間のイテレータを求める (存在しない場合は, end() が返り値).
    /// @param p 
    constexpr typename set<Node>::iterator get(const T &p) const {
        auto it = intervals.upper_bound(Node(p, numeric_limits<T>::max(), 0));
        if (it == intervals.begin()) { return intervals.end(); }

        // ここに来る it は, p を含む区間の次の区間なので, 1 個戻す.
        it = prev(it);

        return it->contains(p) ? it : intervals.end();
    }

    /// @brief p 以上である最小の要素を含んでいる区間のイテレータを求める.
    /// @param p
    constexpr typename set<Node>::iterator lower_bound(const T &p) {
        auto it = get(p);

        if (it != intervals.end()) { return it; }
        return intervals.upper_bound(Node(p, numeric_limits<T>::max(), 0));
    }

    /// @brief p を含むか?
    /// @param p
    constexpr bool covered(const T &p) {
        return get(p) != intervals.end();
    }

    /// @brief 区間 [l, r) を含むか?
    /// @param l 
    /// @param r 
    constexpr bool covered(const T &l, const T &r) {
        assert(l <= r);

        if (l == r) { return true; }

        auto it = get(l);
        return it != intervals.end() && r <= it->r;
    }

    constexpr bool same(const T &p, const T &q) {
        return covered(p) && covered(q) && get(p) == get(q);
    }

    /// @brief p を含む右半開区間に紐づいている値を求める (そのような右半開区間が存在しない場合は nil が返り値)
    /// @param p 
    constexpr V get_value(const T &p) const {
        auto it = get(p);
        return it != intervals.end() ? it->val : nil;
    }

    V operator[](const T &p) const { return get_value(p); }

    constexpr T get_mex(const T &p = 0) {
        auto it = intervals.upper_bound(Node(p, numeric_limits<T>::max(), 0));
        if (it == intervals.begin()) { return p; }

        it = prev(it);

        return it->contains(p) ? it->r : p;
    }

    /// @brief val が紐づいた, 右半開区間 [l, r) を追加または更新する. その際, 発生する差分を add, del 関数で処理する.
    ///        この関数は,新しい区間 [l, r) と既存の区間との重複を適切に処理し,必要に応じて区間の結合,分割,削除を行う.
    /// @param l 左端 (追加または更新する区間の左端)
    /// @param r 右端 (追加または更新する区間の右端)
    /// @param val 右半開区間に紐づける値
    /// @param add 追加差分が発生した際の処理 (引数: T left, T right, V value)
    /// @param del 削除差分が発生した場合の処理 (引数: T left, T right, V value)
    template<class ADDFUNC, class DELFUNC>
    void update(T l, T r, const V &val, const ADDFUNC &add, const DELFUNC &del) {
        // 新しく追加または更新する区間 [l, r) の開始点 l 以上で最も近い区間を見つける.
        // これにより,既存の区間との重複チェックを開始する適切な位置を特定する.
        auto it = intervals.lower_bound(Node(l, 0, val));

        // 新しい区間 [l, r) と重なる可能性のある既存の区間を全て処理する.
        // it->l <= r は,現在の区間 it の左端が新しい区間 [l, r) の右端 r 以下であることを示す.
        while (it != intervals.end() && it->l <= r) {
            // Case 0: 新しい区間の右端 r が現在の区間 it の左端 it->l と一致する場合
            // かつ,値も同じ場合は区間を結合する.
            // これ以上右側の区間との重複はないため,ループを抜ける.
            if (r == it->l) {
                if (it->val == val) {
                    r = it->r; // 新しい区間の右端を拡張
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                }
                break;
            }

            // Case 1: 現在の区間 [it->l, it->r) が新しい区間 [l, r) に完全に含まれるか,
            // または,新しい区間の右端 r で終わる場合 (it->r <= r)
            // この区間は新しい区間に上書きされるため,削除する.
            if (it->r <= r) {
                del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                it = intervals.erase(it);
            } else {
                // Case 2: 新しい区間 [l, r) が現在の区間 [it->l, it->r) の一部と重なる場合
                // (l <= it->l < r < it->r が確定)
                if (it->val == val) {
                    // 値が同じ場合は,新しい区間と現在の区間を結合し,新しい区間の右端を拡張する.
                    // 既存区間は削除される.
                    r = it->r; // 新しい区間の右端を拡張
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                } else {
                    // 値が異なる場合は,現在の区間 [it->l, it->r) を新しい区間によって二分割する.
                    // [it->l, r) の部分は新しい区間によって上書きされるため,[r, it->r) の部分のみが残る.
                    Node node = *it;
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                    // 残りの区間 [r, node.r) を挿入する.
                    it = intervals.emplace_hint(it, r, node.r, node.val);
                    add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
                }
            }
        }

        // 新しい区間 [l, r) の左端 l のすぐ左にある既存の区間をチェックする.
        // これにより,新しい区間と左側の既存区間の結合や分割を処理する.
        if (it != intervals.begin()) {
            it = prev(it); // 左側の区間を取得
            // Case 3: 左側の区間 [it->l, it->r) の右端 it->r が新しい区間の左端 l と一致する場合
            if (it->r == l) {
                if (it->val == val) {
                    // 値が同じ場合は,両区間を結合し,新しい区間の左端を拡張する.
                    l = it->l;
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                }
            } else if (l < it->r) {
                // Case 4: 左側の区間 [it->l, it->r) が新しい区間 [l, r) と重なる場合
                // (it->l < l < it->r が確定)
                if (it->val == val) {
                    // 値が同じ場合は,両区間を結合し,新しい区間の範囲を拡張する.
                    l = min(l, it->l);
                    r = max(r, it->r);
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                } else {
                    // 値が異なる場合は,左側の区間 [it->l, it->r) を新しい区間によって二分割する.
                    // [it->l, l) の部分と [l, it->r) の部分に分けられ,
                    // 後者は新しい区間によって上書きされるため,[it->l, l) の部分のみが残る.
                    if (r < it->r) { // 新しい区間が左側の区間の一部をカバーする場合
                        // 左側の区間の残りの部分 [r, it->r) を挿入
                        it = intervals.emplace_hint(next(it), r, it->r, it->val);
                        add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
                        it = prev(it); // イテレータを元に戻す
                    }
                    Node node = *it;
                    del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                    it = intervals.erase(it);
                    // 残りの区間 [node.l, l) を挿入する.
                    it = intervals.emplace_hint(it, node.l, l, node.val);
                    add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
                }
            }
        }

        // 適切な位置にイテレータを調整する.
        if (it != intervals.end()) { it = next(it); }

        // 最終的に確定した新しい区間 [l, r) を挿入する.
        it = intervals.emplace_hint(it, l, r, val);
        add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
    }

    void update(const T &l, const T &r, const V &val) {
        update(l, r, val, [](T, T, V){}, [](T, T, V){});
    }

    /// @brief 右半開区間 [l, r) を追加または更新する. その際, 発生する差分を add, del 関数で処理する.
    ///        この関数は,新しい区間 [l, r) と既存の区間との重複を適切に処理し,必要に応じて区間の結合,分割,削除を行う.
    /// @param l 左端 (追加または更新する区間の左端)
    /// @param r 右端 (追加または更新する区間の右端)
    /// @param add 追加差分が発生した際の処理 (引数: T left, T right, V value)
    /// @param del 削除差分が発生した場合の処理 (引数: T left, T right, V value)
    template<class ADDFUNC, class DELFUNC>
    void insert(T l, T r, const ADDFUNC &add, const DELFUNC &del) {
        update(l, r, V(), add, del);
    }

    /// @brief 右半開区間 [l, r) を挿入する.
    /// @param l 左端
    /// @param r 右端
    void insert(const T &l, const T &r) {
        update(l, r, V(), [](T, T, V){}, [](T, T, V){});
    }

    /// @brief 右半開区間 [l, r) と重なる既存の区間を削除する.その際,発生する差分を add, del 関数で処理する.
    ///        この関数は,指定された区間 [l, r) と重なる既存の区間を削除し,必要に応じて既存の区間を分割する.
    /// @param l 左端 (削除する区間の左端)
    /// @param r 右端 (削除する区間の右端)
    /// @param add 追加差分が発生した際の処理 (引数: T left, T right, V value) - 分割により一部が残る場合に呼ばれる
    /// @param del 削除差分が発生した場合の処理 (引数: T left, T right, V value)
    template<class ADDFUNC, class DELFUNC>
    void erase(T l, T r, const ADDFUNC &add, const DELFUNC &del) {
        // 削除しようとしている区間 [l, r) の開始点 l 以上で最も近い区間を見つける.
        // これにより,既存の区間との重複チェックを開始する適切な位置を特定する.
        auto it = intervals.lower_bound(Node(l, 0, V()));

        // 新しい区間 [l, r) と重なる可能性のある既存の区間を全て処理する.
        // it->l <= r は,現在の区間 it の左端が削除区間 [l, r) の右端 r 以下であることを示す.
        while (it != intervals.end() && it->l < r) { // it->l < r: 削除区間が現在の区間と重なっている間
            // Case 0: 現在の区間 it の左端 it->l が削除区間の右端 r と一致する場合
            // これ以上右側の区間との重複はないため,ループを抜ける.
            if (it->l == r) { break; }

            // Case 1: 現在の区間 [it->l, it->r) が削除区間 [l, r) に完全に含まれるか,
            // または,削除区間の右端 r で終わる場合 (it->r <= r)
            // この区間は完全に削除される.
            if (it->r <= r) {
                del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                it = intervals.erase(it);
            } else {
                // Case 2: 削除区間 [l, r) が現在の区間 [it->l, it->r) の一部と重なる場合
                // (l <= it->l < r < it->r が確定)
                // 現在の区間は [it->l, r) が削除され,[r, it->r) の部分が残るため,分割される.
                Node node = *it;
                del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                it = intervals.erase(it);
                // 残りの区間 [r, node.r) を挿入する.
                it = intervals.emplace_hint(it, r, node.r, node.val);
                add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
                // これ以上右側の区間との重複はないため,ループを抜ける.
                break;
            }
        }

        // 削除区間 [l, r) の左端 l のすぐ左にある既存の区間をチェックする.
        // これにより,左側の既存区間が削除区間と重なる場合の分割を処理する.
        if (it != intervals.begin()) {
            it = prev(it); // 左側の区間を取得
            if (l < it->r) { // 左側の区間 [it->l, it->r) が削除区間 [l, r) と重なる場合
                // (it->l < l < it->r が確定)
                if (r < it->r) {
                    // 左側の区間 [it->l, it->r) が削除区間 [l, r) を完全に含む場合
                    // [it->l, l) と [r, it->r) の2つの区間に分割される.
                    // まず [r, it->r) を挿入する.
                    it = intervals.emplace_hint(next(it), r, it->r, it->val);
                    add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
                    it = prev(it); // イテレータを元に戻す
                }
                // 左側の区間の元の部分 [it->l, it->r) を削除し,
                // 新しい区間 [node.l, l) を挿入する.
                Node node = *it;
                del_update(del, it->l, it->r, it->val); // 既存区間を削除 (del 関数で差分を通知)
                it = intervals.erase(it);
                it = intervals.emplace_hint(it, node.l, l, node.val);
                add_update(add, it->l, it->r, it->val); // 追加された区間を通知 (add 関数で差分を通知)
            }
        }
    }

    void erase(const T &l, const T &r) {
        erase(l, r, [](T, T, V){}, [](T, T, V){});
    }

    constexpr size_t size() const { return set_size; }
};
