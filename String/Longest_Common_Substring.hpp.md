---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/Longest_Common_Prefix.hpp
    title: "Longest Common Prefix (\u63A5\u5C3E\u8F9E\u306B\u304A\u3051\u308B\u6700\
      \u9577\u5171\u901A\u63A5\u982D\u8F9E)"
  - icon: ':heavy_check_mark:'
    path: String/Suffix_Array.hpp
    title: "Suffix Array (\u63A5\u5C3E\u8F9E\u914D\u5217)"
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
    path: verify/yosupo_library_checker/string/Longest_Common_Substring.test.cpp
    title: verify/yosupo_library_checker/string/Longest_Common_Substring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2\u3064\u306E\u914D\u5217\u306E\u6700\u9577\u5171\u901A\u9023\
      \u7D9A\u90E8\u5206\u5217\uFF08LCS\uFF09\u3092\u6C42\u3081\u308B."
    links: []
  bundledCode: "#line 2 \"String/Longest_Common_Substring.hpp\"\n\n#line 2 \"String/Longest_Common_Prefix.hpp\"\
    \n\n#line 2 \"String/Suffix_Array.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
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
    \n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n//\
    \ a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
    \u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename\
    \ U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n\
    }\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T,\
    \ typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a = b,\
    \ 1: 0);\n}\n\n// a \u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B.\n\
    template<typename T>\ninline T max(const vector<T> &a){\n    if (a.empty()) throw\
    \ invalid_argument(\"vector is empty.\");\n\n    return *max_element(a.begin(),\
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
    \ get_bits(x, bit_length(x)); }\n#line 73 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 4 \"String/Suffix_Array.hpp\"\
    \n\n/**\n * @brief Suffix Array \u3092\u69CB\u7BC9\u3059\u308B.\n * \n * \u30C0\
    \u30D6\u30EA\u30F3\u30B0\u3068\u57FA\u6570\u30BD\u30FC\u30C8\u3092\u7528\u3044\
    \u3066 O(N log N) \u3067\u69CB\u7BC9\u3059\u308B.\n * \u8FD4\u308A\u5024 sa \u306F\
    , sa[i] \u304C\u300C\u8F9E\u66F8\u9806\u3067 i \u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u63A5\u5C3E\u8F9E\u306E\u958B\u59CB\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u300D\
    \u3068\u306A\u308B\u3088\u3046\u306A\u30B5\u30A4\u30BA N \u306E\u914D\u5217.\n\
    \ * \u7A7A\u6587\u5B57\u5217\uFF08\u756A\u5175\uFF09\u306F\u5185\u90E8\u7684\u306A\
    \u69CB\u7BC9\u904E\u7A0B\u3067\u306E\u307F\u5229\u7528\u3055\u308C\u3001\u8FD4\
    \u308A\u5024\u306B\u306F\u542B\u307E\u308C\u306A\u3044.\n * \n * @tparam T \u914D\
    \u5217\u306E\u8981\u7D20\u306E\u578B. std::integral \u30B3\u30F3\u30BB\u30D7\u30C8\
    \u3092\u6E80\u305F\u3059\u5FC5\u8981\u304C\u3042\u308B.\n * @param A \u69CB\u7BC9\
    \u5BFE\u8C61\u306E\u914D\u5217\n * @return vector<int> \u69CB\u7BC9\u3055\u308C\
    \u305F Suffix Array\n */\ntemplate<integral T>\nvector<int> Suffix_Array(const\
    \ vector<T> &A) {\n    int n = A.size();\n    // \u7A7A\u6587\u5B57\u5217\uFF08\
    \u756A\u5175\uFF09\u3092\u542B\u3081\u305F\u30B5\u30A4\u30BA n+1 \u3067\u7BA1\u7406\
    \n    vector<int> suffix_array(n + 1);\n    vector<int> rank(n + 1);     // \u5404\
    \u63A5\u5C3E\u8F9E\u306E\u73FE\u5728\u306E\u30E9\u30F3\u30AF\n    vector<int>\
    \ tmp_sa(n + 1);\n    vector<int> tmp_rank(n + 1);\n\n    // 1\u6587\u5B57\u76EE\
    \u306B\u3088\u308B\u521D\u671F\u30BD\u30FC\u30C8\n    iota(suffix_array.begin(),\
    \ suffix_array.end(), 0);\n    sort(suffix_array.begin(), suffix_array.end(),\
    \ [&](int i, int j) {\n        // \u756A\u5175 (index n) \u3092\u6700\u5C0F\u3068\
    \u3057\u3066\u6271\u3046\n        if (i == n) return true;\n        if (j == n)\
    \ return false;\n        return A[i] < A[j];\n    });\n\n    rank[suffix_array[0]]\
    \ = 0;\n    int r = 0;\n    for (int i = 1; i <= n; ++i) {\n        if (suffix_array[i\
    \ - 1] == n || (suffix_array[i] != n && A[suffix_array[i - 1]] < A[suffix_array[i]]))\
    \ r++;\n        rank[suffix_array[i]] = r;\n    }\n    \n    // \u30C0\u30D6\u30EA\
    \u30F3\u30B0: \u9577\u3055 k \u306E\u6BD4\u8F03\u7D50\u679C\u304B\u3089\u9577\u3055\
    \ 2k \u306E\u6BD4\u8F03\u7D50\u679C\u3092\u5C0E\u51FA\u3059\u308B\n    for (int\
    \ k = 1; k <= n; k <<= 1) {\n        // \u7B2C2\u30AD\u30FC (rank[i+k]) \u306B\
    \u57FA\u3065\u3044\u3066 tmp_sa \u3092\u69CB\u6210\n        int it = 0;\n    \
    \    // \u5F8C\u534A\u90E8\u5206\u304C\u5B58\u5728\u3057\u306A\u3044 (i+k > n)\
    \ \u63A5\u5C3E\u8F9E\u304C\u6700\u5C0F\n        for (int i = n - k + 1; i <= n;\
    \ ++i) tmp_sa[it++] = i;\n        // \u305D\u308C\u4EE5\u5916\u3092\u76F4\u524D\
    \u306E suffix_array \u306E\u9806\u5E8F\uFF08\u9577\u3055 k \u3067\u306E\u9806\u5E8F\
    \uFF09\u3092\u5229\u7528\u3057\u3066\u4E26\u3079\u308B\n        for (int i = 0;\
    \ i <= n; ++i) {\n            if (suffix_array[i] >= k) tmp_sa[it++] = suffix_array[i]\
    \ - k;\n        }\n\n        // \u7B2C1\u30AD\u30FC (rank[i]) \u306B\u57FA\u3065\
    \u3044\u3066\u8A08\u6570\u30BD\u30FC\u30C8\uFF08Counting Sort\uFF09\u3092\u884C\
    \u3046\n        // \u3053\u308C\u306B\u3088\u308A (rank[i], rank[i+k]) \u306E\u30DA\
    \u30A2\u3067\u30BD\u30FC\u30C8\u3057\u305F\u3053\u3068\u306B\u306A\u308B\n   \
    \     vector<int> cnt(r + 1, 0);\n        for (int i = 0; i <= n; ++i) cnt[rank[i]]++;\n\
    \        for (int i = 1; i <= r; ++i) cnt[i] += cnt[i - 1];\n        // \u5B89\
    \u5B9A\u30BD\u30FC\u30C8\u3092\u7DAD\u6301\u3059\u308B\u305F\u3081\u5F8C\u308D\
    \u304B\u3089\u8D70\u67FB\n        for (int i = n; i >= 0; --i) suffix_array[--cnt[rank[tmp_sa[i]]]]\
    \ = tmp_sa[i];\n\n        tmp_rank[suffix_array[0]] = 0;\n        r = 0;\n   \
    \     auto first = [&](int idx) { return rank[idx]; };\n        auto second =\
    \ [&](int idx) { return (idx + k <= n) ? rank[idx + k] : -1; };\n        for (int\
    \ i = 1; i <= n; ++i) {\n            // \u524D\u306E\u8981\u7D20\u3068 (\u7B2C\
    1\u30AD\u30FC, \u7B2C2\u30AD\u30FC) \u306E\u30DA\u30A2\u304C\u7570\u306A\u308B\
    \u5834\u5408\u306B\u30E9\u30F3\u30AF\u3092\u4E0A\u3052\u308B\n            unless\
    \ (first(suffix_array[i - 1]) == first(suffix_array[i]) && second(suffix_array[i\
    \ - 1]) == second(suffix_array[i])) r++;\n            tmp_rank[suffix_array[i]]\
    \ = r;\n        }\n        rank = tmp_rank;\n        // \u3059\u3079\u3066\u306E\
    \u30E9\u30F3\u30AF\u304C\u7570\u306A\u308C\u3070\uFF08\u4E00\u610F\u306B\u5B9A\
    \u307E\u308C\u3070\uFF09\u7D42\u4E86\n        if (r == n) break;\n    }\n\n  \
    \  // \u5148\u982D\u306E\u756A\u5175 (n) \u3092\u524A\u9664\n    suffix_array.erase(suffix_array.begin());\n\
    \n    return suffix_array;\n}\n\n/**\n * @brief \u6574\u6570\u578B\u4EE5\u5916\
    \u306E\u8981\u7D20\u3092\u6301\u3064\u914D\u5217\u306B\u5BFE\u3057\u3066 Suffix\
    \ Array \u3092\u69CB\u7BC9\u3059\u308B.\n *\n * \u5185\u90E8\u3067\u5EA7\u6A19\
    \u5727\u7E2E\u3092\u884C\u3044, \u6574\u6570\u578B\u306E Suffix Array \u69CB\u7BC9\
    \u95A2\u6570\u3092\u547C\u3073\u51FA\u3059.\n * \u8A08\u7B97\u91CF\u306F\u5EA7\
    \u6A19\u5727\u7E2E\u3092\u542B\u3081\u3066 O(N log N) \u3068\u306A\u308B.\n *\n\
    \ * @tparam T \u914D\u5217\u306E\u8981\u7D20\u306E\u578B. !std::integral \u304B\
    \u3064 std::totally_ordered \u30B3\u30F3\u30BB\u30D7\u30C8\u3092\u6E80\u305F\u3059\
    \u5FC5\u8981\u304C\u3042\u308B.\n * @param A \u69CB\u7BC9\u5BFE\u8C61\u306E\u914D\
    \u5217\n * @return vector<int> Suffix Array\n */\ntemplate<typename T>\nrequires\
    \ (!integral<T> && totally_ordered<T>)\nvector<int> Suffix_Array(const vector<T>\
    \ &A) {\n    int n = A.size();\n\n    vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int i, int j) { return\
    \ A[i] < A[j]; });\n\n    vector<int> B(n);\n    int r = 0;\n    for (int i =\
    \ 0; i < n; ++i) {\n        if (i > 0 && A[idx[i - 1]] < A[idx[i]]) r++;\n   \
    \     B[idx[i]] = r;\n    }\n    return Suffix_Array<int>(B);\n}\n\n/**\n * @brief\
    \ \u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066 Suffix Array \u3092\u69CB\u7BC9\u3059\
    \u308B.\n *\n * \u5185\u90E8\u3067 vector<char> \u306B\u5909\u63DB\u3057\u3066\
    \u51E6\u7406\u3092\u884C\u3046\u30E9\u30C3\u30D7\u95A2\u6570.\n *\n * @param S\
    \ \u69CB\u7BC9\u5BFE\u8C61\u306E\u6587\u5B57\u5217\n * @return vector<int> Suffix\
    \ Array\n */\nvector<int> Suffix_Array(const string &S) {\n    return Suffix_Array<char>(vector<char>(S.begin(),\
    \ S.end()));\n}\n#line 4 \"String/Longest_Common_Prefix.hpp\"\n\ntemplate<integral\
    \ T>\nvector<int> Longest_Common_Prefix(const vector<T> &A, const vector<int>\
    \ &sa) {\n    int n = A.size();\n    if (n <= 1) return {};\n    vector<int> rank(n);\n\
    \    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n\n    vector<int> lcp(n - 1);\n\
    \    int h = 0;\n    for (int i = 0; i < n; ++i) {\n        if (rank[i] == n -\
    \ 1) continue;\n\n        int j = sa[rank[i] + 1];\n        while (i + h < n &&\
    \ j + h < n && A[i + h] == A[j + h]) h++;\n\n        lcp[rank[i]] = h;\n\n   \
    \     if (h > 0) h--;\n    }\n\n    return lcp;\n}\n\ntemplate<integral T>\nvector<int>\
    \ Longest_Common_Prefix(const vector<T> &A) {\n    return Longest_Common_Prefix(A,\
    \ Suffix_Array(A));\n}\n\ntemplate<typename T>\nrequires (!integral<T> && totally_ordered<T>)\n\
    vector<int> Longest_Common_Prefix(const vector<T> &A) {\n    int n = A.size();\n\
    \    vector<int> idx(n);\n    iota(idx.begin(), idx.end(), 0);\n    sort(idx.begin(),\
    \ idx.end(), [&](int i, int j) { return A[i] < A[j]; });\n\n    vector<int> B(n);\n\
    \    int r = 0;\n    for (int i = 0; i < n; ++i) {\n        if (i > 0 && A[idx[i\
    \ - 1]] < A[idx[i]]) r++;\n        B[idx[i]] = r;\n    }\n    return Longest_Common_Prefix<int>(B);\n\
    }\n\nvector<int> Longest_Common_Prefix(const string &S) {\n    return Longest_Common_Prefix<char>(vector<char>(S.begin(),\
    \ S.end()));\n}\n#line 4 \"String/Longest_Common_Substring.hpp\"\n\n/**\n * @brief\
    \ 2\u3064\u306E\u914D\u5217\u306E\u6700\u9577\u5171\u901A\u9023\u7D9A\u90E8\u5206\
    \u5217\uFF08LCS\uFF09\u3092\u6C42\u3081\u308B.\n * \n * \u63A5\u5C3E\u8F9E\u914D\
    \u5217\uFF08Suffix Array\uFF09\u3068 LCP \u914D\u5217\u3092\u7528\u3044\u3066\
    \ O((N+M) log (N+M)) \u3067\u8A08\u7B97\u3059\u308B.\n * \n * @tparam T \u914D\
    \u5217\u306E\u8981\u7D20\u306E\u578B. std::totally_ordered \u3092\u6E80\u305F\u3059\
    \u5FC5\u8981\u304C\u3042\u308B.\n * @param A 1\u3064\u76EE\u306E\u914D\u5217\n\
    \ * @param B 2\u3064\u76EE\u306E\u914D\u5217\n * @return tuple<int, int, int,\
    \ int> {A\u5185\u306E\u958B\u59CB\u4F4D\u7F6E, A\u5185\u306E\u7D42\u4E86\u4F4D\
    \u7F6E(inclusive), B\u5185\u306E\u958B\u59CB\u4F4D\u7F6E, B\u5185\u306E\u7D42\u4E86\
    \u4F4D\u7F6E(inclusive)}\n *         \u5171\u901A\u90E8\u5206\u304C\u306A\u3044\
    \u5834\u5408\u306F {0, -1, 0, -1} \u3092\u8FD4\u3059.\n */\ntemplate<totally_ordered\
    \ T>\ntuple<int, int, int, int> Longest_Common_Continuous_Subsequence(const vector<T>\
    \ &A, const vector<T> &B) {\n    int n = A.size(), m = B.size();\n\n    // Step\
    \ I: A \u3068 B \u306E\u8981\u7D20\u3092\u5408\u308F\u305B\u3066\u5EA7\u6A19\u5727\
    \u7E2E\u3092\u884C\u3046\n    vector<T> coords;\n    coords.reserve(n + m);\n\
    \    for (const T &a : A) coords.push_back(a);\n    for (const T &b : B) coords.push_back(b);\n\
    \    sort(coords.begin(), coords.end());\n    coords.erase(unique(coords.begin(),\
    \ coords.end()), coords.end());\n\n    // Step II: \u5EA7\u6A19\u5727\u7E2E\u5F8C\
    \u306E\u6574\u6570\u5217\u3092\u751F\u6210\n    vector<int> C;\n    C.reserve(n\
    \ + m + 1);\n\n    for (const T &a : A) {\n        C.push_back(lower_bound(coords.begin(),\
    \ coords.end(), a) - coords.begin());\n    }\n\n    int sentinel = coords.size();\
    \ // \u756A\u5175\n    C.push_back(sentinel); // A \u3068 B \u3092\u533A\u5207\
    \u308B\u756A\u5175\n\n    for (const auto &b : B) {\n        C.push_back(lower_bound(coords.begin(),\
    \ coords.end(), b) - coords.begin());\n    }\n\n    // Step III: LCP \u3092\u8A08\
    \u7B97\n    vector<int> suffix_array = Suffix_Array(C);\n    vector<int> lcp =\
    \ Longest_Common_Prefix(C, suffix_array);\n\n    // Step IV: SA \u306B\u304A\u3051\
    \u308B\u7531\u6765\u304C\u7570\u306A\u308B\u90E8\u5206\u306B\u304A\u3051\u308B\
    \ LCP \u304C LCS \u306B\u306A\u308B.\n\n    // x \u756A\u76EE\u306E SA \u304C\
    \ A \u7531\u6765\u306A\u3089\u3070 true, B \u7531\u6765\u306A\u3089\u3070 false\n\
    \    auto belong = [&](const int x) -> bool { return suffix_array[x] < n; };\n\
    \n    int a = 0, b = -1, c = 0, d = -1, length = 0;\n    for (int i = 0; i < n\
    \ + m; ++i) {\n        if (suffix_array[i] == n) continue;\n        if (belong(i)\
    \ == belong(i + 1)) continue;\n        unless(chmax(length, lcp[i])) continue;\n\
    \n        int ia = belong(i) ? i : i + 1;\n        int ic = belong(i) ? i + 1\
    \ : i;\n\n        a = suffix_array[ia];\n        b = a + length - 1;\n       \
    \ c = suffix_array[ic] - (n + 1);\n        d = c + length - 1;\n    }\n\n    return\
    \ {a, b, c, d};\n}\n\n/**\n * @brief 2\u3064\u306E\u6587\u5B57\u5217\u306E\u6700\
    \u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217\uFF08LCS\uFF09\u3092\u6C42\u3081\
    \u308B.\n * \n * @param S 1\u3064\u76EE\u306E\u6587\u5B57\u5217\n * @param T 2\u3064\
    \u76EE\u306E\u6587\u5B57\u5217\n * @return tuple<int, int, int, int> {S\u5185\u306E\
    \u958B\u59CB\u4F4D\u7F6E, S\u5185\u306E\u7D42\u4E86\u4F4D\u7F6E(inclusive), T\u5185\
    \u306E\u958B\u59CB\u4F4D\u7F6E, T\u5185\u306E\u7D42\u4E86\u4F4D\u7F6E(inclusive)}\n\
    \ */\ntuple<int, int, int, int> Longest_Common_Substring(const string &S, const\
    \ string &T) {\n    return Longest_Common_Continuous_Subsequence<char>(vector<char>(S.begin(),\
    \ S.end()), vector<char>(T.begin(), T.end()));\n}\n"
  code: "#pragma once\n\n#include \"Longest_Common_Prefix.hpp\"\n\n/**\n * @brief\
    \ 2\u3064\u306E\u914D\u5217\u306E\u6700\u9577\u5171\u901A\u9023\u7D9A\u90E8\u5206\
    \u5217\uFF08LCS\uFF09\u3092\u6C42\u3081\u308B.\n * \n * \u63A5\u5C3E\u8F9E\u914D\
    \u5217\uFF08Suffix Array\uFF09\u3068 LCP \u914D\u5217\u3092\u7528\u3044\u3066\
    \ O((N+M) log (N+M)) \u3067\u8A08\u7B97\u3059\u308B.\n * \n * @tparam T \u914D\
    \u5217\u306E\u8981\u7D20\u306E\u578B. std::totally_ordered \u3092\u6E80\u305F\u3059\
    \u5FC5\u8981\u304C\u3042\u308B.\n * @param A 1\u3064\u76EE\u306E\u914D\u5217\n\
    \ * @param B 2\u3064\u76EE\u306E\u914D\u5217\n * @return tuple<int, int, int,\
    \ int> {A\u5185\u306E\u958B\u59CB\u4F4D\u7F6E, A\u5185\u306E\u7D42\u4E86\u4F4D\
    \u7F6E(inclusive), B\u5185\u306E\u958B\u59CB\u4F4D\u7F6E, B\u5185\u306E\u7D42\u4E86\
    \u4F4D\u7F6E(inclusive)}\n *         \u5171\u901A\u90E8\u5206\u304C\u306A\u3044\
    \u5834\u5408\u306F {0, -1, 0, -1} \u3092\u8FD4\u3059.\n */\ntemplate<totally_ordered\
    \ T>\ntuple<int, int, int, int> Longest_Common_Continuous_Subsequence(const vector<T>\
    \ &A, const vector<T> &B) {\n    int n = A.size(), m = B.size();\n\n    // Step\
    \ I: A \u3068 B \u306E\u8981\u7D20\u3092\u5408\u308F\u305B\u3066\u5EA7\u6A19\u5727\
    \u7E2E\u3092\u884C\u3046\n    vector<T> coords;\n    coords.reserve(n + m);\n\
    \    for (const T &a : A) coords.push_back(a);\n    for (const T &b : B) coords.push_back(b);\n\
    \    sort(coords.begin(), coords.end());\n    coords.erase(unique(coords.begin(),\
    \ coords.end()), coords.end());\n\n    // Step II: \u5EA7\u6A19\u5727\u7E2E\u5F8C\
    \u306E\u6574\u6570\u5217\u3092\u751F\u6210\n    vector<int> C;\n    C.reserve(n\
    \ + m + 1);\n\n    for (const T &a : A) {\n        C.push_back(lower_bound(coords.begin(),\
    \ coords.end(), a) - coords.begin());\n    }\n\n    int sentinel = coords.size();\
    \ // \u756A\u5175\n    C.push_back(sentinel); // A \u3068 B \u3092\u533A\u5207\
    \u308B\u756A\u5175\n\n    for (const auto &b : B) {\n        C.push_back(lower_bound(coords.begin(),\
    \ coords.end(), b) - coords.begin());\n    }\n\n    // Step III: LCP \u3092\u8A08\
    \u7B97\n    vector<int> suffix_array = Suffix_Array(C);\n    vector<int> lcp =\
    \ Longest_Common_Prefix(C, suffix_array);\n\n    // Step IV: SA \u306B\u304A\u3051\
    \u308B\u7531\u6765\u304C\u7570\u306A\u308B\u90E8\u5206\u306B\u304A\u3051\u308B\
    \ LCP \u304C LCS \u306B\u306A\u308B.\n\n    // x \u756A\u76EE\u306E SA \u304C\
    \ A \u7531\u6765\u306A\u3089\u3070 true, B \u7531\u6765\u306A\u3089\u3070 false\n\
    \    auto belong = [&](const int x) -> bool { return suffix_array[x] < n; };\n\
    \n    int a = 0, b = -1, c = 0, d = -1, length = 0;\n    for (int i = 0; i < n\
    \ + m; ++i) {\n        if (suffix_array[i] == n) continue;\n        if (belong(i)\
    \ == belong(i + 1)) continue;\n        unless(chmax(length, lcp[i])) continue;\n\
    \n        int ia = belong(i) ? i : i + 1;\n        int ic = belong(i) ? i + 1\
    \ : i;\n\n        a = suffix_array[ia];\n        b = a + length - 1;\n       \
    \ c = suffix_array[ic] - (n + 1);\n        d = c + length - 1;\n    }\n\n    return\
    \ {a, b, c, d};\n}\n\n/**\n * @brief 2\u3064\u306E\u6587\u5B57\u5217\u306E\u6700\
    \u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217\uFF08LCS\uFF09\u3092\u6C42\u3081\
    \u308B.\n * \n * @param S 1\u3064\u76EE\u306E\u6587\u5B57\u5217\n * @param T 2\u3064\
    \u76EE\u306E\u6587\u5B57\u5217\n * @return tuple<int, int, int, int> {S\u5185\u306E\
    \u958B\u59CB\u4F4D\u7F6E, S\u5185\u306E\u7D42\u4E86\u4F4D\u7F6E(inclusive), T\u5185\
    \u306E\u958B\u59CB\u4F4D\u7F6E, T\u5185\u306E\u7D42\u4E86\u4F4D\u7F6E(inclusive)}\n\
    \ */\ntuple<int, int, int, int> Longest_Common_Substring(const string &S, const\
    \ string &T) {\n    return Longest_Common_Continuous_Subsequence<char>(vector<char>(S.begin(),\
    \ S.end()), vector<char>(T.begin(), T.end()));\n}\n"
  dependsOn:
  - String/Longest_Common_Prefix.hpp
  - String/Suffix_Array.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: String/Longest_Common_Substring.hpp
  requiredBy: []
  timestamp: '2026-04-05 19:25:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/string/Longest_Common_Substring.test.cpp
