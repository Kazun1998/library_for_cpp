---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Segment_Tree/Lazy_Segment_Tree.hpp
    title: Segment_Tree/Lazy_Segment_Tree.hpp
  - icon: ':heavy_check_mark:'
    path: modint.hpp
    title: modint.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
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
    \ *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// vector \u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n  \
    \  ll y = 0;\n    for (auto &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\
    \u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\n\
    T sum(vector<T> &X){\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n   \
    \ return y;\n}\n#line 62 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
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
    #line 2 \"modint.hpp\"\n\ntemplate<int mod>\nclass modint{\n    public:\n    int64_t\
    \ x;\n\n    public:\n    // \u521D\u671F\u5316\n    constexpr modint(): x(0) {}\n\
    \    constexpr modint(int64_t a): x((a % mod + mod) % mod) {}\n\n    // \u30DE\
    \u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x); }\n\
    \n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n        if ((x\
    \ += b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator+(const modint &x, const modint &y) { return modint(x) += y; }\n\n \
    \   // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n        if ((x\
    \ += mod - b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend\
    \ modint operator-(const modint &x, const modint &y) { return modint(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n       \
    \ (x *= b.x) %= mod;\n        return *this;\n    }\n\n    friend modint operator*(const\
    \ modint &x, const modint &y) { return modint(x) *= y; }\n\n    // \u9664\u6CD5\
    \n    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }\n\n\
    \    friend modint operator/(const modint &x, const modint &y) { return modint(x)\
    \ /= y; }\n\n    modint inverse() const {\n        int64_t s = 1, t = 0;\n   \
    \     int64_t a = x, b = mod;\n\n        while (b > 0) {\n            int64_t\
    \ q = a / b;\n\n            a -= q * b; swap(a, b);\n            s -= q * t; swap(s,\
    \ t);\n        }\n\n        assert (a == 1);\n\n        return modint(s);\n  \
    \  }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const modint &a, const\
    \ modint &b) { return (a.x == b.x); }\n    friend bool operator!=(const modint\
    \ &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n    friend\
    \ istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n        a.x\
    \ = (a.x % mod + mod) % mod;\n        return is;\n    }\n\n    // \u51FA\u529B\
    \n    friend ostream &operator<<(ostream &os, const modint &a) { return os <<\
    \ a.x; }\n};\n#line 2 \"Segment_Tree/Lazy_Segment_Tree.hpp\"\n\n/* \u9045\u5EF6\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\nM \u3092 Monoid \u3068\u3059\u308B. M \u4E0A\
    \u306E\u5217\u306B\u5BFE\u3057\u3066, Monid F \u304B\u3089\u306E\u533A\u9593\u4F5C\
    \u7528\u3068, \u9023\u7D9A\u90E8\u5206\u5217\u306B\u5BFE\u3059\u308B\u533A\u9593\
    \u7A4D\u306E\u8A08\u7B97\u306E\u51E6\u7406\u3092\u9AD8\u901F\u306B\u884C\u3046\
    .\n\n* M: Monoid\n* F: Monoid\n* op: M x M \u2192 M: M \u4E0A\u306E\u6F14\u7B97\
    \n* unit: M \u306E\u5358\u4F4D\u5143\n* act: F x M \u2192 M: F \u304B\u3089\u306E\
    \ M \u306E\u6F14\u7B97\n* comp: F x F \u2192 F: F \u540C\u58EB\u306E\u5408\u6210\
    \ (\u5DE6\u306E\u8981\u7D20\u304C\u65B0\u3057\u3044)\n* id: F \u306E\u5358\u4F4D\
    \u5143\n\n(\u6761\u4EF6)\nM: Monoid, F = {f: F x M \u2192 M: \u4F5C\u7528\u7D20\
    } \u306B\u5BFE\u3057\u3066, \u4EE5\u4E0B\u304C\u6210\u7ACB\u3059\u308B.\n* F \u306F\
    \u5199\u50CF\u306E\u5408\u6210\u306B\u9589\u3058\u3066\u3044\u308B. \u3064\u307E\
    \u308A, \u4EFB\u610F\u306E f,g in F \u306B\u5BFE\u3057\u3066, comp(f,g) in F\n\
    * F \u306F M \u306B\u4F5C\u7528\u3059\u308B. \u3064\u307E\u308A, \u4EE5\u4E0B\u304C\
    \u6210\u308A\u7ACB\u3064.\n    * F \u306E\u5358\u4F4D\u5143 id \u306F\u6052\u7B49\
    \u7684\u306B\u4F5C\u7528\u3059\u308B. \u3064\u307E\u308A, \u4EFB\u610F\u306E x\
    \ in M \u306B\u5BFE\u3057\u3066 id(x) = x \u3068\u306A\u308B.\n    * \u4EFB\u610F\
    \u306E f in F, x,y in M \u306B\u5BFE\u3057\u3066, f(xy) = f(x) f(y) \u3067\u3042\
    \u308B.\n\n\n(\u6CE8\u610F)\n\u4F5C\u7528\u7D20\u306F\u5DE6\u304B\u3089\u639B\u3051\
    \u308B. \u66F4\u65B0\u3082\u5DE6\u304B\u3089\u884C\u3046.\n*/\n\ntemplate<typename\
    \ M, typename F>\nclass Lazy_Segment_Tree {\n    public:\n    int n, depth;\n\
    \    const function<M(M, M)> op;\n    const function<M(F, M)> act;\n    const\
    \ function<F(F, F)> comp;\n    vector<M> data; const M unit;\n    vector<F> lazy;\
    \ const F id;\n\n    public:\n    Lazy_Segment_Tree(int size, const function<M(M,\
    \ M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp,\
    \ const F id):\n        n(), op(op), unit(unit), act(act), comp(comp), id(id),\
    \ depth(0) {\n            int m = 1;\n            while (size > m) { depth++,\
    \ m *= 2; }\n            n = m;\n            data.assign(2 * m, unit);\n     \
    \       lazy.assign(2 * m, id);\n        }\n\n    Lazy_Segment_Tree(const vector<M>\
    \ &vec, const function<M(M, M)> op, const M unit, const function<M(F, M)> act,\
    \ const function<F(F, F)> comp, const F id):\n        Lazy_Segment_Tree(vec.size(),\
    \ op, unit, act, comp, id){\n            for (int k = 0; k < vec.size(); k++)\
    \ { data[k+n] = vec[k]; }\n            for (int k = n - 1; k > 0; k--) { data[k]\
    \ = op(data[k << 1], data[k << 1 | 1]); }\n        }\n\n    private:\n    inline\
    \ M evaluate_at(int m){ return lazy[m] == id ? data[m] : act(lazy[m], data[m]);\
    \ }\n\n    void propagate_at(int m){\n        data[m] = evaluate_at(m);\n\n  \
    \      if ((m < n) && (lazy[m] != id)){\n            int left = m << 1;\n    \
    \        lazy[left] = (lazy[left] == id) ? lazy[m] : comp(lazy[m], lazy[left]);\n\
    \n            int right = m << 1 | 1;\n            lazy[right] = (lazy[right]\
    \ == id) ? lazy[m] : comp(lazy[m], lazy[right]); \n        }\n\n        lazy[m]\
    \ = id;\n    }\n\n    inline void propagate_above(int m){\n        int h = 0,\
    \ mm = m;\n        for (mm; mm; mm >>= 1, h++){}\n\n        for (h--; h >= 0;\
    \ h--) { propagate_at(m>>h); }\n    }\n\n    inline void recalc_above(int m){\n\
    \        while (m > 1){\n            m >>= 1;\n            data[m] = op(evaluate_at(m\
    \ << 1), evaluate_at(m << 1 | 1));\n        }\n    }\n\n    pair<int, int> range_propagate(int\
    \ l, int r){\n        int X = l + n, Y = r + n - 1, L0 = -1, R0 = -1;\n    \n\
    \        while (X < Y){\n            if (X & 1) { L0 = max(L0, X++); }\n     \
    \       if ((Y & 1) ==0 ) { R0 = max(R0, Y--); }\n\n            X >>= 1; Y >>=\
    \ 1;\n        }\n\n        L0 = max(L0, X); R0 = max(R0, Y);\n        propagate_above(L0);\
    \ propagate_above(R0);\n        return make_pair(L0, R0);\n    }\n\n    public:\n\
    \    // \u7B2C k \u9805\u3092\u53D6\u5F97\u3059\u308B.\n    inline M operator[](int\
    \ k){\n        int m = k + n;\n        propagate_above(m);\n        lazy[m] =\
    \ id;\n        return data[m] = evaluate_at(m);\n    }\n\n    // i = l, l + 1,\
    \ ..., r \u306B\u5BFE\u3057\u3066, a \u3092\u4F5C\u7528\u3055\u305B\u308B.\n \
    \   // \u4F5C\u7528\u306E\u7BC4\u56F2\u304C\u9589\u533A\u9593\u3067\u3042\u308B\
    \u3053\u3068\u306B\u6CE8\u610F.\n    void action(int l, int r, F a){\n       \
    \ int L0, R0;\n        tie(L0, R0) = range_propagate(l, r + 1);\n\n        int\
    \ L = l + n, R = r + n + 1;\n        while (L < R){\n            if (L & 1){\n\
    \                lazy[L] = (a == id) ? id : comp(a, lazy[L]); \n             \
    \   L++;\n            }\n\n            if (R & 1){\n                R--;\n   \
    \             lazy[R] = (a == id) ? id : comp(a, lazy[R]);\n            }\n\n\
    \            L >>= 1; R >>= 1;\n        }\n\n        recalc_above(L0); recalc_above(R0);\n\
    \    }\n\n    // \u7B2C k \u9805\u3092 x \u306B\u66F4\u65B0\u3059\u308B.\n   \
    \ inline void update(int k, M x){\n        int m = k + n;\n        propagate_above(m);\n\
    \        data[m] = x; lazy[m] = id;\n        recalc_above(m);\n    }\n\n    //\
    \ \u7A4D x[l] * x[l + 1] * ... * x[r] \u3092\u6C42\u3081\u308B.\n    // \u7A4D\
    \u3092\u53D6\u308B\u7BC4\u56F2\u304C\u9589\u533A\u9593\u3067\u3042\u308B\u3053\
    \u3068\u306B\u6CE8\u610F.\n    M product(int l, int r){\n        int L0, R0;\n\
    \        tie(L0, R0) = range_propagate(l, r + 1);\n\n        int L = l + n, R\
    \ = r + n + 1;\n        M vL = unit, vR = unit;\n        while (L < R){\n    \
    \        if (L & 1) { vL = op(vL, evaluate_at(L)); L++; }\n            if (R &\
    \ 1) { R--; vR=op(evaluate_at(R), vR); }\n\n            L >>= 1; R >>= 1;\n  \
    \      }\n\n        return op(vL, vR);\n    }\n\n    // \u5168\u8981\u7D20\u306E\
    \u7A4D\u3092\u6C42\u3081\u308B.\n    inline M all_product() {return product(0,\
    \ n);}\n\n    void refresh() {\n        for (int m = 1; m < 2 * n; m++){\n   \
    \         data[m] = evaluate_at(m);\n            if ((m < n) && (lazy[m] != id)){\n\
    \                int left = m << 1;\n                lazy[left] = (lazy[left]\
    \ == id) ? lazy[m] : comp(lazy[m], lazy[left]);\n\n                int right =\
    \ m << 1 | 1;\n                lazy[right] = (lazy[right] == id) ? lazy[m] : comp(lazy[m],\
    \ lazy[m << 1 | 1]);\n            }\n            lazy[m] = id;\n        }\n  \
    \  }\n};\n#line 6 \"verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp\"\
    \n\nusing L = modint<998244353>;\nusing M = pair<L, int>;\nusing F = pair<L, L>;\n\
    \nauto op = [](M x, M y) -> M {\n    auto first  = x.first  + y.first;\n    auto\
    \ second = x.second + y.second;\n    return { first, second };\n};\n\nauto act\
    \ = [](F a, M x) -> M {\n    auto first  = a.first * x.first + a.second * x.second;\n\
    \    auto second = x.second;\n    return { first, second };\n};\n\nauto comp =\
    \ [](F a, F b) -> F {\n    auto first  = a.first * b.first;\n    auto second =\
    \ a.first * b.second + a.second;\n    return { first, second };\n};\n\nM unit\
    \ = make_pair(0, 0);\nF id = make_pair(1, 0);\n\nint main(){\n    int N, Q; cin\
    \ >> N >> Q;\n\n    vector<M> a(N);\n    for (int i = 0; i < N; i++){\n      \
    \  int x; scanf(\"%d\", &x);\n        a[i] = {x, 1};\n    }\n\n    Lazy_Segment_Tree<M,\
    \ F> S(a, op, unit, act, comp, id);\n\n    for (int q = 0; q < Q; q++){\n    \
    \    int t, l, r;\n        scanf(\"%d\", &t);\n\n        if (t == 0){\n      \
    \      int b, c;\n            scanf(\"%d%d%d%d\", &l, &r, &b, &c);\n         \
    \   S.action(l, r - 1, {b, c});\n        } elif (t == 1) {\n            scanf(\"\
    %d%d\", &l, &r);\n            cout << S.product(l, r - 1).first << \"\\n\";\n\
    \        }\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include\"../../../template/template.hpp\"\n#include\"../../../modint.hpp\"\
    \n#include\"../../../Segment_Tree/Lazy_Segment_Tree.hpp\"\n\nusing L = modint<998244353>;\n\
    using M = pair<L, int>;\nusing F = pair<L, L>;\n\nauto op = [](M x, M y) -> M\
    \ {\n    auto first  = x.first  + y.first;\n    auto second = x.second + y.second;\n\
    \    return { first, second };\n};\n\nauto act = [](F a, M x) -> M {\n    auto\
    \ first  = a.first * x.first + a.second * x.second;\n    auto second = x.second;\n\
    \    return { first, second };\n};\n\nauto comp = [](F a, F b) -> F {\n    auto\
    \ first  = a.first * b.first;\n    auto second = a.first * b.second + a.second;\n\
    \    return { first, second };\n};\n\nM unit = make_pair(0, 0);\nF id = make_pair(1,\
    \ 0);\n\nint main(){\n    int N, Q; cin >> N >> Q;\n\n    vector<M> a(N);\n  \
    \  for (int i = 0; i < N; i++){\n        int x; scanf(\"%d\", &x);\n        a[i]\
    \ = {x, 1};\n    }\n\n    Lazy_Segment_Tree<M, F> S(a, op, unit, act, comp, id);\n\
    \n    for (int q = 0; q < Q; q++){\n        int t, l, r;\n        scanf(\"%d\"\
    , &t);\n\n        if (t == 0){\n            int b, c;\n            scanf(\"%d%d%d%d\"\
    , &l, &r, &b, &c);\n            S.action(l, r - 1, {b, c});\n        } elif (t\
    \ == 1) {\n            scanf(\"%d%d\", &l, &r);\n            cout << S.product(l,\
    \ r - 1).first << \"\\n\";\n        }\n    }\n}\n\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - modint.hpp
  - Segment_Tree/Lazy_Segment_Tree.hpp
  isVerificationFile: false
  path: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp
  requiredBy: []
  timestamp: '2025-08-30 19:21:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp
layout: document
redirect_from:
- /library/verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp
- /library/verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp.html
title: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.cpp
---
