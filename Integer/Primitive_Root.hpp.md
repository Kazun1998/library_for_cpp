---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Miller_Rabin_Primality_Test.hpp
    title: "\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5"
  - icon: ':heavy_check_mark:'
    path: Integer/Odd_Montgomery_Multiplication.hpp
    title: "\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97"
  - icon: ':heavy_check_mark:'
    path: Integer/Pollard_Rho.hpp
    title: Integer/Pollard_Rho.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Prime.hpp
    title: Integer/Prime.hpp
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
    path: verify/yosupo_library_checker/number_theory/Primitive_Root.test.cpp
    title: verify/yosupo_library_checker/number_theory/Primitive_Root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "n \u304C\u539F\u59CB\u6839\u3092\u6301\u3064\u304B\u3069\u3046\
      \u304B\u3092\u5224\u5B9A\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"Integer/Primitive_Root.hpp\"\n\n#line 2 \"Integer/Pollard_Rho.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\
    \n\nusing ll = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B\
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
    \ {\n        return message.c_str();\n    }\n};\n#line 2 \"Integer/Prime.hpp\"\
    \n\n#line 4 \"Integer/Prime.hpp\"\n\nnamespace prime {\n  class Pseudo_Prime_Generator\
    \ {\n    private:\n    long long prime = 1, step = 0;\n\n    public:\n    long\
    \ long get() {\n      if (step) {\n        prime += step;\n        step = 6 -\
    \ step;\n      }\n      else if (prime == 1) { prime = 2; }\n      else if (prime\
    \ == 2) { prime = 3; }\n      else if (prime == 3) { prime = 5, step = 2; }\n\n\
    \      return prime;\n    }\n  };\n\n  // n \u306F\u7D20\u6570?\n  bool is_prime(long\
    \ long n) {\n    if (n <= 3) { return n >= 2; }\n    else if (n == 5) { return\
    \ true; }\n    else if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return\
    \ false; }\n\n    Pseudo_Prime_Generator generator;\n    for (long long p = generator.get();\
    \ p * p <= n; p = generator.get()) {\n      if (n % p == 0) { return false; }\n\
    \    }\n\n    return true;\n  }\n\n  pair<uint64_t, long long> exponents(uint64_t\
    \ n, long long p) {\n    long long e = 0;\n    while (n % p == 0) { e++, n /=\
    \ p; }\n    return {e, n};\n  }\n\n  // \u7D20\u56E0\u6570\u5206\u89E3\n  vector<pair<long\
    \ long, long long>> prime_factorization (long long n) {\n    if (n == 0) { return\
    \ { make_pair(0, 0) }; } \n\n    vector<pair<long long, long long>> factors;\n\
    \    if (n < 0) {\n      factors.emplace_back(make_pair(-1, 1));\n      n = abs(n);\n\
    \    }\n\n    Pseudo_Prime_Generator generator;\n    for (long long p =generator.get();\
    \ p * p <= n; p = generator.get()) {\n      long long e;\n      tie(e, n) = exponents(n,\
    \ p); \n      if (e) { factors.emplace_back(make_pair(p, e)); }\n    }\n\n   \
    \ if (n > 1) { factors.emplace_back(make_pair(n, 1)); }\n  \n    return factors;\n\
    \  }\n\n  // n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\
    \u6210\u3059\u308B.\n  vector<long long> prime_list(long long n) {\n    if (n\
    \ == 0 || n == 1) { return {}; }\n    else if (n == 2) { return {2}; }\n\n   \
    \ if (n % 2 == 0) { n--; }\n\n    long long m = (n + 1) / 2;\n\n    // prime_flag[k]\
    \ := (2k+1) \u306F\u7D20\u6570\u304B?\n    vector<bool> prime_flag(m, true);\n\
    \    prime_flag[0] = false;\n\n    // 9 \u4EE5\u4E0A\u306E 3 \u306E\u500D\u6570\
    \u3092\u6D88\u3059.\n    for (long long x = 4; x < m; x += 3) { prime_flag[x]\
    \ = false; }\n\n    auto generator = Pseudo_Prime_Generator();\n    for (auto\
    \ p = generator.get(); p * p <= n; p = generator.get()) {\n      if (p <= 3) {\
    \ continue; }\n\n      if (!prime_flag[(p - 1) / 2]) { continue; }\n\n      for\
    \ (auto j = (p * p - 1) / 2; j < m; j += p) { prime_flag[j] = false; }\n    }\n\
    \n    vector<long long> primes{2};\n\n    for (long long k = 0; k < m; k++) {\n\
    \      if (prime_flag[k]) { primes.emplace_back(2 * k + 1); }\n    }\n\n    return\
    \ primes;\n  }\n}\n#line 3 \"Integer/Odd_Montgomery_Multiplication.hpp\"\n\nstruct\
    \ Odd_Montgomery_Multiplication {\n    using u64 = uint64_t;\n    using u128 =\
    \ __uint128_t;\n\n    /// @brief \u5270\u4F59\n    u64 mod;\n\n    /// @brief\
    \ N = mod \u3068\u3057\u305F\u3068\u304D, NN' \u2261 -1 (mod R) \u3092\u6E80\u305F\
    \u3059 N'\n    u64 neg_inv;\n\n    /// @brief (2^64)^2 mod N\n    u64 r2;\n\n\
    \    Odd_Montgomery_Multiplication(u64 mod) : mod(mod) {\n        u64 inv = mod;\n\
    \        for (int i = 0; i < 5; ++i) inv *= 2 - mod * inv;\n        neg_inv =\
    \ -inv;\n        u128 r = -mod % mod;\n        r2 = (r * r) % mod;\n    }\n\n\
    \    /// @brief \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\
    . T * R^{-1} mod N \u3092\u8A08\u7B97\u3059\u308B.\n    /// @param T 0 <= T <\
    \ N * R\n    /// @return T * R^{-1} mod N\n    u64 reduce(u128 T) const {\n  \
    \      u64 m = u64(T) * neg_inv;\n        u64 t = (T + (u128)m * mod) >> 64;\n\
    \        if (t >= mod) { t -= mod; }\n        return t;\n    }\n\n    /// @brief\
    \ \u901A\u5E38\u306E\u6574\u6570 a \u3092\u30E2\u30F3\u30B4\u30E1\u30EA\u8868\u73FE\
    \ aR mod N \u306B\u5909\u63DB\u3059\u308B.\n    /// @param a 0 <= a < N\n    ///\
    \ @return aR mod N\n    u64 form(u64 a) const { return reduce((u128)a * r2); }\n\
    \n    /// @brief \u30E2\u30F3\u30B4\u30E1\u30EA\u8868\u73FE\u3055\u308C\u305F\u6570\
    \ a, b \u306E\u7A4D\u3092\u8A08\u7B97\u3059\u308B.\n    /// @param a \u30E2\u30F3\
    \u30B4\u30E1\u30EA\u8868\u73FE\u3055\u308C\u305F\u6570\n    /// @param b \u30E2\
    \u30F3\u30B4\u30E1\u30EA\u8868\u73FE\u3055\u308C\u305F\u6570\n    /// @return\
    \ a * b \u306E\u30E2\u30F3\u30B4\u30E1\u30EA\u8868\u73FE\n    u64 multiply(u64\
    \ a, u64 b) const { return reduce((u128)a * b); }\n\n    /// @brief \u901A\u5E38\
    \u306E\u6574\u6570 a, b \u306E\u7A4D a * b mod N \u3092\u8A08\u7B97\u3059\u308B\
    .\n    /// @param a 0 <= a < N\n    /// @param b 0 <= b < N\n    /// @return a\
    \ * b mod N\n    u64 mod_mul(u64 a, u64 b) const { return reduce(multiply(form(a),\
    \ form(b))); }\n\n    /// @brief a^b mod N \u3092\u8A08\u7B97\u3059\u308B.\n \
    \   /// @param a \u57FA\u6570\n    /// @param b \u6307\u6570\n    /// @return\
    \ a^b mod N\n    u64 modpow(u64 a, u64 b) const {\n        u64 res = form(1);\n\
    \        u64 mont_a = form(a);\n        while (b > 0) {\n            if (b & 1)\
    \ res = multiply(res, mont_a);\n            mont_a = multiply(mont_a, mont_a);\n\
    \            b >>= 1;\n        }\n        return reduce(res);\n    }\n};\n#line\
    \ 2 \"Integer/Miller_Rabin_Primality_Test.hpp\"\n\n#line 6 \"Integer/Miller_Rabin_Primality_Test.hpp\"\
    \n\n/// @brief \u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\
    \u6CD5\u306B\u3088\u308A\u3001\u4E0E\u3048\u3089\u308C\u305F\u6574\u6570\u304C\
    \u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n///\
    \ @param n \u5224\u5B9A\u5BFE\u8C61\u306E\u6574\u6570 (n <= 2^64 - 1)\n/// @return\
    \ n \u304C\u7D20\u6570\u3067\u3042\u308C\u3070 true\u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 false \u3092\u8FD4\u3059\u3002\n/// @note 2^64 \u672A\u6E80\
    \u306E\u6574\u6570\u306B\u5BFE\u3057\u3066\u306F\u6C7A\u5B9A\u7684\u306A\u5224\
    \u5B9A\u3092\u884C\u3046\u3002\n/// @see https://miller-rabin.appspot.com/\nbool\
    \ Miller_Rabin_Primality_Test(uint64_t n) {\n    if (n <= 1) return false;\n \
    \   if (n % 2 == 0) return n == 2; \n\n    int s; uint64_t d;\n    tie (s, d)\
    \ = prime::exponents(n - 1, 2);\n\n    Odd_Montgomery_Multiplication calculator(n);\n\
    \    auto challenge = [&n, &s, &d, &calculator](uint64_t a) -> bool {\n      \
    \  a %= n;\n        if (a == 0) return true;\n\n        auto y = calculator.modpow(a,\
    \ d);\n        if (y == 1 || y == n - 1) return true;\n\n        rep(s) {\n  \
    \          y = calculator.mod_mul(y, y);\n            if (y == n - 1) return true;\n\
    \        }\n\n        return false;\n    };\n\n    // n \u306E\u5024\u306B\u5FDC\
    \u3058\u3066\u3001\u6C7A\u5B9A\u7684\u7D20\u6570\u5224\u5B9A\u306B\u4F7F\u7528\
    \u3059\u308B witness (\u8A3C\u4EBA) \u306E\u30EA\u30B9\u30C8\u3092\u9078\u629E\
    \u3059\u308B\u3002\n    // \u3053\u308C\u3089\u306E\u30EA\u30B9\u30C8\u306F\u3001\
    \u7279\u5B9A\u306E\u7BC4\u56F2\u5185\u306E\u6570\u306B\u5BFE\u3057\u3066\u30DF\
    \u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u6CD5\u304C\u78BA\u7387\u7684\u3067\u306A\
    \u304F\u6C7A\u5B9A\u7684\u306B\u306A\u308B\u3053\u3068\u3092\u4FDD\u8A3C\u3059\
    \u308B\u3002\n    if (n < 4759123141) {\n        // 32\u30D3\u30C3\u30C8\u6574\
    \u6570 (\u7B26\u53F7\u306A\u3057) \u306E\u7BC4\u56F2\u3088\u308A\u5C11\u3057\u5927\
    \u304D\u3044\u5024\u307E\u3067\u3092\u30AB\u30D0\u30FC\n        for (const uint64_t\
    \ a : {2, 7, 61}) {\n            if (n == a) return true; // n \u304C witness\
    \ \u81EA\u8EAB\u306E\u5834\u5408\u306F\u7D20\u6570\n            unless(challenge(a))\
    \ return false;\n        }\n    } else {\n        // 64\u30D3\u30C3\u30C8\u6574\
    \u6570 (\u7B26\u53F7\u306A\u3057) \u306E\u7BC4\u56F2\u3092\u30AB\u30D0\u30FC\n\
    \        for (const uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\n            // \u3053\u306E\u5834\u5408\u3001n > a \u304C\u4FDD\u8A3C\u3055\
    \u308C\u308B\u305F\u3081\u3001n == a \u306E\u30C1\u30A7\u30C3\u30AF\u306F\u4E0D\
    \u8981\n            unless(challenge(a)) return false;\n        }\n    }\n\n \
    \   return true;\n}\n#line 7 \"Integer/Pollard_Rho.hpp\"\n\nuint64_t Find_Prime_Factor_by_Pollard_Rho(uint64_t\
    \ n) {\n    if (n == 1) return 1;\n    if (n % 2 == 0) return 2;\n    if (Miller_Rabin_Primality_Test(n))\
    \ return n;\n\n    Odd_Montgomery_Multiplication calc(n);\n\n    for (uint64_t\
    \ c = 1; c < 99; ++c) {\n        uint64_t mc = calc.form(c);\n        auto f =\
    \ [&](uint64_t x) -> uint64_t {\n            uint64_t y = calc.multiply(x, x);\n\
    \            uint64_t z = y + mc;\n            if (z >= n) z -= n;\n         \
    \   return z;\n        };\n        \n        // form \u3067\u5909\u63DB\u3057\u305F\
    \u5F8C\u306E\u6574\u6570\u3067 gcd \u3092\u53D6\u3063\u3066\u3044\u308B\u304C\
    ,\n        // n \u304C\u5947\u6570\u3067, form \u3067\u306FOdd_Montgomery_Multiplication\
    \ \u306E\u53D6\u308A\u65B9\u7684\u306B n \u3068\u4E92\u3044\u306B\u7D20\u306A\
    2^64 \u3092\u304B\u3051\u3066 n \u3067\u5272\u3063\u3066\u3044\u308B\u305F\u3081\
    ,\n        // gcd \u306F\u4E0D\u5909\u3067\u3042\u308B.\n\n        uint64_t x\
    \ = calc.form(0), y = calc.form(0);\n        uint64_t g = 1;\n        uint64_t\
    \ q = calc.form(1);\n        uint64_t m = 500;\n\n        while (g == 1) {\n \
    \           uint64_t xs = x, ys = y;\n            for (int i = 0; i < m; ++i)\
    \ {\n                x = f(x);\n                y = f(f(y));\n               \
    \ uint64_t diff = x < y ? y - x : x - y;\n                q = calc.multiply(q,\
    \ diff);\n            }\n            g = gcd(q, n);\n            if (g == 1) continue;\n\
    \            if (g == n) {\n                g = 1;\n                x = xs; y\
    \ = ys;\n                while (g == 1) {\n                    x = f(x);\n   \
    \                 y = f(f(y));\n                    uint64_t diff = x < y ? y\
    \ - x : x - y;\n                    g = gcd(diff, n);\n                }\n   \
    \             if (g == n) break;\n            }\n\n            if (Miller_Rabin_Primality_Test(g))\
    \ return g;\n            if (Miller_Rabin_Primality_Test(n / g)) return n / g;\n\
    \            return Find_Prime_Factor_by_Pollard_Rho(g);\n        }\n    }\n \
    \   return n;\n}\n\nvector<pair<uint64_t, ll>> Prime_Factorization_by_Pollard_Rho(uint64_t\
    \ n) {\n    vector<pair<uint64_t, ll>> factors;\n    while (n > 1) {\n       \
    \ uint64_t p = Find_Prime_Factor_by_Pollard_Rho(n);\n        auto [e, m] = prime::exponents(n,\
    \ p);\n\n        factors.emplace_back(p, e);\n        n = m;\n    }\n\n    return\
    \ factors;\n}\n#line 5 \"Integer/Primitive_Root.hpp\"\n\n/// @brief n \u304C\u539F\
    \u59CB\u6839\u3092\u6301\u3064\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\n/// @param n \n/// @return n \u304C\u539F\u59CB\u6839\u3092\u6301\u3064\
    \u306A\u3089 true, \u305D\u3046\u3067\u306A\u3044\u306A\u3089 false\nbool has_Primitive_Root(const\
    \ uint64_t n) {\n    // n \u304C\u539F\u59CB\u6839\u3092\u6301\u3064\u305F\u3081\
    \u306E\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\n    // n = (1,) 2, 4, p^k, 2p^k\
    \ (p: \u5947\u7D20\u6570, k: \u6B63\u306E\u6574\u6570)\n    // \u3067\u8868\u305B\
    \u308B\u3053\u3068\u3067\u3042\u308B.\n\n    if (n <= 1) return n == 1;\n    if\
    \ (n == 2 || n == 4) return true;\n    if (n % 4 == 0) return false;\n\n    uint64_t\
    \ m = (n % 2 == 0) ? n / 2 : n;\n    auto factors = Prime_Factorization_by_Pollard_Rho(m);\n\
    \    // m = p^k (p \u306F\u5947\u7D20\u6570) \u3067\u3042\u308B\u304B\u5224\u5B9A\
    \n    return factors.size() == 1 && factors[0].first != 2;\n}\n\n/// @brief n\
    \ \u306B\u304A\u3051\u308B\u539F\u59CB\u6839\u306E\u3046\u3061\u306E 1 \u3064\u3092\
    \u6C42\u3081\u308B\n/// @param n \u306F 2, 4, p^k, 2p^k \u306E\u3046\u3061\u306E\
    \u3044\u305A\u308C\u304B\u3067\u306A\u304F\u3066\u306F\u306A\u3089\u306A\u3044\
    \ (p: \u7D20\u6570)\n/// @return \u539F\u59CB\u6839\u306E 1 \u3064\n/// @note\
    \ \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\u306F 0 (n\
    \ = 1 \u306E\u3068\u304D\u3082\u8FD4\u308A\u5024 0 \u306A\u306E\u3067\u6CE8\u610F\
    ).\nuint64_t Find_Primitive_Root(const uint64_t n) {\n    // \u5076\u6570\u3068\
    \u3088\u304F\u4F7F\u308F\u308C\u308B\u7D20\u6570\u306F Early Return\n    if (n\
    \ == 1) return 0;\n    if (n == 2) return 1;\n    if (n == 4) return 3;\n    if\
    \ (n == 998244353) return 3;\n    if (n == 1000000007) return 5;\n\n    unless\
    \ (has_Primitive_Root(n)) return 0;\n\n    uint64_t m = (n % 2 == 0) ? n / 2 :\
    \ n;\n    auto factors = Prime_Factorization_by_Pollard_Rho(m);\n\n    // has_Primitive_Root(n)\
    \ \u304C true \u304B\u3064 n > 4 \u306A\u306E\u3067 m \u306F\u5FC5\u305A\u5947\
    \u7D20\u6570\u306E\u51AA p^k \u3068\u306A\u308B\n    // n = p^k \u306E\u3068\u304D\
    , phi(n) = n (p-1) / p = p^(k-1)(p-1)\n    // n = 2p^k \u306E\u3068\u304D, phi(n)\
    \ = n * (1/2) * (p-1)/p = p^(k-1)(p-1)\n    uint64_t p = factors[0].first;\n \
    \   uint64_t phi = (m / p) * (p - 1);\n    auto phi_factors = Prime_Factorization_by_Pollard_Rho(phi);\n\
    \    auto calc = Odd_Montgomery_Multiplication(m);\n\n    auto judge = [&](const\
    \ uint64_t g) {\n        for (auto [q, ignore]: phi_factors) {\n            if\
    \ (calc.modpow(g % m, phi / q) == 1) return false;\n        }\n\n        return\
    \ true;\n    };\n\n    for (uint64_t g = 2; g < n; ++g) {\n        unless (gcd(g,\
    \ n) == 1) continue;\n        if (judge(g)) return g;\n    }\n\n    return 0;\n\
    }\n"
  code: "#pragma once\n\n#include \"Pollard_Rho.hpp\"\n#include \"Odd_Montgomery_Multiplication.hpp\"\
    \n\n/// @brief n \u304C\u539F\u59CB\u6839\u3092\u6301\u3064\u304B\u3069\u3046\u304B\
    \u3092\u5224\u5B9A\u3059\u308B\n/// @param n \n/// @return n \u304C\u539F\u59CB\
    \u6839\u3092\u6301\u3064\u306A\u3089 true, \u305D\u3046\u3067\u306A\u3044\u306A\
    \u3089 false\nbool has_Primitive_Root(const uint64_t n) {\n    // n \u304C\u539F\
    \u59CB\u6839\u3092\u6301\u3064\u305F\u3081\u306E\u5FC5\u8981\u5341\u5206\u6761\
    \u4EF6\u306F\n    // n = (1,) 2, 4, p^k, 2p^k (p: \u5947\u7D20\u6570, k: \u6B63\
    \u306E\u6574\u6570)\n    // \u3067\u8868\u305B\u308B\u3053\u3068\u3067\u3042\u308B\
    .\n\n    if (n <= 1) return n == 1;\n    if (n == 2 || n == 4) return true;\n\
    \    if (n % 4 == 0) return false;\n\n    uint64_t m = (n % 2 == 0) ? n / 2 :\
    \ n;\n    auto factors = Prime_Factorization_by_Pollard_Rho(m);\n    // m = p^k\
    \ (p \u306F\u5947\u7D20\u6570) \u3067\u3042\u308B\u304B\u5224\u5B9A\n    return\
    \ factors.size() == 1 && factors[0].first != 2;\n}\n\n/// @brief n \u306B\u304A\
    \u3051\u308B\u539F\u59CB\u6839\u306E\u3046\u3061\u306E 1 \u3064\u3092\u6C42\u3081\
    \u308B\n/// @param n \u306F 2, 4, p^k, 2p^k \u306E\u3046\u3061\u306E\u3044\u305A\
    \u308C\u304B\u3067\u306A\u304F\u3066\u306F\u306A\u3089\u306A\u3044 (p: \u7D20\u6570\
    )\n/// @return \u539F\u59CB\u6839\u306E 1 \u3064\n/// @note \u5B58\u5728\u3057\
    \u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\u306F 0 (n = 1 \u306E\u3068\u304D\
    \u3082\u8FD4\u308A\u5024 0 \u306A\u306E\u3067\u6CE8\u610F).\nuint64_t Find_Primitive_Root(const\
    \ uint64_t n) {\n    // \u5076\u6570\u3068\u3088\u304F\u4F7F\u308F\u308C\u308B\
    \u7D20\u6570\u306F Early Return\n    if (n == 1) return 0;\n    if (n == 2) return\
    \ 1;\n    if (n == 4) return 3;\n    if (n == 998244353) return 3;\n    if (n\
    \ == 1000000007) return 5;\n\n    unless (has_Primitive_Root(n)) return 0;\n\n\
    \    uint64_t m = (n % 2 == 0) ? n / 2 : n;\n    auto factors = Prime_Factorization_by_Pollard_Rho(m);\n\
    \n    // has_Primitive_Root(n) \u304C true \u304B\u3064 n > 4 \u306A\u306E\u3067\
    \ m \u306F\u5FC5\u305A\u5947\u7D20\u6570\u306E\u51AA p^k \u3068\u306A\u308B\n\
    \    // n = p^k \u306E\u3068\u304D, phi(n) = n (p-1) / p = p^(k-1)(p-1)\n    //\
    \ n = 2p^k \u306E\u3068\u304D, phi(n) = n * (1/2) * (p-1)/p = p^(k-1)(p-1)\n \
    \   uint64_t p = factors[0].first;\n    uint64_t phi = (m / p) * (p - 1);\n  \
    \  auto phi_factors = Prime_Factorization_by_Pollard_Rho(phi);\n    auto calc\
    \ = Odd_Montgomery_Multiplication(m);\n\n    auto judge = [&](const uint64_t g)\
    \ {\n        for (auto [q, ignore]: phi_factors) {\n            if (calc.modpow(g\
    \ % m, phi / q) == 1) return false;\n        }\n\n        return true;\n    };\n\
    \n    for (uint64_t g = 2; g < n; ++g) {\n        unless (gcd(g, n) == 1) continue;\n\
    \        if (judge(g)) return g;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - Integer/Pollard_Rho.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Integer/Prime.hpp
  - Integer/Odd_Montgomery_Multiplication.hpp
  - Integer/Miller_Rabin_Primality_Test.hpp
  isVerificationFile: false
  path: Integer/Primitive_Root.hpp
  requiredBy: []
  timestamp: '2026-04-10 00:02:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Primitive_Root.test.cpp
