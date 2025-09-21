#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#define ERROR 0.000001

#include"../../../template/template.hpp"
#include"../../../Geometry/Intersection_Circle_and_Line.hpp"

using namespace geometry;

int main() {
    cout << fixed << setprecision(15);
    Point<Real> c;
    Real r;
    cin >> c >> r;
    Circle<Real> C(c, r);

    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        Point<Real> A, B; cin >> A >> B;
        Line<Real> l(A, B);

        vector<Point<Real>> intersections = Intersection(C, l);
        unless(compare_x(intersections[0], intersections[1])) {
            swap(intersections[0], intersections[1]);
        }

        cout << intersections[0] << " " << intersections[1] << endl;
    }
}
