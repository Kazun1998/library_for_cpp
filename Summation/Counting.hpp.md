---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Summation/Summation.hpp
    title: "\u7279\u6B8A\u306A\u6570\u5217\u306E\u7DCF\u548C"
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
    document_title: "\u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\
      \u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059."
    links: []
  bundledCode: "#line 2 \"Summation/Counting.hpp\"\n\n#line 2 \"Summation/Summation.hpp\"\
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
    \ {\n        return message.c_str();\n    }\n};\n#line 4 \"Summation/Summation.hpp\"\
    \n\nnamespace summation {\n    /**\n     * @brief \u7B49\u5DEE\u6570\u5217\u306E\
    \u548C\u3092\u6C42\u3081\u307E\u3059.\n     * \n     * sum_{k=l}^{r} (a * k +\
    \ b)\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u4FC2\u6570\
    \ a\n     * @param b \u5B9A\u6570 b\n     * @param l \u4E0B\u9650\n     * @param\
    \ r \u4E0A\u9650\n     * @return T \u7DCF\u548C\n     */\n    template<typename\
    \ T>\n    T linear(T a, T b, T l, T r) {\n        if (l > r) return 0;\n\n   \
    \     T num_terms = r - l + 1;\n        T sum_k = num_terms * (l + r) / 2;\n \
    \       T sum_b = num_terms * b;\n        return a * sum_k + sum_b;\n    }\n\n\
    \    /**\n     * @brief ReLU(\u4E00\u6B21\u95A2\u6570) \u306E\u548C\u3092\u6C42\
    \u3081\u307E\u3059.\n     * \n     * sum_{k=l}^{r} max(0, a * k + b)\n     * \n\
    \     * @tparam T \u6574\u6570\u578B\n     * @param a \u4FC2\u6570 a\n     * @param\
    \ b \u5B9A\u6570 b\n     * @param l \u4E0B\u9650\n     * @param r \u4E0A\u9650\
    \n     * @return T \u7DCF\u548C\n     */\n    template<typename T>\n    T relu_linear(T\
    \ a, T b, T l, T r) {\n        if (a == 0) { return (r - l + 1) * max<T>(0, b);\
    \ }\n        if (a < 0) { return relu_linear(-a, a * (r + l) + b, l, r); }\n\n\
    \        // \u3053\u3053\u306B\u5230\u9054\u3057\u305F\u6BB5\u968E\u3067 a > 0\
    \ \u304C\u4FDD\u8A3C\u3055\u308C\u308B\n\n        if (a * r + b <= 0) return 0;\n\
    \n        T t = max<T>(l, div_ceil(-b, a));\n\n        return linear(a, b, t,\
    \ r);\n    }\n\n    /**\n     * @brief 2\u3064\u306E\u4E00\u6B21\u95A2\u6570\u306E\
    \u6700\u5927\u5024\u306E\u548C\u3092\u6C42\u3081\u307E\u3059.\n     * \n     *\
    \ sum_{k=l}^{r} max(a * k + b, c * k + d)\n     * \n     * @tparam T \u6574\u6570\
    \u578B\n     * @param a \u7B2C1\u306E\u4E00\u6B21\u95A2\u6570\u306E\u4FC2\u6570\
    \ a\n     * @param b \u7B2C1\u306E\u4E00\u6B21\u95A2\u6570\u306E\u5B9A\u6570 b\n\
    \     * @param c \u7B2C2\u306E\u4E00\u6B21\u95A2\u6570\u306E\u4FC2\u6570 c\n \
    \    * @param d \u7B2C2\u306E\u4E00\u6B21\u95A2\u6570\u306E\u5B9A\u6570 d\n  \
    \   * @param l \u4E0B\u9650\n     * @param r \u4E0A\u9650\n     * @return T \u7DCF\
    \u548C\n     */\n    template<typename T>\n    T max_linear(T a, T b, T c, T d,\
    \ T l, T r) {\n        return relu_linear(a - c, b - d, l, r) + linear(c, d, l,\
    \ r);\n    }\n\n    /**\n     * @brief \u4E00\u6B21\u95A2\u6570\u3068\u5B9A\u6570\
    \u306E\u6700\u5927\u5024\u306E\u548C\u3092\u6C42\u3081\u307E\u3059.\n     * \n\
    \     * sum_{k=l}^{r} max(a * k + b, d)\n     * \n     * @tparam T \u6574\u6570\
    \u578B\n     * @param a \u4FC2\u6570 a\n     * @param b \u5B9A\u6570 b\n     *\
    \ @param d \u5B9A\u6570 d\n     * @param l \u4E0B\u9650\n     * @param r \u4E0A\
    \u9650\n     * @return T \u7DCF\u548C\n     */\n    template<typename T>\n   \
    \ T max_linear(T a, T b, T d, T l, T r) { return max_linear(a, b, 0, d, l, r);\
    \ }\n\n    /**\n     * @brief 2\u3064\u306E\u4E00\u6B21\u95A2\u6570\u306E\u6700\
    \u5C0F\u5024\u306E\u548C\u3092\u6C42\u3081\u307E\u3059.\n     * \n     * sum_{k=l}^{r}\
    \ min(a * k + b, c * k + d)\n     * \n     * @tparam T \u6574\u6570\u578B\n  \
    \   * @param a \u7B2C1\u306E\u4E00\u6B21\u95A2\u6570\u306E\u4FC2\u6570 a\n   \
    \  * @param b \u7B2C1\u306E\u4E00\u6B21\u95A2\u6570\u306E\u5B9A\u6570 b\n    \
    \ * @param c \u7B2C2\u306E\u4E00\u6B21\u95A2\u6570\u306E\u4FC2\u6570 c\n     *\
    \ @param d \u7B2C2\u306E\u4E00\u6B21\u95A2\u6570\u306E\u5B9A\u6570 d\n     * @param\
    \ l \u4E0B\u9650\n     * @param r \u4E0A\u9650\n     * @return T \u7DCF\u548C\n\
    \     */\n    template<typename T>\n    T min_linear(T a, T b, T c, T d, T l,\
    \ T r) {\n        return -relu_linear(-(a - c), -(b - d), l, r) + linear(c, d,\
    \ l, r);\n    }\n\n    /**\n     * @brief \u4E00\u6B21\u95A2\u6570\u3068\u5B9A\
    \u6570\u306E\u6700\u5C0F\u5024\u306E\u548C\u3092\u6C42\u3081\u307E\u3059.\n  \
    \   * \n     * sum_{k=l}^{r} min(a * k + b, d)\n     * \n     * @tparam T \u6574\
    \u6570\u578B\n     * @param a \u4FC2\u6570 a\n     * @param b \u5B9A\u6570 b\n\
    \     * @param d \u5B9A\u6570 d\n     * @param l \u4E0B\u9650\n     * @param r\
    \ \u4E0A\u9650\n     * @return T \u7DCF\u548C\n     */\n    template<typename\
    \ T>\n    T min_linear(T a, T b, T u, T l, T r) { return min_linear(a, b, 0, u,\
    \ l, r); }\n\n    /**\n     * @brief \u4E00\u6B21\u95A2\u6570\u306E\u7D76\u5BFE\
    \u5024\u306E\u548C\u3092\u6C42\u3081\u307E\u3059.\n     * \n     * sum_{k=l}^{r}\
    \ |a * k + b|\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u4FC2\
    \u6570 a\n     * @param b \u5B9A\u6570 b\n     * @param l \u4E0B\u9650\n     *\
    \ @param r \u4E0A\u9650\n     * @return T \u7DCF\u548C\n     */\n    template<typename\
    \ T>\n    T abs_linear(T a, T b, T l, T r) {\n        return max_linear(a, b,\
    \ -a, -b, l, r);\n    }\n\n    /**\n     * @brief \u4E00\u6B21\u95A2\u6570\u3092\
    \u7BC4\u56F2 [d, u] \u306B\u53CE\u3081\u305F\u5024\u306E\u548C\u3092\u6C42\u3081\
    \u307E\u3059.\n     * \n     * sum_{k=l}^{r} clamp(a * k + b, d, u)\n     * clamp(x,\
    \ d, u) = min(max(x, d), u)\n     * \n     * @tparam T \u6574\u6570\u578B\n  \
    \   * @param a \u4FC2\u6570 a\n     * @param b \u5B9A\u6570 b\n     * @param d\
    \ \u4E0B\u9650\u5024 d\n     * @param u \u4E0A\u9650\u5024 u\n     * @param l\
    \ \u7DCF\u548C\u306E\u4E0B\u9650\n     * @param r \u7DCF\u548C\u306E\u4E0A\u9650\
    \n     * @return T \u7DCF\u548C\n     */\n    template<typename T>\n    T clamp_linear(T\
    \ a, T b, T d, T u, T l, T r) {\n        return linear(a, b, l, r) - relu_linear(a,\
    \ b - u, l, r) + relu_linear(-a, d - b, l, r);\n    }\n\n    /**\n     * @brief\
    \ 0 \u304B\u3089 n \u307E\u3067\u306E\u4E8C\u4E57\u548C\u3092\u6C42\u3081\u307E\
    \u3059.\n     * \n     * sum_{k=0}^{n} k^2\n     * \n     * @tparam T \u6574\u6570\
    \u578B\n     * @param n \u4E0A\u9650\n     * @return T \u7DCF\u548C\n     */\n\
    \    template<typename T>\n    T sum_sq(T n) {\n        if (n < 0) return 0;\n\
    \        return n * (n + 1) * (2 * n + 1) / 6;\n    }\n\n    /**\n     * @brief\
    \ \u4E00\u6B21\u95A2\u6570\u306E\u4E8C\u4E57\u306E\u548C\u3092\u6C42\u3081\u307E\
    \u3059.\n     * \n     * sum_{k=l}^{r} (a * k + b)^2\n     * \n     * @tparam\
    \ T \u6574\u6570\u578B\n     * @param a \u4FC2\u6570 a\n     * @param b \u5B9A\
    \u6570 b\n     * @param l \u4E0B\u9650\n     * @param r \u4E0A\u9650\n     * @return\
    \ T \u7DCF\u548C\n     */\n    template<typename T>\n    T square_linear(T a,\
    \ T b, T l, T r) {\n        if (l > r) return 0;\n        T sum_1 = (r - l + 1)\
    \ * (l + r) / 2;\n        T sum_2 = sum_sq(r) - sum_sq(l - 1);\n        return\
    \ a * a * sum_2 + 2 * a * b * sum_1 + b * b * (r - l + 1);\n    }\n\n    /**\n\
    \     * @brief 2\u3064\u306E\u4E00\u6B21\u95A2\u6570\u306E\u7A4D\u306E\u548C\u3092\
    \u6C42\u3081\u307E\u3059.\n     * \n     * sum_{k=l}^{r} (a * k + b) * (c * k\
    \ + d)\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u7B2C1\u306E\
    \u4E00\u6B21\u95A2\u6570\u306E\u4FC2\u6570 a\n     * @param b \u7B2C1\u306E\u4E00\
    \u6B21\u95A2\u6570\u306E\u5B9A\u6570 b\n     * @param c \u7B2C2\u306E\u4E00\u6B21\
    \u95A2\u6570\u306E\u4FC2\u6570 c\n     * @param d \u7B2C2\u306E\u4E00\u6B21\u95A2\
    \u6570\u306E\u5B9A\u6570 d\n     * @param l \u4E0B\u9650\n     * @param r \u4E0A\
    \u9650\n     * @return T \u7DCF\u548C\n     */\n    template<typename T>\n   \
    \ T sum_product_linear(T a, T b, T c, T d, T l, T r) {\n        if (l > r) return\
    \ 0;\n        T n = r - l + 1;\n        T sum_k = n * (l + r) / 2;\n        T\
    \ sum_k2 = sum_sq(r) - sum_sq(l - 1);\n        return a * c * sum_k2 + (a * d\
    \ + b * c) * sum_k + b * d * n;\n    }\n\n    /**\n     * @brief 2\u3064\u306E\
    \ ReLU(\u4E00\u6B21\u95A2\u6570) \u306E\u7A4D\u306E\u548C\u3092\u6C42\u3081\u307E\
    \u3059.\n     * \n     * sum_{k=l}^{r} relu(a * k + b) * relu(c * i + d)\n   \
    \  * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u7B2C1\u306E\u4E00\
    \u6B21\u95A2\u6570\u306E\u4FC2\u6570 a\n     * @param b \u7B2C1\u306E\u4E00\u6B21\
    \u95A2\u6570\u306E\u5B9A\u6570 b\n     * @param c \u7B2C2\u306E\u4E00\u6B21\u95A2\
    \u6570\u306E\u4FC2\u6570 c\n     * @param d \u7B2C2\u306E\u4E00\u6B21\u95A2\u6570\
    \u306E\u5B9A\u6570 d\n     * @param l \u4E0B\u9650\n     * @param r \u4E0A\u9650\
    \n     * @return T \u7DCF\u548C\n     */\n    template<typename T>\n    T product_relu_linear(T\
    \ a, T b, T c, T d, T l, T r) {\n        T L = l, R = r;\n\n        if (a > 0)\
    \ L = max<T>(L, div_ceil(-b, a));\n        else if (a < 0) R = min<T>(R, div_floor(-b,\
    \ a));\n        else if (b < 0) return 0;\n\n        if (c > 0) L = max<T>(L,\
    \ div_ceil(-d, c));\n        else if (c < 0) R = min<T>(R, div_floor(-d, c));\n\
    \        else if (d < 0) return 0;\n\n        if (L > R) return 0;\n\n       \
    \ return sum_product_linear(a, b, c, d, L, R);\n    }\n}\n#line 6 \"Summation/Counting.hpp\"\
    \n\nnamespace counting {\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\
    \u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: l <= x <= r, ax + b <=\
    \ y <= cx + d\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u4E0D\
    \u7B49\u5F0F ax + b <= y \u306E\u4FC2\u6570 a\n     * @param b \u4E0D\u7B49\u5F0F\
    \ ax + b <= y \u306E\u5B9A\u6570 b\n     * @param c \u4E0D\u7B49\u5F0F y <= cx\
    \ + d \u306E\u4FC2\u6570 c\n     * @param d \u4E0D\u7B49\u5F0F y <= cx + d \u306E\
    \u5B9A\u6570 d\n     * @param l x \u306E\u4E0B\u9650\n     * @param r x \u306E\
    \u4E0A\u9650\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\
    \u500B\u6570\n     */\n    template<typename T>\n    T count_between_lines(T a,\
    \ T b, T c, T d, T l, T r) {\n        return summation::relu_linear(c - a, d -\
    \ b + 1, l, r);\n    }\n\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\
    \u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: l <= x <= r, ax + b <=\
    \ y <= cx + d, ex + f <= y <= gx + h\n     * \n     * @tparam T \u6574\u6570\u578B\
    \n     * @param a \u4E0D\u7B49\u5F0F ax + b <= y \u306E\u4FC2\u6570 a\n     *\
    \ @param b \u4E0D\u7B49\u5F0F ax + b <= y \u306E\u5B9A\u6570 b\n     * @param\
    \ c \u4E0D\u7B49\u5F0F y <= cx + d \u306E\u4FC2\u6570 c\n     * @param d \u4E0D\
    \u7B49\u5F0F y <= cx + d \u306E\u5B9A\u6570 d\n     * @param e \u4E0D\u7B49\u5F0F\
    \ ex + f <= y \u306E\u4FC2\u6570 e\n     * @param f \u4E0D\u7B49\u5F0F ex + f\
    \ <= y \u306E\u5B9A\u6570 f\n     * @param g \u4E0D\u7B49\u5F0F y <= gx + h \u306E\
    \u4FC2\u6570 g\n     * @param h \u4E0D\u7B49\u5F0F y <= gx + h \u306E\u5B9A\u6570\
    \ h\n     * @param l x \u306E\u4E0B\u9650\n     * @param r x \u306E\u4E0A\u9650\
    \n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\
    \n     */\n    template<typename T>\n    T count_between_lines(T a, T b, T c,\
    \ T d, T e, T f, T g, T h, T l, T r) {\n        // \u5404 x \u306B\u5BFE\u3057\
    \u3066 y \u306E\u500B\u6570\u306F\n        // max(0, min(cx + d, gx + h) - max(ax\
    \ + b, ex + f) + 1)\n        // = max(0, min(\n        //    (c - a)x + (d - b\
    \ + 1),\n        //    (c - e)x + (d - f + 1),\n        //    (g - a)x + (h -\
    \ b + 1),\n        //    (g - e)x + (h - f + 1)\n        // ))\n        // \u3068\
    \u306A\u308B. 4\u3064\u306E\u76F4\u7DDA\u306E\u6700\u5C0F\u5024(\u305F\u3060\u3057\
    \u8CA0\u306A\u30890)\u306E\u548C\u3092\u6C42\u3081\u308B\u554F\u984C\u306B\u5E30\
    \u7740\u3055\u308C\u308B.\n\n        struct Line { T k, m; };\n        std::vector<Line>\
    \ lines = {\n            {c - a, d - b + 1},\n            {c - e, d - f + 1},\n\
    \            {g - a, h - b + 1},\n            {g - e, h - f + 1}\n        };\n\
    \n        T L = l, R = r;\n\n        // \u5024\u304C\u8CA0\u306B\u306A\u308B\u7BC4\
    \u56F2\u3092\u9664\u5916\u3059\u308B (L_i(x) >= 0 \u3092\u6E80\u305F\u3059\u7BC4\
    \u56F2\u306B\u9650\u5B9A)\n        for (const auto& line : lines) {\n        \
    \    if (line.k == 0) {\n                if (line.m < 0) return 0;\n         \
    \   } else if (line.k > 0) {\n                L = max<T>(L, div_ceil(-line.m,\
    \ line.k));\n            } else {\n                R = min<T>(R, div_floor(-line.m,\
    \ line.k));\n            }\n        }\n\n        if (L > R) return 0;\n\n    \
    \    vector<T> points;\n        points.push_back(L - 1);\n        points.push_back(R);\n\
    \n        // \u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u3066\u533A\u9593\
    \u3092\u5206\u5272\u3059\u308B\n        for (size_t i = 0; i < lines.size(); ++i)\
    \ {\n            for (size_t j = i + 1; j < lines.size(); ++j) {\n           \
    \     if (lines[i].k == lines[j].k) continue;\n\n                T num = lines[j].m\
    \ - lines[i].m;\n                T den = lines[i].k - lines[j].k;\n          \
    \      T x = div_floor(num, den);\n                if (x >= L - 1 && x < R) points.push_back(x);\n\
    \            }\n        }\n\n        sort(points.begin(), points.end());\n   \
    \     points.erase(unique(points.begin(), points.end()), points.end());\n\n  \
    \      T total = 0;\n        for (size_t i = 0; i < points.size() - 1; ++i) {\n\
    \            T seg_l = points[i] + 1;\n            T seg_r = points[i+1];\n  \
    \          \n            // \u533A\u9593\u5185\u3067\u306F\u6700\u5C0F\u5024\u3092\
    \u4E0E\u3048\u308B\u76F4\u7DDA\u306F\u5909\u308F\u3089\u306A\u3044\u306E\u3067\
    , \u5148\u982D\u306E\u70B9\u3067\u5224\u5B9A\u3059\u308B\n            T min_val\
    \ = lines[0].k * seg_l + lines[0].m;\n            size_t min_idx = 0;\n      \
    \      for (size_t j = 1; j < lines.size(); ++j) {\n                T val = lines[j].k\
    \ * seg_l + lines[j].m;\n                if (val < min_val) {\n              \
    \      min_val = val;\n                    min_idx = j;\n                }\n \
    \           }\n            \n            total += summation::linear(lines[min_idx].k,\
    \ lines[min_idx].m, seg_l, seg_r);\n        }\n\n        return total;\n    }\n\
    \n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059\
    .\n     * \n     * \u6761\u4EF6: p <= x <= q, r <= y <= s, x + y = k\n     * \n\
    \     * @tparam T \u6574\u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\n \
    \    * @param q x \u306E\u4E0A\u9650\n     * @param r y \u306E\u4E0B\u9650\n \
    \    * @param s y \u306E\u4E0A\u9650\n     * @param k \u548C k\n     * @return\
    \ T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\n     */\n\
    \    template<typename T>\n    T count_sum_eq(T p, T q, T r, T s, T k) {\n   \
    \     return count_sum_range(p, q, r, s, k, k);\n    }\n\n    /**\n     * @brief\
    \ \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44\
    \ (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\
    \u4EF6: p <= x <= q, r <= y <= s, a <= x + y <= b\n     * \n     * @tparam T \u6574\
    \u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\n     * @param q x \u306E\u4E0A\
    \u9650\n     * @param r y \u306E\u4E0B\u9650\n     * @param s y \u306E\u4E0A\u9650\
    \n     * @param a \u548C x + y \u306E\u4E0B\u9650\n     * @param b \u548C x +\
    \ y \u306E\u4E0A\u9650\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \ (x, y) \u306E\u500B\u6570\n     */\n    template<typename T>\n    T count_sum_range(T\
    \ p, T q, T r, T s, T a, T b) {\n        return count_between_lines<T>(0, r, 0,\
    \ s, -1, a, -1, b, p, q);\n    }\n\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\
    \u3092\u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: p <= x <= q, r\
    \ <= y <= s, x - y = k\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param\
    \ p x \u306E\u4E0B\u9650\n     * @param q x \u306E\u4E0A\u9650\n     * @param\
    \ r y \u306E\u4E0B\u9650\n     * @param s y \u306E\u4E0A\u9650\n     * @param\
    \ k \u5DEE k\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\
    \u500B\u6570\n     */\n    template<typename T>\n    T count_diff_eq(T p, T q,\
    \ T r, T s, T k) {\n        return count_sum_eq(p, q, -s, -r, k);\n    }\n\n \
    \   /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\
    \u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059.\n\
    \     * \n     * \u6761\u4EF6: p <= x <= q, r <= y <= s, a <= x - y <= b\n   \
    \  * \n     * @tparam T \u6574\u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\
    \n     * @param q x \u306E\u4E0A\u9650\n     * @param r y \u306E\u4E0B\u9650\n\
    \     * @param s y \u306E\u4E0A\u9650\n     * @param a \u5DEE x - y \u306E\u4E0B\
    \u9650\n     * @param b \u5DEE x - y \u306E\u4E0A\u9650\n     * @return T \u6761\
    \u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\n     */\n    template<typename\
    \ T>\n    T count_diff_range(T p, T q, T r, T s, T a, T b) {\n        return count_sum_range(p,\
    \ q, -s, -r, a, b);\n    }\n}\n"
  code: "#pragma once\n\n#include \"Summation.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \nnamespace counting {\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\
    \u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: l <= x <= r, ax + b <= y <=\
    \ cx + d\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param a \u4E0D\
    \u7B49\u5F0F ax + b <= y \u306E\u4FC2\u6570 a\n     * @param b \u4E0D\u7B49\u5F0F\
    \ ax + b <= y \u306E\u5B9A\u6570 b\n     * @param c \u4E0D\u7B49\u5F0F y <= cx\
    \ + d \u306E\u4FC2\u6570 c\n     * @param d \u4E0D\u7B49\u5F0F y <= cx + d \u306E\
    \u5B9A\u6570 d\n     * @param l x \u306E\u4E0B\u9650\n     * @param r x \u306E\
    \u4E0A\u9650\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\
    \u500B\u6570\n     */\n    template<typename T>\n    T count_between_lines(T a,\
    \ T b, T c, T d, T l, T r) {\n        return summation::relu_linear(c - a, d -\
    \ b + 1, l, r);\n    }\n\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\
    \u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: l <= x <= r, ax + b <=\
    \ y <= cx + d, ex + f <= y <= gx + h\n     * \n     * @tparam T \u6574\u6570\u578B\
    \n     * @param a \u4E0D\u7B49\u5F0F ax + b <= y \u306E\u4FC2\u6570 a\n     *\
    \ @param b \u4E0D\u7B49\u5F0F ax + b <= y \u306E\u5B9A\u6570 b\n     * @param\
    \ c \u4E0D\u7B49\u5F0F y <= cx + d \u306E\u4FC2\u6570 c\n     * @param d \u4E0D\
    \u7B49\u5F0F y <= cx + d \u306E\u5B9A\u6570 d\n     * @param e \u4E0D\u7B49\u5F0F\
    \ ex + f <= y \u306E\u4FC2\u6570 e\n     * @param f \u4E0D\u7B49\u5F0F ex + f\
    \ <= y \u306E\u5B9A\u6570 f\n     * @param g \u4E0D\u7B49\u5F0F y <= gx + h \u306E\
    \u4FC2\u6570 g\n     * @param h \u4E0D\u7B49\u5F0F y <= gx + h \u306E\u5B9A\u6570\
    \ h\n     * @param l x \u306E\u4E0B\u9650\n     * @param r x \u306E\u4E0A\u9650\
    \n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\
    \n     */\n    template<typename T>\n    T count_between_lines(T a, T b, T c,\
    \ T d, T e, T f, T g, T h, T l, T r) {\n        // \u5404 x \u306B\u5BFE\u3057\
    \u3066 y \u306E\u500B\u6570\u306F\n        // max(0, min(cx + d, gx + h) - max(ax\
    \ + b, ex + f) + 1)\n        // = max(0, min(\n        //    (c - a)x + (d - b\
    \ + 1),\n        //    (c - e)x + (d - f + 1),\n        //    (g - a)x + (h -\
    \ b + 1),\n        //    (g - e)x + (h - f + 1)\n        // ))\n        // \u3068\
    \u306A\u308B. 4\u3064\u306E\u76F4\u7DDA\u306E\u6700\u5C0F\u5024(\u305F\u3060\u3057\
    \u8CA0\u306A\u30890)\u306E\u548C\u3092\u6C42\u3081\u308B\u554F\u984C\u306B\u5E30\
    \u7740\u3055\u308C\u308B.\n\n        struct Line { T k, m; };\n        std::vector<Line>\
    \ lines = {\n            {c - a, d - b + 1},\n            {c - e, d - f + 1},\n\
    \            {g - a, h - b + 1},\n            {g - e, h - f + 1}\n        };\n\
    \n        T L = l, R = r;\n\n        // \u5024\u304C\u8CA0\u306B\u306A\u308B\u7BC4\
    \u56F2\u3092\u9664\u5916\u3059\u308B (L_i(x) >= 0 \u3092\u6E80\u305F\u3059\u7BC4\
    \u56F2\u306B\u9650\u5B9A)\n        for (const auto& line : lines) {\n        \
    \    if (line.k == 0) {\n                if (line.m < 0) return 0;\n         \
    \   } else if (line.k > 0) {\n                L = max<T>(L, div_ceil(-line.m,\
    \ line.k));\n            } else {\n                R = min<T>(R, div_floor(-line.m,\
    \ line.k));\n            }\n        }\n\n        if (L > R) return 0;\n\n    \
    \    vector<T> points;\n        points.push_back(L - 1);\n        points.push_back(R);\n\
    \n        // \u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u3066\u533A\u9593\
    \u3092\u5206\u5272\u3059\u308B\n        for (size_t i = 0; i < lines.size(); ++i)\
    \ {\n            for (size_t j = i + 1; j < lines.size(); ++j) {\n           \
    \     if (lines[i].k == lines[j].k) continue;\n\n                T num = lines[j].m\
    \ - lines[i].m;\n                T den = lines[i].k - lines[j].k;\n          \
    \      T x = div_floor(num, den);\n                if (x >= L - 1 && x < R) points.push_back(x);\n\
    \            }\n        }\n\n        sort(points.begin(), points.end());\n   \
    \     points.erase(unique(points.begin(), points.end()), points.end());\n\n  \
    \      T total = 0;\n        for (size_t i = 0; i < points.size() - 1; ++i) {\n\
    \            T seg_l = points[i] + 1;\n            T seg_r = points[i+1];\n  \
    \          \n            // \u533A\u9593\u5185\u3067\u306F\u6700\u5C0F\u5024\u3092\
    \u4E0E\u3048\u308B\u76F4\u7DDA\u306F\u5909\u308F\u3089\u306A\u3044\u306E\u3067\
    , \u5148\u982D\u306E\u70B9\u3067\u5224\u5B9A\u3059\u308B\n            T min_val\
    \ = lines[0].k * seg_l + lines[0].m;\n            size_t min_idx = 0;\n      \
    \      for (size_t j = 1; j < lines.size(); ++j) {\n                T val = lines[j].k\
    \ * seg_l + lines[j].m;\n                if (val < min_val) {\n              \
    \      min_val = val;\n                    min_idx = j;\n                }\n \
    \           }\n            \n            total += summation::linear(lines[min_idx].k,\
    \ lines[min_idx].m, seg_l, seg_r);\n        }\n\n        return total;\n    }\n\
    \n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059\
    .\n     * \n     * \u6761\u4EF6: p <= x <= q, r <= y <= s, x + y = k\n     * \n\
    \     * @tparam T \u6574\u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\n \
    \    * @param q x \u306E\u4E0A\u9650\n     * @param r y \u306E\u4E0B\u9650\n \
    \    * @param s y \u306E\u4E0A\u9650\n     * @param k \u548C k\n     * @return\
    \ T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\n     */\n\
    \    template<typename T>\n    T count_sum_eq(T p, T q, T r, T s, T k) {\n   \
    \     return count_sum_range(p, q, r, s, k, k);\n    }\n\n    /**\n     * @brief\
    \ \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44\
    \ (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\
    \u4EF6: p <= x <= q, r <= y <= s, a <= x + y <= b\n     * \n     * @tparam T \u6574\
    \u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\n     * @param q x \u306E\u4E0A\
    \u9650\n     * @param r y \u306E\u4E0B\u9650\n     * @param s y \u306E\u4E0A\u9650\
    \n     * @param a \u548C x + y \u306E\u4E0B\u9650\n     * @param b \u548C x +\
    \ y \u306E\u4E0A\u9650\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \ (x, y) \u306E\u500B\u6570\n     */\n    template<typename T>\n    T count_sum_range(T\
    \ p, T q, T r, T s, T a, T b) {\n        return count_between_lines<T>(0, r, 0,\
    \ s, -1, a, -1, b, p, q);\n    }\n\n    /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\
    \u3092\u6C42\u3081\u307E\u3059.\n     * \n     * \u6761\u4EF6: p <= x <= q, r\
    \ <= y <= s, x - y = k\n     * \n     * @tparam T \u6574\u6570\u578B\n     * @param\
    \ p x \u306E\u4E0B\u9650\n     * @param q x \u306E\u4E0A\u9650\n     * @param\
    \ r y \u306E\u4E0B\u9650\n     * @param s y \u306E\u4E0A\u9650\n     * @param\
    \ k \u5DEE k\n     * @return T \u6761\u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\
    \u500B\u6570\n     */\n    template<typename T>\n    T count_diff_eq(T p, T q,\
    \ T r, T s, T k) {\n        return count_sum_eq(p, q, -s, -r, k);\n    }\n\n \
    \   /**\n     * @brief \u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\
    \u6570\u306E\u7D44 (x, y) \u306E\u500B\u6570\u3092\u6C42\u3081\u307E\u3059.\n\
    \     * \n     * \u6761\u4EF6: p <= x <= q, r <= y <= s, a <= x - y <= b\n   \
    \  * \n     * @tparam T \u6574\u6570\u578B\n     * @param p x \u306E\u4E0B\u9650\
    \n     * @param q x \u306E\u4E0A\u9650\n     * @param r y \u306E\u4E0B\u9650\n\
    \     * @param s y \u306E\u4E0A\u9650\n     * @param a \u5DEE x - y \u306E\u4E0B\
    \u9650\n     * @param b \u5DEE x - y \u306E\u4E0A\u9650\n     * @return T \u6761\
    \u4EF6\u3092\u6E80\u305F\u3059 (x, y) \u306E\u500B\u6570\n     */\n    template<typename\
    \ T>\n    T count_diff_range(T p, T q, T r, T s, T a, T b) {\n        return count_sum_range(p,\
    \ q, -s, -r, a, b);\n    }\n}\n"
  dependsOn:
  - Summation/Summation.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Summation/Counting.hpp
  requiredBy: []
  timestamp: '2026-03-01 11:18:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Summation/Counting.hpp
