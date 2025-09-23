#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR 0.00001

#include"../../../template/template.hpp"
#include"../../../Geometry/tangent/Common_Tangent_Points.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);

    Circle<Real> C, D;
    cin >> C.center >> C.radius;
    cin >> D.center >> D.radius;

    auto tangents = Common_Tangent_Points(C, D);
    sort(tangents.begin(), tangents.end(), compare_x<Real>);
    for (auto tangent: tangents) {
        cout << tangent << endl;
    }
}
