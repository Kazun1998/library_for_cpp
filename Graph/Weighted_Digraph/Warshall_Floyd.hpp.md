---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Common.hpp
    title: "\u91CD\u307F\u306A\u3057\u3092\u8868\u3059\u578B"
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Digraph.hpp
    title: "\u6709\u5411 Graph"
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Path.hpp
    title: Graph/Digraph/Path.hpp
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/1C.test.cpp
    title: verify/aizu_online_judge/grl/1C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5168\u70B9\u5BFE\u6700\u77ED\u8DEF\u306E\u7D50\u679C"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Weighted_Digraph/Warshall_Floyd.hpp
  bundledCode: "#line 2 \"Graph/Weighted_Digraph/Warshall_Floyd.hpp\"\n\n// Source:\
    \ https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Weighted_Digraph/Warshall_Floyd.hpp\n\
    \n#line 2 \"Graph/Digraph/Digraph.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Digraph/Digraph.hpp\n\
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
    \    }\n};\n#line 2 \"Graph/Common.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Common.hpp\n\
    \n#line 6 \"Graph/Common.hpp\"\n\nnamespace graph_common {\n    /// @brief \u91CD\
    \u307F\u306A\u3057\u3092\u8868\u3059\u578B\n    /// \u8FBA\u30FB\u5F27\u306E\u91CD\
    \u307F\u306E\u578B W \u306E\u65E2\u5B9A\u5024\u3068\u3057\u3066\u4F7F\u3046\u7A7A\
    \u306E\u578B.\n    struct Empty {};\n}\n#line 7 \"Graph/Digraph/Digraph.hpp\"\n\
    \nnamespace digraph {\n    using graph_common::Empty;\n\n    /**\n     * @brief\
    \ \u5F27\n     * @tparam W \u91CD\u307F\u306E\u578B (\u91CD\u307F\u306A\u3057\u306E\
    \u5834\u5408\u306F Empty)\n     */\n    template<typename W = Empty>\n    struct\
    \ Arc {\n        int id, source, target;\n        [[no_unique_address]] W weight;\n\
    \n        Arc(): id(-1), source(-1), target(-1), weight() {}\n        Arc(int\
    \ id, int source, int target, W weight): id(id), source(source), target(target),\
    \ weight(weight) {}\n    };\n\n    /**\n     * @brief \u6709\u5411 Graph\n   \
    \  * @tparam W \u91CD\u307F\u306E\u578B (\u91CD\u307F\u306A\u3057\u306E\u5834\u5408\
    \u306F Empty)\n     * @note \u5F27\u306F\u5024\u3067\u4FDD\u6301\u3059\u308B.\
    \ add_arc \u3092\u547C\u3076\u3068 get_arc \u3067\u5F97\u305F\u53C2\u7167\u306F\
    \u7121\u52B9\u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B.\n     */\n\
    \    template<typename W = Empty>\n    class Digraph {\n        public:\n    \
    \    using Arc_Type = Arc<W>;\n\n        private:\n        int arc_id_offset;\n\
    \        vector<vector<int>> adjacent_out, adjacent_in;\n        vector<Arc_Type>\
    \ arcs;\n\n        public:\n        /**\n         * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n         * @param n \u9802\u70B9\u6570\n         * @param\
    \ arc_id_offset \u5F27 ID \u306E\u30AA\u30D5\u30BB\u30C3\u30C8\n         */\n\
    \        Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {\n\
    \            adjacent_out.assign(n, {});\n            adjacent_in.assign(n, {});\n\
    \            arcs.resize(arc_id_offset);\n        }\n\n        /**\n         *\
    \ @brief \u9802\u70B9\u6570\u3092\u53D6\u5F97\u3059\u308B\n         * @return\
    \ int \u9802\u70B9\u6570\n         */\n        inline int order() const { return\
    \ int(adjacent_in.size()); }\n\n        /**\n         * @brief \u5F27\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\n         * @return int \u5F27\u6570\n         */\n \
    \       inline int size() const { return int(arcs.size()) - arc_id_offset; }\n\
    \n        /**\n         * @brief \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\
    \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B (\u91CD\u307F\u306A\u3057\u7528)\n\
    \         * @return int \u8FFD\u52A0\u3055\u308C\u305F\u5F27\u306E ID\n      \
    \   */\n        int add_arc(int u, int v) requires same_as<W, Empty> { return\
    \ add_arc(u, v, Empty()); }\n\n        /**\n         * @brief \u9802\u70B9 u \u304B\
    \u3089\u9802\u70B9 v \u3078\u306E\u91CD\u307F w \u306E\u5F27\u3092\u8FFD\u52A0\
    \u3059\u308B\n         * @return int \u8FFD\u52A0\u3055\u308C\u305F\u5F27\u306E\
    \ ID\n         */\n        int add_arc(int u, int v, W w) {\n            int id\
    \ = int(arcs.size());\n\n            arcs.emplace_back(id, u, v, w);\n       \
    \     adjacent_out[u].emplace_back(id);\n            adjacent_in[v].emplace_back(id);\n\
    \n            return id;\n        }\n\n        /**\n         * @brief \u9802\u70B9\
    \ u \u304B\u3089\u51FA\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\
    \u5F97\u3059\u308B\n         */\n        inline const vector<int>& successors(int\
    \ u) const { return adjacent_out[u]; }\n\n        /**\n         * @brief \u9802\
    \u70B9 u \u306B\u5165\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\
    \u5F97\u3059\u308B\n         */\n        inline const vector<int>& predecessors(int\
    \ u) const { return adjacent_in[u]; }\n\n        /**\n         * @brief \u5F27\
    \ ID \u304C id \u3067\u3042\u308B\u5F27\u3092\u53D6\u5F97\u3059\u308B\n      \
    \   */\n        inline const Arc_Type& get_arc(int id) const { return arcs[id];\
    \ }\n        inline Arc_Type& get_arc(int id) { return arcs[id]; }\n\n       \
    \ /**\n         * @brief \u9802\u70B9 v \u306E\u51FA\u6B21\u6570\u3092\u53D6\u5F97\
    \u3059\u308B\n         */\n        inline int out_degree(const int v) const {\
    \ return adjacent_out[v].size(); }\n\n        /**\n         * @brief \u9802\u70B9\
    \ v \u306E\u5165\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\n         */\n    \
    \    inline int in_degree(const int v) const { return adjacent_in[v].size(); }\n\
    \n        /**\n         * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u96C6\
    \u5408\u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u3092\u53D6\u5F97\u3059\u308B\n         * @param sources \u59CB\u70B9\u306E\
    \u96C6\u5408\n         * @return vector<int> \u5230\u9054\u53EF\u80FD\u306A\u9802\
    \u70B9\u306E\u30EA\u30B9\u30C8\n         */\n        vector<int> forward_reachable(const\
    \ vector<int> &sources) const {\n            const int n = order();\n        \
    \    vector<bool> visited(n, false);\n            vector<int> reachable;\n\n \
    \           for (const int s : sources) {\n                if (s < 0 || s >= n\
    \ || visited[s]) continue;\n                visited[s] = true;\n             \
    \   reachable.emplace_back(s);\n            }\n\n            for (int head = 0;\
    \ head < reachable.size(); ++head) {\n                const int u = reachable[head];\n\
    \                for (const int id : adjacent_out[u]) {\n                    const\
    \ int v = arcs[id].target;\n                    if (visited[v]) continue;\n\n\
    \                    visited[v] = true;\n                    reachable.emplace_back(v);\n\
    \                }\n            }\n\n            return reachable;\n        }\n\
    \n        /**\n         * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u304B\
    \u3089\u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\
    \u53D6\u5F97\u3059\u308B\n         */\n        vector<int> forward_reachable(const\
    \ int source) const { return forward_reachable(vector<int>{source}); }\n\n   \
    \     /**\n         * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u96C6\u5408\
    \u3078\u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\
    \u53D6\u5F97\u3059\u308B\n         * @param targets \u7D42\u70B9\u306E\u96C6\u5408\
    \n         * @return vector<int> \u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\
    \u30EA\u30B9\u30C8\n         */\n        vector<int> backward_reachable(const\
    \ vector<int> &targets) const {\n            const int n = order();\n        \
    \    vector<bool> visited(n, false);\n            vector<int> reachable;\n\n \
    \           for (const int t : targets) {\n                if (t < 0 || t >= n\
    \ || visited[t]) continue;\n                visited[t] = true;\n             \
    \   reachable.emplace_back(t);\n            }\n\n            for (int head = 0;\
    \ head < reachable.size(); ++head) {\n                const int u = reachable[head];\n\
    \                for (const int id : adjacent_in[u]) {\n                    const\
    \ int v = arcs[id].source;\n                    if (visited[v]) continue;\n\n\
    \                    visited[v] = true;\n                    reachable.emplace_back(v);\n\
    \                }\n            }\n\n            return reachable;\n        }\n\
    \n        /**\n         * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u3078\
    \u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53D6\
    \u5F97\u3059\u308B\n         */\n        vector<int> backward_reachable(const\
    \ int target) const { return backward_reachable(vector<int>{target}); }\n    };\n\
    }\n#line 2 \"Graph/Digraph/Path.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Digraph/Path.hpp\n\
    \n#line 6 \"Graph/Digraph/Path.hpp\"\n\nnamespace digraph {\n    template<typename\
    \ W = Empty>\n    struct Path {\n        vector<int> vertices;\n        vector<Arc<W>>\
    \ arcs;\n\n        Path(const int first, const vector<Arc<W>> &path): arcs(path)\
    \ {\n            vertices.emplace_back(first);\n            for (const auto &arc:\
    \ path) {\n                vertices.emplace_back(arc.target);\n            }\n\
    \        }\n    };\n}\n#line 7 \"Graph/Weighted_Digraph/Warshall_Floyd.hpp\"\n\
    \nnamespace weighted_digraph::warshall_floyd {\n    template<typename W> struct\
    \ Result;\n    template<typename W> Result<W> Warshall_Floyd(const digraph::Digraph<W>\
    \ &D);\n\n    /// @brief \u5168\u70B9\u5BFE\u6700\u77ED\u8DEF\u306E\u7D50\u679C\
    \n    template<typename W>\n    struct Result {\n        /// @brief parent_arc_ids[u][v]:\
    \ u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u306B\u304A\u3051\u308B v \u306B\
    \u5165\u308B\u5F27\u306E ID. u = v \u3084, \u610F\u5473\u3092\u6301\u305F\u306A\
    \u3044\u3068\u304D\u306F -1.\n        vector<vector<int>> parent_arc_ids;\n\n\
    \        /// @brief \u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u304B.\n\
    \        bool has_negative_cycle() const {\n            for (int v = 0; v < int(dist.size());\
    \ ++v) {\n                if (dist[v][v] < W()) { return true; }\n           \
    \ }\n            return false;\n        }\n\n        /// @brief u \u304B\u3089\
    \ v \u306B\u5230\u9054\u53EF\u80FD\u304B.\n        bool is_reachable(int u, int\
    \ v) const { return reachable[u][v]; }\n\n        /// @brief u \u304B\u3089 v\
    \ \u3078\u306E\u6700\u77ED\u8DEF\u9577\u304C -\u221E \u304B.\n        bool is_unbounded(int\
    \ u, int v) const { return unbounded[u][v]; }\n\n        /// @brief u \u304B\u3089\
    \ v \u3078\u306E\u6700\u77ED\u8DEF\u9577\u304C (-\u221E \u3067\u306F\u306A\u3044\
    ) \u6709\u9650\u5024\u3068\u3057\u3066\u5B58\u5728\u3059\u308B\u304B.\n      \
    \  bool is_finite(int u, int v) const { return is_reachable(u, v) && !is_unbounded(u,\
    \ v); }\n\n        /// @brief u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577\
    . is_finite(u, v) \u306E\u3068\u304D\u306E\u307F\u610F\u5473\u3092\u6301\u3064\
    .\n        W distance(int u, int v) const { return dist[u][v]; }\n\n        ///\
    \ @brief start \u304B\u3089 goal \u3078\u306E\u6700\u77ED\u8DEF\u3092\u5FA9\u5143\
    \u3059\u308B.\n        /// @return \u6700\u77ED\u8DEF. goal \u306B\u5230\u9054\
    \u3067\u304D\u306A\u3044, \u307E\u305F\u306F\u6700\u77ED\u8DEF\u9577\u304C -\u221E\
    \ \u306E\u3068\u304D\u306F nullopt.\n        optional<digraph::Path<W>> restore(const\
    \ digraph::Digraph<W> &D, int start, int goal) const {\n            if (!is_finite(start,\
    \ goal)) { return nullopt; }\n\n            vector<digraph::Arc<W>> arcs;\n  \
    \          for (int v = goal; v != start; ) {\n                const auto &arc\
    \ = D.get_arc(parent_arc_ids[start][v]);\n                arcs.emplace_back(arc);\n\
    \                v = arc.source;\n            }\n\n            reverse(arcs.begin(),\
    \ arcs.end());\n            return digraph::Path<W>(start, arcs);\n        }\n\
    \n        private:\n        friend Result<W> Warshall_Floyd<W>(const digraph::Digraph<W>\
    \ &D);\n\n        /// @brief reachable[u][v]: u \u304B\u3089 v \u306B\u5230\u9054\
    \u53EF\u80FD\u304B.\n        vector<vector<bool>> reachable;\n\n        /// @brief\
    \ unbounded[u][v]: u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577\u304C\
    \ -\u221E \u304B (u \u304B\u3089 v \u3078\u306E\u9014\u4E2D\u3067\u8CA0\u9589\u8DEF\
    \u3092\u7D4C\u7531\u3067\u304D\u308B\u304B).\n        vector<vector<bool>> unbounded;\n\
    \n        /// @brief dist[u][v]: u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\
    \u9577. is_finite(u, v) \u306E\u3068\u304D\u306E\u307F\u610F\u5473\u3092\u6301\
    \u3064.\n        vector<vector<W>> dist;\n    };\n\n    /// @brief Warshall-Floyd\
    \ \u6CD5\u306B\u3088\u308A, \u5168\u9802\u70B9\u5BFE\u306E\u6700\u77ED\u8DEF\u3092\
    \u6C42\u3081\u308B. \u8CA0\u306E\u91CD\u307F\u306E\u5F27\u3092\u8A31\u3059.\n\
    \    /// @details \u8A08\u7B97\u91CF\u306F O(N^3). \u8CA0\u9589\u8DEF\u304C\u3042\
    \u3063\u3066\u3082\u8A08\u7B97\u3092\u7D9A\u3051, \u6700\u77ED\u8DEF\u9577\u304C\
    \ -\u221E \u306E\u7D44\u306F unbounded \u306B\u306A\u308B.\n    /// @param D \u91CD\
    \u307F\u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\n    template<typename W>\n \
    \   Result<W> Warshall_Floyd(const digraph::Digraph<W> &D) {\n        int n =\
    \ D.order();\n\n        Result<W> result;\n        result.reachable.assign(n,\
    \ vector<bool>(n, false));\n        result.unbounded.assign(n, vector<bool>(n,\
    \ false));\n        result.dist.assign(n, vector<W>(n, W()));\n        result.parent_arc_ids.assign(n,\
    \ vector<int>(n, -1));\n\n        auto &reachable = result.reachable;\n      \
    \  auto &unbounded = result.unbounded;\n        auto &dist = result.dist;\n  \
    \      auto &parent = result.parent_arc_ids;\n\n        for (int v = 0; v < n;\
    \ ++v) { reachable[v][v] = true; }\n\n        for (int u = 0; u < n; ++u) {\n\
    \            for (int arc_id: D.successors(u)) {\n                const auto &arc\
    \ = D.get_arc(arc_id);\n                int v = arc.target;\n                unless\
    \ (!reachable[u][v] || arc.weight < dist[u][v]) { continue; }\n\n            \
    \    reachable[u][v] = true;\n                dist[u][v] = arc.weight;\n     \
    \           parent[u][v] = arc_id;\n            }\n        }\n\n        for (int\
    \ k = 0; k < n; ++k) {\n            // k \u304C\u8CA0\u9589\u8DEF\u4E0A\u306B\u3042\
    \u308B\u3068\u304D, k \u3092\u7D4C\u7531\u3059\u308B\u7D44\u306E\u8DDD\u96E2\u306F\
    \u767A\u6563\u3059\u308B\u306E\u3067\u66F4\u65B0\u3057\u306A\u3044 (\u5230\u9054\
    \u53EF\u80FD\u6027\u306E\u307F\u66F4\u65B0\u3059\u308B).\n            bool update_dist\
    \ = !(dist[k][k] < W());\n\n            for (int u = 0; u < n; ++u) {\n      \
    \          if (!reachable[u][k]) { continue; }\n\n                for (int v =\
    \ 0; v < n; ++v) {\n                    if (!reachable[k][v]) { continue; }\n\n\
    \                    if (!update_dist) {\n                        reachable[u][v]\
    \ = true;\n                        continue;\n                    }\n\n      \
    \              W d = dist[u][k] + dist[k][v];\n                    unless (!reachable[u][v]\
    \ || d < dist[u][v]) { continue; }\n\n                    reachable[u][v] = true;\n\
    \                    dist[u][v] = d;\n                    parent[u][v] = parent[k][v];\n\
    \                }\n            }\n        }\n\n        // \u8CA0\u9589\u8DEF\u4E0A\
    \u306E\u9802\u70B9 k \u3092\u7D4C\u7531\u3067\u304D\u308B\u7D44 (u, v) \u306F\
    , \u6700\u77ED\u8DEF\u9577\u304C -\u221E \u3067\u3042\u308B.\n        for (int\
    \ k = 0; k < n; ++k) {\n            if (!(dist[k][k] < W())) { continue; }\n\n\
    \            for (int u = 0; u < n; ++u) {\n                if (!reachable[u][k])\
    \ { continue; }\n\n                for (int v = 0; v < n; ++v) {\n           \
    \         if (reachable[k][v]) { unbounded[u][v] = true; }\n                }\n\
    \            }\n        }\n\n        return result;\n    }\n}\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Weighted_Digraph/Warshall_Floyd.hpp\n\
    \n#include \"../Digraph/Digraph.hpp\"\n#include \"../Digraph/Path.hpp\"\n\nnamespace\
    \ weighted_digraph::warshall_floyd {\n    template<typename W> struct Result;\n\
    \    template<typename W> Result<W> Warshall_Floyd(const digraph::Digraph<W> &D);\n\
    \n    /// @brief \u5168\u70B9\u5BFE\u6700\u77ED\u8DEF\u306E\u7D50\u679C\n    template<typename\
    \ W>\n    struct Result {\n        /// @brief parent_arc_ids[u][v]: u \u304B\u3089\
    \ v \u3078\u306E\u6700\u77ED\u8DEF\u306B\u304A\u3051\u308B v \u306B\u5165\u308B\
    \u5F27\u306E ID. u = v \u3084, \u610F\u5473\u3092\u6301\u305F\u306A\u3044\u3068\
    \u304D\u306F -1.\n        vector<vector<int>> parent_arc_ids;\n\n        /// @brief\
    \ \u8CA0\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u304B.\n        bool has_negative_cycle()\
    \ const {\n            for (int v = 0; v < int(dist.size()); ++v) {\n        \
    \        if (dist[v][v] < W()) { return true; }\n            }\n            return\
    \ false;\n        }\n\n        /// @brief u \u304B\u3089 v \u306B\u5230\u9054\u53EF\
    \u80FD\u304B.\n        bool is_reachable(int u, int v) const { return reachable[u][v];\
    \ }\n\n        /// @brief u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577\
    \u304C -\u221E \u304B.\n        bool is_unbounded(int u, int v) const { return\
    \ unbounded[u][v]; }\n\n        /// @brief u \u304B\u3089 v \u3078\u306E\u6700\
    \u77ED\u8DEF\u9577\u304C (-\u221E \u3067\u306F\u306A\u3044) \u6709\u9650\u5024\
    \u3068\u3057\u3066\u5B58\u5728\u3059\u308B\u304B.\n        bool is_finite(int\
    \ u, int v) const { return is_reachable(u, v) && !is_unbounded(u, v); }\n\n  \
    \      /// @brief u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577. is_finite(u,\
    \ v) \u306E\u3068\u304D\u306E\u307F\u610F\u5473\u3092\u6301\u3064.\n        W\
    \ distance(int u, int v) const { return dist[u][v]; }\n\n        /// @brief start\
    \ \u304B\u3089 goal \u3078\u306E\u6700\u77ED\u8DEF\u3092\u5FA9\u5143\u3059\u308B\
    .\n        /// @return \u6700\u77ED\u8DEF. goal \u306B\u5230\u9054\u3067\u304D\
    \u306A\u3044, \u307E\u305F\u306F\u6700\u77ED\u8DEF\u9577\u304C -\u221E \u306E\u3068\
    \u304D\u306F nullopt.\n        optional<digraph::Path<W>> restore(const digraph::Digraph<W>\
    \ &D, int start, int goal) const {\n            if (!is_finite(start, goal)) {\
    \ return nullopt; }\n\n            vector<digraph::Arc<W>> arcs;\n           \
    \ for (int v = goal; v != start; ) {\n                const auto &arc = D.get_arc(parent_arc_ids[start][v]);\n\
    \                arcs.emplace_back(arc);\n                v = arc.source;\n  \
    \          }\n\n            reverse(arcs.begin(), arcs.end());\n            return\
    \ digraph::Path<W>(start, arcs);\n        }\n\n        private:\n        friend\
    \ Result<W> Warshall_Floyd<W>(const digraph::Digraph<W> &D);\n\n        /// @brief\
    \ reachable[u][v]: u \u304B\u3089 v \u306B\u5230\u9054\u53EF\u80FD\u304B.\n  \
    \      vector<vector<bool>> reachable;\n\n        /// @brief unbounded[u][v]:\
    \ u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577\u304C -\u221E \u304B (u\
    \ \u304B\u3089 v \u3078\u306E\u9014\u4E2D\u3067\u8CA0\u9589\u8DEF\u3092\u7D4C\u7531\
    \u3067\u304D\u308B\u304B).\n        vector<vector<bool>> unbounded;\n\n      \
    \  /// @brief dist[u][v]: u \u304B\u3089 v \u3078\u306E\u6700\u77ED\u8DEF\u9577\
    . is_finite(u, v) \u306E\u3068\u304D\u306E\u307F\u610F\u5473\u3092\u6301\u3064\
    .\n        vector<vector<W>> dist;\n    };\n\n    /// @brief Warshall-Floyd \u6CD5\
    \u306B\u3088\u308A, \u5168\u9802\u70B9\u5BFE\u306E\u6700\u77ED\u8DEF\u3092\u6C42\
    \u3081\u308B. \u8CA0\u306E\u91CD\u307F\u306E\u5F27\u3092\u8A31\u3059.\n    ///\
    \ @details \u8A08\u7B97\u91CF\u306F O(N^3). \u8CA0\u9589\u8DEF\u304C\u3042\u3063\
    \u3066\u3082\u8A08\u7B97\u3092\u7D9A\u3051, \u6700\u77ED\u8DEF\u9577\u304C -\u221E\
    \ \u306E\u7D44\u306F unbounded \u306B\u306A\u308B.\n    /// @param D \u91CD\u307F\
    \u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\n    template<typename W>\n    Result<W>\
    \ Warshall_Floyd(const digraph::Digraph<W> &D) {\n        int n = D.order();\n\
    \n        Result<W> result;\n        result.reachable.assign(n, vector<bool>(n,\
    \ false));\n        result.unbounded.assign(n, vector<bool>(n, false));\n    \
    \    result.dist.assign(n, vector<W>(n, W()));\n        result.parent_arc_ids.assign(n,\
    \ vector<int>(n, -1));\n\n        auto &reachable = result.reachable;\n      \
    \  auto &unbounded = result.unbounded;\n        auto &dist = result.dist;\n  \
    \      auto &parent = result.parent_arc_ids;\n\n        for (int v = 0; v < n;\
    \ ++v) { reachable[v][v] = true; }\n\n        for (int u = 0; u < n; ++u) {\n\
    \            for (int arc_id: D.successors(u)) {\n                const auto &arc\
    \ = D.get_arc(arc_id);\n                int v = arc.target;\n                unless\
    \ (!reachable[u][v] || arc.weight < dist[u][v]) { continue; }\n\n            \
    \    reachable[u][v] = true;\n                dist[u][v] = arc.weight;\n     \
    \           parent[u][v] = arc_id;\n            }\n        }\n\n        for (int\
    \ k = 0; k < n; ++k) {\n            // k \u304C\u8CA0\u9589\u8DEF\u4E0A\u306B\u3042\
    \u308B\u3068\u304D, k \u3092\u7D4C\u7531\u3059\u308B\u7D44\u306E\u8DDD\u96E2\u306F\
    \u767A\u6563\u3059\u308B\u306E\u3067\u66F4\u65B0\u3057\u306A\u3044 (\u5230\u9054\
    \u53EF\u80FD\u6027\u306E\u307F\u66F4\u65B0\u3059\u308B).\n            bool update_dist\
    \ = !(dist[k][k] < W());\n\n            for (int u = 0; u < n; ++u) {\n      \
    \          if (!reachable[u][k]) { continue; }\n\n                for (int v =\
    \ 0; v < n; ++v) {\n                    if (!reachable[k][v]) { continue; }\n\n\
    \                    if (!update_dist) {\n                        reachable[u][v]\
    \ = true;\n                        continue;\n                    }\n\n      \
    \              W d = dist[u][k] + dist[k][v];\n                    unless (!reachable[u][v]\
    \ || d < dist[u][v]) { continue; }\n\n                    reachable[u][v] = true;\n\
    \                    dist[u][v] = d;\n                    parent[u][v] = parent[k][v];\n\
    \                }\n            }\n        }\n\n        // \u8CA0\u9589\u8DEF\u4E0A\
    \u306E\u9802\u70B9 k \u3092\u7D4C\u7531\u3067\u304D\u308B\u7D44 (u, v) \u306F\
    , \u6700\u77ED\u8DEF\u9577\u304C -\u221E \u3067\u3042\u308B.\n        for (int\
    \ k = 0; k < n; ++k) {\n            if (!(dist[k][k] < W())) { continue; }\n\n\
    \            for (int u = 0; u < n; ++u) {\n                if (!reachable[u][k])\
    \ { continue; }\n\n                for (int v = 0; v < n; ++v) {\n           \
    \         if (reachable[k][v]) { unbounded[u][v] = true; }\n                }\n\
    \            }\n        }\n\n        return result;\n    }\n}\n"
  dependsOn:
  - Graph/Digraph/Digraph.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Graph/Common.hpp
  - Graph/Digraph/Path.hpp
  isVerificationFile: false
  path: Graph/Weighted_Digraph/Warshall_Floyd.hpp
  requiredBy: []
  timestamp: '2026-10-17 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/grl/1C.test.cpp
