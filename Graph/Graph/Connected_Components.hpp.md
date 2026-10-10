---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Common.hpp
    title: "\u91CD\u307F\u306A\u3057\u3092\u8868\u3059\u578B"
  - icon: ':heavy_check_mark:'
    path: Graph/Graph/Graph.hpp
    title: "\u7121\u5411 Graph"
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
    path: verify/aizu_online_judge/alds1/11D.test.cpp
    title: verify/aizu_online_judge/alds1/11D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Graph/Connected_Components.hpp\"\n\n#line 2 \"Graph/Graph/Graph.hpp\"\
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
    \    }\n};\n#line 2 \"Graph/Common.hpp\"\n\n#line 4 \"Graph/Common.hpp\"\n\nnamespace\
    \ graph_common {\n    /// @brief \u91CD\u307F\u306A\u3057\u3092\u8868\u3059\u578B\
    \n    /// \u8FBA\u30FB\u5F27\u306E\u91CD\u307F\u306E\u578B W \u306E\u65E2\u5B9A\
    \u5024\u3068\u3057\u3066\u4F7F\u3046\u7A7A\u306E\u578B.\n    struct Empty {};\n\
    }\n#line 5 \"Graph/Graph/Graph.hpp\"\n\nnamespace graph {\n    using graph_common::Empty;\n\
    \n    /**\n     * @brief \u7121\u5411\u8FBA\n     * @tparam W \u91CD\u307F\u306E\
    \u578B (\u91CD\u307F\u306A\u3057\u306E\u5834\u5408\u306F Empty)\n     */\n   \
    \ template<typename W = Empty>\n    struct Edge {\n        int id, source, target;\n\
    \        [[no_unique_address]] W weight;\n\n        Edge(): id(-1), source(-1),\
    \ target(-1), weight() {}\n        Edge(int id, int source, int target, W weight):\
    \ id(id), source(source), target(target), weight(weight) {}\n    };\n\n    /**\n\
    \     * @brief \u5411\u304D\u3092\u4ED8\u3051\u305F\u8FBA. \u9802\u70B9 source\
    \ \u304B\u3089 target \u3078\u8FBA id \u3092\u305F\u3069\u308B\u3053\u3068\u3092\
    \u8868\u3059.\n     * @note \u91CD\u307F\u306F get_edge(id).weight \u3067\u53D6\
    \u5F97\u3059\u308B.\n     */\n    struct Oriented_Edge {\n        int id, source,\
    \ target;\n\n        Oriented_Edge(int id, int source, int target): id(id), source(source),\
    \ target(target) {}\n    };\n\n    /**\n     * @brief \u7121\u5411 Graph\n   \
    \  * @tparam W \u91CD\u307F\u306E\u578B (\u91CD\u307F\u306A\u3057\u306E\u5834\u5408\
    \u306F Empty)\n     * @note \u8FBA\u306F\u5024\u3067\u4FDD\u6301\u3059\u308B.\
    \ add_edge \u3092\u547C\u3076\u3068 get_edge \u3067\u5F97\u305F\u53C2\u7167\u306F\
    \u7121\u52B9\u306B\u306A\u308B\u53EF\u80FD\u6027\u304C\u3042\u308B.\n     */\n\
    \    template<typename W = Empty>\n    class Graph {\n        public:\n      \
    \  using Edge_Type = Edge<W>;\n\n        private:\n        vector<vector<Oriented_Edge>>\
    \ incidences;\n        vector<Edge_Type> edges;\n\n        public:\n        int\
    \ edge_id_offset;\n\n        /**\n         * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n         * @param n \u4F4D\u6570 (\u9802\u70B9\u6570)\n        \
    \ * @param edge_id_offset \u8FBA ID \u306E\u30AA\u30D5\u30BB\u30C3\u30C8\n   \
    \      */\n        Graph(int n, int edge_id_offset = 0): incidences(n), edges(edge_id_offset),\
    \ edge_id_offset(edge_id_offset) {}\n\n        /// @brief \u3053\u306E\u30B0\u30E9\
    \u30D5\u306E\u4F4D\u6570 (\u9802\u70B9\u6570) \u3092\u6C42\u3081\u308B.\n    \
    \    inline int order() const { return int(incidences.size()); }\n\n        ///\
    \ @brief \u3053\u306E\u30B0\u30E9\u30D5\u306E\u30B5\u30A4\u30BA (\u8FBA\u6570\
    ) \u3092\u6C42\u3081\u308B.\n        inline int size() const { return int(edges.size())\
    \ - edge_id_offset; }\n\n        /// @brief \u8FBA uv \u3092\u52A0\u3048\u308B\
    \ (\u91CD\u307F\u306A\u3057\u7528).\n        /// @return \u8FFD\u52A0\u3057\u305F\
    \u8FBA\u306E ID\n        int add_edge(int u, int v) requires same_as<W, Empty>\
    \ { return add_edge(u, v, Empty()); }\n\n        /// @brief \u91CD\u307F w \u306E\
    \u8FBA uv \u3092\u52A0\u3048\u308B.\n        /// @return \u8FFD\u52A0\u3057\u305F\
    \u8FBA\u306E ID\n        int add_edge(int u, int v, W w) {\n            int id\
    \ = int(edges.size());\n\n            edges.emplace_back(id, u, v, w);\n     \
    \       incidences[u].emplace_back(id, u, v);\n            incidences[v].emplace_back(id,\
    \ v, u);\n\n            return id;\n        }\n\n        /// @brief \u9802\u70B9\
    \ u \u306B\u63A5\u7D9A\u3059\u308B\u8FBA\u3092, u \u304B\u3089\u51FA\u308B\u5411\
    \u304D\u3067\u53D6\u5F97\u3059\u308B. \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F 2 \u56DE\
    \u73FE\u308C\u308B.\n        inline const vector<Oriented_Edge>& incidence(int\
    \ u) const { return incidences[u]; }\n\n        /// @brief \u8FBA ID \u304C id\
    \ \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n        inline const\
    \ Edge_Type& get_edge(int id) const { return edges[id]; }\n        inline Edge_Type&\
    \ get_edge(int id) { return edges[id]; }\n\n        /// @brief \u9802\u70B9 v\
    \ \u306E\u6B21\u6570\u3092\u6C42\u3081\u308B\n        inline int degree(const\
    \ int v) const { return int(incidences[v].size()); }\n\n        vector<vector<int>>\
    \ adjacency_matrix() const {\n            vector<vector<int>> matrix(order(),\
    \ vector<int>(order(), 0));\n            for (int j = edge_id_offset; j < edge_id_offset\
    \ + size(); ++j) {\n                const Edge_Type &edge = edges[j];\n      \
    \          matrix[edge.source][edge.target]++;\n                matrix[edge.target][edge.source]++;\n\
    \            }\n\n            return matrix;\n        }\n\n        vector<vector<int>>\
    \ degree_matrix() const {\n            vector<vector<int>> matrix(order(), vector<int>(order(),\
    \ 0));\n            for (int i = 0; i < order(); ++i) matrix[i][i] = degree(i);\n\
    \            return matrix;\n        }\n\n        vector<vector<int>> laplacian_matrix()\
    \ const {\n            const vector<vector<int>> D = degree_matrix(), A = adjacency_matrix();\n\
    \            vector<vector<int>> L(order(), vector<int>(order()));\n         \
    \   for (int i = 0; i < order(); ++i) {\n                for (int j = 0; j < order();\
    \ ++j) {\n                    L[i][j] = D[i][j] - A[i][j];\n                }\n\
    \            }\n\n            return L;\n        }\n    };\n}\n#line 4 \"Graph/Graph/Connected_Components.hpp\"\
    \n\nnamespace graph {\n    class Connected_Components {\n        public:\n   \
    \     vector<vector<int>> components;\n        vector<int> component_ids;\n\n\
    \        template<typename W>\n        Connected_Components(const Graph<W> &G)\
    \ {\n            components.clear();\n            component_ids.assign(G.order(),\
    \ -1);\n\n            for (int x = 0; x < G.order(); x++) {\n                unless(component_ids[x]\
    \ == -1) { continue; }\n                dfs(G, x);\n            }\n        };\n\
    \n        private:\n        template<typename W>\n        void dfs(const Graph<W>\
    \ &G, int start) {\n            int component_id = components.size();\n\n    \
    \        components.emplace_back();\n            component_ids[start] = component_id;\n\
    \n            stack<int> st;\n            st.emplace(start);\n            components[component_id].emplace_back(start);\n\
    \n            while(!st.empty()) {\n                int x = st.top(); st.pop();\n\
    \                for (auto edge: G.incidence(x)) {\n                    int y\
    \ = edge.target;\n                    unless (component_ids[y] == -1) { continue;\
    \ }\n\n                    component_ids[y] = component_id;\n                \
    \    components[component_id].emplace_back(y);\n                    st.emplace(y);\n\
    \                }\n            }\n        }\n    };\n\n    template<typename\
    \ W>\n    bool is_Connected(const Graph<W> &G) {\n        auto connected_components\
    \ = Connected_Components(G);\n        return connected_components.components.size()\
    \ == 1;\n    }\n}\n"
  code: "#pragma once\n\n#include\"Graph.hpp\"\n\nnamespace graph {\n    class Connected_Components\
    \ {\n        public:\n        vector<vector<int>> components;\n        vector<int>\
    \ component_ids;\n\n        template<typename W>\n        Connected_Components(const\
    \ Graph<W> &G) {\n            components.clear();\n            component_ids.assign(G.order(),\
    \ -1);\n\n            for (int x = 0; x < G.order(); x++) {\n                unless(component_ids[x]\
    \ == -1) { continue; }\n                dfs(G, x);\n            }\n        };\n\
    \n        private:\n        template<typename W>\n        void dfs(const Graph<W>\
    \ &G, int start) {\n            int component_id = components.size();\n\n    \
    \        components.emplace_back();\n            component_ids[start] = component_id;\n\
    \n            stack<int> st;\n            st.emplace(start);\n            components[component_id].emplace_back(start);\n\
    \n            while(!st.empty()) {\n                int x = st.top(); st.pop();\n\
    \                for (auto edge: G.incidence(x)) {\n                    int y\
    \ = edge.target;\n                    unless (component_ids[y] == -1) { continue;\
    \ }\n\n                    component_ids[y] = component_id;\n                \
    \    components[component_id].emplace_back(y);\n                    st.emplace(y);\n\
    \                }\n            }\n        }\n    };\n\n    template<typename\
    \ W>\n    bool is_Connected(const Graph<W> &G) {\n        auto connected_components\
    \ = Connected_Components(G);\n        return connected_components.components.size()\
    \ == 1;\n    }\n}\n"
  dependsOn:
  - Graph/Graph/Graph.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Graph/Common.hpp
  isVerificationFile: false
  path: Graph/Graph/Connected_Components.hpp
  requiredBy: []
  timestamp: '2026-10-04 17:28:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/alds1/11D.test.cpp
