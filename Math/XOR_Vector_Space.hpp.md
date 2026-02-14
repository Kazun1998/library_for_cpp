---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/exception.hpp
    title: template/exception.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "vectors \u304B\u3089\u751F\u6210\u3055\u308C\u308B\u90E8\u5206\
      \u7A7A\u9593\u3092\u751F\u6210\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Math/XOR_Vector_Space.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numeric>\n#include <ostream>\n#include <optional>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll\
    \ = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\
    \u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename\
    \ T, typename U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a =\
    \ b, 1: 0);\n}\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\
    \u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename\
    \ T, typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a =\
    \ b, 1: 0);\n}\n\n// a \u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B\
    .\ntemplate<typename T>\ninline T max(const vector<T> &a){\n    if (a.empty())\
    \ throw invalid_argument(\"vector is empty.\");\n\n    return *max_element(a.begin(),\
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
    \ b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T\
    \ a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        T q;\n\
    \        tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n    \
    \    tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u\
    \ - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n\
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
    \ get_bits(x, bit_length(x)); }\n#line 73 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 4 \"Math/XOR_Vector_Space.hpp\"\
    \n\ntemplate<integral T>\nclass Xor_Vector_Space {\n    vector<T> basis;\n\n \
    \   public:\n    Xor_Vector_Space(): Xor_Vector_Space(vector<T>{}) {}\n\n    ///\
    \ @brief vectors \u304B\u3089\u751F\u6210\u3055\u308C\u308B\u90E8\u5206\u7A7A\u9593\
    \u3092\u751F\u6210\u3059\u308B.\n    /// @param vectors \u751F\u6210\u5143\u306E\
    \u96C6\u5408\n    Xor_Vector_Space(const vector<T> &vectors) {\n        for (T\
    \ x: vectors) {\n            add_vector(x);\n        }\n    }\n\n    /// @brief\
    \ x \u3092\u8FFD\u52A0\u3059\u308B.\n    /// @param x \n    /// @return \u6B21\
    \u5143\u304C\u5897\u3048\u305F\u3089 True. \u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 False.\n    bool add_vector(T x) {\n        T y = projection(x);\n    \
    \    if (y == 0) return false;\n\n        basis.emplace_back(y);\n\n        return\
    \ true;\n    }\n\n    /// @brief x \u3092\u3053\u306E\u7A7A\u9593\u3078\u5C04\u5F71\
    \u3057\u305F\u6642\u306E\u6B8B\u308A\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \n    /// @return x = a + b (b in X) \u3068\u306A\u308B a.\n    T projection(T\
    \ x) const {\n        for (T v: basis) {\n            x = min<T>(x, x ^ v);\n\
    \        }\n\n        return x;\n    }\n\n    /// @brief x \u306F\u3053\u306E\u7A7A\
    \u9593\u306B\u542B\u307E\u308C\u308B\u304B?\n    /// @param x \n    constexpr\
    \ inline bool contains(const T x) const { return projection(x) == 0; }\n\n   \
    \ /// @brief \u3053\u306E\u7A7A\u9593\u306E\u6B21\u5143\u3092\u6C42\u3081\u308B\
    .\n    constexpr inline size_t dimension() const { return basis.size(); }\n\n\
    \    constexpr bool operator<=(const Xor_Vector_Space &W) const {\n        for\
    \ (T x: basis) {\n            if (!W.contains(x)) return false;\n        }\n\n\
    \        return true;\n    }\n\n    constexpr bool operator>=(const Xor_Vector_Space\
    \ &W) const { return W <= *this; }\n    constexpr bool operator<(const Xor_Vector_Space\
    \ &W) const { return (*this <= W) && (this->dimension() < W.dimension()); }\n\
    \    constexpr bool operator>(const Xor_Vector_Space &W) const { return W < *this;\
    \ }\n    constexpr bool operator==(const Xor_Vector_Space &W) const {  return\
    \ (*this <= W) && (this->dimension() == W.dimension()); }\n    constexpr bool\
    \ operator!=(const Xor_Vector_Space &W) const { return !(*this == W); }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<integral\
    \ T>\nclass Xor_Vector_Space {\n    vector<T> basis;\n\n    public:\n    Xor_Vector_Space():\
    \ Xor_Vector_Space(vector<T>{}) {}\n\n    /// @brief vectors \u304B\u3089\u751F\
    \u6210\u3055\u308C\u308B\u90E8\u5206\u7A7A\u9593\u3092\u751F\u6210\u3059\u308B\
    .\n    /// @param vectors \u751F\u6210\u5143\u306E\u96C6\u5408\n    Xor_Vector_Space(const\
    \ vector<T> &vectors) {\n        for (T x: vectors) {\n            add_vector(x);\n\
    \        }\n    }\n\n    /// @brief x \u3092\u8FFD\u52A0\u3059\u308B.\n    ///\
    \ @param x \n    /// @return \u6B21\u5143\u304C\u5897\u3048\u305F\u3089 True.\
    \ \u305D\u3046\u3067\u306A\u3051\u308C\u3070 False.\n    bool add_vector(T x)\
    \ {\n        T y = projection(x);\n        if (y == 0) return false;\n\n     \
    \   basis.emplace_back(y);\n\n        return true;\n    }\n\n    /// @brief x\
    \ \u3092\u3053\u306E\u7A7A\u9593\u3078\u5C04\u5F71\u3057\u305F\u6642\u306E\u6B8B\
    \u308A\u3092\u6C42\u3081\u308B.\n    /// @param x \n    /// @return x = a + b\
    \ (b in X) \u3068\u306A\u308B a.\n    T projection(T x) const {\n        for (T\
    \ v: basis) {\n            x = min<T>(x, x ^ v);\n        }\n\n        return\
    \ x;\n    }\n\n    /// @brief x \u306F\u3053\u306E\u7A7A\u9593\u306B\u542B\u307E\
    \u308C\u308B\u304B?\n    /// @param x \n    constexpr inline bool contains(const\
    \ T x) const { return projection(x) == 0; }\n\n    /// @brief \u3053\u306E\u7A7A\
    \u9593\u306E\u6B21\u5143\u3092\u6C42\u3081\u308B.\n    constexpr inline size_t\
    \ dimension() const { return basis.size(); }\n\n    constexpr bool operator<=(const\
    \ Xor_Vector_Space &W) const {\n        for (T x: basis) {\n            if (!W.contains(x))\
    \ return false;\n        }\n\n        return true;\n    }\n\n    constexpr bool\
    \ operator>=(const Xor_Vector_Space &W) const { return W <= *this; }\n    constexpr\
    \ bool operator<(const Xor_Vector_Space &W) const { return (*this <= W) && (this->dimension()\
    \ < W.dimension()); }\n    constexpr bool operator>(const Xor_Vector_Space &W)\
    \ const { return W < *this; }\n    constexpr bool operator==(const Xor_Vector_Space\
    \ &W) const {  return (*this <= W) && (this->dimension() == W.dimension()); }\n\
    \    constexpr bool operator!=(const Xor_Vector_Space &W) const { return !(*this\
    \ == W); }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Math/XOR_Vector_Space.hpp
  requiredBy: []
  timestamp: '2026-02-14 19:18:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/XOR_Vector_Space.hpp
