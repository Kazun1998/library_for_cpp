#define PROBLEM "https://yukicoder.me/problems/no/1358"

#include"../../template/template.hpp"
#include"../../Algebra/modint.hpp"
#include"../../Math/Bezout.hpp"

using namespace bezout;
using mint = modint<1000000007>;

mint solve() {
    ll N, K, H, Y; cin >> N >> K >> H >> Y;
    if (N > K) swap(N, K);
    if (K > H) swap(K, H);

    mint ans(0);
    for (int z = 0; Y - z * H >= 0; z++) {
        ans += Count_Solutions(N, K, Y - z * H, 0LL, Y, 0LL, Y);
    }

    return ans;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) cout << solve() << endl;
}
