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
    document_title: "\u5C3A\u53D6\u308A\u6CD5\u306E\u4E00\u822C\u5316\u7248. \u9589\
      \u533A\u9593 [l, r] \u3092\u7BA1\u7406\u3059\u308B add/remove/cond \u3092\u6E21\
      \u3059\u3053\u3068\u3067, \u533A\u9593\u548C\u4EE5\u5916\u306E\u6761\u4EF6\u306B\
      \u3082\u5BFE\u5FDC\u3067\u304D\u308B."
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
    \    }\n};\n#line 2 \"Queries/Two_Pointers.hpp\"\n\n/// @brief \u5C3A\u53D6\u308A\
    \u6CD5\u306E\u4E00\u822C\u5316\u7248. \u9589\u533A\u9593 [l, r] \u3092\u7BA1\u7406\
    \u3059\u308B add/remove/cond \u3092\u6E21\u3059\u3053\u3068\u3067, \u533A\u9593\
    \u548C\u4EE5\u5916\u306E\u6761\u4EF6\u306B\u3082\u5BFE\u5FDC\u3067\u304D\u308B\
    .\n/// @tparam AddFunc void(int r) \u578B. \u8981\u7D20 r \u3092\u533A\u9593\u306B\
    \u8FFD\u52A0\u3059\u308B.\n/// @tparam RemoveFunc void(int i) \u578B. \u8981\u7D20\
    \ i \u3092\u533A\u9593\u304B\u3089\u9664\u304F.\n/// @tparam CondFunc bool() \u578B\
    . \u73FE\u5728\u4FDD\u6301\u3057\u3066\u3044\u308B\u9589\u533A\u9593\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u304B\u3092\u8FD4\u3059.\n/// @param n \u6570\u5217\
    \u306E\u9577\u3055.\n/// @param add \u8981\u7D20\u3092\u533A\u9593\u306B\u8FFD\
    \u52A0\u3059\u308B\u64CD\u4F5C.\n/// @param remove \u8981\u7D20\u3092\u533A\u9593\
    \u304B\u3089\u9664\u304F\u64CD\u4F5C.\n/// @param cond \u73FE\u5728\u306E\u533A\
    \u9593\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\
    \u5224\u5B9A (add(r) \u5F8C\u306B false \u306A\u3089 remove(r) \u3067\u53D6\u308A\
    \u6D88\u3059).\n/// @return result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\
    \u304D, \u9589\u533A\u9593 [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u3088\u3046\u306A\u6700\u5927\u306E result[l] (\u6E80\u305F\u3059 index\
    \ \u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 l - 1).\ntemplate <class AddFunc,\
    \ class RemoveFunc, class CondFunc>\nvector<int> Two_Pointers(const int n, const\
    \ AddFunc &add, const RemoveFunc &remove, const CondFunc &cond) {\n    vector<int>\
    \ result(n, -1);\n    int r = 0;\n\n    for (int l = 0; l < n; ++l) {\n      \
    \  if (r < l) r = l;\n\n        while (r < n) {\n            add(r);\n       \
    \     if (cond()) {\n                ++r;\n            } else {\n            \
    \    remove(r);\n                break;\n            }\n        }\n\n        result[l]\
    \ = r - 1;\n\n        if (l < r) {\n            remove(l);\n        }\n    }\n\
    \n    return result;\n}\n\n/// @brief \u5C3A\u53D6\u308A\u6CD5 (\u7FA4\u7248).\
    \ data \u306E\u8981\u7D20\u304C\u7FA4 (\u5358\u4F4D\u5143 e, \u6F14\u7B97 op,\
    \ \u9006\u5143 inv) \u3092\u306A\u3059\u5834\u5408\u306B, \u533A\u9593\u306E\u7DCF\
    \u7A4D\u3092\u81EA\u52D5\u3067\u7BA1\u7406\u3059\u308B.\n/// @tparam G \u7FA4\u306E\
    \u5143\u306E\u578B.\n/// @tparam OpFunc G(G, G) \u578B. \u7FA4\u306E\u6F14\u7B97\
    . \u7D50\u5408\u7684\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n/// @tparam\
    \ InvFunc G(G) \u578B. \u7FA4\u306E\u9006\u5143. op(inv(x), x) = e \u3092\u6E80\
    \u305F\u3059\u5FC5\u8981\u304C\u3042\u308B.\n/// @tparam CondFunc bool(G) \u578B\
    . \u533A\u9593\u306E\u7DCF\u7A4D\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\
    \u3092\u8FD4\u3059.\n/// @param data \u6570\u5217.\n/// @param e \u5358\u4F4D\u5143\
    .\n/// @param op \u7FA4\u306E\u6F14\u7B97.\n/// @param inv \u7FA4\u306E\u9006\u5143\
    .\n/// @param cond \u7DCF\u7A4D op(data[l], op(data[l + 1], ..., data[r])) \u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\
    .\n/// @return result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D, \u9589\
    \u533A\u9593 [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\
    \u306A\u6700\u5927\u306E result[l] (\u6E80\u305F\u3059 index \u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 l - 1).\ntemplate <class G, class OpFunc, class\
    \ InvFunc, class CondFunc>\nvector<int> Two_Pointers_Group(const vector<G> &data,\
    \ const G &e, const OpFunc &op, const InvFunc &inv, const CondFunc &cond) {\n\
    \    const int n = data.size();\n    G prod = e;\n\n    return Two_Pointers(\n\
    \        n,\n        [&](int i) { prod = op(prod, data[i]); },\n        [&](int\
    \ i) { prod = op(inv(data[i]), prod); },\n        [&]() { return cond(prod); }\n\
    \    );\n}\n\n/// @brief \u5C3A\u53D6\u308A\u6CD5 (\u76F4\u63A5\u5224\u5B9A\u7248\
    ). \u9589\u533A\u9593 [l, r] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\
    \u3046\u304B\u3092 cond(l, r) \u3067\u76F4\u63A5\u5224\u5B9A\u3067\u304D\u308B\
    \u5834\u5408\u306B\u4F7F\u3046. \u72B6\u614B\u306E\u7BA1\u7406 (add/remove) \u304C\
    \u4E0D\u8981.\n/// @tparam CondFunc bool(int, int) \u578B. cond(l, r) \u306F\u9589\
    \u533A\u9593 [l, r] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3092\u8FD4\
    \u3059. l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D r \u306B\u95A2\u3057\u3066\
    \u5358\u8ABF (r \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u306A\u3089 l <= r'\
    \ <= r \u3092\u6E80\u305F\u3059 r' \u3082\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    ) \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n/// @param n \u6570\u5217\
    \u306E\u9577\u3055.\n/// @param cond \u9589\u533A\u9593 [l, r] \u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A.\n/// @return\
    \ result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D, \u9589\u533A\u9593\
    \ [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\
    \u5927\u306E result[l] (\u6E80\u305F\u3059 index \u304C\u5B58\u5728\u3057\u306A\
    \u3051\u308C\u3070 l - 1).\ntemplate <class CondFunc>\nvector<int> Two_Pointers_Direct(const\
    \ int n, const CondFunc &cond) {\n    vector<int> result(n, -1);\n    int r =\
    \ 0;\n\n    for (int l = 0; l < n; ++l) {\n        if (r < l) r = l;\n\n     \
    \   while (r < n && cond(l, r)) {\n            ++r;\n        }\n\n        result[l]\
    \ = r - 1;\n    }\n\n    return result;\n}\n"
  code: "#include \"../template/template.hpp\"\n\n/// @brief \u5C3A\u53D6\u308A\u6CD5\
    \u306E\u4E00\u822C\u5316\u7248. \u9589\u533A\u9593 [l, r] \u3092\u7BA1\u7406\u3059\
    \u308B add/remove/cond \u3092\u6E21\u3059\u3053\u3068\u3067, \u533A\u9593\u548C\
    \u4EE5\u5916\u306E\u6761\u4EF6\u306B\u3082\u5BFE\u5FDC\u3067\u304D\u308B.\n///\
    \ @tparam AddFunc void(int r) \u578B. \u8981\u7D20 r \u3092\u533A\u9593\u306B\u8FFD\
    \u52A0\u3059\u308B.\n/// @tparam RemoveFunc void(int i) \u578B. \u8981\u7D20 i\
    \ \u3092\u533A\u9593\u304B\u3089\u9664\u304F.\n/// @tparam CondFunc bool() \u578B\
    . \u73FE\u5728\u4FDD\u6301\u3057\u3066\u3044\u308B\u9589\u533A\u9593\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u304B\u3092\u8FD4\u3059.\n/// @param n \u6570\u5217\
    \u306E\u9577\u3055.\n/// @param add \u8981\u7D20\u3092\u533A\u9593\u306B\u8FFD\
    \u52A0\u3059\u308B\u64CD\u4F5C.\n/// @param remove \u8981\u7D20\u3092\u533A\u9593\
    \u304B\u3089\u9664\u304F\u64CD\u4F5C.\n/// @param cond \u73FE\u5728\u306E\u533A\
    \u9593\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\
    \u5224\u5B9A (add(r) \u5F8C\u306B false \u306A\u3089 remove(r) \u3067\u53D6\u308A\
    \u6D88\u3059).\n/// @return result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\
    \u304D, \u9589\u533A\u9593 [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u3088\u3046\u306A\u6700\u5927\u306E result[l] (\u6E80\u305F\u3059 index\
    \ \u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 l - 1).\ntemplate <class AddFunc,\
    \ class RemoveFunc, class CondFunc>\nvector<int> Two_Pointers(const int n, const\
    \ AddFunc &add, const RemoveFunc &remove, const CondFunc &cond) {\n    vector<int>\
    \ result(n, -1);\n    int r = 0;\n\n    for (int l = 0; l < n; ++l) {\n      \
    \  if (r < l) r = l;\n\n        while (r < n) {\n            add(r);\n       \
    \     if (cond()) {\n                ++r;\n            } else {\n            \
    \    remove(r);\n                break;\n            }\n        }\n\n        result[l]\
    \ = r - 1;\n\n        if (l < r) {\n            remove(l);\n        }\n    }\n\
    \n    return result;\n}\n\n/// @brief \u5C3A\u53D6\u308A\u6CD5 (\u7FA4\u7248).\
    \ data \u306E\u8981\u7D20\u304C\u7FA4 (\u5358\u4F4D\u5143 e, \u6F14\u7B97 op,\
    \ \u9006\u5143 inv) \u3092\u306A\u3059\u5834\u5408\u306B, \u533A\u9593\u306E\u7DCF\
    \u7A4D\u3092\u81EA\u52D5\u3067\u7BA1\u7406\u3059\u308B.\n/// @tparam G \u7FA4\u306E\
    \u5143\u306E\u578B.\n/// @tparam OpFunc G(G, G) \u578B. \u7FA4\u306E\u6F14\u7B97\
    . \u7D50\u5408\u7684\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n/// @tparam\
    \ InvFunc G(G) \u578B. \u7FA4\u306E\u9006\u5143. op(inv(x), x) = e \u3092\u6E80\
    \u305F\u3059\u5FC5\u8981\u304C\u3042\u308B.\n/// @tparam CondFunc bool(G) \u578B\
    . \u533A\u9593\u306E\u7DCF\u7A4D\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\
    \u3092\u8FD4\u3059.\n/// @param data \u6570\u5217.\n/// @param e \u5358\u4F4D\u5143\
    .\n/// @param op \u7FA4\u306E\u6F14\u7B97.\n/// @param inv \u7FA4\u306E\u9006\u5143\
    .\n/// @param cond \u7DCF\u7A4D op(data[l], op(data[l + 1], ..., data[r])) \u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\
    .\n/// @return result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D, \u9589\
    \u533A\u9593 [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\
    \u306A\u6700\u5927\u306E result[l] (\u6E80\u305F\u3059 index \u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070 l - 1).\ntemplate <class G, class OpFunc, class\
    \ InvFunc, class CondFunc>\nvector<int> Two_Pointers_Group(const vector<G> &data,\
    \ const G &e, const OpFunc &op, const InvFunc &inv, const CondFunc &cond) {\n\
    \    const int n = data.size();\n    G prod = e;\n\n    return Two_Pointers(\n\
    \        n,\n        [&](int i) { prod = op(prod, data[i]); },\n        [&](int\
    \ i) { prod = op(inv(data[i]), prod); },\n        [&]() { return cond(prod); }\n\
    \    );\n}\n\n/// @brief \u5C3A\u53D6\u308A\u6CD5 (\u76F4\u63A5\u5224\u5B9A\u7248\
    ). \u9589\u533A\u9593 [l, r] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3069\
    \u3046\u304B\u3092 cond(l, r) \u3067\u76F4\u63A5\u5224\u5B9A\u3067\u304D\u308B\
    \u5834\u5408\u306B\u4F7F\u3046. \u72B6\u614B\u306E\u7BA1\u7406 (add/remove) \u304C\
    \u4E0D\u8981.\n/// @tparam CondFunc bool(int, int) \u578B. cond(l, r) \u306F\u9589\
    \u533A\u9593 [l, r] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u3092\u8FD4\
    \u3059. l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D r \u306B\u95A2\u3057\u3066\
    \u5358\u8ABF (r \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u306A\u3089 l <= r'\
    \ <= r \u3092\u6E80\u305F\u3059 r' \u3082\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    ) \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B.\n/// @param n \u6570\u5217\
    \u306E\u9577\u3055.\n/// @param cond \u9589\u533A\u9593 [l, r] \u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A.\n/// @return\
    \ result[l] := l \u3092\u56FA\u5B9A\u3057\u305F\u3068\u304D, \u9589\u533A\u9593\
    \ [l, result[l]] \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3088\u3046\u306A\u6700\
    \u5927\u306E result[l] (\u6E80\u305F\u3059 index \u304C\u5B58\u5728\u3057\u306A\
    \u3051\u308C\u3070 l - 1).\ntemplate <class CondFunc>\nvector<int> Two_Pointers_Direct(const\
    \ int n, const CondFunc &cond) {\n    vector<int> result(n, -1);\n    int r =\
    \ 0;\n\n    for (int l = 0; l < n; ++l) {\n        if (r < l) r = l;\n\n     \
    \   while (r < n && cond(l, r)) {\n            ++r;\n        }\n\n        result[l]\
    \ = r - 1;\n    }\n\n    return result;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Queries/Two_Pointers.hpp
  requiredBy: []
  timestamp: '2026-08-21 23:42:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Queries/Two_Pointers.hpp
layout: document
title: "\u5C3A\u53D6\u308A\u6CD5"
---

## Outline

列 $A$ に対する尺取り法を行うメソッドを提供する.

## Theory

$X$ を集合とする.

$X$ 上の列全体の集合の部分集合を $\mathcal{B}$ とする.

$X$ 上の列 $A$ が以下を満たすとする.

* $A$ の任意の連続部分列 $B$ について, $B \in \mathcal{B}$ ならば, 任意の $B$ の連続部分列 $C$ について, $C \in \mathcal{B}$ である.

$A$ の長さを $N$ として, $1 \leq l \leq r \leq N$ に対する $A$ の第 $l$ 項から第 $r$ までの連続部分列を $[l, r]$ と書くことにする.

このとき, $l = 1, 2, \dots, N$ に対して, 以下で定める $r_l$ を求めたい.

* $[l, l] \in \mathcal{B}$ ならば, $r_l = \max \{ k \mid l \leq k \leq N, [l, k] \in \mathcal{B} \}$.
* $[l, l] \notin \mathcal{B}$ ならば, $r_l = l - 1$.

### 尺取り法によるアルゴリズム

$\mathcal{B}$ がこの条件を満たすとき, $r_1, \dots, r_N$ について, 広義単調増加である. これは, $l < k \leq r_l$ を満たす任意の整数 $k$ に対して, 閉区間 $[l + 1, k]$ が $[l, r_l]$ の連続部分列であり, $[l, r_l] \in \mathcal{B}$ と $A$ に関する仮定により $[l + 1, k] \in \mathcal{B}$ となる.

すなわち $r_{l+1} \geq r_l$ となることに由来する.

そのため, $r_{l-1}$ が求められると, $r_l$ の計算は $r = r_{l-1}$ から計算できる.

これを利用することで, 以下のアルゴリズムで $r_1, \dots, r_N$ を高速に求められる.

1. $l = 1$, $r = 0$ から始め, 閉区間 $[l, r]$ を空として管理する.
2. $l = 1, 2, \dots, N$ の順に以下を行う.
   1. $r < N$ かつ, $[l, r + 1] \in \mathcal{B}$ の条件を満たす限り, 閉区間の末尾に $A_{r+1}$ を追加して $r$ を $1$ 増やす.
   2. このとき $r_l = r$ である.
   3. 次の $l$ に移る前に, 閉区間 $[l, r]$ の先頭から要素 $A_l$ を取り除く.

計算量について, $r$ は $l$ が増加する間, 減らずに $1, 2, \dots, N$ をたどるため, 全体を通して要素の追加・削除はそれぞれ高々 $N$ 回しか行われない.

従って, 追加・削除・条件判定の計算量が $O(T)$ 時間とすると, 全体で $O(NT)$ 時間で $r_1, \dots, r_N$ を求められる.

なお, $X, \mathcal{B}$ が特別な場合については, 尺取り法の一部処理を簡略化することができる.

* 区間 $[l, r]$ が条件を満たすかどうかを, 独立な判定問題として $O(T)$ で判定できる場合は, 追加・削除の手続きを省略して同様に尺取り法を適用できる.
* $X$ が群である場合は, 追加として右からの作用, 削除として左からの逆作用, 総積に関する条件で尺取り法を行える.

## Contents

Theory 欄では, 1-indexed だったが, 実装としては 0-indexed にしている.

### Two_Pointers

```cpp
template <class AddFunc, class RemoveFunc, class CondFunc>
vector<int> Two_Pointers(const int n, const AddFunc &add, const RemoveFunc &remove, const CondFunc &cond)
```

* 尺取り法の一般化版. 閉区間 $[l, r]$ を管理する `add` / `remove` / `cond` を渡すことで, 区間和に限らない条件について $r_0, \dots, r_{n-1}$ を求める (0-indexed).
* **引数**
  * $n$: 数列の長さ.
  * `add`: `void(int r)` 型. 要素 $r$ を区間に追加する.
  * `remove`: `void(int i)` 型. 要素 $i$ を区間から除く.
  * `cond`: `bool()` 型. 現在保持している閉区間が条件 $\mathcal{B}$ を満たすかを返す (`add(r)` した直後に `false` であれば, その場で `remove(r)` して取り消される).
* **戻り値**
  * `result[l]` := $l$ を固定したとき, 閉区間 $[l, r]$ が条件を満たすような最大の $r$ を格納する (満たす $r$ が存在しなければ $l - 1$).
* **計算量**
  * `add` / `remove` / `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

### Two_Pointers_Group

```cpp
template <class G, class OpFunc, class InvFunc, class CondFunc>
vector<int> Two_Pointers_Group(const vector<G> &data, const G &e, const OpFunc &op, const InvFunc &inv, const CondFunc &cond)
```

* `Two_Pointers` の群版. `data` の要素が群 $G$ (単位元 $e$, 演算 $\textrm{op}$, 逆元 $\textrm{inv}$) をなす場合に, 区間の総積を自動で管理しながら $r_0, \dots, r_{n-1}$ を求める.
* **引数**
  * `data`: 数列.
  * $G$ に関する情報
    * `e`: 単位元.
    * `op`: $G \times G \to G$. 群 $G$ の演算.
    * `inv`: $G \to G$. 群 $G$ の逆元関数.
  * `cond`: $G \to \{\mathbb{T}, \mathbb{F}\}$. 区間の総積 $\textrm{op}(A_l, \textrm{op}(A_{l+1}, \dots, A_r))$ が条件を満たすかを返す.
* **戻り値**
  * `Two_Pointers` と同様.
* **計算量**
  * `op` / `inv` / `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

### Two_Pointers_Direct

```cpp
template <class CondFunc>
vector<int> Two_Pointers_Direct(const int n, const CondFunc &cond)
```

* `Two_Pointers` の直接判定版. 閉区間 $[l, r]$ が条件を満たすかどうかを `cond(l, r)` で直接判定できる場合に用いる (状態の追加・削除の管理が不要).
* **引数**
  * $n$: 数列の長さ.
  * `cond`: `bool(int, int)` 型. `cond(l, r)` は閉区間 $[l, r]$ が条件を満たすかを返す. $l$ を固定したとき $r$ に関して単調 ($r$ が条件を満たすなら $l \leq r' \leq r$ を満たす $r'$ も条件を満たす) である必要がある.
* **戻り値**
  * `Two_Pointers` と同様.
* **計算量**
  * `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/22| document を作成 |
|2026/08/21| 尺取り法に関するメソッドの作成 |