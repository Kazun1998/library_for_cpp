#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR 0.00001

#include"../../../template/template.hpp"
#include"../../../Geometry/tangent/Common_Tangent_Points.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);

    Point<Real> p, q;
    Real r, s;

    cin >> p >> r >> q >> s;

    Circle<Real> C(p, r), D(q, s);

    auto tangents = Common_Tangent_Points(C, D);
    sort(tangents.begin(), tangents.end(), compare_x<Real>);
    for (auto tangent: tangents) {
        cout << tangent << endl;
    }
}
