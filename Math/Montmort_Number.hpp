#include"../template/template.hpp"
#include"../Modulo/Modulo.hpp"

using namespace modulo;

vector<Modulo>Montmort_Number(int N, const ll M) {
    if (N == 0) { return vector<Modulo>({{1, M}}); }

    vector<Modulo> montmort(N + 1);
    montmort[0] = Modulo(1, M); montmort[1] = Modulo(0, M);

    for (int k = 2; k <= N; k++) {
        montmort[k] = k * montmort[k - 1] + (k % 2 == 0 ? 1 : -1);
    }

    return montmort;
}
