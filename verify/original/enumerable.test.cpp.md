---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/enumerable.hpp
    title: enumerable
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"verify/original/enumerable.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
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
    \ {\n        return message.c_str();\n    }\n};\n#line 2 \"template/enumerable.hpp\"\
    \n\n#line 11 \"template/enumerable.hpp\"\n#include <stdexcept>\n#line 13 \"template/enumerable.hpp\"\
    \n\nnamespace enumerable {\n    /// @brief \u30B3\u30F3\u30C6\u30CA\u306E\u5404\
    \u8981\u7D20\u306B\u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u305D\u306E\u7D50\
    \u679C\u3092\u65B0\u3057\u3044 `std::vector` \u3068\u3057\u3066\u8FD4\u3059\u3002\
    \n    ///\n    /// Ruby \u306E `Enumerable#collect` (\u307E\u305F\u306F `map`)\
    \ \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002C++\u306E `std::transform` \u306B\u4F3C\
    \u3066\u3044\u307E\u3059\u304C\u3001\u5E38\u306B\u51FA\u529B\u3068\u3057\u3066\
    \u65B0\u3057\u3044 `std::vector` \u3092\u751F\u6210\u3057\u3066\u8FD4\u3059\u70B9\
    \u304C\u7570\u306A\u308A\u307E\u3059\u3002\n    /// @tparam Container \u30A4\u30C6\
    \u30EC\u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B (e.g.,\
    \ std::vector<T>)\u3002\n    /// @tparam Func \u5404\u8981\u7D20\u306B\u9069\u7528\
    \u3059\u308B\u95A2\u6570\u306E\u578B\u3002\n    /// @param container \u5BFE\u8C61\
    \u306E\u30B3\u30F3\u30C6\u30CA\u3002\n    /// @param func \u5404\u8981\u7D20\u306B\
    \u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8 (\u30E9\
    \u30E0\u30C0\u5F0F\u306A\u3069)\u3002\n    /// @return \u95A2\u6570\u306E\u9069\
    \u7528\u7D50\u679C\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\
    \n    template <typename Container, typename Func>\n    auto collect(const Container&\
    \ container, const Func& func) {\n        using ResultType = std::invoke_result_t<Func,\
    \ typename Container::const_reference>;\n        std::vector<ResultType> result;\n\
    \        if constexpr (requires { std::size(container); }) {\n            result.reserve(std::size(container));\n\
    \        }\n        for (const auto& element : container) {\n            result.push_back(std::invoke(func,\
    \ element));\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u771F\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#select` \u3084\
    \ `Enumerable#filter` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam\
    \ Container \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\
    \u30CA\u306E\u578B\u3002\n    /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\
    \u308B\u6761\u4EF6\u5224\u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\
    \n    /// @param container \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n\
    \    /// @param pred \u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\
    \u3092\u8FD4\u3059\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n   \
    \ /// @return \u6761\u4EF6\u3092\u6E80\u305F\u3059\u8981\u7D20\u3092\u683C\u7D0D\
    \u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n    template <typename Container,\
    \ typename Pred>\n    auto select(const Container& container, const Pred& pred)\
    \ {\n        using T = std::decay_t<typename Container::const_reference>;\n  \
    \      std::vector<T> result;\n        for (const auto& element : container) {\n\
    \            if (std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u507D\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#reject` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam Container \u30A4\u30C6\u30EC\
    \u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B\u3002\n   \
    \ /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\u308B\u6761\u4EF6\u5224\
    \u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\n    /// @param container\
    \ \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n    /// @param pred \u5404\
    \u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\u3092\u8FD4\u3059\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n    /// @return \u6761\u4EF6\
    \u3092\u6E80\u305F\u3055\u306A\u3044\uFF08\u507D\u3068\u306A\u308B\uFF09\u8981\
    \u7D20\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n \
    \   template <typename Container, typename Pred>\n    auto reject(const Container&\
    \ container, const Pred& pred) {\n        using T = std::decay_t<typename Container::const_reference>;\n\
    \        std::vector<T> result;\n        for (const auto& element : container)\
    \ {\n            if (!std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\u3002\n   \
    \ ///\n    /// Ruby \u306E `Enumerable#inject` (\u307E\u305F\u306F `reduce`) \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @param init \u521D\u671F\u5024\u3002\
    \n    /// @param func \u7573\u307F\u8FBC\u307F\u95A2\u6570 (accum, element) ->\
    \ accum\u3002\n    template <typename Container, typename T, typename Func>\n\
    \    auto inject(const Container& container, T init, Func func) {\n        for\
    \ (const auto& element : container) {\n            init = std::invoke(func, init,\
    \ element);\n        }\n        return init;\n    }\n\n    /// @brief \u30B3\u30F3\
    \u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\uFF08\u521D\u671F\
    \u5024\u306A\u3057\uFF09\u3002\n    ///\n    /// Ruby \u306E `Enumerable#inject`\
    \ (\u307E\u305F\u306F `reduce`) \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n \
    \   /// \u30B3\u30F3\u30C6\u30CA\u304C\u7A7A\u306E\u5834\u5408\u306F\u4F8B\u5916\
    \u3092\u6295\u3052\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Func>\n    auto inject(const Container& container, Func func) {\n        auto\
    \ it = std::begin(container);\n        auto end = std::end(container);\n     \
    \   if (it == end) throw std::runtime_error(\"enumerable::inject: container is\
    \ empty\");\n        // \u5024\u306E\u30B3\u30D4\u30FC\u3092\u4F5C\u6210\u3057\
    \u3066\u30A2\u30AD\u30E5\u30E0\u30EC\u30FC\u30BF\u3068\u3059\u308B\n        auto\
    \ result = *it; \n        ++it;\n        for (; it != end; ++it) {\n         \
    \   result = std::invoke(func, result, *it);\n        }\n        return result;\n\
    \    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n    /// Ruby \u306E\
    \ `Enumerable#all?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container, typename Pred>\n    bool all_of(const Container& container, Pred\
    \ pred) {\n        return std::all_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3044\u305A\u308C\u304B\u306E\u8981\u7D20\u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n   \
    \ /// Ruby \u306E `Enumerable#any?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool any_of(const Container&\
    \ container, Pred pred) {\n        return std::any_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3055\u306A\u3044\u304B\u5224\u5B9A\u3059\u308B\u3002\
    \n    /// Ruby \u306E `Enumerable#none?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool none_of(const Container&\
    \ container, Pred pred) {\n        return std::none_of(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6307\u5B9A\u3057\u305F\
    \u5024\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \u3002\n    /// Ruby \u306E `Enumerable#include?` (\u307E\u305F\u306F `member?`)\
    \ \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename Container,\
    \ typename T>\n    bool include(const Container& container, const T& val) {\n\
    \        return std::find(std::begin(container), std::end(container), val) !=\
    \ std::end(container);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u6700\u521D\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E\
    \ `Enumerable#find` (\u307E\u305F\u306F `detect`) \u306B\u76F8\u5F53\u3057\u307E\
    \u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\u5834\u5408\u306F std::nullopt\
    \ \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Pred>\n    auto find(const Container& container, Pred pred) -> std::optional<typename\
    \ Container::value_type> {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return *it;\n\
    \        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u6700\u521D\u306E\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E `Enumerable#find_index` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\
    \u5834\u5408\u306F std::nullopt \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template\
    \ <typename Container, typename Pred>\n    std::optional<size_t> find_index(const\
    \ Container& container, Pred pred) {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return std::distance(std::begin(container),\
    \ it);\n        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059\u3002\n    /// Ruby\
    \ \u306E `Enumerable#count` (\u30D6\u30ED\u30C3\u30AF\u4ED8\u304D) \u306B\u76F8\
    \u5F53\u3057\u307E\u3059\u3002\n    template <typename Container, typename Pred>\n\
    \    size_t count(const Container& container, Pred pred) {\n        return std::count_if(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u8981\u7D20\u3068\u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306B\
    \u5206\u5272\u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#partition` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @return {\u6E80\u305F\u3059\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8, \u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306E\
    \u30EA\u30B9\u30C8} \u306E\u30DA\u30A2\n    template <typename Container, typename\
    \ Pred>\n    auto partition(const Container& container, Pred pred) {\n       \
    \ using T = typename Container::value_type;\n        std::vector<T> true_list,\
    \ false_list;\n        for (const auto& element : container) {\n            if\
    \ (std::invoke(pred, element)) {\n                true_list.push_back(element);\n\
    \            } else {\n                false_list.push_back(element);\n      \
    \      }\n        }\n        return std::make_pair(true_list, false_list);\n \
    \   }\n\n    /// @brief \u30D6\u30ED\u30C3\u30AF\u306E\u8A55\u4FA1\u7D50\u679C\
    \u3054\u3068\u306B\u30B0\u30EB\u30FC\u30D7\u5316\u3059\u308B\u3002\n    /// Ruby\
    \ \u306E `Enumerable#group_by` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n  \
    \  /// @return \u30AD\u30FC -> \u8981\u7D20\u30EA\u30B9\u30C8 \u306E\u30DE\u30C3\
    \u30D7\n    template <typename Container, typename Func>\n    auto group_by(const\
    \ Container& container, Func func) {\n        using T = typename Container::value_type;\n\
    \        using Key = std::invoke_result_t<Func, typename Container::const_reference>;\n\
    \        std::map<Key, std::vector<T>> result;\n        for (const auto& element\
    \ : container) {\n            result[std::invoke(func, element)].push_back(element);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u30D6\u30ED\u30C3\
    \u30AF\u306E\u8A55\u4FA1\u7D50\u679C\u3092\u4F7F\u3063\u3066\u30BD\u30FC\u30C8\
    \u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#sort_by` \u306B\u76F8\u5F53\
    \u3057\u307E\u3059\u3002\n    template <typename Container, typename Func>\n \
    \   auto sort_by(const Container& container, Func func) {\n        using T = typename\
    \ Container::value_type;\n        using Key = std::decay_t<std::invoke_result_t<Func,\
    \ typename Container::const_reference>>;\n        \n        std::vector<std::pair<Key,\
    \ T>> pairs;\n        if constexpr (requires { std::size(container); }) {\n  \
    \          pairs.reserve(std::size(container));\n        }\n        for (const\
    \ auto& element : container) {\n            pairs.emplace_back(std::invoke(func,\
    \ element), element);\n        }\n\n        std::sort(pairs.begin(), pairs.end(),\
    \ [](const auto& a, const auto& b) {\n            return a.first < b.first;\n\
    \        });\n\n        std::vector<T> result;\n        result.reserve(pairs.size());\n\
    \        for (const auto& p : pairs) {\n            result.push_back(p.second);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u91CD\u8907\u3092\
    \u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u3059\uFF08\u51FA\u73FE\u9806\u3092\u4FDD\u6301\uFF09\u3002\n    /// Ruby \u306E\
    \ `Enumerable#uniq` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container>\n    auto uniq(const Container& container) {\n        using T = typename\
    \ Container::value_type;\n        std::vector<T> result;\n        std::set<T>\
    \ seen;\n        for (const auto& element : container) {\n            if (seen.find(element)\
    \ == seen.end()) {\n                seen.insert(element);\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n} // namespace enumerable\n\
    #line 5 \"verify/original/enumerable.test.cpp\"\n\nvoid verify() {\n    // collect\n\
    \    {\n        vector<int> v = {1, 2, 3};\n        auto res = enumerable::collect(v,\
    \ [](int x) { return x * x; });\n        assert(res == vector<int>({1, 4, 9}));\n\
    \    }\n\n    // select\n    {\n        vector<int> v = {1, 2, 3, 4, 5, 6};\n\
    \        auto res = enumerable::select(v, [](int x) { return x % 2 == 0; });\n\
    \        assert(res == vector<int>({2, 4, 6}));\n    }\n\n    // reject\n    {\n\
    \        vector<int> v = {1, 2, 3, 4, 5, 6};\n        auto res = enumerable::reject(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(res == vector<int>({1, 3,\
    \ 5}));\n    }\n\n    // inject\n    {\n        vector<int> v = {1, 2, 3, 4};\n\
    \        assert(enumerable::inject(v, 0, [](int acc, int x) { return acc + x;\
    \ }) == 10);\n        assert(enumerable::inject(v, 100, [](int acc, int x) { return\
    \ acc + x; }) == 110);\n        assert(enumerable::inject(v, [](int acc, int x)\
    \ { return acc + x; }) == 10);\n    }\n\n    // all_of, any_of, none_of\n    {\n\
    \        vector<int> v = {2, 4, 6};\n        assert(enumerable::all_of(v, [](int\
    \ x) { return x % 2 == 0; }));\n        assert(!enumerable::all_of(v, [](int x)\
    \ { return x == 4; }));\n        assert(enumerable::any_of(v, [](int x) { return\
    \ x == 4; }));\n        assert(!enumerable::any_of(v, [](int x) { return x ==\
    \ 5; }));\n        assert(enumerable::none_of(v, [](int x) { return x % 2 != 0;\
    \ }));\n        assert(!enumerable::none_of(v, [](int x) { return x == 4; }));\n\
    \    }\n\n    // include\n    {\n        vector<int> v = {1, 2, 3};\n        assert(enumerable::include(v,\
    \ 2));\n        assert(!enumerable::include(v, 4));\n    }\n\n    // find\n  \
    \  {\n        vector<int> v = {1, 3, 4, 5};\n        auto res = enumerable::find(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(res.has_value() && res.value()\
    \ == 4);\n        assert(!enumerable::find(v, [](int x) { return x > 10; }).has_value());\n\
    \    }\n\n    // find_index\n    {\n        vector<int> v = {1, 3, 4, 5};\n  \
    \      auto res = enumerable::find_index(v, [](int x) { return x % 2 == 0; });\n\
    \        assert(res.has_value() && res.value() == 2);\n        assert(!enumerable::find_index(v,\
    \ [](int x) { return x > 10; }).has_value());\n    }\n\n    // count\n    {\n\
    \        vector<int> v = {1, 2, 3, 2};\n        assert(enumerable::count(v, [](int\
    \ x) { return x == 2; }) == 2);\n    }\n\n    // partition\n    {\n        vector<int>\
    \ v = {1, 2, 3, 4, 5, 6};\n        auto [evens, odds] = enumerable::partition(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(evens == vector<int>({2,\
    \ 4, 6}));\n        assert(odds == vector<int>({1, 3, 5}));\n    }\n\n    // group_by\n\
    \    {\n        vector<string> v = {\"apple\", \"banana\", \"cherry\", \"date\"\
    };\n        auto res = enumerable::group_by(v, [](const string& s) { return s.length();\
    \ });\n        assert(res[4] == vector<string>({\"date\"}));\n        assert(res[5]\
    \ == vector<string>({\"apple\"}));\n        assert(res[6] == vector<string>({\"\
    banana\", \"cherry\"}));\n    }\n\n    // sort_by\n    {\n        vector<string>\
    \ v = {\"long\", \"s\", \"medium\"};\n        auto res = enumerable::sort_by(v,\
    \ [](const string& s) { return s.length(); });\n        assert(res == vector<string>({\"\
    s\", \"long\", \"medium\"}));\n    }\n\n    // uniq\n    {\n        vector<int>\
    \ v = {1, 2, 3, 2, 4, 1, 5};\n        auto res = enumerable::uniq(v);\n      \
    \  assert(res == vector<int>({1, 2, 3, 4, 5}));\n    }\n    {\n        vector<int>\
    \ v = {5, 1, 4, 2, 3, 5, 1};\n        auto res = enumerable::uniq(v);\n      \
    \  assert(res == vector<int>({5, 1, 4, 2, 3}));\n    }\n}\n\nint main() {\n  \
    \  verify();\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../template/enumerable.hpp\"\
    \n\nvoid verify() {\n    // collect\n    {\n        vector<int> v = {1, 2, 3};\n\
    \        auto res = enumerable::collect(v, [](int x) { return x * x; });\n   \
    \     assert(res == vector<int>({1, 4, 9}));\n    }\n\n    // select\n    {\n\
    \        vector<int> v = {1, 2, 3, 4, 5, 6};\n        auto res = enumerable::select(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(res == vector<int>({2, 4,\
    \ 6}));\n    }\n\n    // reject\n    {\n        vector<int> v = {1, 2, 3, 4, 5,\
    \ 6};\n        auto res = enumerable::reject(v, [](int x) { return x % 2 == 0;\
    \ });\n        assert(res == vector<int>({1, 3, 5}));\n    }\n\n    // inject\n\
    \    {\n        vector<int> v = {1, 2, 3, 4};\n        assert(enumerable::inject(v,\
    \ 0, [](int acc, int x) { return acc + x; }) == 10);\n        assert(enumerable::inject(v,\
    \ 100, [](int acc, int x) { return acc + x; }) == 110);\n        assert(enumerable::inject(v,\
    \ [](int acc, int x) { return acc + x; }) == 10);\n    }\n\n    // all_of, any_of,\
    \ none_of\n    {\n        vector<int> v = {2, 4, 6};\n        assert(enumerable::all_of(v,\
    \ [](int x) { return x % 2 == 0; }));\n        assert(!enumerable::all_of(v, [](int\
    \ x) { return x == 4; }));\n        assert(enumerable::any_of(v, [](int x) { return\
    \ x == 4; }));\n        assert(!enumerable::any_of(v, [](int x) { return x ==\
    \ 5; }));\n        assert(enumerable::none_of(v, [](int x) { return x % 2 != 0;\
    \ }));\n        assert(!enumerable::none_of(v, [](int x) { return x == 4; }));\n\
    \    }\n\n    // include\n    {\n        vector<int> v = {1, 2, 3};\n        assert(enumerable::include(v,\
    \ 2));\n        assert(!enumerable::include(v, 4));\n    }\n\n    // find\n  \
    \  {\n        vector<int> v = {1, 3, 4, 5};\n        auto res = enumerable::find(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(res.has_value() && res.value()\
    \ == 4);\n        assert(!enumerable::find(v, [](int x) { return x > 10; }).has_value());\n\
    \    }\n\n    // find_index\n    {\n        vector<int> v = {1, 3, 4, 5};\n  \
    \      auto res = enumerable::find_index(v, [](int x) { return x % 2 == 0; });\n\
    \        assert(res.has_value() && res.value() == 2);\n        assert(!enumerable::find_index(v,\
    \ [](int x) { return x > 10; }).has_value());\n    }\n\n    // count\n    {\n\
    \        vector<int> v = {1, 2, 3, 2};\n        assert(enumerable::count(v, [](int\
    \ x) { return x == 2; }) == 2);\n    }\n\n    // partition\n    {\n        vector<int>\
    \ v = {1, 2, 3, 4, 5, 6};\n        auto [evens, odds] = enumerable::partition(v,\
    \ [](int x) { return x % 2 == 0; });\n        assert(evens == vector<int>({2,\
    \ 4, 6}));\n        assert(odds == vector<int>({1, 3, 5}));\n    }\n\n    // group_by\n\
    \    {\n        vector<string> v = {\"apple\", \"banana\", \"cherry\", \"date\"\
    };\n        auto res = enumerable::group_by(v, [](const string& s) { return s.length();\
    \ });\n        assert(res[4] == vector<string>({\"date\"}));\n        assert(res[5]\
    \ == vector<string>({\"apple\"}));\n        assert(res[6] == vector<string>({\"\
    banana\", \"cherry\"}));\n    }\n\n    // sort_by\n    {\n        vector<string>\
    \ v = {\"long\", \"s\", \"medium\"};\n        auto res = enumerable::sort_by(v,\
    \ [](const string& s) { return s.length(); });\n        assert(res == vector<string>({\"\
    s\", \"long\", \"medium\"}));\n    }\n\n    // uniq\n    {\n        vector<int>\
    \ v = {1, 2, 3, 2, 4, 1, 5};\n        auto res = enumerable::uniq(v);\n      \
    \  assert(res == vector<int>({1, 2, 3, 4, 5}));\n    }\n    {\n        vector<int>\
    \ v = {5, 1, 4, 2, 3, 5, 1};\n        auto res = enumerable::uniq(v);\n      \
    \  assert(res == vector<int>({5, 1, 4, 2, 3}));\n    }\n}\n\nint main() {\n  \
    \  verify();\n    cout << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - template/enumerable.hpp
  isVerificationFile: true
  path: verify/original/enumerable.test.cpp
  requiredBy: []
  timestamp: '2026-02-15 10:09:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/original/enumerable.test.cpp
layout: document
redirect_from:
- /verify/verify/original/enumerable.test.cpp
- /verify/verify/original/enumerable.test.cpp.html
title: verify/original/enumerable.test.cpp
---
