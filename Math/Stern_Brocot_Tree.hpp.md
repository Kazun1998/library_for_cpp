---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Rational_Approximation.test.cpp
    title: verify/yosupo_library_checker/number_theory/Rational_Approximation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Stern-Brocot_Tree.test.cpp
    title: verify/yosupo_library_checker/number_theory/Stern-Brocot_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "SB \u6728\u306B\u304A\u3051\u308B 1/1 \u304B\u3089 a/b \u3078\
      \u306E\u30D1\u30B9\u3092\u6C42\u3081\u308B."
    links: []
  bundledCode: "#line 2 \"Math/Stern_Brocot_Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n#line 59\
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u6F14\
    \u7B97\u5B50\ntemplate<typename T>\nT add(const T &x, const T &y) { return x +\
    \ y; }\n\ntemplate<typename T>\nT sub(const T &x, const T &y) { return x - y;\
    \ }\n\ntemplate<typename T>\nT mul(const T &x, const T &y) { return x * y; }\n\
    \ntemplate<typename T>\nT neg(const T &x) { return -x; }\n\ntemplate<typename\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n#line 65 \"template/template.hpp\"\
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
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 68 \"template/template.hpp\"\n\n// bitop\n\
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
    \ bit_length(x)); }\n#line 4 \"Math/Stern_Brocot_Tree.hpp\"\n\nstruct Stern_Brocot_Tree\
    \ {\n    using Fraction = pair<ll, ll>;\n    template<typename Direction>\n  \
    \  using Path = vector<pair<Direction, ll>>;\n\n    /// @brief SB \u6728\u306B\
    \u304A\u3051\u308B 1/1 \u304B\u3089 a/b \u3078\u306E\u30D1\u30B9\u3092\u6C42\u3081\
    \u308B.\n    /// @tparam Direction \u5411\u304D\u3092\u8868\u3059\u5024\u3092\u683C\
    \u7D0D\u3059\u308B\u30AF\u30E9\u30B9\n    /// @param a \u5206\u5B50\n    /// @param\
    \ b \u5206\u6BCD\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D) \u3092\
    \u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @return pair<Direction, ll> \u578B\u306E (d,\
    \ k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F d \u306E\u5411\u304D\
    \u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\u3092\u8868\u3059.\n\
    \    template<typename Direction>\n    static Path<Direction> encode(ll a, ll\
    \ b, Direction left, Direction right) {\n        Path<Direction> path;\n     \
    \   ll q, r;\n        tie (q, r) = divmod(a, b);\n        if (q > 0) { path.emplace_back(right,\
    \ q); }\n\n        a = b;\n        b = r;\n        bool parity = true;\n     \
    \   while (b > 0) {\n            tie (q, r) = divmod(a, b);\n            Direction\
    \ direction = parity ? left : right;\n            path.emplace_back(direction,\
    \ q);\n\n            tie (a, b) = make_tuple(b, r);\n            parity = !parity;\n\
    \        }\n\n        if (path.back().second > 1) {\n            path.back().second--;\n\
    \        } else {\n            path.pop_back();\n        }\n\n        return path;\n\
    \    }\n\n    /// @brief SB \u6728\u306B\u304A\u3051\u308B 1/1 \u304B\u3089 code\
    \ \u306B\u6CBF\u3063\u3066, \u5230\u9054\u306E\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u6709\u7406\u6570\u306E\u96C6\u5408\u306F\u6709\u7406\u6570\u958B\u533A\u9593\
    \u306B\u306A\u308B. \u3053\u306E\u6709\u7406\u6570\u958B\u533A\u9593\u306E\u4E0B\
    \u9650\u3068\u4E0A\u9650\u3092\u6C42\u3081\u308B.\n    /// @param code pair<Direction,\
    \ ll> \u578B\u306E (d, k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F\
    \ d \u306E\u5411\u304D\u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\
    \u3092\u8868\u3059.\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\
    \u304D) \u3092\u8868\u3059\u5024\n    /// @return `pair<Fraction, Fraction>` {{\u4E0B\
    \u9650\u5206\u5B50, \u4E0B\u9650\u5206\u6BCD}, {\u4E0A\u9650\u5206\u5B50, \u4E0A\
    \u9650\u5206\u6BCD}}\n    template<typename Direction>\n    static pair<Fraction,\
    \ Fraction> decode_interval(Path<Direction> &code, Direction left, Direction right)\
    \ {\n        ll p = 0, q = 1, r = 1, s = 0;\n        for (auto &&[direction, k]:\
    \ code) {\n            if (direction == left) {\n                r += k * p;\n\
    \                s += k * q;\n            } else {\n                p += k * r;\n\
    \                q += k * s;\n            }\n        }\n\n        return {{p,\
    \ q}, {r, s}}; \n    }\n\n    /// @brief SB \u6728\u306B\u304A\u3051\u308B 1/1\
    \ \u304B\u3089\u79FB\u52D5\u3057\u305F\u969B\u306E\u6709\u7406\u6570\u3092\u6C42\
    \u3081\u308B.\n    /// @tparam Direction code \u306B\u304A\u3051\u308B\u5411\u304D\
    \u3092\u683C\u7D0D\u3059\u308B\u30AF\u30E9\u30B9\n    /// @param code pair<Direction,\
    \ ll> \u578B\u306E (d, k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F\
    \ d \u306E\u5411\u304D\u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\
    \u3092\u8868\u3059.\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\
    \u304D) \u3092\u8868\u3059\u5024\n    template<typename Direction>\n    static\
    \ Fraction decode(Path<Direction> &code, Direction left, Direction right) {\n\
    \        auto &&[x, y] = decode_interval(code, left, right);\n        auto &&[p,\
    \ q] = x;\n        auto &&[r, s] = y;\n        return { p + r, q + s };\n    }\n\
    \n    /// @brief SB \u6728\u306B\u304A\u3051\u308B a/b \u3068 c/d \u306E\u6700\
    \u5C0F\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\n    /// @param a \u6709\
    \u7406\u6570 1 \u306E\u5206\u5B50\n    /// @param b \u6709\u7406\u6570 1 \u306E\
    \u5206\u6BCD\n    /// @param c \u6709\u7406\u6570 2 \u306E\u5206\u5B50\n    ///\
    \ @param d \u6709\u7406\u6570 2 \u306E\u5206\u6BCD\n    /// @return {\u5206\u5B50\
    , \u5206\u6BCD} \u306E\u5F62\u306E pair<ll, ll>\n    static Fraction lowest_common_ancestor(ll\
    \ a, ll b, ll c, ll d) {\n        if ((a == 1 && b == 1) || (c == 1 && d == 1))\
    \ {\n            return {1, 1};\n        }\n\n        Path<bool> code_1 = encode(a,\
    \ b, true, false);\n        Path<bool> code_2 = encode(c, d, true, false);\n\n\
    \        if (code_1.front().first != code_2.front().first) { return {1, 1}; }\n\
    \n        Path<bool> lca_code;\n        for (int i = 0; i < min(code_1.size(),\
    \ code_2.size()); i++) {\n            bool t; ll k, l;\n            tie (t, k)\
    \ = code_1[i];\n            tie (ignore, l) = code_2[i];\n\n            lca_code.emplace_back(t,\
    \ min(k, l));\n            if (k != l) { break; }\n        }\n\n        return\
    \ decode(lca_code, true, false);\n    }\n\n    /// @brief SB \u6728\u306B\u304A\
    \u3051\u308B\u6709\u7406\u6570 a/b \u306E\u6DF1\u3055\n    /// @param a \u5206\
    \u5B50\n    /// @param b \u5206\u6BCD\n    static ll depth(ll a, ll b) {\n   \
    \     ll res = 0;\n        for (auto &&[ignore, k]: encode(a, b, true, false))\
    \ { res += k; }\n\n        return res;\n    }\n\n    /// @brief SB \u6728\u306B\
    \u304A\u3051\u308B\u6709\u7406\u6570 a/b \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C\
    \ k \u3067\u3042\u308B\u6709\u7406\u6570\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ a \u57FA\u6E96\u3068\u306A\u308B\u6709\u7406\u6570\u306E\u5206\u5B50\n    ///\
    \ @param b \u57FA\u6E96\u3068\u306A\u308B\u6709\u7406\u6570\u306E\u5206\u6BCD\n\
    \    /// @param k \u6C42\u3081\u308B\u6709\u7406\u6570\u306E\u6DF1\u3055\n   \
    \ /// @param default_value \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\
    \u308A\u5024\n    /// @return {\u5206\u5B50, \u5206\u6BCD} \u306E\u5F62\u306E\
    \ pair<ll, ll>\n    static Fraction ancestor(ll a, ll b, ll k, Fraction default_value\
    \ = {-1, -1}) {\n        Path<bool> code;\n        for (auto &&[direction, l]:\
    \ encode(a, b, true, false)) {\n            l = min(k, l);\n            code.emplace_back(direction,\
    \ l);\n            k -= l;\n            if (k == 0) { return decode(code, true,\
    \ false); }\n        }\n\n        return default_value;\n    }\n\n    /// @brief\
    \ SB \u6728\u306B\u304A\u3051\u308B\u6709\u7406\u6570 a/b \u306E\u5B50\u5B6B\u306E\
    \u96C6\u5408\u306F\u3042\u308B\u6709\u7406\u6570\u958B\u533A\u9593\u306B\u306A\
    \u308B. \u3053\u306E\u6709\u7406\u6570\u958B\u533A\u9593\u306E\u4E0B\u9650\u3068\
    \u4E0A\u9650\u3092\u6C42\u3081\u308B.\n    /// @param a \u5206\u5B50\n    ///\
    \ @param b \u5206\u6BCD\n    /// @return pair<pair<ll, ll>, pair<ll, ll>> \u306E\
    \u5F62\u306E\u30DA\u30A2. \u305D\u308C\u305E\u308C {{\u4E0B\u9650\u5206\u5B50\
    , \u4E0B\u9650\u5206\u6BCD}, {\u4E0A\u9650\u5206\u5B50, \u4E0A\u9650\u5206\u6BCD\
    }}\n    static pair<Fraction, Fraction> range(ll a, ll b) {\n        auto code\
    \ = encode(a, b, true, false);\n        return decode_interval(code, true, false);\n\
    \    }\n\n    /// @brief \u5358\u8ABF\u5897\u52A0\u306A check \u306B\u304A\u3044\
    \u3066, cond(x) = T \u3068\u306A\u308B\u6700\u5C0F\u306E x \u3092\u631F\u3080\u5206\
    \u5B50\u3068\u5206\u6BCD\u304C N \u4EE5\u4E0B\u306E\u6709\u7406\u6570\u3092\u6C42\
    \u3081\u308B.\n    /// @param N \u5206\u5B50\u3068\u5206\u6BCD\u306E\u4E0A\u9650\
    \n    /// @param cond 2 \u5909\u6570\u95A2\u6570\u3067, cond(a, b) \u306F cond(a\
    \ / b) \u3092\u610F\u5473\u3059\u308B.\n    /// @return \n    static pair<Fraction,\
    \ Fraction> binary_search_range_increase(ll N, function<bool(ll, ll)> cond) {\n\
    \        // x + d * y <= N ?\n        auto is_valid = [&N](const ll x, const ll\
    \ y, const ll d) -> bool {\n            if (y == 0) { return x <= N; }\n\n   \
    \         return d <= (N - x) / y;\n        };\n\n        auto right_search =\
    \ [&N, &cond, &is_valid](const ll p, const ll q, const ll r, const ll s) -> ll\
    \ {\n            ll lower = 0, upper = (N - p) / r + 1;\n            while (upper\
    \ - lower > 1) {\n                ll d = (lower + upper) / 2;\n              \
    \  if (is_valid(p, r, d) && is_valid(q, s, d) && !cond(p + d * r, q + d * s))\
    \ {\n                    lower = d;\n                } else {\n              \
    \      upper = d;\n                }\n            }\n\n            return lower;\n\
    \        };\n\n        auto left_search = [&N, &cond, &is_valid](const ll p, const\
    \ ll q, const ll r, const ll s) -> ll {\n            ll lower = 0, upper = (N\
    \ - p) / r + 1;\n            while (upper - lower > 1) {\n                ll d\
    \ = (lower + upper) / 2;\n                if (is_valid(r, p, d) && is_valid(s,\
    \ q, d) && cond(r + d * p, s + d * q)) {\n                    lower = d;\n   \
    \             } else {\n                    upper = d;\n                }\n  \
    \          }\n\n            return lower;\n        };\n\n        ll p = 0, q =\
    \ 1, r = 1, s = 0;\n        while (p + r <= N && q + s <= N) {\n            ll\
    \ d;\n            d = right_search(p, q, r, s);\n            p += d * r; q +=\
    \ d * s;\n\n            d = left_search(p, q, r, s);\n            r += d * p;\
    \ s += d * q;\n        }\n\n        return {{p, q}, {r, s}};\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nstruct Stern_Brocot_Tree\
    \ {\n    using Fraction = pair<ll, ll>;\n    template<typename Direction>\n  \
    \  using Path = vector<pair<Direction, ll>>;\n\n    /// @brief SB \u6728\u306B\
    \u304A\u3051\u308B 1/1 \u304B\u3089 a/b \u3078\u306E\u30D1\u30B9\u3092\u6C42\u3081\
    \u308B.\n    /// @tparam Direction \u5411\u304D\u3092\u8868\u3059\u5024\u3092\u683C\
    \u7D0D\u3059\u308B\u30AF\u30E9\u30B9\n    /// @param a \u5206\u5B50\n    /// @param\
    \ b \u5206\u6BCD\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D) \u3092\
    \u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @return pair<Direction, ll> \u578B\u306E (d,\
    \ k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F d \u306E\u5411\u304D\
    \u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\u3092\u8868\u3059.\n\
    \    template<typename Direction>\n    static Path<Direction> encode(ll a, ll\
    \ b, Direction left, Direction right) {\n        Path<Direction> path;\n     \
    \   ll q, r;\n        tie (q, r) = divmod(a, b);\n        if (q > 0) { path.emplace_back(right,\
    \ q); }\n\n        a = b;\n        b = r;\n        bool parity = true;\n     \
    \   while (b > 0) {\n            tie (q, r) = divmod(a, b);\n            Direction\
    \ direction = parity ? left : right;\n            path.emplace_back(direction,\
    \ q);\n\n            tie (a, b) = make_tuple(b, r);\n            parity = !parity;\n\
    \        }\n\n        if (path.back().second > 1) {\n            path.back().second--;\n\
    \        } else {\n            path.pop_back();\n        }\n\n        return path;\n\
    \    }\n\n    /// @brief SB \u6728\u306B\u304A\u3051\u308B 1/1 \u304B\u3089 code\
    \ \u306B\u6CBF\u3063\u3066, \u5230\u9054\u306E\u53EF\u80FD\u6027\u304C\u3042\u308B\
    \u6709\u7406\u6570\u306E\u96C6\u5408\u306F\u6709\u7406\u6570\u958B\u533A\u9593\
    \u306B\u306A\u308B. \u3053\u306E\u6709\u7406\u6570\u958B\u533A\u9593\u306E\u4E0B\
    \u9650\u3068\u4E0A\u9650\u3092\u6C42\u3081\u308B.\n    /// @param code pair<Direction,\
    \ ll> \u578B\u306E (d, k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F\
    \ d \u306E\u5411\u304D\u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\
    \u3092\u8868\u3059.\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\
    \u304D) \u3092\u8868\u3059\u5024\n    /// @return `pair<Fraction, Fraction>` {{\u4E0B\
    \u9650\u5206\u5B50, \u4E0B\u9650\u5206\u6BCD}, {\u4E0A\u9650\u5206\u5B50, \u4E0A\
    \u9650\u5206\u6BCD}}\n    template<typename Direction>\n    static pair<Fraction,\
    \ Fraction> decode_interval(Path<Direction> &code, Direction left, Direction right)\
    \ {\n        ll p = 0, q = 1, r = 1, s = 0;\n        for (auto &&[direction, k]:\
    \ code) {\n            if (direction == left) {\n                r += k * p;\n\
    \                s += k * q;\n            } else {\n                p += k * r;\n\
    \                q += k * s;\n            }\n        }\n\n        return {{p,\
    \ q}, {r, s}}; \n    }\n\n    /// @brief SB \u6728\u306B\u304A\u3051\u308B 1/1\
    \ \u304B\u3089\u79FB\u52D5\u3057\u305F\u969B\u306E\u6709\u7406\u6570\u3092\u6C42\
    \u3081\u308B.\n    /// @tparam Direction code \u306B\u304A\u3051\u308B\u5411\u304D\
    \u3092\u683C\u7D0D\u3059\u308B\u30AF\u30E9\u30B9\n    /// @param code pair<Direction,\
    \ ll> \u578B\u306E (d, k) \u304B\u3089\u306A\u308B\u30EA\u30B9\u30C8. (d, k) \u306F\
    \ d \u306E\u5411\u304D\u3078 k \u56DE\u9023\u7D9A\u3067\u9032\u3080\u3053\u3068\
    \u3092\u8868\u3059.\n    /// @param left \u5DE6 (0/1 \u3078\u306E\u5411\u304D\
    ) \u3092\u8868\u3059\u5024\n    /// @param right \u53F3 (1/0 \u3078\u306E\u5411\
    \u304D) \u3092\u8868\u3059\u5024\n    template<typename Direction>\n    static\
    \ Fraction decode(Path<Direction> &code, Direction left, Direction right) {\n\
    \        auto &&[x, y] = decode_interval(code, left, right);\n        auto &&[p,\
    \ q] = x;\n        auto &&[r, s] = y;\n        return { p + r, q + s };\n    }\n\
    \n    /// @brief SB \u6728\u306B\u304A\u3051\u308B a/b \u3068 c/d \u306E\u6700\
    \u5C0F\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\n    /// @param a \u6709\
    \u7406\u6570 1 \u306E\u5206\u5B50\n    /// @param b \u6709\u7406\u6570 1 \u306E\
    \u5206\u6BCD\n    /// @param c \u6709\u7406\u6570 2 \u306E\u5206\u5B50\n    ///\
    \ @param d \u6709\u7406\u6570 2 \u306E\u5206\u6BCD\n    /// @return {\u5206\u5B50\
    , \u5206\u6BCD} \u306E\u5F62\u306E pair<ll, ll>\n    static Fraction lowest_common_ancestor(ll\
    \ a, ll b, ll c, ll d) {\n        if ((a == 1 && b == 1) || (c == 1 && d == 1))\
    \ {\n            return {1, 1};\n        }\n\n        Path<bool> code_1 = encode(a,\
    \ b, true, false);\n        Path<bool> code_2 = encode(c, d, true, false);\n\n\
    \        if (code_1.front().first != code_2.front().first) { return {1, 1}; }\n\
    \n        Path<bool> lca_code;\n        for (int i = 0; i < min(code_1.size(),\
    \ code_2.size()); i++) {\n            bool t; ll k, l;\n            tie (t, k)\
    \ = code_1[i];\n            tie (ignore, l) = code_2[i];\n\n            lca_code.emplace_back(t,\
    \ min(k, l));\n            if (k != l) { break; }\n        }\n\n        return\
    \ decode(lca_code, true, false);\n    }\n\n    /// @brief SB \u6728\u306B\u304A\
    \u3051\u308B\u6709\u7406\u6570 a/b \u306E\u6DF1\u3055\n    /// @param a \u5206\
    \u5B50\n    /// @param b \u5206\u6BCD\n    static ll depth(ll a, ll b) {\n   \
    \     ll res = 0;\n        for (auto &&[ignore, k]: encode(a, b, true, false))\
    \ { res += k; }\n\n        return res;\n    }\n\n    /// @brief SB \u6728\u306B\
    \u304A\u3051\u308B\u6709\u7406\u6570 a/b \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C\
    \ k \u3067\u3042\u308B\u6709\u7406\u6570\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ a \u57FA\u6E96\u3068\u306A\u308B\u6709\u7406\u6570\u306E\u5206\u5B50\n    ///\
    \ @param b \u57FA\u6E96\u3068\u306A\u308B\u6709\u7406\u6570\u306E\u5206\u6BCD\n\
    \    /// @param k \u6C42\u3081\u308B\u6709\u7406\u6570\u306E\u6DF1\u3055\n   \
    \ /// @param default_value \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\
    \u308A\u5024\n    /// @return {\u5206\u5B50, \u5206\u6BCD} \u306E\u5F62\u306E\
    \ pair<ll, ll>\n    static Fraction ancestor(ll a, ll b, ll k, Fraction default_value\
    \ = {-1, -1}) {\n        Path<bool> code;\n        for (auto &&[direction, l]:\
    \ encode(a, b, true, false)) {\n            l = min(k, l);\n            code.emplace_back(direction,\
    \ l);\n            k -= l;\n            if (k == 0) { return decode(code, true,\
    \ false); }\n        }\n\n        return default_value;\n    }\n\n    /// @brief\
    \ SB \u6728\u306B\u304A\u3051\u308B\u6709\u7406\u6570 a/b \u306E\u5B50\u5B6B\u306E\
    \u96C6\u5408\u306F\u3042\u308B\u6709\u7406\u6570\u958B\u533A\u9593\u306B\u306A\
    \u308B. \u3053\u306E\u6709\u7406\u6570\u958B\u533A\u9593\u306E\u4E0B\u9650\u3068\
    \u4E0A\u9650\u3092\u6C42\u3081\u308B.\n    /// @param a \u5206\u5B50\n    ///\
    \ @param b \u5206\u6BCD\n    /// @return pair<pair<ll, ll>, pair<ll, ll>> \u306E\
    \u5F62\u306E\u30DA\u30A2. \u305D\u308C\u305E\u308C {{\u4E0B\u9650\u5206\u5B50\
    , \u4E0B\u9650\u5206\u6BCD}, {\u4E0A\u9650\u5206\u5B50, \u4E0A\u9650\u5206\u6BCD\
    }}\n    static pair<Fraction, Fraction> range(ll a, ll b) {\n        auto code\
    \ = encode(a, b, true, false);\n        return decode_interval(code, true, false);\n\
    \    }\n\n    /// @brief \u5358\u8ABF\u5897\u52A0\u306A check \u306B\u304A\u3044\
    \u3066, cond(x) = T \u3068\u306A\u308B\u6700\u5C0F\u306E x \u3092\u631F\u3080\u5206\
    \u5B50\u3068\u5206\u6BCD\u304C N \u4EE5\u4E0B\u306E\u6709\u7406\u6570\u3092\u6C42\
    \u3081\u308B.\n    /// @param N \u5206\u5B50\u3068\u5206\u6BCD\u306E\u4E0A\u9650\
    \n    /// @param cond 2 \u5909\u6570\u95A2\u6570\u3067, cond(a, b) \u306F cond(a\
    \ / b) \u3092\u610F\u5473\u3059\u308B.\n    /// @return \n    static pair<Fraction,\
    \ Fraction> binary_search_range_increase(ll N, function<bool(ll, ll)> cond) {\n\
    \        // x + d * y <= N ?\n        auto is_valid = [&N](const ll x, const ll\
    \ y, const ll d) -> bool {\n            if (y == 0) { return x <= N; }\n\n   \
    \         return d <= (N - x) / y;\n        };\n\n        auto right_search =\
    \ [&N, &cond, &is_valid](const ll p, const ll q, const ll r, const ll s) -> ll\
    \ {\n            ll lower = 0, upper = (N - p) / r + 1;\n            while (upper\
    \ - lower > 1) {\n                ll d = (lower + upper) / 2;\n              \
    \  if (is_valid(p, r, d) && is_valid(q, s, d) && !cond(p + d * r, q + d * s))\
    \ {\n                    lower = d;\n                } else {\n              \
    \      upper = d;\n                }\n            }\n\n            return lower;\n\
    \        };\n\n        auto left_search = [&N, &cond, &is_valid](const ll p, const\
    \ ll q, const ll r, const ll s) -> ll {\n            ll lower = 0, upper = (N\
    \ - p) / r + 1;\n            while (upper - lower > 1) {\n                ll d\
    \ = (lower + upper) / 2;\n                if (is_valid(r, p, d) && is_valid(s,\
    \ q, d) && cond(r + d * p, s + d * q)) {\n                    lower = d;\n   \
    \             } else {\n                    upper = d;\n                }\n  \
    \          }\n\n            return lower;\n        };\n\n        ll p = 0, q =\
    \ 1, r = 1, s = 0;\n        while (p + r <= N && q + s <= N) {\n            ll\
    \ d;\n            d = right_search(p, q, r, s);\n            p += d * r; q +=\
    \ d * s;\n\n            d = left_search(p, q, r, s);\n            r += d * p;\
    \ s += d * q;\n        }\n\n        return {{p, q}, {r, s}};\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  isVerificationFile: false
  path: Math/Stern_Brocot_Tree.hpp
  requiredBy: []
  timestamp: '2025-11-23 00:39:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Rational_Approximation.test.cpp
  - verify/yosupo_library_checker/number_theory/Stern-Brocot_Tree.test.cpp
