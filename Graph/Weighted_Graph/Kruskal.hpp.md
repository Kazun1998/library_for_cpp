---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
    title: Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/Weighted_Graph/Weighted_Graph.hpp
    title: "\u91CD\u307F\u4ED8\u304D\u7121\u5411\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: Union_Find/Union_Find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/exception.hpp
    title: template/exception.hpp
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
    path: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
    title: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Weighted_Graph/Kruskal.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
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
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u6F14\
    \u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) { return x +\
    \ y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return x - y;\
    \ }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x * y; }\n\
    \ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
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
    \ bit_length(x)); }\n#line 71 \"template/template.hpp\"\n\n// exception\n#line\
    \ 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n    private:\n\
    \    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\
    \u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\
    \u305B\u3093.\") {}\n\n    const char* what() const noexcept override {\n    \
    \    return message.c_str();\n    }\n};\n#line 2 \"Graph/Weighted_Graph/Weighted_Graph.hpp\"\
    \n\nnamespace weighted_graph {\n    template<typename W>\n    struct Weighted_Edge\
    \ {\n        int id, source, target;\n        W weight;\n        Weighted_Edge\
    \ *rev;\n\n        Weighted_Edge() = default;\n        Weighted_Edge (int id,\
    \ int source, int target, W weight): id(id), source(source), target(target), weight(weight)\
    \ {}\n    };\n    \n    template<typename W>\n    class Weighted_Graph {\n   \
    \     using Edge = Weighted_Edge<W>;\n\n        private:\n        vector<vector<Edge*>>\
    \ incidences;\n\n        public:\n        int edge_id_offset;\n        vector<Edge*>\
    \ edges, rev_edges;\n\n        /// @brief \u4F4D\u6570\u304C n \u306E\u91CD\u307F\
    \u4ED8\u304D\u7121\u5411\u30B0\u30E9\u30D5\u3092\u751F\u6210\u3059\u308B.\n  \
    \      /// @param n \u4F4D\u6570\n        /// @param edge_id_offset \u8FBA\u306E\
    \ ID \u306E\u30AA\u30D5\u30BB\u30C3\u30C8\n        Weighted_Graph(int n, int edge_id_offset\
    \ = 0): edge_id_offset(edge_id_offset), incidences(n), edges(edge_id_offset),\
    \ rev_edges(edge_id_offset) {}\n\n        ~Weighted_Graph() {\n            for\
    \ (Edge* edge: edges) {\n                if (edge != nullptr) { delete edge; }\n\
    \            }\n\n            for (Edge* rev_edge: rev_edges) {\n            \
    \    if (rev_edge != nullptr) { delete rev_edge; }\n            }\n        }\n\
    \n        /// @brief \u4F4D\u6570 (\u9802\u70B9\u306E\u6570) \u3092\u6C42\u3081\
    \u308B\n        inline int order() const { return int(incidences.size()); }\n\n\
    \        /// @brief \u30B5\u30A4\u30BA (\u8FBA\u306E\u6570) \u3092\u6C42\u3081\
    \u308B\n        inline int size() const { return int(edges.size()) - edge_id_offset;\
    \ }\n\n\n        /// @brief \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\
    \u91CD\u307F w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B.\n        /// @param\
    \ u \u9802\u70B9 1\n        /// @param v \u9802\u70B9 2\n        /// @param w\
    \ \u91CD\u307F\n        /// @return \u8FFD\u52A0\u3057\u305F\u8FBA\u306E ID\n\
    \        int add_edge(int u, int v, W w){\n            int id = int(edges.size());\n\
    \n            Edge* edge = new Edge(id, u, v, w);\n            Edge* rev_edge\
    \ = new Edge(id, v, u, w);\n\n            edge->rev = rev_edge;\n            rev_edge->rev\
    \ = edge;\n\n            incidences[u].emplace_back(edge);\n            incidences[v].emplace_back(rev_edge);\n\
    \n            edges.emplace_back(edge);\n            rev_edges.emplace_back(rev_edge);\n\
    \n            return id;\n        }\n\n        /// @brief \u9802\u70B9 u \u306B\
    \u63A5\u7D9A\u3059\u308B\u8FBA (\u30A2\u30C9\u30EC\u30B9) \u306E\u30EA\u30B9\u30C8\
    \u3092\u6C42\u3081\u308B.\n        /// @param u \n        inline const vector<Edge*>&\
    \ incidence (int u) const { return incidences[u]; }\n\n        /// @brief \u8FBA\
    \ ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n     \
    \   /// @param id\n        inline const Edge* get_edge(int id) const { return\
    \ edges[id]; }\n\n        /// @brief \u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\
    \u3092\u53D6\u5F97\u3059\u308B.\n        /// @param id\n        inline Edge* get_edge(int\
    \ id) { return edges[id]; }\n    };\n}\n#line 2 \"Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp\"\
    \n\n#line 4 \"Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp\"\n\nnamespace weighted_graph\
    \ {\n    template<typename W>\n    struct Minimum_Spanning_Tree {\n        vector<Weighted_Edge<W>*>\
    \ edges;\n        W weight;\n    };\n}\n#line 2 \"Union_Find/Union_Find.hpp\"\n\
    \nclass Union_Find{\n    private:\n    int N;\n    vector<int> data;\n    int\
    \ _group_number;\n\n    public:\n    Union_Find(int N) : N(N), data(N, -1), _group_number(N)\
    \ {}\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306E\u4EE3\u8868\u5143\u3092\u6C42\
    \u3081\u308B.\n    int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]);\
    \ }\n\n    // \u9802\u70B9\u3092 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_vertex()\
    \ {\n      data.emplace_back(-1);\n      N++;\n      _group_number++;\n\n    \
    \  return N - 1;\n    }\n\n    // \u9802\u70B9\u3092 k \u500B\u8FFD\u52A0\u3059\
    \u308B.\n    vector<int> add_vertices(int k) {\n      vector<int> ids;\n     \
    \ for (; k; k--) { ids.emplace_back(add_vertex()); }\n\n      return ids;\n  \
    \  }\n\n    // x \u3068 y \u3092\u7D50\u5408\u3059\u308B.\n    // force \u3092\
    \ true \u306B\u3059\u308B\u3068, \u5FC5\u305A find(x) \u304C\u6839\u306B\u306A\
    \u308B\u3088\u3046\u306B\u7D50\u5408\u3059\u308B.\n    // \u8FD4\u308A\u5024:\
    \ \u5143\u3005\u975E\u9023\u7D50\u306A\u3089\u3070 true, \u9023\u7D50\u306A\u3089\
    \u3070 false\n    bool unite(int x, int y, bool force = false) {\n        x =\
    \ find(x);\n        y = find(y);\n\n        if (x == y) { return false; }\n\n\
    \        if (!force && (data[x] > data[y])) { swap(x, y); }\n\n        data[x]\
    \ += data[y];\n        data[y] = x;\n\n        _group_number--;\n\n        return\
    \ true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\u304A\u3051\u308B\
    \u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) { return -data[find(x)];\
    \ }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\
    ?\n    int same(int x, int y) { return find(x) == find(y); }\n\n    // \u9023\u7D50\
    \u6210\u5206\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int group_count()\
    \ const { return _group_number; }\n};\n#line 7 \"Graph/Weighted_Graph/Kruskal.hpp\"\
    \n\nnamespace weighted_graph {\n    template<typename W>\n    Minimum_Spanning_Tree<W>\
    \ Kruskal(const Weighted_Graph<W> &G) {\n        using Edge = Weighted_Edge<W>;\n\
    \n        Union_Find U(G.order());\n        vector<Edge*> edges;\n        for\
    \ (Edge* edge: G.edges) {\n            if (edge != nullptr) { edges.emplace_back(edge);\
    \ }\n        }\n\n        vector<Edge*> tree_edges;\n        W tree_weight = 0;\n\
    \n        sort(edges.begin(), edges.end(), [](const Edge* e, const Edge* f) {\
    \ return e->weight < f->weight; } );\n\n        for (auto edge: edges) {\n   \
    \         if (!U.unite(edge->source, edge->target)) { continue; }\n\n        \
    \    tree_edges.emplace_back(edge);\n            tree_weight += edge->weight;\n\
    \        }\n\n        return Minimum_Spanning_Tree<W> { tree_edges, tree_weight\
    \ };\n    }\n}\n"
  code: "#pragma once\n\n#include\"../../template/template.hpp\"\n#include\"Weighted_Graph.hpp\"\
    \n#include\"Minimum_Spanning_Tree.hpp\"\n#include\"../../Union_Find/Union_Find.hpp\"\
    \n\nnamespace weighted_graph {\n    template<typename W>\n    Minimum_Spanning_Tree<W>\
    \ Kruskal(const Weighted_Graph<W> &G) {\n        using Edge = Weighted_Edge<W>;\n\
    \n        Union_Find U(G.order());\n        vector<Edge*> edges;\n        for\
    \ (Edge* edge: G.edges) {\n            if (edge != nullptr) { edges.emplace_back(edge);\
    \ }\n        }\n\n        vector<Edge*> tree_edges;\n        W tree_weight = 0;\n\
    \n        sort(edges.begin(), edges.end(), [](const Edge* e, const Edge* f) {\
    \ return e->weight < f->weight; } );\n\n        for (auto edge: edges) {\n   \
    \         if (!U.unite(edge->source, edge->target)) { continue; }\n\n        \
    \    tree_edges.emplace_back(edge);\n            tree_weight += edge->weight;\n\
    \        }\n\n        return Minimum_Spanning_Tree<W> { tree_edges, tree_weight\
    \ };\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Graph/Weighted_Graph/Weighted_Graph.hpp
  - Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
  - Union_Find/Union_Find.hpp
  isVerificationFile: false
  path: Graph/Weighted_Graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2026-01-01 02:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
documentation_of: Graph/Weighted_Graph/Kruskal.hpp
layout: document
title: "Kruskal \u6CD5"
---

## Outline

重み付き無向グラフ $G$ の最小全域木 $T$ を Kruskal 法で求める.

## History

|日付|内容|
|:---:|:---|
|2025/11/25|Kruskal 法の実装|
