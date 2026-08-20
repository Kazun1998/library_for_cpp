---
data:
  _extendedDependsOn:
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
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "[L, R] \u4E0A\u3067\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\
      \u6761\u4EF6 cond \u306B\u5BFE\u3057\u3066, cond(x) \u304C true \u306B\u306A\
      \u308B\u6700\u5C0F\u306E\u6574\u6570 x \u3092\u4E8C\u5206\u63A2\u7D22\u3067\u6C42\
      \u3081\u308B."
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
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
    \    }\n};\n#line 2 \"Binary_Search/General_Integer.hpp\"\n\n\n/// @brief [L,\
    \ R] \u4E0A\u3067\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u6761\u4EF6 cond \u306B\
    \u5BFE\u3057\u3066, cond(x) \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E\u6574\
    \u6570 x \u3092\u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B.\n/// @tparam\
    \ T \u6574\u6570\u578B\n/// @param L: \u4E0B\u7AEF\n/// @param R: \u4E0A\u7AEF\
    \n/// @param cond: [L, R] \u4E0A\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u6761\
    \u4EF6. T \u3092\u53D7\u3051\u53D6\u308A bool \u3092\u8FD4\u3059\u547C\u3073\u51FA\
    \u3057\u53EF\u80FD\u306A\u5024.\n/// @param default_value: cond(R) \u304C false\
    \ \u306E\u6642\u306E\u8FD4\u308A\u5024\n/// @return cond(x) \u304C true \u306B\
    \u306A\u308B\u6700\u5C0F\u306E\u6574\u6570 x. \u305F\u3060\u3057, cond(R) \u304C\
    \ false \u306E\u5834\u5408\u306F default_value \u3092\u8FD4\u3059.\n/// @note\
    \ L <= R \u3067\u3042\u308B\u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B.\n\
    template<typename T>\nT General_Binary_Increase_Search_Integer(T L, T R, const\
    \ auto& cond, T default_value) {\n    assert(L <= R);\n\n    // \u4F8B\u5916\u30B1\
    \u30FC\u30B9\u306E\u51E6\u7406\n    // R \u3067\u3082 false \u2192 \u7570\u5E38\
    \u5024\n    unless(cond(R)) { return default_value; }\n    // L \u306B\u3066 true\
    \ \u2192 L\n    if(cond(L)) { return L; }\n\n    // \u63A2\u7D22\u30D1\u30FC\u30C8\
    \n    while (R - L > 1) {\n        T C = midpoint(L, R);\n        cond(C) ? R\
    \ = C : L = C;\n    }\n\n    return R;\n}\n\n/// @brief [L, R] \u4E0A\u3067\u5E83\
    \u7FA9\u5358\u8ABF\u6E1B\u5C11\u306A\u6761\u4EF6 cond \u306B\u5BFE\u3057\u3066\
    , cond(x) \u304C true \u306B\u306A\u308B\u6700\u5927\u306E\u6574\u6570 x \u3092\
    \u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B.\n/// @tparam T \u6574\u6570\u578B\
    \n/// @param L: \u4E0B\u7AEF\n/// @param R: \u4E0A\u7AEF\n/// @param cond: [L,\
    \ R] \u4E0A\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306A\u6761\u4EF6. T \u3092\u53D7\
    \u3051\u53D6\u308A bool \u3092\u8FD4\u3059\u547C\u3073\u51FA\u3057\u53EF\u80FD\
    \u306A\u5024.\n/// @param default_value: cond(L) \u304C false \u306E\u6642\u306E\
    \u8FD4\u308A\u5024\n/// @return cond(x) \u304C true \u306B\u306A\u308B\u6700\u5927\
    \u306E\u6574\u6570 x. \u305F\u3060\u3057, cond(L) \u304C false \u306E\u5834\u5408\
    \u306F default_value \u3092\u8FD4\u3059.\n/// @note L <= R \u3067\u3042\u308B\u3053\
    \u3068\u3092\u524D\u63D0\u3068\u3059\u308B.\ntemplate<typename T>\nT General_Binary_Decrease_Search_Integer(T\
    \ L, T R, const auto& cond, T default_value) {\n    assert(L <= R);\n\n    //\
    \ \u4F8B\u5916\u30B1\u30FC\u30B9\u306E\u51E6\u7406\n    // L \u3067\u3082 false\
    \ \u2192 \u7570\u5E38\u5024\n    unless(cond(L)) { return default_value; }\n \
    \   // R \u306B\u3066 true \u2192 R\n    if(cond(R)) { return R; }\n\n    // \u63A2\
    \u7D22\u30D1\u30FC\u30C8\n    while (R - L > 1) {\n        T C = midpoint(L, R);\n\
    \        cond(C) ? L = C : R = C;\n    }\n\n    return L;\n}\n"
  code: "#include\"../template/template.hpp\"\n\n\n/// @brief [L, R] \u4E0A\u3067\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u6761\u4EF6 cond \u306B\u5BFE\u3057\u3066\
    , cond(x) \u304C true \u306B\u306A\u308B\u6700\u5C0F\u306E\u6574\u6570 x \u3092\
    \u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B.\n/// @tparam T \u6574\u6570\u578B\
    \n/// @param L: \u4E0B\u7AEF\n/// @param R: \u4E0A\u7AEF\n/// @param cond: [L,\
    \ R] \u4E0A\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u6761\u4EF6. T \u3092\u53D7\
    \u3051\u53D6\u308A bool \u3092\u8FD4\u3059\u547C\u3073\u51FA\u3057\u53EF\u80FD\
    \u306A\u5024.\n/// @param default_value: cond(R) \u304C false \u306E\u6642\u306E\
    \u8FD4\u308A\u5024\n/// @return cond(x) \u304C true \u306B\u306A\u308B\u6700\u5C0F\
    \u306E\u6574\u6570 x. \u305F\u3060\u3057, cond(R) \u304C false \u306E\u5834\u5408\
    \u306F default_value \u3092\u8FD4\u3059.\n/// @note L <= R \u3067\u3042\u308B\u3053\
    \u3068\u3092\u524D\u63D0\u3068\u3059\u308B.\ntemplate<typename T>\nT General_Binary_Increase_Search_Integer(T\
    \ L, T R, const auto& cond, T default_value) {\n    assert(L <= R);\n\n    //\
    \ \u4F8B\u5916\u30B1\u30FC\u30B9\u306E\u51E6\u7406\n    // R \u3067\u3082 false\
    \ \u2192 \u7570\u5E38\u5024\n    unless(cond(R)) { return default_value; }\n \
    \   // L \u306B\u3066 true \u2192 L\n    if(cond(L)) { return L; }\n\n    // \u63A2\
    \u7D22\u30D1\u30FC\u30C8\n    while (R - L > 1) {\n        T C = midpoint(L, R);\n\
    \        cond(C) ? R = C : L = C;\n    }\n\n    return R;\n}\n\n/// @brief [L,\
    \ R] \u4E0A\u3067\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306A\u6761\u4EF6 cond \u306B\
    \u5BFE\u3057\u3066, cond(x) \u304C true \u306B\u306A\u308B\u6700\u5927\u306E\u6574\
    \u6570 x \u3092\u4E8C\u5206\u63A2\u7D22\u3067\u6C42\u3081\u308B.\n/// @tparam\
    \ T \u6574\u6570\u578B\n/// @param L: \u4E0B\u7AEF\n/// @param R: \u4E0A\u7AEF\
    \n/// @param cond: [L, R] \u4E0A\u5E83\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306A\u6761\
    \u4EF6. T \u3092\u53D7\u3051\u53D6\u308A bool \u3092\u8FD4\u3059\u547C\u3073\u51FA\
    \u3057\u53EF\u80FD\u306A\u5024.\n/// @param default_value: cond(L) \u304C false\
    \ \u306E\u6642\u306E\u8FD4\u308A\u5024\n/// @return cond(x) \u304C true \u306B\
    \u306A\u308B\u6700\u5927\u306E\u6574\u6570 x. \u305F\u3060\u3057, cond(L) \u304C\
    \ false \u306E\u5834\u5408\u306F default_value \u3092\u8FD4\u3059.\n/// @note\
    \ L <= R \u3067\u3042\u308B\u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B.\n\
    template<typename T>\nT General_Binary_Decrease_Search_Integer(T L, T R, const\
    \ auto& cond, T default_value) {\n    assert(L <= R);\n\n    // \u4F8B\u5916\u30B1\
    \u30FC\u30B9\u306E\u51E6\u7406\n    // L \u3067\u3082 false \u2192 \u7570\u5E38\
    \u5024\n    unless(cond(L)) { return default_value; }\n    // R \u306B\u3066 true\
    \ \u2192 R\n    if(cond(R)) { return R; }\n\n    // \u63A2\u7D22\u30D1\u30FC\u30C8\
    \n    while (R - L > 1) {\n        T C = midpoint(L, R);\n        cond(C) ? L\
    \ = C : R = C;\n    }\n\n    return L;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Binary_Search/General_Integer.hpp
  requiredBy: []
  timestamp: '2026-08-20 00:54:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Binary_Search/General_Integer.hpp
