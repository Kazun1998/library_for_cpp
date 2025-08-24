---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Digraph.hpp
    title: Graph/Digraph/Digraph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Strongly_Connected_Components.hpp
    title: Graph/Digraph/Strongly_Connected_Components.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 2 \"template/template.hpp\"\
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
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u9664\
    \u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x >\
    \ 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y\
    \ - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x, U y){\n    T\
    \ q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\
    \u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n \
    \   return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q, r;\n \
    \   tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n\
    }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\
    \u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n\
    \        if (y & 1) { a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n  \
    \  return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n\
    \    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n\
    \    for (auto &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T>\
    \ &X){\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\
    #line 62 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
    \n// \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ...\
    \ >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout\
    \ << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
    \    return is;\n}\n\ntemplate<typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &P){\n    os << P.first << \" \" << P.second;\n    return\
    \ os;\n}\n\ntemplate<typename T>\nvector<T> vector_input(int N, int index){\n\
    \    vector<T> X(N+index);\n    for (int i=index; i<index+N; i++) cin >> X[i];\n\
    \    return X;\n}\n\ntemplate<typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &X){\n    for (auto &x: X) { is >> x; }\n    return is;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &X){\n    int s = (int)X.size();\n\
    \    for (int i = 0; i < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return\
    \ os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const unordered_set<T>\
    \ &S){\n    int i = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n\
    \    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ set<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a;\
    \ i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os\
    \ << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\n\
    ostream &operator<<(ostream &os, const multiset<T> &S){\n    int i = 0;\n    for\
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n#line 65\
    \ \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\n\n//\
    \ \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n#define unless(cond) if (!(cond))\n\
    \n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1,\
    \ _2, name, ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define\
    \ overload4(_1, _2, _3, _4, name, ...) name\n#define overload5(_1, _2, _3, _4,\
    \ _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for\
    \ (ll i = 0; i < n; i++)\n#define rep2(i, n) for (ll i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (ll i = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i\
    \ = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2,\
    \ rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x: a)\n#define foreach2(x,\
    \ y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y,\
    \ z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define\
    \ foreach(...) overload5(__VA_ARGS__, foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n\
    #line 2 \"Graph/Digraph/Digraph.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace Digraph {\n  struct Arc {\n    int id, source, target;\n\n\
    \    Arc(int id, int source, int target): id(id), source(source), target(target)\
    \ {}\n  };\n\n  class Digraph {\n    private:\n    int arc_id_offset;\n    vector<vector<int>>\
    \ adjacent_out, adjacent_in;\n    vector<Arc> arcs;\n\n    public:\n    Digraph(int\
    \ n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {\n        adjacent_out.assign(n,\
    \ {});\n        adjacent_in.assign(n, {});\n        arcs.resize(arc_id_offset,\
    \ Arc(-1, -1, -1));\n      }\n    \n    inline int order() const { return int(adjacent_in.size());\
    \ }\n\n    inline int size() const { return int(arcs.size()) - arc_id_offset;\
    \ }\n\n    // \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u91CD\u307F\
    \ w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B.\n    int add_arc(int u, int v){\n\
    \      int id = int(arcs.size());\n\n      adjacent_out[u].emplace_back(id);\n\
    \      adjacent_in[v].emplace_back(id);\n      arcs.emplace_back(id, u, v);\n\n\
    \      return id;\n    }\n\n    // \u9802\u70B9 u \u304B\u3089\u51FA\u308B\u5F27\
    \u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\n    inline const std::vector<int>&\
    \ successors(int u) const { return adjacent_out[u]; }\n\n    // \u9802\u70B9 u\
    \ \u306B\u5165\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\
    \n    inline const std::vector<int>& predecessors(int u) const { return adjacent_in[u];\
    \ }\n\n    // \u5F27 ID \u304C id \u3067\u3042\u308B\u5F27\u3092\u53D6\u5F97\u3059\
    \u308B.\n    inline const Arc& get_arc(int id) const { return arcs[id]; }\n  \
    \  inline Arc& get_arc(int id) { return arcs[id]; }\n  };\n}\n#line 2 \"Graph/Digraph/Strongly_Connected_Components.hpp\"\
    \n\nnamespace Digraph {\n    class Strongly_Connected_Components {\n        public:\n\
    \        vector<vector<int>> components;\n        vector<int> group;\n\n     \
    \   private:\n        vector<int> order;\n        vector<bool> used;\n\n     \
    \   public:\n        Strongly_Connected_Components(const Digraph &D) {\n     \
    \       int n = D.order();\n\n            used.assign(n, false);\n\n         \
    \   for (int i = 0; i < n; i++) {\n                unless(used[i]) { dfs1(D, i);\
    \ }\n            }\n\n            reverse(all(order));\n            group.assign(n,\
    \ -1);\n\n            for (int v: order) {\n                unless(group[v] ==\
    \ -1) { continue; }\n\n                components.emplace_back(vector<int>());\n\
    \                dfs2(D, v);\n            }\n        }\n\n        private:\n \
    \       void dfs1(const Digraph &D, int v) {\n            used[v] = true;\n  \
    \          for (auto arc_id: D.successors(v)) {\n                auto arc = D.get_arc(arc_id);\n\
    \                int w = arc.target;\n\n                unless(used[w]) { dfs1(D,\
    \ w); }\n            }\n\n            order.emplace_back(v);\n        }\n\n  \
    \      void dfs2(const Digraph &D, int v) {\n            components[group[v] =\
    \ components.size() - 1].emplace_back(v);\n\n            for (auto arc_id: D.predecessors(v))\
    \ {\n                auto arc = D.get_arc(arc_id);\n                int w = arc.source;\n\
    \                if (group[w] == -1) { dfs2(D, w); }\n            }\n        }\n\
    \    };\n}\n#line 5 \"verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp\"\
    \n\nint main() {\n    int N, M; cin >> N >> M;\n    auto D = Digraph::Digraph(N);\n\
    \n    for (int j = 0; j < M; j++) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n\
    \        D.add_arc(a, b);\n    }\n\n    auto S = Digraph::Strongly_Connected_Components(D);\n\
    \n    cout << S.components.size() << endl;\n    for (auto component: S.components)\
    \ {\n        cout << component.size();\n        for (int v: component) {\n   \
    \         cout << \" \" << v;\n        }\n\n        cout << \"\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include\"../../../template/template.hpp\"\
    \n#include\"../../../Graph/Digraph/Strongly_Connected_Components.hpp\"\n\nint\
    \ main() {\n    int N, M; cin >> N >> M;\n    auto D = Digraph::Digraph(N);\n\n\
    \    for (int j = 0; j < M; j++) {\n        int a, b; scanf(\"%d%d\", &a, &b);\n\
    \        D.add_arc(a, b);\n    }\n\n    auto S = Digraph::Strongly_Connected_Components(D);\n\
    \n    cout << S.components.size() << endl;\n    for (auto component: S.components)\
    \ {\n        cout << component.size();\n        for (int v: component) {\n   \
    \         cout << \" \" << v;\n        }\n\n        cout << \"\\n\";\n    }\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - Graph/Digraph/Strongly_Connected_Components.hpp
  - Graph/Digraph/Digraph.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  requiredBy: []
  timestamp: '2025-08-23 11:25:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
- /verify/verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp.html
title: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
---
