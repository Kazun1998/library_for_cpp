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
    path: verify/yosupo_library_checker/data_structure/Ordered_Set.test.cpp
    title: verify/yosupo_library_checker/data_structure/Ordered_Set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u30AD\
      \u30FC\u306E\u6570\u3092\u6C42\u3081\u308B."
    links: []
  bundledCode: "#line 2 \"Data_Structure/AVL_Tree.hpp\"\n\n#line 2 \"template/template.hpp\"\
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
    \ bit_length(x)); }\n#line 71 \"template/template.hpp\"\n\n// exception\n#line\
    \ 2 \"template/exception.hpp\"\n\nclass NotExist: public exception {\n    private:\n\
    \    string message;\n\n    public:\n    NotExist() : message(\"\u6C42\u3081\u3088\
    \u3046\u3068\u3057\u3066\u3044\u305F\u3082\u306E\u306F\u5B58\u5728\u3057\u307E\
    \u305B\u3093.\") {}\n\n    const char* what() const noexcept override {\n    \
    \    return message.c_str();\n    }\n};\n#line 4 \"Data_Structure/AVL_Tree.hpp\"\
    \n\ntemplate<typename K, typename V>\nclass Adelson_Velsky_and_Landis_Tree {\n\
    \    class Node {\n        public:\n        K key;\n        V value;\n       \
    \ Node *left, *right;\n        int height, size;\n\n        Node(K key, V value):\
    \ key(key), value(value), left(nullptr), right(nullptr), height(1), size(1) {}\n\
    \n        inline int set_height() { return height = 1 + std::max(height_of(left),\
    \ height_of(right)); }\n\n        inline int set_size() { return size = 1 + size_of(left)\
    \ + size_of(right); }\n\n        inline int get_height() { return height; }\n\n\
    \        inline int get_bias() { return height_of(left) - height_of(right); }\n\
    \n        static inline int height_of(Node *node)  { return (node == nullptr)\
    \ ? 0 : node->height; }\n\n        static inline int size_of(Node *node) { return\
    \ (node == nullptr) ? 0 : node->size; }\n\n        Node* left_rotation() {\n \
    \           Node *x = this;\n            Node *y = x->right;\n            Node\
    \ *z = y->left;\n\n            y->left = x;\n            x->right = z;\n\n   \
    \         x->set_height();\n            y->set_height();\n\n            x->set_size();\n\
    \            y->set_size();\n\n            return y;\n        }\n\n        Node*\
    \ right_rotation() {\n            Node *x = this;\n            Node *y = x->left;\n\
    \            Node *z = y->right;\n\n            y->right = x;\n            x->left\
    \ = z;\n\n            x->set_height();\n            y->set_height();\n\n     \
    \       x->set_size();\n            y->set_size();\n\n            return y;\n\
    \        }\n\n        static const Node* find_dig(const Node* node, const K &key)\
    \ {\n            if (node == nullptr) { return nullptr; }\n\n            if (key\
    \ == node->key) { return node; }\n\n            return key < node->key ? find_dig(node->left,\
    \ key) : find_dig(node->right, key);\n        }\n    };\n\n    private:\n    Node*\
    \ insert_inner(Node *node, const K &key, const V &value) {\n        if (node ==\
    \ nullptr) { return new Node(key, value); }\n\n        if (key == node->key) {\n\
    \            node->value = value;\n            return node;\n        }\n\n   \
    \     if (key < node->key) {\n            node->left = insert_inner(node->left,\
    \ key, value);\n        } else {\n            node->right = insert_inner(node->right,\
    \ key, value);\n        }\n\n        node->set_height();\n        node->set_size();\n\
    \n        int bias = node->get_bias();\n\n        // Case I: Left Left\n     \
    \   if (bias > 1 && key < node->left->key) {\n            return node->right_rotation();\n\
    \        }\n\n        // Case II: Right Right\n        if (bias < -1 && key >\
    \ node->right->key) {\n            return node->left_rotation();\n        }\n\n\
    \        // Case III: Left Right\n        if (bias > 1 && key > node->left->key)\
    \ {\n            node->left = node->left->left_rotation();\n            return\
    \ node->right_rotation();\n        }\n\n        // Case IV: Right Left\n     \
    \   if (bias < -1 && key < node->right->key) {\n            node->right = node->right->right_rotation();\n\
    \            return node->left_rotation();\n        }\n\n        return node;\n\
    \    }\n\n    Node* delete_inner(Node *node, const K &key) {\n        if (node\
    \ == nullptr) { return node; }\n        else if (key < node->key) {\n        \
    \    node->left = delete_inner(node->left, key);\n        } else if (key > node->key)\
    \ {\n            node->right = delete_inner(node->right, key);\n        } else\
    \ {\n            if (node->left == nullptr) {\n                Node *tmp = node->right;\n\
    \                delete node;\n                return tmp;\n            } else\
    \ if (node->right == nullptr) {\n                Node *tmp = node->left;\n   \
    \             delete node;\n                return tmp;\n            }\n\n   \
    \         Node *tmp = node->right;\n            while (tmp->left != nullptr) {\n\
    \                tmp = tmp->left;\n            }\n\n            node->key = tmp->key;\n\
    \            node->value = tmp->value;\n            node->right = delete_inner(node->right,\
    \ tmp->key);\n        }\n\n        if (node == nullptr) { return node; }\n\n \
    \       node->set_height();\n        node->set_size();\n\n        int bias = node->get_bias();\n\
    \n        // Case I: Left Left\n        if (bias > 1 && node->left->get_bias()\
    \ >= 0) {\n            return node->right_rotation();\n        }\n\n        //\
    \ Case II: Right Right\n        if (bias < -1 && node->right->get_bias() <= 0)\
    \ {\n            return node->left_rotation();\n        }\n\n        // Case III:\
    \ Left Right\n        if (bias > 1 && node->left->get_bias() < 0) {\n        \
    \    node->left = node->left->left_rotation();\n            return node->right_rotation();\n\
    \        }\n\n        // Case IV: Right Left\n        if (bias < -1 && node->right->get_bias()\
    \ > 0) {\n            node->right = node->right->right_rotation();\n         \
    \   return node->left_rotation();\n        }\n\n        return node;\n    }\n\n\
    \    const Node* next_inner(const K &key, bool equal) const {\n        const Node\
    \ *successor = nullptr;\n        const Node *node = root;\n\n        while (node\
    \ != nullptr) {\n            bool condition = equal ? (key <= node->key) : (key\
    \ < node->key);\n\n            if (condition) {\n                successor = node;\n\
    \                node = node->left;\n            } else {\n                node\
    \ = node->right;\n            }\n        }\n\n        return successor;\n    }\n\
    \n    const Node* previous_inner(const K &key, bool equal) const {\n        const\
    \ Node *predecessor = nullptr;\n        const Node *node = root;\n\n        while\
    \ (node != nullptr) {\n            bool condition = equal ? (key >= node->key)\
    \ : (key > node->key);\n\n            if (condition) {\n                predecessor\
    \ = node;\n                node = node->right;\n            } else {\n       \
    \         node = node->left;\n            }\n        }\n        return predecessor;\n\
    \    }\n\n    inline const Node* find_inner(const K &key) {\n        return Node::find_dig(root,\
    \ key);\n    }\n\n    const Node* find_inner(const K &key) const {\n        const\
    \ Node *node = root;\n\n        while (node != nullptr) {\n            if (key\
    \ == node->key) { return node; }\n            node = (key < node->key) ? node->left\
    \ : node->right;\n        }\n\n        return nullptr;\n    }\n\n    void clear(Node*\
    \ node) {\n        if (node == nullptr) return;\n        clear(node->left);\n\
    \        clear(node->right);\n        delete node;\n    }\n\n    int less_count_inner(Node\
    \ *node, const K &key, bool equal) const {\n        if (node == nullptr) { return\
    \ 0; }\n\n        bool condition = equal ? (node->key <= key) : (node->key < key);\n\
    \n        if (condition) {\n            int left_size = Node::size_of(node->left);\n\
    \            return 1 + left_size + less_count_inner(node->right, key, equal);\n\
    \        } else {\n            return less_count_inner(node->left, key, equal);\n\
    \        }\n    }\n\n    Node *root;\n\n    public:\n    Adelson_Velsky_and_Landis_Tree():\
    \ root(nullptr) {}\n    ~Adelson_Velsky_and_Landis_Tree() { clear(root); }\n\n\
    \    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u30AD\
    \u30FC\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int size() const { return\
    \ Node::size_of(root); }\n\n    /// @brief AVL \u6728\u306B `key` \u306B\u5BFE\
    \u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u8FFD\u52A0\u3059\u308B.\n    /// @param\
    \ key \u30AD\u30FC\n    inline void insert(const K &key) { insert(key, V()); }\n\
    \n    /// @brief AVL \u6728\u306B `key`, `value` \u306B\u5BFE\u5FDC\u3059\u308B\
    \u30CE\u30FC\u30C9\u3092\u8FFD\u52A0\u3059\u308B.\n    /// @param key \u30AD\u30FC\
    \n    /// @param value \u30D0\u30EA\u30E5\u30FC\n    inline void insert(const\
    \ K &key, const V &value) {\n        root = insert_inner(root, key, value);\n\
    \    }\n\n    inline void discard(const K &key) { root = delete_inner(root, key);\
    \ }\n\n    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\u306E\u3046\u3061\u306E\u6700\
    \u5C0F\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\u5024\
    \n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\u308A\
    \u5927\u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\u308B\
    .\n    K next(const K &key, bool equal = true) const {\n        const Node *successor\
    \ = next_inner(key, equal);\n\n        if (successor == nullptr) { throw std::out_of_range(\"\
    Successor key not found (out of range).\"); }\n\n        return successor->key;\n\
    \    }\n\n    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\u306E\u3046\u3061\u306E\u6700\
    \u5C0F\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\u5024\
    \n    /// @param default_value `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n   \
    \ /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\u308A\u5927\
    \u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n  \
    \  K next(const K &key, const K &default_value, bool equal = true) const {\n \
    \       const Node *successor = next_inner(key, equal);\n\n        return (successor\
    \ != nullptr) ? successor->key : default_value;\n    }\n\n    /// @brief AVL \u6728\
    \u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\u306E\u30AD\
    \u30FC\u306E\u3046\u3061\u306E\u6700\u5927\u306E\u30AD\u30FC\u3092\u6C42\u3081\
    \u308B.\n    /// @param key \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\
    \u308B\u3068, \u300C`key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\
    \u306B\u306A\u308B.\n    K previous(const K &key, bool equal = true) const {\n\
    \        const Node *predecessor = previous_inner(key, equal);\n\n        if (predecessor\
    \ == nullptr) { throw std::out_of_range(\"Predecessor key not found (out of range).\"\
    ); }\n\n        return predecessor->key;\n    }\n\n    /// @brief AVL \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\u306E\u30AD\u30FC\
    \u3046\u3061\u306E\u6700\u5927\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param key \u95BE\u5024\n    /// @param default_value `key` \u3088\u308A\
    \u5927\u304D\u3044\u30AD\u30FC\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306E\u8FD4\u308A\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068\
    , \u300C`key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\u306B\u306A\
    \u308B.\n    K previous(const K &key, const K &default_value, bool equal = true)\
    \ const {\n        const Node *predecessor = previous_inner(key, equal);\n\n \
    \       return (predecessor != nullptr) ? predecessor->key : default_value;\n\
    \    }\n\n    V& operator[](const K &key) {\n        insert(key);\n        return\
    \ find_inner(key)->value;\n    }\n\n    /// @brief AVL \u6728\u306B\u304A\u3051\
    \u308B `key` \u306B\u5BFE\u5FDC\u3059\u30D0\u30EA\u30E5\u30FC\u3092\u6C42\u3081\
    \u308B.\n    /// @param key \u691C\u7D22\u30AD\u30FC\n    inline V* find(const\
    \ K &key) {\n        Node *node = find_inner(key);\n        return (node == nullptr)\
    \ ? nullptr : &(node->value);\n    }\n\n    \n    /// @brief AVL \u6728\u306B\u304A\
    \u3051\u308B `key` \u306B\u5BFE\u5FDC\u3059\u30D0\u30EA\u30E5\u30FC\u3092\u6C42\
    \u3081\u308B.\n    /// @param key \u691C\u7D22\u30AD\u30FC\n    inline const V*\
    \ find(const K &key) const {\n        const Node *node = find_inner(key);\n  \
    \      return (node == nullptr) ? nullptr : &(node->value);\n    }\n\n    ///\
    \ @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u6607\u9806\
    \ `k` (0-indexed) \u756A\u76EE\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param k \u756A\u53F7 (`k` < 0 \u306B\u3059\u308B\u3068, \u964D\u9806 |`k`|\
    \ (1-indexed) \u756A\u76EE\u306B\u306A\u308B).\n    const K& kth_key(int k) const\
    \ {\n        if (k < 0) { k += size(); }\n\n        if(!(0 <= k && k < size()))\
    \ { throw std::out_of_range(\"Index k is out of bounds.\"); }\n\n        const\
    \ Node *node = root;\n        while (true) {\n            int t = Node::size_of(node->left);\n\
    \n            if (k == t) { return node->key; }\n            else if (k < t) {\
    \ node = node->left; }\n            else {\n                k -= t + 1;\n    \
    \            node = node->right;\n            }\n        }\n    }\n\n    /// @brief\
    \ AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\
    \u306E\u30CE\u30FC\u30C9\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ key \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C\
    `key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\u306B\u306A\u308B\
    .\n    int less_count(const K &key, bool equal = false) const {\n        return\
    \ less_count_inner(root, key, equal);\n    }\n\n    /// @brief AVL \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u3088\u308A\u5927\u304D\u3044\
    \u30CE\u30FC\u30C9\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\
    \u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\
    \u308A\u5927\u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\
    \u308B.\n    inline int more_count(const K &key, bool equal = false) const {\n\
    \        return size() - less_count(key, !equal);\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\ntemplate<typename\
    \ K, typename V>\nclass Adelson_Velsky_and_Landis_Tree {\n    class Node {\n \
    \       public:\n        K key;\n        V value;\n        Node *left, *right;\n\
    \        int height, size;\n\n        Node(K key, V value): key(key), value(value),\
    \ left(nullptr), right(nullptr), height(1), size(1) {}\n\n        inline int set_height()\
    \ { return height = 1 + std::max(height_of(left), height_of(right)); }\n\n   \
    \     inline int set_size() { return size = 1 + size_of(left) + size_of(right);\
    \ }\n\n        inline int get_height() { return height; }\n\n        inline int\
    \ get_bias() { return height_of(left) - height_of(right); }\n\n        static\
    \ inline int height_of(Node *node)  { return (node == nullptr) ? 0 : node->height;\
    \ }\n\n        static inline int size_of(Node *node) { return (node == nullptr)\
    \ ? 0 : node->size; }\n\n        Node* left_rotation() {\n            Node *x\
    \ = this;\n            Node *y = x->right;\n            Node *z = y->left;\n\n\
    \            y->left = x;\n            x->right = z;\n\n            x->set_height();\n\
    \            y->set_height();\n\n            x->set_size();\n            y->set_size();\n\
    \n            return y;\n        }\n\n        Node* right_rotation() {\n     \
    \       Node *x = this;\n            Node *y = x->left;\n            Node *z =\
    \ y->right;\n\n            y->right = x;\n            x->left = z;\n\n       \
    \     x->set_height();\n            y->set_height();\n\n            x->set_size();\n\
    \            y->set_size();\n\n            return y;\n        }\n\n        static\
    \ const Node* find_dig(const Node* node, const K &key) {\n            if (node\
    \ == nullptr) { return nullptr; }\n\n            if (key == node->key) { return\
    \ node; }\n\n            return key < node->key ? find_dig(node->left, key) :\
    \ find_dig(node->right, key);\n        }\n    };\n\n    private:\n    Node* insert_inner(Node\
    \ *node, const K &key, const V &value) {\n        if (node == nullptr) { return\
    \ new Node(key, value); }\n\n        if (key == node->key) {\n            node->value\
    \ = value;\n            return node;\n        }\n\n        if (key < node->key)\
    \ {\n            node->left = insert_inner(node->left, key, value);\n        }\
    \ else {\n            node->right = insert_inner(node->right, key, value);\n \
    \       }\n\n        node->set_height();\n        node->set_size();\n\n      \
    \  int bias = node->get_bias();\n\n        // Case I: Left Left\n        if (bias\
    \ > 1 && key < node->left->key) {\n            return node->right_rotation();\n\
    \        }\n\n        // Case II: Right Right\n        if (bias < -1 && key >\
    \ node->right->key) {\n            return node->left_rotation();\n        }\n\n\
    \        // Case III: Left Right\n        if (bias > 1 && key > node->left->key)\
    \ {\n            node->left = node->left->left_rotation();\n            return\
    \ node->right_rotation();\n        }\n\n        // Case IV: Right Left\n     \
    \   if (bias < -1 && key < node->right->key) {\n            node->right = node->right->right_rotation();\n\
    \            return node->left_rotation();\n        }\n\n        return node;\n\
    \    }\n\n    Node* delete_inner(Node *node, const K &key) {\n        if (node\
    \ == nullptr) { return node; }\n        else if (key < node->key) {\n        \
    \    node->left = delete_inner(node->left, key);\n        } else if (key > node->key)\
    \ {\n            node->right = delete_inner(node->right, key);\n        } else\
    \ {\n            if (node->left == nullptr) {\n                Node *tmp = node->right;\n\
    \                delete node;\n                return tmp;\n            } else\
    \ if (node->right == nullptr) {\n                Node *tmp = node->left;\n   \
    \             delete node;\n                return tmp;\n            }\n\n   \
    \         Node *tmp = node->right;\n            while (tmp->left != nullptr) {\n\
    \                tmp = tmp->left;\n            }\n\n            node->key = tmp->key;\n\
    \            node->value = tmp->value;\n            node->right = delete_inner(node->right,\
    \ tmp->key);\n        }\n\n        if (node == nullptr) { return node; }\n\n \
    \       node->set_height();\n        node->set_size();\n\n        int bias = node->get_bias();\n\
    \n        // Case I: Left Left\n        if (bias > 1 && node->left->get_bias()\
    \ >= 0) {\n            return node->right_rotation();\n        }\n\n        //\
    \ Case II: Right Right\n        if (bias < -1 && node->right->get_bias() <= 0)\
    \ {\n            return node->left_rotation();\n        }\n\n        // Case III:\
    \ Left Right\n        if (bias > 1 && node->left->get_bias() < 0) {\n        \
    \    node->left = node->left->left_rotation();\n            return node->right_rotation();\n\
    \        }\n\n        // Case IV: Right Left\n        if (bias < -1 && node->right->get_bias()\
    \ > 0) {\n            node->right = node->right->right_rotation();\n         \
    \   return node->left_rotation();\n        }\n\n        return node;\n    }\n\n\
    \    const Node* next_inner(const K &key, bool equal) const {\n        const Node\
    \ *successor = nullptr;\n        const Node *node = root;\n\n        while (node\
    \ != nullptr) {\n            bool condition = equal ? (key <= node->key) : (key\
    \ < node->key);\n\n            if (condition) {\n                successor = node;\n\
    \                node = node->left;\n            } else {\n                node\
    \ = node->right;\n            }\n        }\n\n        return successor;\n    }\n\
    \n    const Node* previous_inner(const K &key, bool equal) const {\n        const\
    \ Node *predecessor = nullptr;\n        const Node *node = root;\n\n        while\
    \ (node != nullptr) {\n            bool condition = equal ? (key >= node->key)\
    \ : (key > node->key);\n\n            if (condition) {\n                predecessor\
    \ = node;\n                node = node->right;\n            } else {\n       \
    \         node = node->left;\n            }\n        }\n        return predecessor;\n\
    \    }\n\n    inline const Node* find_inner(const K &key) {\n        return Node::find_dig(root,\
    \ key);\n    }\n\n    const Node* find_inner(const K &key) const {\n        const\
    \ Node *node = root;\n\n        while (node != nullptr) {\n            if (key\
    \ == node->key) { return node; }\n            node = (key < node->key) ? node->left\
    \ : node->right;\n        }\n\n        return nullptr;\n    }\n\n    void clear(Node*\
    \ node) {\n        if (node == nullptr) return;\n        clear(node->left);\n\
    \        clear(node->right);\n        delete node;\n    }\n\n    int less_count_inner(Node\
    \ *node, const K &key, bool equal) const {\n        if (node == nullptr) { return\
    \ 0; }\n\n        bool condition = equal ? (node->key <= key) : (node->key < key);\n\
    \n        if (condition) {\n            int left_size = Node::size_of(node->left);\n\
    \            return 1 + left_size + less_count_inner(node->right, key, equal);\n\
    \        } else {\n            return less_count_inner(node->left, key, equal);\n\
    \        }\n    }\n\n    Node *root;\n\n    public:\n    Adelson_Velsky_and_Landis_Tree():\
    \ root(nullptr) {}\n    ~Adelson_Velsky_and_Landis_Tree() { clear(root); }\n\n\
    \    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u30AD\
    \u30FC\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int size() const { return\
    \ Node::size_of(root); }\n\n    /// @brief AVL \u6728\u306B `key` \u306B\u5BFE\
    \u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u8FFD\u52A0\u3059\u308B.\n    /// @param\
    \ key \u30AD\u30FC\n    inline void insert(const K &key) { insert(key, V()); }\n\
    \n    /// @brief AVL \u6728\u306B `key`, `value` \u306B\u5BFE\u5FDC\u3059\u308B\
    \u30CE\u30FC\u30C9\u3092\u8FFD\u52A0\u3059\u308B.\n    /// @param key \u30AD\u30FC\
    \n    /// @param value \u30D0\u30EA\u30E5\u30FC\n    inline void insert(const\
    \ K &key, const V &value) {\n        root = insert_inner(root, key, value);\n\
    \    }\n\n    inline void discard(const K &key) { root = delete_inner(root, key);\
    \ }\n\n    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\u306E\u3046\u3061\u306E\u6700\
    \u5C0F\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\u5024\
    \n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\u308A\
    \u5927\u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\u308B\
    .\n    K next(const K &key, bool equal = true) const {\n        const Node *successor\
    \ = next_inner(key, equal);\n\n        if (successor == nullptr) { throw std::out_of_range(\"\
    Successor key not found (out of range).\"); }\n\n        return successor->key;\n\
    \    }\n\n    /// @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\
    \ `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\u306E\u3046\u3061\u306E\u6700\
    \u5C0F\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\u5024\
    \n    /// @param default_value `key` \u3088\u308A\u5927\u304D\u3044\u30AD\u30FC\
    \u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306E\u8FD4\u308A\u5024\n   \
    \ /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\u308A\u5927\
    \u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\u308B.\n  \
    \  K next(const K &key, const K &default_value, bool equal = true) const {\n \
    \       const Node *successor = next_inner(key, equal);\n\n        return (successor\
    \ != nullptr) ? successor->key : default_value;\n    }\n\n    /// @brief AVL \u6728\
    \u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\u306E\u30AD\
    \u30FC\u306E\u3046\u3061\u306E\u6700\u5927\u306E\u30AD\u30FC\u3092\u6C42\u3081\
    \u308B.\n    /// @param key \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\
    \u308B\u3068, \u300C`key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\
    \u306B\u306A\u308B.\n    K previous(const K &key, bool equal = true) const {\n\
    \        const Node *predecessor = previous_inner(key, equal);\n\n        if (predecessor\
    \ == nullptr) { throw std::out_of_range(\"Predecessor key not found (out of range).\"\
    ); }\n\n        return predecessor->key;\n    }\n\n    /// @brief AVL \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\u306E\u30AD\u30FC\
    \u3046\u3061\u306E\u6700\u5927\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param key \u95BE\u5024\n    /// @param default_value `key` \u3088\u308A\
    \u5927\u304D\u3044\u30AD\u30FC\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306E\u8FD4\u308A\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068\
    , \u300C`key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\u306B\u306A\
    \u308B.\n    K previous(const K &key, const K &default_value, bool equal = true)\
    \ const {\n        const Node *predecessor = previous_inner(key, equal);\n\n \
    \       return (predecessor != nullptr) ? predecessor->key : default_value;\n\
    \    }\n\n    V& operator[](const K &key) {\n        insert(key);\n        return\
    \ find_inner(key)->value;\n    }\n\n    /// @brief AVL \u6728\u306B\u304A\u3051\
    \u308B `key` \u306B\u5BFE\u5FDC\u3059\u30D0\u30EA\u30E5\u30FC\u3092\u6C42\u3081\
    \u308B.\n    /// @param key \u691C\u7D22\u30AD\u30FC\n    inline V* find(const\
    \ K &key) {\n        Node *node = find_inner(key);\n        return (node == nullptr)\
    \ ? nullptr : &(node->value);\n    }\n\n    \n    /// @brief AVL \u6728\u306B\u304A\
    \u3051\u308B `key` \u306B\u5BFE\u5FDC\u3059\u30D0\u30EA\u30E5\u30FC\u3092\u6C42\
    \u3081\u308B.\n    /// @param key \u691C\u7D22\u30AD\u30FC\n    inline const V*\
    \ find(const K &key) const {\n        const Node *node = find_inner(key);\n  \
    \      return (node == nullptr) ? nullptr : &(node->value);\n    }\n\n    ///\
    \ @brief AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B\u6607\u9806\
    \ `k` (0-indexed) \u756A\u76EE\u306E\u30AD\u30FC\u3092\u6C42\u3081\u308B.\n  \
    \  /// @param k \u756A\u53F7 (`k` < 0 \u306B\u3059\u308B\u3068, \u964D\u9806 |`k`|\
    \ (1-indexed) \u756A\u76EE\u306B\u306A\u308B).\n    const K& kth_key(int k) const\
    \ {\n        if (k < 0) { k += size(); }\n\n        if(!(0 <= k && k < size()))\
    \ { throw std::out_of_range(\"Index k is out of bounds.\"); }\n\n        const\
    \ Node *node = root;\n        while (true) {\n            int t = Node::size_of(node->left);\n\
    \n            if (k == t) { return node->key; }\n            else if (k < t) {\
    \ node = node->left; }\n            else {\n                k -= t + 1;\n    \
    \            node = node->right;\n            }\n        }\n    }\n\n    /// @brief\
    \ AVL \u6728\u306B\u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u672A\u6E80\
    \u306E\u30CE\u30FC\u30C9\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param\
    \ key \u95BE\u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C\
    `key` \u672A\u6E80\u300D\u304C\u300C`key` \u4EE5\u4E0B\u300D\u306B\u306A\u308B\
    .\n    int less_count(const K &key, bool equal = false) const {\n        return\
    \ less_count_inner(root, key, equal);\n    }\n\n    /// @brief AVL \u6728\u306B\
    \u4FDD\u5B58\u3055\u308C\u3066\u3044\u308B `key` \u3088\u308A\u5927\u304D\u3044\
    \u30CE\u30FC\u30C9\u306E\u6570\u3092\u6C42\u3081\u308B.\n    /// @param key \u95BE\
    \u5024\n    /// @param equal `true` \u306B\u3059\u308B\u3068, \u300C`key` \u3088\
    \u308A\u5927\u304D\u3044\u300D\u304C\u300C`key` \u4EE5\u4E0A\u300D\u306B\u306A\
    \u308B.\n    inline int more_count(const K &key, bool equal = false) const {\n\
    \        return size() - less_count(key, !equal);\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Data_Structure/AVL_Tree.hpp
  requiredBy: []
  timestamp: '2026-01-01 02:18:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Ordered_Set.test.cpp
documentation_of: Data_Structure/AVL_Tree.hpp
layout: document
title: "Adelson-Velskii-Landis \u6728"
---

## Outline

平衡二分探索木の $1$ つである AVL 木 (Adelson-Velskii-Landis 木) を構築する.
