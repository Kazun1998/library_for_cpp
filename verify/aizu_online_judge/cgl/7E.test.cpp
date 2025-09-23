#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.000001

#include"../../../template/template.hpp"
#include"../../../Geometry/intersection/Intersection_Circle_and_Circle.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);
    Point<Real> p, q;
    Real r, s;
    cin >> p >> r >> q >> s;

    Circle<Real> C(p, r), D(q, s);

    vector<Point<Real>> intersections = Intersection(C, D);
    unless(compare_x(intersections[0], intersections[1])) {
        swap(intersections[0], intersections[1]);
    }

    cout << intersections[0] << " " << intersections[1] << endl;
}
