#define PROBLEM "https://yukicoder.me/problems/no/1255"

#include"../../template/template.hpp"
#include"../../Modulo/Order.hpp"

int main() {
    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        ll N; cin >> N;
        cout << Modulo::Order(Modulo::Modulo(2, 2 * N - 1)) << endl;
    }
}
