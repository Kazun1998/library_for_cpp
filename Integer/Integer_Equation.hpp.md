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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/original/Integer_Equation.test.cpp
    title: verify/original/Integer_Equation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "[l, +infty) \u4E0A\u306E\u975E\u5B9A\u6570\u591A\u9805\u5F0F\
      \ P (\u4FC2\u6570\u306F\u7B26\u53F7\u306A\u3057\u6574\u6570) \u306B\u5BFE\u3057\
      \u3066, P(x) = y \u3092\u6E80\u305F\u3059\u6574\u6570 x \u3092\u6C42\u3081\u308B\
      \ (\u7B26\u53F7\u306A\u3057\u6574\u6570\u7248)."
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Integer_Equation.hpp
  bundledCode: "#line 2 \"Integer/Integer_Equation.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Integer_Equation.hpp\n\
    \n#line 2 \"template/template.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/template.hpp\n\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <concepts>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <initializer_list>\n#include <iomanip>\n#include <ios>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n\
    #include <ostream>\n#include <optional>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 2 \"template/utility.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/utility.hpp\n\
    \nusing ll = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B\
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
    \ a.end()));\n}\n#line 63 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/math.hpp\n\
    \n// \u6F14\u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) {\
    \ return x + y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return\
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
    \ 66 \"template/template.hpp\"\n\n// inout\n#line 2 \"template/inout.hpp\"\n\n\
    // Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/inout.hpp\n\
    \n// \u5165\u51FA\u529B\n#line 8 \"template/inout.hpp\"\n\ntemplate<class... T>\n\
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
    #line 67 \"template/inout.hpp\"\n\n// 1. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA\
    \ n \u306E 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\ntemplate<typename T>\nauto\
    \ make_multi_dimensional_vector(int n) {\n    return std::vector<T>(n);\n}\n\n\
    // 2. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA n \u3067\u521D\u671F\u5024 val \u3092\
    \u6301\u3064 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\uFF08\u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\uFF09\ntemplate<typename T>\nauto make_multi_dimensional_vector(int\
    \ n, T val) {\n    return std::vector<T>(n, val);\n}\n\n// 3. \u518D\u5E30\uFF1A\
    \u6B21\u5143\u3092\u524A\u308B\ntemplate<typename T, typename... Args>\nauto make_multi_dimensional_vector(int\
    \ n, Args... args) {\n    auto inner = make_multi_dimensional_vector<T>(args...);\n\
    \    return std::vector<decltype(inner)>(n, inner);\n}\n#line 69 \"template/template.hpp\"\
    \n\n// macro\n#line 2 \"template/macro.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/macro.hpp\n\
    \n// \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n\
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
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 72 \"template/template.hpp\"\
    \n\n// bitop\n#line 2 \"template/bitop.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/bitop.hpp\n\
    \n// \u975E\u8CA0\u6574\u6570 x \u306E bit legnth \u3092\u6C42\u3081\u308B.\n\
    ll bit_length(ll x) {\n    if (x == 0) { return 0; }\n    return (sizeof(long)\
    \ * CHAR_BIT) - __builtin_clzll(x);\n}\n\n// \u975E\u8CA0\u6574\u6570 x \u306E\
    \ popcount \u3092\u6C42\u3081\u308B.\nll popcount(ll x) { return __builtin_popcountll(x);\
    \ }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\u3057\u3066, floor(log2(x))\
    \ \u3092\u6C42\u3081\u308B.\nll floor_log2(ll x) { return bit_length(x) - 1; }\n\
    \n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\u3057\u3066, ceil(log2(x)) \u3092\
    \u6C42\u3081\u308B.\nll ceil_log2(ll x) { return bit_length(x - 1); }\n\n// x\
    \ \u306E\u7B2C k \u30D3\u30C3\u30C8\u3092\u53D6\u5F97\u3059\u308B\nint get_bit(ll\
    \ x, int k) { return (x >> k) & 1; }\n\n// x \u306E\u30D3\u30C3\u30C8\u5217\u3092\
    \u53D6\u5F97\u3059\u308B.\n// k \u306F\u30D3\u30C3\u30C8\u5217\u306E\u9577\u3055\
    \u3068\u3059\u308B.\nvector<int> get_bits(ll x, int k) {\n    vector<int> bits(k);\n\
    \    rep(i, k) {\n        bits[i] = x & 1;\n        x >>= 1;\n    }\n\n    return\
    \ bits;\n}\n\n// x \u306E\u30D3\u30C3\u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B\
    .\nvector<int> get_bits(ll x) { return get_bits(x, bit_length(x)); }\n\n// x \u306B\
    \u7ACB\u3063\u3066\u3044\u308B\u306A\u3093\u304B\u3057\u3089\u306E\u30D3\u30C3\
    \u30C8\u306E\u756A\u53F7\u3092\u51FA\u529B\u3059\u308B.\nll lowest_bit(const ll\
    \ x) { return floor_log2(x & (-x)); }\n#line 75 \"template/template.hpp\"\n\n\
    // exception\n#line 2 \"template/exception.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/exception.hpp\n\
    \nclass NotExist: public exception {\n    private:\n    string message;\n\n  \
    \  public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 6 \"Integer/Integer_Equation.hpp\"\n\n/// @brief [l, +infty)\
    \ \u4E0A\u306E\u975E\u5B9A\u6570\u591A\u9805\u5F0F P (\u4FC2\u6570\u306F\u7B26\
    \u53F7\u306A\u3057\u6574\u6570) \u306B\u5BFE\u3057\u3066, P(x) = y \u3092\u6E80\
    \u305F\u3059\u6574\u6570 x \u3092\u6C42\u3081\u308B (\u7B26\u53F7\u306A\u3057\u6574\
    \u6570\u7248).\n/// @param P \u591A\u9805\u5F0F (P[i] \u306F x^i \u306E\u4FC2\u6570\
    ). \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u304C 0 \u306E\u5834\u5408\u306F\u53D6\
    \u308A\u9664\u304B\u308C\u308B.\n/// @param y \u76EE\u6A19\u5024\n/// @param l\
    \ \u635C\u7D22\u7BC4\u56F2\u306E\u4E0B\u9650.\n/// @return P(x) = y \u3092\u6E80\
    \u305F\u3059\u6574\u6570 x. \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F nullopt.\n\
    /// @tparam T \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B (unsigned, unsigned long\
    \ long \u306A\u3069).\n/// @note \u4FC2\u6570\u30FBl\u30FBy \u304C\u5168\u3066\
    \ 0 \u4EE5\u4E0A\u306A\u306E\u3067, P \u306F\u81EA\u52D5\u7684\u306B [l, +infty)\
    \ \u4E0A\u3067\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\u306B\u306A\u308B.\n/// @note\
    \ \u8A55\u4FA1\u306F y \u3092\u8D85\u3048\u305F\u6642\u70B9\u3067\u6253\u3061\u5207\
    \u308B\u305F\u3081\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u304C, y + 1 \u3068 l + 2 * (\u89E3\u306E\u5927\u304D\u3055) \u304C T \u306E\u7BC4\
    \u56F2\u5185\u3067\u3042\u308B\u3053\u3068.\ntemplate<unsigned_integral T>\noptional<T>\
    \ Integer_Equation(vector<T> P, const T y, const T l = 0) {\n    // P \u306E\u6B63\
    \u898F\u5316\n    until(P.empty() || P.back() != 0) {\n        P.pop_back();\n\
    \    }\n\n    assert(P.size() > 1);\n\n    // P(x) \u3092\u8FD4\u3059. \u305F\u3060\
    \u3057 P(x) > y \u306E\u5834\u5408\u306F y + 1 \u3092\u8FD4\u3059 (\u5272\u308A\
    \u7B97\u3067\u8D85\u904E\u3092\u5224\u5B9A\u3059\u308B\u306E\u3067\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044).\n    auto calc = [&](T x) ->\
    \ T {\n        if (x == 0) { return P[0]; }\n\n        T v = 0;\n        for (int\
    \ i = (int)P.size() - 1; i >= 0; i--) {\n            if (P[i] > y) { return y\
    \ + 1; }\n            if (v > (y - P[i]) / x) { return y + 1; }\n            v\
    \ = v * x + P[i];\n        }\n        return v;\n    };\n\n    if (calc(l) > y)\
    \ {\n        return nullopt;\n    }\n\n    // \u4E0A\u754C r (P(r) > y) \u3092\
    \u6C42\u3081\u308B.\n    T d = 1;\n    while (calc(l + d) <= y) {\n        d *=\
    \ 2;\n    }\n\n    // P(lo) <= y < P(hi)\n    T lo = l, hi = l + d;\n    while\
    \ (hi - lo > 1) {\n        T c = lo + (hi - lo) / 2;\n        ((calc(c) <= y)\
    \ ? lo : hi) = c;\n    }\n\n    if (calc(lo) == y) {\n        return lo;\n   \
    \ }\n    return nullopt;\n}\n\n/// @brief [l, +infty) \u4E0A (\u72ED\u7FA9) \u5358\
    \u8ABF\u5897\u52A0\u306A\u6574\u6570\u4FC2\u6570\u306E\u975E\u5B9A\u6570\u591A\
    \u9805\u5F0F P \u306B\u5BFE\u3057\u3066, P(x) = y \u3092\u6E80\u305F\u3059\u6574\
    \u6570 x \u3092\u6C42\u3081\u308B.\n/// @param P \u591A\u9805\u5F0F (P[i] \u306F\
    \ x^i \u306E\u4FC2\u6570). \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u304C 0 \u306E\
    \u5834\u5408\u306F\u53D6\u308A\u9664\u304B\u308C\u308B.\n/// @param y \u76EE\u6A19\
    \u5024\n/// @param l \u635C\u7D22\u7BC4\u56F2\u306E\u4E0B\u9650.\n/// @return\
    \ P(x) = y \u3092\u6E80\u305F\u3059\u6574\u6570 x. \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F nullopt.\n/// @tparam T \u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B (int, long long \u306A\u3069). \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\
    \u3084, numeric_limits \u304C\u7279\u6B8A\u5316\u3055\u308C\u3066\u3044\u306A\u3044\
    \u578B (\u53B3\u5BC6\u30E2\u30FC\u30C9\u306E __int128 \u306A\u3069) \u306F\u4E0D\
    \u53EF.\n/// @note \u4FC2\u6570\u30FBl\u30FBy \u306F\u8CA0\u3067\u3082\u3088\u3044\
    . \u8A55\u4FA1\u306F\u9014\u4E2D\u3067\u6253\u3061\u5207\u308B\u305F\u3081\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u304C, 2 * max(|P[i]|,\
    \ |y|) + |l| \u304C T \u306E\u7BC4\u56F2\u5185\u3067\u3042\u308B\u3053\u3068.\n\
    template<signed_integral T>\noptional<T> Integer_Equation(vector<T> P, const T\
    \ y, const T l = 0) {\n    // P \u306E\u6B63\u898F\u5316\n    until(P.empty()\
    \ || P.back() != 0) {\n        P.pop_back();\n    }\n\n    assert(P.size() > 1);\n\
    \n    // C = max |P[i]|, B = max(C, |y|)\n    T C = 0;\n    for (const T &p: P)\
    \ { C = max(C, p < 0 ? -p : p); }\n    const T B = max(C, y < 0 ? -y : y);\n \
    \   const T MAX = numeric_limits<T>::max();\n\n    // sgn(P(x) - y) \u306B\u76F8\
    \u5F53\u3059\u308B\u5024\u3092\u8FD4\u3059. |x| >= 2 \u306E\u3068\u304D, Horner\
    \ \u6CD5\u306E\u9014\u4E2D\u5024 v \u304C |v| > B \u306B\u306A\u308B\u3068\n \
    \   // \u4EE5\u964D\u306F |v| \u304C\u771F\u306B\u5897\u3048\u7D9A\u3051, \u6700\
    \u7D42\u7684\u306B |P(x)| > B >= |y| \u304B\u3064\u7B26\u53F7\u3082\u78BA\u5B9A\
    \u3059\u308B\u306E\u3067, \u305D\u306E\u6642\u70B9\u3067\u6253\u3061\u5207\u308B\
    .\n    // \u6253\u3061\u5207\u3063\u305F\u5834\u5408\u306F P(x) > y \u306A\u3089\
    \ y + 1, P(x) < y \u306A\u3089 y - 1 \u3092\u8FD4\u3059.\n    auto calc = [&](T\
    \ x) -> T {\n        const T ax = x < 0 ? -x : x;\n        T v = 0;\n        for\
    \ (int i = (int)P.size() - 1; i >= 0; i--) {\n            if (ax >= 2) {\n   \
    \             const T av = v < 0 ? -v : v;\n                if (av > B || av >\
    \ (MAX - C) / ax) {\n                    // \u6B8B\u308A\u306E\u4E57\u7B97\u56DE\
    \u6570\u306F i + 1 \u56DE\n                    bool negative = (v < 0) != (x <\
    \ 0 && (i + 1) % 2 == 1);\n                    return negative ? y - 1 : y + 1;\n\
    \                }\n            }\n            v = v * x + P[i];\n        }\n\
    \        return v;\n    };\n\n    if (calc(l) > y) {\n        return nullopt;\n\
    \    }\n\n    // \u4E0A\u754C r (P(r) > y) \u3092\u6C42\u3081\u308B.\n    T d\
    \ = 1;\n    while (calc(l + d) <= y) {\n        d *= 2;\n    }\n\n    // P(lo)\
    \ <= y < P(hi)\n    T lo = l, hi = l + d;\n    while (hi - lo > 1) {\n       \
    \ T c = midpoint(lo, hi);\n        ((calc(c) <= y) ? lo : hi) = c;\n    }\n\n\
    \    if (calc(lo) == y) {\n        return lo;\n    }\n    return nullopt;\n}\n\
    \n\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Integer_Equation.hpp\n\
    \n#include \"../template/template.hpp\"\n\n/// @brief [l, +infty) \u4E0A\u306E\
    \u975E\u5B9A\u6570\u591A\u9805\u5F0F P (\u4FC2\u6570\u306F\u7B26\u53F7\u306A\u3057\
    \u6574\u6570) \u306B\u5BFE\u3057\u3066, P(x) = y \u3092\u6E80\u305F\u3059\u6574\
    \u6570 x \u3092\u6C42\u3081\u308B (\u7B26\u53F7\u306A\u3057\u6574\u6570\u7248\
    ).\n/// @param P \u591A\u9805\u5F0F (P[i] \u306F x^i \u306E\u4FC2\u6570). \u6700\
    \u9AD8\u6B21\u306E\u4FC2\u6570\u304C 0 \u306E\u5834\u5408\u306F\u53D6\u308A\u9664\
    \u304B\u308C\u308B.\n/// @param y \u76EE\u6A19\u5024\n/// @param l \u635C\u7D22\
    \u7BC4\u56F2\u306E\u4E0B\u9650.\n/// @return P(x) = y \u3092\u6E80\u305F\u3059\
    \u6574\u6570 x. \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F nullopt.\n///\
    \ @tparam T \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B (unsigned, unsigned long\
    \ long \u306A\u3069).\n/// @note \u4FC2\u6570\u30FBl\u30FBy \u304C\u5168\u3066\
    \ 0 \u4EE5\u4E0A\u306A\u306E\u3067, P \u306F\u81EA\u52D5\u7684\u306B [l, +infty)\
    \ \u4E0A\u3067\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\u306B\u306A\u308B.\n/// @note\
    \ \u8A55\u4FA1\u306F y \u3092\u8D85\u3048\u305F\u6642\u70B9\u3067\u6253\u3061\u5207\
    \u308B\u305F\u3081\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u304C, y + 1 \u3068 l + 2 * (\u89E3\u306E\u5927\u304D\u3055) \u304C T \u306E\u7BC4\
    \u56F2\u5185\u3067\u3042\u308B\u3053\u3068.\ntemplate<unsigned_integral T>\noptional<T>\
    \ Integer_Equation(vector<T> P, const T y, const T l = 0) {\n    // P \u306E\u6B63\
    \u898F\u5316\n    until(P.empty() || P.back() != 0) {\n        P.pop_back();\n\
    \    }\n\n    assert(P.size() > 1);\n\n    // P(x) \u3092\u8FD4\u3059. \u305F\u3060\
    \u3057 P(x) > y \u306E\u5834\u5408\u306F y + 1 \u3092\u8FD4\u3059 (\u5272\u308A\
    \u7B97\u3067\u8D85\u904E\u3092\u5224\u5B9A\u3059\u308B\u306E\u3067\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044).\n    auto calc = [&](T x) ->\
    \ T {\n        if (x == 0) { return P[0]; }\n\n        T v = 0;\n        for (int\
    \ i = (int)P.size() - 1; i >= 0; i--) {\n            if (P[i] > y) { return y\
    \ + 1; }\n            if (v > (y - P[i]) / x) { return y + 1; }\n            v\
    \ = v * x + P[i];\n        }\n        return v;\n    };\n\n    if (calc(l) > y)\
    \ {\n        return nullopt;\n    }\n\n    // \u4E0A\u754C r (P(r) > y) \u3092\
    \u6C42\u3081\u308B.\n    T d = 1;\n    while (calc(l + d) <= y) {\n        d *=\
    \ 2;\n    }\n\n    // P(lo) <= y < P(hi)\n    T lo = l, hi = l + d;\n    while\
    \ (hi - lo > 1) {\n        T c = lo + (hi - lo) / 2;\n        ((calc(c) <= y)\
    \ ? lo : hi) = c;\n    }\n\n    if (calc(lo) == y) {\n        return lo;\n   \
    \ }\n    return nullopt;\n}\n\n/// @brief [l, +infty) \u4E0A (\u72ED\u7FA9) \u5358\
    \u8ABF\u5897\u52A0\u306A\u6574\u6570\u4FC2\u6570\u306E\u975E\u5B9A\u6570\u591A\
    \u9805\u5F0F P \u306B\u5BFE\u3057\u3066, P(x) = y \u3092\u6E80\u305F\u3059\u6574\
    \u6570 x \u3092\u6C42\u3081\u308B.\n/// @param P \u591A\u9805\u5F0F (P[i] \u306F\
    \ x^i \u306E\u4FC2\u6570). \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u304C 0 \u306E\
    \u5834\u5408\u306F\u53D6\u308A\u9664\u304B\u308C\u308B.\n/// @param y \u76EE\u6A19\
    \u5024\n/// @param l \u635C\u7D22\u7BC4\u56F2\u306E\u4E0B\u9650.\n/// @return\
    \ P(x) = y \u3092\u6E80\u305F\u3059\u6574\u6570 x. \u5B58\u5728\u3057\u306A\u3044\
    \u5834\u5408\u306F nullopt.\n/// @tparam T \u7B26\u53F7\u4ED8\u304D\u6574\u6570\
    \u578B (int, long long \u306A\u3069). \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\
    \u3084, numeric_limits \u304C\u7279\u6B8A\u5316\u3055\u308C\u3066\u3044\u306A\u3044\
    \u578B (\u53B3\u5BC6\u30E2\u30FC\u30C9\u306E __int128 \u306A\u3069) \u306F\u4E0D\
    \u53EF.\n/// @note \u4FC2\u6570\u30FBl\u30FBy \u306F\u8CA0\u3067\u3082\u3088\u3044\
    . \u8A55\u4FA1\u306F\u9014\u4E2D\u3067\u6253\u3061\u5207\u308B\u305F\u3081\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u304C, 2 * max(|P[i]|,\
    \ |y|) + |l| \u304C T \u306E\u7BC4\u56F2\u5185\u3067\u3042\u308B\u3053\u3068.\n\
    template<signed_integral T>\noptional<T> Integer_Equation(vector<T> P, const T\
    \ y, const T l = 0) {\n    // P \u306E\u6B63\u898F\u5316\n    until(P.empty()\
    \ || P.back() != 0) {\n        P.pop_back();\n    }\n\n    assert(P.size() > 1);\n\
    \n    // C = max |P[i]|, B = max(C, |y|)\n    T C = 0;\n    for (const T &p: P)\
    \ { C = max(C, p < 0 ? -p : p); }\n    const T B = max(C, y < 0 ? -y : y);\n \
    \   const T MAX = numeric_limits<T>::max();\n\n    // sgn(P(x) - y) \u306B\u76F8\
    \u5F53\u3059\u308B\u5024\u3092\u8FD4\u3059. |x| >= 2 \u306E\u3068\u304D, Horner\
    \ \u6CD5\u306E\u9014\u4E2D\u5024 v \u304C |v| > B \u306B\u306A\u308B\u3068\n \
    \   // \u4EE5\u964D\u306F |v| \u304C\u771F\u306B\u5897\u3048\u7D9A\u3051, \u6700\
    \u7D42\u7684\u306B |P(x)| > B >= |y| \u304B\u3064\u7B26\u53F7\u3082\u78BA\u5B9A\
    \u3059\u308B\u306E\u3067, \u305D\u306E\u6642\u70B9\u3067\u6253\u3061\u5207\u308B\
    .\n    // \u6253\u3061\u5207\u3063\u305F\u5834\u5408\u306F P(x) > y \u306A\u3089\
    \ y + 1, P(x) < y \u306A\u3089 y - 1 \u3092\u8FD4\u3059.\n    auto calc = [&](T\
    \ x) -> T {\n        const T ax = x < 0 ? -x : x;\n        T v = 0;\n        for\
    \ (int i = (int)P.size() - 1; i >= 0; i--) {\n            if (ax >= 2) {\n   \
    \             const T av = v < 0 ? -v : v;\n                if (av > B || av >\
    \ (MAX - C) / ax) {\n                    // \u6B8B\u308A\u306E\u4E57\u7B97\u56DE\
    \u6570\u306F i + 1 \u56DE\n                    bool negative = (v < 0) != (x <\
    \ 0 && (i + 1) % 2 == 1);\n                    return negative ? y - 1 : y + 1;\n\
    \                }\n            }\n            v = v * x + P[i];\n        }\n\
    \        return v;\n    };\n\n    if (calc(l) > y) {\n        return nullopt;\n\
    \    }\n\n    // \u4E0A\u754C r (P(r) > y) \u3092\u6C42\u3081\u308B.\n    T d\
    \ = 1;\n    while (calc(l + d) <= y) {\n        d *= 2;\n    }\n\n    // P(lo)\
    \ <= y < P(hi)\n    T lo = l, hi = l + d;\n    while (hi - lo > 1) {\n       \
    \ T c = midpoint(lo, hi);\n        ((calc(c) <= y) ? lo : hi) = c;\n    }\n\n\
    \    if (calc(lo) == y) {\n        return lo;\n    }\n    return nullopt;\n}\n\
    \n\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Integer/Integer_Equation.hpp
  requiredBy: []
  timestamp: '2026-10-18 00:17:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Integer_Equation.test.cpp
