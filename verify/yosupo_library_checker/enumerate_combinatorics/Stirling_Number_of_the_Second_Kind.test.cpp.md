---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/modint.hpp
    title: Algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo_Polynomial/Modulo_Polynomial.hpp
    title: Modulo_Polynomial/Modulo_Polynomial.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo_Polynomial/Numeric_Theory_Translation.hpp
    title: "\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB, \u6570\u8AD6\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: Modulo_Polynomial/Stirling_2nd.hpp
    title: "\u7B2C II \u7A2E Stirling \u6570"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "#line 1 \"verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ get_bits(x, bit_length(x)); }\n#line 2 \"Modulo_Polynomial/Stirling_2nd.hpp\"\
    \n\n#line 2 \"Algebra/modint.hpp\"\n\n#line 4 \"Algebra/modint.hpp\"\n\ntemplate<int\
    \ M>\nclass modint {\n    public:\n    static constexpr int Mod = M; \n    uint64_t\
    \ x;\n\n    public:\n    static modint raw(int v) {\n        modint a;\n     \
    \   a.x = v;\n        return a;\n    }\n\n    // \u521D\u671F\u5316\n    constexpr\
    \ modint(): x(0) {}\n    constexpr modint(int64_t a) {\n        int64_t w = (int64_t)(a)\
    \ % Mod;\n        if (w < 0) { w += Mod; }\n        x = w;\n    }\n\n    // \u30DE\
    \u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x); }\n\
    \n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n        if ((x\
    \ += b.x) >= Mod) x -= Mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator+(const modint &x, const modint &y) { return modint(x) += y; }\n\n \
    \   // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n        if ((x\
    \ += Mod - b.x) >= Mod) x -= Mod;\n        return *this;\n    }\n\n    friend\
    \ modint operator-(const modint &x, const modint &y) { return modint(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n       \
    \ (x *= b.x) %= Mod;\n        return *this;\n    }\n\n    friend modint operator*(const\
    \ modint &x, const modint &y) { return modint(x) *= y; }\n    friend modint operator*(const\
    \ int &x, const modint &y) { return modint(x) *= y; }\n    friend modint operator*(const\
    \ ll &x, const modint &y) { return modint(x) *= y; }\n\n    // \u9664\u6CD5\n\
    \    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }\n\n\
    \    friend modint operator/(const modint &x, const modint &y) { return modint(x)\
    \ /= y; }\n\n    modint inverse() const {\n        int64_t s = 1, t = 0;\n   \
    \     int64_t a = x, b = Mod;\n\n        while (b > 0) {\n            int64_t\
    \ q = a / b;\n\n            a -= q * b; swap(a, b);\n            s -= q * t; swap(s,\
    \ t);\n        }\n\n        assert (a == 1);\n\n        return modint(s);\n  \
    \  }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const modint &a, const\
    \ modint &b) { return (a.x == b.x); }\n    friend bool operator==(const modint\
    \ &a, const int &b) { return a.x == safe_mod(b, Mod); }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n\
    \    friend istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n\
    \        a.x = (a.x % Mod + Mod) % Mod;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const modint &a) { return\
    \ os << a.x; }\n\n    bool is_zero() const { return x == 0; }\n    bool is_member(ll\
    \ a) const { return x == (a % Mod + Mod) % Mod; }\n};\n\ntemplate<int Mod>\nmodint<Mod>\
    \ pow(modint<Mod> x, long long n) {\n    if (n < 0) { return pow(x, -n).inverse();\
    \ }\n\n    auto res = modint<Mod>(1);\n    for (; n; n >>= 1) {\n        if (n\
    \ & 1) { res *= x; }\n        x *= x;\n    }\n\n    return res;\n}\n#line 2 \"\
    Modulo_Polynomial/Numeric_Theory_Translation.hpp\"\n\n#line 2 \"Modulo_Polynomial/Modulo_Polynomial.hpp\"\
    \n\n#line 5 \"Modulo_Polynomial/Modulo_Polynomial.hpp\"\n\ntemplate<typename mint>\n\
    class Modulo_Polynomial {\n    public:\n    int precision = 0;\n\n    public:\n\
    \    vector<mint> poly;\n    Modulo_Polynomial(vector<mint> _poly, int precision):\
    \ precision(precision) {\n        if (_poly.size() > precision) { _poly.resize(precision);\
    \ }\n        poly = _poly;\n    }\n\n    Modulo_Polynomial() = default;\n    Modulo_Polynomial(vector<mint>\
    \ poly) : Modulo_Polynomial(poly, poly.size()) {}\n    Modulo_Polynomial(int precision)\
    \ : Modulo_Polynomial({}, precision) {}\n\n    // \u6F14\u7B97\u5B50\u306E\u5B9A\
    \u7FA9\n    public:\n    // \u30DE\u30A4\u30CA\u30B9\u5143\n    Modulo_Polynomial\
    \ operator-() const {\n        Modulo_Polynomial res(*this);\n        for (auto\
    \ &a : res.poly) { a = -a; }\n        return res;\n    }\n\n    // \u52A0\u6CD5\
    \n    Modulo_Polynomial& operator+=(const Modulo_Polynomial &P){\n        if (size()\
    \ < P.size()) { resize(P.size()); }\n\n        for (int i = 0; i < (int) P.poly.size();\
    \ i++) { poly[i] += P[i]; }\n        reduce();\n\n        return *this;\n    }\n\
    \n    Modulo_Polynomial& operator+=(const mint &a){\n        if (poly.empty())\
    \ { resize(1); }\n        poly[0] += a;\n        reduce();\n\n        return *this;\n\
    \    }\n\n    friend Modulo_Polynomial operator+(const Modulo_Polynomial &lhs,\
    \ const Modulo_Polynomial &rhs) { return Modulo_Polynomial(lhs) += rhs; }\n  \
    \  Modulo_Polynomial operator+(const mint &a) const { return Modulo_Polynomial(*this)\
    \ += a; }\n\n    // \u6E1B\u6CD5\n    Modulo_Polynomial& operator-=(const Modulo_Polynomial\
    \ &P){\n        if (size() < P.size()) { resize(P.size()); }\n\n        for (int\
    \ i = 0; i < (int) P.poly.size(); i++) { poly[i] -= P[i]; }\n        reduce();\n\
    \n        return *this;\n    }\n\n    Modulo_Polynomial& operator-=(const mint\
    \ &a){\n        if (poly.empty()) { resize(1); }\n        poly[0] -= a;\n    \
    \    reduce();\n\n        return *this;\n    }\n\n    friend Modulo_Polynomial\
    \ operator-(const Modulo_Polynomial &lhs, const Modulo_Polynomial &rhs) { return\
    \ Modulo_Polynomial(lhs) -= rhs; }\n    Modulo_Polynomial operator-(const mint\
    \ &a) const { return Modulo_Polynomial(*this) -= a; }\n\n    // \u30B9\u30AB\u30E9\
    \u30FC\u500D\n    Modulo_Polynomial& operator*=(const mint &a){\n        for (int\
    \ i = 0; i < size(); i++) { poly[i] *= a; }\n        reduce();\n        return\
    \ *this;\n    }\n\n    Modulo_Polynomial operator*(const mint &a) const {return\
    \ Modulo_Polynomial(*this) *= a;}\n\n    friend Modulo_Polynomial operator*(const\
    \ mint &a, const Modulo_Polynomial &P) {\n        Modulo_Polynomial res(P);\n\
    \        res *= a;\n        return res;\n    }\n\n    // \u7A4D\n    Modulo_Polynomial&\
    \ operator*=(const Modulo_Polynomial &P) {\n        int r = min({(int) (poly.size()\
    \ + P.poly.size()) - 1, precision, P.precision});\n        vector<mint> A(r);\n\
    \        for (int i = 0; i < size(); i++) {\n            for (int j = 0; j < P.size();\
    \ j++) {\n                if (i + j < r) { A[i + j] += poly[i] * P.poly[j]; }\n\
    \            }\n        }\n\n        poly = A;\n        precision = min(precision,\
    \ P.precision);\n        return *this;\n    }\n\n    friend Modulo_Polynomial\
    \ operator*(const Modulo_Polynomial &lhs, const Modulo_Polynomial &rhs) { return\
    \ Modulo_Polynomial(lhs) *= rhs; }\n\n    // \u30B9\u30AB\u30E9\u30FC\u9664\u7B97\
    \n    Modulo_Polynomial& operator/=(const mint &a) {\n        mint a_inv = a.inverse();\n\
    \        for (int i = 0; i < size(); i++) { poly[i] *= a_inv; }\n        return\
    \ *this;\n    }\n\n    Modulo_Polynomial operator/(const mint &a) const { return\
    \ Modulo_Polynomial(*this) /= a; }\n\n    // index\n    mint operator[] (int k)\
    \ const { return (k < poly.size()) ? poly[k] : 0; }\n\n    // istream\n    friend\
    \ istream &operator>>(istream &is, Modulo_Polynomial &P) {\n        P.poly.resize(P.precision);\n\
    \        for (int i = 0; i < (int)P.precision; i++) { is >> P.poly[i]; }\n   \
    \     return (is);\n    }\n\n    // ostream\n    friend ostream &operator<<(ostream\
    \ &os, const Modulo_Polynomial &P){\n        for (int i = 0; i < (int)P.poly.size();\
    \ i++){\n            os << (i ? \" \" : \"\") << P[i];\n        }\n        return\
    \ os;\n    }\n\n    // poly \u3067\u4FDD\u6301\u3057\u3066\u3044\u308B\u30D9\u30AF\
    \u30C8\u30EB\u306E\u9577\u3055\u3092 size \u306B\u3059\u308B.\n    // size = -1\
    \ \u306E\u3068\u304D\u306F, size = precision \u306B\u5909\u63DB\u3055\u308C\u308B\
    .\n    void resize(int size = -1) {\n        if (size == -1) { size = this ->\
    \ precision; }\n        size = min(size, this -> precision);\n        poly.resize(size);\n\
    \    }\n\n    bool is_zero() const {\n        for (auto &a: poly) { unless(a.is_zero())\
    \ {return false;} }\n        return true;\n    }\n\n    // \u9AD8\u6B21\u306B\u9023\
    \u306A\u308B 0 \u3092\u524A\u9664\u3059\u308B\n    void reduce() {\n        while\
    \ (!poly.empty() && poly.back().is_zero()) { poly.pop_back(); }\n    }\n\n   \
    \ // \u4FDD\u6301\u3057\u3066\u3044\u308B\u591A\u9805\u5F0F\u306E\u4E57\u6CD5\u306E\
    \u9805\u306E\u9577\u3055\u3092\u6C42\u3081\u308B\n    int size() const { return\
    \ poly.size(); }\n\n    // \u6B21\u6570\u3092\u6C42\u3081\u308B (\u30BC\u30ED\u591A\
    \u9805\u5F0F\u306E\u6642\u306F -1)\n    int degree() const {\n        for (int\
    \ d = size() - 1; d >= 0; d--) {\n            unless(poly[d].is_zero()) { return\
    \ d; }\n        }\n        return -1;\n    }\n\n    // \u4F4D\u6570 (\u4FC2\u6570\
    \u304C\u975E\u30BC\u30ED\u3067\u3042\u308B\u6B21\u6570\u306E\u6700\u5C0F\u5024\
    )\n    int order() const {\n        for (int d = 0; d < size(); d++) {\n     \
    \       unless(poly[d].is_zero()) { return d; }\n        }\n        return -1;\n\
    \    }\n};\n#line 5 \"Modulo_Polynomial/Numeric_Theory_Translation.hpp\"\n\ntemplate<typename\
    \ F>\nclass Numeric_Theory_Translation {\n    public:\n    F primitive;\n    vector<F>\
    \ root, iroot, rate2, irate2, rate3, irate3;\n\n    public:\n    Numeric_Theory_Translation()\
    \ {\n        primitive = primitive_root();\n        build_up();\n    }\n\n   \
    \ private:\n    F primitive_root(){\n        if (F::Mod == 2) { return F(1); }\n\
    \        if (F::Mod == 998244353) { return F(3); }\n\n        vector<int> fac;\n\
    \        int v = F::Mod - 1;\n\n        for (int q = 2; q * q <= v; q++){\n  \
    \          int e = 0;\n            while (v % q == 0){\n                e++; v\
    \ /= q;\n            }\n\n            if (e > 0) { fac.emplace_back(q); }\n  \
    \      }\n\n        if (v > 1) { fac.emplace_back(v); }\n\n        F g(2);\n \
    \       while (true) {\n            bool flag = true;\n            for (int q:\
    \ fac) {\n                if (pow(g, (F::Mod - 1) / q) == 1){\n              \
    \      flag = false;\n                    break;\n                }\n        \
    \    }\n            if (flag) { break; }\n            g += 1;\n        }\n   \
    \     return g;\n    }\n\n    void build_up() {\n        int x = ~(F::Mod - 1)\
    \ & (F::Mod - 2);\n        int rank2 = bit_length(x);\n\n        root.resize(rank2\
    \ + 1); iroot.resize(rank2 + 1);\n        rate2.resize(max(0, rank2 - 1)); irate2.resize(max(0,\
    \ rank2 - 1));\n        rate3.resize(max(0, rank2 - 2)); irate3.resize(max(0,\
    \ rank2 - 2));\n\n        root.back() = pow(primitive, (F::Mod - 1) >> rank2);\n\
    \        iroot.back() = root.back().inverse();\n\n        for (int i = rank2 -\
    \ 1; i >= 0; i--){\n            root[i] = root[i + 1] * root[i + 1];\n       \
    \     iroot[i] = iroot[i + 1] * iroot[i + 1];\n        }\n\n        F prod(1),\
    \ iprod(1);\n        for (int i = 0; i < rank2 - 1; i++){\n            rate2[i]\
    \ = root[i + 2] * prod;\n            irate2[i] = iroot[i + 2] * prod;\n\n    \
    \        prod *= iroot[i + 2]; iprod *= root[i + 2];\n        }\n\n        prod\
    \ = 1; iprod = 1;\n        for (int i = 0; i < rank2 - 2; i++){\n            rate3[i]\
    \ = root[i + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n\n   \
    \         prod *= iroot[i + 3]; iprod *= root[i + 3];\n        }\n    }\n\n  \
    \  public:\n    void ntt(vector<F> &A){\n        int N = A.size();\n        int\
    \ h = ceil_log2(N);\n\n        F I = root[2];\n        for (int l = 0; l < h;){\n\
    \            if (h - l == 1){\n                int p = 1 << (h - l - 1);\n   \
    \             F rot(1);\n                for (int s = 0; s < (1 << l); s++){\n\
    \                    int offset = s << (h - l);\n                    for(int i\
    \ = 0; i < p; i++){\n                        F x = A[i + offset], y = A[i + offset\
    \ + p] * rot;\n                        A[i + offset] = x + y;\n              \
    \          A[i + offset + p] = x - y;\n                    }\n\n             \
    \       unless (s + 1 == (1 << l)){ rot *= rate2[bit_length(~s & -(~s)) - 1];\
    \ }\n                }\n                l++;\n            } else {\n         \
    \       int p = 1 << (h - l - 2);\n                F rot(1);\n               \
    \ for (int s = 0; s < (1 << l); s++){\n                    F rot2 = rot * rot,\
    \ rot3 = rot2 * rot;\n                    int offset = s << (h - l);\n       \
    \             for (int i = 0; i < p; i++){\n                        F a0 = A[i\
    \ + offset];\n                        F a1 = A[i + offset + p] * rot;\n      \
    \                  F a2 = A[i + offset + 2 * p] * rot2;\n                    \
    \    F a3 = A[i + offset + 3 * p] * rot3;\n\n                        F alpha =\
    \ (a1 - a3) * I;\n\n                        A[i + offset]         = a0 + a2 +\
    \ a1 + a3;\n                        A[i + offset + p]     = a0 + a2 - a1 - a3;\n\
    \                        A[i + offset + 2 * p] = a0 - a2 + alpha;\n          \
    \              A[i + offset + 3 * p] = a0 - a2 - alpha;\n                    }\n\
    \n                    unless(s + 1 == 1 << l) { rot *= rate3[bit_length(~s & -(~s))\
    \ - 1]; }\n                }\n                l += 2;\n            }\n       \
    \ }\n    }\n\n    public:\n    void inverse_ntt(vector<F> &A){\n        int N\
    \ = A.size();\n        int h = ceil_log2(N);\n\n        F J = iroot[2];\n    \
    \    for (int l = h; l > 0;){\n            if (l == 1){\n                int p\
    \ = 1 << (h - l);\n                F irot(1);\n                for (int s = 0;\
    \ s < (1 << (l - 1)); s++){\n                    int offset = s << (h - l + 1);\n\
    \                    for(int i = 0; i < p; i++){\n                        F x\
    \ = A[i + offset], y = A[i + offset + p];\n                        A[i + offset]\
    \   = x + y;\n                        A[i + offset + p] = (x - y) * irot;\n  \
    \                  }\n\n                    unless (s+1 == 1 << (l - 1) ) { irot\
    \ *= irate2[bit_length(~s & -(~s)) -1]; }\n                }\n               \
    \ l--;\n            } else {\n                int p = 1 << (h - l);\n        \
    \        F irot(1);\n                for (int s=0; s<(1<<(l-2)); s++){\n     \
    \               F irot2 = irot * irot, irot3 = irot2  *irot;\n               \
    \     int offset=s<<(h-l+2);\n                    for (int i = 0; i < p; i++){\n\
    \                        F a0 = A[i + offset];\n                        F a1 =\
    \ A[i + offset + p];\n                        F a2 = A[i + offset + 2 * p];\n\
    \                        F a3 = A[i + offset + 3 * p];\n\n                   \
    \     F beta = (a2 - a3) * J;\n\n                        A[i + offset]       \
    \  = a0 + a2 + a1 + a3;\n                        A[i + offset + p]     = (a0 -\
    \ a1 + beta) * irot;\n                        A[i + offset + 2 * p] = (a0 + a1\
    \ - a2 - a3) * irot2;\n                        A[i + offset + 3 * p] = (a0 - a1\
    \ - beta) * irot3;\n                    }\n\n                    unless (s + 1\
    \ == 1 << (l - 2)) { irot *= irate3[bit_length(~s & -(~s)) - 1]; }\n         \
    \       }\n                l-=2;\n            }\n        }\n\n        F N_inv=F(N).inverse();\n\
    \        for (int i=0; i<N; i++) A[i]*=N_inv;\n    }\n\n    vector<F> convolution(vector<F>\
    \ A, vector<F> B){\n        if (A.empty() || B.empty()) return vector<F>{};\n\n\
    \        int M=A.size(), N=B.size(), L=M+N-1;\n        if (min(M,N)<64){\n   \
    \         vector<F> C(L);\n            for(int i=0; i<M; i++){\n             \
    \   for (int j=0; j<N; j++){\n                    C[i+j]+=A[i]*B[j];\n       \
    \         }\n            }\n            return C;\n        }\n\n        int h=bit_length(L);\n\
    \        int K=1<<h;\n\n        vector<F> X(K), Y(K);\n        copy(A.begin(),\
    \ A.end(), X.begin());\n        copy(B.begin(), B.end(), Y.begin());\n\n     \
    \   ntt(X); ntt(Y);\n        for (int i=0; i<K; i++) X[i]*=Y[i];\n\n        inverse_ntt(X);\
    \ X.resize(L);\n        return X;\n    }\n\n    vector<F> inverse(vector<F> P,\
    \ int d) {\n        int n = P.size();\n        assert(!P.empty() && !P[0].is_zero());\n\
    \n        vector<F> G{P[0].inverse()};\n        while (G.size() < d) {\n     \
    \       int m = G.size();\n            vector<F> A(P.begin(), P.begin() + min(n,\
    \ 2 * m));\n            A.resize(2 * m);\n            vector<F> B(G);\n      \
    \      B.resize(2 * m);\n\n            ntt(A); ntt(B);\n            for (int i\
    \ = 0; i < 2 * m; i++) { A[i] *= B[i]; }\n\n            inverse_ntt(A);\n    \
    \        A.erase(A.begin(), A.begin() + m);\n            A.resize(2 * m);\n\n\
    \            ntt(A);\n            for (int i = 0; i < 2 * m; i++) { A[i] *= -B[i];\
    \ }\n\n            inverse_ntt(A);\n\n            G.insert(G.end(), A.begin(),\
    \ A.begin() + m);\n        }\n\n        G.resize(d);\n        return G;\n    }\n\
    \n    vector<F> inverse(vector<F> P) { return inverse(P, P.size()); }\n\n    vector<F>\
    \ multiple_convolution(vector<vector<F>> A) {\n        if (A.empty()) { return\
    \ {1}; }\n\n        deque<int> queue(A.size());\n        iota(queue.begin(), queue.end(),\
    \ 0);\n\n        while (queue.size() > 1) {\n            int i = queue.front();\
    \ queue.pop_front();\n            int j = queue.front(); queue.pop_front();\n\n\
    \            A[i] = convolution(A[i], A[j]);\n            queue.emplace_back(i);\n\
    \        }\n\n        return A[queue.back()];\n    }\n};\n#line 5 \"Modulo_Polynomial/Stirling_2nd.hpp\"\
    \n\ntemplate<typename mint>\nvector<mint> Stirling_2nd(int N) {\n    Numeric_Theory_Translation<mint>\
    \ calc;\n\n    vector<mint> fact(N + 1), fact_inv(N + 1);\n\n    fact[0] = 1;\n\
    \    for (int k = 1; k <= N; k++) { fact[k] = k * fact[k - 1]; }\n\n    fact_inv[N]\
    \ = fact[N].inverse();\n    for (int k = N - 1; k >= 0; k--) { fact_inv[k] = (k\
    \ + 1) * fact_inv[k + 1]; }\n\n    vector<mint> a(N + 1), b(N + 1);\n    for (int\
    \ i = 0; i <= N; i++) { a[i] = pow(mint(i), N) * fact_inv[i]; }\n    for (int\
    \ j = 0; j <= N; j++) { b[j] = (j % 2 == 0) ? fact_inv[j] : -fact_inv[j]; }\n\n\
    \    vector<mint> c = calc.convolution(a, b);\n    c.erase(c.begin() + N + 1,\
    \ c.end());\n    return c;\n}\n#line 5 \"verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp\"\
    \n\nconst ll Mod = 998244353;\nusing mint = modint<Mod>;\n\nint main() {\n   \
    \ int N; cin >> N;\n    cout << Stirling_2nd<mint>(N) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#include\"../../../template/template.hpp\"\n#include\"../../../Modulo_Polynomial/Stirling_2nd.hpp\"\
    \n\nconst ll Mod = 998244353;\nusing mint = modint<Mod>;\n\nint main() {\n   \
    \ int N; cin >> N;\n    cout << Stirling_2nd<mint>(N) << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - Modulo_Polynomial/Stirling_2nd.hpp
  - Algebra/modint.hpp
  - Modulo_Polynomial/Numeric_Theory_Translation.hpp
  - Modulo_Polynomial/Modulo_Polynomial.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp
  requiredBy: []
  timestamp: '2025-10-25 13:51:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp
- /verify/verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp.html
title: verify/yosupo_library_checker/enumerate_combinatorics/Stirling_Number_of_the_Second_Kind.test.cpp
---
