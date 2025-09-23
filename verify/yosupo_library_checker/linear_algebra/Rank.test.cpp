#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include"../../../template/template.hpp"
#include"../../../modint.hpp"
#include"../../../Linear_Algebra/Rank.hpp"

int main() {
    int N, M; cin >> N >> M;
    Field_Matrix<modint<998244353>> A(N, M); cin >> A;

    cout << Rank(A) << endl;
}