documentation_of: Math/Stern_Brocot_Tree.hpp
layout: document
title: "Stern Brocot \u6728"
---

## Outline

Stern Brocot 木に関する計算を行うメソッドをまとめたクラス.

## Define

$\widehat{\mathbb{Q}_{+0}} := \\\{x \geq 0 \mid x \in \mathbb{Q} \\\} \cup \\\{ \infty \\\}$ とする. 次のようにして, 根付き木である Stern Brocot 木 $T = (V, E)$ を次のようにして形式的に定義する. なお, 形式的に $\frac{1}{0} := \infty$ とする.

$\widehat{\mathbb{Q}_{+0}}$ の開区間 $v := \left(\frac{a}{b}, \frac{c}{d} \right)$ に対して, $v$ のメジアン $\varphi(v)$ を

$$ \varphi(v) := \frac{a+c}{b+d} $$

で定義することにする.

* $T$ の各頂点は $\widehat{\mathbb{Q}_{+0}}$ の閉区間である.
* $T$ の根は $(0, \infty)$ である.
* 次のようにして, 頂点 $v = \left(\frac{a}{b}, \frac{c}{d} \right)$ の子を生成する.
  * $v$ の左の子は $\left(\frac{a}{b}, \varphi(v) \right)$, $v$ の右の子 $\left(\varphi(v), \frac{c}{d} \right)$ になる.