documentation_of: Integer/Primitive_Root.hpp
layout: document
title: "\u539F\u59CB\u6839"
---

## Outline

$\mathbb{Z}/n \mathbb{Z}$ における原始根を求める.

## Definition

$g \in \mathbb{Z} / n \mathbb{Z}$ について, $\operatorname{ord} g = \varphi(n)$ が成り立つ時, $g$ は $\mathbb{Z} / n \mathbb{Z}$ における原始根という.

## Theory 

### 原始根の存在性

原始根の存在性について, 以下の特徴づけがある.

* (a) $\mathbb{Z}/n \mathbb{Z}$ における原始根が存在する.
* (b) $n$ はいずれかのうちのどれかである.
  * $n = 1, 2, 4$.
  * 奇素数 $p$ と正の整数 $k$ を用いて, $n = p^k$ である.
  * 奇素数 $p$ と正の整数 $k$ を用いて, $n = 2p^k$ である.

### 判定条件

$g \in \mathbb{Z}/n \mathbb{Z}$ が原始根かどうかを判定する. そのためには, 以下の特徴づけを用いる.

* (a) $g$ は $\mathbb{Z}/n \mathbb{Z}$ における原始根である.
* (b) 任意の $\varphi(n)$ の素因数 $q$ に対して, $g^{\frac{\varphi(n)}{q}} \neq 1$ である.

