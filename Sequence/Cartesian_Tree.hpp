#pragma once

#include"../template/template.hpp"

template<typename O>
class Cartesian_Tree {
    public:
    bool reversal;
    int root;
    vector<int> left, right, parent;

    Cartesian_Tree() = default;
    Cartesian_Tree(const vector<O> &data, bool reversal = false): left(data.size(), -1), right(data.size(), -1), parent(data.size(), -1), root(-1), reversal(reversal) {
        build_up(data);
    }

    inline bool is_root(const int i) const { return root == i; }

    private:
    /// @brief i の左の子として j を設定する
    /// @param i 親
    /// @param j 左の子
    void set_left(const int i, const int j) {
        left[i] = j;
        parent[j] = i;
    }

    /// @brief i の右の子として j を設定する
    /// @param i 親
    /// @param j 右の子
    void set_right(const int i, const int j) {
        right[i] = j;
        parent[j] = i;
    }

    /// @brief 頂点 i を根に設定する
    /// @param i 根
    void set_root(const int i) {
        root = i;
    }

    bool should_pop(const vector<O> &data, const int x, const int y) {
        if (reversal) { return data[x] <= data[y]; }
        else { return data[x] >= data[y]; }
    }

    void build_up(const vector<O> &data) {
        vector<int> stack;

        for (int i = 0; i < data.size(); i++) {
            if (i == 0) {
                stack.emplace_back(0);
                set_root(0);
                continue;
            }

            int last_pop = -1;
            while (!stack.empty() && should_pop(data, stack.back(), i)) {
                last_pop = stack.back();
                stack.pop_back();
            }

            // 左の子に関する設定
            if (last_pop != -1) {
                set_left(i, last_pop);
            }

            if (stack.empty()) {
                set_root(i);
            } else {
                set_right(stack.back(), i);
            }

            stack.emplace_back(i);
        }
    }
};