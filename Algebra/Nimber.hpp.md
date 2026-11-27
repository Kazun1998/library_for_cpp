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
    path: verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
    title: verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "x * y \u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u30D8\u30EB\u30D1\
      \u30FC\u95A2\u6570"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Algebra/Nimber.hpp
  bundledCode: "#line 2 \"Algebra/Nimber.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Algebra/Nimber.hpp\n\
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
    \    }\n};\n#line 6 \"Algebra/Nimber.hpp\"\n\nclass Nimber {\n    public:\n  \
    \  Nimber(): x(0) {}\n    Nimber(uint64_t x): x(x) {}\n\n    Nimber operator-()\
    \ const { return Nimber(x); }\n\n    Nimber& operator+=(const Nimber &b) {\n \
    \       x ^= b.x;\n        return *this;\n    }\n\n    friend Nimber operator+(const\
    \ Nimber &x, const Nimber &y) { return Nimber(x) += y; }\n\n    Nimber& operator-=(const\
    \ Nimber &b) {\n        *this += b;\n        return *this;\n    }\n\n    friend\
    \ Nimber operator-(const Nimber &x, const Nimber &y) { return Nimber(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    Nimber& operator*=(const Nimber &b) {\n      \
    \  if ((x | b.x) < 256) {\n            if (!table_initialized) init_table();\n\
    \            x = small_table[x][b.x];\n            return *this;\n        }\n\
    \        int level = max(calculate_level(x), calculate_level(b.x));\n        x\
    \ = calculate_mul(x, b.x, level);\n        return *this;\n    }\n\n    friend\
    \ Nimber operator*(const Nimber &x, const Nimber &y) { return Nimber(x) *= y;\
    \ }\n\n    friend bool operator==(const Nimber &a, const Nimber &b) { return a.x\
    \ == b.x; }\n    friend bool operator!=(const Nimber &a, const Nimber &b) { return\
    \ a.x != b.x; }\n    friend bool operator<(const Nimber &a, const Nimber &b) {\
    \ return a.x < b.x; }\n\n    Nimber square() const {\n        if (x < 256) {\n\
    \            if (!table_initialized) init_table();\n            return small_table[x][x];\n\
    \        }\n        int level = calculate_level(x);\n        return Nimber(calculate_square(x,\
    \ level));\n    }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream\
    \ &is, Nimber &a) {\n        is >> a.x;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const Nimber &a) { return\
    \ os << a.x; }\n\n    Nimber inverse() const;\n\n    Nimber sqrt() {\n       \
    \ if (x < 256) {\n            if (!table_initialized) init_table();\n        \
    \    return Nimber(small_sqrt_table[x]);\n        }\n\n        int level = calculate_level(x);\n\
    \        return Nimber(calculate_sqrt(x, level));\n    }\n\n    bool is_zero()\
    \ const { return x == 0; }\n\n    private:\n    uint64_t x;\n\n    inline static\
    \ uint8_t small_table[256][256];\n    inline static bool table_initialized = false;\n\
    \    inline static uint8_t small_sqrt_table[256];\n\n    static void init_table()\
    \ {\n        if (table_initialized) return;\n        small_table[0][0] = 0; small_table[0][1]\
    \ = 0;\n        small_table[1][0] = 0; small_table[1][1] = 1;\n        for (int\
    \ level = 1; level <= 3; ++level) {\n            int half = 1 << (1 << (level\
    \ - 1));\n            int full = 1 << (1 << level);\n            for (int i =\
    \ 0; i < full; ++i) {\n                for (int j = 0; j < full; ++j) {\n    \
    \                if (i < half && j < half) continue;\n                    int\
    \ x0 = i & (half - 1);\n                    int x1 = i >> (1 << (level - 1));\n\
    \                    int y0 = j & (half - 1);\n                    int y1 = j\
    \ >> (1 << (level - 1));\n                    int p = small_table[x0][y0];\n \
    \                   int m = small_table[x0 ^ x1][y0 ^ y1];\n                 \
    \   int b = small_table[small_table[x1][y1]][half >> 1];\n                   \
    \ small_table[i][j] = p ^ b ^ ((p ^ m) << (1 << (level - 1)));\n             \
    \   }\n            }\n        }\n\n        for (int i = 0; i < 256; ++i) {\n \
    \           small_sqrt_table[small_table[i][i]] = i;\n        }\n\n        table_initialized\
    \ = true;\n    }\n\n    static uint64_t build_up(const uint64_t upper, const uint64_t\
    \ lower, int level) {\n        return upper << (1 << (level - 1)) ^ lower;\n \
    \   }\n\n    /// @brief x * y \u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u30D8\
    \u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param y \n    ///\
    \ @param level \n    /// @return \n    static uint64_t calculate_mul(const uint64_t\
    \ x, const uint64_t y, int level) {\n        if (level <= 3) { \n            if\
    \ (!table_initialized) init_table();\n            return small_table[x][y];\n\
    \        }\n\n        const auto &[x1, x0] = separate(x, level);\n        const\
    \ auto &[y1, y0] = separate(y, level);\n\n        uint64_t p = calculate_mul(x0,\
    \ y0, level - 1);\n        uint64_t e = 1ULL << (1 << (level - 1));\n\n      \
    \  uint64_t m = calculate_mul(x0 ^ x1, y0 ^ y1, level - 1);\n        uint64_t\
    \ a = p ^ m * e;\n        uint64_t b = calculate_mul(calculate_mul(x1, y1, level\
    \ - 1), e >> 1, level - 1);\n\n        uint64_t res = (p * e) ^ a ^ b;\n\n   \
    \     return res;\n    }\n\n    /// @brief x \u306E\u81EA\u4E57\u3092\u6C42\u3081\
    \u308B\u30D8\u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param\
    \ level \n    /// @return \n    static uint64_t calculate_square(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_table[x][x];\n        }\n\n        const\
    \ auto &[x1, x0] = separate(x, level);\n\n        uint64_t p = calculate_square(x0,\
    \ level - 1);\n        uint64_t b = calculate_square(x1, level - 1);\n       \
    \ \n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t mul_part\
    \ = calculate_mul(b, e >> 1, level - 1);\n\n        return p ^ (b << (1 << (level\
    \ - 1))) ^ mul_part;\n    }\n\n    static uint64_t calculate_sqrt(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_sqrt_table[x];\n        }\n\n      \
    \  const auto &[x1, x0] = separate(x, level);\n\n        uint64_t y1 = calculate_sqrt(x1,\
    \ level - 1);\n\n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t\
    \ prod = calculate_mul(x1, e >> 1, level - 1);\n        uint64_t y0 = calculate_sqrt(prod\
    \ ^ x0, level - 1);\n\n        return (y1 << (1 << (level - 1))) ^ y0;\n    }\n\
    \n    /// @brief x < 2^(2^k) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 k \u3092\u6C42\u3081\u308B.\n    /// @param x \n    /// @note x >\
    \ 1 \u306E\u3068\u304D\u306F, k = floor_log2(floor_log2(x)) + 1 \u304C\u6210\u308A\
    \u7ACB\u3064.\n    static int calculate_level(const uint64_t &x) {\n        if\
    \ (x == 0 || x == 1) { return 0; }\n\n        return floor_log2(floor_log2(x))\
    \ + 1;\n    }\n\n    /// @brief \u975E\u8CA0\u6574\u6570 x \u3092 x = x1 e_{level}\
    \ + x0, 0 <= x_0 < e_{level}, 0 <= x_1 < e_{level} \u3068\u306A\u308B\u3088\u3046\
    \u306B\u5206\u5272\u3059\u308B. \u305F\u3060\u3057, e_k := 2^(2^k).\n    /// @param\
    \ x \u975E\u8CA0\u6574\u6570\n    /// @param level e_k \u306B\u304A\u3051\u308B\
    \ k \u306E\u5024\n    /// @return {x1, x0} (\u9806\u756A\u6CE8\u610F)\n    static\
    \ pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {\n        uint64_t\
    \ upper = x >> (1 << (level - 1));\n        uint64_t lower = x ^ (upper << (1\
    \ << level - 1));\n\n        return { upper, lower };\n    }\n};\n\ntemplate<typename\
    \ T>\nNimber pow(Nimber x, T n) {\n    if constexpr (std::is_signed_v<T>) {\n\
    \        if (n < 0) return pow(x.inverse(), -n);\n    }\n\n    Nimber res(1);\n\
    \    while (n > 0) {\n        if (n & 1) res *= x;\n        x = x.square();\n\
    \        n >>= 1;\n    }\n    return res;\n}\n\ninline Nimber Nimber::inverse()\
    \ const {\n    int l = calculate_level(x);\n    return pow(*this, l >= 6 ? -2ULL\
    \ : (1ULL << (1 << l)) - 2);\n}\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Algebra/Nimber.hpp\n\
    \n#include \"../template/template.hpp\"\n\nclass Nimber {\n    public:\n    Nimber():\
    \ x(0) {}\n    Nimber(uint64_t x): x(x) {}\n\n    Nimber operator-() const { return\
    \ Nimber(x); }\n\n    Nimber& operator+=(const Nimber &b) {\n        x ^= b.x;\n\
    \        return *this;\n    }\n\n    friend Nimber operator+(const Nimber &x,\
    \ const Nimber &y) { return Nimber(x) += y; }\n\n    Nimber& operator-=(const\
    \ Nimber &b) {\n        *this += b;\n        return *this;\n    }\n\n    friend\
    \ Nimber operator-(const Nimber &x, const Nimber &y) { return Nimber(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    Nimber& operator*=(const Nimber &b) {\n      \
    \  if ((x | b.x) < 256) {\n            if (!table_initialized) init_table();\n\
    \            x = small_table[x][b.x];\n            return *this;\n        }\n\
    \        int level = max(calculate_level(x), calculate_level(b.x));\n        x\
    \ = calculate_mul(x, b.x, level);\n        return *this;\n    }\n\n    friend\
    \ Nimber operator*(const Nimber &x, const Nimber &y) { return Nimber(x) *= y;\
    \ }\n\n    friend bool operator==(const Nimber &a, const Nimber &b) { return a.x\
    \ == b.x; }\n    friend bool operator!=(const Nimber &a, const Nimber &b) { return\
    \ a.x != b.x; }\n    friend bool operator<(const Nimber &a, const Nimber &b) {\
    \ return a.x < b.x; }\n\n    Nimber square() const {\n        if (x < 256) {\n\
    \            if (!table_initialized) init_table();\n            return small_table[x][x];\n\
    \        }\n        int level = calculate_level(x);\n        return Nimber(calculate_square(x,\
    \ level));\n    }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream\
    \ &is, Nimber &a) {\n        is >> a.x;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const Nimber &a) { return\
    \ os << a.x; }\n\n    Nimber inverse() const;\n\n    Nimber sqrt() {\n       \
    \ if (x < 256) {\n            if (!table_initialized) init_table();\n        \
    \    return Nimber(small_sqrt_table[x]);\n        }\n\n        int level = calculate_level(x);\n\
    \        return Nimber(calculate_sqrt(x, level));\n    }\n\n    bool is_zero()\
    \ const { return x == 0; }\n\n    private:\n    uint64_t x;\n\n    inline static\
    \ uint8_t small_table[256][256];\n    inline static bool table_initialized = false;\n\
    \    inline static uint8_t small_sqrt_table[256];\n\n    static void init_table()\
    \ {\n        if (table_initialized) return;\n        small_table[0][0] = 0; small_table[0][1]\
    \ = 0;\n        small_table[1][0] = 0; small_table[1][1] = 1;\n        for (int\
    \ level = 1; level <= 3; ++level) {\n            int half = 1 << (1 << (level\
    \ - 1));\n            int full = 1 << (1 << level);\n            for (int i =\
    \ 0; i < full; ++i) {\n                for (int j = 0; j < full; ++j) {\n    \
    \                if (i < half && j < half) continue;\n                    int\
    \ x0 = i & (half - 1);\n                    int x1 = i >> (1 << (level - 1));\n\
    \                    int y0 = j & (half - 1);\n                    int y1 = j\
    \ >> (1 << (level - 1));\n                    int p = small_table[x0][y0];\n \
    \                   int m = small_table[x0 ^ x1][y0 ^ y1];\n                 \
    \   int b = small_table[small_table[x1][y1]][half >> 1];\n                   \
    \ small_table[i][j] = p ^ b ^ ((p ^ m) << (1 << (level - 1)));\n             \
    \   }\n            }\n        }\n\n        for (int i = 0; i < 256; ++i) {\n \
    \           small_sqrt_table[small_table[i][i]] = i;\n        }\n\n        table_initialized\
    \ = true;\n    }\n\n    static uint64_t build_up(const uint64_t upper, const uint64_t\
    \ lower, int level) {\n        return upper << (1 << (level - 1)) ^ lower;\n \
    \   }\n\n    /// @brief x * y \u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u30D8\
    \u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param y \n    ///\
    \ @param level \n    /// @return \n    static uint64_t calculate_mul(const uint64_t\
    \ x, const uint64_t y, int level) {\n        if (level <= 3) { \n            if\
    \ (!table_initialized) init_table();\n            return small_table[x][y];\n\
    \        }\n\n        const auto &[x1, x0] = separate(x, level);\n        const\
    \ auto &[y1, y0] = separate(y, level);\n\n        uint64_t p = calculate_mul(x0,\
    \ y0, level - 1);\n        uint64_t e = 1ULL << (1 << (level - 1));\n\n      \
    \  uint64_t m = calculate_mul(x0 ^ x1, y0 ^ y1, level - 1);\n        uint64_t\
    \ a = p ^ m * e;\n        uint64_t b = calculate_mul(calculate_mul(x1, y1, level\
    \ - 1), e >> 1, level - 1);\n\n        uint64_t res = (p * e) ^ a ^ b;\n\n   \
    \     return res;\n    }\n\n    /// @brief x \u306E\u81EA\u4E57\u3092\u6C42\u3081\
    \u308B\u30D8\u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param\
    \ level \n    /// @return \n    static uint64_t calculate_square(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_table[x][x];\n        }\n\n        const\
    \ auto &[x1, x0] = separate(x, level);\n\n        uint64_t p = calculate_square(x0,\
    \ level - 1);\n        uint64_t b = calculate_square(x1, level - 1);\n       \
    \ \n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t mul_part\
    \ = calculate_mul(b, e >> 1, level - 1);\n\n        return p ^ (b << (1 << (level\
    \ - 1))) ^ mul_part;\n    }\n\n    static uint64_t calculate_sqrt(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_sqrt_table[x];\n        }\n\n      \
    \  const auto &[x1, x0] = separate(x, level);\n\n        uint64_t y1 = calculate_sqrt(x1,\
    \ level - 1);\n\n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t\
    \ prod = calculate_mul(x1, e >> 1, level - 1);\n        uint64_t y0 = calculate_sqrt(prod\
    \ ^ x0, level - 1);\n\n        return (y1 << (1 << (level - 1))) ^ y0;\n    }\n\
    \n    /// @brief x < 2^(2^k) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 k \u3092\u6C42\u3081\u308B.\n    /// @param x \n    /// @note x >\
    \ 1 \u306E\u3068\u304D\u306F, k = floor_log2(floor_log2(x)) + 1 \u304C\u6210\u308A\
    \u7ACB\u3064.\n    static int calculate_level(const uint64_t &x) {\n        if\
    \ (x == 0 || x == 1) { return 0; }\n\n        return floor_log2(floor_log2(x))\
    \ + 1;\n    }\n\n    /// @brief \u975E\u8CA0\u6574\u6570 x \u3092 x = x1 e_{level}\
    \ + x0, 0 <= x_0 < e_{level}, 0 <= x_1 < e_{level} \u3068\u306A\u308B\u3088\u3046\
    \u306B\u5206\u5272\u3059\u308B. \u305F\u3060\u3057, e_k := 2^(2^k).\n    /// @param\
    \ x \u975E\u8CA0\u6574\u6570\n    /// @param level e_k \u306B\u304A\u3051\u308B\
    \ k \u306E\u5024\n    /// @return {x1, x0} (\u9806\u756A\u6CE8\u610F)\n    static\
    \ pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {\n        uint64_t\
    \ upper = x >> (1 << (level - 1));\n        uint64_t lower = x ^ (upper << (1\
    \ << level - 1));\n\n        return { upper, lower };\n    }\n};\n\ntemplate<typename\
    \ T>\nNimber pow(Nimber x, T n) {\n    if constexpr (std::is_signed_v<T>) {\n\
    \        if (n < 0) return pow(x.inverse(), -n);\n    }\n\n    Nimber res(1);\n\
    \    while (n > 0) {\n        if (n & 1) res *= x;\n        x = x.square();\n\
    \        n >>= 1;\n    }\n    return res;\n}\n\ninline Nimber Nimber::inverse()\
    \ const {\n    int l = calculate_level(x);\n    return pow(*this, l >= 6 ? -2ULL\
    \ : (1ULL << (1 << l)) - 2);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Algebra/Nimber.hpp
  requiredBy: []
  timestamp: '2026-10-17 00:11:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
documentation_of: Algebra/Nimber.hpp
layout: document
title: Nimber
---

## Outline

組み合わせゲーム理論の Nim から導入される Nimber (Nim 和, Nim 積) の計算を行う. $64$ bit 非負整数全体 $\lbrace 0, 1, \dots, 2^{64} - 1 \rbrace$ は Nim 和と Nim 積について体をなし, その上での加法・乗法・逆元・平方根を求める.

Nim 和は Bitwise-XOR である. Nim 積は, 上位と下位に半分ずつ分割して半分の大きさの Nim 積 $4$ 回に帰着させる再帰 (命題 10) で計算し, $256$ 未満の値どうしの積は前計算した表を引く. 積の計算量は $\Theta \left( (\log (x + y))^2 \right)$ である (命題 11).

## Theory

### 理論付け

以下, $\mathbb{N} := \lbrace 0, 1, 2, \dots \rbrace$ とする.

<div class="definition" markdown="1">

定義 1
---

$S \subsetneq \mathbb{N}$ に対して, $S$ に属さない最小の非負整数を $S$ の最小除外数 (minimum excluded value) といい, $\operatorname{mex} S$ と書く. すなわち,

$$ \operatorname{mex} S := \min (\mathbb{N} \setminus S) $$

である.

</div>

<div class="definition" markdown="1">

定義 2
---

$x, y \in \mathbb{N}$ に対して, Nim 和 $x \oplus y$ を

$$ x \oplus y := \operatorname{mex} \left( \lbrace a \oplus y \mid 0 \leq a < x \rbrace \cup \lbrace x \oplus b \mid 0 \leq b < y \rbrace \right) $$

によって ($x + y$ に関して) 帰納的に定める.

</div>

<div class="proposition" markdown="1">

命題 3
---

任意の $x, y \in \mathbb{N}$ に対して, $x \oplus y$ は $x$ と $y$ の Bitwise-XOR に等しい.

</div>

<div class="proof" markdown="1">

証明
---

$x$ と $y$ の Bitwise-XOR を $x \veebar y$ と書く. $x + y$ に関する帰納法で示す. $x + y$ より小さい組では主張が成り立つとし, $z := x \veebar y$ とおく. 示すべきことは, 定義 2 の mex を取る集合を $S$ として, $z \notin S$ かつ $\lbrace 0, 1, \dots, z - 1 \rbrace \subset S$ であることである.

**$z \notin S$ であること.** $0 \leq a < x$ ならば, 帰納法の仮定より $a \oplus y = a \veebar y$ であり, $a \neq x$ より $a \veebar y \neq x \veebar y = z$ である. $x \oplus b ~ (0 \leq b < y)$ についても同様である.

**$0 \leq c < z$ ならば $c \in S$ であること.** $c$ と $z$ が異なる bit のうち最上位のものを第 $t$ bit とすると, $c < z$ より, $c$ の第 $t$ bit は $0$, $z$ の第 $t$ bit は $1$ である. $z = x \veebar y$ なので, $x, y$ の第 $t$ bit はちょうど一方が $1$ である. $x$ の第 $t$ bit が $1$ であるとし, $a := c \veebar y$ とおく.

* 第 $t$ bit より上位では, $c$ と $z$ が一致するので, $a = c \veebar y$ と $z \veebar y = x$ は一致する.
* 第 $t$ bit では, $a$ は $0 \veebar 0 = 0$, $x$ は $1$ である.

よって $a < x$ であり, 帰納法の仮定より $a \oplus y = a \veebar y = c$ なので $c \in S$ である. $y$ の第 $t$ bit が $1$ の場合も, $b := x \veebar c$ とすれば同様である.

</div>

非負整数 $n$ に対して, $F_n := \lbrace 0, 1, \dots, 2^n - 1 \rbrace$ とする. 特に, `uint64_t` で表せる値全体は $F_{64}$ である.

<div class="corollary" markdown="1">

系 4
---

* $(\mathbb{N}, \oplus)$ は $0$ を単位元とする可換群であり, $x$ の逆元は $x$ 自身である.
* 任意の非負整数 $n$ について, $F_n$ は $\oplus$ で閉じている.

</div>

<div class="proof" markdown="1">

証明
---

命題 3 より, $\oplus$ は Bitwise-XOR なので明らかである.

</div>

<div class="definition" markdown="1">

定義 5
---

$x, y \in \mathbb{N}$ に対して, Nim 積 $x \otimes y$ を

$$ x \otimes y := \operatorname{mex} \lbrace (a \otimes y) \oplus (x \otimes b) \oplus (a \otimes b) \mid 0 \leq a < x, 0 \leq b < y \rbrace $$

によって ($x + y$ に関して) 帰納的に定める.

</div>

<div class="theorem" markdown="1">

定理 6
---

$(\mathbb{N}, \oplus, \otimes)$ は $0$ を加法単位元, $1$ を乗法単位元とする体である.

</div>

証明は Conway による ([Reference](#reference) の文献を参照). $1 \oplus 1 = 0$ なので, この体の標数は $2$ である.

非負整数 $k$ に対して,

$$ e_k := 2^{2^k}, \quad e'_k := \frac{e_k}{2} = 2^{2^k - 1} $$

とする. 例えば, $e_0 = 2, e_1 = 4, e_2 = 16, e_3 = 256$ であり, $F_{2^k} = \lbrace 0, 1, \dots, e_k - 1 \rbrace$ である. また, 以下では通常の整数の積を $\times$ で表し, Nim 積 $\otimes$ と区別する.

<div class="theorem" markdown="1">

定理 7
---

任意の非負整数 $k$ について, 以下が成り立つ.

* (1) $F_{2^k}$ は $\otimes$ で閉じている.
* (2) $x \in F_{2^k}$ ならば, $x \otimes e_k = x \times e_k$ である.
* (3) $e_k \otimes e_k = e_k \oplus e^\prime_k \left(= \frac{3}{2} e_k \right)$ である.

</div>

証明は Conway による ([Reference](#reference) の文献を参照).

<div class="corollary" markdown="1">

系 8
---

任意の非負整数 $k$ について, $F_{2^k}$ は $\mathbb{N}$ の部分体であり, 位数 $2^{2^k}$ の有限体である.

</div>

<div class="proof" markdown="1">

証明
---

$F_{2^k}$ は $0, 1$ を含み, 系 4 と定理 7 (1) より $\oplus, \otimes$ で閉じている. また, 系 4 より $x \in F_{2^k}$ の加法の逆元は $x$ 自身なので $F_{2^k}$ に属する. よって, $F_{2^k}$ は $\mathbb{N}$ の部分環である.

あとは, $x \in F_{2^k}, x \neq 0$ の乗法の逆元が $F_{2^k}$ に属することを示せばよい. 写像 $\varphi: F_{2^k} \to F_{2^k}; y \mapsto x \otimes y$ を考える (定理 7 (1) より $F_{2^k}$ に値を取る). $y_1, y_2 \in F_{2^k}$ が $x \otimes y_1 = x \otimes y_2$ を満たすならば $x \otimes (y_1 \oplus y_2) = 0$ であり, 定理 6 より $\mathbb{N}$ は体なので零因子を持たず, $y_1 \oplus y_2 = 0$, すなわち $y_1 = y_2$ である. よって $\varphi$ は単射であり, $F_{2^k}$ は有限集合なので全射でもある. 特に $x \otimes y = 1$ となる $y \in F_{2^k}$ が存在し, これが $\mathbb{N}$ における $x$ の逆元である.

位数は $\lvert F_{2^k} \rvert = 2^{2^k}$ である.

</div>

特に, $F_1 \subset F_2 \subset F_4 \subset \dots \subset F_{64}$ はそれぞれ部分体であり, `uint64_t` 全体 $F_{64}$ は位数 $2^{64}$ の有限体である.

なお, $n$ が $2$ 冪でないとき, $F_n$ は $\otimes$ で閉じていない. 例えば, 定理 7 (2) より $2 \otimes 4 = 2 \otimes e_1 = 2 \times e_1 = 8$ なので, $2, 4 \in F_3$ だが $2 \otimes 4 \notin F_3$ である.

<div class="proposition" markdown="1">

命題 9
---

任意の $a, b \in \mathbb{N}$ に対して, $(a \oplus b) \otimes (a \oplus b) = (a \otimes a) \oplus (b \otimes b)$ である.

</div>

<div class="proof" markdown="1">

証明
---

定理 6 より成り立つ分配法則と可換性から $(a \oplus b) \otimes (a \oplus b) = (a \otimes a) \oplus (a \otimes b) \oplus (a \otimes b) \oplus (b \otimes b)$ であり, 系 4 より $(a \otimes b) \oplus (a \otimes b) = 0$ である.

</div>

### アルゴリズム

#### 乗法

$k \geq 1$, $x \in F_{2^k}$ とする. $e_k = e_{k-1}^2$ より, $x$ は $x_0, x_1 \in F_{2^{k-1}}$ を用いて $x = x_1 \times e_{k-1} + x_0$ と一意に表せる (上位 $2^{k-1}$ bit と下位 $2^{k-1}$ bit への分割). 実装の `separate` はこの分割を求める. $x_1 \times e_{k-1}$ の下位 $2^{k-1}$ bit は全て $0$ であり, $x_0$ の $1$ が立つ bit は下位 $2^{k-1}$ bit に限られるので, 命題 3 より

$$ x_1 \times e_{k-1} + x_0 = (x_1 \times e_{k-1}) \oplus x_0 $$

でもある.

また, $x \in \mathbb{N}$ に対して, $x \in F_{2^k}$ となる最小の $k$ を $x$ のレベルと呼ぶ ($0, 1$ のレベルは $0$). 実装中の `level` はこれを指す.

<div class="proposition" markdown="1">

命題 10
---

$k \geq 1$ とし, $x, y \in F_{2^k}$ を

$$ x = x_1 \times e_{k-1} + x_0, \quad y = y_1 \times e_{k-1} + y_0 \quad (x_0, x_1, y_0, y_1 \in F_{2^{k-1}}) $$

と分割する. このとき,

$$\begin{align*}
    u &:= \left( (x_0 \oplus x_1) \otimes (y_0 \oplus y_1) \right) \oplus (x_0 \otimes y_0), \\
    v &:= (x_0 \otimes y_0) \oplus \left( (x_1 \otimes y_1) \otimes e'_{k-1} \right)
\end{align*}$$

とおくと, $u, v \in F_{2^{k-1}}$ であり,

$$ x \otimes y = u \times e_{k-1} + v $$

が成り立つ.

</div>

<div class="proof" markdown="1">

証明
---

$e := e_{k-1}$, $e^\prime := e^\prime_{k-1}$ とおく. $e^\prime < e$ より $e^\prime \in F_{2^{k-1}}$ なので, 定理 7 (1) より $u, v \in F_{2^{k-1}}$ である.

この節の冒頭で述べたことと定理 7 (2) より, $x = (x_1 \times e) \oplus x_0 = (x_1 \otimes e) \oplus x_0$ であり, $y$ についても同様である. よって, 分配法則と定理 7 (3) から

$$\begin{align*}
    x \otimes y
    &= \left( (x_1 \otimes e) \oplus x_0 \right) \otimes \left( (y_1 \otimes e) \oplus y_0 \right) \\
    &= \left( (x_1 \otimes y_1) \otimes (e \otimes e) \right) \oplus \left( \left( (x_1 \otimes y_0) \oplus (x_0 \otimes y_1) \right) \otimes e \right) \oplus (x_0 \otimes y_0) \\
    &= \left( (x_1 \otimes y_1) \otimes (e \oplus e') \right) \oplus \left( \left( (x_1 \otimes y_0) \oplus (x_0 \otimes y_1) \right) \otimes e \right) \oplus (x_0 \otimes y_0) \\
    &= \left( \left( (x_1 \otimes y_1) \oplus (x_1 \otimes y_0) \oplus (x_0 \otimes y_1) \right) \otimes e \right) \oplus (x_0 \otimes y_0) \oplus \left( (x_1 \otimes y_1) \otimes e' \right)
\end{align*}$$

である. ここで,

$$ (x_1 \otimes y_1) \oplus (x_1 \otimes y_0) \oplus (x_0 \otimes y_1) = \left( (x_0 \oplus x_1) \otimes (y_0 \oplus y_1) \right) \oplus (x_0 \otimes y_0) = u $$

なので, $x \otimes y = (u \otimes e) \oplus v$ である. $u, v \in F_{2^{k-1}}$ なので, 定理 7 (2) とこの節の冒頭で述べたことより $(u \otimes e) \oplus v = u \times e + v$ である.

</div>

命題 10 により, $F_{2^k}$ での Nim 積は $F_{2^{k-1}}$ での Nim 積

$$ x_0 \otimes y_0, \quad (x_0 \oplus x_1) \otimes (y_0 \oplus y_1), \quad x_1 \otimes y_1, \quad (x_1 \otimes y_1) \otimes e'_{k-1} $$

の $4$ 回と, XOR・シフトに帰着される. 実装では次のように計算する.

* $F_8$ (つまり $256$ 未満) どうしの積は, $256 \times 256$ の表を引く. 表は, $F_1 = \lbrace 0, 1 \rbrace$ の積から始めて, 命題 10 を $k = 1, 2, 3$ の順に適用して $O(e_3^2) = O(2^{16})$ で作る. 表は最初に必要になったときに $1$ 回だけ作られる.
* それ以外のときは, $2$ 数のレベルの大きい方を $k ~ (\geq 4)$ として, 命題 10 で $k = 3$ まで再帰する.

<div class="proposition" markdown="1">

命題 11
---

$x, y \in \mathbb{N}$ とし, $x, y$ のレベルの大きい方 (つまり $\max(x, y)$ のレベル) を $k$ とする. $k \geq 3$ のとき, 上の方法で $x \otimes y$ を計算すると, 以下が成り立つ.

* (1) 表の参照回数は $4^{k-3}$ 回である.
* (2) 表の参照以外の演算 (XOR, シフト, 分割) の回数は $O(4^{k-3})$ である.
* (3) $\dfrac{(\log_2 \max(x, y))^2}{64} < 4^{k-3} \leq \dfrac{(\log_2 \max(x, y))^2}{16}$ である.

特に, $x \otimes y$ の計算量は $\Theta(4^k) = \Theta \left( (\log (x + y))^2 \right)$ である.

</div>

<div class="proof" markdown="1">

証明
---

レベル $j$ の積, つまり $F_{2^j}$ の元とみなした積の計算を考える. $j = 3$ ならば表を $1$ 回引き, $j \geq 4$ ならば命題 10 により, レベル $j - 1$ の積

$$ x_0 \otimes y_0, \quad (x_0 \oplus x_1) \otimes (y_0 \oplus y_1), \quad x_1 \otimes y_1, \quad (x_1 \otimes y_1) \otimes e'_{j-1} $$

を $4$ 回計算し, それ以外は分割・XOR・シフトを定数回行う. レベル $j$ の積の表の参照回数を $M(j)$, 再帰呼び出しの回数 (自身も含む) を $C(j)$ とすると, これらは $x, y$ の値によらず,

$$ M(3) = C(3) = 1, \quad M(j) = 4 M(j-1), \quad C(j) = 4 C(j-1) + 1 \quad (j \geq 4) $$

を満たす. これを解くと

$$ M(j) = 4^{j-3}, \quad C(j) = \frac{4^{j-2} - 1}{3} $$

である. 実装は $x \otimes y$ をレベル $k$ の積として計算するので, (1) は $M(k) = 4^{k-3}$ から従う. また, 各呼び出しで行う表の参照以外の演算は定数回なので, その回数は $O(C(k)) = O(4^{k-3})$ であり, (2) が従う.

(3) を示す. $m := \max(x, y)$ とおくと, $m$ のレベルが $k$ であることから $2^{2^{k-1}} \leq m < 2^{2^k}$ である. 対数を取って $2$ 乗すると $(2^k)^2 / 4 \leq (\log_2 m)^2 < (2^k)^2$ であり, $4^{k-3} = (2^k)^2 / 64$ なので, (3) が従う.

最後に, $m \leq x + y \leq 2m$ と $m \geq 2$ より $\log_2 m \leq \log_2 (x + y) \leq 2 \log_2 m$ なので, $\Theta \left( (\log (x + y))^2 \right)$ が従う.

</div>

$64$ bit ($k = 6$) では, 表の参照は $4^3 = 64$ 回である. なお, $k < 3$ のときは表を $1$ 回引くだけである.

<div class="corollary" markdown="1">

系 12
---

$k \geq 1$ とし, $x = x_1 \times e_{k-1} + x_0 ~ (x_0, x_1 \in F_{2^{k-1}})$ とする. このとき,

$$ x \otimes x = (x_1 \otimes x_1) \times e_{k-1} + \left( (x_0 \otimes x_0) \oplus \left( (x_1 \otimes x_1) \otimes e'_{k-1} \right) \right) $$

である.

</div>

<div class="proof" markdown="1">

証明
---

命題 10 で $y = x$ とすると, 命題 9 より $u = (x_0 \otimes x_0) \oplus (x_1 \otimes x_1) \oplus (x_0 \otimes x_0) = x_1 \otimes x_1$ である.

</div>

系 12 により, 平方は $F_{2^{k-1}}$ での平方 $2$ 回と積 $1$ 回に帰着される. $k \geq 3$ として, レベル $k$ の平方の表の参照回数を $S(k)$ とすると, 命題 11 の証明の $M(j) = 4^{j-3}$ を用いて

$$ S(3) = 1, \quad S(k) = 2 S(k-1) + M(k-1) \quad (k \geq 4) $$

であり, これを解くと

$$ S(k) = \frac{4^{k-3} + 2^{k-3}}{2} $$

である. よって, $x$ のレベルを $k ~ (\geq 3)$ とすると, 平方の計算量は $\Theta(4^k) = \Theta \left( (\log x)^2 \right)$ であり, $64$ bit ($k = 6$) では表の参照は $S(6) = 36$ 回である.

#### 逆元

$x \in \mathbb{N}$ と非負整数 $m$ に対して, $x$ の Nim 積の意味での $m$ 乗を $x^{\otimes m}$ と書く ($x^{\otimes 0} = 1$).

<div class="proposition" markdown="1">

命題 13
---

$x \in F_{2^k}$, $x \neq 0$ とする. このとき, $x$ の Nim 積に関する逆元は $x^{\otimes (e_k - 2)}$ である.

</div>

<div class="proof" markdown="1">

証明
---

系 8 より, $F_{2^k}$ の乗法群 $F_{2^k} \setminus \lbrace 0 \rbrace$ の位数は $e_k - 1$ である. Lagrange の定理より $x^{\otimes (e_k - 1)} = 1$ なので, $x \otimes x^{\otimes (e_k - 2)} = 1$ である.

</div>

実装では, $k$ を $x$ のレベルとして, $x^{\otimes (e_k - 2)}$ を繰り返し二乗法で計算する ($k = 6$ のときは $e_6 - 2 = 2^{64} - 2$ を `-2ULL` で表す). 指数 $e_k - 2$ は $2^k$ bit なので, 平方 $2^k$ 回と積高々 $2^k$ 回である. 途中に現れる値は全て $F_{2^k}$ に属するので, 命題 11 と平方の計算量より, 全体の計算量は $O(2^k \cdot 4^k) = O(8^k) = O \left( (\log x)^3 \right)$ である ($x \geq 2$ のとき).

#### 平方根

<div class="theorem" markdown="1">

定理 14
---

非負整数 $k$ と $b \in F_{2^k}$ に対して, $a \otimes a = b$ を満たす $a \in F_{2^k}$ がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

$g: F_{2^k} \to F_{2^k}; a \mapsto a \otimes a$ とする (定理 7 (1) より $F_{2^k}$ に値を取る). $g$ が全単射であることを示せばよい.

$a_1, a_2 \in F_{2^k}$ が $g(a_1) = g(a_2)$ を満たすとする. 命題 9 より

$$ (a_1 \oplus a_2) \otimes (a_1 \oplus a_2) = (a_1 \otimes a_1) \oplus (a_2 \otimes a_2) = 0 $$

である. 系 8 より $F_{2^k}$ は体なので $a_1 \oplus a_2 = 0$, すなわち $a_1 = a_2$ である. よって $g$ は単射である. $F_{2^k}$ は有限集合なので, $g$ は全単射である.

</div>

$F_{2^k} \subset F_{2^{l}} ~ (k \leq l)$ であり, $F_{2^{l}}$ においても $a \otimes a = b$ を満たす $a$ は一意なので, 定理 14 の $a$ は $k$ の取り方によらない.

<div class="definition" markdown="1">

定義 15
---

$b \in \mathbb{N}$ に対して, $a \otimes a = b$ を満たす $a \in \mathbb{N}$ (定理 14 よりただ一つ存在する) を $b$ の平方根といい, $\sqrt{b}$ と書く.

</div>

<div class="proposition" markdown="1">

命題 16
---

$k \geq 1$ とし, $x = x_1 \times e_{k-1} + x_0 ~ (x_0, x_1 \in F_{2^{k-1}})$ とする. このとき,

$$ y_1 := \sqrt{x_1}, \quad y_0 := \sqrt{(x_1 \otimes e'_{k-1}) \oplus x_0} $$

とおくと, $y_0, y_1 \in F_{2^{k-1}}$ であり, $\sqrt{x} = y_1 \times e_{k-1} + y_0$ である.

</div>

<div class="proof" markdown="1">

証明
---

$x_1, (x_1 \otimes e^\prime_{k-1}) \oplus x_0 \in F_{2^{k-1}}$ なので, 定理 14 より $y_0, y_1 \in F_{2^{k-1}}$ である. $y := y_1 \times e_{k-1} + y_0$ とおくと, 系 12 より

$$\begin{align*}
    y \otimes y
    &= (y_1 \otimes y_1) \times e_{k-1} + \left( (y_0 \otimes y_0) \oplus \left( (y_1 \otimes y_1) \otimes e'_{k-1} \right) \right) \\
    &= x_1 \times e_{k-1} + \left( (x_1 \otimes e'_{k-1}) \oplus x_0 \oplus (x_1 \otimes e'_{k-1}) \right) \\
    &= x_1 \times e_{k-1} + x_0 \\
    &= x
\end{align*}$$

である. 平方根の一意性より $y = \sqrt{x}$ である.

</div>

実装では, $256$ 未満の平方根は, 積の表から作った表 ($256$ 要素) を引き, $k \geq 4$ のときは命題 16 で再帰する. 表の参照回数は平方と同じ漸化式を満たすので $S(k)$ 回であり, 計算量は $\Theta \left( (\log x)^2 \right)$ ($64$ bit で表の参照 $36$ 回) である.

### 具体例

* $2 \otimes 2 = 3$, $4 \otimes 4 = 6$, $16 \otimes 16 = 24$ (定理 7 (3)).
* $2 \otimes 3 = 1$ なので, $2$ の逆元は $3$ である.
* $3 \otimes 3 = 2$ なので, $\sqrt{2} = 3$ である.

## Contents

以下, 値が $x$ の `Nimber` を単に $x$ と書く.

### Constructor

```cpp
Nimber()
Nimber(uint64_t x)
```

* 引数なしのときは $0$, そうでなければ $x$ を表す Nimber を生成する.

### 加法・減法

```cpp
Nimber operator+(const Nimber &x, const Nimber &y)
Nimber operator-(const Nimber &x, const Nimber &y)
Nimber operator-() const
```

* $x \oplus y$ を返す. 系 4 より $-x = x$ なので, 減法も $x \oplus y$, 単項マイナスは $x$ 自身である.
* 複合代入演算子 `+=`, `-=` も使える.
* **計算量**
  * $O(1)$

### 乗法

```cpp
Nimber operator*(const Nimber &x, const Nimber &y)
```

* $x \otimes y$ を返す. 複合代入演算子 `*=` も使える.
* **計算量**
  * $\Theta \left( (\log (x + y))^2 \right)$. $x, y$ のレベルの大きい方を $k ~ (\geq 3)$ とすると, 表の参照 $4^{k-3}$ 回 ($64$ bit で $64$ 回). $k < 3$ のときは表の参照 $1$ 回. 命題 11 を参照.
  * 初回の呼び出し時のみ, 表の構築に $O(2^{16})$ かかる.

### square

```cpp
Nimber square() const
```

* $x \otimes x$ を返す.
* **計算量**
  * $\Theta \left( (\log x)^2 \right)$. $x$ のレベルを $k ~ (\geq 3)$ とすると, 表の参照 $S(k) = (4^{k-3} + 2^{k-3}) / 2$ 回 ($64$ bit で $36$ 回). 系 12 の後の議論を参照.

### inverse

```cpp
Nimber inverse() const
```

* Nim 積に関する $x$ の逆元を返す.
* **制約**
  * $x \neq 0$
* **計算量**
  * $O \left( (\log x)^3 \right)$. $x$ のレベルを $k$ とすると, 平方 $2^k$ 回と積高々 $2^k$ 回. 命題 13 の後の議論を参照.

### sqrt

```cpp
Nimber sqrt()
```

* $x$ の平方根 $\sqrt{x}$ (定義 15) を返す.
* **計算量**
  * $\Theta \left( (\log x)^2 \right)$. $x$ のレベルを $k ~ (\geq 3)$ とすると, 表の参照 $S(k)$ 回 ($64$ bit で $36$ 回). 命題 16 の後の議論を参照.

### pow

```cpp
template<typename T>
Nimber pow(Nimber x, T n)
```

* $x^{\otimes n}$ を返す. $T$ が符号付き整数型で $n < 0$ のときは, $x$ の逆元の $(-n)$ 乗を返す.
* **制約**
  * $n < 0$ のときは $x \neq 0$.
* **計算量**
  * 平方と積をそれぞれ $O(\log \lvert n \rvert)$ 回. $n < 0$ のときは, これに加えて逆元を $1$ 回計算する.

### is_zero

```cpp
bool is_zero() const
```

* $x = 0$ ならば `true`, そうでなければ `false` を返す.

### 比較

```cpp
bool operator==(const Nimber &a, const Nimber &b)
bool operator!=(const Nimber &a, const Nimber &b)
bool operator<(const Nimber &a, const Nimber &b)
```

* 値が等しいかどうかを判定する.
* `<` は値を非負整数として比較する. `set` や `map` のキーに使うためのもので, 体の演算とは関係しない.

### 入出力

```cpp
istream &operator>>(istream &is, Nimber &a)
ostream &operator<<(ostream &os, const Nimber &a)
```

* 非負整数として入出力する.

## Reference

* J. H. Conway, *On Numbers and Games*, Chapter 6.
* https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit
* https://natsugiri.hatenablog.com/entry/2020/03/29/073605

## History

|日付|内容|
|:---:|:---:|
|2026/11/27| ドキュメントの書き直し (構成の整理, 証明・計算量の追加, 誤記の修正) |
|2026/02/21| sqrt の実装 |
|2026/02/15| Nimber クラスの実装 |
