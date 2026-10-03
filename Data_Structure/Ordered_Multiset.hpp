#pragma once

#include "../template/template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T, class I = int>
class Ordered_Multiset {
    using Key = pair<T, I>;
    using order_tree = tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

    order_tree t;
    I id = 0;

    public:
    // コンストラクタ

    Ordered_Multiset(): t(), id(0) {};

    Ordered_Multiset(std::initializer_list<T> init_list) : t(), id(0) {
        for (const auto& x : init_list) insert(x);
    }

    template<class Iterator>
    Ordered_Multiset(Iterator first, Iterator last) : t(), id(0) {
        for (auto it = first; it != last; ++it) insert(*it);
    }

    template<class Container>
    Ordered_Multiset(const Container& container) : t(), id(0) {
        // C++11 の範囲ベース for ループを使い、内部の要素をすべて挿入
        for (const auto& x : container) {
            insert(x);
        }
    }

    // 挿入系メソッド

    /// @brief x を挿入する
    /// @param x 挿入値
    /// @return 変化があれば true というルールだが, 多重集合としているので必ず true になる.
    bool insert(const T& x) {
        t.insert({x, id++});
        return true;
    }

    // 削除系メソッド

    /// @brief x が存在するならば, x を 1 個消す.
    /// @param x 削除値
    /// @return 削除に成功したら `true`.
    bool erase(const T& x) {
        auto it = t.lower_bound({x, -1});
        if (it != t.end() && it->first == x) {
            t.erase(it);
            return true;
        }

        return false;
    }

    /// @brief x を消せるだけ消す.
    /// @param x 削除値
    /// @return 削除した x の個数.
    int discard(const T& x) {
        if (!contains(x)) return 0;

        order_tree tail, more;

        // x 以上を tail に移動
        t.split({x, -1}, tail);

        // x より大きい要素を more に移動. tail には x だけが残る.
        tail.split({x, id}, more);

        // t と more が x ではない要素
        t.join(more);

        return tail.size();;
    }

    /// @brief x が含まれているか?
    /// @param x 判定値
    /// @return x が 1 個以上含まれているならば true.
    bool contains(const T& x) const {
        auto it = t.lower_bound({x, -1});
        return it != t.end() && it->first == x;
    }

    /// @brief この多重集合に含まれている元の個数を求める.
    /// @return 元の個数
    size_t size() const { return t.size(); }

    // カウント系メソッド

    /// @brief x 未満の元の個数を求める.
    /// @param x 基準値
    /// @param equal `true` にすると, 「未満」が「以下」になる.
    /// @return x 未満の元の数
    int count_less(const T& x, bool equal = false) const { // x 未満の元の個数を求める.
        if (equal) return t.order_of_key({x, std::numeric_limits<I>::max()}); // x 以下の個数を求めるために、十分大きな ID を指定
        else return t.order_of_key({x, -1});
    }

    /// @brief x より大きい元の個数を求める.
    /// @param x 基準値
    /// @param equal `true` にすると, 「より大きい」が「以上」になる.
    /// @return x より大きい元の個数
    int count_more(const T& x, bool equal = false) const {
        return size() - count_less(x, !equal);
    }

    /// @brief x の個数 (重複度) を求める
    /// @param x 判定値
    /// @return x の個数 (重複度) を求める.
    int count(const T& x) const {
        return count_less(x, true) - count_less(x, false);
    }

    /// @brief l 以上 r 未満の元の数を求める.
    /// @param l 下限
    /// @param r 上限
    /// @param l_equal 下限の条件に等号を認めるか?
    /// @param r_equal 上限の条件に等号を認めるか?
    /// @return l 以上 r 未満の元の数
    int count_range(const T& l, const T& r, bool l_equal = true, bool r_equal = false) const {
        if (l > r || (l == r && (!l_equal || !r_equal))) return 0;

        int upper = count_less(r, r_equal);
        int lower = count_less(l, !l_equal);
        return std::max(0, upper - lower);
    }

    // インデックス系メソッド

    /// @brief k (0-indexed) 番目の値を求める.
    /// @param k 番号
    /// @return k 番目の値
    T kth(int k) const {
        if (k < 0) k += size();
        return t.find_by_order(k)->first;
    }

    /// @brief k (0-indexed) 番目の値を求める. 範囲外の時は nullopt.
    /// @param k 番号
    /// @return k 番目の値
    optional<T> safe_kth(int k) const {
        if (k < 0) k += size();

        auto it = t.find_by_order(k);
        if (it == t.end()) return nullopt;

        return it->first;
    }

    T operator[](int k) { return kth(k); }
    T operator[](int k) const { return kth(k); }

    T kth_min(int k) const { return kth(k); }
    T kth_max(int k) const { return kth(-(k + 1)); }

    /// @return 最小値
    T min() const { return kth(0); }

    /// @return 最大値
    T max() const { return kth(-1); }

    // 隣接要素系メソッド

    /// @brief x より大きい最小の値を求める.
    /// @param x 基準値
    /// @param equal `true` にすると, 「より大きい」が「以上」になる.
    /// @return x より大きい最小の値
    std::optional<T> next(const T& x, bool equal = false) const {
        return safe_kth(count_less(x, !equal));
    }

    /// @brief x 未満の最大の値を求める.
    /// @param x 基準値
    /// @param equal `true` にすると, 「未満」が「以下」になる.
    /// @return x 以下の最大の値
    std::optional<T> previous(const T& x, bool equal = false) const {
        return safe_kth(count_less(x, equal) - 1);
    }

    // その他

    /// @return 空集合?
    bool empty() const { return t.empty(); }

    /// @brief 初期化
    void clear() { t.clear(); id = 0; }
};