documentation_of: Integer/Integer_Equation.hpp
layout: document
title: "\u6574\u6570\u4FC2\u6570\u306E\u591A\u9805\u5F0F\u306B\u3088\u308B\u65B9\u7A0B\
  \u5F0F"
---

## Outline

整数 $l$ 以上の範囲で狭義単調増加な非定数多項式

  $$ P(x) = p_0 + p_1 x + \dots + p_{n-1} x^{n-1} $$

と整数 $y$ に対して, 方程式 $P(x) = y$ を満たす整数 $x \geq l$ を二分探索で求める.

## Theory

### アルゴリズム

$P$ は $[l, \infty)$ 上で狭義単調増加であるため, $P(x) = y$ を満たす $x \geq l$ は存在すれば一意であり, $P(x) \leq y$ を満たす最大の $x$ に一致する. そのため, この $x$ を二分探索で求め, $P(x) = y$ であるかを確認すればよい. 二分探索の上界は, $P(l + d) > y$ となる最小の $2$ の冪 $d$ を用いて $l + d$ とする.

### 多項式の評価とオーバーフローの回避

$P(x)$ は Horner 法

  $$ v_{n} := 0, \quad v_{i} := v_{i+1} x + p_i \quad (i = n-1, \dots, 0) $$

で評価する ($P(x) = v_0$). 途中値が `T` の範囲を超えないように, 以下のように打ち切る.

