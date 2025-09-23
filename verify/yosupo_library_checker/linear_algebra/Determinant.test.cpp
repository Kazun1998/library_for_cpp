#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Linear_Algebra/Field_Matrix.hpp"

int main(){
    int N; cin >> N;
    Field_Matrix<modint<998244353>> A(N);
    cin >> A;
    cout << Determinant(A) << endl;
}
