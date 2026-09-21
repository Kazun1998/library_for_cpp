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
    path: verify/yukicoder/3166.test.cpp
    title: verify/yukicoder/3166.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089\
      \ r \u307E\u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067\
      ) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp
  bundledCode: "#line 2 \"Imos/Sparse_Cyclic_Imos_1.hpp\"\n\n// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp\n\
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
    \    }\n};\n#line 6 \"Imos/Sparse_Cyclic_Imos_1.hpp\"\n\ntemplate <typename T,\
    \ typename I = long long>\nclass Sparse_Cyclic_Imos_1 {\n    private:\n    std::map<I,\
    \ T> diff;\n    I n;\n\n    inline I norm(I t) const { return ((t % n) + n) %\
    \ n; }\n\n    public:\n    Sparse_Cyclic_Imos_1(const I n) : n(n) {}\n\n    ///\
    \ @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\
    \u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\
    \u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @details l <= r (mod\
    \ \u3067\u6B63\u898F\u5316\u3057\u305F\u4E0A\u3067) \u306E\u3068\u304D\u306F\u901A\
    \u5E38\u306E\u9589\u533A\u9593 [l, r] \u3078\u306E\u52A0\u7B97, l > r \u306E\u3068\
    \u304D\u306F [l, n - 1] \u3068 [0, r] \u3078\u306E\u52A0\u7B97\u3092\u610F\u5473\
    \u3059\u308B.\n    /// @param l \u59CB\u70B9\n    /// @param r \u7D42\u70B9\n\
    \    /// @param x \u52A0\u7B97\u5024\n    void add(I l, I r, const T x = 1) {\n\
    \        if (n == 0) return;\n\n        l = norm(l);\n        r = norm(r);\n\n\
    \        // l <= r : [l, r] \u304C (n-1, 0) \u3092\u307E\u305F\u304C\u306A\u3044\
    \u533A\u9593\u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\u3059\u308B\n   \
    \     if (l <= r) {\n            diff[l] += x;\n            if (r + 1 < n) diff[r\
    \ + 1] -= x;\n        } else {\n            diff[0] += x;\n            diff[r\
    \ + 1] -= x;\n            diff[l] += x;\n        }\n    }\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, \u8981\u7D20 t \u306B x \u3092\u52A0\u7B97\
    \u3059\u308B\n    /// @param t \u52A0\u7B97\u3059\u308B\u4F4D\u7F6E\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_point(const I t, const T x) { add(t, t, x);\
    \ }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l, l + 1,\
    \ ..., l + (k - 1) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\
    \n    /// @param l \u59CB\u70B9\n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\
    \u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\n    void add_forward(const\
    \ I l, const I k, const T x) {\n        if (n == 0 || k <= 0) return;\n\n    \
    \    // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\u7B97\u3059\u308B\u304B\
    , m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\
    \n        const I q = k / n, m = k % n;\n        if (q > 0) add(0, n - 1, x *\
    \ q);\n        if (m > 0) add(l, l + m - 1, x);\n    }\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, r, r - 1, ..., r - (k - 1) \u306E\u5404\
    \u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param r \u59CB\u70B9\
    \n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_back(const I r, const I k, const T x) {\n\
    \        if (n == 0 || k <= 0) return;\n\n        // q : \u5186\u74B0\u3092\u4F55\
    \u5468\u5206\u52A0\u7B97\u3059\u308B\u304B, m : \u7AEF\u6570\u3068\u3057\u3066\
    \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n        const I q = k / n, m = k %\
    \ n;\n        if (q > 0) add(0, n - 1, x * q);\n        if (m > 0) add(r - m +\
    \ 1, r, x);\n    }\n\n    /// @brief \u3053\u308C\u307E\u3067\u306E\u52A0\u7B97\
    \u30AF\u30A8\u30EA\u3092\u5186\u74B0\u5168\u4F53 [0, n - 1] \u306B\u3064\u3044\
    \u3066\u7D2F\u7A4D\u3059\u308B\n    /// @return (y, l, r) \u3068\u3044\u3046\u5F62\
    \u306E\u30EA\u30B9\u30C8. l <= x <= r \u306E\u7BC4\u56F2\u306B\u304A\u3044\u3066\
    \u306F\u7D2F\u7A4D\u548C\u304C y \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\
    \u3059\u308B.\n    std::vector<std::tuple<T, I, I>> cumulative() {\n        std::vector<std::tuple<T,\
    \ I, I>> res;\n        if (n == 0) return res;\n\n        T cum = 0;\n       \
    \ I t_old = 0;\n\n        for (const auto &[t, d] : diff) {\n            if (t\
    \ > n - 1) break;\n            if (d == 0) continue;\n\n            if (t_old\
    \ <= t - 1) res.emplace_back(cum, t_old, t - 1);\n\n            cum += d;\n  \
    \          t_old = t;\n        }\n\n        if (t_old <= n - 1) res.emplace_back(cum,\
    \ t_old, n - 1);\n\n        return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\
    \u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\
    \u72B6\u614B\u306B\u3059\u308B\n    void clear() {\n        diff.clear();\n  \
    \  }\n};\n"
  code: "#pragma once\n\n// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp\n\
    \n#include \"../template/template.hpp\"\n\ntemplate <typename T, typename I =\
    \ long long>\nclass Sparse_Cyclic_Imos_1 {\n    private:\n    std::map<I, T> diff;\n\
    \    I n;\n\n    inline I norm(I t) const { return ((t % n) + n) % n; }\n\n  \
    \  public:\n    Sparse_Cyclic_Imos_1(const I n) : n(n) {}\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067 (l \u304B\
    \u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u7B97\u3059\u308B\n    /// @details l <= r (mod \u3067\u6B63\u898F\
    \u5316\u3057\u305F\u4E0A\u3067) \u306E\u3068\u304D\u306F\u901A\u5E38\u306E\u9589\
    \u533A\u9593 [l, r] \u3078\u306E\u52A0\u7B97, l > r \u306E\u3068\u304D\u306F [l,\
    \ n - 1] \u3068 [0, r] \u3078\u306E\u52A0\u7B97\u3092\u610F\u5473\u3059\u308B\
    .\n    /// @param l \u59CB\u70B9\n    /// @param r \u7D42\u70B9\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add(I l, I r, const T x = 1) {\n        if (n\
    \ == 0) return;\n\n        l = norm(l);\n        r = norm(r);\n\n        // l\
    \ <= r : [l, r] \u304C (n-1, 0) \u3092\u307E\u305F\u304C\u306A\u3044\u533A\u9593\
    \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\u3059\u308B\n        if (l <=\
    \ r) {\n            diff[l] += x;\n            if (r + 1 < n) diff[r + 1] -= x;\n\
    \        } else {\n            diff[0] += x;\n            diff[r + 1] -= x;\n\
    \            diff[l] += x;\n        }\n    }\n\n    /// @brief \u5468\u9577 n\
    \ \u306E\u5186\u74B0\u4E0A\u3067, \u8981\u7D20 t \u306B x \u3092\u52A0\u7B97\u3059\
    \u308B\n    /// @param t \u52A0\u7B97\u3059\u308B\u4F4D\u7F6E\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_point(const I t, const T x) { add(t, t, x);\
    \ }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l, l + 1,\
    \ ..., l + (k - 1) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\
    \n    /// @param l \u59CB\u70B9\n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\
    \u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\n    void add_forward(const\
    \ I l, const I k, const T x) {\n        if (n == 0 || k <= 0) return;\n\n    \
    \    // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\u7B97\u3059\u308B\u304B\
    , m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\
    \n        const I q = k / n, m = k % n;\n        if (q > 0) add(0, n - 1, x *\
    \ q);\n        if (m > 0) add(l, l + m - 1, x);\n    }\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, r, r - 1, ..., r - (k - 1) \u306E\u5404\
    \u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param r \u59CB\u70B9\
    \n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_back(const I r, const I k, const T x) {\n\
    \        if (n == 0 || k <= 0) return;\n\n        // q : \u5186\u74B0\u3092\u4F55\
    \u5468\u5206\u52A0\u7B97\u3059\u308B\u304B, m : \u7AEF\u6570\u3068\u3057\u3066\
    \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n        const I q = k / n, m = k %\
    \ n;\n        if (q > 0) add(0, n - 1, x * q);\n        if (m > 0) add(r - m +\
    \ 1, r, x);\n    }\n\n    /// @brief \u3053\u308C\u307E\u3067\u306E\u52A0\u7B97\
    \u30AF\u30A8\u30EA\u3092\u5186\u74B0\u5168\u4F53 [0, n - 1] \u306B\u3064\u3044\
    \u3066\u7D2F\u7A4D\u3059\u308B\n    /// @return (y, l, r) \u3068\u3044\u3046\u5F62\
    \u306E\u30EA\u30B9\u30C8. l <= x <= r \u306E\u7BC4\u56F2\u306B\u304A\u3044\u3066\
    \u306F\u7D2F\u7A4D\u548C\u304C y \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\
    \u3059\u308B.\n    std::vector<std::tuple<T, I, I>> cumulative() {\n        std::vector<std::tuple<T,\
    \ I, I>> res;\n        if (n == 0) return res;\n\n        T cum = 0;\n       \
    \ I t_old = 0;\n\n        for (const auto &[t, d] : diff) {\n            if (t\
    \ > n - 1) break;\n            if (d == 0) continue;\n\n            if (t_old\
    \ <= t - 1) res.emplace_back(cum, t_old, t - 1);\n\n            cum += d;\n  \
    \          t_old = t;\n        }\n\n        if (t_old <= n - 1) res.emplace_back(cum,\
    \ t_old, n - 1);\n\n        return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\
    \u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\
    \u72B6\u614B\u306B\u3059\u308B\n    void clear() {\n        diff.clear();\n  \
    \  }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Sparse_Cyclic_Imos_1.hpp
  requiredBy: []
  timestamp: '2026-09-22 00:38:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/3166.test.cpp
