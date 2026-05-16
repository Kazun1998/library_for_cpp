#pragma once

#include "Tree.hpp"
#include "../Algebra/dynamic_modint.hpp"

vector<int> Subtree_Isomorphism_Hash(const Tree &T, const vector<ll>& primes) {
    using mint = dynamic_modint<1>;

    const int node_count = T.order();
    const int vector_size = T.vector_size();
    const int offset = T.offset();

    vector<vector<int>> combined_ids(vector_size);
    for (int i = offset; i < vector_size; ++i) {
        combined_ids[i].reserve(primes.size());
    }

    // 乱数生成器は一度だけ初期化
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

    auto compress_vals = [&](const auto& vals_to_compress) -> vector<int> {
        using T_val = typename std::decay<decltype(vals_to_compress[offset])>::type;
        vector<T_val> vals;
        vals.reserve(node_count);
        for (int i = offset; i < vector_size; ++i) vals.push_back(vals_to_compress[i]);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<int> res(vector_size, -1);
        for (int i = offset; i < vector_size; ++i) {
            res[i] = lower_bound(vals.begin(), vals.end(), vals_to_compress[i]) - vals.begin();
        }
        return res;
    };

    auto generate_seeds = [&](int count, ll prime) {
        vector<mint> seeds(count + 1);
        for (int d = 0; d <= count; ++d) {
            seeds[d] = mint(static_cast<long long>(gen() % prime));
        }
        return seeds;
    };

    vector<int> height(vector_size, 0);
    for (int x : T.bottom_up()) {
        for (int y : T.get_children(x)) {
            if (height[x] < height[y] + 1) height[x] = height[y] + 1;
        }
    }

    auto calculate_ranks = [&](ll prime) {
        mint::set_mod(prime);
        vector<mint> hash(vector_size, mint(1));

        auto seeds = generate_seeds(node_count, prime);

        for (int x: T.bottom_up()) {
            mint a = seeds[height[x]];
            for (auto y : T.get_children(x)) {
                hash[x] = hash[x] * (a + hash[y]);
            }
        }

        vector<uint64_t> hash_raw(vector_size);
        for (int i = offset; i < vector_size; ++i) hash_raw[i] = hash[i].x;
        return compress_vals(hash_raw);
    };

    for (ll prime : primes) {
        auto ranks = calculate_ranks(prime);
        for (int i = offset; i < vector_size; i++) {
            combined_ids[i].push_back(ranks[i]);
        }
    }

    // すべてのプライムでの ID を統合して座標圧縮
    return compress_vals(combined_ids);
}
