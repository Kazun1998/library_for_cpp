#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

#include "../../../template/template.hpp"
#include "../../../Algebra/modint.hpp"
#include "../../../Math/Sum_of_Exponential_Times_Polynomial.hpp"

using mint = modint<998244353>;

mint verify() {
    mint r; int d; ll n;
    cin >> r >> d >> n;
    return Sum_of_Exponential_Times_Polynomial(r, d, n - 1);
}

int main() {
    cout << verify() << endl;
}