layout: document
title: "\u6574\u6570\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22\u306B\u3088\u308B\u5883\u76EE\
  \u306E\u8A08\u7B97"
---

## Outline

整数 $x$ に関する条件 $\operatorname{cond}(x)$ について, 以下を求める.

* $\operatorname{cond}$ が単調増加の場合 : $\operatorname{cond}(x)=\mathbb{T}$ になるような最小の整数 $x$.
* $\operatorname{cond}$ が単調減少の場合 : $\operatorname{cond}(x)=\mathbb{T}$ になるような最大の整数 $x$.

## Definition

$\mathbb{Z}$ 上の条件 $\operatorname{cond}: \mathbb{Z} \to \\{\mathbb{T}, \mathbb{F}\\}$ について, 以下を定義する.

* 以下を満たすとき, $\operatorname{cond}$ は単調増加であるという
  * $\forall x \in \mathbb{Z};\,\operatorname{cond}(x) = \mathbb{T} \Rightarrow \left(\forall y \geq x;\, \operatorname{cond}(y)=\mathbb{T} \right)$.
* 以下を満たすとき, $\operatorname{cond}$ は単調減少であるという
  * $\forall x \in \mathbb{Z};\,\operatorname{cond}(x) = \mathbb{F} \Rightarrow \left(\forall y \geq x;\,\operatorname{cond}(y)=\mathbb{F} \right)$.
