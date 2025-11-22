---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/base.hpp
    title: Geometry/base.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/object/Point.hpp
    title: Geometry/object/Point.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/object/Triangle.hpp
    title: Geometry/object/Triangle.hpp
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
    links: []
  bundledCode: "#line 2 \"Geometry/triangle_center/Centroid.hpp\"\n\n#line 2 \"Geometry/object/Triangle.hpp\"\
    \n\n#line 2 \"Geometry/object/Point.hpp\"\n\n#line 2 \"Geometry/base.hpp\"\n\n\
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
    \n\n// \u6F14\u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y)\
    \ { return x + y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return\
    \ x - y; }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x *\
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
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
    \ bit_length(x)); }\n#line 4 \"Geometry/base.hpp\"\n\nnamespace geometry {\n \
    \   using Real = double long;\n    const Real epsilon = 1e-9;\n    const Real\
    \ pi = acos(static_cast<Real>(-1));\n\n    enum class Inclusion { OUT = -1, ON\
    \ = 0, IN = 1 };\n    enum class Direction_Relation { PARALLEL = 1, ORTHOGONAL\
    \ = -1, CROSS = 0}; \n\n    inline int sign(const Real &r) { return r <= -epsilon\
    \ ? -1 : r >= epsilon ? 1: 0; }\n    inline int equal(const Real &a, const Real\
    \ &b) { return sign(a - b) == 0; }\n    inline int compare(const Real &a, const\
    \ Real &b) { return sign(b - a); }\n\n    inline int sign(const ll &r) { return\
    \ r < 0 ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const ll &a, const ll &b)\
    \ { return sign(a - b) == 0; }\n    inline int compare(const ll &a, const ll &b)\
    \ { return sign(b - a); }\n\n    inline int sign(const int &r) { return r < 0\
    \ ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const int &a, const int &b) {\
    \ return sign(a - b) == 0; }\n    inline int compare(const int &a, const int &b)\
    \ { return sign(b - a); }\n};\n#line 4 \"Geometry/object/Point.hpp\"\n\nnamespace\
    \ geometry {\n    template<typename R>\n    class Point {\n        public:\n \
    \       R x, y;\n\n        public:\n        Point(): x(0), y(0) {}\n        Point(R\
    \ _x, R _y): x(_x), y(_y) {}\n\n        // \u52A0\u6CD5\n        Point& operator+=(const\
    \ Point &B){\n            x += B.x;\n            y += B.y;\n            return\
    \ *this;\n        }\n\n        friend Point operator+(const Point &P, const Point\
    \ &Q) { return Point(P) += Q; }\n\n        // \u6E1B\u6CD5\n        Point& operator-=(const\
    \ Point &B){\n            x -= B.x;\n            y -= B.y;\n            return\
    \ *this;\n        }\n\n        friend Point operator-(const Point &P, const Point\
    \ &Q) { return Point(P) -= Q; }\n\n        // \u30B9\u30AB\u30E9\u30FC\u500D\n\
    \        Point& operator*=(const R &a){\n            x *= a;\n            y *=\
    \ a;\n            return *this;\n        }\n\n        friend Point operator*(const\
    \ Point &P, const R &a) { return Point(P) *= a; }\n        friend Point operator*(const\
    \ R &a, const Point &P) { return Point(P) *= a; }\n\n        Point& operator/=(const\
    \ R &a){\n            x /= a;\n            y /= a;\n            return *this;\n\
    \        }\n\n        friend Point operator/(const Point &P, const R &a) { return\
    \ Point(P) /= a; }\n\n        Point& operator*=(const Point &P){\n           \
    \ R x1 = P.x * x - P.y * y, y1 = P.y * x + P.x * y;\n            x = x1;\n   \
    \         y = y1;\n            return *this;\n        }\n\n        friend Point\
    \ operator*(const Point &P, const Point<R> &Q) { return Point(P) *= Q; }\n\n \
    \       friend istream& operator>>(istream &is, Point &P) {\n            R a,\
    \ b;\n            is >> a >> b;\n            P = Point(a, b);\n            return\
    \ is;\n        }\n\n        friend ostream& operator<<(ostream &os, const Point\
    \ &P) {\n            return os << P.x << \" \" << P.y;\n        }\n\n        inline\
    \ R norm_2() const { return x * x + y * y; }\n        inline double norm() const\
    \ { return sqrt(norm_2()); }\n        inline R dot(const Point B) const { return\
    \ x * B.x + y * B.y; }\n        inline R det(const Point B) const { return x *\
    \ B.y - y * B.x; }\n\n        inline Point<R> normalize() const { return *this\
    \ / norm(); }\n        inline Point<R> normal() const { return Point(-y, x); }\n\
    \n        inline Point<Real> rotate(double theta) const {\n            Real alpha\
    \ = sin(theta), beta = cos(theta);\n            Real s = beta * x - alpha * y,\
    \ t = alpha * x + beta * y;\n            return Point(s, t);\n        }\n    };\n\
    \n    template<typename R>\n    bool compare_x(const Point<R> &A, const Point<R>\
    \ &B) { return equal(A.x, B.x) ? A.y < B.y : A.x < B.x; }\n\n    template<typename\
    \ R>\n    bool compare_y(const Point<R> &A, const Point<R> &B) { return equal(A.y,\
    \ B.y) ? A.x < B.x : A.y < B.y; }\n\n    template<typename R>\n    inline bool\
    \ operator==(const Point<R> &A, const Point<R> &B) { return equal(A.x, B.x) &&\
    \ equal(A.y, B.y); }\n\n    template<typename R>\n    inline bool operator!=(const\
    \ Point<R> &A, const Point<R> &B) { return !(A == B); }\n\n    template<typename\
    \ R>\n    inline R dot(const Point<R> &A, const Point<R> &B) { return A.x * B.x\
    \ + A.y * B.y; }\n\n    template<typename R>\n    inline R cross(const Point<R>\
    \ &A, const Point<R> &B) { return A.x * B.y - A.y * B.x; }\n\n    template<typename\
    \ R>\n    inline R norm_2(const Point<R> &P) { return dot(P, P); }\n\n    template<typename\
    \ R>\n    inline double norm(const Point<R> &P) { return sqrt(norm_2(P)); }\n\n\
    \    template<typename R>\n    inline Real arg(const Point<R> &P) { return atan2(P.y,\
    \ P.x); }\n}\n#line 4 \"Geometry/object/Triangle.hpp\"\n\nnamespace geometry {\n\
    \    template<typename R>\n    class Triangle {\n        public:\n        Point<R>\
    \ A, B, C;\n\n        public:\n        Triangle() = default;\n        Triangle(const\
    \ Point<R> a, const Point<R> b, const Point<R> c): A(a), B(b), C(c) {}\n\n   \
    \     // \u8FBA BC, \u8FBA CA, \u8FBA AB \u306E\u9577\u3055\u3092\u51FA\u529B\u3059\
    \u308B.\n        tuple<double, double, double> edges() const {\n            return\
    \ make_tuple(norm(C - B), norm(A - C), norm(B - A));\n        }\n\n        //\
    \ [PBC] : [PCA] : [PAB] = alpha : beta : gamma \u3092\u6E80\u305F\u3059\u70B9\
    \ P \u3092\u6C42\u3081\u308B.\n        Point<R> balance(const R &alpha, const\
    \ R &beta, const R &gamma) const {\n            return (alpha * A + beta * B +\
    \ gamma * C) / (alpha + beta + gamma);\n        }\n    };\n\n    template<typename\
    \ R>\n    R Area(const Triangle<R> &T) {\n        auto X = cross(T.B - T.A, T.C\
    \ - T.A);\n        return sign(X) >= 0 ? X / 2 : -X / 2;\n    }\n}\n#line 4 \"\
    Geometry/triangle_center/Centroid.hpp\"\n\nnamespace geometry {\n    template<typename\
    \ R>\n    Point<R> Centroid(const Triangle<R> &T) { return T.balance(1, 1, 1);\
    \ }\n}\n"
  code: "#pragma once\n\n#include\"../object/Triangle.hpp\"\n\nnamespace geometry\
    \ {\n    template<typename R>\n    Point<R> Centroid(const Triangle<R> &T) { return\
    \ T.balance(1, 1, 1); }\n}\n"
  dependsOn:
  - Geometry/object/Triangle.hpp
  - Geometry/object/Point.hpp
  - Geometry/base.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: Geometry/triangle_center/Centroid.hpp
  requiredBy: []
  timestamp: '2025-11-22 15:43:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/triangle_center/Centroid.hpp
layout: document
title: "\u4E09\u89D2\u5F62\u306E\u91CD\u5FC3"
---

## Outline

三角形 $\mathrm{ABC}$ の重心 $\mathrm{G}$ を求める.

## Theory

以下の定理がある.

> 三角形 $\mathrm{ABC}$ において, 線分 $\mathrm{BC}, \mathrm{CA}, \mathrm{AB}$ の中点をそれぞれ $\mathrm{L}, \mathrm{M}, \mathrm{N}$ とおく.
> このとき, 線分 $\mathrm{AL}, \mathrm{BM}, \mathrm{CN}$ は一点で交わる.

### 証明

線分 $\mathrm{AL}, \mathrm{BM}$ の交点を $\mathrm{G}$ とする. このとき, それぞれ

$$ \mathrm{G} = s \mathrm{A} + (1-s) \mathrm{L} = s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} $$

