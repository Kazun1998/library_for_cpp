#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include"../../../template/template.hpp"
#include"../../../Integer/Pollard_Rho.hpp"

int main() {
    int Q; cin >> Q;
    for (int q = 1; q <= Q; ++q) {
        ll a; cin >> a;
        auto factors = Prime_Factorization_by_Pollard_Rho(a);
        sort(factors.begin(), factors.end());

        vector<uint64_t> primes;
        for (auto [p, e]: factors) {
            rep(e) primes.emplace_back(p);
        }

        cout << primes.size() << " " << primes << endl;
    }
}