documentation_of: Graph/Weighted_Digraph/Warshall_Floyd.hpp
layout: document
title: "Warshall-Floyd \u6CD5"
---

## Outline

重み付き有向グラフ $D = (V, A, W)$ の全ての頂点対 $(u, v)$ に対して, $u$ から $v$ への最短路長を Warshall-Floyd 法で求める. 弧の重みが負であってもよく, 負閉路があっても計算を続ける.

## Definition

重み付き有向グラフ $D = (V, A, W)$ の頂点 $u, v$ に対して, 以下のように定める.

* $u$ から $v$ に**到達可能**であるとは, $u$ から $v$ への歩道が存在することである.
* 長さが負である閉路を**負閉路**という.
* $u$ から $v$ への最短路長が $-\infty$ であるとは, $u$ から $v$ への歩道で, 長さがいくらでも小さくなるものが存在することである. これは, $u$ から $v$ への歩道が負閉路を経由できることと同値である.
* $u$ から $v$ への最短路長が**有限**であるとは, $u$ から $v$ に到達可能であり, かつ最短路長が $-\infty$ ではないことである.

## Theory

重み付き有向グラフ $D = (V, A, W)$ について, $V = \{v\_1, \dots, v\_N\}$ とする. 歩道 $p$ の長さ $\operatorname{weight}(p)$ は, $p$ に含まれる弧の重みの総和である. また, 歩道 $q$ の終点と歩道 $r$ の始点が等しいとき, それらを連結した歩道を $q \oplus r$ とする.

