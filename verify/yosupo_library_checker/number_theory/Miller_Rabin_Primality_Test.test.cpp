#include"../../../template/template.hpp"
#include"../../../Integer/Miller_Rabin_Primality.hpp"

int main(){
    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        ll N; scanf("%lld", &N);
        cout << (Miller_Rabin_Primality_Test(N, 10) ? "Yes" : "No") << "\n";
    }
}
