---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Union_Find_with_Non-Commutative_Group_Potential.test.cpp
    title: verify/yosupo_library_checker/data_structure/Union_Find_with_Non-Commutative_Group_Potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
    title: verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
      \u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B."
    links: []
  bundledCode: "#line 2 \"Union_Find/Potentilized_Union_Find.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n// a \u2190 max(a, b)\
    \ \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089\
    , \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool\
    \ chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n// a \u2190\
    \ min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\
    \u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline\
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n#line 59\
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u6F14\
    \u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) { return x +\
    \ y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return x - y;\
    \ }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x * y; }\n\
    \ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<typename\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<typename\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x > 0 ? x\
    \ / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y - 1) / y: x / y)\
    \ ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT safe_mod(T x, U y){\n    T q = div_floor(x,\
    \ y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\
    \u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\n\
    pair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n    return {q, x - q\
    \ * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT round(T x, U y){\n    T q, r;\n    tie (q, r) = divmod(x,\
    \ y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\
    \u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B\
    .\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n        if (y & 1) {\
    \ a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n    return a;\n}\n\n//\
    \ x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\
    \u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n    while (y){\n       \
    \ if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n        y >>= 1;\n  \
    \  }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT modpow(T\
    \ x, U y, T z) {\n    T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x)\
    \ %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n\
    }\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\n\
    ll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto &&x: X) { y+=x; }\n    return\
    \ y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T>\nT sum(vector<T> &X){\n    T y = T(0);\n    for (auto\
    \ &&x: X) { y += x; }\n    return y;\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\
    \u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a,\
    \ b)) \u3092\u6C42\u3081\u308B.\ntuple<ll, ll, ll> Extended_Euclid(ll a, ll b)\
    \ {\n    ll s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        ll q;\n    \
    \    tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n        tie(s,\
    \ t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u - q * v);\n\
    \    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\
    \u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll isqrt(const\
    \ ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n    while ((x\
    \ + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\n    return\
    \ x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\
    \u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return isqrt(N);\
    \ }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F\
    , 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x = isqrt(N);\n\
    \    return x * x == N ? x : x + 1;\n}\n#line 62 \"template/template.hpp\"\n\n\
    // inout\n#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class...\
    \ T>\nvoid input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\\
    n\"; }\n\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&...\
    \ b){\n    cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\
    \\n\";\n}\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &P){\n   \
    \ os << P.first << \" \" << P.second;\n    return os;\n}\n\ntemplate<typename\
    \ T>\nvector<T> vector_input(int N, int index){\n    vector<T> X(N+index);\n \
    \   for (int i=index; i<index+N; i++) cin >> X[i];\n    return X;\n}\n\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &X){\n    for (auto &x: X) {\
    \ is >> x; }\n    return is;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &X){\n    int s = (int)X.size();\n    for (int i = 0; i\
    \ < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &S){\n    int i\
    \ = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n    return os;\n\
    }\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const set<T> &S){\n\
    \    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n   \
    \ return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \"\
    \ \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \"\
    \ \": \"\") << a; i++; }\n    return os;\n}\n#line 65 \"template/template.hpp\"\
    \n\n// macro\n#line 2 \"template/macro.hpp\"\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\
    \u7FA9\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n#define unless(cond) if (!(cond))\n#define until(cond) while (!(cond))\n\
    #define loop while (true)\n\n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\
    \u30AF\u30ED\n#define overload2(_1, _2, name, ...) name\n#define overload3(_1,\
    \ _2, _3, name, ...) name\n#define overload4(_1, _2, _3, _4, name, ...) name\n\
    #define overload5(_1, _2, _3, _4, _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\
    \u3057\u7CFB\n#define rep1(n) for (ll i = 0; i < n; i++)\n#define rep2(i, n) for\
    \ (ll i = 0; i < n; i++)\n#define rep3(i, a, b) for (ll i = a; i < b; i++)\n#define\
    \ rep4(i, a, b, c) for (ll i = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x:\
    \ a)\n#define foreach2(x, y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y,\
    \ z, a) for (auto &&[x, y, z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x,\
    \ y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__, foreach4, foreach3,\
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 68 \"template/template.hpp\"\n\n// bitop\n\
    #line 2 \"template/bitop.hpp\"\n\n// \u975E\u8CA0\u6574\u6570 x \u306E bit legnth\
    \ \u3092\u6C42\u3081\u308B.\nll bit_length(ll x) {\n    if (x == 0) { return 0;\
    \ }\n    return (sizeof(long) * CHAR_BIT) - __builtin_clzll(x);\n}\n\n// \u975E\
    \u8CA0\u6574\u6570 x \u306E popcount \u3092\u6C42\u3081\u308B.\nll popcount(ll\
    \ x) { return __builtin_popcountll(x); }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\
    \u5BFE\u3057\u3066, floor(log2(x)) \u3092\u6C42\u3081\u308B.\nll floor_log2(ll\
    \ x) { return bit_length(x) - 1; }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\
    \u3057\u3066, ceil(log2(x)) \u3092\u6C42\u3081\u308B.\nll ceil_log2(ll x) { return\
    \ bit_length(x - 1); }\n\n// x \u306E\u7B2C k \u30D3\u30C3\u30C8\u3092\u53D6\u5F97\
    \u3059\u308B\nint get_bit(ll x, int k) { return (x >> k) & 1; }\n\n// x \u306E\
    \u30D3\u30C3\u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B.\n// k \u306F\u30D3\u30C3\
    \u30C8\u5217\u306E\u9577\u3055\u3068\u3059\u308B.\nvector<int> get_bits(ll x,\
    \ int k) {\n    vector<int> bits(k);\n    rep(i, k) {\n        bits[i] = x & 1;\n\
    \        x >>= 1;\n    }\n\n    return bits;\n}\n\n// x \u306E\u30D3\u30C3\u30C8\
    \u5217\u3092\u53D6\u5F97\u3059\u308B.\nvector<int> get_bits(ll x) { return get_bits(x,\
    \ bit_length(x)); }\n#line 4 \"Union_Find/Potentilized_Union_Find.hpp\"\n\ntemplate<typename\
    \ Pot>\nclass Potentilized_Union_Find {\n    int n, _group_number;\n    vector<int>\
    \ par, rank;\n    vector<Pot> pot; // P(x) = pot[x] P(par[x])\n    vector<bool>\
    \ valid;\n\n    Pot unit;\n    function<Pot(const Pot&, const Pot&)> add;\n  \
    \  function<Pot(const Pot&, const Pot&)> diff;\n    function<Pot(const Pot&)>\
    \ neg;\n\n    public:\n    Potentilized_Union_Find(int n, function<Pot(const Pot&,\
    \ const Pot&)> add, const Pot &unit, const function<Pot(const Pot &)> neg):\n\
    \        n(n), par(vector<int>(n, -1)), rank(vector<int>(n, 0)), pot(vector<Pot>(n,\
    \ unit)), valid(vector<bool>(n, true)), _group_number(n),\n        unit(unit),\
    \ add(add), neg(neg) {\n            diff = [&add, &neg](const Pot& a, const Pot&\
    \ b) { return add(neg(a), b); };\n        }\n\n    /// @brief \u9802\u70B9 x \u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\u6C42\
    \u3081\u308B.\n    /// @param x \n    int find(int x) {\n        // x \u81EA\u8EAB\
    \u304C\u4EE3\u8868\u5143\u306A\u3089\u3070, x \u3067\u6C7A\u5B9A\n        if (par[x]\
    \ < 0) { return x; }\n\n        int r = find(par[x]);\n        pot[x] = add(pot[x],\
    \ pot[par[x]]);\n        return par[x] = r;\n    }\n\n    /// @brief \u9802\u70B9\
    \ x, y \u306F\u9023\u7D50\u304B?\n    /// @param x \n    /// @param y \n    inline\
    \ bool same(int x, int y) { return find(x) == find(y); }\n\n    /// @brief \u9802\
    \u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306B\u304A\u3051\u308B\
    \u9802\u70B9\u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \n    inline int\
    \ size(int x) { return -par[find(x)]; }\n\n    /// @brief P(x) = a P(y) \u3068\
    \u3044\u3046\u60C5\u5831\u3092\u52A0\u3048\u308B.\n    /// @param x \n    ///\
    \ @param y \n    /// @param a \n    /// @return x, y \u306E\u9593\u304C\u7121\u77DB\
    \u76FE\u306A\u3089\u3070 true, \u77DB\u76FE\u304C\u3042\u308C\u3070 false.\n \
    \   bool unite(int x, int y, Pot a) {\n        a = add(a, potential(y));\n   \
    \     a = add(neg(potential(x)), a);\n\n        x = find(x), y = find(y);\n\n\
    \        if (x == y) {\n            valid[x] = valid[x] && (a == unit);\n    \
    \        return valid[x];\n        }\n\n        if (rank[x] > rank[y]) {\n   \
    \         swap(x, y);\n            a = neg(a);\n        }\n\n        if (rank[x]\
    \ == rank[y]) { rank[x]++; }\n\n        valid[y] = valid[x] && valid[y];\n\n \
    \       par[y] += par[x];\n\n        par[x] = y;\n        pot[x] = a;\n\n    \
    \    _group_number--;\n\n        return true;\n    }\n\n    Pot potential(int\
    \ x) {\n        find(x);\n        return pot[x];\n    }\n\n    /// @brief x \u304B\
    \u3089\u898B\u305F y \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\
    \u308B. \u3064\u307E\u308A, -P(y) + P(x) \u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \u57FA\u6E96\n    /// @param y \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\
    \u3081\u308B\u70B9\n    Pot potential(int x, int y) { return add(potential(x),\
    \ neg(potential(y))); }\n\n    bool is_valid(int x) { return valid[x]; }\n\n \
    \   /// @brief x - y \u9593\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F\u4F4D\
    \u7F6E\u306B\u5B9A\u307E\u308B\u304B?\n    /// @param x \n    /// @param y \n\
    \    /// @return \n    inline bool is_well_defined(int x, int y) { return same(x,\
    \ y) && is_valid(x); }\n\n    /// @brief P(x) = P(y) + a \u3068\u306A\u308A\u5F97\
    \u308B\u304B?\n    /// @param x \n    /// @param y \n    /// @param a \n    ///\
    \ @return \n    bool is_possible(int x, int y, Pot a) { return !same(x, y) ||\
    \ potential(x, y) == a; }\n\n    /// @brief \u9023\u7D50\u6210\u5206\u306E\u6570\
    \n    int group_count() const { return _group_number; }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<typename\
    \ Pot>\nclass Potentilized_Union_Find {\n    int n, _group_number;\n    vector<int>\
    \ par, rank;\n    vector<Pot> pot; // P(x) = pot[x] P(par[x])\n    vector<bool>\
    \ valid;\n\n    Pot unit;\n    function<Pot(const Pot&, const Pot&)> add;\n  \
    \  function<Pot(const Pot&, const Pot&)> diff;\n    function<Pot(const Pot&)>\
    \ neg;\n\n    public:\n    Potentilized_Union_Find(int n, function<Pot(const Pot&,\
    \ const Pot&)> add, const Pot &unit, const function<Pot(const Pot &)> neg):\n\
    \        n(n), par(vector<int>(n, -1)), rank(vector<int>(n, 0)), pot(vector<Pot>(n,\
    \ unit)), valid(vector<bool>(n, true)), _group_number(n),\n        unit(unit),\
    \ add(add), neg(neg) {\n            diff = [&add, &neg](const Pot& a, const Pot&\
    \ b) { return add(neg(a), b); };\n        }\n\n    /// @brief \u9802\u70B9 x \u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\u6C42\
    \u3081\u308B.\n    /// @param x \n    int find(int x) {\n        // x \u81EA\u8EAB\
    \u304C\u4EE3\u8868\u5143\u306A\u3089\u3070, x \u3067\u6C7A\u5B9A\n        if (par[x]\
    \ < 0) { return x; }\n\n        int r = find(par[x]);\n        pot[x] = add(pot[x],\
    \ pot[par[x]]);\n        return par[x] = r;\n    }\n\n    /// @brief \u9802\u70B9\
    \ x, y \u306F\u9023\u7D50\u304B?\n    /// @param x \n    /// @param y \n    inline\
    \ bool same(int x, int y) { return find(x) == find(y); }\n\n    /// @brief \u9802\
    \u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306B\u304A\u3051\u308B\
    \u9802\u70B9\u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \n    inline int\
    \ size(int x) { return -par[find(x)]; }\n\n    /// @brief P(x) = a P(y) \u3068\
    \u3044\u3046\u60C5\u5831\u3092\u52A0\u3048\u308B.\n    /// @param x \n    ///\
    \ @param y \n    /// @param a \n    /// @return x, y \u306E\u9593\u304C\u7121\u77DB\
    \u76FE\u306A\u3089\u3070 true, \u77DB\u76FE\u304C\u3042\u308C\u3070 false.\n \
    \   bool unite(int x, int y, Pot a) {\n        a = add(a, potential(y));\n   \
    \     a = add(neg(potential(x)), a);\n\n        x = find(x), y = find(y);\n\n\
    \        if (x == y) {\n            valid[x] = valid[x] && (a == unit);\n    \
    \        return valid[x];\n        }\n\n        if (rank[x] > rank[y]) {\n   \
    \         swap(x, y);\n            a = neg(a);\n        }\n\n        if (rank[x]\
    \ == rank[y]) { rank[x]++; }\n\n        valid[y] = valid[x] && valid[y];\n\n \
    \       par[y] += par[x];\n\n        par[x] = y;\n        pot[x] = a;\n\n    \
    \    _group_number--;\n\n        return true;\n    }\n\n    Pot potential(int\
    \ x) {\n        find(x);\n        return pot[x];\n    }\n\n    /// @brief x \u304B\
    \u3089\u898B\u305F y \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\
    \u308B. \u3064\u307E\u308A, -P(y) + P(x) \u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \u57FA\u6E96\n    /// @param y \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\
    \u3081\u308B\u70B9\n    Pot potential(int x, int y) { return add(potential(x),\
    \ neg(potential(y))); }\n\n    bool is_valid(int x) { return valid[x]; }\n\n \
    \   /// @brief x - y \u9593\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F\u4F4D\
    \u7F6E\u306B\u5B9A\u307E\u308B\u304B?\n    /// @param x \n    /// @param y \n\
    \    /// @return \n    inline bool is_well_defined(int x, int y) { return same(x,\
    \ y) && is_valid(x); }\n\n    /// @brief P(x) = P(y) + a \u3068\u306A\u308A\u5F97\
    \u308B\u304B?\n    /// @param x \n    /// @param y \n    /// @param a \n    ///\
    \ @return \n    bool is_possible(int x, int y, Pot a) { return !same(x, y) ||\
    \ potential(x, y) == a; }\n\n    /// @brief \u9023\u7D50\u6210\u5206\u306E\u6570\
    \n    int group_count() const { return _group_number; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: Union_Find/Potentilized_Union_Find.hpp
  requiredBy: []
  timestamp: '2025-11-24 00:16:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
  - verify/yosupo_library_checker/data_structure/Union_Find_with_Non-Commutative_Group_Potential.test.cpp
