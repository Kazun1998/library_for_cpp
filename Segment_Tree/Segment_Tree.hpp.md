---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Segment_Tree/preset/Range_Max.hpp
    title: Segment_Tree/preset/Range_Max.hpp
  - icon: ':heavy_check_mark:'
    path: Segment_Tree/preset/Range_Min.hpp
    title: Segment_Tree/preset/Range_Min.hpp
  - icon: ':heavy_check_mark:'
    path: Segment_Tree/preset/Range_Sum.hpp
    title: Segment_Tree/preset/Range_Sum.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Subtree_Monoid_Vertex_Query.hpp
    title: "\u90E8\u5206\u6728\u306B\u95A2\u3059\u308B\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
    title: verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Point_add_Range_Sum.test.cpp
    title: verify/yosupo_library_checker/data_structure/Point_add_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
    title: verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
    title: verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Segment_Tree/Segment_Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <concepts>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n#include\
    \ <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numeric>\n#include <ostream>\n#include <optional>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll\
    \ = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\
    \u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename\
    \ T, typename U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a =\
    \ b, 1: 0);\n}\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\
    \u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename\
    \ T, typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a =\
    \ b, 1: 0);\n}\n\n// a \u306E\u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B\
    .\ntemplate<typename T>\ninline T max(const vector<T> &a){\n    if (a.empty())\
    \ throw invalid_argument(\"vector is empty.\");\n\n    return *max_element(a.begin(),\
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
    \n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nconstexpr ll intpow(ll x, ll\
    \ y) {\n    ll a = 1;\n    while (y) {\n        if (y & 1) { a *= x; }\n     \
    \   x *= x;\n        y >>= 1;\n    }\n    return a;\n}\n\nconstexpr ll pow(ll\
    \ x, ll y) { return intpow(x, y); }\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\
    \u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, integral\
    \ U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n        if (y\
    \ & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n    }\n\
    \n    return a;\n}\n\ntemplate<typename T>\nT sum(const vector<T> &X) {\n    T\
    \ y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\ntemplate<typename\
    \ T>\nT gcd(const T x, const T y) {\n    return y == 0 ? x : gcd(y, x % y);\n\
    }\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44\
    \ (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
    .\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T a, T b) {\n    T s =\
    \ 1, t = 0, u = 0, v = 1;\n    while (b) {\n        auto [q, r] = divmod(a, b);\n\
    \        a = b;\n        b = r;\n        tie(s, t) = make_pair(t, s - q * t);\n\
    \        tie(u, v) = make_pair(v, u - q * v);\n    }\n\n    return make_tuple(s,\
    \ u, a);\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\
    \u306F, 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n    if (N <= 0) { return\
    \ 0; }\n\n    ll x = sqrtl(N);\n    while ((x + 1) * (x + 1) <= N) { x++; }\n\
    \    while (x * x > N) { x--; }\n\n    return x;\n}\n\n// floor(sqrt(N)) \u3092\
    \u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll\
    \ floor_sqrt(const ll &N) { return isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\
    \u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const\
    \ ll &N) {\n    ll x = isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line\
    \ 64 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\n//\
    \ \u5165\u51FA\u529B\n#line 4 \"template/inout.hpp\"\n\ntemplate<class... T>\n\
    void input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\
    \ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&... b){\n  \
    \  cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\\n\";\n\
    }\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &P){\n   \
    \ os << P.first << \" \" << P.second;\n    return os;\n}\n\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &X){\n    for (auto &x: X) {\
    \ is >> x; }\n    return is;\n}\n\ntemplate<typename T, typename U = typename\
    \ T::iterator>\ntypename std::enable_if<!std::is_same<T, std::string>::value,\
    \ ostream&>::type\noperator<<(ostream &os, const T &container){\n    bool is_first\
    \ = true;\n    for (const auto &x : container) {\n        os << (is_first ? \"\
    \" : \" \") << x;\n        is_first = false;\n    }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nstd::vector<T> input_vector(int n, int offset = 0) {\n    std::vector<T>\
    \ res;\n    // \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\
    \u4FDD\uFF08\u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n\
    \    // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
    \u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\n    res.assign(offset, T());\n\n\
    \    for (int i = 0; i < n; ++i) {\n        T el;\n        if (!(std::cin >> el))\
    \ break;\n        res.push_back(std::move(el));\n    }\n    return res;\n}\n\n\
    #line 63 \"template/inout.hpp\"\n\n// 1. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA\
    \ n \u306E 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\ntemplate<typename T>\nauto\
    \ make_multi_dimensional_vector(int n) {\n    return std::vector<T>(n);\n}\n\n\
    // 2. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA n \u3067\u521D\u671F\u5024 val \u3092\
    \u6301\u3064 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\uFF08\u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\uFF09\ntemplate<typename T>\nauto make_multi_dimensional_vector(int\
    \ n, T val) {\n    return std::vector<T>(n, val);\n}\n\n// 3. \u518D\u5E30\uFF1A\
    \u6B21\u5143\u3092\u524A\u308B\ntemplate<typename T, typename... Args>\nauto make_multi_dimensional_vector(int\
    \ n, Args... args) {\n    auto inner = make_multi_dimensional_vector<T>(args...);\n\
    \    return std::vector<decltype(inner)>(n, inner);\n}\n#line 67 \"template/template.hpp\"\
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
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 70 \"template/template.hpp\"\n\n// bitop\n\
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
    \ bit_length(x)); }\n\n// x \u306B\u7ACB\u3063\u3066\u3044\u308B\u306A\u3093\u304B\
    \u3057\u3089\u306E\u30D3\u30C3\u30C8\u306E\u756A\u53F7\u3092\u51FA\u529B\u3059\
    \u308B.\nll lowest_bit(const ll x) { return floor_log2(x & (-x)); }\n#line 73\
    \ \"template/template.hpp\"\n\n// exception\n#line 2 \"template/exception.hpp\"\
    \n\nclass NotExist: public exception {\n    private:\n    string message;\n\n\
    \    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\u3046\u3068\u3057\u3066\
    \u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\u305B\u3093.\") {}\n\n\
    \    const char* what() const noexcept override {\n        return message.c_str();\n\
    \    }\n};\n#line 4 \"Segment_Tree/Segment_Tree.hpp\"\n\ntemplate<typename M,\
    \ typename Op = function<M(M, M)>>\nclass Segment_Tree{\n    private:\n    int\
    \ n;\n    vector<M> data;\n    const Op op;\n    const M unit;\n\n    public:\n\
    \    Segment_Tree(int size, Op op, const M unit): n(), op(op), unit(unit) {\n\
    \        int m = 1;\n        while (m < size) { m *= 2; }\n\n        n = m;\n\
    \        data.assign(2 * n, unit);\n    }\n\n    Segment_Tree(const vector<M>\
    \ &vec, Op op, const M unit):\n        Segment_Tree(vec.size(), op, unit) {\n\
    \            for (int k = 0; k < vec.size(); k++) { data[k + n] = vec[k]; }\n\
    \            for (int k = n - 1; k > 0; k--) { recalc(k); }\n        }\n\n   \
    \ private:\n    void recalc(int k) { data[k] = op(data[k << 1], data[k << 1 |\
    \ 1]); }\n\n    public:\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\
    \u3059\u308B\n    void update(int k, M x) {\n        k += n;\n        data[k]\
    \ = x;\n\n        for (k >>= 1; k; k >>= 1) { recalc(k); }\n    }\n\n    // \u7B2C\
    \ k \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\n    M get(int k) { return data[k\
    \ + n]; }\n\n    M operator[](int k) { return get(k); }\n\n    // \u7B2C l \u8981\
    \u7D20\u304B\u3089\u7B2C r \u8981\u7D20\u307E\u3067\u306E\u7DCF\u7A4D\u3092\u6C42\
    \u3081\u308B\n    M product(int l, int r){\n        l += n; r += n + 1;\n    \
    \    M vl = unit, vr = unit;\n        while (l < r){\n            if (l & 1){\n\
    \                vl = op(vl, data[l]);\n                l++;\n            }\n\n\
    \            if (r & 1){\n                r--;\n                vr = op(data[r],\
    \ vr);\n            }\n\n            l >>= 1; r >>= 1;\n        }\n\n        return\
    \ op(vl, vr);\n    }\n\n    template<typename Func>\n    int max_right(int l,\
    \ const Func &cond) {\n        assert(cond(unit));\n        if (l == n) return\
    \ n;\n\n        l += n;\n        M sm = unit;\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n\n            if (cond(op(sm, data[l]))) {\n        \
    \        sm = op(sm ,data[l]);\n                ++l;\n                continue;\n\
    \            }\n\n            while (l < n) {\n                l = l << 1;\n \
    \               if (cond(op(sm, data[l]))) {\n                    sm = op(sm,\
    \ data[l]);\n                    ++l;\n                }\n            }\n    \
    \        return l - n;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template<typename Func>\n    int min_left(int r, const Func &cond)\
    \ {\n        assert(cond(unit));\n        if (r == 0) return 0;\n\n        r +=\
    \ n;\n        M sm = unit;\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n\n            if (cond(op(data[r], sm))) {\n  \
    \              sm = op(data[r], sm);\n                continue;\n            }\n\
    \n            while (r < n) {\n                r = (r << 1) | 1;\n           \
    \     if (cond(op(data[r], sm))) {\n                    sm = op(data[r], sm);\n\
    \                    r--;\n                }\n            }\n            return\
    \ r + 1 - n;\n\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\
    \ntemplate<typename M, typename Op>\nSegment_Tree(int, Op, M) -> Segment_Tree<M,\
    \ Op>;\n\ntemplate<typename M, typename Op>\nSegment_Tree(const vector<M> &, Op,\
    \ M) -> Segment_Tree<M, Op>;\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate<typename\
    \ M, typename Op = function<M(M, M)>>\nclass Segment_Tree{\n    private:\n   \
    \ int n;\n    vector<M> data;\n    const Op op;\n    const M unit;\n\n    public:\n\
    \    Segment_Tree(int size, Op op, const M unit): n(), op(op), unit(unit) {\n\
    \        int m = 1;\n        while (m < size) { m *= 2; }\n\n        n = m;\n\
    \        data.assign(2 * n, unit);\n    }\n\n    Segment_Tree(const vector<M>\
    \ &vec, Op op, const M unit):\n        Segment_Tree(vec.size(), op, unit) {\n\
    \            for (int k = 0; k < vec.size(); k++) { data[k + n] = vec[k]; }\n\
    \            for (int k = n - 1; k > 0; k--) { recalc(k); }\n        }\n\n   \
    \ private:\n    void recalc(int k) { data[k] = op(data[k << 1], data[k << 1 |\
    \ 1]); }\n\n    public:\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\
    \u3059\u308B\n    void update(int k, M x) {\n        k += n;\n        data[k]\
    \ = x;\n\n        for (k >>= 1; k; k >>= 1) { recalc(k); }\n    }\n\n    // \u7B2C\
    \ k \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\n    M get(int k) { return data[k\
    \ + n]; }\n\n    M operator[](int k) { return get(k); }\n\n    // \u7B2C l \u8981\
    \u7D20\u304B\u3089\u7B2C r \u8981\u7D20\u307E\u3067\u306E\u7DCF\u7A4D\u3092\u6C42\
    \u3081\u308B\n    M product(int l, int r){\n        l += n; r += n + 1;\n    \
    \    M vl = unit, vr = unit;\n        while (l < r){\n            if (l & 1){\n\
    \                vl = op(vl, data[l]);\n                l++;\n            }\n\n\
    \            if (r & 1){\n                r--;\n                vr = op(data[r],\
    \ vr);\n            }\n\n            l >>= 1; r >>= 1;\n        }\n\n        return\
    \ op(vl, vr);\n    }\n\n    template<typename Func>\n    int max_right(int l,\
    \ const Func &cond) {\n        assert(cond(unit));\n        if (l == n) return\
    \ n;\n\n        l += n;\n        M sm = unit;\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n\n            if (cond(op(sm, data[l]))) {\n        \
    \        sm = op(sm ,data[l]);\n                ++l;\n                continue;\n\
    \            }\n\n            while (l < n) {\n                l = l << 1;\n \
    \               if (cond(op(sm, data[l]))) {\n                    sm = op(sm,\
    \ data[l]);\n                    ++l;\n                }\n            }\n    \
    \        return l - n;\n        } while ((l & -l) != l);\n        return n;\n\
    \    }\n\n    template<typename Func>\n    int min_left(int r, const Func &cond)\
    \ {\n        assert(cond(unit));\n        if (r == 0) return 0;\n\n        r +=\
    \ n;\n        M sm = unit;\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n\n            if (cond(op(data[r], sm))) {\n  \
    \              sm = op(data[r], sm);\n                continue;\n            }\n\
    \n            while (r < n) {\n                r = (r << 1) | 1;\n           \
    \     if (cond(op(data[r], sm))) {\n                    sm = op(data[r], sm);\n\
    \                    r--;\n                }\n            }\n            return\
    \ r + 1 - n;\n\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n\
    \ntemplate<typename M, typename Op>\nSegment_Tree(int, Op, M) -> Segment_Tree<M,\
    \ Op>;\n\ntemplate<typename M, typename Op>\nSegment_Tree(const vector<M> &, Op,\
    \ M) -> Segment_Tree<M, Op>;\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Segment_Tree/Segment_Tree.hpp
  requiredBy:
  - Tree/Subtree_Monoid_Vertex_Query.hpp
  - Segment_Tree/preset/Range_Max.hpp
  - Segment_Tree/preset/Range_Min.hpp
  - Segment_Tree/preset/Range_Sum.hpp
  timestamp: '2026-09-20 10:37:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
  - verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
  - verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
  - verify/yosupo_library_checker/data_structure/Point_add_Range_Sum.test.cpp
  - verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
