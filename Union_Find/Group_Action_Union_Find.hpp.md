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
    document_title: "Group_Action_Union_Find \u3092\u69CB\u7BC9\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Union_Find/Group_Action_Union_Find.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T,\
    \ integral U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n    \
    \    if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n\
    \    }\n\n    return a;\n}\n\ntemplate<typename T>\nT sum(const vector<T> &X)\
    \ {\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n\
    template<typename T>\nT gcd(const T x, const T y) {\n    return y == 0 ? x : gcd(y,\
    \ x % y);\n}\n\n// a x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\
    \u7D44 (a, b) \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B\
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
    \ \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ... >>\
    \ a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout\
    \ << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
    \    return is;\n}\n\ntemplate<typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &P){\n    os << P.first << \" \" << P.second;\n    return\
    \ os;\n}\n\ntemplate<typename T>\nvector<T> vector_input(int N, int index){\n\
    \    vector<T> X(N+index);\n    for (int i=index; i<index+N; i++) cin >> X[i];\n\
    \    return X;\n}\n\ntemplate<typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &X){\n    for (auto &x: X) { is >> x; }\n    return is;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &X){\n    int s = (int)X.size();\n\
    \    for (int i = 0; i < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return\
    \ os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const unordered_set<T>\
    \ &S){\n    int i = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n\
    \    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ set<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a;\
    \ i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os\
    \ << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\n\
    ostream &operator<<(ostream &os, const multiset<T> &S){\n    int i = 0;\n    for\
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nstd::vector<T> input_vector(size_t n, size_t offset = 0) {\n    std::vector<T>\
    \ res;\n    // \u6700\u521D\u306B\u5FC5\u8981\u306A\u5168\u5BB9\u91CF\u3092\u78BA\
    \u4FDD\uFF08\u518D\u78BA\u4FDD\u3092\u9632\u3050\uFF09\n    res.reserve(n + offset);\n\
    \    // offset \u5206\u3092\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3067\u57CB\u3081\
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
    \ + \u9006\u5143\ntemplate <typename G, auto op, auto identity, auto inv>\nconcept\
    \ Group_Concept = \n    Monoid_Concept<G, op, identity>\n    && Unary_Operator_Concept<decltype(inv),\
    \ G>;\n\n// \u9806\u5E8F\u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u7FA4 + \u5168\
    \u9806\u5E8F\ntemplate <typename G, auto op, auto identity, auto inv>\nconcept\
    \ Totally_Ordered_Group_Concept = \n    Group_Concept<G, op, identity, inv>\n\
    \    && totally_ordered<G>;\n\n// \u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\u30B3\u30F3\
    \u30BB\u30D7\u30C8\ntemplate<typename T>\nconcept Hashable = requires(T x) {\n\
    \    { hash<T>{}(x) } -> convertible_to<size_t>;\n};\n#line 5 \"Union_Find/Group_Action_Union_Find.hpp\"\
    \n\ntemplate<class G, auto op, G identity, auto inv>\nrequires Group_Concept<G,\
    \ op, identity, inv>\nclass Group_Action_Union_Find {\n    private:\n    vector<vector<int>>\
    \ groups;\n    vector<int> belong;\n    vector<G> lazy, eager;\n\n    public:\n\
    \    /**\n     * @brief Group_Action_Union_Find \u3092\u69CB\u7BC9\u3059\u308B\
    .\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit Group_Action_Union_Find(int\
    \ n) {\n        groups.resize(n);\n        belong.resize(n);\n        lazy.assign(n,\
    \ identity);\n        eager.assign(n, identity);\n\n        for (int i = 0; i\
    \ < n; ++i) {\n            groups[i] = {i};\n            belong[i] = i;\n    \
    \    }\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B.\n  \
    \   * @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    int find(int x)\
    \ const { return belong[x]; }\n\n    /**\n     * @brief \u9802\u70B9 x \u3068\u9802\
    \u70B9 y \u3092\u7D50\u3076.\n     * @param x \u9802\u70B9\n     * @param y \u9802\
    \u70B9\n     * @return \u3059\u3067\u306B\u9023\u7D50\u3060\u3063\u305F\u5834\u5408\
    \u306F false, \u65B0\u305F\u306B\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408\
    \u306F true\n     */\n    bool unite(int x, int y) {\n        x = find(x);\n \
    \       y = find(y);\n        if (x == y) return false;\n\n        // \u5C0F\u3055\
    \u3044\u65B9\u3092\u5927\u304D\u3044\u65B9\u306B\u30DE\u30FC\u30B8 (Union by Size)\n\
    \        if (groups[x].size() < groups[y].size()) {\n            swap(x, y);\n\
    \        }\n\n        const G d = op(inv(lazy[x]), lazy[y]);\n\n        for (int\
    \ z : groups[y]) {\n            belong[z] = x;\n            groups[x].push_back(z);\n\
    \            eager[z] = op(d, eager[z]);\n        }\n\n        groups[y].clear();\n\
    \        return true;\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u3068\u9802\
    \u70B9 y \u304C\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u304B\
    \u3092\u5224\u5B9A\u3059\u308B.\n     * @param x \u9802\u70B9\n     * @param y\
    \ \u9802\u70B9\n     * @return \u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\
    \u3059\u308B\u5834\u5408\u306F true, \u305D\u3046\u3067\u306A\u3044\u5834\u5408\
    \u306F false\n     */\n    bool same(int x, int y) const { return find(x) == find(y);\
    \ }\n\n    /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B.\n     * @param x\
    \ \u9802\u70B9\n     * @return \u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \n     */\n    int size(int x) const { return groups[find(x)].size(); }\n\n  \
    \  /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u5168\u4F53\u306B\u3001\u5DE6\u304B\u3089\u4F5C\u7528 a \u3092\u9069\u7528\
    \u3059\u308B.\n     * @param x \u9802\u70B9\n     * @param a \u4F5C\u7528\u3055\
    \u305B\u308B\u7FA4\u306E\u5143\n     */\n    void action(int x, G a) {\n     \
    \   x = find(x);\n        lazy[x] = op(a, lazy[x]);\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 x \u306E\u5024 V(x) \u306B\u3001\u5DE6\u304B\u3089\u4F5C\
    \u7528 a \u3092\u9069\u7528\u3057 V(x) <- a\u30FBV(x) \u3068\u3059\u308B.\n  \
    \   * @param x \u9802\u70B9\n     * @param a \u4F5C\u7528\u3055\u305B\u308B\u7FA4\
    \u306E\u5143\n     */\n    void vertex_action(int x, G a) {\n        update(x,\
    \ op(a, get(x)));\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u306E\u5024\
    \u3092 a \u306B\u66F4\u65B0\u3059\u308B.\n     * @param x \u9802\u70B9\n     *\
    \ @param a \u66F4\u65B0\u5F8C\u306E\u5024\n     */\n    void update(int x, const\
    \ G& a) { eager[x] = op(inv(lazy[find(x)]), a); }\n\n    /**\n     * @brief \u9802\
    \u70B9 x \u306E\u73FE\u5728\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n     *\
    \ @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u306E\u73FE\u5728\u306E\
    \u5024\n     */\n    G get(int x) const { return op(lazy[find(x)], eager[x]);\
    \ }\n\n    /**\n     * @brief \u9802\u70B9 x \u306E\u73FE\u5728\u306E\u5024\u3092\
    \u53D6\u5F97\u3059\u308B. get(x) \u306E\u30A8\u30A4\u30EA\u30A2\u30B9.\n     *\
    \ @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u306E\u73FE\u5728\u306E\
    \u5024\n     */\n    G operator[](int x) const { return get(x); }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n#include \"../template/concepts.hpp\"\
    \n\ntemplate<class G, auto op, G identity, auto inv>\nrequires Group_Concept<G,\
    \ op, identity, inv>\nclass Group_Action_Union_Find {\n    private:\n    vector<vector<int>>\
    \ groups;\n    vector<int> belong;\n    vector<G> lazy, eager;\n\n    public:\n\
    \    /**\n     * @brief Group_Action_Union_Find \u3092\u69CB\u7BC9\u3059\u308B\
    .\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit Group_Action_Union_Find(int\
    \ n) {\n        groups.resize(n);\n        belong.resize(n);\n        lazy.assign(n,\
    \ identity);\n        eager.assign(n, identity);\n\n        for (int i = 0; i\
    \ < n; ++i) {\n            groups[i] = {i};\n            belong[i] = i;\n    \
    \    }\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B.\n  \
    \   * @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    int find(int x)\
    \ const { return belong[x]; }\n\n    /**\n     * @brief \u9802\u70B9 x \u3068\u9802\
    \u70B9 y \u3092\u7D50\u3076.\n     * @param x \u9802\u70B9\n     * @param y \u9802\
    \u70B9\n     * @return \u3059\u3067\u306B\u9023\u7D50\u3060\u3063\u305F\u5834\u5408\
    \u306F false, \u65B0\u305F\u306B\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408\
    \u306F true\n     */\n    bool unite(int x, int y) {\n        x = find(x);\n \
    \       y = find(y);\n        if (x == y) return false;\n\n        // \u5C0F\u3055\
    \u3044\u65B9\u3092\u5927\u304D\u3044\u65B9\u306B\u30DE\u30FC\u30B8 (Union by Size)\n\
    \        if (groups[x].size() < groups[y].size()) {\n            swap(x, y);\n\
    \        }\n\n        const G d = op(inv(lazy[x]), lazy[y]);\n\n        for (int\
    \ z : groups[y]) {\n            belong[z] = x;\n            groups[x].push_back(z);\n\
    \            eager[z] = op(d, eager[z]);\n        }\n\n        groups[y].clear();\n\
    \        return true;\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u3068\u9802\
    \u70B9 y \u304C\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u304B\
    \u3092\u5224\u5B9A\u3059\u308B.\n     * @param x \u9802\u70B9\n     * @param y\
    \ \u9802\u70B9\n     * @return \u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u5C5E\
    \u3059\u308B\u5834\u5408\u306F true, \u305D\u3046\u3067\u306A\u3044\u5834\u5408\
    \u306F false\n     */\n    bool same(int x, int y) const { return find(x) == find(y);\
    \ }\n\n    /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u6C42\u3081\u308B.\n     * @param x\
    \ \u9802\u70B9\n     * @return \u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \n     */\n    int size(int x) const { return groups[find(x)].size(); }\n\n  \
    \  /**\n     * @brief \u9802\u70B9 x \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u5168\u4F53\u306B\u3001\u5DE6\u304B\u3089\u4F5C\u7528 a \u3092\u9069\u7528\
    \u3059\u308B.\n     * @param x \u9802\u70B9\n     * @param a \u4F5C\u7528\u3055\
    \u305B\u308B\u7FA4\u306E\u5143\n     */\n    void action(int x, G a) {\n     \
    \   x = find(x);\n        lazy[x] = op(a, lazy[x]);\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 x \u306E\u5024 V(x) \u306B\u3001\u5DE6\u304B\u3089\u4F5C\
    \u7528 a \u3092\u9069\u7528\u3057 V(x) <- a\u30FBV(x) \u3068\u3059\u308B.\n  \
    \   * @param x \u9802\u70B9\n     * @param a \u4F5C\u7528\u3055\u305B\u308B\u7FA4\
    \u306E\u5143\n     */\n    void vertex_action(int x, G a) {\n        update(x,\
    \ op(a, get(x)));\n    }\n\n    /**\n     * @brief \u9802\u70B9 x \u306E\u5024\
    \u3092 a \u306B\u66F4\u65B0\u3059\u308B.\n     * @param x \u9802\u70B9\n     *\
    \ @param a \u66F4\u65B0\u5F8C\u306E\u5024\n     */\n    void update(int x, const\
    \ G& a) { eager[x] = op(inv(lazy[find(x)]), a); }\n\n    /**\n     * @brief \u9802\
    \u70B9 x \u306E\u73FE\u5728\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n     *\
    \ @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u306E\u73FE\u5728\u306E\
    \u5024\n     */\n    G get(int x) const { return op(lazy[find(x)], eager[x]);\
    \ }\n\n    /**\n     * @brief \u9802\u70B9 x \u306E\u73FE\u5728\u306E\u5024\u3092\
    \u53D6\u5F97\u3059\u308B. get(x) \u306E\u30A8\u30A4\u30EA\u30A2\u30B9.\n     *\
    \ @param x \u9802\u70B9\n     * @return \u9802\u70B9 x \u306E\u73FE\u5728\u306E\
    \u5024\n     */\n    G operator[](int x) const { return get(x); }\n};"
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
  path: Union_Find/Group_Action_Union_Find.hpp
  requiredBy: []
  timestamp: '2026-03-22 18:53:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Union_Find/Group_Action_Union_Find.hpp
layout: document
redirect_from:
- /library/Union_Find/Group_Action_Union_Find.hpp
- /library/Union_Find/Group_Action_Union_Find.hpp.html
title: "Group_Action_Union_Find \u3092\u69CB\u7BC9\u3059\u308B."
---