layout: document
title: "\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44\u306E\u8A08\u4E0A"
---

## Outline

条件を満たす整数の組 $(x, y)$ の数を求める.

## Theory

### count_between_lines (1 つ)

以下を満たす整数の組 $(x, y)$ の数を求める.

* $ax+b \leq y \leq cx+d$.
* $l \leq x \leq r$.

$l \leq x \leq r$ である $x$ を固定する. このとき, 条件を満たす $y$ の数は

$$ \begin{cases} (cx+d)-(ax+b)+1 & (ax+b \leq cx+d) \\ 0 & (ax+b \gt cx+d) \end{cases} = \operatorname{relu}((c-a)x+(d-b+1))$$

となる. 従って, $x$ を走らせることにより, 求めるべき個数は

$$ \sum_{x=l}^r \operatorname{relu}((c-a)x+(d-b+1)) $$

である. よって, `relu_linear` を利用して求められる.

### count_between_lines (2 つ)

以下を満たす整数の組 $(x, y)$ の数を求める.

* $ax+b \leq y \leq cx+d$.
* $ex+f \leq y \leq gx+h$.
* $l \leq x \leq r$.

各 $x$ に対して, 条件を満たす $y$ の個数は

$$\begin{align*}
\max(0, \min(cx + d, gx + h) - \max(ax + b, ex + f) + 1)
&= \max(0, \min(
    (c - a)x + (d - b + 1),
    (c - e)x + (d - f + 1),
    (g - a)x + (h - b + 1),
    (g - e)x + (h - f + 1)))
