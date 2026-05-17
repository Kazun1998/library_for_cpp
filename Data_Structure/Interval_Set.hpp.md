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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5024 val \u304C\u7D10\u3065\u3044\u3066\u3044\u308B, \u53F3\
      \u534A\u958B\u533A\u9593 [l, r) \u3092\u751F\u6210\u3059\u308B."
    links:
    - https://github.com/drken1215/algorithm/blob/master/DataStructure/intervals_management.cpp
  bundledCode: "#line 2 \"Data_Structure/Interval_Set.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 4 \"Data_Structure/Interval_Set.hpp\"\n\n// Reference: https://github.com/drken1215/algorithm/blob/master/DataStructure/intervals_management.cpp\n\
    \ntemplate<typename T, class V = ll>\nclass Interval_Set {\n    struct Node {\n\
    \        T l, r;\n        V val;\n\n        /// @brief \u5024 val \u304C\u7D10\
    \u3065\u3044\u3066\u3044\u308B, \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\u751F\
    \u6210\u3059\u308B.\n        /// @param l \u5DE6\u7AEF\n        /// @param r \u53F3\
    \u7AEF\n        /// @param val \u7D10\u3065\u3051\u308B\u8981\u7D20\n        Node\
    \ (const T &l, const T &r, const V &val): l(l), r(r), val(val) {};\n\n       \
    \ /// @brief p \u306F\u3053\u306E\u53F3\u534A\u958B\u533A\u9593\u306B\u542B\u307E\
    \u308C\u308B\u304B?\n        /// @param p \n        constexpr bool contains(const\
    \ T &p) const { return l <= p && p < r; }\n\n        constexpr bool operator<(const\
    \ Node &rhs) const {\n            if (l != rhs.l) { return l < rhs.l; }\n    \
    \        return r < rhs.r;\n        }\n\n        friend ostream& operator<<(ostream\
    \ &os, const Node &node) {\n            return os << \"([\" << node.l << \", \"\
    \ << node.r << \"): \" << node.val << \")\";\n        }\n    };\n\n    const V\
    \ nil; // \u30C7\u30D5\u30A9\u30EB\u30C8\u5024\n    size_t set_size;\n    set<Node>\
    \ intervals;\n\n    template<class ADDFUNC>\n    void add_update(const ADDFUNC\
    \ &add, const T l, const T r, const V &val) {\n        add(l, r, val);\n     \
    \   set_size += r - l;\n    }\n\n    template<class DELFUNC>\n    void del_update(const\
    \ DELFUNC &del, const T l, const T r, const V &val) {\n        del(l, r, val);\n\
    \        set_size -= r - l;\n    }\n\n    public:\n    Interval_Set(): Interval_Set(V())\
    \ {}\n\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3092 nil \u3068\u3057\u3066\
    , Interval Set \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\u3092\u751F\u6210\u3059\u308B\
    .\n    Interval_Set(const V &nil): nil(nil), set_size(0) {}\n\n    // iterators\n\
    \    constexpr typename set<Node>::iterator begin() { return intervals.begin();\
    \ }\n    constexpr typename set<Node>::iterator end() { return intervals.end();\
    \ }\n\n    /// @brief p \u3092\u542B\u3080\u533A\u9593\u306E\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u6C42\u3081\u308B (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F, end() \u304C\u8FD4\u308A\u5024).\n    /// @param p \n    constexpr typename\
    \ set<Node>::iterator get(const T &p) const {\n        auto it = intervals.upper_bound(Node(p,\
    \ numeric_limits<T>::max(), 0));\n        if (it == intervals.begin()) { return\
    \ intervals.end(); }\n\n        // \u3053\u3053\u306B\u6765\u308B it \u306F, p\
    \ \u3092\u542B\u3080\u533A\u9593\u306E\u6B21\u306E\u533A\u9593\u306A\u306E\u3067\
    , 1 \u500B\u623B\u3059.\n        it = prev(it);\n\n        return it->contains(p)\
    \ ? it : intervals.end();\n    }\n\n    /// @brief p \u4EE5\u4E0A\u3067\u3042\u308B\
    \u6700\u5C0F\u306E\u8981\u7D20\u3092\u542B\u3093\u3067\u3044\u308B\u533A\u9593\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ p\n    constexpr typename set<Node>::iterator lower_bound(const T &p) {\n  \
    \      auto it = get(p);\n\n        if (it != intervals.end()) { return it; }\n\
    \        return intervals.upper_bound(Node(p, numeric_limits<T>::max(), 0));\n\
    \    }\n\n    /// @brief p \u3092\u542B\u3080\u304B?\n    /// @param p\n    constexpr\
    \ bool covered(const T &p) {\n        return get(p) != intervals.end();\n    }\n\
    \n    /// @brief \u533A\u9593 [l, r) \u3092\u542B\u3080\u304B?\n    /// @param\
    \ l \n    /// @param r \n    constexpr bool covered(const T &l, const T &r) {\n\
    \        assert(l <= r);\n\n        if (l == r) { return true; }\n\n        auto\
    \ it = get(l);\n        return it != intervals.end() && r <= it->r;\n    }\n\n\
    \    constexpr bool same(const T &p, const T &q) {\n        return covered(p)\
    \ && covered(q) && get(p) == get(q);\n    }\n\n    /// @brief p \u3092\u542B\u3080\
    \u53F3\u534A\u958B\u533A\u9593\u306B\u7D10\u3065\u3044\u3066\u3044\u308B\u5024\
    \u3092\u6C42\u3081\u308B (\u305D\u306E\u3088\u3046\u306A\u53F3\u534A\u958B\u533A\
    \u9593\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F nil \u304C\u8FD4\u308A\
    \u5024)\n    /// @param p \n    constexpr V get_value(const T &p) const {\n  \
    \      auto it = get(p);\n        return it != intervals.end() ? it->val : nil;\n\
    \    }\n\n    V operator[](const T &p) const { return get_value(p); }\n\n    constexpr\
    \ T get_mex(const T &p = 0) {\n        auto it = intervals.upper_bound(Node(p,\
    \ numeric_limits<T>::max(), 0));\n        if (it == intervals.begin()) { return\
    \ p; }\n\n        it = prev(it);\n\n        return it->contains(p) ? it->r : p;\n\
    \    }\n\n    /// @brief val \u304C\u7D10\u3065\u3044\u305F, \u53F3\u534A\u958B\
    \u533A\u9593 [l, r) \u3092\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\
    . \u305D\u306E\u969B, \u767A\u751F\u3059\u308B\u5DEE\u5206\u3092 add, del \u95A2\
    \u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///        \u3053\u306E\u95A2\u6570\
    \u306F,\u65B0\u3057\u3044\u533A\u9593 [l, r) \u3068\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u3092\u9069\u5207\u306B\u51E6\u7406\u3057,\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u533A\u9593\u306E\u7D50\u5408,\u5206\u5272,\u524A\u9664\
    \u3092\u884C\u3046.\n    /// @param l \u5DE6\u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\
    \u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\u5DE6\u7AEF)\n    /// @param r \u53F3\
    \u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\
    \u53F3\u7AEF)\n    /// @param val \u53F3\u534A\u958B\u533A\u9593\u306B\u7D10\u3065\
    \u3051\u308B\u5024\n    /// @param add \u8FFD\u52A0\u5DEE\u5206\u304C\u767A\u751F\
    \u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\n\
    \    /// @param del \u524A\u9664\u5DEE\u5206\u304C\u767A\u751F\u3057\u305F\u5834\
    \u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\n    template<class\
    \ ADDFUNC, class DELFUNC>\n    void update(T l, T r, const V &val, const ADDFUNC\
    \ &add, const DELFUNC &del) {\n        // \u65B0\u3057\u304F\u8FFD\u52A0\u307E\
    \u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593 [l, r) \u306E\u958B\u59CB\u70B9\
    \ l \u4EE5\u4E0A\u3067\u6700\u3082\u8FD1\u3044\u533A\u9593\u3092\u898B\u3064\u3051\
    \u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u30C1\u30A7\u30C3\u30AF\u3092\u958B\u59CB\u3059\u308B\
    \u9069\u5207\u306A\u4F4D\u7F6E\u3092\u7279\u5B9A\u3059\u308B.\n        auto it\
    \ = intervals.lower_bound(Node(l, 0, val));\n\n        // \u65B0\u3057\u3044\u533A\
    \u9593 [l, r) \u3068\u91CD\u306A\u308B\u53EF\u80FD\u6027\u306E\u3042\u308B\u65E2\
    \u5B58\u306E\u533A\u9593\u3092\u5168\u3066\u51E6\u7406\u3059\u308B.\n        //\
    \ it->l <= r \u306F,\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF\u304C\
    \u65B0\u3057\u3044\u533A\u9593 [l, r) \u306E\u53F3\u7AEF r \u4EE5\u4E0B\u3067\u3042\
    \u308B\u3053\u3068\u3092\u793A\u3059.\n        while (it != intervals.end() &&\
    \ it->l <= r) {\n            // Case 0: \u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\
    \u7AEF r \u304C\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF it->l \u3068\
    \u4E00\u81F4\u3059\u308B\u5834\u5408\n            // \u304B\u3064,\u5024\u3082\
    \u540C\u3058\u5834\u5408\u306F\u533A\u9593\u3092\u7D50\u5408\u3059\u308B.\n  \
    \          // \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\u533A\u9593\u3068\u306E\
    \u91CD\u8907\u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\u30D7\u3092\u629C\u3051\
    \u308B.\n            if (r == it->l) {\n                if (it->val == val) {\n\
    \                    r = it->r; // \u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF\
    \u3092\u62E1\u5F35\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \       }\n                break;\n            }\n\n            // Case 1: \u73FE\
    \u5728\u306E\u533A\u9593 [it->l, it->r) \u304C\u65B0\u3057\u3044\u533A\u9593 [l,\
    \ r) \u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u308B\u304B,\n            // \u307E\
    \u305F\u306F,\u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF r \u3067\u7D42\u308F\
    \u308B\u5834\u5408 (it->r <= r)\n            // \u3053\u306E\u533A\u9593\u306F\
    \u65B0\u3057\u3044\u533A\u9593\u306B\u4E0A\u66F8\u304D\u3055\u308C\u308B\u305F\
    \u3081,\u524A\u9664\u3059\u308B.\n            if (it->r <= r) {\n            \
    \    del_update(del, it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\
    \u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n        \
    \        it = intervals.erase(it);\n            } else {\n                // Case\
    \ 2: \u65B0\u3057\u3044\u533A\u9593 [l, r) \u304C\u73FE\u5728\u306E\u533A\u9593\
    \ [it->l, it->r) \u306E\u4E00\u90E8\u3068\u91CD\u306A\u308B\u5834\u5408\n    \
    \            // (l <= it->l < r < it->r \u304C\u78BA\u5B9A)\n                if\
    \ (it->val == val) {\n                    // \u5024\u304C\u540C\u3058\u5834\u5408\
    \u306F,\u65B0\u3057\u3044\u533A\u9593\u3068\u73FE\u5728\u306E\u533A\u9593\u3092\
    \u7D50\u5408\u3057,\u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF\u3092\u62E1\
    \u5F35\u3059\u308B.\n                    // \u65E2\u5B58\u533A\u9593\u306F\u524A\
    \u9664\u3055\u308C\u308B.\n                    r = it->r; // \u65B0\u3057\u3044\
    \u533A\u9593\u306E\u53F3\u7AEF\u3092\u62E1\u5F35\n                    del_update(del,\
    \ it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\
    \u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n\
    \                } else {\n                    // \u5024\u304C\u7570\u306A\u308B\
    \u5834\u5408\u306F,\u73FE\u5728\u306E\u533A\u9593 [it->l, it->r) \u3092\u65B0\u3057\
    \u3044\u533A\u9593\u306B\u3088\u3063\u3066\u4E8C\u5206\u5272\u3059\u308B.\n  \
    \                  // [it->l, r) \u306E\u90E8\u5206\u306F\u65B0\u3057\u3044\u533A\
    \u9593\u306B\u3088\u3063\u3066\u4E0A\u66F8\u304D\u3055\u308C\u308B\u305F\u3081\
    ,[r, it->r) \u306E\u90E8\u5206\u306E\u307F\u304C\u6B8B\u308B.\n              \
    \      Node node = *it;\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \           // \u6B8B\u308A\u306E\u533A\u9593 [r, node.r) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(it, r, node.r, node.val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                }\n            }\n        }\n\n        //\
    \ \u65B0\u3057\u3044\u533A\u9593 [l, r) \u306E\u5DE6\u7AEF l \u306E\u3059\u3050\
    \u5DE6\u306B\u3042\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u30C1\u30A7\u30C3\
    \u30AF\u3059\u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65B0\u3057\u3044\
    \u533A\u9593\u3068\u5DE6\u5074\u306E\u65E2\u5B58\u533A\u9593\u306E\u7D50\u5408\
    \u3084\u5206\u5272\u3092\u51E6\u7406\u3059\u308B.\n        if (it != intervals.begin())\
    \ {\n            it = prev(it); // \u5DE6\u5074\u306E\u533A\u9593\u3092\u53D6\u5F97\
    \n            // Case 3: \u5DE6\u5074\u306E\u533A\u9593 [it->l, it->r) \u306E\u53F3\
    \u7AEF it->r \u304C\u65B0\u3057\u3044\u533A\u9593\u306E\u5DE6\u7AEF l \u3068\u4E00\
    \u81F4\u3059\u308B\u5834\u5408\n            if (it->r == l) {\n              \
    \  if (it->val == val) {\n                    // \u5024\u304C\u540C\u3058\u5834\
    \u5408\u306F,\u4E21\u533A\u9593\u3092\u7D50\u5408\u3057,\u65B0\u3057\u3044\u533A\
    \u9593\u306E\u5DE6\u7AEF\u3092\u62E1\u5F35\u3059\u308B.\n                    l\
    \ = it->l;\n                    del_update(del, it->l, it->r, it->val); // \u65E2\
    \u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n                    it = intervals.erase(it);\n               \
    \ }\n            } else if (l < it->r) {\n                // Case 4: \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u65B0\u3057\u3044\u533A\u9593 [l, r)\
    \ \u3068\u91CD\u306A\u308B\u5834\u5408\n                // (it->l < l < it->r\
    \ \u304C\u78BA\u5B9A)\n                if (it->val == val) {\n               \
    \     // \u5024\u304C\u540C\u3058\u5834\u5408\u306F,\u4E21\u533A\u9593\u3092\u7D50\
    \u5408\u3057,\u65B0\u3057\u3044\u533A\u9593\u306E\u7BC4\u56F2\u3092\u62E1\u5F35\
    \u3059\u308B.\n                    l = min(l, it->l);\n                    r =\
    \ max(r, it->r);\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \       } else {\n                    // \u5024\u304C\u7570\u306A\u308B\u5834\u5408\
    \u306F,\u5DE6\u5074\u306E\u533A\u9593 [it->l, it->r) \u3092\u65B0\u3057\u3044\u533A\
    \u9593\u306B\u3088\u3063\u3066\u4E8C\u5206\u5272\u3059\u308B.\n              \
    \      // [it->l, l) \u306E\u90E8\u5206\u3068 [l, it->r) \u306E\u90E8\u5206\u306B\
    \u5206\u3051\u3089\u308C,\n                    // \u5F8C\u8005\u306F\u65B0\u3057\
    \u3044\u533A\u9593\u306B\u3088\u3063\u3066\u4E0A\u66F8\u304D\u3055\u308C\u308B\
    \u305F\u3081,[it->l, l) \u306E\u90E8\u5206\u306E\u307F\u304C\u6B8B\u308B.\n  \
    \                  if (r < it->r) { // \u65B0\u3057\u3044\u533A\u9593\u304C\u5DE6\
    \u5074\u306E\u533A\u9593\u306E\u4E00\u90E8\u3092\u30AB\u30D0\u30FC\u3059\u308B\
    \u5834\u5408\n                        // \u5DE6\u5074\u306E\u533A\u9593\u306E\u6B8B\
    \u308A\u306E\u90E8\u5206 [r, it->r) \u3092\u633F\u5165\n                     \
    \   it = intervals.emplace_hint(next(it), r, it->r, it->val);\n              \
    \          add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\u308C\
    \u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n                        it = prev(it); // \u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u5143\u306B\u623B\u3059\n                    }\n                \
    \    Node node = *it;\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \           // \u6B8B\u308A\u306E\u533A\u9593 [node.l, l) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(it, node.l, l, node.val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                }\n            }\n        }\n\n        //\
    \ \u9069\u5207\u306A\u4F4D\u7F6E\u306B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8ABF\
    \u6574\u3059\u308B.\n        if (it != intervals.end()) { it = next(it); }\n\n\
    \        // \u6700\u7D42\u7684\u306B\u78BA\u5B9A\u3057\u305F\u65B0\u3057\u3044\
    \u533A\u9593 [l, r) \u3092\u633F\u5165\u3059\u308B.\n        it = intervals.emplace_hint(it,\
    \ l, r, val);\n        add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\
    \u3055\u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\
    \u5206\u3092\u901A\u77E5)\n    }\n\n    void update(const T &l, const T &r, const\
    \ V &val) {\n        update(l, r, val, [](T, T, V){}, [](T, T, V){});\n    }\n\
    \n    /// @brief \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\u8FFD\u52A0\u307E\
    \u305F\u306F\u66F4\u65B0\u3059\u308B. \u305D\u306E\u969B, \u767A\u751F\u3059\u308B\
    \u5DEE\u5206\u3092 add, del \u95A2\u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///\
    \        \u3053\u306E\u95A2\u6570\u306F,\u65B0\u3057\u3044\u533A\u9593 [l, r)\
    \ \u3068\u65E2\u5B58\u306E\u533A\u9593\u3068\u306E\u91CD\u8907\u3092\u9069\u5207\
    \u306B\u51E6\u7406\u3057,\u5FC5\u8981\u306B\u5FDC\u3058\u3066\u533A\u9593\u306E\
    \u7D50\u5408,\u5206\u5272,\u524A\u9664\u3092\u884C\u3046.\n    /// @param l \u5DE6\
    \u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\
    \u5DE6\u7AEF)\n    /// @param r \u53F3\u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\
    \u65B0\u3059\u308B\u533A\u9593\u306E\u53F3\u7AEF)\n    /// @param add \u8FFD\u52A0\
    \u5DEE\u5206\u304C\u767A\u751F\u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570\
    : T left, T right, V value)\n    /// @param del \u524A\u9664\u5DEE\u5206\u304C\
    \u767A\u751F\u3057\u305F\u5834\u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left,\
    \ T right, V value)\n    template<class ADDFUNC, class DELFUNC>\n    void insert(T\
    \ l, T r, const ADDFUNC &add, const DELFUNC &del) {\n        update(l, r, V(),\
    \ add, del);\n    }\n\n    /// @brief \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\
    \u633F\u5165\u3059\u308B.\n    /// @param l \u5DE6\u7AEF\n    /// @param r \u53F3\
    \u7AEF\n    void insert(const T &l, const T &r) {\n        update(l, r, V(), [](T,\
    \ T, V){}, [](T, T, V){});\n    }\n\n    /// @brief \u53F3\u534A\u958B\u533A\u9593\
    \ [l, r) \u3068\u91CD\u306A\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u524A\u9664\
    \u3059\u308B.\u305D\u306E\u969B,\u767A\u751F\u3059\u308B\u5DEE\u5206\u3092 add,\
    \ del \u95A2\u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///        \u3053\u306E\
    \u95A2\u6570\u306F,\u6307\u5B9A\u3055\u308C\u305F\u533A\u9593 [l, r) \u3068\u91CD\
    \u306A\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u524A\u9664\u3057,\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u65E2\u5B58\u306E\u533A\u9593\u3092\u5206\u5272\u3059\
    \u308B.\n    /// @param l \u5DE6\u7AEF (\u524A\u9664\u3059\u308B\u533A\u9593\u306E\
    \u5DE6\u7AEF)\n    /// @param r \u53F3\u7AEF (\u524A\u9664\u3059\u308B\u533A\u9593\
    \u306E\u53F3\u7AEF)\n    /// @param add \u8FFD\u52A0\u5DEE\u5206\u304C\u767A\u751F\
    \u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\
    \ - \u5206\u5272\u306B\u3088\u308A\u4E00\u90E8\u304C\u6B8B\u308B\u5834\u5408\u306B\
    \u547C\u3070\u308C\u308B\n    /// @param del \u524A\u9664\u5DEE\u5206\u304C\u767A\
    \u751F\u3057\u305F\u5834\u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right,\
    \ V value)\n    template<class ADDFUNC, class DELFUNC>\n    void erase(T l, T\
    \ r, const ADDFUNC &add, const DELFUNC &del) {\n        // \u524A\u9664\u3057\u3088\
    \u3046\u3068\u3057\u3066\u3044\u308B\u533A\u9593 [l, r) \u306E\u958B\u59CB\u70B9\
    \ l \u4EE5\u4E0A\u3067\u6700\u3082\u8FD1\u3044\u533A\u9593\u3092\u898B\u3064\u3051\
    \u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u30C1\u30A7\u30C3\u30AF\u3092\u958B\u59CB\u3059\u308B\
    \u9069\u5207\u306A\u4F4D\u7F6E\u3092\u7279\u5B9A\u3059\u308B.\n        auto it\
    \ = intervals.lower_bound(Node(l, 0, V()));\n\n        // \u65B0\u3057\u3044\u533A\
    \u9593 [l, r) \u3068\u91CD\u306A\u308B\u53EF\u80FD\u6027\u306E\u3042\u308B\u65E2\
    \u5B58\u306E\u533A\u9593\u3092\u5168\u3066\u51E6\u7406\u3059\u308B.\n        //\
    \ it->l <= r \u306F,\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF\u304C\
    \u524A\u9664\u533A\u9593 [l, r) \u306E\u53F3\u7AEF r \u4EE5\u4E0B\u3067\u3042\u308B\
    \u3053\u3068\u3092\u793A\u3059.\n        while (it != intervals.end() && it->l\
    \ < r) { // it->l < r: \u524A\u9664\u533A\u9593\u304C\u73FE\u5728\u306E\u533A\u9593\
    \u3068\u91CD\u306A\u3063\u3066\u3044\u308B\u9593\n            // Case 0: \u73FE\
    \u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF it->l \u304C\u524A\u9664\u533A\u9593\
    \u306E\u53F3\u7AEF r \u3068\u4E00\u81F4\u3059\u308B\u5834\u5408\n            //\
    \ \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\u533A\u9593\u3068\u306E\u91CD\u8907\
    \u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\u30D7\u3092\u629C\u3051\u308B.\n \
    \           if (it->l == r) { break; }\n\n            // Case 1: \u73FE\u5728\u306E\
    \u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u306B\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u308B\u304B,\n            // \u307E\u305F\u306F\
    ,\u524A\u9664\u533A\u9593\u306E\u53F3\u7AEF r \u3067\u7D42\u308F\u308B\u5834\u5408\
    \ (it->r <= r)\n            // \u3053\u306E\u533A\u9593\u306F\u5B8C\u5168\u306B\
    \u524A\u9664\u3055\u308C\u308B.\n            if (it->r <= r) {\n             \
    \   del_update(del, it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\
    \u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n              \
    \  it = intervals.erase(it);\n            } else {\n                // Case 2:\
    \ \u524A\u9664\u533A\u9593 [l, r) \u304C\u73FE\u5728\u306E\u533A\u9593 [it->l,\
    \ it->r) \u306E\u4E00\u90E8\u3068\u91CD\u306A\u308B\u5834\u5408\n            \
    \    // (l <= it->l < r < it->r \u304C\u78BA\u5B9A)\n                // \u73FE\
    \u5728\u306E\u533A\u9593\u306F [it->l, r) \u304C\u524A\u9664\u3055\u308C,[r, it->r)\
    \ \u306E\u90E8\u5206\u304C\u6B8B\u308B\u305F\u3081,\u5206\u5272\u3055\u308C\u308B\
    .\n                Node node = *it;\n                del_update(del, it->l, it->r,\
    \ it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\
    \u5DEE\u5206\u3092\u901A\u77E5)\n                it = intervals.erase(it);\n \
    \               // \u6B8B\u308A\u306E\u533A\u9593 [r, node.r) \u3092\u633F\u5165\
    \u3059\u308B.\n                it = intervals.emplace_hint(it, r, node.r, node.val);\n\
    \                add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                // \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\
    \u533A\u9593\u3068\u306E\u91CD\u8907\u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\
    \u30D7\u3092\u629C\u3051\u308B.\n                break;\n            }\n     \
    \   }\n\n        // \u524A\u9664\u533A\u9593 [l, r) \u306E\u5DE6\u7AEF l \u306E\
    \u3059\u3050\u5DE6\u306B\u3042\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u30C1\
    \u30A7\u30C3\u30AF\u3059\u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u5DE6\
    \u5074\u306E\u65E2\u5B58\u533A\u9593\u304C\u524A\u9664\u533A\u9593\u3068\u91CD\
    \u306A\u308B\u5834\u5408\u306E\u5206\u5272\u3092\u51E6\u7406\u3059\u308B.\n  \
    \      if (it != intervals.begin()) {\n            it = prev(it); // \u5DE6\u5074\
    \u306E\u533A\u9593\u3092\u53D6\u5F97\n            if (l < it->r) { // \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u3068\
    \u91CD\u306A\u308B\u5834\u5408\n                // (it->l < l < it->r \u304C\u78BA\
    \u5B9A)\n                if (r < it->r) {\n                    // \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u3092\
    \u5B8C\u5168\u306B\u542B\u3080\u5834\u5408\n                    // [it->l, l)\
    \ \u3068 [r, it->r) \u306E2\u3064\u306E\u533A\u9593\u306B\u5206\u5272\u3055\u308C\
    \u308B.\n                    // \u307E\u305A [r, it->r) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(next(it), r, it->r, it->val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = prev(it); // \u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u5143\u306B\u623B\u3059\n                }\n                // \u5DE6\
    \u5074\u306E\u533A\u9593\u306E\u5143\u306E\u90E8\u5206 [it->l, it->r) \u3092\u524A\
    \u9664\u3057,\n                // \u65B0\u3057\u3044\u533A\u9593 [node.l, l) \u3092\
    \u633F\u5165\u3059\u308B.\n                Node node = *it;\n                del_update(del,\
    \ it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\
    \u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n                it = intervals.erase(it);\n\
    \                it = intervals.emplace_hint(it, node.l, l, node.val);\n     \
    \           add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\u308C\
    \u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n            }\n        }\n    }\n\n    void erase(const T &l, const\
    \ T &r) {\n        erase(l, r, [](T, T, V){}, [](T, T, V){});\n    }\n\n    constexpr\
    \ size_t size() const { return set_size; }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\n// Reference: https://github.com/drken1215/algorithm/blob/master/DataStructure/intervals_management.cpp\n\
    \ntemplate<typename T, class V = ll>\nclass Interval_Set {\n    struct Node {\n\
    \        T l, r;\n        V val;\n\n        /// @brief \u5024 val \u304C\u7D10\
    \u3065\u3044\u3066\u3044\u308B, \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\u751F\
    \u6210\u3059\u308B.\n        /// @param l \u5DE6\u7AEF\n        /// @param r \u53F3\
    \u7AEF\n        /// @param val \u7D10\u3065\u3051\u308B\u8981\u7D20\n        Node\
    \ (const T &l, const T &r, const V &val): l(l), r(r), val(val) {};\n\n       \
    \ /// @brief p \u306F\u3053\u306E\u53F3\u534A\u958B\u533A\u9593\u306B\u542B\u307E\
    \u308C\u308B\u304B?\n        /// @param p \n        constexpr bool contains(const\
    \ T &p) const { return l <= p && p < r; }\n\n        constexpr bool operator<(const\
    \ Node &rhs) const {\n            if (l != rhs.l) { return l < rhs.l; }\n    \
    \        return r < rhs.r;\n        }\n\n        friend ostream& operator<<(ostream\
    \ &os, const Node &node) {\n            return os << \"([\" << node.l << \", \"\
    \ << node.r << \"): \" << node.val << \")\";\n        }\n    };\n\n    const V\
    \ nil; // \u30C7\u30D5\u30A9\u30EB\u30C8\u5024\n    size_t set_size;\n    set<Node>\
    \ intervals;\n\n    template<class ADDFUNC>\n    void add_update(const ADDFUNC\
    \ &add, const T l, const T r, const V &val) {\n        add(l, r, val);\n     \
    \   set_size += r - l;\n    }\n\n    template<class DELFUNC>\n    void del_update(const\
    \ DELFUNC &del, const T l, const T r, const V &val) {\n        del(l, r, val);\n\
    \        set_size -= r - l;\n    }\n\n    public:\n    Interval_Set(): Interval_Set(V())\
    \ {}\n\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3092 nil \u3068\u3057\u3066\
    , Interval Set \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\u3092\u751F\u6210\u3059\u308B\
    .\n    Interval_Set(const V &nil): nil(nil), set_size(0) {}\n\n    // iterators\n\
    \    constexpr typename set<Node>::iterator begin() { return intervals.begin();\
    \ }\n    constexpr typename set<Node>::iterator end() { return intervals.end();\
    \ }\n\n    /// @brief p \u3092\u542B\u3080\u533A\u9593\u306E\u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u6C42\u3081\u308B (\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F, end() \u304C\u8FD4\u308A\u5024).\n    /// @param p \n    constexpr typename\
    \ set<Node>::iterator get(const T &p) const {\n        auto it = intervals.upper_bound(Node(p,\
    \ numeric_limits<T>::max(), 0));\n        if (it == intervals.begin()) { return\
    \ intervals.end(); }\n\n        // \u3053\u3053\u306B\u6765\u308B it \u306F, p\
    \ \u3092\u542B\u3080\u533A\u9593\u306E\u6B21\u306E\u533A\u9593\u306A\u306E\u3067\
    , 1 \u500B\u623B\u3059.\n        it = prev(it);\n\n        return it->contains(p)\
    \ ? it : intervals.end();\n    }\n\n    /// @brief p \u4EE5\u4E0A\u3067\u3042\u308B\
    \u6700\u5C0F\u306E\u8981\u7D20\u3092\u542B\u3093\u3067\u3044\u308B\u533A\u9593\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ p\n    constexpr typename set<Node>::iterator lower_bound(const T &p) {\n  \
    \      auto it = get(p);\n\n        if (it != intervals.end()) { return it; }\n\
    \        return intervals.upper_bound(Node(p, numeric_limits<T>::max(), 0));\n\
    \    }\n\n    /// @brief p \u3092\u542B\u3080\u304B?\n    /// @param p\n    constexpr\
    \ bool covered(const T &p) {\n        return get(p) != intervals.end();\n    }\n\
    \n    /// @brief \u533A\u9593 [l, r) \u3092\u542B\u3080\u304B?\n    /// @param\
    \ l \n    /// @param r \n    constexpr bool covered(const T &l, const T &r) {\n\
    \        assert(l <= r);\n\n        if (l == r) { return true; }\n\n        auto\
    \ it = get(l);\n        return it != intervals.end() && r <= it->r;\n    }\n\n\
    \    constexpr bool same(const T &p, const T &q) {\n        return covered(p)\
    \ && covered(q) && get(p) == get(q);\n    }\n\n    /// @brief p \u3092\u542B\u3080\
    \u53F3\u534A\u958B\u533A\u9593\u306B\u7D10\u3065\u3044\u3066\u3044\u308B\u5024\
    \u3092\u6C42\u3081\u308B (\u305D\u306E\u3088\u3046\u306A\u53F3\u534A\u958B\u533A\
    \u9593\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F nil \u304C\u8FD4\u308A\
    \u5024)\n    /// @param p \n    constexpr V get_value(const T &p) const {\n  \
    \      auto it = get(p);\n        return it != intervals.end() ? it->val : nil;\n\
    \    }\n\n    V operator[](const T &p) const { return get_value(p); }\n\n    constexpr\
    \ T get_mex(const T &p = 0) {\n        auto it = intervals.upper_bound(Node(p,\
    \ numeric_limits<T>::max(), 0));\n        if (it == intervals.begin()) { return\
    \ p; }\n\n        it = prev(it);\n\n        return it->contains(p) ? it->r : p;\n\
    \    }\n\n    /// @brief val \u304C\u7D10\u3065\u3044\u305F, \u53F3\u534A\u958B\
    \u533A\u9593 [l, r) \u3092\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\
    . \u305D\u306E\u969B, \u767A\u751F\u3059\u308B\u5DEE\u5206\u3092 add, del \u95A2\
    \u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///        \u3053\u306E\u95A2\u6570\
    \u306F,\u65B0\u3057\u3044\u533A\u9593 [l, r) \u3068\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u3092\u9069\u5207\u306B\u51E6\u7406\u3057,\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u533A\u9593\u306E\u7D50\u5408,\u5206\u5272,\u524A\u9664\
    \u3092\u884C\u3046.\n    /// @param l \u5DE6\u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\
    \u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\u5DE6\u7AEF)\n    /// @param r \u53F3\
    \u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\
    \u53F3\u7AEF)\n    /// @param val \u53F3\u534A\u958B\u533A\u9593\u306B\u7D10\u3065\
    \u3051\u308B\u5024\n    /// @param add \u8FFD\u52A0\u5DEE\u5206\u304C\u767A\u751F\
    \u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\n\
    \    /// @param del \u524A\u9664\u5DEE\u5206\u304C\u767A\u751F\u3057\u305F\u5834\
    \u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\n    template<class\
    \ ADDFUNC, class DELFUNC>\n    void update(T l, T r, const V &val, const ADDFUNC\
    \ &add, const DELFUNC &del) {\n        // \u65B0\u3057\u304F\u8FFD\u52A0\u307E\
    \u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593 [l, r) \u306E\u958B\u59CB\u70B9\
    \ l \u4EE5\u4E0A\u3067\u6700\u3082\u8FD1\u3044\u533A\u9593\u3092\u898B\u3064\u3051\
    \u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u30C1\u30A7\u30C3\u30AF\u3092\u958B\u59CB\u3059\u308B\
    \u9069\u5207\u306A\u4F4D\u7F6E\u3092\u7279\u5B9A\u3059\u308B.\n        auto it\
    \ = intervals.lower_bound(Node(l, 0, val));\n\n        // \u65B0\u3057\u3044\u533A\
    \u9593 [l, r) \u3068\u91CD\u306A\u308B\u53EF\u80FD\u6027\u306E\u3042\u308B\u65E2\
    \u5B58\u306E\u533A\u9593\u3092\u5168\u3066\u51E6\u7406\u3059\u308B.\n        //\
    \ it->l <= r \u306F,\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF\u304C\
    \u65B0\u3057\u3044\u533A\u9593 [l, r) \u306E\u53F3\u7AEF r \u4EE5\u4E0B\u3067\u3042\
    \u308B\u3053\u3068\u3092\u793A\u3059.\n        while (it != intervals.end() &&\
    \ it->l <= r) {\n            // Case 0: \u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\
    \u7AEF r \u304C\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF it->l \u3068\
    \u4E00\u81F4\u3059\u308B\u5834\u5408\n            // \u304B\u3064,\u5024\u3082\
    \u540C\u3058\u5834\u5408\u306F\u533A\u9593\u3092\u7D50\u5408\u3059\u308B.\n  \
    \          // \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\u533A\u9593\u3068\u306E\
    \u91CD\u8907\u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\u30D7\u3092\u629C\u3051\
    \u308B.\n            if (r == it->l) {\n                if (it->val == val) {\n\
    \                    r = it->r; // \u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF\
    \u3092\u62E1\u5F35\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \       }\n                break;\n            }\n\n            // Case 1: \u73FE\
    \u5728\u306E\u533A\u9593 [it->l, it->r) \u304C\u65B0\u3057\u3044\u533A\u9593 [l,\
    \ r) \u306B\u5B8C\u5168\u306B\u542B\u307E\u308C\u308B\u304B,\n            // \u307E\
    \u305F\u306F,\u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF r \u3067\u7D42\u308F\
    \u308B\u5834\u5408 (it->r <= r)\n            // \u3053\u306E\u533A\u9593\u306F\
    \u65B0\u3057\u3044\u533A\u9593\u306B\u4E0A\u66F8\u304D\u3055\u308C\u308B\u305F\
    \u3081,\u524A\u9664\u3059\u308B.\n            if (it->r <= r) {\n            \
    \    del_update(del, it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\
    \u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n        \
    \        it = intervals.erase(it);\n            } else {\n                // Case\
    \ 2: \u65B0\u3057\u3044\u533A\u9593 [l, r) \u304C\u73FE\u5728\u306E\u533A\u9593\
    \ [it->l, it->r) \u306E\u4E00\u90E8\u3068\u91CD\u306A\u308B\u5834\u5408\n    \
    \            // (l <= it->l < r < it->r \u304C\u78BA\u5B9A)\n                if\
    \ (it->val == val) {\n                    // \u5024\u304C\u540C\u3058\u5834\u5408\
    \u306F,\u65B0\u3057\u3044\u533A\u9593\u3068\u73FE\u5728\u306E\u533A\u9593\u3092\
    \u7D50\u5408\u3057,\u65B0\u3057\u3044\u533A\u9593\u306E\u53F3\u7AEF\u3092\u62E1\
    \u5F35\u3059\u308B.\n                    // \u65E2\u5B58\u533A\u9593\u306F\u524A\
    \u9664\u3055\u308C\u308B.\n                    r = it->r; // \u65B0\u3057\u3044\
    \u533A\u9593\u306E\u53F3\u7AEF\u3092\u62E1\u5F35\n                    del_update(del,\
    \ it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\
    \u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n\
    \                } else {\n                    // \u5024\u304C\u7570\u306A\u308B\
    \u5834\u5408\u306F,\u73FE\u5728\u306E\u533A\u9593 [it->l, it->r) \u3092\u65B0\u3057\
    \u3044\u533A\u9593\u306B\u3088\u3063\u3066\u4E8C\u5206\u5272\u3059\u308B.\n  \
    \                  // [it->l, r) \u306E\u90E8\u5206\u306F\u65B0\u3057\u3044\u533A\
    \u9593\u306B\u3088\u3063\u3066\u4E0A\u66F8\u304D\u3055\u308C\u308B\u305F\u3081\
    ,[r, it->r) \u306E\u90E8\u5206\u306E\u307F\u304C\u6B8B\u308B.\n              \
    \      Node node = *it;\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \           // \u6B8B\u308A\u306E\u533A\u9593 [r, node.r) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(it, r, node.r, node.val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                }\n            }\n        }\n\n        //\
    \ \u65B0\u3057\u3044\u533A\u9593 [l, r) \u306E\u5DE6\u7AEF l \u306E\u3059\u3050\
    \u5DE6\u306B\u3042\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u30C1\u30A7\u30C3\
    \u30AF\u3059\u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65B0\u3057\u3044\
    \u533A\u9593\u3068\u5DE6\u5074\u306E\u65E2\u5B58\u533A\u9593\u306E\u7D50\u5408\
    \u3084\u5206\u5272\u3092\u51E6\u7406\u3059\u308B.\n        if (it != intervals.begin())\
    \ {\n            it = prev(it); // \u5DE6\u5074\u306E\u533A\u9593\u3092\u53D6\u5F97\
    \n            // Case 3: \u5DE6\u5074\u306E\u533A\u9593 [it->l, it->r) \u306E\u53F3\
    \u7AEF it->r \u304C\u65B0\u3057\u3044\u533A\u9593\u306E\u5DE6\u7AEF l \u3068\u4E00\
    \u81F4\u3059\u308B\u5834\u5408\n            if (it->r == l) {\n              \
    \  if (it->val == val) {\n                    // \u5024\u304C\u540C\u3058\u5834\
    \u5408\u306F,\u4E21\u533A\u9593\u3092\u7D50\u5408\u3057,\u65B0\u3057\u3044\u533A\
    \u9593\u306E\u5DE6\u7AEF\u3092\u62E1\u5F35\u3059\u308B.\n                    l\
    \ = it->l;\n                    del_update(del, it->l, it->r, it->val); // \u65E2\
    \u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n                    it = intervals.erase(it);\n               \
    \ }\n            } else if (l < it->r) {\n                // Case 4: \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u65B0\u3057\u3044\u533A\u9593 [l, r)\
    \ \u3068\u91CD\u306A\u308B\u5834\u5408\n                // (it->l < l < it->r\
    \ \u304C\u78BA\u5B9A)\n                if (it->val == val) {\n               \
    \     // \u5024\u304C\u540C\u3058\u5834\u5408\u306F,\u4E21\u533A\u9593\u3092\u7D50\
    \u5408\u3057,\u65B0\u3057\u3044\u533A\u9593\u306E\u7BC4\u56F2\u3092\u62E1\u5F35\
    \u3059\u308B.\n                    l = min(l, it->l);\n                    r =\
    \ max(r, it->r);\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \       } else {\n                    // \u5024\u304C\u7570\u306A\u308B\u5834\u5408\
    \u306F,\u5DE6\u5074\u306E\u533A\u9593 [it->l, it->r) \u3092\u65B0\u3057\u3044\u533A\
    \u9593\u306B\u3088\u3063\u3066\u4E8C\u5206\u5272\u3059\u308B.\n              \
    \      // [it->l, l) \u306E\u90E8\u5206\u3068 [l, it->r) \u306E\u90E8\u5206\u306B\
    \u5206\u3051\u3089\u308C,\n                    // \u5F8C\u8005\u306F\u65B0\u3057\
    \u3044\u533A\u9593\u306B\u3088\u3063\u3066\u4E0A\u66F8\u304D\u3055\u308C\u308B\
    \u305F\u3081,[it->l, l) \u306E\u90E8\u5206\u306E\u307F\u304C\u6B8B\u308B.\n  \
    \                  if (r < it->r) { // \u65B0\u3057\u3044\u533A\u9593\u304C\u5DE6\
    \u5074\u306E\u533A\u9593\u306E\u4E00\u90E8\u3092\u30AB\u30D0\u30FC\u3059\u308B\
    \u5834\u5408\n                        // \u5DE6\u5074\u306E\u533A\u9593\u306E\u6B8B\
    \u308A\u306E\u90E8\u5206 [r, it->r) \u3092\u633F\u5165\n                     \
    \   it = intervals.emplace_hint(next(it), r, it->r, it->val);\n              \
    \          add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\u308C\
    \u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n                        it = prev(it); // \u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u5143\u306B\u623B\u3059\n                    }\n                \
    \    Node node = *it;\n                    del_update(del, it->l, it->r, it->val);\
    \ // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = intervals.erase(it);\n         \
    \           // \u6B8B\u308A\u306E\u533A\u9593 [node.l, l) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(it, node.l, l, node.val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                }\n            }\n        }\n\n        //\
    \ \u9069\u5207\u306A\u4F4D\u7F6E\u306B\u30A4\u30C6\u30EC\u30FC\u30BF\u3092\u8ABF\
    \u6574\u3059\u308B.\n        if (it != intervals.end()) { it = next(it); }\n\n\
    \        // \u6700\u7D42\u7684\u306B\u78BA\u5B9A\u3057\u305F\u65B0\u3057\u3044\
    \u533A\u9593 [l, r) \u3092\u633F\u5165\u3059\u308B.\n        it = intervals.emplace_hint(it,\
    \ l, r, val);\n        add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\
    \u3055\u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\
    \u5206\u3092\u901A\u77E5)\n    }\n\n    void update(const T &l, const T &r, const\
    \ V &val) {\n        update(l, r, val, [](T, T, V){}, [](T, T, V){});\n    }\n\
    \n    /// @brief \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\u8FFD\u52A0\u307E\
    \u305F\u306F\u66F4\u65B0\u3059\u308B. \u305D\u306E\u969B, \u767A\u751F\u3059\u308B\
    \u5DEE\u5206\u3092 add, del \u95A2\u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///\
    \        \u3053\u306E\u95A2\u6570\u306F,\u65B0\u3057\u3044\u533A\u9593 [l, r)\
    \ \u3068\u65E2\u5B58\u306E\u533A\u9593\u3068\u306E\u91CD\u8907\u3092\u9069\u5207\
    \u306B\u51E6\u7406\u3057,\u5FC5\u8981\u306B\u5FDC\u3058\u3066\u533A\u9593\u306E\
    \u7D50\u5408,\u5206\u5272,\u524A\u9664\u3092\u884C\u3046.\n    /// @param l \u5DE6\
    \u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\u65B0\u3059\u308B\u533A\u9593\u306E\
    \u5DE6\u7AEF)\n    /// @param r \u53F3\u7AEF (\u8FFD\u52A0\u307E\u305F\u306F\u66F4\
    \u65B0\u3059\u308B\u533A\u9593\u306E\u53F3\u7AEF)\n    /// @param add \u8FFD\u52A0\
    \u5DEE\u5206\u304C\u767A\u751F\u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570\
    : T left, T right, V value)\n    /// @param del \u524A\u9664\u5DEE\u5206\u304C\
    \u767A\u751F\u3057\u305F\u5834\u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left,\
    \ T right, V value)\n    template<class ADDFUNC, class DELFUNC>\n    void insert(T\
    \ l, T r, const ADDFUNC &add, const DELFUNC &del) {\n        update(l, r, V(),\
    \ add, del);\n    }\n\n    /// @brief \u53F3\u534A\u958B\u533A\u9593 [l, r) \u3092\
    \u633F\u5165\u3059\u308B.\n    /// @param l \u5DE6\u7AEF\n    /// @param r \u53F3\
    \u7AEF\n    void insert(const T &l, const T &r) {\n        update(l, r, V(), [](T,\
    \ T, V){}, [](T, T, V){});\n    }\n\n    /// @brief \u53F3\u534A\u958B\u533A\u9593\
    \ [l, r) \u3068\u91CD\u306A\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u524A\u9664\
    \u3059\u308B.\u305D\u306E\u969B,\u767A\u751F\u3059\u308B\u5DEE\u5206\u3092 add,\
    \ del \u95A2\u6570\u3067\u51E6\u7406\u3059\u308B.\n    ///        \u3053\u306E\
    \u95A2\u6570\u306F,\u6307\u5B9A\u3055\u308C\u305F\u533A\u9593 [l, r) \u3068\u91CD\
    \u306A\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u524A\u9664\u3057,\u5FC5\u8981\
    \u306B\u5FDC\u3058\u3066\u65E2\u5B58\u306E\u533A\u9593\u3092\u5206\u5272\u3059\
    \u308B.\n    /// @param l \u5DE6\u7AEF (\u524A\u9664\u3059\u308B\u533A\u9593\u306E\
    \u5DE6\u7AEF)\n    /// @param r \u53F3\u7AEF (\u524A\u9664\u3059\u308B\u533A\u9593\
    \u306E\u53F3\u7AEF)\n    /// @param add \u8FFD\u52A0\u5DEE\u5206\u304C\u767A\u751F\
    \u3057\u305F\u969B\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right, V value)\
    \ - \u5206\u5272\u306B\u3088\u308A\u4E00\u90E8\u304C\u6B8B\u308B\u5834\u5408\u306B\
    \u547C\u3070\u308C\u308B\n    /// @param del \u524A\u9664\u5DEE\u5206\u304C\u767A\
    \u751F\u3057\u305F\u5834\u5408\u306E\u51E6\u7406 (\u5F15\u6570: T left, T right,\
    \ V value)\n    template<class ADDFUNC, class DELFUNC>\n    void erase(T l, T\
    \ r, const ADDFUNC &add, const DELFUNC &del) {\n        // \u524A\u9664\u3057\u3088\
    \u3046\u3068\u3057\u3066\u3044\u308B\u533A\u9593 [l, r) \u306E\u958B\u59CB\u70B9\
    \ l \u4EE5\u4E0A\u3067\u6700\u3082\u8FD1\u3044\u533A\u9593\u3092\u898B\u3064\u3051\
    \u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u65E2\u5B58\u306E\u533A\u9593\
    \u3068\u306E\u91CD\u8907\u30C1\u30A7\u30C3\u30AF\u3092\u958B\u59CB\u3059\u308B\
    \u9069\u5207\u306A\u4F4D\u7F6E\u3092\u7279\u5B9A\u3059\u308B.\n        auto it\
    \ = intervals.lower_bound(Node(l, 0, V()));\n\n        // \u65B0\u3057\u3044\u533A\
    \u9593 [l, r) \u3068\u91CD\u306A\u308B\u53EF\u80FD\u6027\u306E\u3042\u308B\u65E2\
    \u5B58\u306E\u533A\u9593\u3092\u5168\u3066\u51E6\u7406\u3059\u308B.\n        //\
    \ it->l <= r \u306F,\u73FE\u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF\u304C\
    \u524A\u9664\u533A\u9593 [l, r) \u306E\u53F3\u7AEF r \u4EE5\u4E0B\u3067\u3042\u308B\
    \u3053\u3068\u3092\u793A\u3059.\n        while (it != intervals.end() && it->l\
    \ < r) { // it->l < r: \u524A\u9664\u533A\u9593\u304C\u73FE\u5728\u306E\u533A\u9593\
    \u3068\u91CD\u306A\u3063\u3066\u3044\u308B\u9593\n            // Case 0: \u73FE\
    \u5728\u306E\u533A\u9593 it \u306E\u5DE6\u7AEF it->l \u304C\u524A\u9664\u533A\u9593\
    \u306E\u53F3\u7AEF r \u3068\u4E00\u81F4\u3059\u308B\u5834\u5408\n            //\
    \ \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\u533A\u9593\u3068\u306E\u91CD\u8907\
    \u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\u30D7\u3092\u629C\u3051\u308B.\n \
    \           if (it->l == r) { break; }\n\n            // Case 1: \u73FE\u5728\u306E\
    \u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u306B\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u308B\u304B,\n            // \u307E\u305F\u306F\
    ,\u524A\u9664\u533A\u9593\u306E\u53F3\u7AEF r \u3067\u7D42\u308F\u308B\u5834\u5408\
    \ (it->r <= r)\n            // \u3053\u306E\u533A\u9593\u306F\u5B8C\u5168\u306B\
    \u524A\u9664\u3055\u308C\u308B.\n            if (it->r <= r) {\n             \
    \   del_update(del, it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\
    \u9664 (del \u95A2\u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n              \
    \  it = intervals.erase(it);\n            } else {\n                // Case 2:\
    \ \u524A\u9664\u533A\u9593 [l, r) \u304C\u73FE\u5728\u306E\u533A\u9593 [it->l,\
    \ it->r) \u306E\u4E00\u90E8\u3068\u91CD\u306A\u308B\u5834\u5408\n            \
    \    // (l <= it->l < r < it->r \u304C\u78BA\u5B9A)\n                // \u73FE\
    \u5728\u306E\u533A\u9593\u306F [it->l, r) \u304C\u524A\u9664\u3055\u308C,[r, it->r)\
    \ \u306E\u90E8\u5206\u304C\u6B8B\u308B\u305F\u3081,\u5206\u5272\u3055\u308C\u308B\
    .\n                Node node = *it;\n                del_update(del, it->l, it->r,\
    \ it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\u6570\u3067\
    \u5DEE\u5206\u3092\u901A\u77E5)\n                it = intervals.erase(it);\n \
    \               // \u6B8B\u308A\u306E\u533A\u9593 [r, node.r) \u3092\u633F\u5165\
    \u3059\u308B.\n                it = intervals.emplace_hint(it, r, node.r, node.val);\n\
    \                add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                // \u3053\u308C\u4EE5\u4E0A\u53F3\u5074\u306E\
    \u533A\u9593\u3068\u306E\u91CD\u8907\u306F\u306A\u3044\u305F\u3081,\u30EB\u30FC\
    \u30D7\u3092\u629C\u3051\u308B.\n                break;\n            }\n     \
    \   }\n\n        // \u524A\u9664\u533A\u9593 [l, r) \u306E\u5DE6\u7AEF l \u306E\
    \u3059\u3050\u5DE6\u306B\u3042\u308B\u65E2\u5B58\u306E\u533A\u9593\u3092\u30C1\
    \u30A7\u30C3\u30AF\u3059\u308B.\n        // \u3053\u308C\u306B\u3088\u308A,\u5DE6\
    \u5074\u306E\u65E2\u5B58\u533A\u9593\u304C\u524A\u9664\u533A\u9593\u3068\u91CD\
    \u306A\u308B\u5834\u5408\u306E\u5206\u5272\u3092\u51E6\u7406\u3059\u308B.\n  \
    \      if (it != intervals.begin()) {\n            it = prev(it); // \u5DE6\u5074\
    \u306E\u533A\u9593\u3092\u53D6\u5F97\n            if (l < it->r) { // \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u3068\
    \u91CD\u306A\u308B\u5834\u5408\n                // (it->l < l < it->r \u304C\u78BA\
    \u5B9A)\n                if (r < it->r) {\n                    // \u5DE6\u5074\
    \u306E\u533A\u9593 [it->l, it->r) \u304C\u524A\u9664\u533A\u9593 [l, r) \u3092\
    \u5B8C\u5168\u306B\u542B\u3080\u5834\u5408\n                    // [it->l, l)\
    \ \u3068 [r, it->r) \u306E2\u3064\u306E\u533A\u9593\u306B\u5206\u5272\u3055\u308C\
    \u308B.\n                    // \u307E\u305A [r, it->r) \u3092\u633F\u5165\u3059\
    \u308B.\n                    it = intervals.emplace_hint(next(it), r, it->r, it->val);\n\
    \                    add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\
    \u308C\u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\
    \u3092\u901A\u77E5)\n                    it = prev(it); // \u30A4\u30C6\u30EC\u30FC\
    \u30BF\u3092\u5143\u306B\u623B\u3059\n                }\n                // \u5DE6\
    \u5074\u306E\u533A\u9593\u306E\u5143\u306E\u90E8\u5206 [it->l, it->r) \u3092\u524A\
    \u9664\u3057,\n                // \u65B0\u3057\u3044\u533A\u9593 [node.l, l) \u3092\
    \u633F\u5165\u3059\u308B.\n                Node node = *it;\n                del_update(del,\
    \ it->l, it->r, it->val); // \u65E2\u5B58\u533A\u9593\u3092\u524A\u9664 (del \u95A2\
    \u6570\u3067\u5DEE\u5206\u3092\u901A\u77E5)\n                it = intervals.erase(it);\n\
    \                it = intervals.emplace_hint(it, node.l, l, node.val);\n     \
    \           add_update(add, it->l, it->r, it->val); // \u8FFD\u52A0\u3055\u308C\
    \u305F\u533A\u9593\u3092\u901A\u77E5 (add \u95A2\u6570\u3067\u5DEE\u5206\u3092\
    \u901A\u77E5)\n            }\n        }\n    }\n\n    void erase(const T &l, const\
    \ T &r) {\n        erase(l, r, [](T, T, V){}, [](T, T, V){});\n    }\n\n    constexpr\
    \ size_t size() const { return set_size; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Data_Structure/Interval_Set.hpp
  requiredBy: []
  timestamp: '2026-05-17 12:20:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/Interval_Set.hpp
