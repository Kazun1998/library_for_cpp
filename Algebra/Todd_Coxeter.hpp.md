---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/original/Todd_Coxeter.test.cpp
    title: verify/original/Todd_Coxeter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u8A9E. \u6587\u5B57 (0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u6574\
      \u6570) \u306E\u5217. \u7A7A\u5217\u306F\u5358\u4F4D\u5143\u3092\u8868\u3059\
      ."
    links: []
  bundledCode: "#line 2 \"Algebra/Todd_Coxeter.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/template.hpp\n\
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
    \    }\n};\n#line 2 \"Union_Find/Union_Find.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Union_Find/Union_Find.hpp\n\
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
    \ const { return _group_number; }\n};\n#line 5 \"Algebra/Todd_Coxeter.hpp\"\n\n\
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
    \     return alpha;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../Union_Find/Union_Find.hpp\"\
    \n\nstruct Todd_Coxeter {\n    public:\n    /// @brief \u8A9E. \u6587\u5B57 (0\
    \ \u4EE5\u4E0A K \u672A\u6E80\u306E\u6574\u6570) \u306E\u5217. \u7A7A\u5217\u306F\
    \u5358\u4F4D\u5143\u3092\u8868\u3059.\n    using Word = vector<int>;\n\n    ///\
    \ @brief \u95A2\u4FC2\u5F0F (lhs, rhs). lhs = rhs \u3092\u8868\u3059.\n    using\
    \ Relation = pair<Word, Word>;\n\n    private:\n    int K;\n    vector<vector<int>>\
    \ T;\n\n    // \u4EE5\u4E0B\u306F\u69CB\u6210\u4E2D\u306E\u307F\u4F7F\u3046.\n\
    \    Union_Find UF;\n    vector<bool> done; // done[alpha]: alpha \u304B\u3089\
    \u5168\u95A2\u4FC2\u5F0F\u3092\u8ABF\u3079, \u5168\u6587\u5B57\u306E\u884C\u304D\
    \u5148\u3092\u5B9A\u7FA9\u6E08\u307F\u304B?\n\n    /// @brief \u5143\u3092 1 \u3064\
    \u8FFD\u52A0\u3059\u308B.\n    /// @return \u8FFD\u52A0\u3057\u305F\u5143\u306E\
    \u756A\u53F7.\n    int add_vertex() {\n        int alpha = T.size();\n       \
    \ T.emplace_back(K, -1);\n        UF.add_vertex();\n        done.emplace_back(false);\n\
    \n        return alpha;\n    }\n\n    /// @brief \u5143 alpha \u306B\u6587\u5B57\
    \ x \u3092\u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u3092\u6C42\u3081\u308B.\
    \ \u672A\u5B9A\u7FA9\u306A\u3089\u3070\u65B0\u3057\u3044\u5143\u3092\u4F5C\u308B\
    .\n    /// @return \u884C\u304D\u5148\u306E\u4EE3\u8868\u5143.\n    int step(int\
    \ alpha, int x) {\n        alpha = UF.find(alpha);\n        if (T[alpha][x] ==\
    \ -1) {\n            int beta = add_vertex();\n            T[alpha][x] = beta;\n\
    \        }\n\n        return UF.find(T[alpha][x]);\n    }\n\n    /// @brief \u5143\
    \ alpha \u306B\u8A9E w \u3092\u53F3\u304B\u3089\u639B\u3051\u305F\u5143\u3092\u6C42\
    \u3081\u308B. \u9014\u4E2D\u304C\u672A\u5B9A\u7FA9\u306A\u3089\u3070\u65B0\u3057\
    \u3044\u5143\u3092\u4F5C\u308B.\n    /// @return \u884C\u304D\u5148\u306E\u4EE3\
    \u8868\u5143.\n    int walk(int alpha, const Word &w) {\n        for (int x: w)\
    \ {\n            alpha = step(alpha, x);\n        }\n\n        return UF.find(alpha);\n\
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
    \     return alpha;\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Union_Find/Union_Find.hpp
  isVerificationFile: false
  path: Algebra/Todd_Coxeter.hpp
  requiredBy: []
  timestamp: '2026-10-31 18:45:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Todd_Coxeter.test.cpp