\end{align*}$$

と分割できる.

よって, これら 4 つの直線の最小値 (ただし負なら0) の和を求める問題に帰着される.

従って, それぞれの直線について最小値を担う区間を計算し, その区間内における $\operatorname{relu}$ に関する総和を求めれば良い.

### count_sum_eq, count_sum_range

以下を満たす整数の組 $(x, y)$ の数を求める.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $a \leq x + y \leq b$.

この条件式を変形すると,

* $-x+a \leq y \leq -x+b$.
* $r \leq y \leq s$.
* $p \leq x \leq q$.

と変形できる. よって, `count_between_lines` に帰着できる.

また, 以下を満たす整数の組 $(x, y)$ の数は上での問題における $a = b = k$ とした特別バージョンである.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $x + y = k$.

### count_diff_eq, count_diff_range

以下を満たす整数の組 $(x, y)$ の数を求める.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $a \leq x - y \leq b$.

$y = -z$ と変数変換すると,

* $p \leq x \leq q$.
* $-s \leq z \leq -r$.
* $a \leq x + z \leq b$.

となり, `count_sum_range` に帰着できる.

## Contents

### count_between_lines

```cpp
template<typename T>
T count_between_lines(T a, T b, T c, T d, T l, T r)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $ax+b \leq cx+d$.
  * $l \leq x \leq r$.

```cpp
template<typename T>
T count_between_lines(T a, T b, T c, T d, T e, T f, T g, T h, T l, T r)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $ax+b \leq cx+d$.
  * $ex+f \leq gx+h$.
  * $l \leq x \leq r$.

### count_sum_eq

```cpp
template<typename T>
T count_sum_eq(T p, T q, T r, T s, T k)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $x + y = k$.

### count_sum_range

```cpp
template<typename T>
T count_sum_eq(T p, T q, T r, T s, T a, T b)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $a \leq x + y \leq b$.

### count_diff_eq

```cpp
template<typename T>
T count_diff_eq(T p, T q, T r, T s, T k)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $x - y = k$.

### count_diff_range

```cpp
template<typename T>
T count_diff_eq(T p, T q, T r, T s, T a, T b)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $a \leq x - y \leq b$.
