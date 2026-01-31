#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template <class G, auto add, auto zero, auto neg>
requires Ordered_Group_Concept<G, add, zero, neg>
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
    Best_Sum(int K, const vector<G> &vec) : Best_Sum(K, vec, false) {}
    Best_Sum(int K) : Best_Sum(K, {}, false) {}

    void insert(G x) {
        if (reversal) x = neg(x);
        more_insert(x);
        validation();
    }

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

    void change(G from, G to) {
        discard(from);
        insert(to);
    }

    G best_sum() const { return more_sum; }

    G all_sum() const {
        G total = add(more_sum, less_sum);
        return reversal ? neg(total) : total;
    }

    void change_K(int new_K) {
        K = max(0, new_K);
        validation();
    }

    bool contains(G x) const {
        return more.find(x) != more.end() || less.find(x) != less.end();
    }

    inline int size() const { return more.size() + less.size(); }
};

template <class G, auto add, auto zero, auto neg>
requires Ordered_Group_Concept<G, add, zero, neg>
class Worst_Sum : public Best_Sum<G, add, zero, neg> {
    public:
    Worst_Sum(int K, const vector<G> &vec) : Best_Sum<G, add, zero, neg>(K, vec, true) {}
    Worst_Sum(int K) : Best_Sum<G, add, zero, neg>(K, {}, true) {}

    G worst_sum() const { return neg(this->more_sum); }

    private:
    using Best_Sum<G, add, zero, neg>::best_sum;
};
