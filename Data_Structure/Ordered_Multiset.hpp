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

    bool insert(const T x) {
        t.insert({x, id++});
        return true;
    }

    bool erase(const T x) {
        auto it = t.lower_bound({x, -1});
        if (it != t.end() && it->first == x) {
            t.erase(it);
            return true;
        }

        return false;
    }

    bool contains(const T x) const {
        auto it = t.lower_bound({x, -1});
        return it != t.end() && it->first == x;
    }

    size_t size() const { return t.size(); }

    int count_less(const T x, bool equal = false) const {
        if (equal) return t.order_of_key({x, id});
        else return t.order_of_key({x, -1});
    }

    int count_more(const T x, bool equal = false) const {
        return size() - count_less(x, !equal);
    }

    int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {
        if (l > r || (l == r && (!l_equal || !r_equal))) return 0;

        int upper = count_less(r, r_equal);
        int lower = count_less(l, !l_equal);
        return std::max(0, upper - lower);
    }

    T kth(int k) const {
        if (k < 0) k += size();
        return t.find_by_order(k)->first;
    }

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

    T min() const { return kth(0); }
    T max() const { return kth(-1); }

    std::optional<T> next(const T x, bool equal = false) const {
        return safe_kth(count_less(x, !equal));
    }

    std::optional<T> previous(const T x, bool equal = false) const {
        return safe_kth(count_less(x, equal) - 1);
    }

    bool empty() const { return t.empty(); }
    void clear() { t.clear(); id = 0; }
};
