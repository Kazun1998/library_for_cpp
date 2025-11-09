#define PROBLEM "https://yukicoder.me/problems/no/1984"

#include"../../template/template.hpp"
#include"../../Max_Flow/Project_Selection_Problem.hpp"

using namespace projection_selection_problem;

void verify() {
    // 変数代入
    int N, M, K, P; cin >> N >> M >> K >> P;
    vector<ll> E(N + 1), F(M + 1), V(K + 1);
    for (int i = 1; i <= N; i++) { cin >> E[i]; }
    for (int j = 1; j <= M; j++) { cin >> F[j]; }
    for (int k = 1; k <= K; k++) { cin >> V[k]; }

    vector<int> L(N + 1);
    vector<vector<int>> A(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> L[i];
        A[i].resize(L[i]);
        for (int t = 0; t < L[i]; t++) { cin >> A[i][t]; }
    }

    vector<int> I(P), J(P);
    for (int p = 0; p < P; p++) { cin >> I[p] >> J[p]; }

    // 最小カットの設定
    Project_Selection_Problem<ll> B(N + M + K);
    vector<int> X(N + 1), Y(M + 1), Z(K + 1);

    iota(X.begin() + 1, X.end(), 0);
    iota(Y.begin() + 1, Y.end(), N );
    iota(Z.begin() + 1, Z.end(), N + M );

    auto inf = Extended_Algebra<ll>::inf;

    for (int i = 1; i <= N; i++) {
        B.set_one(X[i], E[i]);
        for (int a: A[i]) {
            B.set_zero_one(Z[a], X[i], -inf);
        }
    }

    for (int j = 1; j <= M; j++) {
        B.set_zero(Y[j], F[j]);
    }

    for (int p = 0; p < P; p++) { B.set_zero_one(Y[J[p]], X[I[p]], -inf); }
    for (int k = 1; k <= K; k++) { B.set_one(Z[k], -V[k]); }

    // 最小カットを解く.
    B.solve();
    auto choice = B.choice;

    // 解の計算
    vector<int> goals, actions, preparations;
    for (int i = 1; i <= N; i++) {
        if (choice[X[i]]) goals.emplace_back(i);
    }

    for (int j = 1; j <= M; j++) {
        if (!choice[Y[j]]) actions.emplace_back(j);
    }

    for (int k = 1; k <= K; k++) {
        if (choice[Z[k]]) preparations.emplace_back(k);
    }

    // 解の出力
    cout << B.ans << endl;
    cout << (goals.size() + actions.size() + preparations.size()) << endl;

    for (int k: preparations) { cout << "Preparation " << k << endl; }
    for (int i: goals) { cout << "Goal " << i << endl; }
    for (int j: actions) { cout << "Action " << j << endl; }
}

int main() {
    verify();
}
