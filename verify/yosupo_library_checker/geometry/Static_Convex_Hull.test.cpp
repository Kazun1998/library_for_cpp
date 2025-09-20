#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include"../../../template/template.hpp"
#include"../../../Geometry/Convex_Hull.hpp"

using namespace geometry;

void verify() {
    int N; cin >> N;
    vector<Point<ll>> points(N); cin >> points;

    auto X = Convex_Hull(points);

    cout << X.n << "\n";
    for (auto point: X.vertices) { cout << point << "\n"; }
}

int main() {
    int T; cin >> T;
    rep(T) { verify(); }
}
