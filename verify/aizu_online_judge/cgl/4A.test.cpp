#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A"

#include"../../../template/template.hpp"
#include"../../../Geometry/Convex_Hull.hpp"

using namespace geometry;

int main() {

    int n; cin >> n;
    vector<Point<int>> points(n); cin >> points;

    auto X = Convex_Hull(points, false);

    int argmin = 0;
    for (int i = 1; i < X.n; i++) {
        if (compare_y(X.vertices[i], X.vertices[argmin])) { argmin = i; }
    }

    cout << X.n << endl;
    for (int k = 0; k < X.n; k++) {
        cout << X.vertices[(k + argmin) % X.n] << endl;
    }
}