まず, $D$ に負閉路がない場合を考える. このとき, 歩道の長さは, その歩道から閉路を取り除いて得られるパスの長さ以上になる. よって, 歩道が存在するならば, 長さが最小の歩道が存在する.

$k = 0, 1, 2, \dots, N$ と $s, t \in V$ に対して, $P^{(k)}\_{s, t}$ と $d^{(k)}\_{s, t}$ を以下で定義する.

* $P^{(k)}\_{s, t}$ を, 頂点 $s$ から頂点 $t$ への有向歩道のうち, 始点と終点を除く途中で通る頂点が全て $\{v\_1, \dots, v\_k\}$ に含まれるもの全体の集合とする. $s, t$ 自身は $\{v\_1, \dots, v\_k\}$ に含まれなくてもよい.
* $d^{(k)}\_{s, t}$ を, $P^{(k)}\_{s, t}$ に含まれる歩道の長さの最小値とする. つまり, $\displaystyle d^{(k)}\_{s, t} = \min\_{p \in P^{(k)}\_{s, t}} \operatorname{weight}(p)$. ただし, $P^{(k)}\_{s, t} = \emptyset$ のときは $d^{(k)}\_{s, t} = +\infty$ とする.

最終的に求めるべきは各 $s, t$ に関する $d^{(N)}\_{s, t}$ である.

