---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/Bitwise_Or_Convolution.hpp
    title: Convolution/Bitwise_Or_Convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Convolution/Convolution_Base.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: Convolution/Semilattice_Convolution_Base.hpp
    title: "\u6DFB\u5B57\u304C\u534A\u675F\u3067\u3042\u308B\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: Graph/Graph/Graph.hpp
    title: "\u7121\u5411 Graph"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Chromatic_Number.test.cpp
    title: verify/yosupo_library_checker/graph/Chromatic_Number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Graph/Chromatic_Number.hpp\"\n\n#line 2 \"Graph/Graph/Graph.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
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
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<integral\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<integral\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<integral\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T, integral U>\nauto div_floor(T x, U y){\n    return x /\
    \ y - ((x % y != 0) && ((x < 0) != (y < 0)));\n}\n\n// ceil(x / y) \u3092\u6C42\
    \u3081\u308B.\ntemplate<integral T, integral U>\nauto div_ceil(T x, U y){\n  \
    \  return x / y + ((x % y != 0) && ((x < 0) == (y < 0)));\n}\n\n// x \u3092 y\
    \ \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<integral\
    \ T, integral U>\nauto safe_mod(T x, U y){\n    auto q = div_floor(x, y);\n  \
    \  return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<integral T, integral U>\nauto\
    \ divmod(T x, U y){\n    auto q = div_floor(x, y);\n    return make_pair(q, x\
    \ - q * y);\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<integral\
    \ T, integral U>\nauto round(T x, U y){\n    auto [q, r] = divmod(x, y);\n   \
    \ if (y < 0) return (r <= div_floor(y, 2)) ? q + 1 : q;\n    return (r >= div_ceil(y,\
    \ 2)) ? q + 1 : q;\n}\n\n// \u5947\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B.\ntemplate<integral T>\nbool is_odd(const T &x) { return x % 2 != 0; }\n\
    \n// \u5076\u6570\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<integral\
    \ T>\nbool is_even(const T &x) { return x % 2 == 0; }\n\n// m \u306E\u500D\u6570\
    \u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<integral T, integral\
    \ U>\nbool is_multiple(const T &x, const U &m) { return x % m == 0; }\n\n// \u6B63\
    \u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool\
    \ is_positive(const T &x) { return x > 0; }\n\n// \u8CA0\u304B\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool is_negative(const T &x)\
    \ { return x < 0; }\n\n// \u30BC\u30ED\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\
    \u308B.\ntemplate<typename T>\nbool is_zero(const T &x) { return x == 0; }\n\n\
    // \u975E\u8CA0\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename\
    \ T>\nbool is_non_negative(const T &x) { return x >= 0; }\n\n// \u975E\u6B63\u304B\
    \u3069\u3046\u304B\u5224\u5B9A\u3059\u308B.\ntemplate<typename T>\nbool is_non_positive(const\
    \ T &x) { return x <= 0; }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\
    \n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\nll pow(ll x, ll y) { return intpow(x,\
    \ y); }\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, integral U>\nT modpow(T x, U y, T z)\
    \ {\n    T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\ntemplate<typename\
    \ T>\nT sum(const vector<T> &X) {\n    T y = T(0);\n    for (auto &&x: X) { y\
    \ += x; }\n    return y;\n}\n\ntemplate<typename T>\nT gcd(const T x, const T\
    \ y) {\n    return y == 0 ? x : gcd(y, x % y);\n}\n\n// a x + b y = gcd(a, b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\u3057\u3066\
    , (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T,\
    \ T, T> Extended_Euclid(T a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while\
    \ (b) {\n        auto [q, r] = divmod(a, b);\n        a = b;\n        b = r;\n\
    \        tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v,\
    \ u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrtl(N);\n\
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
    \ get_bits(x, bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\
    \u3093\u304B\u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\
    \u529B\u3059\u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x));\
    \ }\n#line 73 \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 4 \"Graph/Graph/Graph.hpp\"\n\nnamespace graph {\n    struct\
    \ Edge {\n        int id, source, target;\n        Edge *rev;\n\n        Edge()\
    \ = default;\n        Edge(int id, int source, int target): id(id), source(source),\
    \ target(target), rev(nullptr) {}\n    };\n\n    class Graph {\n        private:\n\
    \        vector<vector<Edge*>> incidences;\n        vector<Edge> edges, rev_edges;\n\
    \        vector<int> deg;\n\n        public:\n        int edge_id_offset;\n\n\
    \        public:\n        Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset),\
    \ deg(n, 0) {\n            incidences.assign(n, {});\n            edges.resize(edge_id_offset,\
    \ Edge());\n        }\n\n        /// @brief \u3053\u306E\u30B0\u30E9\u30D5\u306E\
    \u4F4D\u6570 (\u9802\u70B9\u6570) \u3092\u6C42\u3081\u308B.\n        inline int\
    \ order() const { return int(incidences.size()); }\n\n        /// @brief \u3053\
    \u306E\u30B0\u30E9\u30D5\u306E\u30B5\u30A4\u30BA (\u8FBA\u6570) \u3092\u6C42\u3081\
    \u308B.\n        inline int size() const { return int(edges.size()) - edge_id_offset;\
    \ }\n\n        /// @brief \u8FBA uv \u3092\u52A0\u3048\u308B.\n        int add_edge(int\
    \ u, int v) {\n            int id = int(edges.size());\n\n            Edge* edge\
    \ = new Edge(id, u, v);\n            Edge* rev_edge = new Edge(id, v, u);\n\n\
    \            edge->rev = rev_edge;\n            rev_edge->rev = edge;\n\n    \
    \        incidences[u].emplace_back(edge);\n            incidences[v].emplace_back(rev_edge);\n\
    \            edges.emplace_back(*edge);\n\n            deg[u]++;\n           \
    \ deg[v]++;\n\n            return id;\n        }\n\n        /// @brief \u9802\u70B9\
    \ u \u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u306E\u30A2\u30C9\u30EC\u30B9\u4E00\u89A7\
    \u3092\u53D6\u5F97\u3059\u308B.\n        const vector<Edge*>& incidence (int u)\
    \ const { return incidences[u]; }\n\n        // \u8FBA ID \u304C id \u3067\u3042\
    \u308A, source \u304C u \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B\
    .\n        inline const Edge& get_edge(int id) const { return edges[id]; }\n\n\
    \        // \u8FBA ID \u304C id \u3067\u3042\u308A, source \u304C u \u3067\u3042\
    \u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n        inline Edge& get_edge(int\
    \ id) { return edges[id]; }\n\n        /// @brief \u9802\u70B9 v \u306E\u6B21\u6570\
    \u3092\u6C42\u3081\u308B\n        inline int degree(const int v) const { return\
    \ deg[v]; }\n\n        vector<vector<int>> adjacency_matrix() const {\n      \
    \      vector<vector<int>> matrix(order(), vector<int>(order(), 0));\n       \
    \     for (int j = edge_id_offset; j < edge_id_offset + size(); ++j) {\n     \
    \           Edge edge = edges[j];\n                matrix[edge.source][edge.target]++;\n\
    \                matrix[edge.target][edge.source]++;\n            }\n\n      \
    \      return matrix;\n        }\n\n        vector<vector<int>> degree_matrix()\
    \ const {\n            vector<vector<int>> matrix(order(), vector<int>(order(),\
    \ 0));\n            for (int i = 0; i < order(); ++i) matrix[i][i] = degree(i);\n\
    \            return matrix;\n        }\n\n        vector<vector<int>> laplacian_matrix()\
    \ const {\n            const vector<vector<int>> D = degree_matrix(), A = adjacency_matrix();\n\
    \            vector<vector<int>> L(order(), vector<int>(order()));\n         \
    \   for (int i = 0; i < order(); ++i) {\n                for (int j = 0; j < order();\
    \ ++j) {\n                    L[i][j] = D[i][j] - A[i][j];\n                }\n\
    \            }\n\n            return L;\n        }\n    };\n}\n#line 2 \"Convolution/Bitwise_Or_Convolution.hpp\"\
    \n\n#line 2 \"Convolution/Semilattice_Convolution_Base.hpp\"\n\n#line 2 \"Convolution/Convolution_Base.hpp\"\
    \n\n#line 4 \"Convolution/Convolution_Base.hpp\"\n\nnamespace convolution {\n\
    \    template<typename R>\n    class Convolution_Base {\n        protected:\n\
    \        std::vector<R> data;\n\n        public:\n        Convolution_Base() =\
    \ default;\n        Convolution_Base(std::vector<R> data_in): data(std::move(data_in))\
    \ {}\n\n        Convolution_Base(initializer_list<R> init): data(init) {}\n  \
    \      \n        Convolution_Base(size_t n): data(std::vector<R>(n)) {} \n   \
    \     \n        Convolution_Base& operator=(initializer_list<R> init) {\n    \
    \        data = init;\n            return *this;\n        }\n\n        // \u52A0\
    \u6CD5 (+=)\n        Convolution_Base& operator+=(const Convolution_Base<R> &B)\
    \ {\n            if(data.size() != B.data.size()) { throw std::length_error(\"\
    Convolution operands must have the same size.\"); }\n\n            for (size_t\
    \ i = 0; i < data.size(); i++) { data[i] += B.data[i]; }\n            return *this;\n\
    \        }\n\n        // \u6E1B\u6CD5 (-=)\n        Convolution_Base& operator-=(const\
    \ Convolution_Base<R> &B) {\n            if(data.size() != B.data.size()) { throw\
    \ std::length_error(\"Convolution operands must have the same size.\"); }\n  \
    \          for (size_t i = 0; i < data.size(); i++) { data[i] -= B.data[i]; }\n\
    \            return *this;\n        }\n\n        // \u30B9\u30AB\u30E9\u30FC\u500D\
    \ (*=)\n        Convolution_Base& operator*=(const R &a) {\n            for (size_t\
    \ i = 0; i < data.size(); i++) { data[i] *= a; }\n            return *this;\n\
    \        }\n\n        virtual Convolution_Base<R>& operator*=(const Convolution_Base<R>\
    \ &B) = 0;\n\n        inline size_t size() const { return data.size(); }\n\n \
    \       inline R& operator[](size_t k) { return data[k]; }\n        inline const\
    \ R& operator[](size_t k) const { return data[k]; }\n\n        const std::vector<R>&\
    \ to_vector() const { return data; }\n    };\n}\n#line 4 \"Convolution/Semilattice_Convolution_Base.hpp\"\
    \n\nnamespace convolution {\n    template<typename R>\n    class Semilattice_Convolution_Base:\
    \ public Convolution_Base<R> {\n        // \u578B\u30A8\u30A4\u30EA\u30A2\u30B9\
    \n        using Base = Convolution_Base<R>;\n        using Self = Semilattice_Convolution_Base<R>;\n\
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
    \    }\n\n        Self& pow(long long n) {\n            zeta();\n            for\
    \ (R &v : this->data) { v = ::pow(v, n); }\n            mobius();\n          \
    \  return *this;\n        }\n\n        void zeta() { zeta_transform(this->data);\
    \ }\n        void mobius() { mobius_transform(this->data); }\n    };\n\n    template<typename\
    \ T>\n    T pow(T a, const ll n) {\n        a.pow(n);\n        return a;\n   \
    \ }\n}\n#line 4 \"Convolution/Bitwise_Or_Convolution.hpp\"\n\nnamespace convolution\
    \ {\n    template<typename R>\n    class Bitwise_Or_Convolution: public Semilattice_Convolution_Base<R>\
    \ {\n        using Base = Convolution_Base<R>;\n        using ImplBase = Semilattice_Convolution_Base<R>;\n\
    \        using ImplBase::ImplBase;\n\n        // \u52A0\u6CD5 (+)\n        friend\
    \ Bitwise_Or_Convolution operator+(const Bitwise_Or_Convolution &lhs, const Bitwise_Or_Convolution\
    \ &rhs) {\n            Bitwise_Or_Convolution temp(lhs);\n            temp +=\
    \ rhs;\n            return temp;\n        }\n\n        // \u6E1B\u6CD5 (-)\n \
    \       friend Bitwise_Or_Convolution operator-(const Bitwise_Or_Convolution &lhs,\
    \ const Bitwise_Or_Convolution &rhs) {\n            Bitwise_Or_Convolution temp(lhs);\n\
    \            temp -= rhs;\n            return temp;\n        }\n\n        // \u4E57\
    \u6CD5 (*)\n        friend Bitwise_Or_Convolution operator*(const Bitwise_Or_Convolution\
    \ &lhs, const Bitwise_Or_Convolution &rhs) { \n            Bitwise_Or_Convolution\
    \ temp(lhs);\n            temp *= rhs;\n            return temp;\n        }\n\n\
    \        // \u30B9\u30AB\u30E9\u30FC\u500D (a * rhs)\n        friend Bitwise_Or_Convolution\
    \ operator*(const R &a, const Bitwise_Or_Convolution &rhs) {\n            Bitwise_Or_Convolution\
    \ temp(rhs);\n            temp *= a;\n            return temp;\n        }\n\n\
    \        // \u30B9\u30AB\u30E9\u30FC\u500D (lhs * a)\n        friend Bitwise_Or_Convolution\
    \ operator*(const Bitwise_Or_Convolution &lhs, const R &a) {\n            Bitwise_Or_Convolution\
    \ temp(lhs);\n            temp *= a;\n            return temp;\n        }\n\n\
    \        void zeta_transform(std::vector<R> &f) const override {\n           \
    \ int m = floor_log2(f.size());\n\n            for (size_t i = 0; i < m; i++)\
    \ {\n                for (int S = 0; S < (1 << m); S++) {\n                  \
    \  if (!get_bit(S, i)) { continue; }\n\n                    f[S] += f[S ^ (1 <<\
    \ i)];\n                }\n            }\n        }\n\n        void mobius_transform(std::vector<R>\
    \ &g) const override {\n            int m = floor_log2(g.size());\n\n        \
    \    for (size_t i = 0; i < m; i++) {\n                for (int S = 0; S < (1\
    \ << m); S++) {\n                    if (!get_bit(S, i)) { continue; }\n\n   \
    \                 g[S] -= g[S ^ (1 << i)];\n                }\n            }\n\
    \        }\n    };\n}\n#line 5 \"Graph/Graph/Chromatic_Number.hpp\"\n\nnamespace\
    \ graph {\n    int Chromatic_Number(const Graph &G) {\n        int n = G.order();\n\
    \        if (n == 0) return 0;\n\n        using namespace convolution;\n     \
    \   using Conv = Bitwise_Or_Convolution<long long>;\n\n        vector<int> adj_mask(n,\
    \ 0);\n        for (int i = 0; i < n; ++i) {\n            for (auto edge : G.incidence(i))\
    \ {\n                adj_mask[i] |= (1 << edge->target);\n            }\n    \
    \    }\n\n        // Section I: \u72EC\u7ACB\u96C6\u5408\u306E\u5224\u5B9A (S\
    \ \u304C\u72EC\u7ACB\u96C6\u5408\u306A\u3089 1, \u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070 0)\n        vector<long long> indep_vec(1 << n, 0);\n        indep_vec[0]\
    \ = 1;\n        for (int S = 1; S < (1 << n); ++S) {\n            int x = lowest_bit(S);\n\
    \            int prev = S ^ (1 << x);\n            if (indep_vec[prev] && !(adj_mask[x]\
    \ & prev)) indep_vec[S] = 1;\n        }\n\n        if (indep_vec[(1 << n) - 1])\
    \ return 1;\n        Conv indep(indep_vec);\n\n        auto clamp = [&](Conv &c)\
    \ {\n            for (int S = 0; S < (1 << n); ++S) c[S] = (c[S] > 0);\n     \
    \   };\n\n        // Section II: k = 2, 4, 8, ... \u306B\u5BFE\u3057\u3066\u30C0\
    \u30D6\u30EA\u30F3\u30B0\n        vector<Conv> dp_pow2;\n        dp_pow2.push_back(indep);\n\
    \        int k = 0;\n        while ((1 << (k + 1)) <= n) {\n            Conv next\
    \ = dp_pow2.back() * dp_pow2.back();\n            clamp(next);\n            if\
    \ (next[(1 << n) - 1]) break;\n            dp_pow2.push_back(next);\n        \
    \    k++;\n        }\n\n        // Section III: \u4E8C\u5206\u63A2\u7D22\u306B\
    \u3088\u3063\u3066\u5F69\u8272\u6570\u3092\u6C42\u3081\u308B\n        int current_k\
    \ = (1 << k);\n        Conv current_dp = dp_pow2.back();\n        for (int i =\
    \ k - 1; i >= 0; --i) {\n            if (current_k + (1 << i) > n) continue;\n\
    \            Conv res = current_dp * dp_pow2[i];\n            clamp(res);\n  \
    \          unless (res[(1 << n) - 1]) {\n                current_k += (1 << i);\n\
    \                current_dp = res;\n            }\n        }\n\n        return\
    \ current_k + 1;\n    }\n}\n"
  code: "#pragma once\n\n#include \"Graph.hpp\"\n#include \"../../Convolution/Bitwise_Or_Convolution.hpp\"\
    \n\nnamespace graph {\n    int Chromatic_Number(const Graph &G) {\n        int\
    \ n = G.order();\n        if (n == 0) return 0;\n\n        using namespace convolution;\n\
    \        using Conv = Bitwise_Or_Convolution<long long>;\n\n        vector<int>\
    \ adj_mask(n, 0);\n        for (int i = 0; i < n; ++i) {\n            for (auto\
    \ edge : G.incidence(i)) {\n                adj_mask[i] |= (1 << edge->target);\n\
    \            }\n        }\n\n        // Section I: \u72EC\u7ACB\u96C6\u5408\u306E\
    \u5224\u5B9A (S \u304C\u72EC\u7ACB\u96C6\u5408\u306A\u3089 1, \u305D\u3046\u3067\
    \u306A\u3051\u308C\u3070 0)\n        vector<long long> indep_vec(1 << n, 0);\n\
    \        indep_vec[0] = 1;\n        for (int S = 1; S < (1 << n); ++S) {\n   \
    \         int x = lowest_bit(S);\n            int prev = S ^ (1 << x);\n     \
    \       if (indep_vec[prev] && !(adj_mask[x] & prev)) indep_vec[S] = 1;\n    \
    \    }\n\n        if (indep_vec[(1 << n) - 1]) return 1;\n        Conv indep(indep_vec);\n\
    \n        auto clamp = [&](Conv &c) {\n            for (int S = 0; S < (1 << n);\
    \ ++S) c[S] = (c[S] > 0);\n        };\n\n        // Section II: k = 2, 4, 8, ...\
    \ \u306B\u5BFE\u3057\u3066\u30C0\u30D6\u30EA\u30F3\u30B0\n        vector<Conv>\
    \ dp_pow2;\n        dp_pow2.push_back(indep);\n        int k = 0;\n        while\
    \ ((1 << (k + 1)) <= n) {\n            Conv next = dp_pow2.back() * dp_pow2.back();\n\
    \            clamp(next);\n            if (next[(1 << n) - 1]) break;\n      \
    \      dp_pow2.push_back(next);\n            k++;\n        }\n\n        // Section\
    \ III: \u4E8C\u5206\u63A2\u7D22\u306B\u3088\u3063\u3066\u5F69\u8272\u6570\u3092\
    \u6C42\u3081\u308B\n        int current_k = (1 << k);\n        Conv current_dp\
    \ = dp_pow2.back();\n        for (int i = k - 1; i >= 0; --i) {\n            if\
    \ (current_k + (1 << i) > n) continue;\n            Conv res = current_dp * dp_pow2[i];\n\
    \            clamp(res);\n            unless (res[(1 << n) - 1]) {\n         \
    \       current_k += (1 << i);\n                current_dp = res;\n          \
    \  }\n        }\n\n        return current_k + 1;\n    }\n}\n"
  dependsOn:
  - Graph/Graph/Graph.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Convolution/Bitwise_Or_Convolution.hpp
  - Convolution/Semilattice_Convolution_Base.hpp
  - Convolution/Convolution_Base.hpp
  isVerificationFile: false
  path: Graph/Graph/Chromatic_Number.hpp
  requiredBy: []
  timestamp: '2026-04-13 12:08:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/graph/Chromatic_Number.test.cpp
documentation_of: Graph/Graph/Chromatic_Number.hpp
layout: document
title: "\u5F69\u8272\u6570"
---

## Outline

無向グラフ $G = (V, E)$ における彩色数 $\chi(G)$ を求める.

## Definition

$G = (V, E)$ を自己ループを持たない無向グラフとする.

* $C$ を色の集合とする. $C$ が $k$ 要素であり, 以下をみたす時, $G$ は $k$ 彩色可能であるという.
  * $c: V \to C$ が存在して, 任意の $u, v \in V$ に対して, $u, v$ が隣接しているならば, $c(u) \neq c(v)$ である.
* グラフ $G$ の彩色に必要な最小の色数を $G$ の彩色数といい, $\chi(G)$ と書く.

## Theory

### 分割問題への帰着

自己ループを持たない無向グラフ $G = (V, E)$ において, $I \subset V$ について以下が成り立つ時, $I$ は独立集合であるという.

* 任意の $uv \in E$ に対して, $u \not \in I$ または $v \not \in I$ が成り立つ.

このとき, 以下は同値である.

* (a) $G$ は $k$ 彩色可能である.
* (b) $G$ の独立集合 $I_1, \dots, I_k$ であって, $I_1, \dots, I_k$ が $V$ の分割になるものが存在する.

#### 証明

##### (a) ならば (b)

$C = \{C_1, \dots, C_k \}$ とする. $I_a := c^{-1}(\{C_a\})$ とすると, 以下が成り立つ.

* $a \neq b$ ならば, $\{C_a\} \cap \{C_b\} = \emptyset$ である. 故に, $I_a \cap I_b = c^{-1}(\{C_a\}) \cap c^{-1}(\{C_a\}) = c^{-1}(\{C_a\} \cap \{C_b\}) = c^{-1}(\emptyset) = \emptyset$ である.
* $I_1 \cup \dots \cup I_k = c^{-1}(\{C_1\}) \cup \dots c^{-1}(\{C_k\}) = c^{-1}(\{C_1\} \cup \dots \{C_k\}) = c^{-1}(\{C_1, \dots, C_k\}) = c^{-1}(C) = V$ になる.

以上から, $I_1, \dots, I_k$ は $V$ の分割である.

##### (b) ならば (a)

各 $v \in V$ に対して, $c(v) = C_a \iff v \in I_a$ で定める.

* $I_1, \dots, I_k$ が $V$ の独立なので, $v \in I_a$ となる $a$ がただ一つ存在する. よって, $c$ は写像になる.
* $uv \in E$ に対して, $c(u) = C_a$ とする. つまり, $u \in I_a$ とする. このとき, $v \in I_a$ としてしまうと, $I_a$ が独立集合にならない. 故に, $v \not \in I_a$ である. よって, $c(v) \neq C_a$ である.
* $c(V) \subset \{C_1, \dots, C_k\}$ である.

よって, $c$ が $k$ 彩色になる.

### 問題の緩和

故に, 独立集合による分割のパーツの最小個数を求める問題に帰着することが出来た.

分割という問題より, 互いに素の要素を除いた和集合に関する問題に帰着する方が楽なので, 和集合バージョンに帰着させる.

以下は同値になる.

* (a) $G$ は $k$ 彩色可能である.
* (c) $G$ の独立集合 $I_1, \dots, I_k$ であって, $I_1 \cup \dots \cup I_k = V$ となるものが存在する.

#### 証明

(a), (b) の同値性を示したことを利用して, (b), (c) の同値性を証明する.

##### (b) ならば (c)

$I_1, \dots, I_k$ が分割であった. 分割の条件に $I_1 \cup \dots I_k = V$ が含まれている.

##### (c) ならば (b)

次のようにして $J_1, \dots, J_k$ を定める.

* $J_1 := I_1$.
* $J_2 := I_2 \setminus J_1$.
* $\dots$
* $J_a := I_a \setminus J_{a-1}$.
* $\dots$

このようにすると, $J_1, \dots, J_k$ が $V$ の分割になる.

### アルゴリズムの構築

(a), (c) の特徴づけにより, 独立集合の和集合が $V$ に一致させる問題に帰着された.

要するに, 以下の問題を解けば良くなった.

* 以下を満たす最小の正の整数 $k$ を求めよ: 独立集合 $I_1, \dots, I_k$ に対して, $I_1 \cup \dots \cup I_k = V$.

これは, 以下を利用することで解くことができる. なお, $G$ の位数を $N$ とする.

* $\mathcal{I}$ を $G$ の独立集合の族とする.
* $V$ の冪集合族 $\mathcal{P}(V)$ を $\cup$ を演算とするモノイドとする.
* モノイド環 $P \in \Z[\mathcal{P}(V)]$ を以下で定める. ただし, $I \in \mathcal{I}$.
  * $P(I) := \begin{cases} 1 & (I \in \mathcal{I}) \\ 0 & (I \not \in \mathcal{I}) \end{cases}$.
* このとき, 非負整数 $k$ に対して, $P^k(V)$ は $k$ 彩色の組み合わせの数になる. 故に, 以下が同値になる.
  * $G$ は $k$ 彩色可能である.
  * $P^k(V) > 0$.
* よって, $P^k(V)$ が非零になる最小の $k$ を求める問題に帰着される.
  * $\mathcal{P}(V)$ は冪等モノイドである. そのため, $P^k$ の計算は [Bitwise Or に関する畳み込み](../../Convolution/Bitwise_Or_Convolution.hpp) を利用できる.
  * $k$ の求め方としては以下がある.
    * (1) $k = 1, 2, \dots, N$ の順に判定する.
    * (2) まず, 自乗を求めることで, $k = 1, 2, 4, 8, \dots$ の順に求めた後, 二分探索で求める.

Bitwise Or の計算量は (1) だと $O(N^2 2^N)$ 時間, (2) だと $O(N 2^N \log N)$ 時間になる.

## Contents

```cpp
Chromatic_Number(const Graph &G)
```

* 無向グラフ $G = (V, E)$ の彩色数 $\chi(G)$ を求める.
* **引数**
  * $G$ : 無向グラフ
* **計算量** : $G$ の位数とサイズを $N$ として, $O(N 2^N \log N)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/04/13| Chromatic_Number 実装 |
