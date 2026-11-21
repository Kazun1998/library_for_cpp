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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Max_Flow/Project_Selection_Problem.hpp
    title: Max_Flow/Project_Selection_Problem.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/grl/6A.test.cpp
    title: verify/aizu_online_judge/grl/6A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/1984.test.cpp
    title: verify/yukicoder/1984.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5F27\u306E id (\u9806\u8FBA\u3068\u9006\u8FBA\u3067\u5171\u901A\
      )"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Max_Flow/Max_Flow.hpp
  bundledCode: "#line 2 \"Max_Flow/Max_Flow.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Max_Flow/Max_Flow.hpp\n\
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
    \    }\n};\n#line 6 \"Max_Flow/Max_Flow.hpp\"\n\nnamespace max_flow {\n    template<typename\
    \ Cap>\n    struct Arc {\n        /// @brief \u5F27\u306E id (\u9806\u8FBA\u3068\
    \u9006\u8FBA\u3067\u5171\u901A)\n        int id;\n\n        /// @brief \u5F27\u306E\
    \u59CB\u70B9\u3068\u7D42\u70B9\n        int source, target;\n\n        /// @brief\
    \ \u5BB9\u91CF\u3068\u73FE\u5728\u306E\u6D41\u91CF (\u9006\u8FBA\u3067\u306F cap\
    \ = 0, flow = -(\u9806\u8FBA\u306E\u6D41\u91CF))\n        Cap cap, flow;\n\n \
    \       /// @brief true \u2192 add_arc \u3067\u8FFD\u52A0\u3057\u305F\u5F27 (\u9806\
    \u8FBA), false \u2192 \u6B8B\u4F59\u30B0\u30E9\u30D5\u7528\u306E\u9006\u8FBA\n\
    \        bool direction;\n\n        /// @brief \u5BFE\u306B\u306A\u308B\u5F27\
    \ (source \u3068 target \u3092\u5165\u308C\u66FF\u3048\u305F\u5F27) \u3078\u306E\
    \u30DD\u30A4\u30F3\u30BF.\n        /// \u9806\u8FBA\u306A\u3089\u9006\u8FBA\u3092\
    , \u9006\u8FBA\u306A\u3089\u9806\u8FBA\u3092\u6307\u3059.\n        Arc* rev;\n\
    \n        Arc(int id, int source, int target, Cap cap, Cap flow, bool direction):\n\
    \            id(id), source(source), target(target), cap(cap), flow(flow), direction(direction),\
    \ rev(nullptr) {}\n\n        /// @brief \u6B8B\u4F59\u5BB9\u91CF\u304C\u6B63 (\u307E\
    \u3060\u6D41\u305B\u308B) \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n        /// @return \u6B8B\u4F59\u5BB9\u91CF\u304C\u6B63\u306A\u3089\u3070 true\n\
    \        inline bool is_flowable() const { return flow < cap; }\n\n        ///\
    \ @brief \u6B8B\u4F59\u5BB9\u91CF\u3092\u6C42\u3081\u308B\n        /// @return\
    \ \u6B8B\u4F59\u5BB9\u91CF cap - flow\n        inline Cap remain() const { return\
    \ cap - flow; }\n\n        /// @brief \u3053\u306E\u5F27\u306B\u6D41\u91CF d \u3092\
    \u6D41\u3059. \u5BFE\u306B\u306A\u308B\u5F27\u306E\u6D41\u91CF\u3082 -d \u3060\
    \u3051\u66F4\u65B0\u3059\u308B.\n        /// @param d \u6D41\u3059\u91CF\n   \
    \     void push(Cap d) {\n            flow += d;\n            rev->flow -= d;\n\
    \        }\n    };\n\n    template<typename Cap>\n    struct Max_Flow {\n    \
    \    private:\n        using V = int;\n        vector<vector<Arc<Cap>*>> adj_out;\n\
    \        vector<Arc<Cap>*> arcs;\n        vector<int> level, iter;\n\n       \
    \ /// @brief \u6B8B\u4F59\u30B0\u30E9\u30D5\u4E0A\u3067 s \u304B\u3089\u306E BFS\
    \ \u3092\u884C\u3044, level (s \u304B\u3089\u306E\u8DDD\u96E2) \u3092\u8A08\u7B97\
    \u3059\u308B.\n        /// t \u306B\u5230\u9054\u3057\u305F\u6642\u70B9\u3067\u6253\
    \u3061\u5207\u308B.\n        /// @param s \u59CB\u70B9\n        /// @param t \u7D42\
    \u70B9\n        /// @return \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 s \u304B\u3089\
    \ t \u306B\u5230\u9054\u53EF\u80FD\u306A\u3089\u3070 true\n        bool bfs(const\
    \ V s, const V t) {\n            level.assign(order(), -1);\n            queue<V>\
    \ Q;\n\n            Q.push(s);\n            level[s] = 0;\n\n            while\
    \ (!Q.empty()) {\n                V v = Q.front(); Q.pop();\n\n              \
    \  for (Arc<Cap>* arc: adj_out[v]) {\n                    unless(arc->is_flowable()\
    \ && level[arc->target] == -1) { continue; }\n\n                    level[arc->target]\
    \ = level[v] + 1;\n                    if (arc->target == t) { return true; }\n\
    \n                    Q.push(arc->target);\n                }\n            }\n\
    \n            return false;\n        }\n\n        /// @brief \u30EC\u30D9\u30EB\
    \u30B0\u30E9\u30D5\u4E0A\u3067 v \u304B\u3089 t \u3078\u306E\u5897\u52A0\u30D1\
    \u30B9\u3092 1 \u672C\u63A2\u3057, \u305D\u3053\u306B\u6D41\u3059.\n        ///\
    \ iter[v] \u3092\u9032\u3081\u308B\u3053\u3068\u3067, 1 \u56DE\u306E\u30D5\u30A7\
    \u30FC\u30BA\u5185\u3067\u540C\u3058\u5F27\u3092\u518D\u63A2\u7D22\u3057\u306A\
    \u3044.\n        /// @param v \u73FE\u5728\u306E\u9802\u70B9\n        /// @param\
    \ t \u7D42\u70B9\n        /// @param f \u6D41\u91CF\u306E\u4E0A\u9650 (unlimited\
    \ = true \u306E\u3068\u304D\u306F\u7121\u8996\u3055\u308C\u308B)\n        ///\
    \ @param unlimited true \u306E\u3068\u304D, \u6D41\u91CF\u306E\u4E0A\u9650\u306F\
    \u7121\u3044\u3082\u306E\u3068\u3057\u3066\u6271\u3046\n        /// @return \u6D41\
    \u3057\u305F\u91CF (\u5897\u52A0\u30D1\u30B9\u304C\u7121\u3051\u308C\u3070 0)\n\
    \        Cap dfs(const V v, const V t, const Cap f, const bool unlimited) {\n\
    \            if (v == t) { return f; }\n\n            for (int &i = iter[v]; i\
    \ < (int)adj_out[v].size(); ++i) {\n                Arc<Cap>* arc = adj_out[v][i];\n\
    \n                unless(arc->is_flowable() && level[v] < level[arc->target])\
    \ { continue; }\n\n                Cap next_f = unlimited ? arc->remain() : min(f,\
    \ arc->remain());\n                Cap d = dfs(arc->target, t, next_f, false);\n\
    \n                unless(d > 0) { continue; }\n\n                arc->push(d);\n\
    \                return d;\n            }\n\n            return 0;\n        }\n\
    \n        public:\n        /// @brief N \u9802\u70B9\u306E\u30D5\u30ED\u30FC\u5834\
    \u3092\u751F\u6210\u3059\u308B\n        /// @param N \u4F4D\u6570\n        Max_Flow(int\
    \ N = 0) {\n            adj_out.resize(N);\n            level.resize(N);\n   \
    \         iter.resize(N);\n        }\n\n        /// @brief \u78BA\u4FDD\u3057\u305F\
    \u5F27 (\u9806\u8FBA\u3068\u9006\u8FBA) \u3092\u89E3\u653E\u3059\u308B\n     \
    \   ~Max_Flow() {\n            for (Arc<Cap>* arc : arcs) {\n                if\
    \ (arc->rev) { delete arc->rev; }\n                delete arc;\n            }\n\
    \        }\n\n        /// @brief \u30D5\u30ED\u30FC\u5834\u306E\u4F4D\u6570\u3092\
    \u8FD4\u3059\n        /// @return \u4F4D\u6570\n        inline int order() const\
    \ { return adj_out.size(); }\n\n        /// @brief \u30D5\u30ED\u30FC\u5834\u306E\
    \u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B\n        /// @return \u30B5\u30A4\u30BA\
    \n        inline int size() const { return arcs.size(); }\n\n        /// @brief\
    \ \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u5BB9\u91CF cap \u306E\
    \u5F27\u3092\u8FFD\u52A0\u3059\u308B\n        /// @param u \u59CB\u70B9\n    \
    \    /// @param v \u7D42\u70B9\n        /// @param cap \u5BB9\u91CF\n        ///\
    \ @return \u8FFD\u52A0\u3057\u305F\u5F27\u306E id\n        int add_arc(const V\
    \ u, const V v, const Cap cap) {\n            int m = size();\n\n            Arc<Cap>*\
    \ arc = new Arc<Cap>(m, u, v, cap, 0, true);\n            Arc<Cap>* rev_arc =\
    \ new Arc<Cap>(m, v, u, 0, 0, false);\n\n            arc->rev = rev_arc;\n   \
    \         rev_arc->rev = arc;\n\n            adj_out[u].emplace_back(arc);\n \
    \           adj_out[v].emplace_back(rev_arc);\n            arcs.emplace_back(arc);\n\
    \n            return m;\n        }\n\n        /// @brief 1 \u9802\u70B9\u3092\u8FFD\
    \u52A0\u3059\u308B.\n        /// @return \u8FFD\u52A0\u3057\u305F\u9802\u70B9\u306E\
    \u756A\u53F7\n        int add_vertex() {\n            adj_out.emplace_back();\n\
    \            level.emplace_back(-1);\n            iter.emplace_back(0);\n\n  \
    \          return order() - 1;\n        }\n\n        /// @brief source \u304B\u3089\
    \ target \u3078\u306E\u6700\u5927\u6D41\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\
    \u308B\n        /// @param source \u59CB\u70B9\n        /// @param target \u7D42\
    \u70B9\n        /// @return \u6700\u5927\u6D41\u306E\u5927\u304D\u3055\n     \
    \   Cap max_flow(const V source, const V target) {\n            Cap flow = 0;\n\
    \            while (bfs(source, target)) {\n                iter.assign(order(),\
    \ 0);\n                Cap f;\n                while ((f = dfs(source, target,\
    \ Cap(0), true)) > 0) {\n                    flow += f;\n                }\n \
    \           }\n\n            return flow;\n        }\n\n        /// @brief source\
    \ \u304B\u3089 target \u3078\u306E\u9AD8\u3005 flow_limit \u307E\u3067\u306E\u6700\
    \u5927\u6D41\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n        /// @param\
    \ source \u59CB\u70B9\n        /// @param target \u7D42\u70B9\n        /// @param\
    \ flow_limit \u6D41\u3059\u5BB9\u91CF\u306E\u4E0A\u9650\n        /// @return \u6700\
    \u5927\u6D41\u306E\u5927\u304D\u3055\n        Cap max_flow(const V source, const\
    \ V target, Cap flow_limit) {\n            Cap flow = 0;\n            while (flow\
    \ < flow_limit && bfs(source, target)) {\n                iter.assign(order(),\
    \ 0);\n                Cap f;\n                while (flow < flow_limit && (f\
    \ = dfs(source, target, flow_limit - flow, false)) > 0) {\n                  \
    \  flow += f;\n                }\n            }\n\n            return flow;\n\
    \        }\n\n        /// @brief max_flow \u3067\u6C42\u3081\u305F\u6D41\u308C\
    \u3092\u53D6\u5F97\u3059\u308B.\n        /// @return \u7B2C u \u8981\u7D20\u306F\
    , u \u3092\u59CB\u70B9\u3068\u3059\u308B\u5404\u5F27\u306B\u3064\u3044\u3066 (\u5F27\
    \u306E id, \u7D42\u70B9, \u6D41\u91CF) \u3092\u4E26\u3079\u305F\u3082\u306E\n\
    \        vector<vector<tuple<int, V, Cap>>> get_flow() const {\n            vector<vector<tuple<int,\
    \ V, Cap>>> flow(order());\n\n            for (Arc<Cap>* arc: arcs) {\n      \
    \          flow[arc->source].emplace_back(\n                    arc->id,\n   \
    \                 arc->target,\n                    arc->flow\n              \
    \  );\n            }\n\n            return flow;\n        }\n\n        /// @brief\
    \ \u6700\u5C0F\u30AB\u30C3\u30C8\u3092\u6C42\u3081\u308B. max_flow(s, t) \u3092\
    \u547C\u3093\u3060\u5F8C\u306B\u4F7F\u3046\u3053\u3068.\n        /// @param s\
    \ \u59CB\u70B9\n        /// @return \u9577\u3055 N \u306E\u914D\u5217 group. \u6B8B\
    \u4F59\u30B0\u30E9\u30D5\u3067 s \u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\u9802\
    \u70B9 (s \u5074) \u304C false, \u305D\u308C\u4EE5\u5916 (t \u5074) \u304C true\n\
    \        vector<bool> min_cut(const int s) {\n            vector<bool> group(order(),\
    \ true); group[s] = false;\n\n            deque<V> Q{s};\n\n            while\
    \ (!Q.empty()) {\n                V x = Q.front(); Q.pop_front();\n\n        \
    \        for (Arc<Cap>* arc: adj_out[x]) {\n                    V y = arc->target;\n\
    \                    unless(arc->is_flowable() && group[y]) { continue; }\n\n\
    \                    group[y] = false;\n                    Q.emplace_back(y);\n\
    \                }\n            }\n\n            return group;\n        }\n  \
    \  };\n}\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Max_Flow/Max_Flow.hpp\n\
    \n#include\"../template/template.hpp\"\n\nnamespace max_flow {\n    template<typename\
    \ Cap>\n    struct Arc {\n        /// @brief \u5F27\u306E id (\u9806\u8FBA\u3068\
    \u9006\u8FBA\u3067\u5171\u901A)\n        int id;\n\n        /// @brief \u5F27\u306E\
    \u59CB\u70B9\u3068\u7D42\u70B9\n        int source, target;\n\n        /// @brief\
    \ \u5BB9\u91CF\u3068\u73FE\u5728\u306E\u6D41\u91CF (\u9006\u8FBA\u3067\u306F cap\
    \ = 0, flow = -(\u9806\u8FBA\u306E\u6D41\u91CF))\n        Cap cap, flow;\n\n \
    \       /// @brief true \u2192 add_arc \u3067\u8FFD\u52A0\u3057\u305F\u5F27 (\u9806\
    \u8FBA), false \u2192 \u6B8B\u4F59\u30B0\u30E9\u30D5\u7528\u306E\u9006\u8FBA\n\
    \        bool direction;\n\n        /// @brief \u5BFE\u306B\u306A\u308B\u5F27\
    \ (source \u3068 target \u3092\u5165\u308C\u66FF\u3048\u305F\u5F27) \u3078\u306E\
    \u30DD\u30A4\u30F3\u30BF.\n        /// \u9806\u8FBA\u306A\u3089\u9006\u8FBA\u3092\
    , \u9006\u8FBA\u306A\u3089\u9806\u8FBA\u3092\u6307\u3059.\n        Arc* rev;\n\
    \n        Arc(int id, int source, int target, Cap cap, Cap flow, bool direction):\n\
    \            id(id), source(source), target(target), cap(cap), flow(flow), direction(direction),\
    \ rev(nullptr) {}\n\n        /// @brief \u6B8B\u4F59\u5BB9\u91CF\u304C\u6B63 (\u307E\
    \u3060\u6D41\u305B\u308B) \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n        /// @return \u6B8B\u4F59\u5BB9\u91CF\u304C\u6B63\u306A\u3089\u3070 true\n\
    \        inline bool is_flowable() const { return flow < cap; }\n\n        ///\
    \ @brief \u6B8B\u4F59\u5BB9\u91CF\u3092\u6C42\u3081\u308B\n        /// @return\
    \ \u6B8B\u4F59\u5BB9\u91CF cap - flow\n        inline Cap remain() const { return\
    \ cap - flow; }\n\n        /// @brief \u3053\u306E\u5F27\u306B\u6D41\u91CF d \u3092\
    \u6D41\u3059. \u5BFE\u306B\u306A\u308B\u5F27\u306E\u6D41\u91CF\u3082 -d \u3060\
    \u3051\u66F4\u65B0\u3059\u308B.\n        /// @param d \u6D41\u3059\u91CF\n   \
    \     void push(Cap d) {\n            flow += d;\n            rev->flow -= d;\n\
    \        }\n    };\n\n    template<typename Cap>\n    struct Max_Flow {\n    \
    \    private:\n        using V = int;\n        vector<vector<Arc<Cap>*>> adj_out;\n\
    \        vector<Arc<Cap>*> arcs;\n        vector<int> level, iter;\n\n       \
    \ /// @brief \u6B8B\u4F59\u30B0\u30E9\u30D5\u4E0A\u3067 s \u304B\u3089\u306E BFS\
    \ \u3092\u884C\u3044, level (s \u304B\u3089\u306E\u8DDD\u96E2) \u3092\u8A08\u7B97\
    \u3059\u308B.\n        /// t \u306B\u5230\u9054\u3057\u305F\u6642\u70B9\u3067\u6253\
    \u3061\u5207\u308B.\n        /// @param s \u59CB\u70B9\n        /// @param t \u7D42\
    \u70B9\n        /// @return \u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 s \u304B\u3089\
    \ t \u306B\u5230\u9054\u53EF\u80FD\u306A\u3089\u3070 true\n        bool bfs(const\
    \ V s, const V t) {\n            level.assign(order(), -1);\n            queue<V>\
    \ Q;\n\n            Q.push(s);\n            level[s] = 0;\n\n            while\
    \ (!Q.empty()) {\n                V v = Q.front(); Q.pop();\n\n              \
    \  for (Arc<Cap>* arc: adj_out[v]) {\n                    unless(arc->is_flowable()\
    \ && level[arc->target] == -1) { continue; }\n\n                    level[arc->target]\
    \ = level[v] + 1;\n                    if (arc->target == t) { return true; }\n\
    \n                    Q.push(arc->target);\n                }\n            }\n\
    \n            return false;\n        }\n\n        /// @brief \u30EC\u30D9\u30EB\
    \u30B0\u30E9\u30D5\u4E0A\u3067 v \u304B\u3089 t \u3078\u306E\u5897\u52A0\u30D1\
    \u30B9\u3092 1 \u672C\u63A2\u3057, \u305D\u3053\u306B\u6D41\u3059.\n        ///\
    \ iter[v] \u3092\u9032\u3081\u308B\u3053\u3068\u3067, 1 \u56DE\u306E\u30D5\u30A7\
    \u30FC\u30BA\u5185\u3067\u540C\u3058\u5F27\u3092\u518D\u63A2\u7D22\u3057\u306A\
    \u3044.\n        /// @param v \u73FE\u5728\u306E\u9802\u70B9\n        /// @param\
    \ t \u7D42\u70B9\n        /// @param f \u6D41\u91CF\u306E\u4E0A\u9650 (unlimited\
    \ = true \u306E\u3068\u304D\u306F\u7121\u8996\u3055\u308C\u308B)\n        ///\
    \ @param unlimited true \u306E\u3068\u304D, \u6D41\u91CF\u306E\u4E0A\u9650\u306F\
    \u7121\u3044\u3082\u306E\u3068\u3057\u3066\u6271\u3046\n        /// @return \u6D41\
    \u3057\u305F\u91CF (\u5897\u52A0\u30D1\u30B9\u304C\u7121\u3051\u308C\u3070 0)\n\
    \        Cap dfs(const V v, const V t, const Cap f, const bool unlimited) {\n\
    \            if (v == t) { return f; }\n\n            for (int &i = iter[v]; i\
    \ < (int)adj_out[v].size(); ++i) {\n                Arc<Cap>* arc = adj_out[v][i];\n\
    \n                unless(arc->is_flowable() && level[v] < level[arc->target])\
    \ { continue; }\n\n                Cap next_f = unlimited ? arc->remain() : min(f,\
    \ arc->remain());\n                Cap d = dfs(arc->target, t, next_f, false);\n\
    \n                unless(d > 0) { continue; }\n\n                arc->push(d);\n\
    \                return d;\n            }\n\n            return 0;\n        }\n\
    \n        public:\n        /// @brief N \u9802\u70B9\u306E\u30D5\u30ED\u30FC\u5834\
    \u3092\u751F\u6210\u3059\u308B\n        /// @param N \u4F4D\u6570\n        Max_Flow(int\
    \ N = 0) {\n            adj_out.resize(N);\n            level.resize(N);\n   \
    \         iter.resize(N);\n        }\n\n        /// @brief \u78BA\u4FDD\u3057\u305F\
    \u5F27 (\u9806\u8FBA\u3068\u9006\u8FBA) \u3092\u89E3\u653E\u3059\u308B\n     \
    \   ~Max_Flow() {\n            for (Arc<Cap>* arc : arcs) {\n                if\
    \ (arc->rev) { delete arc->rev; }\n                delete arc;\n            }\n\
    \        }\n\n        /// @brief \u30D5\u30ED\u30FC\u5834\u306E\u4F4D\u6570\u3092\
    \u8FD4\u3059\n        /// @return \u4F4D\u6570\n        inline int order() const\
    \ { return adj_out.size(); }\n\n        /// @brief \u30D5\u30ED\u30FC\u5834\u306E\
    \u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B\n        /// @return \u30B5\u30A4\u30BA\
    \n        inline int size() const { return arcs.size(); }\n\n        /// @brief\
    \ \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u5BB9\u91CF cap \u306E\
    \u5F27\u3092\u8FFD\u52A0\u3059\u308B\n        /// @param u \u59CB\u70B9\n    \
    \    /// @param v \u7D42\u70B9\n        /// @param cap \u5BB9\u91CF\n        ///\
    \ @return \u8FFD\u52A0\u3057\u305F\u5F27\u306E id\n        int add_arc(const V\
    \ u, const V v, const Cap cap) {\n            int m = size();\n\n            Arc<Cap>*\
    \ arc = new Arc<Cap>(m, u, v, cap, 0, true);\n            Arc<Cap>* rev_arc =\
    \ new Arc<Cap>(m, v, u, 0, 0, false);\n\n            arc->rev = rev_arc;\n   \
    \         rev_arc->rev = arc;\n\n            adj_out[u].emplace_back(arc);\n \
    \           adj_out[v].emplace_back(rev_arc);\n            arcs.emplace_back(arc);\n\
    \n            return m;\n        }\n\n        /// @brief 1 \u9802\u70B9\u3092\u8FFD\
    \u52A0\u3059\u308B.\n        /// @return \u8FFD\u52A0\u3057\u305F\u9802\u70B9\u306E\
    \u756A\u53F7\n        int add_vertex() {\n            adj_out.emplace_back();\n\
    \            level.emplace_back(-1);\n            iter.emplace_back(0);\n\n  \
    \          return order() - 1;\n        }\n\n        /// @brief source \u304B\u3089\
    \ target \u3078\u306E\u6700\u5927\u6D41\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\
    \u308B\n        /// @param source \u59CB\u70B9\n        /// @param target \u7D42\
    \u70B9\n        /// @return \u6700\u5927\u6D41\u306E\u5927\u304D\u3055\n     \
    \   Cap max_flow(const V source, const V target) {\n            Cap flow = 0;\n\
    \            while (bfs(source, target)) {\n                iter.assign(order(),\
    \ 0);\n                Cap f;\n                while ((f = dfs(source, target,\
    \ Cap(0), true)) > 0) {\n                    flow += f;\n                }\n \
    \           }\n\n            return flow;\n        }\n\n        /// @brief source\
    \ \u304B\u3089 target \u3078\u306E\u9AD8\u3005 flow_limit \u307E\u3067\u306E\u6700\
    \u5927\u6D41\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n        /// @param\
    \ source \u59CB\u70B9\n        /// @param target \u7D42\u70B9\n        /// @param\
    \ flow_limit \u6D41\u3059\u5BB9\u91CF\u306E\u4E0A\u9650\n        /// @return \u6700\
    \u5927\u6D41\u306E\u5927\u304D\u3055\n        Cap max_flow(const V source, const\
    \ V target, Cap flow_limit) {\n            Cap flow = 0;\n            while (flow\
    \ < flow_limit && bfs(source, target)) {\n                iter.assign(order(),\
    \ 0);\n                Cap f;\n                while (flow < flow_limit && (f\
    \ = dfs(source, target, flow_limit - flow, false)) > 0) {\n                  \
    \  flow += f;\n                }\n            }\n\n            return flow;\n\
    \        }\n\n        /// @brief max_flow \u3067\u6C42\u3081\u305F\u6D41\u308C\
    \u3092\u53D6\u5F97\u3059\u308B.\n        /// @return \u7B2C u \u8981\u7D20\u306F\
    , u \u3092\u59CB\u70B9\u3068\u3059\u308B\u5404\u5F27\u306B\u3064\u3044\u3066 (\u5F27\
    \u306E id, \u7D42\u70B9, \u6D41\u91CF) \u3092\u4E26\u3079\u305F\u3082\u306E\n\
    \        vector<vector<tuple<int, V, Cap>>> get_flow() const {\n            vector<vector<tuple<int,\
    \ V, Cap>>> flow(order());\n\n            for (Arc<Cap>* arc: arcs) {\n      \
    \          flow[arc->source].emplace_back(\n                    arc->id,\n   \
    \                 arc->target,\n                    arc->flow\n              \
    \  );\n            }\n\n            return flow;\n        }\n\n        /// @brief\
    \ \u6700\u5C0F\u30AB\u30C3\u30C8\u3092\u6C42\u3081\u308B. max_flow(s, t) \u3092\
    \u547C\u3093\u3060\u5F8C\u306B\u4F7F\u3046\u3053\u3068.\n        /// @param s\
    \ \u59CB\u70B9\n        /// @return \u9577\u3055 N \u306E\u914D\u5217 group. \u6B8B\
    \u4F59\u30B0\u30E9\u30D5\u3067 s \u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\u9802\
    \u70B9 (s \u5074) \u304C false, \u305D\u308C\u4EE5\u5916 (t \u5074) \u304C true\n\
    \        vector<bool> min_cut(const int s) {\n            vector<bool> group(order(),\
    \ true); group[s] = false;\n\n            deque<V> Q{s};\n\n            while\
    \ (!Q.empty()) {\n                V x = Q.front(); Q.pop_front();\n\n        \
    \        for (Arc<Cap>* arc: adj_out[x]) {\n                    V y = arc->target;\n\
    \                    unless(arc->is_flowable() && group[y]) { continue; }\n\n\
    \                    group[y] = false;\n                    Q.emplace_back(y);\n\
    \                }\n            }\n\n            return group;\n        }\n  \
    \  };\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Max_Flow/Max_Flow.hpp
  requiredBy:
  - Max_Flow/Project_Selection_Problem.hpp
  timestamp: '2026-11-06 00:23:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/1984.test.cpp
  - verify/aizu_online_judge/grl/6A.test.cpp
