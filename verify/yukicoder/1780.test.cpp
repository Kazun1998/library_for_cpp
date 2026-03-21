#define PROBLEM "https://yukicoder.me/problems/no/1780"

#include "../../template/template.hpp"
#include "../../Algebra/Extended_Algebra.hpp"
#include "../../Algebra/Semiring_Matrix.hpp"

using ell = Extended_Algebra<ll>;
using Mat = Tropical_Max_Matrix<ll>;
int color = 16, member = 26;

ell solve() {
    vector<int> C(member); cin >> C;
    vector<int> K(member); cin >> K;

    vector<Mat> mat(member, Mat::identity(color));
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        string S; int A, B; ll E;
        cin >> S >> A >> B >> E;
        --A; --B;
        for (auto z: S) {
            chmax(mat[z - 'A'][A, B], ell(E));
            chmax(mat[z - 'A'][B, A], ell(E));
        }
    }

    vector<ell> V(color);
    for (int z = 0; z < member; ++z) {
        Mat tmp = power(mat[z], K[z]);
        for (int c = 0; c < color; ++c) {
            V[c] += tmp[C[z] - 1, c];
        }
    }

    ell ans = -ell::inf;
    for (const auto& v : V) {
        chmax(ans, v);
    }
    return ans;
}

int main() {
    ell ans = solve();
    if (ans.is_negative_infinite()) cout << "Impossible" << endl;
    else cout << ans << endl;
}
