#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include"../../../template/template.hpp"
#include"../../../Math/Two_SAT.hpp"

int main(){
    string p, cnf; cin >> p >> cnf;
    int N, M; cin >> N >> M;
    Two_SAT T(N + 1);

    for (int j = 1; j <= M; j++){
        int a, b, zero;
        bool f, g;
        scanf("%d%d%d", &a, &b, &zero);

        if (a > 0) { f = true; }
        else { a = -a, f = false; }

        if (b > 0) { g = true; }
        else { b = -b, g = false; }

        T.add_or(a, f, b, g);
    }

    unless(T.solve()) {
        cout << "s UNSATISFIABLE\n";
        return 0;
    }

    cout << "s SATISFIABLE\n";
    cout << "v";
    vector<bool> V = T.answer;
    for (int i = 1; i <=N ; i++){
        cout << " " << (V[i]? i:-i);
    }
    cout << " 0\n";
}
