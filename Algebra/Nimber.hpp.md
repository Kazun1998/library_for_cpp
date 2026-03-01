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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
    title: verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "x * y \u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u30D8\u30EB\u30D1\
      \u30FC\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"Algebra/Nimber.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ {\n        return message.c_str();\n    }\n};\n#line 4 \"Algebra/Nimber.hpp\"\
    \n\nclass Nimber {\n    public:\n    Nimber(): x(0) {}\n    Nimber(uint64_t x):\
    \ x(x) {}\n\n    Nimber operator-() const { return Nimber(x); }\n\n    Nimber&\
    \ operator+=(const Nimber &b) {\n        x ^= b.x;\n        return *this;\n  \
    \  }\n\n    friend Nimber operator+(const Nimber &x, const Nimber &y) { return\
    \ Nimber(x) += y; }\n\n    Nimber& operator-=(const Nimber &b) {\n        *this\
    \ += b;\n        return *this;\n    }\n\n    friend Nimber operator-(const Nimber\
    \ &x, const Nimber &y) { return Nimber(x) -= y; }\n\n    // \u4E57\u6CD5\n   \
    \ Nimber& operator*=(const Nimber &b) {\n        if ((x | b.x) < 256) {\n    \
    \        if (!table_initialized) init_table();\n            x = small_table[x][b.x];\n\
    \            return *this;\n        }\n        int level = max(calculate_level(x),\
    \ calculate_level(b.x));\n        x = calculate_mul(x, b.x, level);\n        return\
    \ *this;\n    }\n\n    friend Nimber operator*(const Nimber &x, const Nimber &y)\
    \ { return Nimber(x) *= y; }\n\n    friend bool operator==(const Nimber &a, const\
    \ Nimber &b) { return a.x == b.x; }\n    friend bool operator!=(const Nimber &a,\
    \ const Nimber &b) { return a.x != b.x; }\n    friend bool operator<(const Nimber\
    \ &a, const Nimber &b) { return a.x < b.x; }\n\n    Nimber square() const {\n\
    \        if (x < 256) {\n            if (!table_initialized) init_table();\n \
    \           return small_table[x][x];\n        }\n        int level = calculate_level(x);\n\
    \        return Nimber(calculate_square(x, level));\n    }\n\n    // \u5165\u529B\
    \n    friend istream &operator>>(istream &is, Nimber &a) {\n        is >> a.x;\n\
    \        return is;\n    }\n\n    // \u51FA\u529B\n    friend ostream &operator<<(ostream\
    \ &os, const Nimber &a) { return os << a.x; }\n\n    Nimber inverse() const;\n\
    \n    Nimber sqrt() {\n        if (x < 256) {\n            if (!table_initialized)\
    \ init_table();\n            return Nimber(small_sqrt_table[x]);\n        }\n\n\
    \        int level = calculate_level(x);\n        return Nimber(calculate_sqrt(x,\
    \ level));\n    }\n\n    bool is_zero() const { return x == 0; }\n\n    private:\n\
    \    uint64_t x;\n\n    inline static uint8_t small_table[256][256];\n    inline\
    \ static bool table_initialized = false;\n    inline static uint8_t small_sqrt_table[256];\n\
    \n    static void init_table() {\n        if (table_initialized) return;\n   \
    \     small_table[0][0] = 0; small_table[0][1] = 0;\n        small_table[1][0]\
    \ = 0; small_table[1][1] = 1;\n        for (int level = 1; level <= 3; ++level)\
    \ {\n            int half = 1 << (1 << (level - 1));\n            int full = 1\
    \ << (1 << level);\n            for (int i = 0; i < full; ++i) {\n           \
    \     for (int j = 0; j < full; ++j) {\n                    if (i < half && j\
    \ < half) continue;\n                    int x0 = i & (half - 1);\n          \
    \          int x1 = i >> (1 << (level - 1));\n                    int y0 = j &\
    \ (half - 1);\n                    int y1 = j >> (1 << (level - 1));\n       \
    \             int p = small_table[x0][y0];\n                    int m = small_table[x0\
    \ ^ x1][y0 ^ y1];\n                    int b = small_table[small_table[x1][y1]][half\
    \ >> 1];\n                    small_table[i][j] = p ^ b ^ ((p ^ m) << (1 << (level\
    \ - 1)));\n                }\n            }\n        }\n\n        for (int i =\
    \ 0; i < 256; ++i) {\n            small_sqrt_table[small_table[i][i]] = i;\n \
    \       }\n\n        table_initialized = true;\n    }\n\n    static uint64_t build_up(const\
    \ uint64_t upper, const uint64_t lower, int level) {\n        return upper <<\
    \ (1 << (level - 1)) ^ lower;\n    }\n\n    /// @brief x * y \u3092\u6C42\u3081\
    \u308B\u305F\u3081\u306E\u30D8\u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x\
    \ \n    /// @param y \n    /// @param level \n    /// @return \n    static uint64_t\
    \ calculate_mul(const uint64_t x, const uint64_t y, int level) {\n        if (level\
    \ <= 3) { \n            if (!table_initialized) init_table();\n            return\
    \ small_table[x][y];\n        }\n\n        const auto &[x1, x0] = separate(x,\
    \ level);\n        const auto &[y1, y0] = separate(y, level);\n\n        uint64_t\
    \ p = calculate_mul(x0, y0, level - 1);\n        uint64_t e = 1ULL << (1 << (level\
    \ - 1));\n\n        uint64_t m = calculate_mul(x0 ^ x1, y0 ^ y1, level - 1);\n\
    \        uint64_t a = p ^ m * e;\n        uint64_t b = calculate_mul(calculate_mul(x1,\
    \ y1, level - 1), e >> 1, level - 1);\n\n        uint64_t res = (p * e) ^ a ^\
    \ b;\n\n        return res;\n    }\n\n    /// @brief x \u306E\u81EA\u4E57\u3092\
    \u6C42\u3081\u308B\u30D8\u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n  \
    \  /// @param level \n    /// @return \n    static uint64_t calculate_square(const\
    \ uint64_t x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_table[x][x];\n        }\n\n        const\
    \ auto &[x1, x0] = separate(x, level);\n\n        uint64_t p = calculate_square(x0,\
    \ level - 1);\n        uint64_t b = calculate_square(x1, level - 1);\n       \
    \ \n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t mul_part\
    \ = calculate_mul(b, e >> 1, level - 1);\n\n        return p ^ (b << (1 << (level\
    \ - 1))) ^ mul_part;\n    }\n\n    static uint64_t calculate_sqrt(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_sqrt_table[x];\n        }\n\n      \
    \  const auto &[x1, x0] = separate(x, level);\n\n        uint64_t y1 = calculate_sqrt(x1,\
    \ level - 1);\n\n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t\
    \ prod = calculate_mul(x1, e >> 1, level - 1);\n        uint64_t y0 = calculate_sqrt(prod\
    \ ^ x0, level - 1);\n\n        return (y1 << (1 << (level - 1))) ^ y0;\n    }\n\
    \n    /// @brief x < 2^(2^k) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 k \u3092\u6C42\u3081\u308B.\n    /// @param x \n    /// @note x >\
    \ 1 \u306E\u3068\u304D\u306F, k = floor_log2(floor_log2(x)) + 1 \u304C\u6210\u308A\
    \u7ACB\u3064.\n    static int calculate_level(const uint64_t &x) {\n        if\
    \ (x == 0 || x == 1) { return 0; }\n\n        return floor_log2(floor_log2(x))\
    \ + 1;\n    }\n\n    /// @brief \u975E\u8CA0\u6574\u6570 x \u3092 x = x1 e_{level}\
    \ + x0, 0 <= x_0 < e_{level}, 0 <= x_1 < e_{level} \u3068\u306A\u308B\u3088\u3046\
    \u306B\u5206\u5272\u3059\u308B. \u305F\u3060\u3057, e_k := 2^(2^k).\n    /// @param\
    \ x \u975E\u8CA0\u6574\u6570\n    /// @param level e_k \u306B\u304A\u3051\u308B\
    \ k \u306E\u5024\n    /// @return {x1, x0} (\u9806\u756A\u6CE8\u610F)\n    static\
    \ pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {\n        uint64_t\
    \ upper = x >> (1 << (level - 1));\n        uint64_t lower = x ^ (upper << (1\
    \ << level - 1));\n\n        return { upper, lower };\n    }\n};\n\ntemplate<typename\
    \ T>\nNimber pow(Nimber x, T n) {\n    if constexpr (std::is_signed_v<T>) {\n\
    \        if (n < 0) return pow(x.inverse(), -n);\n    }\n\n    Nimber res(1);\n\
    \    while (n > 0) {\n        if (n & 1) res *= x;\n        x = x.square();\n\
    \        n >>= 1;\n    }\n    return res;\n}\n\ninline Nimber Nimber::inverse()\
    \ const {\n    int l = calculate_level(x);\n    return pow(*this, l >= 6 ? -2ULL\
    \ : (1ULL << (1 << l)) - 2);\n}\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\nclass Nimber {\n\
    \    public:\n    Nimber(): x(0) {}\n    Nimber(uint64_t x): x(x) {}\n\n    Nimber\
    \ operator-() const { return Nimber(x); }\n\n    Nimber& operator+=(const Nimber\
    \ &b) {\n        x ^= b.x;\n        return *this;\n    }\n\n    friend Nimber\
    \ operator+(const Nimber &x, const Nimber &y) { return Nimber(x) += y; }\n\n \
    \   Nimber& operator-=(const Nimber &b) {\n        *this += b;\n        return\
    \ *this;\n    }\n\n    friend Nimber operator-(const Nimber &x, const Nimber &y)\
    \ { return Nimber(x) -= y; }\n\n    // \u4E57\u6CD5\n    Nimber& operator*=(const\
    \ Nimber &b) {\n        if ((x | b.x) < 256) {\n            if (!table_initialized)\
    \ init_table();\n            x = small_table[x][b.x];\n            return *this;\n\
    \        }\n        int level = max(calculate_level(x), calculate_level(b.x));\n\
    \        x = calculate_mul(x, b.x, level);\n        return *this;\n    }\n\n \
    \   friend Nimber operator*(const Nimber &x, const Nimber &y) { return Nimber(x)\
    \ *= y; }\n\n    friend bool operator==(const Nimber &a, const Nimber &b) { return\
    \ a.x == b.x; }\n    friend bool operator!=(const Nimber &a, const Nimber &b)\
    \ { return a.x != b.x; }\n    friend bool operator<(const Nimber &a, const Nimber\
    \ &b) { return a.x < b.x; }\n\n    Nimber square() const {\n        if (x < 256)\
    \ {\n            if (!table_initialized) init_table();\n            return small_table[x][x];\n\
    \        }\n        int level = calculate_level(x);\n        return Nimber(calculate_square(x,\
    \ level));\n    }\n\n    // \u5165\u529B\n    friend istream &operator>>(istream\
    \ &is, Nimber &a) {\n        is >> a.x;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const Nimber &a) { return\
    \ os << a.x; }\n\n    Nimber inverse() const;\n\n    Nimber sqrt() {\n       \
    \ if (x < 256) {\n            if (!table_initialized) init_table();\n        \
    \    return Nimber(small_sqrt_table[x]);\n        }\n\n        int level = calculate_level(x);\n\
    \        return Nimber(calculate_sqrt(x, level));\n    }\n\n    bool is_zero()\
    \ const { return x == 0; }\n\n    private:\n    uint64_t x;\n\n    inline static\
    \ uint8_t small_table[256][256];\n    inline static bool table_initialized = false;\n\
    \    inline static uint8_t small_sqrt_table[256];\n\n    static void init_table()\
    \ {\n        if (table_initialized) return;\n        small_table[0][0] = 0; small_table[0][1]\
    \ = 0;\n        small_table[1][0] = 0; small_table[1][1] = 1;\n        for (int\
    \ level = 1; level <= 3; ++level) {\n            int half = 1 << (1 << (level\
    \ - 1));\n            int full = 1 << (1 << level);\n            for (int i =\
    \ 0; i < full; ++i) {\n                for (int j = 0; j < full; ++j) {\n    \
    \                if (i < half && j < half) continue;\n                    int\
    \ x0 = i & (half - 1);\n                    int x1 = i >> (1 << (level - 1));\n\
    \                    int y0 = j & (half - 1);\n                    int y1 = j\
    \ >> (1 << (level - 1));\n                    int p = small_table[x0][y0];\n \
    \                   int m = small_table[x0 ^ x1][y0 ^ y1];\n                 \
    \   int b = small_table[small_table[x1][y1]][half >> 1];\n                   \
    \ small_table[i][j] = p ^ b ^ ((p ^ m) << (1 << (level - 1)));\n             \
    \   }\n            }\n        }\n\n        for (int i = 0; i < 256; ++i) {\n \
    \           small_sqrt_table[small_table[i][i]] = i;\n        }\n\n        table_initialized\
    \ = true;\n    }\n\n    static uint64_t build_up(const uint64_t upper, const uint64_t\
    \ lower, int level) {\n        return upper << (1 << (level - 1)) ^ lower;\n \
    \   }\n\n    /// @brief x * y \u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u30D8\
    \u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param y \n    ///\
    \ @param level \n    /// @return \n    static uint64_t calculate_mul(const uint64_t\
    \ x, const uint64_t y, int level) {\n        if (level <= 3) { \n            if\
    \ (!table_initialized) init_table();\n            return small_table[x][y];\n\
    \        }\n\n        const auto &[x1, x0] = separate(x, level);\n        const\
    \ auto &[y1, y0] = separate(y, level);\n\n        uint64_t p = calculate_mul(x0,\
    \ y0, level - 1);\n        uint64_t e = 1ULL << (1 << (level - 1));\n\n      \
    \  uint64_t m = calculate_mul(x0 ^ x1, y0 ^ y1, level - 1);\n        uint64_t\
    \ a = p ^ m * e;\n        uint64_t b = calculate_mul(calculate_mul(x1, y1, level\
    \ - 1), e >> 1, level - 1);\n\n        uint64_t res = (p * e) ^ a ^ b;\n\n   \
    \     return res;\n    }\n\n    /// @brief x \u306E\u81EA\u4E57\u3092\u6C42\u3081\
    \u308B\u30D8\u30EB\u30D1\u30FC\u95A2\u6570\n    /// @param x \n    /// @param\
    \ level \n    /// @return \n    static uint64_t calculate_square(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_table[x][x];\n        }\n\n        const\
    \ auto &[x1, x0] = separate(x, level);\n\n        uint64_t p = calculate_square(x0,\
    \ level - 1);\n        uint64_t b = calculate_square(x1, level - 1);\n       \
    \ \n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t mul_part\
    \ = calculate_mul(b, e >> 1, level - 1);\n\n        return p ^ (b << (1 << (level\
    \ - 1))) ^ mul_part;\n    }\n\n    static uint64_t calculate_sqrt(const uint64_t\
    \ x, int level) {\n        if (level <= 3) {\n            if (!table_initialized)\
    \ init_table();\n            return small_sqrt_table[x];\n        }\n\n      \
    \  const auto &[x1, x0] = separate(x, level);\n\n        uint64_t y1 = calculate_sqrt(x1,\
    \ level - 1);\n\n        uint64_t e = 1ULL << (1 << (level - 1));\n        uint64_t\
    \ prod = calculate_mul(x1, e >> 1, level - 1);\n        uint64_t y0 = calculate_sqrt(prod\
    \ ^ x0, level - 1);\n\n        return (y1 << (1 << (level - 1))) ^ y0;\n    }\n\
    \n    /// @brief x < 2^(2^k) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\
    \u6574\u6570 k \u3092\u6C42\u3081\u308B.\n    /// @param x \n    /// @note x >\
    \ 1 \u306E\u3068\u304D\u306F, k = floor_log2(floor_log2(x)) + 1 \u304C\u6210\u308A\
    \u7ACB\u3064.\n    static int calculate_level(const uint64_t &x) {\n        if\
    \ (x == 0 || x == 1) { return 0; }\n\n        return floor_log2(floor_log2(x))\
    \ + 1;\n    }\n\n    /// @brief \u975E\u8CA0\u6574\u6570 x \u3092 x = x1 e_{level}\
    \ + x0, 0 <= x_0 < e_{level}, 0 <= x_1 < e_{level} \u3068\u306A\u308B\u3088\u3046\
    \u306B\u5206\u5272\u3059\u308B. \u305F\u3060\u3057, e_k := 2^(2^k).\n    /// @param\
    \ x \u975E\u8CA0\u6574\u6570\n    /// @param level e_k \u306B\u304A\u3051\u308B\
    \ k \u306E\u5024\n    /// @return {x1, x0} (\u9806\u756A\u6CE8\u610F)\n    static\
    \ pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {\n        uint64_t\
    \ upper = x >> (1 << (level - 1));\n        uint64_t lower = x ^ (upper << (1\
    \ << level - 1));\n\n        return { upper, lower };\n    }\n};\n\ntemplate<typename\
    \ T>\nNimber pow(Nimber x, T n) {\n    if constexpr (std::is_signed_v<T>) {\n\
    \        if (n < 0) return pow(x.inverse(), -n);\n    }\n\n    Nimber res(1);\n\
    \    while (n > 0) {\n        if (n & 1) res *= x;\n        x = x.square();\n\
    \        n >>= 1;\n    }\n    return res;\n}\n\ninline Nimber Nimber::inverse()\
    \ const {\n    int l = calculate_level(x);\n    return pow(*this, l >= 6 ? -2ULL\
    \ : (1ULL << (1 << l)) - 2);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Algebra/Nimber.hpp
  requiredBy: []
  timestamp: '2026-02-28 23:52:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Nim_Product.test.cpp
documentation_of: Algebra/Nimber.hpp
layout: document
title: Nimber
---

## Outline

組み合わせゲーム理論において用いられる Nim から導入された Nimber の計算を行う.

## Theory

非負整数 $n$ に対して,

$$F_n := \{0, 1, \dots, 2^n - 1 \}$$

とする.

### 加法

$F_n$ 上の演算 $\oplus: F_n \times F_n \to F_n$ を

$$x \oplus y := \mathrm{mex} \left(\{ a \oplus y \mid 0 \leq a < x \} \cup \{ x \oplus b \mid 0 \leq b < y \} \right)$$

によって帰納的に定める. ただし, $S \subsetneq \mathbb{N}$ に対して, $S$ の最小除外数 $\mathrm{mex}~S$ を

$$\mathrm{mex}~S := \min (\mathbb{N} \setminus S)$$

で定義する.

すると, $\oplus$ は Bitwise-XOR と一致する.

このことから, 以下が従う.

* $\oplus$ は $F_n$ において可換群になる. 特に, 以下が成り立つ.
  * $x < 2^m < 2^n$ に対して, $x \oplus 2^m = x + 2^m$.
  * 単位元は $0$ である.
  * $x \in F_n$ の逆元は $x$ 自身である.

### 乗法

$F_{2^n}$ 上の演算 $\otimes: F_{2^n} \times F_{2^n} \to F_{2^n}$ を

$$ x \otimes y := \mathrm{mex} \left(\{(a \otimes y) \oplus (x \otimes b) \oplus (a \otimes b) \mid 0 \leq a < x, 0 \leq b < y\} \right)$$

によって帰納的に定める.

このとき, $(F_{2^n}, \oplus, \otimes)$ は $1$ を乗法単位元とする可換体になる.

#### 計算

可換体 $(F_{2^n}, \oplus, \otimes)$ に対して, 以下が成り立つ. ただし, 非負整数 $k~(< n) $ に対して,

$$e_k := 2^{2^k}, \quad e'_k := 2^{2^k - 1} \left(= e_k / 2 \right)$$

とする.

* $x \in F$ に対して, $x < e_k$ ならば, $x \otimes e_k = x \times e_k$ である.
* $e_k \otimes e_k = \frac{3}{2} e_k = e_k + e'_k = e_k \oplus e'_k $.

これらの性質により, $x, y \in F_{2^n}$ に対して, $x \oplus y$ の計算を次のようにして, $F_{2^{n-1}}$ 上の計算に帰着させることができる.

まず, $x,y \in F_{2^n}$ より, $x, y$ はそれぞれ $x_0, x_1, y_0, y_1 \in F_{2^{n-1}}$ を用いて,

$$x = x_1 e_{k-1} + x_0, \quad y = y_1 e_{k-1} + y_0$$

と表せる.

すると,

$$\begin{align*}
    x \otimes y
    &= (x_1 e_{k-1} + x_0) \otimes (y_1 e_{k-1} + y_0) \\
    &= (x_1 e_{k-1} \oplus x_0) \otimes (y_1 e_{k-1} \oplus y_0) \\
    &= (x_1 \otimes e_{k-1} \oplus x_0) \otimes (y_1 \otimes e_{k-1} \oplus y_0) \\
    &= \left((x_1 \otimes y_1) \otimes (e_{k-1} \otimes e_{k-1}) \right) \oplus \left((x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_0 \otimes y_0) \\
    &= \left((x_1 \otimes y_1) \otimes (e_{k-1} \oplus e'_{k-1}) \right) \oplus \left((x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_0 \otimes y_0) \\
    &= \left((x_1 \otimes y_1 \oplus x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
    &= \left(((x_1 \otimes y_1 \oplus x_0 \otimes y_1 \oplus x_1 \otimes y_0 \oplus x_0 \otimes y_0) \oplus x_0 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
    &= \left(((x_1 \oplus x_0) \otimes (y_1 \oplus y_0) \oplus (x_0 \otimes y_0)) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0)\\
    &= \left(((x_1 \oplus x_0) \otimes (y_1 \oplus y_0) \oplus (x_0 \otimes y_0)) \times e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
\end{align*}$$

となり,

$$(x_1 \oplus x_0) \otimes (y_1 \oplus y_0), \quad x_0 \otimes y_0, \quad x_1 \otimes y_1 \otimes e'_{k-1}$$

の $4$ つの "1 レベル下" の積に帰着される.

### 逆元

$x \in F_{2^n}$ は $x \neq 0$ であるとする. Nimber 積の意味での $x$ の $m$ 乗を $\operatorname{power}(x, m)$ と書くことにする.

体における乗法群 $F_{2^n}^\times$ の位数は $(2^{2^n}-1)$ であるため, Lagrange の定理により, $\operatorname{power}(x, 2^{2^n}-1) = 1$ である.

よって, $x$ の Nimber 積の意味での逆元は $\operatorname{power}(x, 2^{2^n}-2)$ である.

### 平方根

まず, 平方根の定義ができることを証明する.

> (定理 1) 任意の $b \in F_{2^n}$ に対して, $a \otimes a = b$ となる $a \in F_{2^n}$ がただ一つ存在する.

(証明)

$x, y \in F_{2^n}$ に対して, $x \otimes x = y \otimes y$ とする. すると, $F_{2^n}$ は位数 $2$ の体であるため, Freshman's Dream により, $(x \oplus y) \otimes (x \oplus y) = 0$ が成り立つ.

$F_{2^n}$ は体であるため, $x \oplus y = 0$ である. つまり, $x = y$ である.

すると, $g: F_{2^n} \to F_{2^n}; x \mapsto x \otimes x$ は定義域と値域が同じ有限集合の $F_{2^n}$ である単射になるため, $g$ は全単射になる.

故に, 任意の $b \in F_{2^n}$ に対して, $g(a) = b$ となる $a \in F_{2^n}$ がただ一つ存在する.

$b \in F_{2^n}$ に対して, $a \otimes a = b$ となる $a \in F_{2^n}$ のことを, $b$ の平方根といい, $\sqrt{b}$ と書く.

#### 計算

$x \in F_{2^n}$ として, $n$ に関して帰納的に求めていく.

$n = 1$ の場合. つまり, $x = 0, 1$ の場合はそれぞれ $\sqrt{0} = 0, \sqrt{1} = 1$ である.

つまり, $x \in F_{2^n}$ とすると, $n \geq 2$ である.

$x = x_1 e_{n-1} + x_0, x_1, x_0 \in F_{2^{n-1}}$ として $x$ を分割することができる.

ここで,

$$ y_1 := \sqrt{x_1}, \quad y_0 := \sqrt{x_1 \otimes e'_{k-1} \oplus x_0}, \quad y := y_1 e_{k-1} + y_0 $$

とする. このとき, $x\_1, x\_1 \otimes e'\_{k-1} \oplus x\_0 \in F\_{2^{n-1}}$ になる.

すると,

$$
\begin{align*}
y \otimes y
&= (y_1 e_{k-1} + y_0) \otimes (y_1 e_{k-1} + y_0) \\
&= (y_1 \otimes e_{k-1} \oplus y_0) \otimes (y_1 \otimes e_{k-1} \oplus y_0) \\
&= (y_1 \otimes y_1) \otimes (e_{k-1} \otimes e_{k-1}) \oplus (y_0 \oplus y_0) \\
&= x_1 \otimes (e_{k-1} \oplus e'_k) \oplus (x_1 \otimes e'_{k-1} \oplus x_0) \\
&= x_1 \otimes e_{k-1} \oplus x_0 \\
&= x
\end{align*}
$$

となる. よって, $y = \sqrt{x}$ である.

## Reference

* https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit
* https://natsugiri.hatenablog.com/entry/2020/03/29/073605

## History

|日付|内容|
|:---:|:---:|
|2026/02/21| sqrt の実装 |
|2026/02/15| Nimber クラスの実装 |