## Theory

Stern Brocot 木 $T$ について, 以下が成り立つ.

* **既約** 分数 $\frac{a}{b}, \frac{c}{d} \in \widehat{\mathbb{Q}_{+0}}$ に対して, 以下は同値になる.
  * $v := \left(\frac{a}{b}, \frac{c}{d} \right) \in V$.
  * $ad-bc=1$.
* 任意の正の有理数 $x \in \mathbb{Q}_+$ に対して, $\varphi(v) = x$ となる $v \in V$ がただ一つ存在する.

## Contents

以降の説明では, $v \in V$ と $\varphi(v) \in \mathbb{Q}_{+}$ が一対一対応にあるため, これを同一視することがある.

以下の型エイリアスを定義する.
```cpp
using Fraction = pair<ll, ll>;

template<typename Direction>
using Path = vector<pair<Direction, ll>>;
```

特に, `Fraction` については, `first` が分子, `second` が分母を表す.

### encode

```cpp
template<typename Direction>
Path<Direction> encode(ll a, ll b, Direction left, Direction right)
```

* $T$ における頂点 $\frac{a}{b}$ への行き方を求める.
* **返り値** : 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
  * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す.
* **計算量** : $O(\log(a + b))$ 時間.

### decode_interval

```cpp
template<typename Direction>
pair<Fraction, Fraction> decode_interval(Path<Direction> &code, Direction left, Direction right)
```