documentation_of: Max_Flow/Max_Flow.hpp
layout: document
title: "\u6700\u5927\u6D41"
---

## Outline

容量付き有向グラフ (フロー場) 上の最大流問題を Dinic 法で解く. 最大流を求めた後に, 最小カットも求められる.

## Theory

<div class="problem" markdown="1">

最大流問題
---

$D = (V, A)$ を有向グラフとする.

* 頂点 $v \in V$ に対して, $v$ を始点とする弧全体の集合を $\delta^+(v)$, $v$ を終点とする弧全体の集合を $\delta^-(v)$ と書く.
* 各弧 $a \in A$ に対して, 容量 $c(a) \geq 0$ が与えられている.

$s \neq t$ なる $s, t \in V$ に対して, 以下の $f: A \to \mathbb{R}$ に関する最大化問題を最大流問題という.

* Maximize $\displaystyle \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a)$.
* Subject to
  * $0 \leq f(a) \leq c(a) \quad (a \in A)$.
  * $\displaystyle \sum_{a \in \delta^+(v)} f(a) = \sum_{a \in \delta^-(v)} f(a) \quad (v \in V \setminus \lbrace s, t \rbrace)$.

</div>

以下, 総和が意味を持ち, 最大値の存在が言えるように, $V$ と $A$ は有限集合 (多重辺・自己ループは許す) とし, 容量 $c(a)$ は実数とする.

