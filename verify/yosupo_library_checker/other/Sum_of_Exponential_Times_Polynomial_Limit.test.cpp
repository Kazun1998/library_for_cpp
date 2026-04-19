#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include "../../../template/template.hpp"
#include "../../../Algebra/modint.hpp"
#include "../../../Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp"

using mint = modint<998244353>;

mint verify() {
    mint r; int d;
    cin >> r >> d;
    return Sum_of_Exponential_Times_Polynomial_Limit(r, d);
}

int main() {
    cout << verify() << endl;
}
