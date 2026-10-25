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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3092\u884C\
      \u3046\u30AF\u30E9\u30B9"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Others/Topological_Sort.hpp
  bundledCode: "#line 2 \"Others/Topological_Sort.hpp\"\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Others/Topological_Sort.hpp\n\
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
    \    }\n};\n#line 6 \"Others/Topological_Sort.hpp\"\n\n/**\n * @brief \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3092\u884C\u3046\u30AF\u30E9\u30B9\
    \n */\nclass Topological_Sort {\n    vector<vector<int>> arcs;\n    bool ignore_self_loop;\n\
    \    bool _is_DAG;\n\n    public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     * @param ignore_self_loop\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u3092\u7121\u8996\u3059\u308B\u304B\u3069\u3046\
    \u304B (false \u306E\u5834\u5408, \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u9589\u8DEF\
    \u3068\u3057\u3066\u6271\u308F\u308C\u308B)\n     */\n    Topological_Sort(int\
    \ n, bool ignore_self_loop = true): arcs(n), ignore_self_loop(ignore_self_loop),\
    \ _is_DAG(false) {}\n\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param source \u59CB\u70B9\n     * @param target \u7D42\u70B9\
    \n     */\n    void add_arc(const int source, const int target) {\n        if\
    \ (source == target && ignore_self_loop) return;\n\n        arcs[source].emplace_back(target);\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u59CB\u70B9\u7FA4\
    \u304B\u3089\u306E\u8FBA\u3068\u3001\u6307\u5B9A\u3055\u308C\u305F\u7D42\u70B9\
    \u7FA4\u3078\u306E\u8FBA\u3092\u6301\u3064\u65B0\u3057\u3044\u9802\u70B9\u3092\
    \u8FFD\u52A0\u3059\u308B\n     * @param sources \u65B0\u3057\u3044\u9802\u70B9\
    \u3078\u306E\u59CB\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param targets \u65B0\
    \u3057\u3044\u9802\u70B9\u304B\u3089\u306E\u7D42\u70B9\u306E\u30EA\u30B9\u30C8\
    \n     * @return int \u8FFD\u52A0\u3055\u308C\u305F\u9802\u70B9\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     */\n    int add_arc_multiple(const vector<int>\
    \ &sources, const vector<int> &targets) {\n        const int x = add_vertex();\n\
    \n        for (const int s: sources) add_arc(s, x);\n        for (const int t:\
    \ targets) add_arc(x, t);\n\n        return x;\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\n     * @return int \u8FFD\u52A0\u3055\
    \u308C\u305F\u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     */\n\
    \    int add_vertex() {\n        arcs.emplace_back(vector<int>{});\n\n       \
    \ return arcs.size() - 1;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3092\u5B9F\u884C\u3059\u308B\n     * @return optional<vector<int>>\
    \ \u30BD\u30FC\u30C8\u3055\u308C\u305F\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3002\
    \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u306F nullopt\n     */\n\
    \    optional<vector<int>> sort() const {\n        const int n = arcs.size();\n\
    \        vector<int> in_degree(n, 0);\n        for (const auto &targets: arcs)\
    \ {\n            for (const int y: targets) ++in_degree[y];\n        }\n\n   \
    \     vector<int> order;\n        order.reserve(n);\n        for (int x = 0; x\
    \ < n; ++x) {\n            if (in_degree[x] == 0) order.push_back(x);\n      \
    \  }\n\n        // order[i] \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D,\
    \ \u65B0\u305F\u306B\u5165\u6B21\u6570\u304C 0 \u306B\u306A\u308B\u9802\u70B9\u306F\
    \ order[i] \u306E\u51FA\u8FD1\u508D\u306E\u307F\n        for (int i = 0; i < (int)order.size();\
    \ ++i) {\n            for (const int y: arcs[order[i]]) {\n                if\
    \ (--in_degree[y] == 0) order.push_back(y);\n            }\n        }\n\n    \
    \    if ((int)order.size() < n) return nullopt;\n        return order;\n    }\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5\u304CDAG (\u6709\u5411\u975E\u5DE1\
    \u56DE\u30B0\u30E9\u30D5) \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n     * @return true DAG\u3067\u3042\u308B\n     * @return false DAG\u3067\u306A\
    \u3044 (\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B)\n     */\n    bool is_DAG()\
    \ const { return sort() != nullopt; }\n};\n"
  code: "#pragma once\n\n// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Others/Topological_Sort.hpp\n\
    \n#include \"../template/template.hpp\"\n\n/**\n * @brief \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3092\u884C\u3046\u30AF\u30E9\u30B9\n */\nclass\
    \ Topological_Sort {\n    vector<vector<int>> arcs;\n    bool ignore_self_loop;\n\
    \    bool _is_DAG;\n\n    public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     * @param ignore_self_loop\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u3092\u7121\u8996\u3059\u308B\u304B\u3069\u3046\
    \u304B (false \u306E\u5834\u5408, \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u9589\u8DEF\
    \u3068\u3057\u3066\u6271\u308F\u308C\u308B)\n     */\n    Topological_Sort(int\
    \ n, bool ignore_self_loop = true): arcs(n), ignore_self_loop(ignore_self_loop),\
    \ _is_DAG(false) {}\n\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param source \u59CB\u70B9\n     * @param target \u7D42\u70B9\
    \n     */\n    void add_arc(const int source, const int target) {\n        if\
    \ (source == target && ignore_self_loop) return;\n\n        arcs[source].emplace_back(target);\n\
    \    }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u59CB\u70B9\u7FA4\
    \u304B\u3089\u306E\u8FBA\u3068\u3001\u6307\u5B9A\u3055\u308C\u305F\u7D42\u70B9\
    \u7FA4\u3078\u306E\u8FBA\u3092\u6301\u3064\u65B0\u3057\u3044\u9802\u70B9\u3092\
    \u8FFD\u52A0\u3059\u308B\n     * @param sources \u65B0\u3057\u3044\u9802\u70B9\
    \u3078\u306E\u59CB\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param targets \u65B0\
    \u3057\u3044\u9802\u70B9\u304B\u3089\u306E\u7D42\u70B9\u306E\u30EA\u30B9\u30C8\
    \n     * @return int \u8FFD\u52A0\u3055\u308C\u305F\u9802\u70B9\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n     */\n    int add_arc_multiple(const vector<int>\
    \ &sources, const vector<int> &targets) {\n        const int x = add_vertex();\n\
    \n        for (const int s: sources) add_arc(s, x);\n        for (const int t:\
    \ targets) add_arc(x, t);\n\n        return x;\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9\u3092\u8FFD\u52A0\u3059\u308B\n     * @return int \u8FFD\u52A0\u3055\
    \u308C\u305F\u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     */\n\
    \    int add_vertex() {\n        arcs.emplace_back(vector<int>{});\n\n       \
    \ return arcs.size() - 1;\n    }\n\n    /**\n     * @brief \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3092\u5B9F\u884C\u3059\u308B\n     * @return optional<vector<int>>\
    \ \u30BD\u30FC\u30C8\u3055\u308C\u305F\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3002\
    \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u306F nullopt\n     */\n\
    \    optional<vector<int>> sort() const {\n        const int n = arcs.size();\n\
    \        vector<int> in_degree(n, 0);\n        for (const auto &targets: arcs)\
    \ {\n            for (const int y: targets) ++in_degree[y];\n        }\n\n   \
    \     vector<int> order;\n        order.reserve(n);\n        for (int x = 0; x\
    \ < n; ++x) {\n            if (in_degree[x] == 0) order.push_back(x);\n      \
    \  }\n\n        // order[i] \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D,\
    \ \u65B0\u305F\u306B\u5165\u6B21\u6570\u304C 0 \u306B\u306A\u308B\u9802\u70B9\u306F\
    \ order[i] \u306E\u51FA\u8FD1\u508D\u306E\u307F\n        for (int i = 0; i < (int)order.size();\
    \ ++i) {\n            for (const int y: arcs[order[i]]) {\n                if\
    \ (--in_degree[y] == 0) order.push_back(y);\n            }\n        }\n\n    \
    \    if ((int)order.size() < n) return nullopt;\n        return order;\n    }\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5\u304CDAG (\u6709\u5411\u975E\u5DE1\
    \u56DE\u30B0\u30E9\u30D5) \u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n     * @return true DAG\u3067\u3042\u308B\n     * @return false DAG\u3067\u306A\
    \u3044 (\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B)\n     */\n    bool is_DAG()\
    \ const { return sort() != nullopt; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Others/Topological_Sort.hpp
  requiredBy: []
  timestamp: '2026-10-20 23:23:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/Topological_Sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---

## Outline

有向グラフ $D = (V , A)$ のトポロジカルソートを求める. また, $D$ が DAG かどうかを判定する.

実装は DFS (深さ優先探索) に基づき, 計算量は頂点数 $n$, 弧数 $m$ に対して $O(n + m)$ である.

## Theory

<div class="definition" markdown="1">

定義 1
---

$D = (V, A)$ を有向グラフとする. $D$ のトポロジカルソートとは, 以下を満たす $V$ 上の順序関係 $\leq$ のことである.

* $\leq$ は全順序関係である.
* 任意の $\overrightarrow{uv} \in A$ に対して, $u < v ~(\Leftrightarrow u \leq v \land u \neq v)$ である.

</div>

<div class="definition" markdown="1">

定義 2
---

$D = (V, A)$ を有向グラフとする. $D$ 内に回路を含まないとき, $D$ は有向非巡回グラフ (DAG) であるという.

</div>

<div class="proposition" markdown="1">

命題 3
---

有向グラフ $D = (V, A)$ は $V \neq \emptyset$ であり, DAG であるとする. このとき, 入近傍が存在しない頂点が存在する.

</div>

<div class="proof" markdown="1">

証明
---

背理法で示す. 全ての頂点に入近傍が存在するとする.

$v_0 \in V$ を固定する. このとき, 次のようにして $V$ 上の列 $v_0, v_1, v_2, \dots$ を取ることができる.

* $v_i$ の入近傍を $1$ つ選び, $v_{i+1}$ とする. すなわち, $\overrightarrow{v_{i+1} v_i} \in A$ である.

$D$ の位数を $n$ とすると, 鳩ノ巣原理により, $v_0, v_1, v_2, \dots, v_n$ の中に重複が存在する. その重複を $v_l = v_r ~ (0 \leq l < r \leq n)$ とする.

すると, 各 $i$ について $\overrightarrow{v_{i+1} v_i} \in A$ なので,

$$ v_r, v_{r-1}, \dots, v_l (= v_r) $$

は $D$ 上の回路になり, $D$ が DAG であることに矛盾する.

よって, $D$ には入近傍が存在しない頂点が存在する.

</div>

<div class="theorem" markdown="1">

定理 4
---

有向グラフ $D = (V, A)$ について, 以下は同値である.

* (a) $D$ はトポロジカルソートを持つ.
* (b) $D$ は DAG である.

</div>

<div class="proof" markdown="1">

証明
---

**(a) ならば (b)**

対偶を示す. $D$ が DAG でないとする. このとき, $D$ 上の回路 $v_1, v_2, \dots, v_k, v_1 ~ (k \geq 1)$ が存在する. ここで, $v_{k+1} = v_1$ とおく.

$D$ がトポロジカルソート $\leq$ を持つと仮定する. $\overrightarrow{v_i v_{i+1}} \in A ~ (1 \leq i \leq k)$ なので, 定義 1 より

$$ v_1 < v_2 < \dots < v_k < v_{k+1} = v_1 $$

である. ここで, $<$ は推移的である. 実際, $u < v < w$ とすると, 推移律より $u \leq w$ である. もし $u = w$ ならば $u \leq v \leq u$ となり反対称律より $u = v$ となって $u \neq v$ に矛盾するので, $u \neq w$ すなわち $u < w$ である.

したがって $v_1 < v_1$ となるが, これは $v_1 \neq v_1$ を意味し矛盾する. (特に $k = 1$, つまり自己ループの場合は, $\overrightarrow{v_1 v_1} \in A$ から直ちに $v_1 < v_1$ となり矛盾する.)

よって, $D$ はトポロジカルソートを持たない.

**(b) ならば (a)**

$D$ の位数 $n$ に関する数学的帰納法で示す.

$n = 1$ のとき: $D$ は DAG なので自己ループを持たず, 弧は存在しない. よって, $V$ 上の唯一の全順序がトポロジカルソートである.

$n$ のときに成立するとする. $D$ の位数が $n+1$ であり, DAG であるとする. 命題 3 より, $D$ には入近傍が存在しない頂点 $x$ が存在する.

$D$ から $x$ と $x$ に接続する弧を除いた有向グラフを $D'$ とする. $D'$ の位数は $n$ である. また, $D'$ 上の回路は $D$ 上の回路でもあるので, $D'$ は DAG である. よって, 数学的帰納法の仮定により, $D'$ にはトポロジカルソート $\leq'$ が存在する.

$\leq'$ を使って, $V$ 上の関係 $\leq$ を次のように定義する.

* $u, v \in V$ に対して, 以下のうちのいずれかを満たすとき, そしてその時に限り $u \leq v$ とする.
  * $u = x$.
  * $u, v \neq x$ であり, $u \leq' v$.

この $\leq$ が $D$ のトポロジカルソートであることを示す.

* 反射律: $u = x$ ならば $u \leq u$. $u \neq x$ ならば $\leq'$ の反射律より $u \leq u$.
* 反対称律: $u \leq v$ かつ $v \leq u$ とする. $u = x$ ならば, $v \leq x$ より $v = x$ なので $u = v$. $v = x$ の場合も同様. $u, v \neq x$ ならば, $u \leq' v$ かつ $v \leq' u$ なので $u = v$.
* 推移律: $u \leq v$ かつ $v \leq w$ とする. $u = x$ ならば $u \leq w$. $u \neq x$ ならば, $u \leq v$ より $v \neq x$ であり, さらに $v \leq w$ より $w \neq x$ である. よって $u \leq' v \leq' w$ なので $u \leq w$.
* 全順序性: $u = x$ または $v = x$ ならば, $u \leq v$ または $v \leq u$ が成り立つ. $u, v \neq x$ ならば, $\leq'$ が全順序なので $u \leq' v$ または $v \leq' u$ である.
* 弧の条件: $\overrightarrow{uv} \in A$ とする. $x$ には入近傍が存在しないので $v \neq x$ である. $u = x$ ならば, $x \leq v$ かつ $x \neq v$ なので $u < v$. $u \neq x$ ならば, $\overrightarrow{uv}$ は $D'$ の弧であり, $\leq'$ の性質から $u <' v$ なので, $u \leq v$ かつ $u \neq v$ すなわち $u < v$.

以上より, $\leq$ は $D$ のトポロジカルソートである.

</div>

定理 4 より, $D$ が DAG であることと $D$ がトポロジカルソートを持つことは同値である. よって, トポロジカルソートの存在判定がそのまま DAG 判定になる.

また, 定理 4 の (b) ⇒ (a) の証明は構成的であり, 入近傍のない頂点を $1$ 個ずつ取り除いていくことでトポロジカルソートを構築できる. 途中で入近傍のない頂点がなくなったのに頂点が残っている場合, 残りの部分は命題 3 より DAG ではないので, $D$ は DAG ではない.

頂点 $x$ を取り除いたとき, 新たに入近傍がなくなりうる頂点は $x$ の出近傍に限られる. そこで各頂点の入次数を管理し, $x$ の出近傍の入次数を $1$ ずつ減らして, $0$ になった頂点を次の候補に加える. 各頂点・各弧は高々 $1$ 回ずつしか処理されないので, 位数 $n$, 大きさ $m$ の有向グラフに対して $O(n+m)$ 時間でトポロジカルソートを構築できる.

<div class="proposition" markdown="1">

命題 5
---

有向グラフ $D = (V, A)$ と $S, T \subseteq V$ に対して, 次の $2$ つの有向グラフを考える.

* $D^+ = (V, A^+)$: $A^+ = A \cup \lbrace \overrightarrow{st} \mid s \in S, t \in T \rbrace$ とする.
* $D^x = (V \cup \lbrace x \rbrace, A^x)$: $x \notin V$ を新しい頂点として, $A^x = A \cup \lbrace \overrightarrow{sx} \mid s \in S \rbrace \cup \lbrace \overrightarrow{xt} \mid t \in T \rbrace$ とする.

このとき, 以下が成り立つ.

* (1) $D^x$ のトポロジカルソート $\leq$ を $V$ に制限したものは, $D^+$ のトポロジカルソートである.
* (2) $D^+$ がトポロジカルソートを持つならば, $D^x$ もトポロジカルソートを持つ.
* (3) $D^+$ が DAG であることと $D^x$ が DAG であることは同値である.

</div>

<div class="proof" markdown="1">

証明
---

**(1)**

$\leq$ を $D^x$ のトポロジカルソートとし, $V$ への制限を $\leq_V$ とする. 全順序を制限したものは全順序である. $\overrightarrow{uv} \in A^+$ とする.

* $\overrightarrow{uv} \in A$ のとき: $\overrightarrow{uv} \in A^x$ なので $u < v$ である.
* $u \in S$ かつ $v \in T$ のとき: $\overrightarrow{ux}, \overrightarrow{xv} \in A^x$ なので $u < x < v$ である. 推移律より $u \leq v$ であり, もし $u = v$ ならば $u \leq x \leq u$ から $u = x$ となって $u \neq x$ に矛盾する. よって $u < v$ である.

よって, $\leq_V$ は $D^+$ のトポロジカルソートである.

**(2)**

$\leq$ を $D^+$ のトポロジカルソートとする. $S, T$ の任意の元 $s \in S, t \in T$ について $\overrightarrow{st} \in A^+$ なので $s < t$ である.

$V \cup \lbrace x \rbrace$ 上の関係 $\leq^x$ を, $x$ を $S$ の最大元の直後に挿入することで, 次のように定める. $u, v \in V$ に対して $u \leq^x v \iff u \leq v$ とし, $x$ との比較は以下で定める.

* $S = \emptyset$ のとき: 任意の $u \in V$ について $x \leq^x u$ (つまり $x$ を最小の元とする).
* $S \neq \emptyset$ のとき: $s_0 = \max S$ として, $u \in V$ について $u \leq^x x \iff u \leq s_0$, $x \leq^x u \iff s_0 < u$ (つまり $x$ を $s_0$ の直後に置く).

これは, 全順序 $\leq$ において $s_0$ とその次の元の間に $x$ を挿入したものなので, 全順序である. また, $A$ の弧については $\leq$ と同じ順序なので条件を満たす. さらに,

* 任意の $s \in S$ について, $s \leq s_0 < x$ なので $s < x$ である.
* 任意の $t \in T$ について, $S = \emptyset$ ならば $x < t$ である. $S \neq \emptyset$ ならば $s_0 < t$ であり, $x$ は $s_0$ の直後なので $x < t$ である.

よって, $\leq^x$ は $D^x$ のトポロジカルソートである.

**(3)**

$D^+$ が DAG ならば, 定理 4 より $D^+$ はトポロジカルソートを持つので, (2) より $D^x$ もトポロジカルソートを持ち, 定理 4 より $D^x$ は DAG である. 逆に, $D^x$ が DAG ならば, 定理 4 より $D^x$ はトポロジカルソートを持つので, (1) より $D^+$ もトポロジカルソートを持ち, 定理 4 より $D^+$ は DAG である.

</div>

命題 5 は, `add_arc_multiple` の理論的な裏付けである. `sources` を $S$, `targets` を $T$ とすると, $D^+$ は $S$ の各頂点から $T$ の各頂点へ弧を直接張ったグラフ, $D^x$ は `add_arc_multiple` が実際に作る (新しい頂点 $x$ を経由する) グラフに対応する. 命題 5 より, 弧を $\lvert S \rvert \times \lvert T \rvert$ 本張る代わりに $\lvert S \rvert + \lvert T \rvert$ 本で済ませても, DAG かどうかの判定は変わらない. また, $D^x$ のトポロジカルソートから $x$ を取り除けば, $D^+$ のトポロジカルソートが得られる.

なお, 命題 5 では自己ループも通常の弧として扱う. $S \cap T \neq \emptyset$ のとき, $D^+$ は自己ループを, $D^x$ は $s \to x \to s$ という閉路を持つので, どちらも DAG ではない. これは `ignore_self_loop` = `false` の場合に対応し, `ignore_self_loop` = `true` の場合も `add_arc_multiple` では閉路が残るため `sort` は `nullopt` を返す.

## Contents

### Constructor

```cpp
Topological_Sort(int n, bool ignore_self_loop = true)
```

* $n$ 頂点の空有向グラフを生成する.
* **引数**
  * `ignore_self_loop`: 自己ループを無視するか?
    * `true` (既定値) のとき, `add_arc` で追加される自己ループは無視される. つまり, 自己ループは順序の制約に影響しないものとして扱う.
    * `false` のとき, 自己ループは通常の弧として追加される. 定義 1 より自己ループを持つ有向グラフはトポロジカルソートを持たないので, `sort` は `nullopt` を返す.

### add_arc

```cpp
void add_arc(const int source, const int target)
```

* 弧 $\overrightarrow{st}$ を追加する. ただし, $s = t$ かつ `ignore_self_loop` = `true` のときは何もしない.

### add_arc_multiple

```cpp
int add_arc_multiple(const vector<int> sources, const vector<int> targets)
```

* `sources` の各頂点から `targets` の各頂点への弧を追加する.
* 新しい頂点 $x$ を $1$ 個追加し, `sources` の各頂点から $x$ へ, $x$ から `targets` の各頂点へ弧を張ることで実現する. これにより, 弧の本数は $\lvert \mathrm{sources} \rvert \times \lvert \mathrm{targets} \rvert$ 本ではなく $\lvert \mathrm{sources} \rvert + \lvert \mathrm{targets} \rvert$ 本で済む.
  * 命題 5 より, この方法でも DAG かどうかの判定は変わらず, 結果から $x$ を取り除けば直接弧を張った場合のトポロジカルソートが得られる.
* **返り値**
  * 追加された頂点 $x$ の番号が返ってくる.
* **注意**
  * $x$ は `sort` の結果にも現れる.
  * `sources` と `targets` に共通する頂点 $s$ があると, $s \to x \to s$ という閉路ができるので, `ignore_self_loop` の設定にかかわらず `sort` は `nullopt` を返す.

### add_vertex

```cpp
int add_vertex()
```

* 頂点を $1$ 個追加する.
* **返り値**
  * 追加された頂点の番号.

### sort

```cpp
optional<vector<int>> sort() const
```

* トポロジカルソートを求める.
* **返り値**
  * DAG の場合は, 全ての弧 $\overrightarrow{uv}$ について $u$ が $v$ より前に来るように並べた頂点列 (トポロジカルソートで小さい順).
  * DAG でない場合は `nullopt`.
* **計算量**
  * $O(n + m)$

### is_DAG

```cpp
bool is_DAG() const
```

* $D$ が DAG かどうかを判定する.
* **返り値**
  * DAG ならば `true`, そうでなければ `false`.
* **計算量**
  * $O(n + m)$

## History

|日付|内容|
|:---:|:---:|
|2026/10/20|`self_loop` を `ignore_self_loop` に改名 <br> トポロジカルソートの構築アルゴリズムを Kahn 法に変更|
|2026/01/31|トポロジカルソートの実装|

