#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.000001

#include"../../../template/template.hpp"
#include"../../../Geometry/tangent/Tangent_Point_from_Point_to_Circle.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);
    Point<Real> P, c;
    Real r;
    cin >> P;
    cin >> c >> r;
    Circle<Real> C(c, r);

    vector<Point<Real>> tangents = Tangent_Points(P, C);
    sort(tangents.begin(), tangents.end(), compare_x<Real>);

    for (auto tangent: tangents) {
        cout << tangent << endl;
    }
}

