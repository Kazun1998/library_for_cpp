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
    document_title: "\u9589\u533A\u9593 [l, r] \u306E\u5404\u8981\u7D20 i \u306B\u5BFE\
      \u3057\u3001\u4E00\u6B21\u5F0F a * (i - l) + b \u3092\u52A0\u7B97\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"Imos/Linear_Imos_1.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 4 \"Imos/Linear_Imos_1.hpp\"\n\ntemplate <typename T>\nclass\
    \ Linear_Imos_1 {\n    private:\n    std::vector<T> slope;\n    std::vector<T>\
    \ intercept;\n    int n;\n\n    void push(int t, T a, T b) {\n        if (!(0\
    \ <= t && t <= n)) return;\n        intercept[t] += a;\n        slope[t] += b;\n\
    \    }\n\n    public:\n    Linear_Imos_1(const int n) : n(n), slope(n + 1, 0),\
    \ intercept(n + 1, 0) {}\n\n    /// @brief \u9589\u533A\u9593 [l, r] \u306E\u5404\
    \u8981\u7D20 i \u306B\u5BFE\u3057\u3001\u4E00\u6B21\u5F0F a * (i - l) + b \u3092\
    \u52A0\u7B97\u3059\u308B\n    /// @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\
    \u306E\u3088\u3046\u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += b, I[l + 1]\
    \ += a + b, I[l + 2] += 2a + b, ..., I[r] += (r - l)a + b\n    /// @param l \u5DE6\
    \u7AEF\n    /// @param r \u53F3\u7AEF\n    /// @param a \u50BE\u304D (\u516C\u5DEE\
    )\n    /// @param b \u5B9A\u6570\u9805 (\u521D\u9805)\n    void add(int l, int\
    \ r, const T a, const T b) {\n        if (l > r) return;\n\n        // \u7BC4\u56F2\
    \u306E\u4E38\u3081\u8FBC\u307F\n        if (l < 0) l = 0;\n        if (r >= n)\
    \ r = n - 1;\n        if (l > r || l >= n || r < 0) return;\n\n        // a(i\
    \ - l) + b = a*i + (b - a*l)\n        push(l, b - a * l, a);\n        push(r +\
    \ 1, -(b - a * l), -a);\n    }\n\n    /// @brief \u9589\u533A\u9593 [l, r] \u306E\
    \u5404\u8981\u7D20\u306B\u5B9A\u6570 x \u3092\u52A0\u7B97\u3059\u308B\n    ///\
    \ @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\u306E\u3088\u3046\u306B\u52A0\
    \u7B97\u3059\u308B.\n    /// I[l] += x, I[l + 1] += x, ..., I[r] += x\n    ///\
    \ @param l \u5DE6\u7AEF\n    /// @param r \u53F3\u7AEF\n    /// @param x \u52A0\
    \u7B97\u5024\n    void add(int l, int r, const T x) { add(l, r, 0, x); }\n\n \
    \   /// @brief \u9589\u533A\u9593 [l, r] \u306E\u5404\u8981\u7D20 i \u306B\u5BFE\
    \u3057\u3001(i - l) + 1 \u3092\u52A0\u7B97\u3059\u308B (1, 2, 3, ... \u306E\u7B49\
    \u5DEE\u6570\u5217)\n    /// @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\u306E\
    \u3088\u3046\u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += 1, I[l + 1] += 2,\
    \ ..., I[r] += (r - l) + 1\n    /// @param l \u5DE6\u7AEF\n    /// @param r \u53F3\
    \u7AEF\n    void add(int l, int r) { add(l, r, T(1), T(1)); }\n\n    /// @brief\
    \ \u9589\u533A\u9593 [l, l + 2m] \u306B\u30C6\u30F3\u30C8\u578B\uFF08\u5C71\u578B\
    \uFF09\u306E\u7B49\u5DEE\u6570\u5217\u3092\u52A0\u7B97\u3059\u308B\n    /// @details\
    \ \u9589\u533A\u9593 [l, l + 2m] \u306B\u6B21\u306E\u3088\u3046\u306B\u5C71\u578B\
    \u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += a, I[l + 1] += a + b, I[l + 2]\
    \ += a + 2b, ..., I[l + m] += a + mb\n    /// I[l + m + 1] += a + (m - 1)b, I[l\
    \ + m + 2] += a + (m - 2)b, ..., I[l + 2m - 1] += a + b, I[l + 2m] += a\n    ///\
    \ @param l \u5DE6\u7AEF\n    /// @param m \u9802\u70B9\u307E\u3067\u306E\u8DDD\
    \u96E2 (\u5C71\u306E\u88FE\u91CE\u306E\u9577\u3055)\n    /// @param a \u88FE\u91CE\
    \u306E\u958B\u59CB\u5024\n    /// @param b \u50BE\u304D (\u516C\u5DEE)\n    void\
    \ add_tent(int l, int m, const T a, const T b) {\n        if (m < 0) return;\n\
    \        add(l, l + m, b, a);\n        add(l + m + 1, l + 2 * m, -b, a + (m -\
    \ 1) * b);\n    }\n\n    /// @brief \u9589\u533A\u9593 [t, t + m - 1] \u3078\u306E\
    \u4E00\u69D8\u306A a \u306E\u52A0\u7B97\u3092\u3001t = l, l + 1, ..., l + k -\
    \ 1 \u306B\u3064\u3044\u3066\u884C\u3046\n    /// @param l \u64CD\u4F5C\u306E\u59CB\
    \u70B9\n    /// @param k \u64CD\u4F5C\u306E\u56DE\u6570\n    /// @param m 1 \u56DE\
    \u306E\u64CD\u4F5C\u3067\u52A0\u7B97\u3059\u308B\u9805\u306E\u6570\n    /// @param\
    \ a \u52A0\u7B97\u3059\u308B\u5024\n    void add_slide_multiple(int l, int k,\
    \ int m, const T a) {\n        if (k <= 0 || m <= 0) return;\n        int s =\
    \ std::min(k, m), lb = std::max(k, m);\n        add(l, l + s - 1, a, a);\n   \
    \     add(l + s, l + lb - 1, (T)s * a);\n        add(l + lb, l + k + m - 2, -a,\
    \ (T)(s - 1) * a);\n    }\n\n    inline int size() const { return n; }\n\n   \
    \ /// @brief \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\n    std::vector<T>\
    \ cumulate() {\n        if (n == 0) return std::vector<T>();\n\n        std::vector<T>\
    \ res(n);\n        T s = 0, ic = 0;\n        for (int i = 0; i < n; ++i) {\n \
    \           s += slope[i];\n            ic += intercept[i];\n            res[i]\
    \ = s * i + ic;\n        }\n\n        return res;\n    }\n\n    /// @brief \u5185\
    \u90E8\u72B6\u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\
    \u304D\u308B\u72B6\u614B\u306B\u3059\u308B\n    void clear() {\n        std::fill(slope.begin(),\
    \ slope.end(), T(0));\n        std::fill(intercept.begin(), intercept.end(), T(0));\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate <typename\
    \ T>\nclass Linear_Imos_1 {\n    private:\n    std::vector<T> slope;\n    std::vector<T>\
    \ intercept;\n    int n;\n\n    void push(int t, T a, T b) {\n        if (!(0\
    \ <= t && t <= n)) return;\n        intercept[t] += a;\n        slope[t] += b;\n\
    \    }\n\n    public:\n    Linear_Imos_1(const int n) : n(n), slope(n + 1, 0),\
    \ intercept(n + 1, 0) {}\n\n    /// @brief \u9589\u533A\u9593 [l, r] \u306E\u5404\
    \u8981\u7D20 i \u306B\u5BFE\u3057\u3001\u4E00\u6B21\u5F0F a * (i - l) + b \u3092\
    \u52A0\u7B97\u3059\u308B\n    /// @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\
    \u306E\u3088\u3046\u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += b, I[l + 1]\
    \ += a + b, I[l + 2] += 2a + b, ..., I[r] += (r - l)a + b\n    /// @param l \u5DE6\
    \u7AEF\n    /// @param r \u53F3\u7AEF\n    /// @param a \u50BE\u304D (\u516C\u5DEE\
    )\n    /// @param b \u5B9A\u6570\u9805 (\u521D\u9805)\n    void add(int l, int\
    \ r, const T a, const T b) {\n        if (l > r) return;\n\n        // \u7BC4\u56F2\
    \u306E\u4E38\u3081\u8FBC\u307F\n        if (l < 0) l = 0;\n        if (r >= n)\
    \ r = n - 1;\n        if (l > r || l >= n || r < 0) return;\n\n        // a(i\
    \ - l) + b = a*i + (b - a*l)\n        push(l, b - a * l, a);\n        push(r +\
    \ 1, -(b - a * l), -a);\n    }\n\n    /// @brief \u9589\u533A\u9593 [l, r] \u306E\
    \u5404\u8981\u7D20\u306B\u5B9A\u6570 x \u3092\u52A0\u7B97\u3059\u308B\n    ///\
    \ @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\u306E\u3088\u3046\u306B\u52A0\
    \u7B97\u3059\u308B.\n    /// I[l] += x, I[l + 1] += x, ..., I[r] += x\n    ///\
    \ @param l \u5DE6\u7AEF\n    /// @param r \u53F3\u7AEF\n    /// @param x \u52A0\
    \u7B97\u5024\n    void add(int l, int r, const T x) { add(l, r, 0, x); }\n\n \
    \   /// @brief \u9589\u533A\u9593 [l, r] \u306E\u5404\u8981\u7D20 i \u306B\u5BFE\
    \u3057\u3001(i - l) + 1 \u3092\u52A0\u7B97\u3059\u308B (1, 2, 3, ... \u306E\u7B49\
    \u5DEE\u6570\u5217)\n    /// @details \u9589\u533A\u9593 [l, r] \u306B\u6B21\u306E\
    \u3088\u3046\u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += 1, I[l + 1] += 2,\
    \ ..., I[r] += (r - l) + 1\n    /// @param l \u5DE6\u7AEF\n    /// @param r \u53F3\
    \u7AEF\n    void add(int l, int r) { add(l, r, T(1), T(1)); }\n\n    /// @brief\
    \ \u9589\u533A\u9593 [l, l + 2m] \u306B\u30C6\u30F3\u30C8\u578B\uFF08\u5C71\u578B\
    \uFF09\u306E\u7B49\u5DEE\u6570\u5217\u3092\u52A0\u7B97\u3059\u308B\n    /// @details\
    \ \u9589\u533A\u9593 [l, l + 2m] \u306B\u6B21\u306E\u3088\u3046\u306B\u5C71\u578B\
    \u306B\u52A0\u7B97\u3059\u308B.\n    /// I[l] += a, I[l + 1] += a + b, I[l + 2]\
    \ += a + 2b, ..., I[l + m] += a + mb\n    /// I[l + m + 1] += a + (m - 1)b, I[l\
    \ + m + 2] += a + (m - 2)b, ..., I[l + 2m - 1] += a + b, I[l + 2m] += a\n    ///\
    \ @param l \u5DE6\u7AEF\n    /// @param m \u9802\u70B9\u307E\u3067\u306E\u8DDD\
    \u96E2 (\u5C71\u306E\u88FE\u91CE\u306E\u9577\u3055)\n    /// @param a \u88FE\u91CE\
    \u306E\u958B\u59CB\u5024\n    /// @param b \u50BE\u304D (\u516C\u5DEE)\n    void\
    \ add_tent(int l, int m, const T a, const T b) {\n        if (m < 0) return;\n\
    \        add(l, l + m, b, a);\n        add(l + m + 1, l + 2 * m, -b, a + (m -\
    \ 1) * b);\n    }\n\n    /// @brief \u9589\u533A\u9593 [t, t + m - 1] \u3078\u306E\
    \u4E00\u69D8\u306A a \u306E\u52A0\u7B97\u3092\u3001t = l, l + 1, ..., l + k -\
    \ 1 \u306B\u3064\u3044\u3066\u884C\u3046\n    /// @param l \u64CD\u4F5C\u306E\u59CB\
    \u70B9\n    /// @param k \u64CD\u4F5C\u306E\u56DE\u6570\n    /// @param m 1 \u56DE\
    \u306E\u64CD\u4F5C\u3067\u52A0\u7B97\u3059\u308B\u9805\u306E\u6570\n    /// @param\
    \ a \u52A0\u7B97\u3059\u308B\u5024\n    void add_slide_multiple(int l, int k,\
    \ int m, const T a) {\n        if (k <= 0 || m <= 0) return;\n        int s =\
    \ std::min(k, m), lb = std::max(k, m);\n        add(l, l + s - 1, a, a);\n   \
    \     add(l + s, l + lb - 1, (T)s * a);\n        add(l + lb, l + k + m - 2, -a,\
    \ (T)(s - 1) * a);\n    }\n\n    inline int size() const { return n; }\n\n   \
    \ /// @brief \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\n    std::vector<T>\
    \ cumulate() {\n        if (n == 0) return std::vector<T>();\n\n        std::vector<T>\
    \ res(n);\n        T s = 0, ic = 0;\n        for (int i = 0; i < n; ++i) {\n \
    \           s += slope[i];\n            ic += intercept[i];\n            res[i]\
    \ = s * i + ic;\n        }\n\n        return res;\n    }\n\n    /// @brief \u5185\
    \u90E8\u72B6\u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\
    \u304D\u308B\u72B6\u614B\u306B\u3059\u308B\n    void clear() {\n        std::fill(slope.begin(),\
    \ slope.end(), T(0));\n        std::fill(intercept.begin(), intercept.end(), T(0));\n\
    \    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Linear_Imos_1.hpp
  requiredBy: []
  timestamp: '2026-05-30 18:39:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Imos/Linear_Imos_1.hpp
