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
    path: Rolling_Hash/Rolling_Hash.hpp
    title: "\u5270\u4F59\u4F53\u306B\u95A2\u3059\u308B Rolling Hash"
  - icon: ':warning:'
    path: Rolling_Hash/Rolling_Hash_Mersenne.hpp
    title: "Mersenne \u6570\u306E\u5270\u4F59\u4F53\u306B\u95A2\u3059\u308B Rolling\
      \ Hash"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Rolling_Hash \u7CFB\u306E\u30AF\u30E9\u30B9\u306B\u5171\u901A\
      \u3059\u308B\u51E6\u7406\u3092\u307E\u3068\u3081\u305F\u57FA\u5E95\u30AF\u30E9\
      \u30B9 (CRTP)"
    links: []
  bundledCode: "#line 2 \"Rolling_Hash/Rolling_Hash_Base.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 4 \"Rolling_Hash/Rolling_Hash_Base.hpp\"\n\nnamespace rolling_hash\
    \ {\n    /// @brief Rolling_Hash \u7CFB\u306E\u30AF\u30E9\u30B9\u306B\u5171\u901A\
    \u3059\u308B\u51E6\u7406\u3092\u307E\u3068\u3081\u305F\u57FA\u5E95\u30AF\u30E9\
    \u30B9 (CRTP)\n    /// @tparam F \u30CF\u30C3\u30B7\u30E5\u5024\u306E\u578B\n\
    \    /// @tparam Derived \u5B9F\u969B\u306E\u6F14\u7B97 (one, zero, mul, add,\
    \ sub) \u3092\u63D0\u4F9B\u3059\u308B\u6D3E\u751F\u30AF\u30E9\u30B9\n    template<typename\
    \ F, typename Derived>\n    class Rolling_Hash_Base {\n        protected:\n  \
    \      F base;\n        int _size;\n        vector<F> power;\n        vector<F>\
    \ hash;\n\n        const Derived& self() const { return static_cast<const Derived&>(*this);\
    \ }\n\n        /// @brief data \u304B\u3089 power, hash \u30C6\u30FC\u30D6\u30EB\
    \u3092\u69CB\u7BC9\u3059\u308B\n        void build(const vector<F> &data) {\n\
    \            _size = (int)data.size();\n\n            power.assign(size() + 1,\
    \ self().one());\n            hash.assign(size() + 1, self().zero());\n\n    \
    \        for (int i = 0; i < size(); ++i) {\n                power[i + 1] = self().mul(base,\
    \ power[i]);\n                hash[i + 1] = self().add(self().mul(base, hash[i]),\
    \ data[i]);\n            }\n        }\n\n        Rolling_Hash_Base(const F base):\
    \ base(base) {}\n\n        public:\n        int size() const { return _size; }\n\
    \n        F get_base() const { return base; }\n\n        /// @brief [0, p) \u306B\
    \u304A\u3051\u308B\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n   \
    \     /// @param p \u53F3\u7AEF (p \u306F\u542B\u307E\u308C\u306A\u3044)\n   \
    \     F get(const int p) const { return hash[p]; }\n\n        /// @brief [l, r)\
    \ \u306B\u304A\u3051\u308B\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\
    \n        /// @param l \u5DE6\u7AEF (l \u306F\u542B\u307E\u308C\u308B)\n     \
    \   /// @param r \u53F3\u7AEF (r \u306F\u542B\u307E\u308C\u306A\u3044)\n     \
    \   F get(const int l, const int r) const {\n            return self().sub(get(r),\
    \ self().mul(power[r - l], get(l)));\n        }\n\n        /// @brief \u533A\u9593\
    \ [l0, r0) \u3068 [l1, r1) \u3092\u3053\u306E\u9806\u306B\u9023\u7D50\u3057\u305F\
    \u3068\u304D\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n   \
    \     F docking(const int l0, const int r0, const int l1, const int r1) const\
    \ {\n            return self().add(self().mul(get(l0, r0), power[r1 - l1]), get(l1,\
    \ r1));\n        }\n\n        /// @brief X \u5168\u4F53\u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u6C42\u3081\u308B\n        F hashing(const vector<F> &X) const\
    \ {\n            F res = self().zero();\n            for (const F &a: X) {\n \
    \               res = self().add(self().mul(base, res), a);\n            }\n\n\
    \            return res;\n        }\n\n        int count(const vector<F> &X, int\
    \ start) const {\n            F alpha = hashing(X);\n            int res = 0;\n\
    \            for (int i = start; i <= size() - (int)X.size(); ++i) {\n       \
    \         if (alpha == get(i, i + X.size())) res++;\n            }\n\n       \
    \     return res;\n        }\n\n        int count(const vector<F> &X) const {\
    \ return count(X, 0); }\n\n        int find(const vector<F> &X, int start) const\
    \ {\n            F alpha = hashing(X);\n            for (int i = start; i <= size()\
    \ - (int)X.size(); ++i) {\n                if (alpha == get(i, i + X.size()))\
    \ return i;\n            }\n\n            return -1;\n        }\n\n        int\
    \ find(const vector<F> &X) const { return find(X, 0); }\n\n        /// @brief\
    \ \u958B\u59CB\u4F4D\u7F6E\u304C pos \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\
    \u306A X \u306E\u51FA\u73FE\u306E\u3046\u3061, \u6700\u3082\u53F3\u5074\u306B\u3042\
    \u308B\u3082\u306E\u306E\u4F4D\u7F6E\u3092\u6C42\u3081\u308B (std::string::rfind\
    \ \u3068\u540C\u3058\u4ED5\u69D8)\n        int rfind(const vector<F> &X, int pos)\
    \ const {\n            F alpha = hashing(X);\n            for (int i = min(pos,\
    \ size() - (int)X.size()); i >= 0; --i) {\n                if (alpha == get(i,\
    \ i + X.size())) return i;\n            }\n\n            return -1;\n        }\n\
    \n        int rfind(const vector<F> &X) const { return rfind(X, size()); }\n \
    \   };\n} // namespace rolling_hash\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nnamespace rolling_hash\
    \ {\n    /// @brief Rolling_Hash \u7CFB\u306E\u30AF\u30E9\u30B9\u306B\u5171\u901A\
    \u3059\u308B\u51E6\u7406\u3092\u307E\u3068\u3081\u305F\u57FA\u5E95\u30AF\u30E9\
    \u30B9 (CRTP)\n    /// @tparam F \u30CF\u30C3\u30B7\u30E5\u5024\u306E\u578B\n\
    \    /// @tparam Derived \u5B9F\u969B\u306E\u6F14\u7B97 (one, zero, mul, add,\
    \ sub) \u3092\u63D0\u4F9B\u3059\u308B\u6D3E\u751F\u30AF\u30E9\u30B9\n    template<typename\
    \ F, typename Derived>\n    class Rolling_Hash_Base {\n        protected:\n  \
    \      F base;\n        int _size;\n        vector<F> power;\n        vector<F>\
    \ hash;\n\n        const Derived& self() const { return static_cast<const Derived&>(*this);\
    \ }\n\n        /// @brief data \u304B\u3089 power, hash \u30C6\u30FC\u30D6\u30EB\
    \u3092\u69CB\u7BC9\u3059\u308B\n        void build(const vector<F> &data) {\n\
    \            _size = (int)data.size();\n\n            power.assign(size() + 1,\
    \ self().one());\n            hash.assign(size() + 1, self().zero());\n\n    \
    \        for (int i = 0; i < size(); ++i) {\n                power[i + 1] = self().mul(base,\
    \ power[i]);\n                hash[i + 1] = self().add(self().mul(base, hash[i]),\
    \ data[i]);\n            }\n        }\n\n        Rolling_Hash_Base(const F base):\
    \ base(base) {}\n\n        public:\n        int size() const { return _size; }\n\
    \n        F get_base() const { return base; }\n\n        /// @brief [0, p) \u306B\
    \u304A\u3051\u308B\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n   \
    \     /// @param p \u53F3\u7AEF (p \u306F\u542B\u307E\u308C\u306A\u3044)\n   \
    \     F get(const int p) const { return hash[p]; }\n\n        /// @brief [l, r)\
    \ \u306B\u304A\u3051\u308B\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\
    \n        /// @param l \u5DE6\u7AEF (l \u306F\u542B\u307E\u308C\u308B)\n     \
    \   /// @param r \u53F3\u7AEF (r \u306F\u542B\u307E\u308C\u306A\u3044)\n     \
    \   F get(const int l, const int r) const {\n            return self().sub(get(r),\
    \ self().mul(power[r - l], get(l)));\n        }\n\n        /// @brief \u533A\u9593\
    \ [l0, r0) \u3068 [l1, r1) \u3092\u3053\u306E\u9806\u306B\u9023\u7D50\u3057\u305F\
    \u3068\u304D\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u6C42\u3081\u308B\n   \
    \     F docking(const int l0, const int r0, const int l1, const int r1) const\
    \ {\n            return self().add(self().mul(get(l0, r0), power[r1 - l1]), get(l1,\
    \ r1));\n        }\n\n        /// @brief X \u5168\u4F53\u306E\u30CF\u30C3\u30B7\
    \u30E5\u5024\u3092\u6C42\u3081\u308B\n        F hashing(const vector<F> &X) const\
    \ {\n            F res = self().zero();\n            for (const F &a: X) {\n \
    \               res = self().add(self().mul(base, res), a);\n            }\n\n\
    \            return res;\n        }\n\n        int count(const vector<F> &X, int\
    \ start) const {\n            F alpha = hashing(X);\n            int res = 0;\n\
    \            for (int i = start; i <= size() - (int)X.size(); ++i) {\n       \
    \         if (alpha == get(i, i + X.size())) res++;\n            }\n\n       \
    \     return res;\n        }\n\n        int count(const vector<F> &X) const {\
    \ return count(X, 0); }\n\n        int find(const vector<F> &X, int start) const\
    \ {\n            F alpha = hashing(X);\n            for (int i = start; i <= size()\
    \ - (int)X.size(); ++i) {\n                if (alpha == get(i, i + X.size()))\
    \ return i;\n            }\n\n            return -1;\n        }\n\n        int\
    \ find(const vector<F> &X) const { return find(X, 0); }\n\n        /// @brief\
    \ \u958B\u59CB\u4F4D\u7F6E\u304C pos \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\
    \u306A X \u306E\u51FA\u73FE\u306E\u3046\u3061, \u6700\u3082\u53F3\u5074\u306B\u3042\
    \u308B\u3082\u306E\u306E\u4F4D\u7F6E\u3092\u6C42\u3081\u308B (std::string::rfind\
    \ \u3068\u540C\u3058\u4ED5\u69D8)\n        int rfind(const vector<F> &X, int pos)\
    \ const {\n            F alpha = hashing(X);\n            for (int i = min(pos,\
    \ size() - (int)X.size()); i >= 0; --i) {\n                if (alpha == get(i,\
    \ i + X.size())) return i;\n            }\n\n            return -1;\n        }\n\
    \n        int rfind(const vector<F> &X) const { return rfind(X, size()); }\n \
    \   };\n} // namespace rolling_hash\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Rolling_Hash/Rolling_Hash_Base.hpp
  requiredBy:
  - Rolling_Hash/Rolling_Hash.hpp
  - Rolling_Hash/Rolling_Hash_Mersenne.hpp
  timestamp: '2026-08-09 21:52:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Rolling_Hash/Rolling_Hash_Base.hpp
