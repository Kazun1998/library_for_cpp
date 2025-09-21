---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Linear_Algebra/Field_Matrix.hpp
    title: Linear_Algebra/Field_Matrix.hpp
  - icon: ':heavy_check_mark:'
    path: modint.hpp
    title: modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#line\
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
    #line 2 \"modint.hpp\"\n\ntemplate<int mod>\nclass modint{\n    public:\n    int64_t\
    \ x;\n\n    public:\n    // \u521D\u671F\u5316\n    constexpr modint(): x(0) {}\n\
    \    constexpr modint(int64_t a): x((a % mod + mod) % mod) {}\n\n    // \u30DE\
    \u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x); }\n\
    \n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n        if ((x\
    \ += b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator+(const modint &x, const modint &y) { return modint(x) += y; }\n\n \
    \   // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n        if ((x\
    \ += mod - b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend\
    \ modint operator-(const modint &x, const modint &y) { return modint(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n       \
    \ (x *= b.x) %= mod;\n        return *this;\n    }\n\n    friend modint operator*(const\
    \ modint &x, const modint &y) { return modint(x) *= y; }\n\n    // \u9664\u6CD5\
    \n    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }\n\n\
    \    friend modint operator/(const modint &x, const modint &y) { return modint(x)\
    \ /= y; }\n\n    modint inverse() const {\n        int64_t s = 1, t = 0;\n   \
    \     int64_t a = x, b = mod;\n\n        while (b > 0) {\n            int64_t\
    \ q = a / b;\n\n            a -= q * b; swap(a, b);\n            s -= q * t; swap(s,\
    \ t);\n        }\n\n        assert (a == 1);\n\n        return modint(s);\n  \
    \  }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const modint &a, const\
    \ modint &b) { return (a.x == b.x); }\n    friend bool operator!=(const modint\
    \ &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n    friend\
    \ istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n        a.x\
    \ = (a.x % mod + mod) % mod;\n        return is;\n    }\n\n    // \u51FA\u529B\
    \n    friend ostream &operator<<(ostream &os, const modint &a) { return os <<\
    \ a.x; }\n};\n#line 2 \"Linear_Algebra/Field_Matrix.hpp\"\n\n#line 4 \"Linear_Algebra/Field_Matrix.hpp\"\
    \n\nclass SingularMatrixError: private exception{\n    const char* what() const\
    \ throw() {\n        return \"\u975E\u6B63\u5247\u884C\u5217\u306B\u95A2\u3059\
    \u308B\u64CD\u4F5C\u3092\u884C\u3044\u307E\u3057\u305F.\";\n    }\n};\n\ntemplate<typename\
    \ F>\nclass Field_Matrix{\n    public:\n    vector<vector<F>> mat;\n    int row,\
    \ col;\n\n    public:\n    Field_Matrix(int row, int col): row(row), col(col){\n\
    \        mat.assign(row, vector<F>(col, F()));\n    }\n\n    Field_Matrix(int\
    \ row): Field_Matrix(row, row){}\n\n    Field_Matrix(vector<vector<F>> &ele):\
    \ Field_Matrix(ele.size(), ele[0].size()){\n        for (int i = 0; i < row; i++){\n\
    \            copy(ele[i].begin(), ele[i].end(), mat[i].begin());\n        }\n\
    \    }\n\n    static Field_Matrix Zero_Matrix(int row, int col) { return Field_Matrix(row,\
    \ col); }\n\n    static Field_Matrix Identity_Matrix(int size) {\n        Field_Matrix\
    \ A(size);\n        for (int i = 0; i < size; i++) { A[i][i] = 1; }\n        return\
    \ A;\n    }\n\n    // \u30B5\u30A4\u30BA\n    pair<int, int> size() { return make_pair(row,\
    \ col); }\n\n    // \u6B63\u65B9\u884C\u5217?\n    bool is_square() const { return\
    \ row == col; }\n\n    // \u8981\u7D20\n    inline const vector<F> &operator[](int\
    \ i) const { return mat[i]; }\n    inline vector<F> &operator[](int i) { return\
    \ mat[i]; }\n\n    // \u6BD4\u8F03\n    bool operator==(const Field_Matrix &B)\
    \ const {\n        if (row != B.row || col != B.col){ return false; }\n\n    \
    \    for (int i = 0; i < row; i++){\n            for (int j = 0; j < col; j++){\n\
    \                if ((*this)[i] != B[i]) return false;\n            }\n      \
    \  }\n        return true;\n    }\n\n    bool operator!=(const Field_Matrix &B)\
    \ const { return !((*this) == B); }\n\n    // \u30DE\u30A4\u30CA\u30B9\u5143\n\
    \    Field_Matrix operator-() const {\n        Field_Matrix A(row, col);\n   \
    \     for (int i = 0; i < row; i++){\n            for (int j = 0; j < col; j++)\
    \ A[i][j] = -(*this)[i][j];\n        }\n        return A;\n    }\n\n    // \u52A0\
    \u6CD5\n    Field_Matrix& operator+=(const Field_Matrix &B){\n        assert (row\
    \ == B.row && col == B.col);\n        for (int i = 0; i < row; i++){\n       \
    \     for (int j = 0; j < col; j++){\n                (*this)[i][j] += B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Field_Matrix operator+(const\
    \ Field_Matrix &B) const { return Field_Matrix(*this) += B; }\n\n    // \u6E1B\
    \u6CD5\n    Field_Matrix& operator-=(const Field_Matrix &B){\n        assert (row\
    \ == B.row && col == B.col);\n        for (int i = 0; i < row; i++){\n       \
    \     for (int j = 0; j < col; j++){\n                (*this)[i][j] -= B[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Field_Matrix operator-(const\
    \ Field_Matrix &B) const  {return Field_Matrix(*this) -= B; }\n\n    // \u4E57\
    \u6CD5\n    Field_Matrix& operator*=(const Field_Matrix &B){\n        assert (col\
    \ == B.row);\n        vector<vector<F>> C(row, vector<F>(B.col, F()));\n\n   \
    \     for (int i = 0; i < row; i++){\n            for (int k = 0; k < col; k++){\n\
    \                for (int j = 0; j < B.col; j++){\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n\n\
    \        mat.swap(C); col = B.col;\n        return *this;\n    }\n\n    Field_Matrix\
    \ operator*(const Field_Matrix &B) const { return Field_Matrix(*this)*=B; }\n\n\
    \    // \u30B9\u30AB\u30E9\u30FC\u500D\n    friend Field_Matrix operator*(const\
    \ F &scaler, const Field_Matrix &rhs){\n        Field_Matrix res(rhs);\n     \
    \   for (int i = 0; i < rhs.row; i++){\n            for (int j = 0; j < rhs.col;\
    \ j++) { res[i][j] *= scaler; }\n        }\n\n        return res;\n    }\n\n \
    \   // \u9006\u884C\u5217\n    Field_Matrix inverse(){\n        assert (is_square());\n\
    \        int N = col;\n        Field_Matrix A(*this), B(N,N);\n        for (int\
    \ i = 0; i < N; i++) B[i][i] = F(1);\n\n        for (int j = 0; j < N; j++){\n\
    \            if (A[j][j] == 0){\n                int i = j + 1;\n            \
    \    for (; i < N; i++){\n                    if (A[i][j] != 0) break;\n     \
    \           }\n\n                if (i == N) { throw SingularMatrixError(); }\n\
    \n                swap(A[i], A[j]); swap(B[i], B[j]);\n            }\n\n     \
    \       F a_inv = A[j][j].inverse();\n\n            for (int k = 0; k < N; k++){\n\
    \                A[j][k] *= a_inv;\n                B[j][k] *= a_inv;\n      \
    \      }\n\n            for (int i = 0; i < N; i++){\n                if (i ==\
    \ j) { continue; }\n\n                F c = A[i][j];\n                for (int\
    \ k = 0; k < N; k++){\n                    A[i][k] -= A[j][k] * c;\n         \
    \           B[i][k] -= B[j][k] * c;\n                }\n            }\n      \
    \  }\n\n        return B;\n    }\n\n    bool is_regular(){\n        assert (is_square());\n\
    \        int N = row;\n\n        vector<vector<F>> A(N, vector<F>(N));\n\n   \
    \     for (int i = 0; i < N; i++){\n            copy(mat[i].begin(), mat[i].end(),\
    \ A[i].begin());\n        }\n\n        for (int j = 0; j < N; j++){\n        \
    \    if (A[j][j] == 0){\n                int i = j + 1;\n                for (;\
    \ i < N; i++){\n                    if (A[i][j] != 0) break;\n               \
    \ }\n                if (i == N) return false;\n                swap(A[i], A[j]);\n\
    \            }\n\n            F a_inv = A[j][j].inverse();\n            for (int\
    \ i = j + 1; i < N; i++){\n                F c = -a_inv * A[i][j];\n\n       \
    \        for (int k = 0; k < N; k++){ A[i][k] += c * A[j][k]; }\n            }\n\
    \        }\n\n        return true;\n    }\n\n    // \u8EE2\u7F6E\n    Field_Matrix\
    \ transpose(){\n        Field_Matrix B(col, row);\n        for (int i = 0; i <\
    \ col; i++){\n            for (int j = 0; j < row; j++) B[i][j] = (*this)[j][i];\n\
    \        }\n        return B;\n    }\n\n    //\n    bool is_valid(){return (row\
    \ > 0) && (col > 0);}\n\n    // \u5165\u529B\n    friend istream &operator>>(istream\
    \ &is, Field_Matrix &A) {\n        for (int i = 0; i < A.row; i++){\n        \
    \    for (int j = 0; j < A.col; j++){\n                cin >> A[i][j];\n     \
    \       }\n        }\n        return is;\n    }\n\n    // \u51FA\u529B\n    friend\
    \ ostream &operator<<(ostream &os, const Field_Matrix &A){\n        for (int i\
    \ = 0; i < A.row; i++){\n            for (int j = 0; j < A.col; j++){\n      \
    \          cout << (j ? \" \": \"\") << A[i][j];\n            }\n            if\
    \ (i < A.row - 1) cout << \"\\n\";\n        }\n        return os;\n    }\n};\n\
    \ntemplate<typename F>\nField_Matrix<F> power(Field_Matrix<F> A, int64_t n){\n\
    \    assert (A.is_square());\n\n    if (n == 0) { return Field_Matrix<F>::Identity_Matrix(A.row);\
    \ }\n    if (n < 0) { return power(A.inverse(), -n); }\n\n    if (n % 2 == 0){\n\
    \        Field_Matrix<F> B = power(A, n / 2);\n        return B * B;\n    } else\
    \ {\n        Field_Matrix<F> B = power(A, (n - 1) / 2);\n        return A * B\
    \ * B;\n    }\n}\n\n// \u884C\u5217 A \u306E\u884C\u5217\u5F0F\u3092\u6C42\u3081\
    \u308B\ntemplate<typename F>\nF Determinant(const Field_Matrix<F> &A){\n    assert\
    \ (A.is_square());\n\n    int n = A.row;\n    F det(1);\n    Field_Matrix<F> B(A);\n\
    \n    for (int j = 0; j < n; j ++){\n        if (B[j][j] == 0){\n            int\
    \ i = j + 1;\n            for (; i < n; i++) {\n                if (B[i][j] !=\
    \ 0) { break; }\n            } \n\n            if (i == n) { return F(0); }\n\n\
    \            swap(B[i], B[j]);\n            det = -det;\n        }\n\n       \
    \ F a_inv = B[j][j].inverse();\n        for (int i = j + 1; i < n; i++){\n   \
    \         F c = -a_inv * B[i][j];\n            for (int k = 0; k < n; k++) { B[i][k]\
    \ += c * B[j][k]; }\n        }\n\n        det *= B[j][j];\n    }\n\n    return\
    \ det;\n}\n\n// \u7B2C (i, i) \u8981\u7D20\u304C a[i] \u3067\u3042\u308B\u5BFE\
    \u89D2\u884C\u5217\u3092\u751F\u6210\u3059\u308B.\ntemplate<typename F>\nField_Matrix<F>\
    \ Diagonal_Matrix(vector<F> a) {\n    int n = a.size();\n    vector<vector<F>>\
    \ X(n, vector<F>(n));\n\n    for (int i = 0; i < n; i++) { X[i][i] = a[i]; }\n\
    \n    return X;\n}\n#line 6 \"verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    Field_Matrix<modint<998244353>> A(N);\n\
    \    cin >> A;\n\n    try {\n        cout << A.inverse() << endl;\n    } catch\
    \ (const SingularMatrixError &error) {\n        cout << -1 << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../modint.hpp\"\n#include\"\
    ../../../Linear_Algebra/Field_Matrix.hpp\"\n\nint main(){\n    int N; cin >> N;\n\
    \    Field_Matrix<modint<998244353>> A(N);\n    cin >> A;\n\n    try {\n     \
    \   cout << A.inverse() << endl;\n    } catch (const SingularMatrixError &error)\
    \ {\n        cout << -1 << endl;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - modint.hpp
  - Linear_Algebra/Field_Matrix.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
  requiredBy: []
  timestamp: '2025-09-21 14:45:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
- /verify/verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp.html
title: verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
---
