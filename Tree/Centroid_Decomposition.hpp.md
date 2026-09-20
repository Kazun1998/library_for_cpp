---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tree/Tree.hpp
    title: Tree/Tree.hpp
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
    path: verify/yosupo_library_checker/tree/Frequency_Table_of_Tree_Distance.test.cpp
    title: verify/yosupo_library_checker/tree/Frequency_Table_of_Tree_Distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u91CD\u5FC3\u5206\
      \u89E3\u3092\u69CB\u7BC9\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Tree/Centroid_Decomposition.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 2 \"Tree/Tree.hpp\"\n\n#line 4 \"Tree/Tree.hpp\"\n\nclass Tree\
    \ {\n    private:\n    int N, _offset, root;\n    vector<int> parent;\n    vector<vector<int>>\
    \ children;\n\n    bool locked;\n\n    public:\n    Tree(int N, int _offset =\
    \ 0): N(N), _offset(_offset) {\n        parent.assign(N + _offset, -1);\n    \
    \    locked = false;\n    }\n\n    bool is_locked() const { return locked; }\n\
    \n    public:\n    inline void set_root(const int &x) {\n        assert (!is_locked());\n\
    \        root = x;\n    }\n\n    inline int vector_size() const { return order()\
    \ + offset(); }\n\n    inline int get_root() const { return root; }\n    inline\
    \ int get_parent(const int &x) const { return parent[x]; }\n    inline vector<int>\
    \ get_children(const int &x) const { return children[x]; }\n\n    public:\n  \
    \  // \u9802\u70B9 x \u306E\u89AA\u3092\u9802\u70B9 y \u306B\u8A2D\u5B9A\u3059\
    \u308B.\n    inline void set_parent(const int &x, const int &y) {\n        assert\
    \ (!is_locked());\n        parent[x] = y;\n    }\n\n    // \u9802\u70B9 x \u306E\
    \u5B50\u306E\u4E00\u3064\u306B\u9802\u70B9 y \u3092\u8A2D\u5B9A\u3059\u308B.\n\
    \    inline void set_child(const int &x, const int &y) { set_parent(y, x); }\n\
    \n    // \u6728\u3092\u78BA\u5B9A\u3055\u305B\u308B\n    void seal() {\n     \
    \   assert(!is_locked());\n\n        parent[root] = -1;\n        children.assign(N\
    \ + offset(), vector<int>());\n        for (int v = offset(); v < N + offset();\
    \ v++) {\n            unless(is_root(v)) { children[parent[v]].emplace_back(v);\
    \ }\n        }\n\n        locked = true;\n        bfs();\n    }\n\n    private:\n\
    \    vector<int> depth;\n    vector<vector<int>> tower;\n    vector<int> _top_down,\
    \ _bottom_up;\n    void bfs() {\n        assert(is_locked());\n\n        tower.assign(N,\
    \ {});\n        depth.assign(N + offset(), -1);\n\n        deque<int> Q{ root\
    \ };\n        tower[0] = { root };\n        depth[root] = 0;\n\n        while\
    \ (!Q.empty()){\n            int x = Q.front(); Q.pop_front();\n\n           \
    \ for (int y: children[x]) {\n                depth[y] = depth[x] + 1;\n     \
    \           tower[depth[y]].emplace_back(y);\n                Q.push_back(y);\n\
    \            }\n        }\n\n        _top_down.clear();\n        _top_down.reserve(N);\n\
    \        for (const auto &layer : tower) {\n            for (int v: layer) _top_down.emplace_back(v);\n\
    \        }\n\n        _bottom_up.clear();\n        _bottom_up.reserve(N);\n  \
    \      for (auto it = tower.rbegin(); it != tower.rend(); ++it) {\n          \
    \  for (int v: *it) _bottom_up.emplace_back(v);\n        }\n    }\n\n    public:\n\
    \    const vector<int>& top_down() const { return _top_down; }\n\n    public:\n\
    \    const vector<int>& bottom_up() const { return _bottom_up; }\n\n    // 1 \u9802\
    \u70B9\u306B\u95A2\u3059\u308B\u60C5\u5831\n    public:\n\n    // x \u306F\u6839\
    ?\n    bool is_root(const int &x) const { return x == root; }\n\n    // x \u306F\
    \u8449?\n    bool is_leaf(const int &x) const {\n        assert(is_locked());\n\
    \        return children[x].empty();\n    }\n\n    // x \u306E\u6B21\u6570\n \
    \   int degree(const int &x) const {\n        assert(is_locked());\n        int\
    \ d = children[x].size();\n        if (is_root(x)) { d--; }\n        return d;\n\
    \    }\n\n    // \u9802\u70B9 x \u306E\u6DF1\u3055\u3092\u6C42\u3081\u308B.\n\
    \    inline int vertex_depth(const int &x) const { return depth[x]; }\n\n    //\
    \ 2 \u9802\u70B9\u306B\u95A2\u3059\u308B\u6761\u4EF6\n\n    // x \u306F y \u306E\
    \u89AA\u304B?\n    bool is_parent(const int &x, const int &y) const {\n      \
    \  assert(is_locked());\n        return !is_root(y) && x == parent[y];\n    }\n\
    \n    // x \u306F y \u306E\u500B\u304B?\n    inline bool is_children(const int\
    \ &x, const int &y) const { return is_parent(y, x); }\n\n    // x \u3068 y \u306F\
    \u5144\u5F1F (\u89AA\u304C\u540C\u3058) \u304B?\n    bool is_brother(const int\
    \ &x, const int &y) const {\n        assert(is_locked());\n        return !is_root(x)\
    \ && !is_root(y) && parent[x] == parent[y];\n    }\n\n    int lowest_common_ancestor_greedy(int\
    \ x, int y) const {\n        assert(is_locked());\n\n        if (vertex_depth(x)\
    \ > vertex_depth(y)) { swap(x, y); }\n\n        while (vertex_depth(x) < vertex_depth(y))\
    \ {\n            y = parent[y];\n        }\n\n        while (x != y) {\n     \
    \       x = get_parent(x);\n            y = get_parent(y);\n        }\n\n    \
    \    return x;\n    }\n\n    private:\n    bool has_euler_tour_vertex = false,\
    \ has_euler_tour_edge = false;\n\n    public:\n    vector<int> in_time, out_time;\n\
    \    vector<int> euler_tour_vertex;\n    vector<tuple<int, int, int>> euler_tour_edge;\n\
    \n    // Euler Tour \u306B\u95A2\u3059\u308B\u8A08\u7B97\u3092\u884C\u3046.\n\
    \    void calculate_euler_tour_vertex() {\n        if(has_euler_tour_vertex) {\
    \ return; }\n\n        euler_tour_vertex.clear();\n        in_time.assign(N +\
    \ offset(), -1);\n        out_time.assign(N + offset(), -1);\n\n        auto dfs\
    \ = [&](auto self, int x) -> void {\n            in_time[x] = (int)euler_tour_vertex.size();\n\
    \            euler_tour_vertex.emplace_back(x);\n\n            for (int y: children[x])\
    \ {\n                self(self, y);\n            }\n\n            out_time[x]\
    \ = (int)euler_tour_vertex.size() - 1;\n            unless(is_root(x)) { euler_tour_vertex.emplace_back(parent[x]);\
    \ }\n        };\n\n        dfs(dfs, root);\n\n        has_euler_tour_vertex =\
    \ true;\n    }\n\n    void calculate_euler_tour_edge() {\n        if(has_euler_tour_edge)\
    \ { return; }\n\n        calculate_euler_tour_vertex();\n        euler_tour_edge.clear();\n\
    \n        for (int t = 0; t < 2 * (N - 1); t++) {\n            int x = euler_tour_vertex[t],\
    \ y = euler_tour_vertex[t + 1];\n            int k = (x == parent[y]) ? 1 : -1;\n\
    \            euler_tour_edge.emplace_back(make_tuple(x, y, k));\n        }\n\n\
    \        has_euler_tour_edge = true;\n    }\n\n    vector<int> path(int u, int\
    \ v) const {\n        int w = lowest_common_ancestor_greedy(u, v);\n\n       \
    \ vector<int> path_first{u}, path_second{v};\n\n        while (u != w) {\n   \
    \         u = get_parent(u);\n            path_first.emplace_back(u);\n      \
    \  }\n\n        while (v != w) {\n            v = get_parent(v);\n           \
    \ path_second.emplace_back(v);\n        }\n\n        path_second.pop_back();\n\
    \        reverse(path_second.begin(), path_second.end());\n\n        path_first.insert(path_first.end(),\
    \ make_move_iterator(path_second.begin()), make_move_iterator(path_second.end()));\n\
    \n        return path_first;\n    }\n\n    inline int order() const { return N;\
    \ }\n    inline int offset() const { return _offset; }\n};\n\nTree Construct_Tree(int\
    \ N, vector<pair<int, int>> edges, int root, int offset = 0) {\n    vector<vector<int>>\
    \ adj(N + offset, vector<int>());\n    for (auto &[u, v]: edges) {\n        adj[u].emplace_back(v);\n\
    \        adj[v].emplace_back(u);\n    }\n\n    Tree T(N, offset);\n    T.set_root(root);\n\
    \n    vector<bool> seen(N + 1, false);\n    seen[root] = true;\n    vector<int>\
    \ stack({root});\n\n    until(stack.empty()) {\n        int v = stack.back();\n\
    \        stack.pop_back();\n\n        for (int w: adj[v]) {\n            if (seen[w])\
    \ { continue; }\n\n            seen[w] = true;\n            T.set_parent(w, v);\n\
    \            stack.emplace_back(w);\n        }\n    }\n\n    T.seal();\n    return\
    \ T;\n}\n#line 5 \"Tree/Centroid_Decomposition.hpp\"\n\nclass Centroid_Decomposition\
    \ {\n    private:\n    int N, _offset;\n    vector<vector<int>> adj;\n    vector<int>\
    \ centroid_parent, centroid_depth;\n    vector<int> decomposition_order;\n   \
    \ vector<bool> removed;\n    vector<int> subtree_size;\n    vector<vector<int>>\
    \ component_vertices;\n\n    private:\n    // Tree \u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u3092 (\u89AA, \u5B50) \u306E\u8FBA\u30EA\u30B9\u30C8\u306B\u5909\u63DB\
    \u3059\u308B.\n    static vector<pair<int, int>> to_edges(const Tree &tree) {\n\
    \        assert(tree.is_locked());\n\n        vector<pair<int, int>> edges;\n\
    \        for (int v = tree.offset(); v < tree.order() + tree.offset(); v++) {\n\
    \            for (int c: tree.get_children(v)) { edges.emplace_back(v, c); }\n\
    \        }\n        return edges;\n    }\n\n    public:\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u91CD\u5FC3\u5206\u89E3\u3092\u69CB\
    \u7BC9\u3059\u308B.\n     * @param tree \u5BFE\u8C61\u3068\u306A\u308B Tree \u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8. \u4E8B\u524D\u306B seal() \u3057\u3066\u3044\u308B\
    \u5FC5\u8981\u304C\u3042\u308B.\n     */\n    Centroid_Decomposition(const Tree\
    \ &tree): Centroid_Decomposition(tree.order(), to_edges(tree), tree.offset())\
    \ {}\n\n    Centroid_Decomposition(int N, const vector<pair<int, int>> &edges,\
    \ int offset = 0): N(N), _offset(offset) {\n        adj.assign(N + offset, {});\n\
    \        for (auto &[u, v]: edges) {\n            adj[u].emplace_back(v);\n  \
    \          adj[v].emplace_back(u);\n        }\n\n        centroid_parent.assign(N\
    \ + offset, -1);\n        centroid_depth.assign(N + offset, -1);\n        removed.assign(N\
    \ + offset, false);\n        subtree_size.assign(N + offset, 0);\n        component_vertices.assign(N\
    \ + offset, {});\n        decomposition_order.reserve(N);\n\n        build(offset,\
    \ -1, 0);\n    }\n\n    private:\n    // x \u3092\u6839\u3068\u3059\u308B (removed\
    \ \u306A\u9802\u70B9\u3092\u9664\u3044\u305F) \u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\u3092\u8A08\u7B97\u3059\u308B.\n    int calculate_subtree_size(int x, int\
    \ p) {\n        subtree_size[x] = 1;\n        for (int y: adj[x]) {\n        \
    \    if (y == p || removed[y]) { continue; }\n            subtree_size[x] += calculate_subtree_size(y,\
    \ x);\n        }\n        return subtree_size[x];\n    }\n\n    // x \u3092\u542B\
    \u3080\u9023\u7D50\u6210\u5206 (\u30B5\u30A4\u30BA total) \u306E\u91CD\u5FC3\u3092\
    \u6C42\u3081\u308B.\n    int find_centroid(int x, int p, int total) {\n      \
    \  for (int y: adj[x]) {\n            if (y == p || removed[y]) { continue; }\n\
    \            if (subtree_size[y] > total / 2) {\n                subtree_size[x]\
    \ = total - subtree_size[y];\n                return find_centroid(y, x, total);\n\
    \            }\n        }\n        return x;\n    }\n\n    // x \u3092\u6839\u3068\
    \u3059\u308B (removed \u306A\u9802\u70B9\u3092\u9664\u3044\u305F) \u90E8\u5206\
    \u6728\u306E\u9802\u70B9\u4E00\u89A7\u3092 out \u306B\u96C6\u3081\u308B.\n   \
    \ void collect_component(int x, int p, vector<int> &out) {\n        out.emplace_back(x);\n\
    \        for (int y: adj[x]) {\n            if (y == p || removed[y]) { continue;\
    \ }\n            collect_component(y, x, out);\n        }\n    }\n\n    void build(int\
    \ start, int parent_centroid, int depth) {\n        int total = calculate_subtree_size(start,\
    \ -1);\n        int c = find_centroid(start, -1, total);\n\n        centroid_parent[c]\
    \ = parent_centroid;\n        centroid_depth[c] = depth;\n        decomposition_order.emplace_back(c);\n\
    \n        component_vertices[c].reserve(total);\n        collect_component(c,\
    \ -1, component_vertices[c]);\n\n        removed[c] = true;\n        for (int\
    \ y: adj[c]) {\n            unless(removed[y]) { build(y, c, depth + 1); }\n \
    \       }\n    }\n\n    public:\n    // \u91CD\u5FC3\u6728\u4E0A\u3067\u306E x\
    \ \u306E\u89AA (x \u304C\u6839\u306A\u3089 -1).\n    inline int get_centroid_parent(const\
    \ int &x) const { return centroid_parent[x]; }\n\n    // \u91CD\u5FC3\u6728\u4E0A\
    \u3067\u306E x \u306E\u6DF1\u3055 (\u6700\u521D\u306B\u53D6\u308A\u9664\u304B\u308C\
    \u305F\u9802\u70B9\u304C\u6DF1\u3055 0).\n    inline int get_centroid_depth(const\
    \ int &x) const { return centroid_depth[x]; }\n\n    // \u91CD\u5FC3\u3092\u53D6\
    \u308A\u9664\u3044\u305F\u9806\u756A (= \u91CD\u5FC3\u6728\u3092\u6DF1\u3055\u306E\
    \u6D45\u3044\u65B9\u304B\u3089\u4E26\u3079\u305F\u3082\u306E).\n    const vector<int>&\
    \ order() const { return decomposition_order; }\n\n    // \u91CD\u5FC3\u6728\u306E\
    \u6839.\n    inline int get_root() const { return decomposition_order.front();\
    \ }\n\n    // \u91CD\u5FC3 x \u304C\u53D6\u308A\u9664\u304B\u308C\u305F\u969B\u306B\
    \u5C5E\u3057\u3066\u3044\u305F\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u4E00\
    \u89A7 (x \u81EA\u8EAB\u3092\u542B\u3080).\n    inline const vector<int>& get_component(const\
    \ int &x) const { return component_vertices[x]; }\n\n    inline int vertex_size()\
    \ const { return N; }\n    inline int offset() const { return _offset; }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n#include\"Tree.hpp\"\
    \n\nclass Centroid_Decomposition {\n    private:\n    int N, _offset;\n    vector<vector<int>>\
    \ adj;\n    vector<int> centroid_parent, centroid_depth;\n    vector<int> decomposition_order;\n\
    \    vector<bool> removed;\n    vector<int> subtree_size;\n    vector<vector<int>>\
    \ component_vertices;\n\n    private:\n    // Tree \u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u3092 (\u89AA, \u5B50) \u306E\u8FBA\u30EA\u30B9\u30C8\u306B\u5909\u63DB\
    \u3059\u308B.\n    static vector<pair<int, int>> to_edges(const Tree &tree) {\n\
    \        assert(tree.is_locked());\n\n        vector<pair<int, int>> edges;\n\
    \        for (int v = tree.offset(); v < tree.order() + tree.offset(); v++) {\n\
    \            for (int c: tree.get_children(v)) { edges.emplace_back(v, c); }\n\
    \        }\n        return edges;\n    }\n\n    public:\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u91CD\u5FC3\u5206\u89E3\u3092\u69CB\
    \u7BC9\u3059\u308B.\n     * @param tree \u5BFE\u8C61\u3068\u306A\u308B Tree \u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8. \u4E8B\u524D\u306B seal() \u3057\u3066\u3044\u308B\
    \u5FC5\u8981\u304C\u3042\u308B.\n     */\n    Centroid_Decomposition(const Tree\
    \ &tree): Centroid_Decomposition(tree.order(), to_edges(tree), tree.offset())\
    \ {}\n\n    Centroid_Decomposition(int N, const vector<pair<int, int>> &edges,\
    \ int offset = 0): N(N), _offset(offset) {\n        adj.assign(N + offset, {});\n\
    \        for (auto &[u, v]: edges) {\n            adj[u].emplace_back(v);\n  \
    \          adj[v].emplace_back(u);\n        }\n\n        centroid_parent.assign(N\
    \ + offset, -1);\n        centroid_depth.assign(N + offset, -1);\n        removed.assign(N\
    \ + offset, false);\n        subtree_size.assign(N + offset, 0);\n        component_vertices.assign(N\
    \ + offset, {});\n        decomposition_order.reserve(N);\n\n        build(offset,\
    \ -1, 0);\n    }\n\n    private:\n    // x \u3092\u6839\u3068\u3059\u308B (removed\
    \ \u306A\u9802\u70B9\u3092\u9664\u3044\u305F) \u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\u3092\u8A08\u7B97\u3059\u308B.\n    int calculate_subtree_size(int x, int\
    \ p) {\n        subtree_size[x] = 1;\n        for (int y: adj[x]) {\n        \
    \    if (y == p || removed[y]) { continue; }\n            subtree_size[x] += calculate_subtree_size(y,\
    \ x);\n        }\n        return subtree_size[x];\n    }\n\n    // x \u3092\u542B\
    \u3080\u9023\u7D50\u6210\u5206 (\u30B5\u30A4\u30BA total) \u306E\u91CD\u5FC3\u3092\
    \u6C42\u3081\u308B.\n    int find_centroid(int x, int p, int total) {\n      \
    \  for (int y: adj[x]) {\n            if (y == p || removed[y]) { continue; }\n\
    \            if (subtree_size[y] > total / 2) {\n                subtree_size[x]\
    \ = total - subtree_size[y];\n                return find_centroid(y, x, total);\n\
    \            }\n        }\n        return x;\n    }\n\n    // x \u3092\u6839\u3068\
    \u3059\u308B (removed \u306A\u9802\u70B9\u3092\u9664\u3044\u305F) \u90E8\u5206\
    \u6728\u306E\u9802\u70B9\u4E00\u89A7\u3092 out \u306B\u96C6\u3081\u308B.\n   \
    \ void collect_component(int x, int p, vector<int> &out) {\n        out.emplace_back(x);\n\
    \        for (int y: adj[x]) {\n            if (y == p || removed[y]) { continue;\
    \ }\n            collect_component(y, x, out);\n        }\n    }\n\n    void build(int\
    \ start, int parent_centroid, int depth) {\n        int total = calculate_subtree_size(start,\
    \ -1);\n        int c = find_centroid(start, -1, total);\n\n        centroid_parent[c]\
    \ = parent_centroid;\n        centroid_depth[c] = depth;\n        decomposition_order.emplace_back(c);\n\
    \n        component_vertices[c].reserve(total);\n        collect_component(c,\
    \ -1, component_vertices[c]);\n\n        removed[c] = true;\n        for (int\
    \ y: adj[c]) {\n            unless(removed[y]) { build(y, c, depth + 1); }\n \
    \       }\n    }\n\n    public:\n    // \u91CD\u5FC3\u6728\u4E0A\u3067\u306E x\
    \ \u306E\u89AA (x \u304C\u6839\u306A\u3089 -1).\n    inline int get_centroid_parent(const\
    \ int &x) const { return centroid_parent[x]; }\n\n    // \u91CD\u5FC3\u6728\u4E0A\
    \u3067\u306E x \u306E\u6DF1\u3055 (\u6700\u521D\u306B\u53D6\u308A\u9664\u304B\u308C\
    \u305F\u9802\u70B9\u304C\u6DF1\u3055 0).\n    inline int get_centroid_depth(const\
    \ int &x) const { return centroid_depth[x]; }\n\n    // \u91CD\u5FC3\u3092\u53D6\
    \u308A\u9664\u3044\u305F\u9806\u756A (= \u91CD\u5FC3\u6728\u3092\u6DF1\u3055\u306E\
    \u6D45\u3044\u65B9\u304B\u3089\u4E26\u3079\u305F\u3082\u306E).\n    const vector<int>&\
    \ order() const { return decomposition_order; }\n\n    // \u91CD\u5FC3\u6728\u306E\
    \u6839.\n    inline int get_root() const { return decomposition_order.front();\
    \ }\n\n    // \u91CD\u5FC3 x \u304C\u53D6\u308A\u9664\u304B\u308C\u305F\u969B\u306B\
    \u5C5E\u3057\u3066\u3044\u305F\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u4E00\
    \u89A7 (x \u81EA\u8EAB\u3092\u542B\u3080).\n    inline const vector<int>& get_component(const\
    \ int &x) const { return component_vertices[x]; }\n\n    inline int vertex_size()\
    \ const { return N; }\n    inline int offset() const { return _offset; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  - Tree/Tree.hpp
  isVerificationFile: false
  path: Tree/Centroid_Decomposition.hpp
  requiredBy: []
  timestamp: '2026-09-20 18:46:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/tree/Frequency_Table_of_Tree_Distance.test.cpp
