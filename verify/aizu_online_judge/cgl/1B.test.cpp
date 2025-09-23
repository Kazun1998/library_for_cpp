#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#define ERROR 0.00000001

#include"../../../template/template.hpp"
#include"../../../Geometry/reflection/Reflection_Point_Line.hpp"

using namespace geometry;

int main() {
    Point<Real> A, B; cin >> A >> B;
    Line<Real> l(A, B);

    int Q; cin >> Q;
    cout << fixed << setprecision(10);
    for (int q = 0; q < Q; q++) {
        Point<Real> P; cin >> P;
        cout << Reflection(P, l) << endl;
    }
}