documentation_of: Imos/Sparse_Cyclic_Imos_1.hpp
layout: document
title: "\u758E\u306A\u5186\u74B0\u4E0A\u306E\u3044\u3082\u3059\u6CD5 (1 \u6B21\u5143\
  \ 0 \u6B21)"
---

## Outline

周長 $n$ が非常に大きい場合でも使用できる, 円環上でいもす法を行うためのクラス.
差分配列を `std::map` で保持することで, 加算クエリの回数を $Q$ としたとき, $n$ に依存せず $O(Q \log Q)$ 程度の時間・空間で処理できる.
[Cyclic_Imos_1](Cyclic_Imos_1.hpp) の疎な (座標圧縮された) 版.

## Theory

[Cyclic_Imos_1](Cyclic_Imos_1.hpp) では差分配列をサイズ $n$ の `std::vector` として保持していたが, $n$ が大きい ($10^{18}$ など) 場合はこれを確保できない.

そこで, 差分が非零となる添字のみを `std::map<I, T>` に保持することで, 実際に加算が行われた箇所のみを管理する. 加算クエリが $Q$ 回であれば, 差分が非零になりうる添字は高々 $O(Q)$ 個であるので, 各クエリを $O(\log Q)$ 時間で処理できる.

最後に, `std::map` に登録された添字を小さい順に走査しながら差分を累積することで, 値が一定となる区間ごとに分割した結果を $O(Q \log Q)$ 時間で列挙できる.

