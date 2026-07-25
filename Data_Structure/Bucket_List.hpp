#pragma once

#include "../template/template.hpp"

// Thanks to: https://github.com/tatyam-prime/SortedSet/blob/main/BucketList.py

template<typename T>
class Bucket_List {
    using Bucket = vector<T>;

    template<bool IsConst>
    class Iterator {
        using BucketsIt = conditional_t<IsConst, typename vector<Bucket>::const_iterator, typename vector<Bucket>::iterator>;
        using ElemIt = conditional_t<IsConst, typename Bucket::const_iterator, typename Bucket::iterator>;

        BucketsIt bkt, bkt_end;
        ElemIt elem;

        void skip_empty() {
            while (bkt != bkt_end && elem == bkt->end()) {
                ++bkt;
                if (bkt != bkt_end) elem = bkt->begin();
            }
        }

        public:
        Iterator(BucketsIt bkt_, BucketsIt bkt_end_): bkt(bkt_), bkt_end(bkt_end_) {
            if (bkt != bkt_end) elem = bkt->begin();
            skip_empty();
        }

        conditional_t<IsConst, const T&, T&> operator*() const { return *elem; }

        Iterator& operator++() {
            ++elem;
            skip_empty();
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            if (bkt != other.bkt) return true;
            return bkt != bkt_end && elem != other.elem;
        }

        bool operator==(const Iterator &other) const { return !(*this != other); }
    };

    public:
    using iterator = Iterator<false>;
    using const_iterator = Iterator<true>;

    iterator begin() { return iterator(buckets.begin(), buckets.end()); }
    iterator end() { return iterator(buckets.end(), buckets.end()); }

    const_iterator begin() const { return const_iterator(buckets.begin(), buckets.end()); }
    const_iterator end() const { return const_iterator(buckets.end(), buckets.end()); }

    private:
    static constexpr double BUCKET_RATIO = 16.0;
    static constexpr double SPLIT_RATIO = 24.0;

    int _size;
    vector<Bucket> buckets;

    tuple<const Bucket&, int, int> position(int k) const {
        if (k < 0 || k >= size()) {
            throw out_of_range("Bucket_List::position");
        }

        if (k < size() - k) {
            for (int i = 0; i < (int)buckets.size(); ++i) {
                const Bucket &bucket = buckets[i];

                if (k < (int)bucket.size()) {
                    return {bucket, i, k};
                }

                k -= bucket.size();
            }
        } else {
            k = size() - k - 1;

            for (int i = (int)buckets.size() - 1; i >= 0; --i) {
                const Bucket &bucket = buckets[i];

                if (k < (int)bucket.size()) {
                    return {bucket, i, (int)bucket.size() - 1 - k};
                }

                k -= bucket.size();
            }
        }

        throw out_of_range("Bucket_List::position");
    }

    tuple<Bucket&, int, int> position(int k) {
        auto [bucket, i, j] = const_cast<const Bucket_List*>(this)->position(k);
        return {const_cast<Bucket&>(bucket), i, j};
    }

    Bucket& locate(int k, int &bucket_index, int &index) {
        auto pos = position(k);
        tie(ignore, bucket_index, index) = pos;

        return get<0>(pos);
    }

    void _insert(Bucket &bucket, int bucket_index, int index, T a) {
        bucket.insert(bucket.begin() + index, a);
        _size++;

        if (bucket.size() > buckets.size() * SPLIT_RATIO) {
            int mid = bucket.size() >> 1;

            Bucket left(bucket.begin(), bucket.begin() + mid);
            Bucket right(bucket.begin() + mid, bucket.end());

            buckets[bucket_index] = std::move(left);
            buckets.insert(buckets.begin() + bucket_index + 1, std::move(right));
        }
    }

    T _pop(Bucket &bucket, int bucket_index, int index) {
        T val = bucket[index];
        bucket.erase(bucket.begin() + index);
        _size--;

        if (bucket.empty()) {
            buckets.erase(buckets.begin() + bucket_index);
        }

        if ((int)buckets.size() > 2 * ideal_bucket_count()) {
            rebuild();
        }

        return val;
    }

    void make_first(const T a) {
        buckets = {{a}};
        _size = 1;
    }

    int ideal_bucket_count() const {
        if (_size == 0) return 0;
        return max(1, (int)ceil(sqrt(_size / BUCKET_RATIO)));
    }

    void rebuild() {
        vector<T> data;
        data.reserve(_size);
        for (const Bucket &bucket : buckets) {
            data.insert(data.end(), bucket.begin(), bucket.end());
        }

        int n = data.size();
        int num_bucket = ideal_bucket_count();

        buckets.assign(num_bucket, Bucket());
        for (int i = 0; i < num_bucket; i++) {
            int l = (long long)n * i / num_bucket;
            int r = (long long)n * (i + 1) / num_bucket;

            buckets[i] = Bucket(data.begin() + l, data.begin() + r);
        }
    }

