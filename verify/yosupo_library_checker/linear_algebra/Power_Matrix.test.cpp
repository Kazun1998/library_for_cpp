#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Linear_Algebra/Field_Matrix.hpp"

int main(){
    int N; cin >> N;
    ll K; cin >> K;
    Field_Matrix<modint<998244353>> A(N);
    cin >> A;
    cout << power(A, K) << endl;
}