* $T$ において, `code` の順番で辿った時に到達する $\widehat{\mathbb{Q}_{+0}}$ 上の開区間の端点を求める.
* **引数**
  * `code`: 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
    * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す. 
* **返り値**
  * 第 $1$ 要素が開区間の下限, 第 $2$ 要素が開区間の上限になる.
* **計算量** : `code` の長さを $m$ として, $O(m)$ 時間.

### decode_interval

```cpp
template<typename Direction>
Fraction decode(Path<Direction> &code, Direction left, Direction right)
```

* $T$ において, `code` の順番で辿った時に到達する正の有理数を求める.
* **入力**
  * `code`: 以下の要件を満たす各要素が `pair<Direction, ll>` であるリスト.
    * リストの中の要素 $(d, k)$ について, $d = $`left` ならば, $k$ 回連続で左の子に進むことを, $d=$`right` ならば, $k$ 回連続で右の子に進むことを表す. 
* **計算量** : `code` の長さを $m$ として, $O(m)$ 時間.

### lowest_common_ancestor

```cpp
Fraction lowest_common_ancestor(ll a, ll b, ll c, ll d)
```

* $T$ における $\frac{a}{b}$ と $\frac{c}{d}$ の最小共通祖先を求める.
* **計算量** : $O(\log(a+b+c+d))$ 時間

