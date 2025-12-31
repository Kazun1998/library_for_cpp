#include"template/template.hpp"
#include"Integer/Smallest_Prime_Factor.hpp"

int main() {
    int n = 100;
    prime::Smallest_Prime_Factor S(n);

    for (int x = 1; x <= n; x++) {
        cout << x << " " << S.prime_factorization(x) << endl;
    }
}
