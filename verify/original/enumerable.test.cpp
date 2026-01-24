#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../template/template.hpp"
#include"../../template/enumerable.hpp"

void verify() {
    // collect
    {
        vector<int> v = {1, 2, 3};
        auto res = enumerable::collect(v, [](int x) { return x * x; });
        assert(res == vector<int>({1, 4, 9}));
    }

    // select
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};
        auto res = enumerable::select(v, [](int x) { return x % 2 == 0; });
        assert(res == vector<int>({2, 4, 6}));
    }

    // reject
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};
        auto res = enumerable::reject(v, [](int x) { return x % 2 == 0; });
        assert(res == vector<int>({1, 3, 5}));
    }

    // inject
    {
        vector<int> v = {1, 2, 3, 4};
        assert(enumerable::inject(v, 0, [](int acc, int x) { return acc + x; }) == 10);
        assert(enumerable::inject(v, 100, [](int acc, int x) { return acc + x; }) == 110);
        assert(enumerable::inject(v, [](int acc, int x) { return acc + x; }) == 10);
    }

    // all_of, any_of, none_of
    {
        vector<int> v = {2, 4, 6};
        assert(enumerable::all_of(v, [](int x) { return x % 2 == 0; }));
        assert(!enumerable::all_of(v, [](int x) { return x == 4; }));
        assert(enumerable::any_of(v, [](int x) { return x == 4; }));
        assert(!enumerable::any_of(v, [](int x) { return x == 5; }));
        assert(enumerable::none_of(v, [](int x) { return x % 2 != 0; }));
        assert(!enumerable::none_of(v, [](int x) { return x == 4; }));
    }

    // include
    {
        vector<int> v = {1, 2, 3};
        assert(enumerable::include(v, 2));
        assert(!enumerable::include(v, 4));
    }

    // find
    {
        vector<int> v = {1, 3, 4, 5};
        auto res = enumerable::find(v, [](int x) { return x % 2 == 0; });
        assert(res.has_value() && res.value() == 4);
        assert(!enumerable::find(v, [](int x) { return x > 10; }).has_value());
    }

    // find_index
    {
        vector<int> v = {1, 3, 4, 5};
        auto res = enumerable::find_index(v, [](int x) { return x % 2 == 0; });
        assert(res.has_value() && res.value() == 2);
        assert(!enumerable::find_index(v, [](int x) { return x > 10; }).has_value());
    }

    // count
    {
        vector<int> v = {1, 2, 3, 2};
        assert(enumerable::count(v, [](int x) { return x == 2; }) == 2);
    }

    // partition
    {
        vector<int> v = {1, 2, 3, 4, 5, 6};
        auto [evens, odds] = enumerable::partition(v, [](int x) { return x % 2 == 0; });
        assert(evens == vector<int>({2, 4, 6}));
        assert(odds == vector<int>({1, 3, 5}));
    }

    // group_by
    {
        vector<string> v = {"apple", "banana", "cherry", "date"};
        auto res = enumerable::group_by(v, [](const string& s) { return s.length(); });
        assert(res[4] == vector<string>({"date"}));
        assert(res[5] == vector<string>({"apple"}));
        assert(res[6] == vector<string>({"banana", "cherry"}));
    }

    // sort_by
    {
        vector<string> v = {"long", "s", "medium"};
        auto res = enumerable::sort_by(v, [](const string& s) { return s.length(); });
        assert(res == vector<string>({"s", "long", "medium"}));
    }

    // uniq
    {
        vector<int> v = {1, 2, 3, 2, 4, 1, 5};
        auto res = enumerable::uniq(v);
        assert(res == vector<int>({1, 2, 3, 4, 5}));
    }
    {
        vector<int> v = {5, 1, 4, 2, 3, 5, 1};
        auto res = enumerable::uniq(v);
        assert(res == vector<int>({5, 1, 4, 2, 3}));
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