このとき, $d^{(k)}\_{s, t}$ について次のように求める.

### * $k = 0$ のとき

$P^{(0)}\_{s, t}$ とは, 途中で頂点を通らない $s$ から $t$ への有向歩道, つまり長さが $0$ または $1$ の歩道全体の集合である.

* $s = t$ のとき, $P^{(0)}\_{s, t}$ は頂点 $s$ のみからなる長さ $0$ の歩道と, $s$ の自己ループ $1$ 本からなる歩道全体の集合である. 負閉路がないので, 自己ループの重みは $0$ 以上であり, $d^{(0)}\_{s, s} = 0$ である.
* $s \neq t$ のとき, $P^{(0)}\_{s, t}$ は $s$ から $t$ への弧 $1$ 本からなる歩道全体の集合である. 弧が存在しなければ $P^{(0)}\_{s, t} = \emptyset$ である.

よって,

$$ d^{(0)}_{s, t} = \begin{cases} 0 & (s = t) \\ \displaystyle \min_{a: s \to t} W(a) & (s \neq t, \ s \text{ から } t \text{ への弧が存在する}) \\ +\infty & (s \neq t, \ s \text{ から } t \text{ への弧が存在しない}) \end{cases} $$

である.

### * $k \geq 1$ のとき

$$ d^{(k)}_{s, t} = \min \left(d^{(k-1)}_{s, t}, \ d^{(k-1)}_{s, v_k} + d^{(k-1)}_{v_k, t} \right) $$