layout: document
title: "XOR \u30D9\u30AF\u30C8\u30EB\u7A7A\u9593"
---

## Outline

XOR 演算によるベクトル空間に関する計算を行う.

## Definition

任意の非負整数 $x \in \mathbb{N}$ はただ一つの二進数表示

$$ x = \sum_{i=0}^\infty b_i 2^i \quad (b_i \in \{0, 1\}) $$

を持つ.

$\mathbb{F}_2$ 上の列で, 有限個の項を除いて $0$ であるような列全体の集合を $V$ とする.

このとき, $\varphi: \mathbb{N} \to V, \psi: V \to \mathbb{N}$ を

$$ \varphi(x) := (b_i), \quad \psi((b_i)) := \sum_{i=0}^\infty b_i 2^i $$

で定めると, これらは逆写像になる.

また, $V$ はベクトル空間であるため, $\varphi$ や $\psi$ による同一視によって, $\mathbb{N}$ を $\mathbb{F}_2$ 係数のベクトル空間とみなすことができる.

このとき, $\mathbb{N}$ におけるベクトルとしての和を XOR という.

## Theory

以下が従う.

* $\mathbb{N}$ は $\{ 2^i \mid i \in \mathbb{N}\}$ を基底とするベクトル空間である.
* $\mathbb{N}$ は無限次元の空間ではあるが, 実用的には, $V_n := \\{ i \mid 0 \leq i \lt 2^n \\}$ に制限して扱う. この $V_n$ は $\mathbb{N}$ の $n$ 次元部分空間になる.
* $\mathbb{N}$ の零ベクトルは $0$ である.
* $x \in \mathbb{N}$ の逆元 $-x$ は自分自身である. つまり, $-x=x$ である.

## Contents

### Constructor

```cpp
template<integral T>
Xor_Vector_Space()
```

* 型 `T` で扱える範囲に制限した $V_n$ の部分空間 $V$ 生成する.
  * 例
    * `T` = `int` のときは $V_{31} \quad (2^{31} \lt 2.2 \times 10^9 )$.
    * `T` = `long long` のときは $V_{63} \quad (2^{63} \lt 9.3 \times 10^{18})$.

```cpp
template<integral T>
Xor_Vector_Space(const vector<T> &vectors)
```

* `vectors` に含まれる `T` の要素でベクトル空間を生成する.

### add_vector

```cpp
bool add_vector(T x)
```

* ベクトル空間に $x$ を加えて更新する.
* **返り値**
  * $x$ を追加して, 次元が増えるならば `true`, そうでなければ `false`.

### projection

```cpp
bool projection(T x)
```

* 型 `T` の $x$ に対して, $x = a + b, b \in V$ となる型 `T` の $a$ が存在する. この $a$ を求める.
* **返り値** : $x - a \in V$ となる $a$.

### contains

```cpp
bool contains(T x)
```

* $x \in V$ かどうかを判定する.

### dimension

```cpp
bool dimension()
```

* $V$ のベクトル空間としての次元を求める.

### order operator

```cpp
bool operator<=(const Xor_Vector_Space &W)
```

* ベクトル空間として, $V \subset W$ かどうかを判定する.
