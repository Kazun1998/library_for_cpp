---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Digraph.hpp
    title: "\u6709\u5411 Graph"
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Eulerian_Trail.hpp
    title: "\u6709\u5411 Graph \u306B\u304A\u3051\u308B Eulerian Trail"
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Path.hpp
    title: Graph/Digraph/Path.hpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eulerian_trail_directed
    links:
    - https://judge.yosupo.jp/problem/eulerian_trail_directed
  bundledCode: "#line 1 \"verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\n\
    \n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
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
    \ y; }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
    \ T>\nT bitwise_and(const T &x, const T &y) { return x & y; }\n\ntemplate<typename\
    \ T>\nT bitwise_or(const T &x, const T &y) { return x | y; }\n\ntemplate<typename\
    \ T>\nT bitwise_xor(const T &x, const T &y) { return x ^ y; }\n\n// \u9664\u7B97\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nauto div_floor(T x, U y){\n    return x /\
    \ y - ((x % y != 0) && ((x < 0) != (y < 0)));\n}\n\n// ceil(x / y) \u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nauto div_ceil(T x, U y){\n  \
    \  return x / y + ((x % y != 0) && ((x < 0) == (y < 0)));\n}\n\n// x \u3092 y\
    \ \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nauto safe_mod(T x, U y){\n    auto q = div_floor(x, y);\n  \
    \  return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\
    \u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nauto\
    \ divmod(T x, U y){\n    auto q = div_floor(x, y);\n    return make_pair(q, x\
    \ - q * y);\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nauto round(T x, U y){\n    auto [q, r] = divmod(x, y);\n   \
    \ if (y < 0) return (r <= div_floor(y, 2)) ? q + 1 : q;\n    return (r >= div_ceil(y,\
    \ 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\
    \n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll\
    \ a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n  \
    \      y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y,\
    \ ll z){\n    ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E\
    \ y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n\
    \    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %=\
    \ z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\ntemplate<typename T>\nT sum(const\
    \ vector<T> &X) {\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return\
    \ y;\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\
    \u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T a, T b) {\n    T s =\
    \ 1, t = 0, u = 0, v = 1;\n    while (b) {\n        T q;\n        tie(q, a, b)\
    \ = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n        tie(s, t) = make_pair(t,\
    \ s - q * t);\n        tie(u, v) = make_pair(v, u - q * v);\n    }\n\n    return\
    \ make_tuple(s, u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0\
    \ \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n\
    \    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n    while ((x + 1) * (x\
    \ + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\n    return x;\n}\n\n\
    // floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0\
    \ \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return isqrt(N); }\n\n//\
    \ ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\
    \u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x = isqrt(N);\n    return\
    \ x * x == N ? x : x + 1;\n}\n#line 64 \"template/template.hpp\"\n\n// inout\n\
    #line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class... T>\n\
    void input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\
    \ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n  \
    \  cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\\n\";\n\
    }\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
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
    \ {\n        return message.c_str();\n    }\n};\n#line 2 \"Graph/Digraph/Eulerian_Trail.hpp\"\
    \n\n#line 2 \"Graph/Digraph/Digraph.hpp\"\n\n#line 4 \"Graph/Digraph/Digraph.hpp\"\
    \n\nnamespace digraph {\n    struct Arc {\n        int id, source, target;\n\n\
    \        Arc() = default;\n        Arc(int id, int source, int target): id(id),\
    \ source(source), target(target) {}\n    };\n\n    class Digraph {\n        private:\n\
    \        int arc_id_offset;\n        vector<vector<Arc*>> adjacent_out, adjacent_in;\n\
    \        vector<Arc> arcs;\n\n        public:\n        /**\n         * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n         * @param n \u9802\u70B9\
    \u6570\n         * @param arc_id_offset \u5F27 ID \u306E\u30AA\u30D5\u30BB\u30C3\
    \u30C8\n         */\n        Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset)\
    \ {\n            adjacent_out.assign(n, {});\n            adjacent_in.assign(n,\
    \ {});\n            arcs.resize(arc_id_offset);\n        }\n        \n       \
    \ /**\n         * @brief \u9802\u70B9\u6570\u3092\u53D6\u5F97\u3059\u308B\n  \
    \       * @return int \u9802\u70B9\u6570\n         */\n        inline int order()\
    \ const { return int(adjacent_in.size()); }\n\n        /**\n         * @brief\
    \ \u8FBA\u6570\u3092\u53D6\u5F97\u3059\u308B\n         * @return int \u8FBA\u6570\
    \n         */\n        inline int size() const { return int(arcs.size()) - arc_id_offset;\
    \ }\n\n        /**\n         * @brief \u9802\u70B9 u \u304B\u3089\u9802\u70B9\
    \ v \u3078\u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B\n         * @param u \u59CB\
    \u70B9\n         * @param v \u7D42\u70B9\n         * @return Arc* \u8FFD\u52A0\
    \u3055\u308C\u305F\u5F27\u3078\u306E\u30DD\u30A4\u30F3\u30BF\n         */\n  \
    \      Arc* add_arc(int u, int v) {\n            int id = int(arcs.size());\n\n\
    \            Arc* arc_ptr = new Arc(id, u, v);\n            arcs.emplace_back(*arc_ptr);\n\
    \            \n            adjacent_out[u].emplace_back(arc_ptr);\n          \
    \  adjacent_in[v].emplace_back(arc_ptr);\n\n            return arc_ptr;\n    \
    \    }\n\n        /**\n         * @brief \u9802\u70B9 u \u304B\u3089\u51FA\u308B\
    \u5F27\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\n         * @param\
    \ u \u9802\u70B9\n         * @return const vector<Arc*>& \u5F27\u306E\u30EA\u30B9\
    \u30C8\n         */\n        inline const vector<Arc*>& successors(int u) const\
    \ { return adjacent_out[u]; }\n\n        /**\n         * @brief \u9802\u70B9 u\
    \ \u306B\u5165\u308B\u5F27\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\
    \n         * @param u \u9802\u70B9\n         * @return const vector<Arc*>& \u5F27\
    \u306E\u30EA\u30B9\u30C8\n         */\n        inline const vector<Arc*>& predecessors(int\
    \ u) const { return adjacent_in[u]; }\n\n        /**\n         * @brief \u6307\
    \u5B9A\u3055\u308C\u305F ID \u306E\u5F27\u3092\u53D6\u5F97\u3059\u308B\n     \
    \    * @param id \u5F27 ID\n         * @return const Arc \u5F27\n         */\n\
    \        inline const Arc get_arc(int id) const { return arcs[id]; }\n       \
    \ inline Arc get_arc(int id) { return arcs[id]; }\n\n        /**\n         * @brief\
    \ \u9802\u70B9 v \u306E\u51FA\u6B21\u6570\u3092\u53D6\u5F97\u3059\u308B\n    \
    \     * @param v \u9802\u70B9\n         * @return int \u51FA\u6B21\u6570\n   \
    \      */\n        inline int out_degree(const int v) const { return adjacent_out[v].size();\
    \ }\n\n        /**\n         * @brief \u9802\u70B9 v \u306E\u5165\u6B21\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\n         * @param v \u9802\u70B9\n         * @return\
    \ int \u5165\u6B21\u6570\n         */\n        inline int in_degree(const int\
    \ v) const { return adjacent_in[v].size(); }\n\n        /**\n         * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u96C6\u5408\u304B\u3089\u5230\u9054\
    \u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\
    \u308B\n         * @param sources \u59CB\u70B9\u306E\u96C6\u5408\n         * @return\
    \ vector<int> \u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\
    \n         */\n        vector<int> forward_reachable(const vector<int> &sources)\
    \ const {\n            const int n = order();\n            vector<bool> visited(n,\
    \ false);\n            vector<int> reachable;\n\n            for (const int s\
    \ : sources) {\n                if (s < 0 || s >= n || visited[s]) continue;\n\
    \                visited[s] = true;\n                reachable.emplace_back(s);\n\
    \            }\n\n            for (int head = 0; head < reachable.size(); ++head)\
    \ {\n                const int u = reachable[head];\n                for (const\
    \ auto *arc : adjacent_out[u]) {\n                    const int v = arc->target;\n\
    \                    if (visited[v]) continue;\n\n                    visited[v]\
    \ = true;\n                    reachable.emplace_back(v);\n                }\n\
    \            }\n\n            return reachable;\n        }\n\n        /**\n  \
    \       * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u304B\u3089\u5230\u9054\
    \u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\
    \u308B\n         * @param source \u59CB\u70B9\n         * @return vector<int>\
    \ \u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n       \
    \  */\n        vector<int> forward_reachable(const int source) const { return\
    \ forward_reachable(vector<int>{source}); }\n\n        /**\n         * @brief\
    \ \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u96C6\u5408\u3078\u5230\u9054\u53EF\
    \u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\
    \n         * @param targets \u7D42\u70B9\u306E\u96C6\u5408\n         * @return\
    \ vector<int> \u5230\u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\
    \n         */\n        vector<int> backward_reachable(const vector<int> &targets)\
    \ const {\n            const int n = order();\n            vector<bool> visited(n,\
    \ false);\n            vector<int> reachable;\n\n            for (const int t\
    \ : targets) {\n                if (t < 0 || t >= n || visited[t]) continue;\n\
    \                visited[t] = true;\n                reachable.emplace_back(t);\n\
    \            }\n\n            for (int head = 0; head < reachable.size(); ++head)\
    \ {\n                const int u = reachable[head];\n                for (const\
    \ auto *arc : adjacent_in[u]) {\n                    const int v = arc->source;\n\
    \                    if (visited[v]) continue;\n\n                    visited[v]\
    \ = true;\n                    reachable.emplace_back(v);\n                }\n\
    \            }\n\n            return reachable;\n        }\n\n        /**\n  \
    \       * @brief \u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u3078\u5230\u9054\u53EF\
    \u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\u3059\u308B\
    \n         * @param target \u7D42\u70B9\n         * @return vector<int> \u5230\
    \u9054\u53EF\u80FD\u306A\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n         */\n  \
    \      vector<int> backward_reachable(const int target) const { return backward_reachable(vector<int>{target});\
    \ }\n    };\n}\n#line 2 \"Graph/Digraph/Path.hpp\"\n\n#line 4 \"Graph/Digraph/Path.hpp\"\
    \n\nnamespace digraph {\n    struct Path {\n        vector<int> vertices;\n  \
    \      vector<Arc> arcs;\n\n        Path(const int first, const vector<Arc> &path):\
    \ arcs(path) {\n            vertices.emplace_back(first);\n            for (const\
    \ auto &arc: path) {\n                vertices.emplace_back(arc.target);\n   \
    \         }\n        }\n    };\n}\n#line 5 \"Graph/Digraph/Eulerian_Trail.hpp\"\
    \n\nnamespace digraph {\n    optional<Path> Eulerian_Trail(const Digraph &D) {\n\
    \        int n = D.order();\n        int m = D.size();\n        int start = -1,\
    \ goal = -1;\n\n        // \u5FC5\u8981\u6761\u4EF6\u306E\u5224\u5B9A\n      \
    \  for (int v = 0; v < n; ++v) {\n            int r = D.out_degree(v) - D.in_degree(v);\n\
    \            if (abs<int>(r) >= 2) return nullopt;\n\n            if (r == 1)\
    \ {\n                if (start != -1) return nullopt;\n\n                start\
    \ = v;\n            } else if (r == -1) {\n                goal = v;\n       \
    \     }\n        }\n\n        // start, goal \u306E\u6C7A\u5B9A\n        if (start\
    \ == -1) {\n            for (int v = 0; v < n; ++v) {\n                if (D.out_degree(v)\
    \ > 0) {\n                    start = goal = v;\n                    break;\n\
    \                }\n            }\n\n            if (start == -1) start = goal\
    \ = 0;\n        }\n\n        vector<int> iter(n, 0);\n        vector<Arc> path;\n\
    \        auto dfs = [&](auto self, const int v) -> void {\n            const auto\
    \ &arcs = D.successors(v);\n            while (iter[v] < arcs.size()) {\n    \
    \            const Arc* arc = arcs[iter[v]++];\n                self(self, arc->target);\n\
    \                path.emplace_back(*arc);\n            }\n        };\n\n     \
    \   dfs(dfs, start);\n\n        // \u5341\u5206\u6027\u306E\u30C1\u30A7\u30C3\u30AF\
    \n        if (path.size() < m) return nullopt;\n\n        reverse(path.begin(),\
    \ path.end());\n        return Path(start, path);\n    }\n}\n#line 5 \"verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp\"\
    \n\nusing namespace digraph;\n\noptional<Path> verify() {\n    int n, m;\n   \
    \ cin >> n >> m;\n    auto D = Digraph(n);\n    for (int j = 0; j < m; ++j) {\n\
    \        int u, v; scanf(\"%d%d\", &u, &v);\n        D.add_arc(u, v);\n    }\n\
    \n    return Eulerian_Trail(D);\n}\n\nint main() {\n    int T; cin >> T;\n   \
    \ for (int t = 0; t < T; ++t) {\n        auto pre_trail = verify();\n        if\
    \ (pre_trail == nullopt) {\n            cout << \"No\" << \"\\n\";\n         \
    \   continue;\n        }\n\n        Path trail = pre_trail.value();\n        cout\
    \ << \"Yes\" << \"\\n\";\n\n        cout << trail.vertices << \"\\n\";\n     \
    \   for (int j = 0; j < trail.arcs.size(); ++j) {\n            cout << (j ? \"\
    \ \" : \"\") << trail.arcs[j].id;\n        }\n        cout << \"\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eulerian_trail_directed\"\
    \n\n#include \"../../../template/template.hpp\"\n#include \"../../../Graph/Digraph/Eulerian_Trail.hpp\"\
    \n\nusing namespace digraph;\n\noptional<Path> verify() {\n    int n, m;\n   \
    \ cin >> n >> m;\n    auto D = Digraph(n);\n    for (int j = 0; j < m; ++j) {\n\
    \        int u, v; scanf(\"%d%d\", &u, &v);\n        D.add_arc(u, v);\n    }\n\
    \n    return Eulerian_Trail(D);\n}\n\nint main() {\n    int T; cin >> T;\n   \
    \ for (int t = 0; t < T; ++t) {\n        auto pre_trail = verify();\n        if\
    \ (pre_trail == nullopt) {\n            cout << \"No\" << \"\\n\";\n         \
    \   continue;\n        }\n\n        Path trail = pre_trail.value();\n        cout\
    \ << \"Yes\" << \"\\n\";\n\n        cout << trail.vertices << \"\\n\";\n     \
    \   for (int j = 0; j < trail.arcs.size(); ++j) {\n            cout << (j ? \"\
    \ \" : \"\") << trail.arcs[j].id;\n        }\n        cout << \"\\n\";\n    }\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Graph/Digraph/Eulerian_Trail.hpp
  - Graph/Digraph/Digraph.hpp
  - Graph/Digraph/Path.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp
  requiredBy: []
  timestamp: '2026-02-28 23:52:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp
- /verify/verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp.html
title: verify/yosupo_library_checker/graph/Eulerian_Trail_Directed.test.cpp
---
