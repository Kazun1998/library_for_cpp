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
    path: verify/original/Functional_Graph.test.cpp
    title: verify/original/Functional_Graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9802\u70B9 x \u304C\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\
      \u70B9\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B."
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Functional_Graph/Functional_Graph.hpp
  bundledCode: "#line 2 \"Functional_Graph/Functional_Graph.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Functional_Graph/Functional_Graph.hpp\n\
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
    \    }\n};\n#line 6 \"Functional_Graph/Functional_Graph.hpp\"\n\nclass Functional_Graph\
    \ {\n    private:\n    struct Cycle {\n        // vertices = (c_0, c_1, ..., c_{m-1})\
    \ \u3067, f(c_j) = c_{j+1}, f(c_{m-1}) = c_0 \u3092\u6E80\u305F\u3059.\n     \
    \   vector<int> vertices;\n\n        Cycle() = default;\n        Cycle(vector<int>\
    \ vertices): vertices(std::move(vertices)) {}\n\n        inline int size() const\
    \ { return vertices.size(); }\n\n        // c_j \u304B\u3089 k \u56DE\u79FB\u52D5\
    \u3057\u305F\u5148\u306E\u9802\u70B9 c_{(j + k) mod m} \u3092\u6C42\u3081\u308B\
    .\n        int jump(int j, ll k) const {\n            int m = size();\n      \
    \      return vertices[(j + safe_mod(k, m)) % m];\n        }\n    };\n\n    struct\
    \ Tree {\n        // vertices[0] \u306F\u6839 (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\
    \u9802\u70B9) \u3067\u3042\u308B.\n        vector<int> vertices;\n\n        //\
    \ depth[i] \u306F vertices[i] \u306E\u6DF1\u3055\u3067\u3042\u308B.\n        vector<int>\
    \ depth;\n\n        // doubling[b][i] \u306F vertices[i] \u304B\u3089 2^b \u56DE\
    \u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9\u306E\u6DFB\u5B57\u3067\u3042\
    \u308B.\n        // \u305F\u3060\u3057, \u6839\u306F\u81EA\u5206\u81EA\u8EAB\u3078\
    \u79FB\u308B\u3068\u3059\u308B.\n        vector<vector<int>> doubling;\n\n   \
    \     Tree() = default;\n\n        // parent[i] \u306F f(vertices[i]) \u306E\u6DFB\
    \u5B57 (parent[0] = 0) \u3067\u3042\u308B.\n        Tree(vector<int> vertices,\
    \ const vector<int> &parent, vector<int> depth): vertices(std::move(vertices)),\
    \ depth(std::move(depth)) {\n            int m = this->vertices.size();\n    \
    \        int max_depth = *max_element(this->depth.begin(), this->depth.end());\n\
    \            int L = max<int>(1, bit_length(max_depth));\n\n            doubling.assign(L,\
    \ vector<int>(m));\n            doubling[0] = parent;\n            for (int b\
    \ = 1; b < L; b++) {\n                for (int i = 0; i < m; i++) {\n        \
    \            doubling[b][i] = doubling[b - 1][doubling[b - 1][i]];\n         \
    \       }\n            }\n        }\n\n        inline int root() const { return\
    \ vertices[0]; }\n\n        // vertices[i] \u304B\u3089 k \u56DE\u79FB\u52D5\u3057\
    \u305F\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B (0 <= k <= depth[i]).\n\
    \        int upper(int i, ll k) const {\n            for (int b = 0; k; k >>=\
    \ 1, b++) {\n                if (k & 1) { i = doubling[b][i]; }\n            }\n\
    \            return vertices[i];\n        }\n    };\n\n    vector<int> f;\n  \
    \  vector<vector<int>> f_inv;\n    int N;\n\n    vector<Cycle> cycles;\n    //\
    \ cycle_ids[x]: x \u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7\
    \ (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u3067\u306A\u3051\u308C\u3070\
    \ -1)\n    // cycle_vertex_ids[x]: x \u306E\u30B5\u30A4\u30AF\u30EB\u5185\u3067\
    \u306E\u6DFB\u5B57 (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u3067\u306A\
    \u3051\u308C\u3070 -1)\n    vector<int> cycle_ids, cycle_vertex_ids;\n\n    vector<Tree>\
    \ trees;\n    // tree_ids[x]: x \u3092\u542B\u3080\u6728\u306E\u756A\u53F7\n \
    \   // tree_vertex_ids[x]: x \u306E\u6728\u306E\u5185\u3067\u306E\u6DFB\u5B57\n\
    \    vector<int> tree_ids, tree_vertex_ids;\n\n    public:\n    Functional_Graph(const\
    \ vector<int> &f): f(f), N(f.size()) {\n        f_inv.resize(N);\n        for\
    \ (int x = 0; x < N; x++) { f_inv[f[x]].emplace_back(x); }\n        build_up();\n\
    \    }\n\n    private:\n    void build_up() {\n        build_cycles();\n     \
    \   build_trees();\n    }\n\n    // \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\u30D1\
    \u30FC\u30C8\n    void build_cycles() {\n        vector<int> indegree(N);\n  \
    \      stack<int> st;\n        for (int x = 0; x < N; x++) {\n            indegree[x]\
    \ = f_inv[x].size();\n            if (indegree[x] == 0) { st.push(x); }\n    \
    \    }\n\n        vector<bool> cycle_flag(N, true);\n\n        while (!st.empty())\
    \ {\n            int x = st.top();\n            st.pop();\n\n            cycle_flag[x]\
    \ = false;\n            indegree[f[x]]--;\n            if (indegree[f[x]] == 0)\
    \ { st.push(f[x]); }\n        }\n\n        cycles.clear();\n        cycle_ids.assign(N,\
    \ -1);\n        cycle_vertex_ids.assign(N, -1);\n\n        for (int x = 0; x <\
    \ N; x++) {\n            unless (cycle_flag[x]) { continue; }\n\n            int\
    \ cycle_id = cycles.size();\n\n            vector<int> vertices{x};\n        \
    \    cycle_flag[x] = false;\n            for (int y = f[x]; y != x; y = f[y])\
    \ {\n                vertices.emplace_back(y);\n                cycle_flag[y]\
    \ = false;\n            }\n\n            int m = vertices.size();\n          \
    \  for (int j = 0; j < m; j++) {\n                cycle_ids[vertices[j]] = cycle_id;\n\
    \                cycle_vertex_ids[vertices[j]] = j;\n            }\n\n       \
    \     cycles.emplace_back(std::move(vertices));\n        }\n    }\n\n    // \u6728\
    \u306E\u69CB\u7BC9\u30D1\u30FC\u30C8\n    void build_trees() {\n        trees.clear();\n\
    \        tree_ids.assign(N, -1);\n        tree_vertex_ids.assign(N, -1);\n\n \
    \       for (int x = 0; x < N; x++) {\n            unless (is_on_cycle(x)) { continue;\
    \ }\n\n            int tree_id = trees.size();\n            vector<int> vertices{x},\
    \ parent{0}, depth{0};\n            tree_ids[x] = tree_id;\n            tree_vertex_ids[x]\
    \ = 0;\n\n            stack<int> st;\n            st.push(x);\n\n            while\
    \ (!st.empty()) {\n                int y = st.top(); st.pop();\n             \
    \   int i = tree_vertex_ids[y];\n\n                for (int z: f_inv[y]) {\n \
    \                   if (is_on_cycle(z)) { continue; }\n\n                    tree_ids[z]\
    \ = tree_id;\n                    tree_vertex_ids[z] = vertices.size();\n\n  \
    \                  vertices.emplace_back(z);\n                    parent.emplace_back(i);\n\
    \                    depth.emplace_back(depth[i] + 1);\n\n                   \
    \ st.push(z);\n                }\n            }\n\n            trees.emplace_back(std::move(vertices),\
    \ parent, std::move(depth));\n        }\n    }\n\n    // x \u304B\u3089 k \u56DE\
    \u79FB\u52D5\u3057\u305F\u3068\u304D\u306B\u30B5\u30A4\u30AF\u30EB\u306B\u5230\
    \u9054\u3057\u3066\u3044\u308B\u304B (f^k(x) \u304C\u30B5\u30A4\u30AF\u30EB\u4E0A\
    \u306E\u9802\u70B9\u304B) \u3092\u5224\u5B9A\u3059\u308B.\n    // f(C) \u2282\
    \ C \u3068\u6DF1\u3055\u306E\u6700\u5C0F\u6027\u3088\u308A, k >= depth(x) \u3068\
    \u540C\u5024\u3067\u3042\u308B.\n    inline bool can_reach_cycle(int x, ll k)\
    \ const { return k >= depth(x); }\n\n    public:\n    /// @brief \u9802\u70B9\
    \ x \u304C\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B.\n    /// @param x \u9802\u70B9\n    /// @return\
    \ \u3042\u308B k >= 1 \u306B\u3064\u3044\u3066 f^k(x) = x \u306A\u3089\u3070 true\n\
    \    inline bool is_on_cycle(int x) const { return cycle_ids[x] != -1; }\n\n \
    \   /// @brief \u9802\u70B9 x \u306E\u6DF1\u3055 (f^k(x) \u304C\u30B5\u30A4\u30AF\
    \u30EB\u4E0A\u306E\u9802\u70B9\u3068\u306A\u308B\u6700\u5C0F\u306E k >= 0) \u3092\
    \u6C42\u3081\u308B.\n    /// @param x \u9802\u70B9\n    /// @return \u9802\u70B9\
    \ x \u306E\u6DF1\u3055\n    inline int depth(int x) const { return trees[tree_ids[x]].depth[tree_vertex_ids[x]];\
    \ }\n\n    /// @brief \u9802\u70B9 x \u306E\u6839 (x \u304B\u3089\u6DF1\u3055\u306E\
    \u56DE\u6570\u3060\u3051\u79FB\u52D5\u3057\u3066\u521D\u3081\u3066\u5230\u9054\
    \u3059\u308B\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9) \u3092\u6C42\u3081\
    \u308B.\n    /// @param x \u9802\u70B9\n    /// @return \u9802\u70B9 x \u306E\u6839\
    \n    inline int root(int x) const { return trees[tree_ids[x]].root(); }\n\n \
    \   /// @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u5F31\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7\u3092\u6C42\u3081\u308B\
    .\n    /// @param x \u9802\u70B9\n    /// @return x \u306E\u6839\u3092\u542B\u3080\
    \u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7 (get_cycle, get_cycles \u306E\u6DFB\
    \u5B57)\n    inline int get_cycle_id(int x) const { return cycle_ids[root(x)];\
    \ }\n\n    /// @brief \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9 c \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u9802\u70B9\u96C6\u5408\u3092\u6C42\u3081\
    \u308B.\n    /// @param c \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\n \
    \   /// @return \u6839\u304C c \u3067\u3042\u308B\u9802\u70B9\u5168\u4F53 (\u5148\
    \u982D\u306F c)\n    const vector<int> &get_tree_vertices(int c) const {\n   \
    \     assert(is_on_cycle(c));\n        return trees[tree_ids[c]].vertices;\n \
    \   }\n\n    /// @brief f^k(x) \u3092\u6C42\u3081\u308B.\n    /// @param x \u9802\
    \u70B9\n    /// @param k \u79FB\u52D5\u56DE\u6570 (k >= 0)\n    /// @return f^k(x)\n\
    \    int calculate(int x, ll k) const {\n        assert(is_non_negative(k));\n\
    \n        const Tree &tree = trees[tree_ids[x]];\n        int i = tree_vertex_ids[x];\n\
    \        unless (can_reach_cycle(x, k)) { return tree.upper(i, k); }\n\n     \
    \   int r = tree.root();\n        return cycles[cycle_ids[r]].jump(cycle_vertex_ids[r],\
    \ k - tree.depth[i]);\n    }\n\n    /// @brief \u30B5\u30A4\u30AF\u30EB\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B.\n    inline int cycle_count() const { return cycles.size();\
    \ }\n\n    /// @brief \u756A\u53F7 id \u306E\u30B5\u30A4\u30AF\u30EB\u3092\u6C42\
    \u3081\u308B.\n    /// @param id \u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7 (0\
    \ <= id < cycle_count())\n    /// @return \u30B5\u30A4\u30AF\u30EB c_0, c_1, ...,\
    \ c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0)\n    const vector<int> &get_cycle(int\
    \ id) const { return cycles[id].vertices; }\n\n    /// @brief \u30B5\u30A4\u30AF\
    \u30EB\u5168\u4F53\u3092\u6C42\u3081\u308B.\n    /// @return \u5404\u30B5\u30A4\
    \u30AF\u30EB c_0, c_1, ..., c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0) \u306E\
    \u30EA\u30B9\u30C8\n    vector<vector<int>> get_cycles() const {\n        vector<vector<int>>\
    \ res;\n        res.reserve(cycles.size());\n        for (const Cycle &cycle:\
    \ cycles) { res.emplace_back(cycle.vertices); }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Functional_Graph/Functional_Graph.hpp\n\
    \n#include\"../template/template.hpp\"\n\nclass Functional_Graph {\n    private:\n\
    \    struct Cycle {\n        // vertices = (c_0, c_1, ..., c_{m-1}) \u3067, f(c_j)\
    \ = c_{j+1}, f(c_{m-1}) = c_0 \u3092\u6E80\u305F\u3059.\n        vector<int> vertices;\n\
    \n        Cycle() = default;\n        Cycle(vector<int> vertices): vertices(std::move(vertices))\
    \ {}\n\n        inline int size() const { return vertices.size(); }\n\n      \
    \  // c_j \u304B\u3089 k \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9\
    \ c_{(j + k) mod m} \u3092\u6C42\u3081\u308B.\n        int jump(int j, ll k) const\
    \ {\n            int m = size();\n            return vertices[(j + safe_mod(k,\
    \ m)) % m];\n        }\n    };\n\n    struct Tree {\n        // vertices[0] \u306F\
    \u6839 (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9) \u3067\u3042\u308B.\n\
    \        vector<int> vertices;\n\n        // depth[i] \u306F vertices[i] \u306E\
    \u6DF1\u3055\u3067\u3042\u308B.\n        vector<int> depth;\n\n        // doubling[b][i]\
    \ \u306F vertices[i] \u304B\u3089 2^b \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\
    \u9802\u70B9\u306E\u6DFB\u5B57\u3067\u3042\u308B.\n        // \u305F\u3060\u3057\
    , \u6839\u306F\u81EA\u5206\u81EA\u8EAB\u3078\u79FB\u308B\u3068\u3059\u308B.\n\
    \        vector<vector<int>> doubling;\n\n        Tree() = default;\n\n      \
    \  // parent[i] \u306F f(vertices[i]) \u306E\u6DFB\u5B57 (parent[0] = 0) \u3067\
    \u3042\u308B.\n        Tree(vector<int> vertices, const vector<int> &parent, vector<int>\
    \ depth): vertices(std::move(vertices)), depth(std::move(depth)) {\n         \
    \   int m = this->vertices.size();\n            int max_depth = *max_element(this->depth.begin(),\
    \ this->depth.end());\n            int L = max<int>(1, bit_length(max_depth));\n\
    \n            doubling.assign(L, vector<int>(m));\n            doubling[0] = parent;\n\
    \            for (int b = 1; b < L; b++) {\n                for (int i = 0; i\
    \ < m; i++) {\n                    doubling[b][i] = doubling[b - 1][doubling[b\
    \ - 1][i]];\n                }\n            }\n        }\n\n        inline int\
    \ root() const { return vertices[0]; }\n\n        // vertices[i] \u304B\u3089\
    \ k \u56DE\u79FB\u52D5\u3057\u305F\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\
    \ (0 <= k <= depth[i]).\n        int upper(int i, ll k) const {\n            for\
    \ (int b = 0; k; k >>= 1, b++) {\n                if (k & 1) { i = doubling[b][i];\
    \ }\n            }\n            return vertices[i];\n        }\n    };\n\n   \
    \ vector<int> f;\n    vector<vector<int>> f_inv;\n    int N;\n\n    vector<Cycle>\
    \ cycles;\n    // cycle_ids[x]: x \u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\u306E\
    \u756A\u53F7 (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u3067\u306A\u3051\
    \u308C\u3070 -1)\n    // cycle_vertex_ids[x]: x \u306E\u30B5\u30A4\u30AF\u30EB\
    \u5185\u3067\u306E\u6DFB\u5B57 (\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\
    \u3067\u306A\u3051\u308C\u3070 -1)\n    vector<int> cycle_ids, cycle_vertex_ids;\n\
    \n    vector<Tree> trees;\n    // tree_ids[x]: x \u3092\u542B\u3080\u6728\u306E\
    \u756A\u53F7\n    // tree_vertex_ids[x]: x \u306E\u6728\u306E\u5185\u3067\u306E\
    \u6DFB\u5B57\n    vector<int> tree_ids, tree_vertex_ids;\n\n    public:\n    Functional_Graph(const\
    \ vector<int> &f): f(f), N(f.size()) {\n        f_inv.resize(N);\n        for\
    \ (int x = 0; x < N; x++) { f_inv[f[x]].emplace_back(x); }\n        build_up();\n\
    \    }\n\n    private:\n    void build_up() {\n        build_cycles();\n     \
    \   build_trees();\n    }\n\n    // \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\u30D1\
    \u30FC\u30C8\n    void build_cycles() {\n        vector<int> indegree(N);\n  \
    \      stack<int> st;\n        for (int x = 0; x < N; x++) {\n            indegree[x]\
    \ = f_inv[x].size();\n            if (indegree[x] == 0) { st.push(x); }\n    \
    \    }\n\n        vector<bool> cycle_flag(N, true);\n\n        while (!st.empty())\
    \ {\n            int x = st.top();\n            st.pop();\n\n            cycle_flag[x]\
    \ = false;\n            indegree[f[x]]--;\n            if (indegree[f[x]] == 0)\
    \ { st.push(f[x]); }\n        }\n\n        cycles.clear();\n        cycle_ids.assign(N,\
    \ -1);\n        cycle_vertex_ids.assign(N, -1);\n\n        for (int x = 0; x <\
    \ N; x++) {\n            unless (cycle_flag[x]) { continue; }\n\n            int\
    \ cycle_id = cycles.size();\n\n            vector<int> vertices{x};\n        \
    \    cycle_flag[x] = false;\n            for (int y = f[x]; y != x; y = f[y])\
    \ {\n                vertices.emplace_back(y);\n                cycle_flag[y]\
    \ = false;\n            }\n\n            int m = vertices.size();\n          \
    \  for (int j = 0; j < m; j++) {\n                cycle_ids[vertices[j]] = cycle_id;\n\
    \                cycle_vertex_ids[vertices[j]] = j;\n            }\n\n       \
    \     cycles.emplace_back(std::move(vertices));\n        }\n    }\n\n    // \u6728\
    \u306E\u69CB\u7BC9\u30D1\u30FC\u30C8\n    void build_trees() {\n        trees.clear();\n\
    \        tree_ids.assign(N, -1);\n        tree_vertex_ids.assign(N, -1);\n\n \
    \       for (int x = 0; x < N; x++) {\n            unless (is_on_cycle(x)) { continue;\
    \ }\n\n            int tree_id = trees.size();\n            vector<int> vertices{x},\
    \ parent{0}, depth{0};\n            tree_ids[x] = tree_id;\n            tree_vertex_ids[x]\
    \ = 0;\n\n            stack<int> st;\n            st.push(x);\n\n            while\
    \ (!st.empty()) {\n                int y = st.top(); st.pop();\n             \
    \   int i = tree_vertex_ids[y];\n\n                for (int z: f_inv[y]) {\n \
    \                   if (is_on_cycle(z)) { continue; }\n\n                    tree_ids[z]\
    \ = tree_id;\n                    tree_vertex_ids[z] = vertices.size();\n\n  \
    \                  vertices.emplace_back(z);\n                    parent.emplace_back(i);\n\
    \                    depth.emplace_back(depth[i] + 1);\n\n                   \
    \ st.push(z);\n                }\n            }\n\n            trees.emplace_back(std::move(vertices),\
    \ parent, std::move(depth));\n        }\n    }\n\n    // x \u304B\u3089 k \u56DE\
    \u79FB\u52D5\u3057\u305F\u3068\u304D\u306B\u30B5\u30A4\u30AF\u30EB\u306B\u5230\
    \u9054\u3057\u3066\u3044\u308B\u304B (f^k(x) \u304C\u30B5\u30A4\u30AF\u30EB\u4E0A\
    \u306E\u9802\u70B9\u304B) \u3092\u5224\u5B9A\u3059\u308B.\n    // f(C) \u2282\
    \ C \u3068\u6DF1\u3055\u306E\u6700\u5C0F\u6027\u3088\u308A, k >= depth(x) \u3068\
    \u540C\u5024\u3067\u3042\u308B.\n    inline bool can_reach_cycle(int x, ll k)\
    \ const { return k >= depth(x); }\n\n    public:\n    /// @brief \u9802\u70B9\
    \ x \u304C\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B.\n    /// @param x \u9802\u70B9\n    /// @return\
    \ \u3042\u308B k >= 1 \u306B\u3064\u3044\u3066 f^k(x) = x \u306A\u3089\u3070 true\n\
    \    inline bool is_on_cycle(int x) const { return cycle_ids[x] != -1; }\n\n \
    \   /// @brief \u9802\u70B9 x \u306E\u6DF1\u3055 (f^k(x) \u304C\u30B5\u30A4\u30AF\
    \u30EB\u4E0A\u306E\u9802\u70B9\u3068\u306A\u308B\u6700\u5C0F\u306E k >= 0) \u3092\
    \u6C42\u3081\u308B.\n    /// @param x \u9802\u70B9\n    /// @return \u9802\u70B9\
    \ x \u306E\u6DF1\u3055\n    inline int depth(int x) const { return trees[tree_ids[x]].depth[tree_vertex_ids[x]];\
    \ }\n\n    /// @brief \u9802\u70B9 x \u306E\u6839 (x \u304B\u3089\u6DF1\u3055\u306E\
    \u56DE\u6570\u3060\u3051\u79FB\u52D5\u3057\u3066\u521D\u3081\u3066\u5230\u9054\
    \u3059\u308B\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9) \u3092\u6C42\u3081\
    \u308B.\n    /// @param x \u9802\u70B9\n    /// @return \u9802\u70B9 x \u306E\u6839\
    \n    inline int root(int x) const { return trees[tree_ids[x]].root(); }\n\n \
    \   /// @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u5F31\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7\u3092\u6C42\u3081\u308B\
    .\n    /// @param x \u9802\u70B9\n    /// @return x \u306E\u6839\u3092\u542B\u3080\
    \u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7 (get_cycle, get_cycles \u306E\u6DFB\
    \u5B57)\n    inline int get_cycle_id(int x) const { return cycle_ids[root(x)];\
    \ }\n\n    /// @brief \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9 c \u3092\
    \u6839\u3068\u3059\u308B\u6728\u306E\u9802\u70B9\u96C6\u5408\u3092\u6C42\u3081\
    \u308B.\n    /// @param c \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\n \
    \   /// @return \u6839\u304C c \u3067\u3042\u308B\u9802\u70B9\u5168\u4F53 (\u5148\
    \u982D\u306F c)\n    const vector<int> &get_tree_vertices(int c) const {\n   \
    \     assert(is_on_cycle(c));\n        return trees[tree_ids[c]].vertices;\n \
    \   }\n\n    /// @brief f^k(x) \u3092\u6C42\u3081\u308B.\n    /// @param x \u9802\
    \u70B9\n    /// @param k \u79FB\u52D5\u56DE\u6570 (k >= 0)\n    /// @return f^k(x)\n\
    \    int calculate(int x, ll k) const {\n        assert(is_non_negative(k));\n\
    \n        const Tree &tree = trees[tree_ids[x]];\n        int i = tree_vertex_ids[x];\n\
    \        unless (can_reach_cycle(x, k)) { return tree.upper(i, k); }\n\n     \
    \   int r = tree.root();\n        return cycles[cycle_ids[r]].jump(cycle_vertex_ids[r],\
    \ k - tree.depth[i]);\n    }\n\n    /// @brief \u30B5\u30A4\u30AF\u30EB\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B.\n    inline int cycle_count() const { return cycles.size();\
    \ }\n\n    /// @brief \u756A\u53F7 id \u306E\u30B5\u30A4\u30AF\u30EB\u3092\u6C42\
    \u3081\u308B.\n    /// @param id \u30B5\u30A4\u30AF\u30EB\u306E\u756A\u53F7 (0\
    \ <= id < cycle_count())\n    /// @return \u30B5\u30A4\u30AF\u30EB c_0, c_1, ...,\
    \ c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0)\n    const vector<int> &get_cycle(int\
    \ id) const { return cycles[id].vertices; }\n\n    /// @brief \u30B5\u30A4\u30AF\
    \u30EB\u5168\u4F53\u3092\u6C42\u3081\u308B.\n    /// @return \u5404\u30B5\u30A4\
    \u30AF\u30EB c_0, c_1, ..., c_{m-1} (f(c_j) = c_{j+1}, f(c_{m-1}) = c_0) \u306E\
    \u30EA\u30B9\u30C8\n    vector<vector<int>> get_cycles() const {\n        vector<vector<int>>\
    \ res;\n        res.reserve(cycles.size());\n        for (const Cycle &cycle:\
    \ cycles) { res.emplace_back(cycle.vertices); }\n        return res;\n    }\n\
    };\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Functional_Graph/Functional_Graph.hpp
  requiredBy: []
  timestamp: '2026-11-21 19:13:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Functional_Graph.test.cpp
