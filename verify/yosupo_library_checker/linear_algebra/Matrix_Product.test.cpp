#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include<bits/stdc++.h>

using namespace std;

#include"../../../modint.hpp"
#include"../../../Algebra/Field_Matrix.hpp"

int main(){
    int N, M, K; cin >> N >> M >> K;
    Field_Matrix<modint<998244353>> A(N, M), B(M, K);
    cin >> A >> B;
    cout << A * B << endl;
}