### 理論付け

<div class="definition" markdown="1">

定義 1
---

最大流問題の制約を全て満たす $f: A \to \mathbb{R}$ を **$s$-$t$ フロー** (または単にフロー) という. フロー $f$ に対して, 目的関数の値

$$ \lvert f \rvert := \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a) $$

を $f$ の **流量** という. 流量が最大となるフローを **最大流** といい, その流量を **最大流量** という.

</div>

<div class="proposition" markdown="1">

命題 2
---

最大流は存在する.

</div>

<div class="proof" markdown="1">

証明
---

全ての弧で $f(a) = 0$ とした $f$ はフローなので, フロー全体の集合 $F$ は空でない. また, $F$ は $\mathbb{R}^A$ の有限個の等式と不等式で定まり, 各成分が $0 \leq f(a) \leq c(a)$ を満たすので, 有界閉集合である. $A$ は有限集合なので, $F$ はコンパクトである. 流量 $\lvert f \rvert$ は $f$ について連続なので, 最大値・最小値の定理より $F$ 上で最大値をとる.

</div>

<div class="definition" markdown="1">

定義 3
---

$S \cup T = V$ かつ $S \cap T = \emptyset$ を満たす $S, T \subset V$ の組 $(S, T)$ を $V$ の分割という. $V$ の分割 $(S, T)$ であって, $s \in S$ かつ $t \in T$ を満たすものを **$s$-$t$ カット** (または単にカット) という. カット $(S, T)$ に対して,

