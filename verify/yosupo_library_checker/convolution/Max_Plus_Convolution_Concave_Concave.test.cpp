#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "../../../template/template.hpp"
#include "../../../Convolution/Max_Plus_Convolution_Concave.hpp"

// 符号を反転すると, 下に凸な列は上に凸な列になる.
// -a, -b に対する max-plus 畳み込みの符号を反転したものが, a, b の min-plus 畳み込みである.
vector<int> verify() {
    int N, M; cin >> N >> M;
    vector<int> a(N), b(M);
    cin >> a >> b;

    for (auto &x: a) { x = -x; }
    for (auto &x: b) { x = -x; }

    assert(convolution::Max_Plus_Convolution_Concave<int>::is_concave(a));
    assert(convolution::Max_Plus_Convolution_Concave<int>::is_concave(b));

    vector<int> c = convolution::Max_Plus_Convolution_Concave<int>::convolve(a, b);
    for (auto &x: c) { x = -x; }

    return c;
}

int main() {
    cout << verify() << endl;
}
