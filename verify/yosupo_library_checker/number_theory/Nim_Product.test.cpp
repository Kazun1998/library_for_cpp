#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include "../../../template/template.hpp"
#include "../../../Algebra/Nimber.hpp"

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        uint64_t a, b; scanf("%llu%llu", &a, &b);
        cout << Nimber(a) * Nimber(b) << "\n";
    }
}
