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
    path: verify/yosupo_library_checker/data_structure/Ordered_Set_3.test.cpp
    title: verify/yosupo_library_checker/data_structure/Ordered_Set_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Treap \u3092\u7A7A\u306B\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Data_Structure/Treap.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \n\n// inout\n#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\n#line 4 \"\
    template/inout.hpp\"\n\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ...\
    \ >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout\
    \ << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
    \    return is;\n}\n\ntemplate<typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &P){\n    os << P.first << \" \" << P.second;\n    return\
    \ os;\n}\n\ntemplate<typename T>\nistream &operator>>(istream &is, vector<T> &X){\n\
    \    for (auto &x: X) { is >> x; }\n    return is;\n}\n\ntemplate<typename T,\
    \ typename U = typename T::iterator>\ntypename std::enable_if<!std::is_same<T,\
    \ std::string>::value, ostream&>::type\noperator<<(ostream &os, const T &container){\n\
    \    bool is_first = true;\n    for (const auto &x : container) {\n        os\
    \ << (is_first ? \"\" : \" \") << x;\n        is_first = false;\n    }\n    return\
    \ os;\n}\n\ntemplate<typename T>\nstd::vector<T> input_vector(int n, int offset\
    \ = 0) {\n    std::vector<T> res;\n    // \u6700\u521D\u306B\u5FC5\u8981\u306A\
    \u5168\u5BB9\u91CF\u3092\u78BA\u4FDD\uFF08\u518D\u78BA\u4FDD\u3092\u9632\u3050\
    \uFF09\n    res.reserve(n + offset);\n    // offset \u5206\u3092\u30C7\u30D5\u30A9\
    \u30EB\u30C8\u5024\u3067\u57CB\u3081\u308B\uFF08\u7279\u5225 indexed \u7528\uFF09\
    \n    res.assign(offset, T());\n\n    for (int i = 0; i < n; ++i) {\n        T\
    \ el;\n        if (!(std::cin >> el)) break;\n        res.push_back(std::move(el));\n\
    \    }\n    return res;\n}\n\n#line 63 \"template/inout.hpp\"\n\n// 1. \u7D42\u7AEF\
    \uFF1A\u30B5\u30A4\u30BA n \u306E 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\ntemplate<typename\
    \ T>\nauto make_multi_dimensional_vector(int n) {\n    return std::vector<T>(n);\n\
    }\n\n// 2. \u7D42\u7AEF\uFF1A\u30B5\u30A4\u30BA n \u3067\u521D\u671F\u5024 val\
    \ \u3092\u6301\u3064 1 \u6B21\u5143 vector \u3092\u4F5C\u308B\uFF08\u30AA\u30FC\
    \u30D0\u30FC\u30ED\u30FC\u30C9\uFF09\ntemplate<typename T>\nauto make_multi_dimensional_vector(int\
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
    \    }\n};\n#line 4 \"Data_Structure/Treap.hpp\"\n\ntemplate<typename T>\nclass\
    \ Treap {\n    struct Node {\n        T key;\n        int priority;\n        int\
    \ size;\n        Node *left = nullptr, *right = nullptr;\n        Node(T key,\
    \ int priority) : key(key), priority(priority), size(1) {}\n    };\n\n    Node\
    \ *root = nullptr;\n    std::mt19937 mt;\n\n    static int get_size(Node* node)\
    \ { return node ? node->size : 0; }\n\n    static Node* update(Node* node) {\n\
    \        if (node) node->size = 1 + get_size(node->left) + get_size(node->right);\n\
    \        return node;\n    }\n\n    void clear(Node* node) {\n        if (!node)\
    \ return;\n        clear(node->left);\n        clear(node->right);\n        delete\
    \ node;\n    }\n\n    const Node* next_inner(const T &key, bool equal) const {\n\
    \        const Node *res = nullptr;\n        const Node *cur = root;\n       \
    \ while (cur) {\n            bool condition = equal ? (key <= cur->key) : (key\
    \ < cur->key);\n            if (condition) {\n                res = cur;\n   \
    \             cur = cur->left;\n            } else {\n                cur = cur->right;\n\
    \            }\n        }\n        return res;\n    }\n\n    const Node* previous_inner(const\
    \ T &key, bool equal) const {\n        const Node *res = nullptr;\n        const\
    \ Node *cur = root;\n        while (cur) {\n            bool condition = equal\
    \ ? (key >= cur->key) : (key > cur->key);\n            if (condition) {\n    \
    \            res = cur;\n                cur = cur->right;\n            } else\
    \ {\n                cur = cur->left;\n            }\n        }\n        return\
    \ res;\n    }\n\n    public:\n    Treap(): mt(std::random_device{}()) {}\n\n \
    \   Treap(std::initializer_list<T> init_list) : Treap() {\n        for (const\
    \ auto& x : init_list) insert(x);\n    }\n\n    template<class Iterator>\n   \
    \ Treap(Iterator first, Iterator last) : Treap() {\n        for (auto it = first;\
    \ it != last; ++it) insert(*it);\n    }\n\n    template<class Container>\n   \
    \ Treap(const Container& container) : Treap() {\n        for (const auto& x :\
    \ container) insert(x);\n    }\n\n    ~Treap() { clear(root); }\n\n    size_t\
    \ size() const { return get_size(root); }\n\n    bool empty() const { return size()\
    \ == 0; }\n\n    static Node* merge(Node* first, Node* second) {\n        if (!first\
    \ || !second) return first ? first : second;\n\n        if (first->priority >\
    \ second->priority) {\n            first->right = merge(first->right, second);\n\
    \            return update(first);\n        } else {\n            second->left\
    \ = merge(first, second->left);\n            return update(second);\n        }\n\
    \    }\n\n    static void split(Node* tree, T key, Node*& less, Node*& more) {\n\
    \        if (!tree) { less = more = nullptr; return; }\n\n        if (tree->key\
    \ < key) {\n            split(tree->right, key, tree->right, more);\n        \
    \    less = update(tree);\n        } else {\n            split(tree->left, key,\
    \ less, tree->left);\n            more = update(tree);\n        }\n    }\n\n \
    \   bool insert(const T key) {\n        if (contains(key)) return false;\n   \
    \     Node *less, *more;\n        split(root, key, less, more);\n        root\
    \ = merge(merge(less, new Node(key, mt())), more);\n        return true;\n   \
    \ }\n\n    bool erase(const T key) {\n        if (!contains(key)) return false;\n\
    \        Node *less, *mid, *more;\n        split(root, key, less, mid);\n    \
    \    split(mid, key + 1, mid, more);\n        clear(mid);\n        root = merge(less,\
    \ more);\n        return true;\n    }\n\n    /// @brief Treap \u3092\u7A7A\u306B\
    \u3059\u308B.\n    void clear() { clear(root); root = nullptr; }\n\n    /// @brief\
    \ \u30AD\u30FC\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\
    \u308B.\n    bool contains(const T key) const {\n        Node* cur = root;\n \
    \       while (cur) {\n            if (cur->key == key) return true;\n       \
    \     cur = (key < cur->key) ? cur->left : cur->right;\n        }\n        return\
    \ false;\n    }\n\n    /// @brief x \u3088\u308A\u5927\u304D\u3044\uFF08\u307E\
    \u305F\u306F\u4EE5\u4E0A\uFF09\u30AD\u30FC\u306E\u3046\u3061\u6700\u5C0F\u306E\
    \u3082\u306E\u3092\u6C42\u3081\u308B.\n    std::optional<T> next(const T x, bool\
    \ equal = false) const {\n        const Node *res = next_inner(x, equal);\n  \
    \      return res ? std::make_optional(res->key) : std::nullopt;\n    }\n\n  \
    \  /// @brief x \u672A\u6E80\uFF08\u307E\u305F\u306F\u4EE5\u4E0B\uFF09\u306E\u30AD\
    \u30FC\u306E\u3046\u3061\u6700\u5927\u306E\u3082\u306E\u3092\u6C42\u3081\u308B\
    .\n    std::optional<T> previous(const T x, bool equal = false) const {\n    \
    \    const Node *res = previous_inner(x, equal);\n        return res ? std::make_optional(res->key)\
    \ : std::nullopt;\n    }\n\n    /// @brief x \u672A\u6E80\u306E\u5143\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B.\n    int count_less(const T x, bool equal = false)\
    \ const {\n        Node* cur = root;\n        int res = 0;\n        while (cur)\
    \ {\n            bool condition = equal ? (cur->key <= x) : (cur->key < x);\n\
    \            if (condition) {\n                res += get_size(cur->left) + 1;\n\
    \                cur = cur->right;\n            } else {\n                cur\
    \ = cur->left;\n            }\n        }\n        return res;\n    }\n\n    ///\
    \ @brief x \u3088\u308A\u5927\u304D\u3044\u5143\u306E\u500B\u6570\u3092\u6C42\u3081\
    \u308B.\n    int count_more(const T x, bool equal = false) const {\n        return\
    \ size() - count_less(x, !equal);\n    }\n\n    /// @brief l \u4EE5\u4E0A r \u672A\
    \u6E80\u306E\u5143\u306E\u6570\u3092\u6C42\u3081\u308B.\n    int count_range(const\
    \ T l, const T r, bool l_equal = true, bool r_equal = false) const {\n       \
    \ if (l > r || (l == r && (!l_equal || !r_equal))) return 0;\n        int upper\
    \ = count_less(r, r_equal);\n        int lower = count_less(l, !l_equal);\n  \
    \      return std::max(0, upper - lower);\n    }\n\n    /// @brief k \u756A\u76EE\
    \ (0-indexed) \u306E\u30AD\u30FC\u3092\u53D6\u5F97\u3059\u308B.\n    T kth(int\
    \ k) const {\n        if (k < 0) k += size();\n        if (k < 0 || k >= (int)size())\
    \ throw std::out_of_range(\"Treap::kth : Index out of range.\");\n\n        Node*\
    \ node = root;\n        loop {\n            int left_size = get_size(node->left);\n\
    \            if (k < left_size) {\n                node = node->left;\n      \
    \      } else if (k == left_size) {\n                break;\n            } else\
    \ {\n                k -= left_size + 1;\n                node = node->right;\n\
    \            }\n        }\n        return node->key;\n    }\n\n    std::optional<T>\
    \ safe_kth(int k) const {\n        if (k < 0) k += size();\n        if (k < 0\
    \ || k >= (int)size()) return std::nullopt;\n        return kth(k);\n    }\n\n\
    \    T operator[](int k) { return kth(k); }\n    T operator[](int k) const { return\
    \ kth(k); }\n\n    T kth_min(int k) const { return kth(k); }\n    T kth_max(int\
    \ k) const { return kth(-(k + 1)); }\n\n    T min() const { return kth(0); }\n\
    \    T max() const { return kth(-1); }\n\n    T pop_min() {\n        T res = min();\n\
    \        erase(res);\n        return res;\n    }\n\n    T pop_max() {\n      \
    \  T res = max();\n        erase(res);\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<typename\
    \ T>\nclass Treap {\n    struct Node {\n        T key;\n        int priority;\n\
    \        int size;\n        Node *left = nullptr, *right = nullptr;\n        Node(T\
    \ key, int priority) : key(key), priority(priority), size(1) {}\n    };\n\n  \
    \  Node *root = nullptr;\n    std::mt19937 mt;\n\n    static int get_size(Node*\
    \ node) { return node ? node->size : 0; }\n\n    static Node* update(Node* node)\
    \ {\n        if (node) node->size = 1 + get_size(node->left) + get_size(node->right);\n\
    \        return node;\n    }\n\n    void clear(Node* node) {\n        if (!node)\
    \ return;\n        clear(node->left);\n        clear(node->right);\n        delete\
    \ node;\n    }\n\n    const Node* next_inner(const T &key, bool equal) const {\n\
    \        const Node *res = nullptr;\n        const Node *cur = root;\n       \
    \ while (cur) {\n            bool condition = equal ? (key <= cur->key) : (key\
    \ < cur->key);\n            if (condition) {\n                res = cur;\n   \
    \             cur = cur->left;\n            } else {\n                cur = cur->right;\n\
    \            }\n        }\n        return res;\n    }\n\n    const Node* previous_inner(const\
    \ T &key, bool equal) const {\n        const Node *res = nullptr;\n        const\
    \ Node *cur = root;\n        while (cur) {\n            bool condition = equal\
    \ ? (key >= cur->key) : (key > cur->key);\n            if (condition) {\n    \
    \            res = cur;\n                cur = cur->right;\n            } else\
    \ {\n                cur = cur->left;\n            }\n        }\n        return\
    \ res;\n    }\n\n    public:\n    Treap(): mt(std::random_device{}()) {}\n\n \
    \   Treap(std::initializer_list<T> init_list) : Treap() {\n        for (const\
    \ auto& x : init_list) insert(x);\n    }\n\n    template<class Iterator>\n   \
    \ Treap(Iterator first, Iterator last) : Treap() {\n        for (auto it = first;\
    \ it != last; ++it) insert(*it);\n    }\n\n    template<class Container>\n   \
    \ Treap(const Container& container) : Treap() {\n        for (const auto& x :\
    \ container) insert(x);\n    }\n\n    ~Treap() { clear(root); }\n\n    size_t\
    \ size() const { return get_size(root); }\n\n    bool empty() const { return size()\
    \ == 0; }\n\n    static Node* merge(Node* first, Node* second) {\n        if (!first\
    \ || !second) return first ? first : second;\n\n        if (first->priority >\
    \ second->priority) {\n            first->right = merge(first->right, second);\n\
    \            return update(first);\n        } else {\n            second->left\
    \ = merge(first, second->left);\n            return update(second);\n        }\n\
    \    }\n\n    static void split(Node* tree, T key, Node*& less, Node*& more) {\n\
    \        if (!tree) { less = more = nullptr; return; }\n\n        if (tree->key\
    \ < key) {\n            split(tree->right, key, tree->right, more);\n        \
    \    less = update(tree);\n        } else {\n            split(tree->left, key,\
    \ less, tree->left);\n            more = update(tree);\n        }\n    }\n\n \
    \   bool insert(const T key) {\n        if (contains(key)) return false;\n   \
    \     Node *less, *more;\n        split(root, key, less, more);\n        root\
    \ = merge(merge(less, new Node(key, mt())), more);\n        return true;\n   \
    \ }\n\n    bool erase(const T key) {\n        if (!contains(key)) return false;\n\
    \        Node *less, *mid, *more;\n        split(root, key, less, mid);\n    \
    \    split(mid, key + 1, mid, more);\n        clear(mid);\n        root = merge(less,\
    \ more);\n        return true;\n    }\n\n    /// @brief Treap \u3092\u7A7A\u306B\
    \u3059\u308B.\n    void clear() { clear(root); root = nullptr; }\n\n    /// @brief\
    \ \u30AD\u30FC\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\
    \u308B.\n    bool contains(const T key) const {\n        Node* cur = root;\n \
    \       while (cur) {\n            if (cur->key == key) return true;\n       \
    \     cur = (key < cur->key) ? cur->left : cur->right;\n        }\n        return\
    \ false;\n    }\n\n    /// @brief x \u3088\u308A\u5927\u304D\u3044\uFF08\u307E\
    \u305F\u306F\u4EE5\u4E0A\uFF09\u30AD\u30FC\u306E\u3046\u3061\u6700\u5C0F\u306E\
    \u3082\u306E\u3092\u6C42\u3081\u308B.\n    std::optional<T> next(const T x, bool\
    \ equal = false) const {\n        const Node *res = next_inner(x, equal);\n  \
    \      return res ? std::make_optional(res->key) : std::nullopt;\n    }\n\n  \
    \  /// @brief x \u672A\u6E80\uFF08\u307E\u305F\u306F\u4EE5\u4E0B\uFF09\u306E\u30AD\
    \u30FC\u306E\u3046\u3061\u6700\u5927\u306E\u3082\u306E\u3092\u6C42\u3081\u308B\
    .\n    std::optional<T> previous(const T x, bool equal = false) const {\n    \
    \    const Node *res = previous_inner(x, equal);\n        return res ? std::make_optional(res->key)\
    \ : std::nullopt;\n    }\n\n    /// @brief x \u672A\u6E80\u306E\u5143\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B.\n    int count_less(const T x, bool equal = false)\
    \ const {\n        Node* cur = root;\n        int res = 0;\n        while (cur)\
    \ {\n            bool condition = equal ? (cur->key <= x) : (cur->key < x);\n\
    \            if (condition) {\n                res += get_size(cur->left) + 1;\n\
    \                cur = cur->right;\n            } else {\n                cur\
    \ = cur->left;\n            }\n        }\n        return res;\n    }\n\n    ///\
    \ @brief x \u3088\u308A\u5927\u304D\u3044\u5143\u306E\u500B\u6570\u3092\u6C42\u3081\
    \u308B.\n    int count_more(const T x, bool equal = false) const {\n        return\
    \ size() - count_less(x, !equal);\n    }\n\n    /// @brief l \u4EE5\u4E0A r \u672A\
    \u6E80\u306E\u5143\u306E\u6570\u3092\u6C42\u3081\u308B.\n    int count_range(const\
    \ T l, const T r, bool l_equal = true, bool r_equal = false) const {\n       \
    \ if (l > r || (l == r && (!l_equal || !r_equal))) return 0;\n        int upper\
    \ = count_less(r, r_equal);\n        int lower = count_less(l, !l_equal);\n  \
    \      return std::max(0, upper - lower);\n    }\n\n    /// @brief k \u756A\u76EE\
    \ (0-indexed) \u306E\u30AD\u30FC\u3092\u53D6\u5F97\u3059\u308B.\n    T kth(int\
    \ k) const {\n        if (k < 0) k += size();\n        if (k < 0 || k >= (int)size())\
    \ throw std::out_of_range(\"Treap::kth : Index out of range.\");\n\n        Node*\
    \ node = root;\n        loop {\n            int left_size = get_size(node->left);\n\
    \            if (k < left_size) {\n                node = node->left;\n      \
    \      } else if (k == left_size) {\n                break;\n            } else\
    \ {\n                k -= left_size + 1;\n                node = node->right;\n\
    \            }\n        }\n        return node->key;\n    }\n\n    std::optional<T>\
    \ safe_kth(int k) const {\n        if (k < 0) k += size();\n        if (k < 0\
    \ || k >= (int)size()) return std::nullopt;\n        return kth(k);\n    }\n\n\
    \    T operator[](int k) { return kth(k); }\n    T operator[](int k) const { return\
    \ kth(k); }\n\n    T kth_min(int k) const { return kth(k); }\n    T kth_max(int\
    \ k) const { return kth(-(k + 1)); }\n\n    T min() const { return kth(0); }\n\
    \    T max() const { return kth(-1); }\n\n    T pop_min() {\n        T res = min();\n\
    \        erase(res);\n        return res;\n    }\n\n    T pop_max() {\n      \
    \  T res = max();\n        erase(res);\n        return res;\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Data_Structure/Treap.hpp
  requiredBy: []
  timestamp: '2026-07-19 19:06:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Ordered_Set_3.test.cpp
documentation_of: Data_Structure/Treap.hpp
layout: document
title: Treap
---

## Outline
平衡二分探索木の $1$ つである Treap (Tree + Heap) を用いた順序付き集合.

各ノードにランダムな優先度 (priority) を割り当て, キーに関しては二分探索木, 優先度に関してはヒープの性質を同時に満たすことで, 期待 $O(\log N)$ の高さを保つ. `split` / `merge` による分割統合型の実装を採用している.

通常の `std::set` の機能に加え, 「小さい方から $k$ 番目の要素の取得」や「ある値未満の要素数」といった順位に関する操作を期待 $O(\log N)$ で行うことができる.

## Theory

### 定義

Treap とは, 各ノードが **キー (key)** と **優先度 (priority)** の2つの値を持つ二分木であり, 以下の2つの性質を同時に満たすものである.

1. **二分探索木性質 (BST property)**: キーについて, 通常の二分探索木の順序関係を満たす. すなわち, 任意のノード $v$ に対して, $v$ の左部分木のすべてのキーは $v$ のキーより小さく, 右部分木のすべてのキーは $v$ のキーより大きい.
2. **ヒープ性質 (Heap property)**: 優先度について, (最大) ヒープの順序関係を満たす. すなわち, 任意のノード $v$ に対して, $v$ の優先度はその子ノードの優先度以上である.

キーが相異なり, 優先度も相異なるとき, これら2つの性質を同時に満たす木の形状は**一意**に定まる. これは, 最も優先度の高いノードが根となり, そのキーを基準にキーが小さいものが左部分木, 大きいものが右部分木を再帰的に構成することから従う.

### ランダム化と期待計算量

Treap では, 各ノードの優先度を**一様ランダム**に生成する. このとき, Treap の構造は「キーをランダムな順序で挿入して構築した二分探索木」と分布が等しくなることが知られている. ランダムな順序で $N$ 個の要素を挿入して構築した二分探索木の期待高さは $O(\log N)$ であるため, Treap の期待高さも $O(\log N)$ となる.

より正確には, ノード $x$ の深さの期待値は $O(\log N)$ であり, 任意の探索・挿入・削除操作の期待計算量は $O(\log N)$ となる.

### split 操作

$\mathrm{split}(T, k)$ は, 木 $T$ をキー $k$ を基準にして, キーが $k$ 未満のノードからなる木 $L$ とキーが $k$ 以上のノードからなる木 $R$ に分割する操作である.

根のキーと $k$ の大小を比較して再帰的に分割を行う.

* 根のキーが $k$ 未満のとき: 根と左部分木はすべて $L$ に属する. 右部分木を再帰的に分割し, 得られた「$k$ 未満の部分」を根の右の子として接続したものが $L$, 残りが $R$ となる.
* 根のキーが $k$ 以上のとき: 根と右部分木はすべて $R$ に属する. 左部分木を再帰的に分割し, 得られた「$k$ 以上の部分」を根の左の子として接続したものが $R$, 残りが $L$ となる.

再帰の深さは木の高さに等しいため, **期待計算量は $O(\log N)$** である.

### merge 操作

$\mathrm{merge}(L, R)$ は, $L$ のすべてのキーが $R$ のすべてのキーより小さいという前提のもとで, 2つの木 $L, R$ を1つの Treap に統合する操作である.

両方の根の優先度を比較し, 優先度が高い方を統合後の根とする.

* $L$ の根の優先度が高いとき: $L$ の根が統合後の根となる. $L$ の右部分木と $R$ を再帰的にマージし, その結果を $L$ の根の右の子とする.
* $R$ の根の優先度が高いとき: $R$ の根が統合後の根となる. $L$ と $R$ の左部分木を再帰的にマージし, その結果を $R$ の根の左の子とする.

この操作は, 統合後の木がヒープ性質を維持することを保証する. **期待計算量は $O(\log N)$** である.

### insert / erase の実現

split と merge を組み合わせることで, 挿入と削除を簡潔に実現できる.

* **insert($x$)**: 木を $x$ を基準に split し, 新たなノード $x$ を単独の木として, $L$, $\\{x\\}$, $R$ の順に merge する.
* **erase($x$)**: 木を $x$ と $x+1$ でそれぞれ split して $x$ のみを含む部分木 $M$ を切り出し, $M$ を破棄した後, 残りの $L$ と $R$ を merge する.

## Contents

### Constructer

```cpp
template<class T>
Treap()

template<class T>
Treap(std::initializer_list<T> init_list)

template<class T>
Treap(Iterator first, Iterator last)

template<class T>
Treap(const Container& container)
```

* 順序付き集合を生成する.

### insert

```cpp
bool insert(const T key)
```

* $x$ を挿入する. 集合であるため, すでに同じ値が存在する場合は何もしない.
* **返り値**
  * 集合に変化があったら `true`, なければ `false`.
* **計算量**: 期待 $O(\log N)$ 時間

### erase

```cpp
bool erase(const T key)
```

* $x$ を削除する.
* **返り値**
  * 要素が削除されたら `true`, 存在しなかったら `false`.
* **計算量**: 期待 $O(\log N)$ 時間

### contains

```cpp
bool contains(const T key) const
```

* $x$ が集合に含まれているか判定する.
* **計算量**: 期待 $O(\log N)$ 時間

### size / empty / clear

```cpp
size_t size() const
bool empty() const
void clear()
```

* 集合の要素数取得, 空判定, 全要素の削除を行う.

### count_less / count_more / count_range

```cpp
int count_less(const T x, bool equal = false) const
int count_more(const T x, bool equal = false) const
int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const
```

* 指定された条件を満たす要素の数を数える.
* **引数**
  * `x`: 基準となる値.
  * `l`, `r`: 範囲の左端および右端.
  * `equal`: 境界値 `x` を含めるかどうか.
  * `l_equal`: 左端 `l` を含めるかどうか.
  * `r_equal`: 右端 `r` を含めるかどうか.
* `count_less`: `equal` が `false` なら $x$ 未満, `true` なら $x$ 以下の個数.
* `count_more`: `equal` が `false` なら $x$ より大きい, `true` なら $x$ 以上の個数.
* `count_range`: 範囲内の要素数.デフォルトでは左閉右開 $[l, r)$.
* **計算量**: 期待 $O(\log N)$ 時間

### kth / safe_kth / operator[]

```cpp
T kth(int k) const
std::optional<T> safe_kth(int k) const
T operator[](int k) const
```

* $k$ 番目に小さい要素を取得する (0-indexed).
* $k < 0$ の場合, 末尾からの位置として扱われる（$-1$ は最大値）.
* `safe_kth` はインデックスが範囲外の場合に `std::nullopt` を返す.
* `kth` はインデックスが範囲外の場合に `std::out_of_range` 例外を送出する.
* **計算量**: 期待 $O(\log N)$ 時間

### kth_min / kth_max

```cpp
T kth_min(int k) const
T kth_max(int k) const
```

* `kth_min(k)`: $k$ 番目に小さい要素を取得する.`kth(k)` と同等.
* **引数**
  * `k`: 順位 (0-indexed).
* `kth_max(k)`: $k$ 番目に大きい要素を取得する.
* **計算量**: 期待 $O(\log N)$ 時間

### min / max

```cpp
T min() const
T max() const
```

* 最小値, および最大値を取得する.
* **計算量**: 期待 $O(\log N)$ 時間

### pop_min / pop_max

```cpp
T pop_min()
T pop_max()
```

* `pop_min()`: 最小値を取得し, その要素を集合から削除する.
* `pop_max()`: 最大値を取得し, その要素を集合から削除する.
* **制約**
  * 集合は空であってはならない.
* **計算量**: 期待 $O(\log N)$ 時間

### next / previous

```cpp
std::optional<T> next(const T x, bool equal = false) const
std::optional<T> previous(const T x, bool equal = false) const
```

* `next`: $x$ の次にある要素を取得する. `equal` が `true` なら $x$ 以上, `false` なら $x$ より大きい最小の要素.
* `previous`: $x$ の前にある要素を取得する. `equal` が `true` なら $x$ 以下, `false` なら $x$ 未満の最大の要素.
* 該当する要素がない場合は `std::nullopt` を返す.
* **引数**
  * `x`: 基準となる値.
  * `equal`: 境界値 `x` を探索対象に含めるかどうか.
* **計算量**: 期待 $O(\log N)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/07/19| Treap 実装 |