documentation_of: Functional_Graph/Functional_Graph.hpp
layout: document
title: Functional Graph
---

## Outline

Functional Graph に関する構造の決定及び, 計算を高速に行う.

## Theory

### 定義と写像との対応

<div class="definition" markdown="1">

定義 1
---

$D = (V, A)$ を有向グラフとする.

任意の頂点 $v \in V$ における出次数が $1$ であるとき, この $D$ は Functional Graph であるという.

</div>

<div class="proposition" markdown="1">

命題 2
---

Functional Graph $D = (V, A)$ の位数を $n$ とすると, サイズも $n$ である.

</div>

<div class="proof" markdown="1">

証明
---

各頂点 $v \in V$ について, $v$ を始点とする有向辺全体の集合を $A_v$ とする. 各有向辺の始点はただ一つであるから, $A_v ~(v \in V)$ は $A$ を分割する. また, $D$ は Functional Graph であるから, $\lvert A_v \rvert$ は $v$ の出次数 $1$ に等しい. よって,

$$\lvert A \rvert = \sum_{v \in V} \lvert A_v \rvert = \sum_{v \in V} 1 = \lvert V \rvert = n$$

である.

</div>

<div class="theorem" markdown="1">

定理 3
---

$V$ を集合とする. このとき, $V$ を頂点集合とする Functional Graph $D = (V, A)$ と写像 $f: V \to V$ は一対一対応する.