documentation_of: Union_Find/Potentilized_Union_Find.hpp
layout: document
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
---

## Outline

Union Find にポテンシャルの概念を付け加え, $2$ 頂点間のポテンシャルの差を取得する.

## Define

$G$ を群とする.

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ において, 以下をみたす時, この $D$ は対称的であるという.

* 任意の $a \in A$ に対して, 以下をみたす逆弧 $\operatorname{rev}: A \to A$ が定まっている.
  * $\operatorname{rev}(a)$ は $a$ の逆向きである. つまり, 以下を満たす.
    * $s(a) = t(\operatorname{rev}(a))$.
    * $t(a) = s(\operatorname{rev}(a))$.
  * $\operatorname{rev}$ は対合である. つまり, 任意の $a \in A$ に対して, $\operatorname{rev}(\operatorname{rev}(a)) = a$ となる.
* 任意の $a \in A$ に対して, $W(\operatorname{rev}(a)) = W(a)^{-1}$ である.

---

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ 上のパス $p = (v_0, v_1, v_2, \dots, v_m)$ に対して, $p$ のポテンシャルエネルギー $E(p)$ を

$$ E(p) := \sum_{j=1}^m W\left(\overrightarrow{v_{j-1} v_j} \right)$$

で定義する.

---

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下の条件をみたす時, $D$ はポテンシャルを持つという.