layout: document
title: Interval Set
---

## Outline

区間による一括の挿入や削除及び, それらに付随する処理を高速に行うことができるデータ構造

## Contents

### constructor

```cpp
(1) Interval_Set(): Interval_Set(V()) {}
(2) Interval_Set(const V &nil): nil(nil), set_size(0) {}
```

* デフォルト値を `nil` として, インスタンスを生成する.

### covered

```cpp
(1) constexpr bool covered(const T &p)
(2) constexpr bool covered(const T &l, const T &r)
```

* (1) $p$ を要素に持っているか?
* (2) $[l, r)$ を部分集合になるか?
  * $p = l, l + 1, \dots, r-1$ を全て要素に持っているか? と同値
* **引数**
  * (1)
    * $p$: 要素
  * (2)
    * $l$: 右半開区間の左端
    * $r$: 右半開区間の右端 

### begin / end

```cpp
constexpr typename set<Node>::iterator begin()
constexpr typename set<Node>::iterator end()
```

* 内部で管理している区間集合（`std::set<Node>`）のイテレータを返す.
* イテレータをデリファレンスすることで `Node` オブジェクトが得られ、`it->l` (左端), `it->r` (右端), `it->val` (値) にアクセスできる.

### get

```cpp
constexpr typename set<Node>::iterator get(const T &p) const
```