documentation_of: Graph/Graph/Connected_Components.hpp
layout: document
title: "\u9023\u7D50\u6210\u5206"
---

## Outline

無向グラフ $G = (V, E)$ の連結成分に関する計算を行う.

## Definition

* 頂点 $u, v \in V$ について, 頂点 $u$ と頂点 $v$ を結ぶ歩道が存在するとき, 頂点 $u, v$ は **連結** であるという.
* $G$ が食うではなく, 任意の $2$ 頂点が連結であるとき, $G$ は **連結** であるという.
* $V$ において, 連結であるという関係は同値になる (証明は後述). この同値関係による同値類を **連結成分** という.

## Theory

> 定理 1
>
> $V$ において, 連結であるという関係は同値になる.

**証明**

* (反射律) 任意の $v \in V$ に対して, 移動しない歩道 $(v)$ が $v$ と $v$ を結ぶ歩道である. よって, $v, v$ は連結である.
* (対称律) $u, v \in V$ 連結であるとする. このとき, 頂点 $u$ と頂点 $v$ を結ぶ歩道を $(u = v_0, e_1, v_1, \dots, v_{n-1}, e_n, v_n = v)$ としたとき, $(v = v_n, e_n, v_{n-1}, \dots, v_1, e_1, v_0 = u)$ は頂点 $v$ と $u$ を結ぶ歩道である. よって, $v, u$ は連結である.
* (推移律) $u, v, w \in V$ について, $u, v$ と $v, w$ はそれぞれ連結であるとする. このとき, 以下が存在する.
  * $(u = v_0, e_1, v_1, \dots, v_{n-1}, e_n, v_n = v)$: $u, v$ を結ぶ歩道.
  * $(v = w_0, f_1, w_1, \dots, w_{m-1}, f_m, w_m = w)$: $v, w$ を結ぶ歩道.

  このとき,

  $$ (u = v_0, e_1, v_1, \dots, e_n, v_n = v = w_0, f_1, w_1, \dots, f_m, w_m = w) $$

  は $u, w$ を結ぶ歩道になる. よって, $u, w$ は連結である.

