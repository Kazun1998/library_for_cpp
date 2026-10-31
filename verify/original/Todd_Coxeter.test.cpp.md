---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/Todd_Coxeter.hpp
    title: "Todd\u2013Coxeter \u6CD5"
  - icon: ':heavy_check_mark:'
    path: Union_Find/Union_Find.hpp
    title: Union Find
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
  bundledCode: "#line 1 \"verify/original/Todd_Coxeter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/template.hpp\n\
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
    \    }\n};\n#line 2 \"Algebra/Todd_Coxeter.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Algebra/Todd_Coxeter.hpp\n\
    \n#line 2 \"Union_Find/Union_Find.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Union_Find/Union_Find.hpp\n\
    \nclass Union_Find{\n    private:\n    int N;\n    vector<int> data;\n    int\
    \ _group_number;\n\n    public:\n    Union_Find(int N) : N(N), data(N, -1), _group_number(N)\
    \ {}\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306E\u4EE3\u8868\u5143\u3092\u6C42\
    \u3081\u308B.\n    int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]);\
    \ }\n\n    // \u9802\u70B9\u3092 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_vertex()\
    \ {\n      data.emplace_back(-1);\n      N++;\n      _group_number++;\n\n    \
    \  return N - 1;\n    }\n\n    // \u9802\u70B9\u3092 k \u500B\u8FFD\u52A0\u3059\
    \u308B.\n    vector<int> add_vertices(int k) {\n      vector<int> ids;\n     \
    \ for (; k; k--) { ids.emplace_back(add_vertex()); }\n\n      return ids;\n  \
    \  }\n\n    // x \u3068 y \u3092\u7D50\u5408\u3059\u308B.\n    // force \u3092\
    \ true \u306B\u3059\u308B\u3068, \u5FC5\u305A find(x) \u304C\u6839\u306B\u306A\
    \u308B\u3088\u3046\u306B\u7D50\u5408\u3059\u308B.\n    // \u8FD4\u308A\u5024:\
    \ \u5143\u3005\u975E\u9023\u7D50\u306A\u3089\u3070 true, \u9023\u7D50\u306A\u3089\
    \u3070 false\n    bool unite(int x, int y, bool force = false) {\n        x =\
    \ find(x);\n        y = find(y);\n\n        if (x == y) { return false; }\n\n\
    \        if (!force && (data[x] > data[y])) { swap(x, y); }\n\n        data[x]\
    \ += data[y];\n        data[y] = x;\n\n        _group_number--;\n\n        return\
    \ true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\u304A\u3051\u308B\
    \u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) { return -data[find(x)];\
    \ }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\
    ?\n    int same(int x, int y) { return find(x) == find(y); }\n\n    // \u9023\u7D50\
    \u6210\u5206\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int group_count()\
    \ const { return _group_number; }\n};\n#line 7 \"Algebra/Todd_Coxeter.hpp\"\n\n\
    struct Todd_Coxeter {\n    public:\n    /// @brief \u8A9E. \u6587\u5B57 (0 \u4EE5\
    \u4E0A K \u672A\u6E80\u306E\u6574\u6570) \u306E\u5217. \u7A7A\u5217\u306F\u5358\
    \u4F4D\u5143\u3092\u8868\u3059.\n    using Word = vector<int>;\n\n    /// @brief\
    \ \u95A2\u4FC2\u5F0F (lhs, rhs). lhs = rhs \u3092\u8868\u3059.\n    using Relation\
    \ = pair<Word, Word>;\n\n    private:\n    int K;\n    vector<vector<int>> T;\n\
    \n    // \u4EE5\u4E0B\u306F\u69CB\u6210\u4E2D\u306E\u307F\u4F7F\u3046.\n    Union_Find\
    \ UF;\n    vector<bool> done; // done[alpha]: alpha \u304B\u3089\u5168\u95A2\u4FC2\
    \u5F0F\u3092\u8ABF\u3079, \u5168\u6587\u5B57\u306E\u884C\u304D\u5148\u3092\u5B9A\
    \u7FA9\u6E08\u307F\u304B?\n\n    /// @brief \u5143\u3092 1 \u3064\u8FFD\u52A0\u3059\
    \u308B.\n    /// @return \u8FFD\u52A0\u3057\u305F\u5143\u306E\u756A\u53F7.\n \
    \   int add_vertex() {\n        int alpha = T.size();\n        T.emplace_back(K,\
    \ -1);\n        UF.add_vertex();\n        done.emplace_back(false);\n\n      \
    \  return alpha;\n    }\n\n    /// @brief \u5143 alpha \u306B\u6587\u5B57 x \u3092\
    \u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u3092\u6C42\u3081\u308B. \u672A\u5B9A\
    \u7FA9\u306A\u3089\u3070\u65B0\u3057\u3044\u5143\u3092\u4F5C\u308B.\n    /// @return\
    \ \u884C\u304D\u5148\u306E\u4EE3\u8868\u5143.\n    int step(int alpha, int x)\
    \ {\n        alpha = UF.find(alpha);\n        if (T[alpha][x] == -1) {\n     \
    \       int beta = add_vertex();\n            T[alpha][x] = beta;\n        }\n\
    \n        return UF.find(T[alpha][x]);\n    }\n\n    /// @brief \u5143 alpha \u306B\
    \u8A9E w \u3092\u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u3092\u6C42\u3081\u308B\
    . \u9014\u4E2D\u304C\u672A\u5B9A\u7FA9\u306A\u3089\u3070\u65B0\u3057\u3044\u5143\
    \u3092\u4F5C\u308B.\n    /// @return \u884C\u304D\u5148\u306E\u4EE3\u8868\u5143\
    .\n    int walk(int alpha, const Word &w) {\n        for (int x: w) {\n      \
    \      alpha = step(alpha, x);\n        }\n\n        return UF.find(alpha);\n\
    \    }\n\n    /// @brief \u5143 alpha0 \u3068\u5143 beta0 \u3092\u540C\u4E00\u8996\
    \u3059\u308B. \u540C\u4E00\u8996\u304B\u3089\u5C0E\u304B\u308C\u308B\u4F75\u5408\
    \u3082\u9023\u9396\u7684\u306B\u884C\u3046.\n    void merge(int alpha0, int beta0)\
    \ {\n        vector<pair<int, int>> Q({{alpha0, beta0}});\n\n        until(Q.empty())\
    \ {\n            auto [alpha, beta] = Q.back();\n            Q.pop_back();\n\n\
    \            alpha = UF.find(alpha);\n            beta = UF.find(beta);\n\n  \
    \          unless (UF.unite(alpha, beta)) continue;\n\n            int gamma =\
    \ UF.find(alpha);\n\n            done[gamma] = done[alpha] || done[beta];\n\n\
    \            for (int x = 0; x < K; ++x) {\n                int delta = T[alpha][x];\n\
    \                int epsilon = T[beta][x];\n\n                T[gamma][x] = (delta\
    \ == -1) ? epsilon : delta;\n                if ((delta != -1) && (epsilon !=\
    \ -1)) {\n                    Q.emplace_back(delta, epsilon);\n              \
    \  }\n            }\n        }\n    }\n\n    /// @brief \u5168\u3066\u306E\u5143\
    \u304B\u3089\u5168\u95A2\u4FC2\u5F0F\u3092\u8ABF\u3079, \u5168\u6587\u5B57\u306E\
    \u884C\u304D\u5148\u3092\u5B9A\u7FA9\u3059\u308B.\n    void enumerate(const vector<Relation>\
    \ &R) {\n        add_vertex();\n        for (int alpha = 0; alpha < (int)T.size();\
    \ ++alpha) {\n            if (done[UF.find(alpha)]) { continue; }\n\n        \
    \    for (const auto &[lhs, rhs]: R) {\n                merge(walk(alpha, lhs),\
    \ walk(alpha, rhs));\n            }\n\n            for (int x = 0; x < K; ++x)\
    \ {\n                step(alpha, x);\n            }\n\n            done[UF.find(alpha)]\
    \ = true;\n        }\n    }\n\n    /// @brief \u4EE3\u8868\u5143\u3060\u3051\u306B\
    \u756A\u53F7\u3092\u632F\u308A\u76F4\u3057, T \u3092\u6700\u7D42\u7684\u306A\u8868\
    \u306B\u3059\u308B. \u5358\u4F4D\u5143\u306E\u5C5E\u3059\u308B\u65CF\u304C 0 \u306B\
    \u306A\u308B.\n    void compress() {\n        int N = T.size();\n        vector<int>\
    \ id(N, -1);\n        int m = 0;\n        id[UF.find(0)] = m++;\n        for (int\
    \ alpha = 0; alpha < N; ++alpha) {\n            if (UF.find(alpha) == alpha &&\
    \ id[alpha] == -1) { id[alpha] = m++; }\n        }\n\n        vector<vector<int>>\
    \ S(m, vector<int>(K));\n        for (int alpha = 0; alpha < N; ++alpha) {\n \
    \           unless (UF.find(alpha) == alpha) { continue; }\n\n            for\
    \ (int x = 0; x < K; ++x) {\n                S[id[alpha]][x] = id[UF.find(T[alpha][x])];\n\
    \            }\n        }\n\n        T = move(S);\n    }\n\n    public:\n    ///\
    \ @brief \u6587\u5B57\u304C K \u500B\u306E\u81EA\u7531\u30E2\u30CE\u30A4\u30C9\
    \u3092, \u95A2\u4FC2\u5F0F R \u306E\u5404 lhs = rhs \u3067\u5272\u3063\u305F\u5546\
    \u30E2\u30CE\u30A4\u30C9 M \u3092\u69CB\u6210\u3059\u308B.\n    /// @param K \u6587\
    \u5B57\u306E\u500B\u6570. \u6587\u5B57\u306F 0, ..., K-1.\n    /// @param R \u95A2\
    \u4FC2\u5F0F\u306E\u5217. \u5404 (lhs, rhs) \u306F lhs = rhs \u3092\u8868\u3059\
    .\n    /// @note \u69CB\u6210\u5F8C, T[alpha][x] \u306F\u5143 alpha \u306B\u6587\
    \u5B57 x \u3092\u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u3067, \u5358\u4F4D\u5143\
    \u306F 0.\n    /// @warning M \u306F\u6709\u9650\u3067\u306A\u3051\u308C\u3070\
    \u306A\u3089\u306A\u3044. \u7121\u9650\u306A\u3089\u3070\u7D42\u4E86\u3057\u306A\
    \u3044 (\u4F8B: R \u304C\u7A7A, ab = ba \u306E\u307F).\n    Todd_Coxeter(int K,\
    \ const vector<Relation> &R): K(K), UF(0) {\n        enumerate(R);\n        compress();\n\
    \n        // \u69CB\u6210\u4E2D\u306E\u307F\u4F7F\u3046\u5909\u6570\u3092\u89E3\
    \u653E\u3059\u308B.\n        UF = Union_Find(0);\n        done = vector<bool>();\n\
    \    }\n\n    /// @brief \u53F3\u304B\u3089\u306E\u4F5C\u7528\u8868\u3092\u8FD4\
    \u3059.\n    /// @return T[alpha][x]: \u5143 alpha \u306B\u6587\u5B57 x \u3092\
    \u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u306E\u756A\u53F7 (\u8AAD\u307F\u53D6\
    \u308A\u5C02\u7528).\n    const vector<vector<int>> &table() const { return T;\
    \ }\n\n    /// @brief M \u306E\u4F4D\u6570 (\u5143\u306E\u500B\u6570) \u3092\u6C42\
    \u3081\u308B.\n    int order() const { return T.size(); }\n\n    /// @brief \u5143\
    \ alpha \u306B\u6587\u5B57 x \u3092\u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u306E\
    \u756A\u53F7\u3092\u6C42\u3081\u308B.\n    /// @param alpha \u5143\u306E\u756A\
    \u53F7 (0 \u4EE5\u4E0A order() \u672A\u6E80).\n    /// @param x \u6587\u5B57 (0\
    \ \u4EE5\u4E0A K \u672A\u6E80).\n    int act(int alpha, int x) const { return\
    \ T[alpha][x]; }\n\n    /// @brief \u8A9E w \u304C\u8868\u3059\u5143\u306E\u756A\
    \u53F7\u3092\u6C42\u3081\u308B.\n    /// @param w \u6587\u5B57\u306E\u5217. \u5404\
    \u6587\u5B57\u306F 0 \u4EE5\u4E0A K \u672A\u6E80. \u7A7A\u5217\u306F\u5358\u4F4D\
    \u5143\u3092\u8868\u3059.\n    /// @return \u5143\u306E\u756A\u53F7 (\u5358\u4F4D\
    \u5143\u306F 0).\n    int eval(const Word &w) const {\n        int alpha = 0;\n\
    \        for (int x: w) {\n            alpha = T[alpha][x];\n        }\n\n   \
    \     return alpha;\n    }\n};\n#line 5 \"verify/original/Todd_Coxeter.test.cpp\"\
    \n\nusing TC = Todd_Coxeter;\nusing Word = TC::Word;\nusing Relation = TC::Relation;\n\
    \nWord power(int x, int n) { return Word(n, x); }\n\n// \u4F5C\u7528\u8868\u304C\
    \u8868\u793A\u3068\u6574\u5408\u3057\u3066\u3044\u308B\u304B\u3092\u691C\u8A3C\
    \u3059\u308B.\nvoid check_consistency(const TC &M, int K, const vector<Relation>\
    \ &R) {\n    int n = M.order();\n\n    // \u5358\u4F4D\u5143\u306E\u756A\u53F7\
    \u306F 0.\n    assert(M.eval({}) == 0);\n\n    // \u4F5C\u7528\u8868\u306E\u5024\
    \u306F\u7BC4\u56F2\u5185\u3067, \u5168\u3066\u306E\u5143\u306F\u5358\u4F4D\u5143\
    \u304B\u3089\u5230\u9054\u3067\u304D\u308B.\n    vector<bool> seen(n, false);\n\
    \    seen[0] = true;\n    queue<int> Q;\n    Q.push(0);\n    while (!Q.empty())\
    \ {\n        int c = Q.front(); Q.pop();\n        for (int x = 0; x < K; ++x)\
    \ {\n            int d = M.act(c, x);\n            assert(0 <= d && d < n);\n\
    \            if (!seen[d]) { seen[d] = true; Q.push(d); }\n        }\n    }\n\
    \    assert(count(seen.begin(), seen.end(), true) == n);\n\n    // \u5168\u3066\
    \u306E\u5143\u306B\u5BFE\u3057\u3066, \u5404\u95A2\u4FC2\u5F0F\u306E\u4E21\u8FBA\
    \u306E\u4F5C\u7528\u5148\u304C\u4E00\u81F4\u3059\u308B.\n    for (int c = 0; c\
    \ < n; ++c) {\n        for (const auto &[l, r]: R) {\n            int cl = c,\
    \ cr = c;\n            for (int x: l) { cl = M.act(cl, x); }\n            for\
    \ (int x: r) { cr = M.act(cr, x); }\n            assert(cl == cr);\n        }\n\
    \    }\n\n    // eval \u306F act \u3092\u7E70\u308A\u8FD4\u3057\u305F\u3082\u306E\
    \u3068\u4E00\u81F4\u3059\u308B.\n    for (const auto &[l, r]: R) {\n        assert(M.eval(l)\
    \ == M.eval(r));\n    }\n}\n\nvoid verify() {\n    const int a = 0, b = 1;\n\n\
    \    // \u4F4D\u6570 3 \u306E\u5DE1\u56DE\u7FA4\n    {\n        vector<Relation>\
    \ R = {{power(a, 3), {}}};\n        TC M(1, R);\n        assert(M.order() == 3);\n\
    \        assert(M.eval(power(a, 3)) == M.eval({}));\n        assert(M.eval(power(a,\
    \ 2)) != M.eval({a}));\n        check_consistency(M, 1, R);\n    }\n\n    // \u7FA4\
    \u306B\u306A\u3089\u306A\u3044\u30E2\u30CE\u30A4\u30C9 <a | a^3 = a>\n    {\n\
    \        vector<Relation> R = {{power(a, 3), {a}}};\n        TC M(1, R);\n   \
    \     assert(M.order() == 3);\n        assert(M.eval(power(a, 3)) == M.eval({a}));\n\
    \        assert(M.eval(power(a, 2)) != M.eval({a}));\n        assert(M.eval({a})\
    \ != M.eval({}));\n        check_consistency(M, 1, R);\n    }\n\n    // \u81EA\
    \u660E\u306A\u30E2\u30CE\u30A4\u30C9 <a | a = e>\n    {\n        vector<Relation>\
    \ R = {{{a}, {}}};\n        TC M(1, R);\n        assert(M.order() == 1);\n   \
    \     check_consistency(M, 1, R);\n    }\n\n    // \u51AA\u7B49\u306A\u5143\u304C\
    \u751F\u6210\u3059\u308B\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n    {\n        vector<Relation>\
    \ R = {{power(a, 2), {a}}, {power(b, 2), {b}}, {{a, b}, {b, a}}};\n        TC\
    \ M(2, R);\n        assert(M.order() == 4);\n        assert(M.eval({a, b}) ==\
    \ M.eval({b, a}));\n        assert(M.eval({a, b, a}) == M.eval({a, b}));\n   \
    \     check_consistency(M, 2, R);\n    }\n\n    // \u96F6\u5143 z \u3092\u6301\
    \u3064\u30E2\u30CE\u30A4\u30C9 <a, z | a^2 = z, az = za = z^2 = z>\n    {\n  \
    \      const int z = 1;\n        vector<Relation> R = {{power(a, 2), {z}}, {{a,\
    \ z}, {z}}, {{z, a}, {z}}, {{z, z}, {z}}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 3);\n        assert(M.eval({a, a}) == M.eval({z}));\n        assert(M.eval({a})\
    \ != M.eval({z}));\n        check_consistency(M, 2, R);\n    }\n\n    // \u5BFE\
    \u79F0\u7FA4 S_3\n    {\n        vector<Relation> R = {{power(a, 2), {}}, {power(b,\
    \ 2), {}}, {{a, b, a, b, a, b}, {}}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 6);\n        assert(M.eval({a, b, a}) == M.eval({b, a, b}));\n        assert(M.eval({a,\
    \ b}) != M.eval({b, a}));\n        check_consistency(M, 2, R);\n    }\n\n    //\
    \ \u4EA4\u4EE3\u7FA4 A_4 = <a, b | a^2, b^3, (ab)^3>, \u5BFE\u79F0\u7FA4 S_4 =\
    \ <a, b | a^2, b^3, (ab)^4>\n    {\n        vector<Relation> R = {{power(a, 2),\
    \ {}}, {power(b, 3), {}}, {{a, b, a, b, a, b}, {}}};\n        TC M(2, R);\n  \
    \      assert(M.order() == 12);\n        check_consistency(M, 2, R);\n\n     \
    \   R.back() = {{a, b, a, b, a, b, a, b}, {}};\n        TC N(2, R);\n        assert(N.order()\
    \ == 24);\n        check_consistency(N, 2, R);\n    }\n\n    // \u56DB\u5143\u6570\
    \u7FA4 Q_8 = <a, b | a^4 = e, a^2 = b^2, b^{-1} a b = a^{-1}>\n    // b^4 = a^4\
    \ = e \u306A\u306E\u3067 b^{-1} = b^3, a^{-1} = a^3 \u3068\u3057\u3066\u66F8\u304F\
    .\n    {\n        vector<Relation> R = {{power(a, 4), {}}, {power(a, 2), power(b,\
    \ 2)}, {{b, b, b, a, b}, power(a, 3)}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 8);\n        check_consistency(M, 2, R);\n    }\n\n    // Coxeter \u751F\u6210\
    \u5143\u306B\u3088\u308B\u5BFE\u79F0\u7FA4 S_n \u306E\u4F4D\u6570\u306F n!\n \
    \   {\n        ll fact = 1;\n        for (int n = 2; n <= 6; ++n) {\n        \
    \    fact *= n;\n\n            int K = n - 1;\n            vector<Relation> R;\n\
    \            for (int i = 0; i < K; ++i) { R.push_back({{i, i}, {}}); }\n    \
    \        for (int i = 0; i + 1 < K; ++i) { R.push_back({{i, i + 1, i}, {i + 1,\
    \ i, i + 1}}); }\n            for (int i = 0; i < K; ++i) {\n                for\
    \ (int j = i + 2; j < K; ++j) { R.push_back({{i, j}, {j, i}}); }\n           \
    \ }\n\n            TC M(K, R);\n            assert(M.order() == fact);\n     \
    \       check_consistency(M, K, R);\n        }\n    }\n}\n\nint main() {\n   \
    \ verify();\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include\"../../template/template.hpp\"\n#include\"../../Algebra/Todd_Coxeter.hpp\"\
    \n\nusing TC = Todd_Coxeter;\nusing Word = TC::Word;\nusing Relation = TC::Relation;\n\
    \nWord power(int x, int n) { return Word(n, x); }\n\n// \u4F5C\u7528\u8868\u304C\
    \u8868\u793A\u3068\u6574\u5408\u3057\u3066\u3044\u308B\u304B\u3092\u691C\u8A3C\
    \u3059\u308B.\nvoid check_consistency(const TC &M, int K, const vector<Relation>\
    \ &R) {\n    int n = M.order();\n\n    // \u5358\u4F4D\u5143\u306E\u756A\u53F7\
    \u306F 0.\n    assert(M.eval({}) == 0);\n\n    // \u4F5C\u7528\u8868\u306E\u5024\
    \u306F\u7BC4\u56F2\u5185\u3067, \u5168\u3066\u306E\u5143\u306F\u5358\u4F4D\u5143\
    \u304B\u3089\u5230\u9054\u3067\u304D\u308B.\n    vector<bool> seen(n, false);\n\
    \    seen[0] = true;\n    queue<int> Q;\n    Q.push(0);\n    while (!Q.empty())\
    \ {\n        int c = Q.front(); Q.pop();\n        for (int x = 0; x < K; ++x)\
    \ {\n            int d = M.act(c, x);\n            assert(0 <= d && d < n);\n\
    \            if (!seen[d]) { seen[d] = true; Q.push(d); }\n        }\n    }\n\
    \    assert(count(seen.begin(), seen.end(), true) == n);\n\n    // \u5168\u3066\
    \u306E\u5143\u306B\u5BFE\u3057\u3066, \u5404\u95A2\u4FC2\u5F0F\u306E\u4E21\u8FBA\
    \u306E\u4F5C\u7528\u5148\u304C\u4E00\u81F4\u3059\u308B.\n    for (int c = 0; c\
    \ < n; ++c) {\n        for (const auto &[l, r]: R) {\n            int cl = c,\
    \ cr = c;\n            for (int x: l) { cl = M.act(cl, x); }\n            for\
    \ (int x: r) { cr = M.act(cr, x); }\n            assert(cl == cr);\n        }\n\
    \    }\n\n    // eval \u306F act \u3092\u7E70\u308A\u8FD4\u3057\u305F\u3082\u306E\
    \u3068\u4E00\u81F4\u3059\u308B.\n    for (const auto &[l, r]: R) {\n        assert(M.eval(l)\
    \ == M.eval(r));\n    }\n}\n\nvoid verify() {\n    const int a = 0, b = 1;\n\n\
    \    // \u4F4D\u6570 3 \u306E\u5DE1\u56DE\u7FA4\n    {\n        vector<Relation>\
    \ R = {{power(a, 3), {}}};\n        TC M(1, R);\n        assert(M.order() == 3);\n\
    \        assert(M.eval(power(a, 3)) == M.eval({}));\n        assert(M.eval(power(a,\
    \ 2)) != M.eval({a}));\n        check_consistency(M, 1, R);\n    }\n\n    // \u7FA4\
    \u306B\u306A\u3089\u306A\u3044\u30E2\u30CE\u30A4\u30C9 <a | a^3 = a>\n    {\n\
    \        vector<Relation> R = {{power(a, 3), {a}}};\n        TC M(1, R);\n   \
    \     assert(M.order() == 3);\n        assert(M.eval(power(a, 3)) == M.eval({a}));\n\
    \        assert(M.eval(power(a, 2)) != M.eval({a}));\n        assert(M.eval({a})\
    \ != M.eval({}));\n        check_consistency(M, 1, R);\n    }\n\n    // \u81EA\
    \u660E\u306A\u30E2\u30CE\u30A4\u30C9 <a | a = e>\n    {\n        vector<Relation>\
    \ R = {{{a}, {}}};\n        TC M(1, R);\n        assert(M.order() == 1);\n   \
    \     check_consistency(M, 1, R);\n    }\n\n    // \u51AA\u7B49\u306A\u5143\u304C\
    \u751F\u6210\u3059\u308B\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\n    {\n        vector<Relation>\
    \ R = {{power(a, 2), {a}}, {power(b, 2), {b}}, {{a, b}, {b, a}}};\n        TC\
    \ M(2, R);\n        assert(M.order() == 4);\n        assert(M.eval({a, b}) ==\
    \ M.eval({b, a}));\n        assert(M.eval({a, b, a}) == M.eval({a, b}));\n   \
    \     check_consistency(M, 2, R);\n    }\n\n    // \u96F6\u5143 z \u3092\u6301\
    \u3064\u30E2\u30CE\u30A4\u30C9 <a, z | a^2 = z, az = za = z^2 = z>\n    {\n  \
    \      const int z = 1;\n        vector<Relation> R = {{power(a, 2), {z}}, {{a,\
    \ z}, {z}}, {{z, a}, {z}}, {{z, z}, {z}}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 3);\n        assert(M.eval({a, a}) == M.eval({z}));\n        assert(M.eval({a})\
    \ != M.eval({z}));\n        check_consistency(M, 2, R);\n    }\n\n    // \u5BFE\
    \u79F0\u7FA4 S_3\n    {\n        vector<Relation> R = {{power(a, 2), {}}, {power(b,\
    \ 2), {}}, {{a, b, a, b, a, b}, {}}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 6);\n        assert(M.eval({a, b, a}) == M.eval({b, a, b}));\n        assert(M.eval({a,\
    \ b}) != M.eval({b, a}));\n        check_consistency(M, 2, R);\n    }\n\n    //\
    \ \u4EA4\u4EE3\u7FA4 A_4 = <a, b | a^2, b^3, (ab)^3>, \u5BFE\u79F0\u7FA4 S_4 =\
    \ <a, b | a^2, b^3, (ab)^4>\n    {\n        vector<Relation> R = {{power(a, 2),\
    \ {}}, {power(b, 3), {}}, {{a, b, a, b, a, b}, {}}};\n        TC M(2, R);\n  \
    \      assert(M.order() == 12);\n        check_consistency(M, 2, R);\n\n     \
    \   R.back() = {{a, b, a, b, a, b, a, b}, {}};\n        TC N(2, R);\n        assert(N.order()\
    \ == 24);\n        check_consistency(N, 2, R);\n    }\n\n    // \u56DB\u5143\u6570\
    \u7FA4 Q_8 = <a, b | a^4 = e, a^2 = b^2, b^{-1} a b = a^{-1}>\n    // b^4 = a^4\
    \ = e \u306A\u306E\u3067 b^{-1} = b^3, a^{-1} = a^3 \u3068\u3057\u3066\u66F8\u304F\
    .\n    {\n        vector<Relation> R = {{power(a, 4), {}}, {power(a, 2), power(b,\
    \ 2)}, {{b, b, b, a, b}, power(a, 3)}};\n        TC M(2, R);\n        assert(M.order()\
    \ == 8);\n        check_consistency(M, 2, R);\n    }\n\n    // Coxeter \u751F\u6210\
    \u5143\u306B\u3088\u308B\u5BFE\u79F0\u7FA4 S_n \u306E\u4F4D\u6570\u306F n!\n \
    \   {\n        ll fact = 1;\n        for (int n = 2; n <= 6; ++n) {\n        \
    \    fact *= n;\n\n            int K = n - 1;\n            vector<Relation> R;\n\
    \            for (int i = 0; i < K; ++i) { R.push_back({{i, i}, {}}); }\n    \
    \        for (int i = 0; i + 1 < K; ++i) { R.push_back({{i, i + 1, i}, {i + 1,\
    \ i, i + 1}}); }\n            for (int i = 0; i < K; ++i) {\n                for\
    \ (int j = i + 2; j < K; ++j) { R.push_back({{i, j}, {j, i}}); }\n           \
    \ }\n\n            TC M(K, R);\n            assert(M.order() == fact);\n     \
    \       check_consistency(M, K, R);\n        }\n    }\n}\n\nint main() {\n   \
    \ verify();\n    cout << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Algebra/Todd_Coxeter.hpp
  - Union_Find/Union_Find.hpp
  isVerificationFile: true
  path: verify/original/Todd_Coxeter.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 19:47:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/original/Todd_Coxeter.test.cpp
layout: document
redirect_from:
- /verify/verify/original/Todd_Coxeter.test.cpp
- /verify/verify/original/Todd_Coxeter.test.cpp.html
title: verify/original/Todd_Coxeter.test.cpp
---
