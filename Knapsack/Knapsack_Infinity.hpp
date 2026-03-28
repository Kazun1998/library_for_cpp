#pragma once

#include"Base.hpp"

namespace knapsack_problem {
    template<copyable I, integral V, integral W, integral Q>
    class Knapsack_Infinity {
        using ItemList = vector<Item<I, V, W>>;
    };
}
