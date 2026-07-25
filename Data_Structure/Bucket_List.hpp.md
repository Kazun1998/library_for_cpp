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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7B2C k \u8981\u7D20\u3068\u306A\u308B\u4F4D\u7F6E\u306B a \u3092\
      \u633F\u5165\u3059\u308B"
    links:
    - https://github.com/tatyam-prime/SortedSet/blob/main/BucketList.py
  bundledCode: "#line 2 \"Data_Structure/Bucket_List.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \    }\n};\n#line 4 \"Data_Structure/Bucket_List.hpp\"\n\n// Thanks to: https://github.com/tatyam-prime/SortedSet/blob/main/BucketList.py\n\
    \ntemplate<typename T>\nclass Bucket_List {\n    using Bucket = vector<T>;\n\n\
    \    template<bool IsConst>\n    class Iterator {\n        using BucketsIt = conditional_t<IsConst,\
    \ typename vector<Bucket>::const_iterator, typename vector<Bucket>::iterator>;\n\
    \        using ElemIt = conditional_t<IsConst, typename Bucket::const_iterator,\
    \ typename Bucket::iterator>;\n\n        BucketsIt bkt, bkt_end;\n        ElemIt\
    \ elem;\n\n        void skip_empty() {\n            while (bkt != bkt_end && elem\
    \ == bkt->end()) {\n                ++bkt;\n                if (bkt != bkt_end)\
    \ elem = bkt->begin();\n            }\n        }\n\n        public:\n        Iterator(BucketsIt\
    \ bkt_, BucketsIt bkt_end_): bkt(bkt_), bkt_end(bkt_end_) {\n            if (bkt\
    \ != bkt_end) elem = bkt->begin();\n            skip_empty();\n        }\n\n \
    \       conditional_t<IsConst, const T&, T&> operator*() const { return *elem;\
    \ }\n\n        Iterator& operator++() {\n            ++elem;\n            skip_empty();\n\
    \            return *this;\n        }\n\n        bool operator!=(const Iterator\
    \ &other) const {\n            if (bkt != other.bkt) return true;\n          \
    \  return bkt != bkt_end && elem != other.elem;\n        }\n\n        bool operator==(const\
    \ Iterator &other) const { return !(*this != other); }\n    };\n\n    public:\n\
    \    using iterator = Iterator<false>;\n    using const_iterator = Iterator<true>;\n\
    \n    iterator begin() { return iterator(buckets.begin(), buckets.end()); }\n\
    \    iterator end() { return iterator(buckets.end(), buckets.end()); }\n\n   \
    \ const_iterator begin() const { return const_iterator(buckets.begin(), buckets.end());\
    \ }\n    const_iterator end() const { return const_iterator(buckets.end(), buckets.end());\
    \ }\n\n    private:\n    static constexpr double BUCKET_RATIO = 16.0;\n    static\
    \ constexpr double SPLIT_RATIO = 24.0;\n\n    int _size;\n    vector<Bucket> buckets;\n\
    \n    tuple<const Bucket&, int, int> position(int k) const {\n        if (k <\
    \ 0 || k >= size()) {\n            throw out_of_range(\"Bucket_List::position\"\
    );\n        }\n\n        if (k < size() - k) {\n            for (int i = 0; i\
    \ < (int)buckets.size(); ++i) {\n                const Bucket &bucket = buckets[i];\n\
    \n                if (k < (int)bucket.size()) {\n                    return {bucket,\
    \ i, k};\n                }\n\n                k -= bucket.size();\n         \
    \   }\n        } else {\n            k = size() - k - 1;\n\n            for (int\
    \ i = (int)buckets.size() - 1; i >= 0; --i) {\n                const Bucket &bucket\
    \ = buckets[i];\n\n                if (k < (int)bucket.size()) {\n           \
    \         return {bucket, i, (int)bucket.size() - 1 - k};\n                }\n\
    \n                k -= bucket.size();\n            }\n        }\n\n        throw\
    \ out_of_range(\"Bucket_List::position\");\n    }\n\n    tuple<Bucket&, int, int>\
    \ position(int k) {\n        auto [bucket, i, j] = const_cast<const Bucket_List*>(this)->position(k);\n\
    \        return {const_cast<Bucket&>(bucket), i, j};\n    }\n\n    Bucket& locate(int\
    \ k, int &bucket_index, int &index) {\n        auto pos = position(k);\n     \
    \   tie(ignore, bucket_index, index) = pos;\n\n        return get<0>(pos);\n \
    \   }\n\n    void _insert(Bucket &bucket, int bucket_index, int index, T a) {\n\
    \        bucket.insert(bucket.begin() + index, a);\n        _size++;\n\n     \
    \   if (bucket.size() > buckets.size() * SPLIT_RATIO) {\n            int mid =\
    \ bucket.size() >> 1;\n\n            Bucket left(bucket.begin(), bucket.begin()\
    \ + mid);\n            Bucket right(bucket.begin() + mid, bucket.end());\n\n \
    \           buckets[bucket_index] = std::move(left);\n            buckets.insert(buckets.begin()\
    \ + bucket_index + 1, std::move(right));\n        }\n    }\n\n    T _pop(Bucket\
    \ &bucket, int bucket_index, int index) {\n        T val = bucket[index];\n  \
    \      bucket.erase(bucket.begin() + index);\n        _size--;\n\n        if (bucket.empty())\
    \ {\n            buckets.erase(buckets.begin() + bucket_index);\n        }\n\n\
    \        if ((int)buckets.size() > 2 * ideal_bucket_count()) {\n            rebuild();\n\
    \        }\n\n        return val;\n    }\n\n    void make_first(const T a) {\n\
    \        buckets = {{a}};\n        _size = 1;\n    }\n\n    int ideal_bucket_count()\
    \ const {\n        if (_size == 0) return 0;\n        return max(1, (int)ceil(sqrt(_size\
    \ / BUCKET_RATIO)));\n    }\n\n    void rebuild() {\n        vector<T> data;\n\
    \        data.reserve(_size);\n        for (const Bucket &bucket : buckets) {\n\
    \            data.insert(data.end(), bucket.begin(), bucket.end());\n        }\n\
    \n        int n = data.size();\n        int num_bucket = ideal_bucket_count();\n\
    \n        buckets.assign(num_bucket, Bucket());\n        for (int i = 0; i < num_bucket;\
    \ i++) {\n            int l = (long long)n * i / num_bucket;\n            int\
    \ r = (long long)n * (i + 1) / num_bucket;\n\n            buckets[i] = Bucket(data.begin()\
    \ + l, data.begin() + r);\n        }\n    }\n\n    public:\n    Bucket_List():\
    \ Bucket_List(vector<T>{}) {}\n\n    Bucket_List(const vector<T> &data) {\n  \
    \      _size = data.size();\n        buckets = {Bucket(data.begin(), data.end())};\n\
    \n        rebuild();\n    }\n\n    /// @brief \u7B2C k \u8981\u7D20\u3068\u306A\
    \u308B\u4F4D\u7F6E\u306B a \u3092\u633F\u5165\u3059\u308B\n    /// @param k \u633F\
    \u5165\u3059\u308B\u5834\u6240\n    /// @param a \u633F\u5165\u3059\u308B\u8981\
    \u7D20\n    void insert(int k, const T a) {\n        if (empty()) {\n        \
    \    if (k != 0) {\n                throw out_of_range(\"Bucket_List::insert\"\
    );\n            }\n\n            return make_first(a);\n        }\n\n        if\
    \ (k < 0) k += size();\n\n        if (k == size()) return append(a);\n\n     \
    \   int i, j;\n        Bucket &bucket = locate(k, i, j);\n\n        _insert(bucket,\
    \ i, j, a);\n    }\n\n    /// @brief \u672B\u5C3E\u306B a \u3092\u8FFD\u52A0\u3059\
    \u308B\n    /// @param a \u8FFD\u52A0\u3059\u308B\u8981\u7D20\n    void append(const\
    \ T a) {\n        if (empty()) return make_first(a);\n\n        auto &bucket =\
    \ buckets.back();\n        _insert(bucket, buckets.size() - 1, bucket.size(),\
    \ a);\n    }\n\n    /// @brief \u672B\u5C3E\u306B a \u3092\u8FFD\u52A0\u3059\u308B\
    \ (append \u306E\u5225\u540D)\n    /// @param a \u8FFD\u52A0\u3059\u308B\u8981\
    \u7D20\n    void push_back(const T a) { append(a); }\n\n    /// @brief \u5148\u982D\
    \u306B a \u3092\u8FFD\u52A0\u3059\u308B\n    /// @param a \u8FFD\u52A0\u3059\u308B\
    \u8981\u7D20\n    void push_front(const T a) { insert(0, a); }\n\n    /// @brief\
    \ \u672B\u5C3E\u306B data \u306E\u8981\u7D20\u3092\u3059\u3079\u3066\u8FFD\u52A0\
    \u3059\u308B\n    /// @param data \u8FFD\u52A0\u3059\u308B\u8981\u7D20\u5217\n\
    \    void extend(const vector<T> &data) {\n        for (const T &a : data) {\n\
    \            append(a);\n        }\n    }\n\n    /// @brief \u7B2C k \u8981\u7D20\
    \u3092\u524A\u9664\u3057\u3001\u305D\u306E\u5024\u3092\u8FD4\u3059\n    /// @param\
    \ k \u524A\u9664\u3059\u308B\u5834\u6240 (\u8CA0\u306E\u5834\u5408\u306F\u672B\
    \u5C3E\u304B\u3089\u6570\u3048\u308B\u3002\u7701\u7565\u6642\u306F\u672B\u5C3E\
    )\n    /// @return \u524A\u9664\u3055\u308C\u305F\u8981\u7D20\n    T pop(int k\
    \ = -1) {\n        if (k < 0) k += size();\n\n        int i, j;\n        Bucket\
    \ &bucket = locate(k, i, j);\n\n        return _pop(bucket, i, j);\n    }\n\n\
    \    /// @brief \u672B\u5C3E\u306E\u8981\u7D20\u3092\u524A\u9664\u3057\u3001\u305D\
    \u306E\u5024\u3092\u8FD4\u3059 (pop \u306E\u5225\u540D)\n    /// @return \u524A\
    \u9664\u3055\u308C\u305F\u8981\u7D20\n    T pop_back() { return pop(); }\n\n \
    \   /// @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3057\u3001\u305D\
    \u306E\u5024\u3092\u8FD4\u3059\n    /// @return \u524A\u9664\u3055\u308C\u305F\
    \u8981\u7D20\n    T pop_front() { return pop(0); }\n\n    T operator[](int k)\
    \ const {\n        if (k < 0) k += size();\n\n        auto [bucket, i, j] = position(k);\n\
    \        return bucket[j];\n    }\n\n    /// @brief \u5148\u982D\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u5148\u982D\u306E\u8981\u7D20\
    \n    T first() const {\n        if (empty()) throw out_of_range(\"Bucket_List::first\"\
    );\n\n        return buckets.front().front();\n    }\n\n    /// @brief \u672B\u5C3E\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u672B\u5C3E\
    \u306E\u8981\u7D20\n    T last() const {\n        if (empty()) throw out_of_range(\"\
    Bucket_List::last\");\n\n        return buckets.back().back();\n    }\n\n    ///\
    \ @brief a \u3068\u4E00\u81F4\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\u3092\u6570\
    \u3048\u308B\n    /// @param a \u6570\u3048\u308B\u5024\n    /// @return a \u3068\
    \u4E00\u81F4\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count(const T\
    \ a) const {\n        int res = 0;\n        for (const Bucket &bucket : buckets)\
    \ {\n            res += std::count(bucket.begin(), bucket.end(), a);\n       \
    \ }\n\n        return res;\n    }\n\n    /// @brief a \u304C\u542B\u307E\u308C\
    \u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n    /// @param a\
    \ \u63A2\u3059\u5024\n    /// @return \u542B\u307E\u308C\u308B\u306A\u3089\u3070\
    \ true\n    bool contains(const T a) const {\n        return count(a) > 0;\n \
    \   }\n\n    /// @brief a \u304C\u521D\u3081\u3066\u73FE\u308C\u308B\u8981\u7D20\
    \u30921\u3064\u524A\u9664\u3059\u308B\n    /// @param a \u524A\u9664\u3059\u308B\
    \u5024\n    /// @return \u524A\u9664\u3067\u304D\u305F\u3089 true\n    bool erase(const\
    \ T a) {\n        for (int i = 0; i < (int)buckets.size(); ++i) {\n          \
    \  Bucket &bucket = buckets[i];\n            auto it = std::find(bucket.begin(),\
    \ bucket.end(), a);\n\n            if (it == bucket.end()) continue;\n\n     \
    \       _pop(bucket, i, it - bucket.begin());\n            return true;\n    \
    \    }\n\n        return false;\n    }\n\n    /// @brief a \u304C\u521D\u3081\u3066\
    \u73FE\u308C\u308B\u4F4D\u7F6E\u3092\u6C42\u3081\u308B\n    /// @param a \u63A2\
    \u3059\u5024\n    /// @return a \u304C\u521D\u3081\u3066\u73FE\u308C\u308B\u4F4D\
    \u7F6E\n    int index(const T a) const {\n        int offset = 0;\n        for\
    \ (const Bucket &bucket : buckets) {\n            auto it = std::find(bucket.begin(),\
    \ bucket.end(), a);\n            if (it != bucket.end()) {\n                return\
    \ offset + (it - bucket.begin());\n            }\n\n            offset += bucket.size();\n\
    \        }\n\n        throw invalid_argument(\"Bucket_List::index\");\n    }\n\
    \n    /// @brief \u9577\u3055\u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u9577\
    \u3055\n    int size() const { return _size; }\n\n    /// @brief \u7A7A\u304B\u3069\
    \u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n    /// @return \u7A7A\u306A\u3089\
    \u3070 true\n    bool empty() const { return _size == 0; }\n\n    /// @brief \u3059\
    \u3079\u3066\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\n    void clear()\
    \ {\n        buckets.clear();\n        _size = 0;\n    }\n\n    /// @brief \u8981\
    \u7D20\u306E\u9806\u5E8F\u3092\u53CD\u8EE2\u3059\u308B\n    void reverse() {\n\
    \        std::reverse(buckets.begin(), buckets.end());\n        for (Bucket &bucket\
    \ : buckets) {\n            std::reverse(bucket.begin(), bucket.end());\n    \
    \    }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../template/template.hpp\"\n\n// Thanks to: https://github.com/tatyam-prime/SortedSet/blob/main/BucketList.py\n\
    \ntemplate<typename T>\nclass Bucket_List {\n    using Bucket = vector<T>;\n\n\
    \    template<bool IsConst>\n    class Iterator {\n        using BucketsIt = conditional_t<IsConst,\
    \ typename vector<Bucket>::const_iterator, typename vector<Bucket>::iterator>;\n\
    \        using ElemIt = conditional_t<IsConst, typename Bucket::const_iterator,\
    \ typename Bucket::iterator>;\n\n        BucketsIt bkt, bkt_end;\n        ElemIt\
    \ elem;\n\n        void skip_empty() {\n            while (bkt != bkt_end && elem\
    \ == bkt->end()) {\n                ++bkt;\n                if (bkt != bkt_end)\
    \ elem = bkt->begin();\n            }\n        }\n\n        public:\n        Iterator(BucketsIt\
    \ bkt_, BucketsIt bkt_end_): bkt(bkt_), bkt_end(bkt_end_) {\n            if (bkt\
    \ != bkt_end) elem = bkt->begin();\n            skip_empty();\n        }\n\n \
    \       conditional_t<IsConst, const T&, T&> operator*() const { return *elem;\
    \ }\n\n        Iterator& operator++() {\n            ++elem;\n            skip_empty();\n\
    \            return *this;\n        }\n\n        bool operator!=(const Iterator\
    \ &other) const {\n            if (bkt != other.bkt) return true;\n          \
    \  return bkt != bkt_end && elem != other.elem;\n        }\n\n        bool operator==(const\
    \ Iterator &other) const { return !(*this != other); }\n    };\n\n    public:\n\
    \    using iterator = Iterator<false>;\n    using const_iterator = Iterator<true>;\n\
    \n    iterator begin() { return iterator(buckets.begin(), buckets.end()); }\n\
    \    iterator end() { return iterator(buckets.end(), buckets.end()); }\n\n   \
    \ const_iterator begin() const { return const_iterator(buckets.begin(), buckets.end());\
    \ }\n    const_iterator end() const { return const_iterator(buckets.end(), buckets.end());\
    \ }\n\n    private:\n    static constexpr double BUCKET_RATIO = 16.0;\n    static\
    \ constexpr double SPLIT_RATIO = 24.0;\n\n    int _size;\n    vector<Bucket> buckets;\n\
    \n    tuple<const Bucket&, int, int> position(int k) const {\n        if (k <\
    \ 0 || k >= size()) {\n            throw out_of_range(\"Bucket_List::position\"\
    );\n        }\n\n        if (k < size() - k) {\n            for (int i = 0; i\
    \ < (int)buckets.size(); ++i) {\n                const Bucket &bucket = buckets[i];\n\
    \n                if (k < (int)bucket.size()) {\n                    return {bucket,\
    \ i, k};\n                }\n\n                k -= bucket.size();\n         \
    \   }\n        } else {\n            k = size() - k - 1;\n\n            for (int\
    \ i = (int)buckets.size() - 1; i >= 0; --i) {\n                const Bucket &bucket\
    \ = buckets[i];\n\n                if (k < (int)bucket.size()) {\n           \
    \         return {bucket, i, (int)bucket.size() - 1 - k};\n                }\n\
    \n                k -= bucket.size();\n            }\n        }\n\n        throw\
    \ out_of_range(\"Bucket_List::position\");\n    }\n\n    tuple<Bucket&, int, int>\
    \ position(int k) {\n        auto [bucket, i, j] = const_cast<const Bucket_List*>(this)->position(k);\n\
    \        return {const_cast<Bucket&>(bucket), i, j};\n    }\n\n    Bucket& locate(int\
    \ k, int &bucket_index, int &index) {\n        auto pos = position(k);\n     \
    \   tie(ignore, bucket_index, index) = pos;\n\n        return get<0>(pos);\n \
    \   }\n\n    void _insert(Bucket &bucket, int bucket_index, int index, T a) {\n\
    \        bucket.insert(bucket.begin() + index, a);\n        _size++;\n\n     \
    \   if (bucket.size() > buckets.size() * SPLIT_RATIO) {\n            int mid =\
    \ bucket.size() >> 1;\n\n            Bucket left(bucket.begin(), bucket.begin()\
    \ + mid);\n            Bucket right(bucket.begin() + mid, bucket.end());\n\n \
    \           buckets[bucket_index] = std::move(left);\n            buckets.insert(buckets.begin()\
    \ + bucket_index + 1, std::move(right));\n        }\n    }\n\n    T _pop(Bucket\
    \ &bucket, int bucket_index, int index) {\n        T val = bucket[index];\n  \
    \      bucket.erase(bucket.begin() + index);\n        _size--;\n\n        if (bucket.empty())\
    \ {\n            buckets.erase(buckets.begin() + bucket_index);\n        }\n\n\
    \        if ((int)buckets.size() > 2 * ideal_bucket_count()) {\n            rebuild();\n\
    \        }\n\n        return val;\n    }\n\n    void make_first(const T a) {\n\
    \        buckets = {{a}};\n        _size = 1;\n    }\n\n    int ideal_bucket_count()\
    \ const {\n        if (_size == 0) return 0;\n        return max(1, (int)ceil(sqrt(_size\
    \ / BUCKET_RATIO)));\n    }\n\n    void rebuild() {\n        vector<T> data;\n\
    \        data.reserve(_size);\n        for (const Bucket &bucket : buckets) {\n\
    \            data.insert(data.end(), bucket.begin(), bucket.end());\n        }\n\
    \n        int n = data.size();\n        int num_bucket = ideal_bucket_count();\n\
    \n        buckets.assign(num_bucket, Bucket());\n        for (int i = 0; i < num_bucket;\
    \ i++) {\n            int l = (long long)n * i / num_bucket;\n            int\
    \ r = (long long)n * (i + 1) / num_bucket;\n\n            buckets[i] = Bucket(data.begin()\
    \ + l, data.begin() + r);\n        }\n    }\n\n    public:\n    Bucket_List():\
    \ Bucket_List(vector<T>{}) {}\n\n    Bucket_List(const vector<T> &data) {\n  \
    \      _size = data.size();\n        buckets = {Bucket(data.begin(), data.end())};\n\
    \n        rebuild();\n    }\n\n    /// @brief \u7B2C k \u8981\u7D20\u3068\u306A\
    \u308B\u4F4D\u7F6E\u306B a \u3092\u633F\u5165\u3059\u308B\n    /// @param k \u633F\
    \u5165\u3059\u308B\u5834\u6240\n    /// @param a \u633F\u5165\u3059\u308B\u8981\
    \u7D20\n    void insert(int k, const T a) {\n        if (empty()) {\n        \
    \    if (k != 0) {\n                throw out_of_range(\"Bucket_List::insert\"\
    );\n            }\n\n            return make_first(a);\n        }\n\n        if\
    \ (k < 0) k += size();\n\n        if (k == size()) return append(a);\n\n     \
    \   int i, j;\n        Bucket &bucket = locate(k, i, j);\n\n        _insert(bucket,\
    \ i, j, a);\n    }\n\n    /// @brief \u672B\u5C3E\u306B a \u3092\u8FFD\u52A0\u3059\
    \u308B\n    /// @param a \u8FFD\u52A0\u3059\u308B\u8981\u7D20\n    void append(const\
    \ T a) {\n        if (empty()) return make_first(a);\n\n        auto &bucket =\
    \ buckets.back();\n        _insert(bucket, buckets.size() - 1, bucket.size(),\
    \ a);\n    }\n\n    /// @brief \u672B\u5C3E\u306B a \u3092\u8FFD\u52A0\u3059\u308B\
    \ (append \u306E\u5225\u540D)\n    /// @param a \u8FFD\u52A0\u3059\u308B\u8981\
    \u7D20\n    void push_back(const T a) { append(a); }\n\n    /// @brief \u5148\u982D\
    \u306B a \u3092\u8FFD\u52A0\u3059\u308B\n    /// @param a \u8FFD\u52A0\u3059\u308B\
    \u8981\u7D20\n    void push_front(const T a) { insert(0, a); }\n\n    /// @brief\
    \ \u672B\u5C3E\u306B data \u306E\u8981\u7D20\u3092\u3059\u3079\u3066\u8FFD\u52A0\
    \u3059\u308B\n    /// @param data \u8FFD\u52A0\u3059\u308B\u8981\u7D20\u5217\n\
    \    void extend(const vector<T> &data) {\n        for (const T &a : data) {\n\
    \            append(a);\n        }\n    }\n\n    /// @brief \u7B2C k \u8981\u7D20\
    \u3092\u524A\u9664\u3057\u3001\u305D\u306E\u5024\u3092\u8FD4\u3059\n    /// @param\
    \ k \u524A\u9664\u3059\u308B\u5834\u6240 (\u8CA0\u306E\u5834\u5408\u306F\u672B\
    \u5C3E\u304B\u3089\u6570\u3048\u308B\u3002\u7701\u7565\u6642\u306F\u672B\u5C3E\
    )\n    /// @return \u524A\u9664\u3055\u308C\u305F\u8981\u7D20\n    T pop(int k\
    \ = -1) {\n        if (k < 0) k += size();\n\n        int i, j;\n        Bucket\
    \ &bucket = locate(k, i, j);\n\n        return _pop(bucket, i, j);\n    }\n\n\
    \    /// @brief \u672B\u5C3E\u306E\u8981\u7D20\u3092\u524A\u9664\u3057\u3001\u305D\
    \u306E\u5024\u3092\u8FD4\u3059 (pop \u306E\u5225\u540D)\n    /// @return \u524A\
    \u9664\u3055\u308C\u305F\u8981\u7D20\n    T pop_back() { return pop(); }\n\n \
    \   /// @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3057\u3001\u305D\
    \u306E\u5024\u3092\u8FD4\u3059\n    /// @return \u524A\u9664\u3055\u308C\u305F\
    \u8981\u7D20\n    T pop_front() { return pop(0); }\n\n    T operator[](int k)\
    \ const {\n        if (k < 0) k += size();\n\n        auto [bucket, i, j] = position(k);\n\
    \        return bucket[j];\n    }\n\n    /// @brief \u5148\u982D\u306E\u8981\u7D20\
    \u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u5148\u982D\u306E\u8981\u7D20\
    \n    T first() const {\n        if (empty()) throw out_of_range(\"Bucket_List::first\"\
    );\n\n        return buckets.front().front();\n    }\n\n    /// @brief \u672B\u5C3E\
    \u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u672B\u5C3E\
    \u306E\u8981\u7D20\n    T last() const {\n        if (empty()) throw out_of_range(\"\
    Bucket_List::last\");\n\n        return buckets.back().back();\n    }\n\n    ///\
    \ @brief a \u3068\u4E00\u81F4\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\u3092\u6570\
    \u3048\u308B\n    /// @param a \u6570\u3048\u308B\u5024\n    /// @return a \u3068\
    \u4E00\u81F4\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n    int count(const T\
    \ a) const {\n        int res = 0;\n        for (const Bucket &bucket : buckets)\
    \ {\n            res += std::count(bucket.begin(), bucket.end(), a);\n       \
    \ }\n\n        return res;\n    }\n\n    /// @brief a \u304C\u542B\u307E\u308C\
    \u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n    /// @param a\
    \ \u63A2\u3059\u5024\n    /// @return \u542B\u307E\u308C\u308B\u306A\u3089\u3070\
    \ true\n    bool contains(const T a) const {\n        return count(a) > 0;\n \
    \   }\n\n    /// @brief a \u304C\u521D\u3081\u3066\u73FE\u308C\u308B\u8981\u7D20\
    \u30921\u3064\u524A\u9664\u3059\u308B\n    /// @param a \u524A\u9664\u3059\u308B\
    \u5024\n    /// @return \u524A\u9664\u3067\u304D\u305F\u3089 true\n    bool erase(const\
    \ T a) {\n        for (int i = 0; i < (int)buckets.size(); ++i) {\n          \
    \  Bucket &bucket = buckets[i];\n            auto it = std::find(bucket.begin(),\
    \ bucket.end(), a);\n\n            if (it == bucket.end()) continue;\n\n     \
    \       _pop(bucket, i, it - bucket.begin());\n            return true;\n    \
    \    }\n\n        return false;\n    }\n\n    /// @brief a \u304C\u521D\u3081\u3066\
    \u73FE\u308C\u308B\u4F4D\u7F6E\u3092\u6C42\u3081\u308B\n    /// @param a \u63A2\
    \u3059\u5024\n    /// @return a \u304C\u521D\u3081\u3066\u73FE\u308C\u308B\u4F4D\
    \u7F6E\n    int index(const T a) const {\n        int offset = 0;\n        for\
    \ (const Bucket &bucket : buckets) {\n            auto it = std::find(bucket.begin(),\
    \ bucket.end(), a);\n            if (it != bucket.end()) {\n                return\
    \ offset + (it - bucket.begin());\n            }\n\n            offset += bucket.size();\n\
    \        }\n\n        throw invalid_argument(\"Bucket_List::index\");\n    }\n\
    \n    /// @brief \u9577\u3055\u3092\u53D6\u5F97\u3059\u308B\n    /// @return \u9577\
    \u3055\n    int size() const { return _size; }\n\n    /// @brief \u7A7A\u304B\u3069\
    \u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\n    /// @return \u7A7A\u306A\u3089\
    \u3070 true\n    bool empty() const { return _size == 0; }\n\n    /// @brief \u3059\
    \u3079\u3066\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\n    void clear()\
    \ {\n        buckets.clear();\n        _size = 0;\n    }\n\n    /// @brief \u8981\
    \u7D20\u306E\u9806\u5E8F\u3092\u53CD\u8EE2\u3059\u308B\n    void reverse() {\n\
    \        std::reverse(buckets.begin(), buckets.end());\n        for (Bucket &bucket\
    \ : buckets) {\n            std::reverse(bucket.begin(), bucket.end());\n    \
    \    }\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Data_Structure/Bucket_List.hpp
  requiredBy: []
  timestamp: '2026-07-25 10:26:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/Bucket_List.hpp