documentation_of: String/Longest_Common_Substring.hpp
layout: document
title: "Longest Common Substring (\u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\
  \u5217)"
---

## Outline

列 $A, B$ における最長共通連続部分列を求める.

## Definition

列 $A, B$ に対して, $\operatorname{LCS}(A, B)$ を $A, B$ における最長共通部分文字列の長さと定義する.

## Theory

以下のように記号を定義する.

* 列 $A$ の長さを $N$, 列 $B$ の長さを $M$ とする.
* $A, B$ に含まれない要素を $\$$ として, $C := A \oplus \$ \oplus B$ とする.
* 接尾辞について, 以下のようにする.
  * $A$ における第 $i$ 接尾辞を $X_i$ とする.
  * $B$ における第 $j$ 接尾辞を $Y_j$ とする.
  * $C$ における第 $k$ 接尾辞を $Z_k$ とする.
* $C$ における接尾辞配列を $(C_1, \dots, C_{N+M+1})$ とする.
* $Z_{S_k}$ と $Z_{S_{k+1}}$ の最長共通接頭辞の長さを $L_k$ とする.

$1 \leq i \leq N, 1 \leq j \leq M$ に対して, $\operatorname{LCS}(X_i, Y_j)$ を求める.

$p, q$ を次のように定める.