layout: document
title: "\u3044\u3082\u3059\u6CD5 (1 \u6B21\u5143 1 \u6B21)"
---

## Outline

1 次元いもす法 (1 次) を行うためのクラス.
特定の区間へ一括して一次式（等差数列）の加算を行うクエリを多数処理した後, 最後に累積和をとることで, 各要素の最終的な値を高速に求めることができる.

## Theory

閉区間 $[l, r]$ の各要素 $i$ に対して一次式 $f(i) = a(i - l) + b$ を加算する操作を考える.
これは, 式を変形すると以下のように表せる.

$$ f(i) = a \cdot i + (b - a \cdot l) $$

そのため, 定数項の部分と, 傾きの部分をそれぞれ $1$ 次元 $0$ 次の基本的ないもす法で計算し, それらの結果を統合すれば $1$ 次元 $1$ 次も解くことができる.

## Contents

### Constructor

```cpp
Linear_Imos_1(const int n)
```

* サイズ $n$ の 1 次元いもす法 (1 次) オブジェクトを生成する.
* **引数**
  * $n$: 要素数
* **計算量** : $O(n)$ 時間.

### add

```cpp
void add(int l, int r, const T a, const T b)
void add(int l, int r, const T x)
void add(int l, int r)
```

* 閉区間 $[l, r]$ の各要素に対して等差数列または定数の加算を行う.
* **注意**
  * 引数の範囲が $[0, n-1]$ の範囲外にある場合は, 自動的に $[0, n-1]$ の範囲にクリップ（丸め込み）される.
  * クリップされた結果, 閉区間が正しく構成できない場合 (例: $l > r$ または範囲外) は何も行わない.