layout: document
title: Bucket_List
---

## Outline
平方分割 (sqrt decomposition) による, 挿入・削除が高速な列 (順序付きの多重集合的なリスト).

列を要素数 $O(\sqrt N)$ 個の **バケット** に分割して保持し, 各バケットは通常の `std::vector` として実装される. 添字アクセス・挿入・削除はいずれも「対象の要素がどのバケットの何番目にあるか」を求めたのち, そのバケット内で `std::vector` の操作を行うことで実現する. バケット数を $O(\sqrt N)$ 程度に保つことで, 各操作が $O(\sqrt N)$ で行える.

`std::vector` の `insert` / `erase` は平均 $O(N)$ かかるのに対し, 本データ構造では要素数 $N$ に対して $O(\sqrt N)$ で任意位置への挿入・削除が可能になる.

## Theory

### バケットの分割数

長さ $n$ の列を, 定数 `BUCKET_RATIO` を用いて $\left\lceil \sqrt{n / \mathrm{BUCKET\_RATIO}} \right\rceil$ 個のバケットに (可能な限り均等に) 分割する. `BUCKET_RATIO` はバケット1個あたりの目標サイズを調整するための定数であり, 実装では $16$ に設定されている.

以降, バケット数を $B$, 各バケットの平均サイズを $O(N / B) = O(\sqrt N)$ に保つことで, 全体の計算量を管理する.

