#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "../../../template/template.hpp"
#include "../../../Convolution/Min_Plus_Convolution_Convex.hpp"

vector<int> verify() {
    int N, M; cin >> N >> M;
    vector<int> a(N), b(M);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < M; ++j) {
        scanf("%d", &b[j]);
    }

    return convolution::Min_Plus_Convolution_Convex<int>::convolve(a, b);
}

int main() {
    cout << verify() << endl;
}