**証明**

#### (a) ならば (b)

対偶を示す.

ある $\varphi(n)$ の素因数 $q$ に対して, $g^{\frac{\varphi(n)}{q}} = 1$ だったとする.

このとき, $q > 1$ であるので, $\frac{\varphi(n)}{q} < \varphi(n)$ である. 故に, $g$ は原始根にならない.

#### (b) ならば (a)

対偶を示す.

$g$ は $\mathbb{Z}/n \mathbb{Z}$ における原始根でないとする. $g^r = 1, 1 \leq r < \varphi(n)$ となる整数 $r$ が存在する. Lagrange の定理により, $r$ は $\varphi(n)$ の真の約数である. 故に, $\frac{\varphi(n)}{r}$ の素因数 $q$ をとることができる.

このとき, $\frac{\varphi(n)}{q}$ は $r$ の倍数である. 故に, $\frac{\varphi(n)}{q} = ra$ となる整数 $a$ が存在する.

すると,

$$ g^{\frac{\varphi(n)}{q}} = g^{ra} = (g^r)^a = 1^a = 1 $$

となり, (b) が成り立たなくなる.


## Contents

### has_Primitive_Root

```cpp
bool has_Primitive_Root(const uint64_t n)
```

* $\mathbb{Z}/n\mathbb{Z}$ に原始根が存在するかどうかを判定する.
* **計算量** : $O(n^{1/4})$ 時間

### Find_Primitive_Root

```cpp
uint64_t Find_Primitive_Root(const uint64_t n)
```

* $\mathbb{Z}/n\mathbb{Z}$ に原始根を $1$ つ求める.
* **返り値**
  * 原始根が存在しない場合の返り値は $0$ になる.
  * $n = 1$ のときの返り値も $0$ になるため, 混同に注意.
* **計算量** : $O(n^{1/4})$ 時間

## History

|日付|内容|
|:---:|:---|
|2026/04/10| has_Primitive_Root, Find_Primitive_Root の実装 |
