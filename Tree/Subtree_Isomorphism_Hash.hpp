#pragma once

#include "Tree.hpp"
#include "../Algebra/dynamic_modint.hpp"

vector<int> Subtree_Isomorphism_Hash(Tree &T, ll prime) {
    using mint = dynamic_modint<1>;
    auto calculate = [&](ll p) -> vector<mint> {
        mint::set_mod(p);

        vector<mint> hash(T.order() + T.offset(), mint(1));
        vector<int> height(T.order() + T.offset(), 0);

        vector<mint> seeds(T.order() + 1);
        static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
        for (int d = 0; d <= T.order(); ++d) {
            seeds[d] = mint(gen());
        }

        for (auto x: T.bottom_up()) {
            for (auto y: T.get_children(x)) {
                chmax(height[x], height[y] + 1);
            }

            mint a = seeds[height[x]];
            for (auto y: T.get_children(x)) {
                hash[x] = hash[x] * (a + hash[y]);
            }
        }

        return hash;
    };

    auto hash = calculate(prime);
    vector<ll> vals;
    vals.reserve(T.order());
    for (int i = T.offset(); i < T.vector_size(); i++) {
        vals.push_back(hash[i].x);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> res(T.vector_size(), -1);
    for (int i = T.offset(); i < T.vector_size(); i++) {
        res[i] = lower_bound(vals.begin(), vals.end(), hash[i].x) - vals.begin();
    }
    return res;
}
