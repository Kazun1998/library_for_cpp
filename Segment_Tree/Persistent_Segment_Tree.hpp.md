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
    path: verify/yosupo_library_checker/data_structure/Static_Range_Frequency.test.cpp
    title: verify/yosupo_library_checker/data_structure/Static_Range_Frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u914D\u5217 data\
      \ \u3067\u521D\u671F\u5316\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Segment_Tree/Persistent_Segment_Tree.hpp\"\n\n#line 2 \"\
    template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <cinttypes>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <concepts>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <optional>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n\
    #include <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n\
    #include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include\
    \ <utility>\n#include <vector>\n\n// utility\n#line 2 \"template/utility.hpp\"\
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
    \    }\n};\n#line 4 \"Segment_Tree/Persistent_Segment_Tree.hpp\"\n\ntemplate<typename\
    \ M>\nclass Persistent_Segment_Tree {\n    private:\n    struct Node {\n     \
    \   M x;\n        Node *left_child, *right_child;\n\n        Node(M x) : x(x),\
    \ left_child(nullptr), right_child(nullptr) {}\n        Node(M x, Node* left,\
    \ Node* right) : x(x), left_child(left), right_child(right) {}\n    };\n\n   \
    \ int n;\n    const function<M(M, M)> op;\n    const M identity;\n    vector<Node*>\
    \ roots;\n    vector<Node*> nodes_pool;\n    int version;\n\n    Node* new_node(M\
    \ x, Node* l = nullptr, Node* r = nullptr) {\n        Node* res = new Node(x,\
    \ l, r);\n        nodes_pool.push_back(res);\n        return res;\n    }\n\n \
    \   Node* build(const int l, const int r, const vector<M> &data) {\n        if\
    \ (l >= r) return nullptr;\n        // 1 \u8981\u7D20\u533A\u9593\u3092\u8868\u3059\
    \u9802\u70B9 \u2192 \u8449\n        if (r - l == 1) return new_node(data[l]);\n\
    \n        // \u305D\u3046\u3067\u306A\u3044\u5834\u5408, 2 \u8981\u7D20\u4EE5\u4E0A\
    \u306E\u533A\u9593\u306A\u306E\u3067, \u5DE6\u3068\u53F3\u306B\u5206\u5272\u3067\
    \u304D\u308B.\n        int m = (l + r) / 2;\n\n        Node* left = build(l, m,\
    \ data);\n        Node* right = build(m, r, data);\n\n        return new_node(op(left->x,\
    \ right->x), left, right);\n    }\n\n    void build_up(const vector<M> &data)\
    \ {\n        if (n > 0) roots.emplace_back(build(0, n, data));\n        else roots.emplace_back(nullptr);\n\
    \    }\n\n    Node* _update(const Node* node, const int l, const int r, const\
    \ int k, const M x) {\n        // \u8449\u306B\u5230\u9054\u3057\u305F\u5834\u5408\
    , \u65B0\u3057\u3044\u5024\u3092\u4FDD\u6301\u3059\u308B\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u6210\u3057\u3066\u8FD4\u3059.\n        if (r - l == 1) return new_node(x);\n\
    \n        int m = (l + r) / 2;\n        Node *left = node->left_child, *right\
    \ = node->right_child;\n\n        // \u66F4\u65B0\u5BFE\u8C61\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306B\u5FDC\u3058\u3066, \u5DE6\u307E\u305F\u306F\u53F3\
    \u306E\u5B50\u3092\u518D\u5E30\u7684\u306B\u65B0\u3057\u304F\u4F5C\u6210\u3059\
    \u308B\n        if (k < m) left = _update(left, l, m, k, x);\n        else right\
    \ = _update(right, m, r, k, x);\n\n        // \u65B0\u3057\u304F\u4F5C\u6210\u3057\
    \u305F\u5B50\uFF08\u7247\u65B9\uFF09\u3068, \u65E2\u5B58\u306E\u3082\u3046\u7247\
    \u65B9\u306E\u5B50\u3092\u7D44\u307F\u5408\u308F\u305B\u3066,\u73FE\u5728\u306E\
    \u9AD8\u3055\u306E\u30CE\u30FC\u30C9\u3092\u65B0\u3057\u304F\u4F5C\u6210\u3059\
    \u308B\n        return new_node(op(left->x, right->x), left, right);\n    }\n\n\
    \    // \u534A\u958B\u533A\u9593 [l, r) \u3092\u8A08\u7B97\u3059\u308B. \u73FE\
    \u5728\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u306F\u534A\u958B\u533A\u9593\
    \ [a, b) \u3092\u8868\u3059.\n    M _product(const Node* node, const int l, const\
    \ int r, const int a, const int b) const {\n        // [l, r) \u3068 [a, b) \u304C\
    \u4E92\u3044\u306B\u7D20\u306A\u3089\u3070, \u5358\u4F4D\u5143\u3092\u8FD4\u3059\
    .\n        if (b <= l || r <= a) return identity;\n        \n        // [a, b)\
    \ \u304C [l, r) \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u306A\u3089\u3070,\
    \ \u30CE\u30FC\u30C9\u306E\u5024\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059.\n\
    \        if (l <= a && b <= r) return node->x;\n\n        int m = (a + b) / 2;\n\
    \n        M vl = _product(node->left_child, l, r, a, m);\n        M vr = _product(node->right_child,\
    \ l, r, m, b);\n\n        return op(vl, vr);\n    }\n\n    M _get(const Node*\
    \ node, const int l, const int r, const int k) const {\n        if (r - l == 1)\
    \ return node->x;\n        int m = (l + r) / 2;\n        if (k < m) return _get(node->left_child,\
    \ l, m, k);\n        else return _get(node->right_child, m, r, k);\n    }\n\n\
    \    Node* _copy(const Node* node_curr, const Node* node_src, const int l, const\
    \ int r, const int a, const int b) {\n        if (b <= l || r <= a) return const_cast<Node*>(node_curr);\n\
    \        if (l <= a && b <= r) return const_cast<Node*>(node_src);\n\n       \
    \ int m = (a + b) / 2;\n        Node *left = _copy(node_curr->left_child, node_src->left_child,\
    \ l, r, a, m);\n        Node *right = _copy(node_curr->right_child, node_src->right_child,\
    \ l, r, m, b);\n\n        return new_node(op(left->x, right->x), left, right);\n\
    \    }\n\n    public:\n    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    . \u914D\u5217 data \u3067\u521D\u671F\u5316\u3059\u308B.\n    /// @param data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\n    /// @param op \u4E8C\u9805\u6F14\u7B97\u5B50\
    \n    /// @param identity \u5358\u4F4D\u5143\n    Persistent_Segment_Tree(const\
    \ vector<M> &data, const function<M(M, M)> op, const M identity): n(data.size()),\
    \ op(op), identity(identity), version(0) {\n        build_up(data);\n    }\n\n\
    \    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u30B5\u30A4\u30BA\
    \ n, \u5168\u8981\u7D20 identity \u3067\u521D\u671F\u5316\u3059\u308B.\n    ///\
    \ @param n \u914D\u5217\u30B5\u30A4\u30BA\n    /// @param op \u4E8C\u9805\u6F14\
    \u7B97\u5B50\n    /// @param identity \u5358\u4F4D\u5143\n    Persistent_Segment_Tree(const\
    \ int n, const function<M(M, M)> op, const M identity): n(n), op(op), identity(identity),\
    \ version(0) {\n        build_up(vector<M>(n, identity));\n    }\n\n    ~Persistent_Segment_Tree()\
    \ {\n        for (Node* node : nodes_pool) delete node;\n    }\n\n    /// @brief\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u30B3\u30D4\u30FC\u3057\u3066\u65B0\u3057\
    \u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4F5C\u6210\u3057, \u305D\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059.\n    /// @param t \u30D9\u30FC\
    \u30B9\u3068\u3059\u308B\u30D0\u30FC\u30B8\u30E7\u30F3 (\u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306F\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3)\n    /// @return \u65B0\
    \u3057\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int increment(int\
    \ t = -1) {\n        if (t == -1) t = version;\n        assert(t <= version);\n\
    \        roots.emplace_back(roots[t]);\n        return ++version;\n    }\n\n \
    \   /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 s \u3092\u30D9\u30FC\u30B9\u306B\
    \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u72B6\u614B\u3092\
    \u4F5C\u6210\u3057, \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u4EE3\u5165\u3059\u308B\
    .\n    /// @param s \u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u4FDD\u5B58\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param k \u66F4\
    \u65B0\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @param\
    \ x \u66F4\u65B0\u5F8C\u306E\u5024\n    /// @return \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ t\n    int update(const int s, const int t, const int k, const M x) {\n    \
    \    assert(s <= version);\n        assert(t <= version);\n        assert(0 <=\
    \ k && k < n);\n\n        roots[t] = _update(roots[s], 0, n, k, x);\n        return\
    \ t;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u30D9\u30FC\
    \u30B9\u306B\u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u65B0\
    \u3057\u3044\u72B6\u614B\u3092\u4F5C\u6210\u3059\u308B. \u73FE\u5728\u306E\u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4E0A\u66F8\u304D\u3059\u308B.\n  \
    \  /// @param t \u30D9\u30FC\u30B9\u3068\u3059\u308B\u30D0\u30FC\u30B8\u30E7\u30F3\
    \n    /// @param k \u66F4\u65B0\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \ (0-indexed)\n    /// @param x \u66F4\u65B0\u5F8C\u306E\u5024\n    /// @return\
    \ \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int update(const\
    \ int t, const int k, const M x) { return update(t, version, k, x); }\n\n    ///\
    \ @brief \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u30D9\u30FC\u30B9\u306B\
    \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u65B0\u3057\u3044\
    \u72B6\u614B\u3092\u4F5C\u6210\u3057\u3001\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\
    \u30F3\u3092\u4E0A\u66F8\u304D\u3059\u308B.\n    /// @param k \u66F4\u65B0\u3059\
    \u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @param x \u66F4\
    \u65B0\u5F8C\u306E\u5024\n    /// @return \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\
    \u30F3\u756A\u53F7\n    int update(const int k, const M x) { return update(version,\
    \ k, x); }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u305D\u306E\
    \u5834\u3067\u66F4\u65B0\uFF08\u4E0A\u66F8\u304D\uFF09\u3059\u308B (update(t,\
    \ t, k, x) \u306E\u30B7\u30CE\u30CB\u30E0).\n    /// @param t \u66F4\u65B0\u5BFE\
    \u8C61\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n    /// @param x \u5024\n    /// @return \u30D0\u30FC\u30B8\
    \u30E7\u30F3\u756A\u53F7 t\n    int amend(const int t, const int k, const M x)\
    \ { return update(t, t, k, x); }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ s \u306E [l, r] \u306E\u7BC4\u56F2\u3092\u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\
    \u30B3\u30D4\u30FC\uFF08\u30DE\u30FC\u30B8\uFF09\u3057\u305F\u3082\u306E\u3092\
    \u30D0\u30FC\u30B8\u30E7\u30F3 u \u306B\u4FDD\u5B58\u3059\u308B.\n    /// @param\
    \ s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u30B3\u30D4\u30FC\u5148\u306E\u30D9\u30FC\u30B9\u3068\u306A\u308B\u30D0\u30FC\
    \u30B8\u30E7\u30F3\n    /// @param u \u7D50\u679C\u306E\u4FDD\u5B58\u5148\u30D0\
    \u30FC\u30B8\u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n\
    \    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u30D0\u30FC\
    \u30B8\u30E7\u30F3 u\n    int copy(const int s, const int t, const int u, const\
    \ int l, const int r) {\n        assert(s <= version);\n        assert(t <= version);\n\
    \        assert(u <= version);\n        if (n == 0 || l > r) return u;\n     \
    \   assert(0 <= l && r < n);\n\n        roots[u] = _copy(roots[t], roots[s], l,\
    \ r + 1, 0, n);\n        return u;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\
    \u30E7\u30F3 s \u306E [l, r] \u306E\u7BC4\u56F2\u3092\u30D0\u30FC\u30B8\u30E7\u30F3\
    \ t \u306B\u30B3\u30D4\u30FC\uFF08\u30DE\u30FC\u30B8\uFF09\u3059\u308B.\n    ///\
    \ @param s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    ///\
    \ @param t \u30B3\u30D4\u30FC\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    ///\
    \ @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n    /// @param r \u53F3\u7AEF (\u9589\
    \u533A\u9593)\n    /// @return \u30D0\u30FC\u30B8\u30E7\u30F3 t\n    int copy(const\
    \ int s, const int t, const int l, const int r) { return copy(s, t, t, l, r);\
    \ }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306E [l, r] \u306E\u7BC4\
    \u56F2\u3092\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u30B3\u30D4\u30FC\
    \u3059\u308B.\n    /// @param t \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\
    \u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n    /// @param\
    \ r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u6700\u65B0\u30D0\u30FC\
    \u30B8\u30E7\u30F3\u756A\u53F7\n    int copy(const int t, const int l, const int\
    \ r) { return copy(t, version, version, l, r); }\n\n    /// @brief \u30D0\u30FC\
    \u30B8\u30E7\u30F3 s \u306E\u5185\u5BB9\u3092\u30D0\u30FC\u30B8\u30E7\u30F3 t\
    \ \u306B\u305D\u306E\u307E\u307E\u30B3\u30D4\u30FC\u3059\u308B.\n    /// @param\
    \ s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u30B3\u30D4\u30FC\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @return\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t\n    int clone(const int s, const int t) {\n\
    \        assert(s <= version);\n        assert(t <= version);\n        roots[t]\
    \ = roots[s];\n        return t;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\
    \u30F3 t \u306E\u5185\u5BB9\u3092\u73FE\u5728\u306E\u6700\u65B0\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306B\u305D\u306E\u307E\u307E\u30B3\u30D4\u30FC\u3059\u308B.\n  \
    \  /// @param t \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n\
    \    /// @return \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int\
    \ clone(const int t) { return clone(t, version); }\n\n    /// @brief \u30D0\u30FC\
    \u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B [l, r] \u306E\u7BC4\u56F2\u306E\u7DCF\
    \u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param t \u53D6\u5F97\u5BFE\u8C61\u306E\
    \u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593\
    )\n    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u533A\u9593\
    \u306E\u7DCF\u7A4D\n    M product(const int t, const int l, const int r) const\
    \ {\n        assert(t <= version);\n        if (l > r || n == 0) return identity;\n\
    \        return _product(roots[t], l, r + 1, 0, n);\n    }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B [l, r] \u306E\u7BC4\
    \u56F2\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param l \u5DE6\u7AEF\
    \ (\u9589\u533A\u9593)\n    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n \
    \   /// @return \u533A\u9593\u306E\u7DCF\u7A4D\n    M product(const int l, const\
    \ int r) const {\n        return product(version, l, r);\n    }\n\n    /// @brief\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B\u5168\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param t \u53D6\u5F97\u5BFE\u8C61\
    \u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @return \u5168\u533A\u9593\u306E\
    \u7DCF\u7A4D\n    M all_product(const int t) const {\n        assert(t <= version);\n\
    \        return (n == 0 || !roots[t]) ? identity : roots[t]->x;\n    }\n\n   \
    \ /// @brief \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\
    \u5168\u533A\u9593\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @return\
    \ \u5168\u533A\u9593\u306E\u7DCF\u7A4D\n    M all_product() const { return all_product(version);\
    \ }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B\
    \u7B2C k \u8981\u7D20\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param\
    \ t \u53D6\u5F97\u5BFE\u8C61\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @return \u8981\u7D20\
    \u306E\u5024\n    M get(const int t, const int k) const {\n        assert(t <=\
    \ version);\n        if (n == 0) return identity;\n        assert(0 <= k && k\
    \ < n);\n\n        return _get(roots[t], 0, n, k);\n    }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\u7B2C k \u8981\u7D20\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (0-indexed)\n    /// @return \u8981\u7D20\u306E\u5024\n   \
    \ M get(const int k) const { return get(version, k); }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\u7B2C k \u8981\u7D20\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    M operator[](const int k) const\
    \ { return get(version, k); }\n\n    /// @brief \u73FE\u5728\u306E\u6700\u65B0\
    \u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B.\n  \
    \  int current_version() const { return version; }\n\n    /// @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u306B\u304A\u3051\u308B\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B.\n    size_t size() const { return n; }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate<typename\
    \ M>\nclass Persistent_Segment_Tree {\n    private:\n    struct Node {\n     \
    \   M x;\n        Node *left_child, *right_child;\n\n        Node(M x) : x(x),\
    \ left_child(nullptr), right_child(nullptr) {}\n        Node(M x, Node* left,\
    \ Node* right) : x(x), left_child(left), right_child(right) {}\n    };\n\n   \
    \ int n;\n    const function<M(M, M)> op;\n    const M identity;\n    vector<Node*>\
    \ roots;\n    vector<Node*> nodes_pool;\n    int version;\n\n    Node* new_node(M\
    \ x, Node* l = nullptr, Node* r = nullptr) {\n        Node* res = new Node(x,\
    \ l, r);\n        nodes_pool.push_back(res);\n        return res;\n    }\n\n \
    \   Node* build(const int l, const int r, const vector<M> &data) {\n        if\
    \ (l >= r) return nullptr;\n        // 1 \u8981\u7D20\u533A\u9593\u3092\u8868\u3059\
    \u9802\u70B9 \u2192 \u8449\n        if (r - l == 1) return new_node(data[l]);\n\
    \n        // \u305D\u3046\u3067\u306A\u3044\u5834\u5408, 2 \u8981\u7D20\u4EE5\u4E0A\
    \u306E\u533A\u9593\u306A\u306E\u3067, \u5DE6\u3068\u53F3\u306B\u5206\u5272\u3067\
    \u304D\u308B.\n        int m = (l + r) / 2;\n\n        Node* left = build(l, m,\
    \ data);\n        Node* right = build(m, r, data);\n\n        return new_node(op(left->x,\
    \ right->x), left, right);\n    }\n\n    void build_up(const vector<M> &data)\
    \ {\n        if (n > 0) roots.emplace_back(build(0, n, data));\n        else roots.emplace_back(nullptr);\n\
    \    }\n\n    Node* _update(const Node* node, const int l, const int r, const\
    \ int k, const M x) {\n        // \u8449\u306B\u5230\u9054\u3057\u305F\u5834\u5408\
    , \u65B0\u3057\u3044\u5024\u3092\u4FDD\u6301\u3059\u308B\u30CE\u30FC\u30C9\u3092\
    \u4F5C\u6210\u3057\u3066\u8FD4\u3059.\n        if (r - l == 1) return new_node(x);\n\
    \n        int m = (l + r) / 2;\n        Node *left = node->left_child, *right\
    \ = node->right_child;\n\n        // \u66F4\u65B0\u5BFE\u8C61\u306E\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306B\u5FDC\u3058\u3066, \u5DE6\u307E\u305F\u306F\u53F3\
    \u306E\u5B50\u3092\u518D\u5E30\u7684\u306B\u65B0\u3057\u304F\u4F5C\u6210\u3059\
    \u308B\n        if (k < m) left = _update(left, l, m, k, x);\n        else right\
    \ = _update(right, m, r, k, x);\n\n        // \u65B0\u3057\u304F\u4F5C\u6210\u3057\
    \u305F\u5B50\uFF08\u7247\u65B9\uFF09\u3068, \u65E2\u5B58\u306E\u3082\u3046\u7247\
    \u65B9\u306E\u5B50\u3092\u7D44\u307F\u5408\u308F\u305B\u3066,\u73FE\u5728\u306E\
    \u9AD8\u3055\u306E\u30CE\u30FC\u30C9\u3092\u65B0\u3057\u304F\u4F5C\u6210\u3059\
    \u308B\n        return new_node(op(left->x, right->x), left, right);\n    }\n\n\
    \    // \u534A\u958B\u533A\u9593 [l, r) \u3092\u8A08\u7B97\u3059\u308B. \u73FE\
    \u5728\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u306F\u534A\u958B\u533A\u9593\
    \ [a, b) \u3092\u8868\u3059.\n    M _product(const Node* node, const int l, const\
    \ int r, const int a, const int b) const {\n        // [l, r) \u3068 [a, b) \u304C\
    \u4E92\u3044\u306B\u7D20\u306A\u3089\u3070, \u5358\u4F4D\u5143\u3092\u8FD4\u3059\
    .\n        if (b <= l || r <= a) return identity;\n        \n        // [a, b)\
    \ \u304C [l, r) \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u306A\u3089\u3070,\
    \ \u30CE\u30FC\u30C9\u306E\u5024\u3092\u305D\u306E\u307E\u307E\u8FD4\u3059.\n\
    \        if (l <= a && b <= r) return node->x;\n\n        int m = (a + b) / 2;\n\
    \n        M vl = _product(node->left_child, l, r, a, m);\n        M vr = _product(node->right_child,\
    \ l, r, m, b);\n\n        return op(vl, vr);\n    }\n\n    M _get(const Node*\
    \ node, const int l, const int r, const int k) const {\n        if (r - l == 1)\
    \ return node->x;\n        int m = (l + r) / 2;\n        if (k < m) return _get(node->left_child,\
    \ l, m, k);\n        else return _get(node->right_child, m, r, k);\n    }\n\n\
    \    Node* _copy(const Node* node_curr, const Node* node_src, const int l, const\
    \ int r, const int a, const int b) {\n        if (b <= l || r <= a) return const_cast<Node*>(node_curr);\n\
    \        if (l <= a && b <= r) return const_cast<Node*>(node_src);\n\n       \
    \ int m = (a + b) / 2;\n        Node *left = _copy(node_curr->left_child, node_src->left_child,\
    \ l, r, a, m);\n        Node *right = _copy(node_curr->right_child, node_src->right_child,\
    \ l, r, m, b);\n\n        return new_node(op(left->x, right->x), left, right);\n\
    \    }\n\n    public:\n    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    . \u914D\u5217 data \u3067\u521D\u671F\u5316\u3059\u308B.\n    /// @param data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\n    /// @param op \u4E8C\u9805\u6F14\u7B97\u5B50\
    \n    /// @param identity \u5358\u4F4D\u5143\n    Persistent_Segment_Tree(const\
    \ vector<M> &data, const function<M(M, M)> op, const M identity): n(data.size()),\
    \ op(op), identity(identity), version(0) {\n        build_up(data);\n    }\n\n\
    \    /// @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF. \u30B5\u30A4\u30BA\
    \ n, \u5168\u8981\u7D20 identity \u3067\u521D\u671F\u5316\u3059\u308B.\n    ///\
    \ @param n \u914D\u5217\u30B5\u30A4\u30BA\n    /// @param op \u4E8C\u9805\u6F14\
    \u7B97\u5B50\n    /// @param identity \u5358\u4F4D\u5143\n    Persistent_Segment_Tree(const\
    \ int n, const function<M(M, M)> op, const M identity): n(n), op(op), identity(identity),\
    \ version(0) {\n        build_up(vector<M>(n, identity));\n    }\n\n    ~Persistent_Segment_Tree()\
    \ {\n        for (Node* node : nodes_pool) delete node;\n    }\n\n    /// @brief\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u30B3\u30D4\u30FC\u3057\u3066\u65B0\u3057\
    \u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4F5C\u6210\u3057, \u305D\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059.\n    /// @param t \u30D9\u30FC\
    \u30B9\u3068\u3059\u308B\u30D0\u30FC\u30B8\u30E7\u30F3 (\u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306F\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3)\n    /// @return \u65B0\
    \u3057\u3044\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int increment(int\
    \ t = -1) {\n        if (t == -1) t = version;\n        assert(t <= version);\n\
    \        roots.emplace_back(roots[t]);\n        return ++version;\n    }\n\n \
    \   /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 s \u3092\u30D9\u30FC\u30B9\u306B\
    \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u72B6\u614B\u3092\
    \u4F5C\u6210\u3057, \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u4EE3\u5165\u3059\u308B\
    .\n    /// @param s \u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u4FDD\u5B58\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param k \u66F4\
    \u65B0\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @param\
    \ x \u66F4\u65B0\u5F8C\u306E\u5024\n    /// @return \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ t\n    int update(const int s, const int t, const int k, const M x) {\n    \
    \    assert(s <= version);\n        assert(t <= version);\n        assert(0 <=\
    \ k && k < n);\n\n        roots[t] = _update(roots[s], 0, n, k, x);\n        return\
    \ t;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u30D9\u30FC\
    \u30B9\u306B\u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u65B0\
    \u3057\u3044\u72B6\u614B\u3092\u4F5C\u6210\u3059\u308B. \u73FE\u5728\u306E\u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u4E0A\u66F8\u304D\u3059\u308B.\n  \
    \  /// @param t \u30D9\u30FC\u30B9\u3068\u3059\u308B\u30D0\u30FC\u30B8\u30E7\u30F3\
    \n    /// @param k \u66F4\u65B0\u3059\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \ (0-indexed)\n    /// @param x \u66F4\u65B0\u5F8C\u306E\u5024\n    /// @return\
    \ \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int update(const\
    \ int t, const int k, const M x) { return update(t, version, k, x); }\n\n    ///\
    \ @brief \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u3092\u30D9\u30FC\u30B9\u306B\
    \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3057\u305F\u65B0\u3057\u3044\
    \u72B6\u614B\u3092\u4F5C\u6210\u3057\u3001\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\
    \u30F3\u3092\u4E0A\u66F8\u304D\u3059\u308B.\n    /// @param k \u66F4\u65B0\u3059\
    \u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @param x \u66F4\
    \u65B0\u5F8C\u306E\u5024\n    /// @return \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\
    \u30F3\u756A\u53F7\n    int update(const int k, const M x) { return update(version,\
    \ k, x); }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u3092\u305D\u306E\
    \u5834\u3067\u66F4\u65B0\uFF08\u4E0A\u66F8\u304D\uFF09\u3059\u308B (update(t,\
    \ t, k, x) \u306E\u30B7\u30CE\u30CB\u30E0).\n    /// @param t \u66F4\u65B0\u5BFE\
    \u8C61\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\n    /// @param x \u5024\n    /// @return \u30D0\u30FC\u30B8\
    \u30E7\u30F3\u756A\u53F7 t\n    int amend(const int t, const int k, const M x)\
    \ { return update(t, t, k, x); }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3\
    \ s \u306E [l, r] \u306E\u7BC4\u56F2\u3092\u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\
    \u30B3\u30D4\u30FC\uFF08\u30DE\u30FC\u30B8\uFF09\u3057\u305F\u3082\u306E\u3092\
    \u30D0\u30FC\u30B8\u30E7\u30F3 u \u306B\u4FDD\u5B58\u3059\u308B.\n    /// @param\
    \ s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u30B3\u30D4\u30FC\u5148\u306E\u30D9\u30FC\u30B9\u3068\u306A\u308B\u30D0\u30FC\
    \u30B8\u30E7\u30F3\n    /// @param u \u7D50\u679C\u306E\u4FDD\u5B58\u5148\u30D0\
    \u30FC\u30B8\u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n\
    \    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u30D0\u30FC\
    \u30B8\u30E7\u30F3 u\n    int copy(const int s, const int t, const int u, const\
    \ int l, const int r) {\n        assert(s <= version);\n        assert(t <= version);\n\
    \        assert(u <= version);\n        if (n == 0 || l > r) return u;\n     \
    \   assert(0 <= l && r < n);\n\n        roots[u] = _copy(roots[t], roots[s], l,\
    \ r + 1, 0, n);\n        return u;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\
    \u30E7\u30F3 s \u306E [l, r] \u306E\u7BC4\u56F2\u3092\u30D0\u30FC\u30B8\u30E7\u30F3\
    \ t \u306B\u30B3\u30D4\u30FC\uFF08\u30DE\u30FC\u30B8\uFF09\u3059\u308B.\n    ///\
    \ @param s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    ///\
    \ @param t \u30B3\u30D4\u30FC\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    ///\
    \ @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n    /// @param r \u53F3\u7AEF (\u9589\
    \u533A\u9593)\n    /// @return \u30D0\u30FC\u30B8\u30E7\u30F3 t\n    int copy(const\
    \ int s, const int t, const int l, const int r) { return copy(s, t, t, l, r);\
    \ }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306E [l, r] \u306E\u7BC4\
    \u56F2\u3092\u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u30B3\u30D4\u30FC\
    \u3059\u308B.\n    /// @param t \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\
    \u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593)\n    /// @param\
    \ r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u6700\u65B0\u30D0\u30FC\
    \u30B8\u30E7\u30F3\u756A\u53F7\n    int copy(const int t, const int l, const int\
    \ r) { return copy(t, version, version, l, r); }\n\n    /// @brief \u30D0\u30FC\
    \u30B8\u30E7\u30F3 s \u306E\u5185\u5BB9\u3092\u30D0\u30FC\u30B8\u30E7\u30F3 t\
    \ \u306B\u305D\u306E\u307E\u307E\u30B3\u30D4\u30FC\u3059\u308B.\n    /// @param\
    \ s \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ t \u30B3\u30D4\u30FC\u5148\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @return\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t\n    int clone(const int s, const int t) {\n\
    \        assert(s <= version);\n        assert(t <= version);\n        roots[t]\
    \ = roots[s];\n        return t;\n    }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\
    \u30F3 t \u306E\u5185\u5BB9\u3092\u73FE\u5728\u306E\u6700\u65B0\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306B\u305D\u306E\u307E\u307E\u30B3\u30D4\u30FC\u3059\u308B.\n  \
    \  /// @param t \u30B3\u30D4\u30FC\u5143\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n\
    \    /// @return \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\n    int\
    \ clone(const int t) { return clone(t, version); }\n\n    /// @brief \u30D0\u30FC\
    \u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B [l, r] \u306E\u7BC4\u56F2\u306E\u7DCF\
    \u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param t \u53D6\u5F97\u5BFE\u8C61\u306E\
    \u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param l \u5DE6\u7AEF (\u9589\u533A\u9593\
    )\n    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n    /// @return \u533A\u9593\
    \u306E\u7DCF\u7A4D\n    M product(const int t, const int l, const int r) const\
    \ {\n        assert(t <= version);\n        if (l > r || n == 0) return identity;\n\
    \        return _product(roots[t], l, r + 1, 0, n);\n    }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B [l, r] \u306E\u7BC4\
    \u56F2\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param l \u5DE6\u7AEF\
    \ (\u9589\u533A\u9593)\n    /// @param r \u53F3\u7AEF (\u9589\u533A\u9593)\n \
    \   /// @return \u533A\u9593\u306E\u7DCF\u7A4D\n    M product(const int l, const\
    \ int r) const {\n        return product(version, l, r);\n    }\n\n    /// @brief\
    \ \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B\u5168\u533A\u9593\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @param t \u53D6\u5F97\u5BFE\u8C61\
    \u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @return \u5168\u533A\u9593\u306E\
    \u7DCF\u7A4D\n    M all_product(const int t) const {\n        assert(t <= version);\n\
    \        return (n == 0 || !roots[t]) ? identity : roots[t]->x;\n    }\n\n   \
    \ /// @brief \u6700\u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\
    \u5168\u533A\u9593\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @return\
    \ \u5168\u533A\u9593\u306E\u7DCF\u7A4D\n    M all_product() const { return all_product(version);\
    \ }\n\n    /// @brief \u30D0\u30FC\u30B8\u30E7\u30F3 t \u306B\u304A\u3051\u308B\
    \u7B2C k \u8981\u7D20\u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param\
    \ t \u53D6\u5F97\u5BFE\u8C61\u306E\u30D0\u30FC\u30B8\u30E7\u30F3\n    /// @param\
    \ k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (0-indexed)\n    /// @return \u8981\u7D20\
    \u306E\u5024\n    M get(const int t, const int k) const {\n        assert(t <=\
    \ version);\n        if (n == 0) return identity;\n        assert(0 <= k && k\
    \ < n);\n\n        return _get(roots[t], 0, n, k);\n    }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\u7B2C k \u8981\u7D20\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param k \u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (0-indexed)\n    /// @return \u8981\u7D20\u306E\u5024\n   \
    \ M get(const int k) const { return get(version, k); }\n\n    /// @brief \u6700\
    \u65B0\u30D0\u30FC\u30B8\u30E7\u30F3\u306B\u304A\u3051\u308B\u7B2C k \u8981\u7D20\
    \u306E\u5024\u3092\u53D6\u5F97\u3059\u308B.\n    M operator[](const int k) const\
    \ { return get(version, k); }\n\n    /// @brief \u73FE\u5728\u306E\u6700\u65B0\
    \u30D0\u30FC\u30B8\u30E7\u30F3\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B.\n  \
    \  int current_version() const { return version; }\n\n    /// @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\u306B\u304A\u3051\u308B\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B.\n    size_t size() const { return n; }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Segment_Tree/Persistent_Segment_Tree.hpp
  requiredBy: []
  timestamp: '2026-04-26 00:54:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Static_Range_Frequency.test.cpp