### 第 $k$ 要素の位置特定 (position)

第 $k$ 要素がどのバケットの何番目に属するかを求める操作. 先頭からバケットを順に見ていき, 累積サイズが $k$ を超えたバケットに絞り込む.

このとき, $k$ が列の**後半寄り**にある場合は末尾のバケットから逆順に辿った方が探索するバケット数が少なくて済む. そのため, $k$ と $N - 1 - k$ の小さい方を基準に, 先頭または末尾のどちらから走査するかを選択する. これにより, 探索するバケット数の期待値・最悪値がおよそ半分になる.

この操作自体はバケット数 $O(\sqrt N)$ 個を線形に走査するため $O(\sqrt N)$ である.

### 挿入とバケットの分割 (split)

第 $k$ 要素の位置に値を挿入する際は, 該当バケットに対して `std::vector::insert` を行う. これによりバケットのサイズが偏っていくため, 挿入後のバケットサイズが `バケット数 × SPLIT_RATIO` を超えた場合, そのバケットを半分に分割して2つのバケットにする (`SPLIT_RATIO` は実装では $24$).

これにより, 1つのバケットに要素が集中して $O(N)$ サイズまで肥大化することを防ぎ, 各バケットのサイズを $O(\sqrt N)$ 程度に保つ.

### 削除とバケットの再構築 (rebuild)