* 任意の $u, v\in V$ に対して, $u$ を始点, $v$ を終点とするパスにおけるポテンシャルエネルギーはパスに依らない.
* つまり, $p, q$ を $u$ を始点, $v$ を終点とするパスとしたとき, $E(p) = E(q)$ が成り立つ.

---

$D$ はポテンシャルを持つとする.

$$ R := \{(u, v) \in V^2 \mid v \text{ is reachable from } u \text{ on } D. \}$$

とする. このとき, $D$ におけるポテンシャル $P: R \to G$ を $u$ を始点, $v$ を終点とするパスを $p$ としたとき, $P(u, v) := E(p)$ とする. $D$ がポテンシャルを持つことから, Well-Defined 性が従う.

## Theory

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下は同値になる.

* (a) $D$ はポテンシャルを持つ.
* (b) 任意の $D$ 上のサイクルに対するポテンシャルエネルギーは単位元である.

## Remark

このライブラリで対応しているのは $P(x) = a P(y)$ の形である, 左作用である. もし, 右作用「のみ」を要求されている場合は, 次のようにして対応させることができる.

* $P(x) = P(y) a$ を変形させると, $P(x)^{-1} = a^{-1} P(y)^{-1}$ となる. $P$ がポテンシャルであるとき, $P(\bullet)^{-1}$ もポテンシャルになる. よって, $P(\bullet)^{-1}$ の問題に帰着させることができる. なお, 関係式を定義する際に, 全て逆元を取ることを忘れないこと.