> 定理 2
>
> $V$ において, 連結であるという関係は, 辺による隣接関係から生成する同値関係である.

**証明**

$V$ 上の関係 $\sim$ を「連結である」という関係とし, $R$ を「辺によって隣接している」という関係とする. $R$ から生成する同値関係を $\approx$ とする. すなわち, $\approx$ は $R$ を含む同値関係のうち最小のものである. $\sim$ と $\approx$ が一致することを示す.

* ($\approx \subseteq \sim$)
  * 定理 1 より, $\sim$ は同値関係である.
  * $u, v \in V$ が $R$ によって隣接しているとする. このとき, $e = uv$ なる $e \in E$ が存在するので, $(u, e, v)$ は $u, v$ を結ぶ長さ $1$ の歩道である. よって, $u \sim v$ である. すなわち, $\sim$ は $R$ を含む.
  * $\approx$ は $R$ を含む同値関係のうち最小であるから, $\approx \subseteq \sim$ である.
* ($\sim \subseteq \approx$)
  * $u \sim v$ とし, $u, v$ を結ぶ歩道を $(u = v_0, e_1, v_1, \dots, e_n, v_n = v)$ とする.
  * 各 $i = 1, \dots, n$ について, $e_i = v_{i-1}v_i$ であるから, $v_{i-1}$ と $v_i$ は $R$ によって隣接している. $\approx$ は $R$ を含むので, $v_{i-1} \approx v_i$ である.
  * $\approx$ は同値関係であるから, 推移律より $u = v_0 \approx v_n = v$ である.