#### 符号なし整数の場合

$x \geq 1$ のとき, 係数と $x$ が $0$ 以上であるため, 途中値は非減少である. よって, 途中で $v_i > y$ となった時点で $P(x) > y$ が確定する. $x = 0$ のときは, 途中値が $y$ を超えても最終値は $P(0) = p_0$ であるため, 打ち切らずに $p_0$ をそのまま評価値とする.

$v_{i+1} x + p_i \leq y$ の判定は, 掛け算をせずに

  $$ p_i \leq y \quad \text{かつ} \quad v_{i+1} \leq \left\lfloor \dfrac{y - p_i}{x} \right\rfloor \quad (x > 0) $$

で行うため, オーバーフローは起こらない ($x \geq 1$).

#### 符号付き整数の場合

$C := \max_i \lvert p_i \rvert$, $B := \max(C, \lvert y \rvert)$ とする.

<div class="theorem" markdown="1">

定理 1
---

$\lvert x \rvert \geq 2$ とする. ある $i$ で $\lvert v_{i+1} \rvert > B$ ならば, $\lvert P(x) \rvert > B$ であり, $P(x)$ の符号は $v_{i+1}$ の符号と, $x < 0$ かつ残りの乗算回数 $i + 1$ が奇数であるか否かで定まる.

