#pragma once

#include"../template/template.hpp"

template<typename O>
class Dual_Heap {
    private:
    std::priority_queue<O, std::vector<O>, std::greater<O>> small;
    std::priority_queue<O, std::vector<O>, std::less<O>> large;
    std::unordered_map<O, int> count_map;
    int _size;

    public:
    Dual_Heap(const std::vector<O> &data) : _size(data.size()) {
        for (const O &a: data) { count_map[a]++; }

        for (auto const& [a, ignore]: count_map) {
            small.emplace(a);
            large.emplace(a);
        }
    }

    Dual_Heap(): Dual_Heap({}) {};

    void push(const O &x) {
        _size++;

        auto [it, inserted] = count_map.try_emplace(x, 1);

        if (inserted) {
            small.emplace(x);
            large.emplace(x);
        } else {
            it->second++;
        }
    }

    bool discard(const O &x) {
        if(!contains(x)) { return false; }

        count_map[x]--;
        _size--;

        if(count_map[x] == 0) { count_map.erase(x); }

        while (!small.empty() && !contains(small.top())) { small.pop(); }
        while (!large.empty() && !contains(large.top())) { large.pop(); }

        return true;
    }

    O get_min() const {
        if (empty()) { throw std::out_of_range("Dual_Heap is empty."); }
        return small.top();
    }

    O get_max() const {
        if (empty()) { throw std::out_of_range("Dual_Heap is empty."); }
        return large.top();
    }

    O pop_min() {
        if (empty()) { throw std::out_of_range("Dual_Heap is empty."); }
        O x = get_min();
        discard(x);
        return x;
    }

    O pop_max() {
        if (empty()) { throw std::out_of_range("Dual_Heap is empty."); }
        O x = get_max();
        discard(x);
        return x;
    }

    inline bool contains(const O &x) const { return count(x) > 0; }

    inline int count(const O &x) const {
        auto it = count_map.find(x);
        return (it != count_map.end()) ? it -> second : 0;
    }

    inline int size() const { return _size; }

    inline bool empty() const { return _size == 0; }
};
