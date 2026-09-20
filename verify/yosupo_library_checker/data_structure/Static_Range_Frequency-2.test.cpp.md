---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Interval_Query/Binary_Decomposer.hpp
    title: "\u4E8C\u5206\u6728\u5206\u5272"
  - icon: ':heavy_check_mark:'
    path: Interval_Query/Interval_Decomposer.hpp
    title: Interval Decomposer
  - icon: ':heavy_check_mark:'
    path: Interval_Query/Interval_Query.hpp
    title: Interval Query
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\
    \n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
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
    \n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nconstexpr ll intpow(ll x, ll\
    \ y) {\n    ll a = 1;\n    while (y) {\n        if (y & 1) { a *= x; }\n     \
    \   x *= x;\n        y >>= 1;\n    }\n    return a;\n}\n\nconstexpr ll pow(ll\
    \ x, ll y) { return intpow(x, y); }\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\
    \u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, integral\
    \ U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n        if (y\
    \ & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n    }\n\
    \n    return a;\n}\n\ntemplate<typename T>\nT sum(const vector<T> &X) {\n    T\
    \ y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\ntemplate<typename\
    \ T>\nT gcd(const T x, const T y) {\n    return y == 0 ? x : gcd(y, x % y);\n\
    }\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44\
    \ (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T a, T b) {\n    T s =\
    \ 1, t = 0, u = 0, v = 1;\n    while (b) {\n        auto [q, r] = divmod(a, b);\n\
    \        a = b;\n        b = r;\n        tie(s, t) = make_pair(t, s - q * t);\n\
    \        tie(u, v) = make_pair(v, u - q * v);\n    }\n\n    return make_tuple(s,\
    \ u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\
    \u306F, 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n    if (N <= 0) { return\
    \ 0; }\n\n    ll x = sqrtl(N);\n    while ((x + 1) * (x + 1) <= N) { x++; }\n\
    \    while (x * x > N) { x--; }\n\n    return x;\n}\n\n// floor(sqrt(N)) \u3092\
    \u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll\
    \ floor_sqrt(const ll &N) { return isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\
    \u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const\
    \ ll &N) {\n    ll x = isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line\
    \ 64 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\n//\
    \ \u5165\u51FA\u529B\n#line 4 \"template/inout.hpp\"\n\ntemplate<class... T>\n\
    void input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\
    \ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n  \
    \  cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\\n\";\n\
    }\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &P){\n   \
    \ os << P.first << \" \" << P.second;\n    return os;\n}\n\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &X){\n    for (auto &x: X) {\
    \ is >> x; }\n    return is;\n}\n\ntemplate<typename T, typename U = typename\
    \ T::iterator>\ntypename std::enable_if<!std::is_same<T, std::string>::value,\
    \ ostream&>::type\noperator<<(ostream &os, const T &container){\n    bool is_first\
    \ = true;\n    for (const auto &x : container) {\n        os << (is_first ? \"\
    \" : \" \") << x;\n        is_first = false;\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nstd::vector<T> input_vector(int n, int offset = 0) {\n    std::vector<T>\
    \ res;\n    // \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\
    \u4FDD\uFF08\u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n\
    \    // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
    \u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\n    res.assign(offset, T());\n\n\
    \    for (int i = 0; i < n; ++i) {\n        T el;\n        if (!(std::cin >> el))\
    \ break;\n        res.push_back(std::move(el));\n    }\n    return res;\n}\n\n\
    #line 63 \"template/inout.hpp\"\n\n// 1. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA\
    \ n \u306E 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\ntemplate<typename T>\nauto\
    \ make_multi_dimensional_vector(int n) {\n    return std::vector<T>(n);\n}\n\n\
    // 2. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA n \u3067\u521D\u671F\u5024 val \u3092\
    \u6301\u3064 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\uFF08\u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\uFF09\ntemplate<typename T>\nauto make_multi_dimensional_vector(int\
    \ n, T val) {\n    return std::vector<T>(n, val);\n}\n\n// 3. \u518D\u5E30\uFF1A\
    \u6B21\u5143\u3092\u524A\u308B\ntemplate<typename T, typename... Args>\nauto make_multi_dimensional_vector(int\
    \ n, Args... args) {\n    auto inner = make_multi_dimensional_vector<T>(args...);\n\
    \    return std::vector<decltype(inner)>(n, inner);\n}\n#line 67 \"template/template.hpp\"\
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
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 70 \"template/template.hpp\"\n\n// bitop\n\
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
    \ bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\u3093\u304B\
    \u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\u529B\u3059\
    \u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x)); }\n#line 73\
    \ \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 2 \"Interval_Query/Interval_Query.hpp\"\n\n#line 2 \"Interval_Query/Interval_Decomposer.hpp\"\
    \n\n#line 4 \"Interval_Query/Interval_Decomposer.hpp\"\n\n/// @brief \u533A\u9593\
    \ [0, N) \u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u533A\u9593\u5206\u89E3\u306E\
    \u62BD\u8C61\u57FA\u5E95\u30AF\u30E9\u30B9.\nclass Interval_Decomposer {\n   \
    \ protected:\n    int n;\n\n    public:\n    /// @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF.\n    /// @param n \u5168\u4F53\u306E\u8981\u7D20\u6570.\n\
    \    explicit Interval_Decomposer(int n): n(n) {}\n\n    virtual ~Interval_Decomposer()\
    \ = default;\n\n    /// @brief \u5168\u4F53\u306E\u8981\u7D20\u6570\u3092\u8FD4\
    \u3059.\n    int size() const { return n; }\n\n    /// @brief \u534A\u958B\u533A\
    \u9593 [l, r) \u3092\u8A08\u7B97\u306B\u5FC5\u8981\u306A\u90E8\u5206\u533A\u9593\
    \u3078\u5206\u89E3\u3059\u308B.\n    /// @param l \u533A\u9593\u306E\u5DE6\u7AEF\
    .\n    /// @param r \u533A\u9593\u306E\u53F3\u7AEF.\n    /// @return (depth, start,\
    \ end) \u306E\u30EA\u30B9\u30C8. depth \u306E\u610F\u5473\u306F\u6D3E\u751F\u30AF\
    \u30E9\u30B9\u306B\u4F9D\u5B58\u3059\u308B.\n    virtual vector<tuple<int, int,\
    \ int>> decompose(int l, int r) const = 0;\n\n    /// @brief \u69CB\u9020\u5168\
    \u4F53\u306B\u5B58\u5728\u3059\u308B\u5168\u30CE\u30FC\u30C9\u3092\u5217\u6319\
    \u3059\u308B.\n    /// @return (depth, start, end) \u306E\u30EA\u30B9\u30C8.\n\
    \    virtual vector<tuple<int, int, int>> all_nodes() const = 0;\n\n    /// @brief\
    \ \u8981\u7D20 i \u3092\u542B\u3080\u5168\u3066\u306E\u30CE\u30FC\u30C9\u3092\u5217\
    \u6319\u3059\u308B.\n    /// @param i \u8981\u7D20\u306E\u4F4D\u7F6E.\n    ///\
    \ @return (depth, start, end) \u306E\u30EA\u30B9\u30C8.\n    virtual vector<tuple<int,\
    \ int, int>> ancestors(int i) const = 0;\n\n    /// @brief \u69CB\u9020\u5168\u4F53\
    \u306B\u5B58\u5728\u3059\u308B\u30CE\u30FC\u30C9\u306E\u7DCF\u6570\u3092\u8FD4\
    \u3059.\n    virtual int node_count() const = 0;\n\n    /// @brief \u30CE\u30FC\
    \u30C9 (depth, start) \u3092 [0, node_count()) \u306E\u4E00\u610F\u306A\u6DFB\u5B57\
    \u306B\u5909\u63DB\u3059\u308B.\n    /// @param depth \u30CE\u30FC\u30C9\u306E\
    \u6DF1\u3055.\n    /// @param start \u30CE\u30FC\u30C9\u304C\u62C5\u5F53\u3059\
    \u308B\u533A\u9593\u306E\u5DE6\u7AEF.\n    virtual int node_index(int depth, int\
    \ start) const = 0;\n\n    /// @brief \u30CE\u30FC\u30C9 (depth, start) \u306E\
    \u5B50\u30CE\u30FC\u30C9\u3092\u5217\u6319\u3059\u308B. \u5B50\u3092\u6301\u305F\
    \u306A\u3044\u5834\u5408 (\u8449) \u306F\u7A7A\u3092\u8FD4\u3059.\n    /// @param\
    \ depth \u30CE\u30FC\u30C9\u306E\u6DF1\u3055.\n    /// @param start \u30CE\u30FC\
    \u30C9\u304C\u62C5\u5F53\u3059\u308B\u533A\u9593\u306E\u5DE6\u7AEF.\n    virtual\
    \ vector<tuple<int, int, int>> children(int depth, int start) const = 0;\n};\n\
    #line 4 \"Interval_Query/Interval_Query.hpp\"\n\n/// @brief Interval_Decomposer\
    \ \u306B\u3088\u308B\u533A\u9593\u5206\u89E3\u3092\u7528\u3044\u3066, \u4E00\u70B9\
    \u66F4\u65B0\u30FB\u533A\u9593\u30AF\u30A8\u30EA\u3092\u884C\u3046\u6C4E\u7528\
    \u30AF\u30E9\u30B9.\n/// @tparam T \u8981\u7D20\u306E\u578B.\n/// @tparam State\
    \ \u5404\u30CE\u30FC\u30C9\u304C\u6301\u3064\u5185\u90E8\u72B6\u614B\u306E\u578B\
    \ (\u4F8B: map, \u96C6\u8A08\u5024\u306A\u3069).\ntemplate <typename T, typename\
    \ State>\nclass Interval_Query {\n    private:\n    int n;\n    vector<T> data;\n\
    \    unique_ptr<Interval_Decomposer> decomposer;\n\n    vector<State> state;\n\
    \n    function<State(const vector<T> &)> build_state;\n    function<State(vector<State>\
    \ &)> merge_children;\n    function<void(State &, int, const T &, const T &)>\
    \ on_update;\n\n    /// @brief \u30CE\u30FC\u30C9 (depth, start, end) \u306E\u72B6\
    \u614B\u3092, \u5B50\u30CE\u30FC\u30C9\u304B\u3089\u518D\u5E30\u7684\u306B\u69CB\
    \u7BC9\u3059\u308B.\n    State build(int depth, int l, int r) {\n        auto\
    \ ch = decomposer->children(depth, l);\n\n        State s;\n        if (ch.empty())\
    \ {\n            vector<T> sub(data.begin() + l, data.begin() + r);\n        \
    \    s = build_state(sub);\n        } else {\n            vector<State> child_states;\n\
    \            child_states.reserve(ch.size());\n            for (auto [cd, cl,\
    \ cr] : ch) { child_states.push_back(build(cd, cl, cr)); }\n            s = merge_children(child_states);\n\
    \        }\n\n        state[decomposer->node_index(depth, l)] = s;\n        return\
    \ s;\n    }\n\n    public:\n    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF.\n    /// @param data \u521D\u671F\u5024.\n    /// @param decomposer \u533A\
    \u9593\u5206\u89E3\u3092\u62C5\u5F53\u3059\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8.\n    /// @param build_state \u8449\u30CE\u30FC\u30C9 (\u5B50\u3092\u6301\
    \u305F\u306A\u3044\u30CE\u30FC\u30C9) \u306E\u72B6\u614B\u3092, \u62C5\u5F53\u3059\
    \u308B\u8981\u7D20\u5217\u304B\u3089\u4F5C\u308B\u95A2\u6570.\n    /// @param\
    \ merge_children \u5B50\u30CE\u30FC\u30C9\u306E\u72B6\u614B\u306E\u30EA\u30B9\u30C8\
    \u304B\u3089, \u89AA\u30CE\u30FC\u30C9\u306E\u72B6\u614B\u3092\u4F5C\u308B\u95A2\
    \u6570.\n    /// @param on_update \u8981\u7D20 i \u304C before \u304B\u3089 after\
    \ \u306B\u5909\u5316\u3057\u305F\u3068\u304D\u306B, \u30CE\u30FC\u30C9\u306E\u72B6\
    \u614B\u3092\u66F4\u65B0\u3059\u308B\u95A2\u6570.\n    Interval_Query(\n     \
    \   const vector<T> &data,\n        unique_ptr<Interval_Decomposer> decomposer,\n\
    \        function<State(const vector<T> &)> build_state,\n        function<State(vector<State>\
    \ &)> merge_children,\n        function<void(State &, int, const T &, const T\
    \ &)> on_update\n    ):\n        n(data.size()), data(data), decomposer(move(decomposer)),\n\
    \        state(this->decomposer->node_count()),\n        build_state(move(build_state)),\
    \ merge_children(move(merge_children)), on_update(move(on_update)) {\n       \
    \ for (auto [depth, l, r] : this->decomposer->all_nodes()) {\n            if (depth\
    \ == 0) { build(depth, l, r); }\n        }\n    }\n\n    /// @brief \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059.\n    int size() const { return n; }\n\n    /// @brief\
    \ i \u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B.\n    const T\
    \ &get(int i) const { return data[i]; }\n\n    /// @brief \u7B2C i \u8981\u7D20\
    \u3092 x \u306B\u66F4\u65B0\u3059\u308B.\n    /// @param i \u66F4\u65B0\u5834\u6240\
    .\n    /// @param x \u66F4\u65B0\u5F8C\u306E\u8981\u7D20.\n    void update(int\
    \ i, const T &x) {\n        const T before = data[i];\n\n        for (auto [depth,\
    \ l, r] : decomposer->ancestors(i)) { on_update(state[decomposer->node_index(depth,\
    \ l)], i, before, x); }\n\n        data[i] = x;\n    }\n\n    /// @brief \u534A\
    \u958B\u533A\u9593 [l, r) \u306B\u304A\u3051\u308B\u30AF\u30A8\u30EA\u306E\u7D50\
    \u679C\u3092\u6C42\u3081\u308B.\n    /// @tparam R \u30AF\u30A8\u30EA\u306E\u8FD4\
    \u308A\u5024\u306E\u578B.\n    /// @param l \u533A\u9593\u306E\u5DE6\u7AEF.\n\
    \    /// @param r \u533A\u9593\u306E\u53F3\u7AEF.\n    /// @param representative\
    \ \u30CE\u30FC\u30C9\u306E\u72B6\u614B\u304B\u3089, \u30AF\u30A8\u30EA\u306E\u7D50\
    \u679C R \u3092\u53D6\u308A\u51FA\u3059\u95A2\u6570.\n    /// @param merge \u8907\
    \u6570\u306E\u30CE\u30FC\u30C9\u306E\u7D50\u679C R \u3092\u96C6\u7D04\u3059\u308B\
    \u95A2\u6570.\n    /// @param identity merge \u306B\u5BFE\u3059\u308B\u5358\u4F4D\
    \u5143.\n    template <typename R>\n    R query(\n        int l, int r,\n    \
    \    function<R(const State &)> representative,\n        function<R(R, R)> merge,\n\
    \        R identity\n    ) const {\n        R res = identity;\n        for (auto\
    \ [depth, lo, hi] : decomposer->decompose(l, r)) { res = merge(res, representative(state[decomposer->node_index(depth,\
    \ lo)])); }\n        return res;\n    }\n};\n#line 2 \"Interval_Query/Binary_Decomposer.hpp\"\
    \n\n#line 4 \"Interval_Query/Binary_Decomposer.hpp\"\n\n/// @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u578B (\u4E8C\u5206\u6728) \u306B\u3088\u308B\u533A\u9593\
    \u5206\u89E3. \u6839 [0, n) \u3092 depth=0 \u3068\u3057, mid = l + (r-l)/2 \u3067\
    \u518D\u5E30\u7684\u306B\u4E8C\u5206\u3059\u308B.\nclass Binary_Decomposer : public\
    \ Interval_Decomposer {\n    private:\n    vector<tuple<int, int, int>> nodes;\n\
    \    unordered_map<long long, int> index_map;\n\n    static long long key(int\
    \ depth, int start) { return (static_cast<long long>(depth) << 32) | static_cast<unsigned\
    \ int>(start); }\n\n    /// @brief \u30CE\u30FC\u30C9 [l, r) (\u6DF1\u3055 depth)\
    \ \u3092\u767B\u9332\u3057, \u5B50\u30CE\u30FC\u30C9\u3092\u518D\u5E30\u7684\u306B\
    \u69CB\u7BC9\u3059\u308B.\n    void build(int l, int r, int depth) {\n       \
    \ index_map[key(depth, l)] = static_cast<int>(nodes.size());\n        nodes.emplace_back(depth,\
    \ l, r);\n\n        if (r - l > 1) {\n            int mid = l + (r - l) / 2;\n\
    \            build(l, mid, depth + 1);\n            build(mid, r, depth + 1);\n\
    \        }\n    }\n\n    /// @brief \u534A\u958B\u533A\u9593 [l, r) \u3092, \u30CE\
    \u30FC\u30C9 [nl, nr) (\u6DF1\u3055 depth) \u4EE5\u4E0B\u306E\u90E8\u5206\u6728\
    \u3067\u5206\u89E3\u3059\u308B.\n    void decompose_rec(int l, int r, int nl,\
    \ int nr, int depth, vector<tuple<int, int, int>> &res) const {\n        if (r\
    \ <= nl || nr <= l) { return; }\n        if (l <= nl && nr <= r) {\n         \
    \   res.emplace_back(depth, nl, nr);\n            return;\n        }\n\n     \
    \   int mid = nl + (nr - nl) / 2;\n        decompose_rec(l, r, nl, mid, depth\
    \ + 1, res);\n        decompose_rec(l, r, mid, nr, depth + 1, res);\n    }\n\n\
    \    public:\n    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF.\n   \
    \ /// @param n \u5168\u4F53\u306E\u8981\u7D20\u6570.\n    explicit Binary_Decomposer(int\
    \ n): Interval_Decomposer(n) {\n        if (n > 0) { build(0, n, 0); }\n    }\n\
    \n    /// @brief \u534A\u958B\u533A\u9593 [l, r) \u3092\u8A08\u7B97\u306B\u5FC5\
    \u8981\u306A\u90E8\u5206\u533A\u9593\u3078\u5206\u89E3\u3059\u308B.\n    /// @param\
    \ l \u533A\u9593\u306E\u5DE6\u7AEF.\n    /// @param r \u533A\u9593\u306E\u53F3\
    \u7AEF.\n    /// @return (depth, start, end) \u306E\u30EA\u30B9\u30C8.\n    vector<tuple<int,\
    \ int, int>> decompose(int l, int r) const override {\n        vector<tuple<int,\
    \ int, int>> res;\n        if (l >= r) { return res; }\n\n        decompose_rec(l,\
    \ r, 0, n, 0, res);\n        return res;\n    }\n\n    /// @brief \u69CB\u9020\
    \u5168\u4F53\u306B\u5B58\u5728\u3059\u308B\u5168\u30CE\u30FC\u30C9\u3092\u5217\
    \u6319\u3059\u308B.\n    vector<tuple<int, int, int>> all_nodes() const override\
    \ { return nodes; }\n\n    /// @brief \u8981\u7D20 i \u3092\u542B\u3080\u5168\u3066\
    \u306E\u30CE\u30FC\u30C9 (\u6839\u304B\u3089\u8449\u307E\u3067\u306E\u7D4C\u8DEF\
    ) \u3092\u5217\u6319\u3059\u308B.\n    vector<tuple<int, int, int>> ancestors(int\
    \ i) const override {\n        vector<tuple<int, int, int>> res;\n\n        int\
    \ l = 0, r = n, depth = 0;\n        while (true) {\n            res.emplace_back(depth,\
    \ l, r);\n            if (r - l <= 1) { break; }\n\n            int mid = l +\
    \ (r - l) / 2;\n            if (i < mid) { r = mid; } else { l = mid; }\n    \
    \        depth++;\n        }\n\n        return res;\n    }\n\n    /// @brief \u30CE\
    \u30FC\u30C9\u306E\u7DCF\u6570\u3092\u8FD4\u3059.\n    int node_count() const\
    \ override { return static_cast<int>(nodes.size()); }\n\n    /// @brief \u30CE\
    \u30FC\u30C9 (depth, start) \u3092\u4E00\u610F\u306A\u6DFB\u5B57\u306B\u5909\u63DB\
    \u3059\u308B.\n    int node_index(int depth, int start) const override { return\
    \ index_map.at(key(depth, start)); }\n\n    /// @brief \u30CE\u30FC\u30C9 (depth,\
    \ start) \u306E\u5B50\u30CE\u30FC\u30C9\u3092\u5217\u6319\u3059\u308B. \u8449\
    \ (\u8981\u7D20\u65701) \u306E\u5834\u5408\u306F\u7A7A\u3092\u8FD4\u3059.\n  \
    \  vector<tuple<int, int, int>> children(int depth, int start) const override\
    \ {\n        vector<tuple<int, int, int>> res;\n\n        auto [d, l, r] = nodes[node_index(depth,\
    \ start)];\n        if (r - l <= 1) { return res; }\n\n        int mid = l + (r\
    \ - l) / 2;\n        res.emplace_back(depth + 1, l, mid);\n        res.emplace_back(depth\
    \ + 1, mid, r);\n        return res;\n    }\n};\n#line 6 \"verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp\"\
    \n\nusing State = unordered_map<int, int>;\n\nvector<int> verify() {\n    int\
    \ N, Q; cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0; i < N; ++i)\
    \ scanf(\"%d\", &a[i]);\n\n    Interval_Query<int, State> iq(\n        a,\n  \
    \      make_unique<Binary_Decomposer>(N),\n        [](const vector<int> &sub)\
    \ {\n            State s;\n            for (int v: sub) { s[v]++; }\n        \
    \    return s;\n        },\n        [](vector<State> &children) {\n          \
    \  // small-to-large: \u4E00\u756A\u5927\u304D\u3044 map \u306B\u6B8B\u308A\u3092\
    \ merge \u3059\u308B\n            int biggest = 0;\n            for (int i = 1;\
    \ i < (int)children.size(); i++) {\n                if (children[i].size() > children[biggest].size())\
    \ { biggest = i; }\n            }\n            State s = move(children[biggest]);\n\
    \            for (int i = 0; i < (int)children.size(); i++) {\n              \
    \  if (i == biggest) { continue; }\n                for (auto &[v, c]: children[i])\
    \ { s[v] += c; }\n            }\n            return s;\n        },\n        [](State\
    \ &s, int, const int &before, const int &after) {\n            if (--s[before]\
    \ == 0) { s.erase(before); }\n            s[after]++;\n        }\n    );\n\n \
    \   vector<int> ans(Q);\n    for (int q = 0; q < Q; ++q) {\n        int l, r,\
    \ x; scanf(\"%d%d%d\", &l, &r , &x);\n        ans[q] = iq.query<int>(l, r,\n \
    \           [x](const State &s) {\n                auto it = s.find(x);\n    \
    \            return it == s.end() ? 0 : it->second;\n            },\n        \
    \    [](int p, int qq) { return p + qq; },\n            0\n        );\n    }\n\
    \n    return ans;\n}\n\nint main() {\n    for (int val: verify()) {\n        printf(\"\
    %d\\n\", val);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include \"../../../template/template.hpp\"\n#include \"../../../Interval_Query/Interval_Query.hpp\"\
    \n#include \"../../../Interval_Query/Binary_Decomposer.hpp\"\n\nusing State =\
    \ unordered_map<int, int>;\n\nvector<int> verify() {\n    int N, Q; cin >> N >>\
    \ Q;\n    vector<int> a(N);\n    for (int i = 0; i < N; ++i) scanf(\"%d\", &a[i]);\n\
    \n    Interval_Query<int, State> iq(\n        a,\n        make_unique<Binary_Decomposer>(N),\n\
    \        [](const vector<int> &sub) {\n            State s;\n            for (int\
    \ v: sub) { s[v]++; }\n            return s;\n        },\n        [](vector<State>\
    \ &children) {\n            // small-to-large: \u4E00\u756A\u5927\u304D\u3044\
    \ map \u306B\u6B8B\u308A\u3092 merge \u3059\u308B\n            int biggest = 0;\n\
    \            for (int i = 1; i < (int)children.size(); i++) {\n              \
    \  if (children[i].size() > children[biggest].size()) { biggest = i; }\n     \
    \       }\n            State s = move(children[biggest]);\n            for (int\
    \ i = 0; i < (int)children.size(); i++) {\n                if (i == biggest) {\
    \ continue; }\n                for (auto &[v, c]: children[i]) { s[v] += c; }\n\
    \            }\n            return s;\n        },\n        [](State &s, int, const\
    \ int &before, const int &after) {\n            if (--s[before] == 0) { s.erase(before);\
    \ }\n            s[after]++;\n        }\n    );\n\n    vector<int> ans(Q);\n \
    \   for (int q = 0; q < Q; ++q) {\n        int l, r, x; scanf(\"%d%d%d\", &l,\
    \ &r , &x);\n        ans[q] = iq.query<int>(l, r,\n            [x](const State\
    \ &s) {\n                auto it = s.find(x);\n                return it == s.end()\
    \ ? 0 : it->second;\n            },\n            [](int p, int qq) { return p\
    \ + qq; },\n            0\n        );\n    }\n\n    return ans;\n}\n\nint main()\
    \ {\n    for (int val: verify()) {\n        printf(\"%d\\n\", val);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Interval_Query/Interval_Query.hpp
  - Interval_Query/Interval_Decomposer.hpp
  - Interval_Query/Binary_Decomposer.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp
  requiredBy: []
  timestamp: '2026-09-20 10:13:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp
- /verify/verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp.html
title: verify/yosupo_library_checker/data_structure/Static_Range_Frequency-2.test.cpp
---
