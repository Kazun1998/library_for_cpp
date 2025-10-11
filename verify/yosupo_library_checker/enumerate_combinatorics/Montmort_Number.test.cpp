#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include"../../../Math/Montmort_Number.hpp"

int main() {
    int N, M; cin >> N >> M;
    auto b = Montmort_Number(N, M);
    for (int k = 1; k <= N; k++) { cout << b[k].a << (k < N ? " " : ""); }
    cout << endl;
}
