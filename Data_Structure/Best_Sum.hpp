#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template <class G, auto add, auto zero, auto neg>
requires Totally_Ordered_Group_Concept<G, add, zero, neg>
class Best_Sum {
    protected:
    G more_sum, less_sum;
    multiset<G> more, less;

    int K;
    bool reversal;

    G sub(G x, G y) const { return add(x, neg(y)); }

    void more_insert(G x) {
        more_sum = add(more_sum, x);
        more.insert(x);
    }

    void less_insert(G x) {
        less_sum = add(less_sum, x);
        less.insert(x);
    }

    void more_to_less() {
        auto node = more.extract(more.begin());
        G x = node.value();
        more_sum = sub(more_sum, x);
        less_sum = add(less_sum, x);
        less.insert(std::move(node));
    }

    void less_to_more() {
        auto node = less.extract(prev(less.end()));
        G x = node.value();
        less_sum = sub(less_sum, x);
        more_sum = add(more_sum, x);
        more.insert(std::move(node));
    }

    void validation() {
        while ((int)more.size() > K) more_to_less();
        while (!less.empty() && (int)more.size() < K) less_to_more();
    }

    protected:
    Best_Sum(int K, const vector<G> &vec, bool reversal) : K(max(0, K)), reversal(reversal), more_sum(zero), less_sum(zero) {
        for (const auto &x : vec) insert(x);
    }

    public:
    /// @brief コンストラクタ.
    /// @param K 上位 K 個の和を管理する.
    /// @param vec 初期データ.
    Best_Sum(int K, const vector<G> &vec) : Best_Sum(K, vec, false) {}

    /// @brief コンストラクタ.
    /// @param K 上位 K 個の和を管理する.
    Best_Sum(int K) : Best_Sum(K, {}, false) {}

    /// @brief 要素 x を追加する.
    /// @param x 追加する要素.
    void insert(G x) {
        if (reversal) x = neg(x);
        more_insert(x);
        validation();
    }

    /// @brief 要素 x を 1 つ削除する.
    /// @param x 削除する要素.
    void discard(G x) {
        if (reversal) x = neg(x);
        
        auto it = more.find(x);
        if (it != more.end()) {
            more_sum = sub(more_sum, x);
            more.erase(it);
        } else {
            it = less.find(x);
            if (it == less.end()) return;

            less_sum = sub(less_sum, x);
            less.erase(it);
        }
        validation();
    }

    /// @brief 要素 from を削除し, to を追加する.
    /// @param from 削除する要素.
    /// @param to 追加する要素.
    void change(G from, G to) {
        discard(from);
        insert(to);
    }

    /// @brief 上位 K 個の和を取得する.
    /// @return 上位 K 個の和.
    G best_sum() const { return more_sum; }

    /// @brief 全要素の和を取得する.
    /// @return 全要素の和.
    G all_sum() const {
        G total = add(more_sum, less_sum);
        return reversal ? neg(total) : total;
    }

    /// @brief 管理する個数 K を変更する.
    /// @param new_K 新しい K.
    void change_K(int new_K) {
        K = max(0, new_K);
        validation();
    }

    /// @brief 要素 x が含まれているか判定する.
    /// @param x 判定する要素.
    /// @return 含まれているなら true, そうでないなら false.
    bool contains(G x) const {
        return more.find(x) != more.end() || less.find(x) != less.end();
    }

    /// @brief 管理している要素数を取得する.
    /// @return 要素数.
    inline int size() const { return more.size() + less.size(); }
};

template <class G, auto add, auto zero, auto neg>
requires Totally_Ordered_Group_Concept<G, add, zero, neg>
class Worst_Sum : public Best_Sum<G, add, zero, neg> {
    public:
    /// @brief コンストラクタ.
    /// @param K 下位 K 個の和を管理する.
    /// @param vec 初期データ.
    Worst_Sum(int K, const vector<G> &vec) : Best_Sum<G, add, zero, neg>(K, vec, true) {}

    /// @brief コンストラクタ.
    /// @param K 下位 K 個の和を管理する.
    Worst_Sum(int K) : Best_Sum<G, add, zero, neg>(K, {}, true) {}

    /// @brief 下位 K 個の和を取得する.
    /// @return 下位 K 個の和.
    G worst_sum() const { return neg(this->more_sum); }

    private:
    using Best_Sum<G, add, zero, neg>::best_sum;
};
