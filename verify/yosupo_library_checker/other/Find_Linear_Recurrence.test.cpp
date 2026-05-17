#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../../template/template.hpp"
#include "../../../Algebra/modint.hpp"
#include "../../../Linear_Algebra/Find_Linear_Recurrence.hpp"

using mint = modint<998244353>;

vector<mint> verify() {
    int N; cin >> N;
    vector<mint> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    return Find_Linear_Recurrence(a);
}

int main(){
    vector<mint> c = verify();

    cout << c.size() << endl;
    cout << c << endl;
}