## Contents

### テンプレート引数

* `T`: 加算する値の型.
* `I`: 添字 (円環上の位置) を表す型. デフォルトは `long long`.

### Constructor

```cpp
Sparse_Cyclic_Imos_1(const I n)
```

* 周長 $n$ の疎な円環いもす法オブジェクトを生成する.
* **引数**
  * $n$: 円環の周長 (要素数)
* **計算量** : $O(1)$ 時間.

### add

```cpp
void add(I l, I r, const T x = 1)
```

* 周長 $n$ の円環上で, $l$ から時計回りに $r$ まで ($l$ から $r$ まで) の各要素に $x$ を加算する.
* $l, r$ は $\bmod n$ で正規化される (負の値や $n$ 以上の値を渡してもよい).
* 正規化後に $l \leq r$ ならば, これは通常の閉区間 $[l, r]$ への加算を意味する. $l > r$ ならば, $[l, n-1]$ と $[0, r]$ への加算を意味する.
* **引数**
  * $l$: 始点
  * $r$: 終点
  * $x$: 加算値 (省略時は $1$)
* **計算量** : ならし $O(\log Q)$ 時間 ($Q$ はこれまでの `add` 系クエリの回数).

### add_point

```cpp
void add_point(const I t, const T x)
```

* 周長 $n$ の円環上で, 要素 $t$ (mod で正規化) に $x$ を加算する.
* **引数**
  * $t$: 加算する位置
  * $x$: 加算値
* **計算量** : ならし $O(\log Q)$ 時間.

### add_forward

```cpp
void add_forward(const I l, const I k, const T x)
```

* 周長 $n$ の円環上で, $l, l+1, \dots, l+(k-1)$ (mod で正規化, 円環を複数周してもよい) の各要素に $x$ を加算する.
* **引数**
  * $l$: 始点
  * $k$: 加算する要素数 ($k \leq 0$ の場合は何も行わない)
  * $x$: 加算値
* **計算量** : ならし $O(\log Q)$ 時間.

### add_back

```cpp
void add_back(const I r, const I k, const T x)
```

* 周長 $n$ の円環上で, $r, r-1, \dots, r-(k-1)$ (mod で正規化, 円環を複数周してもよい) の各要素に $x$ を加算する.
* **引数**
  * $r$: 始点
  * $k$: 加算する要素数 ($k \leq 0$ の場合は何も行わない)
  * $x$: 加算値
* **計算量** : ならし $O(\log Q)$ 時間.

### cumulative

```cpp
std::vector<std::tuple<T, I, I>> cumulative()
```

* これまでの加算クエリの結果を, 円環全体 $[0, n-1]$ について累積する.
* 戻り値は $(y, l, r)$ の形の組のリストであり, 各組は「閉区間 $[l, r]$ において累積和が $y$ で一定である」ことを意味する. リストは $l$ の昇順に並び, 区間は $[0, n-1]$ を過不足なく分割する.
* **計算量** : $O(Q \log Q)$ 時間 ($Q$ はこれまでの `add` 系クエリの回数).

### clear

```cpp
void clear()
```

* 内部の差分 `map` を空にし, 再度 `add` を行えるようにクリアする.
* **計算量** : 保持している要素数を $M$ として $O(M)$ 時間.

|日付|内容|
|:---:|:---|
|2026/09/13| 疎な円環いもす法 (1 次元 0 次) の実装 |