documentation_of: Segment_Tree/Persistent_Segment_Tree.hpp
layout: document
title: "\u6C38\u7D9A Segment Tree"
---

## Outline

Segment Tree を永続化する. 区間を表すノードをポインタで実装する. そのため, 区間のコピーなどに対する処理を得意としている.
## Contents

### Constructor

```cpp
(1)
template<typename M>
Persistent_Segment_Tree(const vector<M> &data, const function<M(M, M)> op, const M identity)

(2)
template<typename M>
Persistent_Segment_Tree(const int n, const function<M(M, M)> op, const M identity)
```

- $\textrm{op}$ を演算, $\textrm{identity}$ を単位元とするモノイド $M$ に関する Segment Tree を作成する.
  * (1) $M$ の列 $\textrm{data}$ で初期化する.
  * (2) 長さ $n$ の単位元だけからなる列で初期化する.
- **計算量**
  * $O(N)$ Time.

### update

```cpp
(1) int update(const int s, const int t, const int k, const M x)
(2) int update(const int t, const int k, const M x)
(3) int update(const int k, const M x)
```

- Segment Tree に対して, バージョンと場所を指定して, $x$ に変更する.
  * (1) バージョン $s$ の Segment Tree の第 $k$ 要素を, $x$ に更新したものを, バージョン $t$ として上書きする.
  * (2) バージョン $t$ の Segment Tree の第 $k$ 要素を, $x$ に更新したものを, 最新バージョンとして上書きする.
  * (3) 最新バージョンの Segment Tree の第 $k$ 要素を, $x$ に更新したものを, 最新バージョンとして上書きする.
