---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Functional_Graph/Functional_Graph.hpp
    title: Functional Graph
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/exception.hpp
    title: template/exception.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"verify/original/Functional_Graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <optional>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\
    \n\nusing ll = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B\
    . a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\n\
    template<typename T, typename U>\ninline bool chmax(T &a, const U b){\n    return\
    \ (a < b ? a = b, 1: 0);\n}\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B\
    . a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\n\
    template<typename T, typename U>\ninline bool chmin(T &a, const U b){\n    return\
    \ (a > b ? a = b, 1: 0);\n}\n\n// a \u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\
    \u3059\u308B.\ntemplate<typename T>\ninline T max(const vector<T> &a){\n    if\
    \ (a.empty()) throw invalid_argument(\"vector is empty.\");\n\n    return *max_element(a.begin(),\
    \ a.end());\n}\n\n// vector<T> a \u306E\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\
    \u308B.\ntemplate<typename T>\ninline T min(const vector<T> &a){\n    if (a.empty())\
    \ throw invalid_argument(\"vector is empty.\");\n\n    return *min_element(a.begin(),\
    \ a.end());\n}\n\n// vector<T> a \u306E\u6700\u5927\u5024\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline\
    \ size_t argmax(const vector<T> &a){\n    if (a.empty()) throw std::invalid_argument(\"\
    vector is empty.\");\n\n    return distance(a.begin(), max_element(a.begin(),\
    \ a.end()));\n}\n\n// vector<T> a \u306E\u6700\u5C0F\u5024\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline\
    \ size_t argmin(const vector<T> &a){\n    if (a.empty()) throw invalid_argument(\"\
    vector is empty.\");\n\n    return distance(a.begin(), min_element(a.begin(),\
    \ a.end()));\n}\n#line 61 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
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
    \ b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T\
    \ a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        T q;\n\
    \        tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n    \
    \    tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u\
    \ - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n\
    \    while ((x + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\
    \n    return x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\
    \u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return\
    \ isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\
    \u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x =\
    \ isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line 64 \"template/template.hpp\"\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\nstd::vector<T>\
    \ input_vector(size_t n, size_t offset = 0) {\n    std::vector<T> res;\n    //\
    \ \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\u4FDD\uFF08\
    \u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n   \
    \ // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
    \u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\n    res.assign(offset, T());\n\
    \    \n    for (size_t i = 0; i < n; ++i) {\n        T el;\n        if (!(std::cin\
    \ >> el)) break;\n        res.push_back(std::move(el));\n    }\n    return res;\n\
    }\n#line 67 \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\
    \n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n\
    #define len(x) ll(x.size())\n#define elif else if\n#define unless(cond) if (!(cond))\n\
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
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 70 \"template/template.hpp\"\
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
    \ get_bits(x, bit_length(x)); }\n#line 73 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 2 \"Functional_Graph/Functional_Graph.hpp\"\
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
    \ { return cycles; }\n};\n#line 5 \"verify/original/Functional_Graph.test.cpp\"\
    \n\nvoid verify() {\n    vector<int> f = {77, 0, 39, 33, 1, 87, 20, 88, 75, 49,\
    \ 58, 48, 78, 24, 60, 90, 26, 55, 31, 7, 18, 14, 77, 25, 75, 89, 99, 44, 72, 92,\
    \ 64, 33, 91, 64, 19, 14, 37, 7, 0, 26, 35, 0, 45, 3, 89, 29, 16, 12, 53, 17,\
    \ 8, 91, 97, 60, 65, 42, 3, 4, 48, 72, 57, 61, 74, 75, 2, 76, 67, 21, 91, 15,\
    \ 52, 97, 13, 12, 60, 41, 81, 79, 41, 12, 64, 65, 48, 14, 82, 45, 85, 87, 7, 59,\
    \ 27, 15, 0, 37, 15, 36, 38, 11, 51, 16};\n\n    Functional_Graph F(f);\n\n  \
    \  int n = 100, k_max = 100000;\n    for (int v = 0; v < n; v++) {\n        int\
    \ w = v;\n        for (int k = 0; k <= k_max; k++) {\n            if (F.calculate(v,\
    \ k) == w) {\n                w = f[w];\n                continue;\n         \
    \   } \n\n            cerr << \"Error\" << endl;\n            cerr << \"v = \"\
    \ << v << \", k = \" << k << endl;\n            cerr << \"expect: \" << w << endl;\n\
    \            cerr << \"returns: \" << F.calculate(v, k) << endl;\n           \
    \ assert(false);\n        }\n    }\n}\n\nint main() {\n    verify();\n    cout\
    \ << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include\"../../../library_for_cpp/template/template.hpp\"\n#include\"../../../library_for_cpp/Functional_Graph/Functional_Graph.hpp\"\
    \n\nvoid verify() {\n    vector<int> f = {77, 0, 39, 33, 1, 87, 20, 88, 75, 49,\
    \ 58, 48, 78, 24, 60, 90, 26, 55, 31, 7, 18, 14, 77, 25, 75, 89, 99, 44, 72, 92,\
    \ 64, 33, 91, 64, 19, 14, 37, 7, 0, 26, 35, 0, 45, 3, 89, 29, 16, 12, 53, 17,\
    \ 8, 91, 97, 60, 65, 42, 3, 4, 48, 72, 57, 61, 74, 75, 2, 76, 67, 21, 91, 15,\
    \ 52, 97, 13, 12, 60, 41, 81, 79, 41, 12, 64, 65, 48, 14, 82, 45, 85, 87, 7, 59,\
    \ 27, 15, 0, 37, 15, 36, 38, 11, 51, 16};\n\n    Functional_Graph F(f);\n\n  \
    \  int n = 100, k_max = 100000;\n    for (int v = 0; v < n; v++) {\n        int\
    \ w = v;\n        for (int k = 0; k <= k_max; k++) {\n            if (F.calculate(v,\
    \ k) == w) {\n                w = f[w];\n                continue;\n         \
    \   } \n\n            cerr << \"Error\" << endl;\n            cerr << \"v = \"\
    \ << v << \", k = \" << k << endl;\n            cerr << \"expect: \" << w << endl;\n\
    \            cerr << \"returns: \" << F.calculate(v, k) << endl;\n           \
    \ assert(false);\n        }\n    }\n}\n\nint main() {\n    verify();\n    cout\
    \ << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Functional_Graph/Functional_Graph.hpp
  isVerificationFile: true
  path: verify/original/Functional_Graph.test.cpp
  requiredBy: []
  timestamp: '2026-02-14 19:18:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/original/Functional_Graph.test.cpp
layout: document
redirect_from:
- /verify/verify/original/Functional_Graph.test.cpp
- /verify/verify/original/Functional_Graph.test.cpp.html
title: verify/original/Functional_Graph.test.cpp
---
