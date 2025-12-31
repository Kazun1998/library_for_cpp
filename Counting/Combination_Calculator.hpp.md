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
    path: Counting/Q_Analog_Combination_Calculator.hpp
    title: "$q$ -\u6570\u306B\u3088\u308B\u7D44\u307F\u5408\u308F\u305B\u8AD6\u306B\
      \u95A2\u3059\u308B\u57FA\u672C\u7684\u306A\u8A08\u7B97"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/enumerate_combinatorics/Binomial_Coefficient_Prime_Mod.test.cpp
    title: verify/yosupo_library_checker/enumerate_combinatorics/Binomial_Coefficient_Prime_Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/enumerate_combinatorics/q-Binomial_Coefficient_Prime_Mod.test.cpp
    title: verify/yosupo_library_checker/enumerate_combinatorics/q-Binomial_Coefficient_Prime_Mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF: \u521D\u671F\u30B5\
      \u30A4\u30BAn\u307E\u3067\u968E\u4E57\u30FB\u9006\u968E\u4E57\u3092\u8A08\u7B97\
      \u3059\u308B"
    links: []
  bundledCode: "#line 2 \"Counting/Combination_Calculator.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u6F14\
    \u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) { return x +\
    \ y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return x - y;\
    \ }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x * y; }\n\
    \ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<typename\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<typename\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x > 0 ? x\
    \ / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y - 1) / y: x / y)\
    \ ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT safe_mod(T x, U y){\n    T q = div_floor(x,\
    \ y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\
    \u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\n\
    pair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n    return {q, x - q\
    \ * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT round(T x, U y){\n    T q, r;\n    tie (q, r) = divmod(x,\
    \ y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\
    \u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B\
    .\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n        if (y & 1) {\
    \ a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n    return a;\n}\n\n//\
    \ x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\
    \u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n    while (y){\n       \
    \ if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n        y >>= 1;\n  \
    \  }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT modpow(T\
    \ x, U y, T z) {\n    T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x)\
    \ %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n\
    }\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\n\
    ll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto &&x: X) { y+=x; }\n    return\
    \ y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T>\nT sum(vector<T> &X){\n    T y = T(0);\n    for (auto\
    \ &&x: X) { y += x; }\n    return y;\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\
    \u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a,\
    \ b)) \u3092\u6C42\u3081\u308B.\ntuple<ll, ll, ll> Extended_Euclid(ll a, ll b)\
    \ {\n    ll s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        ll q;\n    \
    \    tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n        tie(s,\
    \ t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u - q * v);\n\
    \    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\
    \u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll isqrt(const\
    \ ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n    while ((x\
    \ + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\n    return\
    \ x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\
    \u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return isqrt(N);\
    \ }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F\
    , 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x = isqrt(N);\n\
    \    return x * x == N ? x : x + 1;\n}\n#line 62 \"template/template.hpp\"\n\n\
    // inout\n#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class...\
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
    \ bit_length(x)); }\n#line 71 \"template/template.hpp\"\n\n// exception\n#line\
    \ 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n    private:\n\
    \    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\
    \u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\
    \u305B\u3093.\") {}\n\n    const char* what() const noexcept override {\n    \
    \    return message.c_str();\n    }\n};\n#line 4 \"Counting/Combination_Calculator.hpp\"\
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
    \ _fact_inv[n + 1] * _fact_inv[n];\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<typename\
    \ mint>\nclass Combination_Calculator {\n    private:\n    vector<mint> _fact,\
    \ _fact_inv;\n\n    void resize(const int m) {\n        if (m < _fact.size())\
    \ { return; }\n\n        int current_size = _fact.size();\n        int next_size\
    \ = min(max(2 * current_size, m + 1), mint::mod());\n\n        _fact.resize(next_size);\n\
    \        _fact_inv.resize(next_size);\n\n        for (int k = current_size; k\
    \ < next_size; k++) {\n            _fact[k] = k * _fact[k - 1];\n        }\n\n\
    \        _fact_inv.back() = _fact.back().inverse();\n\n        for (int k = next_size\
    \ - 2; k >= current_size; --k) {\n            _fact_inv[k] = (k + 1) * _fact_inv[k\
    \ + 1];\n        }\n    }\n\n    public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF: \u521D\u671F\u30B5\u30A4\u30BAn\u307E\u3067\u968E\u4E57\
    \u30FB\u9006\u968E\u4E57\u3092\u8A08\u7B97\u3059\u308B\n     * @param n \u521D\
    \u671F\u8A08\u7B97\u306E\u4E0A\u9650\n     */\n    Combination_Calculator(const\
    \ int n) {\n        _fact.emplace_back(1); _fact.emplace_back(1);\n        _fact_inv.emplace_back(1);\
    \ _fact_inv.emplace_back(1);\n\n        resize(n);\n    }\n\n    Combination_Calculator():\
    \ Combination_Calculator(0) {}\n\n    /**\n     * @brief k! \u3092\u53D6\u5F97\
    \n     */\n    mint fact(const int k) {\n        resize(k);\n        return _fact[k];\n\
    \    }\n\n    /**\n     * @brief (k!)^(-1) \u3092\u53D6\u5F97\n     */\n    mint\
    \ fact_inv(const int k) {\n        resize(k);\n        return _fact_inv[k];\n\
    \    }\n\n    /**\n     * @brief k \u306E\u9006\u5143 k^(-1) \u3092\u6C42\u3081\
    \u308B\n     * @param k \u9006\u5143\u3092\u6C42\u3081\u305F\u3044\u6570\n   \
    \  */\n    mint inv(const int k) {\n        if (k <= 0) { return 0; }\n\n    \
    \    resize(k);\n        return _fact_inv[k] * _fact[k - 1];\n    }\n\n    /**\n\
    \     * @brief \u7D44\u307F\u5408\u308F\u305B nCk \u3092\u8A08\u7B97\u3059\u308B\
    \n     */\n    mint nCr(const int n, const int r) {\n        if (!(0 <= r && r\
    \ <= n)) { return 0; }\n        resize(n);\n        return _fact[n] * _fact_inv[r]\
    \ * _fact_inv[n - r];\n    }\n\n    /**\n     * @brief \u9806\u5217 nPk \u3092\
    \u8A08\u7B97\u3059\u308B\n     */\n    mint nPr(const int n, const int r) {\n\
    \        if (!(0 <= r && r <= n)) { return 0; }\n        resize(n);\n        return\
    \ _fact[n] * _fact_inv[n - r];\n    }\n\n    /**\n     * @brief \u91CD\u8907\u7D44\
    \u5408\u305B nHk \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint nHr(const int\
    \ n, const int r) {\n        if (n == 0 && r == 0) { return 1; }\n\n        return\
    \ nCr(n + r - 1, r);\n    }\n\n    /**\n     * @brief \u591A\u9805\u4FC2\u6570\
    \ (k_sum)! / (k1! * k2! * ...) \u3092\u8A08\u7B97\u3059\u308B\n     */\n    mint\
    \ multinomial_coefficient(const vector<int> &ks) {\n        int k_sum = 0;\n \
    \       mint lower = 1;\n        for (int k: ks) {\n            k_sum += k;\n\
    \            lower *= _fact_inv[k];\n        }\n\n        resize(k_sum);\n\n \
    \       mint upper = _fact[k_sum];\n\n        return upper * lower;\n    }\n\n\
    \    mint catalan(const int n) {\n        if (n < 0) { return 0; }\n        resize(2\
    \ * n);\n        return _fact[2 * n] * _fact_inv[n + 1] * _fact_inv[n];\n    }\n\
    };\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Counting/Combination_Calculator.hpp
  requiredBy:
  - Counting/Q_Analog_Combination_Calculator.hpp
  timestamp: '2026-01-01 02:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/enumerate_combinatorics/q-Binomial_Coefficient_Prime_Mod.test.cpp
  - verify/yosupo_library_checker/enumerate_combinatorics/Binomial_Coefficient_Prime_Mod.test.cpp