* $S$ の頂点から $T$ の頂点への弧全体の集合を $\delta(S, T)$
* $T$ の頂点から $S$ の頂点への弧全体の集合を $\delta(T, S)$

と書き,

$$ \mathrm{cap}(S, T) := \sum_{a \in \delta(S, T)} c(a) $$

を $(S, T)$ の **容量** という. 容量が最小となるカットを **最小カット** という.

</div>

<div class="proposition" markdown="1">

命題 4
---

$f$ をフロー, $(S, T)$ をカットとする. このとき,

$$ \lvert f \rvert = \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a) $$

が成り立つ.

</div>

<div class="proof" markdown="1">

証明
---

頂点 $v$ に対して,

$$ \mathrm{ex}(v) := \sum_{a \in \delta^+(v)} f(a) - \sum_{a \in \delta^-(v)} f(a) $$

とおく. $\mathrm{ex}(s) = \lvert f \rvert$ である. また, $t \in T$ と $S \cap T = \emptyset$ より $t \notin S$ なので, $v \in S \setminus \lbrace s \rbrace$ ならば $v \neq s, t$ であり, 流量保存則より $\mathrm{ex}(v) = 0$ である. よって,

$$ \sum_{v \in S} \mathrm{ex}(v) = \lvert f \rvert $$