以上より, $\sim$ と $\approx$ は一致する.



## Contents

与えられるグラフ $G$ の位数を $N$, サイズを $M$ とする.

```cpp
template<typename W>
Connected_Components(const Graph<W> &G)
```

* 無向グラフ $G$ の連結成分を求める. 連結成分は深さ優先探索 (スタックを用いた非再帰) で求める.
* $G$ の頂点は $0, 1, \dots, N-1$ で表される.
* **計算量**: $O(N + M)$ 時間.

```cpp
vector<vector<int>> components
vector<int> component_ids
```

* `components`: 連結成分の一覧である. `components[i]` は第 $i$ 連結成分に属する頂点のリストである.
  * 連結成分は, 含まれる頂点のうち最小のものが小さい順に並ぶ. 各連結成分の先頭の頂点は, その連結成分に含まれる頂点のうち最小のものである.
* `component_ids`: 長さ $N$ の配列である. `component_ids[v]` は頂点 $v$ が属する連結成分の番号 $i$ (すなわち, `components[i]` が $v$ を含む) である.

```cpp
template<typename W>
bool is_Connected(const Graph<W> &G)
```

* 無向グラフ $G$ が連結であるかどうかを判定する.
* **返り値**
  * $G$ の連結成分がちょうど $1$ つであるとき `true`, そうでないとき `false`.
  * 特に, 頂点が $0$ 個のグラフに対しては `false` を返す.
* **計算量**: $O(N + M)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/10|連結成分のドキュメントの作成|
|2025/09/19|`is_Connected` の実装|
|2025/09/18|連結成分の実装|
