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
};
