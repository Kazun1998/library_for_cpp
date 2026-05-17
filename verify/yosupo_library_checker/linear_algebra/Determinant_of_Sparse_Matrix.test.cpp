#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"

#include "../../../template/template.hpp"
#include "../../../Algebra/modint.hpp"
#include "../../../Linear_Algebra/Determinant_of_Sparse_Matrix.hpp"

using mint = modint<998244353>;

mint verify() {
    int N, K; cin >> N >> K;
    vector<tuple<int, int, mint>> elements(K);
    for (int i = 0; i < K; ++i) {
        int a, b; mint c; cin >> a >> b >> c;
        elements[i] = {a, b, c};
    }

    return Determinant_of_Sparse_Matrix<mint>(N, elements);
}

int main() {
    cout << verify() << endl;
}
