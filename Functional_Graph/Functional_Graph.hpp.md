---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/original/Functional_Graph.test.cpp
    title: verify/original/Functional_Graph.test.cpp
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
    \ get_bits(x, bit_length(x)); }\n#line 2 \"Functional_Graph/Functional_Graph.hpp\"\
    \n\nclass Functional_Graph {\n    private:\n    vector<int> f;\n    vector<vector<int>>\
    \ f_inv;\n    int N;\n\n    vector<vector<int>> cycles;\n    vector<int> cycle_ids,\
    \ cycle_vertex_ids;\n\n    vector<int> tree_ids, tree_vertex_ids, tree_depth;\n\
    \    vector<vector<int>> tree_vertices;\n    vector<vector<vector<int>>> tree_doubling;\n\
    \n    public:\n    Functional_Graph(const vector<int> &f): f(f), N(f.size()) {\n\
    \        f_inv.resize(N);\n        for (int x = 0; x < N; x++) { f_inv[f[x]].emplace_back(x);\
    \ }\n        build_up();\n    }\n\n    private:\n    void build_up() {\n     \
    \   build_cycles();\n        build_branches();\n    }\n\n    // \u30B5\u30A4\u30AF\
    \u30EB\u691C\u51FA\u30D1\u30FC\u30C8\n    void build_cycles() {\n        vector<int>\
    \ indegree(N);\n        stack<int> st;\n        for (int x = 0; x < N; x++) {\n\
    \            indegree[x] = f_inv[x].size();\n            if (indegree[x] == 0)\
    \ { st.push(x); }\n        }\n\n        vector<bool> cycle_flag(N, true);\n\n\
    \        while (!st.empty()) {\n            int x = st.top();\n            st.pop();\n\
    \n            cycle_flag[x] = false;\n            indegree[f[x]]--;\n        \
    \    if (indegree[f[x]] == 0) { st.push(f[x]); }\n        }\n\n        cycles.clear();\n\
    \        cycle_ids.assign(N, -1);\n        cycle_vertex_ids.assign(N, -1);\n\n\
    \        for (int x = 0; x < N; x++) {\n            if (!cycle_flag[x]) { continue;\
    \ }\n\n            int cycle_id = cycles.size();\n\n            vector<int> cycle{x};\n\
    \            cycle_flag[x] = false;\n            int y = f[x];\n            while\
    \ (y != x) {\n                cycle.emplace_back(y);\n                cycle_flag[y]\
    \ = false;\n                y = f[y];\n            }\n\n            cycles.emplace_back(cycle);\n\
    \            for (int j = 0; j < cycle.size(); j++) {\n                int y =\
    \ cycle[j];\n                cycle_ids[y] = cycle_id;\n                cycle_vertex_ids[y]\
    \ = j;\n            }\n        }\n    }\n\n    void build_branches() {\n     \
    \   tree_ids.assign(N, -1);\n        tree_vertex_ids.assign(N, -1);\n        tree_depth.assign(N,\
    \ 0);\n\n        for (int x = 0; x < N; x++) {\n            if (cycle_ids[x] ==\
    \ -1) { continue; }\n\n            int tree_id = tree_vertices.size();\n     \
    \       vector<int> tree_vertex{x};\n\n            int vertex_id = 0;\n      \
    \      tree_ids[x] = tree_id;\n            tree_vertex_ids[x] = vertex_id;\n\n\
    \            stack<int> st;\n            st.push(x);\n\n            int max_depth\
    \ = 0;\n\n            while (!st.empty()) {\n                int y = st.top();\
    \ st.pop();\n\n                for (int z: f_inv[y]) {\n                    if\
    \ (cycle_ids[z] != -1) { continue; }\n\n                    vertex_id++;\n   \
    \                 tree_ids[z] = tree_id;\n                    tree_vertex_ids[z]\
    \ = vertex_id;\n\n                    tree_depth[z] = tree_depth[y] + 1;\n   \
    \                 chmax(max_depth, tree_depth[z]);\n\n                    st.push(z);\n\
    \                    tree_vertex.emplace_back(z);\n                }\n       \
    \     }\n\n            tree_vertices.emplace_back(tree_vertex);\n            int\
    \ m = tree_vertex.size();\n            vector<vector<int>> doubling(max<int>(1,\
    \ bit_length(max_depth)), vector<int>(m, -1));\n\n            for (int j = 1;\
    \ j < m; j++) {\n                doubling[0][j] = tree_vertex_ids[f[tree_vertex[j]]];\n\
    \            }\n\n            for (int b = 1; b < max<int>(1, bit_length(max_depth));\
    \ b++) {\n                for (int j = 0; j < m; j++) {\n                    doubling[b][j]\
    \ = doubling[b - 1][doubling[b - 1][j]];\n                }\n            }\n\n\
    \            tree_doubling.emplace_back(doubling);\n        }\n    }\n\n    int\
    \ upper(int x, ll k) {\n        int tree_id = tree_ids[x];\n        int vertex_id\
    \ = tree_vertex_ids[x];\n\n        vector<vector<int>> doubling = tree_doubling[tree_id];\n\
    \        for (int b = 0; k; k >>= 1, b++) {\n            if (k & 1) { vertex_id\
    \ = doubling[b][vertex_id]; }\n        }\n\n        return tree_vertices[tree_id][vertex_id];\n\
    \    }\n\n    int jump_on_cycle(int cycle_id, int vertex_id, ll k) {\n       \
    \ auto &cycle = cycles[cycle_id];\n        int m = cycle.size();\n        k =\
    \ safe_mod(k, m);\n        return cycle[(vertex_id + k) % m];\n    }\n\n    public:\n\
    \    inline int root(int x) const { return tree_vertices[tree_ids[x]][0]; }\n\n\
    \    int calculate(int x, ll k) {\n        if ( k < tree_depth[x]) { return upper(x,\
    \ k); }\n\n        k -= tree_depth[x];\n        x = root(x);\n\n        int cycle_id\
    \ = cycle_ids[x];\n        int vertex_id = cycle_vertex_ids[x];\n        return\
    \ jump_on_cycle(cycle_id, vertex_id, k);\n    }\n\n    vector<vector<int>> &get_cycles()\
    \ { return cycles; }\n};\n"
  code: "#include\"../template/template.hpp\"\n\nclass Functional_Graph {\n    private:\n\
    \    vector<int> f;\n    vector<vector<int>> f_inv;\n    int N;\n\n    vector<vector<int>>\
    \ cycles;\n    vector<int> cycle_ids, cycle_vertex_ids;\n\n    vector<int> tree_ids,\
    \ tree_vertex_ids, tree_depth;\n    vector<vector<int>> tree_vertices;\n    vector<vector<vector<int>>>\
    \ tree_doubling;\n\n    public:\n    Functional_Graph(const vector<int> &f): f(f),\
    \ N(f.size()) {\n        f_inv.resize(N);\n        for (int x = 0; x < N; x++)\
    \ { f_inv[f[x]].emplace_back(x); }\n        build_up();\n    }\n\n    private:\n\
    \    void build_up() {\n        build_cycles();\n        build_branches();\n \
    \   }\n\n    // \u30B5\u30A4\u30AF\u30EB\u691C\u51FA\u30D1\u30FC\u30C8\n    void\
    \ build_cycles() {\n        vector<int> indegree(N);\n        stack<int> st;\n\
    \        for (int x = 0; x < N; x++) {\n            indegree[x] = f_inv[x].size();\n\
    \            if (indegree[x] == 0) { st.push(x); }\n        }\n\n        vector<bool>\
    \ cycle_flag(N, true);\n\n        while (!st.empty()) {\n            int x = st.top();\n\
    \            st.pop();\n\n            cycle_flag[x] = false;\n            indegree[f[x]]--;\n\
    \            if (indegree[f[x]] == 0) { st.push(f[x]); }\n        }\n\n      \
    \  cycles.clear();\n        cycle_ids.assign(N, -1);\n        cycle_vertex_ids.assign(N,\
    \ -1);\n\n        for (int x = 0; x < N; x++) {\n            if (!cycle_flag[x])\
    \ { continue; }\n\n            int cycle_id = cycles.size();\n\n            vector<int>\
    \ cycle{x};\n            cycle_flag[x] = false;\n            int y = f[x];\n \
    \           while (y != x) {\n                cycle.emplace_back(y);\n       \
    \         cycle_flag[y] = false;\n                y = f[y];\n            }\n\n\
    \            cycles.emplace_back(cycle);\n            for (int j = 0; j < cycle.size();\
    \ j++) {\n                int y = cycle[j];\n                cycle_ids[y] = cycle_id;\n\
    \                cycle_vertex_ids[y] = j;\n            }\n        }\n    }\n\n\
    \    void build_branches() {\n        tree_ids.assign(N, -1);\n        tree_vertex_ids.assign(N,\
    \ -1);\n        tree_depth.assign(N, 0);\n\n        for (int x = 0; x < N; x++)\
    \ {\n            if (cycle_ids[x] == -1) { continue; }\n\n            int tree_id\
    \ = tree_vertices.size();\n            vector<int> tree_vertex{x};\n\n       \
    \     int vertex_id = 0;\n            tree_ids[x] = tree_id;\n            tree_vertex_ids[x]\
    \ = vertex_id;\n\n            stack<int> st;\n            st.push(x);\n\n    \
    \        int max_depth = 0;\n\n            while (!st.empty()) {\n           \
    \     int y = st.top(); st.pop();\n\n                for (int z: f_inv[y]) {\n\
    \                    if (cycle_ids[z] != -1) { continue; }\n\n               \
    \     vertex_id++;\n                    tree_ids[z] = tree_id;\n             \
    \       tree_vertex_ids[z] = vertex_id;\n\n                    tree_depth[z] =\
    \ tree_depth[y] + 1;\n                    chmax(max_depth, tree_depth[z]);\n\n\
    \                    st.push(z);\n                    tree_vertex.emplace_back(z);\n\
    \                }\n            }\n\n            tree_vertices.emplace_back(tree_vertex);\n\
    \            int m = tree_vertex.size();\n            vector<vector<int>> doubling(max<int>(1,\
    \ bit_length(max_depth)), vector<int>(m, -1));\n\n            for (int j = 1;\
    \ j < m; j++) {\n                doubling[0][j] = tree_vertex_ids[f[tree_vertex[j]]];\n\
    \            }\n\n            for (int b = 1; b < max<int>(1, bit_length(max_depth));\
    \ b++) {\n                for (int j = 0; j < m; j++) {\n                    doubling[b][j]\
    \ = doubling[b - 1][doubling[b - 1][j]];\n                }\n            }\n\n\
    \            tree_doubling.emplace_back(doubling);\n        }\n    }\n\n    int\
    \ upper(int x, ll k) {\n        int tree_id = tree_ids[x];\n        int vertex_id\
    \ = tree_vertex_ids[x];\n\n        vector<vector<int>> doubling = tree_doubling[tree_id];\n\
    \        for (int b = 0; k; k >>= 1, b++) {\n            if (k & 1) { vertex_id\
    \ = doubling[b][vertex_id]; }\n        }\n\n        return tree_vertices[tree_id][vertex_id];\n\
    \    }\n\n    int jump_on_cycle(int cycle_id, int vertex_id, ll k) {\n       \
    \ auto &cycle = cycles[cycle_id];\n        int m = cycle.size();\n        k =\
    \ safe_mod(k, m);\n        return cycle[(vertex_id + k) % m];\n    }\n\n    public:\n\
    \    inline int root(int x) const { return tree_vertices[tree_ids[x]][0]; }\n\n\
    \    int calculate(int x, ll k) {\n        if ( k < tree_depth[x]) { return upper(x,\
    \ k); }\n\n        k -= tree_depth[x];\n        x = root(x);\n\n        int cycle_id\
    \ = cycle_ids[x];\n        int vertex_id = cycle_vertex_ids[x];\n        return\
    \ jump_on_cycle(cycle_id, vertex_id, k);\n    }\n\n    vector<vector<int>> &get_cycles()\
    \ { return cycles; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: Functional_Graph/Functional_Graph.hpp
  requiredBy: []
  timestamp: '2025-10-26 11:56:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Functional_Graph.test.cpp