documentation_of: Algebra/Todd_Coxeter.hpp
layout: document
title: "Todd\u2013Coxeter \u6CD5"
---

## Outline

生成元と関係式によるモノイドの表示 $M = \langle x_0, \dots, x_{K-1} \mid l_0 = r_0, \dots, l_{m-1} = r_{m-1} \rangle$ に対して, $M$ の位数と, 各元への生成元の右からの作用 (右 Cayley グラフ) を求める.

戦略は HLT (Hazelgrove–Leech–Trotter) で, 同一視された元の併合は Union Find で行う.

$M$ が無限のとき, Todd–Coxeter 法は終了しない (命題 12). 有限であるかどうかは一般には判定できない (決定不能) ので, 呼び出し側が $M$ が有限であることを保証する必要がある.

## Define

列/文字列に関する記法 (空列 $\emptyset$, 結合 $\oplus$, 長さ $\lvert \alpha \rvert$ など) は, [列/文字列](/String.html) に従う.

$X$ をアルファベットとする. $X^\ast$ は文字列の結合 $\oplus$ に関してモノイドになる ([列/文字列](/String.html) の命題 4).

### 商モノイド

<div class="definition" markdown="1">

定義 1
---

$X^\ast$ 上の同値関係 $\sim$ について, 以下を満たすとき, $\sim$ は合同関係であるという.

* 任意の $u, v \in X^\ast$ に対して, $u \sim v$ ならば, 任意の $a, b \in X^\ast$ に対して, $a \oplus u \oplus b \sim a \oplus v \oplus b$.

</div>

<div class="proposition" markdown="1">

命題 2
---

$X^\ast$ 上の関係 $R \subset X^\ast \times X^\ast$ について, $R$ を含む合同関係のうち, 最小のものが唯一存在する.

</div>

<div class="proof" markdown="1">

証明
---

$R$ を含む合同関係全体を $\mathcal{C}$ とする. $X^\ast \times X^\ast$ は $R$ を含む合同関係なので, $\mathcal{C}$ は空ではない. $\mathcal{C}$ に属する全ての関係の共通部分を $\sim_0$ とする.

* $\sim_0$ は同値関係である. 反射律, 対称律, 推移律は, $\mathcal{C}$ の各元が満たすので, 共通部分も満たす.
* $\sim_0$ は合同関係である. $u \sim_0 v$ ならば, $\mathcal{C}$ の各元について $u \sim v$ なので, 任意の $a, b$ について $a \oplus u \oplus b \sim a \oplus v \oplus b$ である. よって $a \oplus u \oplus b \sim_0 a \oplus v \oplus b$.
* $\sim_0$ は $R$ を含む.

したがって $\sim_0 \in \mathcal{C}$ であり, $\sim_0$ は $\mathcal{C}$ の全ての元に含まれるので最小である. 最小のものは明らかに唯一である.

</div>

<div class="definition" markdown="1">

定義 3
---

$X^\ast$ 上の関係 $R$ について, $R$ を含む合同関係のうち最小であるものを $\sim_R$ と書く. また, $\sim_R$ における $u \in X^\ast$ の同値類を $[u]$ と書く.

</div>

以下, $R \subset X^\ast \times X^\ast$ を与えられた関係式の集合とし, その元 $(l, r)$ を関係式 $l = r$ と呼ぶ.

<div class="definition" markdown="1">

定義 4
---

$M := X^\ast / {\sim_R}$ とする.

</div>

<div class="proposition" markdown="1">

命題 5
---

$[u] \oplus [v] := [u \oplus v]$ は代表元 $u, v$ の取り方によらず定まり, $M$ はこれを演算として, $e := [\emptyset]$ を単位元とするモノイドになる.

</div>

<div class="proof" markdown="1">

証明
---

$u \sim_R u'$ かつ $v \sim_R v'$ とする. $\sim_R$ は合同関係なので, $u \oplus v \sim_R u' \oplus v$ かつ $u' \oplus v \sim_R u' \oplus v'$ である. 推移律より $u \oplus v \sim_R u' \oplus v'$ なので, 演算は代表元によらず定まる. 結合律と $e$ が単位元であることは, $X^\ast$ がモノイドであることから従う.

</div>

<div class="definition" markdown="1">

定義 6
---

