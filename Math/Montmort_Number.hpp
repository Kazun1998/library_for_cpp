#include"../template/template.hpp"

template<typename mint>
vector<mint>Montmort_Number(int N) {
    if (N == 0) { return vector<mint>({1}); }

    vector<mint> montmort(N + 1);
    montmort[0] = mint(1); montmort[1] = mint(0);

    for (int k = 2; k <= N; k++) {
        montmort[k] = k * montmort[k - 1] + (k % 2 == 0 ? 1 : -1);
    }

    return montmort;
}
