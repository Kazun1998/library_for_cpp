#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../../template/template.hpp"
#include "../../../Algebra/modint.hpp"
#include "../../../Linear_Algebra/Matrix_Subspaces.hpp"

using mint = modint<998244353>;

int main() {
    int N, M; cin >> N >> M;
    Field_Matrix<mint> A(N, M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    Field_Vector<mint> b(N); cin >> b;

    auto solution = Solve_Linear_System(A, b);

    unless (solution.has_value()) {
        cout << -1 << endl;
        return 0;
    }

    auto &[x0, Ker] = solution.value();

    cout << Ker.dimension() << endl;
    cout << x0 << endl;
    for (auto &g: Ker.get_basis()) cout << g << endl;
}
