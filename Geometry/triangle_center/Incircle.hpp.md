---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/base.hpp
    title: Geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/object/Circle.hpp
    title: Geometry/object/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/object/Point.hpp
    title: "\u70B9"
  - icon: ':heavy_check_mark:'
    path: Geometry/object/Triangle.hpp
    title: Geometry/object/Triangle.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/triangle_center/Incenter.hpp
    title: "\u4E09\u89D2\u5F62\u306E\u5185\u5FC3"
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
    path: verify/aizu_online_judge/cgl/7B.test.cpp
    title: verify/aizu_online_judge/cgl/7B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Incircle.hpp
  bundledCode: "#line 2 \"Geometry/triangle_center/Incircle.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Incircle.hpp\n\
    \n#line 2 \"Geometry/object/Circle.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/object/Circle.hpp\n\
    \n#line 2 \"Geometry/object/Point.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/object/Point.hpp\n\
    \n#line 2 \"Geometry/base.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/base.hpp\n\
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
    \    }\n};\n#line 6 \"Geometry/base.hpp\"\n\nnamespace geometry {\n    using Real\
    \ = double long;\n    const Real epsilon = 1e-9;\n    const Real pi = acos(static_cast<Real>(-1));\n\
    \n    enum class Inclusion { OUT = -1, ON = 0, IN = 1 };\n    enum class Direction_Relation\
    \ { PARALLEL = 1, ORTHOGONAL = -1, CROSS = 0}; \n\n    inline int sign(const Real\
    \ &r) { return r <= -epsilon ? -1 : r >= epsilon ? 1: 0; }\n    inline int equal(const\
    \ Real &a, const Real &b) { return sign(a - b) == 0; }\n    inline int compare(const\
    \ Real &a, const Real &b) { return sign(b - a); }\n\n    inline int sign(const\
    \ ll &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const ll\
    \ &a, const ll &b) { return sign(a - b) == 0; }\n    inline int compare(const\
    \ ll &a, const ll &b) { return sign(b - a); }\n\n    inline int sign(const int\
    \ &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const int &a,\
    \ const int &b) { return sign(a - b) == 0; }\n    inline int compare(const int\
    \ &a, const int &b) { return sign(b - a); }\n};\n#line 6 \"Geometry/object/Point.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    class Point {\n      \
    \  public:\n        R x, y;\n\n        public:\n        Point(): x(0), y(0) {}\n\
    \        Point(R _x, R _y): x(_x), y(_y) {}\n\n        // \u52A0\u6CD5\n     \
    \   Point& operator+=(const Point &B){\n            x += B.x;\n            y +=\
    \ B.y;\n            return *this;\n        }\n\n        friend Point operator+(const\
    \ Point &P, const Point &Q) { return Point(P) += Q; }\n\n        // \u6E1B\u6CD5\
    \n        Point& operator-=(const Point &B){\n            x -= B.x;\n        \
    \    y -= B.y;\n            return *this;\n        }\n\n        friend Point operator-(const\
    \ Point &P, const Point &Q) { return Point(P) -= Q; }\n\n        // \u30B9\u30AB\
    \u30E9\u30FC\u500D\n        Point& operator*=(const R &a){\n            x *= a;\n\
    \            y *= a;\n            return *this;\n        }\n\n        friend Point\
    \ operator*(const Point &P, const R &a) { return Point(P) *= a; }\n        friend\
    \ Point operator*(const R &a, const Point &P) { return Point(P) *= a; }\n\n  \
    \      Point& operator/=(const R &a){\n            x /= a;\n            y /= a;\n\
    \            return *this;\n        }\n\n        friend Point operator/(const\
    \ Point &P, const R &a) { return Point(P) /= a; }\n\n        Point& operator*=(const\
    \ Point &P){\n            R x1 = P.x * x - P.y * y, y1 = P.y * x + P.x * y;\n\
    \            x = x1;\n            y = y1;\n            return *this;\n       \
    \ }\n\n        friend Point operator*(const Point &P, const Point<R> &Q) { return\
    \ Point(P) *= Q; }\n\n        friend istream& operator>>(istream &is, Point &P)\
    \ {\n            R a, b;\n            is >> a >> b;\n            P = Point(a,\
    \ b);\n            return is;\n        }\n\n        friend ostream& operator<<(ostream\
    \ &os, const Point &P) {\n            return os << P.x << \" \" << P.y;\n    \
    \    }\n\n        inline R norm_2() const { return x * x + y * y; }\n        inline\
    \ double norm() const { return sqrt(norm_2()); }\n        inline R dot(const Point\
    \ B) const { return x * B.x + y * B.y; }\n        inline R det(const Point B)\
    \ const { return x * B.y - y * B.x; }\n\n        inline Point<R> normalize() const\
    \ { return *this / norm(); }\n        inline Point<R> normal() const { return\
    \ Point(-y, x); }\n\n        inline Point<Real> rotate(double theta) const {\n\
    \            Real alpha = sin(theta), beta = cos(theta);\n            Real s =\
    \ beta * x - alpha * y, t = alpha * x + beta * y;\n            return Point(s,\
    \ t);\n        }\n    };\n\n    template<typename R>\n    bool compare_x(const\
    \ Point<R> &A, const Point<R> &B) { return equal(A.x, B.x) ? A.y < B.y : A.x <\
    \ B.x; }\n\n    template<typename R>\n    bool compare_y(const Point<R> &A, const\
    \ Point<R> &B) { return equal(A.y, B.y) ? A.x < B.x : A.y < B.y; }\n\n    template<typename\
    \ R>\n    inline bool operator==(const Point<R> &A, const Point<R> &B) { return\
    \ equal(A.x, B.x) && equal(A.y, B.y); }\n\n    template<typename R>\n    inline\
    \ bool operator!=(const Point<R> &A, const Point<R> &B) { return !(A == B); }\n\
    \n    template<typename R>\n    inline R dot(const Point<R> &A, const Point<R>\
    \ &B) { return A.x * B.x + A.y * B.y; }\n\n    template<typename R>\n    inline\
    \ R cross(const Point<R> &A, const Point<R> &B) { return A.x * B.y - A.y * B.x;\
    \ }\n\n    template<typename R>\n    inline R norm_2(const Point<R> &P) { return\
    \ dot(P, P); }\n\n    template<typename R>\n    inline double norm(const Point<R>\
    \ &P) { return sqrt(norm_2(P)); }\n\n    template<typename R>\n    inline Real\
    \ arg(const Point<R> &P) { return atan2(P.y, P.x); }\n}\n#line 6 \"Geometry/object/Circle.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    class Circle {\n     \
    \   public:\n        Point<R> center;\n        R radius;\n\n        public:\n\
    \        Circle() = default;\n        Circle(const Point<R> &_center, const R\
    \ &_radius): center(_center), radius(_radius) {}\n    };\n\n    template<typename\
    \ R>\n    R Area(const Circle<R> &C) { return pi * C.radius * C.radius; }\n}\n\
    #line 2 \"Geometry/triangle_center/Incenter.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Incenter.hpp\n\
    \n#line 2 \"Geometry/object/Triangle.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/object/Triangle.hpp\n\
    \n#line 6 \"Geometry/object/Triangle.hpp\"\n\nnamespace geometry {\n    template<typename\
    \ R>\n    class Triangle {\n        public:\n        Point<R> A, B, C;\n\n   \
    \     public:\n        Triangle() = default;\n        Triangle(const Point<R>\
    \ a, const Point<R> b, const Point<R> c): A(a), B(b), C(c) {}\n\n        // \u8FBA\
    \ BC, \u8FBA CA, \u8FBA AB \u306E\u9577\u3055\u3092\u51FA\u529B\u3059\u308B.\n\
    \        tuple<double, double, double> edges() const {\n            return make_tuple(norm(C\
    \ - B), norm(A - C), norm(B - A));\n        }\n\n        // [PBC] : [PCA] : [PAB]\
    \ = alpha : beta : gamma \u3092\u6E80\u305F\u3059\u70B9 P \u3092\u6C42\u3081\u308B\
    .\n        Point<R> balance(const R &alpha, const R &beta, const R &gamma) const\
    \ {\n            return (alpha * A + beta * B + gamma * C) / (alpha + beta + gamma);\n\
    \        }\n    };\n\n    template<typename R>\n    R Area(const Triangle<R> &T)\
    \ {\n        auto X = cross(T.B - T.A, T.C - T.A);\n        return sign(X) >=\
    \ 0 ? X / 2 : -X / 2;\n    }\n}\n#line 6 \"Geometry/triangle_center/Incenter.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    Point<R> Incenter(const\
    \ Triangle<R> &T) { \n        auto [a, b, c] = T.edges();\n        return T.balance(a,\
    \ b, c);\n    }\n}\n#line 7 \"Geometry/triangle_center/Incircle.hpp\"\n\nnamespace\
    \ geometry {\n    template<typename R>\n    Circle<R> Incircle(const Triangle<R>\
    \ &T) {\n        Point<R> center = Incenter(T);\n        auto [a, b, c] = T.edges();\n\
    \        double radius = (2 * Area(T)) / (a + b + c);\n        return Circle<R>(center,\
    \ radius);\n    }\n}\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Incircle.hpp\n\
    \n#include\"../object/Circle.hpp\"\n#include\"Incenter.hpp\"\n\nnamespace geometry\
    \ {\n    template<typename R>\n    Circle<R> Incircle(const Triangle<R> &T) {\n\
    \        Point<R> center = Incenter(T);\n        auto [a, b, c] = T.edges();\n\
    \        double radius = (2 * Area(T)) / (a + b + c);\n        return Circle<R>(center,\
    \ radius);\n    }\n}\n"
  dependsOn:
  - Geometry/object/Circle.hpp
  - Geometry/object/Point.hpp
  - Geometry/base.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Geometry/triangle_center/Incenter.hpp
  - Geometry/object/Triangle.hpp
  isVerificationFile: false
  path: Geometry/triangle_center/Incircle.hpp
  requiredBy: []
  timestamp: '2026-10-17 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/cgl/7B.test.cpp
documentation_of: Geometry/triangle_center/Incircle.hpp
layout: document
title: "\u4E09\u89D2\u5F62\u306E\u5185\u63A5\u5186"
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円を求める.

## Theory

中心 $\textrm{P}$, 半径 $r$ の円とは, $d(\textrm{P}, \textrm{X}) = r$ を満たす点 $\textrm{X}$ 全体のことである ( $r > 0$ ).

中心 $\textrm{P}$, 半径 $r$ の円と直線 $\ell$ が接するとは, $\textrm{P}$ から $\ell$ までの距離が $r$ であることをいう. このとき, $\textrm{P}$ から $\ell$ に下ろした垂線の足を接点という. また, 円が線分 $\textrm{X}\textrm{Y}$ に接するとは, 円が直線 $\textrm{X}\textrm{Y}$ に接し, かつ接点が線分 $\textrm{X}\textrm{Y}$ 上にあることをいう.

<div class="proposition" markdown="1">

命題 1
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする. また, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心を $\textrm{I}$ とする.

このとき, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ までの距離はすべて

$$ \dfrac{2S}{a + b + c} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$2$ つのベクトル $\boldsymbol{p} = (p_x, p_y), \boldsymbol{q} = (q_x, q_y)$ に対して $\boldsymbol{p} \times \boldsymbol{q} = p_x q_y - p_y q_x$ とおく. 点 $\textrm{X}$ から直線 $\textrm{B}\textrm{C}$ までの距離は, 三角形 $\textrm{X}\textrm{B}\textrm{C}$ の面積の $\dfrac{2}{a}$ 倍であるから,

$$ \dfrac{1}{a} \left \lvert (\textrm{B} - \textrm{X}) \times (\textrm{C} - \textrm{X}) \right \rvert $$

である.

$\lambda + \mu + \nu = 1$ を満たす実数 $\lambda, \mu, \nu$ を用いて $\textrm{X} = \lambda \textrm{A} + \mu \textrm{B} + \nu \textrm{C}$ と表す. $\times$ は各引数について線形であり, $\boldsymbol{p} \times \boldsymbol{p} = 0, \boldsymbol{q} \times \boldsymbol{p} = -\boldsymbol{p} \times \boldsymbol{q}$ を満たす. $\textrm{B} - \textrm{X} = \lambda (\textrm{B} - \textrm{A}) + \nu (\textrm{B} - \textrm{C})$, $\textrm{C} - \textrm{X} = \lambda (\textrm{C} - \textrm{A}) + \mu (\textrm{C} - \textrm{B})$ であるから, $(\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{B}) = 0$ に注意して展開すると,

$$ \begin{aligned}
(\textrm{B} - \textrm{X}) \times (\textrm{C} - \textrm{X})
&= \lambda^2 (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \mu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{B}) + \lambda \nu (\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda^2 (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \mu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \nu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda (\lambda + \mu + \nu) (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A})
\end{aligned} $$

である. ここで, $2$ 行目では

$$ (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{B}) = (\textrm{B} - \textrm{A}) \times \left((\textrm{C} - \textrm{A}) - (\textrm{B} - \textrm{A}) \right) = (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) $$

$$ (\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{A}) = \left((\textrm{B} - \textrm{A}) - (\textrm{C} - \textrm{A}) \right) \times (\textrm{C} - \textrm{A}) = (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) $$

を用いた. $\left \lvert (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \right \rvert = 2S$ であるから, $\textrm{X}$ から直線 $\textrm{B}\textrm{C}$ までの距離は $\dfrac{2S}{a} \lvert \lambda \rvert$ である.

[三角形の内心](Incenter.hpp) の系 4 より, $\textrm{I}$ は $\lambda = \dfrac{a}{a + b + c}$ の場合であるから, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}$ までの距離は

$$ \dfrac{2S}{a} \cdot \dfrac{a}{a + b + c} = \dfrac{2S}{a + b + c} $$

である. 直線 $\textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ についても, 頂点の役割を入れ替えて同様に計算すると, 距離はともに $\dfrac{2S}{a + b + c}$ である.

</div>

<div class="theorem" markdown="1">

定理 2
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $3$ 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ すべてに接する円がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

$a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする.

**一意性.** 中心 $\textrm{P}$, 半径 $r$ の円が $3$ 辺すべてに接するとし, 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ 上の接点をそれぞれ $\textrm{D}, \textrm{E}, \textrm{F}$ とする. $\textrm{P}\textrm{F}$ は直線 $\textrm{A}\textrm{B}$ に垂直であるから, 三平方の定理より

$$ d(\textrm{A}, \textrm{F})^2 = d(\textrm{A}, \textrm{P})^2 - r^2 $$

である. 同様に $d(\textrm{A}, \textrm{E})^2 = d(\textrm{A}, \textrm{P})^2 - r^2$ であるから, $d(\textrm{A}, \textrm{E}) = d(\textrm{A}, \textrm{F})$ である. 同様に, $d(\textrm{B}, \textrm{F}) = d(\textrm{B}, \textrm{D}), d(\textrm{C}, \textrm{D}) = d(\textrm{C}, \textrm{E})$ である. これらをそれぞれ $x, y, z$ とおく.

$\textrm{D}, \textrm{E}, \textrm{F}$ はそれぞれ線分 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ 上にあるから,

$$ y + z = a, \quad z + x = b, \quad x + y = c $$

である. これを解くと,

$$ x = \dfrac{b + c - a}{2}, \quad y = \dfrac{c + a - b}{2}, \quad z = \dfrac{a + b - c}{2} $$

である. よって, 接点 $\textrm{D}, \textrm{E}$ は $a, b, c$ のみから定まる. $\textrm{P}$ は $\textrm{D}$ を通り直線 $\textrm{B}\textrm{C}$ に垂直な直線と, $\textrm{E}$ を通り直線 $\textrm{C}\textrm{A}$ に垂直な直線の両方の上にある. 直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}$ は平行でないから, この $2$ 本の垂線も平行でなく, $\textrm{P}$ はその交点としてただ一つに定まる. さらに $r = d(\textrm{P}, \textrm{D})$ も定まる. したがって, $3$ 辺すべてに接する円は高々一つである.

**存在性.** 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心を $\textrm{I}$ とし, $r = \dfrac{2S}{a + b + c}$ とおく. $r > 0$ である. 命題 1 より, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ までの距離はすべて $r$ であるから, 中心 $\textrm{I}$, 半径 $r$ の円はこの $3$ 直線に接する.

あとは, 接点が辺上にあることを示せばよい. $\textrm{I}$ から直線 $\textrm{B}\textrm{C}$ に下ろした垂線の足を $\textrm{H}$ とし, 実数 $t$ を用いて $\textrm{H} = \textrm{B} + t (\textrm{C} - \textrm{B})$ と表す. $\textrm{I} - \textrm{H}$ は $\textrm{C} - \textrm{B}$ に垂直であるから,

$$ (\textrm{I} - \textrm{B}) \cdot (\textrm{C} - \textrm{B}) = (\textrm{H} - \textrm{B}) \cdot (\textrm{C} - \textrm{B}) = t a^2 $$

である. $\textrm{I}$ は頂点 $\textrm{B}$ における内角の二等分線上にあるから, $\textrm{I} - \textrm{B}$ と $\textrm{C} - \textrm{B}$ のなす角は $\dfrac{\textrm{B}}{2}$ であり, $0 < \dfrac{\textrm{B}}{2} < \dfrac{\pi}{2}$ であるから左辺は正である. よって $t > 0$ である. 同様に, $\textrm{B}$ と $\textrm{C}$ の役割を入れ替えると $1 - t > 0$ を得る. したがって $0 < t < 1$ であり, $\textrm{H}$ は辺 $\textrm{B}\textrm{C}$ 上にある. 辺 $\textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ についても同様である.

以上から, $3$ 辺すべてに接する円はただ一つ存在する.

</div>

<div class="definition" markdown="1">

定義 3
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $3$ 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ すべてに接するただ一つの円を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円という.

</div>

次の系によって内接円を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 4
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$, 内心を $\textrm{I}$ とする. このとき, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円は, 中心 $\textrm{I}$, 半径 $\dfrac{2S}{a + b + c}$ の円である.

</div>

<div class="proof" markdown="1">

証明
---

定理 2 の証明から従う.

</div>

内心 $\textrm{I}$ は [三角形の内心](Incenter.hpp) の方法で求められる.

以下, 内接円の性質を述べる.

<div class="proposition" markdown="1">

命題 5
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 内接円と辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ の接点をそれぞれ $\textrm{D}, \textrm{E}, \textrm{F}$ とする. このとき,

$$ d(\textrm{A}, \textrm{E}) = d(\textrm{A}, \textrm{F}) = \dfrac{b + c - a}{2} $$

$$ d(\textrm{B}, \textrm{F}) = d(\textrm{B}, \textrm{D}) = \dfrac{c + a - b}{2} $$

$$ d(\textrm{C}, \textrm{D}) = d(\textrm{C}, \textrm{E}) = \dfrac{a + b - c}{2} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

定理 2 の証明の一意性の部分から従う.

</div>

## Contents

```cpp
template<typename R>
Circle<R> Incircle(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の内接円を求める.
* **計算量**
  * $O(1)$.