layout: document
title: "Rolling Hash \u57FA\u5E95\u30AF\u30E9\u30B9"
---

## Outline

Rolling Hash に関する基底クラスを提供する

## Theory

$\mathcal{A}$ をアルファベット (文字の集合) として, $R$ を可換環とする.

$b \in R$ を適当にとる. また, 文字に関する単射 $h: \mathcal{A} \to R$ をとる (単射でないと, 異なる文字を同一視してしまう).

このとき, $\mathcal{A}$ 上の列 $X = (x_i)_{i=0}^{n-1}$ に関する Rolling Hash $\textrm{hash}(X)$ を

$$ \textrm{hash}(X) := \sum_{i=0}^{n-1} h(x_i) b^{n-1-i} $$

と定義する.

$R$ 上の列 $A = (a_i)_{i=0}^{n-1}$ に対して, $H_0, H_1, \dots, H_n$ を

$$ H_i := \textrm{hash}(A[0:i)) $$

で定める (ただし $A[l:r)$ は $A$ の半開区間 $[l, r)$ に対応する連続部分列を表す).

すると, $A$ の連続部分列 $A[l:r)$ に対する $\textrm{hash}(A[l:r))$ は

$$ \textrm{hash}(A[l:r)) = H_r - H_l \, b^{r-l} $$

