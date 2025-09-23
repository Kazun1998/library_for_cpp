#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.000001

#include"../../../template/template.hpp"
#include"../../../Geometry/triangle_center/Circumcircle.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);
    Triangle<Real> T; cin >> T.A >> T.B >> T.C;

    auto X = Circumcircle(T);
    cout << X.center << " " << X.radius << endl;
}