が成り立つ. これは以下の理由による.

* $d^{(k)}\_{s, t} \leq$ 右辺: $P^{(k-1)}\_{s, t} \subset P^{(k)}\_{s, t}$ なので, $d^{(k)}\_{s, t} \leq d^{(k-1)}\_{s, t}$ である. また, $q \in P^{(k-1)}\_{s, v\_k}$, $r \in P^{(k-1)}\_{v\_k, t}$ に対して, $q \oplus r$ は途中の頂点が $\{v\_1, \dots, v\_k\}$ に含まれるので, $q \oplus r \in P^{(k)}\_{s, t}$ である. $q, r$ をそれぞれ長さが最小のものにとれば, $\operatorname{weight}(q \oplus r) = d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ なので, $d^{(k)}\_{s, t} \leq d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ である.
* $d^{(k)}\_{s, t} \geq$ 右辺: $p \in P^{(k)}\_{s, t}$ を長さが最小の歩道とする.
  * $p$ が途中で $v\_k$ を通らないとき, $p \in P^{(k-1)}\_{s, t}$ なので, $\operatorname{weight}(p) \geq d^{(k-1)}\_{s, t}$ である.
  * $p$ が途中で $v\_k$ を通るとき, 途中で最初に $v\_k$ を通る点と最後に $v\_k$ を通る点で, $p = q \oplus c \oplus r$ と分ける. ここで, $c$ は $v\_k$ から $v\_k$ への閉歩道である. $q \in P^{(k-1)}\_{s, v\_k}$, $r \in P^{(k-1)}\_{v\_k, t}$ であり, 負閉路がないので $\operatorname{weight}(c) \geq 0$ である. よって, $\operatorname{weight}(p) \geq \operatorname{weight}(q) + \operatorname{weight}(r) \geq d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ である.