$x \in X$ と $[u] \in M$ に対して, $[u] \cdot x := [u \oplus (x)]$ と定める. 命題 5 より, これは代表元 $u$ の取り方によらず定まる. これを文字 $x$ の右作用という.

また, $w = (x_1, \dots, x_n) \in X^\ast$ に対して, $[u] \cdot w := [u] \cdot x_1 \cdot \dots \cdot x_n$ と定める. ただし, $[u] \cdot \emptyset := [u]$ とする.

</div>

<div class="proposition" markdown="1">

命題 7
---

$u, w \in X^\ast$ に対して, $[u] \cdot w = [u \oplus w]$ である. 特に $[w] = e \cdot w$ である.

</div>

<div class="proof" markdown="1">

証明
---

$w$ の長さに関する帰納法で示す. $w = \emptyset$ のときは定義から明らか. $w = w' \oplus (x)$ のとき, 帰納法の仮定から $[u] \cdot w = ([u] \cdot w') \cdot x = [u \oplus w'] \cdot x = [u \oplus w' \oplus (x)] = [u \oplus w]$ である.

</div>

命題 7 より, 単位元 $e$ から右作用だけで $M$ の全ての元に到達できる. したがって, 頂点を $M$ の元, 辺を $[u] \xrightarrow{x} [u] \cdot x$ としたグラフ (右 Cayley グラフ) が分かれば, $M$ の位数と, 文字列が表す元が分かる.

<div class="proposition" markdown="1">

命題 8
---

$u, v \in X^\ast$ に対して, 以下は同値である.

* (a) $u \sim_R v$.
* (b) $X^\ast$ の列 $u = w_0, w_1, \dots, w_k = v$ ($k \geq 0$) であって, 各 $i$ について, ある $a, b \in X^\ast$ と $(p, q) \in R$ が存在して, $\lbrace w_{i-1}, w_i \rbrace = \lbrace a \oplus p \oplus b, a \oplus q \oplus b \rbrace$ となるものが存在する.

</div>

<div class="proof" markdown="1">

証明
---

(b) を満たすとき $u \approx v$ と書く.

**(b) ⇒ (a)**: $\sim_R$ は $R$ を含む合同関係なので, $(p, q) \in R$ ならば $a \oplus p \oplus b \sim_R a \oplus q \oplus b$ である. よって $w_{i-1} \sim_R w_i$ であり, 推移律より $u \sim_R v$ である.

**(a) ⇒ (b)**: $\approx$ が $R$ を含む合同関係であることを示せば, $\sim_R$ の最小性より $\sim_R \subset \approx$ である. $k = 0$ をとれば反射律が, 列を逆順にすれば対称律が, 列を連結すれば推移律が成り立つので, $\approx$ は同値関係である. $(p, q) \in R$ は $a = b = \emptyset$, $k = 1$ の場合なので, $\approx$ は $R$ を含む. $u \approx v$ ならば, 列の各項の前後に $a', b'$ を結合すれば $a' \oplus u \oplus b' \approx a' \oplus v \oplus b'$ の列が得られるので, $\approx$ は合同関係である.

</div>

### Todd–Coxeter 法

<div class="definition" markdown="1">

定義 9
---

次のものの組を状態という.

* 頂点の集合 $V$ と, 頂点 $0 \in V$.
* 部分的に定義された辺. 頂点 $\alpha$ と文字 $x$ に対して, $\alpha$ から $x$ の辺が定義されているとき, その行き先を $\alpha \cdot x$ と書く.
* $V$ 上の同値関係 $\equiv$.
* 写像 $\varphi : V \to M$.

頂点 $\alpha$ と $w = (x_1, \dots, x_n) \in X^\ast$ について, $\alpha \cdot x_1 \cdot \dots \cdot x_n$ が全て定義されているとき, その行き先を $\alpha \cdot w$ と書く. 特に $\alpha \cdot \emptyset = \alpha$ である.

状態が次の (a) から (d) を満たすとき, 整合的であるという.

* (a) $\varphi(0) = e$.
* (b) $\alpha \cdot x$ が定義されているならば, $\varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x$.
* (c) $\alpha \equiv \beta$ ならば, $\varphi(\alpha) = \varphi(\beta)$.
* (d) 全ての頂点 $\alpha$ について, $\alpha = 0 \cdot w$ となる $w \in X^\ast$ が存在する.

