#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include"../../../template/template.hpp"
#include"../../../Geometry/relationship/Relationship_Circle_and_Circle.hpp"

using namespace geometry;

int main() {
    Point<Real> A, B;
    Real r, s;

    cin >> A >> r;
    cin >> B >> s;

    Circle<Real> C(A, r), D(B, s);
    cout << Relationship(C, D) << endl;
}