計算量について, 各 $d^{(k)}\_{s, t}$ についての更新式は $O(1)$ 時間で計算でき, $0 \leq k \leq N, s, t \in V$ の全てを走るので, $O(N^3)$ 時間である.

また, $d^{(k-1)}\_{v\_k, v\_k} = 0$ なので, $d^{(k)}\_{s, v\_k} = d^{(k-1)}\_{s, v\_k}$, $d^{(k)}\_{v\_k, t} = d^{(k-1)}\_{v\_k, t}$ となり, $v\_k$ に関する行と列は更新で変化しない. そのため, $d^{(k)}$ を $d^{(k-1)}$ に上書きして計算できて, 空間計算量は $O(N^2)$ である.

### 負閉路がある場合

負閉路があるときは, 上の議論はそのままでは成り立たない. 負閉路上の頂点 $v$ は, 計算の過程で $d\_{v, v} < 0$ となる. 本実装では, 以下のようにして扱う.

* $d\_{v\_k, v\_k} < 0$ である $v\_k$ を経由する更新では, 値の発散を防ぐために, 到達可能性のみを更新して距離は更新しない.
* 最後に, $d\_{v, v} < 0$ である頂点 $v$ について, $u$ から $v$ に到達可能かつ $v$ から $w$ に到達可能な $(u, w)$ の最短路長を $-\infty$ とする.