documentation_of: Segment_Tree/Segment_Tree.hpp
layout: document
title: Segment Tree
---

## Outline

モノイド $M = (M, *, e_M)$ の列に $A$ に対する 1 点更新, 区間積の取得を得意とするデータ構造.

## Contents

### Constructer

```cpp
Segment_Tree S(int size, const function<M(M, M)> op, const M unit)
```

- 長さが `size` の各項が $e_M$ の列で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.

```cpp
Segment_Tree S(const vector<M> &vec, const function<M(M, M)> op, const M unit)
```

- `vec` で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.
- **計算量** : $O(1)$ Time.

### update

```cpp
void S.update(int k, M x)
```

- 第 $k$ 要素を $x$ に更新する.
- **制約**
  - $0 \leq k \lt N$.
- **計算量** : $O(\log N)$ 時間

### product

```cpp
M S.product(int l, int r)
```

* 連続部分列における積 $A_l * A_{l+1} * \dots A_{r-1} * A_r$ を求める.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **注意点**
  * $l \leq r$ でないとき, 返り値は単位元 $e_M$ になる.

### max_right

```cpp
int max_right(int l, const Func &cond)
```

* $M$ の部分集合 $T$ を $T := \{x \in M \mid \textrm{cond}(x)\}$ で定義する. このとき, 以下の条件を両方満たす $r$ (のいずれか 1 つ) 返す.
  * $r = l$ もしくは $A_l * A_{l + 1} * \dots * A_{r-1} \in T$.
  * $r = N$ もしくは $A_l * A_{l + 1} * \dots * A_r \not \in T$.
* $\textrm{cond}$ が単調だとすれば, $A_l * A_{l + 1} \dots * A_{r - 1} \in T$ となる最大の $r$ と解釈することが可能である.
* **制約**
  * $e_M \in T$.
* **計算量**
  * $O(\log N)$ 時間.

### min_left

```cpp
int min_left(int r, const Func &cond)
```

* $M$ の部分集合 $T$ を $T := \{x \in M \mid \textrm{cond}(x)\}$ で定義する. このとき, 以下の条件を両方満たす $l$ (のいずれか 1 つ) 返す.
  * $l = r$ もしくは $A_l * A_{l + 1} * \dots * A_{r-1} \in T$.
  * $l = 0$ もしくは $A_{l-1} * A_l * \dots * A_{r-1} \not \in T$.
* $\textrm{cond}$ が単調だとすれば, $A_l * A_{l + 1} \dots * A_{r - 1} \in T$ となる最大の $l$ と解釈することが可能である.
* **制約**
  * $e_M \in T$.
* **計算量**
  * $O(\log N)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/01/12|max_right, min_left の実装|
|2025/10/30|初期化の際に発生していた, 配列外参照バグの修正|
|2025/08/15|Segment_Tree 実装|