</div>

(b) から, 帰納法により $\alpha \cdot w$ が定義されていれば $\varphi(\alpha \cdot w) = \varphi(\alpha) \cdot w$ である.

Todd–Coxeter 法は, $V = \lbrace 0 \rbrace$, 辺はなし, $\equiv$ は等号, $\varphi(0) = e$ という整合的な状態から始めて, 次の操作を繰り返す.

<div class="proposition" markdown="1">

命題 10
---

整合的な状態に, 以下の操作をしても, 整合的である.

* (1) **定義** (`step`): $\alpha \cdot x$ が未定義のとき, 新しい頂点 $\beta$ を $V$ に加え, $\alpha \cdot x := \beta$ とする. $\equiv$ では $\beta$ は自分自身とのみ同値とし, $\varphi(\beta) := \varphi(\alpha) \cdot x$ とする.
* (2) **関係式の走査** (`walk`, `merge`): $(l, r) \in R$ と頂点 $\alpha$ について, $\alpha \cdot l$ と $\alpha \cdot r$ が定義されているとき, $\alpha \cdot l \equiv \alpha \cdot r$ を加える (すなわち, この対を含む最小の同値関係に $\equiv$ を取り替える).
* (3) **併合の連鎖** (`merge`): $\alpha \equiv \beta$ であり, $\alpha \cdot x$ が定義されているとき, $\beta \cdot x$ が未定義ならば $\beta \cdot x := \alpha \cdot x$ とし, 定義されているならば $\alpha \cdot x \equiv \beta \cdot x$ を加える.

</div>

<div class="proof" markdown="1">

証明
---

**(1)**: (a) と (c) は明らか. (b) は, $\varphi(\alpha \cdot x) = \varphi(\beta) = \varphi(\alpha) \cdot x$ で成り立つ. (d) は, $\alpha = 0 \cdot w$ ならば $\beta = 0 \cdot (w \oplus (x))$ なので成り立つ.

**(2)**: 辺と $\varphi$ は変わらないので, (a), (b), (d) は保たれる. (c) を示す. $\varphi(\alpha) = [u]$ とすると, $\varphi(\alpha \cdot l) = [u] \cdot l = [u \oplus l]$, $\varphi(\alpha \cdot r) = [u \oplus r]$ である. $(l, r) \in R$ より $l \sim_R r$ なので, $\sim_R$ が合同関係であることから $u \oplus l \sim_R u \oplus r$ であり, $\varphi(\alpha \cdot l) = \varphi(\alpha \cdot r)$ が成り立つ. 一方, $\varphi(\alpha) = \varphi(\beta)$ をみたす $(\alpha, \beta)$ の全体は, 同値関係であり, 元の $\equiv$ と $(\alpha \cdot l, \alpha \cdot r)$ を含む. よって, これらを含む最小の同値関係もこれに含まれ, (c) が成り立つ.

**(3)**: $\beta \cdot x := \alpha \cdot x$ とするときは, (c) より $\varphi(\alpha) = \varphi(\beta)$ なので, $\varphi(\beta \cdot x) = \varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x = \varphi(\beta) \cdot x$ で (b) が成り立つ. 辺を加えても (a), (d) は保たれる. 同値関係を加えるときは, $\varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x = \varphi(\beta) \cdot x = \varphi(\beta \cdot x)$ なので, (2) と同様に (c) が成り立つ.

</div>

<div class="proposition" markdown="1">

命題 11
---

整合的な状態が, 以下の (i), (ii), (iii) を満たすとする.

* (i) 全ての頂点 $\alpha$ と全ての文字 $x$ について, $\alpha \cdot x$ が定義されている.
* (ii) $\alpha \equiv \beta$ ならば, 全ての文字 $x$ について $\alpha \cdot x \equiv \beta \cdot x$ である.
* (iii) 全ての頂点 $\alpha$ と全ての $(l, r) \in R$ について, $\alpha \cdot l \equiv \alpha \cdot r$ である.

以下, 頂点 $\alpha$ の $\equiv$ に関する同値類を $\overline{\alpha}$ と書く. このとき, $V / {\equiv}$ に $\overline{\alpha} \cdot x := \overline{\alpha \cdot x}$ で辺を定めたグラフは, $M$ の右 Cayley グラフと同型である. 特に $M$ と $V / {\equiv}$ の間には全単射が存在し, どちらかが有限ならば $\lvert M \rvert = \lvert V / {\equiv} \rvert$ である.