要素を削除して空になったバケットはその都度取り除く. さらに, 削除を繰り返すとバケット数 $B$ に対して総要素数 $N$ が減っていき, 理想的なバケット数 $B^* = O(\sqrt N)$ よりもバケット数が過剰になることがある.

そこで, バケット数が理想値 $B^*$ の $2$ 倍を超えた時点で, 全バケットを一列に展開し直し, 改めて $B^*$ 個のバケットに均等分割する「再構築 (rebuild)」を行う. これにより, 挿入・削除を繰り返してもバケット数が $O(\sqrt N)$ に保たれる.

再構築は $O(N)$ かかるが, これを引き起こすには $\Omega(B^*)$ 回の削除が必要であるため, ならし計算量には $O(\sqrt N)$ しか寄与しない.

### 計算量まとめ

要素数を $N$ として, `insert` / `erase` (削除) / `pop` / `operator[]` などの位置に関する操作はいずれも $O(\sqrt N)$ で行える.

## Contents

### Constructor

```cpp
template<class T>
Bucket_List()

template<class T>
Bucket_List(const vector<T> &data)
```

* 空の列, もしくは `data` の内容で初期化された列を生成する.
* **計算量**: $O(N)$ 時間 ($N$ は `data` のサイズ)

### insert

```cpp
void insert(int k, const T a)
```

