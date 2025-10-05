#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"
#include"../../../Modulo_Polynomial/Subset_Sum.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N, T; cin >> N >> T;
    vector<int> s(N); cin >> s;

    auto p = Subset_Sum<mint>(s, T);
    p.erase(p.begin());

    cout << p << endl;
}