documentation_of: Functional_Graph/Functional_Graph.hpp
layout: document
title: Functional Graph
---

## Outline

Funtional Graph に関する構造の決定及び, 計算を高速に行う.


## Definition

有向グラフ $D = (V, A)$ において, 任意の頂点 $v \in V$ における出次数が $1$ であるとき, この $D$ は Functional Graph であるという.

## Theory

### 写像との対応
$V$ を有限集合とする. このとき, 以下は一対一対応する.

* $V$ を頂点集合とする Functional Graph $D = (V, A)$ .
* 写像 $f: V \to V$.

これらは, それぞれ以下のように対する.

#### Functional Graph から写像

Functional Graph $D = (V, A)$ において, 各頂点 $v \in V$ における唯一ので近傍を $f(v) \in V$ として得られる写像 $f: V \to V$ が対応する.

#### 写像から Functional Graph

写像 $f: V \to V$ に対して, $A$ を

$$A := \left\{ \overrightarrow{v f(v)} ~\middle|~ v \in V \right\}$$

としたときに得られる Functional Graph $D = (V, A)$ が対応する.

### 構造の決定
$D$ におけるそれぞれの弱連結成分 $\Gamma_i$ は次のようにして構成される.

* $\Gamma_i$ にはただ一つのサイクル $v_{i,1}, v_{i,2}, \dots, v_{i,m_i}$ を持つ.
* 各 $v_{i,j}$ について, $v_{i,j}$ を根とする有向根付き木を成す. 有向辺の向きは, 根へ向かう向き.

## Contents

### Constructer

```cpp
Functional_Graph(const vector<int> &f)
```

* 写像 $f$ による Functional Graph を生成する.
* **計算量** : $O(N \log N)$ 時間.

### calculate

```cpp
F.calculate(int x, ll k)
```

* $f^k(x)$ を求める.
* **計算量** : $O(\log N)$ 時間.
  * 厳密には, $f^k(x)$ がサイクル上の頂点ならば $O(1)$ 時間, サイクル上の頂点でなければ $O(\log k)$ 時間.

