#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D"

#include"../../../template/template.hpp"
#include"../../../Calculate/Slide_Maximum.hpp"

int main() {
    int N, L; cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }

    auto b = Slide_Maximum_Value(a, L);
    for (int j = 0; j < N - L + 1; ++j) {
        cout << (j ? " " : "") << -b[j];
    }
    cout << "\n";
}