## Contents

### Constructor

```cpp
template<typename Pot>
Potentilized_Union_Find(int n, function<Pot(const Pot&, const Pot&)> add, const Pot &zero, const function<Pot(const Pot &)> neg)
```

* $n$ 頂点からなる, 各弧に重みづけられる群 $G$ が以下のようにして表される対称的な有向グラフの場を生成する.
  * $G$ の集合は `Pot`, 演算は `add`, 単位元は `unit`, 逆元関数は `neg`

### find

```cpp
int find(int x)
```

* 頂点 $x$ が属する連結成分の代表元を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### same

```cpp
bool same(int x, int y)
```

* 頂点 $x, y$ は連結かどうかを求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### size

```cpp
int size(int x)
```

* 頂点 $x$ が属する連結成分の頂点数を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### unite

```cpp
bool unite(int x, int y, Pot a)
```

* Potential について,$P(x) = a P(y)$ という関係性を加え, 矛盾性を返す.
* **返り値** : $P(x), P(y)$ の間について, 矛盾がなければ `true`, 矛盾があれば (元々矛盾していた場合も含む) `false`.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### potential

```cpp
Pot potential(int x)
```

* $r$ を $x$ が属する連結成分の代表元 (つまり, $\textrm{find}(x)$) とする.  このとき, $r$ を基準とする $x$ のポテンシャル $P(r)^{-1}P(x)$ を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

```cpp
Pot potential(int x, int y)
```

* $y$ を基準とする $x$ のポテンシャル $P(x)P(y)^{-1}$ を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### is_valid

```cpp
bool is_valid(int x)
```

* $x$ を含む連結成分におけるポテンシャルが整合性を持つかどうかを判定する.
* **計算量** : $O(1)$ 時間.

### is_well_defined

```cpp
bool is_well_defined(int x, int y)
```

* $y$ を基準とする $x$ のポテンシャルが「矛盾なく」「一意的」に定義できるかどうかを判定する.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### is_possible

```cpp
bool is_possible(int x, int y, Pot a)
```

* $y$ を基準とする $x$ のポテンシャルについて, $P(x)P(y)^{-1}=a$ となる可能性はあるか?
* **計算量** : ならし $O(\alpha(N))$ 時間.

### group_count

```cpp
int group_count()
```

* 有向グラフにおける連結成分の数を求める.
* **計算量** : $O(1)$ 時間

## History 

|日付|内容|
|:---:|:---:|
|2025/11/24| ポテンシャルの群が非可換群である場合にも対応|
|2025/11/23| ポテンシャル付き Union Find を実装|