documentation_of: Counting/Combination_Calculator.hpp
layout: document
title: "\u7D44\u307F\u5408\u308F\u305B\u8AD6\u306B\u95A2\u3059\u308B\u57FA\u672C\u7684\
  \u306A\u8A08\u7B97"
---

## Outline

組み合わせ論に関する基本的な計算を行う.

## Theory

### 組み合わせを表す関数

(人は互いに区別がつき, ものは互いに区別がつかないとする.)

||意味合い|計算方法|
|:--:|:--:|:--:|
|$N!$|$N$ 人を1列に並べる方法|$N!=1 \times 2 \times \dots \times N$|
|$\dbinom{N}{r}$|$N$ 人から $r$ 人を選び出す方法 |$\dbinom{N}{r}=\dfrac{N!}{r!(N-r)!}$|
|${}_N \mathrm{P}_r$|$N$ 人から $r$ 人を選び出し, その $r$ 人を一列に並べる方法|${}_N \mathrm{P}_r=\dfrac{N!}{(N-r)!}$|
|${}_N \mathrm{H}_r$|$N$ 個のものを $r$ 人に配る方法|${}_N \mathrm{H}_r=\dbinom{N+r-1}{r}$ <br> (ただし, $_0\mathrm{H}_0=1$ とする.)|
|$\dbinom{N}{r_1, r_2, \dots, r_m}$ <br> $(N=r_1+\dots+r_m)$|$N$ 人を $r_1$ 人の $1$ 班, $\cdots$, $r_m$ 人の $m$ 班に分ける方法|$\dbinom{N}{r_1,r_2, \dots, r_m}=\dfrac{N!}{r_1!r_2! \dots r_m!}$|
|$C_n$<br>(カタラン数)|$N$ 個の `(` と $N$ 個の `)` からなる文字列が正しい文字列になる文字列の数 (など) |$C_N=\dfrac{(2N)!}{(N+1)!N!}$|

## Contents

### Constructer

```cpp
Combination_Calculator(const int n)
```

* サイズが $n$ の組み合わせ論に関する基本的な計算を行う計算機を作成する.
* **計算量** : $O(n)$ 時間.

### fact

```cpp
calc.fact(const int k)
```

* $k!$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### fact_inv

```cpp
calc.fact_inv(const int k)
```

* $(k!)^{-1}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### inv

```cpp
calc.inv(const int k)
```

* $k^{-1}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nCr

```cpp
calc.nCr(const int n, const int r)
```

* 二項係数 $_n\mathrm{C}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nPr

```cpp
calc.nPr(const int n, const int r)
```

* 順列の数 $_n\mathrm{P}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nHr

```cpp
calc.nHr(const int n, const int r)
```

* 重複組合せ $_n\mathrm{H}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### multinomial_coefficient

```cpp
calc.multinomial_coefficient(const vector<int> &ks)
```

* 多項係数 $\dbinom{k_1+\dots+k_m}{k_1, \dots, k_m}$ を計算する.
* **計算量** : ならし $O(m)$ 時間.

### catalan

```cpp
calc.catalan(const int n)
```

* Catalan 数 $C_n := \dfrac{1}{n+1} \dbinom{2n}{n}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

