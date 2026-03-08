#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include"../../../template/template.hpp"
#include"../../../Geometry/relationship/Relationship_Circle_and_Circle.hpp"

using namespace geometry;

int main() {
    Circle<Real> C, D;

    cin >> C.center >> C.radius;
    cin >> D.center >> D.radius;
    
    cout << Relationship(C, D) << endl;
}
