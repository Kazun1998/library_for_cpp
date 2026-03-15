---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Odd_Montgomery_Multiplication.hpp
    title: "\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97"
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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Integer/Pollard_Rho.hpp
    title: Integer/Pollard_Rho.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Factorize.test.cpp
    title: verify/yosupo_library_checker/number_theory/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
    title: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\
      \u6CD5\u306B\u3088\u308A\u3001\u4E0E\u3048\u3089\u308C\u305F\u6574\u6570\u304C\
      \u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002"
    links:
    - https://miller-rabin.appspot.com/
  bundledCode: "#line 2 \"Integer/Miller_Rabin_Primality_Test.hpp\"\n\n#line 2 \"\
    template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\
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
    \        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T,\
    \ integral U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n    \
    \    if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n\
    \    }\n\n    return a;\n}\n\ntemplate<typename T>\nT sum(const vector<T> &X)\
    \ {\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n\
    template<typename T>\nT gcd(const T x, const T y) {\n    return y == 0 ? x : gcd(y,\
    \ x % y);\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\
    \u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
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
    \ 64 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\n//\
    \ \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ... >>\
    \ a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout\
    \ << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
    \    return is;\n}\n\ntemplate<typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &P){\n    os << P.first << \" \" << P.second;\n    return\
    \ os;\n}\n\ntemplate<typename T>\nvector<T> vector_input(int N, int index){\n\
    \    vector<T> X(N+index);\n    for (int i=index; i<index+N; i++) cin >> X[i];\n\
    \    return X;\n}\n\ntemplate<typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &X){\n    for (auto &x: X) { is >> x; }\n    return is;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &X){\n    int s = (int)X.size();\n\
    \    for (int i = 0; i < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return\
    \ os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const unordered_set<T>\
    \ &S){\n    int i = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n\
    \    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ set<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a;\
    \ i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os\
    \ << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\n\
    ostream &operator<<(ostream &os, const multiset<T> &S){\n    int i = 0;\n    for\
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nstd::vector<T> input_vector(size_t n, size_t offset = 0) {\n    std::vector<T>\
    \ res;\n    // \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\
    \u4FDD\uFF08\u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n\
    \    // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
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
    \ 6 \"Integer/Miller_Rabin_Primality_Test.hpp\"\n\n/// @brief \u30DF\u30E9\u30FC\
    \u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5\u306B\u3088\u308A\u3001\
    \u4E0E\u3048\u3089\u308C\u305F\u6574\u6570\u304C\u7D20\u6570\u304B\u3069\u3046\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n/// @param n \u5224\u5B9A\u5BFE\u8C61\
    \u306E\u6574\u6570 (n <= 2^64 - 1)\n/// @return n \u304C\u7D20\u6570\u3067\u3042\
    \u308C\u3070 true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 false \u3092\
    \u8FD4\u3059\u3002\n/// @note 2^64 \u672A\u6E80\u306E\u6574\u6570\u306B\u5BFE\u3057\
    \u3066\u306F\u6C7A\u5B9A\u7684\u306A\u5224\u5B9A\u3092\u884C\u3046\u3002\n///\
    \ @see https://miller-rabin.appspot.com/\nbool Miller_Rabin_Primality_Test(uint64_t\
    \ n) {\n    if (n <= 1) return false;\n    if (n % 2 == 0) return n == 2; \n\n\
    \    int s; uint64_t d;\n    tie (s, d) = prime::exponents(n - 1, 2);\n\n    Odd_Montgomery_Multiplication\
    \ calculator(n);\n    auto challenge = [&n, &s, &d, &calculator](uint64_t a) ->\
    \ bool {\n        a %= n;\n        if (a == 0) return true;\n\n        auto y\
    \ = calculator.modpow(a, d);\n        if (y == 1 || y == n - 1) return true;\n\
    \n        rep(s) {\n            y = calculator.mod_mul(y, y);\n            if\
    \ (y == n - 1) return true;\n        }\n\n        return false;\n    };\n\n  \
    \  // n \u306E\u5024\u306B\u5FDC\u3058\u3066\u3001\u6C7A\u5B9A\u7684\u7D20\u6570\
    \u5224\u5B9A\u306B\u4F7F\u7528\u3059\u308B witness (\u8A3C\u4EBA) \u306E\u30EA\
    \u30B9\u30C8\u3092\u9078\u629E\u3059\u308B\u3002\n    // \u3053\u308C\u3089\u306E\
    \u30EA\u30B9\u30C8\u306F\u3001\u7279\u5B9A\u306E\u7BC4\u56F2\u5185\u306E\u6570\
    \u306B\u5BFE\u3057\u3066\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u6CD5\u304C\
    \u78BA\u7387\u7684\u3067\u306A\u304F\u6C7A\u5B9A\u7684\u306B\u306A\u308B\u3053\
    \u3068\u3092\u4FDD\u8A3C\u3059\u308B\u3002\n    if (n < 4759123141) {\n      \
    \  // 32\u30D3\u30C3\u30C8\u6574\u6570 (\u7B26\u53F7\u306A\u3057) \u306E\u7BC4\
    \u56F2\u3088\u308A\u5C11\u3057\u5927\u304D\u3044\u5024\u307E\u3067\u3092\u30AB\
    \u30D0\u30FC\n        for (const uint64_t a : {2, 7, 61}) {\n            if (n\
    \ == a) return true; // n \u304C witness \u81EA\u8EAB\u306E\u5834\u5408\u306F\u7D20\
    \u6570\n            unless(challenge(a)) return false;\n        }\n    } else\
    \ {\n        // 64\u30D3\u30C3\u30C8\u6574\u6570 (\u7B26\u53F7\u306A\u3057) \u306E\
    \u7BC4\u56F2\u3092\u30AB\u30D0\u30FC\n        for (const uint64_t a : {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022}) {\n            // \u3053\u306E\u5834\
    \u5408\u3001n > a \u304C\u4FDD\u8A3C\u3055\u308C\u308B\u305F\u3081\u3001n == a\
    \ \u306E\u30C1\u30A7\u30C3\u30AF\u306F\u4E0D\u8981\n            unless(challenge(a))\
    \ return false;\n        }\n    }\n\n    return true;\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"Prime.hpp\"\
    \n#include \"Odd_Montgomery_Multiplication.hpp\"\n\n/// @brief \u30DF\u30E9\u30FC\
    \u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5\u306B\u3088\u308A\u3001\
    \u4E0E\u3048\u3089\u308C\u305F\u6574\u6570\u304C\u7D20\u6570\u304B\u3069\u3046\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n/// @param n \u5224\u5B9A\u5BFE\u8C61\
    \u306E\u6574\u6570 (n <= 2^64 - 1)\n/// @return n \u304C\u7D20\u6570\u3067\u3042\
    \u308C\u3070 true\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 false \u3092\
    \u8FD4\u3059\u3002\n/// @note 2^64 \u672A\u6E80\u306E\u6574\u6570\u306B\u5BFE\u3057\
    \u3066\u306F\u6C7A\u5B9A\u7684\u306A\u5224\u5B9A\u3092\u884C\u3046\u3002\n///\
    \ @see https://miller-rabin.appspot.com/\nbool Miller_Rabin_Primality_Test(uint64_t\
    \ n) {\n    if (n <= 1) return false;\n    if (n % 2 == 0) return n == 2; \n\n\
    \    int s; uint64_t d;\n    tie (s, d) = prime::exponents(n - 1, 2);\n\n    Odd_Montgomery_Multiplication\
    \ calculator(n);\n    auto challenge = [&n, &s, &d, &calculator](uint64_t a) ->\
    \ bool {\n        a %= n;\n        if (a == 0) return true;\n\n        auto y\
    \ = calculator.modpow(a, d);\n        if (y == 1 || y == n - 1) return true;\n\
    \n        rep(s) {\n            y = calculator.mod_mul(y, y);\n            if\
    \ (y == n - 1) return true;\n        }\n\n        return false;\n    };\n\n  \
    \  // n \u306E\u5024\u306B\u5FDC\u3058\u3066\u3001\u6C7A\u5B9A\u7684\u7D20\u6570\
    \u5224\u5B9A\u306B\u4F7F\u7528\u3059\u308B witness (\u8A3C\u4EBA) \u306E\u30EA\
    \u30B9\u30C8\u3092\u9078\u629E\u3059\u308B\u3002\n    // \u3053\u308C\u3089\u306E\
    \u30EA\u30B9\u30C8\u306F\u3001\u7279\u5B9A\u306E\u7BC4\u56F2\u5185\u306E\u6570\
    \u306B\u5BFE\u3057\u3066\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u6CD5\u304C\
    \u78BA\u7387\u7684\u3067\u306A\u304F\u6C7A\u5B9A\u7684\u306B\u306A\u308B\u3053\
    \u3068\u3092\u4FDD\u8A3C\u3059\u308B\u3002\n    if (n < 4759123141) {\n      \
    \  // 32\u30D3\u30C3\u30C8\u6574\u6570 (\u7B26\u53F7\u306A\u3057) \u306E\u7BC4\
    \u56F2\u3088\u308A\u5C11\u3057\u5927\u304D\u3044\u5024\u307E\u3067\u3092\u30AB\
    \u30D0\u30FC\n        for (const uint64_t a : {2, 7, 61}) {\n            if (n\
    \ == a) return true; // n \u304C witness \u81EA\u8EAB\u306E\u5834\u5408\u306F\u7D20\
    \u6570\n            unless(challenge(a)) return false;\n        }\n    } else\
    \ {\n        // 64\u30D3\u30C3\u30C8\u6574\u6570 (\u7B26\u53F7\u306A\u3057) \u306E\
    \u7BC4\u56F2\u3092\u30AB\u30D0\u30FC\n        for (const uint64_t a : {2, 325,\
    \ 9375, 28178, 450775, 9780504, 1795265022}) {\n            // \u3053\u306E\u5834\
    \u5408\u3001n > a \u304C\u4FDD\u8A3C\u3055\u308C\u308B\u305F\u3081\u3001n == a\
    \ \u306E\u30C1\u30A7\u30C3\u30AF\u306F\u4E0D\u8981\n            unless(challenge(a))\
    \ return false;\n        }\n    }\n\n    return true;\n}"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Integer/Prime.hpp
  - Integer/Odd_Montgomery_Multiplication.hpp
  isVerificationFile: false
  path: Integer/Miller_Rabin_Primality_Test.hpp
  requiredBy:
  - Integer/Pollard_Rho.hpp
  timestamp: '2026-03-12 01:05:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Factorize.test.cpp
  - verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
documentation_of: Integer/Miller_Rabin_Primality_Test.hpp
layout: document
title: "\u30DF\u30E9\u30FC\u30FB\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5"
---

## Outline

ミラー・ラビン素数判定法による高速な素数判定を行う.

## Theory

$n$ が素数かどうかを判定する. $n$ が偶数のときは自明なので, $n$ が奇数であるとする.

---

$p$ が素数であるとする. このとき, $x$ に関する方程式

$$ x^2 \equiv 1 \pmod{p} $$

について,

$$ (x-1)(x+1) \equiv 0 \pmod{p} $$

と変形できる. $n$ が素数であるため,

$$ x \equiv 1 \pmod{p} \quad \lor \quad x \equiv -1 \pmod{p} $$

が成り立つことに注意する.

---

$3$ 以上の奇数 $n$ は素数であると仮定する. $n$ が奇数なので, 正の整数 $s$ と奇数 $d$ を用いて, $n - 1 = 2^s \cdot d$ と表せる.

$n$ の倍数ではない整数 $a$ について, Fermat の小定理により,

$$ a^{n-1} \equiv 1 \pmod{n} $$

が成り立つ. つまり,

$$ a^{n-1} - 1 = a^{2^s \cdot d} - 1 \equiv 0 \pmod{n} $$

となる. 左辺について, 因数分解を行うことによって,

$$ a^{2^s \cdot d} - 1 = (a^{2^{s-1}} + 1) \dots (a^{2^1} + 1)(a^{2^0} + 1) (a^d - 1) \equiv 0 \pmod{n} $$

$n$ は素数であると仮定しているため, 以下のうちのどれかが成り立つ.

* $a^d \equiv 1 \pmod{n}$.
* $0 \leq r \lt s$ となる整数 $r$ が存在して, $a^{2^r \cdot d} \equiv -1 \pmod{n}$.

よって, 対偶を取ることによって, 次が従うことがわかる.

ある $n$ の倍数でない $a$ が存在して, 以下が成り立つとする.

* $a^d \not \equiv 1 \pmod{n}$.
* $0 \leq r \lt s$ なる任意の整数 $r$ に対して, $a^{2^r \cdot d} \not \equiv -1 \pmod{n}$.

このとき, $n$ は合成数である.

---

$1$ つの $a$ について判定を行ったとする. $1$ つの $a$ について判定しただけでは必要条件であるため, 「合成数である」は正しいが, 「素数である」は正しいとは限らない.

ここで, $a$ としてランダムに取ると, $n$ が本来ならば合成数なのに, 素数と判定してしまう確率が $1/4$ 以下になることが証明されている. そのため, 複数個の $a$ について判定すれば, 偽陽性の確率を減らすことができる.

また, $n$ が特定の範囲に収まっているならば, 固定された $a$ たちを使うことによって確定的にすることができる ([参考ページ](https://miller-rabin.appspot.com/#)).

* $n < 4759123141$ のときは, $a = 2, 7, 61$ のみを調べればよい (Gerhard Jaeschke: 1993)
* $n < 2^{64}$ のときは, $a = 2, 325, 9375, 28178, 450775, 9780504, 1795265022$ のみを調べれば良い (Jim Sinclair: 2011/04/20).

## Contents

### Miller_Rabin_Primality_Test

```cpp
bool Miller_Rabin_Primality_Test(uint64_t n)
```

* $n$ が素数かどうかを判定する.
* **計算量** : 判定に使う $a$ の数を $k$ として, $O \left( k \log N \right)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/03/11| モンゴメリ乗算と固定された証人の理論を用いた高速化 |
|2025/09/06| Miller_Rabin_Primality_Test の実装 |
