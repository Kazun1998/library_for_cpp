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
    path: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
    title: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tree/Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\n\n\
    using namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n// a \u2190 max(a, b)\
    \ \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089\
    , \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool\
    \ chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n// a \u2190\
    \ min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\
    \u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline\
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n#line 59\
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u9664\
    \u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x >\
    \ 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y\
    \ - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x, U y){\n    T\
    \ q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\
    \u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n \
    \   return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q, r;\n \
    \   tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n\
    }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\
    \u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n\
    \        if (y & 1) { a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n  \
    \  return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n\
    \    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T,\
    \ typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n    \
    \    if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n\
    \    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto &&x:\
    \ X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T> &X){\n    T y\
    \ = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n#line 62 \"template/template.hpp\"\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n#line 65 \"template/template.hpp\"\
    \n\n// macro\n#line 2 \"template/macro.hpp\"\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\
    \u7FA9\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n#define unless(cond) if (!(cond))\n\n// \u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1, _2, name, ...) name\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define overload4(_1, _2, _3, _4,\
    \ name, ...) name\n#define overload5(_1, _2, _3, _4, _5, name, ...) name\n\n//\
    \ \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for (ll i = 0; i < n; i++)\n\
    #define rep2(i, n) for (ll i = 0; i < n; i++)\n#define rep3(i, a, b) for (ll i\
    \ = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)\n#define\
    \ rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define\
    \ foreach1(x, a) for (auto &&x: a)\n#define foreach2(x, y, a) for (auto &&[x,\
    \ y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y, z]: a)\n#define foreach4(x,\
    \ y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__,\
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 4 \"Tree/Tree.hpp\"\
    \n\nclass Tree {\n    private:\n    int N, offset, root;\n    vector<int> parent;\n\
    \    vector<set<int>> children;\n\n    int N_bit;\n    bool locked;\n\n    public:\n\
    \    Tree(int N, int offset = 0): N(N), offset(offset), N_bit(0) {\n        parent.assign(N\
    \ + offset, -1);\n        for (; (1 << N_bit) <= N; N_bit++) {}\n        locked\
    \ = false;\n    }\n\n    bool is_locked() const { return locked; }\n\n    public:\n\
    \    inline void set_root(const int &x) {\n        assert (!is_locked());\n  \
    \      root = x;\n    }\n\n    public:\n    // \u9802\u70B9 x \u306E\u89AA\u3092\
    \u9802\u70B9 y \u306B\u8A2D\u5B9A\u3059\u308B.\n    inline void set_parent(const\
    \ int &x, const int &y) {\n        assert (!is_locked());\n        parent[x] =\
    \ y;\n    }\n\n    // \u9802\u70B9 x \u306E\u5B50\u306E\u4E00\u3064\u306B\u9802\
    \u70B9 y \u3092\u8A2D\u5B9A\u3059\u308B.\n    inline void set_child(const int\
    \ &x, const int &y) { set_parent(y, x); }\n\n    // \u6728\u3092\u78BA\u5B9A\u3055\
    \u305B\u308B\n    void seal() {\n        assert(!is_locked());\n\n        parent[root]\
    \ = -1;\n        children.assign(N + offset, set<int>());\n        for (int v\
    \ = offset; v < N + offset; v++) {\n            unless(is_root(v)) { children[parent[v]].insert(v);\
    \ }\n        }\n\n        locked = true;\n        bfs();\n    }\n\n    private:\n\
    \    vector<int> depth;\n    vector<vector<int>> tower;\n    void bfs() {\n  \
    \      assert(is_locked());\n\n        tower.assign(N, {});\n        depth.assign(N\
    \ + offset, -1);\n\n        deque<int> Q{ root };\n        tower[0] = { root };\n\
    \        depth[root] = 0;\n\n        while (!Q.empty()){\n            int x =\
    \ Q.front(); Q.pop_front();\n\n            for (int y: children[x]) {\n      \
    \          depth[y] = depth[x] + 1;\n                tower[depth[y]].emplace_back(y);\n\
    \                Q.push_back(y);\n            }\n        }\n    }\n\n    // 1\
    \ \u9802\u70B9\u306B\u95A2\u3059\u308B\u60C5\u5831\n    public:\n\n    // x \u306F\
    \u6839?\n    bool is_root(const int &x) const { return x == root; }\n\n    //\
    \ x \u306F\u8449?\n    bool is_leaf(const int &x) const {\n        assert(is_locked());\n\
    \        return children[x].empty();\n    }\n\n    // x \u306E\u6B21\u6570\n \
    \   int degree(const int &x) const {\n        assert(is_locked());\n        int\
    \ d = children[x].size();\n        if (is_root(x)) { d--; }\n        return d;\n\
    \    }\n\n    inline int vertex_depth(const int &x) { return depth[x]; }\n\n \
    \   // 2 \u9802\u70B9\u306B\u95A2\u3059\u308B\u6761\u4EF6\n\n    // x \u306F y\
    \ \u306E\u89AA\u304B?\n    bool is_parent(const int &x, const int &y) const {\n\
    \        assert(is_locked());\n        return !is_root(y) && x == parent[y];\n\
    \    }\n\n    // x \u306F y \u306E\u500B\u304B?\n    inline bool is_children(const\
    \ int &x, const int &y) const { return is_parent(y, x); }\n\n    // x \u3068 y\
    \ \u306F\u5144\u5F1F (\u89AA\u304C\u540C\u3058) \u304B?\n    bool is_brother(const\
    \ int &x, const int &y) const {\n        assert(is_locked());\n        return\
    \ !is_root(x) && !is_root(y) && parent[x] == parent[y];\n    }\n\n    private:\n\
    \    bool has_upper_list = false;\n    vector<vector<int>> upper_list;\n\n   \
    \ void build_upper_list() {\n        assert(is_locked());\n\n        if (has_upper_list)\
    \ { return; }\n\n        has_upper_list = true;\n\n        upper_list.assign(N_bit,\
    \ vector<int>(N + offset, -1));\n\n        // Step I\n        for (int i = offset;\
    \ i < N + offset; i++) {\n            if (is_root(i)) { upper_list[0][i] = i;\
    \ }\n            else { upper_list[0][i] = parent[i]; }\n        }\n\n       \
    \ // Step II\n        for (int k = 1; k < N_bit; k++) {\n            for (int\
    \ i = offset; i < N + offset; i++) {\n                upper_list[k][i] = upper_list[k\
    \ - 1][upper_list[k - 1][i]];\n            }\n        }\n    }\n\n    public:\n\
    \    int upper(int x, int k, bool over = true) {\n        assert(is_locked());\n\
    \n        build_upper_list();\n        if (vertex_depth(x) < k) { return over?\
    \ root: -1; }\n\n        for(int b = 0; k; k >>= 1, b++){ \n            if (k\
    \ & 1) { x = upper_list[b][x]; }\n        }\n\n        return x;\n    }\n\n  \
    \  public:\n    int lowest_common_ancestor(int x, int y) {\n        assert(is_locked());\n\
    \n        if (vertex_depth(x) > vertex_depth(y)) { swap(x, y); }\n        y =\
    \ upper(y, vertex_depth(y) - vertex_depth(x));\n\n        if (is_root(x) || x\
    \ == y) { return x; }\n\n        for (int k = N_bit - 1; k >= 0; k--) {\n    \
    \        int px = upper_list[k][x], py = upper_list[k][y];\n            if (px\
    \ != py) { x = px, y = py; }\n        }\n\n        return is_root(x) ? root :\
    \ parent[x];\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nclass Tree {\n  \
    \  private:\n    int N, offset, root;\n    vector<int> parent;\n    vector<set<int>>\
    \ children;\n\n    int N_bit;\n    bool locked;\n\n    public:\n    Tree(int N,\
    \ int offset = 0): N(N), offset(offset), N_bit(0) {\n        parent.assign(N +\
    \ offset, -1);\n        for (; (1 << N_bit) <= N; N_bit++) {}\n        locked\
    \ = false;\n    }\n\n    bool is_locked() const { return locked; }\n\n    public:\n\
    \    inline void set_root(const int &x) {\n        assert (!is_locked());\n  \
    \      root = x;\n    }\n\n    public:\n    // \u9802\u70B9 x \u306E\u89AA\u3092\
    \u9802\u70B9 y \u306B\u8A2D\u5B9A\u3059\u308B.\n    inline void set_parent(const\
    \ int &x, const int &y) {\n        assert (!is_locked());\n        parent[x] =\
    \ y;\n    }\n\n    // \u9802\u70B9 x \u306E\u5B50\u306E\u4E00\u3064\u306B\u9802\
    \u70B9 y \u3092\u8A2D\u5B9A\u3059\u308B.\n    inline void set_child(const int\
    \ &x, const int &y) { set_parent(y, x); }\n\n    // \u6728\u3092\u78BA\u5B9A\u3055\
    \u305B\u308B\n    void seal() {\n        assert(!is_locked());\n\n        parent[root]\
    \ = -1;\n        children.assign(N + offset, set<int>());\n        for (int v\
    \ = offset; v < N + offset; v++) {\n            unless(is_root(v)) { children[parent[v]].insert(v);\
    \ }\n        }\n\n        locked = true;\n        bfs();\n    }\n\n    private:\n\
    \    vector<int> depth;\n    vector<vector<int>> tower;\n    void bfs() {\n  \
    \      assert(is_locked());\n\n        tower.assign(N, {});\n        depth.assign(N\
    \ + offset, -1);\n\n        deque<int> Q{ root };\n        tower[0] = { root };\n\
    \        depth[root] = 0;\n\n        while (!Q.empty()){\n            int x =\
    \ Q.front(); Q.pop_front();\n\n            for (int y: children[x]) {\n      \
    \          depth[y] = depth[x] + 1;\n                tower[depth[y]].emplace_back(y);\n\
    \                Q.push_back(y);\n            }\n        }\n    }\n\n    // 1\
    \ \u9802\u70B9\u306B\u95A2\u3059\u308B\u60C5\u5831\n    public:\n\n    // x \u306F\
    \u6839?\n    bool is_root(const int &x) const { return x == root; }\n\n    //\
    \ x \u306F\u8449?\n    bool is_leaf(const int &x) const {\n        assert(is_locked());\n\
    \        return children[x].empty();\n    }\n\n    // x \u306E\u6B21\u6570\n \
    \   int degree(const int &x) const {\n        assert(is_locked());\n        int\
    \ d = children[x].size();\n        if (is_root(x)) { d--; }\n        return d;\n\
    \    }\n\n    inline int vertex_depth(const int &x) { return depth[x]; }\n\n \
    \   // 2 \u9802\u70B9\u306B\u95A2\u3059\u308B\u6761\u4EF6\n\n    // x \u306F y\
    \ \u306E\u89AA\u304B?\n    bool is_parent(const int &x, const int &y) const {\n\
    \        assert(is_locked());\n        return !is_root(y) && x == parent[y];\n\
    \    }\n\n    // x \u306F y \u306E\u500B\u304B?\n    inline bool is_children(const\
    \ int &x, const int &y) const { return is_parent(y, x); }\n\n    // x \u3068 y\
    \ \u306F\u5144\u5F1F (\u89AA\u304C\u540C\u3058) \u304B?\n    bool is_brother(const\
    \ int &x, const int &y) const {\n        assert(is_locked());\n        return\
    \ !is_root(x) && !is_root(y) && parent[x] == parent[y];\n    }\n\n    private:\n\
    \    bool has_upper_list = false;\n    vector<vector<int>> upper_list;\n\n   \
    \ void build_upper_list() {\n        assert(is_locked());\n\n        if (has_upper_list)\
    \ { return; }\n\n        has_upper_list = true;\n\n        upper_list.assign(N_bit,\
    \ vector<int>(N + offset, -1));\n\n        // Step I\n        for (int i = offset;\
    \ i < N + offset; i++) {\n            if (is_root(i)) { upper_list[0][i] = i;\
    \ }\n            else { upper_list[0][i] = parent[i]; }\n        }\n\n       \
    \ // Step II\n        for (int k = 1; k < N_bit; k++) {\n            for (int\
    \ i = offset; i < N + offset; i++) {\n                upper_list[k][i] = upper_list[k\
    \ - 1][upper_list[k - 1][i]];\n            }\n        }\n    }\n\n    public:\n\
    \    int upper(int x, int k, bool over = true) {\n        assert(is_locked());\n\
    \n        build_upper_list();\n        if (vertex_depth(x) < k) { return over?\
    \ root: -1; }\n\n        for(int b = 0; k; k >>= 1, b++){ \n            if (k\
    \ & 1) { x = upper_list[b][x]; }\n        }\n\n        return x;\n    }\n\n  \
    \  public:\n    int lowest_common_ancestor(int x, int y) {\n        assert(is_locked());\n\
    \n        if (vertex_depth(x) > vertex_depth(y)) { swap(x, y); }\n        y =\
    \ upper(y, vertex_depth(y) - vertex_depth(x));\n\n        if (is_root(x) || x\
    \ == y) { return x; }\n\n        for (int k = N_bit - 1; k >= 0; k--) {\n    \
    \        int px = upper_list[k][x], py = upper_list[k][y];\n            if (px\
    \ != py) { x = px, y = py; }\n        }\n\n        return is_root(x) ? root :\
    \ parent[x];\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  isVerificationFile: false
  path: Tree/Tree.hpp
  requiredBy: []
  timestamp: '2025-09-06 23:10:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
documentation_of: Tree/Tree.hpp
layout: document
redirect_from:
- /library/Tree/Tree.hpp
- /library/Tree/Tree.hpp.html
title: Tree/Tree.hpp
---