* 第 $k$ 要素となる位置に `a` を挿入する.
* **引数**
  * `k`: 挿入する場所. 負の場合は末尾からの位置として扱われる. `k == size()` のときは末尾への追加 (`append`) として扱われる.
* **計算量**: $O(\sqrt N)$ 時間

### append / push_back / push_front

```cpp
void append(const T a)
void push_back(const T a)
void push_front(const T a)
```

* `append` / `push_back`: 末尾に `a` を追加する (両者は同じ操作).
* `push_front`: 先頭に `a` を追加する (`insert(0, a)` と同等).
* **計算量**: ならし $O(\sqrt N)$ 時間

### extend

```cpp
void extend(const vector<T> &data)
```

* 末尾に `data` の要素をすべて順に追加する.
* **計算量**: $O(M \sqrt N)$ 時間 ($M$ は `data` のサイズ)

### pop / pop_back / pop_front

```cpp
T pop(int k = -1)
T pop_back()
T pop_front()
```

* `pop`: 第 $k$ 要素を削除し, その値を返す.
* **引数**
  * `k`: 削除する場所. 負の場合は末尾からの位置として扱われる. 省略時は末尾の要素を削除する.
* `pop_back`: 末尾の要素を削除し, その値を返す (`pop()` と同等).
* `pop_front`: 先頭の要素を削除し, その値を返す (`pop(0)` と同等).
* **計算量**: ならし $O(\sqrt N)$ 時間