* **制約**
  * 指定するバージョン $s, t$ が存在すること.
  * $0 \leq k < N$.
* **返り値**
  * 更新先のバージョン
- **計算量**
  * $O(\log N)$ Time.

### amend

```cpp
int amend(const int t, const int k, const M x)
```
- `update(t, t, k, x)` のシノニム. つまり, バージョン $t$ の Segment Tree を, 第 $k$ 要素を $x$ に更新したものに上書きする.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq k < N$.
* **返り値**
  * 更新先のバージョン
- **計算量**
  * $O(\log N)$ Time.

### copy

```cpp
(1) int copy(const int s, const int t, const int u, const int l, const int r)
(2) int copy(const int s, const int t, const int l, const int r)
(3) int copy(const int t, const int l, const int r)
```

* 閉区間 $[l, r]$ におけるノードをコピー（部分共有）する.
  * (1) バージョン $s$ における閉区間 $[l, r]$ をバージョン $t$ の閉区間 $[l, r]$ にコピーする.
  * (2) バージョン $t$ における閉区間 $[l, r]$ を最新バージョン閉区間 $[l, r]$ にコピーする.
* **制約**
  * 指定するバージョン $s, t, u$ が存在すること.
  * $0 \leq l \leq r \lt N$.
* **計算量**
  * $O(\log N)$ Time.

