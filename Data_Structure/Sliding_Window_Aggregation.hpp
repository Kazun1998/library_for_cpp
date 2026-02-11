#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template <typename M, auto op, auto identity>
requires Monoid_Concept<M, op, identity>
class Sliding_Window_Aggregation {
    private:
    vector<M> left_value, left_prod;
    vector<M> right_value, right_prod;

    // 片方のスタックが空になった際、もう片方の半分を移し替える処理 (ならし O(1))
    void rebalance_from_right() {
        size_t total = right_value.size();
        size_t rm = total / 2;
        size_t lm = total - rm;

        vector<M> tmp;
        for (size_t i = 0; i < rm; ++i) {
            tmp.push_back(right_value.back());
            right_value.pop_back();
        }
        right_prod.clear();

        for (size_t i = 0; i < lm; ++i) {
            M y = right_value.back();
            right_value.pop_back();
            push_front(y);
        }

        reverse(tmp.begin(), tmp.end());
        for (const auto& v : tmp) {
            push_back(v);
        }
    }

    void rebalance_from_left() {
        size_t total = left_value.size();
        size_t lm = total / 2;
        size_t rm = total - lm;

        vector<M> tmp;
        for (size_t i = 0; i < lm; ++i) {
            tmp.push_back(left_value.back());
            left_value.pop_back();
        }
        left_prod.clear();

        for (size_t i = 0; i < rm; ++i) {
            M y = left_value.back();
            left_value.pop_back();
            push_back(y);
        }

        reverse(tmp.begin(), tmp.end());
        for (const auto& v : tmp) {
            push_front(v);
        }
    }

    public:
    Sliding_Window_Aggregation(): left_value(), left_prod(), right_value(), right_prod() {}

    inline size_t size() const { return left_value.size() + right_value.size(); }

    inline bool empty() const { return size() == 0; }

    void push_front(M x) {
        left_value.push_back(x);
        if (left_prod.empty()) {
            left_prod.push_back(x);
        } else {
            // 左側への追加は (新要素 op 既存積)
            left_prod.push_back(op(x, left_prod.back()));
        }
    }

    void push_back(M x) {
        right_value.push_back(x);
        if (right_prod.empty()) {
            right_prod.push_back(x);
        } else {
            // 右側への追加は (既存積 op 新要素)
            right_prod.push_back(op(right_prod.back(), x));
        }
    }

    void pop_front() {
        if (left_value.empty()) {
            if (right_value.empty()) return;
            rebalance_from_right();
        }
        left_value.pop_back();
        left_prod.pop_back();
    }

    void pop_back() {
        if (right_value.empty()) {
            if (left_value.empty()) return;
            rebalance_from_left();
        }
        right_value.pop_back();
        right_prod.pop_back();
    }

    // 全体の積を O(1) で取得
    M product() const {
        if (left_prod.empty() && right_prod.empty()) return identity;
        if (left_prod.empty()) return right_prod.back();
        if (right_prod.empty()) return left_prod.back();
        return op(left_prod.back(), right_prod.back());
    }

    void clear() {
        left_value.clear();
        left_prod.clear();
        right_value.clear();
        right_prod.clear();
    }
};