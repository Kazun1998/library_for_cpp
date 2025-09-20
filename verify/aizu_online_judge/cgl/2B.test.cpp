#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"

#include"../../../template/template.hpp"
#include"../../../Geometry/Intersection_Segment_and_Segment.hpp"

using namespace geometry;

int main() {
    using namespace geometry;

    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        Point<int> A, B, C, D; cin >> A >> B >> C >> D;
        Segment<int> s(A, B), t(C, D);
        cout << has_Intersection(s, t) << endl;
    }
}