である.

一方, 左辺を弧ごとにまとめる. $u$ から $v$ への弧 $a$ について, $f(a)$ は $\mathrm{ex}(u)$ に $+f(a)$, $\mathrm{ex}(v)$ に $-f(a)$ として現れる.

* $u, v \in S$ のとき (自己ループを含む), $a$ の寄与は $f(a) - f(a) = 0$ である.
* $u \in S, v \in T$ のとき, すなわち $a \in \delta(S, T)$ のとき, $a$ の寄与は $+f(a)$ である.
* $u \in T, v \in S$ のとき, すなわち $a \in \delta(T, S)$ のとき, $a$ の寄与は $-f(a)$ である.
* $u, v \in T$ のとき, $a$ は左辺に現れない.

よって, 左辺は $\displaystyle \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a)$ に等しい.

</div>

<div class="proposition" markdown="1">

命題 5 (弱双対性)
---

$f$ をフロー, $(S, T)$ をカットとする. このとき, $\lvert f \rvert \leq \mathrm{cap}(S, T)$ が成り立つ.

さらに, 等号が成り立つための必要十分条件は, 次の $2$ つがともに成り立つことである.

* 任意の $a \in \delta(S, T)$ に対して, $f(a) = c(a)$.
* 任意の $a \in \delta(T, S)$ に対して, $f(a) = 0$.