* 点 $p$ を含む区間のイテレータを求める.
* $p$ を含む区間が存在しない場合は `end()` を返す.

### lower_bound

```cpp
constexpr typename set<Node>::iterator lower_bound(const T &p)
```

* 点 $p$ を含む区間、または $p$ より右側にある最初の区間のイテレータを求める.
* 該当する区間が存在しない場合は `end()` を返す.

### get_value / operator[]

```cpp
constexpr V get_value(const T &p) const
V operator[](const T &p) const
```

* 点 $p$ を含む区間に紐づいている値を求める. $p$ を含む区間が存在しない場合は `nil` を返す.

### same

```cpp
constexpr bool same(const T &p, const T &q)
```

* 点 $p$ と $q$ が同じ区間に属しているかを判定する.

### get_mex

```cpp
constexpr T get_mex(const T &p = 0)
```

* $p$ 以上の値のうち、集合に含まれていない最小の値を求める.

### size

```cpp
constexpr size_t size() const
```

* 集合に含まれる要素の総数（管理されている各区間の長さの合計）を返す.

### update

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void update(T l, T r, const V &val, const ADDFUNC &add, const DELFUNC &del)
(2) void update(const T &l, const T &r, const V &val)
```

* 区間 $[l, r)$ の値を `val` で更新する.
* **引数**
  * `l`, `r`: 更新対象とする右半開区間 $[l, r)$.
  * `val`: 更新後の値.
  * `add`: 内部で新たに区間が生成・追加された際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 追加された区間の左端、右端、およびその値.
  * `del`: 既存の区間が削除、あるいは上書きによって消滅・縮小する際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 削除される直前の区間の左端、右端、およびその値.
* **計算量**: ならし $O(\log N)$ ($N$ は現在の区間数)

### insert

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void insert(T l, T r, const ADDFUNC &add, const DELFUNC &del)
(2) void insert(const T &l, const T &r)
```

* 区間 $[l, r)$ を集合に追加する. 値には `V()` が用いられる.
* 既存の区間と連続または重複する場合、それらは自動的にマージされる.
* **引数**
  * `l`, `r`: 挿入する右半開区間 $[l, r)$.
  * `add`: マージや新規作成によって新たな区間が生成された際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 生成された区間の左端、右端、およびその値 (`V()`).
  * `del`: マージによって既存の区間が消滅する際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 消滅する直前の区間の左端、右端、およびその値.

### erase

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void erase(T l, T r, const ADDFUNC &add, const DELFUNC &del)
(2) void erase(const T &l, const T &r)
```

* 区間 $[l, r)$ を集合から削除する.
* 指定範囲と重なる既存の区間は削除され、必要に応じて端の部分が分割されて残る.
* **引数**
  * `l`, `r`: 削除対象とする右半開区間 $[l, r)$.
  * `add`: 既存の区間が $[l, r)$ によって分割され、一部が残る場合に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 分割されて残った方の区間の左端、右端、およびその値.
  * `del`: 既存の区間（またはその一部）が削除される際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 削除される直前の区間（または分割される前の元区間）の左端、右端、およびその値.