documentation_of: Tree/Centroid_Decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3 (Centroid Decomposition)"
---

## Outline

木 $T = (V, E)$ に対して重心分解を行う.

## Theory

木 $T = (V, E)$ に対して, その頂点を取り除いてできる各連結成分の頂点数が, いずれも元の木の頂点数の半分以下になるような頂点を木 $T$ の重心という.

任意の木に対する重心は $1$ 個または $2$ 個であること, また, $2$ 個ある場合は隣接している頂点同士であることが証明できる.

以下の手続きを再帰的に行うことによる木の分解を重心分解という.

1. 現在の連結成分の重心 $c$ を 1 つ選ぶ.
2. $c$ を取り除く.
3. $c$ を取り除いてできる各連結成分に対して, 1. に戻って同じ手続きを行う.

重心を取り除くたびに連結成分の頂点数が半分以下になるため, この再帰は深さ $O(\log N)$ で終了する. また, 取り除かれた重心たちを「取り除かれた時点で属していた連結成分の直前の重心」を親とみなすことで木とみなせる. このような木を重心木と呼ぶ.

重心分解は, $2$ 頂点間のパスに関するクエリを効率的に処理する際に用いられる. 頂点 $u, v$ を結ぶパスは, 重心分解の過程で $u, v$ が最後に同じ連結成分に属していた際の重心 (すなわち重心木上での $u, v$ の最近共通祖先) を必ず経由する. そのため, 各重心 $c$ について「$c$ を通るパスに関する情報」を前計算しておけば, 重心木の深さが $O(\log N)$ であることから, 全体で効率よくクエリを処理できる.

