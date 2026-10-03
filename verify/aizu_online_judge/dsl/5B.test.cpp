#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include"../../../template/template.hpp"
#include"../../../Imos/Imos_2.hpp"

int verify() {
    int N; cin >> N;
    int R = 1000;

    Imos_2<int> I(R + 1, R + 1);

    for (int i = 1; i <= N; ++i) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        I.add(x1, x2 - 1, y1, y2 - 1);
    }

    auto J = I.cumulate();

    int ans = 0;
    for (int i = 0; i <= R; ++i) {
        chmax(ans, max(J[i]));
    }

    return ans;
}

int main() {
    cout << verify() << endl;
}
