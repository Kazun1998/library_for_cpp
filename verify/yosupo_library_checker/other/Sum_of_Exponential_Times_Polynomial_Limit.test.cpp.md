---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/modint.hpp
    title: Algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Counting/Combination_Calculator.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B\u8AD6\u306B\u95A2\u3059\u308B\u57FA\u672C\
      \u7684\u306A\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: Integer/Smallest_Prime_Factor.hpp
    title: "\u6700\u5C0F\u7D20\u56E0\u6570"
  - icon: ':heavy_check_mark:'
    path: Math/Enumerate_Geometrics.hpp
    title: Math/Enumerate_Geometrics.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Enumerate_Powers.hpp
    title: "\u51AA\u4E57\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp
    title: "(\u7B49\u6BD4) x (\u5358\u9805\u5F0F) \u306E\u7D1A\u6570"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<integral\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<integral\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<integral\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T, integral U>\nauto div_floor(T x, U y){\n    return x /\
    \ y - ((x % y != 0) && ((x < 0) != (y < 0)));\n}\n\n// ceil(x / y) \u3092\u6C42\
    \u3081\u308B.\ntemplate<integral T, integral U>\nauto div_ceil(T x, U y){\n  \
    \  return x / y + ((x % y != 0) && ((x < 0) == (y < 0)));\n}\n\n// x \u3092 y\
    \ \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<integral\
    \ T, integral U>\nauto safe_mod(T x, U y){\n    auto q = div_floor(x, y);\n  \
    \  return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<integral T, integral U>\nauto\
    \ divmod(T x, U y){\n    auto q = div_floor(x, y);\n    return make_pair(q, x\
    \ - q * y);\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<integral\
    \ T, integral U>\nauto round(T x, U y){\n    auto [q, r] = divmod(x, y);\n   \
    \ if (y < 0) return (r <= div_floor(y, 2)) ? q + 1 : q;\n    return (r >= div_ceil(y,\
    \ 2)) ? q + 1 : q;\n}\n\n// \u5947\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B.\ntemplate<integral T>\nbool is_odd(const T &x) { return x % 2 != 0; }\n\
    \n// \u5076\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<integral\
    \ T>\nbool is_even(const T &x) { return x % 2 == 0; }\n\n// m \u306E\u500D\u6570\
    \u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<integral T, integral\
    \ U>\nbool is_multiple(const T &x, const U &m) { return x % m == 0; }\n\n// \u6B63\
    \u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool\
    \ is_positive(const T &x) { return x > 0; }\n\n// \u8CA0\u304B\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool is_negative(const T &x)\
    \ { return x < 0; }\n\n// \u30BC\u30ED\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B.\ntemplate<typename T>\nbool is_zero(const T &x) { return x == 0; }\n\n\
    // \u975E\u8CA0\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename\
    \ T>\nbool is_non_negative(const T &x) { return x >= 0; }\n\n// \u975E\u6B63\u304B\
    \u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool is_non_positive(const\
    \ T &x) { return x <= 0; }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\
    \n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\nll pow(ll x, ll y) { return intpow(x,\
    \ y); }\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, integral U>\nT modpow(T x, U y, T z)\
    \ {\n    T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\ntemplate<typename\
    \ T>\nT sum(const vector<T> &X) {\n    T y = T(0);\n    for (auto &&x: X) { y\
    \ += x; }\n    return y;\n}\n\ntemplate<typename T>\nT gcd(const T x, const T\
    \ y) {\n    return y == 0 ? x : gcd(y, x % y);\n}\n\n// a x + b y = gcd(a, b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\u3057\u3066\
    , (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T,\
    \ T, T> Extended_Euclid(T a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while\
    \ (b) {\n        auto [q, r] = divmod(a, b);\n        a = b;\n        b = r;\n\
    \        tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v,\
    \ u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrtl(N);\n\
    \    while ((x + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\
    \n    return x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\
    \u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return\
    \ isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\
    \u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x =\
    \ isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line 64 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class...\
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
    \ get_bits(x, bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\
    \u3093\u304B\u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\
    \u529B\u3059\u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x));\
    \ }\n#line 73 \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 2 \"Algebra/modint.hpp\"\n\n#line 4 \"Algebra/modint.hpp\"\n\
    \ntemplate<int M>\nclass modint {\n    public:\n    static constexpr int _mod\
    \ = M; \n    uint64_t x;\n\n    public:\n    static constexpr int mod() { return\
    \ _mod; }\n\n    static modint raw(int v) {\n        modint a;\n        a.x =\
    \ v;\n        return a;\n    }\n\n    // \u521D\u671F\u5316\n    constexpr modint():\
    \ x(0) {}\n    constexpr modint(int64_t a) {\n        int64_t w = (int64_t)(a)\
    \ % mod();\n        if (w < 0) { w += mod(); }\n        x = w;\n    }\n\n    //\
    \ \u30DE\u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x);\
    \ }\n\n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n       \
    \ if ((x += b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\n    friend\
    \ modint operator+(const modint &x, const modint &y) { return modint(x) += y;\
    \ }\n\n    // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n       \
    \ if ((x += mod() - b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\
    \n    friend modint operator-(const modint &x, const modint &y) { return modint(x)\
    \ -= y; }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n \
    \       (x *= b.x) %= mod();\n        return *this;\n    }\n\n    friend modint\
    \ operator*(const modint &x, const modint &y) { return modint(x) *= y; }\n   \
    \ friend modint operator*(const int &x, const modint &y) { return modint(x) *=\
    \ y; }\n    friend modint operator*(const ll &x, const modint &y) { return modint(x)\
    \ *= y; }\n\n    // \u9664\u6CD5\n    modint& operator/=(const modint &b){ return\
    \ (*this) *= b.inverse(); }\n\n    friend modint operator/(const modint &x, const\
    \ modint &y) { return modint(x) /= y; }\n\n    modint inverse() const {\n    \
    \    int64_t s = 1, t = 0;\n        int64_t a = x, b = mod();\n\n        while\
    \ (b > 0) {\n            int64_t q = a / b;\n\n            a -= q * b; swap(a,\
    \ b);\n            s -= q * t; swap(s, t);\n        }\n\n        assert (a ==\
    \ 1);\n\n        return modint(s);\n    }\n\n    // \u6BD4\u8F03\n    friend bool\
    \ operator==(const modint &a, const modint &b) { return (a.x == b.x); }\n    friend\
    \ bool operator==(const modint &a, const int &b) { return a.x == safe_mod(b, mod());\
    \ }\n    friend bool operator!=(const modint &a, const modint &b) { return (a.x\
    \ != b.x); }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream &is,\
    \ modint &a) {\n        int64_t x;\n        is >> x;\n        a.x = safe_mod(x,\
    \ mod());\n        return is;\n    }\n\n    // \u51FA\u529B\n    friend ostream\
    \ &operator<<(ostream &os, const modint &a) { return os << a.x; }\n\n    bool\
    \ is_zero() const { return x == 0; }\n    bool is_member(ll a) const { return\
    \ x == (a % mod() + mod()) % mod(); }\n};\n\ntemplate<typename T>\nstruct is_modint\
    \ : std::false_type {};\n\ntemplate<int M>\nstruct is_modint<modint<M>> : std::true_type\
    \ {};\n\ntemplate<typename Mint>\nrequires is_modint<Mint>::value\nMint pow(Mint\
    \ x, long long n) {\n    if (n < 0) { return pow(x, -n).inverse(); }\n\n    Mint\
    \ res(1);\n    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n      \
    \  x *= x;\n    }\n\n    return res;\n}\n#line 2 \"Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp\"\
    \n\n#line 2 \"Counting/Combination_Calculator.hpp\"\n\n#line 4 \"Counting/Combination_Calculator.hpp\"\
    \n\ntemplate<typename mint>\nclass Combination_Calculator {\n    private:\n  \
    \  vector<mint> _fact, _fact_inv;\n\n    void resize(const int m) {\n        if\
    \ (m < _fact.size()) { return; }\n\n        int current_size = _fact.size();\n\
    \        int next_size = min(max(2 * current_size, m + 1), mint::mod());\n\n \
    \       _fact.resize(next_size);\n        _fact_inv.resize(next_size);\n\n   \
    \     for (int k = current_size; k < next_size; k++) {\n            _fact[k] =\
    \ k * _fact[k - 1];\n        }\n\n        _fact_inv.back() = _fact.back().inverse();\n\
    \n        for (int k = next_size - 2; k >= current_size; --k) {\n            _fact_inv[k]\
    \ = (k + 1) * _fact_inv[k + 1];\n        }\n    }\n\n    public:\n    /**\n  \
    \   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF: \u521D\u671F\u30B5\u30A4\
    \u30BAn\u307E\u3067\u968E\u4E57\u30FB\u9006\u968E\u4E57\u3092\u8A08\u7B97\u3059\
    \u308B\n     * @param n \u521D\u671F\u8A08\u7B97\u306E\u4E0A\u9650\n     */\n\
    \    Combination_Calculator(const int n) {\n        _fact.emplace_back(1); _fact.emplace_back(1);\n\
    \        _fact_inv.emplace_back(1); _fact_inv.emplace_back(1);\n\n        resize(n);\n\
    \    }\n\n    Combination_Calculator(): Combination_Calculator(0) {}\n\n    /**\n\
    \     * @brief k! \u3092\u53D6\u5F97\n     */\n    mint fact(const int k) {\n\
    \        resize(k);\n        return _fact[k];\n    }\n\n    /**\n     * @brief\
    \ (k!)^(-1) \u3092\u53D6\u5F97\n     */\n    mint fact_inv(const int k) {\n  \
    \      resize(k);\n        return _fact_inv[k];\n    }\n\n    /**\n     * @brief\
    \ k \u306E\u9006\u5143 k^(-1) \u3092\u6C42\u3081\u308B\n     * @param k \u9006\
    \u5143\u3092\u6C42\u3081\u305F\u3044\u6570\n     */\n    mint inv(const int k)\
    \ {\n        if (k <= 0) { return 0; }\n\n        resize(k);\n        return _fact_inv[k]\
    \ * _fact[k - 1];\n    }\n\n    /**\n     * @brief \u7D44\u307F\u5408\u308F\u305B\
    \ nCk \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint nCr(const int n, const\
    \ int r) {\n        if (!(0 <= r && r <= n)) { return 0; }\n        resize(n);\n\
    \        return _fact[n] * _fact_inv[r] * _fact_inv[n - r];\n    }\n\n    /**\n\
    \     * @brief \u9806\u5217 nPk \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint\
    \ nPr(const int n, const int r) {\n        if (!(0 <= r && r <= n)) { return 0;\
    \ }\n        resize(n);\n        return _fact[n] * _fact_inv[n - r];\n    }\n\n\
    \    /**\n     * @brief \u91CD\u8907\u7D44\u5408\u305B nHk \u3092\u8A08\u7B97\u3059\
    \u308B\n     */\n    mint nHr(const int n, const int r) {\n        if (n == 0\
    \ && r == 0) { return 1; }\n\n        return nCr(n + r - 1, r);\n    }\n\n   \
    \ /**\n     * @brief \u591A\u9805\u4FC2\u6570 (k_sum)! / (k1! * k2! * ...) \u3092\
    \u8A08\u7B97\u3059\u308B\n     */\n    mint multinomial_coefficient(const vector<int>\
    \ &ks) {\n        int k_sum = 0;\n        mint lower = 1;\n        for (int k:\
    \ ks) {\n            k_sum += k;\n            lower *= _fact_inv[k];\n       \
    \ }\n\n        resize(k_sum);\n\n        mint upper = _fact[k_sum];\n\n      \
    \  return upper * lower;\n    }\n\n    mint catalan(const int n) {\n        if\
    \ (n < 0) { return 0; }\n        resize(2 * n);\n        return _fact[2 * n] *\
    \ _fact_inv[n + 1] * _fact_inv[n];\n    }\n};\n#line 2 \"Math/Enumerate_Geometrics.hpp\"\
    \n\n#line 4 \"Math/Enumerate_Geometrics.hpp\"\n\ntemplate<typename F>\nvector<F>\
    \ Enumerate_Geometrics(const F a, const F r, const int n) {\n    vector<F> res(n\
    \ + 1);\n    res[0] = a;\n    for (int k = 1; k <= n; ++k) res[k] = r * res[k\
    \ - 1];\n\n    return res;\n}\ntemplate<typename F>\nvector<F> Enumerate_Geometrics(const\
    \ F r, const int n) {\n    return Enumerate_Geometrics(F(1), r, n);\n}\n#line\
    \ 2 \"Math/Enumerate_Powers.hpp\"\n\n#line 2 \"Integer/Smallest_Prime_Factor.hpp\"\
    \n\n#line 4 \"Integer/Smallest_Prime_Factor.hpp\"\n\nnamespace prime {\n    class\
    \ Smallest_Prime_Factor {\n        private:\n        vector<ll> spf; // smallest\
    \ prime factor\n\n        public:\n        Smallest_Prime_Factor(int N): spf(N\
    \ + 1, 1) {\n            if (N <= 1) return;\n\n            for (int x = 2; x\
    \ <= N; x += 2) spf[x] = 2;\n            for (int x = 3; x <= N; x += 6) spf[x]\
    \ = 3;\n\n            vector<int> primes{2, 3};\n            bool parity = 0;\n\
    \            for (int x = 5; x <= N; x += parity ? 4 : 2, parity ^= true) {\n\
    \                if (spf[x] == 1) {\n                    spf[x] = x;\n       \
    \             primes.emplace_back(x);\n                }\n\n                for\
    \ (int p: primes) {\n                    unless (x <= N / p) break;\n\n      \
    \              spf[x * p] = p;\n                    if (p == spf[x]) break;\n\
    \                }\n            }\n        }\n\n        constexpr inline int smallest_prime_factor(int\
    \ x) const { return spf[x]; }\n        \n        /**\n         * @brief \u6574\
    \u6570 x \u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n         */\n        constexpr inline int operator[](int x) const { return spf[x];\
    \ }\n\n        vector<pair<long long, long long>> prime_factorization(int n) {\n\
    \            if (n == 0)  { return vector<pair<long long, long long>>{ make_pair(0,\
    \ 1) }; }\n\n            vector<pair<long long, long long>> factors;\n       \
    \     if (n < 0) {\n                factors.emplace_back(-1, 1);\n           \
    \     n = -n;\n            }\n\n            while (n > 1) {\n                int\
    \ p = spf[n];\n                int e = 0;\n                while (spf[n] == p)\
    \ {\n                    e ++;\n                    n /= p;\n                }\n\
    \n                factors.emplace_back(p, e);\n            }\n\n            return\
    \ factors;\n        }\n    };\n}\n#line 5 \"Math/Enumerate_Powers.hpp\"\n\n/**\n\
    \ * @brief 0^k, 1^k, ..., n^k \u306E\u5217\u6319\n * @details \u6700\u5C0F\u7D20\
    \u56E0\u6570 (SPF) \u3092\u7528\u3044\u3066\u30010 \u304B\u3089 n \u307E\u3067\
    \u306E\u6574\u6570\u306E k \u4E57\u3092 O(n + \\pi(n) \\log k) \u3067\u8A08\u7B97\
    \u3059\u308B.\n * @tparam F \u5024\u306E\u578B (modint \u306A\u3069)\n * @param\
    \ n \u6700\u5927\u5024\n * @param k \u6307\u6570\n * @return vector<F> \u9577\u3055\
    \ n + 1 \u306E\u914D\u5217.res[i] = i^k.\n */\ntemplate<typename F>\nvector<F>\
    \ Enumerate_Powers(const int n, const ll k) {\n    vector<F> powers(n + 1);\n\
    \    powers[0] = (k == 0) ? F(1) : F(0);\n\n    // \u3053\u306E\u5F8C, n >= 1\
    \ \u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u90E8\u5206\u304C\u3042\u308B\u305F\
    \u3081, n = 0 \u3092\u4F8B\u5916\u51E6\u7406\n    if (n == 0) return powers;\n\
    \n    powers[1] = F(1);\n    auto spf = prime::Smallest_Prime_Factor(n);\n\n \
    \   for (int x = 2; x <= n; ++x) {\n        int p = spf[x];\n        if (p ==\
    \ x) {\n            // x \u304C\u7D20\u6570\u306E\u3068\u304D\u306F\u305D\u306E\
    \u307E\u307E\u8A08\u7B97\n            powers[x] = pow(F(x), k);\n        } else\
    \ {\n            // x \u304C\u5408\u6210\u6570\u306E\u3068\u304D, x \u306E 2 \u4EE5\
    \u4E0A x \u672A\u6E80\u306E\u7D04\u6570\u306E 1 \u3064\u3092 d \u3068\u3059\u308B\
    \u3068,\n            // x = d * (x / d) \u3088\u308A, x^k = d^k * (x / d)^k \u3067\
    \u3042\u308B.\n            // \u3053\u3053\u3067\u306F, d = p (\u6700\u5C0F\u7D20\
    \u56E0\u6570) \u3068\u3057\u3066\u3044\u308B.\n            powers[x] = powers[p]\
    \ * powers[x / p];\n        }\n    }\n    return powers;\n}\n#line 7 \"Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp\"\
    \n\ntemplate<typename F>\nF Sum_of_Exponential_Times_Polynomial_Limit(const F\
    \ r, const int d) {\n    assert(r != F(1));\n\n    vector<F> S(d + 2);\n    {\n\
    \        vector<F> powers = Enumerate_Powers<F>(d + 2, d);\n        F r_pow =\
    \ 1;\n        S[0] = powers[0];\n        for (int k = 1; k <= d + 1; ++k) {\n\
    \            r_pow *= r;\n            S[k] = S[k - 1] + powers[k] * r_pow;\n \
    \       }\n        vector<F>().swap(powers);\n    }\n\n    F P_1 = 0; // \u591A\
    \u9805\u5F0F P(x) \u306E x=1 \u306B\u304A\u3051\u308B\u5024\n    {\n        F\
    \ comb = 1;\n        F r_pow = 1;\n        for (int k = 0; k <= d + 1; ++k) {\n\
    \            F term = comb * r_pow * S[d + 1 - k];\n            is_even(k) ? P_1\
    \ += term : P_1 -= term;\n            if (k < d + 1) {\n                comb *=\
    \ F(d + 1 - k);\n                comb /= F(k + 1);\n                r_pow *= r;\n\
    \            }\n        }\n    }\n\n    return P_1 / pow(1 - r, d + 1);\n}\n#line\
    \ 6 \"verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nmint verify() {\n    mint r; int d;\n \
    \   cin >> r >> d;\n    return Sum_of_Exponential_Times_Polynomial_Limit(r, d);\n\
    }\n\nint main() {\n    cout << verify() << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include \"../../../template/template.hpp\"\n#include \"../../../Algebra/modint.hpp\"\
    \n#include \"../../../Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp\"\
    \n\nusing mint = modint<998244353>;\n\nmint verify() {\n    mint r; int d;\n \
    \   cin >> r >> d;\n    return Sum_of_Exponential_Times_Polynomial_Limit(r, d);\n\
    }\n\nint main() {\n    cout << verify() << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Algebra/modint.hpp
  - Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp
  - Counting/Combination_Calculator.hpp
  - Math/Enumerate_Geometrics.hpp
  - Math/Enumerate_Powers.hpp
  - Integer/Smallest_Prime_Factor.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
  requiredBy: []
  timestamp: '2026-04-19 12:32:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
- /verify/verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp.html
title: verify/yosupo_library_checker/other/Sum_of_Exponential_Times_Polynomial_Limit.test.cpp
---