### operator[]

```cpp
T operator[](int k) const
```

* 第 $k$ 要素を取得する.
* **引数**
  * `k`: 取得する場所. 負の場合は末尾からの位置として扱われる.
* **計算量**: $O(\sqrt N)$ 時間

### first / last

```cpp
T first() const
T last() const
```

* 先頭 / 末尾の要素を取得する.
* **制約**
  * 列は空であってはならない (空の場合 `std::out_of_range` を送出する).
* **計算量**: $O(1)$ 時間

### count

```cpp
int count(const T a) const
```

* `a` と一致する要素の個数を数える.
* **計算量**: $O(N)$ 時間

### contains

```cpp
bool contains(const T a) const
```

* `a` が列に含まれるかどうかを判定する.
* **計算量**: $O(N)$ 時間

### erase

```cpp
bool erase(const T a)
```

* `a` が初めて現れる要素を1つ削除する.
* **返り値**
  * 削除できたら `true`, `a` が存在しなかったら `false`.
* **計算量**: $O(N)$ 時間

### index

```cpp
int index(const T a) const
```

* `a` が初めて現れる位置を返す.
* **制約**
  * `a` が列に含まれていなければならない (含まれない場合 `std::invalid_argument` を送出する).
* **計算量**: $O(N)$ 時間

### size / empty / clear

```cpp
int size() const
bool empty() const
void clear()
```

* 列の要素数取得, 空判定, 全要素の削除を行う.
* **計算量**: `size` / `empty` は $O(1)$ 時間, `clear` は $O(1)$ 時間

### reverse

```cpp
void reverse()
```

* 列の要素の順序を反転する.
* **計算量**: $O(N)$ 時間

### begin / end

```cpp
iterator begin()
iterator end()
const_iterator begin() const
const_iterator end() const
```

* 先頭 / 番兵の位置を指すイテレータを取得する. `for (auto x : bucket_list)` のような範囲 `for` 文で利用できる.
* **計算量**: `begin` は $O(1)$ 時間, 各要素への `++` はならし $O(1)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/07/25| Bucket_List 実装 |
