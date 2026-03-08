#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Partition_P.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    cout << Partitions_P<mint>(N) << endl;
}