    public:
    Bucket_List(): Bucket_List(vector<T>{}) {}

    Bucket_List(const vector<T> &data) {
        _size = data.size();
        buckets = {Bucket(data.begin(), data.end())};

        rebuild();
    }

    /// @brief 第 k 要素となる位置に a を挿入する
    /// @param k 挿入する場所
    /// @param a 挿入する要素
    void insert(int k, const T a) {
        if (empty()) {
            if (k != 0) {
                throw out_of_range("Bucket_List::insert");
            }

            return make_first(a);
        }

        if (k < 0) k += size();

        if (k == size()) return append(a);

        int i, j;
        Bucket &bucket = locate(k, i, j);

        _insert(bucket, i, j, a);
    }

    /// @brief 末尾に a を追加する
    /// @param a 追加する要素
    void append(const T a) {
        if (empty()) return make_first(a);

        auto &bucket = buckets.back();
        _insert(bucket, buckets.size() - 1, bucket.size(), a);
    }

    /// @brief 末尾に a を追加する (append の別名)
    /// @param a 追加する要素
    void push_back(const T a) { append(a); }

    /// @brief 先頭に a を追加する
    /// @param a 追加する要素
    void push_front(const T a) { insert(0, a); }

    /// @brief 末尾に data の要素をすべて追加する
    /// @param data 追加する要素列
    void extend(const vector<T> &data) {
        for (const T &a : data) {
            append(a);
        }
    }

    /// @brief 第 k 要素を削除し、その値を返す
    /// @param k 削除する場所 (負の場合は末尾から数える。省略時は末尾)
    /// @return 削除された要素
    T pop(int k = -1) {
        if (k < 0) k += size();

        int i, j;
        Bucket &bucket = locate(k, i, j);

        return _pop(bucket, i, j);
    }

    /// @brief 末尾の要素を削除し、その値を返す (pop の別名)
    /// @return 削除された要素
    T pop_back() { return pop(); }

    /// @brief 先頭の要素を削除し、その値を返す
    /// @return 削除された要素
    T pop_front() { return pop(0); }

    T operator[](int k) const {
        if (k < 0) k += size();

        auto [bucket, i, j] = position(k);
        return bucket[j];
    }

    /// @brief 先頭の要素を取得する
    /// @return 先頭の要素
    T first() const {
        if (empty()) throw out_of_range("Bucket_List::first");

        return buckets.front().front();
    }

    /// @brief 末尾の要素を取得する
    /// @return 末尾の要素
    T last() const {
        if (empty()) throw out_of_range("Bucket_List::last");

        return buckets.back().back();
    }

    /// @brief a と一致する要素の個数を数える
    /// @param a 数える値
    /// @return a と一致する要素の個数
    int count(const T a) const {
        int res = 0;
        for (const Bucket &bucket : buckets) {
            res += std::count(bucket.begin(), bucket.end(), a);
        }

        return res;
    }

    /// @brief a が含まれるかどうかを判定する
    /// @param a 探す値
    /// @return 含まれるならば true
    bool contains(const T a) const {
        return count(a) > 0;
    }

    /// @brief a が初めて現れる要素を1つ削除する
    /// @param a 削除する値
    /// @return 削除できたら true
    bool erase(const T a) {
        for (int i = 0; i < (int)buckets.size(); ++i) {
            Bucket &bucket = buckets[i];
            auto it = std::find(bucket.begin(), bucket.end(), a);

            if (it == bucket.end()) continue;

            _pop(bucket, i, it - bucket.begin());
            return true;
        }

        return false;
    }

    /// @brief a が初めて現れる位置を求める
    /// @param a 探す値
    /// @return a が初めて現れる位置
    int index(const T a) const {
        int offset = 0;
        for (const Bucket &bucket : buckets) {
            auto it = std::find(bucket.begin(), bucket.end(), a);
            if (it != bucket.end()) {
                return offset + (it - bucket.begin());
            }

            offset += bucket.size();
        }

        throw invalid_argument("Bucket_List::index");
    }

    /// @brief 長さを取得する
    /// @return 長さ
    int size() const { return _size; }

    /// @brief 空かどうかを判定する
    /// @return 空ならば true
    bool empty() const { return _size == 0; }

    /// @brief すべての要素を削除する
    void clear() {
        buckets.clear();
        _size = 0;
    }

    /// @brief 要素の順序を反転する
    void reverse() {
        std::reverse(buckets.begin(), buckets.end());
        for (Bucket &bucket : buckets) {
            std::reverse(bucket.begin(), bucket.end());
        }
    }
};
