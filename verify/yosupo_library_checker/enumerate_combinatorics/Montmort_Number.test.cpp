#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include "../../../Algebra/dynamic_modint.hpp"
#include "../../../Math/Montmort_Number.hpp"

using mint = dynamic_modint<0>;

int main() {
    int N, M; cin >> N >> M;
    mint::set_mod(M);
    auto b = Montmort_Number<mint>(N);
    for (int k = 1; k <= N; k++) { cout << b[k].x << (k < N ? " " : ""); }
    cout << endl;
}