## Examples

[[Library Checker] Frequency Table of Tree Distance](https://judge.yosupo.jp/problem/frequency_table_of_tree_distance)

各重心 $c$ について, $c$ を含む連結成分内での $c$ からの距離を集計し, $c$ を経由する 2 頂点間の距離の個数を求める. ただし, $c$ の各子の部分木内だけで完結するペアは $c$ を経由しないため, 包除原理により差し引く必要がある.

## Contents

### Constructor

```cpp
Centroid_Decomposition(const Tree &tree)
```

* `Tree` オブジェクトから重心分解を構築する.
* **引数**
  * `tree`: 対象となる `Tree` オブジェクト. 事前に `seal()` している必要がある.
* **計算量**: $T$ の位数を $N$ として, $O(N \log N)$ 時間.

```cpp
Centroid_Decomposition(int N, const vector<pair<int, int>> &edges, int offset = 0)
```

* 頂点数 $N$ と辺のリストから重心分解を構築する.
* **引数**
  * $N$: 頂点数.
  * `edges`: 木を構成する辺のリスト.
  * `offset`: 頂点番号のオフセット.
* **計算量**: $O(N \log N)$ 時間.

### order

```cpp
const vector<int>& order() const
```

* 重心を取り除いた順番のリストを返す (重心木を根から深さの浅い順に並べたものに一致する).
* **返り値**: 重心を取り除いた順に並べた頂点のリスト.
* **計算量**: $O(1)$ 時間.

### get_root

```cpp
int get_root() const
```

* 重心木の根 (最初に取り除かれた頂点) を返す.
* **計算量**: $O(1)$ 時間.

### get_centroid_parent

```cpp
int get_centroid_parent(const int &x) const
```

* 重心木上での頂点 $x$ の親を返す.
* **引数**
  * $x$: 頂点.
* **返り値**
  * $x$ が重心木の根であれば `-1`
  * そうでなければ, 重心木における $x$ の親. つまり, $x$ が取り除かれた時点で属していた連結成分の直前の重心.
* **計算量**: $O(1)$ 時間.

### get_centroid_depth

```cpp
int get_centroid_depth(const int &x) const
```

* 重心木上での頂点 $x$ の深さを返す (根の深さは $0$).
* **引数**
  * $x$: 頂点.
* **計算量**: $O(1)$ 時間.
