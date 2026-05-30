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
    path: verify/aizu_online_judge/dsl/5B.test.cpp
    title: verify/aizu_online_judge/dsl/5B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3057\u3066\u7D50\u679C\u3092\
      \u8FD4\u3059 (\u7D2F\u7A4D\u548C\u4F5C\u7528\u7D20 S \u306E\u9069\u7528)"
    links: []
  bundledCode: "#line 2 \"Imos/Imos_2.hpp\"\n\n#line 2 \"template/template.hpp\"\n\
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
    \ get_bits(x, bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\
    \u3093\u304B\u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\
    \u529B\u3059\u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x));\
    \ }\n#line 73 \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 4 \"Imos/Imos_2.hpp\"\n\n#line 7 \"Imos/Imos_2.hpp\"\n\ntemplate\
    \ <typename T>\nclass Imos_2 {\n    private:\n    // \u5DEE\u5206\u914D\u5217\
    \ (h+1 x w+1 \u306B\u3059\u308B\u3053\u3068\u3067\u5883\u754C\u5916\u53C2\u7167\
    \u3092\u56DE\u907F)\n    std::vector<std::vector<T>> lazy;\n    int h, w;\n\n\
    \    bool push(const int i, const int j, const T x) {\n        if (!(0 <= i &&\
    \ i <= h)) return false;\n        if (!(0 <= j && j <= w)) return false;\n\n \
    \       lazy[i][j] += x;\n        return true;\n    }\n\n    public:\n    Imos_2(const\
    \ int h, const int w): lazy(h + 1, std::vector<T>(w + 1, T())), h(h), w(w) {}\n\
    \n    // \u9589\u533A\u9593 [u, d] x [l, r] \u3078\u306E\u5024 x \u306E\u52A0\u7B97\
    \ (4\u70B9\u66F4\u65B0)\n    void add(int u, int d, int l, int r, const T x) {\n\
    \        // \u7BC4\u56F2\u306E\u6B63\u898F\u5316\n        u = std::max(0, u);\
    \ l = std::max(0, l);\n        d = std::min(h - 1, d); r = std::min(w - 1, r);\n\
    \        if (u > d || l > r) return;\n\n        push(u, l, x);\n        push(u,\
    \ r + 1, -x);\n        push(d + 1, l, -x);\n        push(d + 1, r + 1, x);\n \
    \   }\n\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u5024 1 \u3067\u306E\u52A0\u7B97\
    \n    void add(const int u, const int d, const int l, const int r) { \n      \
    \  add(u, d, l, r, T(1)); \n    }\n\n    /// @brief \u7D2F\u7A4D\u548C\u3092\u8A08\
    \u7B97\u3057\u3066\u7D50\u679C\u3092\u8FD4\u3059 (\u7D2F\u7A4D\u548C\u4F5C\u7528\
    \u7D20 S \u306E\u9069\u7528)\n    std::vector<std::vector<T>> cumulate() {\n \
    \       std::vector<std::vector<T>> res = lazy;\n        \n        // \u5217\u65B9\
    \u5411 (y) \u306E\u7D2F\u7A4D\u548C\n        for (int i = 0; i < h; ++i) {\n \
    \           for (int j = 1; j < w; ++j) {\n                res[i][j] += res[i][j\
    \ - 1];\n            }\n        }\n        // \u884C\u65B9\u5411 (x) \u306E\u7D2F\
    \u7A4D\u548C\n        for (int i = 1; i < h; ++i) {\n            for (int j =\
    \ 0; j < w; ++j) {\n                res[i][j] += res[i - 1][j];\n            }\n\
    \        }\n        \n        // \u7D50\u679C\u306F h x w \u306E\u30B5\u30A4\u30BA\
    \u306B\u5207\u308A\u8A70\u3081\u3066\u8FD4\u3059\n        res.resize(h);\n   \
    \     for(auto& row : res) row.resize(w);\n        return res;\n    }\n\n    ///\
    \ @brief \u5185\u90E8\u72B6\u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\
    \u5EA6 add \u3067\u304D\u308B\u72B6\u614B\u306B\u3059\u308B\n    void clear()\
    \ {\n        for (int i = 0; i <= h; ++i) {\n            std::fill(lazy[i].begin(),\
    \ lazy[i].end(), T(0));\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\n#include <vector>\n\
    #include <algorithm>\n\ntemplate <typename T>\nclass Imos_2 {\n    private:\n\
    \    // \u5DEE\u5206\u914D\u5217 (h+1 x w+1 \u306B\u3059\u308B\u3053\u3068\u3067\
    \u5883\u754C\u5916\u53C2\u7167\u3092\u56DE\u907F)\n    std::vector<std::vector<T>>\
    \ lazy;\n    int h, w;\n\n    bool push(const int i, const int j, const T x) {\n\
    \        if (!(0 <= i && i <= h)) return false;\n        if (!(0 <= j && j <=\
    \ w)) return false;\n\n        lazy[i][j] += x;\n        return true;\n    }\n\
    \n    public:\n    Imos_2(const int h, const int w): lazy(h + 1, std::vector<T>(w\
    \ + 1, T())), h(h), w(w) {}\n\n    // \u9589\u533A\u9593 [u, d] x [l, r] \u3078\
    \u306E\u5024 x \u306E\u52A0\u7B97 (4\u70B9\u66F4\u65B0)\n    void add(int u, int\
    \ d, int l, int r, const T x) {\n        // \u7BC4\u56F2\u306E\u6B63\u898F\u5316\
    \n        u = std::max(0, u); l = std::max(0, l);\n        d = std::min(h - 1,\
    \ d); r = std::min(w - 1, r);\n        if (u > d || l > r) return;\n\n       \
    \ push(u, l, x);\n        push(u, r + 1, -x);\n        push(d + 1, l, -x);\n \
    \       push(d + 1, r + 1, x);\n    }\n\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\
    \u5024 1 \u3067\u306E\u52A0\u7B97\n    void add(const int u, const int d, const\
    \ int l, const int r) { \n        add(u, d, l, r, T(1)); \n    }\n\n    /// @brief\
    \ \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3057\u3066\u7D50\u679C\u3092\u8FD4\u3059\
    \ (\u7D2F\u7A4D\u548C\u4F5C\u7528\u7D20 S \u306E\u9069\u7528)\n    std::vector<std::vector<T>>\
    \ cumulate() {\n        std::vector<std::vector<T>> res = lazy;\n        \n  \
    \      // \u5217\u65B9\u5411 (y) \u306E\u7D2F\u7A4D\u548C\n        for (int i\
    \ = 0; i < h; ++i) {\n            for (int j = 1; j < w; ++j) {\n            \
    \    res[i][j] += res[i][j - 1];\n            }\n        }\n        // \u884C\u65B9\
    \u5411 (x) \u306E\u7D2F\u7A4D\u548C\n        for (int i = 1; i < h; ++i) {\n \
    \           for (int j = 0; j < w; ++j) {\n                res[i][j] += res[i\
    \ - 1][j];\n            }\n        }\n        \n        // \u7D50\u679C\u306F\
    \ h x w \u306E\u30B5\u30A4\u30BA\u306B\u5207\u308A\u8A70\u3081\u3066\u8FD4\u3059\
    \n        res.resize(h);\n        for(auto& row : res) row.resize(w);\n      \
    \  return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\u614B\u3092\u30AF\u30EA\
    \u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\u72B6\u614B\u306B\u3059\
    \u308B\n    void clear() {\n        for (int i = 0; i <= h; ++i) {\n         \
    \   std::fill(lazy[i].begin(), lazy[i].end(), T(0));\n        }\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Imos_2.hpp
  requiredBy: []
  timestamp: '2026-05-28 01:19:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/dsl/5B.test.cpp
documentation_of: Imos/Imos_2.hpp
layout: document
title: "\u3044\u3082\u3059\u6CD5 (2 \u6B21\u5143 0 \u6B21)"
---

## Outline

2 次元いもす法を行うためのクラス.

## Theory

[1 次元バージョン](Imos_1.hpp) の記号を引き継ぐことにする.

$2$ 次元いもす法は, 以下の問いを高速に答えることができる. これ以降, $\otimes$ で線形写像やベクトルのテンソル積を表すことにする.

> $Q$ 個の $u_q \leq d_q, l_q \leq r_q$ を満たす非負整数の組 $(u_q, d_q, l_q, r_q)$ と $\alpha_q \in A$ が与えられる.
>
> このとき, $\displaystyle \sum_{q=1}^Q \alpha_q \left(\sum_{\substack{u_q \leq i \leq d_q \\ l_q \leq j \leq r_q}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)$ の $0 \leq i < H, 0 \leq j < W$ における項を求めろ.

愚直な方法だと, $O(NHQ)$ 時間になるが, いもす法を使うことによって, $O(NH+Q)$ 時間に短縮できる.

$$
\begin{align*}
\sum_{\substack{u \leq i \leq d \\ l \leq j \leq r}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j
&= \sum_{i=u}^d \left( \sum_{j=l}^r \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
&= \sum_{i=u}^d \left(\boldsymbol{e}_i \otimes \left( \sum_{j=l}^r \boldsymbol{e}_j \right) \right) \\
&= \left(\sum_{i=u}^d \boldsymbol{e}_i \right) \otimes \left( \sum_{j=l}^r \boldsymbol{e}_j \right) \\
&= \left(S(\boldsymbol{e}_u - \boldsymbol{e}_{d+1}) \right) \otimes \left(S(\boldsymbol{e}_l - \boldsymbol{e}_{r+1}) \right) \\
&= (S \otimes S) \left(\left(\boldsymbol{e}_u - \boldsymbol{e}_{d+1} \right) \otimes \left( \boldsymbol{e}_l - \boldsymbol{e}_{r+1} \right) \right) \\
&= (S \otimes S) \left(\boldsymbol{e}_u \otimes \boldsymbol{e}_l - \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
\end{align*}
$$

である. よって,

$$
\begin{align*}
\sum_{q=1}^Q \alpha_q \left(\sum_{\substack{u_q \leq i \leq d_q \\ l_q \leq j \leq r_q}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
&= \sum_{q=1}^Q \alpha_q (S \otimes S) \left(\boldsymbol{e}_u \otimes \boldsymbol{e}_l - \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
&= \sum_{q=1}^Q (S \otimes S) \left(\alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_l - \alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
\end{align*}
$$

となる.

$S$ の中身は $4Q$ 個の項の和である.

ここから, $S \otimes S$ の計算を行う.

$$ \sum_{q=1}^Q (S \otimes S) \left(\alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_l - \alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) = \sum_{i,j} \beta_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j $$

と書くことができる.

$$ S \otimes S = (S \otimes I)(I \otimes S)$$

であることに注意する.

各 $i, j$ に対して,

$$
\begin{align*}
  (I \otimes S)(\boldsymbol{e}_i \otimes \boldsymbol{e}_j)
  &= (I \boldsymbol{e}_i) \otimes (S \boldsymbol{e}_j) \\
  &= \boldsymbol{e}_i \otimes \sum_{q \geq j} \boldsymbol{e}_q \\
  &= \sum_{q \geq j }\boldsymbol{e}_i \otimes  \boldsymbol{e}_q
\end{align*}
$$

である.

よって,

$$
\begin{align*}
  (I \otimes S)\left(\sum_{i,j} \beta_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
  &= \sum_{i,j} \beta_{i,j} (I \otimes S) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
  &= \sum_{i,j} \beta_{i,j} \sum_{q \geq j} \boldsymbol{e}_i \otimes  \boldsymbol{e}_q \\
  &= \sum_{i,j} \left(\sum_{q=0}^j \beta_{i,q} \right) \boldsymbol{e}_i \otimes \boldsymbol{e}_j \\
\end{align*}
$$

である.

$$ \gamma_{i,j} := \sum_{q=0}^j \beta_{i,q} $$

とおく.

同様にして,

$$\begin{align*}
  (I \otimes S) \left( \sum_{i, j} \gamma_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
  &= \sum_{i,j} \gamma_{i,j} (I \otimes S) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
  &= \sum_{i,j} \left(\sum_{p=0}^i \gamma_{p,j} \right) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
\end{align*}$$

となる.

ここで,

$$ \sum_{p=0}^i \gamma_{i,j} = \sum_{p=0}^i \sum_{q=0}^j \beta_{i,j} $$

である.

よって, $2$ 次元累積和とは,

$$ \left(\beta_{i,j} \right) \mapsto \left(\sum_{p=0}^i \sum_{q=0}^j \beta_{i,j} \right) $$

とする変換である.

この変換は $(S \otimes I), (I \otimes S)$ を連続して計算することによって, $O(HW)$ 時間で求められる.


## Contents

### Constructor

```cpp
Imos_2(const int h, const int w)
```

* サイズ $h \times w$ の 2 次元いもす法オブジェクトを生成する.
* **引数**
  * $h$: 縦方向の要素数
  * $w$: 横方向の要素数
* **計算量** : $O(hw)$ 時間.

### add

```cpp
void add(int u, int d, int l, int r, const T x)
void add(const int u, const int d, const int l, const int r)
```

* 閉区間 $[u, d] \times [l, r]$ の各要素に加算を行う.
* 引数の範囲が $[0, h-1] \times [0, w-1]$ の範囲外にある場合は, 自動的に $[0, h-1] \times [0, w-1]$ の範囲にクリップ（丸め込み）される. クリップされた結果, 閉区間が正しく構成できない場合 (例: $u > d$ または $l > r$ または範囲外) は何も行わない.
* **引数**
  * (1) (引数が5つの場合)
    * $u$: 閉区間の上端
    * $d$: 閉区間の下端
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * $x$: 加算値
  * (2) (引数が4つの場合)
    * $u$: 閉区間の上端
    * $d$: 閉区間の下端
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
* **計算量** : $O(1)$ 時間.

### cumulate

```cpp
std::vector<std::vector<T>> cumulate()
```

* これまでの加算クエリの結果を累積し, 各要素の最終的な値からなるサイズ $h \times w$ の 2 次元配列を生成・返却する.
* **計算量** : $O(hw)$ 時間.

### clear

```cpp
void clear()
```

* 内部の差分配列を $0$ で初期化し, 再度 `add` を行えるようにクリアする.
* **計算量** : $O(hw)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/05/30| いもす法 (2 次元 0 次) の実装 |