### ancestor

```cpp
Fraction ancestor(ll a, ll b, ll k, Fraction default_value = {-1, -1})
```

* $T$ における $\frac{a}{b}$ の祖先のうち, 深さがちょうど $k$ であるものを求める. ただし, 存在しない時の返り値は $-1/-1$ とする.
* **計算量** : $O(\log(a+b))$ 時間.

### range

```cpp
pair<Fraction, Fraction> range(ll a, ll b)
```

* $\varphi(v) = a/b$ となる $v \in V$ の下限と上限を求める.
* **返り値**
  * 第 $1$ 要素が開区間の下限, 第 $2$ 要素が開区間の上限になる.
* **計算量** : $O(\log(a+b))$ 時間.

### binary_search_range_increase

```cpp
pair<Fraction, Fraction> binary_search_range_increase(ll N, function<bool(ll, ll)> cond)
```

* 単調増加な条件 $\textrm{cond}$ において, $\textrm{cond}(x) = \mathbb{T}$ となる最小の $x$ を挟む分子と分母が $N$ 以下の有理数を求める.
* **引数**
  * $\textrm{cond}$: $\mathbb{Q}_+$ 上の単調増加な関数. ただし, 実装上は $2$ 変数関数とし, $\textrm{cond}(a, b) = \textrm{cond}(a/b)$ を意味する.
* **返り値**
  * $Q_N$ を分子と分母が共に $N$ 以下である正の有理数全体の集合とする.
  * 第 $1$ 要素は $\sup \\\{x \in Q_N \mid \lnot \mathrm{cond}(x) \\\}$ である有理数である. 要するに, $\mathrm{cond}(x)$ を満たさない $Q_N$ の最大の要素である.
  * 第 $2$ 要素は $\inf \\\{y \in Q_N \mid \mathrm{cond}(y) \\\}$ である有理数である. 要するに, $\mathrm{cond}(y)$ を満たす $Q_N$ の最小の要素である.
