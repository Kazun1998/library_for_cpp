#pragma once

#include "../template/template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
class Ordered_Set {
    typedef tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> order_tree;

    order_tree t;

    public:
    Ordered_Set(): t() {};
};