</div>

<div class="proof" markdown="1">

証明
---

命題 4 と容量制約 $0 \leq f(a) \leq c(a)$ より,

$$ \lvert f \rvert = \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a) \leq \sum_{a \in \delta(S, T)} f(a) \leq \sum_{a \in \delta(S, T)} c(a) = \mathrm{cap}(S, T) $$

である. $1$ つ目の不等号で等号が成り立つことは, 任意の $a \in \delta(T, S)$ で $f(a) = 0$ となることと同値であり, $2$ つ目の不等号で等号が成り立つことは, 任意の $a \in \delta(S, T)$ で $f(a) = c(a)$ となることと同値である.

</div>

### 残余グラフによる最大流の導出

<div class="definition" markdown="1">

定義 6
---

$f$ をフローとする. 各弧 $a \in A$ が $u$ から $v$ への弧であるとき, 次の $2$ 種類の弧を考える.

* **順辺** $a$: $u$ から $v$ への弧で, **残余容量** は $c(a) - f(a)$ である.
* **逆辺** $\overline{a}$: $v$ から $u$ への弧で, **残余容量** は $f(a)$ である.

これらのうち, 残余容量が正であるもの全体を $A_f$ とし, 有向グラフ $D_f = (V, A_f)$ を $f$ に関する **残余グラフ** という. また, $D_f$ 上の $s$ から $t$ への路を **増加パス** という.

</div>

実装では, 順辺を `cap` $= c(a)$, `flow` $= f(a)$ として持ち, 逆辺を `cap` $= 0$, `flow` $= -f(a)$ として持つ. こうすると, どちらの弧でも残余容量は `remain()` $=$ `cap` $-$ `flow` で求まり, 残余グラフの弧であることは `is_flowable()` (`flow` $<$ `cap`) で判定できる. また, 順辺に $d$ だけ流すことと, 逆辺に $d$ だけ流す (順辺の流量を $d$ だけ減らす) ことは, どちらも `push(d)` で表せる.

<div class="theorem" markdown="1">

定理 7 (最大流最小カット定理)
---

$f$ をフローとする. 以下は同値である.

* (a) $f$ は最大流である.
* (b) 残余グラフ $D_f$ に増加パスが存在しない.
* (c) $\lvert f \rvert = \mathrm{cap}(S, T)$ となるカット $(S, T)$ が存在する.

</div>

<div class="proof" markdown="1">

証明
---

**(a) $\Rightarrow$ (b)**: 対偶を示す. $D_f$ に増加パスが存在するとする. 増加パスから閉路を取り除くことで, 同じ頂点を $2$ 度通らない増加パス $s = v_0, v_1, \dots, v_k = t$ が取れる. この路の弧の残余容量の最小値を $\varepsilon$ とすると, $\varepsilon > 0$ である.

同じ頂点を $2$ 度通らないので, この路は同じ $a \in A$ の順辺 $a$ と逆辺 $\overline{a}$ を両方使うことはない. そこで, 路の各弧について次のように $f$ を変更したものを $f'$ とする.

* 順辺 $a$ を使うとき, $f'(a) = f(a) + \varepsilon$.
* 逆辺 $\overline{a}$ を使うとき, $f'(a) = f(a) - \varepsilon$.

$\varepsilon$ の取り方から, $f'$ は容量制約を満たす.

次に, 命題 4 の証明と同じ $\mathrm{ex}$ の変化を見る. $D_f$ の $u$ から $v$ への弧を $1$ 本使うと,

* 順辺 $a$ (元の弧も $u$ から $v$) のとき, $f(a)$ が $\varepsilon$ 増えるので, $\mathrm{ex}(u)$ は $\varepsilon$ 増え, $\mathrm{ex}(v)$ は $\varepsilon$ 減る.
* 逆辺 $\overline{a}$ (元の弧は $v$ から $u$) のとき, $f(a)$ が $\varepsilon$ 減るので, $\mathrm{ex}(v)$ は $\varepsilon$ 減り, $\mathrm{ex}(u)$ は $\varepsilon$ 増える.

いずれの場合も, 始点側の $\mathrm{ex}$ が $\varepsilon$ 増え, 終点側の $\mathrm{ex}$ が $\varepsilon$ 減る. よって, 路の途中の頂点 $v_1, \dots, v_{k-1}$ では増減が打ち消し合い, $\mathrm{ex}$ は変わらない. したがって $f'$ は流量保存則も満たすフローであり, $\lvert f' \rvert = \mathrm{ex}(s) + \varepsilon = \lvert f \rvert + \varepsilon > \lvert f \rvert$ である. これは $f$ が最大流でないことを意味する.

**(b) $\Rightarrow$ (c)**: $D_f$ 上で $s$ から到達可能な頂点全体を $S$ とし, $T := V \setminus S$ とする. $s \in S$ であり, (b) より $t \notin S$, すなわち $t \in T$ なので, $(S, T)$ はカットである.

* $a \in \delta(S, T)$ を $u$ ($\in S$) から $v$ ($\in T$) への弧とする. $f(a) < c(a)$ ならば順辺 $a$ が $D_f$ の弧になり, $v$ が $s$ から到達可能になって矛盾する. よって $f(a) = c(a)$ である.
* $a \in \delta(T, S)$ を $u$ ($\in T$) から $v$ ($\in S$) への弧とする. $f(a) > 0$ ならば逆辺 $\overline{a}$ ($v$ から $u$ への弧) が $D_f$ の弧になり, $u$ が $s$ から到達可能になって矛盾する. よって $f(a) = 0$ である.

命題 5 の等号成立条件より, $\lvert f \rvert = \mathrm{cap}(S, T)$ である.

**(c) $\Rightarrow$ (a)**: 任意のフロー $g$ に対して, 命題 5 より $\lvert g \rvert \leq \mathrm{cap}(S, T) = \lvert f \rvert$ である. よって $f$ は最大流である.

</div>

### 最大流問題と最小カット問題の双対性

<div class="proposition" markdown="1">

命題 8
---

