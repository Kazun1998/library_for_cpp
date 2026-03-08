#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#define ERROR 0.00000001

#include"../../../template/template.hpp"
#include"../../../Geometry/intersection/Intersection_Segment_and_Segment.hpp"

using namespace geometry;

int main() {
    using namespace geometry;

    int Q; cin >> Q;
    cout << fixed << setprecision(10);
    for (int q = 0; q < Q; q++) {
        Segment<Real> s, t; cin >> s.A >> s.B >> t.A >> t.B;

        cout << Intersection(s, t) << endl;
    }
}
