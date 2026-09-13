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
    document_title: "Trie \u6728\u306B vec \u3092\u633F\u5165\u3059\u308B. \u305F\u3060\
      \u3057, \u633F\u5165\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089."
    links: []
  bundledCode: "#line 2 \"Sequence/Ordered_Trie.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 2 \"template/concepts.hpp\"\n\n// \u5358\u9805\u6F14\u7B97\u5B50\
    \u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate <typename Op, typename X>\nconcept Unary_Operator_Concept\
    \ = requires(Op op, const X &x) {\n    { op(x) } -> std::convertible_to<X>;\n\
    };\n\n// \u4E8C\u9805\u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate\
    \ <typename Op, typename X>\nconcept Binary_Operator_Concept = requires(Op op,const\
    \ X &x, const X &y) {\n    { op(x, y) } -> std::convertible_to<X>;\n};\n\n// \u30E2\
    \u30CE\u30A4\u30C9\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u4E8C\u9805\u6F14\u7B97\
    \ + \u5358\u4F4D\u5143\ntemplate <typename M, auto op, auto identity>\nconcept\
    \ Monoid_Concept = \n    Binary_Operator_Concept<decltype(op), M>\n    && std::convertible_to<decltype(identity),\
    \ M>;\n\n// \u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u30E2\u30CE\u30A4\u30C9\
    \ + \u9006\u5143\ntemplate <typename G, auto op, auto identity, auto inv>\nconcept\
    \ Group_Concept = \n    Monoid_Concept<G, op, identity>\n    && Unary_Operator_Concept<decltype(inv),\
    \ G>;\n\n// \u9806\u5E8F\u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u7FA4 + \u5168\
    \u9806\u5E8F\ntemplate <typename G, auto op, auto identity, auto inv>\nconcept\
    \ Totally_Ordered_Group_Concept = \n    Group_Concept<G, op, identity, inv>\n\
    \    && totally_ordered<G>;\n\n// \u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\u30B3\u30F3\
    \u30BB\u30D7\u30C8\ntemplate<typename T>\nconcept Hashable = requires(T x) {\n\
    \    { hash<T>{}(x) } -> convertible_to<size_t>;\n};\n#line 5 \"Sequence/Ordered_Trie.hpp\"\
    \n\ntemplate<typename T> requires totally_ordered<T>\nclass Ordered_Trie {\n \
    \   struct Node {\n        T item;\n        map<T, Node*> next;\n        size_t\
    \ terminal_count, prefix_count;\n        bool is_root;\n\n        Node(): Node(T())\
    \ {}\n        Node(const T &item, const bool is_root = false): item(item), terminal_count(0),\
    \ prefix_count(0), is_root(is_root) {}\n\n        bool contains(const T &x) const\
    \ { return next.find(x) != next.end(); }\n\n        inline Node* dig(const T x)\
    \ { return contains(x) ? next[x] : nullptr; }\n    };\n\n    public:\n    Node\
    \ *root;\n\n    Ordered_Trie() {\n        root = new Node(T(), true);\n    }\n\
    \n    // insert\n\n    /// @brief Trie \u6728\u306B vec \u3092\u633F\u5165\u3059\
    \u308B. \u305F\u3060\u3057, \u633F\u5165\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node\
    \ \u304B\u3089.\n    /// @param vec\n    /// @param node\n    void insert(const\
    \ vector<T> &vec, Node *node) {\n        node->prefix_count++;\n        for (T\
    \ x: vec) {\n            if (!node->contains(x)) {\n                node->next[x]\
    \ = new Node(x);\n            }\n\n            node = node->next[x];\n       \
    \     node->prefix_count++;\n        }\n\n        node->terminal_count++;\n  \
    \  }\n\n    /// @brief Trie \u6728\u306B vec \u3092\u633F\u5165\u3059\u308B.\n\
    \    /// @param vec\n    void insert(const vector<T> &vec) { insert(vec, root);\
    \ }\n\n    // erase\n\n    /// @brief Trie \u6728\u304B\u3089 vec \u3092\u524A\
    \u9664\u3059\u308B. \u305F\u3060\u3057, \u524A\u9664\u306E\u958B\u59CB\u4F4D\u7F6E\
    \u306F node \u304B\u3089. \u767B\u9332\u3055\u308C\u3066\u3044\u306A\u3051\u308C\
    \u3070\u4F55\u3082\u305B\u305A false \u3092\u8FD4\u3059.\n    /// @param vec\n\
    \    /// @param node\n    bool erase(const vector<T> &vec, Node *node) {\n   \
    \     if (count(vec, node) == 0) { return false; }\n\n        vector<Node*> path\
    \ = {node};\n        for (const T &x: vec) {\n            node = node->next[x];\n\
    \            path.emplace_back(node);\n        }\n\n        node->terminal_count--;\n\
    \        for (Node *node: path) { node->prefix_count--; }\n\n        for (size_t\
    \ i = path.size() - 1; i >= 1; i--) {\n            Node *cur = path[i];\n    \
    \        Node *par = path[i - 1];\n            if (cur->prefix_count > 0) { break;\
    \ }\n\n            par->next.erase(cur->item);\n            delete cur;\n    \
    \    }\n\n        return true;\n    }\n\n    /// @brief Trie \u6728\u304B\u3089\
    \ vec \u3092\u524A\u9664\u3059\u308B. \u767B\u9332\u3055\u308C\u3066\u3044\u306A\
    \u3051\u308C\u3070\u4F55\u3082\u305B\u305A false \u3092\u8FD4\u3059.\n    ///\
    \ @param vec\n    bool erase(const vector<T> &vec) { return erase(vec, root);\
    \ }\n\n    // discard\n\n    /// @brief Trie \u6728\u306B\u767B\u9332\u3055\u308C\
    \u3066\u3044\u308B vec \u3092\u3059\u3079\u3066\u524A\u9664\u3059\u308B. \u305F\
    \u3060\u3057, \u524A\u9664\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089\
    .\n    /// @param vec\n    /// @param node\n    /// @return \u524A\u9664\u3057\
    \u305F\u500B\u6570.\n    size_t discard(const vector<T> &vec, Node *node) {\n\
    \        Node *final_node = get(vec, node);\n        if (final_node == nullptr\
    \ || final_node->terminal_count == 0) { return 0; }\n\n        const size_t cnt\
    \ = final_node->terminal_count;\n\n        vector<Node*> path = {node};\n    \
    \    for (const T &x: vec) {\n            node = node->next[x];\n            path.emplace_back(node);\n\
    \        }\n\n        node->terminal_count = 0;\n        for (Node *n: path) {\
    \ n->prefix_count -= cnt; }\n\n        for (size_t i = path.size() - 1; i >= 1;\
    \ i--) {\n            Node *cur = path[i];\n            Node *par = path[i - 1];\n\
    \            if (cur->prefix_count > 0) { break; }\n\n            par->next.erase(cur->item);\n\
    \            delete cur;\n        }\n\n        return cnt;\n    }\n\n    /// @brief\
    \ Trie \u6728\u306B\u767B\u9332\u3055\u308C\u3066\u3044\u308B vec \u3092\u3059\
    \u3079\u3066\u524A\u9664\u3059\u308B.\n    /// @param vec\n    /// @return \u524A\
    \u9664\u3057\u305F\u500B\u6570.\n    size_t discard(const vector<T> &vec) { return\
    \ discard(vec, root); }\n\n    // count\n\n    /// @brief Trie \u6728\u306B\u767B\
    \u9332\u3055\u308C\u3066\u3044\u308B vec \u306E\u6570\u3092\u6C42\u3081\u308B\
    . \u305F\u3060\u3057, \u691C\u7D22\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\
    \u3089.\n    /// @param vec\n    /// @param node\n    size_t count(const vector<T>\
    \ &vec, Node *node) {\n        Node *final_node = get(vec, node);\n        return\
    \ final_node != nullptr ? final_node->terminal_count : 0;\n    }\n\n    size_t\
    \ count(const vector<T> &vec) { return count(vec, root); }\n\n    // count_prefixing\n\
    \    size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true)\
    \ {\n        Node *final_node = get(vec, node);\n        if (final_node == nullptr)\
    \ { return 0; }\n\n        return equal ? node->prefix_count : node->prefix_count\
    \ - node->terminal_count;\n    }\n\n    size_t count_prefixing(const vector<T>\
    \ &vec, bool equal = true) { return count_prefixing(vec, root, equal); }\n\n \
    \   // count_prefixed\n    size_t count_prefixed(const vector<T> &vec, Node *node,\
    \ bool equal = true) {\n        size_t res = node->terminal_count;\n        for\
    \ (T x: vec) {\n            if(!node->contains(x)) { return res; }\n\n       \
    \     node = node->next[x];\n            res += node->terminal_count;\n      \
    \  }\n\n        return equal ? res : res - node->terminal_count;\n    }\n\n  \
    \  size_t count_prefixed(const vector<T> &vec, bool equal = true) { return count_prefixed(vec,\
    \ root, equal); }\n\n    // contains\n    bool contains(const vector<T> &vec,\
    \ Node *node) { return count(vec, node) > 0; }\n    bool contains(const vector<T>\
    \ &vec) { return contains(vec, root); }\n\n    // search\n    bool search(const\
    \ vector<T> &vec, Node *node) { return contains(vec, node); }\n    bool search(const\
    \ vector<T> &vec) { return search(vec, root); }\n\n    // search_prefixing\n \
    \   bool search_prefixing(const vector<T> &vec, Node *node) { return count_prefixing(vec,\
    \ node) > 0; }\n    bool search_prefixing(const vector<T> &vec) { return search_prefixing(vec,\
    \ root); }\n\n    // search_prefixed\n    bool search_prefixed(const vector<T>\
    \ &vec, Node *node) { return count_prefixed(vec, node) > 0; }\n    bool search_prefixed(const\
    \ vector<T> &vec) { return search_prefixed(vec, root); }\n\n    Node* get_root()\
    \ { return root; }\n    Node* get(const vector<T> &vec, Node *node) {\n      \
    \  for (T x: vec) {\n            node = node->dig(x);\n            if (node ==\
    \ nullptr) { break; }\n        }\n\n        return node;\n    }\n\n    Node* get(const\
    \ vector<T> &vec) { return get(vec, root); }\n\n    // size\n    size_t size()\
    \ const { return root->prefix_count; }\n\n    // order statistics\n\n    /// @brief\
    \ \u8F9E\u66F8\u9806\u3067 node \u4EE5\u4E0B k \u756A\u76EE (0-indexed) \u306B\
    \u5C0F\u3055\u3044\u5217\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, node \u304B\
    \u3089\u306E\u76F8\u5BFE\u9806\u4F4D\u3067\u6570\u3048\u308B.\n    /// @param\
    \ k\n    /// @param node\n    vector<T> find_by_order(size_t k, Node *node) {\n\
    \        assert(k < node->prefix_count);\n\n        vector<T> res;\n        while\
    \ (true) {\n            if (k < node->terminal_count) { return res; }\n      \
    \      k -= node->terminal_count;\n\n            for (const auto &[x, child]:\
    \ node->next) {\n                if (k < child->prefix_count) {\n            \
    \        res.emplace_back(x);\n                    node = child;\n           \
    \         goto next_node;\n                }\n\n                k -= child->prefix_count;\n\
    \            }\n\n            assert(false);\n            next_node:;\n      \
    \  }\n    }\n\n    /// @brief \u8F9E\u66F8\u9806\u3067 k \u756A\u76EE (0-indexed)\
    \ \u306B\u5C0F\u3055\u3044\u5217\u3092\u6C42\u3081\u308B.\n    /// @param k\n\
    \    vector<T> find_by_order(size_t k) { return find_by_order(k, root); }\n\n\
    \    /// @brief vec \u3088\u308A\u771F\u306B\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\
    \u3044\u5217\u306E\u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\
    \u7D22\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param\
    \ vec\n    /// @param node\n    size_t order_of_key(const vector<T> &vec, Node\
    \ *node) {\n        size_t res = 0;\n        for (const T &x: vec) {\n       \
    \     res += node->terminal_count;\n\n            for (auto it = node->next.begin();\
    \ it != node->next.end() && it->first < x; ++it) {\n                res += it->second->prefix_count;\n\
    \            }\n\n            if (!node->contains(x)) { return res; }\n      \
    \      node = node->next[x];\n        }\n\n        return res;\n    }\n\n    ///\
    \ @brief vec \u3088\u308A\u771F\u306B\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\
    \u5217\u306E\u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    size_t\
    \ order_of_key(const vector<T> &vec) { return order_of_key(vec, root); }\n\n \
    \   /// @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u5217\
    \u306E\u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\u7D22\u306E\
    \u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param vec\n    ///\
    \ @param node\n    /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\
    \u7B49\u3057\u3044\u5217\u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t\
    \ count_less(const vector<T> &vec, Node *node, bool equal = false) {\n       \
    \ return order_of_key(vec, node) + (equal ? count(vec, node) : 0);\n    }\n\n\
    \    /// @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u5217\
    \u306E\u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param\
    \ equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\u3057\u3044\u5217\
    \u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_less(const vector<T>\
    \ &vec, bool equal = false) { return count_less(vec, root, equal); }\n\n    ///\
    \ @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u5217\u306E\
    \u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\u7D22\u306E\u958B\
    \u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param vec\n    /// @param\
    \ node\n    /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\
    \u3057\u3044\u5217\u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_more(const\
    \ vector<T> &vec, Node *node, bool equal = false) {\n        return node->prefix_count\
    \ - order_of_key(vec, node) - (equal ? 0 : count(vec, node));\n    }\n\n    ///\
    \ @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u5217\u306E\
    \u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param equal\
    \ true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\u3057\u3044\u5217\u3082\
    \u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_more(const vector<T> &vec,\
    \ bool equal = false) { return count_more(vec, root, equal); }\n\n    /// @brief\
    \ \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\u8F9E\u66F8\
    \u9806\u6700\u5C0F\u306E\u5217\u3092\u6C42\u3081\u308B.\n    optional<vector<T>>\
    \ min() {\n        if (root->prefix_count == 0) { return nullopt; }\n\n      \
    \  Node *node = root;\n        vector<T> res;\n        while (node->terminal_count\
    \ == 0) {\n            auto it = node->next.begin();\n            res.emplace_back(it->first);\n\
    \            node = it->second;\n        }\n\n        return res;\n    }\n\n \
    \   /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\
    \u8F9E\u66F8\u9806\u6700\u5927\u306E\u5217\u3092\u6C42\u3081\u308B.\n    optional<vector<T>>\
    \ max() {\n        if (root->prefix_count == 0) { return nullopt; }\n\n      \
    \  Node *node = root;\n        vector<T> res;\n        while (!node->next.empty())\
    \ {\n            auto it = node->next.rbegin();\n            res.emplace_back(it->first);\n\
    \            node = it->second;\n        }\n\n        return res;\n    }\n\n \
    \   /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\
    \ vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u6700\u5C0F\u306E\
    \u5217 (successor) \u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param\
    \ equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3082\u5019\u88DC\u306B\u542B\
    \u3081\u308B (vec \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5217\u3092\u6C42\u3081\
    \u308B).\n    optional<vector<T>> next(const vector<T> &vec, bool equal = false)\
    \ {\n        size_t idx = order_of_key(vec) + (equal ? 0 : count(vec));\n    \
    \    if (idx >= size()) { return nullopt; }\n\n        return find_by_order(idx);\n\
    \    }\n\n    /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\
    \u4E2D\u3067 vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u6700\u5927\
    \u306E\u5217 (predecessor) \u3092\u6C42\u3081\u308B.\n    /// @param vec\n   \
    \ /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3082\u5019\u88DC\u306B\
    \u542B\u3081\u308B (vec \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u5217\u3092\u6C42\
    \u3081\u308B).\n    optional<vector<T>> prev(const vector<T> &vec, bool equal\
    \ = false) {\n        size_t idx = order_of_key(vec) + (equal ? count(vec) : 0);\n\
    \        if (idx == 0) { return nullopt; }\n\n        return find_by_order(idx\
    \ - 1);\n    }\n\n    // for string\n    void insert(const string &str, Node *node)\
    \ { insert(vector<char>(str.begin(), str.end()), node); }\n    void insert(const\
    \ string &str) { insert(str, root); }\n\n    bool erase(const string &str, Node\
    \ *node) { return erase(vector<char>(str.begin(), str.end()), node); }\n    bool\
    \ erase(const string &str) { return erase(str, root); }\n\n    size_t discard(const\
    \ string &str, Node *node) { return discard(vector<char>(str.begin(), str.end()),\
    \ node); }\n    size_t discard(const string &str) { return discard(str, root);\
    \ }\n\n    size_t count(const string &str, Node *node) { return count(vector<char>(str.begin(),\
    \ str.end()), node); }\n    size_t count(const string &str) { return count(str,\
    \ root); }\n\n    size_t count_prefixing(const string &str, Node *node) { return\
    \ count_prefixing(vector<char>(str.begin(), str.end()), node); }\n    size_t count_prefixing(const\
    \ string &str) { return count_prefixing(str, root); }\n\n    size_t count_prefixed(const\
    \ string &str, Node *node) { return count_prefixed(vector<char>(str.begin(), str.end()),\
    \ node); }\n    size_t count_prefixed(const string &str) { return count_prefixed(str,\
    \ root); }\n\n    bool contains(const string &str, Node *node) { return contains(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool contains(const string &str) { return contains(str,\
    \ root); }\n\n    bool search(const string &str, Node *node) { return search(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool search(const string &str) { return search(str,\
    \ root); }\n\n    bool search_prefixing(const string &str, Node *node) { return\
    \ search_prefixing(vector<char>(str.begin(), str.end()), node); }\n    bool search_prefixing(const\
    \ string &str) { return search_prefixing(str, root); }\n\n    bool search_prefixed(const\
    \ string &str, Node *node) { return search_prefixed(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool search_prefixed(const string &str) { return search_prefixed(str,\
    \ root); }\n\n    Node* get(const string &str, Node *node) { return get(vector<char>(str.begin(),\
    \ str.end()), node); }\n    Node* get(const string &str) { return get(str, root);\
    \ }\n\n    size_t order_of_key(const string &str, Node *node) { return order_of_key(vector<char>(str.begin(),\
    \ str.end()), node); }\n    size_t order_of_key(const string &str) { return order_of_key(str,\
    \ root); }\n\n    size_t count_less(const string &str, Node *node, bool equal\
    \ = false) { return count_less(vector<char>(str.begin(), str.end()), node, equal);\
    \ }\n    size_t count_less(const string &str, bool equal = false) { return count_less(str,\
    \ root, equal); }\n\n    size_t count_more(const string &str, Node *node, bool\
    \ equal = false) { return count_more(vector<char>(str.begin(), str.end()), node,\
    \ equal); }\n    size_t count_more(const string &str, bool equal = false) { return\
    \ count_more(str, root, equal); }\n\n    optional<vector<char>> next(const string\
    \ &str, bool equal = false) { return next(vector<char>(str.begin(), str.end()),\
    \ equal); }\n    optional<vector<char>> prev(const string &str, bool equal = false)\
    \ { return prev(vector<char>(str.begin(), str.end()), equal); }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../template/concepts.hpp\"\
    \n\ntemplate<typename T> requires totally_ordered<T>\nclass Ordered_Trie {\n \
    \   struct Node {\n        T item;\n        map<T, Node*> next;\n        size_t\
    \ terminal_count, prefix_count;\n        bool is_root;\n\n        Node(): Node(T())\
    \ {}\n        Node(const T &item, const bool is_root = false): item(item), terminal_count(0),\
    \ prefix_count(0), is_root(is_root) {}\n\n        bool contains(const T &x) const\
    \ { return next.find(x) != next.end(); }\n\n        inline Node* dig(const T x)\
    \ { return contains(x) ? next[x] : nullptr; }\n    };\n\n    public:\n    Node\
    \ *root;\n\n    Ordered_Trie() {\n        root = new Node(T(), true);\n    }\n\
    \n    // insert\n\n    /// @brief Trie \u6728\u306B vec \u3092\u633F\u5165\u3059\
    \u308B. \u305F\u3060\u3057, \u633F\u5165\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node\
    \ \u304B\u3089.\n    /// @param vec\n    /// @param node\n    void insert(const\
    \ vector<T> &vec, Node *node) {\n        node->prefix_count++;\n        for (T\
    \ x: vec) {\n            if (!node->contains(x)) {\n                node->next[x]\
    \ = new Node(x);\n            }\n\n            node = node->next[x];\n       \
    \     node->prefix_count++;\n        }\n\n        node->terminal_count++;\n  \
    \  }\n\n    /// @brief Trie \u6728\u306B vec \u3092\u633F\u5165\u3059\u308B.\n\
    \    /// @param vec\n    void insert(const vector<T> &vec) { insert(vec, root);\
    \ }\n\n    // erase\n\n    /// @brief Trie \u6728\u304B\u3089 vec \u3092\u524A\
    \u9664\u3059\u308B. \u305F\u3060\u3057, \u524A\u9664\u306E\u958B\u59CB\u4F4D\u7F6E\
    \u306F node \u304B\u3089. \u767B\u9332\u3055\u308C\u3066\u3044\u306A\u3051\u308C\
    \u3070\u4F55\u3082\u305B\u305A false \u3092\u8FD4\u3059.\n    /// @param vec\n\
    \    /// @param node\n    bool erase(const vector<T> &vec, Node *node) {\n   \
    \     if (count(vec, node) == 0) { return false; }\n\n        vector<Node*> path\
    \ = {node};\n        for (const T &x: vec) {\n            node = node->next[x];\n\
    \            path.emplace_back(node);\n        }\n\n        node->terminal_count--;\n\
    \        for (Node *node: path) { node->prefix_count--; }\n\n        for (size_t\
    \ i = path.size() - 1; i >= 1; i--) {\n            Node *cur = path[i];\n    \
    \        Node *par = path[i - 1];\n            if (cur->prefix_count > 0) { break;\
    \ }\n\n            par->next.erase(cur->item);\n            delete cur;\n    \
    \    }\n\n        return true;\n    }\n\n    /// @brief Trie \u6728\u304B\u3089\
    \ vec \u3092\u524A\u9664\u3059\u308B. \u767B\u9332\u3055\u308C\u3066\u3044\u306A\
    \u3051\u308C\u3070\u4F55\u3082\u305B\u305A false \u3092\u8FD4\u3059.\n    ///\
    \ @param vec\n    bool erase(const vector<T> &vec) { return erase(vec, root);\
    \ }\n\n    // discard\n\n    /// @brief Trie \u6728\u306B\u767B\u9332\u3055\u308C\
    \u3066\u3044\u308B vec \u3092\u3059\u3079\u3066\u524A\u9664\u3059\u308B. \u305F\
    \u3060\u3057, \u524A\u9664\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089\
    .\n    /// @param vec\n    /// @param node\n    /// @return \u524A\u9664\u3057\
    \u305F\u500B\u6570.\n    size_t discard(const vector<T> &vec, Node *node) {\n\
    \        Node *final_node = get(vec, node);\n        if (final_node == nullptr\
    \ || final_node->terminal_count == 0) { return 0; }\n\n        const size_t cnt\
    \ = final_node->terminal_count;\n\n        vector<Node*> path = {node};\n    \
    \    for (const T &x: vec) {\n            node = node->next[x];\n            path.emplace_back(node);\n\
    \        }\n\n        node->terminal_count = 0;\n        for (Node *n: path) {\
    \ n->prefix_count -= cnt; }\n\n        for (size_t i = path.size() - 1; i >= 1;\
    \ i--) {\n            Node *cur = path[i];\n            Node *par = path[i - 1];\n\
    \            if (cur->prefix_count > 0) { break; }\n\n            par->next.erase(cur->item);\n\
    \            delete cur;\n        }\n\n        return cnt;\n    }\n\n    /// @brief\
    \ Trie \u6728\u306B\u767B\u9332\u3055\u308C\u3066\u3044\u308B vec \u3092\u3059\
    \u3079\u3066\u524A\u9664\u3059\u308B.\n    /// @param vec\n    /// @return \u524A\
    \u9664\u3057\u305F\u500B\u6570.\n    size_t discard(const vector<T> &vec) { return\
    \ discard(vec, root); }\n\n    // count\n\n    /// @brief Trie \u6728\u306B\u767B\
    \u9332\u3055\u308C\u3066\u3044\u308B vec \u306E\u6570\u3092\u6C42\u3081\u308B\
    . \u305F\u3060\u3057, \u691C\u7D22\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\
    \u3089.\n    /// @param vec\n    /// @param node\n    size_t count(const vector<T>\
    \ &vec, Node *node) {\n        Node *final_node = get(vec, node);\n        return\
    \ final_node != nullptr ? final_node->terminal_count : 0;\n    }\n\n    size_t\
    \ count(const vector<T> &vec) { return count(vec, root); }\n\n    // count_prefixing\n\
    \    size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true)\
    \ {\n        Node *final_node = get(vec, node);\n        if (final_node == nullptr)\
    \ { return 0; }\n\n        return equal ? node->prefix_count : node->prefix_count\
    \ - node->terminal_count;\n    }\n\n    size_t count_prefixing(const vector<T>\
    \ &vec, bool equal = true) { return count_prefixing(vec, root, equal); }\n\n \
    \   // count_prefixed\n    size_t count_prefixed(const vector<T> &vec, Node *node,\
    \ bool equal = true) {\n        size_t res = node->terminal_count;\n        for\
    \ (T x: vec) {\n            if(!node->contains(x)) { return res; }\n\n       \
    \     node = node->next[x];\n            res += node->terminal_count;\n      \
    \  }\n\n        return equal ? res : res - node->terminal_count;\n    }\n\n  \
    \  size_t count_prefixed(const vector<T> &vec, bool equal = true) { return count_prefixed(vec,\
    \ root, equal); }\n\n    // contains\n    bool contains(const vector<T> &vec,\
    \ Node *node) { return count(vec, node) > 0; }\n    bool contains(const vector<T>\
    \ &vec) { return contains(vec, root); }\n\n    // search\n    bool search(const\
    \ vector<T> &vec, Node *node) { return contains(vec, node); }\n    bool search(const\
    \ vector<T> &vec) { return search(vec, root); }\n\n    // search_prefixing\n \
    \   bool search_prefixing(const vector<T> &vec, Node *node) { return count_prefixing(vec,\
    \ node) > 0; }\n    bool search_prefixing(const vector<T> &vec) { return search_prefixing(vec,\
    \ root); }\n\n    // search_prefixed\n    bool search_prefixed(const vector<T>\
    \ &vec, Node *node) { return count_prefixed(vec, node) > 0; }\n    bool search_prefixed(const\
    \ vector<T> &vec) { return search_prefixed(vec, root); }\n\n    Node* get_root()\
    \ { return root; }\n    Node* get(const vector<T> &vec, Node *node) {\n      \
    \  for (T x: vec) {\n            node = node->dig(x);\n            if (node ==\
    \ nullptr) { break; }\n        }\n\n        return node;\n    }\n\n    Node* get(const\
    \ vector<T> &vec) { return get(vec, root); }\n\n    // size\n    size_t size()\
    \ const { return root->prefix_count; }\n\n    // order statistics\n\n    /// @brief\
    \ \u8F9E\u66F8\u9806\u3067 node \u4EE5\u4E0B k \u756A\u76EE (0-indexed) \u306B\
    \u5C0F\u3055\u3044\u5217\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, node \u304B\
    \u3089\u306E\u76F8\u5BFE\u9806\u4F4D\u3067\u6570\u3048\u308B.\n    /// @param\
    \ k\n    /// @param node\n    vector<T> find_by_order(size_t k, Node *node) {\n\
    \        assert(k < node->prefix_count);\n\n        vector<T> res;\n        while\
    \ (true) {\n            if (k < node->terminal_count) { return res; }\n      \
    \      k -= node->terminal_count;\n\n            for (const auto &[x, child]:\
    \ node->next) {\n                if (k < child->prefix_count) {\n            \
    \        res.emplace_back(x);\n                    node = child;\n           \
    \         goto next_node;\n                }\n\n                k -= child->prefix_count;\n\
    \            }\n\n            assert(false);\n            next_node:;\n      \
    \  }\n    }\n\n    /// @brief \u8F9E\u66F8\u9806\u3067 k \u756A\u76EE (0-indexed)\
    \ \u306B\u5C0F\u3055\u3044\u5217\u3092\u6C42\u3081\u308B.\n    /// @param k\n\
    \    vector<T> find_by_order(size_t k) { return find_by_order(k, root); }\n\n\
    \    /// @brief vec \u3088\u308A\u771F\u306B\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\
    \u3044\u5217\u306E\u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\
    \u7D22\u306E\u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param\
    \ vec\n    /// @param node\n    size_t order_of_key(const vector<T> &vec, Node\
    \ *node) {\n        size_t res = 0;\n        for (const T &x: vec) {\n       \
    \     res += node->terminal_count;\n\n            for (auto it = node->next.begin();\
    \ it != node->next.end() && it->first < x; ++it) {\n                res += it->second->prefix_count;\n\
    \            }\n\n            if (!node->contains(x)) { return res; }\n      \
    \      node = node->next[x];\n        }\n\n        return res;\n    }\n\n    ///\
    \ @brief vec \u3088\u308A\u771F\u306B\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\
    \u5217\u306E\u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    size_t\
    \ order_of_key(const vector<T> &vec) { return order_of_key(vec, root); }\n\n \
    \   /// @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u5217\
    \u306E\u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\u7D22\u306E\
    \u958B\u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param vec\n    ///\
    \ @param node\n    /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\
    \u7B49\u3057\u3044\u5217\u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t\
    \ count_less(const vector<T> &vec, Node *node, bool equal = false) {\n       \
    \ return order_of_key(vec, node) + (equal ? count(vec, node) : 0);\n    }\n\n\
    \    /// @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u5217\
    \u306E\u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param\
    \ equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\u3057\u3044\u5217\
    \u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_less(const vector<T>\
    \ &vec, bool equal = false) { return count_less(vec, root, equal); }\n\n    ///\
    \ @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u5217\u306E\
    \u500B\u6570\u3092\u6C42\u3081\u308B. \u305F\u3060\u3057, \u691C\u7D22\u306E\u958B\
    \u59CB\u4F4D\u7F6E\u306F node \u304B\u3089.\n    /// @param vec\n    /// @param\
    \ node\n    /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\
    \u3057\u3044\u5217\u3082\u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_more(const\
    \ vector<T> &vec, Node *node, bool equal = false) {\n        return node->prefix_count\
    \ - order_of_key(vec, node) - (equal ? 0 : count(vec, node));\n    }\n\n    ///\
    \ @brief vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u5217\u306E\
    \u500B\u6570\u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param equal\
    \ true \u306E\u3068\u304D vec \u81EA\u8EAB\u3068\u7B49\u3057\u3044\u5217\u3082\
    \u500B\u6570\u306B\u542B\u3081\u308B.\n    size_t count_more(const vector<T> &vec,\
    \ bool equal = false) { return count_more(vec, root, equal); }\n\n    /// @brief\
    \ \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\u8F9E\u66F8\
    \u9806\u6700\u5C0F\u306E\u5217\u3092\u6C42\u3081\u308B.\n    optional<vector<T>>\
    \ min() {\n        if (root->prefix_count == 0) { return nullopt; }\n\n      \
    \  Node *node = root;\n        vector<T> res;\n        while (node->terminal_count\
    \ == 0) {\n            auto it = node->next.begin();\n            res.emplace_back(it->first);\n\
    \            node = it->second;\n        }\n\n        return res;\n    }\n\n \
    \   /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\
    \u8F9E\u66F8\u9806\u6700\u5927\u306E\u5217\u3092\u6C42\u3081\u308B.\n    optional<vector<T>>\
    \ max() {\n        if (root->prefix_count == 0) { return nullopt; }\n\n      \
    \  Node *node = root;\n        vector<T> res;\n        while (!node->next.empty())\
    \ {\n            auto it = node->next.rbegin();\n            res.emplace_back(it->first);\n\
    \            node = it->second;\n        }\n\n        return res;\n    }\n\n \
    \   /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\u4E2D\u3067\
    \ vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5927\u304D\u3044\u6700\u5C0F\u306E\
    \u5217 (successor) \u3092\u6C42\u3081\u308B.\n    /// @param vec\n    /// @param\
    \ equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3082\u5019\u88DC\u306B\u542B\
    \u3081\u308B (vec \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5217\u3092\u6C42\u3081\
    \u308B).\n    optional<vector<T>> next(const vector<T> &vec, bool equal = false)\
    \ {\n        size_t idx = order_of_key(vec) + (equal ? 0 : count(vec));\n    \
    \    if (idx >= size()) { return nullopt; }\n\n        return find_by_order(idx);\n\
    \    }\n\n    /// @brief \u767B\u9332\u3055\u308C\u3066\u3044\u308B\u5217\u306E\
    \u4E2D\u3067 vec \u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\u6700\u5927\
    \u306E\u5217 (predecessor) \u3092\u6C42\u3081\u308B.\n    /// @param vec\n   \
    \ /// @param equal true \u306E\u3068\u304D vec \u81EA\u8EAB\u3082\u5019\u88DC\u306B\
    \u542B\u3081\u308B (vec \u4EE5\u4E0B\u3067\u6700\u5927\u306E\u5217\u3092\u6C42\
    \u3081\u308B).\n    optional<vector<T>> prev(const vector<T> &vec, bool equal\
    \ = false) {\n        size_t idx = order_of_key(vec) + (equal ? count(vec) : 0);\n\
    \        if (idx == 0) { return nullopt; }\n\n        return find_by_order(idx\
    \ - 1);\n    }\n\n    // for string\n    void insert(const string &str, Node *node)\
    \ { insert(vector<char>(str.begin(), str.end()), node); }\n    void insert(const\
    \ string &str) { insert(str, root); }\n\n    bool erase(const string &str, Node\
    \ *node) { return erase(vector<char>(str.begin(), str.end()), node); }\n    bool\
    \ erase(const string &str) { return erase(str, root); }\n\n    size_t discard(const\
    \ string &str, Node *node) { return discard(vector<char>(str.begin(), str.end()),\
    \ node); }\n    size_t discard(const string &str) { return discard(str, root);\
    \ }\n\n    size_t count(const string &str, Node *node) { return count(vector<char>(str.begin(),\
    \ str.end()), node); }\n    size_t count(const string &str) { return count(str,\
    \ root); }\n\n    size_t count_prefixing(const string &str, Node *node) { return\
    \ count_prefixing(vector<char>(str.begin(), str.end()), node); }\n    size_t count_prefixing(const\
    \ string &str) { return count_prefixing(str, root); }\n\n    size_t count_prefixed(const\
    \ string &str, Node *node) { return count_prefixed(vector<char>(str.begin(), str.end()),\
    \ node); }\n    size_t count_prefixed(const string &str) { return count_prefixed(str,\
    \ root); }\n\n    bool contains(const string &str, Node *node) { return contains(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool contains(const string &str) { return contains(str,\
    \ root); }\n\n    bool search(const string &str, Node *node) { return search(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool search(const string &str) { return search(str,\
    \ root); }\n\n    bool search_prefixing(const string &str, Node *node) { return\
    \ search_prefixing(vector<char>(str.begin(), str.end()), node); }\n    bool search_prefixing(const\
    \ string &str) { return search_prefixing(str, root); }\n\n    bool search_prefixed(const\
    \ string &str, Node *node) { return search_prefixed(vector<char>(str.begin(),\
    \ str.end()), node); }\n    bool search_prefixed(const string &str) { return search_prefixed(str,\
    \ root); }\n\n    Node* get(const string &str, Node *node) { return get(vector<char>(str.begin(),\
    \ str.end()), node); }\n    Node* get(const string &str) { return get(str, root);\
    \ }\n\n    size_t order_of_key(const string &str, Node *node) { return order_of_key(vector<char>(str.begin(),\
    \ str.end()), node); }\n    size_t order_of_key(const string &str) { return order_of_key(str,\
    \ root); }\n\n    size_t count_less(const string &str, Node *node, bool equal\
    \ = false) { return count_less(vector<char>(str.begin(), str.end()), node, equal);\
    \ }\n    size_t count_less(const string &str, bool equal = false) { return count_less(str,\
    \ root, equal); }\n\n    size_t count_more(const string &str, Node *node, bool\
    \ equal = false) { return count_more(vector<char>(str.begin(), str.end()), node,\
    \ equal); }\n    size_t count_more(const string &str, bool equal = false) { return\
    \ count_more(str, root, equal); }\n\n    optional<vector<char>> next(const string\
    \ &str, bool equal = false) { return next(vector<char>(str.begin(), str.end()),\
    \ equal); }\n    optional<vector<char>> prev(const string &str, bool equal = false)\
    \ { return prev(vector<char>(str.begin(), str.end()), equal); }\n};\n"
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
  path: Sequence/Ordered_Trie.hpp
  requiredBy: []
  timestamp: '2026-09-13 11:40:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Sequence/Ordered_Trie.hpp
