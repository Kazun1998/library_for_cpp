---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Algebra/Gaussian_Integer.hpp
    title: Algebra/Gaussian_Integer.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Divisors.hpp
    title: Integer/Divisors.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Quotients.hpp
    title: Integer/Quotients.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Floor_Linear_Sum.hpp
    title: Math/Floor_Linear_Sum.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Two_SAT.hpp
    title: Math/Two_SAT.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Discrete_Log.hpp
    title: Modulo/Discrete_Log.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Modulo.hpp
    title: Modulo/Modulo.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Order.hpp
    title: Modulo/Order.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Tree.hpp
    title: Tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
    title: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
    title: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
    title: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
    title: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
    title: verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
    title: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/other/two_sat.test.cpp
    title: verify/yosupo_library_checker/other/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
    title: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/Modulo_Order.test.cpp
    title: verify/yukicoder/Modulo_Order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class...\
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
    \ \": \"\") << a; i++; }\n    return os;\n}\n"
  code: "// \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >>\
    \ ... >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class...\
    \ Ts>\nvoid print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ...\
    \ << (cout << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename\
    \ U>\nistream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
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
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/inout.hpp
  requiredBy:
  - Modulo/Modulo.hpp
  - Modulo/Order.hpp
  - Modulo/Discrete_Log.hpp
  - Tree/Tree.hpp
  - Algebra/Gaussian_Integer.hpp
  - Math/Two_SAT.hpp
  - Math/Floor_Linear_Sum.hpp
  - Integer/Divisors.hpp
  - Integer/Quotients.hpp
  - template/template.hpp
  timestamp: '2025-08-17 13:03:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/Modulo_Order.test.cpp
  - verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
  - verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  - verify/yosupo_library_checker/other/two_sat.test.cpp
documentation_of: template/inout.hpp
layout: document
redirect_from:
- /library/template/inout.hpp
- /library/template/inout.hpp.html
title: template/inout.hpp
---