$$ \mathrm{G} = t \mathrm{B} + (1-t) \mathrm{M} = t \mathrm{B} + (1-s) \cdot \dfrac{\mathrm{C}+\mathrm{A}}{2} $$

となる $0$ 以上 $1$ 以下の整数 $s, t$ が存在する.

$\mathrm{A}$ を始点とするベクトルに変換させると,

* $\mathrm{G} = \overrightarrow{\mathrm{AG}} - \overrightarrow{\mathrm{AO}}$.
* $s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} = -s \overrightarrow{\mathrm{AO}} + (1-s) \cdot \dfrac{\left(\overrightarrow{\mathrm{AB}} - \overrightarrow{\mathrm{AO}} \right) + \left(\overrightarrow{\mathrm{AC}} - \overrightarrow{\mathrm{AO}} \right)}{2} = \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AC}} - \overrightarrow{\mathrm{AO}}$

である.

そのため,

$$ \overrightarrow{\mathrm{AG}} = \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AC}} \cdots (1) $$

が導ける.

同様にして,

$$ \overrightarrow{\mathrm{AG}} = t \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-t}{2} \cdot \overrightarrow{\mathrm{AC}} \cdots (2) $$

も従う.

ここで, $\mathrm{A}, \mathrm{B}, \mathrm{C}$ は三角形を成す $3$ 点であるため, $\overrightarrow{\mathrm{AB}}, \overrightarrow{\mathrm{AC}}$ は一次独立である.

