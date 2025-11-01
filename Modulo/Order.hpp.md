---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Divisors.hpp
    title: Integer/Divisors.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Euler_Totient.hpp
    title: "Euler's Totient \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: Integer/Prime.hpp
    title: Integer/Prime.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Modulo.hpp
    title: Modulo/Modulo.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/Modulo_Order.test.cpp
    title: verify/yukicoder/Modulo_Order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Modulo/Order.hpp\"\n\n#line 2 \"Modulo/Modulo.hpp\"\n\n\
    #line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
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
    \ 1: 0);\n}\n#line 59 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// \u9664\u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){\
    \ return (x > 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0\
    \ ? (x + y - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT safe_mod(T\
    \ x, U y){\n    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092\
    \ y \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x,\
    \ y);\n    return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q,\
    \ r;\n    tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1\
    \ : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E\
    \ y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n \
    \   while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n        y >>=\
    \ 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\
    \u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x\
    \ *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\
    \u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n \
    \       if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>=\
    \ 1;\n    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto\
    \ &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T> &X){\n\
    \    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n// a\
    \ x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b)\
    \ \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntuple<ll,\
    \ ll, ll> Extended_Euclid(ll a, ll b) {\n    ll s = 1, t = 0, u = 0, v = 1;\n\
    \    while (b) {\n        ll q;\n        tie(q, a, b) = make_tuple(div_floor(a,\
    \ b), b, safe_mod(a, b));\n        tie(s, t) = make_pair(t, s - q * t);\n    \
    \    tie(u, v) = make_pair(v, u - q * v);\n    }\n\n    return make_tuple(s, u,\
    \ a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\
    \u306F, 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n    if (N <= 0) { return\
    \ 0; }\n\n    ll x = sqrt(N);\n    while ((x + 1) * (x + 1) <= N) { x++; }\n \
    \   while (x * x > N) { x--; }\n\n    return x;\n}\n\n// floor(sqrt(N)) \u3092\
    \u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll\
    \ floor_sqrt(const ll &N) { return isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\
    \u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const\
    \ ll &N) {\n    ll x = isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line\
    \ 62 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\n//\
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
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n#line 65\
    \ \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\n\n//\
    \ \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n#define unless(cond) if (!(cond))\n\
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
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 68 \"template/template.hpp\"\
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
    \ get_bits(x, bit_length(x)); }\n#line 4 \"Modulo/Modulo.hpp\"\n\nnamespace modulo\
    \ {\n    class DifferentModulus : public exception {\n      public: // public\u306B\
    \u6307\u5B9A\n      const char* what() const noexcept override { return \"\u7570\
    \u306A\u308B\u6CD5\u540C\u58EB\u306E\u56DB\u5247\u6F14\u7B97\u3067\u3059\"; }\n\
    \    };\n\n    struct Modulo {\n        long long a, n;\n\n        public:\n \
    \       // \u521D\u671F\u5316\n        Modulo(): a(0), n(1) {}\n        Modulo(long\
    \ long a, long long n): a((a % n + n) % n), n(n) {}\n\n        // \u30DE\u30A4\
    \u30CA\u30B9\u5143\n        Modulo operator-() const { return Modulo(-a, n); }\n\
    \n        // \u52A0\u6CD5\n        Modulo& operator+=(const Modulo &y) {\n   \
    \         if (n != y.n) { throw DifferentModulus(); }\n    \n            if ((a\
    \ += y.a) >= n) a -= n;\n            return *this;\n        }\n\n        Modulo&\
    \ operator+=(const long long &y) { return (*this) += Modulo(y, n); }\n\n     \
    \   friend Modulo operator+(const Modulo &x, const Modulo &y) { return Modulo(x)\
    \ += y ; }\n        friend Modulo operator+(const Modulo &x, const long long &a)\
    \ { return x + Modulo(a, x.n); }\n        friend Modulo operator+(const long long\
    \ &a, const Modulo &x) { return Modulo(a, x.n) + x; }\n\n        // \u6E1B\u6CD5\
    \n        Modulo& operator-=(const Modulo &y) {\n            if (n != y.n) { throw\
    \ DifferentModulus(); }\n            if ((a += (n - y.a)) >= n) a -= n;\n    \
    \        return *this;\n        }\n\n        Modulo& operator-=(const long long\
    \ &y) { return (*this) -= Modulo(y, n); }\n\n        friend Modulo operator-(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) -= y; }\n        friend Modulo\
    \ operator-(const Modulo &x, const long long &a) { return x - Modulo(a, x.n);\
    \ }\n        friend Modulo operator-(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) - x; }\n\n        // \u4E57\u6CD5\n        Modulo& operator*=(const\
    \ Modulo &y) {\n            if (n != y.n) { throw DifferentModulus(); }\n    \
    \        (a *= y.a) %= n;\n            return *this;\n        }\n\n        Modulo&\
    \ operator*=(const long long &y){return (*this) *= Modulo(y, n); }\n\n       \
    \ friend Modulo operator*(const Modulo &x, const Modulo &y) { return Modulo(x)\
    \ *= y; }\n        friend Modulo operator*(const Modulo &x, const long long &a)\
    \ { return x * Modulo(a,x.n); }\n        friend Modulo operator*(const long long\
    \ &a, const Modulo &x) { return Modulo(a, x.n) * x; }\n\n        // \u9664\u6CD5\
    \n        Modulo& operator/=(const Modulo &y){\n            if (n != y.n) { throw\
    \ DifferentModulus(); }\n            return (*this) *= y.inverse();\n        }\n\
    \n        Modulo& operator/=(const long long &y) {return (*this ) /= Modulo(y,\
    \ n); }\n\n        friend Modulo operator/(const Modulo &x, const Modulo &y) {\
    \ return Modulo(x) /= y; }\n        friend Modulo operator/(const Modulo &x, const\
    \ long long &a) { return x / Modulo(a, x.n); }\n        friend Modulo operator/(const\
    \ long long &a, const Modulo &x) { return Modulo(a, x.n) / x; }\n\n        //\
    \ \u9000\u5316\n        Modulo& degenerate(const int m){\n            a %= m;\
    \ n = m;\n            return *this;\n        }\n\n        // \u30E2\u30B8\u30E5\
    \u30E9\u30FC\u9006\u5143\n        bool invertible() const {\n            long\
    \ long x = a, y = n;\n            while (y) { swap(x = x % y, y); }\n        \
    \    return x == 1;\n        }\n\n        Modulo inverse() const{\n          \
    \  long long s = 1, t = 0;\n            long long x = a, y = n;\n            while\
    \ (y){\n                auto q = x / y;\n                swap(x -= q * y, y);\n\
    \                swap(s -= q * t, t);\n            }\n\n            return Modulo(s,\
    \ n);\n        }\n\n        // include?\n        bool is_member(ll x) { return\
    \ safe_mod(x - a, n) == 0; }\n\n        bool is_zero() { return is_member(0);\
    \ }\n        \n\n        // \u6BD4\u8F03\n        friend bool operator==(const\
    \ Modulo &x, const Modulo &y) { return x.a==y.a; }\n        friend bool operator==(const\
    \ Modulo &x, const long long &a) { return (x.a - a) % x.n == 0; }\n        friend\
    \ bool operator==(const long long &a, const Modulo &x) { return (a - x.a) % x.n\
    \ == 0; }\n\n        friend bool operator!=(const Modulo &x, const Modulo &y)\
    \ { return x.a != y.a; }\n        friend bool operator!=(const Modulo &x, const\
    \ long long &a) { return (x.a - a)% x.n != 0; }\n        friend bool operator!=(const\
    \ long long &a, const Modulo &x) { return (a - x.a)% x.n != 0; }\n\n        //\
    \ \u5165\u529B\n        friend istream &operator>>(istream &is, Modulo &x) {\n\
    \            long long b, m;\n            is >> b >> m;\n            x = Modulo(b,\
    \ m);\n            return (is);\n        }\n\n        // \u51FA\u529B\n      \
    \  friend ostream &operator<<(ostream &os, const Modulo &x) { return os << x.a\
    \ << \" (mod \" << x.n << \")\"; }\n    };\n\n    Modulo pow(Modulo x, long long\
    \ n) {\n        if (n < 0) { return pow(x, -n).inverse(); }\n\n        auto res\
    \ = Modulo(1, x.n);\n        for (; n; n >>= 1) {\n            if (n & 1) { res\
    \ *= x; }\n            x *= x;\n        }\n\n        return res;\n    }\n}\n#line\
    \ 2 \"Integer/Euler_Totient.hpp\"\n\n#line 2 \"Integer/Prime.hpp\"\n\n#line 4\
    \ \"Integer/Prime.hpp\"\n\nnamespace prime {\n  class Pseudo_Prime_Generator {\n\
    \    private:\n    long long prime = 1, step = 0;\n\n    public:\n    long long\
    \ get() {\n      if (step) {\n        prime += step;\n        step = 6 - step;\n\
    \      }\n      else if (prime == 1) { prime = 2; }\n      else if (prime == 2)\
    \ { prime = 3; }\n      else if (prime == 3) { prime = 5, step = 2; }\n\n    \
    \  return prime;\n    }\n  };\n\n  // n \u306F\u7D20\u6570?\n  bool is_prime(long\
    \ long n) {\n    if (n <= 3) { return n >= 2; }\n    else if (n == 5) { return\
    \ true; }\n    else if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return\
    \ false; }\n\n    Pseudo_Prime_Generator generator;\n    for (long long p = generator.get();\
    \ p * p <= n; p = generator.get()) {\n      if (n % p == 0) { return false; }\n\
    \    }\n\n    return true;\n  }\n\n  pair<long long, long long> exponents(long\
    \ long n, long long p) {\n    long long e = 0;\n    while (n % p == 0) { e++,\
    \ n /= p; }\n    return {e, n};\n  }\n\n  // \u7D20\u56E0\u6570\u5206\u89E3\n\
    \  vector<pair<long long, long long>> prime_factorization (long long n) {\n  \
    \  if (n == 0) { return { make_pair(0, 0) }; } \n\n    vector<pair<long long,\
    \ long long>> factors;\n    if (n < 0) {\n      factors.emplace_back(make_pair(-1,\
    \ 1));\n      n = abs(n);\n    }\n\n    Pseudo_Prime_Generator generator;\n  \
    \  for (long long p =generator.get(); p * p <= n; p = generator.get()) {\n   \
    \   long long e;\n      tie(e, n) = exponents(n, p); \n      if (e) { factors.emplace_back(make_pair(p,\
    \ e)); }\n    }\n\n    if (n > 1) { factors.emplace_back(make_pair(n, 1)); }\n\
    \  \n    return factors;\n  }\n\n  // n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\
    \u30B9\u30C8\u3092\u4F5C\u6210\u3059\u308B.\n  vector<long long> prime_list(long\
    \ long n) {\n    if (n == 0 || n == 1) { return {}; }\n    else if (n == 2) {\
    \ return {2}; }\n\n    if (n % 2 == 0) { n--; }\n\n    long long m = (n + 1) /\
    \ 2;\n\n    // prime_flag[k] := (2k+1) \u306F\u7D20\u6570\u304B?\n    vector<bool>\
    \ prime_flag(m, true);\n    prime_flag[0] = false;\n\n    // 9 \u4EE5\u4E0A\u306E\
    \ 3 \u306E\u500D\u6570\u3092\u6D88\u3059.\n    for (long long x = 4; x < m; x\
    \ += 3) { prime_flag[x] = false; }\n\n    auto generator = Pseudo_Prime_Generator();\n\
    \    for (auto p = generator.get(); p * p <= n; p = generator.get()) {\n     \
    \ if (p <= 3) { continue; }\n\n      if (!prime_flag[(p - 1) / 2]) { continue;\
    \ }\n\n      for (auto j = (p * p - 1) / 2; j < m; j += p) { prime_flag[j] = false;\
    \ }\n    }\n\n    vector<long long> primes{2};\n\n    for (long long k = 0; k\
    \ < m; k++) {\n      if (prime_flag[k]) { primes.emplace_back(2 * k + 1); }\n\
    \    }\n\n    return primes;\n  }\n}\n#line 4 \"Integer/Euler_Totient.hpp\"\n\n\
    long long Euler_Totient(long long N, bool mode = true) {\n    if (N == 1) { return\
    \ mode ? 1 : 0; }\n\n    long long phi = 1;\n    for (auto &&[p, e]: prime::prime_factorization(N))\
    \ {\n        phi *= p - 1;\n        for (int k = 0; k < e - 1; k++) { phi *= p;\
    \ }\n    }\n\n    return phi;\n}\n#line 2 \"Integer/Divisors.hpp\"\n\n#line 4\
    \ \"Integer/Divisors.hpp\"\n\n// N \u4EE5\u4E0B\u306E\u7D04\u6570\u3092\u5217\u6319\
    \nvector<ll> Divisors(ll N) {\n    vector<ll> divisors;\n    for (int x = 1; x\
    \ * x <= N; x++){\n        unless(N % x == 0) { continue; }\n\n        divisors.emplace_back(x);\n\
    \        if (N / x != x) { divisors.emplace_back(N / x); }\n    }\n\n    sort(all(divisors));\n\
    \n    return divisors;\n}\n#line 6 \"Modulo/Order.hpp\"\n\nnamespace modulo {\n\
    \    // X \u306E\u4F4D\u6570\u3092\u6C42\u3081\u308B\n    ll Order(const Modulo\
    \ &X, ll irreversible = -1) { \n        ll phi = Euler_Totient(X.n);\n\n     \
    \   ll a = X.n + 1;\n        for (ll k = 1; k * k <= phi; k++) {\n           \
    \ unless(phi % k == 0) { continue; }\n\n            if (k < a && pow(X, k).is_member(1))\
    \ { return k; }\n\n            if (phi / k < a && pow(X, phi / k).is_member(1))\
    \ { a = phi / k; }\n        }\n\n        return a < X.n + 1 ? a : irreversible;\n\
    \    }\n}\n"
  code: "#pragma once\n\n#include\"Modulo.hpp\"\n#include\"../Integer/Euler_Totient.hpp\"\
    \n#include\"../Integer/Divisors.hpp\"\n\nnamespace modulo {\n    // X \u306E\u4F4D\
    \u6570\u3092\u6C42\u3081\u308B\n    ll Order(const Modulo &X, ll irreversible\
    \ = -1) { \n        ll phi = Euler_Totient(X.n);\n\n        ll a = X.n + 1;\n\
    \        for (ll k = 1; k * k <= phi; k++) {\n            unless(phi % k == 0)\
    \ { continue; }\n\n            if (k < a && pow(X, k).is_member(1)) { return k;\
    \ }\n\n            if (phi / k < a && pow(X, phi / k).is_member(1)) { a = phi\
    \ / k; }\n        }\n\n        return a < X.n + 1 ? a : irreversible;\n    }\n\
    }\n"
  dependsOn:
  - Modulo/Modulo.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - Integer/Euler_Totient.hpp
  - Integer/Prime.hpp
  - Integer/Divisors.hpp
  isVerificationFile: false
  path: Modulo/Order.hpp
  requiredBy: []
  timestamp: '2025-11-01 19:45:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/Modulo_Order.test.cpp
documentation_of: Modulo/Order.hpp
layout: document
title: "\u5270\u4F59\u985E\u306E\u6307\u6570"
---

## Outline

$X \in \mathbb{Z}/M \mathbb{Z}$ に対して, $X$ の位数を求める.

## Theory

$X \in \mathbb{Z}/M \mathbb{Z}$ の位数とは, $ X^K = 1 $ を満たす最小の正の整数 $K$ として定義される.

位数が存在することに関する以下の命題を証明する.

> $X \in \mathbb{Z}/M \mathbb{Z}$ に対して, 以下は同値である.
> * (a) $X^K = 1$ となる正の整数 $K$ が存在する.
> * (b) $X$ は可逆である.

### 証明

* (a) ならば (b)

$K$ は正の整数であるので, $K - 1 \geq 0$ である. よって, $X \cdot X^{K-1} = 1$ であるため, $X$ は可逆である.

* (b) ならば (a)

$M$ 個の値 $X^0, X^1, X^2, \dots, X^M$ について, 鳩ノ巣原理により, $X^a = X^b$ となる整数 $a, b ~(0 \leq a \lt b \leq M)$ が存在する.

$X$ は可逆であるため, $X^{b-a}=1$ である. $b-a \gt 0$ であるため, $X^K=1$ となる正の整数 $K$ が存在する.

$\square$

これ以降, $X$ が可逆であるとして, $X$ の位数を求める.

$\mathbb{Z}/M \mathbb{Z}$ における可逆元からなる集合 $G := (\mathbb{Z}/M \mathbb{Z})^\times$ は積を演算として群になる. 特に, $X \in G$ である.

群論の知識により, 以下が従う.

* $G$ の位数は $\varphi(M)$ である.
* $\operatorname{ord}_G(X) = \\# \left \langle X \right \rangle$ である. なお, $\left \langle X \right \rangle$ とは, $X$ によって生成される $G$ の部分群である.
* $\left \langle X \right \rangle$ は $G$ の部分群であるので, Lagrange の定理から, $\\# \left \langle X \right \rangle$ は $\\# G$ の約数である.

以上から, $\operatorname{ord}_G(X)$ は $\varphi(M)$ の約数である.

ボトルネックとなるパートの計算量は以下である.

* $\varphi(M)$ の計算: $O \left(\sqrt{M} \right)$ 時間.
* $\varphi(M)$ の約数列挙: $O \left(\sqrt{\varphi(M)} \right)$ 時間.
* $\varphi(M)$ の各約数 $k$ に対して, $X^k$ の計算に $O(\log M)$ 時間かかる

よって, 位数の存在判定と最小値を求めるための計算量は $M$ の約数の個数を $d(M)$ として, $O\left(\sqrt{M} + d(M) \log M \right)$ 時間である.

## Contents

```cpp
ll Order(const Modulo &X, ll irreversible = -1)
```
* $X \in \mathbb{Z}/M \mathbb{Z}$ の位数を求める. $X$ が非可逆の場合, 返り値は `irreversible` となる.
* **計算量** : $O\left(\sqrt{M} + d(M) \log M \right)$ 時間.