最短路長が有限である $(u, w)$ については, $u$ から $w$ への歩道上に負閉路上の頂点が存在しない. そのため, 負閉路がない場合と同じ議論が成り立ち, 距離と経路は正しく求まる.

## Contents

### Warshall_Floyd

```cpp
template<typename W>
Result<W> Warshall_Floyd(const digraph::Digraph<W> &D)
```

* 重み付き有向グラフ $D$ の全頂点対の最短路を求める. 名前空間は `weighted_digraph::warshall_floyd` である.
* **引数**
  * $D$ : 重み付き有向グラフ ([`digraph::Digraph<W>`](../Digraph/Digraph.html)). 多重弧や自己ループがあってもよい.
* **制約** : 重みの和が `W` の範囲に収まる.
* **計算量** : $D$ の位数を $N$ とすると, $O(N^3)$ 時間, $O(N^2)$ 空間.

### Result

`Warshall_Floyd` の結果を表す構造体である. 到達可能性, 最短路長が $-\infty$ か, 最短路長は, 以下のメンバ関数から取得する.

|メンバ|内容|
|:---|:---|
|`vector<vector<int>> parent_arc_ids`|`parent_arc_ids[u][v]`: $u$ から $v$ への最短路における $v$ に入る弧の ID. $u = v$ や, 意味を持たないときは $-1$|