で求められる.

ここで, $H_0, H_1, \dots, H_n$ は

$$ H_0 = 0, \quad H_i = b H_{i-1} + h(a_{i-1}) $$

によって求められる.

以上から, 連続部分列に対するハッシュ値を前計算 $O(n)$ 時間, クエリを $O(1)$ 時間/クエリで求められる.

## Contents

`Rolling_Hash_Base<F, Derived>` は Rolling Hash を実現するクラス群 (`Rolling_Hash<F>`, `Rolling_Hash_Mersenne` など) の共通処理をまとめた基底クラスであり, 直接インスタンス化することは想定していない (コンストラクタは `protected`).

`Derived` は `one() / zero() / mul(a, b) / add(a, b) / sub(a, b)` (それぞれ $R$ の単位元, 零元, 乗法, 加法, 減法に対応) を実装している必要がある.

### size

```cpp
int size() const
```

* 元の列 $A$ の長さ $n$ を返す.
* **計算量**
  * $O(1)$ 時間

### get_base

```cpp
F get_base() const
```

* 基数 $b$ を返す.
* **計算量**
  * $O(1)$ 時間

### get (1変数)

```cpp
F get(const int p) const
```

* $\textrm{hash}(A[0:p))$, すなわち $H_p$ を返す.
* **引数**
  * $p$: 右端 (含まれない)