$$ p \lt q, \quad \{ S_p, S_q \} = \{ i, j + N + 1 \}$$

このとき,

$$ \operatorname{LCS}(X_i, Y_j) = \operatorname{LCS}(Z_{S_p}, Z_{S_q}) = \min(L_p, \dots, L_{q-1}) $$

である.

ここで, $S_p, \dots, S_q$ の間には, 「$N$ 以下」と 「$(N+1)$ より大きい」が少なくとも $1$ つは含まれている. 特に, $p \leq k < q$ で $Z_{S_k}, Z_{S_{k+1}}$ のうち, 一方が $A$ 由来, 他方が $B$ 由来となるものがある. このとき,

$$ \operatorname{LCS}(X_i, Y_j) \leq L_k $$

である.

以上から, 以下を満たすもの $k$ についての総和を考えれば良いことになる.

* $Z_{S_k}, Z_{S_{k+1}}$ のうち, 一方が $A$ 由来, 他方が $B$ 由来となる $k$ における $L_k$.

計算量は最長共通接頭辞の計算量になるため, $O(N \log N)$ 時間である.

## Contents

### Longest_Common_Continuous_Subsequence
```cpp
template<totally_ordered T>
tuple<int, int, int, int> Longest_Common_Continuous_Subsequence(const vector<T> &A, const vector<T> &B)
```

* 全順序 $T$ 上の列 $A, B$ に対する最長共通連続部分列となる部分を求める.
* **返り値**
  * $(a, b, c, d)$ の形のタプル.
  * 以下を意味する.
    * $(A_a, \dots, A_b) = (B_c, \dots, B_d)$.
    * $(A_a, \dots, A_b)$ が最長共通部分列である.
* **計算量**: $N := \lvert A \rvert, M := \lvert B \rvert$ として, $O((N + M) \log (N + M))$ 時間.

### Longest_Common_Substring

```cpp
tuple<int, int, int, int> Longest_Common_Substring(const string &S, const string &T)
```

* 文字列 $S, T$ に対する最長共通部分文字列となる部分を求める.
* **返り値**
  * $(a, b, c, d)$ の形のタプル.
  * 以下を意味する.
    * $(S_a, \dots, S_b) = (T_c, \dots, T_d)$.
    * $(S_a, \dots, S_b)$ が最長共通部分文字列である.
* **計算量**: $N := \lvert S \rvert, M := \lvert T \rvert$ として, $O((N + M) \log (N + M))$ 時間.


## History

|日付|内容|
|:---:|:---|
|2026/04/05| Longest_Common_Continuous_Subsequence, Longest_Common_Substring 実装 |
