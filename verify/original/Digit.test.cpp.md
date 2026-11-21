---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Digit.hpp
    title: "\u6574\u6570\u306E\u6841"
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
  bundledCode: "#line 1 \"verify/original/Digit.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 2 \"template/template.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/template/template.hpp\n\
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
    \    }\n};\n#line 2 \"Integer/Digit.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Digit.hpp\n\
    \n#line 6 \"Integer/Digit.hpp\"\n\n/// @brief \u4E0D\u6B63\u306A\u5E95\u304C\u6307\
    \u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\u30B9\u30ED\u30FC\u3055\u308C\u308B\
    \u30AB\u30B9\u30BF\u30E0\u4F8B\u5916\nclass BaseException : public runtime_error\
    \ {\n    private:\n    ll error_base;\n\n    public:\n    /**\n     * @brief BaseException\u3092\
    \u69CB\u7BC9\u3057\u307E\u3059\u3002\n     * @param base \u4E0D\u6B63\u306A\u5E95\
    \u306E\u5024\n     */\n    BaseException(ll base) :\n        runtime_error(\"\u6307\
    \u5B9A\u3057\u305F\u5E95 \" + to_string(base) + \" \u306F\u4E0D\u6B63\u306A\u5E95\
    \u3067\u3059.\"),\n        error_base(base) {}\n};\n\n/// @brief \u6574\u6570\
    \ N \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306E\u8868\u73FE\u3092\
    \u6C42\u3081\u308B.\n/// @param N \u975E\u8CA0\u6574\u6570 (N >= 0)\n/// @param\
    \ b \u5E95 (b >= 2). Default to 10.\n/// @param l \u9577\u3055\u304C l \u306B\u306A\
    \u308B\u3088\u3046\u306B\u5DE6\u5074\u306B 0 \u3092\u57CB\u3081\u305F\u308A, \u53F3\
    \u304B\u3089 l \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B. -1 \u306F\u7121\u6307\
    \u5B9A.\n/// @return vector<ll> \u6570\u306E\u30EA\u30B9\u30C8 (\u6700\u4E0A\u4F4D\
    \u6841\u304B\u3089\u6700\u4E0B\u4F4D\u6841\u306E\u9806).\nvector<ll> Integer_Digits(ll\
    \ N, const ll b = 10, const int l = -1) {\n    if (b < 2) { throw BaseException(b);\
    \ }\n\n    vector<ll> digits;\n\n    if (l == -1) {\n        if (N == 0) {\n \
    \           digits.push_back(0);\n            return digits;\n        }\n\n  \
    \      while (N > 0) {\n            digits.push_back(N % b);\n            N /=\
    \ b;\n        }\n    } else {\n        for (int i = 0; i < l; ++i) {\n       \
    \     digits.push_back(N % b);\n            N /= b;\n        }\n    }\n\n    reverse(digits.begin(),\
    \ digits.end());\n    return digits;\n}\n\n/// @brief \u6574\u6570 N \u306E\u5E95\
    \u3092 b \u3068\u3057\u305F\u5834\u5408\u306E\u6841\u6570\u3092\u6C42\u3081\u308B\
    \ (0 \u306F 0 \u6841\u3068\u3059\u308B).\n/// @param N \u975E\u8CA0\u6574\u6570\
    \ (N >= 0)\n/// @param b \u5E95 (b >= 2). Default to 10.\nint Integer_Length(ll\
    \ N, const ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    int\
    \ length = 0;\n    for (; N > 0; length++) { N /= b; }\n\n    return length;\n\
    }\n\n/// @brief \u6574\u6570 N \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\
    \u306E\u6841\u548C\u3092\u6C42\u3081\u308B.\n/// @param N \u975E\u8CA0\u6574\u6570\
    \ (N >= 0)\n/// @param b \u5E95 (b >= 2). \u30C7\u30D5\u30A9\u30EB\u30C8\u306F\
    \ 10.\nll Digit_Sum(ll N, const ll b = 10) {\n    if (b < 2) { throw BaseException(b);\
    \ }\n\n    ll sum = 0;\n\n    while (N > 0) {\n        sum += N % b;\n       \
    \ N /= b;\n    }\n    return sum;\n}\n\n/// @brief \u6574\u6570 N \u306E\u5E95\
    \u3092 b \u3068\u3057\u305F\u5834\u5408\u306B\u304A\u3051\u308B\u5404\u6570\u306E\
    \u51FA\u73FE\u56DE\u6570\u3092\u6C42\u3081\u308B.\n/// @param N \u975E\u8CA0\u6574\
    \u6570 (N >= 0)\n/// @param b \u5E95 (b >= 2). Default to 10.\n/// @return \u9577\
    \u3055 b \u306E\u914D\u5217. \u7B2C k \u8981\u7D20\u306F k \u306E\u51FA\u73FE\u56DE\
    \u6570.\nvector<ll> Digit_Count(ll N, const ll b = 10) {\n    if (b < 2) { throw\
    \ BaseException(b); }\n\n    vector<ll> count(b, 0);\n    for (ll d : Integer_Digits(N,\
    \ b)) {\n        count[d]++;\n    }\n    return count;\n}\n\n/// @brief \u5E95\
    \u3092 b \u3068\u3057\u305F\u5834\u5408\u306B digits \u304C\u306A\u3059\u6574\u6570\
    \u3092\u8FD4\u3059 (Integer_Digits \u306E\u9006\u95A2\u6570)\n/// @param digits\
    \ \u6570\u306E\u30EA\u30B9\u30C8 (\u6700\u4E0A\u4F4D\u6841\u304B\u3089\u6700\u4E0B\
    \u4F4D\u6841\u306E\u9806)\n/// @param b \u5E95 (b >= 2). Default to 10.\n/// @return\
    \ \u6574\u6570 (\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306E\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u6CE8\u610F)\nll From_Digits(const vector<ll> &digits,\
    \ const ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    ll res\
    \ = 0;\n    for (ll x : digits) {  res = b * res + x; }\n    return res;\n}\n\
    #line 5 \"verify/original/Digit.test.cpp\"\n\n// b^i \u3092\u8A08\u7B97\u3059\u308B\
    \ (\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7BC4\u56F2\u3067\
    \u4F7F\u3046)\nll naive_pow(ll b, int i) {\n    ll res = 1;\n    for (int k =\
    \ 0; k < i; k++) { res *= b; }\n    return res;\n}\n\n// b \u9032\u8868\u8A18\u306E\
    \u6841\u6570\u306E\u611A\u76F4\u8A08\u7B97: b^d > n \u3068\u306A\u308B\u6700\u5C0F\
    \u306E d\nint naive_length(ll n, ll b) {\n    int d = 0;\n    for (__int128 p\
    \ = 1; p <= n; p *= b) { d++; }\n    return d;\n}\n\n// digits \u304C n \u306E\
    \ b \u9032\u8868\u8A18\u306E\u6761\u4EF6 (\u5B9A\u7406 1) \u3092\u6E80\u305F\u3059\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\nbool is_representation(const vector<ll>\
    \ &digits, ll n, ll b) {\n    if (n == 0) { return digits == vector<ll>{0}; }\n\
    \    if (digits.empty() || digits.front() == 0) { return false; }\n\n    __int128\
    \ value = 0;\n    for (ll x : digits) {\n        if (x < 0 || x >= b) { return\
    \ false; }\n        value = value * b + x;\n    }\n    return value == n;\n}\n\
    \nvoid verify() {\n    // \u5177\u4F53\u7684\u306A\u5024\n    {\n        assert((Integer_Digits(12345)\
    \ == vector<ll>{1, 2, 3, 4, 5}));\n        assert((Integer_Digits(10, 2) == vector<ll>{1,\
    \ 0, 1, 0}));\n        assert((Integer_Digits(255, 16) == vector<ll>{15, 15}));\n\
    \        assert((Integer_Digits(0) == vector<ll>{0}));\n\n        assert(Integer_Length(0)\
    \ == 0);\n        assert(Integer_Length(9) == 1);\n        assert(Integer_Length(999)\
    \ == 3);\n        assert(Integer_Length(1000) == 4);\n        assert(Integer_Length(1024,\
    \ 2) == 11);\n\n        assert(Digit_Sum(0) == 0);\n        assert(Digit_Sum(12345)\
    \ == 15);\n        assert(Digit_Sum(255, 2) == 8);\n\n        assert((Digit_Count(1122333)\
    \ == vector<ll>{0, 2, 2, 3, 0, 0, 0, 0, 0, 0}));\n        assert((Digit_Count(0)\
    \ == vector<ll>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}));\n        assert((Digit_Count(10,\
    \ 2) == vector<ll>{2, 2}));\n\n        assert(From_Digits({1, 2, 3, 4, 5}) ==\
    \ 12345);\n        assert(From_Digits({1, 0, 1, 0}, 2) == 10);\n        assert(From_Digits({})\
    \ == 0);\n        assert(From_Digits({0, 0, 7}) == 7);\n    }\n\n    // \u9577\
    \u3055 l \u306E\u6307\u5B9A\n    {\n        assert((Integer_Digits(5, 2, 6) ==\
    \ vector<ll>{0, 0, 0, 1, 0, 1}));\n        assert((Integer_Digits(12345, 10, 3)\
    \ == vector<ll>{3, 4, 5}));\n        assert((Integer_Digits(12345, 10, 5) == vector<ll>{1,\
    \ 2, 3, 4, 5}));\n        assert((Integer_Digits(0, 10, 3) == vector<ll>{0, 0,\
    \ 0}));\n        assert(Integer_Digits(12345, 10, 0).empty());\n    }\n\n    //\
    \ \u4E0D\u6B63\u306A\u5E95\u3067\u306F BaseException \u304C\u9001\u51FA\u3055\u308C\
    \u308B\n    {\n        for (ll b : {1LL, 0LL, -3LL}) {\n            bool thrown;\n\
    \n            thrown = false;\n            try { Integer_Digits(10, b); } catch\
    \ (const BaseException &) { thrown = true; }\n            assert(thrown);\n\n\
    \            thrown = false;\n            try { Integer_Length(10, b); } catch\
    \ (const BaseException &) { thrown = true; }\n            assert(thrown);\n\n\
    \            thrown = false;\n            try { Digit_Sum(10, b); } catch (const\
    \ BaseException &) { thrown = true; }\n            assert(thrown);\n\n       \
    \     thrown = false;\n            try { Digit_Count(10, b); } catch (const BaseException\
    \ &) { thrown = true; }\n            assert(thrown);\n\n            thrown = false;\n\
    \            try { From_Digits({1, 0}, b); } catch (const BaseException &) { thrown\
    \ = true; }\n            assert(thrown);\n        }\n    }\n\n    // \u5C0F\u3055\
    \u3044 n, b \u3067\u306E\u7DCF\u5F53\u305F\u308A (\u5B9A\u7FA9\u3068\u306E\u7A81\
    \u304D\u5408\u308F\u305B)\n    {\n        for (ll b = 2; b <= 12; b++) {\n   \
    \         for (ll n = 0; n <= 3000; n++) {\n                vector<ll> digits\
    \ = Integer_Digits(n, b);\n                assert(is_representation(digits, n,\
    \ b));\n                assert(From_Digits(digits, b) == n);\n\n             \
    \   assert(Integer_Length(n, b) == naive_length(n, b));\n\n                ll\
    \ sum = 0;\n                vector<ll> count(b, 0);\n                for (ll x\
    \ : digits) { sum += x; count[x]++; }\n                if (n == 0) { count[0]\
    \ = 1; }\n                assert(Digit_Sum(n, b) == sum);\n                assert(Digit_Count(n,\
    \ b) == count);\n\n                // l \u3092\u6307\u5B9A\u3057\u305F\u3068\u304D\
    \u306F, \u4E0B\u304B\u3089 l \u6841 ((n / b^i) mod b) \u3092\u4E26\u3079\u305F\
    \u3082\u306E\u306B\u306A\u308B\n                for (int l = 0; l <= 8; l++) {\n\
    \                    vector<ll> expected(l);\n                    for (int i =\
    \ 0; i < l; i++) {\n                        __int128 p = 1;\n                \
    \        for (int k = 0; k < i; k++) { p *= b; }\n                        expected[l\
    \ - 1 - i] = (ll)((n / p) % b);\n                    }\n                    assert(Integer_Digits(n,\
    \ b, l) == expected);\n                }\n            }\n        }\n    }\n\n\
    \    // \u547D\u984C 4 (n \u2261 S_b(n) mod (b-1)) \u3068\u547D\u984C 7 (\u6570\
    \u5B57\u6839\u306E\u516C\u5F0F)\n    {\n        for (ll b = 2; b <= 20; b++) {\n\
    \            for (ll n = 0; n <= 5000; n++) {\n                assert((n - Digit_Sum(n,\
    \ b)) % (b - 1) == 0);\n\n                ll r = n;\n                while (r\
    \ >= b) { r = Digit_Sum(r, b); }\n\n                ll expected;\n           \
    \     if (n == 0) { expected = 0; }\n                else if (n % (b - 1) != 0)\
    \ { expected = n % (b - 1); }\n                else { expected = b - 1; }\n  \
    \              assert(r == expected);\n            }\n        }\n    }\n\n   \
    \ // \u5927\u304D\u306A\u5024\n    {\n        const ll M = LLONG_MAX;\n      \
    \  assert(Integer_Length(M) == 19);\n        assert(Integer_Length(M, 2) == 63);\n\
    \        assert((Integer_Digits(M, 2) == vector<ll>(63, 1)));\n        assert(Digit_Sum(M,\
    \ 2) == 63);\n\n        for (ll b : {2LL, 3LL, 7LL, 10LL, 16LL, 1000000007LL,\
    \ 1000000000000000000LL, M}) {\n            vector<ll> digits = Integer_Digits(M,\
    \ b);\n            assert(is_representation(digits, M, b));\n            assert(From_Digits(digits,\
    \ b) == M);\n            assert(Integer_Length(M, b) == naive_length(M, b));\n\
    \        }\n\n        // b > N \u306E\u3068\u304D\u306F 1 \u6841\n        assert((Integer_Digits(12345,\
    \ M) == vector<ll>{12345}));\n        assert(Integer_Length(12345, M) == 1);\n\
    \        assert(naive_pow(10, 18) == 1000000000000000000LL);\n        assert((Integer_Digits(naive_pow(10,\
    \ 18), naive_pow(10, 9)) == vector<ll>{1, 0, 0}));\n    }\n}\n\nint main() {\n\
    \    verify();\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../Integer/Digit.hpp\"\
    \n\n// b^i \u3092\u8A08\u7B97\u3059\u308B (\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u7BC4\u56F2\u3067\u4F7F\u3046)\nll naive_pow(ll b, int\
    \ i) {\n    ll res = 1;\n    for (int k = 0; k < i; k++) { res *= b; }\n    return\
    \ res;\n}\n\n// b \u9032\u8868\u8A18\u306E\u6841\u6570\u306E\u611A\u76F4\u8A08\
    \u7B97: b^d > n \u3068\u306A\u308B\u6700\u5C0F\u306E d\nint naive_length(ll n,\
    \ ll b) {\n    int d = 0;\n    for (__int128 p = 1; p <= n; p *= b) { d++; }\n\
    \    return d;\n}\n\n// digits \u304C n \u306E b \u9032\u8868\u8A18\u306E\u6761\
    \u4EF6 (\u5B9A\u7406 1) \u3092\u6E80\u305F\u3059\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\nbool is_representation(const vector<ll> &digits, ll n, ll b) {\n    if\
    \ (n == 0) { return digits == vector<ll>{0}; }\n    if (digits.empty() || digits.front()\
    \ == 0) { return false; }\n\n    __int128 value = 0;\n    for (ll x : digits)\
    \ {\n        if (x < 0 || x >= b) { return false; }\n        value = value * b\
    \ + x;\n    }\n    return value == n;\n}\n\nvoid verify() {\n    // \u5177\u4F53\
    \u7684\u306A\u5024\n    {\n        assert((Integer_Digits(12345) == vector<ll>{1,\
    \ 2, 3, 4, 5}));\n        assert((Integer_Digits(10, 2) == vector<ll>{1, 0, 1,\
    \ 0}));\n        assert((Integer_Digits(255, 16) == vector<ll>{15, 15}));\n  \
    \      assert((Integer_Digits(0) == vector<ll>{0}));\n\n        assert(Integer_Length(0)\
    \ == 0);\n        assert(Integer_Length(9) == 1);\n        assert(Integer_Length(999)\
    \ == 3);\n        assert(Integer_Length(1000) == 4);\n        assert(Integer_Length(1024,\
    \ 2) == 11);\n\n        assert(Digit_Sum(0) == 0);\n        assert(Digit_Sum(12345)\
    \ == 15);\n        assert(Digit_Sum(255, 2) == 8);\n\n        assert((Digit_Count(1122333)\
    \ == vector<ll>{0, 2, 2, 3, 0, 0, 0, 0, 0, 0}));\n        assert((Digit_Count(0)\
    \ == vector<ll>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}));\n        assert((Digit_Count(10,\
    \ 2) == vector<ll>{2, 2}));\n\n        assert(From_Digits({1, 2, 3, 4, 5}) ==\
    \ 12345);\n        assert(From_Digits({1, 0, 1, 0}, 2) == 10);\n        assert(From_Digits({})\
    \ == 0);\n        assert(From_Digits({0, 0, 7}) == 7);\n    }\n\n    // \u9577\
    \u3055 l \u306E\u6307\u5B9A\n    {\n        assert((Integer_Digits(5, 2, 6) ==\
    \ vector<ll>{0, 0, 0, 1, 0, 1}));\n        assert((Integer_Digits(12345, 10, 3)\
    \ == vector<ll>{3, 4, 5}));\n        assert((Integer_Digits(12345, 10, 5) == vector<ll>{1,\
    \ 2, 3, 4, 5}));\n        assert((Integer_Digits(0, 10, 3) == vector<ll>{0, 0,\
    \ 0}));\n        assert(Integer_Digits(12345, 10, 0).empty());\n    }\n\n    //\
    \ \u4E0D\u6B63\u306A\u5E95\u3067\u306F BaseException \u304C\u9001\u51FA\u3055\u308C\
    \u308B\n    {\n        for (ll b : {1LL, 0LL, -3LL}) {\n            bool thrown;\n\
    \n            thrown = false;\n            try { Integer_Digits(10, b); } catch\
    \ (const BaseException &) { thrown = true; }\n            assert(thrown);\n\n\
    \            thrown = false;\n            try { Integer_Length(10, b); } catch\
    \ (const BaseException &) { thrown = true; }\n            assert(thrown);\n\n\
    \            thrown = false;\n            try { Digit_Sum(10, b); } catch (const\
    \ BaseException &) { thrown = true; }\n            assert(thrown);\n\n       \
    \     thrown = false;\n            try { Digit_Count(10, b); } catch (const BaseException\
    \ &) { thrown = true; }\n            assert(thrown);\n\n            thrown = false;\n\
    \            try { From_Digits({1, 0}, b); } catch (const BaseException &) { thrown\
    \ = true; }\n            assert(thrown);\n        }\n    }\n\n    // \u5C0F\u3055\
    \u3044 n, b \u3067\u306E\u7DCF\u5F53\u305F\u308A (\u5B9A\u7FA9\u3068\u306E\u7A81\
    \u304D\u5408\u308F\u305B)\n    {\n        for (ll b = 2; b <= 12; b++) {\n   \
    \         for (ll n = 0; n <= 3000; n++) {\n                vector<ll> digits\
    \ = Integer_Digits(n, b);\n                assert(is_representation(digits, n,\
    \ b));\n                assert(From_Digits(digits, b) == n);\n\n             \
    \   assert(Integer_Length(n, b) == naive_length(n, b));\n\n                ll\
    \ sum = 0;\n                vector<ll> count(b, 0);\n                for (ll x\
    \ : digits) { sum += x; count[x]++; }\n                if (n == 0) { count[0]\
    \ = 1; }\n                assert(Digit_Sum(n, b) == sum);\n                assert(Digit_Count(n,\
    \ b) == count);\n\n                // l \u3092\u6307\u5B9A\u3057\u305F\u3068\u304D\
    \u306F, \u4E0B\u304B\u3089 l \u6841 ((n / b^i) mod b) \u3092\u4E26\u3079\u305F\
    \u3082\u306E\u306B\u306A\u308B\n                for (int l = 0; l <= 8; l++) {\n\
    \                    vector<ll> expected(l);\n                    for (int i =\
    \ 0; i < l; i++) {\n                        __int128 p = 1;\n                \
    \        for (int k = 0; k < i; k++) { p *= b; }\n                        expected[l\
    \ - 1 - i] = (ll)((n / p) % b);\n                    }\n                    assert(Integer_Digits(n,\
    \ b, l) == expected);\n                }\n            }\n        }\n    }\n\n\
    \    // \u547D\u984C 4 (n \u2261 S_b(n) mod (b-1)) \u3068\u547D\u984C 7 (\u6570\
    \u5B57\u6839\u306E\u516C\u5F0F)\n    {\n        for (ll b = 2; b <= 20; b++) {\n\
    \            for (ll n = 0; n <= 5000; n++) {\n                assert((n - Digit_Sum(n,\
    \ b)) % (b - 1) == 0);\n\n                ll r = n;\n                while (r\
    \ >= b) { r = Digit_Sum(r, b); }\n\n                ll expected;\n           \
    \     if (n == 0) { expected = 0; }\n                else if (n % (b - 1) != 0)\
    \ { expected = n % (b - 1); }\n                else { expected = b - 1; }\n  \
    \              assert(r == expected);\n            }\n        }\n    }\n\n   \
    \ // \u5927\u304D\u306A\u5024\n    {\n        const ll M = LLONG_MAX;\n      \
    \  assert(Integer_Length(M) == 19);\n        assert(Integer_Length(M, 2) == 63);\n\
    \        assert((Integer_Digits(M, 2) == vector<ll>(63, 1)));\n        assert(Digit_Sum(M,\
    \ 2) == 63);\n\n        for (ll b : {2LL, 3LL, 7LL, 10LL, 16LL, 1000000007LL,\
    \ 1000000000000000000LL, M}) {\n            vector<ll> digits = Integer_Digits(M,\
    \ b);\n            assert(is_representation(digits, M, b));\n            assert(From_Digits(digits,\
    \ b) == M);\n            assert(Integer_Length(M, b) == naive_length(M, b));\n\
    \        }\n\n        // b > N \u306E\u3068\u304D\u306F 1 \u6841\n        assert((Integer_Digits(12345,\
    \ M) == vector<ll>{12345}));\n        assert(Integer_Length(12345, M) == 1);\n\
    \        assert(naive_pow(10, 18) == 1000000000000000000LL);\n        assert((Integer_Digits(naive_pow(10,\
    \ 18), naive_pow(10, 9)) == vector<ll>{1, 0, 0}));\n    }\n}\n\nint main() {\n\
    \    verify();\n    cout << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Integer/Digit.hpp
  isVerificationFile: true
  path: verify/original/Digit.test.cpp
  requiredBy: []
  timestamp: '2026-11-20 01:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/original/Digit.test.cpp
layout: document
redirect_from:
- /verify/verify/original/Digit.test.cpp
- /verify/verify/original/Digit.test.cpp.html
title: verify/original/Digit.test.cpp
---