</div>

<div class="proof" markdown="1">

証明
---

(i) より, 全ての頂点 $\alpha$ と $w \in X^\ast$ について $\alpha \cdot w$ が定義される. (ii) より, $\overline{\alpha} \cdot x$ は代表元の取り方によらず定まる. これを繰り返せば, $\overline{\alpha} \cdot w = \overline{\alpha \cdot w}$ である.

**(1) $\psi : M \to V / {\equiv}$, $\psi([w]) := \overline{0 \cdot w}$ が定まる.**

$u \sim_R v$ とする. 命題 8 より, 置き換え $1$ 回の場合, すなわち $u = a \oplus p \oplus b$, $v = a \oplus q \oplus b$ ($(p, q) \in R$ またはその逆) について $\overline{0 \cdot u} = \overline{0 \cdot v}$ を示せばよい. $\gamma := 0 \cdot a$ とすると, (iii) より $\gamma \cdot p \equiv \gamma \cdot q$ である. (ii) を $b$ の文字について繰り返すと, $\gamma \cdot p \cdot b \equiv \gamma \cdot q \cdot b$ である. これは $0 \cdot u \equiv 0 \cdot v$ に他ならない.

**(2) $\psi$ は全射である.**

(d) より, 全ての頂点は $0 \cdot w$ の形で表される.

**(3) $\psi$ は単射である.**

(c) より $\varphi$ は $V / {\equiv}$ から $M$ への写像 $\bar{\varphi}$ を誘導する. (a), (b) から $\varphi(0 \cdot w) = e \cdot w = [w]$ なので, $\bar{\varphi}(\psi([w])) = [w]$, すなわち $\bar{\varphi} \circ \psi = \mathrm{id}_M$ である. よって $\psi$ は単射である.

**(4) 辺が保たれる.**

$\psi([w] \cdot x) = \psi([w \oplus (x)]) = \overline{0 \cdot w \cdot x} = \overline{0 \cdot w} \cdot x = \psi([w]) \cdot x$.

以上から $\psi$ は全単射で, 辺を保つ.

</div>

Todd–Coxeter 法は, 状態が (i), (ii), (iii) を満たしたところで終了し, 頂点の同値類に $0, 1, \dots$ と番号を振り直す (`compress`). このとき, 単位元 $e$ に対応する頂点の同値類の番号は $0$ になる. 実装では各同値類の代表元だけが辺を持つが, 併合のときに (命題 10 の (3) により) 辺を引き継ぐので, (i), (ii), (iii) は同値類ごとに見ても同じである.

<div class="proposition" markdown="1">

命題 12
---

$M$ が無限ならば, Todd–Coxeter 法は終了しない.

</div>

<div class="proof" markdown="1">

証明
---

終了したとき, $V$ は有限である. 命題 10 より状態は整合的であり, 終了条件より (i), (ii), (iii) を満たすので, 命題 11 より $M$ も有限である. 対偶をとれば, $M$ が無限ならば終了しない.

</div>

有限表示のモノイド $M$ が有限かどうかを判定するアルゴリズムは存在しない (決定不能である). 終了しない入力を事前に検出することはできず, Todd–Coxeter 法も, 終了しないことを検出する仕組みは持たない.


また, 終了する場合でも, 途中で作る頂点の個数は $\lvert M \rvert$ を大きく超えることがある. HLT は, 先に全ての頂点で全ての辺を埋めるので, 併合される頂点が多く出る.

実装との対応は以下の通りである.

|概念|実装|
|:---:|:---:|
|頂点, 辺|`T[alpha][x]` (未定義は $-1$)|
|同値関係 $\equiv$|`UF` (union-find)|
|全ての関係式を調べ終えた頂点|`done[alpha]`|
|併合の連鎖|`merge` (スタック)|
|番号の振り直し|`compress`|

調べ終えた性質は, 頂点を併合しても保たれる. そのため, 併合後の頂点の `done` は `done[alpha] || done[beta]` とする.

### 具体例

