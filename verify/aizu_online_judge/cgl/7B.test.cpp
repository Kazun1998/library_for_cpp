#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_B"
#define ERROR 0.000001

#include"../../../template/template.hpp"
#include"../../../Geometry/triangle_center/Incircle.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(10);
    Point<Real> A, B, C; cin >> A >> B >> C;
    auto X = Incircle(Triangle<Real>(A, B, C));
    cout << X.center << " " << X.radius << endl;
}
