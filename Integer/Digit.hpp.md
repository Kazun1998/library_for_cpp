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
    path: verify/original/Digit.test.cpp
    title: verify/original/Digit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E0D\u6B63\u306A\u5E95\u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\
      \u304D\u306B\u30B9\u30ED\u30FC\u3055\u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\
      \u5916"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Digit.hpp
  bundledCode: "#line 2 \"Integer/Digit.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Digit.hpp\n\
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
    \    }\n};\n#line 6 \"Integer/Digit.hpp\"\n\n/// @brief \u4E0D\u6B63\u306A\u5E95\
    \u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\u30B9\u30ED\u30FC\u3055\
    \u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\u5916\nclass BaseException : public\
    \ runtime_error {\n    private:\n    ll error_base;\n\n    public:\n    /**\n\
    \     * @brief BaseException\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\n     *\
    \ @param base \u4E0D\u6B63\u306A\u5E95\u306E\u5024\n     */\n    BaseException(ll\
    \ base) :\n        runtime_error(\"\u6307\u5B9A\u3057\u305F\u5E95 \" + to_string(base)\
    \ + \" \u306F\u4E0D\u6B63\u306A\u5E95\u3067\u3059.\"),\n        error_base(base)\
    \ {}\n};\n\n/// @brief \u6574\u6570 N \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\
    \u5408\u306E\u8868\u73FE\u3092\u6C42\u3081\u308B.\n/// @param N \u975E\u8CA0\u6574\
    \u6570 (N >= 0)\n/// @param b \u5E95 (b >= 2). Default to 10.\n/// @param l \u9577\
    \u3055\u304C l \u306B\u306A\u308B\u3088\u3046\u306B\u5DE6\u5074\u306B 0 \u3092\
    \u57CB\u3081\u305F\u308A, \u53F3\u304B\u3089 l \u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B. -1 \u306F\u7121\u6307\u5B9A.\n/// @return vector<ll> \u6570\u306E\u30EA\
    \u30B9\u30C8 (\u6700\u4E0A\u4F4D\u6841\u304B\u3089\u6700\u4E0B\u4F4D\u6841\u306E\
    \u9806).\nvector<ll> Integer_Digits(ll N, const ll b = 10, const int l = -1) {\n\
    \    if (b < 2) { throw BaseException(b); }\n\n    vector<ll> digits;\n\n    if\
    \ (l == -1) {\n        if (N == 0) {\n            digits.push_back(0);\n     \
    \       return digits;\n        }\n\n        while (N > 0) {\n            digits.push_back(N\
    \ % b);\n            N /= b;\n        }\n    } else {\n        for (int i = 0;\
    \ i < l; ++i) {\n            digits.push_back(N % b);\n            N /= b;\n \
    \       }\n    }\n\n    reverse(digits.begin(), digits.end());\n    return digits;\n\
    }\n\n/// @brief \u6574\u6570 N \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\
    \u306E\u6841\u6570\u3092\u6C42\u3081\u308B (0 \u306F 0 \u6841\u3068\u3059\u308B\
    ).\n/// @param N \u975E\u8CA0\u6574\u6570 (N >= 0)\n/// @param b \u5E95 (b >=\
    \ 2). Default to 10.\nint Integer_Length(ll N, const ll b = 10) {\n    if (b <\
    \ 2) { throw BaseException(b); }\n\n    int length = 0;\n    for (; N > 0; length++)\
    \ { N /= b; }\n\n    return length;\n}\n\n/// @brief \u6574\u6570 N \u306E\u5E95\
    \u3092 b \u3068\u3057\u305F\u5834\u5408\u306E\u6841\u548C\u3092\u6C42\u3081\u308B\
    .\n/// @param N \u975E\u8CA0\u6574\u6570 (N >= 0)\n/// @param b \u5E95 (b >= 2).\
    \ \u30C7\u30D5\u30A9\u30EB\u30C8\u306F 10.\nll Digit_Sum(ll N, const ll b = 10)\
    \ {\n    if (b < 2) { throw BaseException(b); }\n\n    ll sum = 0;\n\n    while\
    \ (N > 0) {\n        sum += N % b;\n        N /= b;\n    }\n    return sum;\n\
    }\n\n/// @brief \u6574\u6570 N \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\
    \u306B\u304A\u3051\u308B\u5404\u6570\u306E\u51FA\u73FE\u56DE\u6570\u3092\u6C42\
    \u3081\u308B.\n/// @param N \u975E\u8CA0\u6574\u6570 (N >= 0)\n/// @param b \u5E95\
    \ (b >= 2). Default to 10.\n/// @return \u9577\u3055 b \u306E\u914D\u5217. \u7B2C\
    \ k \u8981\u7D20\u306F k \u306E\u51FA\u73FE\u56DE\u6570.\nvector<ll> Digit_Count(ll\
    \ N, const ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    vector<ll>\
    \ count(b, 0);\n    for (ll d : Integer_Digits(N, b)) {\n        count[d]++;\n\
    \    }\n    return count;\n}\n\n/// @brief \u5E95\u3092 b \u3068\u3057\u305F\u5834\
    \u5408\u306B digits \u304C\u306A\u3059\u6574\u6570\u3092\u8FD4\u3059 (Integer_Digits\
    \ \u306E\u9006\u95A2\u6570)\n/// @param digits \u6570\u306E\u30EA\u30B9\u30C8\
    \ (\u6700\u4E0A\u4F4D\u6841\u304B\u3089\u6700\u4E0B\u4F4D\u6841\u306E\u9806)\n\
    /// @param b \u5E95 (b >= 2). Default to 10.\n/// @return \u6574\u6570 (\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306E\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u305F\u3081\u6CE8\u610F)\nll From_Digits(const vector<ll> &digits, const ll b\
    \ = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    ll res = 0;\n   \
    \ for (ll x : digits) {  res = b * res + x; }\n    return res;\n}\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Digit.hpp\n\
    \n#include\"../template/template.hpp\"\n\n/// @brief \u4E0D\u6B63\u306A\u5E95\u304C\
    \u6307\u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\u30B9\u30ED\u30FC\u3055\u308C\
    \u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\u5916\nclass BaseException : public runtime_error\
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
    \ = 0;\n    for (ll x : digits) {  res = b * res + x; }\n    return res;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Integer/Digit.hpp
  requiredBy: []
  timestamp: '2026-11-20 01:12:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Digit.test.cpp
documentation_of: Integer/Digit.hpp
layout: document
title: "\u6574\u6570\u306E\u6841"
---

## Outline

整数の表示や桁に関する計算を行う.

## Theory

### b 進表記

<div class="theorem" markdown="1">

定理 1
---

$b$ を $2$ 以上の整数とする.

正の整数 $n$ に対して, 以下を満たす整数の有限列 $a$ がただ一つ存在する. ただし, $d$ を $a$ の長さとして, $a = (a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ と添字を付ける.

* $i = d-1, d-2, \dots, 1, 0$ に対して, $0 \leq a_i < b$ である.
* $a_{d-1} \neq 0$.
* $n = a_{d-1} b^{d-1} + \dots + a_1 b + a_0$.

</div>

<div class="proof" markdown="1">

証明
---

$n$ に関する累積帰納法で示す. $n$ を $b$ で割った商を $q$, 余りを $r$ とする. すなわち, $n = qb + r$ かつ $0 \leq r < b$ である.

**存在**: $n < b$ のときは, $d = 1, a_0 = n$ とすればよい. $n \geq b$ のときは $1 \leq q < n$ であるから, 帰納法の仮定より, $q$ に対して条件を満たす列 $(e_{k-1}, \dots, e_0)$ が存在する. このとき, 長さ $k + 1$ の列 $a = (e_{k-1}, \dots, e_0, r)$ は $n$ に対して条件を満たす.

**一意性**: 長さ $d$ の列 $a$ が $n$ に対して条件を満たすとする. $n = (a_{d-1} b^{d-2} + \dots + a_1) b + a_0$ かつ $0 \leq a_0 < b$ であるから, 商と余りの一意性より $a_0 = r$ である. また,

* $d = 1$ のとき, $n = a_0 < b$ である.
* $d \geq 2$ のとき, $n \geq a_{d-1} b^{d-1} \geq b$ である.

よって, $n < b$ ならば $a = (r)$ に限る. $n \geq b$ ならば $d \geq 2$ であり, 列 $(a_{d-1}, \dots, a_1)$ は $q = a_{d-1} b^{d-2} + \dots + a_1$ に対して条件を満たす. $1 \leq q < n$ であるから, 帰納法の仮定より, この列は $q$ から一意に定まる. 以上より, $a$ は一意である.

</div>

<div class="definition" markdown="1">

定義 2
---

$b$ を $2$ 以上の整数とし, 正の整数 $n$ に対して, 定理 1 の列を $a = (a_{d-1}, \dots, a_1, a_0)$ とする.

* $b$ を底や基数という.
* $a$ を $n$ の $b$ 進表記という.
* $a$ の長さ $d$ を $n$ の $b$ 進表記における桁数という.
* $a_i$ を $n$ の $b$ 進表記における $b^i$ の位という.
  * 特に, $b^{d-1}$ の位 $a_{d-1}$ を $n$ の $b$ 進表記における最高位という.

また, $0$ の $b$ 進表記は空列とする. すなわち, $0$ の桁数は $0$ である.

$c_0, c_1, \dots, c_{b-1}$ を互いに異なる文字とするとき, $n$ を

$$ n = (c_{a_{d-1}} c_{a_{d-2}} \cdots c_{a_1} c_{a_0})_b $$

と書くこともある.

</div>

### 数字和/数字根

<div class="definition" markdown="1">

定義 3
---

$b$ を $2$ 以上の整数, $n$ を正の整数として, $a = (a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ を $n$ の $b$ 進表記とする.

このとき,

$$ S_b(n) := \sum_{k=0}^{d-1} a_k $$

を $n$ の $b$ 進数字和という.

また, $0$ の $b$ 進数字和は $S_b(0) := 0$ とする.

</div>

<div class="proposition" markdown="1">

命題 4
---

$b$ を $2$ 以上の整数, $n$ を非負整数とする. このとき,

$$ n \equiv S_b(n) \pmod{(b-1)} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$n = 0$ のときは明らかである. $n \geq 1$ のとき, $n$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とする. $b \equiv 1 \pmod{(b-1)}$ より, 任意の非負整数 $k$ に対して $b^k \equiv 1 \pmod{(b-1)}$ であるから,

$$ n = \sum_{k=0}^{d-1} a_k b^k \equiv \sum_{k=0}^{d-1} a_k = S_b(n) \pmod{(b-1)} $$

である.

</div>

<div class="proposition" markdown="1">

命題 5
---

$b$ を $2$ 以上の整数, $n$ を非負整数とする. 次のようにして整数列 $(x_k)$ を定める.

* $x_0 := n$.
* $x_k := S_b(x_{k-1}) \quad (k \geq 1)$.

このとき, $(x_k)$ は有限個の例外を除いて定数列である.

</div>

<div class="proof" markdown="1">

証明
---

まず, 非負整数 $m$ に対して次が成り立つことを示す.

* $0 \leq m < b$ ならば $S_b(m) = m$.
* $m \geq b$ ならば $S_b(m) < m$.

$m = 0$ のときは定義より $S_b(0) = 0$ である. $1 \leq m < b$ のときは, $m$ の $b$ 進表記は $(m)$ であるから $S_b(m) = m$ である. $m \geq b$ のときは, 定理 1 の証明より $m$ の桁数 $d$ は $d \geq 2$ であり, $m$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とすると,

$$ m - S_b(m) = \sum_{k=1}^{d-1} a_k \left( b^k - 1 \right) \geq a_{d-1} \left( b^{d-1} - 1 \right) \geq 1 $$

である.

よって, $x_k \geq b$ である間は $(x_k)$ は非負整数の狭義単調減少列であるから, $x_K < b$ となる $K$ が存在する. このとき, $k \geq K$ に対して $x_k = x_K$ である.

</div>

<div class="definition" markdown="1">

定義 6
---

命題 5 の数列 $(x_k)$ が最終的にとる値を, $n$ の $b$ 進数字根という.

</div>

<div class="proposition" markdown="1">

命題 7
---

$b$ を $2$ 以上の整数, $n$ を非負整数とし, $n$ の $b$ 進数字根を $r$ とする. このとき, 以下が成り立つ.

$$ r = \begin{cases}
  0 & (n = 0) \\
  n \bmod (b - 1) & (n \not \equiv 0 \pmod{(b-1)}) \\
  b - 1 & (n > 0 \land (b-1) \mid n)
\end{cases}$$

</div>

<div class="proof" markdown="1">

証明
---

命題 5 と同様に, $x_0 := n, x_k := S_b(x_{k-1}) \ (k \geq 1)$ とする. 命題 5 の証明より, $x_K < b$ となる $K$ が存在し, $r = x_K$ である. 特に, $0 \leq r < b$ である.

また, 命題 4 より, 任意の $k \geq 1$ に対して $x_k = S_b(x_{k-1}) \equiv x_{k-1} \pmod{(b-1)}$ であるから, $r = x_K \equiv x_0 = n \pmod{(b-1)}$ である.

$n = 0$ のとき, $S_b(0) = 0$ より, 任意の $k$ に対して $x_k = 0$ であるから, $r = 0$ である.

$n > 0$ のとき, 正の整数 $m$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とすると, $S_b(m) \geq a_{d-1} \geq 1$ である. よって, 帰納的に任意の $k$ に対して $x_k \geq 1$ であり, 特に $1 \leq r \leq b - 1$ である.

$1, 2, \dots, b-1$ は $b - 1$ を法としてどの 2 つも合同でないから, $1 \leq r \leq b-1$ かつ $r \equiv n \pmod{(b-1)}$ を満たす $r$ はただ一つである. したがって,

* $n \not\equiv 0 \pmod{(b-1)}$ のとき, $1 \leq n \bmod (b-1) \leq b - 2$ であり, $n \bmod (b-1) \equiv n \pmod{(b-1)}$ であるから, $r = n \bmod (b-1)$ である.
* $(b-1) \mid n$ のとき, $b - 1 \equiv 0 \equiv n \pmod{(b-1)}$ であるから, $r = b - 1$ である.

</div>

## Remark

このライブラリの関数は, $b$ 進表記を最高位 $a_{d-1}$ から $a_0$ の順に並べた列 $(a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ として扱う.

## Contents

### Integer_Digits

```cpp
vector<ll> Integer_Digits(ll N, const ll b = 10, const int l = -1)
```

* $N$ の $b$ 進表記を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
  * $l$ : 出力される長さについて制御する.
    * $l = -1$ のときは, 厳密な意味での $b$ 進表記が返される. ただし, $N = 0$ のときは $(0)$ が返される.
    * $l \geq 0$ のときは, 長さが $l$ になるように調整される. 具体的には, $N$ の $b$ 進表記での表示を $a = (a_{d-1}, \dots, a_1, a_0)$ とするとき, それぞれ以下のようになる.
      * $l \gt d$ のとき: 返り値は $(\underbrace{0, \dots, 0}\_{l-d}, a_{d-1}, \dots, a_1, a_0)$ となる.
      * $l \leq d$ のとき: 返り値は $(a_{l-1}, \dots, a_1, a_0)$ となる.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $l = -1$ または $l \geq 0$.
  * $N \geq 0$.
* **計算量** : $l = -1$ のとき $O \left( \log_b N \right)$ 時間, $l \geq 0$ のとき $O(l)$ 時間.

### Integer_Length

```cpp
int Integer_Length(ll N, const ll b = 10)
```

* $N$ の $b$ 進表記における桁数を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **注意** : $0$ の桁数は $0$ とする. したがって, `Integer_Length(0)` と `Integer_Digits(0).size()` は一致しない.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \geq 0$.
* **計算量** : $O \left( \log_b N \right)$ 時間.

### Digit_Sum

```cpp
ll Digit_Sum(ll N, const ll b = 10)
```

* $N$ の $b$ 進表記における数字和を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \geq 0$.
* **計算量** : $O \left( \log_b N \right)$ 時間.

### Digit_Count

```cpp
vector<ll> Digit_Count(ll N, const ll b = 10)
```

* $N$ の $b$ 進表記における各数の出現回数を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **出力**
  * 長さ $b$ のリスト. 第 $j$ 要素には, $N$ の $b$ 進表記における $j$ の出現回数が格納されている.
  * $N = 0$ のときは, `Integer_Digits` と同様に $(0)$ を表記とみなすため, 第 $0$ 要素が $1$ になる.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \geq 0$.
  * 長さ $b$ の配列を確保するため, $b$ が大きすぎるとメモリが不足する.
* **計算量** : $O \left( b + \log_b N \right)$ 時間, $O(b)$ 空間.

### From_Digits

```cpp
ll From_Digits(const vector<ll> &digits, const ll b = 10)
```

* $b$ 進表記が `digits` となる整数を求める (`Integer_Digits` の逆関数).
* **入力**
  * `digits` : 最上位桁から最下位桁の順に並べた数のリスト.
  * $b$ : 基数. デフォルトは $b = 10$.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
* **注意**
  * `digits` の各要素が $0$ 以上 $b$ 未満であるかは検査しない. `digits` $= (c_{L-1}, \dots, c_1, c_0)$ とするとき, 範囲外の要素があっても $\displaystyle \sum_{i=0}^{L-1} c_i b^i$ をそのまま計算した値を返す ($L$ は `digits` の長さ).
  * オーバーフローに注意.
* **計算量** : $L$ を `digits` の長さとして, $O(L)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/11/20|ドキュメントの誤記修正, 制約の追記, Theory の整理と証明の追加|
|2025/11/24|引数の変更 & ドキュメントの追加|