* **計算量**
  * $O(1)$ 時間

### get (2変数)

```cpp
F get(const int l, const int r) const
```

* $\textrm{hash}(A[l:r))$ を返す.
* **引数**
  * $l$: 左端 (含まれる)
  * $r$: 右端 (含まれない)
* **計算量**
  * $O(1)$ 時間

### docking

```cpp
F docking(const int l0, const int r0, const int l1, const int r1) const
```

* $A[l_0:r_0)$ と $A[l_1:r_1)$ をこの順に連結した列に対する Rolling Hash 値, すなわち $\textrm{hash}(A[l_0:r_0)) \cdot b^{r_1-l_1} + \textrm{hash}(A[l_1:r_1))$ を返す.
* **引数**
  * $l_0, r_0$: 前半区間 ($[l_0, r_0)$)
  * $l_1, r_1$: 後半区間 ($[l_1, r_1)$)
* **計算量**
  * $O(1)$ 時間

### hashing

```cpp
F hashing(const vector<F> &X) const
```

* この Rolling Hash と同じ基数 $b$ を用いて, 列 $X$ 全体の $\textrm{hash}(X)$ を求める.
* **引数**
  * `X`: ハッシュ値を求めたい列
* **計算量**
  * $O(\lvert X \rvert)$ 時間

### count

```cpp
int count(const vector<F> &X, int start = 0) const
```

* $A[\bullet : \bullet + \lvert X \rvert)$ が $X$ と一致するような開始位置が, $\texttt{start}$ 以上にいくつあるかを返す.
* **引数**
  * `X`: 探索するパターン
  * `start`: 探索を開始する位置 (省略時は $0$)
* **計算量**
  * $O(n)$ 時間

### find

```cpp
int find(const vector<F> &X, int start = 0) const
```

* $A$ 内で $X$ が最初に出現する位置 ($\texttt{start}$ 以上で最小の位置) を返す. 存在しなければ $-1$ を返す.
* **引数**
  * `X`: 探索するパターン
  * `start`: 探索を開始する位置 (省略時は $0$)
* **計算量**
  * $O(n)$ 時間

### rfind

```cpp
int rfind(const vector<F> &X, int pos = size()) const
```

* $A$ 内で $X$ が出現する位置のうち, $\texttt{pos}$ 以下で最大のものを返す. 存在しなければ $-1$ を返す. (`std::string::rfind` と同じ仕様)
* **引数**
  * `X`: 探索するパターン
  * `pos`: 探索範囲の上限 (省略時は $n$, すなわち列全体)
* **計算量**
  * $O(n)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/08/09| Rolling_Hash_Base 実装 |