最大流量は, 最小カットの容量に等しい. さらに, $f$ が最大流であるとき, 残余グラフ $D_f$ 上で $s$ から到達可能な頂点全体を $S$, $T := V \setminus S$ とすると, $(S, T)$ は最小カットである.

</div>

<div class="proof" markdown="1">

証明
---

命題 2 より最大流 $f$ が存在する. 定理 7 の (a) $\Rightarrow$ (b) $\Rightarrow$ (c) の証明より, $S$ を $D_f$ 上で $s$ から到達可能な頂点全体, $T := V \setminus S$ とすると, $(S, T)$ はカットであり, $\lvert f \rvert = \mathrm{cap}(S, T)$ である. 一方, 任意のカット $(S', T')$ に対して, 命題 5 より $\mathrm{cap}(S', T') \geq \lvert f \rvert = \mathrm{cap}(S, T)$ である. よって $(S, T)$ は最小カットであり, その容量は最大流量に等しい.

</div>

`min_cut(s)` は, `max_flow(s, t)` で最大流を求めた後の残余グラフ上で $s$ から BFS を行い, 命題 8 の $(S, T)$ を求めている. 返り値では $S$ に属する頂点が `false`, $T$ に属する頂点が `true` である.

最大流問題は $f$ に関する線形計画問題なので, その双対問題を考えることができる. 以下, 弧 $a \in A$ の始点を $s(a)$, 終点を $t(a)$ と書く.

<div class="proposition" markdown="1">

命題 9 (最大流問題の双対問題)
---

最大流問題の双対問題は, $p: V \to \mathbb{R}$ と $z: A \to \mathbb{R}$ に関する次の最小化問題 (D) である.

* Minimize $\displaystyle \sum_{a \in A} c(a) z(a)$.
* Subject to
  * $z(a) \geq p(s(a)) - p(t(a)) \quad (a \in A)$.
  * $z(a) \geq 0 \quad (a \in A)$.
  * $p(s) = 1, \quad p(t) = 0$.

さらに, 以下が成り立つ.

* (D) の最適値は, 最小カットの容量に等しい. したがって, 最大流量にも等しい.
* $(S, T)$ を最小カットとし, $p(v) = 1 ~ (v \in S)$, $p(v) = 0 ~ (v \in T)$, $z(a) = 1 ~ (a \in \delta(S, T))$, $z(a) = 0 ~ (a \notin \delta(S, T))$ とすると, $(p, z)$ は (D) の最適解である.

</div>

<div class="proof" markdown="1">

証明
---

**双対問題の導出**: 線形計画問題

* Maximize $\displaystyle \sum_{j} w_j x_j$.
* Subject to
  * $\displaystyle \sum_{j} \alpha_{ij} x_j \leq b_i \quad (i \in I)$.
  * $\displaystyle \sum_{j} \beta_{kj} x_j = d_k \quad (k \in K)$.
  * $x_j \geq 0$.

の双対問題は, 不等式制約 $i$ に変数 $y_i \geq 0$ を, 等式制約 $k$ に符号制約の無い変数 $q_k$ を対応させた

* Minimize $\displaystyle \sum_{i \in I} b_i y_i + \sum_{k \in K} d_k q_k$.
* Subject to
  * $\displaystyle \sum_{i \in I} \alpha_{ij} y_i + \sum_{k \in K} \beta_{kj} q_k \geq w_j$ (各 $j$).
  * $y_i \geq 0 \quad (i \in I)$.

である. 最大流問題では, 変数は $f(a) ~ (a \in A)$ であり,

* 容量制約 $f(a) \leq c(a)$ に $z(a) \geq 0$ を,
* 頂点 $w \in V \setminus \lbrace s, t \rbrace$ における流量保存則 $\displaystyle \sum_{a \in \delta^+(w)} f(a) - \sum_{a \in \delta^-(w)} f(a) = 0$ に $q(w)$ を

対応させる. 目的関数における $f(a)$ の係数は, $s(a) = s$ ならば $1$ を, $t(a) = s$ ならば $-1$ を足したものである. また, 流量保存則の左辺において, $f(a)$ は $w = s(a)$ の式に係数 $1$ で, $w = t(a)$ の式に係数 $-1$ で現れる. よって, $q(s) = q(t) = 0$ と約束すると, $f(a)$ に対応する双対問題の制約は

$$ z(a) + q(s(a)) - q(t(a)) \geq [s(a) = s] - [t(a) = s] $$

となる. ただし, $[P]$ は条件 $P$ が真ならば $1$, 偽ならば $0$ を表す. ここで, $p(v) := [v = s] - q(v)$ とおくと, $p(s) = 1$, $p(t) = 0$ であり, 上の制約は $z(a) \geq p(s(a)) - p(t(a))$ と書き直せる. $s, t$ 以外の頂点 $v$ では $q(v)$ に符号制約が無いので, $p(v)$ にも符号制約は無い. 等式制約の右辺は $0$ なので, 目的関数は $\displaystyle \sum_{a \in A} c(a) z(a)$ である. 以上より, 双対問題は (D) である.

**(D) の最適値が最大流量以上であること**: $(p, z)$ を (D) の制約を満たす任意の組, $f$ を任意のフローとする. $0 \leq f(a) \leq c(a)$ と $z(a) \geq 0$ より $c(a) z(a) \geq f(a) z(a)$ であり, $f(a) \geq 0$ と $z(a) \geq p(s(a)) - p(t(a))$ より $f(a) z(a) \geq f(a) (p(s(a)) - p(t(a)))$ である. よって,

$$ \sum_{a \in A} c(a) z(a) \geq \sum_{a \in A} f(a) (p(s(a)) - p(t(a))) $$

である. 右辺を頂点ごとにまとめると, 命題 4 の証明と同じ $\mathrm{ex}$ を用いて

$$ \sum_{a \in A} f(a) (p(s(a)) - p(t(a))) = \sum_{w \in V} p(w) \mathrm{ex}(w) $$

となる. 流量保存則より $w \neq s, t$ では $\mathrm{ex}(w) = 0$ であり, $p(s) = 1$, $p(t) = 0$, $\mathrm{ex}(s) = \lvert f \rvert$ なので, 右辺は $\lvert f \rvert$ に等しい. したがって, (D) の目的関数の値は, 任意のフローの流量以上である. 命題 2 より最大流が存在するので, (D) の目的関数の値は最大流量以上である.

