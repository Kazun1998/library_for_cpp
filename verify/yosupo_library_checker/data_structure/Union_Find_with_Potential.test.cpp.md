---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/modint.hpp
    title: Algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Union_Find/Potentilized_Union_Find.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D Union Find"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n//\
    \ a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
    \u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename\
    \ U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n\
    }\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T,\
    \ typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a = b,\
    \ 1: 0);\n}\n#line 59 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// \u6F14\u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y)\
    \ { return x + y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return\
    \ x - y; }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x *\
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
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
    \ bit_length(x)); }\n#line 2 \"Algebra/modint.hpp\"\n\n#line 4 \"Algebra/modint.hpp\"\
    \n\ntemplate<int M>\nclass modint {\n    public:\n    static constexpr int _mod\
    \ = M; \n    uint64_t x;\n\n    public:\n    static int mod() { return _mod; }\n\
    \n    static modint raw(int v) {\n        modint a;\n        a.x = v;\n      \
    \  return a;\n    }\n\n    // \u521D\u671F\u5316\n    constexpr modint(): x(0)\
    \ {}\n    constexpr modint(int64_t a) {\n        int64_t w = (int64_t)(a) % mod();\n\
    \        if (w < 0) { w += mod(); }\n        x = w;\n    }\n\n    // \u30DE\u30A4\
    \u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x); }\n\n  \
    \  // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n        if ((x +=\
    \ b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\n    friend modint\
    \ operator+(const modint &x, const modint &y) { return modint(x) += y; }\n\n \
    \   // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n        if ((x\
    \ += mod() - b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\n    friend\
    \ modint operator-(const modint &x, const modint &y) { return modint(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n       \
    \ (x *= b.x) %= mod();\n        return *this;\n    }\n\n    friend modint operator*(const\
    \ modint &x, const modint &y) { return modint(x) *= y; }\n    friend modint operator*(const\
    \ int &x, const modint &y) { return modint(x) *= y; }\n    friend modint operator*(const\
    \ ll &x, const modint &y) { return modint(x) *= y; }\n\n    // \u9664\u6CD5\n\
    \    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }\n\n\
    \    friend modint operator/(const modint &x, const modint &y) { return modint(x)\
    \ /= y; }\n\n    modint inverse() const {\n        int64_t s = 1, t = 0;\n   \
    \     int64_t a = x, b = mod();\n\n        while (b > 0) {\n            int64_t\
    \ q = a / b;\n\n            a -= q * b; swap(a, b);\n            s -= q * t; swap(s,\
    \ t);\n        }\n\n        assert (a == 1);\n\n        return modint(s);\n  \
    \  }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const modint &a, const\
    \ modint &b) { return (a.x == b.x); }\n    friend bool operator==(const modint\
    \ &a, const int &b) { return a.x == safe_mod(b, mod()); }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n\
    \    friend istream &operator>>(istream &is, modint &a) {\n        int64_t x;\n\
    \        is >> x;\n        a.x = safe_mod(x, mod());\n        return is;\n   \
    \ }\n\n    // \u51FA\u529B\n    friend ostream &operator<<(ostream &os, const\
    \ modint &a) { return os << a.x; }\n\n    bool is_zero() const { return x == 0;\
    \ }\n    bool is_member(ll a) const { return x == (a % mod() + mod()) % mod();\
    \ }\n};\n\ntemplate<int mod>\nmodint<mod> pow(modint<mod> x, long long n) {\n\
    \    if (n < 0) { return pow(x, -n).inverse(); }\n\n    auto res = modint<mod>(1);\n\
    \    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n        x *= x;\n\
    \    }\n\n    return res;\n}\n#line 2 \"Union_Find/Potentilized_Union_Find.hpp\"\
    \n\n#line 4 \"Union_Find/Potentilized_Union_Find.hpp\"\n\ntemplate<typename Pot>\n\
    class Potentilized_Union_Find {\n    int n, _group_number;\n    vector<int> par,\
    \ rank;\n    vector<Pot> pot; // P(x) = P(par[x]) + diff[x]\n    vector<bool>\
    \ valid;\n\n    Pot zero;\n    function<Pot(const Pot&, const Pot&)> add;\n  \
    \  function<Pot(const Pot&, const Pot&)> diff;\n    function<Pot(const Pot&)>\
    \ neg;\n\n    public:\n    Potentilized_Union_Find(int n, function<Pot(const Pot&,\
    \ const Pot&)> add, const Pot &zero, const function<Pot(const Pot &)> neg):\n\
    \        n(n), par(vector<int>(n, -1)), rank(vector<int>(n, 0)), pot(vector<Pot>(n,\
    \ zero)), valid(vector<bool>(n, true)), _group_number(n),\n        zero(zero),\
    \ add(add), neg(neg) {\n            diff = [&add, &neg](const Pot& a, const Pot&\
    \ b) { return add(neg(a), b); };\n        }\n\n    /// @brief \u9802\u70B9 x \u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\u6C42\
    \u3081\u308B.\n    /// @param x \n    int find(int x) {\n        // x \u81EA\u8EAB\
    \u304C\u4EE3\u8868\u5143\u306A\u3089\u3070, x \u3067\u6C7A\u5B9A\n        if (par[x]\
    \ < 0) { return x; }\n\n        int r = find(par[x]);\n        pot[x] = add(pot[par[x]],\
    \ pot[x]);\n\n        return par[x] = r;\n    }\n\n    /// @brief \u9802\u70B9\
    \ x, y \u306F\u9023\u7D50\u304B?\n    /// @param x \n    /// @param y \n    inline\
    \ bool same(int x, int y) { return find(x) == find(y); }\n\n    /// @brief \u9802\
    \u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306B\u304A\u3051\u308B\
    \u9802\u70B9\u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \n    inline int\
    \ size(int x) { return -par[find(x)]; }\n\n    /// @brief P(x) = P(y) + a \u3068\
    \u3044\u3046\u60C5\u5831\u3092\u52A0\u3048\u308B.\n    /// @param x \n    ///\
    \ @param y \n    /// @param a \n    /// @return x, y \u306E\u9593\u304C\u7121\u77DB\
    \u76FE\u306A\u3089\u3070 true, \u77DB\u76FE\u304C\u3042\u308C\u3070 false.\n \
    \   bool unite(int x, int y, Pot a) {\n        a = add(potential(x), a);\n   \
    \     a = add(a, neg(potential(y)));\n\n        x = find(x), y = find(y);\n\n\
    \        if (x == y) {\n            valid[x] = valid[x] && (diff(pot[x], pot[y])\
    \ == a);\n            return valid[x];\n        }\n\n        if (rank[x] < rank[y])\
    \ {\n            swap(x, y);\n            a = neg(a);\n        }\n\n        if\
    \ (rank[x] == rank[y]) { rank[x]++; }\n\n        valid[x] = valid[x] && valid[y];\n\
    \    \n        par[x] += par[y];\n        par[y] = x;\n\n        pot[y] = a;\n\
    \n        _group_number--;\n\n        return true;\n    }\n\n    Pot potential(int\
    \ x) {\n        find(x);\n        return pot[x];\n    }\n\n    /// @brief x \u304B\
    \u3089\u898B\u305F y \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\
    \u308B. \u3064\u307E\u308A, -P(y) + P(x) \u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \u57FA\u6E96\n    /// @param y \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u6C42\
    \u3081\u308B\u70B9\n    Pot potential(int x, int y) { return add(neg(potential(x)),\
    \ potential(y)); }\n\n    bool is_valid(int x) { return valid[x]; }\n\n    ///\
    \ @brief x - y \u9593\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F\u4F4D\u7F6E\
    \u306B\u5B9A\u307E\u308B\u304B?\n    /// @param x \n    /// @param y \n    ///\
    \ @return \n    inline bool is_well_defined(int x, int y) { return same(x, y)\
    \ && is_valid(x); }\n\n    /// @brief P(x) = P(y) + a \u3068\u306A\u308A\u5F97\
    \u308B\u304B?\n    /// @param x \n    /// @param y \n    /// @param a \n    ///\
    \ @return \n    bool is_possible(int x, int y, Pot a) { return !same(x, y) ||\
    \ potential(x, y) == a; }\n\n    /// @brief \u9023\u7D50\u6210\u5206\u306E\u6570\
    \n    int group_count() const { return _group_number; }\n};\n#line 6 \"verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    int N, Q; cin >> N >>\
    \ Q;\n    Potentilized_Union_Find<mint> U(N, add<mint>, mint(0), neg<mint>);\n\
    \n    for (int q = 0; q < Q; q++) {\n        int t; scanf(\"%d\", &t);\n     \
    \   if (t == 0) {\n            int u, v, _x; scanf(\"%d%d%d\", &u, &v, &_x);\n\
    \            mint x = mint::raw(_x);\n\n            if (U.is_possible(u, v, x))\
    \ { \n                U.unite(u, v, x);\n                cout << 1 << \"\\n\"\
    ;\n            } else {\n                cout << 0 << \"\\n\";\n            }\n\
    \        } else if (t == 1) {\n            int u, v; scanf(\"%d%d\", &u, &v);\n\
    \            if (U.is_well_defined(u, v)) {\n                cout << U.potential(u,\
    \ v) << \"\\n\";\n            } else {\n                cout << -1 << \"\\n\"\
    ;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include\"../../../template/template.hpp\"\n#include\"../../../Algebra/modint.hpp\"\
    \n#include\"../../../Union_Find/Potentilized_Union_Find.hpp\"\n\nusing mint =\
    \ modint<998244353>;\n\nint main() {\n    int N, Q; cin >> N >> Q;\n    Potentilized_Union_Find<mint>\
    \ U(N, add<mint>, mint(0), neg<mint>);\n\n    for (int q = 0; q < Q; q++) {\n\
    \        int t; scanf(\"%d\", &t);\n        if (t == 0) {\n            int u,\
    \ v, _x; scanf(\"%d%d%d\", &u, &v, &_x);\n            mint x = mint::raw(_x);\n\
    \n            if (U.is_possible(u, v, x)) { \n                U.unite(u, v, x);\n\
    \                cout << 1 << \"\\n\";\n            } else {\n               \
    \ cout << 0 << \"\\n\";\n            }\n        } else if (t == 1) {\n       \
    \     int u, v; scanf(\"%d%d\", &u, &v);\n            if (U.is_well_defined(u,\
    \ v)) {\n                cout << U.potential(u, v) << \"\\n\";\n            }\
    \ else {\n                cout << -1 << \"\\n\";\n            }\n        }\n \
    \   }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - Algebra/modint.hpp
  - Union_Find/Potentilized_Union_Find.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
  requiredBy: []
  timestamp: '2025-11-23 12:30:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
- /verify/verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp.html
title: verify/yosupo_library_checker/data_structure/Union_Find_with_Potential.test.cpp
---
