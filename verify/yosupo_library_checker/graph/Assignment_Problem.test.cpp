#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include"../../../template/template.hpp"
#include"../../../Calculate/Hungarian.hpp"

int main() {
    int N; cin >> N;
    vector<vector<ll>> a(N, vector<ll>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    Hungarian<ll> H(a);

    cout << H.total_cost << endl;
    cout << H.matching << endl;
}
