---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
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
    document_title: "\u4E0D\u6B63\u306A\u5E95\u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\
      \u304D\u306B\u30B9\u30ED\u30FC\u3055\u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\
      \u5916"
    links: []
  bundledCode: "#line 2 \"Integer/Digit.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n// a \u2190 max(a, b)\
    \ \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089\
    , \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool\
    \ chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n// a \u2190\
    \ min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\
    \u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline\
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n#line 59\
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u9664\
    \u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x >\
    \ 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y\
    \ - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT safe_mod(T x, U y){\n\
    \    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\
    \u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n \
    \   return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q, r;\n \
    \   tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n\
    }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\
    \u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n\
    \        if (y & 1) { a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n  \
    \  return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n\
    \    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T,\
    \ typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n    \
    \    if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n\
    \    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto &&x:\
    \ X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T> &X){\n    T y\
    \ = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n// a x + b y\
    \ = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\
    \u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntuple<ll, ll, ll> Extended_Euclid(ll\
    \ a, ll b) {\n    ll s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        ll\
    \ q;\n        tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n\
    \        tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v,\
    \ u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n\
    \    while ((x + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\
    \n    return x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\
    \u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return\
    \ isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\
    \u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x =\
    \ isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line 62 \"template/template.hpp\"\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n#line 65 \"template/template.hpp\"\
    \n\n// macro\n#line 2 \"template/macro.hpp\"\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\
    \u7FA9\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n#define unless(cond) if (!(cond))\n#define until(cond) while (!(cond))\n\
    #define loop while (true)\n\n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\
    \u30AF\u30ED\n#define overload2(_1, _2, name, ...) name\n#define overload3(_1,\
    \ _2, _3, name, ...) name\n#define overload4(_1, _2, _3, _4, name, ...) name\n\
    #define overload5(_1, _2, _3, _4, _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\
    \u3057\u7CFB\n#define rep1(n) for (ll i = 0; i < n; i++)\n#define rep2(i, n) for\
    \ (ll i = 0; i < n; i++)\n#define rep3(i, a, b) for (ll i = a; i < b; i++)\n#define\
    \ rep4(i, a, b, c) for (ll i = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__,\
    \ rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x:\
    \ a)\n#define foreach2(x, y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y,\
    \ z, a) for (auto &&[x, y, z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x,\
    \ y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__, foreach4, foreach3,\
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 68 \"template/template.hpp\"\n\n// bitop\n\
    #line 2 \"template/bitop.hpp\"\n\n// \u975E\u8CA0\u6574\u6570 x \u306E bit legnth\
    \ \u3092\u6C42\u3081\u308B.\nll bit_length(ll x) {\n    if (x == 0) { return 0;\
    \ }\n    return (sizeof(long) * CHAR_BIT) - __builtin_clzll(x);\n}\n\n// \u975E\
    \u8CA0\u6574\u6570 x \u306E popcount \u3092\u6C42\u3081\u308B.\nll popcount(ll\
    \ x) { return __builtin_popcountll(x); }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\
    \u5BFE\u3057\u3066, floor(log2(x)) \u3092\u6C42\u3081\u308B.\nll floor_log2(ll\
    \ x) { return bit_length(x) - 1; }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\
    \u3057\u3066, ceil(log2(x)) \u3092\u6C42\u3081\u308B.\nll ceil_log2(ll x) { return\
    \ bit_length(x - 1); }\n\n// x \u306E\u7B2C k \u30D3\u30C3\u30C8\u3092\u53D6\u5F97\
    \u3059\u308B\nint get_bit(ll x, int k) { return (x >> k) & 1; }\n\n// x \u306E\
    \u30D3\u30C3\u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B.\n// k \u306F\u30D3\u30C3\
    \u30C8\u5217\u306E\u9577\u3055\u3068\u3059\u308B.\nvector<int> get_bits(ll x,\
    \ int k) {\n    vector<int> bits(k);\n    rep(i, k) {\n        bits[i] = x & 1;\n\
    \        x >>= 1;\n    }\n\n    return bits;\n}\n\n// x \u306E\u30D3\u30C3\u30C8\
    \u5217\u3092\u53D6\u5F97\u3059\u308B.\nvector<int> get_bits(ll x) { return get_bits(x,\
    \ bit_length(x)); }\n#line 4 \"Integer/Digit.hpp\"\n\n/**\n * @brief \u4E0D\u6B63\
    \u306A\u5E95\u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\u30B9\u30ED\
    \u30FC\u3055\u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\u5916\n */\nclass BaseException\
    \ : public runtime_error {\n    private:\n    ll error_base;\n\n    public:\n\
    \    /**\n     * @brief BaseException\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\
    \n     * * @param base \u4E0D\u6B63\u306A\u5E95\u306E\u5024\n     */\n    BaseException(ll\
    \ base) :\n        runtime_error(\"\u6307\u5B9A\u3057\u305F\u5E95 \" + to_string(base)\
    \ + \" \u306F\u4E0D\u6B63\u306A\u5E95\u3067\u3059.\"), \n        error_base(base)\
    \ {}\n};\n\n/**\n * @brief \u6574\u6570 n \u306E\u5E95\u3092 b \u3068\u3057\u305F\
    \u5834\u5408\u306E\u8868\u73FE\u3092\u6C42\u3081\u308B.\n *\n * @param n \u7B26\
    \u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n * @param b \u5E95 (b >= 2). Default\
    \ to 10.\n * @param l \u9577\u3055\u304C 0 \u306B\u306A\u308B\u3088\u3046\u306B\
    \u5DE6\u5074\u306B 0 \u3092\u57CB\u3081\u305F\u308A, \u53F3\u304B\u3089 l \u8981\
    \u7D20\u3092\u53D6\u5F97\u3059\u308B. -1 \u306F\u7121\u6307\u5B9A.\n * @return\
    \ vector<ll> \u6570\u306E\u30EA\u30B9\u30C8 (\u6700\u4E0A\u4F4D\u6841\u304B\u3089\
    \u6700\u4E0B\u4F4D\u6841\u306E\u9806).\n */\nvector<ll> Integer_Digits(ll n, ll\
    \ b = 10, int l = -1) {\n    if (b < 2) { throw BaseException(b); }\n\n    n =\
    \ abs(n);\n    vector<ll> digits;\n\n    if (l == -1) {\n        if (n == 0) {\n\
    \            digits.push_back(0);\n            return digits;\n        }\n\n \
    \       while (n > 0) {\n            digits.push_back(n % b);\n            n /=\
    \ b;\n        }\n    } else {\n        for (int i = 0; i < l; ++i) {\n       \
    \     digits.push_back(n % b);\n            n /= b;\n        }\n    }\n\n    reverse(digits.begin(),\
    \ digits.end());\n    return digits;\n}\n\n/**\n * @brief \u6574\u6570 n \u306E\
    \u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306E\u6841\u6570\u3092\u6C42\u3081\
    \u308B (0 \u306F 0 \u6841\u3068\u3059\u308B).\n *\n * @param n \u7B26\u53F7\u306F\
    \u7121\u8996\u3055\u308C\u308B\n * @param b \u5E95 (b >= 2). Default to 10.\n\
    \ * @return int \u6841\u6570\n */\nint Integer_Length(ll n, ll b = 10) {\n   \
    \ if (b < 2) { throw BaseException(b); }\n    \n    n = abs(n);\n    \n    int\
    \ length = 0;\n    for (; n > 0; length++) { n /= b; }\n\n    return length;\n\
    }\n\n/**\n * @brief \u6574\u6570 n \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\
    \u5408\u306E\u6841\u548C\u3092\u6C42\u3081\u308B.\n *\n * @param n \u7B26\u53F7\
    \u306F\u7121\u8996\u3055\u308C\u308B\n * @param b \u5E95 (b >= 2). \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u306F 10.\n * @return ll \u6841\u548C\n */\nll Digit_Sum(ll\
    \ n, ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n    \n    n = abs(n);\n\
    \    \n    ll sum = 0;\n        \n    while (n > 0) {\n        sum += n % b;\n\
    \        n /= b;\n    }\n    return sum;\n}\n\n/**\n * @brief \u6574\u6570 n \u306E\
    \u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306B\u304A\u3051\u308B\u5404\u6570\
    \u306E\u51FA\u73FE\u56DE\u6570\u3092\u6C42\u3081\u308B.\n *\n * @param n \u7B26\
    \u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n * @param b \u5E95 (b >= 2). Default\
    \ to 10.\n * @return vector<ll> \u9577\u3055 b \u306E\u914D\u5217. \u7B2C k \u8981\
    \u7D20\u306F k \u306E\u51FA\u73FE\u56DE\u6570.\n */\nvector<ll> Digit_Count(ll\
    \ n, ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    n = abs(n);\n\
    \n    vector<ll> count(b, 0);    \n    for (ll d : Integer_Digits(n, b)) {\n \
    \       count[d]++;\n    }\n    return count;\n}\n\n/**\n * @brief \u5E95\u3092\
    \ b \u3068\u3057\u305F\u5834\u5408\u306B digit \u304C\u306A\u3059\u6574\u6570\u3092\
    \u8FD4\u3059 (Integer_Digit \u306E\u9006\u95A2\u6570)\n *\n * @param digits \u6570\
    \u306E\u30EA\u30B9\u30C8 (\u6700\u4E0A\u4F4D\u6841\u304B\u3089\u6700\u4E0B\u4F4D\
    \u6841\u306E\u9806)\n * @param b \u5E95 (b >= 2). Default to 10.\n * @return ll\
    \ \u6574\u6570 (\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306E\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u6CE8\u610F)\n */\nll From_Digits(const vector<ll>\
    \ &digits, ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\n    ll\
    \ res = 0;\n    for (ll x : digits) {  res = b * res + x; }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\n/**\n * @brief \u4E0D\
    \u6B63\u306A\u5E95\u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\u30B9\
    \u30ED\u30FC\u3055\u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\u5916\n */\nclass\
    \ BaseException : public runtime_error {\n    private:\n    ll error_base;\n\n\
    \    public:\n    /**\n     * @brief BaseException\u3092\u69CB\u7BC9\u3057\u307E\
    \u3059\u3002\n     * * @param base \u4E0D\u6B63\u306A\u5E95\u306E\u5024\n    \
    \ */\n    BaseException(ll base) :\n        runtime_error(\"\u6307\u5B9A\u3057\
    \u305F\u5E95 \" + to_string(base) + \" \u306F\u4E0D\u6B63\u306A\u5E95\u3067\u3059\
    .\"), \n        error_base(base) {}\n};\n\n/**\n * @brief \u6574\u6570 n \u306E\
    \u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306E\u8868\u73FE\u3092\u6C42\u3081\
    \u308B.\n *\n * @param n \u7B26\u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n *\
    \ @param b \u5E95 (b >= 2). Default to 10.\n * @param l \u9577\u3055\u304C 0 \u306B\
    \u306A\u308B\u3088\u3046\u306B\u5DE6\u5074\u306B 0 \u3092\u57CB\u3081\u305F\u308A\
    , \u53F3\u304B\u3089 l \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B. -1 \u306F\u7121\
    \u6307\u5B9A.\n * @return vector<ll> \u6570\u306E\u30EA\u30B9\u30C8 (\u6700\u4E0A\
    \u4F4D\u6841\u304B\u3089\u6700\u4E0B\u4F4D\u6841\u306E\u9806).\n */\nvector<ll>\
    \ Integer_Digits(ll n, ll b = 10, int l = -1) {\n    if (b < 2) { throw BaseException(b);\
    \ }\n\n    n = abs(n);\n    vector<ll> digits;\n\n    if (l == -1) {\n       \
    \ if (n == 0) {\n            digits.push_back(0);\n            return digits;\n\
    \        }\n\n        while (n > 0) {\n            digits.push_back(n % b);\n\
    \            n /= b;\n        }\n    } else {\n        for (int i = 0; i < l;\
    \ ++i) {\n            digits.push_back(n % b);\n            n /= b;\n        }\n\
    \    }\n\n    reverse(digits.begin(), digits.end());\n    return digits;\n}\n\n\
    /**\n * @brief \u6574\u6570 n \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\
    \u306E\u6841\u6570\u3092\u6C42\u3081\u308B (0 \u306F 0 \u6841\u3068\u3059\u308B\
    ).\n *\n * @param n \u7B26\u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n * @param\
    \ b \u5E95 (b >= 2). Default to 10.\n * @return int \u6841\u6570\n */\nint Integer_Length(ll\
    \ n, ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n    \n    n = abs(n);\n\
    \    \n    int length = 0;\n    for (; n > 0; length++) { n /= b; }\n\n    return\
    \ length;\n}\n\n/**\n * @brief \u6574\u6570 n \u306E\u5E95\u3092 b \u3068\u3057\
    \u305F\u5834\u5408\u306E\u6841\u548C\u3092\u6C42\u3081\u308B.\n *\n * @param n\
    \ \u7B26\u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n * @param b \u5E95 (b >= 2).\
    \ \u30C7\u30D5\u30A9\u30EB\u30C8\u306F 10.\n * @return ll \u6841\u548C\n */\n\
    ll Digit_Sum(ll n, ll b = 10) {\n    if (b < 2) { throw BaseException(b); }\n\
    \    \n    n = abs(n);\n    \n    ll sum = 0;\n        \n    while (n > 0) {\n\
    \        sum += n % b;\n        n /= b;\n    }\n    return sum;\n}\n\n/**\n *\
    \ @brief \u6574\u6570 n \u306E\u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306B\
    \u304A\u3051\u308B\u5404\u6570\u306E\u51FA\u73FE\u56DE\u6570\u3092\u6C42\u3081\
    \u308B.\n *\n * @param n \u7B26\u53F7\u306F\u7121\u8996\u3055\u308C\u308B\n *\
    \ @param b \u5E95 (b >= 2). Default to 10.\n * @return vector<ll> \u9577\u3055\
    \ b \u306E\u914D\u5217. \u7B2C k \u8981\u7D20\u306F k \u306E\u51FA\u73FE\u56DE\
    \u6570.\n */\nvector<ll> Digit_Count(ll n, ll b = 10) {\n    if (b < 2) { throw\
    \ BaseException(b); }\n\n    n = abs(n);\n\n    vector<ll> count(b, 0);    \n\
    \    for (ll d : Integer_Digits(n, b)) {\n        count[d]++;\n    }\n    return\
    \ count;\n}\n\n/**\n * @brief \u5E95\u3092 b \u3068\u3057\u305F\u5834\u5408\u306B\
    \ digit \u304C\u306A\u3059\u6574\u6570\u3092\u8FD4\u3059 (Integer_Digit \u306E\
    \u9006\u95A2\u6570)\n *\n * @param digits \u6570\u306E\u30EA\u30B9\u30C8 (\u6700\
    \u4E0A\u4F4D\u6841\u304B\u3089\u6700\u4E0B\u4F4D\u6841\u306E\u9806)\n * @param\
    \ b \u5E95 (b >= 2). Default to 10.\n * @return ll \u6574\u6570 (\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u306E\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\
    \u6CE8\u610F)\n */\nll From_Digits(const vector<ll> &digits, ll b = 10) {\n  \
    \  if (b < 2) { throw BaseException(b); }\n\n    ll res = 0;\n    for (ll x :\
    \ digits) {  res = b * res + x; }\n    return res;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: Integer/Digit.hpp
  requiredBy: []
  timestamp: '2025-11-02 11:44:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Integer/Digit.hpp
layout: document
redirect_from:
- /library/Integer/Digit.hpp
- /library/Integer/Digit.hpp.html
title: "\u4E0D\u6B63\u306A\u5E95\u304C\u6307\u5B9A\u3055\u308C\u305F\u3068\u304D\u306B\
  \u30B9\u30ED\u30FC\u3055\u308C\u308B\u30AB\u30B9\u30BF\u30E0\u4F8B\u5916"
---