* $\operatorname{cond}$ が単調増加または単調減少であるとき, $\operatorname{cond}$ は単調であるという.

## Theory

単調増加である $\operatorname{cond}$ に対して, $\operatorname{cond}(x) = \mathbb{T}$ となる最小の $x \in \mathbb{Z}$ を $X$ として, $X$ を求める.

このとき, 以下のアルゴリズムを適用させることで高速に求められる.

1. $L_0, R_0 \in \mathbb{Z}$ を $\operatorname{cond}(L_0) = \mathbb{F}, \operatorname{cond}(R_0) = \mathbb{T}$ であるとする. このとき, 単調性から, $L_0 \lt X \leq R_0$ が保証されている.
2. $L \gets L_0, R \gets R_0$ とする.
3. $R - L > 1$ である限り, 以下を繰り返し行う.
    * $C:=\left \lfloor \dfrac{L+R}{2} \right \rfloor$ とする.
    * $\operatorname{cond}(C)=\mathbb{T}$ ならば, $L \lt X \leq C$ であることが分かる. よって, $R \gets C$ とする.
    * $\operatorname{cond}(C)=\mathbb{F}$ ならば, $C \lt X \leq R$ であることが分かる. よって, $L \gets C$ とする.
4. イテレートの条件と初期値の定め方から, ここに来たときは $R - L = 1$ である. よって, $L \lt X \leq R$ となる整数 $X$ は $X = R$ に限られる. 従って, $R$ を出力すれば良い.

このアルゴリズムにおいて, イテレート $1$ 回で $(R-L)$ はもともとの約半分になる.

よって, $X$ を $O(\log (R-L))$ 回のイテレートで求められ, $\operatorname{cond}$ の $1$ 回当たりの計算量を $O(K)$ とすると, 合計で $O(K \log(R-L))$ 時間で $X$ を求められる.

## Contents

$\textrm{cond}$ の時間計算量を $O(K)$ 時間とする.

### General_Binary_Increase_Search_Integer

```cpp
template<typename T>
T General_Binary_Increase_Search_Integer(T L, T R, const auto& cond, T default_value)
```

* $[L, R]$ 上で単調増加な条件 $\mathrm{cond}$ に対し, $\mathrm{cond}(x)$ が真となる最小の整数 $x$ を二分探索で求める.
* **引数**
  * $L$ : 探索範囲の下端.
  * $R$ : 探索範囲の上端.
  * $\textrm{cond}$: $[L, R]$ 上の単調増加な関数.
  * `default_value`: $\mathrm{cond}(R)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(R)$ が偽の場合は `default_value` である.
  * そうでない場合は $\mathrm{cond}(x)$ が真となる最小の整数 $x \in [L, R]$ である.
* **制約**
  * $L \leq R$.
* **計算量**
  * $O(K \log(R - L))$ 時間.

### General_Binary_Decrease_Search_Integer

```cpp
template<typename T>
T General_Binary_Decrease_Search_Integer(T L, T R, const auto& cond, T default_value)
```

* $[L, R]$ 上で単調減少な条件 $\mathrm{cond}$ に対し, $\mathrm{cond}(x)$ が真となる最大の整数 $x$ を二分探索で求める.
* **引数**
  * $L$ : 探索範囲の下端.
  * $R$ : 探索範囲の上端.
  * $\textrm{cond}$ : $[L, R]$ 上の単調減少な関数.
  * `default_value`: $\mathrm{cond}(L)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(L)$ が偽の場合は `default_value` である.
  * そうでない場合は $\mathrm{cond}(x)$ が真となる最大の整数 $x \in [L, R]$ である.
* **制約**
  * $L \leq R$.
* **計算量**
  * $O(K \log(R - L))$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/20| document の作成 |
|2025/09/24| 整数上の二分探索 実装 |