よって, (1), (2) における係数比較により, $s, t$ は

$$ \dfrac{1-s}{2} = t, \quad \dfrac{1-s}{2} = \dfrac{1-t}{2} $$

を満たす. これを解くと,

$$ s = t = \dfrac{1}{3} $$

となる.

これは, $\mathrm{G}$ は確かに 線分 $\mathrm{AL}, \mathrm{BM}$ 上に存在すること. そして,

$$\mathrm{G} = s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} = \dfrac{\mathrm{A} + \mathrm{B} + \mathrm{C}}{3} $$

であることを意味する.

そして,

$$ G = \dfrac{\mathrm{A} + \mathrm{B} + \mathrm{C}}{3} = \dfrac{1}{3} \mathrm{C} + \dfrac{2}{3} \cdot \dfrac{\mathrm{A} + \mathrm{B}}{2} = \dfrac{1}{3} \mathrm{C} + \dfrac{2}{3} \mathrm{N} $$

であるため, $\mathrm{G}$ は線分 $\mathrm{CN}$ 上の点でもある.

以上から, 線分 $\mathrm{AL}, \mathrm{BM}, \mathrm{CN}$ は一点で交わる.

$\square$

この定理における, 点 $\mathrm{G}$ を三角形 $\mathrm{ABC}$ の重心という.

## Contents

```cpp
template<typename R>
Point<R> Centroid(const Triangle<R> &T)
```

* 三角形 $\mathrm{T}$ の重心を求める.
