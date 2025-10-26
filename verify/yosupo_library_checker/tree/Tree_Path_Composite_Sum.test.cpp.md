---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/modint.hpp
    title: Algebra/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Generator.hpp
    title: Tree/Generator.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Rerooting.hpp
    title: "\u5168\u65B9\u4F4D\u6728 DP (Rerooting DP)"
  - icon: ':heavy_check_mark:'
    path: Tree/Tree.hpp
    title: Tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Tree_DP.hpp
    title: "\u6728 DP"
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
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "#line 1 \"verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\n\
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
    \ constexpr int _mod = M; \n    uint64_t x;\n\n    public:\n    static int mod()\
    \ { return _mod; }\n\n    static modint raw(int v) {\n        modint a;\n    \
    \    a.x = v;\n        return a;\n    }\n\n    // \u521D\u671F\u5316\n    constexpr\
    \ modint(): x(0) {}\n    constexpr modint(int64_t a) {\n        int64_t w = (int64_t)(a)\
    \ % mod();\n        if (w < 0) { w += mod(); }\n        x = w;\n    }\n\n    //\
    \ \u30DE\u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x);\
    \ }\n\n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n       \
    \ if ((x += b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\n    friend\
    \ modint operator+(const modint &x, const modint &y) { return modint(x) += y;\
    \ }\n\n    // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n       \
    \ if ((x += mod() - b.x) >= mod()) x -= mod();\n        return *this;\n    }\n\
    \n    friend modint operator-(const modint &x, const modint &y) { return modint(x)\
    \ -= y; }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n \
    \       (x *= b.x) %= mod();\n        return *this;\n    }\n\n    friend modint\
    \ operator*(const modint &x, const modint &y) { return modint(x) *= y; }\n   \
    \ friend modint operator*(const int &x, const modint &y) { return modint(x) *=\
    \ y; }\n    friend modint operator*(const ll &x, const modint &y) { return modint(x)\
    \ *= y; }\n\n    // \u9664\u6CD5\n    modint& operator/=(const modint &b){ return\
    \ (*this) *= b.inverse(); }\n\n    friend modint operator/(const modint &x, const\
    \ modint &y) { return modint(x) /= y; }\n\n    modint inverse() const {\n    \
    \    int64_t s = 1, t = 0;\n        int64_t a = x, b = mod();\n\n        while\
    \ (b > 0) {\n            int64_t q = a / b;\n\n            a -= q * b; swap(a,\
    \ b);\n            s -= q * t; swap(s, t);\n        }\n\n        assert (a ==\
    \ 1);\n\n        return modint(s);\n    }\n\n    // \u6BD4\u8F03\n    friend bool\
    \ operator==(const modint &a, const modint &b) { return (a.x == b.x); }\n    friend\
    \ bool operator==(const modint &a, const int &b) { return a.x == safe_mod(b, mod());\
    \ }\n    friend bool operator!=(const modint &a, const modint &b) { return (a.x\
    \ != b.x); }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream &is,\
    \ modint &a) {\n        is >> a.x;\n        a.x = (a.x % mod() + mod()) % mod();\n\
    \        return is;\n    }\n\n    // \u51FA\u529B\n    friend ostream &operator<<(ostream\
    \ &os, const modint &a) { return os << a.x; }\n\n    bool is_zero() const { return\
    \ x == 0; }\n    bool is_member(ll a) const { return x == (a % mod() + mod())\
    \ % mod(); }\n};\n\ntemplate<int mod>\nmodint<mod> pow(modint<mod> x, long long\
    \ n) {\n    if (n < 0) { return pow(x, -n).inverse(); }\n\n    auto res = modint<mod>(1);\n\
    \    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n        x *= x;\n\
    \    }\n\n    return res;\n}\n#line 2 \"Tree/Tree.hpp\"\n\n#line 4 \"Tree/Tree.hpp\"\
    \n\nclass Tree {\n    private:\n    int N, offset, root;\n    vector<int> parent;\n\
    \    vector<vector<int>> children;\n\n    int N_bit;\n    bool locked;\n\n   \
    \ public:\n    Tree(int N, int offset = 0): N(N), offset(offset), N_bit(0) {\n\
    \        parent.assign(N + offset, -1);\n        for (; (1 << N_bit) <= N; N_bit++)\
    \ {}\n        locked = false;\n    }\n\n    bool is_locked() const { return locked;\
    \ }\n\n    public:\n    inline void set_root(const int &x) {\n        assert (!is_locked());\n\
    \        root = x;\n    }\n\n    inline int vector_size() const { return N + offset;\
    \ }\n\n    inline int get_root() const { return root; }\n    inline int get_parent(const\
    \ int &x) const { return parent[x]; }\n    inline vector<int> get_children(const\
    \ int &x) const { return children[x]; }\n\n    public:\n    // \u9802\u70B9 x\
    \ \u306E\u89AA\u3092\u9802\u70B9 y \u306B\u8A2D\u5B9A\u3059\u308B.\n    inline\
    \ void set_parent(const int &x, const int &y) {\n        assert (!is_locked());\n\
    \        parent[x] = y;\n    }\n\n    // \u9802\u70B9 x \u306E\u5B50\u306E\u4E00\
    \u3064\u306B\u9802\u70B9 y \u3092\u8A2D\u5B9A\u3059\u308B.\n    inline void set_child(const\
    \ int &x, const int &y) { set_parent(y, x); }\n\n    // \u6728\u3092\u78BA\u5B9A\
    \u3055\u305B\u308B\n    void seal() {\n        assert(!is_locked());\n\n     \
    \   parent[root] = -1;\n        children.assign(N + offset, vector<int>());\n\
    \        for (int v = offset; v < N + offset; v++) {\n            unless(is_root(v))\
    \ { children[parent[v]].emplace_back(v); }\n        }\n\n        locked = true;\n\
    \        bfs();\n    }\n\n    private:\n    vector<int> depth;\n    vector<vector<int>>\
    \ tower;\n    void bfs() {\n        assert(is_locked());\n\n        tower.assign(N,\
    \ {});\n        depth.assign(N + offset, -1);\n\n        deque<int> Q{ root };\n\
    \        tower[0] = { root };\n        depth[root] = 0;\n\n        while (!Q.empty()){\n\
    \            int x = Q.front(); Q.pop_front();\n\n            for (int y: children[x])\
    \ {\n                depth[y] = depth[x] + 1;\n                tower[depth[y]].emplace_back(y);\n\
    \                Q.push_back(y);\n            }\n        }\n    }\n\n    public:\n\
    \    vector<int> top_down() const {\n        vector<int> res;\n        for (auto\
    \ layer: tower) {\n            res.insert(res.end(), layer.begin(), layer.end());\n\
    \        }\n\n        return res;\n    }\n\n    public:\n    vector<int> bottom_up()\
    \ const {\n        vector<int> res;\n        for (auto it = tower.rbegin(); it\
    \ != tower.rend(); ++it) {\n            const auto &layer = *it;\n           \
    \ res.insert(res.end(), layer.begin(), layer.end());\n        }\n\n        return\
    \ res;\n    }\n\n    // 1 \u9802\u70B9\u306B\u95A2\u3059\u308B\u60C5\u5831\n \
    \   public:\n\n    // x \u306F\u6839?\n    bool is_root(const int &x) const {\
    \ return x == root; }\n\n    // x \u306F\u8449?\n    bool is_leaf(const int &x)\
    \ const {\n        assert(is_locked());\n        return children[x].empty();\n\
    \    }\n\n    // x \u306E\u6B21\u6570\n    int degree(const int &x) const {\n\
    \        assert(is_locked());\n        int d = children[x].size();\n        if\
    \ (is_root(x)) { d--; }\n        return d;\n    }\n\n    // \u9802\u70B9 x \u306E\
    \u6DF1\u3055\u3092\u6C42\u3081\u308B.\n    inline int vertex_depth(const int &x)\
    \ { return depth[x]; }\n\n    // 2 \u9802\u70B9\u306B\u95A2\u3059\u308B\u6761\u4EF6\
    \n\n    // x \u306F y \u306E\u89AA\u304B?\n    bool is_parent(const int &x, const\
    \ int &y) const {\n        assert(is_locked());\n        return !is_root(y) &&\
    \ x == parent[y];\n    }\n\n    // x \u306F y \u306E\u500B\u304B?\n    inline\
    \ bool is_children(const int &x, const int &y) const { return is_parent(y, x);\
    \ }\n\n    // x \u3068 y \u306F\u5144\u5F1F (\u89AA\u304C\u540C\u3058) \u304B\
    ?\n    bool is_brother(const int &x, const int &y) const {\n        assert(is_locked());\n\
    \        return !is_root(x) && !is_root(y) && parent[x] == parent[y];\n    }\n\
    \n    private:\n    bool has_upper_list = false;\n    vector<vector<int>> upper_list;\n\
    \n    void build_upper_list() {\n        assert(is_locked());\n\n        if (has_upper_list)\
    \ { return; }\n\n        has_upper_list = true;\n\n        upper_list.assign(N_bit,\
    \ vector<int>(N + offset, -1));\n\n        // Step I\n        for (int i = offset;\
    \ i < N + offset; i++) {\n            if (is_root(i)) { upper_list[0][i] = i;\
    \ }\n            else { upper_list[0][i] = parent[i]; }\n        }\n\n       \
    \ // Step II\n        for (int k = 1; k < N_bit; k++) {\n            for (int\
    \ i = offset; i < N + offset; i++) {\n                upper_list[k][i] = upper_list[k\
    \ - 1][upper_list[k - 1][i]];\n            }\n        }\n    }\n\n    public:\n\
    \    // \u9802\u70B9 x \u304B\u3089\u898B\u3066 k \u4EE3\u524D\u306E\u9802\u70B9\
    \u3092\u6C42\u3081\u308B.\n    // vertex_depth(x) < k \u306E\u3068\u304D\u8FD4\
    \u308A\u5024\u306F over = true \u306A\u3089\u3070 root, false \u306A\u3089\u3070\
    , -1 \u3067\u3042\u308B.\n    int upper(int x, int k, bool over = true) {\n  \
    \      assert(is_locked());\n\n        build_upper_list();\n        if (vertex_depth(x)\
    \ < k) { return over? root: -1; }\n\n        for(int b = 0; k; k >>= 1, b++){\
    \ \n            if (k & 1) { x = upper_list[b][x]; }\n        }\n\n        return\
    \ x;\n    }\n\n    public:\n    // \u9802\u70B9 x \u3068\u9802\u70B9 y \u306E\u6700\
    \u5C0F\u5171\u901A\u5148\u7956\u3092\u6C42\u3081\u308B.\n    int lowest_common_ancestor(int\
    \ x, int y) {\n        assert(is_locked());\n\n        if (vertex_depth(x) > vertex_depth(y))\
    \ { swap(x, y); }\n        y = upper(y, vertex_depth(y) - vertex_depth(x));\n\n\
    \        if (is_root(x) || x == y) { return x; }\n\n        for (int k = N_bit\
    \ - 1; k >= 0; k--) {\n            int px = upper_list[k][x], py = upper_list[k][y];\n\
    \            if (px != py) { x = px, y = py; }\n        }\n\n        return is_root(x)\
    \ ? root : parent[x];\n    }\n\n    int lowest_common_ancestor_greedy(int x, int\
    \ y) {\n        assert(is_locked());\n\n        if (vertex_depth(x) > vertex_depth(y))\
    \ { swap(x, y); }\n\n        while (vertex_depth(x) < vertex_depth(y)) {\n   \
    \         y = parent[y];\n        }\n\n        while (x != y) {\n            x\
    \ = get_parent(x);\n            y = get_parent(y);\n        }\n\n        return\
    \ x;\n    }\n\n    // 2 \u9802\u70B9 x, y \u9593\u306E\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B.\n    int distance(int x, int y) {\n        return vertex_depth(x)\
    \ + vertex_depth(y) - 2 * vertex_depth(lowest_common_ancestor(x, y));\n    }\n\
    \n    private:\n    bool has_euler_tour_vertex = false, has_euler_tour_edge =\
    \ false;\n\n    public:\n    vector<int> in_time, out_time;\n    vector<int> euler_tour_vertex;\n\
    \    vector<tuple<int, int, int>> euler_tour_edge;\n\n    // Euler Tour \u306B\
    \u95A2\u3059\u308B\u8A08\u7B97\u3092\u884C\u3046.\n    void calculate_euler_tour_vertex()\
    \ {\n        if(has_euler_tour_vertex) { return; }\n\n        euler_tour_vertex.clear();\n\
    \        in_time.assign(N + offset, -1);\n        out_time.assign(N + offset,\
    \ -1);\n\n        auto dfs = [&](auto self, int x) -> void {\n            in_time[x]\
    \ = (int)euler_tour_vertex.size();\n            euler_tour_vertex.emplace_back(x);\n\
    \n            for (int y: children[x]) {\n                self(self, y);\n   \
    \         }\n\n            out_time[x] = (int)euler_tour_vertex.size() - 1;\n\
    \            unless(is_root(x)) { euler_tour_vertex.emplace_back(parent[x]); }\n\
    \        };\n\n        dfs(dfs, root);\n\n        has_euler_tour_vertex = true;\n\
    \    }\n\n    void calculate_euler_tour_edge() {\n        if(has_euler_tour_edge)\
    \ { return; }\n\n        calculate_euler_tour_vertex();\n        euler_tour_edge.clear();\n\
    \n        for (int t = 0; t < 2 * (N - 1); t++) {\n            int x = euler_tour_vertex[t],\
    \ y = euler_tour_vertex[t + 1];\n            int k = (x == parent[y]) ? 1 : -1;\n\
    \            euler_tour_edge.emplace_back(make_tuple(x, y, k));\n        }\n\n\
    \        has_euler_tour_edge = true;\n    }\n\n    // \u9802\u70B9 u \u304B\u3089\
    \u9802\u70B9 v \u3078\u5411\u304B\u3046\u30D1\u30B9\u306B\u304A\u3044\u3066 k\
    \ \u756A\u76EE (0-indexed) \u306B\u901A\u308B\u9802\u70B9 (\u30D1\u30B9\u306E\u9577\
    \u3055\u304C k \u3088\u308A\u5927\u304D\u3044\u5834\u5408\u306F over)\n    int\
    \ jump(int u, int v, int k, int over = -1) {\n        if (k == 0) { return u;\
    \ }\n\n        int w = lowest_common_ancestor(u, v);\n        int dist_uw = vertex_depth(u)\
    \ - vertex_depth(w);\n        int dist_wv = vertex_depth(v) - vertex_depth(w);\n\
    \        int dist_uv = dist_uw + dist_wv;\n\n        if (dist_uv < k) { \n   \
    \         return over;\n        } else if (k <= dist_uw) {\n            return\
    \ upper(u, k);\n        } else {\n            return upper(v, dist_uv - k);\n\
    \        }\n    }\n\n    vector<int> path(int u, int v) {\n        int w = lowest_common_ancestor_greedy(u,\
    \ v);\n\n        vector<int> path_first{u}, path_second{v};\n\n        while (u\
    \ != w) {\n            u = get_parent(u);\n            path_first.emplace_back(u);\n\
    \        }\n\n        while (v != w) {\n            v = get_parent(v);\n     \
    \       path_second.emplace_back(v);\n        }\n\n        path_second.pop_back();\n\
    \        reverse(path_second.begin(), path_second.end());\n\n        path_first.insert(path_first.end(),\
    \ make_move_iterator(path_second.begin()), make_move_iterator(path_second.end()));\n\
    \n        return path_first;\n    }\n};\n\nTree Construct_Tree(int N, vector<pair<int,\
    \ int>> edges, int root, int offset = 0) {\n    vector<vector<int>> adj(N + offset,\
    \ vector<int>());\n    for (auto &[u, v]: edges) {\n        adj[u].emplace_back(v);\n\
    \        adj[v].emplace_back(u);\n    }\n\n    Tree T(N, offset);\n    T.set_root(root);\n\
    \n    vector<bool> seen(N + 1, false);\n    seen[root] = true;\n    vector<int>\
    \ stack({root});\n\n    until(stack.empty()) {\n        int v = stack.back();\n\
    \        stack.pop_back();\n\n        for (int w: adj[v]) {\n            if (seen[w])\
    \ { continue; }\n\n            seen[w] = true;\n            T.set_parent(w, v);\n\
    \            stack.emplace_back(w);\n        }\n    }\n\n    T.seal();\n    return\
    \ T;\n}\n#line 2 \"Tree/Generator.hpp\"\n\nTree Generate_Tree(int N, vector<vector<int>>\
    \ adjacent, int root, int offset = 0) {\n    Tree T(N, offset);\n    T.set_root(root);\n\
    \n    vector<bool> seen(N + offset, false); seen[root] = true;\n    deque<int>\
    \ Q{root};\n\n    while(!Q.empty()) {\n        int v = Q.back(); Q.pop_back();\n\
    \        for (int w: adjacent[v]) {\n            if (seen[w]) { continue; }\n\n\
    \            seen[w] = true;\n            T.set_child(v, w);\n            Q.push_back(w);\n\
    \        }\n    }\n\n    T.seal();\n    return T;\n}\n\nTree Generate_Tree(int\
    \ N, vector<pair<int, int>> edges, int root, int offset = 0) {\n    vector<vector<int>>\
    \ adjacent(N + offset, vector<int>());\n    for (auto &&[u, v]: edges) {\n   \
    \     adjacent[u].emplace_back(v);\n        adjacent[v].emplace_back(u);\n   \
    \ }\n\n    return Generate_Tree(N, adjacent, root, offset);\n}\n#line 2 \"Tree/Rerooting.hpp\"\
    \n\n#line 2 \"Tree/Tree_DP.hpp\"\n\n#line 4 \"Tree/Tree_DP.hpp\"\n\ntemplate<typename\
    \ X>\nvector<X> Tree_DP_from_Root(Tree &T, function<X(X, int, int)> f, const X\
    \ alpha) {\n    vector<X> data(T.vector_size());\n\n    data[T.get_root()] = alpha;\n\
    \n    for (int x: T.top_down()) {\n        for (int y: T.get_children(x)) {\n\
    \            data[y] = f(data[x], x, y);\n        }\n    }\n\n    return data;\n\
    }\n\ntemplate<typename X, typename M>\nvector<X> Tree_DP_from_Leaf(Tree &T, function<M(X,\
    \ int, int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit)\
    \ {\n    using V = int;\n\n    vector<X> data(T.vector_size());\n\n    for (V\
    \ v: T.bottom_up()) {\n        M tmp = unit;\n        for (V w: T.get_children(v))\
    \ {\n            tmp = merge(tmp, f(data[w], v, w));\n        }\n        data[v]\
    \ = g(tmp, v);\n    }\n\n    return data;\n}\n#line 5 \"Tree/Rerooting.hpp\"\n\
    \ntemplate<typename X, typename M>\nclass Rerooting_DP {\n    public:\n    vector<X>\
    \ lower, upper, result;\n\n    public:\n    Rerooting_DP(Tree &T, function<M(X,\
    \ int, int)> f, function<X(M, int)> g, function<X(M, int)> h, function<M(M, M)>\
    \ merge, const M unit) {\n        using V = int;\n\n        // T \u306E\u9802\u70B9\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u95A2\u3059\u308B\u5024\
    \n        lower = Tree_DP_from_Leaf(T, f, g, merge, unit);\n        upper.resize(T.vector_size());\n\
    \n        for (V v: T.top_down()) {\n            const auto &children_v = T.get_children(v);\n\
    \    \n            vector<M> left{unit}, right{unit};\n            for (V c: children_v)\
    \ {\n                left.emplace_back(merge(left.back(), f(lower[c], v, c)));\n\
    \            }\n\n            for (auto it = children_v.rbegin(); it != children_v.rend();\
    \ ++it) {\n                V c = *it;\n                right.emplace_back(merge(right.back(),\
    \ f(lower[c], v, c)));\n            }\n\n            reverse(right.begin(), right.end());\n\
    \            for (int i = 0; i < children_v.size(); i++) {\n                V\
    \ c = children_v[i];\n                M a = merge(left[i], right[i + 1]);\n  \
    \              M b = T.is_root(v) ? a : merge(a, f(upper[v], v, T.get_parent(v)));\n\
    \n                upper[c] = g(b, v);\n            }\n        }\n\n        result.resize(T.vector_size());\n\
    \        for (V v: T.top_down()) {\n            M a = T.is_root(v) ? unit : f(upper[v],\
    \ v, T.get_parent(v));\n            for (V c: T.get_children(v)) {\n         \
    \       a = merge(a, f(lower[c], v, c));\n            }\n\n            result[v]\
    \ = h(a, v);\n        }\n    }\n\n    Rerooting_DP(Tree &T, function<M(X, int,\
    \ int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit):\n  \
    \      Rerooting_DP(T, f, g, g, merge, unit) {}\n};\n#line 7 \"verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct X {\n    mint p;\n    int subtree_size;\n\
    };\n\nstruct M {\n    mint q;\n    int subtree_size;\n};\n\nint main() {\n   \
    \ int N; cin >> N;\n\n    vector<pair<int, int>> edges(N - 1);\n    vector<mint>\
    \ a(N);\n    map<pair<int, int>, pair<mint, mint>> edge_function;\n\n    for (int\
    \ i = 0; i < N; i++) { int x; scanf(\"%d\", &x); a[i] = mint(x); }\n    for (int\
    \ j = 0; j < N - 1; j++) {\n        int u, v, x, y;\n        scanf(\"%d%d%d%d\"\
    , &u, &v, &x, &y);\n        mint b(x), c(y);\n\n        if (u > v) { swap(u, v);\
    \ }\n        edge_function[{u, v}] = { b, c };\n        edges[j] = { u, v };\n\
    \    }\n\n    Tree T = Generate_Tree(N, edges, 0);\n\n    function<M(X, int, int)>\
    \ f = [&edge_function](const X x, int u, int v) -> M {\n        if (u > v) { swap(u,\
    \ v); }\n        const auto &[b, c] = edge_function[{u, v}];\n\n        return\
    \ { b * x.p + c * x.subtree_size, x.subtree_size };\n    };\n\n    function<X(M,\
    \ int)> g = [&a](const M s, const int v) -> X {\n        return { s.q + a[v],\
    \ s.subtree_size + 1};\n    };\n\n    function<M(M, M)> merge = [](const M s,\
    \ const M t) -> M {\n        return { s.q + t.q, s.subtree_size + t.subtree_size};\n\
    \    };\n\n    Rerooting_DP<X, M> rerooting(T, f, g, merge, {0, 0});\n\n    for\
    \ (int v = 0; v < N; v++) {\n        cout << (v ? \" \" : \"\") << rerooting.result[v].p;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include\"template/template.hpp\"\n#include\"Algebra/modint.hpp\"\n#include\"\
    Tree/Generator.hpp\"\n#include\"Tree/Rerooting.hpp\"\n\nusing mint = modint<998244353>;\n\
    \nstruct X {\n    mint p;\n    int subtree_size;\n};\n\nstruct M {\n    mint q;\n\
    \    int subtree_size;\n};\n\nint main() {\n    int N; cin >> N;\n\n    vector<pair<int,\
    \ int>> edges(N - 1);\n    vector<mint> a(N);\n    map<pair<int, int>, pair<mint,\
    \ mint>> edge_function;\n\n    for (int i = 0; i < N; i++) { int x; scanf(\"%d\"\
    , &x); a[i] = mint(x); }\n    for (int j = 0; j < N - 1; j++) {\n        int u,\
    \ v, x, y;\n        scanf(\"%d%d%d%d\", &u, &v, &x, &y);\n        mint b(x), c(y);\n\
    \n        if (u > v) { swap(u, v); }\n        edge_function[{u, v}] = { b, c };\n\
    \        edges[j] = { u, v };\n    }\n\n    Tree T = Generate_Tree(N, edges, 0);\n\
    \n    function<M(X, int, int)> f = [&edge_function](const X x, int u, int v) ->\
    \ M {\n        if (u > v) { swap(u, v); }\n        const auto &[b, c] = edge_function[{u,\
    \ v}];\n\n        return { b * x.p + c * x.subtree_size, x.subtree_size };\n \
    \   };\n\n    function<X(M, int)> g = [&a](const M s, const int v) -> X {\n  \
    \      return { s.q + a[v], s.subtree_size + 1};\n    };\n\n    function<M(M,\
    \ M)> merge = [](const M s, const M t) -> M {\n        return { s.q + t.q, s.subtree_size\
    \ + t.subtree_size};\n    };\n\n    Rerooting_DP<X, M> rerooting(T, f, g, merge,\
    \ {0, 0});\n\n    for (int v = 0; v < N; v++) {\n        cout << (v ? \" \" :\
    \ \"\") << rerooting.result[v].p;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - Algebra/modint.hpp
  - Tree/Generator.hpp
  - Tree/Tree.hpp
  - Tree/Rerooting.hpp
  - Tree/Tree_DP.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-26 00:25:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp
- /verify/verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp.html
title: verify/yosupo_library_checker/tree/Tree_Path_Composite_Sum.test.cpp
---