### increment

```cpp
int increment(int t = -1)
```

* バージョン $t$ をコピーして新しい最新バージョンを作成する. $t = -1$ の場合は現在の最新バージョンをコピーする.
* **返り値**
  * 新しい最新バージョンの番号
* **計算量**
  * $O(1)$ Time.

### clone

```cpp
(1) int clone(const int s, const int t)
(2) int clone(const int t)
```

* `copy(s, t, 0, n - 1)` 相当の処理を行い, Segment Tree をそのままコピーする.
  * (1) バージョン $s$ の Segment Tree をバージョン $t$ の Segment Tree に完全コピーする.
  * (2) バージョン $t$ の Segment Tree を最新バージョンの Segment Tree に完全コピーする.
* **制約**
  * 指定するバージョン $s, t$ が存在すること.
* **計算量**
  * $O(1)$ Time.

### product

```cpp
(1) M product(const int t, const int l, const int r) const
(2) M product(const int l, const int r) const
```

* 閉区間 $[l, r]$ における要素の総積を求める.
  * (1) バージョン $t$ の Segment Tree 上の閉区間 $[l, r]$ における要素の総積を求める.
  * (2) 最新バージョンの Segment Tree 上の閉区間 $[l, r]$ における要素の総積を求める.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq l \leq r < N$.
* **計算量**
  * $O(\log N)$ Time.

### all_product

```cpp
(1) M all_product(const int t) const
(2) M all_product() const
```

* 全区間の総積を求める.
* **計算量**
  * $O(1)$ Time.

### get

```cpp
(1) M get(const int t, const int k) const
(2) M get(const int k) const
(3) M operator[](const int k) const
```

* 第 $k$ 要素を取得する.
  * (1) バージョン $t$ の第 $k$ 要素を取得する.
  * (2), (3) 最新バージョンの第 $k$ 要素を取得する.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq t < N$.
* **計算量**
  * $O(\log N)$ Time.

### current_version

```cpp
int current_version()
```

* 最新バージョンの番号を取得する.
* **計算量**
  * $O(1)$ Time.

### size

```cpp
size_t size()
```

* 1 つのバージョンにおける, Segment Tree の要素数を取得する.
* **計算量**
  * $O(1)$ Time.

## History

|日付|内容|
|:---:|:---|
|2026/04/26| Persistent_Segment_Tree 実装 |