</div>

<div class="proof" markdown="1">

証明
---

$V$ を頂点集合とする Functional Graph 全体の集合を $\mathcal{D}$, 写像 $V \to V$ 全体の集合を $\mathcal{F}$ とする. ここで, 有向辺の集合は $A \subset V \times V$ であり, ループ $(v, v)$ も許すものとする.

まず, 写像 $\Phi: \mathcal{D} \to \mathcal{F}$ を構成する. $D = (V, A) \in \mathcal{D}$ とする. 各頂点 $v \in V$ の出次数は $1$ であるから, $(v, w) \in A$ となる $w \in V$ がただ一つ存在する. この $w$ を $f_D(v)$ と書くことにより, 写像 $f_D: V \to V$ が定まる. $\Phi(D) := f_D$ とする.

次に, 写像 $\Psi: \mathcal{F} \to \mathcal{D}$ を構成する. $f \in \mathcal{F}$ とし, $A_f := \lbrace (v, f(v)) \mid v \in V \rbrace$ とする. 各頂点 $v \in V$ について, $v$ を始点とする $A_f$ の有向辺は $(v, f(v))$ のみであるから, $v$ の出次数は $1$ である. よって, $D_f := (V, A_f) \in \mathcal{D}$ であり, $\Psi(f) := D_f$ とする.

