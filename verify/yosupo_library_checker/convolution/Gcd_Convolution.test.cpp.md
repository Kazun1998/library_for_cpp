---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Algebra/modint.hpp
    title: Algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/Commutative_Idempotent_Monoid_Convolution_Base.hpp
    title: Convolution/Commutative_Idempotent_Monoid_Convolution_Base.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/Convolution_Base.hpp
    title: Convolution/Convolution_Base.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/Gcd_Convolution.hpp
    title: Convolution/Gcd_Convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ get_bits(x, bit_length(x)); }\n#line 2 \"Algebra/modint.hpp\"\n\n#line 4 \"\
    Algebra/modint.hpp\"\n\ntemplate<int M>\nclass modint {\n    public:\n    static\
    \ constexpr int Mod = M; \n    int64_t x;\n\n    public:\n    // \u521D\u671F\u5316\
    \n    constexpr modint(): x(0) {}\n    constexpr modint(int64_t a): x((a % Mod\
    \ + Mod) % Mod) {}\n\n    // \u30DE\u30A4\u30CA\u30B9\u5143\n    modint operator-()\
    \ const { return modint(-x); }\n\n    // \u52A0\u6CD5\n    modint& operator+=(const\
    \ modint &b){\n        if ((x += b.x) >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n\n    friend modint operator+(const modint &x, const modint &y) { return\
    \ modint(x) += y; }\n\n    // \u6E1B\u6CD5\n    modint& operator-=(const modint\
    \ &b){\n        if ((x += Mod - b.x) >= Mod) x -= Mod;\n        return *this;\n\
    \    }\n\n    friend modint operator-(const modint &x, const modint &y) { return\
    \ modint(x) -= y; }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint\
    \ &b){\n        (x *= b.x) %= Mod;\n        return *this;\n    }\n\n    friend\
    \ modint operator*(const modint &x, const modint &y) { return modint(x) *= y;\
    \ }\n    friend modint operator*(const int &x, const modint &y) { return modint(x)\
    \ *= y; }\n    friend modint operator*(const ll &x, const modint &y) { return\
    \ modint(x) *= y; }\n\n    // \u9664\u6CD5\n    modint& operator/=(const modint\
    \ &b){ return (*this) *= b.inverse(); }\n\n    friend modint operator/(const modint\
    \ &x, const modint &y) { return modint(x) /= y; }\n\n    modint inverse() const\
    \ {\n        int64_t s = 1, t = 0;\n        int64_t a = x, b = Mod;\n\n      \
    \  while (b > 0) {\n            int64_t q = a / b;\n\n            a -= q * b;\
    \ swap(a, b);\n            s -= q * t; swap(s, t);\n        }\n\n        assert\
    \ (a == 1);\n\n        return modint(s);\n    }\n\n    // \u6BD4\u8F03\n    friend\
    \ bool operator==(const modint &a, const modint &b) { return (a.x == b.x); }\n\
    \    friend bool operator==(const modint &a, const int &b) { return a.x == safe_mod(b,\
    \ Mod); }\n    friend bool operator!=(const modint &a, const modint &b) { return\
    \ (a.x != b.x); }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream\
    \ &is, modint &a) {\n        is >> a.x;\n        a.x = (a.x % Mod + Mod) % Mod;\n\
    \        return is;\n    }\n\n    // \u51FA\u529B\n    friend ostream &operator<<(ostream\
    \ &os, const modint &a) { return os << a.x; }\n\n    bool is_zero() const { return\
    \ x == 0; }\n    bool is_member(ll a) const { return x == (a % Mod + Mod) % Mod;\
    \ }\n};\n\ntemplate<int Mod>\nmodint<Mod> pow(modint<Mod> x, long long n) {\n\
    \    if (n < 0) { return pow(x, -n).inverse(); }\n\n    auto res = modint<Mod>(1);\n\
    \    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n        x *= x;\n\
    \    }\n\n    return res;\n}\n#line 2 \"Convolution/Commutative_Idempotent_Monoid_Convolution_Base.hpp\"\
    \n\n#line 2 \"Convolution/Convolution_Base.hpp\"\n\n#line 4 \"Convolution/Convolution_Base.hpp\"\
    \n\nnamespace convolution {\n    template<typename R>\n    class Convolution_Base\
    \ {\n        protected:\n        std::vector<R> data;\n\n        public:\n   \
    \     Convolution_Base() = default;\n        Convolution_Base(std::vector<R> data_in):\
    \ data(std::move(data_in)) {}\n        \n        Convolution_Base(size_t n): data(std::vector<R>(n))\
    \ {} \n        \n        // \u52A0\u6CD5 (+=)\n        Convolution_Base& operator+=(const\
    \ Convolution_Base<R> &B) {\n            if(data.size() != B.data.size()) { throw\
    \ std::length_error(\"Convolution operands must have the same size.\"); }\n\n\
    \            for (size_t i = 0; i < data.size(); i++) { data[i] += B.data[i];\
    \ }\n            return *this;\n        }\n\n        // \u6E1B\u6CD5 (-=)\n  \
    \      Convolution_Base& operator-=(const Convolution_Base<R> &B) {\n        \
    \    if(data.size() != B.data.size()) { throw std::length_error(\"Convolution\
    \ operands must have the same size.\"); }\n            for (size_t i = 0; i <\
    \ data.size(); i++) { data[i] -= B.data[i]; }\n            return *this;\n   \
    \     }\n\n        // \u30B9\u30AB\u30E9\u30FC\u500D (*=)\n        Convolution_Base&\
    \ operator*=(const R &a) {\n            for (size_t i = 0; i < data.size(); i++)\
    \ { data[i] *= a; }\n            return *this;\n        }\n\n        virtual Convolution_Base<R>&\
    \ operator*=(const Convolution_Base<R> &B) = 0;\n\n        inline size_t size()\
    \ const { return data.size(); }\n\n        inline R& operator[](size_t k) { return\
    \ data[k]; }\n        inline const R& operator[](size_t k) const { return data[k];\
    \ }\n\n        const std::vector<R>& to_vector() const { return data; }\n    };\n\
    }\n#line 4 \"Convolution/Commutative_Idempotent_Monoid_Convolution_Base.hpp\"\n\
    \nnamespace convolution {\n    template<typename R>\n    class Commutative_Idempotent_Monoid_Convolution_Base:\
    \ public Convolution_Base<R> {\n        // \u578B\u30A8\u30A4\u30EA\u30A2\u30B9\
    \n        using Base = Convolution_Base<R>;\n        using Self = Commutative_Idempotent_Monoid_Convolution_Base<R>;\n\
    \n        using Base::Base;\n\n        public:\n        virtual void zeta_transform(std::vector<R>\
    \ &f) const = 0;\n        virtual void mobius_transform(std::vector<R> &g) const\
    \ = 0;\n\n        Self& operator*=(const Base &B) override {\n            if (this->data.size()\
    \ != B.to_vector().size()) {\n                throw std::length_error(\"Convolution\
    \ operands must have the same size.\");\n            }\n\n            std::vector<R>\
    \ f_copy(this->data); \n            std::vector<R> g_copy(B.to_vector()); \n\n\
    \            this->zeta_transform(f_copy);\n            this->zeta_transform(g_copy);\
    \ \n\n            for (size_t i = 0; i < f_copy.size(); i++) { \n            \
    \    f_copy[i] *= g_copy[i]; \n            }\n\n            this->mobius_transform(f_copy);\n\
    \            this->data = std::move(f_copy);\n            return *this;\n    \
    \    }\n\n        void zeta() { zeta_transform(this->data); }\n        void mobius()\
    \ { mobius_transform(this->data); }\n    };\n}\n#line 2 \"Convolution/Gcd_Convolution.hpp\"\
    \n\nnamespace convolution {\n    template<typename R>\n    class Gcd_Convolution:\
    \ public Commutative_Idempotent_Monoid_Convolution_Base<R> {\n        using Base\
    \ = Convolution_Base<R>;\n        using ImplBase = Commutative_Idempotent_Monoid_Convolution_Base<R>;\n\
    \        using ImplBase::ImplBase;\n\n        // \u52A0\u6CD5 (+)\n        friend\
    \ Gcd_Convolution operator+(const Gcd_Convolution &lhs, const Gcd_Convolution\
    \ &rhs) {\n            Gcd_Convolution temp(lhs);\n            temp += rhs;\n\
    \            return temp;\n        }\n\n        // \u6E1B\u6CD5 (-)\n        friend\
    \ Gcd_Convolution operator-(const Gcd_Convolution &lhs, const Gcd_Convolution\
    \ &rhs) {\n            Gcd_Convolution temp(lhs);\n            temp -= rhs;\n\
    \            return temp;\n        }\n\n        // \u4E57\u6CD5 (*)\n        friend\
    \ Gcd_Convolution operator*(const Gcd_Convolution &lhs, const Gcd_Convolution\
    \ &rhs) { \n            Gcd_Convolution temp(lhs);\n            temp *= rhs;\n\
    \            return temp;\n        }\n\n        // \u30B9\u30AB\u30E9\u30FC\u500D\
    \ (a * rhs)\n        friend Gcd_Convolution operator*(const R &a, const Gcd_Convolution\
    \ &rhs) {\n            Gcd_Convolution temp(rhs);\n            temp *= a;\n  \
    \          return temp;\n        }\n\n        // \u30B9\u30AB\u30E9\u30FC\u500D\
    \ (lhs * a)\n        friend Gcd_Convolution operator*(const Gcd_Convolution &lhs,\
    \ const R &a) {\n            Gcd_Convolution temp(lhs);\n            temp *= a;\n\
    \            return temp;\n        }\n\n        void zeta_transform(std::vector<R>\
    \ &f) const override {\n            size_t n = f.size() - 1;\n            vector<bool>\
    \ is_prime(n + 1, true);\n\n            for (int p = 2; p <= n + 1; p++) {\n \
    \               if (!is_prime[p]) { continue; }\n\n                for (size_t\
    \ k = n / p; k > 0; k--) {\n                    is_prime[k * p] = false;\n   \
    \                 f[k] += f[k * p];\n                }\n            }\n      \
    \  }\n\n        void mobius_transform(std::vector<R> &g) const override {\n  \
    \          size_t n = g.size() - 1;\n            vector<bool> is_prime(n + 1,\
    \ true);\n\n            for (int p = 2; p <= n + 1; p++) {\n                if\
    \ (!is_prime[p]) { continue; }\n\n                for (size_t k = 1; k <= n /\
    \ p; k++) {\n                    is_prime[k * p] = false;\n                  \
    \  g[k] -= g[k * p];\n                }\n            }\n        }\n    };\n}\n\
    #line 6 \"verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    int N; cin >> N;\n  \
    \  vector<mint> a(N + 1), b(N + 1);\n    for (int i = 1; i <= N; i++) {\n    \
    \    int x; scanf(\"%d\", &x);\n        a[i] = mint(x);\n    }\n\n    for (int\
    \ j = 1; j <= N; j++) {\n        int y; scanf(\"%d\", &y);\n        b[j] = mint(y);\n\
    \    }\n\n    convolution::Gcd_Convolution<mint> A(a), B(b);\n    vector<mint>\
    \ c = (A * B).to_vector();\n    c.erase(c.begin(), c.begin() + 1);\n    cout <<\
    \ c << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../Algebra/modint.hpp\"\n#include\"\
    ../../../Convolution/Gcd_Convolution.hpp\"\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    int N; cin >> N;\n    vector<mint> a(N + 1), b(N + 1);\n \
    \   for (int i = 1; i <= N; i++) {\n        int x; scanf(\"%d\", &x);\n      \
    \  a[i] = mint(x);\n    }\n\n    for (int j = 1; j <= N; j++) {\n        int y;\
    \ scanf(\"%d\", &y);\n        b[j] = mint(y);\n    }\n\n    convolution::Gcd_Convolution<mint>\
    \ A(a), B(b);\n    vector<mint> c = (A * B).to_vector();\n    c.erase(c.begin(),\
    \ c.begin() + 1);\n    cout << c << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - Algebra/modint.hpp
  - Convolution/Gcd_Convolution.hpp
  - Convolution/Commutative_Idempotent_Monoid_Convolution_Base.hpp
  - Convolution/Convolution_Base.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp
  requiredBy: []
  timestamp: '2025-10-25 13:41:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp
- /verify/verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp.html
title: verify/yosupo_library_checker/convolution/Gcd_Convolution.test.cpp
---
