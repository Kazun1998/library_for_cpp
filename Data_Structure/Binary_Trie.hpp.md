---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/exception.hpp
    title: template/exception.hpp
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
  - icon: ':x:'
    path: verify/yosupo_library_checker/data_structure/Set_Xor-Min.test.cpp
    title: verify/yosupo_library_checker/data_structure/Set_Xor-Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "x \u3092\u633F\u5165\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Data_Structure/Binary_Trie.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ b)) \u3092\u6C42\u3081\u308B.\ntemplate<integral T>\ntuple<T, T, T> Extended_Euclid(T\
    \ a, T b) {\n    T s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        T q;\n\
    \        tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));\n    \
    \    tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u\
    \ - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n\
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
    \ get_bits(x, bit_length(x)); }\n#line 73 \"template/template.hpp\"\n\n// exception\n\
    #line 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n   \
    \ private:\n    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\
    \u3081\u3088\u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\
    \u3057\u307E\u305B\u3093.\") {}\n\n    const char* what() const noexcept override\
    \ {\n        return message.c_str();\n    }\n};\n#line 4 \"Data_Structure/Binary_Trie.hpp\"\
    \n\ntemplate<typename T>\nclass Binary_Trie {\n    struct Binary_Trie_Node {\n\
    \        int terminal = 0, subtree_size = 0;\n        Binary_Trie_Node *zero_child\
    \ = nullptr, *one_child = nullptr;\n\n        Binary_Trie_Node() = default;\n\
    \    };\n\n    int bit_size;\n    bool allow_multiple;\n    T _lazy_xor = 0, max_value;\n\
    \    Binary_Trie_Node *root;\n\n    Binary_Trie_Node* find_node(T x) {\n     \
    \   Binary_Trie_Node *node = root;\n        for (int k = bit_size - 1; k >= 0;\
    \ k--) {\n            node = get_bit(x, k) ? node->one_child : node->zero_child;\n\
    \            if (node == nullptr) { break; }\n        }\n\n        return node;\n\
    \    }\n\n    public:\n    Binary_Trie() = default;\n\n    Binary_Trie(const int\
    \ bit_size, bool allow_multiple = false):\n        bit_size(bit_size), allow_multiple(allow_multiple),\
    \ max_value(T(1) << bit_size) {\n            root = new Binary_Trie_Node();\n\
    \        }\n\n    inline T lazy_xor() const { return _lazy_xor; }\n    inline\
    \ void act_xor(T x) { _lazy_xor ^= x; }\n\n    // \u8981\u7D20\u306E\u8FFD\u52A0\
    \n\n    /// @brief x \u3092\u633F\u5165\u3059\u308B.\n    /// @param x \u633F\u5165\
    \u3059\u308B\u5024\n    /// @return Trie \u6728\u306B\u5909\u5316\u304C\u3042\u308C\
    \u3070 true, \u306A\u3051\u308C\u3070 false.\n    bool insert(T x) {\n       \
    \ Binary_Trie_Node *node = root;\n        vector<Binary_Trie_Node*> path(bit_size\
    \ + 1);\n        path[0] = root;\n\n        x ^= lazy_xor();\n\n        for (int\
    \ k = 0; k < bit_size; k++) {\n            bool bit = get_bit(x, bit_size - (k\
    \ + 1));\n            Binary_Trie_Node **child_ptr = bit ? &node->one_child :\
    \ &node->zero_child;\n\n            if (*child_ptr == nullptr) {\n           \
    \     *child_ptr = new Binary_Trie_Node();\n            }\n\n            node\
    \ = *child_ptr;\n            path[k + 1] = node;\n        }\n\n        if (node->terminal\
    \ > 0 && !allow_multiple) { return false; }\n        \n        node->terminal++;\n\
    \        for (auto node: path) {\n            node->subtree_size++;\n        }\n\
    \n        return true;\n    }\n\n    // \u8981\u7D20\u306E\u524A\u9664\n\n   \
    \ /// @brief `x` \u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u306B `x` \u3092 1\
    \ \u500B\u524A\u9664\u3059\u308B.\n    /// @param x \u524A\u9664\u3059\u308B\u8981\
    \u7D20\n    /// @return Trie \u6728\u306B\u5909\u5316\u304C\u3042\u308C\u3070\
    \ true, \u306A\u3051\u308C\u3070 false.\n    bool discard(T x) {\n        unless(0\
    \ <= x && x < max_value) { return 0; }\n\n        Binary_Trie_Node *node = root;\n\
    \n        vector<Binary_Trie_Node*> path(bit_size + 1);\n        path[0] = root;\n\
    \n        x ^= lazy_xor();\n\n        for (int d = 0; d < bit_size; d++) {\n \
    \           bool bit = get_bit(x, bit_size - (d + 1));\n\n            Binary_Trie_Node\
    \ **child_ptr = bit ? &node->one_child : &node->zero_child;\n\n            if\
    \ (*child_ptr == nullptr) { return false; }\n\n            node = *child_ptr;\n\
    \            path[d + 1] = node;\n        }\n\n        if (!node->terminal) {\
    \ return false; }\n\n        node->terminal--;\n        for (auto node: path)\
    \ { node->subtree_size--; }\n\n        return true;\n    }\n\n    /// @brief `x`\
    \ \u3092\u9AD8\u3005 `k` \u56DE\u524A\u9664\u3059\u308B.\n    /// @param x \u524A\
    \u9664\u3059\u308B\u8981\u7D20\n    /// @param k \u524A\u9664\u3059\u308B\u500B\
    \u6570 (k = -1 \u3068\u3059\u308B\u3068, \u7121\u9650\u56DE\u306B\u306A\u308B\
    )\n    /// @return `x` \u3092\u524A\u9664\u3057\u305F\u56DE\u6570\n    int erase(T\
    \ x, int k = -1) {\n        unless(0 <= x && x < max_value) { return 0; }\n  \
    \  \n        Binary_Trie_Node *node = root;\n\n        vector<Binary_Trie_Node*>\
    \ path(bit_size + 1);\n        path[0] = root;\n\n        x ^= lazy_xor();\n\n\
    \        for (int d = 0; d < bit_size; d++) {\n            bool bit = get_bit(x,\
    \ bit_size - (d + 1));\n\n            Binary_Trie_Node **child_ptr = bit ? &node->one_child\
    \ : &node->zero_child;\n\n            if (*child_ptr == nullptr) { return false;\
    \ }\n\n            node = *child_ptr;\n            path[d + 1] = node;\n     \
    \   }\n\n        if ((k == -1) || node->terminal < k) { \n            k = node->terminal;\n\
    \        }\n\n        node->terminal -= k;\n        for (auto node: path) { node->subtree_size\
    \ -= k; }\n\n        return k;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u6570\u3092\u6C42\u3081\
    \u308B.\n    inline int64_t size() const { return root->subtree_size; }\n\n  \
    \  inline explicit operator bool() const { return size() > 0; }\n\n    /// @brief\
    \ Binary Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B x \u306E\u6570\
    \u3092\u6C42\u3081\u308B.\n    /// @param x \u691C\u7D22\u5024\n    int count(T\
    \ x) {\n        unless (0 <= x && x < max_value) { return 0; }\n\n        x ^=\
    \ lazy_xor();\n\n        Binary_Trie_Node* node = find_node(x);\n        return\
    \ node != nullptr ? node->subtree_size : 0;\n    }\n\n    /// @brief Binary Trie\
    \ \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\
    \n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u672A\u6E80\
    \u300D\u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\u308B.\n    int less_count(T\
    \ x, bool equal = false) {\n        if (equal) { return less_count(x + 1, false);\
    \ }\n\n        if (x < 0) { return 0; }\n        if (x >= (T(1) << bit_size))\
    \ { return root->subtree_size;}\n\n        int res = 0;\n        Binary_Trie_Node\
    \ *node = root;\n\n        x ^= lazy_xor();\n\n        for (int k = bit_size -\
    \ 1; k >= 0; k--) {\n            Binary_Trie_Node *left = node->zero_child, *right\
    \ = node->one_child;\n            if (get_bit(lazy_xor(), k)) {\n            \
    \    swap(left, right);\n            }\n\n            if (get_bit(x, k)) {\n \
    \               if (left != nullptr) {\n                    res += left->subtree_size;\n\
    \                } else if (right != nullptr) {\n                    return res;\n\
    \                }\n\n                node = right;\n            } else {\n  \
    \              if (left == nullptr) {\n                    return res;\n     \
    \           }\n\n                node = left;\n            }\n        }\n\n  \
    \      return res;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\u4FDD\u5B58\
    \u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u306E\
    \u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\n    /// @param\
    \ equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u3088\u308A\u5927\u304D\u3044\
    \u300D\u304C\u300C`x` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n    inline int more_count(T\
    \ x, bool equal = false) const { return size() - less_count(x, !equal); }\n\n\
    \    /// @brief Binary Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `x` \u672A\u6E80\u3067\u6700\u5927\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\
    .\n    /// @param x \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\
    \u3068, \u300C`x` \u672A\u6E80\u300D\u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\
    \u308B.\n    T low_value(T x, bool equal = false) {\n        if (equal) { x++;\
    \ }\n\n        int alpha = less_count(x, false);\n\n        if (alpha == 0) {\
    \ throw out_of_range(\"No value found that is less than the limit \" + to_string(x)\
    \ + \".\"); }\n\n        return kth(alpha - 1);\n    }\n\n    /// @brief Binary\
    \ Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u672A\u6E80\
    \u3067\u6700\u5927\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \u95BE\u5024\n    /// @param default_value `x` \u672A\u6E80\u306E\u8981\u7D20\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n   \
    \ /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u672A\u6E80\u300D\
    \u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\u308B.\n    T low_value(T x, T\
    \ default_value, bool equal = false) const {\n        if (equal) { x++; }\n\n\
    \        int alpha = less_count(x, false);\n\n        return alpha > 0 ? kth(alpha\
    \ - 1) : default_value;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\u4FDD\
    \u5B58\u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\
    \u306E\u3046\u3061\u6700\u5C0F\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param x \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068\
    , \u300C`x` \u3088\u308A\u5927\u304D\u3044\u300D\u304C\u300C`x` \u4EE5\u4E0A\u300D\
    \u306B\u306A\u308B.\n    T high_value(T x, bool equal = false) {\n        if (equal)\
    \ { x--; }\n\n        int beta = more_count(x, false);\n\n        if (beta ==\
    \ 0) { throw out_of_range(\"No value found that is more than the limit \" + to_string(x)\
    \ + \".\"); }\n\n        return kth(-beta);\n    }\n\n    /// @brief Binary Trie\
    \ \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u306E\u3046\u3061\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\n    /// @param default_value\
    \ `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n    /// @param equal `true` \u306B\
    \u3059\u308B\u3068, \u300C`x` \u3088\u308A\u5927\u304D\u3044\u300D\u304C\u300C\
    `x` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n    T high_value(T x, T default_value,\
    \ bool equal = false) const {\n        if (equal) { x--; }\n\n        int beta\
    \ = more_count(x, false);\n\n        return beta > 0 ? kth(-beta) : default_value;\n\
    \    }\n\n    /// @brief Binary Trie \u6728\u306B\u3066 `x` \u304C\u5B58\u5728\
    \u3059\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B.\n    /// @param\
    \ x \n    inline bool contains(T x) { return count(x) > 0; }\n\n    T operator[](int\
    \ k) const {\n        if (k < 0) { k += size(); }\n\n        unless(0 <= k &&\
    \ k < size()) { throw out_of_range(\"Out of Range\"); }\n\n        T value = 0;\n\
    \        Binary_Trie_Node *node = root;\n        for (int d = bit_size - 1; d\
    \ >= 0; d--) {\n            Binary_Trie_Node *left = node->zero_child, *right\
    \ = node->one_child;\n\n            if (get_bit(lazy_xor(), d)) { swap(left, right);\
    \ }\n\n            if (left == nullptr) {\n                node = right;\n   \
    \             value |= T(1) << d;\n            } else if (left->subtree_size <=\
    \ k) {\n                k -= left->subtree_size;\n                node = right;\n\
    \                value |= T(1) << d;\n            } else {\n                node\
    \ = left;\n            }\n        }\n\n        return value;\n    }\n\n    inline\
    \ T kth(int k) const { return (*this)[k]; }\n\n    /// @brief \u6700\u5C0F\u5024\
    \u3092\u53D6\u5F97\u3059\u308B.\n    inline T get_min() const { return kth(0);\
    \ }\n\n\n    /// @brief \u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B.\n  \
    \  inline T get_max() const { return kth(-1); }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<typename\
    \ T>\nclass Binary_Trie {\n    struct Binary_Trie_Node {\n        int terminal\
    \ = 0, subtree_size = 0;\n        Binary_Trie_Node *zero_child = nullptr, *one_child\
    \ = nullptr;\n\n        Binary_Trie_Node() = default;\n    };\n\n    int bit_size;\n\
    \    bool allow_multiple;\n    T _lazy_xor = 0, max_value;\n    Binary_Trie_Node\
    \ *root;\n\n    Binary_Trie_Node* find_node(T x) {\n        Binary_Trie_Node *node\
    \ = root;\n        for (int k = bit_size - 1; k >= 0; k--) {\n            node\
    \ = get_bit(x, k) ? node->one_child : node->zero_child;\n            if (node\
    \ == nullptr) { break; }\n        }\n\n        return node;\n    }\n\n    public:\n\
    \    Binary_Trie() = default;\n\n    Binary_Trie(const int bit_size, bool allow_multiple\
    \ = false):\n        bit_size(bit_size), allow_multiple(allow_multiple), max_value(T(1)\
    \ << bit_size) {\n            root = new Binary_Trie_Node();\n        }\n\n  \
    \  inline T lazy_xor() const { return _lazy_xor; }\n    inline void act_xor(T\
    \ x) { _lazy_xor ^= x; }\n\n    // \u8981\u7D20\u306E\u8FFD\u52A0\n\n    /// @brief\
    \ x \u3092\u633F\u5165\u3059\u308B.\n    /// @param x \u633F\u5165\u3059\u308B\
    \u5024\n    /// @return Trie \u6728\u306B\u5909\u5316\u304C\u3042\u308C\u3070\
    \ true, \u306A\u3051\u308C\u3070 false.\n    bool insert(T x) {\n        Binary_Trie_Node\
    \ *node = root;\n        vector<Binary_Trie_Node*> path(bit_size + 1);\n     \
    \   path[0] = root;\n\n        x ^= lazy_xor();\n\n        for (int k = 0; k <\
    \ bit_size; k++) {\n            bool bit = get_bit(x, bit_size - (k + 1));\n \
    \           Binary_Trie_Node **child_ptr = bit ? &node->one_child : &node->zero_child;\n\
    \n            if (*child_ptr == nullptr) {\n                *child_ptr = new Binary_Trie_Node();\n\
    \            }\n\n            node = *child_ptr;\n            path[k + 1] = node;\n\
    \        }\n\n        if (node->terminal > 0 && !allow_multiple) { return false;\
    \ }\n        \n        node->terminal++;\n        for (auto node: path) {\n  \
    \          node->subtree_size++;\n        }\n\n        return true;\n    }\n\n\
    \    // \u8981\u7D20\u306E\u524A\u9664\n\n    /// @brief `x` \u304C\u5B58\u5728\
    \u3059\u308B\u5834\u5408\u306B `x` \u3092 1 \u500B\u524A\u9664\u3059\u308B.\n\
    \    /// @param x \u524A\u9664\u3059\u308B\u8981\u7D20\n    /// @return Trie \u6728\
    \u306B\u5909\u5316\u304C\u3042\u308C\u3070 true, \u306A\u3051\u308C\u3070 false.\n\
    \    bool discard(T x) {\n        unless(0 <= x && x < max_value) { return 0;\
    \ }\n\n        Binary_Trie_Node *node = root;\n\n        vector<Binary_Trie_Node*>\
    \ path(bit_size + 1);\n        path[0] = root;\n\n        x ^= lazy_xor();\n\n\
    \        for (int d = 0; d < bit_size; d++) {\n            bool bit = get_bit(x,\
    \ bit_size - (d + 1));\n\n            Binary_Trie_Node **child_ptr = bit ? &node->one_child\
    \ : &node->zero_child;\n\n            if (*child_ptr == nullptr) { return false;\
    \ }\n\n            node = *child_ptr;\n            path[d + 1] = node;\n     \
    \   }\n\n        if (!node->terminal) { return false; }\n\n        node->terminal--;\n\
    \        for (auto node: path) { node->subtree_size--; }\n\n        return true;\n\
    \    }\n\n    /// @brief `x` \u3092\u9AD8\u3005 `k` \u56DE\u524A\u9664\u3059\u308B\
    .\n    /// @param x \u524A\u9664\u3059\u308B\u8981\u7D20\n    /// @param k \u524A\
    \u9664\u3059\u308B\u500B\u6570 (k = -1 \u3068\u3059\u308B\u3068, \u7121\u9650\u56DE\
    \u306B\u306A\u308B)\n    /// @return `x` \u3092\u524A\u9664\u3057\u305F\u56DE\u6570\
    \n    int erase(T x, int k = -1) {\n        unless(0 <= x && x < max_value) {\
    \ return 0; }\n    \n        Binary_Trie_Node *node = root;\n\n        vector<Binary_Trie_Node*>\
    \ path(bit_size + 1);\n        path[0] = root;\n\n        x ^= lazy_xor();\n\n\
    \        for (int d = 0; d < bit_size; d++) {\n            bool bit = get_bit(x,\
    \ bit_size - (d + 1));\n\n            Binary_Trie_Node **child_ptr = bit ? &node->one_child\
    \ : &node->zero_child;\n\n            if (*child_ptr == nullptr) { return false;\
    \ }\n\n            node = *child_ptr;\n            path[d + 1] = node;\n     \
    \   }\n\n        if ((k == -1) || node->terminal < k) { \n            k = node->terminal;\n\
    \        }\n\n        node->terminal -= k;\n        for (auto node: path) { node->subtree_size\
    \ -= k; }\n\n        return k;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u6570\u3092\u6C42\u3081\
    \u308B.\n    inline int64_t size() const { return root->subtree_size; }\n\n  \
    \  inline explicit operator bool() const { return size() > 0; }\n\n    /// @brief\
    \ Binary Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B x \u306E\u6570\
    \u3092\u6C42\u3081\u308B.\n    /// @param x \u691C\u7D22\u5024\n    int count(T\
    \ x) {\n        unless (0 <= x && x < max_value) { return 0; }\n\n        x ^=\
    \ lazy_xor();\n\n        Binary_Trie_Node* node = find_node(x);\n        return\
    \ node != nullptr ? node->subtree_size : 0;\n    }\n\n    /// @brief Binary Trie\
    \ \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u672A\u6E80\u306E\
    \u8981\u7D20\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\
    \n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u672A\u6E80\
    \u300D\u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\u308B.\n    int less_count(T\
    \ x, bool equal = false) {\n        if (equal) { return less_count(x + 1, false);\
    \ }\n\n        if (x < 0) { return 0; }\n        if (x >= (T(1) << bit_size))\
    \ { return root->subtree_size;}\n\n        int res = 0;\n        Binary_Trie_Node\
    \ *node = root;\n\n        x ^= lazy_xor();\n\n        for (int k = bit_size -\
    \ 1; k >= 0; k--) {\n            Binary_Trie_Node *left = node->zero_child, *right\
    \ = node->one_child;\n            if (get_bit(lazy_xor(), k)) {\n            \
    \    swap(left, right);\n            }\n\n            if (get_bit(x, k)) {\n \
    \               if (left != nullptr) {\n                    res += left->subtree_size;\n\
    \                } else if (right != nullptr) {\n                    return res;\n\
    \                }\n\n                node = right;\n            } else {\n  \
    \              if (left == nullptr) {\n                    return res;\n     \
    \           }\n\n                node = left;\n            }\n        }\n\n  \
    \      return res;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\u4FDD\u5B58\
    \u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u306E\
    \u6570\u3092\u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\n    /// @param\
    \ equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u3088\u308A\u5927\u304D\u3044\
    \u300D\u304C\u300C`x` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n    inline int more_count(T\
    \ x, bool equal = false) const { return size() - less_count(x, !equal); }\n\n\
    \    /// @brief Binary Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `x` \u672A\u6E80\u3067\u6700\u5927\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B\
    .\n    /// @param x \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\
    \u3068, \u300C`x` \u672A\u6E80\u300D\u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\
    \u308B.\n    T low_value(T x, bool equal = false) {\n        if (equal) { x++;\
    \ }\n\n        int alpha = less_count(x, false);\n\n        if (alpha == 0) {\
    \ throw out_of_range(\"No value found that is less than the limit \" + to_string(x)\
    \ + \".\"); }\n\n        return kth(alpha - 1);\n    }\n\n    /// @brief Binary\
    \ Trie \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u672A\u6E80\
    \u3067\u6700\u5927\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ x \u95BE\u5024\n    /// @param default_value `x` \u672A\u6E80\u306E\u8981\u7D20\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n   \
    \ /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`x` \u672A\u6E80\u300D\
    \u304C\u300C`x` \u4EE5\u4E0B\u300D\u306B\u306A\u308B.\n    T low_value(T x, T\
    \ default_value, bool equal = false) const {\n        if (equal) { x++; }\n\n\
    \        int alpha = less_count(x, false);\n\n        return alpha > 0 ? kth(alpha\
    \ - 1) : default_value;\n    }\n\n    /// @brief Binary Trie \u6728\u306B\u4FDD\
    \u5B58\u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\
    \u306E\u3046\u3061\u6700\u5C0F\u306E\u8981\u7D20\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param x \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068\
    , \u300C`x` \u3088\u308A\u5927\u304D\u3044\u300D\u304C\u300C`x` \u4EE5\u4E0A\u300D\
    \u306B\u306A\u308B.\n    T high_value(T x, bool equal = false) {\n        if (equal)\
    \ { x--; }\n\n        int beta = more_count(x, false);\n\n        if (beta ==\
    \ 0) { throw out_of_range(\"No value found that is more than the limit \" + to_string(x)\
    \ + \".\"); }\n\n        return kth(-beta);\n    }\n\n    /// @brief Binary Trie\
    \ \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `x` \u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u306E\u3046\u3061\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u6C42\u3081\u308B.\n    /// @param x \u95BE\u5024\n    /// @param default_value\
    \ `x` \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\
    \u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n    /// @param equal `true` \u306B\
    \u3059\u308B\u3068, \u300C`x` \u3088\u308A\u5927\u304D\u3044\u300D\u304C\u300C\
    `x` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n    T high_value(T x, T default_value,\
    \ bool equal = false) const {\n        if (equal) { x--; }\n\n        int beta\
    \ = more_count(x, false);\n\n        return beta > 0 ? kth(-beta) : default_value;\n\
    \    }\n\n    /// @brief Binary Trie \u6728\u306B\u3066 `x` \u304C\u5B58\u5728\
    \u3059\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B.\n    /// @param\
    \ x \n    inline bool contains(T x) { return count(x) > 0; }\n\n    T operator[](int\
    \ k) const {\n        if (k < 0) { k += size(); }\n\n        unless(0 <= k &&\
    \ k < size()) { throw out_of_range(\"Out of Range\"); }\n\n        T value = 0;\n\
    \        Binary_Trie_Node *node = root;\n        for (int d = bit_size - 1; d\
    \ >= 0; d--) {\n            Binary_Trie_Node *left = node->zero_child, *right\
    \ = node->one_child;\n\n            if (get_bit(lazy_xor(), d)) { swap(left, right);\
    \ }\n\n            if (left == nullptr) {\n                node = right;\n   \
    \             value |= T(1) << d;\n            } else if (left->subtree_size <=\
    \ k) {\n                k -= left->subtree_size;\n                node = right;\n\
    \                value |= T(1) << d;\n            } else {\n                node\
    \ = left;\n            }\n        }\n\n        return value;\n    }\n\n    inline\
    \ T kth(int k) const { return (*this)[k]; }\n\n    /// @brief \u6700\u5C0F\u5024\
    \u3092\u53D6\u5F97\u3059\u308B.\n    inline T get_min() const { return kth(0);\
    \ }\n\n\n    /// @brief \u6700\u5927\u5024\u3092\u53D6\u5F97\u3059\u308B.\n  \
    \  inline T get_max() const { return kth(-1); }\n};"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Data_Structure/Binary_Trie.hpp
  requiredBy: []
  timestamp: '2026-02-14 20:38:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Set_Xor-Min.test.cpp
documentation_of: Data_Structure/Binary_Trie.hpp
layout: document
title: "Binary Trie \u6728"
---

## Outline

非負整数をビット列に変換して Trie 木で管理することにより, 値の挿入, 削除, 検索などをオンライン $O(w)$ 時間で行うことができる.
