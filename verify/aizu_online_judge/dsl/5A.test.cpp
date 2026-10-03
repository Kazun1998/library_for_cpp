#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A"

#include"../../../template/template.hpp"
#include"../../../Imos/Imos_1.hpp"

int verify() {
    int N, T; cin >> N >> T;

    Imos_1<int> I(T + 1);

    for (int i = 1; i <= N; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        I.add(l, r - 1);
    }

    return max(I.cumulate());
}

int main() {
    cout << verify() << endl;
}
