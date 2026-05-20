#pragma once

#include "../template/template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
class Ordered_Multiset {
    using Key = pair<T, int>;
    typedef tree<Key, null_type, less<Key>, rb_tree_tag, tree_order_statistics_node_update> order_tree;

    order_tree t;
    int id = 0;

    public:
    Ordered_Set(): t(), id(0) {};

    Ordered_Set(std::initializer_list<T> init_list) : t(), id(0) {
        for (const auto& x : init_list) insert(x);
    }

    template<class Iterator>
    Ordered_Set(Iterator first, Iterator last) : t(), id(0) {
        for (auto it = first; it != last; ++it) insert(*it);
    }

    template<class Container>
    Ordered_Set(const Container& container) : t(), id(0) {
        // C++11 の範囲ベース for ループを使い、内部の要素をすべて挿入
        for (const auto& x : container) {
            insert(x);
        }
    }

    bool insert(const T x) {}

    bool erase(const T x) {}

    bool contains(const T x) const {}

    size_t size() const {}

    int count_less(const T x, bool equal = false) const {}

    int count_more(const T x, bool equal = false) const {}

    int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {}

    T kth(int k) const {}

    optional<T> safe_kth(int k) const {}

    T operator[](int k) { return kth(k); }
    T operator[](int k) const { return kth(k); }

    T kth_min(int k) const { return kth(k); }
    T kth_max(int k) const { return kth(-(k + 1)); }

    T min() const { return kth(0); }
    T max() const { return kth(-1); }

    std::optional<T> next(const T x, bool equal = false) const {}

    std::optional<T> previous(const T x, bool equal = false) const {}

    bool empty() const { return t.empty(); }
    void clear() { t.clear(); }
};
