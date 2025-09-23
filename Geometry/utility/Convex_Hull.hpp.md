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
    path: Geometry/object/Polygon.hpp
    title: Geometry/object/Polygon.hpp
  - icon: ':heavy_check_mark:'
    path: Geometry/utility/Counter_Clockwise.hpp
    title: Geometry/utility/Counter_Clockwise.hpp
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
    path: verify/aizu_online_judge/cgl/4A.test.cpp
    title: verify/aizu_online_judge/cgl/4A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/geometry/Static_Convex_Hull.test.cpp
    title: verify/yosupo_library_checker/geometry/Static_Convex_Hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/utility/Convex_Hull.hpp\"\n\n#line 2 \"Geometry/utility/Counter_Clockwise.hpp\"\
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
    \n\n// \u9664\u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){\
    \ return (x > 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0\
    \ ? (x + y - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x,\
    \ U y){\n    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092\
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
    \ b), b, mod(a, b));\n        tie(s, t) = make_pair(t, s - q * t);\n        tie(u,\
    \ v) = make_pair(v, u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\
    #line 62 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
    \n// \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ...\
    \ >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
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
    \n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1,\
    \ _2, name, ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define\
    \ overload4(_1, _2, _3, _4, name, ...) name\n#define overload5(_1, _2, _3, _4,\
    \ _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for\
    \ (ll i = 0; i < n; i++)\n#define rep2(i, n) for (ll i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (ll i = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i\
    \ = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2,\
    \ rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x: a)\n#define foreach2(x,\
    \ y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y,\
    \ z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define\
    \ foreach(...) overload5(__VA_ARGS__, foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n\
    #line 4 \"Geometry/base.hpp\"\n\nnamespace geometry {\n    using Real = double\
    \ long;\n    const Real epsilon = 1e-9;\n    const Real pi = acos(static_cast<Real>(-1));\n\
    \n    enum class Inclusion { OUT = -1, ON = 0, IN = 1 };\n    enum class Direction_Relation\
    \ { PARALLEL = 1, ORTHOGONAL = -1, CROSS = 0}; \n\n    inline int sign(const Real\
    \ &r) { return r <= -epsilon ? -1 : r >= epsilon ? 1: 0; }\n    inline int equal(const\
    \ Real &a, const Real &b) { return sign(a - b) == 0; }\n    inline int compare(const\
    \ Real &a, const Real &b) { return sign(b - a); }\n\n    inline int sign(const\
    \ ll &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const ll\
    \ &a, const ll &b) { return sign(a - b) == 0; }\n    inline int compare(const\
    \ ll &a, const ll &b) { return sign(b - a); }\n\n    inline int sign(const int\
    \ &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }\n    inline int equal(const int &a,\
    \ const int &b) { return sign(a - b) == 0; }\n    inline int compare(const int\
    \ &a, const int &b) { return sign(b - a); }\n};\n#line 4 \"Geometry/object/Point.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    class Point {\n      \
    \  public:\n        R x, y;\n\n        public:\n        Point(): x(0), y(0) {}\n\
    \        Point(R _x, R _y): x(_x), y(_y) {}\n\n        // \u52A0\u6CD5\n     \
    \   Point& operator+=(const Point &B){\n            x += B.x;\n            y +=\
    \ B.y;\n            return *this;\n        }\n\n        friend Point operator+(const\
    \ Point &P, const Point &Q) { return Point(P) += Q; }\n\n        // \u6E1B\u6CD5\
    \n        Point& operator-=(const Point &B){\n            x -= B.x;\n        \
    \    y -= B.y;\n            return *this;\n        }\n\n        friend Point operator-(const\
    \ Point &P, const Point &Q) { return Point(P) -= Q; }\n\n        // \u30B9\u30AB\
    \u30E9\u30FC\u500D\n        Point& operator*=(const R &a){\n            x *= a;\n\
    \            y *= a;\n            return *this;\n        }\n\n        friend Point\
    \ operator*(const Point &P, const R &a) { return Point(P) *= a; }\n        friend\
    \ Point operator*(const R &a, const Point &P) { return Point(P) *= a; }\n\n  \
    \      Point& operator/=(const R &a){\n            x /= a;\n            y /= a;\n\
    \            return *this;\n        }\n\n        friend Point operator/(const\
    \ Point &P, const R &a) { return Point(P) /= a; }\n\n        Point& operator*=(const\
    \ Point &P){\n            R x1 = P.x * x - P.y * y, y1 = P.y * x + P.x * y;\n\
    \            x = x1;\n            y = y1;\n            return *this;\n       \
    \ }\n\n        friend Point operator*(const Point &P, const Point<R> &Q) { return\
    \ Point(P) *= Q; }\n\n        friend istream& operator>>(istream &is, Point &P)\
    \ {\n            R a, b;\n            is >> a >> b;\n            P = Point(a,\
    \ b);\n            return is;\n        }\n\n        friend ostream& operator<<(ostream\
    \ &os, const Point &P) {\n            return os << P.x << \" \" << P.y;\n    \
    \    }\n\n        inline R norm_2() const { return x * x + y * y; }\n        inline\
    \ double norm() const { return sqrt(norm_2()); }\n        inline R dot(const Point\
    \ B) const { return x * B.x + y * B.y; }\n        inline R det(const Point B)\
    \ const { return x * B.y - y * B.x; }\n\n        inline Point<R> normalize() const\
    \ { return *this / norm(); }\n        inline Point<R> normal() const { return\
    \ Point(-y, x); }\n\n        inline Point<Real> rotate(double theta) const {\n\
    \            Real alpha = sin(theta), beta = cos(theta);\n            Real s =\
    \ beta * x - alpha * y, t = alpha * x + beta * y;\n            return Point(s,\
    \ t);\n        }\n    };\n\n    template<typename R>\n    bool compare_x(const\
    \ Point<R> &A, const Point<R> &B) { return equal(A.x, B.x) ? A.y < B.y : A.x <\
    \ B.x; }\n\n    template<typename R>\n    bool compare_y(const Point<R> &A, const\
    \ Point<R> &B) { return equal(A.y, B.y) ? A.x < B.x : A.y < B.y; }\n\n    template<typename\
    \ R>\n    inline bool operator==(const Point<R> &A, const Point<R> &B) { return\
    \ equal(A.x, B.x) && equal(A.y, B.y); }\n\n    template<typename R>\n    inline\
    \ bool operator!=(const Point<R> &A, const Point<R> &B) { return !(A == B); }\n\
    \n    template<typename R>\n    inline R dot(const Point<R> &A, const Point<R>\
    \ &B) { return A.x * B.x + A.y * B.y; }\n\n    template<typename R>\n    inline\
    \ R cross(const Point<R> &A, const Point<R> &B) { return A.x * B.y - A.y * B.x;\
    \ }\n\n    template<typename R>\n    inline R norm_2(const Point<R> &P) { return\
    \ dot(P, P); }\n\n    template<typename R>\n    inline double norm(const Point<R>\
    \ &P) { return sqrt(norm_2(P)); }\n\n    template<typename R>\n    inline Real\
    \ arg(const Point<R> &P) { return atan2(P.y, P.x); }\n}\n#line 4 \"Geometry/utility/Counter_Clockwise.hpp\"\
    \n\nnamespace geometry {\n    constexpr int COUNTER_CLOCKWISE = +1;\n    constexpr\
    \ int CLOCKWISE = -1;\n    constexpr int ONLINE_BACK = -2;   // c-a-b\n    constexpr\
    \ int ONLINE_FRONT = +2;  // a-b-c\n    constexpr int ON_SEGMENT = 0;     // a-c-b\n\
    \n    // A -> B -> C \u3068\u9032\u3093\u3060\u6642\u306E\u9032\u884C\u65B9\u5411\
    \u3092\u8ABF\u3079\u308B (B \u8996\u70B9)\n    // Input\n    // A: \u59CB\u70B9\
    \n    // B: \u4E2D\u7D99\u5730\u70B9\n    // C: \u7D42\u70B9\n    template<typename\
    \ R>\n    int Counter_Clockwise(const Point<R> &A, Point<R> B, Point<R> C) {\n\
    \        B = B - A; C = C - A;\n        if (sign(cross(B, C)) == +1) { return\
    \ COUNTER_CLOCKWISE; }\n        if (sign(cross(B, C)) == -1) { return CLOCKWISE;\
    \ }\n        if (sign(dot(B, C)) == -1) { return ONLINE_BACK; }\n        if (norm_2(B)\
    \ < norm_2(C)) { return ONLINE_FRONT; }\n        return ON_SEGMENT;\n    }\n}\n\
    #line 2 \"Geometry/object/Polygon.hpp\"\n\n#line 4 \"Geometry/object/Polygon.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    struct Polygon {\n   \
    \     vector<Point<R>> vertices;\n        int n;\n\n        Polygon() = default;\n\
    \        Polygon(const vector<Point<R>> &_vertices): vertices(_vertices), n(_vertices.size())\
    \ {}\n    };\n\n    template<typename R>\n    R Area(const Polygon<R> &X) {\n\
    \        R area = cross(X.vertices[X.n - 1], X.vertices[0]);\n        for (int\
    \ i = 0; i < X.n - 1; i++) {\n            area += cross(X.vertices[i], X.vertices[i\
    \ + 1]);\n        }\n\n        return abs(area) / 2;\n    }\n}\n#line 5 \"Geometry/utility/Convex_Hull.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    Polygon<R> Convex_Hull(vector<Point<R>>\
    \ points, bool strict = true) {\n        // \u524D\u51E6\u7406\n        sort(points.begin(),\
    \ points.end(), compare_x<R>);\n        points.erase(unique(points.begin(), points.end()),\
    \ points.end());\n\n        int n = points.size();\n\n        if (n <= 2) { return\
    \ Polygon(points); }\n\n        int k = 0;\n        vector<Point<R>> vertices(2\
    \ * n);\n        auto is_valid = [&](const int i) -> bool { \n            int\
    \ d = Counter_Clockwise(vertices[k - 2], vertices[k - 1], points[i]);\n      \
    \      return (d == COUNTER_CLOCKWISE || (!strict && d == ONLINE_FRONT));\n  \
    \      };\n\n        for (int i = 0; i < n; vertices[k++] = points[i++]) {\n \
    \           if (!vertices.empty() && vertices.back() == points[i]) { vertices.pop_back();\
    \ }\n\n            while(k >= 2 && !is_valid(i)) {\n                k--;\n   \
    \         }\n        }\n\n        for (int i = n - 2, t = k + 1; i >= 0; vertices[k++]\
    \ = points[i--]) {\n            if (!vertices.empty() && vertices.back() == points[i])\
    \ { vertices.pop_back(); }\n\n            while (k >= t && !is_valid(i)) {\n \
    \               k--;\n            }\n        }\n\n        vertices.resize(k -\
    \ 1);\n        return Polygon(vertices);\n    }\n}\n"
  code: "#pragma once\n\n#include\"Counter_Clockwise.hpp\"\n#include\"../object/Polygon.hpp\"\
    \n\nnamespace geometry {\n    template<typename R>\n    Polygon<R> Convex_Hull(vector<Point<R>>\
    \ points, bool strict = true) {\n        // \u524D\u51E6\u7406\n        sort(points.begin(),\
    \ points.end(), compare_x<R>);\n        points.erase(unique(points.begin(), points.end()),\
    \ points.end());\n\n        int n = points.size();\n\n        if (n <= 2) { return\
    \ Polygon(points); }\n\n        int k = 0;\n        vector<Point<R>> vertices(2\
    \ * n);\n        auto is_valid = [&](const int i) -> bool { \n            int\
    \ d = Counter_Clockwise(vertices[k - 2], vertices[k - 1], points[i]);\n      \
    \      return (d == COUNTER_CLOCKWISE || (!strict && d == ONLINE_FRONT));\n  \
    \      };\n\n        for (int i = 0; i < n; vertices[k++] = points[i++]) {\n \
    \           if (!vertices.empty() && vertices.back() == points[i]) { vertices.pop_back();\
    \ }\n\n            while(k >= 2 && !is_valid(i)) {\n                k--;\n   \
    \         }\n        }\n\n        for (int i = n - 2, t = k + 1; i >= 0; vertices[k++]\
    \ = points[i--]) {\n            if (!vertices.empty() && vertices.back() == points[i])\
    \ { vertices.pop_back(); }\n\n            while (k >= t && !is_valid(i)) {\n \
    \               k--;\n            }\n        }\n\n        vertices.resize(k -\
    \ 1);\n        return Polygon(vertices);\n    }\n}\n"
  dependsOn:
  - Geometry/utility/Counter_Clockwise.hpp
  - Geometry/object/Point.hpp
  - Geometry/base.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - Geometry/object/Polygon.hpp
  isVerificationFile: false
  path: Geometry/utility/Convex_Hull.hpp
  requiredBy: []
  timestamp: '2025-09-23 11:02:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/geometry/Static_Convex_Hull.test.cpp
  - verify/aizu_online_judge/cgl/4A.test.cpp
documentation_of: Geometry/utility/Convex_Hull.hpp
layout: document
redirect_from:
- /library/Geometry/utility/Convex_Hull.hpp
- /library/Geometry/utility/Convex_Hull.hpp.html
title: Geometry/utility/Convex_Hull.hpp
---
