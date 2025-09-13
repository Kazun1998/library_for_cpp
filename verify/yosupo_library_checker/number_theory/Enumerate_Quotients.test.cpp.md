---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Quotients.hpp
    title: Integer/Quotients.hpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n\
    #include<bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"Integer/Quotients.hpp\"\
    \n\n#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#line 29 \"template/template.hpp\"\n#include <initializer_list>\n\
    #line 50 \"template/template.hpp\"\n#include <type_traits>\n#line 56 \"template/template.hpp\"\
    \n\n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n\
    // a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
    \u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename\
    \ U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n\
    }\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T,\
    \ typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a = b,\
    \ 1: 0);\n}\n#line 59 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// \u9664\u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){\
    \ return (x > 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0\
    \ ? (x + y - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x,\
    \ U y){\n    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092\
    \ y \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x,\
    \ y);\n    return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q,\
    \ r;\n    tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1\
    \ : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E\
    \ y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n \
    \   while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n        y >>=\
    \ 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\
    \u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x\
    \ *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\
    \u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n \
    \       if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>=\
    \ 1;\n    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto\
    \ &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T> &X){\n\
    \    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n#line 62\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\n// \u5165\
    \u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ... >> a); }\n\
    \nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\nvoid print(const\
    \ T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout << \" \",\
    \ b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\n\
    template<typename T, typename U>\nostream &operator<<(ostream &os, const pair<T,\
    \ U> &P){\n    os << P.first << \" \" << P.second;\n    return os;\n}\n\ntemplate<typename\
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
    \ elif else if\n#define unless(cond) if (!(cond))\n\n// \u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1, _2, name, ...) name\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define overload4(_1, _2, _3, _4,\
    \ name, ...) name\n#define overload5(_1, _2, _3, _4, _5, name, ...) name\n\n//\
    \ \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for (ll i = 0; i < n; i++)\n\
    #define rep2(i, n) for (ll i = 0; i < n; i++)\n#define rep3(i, a, b) for (ll i\
    \ = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)\n#define\
    \ rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define\
    \ foreach1(x, a) for (auto &&x: a)\n#define foreach2(x, y, a) for (auto &&[x,\
    \ y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y, z]: a)\n#define foreach4(x,\
    \ y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__,\
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 4 \"Integer/Quotients.hpp\"\
    \n\nvector<tuple<ll, ll, ll>> Quotients(ll N) {\n    auto quotients = vector<tuple<ll,\
    \ ll, ll>>();\n\n    ll l = 1;\n    while (l <= N) {\n        ll q = N / l;\n\
    \        ll r = N / q;\n        quotients.emplace_back(q, l, r);\n        l =\
    \ r + 1;\n    }\n\n    return quotients;\n}\n#line 8 \"verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp\"\
    \n\nint main() {\n    ll N; cin >> N;\n    auto quotients = Quotients(N);\n\n\
    \    reverse(quotients.begin(), quotients.end());\n    cout << quotients.size()\
    \ << endl;\n    for (int i = 0; i < quotients.size(); i ++) {\n        cout <<\
    \ get<0>(quotients[i]) << (i < quotients.size() ? \" \" : \"\");\n    }\n    cout\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#include\"../../../Integer/Quotients.hpp\"\
    \n\nint main() {\n    ll N; cin >> N;\n    auto quotients = Quotients(N);\n\n\
    \    reverse(quotients.begin(), quotients.end());\n    cout << quotients.size()\
    \ << endl;\n    for (int i = 0; i < quotients.size(); i ++) {\n        cout <<\
    \ get<0>(quotients[i]) << (i < quotients.size() ? \" \" : \"\");\n    }\n    cout\
    \ << endl;\n}\n"
  dependsOn:
  - Integer/Quotients.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  requiredBy: []
  timestamp: '2025-09-13 11:11:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
- /verify/verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp.html
title: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
---