任意の $D \in \mathcal{D}$ に対して $\Psi(\Phi(D)) = D$ であることを示す. $D = (V, A) \in \mathcal{D}$ とする. 任意の $v \in V$ について, $f_D$ の定義から $(v, f_D(v)) \in A$ であるので, $A_{f_D} \subset A$ である. 逆に, $(v, w) \in A$ とすると, $v$ を始点とする $A$ の有向辺はただ一つなので $w = f_D(v)$ であり, $(v, w) \in A_{f_D}$ である. よって $A \subset A_{f_D}$ であり, $A_{f_D} = A$, すなわち $\Psi(\Phi(D)) = D$ である.

任意の $f \in \mathcal{F}$ に対して $\Phi(\Psi(f)) = f$ であることを示す. $f \in \mathcal{F}$ とする. 任意の $v \in V$ について, $v$ を始点とする $A_f$ のただ一つの有向辺は $(v, f(v))$ であるから, $f_{D_f}(v) = f(v)$ である. よって $\Phi(\Psi(f)) = f$ である.

以上より, $\Phi$ と $\Psi$ は互いに逆写像であり, $\mathcal{D}$ と $\mathcal{F}$ は一対一対応する.

</div>

### Functional Graph の構造

以下, Functional Graph $D = (V, A)$ に対して, 各 $v \in V$ について $(v, f(v)) \in A$ となる写像 $f: V \to V$ を考える (定理 3). また, $f^0 = \mathrm{id}_V, f^{k+1} = f \circ f^k$ とする.

