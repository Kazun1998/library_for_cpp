---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Miller_Rabin_Primality_Test.hpp
    title: Integer/Miller_Rabin_Primality_Test.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Prime.hpp
    title: Integer/Prime.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line\
    \ 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n//\
    \ a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
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
    \    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n// a\
    \ x + b y = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b)\
    \ \u306B\u5BFE\u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntuple<ll,\
    \ ll, ll> Extended_Euclid(ll a, ll b) {\n    ll s = 1, t = 0, u = 0, v = 1;\n\
    \    while (b) {\n        ll q;\n        tie(q, a, b) = make_tuple(div_floor(a,\
    \ b), b, mod(a, b));\n        tie(s, t) = make_pair(t, s - q * t);\n        tie(u,\
    \ v) = make_pair(v, u - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\
    \n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F,\
    \ 0 \u3068\u3059\u308B).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0;\
    \ }\n\n    ll x = sqrt(N);\n    while ((x + 1) * (x + 1) <= N) { x++; }\n    while\
    \ (x * x > N) { x--; }\n\n    return x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\
    \u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const\
    \ ll &N) { return isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N\
    \ < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll\
    \ &N) {\n    ll x = isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line 62\
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
    \ foreach2, foreach1)(__VA_ARGS__)\n#line 2 \"Integer/Miller_Rabin_Primality_Test.hpp\"\
    \n\n#line 2 \"Integer/Prime.hpp\"\n\nnamespace Prime {\n  class Pseudo_Prime_Generator\
    \ {\n    private:\n    long long prime = 1, step = 0;\n\n    public:\n    long\
    \ long get() {\n      if (step) {\n        prime += step;\n        step = 6 -\
    \ step;\n      }\n      else if (prime == 1) { prime = 2; }\n      else if (prime\
    \ == 2) { prime = 3; }\n      else if (prime == 3) { prime = 5, step = 2; }\n\n\
    \      return prime;\n    }\n  };\n\n  // n \u306F\u7D20\u6570?\n  bool is_prime(long\
    \ long n) {\n    if (n <= 3) { return n >= 2; }\n    else if (n == 5) { return\
    \ true; }\n    else if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return\
    \ false; }\n\n    Pseudo_Prime_Generator generator;\n    for (long long p = generator.get();\
    \ p * p <= n; p = generator.get()) {\n      if (n % p == 0) { return false; }\n\
    \    }\n\n    return true;\n  }\n\n  pair<long long, long long> exponents(long\
    \ long n, long long p) {\n    long long e = 0;\n    while (n % p == 0) { e++,\
    \ n /= p; }\n    return {e, n};\n  }\n\n  // \u7D20\u56E0\u6570\u5206\u89E3\n\
    \  vector<pair<long long, long long>> prime_factorization (long long n) {\n  \
    \  if (n == 0) { return { make_pair(0, 0) }; } \n\n    vector<pair<long long,\
    \ long long>> factors;\n    if (n < 0) {\n      factors.emplace_back(make_pair(-1,\
    \ 1));\n      n = abs(n);\n    }\n\n    Pseudo_Prime_Generator generator;\n  \
    \  for (long long p =generator.get(); p * p <= n; p = generator.get()) {\n   \
    \   long long e;\n      tie(e, n) = exponents(n, p); \n      if (e) { factors.emplace_back(make_pair(p,\
    \ e)); }\n    }\n\n    if (n > 1) { factors.emplace_back(make_pair(n, 1)); }\n\
    \  \n    return factors;\n  }\n\n  // n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\
    \u30B9\u30C8\u3092\u4F5C\u6210\u3059\u308B.\n  vector<long long> prime_list(long\
    \ long n) {\n    if (n == 0 || n == 1) { return {}; }\n    else if (n == 2) {\
    \ return {2}; }\n\n    if (n % 2 == 0) { n--; }\n\n    long long m = (n + 1) /\
    \ 2;\n\n    // prime_flag[k] := (2k+1) \u306F\u7D20\u6570\u304B?\n    vector<bool>\
    \ prime_flag(m, true);\n    prime_flag[0] = false;\n\n    // 9 \u4EE5\u4E0A\u306E\
    \ 3 \u306E\u500D\u6570\u3092\u6D88\u3059.\n    for (long long x = 4; x < m; x\
    \ += 3) { prime_flag[x] = false; }\n\n    auto generator = Pseudo_Prime_Generator();\n\
    \    for (auto p = generator.get(); p * p <= n; p = generator.get()) {\n     \
    \ if (p <= 3) { continue; }\n\n      if (!prime_flag[(p - 1) / 2]) { continue;\
    \ }\n\n      for (auto j = (p * p - 1) / 2; j < m; j += p) { prime_flag[j] = false;\
    \ }\n    }\n\n    vector<long long> primes{2};\n\n    for (long long k = 0; k\
    \ < m; k++) {\n      if (prime_flag[k]) { primes.emplace_back(2 * k + 1); }\n\
    \    }\n\n    return primes;\n  }\n}\n#line 5 \"Integer/Miller_Rabin_Primality_Test.hpp\"\
    \n\n// N \u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\
    .\nbool Miller_Rabin_Primality_Test(ll N, int trial = 30) {\n    if (N == 2) {\
    \ return true; }\n    if (N == 1 || N % 2 == 0) { return false; }\n\n    ll q;\
    \ int k;\n    tie (k, q) = Prime::exponents(N - 1, 2);\n\n    random_device device;\n\
    \    mt19937_64 gen(device());\n    uniform_int_distribution<ll> distribute(2,\
    \ N - 1);\n\n    auto challenge = [&]() -> bool {\n        __int128_t m = distribute(gen);\n\
    \        auto y = modpow(m, q, (__int128_t)N);\n\n        if (y == 1) { return\
    \ true; }\n\n        rep(k) {\n            if ((y + 1) % N == 0) { return true;\
    \ }\n\n            y *= y; y %= N;\n        }\n\n        return false;\n    };\n\
    \n    rep(trial) { unless(challenge()) { return false; } }\n\n    return true;\n\
    }\n#line 5 \"verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp\"\
    \n\nint main(){\n    int Q; cin >> Q;\n    for (int q = 1; q <= Q; q++) {\n  \
    \      ll N; scanf(\"%lld\", &N);\n        cout << (Miller_Rabin_Primality_Test(N,\
    \ 10) ? \"Yes\" : \"No\") << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../Integer/Miller_Rabin_Primality_Test.hpp\"\
    \n\nint main(){\n    int Q; cin >> Q;\n    for (int q = 1; q <= Q; q++) {\n  \
    \      ll N; scanf(\"%lld\", &N);\n        cout << (Miller_Rabin_Primality_Test(N,\
    \ 10) ? \"Yes\" : \"No\") << \"\\n\";\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - Integer/Miller_Rabin_Primality_Test.hpp
  - Integer/Prime.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
  requiredBy: []
  timestamp: '2025-09-27 09:56:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
- /verify/verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp.html
title: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
---