</div>

<div class="proof" markdown="1">

証明
---

$\lvert v_{i+1} \rvert > C$ とすると,

  $$ \lvert v_i \rvert \geq \lvert v_{i+1} \rvert \lvert x \rvert - \lvert p_i \rvert \geq 2 \lvert v_{i+1} \rvert - C > \lvert v_{i+1} \rvert $$

であり, $v_i$ の符号は $v_{i+1} x$ の符号に等しい. 以降も同様に, $\lvert v \rvert$ は真に増え続け, 符号は $x$ の符号のみで決まる. したがって $\lvert P(x) \rvert = \lvert v_0 \rvert > B \geq \lvert y \rvert$ である.

</div>

そのため, $\lvert v \rvert > B$ となった時点で $P(x)$ と $y$ の大小が確定する. 掛け算がオーバーフローしうる場合 ($\lvert v \rvert > (\mathrm{MAX} - C) / \lvert x \rvert$) も同様に打ち切る.

* $P(x) > y$ と確定した場合は $y + 1$ を, $P(x) < y$ と確定した場合は $y - 1$ を評価値とする.
* $\lvert x \rvert \leq 1$ のときは値が膨らまないため, そのまま評価する.

## Contents

```cpp
template<unsigned_integral T>
optional<T> Integer_Equation(vector<T> P, const T y, const T l = 0)
```

* 符号なし整数版. $P(x) = y$ を満たす整数 $x \geq l$ を求める.
* **制約**
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $y + 1$ と $l + 2d$ ($d$ は上界の探索で得られる値) が `T` の範囲内であること. 目安として, $y$ が `T` の最大値の約半分以下であること.
* **返り値**: 解が存在する場合はその値, 存在しない場合は `nullopt`.
* **計算量**: 解を $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).

```cpp
template<signed_integral T>
optional<T> Integer_Equation(vector<T> P, const T y, const T l = 0)
```

* 符号付き整数版. $P(x) = y$ を満たす整数 $x \geq l$ を求める.
* **制約**
  * $P$ は $[l, \infty)$ 上で狭義単調増加でなくてはならない. 係数, $l$, $y$ は負でもよい.
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $2 \max(C, \lvert y \rvert) + \lvert l \rvert$ が `T` の範囲内であること.
* **返り値**: 解が存在する場合はその値, 存在しない場合は `nullopt`.
* **計算量**: 解を $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).
