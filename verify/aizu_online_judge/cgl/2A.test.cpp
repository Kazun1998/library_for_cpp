#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include"../../../template/template.hpp"
#include"../../../Geometry/relationship/Parallel_Orthogonal_Line_Line.hpp"

using namespace geometry;

int main() {
    using namespace geometry;

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        Line<int> l, m; cin >> l.A >> l.B >> m.A >> m.B;

        switch (Parallel_Orthogonal(l, m)) {
            case Direction_Relation::PARALLEL:
                cout << 2 << endl;
                break;
            case Direction_Relation::ORTHOGONAL:
                cout << 1 << endl;
                break;
            case Direction_Relation::CROSS:
                cout << 0 << endl;
                break;
        }
    }
}