layout: document
title: "\u9806\u5E8F\u4ED8\u304D Trie \u6728"
---

## Outline

列の接頭辞に関する検索に加えて, 辞書順に関する計算を高速に行うことができる Trie 木を提供する.

内部で各ノードの子を `std::map` で管理しており, キーの型 $T$ が全順序 (`totally_ordered<T>`) を持つ必要がある.

## Define

$\mathcal{A}$ を全順序の入ったアルファベットとする.

$W_1, W_2, \dots, W_n$ に関する Trie 木とは, 以下で定義される根付き木 $(T, r)~(T = (V, E))$ である.

* $V$ は $W_1, \dots, W_n$ の接頭辞全体 (空文字列も含む) である. つまり,

$$ V = \{ \emptyset \} ~\cup~ \bigcup_{i=1}^n \{ v_{i,j} := w_{i,1} \dots w_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.

* 根 $r$ は空文字列 $\emptyset$ である.
* $T$ における辺は, 長さがちょうど $1$ だけ異なり, 一方が他方の接頭辞になっているとき, そしてそのときに限って結ばれる. つまり,

$$ E := \bigcup_{i=1}^n \{ v_{i,j-1} v_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.

各ノードの子は $\mathcal{A}$ の順序に従って並んでいるため, 木を深さ優先で辿ると登録されている列を辞書順に列挙できる. これを利用して,辞書式順序に関するクエリを高速に計算するメソッドを提供する.

## Contents

以下, $L$ を挿入・削除・検索の対象となる列の長さ, $D$ をノードの子の数 (アルファベットサイズ以下) とする.

### Constructor

```cpp
Ordered_Trie()
```

- 空の Trie 木を作成する.
- **計算量**
  * $O(1)$ Time.

### insert

```cpp
(1) void insert(const vector<T> &vec, Node *node)
(2) void insert(const vector<T> &vec)
```

- Trie 木に `vec` を挿入する.
  * (1) 挿入の開始位置を `node` にする.
  * (2) 挿入の開始位置を根にする.
- **計算量**
  * $O(L \log D)$ Time.

### erase

```cpp
(1) bool erase(const vector<T> &vec, Node *node)
(2) bool erase(const vector<T> &vec)
```

- Trie 木から `vec` を $1$ 個削除する.
  * (1) 削除の開始位置を `node` にする.
  * (2) 削除の開始位置を根にする.
- **返り値**
  * `vec` が登録されていなければ何もせず `false` を返す. 削除できれば `true` を返す.
- **計算量**
  * $O(L \log D)$ Time.

### discard

```cpp
(1) size_t discard(const vector<T> &vec, Node *node)
(2) size_t discard(const vector<T> &vec)
```

- Trie 木に登録されている `vec` をすべて削除する.
  * (1) 削除の開始位置を `node` にする.
  * (2) 削除の開始位置を根にする.
- **返り値**
  * 削除した個数.
- **計算量**
  * $O(L \log D)$ Time.

### count

```cpp
(1) size_t count(const vector<T> &vec, Node *node)
(2) size_t count(const vector<T> &vec)
```

- Trie 木に登録されている `vec` の個数を求める.
  * (1) 検索の開始位置を `node` にする.
  * (2) 検索の開始位置を根にする.
- **計算量**
  * $O(L \log D)$ Time.

### count_prefixing

```cpp
(1) size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true)
(2) size_t count_prefixing(const vector<T> &vec, bool equal = true)
```

- 登録されている列のうち, `vec` の接頭辞になっているものの個数を求める.
  * `equal = false` のとき, `vec` 自身は除いて数える.
- **計算量**
  * $O(L \log D)$ Time.

### count_prefixed

```cpp
(1) size_t count_prefixed(const vector<T> &vec, Node *node, bool equal = true)
(2) size_t count_prefixed(const vector<T> &vec, bool equal = true)
```

- 登録されている列のうち, `vec` を接頭辞に持つものの個数を求める.
  * `equal = false` のとき, `vec` 自身は除いて数える.
- **計算量**
  * $O(L \log D)$ Time.

### contains / search

```cpp
(1) bool contains(const vector<T> &vec, Node *node)
(2) bool contains(const vector<T> &vec)
(3) bool search(const vector<T> &vec, Node *node)
(4) bool search(const vector<T> &vec)
```

- `vec` が登録されているかどうかを判定する. `search` は `contains` のシノニム.
- **計算量**
  * $O(L \log D)$ Time.

### search_prefixing / search_prefixed

```cpp
(1) bool search_prefixing(const vector<T> &vec, Node *node)
(2) bool search_prefixing(const vector<T> &vec)
(3) bool search_prefixed(const vector<T> &vec, Node *node)
(4) bool search_prefixed(const vector<T> &vec)
```

- `search_prefixing` は `vec` の接頭辞になっている列が $1$ つでも登録されているか, `search_prefixed` は `vec` を接頭辞に持つ列が $1$ つでも登録されているかを判定する.
- **計算量**
  * $O(L \log D)$ Time.

### get / get_root

```cpp
(1) Node* get(const vector<T> &vec, Node *node)
(2) Node* get(const vector<T> &vec)
(3) Node* get_root()
```

- `vec` に対応するノードを求める. 途中で辿れなくなった場合は `nullptr` を返す.
  * (3) 根のノードを返す.
- **計算量**
  * $O(L \log D)$ Time.

### size

```cpp
size_t size() const
```

- Trie 木に登録されている列の総数を求める.
- **計算量**
  * $O(1)$ Time.

### find_by_order

```cpp
(1) vector<T> find_by_order(size_t k, Node *node)
(2) vector<T> find_by_order(size_t k)
```

- 辞書順で $k$ 番目 ($0$-indexed) に小さい列を求める.
  * (1) `node` 以下における相対的な順位で数える.
- **制約**
  * $0 \leq k <$ (対象の部分木に登録されている列の総数).
- **計算量**
  * $O(L \log D)$ Time.

### order_of_key

```cpp
(1) size_t order_of_key(const vector<T> &vec, Node *node)
(2) size_t order_of_key(const vector<T> &vec)
```

- `vec` より真に辞書順で小さい列の個数を求める.
  * (1) `node` 以下における相対的な個数で数える.
- **計算量**
  * $O(L D)$ Time.

### count_less / count_more

```cpp
(1) size_t count_less(const vector<T> &vec, Node *node, bool equal = false)
(2) size_t count_less(const vector<T> &vec, bool equal = false)
(3) size_t count_more(const vector<T> &vec, Node *node, bool equal = false)
(4) size_t count_more(const vector<T> &vec, bool equal = false)
```

- `vec` より辞書順で小さい (大きい) 列の個数を求める.
  * `equal = true` のとき, `vec` 自身と等しい列も個数に含める.
- **計算量**
  * $O(L D)$ Time.

### min / max

```cpp
(1) optional<vector<T>> min()
(2) optional<vector<T>> max()
```

- 登録されている列の中で辞書順最小 / 最大の列を求める.
- **返り値**
  * $1$ つも登録されていなければ `nullopt` を返す.
- **計算量**
  * $O(L)$ Time.

### next / prev

```cpp
(1) optional<vector<T>> next(const vector<T> &vec, bool equal = false)
(2) optional<vector<T>> prev(const vector<T> &vec, bool equal = false)
```

- 登録されている列の中で `vec` の successor (`next`) / predecessor (`prev`) を求める.
  * `equal = true` のとき, `vec` 自身も候補に含める.
- **返り値**
  * 該当する列が存在しなければ `nullopt` を返す.
- **計算量**
  * $O(L D)$ Time.

## Note

`string` を対象とする場合は, `vector<char>` の代わりに `string` を直接渡すオーバーロードが用意されている.

## History

|日付|内容|
|:---:|:---|
|2026/09/13| Ordered_Trie 実装 |
