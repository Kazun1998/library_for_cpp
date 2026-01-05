---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/concepts.hpp
    title: template/concepts.hpp
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
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u8FBA xy \u3092\u52A0\u3048\u308B. \u3053\u308C\u306B\u3088\u3063\
      \u3066 x, y \u304C\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408, \u9023\u7D50\
      \u6210\u5206\u306E\u8272\u306E\u66F4\u65B0\u3092\u884C\u3046."
    links: []
  bundledCode: "#line 2 \"Union_Find/Coloring_Union_Find.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n\n// a \u306E\
    \u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline\
    \ T max(const vector<T> &a){\n    if (a.empty()) throw invalid_argument(\"vector\
    \ is empty.\");\n\n    return *max_element(a.begin(), a.end());\n}\n\n// vector<T>\
    \ a \u306E\u6700\u5C0F\u5024\u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename\
    \ T>\ninline T min(const vector<T> &a){\n    if (a.empty()) throw invalid_argument(\"\
    vector is empty.\");\n\n    return *min_element(a.begin(), a.end());\n}\n\n//\
    \ vector<T> a \u306E\u6700\u5927\u5024\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline size_t argmax(const\
    \ vector<T> &a){\n    if (a.empty()) throw std::invalid_argument(\"vector is empty.\"\
    );\n\n    return distance(a.begin(), max_element(a.begin(), a.end()));\n}\n\n\
    // vector<T> a \u306E\u6700\u5C0F\u5024\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u3092\u53D6\u5F97\u3059\u308B.\ntemplate<typename T>\ninline size_t argmin(const\
    \ vector<T> &a){\n    if (a.empty()) throw invalid_argument(\"vector is empty.\"\
    );\n\n    return distance(a.begin(), min_element(a.begin(), a.end()));\n}\n#line\
    \ 59 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n//\
    \ \u6F14\u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) { return\
    \ x + y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return x -\
    \ y; }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x * y;\
    \ }\n\ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\nstd::vector<T>\
    \ input_vector(size_t n, size_t offset = 0) {\n    std::vector<T> res;\n    //\
    \ \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\u4FDD\uFF08\
    \u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n   \
    \ // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
    \u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\n    res.assign(offset, T());\n\
    \    \n    for (size_t i = 0; i < n; ++i) {\n        T el;\n        if (!(std::cin\
    \ >> el)) break;\n        res.push_back(std::move(el));\n    }\n    return res;\n\
    }\n#line 65 \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\
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
    \ get_bits(x, bit_length(x)); }\n#line 71 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 2 \"template/concepts.hpp\"\
    \n\n// \u5358\u9805\u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate\
    \ <typename Op, typename X>\nconcept Unary_Operator_Concept = requires(Op op,\
    \ const X &x) {\n    { op(x) } -> std::convertible_to<X>;\n};\n\n// \u4E8C\u9805\
    \u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate <typename Op, typename\
    \ X>\nconcept Binary_Operator_Concept = requires(Op op,const X &x, const X &y)\
    \ {\n    { op(x, y) } -> std::convertible_to<X>;\n};\n\n// \u30E2\u30CE\u30A4\u30C9\
    \u30B3\u30F3\u30BB\u30D7\u30C8\n// \u4E8C\u9805\u6F14\u7B97 + \u5358\u4F4D\u5143\
    \ntemplate <typename M, auto op, auto identity>\nconcept Monoid_Concept = \n \
    \   Binary_Operator_Concept<decltype(op), M>\n    && std::convertible_to<decltype(identity),\
    \ M>;\n\n// \u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u30E2\u30CE\u30A4\u30C9\
    \ + \u9006\u5143\ntemplate <typename G, auto op, auto inv, auto identity>\nconcept\
    \ Group_Concept = \n    Monoid_Concept<G, op, identity>\n    && Unary_Operator_Concept<decltype(inv),\
    \ G>;\n\n// \u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\u30B3\u30F3\u30BB\u30D7\u30C8\
    \ntemplate<typename T>\nconcept Hashable = requires(T x) {\n    { hash<T>{}(x)\
    \ } -> convertible_to<size_t>;\n};\n#line 5 \"Union_Find/Coloring_Union_Find.hpp\"\
    \n\ntemplate<class Color, auto merge, auto unit>\nrequires Monoid_Concept<Color,\
    \ merge, unit>\nclass Coloring_Union_Find {\n    int n, _group_number;\n    vector<int>\
    \ parents, rank;\n    vector<Color> data;\n\n    public:\n    explicit Coloring_Union_Find(int\
    \ n): n(n), parents(n, -1), data(n, unit), rank(n, 0), _group_number(n) {}\n \
    \   explicit Coloring_Union_Find(vector<Color> &colors):\n        n(colors.size()),\
    \ parents(n, -1), data(move(colors)), rank(n, 0), _group_number(n) {}\n\n    int\
    \ find(int x) {\n        return parents[x] < 0 ? x : parents[x] = find(parents[x]);\n\
    \    }\n\n    /// @brief \u8FBA xy \u3092\u52A0\u3048\u308B. \u3053\u308C\u306B\
    \u3088\u3063\u3066 x, y \u304C\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408\
    , \u9023\u7D50\u6210\u5206\u306E\u8272\u306E\u66F4\u65B0\u3092\u884C\u3046.\n\
    \    /// @param x \u9802\u70B9 1\n    /// @param y \u9802\u70B9 2\n    /// @return\
    \ \u9023\u7D50\u6210\u5206\u306E\u6570\u304C\u6E1B\u3063\u305F\u3089 true.\n \
    \   bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\n\
    \        if (x == y) { return false; }\n\n        if (rank[x] < rank[y]) { swap(x,\
    \ y); }\n\n        data[x] = merge(data[x], data[y]);\n\n        parents[x] +=\
    \ parents[y];\n        parents[y] = x;\n\n        _group_number--;\n\n       \
    \ if (rank[x] == rank[y]) { rank[x]++; }\n\n        return true;\n    }\n\n  \
    \  inline int size(int x) { return -parents[find(x)]; }\n\n    inline bool same(int\
    \ x, int y) { return find(x) == find(y); }\n\n    /// @brief x \u304C\u5C5E\u3059\
    \u308B\u9802\u70B9\u306E\u8272\u3092\u6C42\u3081\u308B.\n    /// @param x \u9802\
    \u70B9\n    inline Color get(int x) { return data[find(x)]; }\n\n    /// @brief\
    \ x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u8272\u3092 c \u306B\
    \u5909\u66F4\u3059\u308B.\n    /// @param x \u8272\u3092\u5909\u66F4\u3059\u308B\
    \u9802\u70B9\n    /// @param c \u5909\u66F4\u5F8C\u306E\u8272\n    inline void\
    \ set(int x, Color c) { data[find(x)] = c; }\n\n    inline int group_count() const\
    \ { return _group_number; }\n\n    vector<vector<int>> groups() {\n        unordered_map<int,\
    \ vector<int>> current_groups;\n        for (int i = 0; i < parents.size(); i++)\
    \ {\n            current_groups[find(i)].emplace_back(i);\n        }\n\n     \
    \   vector<vector<int>> res;\n        for (auto group: current_groups) res.emplace_back(group.second);\n\
    \n        return res;\n    }\n\n    vector<pair<vector<int>, Color>> group_colors()\
    \ {\n        vector<pair<vector<int>, Color>> res;\n        for (auto group: groups())\
    \ {\n            res.emplace_back(group, get(group[0]));\n        }\n\n      \
    \  return res;\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"../template/concepts.hpp\"\
    \n\ntemplate<class Color, auto merge, auto unit>\nrequires Monoid_Concept<Color,\
    \ merge, unit>\nclass Coloring_Union_Find {\n    int n, _group_number;\n    vector<int>\
    \ parents, rank;\n    vector<Color> data;\n\n    public:\n    explicit Coloring_Union_Find(int\
    \ n): n(n), parents(n, -1), data(n, unit), rank(n, 0), _group_number(n) {}\n \
    \   explicit Coloring_Union_Find(vector<Color> &colors):\n        n(colors.size()),\
    \ parents(n, -1), data(move(colors)), rank(n, 0), _group_number(n) {}\n\n    int\
    \ find(int x) {\n        return parents[x] < 0 ? x : parents[x] = find(parents[x]);\n\
    \    }\n\n    /// @brief \u8FBA xy \u3092\u52A0\u3048\u308B. \u3053\u308C\u306B\
    \u3088\u3063\u3066 x, y \u304C\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408\
    , \u9023\u7D50\u6210\u5206\u306E\u8272\u306E\u66F4\u65B0\u3092\u884C\u3046.\n\
    \    /// @param x \u9802\u70B9 1\n    /// @param y \u9802\u70B9 2\n    /// @return\
    \ \u9023\u7D50\u6210\u5206\u306E\u6570\u304C\u6E1B\u3063\u305F\u3089 true.\n \
    \   bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\n\
    \        if (x == y) { return false; }\n\n        if (rank[x] < rank[y]) { swap(x,\
    \ y); }\n\n        data[x] = merge(data[x], data[y]);\n\n        parents[x] +=\
    \ parents[y];\n        parents[y] = x;\n\n        _group_number--;\n\n       \
    \ if (rank[x] == rank[y]) { rank[x]++; }\n\n        return true;\n    }\n\n  \
    \  inline int size(int x) { return -parents[find(x)]; }\n\n    inline bool same(int\
    \ x, int y) { return find(x) == find(y); }\n\n    /// @brief x \u304C\u5C5E\u3059\
    \u308B\u9802\u70B9\u306E\u8272\u3092\u6C42\u3081\u308B.\n    /// @param x \u9802\
    \u70B9\n    inline Color get(int x) { return data[find(x)]; }\n\n    /// @brief\
    \ x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u8272\u3092 c \u306B\
    \u5909\u66F4\u3059\u308B.\n    /// @param x \u8272\u3092\u5909\u66F4\u3059\u308B\
    \u9802\u70B9\n    /// @param c \u5909\u66F4\u5F8C\u306E\u8272\n    inline void\
    \ set(int x, Color c) { data[find(x)] = c; }\n\n    inline int group_count() const\
    \ { return _group_number; }\n\n    vector<vector<int>> groups() {\n        unordered_map<int,\
    \ vector<int>> current_groups;\n        for (int i = 0; i < parents.size(); i++)\
    \ {\n            current_groups[find(i)].emplace_back(i);\n        }\n\n     \
    \   vector<vector<int>> res;\n        for (auto group: current_groups) res.emplace_back(group.second);\n\
    \n        return res;\n    }\n\n    vector<pair<vector<int>, Color>> group_colors()\
    \ {\n        vector<pair<vector<int>, Color>> res;\n        for (auto group: groups())\
    \ {\n            res.emplace_back(group, get(group[0]));\n        }\n\n      \
    \  return res;\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - template/concepts.hpp
  isVerificationFile: false
  path: Union_Find/Coloring_Union_Find.hpp
  requiredBy: []
  timestamp: '2026-01-04 22:16:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Union_Find/Coloring_Union_Find.hpp
layout: document
redirect_from:
- /library/Union_Find/Coloring_Union_Find.hpp
- /library/Union_Find/Coloring_Union_Find.hpp.html
title: "\u8FBA xy \u3092\u52A0\u3048\u308B. \u3053\u308C\u306B\u3088\u3063\u3066 x,\
  \ y \u304C\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408, \u9023\u7D50\u6210\u5206\
  \u306E\u8272\u306E\u66F4\u65B0\u3092\u884C\u3046."
---