以下では, 文字 $x_0, x_1$ をそれぞれ生成元 $a, b$ とみなす. 元の番号は構成の過程で決まるので, 単位元の番号が $0$ であること以外は, 番号そのものではなく `eval` の一致・不一致で例を述べる.

#### 巡回群

位数 $3$ の巡回群 $\langle a \mid a^3 = e \rangle$ に対応する例である.

{% raw %}
```cpp
Todd_Coxeter M(1, {{{0, 0, 0}, {}}});

M.order();                          // 3
M.eval({0, 0, 0}) == M.eval({});    // true (a^3 = e)
M.eval({0, 0}) == M.eval({0});      // false
```
{% endraw %}

#### 群にならないモノイド

$\langle a \mid a^3 = a \rangle$ に対応する例である. $a^3 = a$ だが $a^2 \neq a$ より, $a$ に逆元が存在しない.

{% raw %}
```cpp
Todd_Coxeter M(1, {{{0, 0, 0}, {0}}});

M.order();                          // 3 (e, a, a^2)
M.eval({0, 0, 0}) == M.eval({0});   // true
M.eval({0, 0}) == M.eval({0});      // false
M.eval({0}) == M.eval({});          // false
```
{% endraw %}

#### 冪等な元が生成する可換モノイド

$\langle a, b \mid a^2 = a, b^2 = b, ab = ba \rangle$ に対応する例である. 元は $e, a, b, ab$ の $4$ 個である.

{% raw %}
```cpp
Todd_Coxeter M(2, {{{0, 0}, {0}}, {{1, 1}, {1}}, {{0, 1}, {1, 0}}});

M.order();                              // 4
M.eval({0, 1}) == M.eval({1, 0});       // true
M.eval({0, 1, 0}) == M.eval({0, 1});    // true
```
{% endraw %}

#### 3 次対称群

$3$ 次対称群 $\mathfrak{S}_3 = \langle a, b \mid a^2 = b^2 = (ab)^3 = e \rangle$ に対応する例である.

{% raw %}
```cpp
Todd_Coxeter M(2, {{{0, 0}, {}}, {{1, 1}, {}}, {{0, 1, 0, 1, 0, 1}, {}}});

M.order();                              // 6
M.eval({0, 1, 0}) == M.eval({1, 0, 1}); // true  (aba = bab)
M.eval({0, 1}) == M.eval({1, 0});       // false (ab ≠ ba)
```
{% endraw %}

#### 終了しない例

次のように $M$ が無限になる表示は, 命題 12 より終了しない.

* $\langle a \rangle$ ($\mathbb{N}$ と同型).
* $\langle a, b \mid ab = ba \rangle$ ($\mathbb{N}^2$ と同型).

## Contents

### Types

```cpp
using Word = vector<int>
using Relation = pair<Word, Word>
```

* それぞれ文字列, 関係式を表す型.

### Constructor

```cpp
Todd_Coxeter(int K, const vector<Relation> &R)
```

* $K$ 個の文字 $x_0, x_1, \dots, x_{K-1}$ からなる自由モノイドを, 関係式 $R$ で割った商モノイド $M$ を構成する.
* **制約**
  * $M$ は有限でなければならない. 無限の場合は, 命題 12 より終了しない. また, $M$ が有限かどうかは決定不能なので, 終了しない入力を事前に検出することはできない.
* **計算量**
  * 構成の途中で定義する元の個数に依存し, 理論的に押さえつけることは難しい. 特に, 途中の個数は, $M$ の位数と比較しても大きくなることがある.

### order

```cpp
int order() const
```

* $M$ の位数 $\lvert M \rvert$ を返す.

### act

```cpp
int act(int alpha, int x) const
```

* 元 $\alpha$ に文字 $x$ を右から掛けた元 $\alpha \cdot x$ の番号を返す.
* **計算量**
  * $O(1)$

### eval

```cpp
int eval(const Word &w) const
```

* 文字列 $w$ が表す元の番号を返す. すなわち, 単位元に $w$ の文字を左から順に作用させた元である.
* **計算量**
  * $O(\lvert w \rvert)$

### table

```cpp
const vector<vector<int>> &table() const
```

* 作用表を返す. `table()[alpha][x]` は $\alpha \cdot x$ の番号に等しい.

## History

|日付|内容|
|:---:|:---:|
|2026/10/31|Todd–Coxeter 法の実装|
