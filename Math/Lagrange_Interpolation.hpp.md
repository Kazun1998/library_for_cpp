---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Counting/Combination_Calculator.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B\u8AD6\u306B\u95A2\u3059\u308B\u57FA\u672C\
      \u7684\u306A\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/enumerable.hpp
    title: enumerable
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
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\
      \u305F\u8A55\u4FA1\u70B9\u306E\u5024\u306E\u8A08\u7B97 (O(N^2))"
    links: []
  bundledCode: "#line 2 \"Math/Lagrange_Interpolation.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\nll pow(ll x, ll y) { return intpow(x,\
    \ y); }\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, integral U>\nT modpow(T x, U y, T z)\
    \ {\n    T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\ntemplate<typename\
    \ T>\nT sum(const vector<T> &X) {\n    T y = T(0);\n    for (auto &&x: X) { y\
    \ += x; }\n    return y;\n}\n\ntemplate<typename T>\nT gcd(const T x, const T\
    \ y) {\n    return y == 0 ? x : gcd(y, x % y);\n}\n\n// a x + b y = gcd(a, b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\u3057\u3066\
    , (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T,\
    \ T, T> Extended_Euclid(T a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while\
    \ (b) {\n        auto [q, r] = divmod(a, b);\n        a = b;\n        b = r;\n\
    \        tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v,\
    \ u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrtl(N);\n\
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
    \ get_bits(x, bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\
    \u3093\u304B\u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\
    \u529B\u3059\u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x));\
    \ }\n#line 73 \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 2 \"template/enumerable.hpp\"\n\n#line 11 \"template/enumerable.hpp\"\
    \n#include <stdexcept>\n#line 13 \"template/enumerable.hpp\"\n\nnamespace enumerable\
    \ {\n    /// @brief \u30B3\u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u95A2\
    \u6570\u3092\u9069\u7528\u3057\u3001\u305D\u306E\u7D50\u679C\u3092\u65B0\u3057\
    \u3044 `std::vector` \u3068\u3057\u3066\u8FD4\u3059\u3002\n    ///\n    /// Ruby\
    \ \u306E `Enumerable#collect` (\u307E\u305F\u306F `map`) \u306B\u76F8\u5F53\u3057\
    \u307E\u3059\u3002C++\u306E `std::transform` \u306B\u4F3C\u3066\u3044\u307E\u3059\
    \u304C\u3001\u5E38\u306B\u51FA\u529B\u3068\u3057\u3066\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u751F\u6210\u3057\u3066\u8FD4\u3059\u70B9\u304C\u7570\u306A\u308A\u307E\
    \u3059\u3002\n    /// @tparam Container \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\
    \u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B (e.g., std::vector<T>)\u3002\n    ///\
    \ @tparam Func \u5404\u8981\u7D20\u306B\u9069\u7528\u3059\u308B\u95A2\u6570\u306E\
    \u578B\u3002\n    /// @param container \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\
    \u3002\n    /// @param func \u5404\u8981\u7D20\u306B\u9069\u7528\u3059\u308B\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8 (\u30E9\u30E0\u30C0\u5F0F\u306A\u3069\
    )\u3002\n    /// @return \u95A2\u6570\u306E\u9069\u7528\u7D50\u679C\u3092\u683C\
    \u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n    template <typename\
    \ Container, typename Func>\n    auto collect(const Container& container, const\
    \ Func& func) {\n        using ResultType = std::invoke_result_t<Func, typename\
    \ Container::const_reference>;\n        std::vector<ResultType> result;\n    \
    \    if constexpr (requires { std::size(container); }) {\n            result.reserve(std::size(container));\n\
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
    #line 2 \"Counting/Combination_Calculator.hpp\"\n\n#line 4 \"Counting/Combination_Calculator.hpp\"\
    \n\ntemplate<typename mint>\nclass Combination_Calculator {\n    private:\n  \
    \  vector<mint> _fact, _fact_inv;\n\n    void resize(const int m) {\n        if\
    \ (m < _fact.size()) { return; }\n\n        int current_size = _fact.size();\n\
    \        int next_size = min(max(2 * current_size, m + 1), mint::mod());\n\n \
    \       _fact.resize(next_size);\n        _fact_inv.resize(next_size);\n\n   \
    \     for (int k = current_size; k < next_size; k++) {\n            _fact[k] =\
    \ k * _fact[k - 1];\n        }\n\n        _fact_inv.back() = _fact.back().inverse();\n\
    \n        for (int k = next_size - 2; k >= current_size; --k) {\n            _fact_inv[k]\
    \ = (k + 1) * _fact_inv[k + 1];\n        }\n    }\n\n    public:\n    /**\n  \
    \   * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF: \u521D\u671F\u30B5\u30A4\
    \u30BAn\u307E\u3067\u968E\u4E57\u30FB\u9006\u968E\u4E57\u3092\u8A08\u7B97\u3059\
    \u308B\n     * @param n \u521D\u671F\u8A08\u7B97\u306E\u4E0A\u9650\n     */\n\
    \    Combination_Calculator(const int n) {\n        _fact.emplace_back(1); _fact.emplace_back(1);\n\
    \        _fact_inv.emplace_back(1); _fact_inv.emplace_back(1);\n\n        resize(n);\n\
    \    }\n\n    Combination_Calculator(): Combination_Calculator(0) {}\n\n    /**\n\
    \     * @brief k! \u3092\u53D6\u5F97\n     */\n    mint fact(const int k) {\n\
    \        resize(k);\n        return _fact[k];\n    }\n\n    /**\n     * @brief\
    \ (k!)^(-1) \u3092\u53D6\u5F97\n     */\n    mint fact_inv(const int k) {\n  \
    \      resize(k);\n        return _fact_inv[k];\n    }\n\n    /**\n     * @brief\
    \ k \u306E\u9006\u5143 k^(-1) \u3092\u6C42\u3081\u308B\n     * @param k \u9006\
    \u5143\u3092\u6C42\u3081\u305F\u3044\u6570\n     */\n    mint inv(const int k)\
    \ {\n        if (k <= 0) { return 0; }\n\n        resize(k);\n        return _fact_inv[k]\
    \ * _fact[k - 1];\n    }\n\n    /**\n     * @brief \u7D44\u307F\u5408\u308F\u305B\
    \ nCk \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint nCr(const int n, const\
    \ int r) {\n        if (!(0 <= r && r <= n)) { return 0; }\n        resize(n);\n\
    \        return _fact[n] * _fact_inv[r] * _fact_inv[n - r];\n    }\n\n    /**\n\
    \     * @brief \u9806\u5217 nPk \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint\
    \ nPr(const int n, const int r) {\n        if (!(0 <= r && r <= n)) { return 0;\
    \ }\n        resize(n);\n        return _fact[n] * _fact_inv[n - r];\n    }\n\n\
    \    /**\n     * @brief \u91CD\u8907\u7D44\u5408\u305B nHk \u3092\u8A08\u7B97\u3059\
    \u308B\n     */\n    mint nHr(const int n, const int r) {\n        if (n == 0\
    \ && r == 0) { return 1; }\n\n        return nCr(n + r - 1, r);\n    }\n\n   \
    \ /**\n     * @brief \u591A\u9805\u4FC2\u6570 (k_sum)! / (k1! * k2! * ...) \u3092\
    \u8A08\u7B97\u3059\u308B\n     */\n    mint multinomial_coefficient(const vector<int>\
    \ &ks) {\n        int k_sum = 0;\n        mint lower = 1;\n        for (int k:\
    \ ks) {\n            k_sum += k;\n            lower *= _fact_inv[k];\n       \
    \ }\n\n        resize(k_sum);\n\n        mint upper = _fact[k_sum];\n\n      \
    \  return upper * lower;\n    }\n\n    mint catalan(const int n) {\n        if\
    \ (n < 0) { return 0; }\n        resize(2 * n);\n        return _fact[2 * n] *\
    \ _fact_inv[n + 1] * _fact_inv[n];\n    }\n};\n#line 6 \"Math/Lagrange_Interpolation.hpp\"\
    \n\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\
    \u3044\u305F\u8A55\u4FA1\u70B9\u306E\u5024\u306E\u8A08\u7B97 (O(N^2))\n * @details\
    \ \u4E0E\u3048\u3089\u308C\u305F n \u500B\u306E\u70B9 (x[i], y[i]) \u3092\u901A\
    \u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F P \u306B\u5BFE\u3057\u3001\
    P(X) \u3092\u6C42\u3081\u308B\u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B\
    \ (ModInt \u7B49)\n * @param x \u70B9\u306E x \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\
    \ (\u3059\u3079\u3066\u7570\u306A\u308B\u5FC5\u8981\u304C\u3042\u308B)\n * @param\
    \ y \u70B9\u306E y \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\n * @param X \u8A55\u4FA1\
    \u70B9\n * @return F P(X) \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point(const\
    \ vector<F> &x, const vector<F> &y, F X) {\n    assert(x.size() == y.size());\n\
    \    int n = (int)x.size();\n\n    // \u5206\u5B50\u306E\u7D2F\u7A4D\u7A4D\u3092\
    \u524D\u8A08\u7B97 O(N)\n    vector<F> pre(n + 1, F(1)), suf(n + 1, F(1));\n \
    \   for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] * (X - x[i]);\n    for (int\
    \ i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * (X - x[i]);\n\n    F Y = F(0);\n\
    \    for (int i = 0; i < n; ++i) {\n        // \u5206\u6BCD\u306E\u7A4D\u3092\u8A08\
    \u7B97\n        F den = F(1);\n        for (int j = 0; j < n; ++j) {\n       \
    \     if (i == j) continue;\n\n            den *= (x[i] - x[j]);\n        }\n\n\
    \        Y += y[i] * pre[i] * suf[i + 1] / den;\n    }\n\n    return Y;\n}\n\n\
    /**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\
    \u305F\u8A55\u4FA1\u70B9\u306E\u5024\u306E\u8A08\u7B97 (O(N^2))\n * @details points[i]\
    \ = (x_i, y_i) \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\
    \ P \u306B\u5BFE\u3057\u3001P(X) \u3092\u6C42\u3081\u308B\u3002\n * @tparam F\
    \ \u4F53\u3092\u8868\u3059\u578B\n * @param points \u70B9 (x, y) \u306E\u30EA\u30B9\
    \u30C8\n * @param X \u8A55\u4FA1\u70B9\n * @return F P(X) \u306E\u5024\n */\n\
    template<typename F>\nF Lagrange_Interpolation_Point(const vector<pair<F, F>>\
    \ &points, F X) {\n    auto x = enumerable::collect(points, [](const auto &p)\
    \ { return p.first; });\n    auto y = enumerable::collect(points, [](const auto\
    \ &p) { return p.second; });\n    return Lagrange_Interpolation_Point(x, y, X);\n\
    }\n\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\
    \u3044\u305F\u591A\u9805\u5F0F\u306E\u4FC2\u6570\u306E\u6C7A\u5B9A (O(N^2))\n\
    \ * @details \u4E0E\u3048\u3089\u308C\u305F n \u500B\u306E\u70B9 (x[i], y[i])\
    \ \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F P(x) = \\\
    sum res[i] * x^i \u3092\u6C42\u3081\u308B\u3002\n * @tparam F \u4F53\u3092\u8868\
    \u3059\u578B\n * @param x \u70B9\u306E x \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\
    \ (\u3059\u3079\u3066\u7570\u306A\u308B\u5FC5\u8981\u304C\u3042\u308B)\n * @param\
    \ y \u70B9\u306E y \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\n * @return vector<F>\
    \ \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u30EA\u30B9\u30C8 res (res[i] \u306F x^i\
    \ \u306E\u4FC2\u6570)\n */\ntemplate<typename F>\nvector<F> Lagrange_Interpolation_Polynomial(const\
    \ vector<F> &x, const vector<F> &y) {\n    assert(x.size() == y.size());\n   \
    \ int n = (int)x.size();\n    if (n == 0) return {};\n\n    // Section I: m(x)\
    \ = \\prod (x - xs[i]) \u3092\u8A08\u7B97\n    vector<F> m(n + 1, 0);\n    m[0]\
    \ = 1;\n    for (int i = 0; i < n; ++i) {\n        for (int j = i; j >= 0; --j)\
    \ {\n            m[j + 1] += m[j];\n            m[j] *= -x[i];\n        }\n  \
    \  }\n\n    // Section II: m \u306E\u5C0E\u95A2\u6570 m' \u3092\u6C42\u3081\u308B\
    .\n    vector<F> m_diff(n);\n    for (int i = 1; i <= n; ++i) {\n        m_diff[i\
    \ - 1] = F(i) * m[i];\n    }\n\n    // Section III: f \u3092\u6C42\u3081\u308B\
    .\n    vector<F> res(n, 0);\n    for (int i = 0; i < n; ++i) {\n        // Evaluate\
    \ m'(x[i]) using Horner's method\n        F val_diff = 0;\n        for (int j\
    \ = n - 1; j >= 0; --j) {\n            val_diff = val_diff * x[i] + m_diff[j];\n\
    \        }\n\n        F weight = y[i] / val_diff;\n\n        // Compute Q_i(x)\
    \ = m(x) / (x - x[i]) and add weight * Q_i(x) to res\n        F q = m[n];\n  \
    \      for (int j = n - 1; j >= 0; --j) {\n            res[j] += weight * q;\n\
    \            q = m[j] + x[i] * q;\n        }\n    }\n    return res;\n}\n\n/**\n\
    \ * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\u305F\
    \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u306E\u6C7A\u5B9A (O(N^2))\n * @details points[i]\
    \ = (x_i, y_i) \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\
    \ P(x) = \\sum res[i] * x^i \u3092\u6C42\u3081\u308B\u3002\n * @tparam F \u4F53\
    \u3092\u8868\u3059\u578B\n * @param points \u70B9 (x, y) \u306E\u30EA\u30B9\u30C8\
    \n * @return vector<F> \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u30EA\u30B9\u30C8\
    \ res (res[i] \u306F x^i \u306E\u4FC2\u6570)\n */\ntemplate<typename F>\nvector<F>\
    \ Lagrange_Interpolation_Polynomial(const vector<pair<F, F>> &points) {\n    auto\
    \ x = enumerable::collect(points, [](const auto &p) { return p.first; });\n  \
    \  auto y = enumerable::collect(points, [](const auto &p) { return p.second; });\n\
    \    return Lagrange_Interpolation_Polynomial(x, y);\n}\n\n/**\n * @brief \u7B49\
    \u5DEE\u6570\u5217\u4E0A\u306E\u70B9\u306B\u304A\u3051\u308B\u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593 (O(N))\n * @details \u591A\u9805\u5F0F P(a*i +\
    \ b) = y[i] (0 <= i < |y|) \u3092\u6E80\u305F\u3059 P(s) \u3092\u6C42\u3081\u308B\
    \u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B (ModInt \u7B49)\n * @param\
    \ a \u7B49\u5DEE\u6570\u5217\u306E\u516C\u5DEE\n * @param b \u7B49\u5DEE\u6570\
    \u5217\u306E\u521D\u9805\n * @param y \u5404\u70B9\u306B\u304A\u3051\u308B\u591A\
    \u9805\u5F0F\u306E\u5024\u306E\u30EA\u30B9\u30C8\n * @param s \u8A55\u4FA1\u70B9\
    \n * @return F P(s) \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point_Arithmetic(const\
    \ F a, const F b, const vector<F> &y, const F s) {\n    int n = (int)y.size();\n\
    \    if (n == 0) return F(0);\n    if (n == 1) return y[0];\n    int d = n - 1;\n\
    \n    Combination_Calculator<F> calc(d + 1);\n\n    // Precompute s - (a*i + b)\n\
    \    vector<F> diffs(n);\n    F cur_x = b;\n    for (int i = 0; i < n; ++i) {\n\
    \        diffs[i] = s - cur_x;\n        cur_x += a;\n    }\n\n    vector<F> prefix(n),\
    \ suffix(n);\n    prefix[0] = diffs[0];\n    for (int i = 1; i < n; ++i) prefix[i]\
    \ = prefix[i - 1] * diffs[i];\n    suffix[d] = diffs[d];\n    for (int i = d -\
    \ 1; i >= 0; --i) suffix[i] = suffix[i + 1] * diffs[i];\n\n    // coef = (-a)^{-d}\n\
    \    F coef = (a == F(1)) ? ((d & 1) ? F(-1) : F(1)) : pow(-a, -d);\n\n    F t\
    \ = 0;\n    for (int i = 0; i < n; ++i) {\n        F pre = (i == 0) ? 1 : prefix[i\
    \ - 1];\n        F suf = (i == d) ? 1 : suffix[i + 1];\n\n        F alpha = pre\
    \ * suf * calc.fact_inv(i) * calc.fact_inv(d - i);\n        if (is_odd(i)) alpha\
    \ = -alpha;\n\n        t += y[i] * alpha;\n    }\n\n    return coef * t;\n}\n\n\
    /**\n * @brief \u9023\u7D9A\u3059\u308B\u6574\u6570\u70B9\u306B\u304A\u3051\u308B\
    \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (O(N))\n * @details \u591A\u9805\
    \u5F0F P(i) = y[i] (0 <= i < |y|) \u3092\u6E80\u305F\u3059 P(s) \u3092\u6C42\u3081\
    \u308B\u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B (ModInt \u7B49)\n *\
    \ @param y \u5404\u70B9\u306B\u304A\u3051\u308B\u591A\u9805\u5F0F\u306E\u5024\u306E\
    \u30EA\u30B9\u30C8 (x = 0, 1, ..., |y|-1)\n * @param s \u8A55\u4FA1\u70B9\n *\
    \ @return F P(s) \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point_Arithmetic(const\
    \ vector<F> &y, const F s) {\n    return Lagrange_Interpolation_Point_Arithmetic<F>(1,\
    \ 0, y, s);\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../template/enumerable.hpp\"\
    \n#include \"../Counting/Combination_Calculator.hpp\"\n\n/**\n * @brief \u30E9\
    \u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\u305F\u8A55\u4FA1\
    \u70B9\u306E\u5024\u306E\u8A08\u7B97 (O(N^2))\n * @details \u4E0E\u3048\u3089\u308C\
    \u305F n \u500B\u306E\u70B9 (x[i], y[i]) \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\
    \u306E\u591A\u9805\u5F0F P \u306B\u5BFE\u3057\u3001P(X) \u3092\u6C42\u3081\u308B\
    \u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B (ModInt \u7B49)\n * @param\
    \ x \u70B9\u306E x \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8 (\u3059\u3079\u3066\u7570\
    \u306A\u308B\u5FC5\u8981\u304C\u3042\u308B)\n * @param y \u70B9\u306E y \u5EA7\
    \u6A19\u306E\u30EA\u30B9\u30C8\n * @param X \u8A55\u4FA1\u70B9\n * @return F P(X)\
    \ \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point(const\
    \ vector<F> &x, const vector<F> &y, F X) {\n    assert(x.size() == y.size());\n\
    \    int n = (int)x.size();\n\n    // \u5206\u5B50\u306E\u7D2F\u7A4D\u7A4D\u3092\
    \u524D\u8A08\u7B97 O(N)\n    vector<F> pre(n + 1, F(1)), suf(n + 1, F(1));\n \
    \   for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] * (X - x[i]);\n    for (int\
    \ i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * (X - x[i]);\n\n    F Y = F(0);\n\
    \    for (int i = 0; i < n; ++i) {\n        // \u5206\u6BCD\u306E\u7A4D\u3092\u8A08\
    \u7B97\n        F den = F(1);\n        for (int j = 0; j < n; ++j) {\n       \
    \     if (i == j) continue;\n\n            den *= (x[i] - x[j]);\n        }\n\n\
    \        Y += y[i] * pre[i] * suf[i + 1] / den;\n    }\n\n    return Y;\n}\n\n\
    /**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\
    \u305F\u8A55\u4FA1\u70B9\u306E\u5024\u306E\u8A08\u7B97 (O(N^2))\n * @details points[i]\
    \ = (x_i, y_i) \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\
    \ P \u306B\u5BFE\u3057\u3001P(X) \u3092\u6C42\u3081\u308B\u3002\n * @tparam F\
    \ \u4F53\u3092\u8868\u3059\u578B\n * @param points \u70B9 (x, y) \u306E\u30EA\u30B9\
    \u30C8\n * @param X \u8A55\u4FA1\u70B9\n * @return F P(X) \u306E\u5024\n */\n\
    template<typename F>\nF Lagrange_Interpolation_Point(const vector<pair<F, F>>\
    \ &points, F X) {\n    auto x = enumerable::collect(points, [](const auto &p)\
    \ { return p.first; });\n    auto y = enumerable::collect(points, [](const auto\
    \ &p) { return p.second; });\n    return Lagrange_Interpolation_Point(x, y, X);\n\
    }\n\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\
    \u3044\u305F\u591A\u9805\u5F0F\u306E\u4FC2\u6570\u306E\u6C7A\u5B9A (O(N^2))\n\
    \ * @details \u4E0E\u3048\u3089\u308C\u305F n \u500B\u306E\u70B9 (x[i], y[i])\
    \ \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F P(x) = \\\
    sum res[i] * x^i \u3092\u6C42\u3081\u308B\u3002\n * @tparam F \u4F53\u3092\u8868\
    \u3059\u578B\n * @param x \u70B9\u306E x \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\
    \ (\u3059\u3079\u3066\u7570\u306A\u308B\u5FC5\u8981\u304C\u3042\u308B)\n * @param\
    \ y \u70B9\u306E y \u5EA7\u6A19\u306E\u30EA\u30B9\u30C8\n * @return vector<F>\
    \ \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u30EA\u30B9\u30C8 res (res[i] \u306F x^i\
    \ \u306E\u4FC2\u6570)\n */\ntemplate<typename F>\nvector<F> Lagrange_Interpolation_Polynomial(const\
    \ vector<F> &x, const vector<F> &y) {\n    assert(x.size() == y.size());\n   \
    \ int n = (int)x.size();\n    if (n == 0) return {};\n\n    // Section I: m(x)\
    \ = \\prod (x - xs[i]) \u3092\u8A08\u7B97\n    vector<F> m(n + 1, 0);\n    m[0]\
    \ = 1;\n    for (int i = 0; i < n; ++i) {\n        for (int j = i; j >= 0; --j)\
    \ {\n            m[j + 1] += m[j];\n            m[j] *= -x[i];\n        }\n  \
    \  }\n\n    // Section II: m \u306E\u5C0E\u95A2\u6570 m' \u3092\u6C42\u3081\u308B\
    .\n    vector<F> m_diff(n);\n    for (int i = 1; i <= n; ++i) {\n        m_diff[i\
    \ - 1] = F(i) * m[i];\n    }\n\n    // Section III: f \u3092\u6C42\u3081\u308B\
    .\n    vector<F> res(n, 0);\n    for (int i = 0; i < n; ++i) {\n        // Evaluate\
    \ m'(x[i]) using Horner's method\n        F val_diff = 0;\n        for (int j\
    \ = n - 1; j >= 0; --j) {\n            val_diff = val_diff * x[i] + m_diff[j];\n\
    \        }\n\n        F weight = y[i] / val_diff;\n\n        // Compute Q_i(x)\
    \ = m(x) / (x - x[i]) and add weight * Q_i(x) to res\n        F q = m[n];\n  \
    \      for (int j = n - 1; j >= 0; --j) {\n            res[j] += weight * q;\n\
    \            q = m[j] + x[i] * q;\n        }\n    }\n    return res;\n}\n\n/**\n\
    \ * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u3092\u7528\u3044\u305F\
    \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u306E\u6C7A\u5B9A (O(N^2))\n * @details points[i]\
    \ = (x_i, y_i) \u3092\u901A\u308B n-1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F\
    \ P(x) = \\sum res[i] * x^i \u3092\u6C42\u3081\u308B\u3002\n * @tparam F \u4F53\
    \u3092\u8868\u3059\u578B\n * @param points \u70B9 (x, y) \u306E\u30EA\u30B9\u30C8\
    \n * @return vector<F> \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u30EA\u30B9\u30C8\
    \ res (res[i] \u306F x^i \u306E\u4FC2\u6570)\n */\ntemplate<typename F>\nvector<F>\
    \ Lagrange_Interpolation_Polynomial(const vector<pair<F, F>> &points) {\n    auto\
    \ x = enumerable::collect(points, [](const auto &p) { return p.first; });\n  \
    \  auto y = enumerable::collect(points, [](const auto &p) { return p.second; });\n\
    \    return Lagrange_Interpolation_Polynomial(x, y);\n}\n\n/**\n * @brief \u7B49\
    \u5DEE\u6570\u5217\u4E0A\u306E\u70B9\u306B\u304A\u3051\u308B\u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593 (O(N))\n * @details \u591A\u9805\u5F0F P(a*i +\
    \ b) = y[i] (0 <= i < |y|) \u3092\u6E80\u305F\u3059 P(s) \u3092\u6C42\u3081\u308B\
    \u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B (ModInt \u7B49)\n * @param\
    \ a \u7B49\u5DEE\u6570\u5217\u306E\u516C\u5DEE\n * @param b \u7B49\u5DEE\u6570\
    \u5217\u306E\u521D\u9805\n * @param y \u5404\u70B9\u306B\u304A\u3051\u308B\u591A\
    \u9805\u5F0F\u306E\u5024\u306E\u30EA\u30B9\u30C8\n * @param s \u8A55\u4FA1\u70B9\
    \n * @return F P(s) \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point_Arithmetic(const\
    \ F a, const F b, const vector<F> &y, const F s) {\n    int n = (int)y.size();\n\
    \    if (n == 0) return F(0);\n    if (n == 1) return y[0];\n    int d = n - 1;\n\
    \n    Combination_Calculator<F> calc(d + 1);\n\n    // Precompute s - (a*i + b)\n\
    \    vector<F> diffs(n);\n    F cur_x = b;\n    for (int i = 0; i < n; ++i) {\n\
    \        diffs[i] = s - cur_x;\n        cur_x += a;\n    }\n\n    vector<F> prefix(n),\
    \ suffix(n);\n    prefix[0] = diffs[0];\n    for (int i = 1; i < n; ++i) prefix[i]\
    \ = prefix[i - 1] * diffs[i];\n    suffix[d] = diffs[d];\n    for (int i = d -\
    \ 1; i >= 0; --i) suffix[i] = suffix[i + 1] * diffs[i];\n\n    // coef = (-a)^{-d}\n\
    \    F coef = (a == F(1)) ? ((d & 1) ? F(-1) : F(1)) : pow(-a, -d);\n\n    F t\
    \ = 0;\n    for (int i = 0; i < n; ++i) {\n        F pre = (i == 0) ? 1 : prefix[i\
    \ - 1];\n        F suf = (i == d) ? 1 : suffix[i + 1];\n\n        F alpha = pre\
    \ * suf * calc.fact_inv(i) * calc.fact_inv(d - i);\n        if (is_odd(i)) alpha\
    \ = -alpha;\n\n        t += y[i] * alpha;\n    }\n\n    return coef * t;\n}\n\n\
    /**\n * @brief \u9023\u7D9A\u3059\u308B\u6574\u6570\u70B9\u306B\u304A\u3051\u308B\
    \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (O(N))\n * @details \u591A\u9805\
    \u5F0F P(i) = y[i] (0 <= i < |y|) \u3092\u6E80\u305F\u3059 P(s) \u3092\u6C42\u3081\
    \u308B\u3002\n * @tparam F \u4F53\u3092\u8868\u3059\u578B (ModInt \u7B49)\n *\
    \ @param y \u5404\u70B9\u306B\u304A\u3051\u308B\u591A\u9805\u5F0F\u306E\u5024\u306E\
    \u30EA\u30B9\u30C8 (x = 0, 1, ..., |y|-1)\n * @param s \u8A55\u4FA1\u70B9\n *\
    \ @return F P(s) \u306E\u5024\n */\ntemplate<typename F>\nF Lagrange_Interpolation_Point_Arithmetic(const\
    \ vector<F> &y, const F s) {\n    return Lagrange_Interpolation_Point_Arithmetic<F>(1,\
    \ 0, y, s);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - template/enumerable.hpp
  - Counting/Combination_Calculator.hpp
  isVerificationFile: false
  path: Math/Lagrange_Interpolation.hpp
  requiredBy: []
  timestamp: '2026-04-18 01:08:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Lagrange_Interpolation.hpp
layout: document
title: "Lagrange \u88DC\u9593"
---

## Outline

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $(d+1)$ 個の条件

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ に関する値を求める.

## Theory

### Lagrange 多項式を使った, 多項式の決定

$F$ を体とする.

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $x_0, x_1, \dots, x_d$ は互いに異なるとする.
このとき,

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ はただ $1$ つ存在する. 証明は Vandermonde 行列が正則であることから従う.

---

$i = 0, 1, \dots, d$ に対して, Lagrange 多項式 $\ell_i(x)$ を

$$ \ell_i(x) := \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{x - x_j}{x_i - x_j} $$

で定める. このとき, $i, j \in \\{0, 1, \dots, d \\}$ に対して,

$$ \ell_i(x_j) = \delta_{i, j} $$

が成り立つ.

このとき, 多項式 $g$ を

$$ g(x) := \sum_{i=0}^d y_i \ell_i(x) $$

で定めると,

$$ g(x_j) = \sum_{i=0}^d y_i \ell_i(x_j) = \sum_{i=0}^d y_i \delta_{i,j} = y_j $$

である. ただし, $\delta_{i,j}$ は Kronecker Delta.

よって, $f, g$ は相異なる $(d+1)$ 個の点で一致する $d$ 次以下の多項式であるため, $f = g$ が成り立つ. 故に,

$$ f(x) = \sum_{i=0}^d y_i \ell_i(x) $$

である.

### 特定の一点における値

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $(d+1)$ 個の条件

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ に関する $f(s)$ の値を求める.

各 $i$ に対して, $\ell_i(s)$ は $O(d)$ 時間で求められる. 故に,

$$ f(s) = \sum_{i=0}^d y_i \ell_i(s) $$

であるため, $f(s)$ は $O(d^2)$ 時間で求められる.

### 多項式の各係数を求める

多項式 $m(x)$ を

$$m(x) := \prod_{i=0}^d (x - x_i)$$

と置く. この $m(x)$ は $O(d^2)$ 時間で求めることができる. このとき,

$$\ell_i(x) = \dfrac{1}{m'(x_i)} \cdot \dfrac{m(x)}{x - x_i}$$

である.

ここで $m'(x_i) = \prod_{j \neq i} (x_i - x_j)$ であり, これは $m(x)$ を微分した多項式 $m'(x)$ に $x = x_i$ を代入することで得られる.

各 $i$ について, 微分係数 $m'(x_i)$ の計算に $O(d)$ 時間, 多項式の除算（組立除法）に $O(d)$ かかるため, 各 $\ell_i(x)$ は $O(d)$ 時間で求められる.

これを $(d+1)$ 個足し合わせるため, 全体の計算量は $O(d^2)$ 時間である。

故に, 各 $\ell_i(x)$ は $O(d)$ 時間で求められ, これを $(d+1)$ 個合計するため, 合計の時間計算量は $O(d^2)$ 時間である.

## 標本点が等差数列のとき

もし, 標本点 $x_i$ が等差数列 $x_i = ai + b$ を満たしているならば, 特定の点 $f(s)$ を求める計算量は $O(d^2)$ 時間から, $O(d)$ 時間に大きく落ちる.

Lagrange 多項式の値 $\ell_i(s)$ について,

$$\begin{align*}
    \ell_i(s)
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - x_j}{x_i - x_j} \\
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{(ai+b) - (aj+b)} \\
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{a(i-j)} \\
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{i-j}
\end{align*}$$

である. ここで,

$$ \varepsilon_j := s - (a j + b) $$

とおくと,


$$\begin{align*}
    \ell_i(s)
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{i-j} \\
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{\varepsilon_j}{i-j} \\
    &= \dfrac{1}{a^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i \cdot (i-1) \dots 1 \cdot (-1) \cdot (-2) \dots (-(i-d))} \\
    &= \dfrac{1}{a^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i! \cdot (d-i)! \cdot (-1)^{d-i}} \\
    &= \dfrac{(-1)^i}{(-a)^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i! \cdot (d-i)!}
\end{align*}$$

である.

$$ \textrm{prefix}_i := \varepsilon_0 \varepsilon_1 \dots \varepsilon_i, \quad \textrm{suffix}_i := \varepsilon_i \varepsilon_{i+1} \dots \varepsilon_d $$

とおくと,

$$ \ell_i(s) = \dfrac{(-1)^i}{(-a)^d} \cdot \dfrac{\textrm{prefix}_{i-1} \cdot \textrm{suffix}_{i+1} }{i! \cdot (d-i)!} $$

である.

$\textrm{prefix}_i, \textrm{suffix}_i$ はそれぞれ順番に注意して累積的に計算することにより, $i=0,1,\dots,d$ を合計で $O(d)$ 時間で求められる.

階乗の逆元も, $(0!)^{-1}, (1!)^{-1}, \dots, (d!)^{-1}$ を合計で $O(d)$ 時間で求められる.

以上から, 前計算 $O(d)$ 時間の元で $0 \leq i \leq d$ における $\ell_i(s)$ をで各 $O(1)$ 時間で求められる.

故に, $f(s)$ を $O(d)$ 時間で求められる.

## History 

|日付|内容|
|:---:|:---:|
|2026/04/18| Lagrange 補間に関するメソッドの実装 |
