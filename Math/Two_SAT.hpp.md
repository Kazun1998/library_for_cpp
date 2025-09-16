---
data:
  _extendedDependsOn:
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
    path: verify/yosupo_library_checker/other/two_sat.test.cpp
    title: verify/yosupo_library_checker/other/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
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
    #line 2 \"Math/Two_SAT.hpp\"\n\nclass Two_SAT{\n    public:\n    vector<vector<int>>\
    \ arc,rev;\n    bool satisfiable;\n    vector<bool> answer;\n\n    private:\n\
    \    int N;\n\n    public:\n    Two_SAT(int N): N(N) {\n        arc.resize(2 *\
    \ N);\n        rev.resize(2 * N);\n    }\n\n    public:\n    // \u9802\u70B9\u3092\
    \ 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_variable() {\n        int id\
    \ = N;\n        arc.emplace_back(vector<int>()); arc.emplace_back(vector<int>());\n\
    \        rev.emplace_back(vector<int>()); rev.emplace_back(vector<int>());\n \
    \       N++;\n\n        return id;\n    }\n\n    // \u9802\u70B9\u3092 k \u500B\
    \u8FFD\u52A0\u3059\u308B.\n    vector<int> add_variables(int k = 1) {\n      \
    \  vector<int> I;\n        for (; k > 0; k--){ I.emplace_back(add_variable());\
    \ }\n        return I;\n    }\n\n    public:\n    inline int variable_number()\
    \ { return N; }\n\n    private:\n    inline int var_to_index(const int v) const\
    \ { return max(2 * v, 2 * (-v - 1) + 1); }\n\n    private:\n    // \u5F27 X[i]\
    \ => X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    // \u305F\u3060\u3057, X[~i] =\
    \ not X[i] \u3068\u3059\u308B.\n    void add_clause(int i, int j) {\n        int\
    \ p = var_to_index(i), q = var_to_index(j);\n        arc[p].emplace_back(q);\n\
    \        rev[q].emplace_back(p);\n    }\n\n    public:\n    // \u7BC0 (X[i] =\
    \ f) => (X[j] = g) \u3092\u8FFD\u52A0\u3059\u308B.\n    void add_imply(int i,\
    \ bool f, int j, int g) { add_imply(f ? i: ~i, g ? j: ~j); }\n\n    void add_imply(int\
    \ i, int j) {\n        add_clause(i, j);\n        add_clause(~j, ~i);\n    }\n\
    \n    public:\n    // (X[i] = f) or (X[j] = g) \u3092\u8FFD\u52A0\u3059\u308B\
    .\n    inline void add_or(int i, bool f, int j, bool g) { add_imply(i, !f, j,\
    \ g); }\n    inline void add_or(int i, int j) { add_imply(~i, j); }\n\n    public:\n\
    \    // not ((X[i] = f) and (X[j] = g)) \u3092\u8FFD\u52A0\u3059\u308B.\n    inline\
    \ void add_nand(int i, bool f, int j, bool g) { add_imply(i, f, j, !g); }\n  \
    \  inline void add_nand(int i, int j) { add_imply(i, ~j); }\n\n    public:\n \
    \   // X[i] = X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    inline void add_equal(int\
    \ i, int j) { add_imply(i, j); add_imply(j, i); }\n\n    public:\n    // X[i]\
    \ != X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    inline void add_not_equal(int i,\
    \ int j) { add_equal(i, ~j); }\n\n    public:\n    // X[i] = True \u3068\u3059\
    \u308B.\n    inline void set_true(int i) { add_clause(~i, i); }\n\n    public:\n\
    \    // X[i]=False \u3068\u3059\u308B.\n    inline void set_false(int i) {add_clause(i,\
    \ ~i); }\n\n    // \u4EE5\u4E0B, 2-SAT \u3092\u89E3\u304F\u305F\u3081\u306E\u5F37\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\u306B\u95A2\u3059\u308B\u30E1\u30BD\u30C3\
    \u30C9\u305F\u3061\n    private:\n    int id_number;\n    vector<int> id;\n  \
    \  vector<int> order; vector<bool> used;\n\n    public:\n    bool solve() {\n\
    \        order.clear();\n        used.assign(2 * N, false);\n\n        for (int\
    \ i = 0; i < 2 * N; i++){\n            if (!used[i]) { dfs1(i); }\n        }\n\
    \n        reverse(order.begin(), order.end());\n        id.assign(2 * N, -1);\n\
    \n        id_number = 0;\n        for (int v: order){\n            unless(id[v]\
    \ == -1) { continue; }\n\n            dfs2(v);\n            id_number++;\n   \
    \     }\n\n        answer.assign(N, false);\n        for (int i = 0; i < N; i++){\n\
    \            if (id[2 * i] == id[2 * i + 1]){\n                answer.clear();\n\
    \                return satisfiable=false;\n            }\n\n            answer[i]\
    \ = (id[2 * i] > id[2 * i + 1]);\n        }\n\n        return satisfiable = true;\n\
    \    }\n\n    private:\n    void dfs1(int v){\n        used[v] = true;\n     \
    \   for (int w: arc[v]){\n            unless (used[w]) { dfs1(w); }\n        }\n\
    \        order.emplace_back(v);\n    }\n\n    void dfs2(int v){\n        id[v]\
    \ = id_number;\n        for (auto w: rev[v]){\n            if (id[w] == -1) {\
    \ dfs2(w); }\n        }\n    }\n};\n"
  code: "#include\"../template/template.hpp\"\n\nclass Two_SAT{\n    public:\n   \
    \ vector<vector<int>> arc,rev;\n    bool satisfiable;\n    vector<bool> answer;\n\
    \n    private:\n    int N;\n\n    public:\n    Two_SAT(int N): N(N) {\n      \
    \  arc.resize(2 * N);\n        rev.resize(2 * N);\n    }\n\n    public:\n    //\
    \ \u9802\u70B9\u3092 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_variable()\
    \ {\n        int id = N;\n        arc.emplace_back(vector<int>()); arc.emplace_back(vector<int>());\n\
    \        rev.emplace_back(vector<int>()); rev.emplace_back(vector<int>());\n \
    \       N++;\n\n        return id;\n    }\n\n    // \u9802\u70B9\u3092 k \u500B\
    \u8FFD\u52A0\u3059\u308B.\n    vector<int> add_variables(int k = 1) {\n      \
    \  vector<int> I;\n        for (; k > 0; k--){ I.emplace_back(add_variable());\
    \ }\n        return I;\n    }\n\n    public:\n    inline int variable_number()\
    \ { return N; }\n\n    private:\n    inline int var_to_index(const int v) const\
    \ { return max(2 * v, 2 * (-v - 1) + 1); }\n\n    private:\n    // \u5F27 X[i]\
    \ => X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    // \u305F\u3060\u3057, X[~i] =\
    \ not X[i] \u3068\u3059\u308B.\n    void add_clause(int i, int j) {\n        int\
    \ p = var_to_index(i), q = var_to_index(j);\n        arc[p].emplace_back(q);\n\
    \        rev[q].emplace_back(p);\n    }\n\n    public:\n    // \u7BC0 (X[i] =\
    \ f) => (X[j] = g) \u3092\u8FFD\u52A0\u3059\u308B.\n    void add_imply(int i,\
    \ bool f, int j, int g) { add_imply(f ? i: ~i, g ? j: ~j); }\n\n    void add_imply(int\
    \ i, int j) {\n        add_clause(i, j);\n        add_clause(~j, ~i);\n    }\n\
    \n    public:\n    // (X[i] = f) or (X[j] = g) \u3092\u8FFD\u52A0\u3059\u308B\
    .\n    inline void add_or(int i, bool f, int j, bool g) { add_imply(i, !f, j,\
    \ g); }\n    inline void add_or(int i, int j) { add_imply(~i, j); }\n\n    public:\n\
    \    // not ((X[i] = f) and (X[j] = g)) \u3092\u8FFD\u52A0\u3059\u308B.\n    inline\
    \ void add_nand(int i, bool f, int j, bool g) { add_imply(i, f, j, !g); }\n  \
    \  inline void add_nand(int i, int j) { add_imply(i, ~j); }\n\n    public:\n \
    \   // X[i] = X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    inline void add_equal(int\
    \ i, int j) { add_imply(i, j); add_imply(j, i); }\n\n    public:\n    // X[i]\
    \ != X[j] \u3092\u8FFD\u52A0\u3059\u308B.\n    inline void add_not_equal(int i,\
    \ int j) { add_equal(i, ~j); }\n\n    public:\n    // X[i] = True \u3068\u3059\
    \u308B.\n    inline void set_true(int i) { add_clause(~i, i); }\n\n    public:\n\
    \    // X[i]=False \u3068\u3059\u308B.\n    inline void set_false(int i) {add_clause(i,\
    \ ~i); }\n\n    // \u4EE5\u4E0B, 2-SAT \u3092\u89E3\u304F\u305F\u3081\u306E\u5F37\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\u306B\u95A2\u3059\u308B\u30E1\u30BD\u30C3\
    \u30C9\u305F\u3061\n    private:\n    int id_number;\n    vector<int> id;\n  \
    \  vector<int> order; vector<bool> used;\n\n    public:\n    bool solve() {\n\
    \        order.clear();\n        used.assign(2 * N, false);\n\n        for (int\
    \ i = 0; i < 2 * N; i++){\n            if (!used[i]) { dfs1(i); }\n        }\n\
    \n        reverse(order.begin(), order.end());\n        id.assign(2 * N, -1);\n\
    \n        id_number = 0;\n        for (int v: order){\n            unless(id[v]\
    \ == -1) { continue; }\n\n            dfs2(v);\n            id_number++;\n   \
    \     }\n\n        answer.assign(N, false);\n        for (int i = 0; i < N; i++){\n\
    \            if (id[2 * i] == id[2 * i + 1]){\n                answer.clear();\n\
    \                return satisfiable=false;\n            }\n\n            answer[i]\
    \ = (id[2 * i] > id[2 * i + 1]);\n        }\n\n        return satisfiable = true;\n\
    \    }\n\n    private:\n    void dfs1(int v){\n        used[v] = true;\n     \
    \   for (int w: arc[v]){\n            unless (used[w]) { dfs1(w); }\n        }\n\
    \        order.emplace_back(v);\n    }\n\n    void dfs2(int v){\n        id[v]\
    \ = id_number;\n        for (auto w: rev[v]){\n            if (id[w] == -1) {\
    \ dfs2(w); }\n        }\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  isVerificationFile: false
  path: Math/Two_SAT.hpp
  requiredBy: []
  timestamp: '2025-09-17 00:08:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/other/two_sat.test.cpp
documentation_of: Math/Two_SAT.hpp
layout: document
redirect_from:
- /library/Math/Two_SAT.hpp
- /library/Math/Two_SAT.hpp.html
title: Math/Two_SAT.hpp
---
