#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#define ERROR 0.00000001

#include"../../../template/template.hpp"
#include"../../../Geometry/projection/Projection_Point_Line.hpp"

using namespace geometry;

int main() {
    Line<Real> l; cin >> l.A >> l.B;

    int Q; cin >> Q;
    cout << fixed << setprecision(10);
    for (int q = 0; q < Q; q++) {
        Point<Real> P; cin >> P;
        cout << Projection(P, l) << endl;
    }
}
