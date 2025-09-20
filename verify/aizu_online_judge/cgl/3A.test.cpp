#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_A"

#include"../../../template/template.hpp"
#include"../../../Geometry/Polygon.hpp"

using namespace geometry;

int main() {
    using namespace geometry;

    int n; cin >> n;
    vector<Point<Real>> vertices;
    for (int i = 1; i <= n; i++) {
        Point<Real> P; cin >> P;
        vertices.emplace_back(P);
    }

    Polygon<Real> X(vertices);

    cout << fixed << setprecision(1) << Area(X) << endl;
}