### has_negative_cycle

```cpp
bool has_negative_cycle() const
```

* $D$ に負閉路が存在するか.
* **計算量** : $O(N)$ 時間.

### is_reachable

```cpp
bool is_reachable(int u, int v) const
```

* $u$ から $v$ に到達可能か.
* **計算量** : $O(1)$ 時間.

### is_unbounded

```cpp
bool is_unbounded(int u, int v) const
```

* $u$ から $v$ への最短路長が $-\infty$ か.
* **計算量** : $O(1)$ 時間.

### is_finite

```cpp
bool is_finite(int u, int v) const
```

* $u$ から $v$ への最短路長が, $-\infty$ ではない有限値として存在するか.
* **計算量** : $O(1)$ 時間.

### distance

```cpp
W distance(int u, int v) const
```

* $u$ から $v$ への最短路長を返す.
* **制約** : `is_finite(u, v)` が `true` である.
* **計算量** : $O(1)$ 時間.

### restore

```cpp
optional<digraph::Path<W>> restore(const digraph::Digraph<W> &D, int start, int goal) const
```

* $\mathrm{start}$ から $\mathrm{goal}$ への最短路を復元する.
* **引数**
  * $D$ : `Warshall_Floyd` に渡したものと同じグラフ.
  * $\mathrm{start}, \mathrm{goal}$ : 始点, 終点.
* **戻り値** : 最短路. $\mathrm{goal}$ に到達できない, または最短路長が $-\infty$ のときは `nullopt`.
* **計算量** : 経路の長さを $L$ とすると, $O(L)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/08| Warshall-Floyd 法の実装 |
