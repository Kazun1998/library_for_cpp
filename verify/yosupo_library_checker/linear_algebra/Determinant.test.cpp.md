---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algebra/Field_Matrix.hpp
    title: Algebra/Field_Matrix.hpp
  - icon: ':heavy_check_mark:'
    path: modint.hpp
    title: modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#line 2 \"modint.hpp\"\n\ntemplate<int mod>\nclass modint{\n\
    \    public:\n    int64_t x;\n\n    public:\n    // \u521D\u671F\u5316\n    constexpr\
    \ modint(): x(0) {}\n    constexpr modint(int64_t a): x((a % mod + mod) % mod)\
    \ {}\n\n    // \u30DE\u30A4\u30CA\u30B9\u5143\n    modint operator-() const {\
    \ return modint(-x); }\n\n    // \u52A0\u6CD5\n    modint& operator+=(const modint\
    \ &b){\n        if ((x += b.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \n    friend modint operator+(const modint &x, const modint &y) { return modint(x)\
    \ += y; }\n\n    // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n \
    \       if ((x += mod - b.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \n    friend modint operator-(const modint &x, const modint &y) { return modint(x)\
    \ -= y; }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n \
    \       (x *= b.x) %= mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator*(const modint &x, const modint &y) { return modint(x) *= y; }\n\n \
    \   // \u9664\u6CD5\n    modint& operator/=(const modint &b){ return (*this) *=\
    \ b.inverse(); }\n\n    friend modint operator/(const modint &x, const modint\
    \ &y) { return modint(x) /= y; }\n\n    modint inverse() const {\n        int64_t\
    \ s = 1, t = 0;\n        int64_t a = x, b = mod;\n\n        while (b > 0) {\n\
    \            int64_t q = a / b;\n\n            a -= q * b; swap(a, b);\n     \
    \       s -= q * t; swap(s, t);\n        }\n\n        assert (a == 1);\n\n   \
    \     return modint(s);\n    }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const\
    \ modint &a, const modint &b) { return (a.x == b.x); }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n\
    \    friend istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n\
    \        a.x = (a.x % mod + mod) % mod;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const modint &a) { return\
    \ os << a.x; }\n};\n#line 2 \"Algebra/Field_Matrix.hpp\"\n\nclass SingularMatrixError:\
    \ private exception{\n    const char* what() const throw() {\n        return \"\
    \u975E\u6B63\u5247\u884C\u5217\u306B\u95A2\u3059\u308B\u64CD\u4F5C\u3092\u884C\
    \u3044\u307E\u3057\u305F.\";\n    }\n};\n\ntemplate<typename F>\nclass Field_Matrix{\n\
    \    private:\n    vector<vector<F>> mat;\n\n    public:\n    int row, col;\n\n\
    \    public:\n    Field_Matrix(int row, int col): row(row), col(col){\n      \
    \  mat.assign(row, vector<F>(col, F()));\n    }\n\n    Field_Matrix(int row):\
    \ Field_Matrix(row, row){}\n\n    Field_Matrix(vector<vector<F>> &ele): Field_Matrix(ele.size(),\
    \ ele[0].size()){\n        for (int i = 0; i < row; i++){\n            copy(ele[i].begin(),\
    \ ele[i].end(), mat[i].begin());\n        }\n    }\n\n    static Field_Matrix\
    \ Zero_Matrix(int row, int col) { return Field_Matrix(row, col); }\n\n    static\
    \ Field_Matrix Identity_Matrix(int size) {\n        Field_Matrix A(size);\n  \
    \      for (int i = 0; i < size; i++) { A[i][i] = 1; }\n        return A;\n  \
    \  }\n\n    // \u30B5\u30A4\u30BA\n    pair<int, int> size() { return make_pair(row,\
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
    \ det;\n}\n#line 9 \"verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    Field_Matrix<modint<998244353>> A(N);\n\
    \    cin >> A;\n    cout << Determinant(A) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#include\"../../../modint.hpp\"\n#include\"../../../Algebra/Field_Matrix.hpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    Field_Matrix<modint<998244353>> A(N);\n\
    \    cin >> A;\n    cout << Determinant(A) << endl;\n}\n"
  dependsOn:
  - modint.hpp
  - Algebra/Field_Matrix.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
  requiredBy: []
  timestamp: '2025-08-16 23:39:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
- /verify/verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp.html
title: verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
---