<div class="definition" markdown="1">

定義 4
---

$D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする.

* ある $k \geq 1$ について $f^k(v) = v$ となるとき, $v \in V$ をサイクル上の頂点という. サイクル上の頂点全体の集合を $C$ とする.
* 相異なる頂点の列 $u_0, u_1, \dots, u_{m-1} ~(m \geq 1)$ が, $0 \leq j < m - 1$ について $(u_j, u_{j+1}) \in A$ であり, かつ $(u_{m-1}, u_0) \in A$ であるとき, この列を $D$ のサイクルという. ただし, 巡回的に並べ替えて得られる列は同じサイクルとみなす.

</div>

<div class="proposition" markdown="1">

命題 5
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. また, $C$ をサイクル上の頂点全体の集合とする. このとき, 以下が成り立つ.

1. $f(C) \subset C$ であり, $f$ の $C$ への制限は $C$ 上の全単射である.
2. $c \in C$ とし, $m := \min \lbrace k \geq 1 \mid f^k(c) = c \rbrace$ とする. このとき, $c, f(c), \dots, f^{m-1}(c)$ は $D$ のサイクルである. 逆に, $c$ を通る $D$ のサイクルはこれに限る. 特に, 各 $c \in C$ を通るサイクルはただ一つ存在し, $D$ のサイクルの頂点集合全体は $C$ を分割する.
3. 任意の $v \in V$ に対して, ある $k \geq 0$ が存在して, $f^k(v) \in C$ となる.

</div>

<div class="proof" markdown="1">

証明
---

(1) $c \in C$ とし, $k \geq 1$ を $f^k(c) = c$ となるように取る. $f^k(f(c)) = f(f^k(c)) = f(c)$ であるから, $f(c) \in C$ である.

次に, $f$ の $C$ への制限が単射であることを示す. $a, b \in C$ が $f(a) = f(b)$ を満たすとする. $k, l \geq 1$ を $f^k(a) = a, f^l(b) = b$ となるように取ると, $f^{kl}(a) = a, f^{kl}(b) = b$ であるから,

$$a = f^{kl}(a) = f^{kl-1}(f(a)) = f^{kl-1}(f(b)) = f^{kl}(b) = b$$

である. よって, $f$ の $C$ への制限は単射である.