* **引数**
  * (1) (引数が4つの場合)
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * $a$: 傾き (公差)
    * $b$: 定数項 (初項)
    * ※ 各要素 $i \in [l, r]$ に対して $a(i - l) + b$ を加算する.
  * (2) (引数が3つの場合)
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * $x$: 加算値
    * ※ 各要素 $i \in [l, r]$ に対して $x$ を加算する (`add(l, r, 0, x)` と同等).
  * (3) (引数が2つの場合)
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * ※ 各要素 $i \in [l, r]$ に対して $(i - l) + 1$ を加算する (`add(l, r, 1, 1)` と同等).
* **計算量** : $O(1)$ 時間.

### add_tent

```cpp
void add_tent(int l, int m, const T a, const T b)
```

* 閉区間 $[l, l + 2m]$ に左端が $l$ で裾野の長さが $m$ である, 以下で定義されるテント型 (山型) 関数 $t(i)$ を加算する.

$$ t(i) := \begin{cases}
  a + (i - l)b & (l \leq i \leq l + m) \\
  a + (l + 2m - i)b & (l + m < i \leq i + 2m) \\
  0 & (\textrm{otherwise})
\end{cases}$$

* 要するに, $(\underbrace{0, 0, \dots, 0}_l, a, a + b, a+2b, \dots, a + mb, a+(m-1)b, \dots, a+2b, a+b, a, 0, \dots, 0)$ を加算する.
* **引数**
  * $l$: 閉区間の左端
  * $m$: 頂点までの距離 (山の裾野の長さ)
  * $a$: 裾野の開始値 (初項)
  * $b$: 傾き (公差)
* **計算量** : $O(1)$ 時間.

### add_slide_multiple

```cpp
void add_slide_multiple(int l, int k, int m, const T a)
```

* 閉区間 $[t, t + m - 1]$ への一様な $a$ の加算を, $t = l, l + 1, \dots, l + k - 1$ について行う.
* **引数**
  * $l$: 操作の始点
  * $k$: 操作の回数
  * $m$: 1回あたりの操作で加算する項の数
  * $a$: 加算する値
* **計算量** : $O(1)$ 時間.

### size

```cpp
int size() const
```

* オブジェクトのサイズ $n$ を返す.
* **計算量** : $O(1)$ 時間.

### cumulate

```cpp
std::vector<T> cumulate()
```

* これまでの加算クエリの結果を累積し, 各要素の最終的な値からなるサイズ $n$ の配列を生成・返却する.
* **計算量** : $O(n)$ 時間.

### clear

```cpp
void clear()
```

* 内部状態をクリアして, 再度 `add` できる状態にする.
* **計算量** : $O(n)$ 時間.

|日付|内容|
|:---:|:---|
|2026/05/30| いもす法 (1 次元 1 次) の実装 |