**最小カットから (D) の解が作れること**: $(S, T)$ を最小カットとし, $(p, z)$ を命題の主張の通りに定める. $s \in S$, $t \in T$ より $p(s) = 1$, $p(t) = 0$ である. 弧 $a$ について, $p(s(a)) - p(t(a)) = 1$ となるのは $s(a) \in S$ かつ $t(a) \in T$ のとき, すなわち $a \in \delta(S, T)$ のときに限り, このとき $z(a) = 1$ である. それ以外のとき $p(s(a)) - p(t(a)) \leq 0 \leq z(a)$ である. よって $(p, z)$ は (D) の制約を満たし, その目的関数の値は

$$ \sum_{a \in A} c(a) z(a) = \sum_{a \in \delta(S, T)} c(a) = \mathrm{cap}(S, T) $$

である. 命題 8 より $\mathrm{cap}(S, T)$ は最大流量に等しい.

以上より, (D) の目的関数の値は常に最大流量以上であり, 最小カットから作った $(p, z)$ で最大流量に一致する. よって, この $(p, z)$ は (D) の最適解であり, (D) の最適値は最小カットの容量 (= 最大流量) に等しい.

</div>

(D) に $p(v) \in \lbrace 0, 1 \rbrace$ という制約を加えると, $S = \lbrace v \in V \mid p(v) = 1 \rbrace$, $T = \lbrace v \in V \mid p(v) = 0 \rbrace$ とすると, $(S, T)$ がカットに対応する. このとき $z(a) = 1 ~ (a \in \delta(S, T))$, $z(a) = 0 ~ (a \notin \delta(S, T))$ とするのが最適なので, (D) は最小カット問題そのものになる. 命題 9 は, この制約を外しても最適値が変わらないことを示している.

最後に, 容量が整数の場合に成り立つ命題を紹介する. 最大流問題に, 各弧の流量が整数であるという制約を加えた次の整数線形計画問題を考える.

* Maximize $\displaystyle \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a)$.
* Subject to
  * $0 \leq f(a) \leq c(a) \quad (a \in A)$.
  * $\displaystyle \sum_{a \in \delta^+(v)} f(a) = \sum_{a \in \delta^-(v)} f(a) \quad (v \in V \setminus \lbrace s, t \rbrace)$.
  * $f(a) \in \mathbb{Z} \quad (a \in A)$.

次の命題 10 より, 容量が整数ならば, この問題は最大流問題と同じ最適値を持つ. このため, 整数の範囲の計算だけで最大流を求めることができる. 証明は, 最大流問題の制約行列が完全ユニモジュラであることによる (ここでは省略する).

<div class="proposition" markdown="1">

命題 10 (整数性)
---

全ての弧 $a \in A$ について容量 $c(a)$ が整数であるとする. このとき, 以下が成り立つ.

* 最大流量は整数である.
* 全ての弧で $f(a)$ が整数であるような最大流 $f$ が存在する.

特に, 上の整数線形計画問題の最適値は, 最大流問題の最適値 (最大流量) に等しい.

</div>

## Contents

### Constructor

```cpp
template<typename Cap>
Max_Flow<Cap> F(int N = 0)
```

* 容量の型が `Cap` である, 位数 $N$ のフロー場を生成する. 弧は無い.

### order

```cpp
int F.order()
```

* フロー場の位数を返す.

### size

```cpp
int F.size()
```

* フロー場のサイズ (`add_arc` で追加した弧の本数) を返す. 残余グラフ用の逆辺は数えない.

### add_arc

```cpp
int F.add_arc(const int u, const int v, const Cap cap)
```

* 頂点 $u$ から頂点 $v$ への容量 `cap` の弧を追加する.
* **返り値**
  * 追加した弧の番号. $0, 1, 2, \dots$ の順に振られる.
* **制約**
  * $0 \leq u < N, 0 \leq v < N$
  * `cap` $\geq 0$

### add_vertex

```cpp
int F.add_vertex()
```

* 頂点を $1$ 個追加する.
* **返り値**
  * 追加した頂点の番号.

### max_flow

```cpp
Cap F.max_flow(const int source, const int target)
Cap F.max_flow(const int source, const int target, Cap flow_limit)
```

* 頂点 `source` から頂点 `target` へ流せる最大流量を求める.
* `flow_limit` を指定すると, 流す量が高々 `flow_limit` になるところで打ち切る. つまり, 返り値は `flow_limit` と最大流量のうち小さい方になる.
* **返り値**
  * この呼び出しで流した量.
* **注意**
  * 流した結果 (残余グラフ) はフロー場に残る. そのため, `max_flow` を続けて呼ぶと, 前回の流れに追加で流せる量が返る. 例えば, `flow_limit` を指定して途中で打ち切った後に `flow_limit` を指定せずに呼ぶと, $2$ 回の返り値の和が最大流量になる.
* **制約**
  * $0 \leq$ `source` $< N$, $0 \leq$ `target` $< N$
  * `source` $\neq$ `target`
* **計算量** : 計算量は色々ある.
  * 一般には $O(N^2 M)$ 時間.
  * 辺の容量が全て整数である場合
    * 辺容量の平均値が $K$ の場合, $O(K M^{3/2})$ 時間.
    * 辺容量の最大値が $K$ であり, 多重辺が無い場合, $O(K N^{2/3} M)$ 時間.
  * 二部マッチングを求める場合 $O(\sqrt{N} M)$ 時間.

### get_flow

```cpp
vector<vector<tuple<int, int, Cap>>> F.get_flow()
```

* `max_flow` で求めた流れを返す.
* **返り値**
  * 長さ $N$ の配列. 第 $u$ 要素には, $u$ を始点とする各弧について, 次の tuple $(m, v, c)$ が弧の番号の小さい順に並ぶ.
    * 弧の番号が $m$ である.
    * $u$ から $v$ への弧である.
    * その弧の流量が $c$ である.
* **計算量**
  * $O(N + M)$ 時間.

### min_cut

```cpp
vector<bool> F.min_cut(const int s)
```

* 頂点 $s$ を始点とする最小カットを求める. `flow_limit` を指定せずに `F.max_flow(s, t)` を呼んだ後に使う (以下, この $t$ を終点とする).
* **返り値**
  * 長さ $N$ の `bool` 配列 $x$. 最小カット $(S, T)$ の一例を表し, 以下を満たす.
    * $v \in S \iff x_v = \mathtt{false}$ (残余グラフ上で $s$ から到達可能)
    * $v \in T \iff x_v = \mathtt{true}$
    * $s \in S, t \in T$
  * $S$ から $T$ へ向かう弧の容量の総和は, 最大流量に等しい.
* **計算量**
  * $O(N + M)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/11/06| `flow_limit` を指定した `max_flow` が上限を超えて流す不具合と, current-arc が働かない不具合を修正. ドキュメントの `min_cut` の返り値の説明を実装に合わせて修正 ($S$ 側が `false`) |
