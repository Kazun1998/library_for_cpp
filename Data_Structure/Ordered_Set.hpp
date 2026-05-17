#pragma once

#include "../template/template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
class Ordered_Set {
    typedef tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> order_tree;

    order_tree t;

    public:
    Ordered_Set(): t() {};

    Ordered_Set(std::initializer_list<T> init_list) : t() {
        for (const auto& x : init_list) insert(x);
    }

    template<class InputIterator>
    Ordered_Set(InputIterator first, InputIterator last) : t() {
        for (auto it = first; it != last; ++it) insert(*it);
    }

    template<class Container>
    Ordered_Set(const Container& container) : t() {
        // C++11 の範囲ベース for ループを使い、内部の要素をすべて挿入
        for (const auto& x : container) {
            insert(x);
        }
    }

    bool insert(const T x) {
        auto result = t.insert(x);
        return result.second;
    }

    bool erase(const T x) {
        auto it = t.find(x);
        if (it == t.end()) return false;

        t.erase(it);
        return true;
    }

    bool contains(const T x) const { return t.find(x) != t.end(); }

    size_t size() const { return t.size(); }

    int count_less(const T x, bool equal = false) const {
        int k = t.order_of_key(x);
        if (equal && contains(x)) k++;

        return k;
    }

    int count_more(const T x, bool equal = false) const {
        return size() - count_less(x, !equal);
    }

    int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {
        // 範囲が空だったら明らかに 0
        if (l > r || (l == r && (!l_equal || !r_equal))) return 0;

        // 「r 以下の個数」から「l 未満の個数」を引くことで範囲内を切り出す
        int upper = count_less(r, r_equal);
        int lower = count_less(l, !l_equal);

        return std::max(0, upper - lower);
    }

    T kth(int k) const {
        if (k < 0) k += size();

        return *t.find_by_order(k);
    }

    optional<T> safe_kth(int k) const {
        if (k < 0) k += size();

        auto it = t.find_by_order(k);
        if (it == t.end()) return nullopt;

        return *it;
    }

    T operator[](int k) { return kth(k); }
    T operator[](int k) const { return kth(k); }

    T kth_min(int k) const { return kth(k); }
    T kth_max(int k) const { return kth(-(k + 1)); }

    T min() const { return kth(0); }
    T max() const { return kth(-1); }

    std::optional<T> next(const T x, bool equal = false) const {
        return safe_kth(count_less(x, !equal));
    }

    std::optional<T> previous(const T x, bool equal = false) const {
        int rank = count_less(x, equal) - 1;
        if (rank < 0) return std::nullopt;
        return safe_kth(rank);
    }

    bool empty() const { return t.empty(); }
    void clear() { t.clear(); }

    auto begin() const { return t.begin(); }
    auto end() const { return t.end(); }
};
