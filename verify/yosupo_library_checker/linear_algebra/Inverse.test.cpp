#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include"../../../template/template.hpp"
#include"../../../modint.hpp"
#include"../../../Linear_Algebra/Field_Matrix.hpp"

int main(){
    int N; cin >> N;
    Field_Matrix<modint<998244353>> A(N);
    cin >> A;

    try {
        cout << A.inverse() << endl;
    } catch (const SingularMatrixError &error) {
        cout << -1 << endl;
    }
}