最後に, 全射であることを示す. $c \in C$ とし, $k \geq 1$ を $f^k(c) = c$ となるように取る. $c' := f^{k-1}(c)$ とすると, 前半の議論を繰り返し用いて $c' \in C$ であり, $f(c') = f^k(c) = c$ である. よって, $f$ の $C$ への制限は全射である.

(2) $u_j := f^j(c) ~(0 \leq j < m)$ とする. $0 \leq i < j < m$ で $u_i = u_j$ となるものが存在したとすると, 両辺に $f^{m-j}$ を作用させて $f^{m-j+i}(c) = f^m(c) = c$ を得る. $0 < m - j + i < m$ であるから, これは $m$ の最小性に反する. よって, $u_0, \dots, u_{m-1}$ は相異なる. また, $f$ の定義から $(u_j, u_{j+1}) = (u_j, f(u_j)) \in A ~(0 \leq j < m - 1)$ であり, $(u_{m-1}, u_0) = (f^{m-1}(c), f^m(c)) \in A$ である. よって, $u_0, \dots, u_{m-1}$ はサイクルである.

逆に, $w_0, w_1, \dots, w_{l-1}$ を $c$ を通るサイクルとする. 巡回的に並べ替えて $w_0 = c$ としてよい. 各頂点の出次数は $1$ であるから, $(w_j, w_{j+1}) \in A$ より $w_{j+1} = f(w_j)$ であり, 同様に $w_0 = f(w_{l-1})$ である. よって, $w_j = f^j(c) ~(0 \leq j < l)$ かつ $f^l(c) = c$ である. もし $1 \leq k < l$ で $f^k(c) = c$ となるものがあれば $w_k = w_0$ となり, $w_0, \dots, w_{l-1}$ が相異なることに反する. よって $l = m$ であり, このサイクルは $u_0, \dots, u_{m-1}$ と一致する.

以上より, 各 $c \in C$ を通るサイクルはただ一つである. また, 任意のサイクル $w_0, \dots, w_{l-1}$ について, 上と同様に $w_{j+1} = f(w_j) ~(0 \leq j < l - 1)$, $w_0 = f(w_{l-1})$ であるから, $f^l(w_j) = w_j$ であり, サイクルの頂点は全てサイクル上の頂点である. よって, $D$ のサイクルの頂点集合全体は $C$ を分割する.

(3) $n := \lvert V \rvert$ とする. $v, f(v), \dots, f^n(v)$ は $V$ の $n + 1$ 個の元であるから, 鳩の巣原理より, $0 \leq i < j \leq n$ で $f^i(v) = f^j(v)$ となるものが存在する. このとき $f^{j-i}(f^i(v)) = f^i(v)$ であり, $j - i \geq 1$ であるから, $f^i(v) \in C$ である.

</div>

<div class="definition" markdown="1">

定義 6
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. また, $C$ をサイクル上の頂点全体の集合とする.

* $v \in V$ に対して, $d(v) := \min \lbrace k \geq 0 \mid f^k(v) \in C \rbrace$ を $v$ の深さ, $r(v) := f^{d(v)}(v)$ を $v$ の根という (命題 5 (3) より well-defined である).
* $c \in C$ に対して, $T(c) := \lbrace v \in V \mid r(v) = c \rbrace$ とする.
* $c \in C$ に対して, $c$ を通るただ一つのサイクルの頂点集合を $Z(c)$ とする (命題 5 (2)).

</div>

サイクル上の頂点 $v$ については $d(v) = 0, r(v) = v$ である. また, $r$ は写像 $V \to C$ であるから, $T(c) ~(c \in C)$ は $V$ を分割する.

<div class="proposition" markdown="1">

命題 7
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. $c$ をサイクル上の頂点とし, 根が $c$ である頂点全体の集合を $T$ とする. このとき, 以下が成り立つ.

1. $v \in T \setminus \lbrace c \rbrace$ ならば, $f(v) \in T$ であり, $f(v)$ の深さは $v$ の深さより $1$ だけ小さい.
2. $A_T := \lbrace (v, f(v)) \mid v \in T \setminus \lbrace c \rbrace \rbrace$ とすると, 有向グラフ $(T, A_T)$ は $c$ を根とする有向根付き木である. すなわち, $(T, A_T)$ の基礎グラフは木であり, 任意の $v \in T$ について, $v$ から $c$ への $(T, A_T)$ 上の有向路が存在する. また, その長さは $v$ の深さに等しい.

</div>

<div class="proof" markdown="1">

証明
---

深さ, 根を定義 6 の $d, r$ で表し, $C$ をサイクル上の頂点全体の集合とする.

(1) $v \in T \setminus \lbrace c \rbrace$ とする. もし $d(v) = 0$ ならば, $v \in C$ であり $r(v) = v$ であるから $v = c$ となって矛盾する. よって $d(v) \geq 1$ である.

$f^{d(v)-1}(f(v)) = f^{d(v)}(v) \in C$ であるから, $d(f(v)) \leq d(v) - 1$ である. また, ある $k < d(v) - 1$ について $f^k(f(v)) \in C$ であるとすると, $f^{k+1}(v) \in C$ かつ $k + 1 < d(v)$ となり, $d(v)$ の最小性に反する. よって $d(f(v)) = d(v) - 1$ である. さらに,

$$r(f(v)) = f^{d(v)-1}(f(v)) = f^{d(v)}(v) = r(v) = c$$

であるから, $f(v) \in T$ である.

(2) $v \in T$ とし, $v_j := f^j(v) ~(0 \leq j \leq d(v))$ とする. (1) を繰り返し用いると, $0 \leq j \leq d(v)$ について $v_j \in T$ かつ $d(v_j) = d(v) - j$ である. $d(c) = 0$ であるから, $0 \leq j < d(v)$ について $v_j \neq c$ であり, $(v_j, v_{j+1}) = (v_j, f(v_j)) \in A_T$ である. また, $v_{d(v)} = r(v) = c$ である. よって, $v_0, v_1, \dots, v_{d(v)}$ は $v$ から $c$ への長さ $d(v)$ の有向路である. 特に, $(T, A_T)$ の基礎グラフは連結である.

$A_T$ の有向辺 $(v, f(v))$ について, (1) より $d(f(v)) = d(v) - 1 < d(v)$ である. よって, $A_T$ はループを含まず, $(u, w), (w, u)$ の両方を含むこともない. また, 各頂点を始点とする $A_T$ の有向辺は高々 $1$ 本であるから, $A_T$ に重複する有向辺はない. したがって, $(T, A_T)$ の基礎グラフは, $\lvert T \rvert$ 頂点, $\lvert T \rvert - 1$ 辺の連結な単純グラフであり, 木である.

</div>

<div class="theorem" markdown="1">

定理 8
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. $W$ を $D$ の弱連結成分の頂点集合とする. このとき, 以下が成り立つ.

1. $W$ に含まれる $D$ のサイクルはただ一つである.
2. そのサイクルの頂点集合を $Z$ とすると, $W = \lbrace v \in V \mid \text{ある } k \geq 0 \text{ について } f^k(v) \in Z \rbrace$ である.

</div>

<div class="proof" markdown="1">

証明
---

定義 6 の記法を用いる. $D$ のサイクルの頂点集合 $Z$ に対して,

$$W_Z := \lbrace v \in V \mid r(v) \in Z \rbrace = \bigcup_{c \in Z} T(c)$$

とする. 命題 5 (2) より, サイクルの頂点集合全体は $C$ を分割するから, $W_Z$ 全体は $V$ を分割する. 以下, 各 $W_Z$ が弱連結成分であること, $W_Z$ に含まれるサイクルは $Z$ を頂点集合とするものただ一つであること, $W_Z = \lbrace v \in V \mid \text{ある } k \geq 0 \text{ について } f^k(v) \in Z \rbrace$ であることを示す.

まず, 異なる $W_Z$ の間に有向辺がないことを示す. $(v, f(v)) \in A$ とする. $v \notin C$ のときは, $v \in T(r(v)) \setminus \lbrace r(v) \rbrace$ であるから, 命題 7 (1) より $r(f(v)) = r(v)$ である. $v \in C$ のときは, 命題 5 (1) より $f(v) \in C$ であり, $r(f(v)) = f(v) \in Z(v) = Z(r(v))$ である. いずれの場合も $v$ と $f(v)$ は同じ $W_Z$ に属する. よって, 各弱連結成分はある $W_Z$ に含まれる.

次に, $W_Z$ の基礎グラフが連結であることを示す. 命題 7 (2) より, 各 $v \in W_Z$ から $r(v) \in Z$ への有向路が存在し, その頂点は全て $T(r(v)) \subset W_Z$ に属する. また, $Z$ の頂点同士はサイクルの有向辺で結ばれている. よって $W_Z$ は連結であり, 前段と合わせて, $W_Z$ は弱連結成分の頂点集合である.

$W_Z$ に含まれるサイクルの頂点集合を $Z'$ とすると, $Z' \subset C$ であるから, $c' \in Z'$ について $r(c') = c' \in Z$ である. よって $Z \cap Z' \neq \emptyset$ であり, 命題 5 (2) よりサイクルの頂点集合全体は $C$ を分割するから, $Z' = Z$ である. 同じく命題 5 (2) より, 頂点集合が $Z$ であるサイクルはただ一つである. よって (1) が成り立つ.

最後に (2) を示す. $v \in W_Z$ ならば, $f^{d(v)}(v) = r(v) \in Z$ である. 逆に, ある $k \geq 0$ について $f^k(v) \in Z \subset C$ であるとすると, $d(v)$ の最小性より $k \geq d(v)$ であり, $f^k(v) = f^{k - d(v)}(r(v)) \in Z(r(v))$ である. よって $Z \cap Z(r(v)) \neq \emptyset$ であるから, $Z(r(v)) = Z$, すなわち $r(v) \in Z$ であり, $v \in W_Z$ である.

</div>

すなわち, Functional Graph の各弱連結成分は, ただ一つのサイクルと, その各頂点 $c$ を根とし, 根へ向かう向きに有向辺が付いた有向根付き木 $T(c)$ (命題 7) から成る.

### クエリの処理について

続いて, $f^k(x)$ の求め方を述べる. 移動先は, $k$ が深さ未満であれば木の上, 深さ以上であればサイクルの上にある.

<div class="proposition" markdown="1">

命題 9
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph, $f: V \to V$ を $D$ に対応する写像とする. $x \in V$ の深さを $d$, 根を $r$ とし, $r$ を通るサイクルを $c_0, c_1, \dots, c_{m-1}$ ($f(c_i) = c_{i+1} ~(0 \leq i < m - 1)$, $f(c_{m-1}) = c_0$) として, $r = c_j$ とする. このとき, 整数 $k \geq 0$ について以下が成り立つ.

1. $k < d$ ならば, $f^k(x)$ はサイクル上の頂点ではなく, その根は $r$, 深さは $d - k$ である.
2. $k \geq d$ ならば, $f^k(x) = c_{(j + k - d) \bmod m}$ である. 特に, $f^k(x)$ はサイクル上の頂点である.

</div>

<div class="proof" markdown="1">

証明
---

深さ, 根を定義 6 の記号で表す.

(1) $0 \leq i \leq k$ について, $r(f^i(x)) = r$ かつ $d(f^i(x)) = d - i$ であることを $i$ に関する帰納法で示す. $i = 0$ のときは明らかである. $i < k$ について成り立つとすると, $d(f^i(x)) = d - i > d - k > 0$ であるから, $f^i(x) \neq r$ である. よって, 命題 7 (1) より $r(f^{i+1}(x)) = r$ かつ $d(f^{i+1}(x)) = d - i - 1$ である.

特に $d(f^k(x)) = d - k > 0$ であるから, $f^k(x)$ はサイクル上の頂点ではない.

(2) $f^k(x) = f^{k-d}(f^d(x)) = f^{k-d}(r) = f^{k-d}(c_j)$ である. $f(c_i) = c_{(i + 1) \bmod m} ~(0 \leq i < m)$ であるから, $n \geq 0$ に関する帰納法により $f^n(c_j) = c_{(j + n) \bmod m}$ である. $n = k - d$ とすればよい.

</div>

命題 9 (2) より, $k \geq d(x)$ の場合は, 根 $r(x)$ を含むサイクルとその中での $r(x)$ の位置を前計算しておけば, $f^k(x)$ を $O(1)$ 時間で求められる.

$k < d(x)$ の場合は, 命題 9 (1) より, $f^k(x)$ は $x$ を含む木 $T(r(x))$ の中で $x$ から根の方向へ $k$ 回移動した頂点である. これは次の命題によって, 木ごとのダブリングで求められる.

<div class="proposition" markdown="1">

命題 10
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph, $f: V \to V$ を $D$ に対応する写像とする. $c$ をサイクル上の頂点とし, 根が $c$ である頂点全体の集合を $T$ とする. 写像 $g: T \to T$ を

$$g(v) := \begin{cases} f(v) & (v \neq c) \\ c & (v = c) \end{cases}$$

で定める. このとき, $v \in T$ と $0 \leq k \leq d(v)$ を満たす整数 $k$ について, $g^k(v) = f^k(v)$ である. ただし, $d(v)$ は $v$ の深さである.

</div>

<div class="proof" markdown="1">

証明
---

命題 7 (1) より, $v \in T \setminus \lbrace c \rbrace$ ならば $f(v) \in T$ であるから, $g$ は $T$ から $T$ への写像として定まる.

$k$ に関する帰納法で示す. $k = 0$ のときは明らかである. $k < d(v)$ について $g^k(v) = f^k(v)$ が成り立つとする. 命題 9 (1) より $f^k(v)$ はサイクル上の頂点ではないから, $f^k(v) \neq c$ である. よって, $g^{k+1}(v) = g(f^k(v)) = f(f^k(v)) = f^{k+1}(v)$ である.

</div>

以上をもとに, 次のようにして $f^k(x)$ を求める.

**前計算.** サイクル上の頂点の集合 $C$ と各サイクルを求め, 各 $c \in C$ について木 $T(c)$ とその各頂点の深さを求める. これらは $O(N)$ 時間で求められる. さらに, 各 $c \in C$ について, $T(c)$ の頂点の深さの最大値を $D_c$, $L_c := \max(1, \lfloor \log_2 D_c \rfloor + 1)$ ($D_c = 0$ のときは $L_c = 1$) とし, 命題 10 の $g$ について $g^{2^b} ~(0 \leq b < L_c)$ の表を

$$g^{2^b} = g^{2^{b-1}} \circ g^{2^{b-1}} \quad (1 \leq b < L_c)$$

により作る. $D_c \leq N - 1$ より $L_c = O(\log N)$ であるから, この表は $O(\lvert T(c) \rvert \log N)$ 時間で作れる. 定義 6 の後で述べたように $T(c) ~(c \in C)$ は $V$ を分割するので, 前計算全体の計算量は $O(N \log N)$ 時間である.

**クエリ.** $d := d(x)$ とする.

* $k \geq d$ のとき, 命題 9 (2) より $O(1)$ 時間で求められる.
* $k < d$ のとき, $k$ を $2$ 進展開して $k = 2^{b_1} + 2^{b_2} + \dots + 2^{b_s} ~(b_1 < b_2 < \dots < b_s)$ とする. $k < d \leq D_{r(x)}$ より, 各 $b_i$ は $b_i < L_{r(x)}$ を満たす. 命題 10 より

  $$f^k(x) = g^k(x) = g^{2^{b_s}} \circ \dots \circ g^{2^{b_1}} (x)$$

  であるから, 表を $s$ 回引くことで求められる. $s \leq \lfloor \log_2 k \rfloor + 1$ であるから, $O(\log k)$ 時間である.

$d < N$ であるから, いずれの場合も $O(\log N)$ 時間である.

## Contents

以下, $N$ を頂点数とし, 頂点は $0, 1, \dots, N - 1$ で表す. また, $f$ を Functional Graph に対応する写像とし, 深さ $d(x)$, 根 $r(x)$ は定義 6 のものとする.

### Constructor

```cpp
Functional_Graph(const vector<int> &f)
```

* 写像 $f: \lbrace 0, 1, \dots, N - 1 \rbrace \to \lbrace 0, 1, \dots, N - 1 \rbrace$ による Functional Graph を生成する. ただし, $N$ は `f` の長さである.
* サイクルの検出と, サイクル上の各頂点を根とする木 (命題 7) の構築, および木ごとのダブリングの表 (命題 10) の構築を行う.
* **制約**
  * $0 \leq f(x) < N ~(0 \leq x < N)$. 確認は行わない.
* **計算量** : $O(N \log N)$ 時間 (Theory の前計算を参照).

### calculate

```cpp
int F.calculate(int x, ll k) const
```

* $f^k(x)$ を求める.
* $k < d(x)$ のときは, $x$ を含む木の上でダブリングにより $k$ 回移動する (命題 10). $k \geq d(x)$ のときは, 根 $r(x)$ を含むサイクルの上で $k - d(x)$ 回移動する (命題 9 (2)).
* **制約**
  * $0 \leq x < N$.
  * $k \geq 0$. 満たさない場合は `assert` で停止する.
* **計算量** : $O(\log N)$ 時間.
  * 厳密には, $k \geq d(x)$ (すなわち, $f^k(x)$ がサイクル上の頂点) ならば $O(1)$ 時間, $k < d(x)$ ならば $O(\log k)$ 時間 (Theory のクエリを参照).

### is_on_cycle

```cpp
bool F.is_on_cycle(int x) const
```

* $x$ がサイクル上の頂点 (定義 4) かどうかを判定する.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### depth

```cpp
int F.depth(int x) const
```

* $x$ の深さ $d(x)$ を求める.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### root

```cpp
int F.root(int x) const
```

* $x$ の根 $r(x)$ を求める.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### get_cycle_id

```cpp
int F.get_cycle_id(int x) const
```

* $x$ の根 $r(x)$ を含むサイクルの番号を求める. 番号は `get_cycle`, `get_cycles` の添字と対応する.
* 定理 8 より, $2$ 頂点 $x, y$ が同じ弱連結成分に属することと, `F.get_cycle_id(x) == F.get_cycle_id(y)` であることは同値である.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### get_tree_vertices

```cpp
const vector<int> &F.get_tree_vertices(int c) const
```

* サイクル上の頂点 $c$ に対して, $T(c)$ (根が $c$ である頂点全体) を求める.
* 先頭の要素は $c$ である. それ以外の順番は保証しない.
* **制約**
  * $0 \leq c < N$.
  * $c$ はサイクル上の頂点である. 満たさない場合は `assert` で停止する.
* **計算量** : $O(1)$ 時間.

### cycle_count

```cpp
int F.cycle_count() const
```

* サイクルの個数を求める. 定理 8 より, これは弱連結成分の個数に等しい.
* **計算量** : $O(1)$ 時間.

### get_cycle

```cpp
const vector<int> &F.get_cycle(int id) const
```

* 番号 `id` のサイクル $c_0, c_1, \dots, c_{m-1}$ を求める. ここで, $f(c_j) = c_{j+1} ~(0 \leq j < m - 1)$, $f(c_{m-1}) = c_0$ である.
* **制約**
  * `F.cycle_count()` を $M$ として, $0 \leq \mathrm{id} < M$. 確認は行わない.
* **計算量** : $O(1)$ 時間.

### get_cycles

```cpp
vector<vector<int>> F.get_cycles() const
```

* 全てのサイクルを, 番号順に並べたリストとして求める. 各サイクルの形式は `get_cycle` と同じである.
* **計算量** : $O(N)$ 時間.
  * 新しいリストを作って返すため. 特定のサイクルのみが必要な場合は `get_cycle` を用いる.

## History

|日付|内容|
|:---:|:---:|
|2026/11/21| サイクルと木のデータを `Cycle`, `Tree` クラスに再構成 <br> `is_on_cycle`, `depth`, `get_cycle_id`, `get_tree_vertices`, `cycle_count`, `get_cycle` の実装 <br> `get_cycles` の返り値を参照から値に変更 <br> `calculate` で `k` が負のときに `assert` で停止するように変更 <br> ダブリング表の範囲外アクセスと, `calculate` でのダブリング表のコピーを修正 |
|2025/10/26| `root` の実装 |
|2025/10/23| Functional_Graph クラスの実装 <br> `get_cycles` の実装 |
