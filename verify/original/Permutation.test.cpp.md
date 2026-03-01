---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/Permutaion.hpp
    title: "\u7F6E\u63DB"
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/exception.hpp
    title: template/exception.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"verify/original/Permutation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\
    \n\nusing ll = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B\
    . a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\n\
    template<typename T, typename U>\ninline bool chmax(T &a, const U b){\n    return\
    \ (a < b ? a = b, 1: 0);\n}\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B\
    . a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\n\
    template<typename T, typename U>\ninline bool chmin(T &a, const U b){\n    return\
    \ (a > b ? a = b, 1: 0);\n}\n\n// a \u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\
    \u3059\u308B.\ntemplate<typename T>\ninline T max(const vector<T> &a){\n    if\
    \ (a.empty()) throw invalid_argument(\"vector is empty.\");\n\n    return *max_element(a.begin(),\
    \ a.end());\n}\n\n// vector<T> a \u306E\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\
    \u308B.\ntemplate<typename T>\ninline T min(const vector<T> &a){\n    if (a.empty())\
    \ throw invalid_argument(\"vector is empty.\");\n\n    return *min_element(a.begin(),\
    \ a.end());\n}\n\n// vector<T> a \u306E\u6700\u5927\u5024\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline\
    \ size_t argmax(const vector<T> &a){\n    if (a.empty()) throw std::invalid_argument(\"\
    vector is empty.\");\n\n    return distance(a.begin(), max_element(a.begin(),\
    \ a.end()));\n}\n\n// vector<T> a \u306E\u6700\u5C0F\u5024\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline\
    \ size_t argmin(const vector<T> &a){\n    if (a.empty()) throw invalid_argument(\"\
    vector is empty.\");\n\n    return distance(a.begin(), min_element(a.begin(),\
    \ a.end()));\n}\n#line 61 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// \u6F14\u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y)\
    \ { return x + y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return\
    \ x - y; }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x *\
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<typename\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<typename\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nauto div_floor(T x, U y){\n    return x /\
    \ y - ((x % y != 0) && ((x < 0) != (y < 0)));\n}\n\n// ceil(x / y) \u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nauto div_ceil(T x, U y){\n  \
    \  return x / y + ((x % y != 0) && ((x < 0) == (y < 0)));\n}\n\n// x \u3092 y\
    \ \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nauto safe_mod(T x, U y){\n    auto q = div_floor(x, y);\n  \
    \  return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nauto\
    \ divmod(T x, U y){\n    auto q = div_floor(x, y);\n    return make_pair(q, x\
    \ - q * y);\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nauto round(T x, U y){\n    auto [q, r] = divmod(x, y);\n   \
    \ if (y < 0) return (r <= div_floor(y, 2)) ? q + 1 : q;\n    return (r >= div_ceil(y,\
    \ 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\
    \n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll\
    \ a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n  \
    \      y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y,\
    \ ll z){\n    ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E\
    \ y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n\
    \    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %=\
    \ z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\ntemplate<typename T>\nT sum(const\
    \ vector<T> &X) {\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return\
    \ y;\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\
    \u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T a, T b) {\n    T s =\
    \ 1, t = 0, u = 0, v = 1;\n    while (b) {\n        T q;\n        tie(q, a, b)\
    \ = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n        tie(s, t) = make_pair(t,\
    \ s - q * t);\n        tie(u, v) = make_pair(v, u - q * v);\n    }\n\n    return\
    \ make_tuple(s, u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0\
    \ \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n\
    \    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n    while ((x + 1) * (x\
    \ + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\n    return x;\n}\n\n\
    // floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0\
    \ \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return isqrt(N); }\n\n//\
    \ ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\
    \u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x = isqrt(N);\n    return\
    \ x * x == N ? x : x + 1;\n}\n#line 64 \"template/template.hpp\"\n\n// inout\n\
    #line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class... T>\n\
    void input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\
    \ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n  \
    \  cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\\n\";\n\
    }\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\nstd::vector<T>\
    \ input_vector(size_t n, size_t offset = 0) {\n    std::vector<T> res;\n    //\
    \ \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\u4FDD\uFF08\
    \u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n   \
    \ // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
    \u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\n    res.assign(offset, T());\n\
    \    \n    for (size_t i = 0; i < n; ++i) {\n        T el;\n        if (!(std::cin\
    \ >> el)) break;\n        res.push_back(std::move(el));\n    }\n    return res;\n\
    }\n#line 67 \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\
    \n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n\
    #define len(x) ll(x.size())\n#define elif else if\n#define unless(cond) if (!(cond))\n\
    #define until(cond) while (!(cond))\n#define loop while (true)\n\n// \u30AA\u30FC\
    \u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1, _2, name,\
    \ ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define overload4(_1,\
    \ _2, _3, _4, name, ...) name\n#define overload5(_1, _2, _3, _4, _5, name, ...)\
    \ name\n\n// \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for (ll i = 0; i\
    \ < n; i++)\n#define rep2(i, n) for (ll i = 0; i < n; i++)\n#define rep3(i, a,\
    \ b) for (ll i = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i = a; i < b;\
    \ i += c)\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define foreach1(x, a) for (auto &&x: a)\n#define foreach2(x, y, a) for (auto\
    \ &&[x, y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y, z]: a)\n#define\
    \ foreach4(x, y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__,\
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 70 \"template/template.hpp\"\
    \n\n// bitop\n#line 2 \"template/bitop.hpp\"\n\n// \u975E\u8CA0\u6574\u6570 x\
    \ \u306E bit legnth \u3092\u6C42\u3081\u308B.\nll bit_length(ll x) {\n    if (x\
    \ == 0) { return 0; }\n    return (sizeof(long) * CHAR_BIT) - __builtin_clzll(x);\n\
    }\n\n// \u975E\u8CA0\u6574\u6570 x \u306E popcount \u3092\u6C42\u3081\u308B.\n\
    ll popcount(ll x) { return __builtin_popcountll(x); }\n\n// \u6B63\u306E\u6574\
    \u6570 x \u306B\u5BFE\u3057\u3066, floor(log2(x)) \u3092\u6C42\u3081\u308B.\n\
    ll floor_log2(ll x) { return bit_length(x) - 1; }\n\n// \u6B63\u306E\u6574\u6570\
    \ x \u306B\u5BFE\u3057\u3066, ceil(log2(x)) \u3092\u6C42\u3081\u308B.\nll ceil_log2(ll\
    \ x) { return bit_length(x - 1); }\n\n// x \u306E\u7B2C k \u30D3\u30C3\u30C8\u3092\
    \u53D6\u5F97\u3059\u308B\nint get_bit(ll x, int k) { return (x >> k) & 1; }\n\n\
    // x \u306E\u30D3\u30C3\u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B.\n// k \u306F\
    \u30D3\u30C3\u30C8\u5217\u306E\u9577\u3055\u3068\u3059\u308B.\nvector<int> get_bits(ll\
    \ x, int k) {\n    vector<int> bits(k);\n    rep(i, k) {\n        bits[i] = x\
    \ & 1;\n        x >>= 1;\n    }\n\n    return bits;\n}\n\n// x \u306E\u30D3\u30C3\
    \u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B.\nvector<int> get_bits(ll x) { return\
    \ get_bits(x, bit_length(x)); }\n#line 73 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 1 \"Algebra/Permutaion.hpp\"\
    \n#pragma\n\n#line 4 \"Algebra/Permutaion.hpp\"\n\nclass Permutation {\n    private:\n\
    \    vector<int> perm, ind;\n\n    public:\n    constexpr Permutation(const int\
    \ n) {\n        perm.resize(n);\n        ind.resize(n);\n        iota(perm.begin(),\
    \ perm.end(), 0);\n        iota(ind.begin(), ind.end(), 0);\n    }\n\n    constexpr\
    \ Permutation(const vector<int> &vec) : perm(vec) {\n        ind.resize(perm.size());\n\
    \        for (int i = 0; i < perm.size(); ++i) {\n            ind[perm[i]] = i;\n\
    \        }\n    }\n\n    /// @brief n \u8981\u7D20\u306E\u6052\u7B49\u7F6E\u63DB\
    \u3092\u751F\u6210\u3059\u308B.\n    static constexpr Permutation identity(int\
    \ n) {\n        return Permutation(n);\n    }\n\n    /// @brief i \u756A\u76EE\
    \u3068 j \u756A\u76EE\u3092\u4EA4\u63DB\u3059\u308B.\n    ///\n    /// \u203B\
    \ i \u3068 j \u3092\u4EA4\u63DB\u3067\u306F\u306A\u3044.\n    constexpr void swap(int\
    \ i, int j) {\n        int u = perm[i];\n        int v = perm[j];\n        std::swap(perm[i],\
    \ perm[j]);\n        std::swap(ind[u], ind[v]);\n    }\n\n    /// @brief u \u3068\
    \ v \u3092\u4EA4\u63DB\n    ///\n    /// \u203B u \u756A\u76EE\u3068 v \u756A\u76EE\
    \u3092\u4EA4\u63DB\u3067\u306F\u306A\u3044.\n    constexpr void transposition(int\
    \ u, int v) {\n        swap(ind[u], ind[v]);\n    }\n\n    /// @brief \u7F6E\u63DB\
    \u3092\u5FAA\u74B0\u7F6E\u63DB\u306E\u7A4D\u306B\u5206\u89E3\u3059\u308B.\n  \
    \  /// @return \n    vector<vector<int>> cycle_division() const {\n        vector<vector<int>>\
    \ cycles;\n        vector<bool> used(perm.size(), false);\n        for (int i\
    \ = 0; i < (int)perm.size(); ++i) {\n            if (used[i]) continue;\n    \
    \        vector<int> cycle;\n            int cur = i;\n            while (!used[cur])\
    \ {\n                used[cur] = true;\n                cycle.push_back(cur);\n\
    \                cur = perm[cur];\n            }\n            cycles.push_back(cycle);\n\
    \        }\n        return cycles;\n    }\n\n    /// @brief \u4E92\u63DB\u306E\
    \u6700\u5C0F\u56DE\u6570\u3092\u6C42\u3081\u308B.\n    /// @return \n    int minimum_transposition()\
    \ const {\n        return perm.size() - cycle_division().size();\n    }\n\n  \
    \  /// @brief \u8EE2\u5012\u6570\u3092\u6C42\u3081\u308B.\n    /// @return \n\
    \    long long inversion() const {\n        long long ans = 0;\n        int n\
    \ = perm.size();\n        vector<int> bit(n + 1, 0);\n        for (int i = 0;\
    \ i < n; ++i) {\n            int s = 0;\n            for (int x = perm[i] + 1;\
    \ x > 0; x -= x & -x) s += bit[x];\n            ans += i - s;\n            for\
    \ (int x = perm[i] + 1; x <= n; x += x & -x) bit[x]++;\n        }\n        return\
    \ ans;\n    }\n\n    /// @brief \u7F6E\u63DB\u306E\u7B26\u53F7\uFF08\u5076\u7F6E\
    \u63DB\u306A\u3089 1\u3001\u5947\u7F6E\u63DB\u306A\u3089 -1\uFF09\u3092\u8FD4\u3059\
    .\n    int sign() const {\n        return (minimum_transposition() & 1) ? -1 :\
    \ 1;\n    }\n\n    constexpr Permutation operator*(const Permutation &rhs) const\
    \ {\n        int n = perm.size();\n        vector<int> res(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            res[i] = perm[rhs.perm[i]];\n        }\n \
    \       return Permutation(res);\n    }\n\n    constexpr Permutation& operator*=(const\
    \ Permutation &rhs) {\n        *this = *this * rhs;\n        return *this;\n \
    \   }\n\n    /// @brief \u9006\u7F6E\u63DB\u3092\u6C42\u3081\u308B.\n    /// @return\
    \ \n    constexpr Permutation inverse() const {\n        return Permutation(ind);\n\
    \    }\n\n    /// @brief i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B.\n    constexpr int operator[](int i) const {\n        return perm[i];\n\
    \    }\n};\n\nlong long permutation_inversion(const Permutation &P, const Permutation\
    \ &Q) {\n    return (Q * P.inverse()).inversion();\n}\n\ntemplate<typename T>\n\
    optional<long long> list_inversion(const vector<T> &A, const vector<T> &B) {\n\
    \    assert(A.size() == B.size());\n\n    int n = A.size();\n    map<T, vector<int>>\
    \ dic;\n\n    for (int i = 0; i < n; i++) dic[A[i]].emplace_back(i);\n\n    for\
    \ (auto& [ignore, lis]: dic) reverse(lis.begin(), lis.end());\n\n    vector<int>\
    \ p(n);\n    for (int i = 0; i < n; i++) {\n        if (dic[B[i]].empty()) return\
    \ nullopt;\n\n        p[i] = dic[B[i]].back();\n        dic[B[i]].pop_back();\n\
    \    }\n\n    return Permutation(p).inversion();\n}\n#line 5 \"verify/original/Permutation.test.cpp\"\
    \n\nvoid verify() {\n    // Constructor & Identity\n    {\n        Permutation\
    \ p(5);\n        assert(p.inversion() == 0);\n        assert(p.sign() == 1);\n\
    \        auto cycles = p.cycle_division();\n        assert(cycles.size() == 5);\n\
    \    }\n    \n    {\n        Permutation p = Permutation::identity(3);\n     \
    \   assert(p.inversion() == 0);\n    }\n\n    // Vector Constructor & Inversion\
    \ & Sign\n    {\n        vector<int> v = {2, 0, 1};\n        Permutation p(v);\n\
    \        assert(p.inversion() == 2);\n        assert(p.sign() == 1);\n       \
    \ \n        vector<int> v2 = {2, 1, 0};\n        Permutation p2(v2);\n       \
    \ assert(p2.inversion() == 3);\n        assert(p2.sign() == -1);\n    }\n\n  \
    \  // Multiplication (Composition)\n    {\n        vector<int> v1 = {1, 2, 0};\n\
    \        vector<int> v2 = {0, 2, 1};\n        Permutation p(v1);\n        Permutation\
    \ q(v2);\n        Permutation r = p * q;\n        \n        assert(r.inversion()\
    \ == 1);\n        \n        auto cycles = r.cycle_division();\n        assert(cycles.size()\
    \ == 2);\n    }\n\n    // Inverse\n    {\n        vector<int> v = {2, 0, 1};\n\
    \        Permutation p(v);\n        Permutation inv = p.inverse();\n        \n\
    \        Permutation id = p * inv;\n        assert(id.inversion() == 0);\n   \
    \     \n        Permutation id2 = inv * p;\n        assert(id2.inversion() ==\
    \ 0);\n    }\n\n    // Swap & Transposition\n    {\n        Permutation p(4);\n\
    \        p.swap(1, 3);\n        assert(p.inversion() == 3);\n\n        Permutation\
    \ q(3);\n        q.transposition(0, 2);\n        assert(q.inversion() == 3);\n\
    \        \n        q.transposition(1, 2);\n        assert(q.inversion() == 2);\n\
    \    }\n\n    // Minimum Transposition\n    {\n        vector<int> v = {2, 0,\
    \ 1};\n        Permutation p(v);\n        assert(p.minimum_transposition() ==\
    \ 2);\n    }\n\n    // list_inversion\n    {\n        vector<int> A = {10, 20,\
    \ 30};\n        vector<int> B = {20, 30, 10};\n        auto res = list_inversion(A,\
    \ B);\n        assert(res.has_value());\n        assert(res.value() == 2);\n \
    \       \n        vector<int> C = {1, 1, 2};\n        vector<int> D = {1, 2, 1};\n\
    \        assert(list_inversion(C, D).value() == 1);\n        \n        vector<int>\
    \ E = {1, 2};\n        vector<int> F = {1, 3};\n        assert(!list_inversion(E,\
    \ F).has_value());\n    }\n}\n\nint main() {\n    verify();\n    cout << \"Hello\
    \ World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../Algebra/Permutaion.hpp\"\
    \n\nvoid verify() {\n    // Constructor & Identity\n    {\n        Permutation\
    \ p(5);\n        assert(p.inversion() == 0);\n        assert(p.sign() == 1);\n\
    \        auto cycles = p.cycle_division();\n        assert(cycles.size() == 5);\n\
    \    }\n    \n    {\n        Permutation p = Permutation::identity(3);\n     \
    \   assert(p.inversion() == 0);\n    }\n\n    // Vector Constructor & Inversion\
    \ & Sign\n    {\n        vector<int> v = {2, 0, 1};\n        Permutation p(v);\n\
    \        assert(p.inversion() == 2);\n        assert(p.sign() == 1);\n       \
    \ \n        vector<int> v2 = {2, 1, 0};\n        Permutation p2(v2);\n       \
    \ assert(p2.inversion() == 3);\n        assert(p2.sign() == -1);\n    }\n\n  \
    \  // Multiplication (Composition)\n    {\n        vector<int> v1 = {1, 2, 0};\n\
    \        vector<int> v2 = {0, 2, 1};\n        Permutation p(v1);\n        Permutation\
    \ q(v2);\n        Permutation r = p * q;\n        \n        assert(r.inversion()\
    \ == 1);\n        \n        auto cycles = r.cycle_division();\n        assert(cycles.size()\
    \ == 2);\n    }\n\n    // Inverse\n    {\n        vector<int> v = {2, 0, 1};\n\
    \        Permutation p(v);\n        Permutation inv = p.inverse();\n        \n\
    \        Permutation id = p * inv;\n        assert(id.inversion() == 0);\n   \
    \     \n        Permutation id2 = inv * p;\n        assert(id2.inversion() ==\
    \ 0);\n    }\n\n    // Swap & Transposition\n    {\n        Permutation p(4);\n\
    \        p.swap(1, 3);\n        assert(p.inversion() == 3);\n\n        Permutation\
    \ q(3);\n        q.transposition(0, 2);\n        assert(q.inversion() == 3);\n\
    \        \n        q.transposition(1, 2);\n        assert(q.inversion() == 2);\n\
    \    }\n\n    // Minimum Transposition\n    {\n        vector<int> v = {2, 0,\
    \ 1};\n        Permutation p(v);\n        assert(p.minimum_transposition() ==\
    \ 2);\n    }\n\n    // list_inversion\n    {\n        vector<int> A = {10, 20,\
    \ 30};\n        vector<int> B = {20, 30, 10};\n        auto res = list_inversion(A,\
    \ B);\n        assert(res.has_value());\n        assert(res.value() == 2);\n \
    \       \n        vector<int> C = {1, 1, 2};\n        vector<int> D = {1, 2, 1};\n\
    \        assert(list_inversion(C, D).value() == 1);\n        \n        vector<int>\
    \ E = {1, 2};\n        vector<int> F = {1, 3};\n        assert(!list_inversion(E,\
    \ F).has_value());\n    }\n}\n\nint main() {\n    verify();\n    cout << \"Hello\
    \ World\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Algebra/Permutaion.hpp
  isVerificationFile: true
  path: verify/original/Permutation.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 23:52:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/original/Permutation.test.cpp
layout: document
redirect_from:
- /verify/verify/original/Permutation.test.cpp
- /verify/verify/original/Permutation.test.cpp.html
title: verify/original/Permutation.test.cpp
---
