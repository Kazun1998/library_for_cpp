#pragma once

#include"../template/template.hpp"
#include"../template/concepts.hpp"

template<class G, auto op, auto identity, auto inv>
requires Group_Concept<G, op, identity, inv>
class Interval_Product {
    vector<G> prefix_prod;

    public:
    explicit Interval_Product(const vector<G> &data) {
        prefix_prod.reserve(data.size() + 1);

        // 累積和は exclusive でとる. つまり, prefix_prod[i] = data[0] * data[1] * ... * data[i - 1] になる.
        prefix_prod.push_back(identity);
        for (const G &x : data) {
            prefix_prod.push_back(op(prefix_prod.back(), x));
        }
    }

    /// @brief 閉区間 [0, r] における累積
    /// @param r 区間の右端
    /// @return 
    inline G query(const int r) const { return prefix_prod[r + 1]; }

    /// @brief 閉区間 [l, r] における累積
    /// @param l 区間の左端
    /// @param r 区間の右端
    inline G query(int l, int r) const {
        if (l == 0) return query(r);
        return op(inv(query(l - 1)), query(r));
    }
};
