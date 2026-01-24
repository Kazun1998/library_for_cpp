#pragma once

#include "../template/template.hpp"

class Mo {
    private:
    int N;
    int query_count;
    vector<int> left, right;

    public:
    Mo(const int N): N(N), query_count(0), left(0), right(0) {}

    /// @brief 閉区間 [l, r] に関するクエリを追加する
    /// @param l 左端
    /// @param r 右端
    void add_query(const int l, const int r) {
        left.emplace_back(l);
        right.emplace_back(r + 1);
        query_count++;
    }

    template<typename ADD, typename DEL, typename REM>
    void run(const ADD &add, const DEL &del, const REM &rem) {
        int bucket_size = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(query_count * 2.0 / 3.0)));
        int bucket_count = div_ceil(N, bucket_size);
        vector<vector<int>> buckets(bucket_count, vector<int>(0));

        for (int q = 0; q < query_count; q++) {
            int bucket_id = div_floor(left[q], bucket_size);
            buckets[bucket_id].emplace_back(q);
        }

        int l = 0, r = 0;
        for (int bucket_id = 0; bucket_id < bucket_count; bucket_id++) {
            auto &bucket = buckets[bucket_id];
            if (bucket_id % 2 == 0) {
                sort(bucket.begin(), bucket.end(), [&](const int p, const int q) -> bool { return right[p] < right[q]; });
            } else {
                sort(bucket.rbegin(), bucket.rend(), [&](const int p, const int q) -> bool { return right[p] < right[q]; });
            }

            for (const int q: bucket) {
                while (left[q] < l) add(--l);
                while (r < right[q]) add(r++);

                while(l < left[q]) del(l++);
                while(right[q] < r) del(--r);

                rem(q);
            }
        }
    }
};
